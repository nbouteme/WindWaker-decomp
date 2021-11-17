#include <J3DGraphBase/J3DShapeMtx.h>
#include <J3DGraphBase/J3DSys.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <mtx/mtx.h>
#include <Runtime.PPCEABI.H/ptmf.h>
#include <J3DGraphBase/J3DTransform.h>
#include <gx/GXAttr.h>
#include <gx/GXDisplayList.h>
#include <JKernel/JKRHeap.h>
#include <J3DGraphBase/J3DShapeMtx.h>
#include <J3DShapeMtxConcatView.h>
#include <J3DShapeMtx.h>
#include <J3DShapeMtxMultiImm.h>
#include <J3DShapeMtxMulti.h>
#include <J3DShapeMtxYBBoardConcatView.h>
#include <J3DShapeMtxYBBoardImm.h>
#include <J3DShapeMtxBBoardConcatView.h>
#include <J3DShapeDraw.h>
#include <J3DShapeMtxBBoardImm.h>
#include <J3DShapeMtxImm.h>
#include <J3DShapeMtxMultiConcatView.h>

undefined1 J3DShapeMtx;
uint J3DShapeMtx;
undefined1 J3DShapeMtx;
struct MTX34 * J3DShapeMtxConcatView[3];

/* __thiscall J3DShapeMtx::loadMtxIndx_PNGP(int,
                                            unsigned short) const */

void __thiscall J3DShapeMtx::loadMtxIndx_PNGP(J3DShapeMtx *this,int param_1,ushort param_2)

{
  write_volatile_1(DAT_cc008000,0x20);
  write_volatile_2(0xcc008000,param_2);
  write_volatile_2(0xcc008000,(short)param_1 * 0xc | 0xb000);
  write_volatile_1(DAT_cc008000,0x28);
  write_volatile_2(0xcc008000,param_2);
  write_volatile_2(0xcc008000,(short)param_1 * 9 + 0x400U | 0x8000);
  return;
}


/* __thiscall J3DShapeMtx::loadMtxIndx_PCPU(int,
                                            unsigned short) const */

void __thiscall J3DShapeMtx::loadMtxIndx_PCPU(J3DShapeMtx *this,int param_1,ushort param_2)

{
  J3DGraphBase::J3DFifoLoadPosMtxImm((J3DGraphBase::j3dSys.mpCurShapePacket)->mpViewMtx,param_1 * 3)
  ;
  J3DSys::loadNrmMtxIndx(&J3DGraphBase::j3dSys,param_1,param_2);
  return;
}


/* __thiscall J3DShapeMtx::loadMtxIndx_NCPU(int,
                                            unsigned short) const */

void __thiscall J3DShapeMtx::loadMtxIndx_NCPU(J3DShapeMtx *this,int param_1,ushort param_2)

{
  J3DSys::loadPosMtxIndx(&J3DGraphBase::j3dSys,param_1,param_2);
  J3DGraphBase::J3DFifoLoadNrmMtxImm((J3DGraphBase::j3dSys.mpCurShapePacket)->mpViewMtx,param_1 * 3)
  ;
  return;
}


/* __thiscall J3DShapeMtx::loadMtxIndx_PNCPU(int,
                                             unsigned short) const */

void __thiscall J3DShapeMtx::loadMtxIndx_PNCPU(J3DShapeMtx *this,int param_1,ushort param_2)

{
  J3DGraphBase::J3DFifoLoadPosMtxImm((J3DGraphBase::j3dSys.mpCurShapePacket)->mpViewMtx,param_1 * 3)
  ;
  J3DGraphBase::J3DFifoLoadNrmMtxImm((J3DGraphBase::j3dSys.mpCurShapePacket)->mpViewMtx,param_1 * 3)
  ;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall J3DShapeMtxImm::loadMtxImm_PNGP(int,
                                              unsigned short) const */

void __thiscall J3DShapeMtxImm::loadMtxImm_PNGP(J3DShapeMtxImm *this,int param_1,ushort param_2)

{
  undefined2 in_register_00000014;
  
  J3DGraphBase::J3DFifoLoadPosMtxImm(J3DGraphBase::j3dSys.mpCurDrawPosMtxArr + param_2,param_1 * 3);
  (**(code **)(*(int *)this + 0x20))(this,param_1,CONCAT22(in_register_00000014,param_2));
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall J3DShapeMtxImm::loadMtxImm_PCPU(int,
                                              unsigned short) const */

void __thiscall J3DShapeMtxImm::loadMtxImm_PCPU(J3DShapeMtxImm *this,int param_1,ushort param_2)

{
  undefined2 in_register_00000014;
  
  J3DGraphBase::J3DFifoLoadPosMtxImm((J3DGraphBase::j3dSys.mpCurShapePacket)->mpViewMtx,param_1 * 3)
  ;
  (**(code **)(*(int *)this + 0x20))(this,param_1,CONCAT22(in_register_00000014,param_2));
  return;
}


/* __thiscall J3DShapeMtxImm::loadMtxImm_NCPU(int,
                                              unsigned short) const */

void __thiscall J3DShapeMtxImm::loadMtxImm_NCPU(J3DShapeMtxImm *this,int param_1,ushort param_2)

{
  J3DGraphBase::J3DFifoLoadPosMtxImm(J3DGraphBase::j3dSys.mpCurDrawPosMtxArr + param_2,param_1 * 3);
  J3DGraphBase::J3DFifoLoadNrmMtxImm((J3DGraphBase::j3dSys.mpCurShapePacket)->mpViewMtx,param_1 * 3)
  ;
  return;
}


/* __thiscall J3DShapeMtxImm::loadMtxImm_PNCPU(int,
                                               unsigned short) const */

void __thiscall J3DShapeMtxImm::loadMtxImm_PNCPU(J3DShapeMtxImm *this,int param_1,ushort param_2)

{
  J3DGraphBase::J3DFifoLoadPosMtxImm((J3DGraphBase::j3dSys.mpCurShapePacket)->mpViewMtx,param_1 * 3)
  ;
  J3DGraphBase::J3DFifoLoadNrmMtxImm((J3DGraphBase::j3dSys.mpCurShapePacket)->mpViewMtx,param_1 * 3)
  ;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall J3DShapeMtxConcatView::loadMtxConcatView_PNGP(int,
                                                            unsigned short) const */

void __thiscall
J3DShapeMtxConcatView::loadMtxConcatView_PNGP
          (J3DShapeMtxConcatView *this,int param_1,ushort param_2)

{
  undefined2 in_register_00000014;
  MTX34 MStack72;
  
  mtx::PSMTXConcat((J3DGraphBase::j3dSys.mpCurShapePacket)->mpViewMtx,
                   J3DGraphBase::j3dSys.mpCurDrawPosMtxArr + param_2,&MStack72);
  J3DGraphBase::J3DFifoLoadPosMtxImm(&MStack72,param_1 * 3);
  (**(code **)(*(int *)this + 0x24))(this,param_1,CONCAT22(in_register_00000014,param_2),&MStack72);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall J3DShapeMtxConcatView::loadMtxConcatView_PCPU(int,
                                                            unsigned short) const */

void __thiscall
J3DShapeMtxConcatView::loadMtxConcatView_PCPU
          (J3DShapeMtxConcatView *this,int param_1,ushort param_2)

{
  undefined2 in_register_00000014;
  MTX34 MStack72;
  
  mtx::PSMTXConcat((J3DGraphBase::j3dSys.mpCurShapePacket)->mpViewMtx,
                   J3DGraphBase::j3dSys.mpCurDrawPosMtxArr + param_2,&MStack72);
  J3DGraphBase::J3DFifoLoadPosMtxImm((J3DGraphBase::j3dSys.mpCurShapePacket)->mpViewMtx,param_1 * 3)
  ;
  (**(code **)(*(int *)this + 0x24))(this,param_1,CONCAT22(in_register_00000014,param_2),&MStack72);
  return;
}


/* __thiscall J3DShapeMtxConcatView::loadMtxConcatView_NCPU(int,
                                                            unsigned short) const */

void __thiscall
J3DShapeMtxConcatView::loadMtxConcatView_NCPU
          (J3DShapeMtxConcatView *this,int param_1,ushort param_2)

{
  MTX34 MStack56;
  
  mtx::PSMTXConcat((J3DGraphBase::j3dSys.mpCurShapePacket)->mpViewMtx,
                   J3DGraphBase::j3dSys.mpCurDrawPosMtxArr + param_2,&MStack56);
  J3DGraphBase::J3DFifoLoadPosMtxImm(&MStack56,param_1 * 3);
  J3DGraphBase::J3DFifoLoadNrmMtxImm((J3DGraphBase::j3dSys.mpCurShapePacket)->mpViewMtx,param_1 * 3)
  ;
  return;
}


/* __thiscall J3DShapeMtxConcatView::loadMtxConcatView_PNCPU(int,
                                                             unsigned short) const */

void __thiscall
J3DShapeMtxConcatView::loadMtxConcatView_PNCPU
          (J3DShapeMtxConcatView *this,int param_1,ushort param_2)

{
  J3DGraphBase::J3DFifoLoadPosMtxImm((J3DGraphBase::j3dSys.mpCurShapePacket)->mpViewMtx,param_1 * 3)
  ;
  J3DGraphBase::J3DFifoLoadNrmMtxImm((J3DGraphBase::j3dSys.mpCurShapePacket)->mpViewMtx,param_1 * 3)
  ;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall J3DShapeMtx::load(void) const */

void __thiscall J3DShapeMtx::load(J3DShapeMtx *this)

{
  PTMF local_18 [2];
  
  local_18[0].this_delta = *(int *)(&sMtxLoadPipeline + _sCurrentPipeline * 0xc);
  local_18[0].vtbl_offset = (&DAT_8039d9a4)[_sCurrentPipeline * 3];
  local_18[0].func = (undefined *)(&DAT_8039d9a8)[_sCurrentPipeline * 3];
  Runtime.PPCEABI.H::__ptmf_scall(local_18,this,(void *)0x0);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall J3DShapeMtx::calcNBTScale(Vec const &,
                                        float *[][][],
                                        float *[][][]) */

void __thiscall
J3DShapeMtx::calcNBTScale(J3DShapeMtx *this,Vec *param_1,float *param_2,float *param_3)

{
  J3DGraphBase::J3DPSMtx33Copy
            (param_2 + (uint)*(ushort *)(this + 4) * 9,param_3 + (uint)*(ushort *)(this + 4) * 9);
  J3DGraphBase::J3DScaleNrmMtx33(param_3 + (uint)*(ushort *)(this + 4) * 9,param_1);
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall J3DShapeMtxImm::load(void) const */

void __thiscall J3DShapeMtxImm::load(J3DShapeMtxImm *this)

{
  PTMF local_18 [2];
  
  local_18[0].this_delta = *(int *)(&sMtxLoadPipeline + _sCurrentPipeline * 0xc);
  local_18[0].vtbl_offset = (&DAT_8039da04)[_sCurrentPipeline * 3];
  local_18[0].func = (undefined *)(&DAT_8039da08)[_sCurrentPipeline * 3];
  Runtime.PPCEABI.H::__ptmf_scall(local_18,this,(void *)0x0);
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall J3DShapeMtxConcatView::load(void) const */

void __thiscall J3DShapeMtxConcatView::load(J3DShapeMtxConcatView *this)

{
  PTMF local_18;
  
  sMtxPtrTbl[0] = (J3DGraphBase::j3dSys.mpCurModel)->mpNodeMtx;
  sMtxPtrTbl[1] = (J3DGraphBase::j3dSys.mpCurModel)->mpWeightEnvMtx;
  local_18.this_delta = *(int *)(&sMtxLoadPipeline + _sCurrentPipeline * 0xc);
  local_18.vtbl_offset = (&DAT_8039da64)[_sCurrentPipeline * 3];
  local_18.func = (undefined *)(&DAT_8039da68)[_sCurrentPipeline * 3];
  J3DGraphBase::j3dSys.mpCurDrawPosMtxArr =
       sMtxPtrTbl
       [((J3DGraphBase::j3dSys.mpCurModel)->mpModelData->mJointTree).mDrawMtxData.mpMtxTypeArray
        [*(ushort *)(this + 4)]];
  gx::GXSetArray(GX_POS_MTX_ARRAY,J3DGraphBase::j3dSys.mpCurDrawPosMtxArr,0x30);
  Runtime.PPCEABI.H::__ptmf_scall(&local_18,this,(void *)0x0);
  return;
}


/* __thiscall J3DShapeMtxImm::loadNrmMtx(int,
                                         unsigned short) const */

void __thiscall J3DShapeMtxImm::loadNrmMtx(J3DShapeMtxImm *this,int param_1,ushort param_2)

{
  uint uVar1;
  float fVar2;
  undefined auStack88 [36];
  undefined auStack52 [48];
  
  fVar2 = J3DGraphBase::j3dSys.mCurNBTScale.z;
  uVar1 = (uint)param_2;
  if (*(char *)(J3DShapeMtx::sCurrentScaleFlag + uVar1) == '\x01') {
    if (J3DShapeMtx::sNBTFlag == '\0') {
      J3DGraphBase::J3DFifoLoadNrmMtxImm(J3DGraphBase::j3dSys.mpCurDrawPosMtxArr + uVar1,0);
    }
    else {
      J3DGraphBase::J3DPSMtx33CopyFrom34(J3DGraphBase::j3dSys.mpCurDrawPosMtxArr + uVar1,auStack52);
      J3DGraphBase::J3DScaleNrmMtx33(auStack52,fVar2);
      J3DGraphBase::J3DFifoLoadNrmMtxImm3x3(auStack52,0);
    }
  }
  else {
    J3DGraphBase::J3DPSCalcInverseTranspose
              (J3DGraphBase::j3dSys.mpCurDrawPosMtxArr + uVar1,auStack88);
    if (J3DShapeMtx::sNBTFlag == '\0') {
      J3DGraphBase::J3DFifoLoadNrmMtxImm3x3(auStack88,0);
    }
    else {
      J3DGraphBase::J3DScaleNrmMtx33(auStack88,J3DGraphBase::j3dSys.mCurNBTScale.z);
      J3DGraphBase::J3DFifoLoadNrmMtxImm3x3(auStack88,0);
    }
  }
  return;
}


/* __thiscall J3DShapeMtxConcatView::loadNrmMtx(int,
                                                unsigned short,
                                                float *[][][][]) const */

void __thiscall
J3DShapeMtxConcatView::loadNrmMtx
          (J3DShapeMtxConcatView *this,int param_1,ushort param_2,float *param_3)

{
  float fVar1;
  undefined auStack88 [36];
  undefined auStack52 [48];
  
  fVar1 = J3DGraphBase::j3dSys.mCurNBTScale.z;
  if (*(char *)(J3DShapeMtx::sCurrentScaleFlag + param_2) == '\x01') {
    if (J3DShapeMtx::sNBTFlag == '\0') {
      J3DGraphBase::J3DFifoLoadNrmMtxImm(param_3,0);
    }
    else {
      J3DGraphBase::J3DPSMtx33CopyFrom34(param_3,auStack52);
      J3DGraphBase::J3DScaleNrmMtx33(auStack52,fVar1);
      J3DGraphBase::J3DFifoLoadNrmMtxImm3x3(auStack52,0);
    }
  }
  else {
    J3DGraphBase::J3DPSCalcInverseTranspose(param_3,auStack88);
    if (J3DShapeMtx::sNBTFlag == '\0') {
      J3DGraphBase::J3DFifoLoadNrmMtxImm3x3(auStack88,0);
    }
    else {
      J3DGraphBase::J3DScaleNrmMtx33(auStack88,J3DGraphBase::j3dSys.mCurNBTScale.z);
      J3DGraphBase::J3DFifoLoadNrmMtxImm3x3(auStack88,0);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall J3DShapeMtxMulti::load(void) const */

void __thiscall J3DShapeMtxMulti::load(J3DShapeMtxMulti *this)

{
  void *pvVar1;
  int iVar2;
  PTMF local_28 [2];
  
  local_28[0].this_delta = *(int *)(&J3DShapeMtx::sMtxLoadPipeline + _sCurrentPipeline * 0xc);
  local_28[0].vtbl_offset = (&DAT_8039d9a4)[_sCurrentPipeline * 3];
  local_28[0].func = (undefined *)(&DAT_8039d9a8)[_sCurrentPipeline * 3];
  iVar2 = 0;
  for (pvVar1 = (void *)0x0; (int)pvVar1 < (int)(uint)*(ushort *)(this + 8);
      pvVar1 = (void *)((int)pvVar1 + 1)) {
    if (*(short *)(*(int *)(this + 0xc) + iVar2) != -1) {
      Runtime.PPCEABI.H::__ptmf_scall(local_28,this,pvVar1);
    }
    iVar2 = iVar2 + 2;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall J3DShapeMtxMulti::calcNBTScale(Vec const &,
                                             float *[][][],
                                             float *[][][]) */

void __thiscall
J3DShapeMtxMulti::calcNBTScale(J3DShapeMtxMulti *this,Vec *param_1,float *param_2,float *param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  for (iVar2 = 0; iVar2 < (int)(uint)*(ushort *)(this + 8); iVar2 = iVar2 + 1) {
    uVar1 = (uint)*(ushort *)(*(int *)(this + 0xc) + iVar3);
    if (uVar1 != 0xffff) {
      J3DGraphBase::J3DPSMtx33Copy(param_2 + uVar1 * 9,param_3 + uVar1 * 9);
      J3DGraphBase::J3DScaleNrmMtx33
                (param_3 + (uint)*(ushort *)(*(int *)(this + 0xc) + iVar3) * 9,param_1);
    }
    iVar3 = iVar3 + 2;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall J3DShapeMtxMultiImm::load(void) const */

void __thiscall J3DShapeMtxMultiImm::load(J3DShapeMtxMultiImm *this)

{
  void *pvVar1;
  int iVar2;
  PTMF local_28 [2];
  
  local_28[0].this_delta = *(int *)(&J3DShapeMtxImm::sMtxLoadPipeline + _sCurrentPipeline * 0xc);
  local_28[0].vtbl_offset = (&DAT_8039da04)[_sCurrentPipeline * 3];
  local_28[0].func = (undefined *)(&DAT_8039da08)[_sCurrentPipeline * 3];
  iVar2 = 0;
  for (pvVar1 = (void *)0x0; (int)pvVar1 < (int)(uint)*(ushort *)(this + 8);
      pvVar1 = (void *)((int)pvVar1 + 1)) {
    if (*(short *)(*(int *)(this + 0xc) + iVar2) != -1) {
      Runtime.PPCEABI.H::__ptmf_scall(local_28,this,pvVar1);
    }
    iVar2 = iVar2 + 2;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall J3DShapeMtxMultiConcatView::load(void) const */

void __thiscall J3DShapeMtxMultiConcatView::load(J3DShapeMtxMultiConcatView *this)

{
  void *pvVar1;
  int iVar2;
  PTMF local_28;
  
  J3DShapeMtxConcatView::sMtxPtrTbl[0] = (J3DGraphBase::j3dSys.mpCurModel)->mpNodeMtx;
  J3DShapeMtxConcatView::sMtxPtrTbl[1] = (J3DGraphBase::j3dSys.mpCurModel)->mpWeightEnvMtx;
  local_28.this_delta = *(int *)(&J3DShapeMtxConcatView::sMtxLoadPipeline + _sCurrentPipeline * 0xc)
  ;
  local_28.vtbl_offset = (&DAT_8039da64)[_sCurrentPipeline * 3];
  local_28.func = (undefined *)(&DAT_8039da68)[_sCurrentPipeline * 3];
  iVar2 = 0;
  for (pvVar1 = (void *)0x0; (int)pvVar1 < (int)(uint)*(ushort *)(this + 8);
      pvVar1 = (void *)((int)pvVar1 + 1)) {
    if (*(ushort *)(*(int *)(this + 0xc) + iVar2) != 0xffff) {
      J3DGraphBase::j3dSys.mpCurDrawPosMtxArr =
           J3DShapeMtxConcatView::sMtxPtrTbl
           [((J3DGraphBase::j3dSys.mpCurModel)->mpModelData->mJointTree).mDrawMtxData.mpMtxTypeArray
            [*(ushort *)(*(int *)(this + 0xc) + iVar2)]];
      gx::GXSetArray(GX_POS_MTX_ARRAY,J3DGraphBase::j3dSys.mpCurDrawPosMtxArr,0x30);
      Runtime.PPCEABI.H::__ptmf_scall(&local_28,this,pvVar1);
    }
    iVar2 = iVar2 + 2;
  }
  return;
}


/* __thiscall J3DShapeMtxMultiImm::loadNrmMtx(int,
                                              unsigned short) const */

void __thiscall
J3DShapeMtxMultiImm::loadNrmMtx(J3DShapeMtxMultiImm *this,int param_1,ushort param_2)

{
  uint uVar1;
  float fVar2;
  undefined auStack88 [36];
  undefined auStack52 [48];
  
  fVar2 = J3DGraphBase::j3dSys.mCurNBTScale.z;
  uVar1 = (uint)param_2;
  if (*(char *)(J3DShapeMtx::sCurrentScaleFlag + uVar1) == '\x01') {
    if (J3DShapeMtx::sNBTFlag == '\0') {
      J3DGraphBase::J3DFifoLoadNrmMtxImm
                (J3DGraphBase::j3dSys.mpCurDrawPosMtxArr + uVar1,param_1 * 3);
    }
    else {
      J3DGraphBase::J3DPSMtx33CopyFrom34(J3DGraphBase::j3dSys.mpCurDrawPosMtxArr + uVar1,auStack52);
      J3DGraphBase::J3DScaleNrmMtx33(auStack52,fVar2);
      J3DGraphBase::J3DFifoLoadNrmMtxImm3x3(auStack52,0);
    }
  }
  else {
    J3DGraphBase::J3DPSCalcInverseTranspose
              (J3DGraphBase::j3dSys.mpCurDrawPosMtxArr + uVar1,auStack88);
    if (J3DShapeMtx::sNBTFlag == '\0') {
      J3DGraphBase::J3DFifoLoadNrmMtxImm3x3(auStack88,param_1 * 3);
    }
    else {
      J3DGraphBase::J3DScaleNrmMtx33(auStack88,J3DGraphBase::j3dSys.mCurNBTScale.z);
      J3DGraphBase::J3DFifoLoadNrmMtxImm3x3(auStack88,param_1 * 3);
    }
  }
  return;
}


/* __thiscall J3DShapeMtxMultiConcatView::loadNrmMtx(int,
                                                     unsigned short,
                                                     float *[][][][]) const */

void __thiscall
J3DShapeMtxMultiConcatView::loadNrmMtx
          (J3DShapeMtxMultiConcatView *this,int param_1,ushort param_2,float *param_3)

{
  float fVar1;
  undefined auStack88 [36];
  undefined auStack52 [48];
  
  fVar1 = J3DGraphBase::j3dSys.mCurNBTScale.z;
  if (*(char *)(J3DShapeMtx::sCurrentScaleFlag + param_2) == '\x01') {
    if (J3DShapeMtx::sNBTFlag == '\0') {
      J3DGraphBase::J3DFifoLoadNrmMtxImm(param_3,param_1 * 3);
    }
    else {
      J3DGraphBase::J3DPSMtx33CopyFrom34(param_3,auStack52);
      J3DGraphBase::J3DScaleNrmMtx33(auStack52,fVar1);
      J3DGraphBase::J3DFifoLoadNrmMtxImm3x3(auStack52,0);
    }
  }
  else {
    J3DGraphBase::J3DPSCalcInverseTranspose(param_3,auStack88);
    if (J3DShapeMtx::sNBTFlag == '\0') {
      J3DGraphBase::J3DFifoLoadNrmMtxImm3x3(auStack88,param_1 * 3);
    }
    else {
      J3DGraphBase::J3DScaleNrmMtx33(auStack88,J3DGraphBase::j3dSys.mCurNBTScale.z);
      J3DGraphBase::J3DFifoLoadNrmMtxImm3x3(auStack88,param_1 * 3);
    }
  }
  return;
}


/* __thiscall J3DShapeMtxBBoardImm::load(void) const */

void __thiscall J3DShapeMtxBBoardImm::load(J3DShapeMtxBBoardImm *this)

{
  MTX34 local_38;
  
  mtx::PSMTXCopy(J3DGraphBase::j3dSys.mpCurDrawPosMtxArr + *(ushort *)(this + 4),&local_38);
  J3DGraphBase::J3DCalcBBoardMtx(&local_38);
  J3DGraphBase::J3DFifoLoadPosMtxImm(&local_38,0);
  local_38.m[0][0] = J3DGraphBase::_1862 / local_38.m[0][0];
  local_38.m[1][1] = J3DGraphBase::_1862 / local_38.m[1][1];
  local_38.m[2][2] = J3DGraphBase::_1862 / local_38.m[2][2];
  local_38.m[0][3] = J3DGraphBase::_1863;
  local_38.m[1][3] = J3DGraphBase::_1863;
  local_38.m[2][3] = J3DGraphBase::_1863;
  if (J3DShapeMtx::sNBTFlag == '\0') {
    J3DGraphBase::J3DFifoLoadNrmMtxImm(&local_38,0);
  }
  else {
    J3DGraphBase::J3DScaleNrmMtx(&local_38,J3DGraphBase::j3dSys.mCurNBTScale.z);
    J3DGraphBase::J3DFifoLoadNrmMtxImm(&local_38,0);
  }
  return;
}


/* __thiscall J3DShapeMtxBBoardConcatView::load(void) const */

void __thiscall J3DShapeMtxBBoardConcatView::load(J3DShapeMtxBBoardConcatView *this)

{
  uint uVar1;
  MTX34 local_38;
  
  uVar1 = (uint)(ushort)((J3DGraphBase::j3dSys.mpCurModel)->mpModelData->mJointTree).mDrawMtxData.
                        mpDataArray[*(ushort *)(this + 4)];
  if (((J3DGraphBase::j3dSys.mpCurModel)->mpModelData->mJointTree).mDrawMtxData.mpMtxTypeArray
      [*(ushort *)(this + 4)] == 0) {
    mtx::PSMTXConcat(&J3DGraphBase::j3dSys.mCurViewMtx,
                     (J3DGraphBase::j3dSys.mpCurModel)->mpNodeMtx + uVar1,&local_38);
  }
  else {
    mtx::PSMTXConcat(&J3DGraphBase::j3dSys.mCurViewMtx,
                     (J3DGraphBase::j3dSys.mpCurModel)->mpWeightEnvMtx + uVar1,&local_38);
  }
  J3DGraphBase::J3DCalcBBoardMtx(&local_38);
  J3DGraphBase::J3DFifoLoadPosMtxImm(&local_38,0);
  local_38.m[0][0] = J3DGraphBase::_1862 / local_38.m[0][0];
  local_38.m[1][1] = J3DGraphBase::_1862 / local_38.m[1][1];
  local_38.m[2][2] = J3DGraphBase::_1862 / local_38.m[2][2];
  local_38.m[0][3] = J3DGraphBase::_1863;
  local_38.m[1][3] = J3DGraphBase::_1863;
  local_38.m[2][3] = J3DGraphBase::_1863;
  if (J3DShapeMtx::sNBTFlag == '\0') {
    J3DGraphBase::J3DFifoLoadNrmMtxImm(&local_38,0);
  }
  else {
    J3DGraphBase::J3DScaleNrmMtx(&local_38,J3DGraphBase::j3dSys.mCurNBTScale.z);
    J3DGraphBase::J3DFifoLoadNrmMtxImm(&local_38,0);
  }
  return;
}


/* __thiscall J3DShapeMtxYBBoardImm::load(void) const */

void __thiscall J3DShapeMtxYBBoardImm::load(J3DShapeMtxYBBoardImm *this)

{
  undefined auStack104 [36];
  MTX34 MStack68;
  
  mtx::PSMTXCopy(J3DGraphBase::j3dSys.mpCurDrawPosMtxArr + *(ushort *)(this + 4),&MStack68);
  J3DGraphBase::J3DCalcYBBoardMtx(&MStack68);
  J3DGraphBase::J3DFifoLoadPosMtxImm(&MStack68,0);
  if (*(char *)(J3DShapeMtx::sCurrentScaleFlag + *(ushort *)(this + 4)) == '\x01') {
    if (J3DShapeMtx::sNBTFlag == '\0') {
      J3DGraphBase::J3DFifoLoadNrmMtxImm(&MStack68,0);
    }
    else {
      J3DGraphBase::J3DScaleNrmMtx(&MStack68,J3DGraphBase::j3dSys.mCurNBTScale.z);
      J3DGraphBase::J3DFifoLoadNrmMtxImm(&MStack68,0);
    }
  }
  else {
    J3DGraphBase::J3DPSCalcInverseTranspose(&MStack68,auStack104);
    if (J3DShapeMtx::sNBTFlag == '\0') {
      J3DGraphBase::J3DFifoLoadNrmMtxImm3x3(auStack104,0);
    }
    else {
      J3DGraphBase::J3DScaleNrmMtx33(auStack104,J3DGraphBase::j3dSys.mCurNBTScale.z);
      J3DGraphBase::J3DFifoLoadNrmMtxImm3x3(auStack104,0);
    }
  }
  return;
}


/* __thiscall J3DShapeMtxYBBoardConcatView::load(void) const */

void __thiscall J3DShapeMtxYBBoardConcatView::load(J3DShapeMtxYBBoardConcatView *this)

{
  uint uVar1;
  undefined auStack104 [36];
  MTX34 MStack68;
  
  uVar1 = (uint)(ushort)((J3DGraphBase::j3dSys.mpCurModel)->mpModelData->mJointTree).mDrawMtxData.
                        mpDataArray[*(ushort *)(this + 4)];
  if (((J3DGraphBase::j3dSys.mpCurModel)->mpModelData->mJointTree).mDrawMtxData.mpMtxTypeArray
      [*(ushort *)(this + 4)] == 0) {
    mtx::PSMTXConcat(&J3DGraphBase::j3dSys.mCurViewMtx,
                     (J3DGraphBase::j3dSys.mpCurModel)->mpNodeMtx + uVar1,&MStack68);
  }
  else {
    mtx::PSMTXConcat(&J3DGraphBase::j3dSys.mCurViewMtx,
                     (J3DGraphBase::j3dSys.mpCurModel)->mpWeightEnvMtx + uVar1,&MStack68);
  }
  J3DGraphBase::J3DCalcYBBoardMtx(&MStack68);
  J3DGraphBase::J3DFifoLoadPosMtxImm(&MStack68,0);
  if (*(char *)(J3DShapeMtx::sCurrentScaleFlag + *(ushort *)(this + 4)) == '\x01') {
    if (J3DShapeMtx::sNBTFlag == '\0') {
      J3DGraphBase::J3DFifoLoadNrmMtxImm(&MStack68,0);
    }
    else {
      J3DGraphBase::J3DScaleNrmMtx(&MStack68,J3DGraphBase::j3dSys.mCurNBTScale.z);
      J3DGraphBase::J3DFifoLoadNrmMtxImm(&MStack68,0);
    }
  }
  else {
    J3DGraphBase::J3DPSCalcInverseTranspose(&MStack68,auStack104);
    if (J3DShapeMtx::sNBTFlag == '\0') {
      J3DGraphBase::J3DFifoLoadNrmMtxImm3x3(auStack104,0);
    }
    else {
      J3DGraphBase::J3DScaleNrmMtx33(auStack104,J3DGraphBase::j3dSys.mCurNBTScale.z);
      J3DGraphBase::J3DFifoLoadNrmMtxImm3x3(auStack104,0);
    }
  }
  return;
}


/* __thiscall J3DShapeDraw::J3DShapeDraw(unsigned char const *,
                                         unsigned long) */

void __thiscall J3DShapeDraw::J3DShapeDraw(J3DShapeDraw *this,uchar *param_1,ulong param_2)

{
  *(undefined1 **)this = &__vt;
  *(uchar **)(this + 8) = param_1;
  *(ulong *)(this + 4) = param_2;
  return;
}


/* __thiscall J3DShapeDraw::draw(void) const */

void __thiscall J3DShapeDraw::draw(J3DShapeDraw *this)

{
  gx::GXCallDisplayList(*(undefined4 *)(this + 8),*(undefined4 *)(this + 4));
  return;
}


/* __thiscall J3DShapeDraw::~J3DShapeDraw(void) */

void __thiscall J3DShapeDraw::_J3DShapeDraw(J3DShapeDraw *this)

{
  short in_r4;
  
  if ((this != (J3DShapeDraw *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall J3DShapeMtxYBBoardConcatView::~J3DShapeMtxYBBoardConcatView(void) */

void __thiscall
J3DShapeMtxYBBoardConcatView::_J3DShapeMtxYBBoardConcatView(J3DShapeMtxYBBoardConcatView *this)

{
  bool bVar1;
  short in_r4;
  
  bVar1 = this != (J3DShapeMtxYBBoardConcatView *)0x0;
  if (bVar1) {
    *(undefined1 **)this = &__vt;
    if (((bVar1) && (*(undefined1 **)this = &J3DShapeMtxYBBoardImm::__vt, bVar1)) &&
       (*(undefined1 **)this = &J3DShapeMtxImm::__vt, bVar1)) {
      *(undefined1 **)this = &J3DShapeMtx::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DShapeMtxYBBoardImm::getType(void) const */

undefined4 __thiscall J3DShapeMtxYBBoardImm::getType(J3DShapeMtxYBBoardImm *this)

{
  return 0x534d5942;
}


/* __thiscall J3DShapeMtx::getUseMtxIndex(unsigned short) const */

undefined2 __thiscall J3DShapeMtx::getUseMtxIndex(J3DShapeMtx *this,ushort param_1)

{
  return *(undefined2 *)(this + 4);
}


/* __thiscall J3DShapeMtxYBBoardImm::~J3DShapeMtxYBBoardImm(void) */

void __thiscall J3DShapeMtxYBBoardImm::_J3DShapeMtxYBBoardImm(J3DShapeMtxYBBoardImm *this)

{
  bool bVar1;
  short in_r4;
  
  bVar1 = this != (J3DShapeMtxYBBoardImm *)0x0;
  if (bVar1) {
    *(undefined1 **)this = &__vt;
    if ((bVar1) && (*(undefined1 **)this = &J3DShapeMtxImm::__vt, bVar1)) {
      *(undefined1 **)this = &J3DShapeMtx::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DShapeMtxBBoardConcatView::~J3DShapeMtxBBoardConcatView(void) */

void __thiscall
J3DShapeMtxBBoardConcatView::_J3DShapeMtxBBoardConcatView(J3DShapeMtxBBoardConcatView *this)

{
  bool bVar1;
  short in_r4;
  
  bVar1 = this != (J3DShapeMtxBBoardConcatView *)0x0;
  if (bVar1) {
    *(undefined1 **)this = &__vt;
    if (((bVar1) && (*(undefined1 **)this = &J3DShapeMtxBBoardImm::__vt, bVar1)) &&
       (*(undefined1 **)this = &J3DShapeMtxImm::__vt, bVar1)) {
      *(undefined1 **)this = &J3DShapeMtx::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DShapeMtxBBoardImm::getType(void) const */

undefined4 __thiscall J3DShapeMtxBBoardImm::getType(J3DShapeMtxBBoardImm *this)

{
  return 0x534d4242;
}


/* __thiscall J3DShapeMtxBBoardImm::~J3DShapeMtxBBoardImm(void) */

void __thiscall J3DShapeMtxBBoardImm::_J3DShapeMtxBBoardImm(J3DShapeMtxBBoardImm *this)

{
  bool bVar1;
  short in_r4;
  
  bVar1 = this != (J3DShapeMtxBBoardImm *)0x0;
  if (bVar1) {
    *(undefined1 **)this = &__vt;
    if ((bVar1) && (*(undefined1 **)this = &J3DShapeMtxImm::__vt, bVar1)) {
      *(undefined1 **)this = &J3DShapeMtx::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DShapeMtxMultiConcatView::~J3DShapeMtxMultiConcatView(void) */

void __thiscall
J3DShapeMtxMultiConcatView::_J3DShapeMtxMultiConcatView(J3DShapeMtxMultiConcatView *this)

{
  bool bVar1;
  short in_r4;
  
  bVar1 = this != (J3DShapeMtxMultiConcatView *)0x0;
  if (bVar1) {
    *(undefined1 **)this = &__vt;
    if (((bVar1) && (*(undefined1 **)this = &J3DShapeMtxConcatView::__vt, bVar1)) &&
       (*(undefined1 **)this = &J3DShapeMtxImm::__vt, bVar1)) {
      *(undefined1 **)this = &J3DShapeMtx::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DShapeMtxMultiConcatView::getType(void) const */

undefined4 __thiscall J3DShapeMtxMultiConcatView::getType(J3DShapeMtxMultiConcatView *this)

{
  return 0x534d4d49;
}


/* __thiscall J3DShapeMtxMultiConcatView::getUseMtxNum(void) const */

undefined2 __thiscall J3DShapeMtxMultiConcatView::getUseMtxNum(J3DShapeMtxMultiConcatView *this)

{
  return *(undefined2 *)(this + 8);
}


/* __thiscall J3DShapeMtxMultiConcatView::getUseMtxIndex(unsigned short) const */

undefined2 __thiscall
J3DShapeMtxMultiConcatView::getUseMtxIndex(J3DShapeMtxMultiConcatView *this,ushort param_1)

{
  return *(undefined2 *)(*(int *)(this + 0xc) + (uint)param_1 * 2);
}


/* __thiscall J3DShapeMtxMultiConcatView::loadNrmMtx(int,
                                                     unsigned short) const */

void __thiscall
J3DShapeMtxMultiConcatView::loadNrmMtx(J3DShapeMtxMultiConcatView *this,int param_1,ushort param_2)

{
  return;
}


/* __thiscall J3DShapeMtxMultiImm::~J3DShapeMtxMultiImm(void) */

void __thiscall J3DShapeMtxMultiImm::_J3DShapeMtxMultiImm(J3DShapeMtxMultiImm *this)

{
  bool bVar1;
  short in_r4;
  
  bVar1 = this != (J3DShapeMtxMultiImm *)0x0;
  if (bVar1) {
    *(undefined1 **)this = &__vt;
    if ((bVar1) && (*(undefined1 **)this = &J3DShapeMtxImm::__vt, bVar1)) {
      *(undefined1 **)this = &J3DShapeMtx::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DShapeMtxMultiImm::getType(void) const */

undefined4 __thiscall J3DShapeMtxMultiImm::getType(J3DShapeMtxMultiImm *this)

{
  return 0x534d4d49;
}


/* __thiscall J3DShapeMtxMultiImm::getUseMtxNum(void) const */

undefined2 __thiscall J3DShapeMtxMultiImm::getUseMtxNum(J3DShapeMtxMultiImm *this)

{
  return *(undefined2 *)(this + 8);
}


/* __thiscall J3DShapeMtxMultiImm::getUseMtxIndex(unsigned short) const */

undefined2 __thiscall J3DShapeMtxMultiImm::getUseMtxIndex(J3DShapeMtxMultiImm *this,ushort param_1)

{
  return *(undefined2 *)(*(int *)(this + 0xc) + (uint)param_1 * 2);
}


/* __thiscall J3DShapeMtxMulti::~J3DShapeMtxMulti(void) */

void __thiscall J3DShapeMtxMulti::_J3DShapeMtxMulti(J3DShapeMtxMulti *this)

{
  short in_r4;
  
  if (this != (J3DShapeMtxMulti *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (J3DShapeMtxMulti *)0x0) {
      *(undefined1 **)this = &J3DShapeMtx::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DShapeMtxMulti::getType(void) const */

undefined4 __thiscall J3DShapeMtxMulti::getType(J3DShapeMtxMulti *this)

{
  return 0x534d4d4c;
}


/* __thiscall J3DShapeMtxMulti::getUseMtxNum(void) const */

undefined2 __thiscall J3DShapeMtxMulti::getUseMtxNum(J3DShapeMtxMulti *this)

{
  return *(undefined2 *)(this + 8);
}


/* __thiscall J3DShapeMtxMulti::getUseMtxIndex(unsigned short) const */

undefined2 __thiscall J3DShapeMtxMulti::getUseMtxIndex(J3DShapeMtxMulti *this,ushort param_1)

{
  return *(undefined2 *)(*(int *)(this + 0xc) + (uint)param_1 * 2);
}


/* __thiscall J3DShapeMtxConcatView::~J3DShapeMtxConcatView(void) */

void __thiscall J3DShapeMtxConcatView::_J3DShapeMtxConcatView(J3DShapeMtxConcatView *this)

{
  bool bVar1;
  short in_r4;
  
  bVar1 = this != (J3DShapeMtxConcatView *)0x0;
  if (bVar1) {
    *(undefined1 **)this = &__vt;
    if ((bVar1) && (*(undefined1 **)this = &J3DShapeMtxImm::__vt, bVar1)) {
      *(undefined1 **)this = &J3DShapeMtx::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DShapeMtxConcatView::getType(void) const */

undefined4 __thiscall J3DShapeMtxConcatView::getType(J3DShapeMtxConcatView *this)

{
  return 0x534d4356;
}


/* __thiscall J3DShapeMtxConcatView::loadNrmMtx(int,
                                                unsigned short) const */

void __thiscall
J3DShapeMtxConcatView::loadNrmMtx(J3DShapeMtxConcatView *this,int param_1,ushort param_2)

{
  return;
}


/* __thiscall J3DShapeMtxImm::~J3DShapeMtxImm(void) */

void __thiscall J3DShapeMtxImm::_J3DShapeMtxImm(J3DShapeMtxImm *this)

{
  short in_r4;
  
  if (this != (J3DShapeMtxImm *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (J3DShapeMtxImm *)0x0) {
      *(undefined1 **)this = &J3DShapeMtx::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DShapeMtxImm::getType(void) const */

undefined4 __thiscall J3DShapeMtxImm::getType(J3DShapeMtxImm *this)

{
  return 0x534d494d;
}


/* __thiscall J3DShapeMtx::~J3DShapeMtx(void) */

void __thiscall J3DShapeMtx::_J3DShapeMtx(J3DShapeMtx *this)

{
  short in_r4;
  
  if ((this != (J3DShapeMtx *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall J3DShapeMtx::getType(void) const */

undefined4 __thiscall J3DShapeMtx::getType(J3DShapeMtx *this)

{
  return 0x534d5458;
}


namespace J3DGraphBase {

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __sinit_J3DShapeMtx_cpp(void)

{
  _sMtxLoadPipeline = _1496;
  DAT_8039d9a4 = DAT_8039d974;
  DAT_8039d9a8 = PTR_loadMtxIndx_PNGP_8039d978;
  DAT_8039d9ac = _1497;
  DAT_8039d9b0 = DAT_8039d980;
  DAT_8039d9b4 = PTR_loadMtxIndx_PCPU_8039d984;
  DAT_8039d9b8 = _1498;
  DAT_8039d9bc = DAT_8039d98c;
  DAT_8039d9c0 = PTR_loadMtxIndx_NCPU_8039d990;
  DAT_8039d9c4 = _1499;
  DAT_8039d9c8 = DAT_8039d998;
  DAT_8039d9cc = PTR_loadMtxIndx_PNCPU_8039d99c;
  _sMtxLoadPipeline = _1500;
  DAT_8039da04 = DAT_8039d9d4;
  DAT_8039da08 = PTR_loadMtxImm_PNGP_8039d9d8;
  DAT_8039da0c = _1501;
  DAT_8039da10 = DAT_8039d9e0;
  DAT_8039da14 = PTR_loadMtxImm_PCPU_8039d9e4;
  DAT_8039da18 = _1502;
  DAT_8039da1c = DAT_8039d9ec;
  DAT_8039da20 = PTR_loadMtxImm_NCPU_8039d9f0;
  DAT_8039da24 = _1503;
  DAT_8039da28 = DAT_8039d9f8;
  DAT_8039da2c = PTR_loadMtxImm_PNCPU_8039d9fc;
  _sMtxLoadPipeline = _1504;
  DAT_8039da64 = DAT_8039da34;
  DAT_8039da68 = PTR_loadMtxConcatView_PNGP_8039da38;
  DAT_8039da6c = _1505;
  DAT_8039da70 = DAT_8039da40;
  DAT_8039da74 = PTR_loadMtxConcatView_PCPU_8039da44;
  DAT_8039da78 = _1506;
  DAT_8039da7c = DAT_8039da4c;
  DAT_8039da80 = PTR_loadMtxConcatView_NCPU_8039da50;
  DAT_8039da84 = _1507;
  DAT_8039da88 = DAT_8039da58;
  DAT_8039da8c = PTR_loadMtxConcatView_PNCPU_8039da5c;
  return;
}

