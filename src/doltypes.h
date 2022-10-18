#pragma once

using BOOL = bool;

using undefined = char;
using undefined1 = unsigned char;
using undefined2 = short;
using undefined4 = unsigned int;
using undefined8 = long long;

using u8 = unsigned char;
using u16 = unsigned short;
using u32 = unsigned;
using u64 = unsigned long long;

using uint = unsigned int;
using ulong = unsigned long int;

using s8 = char;
using s16 = short;
using s32 = int;
using s64 = long long;

using f32 = float;
using f64 = double;

using byte = unsigned char;
using ushort = unsigned short;
using uchar = unsigned char;
using ssize_t = long;

#define AT_ADDRESS(X)

template <class P, class M>
u64 my_offsetof(const M P::*member) {
	return (u64) & (reinterpret_cast<P *>(0)->*member);
}

template <class P, class M>
P *my_container_of_impl(M *ptr, const M P::*member) {
	return (P *)((char *)ptr - my_offsetof(member));
}

#define my_container_of(ptr, type, member) \
	my_container_of_impl(ptr, &type::member)

#if _WIN32 || _WIN64
#if _WIN64
#define PTR64
#else
#define PTR32
#endif
#elif __GNUC__
#if __x86_64__ || __ppc64__
#define PTR64
#else
#define PTR32
#endif
#elif UINTPTR_MAX > UINT_MAX
#define PTR64
#else
#define PTR32
#endif

template <typename T>
struct big_endian {
	T internal;

	// constructor to reinterpret endianness
	big_endian(const T _i) : internal(_i) {
	}

	constexpr operator T() const noexcept {
		if constexpr (sizeof(T) == 2)
			return __builtin_bswap16(internal);
		else if constexpr (sizeof(T) == 4)
			return __builtin_bswap32(internal);
		else if constexpr (sizeof(T) == 8)
			return __builtin_bswap64(internal);
	}

	constexpr big_endian<T> &operator=(const T &rhs) noexcept {
		if constexpr (sizeof(T) == 2)
			internal = __builtin_bswap16(internal);
		else if constexpr (sizeof(T) == 4)
			internal = __builtin_bswap32(internal);
		else if constexpr (sizeof(T) == 8)
			internal = __builtin_bswap64(internal);
		return *this;
	}
};

using be_u16 = big_endian<unsigned short>;
using be_u32 = big_endian<unsigned>;
using be_u64 = big_endian<unsigned long long>;

using be_uint = big_endian<unsigned int>;
using be_ulong = big_endian<unsigned long int>;

using be_s16 = big_endian<short>;
using be_s32 = big_endian<int>;
using be_s64 = big_endian<long long>;

template <typename T>
struct TVec3 {
	T x, y, z;
};
