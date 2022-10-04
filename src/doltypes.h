#pragma once

using u16 = unsigned short;
using BOOL = bool;
using s16 = short;
using u8 = unsigned char;
using undefined1 = unsigned char;
using s8 = char;
using u32 = unsigned;
using s32 = int;
using undefined2 = short;
using undefined4 = unsigned int;
using undefined8 = long long;
using ulong = unsigned long int;
using uint = unsigned int;
using undefined = char;
using byte = unsigned char;
using f32 = float;
using ushort = unsigned short;
using uchar = unsigned char;
using f64 = double;
using s64 = long long;
using u64 = unsigned long long;
using ssize_t = long;

#define AT_ADDRESS(X) 


template <class P, class M>
u64 my_offsetof(const M P::*member) {
	return (u64)&(reinterpret_cast<P *>(0)->*member);
}

template <class P, class M>
P *my_container_of_impl(M *ptr, const M P::*member) {
	return (P *)((char *)ptr - my_offsetof(member));
}

#define my_container_of(ptr, type, member) \
	my_container_of_impl(ptr, &type::member)
