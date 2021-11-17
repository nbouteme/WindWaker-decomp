#include <gf/GFLight.h>


namespace gf {

/* __stdcall GFSetChanMatColor(_GXChannelID,
                               _GXColor) */

void GFSetChanMatColor(ushort param_1,byte *param_2)

{
  write_volatile_1(DAT_cc008000,0x10);
  write_volatile_2(0xcc008000,0);
  write_volatile_2(0xcc008000,(param_1 & 1) + 0x100c);
  write_volatile_4(0xcc008000,
                   (uint)param_2[3] |
                   (uint)param_2[2] << 8 | (uint)*param_2 << 0x18 | (uint)param_2[1] << 0x10);
  return;
}

