#include <MSL_C.PPCEABI.bare.H/e_rem_pio2.h>
#include <MSL_C.PPCEABI.bare.H/k_rem_pio2.h>


namespace MSL_C.PPCEABI.bare.H {

int __ieee754_rem_pio2(double param_1,double *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  double *pdVar4;
  int iVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  uint local_58;
  double local_48;
  double local_40;
  double local_38 [3];
  longlong local_20;
  undefined4 local_18;
  uint uStack20;
  
  dVar6 = _150;
  dVar7 = _148;
  local_58 = (uint)((ulonglong)param_1 >> 0x20);
  uVar1 = local_58 & 0x7fffffff;
  if (uVar1 < 0x3fe921fc) {
    *param_2 = param_1;
    iVar2 = 0;
    param_2[1] = _146;
  }
  else {
    if (uVar1 < 0x4002d97c) {
      if ((int)local_58 < 1) {
        param_1 = _147 + param_1;
        if (uVar1 == 0x3ff921fb) {
          param_1 = param_1 + _149;
          *param_2 = _150 + param_1;
          param_2[1] = dVar6 + (param_1 - *param_2);
        }
        else {
          *param_2 = _148 + param_1;
          param_2[1] = dVar7 + (param_1 - *param_2);
        }
        iVar2 = -1;
      }
      else {
        param_1 = param_1 - _147;
        if (uVar1 == 0x3ff921fb) {
          param_1 = param_1 - _149;
          *param_2 = param_1 - _150;
          param_2[1] = (param_1 - *param_2) - dVar6;
        }
        else {
          *param_2 = param_1 - _148;
          param_2[1] = (param_1 - *param_2) - dVar7;
        }
        iVar2 = 1;
      }
    }
    else {
      iVar3 = (int)uVar1 >> 0x14;
      if (uVar1 < 0x413921fc) {
        iVar2 = (int)(_152 * ABS(param_1) + _151);
        local_38[2] = (double)(CONCAT44(0x43300000,iVar2) ^ 0x80000000);
        local_38[2] = local_38[2] - _158;
        dVar7 = -(_147 * local_38[2] - ABS(param_1));
        dVar6 = _148 * local_38[2];
        if ((iVar2 < 0x20) && (uVar1 != *(uint *)(&DAT_8037128c + iVar2 * 4))) {
          *param_2 = dVar7 - dVar6;
        }
        else {
          *param_2 = dVar7 - dVar6;
          if (0x10 < (int)(iVar3 - (*(uint *)param_2 >> 0x14 & 0x7ff))) {
            dVar8 = dVar7 - _149 * local_38[2];
            dVar6 = _150 * local_38[2] - ((dVar7 - dVar8) - _149 * local_38[2]);
            *param_2 = dVar8 - dVar6;
            dVar7 = dVar8;
            if (0x31 < (int)(iVar3 - (*(uint *)param_2 >> 0x14 & 0x7ff))) {
              dVar7 = dVar8 - _153 * local_38[2];
              dVar6 = _154 * local_38[2] - ((dVar8 - dVar7) - _153 * local_38[2]);
              *param_2 = dVar7 - dVar6;
            }
          }
        }
        param_2[1] = (dVar7 - *param_2) - dVar6;
        if ((longlong)param_1 < 0) {
          iVar2 = -iVar2;
          *param_2 = -*param_2;
          param_2[1] = -param_2[1];
        }
      }
      else {
        if (uVar1 < 0x7ff00000) {
          iVar5 = 3;
          dVar7 = (double)((ulonglong)param_1 & 0xffffffff |
                          (ulonglong)(uVar1 + (iVar3 + -0x416) * -0x100000) << 0x20);
          local_18 = 0x43300000;
          iVar2 = (int)dVar7;
          local_38[2] = (double)(longlong)iVar2;
          local_38[1] = (double)(CONCAT44(0x43300000,iVar2) ^ 0x80000000);
          local_48 = local_38[1] - _158;
          dVar7 = _155 * (dVar7 - local_48);
          uStack20 = (uint)dVar7;
          local_20 = (longlong)(int)uStack20;
          uStack20 = uStack20 ^ 0x80000000;
          local_40 = (double)CONCAT44(0x43300000,uStack20) - _158;
          local_38[0] = _155 * (dVar7 - local_40);
          for (pdVar4 = local_38 + 1; _146 == pdVar4[-1]; pdVar4 = pdVar4 + -1) {
            iVar5 = iVar5 + -1;
          }
          iVar2 = __kernel_rem_pio2(&local_48,param_2,iVar3 + -0x416,iVar5,2,&two_over_pi);
          if ((longlong)param_1 < 0) {
            iVar2 = -iVar2;
            *param_2 = -*param_2;
            param_2[1] = -param_2[1];
          }
        }
        else {
          iVar2 = 0;
          param_2[1] = param_1 - param_1;
          *param_2 = param_1 - param_1;
        }
      }
    }
  }
  return iVar2;
}

