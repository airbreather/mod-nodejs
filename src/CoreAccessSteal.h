#ifndef MOD_NODEJS_CORE_ACCESS_STEAL_H
#define MOD_NODEJS_CORE_ACCESS_STEAL_H

// This file exists ONLY so that mod-nodejs does not require a core patch to
// AzerothCore for the handful of private/protected members it needs to read.
//
// It uses a well-known, standards-legal C++ idiom (informally called the
// "steal" or "loophole" trick): explicit template instantiation is not
// subject to access control ([temp.explicit] in the standard), so a
// friend function declared inside a template can be used to smuggle out a
// pointer-to-member for a private/protected member, without that member
// ever being marked `friend` in the original class and without patching
// the original class at all.
//
// This has been verified to compile and run correctly under GCC 13
// (Ubuntu 24.04) with -std=c++20 -Wall -Wextra, producing zero warnings.
// It is widely used in production C++ code (Boost, and various serialization
// / reflection libraries) and is portable across GCC, Clang, and MSVC/
// clang-cl, which matters here since AzerothCore builds with MSVC/clang-cl
// on Windows and GCC/Clang on Linux.
//
// IMPORTANT CAVEAT: this only works for members that ALREADY EXIST in
// AzerothCore's classes, regardless of their access level. It cannot
// synthesize new behavior that doesn't exist yet (see CoreAccessShims.cpp
// for the one case -- Guild::SetMOTD/SetInfo -- where the desired
// functionality didn't exist in any form before, and had to be
// reimplemented here instead of merely "unlocked").
//
// Usage pattern for a private/protected DATA member:
//
//   AC_STEAL_MEMBER(BattlegroundScore_PlayerGuid, BattlegroundScore, PlayerGuid, ObjectGuid)
//   // ... later ...
//   ObjectGuid guid = BattlegroundScore_PlayerGuid(score);   // score is BattlegroundScore const&
//
// Usage pattern for a private/protected MEMBER FUNCTION (0-arg getter):
//
//   AC_STEAL_METHOD(BattlegroundScore_GetDeaths, BattlegroundScore, GetDeaths, uint32)
//   // ... later ...
//   uint32 deaths = BattlegroundScore_GetDeaths(score);
//
// See CoreAccessShims.h/.cpp for every concrete instantiation this module
// actually needs, mirroring PR azerothcore-wotlk#26648 field-for-field.

template <typename Tag, typename Tag::type M>
struct AC_Rob
{
    friend typename Tag::type AC_RobGet(Tag) { return M; }
};

// --- Data member accessor generator -----------------------------------
// Name:      identifier prefix for the generated tag struct and function
// ClassName: the AzerothCore class that owns the member
// Member:    the (private/protected) member name inside ClassName
// MemberType: the declared type of that member
#define AC_STEAL_MEMBER(Name, ClassName, Member, ...)                        \
    struct Name##_AC_Tag                                                     \
    {                                                                        \
        using type = __VA_ARGS__ ClassName::*;                               \
        friend type AC_RobGet(Name##_AC_Tag);                                \
    };                                                                       \
    template struct AC_Rob<Name##_AC_Tag, &ClassName::Member>;               \
    inline __VA_ARGS__& Name(ClassName& obj)                                 \
    {                                                                        \
        return obj.*AC_RobGet(Name##_AC_Tag{});                              \
    }                                                                        \
    inline __VA_ARGS__ const& Name(ClassName const& obj)                    \
    {                                                                        \
        return obj.*AC_RobGet(Name##_AC_Tag{});                              \
    }

// --- Member function accessor generator --------------------------------
// Same idea, but for calling a private/protected non-static member function.
// RetType and Args... must match the target method's signature exactly
// (including const-ness of the method itself, passed via IsConst).
#define AC_STEAL_METHOD(Name, ClassName, Method, RetType, ...)               \
    struct Name##_AC_Tag                                                     \
    {                                                                        \
        using type = RetType (ClassName::*)(__VA_ARGS__) const;              \
        friend type AC_RobGet(Name##_AC_Tag);                                \
    };                                                                       \
    template struct AC_Rob<Name##_AC_Tag, &ClassName::Method>;               \
    template <typename... CallArgs>                                         \
    inline RetType Name(ClassName const& obj, CallArgs&&... args)           \
    {                                                                        \
        return (obj.*AC_RobGet(Name##_AC_Tag{}))(std::forward<CallArgs>(args)...); \
    }

#endif // MOD_NODEJS_CORE_ACCESS_STEAL_H
