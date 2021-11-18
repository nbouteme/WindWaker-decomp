#include <d_timer.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <d_com_inf_game.h>
#include <f_op_msg_mng.h>
#include <d_resorce.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <m_Do_ext.h>
#include <JKernel/JKRHeap.h>
#include <d_timer.h>
#include <os/OSTime.h>
#include <d_meter.h>
#include <d_drawlist.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <J2DGraph/J2DPane.h>
#include <J2DGraph/J2DScreen.h>
#include <J2DGraph/J2DPicture.h>
#include <JKernel/JKRArchivePub.h>
#include <dDlst_TimerScrnDraw_c.h>
#include <dTimer_c.h>


namespace d_timer {
}

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dTimer_c::_create(void) */

PhaseState __thiscall dTimer_c::_create(dTimer_c *this)

{
  ushort uVar1;
  ulonglong uVar2;
  int iVar3;
  PhaseState PVar4;
  fopMsgM_prm_class__Timer *pPrm;
  dRes_info_c *pdVar5;
  ulong uVar6;
  JKRSolidHeap *pJVar7;
  dDlst_TimerScrnDraw_c *pScrn;
  void *pvVar8;
  undefined4 uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  undefined *puVar13;
  
  PVar4 = d_com_inf_game::dComIfG_resLoad(&this->mPhs,"Timer");
  if (PVar4 == cPhs_COMPLEATE_e) {
    pPrm = (fopMsgM_prm_class__Timer *)f_op_msg_mng::fopMsgM_GetAppend(&this->parent);
    if (pPrm == (fopMsgM_prm_class__Timer *)0x0) {
      PVar4 = cPhs_ERROR_e;
    }
    else {
      pdVar5 = dRes_control_c::getResInfo
                         ("Timer",d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
      if (pdVar5 == (dRes_info_c *)0x0) {
        uVar6 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar6,"d_timer.cpp",0x44,"resInfo != 0");
        m_Do_printf::OSPanic("d_timer.cpp",0x44,&DAT_803639af);
      }
      if (pPrm->field_0x23 == 0) {
        pJVar7 = m_Do_ext::mDoExt_createSolidHeapFromGameToCurrent(0x34c0,0x20);
        this->mpSolidHeap = &pJVar7->parent;
      }
      else {
        pJVar7 = m_Do_ext::mDoExt_createSolidHeapFromGameToCurrent(0x4260,0x20);
        this->mpSolidHeap = &pJVar7->parent;
      }
      if (this->mpSolidHeap == (JKRHeap *)0x0) {
        PVar4 = cPhs_ERROR_e;
      }
      else {
        pScrn = (dDlst_TimerScrnDraw_c *)JKernel::operator_new(0x238);
        if (pScrn != (dDlst_TimerScrnDraw_c *)0x0) {
          (pScrn->parent).vtbl = (undefined *)&dDlst_base_c::__vt;
          (pScrn->parent).vtbl = &dDlst_TimerScrnDraw_c::__vt;
          pScrn->field_0x234 = 0;
          *(undefined4 *)&pScrn->field_0x230 = 0xffffffff;
          pScrn->field_0x235 = 0;
        }
        this->mpScrnDraw = pScrn;
        dDlst_TimerScrnDraw_c::setScreen(this->mpScrnDraw,"ship_race0.blo",pdVar5->mpArchive);
        if (pPrm->field_0x23 != 0) {
          pvVar8 = JKRHeap::alloc(this->mpSolidHeap,0xc00,0x20);
          *(void **)&this->field_0x100 = pvVar8;
          if (*(int *)&this->field_0x100 == 0) {
            uVar6 = JUTAssertion::getSDevice();
            JUTAssertion::showAssert(uVar6,"d_timer.cpp",0x5a,"iconTex != 0");
            m_Do_printf::OSPanic("d_timer.cpp",0x5a,&DAT_803639af);
          }
          dDlst_TimerScrnDraw_c::setIconType
                    (this->mpScrnDraw,*(void **)&this->field_0x100,pPrm->field_0x23);
        }
        m_Do_ext::mDoExt_restoreCurrentHeap();
        m_Do_ext::mDoExt_adjustSolidHeap((JKRSolidHeap *)this->mpSolidHeap);
        dDlst_TimerScrnDraw_c::setRupeePos(this->mpScrnDraw,(pPrm->mRupeePos).x,(pPrm->mRupeePos).y)
        ;
        dDlst_TimerScrnDraw_c::setTimerPos(this->mpScrnDraw,(pPrm->mTimerPos).x,(pPrm->mTimerPos).y)
        ;
        dDlst_TimerScrnDraw_c::setShowType(this->mpScrnDraw,pPrm->lmShowType);
        this->field_0x154 = pPrm->field_0x1c;
        if (this->field_0x154 == 7) {
          uVar10 = (DAT_800000f8 >> 2) / 1000;
          iVar3 = (int)d_com_inf_game::g_dComIfG_gameInfo._23784_4_ >> 0x1f;
          uVar2 = (ulonglong)d_com_inf_game::g_dComIfG_gameInfo._23784_4_;
          uVar9 = 0;
          *(uint *)&this->field_0x144 = uVar10 * d_com_inf_game::g_dComIfG_gameInfo._23784_4_;
          *(uint *)&this->field_0x140 = (int)(uVar10 * uVar2 >> 0x20) + uVar10 * iVar3;
          iVar3 = os::OSGetTime();
          *(undefined4 *)&this->field_0x114 = uVar9;
          *(int *)&this->field_0x110 = iVar3;
          *(undefined4 *)&this->field_0x11c = uVar9;
          *(int *)&this->field_0x118 = iVar3;
          uVar12 = *(uint *)&this->field_0x114;
          uVar11 = (DAT_800000f8 >> 2) / 1000;
          iVar3 = (int)d_com_inf_game::g_dComIfG_gameInfo._23780_4_ >> 0x1f;
          uVar2 = (ulonglong)d_com_inf_game::g_dComIfG_gameInfo._23780_4_;
          uVar10 = uVar11 * d_com_inf_game::g_dComIfG_gameInfo._23780_4_;
          *(uint *)&this->field_0x114 = uVar12 - uVar10;
          *(uint *)&this->field_0x110 =
               *(int *)&this->field_0x110 -
               ((uint)(uVar12 < uVar10) + (int)(uVar11 * uVar2 >> 0x20) + uVar11 * iVar3);
          *(undefined *)&this->field_0x164 = 0;
          this->field_0x154 = d_com_inf_game::g_dComIfG_gameInfo._23788_4_;
          d_com_inf_game::g_dComIfG_gameInfo._23780_4_ = getTimeMs(this);
          d_com_inf_game::g_dComIfG_gameInfo._23784_4_ = getLimitTimeMs(this);
          d_com_inf_game::g_dComIfG_gameInfo._23788_4_ = this->field_0x154;
          d_com_inf_game::g_dComIfG_gameInfo.mpRestartTimer = this;
          if (d_com_inf_game::g_dComIfG_gameInfo._23788_4_ == 3) {
            dDlst_TimerScrnDraw_c::setShowType(this->mpScrnDraw,1);
          }
          stock_start(this,10);
        }
        else {
          uVar1 = *(ushort *)&pPrm->field_0x20;
          uVar10 = DAT_800000f8 >> 2;
          *(uint *)&this->field_0x144 = uVar1 * uVar10;
          *(int *)&this->field_0x140 = (int)((ulonglong)(uint)uVar1 * (ulonglong)uVar10 >> 0x20);
          *(undefined4 *)&this->field_0x114 = 0;
          *(undefined4 *)&this->field_0x110 = 0;
          *(undefined4 *)&this->field_0x11c = 0;
          *(undefined4 *)&this->field_0x118 = 0;
          *(undefined *)&this->field_0x164 = 0;
          d_com_inf_game::g_dComIfG_gameInfo._23780_4_ = getTimeMs(this);
          d_com_inf_game::g_dComIfG_gameInfo._23784_4_ = getLimitTimeMs(this);
          d_com_inf_game::g_dComIfG_gameInfo._23788_4_ = this->field_0x154;
          d_com_inf_game::g_dComIfG_gameInfo.mpRestartTimer = this;
        }
        *(undefined4 *)&this->field_0x124 = 0;
        *(undefined4 *)&this->field_0x120 = 0;
        *(undefined4 *)&this->field_0x12c = 0;
        *(undefined4 *)&this->field_0x128 = 0;
        *(undefined4 *)&this->field_0x134 = 0;
        *(undefined4 *)&this->field_0x130 = 0;
        *(undefined4 *)&this->field_0x13c = 0;
        *(undefined4 *)&this->field_0x138 = 0;
        *(undefined *)&this->field_0x162 = 0;
        *(undefined *)&this->field_0x163 = 0;
        *(undefined4 *)&this->field_0x158 = 0x78;
        *(undefined4 *)&this->field_0x15c = 0;
        puVar13 = (undefined *)0x0;
        *(undefined4 *)&this->field_0x16c = 0;
        *(undefined4 *)&this->field_0x168 = 0;
        iVar3 = this->field_0x154;
        if (iVar3 == 3) {
          puVar13 = &d_timer::VolcanoSeTable;
        }
        else {
          if ((iVar3 < 3) && (1 < iVar3)) {
            puVar13 = &d_timer::ShipRaceSeTable;
          }
        }
        if (puVar13 != (undefined *)0x0) {
          while (-1 < *(int *)&this->field_0x168) {
            *(undefined4 *)&this->field_0x168 =
                 *(undefined4 *)(puVar13 + *(int *)&this->field_0x16c * 8);
            iVar3 = getRestTimeMs(this);
            if (*(int *)&this->field_0x168 < iVar3) break;
            *(int *)&this->field_0x16c = *(int *)&this->field_0x16c + 1;
          }
        }
        PVar4 = cPhs_COMPLEATE_e;
      }
    }
  }
  return PVar4;
}


/* __thiscall dTimer_c::_execute(void) */

undefined4 __thiscall dTimer_c::_execute(dTimer_c *this)

{
  char cVar1;
  short sVar2;
  byte bVar4;
  int iVar3;
  undefined4 uVar5;
  undefined8 uVar6;
  
  if (*(char *)&this->field_0x162 != '\x01') {
    uVar6 = getRestTimeMs(this);
    uVar5 = (undefined4)uVar6;
    *(int *)&this->field_0x150 = (int)((ulonglong)uVar6 >> 0x20);
    cVar1 = *(char *)&this->field_0x164;
    if (((cVar1 == '\0') || (cVar1 == '\x01')) || (cVar1 == '\x03')) {
      *(undefined4 *)&this->field_0x114 = 0;
      *(undefined4 *)&this->field_0x110 = 0;
      *(undefined4 *)&this->field_0x11c = 0;
      *(undefined4 *)&this->field_0x118 = 0;
      if ((*(char *)&this->field_0x164 == '\x01') || (*(char *)&this->field_0x164 == '\x03')) {
        sVar2 = *(short *)&this->field_0x160 + -1;
        *(short *)&this->field_0x160 = sVar2;
        if (sVar2 < 1) {
          if (*(char *)&this->field_0x164 == '\x03') {
            stock_start(this);
          }
          else {
            start(this);
          }
        }
      }
    }
    else {
      if (cVar1 == '\x02') {
        iVar3 = os::OSGetTime();
        *(undefined4 *)&this->field_0x11c = uVar5;
        *(int *)&this->field_0x118 = iVar3;
        d_com_inf_game::g_dComIfG_gameInfo._23780_4_ = getTimeMs(this);
        d_com_inf_game::g_dComIfG_gameInfo._23784_4_ = getLimitTimeMs(this);
        iVar3 = getRestTimeMs(this);
        if (iVar3 < 1) {
          *(uint *)&this->field_0x11c = *(uint *)&this->field_0x144 + *(uint *)&this->field_0x114;
          *(uint *)&this->field_0x118 =
               *(int *)&this->field_0x140 +
               *(int *)&this->field_0x110 +
               (uint)CARRY4(*(uint *)&this->field_0x144,*(uint *)&this->field_0x114);
          *(undefined4 *)&this->field_0x13c = 0;
          *(undefined4 *)&this->field_0x138 = 0;
          d_com_inf_game::g_dComIfG_gameInfo._23780_4_ = getTimeMs(this);
          if (this->field_0x154 == 3) {
            end(this,0x1e);
          }
        }
      }
      else {
        *(undefined4 *)&this->field_0x11c = *(undefined4 *)&this->field_0x124;
        *(undefined4 *)&this->field_0x118 = *(undefined4 *)&this->field_0x120;
      }
    }
  }
  cVar1 = *(char *)&this->field_0x164;
  if ((cVar1 == '\0') || (cVar1 == '\x02')) {
    if ((this->field_0x154 == 3) || (this->field_0x154 == 2)) {
      bVar4 = d_meter::dMenu_flag();
      if ((bVar4 == 0) && (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode != 1)) {
        restart(this,'\x01');
      }
      else {
        stop(this,'\x01');
      }
    }
  }
  else {
    if (cVar1 == '\x06') {
      iVar3 = dDlst_TimerScrnDraw_c::closeAnime(this->mpScrnDraw);
      if (iVar3 != 0) {
        f_op_msg_mng::fopMsgM_Delete(this);
      }
    }
    else {
      if ((cVar1 != '\x05') && (cVar1 == '\x04')) {
        if (*(int *)&this->field_0x158 < 1) {
          if (this->field_0x154 == 3) {
            deleteRequest(this);
            this->mpScrnDraw->field_0x234 = 0;
          }
          else {
            this->mpScrnDraw->field_0x234 = 0;
            *(undefined *)&this->field_0x164 = 5;
          }
        }
        else {
          *(int *)&this->field_0x158 = *(int *)&this->field_0x158 + -1;
        }
      }
    }
  }
  if (*(int *)&this->field_0x15c < 6) {
    *(int *)&this->field_0x15c = *(int *)&this->field_0x15c + 1;
  }
  else {
    dDlst_TimerScrnDraw_c::anime(this->mpScrnDraw);
  }
  iVar3 = getRestTimeMs(this);
  dDlst_TimerScrnDraw_c::setTimer(this->mpScrnDraw,iVar3);
  dDlst_TimerScrnDraw_c::setRupee(this->mpScrnDraw,d_com_inf_game::g_dComIfG_gameInfo._23772_2_);
  SetSE(this);
  return 1;
}


/* __thiscall dTimer_c::_draw(void) */

undefined4 __thiscall dTimer_c::_draw(dTimer_c *this)

{
  byte bVar1;
  
  bVar1 = d_meter::dMenu_flag();
  if (bVar1 == 0) {
    dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                      &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                      &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                      &this->mpScrnDraw->parent);
  }
  return 1;
}


/* __thiscall dTimer_c::_delete(void) */

undefined4 __thiscall dTimer_c::_delete(dTimer_c *this)

{
  char cVar1;
  
  if (this->mpSolidHeap != (JKRHeap *)0x0) {
    m_Do_ext::mDoExt_destroySolidHeap();
  }
  if ((((this->field_0x154 == 3) && (cVar1 = *(char *)&this->field_0x164, cVar1 != '\x06')) &&
      (cVar1 != '\x05')) && (cVar1 != '\x04')) {
    d_com_inf_game::g_dComIfG_gameInfo._23780_4_ = getTimeMs(this);
    d_com_inf_game::g_dComIfG_gameInfo._23784_4_ = getLimitTimeMs(this);
    d_com_inf_game::g_dComIfG_gameInfo._23788_4_ = this->field_0x154;
  }
  else {
    d_com_inf_game::g_dComIfG_gameInfo._23780_4_ = 0;
    d_com_inf_game::g_dComIfG_gameInfo._23784_4_ = 0;
    d_com_inf_game::g_dComIfG_gameInfo._23788_4_ = -1;
  }
  d_com_inf_game::g_dComIfG_gameInfo.mpRestartTimer = (dTimer_c *)0x0;
  d_com_inf_game::dComIfG_resDelete(&this->mPhs,"Timer");
  return 1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dTimer_c::RestTimeCheck(int) */

undefined4 __thiscall dTimer_c::RestTimeCheck(dTimer_c *this,int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = getRestTimeMs(this);
  if ((iVar1 <= param_1) && (*(int *)&this->field_0x150 < param_1)) {
    uVar2 = 1;
  }
  return uVar2;
}


/* __thiscall dTimer_c::deleteCheck(void) */

uint __thiscall dTimer_c::deleteCheck(dTimer_c *this)

{
  uint uVar1;
  
  uVar1 = countLeadingZeros(5 - (uint)*(byte *)&this->field_0x164);
  return uVar1 >> 5 & 0xff;
}


/* __thiscall dTimer_c::SetSE(void) */

void __thiscall dTimer_c::SetSE(dTimer_c *this)

{
  undefined *puVar1;
  int iVar2;
  
  if (((*(char *)&this->field_0x162 == '\0') && (this->field_0x154 != 4)) &&
     (iVar2 = getRestTimeMs(this), iVar2 / 1000 < *(int *)&this->field_0x150 / 1000)) {
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x8ea,(cXyz *)0x0,0,0,d_timer::_4227,d_timer::_4227,
               d_timer::_4228,d_timer::_4228,0);
  }
  iVar2 = RestTimeCheck(this,*(int *)&this->field_0x168);
  if (iVar2 != 0) {
    iVar2 = this->field_0x154;
    if (iVar2 == 3) {
      puVar1 = &d_timer::VolcanoSeTable;
    }
    else {
      if (2 < iVar2) {
        return;
      }
      if (iVar2 < 2) {
        return;
      }
      puVar1 = &d_timer::ShipRaceSeTable;
    }
    if (*(ulong *)(puVar1 + *(int *)&this->field_0x16c * 8 + 4) != 0xffffffff) {
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,*(ulong *)(puVar1 + *(int *)&this->field_0x16c * 8 + 4),
                 (cXyz *)0x0,0,0,d_timer::_4227,d_timer::_4227,d_timer::_4228,d_timer::_4228,0);
      *(int *)&this->field_0x16c = *(int *)&this->field_0x16c + 1;
      *(undefined4 *)&this->field_0x168 = *(undefined4 *)(puVar1 + *(int *)&this->field_0x16c * 8);
    }
  }
  return;
}


/* __thiscall dTimer_c::start(void) */

undefined4 __thiscall dTimer_c::start(dTimer_c *this)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 in_r4;
  
  if ((*(char *)&this->field_0x164 == '\0') || (*(char *)&this->field_0x164 == '\x01')) {
    *(undefined *)&this->field_0x164 = 2;
    iVar1 = os::OSGetTime();
    *(undefined4 *)&this->field_0x114 = in_r4;
    *(int *)&this->field_0x110 = iVar1;
    *(undefined4 *)&this->field_0x11c = in_r4;
    *(int *)&this->field_0x118 = iVar1;
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


/* __thiscall dTimer_c::start(short) */

undefined4 __thiscall dTimer_c::start(dTimer_c *this,short param_1)

{
  if (*(char *)&this->field_0x164 == '\0') {
    *(short *)&this->field_0x160 = param_1;
    *(undefined *)&this->field_0x164 = 1;
    return 1;
  }
  return 0;
}


/* __thiscall dTimer_c::stock_start(void) */

bool __thiscall dTimer_c::stock_start(dTimer_c *this)

{
  bool bVar1;
  ulonglong uVar2;
  int iVar3;
  undefined4 in_r4;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  bVar1 = *(char *)&this->field_0x164 == '\x03';
  if (bVar1) {
    *(undefined *)&this->field_0x164 = 2;
    iVar3 = os::OSGetTime();
    *(undefined4 *)&this->field_0x114 = in_r4;
    *(int *)&this->field_0x110 = iVar3;
    *(undefined4 *)&this->field_0x11c = in_r4;
    *(int *)&this->field_0x118 = iVar3;
    uVar6 = *(uint *)&this->field_0x114;
    uVar5 = (DAT_800000f8 >> 2) / 1000;
    iVar3 = (int)d_com_inf_game::g_dComIfG_gameInfo._23780_4_ >> 0x1f;
    uVar2 = (ulonglong)d_com_inf_game::g_dComIfG_gameInfo._23780_4_;
    uVar4 = uVar5 * d_com_inf_game::g_dComIfG_gameInfo._23780_4_;
    *(uint *)&this->field_0x114 = uVar6 - uVar4;
    *(uint *)&this->field_0x110 =
         *(int *)&this->field_0x110 -
         ((uint)(uVar6 < uVar4) + (int)(uVar5 * uVar2 >> 0x20) + uVar5 * iVar3);
  }
  return bVar1;
}


/* __thiscall dTimer_c::stock_start(short) */

undefined4 __thiscall dTimer_c::stock_start(dTimer_c *this,short param_1)

{
  if (*(char *)&this->field_0x164 == '\0') {
    *(short *)&this->field_0x160 = param_1;
    *(undefined *)&this->field_0x164 = 3;
    return 1;
  }
  return 0;
}


/* __thiscall dTimer_c::stop(unsigned char) */

undefined4 __thiscall dTimer_c::stop(dTimer_c *this,uchar param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined3 in_register_00000010;
  
  uVar1 = CONCAT31(in_register_00000010,param_1);
  if ((*(char *)&this->field_0x162 == '\x01') || (*(char *)&this->field_0x163 != '\0')) {
    uVar1 = 0;
  }
  else {
    if (*(char *)&this->field_0x164 == '\x02') {
      iVar2 = os::OSGetTime();
      *(undefined4 *)&this->field_0x134 = uVar1;
      *(int *)&this->field_0x130 = iVar2;
      *(undefined *)&this->field_0x162 = 1;
      *(uchar *)&this->field_0x163 = param_1;
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}


/* __thiscall dTimer_c::restart(unsigned char) */

undefined4 __thiscall dTimer_c::restart(dTimer_c *this,uchar param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined3 in_register_00000010;
  uint uVar4;
  
  uVar1 = CONCAT31(in_register_00000010,param_1);
  if ((*(char *)&this->field_0x162 == '\x01') && (*(uchar *)&this->field_0x163 == param_1)) {
    if (*(char *)&this->field_0x164 == '\x02') {
      iVar2 = os::OSGetTime();
      *(undefined4 *)&this->field_0x11c = uVar1;
      *(int *)&this->field_0x118 = iVar2;
      uVar4 = *(uint *)&this->field_0x13c;
      uVar3 = *(uint *)&this->field_0x11c - *(uint *)&this->field_0x134;
      *(uint *)&this->field_0x13c = uVar4 + uVar3;
      *(uint *)&this->field_0x138 =
           *(int *)&this->field_0x138 +
           (*(int *)&this->field_0x118 -
           ((uint)(*(uint *)&this->field_0x11c < *(uint *)&this->field_0x134) +
           *(int *)&this->field_0x130)) + (uint)CARRY4(uVar4,uVar3);
      *(undefined *)&this->field_0x162 = 0;
      *(undefined *)&this->field_0x163 = 0;
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


/* __thiscall dTimer_c::end(int) */

undefined4 __thiscall dTimer_c::end(dTimer_c *this,int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if (*(char *)&this->field_0x164 == '\x02') {
    iVar3 = param_1;
    iVar2 = os::OSGetTime();
    *(int *)&this->field_0x124 = iVar3;
    *(int *)&this->field_0x120 = iVar2;
    *(undefined *)&this->field_0x164 = 4;
    if (param_1 != -1) {
      *(int *)&this->field_0x158 = param_1;
    }
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


/* __thiscall dTimer_c::deleteRequest(void) */

undefined4 __thiscall dTimer_c::deleteRequest(dTimer_c *this)

{
  *(undefined *)&this->field_0x164 = 6;
  return 1;
}


/* __thiscall dTimer_c::getTimeMs(void) */

undefined4 __thiscall dTimer_c::getTimeMs(dTimer_c *this)

{
  uint uVar1;
  undefined4 extraout_r4;
  
  uVar1 = *(uint *)&this->field_0x11c - *(uint *)&this->field_0x114;
  Runtime.PPCEABI.H::__div2i
            ((*(int *)&this->field_0x118 -
             ((uint)(*(uint *)&this->field_0x11c < *(uint *)&this->field_0x114) +
             *(int *)&this->field_0x110)) -
             ((uint)(uVar1 < *(uint *)&this->field_0x13c) + *(int *)&this->field_0x138),
             uVar1 - *(uint *)&this->field_0x13c,0,(DAT_800000f8 >> 2) / 1000);
  return extraout_r4;
}


/* __thiscall dTimer_c::getLimitTimeMs(void) */

undefined4 __thiscall dTimer_c::getLimitTimeMs(dTimer_c *this)

{
  undefined4 extraout_r4;
  
  Runtime.PPCEABI.H::__div2i
            (*(undefined4 *)&this->field_0x140,*(undefined4 *)&this->field_0x144,0,
             (DAT_800000f8 >> 2) / 1000);
  return extraout_r4;
}


/* __thiscall dTimer_c::getRestTimeMs(void) */

undefined4 __thiscall dTimer_c::getRestTimeMs(dTimer_c *this)

{
  uint uVar1;
  undefined4 extraout_r4;
  uint uVar2;
  
  uVar2 = *(uint *)&this->field_0x11c - *(uint *)&this->field_0x114;
  uVar1 = uVar2 - *(uint *)&this->field_0x13c;
  Runtime.PPCEABI.H::__div2i
            (*(int *)&this->field_0x140 -
             ((uint)(*(uint *)&this->field_0x144 < uVar1) +
             ((*(int *)&this->field_0x118 -
              ((uint)(*(uint *)&this->field_0x11c < *(uint *)&this->field_0x114) +
              *(int *)&this->field_0x110)) -
             ((uint)(uVar2 < *(uint *)&this->field_0x13c) + *(int *)&this->field_0x138))),
             *(uint *)&this->field_0x144 - uVar1,0,(DAT_800000f8 >> 2) / 1000);
  return extraout_r4;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dDlst_TimerScrnDraw_c::setScreen(char const *,
                                               JKRArchive *) */

void __thiscall
dDlst_TimerScrnDraw_c::setScreen(dDlst_TimerScrnDraw_c *this,char *param_1,JKRArchive *param_2)

{
  J2DScreen *pJVar1;
  J2DPane *pJVar2;
  TBox2_float_ local_28;
  
  pJVar1 = (J2DScreen *)JKernel::operator_new(0xd4);
  if (pJVar1 != (J2DScreen *)0x0) {
    local_28.mTL.x = d_timer::0_0;
    local_28.mTL.y = d_timer::0_0;
    local_28.mBR.x = d_timer::640_0;
    local_28.mBR.y = d_timer::480_0;
    J2DPane::J2DPane((J2DPane *)pJVar1,(J2DPane *)0x0,true,0x726f6f74,&local_28);
    (pJVar1->parent).vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
    pJVar1->field_0xd0 = (_GXColor)0xffffffff;
    pJVar1->mbClipToParent = 0;
  }
  this->mpScreen = pJVar1;
  J2DScreen::set(this->mpScreen,param_1,param_2);
  this->field_0x22c = (J2DPicture *)0x0;
  pJVar1 = (J2DScreen *)
           (*(code *)((this->mpScreen->parent).vtbl)->search)(this->mpScreen,0x74696d30);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x8,pJVar1);
  pJVar1 = (J2DScreen *)
           (*(code *)((this->mpScreen->parent).vtbl)->search)(this->mpScreen,0x636e3030);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x40,pJVar1);
  pJVar1 = (J2DScreen *)
           (*(code *)((this->mpScreen->parent).vtbl)->search)(this->mpScreen,0x74743031);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x78,pJVar1);
  pJVar1 = (J2DScreen *)
           (*(code *)((this->mpScreen->parent).vtbl)->search)(this->mpScreen,0x746e3031);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0xb0,pJVar1);
  pJVar1 = (J2DScreen *)
           (*(code *)((this->mpScreen->parent).vtbl)->search)(this->mpScreen,0x746e3030);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0xe8,pJVar1);
  pJVar1 = (J2DScreen *)
           (*(code *)((this->mpScreen->parent).vtbl)->search)(this->mpScreen,0x746b3030);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x120,pJVar1);
  pJVar1 = (J2DScreen *)(*(code *)((this->mpScreen->parent).vtbl)->search)(this->mpScreen,0x727570);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x158,pJVar1);
  pJVar1 = (J2DScreen *)
           (*(code *)((this->mpScreen->parent).vtbl)->search)(this->mpScreen,0x7275786b);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x190,pJVar1);
  pJVar1 = (J2DScreen *)
           (*(code *)((this->mpScreen->parent).vtbl)->search)(this->mpScreen,0x7275706b);
  f_op_msg_mng::fopMsgM_setPaneData(&this->field_0x1c8,pJVar1);
  pJVar2 = (J2DPane *)(*(code *)((this->mpScreen->parent).vtbl)->search)(this->mpScreen,0x74743032);
  this->field_0x200 = pJVar2;
  pJVar2 = (J2DPane *)(*(code *)((this->mpScreen->parent).vtbl)->search)(this->mpScreen,0x74743033);
  this->field_0x204 = pJVar2;
  pJVar2 = (J2DPane *)(*(code *)((this->mpScreen->parent).vtbl)->search)(this->mpScreen,0x74743034);
  this->field_0x208 = pJVar2;
  pJVar2 = (J2DPane *)(*(code *)((this->mpScreen->parent).vtbl)->search)(this->mpScreen,0x74743035);
  this->field_0x20c = pJVar2;
  pJVar2 = (J2DPane *)(*(code *)((this->mpScreen->parent).vtbl)->search)(this->mpScreen,0x74743036);
  this->field_0x210 = pJVar2;
  pJVar2 = (J2DPane *)(*(code *)((this->mpScreen->parent).vtbl)->search)(this->mpScreen,0x727531);
  this->field_0x214 = pJVar2;
  pJVar2 = (J2DPane *)(*(code *)((this->mpScreen->parent).vtbl)->search)(this->mpScreen,0x727532);
  this->field_0x218 = pJVar2;
  pJVar2 = (J2DPane *)(*(code *)((this->mpScreen->parent).vtbl)->search)(this->mpScreen,0x727533);
  this->field_0x21c = pJVar2;
  pJVar2 = (J2DPane *)(*(code *)((this->mpScreen->parent).vtbl)->search)(this->mpScreen,0x72756b31);
  this->field_0x220 = pJVar2;
  pJVar2 = (J2DPane *)(*(code *)((this->mpScreen->parent).vtbl)->search)(this->mpScreen,0x72756b32);
  this->field_0x224 = pJVar2;
  pJVar2 = (J2DPane *)(*(code *)((this->mpScreen->parent).vtbl)->search)(this->mpScreen,0x72756b33);
  this->field_0x228 = pJVar2;
  setShowType(this,3);
  return;
}


/* __thiscall dDlst_TimerScrnDraw_c::changeNumberTexture(J2DPane *,
                                                         int) */

void __thiscall
dDlst_TimerScrnDraw_c::changeNumberTexture(dDlst_TimerScrnDraw_c *this,J2DPane *param_1,int param_2)

{
  char *pcVar1;
  
  if ((param_2 < 0) || (9 < param_2)) {
    param_2 = 0;
  }
  pcVar1 = (char *)getNumber(this,param_2);
  J2DPicture::changeTexture((J2DPicture *)param_1,pcVar1,0);
  return;
}


/* __thiscall dDlst_TimerScrnDraw_c::getNumber(int) */

undefined * __thiscall dDlst_TimerScrnDraw_c::getNumber(dDlst_TimerScrnDraw_c *this,int param_1)

{
  return (&d_timer::number_4344)[param_1];
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x8023ccb8) */
/* __thiscall dDlst_TimerScrnDraw_c::setTimer(int) */

void __thiscall dDlst_TimerScrnDraw_c::setTimer(dDlst_TimerScrnDraw_c *this,int param_1)

{
  short sVar1;
  float fVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined8 in_f31;
  double dVar7;
  undefined auStack8 [8];
  
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  iVar4 = (param_1 / 1000) / 0x3c;
  iVar5 = (param_1 / 1000) % 0x3c;
  changeNumberTexture(this,&((this->field_0x78).mpPane)->parent,iVar4 / 10);
  changeNumberTexture(this,this->field_0x200,iVar4 % 10);
  changeNumberTexture(this,this->field_0x204,iVar5 / 10);
  changeNumberTexture(this,this->field_0x208,iVar5 % 10);
  changeNumberTexture(this,this->field_0x20c,(param_1 % 1000) / 100);
  changeNumberTexture(this,this->field_0x210,((param_1 % 1000) % 100) / 10);
  if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode == 1) {
    sVar1 = (this->field_0x8).mUserData;
    if (sVar1 < 5) {
      (this->field_0x8).mUserData = sVar1 + 1;
      uVar3 = (int)(short)(5 - (this->field_0x8).mUserData) ^ 0x80000000;
      fVar2 = ((float)((double)CONCAT44(0x43300000,uVar3) - d_timer::_4368) *
              (float)((double)CONCAT44(0x43300000,uVar3) - d_timer::_4368)) / d_timer::_4366;
      dVar7 = (double)fVar2;
      f_op_msg_mng::fopMsgM_setNowAlpha(&this->field_0x8,fVar2);
      f_op_msg_mng::fopMsgM_setNowAlpha(&this->field_0x40,(float)dVar7);
      f_op_msg_mng::fopMsgM_setNowAlpha(&this->field_0x78,(float)dVar7);
      f_op_msg_mng::fopMsgM_setNowAlpha(&this->field_0xb0,(float)dVar7);
      f_op_msg_mng::fopMsgM_setNowAlpha(&this->field_0xe8,(float)dVar7);
      f_op_msg_mng::fopMsgM_setNowAlpha(&this->field_0x120,(float)dVar7);
    }
  }
  else {
    sVar1 = (this->field_0x8).mUserData;
    if (0 < sVar1) {
      (this->field_0x8).mUserData = sVar1 + -1;
      uVar3 = (int)(short)(5 - (this->field_0x8).mUserData) ^ 0x80000000;
      fVar2 = ((float)((double)CONCAT44(0x43300000,uVar3) - d_timer::_4368) *
              (float)((double)CONCAT44(0x43300000,uVar3) - d_timer::_4368)) / d_timer::_4366;
      dVar7 = (double)fVar2;
      f_op_msg_mng::fopMsgM_setNowAlpha(&this->field_0x8,fVar2);
      f_op_msg_mng::fopMsgM_setNowAlpha(&this->field_0x40,(float)dVar7);
      f_op_msg_mng::fopMsgM_setNowAlpha(&this->field_0x78,(float)dVar7);
      f_op_msg_mng::fopMsgM_setNowAlpha(&this->field_0xb0,(float)dVar7);
      f_op_msg_mng::fopMsgM_setNowAlpha(&this->field_0xe8,(float)dVar7);
      f_op_msg_mng::fopMsgM_setNowAlpha(&this->field_0x120,(float)dVar7);
    }
  }
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x8023ced0) */
/* __thiscall dDlst_TimerScrnDraw_c::setRupee(short) */

void __thiscall dDlst_TimerScrnDraw_c::setRupee(dDlst_TimerScrnDraw_c *this,short param_1)

{
  short sVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined8 in_f31;
  double dVar7;
  undefined auStack8 [8];
  
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  iVar3 = *(int *)&this->field_0x230;
  if (param_1 != iVar3) {
    if (param_1 < iVar3) {
      *(int *)&this->field_0x230 = iVar3 + -1;
    }
    else {
      *(int *)&this->field_0x230 = iVar3 + 1;
    }
    if (*(int *)&this->field_0x230 < 0) {
      *(undefined4 *)&this->field_0x230 = 0;
    }
    iVar3 = *(int *)&this->field_0x230;
    iVar5 = (iVar3 % 100) / 10;
    changeNumberTexture(this,this->field_0x21c,iVar3 % 10);
    changeNumberTexture(this,this->field_0x218,iVar5);
    changeNumberTexture(this,this->field_0x214,iVar3 / 100);
    changeNumberTexture(this,this->field_0x228,iVar3 % 10);
    changeNumberTexture(this,this->field_0x224,iVar5);
    changeNumberTexture(this,this->field_0x220,iVar3 / 100);
  }
  if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode == 1) {
    sVar1 = (this->field_0x158).mUserData;
    if (sVar1 < 5) {
      (this->field_0x158).mUserData = sVar1 + 1;
      uVar4 = (int)(this->field_0x158).mUserData ^ 0x80000000;
      fVar2 = d_timer::_4227 -
              ((float)((double)CONCAT44(0x43300000,uVar4) - d_timer::_4368) *
              (float)((double)CONCAT44(0x43300000,uVar4) - d_timer::_4368)) / d_timer::_4366;
      dVar7 = (double)fVar2;
      f_op_msg_mng::fopMsgM_setNowAlpha(&this->field_0x158,fVar2);
      f_op_msg_mng::fopMsgM_setNowAlpha(&this->field_0x190,(float)dVar7);
      f_op_msg_mng::fopMsgM_setNowAlpha(&this->field_0x1c8,(float)dVar7);
    }
  }
  else {
    sVar1 = (this->field_0x158).mUserData;
    if (0 < sVar1) {
      (this->field_0x158).mUserData = sVar1 + -1;
      uVar4 = (int)(this->field_0x158).mUserData ^ 0x80000000;
      fVar2 = d_timer::_4227 -
              ((float)((double)CONCAT44(0x43300000,uVar4) - d_timer::_4368) *
              (float)((double)CONCAT44(0x43300000,uVar4) - d_timer::_4368)) / d_timer::_4366;
      dVar7 = (double)fVar2;
      f_op_msg_mng::fopMsgM_setNowAlpha(&this->field_0x158,fVar2);
      f_op_msg_mng::fopMsgM_setNowAlpha(&this->field_0x190,(float)dVar7);
      f_op_msg_mng::fopMsgM_setNowAlpha(&this->field_0x1c8,(float)dVar7);
    }
  }
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  return;
}


namespace d_timer {

/* __stdcall dTm_parentPaneScale(fopMsgM_pane_class *,
                                 fopMsgM_pane_class *,
                                 float) */

void dTm_parentPaneScale
               (fopMsgM_pane_class *param_1,fopMsgM_pane_class *param_2,double param_3)

{
  (param_1->mPosCenter).x =
       (param_2->mPosCenter).x +
       (float)(param_3 * (double)((param_1->mPosCenterOrig).x - (param_2->mPosCenterOrig).x));
  (param_1->mPosCenter).y =
       (param_2->mPosCenter).y +
       (float)(param_3 * (double)((param_1->mPosCenterOrig).y - (param_2->mPosCenterOrig).y));
  f_op_msg_mng::fopMsgM_paneScaleXY(param_1,(float)param_3);
  return;
}

}

/* __thiscall dDlst_TimerScrnDraw_c::setPaneInitialPos(fopMsgM_pane_class *,
                                                       float,
                                                       float) */

void __thiscall
dDlst_TimerScrnDraw_c::setPaneInitialPos
          (dDlst_TimerScrnDraw_c *this,fopMsgM_pane_class *param_1,float param_2,float param_3)

{
  float fVar1;
  
  fVar1 = d_timer::_4410;
  (param_1->mPosCenterOrig).x = param_2 + (param_1->mSizeOrig).x * d_timer::_4410;
  (param_1->mPosCenterOrig).y = param_3 + (param_1->mSizeOrig).y * fVar1;
  f_op_msg_mng::fopMsgM_paneTrans(param_1,(double)d_timer::0_0,(double)d_timer::0_0);
  return;
}


/* WARNING: Removing unreachable block (ram,0x8023d0a8) */
/* WARNING: Removing unreachable block (ram,0x8023d0b0) */
/* __thiscall dDlst_TimerScrnDraw_c::setTimerPos(float,
                                                 float) */

void __thiscall
dDlst_TimerScrnDraw_c::setTimerPos(dDlst_TimerScrnDraw_c *this,float param_1,float param_2)

{
  undefined4 uVar1;
  double dVar2;
  double dVar3;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar3 = (double)param_2;
  dVar2 = (double)param_1;
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  setPaneInitialPos(this,&this->field_0x8,param_1,param_2);
  setPaneInitialPos(this,&this->field_0x40,
                    (float)(dVar2 + (double)(this->field_0x40).mPosTopLeftOrig.x) -
                    (this->field_0x8).mPosTopLeftOrig.x,
                    (float)(dVar3 + (double)(this->field_0x40).mPosTopLeftOrig.y) -
                    (this->field_0x8).mPosTopLeftOrig.y);
  setPaneInitialPos(this,&this->field_0x78,
                    (float)(dVar2 + (double)(this->field_0x78).mPosTopLeftOrig.x) -
                    (this->field_0x8).mPosTopLeftOrig.x,
                    (float)(dVar3 + (double)(this->field_0x78).mPosTopLeftOrig.y) -
                    (this->field_0x8).mPosTopLeftOrig.y);
  setPaneInitialPos(this,&this->field_0xb0,
                    (float)(dVar2 + (double)(this->field_0xb0).mPosTopLeftOrig.x) -
                    (this->field_0x8).mPosTopLeftOrig.x,
                    (float)(dVar3 + (double)(this->field_0xb0).mPosTopLeftOrig.y) -
                    (this->field_0x8).mPosTopLeftOrig.y);
  setPaneInitialPos(this,&this->field_0xe8,
                    (float)(dVar2 + (double)(this->field_0xe8).mPosTopLeftOrig.x) -
                    (this->field_0x8).mPosTopLeftOrig.x,
                    (float)(dVar3 + (double)(this->field_0xe8).mPosTopLeftOrig.y) -
                    (this->field_0x8).mPosTopLeftOrig.y);
  setPaneInitialPos(this,&this->field_0x120,
                    (float)(dVar2 + (double)(this->field_0x120).mPosTopLeftOrig.x) -
                    (this->field_0x8).mPosTopLeftOrig.x,
                    (float)(dVar3 + (double)(this->field_0x120).mPosTopLeftOrig.y) -
                    (this->field_0x8).mPosTopLeftOrig.y);
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  __psq_l0(auStack24,uVar1);
  __psq_l1(auStack24,uVar1);
  return;
}


/* __thiscall dDlst_TimerScrnDraw_c::setRupeePos(float,
                                                 float) */

void __thiscall
dDlst_TimerScrnDraw_c::setRupeePos(dDlst_TimerScrnDraw_c *this,float param_1,float param_2)

{
  double dVar1;
  double dVar2;
  
  dVar2 = (double)param_2;
  dVar1 = (double)param_1;
  setPaneInitialPos(this,&this->field_0x158,param_1,param_2);
  setPaneInitialPos(this,&this->field_0x1c8,(float)dVar1,(float)dVar2);
  return;
}


/* __thiscall dDlst_TimerScrnDraw_c::setShowType(unsigned char) */

void __thiscall dDlst_TimerScrnDraw_c::setShowType(dDlst_TimerScrnDraw_c *this,byte param_1)

{
  if ((param_1 & 1) == 0) {
    (((this->field_0x8).mpPane)->parent).mbDraw = 0;
    (((this->field_0x40).mpPane)->parent).mbDraw = 0;
    (((this->field_0x78).mpPane)->parent).mbDraw = 0;
    (((this->field_0xb0).mpPane)->parent).mbDraw = 0;
    (((this->field_0xe8).mpPane)->parent).mbDraw = 0;
    (((this->field_0x120).mpPane)->parent).mbDraw = 0;
  }
  else {
    (((this->field_0x8).mpPane)->parent).mbDraw = 1;
    (((this->field_0x40).mpPane)->parent).mbDraw = 1;
    (((this->field_0x78).mpPane)->parent).mbDraw = 1;
    (((this->field_0xb0).mpPane)->parent).mbDraw = 1;
    (((this->field_0xe8).mpPane)->parent).mbDraw = 1;
    (((this->field_0x120).mpPane)->parent).mbDraw = 1;
  }
  if ((param_1 & 2) != 0) {
    (((this->field_0x158).mpPane)->parent).mbDraw = 1;
    (((this->field_0x1c8).mpPane)->parent).mbDraw = 1;
    if (this->field_0x22c == (J2DPicture *)0x0) {
      return;
    }
    (this->field_0x22c->parent).mbDraw = 1;
    return;
  }
  (((this->field_0x158).mpPane)->parent).mbDraw = 0;
  (((this->field_0x1c8).mpPane)->parent).mbDraw = 0;
  if (this->field_0x22c == (J2DPicture *)0x0) {
    return;
  }
  (this->field_0x22c->parent).mbDraw = 0;
  return;
}


/* WARNING: Removing unreachable block (ram,0x8023d22c) */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall dDlst_TimerScrnDraw_c::setIconType(void *,
                                                 unsigned char) */

void __thiscall
dDlst_TimerScrnDraw_c::setIconType(dDlst_TimerScrnDraw_c *this,void *param_1,uchar param_2)

{
  J2DPicture *this_00;
  J2DScreen *pJVar1;
  void *pvVar2;
  
  if (param_2 == '\x04') {
    pvVar2 = (void *)0x98;
  }
  else {
    pvVar2 = param_1;
    if (param_2 < 4) {
      pvVar2 = (void *)(uint)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                             mEquippedSword;
    }
  }
  JKRArchive::readTypeResource
            (param_1,0xc00,0x54494d47,dItem_data::item_resource[(uint)pvVar2 & 0xff].mIconFilename,
             d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpItemIconArchive);
  this_00 = (J2DPicture *)JKernel::operator_new(0x124);
  if (this_00 != (J2DPicture *)0x0) {
    J2DPicture::J2DPicture(this_00,(ResTIMG *)param_1);
  }
  this->field_0x22c = this_00;
  pJVar1 = (this->field_0x158).mpPane;
  *(undefined *)&pJVar1[1].parent.mBox.mTL.y = 0;
  *(undefined *)((int)&pJVar1[1].parent.mBox.mTL.y + 1) = 0;
  *(undefined *)((int)&pJVar1[1].parent.mBox.mTL.y + 2) = 0;
  *(undefined *)((int)&pJVar1[1].parent.mBox.mTL.y + 3) = 0;
  pJVar1 = (this->field_0x1c8).mpPane;
  *(undefined *)&pJVar1[1].parent.mBox.mTL.y = 0;
  *(undefined *)((int)&pJVar1[1].parent.mBox.mTL.y + 1) = 0;
  *(undefined *)((int)&pJVar1[1].parent.mBox.mTL.y + 2) = 0;
  *(undefined *)((int)&pJVar1[1].parent.mBox.mTL.y + 3) = 0;
  (this->field_0x22c->parent).mAlpha = 0;
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x8023d61c) */
/* WARNING: Removing unreachable block (ram,0x8023d624) */
/* __thiscall dDlst_TimerScrnDraw_c::anime(void) */

void __thiscall dDlst_TimerScrnDraw_c::anime(dDlst_TimerScrnDraw_c *this)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined8 in_f30;
  double dVar5;
  undefined8 in_f31;
  double dVar6;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  if (this->field_0x235 == 0) {
    if ((int)(char)this->field_0x234 < (int)d_timer::animeFrame_4519[2]) {
      this->field_0x234 = this->field_0x234 + 1;
    }
    else {
      this->field_0x235 = 1;
    }
    if ((int)(char)this->field_0x234 <= (int)d_timer::animeFrame_4519[1]) {
      uVar2 = (int)(char)this->field_0x234 ^ 0x80000000;
      uVar3 = (int)d_timer::animeFrame_4519[1] ^ 0x80000000;
      dVar6 = (double)(((float)((double)CONCAT44(0x43300000,uVar2) - d_timer::_4368) *
                       (float)((double)CONCAT44(0x43300000,uVar2) - d_timer::_4368)) /
                      ((float)((double)CONCAT44(0x43300000,uVar3) - d_timer::_4368) *
                      (float)((double)CONCAT44(0x43300000,uVar3) - d_timer::_4368)));
      dVar5 = (double)(d_timer::_4550 * (float)((double)d_timer::_4227 - dVar6));
      f_op_msg_mng::fopMsgM_paneTrans(&this->field_0x8,dVar5,(double)d_timer::0_0);
      f_op_msg_mng::fopMsgM_paneTrans(&this->field_0x40,dVar5,(double)d_timer::0_0);
      f_op_msg_mng::fopMsgM_paneTrans(&this->field_0xb0,dVar5,(double)d_timer::0_0);
      f_op_msg_mng::fopMsgM_paneTrans(&this->field_0xe8,dVar5,(double)d_timer::0_0);
      f_op_msg_mng::fopMsgM_paneTrans(&this->field_0x120,dVar5,(double)d_timer::0_0);
      f_op_msg_mng::fopMsgM_setNowAlpha(&this->field_0x8,(float)dVar6);
      f_op_msg_mng::fopMsgM_setNowAlpha(&this->field_0x40,(float)dVar6);
      f_op_msg_mng::fopMsgM_setNowAlpha(&this->field_0x78,(float)dVar6);
      f_op_msg_mng::fopMsgM_setNowAlpha(&this->field_0xb0,(float)dVar6);
      f_op_msg_mng::fopMsgM_setNowAlpha(&this->field_0xe8,(float)dVar6);
      f_op_msg_mng::fopMsgM_setNowAlpha(&this->field_0x120,(float)dVar6);
      f_op_msg_mng::fopMsgM_paneScaleXY(&this->field_0x8,DAT_803e6b00);
      d_timer::dTm_parentPaneScale(&this->field_0x40,&this->field_0x8,(double)DAT_803e6b00);
      d_timer::dTm_parentPaneScale(&this->field_0x78,&this->field_0x8,(double)DAT_803e6b00);
      d_timer::dTm_parentPaneScale(&this->field_0xb0,&this->field_0x8,(double)DAT_803e6b00);
      d_timer::dTm_parentPaneScale(&this->field_0xe8,&this->field_0x8,(double)DAT_803e6b00);
      d_timer::dTm_parentPaneScale(&this->field_0x120,&this->field_0x8,(double)DAT_803e6b00);
    }
    bVar1 = this->field_0x234;
    if (((int)d_timer::animeFrame_4519[0] < (int)(char)bVar1) &&
       ((int)(char)bVar1 <= (int)d_timer::animeFrame_4519[2])) {
      uVar2 = (int)(short)((char)bVar1 - d_timer::animeFrame_4519[0]) ^ 0x80000000;
      dVar5 = (double)(((float)((double)CONCAT44(0x43300000,uVar2) - d_timer::_4368) *
                       (float)((double)CONCAT44(0x43300000,uVar2) - d_timer::_4368)) /
                      ((float)((double)CONCAT44(0x43300000,
                                                (int)d_timer::animeFrame_4519[1] ^ 0x80000000U) -
                              d_timer::_4368) *
                      (float)((double)CONCAT44(0x43300000,
                                               (int)d_timer::animeFrame_4519[1] ^ 0x80000000U) -
                             d_timer::_4368)));
      f_op_msg_mng::fopMsgM_paneTrans
                (&this->field_0x158,
                 (double)(d_timer::_4550 * (float)((double)d_timer::_4227 - dVar5) +
                         (float)((double)CONCAT44(0x43300000,(int)DAT_803e6b06 ^ 0x80000000) -
                                d_timer::_4368)),
                 (double)(float)((double)CONCAT44(0x43300000,(int)DAT_803e6b08 ^ 0x80000000) -
                                d_timer::_4368));
      f_op_msg_mng::fopMsgM_setNowAlpha(&this->field_0x158,(float)dVar5);
      f_op_msg_mng::fopMsgM_setNowAlpha(&this->field_0x190,(float)dVar5);
      f_op_msg_mng::fopMsgM_setNowAlpha(&this->field_0x1c8,(float)dVar5);
      f_op_msg_mng::fopMsgM_paneScaleXY(&this->field_0x158,DAT_803e6b0c);
      d_timer::dTm_parentPaneScale(&this->field_0x1c8,&this->field_0x158,(double)DAT_803e6b0c);
    }
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  __psq_l0(auStack24,uVar4);
  __psq_l1(auStack24,uVar4);
  return;
}


/* WARNING: Removing unreachable block (ram,0x8023d820) */
/* WARNING: Removing unreachable block (ram,0x8023d828) */
/* __thiscall dDlst_TimerScrnDraw_c::closeAnime(void) */

bool __thiscall dDlst_TimerScrnDraw_c::closeAnime(dDlst_TimerScrnDraw_c *this)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined8 in_f30;
  double x;
  undefined8 in_f31;
  double dVar5;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  this->field_0x234 = this->field_0x234 + 1;
  bVar1 = this->field_0x234;
  if ((char)bVar1 < 8) {
    uVar2 = (int)(char)bVar1 ^ 0x80000000;
    uVar3 = (int)(short)(7 - (char)bVar1) ^ 0x80000000;
    dVar5 = (double)(((float)((double)CONCAT44(0x43300000,uVar3) - d_timer::_4368) *
                     (float)((double)CONCAT44(0x43300000,uVar3) - d_timer::_4368)) / d_timer::_4575)
    ;
    x = (double)(d_timer::_4550 *
                (((float)((double)CONCAT44(0x43300000,uVar2) - d_timer::_4368) *
                 (float)((double)CONCAT44(0x43300000,uVar2) - d_timer::_4368)) / d_timer::_4575));
    f_op_msg_mng::fopMsgM_paneTrans(&this->field_0x8,x,(double)d_timer::0_0);
    f_op_msg_mng::fopMsgM_paneTrans(&this->field_0x40,x,(double)d_timer::0_0);
    f_op_msg_mng::fopMsgM_paneTrans(&this->field_0xb0,x,(double)d_timer::0_0);
    f_op_msg_mng::fopMsgM_paneTrans(&this->field_0xe8,x,(double)d_timer::0_0);
    f_op_msg_mng::fopMsgM_paneTrans(&this->field_0x120,x,(double)d_timer::0_0);
    f_op_msg_mng::fopMsgM_setNowAlpha(&this->field_0x8,(float)dVar5);
    f_op_msg_mng::fopMsgM_setNowAlpha(&this->field_0x40,(float)dVar5);
    f_op_msg_mng::fopMsgM_setNowAlpha(&this->field_0x78,(float)dVar5);
    f_op_msg_mng::fopMsgM_setNowAlpha(&this->field_0xb0,(float)dVar5);
    f_op_msg_mng::fopMsgM_setNowAlpha(&this->field_0xe8,(float)dVar5);
    f_op_msg_mng::fopMsgM_setNowAlpha(&this->field_0x120,(float)dVar5);
    f_op_msg_mng::fopMsgM_paneTrans
              (&this->field_0x158,
               (double)(float)(x + (double)(float)((double)CONCAT44(0x43300000,
                                                                    (int)DAT_803e6b06 ^ 0x80000000)
                                                  - d_timer::_4368)),
               (double)(float)((double)CONCAT44(0x43300000,(int)DAT_803e6b08 ^ 0x80000000) -
                              d_timer::_4368));
    f_op_msg_mng::fopMsgM_setNowAlpha(&this->field_0x158,(float)dVar5);
    f_op_msg_mng::fopMsgM_setNowAlpha(&this->field_0x190,(float)dVar5);
    f_op_msg_mng::fopMsgM_setNowAlpha(&this->field_0x1c8,(float)dVar5);
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  __psq_l0(auStack24,uVar4);
  __psq_l1(auStack24,uVar4);
  return '\x06' < (char)this->field_0x234;
}


/* __thiscall dDlst_TimerScrnDraw_c::hide(void) */

undefined4 __thiscall dDlst_TimerScrnDraw_c::hide(dDlst_TimerScrnDraw_c *this)

{
  f_op_msg_mng::fopMsgM_setNowAlphaZero(&this->field_0x8);
  f_op_msg_mng::fopMsgM_setNowAlphaZero(&this->field_0x40);
  f_op_msg_mng::fopMsgM_setNowAlphaZero(&this->field_0x78);
  f_op_msg_mng::fopMsgM_setNowAlphaZero(&this->field_0xb0);
  f_op_msg_mng::fopMsgM_setNowAlphaZero(&this->field_0xe8);
  f_op_msg_mng::fopMsgM_setNowAlphaZero(&this->field_0x120);
  f_op_msg_mng::fopMsgM_setNowAlphaZero(&this->field_0x158);
  f_op_msg_mng::fopMsgM_setNowAlphaZero(&this->field_0x190);
  f_op_msg_mng::fopMsgM_setNowAlphaZero(&this->field_0x1c8);
  return 1;
}


/* __thiscall dDlst_TimerScrnDraw_c::draw(void) */

void __thiscall dDlst_TimerScrnDraw_c::draw(dDlst_TimerScrnDraw_c *this)

{
  J2DOrthoGraph *pCtx;
  
  f_op_msg_mng::fopMsgM_setAlpha(&this->field_0x8);
  f_op_msg_mng::fopMsgM_setAlpha(&this->field_0x40);
  f_op_msg_mng::fopMsgM_setAlpha(&this->field_0x78);
  f_op_msg_mng::fopMsgM_setAlpha(&this->field_0xb0);
  f_op_msg_mng::fopMsgM_setAlpha(&this->field_0xe8);
  f_op_msg_mng::fopMsgM_setAlpha(&this->field_0x120);
  f_op_msg_mng::fopMsgM_setAlpha(&this->field_0x158);
  f_op_msg_mng::fopMsgM_setAlpha(&this->field_0x190);
  f_op_msg_mng::fopMsgM_setAlpha(&this->field_0x1c8);
  pCtx = d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph;
  (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph)->parent).vtbl)->setPort)
            (d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph);
  J2DScreen::draw(this->mpScreen,d_timer::0_0,d_timer::0_0,&pCtx->parent);
  if (this->field_0x22c != (J2DPicture *)0x0) {
    J2DPicture::draw(this->field_0x22c,(this->field_0x158).mPosTopLeft.x,
                     (this->field_0x158).mPosTopLeft.y,(this->field_0x158).mSize.x,
                     (this->field_0x158).mSize.y,false,false,false);
    (this->field_0x22c->parent).mAlpha = (this->field_0x158).mAlpha;
  }
  return;
}


namespace d_timer {

/* __stdcall dTimer_Draw(dTimer_c *) */

void dTimer_Draw(dTimer_c *param_1)

{
  ::dTimer_c::_draw(param_1);
  return;
}


/* __stdcall dTimer_Execute(dTimer_c *) */

void dTimer_Execute(dTimer_c *param_1)

{
  ::dTimer_c::_execute(param_1);
  return;
}


/* __stdcall dTimer_IsDelete(dTimer_c *) */

undefined4 dTimer_IsDelete(void)

{
  return 1;
}


/* __stdcall dTimer_Delete(dTimer_c *) */

void dTimer_Delete(dTimer_c *param_1)

{
  ::dTimer_c::_delete(param_1);
  return;
}


/* __stdcall dTimer_Create(msg_class *) */

void dTimer_Create(dTimer_c *param_1)

{
  ::dTimer_c::_create(param_1);
  return;
}


/* __stdcall dTimer_createTimer(int,
                                unsigned short,
                                unsigned char,
                                unsigned char,
                                float,
                                float,
                                float,
                                float) */

undefined4
dTimer_createTimer
          (undefined param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (d_com_inf_game::g_dComIfG_gameInfo._23788_4_ == -1) {
    uVar1 = f_op_msg_mng::fop_Timer_create(0x1ec,param_1,param_2,param_3,param_4,0);
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


/* __stdcall dTimer_createStockTimer(void) */

undefined4 dTimer_createStockTimer(void)

{
  undefined4 uVar1;
  
  if (d_com_inf_game::g_dComIfG_gameInfo._23788_4_ == -1) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = f_op_msg_mng::fop_Timer_create
                      ((double)_4676,(double)_4677,(double)_4678,(double)_4679,0x1ec,7,0,3,0,0);
  }
  return uVar1;
}

}

/* __thiscall dDlst_TimerScrnDraw_c::~dDlst_TimerScrnDraw_c(void) */

void __thiscall dDlst_TimerScrnDraw_c::_dDlst_TimerScrnDraw_c(dDlst_TimerScrnDraw_c *this)

{
  short in_r4;
  
  if (this != (dDlst_TimerScrnDraw_c *)0x0) {
    (this->parent).vtbl = &__vt;
    if (this != (dDlst_TimerScrnDraw_c *)0x0) {
      (this->parent).vtbl = (undefined *)&dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}

