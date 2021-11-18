#include <SComponent/c_bg_w.h>
#include <m_Do_printf.h>
#include <mtx/mtx.h>
#include <SComponent/c_bg_w.h>
#include <JKernel/JKRHeap.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <mtx/vec.h>
#include <mtx/mtxvec.h>
#include <SComponent/c_m3d.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <SComponent/c_m3d_g_aab.h>
#include <SComponent/c_math.h>
#include <JUtility/JUTAssert.h>
#include <cBgW_RwgElm.h>
#include <Demangler/cBgW.h>
#include <cBgW_BgId.h>
#include <cBgW_TriElm.h>
#include <cBgW_NodeTree.h>
#include <cBgW_GrpElm.h>


namespace cBgW {
}

namespace SComponent {

/* __stdcall ASSERT_SOLDHEAP(void) */

void ASSERT_SOLDHEAP(void)

{
  int iVar1;
  
  iVar1 = (*(code *)JKRHeap::sCurrentHeap->vtbl->getHeapType)();
  if (iVar1 != 0x534c4944) {
    m_Do_printf::OSReport_Error
              (
              "＊＊＊＊＊＊＊Ａバグです＊＊＊＊＊＊＊\n＊＊＊＊＊＊＊Ａバグです＊＊＊＊＊＊＊\n＊＊＊＊＊＊＊Ａバグです＊＊＊＊＊＊＊\ncBgWはカレントヒープがソリッドヒープ以外だと破綻します。\n必ず、カレントヒープをソリッドヒープにしてください。\nここでnewされた領域は二度と開放されることはありません。\n慢性的にメモリーリークを繰り返し、いずれ確実にＡバグを引き起こすことでしょう。\n必ずp修正してください。この下の水色のメッセージにアクターの名前が書いてあるはずです。\n"
              );
  }
  return;
}

}

/* __thiscall cBgW::cBgW(void) */

void __thiscall cBgW::cBgW(cBgW *this)

{
  float fVar1;
  
  this->vtbl = (undefined *)&cBgW_BgId::__vt;
  this->mCount = 0x100;
  this->vtbl = (undefined *)&__vt;
  this->mpBgDt = (cBgD_t *)0x0;
  this->mFlags = Global;
  this->mbNeedsFullTransform = 1;
  this->mMoveCounter = 0;
  fVar1 = SComponent::0_0;
  (this->mTransVel).x = SComponent::0_0;
  (this->mTransVel).y = fVar1;
  (this->mTransVel).z = fVar1;
  this->mpTriElm = (cBgW_TriElm *)0x0;
  this->mpRwg = (cBgW_RwgElm *)0x0;
  this->mpBlk = (cBgW__BlkElm *)0x0;
  this->mpNodeTree = (cBgW_NodeTree *)0x0;
  this->mpGrp = (cBgW_GrpElm *)0x0;
  this->mpVtxTbl = (cXyz *)0x0;
  this->mpModelMtx = (MTX34 *)0x0;
  mtx::PSMTXIdentity(&this->mOldMtx);
  mtx::PSMTXIdentity(&this->mCurMtx);
  this->mRootGrpIdx = 0xffff;
  this->mWallCorrectPriority = 2;
  this->mIgnorePlaneType = 0;
  return;
}


/* __thiscall cBgW::~cBgW(void) */

void __thiscall cBgW::_cBgW(cBgW *this)

{
  short in_r4;
  
  if (this != (cBgW *)0x0) {
    this->vtbl = (undefined *)&__vt;
    FreeArea(this);
    if (this != (cBgW *)0x0) {
      this->vtbl = (undefined *)&cBgW_BgId::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall cBgW::FreeArea(void) */

void __thiscall cBgW::FreeArea(cBgW *this)

{
  this->mpTriElm = (cBgW_TriElm *)0x0;
  this->mpRwg = (cBgW_RwgElm *)0x0;
  this->mpNodeTree = (cBgW_NodeTree *)0x0;
  this->mpBlk = (cBgW__BlkElm *)0x0;
  this->mpGrp = (cBgW_GrpElm *)0x0;
  this->mpVtxTbl = (cXyz *)0x0;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall cBgW::GlobalVtx(void) */

void __thiscall cBgW::GlobalVtx(cBgW *this)

{
  cXyz *pcVar1;
  int iVar2;
  int iVar3;
  
  if (this->mpModelMtx != (MTX34 *)0x0) {
    if (this->mbNeedsFullTransform == 0) {
      iVar3 = 0;
      for (iVar2 = 0; iVar2 < this->mpBgDt->mVtxCount; iVar2 = iVar2 + 1) {
        pcVar1 = (cXyz *)((int)&this->mpVtxTbl->x + iVar3);
        mtx::PSVECAdd(pcVar1,&this->mTransVel,pcVar1);
        iVar3 = iVar3 + 0xc;
      }
    }
    else {
      iVar3 = 0;
      for (iVar2 = 0; iVar2 < this->mpBgDt->mVtxCount; iVar2 = iVar2 + 1) {
        mtx::PSMTXMultVec(this->mpModelMtx,(cXyz *)((int)&(this->mpBgDt->mpVtxTbl->v).x + iVar3),
                          (cXyz *)((int)&this->mpVtxTbl->x + iVar3));
        iVar3 = iVar3 + 0xc;
      }
    }
  }
  return;
}


/* __thiscall cBgW::SetVtx(void) */

bool __thiscall cBgW::SetVtx(cBgW *this)

{
  float fVar1;
  cXyz *pcVar2;
  int iVar3;
  int iVar4;
  
  SComponent::ASSERT_SOLDHEAP();
  if ((this->mFlags & NoVtxTbl) == 0) {
    if ((this->mFlags & MoveBG) == 0) {
      this->mpVtxTbl = (cXyz *)this->mpBgDt->mpVtxTbl;
    }
    else {
      pcVar2 = (cXyz *)JKernel::operator_new__(this->mpBgDt->mVtxCount * 0xc);
      this->mpVtxTbl = pcVar2;
      fVar1 = SComponent::0_0;
      if (this->mpVtxTbl == (cXyz *)0x0) {
        return true;
      }
      if ((this->mFlags & 0x40) != 0) {
        iVar3 = 0;
        for (iVar4 = 0; iVar4 < this->mpBgDt->mVtxCount; iVar4 = iVar4 + 1) {
          *(float *)((int)&this->mpVtxTbl->x + iVar3) = fVar1;
          *(float *)((int)&this->mpVtxTbl->y + iVar3) = fVar1;
          *(float *)((int)&this->mpVtxTbl->z + iVar3) = fVar1;
          iVar3 = iVar3 + 0xc;
        }
      }
      GlobalVtx(this);
    }
  }
  else {
    this->mpVtxTbl = (cXyz *)0x0;
  }
  return false;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall cBgW::CalcPlane(void) */

void __thiscall cBgW::CalcPlane(cBgW *this)

{
  cBgD__Tri_t *pTri;
  cBgW_TriElm *pElm;
  cBgD_Vtx_t *pVtx;
  cBgD__Tri_t *pTriTbl;
  int iVar1;
  int iVar2;
  int iVar3;
  double dVar4;
  
  pTriTbl = this->mpBgDt->mpTriTbl;
  if (this->mpVtxTbl != (cXyz *)0x0) {
    if (this->mbNeedsFullTransform == 0) {
      iVar2 = 0;
      for (iVar1 = 0; iVar1 < this->mpBgDt->mTriCount; iVar1 = iVar1 + 1) {
        dVar4 = (double)mtx::PSVECDotProduct
                                  ((int)&(this->mpTriElm->mPlane).mNorm.x + iVar2,&this->mTransVel);
        *(float *)((int)&(this->mpTriElm->mPlane).mDist + iVar2) =
             (float)((double)*(float *)((int)&(this->mpTriElm->mPlane).mDist + iVar2) - dVar4);
        iVar2 = iVar2 + 0x18;
      }
    }
    else {
      iVar3 = 0;
      iVar2 = 0;
      for (iVar1 = 0; iVar1 < this->mpBgDt->mTriCount; iVar1 = iVar1 + 1) {
        pElm = (cBgW_TriElm *)((int)&(this->mpTriElm->mPlane).mNorm.x + iVar2);
        pTri = (cBgD__Tri_t *)((int)&pTriTbl->mVtxIdx0 + iVar3);
        pVtx = (cBgD_Vtx_t *)this->mpVtxTbl;
        SComponent::cM3d_CalcPla
                  ((TVec3_float_ *)(pVtx + (ushort)pTri->mVtxIdx0),
                   (TVec3_float_ *)(pVtx + (ushort)pTri->mVtxIdx1),
                   (TVec3_float_ *)(pVtx + (ushort)pTri->mVtxIdx2),(TVec3_float_ *)pElm,
                   &(pElm->mPlane).mDist);
        iVar3 = iVar3 + 10;
        iVar2 = iVar2 + 0x18;
      }
    }
  }
  return;
}


/* __thiscall cBgW::SetTri(void) */

bool __thiscall cBgW::SetTri(cBgW *this)

{
  bool bVar1;
  undefined4 uVar2;
  cBgW_TriElm *pcVar3;
  int iVar4;
  
  SComponent::ASSERT_SOLDHEAP();
  iVar4 = this->mpBgDt->mTriCount;
  uVar2 = JKernel::operator_new__(iVar4 * 0x18 + 0x10);
  pcVar3 = (cBgW_TriElm *)
           Runtime.PPCEABI.H::__construct_new_array
                     (uVar2,cBgW_TriElm::cBgW_TriElm,cBgW_TriElm::_cBgW_TriElm,0x18,iVar4);
  this->mpTriElm = pcVar3;
  bVar1 = this->mpTriElm != (cBgW_TriElm *)0x0;
  if (bVar1) {
                    /* CalcPlane */
    (**(code **)(this->vtbl + 0x10))(this);
  }
  return !bVar1;
}


/* __thiscall cBgW::BlckConnect(unsigned short *,
                                int *,
                                int) */

void __thiscall cBgW::BlckConnect(cBgW *this,ushort *pRwgFirstIdx,int *pRwgPrevIdx,int idx)

{
  if (*pRwgFirstIdx == 0xffff) {
    *pRwgFirstIdx = (ushort)idx;
  }
  if (*pRwgPrevIdx != 0xffff) {
    this->mpRwg[*pRwgPrevIdx].mNext = (ushort)idx;
  }
  *pRwgPrevIdx = idx;
  this->mpRwg[*pRwgPrevIdx].mNext = -1;
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* WARNING: Removing unreachable block (ram,0x80247bd8) */
/* __thiscall cBgW::ClassifyPlane(void) */

void __thiscall cBgW::ClassifyPlane(cBgW *this)

{
  uint end;
  cBgW_TriElm *pTriElm;
  cBgD_t *pDt;
  ushort *pBlk;
  uint idx;
  int triP;
  int iVar1;
  int blk;
  int iVar2;
  undefined4 uVar3;
  undefined8 in_f31;
  double min;
  int blkIdxGround;
  int blkIdxWall;
  int blkIdxRoof;
  undefined auStack8 [8];
  float normY;
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (this->mpVtxTbl != (cXyz *)0x0) {
    iVar2 = 0;
    blk = 0;
    iVar1 = 0;
    min = (double)SComponent::G_CM3D_F_ABS_MIN;
    while( true ) {
      pDt = this->mpBgDt;
      if (pDt->mBlkCount <= iVar2) break;
      pBlk = (ushort *)((int)pDt->mpBlkTbl + iVar1);
      idx = (uint)*pBlk;
      if (iVar2 == pDt->mBlkCount + -1) {
        end = pDt->mTriCount;
      }
      else {
        end = (uint)pBlk[1];
      }
      *(undefined2 *)((int)&this->mpBlk->mRoofIdx + blk) = 0xffff;
      *(undefined2 *)((int)&this->mpBlk->mWallIdx + blk) = 0xffff;
      *(undefined2 *)((int)&this->mpBlk->mGroundIdx + blk) = 0xffff;
      blkIdxGround = 0xffff;
      blkIdxWall = 0xffff;
      blkIdxRoof = 0xffff;
      triP = idx * 0x18;
      for (; (int)idx <= (int)(end - 1); idx = idx + 1) {
        pTriElm = (cBgW_TriElm *)((int)&(this->mpTriElm->mPlane).mNorm.x + triP);
        normY = (pTriElm->mPlane).mNorm.y;
        if (((min <= (double)ABS((pTriElm->mPlane).mNorm.x)) || (min <= (double)ABS(normY))) ||
           (min <= (double)ABS((pTriElm->mPlane).mNorm.z))) {
          if (normY < SComponent::0_5) {
            if (SComponent::_0_8 <= normY) {
              if ((this->mIgnorePlaneType & Wall) == 0) {
                BlckConnect(this,(ushort *)((int)&this->mpBlk->mWallIdx + blk),&blkIdxWall,idx);
              }
            }
            else {
              if ((this->mIgnorePlaneType & Roof) == 0) {
                BlckConnect(this,(ushort *)((int)&this->mpBlk->mRoofIdx + blk),&blkIdxRoof,idx);
              }
            }
          }
          else {
            if ((this->mIgnorePlaneType & Ground) == 0) {
              BlckConnect(this,(ushort *)((int)&this->mpBlk->mGroundIdx + blk),&blkIdxGround,idx);
            }
          }
        }
        triP = triP + 0x18;
      }
      iVar2 = iVar2 + 1;
      blk = blk + 6;
      iVar1 = iVar1 + 2;
    }
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return;
}


/* __thiscall cBgW::MakeBlckTransMinMax(cXyz *,
                                        cXyz *) */

void __thiscall cBgW::MakeBlckTransMinMax(cBgW *this,cXyz *param_1,cXyz *param_2)

{
  mtx::PSVECAdd(param_1,&this->mTransVel,param_1);
  mtx::PSVECAdd(param_2,&this->mTransVel,param_2);
  return;
}


/* __thiscall cBgW::MakeBlckMinMax(int,
                                   cXyz *,
                                   cXyz *) */

void __thiscall cBgW::MakeBlckMinMax(cBgW *this,int param_1,cXyz *pMin,cXyz *pMax)

{
  cXyz *pVtx;
  
  pVtx = this->mpVtxTbl + param_1;
  if (pVtx->x < pMin->x) {
    pMin->x = pVtx->x;
  }
  if (pMax->x < pVtx->x) {
    pMax->x = pVtx->x;
  }
  if (pVtx->y < pMin->y) {
    pMin->y = pVtx->y;
  }
  if (pMax->y < pVtx->y) {
    pMax->y = pVtx->y;
  }
  if (pVtx->z < pMin->z) {
    pMin->z = pVtx->z;
  }
  if (pVtx->z <= pMax->z) {
    return;
  }
  pMax->z = pVtx->z;
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall cBgW::MakeBlckBnd(int,
                                cXyz *,
                                cXyz *) */

void __thiscall cBgW::MakeBlckBnd(cBgW *this,int blk_idx,cXyz *pMin,cXyz *pMax)

{
  float fVar1;
  uint max;
  cBgD_t *pDt;
  uint uVar2;
  int iVar3;
  
  fVar1 = SComponent::1_0E9;
  pDt = this->mpBgDt;
  uVar2 = (uint)pDt->mpBlkTbl[blk_idx];
  if (blk_idx == pDt->mBlkCount + -1) {
    max = pDt->mTriCount;
  }
  else {
    max = (uint)pDt->mpBlkTbl[blk_idx + 1];
  }
  if (this->mbNeedsFullTransform == 0) {
                    /* Fast path -- if no need to rebuild everything, just translate existing
                       blocks. */
    MakeBlckTransMinMax(this,pMin,pMax);
  }
  else {
    pMin->z = SComponent::1_0E9;
    pMin->y = fVar1;
    pMin->x = fVar1;
    fVar1 = SComponent::_1_0E9;
    pMax->z = SComponent::_1_0E9;
    pMax->y = fVar1;
    pMax->x = fVar1;
    iVar3 = uVar2 * 10;
    for (; fVar1 = SComponent::1_0, (int)uVar2 <= (int)(max - 1); uVar2 = uVar2 + 1) {
      MakeBlckMinMax(this,(uint)*(ushort *)((int)&this->mpBgDt->mpTriTbl->mVtxIdx0 + iVar3),pMin,
                     pMax);
      MakeBlckMinMax(this,(uint)*(ushort *)((int)&this->mpBgDt->mpTriTbl->mVtxIdx1 + iVar3),pMin,
                     pMax);
      MakeBlckMinMax(this,(uint)*(ushort *)((int)&this->mpBgDt->mpTriTbl->mVtxIdx2 + iVar3),pMin,
                     pMax);
      iVar3 = iVar3 + 10;
    }
    pMin->x = pMin->x - SComponent::1_0;
    pMin->y = pMin->y - fVar1;
    pMin->z = pMin->z - fVar1;
    pMax->x = pMax->x + fVar1;
    pMax->y = pMax->y + fVar1;
    pMax->z = pMax->z + fVar1;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall cBgW::MakeNodeTreeRp(int) */

void __thiscall cBgW::MakeNodeTreeRp(cBgW *this,int node_idx)

{
  float fVar1;
  cBgW_NodeTree *pNd;
  int iVar2;
  cBgD__Tree_t *pNode;
  uint childIdx;
  int iVar3;
  
  fVar1 = SComponent::1_0E9;
  pNode = this->mpBgDt->mpNodeTreeTbl + node_idx;
  if ((pNode->mFlag & 1) == 0) {
    pNd = this->mpNodeTree + node_idx;
    (pNd->mMin).z = SComponent::1_0E9;
    (pNd->mMin).y = fVar1;
    (pNd->mMin).x = fVar1;
    fVar1 = SComponent::_1_0E9;
    (pNd->mMax).z = SComponent::_1_0E9;
    (pNd->mMax).y = fVar1;
    (pNd->mMax).x = fVar1;
    iVar2 = 0;
    iVar3 = 0;
    do {
      childIdx = (uint)*(ushort *)((int)&pNode->mChild0 + iVar3);
      if (childIdx != 0xffff) {
        MakeNodeTreeRp(this,childIdx);
        ::cM3dGAab::SetMinMax
                  ((cM3dGAab *)(this->mpNodeTree + node_idx),&this->mpNodeTree[childIdx].mMin);
        ::cM3dGAab::SetMinMax
                  ((cM3dGAab *)(this->mpNodeTree + node_idx),&this->mpNodeTree[childIdx].mMax);
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 2;
    } while (iVar2 < 8);
  }
  else {
    if (pNode->mChild0 != 0xffff) {
      MakeBlckBnd(this,(uint)pNode->mChild0,&this->mpNodeTree[node_idx].mMin,
                  &this->mpNodeTree[node_idx].mMax);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall cBgW::MakeNodeTreeGrpRp(int) */

void __thiscall cBgW::MakeNodeTreeGrpRp(cBgW *this,int grp_idx)

{
  ushort uVar1;
  uint childId;
  
  childId = (uint)this->mpBgDt->mpGrpTbl[grp_idx].mTreIdx;
  if (childId != 0xffff) {
    MakeNodeTreeRp(this,childId);
    ::cM3dGAab::SetMin(&this->mpGrp[grp_idx].mAabb,
                       &this->mpNodeTree[this->mpBgDt->mpGrpTbl[grp_idx].mTreIdx].mMin);
    ::cM3dGAab::SetMax(&this->mpGrp[grp_idx].mAabb,
                       &this->mpNodeTree[this->mpBgDt->mpGrpTbl[grp_idx].mTreIdx].mMax);
  }
  uVar1 = this->mpBgDt->mpGrpTbl[grp_idx].mFirstChild;
  while (childId = (uint)uVar1, childId != 0xffff) {
    MakeNodeTreeGrpRp(this,childId);
    ::cM3dGAab::SetMin(&this->mpGrp[grp_idx].mAabb,&this->mpGrp[childId].mAabb.mMin);
    ::cM3dGAab::SetMax(&this->mpGrp[grp_idx].mAabb,&this->mpGrp[childId].mAabb.mMax);
    uVar1 = this->mpBgDt->mpGrpTbl[childId].mNextSibling;
  }
  return;
}


/* __thiscall cBgW::MakeNodeTree(void) */

void __thiscall cBgW::MakeNodeTree(cBgW *this)

{
  int iVar1;
  int iVar2;
  cM3dGAab *pAabb;
  int iVar3;
  float max;
  float min;
  
  max = SComponent::_1_0E9;
  min = SComponent::1_0E9;
  if (this->mpVtxTbl == (cXyz *)0x0) {
    iVar3 = 0;
    iVar2 = 0;
    iVar1 = this->mpBgDt->mGrpCount;
    if (0 < iVar1) {
      do {
        if (*(short *)((int)&this->mpBgDt->mpGrpTbl->mParent + iVar2) == -1) {
          this->mRootGrpIdx = iVar3;
          return;
        }
        iVar3 = iVar3 + 1;
        iVar2 = iVar2 + 0x34;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
    }
  }
  else {
    iVar2 = 0;
    iVar1 = 0;
    while( true ) {
      iVar3 = this->mpBgDt->mGrpCount;
      if (iVar3 <= iVar2) break;
      pAabb = (cM3dGAab *)((int)&(this->mpGrp->mAabb).mMin.x + iVar1);
      (pAabb->mMin).z = min;
      (pAabb->mMin).y = min;
      (pAabb->mMin).x = min;
      (pAabb->mMax).z = max;
      (pAabb->mMax).y = max;
      (pAabb->mMax).x = max;
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0x20;
    }
    iVar1 = 0;
    iVar2 = 0;
    if (0 < iVar3) {
      do {
        if (*(short *)((int)&this->mpBgDt->mpGrpTbl->mParent + iVar2) == -1) {
          this->mRootGrpIdx = iVar1;
          MakeNodeTreeGrpRp(this,iVar1);
          return;
        }
        iVar1 = iVar1 + 1;
        iVar2 = iVar2 + 0x34;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
  }
  return;
}


/* __thiscall cBgW::ChkMemoryError(void) */

undefined4 __thiscall cBgW::ChkMemoryError(cBgW *this)

{
  if ((((this->mpTriElm != (cBgW_TriElm *)0x0) && (this->mpRwg != (cBgW_RwgElm *)0x0)) &&
      (this->mpBlk != (cBgW__BlkElm *)0x0)) &&
     ((this->mpNodeTree != (cBgW_NodeTree *)0x0 && (this->mpGrp != (cBgW_GrpElm *)0x0)))) {
    return 0;
  }
  return 1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall cBgW::Set(cBgD_t *,
                        unsigned long,
                        float *[][][]) */

int __thiscall cBgW::Set(cBgW *this,cBgD_t *pData,cBgW__Flag flags,MTX34 *pMtx)

{
  int iVar1;
  bool bVar7;
  char cVar8;
  undefined4 uVar2;
  cBgW_RwgElm *pcVar3;
  cBgW__BlkElm *pcVar4;
  cBgW_NodeTree *pcVar5;
  cBgW_GrpElm *pcVar6;
  float fVar9;
  
  SComponent::ASSERT_SOLDHEAP();
  this->mFlags = Global;
  this->mpVtxTbl = (cXyz *)0x0;
  this->mpTriElm = (cBgW_TriElm *)0x0;
  this->mpRwg = (cBgW_RwgElm *)0x0;
  this->mpBlk = (cBgW__BlkElm *)0x0;
  this->mpNodeTree = (cBgW_NodeTree *)0x0;
  this->mpGrp = (cBgW_GrpElm *)0x0;
  fVar9 = SComponent::cM_rndF(SComponent::128_0);
                    /* Stagger the move counter */
  this->mMoveCounter = (byte)(int)fVar9;
  if (pData == (cBgD_t *)0x0) {
    iVar1 = 1;
  }
  else {
    this->mFlags = flags;
    if ((this->mFlags & Global) == 0) {
      this->mpModelMtx = pMtx;
      mtx::PSMTXCopy(this->mpModelMtx,&this->mOldMtx);
      mtx::PSMTXCopy(this->mpModelMtx,&this->mCurMtx);
    }
    else {
      this->mpModelMtx = (MTX34 *)0x0;
      mtx::PSMTXIdentity(&this->mOldMtx);
      mtx::PSMTXIdentity(&this->mCurMtx);
    }
    this->mpBgDt = pData;
    bVar7 = SetVtx(this);
    if ((bVar7 == false) && (cVar8 = SetTri(this), cVar8 == '\0')) {
      iVar1 = this->mpBgDt->mTriCount;
      uVar2 = JKernel::operator_new__(iVar1 * 8 + 0x10);
      pcVar3 = (cBgW_RwgElm *)
               Runtime.PPCEABI.H::__construct_new_array
                         (uVar2,cBgW_RwgElm::cBgW_RwgElm,cBgW_RwgElm::_cBgW_RwgElm,8,iVar1);
      this->mpRwg = pcVar3;
      if (this->mpRwg == (cBgW_RwgElm *)0x0) {
        FreeArea(this);
        iVar1 = 1;
      }
      else {
        pcVar4 = (cBgW__BlkElm *)JKernel::operator_new__(this->mpBgDt->mBlkCount * 6);
        this->mpBlk = pcVar4;
        if (this->mpBlk == (cBgW__BlkElm *)0x0) {
          FreeArea(this);
          iVar1 = 1;
        }
        else {
          iVar1 = this->mpBgDt->mNodeTreeCount;
          uVar2 = JKernel::operator_new__(iVar1 * 0x1c + 0x10);
          pcVar5 = (cBgW_NodeTree *)
                   Runtime.PPCEABI.H::__construct_new_array
                             (uVar2,cBgW_NodeTree::cBgW_NodeTree,cBgW_NodeTree::_cBgW_NodeTree,0x1c,
                              iVar1);
          this->mpNodeTree = pcVar5;
          if (this->mpNodeTree == (cBgW_NodeTree *)0x0) {
            FreeArea(this);
            iVar1 = 1;
          }
          else {
            iVar1 = this->mpBgDt->mGrpCount;
            uVar2 = JKernel::operator_new__(iVar1 * 0x20 + 0x10);
            pcVar6 = (cBgW_GrpElm *)
                     Runtime.PPCEABI.H::__construct_new_array
                               (uVar2,cBgW_GrpElm::cBgW_GrpElm,cBgW_GrpElm::_cBgW_GrpElm,0x20,iVar1)
            ;
            this->mpGrp = pcVar6;
            if (this->mpGrp == (cBgW_GrpElm *)0x0) {
              FreeArea(this);
              iVar1 = 1;
            }
            else {
                    /* ClassifyPlane */
              (**(code **)(this->vtbl + 0x14))(this);
              this->mbNeedsFullTransform = 1;
              MakeNodeTree(this);
              iVar1 = 0;
            }
          }
        }
      }
    }
    else {
      FreeArea(this);
      iVar1 = 1;
    }
  }
  return iVar1;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x8024856c) */
/* __thiscall cBgW::RwgLineCheck(unsigned short,
                                 cBgS_LinChk *) */

undefined4 __thiscall cBgW::RwgLineCheck(cBgW *this,ushort param_1,cBgS_LinChk *param_2)

{
  uint uVar1;
  cXyz *pcVar2;
  char cVar3;
  cXyz *pcVar4;
  cXyz *pcVar5;
  cBgW_TriElm *pcVar6;
  cBgD__Tri_t *pcVar7;
  undefined4 uVar8;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  undefined **local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  
  uVar8 = 0;
  local_4c = &cM3dGTri::__vt;
  do {
    uVar1 = (uint)param_1;
    pcVar7 = this->mpBgDt->mpTriTbl + uVar1;
    pcVar6 = this->mpTriElm + uVar1;
    pcVar2 = this->mpVtxTbl;
    pcVar5 = pcVar2 + (ushort)pcVar7->mVtxIdx2;
    pcVar4 = pcVar2 + (ushort)pcVar7->mVtxIdx1;
    pcVar2 = pcVar2 + (ushort)pcVar7->mVtxIdx0;
    local_48 = pcVar2->x;
    local_44 = pcVar2->y;
    local_40 = pcVar2->z;
    local_3c = pcVar4->x;
    local_38 = pcVar4->y;
    local_34 = pcVar4->z;
    local_30 = pcVar5->x;
    local_2c = pcVar5->y;
    local_28 = pcVar5->z;
    local_5c = (pcVar6->mPlane).mNorm.x;
    local_58 = (pcVar6->mPlane).mNorm.y;
    local_54 = (pcVar6->mPlane).mNorm.z;
    local_50 = (pcVar6->mPlane).mDist;
    cVar3 = SComponent::cM3d_Cross_LinTri
                      (&param_2->mLin,&local_5c,&local_68,param_2->field_0x53,param_2->field_0x54);
    if ((cVar3 != '\0') &&
       (cVar3 = (**(code **)(this->vtbl + 0x18))(this,param_1,(param_2->parent).mpPolyPassChk),
       cVar3 == '\0')) {
      (param_2->mLin).mP1.x = local_68;
      (param_2->mLin).mP1.y = local_64;
      (param_2->mLin).mP1.z = local_60;
      (param_2->mPolyInfo).mTriIdx = param_1;
      uVar8 = 1;
    }
    param_1 = this->mpRwg[uVar1].mNext;
  } while (param_1 != 0xffff);
  return uVar8;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall cBgW::LineCheckRp(cBgS_LinChk *,
                                int) */

undefined4 __thiscall cBgW::LineCheckRp(cBgW *this,cBgS_LinChk *param_1,int param_2)

{
  ushort uVar1;
  uint uVar2;
  undefined4 ret;
  char cVar3;
  cBgD__Tree_t *pcVar4;
  
  uVar2 = SComponent::cM3d_Cross_MinMaxBoxLine
                    (&this->mpNodeTree[param_2].mMin,&this->mpNodeTree[param_2].mMax,
                     (cXyz *)&param_1->mLin,&(param_1->mLin).mP1);
  if ((uVar2 & 0xff) == 0) {
    ret = 0;
  }
  else {
    pcVar4 = this->mpBgDt->mpNodeTreeTbl + param_2;
    ret = 0;
    if ((pcVar4->mFlag & 1) == 0) {
      if ((pcVar4->mChild0 != 0xffff) &&
         (cVar3 = LineCheckRp(this,param_1,(uint)pcVar4->mChild0), cVar3 != '\0')) {
        ret = 1;
      }
      if ((pcVar4->mChild1 != 0xffff) &&
         (cVar3 = LineCheckRp(this,param_1,(uint)pcVar4->mChild1), cVar3 != '\0')) {
        ret = 1;
      }
      if ((pcVar4->mChild2 != 0xffff) &&
         (cVar3 = LineCheckRp(this,param_1,(uint)pcVar4->mChild2), cVar3 != '\0')) {
        ret = 1;
      }
      if ((pcVar4->mChild3 != 0xffff) &&
         (cVar3 = LineCheckRp(this,param_1,(uint)pcVar4->mChild3), cVar3 != '\0')) {
        ret = 1;
      }
      if ((pcVar4->mChild4 != 0xffff) &&
         (cVar3 = LineCheckRp(this,param_1,(uint)pcVar4->mChild4), cVar3 != '\0')) {
        ret = 1;
      }
      if ((pcVar4->mChild5 != 0xffff) &&
         (cVar3 = LineCheckRp(this,param_1,(uint)pcVar4->mChild5), cVar3 != '\0')) {
        ret = 1;
      }
      if ((pcVar4->mChild6 != 0xffff) &&
         (cVar3 = LineCheckRp(this,param_1,(uint)pcVar4->mChild6), cVar3 != '\0')) {
        ret = 1;
      }
      if ((pcVar4->mChild7 != 0xffff) &&
         (cVar3 = LineCheckRp(this,param_1,(uint)pcVar4->mChild7), cVar3 != '\0')) {
        ret = 1;
      }
    }
    else {
      if (((param_1->field_0x50 != 0) &&
          (uVar1 = this->mpBlk[pcVar4->mChild0].mWallIdx, uVar1 != 0xffff)) &&
         (cVar3 = RwgLineCheck(this,uVar1,param_1), cVar3 != '\0')) {
        ret = 1;
      }
      if (((param_1->field_0x51 != 0) &&
          (uVar1 = this->mpBlk[pcVar4->mChild0].mGroundIdx, uVar1 != 0xffff)) &&
         (cVar3 = RwgLineCheck(this,uVar1,param_1), cVar3 != '\0')) {
        ret = 1;
      }
      if (((param_1->field_0x52 != 0) &&
          (uVar1 = this->mpBlk[pcVar4->mChild0].mRoofIdx, uVar1 != 0xffff)) &&
         (cVar3 = RwgLineCheck(this,uVar1,param_1), cVar3 != '\0')) {
        ret = 1;
      }
    }
  }
  return ret;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall cBgW::LineCheckGrpRp(cBgS_LinChk *,
                                   int,
                                   int) */

int __thiscall cBgW::LineCheckGrpRp(cBgW *this,cBgS_LinChk *pLinChk,int grp,int depth)

{
  ushort uVar1;
  char cVar5;
  int iVar2;
  cM3dGAab *pAabb;
  uint uVar3;
  uint uVar4;
  
  cVar5 = (**(code **)(this->vtbl + 0x20))(this,grp,(pLinChk->parent).mpGrpPassChk);
  if (cVar5 == '\0') {
    pAabb = &this->mpGrp[grp].mAabb;
    uVar3 = SComponent::cM3d_Cross_MinMaxBoxLine
                      (&pAabb->mMin,&pAabb->mMax,(cXyz *)&pLinChk->mLin,&(pLinChk->mLin).mP1);
    if ((uVar3 & 0xff) == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = 0;
      uVar3 = (uint)this->mpBgDt->mpGrpTbl[grp].mTreIdx;
      if ((uVar3 != 0xffff) && (cVar5 = LineCheckRp(this,pLinChk,uVar3), cVar5 != '\0')) {
        iVar2 = 1;
      }
      uVar1 = this->mpBgDt->mpGrpTbl[grp].mFirstChild;
      while (uVar3 = (uint)uVar1, uVar3 != 0xffff) {
        uVar4 = LineCheckGrpRp(this,pLinChk,uVar3,depth + 1);
        if ((uVar4 & 0xff) != 0) {
          iVar2 = 1;
        }
        uVar1 = this->mpBgDt->mpGrpTbl[uVar3].mNextSibling;
      }
    }
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x80248a50) */
/* WARNING: Removing unreachable block (ram,0x80248a98) */
/* __thiscall cBgW::RwgGroundCheckCommon(float,
                                         unsigned short,
                                         cBgS_GndChk *) */

undefined4 __thiscall cBgW::RwgGroundCheckCommon(cBgW *this,float y,ushort idx,cBgS_GndChk *pChk)

{
  uint uVar1;
  char cVar3;
  undefined4 uVar2;
  cXyz *pVtx;
  cBgD__Tri_t *pTri;
  undefined4 uVar4;
  double dVar5;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  dVar5 = (double)y;
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if ((dVar5 < (double)(pChk->mPos).y) && ((double)pChk->mRetY < dVar5)) {
    pTri = this->mpBgDt->mpTriTbl + idx;
    pVtx = this->mpVtxTbl;
    uVar1 = SComponent::cM3d_CrossY_Tri_Front
                      (pVtx + (ushort)pTri->mVtxIdx0,pVtx + (ushort)pTri->mVtxIdx1,
                       pVtx + (ushort)pTri->mVtxIdx2,&pChk->mPos);
                    /* ChkPolyThrough */
    if (((uVar1 & 0xff) != 0) &&
       (cVar3 = (**(code **)(this->vtbl + 0x18))(this,idx,(pChk->parent).mpPolyPassChk),
       cVar3 == '\0')) {
      pChk->mRetY = (float)dVar5;
      (pChk->mPolyInfo).mTriIdx = idx;
      uVar2 = 1;
      goto LAB_80248a98;
    }
  }
  uVar2 = 0;
LAB_80248a98:
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall cBgW::RwgGroundCheckGnd(unsigned short,
                                      cBgS_GndChk *) */

undefined4 __thiscall cBgW::RwgGroundCheckGnd(cBgW *this,ushort param_1,cBgS_GndChk *pChk)

{
  cBgW_TriElm *pTri;
  char cVar1;
  undefined4 uVar2;
  cBgW_RwgElm *pRwg;
  
  uVar2 = 0;
  do {
    pRwg = this->mpRwg;
    pTri = this->mpTriElm + param_1;
    cVar1 = RwgGroundCheckCommon
                      (this,((-(pTri->mPlane).mNorm.x * (pChk->mPos).x -
                             (pTri->mPlane).mNorm.z * (pChk->mPos).z) - (pTri->mPlane).mDist) /
                            (pTri->mPlane).mNorm.y,param_1,pChk);
    if (cVar1 != '\0') {
      uVar2 = 1;
    }
    param_1 = pRwg[param_1].mNext;
  } while (param_1 != 0xffff);
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x80248c18) */
/* __thiscall cBgW::RwgGroundCheckWall(unsigned short,
                                       cBgS_GndChk *) */

undefined4 __thiscall cBgW::RwgGroundCheckWall(cBgW *this,ushort param_1,cBgS_GndChk *param_2)

{
  cBgW_TriElm *pTri;
  char cVar1;
  undefined4 uVar2;
  cBgW_RwgElm *pRwg;
  undefined4 uVar3;
  double normY;
  undefined8 in_f31;
  double 0_014;
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  uVar2 = 0;
  0_014 = (double)SComponent::0_014;
  do {
    pTri = this->mpTriElm + param_1;
    pRwg = this->mpRwg;
    normY = (double)(pTri->mPlane).mNorm.y;
    if ((0_014 <= normY) &&
       (cVar1 = RwgGroundCheckCommon
                          (this,(float)((double)((-(pTri->mPlane).mNorm.x * (param_2->mPos).x -
                                                 (pTri->mPlane).mNorm.z * (param_2->mPos).z) -
                                                (pTri->mPlane).mDist) / normY),param_1,param_2),
       cVar1 != '\0')) {
      uVar2 = 1;
    }
    param_1 = pRwg[param_1].mNext;
  } while (param_1 != 0xffff);
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall cBgW::GroundCrossRp(cBgS_GndChk *,
                                  int) */

undefined4 __thiscall cBgW::GroundCrossRp(cBgW *this,cBgS_GndChk *param_1,int param_2)

{
  ushort uVar1;
  bool bVar2;
  char cVar3;
  cBgW_NodeTree *pNd;
  uint uVar4;
  cBgD__Tree_t *pTreeTbl;
  undefined4 ret;
  float posN;
  
  ret = 0;
  pTreeTbl = this->mpBgDt->mpNodeTreeTbl + param_2;
  if ((pTreeTbl->mFlag & 1) == 0) {
    uVar4 = (uint)pTreeTbl->mChild2;
    if (uVar4 != 0xffff) {
      pNd = this->mpNodeTree + uVar4;
      posN = (param_1->mPos).x;
      if (((posN < (pNd->mMin).x) || ((pNd->mMax).x < posN)) ||
         ((posN = (param_1->mPos).z, posN < (pNd->mMin).z || ((pNd->mMax).z < posN)))) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if ((((bVar2) && ((pNd->mMin).y < (param_1->mPos).y)) && (param_1->mRetY <= (pNd->mMax).y)) &&
         (cVar3 = GroundCrossRp(this,param_1,uVar4), cVar3 != '\0')) {
        ret = 1;
      }
    }
    uVar4 = (uint)pTreeTbl->mChild3;
    if (uVar4 != 0xffff) {
      pNd = this->mpNodeTree + uVar4;
      posN = (param_1->mPos).x;
      if (((posN < (pNd->mMin).x) || ((pNd->mMax).x < posN)) ||
         ((posN = (param_1->mPos).z, posN < (pNd->mMin).z || ((pNd->mMax).z < posN)))) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if (((bVar2) && ((pNd->mMin).y < (param_1->mPos).y)) &&
         ((param_1->mRetY <= (pNd->mMax).y &&
          (cVar3 = GroundCrossRp(this,param_1,uVar4), cVar3 != '\0')))) {
        ret = 1;
      }
    }
    uVar4 = (uint)pTreeTbl->mChild6;
    if (uVar4 != 0xffff) {
      pNd = this->mpNodeTree + uVar4;
      posN = (param_1->mPos).x;
      if ((((posN < (pNd->mMin).x) || ((pNd->mMax).x < posN)) ||
          (posN = (param_1->mPos).z, posN < (pNd->mMin).z)) || ((pNd->mMax).z < posN)) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if (((bVar2) && ((pNd->mMin).y < (param_1->mPos).y)) &&
         ((param_1->mRetY <= (pNd->mMax).y &&
          (cVar3 = GroundCrossRp(this,param_1,uVar4), cVar3 != '\0')))) {
        ret = 1;
      }
    }
    uVar4 = (uint)pTreeTbl->mChild7;
    if (uVar4 != 0xffff) {
      pNd = this->mpNodeTree + uVar4;
      posN = (param_1->mPos).x;
      if (((posN < (pNd->mMin).x) || ((pNd->mMax).x < posN)) ||
         ((posN = (param_1->mPos).z, posN < (pNd->mMin).z || ((pNd->mMax).z < posN)))) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if ((((bVar2) && ((pNd->mMin).y < (param_1->mPos).y)) && (param_1->mRetY <= (pNd->mMax).y)) &&
         (cVar3 = GroundCrossRp(this,param_1,uVar4), cVar3 != '\0')) {
        ret = 1;
      }
    }
    uVar4 = (uint)pTreeTbl->mChild0;
    if (uVar4 != 0xffff) {
      pNd = this->mpNodeTree + uVar4;
      posN = (param_1->mPos).x;
      if (((posN < (pNd->mMin).x) || ((pNd->mMax).x < posN)) ||
         ((posN = (param_1->mPos).z, posN < (pNd->mMin).z || ((pNd->mMax).z < posN)))) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if (((bVar2) && ((pNd->mMin).y < (param_1->mPos).y)) &&
         ((param_1->mRetY <= (pNd->mMax).y &&
          (cVar3 = GroundCrossRp(this,param_1,uVar4), cVar3 != '\0')))) {
        ret = 1;
      }
    }
    uVar4 = (uint)pTreeTbl->mChild1;
    if (uVar4 != 0xffff) {
      pNd = this->mpNodeTree + uVar4;
      posN = (param_1->mPos).x;
      if ((((posN < (pNd->mMin).x) || ((pNd->mMax).x < posN)) ||
          (posN = (param_1->mPos).z, posN < (pNd->mMin).z)) || ((pNd->mMax).z < posN)) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if (((bVar2) && ((pNd->mMin).y < (param_1->mPos).y)) &&
         ((param_1->mRetY <= (pNd->mMax).y &&
          (cVar3 = GroundCrossRp(this,param_1,uVar4), cVar3 != '\0')))) {
        ret = 1;
      }
    }
    uVar4 = (uint)pTreeTbl->mChild4;
    if (uVar4 != 0xffff) {
      pNd = this->mpNodeTree + uVar4;
      posN = (param_1->mPos).x;
      if (((posN < (pNd->mMin).x) || ((pNd->mMax).x < posN)) ||
         ((posN = (param_1->mPos).z, posN < (pNd->mMin).z || ((pNd->mMax).z < posN)))) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if ((((bVar2) && ((pNd->mMin).y < (param_1->mPos).y)) && (param_1->mRetY <= (pNd->mMax).y)) &&
         (cVar3 = GroundCrossRp(this,param_1,uVar4), cVar3 != '\0')) {
        ret = 1;
      }
    }
    uVar4 = (uint)pTreeTbl->mChild5;
    if (uVar4 != 0xffff) {
      pNd = this->mpNodeTree + uVar4;
      posN = (param_1->mPos).x;
      if (((posN < (pNd->mMin).x) || ((pNd->mMax).x < posN)) ||
         ((posN = (param_1->mPos).z, posN < (pNd->mMin).z || ((pNd->mMax).z < posN)))) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if (((bVar2) && ((pNd->mMin).y < (param_1->mPos).y)) &&
         ((param_1->mRetY <= (pNd->mMax).y &&
          (cVar3 = GroundCrossRp(this,param_1,uVar4), cVar3 != '\0')))) {
        ret = 1;
      }
    }
  }
  else {
    if (((param_1->mbChkGnd != 0) &&
        (uVar1 = this->mpBlk[pTreeTbl->mChild0].mGroundIdx, uVar1 != 0xffff)) &&
       (cVar3 = RwgGroundCheckGnd(this,uVar1,param_1), cVar3 != '\0')) {
      ret = 1;
    }
    if (((param_1->mbChkWall != 0) &&
        (uVar1 = this->mpBlk[pTreeTbl->mChild0].mWallIdx, uVar1 != 0xffff)) &&
       (cVar3 = RwgGroundCheckWall(this,uVar1,param_1), cVar3 != '\0')) {
      ret = 1;
    }
  }
  return ret;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall cBgW::GroundCrossGrpRp(cBgS_GndChk *,
                                     int,
                                     int) */

int __thiscall cBgW::GroundCrossGrpRp(cBgW *this,cBgS_GndChk *pChk,int grpIdx,int depth)

{
  float fVar1;
  ushort uVar2;
  char cVar4;
  int ret;
  cBgW_GrpElm *pGrp;
  uint uVar3;
  uint uVar5;
  bool inXZ;
  
                    /* ChkGrpThrough */
  cVar4 = (**(code **)(this->vtbl + 0x20))(this,grpIdx,(pChk->parent).mpGrpPassChk);
  if (cVar4 == '\0') {
    pGrp = this->mpGrp + grpIdx;
    fVar1 = (pChk->mPos).x;
    if ((((fVar1 < (pGrp->mAabb).mMin.x) || ((pGrp->mAabb).mMax.x < fVar1)) ||
        (fVar1 = (pChk->mPos).z, fVar1 < (pGrp->mAabb).mMin.z)) || ((pGrp->mAabb).mMax.z < fVar1)) {
      inXZ = false;
    }
    else {
      inXZ = true;
    }
    if (((!inXZ) || ((pChk->mPos).y <= (pGrp->mAabb).mMin.y)) ||
       ((pGrp->mAabb).mMax.y < pChk->mRetY)) {
      ret = 0;
    }
    else {
      ret = 0;
      uVar5 = (uint)this->mpBgDt->mpGrpTbl[grpIdx].mTreIdx;
      if ((uVar5 != 0xffff) && (cVar4 = GroundCrossRp(this,pChk,uVar5), cVar4 != '\0')) {
        ret = 1;
      }
      uVar2 = this->mpBgDt->mpGrpTbl[grpIdx].mFirstChild;
      while (uVar5 = (uint)uVar2, uVar5 != 0xffff) {
        uVar3 = GroundCrossGrpRp(this,pChk,uVar5,depth + 1);
        if ((uVar3 & 0xff) != 0) {
          ret = 1;
        }
        uVar2 = this->mpBgDt->mpGrpTbl[uVar5].mNextSibling;
      }
    }
  }
  else {
    ret = 0;
  }
  return ret;
}


/* __thiscall cBgW::CopyOldMtx(void) */

void __thiscall cBgW::CopyOldMtx(cBgW *this)

{
  if (this->mpModelMtx != (MTX34 *)0x0) {
    mtx::PSMTXCopy(&this->mCurMtx,&this->mOldMtx);
    mtx::PSMTXCopy(this->mpModelMtx,&this->mCurMtx);
  }
  return;
}


/* __thiscall cBgW::Move(void) */

void __thiscall cBgW::Move(cBgW *this)

{
  cBgW__Flag cVar1;
  float fVar2;
  float fVar3;
  MTX34 *pMVar4;
  
  cVar1 = this->mFlags;
  if (((cVar1 & Immovable) == 0) && ((cVar1 & MoveBG) != 0)) {
    if ((cVar1 & 2) == 0) {
      if (((((this->mMoveCounter < 0xff) &&
            (pMVar4 = this->mpModelMtx, (this->mCurMtx).m[0] == pMVar4->m[0])) &&
           ((this->mCurMtx).m[1] == pMVar4->m[1])) &&
          (((((this->mCurMtx).m[2] == pMVar4->m[2] && ((this->mCurMtx).m[1][0] == pMVar4->m[1][0]))
            && (((this->mCurMtx).m[1][1] == pMVar4->m[1][1] &&
                (((this->mCurMtx).m[1][2] == pMVar4->m[1][2] &&
                 ((this->mCurMtx).m[2][0] == pMVar4->m[2][0])))))) &&
           ((this->mCurMtx).m[2][1] == pMVar4->m[2][1])))) &&
         ((this->mCurMtx).m[2][2] == pMVar4->m[2][2])) {
        fVar2 = (this->mCurMtx).m[3];
        fVar3 = pMVar4->m[3];
        if (((fVar2 == fVar3) && ((this->mCurMtx).m[1][3] == pMVar4->m[1][3])) &&
           ((this->mCurMtx).m[2][3] == pMVar4->m[2][3])) {
          mtx::PSMTXCopy(pMVar4,&this->mOldMtx);
          if ((this->mIgnorePlaneType & 8) == 0) {
            return;
          }
        }
        else {
          (this->mTransVel).x = fVar3 - fVar2;
          (this->mTransVel).y = this->mpModelMtx->m[1][3] - (this->mCurMtx).m[1][3];
          (this->mTransVel).z = this->mpModelMtx->m[2][3] - (this->mCurMtx).m[2][3];
          this->mbNeedsFullTransform = 0;
        }
      }
      else {
        this->mbNeedsFullTransform = 1;
      }
      if (this->mMoveCounter == 0xff) {
        this->mMoveCounter = 0;
      }
      else {
        this->mMoveCounter = this->mMoveCounter + 1;
      }
      GlobalVtx(this);
    }
    CopyOldMtx(this);
    (**(code **)(this->vtbl + 0x10))(this);
    (**(code **)(this->vtbl + 0x14))(this);
    MakeNodeTree(this);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall cBgW::RwgShdwDraw(int,
                                cBgS_ShdwDraw *) */

void __thiscall cBgW::RwgShdwDraw(cBgW *this,int param_1,cBgS_ShdwDraw *param_2)

{
  char cVar2;
  ulong uVar1;
  cBgD__Tri_t *pcVar3;
  cBgW_RwgElm *pcVar4;
  
  while( true ) {
    pcVar4 = this->mpRwg;
    cVar2 = (**(code **)(this->vtbl + 0x1c))(this,param_1,*(undefined4 *)param_2);
    if (cVar2 == '\0') {
      pcVar3 = this->mpBgDt->mpTriTbl + param_1;
      (**(code **)(param_2 + 1))
                (param_2,this->mpVtxTbl,pcVar3->mVtxIdx0,pcVar3->mVtxIdx1,pcVar3->mVtxIdx2,
                 this->mpTriElm + param_1);
    }
    param_1 = ZEXT24((ushort)pcVar4[param_1].mNext);
    if (param_1 == 0xffff) break;
    if (this->mpBgDt->mTriCount <= param_1) {
      uVar1 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar1,"c_bg_w.cpp",0xbc6,"0 <= index && index < pm_bgd->m_t_num");
      m_Do_printf::OSPanic("c_bg_w.cpp",0xbc6,&DAT_80364dd4);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall cBgW::ShdwDrawRp(cBgS_ShdwDraw *,
                               int) */

void __thiscall cBgW::ShdwDrawRp(cBgW *this,cBgS_ShdwDraw *param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  cBgD__Tree_t *pcVar3;
  
  cVar1 = SComponent::cM3d_Cross_AabAab(this->mpNodeTree + param_2,&param_1->mAab);
  if (cVar1 != '\0') {
    pcVar3 = this->mpBgDt->mpNodeTreeTbl + param_2;
    if ((pcVar3->mFlag & 1) == 0) {
      if (pcVar3->mChild0 != 0xffff) {
        ShdwDrawRp(this,param_1,(uint)pcVar3->mChild0);
      }
      if (pcVar3->mChild1 != 0xffff) {
        ShdwDrawRp(this,param_1,(uint)pcVar3->mChild1);
      }
      if (pcVar3->mChild2 != 0xffff) {
        ShdwDrawRp(this,param_1,(uint)pcVar3->mChild2);
      }
      if (pcVar3->mChild3 != 0xffff) {
        ShdwDrawRp(this,param_1,(uint)pcVar3->mChild3);
      }
      if (pcVar3->mChild4 != 0xffff) {
        ShdwDrawRp(this,param_1,(uint)pcVar3->mChild4);
      }
      if (pcVar3->mChild5 != 0xffff) {
        ShdwDrawRp(this,param_1,(uint)pcVar3->mChild5);
      }
      if (pcVar3->mChild6 != 0xffff) {
        ShdwDrawRp(this,param_1,(uint)pcVar3->mChild6);
      }
      if (pcVar3->mChild7 != 0xffff) {
        ShdwDrawRp(this,param_1,(uint)pcVar3->mChild7);
      }
    }
    else {
      uVar2 = (uint)this->mpBlk[pcVar3->mChild0].mWallIdx;
      if (uVar2 != 0xffff) {
        RwgShdwDraw(this,uVar2,param_1);
      }
      uVar2 = (uint)this->mpBlk[pcVar3->mChild0].mRoofIdx;
      if (uVar2 != 0xffff) {
        RwgShdwDraw(this,uVar2,param_1);
      }
      uVar2 = (uint)this->mpBlk[pcVar3->mChild0].mGroundIdx;
      if (uVar2 != 0xffff) {
        RwgShdwDraw(this,uVar2,param_1);
      }
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall cBgW::ShdwDrawGrpRp(cBgS_ShdwDraw *,
                                  int) */

void __thiscall cBgW::ShdwDrawGrpRp(cBgW *this,cBgS_ShdwDraw *param_1,int param_2)

{
  ushort uVar1;
  char cVar2;
  uint uVar3;
  
  cVar2 = SComponent::cM3d_Cross_AabAab(&this->mpGrp[param_2].mAabb,&param_1->mAab);
  if (cVar2 != '\0') {
    uVar3 = (uint)this->mpBgDt->mpGrpTbl[param_2].mTreIdx;
    if (uVar3 != 0xffff) {
      ShdwDrawRp(this,param_1,uVar3);
    }
    uVar1 = this->mpBgDt->mpGrpTbl[param_2].mFirstChild;
    while (uVar3 = (uint)uVar1, uVar3 != 0xffff) {
      ShdwDrawGrpRp(this,param_1,uVar3);
      uVar1 = this->mpBgDt->mpGrpTbl[uVar3].mNextSibling;
    }
  }
  return;
}


/* __thiscall cBgW::ChkPolyThrough(int,
                                   cBgS_PolyPassChk *) */

undefined4 __thiscall cBgW::ChkPolyThrough(cBgW *this,int param_1,cBgS_PolyPassChk *param_2)

{
  return 0;
}


/* __thiscall cBgW::ChkShdwDrawThrough(int,
                                       cBgS_PolyPassChk *) */

void __thiscall cBgW::ChkShdwDrawThrough(cBgW *this,int param_1,cBgS_PolyPassChk *param_2)

{
  (**(code **)(this->vtbl + 0x18))();
  return;
}


/* __thiscall cBgW::ChkGrpThrough(int,
                                  cBgS_GrpPassChk *,
                                  int) */

undefined4 __thiscall
cBgW::ChkGrpThrough(cBgW *this,int param_1,cBgS_GrpPassChk *param_2,int param_3)

{
  return 0;
}


/* __thiscall cBgW::GetGrpToRoomIndex(int) const */

uint __thiscall cBgW::GetGrpToRoomIndex(cBgW *this,int grp_index)

{
  bool bVar1;
  ulong uVar2;
  uint uVar3;
  cBgD__Grp_t *pGrpTbl;
  
  bVar1 = false;
  if (-1 < grp_index) {
    if (grp_index < this->mpBgDt->mGrpCount) {
      bVar1 = true;
    }
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar2,"c_bg_w.cpp",0xc77,"0 <= grp_index && grp_index < pm_bgd->m_g_num");
    m_Do_printf::OSPanic("c_bg_w.cpp",0xc77,&DAT_80364dd4);
  }
  pGrpTbl = this->mpBgDt->mpGrpTbl;
  if ((pGrpTbl[grp_index].mParent == 0xffff) ||
     (pGrpTbl[pGrpTbl[grp_index].mParent].mParent == 0xffff)) {
    uVar3 = 0xffff;
  }
  else {
    uVar3 = (uint)pGrpTbl[pGrpTbl[pGrpTbl[grp_index].mParent].mParent].mRoomIdx;
  }
  return uVar3;
}


/* __thiscall cBgW::GetTrans(cXyz *) const */

void __thiscall cBgW::GetTrans(cBgW *this,cXyz *param_1)

{
  param_1->x = this->mpModelMtx->m[3] - (this->mOldMtx).m[3];
  param_1->y = this->mpModelMtx->m[1][3] - (this->mOldMtx).m[1][3];
  param_1->z = this->mpModelMtx->m[2][3] - (this->mOldMtx).m[2][3];
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall cBgW::GetTriPnt(int,
                              cXyz *,
                              cXyz *,
                              cXyz *) const */

void __thiscall cBgW::GetTriPnt(cBgW *this,int param_1,cXyz *param_2,cXyz *param_3,cXyz *param_4)

{
  ulong uVar1;
  cXyz *pcVar2;
  cBgD__Tri_t *pcVar3;
  
  if (this->mpBgDt == (cBgD_t *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"c_bg_w.cpp",0xcb3,"pm_bgd != 0");
    m_Do_printf::OSPanic("c_bg_w.cpp",0xcb3,&DAT_80364dd4);
  }
  pcVar3 = this->mpBgDt->mpTriTbl + param_1;
  pcVar2 = this->mpVtxTbl + (ushort)pcVar3->mVtxIdx0;
  param_2->x = pcVar2->x;
  param_2->y = pcVar2->y;
  param_2->z = pcVar2->z;
  pcVar2 = this->mpVtxTbl + (ushort)pcVar3->mVtxIdx1;
  param_3->x = pcVar2->x;
  param_3->y = pcVar2->y;
  param_3->z = pcVar2->z;
  pcVar2 = this->mpVtxTbl + (ushort)pcVar3->mVtxIdx2;
  param_4->x = pcVar2->x;
  param_4->y = pcVar2->y;
  param_4->z = pcVar2->z;
  return;
}


/* __thiscall cBgW::GetTopUnder(float *,
                                float *) const */

void __thiscall cBgW::GetTopUnder(cBgW *this,float *param_1,float *param_2)

{
  *param_2 = this->mpGrp[this->mRootGrpIdx].mAabb.mMin.y;
  *param_1 = this->mpGrp[this->mRootGrpIdx].mAabb.mMax.y;
  return;
}


/* __thiscall cBgW_BgId::~cBgW_BgId(void) */

void __thiscall cBgW_BgId::_cBgW_BgId(cBgW_BgId *this)

{
  short in_r4;
  
  if ((this != (cBgW_BgId *)0x0) && (*(undefined ***)(this + 4) = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall cBgW_GrpElm::~cBgW_GrpElm(void) */

void __thiscall cBgW_GrpElm::_cBgW_GrpElm(cBgW_GrpElm *this)

{
  short in_r4;
  
  if (this != (cBgW_GrpElm *)0x0) {
    this->field_0x0 = &__vt;
    if (this != (cBgW_GrpElm *)0xfffffffc) {
      (this->mAabb).vtbl = &::cM3dGAab::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall cBgW_GrpElm::cBgW_GrpElm(void) */

void __thiscall cBgW_GrpElm::cBgW_GrpElm(cBgW_GrpElm *this)

{
  this->field_0x0 = &__vt;
  (this->mAabb).vtbl = &::cM3dGAab::__vt;
  return;
}


/* __thiscall cBgW_NodeTree::~cBgW_NodeTree(void) */

void __thiscall cBgW_NodeTree::_cBgW_NodeTree(cBgW_NodeTree *this)

{
  short in_r4;
  
  if (this != (cBgW_NodeTree *)0x0) {
    this->field_0x18 = &__vt;
    if (this != (cBgW_NodeTree *)0x0) {
      this->field_0x18 = &::cM3dGAab::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall cBgW_NodeTree::cBgW_NodeTree(void) */

void __thiscall cBgW_NodeTree::cBgW_NodeTree(cBgW_NodeTree *this)

{
  this->field_0x18 = &::cM3dGAab::__vt;
  this->field_0x18 = &__vt;
  return;
}


/* __thiscall cBgW_RwgElm::~cBgW_RwgElm(void) */

void __thiscall cBgW_RwgElm::_cBgW_RwgElm(cBgW_RwgElm *this)

{
  short in_r4;
  
  if ((this != (cBgW_RwgElm *)0x0) && (this->vtbl = (undefined *)&__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall cBgW_RwgElm::cBgW_RwgElm(void) */

void __thiscall cBgW_RwgElm::cBgW_RwgElm(cBgW_RwgElm *this)

{
  this->vtbl = (undefined *)&__vt;
  return;
}


/* __thiscall cBgW_TriElm::~cBgW_TriElm(void) */

void __thiscall cBgW_TriElm::_cBgW_TriElm(cBgW_TriElm *this)

{
  short in_r4;
  
  if (this != (cBgW_TriElm *)0x0) {
    this->vtbl = (undefined *)&__vt;
    if (this != (cBgW_TriElm *)0x0) {
      (this->mPlane).vtbl = (undefined *)&cM3dGPla::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall cBgW_TriElm::cBgW_TriElm(void) */

void __thiscall cBgW_TriElm::cBgW_TriElm(cBgW_TriElm *this)

{
  this->vtbl = (undefined *)&__vt;
  (this->mPlane).vtbl = (undefined *)&cM3dGPla::__vt;
  return;
}

