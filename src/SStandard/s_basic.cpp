#include <SStandard/s_basic.h>
#include <SStandard/s_basic.h>


namespace SStandard {

/* __stdcall sBs_FillArea_s(void *,
                            unsigned long,
                            short) */

void sBs_FillArea_s(short *param_1,uint param_2,short param_3)

{
  uint uVar1;
  
  uVar1 = param_2 >> 1;
  if (uVar1 == 0) {
    return;
  }
  do {
    *param_1 = param_3;
    param_1 = param_1 + 1;
    uVar1 = uVar1 - 1;
  } while (uVar1 != 0);
  return;
}


/* __stdcall sBs_ClearArea(void *,
                           unsigned long) */

void sBs_ClearArea(undefined4 param_1,undefined4 param_2)

{
  sBs_FillArea_s(param_1,param_2,0);
  return;
}

