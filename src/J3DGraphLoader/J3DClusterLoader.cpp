#include <J3DGraphLoader/J3DClusterLoader.h>
#include <J3DGraphLoader/J3DClusterLoader.h>
#include <JKernel/JKRHeap.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <J3DGraphAnimator/J3DCluster.h>
#include <m_Do_printf.h>
#include <JUtility/JUTNameTab.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <J3DGraphLoader/J3DMaterialFactory.h>
#include <J3DClusterLoaderDataBase.h>
#include <J3DClusterLoader.h>
#include <J3DClusterLoader_v15.h>


/* __thiscall J3DClusterLoaderDataBase::load(void const *) */

undefined4 __thiscall J3DClusterLoaderDataBase::load(J3DClusterLoaderDataBase *this,void *param_1)

{
  undefined4 uVar1;
  J3DClusterLoader_v15 aJStack24 [20];
  
  if ((*(int *)this == 0x4a334431) && (*(int *)(this + 4) == 0x626c7331)) {
    J3DClusterLoader_v15::J3DClusterLoader_v15(aJStack24);
    uVar1 = J3DClusterLoader_v15::load(aJStack24,this);
    J3DClusterLoader_v15::_J3DClusterLoader_v15(aJStack24);
  }
  else {
    if ((*(int *)this == 0x4a334432) && (*(int *)(this + 4) == 0x626c7332)) {
      uVar1 = 0;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}


/* __thiscall J3DClusterLoader_v15::J3DClusterLoader_v15(void) */

void __thiscall J3DClusterLoader_v15::J3DClusterLoader_v15(J3DClusterLoader_v15 *this)

{
  *(undefined1 **)this = &J3DClusterLoader::__vt;
  *(undefined1 **)this = &__vt;
  return;
}


/* __thiscall J3DClusterLoader_v15::~J3DClusterLoader_v15(void) */

void __thiscall J3DClusterLoader_v15::_J3DClusterLoader_v15(J3DClusterLoader_v15 *this)

{
  short in_r4;
  
  if (this != (J3DClusterLoader_v15 *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (J3DClusterLoader_v15 *)0x0) {
      *(undefined1 **)this = &J3DClusterLoader::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall J3DClusterLoader_v15::load(void const *) */

undefined4 __thiscall J3DClusterLoader_v15::load(J3DClusterLoader_v15 *this,void *param_1)

{
  J3DDeformData *this_00;
  uint uVar1;
  int *piVar2;
  
  this_00 = (J3DDeformData *)JKernel::operator_new(0x28);
  if (this_00 != (J3DDeformData *)0x0) {
    J3DDeformData::J3DDeformData(this_00);
  }
  *(J3DDeformData **)(this + 4) = this_00;
  J3DDeformData::clear(*(J3DDeformData **)(this + 4));
  piVar2 = (int *)((int)param_1 + 0x20);
  for (uVar1 = 0; uVar1 < *(uint *)((int)param_1 + 0xc); uVar1 = uVar1 + 1) {
    if (*piVar2 == 0x434c5331) {
      readCluster(this,(J3DClusterBlock *)piVar2);
    }
    else {
      m_Do_printf::OSReport("Unknown data block\n");
    }
    piVar2 = (int *)((int)piVar2 + piVar2[1]);
  }
  return *(undefined4 *)(this + 4);
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall J3DClusterLoader_v15::readCluster(J3DClusterBlock const *) */

void __thiscall
J3DClusterLoader_v15::readCluster(J3DClusterLoader_v15 *this,J3DClusterBlock *param_1)

{
  ushort uVar1;
  JUTNameTab *pJVar2;
  ResNTAB *pRVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined2 *puVar8;
  ushort *puVar9;
  int iVar10;
  undefined2 *puVar11;
  undefined4 *puVar12;
  int iVar13;
  int iVar14;
  
  **(undefined2 **)(this + 4) = *(undefined2 *)(param_1 + 8);
  *(undefined2 *)(*(int *)(this + 4) + 2) = *(undefined2 *)(param_1 + 10);
  *(undefined2 *)(*(int *)(this + 4) + 0x14) = *(undefined2 *)(param_1 + 0xe);
  *(undefined2 *)(*(int *)(this + 4) + 0x16) = *(undefined2 *)(param_1 + 0x10);
  *(undefined2 *)(*(int *)(this + 4) + 4) = *(undefined2 *)(param_1 + 0xc);
  if (*(int *)(param_1 + 0x28) == 0) {
    *(undefined4 *)(*(int *)(this + 4) + 0x20) = 0;
  }
  else {
    pJVar2 = (JUTNameTab *)JKernel::operator_new(0x10);
    if (pJVar2 != (JUTNameTab *)0x0) {
      pRVar3 = (ResNTAB *)
               J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x28));
      JUTNameTab::JUTNameTab(pJVar2,pRVar3);
    }
    *(JUTNameTab **)(*(int *)(this + 4) + 0x20) = pJVar2;
  }
  if (*(int *)(param_1 + 0x2c) == 0) {
    *(undefined4 *)(*(int *)(this + 4) + 0x24) = 0;
  }
  else {
    pJVar2 = (JUTNameTab *)JKernel::operator_new(0x10);
    if (pJVar2 != (JUTNameTab *)0x0) {
      pRVar3 = (ResNTAB *)
               J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x2c));
      JUTNameTab::JUTNameTab(pJVar2,pRVar3);
    }
    *(JUTNameTab **)(*(int *)(this + 4) + 0x24) = pJVar2;
  }
  uVar4 = J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x20));
  *(undefined4 *)(*(int *)(this + 4) + 0x18) = uVar4;
  uVar4 = J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x24));
  *(undefined4 *)(*(int *)(this + 4) + 0x1c) = uVar4;
  uVar1 = **(ushort **)(this + 4);
  uVar4 = JKernel::operator_new__((uint)uVar1 * 0x24 + 0x10);
  uVar4 = Runtime.PPCEABI.H::__construct_new_array(uVar4,0,0,0x24,(uint)uVar1);
  *(undefined4 *)(*(int *)(this + 4) + 8) = uVar4;
  iVar5 = J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x14));
  iVar7 = 0;
  for (iVar13 = 0; puVar9 = *(ushort **)(this + 4), iVar13 < (int)(uint)*puVar9; iVar13 = iVar13 + 1
      ) {
    puVar6 = (undefined4 *)(*(int *)(puVar9 + 4) + iVar7);
    puVar12 = (undefined4 *)(iVar5 + iVar7);
    *puVar6 = *puVar12;
    puVar6[1] = puVar12[1];
    puVar6[2] = puVar12[2];
    *(undefined *)(puVar6 + 3) = *(undefined *)(puVar12 + 3);
    *(undefined2 *)(puVar6 + 4) = *(undefined2 *)(puVar12 + 4);
    *(undefined2 *)((int)puVar6 + 0x12) = *(undefined2 *)((int)puVar12 + 0x12);
    *(undefined2 *)(puVar6 + 5) = *(undefined2 *)(puVar12 + 5);
    *(undefined2 *)((int)puVar6 + 0x16) = *(undefined2 *)((int)puVar12 + 0x16);
    puVar6[6] = puVar12[6];
    puVar6[7] = puVar12[7];
    puVar6[8] = puVar12[8];
    iVar7 = iVar7 + 0x24;
  }
  uVar1 = puVar9[1];
  uVar4 = JKernel::operator_new__((uint)uVar1 * 0xc + 0x10);
  uVar4 = Runtime.PPCEABI.H::__construct_new_array(uVar4,0,0,0xc,(uint)uVar1);
  *(undefined4 *)(*(int *)(this + 4) + 0xc) = uVar4;
  iVar5 = J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x18));
  iVar7 = 0;
  for (iVar13 = 0; iVar10 = *(int *)(this + 4), iVar13 < (int)(uint)*(ushort *)(iVar10 + 2);
      iVar13 = iVar13 + 1) {
    puVar8 = (undefined2 *)(*(int *)(iVar10 + 0xc) + iVar7);
    puVar11 = (undefined2 *)(iVar5 + iVar7);
    *puVar8 = *puVar11;
    puVar8[1] = puVar11[1];
    *(undefined4 *)(puVar8 + 2) = *(undefined4 *)(puVar11 + 2);
    *(undefined4 *)(puVar8 + 4) = *(undefined4 *)(puVar11 + 4);
    iVar7 = iVar7 + 0xc;
  }
  uVar1 = *(ushort *)(iVar10 + 4);
  uVar4 = JKernel::operator_new__((uint)uVar1 * 0xc + 0x10);
  uVar4 = Runtime.PPCEABI.H::__construct_new_array(uVar4,0,0,0xc,(uint)uVar1);
  *(undefined4 *)(*(int *)(this + 4) + 0x10) = uVar4;
  iVar5 = J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x1c));
  iVar7 = 0;
  for (iVar13 = 0; iVar13 < (int)(uint)*(ushort *)(*(int *)(this + 4) + 4); iVar13 = iVar13 + 1) {
    puVar8 = (undefined2 *)(*(int *)(*(int *)(this + 4) + 0x10) + iVar7);
    puVar11 = (undefined2 *)(iVar5 + iVar7);
    *puVar8 = *puVar11;
    *(undefined4 *)(puVar8 + 2) = *(undefined4 *)(puVar11 + 2);
    *(undefined4 *)(puVar8 + 4) = *(undefined4 *)(puVar11 + 4);
    iVar7 = iVar7 + 0xc;
  }
  iVar13 = 0;
  iVar7 = 0;
  while( true ) {
    if ((int)(uint)**(ushort **)(this + 4) <= iVar13) break;
    iVar14 = *(int *)(*(ushort **)(this + 4) + 4) + iVar7;
    uVar4 = J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(iVar14 + 8));
    *(undefined4 *)(iVar14 + 8) = uVar4;
    uVar4 = J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(iVar14 + 0x18));
    *(undefined4 *)(iVar14 + 0x18) = uVar4;
    iVar10 = J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(iVar14 + 0x1c));
    *(uint *)(iVar14 + 0x1c) =
         *(int *)(*(int *)(this + 4) + 0x10) + ((uint)((iVar10 - iVar5) / 0xc) / 0xc) * 0xc;
    puVar6 = (undefined4 *)JKernel::operator_new(0x14);
    if (puVar6 != (undefined4 *)0x0) {
      uVar4 = *(undefined4 *)(this + 4);
      J3DDeformer::clear((J3DDeformer *)puVar6);
      *puVar6 = uVar4;
    }
    if (*(ushort *)(iVar14 + 0x14) == 0) {
      puVar6[3] = 0;
    }
    else {
      uVar4 = JKernel::operator_new__((uint)*(ushort *)(iVar14 + 0x14) * 0xc);
      puVar6[3] = uVar4;
    }
    puVar6[4] = (uint)*(byte *)(iVar14 + 0xc);
    uVar4 = JKernel::operator_new__((uint)*(ushort *)(iVar14 + 0x10) << 2);
    puVar6[2] = uVar4;
    *(undefined4 **)(iVar14 + 0x20) = puVar6;
    iVar13 = iVar13 + 1;
    iVar7 = iVar7 + 0x24;
  }
  iVar7 = 0;
  for (iVar5 = 0; iVar5 < (int)(uint)*(ushort *)(*(int *)(this + 4) + 2); iVar5 = iVar5 + 1) {
    iVar13 = *(int *)(*(int *)(this + 4) + 0xc) + iVar7;
    uVar4 = J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(iVar13 + 4));
    *(undefined4 *)(iVar13 + 4) = uVar4;
    uVar4 = J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(iVar13 + 8));
    *(undefined4 *)(iVar13 + 8) = uVar4;
    iVar7 = iVar7 + 0xc;
  }
  iVar7 = 0;
  for (iVar5 = 0; iVar5 < (int)(uint)*(ushort *)(*(int *)(this + 4) + 4); iVar5 = iVar5 + 1) {
    iVar13 = *(int *)(*(int *)(this + 4) + 0x10) + iVar7;
    uVar4 = J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(iVar13 + 4));
    *(undefined4 *)(iVar13 + 4) = uVar4;
    uVar4 = J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(iVar13 + 8));
    *(undefined4 *)(iVar13 + 8) = uVar4;
    iVar7 = iVar7 + 0xc;
  }
  return;
}


/* __thiscall J3DClusterLoader::~J3DClusterLoader(void) */

void __thiscall J3DClusterLoader::_J3DClusterLoader(J3DClusterLoader *this)

{
  short in_r4;
  
  if ((this != (J3DClusterLoader *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


namespace J3DGraphLoader {

/* __stdcall JSUConvertOffsetToPtr<J3DClusterVertex>(void const *,
                                                     void const *) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<J3DClusterKey>(void const *,
                                                  void const *) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<J3DCluster>(void const *,
                                               void const *) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<float>(void const *,
                                          void const *) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<ResNTAB>(void const *,
                                            void const *) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}

