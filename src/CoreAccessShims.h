#ifndef MOD_NODEJS_CORE_ACCESS_SHIMS_H
#define MOD_NODEJS_CORE_ACCESS_SHIMS_H

// Replacement for azerothcore-wotlk PR #26648 ("Expose a few values more
// publicly that seem safe"), implemented entirely on the module side so
// that AzerothCore's core does NOT need to be patched.
//
// If/when #26648 (or an equivalent) is merged upstream, everything in this
// file becomes redundant and can be deleted in favor of the real public
// getters -- at that point just remove the #include of this file and the
// call sites will need trivial updates (Foo_GetBar(x) -> x.GetBar()).
// Nothing else in the module depends on the *mechanism* used here, only on
// the free functions declared below, so that swap is a mechanical, local
// change whenever the update happens.
//
// Adjust the #include paths below to match wherever mod-nodejs's build
// already locates AzerothCore's headers (this mirrors the same include
// roots AC's own CMake exposes to modules).

#include "CoreAccessSteal.h"

#include "Battlegrounds/BattlegroundScore.h"
#include "Battlegrounds/Zones/BattlegroundAB.h"
#include "Battlegrounds/Zones/BattlegroundAV.h"
#include "Battlegrounds/Zones/BattlegroundEY.h"
#include "Battlegrounds/Zones/BattlegroundIC.h"
#include "Battlegrounds/Zones/BattlegroundSA.h"
#include "Battlegrounds/Zones/BattlegroundWS.h"
#include "Guilds/Guild.h"
#include "Loot/LootMgr.h"
#include "Spells/Auras/SpellAuraEffects.h"

// ---------------------------------------------------------------------
// BattlegroundScore (base struct)
// ---------------------------------------------------------------------
// PlayerGuid has no existing getter anywhere -- must steal the raw field.
AC_STEAL_MEMBER(BattlegroundScore_PlayerGuid, BattlegroundScore, PlayerGuid, ObjectGuid)
inline ObjectGuid BattlegroundScore_GetPlayerGuid(BattlegroundScore const& s) { return BattlegroundScore_PlayerGuid(s); }

// These three already exist as *protected* 0-arg const getters -- steal the
// method itself (more stable than the raw field if AC ever changes how
// these are stored internally).
AC_STEAL_METHOD(BattlegroundScore_GetDeaths, BattlegroundScore, GetDeaths, uint32)
AC_STEAL_METHOD(BattlegroundScore_GetHonorableKills, BattlegroundScore, GetHonorableKills, uint32)
AC_STEAL_METHOD(BattlegroundScore_GetBonusHonor, BattlegroundScore, GetBonusHonor, uint32)

// ---------------------------------------------------------------------
// Per-battleground score subclasses -- all genuinely new fields, no
// existing getter to fall back on, so steal the raw members directly.
// ---------------------------------------------------------------------
AC_STEAL_MEMBER(BattlegroundABScore_BasesAssaulted, BattlegroundABScore, BasesAssaulted, uint32)
AC_STEAL_MEMBER(BattlegroundABScore_BasesDefended, BattlegroundABScore, BasesDefended, uint32)

AC_STEAL_MEMBER(BattlegroundAVScore_GraveyardsAssaulted, BattlegroundAVScore, GraveyardsAssaulted, uint32)
AC_STEAL_MEMBER(BattlegroundAVScore_GraveyardsDefended, BattlegroundAVScore, GraveyardsDefended, uint32)
AC_STEAL_MEMBER(BattlegroundAVScore_TowersAssaulted, BattlegroundAVScore, TowersAssaulted, uint32)
AC_STEAL_MEMBER(BattlegroundAVScore_TowersDefended, BattlegroundAVScore, TowersDefended, uint32)
AC_STEAL_MEMBER(BattlegroundAVScore_MinesCaptured, BattlegroundAVScore, MinesCaptured, uint32)

AC_STEAL_MEMBER(BattlegroundEYScore_FlagCaptures, BattlegroundEYScore, FlagCaptures, uint32)

AC_STEAL_MEMBER(BattlegroundICScore_BasesAssaulted, BattlegroundICScore, BasesAssaulted, uint32)
AC_STEAL_MEMBER(BattlegroundICScore_BasesDefended, BattlegroundICScore, BasesDefended, uint32)

AC_STEAL_MEMBER(BattlegroundSAScore_DemolishersDestroyed, BattlegroundSAScore, DemolishersDestroyed, uint32)
AC_STEAL_MEMBER(BattlegroundSAScore_GatesDestroyed, BattlegroundSAScore, GatesDestroyed, uint32)

AC_STEAL_MEMBER(BattlegroundWGScore_FlagCaptures, BattlegroundWGScore, FlagCaptures, uint32)
AC_STEAL_MEMBER(BattlegroundWGScore_FlagReturns, BattlegroundWGScore, FlagReturns, uint32)

// ---------------------------------------------------------------------
// SpellAuraEffects: GetEnabled() didn't exist, m_isAuraEnabled is private.
// ---------------------------------------------------------------------
AC_STEAL_MEMBER(AuraEffect_IsAuraEnabled, AuraEffect, m_isAuraEnabled, bool)
inline bool AuraEffect_GetEnabled(AuraEffect const& e) { return AuraEffect_IsAuraEnabled(e); }

// ---------------------------------------------------------------------
// LootItem::count -- NOT an access problem (LootItem is a plain struct,
// `count` is already public); it's an ADDRESSABILITY problem, since
// vanilla AzerothCore still declares it as an 8-bit bitfield:
//
//     uint8 count : 8;
//
// You cannot take the address of a bitfield, which breaks any generic,
// pointer-to-member-based binding mechanism. The fix is simply to never
// bind this field generically -- read/write it by value instead.
// No core patch and no private-access trick needed for this one at all.
// ---------------------------------------------------------------------
inline uint32_t LootItem_GetCount(LootItem const& item) { return item.count; }
inline void LootItem_SetCount(LootItem& item, uint32_t value)
{
    // vanilla AC's field is still a uint8:8, so clamp defensively --
    // once azerothcore-wotlk#26648 lands and count becomes a real uint32,
    // this clamp becomes a no-op and can be deleted.
    item.count = static_cast<decltype(item.count)>(value > 255 ? 255 : value);
}

// ---------------------------------------------------------------------
// Guild::GetUnorderedMembers() -- trivial field expose, m_members is
// protected with no existing accessor.
// ---------------------------------------------------------------------
AC_STEAL_MEMBER(Guild_Members, Guild, m_members, std::unordered_map<uint32, Guild::Member>)
inline std::unordered_map<uint32, Guild::Member> const& Guild_GetUnorderedMembers(Guild const& g) { return Guild_Members(g); }

// Guild::SetMOTD / Guild::SetInfo are declared in CoreAccessShims.cpp
// instead of here, since they are NOT mere visibility fixes -- see the
// comment there for why they need a real (small) reimplementation rather
// than a one-line steal.
void Guild_SetMOTD(Guild& guild, std::string_view motd);
void Guild_SetInfo(Guild& guild, std::string_view info);

#endif // MOD_NODEJS_CORE_ACCESS_SHIMS_H
