#include <gx/GXDisplayList.h>
#include <gx/GXGeometry.h>


namespace gx {

void GXCallDisplayList(undefined4 param_1,undefined4 param_2)

{
  if (gx[0x13d] != 0) {
    __GXSetDirtyState();
  }
  if (*gx == 0) {
    __GXSendFlushPrim();
  }
  write_volatile_1(DAT_cc008000,0x40);
  write_volatile_4(0xcc008000,param_1);
  write_volatile_4(0xcc008000,param_2);
  return;
}

