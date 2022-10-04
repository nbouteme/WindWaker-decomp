#pragma once
#include <dolphin/types.h>

namespace os {
#define OS_PROTECT_CHAN0 0
#define OS_PROTECT_CHAN1 1
#define OS_PROTECT_CHAN2 2
#define OS_PROTECT_CHAN3 3

// Capability bits
#define OS_PROTECT_CONTROL_NONE 0x00
#define OS_PROTECT_CONTROL_READ 0x01   // OK to read  [addr, addr + nBytes)
#define OS_PROTECT_CONTROL_WRITE 0x02  // OK to write [addr, addr + nBytes)
#define OS_PROTECT_CONTROL_RDWR (OS_PROTECT_CONTROL_READ | OS_PROTECT_CONTROL_WRITE)

// dsisr bits for memory protection error handler, which tells
// from which region the error was reported
#define OS_PROTECT0_BIT 0x00000001		   // by OS_PROTECT_CHAN0 range
#define OS_PROTECT1_BIT 0x00000002		   // by OS_PROTECT_CHAN1 range
#define OS_PROTECT2_BIT 0x00000004		   // by OS_PROTECT_CHAN2 range
#define OS_PROTECT3_BIT 0x00000008		   // by OS_PROTECT_CHAN3 range
#define OS_PROTECT_ADDRERR_BIT 0x00000010  // by [24M or 48M, 64M)

	void OSProtectRange(u32 chan, void* addr, u32 nBytes, u32 control);
}