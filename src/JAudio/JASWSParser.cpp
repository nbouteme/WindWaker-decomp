#include <JAudio/JASWSParser.h>
#include <JAudio/JASWSParser.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JAudio/JASWaveBank.h>
#include <JKernel/JKRHeap.h>
#include <JAudio/JASBasicWaveBank.h>
#include <JAudio/JASWaveArcLoader.h>
#include <JAudio/JASSimpleWaveBank.h>
#include <JASystem/WSParser.h>


namespace JASystem {
undefined1 WSParser;

/* __thiscall WSParser::getGroupCount(void *) */

undefined4 __thiscall WSParser::getGroupCount(WSParser *this,void *param_1)

{
  int iVar1;
  
  iVar1 = JAudio::JSUConvertOffsetToPtr(this,*(undefined4 *)(this + 0x14));
  return *(undefined4 *)(iVar1 + 8);
}


/* WARNING: Inlined function: FUN_80328f14 */
/* WARNING: Inlined function: FUN_80328f60 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall WSParser::createBasicWaveBank(void *) */

TBasicWaveBank * __thiscall WSParser::createBasicWaveBank(WSParser *this,void *param_1)

{
  uint uVar1;
  JKRHeap *this_00;
  int iVar2;
  TBasicWaveBank *this_01;
  int iVar3;
  int iVar4;
  TWaveGroup *this_02;
  int iVar5;
  char *pcVar6;
  TWaveInfo *pTVar7;
  uint *puVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  TWaveInfo local_68;
  TWaveInfo local_67;
  TWaveInfo local_66;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined2 local_48;
  undefined2 local_46;
  undefined4 local_40;
  
  this_00 = (JKRHeap *)TWaveBank::getCurrentHeap((TWaveBank *)this);
  iVar2 = JKRHeap::getFreeSize(this_00);
  this_01 = (TBasicWaveBank *)JKernel::operator_new(0x2c,this_00,0);
  if (this_01 != (TBasicWaveBank *)0x0) {
    TBasicWaveBank::TBasicWaveBank(this_01);
  }
  if (this_01 == (TBasicWaveBank *)0x0) {
    this_01 = (TBasicWaveBank *)0x0;
  }
  else {
    iVar3 = JAudio::JSUConvertOffsetToPtr(this,*(undefined4 *)(this + 0x14));
    TBasicWaveBank::setGroupCount(this_01,*(ulong *)(iVar3 + 8));
    uVar12 = 0;
    iVar9 = 0;
    for (uVar11 = 0; uVar11 < *(uint *)(iVar3 + 8); uVar11 = uVar11 + 1) {
      iVar4 = JAudio::JSUConvertOffsetToPtr(this,*(undefined4 *)(iVar3 + iVar9 + 0xc));
      iVar4 = JAudio::JSUConvertOffsetToPtr(this,*(undefined4 *)(iVar4 + 0xc));
      this_02 = (TWaveGroup *)TBasicWaveBank::getWaveGroup(this_01,uVar11);
      iVar5 = JAudio::JSUConvertOffsetToPtr(this,*(undefined4 *)(this + 0x10));
      pcVar6 = (char *)JAudio::JSUConvertOffsetToPtr(this,*(undefined4 *)(iVar5 + iVar9 + 8));
      TBasicWaveBank::TWaveGroup::setWaveCount(this_02,*(ulong *)(iVar4 + 4));
      iVar5 = 0;
      for (uVar10 = 0; uVar10 < *(uint *)(iVar4 + 4); uVar10 = uVar10 + 1) {
        pTVar7 = (TWaveInfo *)
                 JAudio::JSUConvertOffsetToPtr(this,*(undefined4 *)(pcVar6 + iVar5 + 0x74));
        local_68 = *pTVar7;
        local_67 = pTVar7[1];
        local_66 = pTVar7[2];
        local_64 = *(undefined4 *)(pTVar7 + 4);
        local_60 = *(undefined4 *)(pTVar7 + 8);
        local_5c = *(undefined4 *)(pTVar7 + 0xc);
        local_58 = *(undefined4 *)(pTVar7 + 0x10);
        local_54 = *(undefined4 *)(pTVar7 + 0x14);
        local_50 = *(undefined4 *)(pTVar7 + 0x18);
        local_4c = *(undefined4 *)(pTVar7 + 0x1c);
        local_48 = *(undefined2 *)(pTVar7 + 0x20);
        local_46 = *(undefined2 *)(pTVar7 + 0x22);
        local_40 = *(undefined4 *)(pTVar7 + 0x28);
        puVar8 = (uint *)JAudio::JSUConvertOffsetToPtr(this,*(undefined4 *)(iVar4 + iVar5 + 8));
        uVar1 = *puVar8 & 0xffff;
        TBasicWaveBank::TWaveGroup::setWaveInfo(this_02,uVar10,uVar1,&local_68);
        if (uVar12 < uVar1) {
          uVar12 = uVar1;
        }
        iVar5 = iVar5 + 4;
      }
      TWaveArc::setFileName((TWaveArc *)this_02,pcVar6);
      iVar9 = iVar9 + 4;
    }
    TBasicWaveBank::setWaveTableSize(this_01,uVar12 + 1);
    iVar3 = JKRHeap::getFreeSize(this_00);
    _sUsedHeapSize = _sUsedHeapSize + (iVar2 - iVar3);
  }
  return this_01;
}


/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall WSParser::createSimpleWaveBank(void *) */

TSimpleWaveBank * __thiscall WSParser::createSimpleWaveBank(WSParser *this,void *param_1)

{
  JKRHeap *this_00;
  int iVar1;
  int iVar2;
  TSimpleWaveBank *this_01;
  int iVar3;
  char *pcVar4;
  TWaveInfo *pTVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  TWaveInfo local_58;
  TWaveInfo local_57;
  TWaveInfo local_56;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined2 local_38;
  undefined2 local_36;
  undefined4 local_30;
  
  this_00 = (JKRHeap *)TWaveBank::getCurrentHeap((TWaveBank *)this);
  iVar1 = JKRHeap::getFreeSize(this_00);
  iVar2 = JAudio::JSUConvertOffsetToPtr(this,*(undefined4 *)(this + 0x14));
  if (*(int *)(iVar2 + 8) == 1) {
    this_01 = (TSimpleWaveBank *)JKernel::operator_new(0x84,this_00,0);
    if (this_01 != (TSimpleWaveBank *)0x0) {
      TSimpleWaveBank::TSimpleWaveBank(this_01);
    }
    if (this_01 == (TSimpleWaveBank *)0x0) {
      this_01 = (TSimpleWaveBank *)0x0;
    }
    else {
      uVar8 = 0;
      iVar2 = JAudio::JSUConvertOffsetToPtr(this,*(undefined4 *)(iVar2 + 0xc));
      iVar2 = JAudio::JSUConvertOffsetToPtr(this,*(undefined4 *)(iVar2 + 0xc));
      iVar3 = JAudio::JSUConvertOffsetToPtr(this,*(undefined4 *)(this + 0x10));
      pcVar4 = (char *)JAudio::JSUConvertOffsetToPtr(this,*(undefined4 *)(iVar3 + 8));
      iVar3 = 0;
      for (uVar7 = 0; uVar7 < *(uint *)(iVar2 + 4); uVar7 = uVar7 + 1) {
        puVar6 = (uint *)JAudio::JSUConvertOffsetToPtr(this,*(undefined4 *)(iVar2 + iVar3 + 8));
        if (uVar8 < (*puVar6 & 0xffff)) {
          uVar8 = *puVar6 & 0xffff;
        }
        iVar3 = iVar3 + 4;
      }
      TSimpleWaveBank::setWaveTableSize(this_01,uVar8 + 1);
      iVar3 = 0;
      for (uVar8 = 0; uVar8 < *(uint *)(iVar2 + 4); uVar8 = uVar8 + 1) {
        pTVar5 = (TWaveInfo *)
                 JAudio::JSUConvertOffsetToPtr(this,*(undefined4 *)(pcVar4 + iVar3 + 0x74));
        local_58 = *pTVar5;
        local_57 = pTVar5[1];
        local_56 = pTVar5[2];
        local_54 = *(undefined4 *)(pTVar5 + 4);
        local_50 = *(undefined4 *)(pTVar5 + 8);
        local_4c = *(undefined4 *)(pTVar5 + 0xc);
        local_48 = *(undefined4 *)(pTVar5 + 0x10);
        local_44 = *(undefined4 *)(pTVar5 + 0x14);
        local_40 = *(undefined4 *)(pTVar5 + 0x18);
        local_3c = *(undefined4 *)(pTVar5 + 0x1c);
        local_38 = *(undefined2 *)(pTVar5 + 0x20);
        local_36 = *(undefined2 *)(pTVar5 + 0x22);
        local_30 = *(undefined4 *)(pTVar5 + 0x28);
        puVar6 = (uint *)JAudio::JSUConvertOffsetToPtr(this,*(undefined4 *)(iVar2 + iVar3 + 8));
        TSimpleWaveBank::setWaveInfo(this_01,*puVar6 & 0xffff,&local_58);
        iVar3 = iVar3 + 4;
      }
      TWaveArc::setFileName((TWaveArc *)(this_01 + 4),pcVar4);
      iVar2 = JKRHeap::getFreeSize(this_00);
      _sUsedHeapSize = _sUsedHeapSize + (iVar1 - iVar2);
    }
  }
  else {
    this_01 = (TSimpleWaveBank *)0x0;
  }
  return this_01;
}

}

namespace JAudio {

/* __stdcall JSUConvertOffsetToPtr<JASystem::WSParser::TCtrlWave>(void const *,
                                                                  unsigned long) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<JASystem::WSParser::TWave>(void const *,
                                                              unsigned long) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<JASystem::WSParser::TWaveArchive>(void const *,
                                                                     unsigned long) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<JASystem::WSParser::TWaveArchiveBank>(void const *,
                                                                         unsigned long) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<JASystem::WSParser::TCtrl>(void const *,
                                                              unsigned long) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<JASystem::WSParser::TCtrlScene>(void const *,
                                                                   unsigned long) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<JASystem::WSParser::TCtrlGroup>(void const *,
                                                                   unsigned long) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}

