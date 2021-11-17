#include <JRenderer/JRenderer.h>


namespace JRenderer {

/* __stdcall JRNLoadTexCached(_GXTexMapID,
                              unsigned long,
                              _GXTexCacheSize,
                              unsigned long,
                              _GXTexCacheSize) */

void JRNLoadTexCached(int param_1,uint param_2,int param_3,uint param_4,int param_5)

{
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,
                   (uint)(byte)(&JRNTexImage1Ids)[param_1] << 0x18 |
                   (param_3 + 3) * 0x40000 | param_2 >> 5 | (param_3 + 3) * 0x8000);
  if (param_5 == 3) {
    return;
  }
  if (0xfffff < param_4) {
    return;
  }
  write_volatile_1(DAT_cc008000,0x61);
  write_volatile_4(0xcc008000,
                   (uint)(byte)(&JRNTexImage2Ids)[param_1] << 0x18 |
                   (param_5 + 3) * 0x40000 | param_4 >> 5 | (param_5 + 3) * 0x8000);
  return;
}

