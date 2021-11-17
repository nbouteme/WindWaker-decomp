#include <MSL_C.PPCEABI.bare.H/ansi_fp.h>
#include <MSL_C.PPCEABI.bare.H/ansi_fp.h>
#include <MSL_C.PPCEABI.bare.H/s_frexp.h>
#include <MSL_C.PPCEABI.bare.H/s_ldexp.h>
#include <MSL_C.PPCEABI.bare.H/s_modf.h>
#include <Runtime.PPCEABI.H/runtime.h>


namespace MSL_C.PPCEABI.bare.H {

void __num2dec(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  short sVar8;
  
  sVar8 = *(short *)(param_1 + 2);
  __num2dec_internal(param_2);
  if (*(byte *)(param_2 + 5) < 10) {
    if (0x24 < sVar8) {
      sVar8 = 0x24;
    }
    iVar7 = (int)sVar8;
    if ((0 < iVar7) && (iVar7 < (int)(uint)*(byte *)(param_2 + 4))) {
      iVar6 = param_2 + iVar7;
      if (*(byte *)(iVar6 + 5) < 6) {
        if (*(byte *)(iVar6 + 5) < 5) {
          iVar6 = -1;
        }
        else {
          pcVar4 = (char *)(iVar6 + 6);
          pcVar3 = (char *)(param_2 + *(byte *)(param_2 + 4) + 5);
          iVar2 = (int)pcVar3 - (int)pcVar4;
          if (pcVar4 < pcVar3) {
            do {
              if (*pcVar4 != '\0') {
                iVar6 = 1;
                goto LAB_80329e90;
              }
              pcVar4 = pcVar4 + 1;
              iVar2 = iVar2 + -1;
            } while (iVar2 != 0);
          }
          if ((*(byte *)(iVar6 + 4) & 1) == 0) {
            iVar6 = -1;
          }
          else {
            iVar6 = 1;
          }
        }
      }
      else {
        iVar6 = 1;
      }
LAB_80329e90:
      *(char *)(param_2 + 4) = (char)sVar8;
      if (-1 < iVar6) {
        for (pbVar5 = (byte *)(param_2 + 5) + iVar7 + -1; 8 < *pbVar5; pbVar5 = pbVar5 + -1) {
          if (pbVar5 == (byte *)(param_2 + 5)) {
            *pbVar5 = 1;
            *(short *)(param_2 + 2) = *(short *)(param_2 + 2) + 1;
            goto LAB_80329f0c;
          }
          *pbVar5 = 0;
        }
        *pbVar5 = *pbVar5 + 1;
      }
    }
LAB_80329f0c:
    while ((int)(uint)*(byte *)(param_2 + 4) < iVar7) {
      bVar1 = *(byte *)(param_2 + 4);
      *(byte *)(param_2 + 4) = bVar1 + 1;
      *(undefined *)(param_2 + bVar1 + 5) = 0;
    }
    *(ushort *)(param_2 + 2) = *(short *)(param_2 + 2) - (*(byte *)(param_2 + 4) - 1);
    for (iVar7 = 0; iVar7 < (int)(uint)*(byte *)(param_2 + 4); iVar7 = iVar7 + 1) {
      *(char *)(param_2 + iVar7 + 5) = *(char *)(param_2 + iVar7 + 5) + '0';
    }
  }
  return;
}


/* WARNING: Could not reconcile some variable overlaps */

void __num2dec_internal(double param_1,char *param_2)

{
  uint uVar1;
  int iVar2;
  char cVar3;
  short sVar4;
  double dVar5;
  undefined8 uVar6;
  double local_a8;
  undefined4 local_a0;
  undefined8 local_98;
  undefined8 local_88;
  double local_80;
  undefined auStack120 [44];
  undefined auStack76 [56];
  
  local_a8._0_4_ = (uint)((ulonglong)param_1 >> 0x20);
  cVar3 = -(char)((longlong)param_1 >> 0x3f);
  if (_620 == param_1) {
    *param_2 = cVar3;
    *(undefined2 *)(param_2 + 2) = 0;
    param_2[4] = '\x01';
    param_2[5] = '\0';
  }
  else {
    local_88._4_4_ = SUB84(param_1,0);
    if ((local_a8._0_4_ & 0x7ff00000) == 0x7ff00000) {
      if ((((ulonglong)param_1 & 0xfffff00000000) == 0) && (local_88._4_4_ == 0)) {
        uVar1 = 2;
      }
      else {
        uVar1 = 1;
      }
    }
    else {
      if (((local_a8._0_4_ & 0x7ff00000) < 0x7ff00000) &&
         (((ulonglong)param_1 & 0x7ff0000000000000) == 0)) {
        if ((((ulonglong)param_1 & 0xfffff00000000) == 0) && (local_88._4_4_ == 0)) {
          uVar1 = 3;
        }
        else {
          uVar1 = 5;
        }
      }
      else {
        uVar1 = 4;
      }
    }
    if (uVar1 < 3) {
      *param_2 = cVar3;
      *(undefined2 *)(param_2 + 2) = 0;
      param_2[4] = '\x01';
      if ((local_a8._0_4_ & 0x7ff00000) == 0x7ff00000) {
        if ((((ulonglong)param_1 & 0xfffff00000000) == 0) && (local_88._4_4_ == 0)) {
          iVar2 = 2;
        }
        else {
          iVar2 = 1;
        }
      }
      else {
        if (((local_a8._0_4_ & 0x7ff00000) < 0x7ff00000) &&
           (((ulonglong)param_1 & 0x7ff0000000000000) == 0)) {
          if ((((ulonglong)param_1 & 0xfffff00000000) == 0) && (local_88._4_4_ == 0)) {
            iVar2 = 3;
          }
          else {
            iVar2 = 5;
          }
        }
        else {
          iVar2 = 4;
        }
      }
      cVar3 = 'I';
      if (iVar2 == 1) {
        cVar3 = 'N';
      }
      param_2[5] = cVar3;
    }
    else {
      local_a8 = param_1;
      if (cVar3 != '\0') {
        local_a8 = -param_1;
      }
      local_88 = param_1;
      dVar5 = frexp(local_a8,&local_a0);
      local_98._4_4_ = SUB84(dVar5,0);
      local_98 = dVar5;
      if (local_98._4_4_ == 0) {
        local_98._0_4_ = (uint)((ulonglong)dVar5 >> 0x20);
        sVar4 = __count_trailing_zerol(local_98._0_4_ | 0x100000);
        sVar4 = sVar4 + 0x20;
      }
      else {
        sVar4 = __count_trailing_zerol();
      }
      __two_exp(auStack120,(int)(short)(local_a0._2_2_ - (0x35 - sVar4)));
      dVar5 = ldexp(dVar5,(int)(short)(0x35 - sVar4));
      modf(dVar5,&local_80);
      uVar6 = Runtime.PPCEABI.H::__cvt_dbl_usll(local_80);
      __ull2dec(auStack76,(int)uVar6,(int)((ulonglong)uVar6 >> 0x20),(int)uVar6);
      __timesdec(param_2,auStack76,auStack120);
      *param_2 = cVar3;
    }
  }
  return;
}


void __two_exp(undefined4 *param_1,ushort param_2)

{
  undefined auStack200 [44];
  undefined auStack156 [44];
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined2 local_48;
  undefined auStack68 [56];
  
  switch(param_2) {
  case 0:
    __str2dec(param_1,"1",0);
    break;
  case 1:
    __str2dec(param_1,"2",0);
    break;
  case 2:
    __str2dec(param_1,"4",0);
    break;
  case 3:
    __str2dec(param_1,"8",0);
    break;
  case 4:
    __str2dec(param_1,"16",1);
    break;
  case 5:
    __str2dec(param_1,"32",1);
    break;
  case 6:
    __str2dec(param_1,"64",1);
    break;
  case 7:
    __str2dec(param_1,"128",2);
    break;
  case 8:
    __str2dec(param_1,"256",2);
    break;
  case 0xffffffc0:
    __str2dec(param_1,"542101086242752217003726400434970855712890625",0xffffffec);
    break;
  default:
    __two_exp(auStack68,(int)((short)param_2 / 2));
    __timesdec(param_1,auStack68,auStack68);
    if ((param_2 & 1) != 0) {
      local_70 = *param_1;
      local_6c = param_1[1];
      local_68 = param_1[2];
      local_64 = param_1[3];
      local_60 = param_1[4];
      local_5c = param_1[5];
      local_58 = param_1[6];
      local_54 = param_1[7];
      local_50 = param_1[8];
      local_4c = param_1[9];
      local_48 = *(undefined2 *)(param_1 + 10);
      if ((short)param_2 < 1) {
        __str2dec(auStack200,"5",0xffffffff);
        __timesdec(param_1,&local_70,auStack200);
      }
      else {
        __str2dec(auStack156,"2",0);
        __timesdec(param_1,&local_70,auStack156);
      }
    }
    break;
  case 0xffffffcb:
    __str2dec(param_1,"11102230246251565404236316680908203125",0xfffffff0);
    break;
  case 0xffffffe0:
    __str2dec(param_1,"23283064365386962890625",0xfffffff6);
    break;
  case 0xfffffff0:
    __str2dec(param_1,"152587890625",0xfffffffb);
    break;
  case 0xfffffff8:
    __str2dec(param_1,"390625",0xfffffffd);
    break;
  case 0xfffffff9:
    __str2dec(param_1,"78125",0xfffffffd);
    break;
  case 0xfffffffa:
    __str2dec(param_1,"15625",0xfffffffe);
    break;
  case 0xfffffffb:
    __str2dec(param_1,"3125",0xfffffffe);
    break;
  case 0xfffffffc:
    __str2dec(param_1,"625",0xfffffffe);
    break;
  case 0xfffffffd:
    __str2dec(param_1,"125",0xffffffff);
    break;
  case 0xfffffffe:
    __str2dec(param_1,"25",0xffffffff);
    break;
  case 0xffffffff:
    __str2dec(param_1,"5",0xffffffff);
  }
  return;
}


void __str2dec(undefined *param_1,char *param_2,undefined2 param_3)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  
  *(undefined2 *)(param_1 + 2) = param_3;
  iVar3 = 0;
  *param_1 = 0;
  for (; (iVar3 < 0x24 && (*param_2 != '\0')); param_2 = param_2 + 1) {
    iVar1 = iVar3 + 5;
    iVar3 = iVar3 + 1;
    param_1[iVar1] = *param_2 + -0x30;
  }
  param_1[4] = (char)iVar3;
  if (*param_2 == '\0') {
    return;
  }
  if (*param_2 < '\x05') {
    return;
  }
  do {
    param_2 = param_2 + 1;
    if (*param_2 == '\0') {
      if ((param_1[iVar3 + 4] & 1) == 0) {
        return;
      }
      break;
    }
  } while (*param_2 == '0');
  pbVar2 = param_1 + 5 + ((byte)param_1[4] - 1);
  while( true ) {
    if (*pbVar2 < 9) {
      *pbVar2 = *pbVar2 + 1;
      return;
    }
    if (pbVar2 == param_1 + 5) break;
    *pbVar2 = 0;
    pbVar2 = pbVar2 + -1;
  }
  *pbVar2 = 1;
  *(short *)(param_1 + 2) = *(short *)(param_1 + 2) + 1;
  return;
}


void __timesdec(undefined *param_1,int param_2,int param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte *pbVar6;
  byte *pbVar7;
  byte *pbVar8;
  byte *pbVar9;
  byte *pbVar10;
  byte *pbVar11;
  byte *pbVar12;
  byte *pbVar13;
  byte *pbVar14;
  byte bVar15;
  byte bVar16;
  char cVar17;
  int iVar18;
  byte *pbVar19;
  byte *pbVar20;
  byte *pbVar21;
  uint uVar22;
  uint uVar23;
  int iVar24;
  uint uVar25;
  byte *pbVar26;
  int iVar27;
  byte abStack89 [77];
  
  uVar25 = 0;
  iVar27 = (uint)*(byte *)(param_2 + 4) + (*(byte *)(param_3 + 4) - 1);
  *param_1 = 0;
  pbVar21 = (byte *)((int)register0x00000004 + -0x58) + iVar27 + 1;
  pbVar20 = pbVar21;
  for (; 0 < iVar27; iVar27 = iVar27 + -1) {
    iVar18 = *(byte *)(param_3 + 4) - 1;
    iVar24 = (iVar27 - iVar18) + -1;
    if (iVar24 < 0) {
      iVar24 = 0;
      iVar18 = iVar27 + -1;
    }
    uVar22 = (uint)*(byte *)(param_2 + 4) - iVar24;
    pbVar26 = (byte *)(param_2 + iVar24 + 5);
    pbVar19 = (byte *)(param_3 + iVar18 + 5);
    uVar23 = iVar18 + 1U;
    if ((int)uVar22 < (int)(iVar18 + 1U)) {
      uVar23 = uVar22;
    }
    if (0 < (int)uVar23) {
      uVar22 = uVar23 >> 3;
      if (uVar22 != 0) {
        do {
          bVar15 = *pbVar26;
          bVar16 = *pbVar19;
          pbVar1 = pbVar26 + 1;
          pbVar2 = pbVar19 + -1;
          pbVar3 = pbVar26 + 2;
          pbVar4 = pbVar19 + -2;
          pbVar5 = pbVar26 + 3;
          pbVar6 = pbVar19 + -3;
          pbVar7 = pbVar26 + 4;
          pbVar8 = pbVar19 + -4;
          pbVar9 = pbVar26 + 5;
          pbVar10 = pbVar19 + -5;
          pbVar11 = pbVar26 + 6;
          pbVar12 = pbVar19 + -6;
          pbVar13 = pbVar26 + 7;
          pbVar14 = pbVar19 + -7;
          pbVar26 = pbVar26 + 8;
          pbVar19 = pbVar19 + -8;
          uVar25 = uVar25 + (uint)bVar15 * (uint)bVar16 + (uint)*pbVar1 * (uint)*pbVar2 +
                   (uint)*pbVar3 * (uint)*pbVar4 + (uint)*pbVar5 * (uint)*pbVar6 +
                   (uint)*pbVar7 * (uint)*pbVar8 + (uint)*pbVar9 * (uint)*pbVar10 +
                   (uint)*pbVar11 * (uint)*pbVar12 + (uint)*pbVar13 * (uint)*pbVar14;
          uVar22 = uVar22 - 1;
        } while (uVar22 != 0);
        uVar23 = uVar23 & 7;
        if (uVar23 == 0) goto LAB_8032a724;
      }
      do {
        bVar15 = *pbVar26;
        pbVar26 = pbVar26 + 1;
        bVar16 = *pbVar19;
        pbVar19 = pbVar19 + -1;
        uVar25 = uVar25 + (uint)bVar15 * (uint)bVar16;
        uVar23 = uVar23 - 1;
      } while (uVar23 != 0);
    }
LAB_8032a724:
    uVar23 = uVar25 / 10;
    cVar17 = (char)uVar25;
    uVar25 = uVar25 / 10;
    pbVar20 = pbVar20 + -1;
    *pbVar20 = cVar17 + (char)uVar23 * -10;
  }
  *(short *)(param_1 + 2) = *(short *)(param_2 + 2) + *(short *)(param_3 + 2);
  if (uVar25 != 0) {
    pbVar20 = pbVar20 + -1;
    *pbVar20 = (byte)uVar25;
    *(short *)(param_1 + 2) = *(short *)(param_1 + 2) + 1;
  }
  iVar27 = 0;
  for (; (iVar27 < 0x24 && (pbVar20 < pbVar21)); pbVar20 = pbVar20 + 1) {
    iVar18 = iVar27 + 5;
    iVar27 = iVar27 + 1;
    param_1[iVar18] = *pbVar20;
  }
  param_1[4] = (char)iVar27;
  if ((pbVar20 < pbVar21) && (4 < *pbVar20)) {
    if (*pbVar20 == 5) {
      pbVar19 = pbVar20 + 1;
      iVar27 = (int)pbVar21 - (int)pbVar19;
      if (pbVar19 < pbVar21) {
        do {
          if (*pbVar19 != 0) goto LAB_8032a7f0;
          pbVar19 = pbVar19 + 1;
          iVar27 = iVar27 + -1;
        } while (iVar27 != 0);
      }
      if ((pbVar20[-1] & 1) == 0) {
        return;
      }
    }
LAB_8032a7f0:
    for (pbVar20 = param_1 + 5 + ((byte)param_1[4] - 1); 8 < *pbVar20; pbVar20 = pbVar20 + -1) {
      if (pbVar20 == param_1 + 5) {
        *pbVar20 = 1;
        *(short *)(param_1 + 2) = *(short *)(param_1 + 2) + 1;
        return;
      }
      *pbVar20 = 0;
    }
    *pbVar20 = *pbVar20 + 1;
  }
  return;
}


void __ull2dec
               (undefined *param_1,undefined4 param_2,uint param_3,uint param_4)

{
  byte bVar1;
  undefined uVar2;
  undefined *puVar3;
  undefined extraout_r4;
  undefined *puVar4;
  undefined4 uVar5;
  longlong lVar6;
  
  lVar6 = CONCAT44(param_3,param_4);
  *param_1 = 0;
  if ((param_4 | param_3) == 0) {
    *(undefined2 *)(param_1 + 2) = 0;
    param_1[4] = 1;
    param_1[5] = 0;
  }
  else {
    param_1[4] = 0;
    while( true ) {
      uVar5 = (undefined4)((ulonglong)lVar6 >> 0x20);
      if (lVar6 == 0) break;
      Runtime.PPCEABI.H::__mod2u(uVar5,(int)lVar6,0,10);
      bVar1 = param_1[4];
      param_1[4] = bVar1 + 1;
      param_1[bVar1 + 5] = extraout_r4;
      lVar6 = Runtime.PPCEABI.H::__div2u(uVar5,(int)lVar6,0,10);
    }
    puVar3 = param_1 + (byte)param_1[4] + 5;
    for (puVar4 = param_1 + 5; puVar3 = puVar3 + -1, puVar4 < puVar3; puVar4 = puVar4 + 1) {
      uVar2 = *puVar4;
      *puVar4 = *puVar3;
      *puVar3 = uVar2;
    }
    *(ushort *)(param_1 + 2) = (byte)param_1[4] - 1;
  }
  return;
}


int __count_trailing_zerol(uint param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  iVar2 = 0x20;
  uVar5 = 0xffff;
  uVar3 = 0x10;
  iVar1 = 0;
  iVar4 = 0x10;
  do {
    if (iVar2 == 0) {
      return iVar1;
    }
    if ((param_1 & uVar5) == 0) {
      iVar1 = iVar1 + iVar4;
      param_1 = param_1 >> iVar4;
      iVar2 = iVar2 - iVar4;
    }
    else {
      if (uVar5 == 1) {
        return iVar1;
      }
    }
    if (1 < uVar3) {
      uVar3 = (int)uVar3 >> 1;
    }
    if (1 < uVar5) {
      uVar5 = uVar5 >> uVar3;
      iVar4 = iVar4 - uVar3;
    }
  } while( true );
}

