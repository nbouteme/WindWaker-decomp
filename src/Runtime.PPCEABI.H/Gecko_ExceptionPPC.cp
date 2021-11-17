#include <Runtime.PPCEABI.H/Gecko_ExceptionPPCp.h>


namespace Runtime.PPCEABI.H {
undefined4 fragmentinfo;

void __unregister_fragment(int param_1)

{
  if (param_1 < 0) {
    return;
  }
  if (0 < param_1) {
    return;
  }
  (&fragmentinfo)[param_1 * 3] = 0;
  (&DAT_803f1abc)[param_1 * 3] = 0;
  (&DAT_803f1ac0)[param_1 * 3] = 0;
  return;
}


undefined4 __register_fragment(undefined4 param_1,undefined4 param_2)

{
  if (DAT_803f1ac0 == 0) {
    fragmentinfo = param_1;
    DAT_803f1abc = param_2;
    DAT_803f1ac0 = 1;
    return 0;
  }
  return 0xffffffff;
}

