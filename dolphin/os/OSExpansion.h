#pragma once

#include <dolphin/types.h>
#include <dolphin/os.h>
namespace os {

#define EXI_MEMORY_CARD_59      0x00000004
#define EXI_MEMORY_CARD_123     0x00000008
#define EXI_MEMORY_CARD_251     0x00000010
#define EXI_MEMORY_CARD_507     0x00000020

#ifndef EXI_MEMORY_CARD_1019

#define EXI_MEMORY_CARD_1019    0x00000040
#define EXI_MEMORY_CARD_2043    0x00000080

// Since SDK 9/5/02 Patch 1, EXI_MEMORY_CARD_*[A-G] are not
// returned with EXIGetType(). EXIGetType() returns EXI_MEMORY_CARD_1019
// for any type of Memory Card 1019 and EXI_MEMORY_CARD_2043 for any type
// of Memory Card 2043.
#define EXI_MEMORY_CARD_1019A   0x00000140
#define EXI_MEMORY_CARD_1019B   0x00000240
#define EXI_MEMORY_CARD_1019C   0x00000340
#define EXI_MEMORY_CARD_1019D   0x00000440
#define EXI_MEMORY_CARD_1019E   0x00000540
#define EXI_MEMORY_CARD_1019F   0x00000640
#define EXI_MEMORY_CARD_1019G   0x00000740

#define EXI_MEMORY_CARD_2043A   0x00000180
#define EXI_MEMORY_CARD_2043B   0x00000280
#define EXI_MEMORY_CARD_2043C   0x00000380
#define EXI_MEMORY_CARD_2043D   0x00000480
#define EXI_MEMORY_CARD_2043E   0x00000580
#define EXI_MEMORY_CARD_2043F   0x00000680
#define EXI_MEMORY_CARD_2043G   0x00000780

#endif  // EXI_MEMORY_CARD_1019

#define EXI_USB_ADAPTER         0x01010000
#define EXI_NPDP_GDEV           0x01020000

#define EXI_MODEM               0x02020000
#define EXI_ETHER               0x04020200

#define EXI_MARLIN              0x03010000

#define EXI_IS_VIEWER           0x05070000

BOOL  EXIProbe        ( s32 chan );
s32   EXIProbeEx      ( s32 chan );

s32   EXIGetType      ( s32 chan, u32 dev, u32* type );
char* EXIGetTypeString( u32 type );
}