#include <d_bg_s.h>
#include <SComponent/c_bg_s.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <d_bg_s.h>
#include <SComponent/c_bg_s_chk.h>
#include <SComponent/c_bg_w.h>
#include <d_bg_s_acch.h>
#include <d_bg_w.h>
#include <d_bg_s_spl_grp_chk.h>
#include <SComponent/c_m3d_g_cyl.h>
#include <mtx/mtx.h>
#include <mtx/mtxvec.h>
#include <mtx/vec.h>
#include <SComponent/c_bg_s_lin_chk.h>
#include <Demangler/dBgS_CrrPos.h>
#include <dBgW.h>
#include <dBgS.h>


/* __thiscall dBgS::Ct(void) */

void __thiscall dBgS::Ct(dBgS *this)

{
  cBgS::Ct(&this->parent);
  return;
}


/* __thiscall dBgS::Dt(void) */

void __thiscall dBgS::Dt(dBgS *this)

{
  cBgS::Dt(&this->parent);
  return;
}


/* __thiscall dBgS::ClrMoveFlag(void) */

void __thiscall dBgS::ClrMoveFlag(dBgS *this)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = 0;
  iVar4 = 0x100;
  do {
    piVar2 = (int *)((int)&(this->parent).mChkElm[0].mpBgW + iVar1);
    if ((piVar2[1] & 1U) != 0) {
      iVar3 = *piVar2;
      *(byte *)(iVar3 + 0xba) = *(byte *)(iVar3 + 0xba) & 0xfe;
    }
    iVar1 = iVar1 + 0x14;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return;
}


/* __thiscall dBgS::Move(void) */

void __thiscall dBgS::Move(dBgS *this)

{
  short sVar1;
  int iVar2;
  cBgS_ChkElm *pElm;
  dBgW *pdVar3;
  int iVar4;
  
  cBgS::Move(&this->parent);
  iVar2 = 0;
  iVar4 = 0x100;
  do {
    pElm = (cBgS_ChkElm *)((int)&(this->parent).mChkElm[0].mpBgW + iVar2);
    if ((pElm->mFlags & 1U) != 0) {
      pdVar3 = pElm->mpBgW;
      sVar1 = (pElm->mpActorPtr->mCollisionRot).y;
      pdVar3->mRotYDelta = sVar1 - pdVar3->mOldRotY;
      pdVar3->mOldRotY = sVar1;
    }
    iVar2 = iVar2 + 0x14;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return;
}


/* __thiscall dBgS::Regist(cBgW *,
                           fopAc_ac_c *) */

int __thiscall dBgS::Regist(dBgS *this,dBgW *pBgW,fopAc_ac_c *pActor)

{
  int iVar1;
  uint procID;
  
  if (pBgW == (dBgW *)0x0) {
    iVar1 = 1;
  }
  else {
    if ((pActor != (fopAc_ac_c *)0x0) && (((pBgW->parent).mFlags & MoveBG) != 0)) {
      pBgW->mOldRotY = (pActor->mCollisionRot).y;
      pBgW->mRoomNo = (short)(char)(pActor->mCurrent).mRoomNo;
    }
    if (pActor == (fopAc_ac_c *)0x0) {
      procID = 0xffffffff;
    }
    else {
      procID = (pActor->parent).parent.mBsPcId;
    }
    iVar1 = cBgS::Regist(&this->parent,&pBgW->parent,procID,pActor);
  }
  return iVar1;
}


/* __thiscall dBgS::ChkMoveBG(cBgS_PolyInfo &) */

undefined4 __thiscall dBgS::ChkMoveBG(dBgS *this,cBgS_PolyInfo *param_1)

{
  cBgW__Flag cVar1;
  dBgW *pdVar2;
  
  pdVar2 = cBgS::GetBgWPointer((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,param_1);
  if (pdVar2 != (dBgW *)0x0) {
    cVar1 = (pdVar2->parent).mFlags;
    if ((cVar1 & Immovable) != 0) {
      return 0;
    }
    if ((cVar1 & MoveBG) != 0) {
      return 1;
    }
  }
  return 0;
}


/* __thiscall dBgS::ChkMoveBG_NoDABg(cBgS_PolyInfo &) */

undefined4 __thiscall dBgS::ChkMoveBG_NoDABg(dBgS *this,cBgS_PolyInfo *param_1)

{
  dBgW *pdVar1;
  undefined4 uVar2;
  
  pdVar1 = cBgS::GetBgWPointer((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,param_1);
  if ((pdVar1 == (dBgW *)0x0) || (((pdVar1->parent).mFlags & MoveBG) == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall dBgS::GetPolyId0(int,
                               int,
                               int,
                               unsigned long,
                               unsigned long) */

int __thiscall
dBgS::GetPolyId0(dBgS *this,int param_1,int param_2,int param_3,ulong param_4,ulong param_5)

{
  bool bVar1;
  ulong uVar2;
  cBgD_t *pcVar3;
  uint uVar4;
  dBgW *pdVar5;
  
  bVar1 = false;
  if ((-1 < param_1) && (param_1 < 0x100)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_bg_s.cpp",0x349,"0 <= bg_index && bg_index < 256");
    m_Do_printf::OSPanic("d_bg_s.cpp",0x349,"Halt");
  }
  if (((this->parent).mChkElm[param_1].mFlags & 1U) != 0) {
    pdVar5 = (this->parent).mChkElm[param_1].mpBgW;
    bVar1 = false;
    if ((-1 < param_2) && (param_2 < ((pdVar5->parent).mpBgDt)->mTriCount)) {
      bVar1 = true;
    }
    if (!bVar1) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert
                (uVar2,"c_bg_w.h",0x2f1,"0 <= poly_index && poly_index < pm_bgd->m_t_num");
      m_Do_printf::OSPanic("c_bg_w.h",0x2f1,"Halt");
    }
    pcVar3 = (pdVar5->parent).mpBgDt;
    uVar4 = (uint)(ushort)pcVar3->mpTriTbl[param_2].mID;
    if (pcVar3->mTiCount <= (int)uVar4) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"c_bg_w.h",0x2f8,"0 <= id && id < pm_bgd->m_ti_num");
      m_Do_printf::OSPanic("c_bg_w.h",0x2f8,"Halt");
    }
    param_3 = (param_4 & ((pdVar5->parent).mpBgDt)->mpTiTbl[uVar4].mPolyID0) >> param_5;
  }
  return param_3;
}


/* __thiscall dBgS::GetPolyCamId(int,
                                 int) */

void __thiscall dBgS::GetPolyCamId(dBgS *this,int param_1,int param_2)

{
  GetPolyId0(this,param_1,param_2,0xff,0xff,0);
  return;
}


/* __thiscall dBgS::GetMtrlSndId(cBgS_PolyInfo &) */

void __thiscall dBgS::GetMtrlSndId(dBgS *this,cBgS_PolyInfo *param_1)

{
  GetPolyId0(this,(uint)(ushort)param_1->mBgIndex,(uint)(ushort)param_1->mTriIdx,0,0x1f00,8);
  return;
}


/* __thiscall dBgS::GetExitId(cBgS_PolyInfo &) */

void __thiscall dBgS::GetExitId(dBgS *this,cBgS_PolyInfo *param_1)

{
  GetPolyId0(this,(uint)(ushort)param_1->mBgIndex,(uint)(ushort)param_1->mTriIdx,0x3f,0x7e000,0xd);
  return;
}


/* __thiscall dBgS::GetPolyColor(cBgS_PolyInfo &) */

undefined4 __thiscall dBgS::GetPolyColor(dBgS *this,cBgS_PolyInfo *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  
  if ((ushort)param_1->mTriIdx != 0xffff) {
    if (param_1->mBgIndex != 0x100) {
      bVar1 = true;
      goto LAB_800a06d4;
    }
  }
  bVar1 = false;
LAB_800a06d4:
  if (bVar1) {
    uVar2 = GetPolyId0(this,(uint)(ushort)param_1->mBgIndex,(uint)(ushort)param_1->mTriIdx,0xff,
                       0x7f80000,0x13);
  }
  else {
    uVar2 = 0xff;
  }
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dBgS::GetGrpRoomInfId(cBgS_PolyInfo &) */

byte __thiscall dBgS::GetGrpRoomInfId(dBgS *this,cBgS_PolyInfo *param_1)

{
  ulong uVar1;
  int grp_id;
  byte bVar2;
  uint uVar3;
  
  uVar3 = (uint)(ushort)param_1->mBgIndex;
  if (0xff < uVar3) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_bg_s.cpp",0x3a9,"0 <= bg_index && bg_index < 256");
    m_Do_printf::OSPanic("d_bg_s.cpp",0x3a9,"Halt");
  }
  if (((this->parent).mChkElm[uVar3].mFlags & 1U) == 0) {
    bVar2 = 0xff;
  }
  else {
    bVar2 = ((this->parent).mChkElm[uVar3].mpBgW)->mRoomNo2;
    if (bVar2 == 0xff) {
      grp_id = cBgS::GetTriGrp(&this->parent,(uint)(ushort)param_1->mBgIndex,
                               (uint)(ushort)param_1->mTriIdx);
      if (grp_id == -1) {
        bVar2 = 0xff;
      }
      else {
        bVar2 = cBgS::GetGrpInf(&this->parent,param_1,grp_id);
      }
    }
  }
  return bVar2;
}


/* __thiscall dBgS::GetGrpSoundId(cBgS_PolyInfo &) */

uint __thiscall dBgS::GetGrpSoundId(dBgS *this,cBgS_PolyInfo *param_1)

{
  int grp_id;
  uint uVar1;
  
  grp_id = cBgS::GetTriGrp(&this->parent,(uint)(ushort)param_1->mBgIndex,
                           (uint)(ushort)param_1->mTriIdx);
  if (grp_id == -1) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = cBgS::GetGrpInf(&this->parent,param_1,grp_id);
    uVar1 = uVar1 >> 0xb & 0xff;
  }
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dBgS::ChkGrpInf(cBgS_PolyInfo &,
                              unsigned long) */

uint __thiscall dBgS::ChkGrpInf(dBgS *this,cBgS_PolyInfo *param_1,ulong param_2)

{
  int grp_id;
  uint uVar1;
  
  grp_id = cBgS::GetTriGrp(&this->parent,(uint)(ushort)param_1->mBgIndex,
                           (uint)(ushort)param_1->mTriIdx);
  if (grp_id == -1) {
    uVar1 = 0;
  }
  else {
    uVar1 = cBgS::GetGrpInf(&this->parent,param_1,grp_id);
    uVar1 = uVar1 & param_2;
  }
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall dBgS::GetPolyId1(int,
                               int,
                               int,
                               unsigned long,
                               unsigned long) */

int __thiscall
dBgS::GetPolyId1(dBgS *this,int param_1,int param_2,int param_3,ulong param_4,ulong param_5)

{
  bool bVar1;
  ulong uVar2;
  cBgD_t *pcVar3;
  uint uVar4;
  dBgW *pdVar5;
  
  bVar1 = false;
  if ((-1 < param_1) && (param_1 < 0x100)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_bg_s.cpp",0x414,"0 <= bg_index && bg_index < 256");
    m_Do_printf::OSPanic("d_bg_s.cpp",0x414,"Halt");
  }
  if (((this->parent).mChkElm[param_1].mFlags & 1U) != 0) {
    pdVar5 = (this->parent).mChkElm[param_1].mpBgW;
    bVar1 = false;
    if ((-1 < param_2) && (param_2 < ((pdVar5->parent).mpBgDt)->mTriCount)) {
      bVar1 = true;
    }
    if (!bVar1) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert
                (uVar2,"c_bg_w.h",0x2f1,"0 <= poly_index && poly_index < pm_bgd->m_t_num");
      m_Do_printf::OSPanic("c_bg_w.h",0x2f1,"Halt");
    }
    pcVar3 = (pdVar5->parent).mpBgDt;
    uVar4 = (uint)(ushort)pcVar3->mpTriTbl[param_2].mID;
    if (pcVar3->mTiCount <= (int)uVar4) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"c_bg_w.h",0x2fd,"0 <= id && id < pm_bgd->m_ti_num");
      m_Do_printf::OSPanic("c_bg_w.h",0x2fd,"Halt");
    }
    param_3 = (param_4 & ((pdVar5->parent).mpBgDt)->mpTiTbl[uVar4].mPolyID1) >> param_5;
  }
  return param_3;
}


/* __thiscall dBgS::GetLinkNo(cBgS_PolyInfo &) */

void __thiscall dBgS::GetLinkNo(dBgS *this,cBgS_PolyInfo *param_1)

{
  GetPolyId1(this,(uint)(ushort)param_1->mBgIndex,(uint)(ushort)param_1->mTriIdx,0xff,0xff,0);
  return;
}


/* __thiscall dBgS::GetWallCode(cBgS_PolyInfo &) */

void __thiscall dBgS::GetWallCode(dBgS *this,cBgS_PolyInfo *param_1)

{
  GetPolyId1(this,(uint)(ushort)param_1->mBgIndex,(uint)(ushort)param_1->mTriIdx,0,0xf00,8);
  return;
}


/* __thiscall dBgS::GetSpecialCode(cBgS_PolyInfo &) */

void __thiscall dBgS::GetSpecialCode(dBgS *this,cBgS_PolyInfo *param_1)

{
  GetPolyId1(this,(uint)(ushort)param_1->mBgIndex,(uint)(ushort)param_1->mTriIdx,0,0xf000,0xc);
  return;
}


namespace d_bg_s {

/* __stdcall dBgS_ChangeAttributeCode(unsigned long,
                                      unsigned long *) */

void dBgS_ChangeAttributeCode(int param_1,uint *param_2)

{
  *param_2 = *param_2 & 0xffe0ffff;
  *param_2 = *param_2 | param_1 << 0x10;
  return;
}

}

/* __thiscall dBgS::GetAttributeCodeDirect(cBgS_PolyInfo &) */

void __thiscall dBgS::GetAttributeCodeDirect(dBgS *this,cBgS_PolyInfo *param_1)

{
  GetPolyId1(this,(uint)(ushort)param_1->mBgIndex,(uint)(ushort)param_1->mTriIdx,0,0x1f0000,0x10);
  return;
}


/* __thiscall dBgS::GetAttributeCode(cBgS_PolyInfo &) */

int __thiscall dBgS::GetAttributeCode(dBgS *this,cBgS_PolyInfo *param_1)

{
  int iVar1;
  
  iVar1 = GetAttributeCodeDirect(this,param_1);
  if ((iVar1 < 0) || (0x1f < iVar1)) {
    iVar1 = 0;
  }
  else {
    iVar1 = d_bg_s::atr_conv[iVar1];
  }
  return iVar1;
}


/* __thiscall dBgS::GetGroundCode(cBgS_PolyInfo &) */

void __thiscall dBgS::GetGroundCode(dBgS *this,cBgS_PolyInfo *param_1)

{
  GetPolyId1(this,(uint)(ushort)param_1->mBgIndex,(uint)(ushort)param_1->mTriIdx,0,0x3e00000,0x15);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall dBgS::GetPolyId2(int,
                               int,
                               int,
                               unsigned long,
                               unsigned long) */

int __thiscall
dBgS::GetPolyId2(dBgS *this,int param_1,int param_2,int param_3,ulong param_4,ulong param_5)

{
  bool bVar1;
  ulong uVar2;
  cBgD_t *pcVar3;
  uint uVar4;
  dBgW *pdVar5;
  
  bVar1 = false;
  if ((-1 < param_1) && (param_1 < 0x100)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_bg_s.cpp",0x4c1,"0 <= bg_index && bg_index < 256");
    m_Do_printf::OSPanic("d_bg_s.cpp",0x4c1,"Halt");
  }
  if (((this->parent).mChkElm[param_1].mFlags & 1U) != 0) {
    pdVar5 = (this->parent).mChkElm[param_1].mpBgW;
    bVar1 = false;
    if ((-1 < param_2) && (param_2 < ((pdVar5->parent).mpBgDt)->mTriCount)) {
      bVar1 = true;
    }
    if (!bVar1) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert
                (uVar2,"c_bg_w.h",0x2f1,"0 <= poly_index && poly_index < pm_bgd->m_t_num");
      m_Do_printf::OSPanic("c_bg_w.h",0x2f1,"Halt");
    }
    pcVar3 = (pdVar5->parent).mpBgDt;
    uVar4 = (uint)(ushort)pcVar3->mpTriTbl[param_2].mID;
    if (pcVar3->mTiCount <= (int)uVar4) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"c_bg_w.h",0x302,"0 <= id && id < pm_bgd->m_ti_num");
      m_Do_printf::OSPanic("c_bg_w.h",0x302,"Halt");
    }
    param_3 = (param_4 & ((pdVar5->parent).mpBgDt)->mpTiTbl[uVar4].mPolyID2) >> param_5;
  }
  return param_3;
}


/* __thiscall dBgS::GetCamMoveBG(cBgS_PolyInfo &) */

void __thiscall dBgS::GetCamMoveBG(dBgS *this,cBgS_PolyInfo *param_1)

{
  GetPolyId2(this,(uint)(ushort)param_1->mBgIndex,(uint)(ushort)param_1->mTriIdx,0xff,0xff,0);
  return;
}


/* __thiscall dBgS::GetRoomCamId(cBgS_PolyInfo &) */

void __thiscall dBgS::GetRoomCamId(dBgS *this,cBgS_PolyInfo *param_1)

{
  GetPolyId2(this,(uint)(ushort)param_1->mBgIndex,(uint)(ushort)param_1->mTriIdx,0xff,0xff00,8);
  return;
}


/* __thiscall dBgS::GetRoomPathId(cBgS_PolyInfo &) */

void __thiscall dBgS::GetRoomPathId(dBgS *this,cBgS_PolyInfo *param_1)

{
  GetPolyId2(this,(uint)(ushort)param_1->mBgIndex,(uint)(ushort)param_1->mTriIdx,0xff,0xff0000,0x10)
  ;
  return;
}


namespace d_bg_s {

/* __stdcall dBgS_GetRoomPathPntNo(unsigned long) */

uint dBgS_GetRoomPathPntNo(uint param_1)

{
  return param_1 >> 0x18;
}

}

/* __thiscall dBgS::GetRoomPathPntNo(cBgS_PolyInfo &) */

void __thiscall dBgS::GetRoomPathPntNo(dBgS *this,cBgS_PolyInfo *param_1)

{
  GetPolyId2(this,(uint)(ushort)param_1->mBgIndex,(uint)(ushort)param_1->mTriIdx,0xff,0xff000000,
             0x18);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dBgS::GetRoomId(cBgS_PolyInfo &) */

uint __thiscall dBgS::GetRoomId(dBgS *this,cBgS_PolyInfo *param_1)

{
  ushort uVar1;
  bool bVar2;
  uint uVar3;
  ulong uVar4;
  char cVar5;
  int grp;
  
  if ((param_1->mTriIdx == -1) || (param_1->mBgIndex == 0x100)) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if (bVar2) {
    uVar1 = param_1->mBgIndex;
    if (0xff < uVar1) {
      uVar4 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar4,"d_bg_s.cpp",0x51b,"0 <= id && id < 256");
      m_Do_printf::OSPanic("d_bg_s.cpp",0x51b,"Halt");
    }
    cVar5 = cBgS::ChkPolySafe(&this->parent,param_1);
    if (cVar5 == '\0') {
      uVar3 = 0xffffffff;
    }
    else {
      uVar3 = (uint)(ushort)((this->parent).mChkElm[uVar1].mpBgW)->mRoomNo;
      if (uVar3 == 0xffff) {
        grp = cBgS::GetTriGrp(&this->parent,(uint)(ushort)param_1->mBgIndex,
                              (uint)(ushort)param_1->mTriIdx);
        uVar3 = cBgS::GetGrpToRoomId(&this->parent,(uint)(ushort)param_1->mBgIndex,grp);
        if (uVar3 == 0xffff) {
          uVar3 = 0xffffffff;
        }
      }
    }
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dBgS::ChkPolyHSStick(cBgS_PolyInfo &) */

uint __thiscall dBgS::ChkPolyHSStick(dBgS *this,cBgS_PolyInfo *param_1)

{
  ushort uVar1;
  ulong uVar2;
  cBgD_t *pcVar3;
  uint uVar4;
  dBgW *pdVar5;
  
  uVar4 = (uint)(ushort)param_1->mBgIndex;
  if (0xff < uVar4) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_bg_s.cpp",0x583,"0 <= bg_index && bg_index < 256");
    m_Do_printf::OSPanic("d_bg_s.cpp",0x583,"Halt");
  }
  if (((this->parent).mChkElm[uVar4].mFlags & 1U) == 0) {
    uVar4 = 0;
  }
  else {
    pdVar5 = (this->parent).mChkElm[uVar4].mpBgW;
    uVar1 = param_1->mTriIdx;
    if (((pdVar5->parent).mpBgDt)->mTriCount <= (int)(uint)uVar1) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert
                (uVar2,"c_bg_w.h",0x2f1,"0 <= poly_index && poly_index < pm_bgd->m_t_num");
      m_Do_printf::OSPanic("c_bg_w.h",0x2f1,"Halt");
    }
    pcVar3 = (pdVar5->parent).mpBgDt;
    uVar4 = (uint)(ushort)pcVar3->mpTriTbl[uVar1].mID;
    if (pcVar3->mTiCount <= (int)uVar4) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"c_bg_w.h",0x307,"0 <= id && id < pm_bgd->m_ti_num");
      m_Do_printf::OSPanic("c_bg_w.h",0x307,"Halt");
    }
    uVar4 = ((pdVar5->parent).mpBgDt)->mpTiTbl[uVar4].mPassFlag & 0x10;
  }
  return uVar4;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall dBgS::LineCrossNonMoveBG(cBgS_LinChk *) */

int __thiscall dBgS::LineCrossNonMoveBG(dBgS *this,cBgS_LinChk *pChk)

{
  uint uVar1;
  bool bVar3;
  ulong uVar2;
  cBgS_ChkElm *pChkElm;
  dBgW *pdVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar6 = 0;
  (pChk->mPolyInfo).mTriIdx = -1;
  (pChk->mPolyInfo).mBgIndex = 0x100;
  iVar7 = 0;
  (pChk->mPolyInfo).mpBgW = (cBgW *)0x0;
  (pChk->mPolyInfo).mProcID = -1;
  pChk->mFlags = pChk->mFlags & 0xffffffef;
  iVar5 = 0;
  do {
    pChkElm = (cBgS_ChkElm *)((int)&(this->parent).mChkElm[0].mpBgW + iVar7);
    if (((pChkElm->mFlags & 1U) != 0) && ((pChkElm->mpBgW->parent).mpVtxTbl != (cXyz *)0x0)) {
      bVar3 = cBgS_Chk::ChkSameActorPid(&pChk->parent,pChkElm->mProcID);
      if ((bVar3 == false) && (((pChkElm->mpBgW->parent).mFlags & MoveBG) == 0)) {
        uVar1 = countLeadingZeros(pChk->mFlags & 0x40000000);
        pChk->field_0x50 = (byte)(uVar1 >> 5);
        uVar1 = countLeadingZeros(pChk->mFlags & 0x80000000);
        pChk->field_0x51 = (byte)(uVar1 >> 5);
        uVar1 = countLeadingZeros(pChk->mFlags & 0x20000000);
        pChk->field_0x52 = (byte)(uVar1 >> 5);
        uVar1 = cBgW::LineCheckGrpRp(&pChkElm->mpBgW->parent,pChk,*(int *)&pChkElm->mpBgW->parent,1)
        ;
        if ((uVar1 & 0xff) != 0) {
          iVar6 = pChkElm->mProcID;
          pdVar4 = pChkElm->mpBgW;
          if (iVar5 < 0) {
            uVar2 = JUTAssertion::getSDevice();
            JUTAssertion::showAssert(uVar2,"c_bg_s_poly_info.h",0x59,"0 <= bg_index");
            m_Do_printf::OSPanic("c_bg_s_poly_info.h",0x59,"Halt");
          }
          (pChk->mPolyInfo).mBgIndex = (short)iVar5;
          (pChk->mPolyInfo).mpBgW = &pdVar4->parent;
          (pChk->mPolyInfo).mProcID = iVar6;
          iVar6 = 1;
        }
      }
    }
    iVar5 = iVar5 + 1;
    iVar7 = iVar7 + 0x14;
  } while (iVar5 < 0x100);
  if (iVar6 != 0) {
    pChk->mFlags = pChk->mFlags | 0x10;
  }
  return iVar6;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall dBgS::WallCorrect(dBgS_Acch *) */

void __thiscall dBgS::WallCorrect(dBgS *this,dBgS_Acch *pAcch)

{
  int pid;
  cXyz *pcVar1;
  dBgW *pBgW;
  bool bVar2;
  int iVar3;
  cXyz *pcVar4;
  dBgS_AcchCir *pAcchCir;
  int idx;
  uint pass;
  cBgS_ChkElm *pChk;
  
  iVar3 = 0;
  idx = 0;
  while( true ) {
    if (pAcch->mAcchCirCount <= iVar3) break;
    pAcchCir = (dBgS_AcchCir *)((int)&(pAcch->mpAcchCir->mPolyInfo).mTriIdx + idx);
    pAcchCir->field_0x28 = pAcchCir->mWallRadius * pAcchCir->mWallRadius;
    iVar3 = iVar3 + 1;
    idx = idx + 0x40;
  }
  dBgS_Acch::SetWallCir(pAcch);
  pcVar4 = pAcch->mpPos;
  pcVar1 = pAcch->mpOldPos;
  (pAcch->mLin).mP0.x = pcVar1->x;
  (pAcch->mLin).mP0.y = pcVar1->y;
  (pAcch->mLin).mP0.z = pcVar1->z;
  (pAcch->mLin).mP1.x = pcVar4->x;
  (pAcch->mLin).mP1.y = pcVar4->y;
  (pAcch->mLin).mP1.z = pcVar4->z;
  dBgS_Acch::CalcWallBmdCyl(pAcch);
  pass = 0;
  do {
    idx = 0;
    iVar3 = 0;
    do {
      pChk = (cBgS_ChkElm *)((int)&(this->parent).mChkElm[0].mpBgW + iVar3);
      if ((pChk->mFlags & 1U) != 0) {
        pBgW = pChk->mpBgW;
        if ((pBgW->parent).mpVtxTbl != (cXyz *)0x0) {
          pid = pChk->mProcID;
          pAcch->mChkElmIdx = idx;
          pAcch->mChkElmBgW = pBgW;
          pAcch->mChkElmProcID = pid;
          bVar2 = cBgS_Chk::ChkSameActorPid(&pAcch->mChk,pChk->mProcID);
          if ((bVar2 == false) && (pBgW = pChk->mpBgW, (pBgW->parent).mWallCorrectPriority == pass))
          {
            dBgW::WallCorrectGrpRp(pBgW,pAcch,(pBgW->parent).mRootGrpIdx,1);
          }
        }
      }
      idx = idx + 1;
      iVar3 = iVar3 + 0x14;
    } while (idx < 0x100);
    pass = pass + 1;
  } while ((int)pass < 3);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall dBgS::RoofChk(dBgS_RoofChk *) */

double __thiscall dBgS::RoofChk(dBgS *this,dBgS_RoofChk *param_1)

{
  bool bVar2;
  char cVar3;
  ulong uVar1;
  dBgW *pdVar4;
  dBgW **ppdVar5;
  dBgW *pdVar6;
  int iVar7;
  int iVar8;
  
  param_1[1].mPolyInfo.mpBgW = (cBgW *)d_bg_s::_4376;
  (param_1->mPolyInfo).mTriIdx = -1;
  (param_1->mPolyInfo).mBgIndex = 0x100;
  iVar7 = 0;
  (param_1->mPolyInfo).mpBgW = (cBgW *)0x0;
  (param_1->mPolyInfo).mProcID = -1;
  iVar8 = 0;
  do {
    ppdVar5 = (dBgW **)((int)&(this->parent).mChkElm[0].mpBgW + iVar7);
    if ((((uint)ppdVar5[1] & 1) != 0) && (((*ppdVar5)->parent).mpVtxTbl != (cXyz *)0x0)) {
      bVar2 = cBgS_Chk::ChkSameActorPid(&param_1->mChk,(uint)ppdVar5[2]);
      if ((bVar2 == false) &&
         (cVar3 = dBgW::RoofChkGrpRp(*ppdVar5,param_1,((*ppdVar5)->parent).mRootGrpIdx,1),
         cVar3 != '\0')) {
        pdVar4 = ppdVar5[2];
        pdVar6 = *ppdVar5;
        if (iVar8 < 0) {
          uVar1 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar1,"c_bg_s_poly_info.h",0x59,"0 <= bg_index");
          m_Do_printf::OSPanic("c_bg_s_poly_info.h",0x59,"Halt");
        }
        (param_1->mPolyInfo).mBgIndex = (short)iVar8;
        (param_1->mPolyInfo).mpBgW = &pdVar6->parent;
        (param_1->mPolyInfo).mProcID = (int)pdVar4;
      }
    }
    iVar8 = iVar8 + 1;
    iVar7 = iVar7 + 0x14;
  } while (iVar8 < 0x100);
  return (double)(float)param_1[1].mPolyInfo.mpBgW;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall dBgS::SplGrpChk(dBgS_SplGrpChk *) */

undefined4 __thiscall dBgS::SplGrpChk(dBgS *this,dBgS_SplGrpChk *param_1)

{
  bool bVar2;
  char cVar3;
  ulong uVar1;
  int iVar4;
  cBgS_ChkElm *ppBgW;
  dBgW *pdVar5;
  int iVar6;
  int bg_index;
  undefined4 uVar7;
  
  uVar7 = 0;
  dBgS_SplGrpChk::Init(param_1);
  bg_index = 0;
  iVar6 = 0;
  do {
    ppBgW = (cBgS_ChkElm *)((int)&(this->parent).mChkElm[0].mpBgW + iVar6);
    if (((ppBgW->mFlags & 1U) != 0) && ((ppBgW->mpBgW->parent).mpVtxTbl != (cXyz *)0x0)) {
      bVar2 = cBgS_Chk::ChkSameActorPid(&param_1->mChk,ppBgW->mProcID);
      if ((bVar2 == false) &&
         (cVar3 = dBgW::SplGrpChkGrpRp(ppBgW->mpBgW,param_1,(ppBgW->mpBgW->parent).mRootGrpIdx,1),
         cVar3 != '\0')) {
        uVar7 = 1;
        iVar4 = ppBgW->mProcID;
        pdVar5 = ppBgW->mpBgW;
        if (bg_index < 0) {
          uVar1 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar1,"c_bg_s_poly_info.h",0x59,"0 <= bg_index");
          m_Do_printf::OSPanic("c_bg_s_poly_info.h",0x59,"Halt");
        }
        (param_1->mPolyInfo).mBgIndex = (short)bg_index;
        (param_1->mPolyInfo).mpBgW = &pdVar5->parent;
        (param_1->mPolyInfo).mProcID = iVar4;
        param_1->mFlags = param_1->mFlags | 1;
      }
    }
    bg_index = bg_index + 1;
    iVar6 = iVar6 + 0x14;
  } while (bg_index < 0x100);
  return uVar7;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall dBgS::SphChk(dBgS_SphChk *,
                           void *) */

undefined4 __thiscall dBgS::SphChk(dBgS *this,dBgS_SphChk *param_1,void *param_2)

{
  bool bVar2;
  char cVar3;
  ulong uVar1;
  dBgW **ppdVar4;
  dBgW *pdVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  dBgW *pdVar9;
  
  uVar8 = 0;
  (param_1->mPolyInfo).mTriIdx = -1;
  (param_1->mPolyInfo).mBgIndex = 0x100;
  iVar6 = 0;
  (param_1->mPolyInfo).mpBgW = (cBgW *)0x0;
  (param_1->mPolyInfo).mProcID = -1;
  iVar7 = 0;
  do {
    ppdVar4 = (dBgW **)((int)&(this->parent).mChkElm[0].mpBgW + iVar6);
    if ((((uint)ppdVar4[1] & 1) != 0) && (((*ppdVar4)->parent).mpVtxTbl != (cXyz *)0x0)) {
      bVar2 = cBgS_Chk::ChkSameActorPid(&param_1->mChk,(uint)ppdVar4[2]);
      if ((bVar2 == false) &&
         (cVar3 = dBgW::SphChkGrpRp(*ppdVar4,param_1,param_2,((*ppdVar4)->parent).mRootGrpIdx,1),
         cVar3 != '\0')) {
        pdVar5 = ppdVar4[2];
        pdVar9 = *ppdVar4;
        if (iVar7 < 0) {
          uVar1 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar1,"c_bg_s_poly_info.h",0x59,"0 <= bg_index");
          m_Do_printf::OSPanic("c_bg_s_poly_info.h",0x59,"Halt");
        }
        (param_1->mPolyInfo).mBgIndex = (short)iVar7;
        (param_1->mPolyInfo).mpBgW = &pdVar9->parent;
        (param_1->mPolyInfo).mProcID = (int)pdVar5;
        uVar8 = 1;
      }
    }
    iVar7 = iVar7 + 1;
    iVar6 = iVar6 + 0x14;
  } while (iVar7 < 0x100);
  return uVar8;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Removing unreachable block (ram,0x800a192c) */
/* WARNING: Removing unreachable block (ram,0x800a1934) */
/* __thiscall dBgS::WallCrrPos(dBgS_CrrPos *) */

undefined4 __thiscall dBgS::WallCrrPos(dBgS *this,dBgS_CrrPos *param_1)

{
  float fVar1;
  uint uVar2;
  cXyz *pcVar3;
  bool bVar5;
  char cVar6;
  ulong uVar4;
  cXyz *pcVar7;
  undefined4 uVar8;
  dBgW *pdVar9;
  dBgW **ppdVar10;
  dBgW *pdVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  undefined4 uVar15;
  undefined8 in_f30;
  double dVar16;
  undefined8 in_f31;
  double dVar17;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar15 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  dVar16 = (double)(d_bg_s::_4724 * param_1->mOffsY);
  dVar17 = (double)param_1->field_0x40;
  ::cM3dGCyl::SetC(&param_1->mCyl0,param_1->mpLine0);
  ::cM3dGCyl::SetR(&param_1->mCyl0,(float)dVar17);
  ::cM3dGCyl::SetH(&param_1->mCyl0,(float)dVar16);
  dVar17 = (double)(d_bg_s::_4724 * param_1->mOffsY);
  dVar16 = (double)param_1->field_0x40;
  ::cM3dGCyl::SetC(&param_1->mCyl1,param_1->mpPos);
  ::cM3dGCyl::SetR(&param_1->mCyl1,(float)dVar16);
  ::cM3dGCyl::SetH(&param_1->mCyl1,(float)dVar17);
  pcVar7 = param_1->mpPos;
  pcVar3 = param_1->mpLine0;
  (param_1->mLin).mP0.x = pcVar3->x;
  (param_1->mLin).mP0.y = pcVar3->y;
  (param_1->mLin).mP0.z = pcVar3->z;
  (param_1->mLin).mP1.x = pcVar7->x;
  (param_1->mLin).mP1.y = pcVar7->y;
  (param_1->mLin).mP1.z = pcVar7->z;
  fVar1 = d_bg_s::_4725;
  *(float *)&param_1->field_0x54 = d_bg_s::_4725;
  *(float *)&param_1->field_0x50 = fVar1;
  *(float *)&param_1->field_0x4c = fVar1;
  uVar8 = 0;
  iVar14 = 0;
  do {
    iVar13 = 0;
    iVar12 = 0;
    do {
      ppdVar10 = (dBgW **)((int)&(this->parent).mChkElm[0].mpBgW + iVar12);
      if (((((uint)ppdVar10[1] & 1) != 0) && (((*ppdVar10)->parent).mpVtxTbl != (cXyz *)0x0)) &&
         (bVar5 = cBgS_Chk::ChkSameActorPid((cBgS_Chk *)&param_1->mpPolyPassChk,(uint)ppdVar10[2]),
         bVar5 == false)) {
        uVar2 = countLeadingZeros(iVar14 - (uint)((*ppdVar10)->parent).mWallCorrectPriority);
        if (((uVar2 >> 5 & 0xff) != 0) &&
           (cVar6 = dBgW::WallCrrPos(*ppdVar10,param_1), cVar6 != '\0')) {
          pdVar9 = ppdVar10[2];
          pdVar11 = *ppdVar10;
          if (iVar13 < 0) {
            uVar4 = JUTAssertion::getSDevice();
            JUTAssertion::showAssert(uVar4,"c_bg_s_poly_info.h",0x59,"0 <= bg_index");
            m_Do_printf::OSPanic("c_bg_s_poly_info.h",0x59,"Halt");
          }
          (param_1->mPolyInfo).mBgIndex = (short)iVar13;
          (param_1->mPolyInfo).mpBgW = &pdVar11->parent;
          (param_1->mPolyInfo).mProcID = (int)pdVar9;
          param_1->mpPos->x = param_1->mpPos->x + *(float *)&param_1->field_0x4c;
          param_1->mpPos->y = param_1->mpPos->y + *(float *)&param_1->field_0x50;
          param_1->mpPos->z = param_1->mpPos->z + *(float *)&param_1->field_0x54;
          uVar8 = 1;
        }
      }
      iVar13 = iVar13 + 1;
      iVar12 = iVar12 + 0x14;
    } while (iVar13 < 0x100);
    iVar14 = iVar14 + 1;
  } while (iVar14 < 3);
  __psq_l0(auStack8,uVar15);
  __psq_l1(auStack8,uVar15);
  __psq_l0(auStack24,uVar15);
  __psq_l1(auStack24,uVar15);
  return uVar8;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall dBgS::MoveBgCrrPos(cBgS_PolyInfo &,
                                 bool,
                                 cXyz *,
                                 csXyz *,
                                 csXyz *) */

void __thiscall
dBgS::MoveBgCrrPos(dBgS *this,cBgS_PolyInfo *pPolyInf,bool param_2,cXyz *pDstPos,csXyz *pRot,
                  csXyz *pCollisionRot)

{
  int iVar1;
  ulong uVar2;
  char cVar3;
  undefined3 in_register_00000014;
  dBgW *pdVar4;
  uint idx;
  
  if ((param_2 != false) &&
     (idx = (uint)(ushort)pPolyInf->mBgIndex, iVar1 = -idx + 0x100,
     (iVar1 - ((uint)(iVar1 == 0) + -idx + 0xff) & 0xff) != 0)) {
    if (0xff < idx) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"d_bg_s.cpp",0x777,"0 <= bg_index && bg_index < 256");
      m_Do_printf::OSPanic("d_bg_s.cpp",0x777,"Halt");
    }
    if (((((this->parent).mChkElm[idx].mFlags & 1U) != 0) &&
        (pdVar4 = (this->parent).mChkElm[idx].mpBgW, (pdVar4->mFlag & 1) != 0)) &&
       (cVar3 = cBgS::ChkPolySafe(&this->parent,pPolyInf), cVar3 != '\0')) {
      (**(code **)((pdVar4->parent).vtbl + 0x24))
                (pdVar4,pPolyInf,(this->parent).mChkElm[idx].mpActorPtr,
                 CONCAT31(in_register_00000014,param_2),pDstPos,pRot,pCollisionRot);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall dBgS::MoveBgTransPos(cBgS_PolyInfo &,
                                   bool,
                                   cXyz *,
                                   csXyz *,
                                   csXyz *) */

void __thiscall
dBgS::MoveBgTransPos
          (dBgS *this,cBgS_PolyInfo *param_1,bool param_2,cXyz *param_3,csXyz *param_4,
          csXyz *param_5)

{
  int iVar1;
  ulong uVar2;
  char cVar3;
  undefined3 in_register_00000014;
  dBgW *pdVar4;
  uint uVar5;
  
  if ((param_2 != false) &&
     (uVar5 = (uint)(ushort)param_1->mBgIndex, iVar1 = -uVar5 + 0x100,
     (iVar1 - ((uint)(iVar1 == 0) + -uVar5 + 0xff) & 0xff) != 0)) {
    if (0xff < uVar5) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"d_bg_s.cpp",0x7a4,"0 <= bg_index && bg_index < 256");
      m_Do_printf::OSPanic("d_bg_s.cpp",0x7a4,"Halt");
    }
    if (((((this->parent).mChkElm[uVar5].mFlags & 1U) != 0) &&
        (pdVar4 = (this->parent).mChkElm[uVar5].mpBgW, (pdVar4->mFlag & 1) != 0)) &&
       (cVar3 = cBgS::ChkPolySafe(&this->parent,param_1), cVar3 != '\0')) {
      (**(code **)((pdVar4->parent).vtbl + 0x28))
                (pdVar4,param_1,(this->parent).mChkElm[uVar5].mpActorPtr,
                 CONCAT31(in_register_00000014,param_2),param_3,param_4,param_5);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall dBgS::MoveBgMatrixCrrPos(cBgS_PolyInfo &,
                                       bool,
                                       cXyz *,
                                       csXyz *,
                                       csXyz *) */

void __thiscall
dBgS::MoveBgMatrixCrrPos
          (dBgS *this,cBgS_PolyInfo *param_1,bool param_2,cXyz *param_3,csXyz *param_4,
          csXyz *param_5)

{
  int iVar1;
  ulong uVar2;
  dBgW *pdVar3;
  undefined3 in_register_00000014;
  cBgS_ChkElm *pcVar4;
  uint uVar5;
  
  if ((param_2 != false) &&
     (uVar5 = (uint)(ushort)param_1->mBgIndex, iVar1 = -uVar5 + 0x100,
     (iVar1 - ((uint)(iVar1 == 0) + -uVar5 + 0xff) & 0xff) != 0)) {
    if (0xff < uVar5) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"d_bg_s.cpp",1999,"0 <= bg_index && bg_index < 256");
      m_Do_printf::OSPanic("d_bg_s.cpp",1999,"Halt");
    }
    pcVar4 = (this->parent).mChkElm + uVar5;
    if (((pcVar4->mFlags & 1U) != 0) &&
       (pdVar3 = (this->parent).mChkElm[uVar5].mpBgW, (pdVar3->mFlag & 1) != 0)) {
      (**(code **)((pdVar3->parent).vtbl + 0x2c))
                (pdVar3,param_1,pcVar4->mpActorPtr,CONCAT31(in_register_00000014,param_2),param_3,
                 param_4,param_5);
    }
  }
  return;
}


namespace d_bg_s {

/* __stdcall dBgS_MoveBGProc_Typical(dBgW *,
                                     void *,
                                     cBgS_PolyInfo &,
                                     bool,
                                     cXyz *,
                                     csXyz *,
                                     csXyz *) */

void dBgS_MoveBGProc_Typical
               (dBgW *param_1,void *param_2,cBgS_PolyInfo *param_3,bool param_4,cXyz *param_5,
               csXyz *param_6,csXyz *param_7)

{
  int iVar1;
  cXyz local_58;
  cXyz cStack76;
  MTX34 MStack64;
  
  iVar1 = mtx::PSMTXInverse(&(param_1->parent).mOldMtx,&MStack64);
  if (iVar1 != 0) {
    mtx::PSMTXMultVec(&MStack64,param_5,&cStack76);
    mtx::PSMTXMultVec((param_1->parent).mpModelMtx,&cStack76,&local_58);
    param_5->x = local_58.x;
    param_5->y = local_58.y;
    param_5->z = local_58.z;
  }
  return;
}


/* __stdcall dBgS_MoveBGProc_RotY(dBgW *,
                                  void *,
                                  cBgS_PolyInfo &,
                                  bool,
                                  cXyz *,
                                  csXyz *,
                                  csXyz *) */

void dBgS_MoveBGProc_RotY
               (dBgW *param_1,void *param_2,cBgS_PolyInfo *param_3,bool param_4,cXyz *param_5,
               csXyz *param_6,csXyz *param_7)

{
  short sVar1;
  
  if (param_7 == (csXyz *)0x0) {
    return;
  }
  sVar1 = param_1->mRotYDelta;
  if (param_7 != (csXyz *)0x0) {
    param_7->y = param_7->y + sVar1;
  }
  if (param_6 == (csXyz *)0x0) {
    return;
  }
  param_6->y = param_6->y + sVar1;
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __stdcall dBgS_MoveBGProc_TypicalRotY(dBgW *,
                                         void *,
                                         cBgS_PolyInfo &,
                                         bool,
                                         cXyz *,
                                         csXyz *,
                                         csXyz *) */

void dBgS_MoveBGProc_TypicalRotY
               (dBgW *param_1,void *param_2,cBgS_PolyInfo *param_3,bool param_4,cXyz *param_5,
               csXyz *param_6,csXyz *param_7)

{
  dBgS_MoveBGProc_Typical(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  dBgS_MoveBGProc_RotY(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}


/* __stdcall dBgS_MoveBGProc_Trans(dBgW *,
                                   void *,
                                   cBgS_PolyInfo &,
                                   bool,
                                   cXyz *,
                                   csXyz *,
                                   csXyz *) */

void dBgS_MoveBGProc_Trans
               (cBgW *param_1,void *param_2,cBgS_PolyInfo *param_3,bool param_4,cXyz *param_5,
               cXyz *param_6,csXyz *param_7)

{
  cXyz cStack24;
  
  cBgW::GetTrans(param_1,&cStack24);
  mtx::PSVECAdd(param_5,&cStack24,param_5);
  return;
}

}

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dBgS::RideCallBack(cBgS_PolyInfo &,
                                 fopAc_ac_c *) */

void __thiscall dBgS::RideCallBack(dBgS *this,cBgS_PolyInfo *param_1,fopAc_ac_c *param_2)

{
  bool bVar1;
  uint uVar2;
  ulong uVar3;
  dBgW *pdVar4;
  uint uVar5;
  
  uVar5 = (uint)(ushort)param_1->mBgIndex;
  if (0xff < uVar5) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"d_bg_s.cpp",0x881,"0 <= bg_index && bg_index < 256");
    m_Do_printf::OSPanic("d_bg_s.cpp",0x881,"Halt");
  }
  pdVar4 = (this->parent).mChkElm[uVar5].mpBgW;
  uVar2 = (pdVar4->parent).mCount;
  if (((int)uVar2 < 0) || (0xff < (int)uVar2)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if ((bVar1) && ((code *)pdVar4->mpRideCb != (code *)0x0)) {
    (*(code *)pdVar4->mpRideCb)(pdVar4,(this->parent).mChkElm[uVar5].mpActorPtr,param_2);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dBgS::PushPullCallBack(cBgS_PolyInfo &,
                                     fopAc_ac_c *,
                                     short,
                                     dBgW::PushPullLabel) */

undefined4 __thiscall
dBgS::PushPullCallBack
          (dBgS *this,cBgS_PolyInfo *param_1,fopAc_ac_c *param_2,short param_3,PushPullLabel param_4
          )

{
  bool bVar1;
  uint uVar2;
  ulong uVar3;
  undefined4 uVar4;
  fopAc_ac_c *pfVar5;
  dBgW *pdVar6;
  undefined2 in_register_00000018;
  code *pcVar7;
  uint uVar8;
  
  uVar8 = (uint)(ushort)param_1->mBgIndex;
  if (0xff < uVar8) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"d_bg_s.cpp",0x8a2,"0 <= bg_index && bg_index < 256");
    m_Do_printf::OSPanic("d_bg_s.cpp",0x8a2,"Halt");
  }
  pdVar6 = (this->parent).mChkElm[uVar8].mpBgW;
  uVar2 = (pdVar6->parent).mCount;
  if (((int)uVar2 < 0) || (0xff < (int)uVar2)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    pfVar5 = (this->parent).mChkElm[uVar8].mpActorPtr;
    if (pfVar5 == (fopAc_ac_c *)0x0) {
      uVar4 = 0;
    }
    else {
      pcVar7 = (code *)pdVar6->mpPushPullCb;
      if (pcVar7 == (code *)0x0) {
        uVar4 = 0;
      }
      else {
        uVar4 = (*pcVar7)(pfVar5,param_2,CONCAT22(in_register_00000018,param_3),param_4);
      }
    }
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x800a2530) */
/* __thiscall dBgS_CrrPos::CrrPos(dBgS &) */

void __thiscall dBgS_CrrPos::CrrPos(dBgS_CrrPos *this,dBgS *param_1)

{
  float fVar1;
  float fVar2;
  bool bVar3;
  cXyz *pcVar4;
  ulong uVar5;
  cXyz *pcVar6;
  char cVar8;
  cM3dGPla *pcVar7;
  undefined4 uVar9;
  double dVar10;
  undefined8 in_f31;
  double dVar11;
  float fVar12;
  cXyz local_10c;
  cXyz local_100;
  cXyz cStack244;
  cXyz local_e8;
  cBgS_LinChk local_dc;
  cBgS_LinChk cStack132;
  undefined auStack8 [8];
  
  uVar9 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if ((this->field_0x38 & 1) == 0) {
    this->field_0x38 = this->field_0x38 & 0xffffffef;
    this->field_0x38 = this->field_0x38 & 0xffffffdf;
    this->field_0x38 = this->field_0x38 & 0xffffffbf;
    bVar3 = false;
    pcVar4 = this->mpPos;
    if (((((d_bg_s::_5054 < pcVar4->x) && (pcVar4->x < d_bg_s::_5055)) &&
         (d_bg_s::_5054 < pcVar4->y)) &&
        ((pcVar4->y < d_bg_s::_5055 && (d_bg_s::_5054 < pcVar4->z)))) && (pcVar4->z < d_bg_s::_5055)
       ) {
      bVar3 = true;
    }
    if (!bVar3) {
      uVar5 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert
                (uVar5,"d_bg_s.cpp",0x8e8,
                 "-1.0e32f < pm_pos->x && pm_pos->x < 1.0e32f && -1.0e32f < pm_pos->y && pm_pos->y < 1.0e32f && -1.0e32f < pm_pos->z && pm_pos->z < 1.0e32f"
                );
      m_Do_printf::OSPanic("d_bg_s.cpp",0x8e8,"Halt");
    }
    if ((this->field_0x38 & 4) == 0) {
      fVar12 = mtx::PSVECSquareDistance(this->mpLine0,this->mpPos);
      bVar3 = false;
      if (d_bg_s::_5056 * this->field_0x40 * this->field_0x40 < fVar12) {
        bVar3 = true;
        cStack132.parent.mpPolyPassChk = (cBgS_PolyPassChk *)0x0;
        cStack132.parent.mpGrpPassChk = (cBgS_GrpPassChk *)0x0;
        cStack132.parent.mbExcludeSameProcID = true;
        cStack132.mPolyInfo.mTriIdx = 0xffff;
        cStack132.mPolyInfo.mBgIndex = 0x100;
        cStack132.mPolyInfo.mpBgW = (cBgW *)0x0;
        cStack132.mPolyInfo.mProcID = -1;
        cStack132.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_LinChk::__vt;
        cStack132.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&PTR_80371fbc;
        cStack132.mLin.vtbl = (undefined *)&::cM3dGLin::__vt;
        ::cBgS_LinChk::ct(&cStack132);
        pcVar4 = this->mpLine0;
        local_e8.x = pcVar4->x;
        local_e8.z = pcVar4->z;
        pcVar6 = this->mpPos;
        cStack244.x = pcVar6->x;
        cStack244.z = pcVar6->z;
        local_e8.y = pcVar4->y + this->mOffsY;
        cStack244.y = pcVar6->y + this->mOffsY;
        ::cBgS_LinChk::Set2(&cStack132,&local_e8,&cStack244,this->mProcID);
        cStack132.parent.mpPolyPassChk = this->mpPolyPassChk;
        cStack132.parent.mpGrpPassChk = this->mpGrpPassChk;
        cStack132.parent.mProcID = this->mProcID;
        cStack132.parent.mbExcludeSameProcID = this->mbExcludeSameProcID;
        cStack132.mFlags = cStack132.mFlags | 0x80000000;
        cVar8 = cBgS::LineCross(&param_1->parent,&cStack132);
        if (cVar8 != '\0') {
          pcVar4 = this->mpPos;
          pcVar4->x = cStack132.mLin.mP1.x;
          pcVar4->y = cStack132.mLin.mP1.y;
          pcVar4->z = cStack132.mLin.mP1.z;
          pcVar7 = cBgS::GetTriPla(&param_1->parent,(uint)(ushort)cStack132.mPolyInfo.mBgIndex,
                                   (uint)(ushort)cStack132.mPolyInfo.mTriIdx);
          this->mpPos->x = this->mpPos->x + (pcVar7->mNorm).x;
          this->mpPos->y = this->mpPos->y + ((pcVar7->mNorm).y - this->mOffsY);
          this->mpPos->z = this->mpPos->z + (pcVar7->mNorm).z;
        }
        cStack132.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_LinChk::__vt;
        cStack132.mLin.vtbl = (undefined *)&::cM3dGLin::__vt;
        cStack132.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
        cBgS_Chk::_cBgS_Chk(&cStack132.parent);
      }
      cVar8 = dBgS::WallCrrPos(param_1,this);
      if ((cVar8 != '\0') && (bVar3)) {
        local_dc.parent.mpPolyPassChk = (cBgS_PolyPassChk *)0x0;
        local_dc.parent.mpGrpPassChk = (cBgS_GrpPassChk *)0x0;
        local_dc.parent.mbExcludeSameProcID = true;
        local_dc.mPolyInfo.mTriIdx = 0xffff;
        local_dc.mPolyInfo.mBgIndex = 0x100;
        local_dc.mPolyInfo.mpBgW = (cBgW *)0x0;
        local_dc.mPolyInfo.mProcID = -1;
        local_dc.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_LinChk::__vt;
        local_dc.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&PTR_80371fbc;
        local_dc.mLin.vtbl = (undefined *)&::cM3dGLin::__vt;
        ::cBgS_LinChk::ct(&local_dc);
        pcVar4 = this->mpLine0;
        local_100.x = pcVar4->x;
        local_100.z = pcVar4->z;
        pcVar6 = this->mpPos;
        local_10c.x = pcVar6->x;
        local_10c.z = pcVar6->z;
        local_100.y = pcVar4->y + this->mOffsY;
        local_10c.y = pcVar6->y + this->mOffsY;
        ::cBgS_LinChk::Set2(&local_dc,&local_100,&local_10c,this->mProcID);
        local_dc.parent.mpPolyPassChk = this->mpPolyPassChk;
        local_dc.parent.mpGrpPassChk = this->mpGrpPassChk;
        local_dc.parent.mProcID = this->mProcID;
        local_dc.parent.mbExcludeSameProcID = this->mbExcludeSameProcID;
        local_dc.mFlags = local_dc.mFlags | 0x80000000;
        cVar8 = cBgS::LineCross(&param_1->parent,&local_dc);
        if (cVar8 != '\0') {
          pcVar4 = this->mpPos;
          pcVar4->x = local_dc.mLin.mP1.x;
          pcVar4->y = local_dc.mLin.mP1.y;
          pcVar4->z = local_dc.mLin.mP1.z;
          pcVar7 = cBgS::GetTriPla(&param_1->parent,(uint)(ushort)local_dc.mPolyInfo.mBgIndex,
                                   (uint)(ushort)local_dc.mPolyInfo.mTriIdx);
          this->mpPos->x = this->mpPos->x + (pcVar7->mNorm).x;
          this->mpPos->y = this->mpPos->y + ((pcVar7->mNorm).y - this->mOffsY);
          this->mpPos->z = this->mpPos->z + (pcVar7->mNorm).z;
        }
        local_dc.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_LinChk::__vt;
        local_dc.mLin.vtbl = (undefined *)&::cM3dGLin::__vt;
        local_dc.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
        cBgS_Chk::_cBgS_Chk(&local_dc.parent);
      }
    }
    if ((this->field_0x38 & 2) == 0) {
      this->field_0x60 = 0;
      (this->mGndChk).parent.mpPolyPassChk = this->mpPolyPassChk;
      (this->mGndChk).parent.mpGrpPassChk = this->mpGrpPassChk;
      (this->mGndChk).parent.mProcID = this->mProcID;
      (this->mGndChk).parent.mbExcludeSameProcID = this->mbExcludeSameProcID;
      pcVar4 = this->mpPos;
      fVar12 = pcVar4->y;
      fVar1 = pcVar4->z;
      fVar2 = this->mOffsY2;
      (this->mGndChk).mPos.x = pcVar4->x;
      (this->mGndChk).mPos.y = fVar12 + fVar2;
      (this->mGndChk).mPos.z = fVar1;
      dVar11 = (double)this->mpPos->y;
      dVar10 = (double)cBgS::GroundCross(&param_1->parent,&this->mGndChk);
      this->field_0x5c = (float)dVar10;
      dVar10 = (double)this->field_0x5c;
      if (((double)d_bg_s::_5057 != dVar10) && (dVar11 < dVar10)) {
        this->mpPos->y = this->field_0x5c;
        if (this->field_0x58 != (undefined *)0x0) {
          *(float *)(this->field_0x58 + 4) = d_bg_s::_4725;
        }
        this->field_0x60 = 1;
      }
    }
  }
  __psq_l0(auStack8,uVar9);
  __psq_l1(auStack8,uVar9);
  return;
}


/* __thiscall dBgW::MatrixCrrPos(cBgS_PolyInfo &,
                                 void *,
                                 bool,
                                 cXyz *,
                                 csXyz *,
                                 csXyz *) */

void __thiscall
dBgW::MatrixCrrPos(dBgW *this,cBgS_PolyInfo *param_1,void *param_2,bool param_3,cXyz *param_4,
                  csXyz *param_5,csXyz *param_6)

{
  (**(code **)((this->parent).vtbl + 0x24))();
  return;
}

