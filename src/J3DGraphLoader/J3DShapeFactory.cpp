#include <J3DGraphLoader/J3DShapeFactory.h>
#include <J3DGraphLoader/J3DModelLoader.h>
#include <J3DGraphLoader/J3DShapeFactory.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JKernel/JKRHeap.h>
#include <J3DGraphBase/J3DShape.h>
#include <m_Do_printf.h>
#include <J3DGraphBase/J3DShapeMtx.h>
#include <J3DShapeFactory.h>


/* __thiscall J3DShapeFactory::J3DShapeFactory(J3DShapeBlock const &) */

void __thiscall J3DShapeFactory::J3DShapeFactory(J3DShapeFactory *this,J3DShapeBlock *param_1)

{
  undefined4 uVar1;
  
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0xc));
  *(undefined4 *)this = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x10));
  *(undefined4 *)(this + 4) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x18));
  *(undefined4 *)(this + 8) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x1c));
  *(undefined4 *)(this + 0xc) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x20));
  *(undefined4 *)(this + 0x10) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x24));
  *(undefined4 *)(this + 0x14) = uVar1;
  uVar1 = J3DGraphLoader::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + 0x28));
  *(undefined4 *)(this + 0x18) = uVar1;
  *(undefined4 *)(this + 0x1c) = 0;
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall J3DShapeFactory::create(int,
                                      unsigned long,
                                      _GXVtxDescList *) */

J3DShape * __thiscall
J3DShapeFactory::create(J3DShapeFactory *this,int param_1,ulong param_2,_GXVtxDescList *param_3)

{
  J3DShape *this_00;
  J3DShapeMtx **ppJVar1;
  J3DShapeDraw **ppJVar2;
  float *pfVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  
  this_00 = (J3DShape *)JKernel::operator_new(0x68);
  if (this_00 != (J3DShape *)0x0) {
    this_00->vtbl = &J3DShape::__vt;
    this_00->field_0x40 = (undefined *)0x3cf3cf00;
    this_00->field_0x44 = (undefined *)0xf3cf3c;
    J3DShape::initialize(this_00);
  }
  iVar5 = param_1 * 2;
  this_00->mMtxGroupNum =
       *(short *)(*(int *)this + (uint)*(ushort *)(*(int *)(this + 4) + iVar5) * 0x28 + 2);
  this_00->mBoundingSphereRadius =
       *(float *)(*(int *)this + (uint)*(ushort *)(*(int *)(this + 4) + iVar5) * 0x28 + 0xc);
  this_00->mpAttrDecl =
       (undefined *)
       (*(int *)(this + 8) +
       (uint)*(ushort *)(*(int *)this + (uint)*(ushort *)(*(int *)(this + 4) + iVar5) * 0x28 + 4));
  ppJVar1 = (J3DShapeMtx **)JKernel::operator_new__((uint)(ushort)this_00->mMtxGroupNum << 2);
  this_00->mpShapeMtx = ppJVar1;
  ppJVar2 = (J3DShapeDraw **)JKernel::operator_new__((uint)(ushort)this_00->mMtxGroupNum << 2);
  this_00->mpShapeDraw = ppJVar2;
  pfVar3 = (float *)(*(int *)this + (uint)*(ushort *)(*(int *)(this + 4) + iVar5) * 0x28 + 0x10);
  (this_00->mBoundingBoxMin).x = *pfVar3;
  (this_00->mBoundingBoxMin).y = pfVar3[1];
  (this_00->mBoundingBoxMin).z = pfVar3[2];
  pfVar3 = (float *)(*(int *)this + (uint)*(ushort *)(*(int *)(this + 4) + iVar5) * 0x28 + 0x1c);
  (this_00->mBoundingBoxMax).x = *pfVar3;
  (this_00->mBoundingBoxMax).y = pfVar3[1];
  (this_00->mBoundingBoxMax).z = pfVar3[2];
  this_00->mpVatVcdCmd = (undefined *)(*(int *)(this + 0x1c) + param_1 * 0xc0);
  iVar6 = 0;
  for (iVar5 = 0; iVar5 < (int)(uint)(ushort)this_00->mMtxGroupNum; iVar5 = iVar5 + 1) {
    uVar4 = newShapeMtx(this,param_2,param_1,iVar5);
    *(undefined4 *)((int)this_00->mpShapeMtx + iVar6) = uVar4;
    uVar4 = newShapeDraw(this,param_1,iVar5);
    *(undefined4 *)((int)this_00->mpShapeDraw + iVar6) = uVar4;
    iVar6 = iVar6 + 4;
  }
  this_00->mShapeIdx = (short)param_1;
  return this_00;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x802fe804) */
/* WARNING: Removing unreachable block (ram,0x802fe990) */
/* WARNING: Removing unreachable block (ram,0x802fe6a4) */
/* __thiscall J3DShapeFactory::newShapeMtx(unsigned long,
                                           int,
                                           int) const */

undefined4 * __thiscall
J3DShapeFactory::newShapeMtx(J3DShapeFactory *this,ulong param_1,int param_2,int param_3)

{
  byte bVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  undefined4 *puVar8;
  undefined2 *puVar9;
  
  puVar8 = (undefined4 *)0x0;
  pbVar7 = (byte *)(*(int *)this + (uint)*(ushort *)(*(int *)(this + 4) + param_2 * 2) * 0x28);
  puVar9 = (undefined2 *)(*(int *)(this + 0x14) + (uint)*(ushort *)(pbVar7 + 6) * 8 + param_3 * 8);
  uVar4 = param_1 & 0xf0;
  if (uVar4 == 0x10) {
    bVar1 = *pbVar7;
    if (bVar1 == 2) {
      puVar8 = (undefined4 *)JKernel::operator_new(8);
      if (puVar8 != (undefined4 *)0x0) {
        uVar2 = *puVar9;
        *puVar8 = &J3DShapeMtx::__vt;
        *(undefined2 *)(puVar8 + 1) = uVar2;
        *puVar8 = &J3DShapeMtxImm::__vt;
        *puVar8 = &J3DShapeMtxYBBoardImm::__vt;
      }
    }
    else {
      if (bVar1 < 2) {
        if (bVar1 == 0) {
          puVar8 = (undefined4 *)JKernel::operator_new(8);
          if (puVar8 != (undefined4 *)0x0) {
            uVar2 = *puVar9;
            *puVar8 = &J3DShapeMtx::__vt;
            *(undefined2 *)(puVar8 + 1) = uVar2;
            *puVar8 = &J3DShapeMtxImm::__vt;
          }
        }
        else {
          puVar8 = (undefined4 *)JKernel::operator_new(8);
          if (puVar8 != (undefined4 *)0x0) {
            uVar2 = *puVar9;
            *puVar8 = &J3DShapeMtx::__vt;
            *(undefined2 *)(puVar8 + 1) = uVar2;
            *puVar8 = &J3DShapeMtxImm::__vt;
            *puVar8 = &J3DShapeMtxBBoardImm::__vt;
          }
        }
      }
      else {
        if (bVar1 < 4) {
          puVar8 = (undefined4 *)JKernel::operator_new(0x10);
          if (puVar8 != (undefined4 *)0x0) {
            iVar6 = *(int *)(this + 0xc);
            iVar5 = *(int *)(puVar9 + 2);
            uVar2 = puVar9[1];
            uVar3 = *puVar9;
            *puVar8 = &J3DShapeMtx::__vt;
            *(undefined2 *)(puVar8 + 1) = uVar3;
            *puVar8 = &J3DShapeMtxImm::__vt;
            *puVar8 = &J3DShapeMtxMultiImm::__vt;
            *(undefined2 *)(puVar8 + 2) = uVar2;
            puVar8[3] = iVar6 + iVar5 * 2;
          }
        }
        else {
          m_Do_printf::OSReport("WRONG SHAPE MATRIX TYPE (J3DModelInit.cpp)\n");
        }
      }
    }
  }
  else {
    if ((uVar4 < 0x10) || (uVar4 != 0x20)) {
      if (*pbVar7 == 3) {
        puVar8 = (undefined4 *)JKernel::operator_new(0x10);
        if (puVar8 != (undefined4 *)0x0) {
          iVar6 = *(int *)(this + 0xc);
          iVar5 = *(int *)(puVar9 + 2);
          uVar2 = puVar9[1];
          uVar3 = *puVar9;
          *puVar8 = &J3DShapeMtx::__vt;
          *(undefined2 *)(puVar8 + 1) = uVar3;
          *puVar8 = &J3DShapeMtxMulti::__vt;
          *(undefined2 *)(puVar8 + 2) = uVar2;
          puVar8[3] = iVar6 + iVar5 * 2;
        }
      }
      else {
        if (*pbVar7 < 3) {
          puVar8 = (undefined4 *)JKernel::operator_new(8);
          if (puVar8 != (undefined4 *)0x0) {
            uVar2 = *puVar9;
            *puVar8 = &J3DShapeMtx::__vt;
            *(undefined2 *)(puVar8 + 1) = uVar2;
          }
        }
        else {
          m_Do_printf::OSReport("WRONG SHAPE MATRIX TYPE (J3DModelInit.cpp)\n");
        }
      }
    }
    else {
      bVar1 = *pbVar7;
      if (bVar1 == 2) {
        puVar8 = (undefined4 *)JKernel::operator_new(8);
        if (puVar8 != (undefined4 *)0x0) {
          uVar2 = *puVar9;
          *puVar8 = &J3DShapeMtx::__vt;
          *(undefined2 *)(puVar8 + 1) = uVar2;
          *puVar8 = &J3DShapeMtxImm::__vt;
          *puVar8 = &J3DShapeMtxYBBoardImm::__vt;
          *puVar8 = &J3DShapeMtxYBBoardConcatView::__vt;
        }
      }
      else {
        if (bVar1 < 2) {
          if (bVar1 == 0) {
            puVar8 = (undefined4 *)JKernel::operator_new(8);
            if (puVar8 != (undefined4 *)0x0) {
              uVar2 = *puVar9;
              *puVar8 = &J3DShapeMtx::__vt;
              *(undefined2 *)(puVar8 + 1) = uVar2;
              *puVar8 = &J3DShapeMtxImm::__vt;
              *puVar8 = &J3DShapeMtxConcatView::__vt;
            }
          }
          else {
            puVar8 = (undefined4 *)JKernel::operator_new(8);
            if (puVar8 != (undefined4 *)0x0) {
              uVar2 = *puVar9;
              *puVar8 = &J3DShapeMtx::__vt;
              *(undefined2 *)(puVar8 + 1) = uVar2;
              *puVar8 = &J3DShapeMtxImm::__vt;
              *puVar8 = &J3DShapeMtxBBoardImm::__vt;
              *puVar8 = &J3DShapeMtxBBoardConcatView::__vt;
            }
          }
        }
        else {
          if (bVar1 < 4) {
            puVar8 = (undefined4 *)JKernel::operator_new(0x10);
            if (puVar8 != (undefined4 *)0x0) {
              iVar6 = *(int *)(this + 0xc);
              iVar5 = *(int *)(puVar9 + 2);
              uVar2 = puVar9[1];
              uVar3 = *puVar9;
              *puVar8 = &J3DShapeMtx::__vt;
              *(undefined2 *)(puVar8 + 1) = uVar3;
              *puVar8 = &J3DShapeMtxImm::__vt;
              *puVar8 = &J3DShapeMtxConcatView::__vt;
              *puVar8 = &J3DShapeMtxMultiConcatView::__vt;
              *(undefined2 *)(puVar8 + 2) = uVar2;
              puVar8[3] = iVar6 + iVar5 * 2;
            }
          }
          else {
            m_Do_printf::OSReport("WRONG SHAPE MATRIX TYPE (J3DModelInit.cpp)\n");
          }
        }
      }
    }
  }
  return puVar8;
}


/* __thiscall J3DShapeFactory::newShapeDraw(int,
                                            int) const */

J3DShapeDraw * __thiscall
J3DShapeFactory::newShapeDraw(J3DShapeFactory *this,int param_1,int param_2)

{
  J3DShapeDraw *this_00;
  ulong *puVar1;
  
  puVar1 = (ulong *)(*(int *)(this + 0x18) +
                    (uint)*(ushort *)
                           (*(int *)this +
                           (uint)*(ushort *)(*(int *)(this + 4) + param_1 * 2) * 0x28 + 8) * 8 +
                    param_2 * 8);
  this_00 = (J3DShapeDraw *)JKernel::operator_new(0xc);
  if (this_00 != (J3DShapeDraw *)0x0) {
    J3DShapeDraw::J3DShapeDraw(this_00,(uchar *)(*(int *)(this + 0x10) + puVar1[1]),*puVar1);
  }
  return this_00;
}


/* __thiscall J3DShapeFactory::allocVcdVatCmdBuffer(unsigned long) */

void __thiscall J3DShapeFactory::allocVcdVatCmdBuffer(J3DShapeFactory *this,ulong param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = JKernel::operator_new__(param_1 * 0xc0,0x20);
  *(undefined4 *)(this + 0x1c) = uVar1;
  iVar2 = 0;
  for (uVar3 = param_1 * 0xc0 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)(*(int *)(this + 0x1c) + iVar2) = 0;
    iVar2 = iVar2 + 4;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall J3DShapeFactory::calcSize(int,
                                        unsigned long) */

int __thiscall J3DShapeFactory::calcSize(J3DShapeFactory *this,int param_1,ulong param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = (uint)*(ushort *)
                 (*(int *)this + (uint)*(ushort *)(*(int *)(this + 4) + param_1 * 2) * 0x28 + 2);
  iVar4 = uVar3 * 8 + 0x68;
  for (uVar2 = 0; uVar2 < uVar3; uVar2 = uVar2 + 1) {
    iVar1 = calcSizeShapeMtx(this,param_2,param_1,uVar2);
    iVar4 = iVar4 + iVar1 + 0xc;
  }
  return iVar4;
}


/* __thiscall J3DShapeFactory::calcSizeVcdVatCmdBuffer(unsigned long) */

int __thiscall J3DShapeFactory::calcSizeVcdVatCmdBuffer(J3DShapeFactory *this,ulong param_1)

{
  return param_1 * 0xc0;
}


/* WARNING: Removing unreachable block (ram,0x802feca8) */
/* WARNING: Removing unreachable block (ram,0x802fed04) */
/* WARNING: Removing unreachable block (ram,0x802fec48) */
/* __thiscall J3DShapeFactory::calcSizeShapeMtx(unsigned long,
                                                int,
                                                int) const */

undefined4 __thiscall
J3DShapeFactory::calcSizeShapeMtx(J3DShapeFactory *this,ulong param_1,int param_2,int param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar4 = *(int *)this;
  iVar3 = (uint)*(ushort *)(*(int *)(this + 4) + param_2 * 2) * 0x28;
  uVar5 = 0;
  uVar2 = param_1 & 0xf0;
  if (uVar2 == 0x10) {
    bVar1 = *(byte *)(iVar4 + iVar3);
    if (bVar1 == 2) {
      uVar5 = 8;
    }
    else {
      if (bVar1 < 2) {
        if (bVar1 == 0) {
          uVar5 = 8;
        }
        else {
          uVar5 = 8;
        }
      }
      else {
        if (bVar1 < 4) {
          uVar5 = 0x10;
        }
        else {
          m_Do_printf::OSReport("WRONG SHAPE MATRIX TYPE (J3DModelInit.cpp)\n");
        }
      }
    }
  }
  else {
    if ((uVar2 < 0x10) || (uVar2 != 0x20)) {
      if (*(byte *)(iVar4 + iVar3) == 3) {
        uVar5 = 0x10;
      }
      else {
        if (*(byte *)(iVar4 + iVar3) < 3) {
          uVar5 = 8;
        }
        else {
          m_Do_printf::OSReport("WRONG SHAPE MATRIX TYPE (J3DModelInit.cpp)\n");
        }
      }
    }
    else {
      bVar1 = *(byte *)(iVar4 + iVar3);
      if (bVar1 == 2) {
        uVar5 = 8;
      }
      else {
        if (bVar1 < 2) {
          if (bVar1 == 0) {
            uVar5 = 8;
          }
          else {
            uVar5 = 8;
          }
        }
        else {
          if (bVar1 < 4) {
            uVar5 = 0x10;
          }
          else {
            m_Do_printf::OSReport("WRONG SHAPE MATRIX TYPE (J3DModelInit.cpp)\n");
          }
        }
      }
    }
  }
  return uVar5;
}


namespace J3DGraphLoader {

/* __stdcall JSUConvertOffsetToPtr<J3DShapeDrawInitData>(void const *,
                                                         unsigned long) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<J3DShapeMtxInitData>(void const *,
                                                        unsigned long) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<unsigned char>(void const *,
                                                  unsigned long) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<_GXVtxDescList>(void const *,
                                                   unsigned long) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}

