#include <SComponent/c_bg_s.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <SComponent/c_bg_w.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <SComponent/c_bg_s.h>
#include <SComponent/c_bg_s_chk.h>
#include <cBgS_ChkElm.h>
#include <cBgS.h>


namespace SComponent {
undefined4 l_SetCounter;
}

/* __thiscall cBgS_ChkElm::Init(void) */

void __thiscall cBgS_ChkElm::Init(cBgS_ChkElm *this)

{
  this->mpBgW = (dBgW *)0x0;
  this->mFlags = 0;
  this->mpActorPtr = (fopAc_ac_c *)0x0;
  this->mProcID = -1;
  return;
}


/* __thiscall cBgS_ChkElm::Regist2(cBgW *,
                                   unsigned int,
                                   void *) */

void __thiscall cBgS_ChkElm::Regist2(cBgS_ChkElm *this,cBgW *pBgW,uint procID,void *pActor)

{
  this->mFlags = this->mFlags | 1;
  this->mpBgW = (dBgW *)pBgW;
  this->mProcID = procID;
  this->mpActorPtr = (fopAc_ac_c *)pActor;
  return;
}


/* __thiscall cBgS_ChkElm::Release(void) */

void __thiscall cBgS_ChkElm::Release(cBgS_ChkElm *this)

{
  this->mFlags = this->mFlags & 0xfffffffe;
  this->mpBgW = (dBgW *)0x0;
  this->mProcID = -1;
  this->mpActorPtr = (fopAc_ac_c *)0x0;
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall cBgS::Regist(cBgW *,
                           unsigned int,
                           void *) */

int __thiscall cBgS::Regist(cBgS *this,cBgW *pBgW,uint procID,void *pActor)

{
  bool bVar1;
  char cVar3;
  ulong uVar2;
  cBgS_ChkElm *pElm;
  uint uVar4;
  
  if (pBgW != (cBgW *)0x0) {
    if (((int)pBgW->mCount < 0) || (0xff < (int)pBgW->mCount)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if ((!bVar1) &&
       (cVar3 = cBgW::ChkMemoryError(pBgW), uVar4 = SComponent::l_SetCounter, cVar3 == '\0')) {
      bVar1 = false;
      if ((-1 < (int)SComponent::l_SetCounter) && ((int)SComponent::l_SetCounter < 0x100)) {
        bVar1 = true;
      }
      if (!bVar1) {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar2,"c_bg_s.cpp",0x97,"0 <= i && i < 256");
        m_Do_printf::OSPanic("c_bg_s.cpp",0x97,&DAT_80364a25);
      }
      do {
        pElm = this->mChkElm + uVar4;
        if ((pElm->mFlags & 1U) == 0) {
          (**(code **)(pElm->vtbl + 0xc))(pElm,pBgW,procID,pActor);
          pBgW->mCount = uVar4;
          SComponent::l_SetCounter = uVar4 + 1;
          if (0xff < (int)SComponent::l_SetCounter) {
            SComponent::l_SetCounter = 0;
          }
          return 0;
        }
        uVar4 = uVar4 + 1;
        if (0xff < (int)uVar4) {
          uVar4 = 0;
        }
      } while (SComponent::l_SetCounter != uVar4);
      pBgW->mCount = 0x100;
    }
  }
  return 1;
}


/* __thiscall cBgS::Release(cBgW *) */

undefined4 __thiscall cBgS::Release(cBgS *this,cBgW *param_1)

{
  bool bVar1;
  uint uVar2;
  
  if (param_1 != (cBgW *)0x0) {
    uVar2 = param_1->mCount;
    if (((int)uVar2 < 0) || (0xff < (int)uVar2)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if ((((bVar1) && (-1 < (int)uVar2)) && ((int)uVar2 < 0x100)) &&
       ((this->mChkElm[uVar2].mFlags & 1U) != 0)) {
      cBgS_ChkElm::Release(this->mChkElm + uVar2);
      param_1->mCount = 0x100;
      return 0;
    }
  }
  return 1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall cBgS::Ct(void) */

void __thiscall cBgS::Ct(cBgS *this)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  SComponent::l_SetCounter = 0;
  iVar1 = 0;
  do {
    cBgS_ChkElm::Init((cBgS_ChkElm *)((int)&this->mChkElm[0].mpBgW + iVar2));
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x14;
  } while (iVar1 < 0x100);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall cBgS::Dt(void) */

void __thiscall cBgS::Dt(cBgS *this)

{
  cBgS_ChkElm *this_00;
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 0;
  do {
    this_00 = (cBgS_ChkElm *)((int)&this->mChkElm[0].mpBgW + iVar2);
    if ((this_00->mFlags & 1U) != 0) {
      cBgS_ChkElm::Release(this_00);
    }
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x14;
  } while (iVar1 < 0x100);
  iVar1 = 0;
  iVar2 = 0;
  do {
    cBgS_ChkElm::Init((cBgS_ChkElm *)((int)&this->mChkElm[0].mpBgW + iVar2));
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x14;
  } while (iVar1 < 0x100);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall cBgS::LineCross(cBgS_LinChk *) */

int __thiscall cBgS::LineCross(cBgS *this,cBgS_LinChk *pChk)

{
  uint uVar1;
  bool bVar3;
  ulong uVar2;
  cBgS_ChkElm *pChkElm;
  dBgW *pdVar4;
  int bg_index;
  int iVar5;
  int iVar6;
  
  iVar5 = 0;
  (pChk->mPolyInfo).mTriIdx = -1;
  (pChk->mPolyInfo).mBgIndex = 0x100;
  iVar6 = 0;
  (pChk->mPolyInfo).mpBgW = (cBgW *)0x0;
  (pChk->mPolyInfo).mProcID = -1;
  pChk->mFlags = pChk->mFlags & 0xffffffef;
  bg_index = 0;
  do {
    pChkElm = (cBgS_ChkElm *)((int)&this->mChkElm[0].mpBgW + iVar6);
    if (((pChkElm->mFlags & 1U) != 0) && ((pChkElm->mpBgW->parent).mpVtxTbl != (cXyz *)0x0)) {
      bVar3 = cBgS_Chk::ChkSameActorPid(&pChk->parent,pChkElm->mProcID);
      if (bVar3 == false) {
        uVar1 = countLeadingZeros(pChk->mFlags & 0x40000000);
        pChk->field_0x50 = (byte)(uVar1 >> 5);
        uVar1 = countLeadingZeros(pChk->mFlags & 0x80000000);
        pChk->field_0x51 = (byte)(uVar1 >> 5);
        uVar1 = countLeadingZeros(pChk->mFlags & 0x20000000);
        pChk->field_0x52 = (byte)(uVar1 >> 5);
        uVar1 = cBgW::LineCheckGrpRp(&pChkElm->mpBgW->parent,pChk,*(int *)&pChkElm->mpBgW->parent,1)
        ;
        if ((uVar1 & 0xff) != 0) {
          iVar5 = pChkElm->mProcID;
          pdVar4 = pChkElm->mpBgW;
          if (bg_index < 0) {
            uVar2 = JUTAssertion::getSDevice();
            JUTAssertion::showAssert(uVar2,"c_bg_s_poly_info.h",0x59,"0 <= bg_index");
            m_Do_printf::OSPanic("c_bg_s_poly_info.h",0x59,&DAT_80364a25);
          }
          (pChk->mPolyInfo).mBgIndex = (short)bg_index;
          (pChk->mPolyInfo).mpBgW = &pdVar4->parent;
          (pChk->mPolyInfo).mProcID = iVar5;
          iVar5 = 1;
        }
      }
    }
    bg_index = bg_index + 1;
    iVar6 = iVar6 + 0x14;
  } while (bg_index < 0x100);
  if (iVar5 != 0) {
    pChk->mFlags = pChk->mFlags | 0x10;
  }
  return iVar5;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall cBgS::GroundCross(cBgS_GndChk *) */

double __thiscall cBgS::GroundCross(cBgS *this,cBgS_GndChk *pChk)

{
  bool bVar3;
  dBgW *pBgW;
  uint uVar1;
  ulong uVar2;
  int bg_index;
  int iVar4;
  
  pChk->mRetY = SComponent::_1_0E9;
  (pChk->mPolyInfo).mTriIdx = -1;
  (pChk->mPolyInfo).mBgIndex = 0x100;
  (pChk->mPolyInfo).mpBgW = (cBgW *)0x0;
  (pChk->mPolyInfo).mProcID = -1;
  pChk->mbChkWall = pChk->mFlagIn & 2;
  pChk->mbChkGnd = pChk->mFlagIn & 1;
  bg_index = 0;
  do {
    if (((this->mChkElm[0].mFlags & 1U) != 0) &&
       (((this->mChkElm[0].mpBgW)->parent).mpVtxTbl != (cXyz *)0x0)) {
      bVar3 = cBgS_Chk::ChkSameActorPid(&pChk->parent,this->mChkElm[0].mProcID);
      if ((bVar3 == false) &&
         (pBgW = this->mChkElm[0].mpBgW,
         uVar1 = cBgW::GroundCrossGrpRp(&pBgW->parent,pChk,*(int *)&pBgW->parent,1),
         (uVar1 & 0xff) != 0)) {
        iVar4 = this->mChkElm[0].mProcID;
        pBgW = this->mChkElm[0].mpBgW;
        if (bg_index < 0) {
          uVar2 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar2,"c_bg_s_poly_info.h",0x59,"0 <= bg_index");
          m_Do_printf::OSPanic("c_bg_s_poly_info.h",0x59,&DAT_80364a25);
        }
        (pChk->mPolyInfo).mBgIndex = (short)bg_index;
        (pChk->mPolyInfo).mpBgW = &pBgW->parent;
        (pChk->mPolyInfo).mProcID = iVar4;
      }
    }
    bg_index = bg_index + 1;
    this = (cBgS *)(this->mChkElm + 1);
  } while (bg_index < 0x100);
  return (double)pChk->mRetY;
}


namespace cBgS {

/* __thiscall ConvDzb(void *) */

cBgD_t * ConvDzb(cBgD_t *pDt)

{
  uint uVar1;
  ulong uVar2;
  int iVar3;
  int iVar4;
  
  if ((pDt->mFlags & 0x80000000U) == 0) {
    pDt->mFlags = pDt->mFlags | 0x80000000;
    uVar1 = (int)pDt->mpVtxTbl >> 0x1f;
    if ((uVar1 * 4 | (int)pDt->mpVtxTbl * 0x40000000 + uVar1 >> 0x1e) != uVar1) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"c_bg_s.cpp",0x214,"((int)pbgd->m_v_tbl % 4) == 0");
      m_Do_printf::OSPanic("c_bg_s.cpp",0x214,&DAT_80364a25);
    }
    uVar1 = (uint)pDt->mpTriTbl >> 0x1f;
    if (((uint)pDt->mpTriTbl & 1 ^ uVar1) != uVar1) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"c_bg_s.cpp",0x215,"((int)pbgd->m_t_tbl % 2) == 0");
      m_Do_printf::OSPanic("c_bg_s.cpp",0x215,&DAT_80364a25);
    }
    uVar1 = (uint)pDt->mpBlkTbl >> 0x1f;
    if (((uint)pDt->mpBlkTbl & 1 ^ uVar1) != uVar1) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"c_bg_s.cpp",0x216,"((int)pbgd->m_b_tbl % 2) == 0");
      m_Do_printf::OSPanic("c_bg_s.cpp",0x216,&DAT_80364a25);
    }
    uVar1 = (uint)pDt->mpNodeTreeTbl >> 0x1f;
    if (((uint)pDt->mpNodeTreeTbl & 1 ^ uVar1) != uVar1) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"c_bg_s.cpp",0x217,"((int)pbgd->m_tree_tbl % 2) == 0");
      m_Do_printf::OSPanic("c_bg_s.cpp",0x217,&DAT_80364a25);
    }
    uVar1 = (int)pDt->mpGrpTbl >> 0x1f;
    if ((uVar1 * 4 | (int)pDt->mpGrpTbl * 0x40000000 + uVar1 >> 0x1e) != uVar1) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"c_bg_s.cpp",0x218,"((int)pbgd->m_g_tbl % 4) == 0");
      m_Do_printf::OSPanic("c_bg_s.cpp",0x218,&DAT_80364a25);
    }
    uVar1 = (int)pDt->mpTiTbl >> 0x1f;
    if ((uVar1 * 4 | (int)pDt->mpTiTbl * 0x40000000 + uVar1 >> 0x1e) != uVar1) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"c_bg_s.cpp",0x219,"((int)pbgd->m_ti_tbl % 4) == 0");
      m_Do_printf::OSPanic("c_bg_s.cpp",0x219,&DAT_80364a25);
    }
    if (pDt->mpVtxTbl != (cBgD_Vtx_t *)0x0) {
      pDt->mpVtxTbl = (cBgD_Vtx_t *)((int)&pDt->mVtxCount + (int)&pDt->mpVtxTbl->v);
    }
    pDt->mpTriTbl = (cBgD__Tri_t *)((int)&pDt->mVtxCount + (int)&pDt->mpTriTbl->mVtxIdx0);
    pDt->mpBlkTbl = (ushort *)((int)pDt->mpBlkTbl + (int)pDt);
    pDt->mpNodeTreeTbl = (cBgD__Tree_t *)((int)&pDt->mVtxCount + (int)&pDt->mpNodeTreeTbl->mFlag);
    pDt->mpGrpTbl = (cBgD__Grp_t *)((int)&pDt->mVtxCount + (int)&pDt->mpGrpTbl->mpName);
    pDt->mpTiTbl = (cBgD__Ti_t *)((int)&pDt->mVtxCount + (int)&pDt->mpTiTbl->mPolyID0);
    iVar3 = 0;
    for (iVar4 = 0; iVar4 < pDt->mGrpCount; iVar4 = iVar4 + 1) {
      *(int *)((int)&pDt->mpGrpTbl->mpName + iVar3) =
           (int)&pDt->mVtxCount + *(int *)((int)&pDt->mpGrpTbl->mpName + iVar3);
      iVar3 = iVar3 + 0x34;
    }
  }
  return pDt;
}

}

/* __thiscall cBgS::GetActorPointer(int) const */

fopAc_ac_c * __thiscall cBgS::GetActorPointer(cBgS *this,int actor_index)

{
  bool bVar1;
  ulong uVar2;
  
  bVar1 = false;
  if ((-1 < actor_index) && (actor_index < 0x100)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"c_bg_s.cpp",0x237,"0 <= actor_index && actor_index < 256");
    m_Do_printf::OSPanic("c_bg_s.cpp",0x237,&DAT_80364a25);
  }
  return this->mChkElm[actor_index].mpActorPtr;
}


/* __thiscall cBgS::GetBgWPointer(cBgS_PolyInfo &) const */

dBgW * __thiscall cBgS::GetBgWPointer(cBgS *this,cBgS_PolyInfo *param_1)

{
  uint uVar1;
  
  uVar1 = (uint)(ushort)param_1->mBgIndex;
  if ((uVar1 < 0x100) && ((this->mChkElm[uVar1].mFlags & 1U) != 0)) {
    return this->mChkElm[uVar1].mpBgW;
  }
  return (dBgW *)0x0;
}


/* __thiscall cBgS::ChkPolySafe(cBgS_PolyInfo &) */

undefined4 __thiscall cBgS::ChkPolySafe(cBgS *this,cBgS_PolyInfo *pPolyInf)

{
  bool bVar1;
  uint uVar2;
  
  if ((pPolyInf->mTriIdx == -1) || (pPolyInf->mBgIndex == 0x100)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (!bVar1) {
    return 0;
  }
  uVar2 = (uint)(ushort)pPolyInf->mBgIndex;
  if (0xff < uVar2) {
    return 0;
  }
  if ((this->mChkElm[uVar2].mFlags & 1U) != 0) {
    if (((dBgW *)pPolyInf->mpBgW == this->mChkElm[uVar2].mpBgW) &&
       (pPolyInf->mProcID == this->mChkElm[uVar2].mProcID)) {
      return 1;
    }
    return 0;
  }
  return 0;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall cBgS::GetTriGrp(int,
                              int) const */

uint __thiscall cBgS::GetTriGrp(cBgS *this,int bg_index,int poly_index)

{
  bool bVar1;
  ulong uVar2;
  uint uVar3;
  dBgW *pdVar4;
  
  bVar1 = false;
  if ((-1 < bg_index) && (bg_index < 0x100)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"c_bg_s.cpp",0x278,"0 <= bg_index && bg_index < 256");
    m_Do_printf::OSPanic("c_bg_s.cpp",0x278,&DAT_80364a25);
  }
  if ((this->mChkElm[bg_index].mFlags & 1U) == 0) {
    uVar3 = 0xffffffff;
  }
  else {
    pdVar4 = this->mChkElm[bg_index].mpBgW;
    bVar1 = false;
    if (-1 < poly_index) {
      if (poly_index < ((pdVar4->parent).mpBgDt)->mTriCount) {
        bVar1 = true;
      }
    }
    if (!bVar1) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert
                (uVar2,"c_bg_w.h",0x2a2,"0 <= poly_index && poly_index < pm_bgd->m_t_num");
      m_Do_printf::OSPanic("c_bg_w.h",0x2a2,&DAT_80364a25);
    }
    uVar3 = (uint)(ushort)((pdVar4->parent).mpBgDt)->mpTriTbl[poly_index].mGrpIdx;
  }
  return uVar3;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall cBgS::GetGrpToRoomId(int,
                                   int) const */

undefined4 __thiscall cBgS::GetGrpToRoomId(cBgS *this,int bg_index,int grp)

{
  bool bVar1;
  ulong uVar2;
  undefined4 uVar3;
  dBgW *pdVar4;
  
  bVar1 = false;
  if ((-1 < bg_index) && (bg_index < 0x100)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"c_bg_s.cpp",0x289,"0 <= bg_index && bg_index < 256");
    m_Do_printf::OSPanic("c_bg_s.cpp",0x289,&DAT_80364a25);
  }
  if ((this->mChkElm[bg_index].mFlags & 1U) == 0) {
    uVar3 = 0xffff;
  }
  else {
    if (grp == 0xffff) {
      uVar3 = 0xffff;
    }
    else {
      pdVar4 = this->mChkElm[bg_index].mpBgW;
      uVar3 = (**(code **)((pdVar4->parent).vtbl + 0xc))(pdVar4,grp);
    }
  }
  return uVar3;
}


/* __thiscall cBgS::GetTriPla(int,
                              int) const */

cM3dGPla * __thiscall cBgS::GetTriPla(cBgS *this,int bg_index,int poly_index)

{
  bool bVar1;
  ulong uVar2;
  dBgW *pdVar3;
  
  if ((-1 < bg_index) && (bg_index < 0x100)) {
    if ((this->mChkElm[bg_index].mFlags & 1U) == 0) {
      return &((cBgW_TriElm *)0x0)->mPlane;
    }
    pdVar3 = this->mChkElm[bg_index].mpBgW;
    bVar1 = false;
    if ((-1 < poly_index) && (poly_index < ((pdVar3->parent).mpBgDt)->mTriCount)) {
      bVar1 = true;
    }
    if (!bVar1) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert
                (uVar2,"c_bg_w.h",0x2af,"0 <= poly_index && poly_index < pm_bgd->m_t_num");
      m_Do_printf::OSPanic("c_bg_w.h",0x2af,&DAT_80364a25);
    }
    return &((pdVar3->parent).mpTriElm + poly_index)->mPlane;
  }
  return &((cBgW_TriElm *)0x0)->mPlane;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall cBgS::GetTriPnt(cBgS_PolyInfo &,
                              cXyz *,
                              cXyz *,
                              cXyz *) const */

void __thiscall
cBgS::GetTriPnt(cBgS *this,cBgS_PolyInfo *param_1,cXyz *param_2,cXyz *param_3,cXyz *param_4)

{
  ulong uVar1;
  uint uVar2;
  
  uVar2 = (uint)(ushort)param_1->mBgIndex;
  if (0xff < uVar2) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"c_bg_s.cpp",0x2f6,"0 <= id && id < 256");
    m_Do_printf::OSPanic("c_bg_s.cpp",0x2f6,&DAT_80364a25);
  }
  if ((this->mChkElm[uVar2].mFlags & 1U) != 0) {
    cBgW::GetTriPnt(&(this->mChkElm[uVar2].mpBgW)->parent,(uint)(ushort)param_1->mTriIdx,param_2,
                    param_3,param_4);
  }
  return;
}


/* __thiscall cBgS::Move(void) */

void __thiscall cBgS::Move(cBgS *this)

{
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall cBgS::ShdwDraw(cBgS_ShdwDraw *) */

void __thiscall cBgS::ShdwDraw(cBgS *this,cBgS_ShdwDraw *param_1)

{
  cBgS_ChkElm *pChk;
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 0;
  do {
    pChk = (cBgS_ChkElm *)((int)&this->mChkElm[0].mpBgW + iVar2);
    if ((pChk->mFlags & 1U) != 0) {
      cBgW::ShdwDrawGrpRp(&pChk->mpBgW->parent,param_1,*(int *)&pChk->mpBgW->parent);
    }
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x14;
  } while (iVar1 < 0x100);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall cBgS::GetGrpInf(cBgS_PolyInfo &,
                              int) const */

uint __thiscall cBgS::GetGrpInf(cBgS *this,cBgS_PolyInfo *poly_info,int grp_id)

{
  bool bVar1;
  ulong uVar2;
  uint uVar3;
  dBgW *pdVar4;
  
  uVar3 = (uint)(ushort)poly_info->mBgIndex;
  if (0xff < uVar3) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"c_bg_s.cpp",0x37d,"0 <= bg_index && bg_index < 256");
    m_Do_printf::OSPanic("c_bg_s.cpp",0x37d,&DAT_80364a25);
  }
  if ((this->mChkElm[uVar3].mFlags & 1U) == 0) {
    uVar3 = 0xffffffff;
  }
  else {
    pdVar4 = this->mChkElm[uVar3].mpBgW;
    bVar1 = false;
    if ((-1 < grp_id) && (grp_id < ((pdVar4->parent).mpBgDt)->mGrpCount)) {
      bVar1 = true;
    }
    if (!bVar1) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"c_bg_w.h",0x2e1,"0 <= grp_id && grp_id < pm_bgd->m_g_num");
      m_Do_printf::OSPanic("c_bg_w.h",0x2e1,&DAT_80364a25);
    }
    uVar3 = ((pdVar4->parent).mpBgDt)->mpGrpTbl[grp_id].mAttr;
  }
  return uVar3;
}

