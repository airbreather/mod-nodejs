#ifndef MOD_NODEJS_NODECOMMON_H
#define MOD_NODEJS_NODECOMMON_H

#include <cstdint>
#include <iterator>

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
