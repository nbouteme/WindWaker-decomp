#include <d_s_name.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <d_resorce.h>
#include <d_com_lib_game.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <d_com_inf_game.h>
#include <d_s_name.h>
#include <m_Do_ext.h>
#include <JKernel/JKRExpHeap.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <JKernel/JKRHeap.h>
#include <JKernel/JKRMemArchive.h>
#include <d_file_select.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <d_name.h>
#include <d_file_error.h>
#include <d_menu_save.h>
#include <m_Do_hostIO.h>
#include <d_drawlist.h>
#include <d_kankyo.h>
#include <f_op_kankyo_mng.h>
#include <f_pc_layer.h>
#include <f_pc_stdcreate_req.h>
#include <d_menu_cloth.h>
#include <J2DGraph/J2DPane.h>
#include <J2DGraph/J2DScreen.h>
#include <f_op_msg_mng.h>
#include <f_op_overlap_mng.h>
#include <Runtime.PPCEABI.H/ptmf.h>
#include <mtx/mtx44.h>
#include <m_Do_mtx.h>
#include <mtx/mtx.h>
#include <f_op_draw_iter.h>
#include <f_pc_manager.h>
#include <d_save.h>
#include <m_Do_MemCard.h>
#include <os/OSReset.h>
#include <m_Do_MemCardRWmng.h>
#include <JKernel/JKRAram.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <m_Do_dvd_thread.h>
#include <f_op_scene_mng.h>
#include <m_Do_audio.h>
#include <gx/GXTransform.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <dDlst_FLSEL_CLOTH_c.h>
#include <dSn_HIO_c.h>
#include <dScnName_c.h>
#include <dDlst_BTICN_c.h>


namespace d_s_name {
}

namespace d_s_name {
undefined g_snHIO;
}

/* __thiscall dSn_HIO_c::dSn_HIO_c(void) */

void __thiscall dSn_HIO_c::dSn_HIO_c(dSn_HIO_c *this)

{
  *(undefined1 **)this = &__vt;
  this[5] = (dSn_HIO_c)0x14;
  this[6] = (dSn_HIO_c)0xf;
  this[7] = (dSn_HIO_c)0x1e;
  this[8] = (dSn_HIO_c)0x0;
  this[9] = (dSn_HIO_c)0x0;
  this[10] = (dSn_HIO_c)0x0;
  this[0xb] = (dSn_HIO_c)0x0;
  this[0xe] = (dSn_HIO_c)0x7;
  *(undefined2 *)(this + 0xc) = 0xff38;
  this[0xf] = (dSn_HIO_c)0x2;
  this[0x10] = (dSn_HIO_c)0x0;
  this[0x11] = (dSn_HIO_c)0x0;
  this[0x12] = (dSn_HIO_c)0x0;
  this[0x13] = (dSn_HIO_c)0x0;
  this[0x14] = (dSn_HIO_c)0x0;
  this[0x15] = (dSn_HIO_c)0x0;
  this[0x16] = (dSn_HIO_c)0x0;
  this[0x17] = (dSn_HIO_c)0x0;
  this[0x18] = (dSn_HIO_c)0x0;
  this[0x19] = (dSn_HIO_c)0x0;
  this[0x1a] = (dSn_HIO_c)0x0;
  this[0x1b] = (dSn_HIO_c)0x0;
  return;
}


namespace d_s_name {

/* __stdcall phase_1(char *) */

undefined4 phase_1(char *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  JAIZelBasic::bgmStart(JAIZelBasic::zel_basic,(uint)&DAT_8000001e,0,0);
  iVar1 = dRes_control_c::setStageRes
                    (&d_com_inf_game::g_dComIfG_gameInfo.mResCtrl,param_1,(JKRHeap *)0x0);
  uVar2 = 2;
  if (iVar1 == 0) {
    uVar2 = 5;
  }
  return uVar2;
}


/* __stdcall phase_2(char *) */

uint phase_2(char *param_1)

{
  uint uVar1;
  
  uVar1 = dRes_control_c::syncRes
                    (param_1,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mStageInfo,0x40);
  if ((int)uVar1 < 0) {
    uVar1 = 5;
  }
  else {
    uVar1 = ~((int)(-uVar1 & ~uVar1) >> 0x1f) & 2;
  }
  return uVar1;
}


/* __stdcall phase_3(char *) */

undefined4 phase_3(void)

{
  return 4;
}


/* __stdcall resLoad(request_of_phase_process_class *,
                     char *) */

undefined4 resLoad(request_of_phase_process_class *param_1,void *param_2)

{
  undefined4 uVar1;
  
  if (param_1->mStep == 2) {
    uVar1 = 4;
  }
  else {
    uVar1 = d_com_lib_game::dComLbG_PhaseHandler(param_1,(cPhs__Handler *)&l_method_4165,param_2);
  }
  return uVar1;
}

}

/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x802301a0) */
/* WARNING: Removing unreachable block (ram,0x802301a8) */
/* __thiscall dScnName_c::create(void) */

int __thiscall dScnName_c::create(dScnName_c *this)

{
  float fVar1;
  float fVar2;
  JFWDisplay *pJVar3;
  int iVar4;
  JKRExpHeap *pJVar5;
  ulong uVar6;
  undefined4 uVar7;
  JKRMemArchive *this_00;
  void *pvVar8;
  undefined4 *puVar9;
  layer_class *plVar10;
  undefined4 uVar11;
  undefined8 in_f30;
  double dVar12;
  undefined8 in_f31;
  double dVar13;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar11 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNextStage.mbHasNext = 0;
  d_com_inf_game::dComIfGp_setNextStage("Name",0,0,0xff,d_s_name::_4322,0,1,0);
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName._0_4_ =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNextStage.parent.mStageName._0_4_;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName._4_4_ =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNextStage.parent.mStageName._4_4_;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mRoomNo =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNextStage.parent.mRoomNo;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStartCode =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNextStage.parent.mStartCode;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mLayerNo =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNextStage.parent.mLayerNo;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNextStage.mbHasNext = 0;
  iVar4 = d_s_name::resLoad(this + 0x1c4,"Stage");
  if (iVar4 == 4) {
    pJVar5 = m_Do_ext::mDoExt_getGameHeap();
    pJVar5 = JKRExpHeap::create(0x68000,&pJVar5->parent,false);
    *(JKRExpHeap **)(this + 0x1cc) = pJVar5;
    if (*(int *)(this + 0x1cc) == 0) {
      uVar6 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar6,"d_s_name.cpp",0x1c8,"heap != 0");
      m_Do_printf::OSPanic("d_s_name.cpp",0x1c8,"Halt");
    }
    uVar7 = m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(this + 0x1cc));
    *(undefined4 *)(this + 0x1d0) = uVar7;
    this_00 = (JKRMemArchive *)JKernel::operator_new(0x70);
    if (this_00 != (JKRMemArchive *)0x0) {
      JKRMemArchive::JKRMemArchive(this_00);
    }
    *(JKRMemArchive **)(this + 0x40c) = this_00;
    pvVar8 = dRes_control_c::getRes
                       ("Stage",0x17,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mStageInfo,0x40);
    JKRMemArchive::mountFixed(*(JKRMemArchive **)(this + 0x40c),pvVar8,0);
    cloth_create(this);
    buttonIconCreate(this);
    pvVar8 = JKernel::operator_new(0x394c);
    if (pvVar8 != (void *)0x0) {
      *(undefined ***)((int)pvVar8 + 4) = &dDlst_base_c::__vt;
      *(char **)((int)pvVar8 + 4) = d_file_select::l_Collec_6111 + 0x1a8;
      Runtime.PPCEABI.H::__construct_array
                ((void *)((int)pvVar8 + 0x37d8),JUtility::TColor::TColor,(undefined *)0x0,4,0xb);
      Runtime.PPCEABI.H::__construct_array
                ((void *)((int)pvVar8 + 0x3804),JUtility::TColor::TColor,(undefined *)0x0,4,0xb);
      Runtime.PPCEABI.H::__construct_array
                ((void *)((int)pvVar8 + 0x3830),JUtility::TColor::TColor,(undefined *)0x0,4,0x12);
      Runtime.PPCEABI.H::__construct_array
                ((void *)((int)pvVar8 + 0x3878),JUtility::TColor::TColor,(undefined *)0x0,4,0x12);
      Runtime.PPCEABI.H::__construct_array
                ((void *)((int)pvVar8 + 0x38c0),JUtility::TColor::TColor,(undefined *)0x0,4,2);
      Runtime.PPCEABI.H::__construct_array
                ((void *)((int)pvVar8 + 0x38c8),JUtility::TColor::TColor,(undefined *)0x0,4,2);
      Runtime.PPCEABI.H::__construct_array
                ((void *)((int)pvVar8 + 0x38d0),JUtility::TColor::TColor,(undefined *)0x0,4,2);
      Runtime.PPCEABI.H::__construct_array
                ((void *)((int)pvVar8 + 0x38d8),JUtility::TColor::TColor,(undefined *)0x0,4,2);
    }
    *(void **)(this + 0x428) = pvVar8;
    if (*(int *)(this + 0x428) == 0) {
      uVar6 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar6,"d_s_name.cpp",0x1d6,"dFs_c != 0");
      m_Do_printf::OSPanic("d_s_name.cpp",0x1d6,"Halt");
    }
    **(undefined4 **)(this + 0x428) = *(undefined4 *)(this + 0x40c);
    uVar7 = JKernel::operator_new__(0x12000,0x20);
    *(undefined4 *)(this + 0x1bb0) = uVar7;
    if (*(int *)(this + 0x1bb0) == 0) {
      uVar6 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar6,"d_s_name.cpp",0x1dc,"savePicDatabuf != 0");
      m_Do_printf::OSPanic("d_s_name.cpp",0x1dc,"Halt");
    }
    if (*(short *)(this + 8) == 0xc) {
      *(undefined *)(*(int *)(this + 0x428) + 0x3940) = 0;
      puVar9 = (undefined4 *)JKernel::operator_new(0x2ae8);
      if (puVar9 != (undefined4 *)0x0) {
        *puVar9 = &dName_c::__vt;
        puVar9[2] = &dDlst_base_c::__vt;
        puVar9[2] = &dDlst_NameIN_c::__vt;
      }
      *(undefined4 **)(this + 0x424) = puVar9;
      if (*(int *)(this + 0x424) == 0) {
        uVar6 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar6,"d_s_name.cpp",0x1e4,"dNm_c != 0");
        m_Do_printf::OSPanic("d_s_name.cpp",0x1e4,"Halt");
      }
      dName_c::_create(*(dName_c **)(this + 0x424));
      puVar9 = (undefined4 *)JKernel::operator_new(0x30c);
      if (puVar9 != (undefined4 *)0x0) {
        *puVar9 = &dFile_error_c::__vt;
        puVar9[2] = &dDlst_base_c::__vt;
        puVar9[2] = &dDlst_FileErr_c::__vt;
      }
      *(undefined4 **)(this + 0x42c) = puVar9;
      if (*(int *)(this + 0x42c) == 0) {
        uVar6 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar6,"d_s_name.cpp",0x1e9,"dFe_c != 0");
        m_Do_printf::OSPanic("d_s_name.cpp",0x1e9,"Halt");
      }
      dFile_error_c::_create(*(dFile_error_c **)(this + 0x42c));
      *(undefined4 *)(this + 0x430) = 0;
      d_com_inf_game::g_dComIfG_gameInfo._4753_1_ = 0;
      d_com_inf_game::g_dComIfG_gameInfo._4754_1_ = 0;
    }
    if (*(short *)(this + 8) == 0xd) {
      d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mInfo.mNumGamesCompleted = 1;
      *(undefined *)(*(int *)(this + 0x428) + 0x3940) = 1;
      puVar9 = (undefined4 *)JKernel::operator_new(0x1ba4);
      if (puVar9 != (undefined4 *)0x0) {
        *puVar9 = &dMenu_save_c::__vt;
        puVar9[2] = &dDlst_base_c::__vt;
        puVar9[2] = &dDlst_MenuSave_c::__vt;
      }
      *(undefined4 **)(this + 0x430) = puVar9;
      if (*(int *)(this + 0x430) == 0) {
        uVar6 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar6,"d_s_name.cpp",0x1ff,"dMs_c != 0");
        m_Do_printf::OSPanic("d_s_name.cpp",0x1ff,"Halt");
      }
      *(undefined *)(*(int *)(this + 0x430) + 0x537) = 3;
      dMenu_save_c::_create(*(dMenu_save_c **)(this + 0x430));
      *(undefined4 *)(this + 0x42c) = 0;
      *(undefined4 *)(this + 0x424) = 0;
    }
    dFile_select_c::_create(*(dFile_select_c **)(this + 0x428));
    DAT_803e7030 = mDoHIO_subRoot_c::createChild
                             (&mDoHIO_subRoot_c_803a5778,"名前登録シーン",
                              (JORReflexible *)&d_s_name::g_snHIO);
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.field_0x4841 = 1;
    fVar1 = (float)((double)CONCAT44(0x43300000,
                                     (uint)*(ushort *)(mDoMch_render_c::mRenderModeObj + 6)) -
                   d_s_name::_4332);
    dVar12 = (double)fVar1;
    fVar2 = (float)((double)CONCAT44(0x43300000,
                                     (uint)*(ushort *)(mDoMch_render_c::mRenderModeObj + 4)) -
                   d_s_name::_4332);
    dVar13 = (double)fVar2;
    dDlst_window_c::setViewPort
              (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mDlstWindow,d_s_name::_4322,d_s_name::_4322,
               fVar2,fVar1,d_s_name::_4322,d_s_name::_4323);
    dDlst_window_c::setScissor
              (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mDlstWindow,d_s_name::_4322,d_s_name::_4322,
               (float)dVar13,(float)dVar12);
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurCameraInfo = 0;
    d_com_inf_game::g_dComIfG_gameInfo.mPlay._18541_1_ = 2;
    d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera = (camera_class *)(this + 0x1d4);
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera =
         d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera;
    *(float *)(this + 0x29c) = d_s_name::_4324;
    *(float *)(this + 0x2a0) = d_s_name::_4325;
    *(float *)(this + 0x2a4) = d_s_name::_4326;
    *(float *)(this + 0x2a8) =
         (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mDlstWindow[0].mWidth /
         d_com_inf_game::g_dComIfG_gameInfo.mPlay.mDlstWindow[0].mHeight) *
         f_ap_game::g_HIO.aspectRatio;
    *(float *)(this + 0x2ac) = d_s_name::_4327;
    fVar1 = d_s_name::_4322;
    *(float *)(this + 0x2b0) = d_s_name::_4322;
    *(float *)(this + 0x2b4) = d_s_name::_4328;
    *(float *)(this + 0x2b8) = fVar1;
    *(float *)(this + 700) = d_s_name::_4329;
    *(float *)(this + 0x2c0) = d_s_name::_4330;
    *(undefined2 *)(this + 0x2d0) = 0;
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor = (daPy_lk_c *)0x0;
    d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x22c =
         d_com_inf_game::g_dComIfG_gameInfo.mPlay.mDlstWindow;
    d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x230 =
         d_com_inf_game::g_dComIfG_gameInfo.mPlay.mDlstWindow;
    mDoGph_gInf_c::mAutoForcus = 0;
    setView(this);
    d_kankyo::dKy_setLight_init();
    f_op_kankyo_mng::fopKyM_Create(0x1e4,0,0);
    f_op_kankyo_mng::fopKyM_Create(0x1e5,0,0);
    plVar10 = f_pc_layer::fpcLy_CurrentLayer();
    f_pc_stdcreate_req::fpcSCtRq_Request(plVar10,0x1ba,(undefined *)0x0,(void *)0x0,(void *)0x0);
    plVar10 = f_pc_layer::fpcLy_CurrentLayer();
    f_pc_stdcreate_req::fpcSCtRq_Request(plVar10,0x1bb,(undefined *)0x0,(void *)0x0,(void *)0x0);
    d_kankyo::g_env_light.mVrSkyColor.r = 0x50;
    d_kankyo::g_env_light.mVrSkyColor.g = 0x78;
    d_kankyo::g_env_light.mVrSkyColor.b = 0xff;
    d_kankyo::g_env_light.mVrSkyColor.a = 0xff;
    d_kankyo::g_env_light.mVrkumoColor.r = 0xff;
    d_kankyo::g_env_light.mVrkumoColor.g = 0xff;
    d_kankyo::g_env_light.mVrkumoColor.b = 0xff;
    d_kankyo::g_env_light.mVrkumoColor.a = 0xff;
    d_kankyo::g_env_light.mVrKasumiMaeColor.r = 0xd2;
    d_kankyo::g_env_light.mVrKasumiMaeColor.g = 0xe5;
    d_kankyo::g_env_light.mVrKasumiMaeColor.b = 0xff;
    d_kankyo::g_env_light.mVrKasumiMaeColor.a = 0xff;
    this[0x558] = DAT_803e7031;
    this[0x1bb8] = (dScnName_c)0x0;
    if (*(short *)(this + 8) == 0xc) {
      this[0x554] = (dScnName_c)0x0;
      this[0x556] = (dScnName_c)0x0;
      this[0x557] = (dScnName_c)0x0;
    }
    else {
      if (*(short *)(this + 8) == 0xd) {
        this[0x554] = (dScnName_c)0xa;
        this[0x557] = (dScnName_c)0x3;
      }
    }
    pJVar3 = JFWDisplay::sManager;
    *(uint *)&JFWDisplay::sManager->field_0x24 = (DAT_800000f8 >> 2) / 0x1e;
    *(undefined2 *)&pJVar3->field_0x20 = 0;
  }
  __psq_l0(auStack8,uVar11);
  __psq_l1(auStack8,uVar11);
  __psq_l0(auStack24,uVar11);
  __psq_l1(auStack24,uVar11);
  return iVar4;
}


/* __thiscall dScnName_c::cloth_create(void) */

void __thiscall dScnName_c::cloth_create(dScnName_c *this)

{
  cloth2D_create(this);
  this[0x55d] = (dScnName_c)0x0;
  return;
}


/* __thiscall dScnName_c::cloth_move(void) */

void __thiscall dScnName_c::cloth_move(dScnName_c *this)

{
  if ((this[0x55d] != (dScnName_c)0x0) && (DAT_803e7037 == '\0')) {
    dMCloth_c::cloth_move(*(dMCloth_c **)(this + 0x420));
  }
  return;
}


/* __thiscall dScnName_c::cloth2D_create(void) */

void __thiscall dScnName_c::cloth2D_create(dScnName_c *this)

{
  JKRArchive *pJVar1;
  dMCloth_c *this_00;
  ulong uVar2;
  
  pJVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpClothResArchive;
  this_00 = (dMCloth_c *)JKernel::operator_new(0x9168);
  if (this_00 != (dMCloth_c *)0x0) {
    dMCloth_c::dMCloth_c(this_00);
  }
  *(dMCloth_c **)(this + 0x420) = this_00;
  if (*(int *)(this + 0x420) == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_s_name.cpp",0x321,"cloth.cloth_c != 0");
    m_Do_printf::OSPanic("d_s_name.cpp",0x321,"Halt");
  }
  *(JKRArchive **)(*(int *)(this + 0x420) + 0x44) = pJVar1;
  *(undefined *)(*(int *)(this + 0x420) + 0x913d) = 1;
  return;
}


/* __thiscall dScnName_c::buttonIconCreate(void) */

void __thiscall dScnName_c::buttonIconCreate(dScnName_c *this)

{
  J2DPane *this_00;
  ulong uVar1;
  J2DScreen *pJVar2;
  TBox2_float_ local_28;
  undefined4 local_18;
  uint uStack20;
  
  this_00 = (J2DPane *)JKernel::operator_new(0xd4);
  if (this_00 != (J2DPane *)0x0) {
    local_28.mTL.x = d_s_name::_4322;
    local_28.mTL.y = d_s_name::_4322;
    local_28.mBR.x = d_s_name::_4447;
    local_28.mBR.y = d_s_name::_4448;
    J2DPane::J2DPane(this_00,(J2DPane *)0x0,true,0x726f6f74,&local_28);
    this_00->vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
    *(undefined4 *)this_00[1].mMagic = 0xffffffff;
    *(undefined *)&this_00[1].vtbl = 0;
  }
  *(J2DPane **)(this + 0x418) = this_00;
  if (*(int *)(this + 0x418) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_s_name.cpp",0x362,"btnIcon.scr != 0");
    m_Do_printf::OSPanic("d_s_name.cpp",0x362,"Halt");
  }
  J2DScreen::set(*(J2DScreen **)(this + 0x418),"main_parts_fileselect.blo",
                 *(JKRArchive **)(this + 0x40c));
  pJVar2 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x418) + 0x30))(*(int **)(this + 0x418),0x63656e74);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x43c),pJVar2);
  pJVar2 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x418) + 0x30))(*(int **)(this + 0x418),0x626162);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x474),pJVar2);
  pJVar2 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x418) + 0x30))(*(int **)(this + 0x418),0x62616174);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x4ac),pJVar2);
  pJVar2 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x418) + 0x30))(*(int **)(this + 0x418),0x62617770);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x4e4),pJVar2);
  pJVar2 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0x418) + 0x30))(*(int **)(this + 0x418),0x62617764);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x51c),pJVar2);
  *(undefined2 *)(this + 0x1bb4) = 0;
  uStack20 = (int)DAT_803e7038 ^ 0x80000000;
  local_18 = 0x43300000;
  paneTransButtonIcon(this,*(short *)(this + 0x1bb4),DAT_803e703a,
                      (float)((double)CONCAT44(0x43300000,uStack20) - d_s_name::_4450),
                      d_s_name::_4322,'\0');
  this[0x1bb6] = (dScnName_c)0x6;
  return;
}


/* WARNING: Removing unreachable block (ram,0x802305bc) */
/* WARNING: Removing unreachable block (ram,0x802305c4) */
/* __thiscall dScnName_c::paneTransButtonIcon(short,
                                              unsigned char,
                                              float,
                                              float,
                                              unsigned char) */

undefined4 __thiscall
dScnName_c::paneTransButtonIcon
          (dScnName_c *this,short param_1,uchar param_2,float param_3,float param_4,uchar param_5)

{
  undefined4 uVar1;
  undefined3 in_register_00000018;
  undefined4 uVar2;
  double dVar3;
  double dVar4;
  undefined8 in_f30;
  undefined8 in_f31;
  double dVar5;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar4 = (double)param_4;
  dVar5 = (double)param_3;
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  if (param_1 < 0) {
    uVar1 = 0;
  }
  else {
    if ((int)(uint)param_2 < (int)param_1) {
      uVar1 = 1;
    }
    else {
      dVar3 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                ((uint)param_2,(int)param_1,CONCAT31(in_register_00000018,param_5));
      dVar5 = (double)(float)(dVar5 + (double)(float)(dVar3 * (double)(float)(dVar4 - dVar5)));
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0x43c),(double)d_s_name::_4322,dVar5);
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0x474),(double)d_s_name::_4322,dVar5);
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0x4ac),(double)d_s_name::_4322,dVar5);
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0x4e4),(double)d_s_name::_4322,dVar5);
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0x51c),(double)d_s_name::_4322,dVar5);
      uVar1 = 0;
    }
  }
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  __psq_l0(auStack24,uVar2);
  __psq_l1(auStack24,uVar2);
  return uVar1;
}


/* __thiscall dScnName_c::execute(void) */

undefined4 __thiscall dScnName_c::execute(dScnName_c *this)

{
  int iVar1;
  
  iVar1 = f_op_overlap_mng::fopOvlpM_IsPeek();
  if (iVar1 == 0) {
    d_com_inf_game::dComIfG_resetToOpening(this);
  }
  if (*mDoRst::mResetData == 0) {
    cloth_move(this);
    if (*(dFile_error_c **)(this + 0x42c) != (dFile_error_c *)0x0) {
      dFile_error_c::_move(*(dFile_error_c **)(this + 0x42c));
    }
    Runtime.PPCEABI.H::__ptmf_scall
              ((PTMF *)(&d_s_name::MainProc + (uint)(byte)this[0x554] * 3),this,&DAT_80390000);
    buttonIconProc(this);
  }
  return 1;
}


/* __thiscall dScnName_c::setView(void) */

void __thiscall dScnName_c::setView(dScnName_c *this)

{
  float fVar1;
  
  mtx::C_MTXPerspective
            ((double)*(float *)(this + 0x2a4),(double)*(float *)(this + 0x2a8),
             (double)*(float *)(this + 0x29c),(double)*(float *)(this + 0x2a0),this + 0x2d4);
  m_Do_mtx::mDoMtx_lookAt(this + 0x314,this + 0x2ac,this + 0x2b8,(int)*(short *)(this + 0x2d0));
  mtx::PSMTXInverse(this + 0x314,this + 0x344);
  mtx::PSMTXCopy((MTX34 *)(this + 0x314),(MTX34 *)(this + 0x3b4));
  fVar1 = d_s_name::_4322;
  *(float *)(this + 0x3c0) = d_s_name::_4322;
  *(float *)(this + 0x3d0) = fVar1;
  *(float *)(this + 0x3e0) = fVar1;
  mtx::PSMTXCopy((MTX34 *)(this + 0x314),&J3DGraphBase::j3dSys.mCurViewMtx);
  m_Do_mtx::mDoMtx_concatProjView(this + 0x2d4,this + 0x314,this + 0x374);
  return;
}


/* __thiscall dScnName_c::draw(void) */

undefined4 __thiscall dScnName_c::draw(dScnName_c *this)

{
  create_tag_class *pcVar1;
  
  setView(this);
  for (pcVar1 = (create_tag_class *)f_op_draw_iter::fopDwIt_Begin();
      pcVar1 != (create_tag_class *)0x0;
      pcVar1 = (create_tag_class *)f_op_draw_iter::fopDwIt_Next(pcVar1)) {
    f_pc_manager::fpcM_Draw(pcVar1->mpTagData);
  }
  if ((this[0x55d] != (dScnName_c)0x0) && (DAT_803e7037 == '\0')) {
    dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                      &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                      &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                      (dDlst_base_c *)(this + 0x41c));
  }
  Runtime.PPCEABI.H::__ptmf_scall
            ((PTMF *)(&d_s_name::DrawProc + (uint)(byte)this[0x557] * 3),this,&DAT_80390000);
  dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                    (dDlst_base_c *)(this + 0x414));
  return 1;
}


/* __thiscall dScnName_c::~dScnName_c(void) */

void __thiscall dScnName_c::_dScnName_c(dScnName_c *this)

{
  JKRHeap *pJVar1;
  int *piVar2;
  short in_r4;
  
  if (this != (dScnName_c *)0x0) {
    dFile_select_c::_delete(*(dFile_select_c **)(this + 0x428));
    pJVar1 = *(JKRHeap **)(this + 0x428);
    if (pJVar1 != (JKRHeap *)0x0) {
      if ((pJVar1 != (JKRHeap *)0xfffffffc) &&
         (*(char **)&pJVar1->field_0x4 = d_file_select::l_Collec_6111 + 0x1a8,
         pJVar1 != (JKRHeap *)0xfffffffc)) {
        *(undefined ***)&pJVar1->field_0x4 = &dDlst_base_c::__vt;
      }
      JKernel::operator_delete(pJVar1);
    }
    if (*(dName_c **)(this + 0x424) != (dName_c *)0x0) {
      dName_c::_delete(*(dName_c **)(this + 0x424));
      piVar2 = *(int **)(this + 0x424);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2,1);
      }
    }
    if (*(dFile_error_c **)(this + 0x42c) != (dFile_error_c *)0x0) {
      dFile_error_c::_delete(*(dFile_error_c **)(this + 0x42c));
      piVar2 = *(int **)(this + 0x42c);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2,1);
      }
    }
    if (*(dMenu_save_c **)(this + 0x430) != (dMenu_save_c *)0x0) {
      dMenu_save_c::_delete(*(dMenu_save_c **)(this + 0x430));
      piVar2 = *(int **)(this + 0x430);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2,1);
      }
    }
    JKernel::operator_delete(*(JKRHeap **)(this + 0x1bb0));
    piVar2 = *(int **)(this + 0x418);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2,1);
    }
    JKRMemArchive::unmountFixed(*(JKRMemArchive **)(this + 0x40c));
    piVar2 = *(int **)(this + 0x420);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2,1);
    }
    mDoHIO_subRoot_c::deleteChild(&mDoHIO_subRoot_c_803a5778,DAT_803e7030);
    JKRHeap::becomeCurrentHeap(*(JKRHeap **)(this + 0x1d0));
    JKRHeap::destroy(*(JKRHeap **)(this + 0x1cc));
    dRes_control_c::deleteRes("Stage",d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mStageInfo,0x40);
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.field_0x4841 = 0;
    dSv_restart_c::setRestartOption(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mRestart,'\0');
    if (this != (dScnName_c *)0xfffffbe4) {
      *(undefined1 **)(this + 0x41c) = &dDlst_FLSEL_CLOTH_c::__vt;
      if (this != (dScnName_c *)0xfffffbe4) {
        *(undefined ***)(this + 0x41c) = &dDlst_base_c::__vt;
      }
    }
    if (this != (dScnName_c *)0xfffffbec) {
      *(undefined1 **)(this + 0x414) = &dDlst_BTICN_c::__vt;
      if (this != (dScnName_c *)0xfffffbec) {
        *(undefined ***)(this + 0x414) = &dDlst_base_c::__vt;
      }
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dScnName_c::MemCardCheckMain(void) */

void __thiscall dScnName_c::MemCardCheckMain(dScnName_c *this)

{
  if (((DAT_file_cursor == 0) || (DAT_file_cursor == 1)) && (*mDoRst::mResetData == 0)) {
    if ((this[0x1bb8] == (dScnName_c)0x0) &&
       ((*(dFile_error_c **)(this + 0x42c))[0x2f5] == (dFile_error_c)0x1)) {
      dFile_error_c::closeMessage(*(dFile_error_c **)(this + 0x42c));
      this[0x55a] = (dScnName_c)0xff;
      this[0x55b] = (dScnName_c)0x0;
      this[0x556] = (dScnName_c)0x2;
    }
    DAT_file_cursor = 2;
  }
  Runtime.PPCEABI.H::__ptmf_scall
            ((PTMF *)(&d_s_name::MemCardCheckProc + (uint)(byte)this[0x556] * 3),this,&DAT_80390000)
  ;
  return;
}


/* __thiscall dScnName_c::MemCardStatCheck(void) */

void __thiscall dScnName_c::MemCardStatCheck(dScnName_c *this)

{
  mDoMemCd_Ctrl_status mVar1;
  
  if (this[0x558] == (dScnName_c)0x0) {
    mVar1 = mDoMemCd_Ctrl_c::getStatus(&m_Do_MemCard::g_mDoMemCd_control,0);
    switch(mVar1) {
    case STANDBY:
      dFile_error_c::setErrMessage(*(dFile_error_c **)(this + 0x42c),9,0);
      this[0x55b] = (dScnName_c)0x4;
      this[0x55a] = (dScnName_c)0x1a;
      this[0x556] = (dScnName_c)0x2;
      break;
    case RESTORE:
      dFile_error_c::setErrMessage(*(dFile_error_c **)(this + 0x42c),0x15,0);
      this[0x556] = (dScnName_c)0x9;
      break;
    case CREATE:
      DAT_803b4ff0 = *(undefined4 *)(this + 0x1bb0);
      mDoMemCd_Ctrl_c::load(&m_Do_MemCard::g_mDoMemCd_control);
      this[0x556] = (dScnName_c)0x1;
      break;
    case ENCODING:
    case ERROR:
      dFile_error_c::setErrMessage(*(dFile_error_c **)(this + 0x42c),0x2d,0);
      this[0x556] = (dScnName_c)0x5;
      break;
    case 8:
      dFile_error_c::setErrMessage(*(dFile_error_c **)(this + 0x42c),10,0);
      this[0x55b] = (dScnName_c)0x4;
      this[0x55a] = (dScnName_c)0x1a;
      this[0x556] = (dScnName_c)0x2;
      break;
    case 9:
      dFile_error_c::setErrMessage(*(dFile_error_c **)(this + 0x42c),0xb,0);
      this[0x55b] = (dScnName_c)0x4;
      this[0x55a] = (dScnName_c)0x1a;
      this[0x556] = (dScnName_c)0x2;
      break;
    case WRONG_DEVICE:
      dFile_error_c::setErrMessage(*(dFile_error_c **)(this + 0x42c),0xc,0);
      this[0x55b] = (dScnName_c)0x4;
      this[0x55a] = (dScnName_c)0x1a;
      this[0x556] = (dScnName_c)0x2;
      break;
    case 0xb:
    case IOERROR:
      dFile_error_c::setErrMessage(*(dFile_error_c **)(this + 0x42c),0xf,0);
      this[0x556] = (dScnName_c)0x3;
      this[0x55a] = (dScnName_c)0x60;
      this[0x55c] = (dScnName_c)0x61;
      this[0x55b] = (dScnName_c)0xd;
    }
  }
  else {
    this[0x558] = (dScnName_c)((char)this[0x558] + -1);
  }
  return;
}


/* __thiscall dScnName_c::MemCardLoadWait(void) */

void __thiscall dScnName_c::MemCardLoadWait(dScnName_c *this)

{
  int iVar1;
  
  iVar1 = mDoMemCd_Ctrl_c::LoadSync(&m_Do_MemCard::g_mDoMemCd_control,this + 0x560,0x1650,0);
  if (iVar1 != 0) {
    if (iVar1 == 1) {
      d_com_inf_game::g_dComIfG_gameInfo._4764_4_ = DAT_803b502c;
      d_com_inf_game::g_dComIfG_gameInfo._4760_4_ = DAT_CardSerialNo;
      if (d_com_inf_game::g_dComIfG_gameInfo._4754_1_ != '\0') {
        d_com_inf_game::g_dComIfG_gameInfo._4754_1_ = '\0';
      }
      this[0x554] = (dScnName_c)0x1;
      this[0x557] = (dScnName_c)0x4;
    }
    else {
      if (iVar1 == 2) {
        this[0x556] = (dScnName_c)0x0;
      }
    }
  }
  return;
}


/* __thiscall dScnName_c::MemCardErrMsgWaitKey(void) */

void __thiscall dScnName_c::MemCardErrMsgWaitKey(dScnName_c *this)

{
  if ((*(dFile_error_c **)(this + 0x42c))[0x2f5] == (dFile_error_c)0x2) {
    if ((byte)this[0x55a] != 0xff) {
      dFile_error_c::setErrMessage(*(dFile_error_c **)(this + 0x42c),(uint)(byte)this[0x55a],0);
    }
    this[0x556] = this[0x55b];
  }
  return;
}


/* __thiscall dScnName_c::MemCardErrMsgWaitKey2(void) */

void __thiscall dScnName_c::MemCardErrMsgWaitKey2(dScnName_c *this)

{
  dFile_error_c *this_00;
  
  this_00 = *(dFile_error_c **)(this + 0x42c);
  if (this_00[0x2f5] == (dFile_error_c)0x2) {
    if ((byte)this[0x55a] == 0xff) {
      dFile_error_c::setErrMessage(this_00,(uint)(byte)this[0x55c],0);
      this[0x556] = this[0x55b];
    }
    else {
      dFile_error_c::setErrMessage(this_00,(uint)(byte)this[0x55a],0);
      this[0x55a] = (dScnName_c)0xff;
      this[0x556] = (dScnName_c)0x3;
    }
  }
  return;
}


/* __thiscall dScnName_c::MemCardGotoIPLSelect(void) */

void __thiscall dScnName_c::MemCardGotoIPLSelect(dScnName_c *this)

{
  dFile_error_c *this_00;
  
  this_00 = *(dFile_error_c **)(this + 0x42c);
  if (this_00[0x2f5] == (dFile_error_c)0x2) {
    if (this_00[0x2f6] == (dFile_error_c)0x1) {
      dFile_error_c::setErrMessage(this_00,0x1a,0);
      this[0x556] = (dScnName_c)0x4;
    }
    else {
      this[0x556] = (dScnName_c)0xe;
    }
  }
  return;
}


/* __thiscall dScnName_c::MemCardGotoIPL(void) */

void __thiscall dScnName_c::MemCardGotoIPL(dScnName_c *this)

{
  os::OSResetSystem(1,1,1);
  return;
}


/* __thiscall dScnName_c::MemCardErrMsgWaitNoSaveSel(void) */

void __thiscall dScnName_c::MemCardErrMsgWaitNoSaveSel(dScnName_c *this)

{
  if (*(char *)(*(int *)(this + 0x42c) + 0x2f5) == '\x02') {
    if (*(char *)(*(int *)(this + 0x42c) + 0x2f6) == '\x01') {
      this[0x556] = (dScnName_c)0x0;
    }
    else {
      dSv_info_c::initdata_to_card
                (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo,(char *)(this + 0x560),0);
      m_Do_MemCardRWmng::mDoMemCdRWm_SetCheckSumGameData(this + 0x560,0);
      dSv_info_c::initdata_to_card
                (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo,(char *)(this + 0x560),1);
      m_Do_MemCardRWmng::mDoMemCdRWm_SetCheckSumGameData(this + 0x560,1);
      dSv_info_c::initdata_to_card
                (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo,(char *)(this + 0x560),2);
      m_Do_MemCardRWmng::mDoMemCdRWm_SetCheckSumGameData(this + 0x560,2);
      d_com_inf_game::g_dComIfG_gameInfo._4754_1_ = 1;
      this[0x554] = (dScnName_c)0x1;
      this[0x557] = (dScnName_c)0x4;
    }
  }
  return;
}


/* __thiscall dScnName_c::MemCardErrMsgWaitFormatSel(void) */

void __thiscall dScnName_c::MemCardErrMsgWaitFormatSel(dScnName_c *this)

{
  dFile_error_c *this_00;
  
  this_00 = *(dFile_error_c **)(this + 0x42c);
  if (this_00[0x2f5] == (dFile_error_c)0x2) {
    if (this_00[0x2f6] == (dFile_error_c)0x1) {
      dFile_error_c::setErrMessage(this_00,0x10,0);
      this[0x55b] = (dScnName_c)0x4;
      this[0x55a] = (dScnName_c)0x1a;
      this[0x556] = (dScnName_c)0x2;
    }
    else {
      dFile_error_c::setErrMessage(this_00,0x11,0);
      this[0x556] = (dScnName_c)0x6;
    }
  }
  return;
}


/* __thiscall dScnName_c::MemCardErrMsgWaitFormatSel2(void) */

void __thiscall dScnName_c::MemCardErrMsgWaitFormatSel2(dScnName_c *this)

{
  dFile_error_c *this_00;
  
  this_00 = *(dFile_error_c **)(this + 0x42c);
  if (this_00[0x2f5] == (dFile_error_c)0x2) {
    if (this_00[0x2f6] == (dFile_error_c)0x1) {
      dFile_error_c::setErrMessage(this_00,0x10,0);
      this[0x55b] = (dScnName_c)0x4;
      this[0x55a] = (dScnName_c)0x1a;
      this[0x556] = (dScnName_c)0x2;
    }
    else {
      mDoMemCd_Ctrl_c::command_format(&m_Do_MemCard::g_mDoMemCd_control);
      dFile_error_c::setErrMessage(*(dFile_error_c **)(this + 0x42c),0x12,1);
      this[0x556] = (dScnName_c)0x7;
      this[0x1bb8] = (dScnName_c)0x1;
    }
  }
  return;
}


/* __thiscall dScnName_c::MemCardFormat(void) */

void __thiscall dScnName_c::MemCardFormat(dScnName_c *this)

{
  undefined4 uVar1;
  
  uVar1 = mDoMemCd_Ctrl_c::FormatSync(&m_Do_MemCard::g_mDoMemCd_control);
  *(undefined4 *)(this + 0x1bbc) = uVar1;
  if (*(int *)(this + 0x1bbc) != 0) {
    dFile_error_c::closeMessage(*(dFile_error_c **)(this + 0x42c));
    this[0x556] = (dScnName_c)0x8;
  }
  return;
}


/* __thiscall dScnName_c::MemCardFormatCheck(void) */

void __thiscall dScnName_c::MemCardFormatCheck(dScnName_c *this)

{
  if (*(char *)(*(int *)(this + 0x42c) + 0x2f5) == '\x02') {
    if (*(int *)(this + 0x1bbc) == 2) {
      this[0x55a] = (dScnName_c)0xff;
      this[0x55b] = (dScnName_c)0x0;
      dFile_error_c::setErrMessage(*(dFile_error_c **)(this + 0x42c),0x14,0);
      this[0x556] = (dScnName_c)0x2;
    }
    else {
      if (*(int *)(this + 0x1bbc) == 1) {
        this[0x55a] = (dScnName_c)0xff;
        this[0x55b] = (dScnName_c)0x0;
        dFile_error_c::setErrMessage(*(dFile_error_c **)(this + 0x42c),0x13,0);
        *(undefined *)(*(int *)(this + 0x42c) + 0x2fc) = 1;
        this[0x556] = (dScnName_c)0x2;
      }
    }
    this[0x1bb8] = (dScnName_c)0x0;
    this[0x55a] = (dScnName_c)0xff;
  }
  return;
}


/* __thiscall dScnName_c::MemCardMakeGameFileSel(void) */

void __thiscall dScnName_c::MemCardMakeGameFileSel(dScnName_c *this)

{
  dFile_error_c *this_00;
  
  this_00 = *(dFile_error_c **)(this + 0x42c);
  if (this_00[0x2f5] == (dFile_error_c)0x2) {
    if (this_00[0x2f6] == (dFile_error_c)0x1) {
      dFile_error_c::setErrMessage(this_00,0x16,0);
      this[0x55b] = (dScnName_c)0x4;
      this[0x55a] = (dScnName_c)0x1a;
      this[0x556] = (dScnName_c)0x2;
    }
    else {
      dSv_info_c::initdata_to_card
                (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo,(char *)(this + 0x560),0);
      m_Do_MemCardRWmng::mDoMemCdRWm_SetCheckSumGameData(this + 0x560,0);
      dSv_info_c::initdata_to_card
                (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo,(char *)(this + 0x560),1);
      m_Do_MemCardRWmng::mDoMemCdRWm_SetCheckSumGameData(this + 0x560,1);
      dSv_info_c::initdata_to_card
                (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo,(char *)(this + 0x560),2);
      m_Do_MemCardRWmng::mDoMemCdRWm_SetCheckSumGameData(this + 0x560,2);
      mDoMemCd_Ctrl_c::save(&m_Do_MemCard::g_mDoMemCd_control,this + 0x560,0x1650,0);
      dFile_error_c::setErrMessage(*(dFile_error_c **)(this + 0x42c),0x17,1);
      this[0x556] = (dScnName_c)0xa;
      this[0x1bb8] = (dScnName_c)0x1;
    }
  }
  return;
}


/* __thiscall dScnName_c::MemCardMakeGameFile(void) */

void __thiscall dScnName_c::MemCardMakeGameFile(dScnName_c *this)

{
  undefined4 uVar1;
  
  uVar1 = mDoMemCd_Ctrl_c::SaveSync(&m_Do_MemCard::g_mDoMemCd_control);
  *(undefined4 *)(this + 0x1bbc) = uVar1;
  if (*(int *)(this + 0x1bbc) != 0) {
    dFile_error_c::closeMessage(*(dFile_error_c **)(this + 0x42c));
    this[0x556] = (dScnName_c)0xb;
  }
  return;
}


/* __thiscall dScnName_c::MemCardMakeGameFileCheck(void) */

void __thiscall dScnName_c::MemCardMakeGameFileCheck(dScnName_c *this)

{
  if (*(char *)(*(int *)(this + 0x42c) + 0x2f5) == '\x02') {
    if (*(int *)(this + 0x1bbc) == 2) {
      this[0x55a] = (dScnName_c)0xff;
      this[0x55b] = (dScnName_c)0x0;
      dFile_error_c::setErrMessage(*(dFile_error_c **)(this + 0x42c),0x18,0);
      this[0x556] = (dScnName_c)0x2;
    }
    else {
      if (*(int *)(this + 0x1bbc) == 1) {
        d_com_inf_game::g_dComIfG_gameInfo._4753_1_ = 1;
        this[0x55a] = (dScnName_c)0xff;
        this[0x55b] = (dScnName_c)0xc;
        dFile_error_c::setErrMessage(*(dFile_error_c **)(this + 0x42c),0x19,0);
        this[0x556] = (dScnName_c)0x2;
      }
    }
    this[0x1bb8] = (dScnName_c)0x0;
    this[0x55a] = (dScnName_c)0xff;
  }
  return;
}


/* __thiscall dScnName_c::MemCardGotoFileSelect(void) */

void __thiscall dScnName_c::MemCardGotoFileSelect(dScnName_c *this)

{
  this[0x554] = (dScnName_c)0x1;
  this[0x557] = (dScnName_c)0x4;
  return;
}


/* __thiscall dScnName_c::MemCardCheckDbg(void) */

void __thiscall dScnName_c::MemCardCheckDbg(dScnName_c *this)

{
  return;
}


/* __thiscall dScnName_c::MemCardCheckDbgWait(void) */

void __thiscall dScnName_c::MemCardCheckDbgWait(dScnName_c *this)

{
  if ((*(dFile_error_c **)(this + 0x42c))[0x2f5] == (dFile_error_c)0x0) {
    if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 5 & 1) == 0) {
      if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 3 & 1) != 0) {
        this[0x554] = (dScnName_c)0x1;
        this[0x557] = (dScnName_c)0x4;
      }
    }
    else {
      dFile_error_c::initial(*(dFile_error_c **)(this + 0x42c));
      this[0x556] = (dScnName_c)0xf;
    }
  }
  return;
}


/* __thiscall dScnName_c::FileErrorDraw(void) */

void __thiscall dScnName_c::FileErrorDraw(dScnName_c *this)

{
  if (*(dFile_error_c **)(this + 0x42c) != (dFile_error_c *)0x0) {
    dFile_error_c::_draw(*(dFile_error_c **)(this + 0x42c));
  }
  return;
}


/* __thiscall dScnName_c::NoteOpen(void) */

void __thiscall dScnName_c::NoteOpen(dScnName_c *this)

{
  EVP_PKEY_CTX *ctx;
  
  if (this[0x558] == (dScnName_c)0x0) {
    ctx = (EVP_PKEY_CTX *)0x899;
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x899,(cXyz *)0x0,0,0,d_s_name::_4323,d_s_name::_4323,
               d_s_name::_4959,d_s_name::_4959,0);
    this[0x554] = (dScnName_c)0x2;
    this[0x55d] = (dScnName_c)0x1;
    dMCloth_c::init(*(dMCloth_c **)(this + 0x420),ctx);
    this[0x559] = DAT_803e7032;
  }
  else {
    this[0x558] = (dScnName_c)((char)this[0x558] + -1);
  }
  return;
}


/* __thiscall dScnName_c::NoteOpenWait(void) */

void __thiscall dScnName_c::NoteOpenWait(dScnName_c *this)

{
  if (this[0x559] == (dScnName_c)0x0) {
    if (DAT_803e7034 == '\0') {
      if (*(short *)(this + 8) == 0xc) {
        *(dScnName_c **)(*(int *)(this + 0x428) + 0x3938) = this + 0x560;
        *(undefined4 *)(*(int *)(this + 0x428) + 0x393c) = *(undefined4 *)(this + 0x1bb0);
      }
      if (*(short *)(this + 8) == 0xd) {
        *(int *)(*(int *)(this + 0x428) + 0x3938) = *(int *)(this + 0x430) + 0x554;
        *(undefined4 *)(*(int *)(this + 0x428) + 0x393c) = *(undefined4 *)(this + 0x1bb0);
      }
      dFile_select_c::initial(*(dFile_select_c **)(this + 0x428));
      this[0x554] = (dScnName_c)0x3;
      this[0x555] = (dScnName_c)0x0;
      this[0x557] = (dScnName_c)0x1;
    }
  }
  else {
    this[0x559] = (dScnName_c)((char)this[0x559] + -1);
  }
  return;
}


/* __thiscall dScnName_c::FileSelectOpen(void) */

void __thiscall dScnName_c::FileSelectOpen(dScnName_c *this)

{
  Runtime.PPCEABI.H::__ptmf_scall
            ((PTMF *)(&d_s_name::FileSelOpenProc + (uint)(byte)this[0x555] * 3),this,&DAT_80390000);
  return;
}


/* __thiscall dScnName_c::buttonIconProc(void) */

void __thiscall dScnName_c::buttonIconProc(dScnName_c *this)

{
  int iVar1;
  
  switch(this[0x1bb6]) {
  case (dScnName_c)0x0:
    iVar1 = paneTransButtonIcon(this,*(short *)(this + 0x1bb4) - (ushort)DAT_803e703b,DAT_803e703a,
                                (float)((double)CONCAT44(0x43300000,(int)DAT_803e7038 ^ 0x80000000)
                                       - d_s_name::_4450),d_s_name::_4322,'\x01');
    *(short *)(this + 0x1bb4) = *(short *)(this + 0x1bb4) + 1;
    if (iVar1 == 1) {
      *(undefined2 *)(this + 0x1bb4) = 0;
      this[0x1bb6] = (dScnName_c)0x6;
      *(dScnName_c *)(*(int *)(this + 0x428) + 0x3936) = this[0x1bb6];
    }
    break;
  case (dScnName_c)0x1:
    if (*(char *)(*(int *)(this + 0x51c) + 0xaa) != '\0') {
      *(undefined *)(*(int *)(this + 0x51c) + 0xaa) = 0;
      *(undefined *)(*(int *)(this + 0x474) + 0xaa) = 0;
      *(undefined *)(*(int *)(this + 0x4ac) + 0xaa) = 0;
    }
    iVar1 = paneTransButtonIcon(this,*(short *)(this + 0x1bb4) - (ushort)DAT_803e703b,DAT_803e703a,
                                (float)((double)CONCAT44(0x43300000,(int)DAT_803e7038 ^ 0x80000000)
                                       - d_s_name::_4450),d_s_name::_4322,'\x01');
    *(short *)(this + 0x1bb4) = *(short *)(this + 0x1bb4) + 1;
    if (iVar1 == 1) {
      *(undefined2 *)(this + 0x1bb4) = 0;
      this[0x1bb6] = (dScnName_c)0x6;
      *(dScnName_c *)(*(int *)(this + 0x428) + 0x3936) = this[0x1bb6];
    }
    break;
  case (dScnName_c)0x2:
    if (*(char *)(*(int *)(this + 0x51c) + 0xaa) == '\0') {
      *(undefined *)(*(int *)(this + 0x51c) + 0xaa) = 1;
      *(undefined *)(*(int *)(this + 0x474) + 0xaa) = 1;
      *(undefined *)(*(int *)(this + 0x4ac) + 0xaa) = 1;
    }
    iVar1 = paneTransButtonIcon(this,*(short *)(this + 0x1bb4) - (ushort)DAT_803e703b,DAT_803e703a,
                                (float)((double)CONCAT44(0x43300000,(int)DAT_803e7038 ^ 0x80000000)
                                       - d_s_name::_4450),d_s_name::_4322,'\x01');
    *(short *)(this + 0x1bb4) = *(short *)(this + 0x1bb4) + 1;
    if (iVar1 == 1) {
      *(undefined2 *)(this + 0x1bb4) = 0;
      this[0x1bb6] = (dScnName_c)0x6;
      *(dScnName_c *)(*(int *)(this + 0x428) + 0x3936) = this[0x1bb6];
    }
    break;
  case (dScnName_c)0x3:
    iVar1 = paneTransButtonIcon(this,*(short *)(this + 0x1bb4) - (ushort)DAT_803e703b,DAT_803e703a,
                                d_s_name::_4322,
                                (float)((double)CONCAT44(0x43300000,(int)DAT_803e7038 ^ 0x80000000)
                                       - d_s_name::_4450),'\0');
    *(short *)(this + 0x1bb4) = *(short *)(this + 0x1bb4) + 1;
    if (iVar1 == 1) {
      *(undefined2 *)(this + 0x1bb4) = 0;
      this[0x1bb6] = (dScnName_c)0x6;
      *(dScnName_c *)(*(int *)(this + 0x428) + 0x3936) = this[0x1bb6];
    }
    break;
  case (dScnName_c)0x4:
    iVar1 = paneTransButtonIcon(this,*(short *)(this + 0x1bb4) - (ushort)DAT_803e703b,DAT_803e703a,
                                d_s_name::_4322,
                                (float)((double)CONCAT44(0x43300000,(int)DAT_803e7038 ^ 0x80000000)
                                       - d_s_name::_4450),'\0');
    *(short *)(this + 0x1bb4) = *(short *)(this + 0x1bb4) + 1;
    if (iVar1 == 1) {
      *(undefined2 *)(this + 0x1bb4) = 0;
      if (*(char *)(*(int *)(this + 0x51c) + 0xaa) == '\0') {
        *(undefined *)(*(int *)(this + 0x51c) + 0xaa) = 1;
        *(undefined *)(*(int *)(this + 0x474) + 0xaa) = 1;
        *(undefined *)(*(int *)(this + 0x4ac) + 0xaa) = 1;
      }
      this[0x1bb6] = (dScnName_c)0x0;
      *(dScnName_c *)(*(int *)(this + 0x428) + 0x3936) = this[0x1bb6];
    }
    break;
  case (dScnName_c)0x5:
    iVar1 = paneTransButtonIcon(this,*(short *)(this + 0x1bb4) - (ushort)DAT_803e703b,DAT_803e703a,
                                d_s_name::_4322,
                                (float)((double)CONCAT44(0x43300000,(int)DAT_803e7038 ^ 0x80000000)
                                       - d_s_name::_4450),'\0');
    *(short *)(this + 0x1bb4) = *(short *)(this + 0x1bb4) + 1;
    if (iVar1 == 1) {
      *(undefined2 *)(this + 0x1bb4) = 0;
      if (*(char *)(*(int *)(this + 0x51c) + 0xaa) != '\0') {
        *(undefined *)(*(int *)(this + 0x51c) + 0xaa) = 0;
        *(undefined *)(*(int *)(this + 0x474) + 0xaa) = 0;
        *(undefined *)(*(int *)(this + 0x4ac) + 0xaa) = 0;
      }
      this[0x1bb6] = (dScnName_c)0x0;
      *(dScnName_c *)(*(int *)(this + 0x428) + 0x3936) = this[0x1bb6];
    }
  }
  return;
}


/* __thiscall dScnName_c::FileSelOpenMain(void) */

void __thiscall dScnName_c::FileSelOpenMain(dScnName_c *this)

{
  char cVar1;
  
  cVar1 = dFile_select_c::_open(*(dFile_select_c **)(this + 0x428));
  if (cVar1 == '\x01') {
    if (*(short *)(this + 8) == 0xd) {
      this[0x1bb6] = (dScnName_c)0x2;
    }
    else {
      this[0x1bb6] = (dScnName_c)0x1;
    }
    *(dScnName_c *)(*(int *)(this + 0x428) + 0x3936) = this[0x1bb6];
    this[0x554] = (dScnName_c)0x4;
  }
  return;
}


/* __thiscall dScnName_c::FileselOpenWait(void) */

void __thiscall dScnName_c::FileselOpenWait(dScnName_c *this)

{
  return;
}


/* __thiscall dScnName_c::FileSelectMain(void) */

void __thiscall dScnName_c::FileSelectMain(dScnName_c *this)

{
  dFile_select_c::_move(*(dFile_select_c **)(this + 0x428));
  this[0x1bb6] = *(dScnName_c *)(*(int *)(this + 0x428) + 0x3936);
  if (*(short *)(this + 8) == 0xc) {
    FileSelectMainNormal(this);
  }
  if (*(short *)(this + 8) == 0xd) {
    FileSelectMainExSave(this);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f24 */
/* WARNING: Inlined function: FUN_80328f70 */
/* __thiscall dScnName_c::FileSelectMainNormal(void) */

void __thiscall dScnName_c::FileSelectMainNormal(dScnName_c *this)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  ushort uVar5;
  int iVar4;
  uint uVar6;
  int in_r10;
  JKRAram *this_00;
  char cVar7;
  char cVar8;
  
  bVar1 = *(byte *)(*(int *)(this + 0x428) + 0x392c);
  if (bVar1 == 2) {
    this[0x1bb6] = (dScnName_c)0x3;
    this[0x554] = (dScnName_c)0x5;
  }
  else {
    if ((bVar1 < 2) && (bVar1 != 0)) {
      this[0x1bb9] = (dScnName_c)0x0;
      uVar6 = (uint)*(byte *)(*(int *)(this + 0x428) + 0x3922);
      if (*(char *)(*(int *)(this + 0x428) + uVar6 + 0x3914) == '\0') {
        dSv_info_c::card_to_memory
                  (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo,(char *)(this + 0x560),uVar6);
        if ((*(char *)(*(int *)(this + 0x428) + (uint)*(byte *)(*(int *)(this + 0x428) + 0x3922) +
                      0x391a) != '\0') &&
           (iVar3 = dSv_event_c::isEventBit
                              (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x3510),
           iVar3 == 0)) {
          this[0x1bb9] = (dScnName_c)0x1;
        }
        cVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._2_1_;
        if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._2_1_ != '\0') {
          cVar8 = '\0';
          uVar6 = 0;
          cVar7 = '\0';
          this_00 = (JKRAram *)
                    (*(int *)(this + 0x1bb0) +
                    (uint)*(byte *)(*(int *)(this + 0x428) + 0x3922) * 0x6000);
          iVar3 = 0;
          do {
            uVar5 = dSv_event_c::getEventReg
                              (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x89ff);
            if ((1 << iVar3 & uVar5 & 0xff) == 0) {
              iVar4 = m_Do_MemCardRWmng::mDoMemCdRWm_TestCheckSumPictData(this_00);
              if (iVar4 == 0) {
                cVar8 = cVar8 + '\x01';
              }
              else {
                JKRAram::mainRamToAram
                          (this_00,*(uchar **)
                                    ((int)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mDlstWindow +
                                    (uVar6 & 0xff) * 4 + -0x44),(JKRAramBlock *)0x2000,0,0,0,
                           (JKRHeap *)&DAT_ffffffff,in_r10);
                uVar6 = uVar6 + 1;
              }
              cVar7 = cVar7 + '\x01';
              if (cVar7 == cVar2) break;
            }
            this_00 = (JKRAram *)&this_00[0x3e].field_0x8;
            iVar3 = iVar3 + 1;
          } while (iVar3 < 3);
          d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._2_1_ = cVar2 - cVar8
          ;
        }
        dSv_event_c::setEventReg(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x89ff,0);
        DAT_803b4ff0 = 0;
        dComIfG_play_c::itemInit(&d_com_inf_game::g_dComIfG_gameInfo.mPlay);
        if (this[0x1bb9] == (dScnName_c)0x0) {
          this[0x55f] = (dScnName_c)0x0;
          this[0x554] = (dScnName_c)0x9;
        }
        else {
          this[0x1bb6] = (dScnName_c)0x3;
          this[0x554] = (dScnName_c)0x5;
        }
      }
      else {
        this[0x1bb6] = (dScnName_c)0x3;
        this[0x554] = (dScnName_c)0x5;
      }
    }
  }
  return;
}


/* __thiscall dScnName_c::FileSelectMainExSave(void) */

void __thiscall dScnName_c::FileSelectMainExSave(dScnName_c *this)

{
  byte bVar1;
  
  bVar1 = *(byte *)(*(int *)(this + 0x428) + 0x392c);
  if (bVar1 == 1) {
    this[0x558] = (dScnName_c)0x2d;
    this[0x554] = (dScnName_c)0xd;
    return;
  }
  if (bVar1 == 0) {
    return;
  }
  if (3 < bVar1) {
    return;
  }
  this[0x1bb6] = (dScnName_c)0x3;
  this[0x554] = (dScnName_c)0x5;
  return;
}


/* __thiscall dScnName_c::ResetWait(void) */

void __thiscall dScnName_c::ResetWait(dScnName_c *this)

{
  if (this[0x558] != (dScnName_c)0x0) {
    this[0x558] = (dScnName_c)((char)this[0x558] + -1);
    return;
  }
  *mDoRst::mResetData = 1;
  return;
}


/* __thiscall dScnName_c::FileSelectClose(void) */

void __thiscall dScnName_c::FileSelectClose(dScnName_c *this)

{
  byte bVar1;
  undefined8 uVar2;
  
  uVar2 = dFile_select_c::_close(*(dFile_select_c **)(this + 0x428));
  if (((uint)((ulonglong)uVar2 >> 0x20) & 0xff) == 1) {
    bVar1 = *(byte *)(*(int *)(this + 0x428) + 0x392c);
    if (bVar1 == 2) {
      if (*(short *)(this + 8) == 0xd) {
        dMenu_save_c::initialize(*(dMenu_save_c **)(this + 0x430));
        *(undefined *)(*(int *)(this + 0x430) + 0x53c) = 1;
        *(undefined *)(*(int *)(this + 0x430) + 0x53d) =
             *(undefined *)(*(int *)(this + 0x428) + 0x392f);
        if (*(char *)(*(int *)(this + 0x428) + 0x392f) == '\x02') {
          dMenu_save_c::initializeEx(*(dMenu_save_c **)(this + 0x430));
        }
        this[0x554] = (dScnName_c)0xa;
        this[0x557] = (dScnName_c)0x3;
      }
      else {
        this[0x55d] = (dScnName_c)0x0;
        dMCloth_c::init(*(dMCloth_c **)(this + 0x420),(EVP_PKEY_CTX *)uVar2);
        this[0x554] = (dScnName_c)0x0;
        this[0x556] = (dScnName_c)0x0;
        this[0x557] = (dScnName_c)0x0;
      }
      dMCloth_c::alpha_out(*(dMCloth_c **)(this + 0x420));
    }
    else {
      if (bVar1 < 2) {
        if (bVar1 != 0) {
          if (this[0x1bb9] == (dScnName_c)0x0) {
            MSL_C.PPCEABI.bare.H::strcpy((char *)(*(int *)(this + 0x424) + 0x2ad0),"");
          }
          else {
            MSL_C.PPCEABI.bare.H::strcpy
                      ((char *)(*(int *)(this + 0x424) + 0x2ad0),
                       &d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mInfo.mPlayerName);
          }
          dName_c::initial(*(dName_c **)(this + 0x424));
          this[0x554] = (dScnName_c)0x6;
          this[0x555] = (dScnName_c)0x0;
          this[0x557] = (dScnName_c)0x2;
        }
      }
      else {
        if (bVar1 < 4) {
          dMCloth_c::alpha_out(*(dMCloth_c **)(this + 0x420));
          dMenu_save_c::initialize(*(dMenu_save_c **)(this + 0x430));
          this[0x554] = (dScnName_c)0xa;
          this[0x557] = (dScnName_c)0x3;
        }
      }
    }
  }
  return;
}


/* __thiscall dScnName_c::FileSelectDraw(void) */

void __thiscall dScnName_c::FileSelectDraw(dScnName_c *this)

{
  dFile_select_c::_draw(*(dFile_select_c **)(this + 0x428));
  return;
}


/* __thiscall dScnName_c::NameInOpen(void) */

void __thiscall dScnName_c::NameInOpen(dScnName_c *this)

{
  Runtime.PPCEABI.H::__ptmf_scall
            ((PTMF *)(&d_s_name::NameOpenProc + (uint)(byte)this[0x555] * 3),this,&DAT_80390000);
  return;
}


/* __thiscall dScnName_c::NameOpenMain(void) */

void __thiscall dScnName_c::NameOpenMain(dScnName_c *this)

{
  char cVar1;
  
  cVar1 = dName_c::_open(*(dName_c **)(this + 0x424));
  if (cVar1 == '\x01') {
    this[0x1bb6] = (dScnName_c)0x0;
    this[0x554] = (dScnName_c)0x7;
  }
  return;
}


/* __thiscall dScnName_c::NameOpenWait(void) */

void __thiscall dScnName_c::NameOpenWait(dScnName_c *this)

{
  return;
}


/* __thiscall dScnName_c::NameInMain(void) */

void __thiscall dScnName_c::NameInMain(dScnName_c *this)

{
  dName_c::_move(*(dName_c **)(this + 0x424));
  if (*(char *)(*(int *)(this + 0x424) + 0x290b) == '\x01') {
    if (this[0x1bb9] == (dScnName_c)0x0) {
      dSv_info_c::init(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo);
      dComIfG_play_c::itemInit(&d_com_inf_game::g_dComIfG_gameInfo.mPlay);
    }
    MSL_C.PPCEABI.bare.H::strcpy
              (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mInfo.mPlayerName,
               (char *)(*(int *)(this + 0x424) + 0x2a5c));
    this[0x55f] = (dScnName_c)0x1;
    this[0x554] = (dScnName_c)0x9;
  }
  else {
    if (*(char *)(*(int *)(this + 0x424) + 0x290b) == '\x02') {
      this[0x1bb6] = (dScnName_c)0x3;
      this[0x554] = (dScnName_c)0x8;
    }
  }
  return;
}


/* __thiscall dScnName_c::NameInClose(void) */

void __thiscall dScnName_c::NameInClose(dScnName_c *this)

{
  char cVar1;
  
  cVar1 = dName_c::_close(*(dName_c **)(this + 0x424));
  if (cVar1 == '\x01') {
    dFile_select_c::initial(*(dFile_select_c **)(this + 0x428));
    this[0x554] = (dScnName_c)0x3;
    this[0x555] = (dScnName_c)0x0;
    this[0x557] = (dScnName_c)0x1;
  }
  return;
}


/* __thiscall dScnName_c::NameInDraw(void) */

void __thiscall dScnName_c::NameInDraw(dScnName_c *this)

{
  dName_c::_draw(*(dName_c **)(this + 0x424));
  return;
}


/* __thiscall dScnName_c::ShopDemoDataLoad(void) */

void __thiscall dScnName_c::ShopDemoDataLoad(dScnName_c *this)

{
  undefined4 uVar1;
  
  uVar1 = mDoDvdThd_toMainRam_c::create("/res/ShopDemo/zelda_save.bin",0,(JKRHeap *)0x0);
  *(undefined4 *)(this + 0x410) = uVar1;
  this[0x554] = (dScnName_c)0xf;
  return;
}


/* __thiscall dScnName_c::ShopDemoDataSet(void) */

void __thiscall dScnName_c::ShopDemoDataSet(dScnName_c *this)

{
  int iVar1;
  
  if (*(char *)(*(int *)(this + 0x410) + 0xc) != '\0') {
    copy_bytes((byte *)(this + 0x560),(byte *)(*(int *)(*(int *)(this + 0x410) + 0x1c) + 8),0x1650);
    iVar1 = *(int *)(this + 0x410);
    if (iVar1 != 0) {
      (**(code **)(*(int *)(iVar1 + 0x10) + 8))(iVar1,1);
    }
    this[0x554] = (dScnName_c)0x1;
    this[0x557] = (dScnName_c)0x4;
  }
  return;
}


/* __thiscall dScnName_c::SaveOpen(void) */

void __thiscall dScnName_c::SaveOpen(dScnName_c *this)

{
  char cVar1;
  
  if (this[0x558] == (dScnName_c)0x0) {
    cVar1 = dMenu_save_c::_open(*(dMenu_save_c **)(this + 0x430));
    if (cVar1 == '\x01') {
      this[0x1bb6] = (dScnName_c)0x1;
      *(dScnName_c *)(*(int *)(this + 0x428) + 0x3936) = this[0x1bb6];
      this[0x554] = (dScnName_c)0xb;
    }
  }
  else {
    this[0x558] = (dScnName_c)((char)this[0x558] + -1);
  }
  return;
}


/* __thiscall dScnName_c::SaveMain(void) */

void __thiscall dScnName_c::SaveMain(dScnName_c *this)

{
  dMenu_save_c dVar1;
  
  dVar1 = (*(dMenu_save_c **)(this + 0x430))[0x531];
  if (dVar1 == (dMenu_save_c)0x3) {
    this[0x1bb6] = (dScnName_c)0x3;
    this[0x554] = (dScnName_c)0xc;
  }
  else {
    if ((((byte)dVar1 < 3) && (1 < (byte)dVar1)) &&
       (dMenu_save_c::_move(*(dMenu_save_c **)(this + 0x430)),
       *(char *)(*(int *)(this + 0x430) + 0x538) == '\0')) {
      this[0x558] = (dScnName_c)0x2d;
      this[0x554] = (dScnName_c)0xd;
    }
  }
  return;
}


/* __thiscall dScnName_c::SaveClose(void) */

void __thiscall dScnName_c::SaveClose(dScnName_c *this)

{
  char cVar1;
  
  cVar1 = dMenu_save_c::_close(*(dMenu_save_c **)(this + 0x430));
  if (cVar1 == '\x01') {
    this[0x554] = (dScnName_c)0x1;
    this[0x557] = (dScnName_c)0x4;
  }
  return;
}


/* __thiscall dScnName_c::SaveDraw(void) */

void __thiscall dScnName_c::SaveDraw(dScnName_c *this)

{
  dMenu_save_c::_draw2(*(dMenu_save_c **)(this + 0x430));
  return;
}


/* __thiscall dScnName_c::NoneDraw(void) */

void __thiscall dScnName_c::NoneDraw(dScnName_c *this)

{
  return;
}


/* __thiscall dScnName_c::changeGameScene(void) */

void __thiscall dScnName_c::changeGameScene(dScnName_c *this)

{
  undefined2 uVar1;
  int iVar2;
  
  iVar2 = f_op_overlap_mng::fopOvlpM_IsPeek();
  if (iVar2 == 0) {
    d_com_inf_game::dComIfGs_gameStart();
    uVar1 = 7;
    if (this[0x55f] != (dScnName_c)0x0) {
      uVar1 = 0xe;
    }
    iVar2 = f_op_scene_mng::fopScnM_ChangeReq(this,uVar1,0,5);
    if (iVar2 != 0) {
      d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mDanBit.field_0x0 = -1;
      d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mRestart.mLinkRestartParameters = 0;
      m_Do_audio::mDoAud_setSceneName
                (0x803c9d48,
                 (int)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNextStage.parent.mStartCode,
                 (int)(char)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNextStage.parent.mLayerNo);
    }
  }
  return;
}


namespace d_s_name {

/* __stdcall dScnName_Draw(dScnName_c *) */

void dScnName_Draw(dScnName_c *param_1)

{
  ::dScnName_c::draw(param_1);
  return;
}


/* __stdcall dScnName_Execute(dScnName_c *) */

void dScnName_Execute(dScnName_c *param_1)

{
  ::dScnName_c::execute(param_1);
  return;
}


/* __stdcall dScnName_IsDelete(dScnName_c *) */

undefined4 dScnName_IsDelete(void)

{
  return 1;
}


/* __stdcall dScnName_Delete(dScnName_c *) */

undefined4 dScnName_Delete(dScnName_c *param_1)

{
  ::dScnName_c::_dScnName_c(param_1);
  return 1;
}


/* __stdcall dScnName_Create(scene_class *) */

void dScnName_Create(dScnName_c *param_1)

{
  if (param_1 != (dScnName_c *)0x0) {
    *(undefined ***)(param_1 + 0x414) = &dDlst_base_c::__vt;
    *(undefined1 **)(param_1 + 0x414) = &::dDlst_BTICN_c::__vt;
    *(undefined ***)(param_1 + 0x41c) = &dDlst_base_c::__vt;
    *(undefined1 **)(param_1 + 0x41c) = &::dDlst_FLSEL_CLOTH_c::__vt;
  }
  ::dScnName_c::create(param_1);
  return;
}

}

/* __thiscall dDlst_BTICN_c::draw(void) */

void __thiscall dDlst_BTICN_c::draw(dDlst_BTICN_c *this)

{
  J2DOrthoGraph *pCtx;
  
  pCtx = d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph;
  (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph)->parent).vtbl)->setPort)
            (d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph);
  J2DScreen::draw(*(J2DScreen **)(this + 4),d_s_name::_4322,d_s_name::_4322,&pCtx->parent);
  return;
}


/* __thiscall dDlst_FLSEL_CLOTH_c::draw(void) */

void __thiscall dDlst_FLSEL_CLOTH_c::draw(dDlst_FLSEL_CLOTH_c *this)

{
  _GXColor local_54;
  _GXColor local_50;
  _GXColor local_4c;
  MTX44 MStack72;
  
  mtx::C_MTXPerspective
            ((double)d_s_name::_5548,
             (double)(((d_com_inf_game::g_dComIfG_gameInfo.field_0x5cfc)->mWidth /
                      (d_com_inf_game::g_dComIfG_gameInfo.field_0x5cfc)->mHeight) *
                     f_ap_game::g_HIO.aspectRatio),(double)d_s_name::_4323,(double)d_s_name::_5549,
             &MStack72);
  gx::GXSetProjection(&MStack72,GX_PERSPECTIVE);
  local_54 = d_s_name::_5533;
  local_50 = d_s_name::_5531;
  local_4c = d_s_name::_5531;
  dMCloth_c::draw(*(dMCloth_c **)(this + 4),d_s_name::_4322,&local_4c,&local_54,'\0');
  (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph)->parent).vtbl)->setPort)();
  return;
}


/* __thiscall dDlst_FLSEL_CLOTH_c::~dDlst_FLSEL_CLOTH_c(void) */

void __thiscall dDlst_FLSEL_CLOTH_c::_dDlst_FLSEL_CLOTH_c(dDlst_FLSEL_CLOTH_c *this)

{
  short in_r4;
  
  if (this != (dDlst_FLSEL_CLOTH_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dDlst_FLSEL_CLOTH_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dDlst_BTICN_c::~dDlst_BTICN_c(void) */

void __thiscall dDlst_BTICN_c::_dDlst_BTICN_c(dDlst_BTICN_c *this)

{
  short in_r4;
  
  if (this != (dDlst_BTICN_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dDlst_BTICN_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dSn_HIO_c::~dSn_HIO_c(void) */

void __thiscall dSn_HIO_c::_dSn_HIO_c(dSn_HIO_c *this)

{
  short in_r4;
  
  if ((this != (dSn_HIO_c *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


namespace d_s_name {

void __sinit_d_s_name_cpp(void)

{
  ::dSn_HIO_c::dSn_HIO_c((dSn_HIO_c *)&g_snHIO);
  Runtime.PPCEABI.H::__register_global_object();
  MainProc = _4462;
  DAT_80394200 = DAT_80394140;
  DAT_80394204 = DAT_80394144;
  DAT_80394208 = _4463;
  DAT_8039420c = DAT_8039414c;
  DAT_80394210 = PTR_NoteOpen_80394150;
  DAT_80394214 = _4464;
  DAT_80394218 = DAT_80394158;
  DAT_8039421c = PTR_NoteOpenWait_8039415c;
  DAT_80394220 = _4465;
  DAT_80394224 = DAT_80394164;
  DAT_80394228 = PTR_FileSelectOpen_80394168;
  DAT_8039422c = _4466;
  DAT_80394230 = DAT_80394170;
  DAT_80394234 = PTR_FileSelectMain_80394174;
  DAT_80394238 = _4467;
  DAT_8039423c = DAT_8039417c;
  DAT_80394240 = PTR_FileSelectClose_80394180;
  DAT_80394244 = _4468;
  DAT_80394248 = DAT_80394188;
  DAT_8039424c = PTR_NameInOpen_8039418c;
  DAT_80394250 = _4469;
  DAT_80394254 = DAT_80394194;
  DAT_80394258 = PTR_NameInMain_80394198;
  DAT_8039425c = _4470;
  DAT_80394260 = DAT_803941a0;
  DAT_80394264 = PTR_NameInClose_803941a4;
  DAT_80394268 = _4471;
  DAT_8039426c = DAT_803941ac;
  DAT_80394270 = PTR_changeGameScene_803941b0;
  DAT_80394274 = _4472;
  DAT_80394278 = DAT_803941b8;
  DAT_8039427c = PTR_SaveOpen_803941bc;
  DAT_80394280 = _4473;
  DAT_80394284 = DAT_803941c4;
  DAT_80394288 = PTR_SaveMain_803941c8;
  DAT_8039428c = _4474;
  DAT_80394290 = DAT_803941d0;
  DAT_80394294 = PTR_SaveClose_803941d4;
  DAT_80394298 = _4475;
  DAT_8039429c = DAT_803941dc;
  DAT_803942a0 = PTR_ResetWait_803941e0;
  DAT_803942a4 = _4476;
  DAT_803942a8 = DAT_803941e8;
  DAT_803942ac = PTR_ShopDemoDataLoad_803941ec;
  DAT_803942b0 = _4477;
  DAT_803942b4 = DAT_803941f4;
  DAT_803942b8 = PTR_ShopDemoDataSet_803941f8;
  MemCardCheckProc = _4478;
  DAT_8039438c = DAT_803942c0;
  DAT_80394390 = PTR_MemCardStatCheck_803942c4;
  DAT_80394394 = _4479;
  DAT_80394398 = DAT_803942cc;
  DAT_8039439c = PTR_MemCardLoadWait_803942d0;
  DAT_803943a0 = _4480;
  DAT_803943a4 = DAT_803942d8;
  DAT_803943a8 = PTR_MemCardErrMsgWaitKey_803942dc;
  DAT_803943ac = _4481;
  DAT_803943b0 = DAT_803942e4;
  DAT_803943b4 = PTR_MemCardErrMsgWaitKey2_803942e8;
  DAT_803943b8 = _4482;
  DAT_803943bc = DAT_803942f0;
  DAT_803943c0 = PTR_MemCardErrMsgWaitNoSaveSel_803942f4;
  DAT_803943c4 = _4483;
  DAT_803943c8 = DAT_803942fc;
  DAT_803943cc = PTR_MemCardErrMsgWaitFormatSel_80394300;
  DAT_803943d0 = _4484;
  DAT_803943d4 = DAT_80394308;
  DAT_803943d8 = PTR_MemCardErrMsgWaitFormatSel2_8039430c;
  DAT_803943dc = _4485;
  DAT_803943e0 = DAT_80394314;
  DAT_803943e4 = PTR_MemCardFormat_80394318;
  DAT_803943e8 = _4486;
  DAT_803943ec = DAT_80394320;
  DAT_803943f0 = PTR_MemCardFormatCheck_80394324;
  DAT_803943f4 = _4487;
  DAT_803943f8 = DAT_8039432c;
  DAT_803943fc = PTR_MemCardMakeGameFileSel_80394330;
  DAT_80394400 = _4488;
  DAT_80394404 = DAT_80394338;
  DAT_80394408 = PTR_MemCardMakeGameFile_8039433c;
  DAT_8039440c = _4489;
  DAT_80394410 = DAT_80394344;
  DAT_80394414 = PTR_MemCardMakeGameFileCheck_80394348;
  DAT_80394418 = _4490;
  DAT_8039441c = DAT_80394350;
  DAT_80394420 = PTR_MemCardGotoFileSelect_80394354;
  DAT_80394424 = _4491;
  DAT_80394428 = DAT_8039435c;
  DAT_8039442c = PTR_MemCardGotoIPLSelect_80394360;
  DAT_80394430 = _4492;
  DAT_80394434 = DAT_80394368;
  DAT_80394438 = PTR_MemCardGotoIPL_8039436c;
  DAT_8039443c = _4493;
  DAT_80394440 = DAT_80394374;
  DAT_80394444 = PTR_MemCardCheckDbg_80394378;
  DAT_80394448 = _4494;
  DAT_8039444c = DAT_80394380;
  DAT_80394450 = PTR_MemCardCheckDbgWait_80394384;
  NameOpenProc = _4495;
  DAT_80394470 = DAT_80394458;
  DAT_80394474 = PTR_NameOpenMain_8039445c;
  DAT_80394478 = _4496;
  DAT_8039447c = DAT_80394464;
  DAT_80394480 = PTR_NameOpenWait_80394468;
  FileSelOpenProc = _4497;
  DAT_803944a0 = DAT_80394488;
  DAT_803944a4 = PTR_FileSelOpenMain_8039448c;
  DAT_803944a8 = _4498;
  DAT_803944ac = DAT_80394494;
  DAT_803944b0 = PTR_FileselOpenWait_80394498;
  DrawProc = _4499;
  DAT_803944f4 = DAT_803944b8;
  DAT_803944f8 = PTR_FileErrorDraw_803944bc;
  DAT_803944fc = _4500;
  DAT_80394500 = DAT_803944c4;
  DAT_80394504 = PTR_FileSelectDraw_803944c8;
  DAT_80394508 = _4501;
  DAT_8039450c = DAT_803944d0;
  DAT_80394510 = PTR_NameInDraw_803944d4;
  DAT_80394514 = _4502;
  DAT_80394518 = DAT_803944dc;
  DAT_8039451c = PTR_SaveDraw_803944e0;
  DAT_80394520 = _4503;
  DAT_80394524 = DAT_803944e8;
  DAT_80394528 = PTR_NoneDraw_803944ec;
  return;
}

