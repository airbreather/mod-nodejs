#ifndef MOD_NODEJS_NODECOMMON_H
#define MOD_NODEJS_NODECOMMON_H

#include <cstdint>
#include <iterator>

// magic numbers intended to make it hard for a script to ACCIDENTALLY try to use an ObjectGuid as a
// pointer to an object that's being wrapped. this is NOT a security measure: never give untrusted
// individuals the ability to run arbitrary JavaScript code on the server. there's an avenue for ACE
// by exploiting the fact that we send ObjectGuid values wrapped in External, combined with the fact
// that overwhelmingly many constructor functions treat "first arg is an External" as a signal for
// using its value as a pointer to an object of a specific type. there's no point in doing anything
// to close that hole, however, because there's a much easier avenue for ACE:
//
// import process from 'node:process';
//
// so we don't bother with anything fancy to protect or randomize these values or anything.
constexpr uint32_t OWNERSHIP_TRANSFER_MAGIC = 0x87654321;
constexpr uint32_t OBJECT_REFERENCE_MAGIC = 0x12345678;

template <typename T>
concept IsNonConstPointer =
	std::is_pointer_v<T>
	&& !std::is_const_v<std::remove_pointer_t<T>>;

template <typename T>
concept IsConstPointer =
	std::is_pointer_v<T>
	&& std::is_const_v<std::remove_pointer_t<T>>;

template <typename M>
concept MapLike = requires(M m, typename M::key_type k) {
	typename M::key_type;
	typename M::mapped_type;
	std::input_iterator<std::pair<const typename M::key_type, typename M::mapped_type>>;
	{ m.find(k) } -> std::same_as<typename M::iterator>;
};

template <template <typename...> class, typename>
struct is_specialization_of {
	static constexpr auto value = false;
};

template <template <typename...> class T, typename... Us>
struct is_specialization_of<T, T<Us...>> {
	static constexpr auto value = true;
};

template <template <typename...> class T, typename... Us>
constexpr bool is_specialization_of_v = is_specialization_of<T, Us...>::value;

#endif //MOD_NODEJS_NODECOMMON_H
