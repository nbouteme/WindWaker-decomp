#include <d_a_agb.h>
#include <m_Do_ext.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <JKernel/JKRHeap.h>
#include <f_op_msg_mng.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <d_a_agb.h>
#include <d_stage.h>
#include <d_map.h>
#include <JUtility/JUTGba.h>
#include <m_Do_gba_com.h>
#include <d_msg.h>
#include <m_Do_dvd_thread.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <d_save.h>
#include <d_particle.h>
#include <Runtime.PPCEABI.H/ptmf.h>
#include <d_com_inf_game.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <d_event_manager.h>
#include <f_op_actor_mng.h>
#include <SComponent/c_math.h>
#include <f_pc_executor.h>
#include <f_pc_searcher.h>
#include <f_op_actor_iter.h>
#include <d_a_bomb_static.h>
#include <d_meter.h>
#include <d_kankyo_wether.h>
#include <d_kankyo.h>
#include <SComponent/c_lib.h>
#include <SComponent/c_xyz.h>
#include <SComponent/c_bg_s_lin_chk.h>
#include <d_bg_s_lin_chk.h>
#include <SComponent/c_bg_s.h>
#include <d_bg_s_acch.h>
#include <d_bg_s.h>
#include <SComponent/c_bg_s_chk.h>
#include <SComponent/c_bg_s_gnd_chk.h>
#include <mtx/vec.h>
#include <d_attention.h>
#include <mtx/mtx.h>
#include <m_Do_mtx.h>
#include <d_resorce.h>
#include <gx/GXTexture.h>
#include <d_event.h>
#include <f_op_actor.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <mDoHIO_entry_c.h>
#include <dMsgCtrl_c.h>
#include <daAgb_c.h>
#include <J3DTevBlock.h>
#include <dBgS_LinkLinChk.h>
#include <dBgS_LinkAcch.h>
#include <Demangler/dBgS_CrrPos.h>
#include <daPy_py_c.h>
#include <dBgS_LinkCrrPos.h>
#include <daAgb_HIO_c.h>


namespace d_a_agb {
}

namespace d_a_agb {
}

namespace dBgS_CrrPos {
}

namespace d_a_agb {
undefined l_HIO;
undefined l_msgCtrl;
undefined4 l_gbaCommand;
}
undefined1 daAgb_c;
undefined1 daAgb_c;
undefined1 daAgb_c;
undefined1 daAgb_c;
undefined1 daAgb_c;
undefined1 daAgb_c;

namespace d_a_agb {
undefined1 se_flag$4619;
undefined1 init$4620;
}

/* __thiscall daAgb_HIO_c::daAgb_HIO_c(void) */

void __thiscall daAgb_HIO_c::daAgb_HIO_c(daAgb_HIO_c *this)

{
  *(undefined1 **)this = &::mDoHIO_entry_c::__vt;
  *(undefined1 **)this = &__vt;
  Runtime.PPCEABI.H::__construct_array(this + 4,J3DGXColorS10::J3DGXColorS10,(undefined *)0x0,8,2);
  *(undefined2 *)(this + 4) = 0;
  *(undefined2 *)(this + 6) = 0xff;
  *(undefined2 *)(this + 8) = 0;
  *(undefined2 *)(this + 10) = 0xff;
  *(undefined2 *)(this + 0xc) = 0;
  *(undefined2 *)(this + 0xe) = 0x1e;
  *(undefined2 *)(this + 0x10) = 0;
  *(undefined2 *)(this + 0x12) = 0;
  *(float *)(this + 0x14) = d_a_agb::_4274;
  *(float *)(this + 0x18) = d_a_agb::_4275;
  *(float *)(this + 0x1c) = d_a_agb::_4276;
  *(float *)(this + 0x20) = d_a_agb::_4277;
  *(float *)(this + 0x24) = d_a_agb::_4278;
  *(float *)(this + 0x28) = d_a_agb::_4279;
  *(float *)(this + 0x2c) = d_a_agb::_4280;
  *(float *)(this + 0x30) = d_a_agb::_4281;
  return;
}


/* __thiscall mDoHIO_entry_c::~mDoHIO_entry_c(void) */

void __thiscall mDoHIO_entry_c::_mDoHIO_entry_c(mDoHIO_entry_c *this)

{
  short in_r4;
  
  if ((this != (mDoHIO_entry_c *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall dMsgCtrl_c::init(unsigned short) */

int __thiscall dMsgCtrl_c::init(dMsgCtrl_c *this,EVP_PKEY_CTX *ctx)

{
  *(short *)this = (short)ctx;
  *(undefined4 *)(this + 4) = 0xffffffff;
  *(undefined4 *)(this + 8) = 0;
  return 1;
}


/* __thiscall dMsgCtrl_c::execute(void) */

uint __thiscall dMsgCtrl_c::execute(dMsgCtrl_c *this)

{
  undefined4 uVar1;
  msg_class *pmVar2;
  int iVar3;
  
  if (*(uint *)(this + 4) == 0xffffffff) {
    uVar1 = f_op_msg_mng::fopMsgM_messageSet(*(undefined2 *)this);
    *(undefined4 *)(this + 4) = uVar1;
  }
  else {
    iVar3 = *(int *)(this + 8);
    if (iVar3 != 0) {
      if (*(short *)(iVar3 + 0xf8) == 0x12) {
        *(undefined2 *)(iVar3 + 0xf8) = 0x13;
        d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mStateFlags =
             d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mStateFlags | 8;
      }
      return (uint)*(ushort *)(*(int *)(this + 8) + 0xf8);
    }
    pmVar2 = f_op_msg_mng::fopMsgM_SearchByID(*(uint *)(this + 4));
    *(msg_class **)(this + 8) = pmVar2;
  }
  return 0xffffffff;
}


namespace d_a_agb {

/* __stdcall sjis2chrNo(unsigned char) */

uint sjis2chrNo(char param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  while( true ) {
    if (0x9e < (uVar1 & 0xff)) {
      return 0xff;
    }
    if (param_1 == (&l_sjis2chrNo_4313)[uVar1 & 0xff]) break;
    uVar1 = uVar1 + 1;
  }
  return uVar1;
}

}

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall daAgb_c::NameConv(void) */

void __thiscall daAgb_c::NameConv(daAgb_c *this)

{
  uint uVar1;
  undefined *puVar2;
  int iVar3;
  
  puVar2 = &d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mInfo.mPlayerName;
  *(undefined4 *)&this->field_0x64c = 0;
  *(undefined4 *)&this->field_0x648 = 0;
  iVar3 = 0;
  do {
    uVar1 = d_a_agb::sjis2chrNo(*puVar2);
    *(uint *)&this->field_0x64c = *(uint *)&this->field_0x64c | uVar1 & 0xff;
    puVar2 = puVar2 + 1;
    if (iVar3 < 7) {
      uVar1 = *(uint *)&this->field_0x64c;
      *(uint *)&this->field_0x64c = uVar1 << 8;
      *(uint *)&this->field_0x648 = uVar1 >> 0x18 | *(int *)&this->field_0x648 << 8;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 8);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall daAgb_c::uploadInitCheck(void) */

undefined4 __thiscall daAgb_c::uploadInitCheck(daAgb_c *this)

{
  dStage_roomStatus_c *pdVar1;
  uint *puVar2;
  dMap_c *this_00;
  char cVar4;
  int iVar3;
  
  pdVar1 = dStage_roomControl_c::getStatusRoomDt
                     (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mRoomCtrl,
                      (int)(char)dStage_roomControl_c::mStayNo);
  puVar2 = (uint *)(*(code *)((pdVar1->parent).parent.vtbl)->getFileListInfo)();
  this_00 = (dMap_c *)
            (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)
                      (0x803c9d58);
  if ((((*(uint *)(this_00 + 0xc) >> 0x10 & 7) != 7) &&
      (cVar4 = dMap_c::isEnableDispMap(this_00), cVar4 == '\0')) ||
     ((puVar2 != (uint *)0x0 && ((*puVar2 & 2) != 0)))) {
    dMsgCtrl_c::init((dMsgCtrl_c *)&d_a_agb::l_msgCtrl,(EVP_PKEY_CTX *)&DAT_00000001);
    *(undefined *)&this->field_0x66a = 10;
    return 1;
  }
  if (m_Do_ext::m_Do_gba_com::g_mDoGaC_gbaCom == '\0') {
    *(undefined *)&this->field_0x66f = 0;
    *(undefined *)&this->field_0x678 = 0;
    JUTGba::doInitProbe(_sManager,1,(FuncDef593 *)0x0,(void *)0x0);
    JUTGba::doInitProbe(_sManager,2,(FuncDef593 *)0x0,(void *)0x0);
    JUTGba::doInitProbe(_sManager,3,(FuncDef593 *)0x0,(void *)0x0);
    *(undefined *)&this->field_0x66a = 1;
    return 1;
  }
  iVar3 = mDoGaC_agbCom_c::mDoGaC_GbaLink
                    ((mDoGaC_agbCom_c *)&m_Do_ext::m_Do_gba_com::g_mDoGaC_gbaCom);
  if (iVar3 != 0) {
    dMsgCtrl_c::init((dMsgCtrl_c *)&d_a_agb::l_msgCtrl,(EVP_PKEY_CTX *)&DAT_00000002);
    *(undefined *)&this->field_0x66a = 10;
    return 1;
  }
  JUTGba::doInitProbe(_sManager,1,(FuncDef593 *)0x0,(void *)0x0);
  JUTGba::doInitProbe(_sManager,2,(FuncDef593 *)0x0,(void *)0x0);
  JUTGba::doInitProbe(_sManager,3,(FuncDef593 *)0x0,(void *)0x0);
  *(undefined *)&this->field_0x66a = 1;
  mDoGaC_agbCom_c::mDoGaC_ConnectSleep((mDoGaC_agbCom_c *)&m_Do_ext::m_Do_gba_com::g_mDoGaC_gbaCom);
  return 1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall daAgb_c::uploadPortCheckWait(void) */

undefined4 __thiscall daAgb_c::uploadPortCheckWait(daAgb_c *this)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int local_28 [6];
  
  iVar3 = 0;
  iVar4 = 0;
  do {
    uVar1 = JUTGba::resultInitProbe(_sManager,iVar3 + 1,(ulong *)((int)local_28 + iVar4 + 0xc));
    *(undefined4 *)((int)local_28 + iVar4) = uVar1;
    if (*(int *)((int)local_28 + iVar4) == -2) {
      return 1;
    }
    iVar3 = iVar3 + 1;
    iVar4 = iVar4 + 4;
  } while (iVar3 < 3);
  iVar3 = mDoGaC_agbCom_c::mDoGaC_GbaLink
                    ((mDoGaC_agbCom_c *)&m_Do_ext::m_Do_gba_com::g_mDoGaC_gbaCom);
  if (iVar3 == 0) {
    cVar2 = '\0';
    iVar3 = 0;
    iVar4 = 3;
    do {
      if ((*(int *)((int)local_28 + iVar3) == 0) &&
         (*(int *)((int)local_28 + iVar3 + 0xc) == 0x40000)) {
        *(char *)&this->field_0x666 = cVar2 + '\x01';
        dMsgCtrl_c::init((dMsgCtrl_c *)&d_a_agb::l_msgCtrl,(EVP_PKEY_CTX *)0x5);
        *(undefined *)&this->field_0x66a = 2;
        return 1;
      }
      cVar2 = cVar2 + '\x01';
      iVar3 = iVar3 + 4;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    dMsgCtrl_c::init((dMsgCtrl_c *)&d_a_agb::l_msgCtrl,(EVP_PKEY_CTX *)&DAT_00000003);
    *(undefined *)&this->field_0x66a = 10;
    mDoGaC_agbCom_c::mDoGaC_ConnectWake((mDoGaC_agbCom_c *)&m_Do_ext::m_Do_gba_com::g_mDoGaC_gbaCom)
    ;
  }
  else {
    dMsgCtrl_c::init((dMsgCtrl_c *)&d_a_agb::l_msgCtrl,(EVP_PKEY_CTX *)&DAT_00000002);
    *(undefined *)&this->field_0x66a = 10;
  }
  return 1;
}


/* __thiscall daAgb_c::uploadSelect(void) */

undefined4 __thiscall daAgb_c::uploadSelect(daAgb_c *this)

{
  int iVar1;
  JKRHeap *pHeap;
  ulong uVar2;
  
  iVar1 = dMsgCtrl_c::execute((dMsgCtrl_c *)&d_a_agb::l_msgCtrl);
  if (iVar1 == 0xe) {
    if ((d_com_inf_game::g_dComIfG_gameInfo._23529_1_ == '\0') &&
       (*(char *)(DAT_803e3648 + 0xfa) == '\0')) {
      *(undefined2 *)(DAT_803e3648 + 0xf8) = 0xf;
      f_op_msg_mng::fopMsgM_messageSet(6);
      *(undefined *)&this->field_0x66a = 3;
      pHeap = (JKRHeap *)d_msg::dMsg_getAgbWorkArea();
      d_a_agb::l_gbaCommand = mDoDvdThd_toMainRam_c::create("/res/Gba/client_u.bin",0,pHeap);
      if (d_a_agb::l_gbaCommand == 0) {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar2,"d_a_agb.cpp",0x35c,"l_gbaCommand != 0");
        m_Do_printf::OSPanic("d_a_agb.cpp",0x35c,"Halt");
      }
      mDoGaC_agbCom_c::mDoGaC_GbaReboot((mDoGaC_agbCom_c *)&m_Do_ext::m_Do_gba_com::g_mDoGaC_gbaCom)
      ;
      DAT_803b9159 = *(undefined *)&this->field_0x666;
      *(undefined *)&this->field_0x66f = 0;
      *(undefined *)&this->field_0x678 = 0;
    }
    else {
      *(undefined2 *)(DAT_803e3648 + 0xf8) = 0x10;
      mDoGaC_agbCom_c::mDoGaC_ConnectWake
                ((mDoGaC_agbCom_c *)&m_Do_ext::m_Do_gba_com::g_mDoGaC_gbaCom);
    }
  }
  return 1;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall daAgb_c::uploadJoyboot1(void) */

undefined4 __thiscall daAgb_c::uploadJoyboot1(daAgb_c *this)

{
  ulong uVar1;
  uchar *puVar2;
  
  if (*(char *)(d_a_agb::l_gbaCommand + 0xc) != '\0') {
    puVar2 = *(uchar **)(d_a_agb::l_gbaCommand + 0x1c);
    if (puVar2 == (uchar *)0x0) {
      uVar1 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar1,"d_a_agb.cpp",0x37b,"programp != 0");
      m_Do_printf::OSPanic("d_a_agb.cpp",0x37b,"Halt");
    }
    JUTGba::doJoyBoot(_sManager,(uint)DAT_803b9159,3,-1,puVar2,
                      *(int *)(d_a_agb::l_gbaCommand + 0x20) - 4,(FuncDef592 *)0x0,(void *)0x0);
    *(undefined *)&this->field_0x66a = 4;
    *(undefined2 *)&this->field_0x664 = 0x1c2;
  }
  return 1;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall daAgb_c::uploadJoyboot2(void) */

undefined4 __thiscall daAgb_c::uploadJoyboot2(daAgb_c *this)

{
  int iVar1;
  uchar auStack24 [16];
  
  iVar1 = JUTGba::resultJoyBoot(_sManager,(uint)DAT_803b9159,auStack24);
  if (iVar1 == -2) {
    *(short *)&this->field_0x664 = *(short *)&this->field_0x664 + -1;
    if (*(short *)&this->field_0x664 == 0) {
      *(undefined2 *)(DAT_803e3648 + 0xf8) = 0xf;
      f_op_msg_mng::fopMsgM_messageSet(7);
      f_op_msg_mng::fopMsgM_messageSendOn();
      *(undefined *)&this->field_0x66a = 10;
      JKRHeap::free(*(void **)(d_a_agb::l_gbaCommand + 0x1c),(JKRHeap *)0x0);
      if (d_a_agb::l_gbaCommand != 0) {
        (**(code **)(*(int *)(d_a_agb::l_gbaCommand + 0x10) + 8))(d_a_agb::l_gbaCommand,1);
      }
    }
  }
  else {
    JKRHeap::free(*(void **)(d_a_agb::l_gbaCommand + 0x1c),(JKRHeap *)0x0);
    if (d_a_agb::l_gbaCommand != 0) {
      (**(code **)(*(int *)(d_a_agb::l_gbaCommand + 0x10) + 8))(d_a_agb::l_gbaCommand,1);
    }
    if (iVar1 == 0) {
      *(undefined2 *)&this->field_0x664 = 0xf;
      *(undefined *)&this->field_0x66a = 6;
    }
    else {
      *(undefined2 *)(DAT_803e3648 + 0xf8) = 0xf;
      f_op_msg_mng::fopMsgM_messageSet(7);
      f_op_msg_mng::fopMsgM_messageSendOn();
      *(undefined *)&this->field_0x66a = 10;
    }
  }
  return 1;
}


/* __thiscall daAgb_c::uploadMessageLoad(void) */

undefined4 __thiscall daAgb_c::uploadMessageLoad(daAgb_c *this)

{
  ulong uVar1;
  
  *(short *)&this->field_0x664 = *(short *)&this->field_0x664 + -1;
  if (*(short *)&this->field_0x664 == 0) {
    d_a_agb::l_gbaCommand = mDoDvdThd_toMainRam_c::create("/res/Gba/msg_LZ.bin",0,(JKRHeap *)0x0);
    if (d_a_agb::l_gbaCommand == 0) {
      uVar1 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar1,"d_a_agb.cpp",1000,"l_gbaCommand != 0");
      m_Do_printf::OSPanic("d_a_agb.cpp",1000,"Halt");
    }
    *(undefined *)&this->field_0x66a = 7;
    m_Do_ext::m_Do_gba_com::g_mDoGaC_gbaCom = 1;
    mDoGaC_agbCom_c::mDoGaC_ComStart((mDoGaC_agbCom_c *)&m_Do_ext::m_Do_gba_com::g_mDoGaC_gbaCom);
  }
  return 1;
}


/* __thiscall daAgb_c::uploadMessageLoad2(void) */

undefined4 __thiscall daAgb_c::uploadMessageLoad2(daAgb_c *this)

{
  if (*(char *)(d_a_agb::l_gbaCommand + 0xc) != '\0') {
    *(undefined *)&this->field_0x66a = 5;
  }
  return 1;
}


/* __thiscall daAgb_c::uploadConnect(void) */

undefined4 __thiscall daAgb_c::uploadConnect(daAgb_c *this)

{
  int iVar1;
  ulong uVar2;
  dMap_c *this_00;
  ulong *puVar3;
  
  if ((m_Do_ext::m_Do_gba_com::g_mDoGaC_gbaCom == '\0') ||
     (iVar1 = mDoGaC_agbCom_c::mDoGaC_GbaLink
                        ((mDoGaC_agbCom_c *)&m_Do_ext::m_Do_gba_com::g_mDoGaC_gbaCom), iVar1 == 0))
  {
    mDoGaC_agbCom_c::mDoGaC_GbaReboot((mDoGaC_agbCom_c *)&m_Do_ext::m_Do_gba_com::g_mDoGaC_gbaCom);
    *(undefined2 *)(DAT_803e3648 + 0xf8) = 0xf;
    f_op_msg_mng::fopMsgM_messageSet(7);
    f_op_msg_mng::fopMsgM_messageSendOn();
    *(undefined *)&this->field_0x66a = 10;
    JKRHeap::free(*(void **)(d_a_agb::l_gbaCommand + 0x1c),(JKRHeap *)0x0);
    if (d_a_agb::l_gbaCommand != 0) {
      (**(code **)(*(int *)(d_a_agb::l_gbaCommand + 0x10) + 8))(d_a_agb::l_gbaCommand,1);
    }
  }
  else {
    puVar3 = *(ulong **)(d_a_agb::l_gbaCommand + 0x1c);
    if (puVar3 == (ulong *)0x0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"d_a_agb.cpp",0x415,"programp != 0");
      m_Do_printf::OSPanic("d_a_agb.cpp",0x415,"Halt");
    }
    mDoGaC_agbCom_c::mDoGaC_SendDataSet
              ((mDoGaC_agbCom_c *)&m_Do_ext::m_Do_gba_com::g_mDoGaC_gbaCom,puVar3,
               *(int *)(d_a_agb::l_gbaCommand + 0x20),'\0',0);
    *(undefined *)&this->field_0x66a = 8;
    NameConv(this);
    this_00 = (dMap_c *)
              mDoGaC_agbCom_c::mDoGaC_SendDataSet
                        ((mDoGaC_agbCom_c *)&m_Do_ext::m_Do_gba_com::g_mDoGaC_gbaCom,
                         (ulong *)&this->field_0x648,8,'\n',0);
    dMap_c::mapAGBSendIslandData(this_00);
  }
  return 1;
}


/* __thiscall daAgb_c::uploadMessageSend(void) */

undefined4 __thiscall daAgb_c::uploadMessageSend(daAgb_c *this)

{
  if (*(char *)(DAT_803b915c + 4) == '\0') {
    *(undefined *)&this->field_0x678 = 1;
    if (*(char *)&this->field_0x67a != '\0') {
      *(undefined2 *)(DAT_803e3648 + 0xf8) = 0xf;
      f_op_msg_mng::fopMsgM_messageSet(8);
      f_op_msg_mng::fopMsgM_messageSendOn();
      *(undefined *)&this->field_0x66a = 0xb;
      *(undefined2 *)&this->field_0x664 = 0x3c;
      dSv_event_c::onEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x1a20);
      dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0x2e7,
                         &(this->parent).mCurrent.mPos,(csXyz *)0x0,(cXyz *)0x0,0xff,
                         (dPa_levelEcallBack *)&this->field_0x684,-1,(_GXColor *)0x0,(_GXColor *)0x0
                         ,(cXyz *)0x0);
      JKRHeap::free(*(void **)(d_a_agb::l_gbaCommand + 0x1c),(JKRHeap *)0x0);
      if (d_a_agb::l_gbaCommand != 0) {
        (**(code **)(*(int *)(d_a_agb::l_gbaCommand + 0x10) + 8))(d_a_agb::l_gbaCommand,1);
      }
    }
  }
  else {
    if (*(char *)(DAT_803b915c + 4) == '\t') {
      *(undefined2 *)&this->field_0x664 = 5;
      *(undefined *)&this->field_0x66a = 9;
    }
  }
  return 1;
}


/* __thiscall daAgb_c::uploadRetryWait(void) */

undefined4 __thiscall daAgb_c::uploadRetryWait(daAgb_c *this)

{
  *(short *)&this->field_0x664 = *(short *)&this->field_0x664 + -1;
  if (*(short *)&this->field_0x664 == 0) {
    *(undefined *)&this->field_0x66a = 5;
  }
  return 1;
}


/* __thiscall daAgb_c::uploadMsgEndWait(void) */

undefined4 __thiscall daAgb_c::uploadMsgEndWait(daAgb_c *this)

{
  int iVar1;
  
  iVar1 = dMsgCtrl_c::execute((dMsgCtrl_c *)&d_a_agb::l_msgCtrl);
  if (iVar1 == 0xe) {
    *(undefined2 *)(DAT_803e3648 + 0xf8) = 0x10;
  }
  return 1;
}


/* __thiscall daAgb_c::uploadMsgEndTimer(void) */

undefined4 __thiscall daAgb_c::uploadMsgEndTimer(daAgb_c *this)

{
  dMsgCtrl_c::execute((dMsgCtrl_c *)&d_a_agb::l_msgCtrl);
  if (*(short *)&this->field_0x664 != 0) {
    *(short *)&this->field_0x664 = *(short *)&this->field_0x664 + -1;
    if (*(short *)&this->field_0x664 == 0) {
      *(undefined2 *)(DAT_803e3648 + 0xf8) = 0x10;
      f_op_msg_mng::fopMsgM_messageSendOn();
    }
    else {
      if (*(short *)&this->field_0x664 == 0x1e) {
        *(undefined *)&this->field_0x66f = 1;
      }
    }
  }
  return 1;
}


/* __thiscall daAgb_c::modeLoad(void) */

void __thiscall daAgb_c::modeLoad(daAgb_c *this)

{
  uint uVar1;
  PTMF local_18 [2];
  
  if ((this->parent).mEvtInfo.mCommand == InTalk) {
    uVar1 = (uint)*(byte *)&this->field_0x66a;
    local_18[0].this_delta = *(int *)(&uploadFuncTable + uVar1 * 0xc);
    local_18[0].vtbl_offset = (&DAT_803893d4)[uVar1 * 3];
    local_18[0].func = (undefined *)(&DAT_803893d8)[uVar1 * 3];
    Runtime.PPCEABI.H::__ptmf_scall(local_18,this,(void *)local_18[0].this_delta);
  }
  else {
    *(undefined *)&this->field_0x66a = 0;
    (this->parent).mEvtInfo.mCondition = (this->parent).mEvtInfo.mCondition | CanTalk;
    *(undefined *)&this->field_0x669 = 0;
  }
  return;
}


/* __thiscall daAgb_c::modeLookAttention(void) */

void __thiscall daAgb_c::modeLookAttention(daAgb_c *this)

{
  sbyte sVar1;
  bool bVar2;
  
  if (d_a_agb::init_4620 == '\0') {
    d_a_agb::se_flag_4619 = '\0';
    d_a_agb::init_4620 = '\x01';
  }
  if ((this->parent).mEvtInfo.mCommand == InDemo) {
    if (d_a_agb::se_flag_4619 == '\0') {
      sVar1 = d_com_inf_game::dComIfGp_getReverb((int)(char)(this->parent).mCurrent.mRoomNo);
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x484c,&(this->parent).mEyePos,0,sVar1,d_a_agb::_4642,
                 d_a_agb::_4642,d_a_agb::_4643,d_a_agb::_4643,0);
      d_a_agb::se_flag_4619 = '\x01';
    }
    bVar2 = dEvent_manager_c::endCheckOld
                      (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,
                       "DEFAULT_AGB_LOOK_ATTENTION");
    if (bVar2 != false) {
      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mStateFlags =
           d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mStateFlags | 8;
      *(undefined *)&this->field_0x669 = 0;
      d_a_agb::se_flag_4619 = '\0';
      *(undefined2 *)&this->field_0x65c = 1;
      if (*(char *)&this->field_0x674 == '\0') {
        (this->parent).mCollisionRot.x = 0;
        (this->parent).mCollisionRot.y = 0;
        (this->parent).mCollisionRot.z = 0;
        *(float *)&this->field_0x628 = d_a_agb::_4644;
      }
    }
  }
  else {
    f_op_actor_mng::fopAcM_orderOtherEvent2
              (&this->parent,"DEFAULT_AGB_LOOK_ATTENTION",RequiresActiveActor2,0xffff);
  }
  return;
}


/* __thiscall daAgb_c::DungeonNoGet(void) */

char __thiscall daAgb_c::DungeonNoGet(daAgb_c *this)

{
  char cVar1;
  
  cVar1 = (&DungeonNoTable)[*(byte *)&this->field_0x66c];
  if (cVar1 == '\0') {
    if (*(char *)&this->field_0x67e != '\0') {
      switch(*(undefined *)&this->field_0x66d) {
      case 1:
        cVar1 = '\n';
        break;
      case 4:
        cVar1 = '\x0e';
        break;
      case 0xb:
        cVar1 = '\x06';
        break;
      case 0xd:
        cVar1 = '\a';
        break;
      case 0x14:
        cVar1 = '\x0f';
        break;
      case 0x17:
        cVar1 = '\f';
        break;
      case 0x28:
        cVar1 = '\x10';
        break;
      case 0x29:
        cVar1 = '\b';
        break;
      case 0x2c:
        cVar1 = '\t';
        break;
      case 0x2d:
        cVar1 = '\r';
      }
    }
    if (*(char *)&this->field_0x66d != *(char *)&this->field_0x66e) {
      resetCursor(this,true);
    }
  }
  *(undefined *)&this->field_0x66e = *(undefined *)&this->field_0x66d;
  return cVar1;
}


/* __thiscall daAgb_c::MapNoSet(unsigned char,
                                unsigned char,
                                unsigned char) */

void __thiscall daAgb_c::MapNoSet(daAgb_c *this,uchar param_1,uchar param_2,uchar param_3)

{
  int iVar1;
  
  *(uchar *)&this->field_0x66c = param_1;
  *(uchar *)&this->field_0x66d = param_2;
  *(char *)&this->field_0x67e = '\x01' - (param_3 == '\0');
  *(undefined *)&this->field_0x670 = 1;
  iVar1 = DungeonNoGet(this);
  d_com_inf_game::g_dComIfG_gameInfo._119263_1_ =
       (byte)(iVar1 << 2) & 0x7c | d_com_inf_game::g_dComIfG_gameInfo._119263_1_ & 0x83;
  return;
}


/* __thiscall daAgb_c::onFree(void) */

void __thiscall daAgb_c::onFree(daAgb_c *this)

{
  *(undefined *)&this->field_0x671 = 1;
  *(undefined4 *)&this->field_0x650 = 0xffffffff;
  *(undefined *)&this->field_0x677 = 0;
  return;
}


/* __thiscall daAgb_c::onHold(void) */

void __thiscall daAgb_c::onHold(daAgb_c *this)

{
  *(undefined *)&this->field_0x674 = 1;
  *(float *)(*(int *)&this->field_0x2a0 + 0xc) = d_a_agb::_4686;
  return;
}


/* __thiscall daAgb_c::offHold(void) */

void __thiscall daAgb_c::offHold(daAgb_c *this)

{
  *(undefined *)&this->field_0x674 = 0;
  *(float *)(*(int *)&this->field_0x2a0 + 0xc) = d_a_agb::_4642;
  return;
}


/* __thiscall daAgb_c::resetCursor(bool) */

void __thiscall daAgb_c::resetCursor(daAgb_c *this,bool param_1)

{
  daPy_lk_c *pdVar1;
  daPy_lk_c *pdVar2;
  
  pdVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor;
  *(undefined *)&this->field_0x671 = 0;
  *(undefined *)&this->field_0x677 = 0;
  *(undefined4 *)&this->field_0x650 = 0xffffffff;
  pdVar2 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor;
  if ((pdVar1->parent).parent.parent.parent.mProcName == 0xc4) {
    (this->parent).mCurrent.mPos.x =
         ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor)->parent).parent.mCurrent.mPos.x;
    (this->parent).mCurrent.mPos.y = (pdVar2->parent).parent.mCurrent.mPos.y;
    (this->parent).mCurrent.mPos.z = (pdVar2->parent).parent.mCurrent.mPos.z;
    pdVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor;
    (this->parent).mOrig.mPos.x =
         ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor)->parent).parent.mCurrent.mPos.x;
    (this->parent).mOrig.mPos.y = (pdVar1->parent).parent.mCurrent.mPos.y;
    (this->parent).mOrig.mPos.z = (pdVar1->parent).parent.mCurrent.mPos.z;
  }
  else {
    (this->parent).mCurrent.mPos.x = (pdVar1->parent).parent.mCurrent.mPos.x;
    (this->parent).mCurrent.mPos.y = (pdVar1->parent).parent.mCurrent.mPos.y;
    (this->parent).mCurrent.mPos.z = (pdVar1->parent).parent.mCurrent.mPos.z;
    (this->parent).mOrig.mPos.x = (pdVar1->parent).parent.mCurrent.mPos.x;
    (this->parent).mOrig.mPos.y = (pdVar1->parent).parent.mCurrent.mPos.y;
    (this->parent).mOrig.mPos.z = (pdVar1->parent).parent.mCurrent.mPos.z;
  }
  *(float *)&this->field_0x628 = d_a_agb::_4644;
  (this->parent).mCollisionRot.x = 0;
  (this->parent).mCollisionRot.y = 0;
  (this->parent).mCollisionRot.z = 0;
  if (param_1 != false) {
    if (*(char *)&this->field_0x66b == '\x0e') {
      *(undefined2 *)&this->field_0x65c = 0;
    }
    *(undefined *)&this->field_0x675 = 0;
    *(undefined *)&this->field_0x676 = 0;
  }
  *(undefined *)&this->field_0x674 = 0;
  *(float *)(*(int *)&this->field_0x2a0 + 0xc) = d_a_agb::_4642;
  return;
}


/* __thiscall daAgb_c::FlashCheck(void) */

undefined4 __thiscall daAgb_c::FlashCheck(daAgb_c *this)

{
  if ((*(char *)&this->field_0x671 == '\0') && (*(char *)&this->field_0x677 != '\x01')) {
    return 0;
  }
  return 1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall daAgb_c::FlagsRecv(void) */

void __thiscall daAgb_c::FlagsRecv(daAgb_c *this)

{
  uint uVar1;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar1 = (uint)DAT_803b9159;
  uVar2 = m_Do_ext::m_Do_gba_com::BigLittleChange(_mGbaFlg);
  m_Do_controller_pad::g_mDoCPd_cpadInfo[uVar1].mButton0 =
       (byte)(uVar2 >> 0x12) & 0x10 | m_Do_controller_pad::g_mDoCPd_cpadInfo[uVar1].mButton0 & 0xef;
  m_Do_controller_pad::g_mDoCPd_cpadInfo[uVar1].mButton0 =
       (byte)(uVar2 >> 0x12) & 0x20 | m_Do_controller_pad::g_mDoCPd_cpadInfo[uVar1].mButton0 & 0xdf;
  m_Do_controller_pad::g_mDoCPd_cpadInfo[uVar1].mButton0 =
       (byte)(uVar2 >> 0xe) & 0x80 | m_Do_controller_pad::g_mDoCPd_cpadInfo[uVar1].mButton0 & 0x7f;
  m_Do_controller_pad::g_mDoCPd_cpadInfo[uVar1].mButton0 =
       (byte)(uVar2 >> 0xe) & 0x40 | m_Do_controller_pad::g_mDoCPd_cpadInfo[uVar1].mButton0 & 0xbf;
  m_Do_controller_pad::g_mDoCPd_cpadInfo[uVar1].mButton0 =
       (byte)(uVar2 >> 0x10) & 1 | m_Do_controller_pad::g_mDoCPd_cpadInfo[uVar1].mButton0 & 0xfe;
  m_Do_controller_pad::g_mDoCPd_cpadInfo[uVar1].mButton1 =
       (byte)(uVar2 >> 10) & 0x80 | m_Do_controller_pad::g_mDoCPd_cpadInfo[uVar1].mButton1 & 0x7f;
  m_Do_controller_pad::g_mDoCPd_cpadInfo[uVar1].mButton0 =
       (byte)(uVar2 >> 0x16) & 4 | m_Do_controller_pad::g_mDoCPd_cpadInfo[uVar1].mButton0 & 0xfb;
  m_Do_controller_pad::g_mDoCPd_cpadInfo[uVar1].mButton0 =
       (byte)(uVar2 >> 0x18) & 2 | m_Do_controller_pad::g_mDoCPd_cpadInfo[uVar1].mButton0 & 0xfd;
  m_Do_controller_pad::g_mDoCPd_cpadInfo[uVar1].mButton1 =
       (byte)((uVar2 >> 0x13 & 1) << 4) |
       m_Do_controller_pad::g_mDoCPd_cpadInfo[uVar1].mButton1 & 0xef;
  uVar4 = uVar2 >> 0x10 & (uVar2 >> 0x10 ^ (uint)*(ushort *)&this->field_0x65a);
  m_Do_controller_pad::g_mDoCPd_cpadInfo[uVar1].mButton2 =
       (byte)(uVar4 >> 2) & 0x10 | m_Do_controller_pad::g_mDoCPd_cpadInfo[uVar1].mButton2 & 0xef;
  m_Do_controller_pad::g_mDoCPd_cpadInfo[uVar1].mButton2 =
       (byte)(uVar4 >> 2) & 0x20 | m_Do_controller_pad::g_mDoCPd_cpadInfo[uVar1].mButton2 & 0xdf;
  m_Do_controller_pad::g_mDoCPd_cpadInfo[uVar1].mButton2 =
       (byte)(uVar4 << 2) & 0x80 | m_Do_controller_pad::g_mDoCPd_cpadInfo[uVar1].mButton2 & 0x7f;
  m_Do_controller_pad::g_mDoCPd_cpadInfo[uVar1].mButton2 =
       (byte)(uVar4 << 2) & 0x40 | m_Do_controller_pad::g_mDoCPd_cpadInfo[uVar1].mButton2 & 0xbf;
  m_Do_controller_pad::g_mDoCPd_cpadInfo[uVar1].mButton2 =
       (byte)uVar4 & 1 | m_Do_controller_pad::g_mDoCPd_cpadInfo[uVar1].mButton2 & 0xfe;
  m_Do_controller_pad::g_mDoCPd_cpadInfo[uVar1].mButton3 =
       (byte)(uVar4 << 6) & 0x80 | m_Do_controller_pad::g_mDoCPd_cpadInfo[uVar1].mButton3 & 0x7f;
  m_Do_controller_pad::g_mDoCPd_cpadInfo[uVar1].mButton2 =
       (byte)(uVar4 >> 6) & 4 | m_Do_controller_pad::g_mDoCPd_cpadInfo[uVar1].mButton2 & 0xfb;
  m_Do_controller_pad::g_mDoCPd_cpadInfo[uVar1].mButton2 =
       (byte)(uVar4 >> 8) & 2 | m_Do_controller_pad::g_mDoCPd_cpadInfo[uVar1].mButton2 & 0xfd;
  m_Do_controller_pad::g_mDoCPd_cpadInfo[uVar1].mButton3 =
       (byte)(uVar4 << 1) & 0x10 | m_Do_controller_pad::g_mDoCPd_cpadInfo[uVar1].mButton3 & 0xef;
  m_Do_controller_pad::g_mDoCPd_cpadInfo[DAT_803b9159].field_0x34 = 0;
  *(short *)&this->field_0x65a = (short)(uVar2 >> 0x10);
  *(char *)&this->field_0x673 = '\x01' - (cRam803f6e77 == '\0');
  m_Do_ext::m_Do_gba_com::BigLittleChange(uRam803f6e78);
  *(undefined2 *)&this->field_0x630 = extraout_var;
  m_Do_ext::m_Do_gba_com::BigLittleChange(uRam803f6e7a);
  *(undefined2 *)&this->field_0x632 = extraout_var_00;
  *(char *)&this->field_0x67a = '\x01' - ((bRam803f6e76 >> 2 & 1) == 0);
  iVar3 = dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x1708);
  if ((iVar3 == 0) && ((bRam803f6e76 >> 3 & 1) != 0)) {
    dSv_event_c::onEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x1708);
  }
  iVar3 = dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x1a10);
  if ((iVar3 == 0) && ((bRam803f6e76 >> 4 & 1) != 0)) {
    dSv_event_c::onEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x1a10);
  }
  iVar3 = dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x1a08);
  if ((iVar3 == 0) && ((bRam803f6e76 >> 5 & 1) != 0)) {
    dSv_event_c::onEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x1a08);
  }
  return;
}


/* __thiscall daAgb_c::SwitchOn(void) */

void __thiscall daAgb_c::SwitchOn(daAgb_c *this)

{
  byte bVar1;
  int iVar2;
  uint switchNo;
  
  iVar2 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)();
  if (bRam803f6e7d == *(byte *)(iVar2 + 9) >> 1) {
    bVar1 = cRam803f6e7f - 1;
    if (mSwitch != 0xff) {
      dSv_info_c::revSwitch
                (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo,(uint)mSwitch,(uint)bRam803f6e7e);
    }
    if ((bVar1 != 9) && (switchNo = (uint)bRam803f6e80, switchNo != 0xff)) {
      if ((bVar1 < 2) || (bVar1 == 8)) {
        dSv_info_c::onSwitch
                  (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo,switchNo,(uint)bRam803f6e7e);
      }
      else {
        dSv_info_c::revSwitch
                  (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo,switchNo,(uint)bRam803f6e7e);
      }
    }
  }
  mDoGaC_agbCom_c::mDoGaC_DataStatusReset
            ((mDoGaC_agbCom_c *)&m_Do_ext::m_Do_gba_com::g_mDoGaC_gbaCom,'\b');
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall daAgb_c::GbaItemUse(void) */

void __thiscall daAgb_c::GbaItemUse(daAgb_c *this)

{
  daPy_lk_c *pdVar1;
  dStage_roomStatus_c *pdVar2;
  uint *puVar3;
  fopAc_ac_c *pfVar4;
  uint uVar5;
  bool bVar6;
  char cVar7;
  int iVar8;
  uint uVar9;
  double dVar10;
  float fVar11;
  undefined4 local_28 [2];
  undefined4 local_20;
  uint uStack28;
  
  uVar9 = (uint)mItem;
  iVar8 = 0;
  if (((uVar9 - 3 < 3) || (uVar9 == 0x11)) || (uVar9 == 0x12)) {
    pdVar2 = dStage_roomControl_c::getStatusRoomDt
                       (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mRoomCtrl,
                        (int)(char)dStage_roomControl_c::mStayNo);
    puVar3 = (uint *)(*(code *)((pdVar2->parent).parent.vtbl)->getFileListInfo)();
    if ((puVar3 == (uint *)0x0) || ((*puVar3 & 4) == 0)) {
      _mEffect = 0x20000;
      return;
    }
    if (*(char *)&this->field_0x67c != '\0') {
      _mEffect = m_Do_ext::m_Do_gba_com::BigLittleChange
                           ((uint)*(ushort *)&this->field_0x660 << 0x10 | 0x300);
      return;
    }
    if (uVar9 == 5) {
      fVar11 = SComponent::cM_rndF(d_a_agb::_5164);
      dVar10 = (double)fVar11;
      if ((double)d_a_agb::_4280 <= dVar10) {
        if (d_a_agb::_5165 <= dVar10) {
          if (d_a_agb::_5166 <= dVar10) {
            iVar8 = dSv_event_c::isEventBit
                              (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x2e08);
            if (iVar8 == 0) {
              iVar8 = 0xd;
            }
            else {
              iVar8 = 0xc;
            }
          }
          else {
            iVar8 = 0xd;
          }
        }
        else {
          iVar8 = 10;
        }
      }
      else {
        iVar8 = 0x13;
      }
      if (((iVar8 == 0xc) || (iVar8 == 0xd)) &&
         ((((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor)->parent).field_0x2a0 & 1) != 0))
      {
        iVar8 = 10;
      }
    }
  }
  pdVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor;
  if ((ushort)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mCurrRupees <
      (ushort)bRam803f6e85) {
    _mEffect = 0x10000;
    return;
  }
  switch(uVar9) {
  default:
    _mEffect = 0;
    return;
  case 2:
    if (*(char *)&this->field_0x67b != '\0') {
      _mEffect = m_Do_ext::m_Do_gba_com::BigLittleChange
                           ((uint)*(ushort *)&this->field_0x65e << 0x10 | 0x300);
      return;
    }
    if ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor !=
         d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor) &&
       (dVar10 = (double)f_op_actor_mng::fopAcM_searchActorDistanceXZ(this),
       dVar10 < (double)d_a_agb::_5167)) {
      _mEffect = 0;
      return;
    }
    if ((*(char *)&this->field_0x671 == '\0') && (*(char *)&this->field_0x677 != '\x01')) {
      uVar9 = 0xe;
      onFree(this);
      *(undefined2 *)&this->field_0x65c = 0x10e;
      *(float *)(*(int *)&this->field_0x2a0 + 0xc) = d_a_agb::_4686;
    }
    else {
      if ((*(char *)&this->field_0x671 == '\0') &&
         ((d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mDanBit._1_1_ < 0x18 &&
          (iVar8 = f_pc_executor::fpcEx_IsExist(*(undefined4 *)&this->field_0x650), iVar8 != 0)))) {
        local_28[0] = *(undefined4 *)&this->field_0x650;
        pfVar4 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,local_28);
        fVar11 = SComponent::cM_rndF(d_a_agb::_4279);
        if (d_a_agb::_5168 <= (double)fVar11) {
          *(undefined4 *)&this->field_0x640 = 4;
        }
        else {
          *(undefined4 *)&this->field_0x640 = 3;
        }
        *(float *)&this->field_0x634 = (pfVar4->mCurrent).mPos.x;
        *(float *)&this->field_0x638 = (pfVar4->mCurrent).mPos.y;
        *(float *)&this->field_0x63c = (pfVar4->mCurrent).mPos.z;
        d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mDanBit._1_1_ =
             d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mDanBit._1_1_ + 1;
        uVar9 = 0xf;
      }
      uVar5 = daBomb_c::prm_make(8,false,false);
      f_op_actor_mng::fopAcM_create
                (0x128,uVar5,&(this->parent).mCurrent.mPos,-1,(csXyz *)0x0,(cXyz *)0x0,0xff,
                 (undefined *)0x0);
      *(undefined2 *)&this->field_0x65c = 0x78;
    }
    break;
  case 3:
    ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor)->parent).field_0x29c =
         ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor)->parent).field_0x29c | 0x1000;
    *(undefined2 *)&pdVar1->field_0x354c = 0x96;
    resetCursor(this,false);
    *(undefined2 *)&this->field_0x65c = 0x96;
    *(float *)(*(int *)&this->field_0x2a0 + 0xc) = d_a_agb::_4686;
    break;
  case 4:
    if ((((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor)->parent).field_0x2a0 & 1) != 0) {
      _mEffect = 0;
      return;
    }
    (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor)->field_0x354e = 300;
    resetCursor(this,false);
    *(undefined2 *)&this->field_0x65c = 300;
    *(float *)(*(int *)&this->field_0x2a0 + 0xc) = d_a_agb::_4686;
    break;
  case 5:
    uVar9 = uVar9 | iVar8 << 8;
    resetCursor(this,false);
    break;
  case 7:
    bVar6 = d_com_inf_game::dComIfGs_checkGetItem(BaitBag);
    if (bVar6 != false) {
      cVar7 = dSv_player_bag_item_c::checkBaitItemEmpty
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem);
      if (cVar7 != '\0') {
        uVar9 = uVar9 | 0x1000000;
      }
      bVar6 = d_com_inf_game::dComIfGs_checkGetItem(Bombs);
      if ((bVar6 != false) &&
         (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._4_1_ <
          d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax.field_0x2)) {
        uVar9 = uVar9 | 0x10000;
      }
      if ((d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.mBowSlot != InvalidItem)
         && (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._3_1_ <
             d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax.field_0x1)) {
        uVar9 = uVar9 | 0x100;
      }
    }
    break;
  case 8:
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAdjustHp =
         (int)((float)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAdjustHp + d_a_agb::_5169);
    resetCursor(this,false);
    *(undefined2 *)&this->field_0x65c = 0x3c;
    break;
  case 9:
    d_com_inf_game::g_dComIfG_gameInfo.mPlay._18648_2_ =
         d_com_inf_game::g_dComIfG_gameInfo.mPlay._18648_2_ + 8;
    resetCursor(this,false);
    *(undefined2 *)&this->field_0x65c = 0x3c;
    break;
  case 10:
    uStack28 = (uint)(ushort)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                             mMaxHp;
    local_20 = 0x43300000;
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAdjustHp =
         (int)((float)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAdjustHp +
              (float)((double)CONCAT44(0x43300000,uStack28) - d_a_agb::_5172));
    d_com_inf_game::g_dComIfG_gameInfo.mPlay._18648_2_ =
         d_com_inf_game::g_dComIfG_gameInfo.mPlay._18648_2_ +
         (ushort)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mMaxMagic;
    resetCursor(this,false);
    *(undefined2 *)&this->field_0x65c = 0x3c;
    break;
  case 0xc:
    if (*(char *)&this->field_0x67c != '\0') {
      _mEffect = m_Do_ext::m_Do_gba_com::BigLittleChange
                           ((uint)*(ushort *)&this->field_0x660 << 0x10 | 0x300);
      return;
    }
    ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor)->parent).field_0x29c =
         ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor)->parent).field_0x29c | 0x1000;
    *(undefined2 *)&pdVar1->field_0x354c = 300;
    if ((((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor)->parent).field_0x2a0 & 1) == 0) {
      (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor)->field_0x354e = 300;
    }
    resetCursor(this,false);
    *(undefined2 *)&this->field_0x65c = 300;
    *(float *)(*(int *)&this->field_0x2a0 + 0xc) = d_a_agb::_4686;
    break;
  case 0xd:
    if (*(char *)&this->field_0x67c != '\0') {
      _mEffect = m_Do_ext::m_Do_gba_com::BigLittleChange
                           ((uint)*(ushort *)&this->field_0x660 << 0x10 | 0x300);
      return;
    }
    if ((((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor)->parent).field_0x2a0 & 1) != 0) {
      _mEffect = 0;
      return;
    }
    (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor)->field_0x354e = 600;
    resetCursor(this,false);
    *(undefined2 *)&this->field_0x65c = 600;
    *(float *)(*(int *)&this->field_0x2a0 + 0xc) = d_a_agb::_4686;
    break;
  case 0x10:
    if (((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor !=
          d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor) ||
        ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8 & 0x8000000U) != 0)) ||
       ((iVar8 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->vtbl->
                           checkPlayerFly)(), iVar8 != 0 &&
        (((d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8 & 0x100000U) == 0 &&
         ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8 & 0x10000U) == 0)))))) {
      _mEffect = m_Do_ext::m_Do_gba_com::BigLittleChange(0x1f0300);
      return;
    }
    if (*(char *)&this->field_0x67d != '\0') {
      _mEffect = m_Do_ext::m_Do_gba_com::BigLittleChange
                           ((uint)*(ushort *)&this->field_0x662 << 0x10 | 0x300);
      return;
    }
    *(undefined *)&this->field_0x67f = 1;
    break;
  case 0x11:
    _mEffect = m_Do_ext::m_Do_gba_com::BigLittleChange(uVar9);
    return;
  case 0x12:
    if ((((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor)->parent).field_0x2a0 & 1) != 0) {
      _mEffect = 0;
      return;
    }
    _mEffect = m_Do_ext::m_Do_gba_com::BigLittleChange(uVar9);
    return;
  case 0x13:
    resetCursor(this,false);
    *(undefined2 *)&this->field_0x65c = 0x1e;
    break;
  case 0x14:
    resetCursor(this,false);
    break;
  case 0x15:
    resetCursor(this,false);
    uVar5 = daBomb_c::prm_make(8,false,false);
    f_op_actor_mng::fopAcM_create
              (0x128,uVar5,&(this->parent).mCurrent.mPos,-1,(csXyz *)0x0,(cXyz *)0x0,0xff,
               (undefined *)0x0);
    *(undefined2 *)&this->field_0x65c = 0x78;
  }
  *(undefined *)&this->field_0x672 = 0;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAdjustRupees =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAdjustRupees - (uint)bRam803f6e85;
  _mEffect = m_Do_ext::m_Do_gba_com::BigLittleChange(uVar9);
  *(char *)&this->field_0x66b = (char)uVar9;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall daAgb_c::Shopping(void) */

void __thiscall daAgb_c::Shopping(daAgb_c *this)

{
  byte bVar1;
  char cVar2;
  bool bVar3;
  
  mItemBuy = mShop;
  bVar3 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode != 0;
  bVar1 = d_meter::dMenu_flag();
  if ((bVar3 | bVar1) == 0) {
    if ((ushort)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mCurrRupees <
        (ushort)bRam803f6e8a) {
      uRam803f6e71 = 3;
    }
    else {
      if (mShop == '\0') {
        if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax.field_0x1 <=
            d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._3_1_) {
          uRam803f6e71 = 2;
          return;
        }
        d_com_inf_game::g_dComIfG_gameInfo.mPlay.field_0x48e0 =
             d_com_inf_game::g_dComIfG_gameInfo.mPlay.field_0x48e0 + (ushort)bRam803f6e89;
      }
      else {
        if (mShop == '\x01') {
          if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax.field_0x2 <=
              d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._4_1_) {
            uRam803f6e71 = 2;
            return;
          }
          d_com_inf_game::g_dComIfG_gameInfo.mPlay._18660_2_ =
               d_com_inf_game::g_dComIfG_gameInfo.mPlay._18660_2_ + (ushort)bRam803f6e89;
        }
        else {
          cVar2 = dSv_player_bag_item_c::checkBaitItemEmpty
                            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem);
          if (cVar2 == '\0') {
            uRam803f6e71 = 2;
            return;
          }
          dSv_player_bag_item_c::setBaitItem
                    (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem,0x82);
        }
      }
      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAdjustRupees =
           d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAdjustRupees - (uint)bRam803f6e8a;
      uRam803f6e71 = 1;
    }
  }
  else {
    uRam803f6e71 = 0;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall daAgb_c::FlagsSend(unsigned long) */

void __thiscall daAgb_c::FlagsSend(daAgb_c *this,ulong param_1)

{
  undefined2 extraout_var;
  byte bVar6;
  int iVar1;
  cXyz *pcVar2;
  undefined2 uVar5;
  uint uVar3;
  undefined4 uVar4;
  bool bVar7;
  
  if ((*(char *)&this->field_0x670 == '\0') ||
     (((param_1 != 1 && (1 < param_1 - 5)) && (param_1 != 7)))) {
    d_com_inf_game::g_dComIfG_gameInfo._119262_1_ =
         d_com_inf_game::g_dComIfG_gameInfo._119262_1_ & 0xfe | 1;
  }
  else {
    d_com_inf_game::g_dComIfG_gameInfo._119262_1_ =
         d_com_inf_game::g_dComIfG_gameInfo._119262_1_ & 0xfe;
  }
  bVar6 = d_meter::dMenu_flag();
  d_com_inf_game::g_dComIfG_gameInfo._119262_1_ =
       (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode != 0) << 2 |
       (byte)((bVar6 & 1) << 1) | d_com_inf_game::g_dComIfG_gameInfo._119262_1_ & 0xf9;
  iVar1 = d_stage::dStage_checkRestart();
  if ((iVar1 == 0) && ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8 & 0x20000000U) == 0)) {
    d_com_inf_game::g_dComIfG_gameInfo._119262_1_ =
         d_com_inf_game::g_dComIfG_gameInfo._119262_1_ & 0xf7;
  }
  else {
    d_com_inf_game::g_dComIfG_gameInfo._119262_1_ =
         d_com_inf_game::g_dComIfG_gameInfo._119262_1_ & 0xf7 | 8;
  }
  m_Do_ext::m_Do_gba_com::BigLittleChange
            (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mCurrRupees);
  d_com_inf_game::g_dComIfG_gameInfo._119257_1_ =
       d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mCurrentWalletIndex & 3 |
       d_com_inf_game::g_dComIfG_gameInfo._119257_1_ & 0xfc;
  d_com_inf_game::g_dComIfG_gameInfo._119252_2_ = extraout_var;
  iVar1 = d_kankyo_wether::dKyw_gbwind_use_check();
  if (iVar1 == 0) {
    d_com_inf_game::g_dComIfG_gameInfo._119263_1_ =
         d_com_inf_game::g_dComIfG_gameInfo._119263_1_ & 0xfd;
  }
  else {
    d_com_inf_game::g_dComIfG_gameInfo._119263_1_ =
         d_com_inf_game::g_dComIfG_gameInfo._119263_1_ & 0xfd | 2;
    if ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode == 0) ||
       ((iVar1 = dEvent_manager_c::startCheckOld
                           (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,"TACT_WINDOW2_SHIP")
        , iVar1 == 0 &&
        (iVar1 = dEvent_manager_c::startCheckOld
                           (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,"TACT_WINDOW2"),
        iVar1 == 0)))) {
      pcVar2 = d_kankyo_wether::dKyw_get_wind_vec();
      iVar1 = SComponent::cM_atan2s(pcVar2->x,pcVar2->z);
      uVar5 = (undefined2)iVar1;
    }
    else {
      uVar5 = *(undefined2 *)&this->field_0x658;
    }
    d_com_inf_game::g_dComIfG_gameInfo._119254_1_ = (undefined)((ushort)uVar5 >> 8);
    *(undefined2 *)&this->field_0x658 = uVar5;
  }
  iVar1 = d_com_inf_game::dComIfGs_isStageTbox(3,0xf);
  d_com_inf_game::g_dComIfG_gameInfo._119255_1_ =
       (iVar1 != 0) << 3 | d_com_inf_game::g_dComIfG_gameInfo._119255_1_ & 0xf7;
  iVar1 = d_com_inf_game::dComIfGs_isStageTbox(4,0xf);
  d_com_inf_game::g_dComIfG_gameInfo._119255_1_ =
       (iVar1 != 0) << 4 | d_com_inf_game::g_dComIfG_gameInfo._119255_1_ & 0xef;
  iVar1 = d_com_inf_game::dComIfGs_isStageTbox(5,0xf);
  d_com_inf_game::g_dComIfG_gameInfo._119255_1_ =
       (iVar1 != 0) << 5 | d_com_inf_game::g_dComIfG_gameInfo._119255_1_ & 0xdf;
  iVar1 = d_com_inf_game::dComIfGs_isStageTbox(6,0xf);
  d_com_inf_game::g_dComIfG_gameInfo._119255_1_ =
       (iVar1 != 0) << 6 | d_com_inf_game::g_dComIfG_gameInfo._119255_1_ & 0xbf;
  iVar1 = d_com_inf_game::dComIfGs_isStageTbox(7,0xf);
  d_com_inf_game::g_dComIfG_gameInfo._119255_1_ =
       (iVar1 != 0) << 7 | d_com_inf_game::g_dComIfG_gameInfo._119255_1_ & 0x7f;
  d_com_inf_game::g_dComIfG_gameInfo._119256_1_ =
       (undefined)((*(ushort *)&this->field_0x65c + 0x1d) / 0x1e);
  uVar3 = d_kankyo::dKy_get_dayofweek();
  d_com_inf_game::g_dComIfG_gameInfo._119258_1_ =
       (byte)((uVar3 & 0xff) << 5) | d_com_inf_game::g_dComIfG_gameInfo._119258_1_ & 0x1f;
  bVar6 = d_kankyo::dKy_getdaytime_hour();
  d_com_inf_game::g_dComIfG_gameInfo._119258_1_ =
       bVar6 & 0x1f | d_com_inf_game::g_dComIfG_gameInfo._119258_1_ & 0xe0;
  bVar6 = d_kankyo::dKy_getdaytime_minute();
  d_com_inf_game::g_dComIfG_gameInfo._119259_1_ =
       bVar6 & 0x3f | d_com_inf_game::g_dComIfG_gameInfo._119259_1_ & 0xc0;
  d_com_inf_game::g_dComIfG_gameInfo._119260_1_ =
       (byte)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mCurrHp & 0x7f |
       d_com_inf_game::g_dComIfG_gameInfo._119260_1_ & 0x80;
  iVar1 = dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x1708);
  d_com_inf_game::g_dComIfG_gameInfo._119262_1_ =
       (byte)(iVar1 << 6) & 0x40 | d_com_inf_game::g_dComIfG_gameInfo._119262_1_ & 0xbf;
  iVar1 = dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x1a10);
  d_com_inf_game::g_dComIfG_gameInfo._119259_1_ =
       (byte)(iVar1 << 6) & 0x40 | d_com_inf_game::g_dComIfG_gameInfo._119259_1_ & 0xbf;
  iVar1 = dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x1a08);
  d_com_inf_game::g_dComIfG_gameInfo._119259_1_ =
       (byte)(iVar1 << 7) | d_com_inf_game::g_dComIfG_gameInfo._119259_1_ & 0x7f;
  iVar1 = dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0xf80);
  if ((iVar1 == 0) ||
     (iVar1 = dSv_event_c::isEventBit
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x1e80),
     iVar1 != 0)) {
    d_com_inf_game::g_dComIfG_gameInfo._119261_1_ =
         d_com_inf_game::g_dComIfG_gameInfo._119261_1_ & 0xf8;
  }
  else {
    iVar1 = dSv_player_collect_c::isSymbol
                      (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x02');
    if (iVar1 == 0) {
      iVar1 = dSv_player_collect_c::isSymbol
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x01');
      if (iVar1 == 0) {
        d_com_inf_game::g_dComIfG_gameInfo._119261_1_ =
             d_com_inf_game::g_dComIfG_gameInfo._119261_1_ & 0xf8 | 1;
      }
      else {
        d_com_inf_game::g_dComIfG_gameInfo._119261_1_ =
             d_com_inf_game::g_dComIfG_gameInfo._119261_1_ & 0xf8 | 2;
      }
    }
    else {
      d_com_inf_game::g_dComIfG_gameInfo._119261_1_ =
           d_com_inf_game::g_dComIfG_gameInfo._119261_1_ & 0xf8 | 4;
    }
  }
  iVar1 = dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x3920);
  if (iVar1 == 0) {
    d_com_inf_game::g_dComIfG_gameInfo._119261_1_ =
         d_com_inf_game::g_dComIfG_gameInfo._119261_1_ & 199;
  }
  else {
    uVar4 = dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x1480)
    ;
    uVar3 = countLeadingZeros(uVar4);
    d_com_inf_game::g_dComIfG_gameInfo._119261_1_ =
         (byte)((uVar3 >> 5 & 0xff) << 3) & 8 | d_com_inf_game::g_dComIfG_gameInfo._119261_1_ & 0xf7
    ;
    uVar4 = dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x1440)
    ;
    uVar3 = countLeadingZeros(uVar4);
    d_com_inf_game::g_dComIfG_gameInfo._119261_1_ =
         (byte)((uVar3 >> 5 & 0xff) << 4) & 0x10 |
         d_com_inf_game::g_dComIfG_gameInfo._119261_1_ & 0xef;
    uVar4 = dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x1410)
    ;
    uVar3 = countLeadingZeros(uVar4);
    d_com_inf_game::g_dComIfG_gameInfo._119261_1_ =
         (byte)((uVar3 >> 5 & 0xff) << 5) & 0x20 |
         d_com_inf_game::g_dComIfG_gameInfo._119261_1_ & 0xdf;
  }
  iVar1 = dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x1820);
  if (iVar1 == 0) {
    d_com_inf_game::g_dComIfG_gameInfo._119261_1_ =
         d_com_inf_game::g_dComIfG_gameInfo._119261_1_ & 0x3f;
  }
  else {
    uVar4 = d_com_inf_game::dComIfGs_isStageBossEnemy(7);
    uVar3 = countLeadingZeros(uVar4);
    d_com_inf_game::g_dComIfG_gameInfo._119261_1_ =
         (byte)((uVar3 >> 5 & 0xff) << 6) & 0x40 |
         d_com_inf_game::g_dComIfG_gameInfo._119261_1_ & 0xbf;
    uVar4 = d_com_inf_game::dComIfGs_isStageBossEnemy(6);
    uVar3 = countLeadingZeros(uVar4);
    d_com_inf_game::g_dComIfG_gameInfo._119261_1_ =
         (byte)((uVar3 >> 5 & 0xff) << 7) | d_com_inf_game::g_dComIfG_gameInfo._119261_1_ & 0x7f;
  }
  iVar1 = dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x1e40);
  d_com_inf_game::g_dComIfG_gameInfo._119262_1_ =
       *(char *)&this->field_0x671 << 7 |
       (byte)(iVar1 << 4) & 0x10 | d_com_inf_game::g_dComIfG_gameInfo._119262_1_ & 0x6f;
  d_com_inf_game::g_dComIfG_gameInfo._119263_1_ =
       *(byte *)&this->field_0x677 & 1 | d_com_inf_game::g_dComIfG_gameInfo._119263_1_ & 0xfe;
  if (param_1 == 6) {
    d_com_inf_game::g_dComIfG_gameInfo._119260_1_ =
         d_com_inf_game::g_dComIfG_gameInfo._119260_1_ & 0x7f | 0x80;
  }
  else {
    d_com_inf_game::g_dComIfG_gameInfo._119260_1_ =
         d_com_inf_game::g_dComIfG_gameInfo._119260_1_ & 0x7f;
  }
  bVar6 = dSv_player_collect_c::isTact
                    (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\0');
  if (((m_Do_controller_pad::g_mDoCPd_cpadInfo[0]._48_2_ == 0) &&
      (m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mStickMainValue == d_a_agb::_4278)) &&
     (m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mStickCValue == d_a_agb::_4278)) {
    d_com_inf_game::g_dComIfG_gameInfo._119255_1_ =
         bVar6 & 1 | d_com_inf_game::g_dComIfG_gameInfo._119255_1_ & 0xfc;
  }
  else {
    d_com_inf_game::g_dComIfG_gameInfo._119255_1_ =
         bVar6 & 1 | d_com_inf_game::g_dComIfG_gameInfo._119255_1_ & 0xfc | 2;
  }
  if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mMaxMagic == 0) {
    d_com_inf_game::g_dComIfG_gameInfo._119263_1_ =
         d_com_inf_game::g_dComIfG_gameInfo._119263_1_ & 0x7f;
  }
  else {
    d_com_inf_game::g_dComIfG_gameInfo._119263_1_ =
         d_com_inf_game::g_dComIfG_gameInfo._119263_1_ & 0x7f | 0x80;
  }
  d_com_inf_game::g_dComIfG_gameInfo._119257_1_ =
       (*(byte *)&this->field_0x675 & 1) << 5 | d_com_inf_game::g_dComIfG_gameInfo._119257_1_ & 0xdf
  ;
  bVar7 = d_com_inf_game::dComIfGs_checkGetItem(cabana_deed);
  d_com_inf_game::g_dComIfG_gameInfo._119257_1_ =
       (bVar7 != false) << 6 | d_com_inf_game::g_dComIfG_gameInfo._119257_1_ & 0xbf;
  mDoGaC_agbCom_c::mDoGaC_SendDataSet
            ((mDoGaC_agbCom_c *)&m_Do_ext::m_Do_gba_com::g_mDoGaC_gbaCom,
             (ulong *)&d_com_inf_game::g_dComIfG_gameInfo.field_0x1d1d4,0xc,'\t',0);
  return;
}


/* WARNING: Inlined function: __save_gpr */
/* WARNING: Inlined function: __restore_gpr */
/* WARNING: Removing unreachable block (ram,0x800d25b0) */
/* WARNING: Removing unreachable block (ram,0x800d25b8) */
/* __thiscall daAgb_c::CursorMove(fopAc_ac_c *,
                                  unsigned long) */

void __thiscall daAgb_c::CursorMove(daAgb_c *this,fopAc_ac_c *param_1,ulong param_2)

{
  byte bVar1;
  float fVar2;
  daPy_lk_c *pdVar3;
  int iVar4;
  dStage_roomStatus_c *pdVar5;
  char cVar6;
  cBgS_PolyPassChk *pcVar7;
  cBgS_PolyPassChk *pcVar8;
  int iVar9;
  undefined4 uVar10;
  double dVar11;
  undefined8 in_f30;
  undefined8 in_f31;
  double dVar12;
  double dVar13;
  cXyz local_1e8;
  float local_1dc;
  float local_1d8;
  float local_1d4;
  cXyz local_1d0;
  cXyz local_1c4;
  cXyz local_1b8;
  cXyz local_1ac;
  float local_1a0;
  float local_19c;
  float local_198;
  cBgS_GndChk local_194;
  cBgS_PolyPassChk local_154;
  undefined local_148 [8];
  undefined local_140 [104];
  uint local_d8;
  dBgS_LinChk local_d4;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  pdVar3 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor;
  uVar10 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  if (param_2 == 7) {
    if (*(char *)&this->field_0x67e == '\0') {
      dVar12 = (double)d_a_agb::_4276;
    }
    else {
      dVar12 = (double)d_a_agb::_4275;
    }
  }
  else {
    dVar12 = (double)d_a_agb::_4274;
  }
  iVar4 = SComponent::cLib_chaseF
                    ((float *)&this->field_0x628,d_a_agb::_4644,*(float *)&this->field_0x62c);
  if ((((iVar4 != 0) && (*(char *)&this->field_0x673 != '\0')) &&
      (*(char *)&this->field_0x672 != '\0')) &&
     ((*(char *)&this->field_0x674 == '\0' &&
      (bVar1 = m_Do_controller_pad::g_mDoCPd_cpadInfo[DAT_803b9159].mButton0, (bVar1 >> 1 & 1) == 0)
      ))) {
    if ((char)bVar1 < '\0') {
      (param_1->mOrig).mPos.x = (float)((double)(param_1->mOrig).mPos.x - dVar12);
    }
    else {
      if ((bVar1 >> 6 & 1) != 0) {
        (param_1->mOrig).mPos.x = (float)((double)(param_1->mOrig).mPos.x + dVar12);
      }
    }
    if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[DAT_803b9159].mButton0 >> 4 & 1) == 0) {
      if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[DAT_803b9159].mButton0 >> 5 & 1) != 0) {
        (param_1->mOrig).mPos.z = (float)((double)(param_1->mOrig).mPos.z + dVar12);
      }
    }
    else {
      (param_1->mOrig).mPos.z = (float)((double)(param_1->mOrig).mPos.z - dVar12);
    }
    if ((param_2 == 7) && (*(char *)&this->field_0x67e == '\0')) {
      fVar2 = (param_1->mOrig).mPos.x;
      if (d_a_agb::_5802 <= fVar2) {
        if (d_a_agb::_5803 < fVar2) {
          (param_1->mOrig).mPos.x = d_a_agb::_5803;
        }
      }
      else {
        (param_1->mOrig).mPos.x = d_a_agb::_5802;
      }
      fVar2 = (param_1->mOrig).mPos.z;
      if (d_a_agb::_5802 <= fVar2) {
        if (d_a_agb::_5803 < fVar2) {
          (param_1->mOrig).mPos.z = d_a_agb::_5803;
        }
      }
      else {
        (param_1->mOrig).mPos.z = d_a_agb::_5802;
      }
    }
    else {
      pdVar5 = dStage_roomControl_c::getStatusRoomDt
                         (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mRoomCtrl,
                          (int)(char)dStage_roomControl_c::mStayNo);
      iVar4 = (*(code *)((pdVar5->parent).parent.vtbl)->getMapInfo)();
      if (iVar4 != 0) {
        fVar2 = (param_1->mOrig).mPos.x;
        if (*(float *)(iVar4 + 0x18) <= fVar2) {
          if (*(float *)(iVar4 + 0x20) < fVar2) {
            (param_1->mOrig).mPos.x = *(float *)(iVar4 + 0x20);
          }
        }
        else {
          (param_1->mOrig).mPos.x = *(float *)(iVar4 + 0x18);
        }
        fVar2 = (param_1->mOrig).mPos.z;
        if (*(float *)(iVar4 + 0x1c) <= fVar2) {
          if (*(float *)(iVar4 + 0x24) < fVar2) {
            (param_1->mOrig).mPos.z = *(float *)(iVar4 + 0x24);
          }
        }
        else {
          (param_1->mOrig).mPos.z = *(float *)(iVar4 + 0x1c);
        }
      }
    }
    SComponent::cLib_chaseF((float *)&param_1->mCurrent,(param_1->mOrig).mPos.x,(float)dVar12);
    SComponent::cLib_chaseF(&(param_1->mCurrent).mPos.z,(param_1->mOrig).mPos.z,(float)dVar12);
    dVar12 = (double)f_op_actor_mng::fopAcM_searchActorDistanceXZ
                               (param_1,d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor);
    if ((double)d_a_agb::_5804 < dVar12) {
      if ((*(char *)&this->field_0x671 == '\0') && (*(char *)&this->field_0x677 != '\0')) {
        *(undefined *)&this->field_0x671 = 0;
        *(undefined *)&this->field_0x677 = 0;
        *(undefined4 *)&this->field_0x650 = 0xffffffff;
      }
      else {
        ::cXyz::operator__(&local_1e8,&(pdVar3->parent).parent.mCurrent.mPos,
                           &(param_1->mCurrent).mPos);
        fVar2 = d_a_agb::_5804;
        local_1a0 = local_1e8.x;
        local_19c = local_1e8.y;
        local_198 = local_1e8.z;
        (param_1->mOrig).mPos.x =
             (pdVar3->parent).parent.mCurrent.mPos.x -
             (float)((double)(d_a_agb::_5804 * local_1e8.x) / dVar12);
        (param_1->mOrig).mPos.z =
             (pdVar3->parent).parent.mCurrent.mPos.z -
             (float)((double)(fVar2 * local_1e8.z) / dVar12);
      }
    }
  }
  local_1b8.x = (param_1->mNext).mPos.x;
  local_1ac.y = (param_1->mNext).mPos.y;
  local_1b8.z = (param_1->mNext).mPos.z;
  local_1b8.y = local_1ac.y + d_a_agb::_5805;
  local_d4.parent.parent.mpPolyPassChk = (cBgS_PolyPassChk *)0x0;
  local_d4.parent.parent.mpGrpPassChk = (cBgS_GrpPassChk *)0x0;
  local_d4.parent.parent.mbExcludeSameProcID = true;
  local_d4.parent.mPolyInfo.mTriIdx = -1;
  local_d4.parent.mPolyInfo.mBgIndex = 0x100;
  local_d4.parent.mPolyInfo.mpBgW = (cBgW *)0x0;
  local_d4.parent.mPolyInfo.mProcID = -1;
  local_d4.parent.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_LinChk::__vt;
  local_d4.parent.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&PTR_80371fbc;
  local_d4.parent.mLin.vtbl = (undefined *)&::cM3dGLin::__vt;
  local_1ac.x = local_1b8.x;
  local_1ac.z = local_1b8.z;
  ::cBgS_LinChk::ct(&local_d4.parent);
  pcVar8 = (cBgS_PolyPassChk *)&local_d4.mPolyPassChk;
  local_d4.mPolyPassChk.parent.mbObjThrough = 0;
  local_d4.mPolyPassChk.parent.mbCamThrough = 0;
  local_d4.mPolyPassChk.parent.mbArrowsAndLightThrough = 0;
  local_d4.mPolyPassChk.parent.mbBombThrough = 0;
  local_d4.mPolyPassChk.parent.mbBoomerangThrough = 0;
  local_d4.mPolyPassChk.parent.mbHookshotThrough = 0;
  local_d4.mGrpPassChk.parent.mAttr = 1;
  local_d4.parent.parent.mpGrpPassChk = (cBgS_GrpPassChk *)pcVar8;
  if (pcVar8 != (cBgS_PolyPassChk *)0x0) {
    local_d4.parent.parent.mpGrpPassChk = (cBgS_GrpPassChk *)&local_d4.mGrpPassChk;
  }
  local_d4.parent.parent.vtbl = (cBgS_Chk__vtbl *)&dBgS_LinkLinChk::__vt;
  local_d4.parent.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&DAT_803897ac;
  local_d4.mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&DAT_803897b8;
  local_d4.mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&DAT_803897c4;
  local_d4.mPolyPassChk.parent.mbLinkThrough = 1;
  local_d4.parent.parent.mpPolyPassChk = pcVar8;
  ::dBgS_LinChk::Set(&local_d4,&local_1ac,&local_1b8,param_1);
  local_d4.parent.mFlags = local_d4.parent.mFlags & 0x3fffffff;
  dVar12 = (double)d_a_agb::_5805;
  cVar6 = cBgS::LineCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,&local_d4.parent);
  if (cVar6 != '\0') {
    dVar12 = (double)((local_d4.parent.mLin.mP1.y - d_a_agb::_5806) - (param_1->mCurrent).mPos.y);
    if (dVar12 < (double)d_a_agb::_5807) {
      dVar12 = (double)d_a_agb::_5807;
    }
  }
  *(float *)&this->field_0x310 = (float)dVar12;
  *(float *)&this->field_0x314 = d_a_agb::_4275;
  ::dBgS_AcchCir::SetWall((dBgS_AcchCir *)&this->field_0x5e8,(float)dVar12,d_a_agb::_5808);
  dBgS_CrrPos::CrrPos((dBgS_CrrPos *)&this->field_0x2d4,
                      &d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS);
  dBgS_Acch::CrrPos((dBgS_Acch *)&this->field_0x424,&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS);
  local_1c4.x = (param_1->mNext).mPos.x;
  local_1c4.z = (param_1->mNext).mPos.z;
  local_1c4.y = (float)((double)(param_1->mNext).mPos.y + dVar12);
  local_1d0.x = (param_1->mCurrent).mPos.x;
  local_1d0.z = (param_1->mCurrent).mPos.z;
  local_1d0.y = (float)((double)(param_1->mCurrent).mPos.y + dVar12);
  local_140._0_4_ = (cBgS_PolyPassChk *)0x0;
  local_140._4_4_ = (cBgS_PolyPassChk *)0x0;
  local_140[12] = true;
  local_140._20_2_ = -1;
  local_140._22_2_ = 0x100;
  local_140._24_4_ = (cBgW *)0x0;
  local_140._28_4_ = -1;
  local_140._16_4_ = &::cBgS_LinChk::__vt;
  local_140._32_4_ = &PTR_80371fbc;
  local_140._60_4_ = &::cM3dGLin::__vt;
  ::cBgS_LinChk::ct((cBgS_LinChk *)local_140);
  pcVar7 = (cBgS_PolyPassChk *)(local_140 + 0x58);
  local_140[92] = 0;
  local_140[93] = 0;
  local_140[95] = 0;
  local_140[96] = 0;
  local_140[97] = 0;
  local_140[98] = 0;
  local_d8 = 1;
  local_140._4_4_ = pcVar7;
  if (pcVar7 != (cBgS_PolyPassChk *)0x0) {
    local_140._4_4_ = (cBgS_PolyPassChk *)(local_140 + 100);
  }
  local_140._16_4_ = &dBgS_LinkLinChk::__vt;
  local_140._32_4_ = (undefined **)&DAT_803897ac;
  local_140._88_4_ = (undefined **)&DAT_803897b8;
  local_140._100_4_ = (undefined **)&DAT_803897c4;
  local_140[94] = 1;
  local_140._0_4_ = pcVar7;
  ::dBgS_LinChk::Set((dBgS_LinChk *)local_140,&local_1c4,&local_1d0,param_1);
  cVar6 = cBgS::LineCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,(cBgS_LinChk *)local_140
                         );
  if (cVar6 != '\0') {
    (param_1->mCurrent).mPos.x = (param_1->mNext).mPos.x;
    (param_1->mCurrent).mPos.y = (param_1->mNext).mPos.y;
    (param_1->mCurrent).mPos.z = (param_1->mNext).mPos.z;
  }
  local_140._88_4_ = &PTR_80371f44;
  local_140._100_4_ = &PTR_80371f50;
  if (pcVar7 != (cBgS_PolyPassChk *)0x0) {
    local_140._88_4_ = &::dBgS_Chk::__vt;
    local_140._100_4_ = &PTR_80371f68;
    if (((undefined *)register0x00000004 != (undefined *)0xdc) &&
       (local_140._100_4_ = &::dBgS_GrpPassChk::__vt,
       (undefined *)register0x00000004 != (undefined *)0xdc)) {
      local_140._100_4_ = &::cBgS_GrpPassChk::__vt;
    }
    if ((pcVar7 != (cBgS_PolyPassChk *)0x0) &&
       (local_140._88_4_ = &::dBgS_PolyPassChk::__vt, pcVar7 != (cBgS_PolyPassChk *)0x0)) {
      local_140._88_4_ = &::cBgS_PolyPassChk::__vt;
    }
  }
  local_140._16_4_ = &::cBgS_LinChk::__vt;
  local_140._60_4_ = &::cM3dGLin::__vt;
  local_140._32_4_ = &::cBgS_PolyInfo::__vt;
  cBgS_Chk::_cBgS_Chk((cBgS_Chk *)local_140);
  iVar4 = dBgS::GetRoomId(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,
                          (cBgS_PolyInfo *)&this->field_0x3a0);
  (param_1->mTevStr).mRoomNo = (byte)iVar4;
  (param_1->mCurrent).mRoomNo = (byte)iVar4;
  if (iVar4 == (char)(pdVar3->parent).parent.mCurrent.mRoomNo) {
    *(undefined *)&this->field_0x679 = 1;
    if ((*(uint *)&this->field_0x30c & 0x20) != 0) {
      (param_1->mOrig).mPos.x = (param_1->mCurrent).mPos.x;
    }
    if ((*(uint *)&this->field_0x30c & 0x40) != 0) {
      (param_1->mOrig).mPos.z = (param_1->mCurrent).mPos.z;
    }
    ::cBgS_GndChk::cBgS_GndChk(&local_194);
    pcVar7 = &local_154;
    local_154.mbObjThrough = 0;
    local_154.mbCamThrough = 0;
    local_154.mbLinkThrough = 0;
    local_154.mbArrowsAndLightThrough = 0;
    local_154.mbBombThrough = 0;
    local_154.mbBoomerangThrough = 0;
    local_154.mbHookshotThrough = 0;
    local_148._4_4_ = 1;
    local_194.parent.vtbl = &::dBgS_GndChk::__vt;
    local_194.mPolyInfo.vtbl = &cBgS_PolyInfo__vtbl_80371f08;
    local_154.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
    local_148._0_4_ = &PTR_80371f20;
    local_194.parent.mpGrpPassChk = (cBgS_GrpPassChk *)pcVar7;
    if (pcVar7 != (cBgS_PolyPassChk *)0x0) {
      local_194.parent.mpGrpPassChk = (cBgS_GrpPassChk *)local_148;
    }
    dVar12 = (double)d_a_agb::_5809;
    local_194.mFlagIn = local_194.mFlagIn & 0xfffffffd;
    local_1d8 = d_a_agb::_5810 + (param_1->mCurrent).mPos.y;
    iVar4 = 0;
    iVar9 = 0;
    dVar13 = (double)local_1d8;
    local_194.parent.mpPolyPassChk = pcVar7;
    do {
      local_1dc = (param_1->mCurrent).mPos.x + *(float *)((int)&d_a_agb::l_ckOffset_5504 + iVar9);
      local_1d4 = (param_1->mCurrent).mPos.z + *(float *)((int)&DAT_80389584 + iVar9);
      local_194.mPos.y = (float)dVar13;
      local_194.mPos.x = local_1dc;
      local_194.mPos.z = local_1d4;
      dVar11 = (double)cBgS::GroundCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                                         &local_194);
      if (dVar12 < dVar11) {
        dVar12 = dVar11;
      }
      iVar4 = iVar4 + 1;
      iVar9 = iVar9 + 8;
    } while (iVar4 < 4);
    SComponent::cLib_chaseF(&(param_1->mCurrent).mPos.y,(param_1->mOrig).mPos.y,d_a_agb::_4274);
    dVar13 = (double)(param_1->mCurrent).mPos.y;
    if ((dVar13 < dVar12) &&
       (dVar12 < (double)(d_a_agb::_4642 + (float)((double)d_a_agb::_4277 + dVar13)))) {
      (param_1->mOrig).mPos.y = (float)dVar12;
    }
    local_154.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
    local_148._0_4_ = &PTR_80371f20;
    if (pcVar7 != (cBgS_PolyPassChk *)0x0) {
      local_154.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
      local_148._0_4_ = &PTR_80371f68;
      if (((undefined *)register0x00000004 != (undefined *)0x148) &&
         (local_148._0_4_ = &::dBgS_GrpPassChk::__vt,
         (undefined *)register0x00000004 != (undefined *)0x148)) {
        local_148._0_4_ = &::cBgS_GrpPassChk::__vt;
      }
      if ((pcVar7 != (cBgS_PolyPassChk *)0x0) &&
         (local_154.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
         pcVar7 != (cBgS_PolyPassChk *)0x0)) {
        local_154.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
      }
    }
    local_194.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_GndChk::__vt;
    local_194.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
    cBgS_Chk::_cBgS_Chk(&local_194.parent);
    local_d4.mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f44;
    local_d4.mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_80371f50;
    if (pcVar8 != (cBgS_PolyPassChk *)0x0) {
      local_d4.mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
      local_d4.mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_80371f68;
      if (((undefined *)register0x00000004 != (undefined *)0x70) &&
         (local_d4.mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&::dBgS_GrpPassChk::__vt,
         (undefined *)register0x00000004 != (undefined *)0x70)) {
        local_d4.mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&::cBgS_GrpPassChk::__vt;
      }
      if ((pcVar8 != (cBgS_PolyPassChk *)0x0) &&
         (local_d4.mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
         pcVar8 != (cBgS_PolyPassChk *)0x0)) {
        local_d4.mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
      }
    }
    local_d4.parent.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_LinChk::__vt;
    local_d4.parent.mLin.vtbl = (undefined *)&::cM3dGLin::__vt;
    local_d4.parent.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
    cBgS_Chk::_cBgS_Chk((cBgS_Chk *)&local_d4);
  }
  else {
    local_d4.mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f44;
    local_d4.mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_80371f50;
    if (pcVar8 != (cBgS_PolyPassChk *)0x0) {
      local_d4.mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
      local_d4.mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_80371f68;
      if (((undefined *)register0x00000004 != (undefined *)0x70) &&
         (local_d4.mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&::dBgS_GrpPassChk::__vt,
         (undefined *)register0x00000004 != (undefined *)0x70)) {
        local_d4.mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&::cBgS_GrpPassChk::__vt;
      }
      if ((pcVar8 != (cBgS_PolyPassChk *)0x0) &&
         (local_d4.mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
         pcVar8 != (cBgS_PolyPassChk *)0x0)) {
        local_d4.mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
      }
    }
    local_d4.parent.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_LinChk::__vt;
    local_d4.parent.mLin.vtbl = (undefined *)&::cM3dGLin::__vt;
    local_d4.parent.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
    cBgS_Chk::_cBgS_Chk((cBgS_Chk *)&local_d4);
  }
  __psq_l0(auStack8,uVar10);
  __psq_l1(auStack8,uVar10);
  __psq_l0(auStack24,uVar10);
  __psq_l1(auStack24,uVar10);
  return;
}


/* __thiscall dBgS_LinkLinChk::~dBgS_LinkLinChk(void) */

void __thiscall dBgS_LinkLinChk::_dBgS_LinkLinChk(dBgS_LinkLinChk *this)

{
  short in_r4;
  
  if (this != (dBgS_LinkLinChk *)0x0) {
    (this->parent).parent.parent.vtbl = (cBgS_Chk__vtbl *)&__vt;
    (this->parent).parent.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&DAT_803897ac;
    (this->parent).mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&DAT_803897b8;
    (this->parent).mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&DAT_803897c4;
    if (this != (dBgS_LinkLinChk *)0x0) {
      (this->parent).parent.parent.vtbl = (cBgS_Chk__vtbl *)&::dBgS_LinChk::__vt;
      (this->parent).parent.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&DAT_80371f38;
      (this->parent).mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f44;
      (this->parent).mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_80371f50;
      if (this != (dBgS_LinkLinChk *)0xffffffa8) {
        (this->parent).mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
        (this->parent).mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_80371f68;
        if (this != (dBgS_LinkLinChk *)0xffffff9c) {
          (this->parent).mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&::dBgS_GrpPassChk::__vt
          ;
          if (this != (dBgS_LinkLinChk *)0xffffff9c) {
            (this->parent).mGrpPassChk.parent.vtbl =
                 (cBgS_GrpPassChk__vtbl *)&::cBgS_GrpPassChk::__vt;
          }
        }
        if ((this != (dBgS_LinkLinChk *)0xffffffa8) &&
           ((this->parent).mPolyPassChk.parent.vtbl =
                 (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
           this != (dBgS_LinkLinChk *)0xffffffa8)) {
          (this->parent).mPolyPassChk.parent.vtbl =
               (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
        }
      }
      if (this != (dBgS_LinkLinChk *)0x0) {
        (this->parent).parent.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_LinChk::__vt;
        (this->parent).parent.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&PTR_80371fbc;
        if (this != (dBgS_LinkLinChk *)0xffffffdc) {
          (this->parent).parent.mLin.vtbl = (undefined *)&::cM3dGLin::__vt;
        }
        if (this != (dBgS_LinkLinChk *)0xffffffec) {
          (this->parent).parent.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
        }
        cBgS_Chk::_cBgS_Chk((cBgS_Chk *)this);
      }
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall daAgb_c::modeMove(void) */

void __thiscall daAgb_c::modeMove(daAgb_c *this)

{
  char cVar1;
  daPy_lk_c *pdVar2;
  uint uVar3;
  byte bVar7;
  int iVar4;
  short sVar6;
  dAttList_c *this_00;
  fopAc_ac_c *pfVar5;
  fopAcM__Status fVar8;
  uint uVar9;
  bool bVar10;
  double dVar11;
  double dVar12;
  float fVar13;
  undefined4 local_60;
  undefined4 local_5c;
  cXyz local_58;
  cXyz local_4c;
  cXyz local_40;
  cXyz local_34;
  float local_28;
  float local_24;
  float local_20;
  
  pdVar2 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor;
  bVar10 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode != 0;
  bVar7 = d_meter::dMenu_flag();
  bVar7 = bVar10 | bVar7;
  iVar4 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)
                    (0x803c9d58);
  uVar9 = *(uint *)(iVar4 + 0xc) >> 0x10 & 7;
  if ((this->parent).mEvtInfo.mCommand == InTalk) {
    *(undefined *)&this->field_0x66a = 0;
    *(undefined *)&this->field_0x669 = 2;
    return;
  }
  if (*(short *)&this->field_0x65c != 0) {
    cVar1 = *(char *)&this->field_0x66b;
    if ((cVar1 == '\x03') || (cVar1 == '\f')) {
      *(undefined2 *)&this->field_0x65c =
           *(undefined2 *)&(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor)->field_0x354c;
      if (*(short *)&this->field_0x65c == 0) {
        *(float *)(*(int *)&this->field_0x2a0 + 0xc) = d_a_agb::_4642;
      }
    }
    else {
      if ((cVar1 == '\x04') || (cVar1 == '\r')) {
        *(short *)&this->field_0x65c =
             (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor)->field_0x354e;
        if (*(short *)&this->field_0x65c == 0) {
          *(float *)(*(int *)&this->field_0x2a0 + 0xc) = d_a_agb::_4642;
        }
      }
      else {
        if (bVar7 == 0) {
          *(short *)&this->field_0x65c = *(short *)&this->field_0x65c + -1;
          if (*(char *)&this->field_0x66b == '\x0e') {
            if (*(short *)&this->field_0x65c == 0x78) {
              uVar3 = daBomb_c::prm_make(8,false,false);
              f_op_actor_mng::fopAcM_create
                        (0x128,uVar3,&(this->parent).mCurrent.mPos,-1,(csXyz *)0x0,(cXyz *)0x0,0xff,
                         (undefined *)0x0);
            }
            else {
              if (*(short *)&this->field_0x65c == 0) {
                resetCursor(this,false);
              }
            }
          }
          if ((*(char *)&this->field_0x66b == '\x0f') && (*(short *)&this->field_0x65c == 0x1e)) {
            f_op_actor_mng::fopAcM_fastCreateItem
                      ((cXyz *)&this->field_0x634,*(uint *)&this->field_0x640,-1,(csXyz *)0x0,
                       (cXyz *)0x0,(double)d_a_agb::_4279,(double)d_a_agb::_4275,
                       (double)d_a_agb::_6205,0xffffffff,0);
          }
        }
      }
    }
  }
  if (((*(char *)&this->field_0x673 == '\0') || (bVar7 != 0)) || (*(short *)&this->field_0x65c != 0)
     ) {
    *(undefined *)&this->field_0x672 = 0;
  }
  else {
    *(undefined *)&this->field_0x672 = 1;
  }
  iVar4 = mDoGaC_agbCom_c::mDoGaC_GbaLink
                    ((mDoGaC_agbCom_c *)&m_Do_ext::m_Do_gba_com::g_mDoGaC_gbaCom);
  if (((iVar4 != 0) &&
      (iVar4 = mDoGaC_agbCom_c::mDoGaC_RecvStatusCheck
                         ((mDoGaC_agbCom_c *)&m_Do_ext::m_Do_gba_com::g_mDoGaC_gbaCom,'\x06'),
      iVar4 != 0)) &&
     (iVar4 = mDoGaC_agbCom_c::mDoGaC_SendStatusCheck
                        ((mDoGaC_agbCom_c *)&m_Do_ext::m_Do_gba_com::g_mDoGaC_gbaCom,'\a'),
     iVar4 != 0)) {
    if ((*(char *)&this->field_0x672 == '\0') && (mItem != '\x15')) {
      _mEffect = 0;
    }
    else {
      GbaItemUse(this);
    }
    mDoGaC_agbCom_c::mDoGaC_DataStatusReset
              ((mDoGaC_agbCom_c *)&m_Do_ext::m_Do_gba_com::g_mDoGaC_gbaCom,'\x06');
    mDoGaC_agbCom_c::mDoGaC_SendDataSet
              ((mDoGaC_agbCom_c *)&m_Do_ext::m_Do_gba_com::g_mDoGaC_gbaCom,(ulong *)&mEffect,4,'\a',
               _mEffect);
  }
  if (((((*(char *)&this->field_0x67f != '\0') &&
        (*(undefined *)&this->field_0x67f = 0, *(char *)&this->field_0x67d == '\0')) &&
       (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor ==
        d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor)) &&
      ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8 & 0x8000000U) == 0)) &&
     (((iVar4 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->vtbl->
                          checkPlayerFly)(), iVar4 == 0 ||
       ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8 & 0x100000U) != 0)) ||
      ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8 & 0x10000U) != 0)))) {
    *(undefined *)&this->field_0x669 = 1;
    *(undefined *)&this->field_0x672 = 0;
    (this->parent).mEyePos.x = (this->parent).mCurrent.mPos.x;
    (this->parent).mEyePos.y = (this->parent).mCurrent.mPos.y;
    (this->parent).mEyePos.z = (this->parent).mCurrent.mPos.z;
    ::cXyz::operator__(&local_34,&(this->parent).mEyePos,&(pdVar2->parent).parent.mCurrent.mPos);
    local_28 = local_34.x;
    local_24 = local_34.y;
    local_20 = local_34.z;
    local_4c.x = local_34.x;
    local_4c.y = d_a_agb::_4278;
    local_4c.z = local_34.z;
    fVar13 = mtx::PSVECSquareMag(&local_4c);
    dVar12 = (double)fVar13;
    if ((double)d_a_agb::_4278 < dVar12) {
      dVar11 = 1.0 / SQRT(dVar12);
      dVar11 = d_a_agb::_6206 * dVar11 * (d_a_agb::_6207 - dVar12 * dVar11 * dVar11);
      dVar11 = d_a_agb::_6206 * dVar11 * (d_a_agb::_6207 - dVar12 * dVar11 * dVar11);
      dVar12 = (double)(float)(dVar12 * d_a_agb::_6206 * dVar11 *
                                        (d_a_agb::_6207 - dVar12 * dVar11 * dVar11));
    }
    dVar11 = (double)d_a_agb::_4280;
    if (dVar12 < dVar11) {
      (this->parent).mEyePos.x =
           (this->parent).mEyePos.x +
           (float)(dVar11 * (double)JKernel::JMath::jmaSinTable
                                    [(int)((int)(pdVar2->parent).parent.mCollisionRot.y & 0xffffU)
                                     >> (JKernel::JMath::jmaSinShift & 0x3f)]);
      (this->parent).mEyePos.z =
           (this->parent).mEyePos.z +
           (float)(dVar11 * (double)JKernel::JMath::jmaCosTable
                                    [(int)((int)(pdVar2->parent).parent.mCollisionRot.y & 0xffffU)
                                     >> (JKernel::JMath::jmaSinShift & 0x3f)]);
    }
    (this->parent).mAttentionPos.x = (this->parent).mEyePos.x;
    (this->parent).mAttentionPos.y = (this->parent).mEyePos.y;
    (this->parent).mAttentionPos.z = (this->parent).mEyePos.z;
    if (*(char *)&this->field_0x674 == '\0') {
      sVar6 = f_op_actor_mng::fopAcM_searchActorAngleY
                        (&this->parent,
                         (fopAc_ac_c *)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor);
      (this->parent).mCollisionRot.y = sVar6;
      ::cXyz::operator__(&local_40,&(pdVar2->parent).parent.mEyePos,&(this->parent).mEyePos);
      local_58.x = local_40.x;
      local_58.y = d_a_agb::_4278;
      local_58.z = local_40.z;
      fVar13 = mtx::PSVECSquareMag(&local_58);
      dVar12 = (double)fVar13;
      if ((double)d_a_agb::_4278 < dVar12) {
        dVar11 = 1.0 / SQRT(dVar12);
        dVar11 = d_a_agb::_6206 * dVar11 * (d_a_agb::_6207 - dVar12 * dVar11 * dVar11);
        dVar11 = d_a_agb::_6206 * dVar11 * (d_a_agb::_6207 - dVar12 * dVar11 * dVar11);
        dVar12 = (double)(float)(dVar12 * d_a_agb::_6206 * dVar11 *
                                          (d_a_agb::_6207 - dVar12 * dVar11 * dVar11));
      }
      iVar4 = SComponent::cM_atan2s
                        ((float)dVar12,(pdVar2->parent).parent.mEyePos.y - (this->parent).mEyePos.y)
      ;
      (this->parent).mCollisionRot.x = (short)iVar4;
      *(float *)&this->field_0x628 = d_a_agb::_4275;
    }
    else {
      sVar6 = f_op_actor_mng::fopAcM_searchActorAngleY
                        (&this->parent,
                         (fopAc_ac_c *)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor);
      if (*(char *)&this->field_0x675 == '\0') {
        sVar6 = -sVar6;
      }
      (this->parent).mCollisionRot.z = sVar6;
    }
    *(undefined *)&this->field_0x66b = 0x10;
    *(undefined2 *)&this->field_0x65c = 0x5a;
  }
  iVar4 = mDoGaC_agbCom_c::mDoGaC_GbaLink
                    ((mDoGaC_agbCom_c *)&m_Do_ext::m_Do_gba_com::g_mDoGaC_gbaCom);
  if (((iVar4 != 0) &&
      (iVar4 = mDoGaC_agbCom_c::mDoGaC_RecvStatusCheck
                         ((mDoGaC_agbCom_c *)&m_Do_ext::m_Do_gba_com::g_mDoGaC_gbaCom,'\f'),
      iVar4 != 0)) &&
     (iVar4 = mDoGaC_agbCom_c::mDoGaC_SendStatusCheck
                        ((mDoGaC_agbCom_c *)&m_Do_ext::m_Do_gba_com::g_mDoGaC_gbaCom,'\r'),
     iVar4 != 0)) {
    Shopping(this);
    mDoGaC_agbCom_c::mDoGaC_DataStatusReset
              ((mDoGaC_agbCom_c *)&m_Do_ext::m_Do_gba_com::g_mDoGaC_gbaCom,'\f');
    mDoGaC_agbCom_c::mDoGaC_SendDataSet
              ((mDoGaC_agbCom_c *)&m_Do_ext::m_Do_gba_com::g_mDoGaC_gbaCom,(ulong *)&mItemBuy,4,'\r'
               ,_mItemBuy);
  }
  uVar3 = (uint)DAT_803b9159;
  if (((m_Do_controller_pad::g_mDoCPd_cpadInfo[uVar3].field_0x34 == 0) &&
      ((pdVar2->parent).parent.parent.parent.mProcName != 0xc4)) &&
     (((*(char *)&this->field_0x672 != '\0' &&
       ((*(char *)&this->field_0x675 == '\0' &&
        ((m_Do_controller_pad::g_mDoCPd_cpadInfo[uVar3].mButton2 >> 2 & 1) != 0)))) ||
      (((d_com_inf_game::g_dComIfG_gameInfo._119255_1_ >> 2 & 1) != 0 &&
       (((m_Do_controller_pad::g_mDoCPd_cpadInfo[uVar3].mButton2 >> 2 & 1) != 0 ||
        ((m_Do_controller_pad::g_mDoCPd_cpadInfo[uVar3].mButton2 & 1) != 0)))))))) {
    offHold(this);
    *(undefined *)&this->field_0x671 = 0;
    if (*(char *)&this->field_0x677 == '\0') {
      if (((uVar9 != 6) &&
          (this_00 = dAttention_c::GetLockonList
                               (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAttention,0),
          this_00 != (dAttList_c *)0x0)) &&
         (pfVar5 = dAttList_c::getActor(this_00), pfVar5 != (fopAc_ac_c *)0x0)) {
        bVar10 = false;
        fVar8 = pfVar5->mStatus;
        if (((fVar8 & AppearsOnMiniMap) != 0) && ((fVar8 & 0x1f) == 0)) {
          bVar10 = true;
        }
        if (((bVar10) && ((fVar8 & IsBossOrMiniBoss) == 0)) &&
           ((pfVar5->parent).parent.mProcName != 0xf3)) {
          (this->parent).mCurrent.mPos.x = (pfVar5->mCurrent).mPos.x;
          (this->parent).mCurrent.mPos.y = (pfVar5->mCurrent).mPos.y;
          (this->parent).mCurrent.mPos.z = (pfVar5->mCurrent).mPos.z;
          (this->parent).mOrig.mPos.x = (pfVar5->mCurrent).mPos.x;
          (this->parent).mOrig.mPos.y = (pfVar5->mCurrent).mPos.y;
          (this->parent).mOrig.mPos.z = (pfVar5->mCurrent).mPos.z;
          *(int *)&this->field_0x650 = this_00->mPcId;
          *(undefined *)&this->field_0x677 = 1;
        }
      }
    }
    else {
      *(undefined4 *)&this->field_0x650 = 0xffffffff;
      *(undefined *)&this->field_0x677 = 0;
    }
  }
  if (*(char *)&this->field_0x671 != '\0') {
    if (*(char *)&this->field_0x674 == '\0') {
      CursorMove(this,&this->parent,uVar9);
    }
    goto LAB_800d300c;
  }
  if (*(char *)&this->field_0x677 == '\x01') {
    local_5c = *(undefined4 *)&this->field_0x650;
    pfVar5 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,&local_5c);
    if (pfVar5 != (fopAc_ac_c *)0x0) {
      bVar10 = false;
      if (((pfVar5->mStatus & AppearsOnMiniMap) != 0) && ((pfVar5->mStatus & 0x1f) == 0)) {
        bVar10 = true;
      }
      if (bVar10) goto LAB_800d2ec8;
    }
    *(undefined4 *)&this->field_0x650 = 0xffffffff;
    *(undefined *)&this->field_0x677 = 0;
  }
LAB_800d2ec8:
  if (*(char *)&this->field_0x677 == '\0') {
    if ((pdVar2->parent).parent.parent.parent.mProcName == 0xc4) {
      onFree(this);
    }
    else {
      (this->parent).mCurrent.mPos.x = (pdVar2->parent).parent.mCurrent.mPos.x;
      (this->parent).mCurrent.mPos.y = (pdVar2->parent).parent.mCurrent.mPos.y;
      (this->parent).mCurrent.mPos.z = (pdVar2->parent).parent.mCurrent.mPos.z;
      (this->parent).mOrig.mPos.x = (pdVar2->parent).parent.mCurrent.mPos.x;
      (this->parent).mOrig.mPos.y = (pdVar2->parent).parent.mCurrent.mPos.y;
      (this->parent).mOrig.mPos.z = (pdVar2->parent).parent.mCurrent.mPos.z;
    }
  }
  else {
    local_60 = *(undefined4 *)&this->field_0x650;
    pfVar5 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,&local_60);
    (this->parent).mCurrent.mPos.x = (pfVar5->mCurrent).mPos.x;
    (this->parent).mCurrent.mPos.y = (pfVar5->mCurrent).mPos.y;
    (this->parent).mCurrent.mPos.z = (pfVar5->mCurrent).mPos.z;
    (this->parent).mOrig.mPos.x = (pfVar5->mCurrent).mPos.x;
    (this->parent).mOrig.mPos.y = (pfVar5->mCurrent).mPos.y;
    (this->parent).mOrig.mPos.z = (pfVar5->mCurrent).mPos.z;
  }
  (this->parent).mCollisionRot.x = 0;
  (this->parent).mCollisionRot.y = 0;
  (this->parent).mCollisionRot.z = 0;
  *(float *)&this->field_0x628 = d_a_agb::_4644;
  if ((((m_Do_controller_pad::g_mDoCPd_cpadInfo[DAT_803b9159].field_0x34 == 0) &&
       (bVar7 = m_Do_controller_pad::g_mDoCPd_cpadInfo[DAT_803b9159].mButton0, (bVar7 >> 1 & 1) == 0
       )) && ((byte)(bVar7 >> 5 & 1 | bVar7 >> 4 & 1 | bVar7 >> 7 | bVar7 >> 6 & 1) != 0)) &&
     ((*(char *)&this->field_0x672 != '\0' && (*(char *)&this->field_0x674 == '\0')))) {
    onFree(this);
  }
LAB_800d300c:
  if (*(char *)&this->field_0x669 == '\0') {
    (this->parent).mEvtInfo.mCondition = (this->parent).mEvtInfo.mCondition | CanTalk;
  }
  return;
}


/* __thiscall daAgb_c::modeDelete(void) */

void __thiscall daAgb_c::modeDelete(daAgb_c *this)

{
  int iVar1;
  
  if (((*(short *)&this->field_0x664 == 0) &&
      (iVar1 = mDoGaC_agbCom_c::mDoGaC_GbaLink
                         ((mDoGaC_agbCom_c *)&m_Do_ext::m_Do_gba_com::g_mDoGaC_gbaCom), iVar1 != 0))
     && (iVar1 = mDoGaC_agbCom_c::mDoGaC_SendStatusCheck
                           ((mDoGaC_agbCom_c *)&m_Do_ext::m_Do_gba_com::g_mDoGaC_gbaCom,'\x01'),
        iVar1 != 0)) {
    *(undefined4 *)&this->field_0x64c = 0x1000000;
    *(undefined4 *)&this->field_0x648 = 0;
    mDoGaC_agbCom_c::mDoGaC_SendDataSet
              ((mDoGaC_agbCom_c *)&m_Do_ext::m_Do_gba_com::g_mDoGaC_gbaCom,
               (ulong *)&this->field_0x648,4,'\x01',0);
    *(short *)&this->field_0x664 = *(short *)&this->field_0x664 + 1;
  }
  return;
}


namespace d_a_agb {

/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __stdcall daAgb_Execute(daAgb_c *) */

undefined4 daAgb_Execute(daAgb_c *param_1)

{
  char cVar1;
  ushort uVar2;
  float fVar3;
  daPy_lk_c *pdVar4;
  daPy_lk_c *pdVar5;
  uint uVar6;
  int iVar7;
  byte bVar9;
  short sVar8;
  bool bVar10;
  
  pdVar4 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor;
  *(undefined *)&param_1->field_0x679 = 0;
  iVar7 = mDoGaC_agbCom_c::mDoGaC_GbaLink
                    ((mDoGaC_agbCom_c *)&m_Do_ext::m_Do_gba_com::g_mDoGaC_gbaCom);
  if ((iVar7 == 0) ||
     (iVar7 = mDoGaC_agbCom_c::mDoGaC_RecvStatusCheck
                        ((mDoGaC_agbCom_c *)&m_Do_ext::m_Do_gba_com::g_mDoGaC_gbaCom,'\x04'),
     iVar7 == 0)) {
    m_Do_controller_pad::g_mDoCPd_cpadInfo[DAT_803b9159].field_0x34 = 1;
  }
  else {
    ::daAgb_c::FlagsRecv(param_1);
    mDoGaC_agbCom_c::mDoGaC_DataStatusReset
              ((mDoGaC_agbCom_c *)&m_Do_ext::m_Do_gba_com::g_mDoGaC_gbaCom,'\x04');
  }
  bVar10 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode != 0;
  bVar9 = d_meter::dMenu_flag();
  iVar7 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)();
  uVar6 = *(uint *)(iVar7 + 0xc);
  iVar7 = mDoGaC_agbCom_c::mDoGaC_GbaLink
                    ((mDoGaC_agbCom_c *)&m_Do_ext::m_Do_gba_com::g_mDoGaC_gbaCom);
  if (iVar7 == 0) {
    if (*(char *)&param_1->field_0x680 != '\0') {
      *(undefined *)&param_1->field_0x680 = 0;
      ::daAgb_c::resetCursor(param_1,true);
      *(undefined *)&param_1->field_0x672 = 0;
      pdVar5 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor;
      if (*(short *)&param_1->field_0x65c != 0) {
        cVar1 = *(char *)&param_1->field_0x66b;
        if ((cVar1 == '\x03') || (cVar1 == '\f')) {
          ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor)->parent).field_0x29c =
               ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor)->parent).field_0x29c | 0x1000
          ;
          *(undefined2 *)&pdVar5->field_0x354c = 10;
        }
        else {
          if ((cVar1 == '\x04') || ((cVar1 == '\r' || (cVar1 == '\f')))) {
            (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor)->field_0x354e = 10;
          }
        }
        *(undefined2 *)&param_1->field_0x65c = 0;
      }
      *(undefined *)&param_1->field_0x66b = 0;
      *(undefined2 *)&param_1->field_0x630 = 0;
      *(undefined2 *)&param_1->field_0x632 = 0;
      (**(code **)(*(int *)&param_1->field_0x684 + 0x20))(&param_1->field_0x684);
    }
  }
  else {
    iVar7 = mDoGaC_agbCom_c::mDoGaC_RecvStatusCheck
                      ((mDoGaC_agbCom_c *)&m_Do_ext::m_Do_gba_com::g_mDoGaC_gbaCom,'\b');
    if (iVar7 != 0) {
      ::daAgb_c::SwitchOn(param_1);
    }
    iVar7 = mDoGaC_agbCom_c::mDoGaC_SendStatusCheck
                      ((mDoGaC_agbCom_c *)&m_Do_ext::m_Do_gba_com::g_mDoGaC_gbaCom,'\t');
    if (iVar7 != 0) {
      ::daAgb_c::FlagsSend(param_1,uVar6 >> 0x10 & 7);
    }
    *(undefined *)&param_1->field_0x680 = 1;
  }
  if (::daAgb_c::init_localstatic4_modeProcCall == (code)0x0) {
    _mode_proc_localstatic3_modeProcCall = _6217;
    DAT_803895d4 = DAT_803895a4;
    DAT_803895d8 = PTR_modeMove_803895a8;
    DAT_803895dc = _6218;
    DAT_803895e0 = DAT_803895b0;
    DAT_803895e4 = PTR_modeLookAttention_803895b4;
    DAT_803895e8 = _6219;
    DAT_803895ec = DAT_803895bc;
    DAT_803895f0 = PTR_modeLoad_803895c0;
    DAT_803895f4 = _6220;
    DAT_803895f8 = DAT_803895c8;
    DAT_803895fc = PTR_modeDelete_803895cc;
    ::daAgb_c::init_localstatic4_modeProcCall = (code)0x1;
  }
  Runtime.PPCEABI.H::__ptmf_scall
            ((PTMF *)(::daAgb_c::mode_proc_localstatic3_modeProcCall +
                     (uint)*(byte *)&param_1->field_0x669 * 0xc),param_1,&DAT_80390000);
  iVar7 = mDoGaC_agbCom_c::mDoGaC_GbaLink
                    ((mDoGaC_agbCom_c *)&m_Do_ext::m_Do_gba_com::g_mDoGaC_gbaCom);
  if (iVar7 != 0) {
    if (*(char *)&param_1->field_0x671 == '\0') {
      if ((((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor ==
             d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor) &&
           (iVar7 = (*(code *)pdVar4->vtbl->checkPlayerFly)(pdVar4), iVar7 == 0)) ||
          ((sVar8 = (pdVar4->parent).parent.parent.parent.mProcName, sVar8 == 0x171 &&
           (daNpc_Md_c::m_flying == '\0')))) ||
         (((sVar8 == 0x150 && (daNpc_Cb1_c::m_flying == '\0')) || (sVar8 == 0x13c)))) {
        fVar3 = ABS((pdVar4->parent).parent.mVelocityFwd);
        if (_4278 < fVar3) {
          if (_4279 <= fVar3) {
            if (_4280 <= fVar3) {
              if (_4281 <= fVar3) {
                d_com_inf_game::g_dComIfG_gameInfo._119257_1_ =
                     d_com_inf_game::g_dComIfG_gameInfo._119257_1_ & 0xe3 | 0x10;
              }
              else {
                d_com_inf_game::g_dComIfG_gameInfo._119257_1_ =
                     d_com_inf_game::g_dComIfG_gameInfo._119257_1_ & 0xe3 | 0xc;
              }
            }
            else {
              d_com_inf_game::g_dComIfG_gameInfo._119257_1_ =
                   d_com_inf_game::g_dComIfG_gameInfo._119257_1_ & 0xe3 | 8;
            }
          }
          else {
            d_com_inf_game::g_dComIfG_gameInfo._119257_1_ =
                 d_com_inf_game::g_dComIfG_gameInfo._119257_1_ & 0xe3 | 4;
          }
        }
        else {
          d_com_inf_game::g_dComIfG_gameInfo._119257_1_ =
               d_com_inf_game::g_dComIfG_gameInfo._119257_1_ & 0xe3;
        }
      }
      else {
        d_com_inf_game::g_dComIfG_gameInfo._119257_1_ =
             d_com_inf_game::g_dComIfG_gameInfo._119257_1_ & 0xe3;
      }
    }
    else {
      if (((param_1->parent).mCurrent.mPos.x == (param_1->parent).mNext.mPos.x) &&
         ((param_1->parent).mCurrent.mPos.z == (param_1->parent).mNext.mPos.z)) {
        d_com_inf_game::g_dComIfG_gameInfo._119257_1_ =
             d_com_inf_game::g_dComIfG_gameInfo._119257_1_ & 0xe3;
      }
      else {
        d_com_inf_game::g_dComIfG_gameInfo._119257_1_ =
             d_com_inf_game::g_dComIfG_gameInfo._119257_1_ & 0xe3 | 4;
      }
    }
    if (((*(char *)&param_1->field_0x674 != '\0') && ((bVar10 | bVar9) == 0)) &&
       (*(char *)&param_1->field_0x669 != '\x01')) {
      if (*(char *)&param_1->field_0x675 == '\0') {
        (param_1->parent).mCollisionRot.z = (param_1->parent).mCollisionRot.z + 0x200;
      }
      else {
        if (*(char *)&param_1->field_0x676 == '\0') {
          sVar8 = f_op_actor_mng::fopAcM_searchActorAngleY
                            (&param_1->parent,
                             (fopAc_ac_c *)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor
                            );
          (param_1->parent).mCollisionRot.z = sVar8;
        }
        else {
          (param_1->parent).mCollisionRot.z = (param_1->parent).mCollisionRot.z + 0x1000;
        }
      }
    }
    mtx::PSMTXTrans((double)(param_1->parent).mCurrent.mPos.x,
                    (double)((param_1->parent).mCurrent.mPos.y + *(float *)&param_1->field_0x628),
                    (double)(param_1->parent).mCurrent.mPos.z,&mDoMtx_stack_c::now);
    m_Do_mtx::mDoMtx_YrotM(&mDoMtx_stack_c::now,(param_1->parent).mCollisionRot.y);
    m_Do_mtx::mDoMtx_XrotM(&mDoMtx_stack_c::now,(param_1->parent).mCollisionRot.x);
    m_Do_mtx::mDoMtx_ZrotM(&mDoMtx_stack_c::now,(param_1->parent).mCollisionRot.z);
    mtx::PSMTXCopy(&mDoMtx_stack_c::now,(MTX34 *)(*(int *)&param_1->field_0x298 + 0x24));
    if (*(char *)&param_1->field_0x669 == '\x01') {
      *(float *)(*(int *)&param_1->field_0x2a0 + 0x10) = _6372;
    }
    else {
      uVar2 = *(ushort *)&param_1->field_0x65c;
      if ((uVar2 == 0) ||
         ((((cVar1 = *(char *)&param_1->field_0x66b, cVar1 != '\x04' && (cVar1 != '\r')) &&
           (cVar1 != '\f')) && (cVar1 != '\x03')))) {
        if ((((*(char *)&param_1->field_0x672 == '\0') && (*(char *)&param_1->field_0x676 == '\0'))
            || ((*(char *)&param_1->field_0x671 == '\0' &&
                (*(char *)&param_1->field_0x677 != '\x01')))) &&
           ((*(char *)&param_1->field_0x66b != '\x0e' || (uVar2 < 0x79)))) {
          *(float *)(*(int *)&param_1->field_0x2a0 + 0x10) = _4278;
        }
        else {
          ::mDoExt_baseAnm::play((mDoExt_baseAnm *)&param_1->field_0x29c);
        }
      }
      else {
        if (uVar2 < 0x3d) {
          ::mDoExt_baseAnm::play((mDoExt_baseAnm *)&param_1->field_0x29c);
        }
        else {
          *(float *)(*(int *)&param_1->field_0x2a0 + 0x10) = _6372;
        }
      }
    }
  }
  return 1;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __stdcall daAgb_Draw(daAgb_c *) */

undefined4 daAgb_Draw(int param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  ushort uVar4;
  int iVar5;
  byte bVar6;
  
  bVar6 = 1;
  iVar2 = mDoGaC_agbCom_c::mDoGaC_GbaLink
                    ((mDoGaC_agbCom_c *)&m_Do_ext::m_Do_gba_com::g_mDoGaC_gbaCom);
  if (iVar2 != 0) {
    if ((((*(char *)(param_1 + 0x66f) != '\0') &&
         ((d_com_inf_game::g_dComIfG_gameInfo._119262_1_ & 1) == 0)) &&
        ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode == 0 ||
         ((iVar2 = dEvent_manager_c::startCheckOld
                             (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,
                              "DEFAULT_AGB_LOOK_ATTENTION"), iVar2 != 0 ||
          (*(char *)(param_1 + 0x669) == '\x02')))))) &&
       ((*(ushort *)(param_1 + 0x65c) == 0 ||
        (((((*(char *)(param_1 + 0x669) == '\x01' ||
            (cVar1 = *(char *)(param_1 + 0x66b), cVar1 == '\x10')) || (cVar1 == '\x03')) ||
          ((cVar1 == '\f' || (cVar1 == '\x04')))) ||
         ((cVar1 == '\r' || ((cVar1 == '\x0e' && (0x78 < *(ushort *)(param_1 + 0x65c))))))))))) {
      *(undefined4 *)(*(int *)(param_1 + 0x2a4) + 8) =
           *(undefined4 *)(*(int *)(param_1 + 0x2a0) + 0x10);
      iVar2 = *(int *)(*(int *)(param_1 + 0x298) + 4);
      for (uVar4 = 0; uVar4 < *(ushort *)(iVar2 + 0x5c); uVar4 = uVar4 + 1) {
        iVar5 = *(int *)(*(int *)(iVar2 + 0x60) + (uint)uVar4 * 4);
        piVar3 = *(int **)(iVar5 + 0x2c);
        (**(code **)(*piVar3 + 0x60))(piVar3,1,0x803e3604);
        piVar3 = *(int **)(iVar5 + 0x2c);
        (**(code **)(*piVar3 + 0x60))(piVar3,2,0x803e360c);
      }
      m_Do_ext::mDoExt_modelUpdateDL(*(J3DModel **)(param_1 + 0x298));
      if ((*(char *)(param_1 + 0x679) != '\0') &&
         (_4644 < *(float *)(param_1 + 0x1fc) - *(float *)(param_1 + 0x330))) {
        d_com_inf_game::dComIfGd_setSimpleShadow2
                  ((cXyz *)(param_1 + 0x1f8),*(float *)(param_1 + 0x330),_4275,
                   (cBgS_PolyInfo *)(param_1 + 0x3a0),0,_4642,(_GXTexObj *)(param_1 + 0x2b4));
      }
      bVar6 = 0;
    }
  }
  dMap_c::drawPointSingle
            (3,*(float *)(param_1 + 0x1f8),*(float *)(param_1 + 0x1fc),*(float *)(param_1 + 0x200),
             *(byte *)(param_1 + 0x20a),-0x8000,bVar6,0,'\0');
  return 1;
}

}

/* __thiscall J3DTevBlock::setTevColor(unsigned long,
                                       J3DGXColorS10 const *) */

void __thiscall J3DTevBlock::setTevColor(J3DTevBlock *this,ulong param_1,J3DGXColorS10 *param_2)

{
  return;
}


namespace d_a_agb {

/* __stdcall daAgb_IsDelete(daAgb_c *) */

undefined4 daAgb_IsDelete(void)

{
  return 1;
}


/* __stdcall daAgb_Delete(daAgb_c *) */

undefined4 daAgb_Delete(int param_1)

{
  d_com_inf_game::dComIfG_resDelete((request_of_phase_process_class *)(param_1 + 0x290),"Agb");
  (**(code **)(*(int *)(param_1 + 0x684) + 0x20))(param_1 + 0x684);
  return 1;
}


/* __stdcall createHeap_CB(fopAc_ac_c *) */

void createHeap_CB(daAgb_c *param_1)

{
  ::daAgb_c::createHeap(param_1);
  return;
}

}

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall daAgb_c::createHeap(void) */

undefined4 __thiscall daAgb_c::createHeap(daAgb_c *this)

{
  J3DModelData *pModel;
  ulong uVar1;
  J3DModel *pJVar2;
  undefined4 uVar3;
  J3DAnmTevRegKey *pJVar4;
  int iVar5;
  ResTIMG *pRVar6;
  
  pModel = (J3DModelData *)
           dRes_control_c::getRes
                     ("Agb",4,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
  if (pModel == (J3DModelData *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_a_agb.cpp",0xccd,"modelData != 0");
    m_Do_printf::OSPanic("d_a_agb.cpp",0xccd,"Halt");
  }
  pJVar2 = m_Do_ext::mDoExt_J3DModel__create(pModel,0x80000,0x11000002);
  *(J3DModel **)&this->field_0x298 = pJVar2;
  if (*(int *)&this->field_0x298 == 0) {
    uVar3 = 0;
  }
  else {
    pJVar4 = (J3DAnmTevRegKey *)
             dRes_control_c::getRes
                       ("Agb",7,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
    iVar5 = ::mDoExt_brkAnm::init
                      ((mDoExt_brkAnm *)&this->field_0x29c,pModel,pJVar4,true,Repeat,d_a_agb::_4642,
                       0,-1,false,1);
    if (iVar5 == 0) {
      uVar3 = 0;
    }
    else {
      pRVar6 = ((pModel->mMaterialTable).mpTexture)->mpTexData;
      gx::GXInitTexObj((GXTexObj *)&this->field_0x2b4,&pRVar6[1].mTexFmt + pRVar6[1].mTexDataOffs,
                       (uint)pRVar6[1].mWidth,(uint)pRVar6[1].mHeight,pRVar6[1].mTexFmt,
                       pRVar6[1].mWrapS,pRVar6[1].mWrapT,
                       SUB41(1 - (uint)pRVar6[1].mMipmapCount >> 0x1f,0));
      gx::GXInitTexObjLOD((double)(d_a_agb::_6477 *
                                  (float)((double)CONCAT44(0x43300000,
                                                           (int)(char)pRVar6[1].mMinLOD ^ 0x80000000
                                                          ) - d_a_agb::_6480)),
                          (double)(d_a_agb::_6477 *
                                  (float)((double)CONCAT44(0x43300000,
                                                           (int)(char)pRVar6[1].mMaxLOD ^ 0x80000000
                                                          ) - d_a_agb::_6480)),
                          (double)(d_a_agb::_6478 *
                                  (float)((double)CONCAT44(0x43300000,
                                                           (int)pRVar6[1].mLODBias ^ 0x80000000) -
                                         d_a_agb::_6480)),&this->field_0x2b4,pRVar6[1].mMinFilter,
                          pRVar6[1].mMagFilter,pRVar6[1].mbBiasClamp,pRVar6[1].mbDoEdgeLOD,
                          pRVar6[1].mMaxAniso);
      uVar3 = 1;
    }
  }
  return uVar3;
}


namespace d_a_agb {

/* __stdcall daAgb_Create(fopAc_ac_c *) */

PhaseState daAgb_Create(daAgb_c *pthis)

{
  PhaseState PVar1;
  uint uVar2;
  
  if (((pthis->parent).mCondition & Constructed) == 0) {
    if (pthis != (daAgb_c *)0x0) {
      ::daAgb_c::daAgb_c(pthis);
    }
    (pthis->parent).mCondition = (pthis->parent).mCondition | Constructed;
  }
  PVar1 = d_com_inf_game::dComIfG_resLoad
                    ((request_of_phase_process_class *)&pthis->field_0x290,"Agb");
  if (PVar1 == cPhs_COMPLEATE_e) {
    d_com_inf_game::g_dComIfG_gameInfo.mpAgb = pthis;
    uVar2 = f_op_actor_mng::fopAcM_entrySolidHeap(&pthis->parent,createHeap_CB,0x500);
    if ((uVar2 & 0xff) == 0) {
      PVar1 = cPhs_ERROR_e;
    }
    else {
      *(actor_place **)&pthis->field_0x318 = &(pthis->parent).mCurrent;
      *(actor_place **)&pthis->field_0x31c = &(pthis->parent).mNext;
      *(undefined4 *)&pthis->field_0x32c = 0;
      *(undefined4 *)&pthis->field_0x300 = 0xffffffff;
      *(float *)&pthis->field_0x310 = _5805;
      *(float *)&pthis->field_0x314 = _4275;
      *(float *)&pthis->field_0x338 = _4277;
      *(uint *)&pthis->field_0x3bc = *(uint *)&pthis->field_0x3bc & 0xfffffffd;
      *(uint *)&pthis->field_0x30c = *(uint *)&pthis->field_0x30c & 0xfffffff7;
      dBgS_Acch::Set((dBgS_Acch *)&pthis->field_0x424,&(pthis->parent).mCurrent.mPos,
                     &(pthis->parent).mNext.mPos,&pthis->parent,1,
                     (dBgS_AcchCir *)&pthis->field_0x5e8,(cXyz *)0x0,(csXyz *)0x0,(csXyz *)0x0);
      *(uint *)&pthis->field_0x44c = *(uint *)&pthis->field_0x44c | 0x2000;
      *(uint *)&pthis->field_0x44c = *(uint *)&pthis->field_0x44c | 2;
      ::dBgS_AcchCir::SetWall((dBgS_AcchCir *)&pthis->field_0x5e8,_5805,_5808);
      DAT_803b919c = &::daAgb_c::mGbaFlg;
      DAT_803b91bc = &::daAgb_c::mSwitch;
      DAT_803b91ac = &::daAgb_c::mItem;
      DAT_803b91dc = &::daAgb_c::mShop;
      *(undefined *)&pthis->field_0x670 = 0;
      *(undefined2 *)&pthis->field_0x65c = 0;
      *(undefined *)&pthis->field_0x66b = 0;
      *(char *)&pthis->field_0x66f = m_Do_ext::m_Do_gba_com::g_mDoGaC_gbaCom;
      *(char *)&pthis->field_0x678 = '\x01' - (m_Do_ext::m_Do_gba_com::g_mDoGaC_gbaCom == '\0');
      *(undefined4 *)&pthis->field_0x654 = 0;
      *(undefined4 *)&pthis->field_0x650 = 0xffffffff;
      *(undefined *)&pthis->field_0x677 = 0;
      *(undefined *)&pthis->field_0x67b = 0;
      *(undefined *)&pthis->field_0x680 = 1;
      f_op_actor_mng::fopAcM_setStageLayer(&pthis->parent);
      dEvt_info_c::setEventName(&(pthis->parent).mEvtInfo,"DEFAULT_AGB_USE");
    }
  }
  return PVar1;
}

}

/* __thiscall daAgb_c::daAgb_c(void) */

void __thiscall daAgb_c::daAgb_c(daAgb_c *this)

{
  fopAc_ac_c::fopAc_ac_c(&this->parent);
  *(undefined ***)&this->field_0x29c = &::mDoExt_baseAnm::__vt;
  *(undefined4 *)&this->field_0x2a0 = 0;
  *(undefined ***)&this->field_0x29c = &::mDoExt_brkAnm::__vt;
  *(undefined4 *)&this->field_0x2a8 = 0;
  *(undefined4 *)&this->field_0x2ac = 0;
  dBgS_LinkCrrPos::dBgS_LinkCrrPos((dBgS_LinkCrrPos *)&this->field_0x2d4);
  dBgS_Acch::dBgS_Acch((dBgS_Acch *)&this->field_0x424);
  *(undefined1 **)&this->field_0x434 = &dBgS_LinkAcch::__vt;
  *(undefined **)&this->field_0x438 = &DAT_80389728;
  *(undefined **)&this->field_0x444 = &DAT_80389734;
  *(undefined *)&this->field_0x43e = 1;
  ::dBgS_AcchCir::dBgS_AcchCir((dBgS_AcchCir *)&this->field_0x5e8);
  dPa_followEcallBack::dPa_followEcallBack((dPa_followEcallBack *)&this->field_0x684,0,0);
  return;
}


/* __thiscall dBgS_LinkAcch::~dBgS_LinkAcch(void) */

void __thiscall dBgS_LinkAcch::_dBgS_LinkAcch(dBgS_LinkAcch *this)

{
  short in_r4;
  
  if (this != (dBgS_LinkAcch *)0x0) {
    *(undefined1 **)(this + 0x10) = &__vt;
    *(undefined **)(this + 0x14) = &DAT_80389728;
    *(undefined **)(this + 0x20) = &DAT_80389734;
    dBgS_Acch::_dBgS_Acch((dBgS_Acch *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dBgS_LinkCrrPos::~dBgS_LinkCrrPos(void) */

void __thiscall dBgS_LinkCrrPos::_dBgS_LinkCrrPos(dBgS_LinkCrrPos *this)

{
  short in_r4;
  
  if (this != (dBgS_LinkCrrPos *)0x0) {
    *(undefined ***)(this + 0xc) = &__vt;
    *(undefined **)(this + 0x10) = &DAT_80389698;
    *(undefined **)(this + 0x1c) = &DAT_803896a4;
    *(undefined **)(this + 0x34) = &DAT_803896b0;
    dBgS_CrrPos::_dBgS_CrrPos((dBgS_CrrPos *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dBgS_CrrPos::~dBgS_CrrPos(void) */

void __thiscall dBgS_CrrPos::_dBgS_CrrPos(dBgS_CrrPos *this)

{
  short in_r4;
  
  if (this != (dBgS_CrrPos *)0x0) {
    (this->mPolyInfo).vtbl = (cBgS_PolyInfo__vtbl *)&__vt;
    (this->mPolyPassChk).vtbl = (cBgS_PolyPassChk__vtbl *)&DAT_80389668;
    (this->mGrpPassChk).vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_80389674;
    this->field_0x34 = (undefined *)&PTR_80389680;
    if (this != (dBgS_CrrPos *)0xffffff08) {
      (this->mLinChk).parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_LinChk::__vt;
      (this->mLinChk).mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&PTR_80371fbc;
      if (this != (dBgS_CrrPos *)0xfffffee4) {
        (this->mLinChk).mLin.vtbl = (undefined *)&::cM3dGLin::__vt;
      }
      if (this != (dBgS_CrrPos *)0xfffffef4) {
        (this->mLinChk).mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
      }
      cBgS_Chk::_cBgS_Chk(&(this->mLinChk).parent);
    }
    if (this != (dBgS_CrrPos *)0xffffff48) {
      (this->mGndChk).parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_GndChk::__vt;
      (this->mGndChk).mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&PTR_80371e90;
      if (this != (dBgS_CrrPos *)0xffffff34) {
        (this->mGndChk).mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
      }
      cBgS_Chk::_cBgS_Chk(&(this->mGndChk).parent);
    }
    if (this != (dBgS_CrrPos *)0xffffff64) {
      (this->mLin).vtbl = (undefined *)&::cM3dGLin::__vt;
    }
    if (this != (dBgS_CrrPos *)0xffffff7c) {
      (this->mCyl1).vtbl = (cCcD_CylAttr__vtbl *)&::cM3dGCyl::__vt;
    }
    if (this != (dBgS_CrrPos *)0xffffff94) {
      (this->mCyl0).vtbl = (cCcD_CylAttr__vtbl *)&::cM3dGCyl::__vt;
    }
    cBgS_Chk::_cBgS_Chk((cBgS_Chk *)&this->mpPolyPassChk);
    if (this != (dBgS_CrrPos *)0xfffffff0) {
      (this->mPolyPassChk).vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
      (this->mGrpPassChk).vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_80371f68;
      if (this != (dBgS_CrrPos *)0xffffffe4) {
        (this->mGrpPassChk).vtbl = (cBgS_GrpPassChk__vtbl *)&::dBgS_GrpPassChk::__vt;
        if (this != (dBgS_CrrPos *)0xffffffe4) {
          (this->mGrpPassChk).vtbl = (cBgS_GrpPassChk__vtbl *)&::cBgS_GrpPassChk::__vt;
        }
      }
      if ((this != (dBgS_CrrPos *)0xfffffff0) &&
         ((this->mPolyPassChk).vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
         this != (dBgS_CrrPos *)0xfffffff0)) {
        (this->mPolyPassChk).vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
      }
    }
    if (this != (dBgS_CrrPos *)0x0) {
      (this->mPolyInfo).vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dBgS_LinkCrrPos::dBgS_LinkCrrPos(void) */

void __thiscall dBgS_LinkCrrPos::dBgS_LinkCrrPos(dBgS_LinkCrrPos *this)

{
  dBgS_CrrPos::dBgS_CrrPos((dBgS_CrrPos *)this);
  *(undefined ***)(this + 0xc) = &__vt;
  *(undefined **)(this + 0x10) = &DAT_80389698;
  *(undefined **)(this + 0x1c) = &DAT_803896a4;
  *(undefined **)(this + 0x34) = &DAT_803896b0;
  this[0x16] = (dBgS_LinkCrrPos)0x1;
  return;
}


/* __thiscall dBgS_CrrPos::dBgS_CrrPos(void) */

void __thiscall dBgS_CrrPos::dBgS_CrrPos(dBgS_CrrPos *this)

{
  float fVar1;
  cBgS_PolyPassChk *pcVar2;
  
  (this->mPolyInfo).vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
  (this->mPolyInfo).mTriIdx = -1;
  (this->mPolyInfo).mBgIndex = 0x100;
  (this->mPolyInfo).mpBgW = (cBgW *)0x0;
  (this->mPolyInfo).mProcID = -1;
  (this->mPolyPassChk).vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
  (this->mPolyPassChk).vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt;
  (this->mPolyPassChk).mbObjThrough = 0;
  (this->mPolyPassChk).mbCamThrough = 0;
  (this->mPolyPassChk).mbLinkThrough = 0;
  (this->mPolyPassChk).mbArrowsAndLightThrough = 0;
  (this->mPolyPassChk).mbBombThrough = 0;
  (this->mPolyPassChk).mbBoomerangThrough = 0;
  (this->mPolyPassChk).mbHookshotThrough = 0;
  (this->mGrpPassChk).vtbl = (cBgS_GrpPassChk__vtbl *)&::cBgS_GrpPassChk::__vt;
  (this->mGrpPassChk).vtbl = (cBgS_GrpPassChk__vtbl *)&::dBgS_GrpPassChk::__vt;
  (this->mGrpPassChk).mAttr = 1;
  (this->mPolyPassChk).vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
  (this->mGrpPassChk).vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_80371f68;
  this->field_0x34 = (undefined *)&cBgS_Chk::__vt;
  this->mpPolyPassChk = (cBgS_PolyPassChk *)0x0;
  this->mpGrpPassChk = (cBgS_GrpPassChk *)0x0;
  this->mbExcludeSameProcID = true;
  (this->mPolyInfo).vtbl = (cBgS_PolyInfo__vtbl *)&__vt;
  (this->mPolyPassChk).vtbl = (cBgS_PolyPassChk__vtbl *)&DAT_80389668;
  (this->mGrpPassChk).vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_80389674;
  this->field_0x34 = (undefined *)&PTR_80389680;
  (this->mCyl0).vtbl = (cCcD_CylAttr__vtbl *)&::cM3dGCyl::__vt;
  (this->mCyl1).vtbl = (cCcD_CylAttr__vtbl *)&::cM3dGCyl::__vt;
  (this->mLin).vtbl = (undefined *)&::cM3dGLin::__vt;
  ::cBgS_GndChk::cBgS_GndChk(&this->mGndChk);
  (this->mLinChk).parent.vtbl = &cBgS_Chk::__vt;
  (this->mLinChk).parent.mpPolyPassChk = (cBgS_PolyPassChk *)0x0;
  (this->mLinChk).parent.mpGrpPassChk = (cBgS_GrpPassChk *)0x0;
  (this->mLinChk).parent.mbExcludeSameProcID = true;
  (this->mLinChk).mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
  (this->mLinChk).mPolyInfo.mTriIdx = -1;
  (this->mLinChk).mPolyInfo.mBgIndex = 0x100;
  (this->mLinChk).mPolyInfo.mpBgW = (cBgW *)0x0;
  (this->mLinChk).mPolyInfo.mProcID = -1;
  (this->mLinChk).parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_LinChk::__vt;
  (this->mLinChk).mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&PTR_80371fbc;
  (this->mLinChk).mLin.vtbl = (undefined *)&::cM3dGLin::__vt;
  ::cBgS_LinChk::ct(&this->mLinChk);
  this->mpPolyPassChk = &this->mPolyPassChk;
  pcVar2 = &this->mPolyPassChk;
  if (pcVar2 != (cBgS_PolyPassChk *)0x0) {
    pcVar2 = (cBgS_PolyPassChk *)&this->mGrpPassChk;
  }
  this->mpGrpPassChk = (cBgS_GrpPassChk *)pcVar2;
  this->mProcID = -1;
  this->field_0x38 = 0;
  fVar1 = d_a_agb::_4278;
  this->mOffsY = d_a_agb::_4278;
  this->field_0x40 = fVar1;
  this->mpPos = (cXyz *)0x0;
  this->mpLine0 = (cXyz *)0x0;
  this->field_0x5c = d_a_agb::_5809;
  this->field_0x60 = 0;
  this->field_0x68 = d_a_agb::_5807;
  this->field_0x58 = (undefined *)0x0;
  this->mOffsY2 = d_a_agb::_6658;
  return;
}


/* __thiscall daAgb_HIO_c::~daAgb_HIO_c(void) */

void __thiscall daAgb_HIO_c::_daAgb_HIO_c(daAgb_HIO_c *this)

{
  short in_r4;
  
  if (this != (daAgb_HIO_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (daAgb_HIO_c *)0x0) {
      *(undefined1 **)this = &::mDoHIO_entry_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


namespace d_a_agb {

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __sinit_d_a_agb_cpp(void)

{
  ::daAgb_HIO_c::daAgb_HIO_c((daAgb_HIO_c *)&l_HIO);
  Runtime.PPCEABI.H::__register_global_object();
  Runtime.PPCEABI.H::__register_global_object(&l_msgCtrl,::dMsgCtrl_c::_dMsgCtrl_c,&_4341);
  _uploadFuncTable = _4342;
  DAT_803893d4 = DAT_80389344;
  DAT_803893d8 = PTR_uploadInitCheck_80389348;
  DAT_803893dc = _4343;
  DAT_803893e0 = DAT_80389350;
  DAT_803893e4 = PTR_uploadPortCheckWait_80389354;
  DAT_803893e8 = _4344;
  DAT_803893ec = DAT_8038935c;
  DAT_803893f0 = PTR_uploadSelect_80389360;
  DAT_803893f4 = _4345;
  DAT_803893f8 = DAT_80389368;
  DAT_803893fc = PTR_uploadJoyboot1_8038936c;
  DAT_80389400 = _4346;
  DAT_80389404 = DAT_80389374;
  DAT_80389408 = PTR_uploadJoyboot2_80389378;
  DAT_8038940c = _4347;
  DAT_80389410 = DAT_80389380;
  DAT_80389414 = PTR_uploadConnect_80389384;
  DAT_80389418 = _4348;
  DAT_8038941c = DAT_8038938c;
  DAT_80389420 = PTR_uploadMessageLoad_80389390;
  DAT_80389424 = _4349;
  DAT_80389428 = DAT_80389398;
  DAT_8038942c = PTR_uploadMessageLoad2_8038939c;
  DAT_80389430 = _4350;
  DAT_80389434 = DAT_803893a4;
  DAT_80389438 = PTR_uploadMessageSend_803893a8;
  DAT_8038943c = _4351;
  DAT_80389440 = DAT_803893b0;
  DAT_80389444 = PTR_uploadRetryWait_803893b4;
  DAT_80389448 = _4352;
  DAT_8038944c = DAT_803893bc;
  DAT_80389450 = PTR_uploadMsgEndWait_803893c0;
  DAT_80389454 = _4353;
  DAT_80389458 = DAT_803893c8;
  DAT_8038945c = PTR_uploadMsgEndTimer_803893cc;
  return;
}

}

/* __thiscall dMsgCtrl_c::~dMsgCtrl_c(void) */

void __thiscall dMsgCtrl_c::_dMsgCtrl_c(dMsgCtrl_c *this)

{
  short in_r4;
  
  if ((this != (dMsgCtrl_c *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* [thunk]:__thiscall dBgS_LinkLinChk::~dBgS_LinkLinChk(void) */

void __thiscall dBgS_LinkLinChk::_dBgS_LinkLinChk(dBgS_LinkLinChk *this)

{
  _dBgS_LinkLinChk((dBgS_LinkLinChk *)&this[-1].parent.mPolyPassChk);
  return;
}


/* [thunk]:__thiscall dBgS_LinkLinChk::~dBgS_LinkLinChk(void) */

void __thiscall dBgS_LinkLinChk::_dBgS_LinkLinChk(dBgS_LinkLinChk *this)

{
  _dBgS_LinkLinChk((dBgS_LinkLinChk *)&this[-1].parent.parent.parent.mProcID);
  return;
}


/* [thunk]:__thiscall dBgS_LinkLinChk::~dBgS_LinkLinChk(void) */

void __thiscall dBgS_LinkLinChk::_dBgS_LinkLinChk(dBgS_LinkLinChk *this)

{
  _dBgS_LinkLinChk((dBgS_LinkLinChk *)&this[-1].parent.parent.mPolyInfo);
  return;
}


/* [thunk]:__thiscall dBgS_LinkAcch::~dBgS_LinkAcch(void) */

void __thiscall dBgS_LinkAcch::_dBgS_LinkAcch(dBgS_LinkAcch *this)

{
  _dBgS_LinkAcch(this + -0x20);
  return;
}


/* [thunk]:__thiscall dBgS_LinkAcch::~dBgS_LinkAcch(void) */

void __thiscall dBgS_LinkAcch::_dBgS_LinkAcch(dBgS_LinkAcch *this)

{
  _dBgS_LinkAcch(this + -0x14);
  return;
}


/* [thunk]:__thiscall dBgS_LinkCrrPos::~dBgS_LinkCrrPos(void) */

void __thiscall dBgS_LinkCrrPos::_dBgS_LinkCrrPos(dBgS_LinkCrrPos *this)

{
  _dBgS_LinkCrrPos(this + -0x1c);
  return;
}


/* [thunk]:__thiscall dBgS_LinkCrrPos::~dBgS_LinkCrrPos(void) */

void __thiscall dBgS_LinkCrrPos::_dBgS_LinkCrrPos(dBgS_LinkCrrPos *this)

{
  _dBgS_LinkCrrPos(this + -0x10);
  return;
}


/* [thunk]:__thiscall dBgS_LinkCrrPos::~dBgS_LinkCrrPos(void) */

void __thiscall dBgS_LinkCrrPos::_dBgS_LinkCrrPos(dBgS_LinkCrrPos *this)

{
  _dBgS_LinkCrrPos(this + -0x24);
  return;
}


/* [thunk]:__thiscall dBgS_CrrPos::~dBgS_CrrPos(void) */

void __thiscall dBgS_CrrPos::_dBgS_CrrPos(dBgS_CrrPos *this)

{
  _dBgS_CrrPos((dBgS_CrrPos *)&this[-1].mLinChk.mLin.vtbl);
  return;
}


/* [thunk]:__thiscall dBgS_CrrPos::~dBgS_CrrPos(void) */

void __thiscall dBgS_CrrPos::_dBgS_CrrPos(dBgS_CrrPos *this)

{
  _dBgS_CrrPos((dBgS_CrrPos *)&this[-1].mLinChk.field_0x40.z);
  return;
}


/* [thunk]:__thiscall dBgS_CrrPos::~dBgS_CrrPos(void) */

void __thiscall dBgS_CrrPos::_dBgS_CrrPos(dBgS_CrrPos *this)

{
  _dBgS_CrrPos((dBgS_CrrPos *)&this[-1].mLinChk.mLin.mP1.y);
  return;
}


/* __thiscall daPy_py_c::checkPlayerFly(void) const */

undefined4 __thiscall daPy_py_c::checkPlayerFly(daPy_py_c *this)

{
  return 0;
}

