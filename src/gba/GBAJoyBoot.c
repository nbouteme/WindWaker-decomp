#include <gba/GBAJoyBoot.h>
#include <gba/GBAGetProcessStatus.h>
#include <gba/GBAJoyBoot.h>
#include <gba/GBA.h>
#include <gba/GBARead.h>
#include <os/OSTime.h>
#include <gba/GBAWrite.h>
#include <gba/GBAXfer.h>


namespace gba {

int GBAJoyBootAsync
              (uint param_1,int param_2,int param_3,int param_4,int param_5,undefined4 param_6,
              undefined4 param_7)

{
  int iVar1;
  int iVar2;
  undefined auStack36 [4];
  
  iVar1 = param_1 * 0x100;
  if ((param_1 & 0xfffffffc) == 0) {
    if ((param_5 == 0) || (0x40000 < param_5)) {
      iVar2 = 4;
    }
    else {
      if ((param_3 < -4) || (4 < param_3)) {
        iVar2 = 4;
      }
      else {
        if ((param_2 < 0) || (6 < param_2)) {
          iVar2 = 4;
        }
        else {
          if ((uint)*(byte *)(param_4 + 0xaf) *
              (uint)*(byte *)(param_4 + 0xae) *
              (uint)*(byte *)(param_4 + 0xac) * (uint)*(byte *)(param_4 + 0xad) == 0) {
            iVar2 = 4;
          }
          else {
            iVar2 = GBAGetProcessStatus(param_1,auStack36);
            if (iVar2 == 0) {
              *(int *)(&DAT_803ed320 + iVar1) = param_2;
              *(int *)(&DAT_803ed324 + iVar1) = param_3;
              *(int *)(&DAT_803ed328 + iVar1) = param_4;
              *(int *)(&DAT_803ed32c + iVar1) = param_5;
              *(undefined4 *)(&DAT_803ed330 + iVar1) = param_6;
              *(undefined4 *)(&DAT_803ed334 + iVar1) = param_7;
              *(uint *)(&DAT_803ed354 + iVar1) = (uint)DAT_8039b388;
              iVar2 = GBAGetStatusAsync(param_1,*(undefined4 *)(&DAT_803ed330 + iVar1),F23);
              if (iVar2 != 0) {
                *(undefined4 *)(&DAT_803ed334 + iVar1) = 0;
              }
            }
          }
        }
      }
    }
  }
  else {
    iVar2 = 4;
  }
  return iVar2;
}


void F23(int param_1,int param_2)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = param_1 * 0x100;
  if ((param_2 != 0) ||
     (param_2 = GBAResetAsync(param_1,*(undefined4 *)(&DAT_803ed330 + iVar1),F25), param_2 != 0)) {
    *(undefined4 *)(&DAT_803ed34c + iVar1) = 0;
    *(undefined4 *)(&DAT_803ed348 + iVar1) = 0;
    pcVar2 = *(code **)(&DAT_803ed334 + iVar1);
    if (pcVar2 != (code *)0x0) {
      *(undefined4 *)(&DAT_803ed334 + iVar1) = 0;
      (*pcVar2)(param_1,param_2);
    }
  }
  *(int *)(&DAT_803ed300 + iVar1) = param_2;
  return;
}


void F25(int param_1,int param_2)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = param_1 * 0x100;
  if ((param_2 == 0) && (**(char **)(&DAT_803ed330 + iVar1) != DAT_8039b3a5)) {
    param_2 = 3;
  }
  if ((param_2 != 0) ||
     (param_2 = GBAGetStatusAsync(param_1,*(undefined4 *)(&DAT_803ed330 + iVar1),F27), param_2 != 0)
     ) {
    *(undefined4 *)(&DAT_803ed34c + iVar1) = 0;
    *(undefined4 *)(&DAT_803ed348 + iVar1) = 0;
    pcVar2 = *(code **)(&DAT_803ed334 + iVar1);
    if (pcVar2 != (code *)0x0) {
      *(undefined4 *)(&DAT_803ed334 + iVar1) = 0;
      (*pcVar2)(param_1,param_2);
    }
  }
  *(int *)(&DAT_803ed300 + iVar1) = param_2;
  return;
}


void F27(int param_1,int param_2)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = param_1 * 0x100;
  if ((param_2 == 0) && (**(char **)(&DAT_803ed330 + iVar1) != D54)) {
    param_2 = 3;
  }
  if ((param_2 != 0) ||
     (param_2 = GBAReadAsync(param_1,&DAT_803ed338 + iVar1,*(undefined4 *)(&DAT_803ed330 + iVar1),
                             F29), param_2 != 0)) {
    *(undefined4 *)(&DAT_803ed34c + iVar1) = 0;
    *(undefined4 *)(&DAT_803ed348 + iVar1) = 0;
    pcVar2 = *(code **)(&DAT_803ed334 + iVar1);
    if (pcVar2 != (code *)0x0) {
      *(undefined4 *)(&DAT_803ed334 + iVar1) = 0;
      (*pcVar2)(param_1,param_2);
    }
  }
  *(int *)(&DAT_803ed300 + iVar1) = param_2;
  return;
}


void F29(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  code *pcVar5;
  uint uVar6;
  int *piVar7;
  
  iVar1 = param_1 * 0x100;
  piVar7 = (int *)(&DAT_803ed320 + iVar1);
  if (param_2 == 0) {
    *(uint *)(&DAT_803ed378 + iVar1) =
         (uint)(byte)((&DAT_803ed338)[iVar1] ^ s____Coded_by_Kawasedo_8039b389[16]) |
         (uint)(byte)((&DAT_803ed339)[iVar1] ^ s____Coded_by_Kawasedo_8039b389[6]) << 8 |
         (uint)(byte)((&DAT_803ed33b)[iVar1] ^ s____Coded_by_Kawasedo_8039b389[19]) << 0x18 |
         (uint)(byte)((&DAT_803ed33a)[iVar1] ^ s____Coded_by_Kawasedo_8039b389[5]) << 0x10;
    if (((((&DAT_803ed33b)[iVar1] == '\0') || ((&DAT_803ed33a)[iVar1] == '\0')) ||
        ((*(uint *)(&DAT_803ed378 + iVar1) & (uint)DAT_8039b385 << 9) == 0)) ||
       ((((&DAT_803ed339)[iVar1] == '\0' || (*(uint *)(&DAT_803ed378 + iVar1) >> 0xf == 0)) ||
        ((&DAT_803ed338)[iVar1] == '\0')))) {
      param_2 = 3;
    }
    else {
      iVar4 = *(int *)(&DAT_803ed324 + iVar1);
      if (iVar4 == 0) {
        *(uint *)(&DAT_803ed37c + iVar1) = (*piVar7 << 1 | 0x70U) << 0x10;
      }
      else {
        if (iVar4 < 0) {
          if (-5 < iVar4) {
            *(int *)(&DAT_803ed37c + iVar1) = (*piVar7 << 4 | (3 - iVar4) * 2) << 0x10;
          }
        }
        else {
          if (iVar4 < 5) {
            *(int *)(&DAT_803ed37c + iVar1) = (*piVar7 << 4 | (iVar4 + -1) * 2) << 0x10;
          }
        }
      }
      *(uint *)(&DAT_803ed340 + iVar1) =
           ~(uint)DAT_8039b3a4 & *(int *)(&DAT_803ed32c + iVar1) + (uint)DAT_8039b3a4;
      uVar2 = (uint)(byte)s____Coded_by_Kawasedo_8039b389[11] << (uint)DAT_8039b3a1;
      if (*(int *)(&DAT_803ed340 + iVar1) < (int)uVar2) {
        *(uint *)(&DAT_803ed340 + iVar1) = uVar2;
      }
      *(undefined4 *)(&DAT_803ed384 + iVar1) = *(undefined4 *)(&DAT_803ed340 + iVar1);
      *(uint *)(&DAT_803ed340 + iVar1) = *(int *)(&DAT_803ed340 + iVar1) - uVar2;
      *(int *)(&DAT_803ed340 + iVar1) = *(int *)(&DAT_803ed340 + iVar1) >> (DAT_8039b3a0 & 0x3f);
      uVar6 = *(uint *)(&DAT_803ed340 + iVar1);
      *(uint *)(&DAT_803ed37c + iVar1) =
           *(uint *)(&DAT_803ed37c + iVar1) |
           uVar6 & DAT_8039b384 |
           (uVar6 & (uint)DAT_8039b383 << (uint)DAT_8039b3a4) << (uint)DAT_8039b39f |
           (uVar6 & ((uint)DAT_8039b383 | (uint)DAT_8039b386 << (uint)DAT_8039b3a5)) <<
           (uint)DAT_8039b387;
      uVar6 = *(uint *)(&DAT_803ed37c + iVar1);
      *(uint *)(&DAT_803ed37c + iVar1) =
           uVar6 | (uint)DAT_8039b383 |
                   (uint)(byte)s____Coded_by_Kawasedo_8039b389[8] << 10 |
                   (uint)DAT_8039b385 << 0x11 |
                   (uint)DAT_8039b383 << 0x18 |
                   (uVar6 + ((int)uVar6 >> 8) + ((int)uVar6 >> 0x10)) * 0x1000000;
      uVar6 = *(uint *)(&DAT_803ed37c + iVar1);
      if ((uVar6 & uVar2) == 0) {
        (&DAT_803ed33c)[iVar1] = (byte)uVar6 ^ s____Coded_by_Kawasedo_8039b389[12];
        (&DAT_803ed33d)[iVar1] =
             (byte)((uint)*(undefined4 *)(&DAT_803ed37c + iVar1) >> 8) ^
             s____Coded_by_Kawasedo_8039b389[13];
        (&DAT_803ed33f)[iVar1] =
             (byte)((uint)*(undefined4 *)(&DAT_803ed37c + iVar1) >> 0x18) ^
             s____Coded_by_Kawasedo_8039b389[13];
        (&DAT_803ed33e)[iVar1] =
             (byte)((uint)*(undefined4 *)(&DAT_803ed37c + iVar1) >> 0x10) ^
             s____Coded_by_Kawasedo_8039b389[14];
      }
      else {
        (&DAT_803ed33f)[iVar1] = (byte)(uVar6 >> 0x18) ^ s____Coded_by_Kawasedo_8039b389[4];
        (&DAT_803ed33e)[iVar1] =
             (byte)((uint)*(undefined4 *)(&DAT_803ed37c + iVar1) >> 0x10) ^
             s____Coded_by_Kawasedo_8039b389[7];
        (&DAT_803ed33c)[iVar1] =
             (byte)*(undefined4 *)(&DAT_803ed37c + iVar1) ^ s____Coded_by_Kawasedo_8039b389[16];
        (&DAT_803ed33d)[iVar1] =
             (byte)((uint)*(undefined4 *)(&DAT_803ed37c + iVar1) >> 8) ^
             s____Coded_by_Kawasedo_8039b389[17];
      }
      iVar3 = DAT_8039b3a6 + 1;
      *(int *)(&DAT_803ed358 + iVar1) = iVar3 << (uint)DAT_8039b3a2;
      *(uint *)(&DAT_803ed354 + iVar1) = (uint)DAT_8039b388;
      iVar4 = os::OSGetTime();
      *(int *)(&DAT_803ed34c + iVar1) = iVar3;
      *(int *)(&DAT_803ed348 + iVar1) = iVar4;
      *(undefined4 *)(&DAT_803ed350 + iVar1) = 1;
      param_2 = GBAWriteAsync(param_1,&DAT_803ed33c + iVar1,*(undefined4 *)(&DAT_803ed330 + iVar1),
                              F31);
    }
  }
  if (param_2 != 0) {
    *(undefined4 *)(&DAT_803ed34c + iVar1) = 0;
    *(undefined4 *)(&DAT_803ed348 + iVar1) = 0;
    pcVar5 = *(code **)(&DAT_803ed334 + iVar1);
    if (pcVar5 != (code *)0x0) {
      *(undefined4 *)(&DAT_803ed334 + iVar1) = 0;
      (*pcVar5)(param_1,param_2);
    }
  }
  *(int *)(&DAT_803ed300 + iVar1) = param_2;
  return;
}


void F31(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  byte *pbVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  code *pcVar10;
  undefined *puVar11;
  
  iVar2 = param_1 * 0x100;
  puVar11 = &DAT_803ed320 + iVar2;
  if (param_2 != 0) goto LAB_802a1178;
  if (*(int *)(&DAT_803ed350 + iVar2) == 0) {
    if ((**(byte **)(&DAT_803ed330 + iVar2) & s____Coded_by_Kawasedo_8039b389[11]) != 0) {
      if ((int)(uint)(**(byte **)(&DAT_803ed330 + iVar2) & DAT_8039b3aa) >> (DAT_8039b3a1 & 0x3f) ==
          (int)(*(uint *)(&DAT_803ed354 + iVar2) & (uint)DAT_8039b3a1) >> (DAT_8039b39f & 0x3f)) {
        *(uint *)(&DAT_803ed354 + iVar2) =
             *(uint *)(&DAT_803ed354 + iVar2) -
             ((uint)(byte)s____Coded_by_Kawasedo_8039b389[16] -
             (uint)(byte)s____Coded_by_Kawasedo_8039b389[14]);
        goto LAB_802a0df0;
      }
    }
    param_2 = 3;
  }
  else {
    *(undefined4 *)(&DAT_803ed350 + iVar2) = 0;
LAB_802a0df0:
    iVar5 = *(int *)(&DAT_803ed354 + iVar2);
    if (*(int *)(&DAT_803ed384 + iVar2) < iVar5) {
      uVar4 = os::OSGetTick();
      *(undefined4 *)(&DAT_803ed344 + iVar2) = uVar4;
      param_2 = GBAReadAsync(param_1,&DAT_803ed338 + iVar2,*(undefined4 *)(&DAT_803ed330 + iVar2),
                             F33);
    }
    else {
      if (iVar5 < *(int *)(&DAT_803ed384 + iVar2)) {
        uVar3 = (uint)(byte)s____Coded_by_Kawasedo_8039b389[20];
        *(uint *)(&DAT_803ed340 + iVar2) = (uint)(byte)s____Coded_by_Kawasedo_8039b389[20];
        while (*(int *)(&DAT_803ed340 + iVar2) < (int)(uint)DAT_8039b3a1) {
          if (*(int *)(&DAT_803ed32c + iVar2) != 0) {
            pbVar6 = *(byte **)(&DAT_803ed328 + iVar2);
            *(byte **)(&DAT_803ed328 + iVar2) = pbVar6 + 1;
            uVar8 = (uint)DAT_8039b3a5;
            bVar1 = *pbVar6;
            *(int *)(&DAT_803ed32c + iVar2) = *(int *)(&DAT_803ed32c + iVar2) + -1;
            uVar3 = uVar3 | (uint)bVar1 << *(int *)(&DAT_803ed340 + iVar2) * uVar8;
          }
          *(int *)(&DAT_803ed340 + iVar2) = *(int *)(&DAT_803ed340 + iVar2) + 1;
        }
        if (*(uint *)(&DAT_803ed354 + iVar2) == (uint)DAT_8039b3a6) {
          *(uint *)(&DAT_803ed380 + iVar2) = uVar3;
        }
        else {
          if (*(uint *)(&DAT_803ed354 + iVar2) == (uint)DAT_8039b3a7) {
            uVar3 = param_1 << (uint)DAT_8039b3a5;
          }
        }
        if ((int)(uint)DAT_8039b382 <= *(int *)(&DAT_803ed354 + iVar2)) {
          uVar8 = *(uint *)(&DAT_803ed358 + iVar2);
          uVar7 = (uint)(byte)s____Coded_by_Kawasedo_8039b389[11];
          uVar9 = uVar3;
          while( true ) {
            if ((int)uVar7 <= (int)(uint)DAT_8039b39e) break;
            if (((uVar9 ^ uVar8) & 1) == 0) {
              uVar8 = uVar8 >> 1;
            }
            else {
              uVar8 = uVar8 >> 1 ^
                      (uint)DAT_8039b3a6 * 0x100 +
                      (((uint)DAT_8039b3a8 + (uint)DAT_8039b3ab + (uint)DAT_8039b3ab * -0x10) -
                      (uint)DAT_8039b3a3);
            }
            uVar9 = uVar9 >> 1;
            uVar7 = uVar7 - 1;
          }
          *(uint *)(&DAT_803ed358 + iVar2) = uVar8;
        }
        if (*(int *)(&DAT_803ed354 + iVar2) == DAT_8039b3a8 + 0x100) {
          *(uint *)(&DAT_803ed35c + iVar2) = uVar3;
        }
        else {
          if (*(int *)(&DAT_803ed354 + iVar2) == DAT_8039b381 + 0x100) {
            *(uint *)(&DAT_803ed340 + iVar2) = (uint)DAT_8039b387;
            *(uint *)(puVar11 + *(int *)(&DAT_803ed340 + iVar2) * 4 + 0x3c) = uVar3;
          }
        }
      }
      else {
        uVar3 = *(uint *)(&DAT_803ed358 + iVar2) | iVar5 << 0x10;
      }
      if ((int)(uint)DAT_8039b3ab < *(int *)(&DAT_803ed354 + iVar2)) {
        *(uint *)(&DAT_803ed378 + iVar2) =
             *(int *)(&DAT_803ed378 + iVar2) *
             ((uint)(byte)s____Coded_by_Kawasedo_8039b389[14] << (uint)DAT_8039b3aa |
             (uint)(byte)s____Coded_by_Kawasedo_8039b389[12] |
             (uint)(byte)s____Coded_by_Kawasedo_8039b389[15] << (uint)DAT_8039b3a5 |
             (uint)(byte)s____Coded_by_Kawasedo_8039b389[15] << (uint)DAT_8039b3ac) -
             ((uint)(byte)s____Coded_by_Kawasedo_8039b389[18] -
             (uint)(byte)s____Coded_by_Kawasedo_8039b389[17]);
        uVar3 = uVar3 ^ *(uint *)(&DAT_803ed378 + iVar2) ^
                -(*(int *)(&DAT_803ed354 + iVar2) +
                 (uint)(byte)s____Coded_by_Kawasedo_8039b389[2] * 0x100000) ^
                ((uint)(byte)s____Coded_by_Kawasedo_8039b389[9] << 8 |
                (uint)(byte)s____Coded_by_Kawasedo_8039b389[10] << 0x10 |
                (uint)(byte)s____Coded_by_Kawasedo_8039b389[2] << 0x18 |
                (uint)(byte)s____Coded_by_Kawasedo_8039b389[2]);
      }
      (&DAT_803ed33f)[iVar2] = (char)(uVar3 >> (uint)D54);
      (&DAT_803ed33c)[iVar2] = (char)(uVar3 >> (uint)DAT_8039b39e);
      (&DAT_803ed33d)[iVar2] = (char)(uVar3 >> (uint)DAT_8039b3a9);
      (&DAT_803ed33e)[iVar2] = (char)(uVar3 >> (uint)DAT_8039b3aa);
      if (*(int *)(&DAT_803ed354 + iVar2) == (uint)DAT_8039b381 + (uint)DAT_8039b381) {
        *(uint *)(&DAT_803ed364 + iVar2) = uVar3;
      }
      if (*(int *)(&DAT_803ed340 + iVar2) < (int)(uint)DAT_8039b3a1) {
        *(uint *)(puVar11 + (3 - (1 - *(int *)(&DAT_803ed340 + iVar2))) * 4 + 0x3c) = uVar3;
        iVar5 = *(int *)(&DAT_803ed340 + iVar2);
        *(int *)(puVar11 + (5 - iVar5) * 4 + 0x3c) =
             *(int *)(puVar11 + (2 - (1 - iVar5)) * 4 + 0x3c) *
             *(int *)(puVar11 + (4 - iVar5) * 4 + 0x3c);
        iVar5 = 1 - *(int *)(&DAT_803ed340 + iVar2);
        *(int *)(puVar11 + (5 - iVar5) * 4 + 0x3c) =
             *(int *)(puVar11 + iVar5 * 4 + 0x3c) *
             *(int *)(puVar11 + *(int *)(&DAT_803ed340 + iVar2) * 4 + 0x3c);
        iVar5 = *(int *)(&DAT_803ed340 + iVar2);
        *(int *)(puVar11 + (7 - iVar5) * 4 + 0x3c) =
             *(int *)(puVar11 + (1 - iVar5) * -4 + 0x3c) *
             *(int *)(puVar11 + (4 - iVar5) * 4 + 0x3c);
      }
      param_2 = GBAWriteAsync(param_1,&DAT_803ed33c + iVar2,*(undefined4 *)(&DAT_803ed330 + iVar2),
                              F31);
    }
  }
LAB_802a1178:
  if (param_2 != 0) {
    *(undefined4 *)(&DAT_803ed34c + iVar2) = 0;
    *(undefined4 *)(&DAT_803ed348 + iVar2) = 0;
    pcVar10 = *(code **)(&DAT_803ed334 + iVar2);
    if (pcVar10 != (code *)0x0) {
      *(undefined4 *)(&DAT_803ed334 + iVar2) = 0;
      (*pcVar10)(param_1,param_2);
    }
  }
  *(int *)(&DAT_803ed300 + iVar2) = param_2;
  return;
}


void F33(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  byte *pbVar3;
  code *pcVar4;
  undefined *puVar5;
  
  iVar1 = param_1 * 0x100;
  puVar5 = &DAT_803ed320 + iVar1;
  if (param_2 == 0) {
    *(undefined4 *)(&DAT_803ed340 + iVar1) = 0x21;
    while( true ) {
      if (0x23 < *(int *)(&DAT_803ed340 + iVar1)) break;
      pbVar3 = &D54 + *(int *)(&DAT_803ed340 + iVar1);
      param_2 = ((uint)(byte)(&DAT_803ed338)[iVar1] ^ *(uint *)(puVar5 + (uint)*pbVar3 * 4 + 0x3c) |
                (uint)(byte)(&DAT_803ed339)[iVar1] ^
                *(uint *)(puVar5 + (uint)*pbVar3 * 4 + 0x3c) >> 8 |
                (uint)(byte)(&DAT_803ed33b)[iVar1] ^
                *(uint *)(puVar5 + (uint)*pbVar3 * 4 + 0x3c) >> 0x18 |
                (uint)(byte)(&DAT_803ed33a)[iVar1] ^
                *(uint *)(puVar5 + (uint)*pbVar3 * 4 + 0x3c) >> 0x10) << 0x18;
      if (param_2 == 0) break;
      *(int *)(&DAT_803ed340 + iVar1) = *(int *)(&DAT_803ed340 + iVar1) + 1;
    }
    if (param_2 == 0) {
      uVar2 = os::OSGetTick();
      *(undefined4 *)(&DAT_803ed344 + iVar1) = uVar2;
      param_2 = GBAGetStatusAsync(param_1,*(undefined4 *)(&DAT_803ed330 + iVar1),F35);
    }
    else {
      param_2 = 3;
    }
  }
  if (param_2 != 0) {
    *(undefined4 *)(&DAT_803ed34c + iVar1) = 0;
    *(undefined4 *)(&DAT_803ed348 + iVar1) = 0;
    pcVar4 = *(code **)(&DAT_803ed334 + iVar1);
    if (pcVar4 != (code *)0x0) {
      *(undefined4 *)(&DAT_803ed334 + iVar1) = 0;
      (*pcVar4)(param_1,param_2);
    }
  }
  *(int *)(&DAT_803ed300 + iVar1) = param_2;
  return;
}


void F35(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  code *pcVar4;
  
  iVar1 = param_1 * 0x100;
  if (param_2 == 0) {
    iVar2 = os::OSGetTick();
    if ((uint)(iVar2 - *(int *)(&DAT_803ed344 + iVar1)) < (DAT_800000f8 >> 2) * 10) {
      pbVar3 = *(byte **)(&DAT_803ed330 + iVar1);
      if ((*pbVar3 & 0x32) == 0) {
        if (*pbVar3 == 8) {
          __GBASetDelay(param_1,pbVar3,0,(DAT_800000f8 >> 2) / 0x7d & 0x1ffffff8);
          param_2 = GBAReadAsync(param_1,&DAT_803ed338 + iVar1,
                                 *(undefined4 *)(&DAT_803ed330 + iVar1),F37);
          __GBASetDelay(param_1,0x431bde83,0,((DAT_800000f8 >> 2) / 0x1e848) * 0x3c >> 3);
        }
        else {
          param_2 = GBAGetStatusAsync(param_1,pbVar3,F35);
        }
      }
      else {
        param_2 = 3;
      }
    }
    else {
      param_2 = 3;
    }
  }
  if (param_2 != 0) {
    *(undefined4 *)(&DAT_803ed34c + iVar1) = 0;
    *(undefined4 *)(&DAT_803ed348 + iVar1) = 0;
    pcVar4 = *(code **)(&DAT_803ed334 + iVar1);
    if (pcVar4 != (code *)0x0) {
      *(undefined4 *)(&DAT_803ed334 + iVar1) = 0;
      (*pcVar4)(param_1,param_2);
    }
  }
  *(int *)(&DAT_803ed300 + iVar1) = param_2;
  return;
}


void F37(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  code *pcVar3;
  
  iVar1 = param_1 * 0x100;
  if (param_2 == 0) {
    uVar2 = *(uint *)(&DAT_803ed380 + iVar1);
    if ((((byte)(&DAT_803ed338)[iVar1] ^ uVar2 |
         (uint)(byte)(&DAT_803ed339)[iVar1] ^ uVar2 >> 8 |
         (uint)(byte)(&DAT_803ed33b)[iVar1] ^ uVar2 >> 0x18 |
         (uint)(byte)(&DAT_803ed33a)[iVar1] ^ uVar2 >> 0x10) & 0xff) == 0) {
      param_2 = GBAWriteAsync(param_1,&DAT_803ed338 + iVar1,*(undefined4 *)(&DAT_803ed330 + iVar1),
                              F39);
    }
    else {
      param_2 = 3;
    }
  }
  if (param_2 != 0) {
    *(undefined4 *)(&DAT_803ed34c + iVar1) = 0;
    *(undefined4 *)(&DAT_803ed348 + iVar1) = 0;
    pcVar3 = *(code **)(&DAT_803ed334 + iVar1);
    if (pcVar3 != (code *)0x0) {
      *(undefined4 *)(&DAT_803ed334 + iVar1) = 0;
      (*pcVar3)(param_1,param_2);
    }
  }
  *(int *)(&DAT_803ed300 + iVar1) = param_2;
  return;
}


void F39(int param_1,int param_2)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = param_1 * 0x100;
  if (param_2 == 0) {
    **(undefined **)(&DAT_803ed330 + iVar1) = 0;
  }
  *(undefined4 *)(&DAT_803ed34c + iVar1) = 0;
  *(undefined4 *)(&DAT_803ed348 + iVar1) = 0;
  pcVar2 = *(code **)(&DAT_803ed334 + iVar1);
  if (pcVar2 != (code *)0x0) {
    *(undefined4 *)(&DAT_803ed334 + iVar1) = 0;
    (*pcVar2)(param_1,param_2);
  }
  *(int *)(&DAT_803ed300 + iVar1) = param_2;
  return;
}


void GBAJoyBoot(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = GBAJoyBootAsync();
  if (iVar1 == 0) {
    __GBASync(param_1);
  }
  return;
}

