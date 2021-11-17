#include <exi/EXIBios.h>
#include <os/OSInterrupt.h>
#include <exi/EXIBios.h>
#include <os/OS.h>
#include <os/OSTime.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <os/OSContext.h>
#include <MSL_C.PPCEABI.bare.H/mem.h>


namespace exi {
undefined Ecb;

void SetExiInterruptMask(int param_1,int *param_2)

{
  int iVar1;
  
  if (param_1 == 1) {
    if ((*param_2 == 0) || ((param_2[3] & 0x10U) != 0)) {
      os::__OSMaskInterrupts(0x80000);
    }
    else {
      os::__OSUnmaskInterrupts(0x80000);
    }
  }
  else {
    if (param_1 < 1) {
      if (-1 < param_1) {
        if (((*param_2 == 0) && (DAT_803f0d30 == 0)) || ((param_2[3] & 0x10U) != 0)) {
          os::__OSMaskInterrupts(&DAT_00410000);
        }
        else {
          os::__OSUnmaskInterrupts(&DAT_00410000);
        }
      }
    }
    else {
      if (param_1 < 3) {
        iVar1 = os::__OSGetInterruptHandler(0x19);
        if ((iVar1 == 0) || ((param_2[3] & 0x10U) != 0)) {
          os::__OSMaskInterrupts(0x40);
        }
        else {
          os::__OSUnmaskInterrupts(0x40);
        }
      }
    }
  }
  return;
}


undefined4 EXIImm(int param_1,byte *param_2,int param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  iVar1 = param_1 * 0x40;
  uVar3 = os::OSDisableInterrupts();
  if (((*(uint *)(&DAT_803f0cbc + iVar1) & 3) == 0) && ((*(uint *)(&DAT_803f0cbc + iVar1) & 4) != 0)
     ) {
    *(undefined4 *)(&DAT_803f0cb4 + iVar1) = param_5;
    if (*(int *)(&DAT_803f0cb4 + iVar1) != 0) {
      EXIClearInterrupts(param_1,0,1,0);
      os::__OSUnmaskInterrupts(0x200000 >> param_1 * 3);
    }
    *(uint *)(&DAT_803f0cbc + iVar1) = *(uint *)(&DAT_803f0cbc + iVar1) | 2;
    if (param_4 != 0) {
      uVar2 = 0;
      iVar6 = 0;
      if (0 < param_3) {
        if ((8 < param_3) && (uVar7 = param_3 - 1U >> 3, pbVar4 = param_2, 0 < param_3 + -8)) {
          do {
            uVar2 = uVar2 | (uint)*pbVar4 << (3 - iVar6) * 8 |
                    (uint)pbVar4[1] << (3 - (iVar6 + 1)) * 8 |
                    (uint)pbVar4[2] << (3 - (iVar6 + 2)) * 8 | (uint)pbVar4[3] << iVar6 * -8 |
                    (uint)pbVar4[4] << (3 - (iVar6 + 4)) * 8 |
                    (uint)pbVar4[5] << (3 - (iVar6 + 5)) * 8 |
                    (uint)pbVar4[6] << (3 - (iVar6 + 6)) * 8 |
                    (uint)pbVar4[7] << (3 - (iVar6 + 7)) * 8;
            pbVar4 = pbVar4 + 8;
            iVar6 = iVar6 + 8;
            uVar7 = uVar7 - 1;
          } while (uVar7 != 0);
        }
        pbVar4 = param_2 + iVar6;
        iVar5 = param_3 - iVar6;
        if (iVar6 < param_3) {
          do {
            uVar2 = uVar2 | (uint)*pbVar4 << (3 - iVar6) * 8;
            pbVar4 = pbVar4 + 1;
            iVar6 = iVar6 + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
      }
      *(uint *)(&DAT_cc006810 + param_1 * 0x14) = uVar2;
    }
    *(byte **)(&DAT_803f0cc4 + iVar1) = param_2;
    iVar6 = param_3;
    if (param_4 == 1) {
      iVar6 = 0;
    }
    *(int *)(&DAT_803f0cc0 + iVar1) = iVar6;
    *(uint *)(&DAT_cc00680c + param_1 * 0x14) = param_4 << 2 | 1U | (param_3 + -1) * 0x10;
    os::OSRestoreInterrupts(uVar3);
    uVar3 = 1;
  }
  else {
    os::OSRestoreInterrupts(uVar3);
    uVar3 = 0;
  }
  return uVar3;
}


undefined4 EXIImmEx(int card_slot,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  while( true ) {
    if (param_3 == 0) {
      return 1;
    }
    iVar2 = param_3;
    if (3 < param_3) {
      iVar2 = 4;
    }
    iVar1 = EXIImm(card_slot,param_2,iVar2,param_4,0);
    if (iVar1 == 0) break;
    iVar1 = EXISync(card_slot);
    if (iVar1 == 0) {
      return 0;
    }
    param_2 = param_2 + iVar2;
    param_3 = param_3 - iVar2;
  }
  return 0;
}


undefined4 EXIDma(int param_1,uint param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = param_1 * 0x40;
  uVar2 = os::OSDisableInterrupts();
  if (((*(uint *)(&DAT_803f0cbc + iVar1) & 3) == 0) && ((*(uint *)(&DAT_803f0cbc + iVar1) & 4) != 0)
     ) {
    *(undefined4 *)(&DAT_803f0cb4 + iVar1) = param_5;
    if (*(int *)(&DAT_803f0cb4 + iVar1) != 0) {
      EXIClearInterrupts(param_1,0,1,0);
      os::__OSUnmaskInterrupts(0x200000 >> param_1 * 3);
    }
    *(uint *)(&DAT_803f0cbc + iVar1) = *(uint *)(&DAT_803f0cbc + iVar1) | 1;
    param_1 = param_1 * 0x14;
    *(uint *)(&DAT_cc006804 + param_1) = param_2 & 0x3ffffe0;
    *(undefined4 *)(&DAT_cc006808 + param_1) = param_3;
    *(uint *)(&DAT_cc00680c + param_1) = param_4 << 2 | 3;
    os::OSRestoreInterrupts(uVar2);
    uVar2 = 1;
  }
  else {
    os::OSRestoreInterrupts(uVar2);
    uVar2 = 0;
  }
  return uVar2;
}


undefined4 EXISync(int param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined *puVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  uint uVar11;
  
  iVar2 = param_1 * 0x40;
  uVar9 = 0;
  iVar10 = param_1 * 0x14;
  do {
    if ((*(uint *)(&DAT_803f0cbc + iVar2) & 4) == 0) {
      return 0;
    }
  } while ((*(uint *)(&DAT_cc00680c + iVar10) & 1) != 0);
  uVar4 = os::OSDisableInterrupts();
  if ((*(uint *)(&DAT_803f0cbc + iVar2) & 4) != 0) {
    if ((*(uint *)(&DAT_803f0cbc + iVar2) & 3) != 0) {
      if ((*(uint *)(&DAT_803f0cbc + iVar2) & 2) != 0) {
        iVar5 = *(int *)(&DAT_803f0cc0 + iVar2);
        if (iVar5 != 0) {
          puVar7 = *(undefined **)(&DAT_803f0cc4 + iVar2);
          uVar3 = *(uint *)(&DAT_cc006810 + iVar10);
          iVar6 = 0;
          if (0 < iVar5) {
            if ((8 < iVar5) && (uVar11 = iVar5 - 1U >> 3, 0 < iVar5 + -8)) {
              do {
                *puVar7 = (char)(uVar3 >> (3 - iVar6) * 8);
                puVar7[1] = (char)(uVar3 >> (3 - (iVar6 + 1)) * 8);
                puVar7[2] = (char)(uVar3 >> (3 - (iVar6 + 2)) * 8);
                puVar7[3] = (char)(uVar3 >> iVar6 * -8);
                puVar7[4] = (char)(uVar3 >> (3 - (iVar6 + 4)) * 8);
                puVar7[5] = (char)(uVar3 >> (3 - (iVar6 + 5)) * 8);
                puVar7[6] = (char)(uVar3 >> (3 - (iVar6 + 6)) * 8);
                puVar7[7] = (char)(uVar3 >> (3 - (iVar6 + 7)) * 8);
                puVar7 = puVar7 + 8;
                iVar6 = iVar6 + 8;
                uVar11 = uVar11 - 1;
              } while (uVar11 != 0);
            }
            iVar8 = iVar5 - iVar6;
            if (iVar6 < iVar5) {
              do {
                *puVar7 = (char)(uVar3 >> (3 - iVar6) * 8);
                puVar7 = puVar7 + 1;
                iVar6 = iVar6 + 1;
                iVar8 = iVar8 + -1;
              } while (iVar8 != 0);
            }
          }
        }
      }
      *(uint *)(&DAT_803f0cbc + iVar2) = *(uint *)(&DAT_803f0cbc + iVar2) & 0xfffffffc;
    }
    iVar5 = os::__OSGetDIConfig();
    if (((((iVar5 != 0xff) || (*(int *)(&DAT_803f0cc0 + iVar2) != 4)) ||
         (((&DAT_cc006800)[param_1 * 5] & 0x70) != 0)) ||
        (((piVar1 = (int *)(&DAT_cc006810 + iVar10), *piVar1 != 0x1010000 && (*piVar1 != 0x5070000))
         && (*piVar1 != 0x4220001)))) || (DAT_800030e6 == -0x7e00)) {
      uVar9 = 1;
    }
  }
  os::OSRestoreInterrupts(uVar4);
  return uVar9;
}


uint EXIClearInterrupts(int param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (&DAT_cc006800)[param_1 * 5];
  uVar2 = uVar1 & 0x7f5;
  if (param_2 != 0) {
    uVar2 = uVar2 | 2;
  }
  if (param_3 != 0) {
    uVar2 = uVar2 | 8;
  }
  if (param_4 != 0) {
    uVar2 = uVar2 | 0x800;
  }
  (&DAT_cc006800)[param_1 * 5] = uVar2;
  return uVar1;
}


undefined4 EXISetExiCallback(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)(&Ecb + param_1 * 0x40);
  uVar1 = os::OSDisableInterrupts();
  uVar2 = *puVar3;
  *puVar3 = param_2;
  if (param_1 == 2) {
    SetExiInterruptMask(0,&Ecb);
  }
  else {
    SetExiInterruptMask(param_1,puVar3);
  }
  os::OSRestoreInterrupts(uVar1);
  return uVar2;
}


undefined4 __EXIProbe(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint *puVar3;
  int *piVar4;
  int extraout_r4;
  uint uVar5;
  undefined8 uVar6;
  
  if (param_1 == 2) {
    uVar1 = 1;
  }
  else {
    uVar1 = 1;
    uVar2 = os::OSDisableInterrupts();
    puVar3 = &DAT_cc006800 + param_1 * 5;
    uVar5 = *puVar3;
    if ((*(uint *)(&DAT_803f0cbc + param_1 * 0x40) & 8) == 0) {
      if ((uVar5 & 0x800) != 0) {
        *puVar3 = *puVar3 & 0x7f5 | 0x800;
        (&DAT_803f0cd0)[param_1 * 0x10] = 0;
        (&DAT_800030c0)[param_1] = 0;
      }
      if ((uVar5 & 0x1000) == 0) {
        (&DAT_803f0cd0)[param_1 * 0x10] = 0;
        (&DAT_800030c0)[param_1] = 0;
        uVar1 = 0;
      }
      else {
        os::OSGetTime();
        uVar6 = Runtime.PPCEABI.H::__div2i();
        Runtime.PPCEABI.H::__div2i((int)((ulonglong)uVar6 >> 0x20),(int)uVar6,0,100);
        piVar4 = &DAT_800030c0 + param_1;
        if (*piVar4 == 0) {
          *piVar4 = extraout_r4 + 1;
        }
        if ((extraout_r4 + 1) - *piVar4 < 3) {
          uVar1 = 0;
        }
      }
    }
    else {
      if (((uVar5 & 0x1000) == 0) || ((uVar5 & 0x800) != 0)) {
        (&DAT_803f0cd0)[param_1 * 0x10] = 0;
        (&DAT_800030c0)[param_1] = 0;
        uVar1 = 0;
      }
    }
    os::OSRestoreInterrupts(uVar2);
  }
  return uVar1;
}


int EXIProbe(int param_1)

{
  int iVar1;
  undefined auStack12 [4];
  
  iVar1 = __EXIProbe(param_1);
  if ((iVar1 != 0) && ((&DAT_803f0cd0)[param_1 * 0x10] == 0)) {
    iVar1 = EXIGetID(param_1,0,auStack12);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = 1;
    }
  }
  return iVar1;
}


undefined4 EXIProbeEx(int card_slot)

{
  int iVar1;
  undefined4 uVar2;
  undefined auStack12 [4];
  
  iVar1 = __EXIProbe(card_slot);
  if ((iVar1 != 0) && ((&DAT_803f0cd0)[card_slot * 0x10] == 0)) {
    iVar1 = EXIGetID(card_slot,0,auStack12);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = 1;
    }
  }
  if (iVar1 == 0) {
    if ((&DAT_800030c0)[card_slot] == 0) {
      uVar2 = 0xffffffff;
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}


undefined4 EXIAttach(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined auStack36 [16];
  
  iVar1 = param_1 * 0x40;
  iVar2 = __EXIProbe(param_1);
  if ((iVar2 != 0) && ((&DAT_803f0cd0)[param_1 * 0x10] == 0)) {
    EXIGetID(param_1,0,auStack36);
  }
  uVar3 = os::OSDisableInterrupts();
  if ((&DAT_803f0cd0)[param_1 * 0x10] == 0) {
    os::OSRestoreInterrupts(uVar3);
    uVar4 = 0;
  }
  else {
    uVar4 = os::OSDisableInterrupts();
    if (((*(uint *)(&DAT_803f0cbc + iVar1) & 8) == 0) && (iVar2 = __EXIProbe(param_1), iVar2 != 0))
    {
      EXIClearInterrupts(param_1,1,0,0);
      *(undefined4 *)(&DAT_803f0cb8 + iVar1) = param_2;
      os::__OSUnmaskInterrupts(0x100000 >> param_1 * 3);
      *(uint *)(&DAT_803f0cbc + iVar1) = *(uint *)(&DAT_803f0cbc + iVar1) | 8;
      os::OSRestoreInterrupts(uVar4);
      uVar4 = 1;
    }
    else {
      os::OSRestoreInterrupts(uVar4);
      uVar4 = 0;
    }
    os::OSRestoreInterrupts(uVar3);
  }
  return uVar4;
}


undefined4 EXIDetach(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = param_1 * 0x40;
  uVar2 = os::OSDisableInterrupts();
  if ((*(uint *)(&DAT_803f0cbc + iVar1) & 8) == 0) {
    os::OSRestoreInterrupts(uVar2);
    uVar2 = 1;
  }
  else {
    if (((*(uint *)(&DAT_803f0cbc + iVar1) & 0x10) == 0) || (*(int *)(&DAT_803f0cc8 + iVar1) != 0))
    {
      *(uint *)(&DAT_803f0cbc + iVar1) = *(uint *)(&DAT_803f0cbc + iVar1) & 0xfffffff7;
      os::__OSMaskInterrupts(0x500000 >> param_1 * 3);
      os::OSRestoreInterrupts(uVar2);
      uVar2 = 1;
    }
    else {
      os::OSRestoreInterrupts(uVar2);
      uVar2 = 0;
    }
  }
  return uVar2;
}


undefined4 EXISelect(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = param_1 * 0x40;
  uVar2 = os::OSDisableInterrupts();
  if (((*(uint *)(&DAT_803f0cbc + iVar1) & 4) == 0) &&
     ((param_1 == 2 ||
      ((((param_2 != 0 || ((*(uint *)(&DAT_803f0cbc + iVar1) & 8) != 0)) ||
        (iVar3 = __EXIProbe(param_1), iVar3 != 0)) &&
       (((*(uint *)(&DAT_803f0cbc + iVar1) & 0x10) != 0 &&
        (*(int *)(&DAT_803f0cc8 + iVar1) == param_2)))))))) {
    *(uint *)(&DAT_803f0cbc + iVar1) = *(uint *)(&DAT_803f0cbc + iVar1) | 4;
    (&DAT_cc006800)[param_1 * 5] =
         (&DAT_cc006800)[param_1 * 5] & 0x405 | (1 << param_2) << 7 | param_3 << 4;
    if ((*(uint *)(&DAT_803f0cbc + iVar1) & 8) != 0) {
      if (param_1 == 1) {
        os::__OSMaskInterrupts(0x20000);
      }
      else {
        if ((param_1 < 1) && (-1 < param_1)) {
          os::__OSMaskInterrupts(0x100000);
        }
      }
    }
    os::OSRestoreInterrupts(uVar2);
    uVar2 = 1;
  }
  else {
    os::OSRestoreInterrupts(uVar2);
    uVar2 = 0;
  }
  return uVar2;
}


undefined4 EXIDeselect(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = param_1 * 0x40;
  uVar1 = os::OSDisableInterrupts();
  if ((*(uint *)(&DAT_803f0cbc + iVar2) & 4) == 0) {
    os::OSRestoreInterrupts(uVar1);
    uVar1 = 0;
  }
  else {
    *(uint *)(&DAT_803f0cbc + iVar2) = *(uint *)(&DAT_803f0cbc + iVar2) & 0xfffffffb;
    uVar3 = (&DAT_cc006800)[param_1 * 5];
    (&DAT_cc006800)[param_1 * 5] = uVar3 & 0x405;
    if ((*(uint *)(&DAT_803f0cbc + iVar2) & 8) != 0) {
      if (param_1 == 1) {
        os::__OSUnmaskInterrupts(0x20000);
      }
      else {
        if ((param_1 < 1) && (-1 < param_1)) {
          os::__OSUnmaskInterrupts(0x100000);
        }
      }
    }
    os::OSRestoreInterrupts(uVar1);
    if ((param_1 == 2) || ((uVar3 & 0x80) == 0)) {
      uVar1 = 1;
    }
    else {
      iVar2 = __EXIProbe(param_1);
      if (iVar2 == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = 1;
      }
    }
  }
  return uVar1;
}


void EXIIntrruptHandler(short param_1,undefined4 param_2)

{
  int iVar1;
  code *pcVar2;
  undefined auStack736 [724];
  
  iVar1 = (param_1 + -9) / 3;
  (&DAT_cc006800)[iVar1 * 5] = (&DAT_cc006800)[iVar1 * 5] & 0x7f5 | 2;
  pcVar2 = *(code **)(&Ecb + iVar1 * 0x40);
  if (pcVar2 != (code *)0x0) {
    os::OSClearContext(auStack736);
    os::OSSetCurrentContext(auStack736);
    (*pcVar2)(iVar1,param_2);
    os::OSClearContext(auStack736);
    os::OSSetCurrentContext(param_2);
  }
  return;
}


void TCIntrruptHandler(short param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined *puVar7;
  int iVar8;
  uint uVar9;
  undefined auStack728 [712];
  
  iVar2 = (param_1 + -10) / 3;
  iVar1 = iVar2 * 0x40;
  os::__OSMaskInterrupts(0x80000000 >> (int)param_1);
  (&DAT_cc006800)[iVar2 * 5] = (&DAT_cc006800)[iVar2 * 5] & 0x7f5 | 8;
  pcVar3 = *(code **)(&DAT_803f0cb4 + iVar1);
  if (pcVar3 != (code *)0x0) {
    iVar6 = 0;
    *(undefined4 *)(&DAT_803f0cb4 + iVar1) = 0;
    if ((*(uint *)(&DAT_803f0cbc + iVar1) & 3) != 0) {
      if ((*(uint *)(&DAT_803f0cbc + iVar1) & 2) != 0) {
        iVar5 = *(int *)(&DAT_803f0cc0 + iVar1);
        if (iVar5 != 0) {
          puVar7 = *(undefined **)(&DAT_803f0cc4 + iVar1);
          uVar4 = *(uint *)(&DAT_cc006810 + iVar2 * 0x14);
          if (0 < iVar5) {
            if ((8 < iVar5) && (uVar9 = iVar5 - 1U >> 3, 0 < iVar5 + -8)) {
              do {
                *puVar7 = (char)(uVar4 >> (3 - iVar6) * 8);
                puVar7[1] = (char)(uVar4 >> (3 - (iVar6 + 1)) * 8);
                puVar7[2] = (char)(uVar4 >> (3 - (iVar6 + 2)) * 8);
                puVar7[3] = (char)(uVar4 >> iVar6 * -8);
                puVar7[4] = (char)(uVar4 >> (3 - (iVar6 + 4)) * 8);
                puVar7[5] = (char)(uVar4 >> (3 - (iVar6 + 5)) * 8);
                puVar7[6] = (char)(uVar4 >> (3 - (iVar6 + 6)) * 8);
                puVar7[7] = (char)(uVar4 >> (3 - (iVar6 + 7)) * 8);
                puVar7 = puVar7 + 8;
                iVar6 = iVar6 + 8;
                uVar9 = uVar9 - 1;
              } while (uVar9 != 0);
            }
            iVar8 = iVar5 - iVar6;
            if (iVar6 < iVar5) {
              do {
                *puVar7 = (char)(uVar4 >> (3 - iVar6) * 8);
                puVar7 = puVar7 + 1;
                iVar6 = iVar6 + 1;
                iVar8 = iVar8 + -1;
              } while (iVar8 != 0);
            }
          }
        }
      }
      *(uint *)(&DAT_803f0cbc + iVar1) = *(uint *)(&DAT_803f0cbc + iVar1) & 0xfffffffc;
    }
    os::OSClearContext(auStack728);
    os::OSSetCurrentContext(auStack728);
    (*pcVar3)(iVar2,param_2);
    os::OSClearContext(auStack728);
    os::OSSetCurrentContext(param_2);
  }
  return;
}


void EXTIntrruptHandler(short param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  undefined auStack728 [712];
  
  iVar2 = (param_1 + -0xb) / 3;
  os::__OSMaskInterrupts(0x500000 >> iVar2 * 3);
  iVar1 = iVar2 * 0x40;
  pcVar3 = *(code **)(&DAT_803f0cb8 + iVar1);
  *(uint *)(&DAT_803f0cbc + iVar1) = *(uint *)(&DAT_803f0cbc + iVar1) & 0xfffffff7;
  if (pcVar3 != (code *)0x0) {
    os::OSClearContext(auStack728);
    os::OSSetCurrentContext(auStack728);
    *(undefined4 *)(&DAT_803f0cb8 + iVar1) = 0;
    (*pcVar3)(iVar2,param_2);
    os::OSClearContext(auStack728);
    os::OSSetCurrentContext(param_2);
  }
  return;
}


void EXIInit(void)

{
  uint uVar1;
  
  os::OSRegisterVersion(__EXIVersion);
  os::__OSMaskInterrupts(0x7f8000);
  DAT_cc006814 = 0;
  DAT_cc006828 = 0;
  DAT_cc006800 = 0x2000;
  os::__OSSetInterruptHandler(9,EXIIntrruptHandler);
  os::__OSSetInterruptHandler(10,TCIntrruptHandler);
  os::__OSSetInterruptHandler(0xb,EXTIntrruptHandler);
  os::__OSSetInterruptHandler(0xc,EXIIntrruptHandler);
  os::__OSSetInterruptHandler(0xd,TCIntrruptHandler);
  os::__OSSetInterruptHandler(0xe,EXTIntrruptHandler);
  os::__OSSetInterruptHandler(0xf,EXIIntrruptHandler);
  os::__OSSetInterruptHandler(0x10,TCIntrruptHandler);
  uVar1 = os::OSGetConsoleType();
  if ((uVar1 & 0x10000000) != 0) {
    DAT_800030c4 = 0;
    DAT_800030c0 = 0;
    DAT_803f0d10 = 0;
    DAT_803f0cd0 = 0;
    __EXIProbe(0);
    __EXIProbe(1);
  }
  return;
}


undefined4 EXILock(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined *puVar3;
  int iVar4;
  undefined *puVar5;
  int iVar6;
  
  iVar1 = param_1 * 0x40;
  puVar5 = &Ecb + iVar1;
  uVar2 = os::OSDisableInterrupts();
  if ((*(uint *)(&DAT_803f0cbc + iVar1) & 0x10) == 0) {
    *(uint *)(&DAT_803f0cbc + iVar1) = *(uint *)(&DAT_803f0cbc + iVar1) | 0x10;
    *(int *)(&DAT_803f0cc8 + iVar1) = param_2;
    SetExiInterruptMask(param_1,puVar5);
    os::OSRestoreInterrupts(uVar2);
    uVar2 = 1;
  }
  else {
    if (param_3 != 0) {
      iVar4 = *(int *)(&DAT_803f0cd4 + iVar1);
      puVar3 = puVar5;
      iVar6 = iVar4;
      if (0 < iVar4) {
        do {
          if (*(int *)(puVar3 + 0x28) == param_2) {
            os::OSRestoreInterrupts(uVar2);
            return 0;
          }
          puVar3 = puVar3 + 8;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
      *(int *)(puVar5 + iVar4 * 8 + 0x2c) = param_3;
      *(int *)(puVar5 + *(int *)(&DAT_803f0cd4 + iVar1) * 8 + 0x28) = param_2;
      *(int *)(&DAT_803f0cd4 + iVar1) = *(int *)(&DAT_803f0cd4 + iVar1) + 1;
    }
    os::OSRestoreInterrupts(uVar2);
    uVar2 = 0;
  }
  return uVar2;
}


undefined4 EXIUnlock(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  code *pcVar4;
  
  iVar1 = param_1 * 0x40;
  uVar3 = os::OSDisableInterrupts();
  if ((*(uint *)(&DAT_803f0cbc + iVar1) & 0x10) == 0) {
    os::OSRestoreInterrupts(uVar3);
    uVar3 = 0;
  }
  else {
    *(uint *)(&DAT_803f0cbc + iVar1) = *(uint *)(&DAT_803f0cbc + iVar1) & 0xffffffef;
    SetExiInterruptMask(param_1,&Ecb + iVar1);
    if (0 < *(int *)(&DAT_803f0cd4 + iVar1)) {
      pcVar4 = *(code **)(&DAT_803f0cdc + iVar1);
      iVar2 = *(int *)(&DAT_803f0cd4 + iVar1) + -1;
      *(int *)(&DAT_803f0cd4 + iVar1) = iVar2;
      if (0 < iVar2) {
        MSL_C.PPCEABI.bare.H::memmove
                  (&DAT_803f0cd8 + iVar1,&DAT_803f0ce0 + iVar1,*(int *)(&DAT_803f0cd4 + iVar1) << 3)
        ;
      }
      (*pcVar4)(param_1,0);
    }
    os::OSRestoreInterrupts(uVar3);
    uVar3 = 1;
  }
  return uVar3;
}


undefined4 EXIGetState(int param_1)

{
  return *(undefined4 *)(&DAT_803f0cbc + param_1 * 0x40);
}


void UnlockedHandler(undefined4 param_1)

{
  undefined auStack8 [8];
  
  EXIGetID(param_1,0,auStack8);
  return;
}


undefined4 EXIGetID(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  undefined4 uVar10;
  code *pcVar11;
  int unaff_r29;
  undefined4 local_24;
  
  iVar1 = param_1 * 0x40;
  if ((param_1 < 2) && (param_2 == 0)) {
    iVar9 = __EXIProbe(param_1);
    if (iVar9 == 0) {
      return 0;
    }
    if ((&DAT_803f0cd0)[param_1 * 0x10] == (&DAT_800030c0)[param_1]) {
      *param_3 = *(undefined4 *)(&DAT_803f0ccc + iVar1);
      return (&DAT_803f0cd0)[param_1 * 0x10];
    }
    uVar10 = os::OSDisableInterrupts();
    if (((*(uint *)(&DAT_803f0cbc + iVar1) & 8) == 0) && (iVar9 = __EXIProbe(param_1), iVar9 != 0))
    {
      EXIClearInterrupts(param_1,1,0,0);
      *(undefined4 *)(&DAT_803f0cb8 + iVar1) = 0;
      os::__OSUnmaskInterrupts(0x100000 >> param_1 * 3);
      *(uint *)(&DAT_803f0cbc + iVar1) = *(uint *)(&DAT_803f0cbc + iVar1) | 8;
      os::OSRestoreInterrupts(uVar10);
      bVar2 = true;
    }
    else {
      os::OSRestoreInterrupts(uVar10);
      bVar2 = false;
    }
    if (!bVar2) {
      return 0;
    }
    unaff_r29 = (&DAT_800030c0)[param_1];
  }
  bVar2 = false;
  if ((param_1 < 2) && (param_2 == 0)) {
    bVar2 = true;
  }
  if (bVar2) {
    pcVar11 = UnlockedHandler;
  }
  else {
    pcVar11 = (code *)0x0;
  }
  uVar10 = EXILock(param_1,param_2,pcVar11);
  uVar3 = countLeadingZeros(uVar10);
  uVar3 = uVar3 >> 5;
  if (uVar3 == 0) {
    uVar10 = EXISelect(param_1,param_2,0);
    uVar4 = countLeadingZeros(uVar10);
    uVar3 = uVar4 >> 5;
    if (uVar3 == 0) {
      local_24 = 0;
      uVar10 = EXIImm(param_1,&local_24,2,1,0);
      uVar3 = countLeadingZeros(uVar10);
      uVar10 = EXISync(param_1);
      uVar5 = countLeadingZeros(uVar10);
      uVar10 = EXIImm(param_1,param_3,4,0,0);
      uVar6 = countLeadingZeros(uVar10);
      uVar10 = EXISync(param_1);
      uVar7 = countLeadingZeros(uVar10);
      uVar10 = EXIDeselect(param_1);
      uVar8 = countLeadingZeros(uVar10);
      uVar3 = (uVar4 | uVar3 | uVar5 | uVar6 | uVar7 | uVar8) >> 5;
    }
    uVar10 = os::OSDisableInterrupts();
    if ((*(uint *)(&DAT_803f0cbc + iVar1) & 0x10) == 0) {
      os::OSRestoreInterrupts(uVar10);
    }
    else {
      *(uint *)(&DAT_803f0cbc + iVar1) = *(uint *)(&DAT_803f0cbc + iVar1) & 0xffffffef;
      SetExiInterruptMask(param_1,&Ecb + iVar1);
      if (0 < *(int *)(&DAT_803f0cd4 + iVar1)) {
        pcVar11 = *(code **)(&DAT_803f0cdc + iVar1);
        iVar9 = *(int *)(&DAT_803f0cd4 + iVar1) + -1;
        *(int *)(&DAT_803f0cd4 + iVar1) = iVar9;
        if (0 < iVar9) {
          MSL_C.PPCEABI.bare.H::memmove
                    (&DAT_803f0cd8 + iVar1,&DAT_803f0ce0 + iVar1,
                     *(int *)(&DAT_803f0cd4 + iVar1) << 3);
        }
        (*pcVar11)(param_1,0);
      }
      os::OSRestoreInterrupts(uVar10);
    }
  }
  if ((param_1 < 2) && (param_2 == 0)) {
    uVar10 = os::OSDisableInterrupts();
    if ((*(uint *)(&DAT_803f0cbc + iVar1) & 8) == 0) {
      os::OSRestoreInterrupts(uVar10);
    }
    else {
      if (((*(uint *)(&DAT_803f0cbc + iVar1) & 0x10) == 0) || (*(int *)(&DAT_803f0cc8 + iVar1) != 0)
         ) {
        *(uint *)(&DAT_803f0cbc + iVar1) = *(uint *)(&DAT_803f0cbc + iVar1) & 0xfffffff7;
        os::__OSMaskInterrupts(0x500000 >> param_1 * 3);
        os::OSRestoreInterrupts(uVar10);
      }
      else {
        os::OSRestoreInterrupts(uVar10);
      }
    }
    os::OSDisableInterrupts();
    uVar3 = uVar3 | (&DAT_800030c0)[param_1] != unaff_r29;
    if (uVar3 == 0) {
      *(undefined4 *)(&DAT_803f0ccc + iVar1) = *param_3;
      (&DAT_803f0cd0)[param_1 * 0x10] = unaff_r29;
    }
    os::OSRestoreInterrupts();
    if (uVar3 == 0) {
      uVar10 = (&DAT_803f0cd0)[param_1 * 0x10];
    }
    else {
      uVar10 = 0;
    }
  }
  else {
    if (uVar3 == 0) {
      uVar10 = 1;
    }
    else {
      uVar10 = 0;
    }
  }
  return uVar10;
}

