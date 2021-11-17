#include <TRK_MINNOW_DOLPHIN/support.h>
#include <TRK_MINNOW_DOLPHIN/msgbuf.h>
#include <TRK_MINNOW_DOLPHIN/support.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <TRK_MINNOW_DOLPHIN/msg.h>
#include <TRK_MINNOW_DOLPHIN/serpoll.h>


namespace TRK_MINNOW_DOLPHIN {

int HandlePositionFileSupportRequest
              (undefined4 param_1,undefined4 *param_2,undefined param_3,undefined *param_4)

{
  int iVar1;
  uint uVar2;
  undefined4 unaff_r31;
  int local_28;
  undefined4 local_24;
  undefined4 local_20 [2];
  
  iVar1 = TRKGetFreeBuffer(&local_24,&local_28);
  if (iVar1 == 0) {
    uVar2 = *(uint *)(local_28 + 0xc);
    if (uVar2 < 0x880) {
      *(uint *)(local_28 + 0xc) = uVar2 + 1;
      iVar1 = 0;
      *(undefined *)(local_28 + uVar2 + 0x10) = 0xd4;
      *(int *)(local_28 + 8) = *(int *)(local_28 + 8) + 1;
    }
    else {
      iVar1 = 0x301;
    }
  }
  if (iVar1 == 0) {
    iVar1 = TRKAppendBuffer1_ui32(local_28,param_1);
  }
  if (iVar1 == 0) {
    iVar1 = TRKAppendBuffer1_ui32(local_28,*param_2);
  }
  if (iVar1 == 0) {
    uVar2 = *(uint *)(local_28 + 0xc);
    if (uVar2 < 0x880) {
      *(uint *)(local_28 + 0xc) = uVar2 + 1;
      iVar1 = 0;
      *(undefined *)(local_28 + uVar2 + 0x10) = param_3;
      *(int *)(local_28 + 8) = *(int *)(local_28 + 8) + 1;
    }
    else {
      iVar1 = 0x301;
    }
  }
  if (iVar1 == 0) {
    *param_4 = 0;
    iVar1 = TRKRequestSend(local_28,local_20,3,3,0);
    if (iVar1 == 0) {
      unaff_r31 = TRKGetBuffer(local_20[0]);
      TRKSetBufferPosition(unaff_r31,2);
      iVar1 = TRKReadBuffer1_ui8(unaff_r31,param_4);
    }
    if (iVar1 == 0) {
      iVar1 = TRKReadBuffer1_ui32(unaff_r31,param_2);
    }
    else {
      *param_2 = 0xffffffff;
    }
    TRKReleaseBuffer(local_20[0]);
  }
  TRKReleaseBuffer(local_24);
  return iVar1;
}


int HandleCloseFileSupportRequest(undefined4 param_1,undefined *param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int local_28;
  undefined4 local_24;
  undefined4 local_20 [4];
  
  iVar1 = TRKGetFreeBuffer(&local_24,&local_28);
  if (iVar1 == 0) {
    uVar2 = *(uint *)(local_28 + 0xc);
    if (uVar2 < 0x880) {
      *(uint *)(local_28 + 0xc) = uVar2 + 1;
      iVar1 = 0;
      *(undefined *)(local_28 + uVar2 + 0x10) = 0xd3;
      *(int *)(local_28 + 8) = *(int *)(local_28 + 8) + 1;
    }
    else {
      iVar1 = 0x301;
    }
  }
  if (iVar1 == 0) {
    iVar1 = TRKAppendBuffer1_ui32(local_28,param_1);
  }
  if (iVar1 == 0) {
    *param_2 = 0;
    iVar1 = TRKRequestSend(local_28,local_20,3,3,0);
    if (iVar1 == 0) {
      uVar3 = TRKGetBuffer(local_20[0]);
      TRKSetBufferPosition(uVar3,2);
      iVar1 = TRKReadBuffer1_ui8(uVar3,param_2);
    }
    TRKReleaseBuffer(local_20[0]);
  }
  TRKReleaseBuffer(local_24);
  return iVar1;
}


int HandleOpenFileSupportRequest
              (char *param_1,undefined param_2,undefined4 *param_3,undefined *param_4)

{
  int iVar1;
  uint uVar2;
  size_t sVar3;
  undefined4 unaff_r31;
  int local_28;
  undefined4 local_24;
  undefined4 local_20 [2];
  
  *param_3 = 0;
  iVar1 = TRKGetFreeBuffer(&local_24,&local_28);
  if (iVar1 == 0) {
    uVar2 = *(uint *)(local_28 + 0xc);
    if (uVar2 < 0x880) {
      *(uint *)(local_28 + 0xc) = uVar2 + 1;
      iVar1 = 0;
      *(undefined *)(local_28 + uVar2 + 0x10) = 0xd2;
      *(int *)(local_28 + 8) = *(int *)(local_28 + 8) + 1;
    }
    else {
      iVar1 = 0x301;
    }
  }
  if (iVar1 == 0) {
    uVar2 = *(uint *)(local_28 + 0xc);
    if (uVar2 < 0x880) {
      *(uint *)(local_28 + 0xc) = uVar2 + 1;
      iVar1 = 0;
      *(undefined *)(local_28 + uVar2 + 0x10) = param_2;
      *(int *)(local_28 + 8) = *(int *)(local_28 + 8) + 1;
    }
    else {
      iVar1 = 0x301;
    }
  }
  if (iVar1 == 0) {
    sVar3 = MSL_C.PPCEABI.bare.H::strlen(param_1);
    iVar1 = TRKAppendBuffer1_ui16(local_28,sVar3 + 1 & 0xffff);
  }
  if (iVar1 == 0) {
    sVar3 = MSL_C.PPCEABI.bare.H::strlen(param_1);
    iVar1 = TRKAppendBuffer_ui8(local_28,param_1,sVar3 + 1);
  }
  if (iVar1 == 0) {
    *param_4 = 0;
    iVar1 = TRKRequestSend(local_28,local_20,7,3,0);
    if (iVar1 == 0) {
      unaff_r31 = TRKGetBuffer(local_20[0]);
      TRKSetBufferPosition(unaff_r31,2);
      iVar1 = TRKReadBuffer1_ui8(unaff_r31,param_4);
    }
    if (iVar1 == 0) {
      iVar1 = TRKReadBuffer1_ui32(unaff_r31,param_3);
    }
    TRKReleaseBuffer(local_20[0]);
  }
  TRKReleaseBuffer(local_24);
  return iVar1;
}


int TRKRequestSend
              (undefined4 param_1,int *param_2,uint param_3,int param_4,int param_5)

{
  bool bVar1;
  int iVar2;
  uint unaff_r29;
  int unaff_r30;
  int iVar3;
  char local_38;
  byte local_37 [19];
  
  param_4 = param_4 + 1;
  iVar3 = 0;
  bVar1 = true;
  *param_2 = -1;
LAB_80335298:
  if (((param_4 == 0) || (*param_2 != -1)) || (iVar3 != 0)) {
    if (*param_2 == -1) {
      iVar3 = 0x800;
    }
    return iVar3;
  }
  iVar3 = TRKMessageSend(param_1);
  if (iVar3 == 0) {
    if (param_5 != 0) {
      unaff_r29 = 0;
    }
LAB_8033518c:
    iVar2 = TRKTestForPacket();
    *param_2 = iVar2;
    if (*param_2 == -1) goto code_r0x803351a0;
    goto LAB_803351bc;
  }
  goto LAB_80335294;
code_r0x803351a0:
  if (param_5 == 0) goto LAB_8033518c;
  unaff_r29 = unaff_r29 + 1;
  if (unaff_r29 < 0x4c4b3ec) goto LAB_8033518c;
LAB_803351bc:
  if (*param_2 != -1) {
    bVar1 = false;
    unaff_r30 = TRKGetBuffer();
    TRKSetBufferPosition(unaff_r30,0);
    iVar3 = TRKReadBuffer1_ui8(unaff_r30,local_37);
    if ((iVar3 != 0) || (0x7f < local_37[0])) goto LAB_8033520c;
    TRKProcessInput(*param_2);
    *param_2 = -1;
    goto LAB_8033518c;
  }
LAB_8033520c:
  if (*param_2 != -1) {
    if (*(uint *)(unaff_r30 + 8) < param_3) {
      bVar1 = true;
    }
    if ((iVar3 == 0) && (!bVar1)) {
      iVar3 = TRKReadBuffer1_ui8(unaff_r30,&local_38);
    }
    if (((iVar3 == 0) && (!bVar1)) && ((local_37[0] != 0x80 || (local_38 != '\0')))) {
      bVar1 = true;
    }
    if ((iVar3 != 0) || (bVar1)) {
      TRKReleaseBuffer(*param_2);
      *param_2 = -1;
    }
  }
LAB_80335294:
  param_4 = param_4 + -1;
  goto LAB_80335298;
}


int TRKSuppAccessFile
              (int param_1,int param_2,uint *param_3,char *param_4,int param_5,int param_6)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined uVar6;
  int unaff_r28;
  uint uVar7;
  char local_48 [2];
  ushort local_46;
  int local_44;
  undefined4 local_40;
  undefined4 local_3c [4];
  
  if ((param_2 == 0) || (*param_3 == 0)) {
    iVar4 = 2;
  }
  else {
    bVar1 = false;
    *param_4 = '\0';
    uVar7 = 0;
    iVar4 = 0;
    while ((((!bVar1 && (uVar7 < *param_3)) && (iVar4 == 0)) && (*param_4 == '\0'))) {
      uVar5 = *param_3 - uVar7;
      uVar2 = 0x800;
      if (uVar5 < 0x801) {
        uVar2 = uVar5;
      }
      iVar4 = TRKGetFreeBuffer(&local_40,&local_44);
      if (iVar4 == 0) {
        uVar6 = 0xd0;
        if (param_6 != 0) {
          uVar6 = 0xd1;
        }
        uVar5 = *(uint *)(local_44 + 0xc);
        if (uVar5 < 0x880) {
          *(uint *)(local_44 + 0xc) = uVar5 + 1;
          iVar4 = 0;
          *(undefined *)(local_44 + uVar5 + 0x10) = uVar6;
          *(int *)(local_44 + 8) = *(int *)(local_44 + 8) + 1;
        }
        else {
          iVar4 = 0x301;
        }
      }
      if (iVar4 == 0) {
        iVar4 = TRKAppendBuffer1_ui32(local_44,param_1);
      }
      if (iVar4 == 0) {
        iVar4 = TRKAppendBuffer1_ui16(local_44,uVar2 & 0xffff);
      }
      if ((param_6 == 0) && (iVar4 == 0)) {
        iVar4 = TRKAppendBuffer_ui8(local_44,param_2 + uVar7,uVar2);
      }
      if (iVar4 == 0) {
        if (param_5 == 0) {
          iVar4 = TRKMessageSend(local_44);
        }
        else {
          uVar3 = 0;
          local_46 = 0;
          local_48[0] = '\0';
          if ((param_6 != 0) && (param_1 == 0)) {
            uVar3 = 1;
          }
          uVar5 = countLeadingZeros(uVar3);
          iVar4 = TRKRequestSend(local_44,local_3c,5,3,uVar5 >> 5);
          if (iVar4 == 0) {
            unaff_r28 = TRKGetBuffer(local_3c[0]);
            TRKSetBufferPosition(unaff_r28,2);
            iVar4 = TRKReadBuffer1_ui8(unaff_r28,local_48);
          }
          if (iVar4 == 0) {
            iVar4 = TRKReadBuffer1_ui16(unaff_r28,&local_46);
          }
          if ((param_6 != 0) && (iVar4 == 0)) {
            if ((*(int *)(unaff_r28 + 8) != local_46 + 5) &&
               (local_46 = (short)*(int *)(unaff_r28 + 8) - 5, local_48[0] == '\0')) {
              local_48[0] = '\x01';
            }
            if (local_46 <= uVar2) {
              iVar4 = TRKReadBuffer_ui8(unaff_r28,param_2 + uVar7);
            }
          }
          uVar5 = (uint)local_46;
          if (uVar5 != uVar2) {
            if (((param_6 == 0) || (uVar2 <= uVar5)) && (local_48[0] == '\0')) {
              local_48[0] = '\x01';
            }
            bVar1 = true;
            uVar2 = uVar5;
          }
          *param_4 = local_48[0];
          TRKReleaseBuffer(local_3c[0]);
        }
      }
      TRKReleaseBuffer(local_40);
      uVar7 = uVar7 + uVar2;
    }
    *param_3 = uVar7;
  }
  return iVar4;
}

