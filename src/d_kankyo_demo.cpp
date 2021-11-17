#include <d_kankyo_demo.h>
#include <d_kankyo.h>


namespace d_kankyo_demo {

/* __stdcall dKydm_demo_plight_entry(DEMO_PLIGHT *,
                                     cXyz *,
                                     int,
                                     unsigned char) */

void dKydm_demo_plight_entry
               (undefined4 *param_1,undefined4 *param_2,int param_3,uint param_4)

{
  if (-1 < param_3) {
    param_1[2] = *param_2;
    param_1[3] = param_2[1];
    param_1[4] = param_2[2];
    param_1[1] = param_3 + (param_4 & 0xff) * 100;
    if ((int)param_1[1] < 100) {
      *(undefined2 *)(param_1 + 5) = 0xff;
      *(undefined2 *)((int)param_1 + 0x16) = 0xff;
      *(undefined2 *)(param_1 + 6) = 0x80;
      param_1[7] = _4015;
      param_1[8] = _4016;
      d_kankyo::dKy_plight_set((LIGHT_INFLUENCE *)(param_1 + 2));
    }
    else {
      if (param_1[1] == 0x67) {
        *(undefined2 *)(param_1 + 5) = 0xff;
        *(undefined2 *)((int)param_1 + 0x16) = 0xff;
        *(undefined2 *)(param_1 + 6) = 0x78;
        param_1[7] = _4019;
        param_1[8] = _4020;
      }
      else {
        *(undefined2 *)(param_1 + 5) = 0xff;
        *(undefined2 *)((int)param_1 + 0x16) = 0xff;
        *(undefined2 *)(param_1 + 6) = 0x78;
        param_1[7] = _4017;
        param_1[8] = _4018;
      }
      d_kankyo::dKy_efplight_set((LIGHT_INFLUENCE *)(param_1 + 2));
    }
    *param_1 = 0;
    param_1[1] = param_3;
  }
  return;
}


/* __stdcall dKydm_demo_plight_delete(DEMO_PLIGHT *) */

void dKydm_demo_plight_delete(int param_1)

{
  if (param_1 != 0) {
    if (*(int *)(param_1 + 4) < 100) {
      d_kankyo::dKy_plight_cut((LIGHT_INFLUENCE *)(param_1 + 8));
    }
    else {
      d_kankyo::dKy_efplight_cut((LIGHT_INFLUENCE *)(param_1 + 8));
    }
  }
  return;
}


/* __stdcall dKydm_demo_plight_execute(DEMO_PLIGHT *,
                                       cXyz *) */

void dKydm_demo_plight_execute(int param_1,undefined4 *param_2)

{
  if (param_1 == 0) {
    return;
  }
  *(undefined4 *)(param_1 + 8) = *param_2;
  *(undefined4 *)(param_1 + 0xc) = param_2[1];
  *(undefined4 *)(param_1 + 0x10) = param_2[2];
  return;
}

