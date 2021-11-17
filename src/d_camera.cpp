#include <d_camera.h>
#include <d_camera.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <d_drawlist.h>
#include <d_spline_path.h>
#include <d_cam_param.h>
#include <f_op_camera_mng.h>
#include <JKernel/JKRHeap.h>
#include <SComponent/c_math.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <d_com_static.h>
#include <SComponent/c_angle.h>
#include <SComponent/c_xyz.h>
#include <d_bg_s.h>
#include <SComponent/c_bg_s_lin_chk.h>
#include <SComponent/c_bg_s.h>
#include <SComponent/c_bg_s_chk.h>
#include <d_attention.h>
#include <mtx/vec.h>
#include <d_demo.h>
#include <Runtime.PPCEABI.H/ptmf.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <f_pc_searcher.h>
#include <f_op_actor_iter.h>
#include <d_com_inf_game.h>
#include <m_Do_lib.h>
#include <m_Do_mtx.h>
#include <mtx/mtxvec.h>
#include <SComponent/c_bg_s_gnd_chk.h>
#include <d_bg_s_lin_chk.h>
#include <d_cc_mass_s.h>
#include <SComponent/c_m3d.h>
#include <SComponent/c_m3d_g_sph.h>
#include <d_cc_uty.h>
#include <d_a_sea.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <d_door.h>
#include <d_a_himo2.h>
#include <d_ev_camera.h>
#include <d_vibration.h>
#include <SComponent/c_lib.h>
#include <d_cc_s.h>
#include <d_event_manager.h>
#include <m_Do_graphic.h>
#include <mtx/mtx.h>
#include <d_a_grid.h>
#include <mtx/mtx44.h>
#include <f_pc_leaf.h>
#include <f_op_overlap_mng.h>
#include <d_map.h>
#include <f_op_actor_mng.h>
#include <d_com_lib_game.h>
#include <cXyz.h>
#include <cAngle.h>
#include <dCamera_c/BG.h>
#include <dBgS_CamGndChk.h>
#include <dCamera_c/@class$4017d_camera_cpp.h>
#include <dBgS_CamLinChk_NorWtr.h>
#include <d2DBSplinePath.h>
#include <dCamParam_c.h>
#include <daPy_py_c.h>
#include <dCamForcusLine.h>
#include <dBgS_CamSphChk.h>
#include <Demangler/dBgS_SphChk.h>
#include <dBgS_CamGndChk_Wtr.h>
#include <dCamera_c.h>
#include <@unnamed@d_camera_cpp@.h>
#include <cSAngle.h>
#include <dBgS_CamLinChk.h>
#include <cBgS.h>


namespace d_camera {
undefined4 ofan$9214;
undefined4 opixy$9221;
undefined4 p$13482;
undefined4 p$13498;
undefined p$14128;
undefined p$14143;
undefined4 prev_hit_type$8381;
undefined1 init$8382;
undefined4 prev_plat1$8384;
undefined1 init$8385;
undefined4 prev_plat2$8387;
undefined1 init$8388;
undefined1 init$9216;
float dfan$9218;
undefined1 init$9219;
undefined1 init$9223;
float dpixy$9225;
undefined1 init$9226;
float SA_FLY$9681;
undefined1 init$9682;
float SA_FLY$12181;
undefined1 init$12182;
undefined1 init$13484;
undefined1 init$13500;
undefined1 init$14130;
undefined1 init$14145;
}

/* __thiscall @unnamed@d_camera_cpp@::limitf(float,
                                             float,
                                             float) */

double __thiscall
@unnamed@d_camera_cpp@::limitf
          (_unnamed_d_camera_cpp_ *this,float param_1,float param_2,float param_3)

{
  double dVar1;
  
  dVar1 = (double)param_1;
  if ((double)param_3 < dVar1) {
    return (double)param_3;
  }
  if ((double)param_2 <= dVar1) {
    return dVar1;
  }
  return (double)param_2;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dCamera_c::dCamera_c(camera_class *) */

void __thiscall dCamera_c::dCamera_c(dCamera_c *this,camera_class *pCamera)

{
  byte bVar1;
  int iVar2;
  ulong uVar3;
  
  Runtime.PPCEABI.H::__construct_array
            (this->field_0xa4,@class$4017d_camera_cpp::_class_4017d_camera_cpp,
             @class$4017d_camera_cpp::__class_4017d_camera_cpp,0x20,2);
  (this->mForcusLine).vtbl = (undefined *)&dDlst_base_c::__vt;
  (this->mForcusLine).vtbl = (undefined *)&dDlst_effectLine_c::__vt;
  cM_rnd_c::init(&(this->mForcusLine).mRnd,100,100,100);
  BG::BG(&this->mBG);
  (this->mSpline2DPath).vtbl = &d2DBSplinePath::__vt;
  d2DBSplinePath::Init(&this->mSpline2DPath,0,0);
  dCamSetup_c::dCamSetup_c(&this->mCamSetup);
  dCamParam_c::dCamParam_c(&this->mCamParam,0);
  iVar2 = f_op_camera_mng::fopCamM_GetParam(pCamera);
  bVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[iVar2].mCamIdx;
  uVar3 = f_op_camera_mng::fopCamM_GetParam(pCamera);
  iVar2 = f_op_camera_mng::fopCamM_GetParam(pCamera);
  initialize(this,pCamera,
             (fopAc_ac_c *)
             d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor
             [(char)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[iVar2].mCamIdx * 2],uVar3,
             (int)(char)bVar1);
  return;
}


/* __thiscall dCamera_c::~dCamera_c(void) */

void __thiscall dCamera_c::_dCamera_c(dCamera_c *this)

{
  short in_r4;
  
  if (this != (dCamera_c *)0x0) {
    fopAc_ac_c::stopStatus = 0;
    dCamParam_c::_dCamParam_c(&this->mCamParam);
    dCamSetup_c::_dCamSetup_c(&this->mCamSetup);
    if ((this != (dCamera_c *)0xfffffc08) && (this != (dCamera_c *)0xfffffb38)) {
      (this->mSpline2DPath).vtbl = &d2DBSplinePath::__vt;
    }
    BG::_BG(&this->mBG);
    if (this != (dCamera_c *)0xfffffe50) {
      if (this != (dCamera_c *)0xfffffe50) {
        (this->mForcusLine).vtbl = (undefined *)&dDlst_effectLine_c::__vt;
        if (this != (dCamera_c *)0xfffffe50) {
          (this->mForcusLine).vtbl = (undefined *)&dDlst_base_c::__vt;
        }
      }
    }
    Runtime.PPCEABI.H::__destroy_arr
              (this->field_0xa4,@class$4017d_camera_cpp::__class_4017d_camera_cpp,0x20,2);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall dCamera_c::initialize(camera_class *,
                                    fopAc_ac_c *,
                                    unsigned long,
                                    unsigned long) */

void __thiscall
dCamera_c::initialize
          (dCamera_c *this,camera_class *param_1,fopAc_ac_c *param_2,ulong param_3,ulong param_4)

{
  int iVar1;
  uint uVar2;
  stage_stag_info_class *pStagInfo;
  char cVar4;
  short sVar3;
  double dVar5;
  float fVar6;
  cSAngle local_78;
  cSAngle acStack116 [2];
  cSAngle acStack112 [2];
  cSAngle acStack108 [2];
  cSGlobe cStack104;
  cXyz local_60;
  cXyz local_54;
  cXyz local_48;
  cXyz cStack60;
  cXyz local_30;
  cXyz local_24 [2];
  
  this->mpCamera = param_1;
  this->field_0x4 = 1;
  this->field_0x5 = 0;
  this->mpPlayerActor = param_2;
  this->mCameraInfoIdx = param_3;
  this->mPadId = param_4;
  initMonitor(this);
  initPad(this);
  dCamForcusLine::Init(&this->mForcusLine);
  iVar1 = GetCameraTypeFromCameraName(this,"Field");
  this->mCamTypeField = iVar1;
  iVar1 = GetCameraTypeFromCameraName(this,"Event");
  this->mCamTypeEvent = iVar1;
  iVar1 = GetCameraTypeFromCameraName(this,"Water");
  this->mCamTypeWater = iVar1;
  iVar1 = GetCameraTypeFromCameraName(this,"Subject");
  this->field_0x774 = iVar1;
  iVar1 = GetCameraTypeFromCameraName(this,"Boat");
  this->mCamTypeBoat = iVar1;
  iVar1 = GetCameraTypeFromCameraName(this,"BoatBattle");
  this->mCamTypeBoatBattle = iVar1;
  iVar1 = GetCameraTypeFromCameraName(this,"Restrict");
  this->mCamTypeRestrict = iVar1;
  iVar1 = GetCameraTypeFromCameraName(this,"Keep");
  this->mCamTypeKeep = iVar1;
  this->mMapToolType = this->mCamTypeField;
  this->mCurType = this->mCamTypeField;
  this->field_0x524 = 0xff;
  this->field_0x528 = 0;
  *(undefined4 *)&this->field_0x258 = 0;
  this->field_0x254 = 0;
  *(undefined4 *)&this->field_0x248 = 0x85e;
  *(undefined4 *)&this->field_0x24c = 0x828;
  *(undefined4 *)&this->field_0x250 = 0x381b;
  this->mCurMode = 0;
  this->field_0x144 = 1;
  this->field_0x514 = 0;
  this->field_0x14c = d_camera::0_0;
  this->mEventFlags = 0;
  (this->field_0x148).v = cSAngle::_0;
  *(undefined4 *)&this->field_0x7c = 0;
  fVar6 = SComponent::cM_rndFX(d_camera::_5124);
  uVar2 = Runtime.PPCEABI.H::__cvt_fp2unsigned((double)fVar6);
  this->field_0x80 = uVar2;
  *(float *)&this->field_0x64 = d_camera::1_0;
  fVar6 = d_camera::0_0;
  *(float *)&this->field_0x5f4 = d_camera::0_0;
  this->field_0x5f8 = fVar6;
  this->field_0x5fc = 0;
  *(undefined4 *)&this->field_0x600 = 0xffffffff;
  pStagInfo = (stage_stag_info_class *)
              (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)()
  ;
  if ((((pStagInfo != (stage_stag_info_class *)0x0) && (pStagInfo->mCameraMapToolID != 0xffffffff))
      && (iVar1 = GetCameraTypeFromMapToolID(this,(uint)pStagInfo->mCameraMapToolID,-1),
         iVar1 != 0xff)) && (cVar4 = Chtyp(this,iVar1), cVar4 != '\0')) {
    this->mMapToolType = iVar1;
  }
  this->mCurStyle = (int)types[this->mCurType].mStyles[this->mCurMode];
  this->field_0x130 = -1;
  this->mStageMapToolCameraIdx = 0xff;
  this->field_0xe8 = -1;
  this->field_0x40c = -1;
  this->field_0x410 = -1;
  this->mStaffIdx = -1;
  this->field_0x404 = -1;
  this->mRoomNo = -1;
  fVar6 = d_camera::_5126;
  *(float *)&this->field_0x318 = d_camera::_5126;
  *(float *)&this->field_0x310 = fVar6;
  (this->mBG).field_0x58 = fVar6;
  *(uint *)&(this->mBG).field_0x54 = *(uint *)&(this->mBG).field_0x54 & 0xfffffffe;
  *(uint *)&(this->mBG).field_0x54 = *(uint *)&(this->mBG).field_0x54 | 2;
  this->field_0x31d = 0;
  *(undefined *)&this->field_0x31c = 0;
  *(float *)&this->field_0x32c = ::cXyz::Zero.x;
  *(float *)&this->field_0x330 = ::cXyz::Zero.y;
  *(float *)&this->field_0x334 = ::cXyz::Zero.z;
  *(undefined4 *)&this->field_0x320 = *(undefined4 *)&this->field_0x32c;
  *(undefined4 *)&this->field_0x324 = *(undefined4 *)&this->field_0x330;
  *(undefined4 *)&this->field_0x328 = *(undefined4 *)&this->field_0x334;
  *(undefined4 *)&this->field_0x33c = 0;
  *(short *)&this->field_0x33a = cSAngle::_0;
  *(undefined2 *)&this->field_0x338 = *(undefined2 *)&this->field_0x33a;
  this->field_0x350 = 0;
  *(undefined4 *)&this->field_0x364 = 0;
  *(float *)&this->field_0x368 = d_camera::0_0;
  *(float *)&this->field_0x354 = fVar6;
  this->mRoomMapToolCameraIdx = 0xff;
  *(float *)&this->field_0x608 = (this->mCamSetup).mBGChk.field_0x3c;
  iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                    (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"sea");
  if (iVar1 == 0) {
    *(undefined *)&this->field_0x780 = 1;
  }
  else {
    *(undefined *)&this->field_0x780 = 0;
  }
  iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                    (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"kaze");
  if (iVar1 == 0) {
    *(undefined *)&this->field_0x788 = 1;
  }
  else {
    *(undefined *)&this->field_0x788 = 0;
  }
  iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                    (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"M_Dai");
  if (iVar1 == 0) {
    *(undefined *)&this->field_0x789 = 1;
  }
  else {
    *(undefined *)&this->field_0x789 = 0;
  }
  iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                    (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"kazeB");
  if (iVar1 == 0) {
    *(undefined *)&this->field_0x78b = 1;
  }
  else {
    *(undefined *)&this->field_0x78b = 0;
  }
  iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                    (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"GanonK");
  if (iVar1 == 0) {
    *(undefined *)&this->field_0x784 = 1;
  }
  else {
    *(undefined *)&this->field_0x784 = 0;
  }
  iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                    (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"GTower");
  if (iVar1 == 0) {
    *(undefined *)&this->field_0x785 = 1;
  }
  else {
    *(undefined *)&this->field_0x785 = 0;
  }
  iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                    (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Asoko");
  if (((iVar1 == 0) ||
      (iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                         (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Abship"),
      iVar1 == 0)) ||
     (iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                        (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"PShip"),
     iVar1 == 0)) {
    *(undefined *)&this->field_0x781 = 1;
  }
  else {
    *(undefined *)&this->field_0x781 = 0;
  }
  iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                    (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Obshop");
  if (iVar1 == 0) {
    *(undefined *)&this->field_0x782 = 1;
  }
  else {
    *(undefined *)&this->field_0x782 = 0;
  }
  iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                    (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"A_umikz");
  if (iVar1 == 0) {
    *(undefined *)&this->field_0x783 = 1;
  }
  else {
    *(undefined *)&this->field_0x783 = 0;
  }
  this->field_0x534 = 0;
  this->field_0x536 = 0x180;
  if (*(char *)&this->field_0x781 == '\0') {
    if (*(char *)&this->field_0x782 == '\0') {
      if (*(char *)&this->field_0x783 == '\0') {
        this->field_0x530 = 0;
        fVar6 = d_camera::0_0;
        *(float *)&this->field_0x538 = d_camera::0_0;
        *(float *)&this->field_0x540 = fVar6;
      }
      else {
        this->field_0x530 = 3;
        *(float *)&this->field_0x540 = d_camera::1_0;
        dVar5 = (double)daObjPirateship::getShipOffsetY
                                  (&this->field_0x534,&this->field_0x536,d_camera::130_0);
        *(float *)&this->field_0x538 = (float)dVar5;
        *(float *)&this->field_0x538 = *(float *)&this->field_0x538 * *(float *)&this->field_0x540;
      }
    }
    else {
      this->field_0x530 = 2;
      *(float *)&this->field_0x540 = d_camera::_5128;
      dVar5 = (double)daObjPirateship::getShipOffsetY
                                (&this->field_0x534,&this->field_0x536,d_camera::130_0);
      *(float *)&this->field_0x538 = (float)dVar5;
      *(float *)&this->field_0x538 = *(float *)&this->field_0x538 * *(float *)&this->field_0x540;
    }
  }
  else {
    this->field_0x530 = 1;
    *(float *)&this->field_0x540 = d_camera::1_0;
    dVar5 = (double)daObjPirateship::getShipOffsetY
                              (&this->field_0x534,&this->field_0x536,d_camera::130_0);
    *(float *)&this->field_0x538 = (float)dVar5;
    *(float *)&this->field_0x538 = *(float *)&this->field_0x538 * *(float *)&this->field_0x540;
  }
  dCamParam_c::Change(&this->mCamParam,this->mCurStyle);
  attentionPos(&local_30,this,this->mpPlayerActor);
  local_24[0].x = local_30.x;
  local_24[0].y = local_30.y;
  local_24[0].z = local_30.z;
  fVar6 = dCamParam_c::CenterHeight(&this->mCamParam,d_camera::0_0);
  local_24[0].y = local_24[0].y + fVar6;
  cSAngle::cSAngle(acStack108,0);
  directionOf((dCamera_c *)acStack112,(fopAc_ac_c *)this);
  cSGlobe::cSGlobe(&cStack104,d_camera::0_0,acStack108,acStack112);
  cSGlobe::Xyz(&cStack60,&cStack104);
  ::cXyz::operator__(&local_48,local_24,&cStack60);
  (this->field_0x44).x = local_48.x;
  (this->field_0x44).y = local_48.y;
  (this->field_0x44).z = local_48.z;
  (this->mCenter).x = (this->field_0x44).x;
  (this->mCenter).y = (this->field_0x44).y;
  (this->mCenter).z = (this->field_0x44).z;
  directionOf((dCamera_c *)acStack116,(fopAc_ac_c *)this);
  sVar3 = cSAngle::Inv(acStack116);
  cSGlobe::Val(&this->field_0x3c,d_camera::_5129,0,sVar3);
  this->field_0x8 = (this->field_0x3c).mDistance;
  this->field_0xc = (this->field_0x3c).mAngleX.v;
  (this->field_0xe).v = (this->field_0x3c).mAngleY.v;
  cSGlobe::Xyz(&local_54,&this->field_0x3c);
  ::cXyz::operator__(&local_60,&this->field_0x44,&local_54);
  (this->field_0x50).x = local_60.x;
  (this->field_0x50).y = local_60.y;
  (this->field_0x50).z = local_60.z;
  (this->mEye).x = (this->field_0x50).x;
  (this->mEye).y = (this->field_0x50).y;
  (this->mEye).z = (this->field_0x50).z;
  sVar3 = cSAngle::Inv(&this->field_0xe);
  cSAngle::cSAngle(&local_78,sVar3);
  (this->mAngleY).v = local_78;
  fVar6 = d_camera::0_0;
  (this->mUp).x = d_camera::0_0;
  (this->mUp).y = d_camera::1_0;
  (this->mUp).z = fVar6;
  (this->mBank).v = cSAngle::_0;
  this->field_0x5c = (this->mBank).v;
  dVar5 = (double)dCamParam_c::Fovy(&this->mCamParam,fVar6);
  this->mFovY = (float)dVar5;
  this->field_0x60 = (float)dVar5;
  *(undefined *)&this->field_0x220 = 0;
  return;
}


/* __thiscall dCamera_c::Start(void) */

void __thiscall dCamera_c::Start(dCamera_c *this)

{
  this->field_0x4 = 1;
  return;
}


/* __thiscall dCamera_c::Stop(void) */

void __thiscall dCamera_c::Stop(dCamera_c *this)

{
  this->field_0x4 = 0;
  return;
}


/* __thiscall dCamera_c::Stay(void) */

void __thiscall dCamera_c::Stay(dCamera_c *this)

{
  this->field_0x5 = 1;
  return;
}


/* __thiscall dCamera_c::ChangeModeOK(long) */

uint __thiscall dCamera_c::ChangeModeOK(dCamera_c *this,long param_1)

{
  if ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr.mCameraPlay == 0) &&
     ((this->mEventFlags & 0x20000000) == 0)) {
    return (uint)(int)types[this->mCurType].mStyles[param_1] >> 0x1f ^ 1;
  }
  return 0;
}


/* __thiscall dCamera_c::initPad(void) */

void __thiscall dCamera_c::initPad(dCamera_c *this)

{
  float fVar1;
  
  this->mStickMainPosXLast = m_Do_controller_pad::g_mDoCPd_cpadInfo[this->mPadId].mStickMainPosX;
  this->mStickMainPosYLast = m_Do_controller_pad::g_mDoCPd_cpadInfo[this->mPadId].mStickMainPosY;
  this->mStickMainValueLast = m_Do_controller_pad::g_mDoCPd_cpadInfo[this->mPadId].mStickMainValue;
  fVar1 = d_camera::0_0;
  this->mStickMainPosXDelta = d_camera::0_0;
  this->mStickMainPosYDelta = fVar1;
  this->mStickMainValueDelta = fVar1;
  this->mStickCPosXLast = m_Do_controller_pad::g_mDoCPd_cpadInfo[this->mPadId].mStickCPosX;
  this->mStickCPosYLast = m_Do_controller_pad::g_mDoCPd_cpadInfo[this->mPadId].mStickCPosY;
  this->mStickCValueLast = m_Do_controller_pad::g_mDoCPd_cpadInfo[this->mPadId].mStickCValue;
  this->mStickCPosXDelta = fVar1;
  this->mStickCPosYDelta = fVar1;
  this->mStickCValueDelta = fVar1;
  *(undefined4 *)&this->field_0x18c = 0;
  *(undefined4 *)&this->field_0x188 = 0;
  *(undefined4 *)&this->field_0x184 = 0;
  this->mTriggerLeftLast = m_Do_controller_pad::g_mDoCPd_cpadInfo[this->mPadId].mTriggerLeft;
  this->mTriggerLeftDelta = fVar1;
  this->field_0x198 = 0;
  this->field_0x199 = 0;
  this->field_0x19a = 0;
  this->field_0x19b = 0;
  this->mTriggerRightLast = m_Do_controller_pad::g_mDoCPd_cpadInfo[this->mPadId].mTriggerRight;
  this->mTriggerRightDelta = fVar1;
  this->field_0x1a4 = 0;
  this->field_0x1a5 = 0;
  this->field_0x1a6 = 0;
  this->field_0x1a7 = 0;
  this->field_0x1a8 =
       1 - ((m_Do_controller_pad::g_mDoCPd_cpadInfo[this->mPadId].mButton1 >> 6 & 1) == 0);
  this->field_0x1a9 =
       1 - ((m_Do_controller_pad::g_mDoCPd_cpadInfo[this->mPadId].mButton3 >> 6 & 1) == 0);
  this->field_0x1aa =
       1 - ((m_Do_controller_pad::g_mDoCPd_cpadInfo[this->mPadId].mButton1 >> 5 & 1) == 0);
  this->field_0x1ab =
       1 - ((m_Do_controller_pad::g_mDoCPd_cpadInfo[this->mPadId].mButton3 >> 5 & 1) == 0);
  this->field_0x1aa =
       1 - ((m_Do_controller_pad::g_mDoCPd_cpadInfo[this->mPadId].mButton1 >> 5 & 1) == 0);
  this->field_0x1ab =
       1 - ((m_Do_controller_pad::g_mDoCPd_cpadInfo[this->mPadId].mButton3 >> 5 & 1) == 0);
  this->field_0x1ac =
       1 - ((m_Do_controller_pad::g_mDoCPd_cpadInfo[this->mPadId].mButton0 >> 3 & 1) == 0);
  this->field_0x1ad =
       1 - ((m_Do_controller_pad::g_mDoCPd_cpadInfo[this->mPadId].mButton2 >> 3 & 1) == 0);
  this->field_0x1ae = 0;
  return;
}


/* WARNING: Removing unreachable block (ram,0x801626ec) */
/* WARNING: Removing unreachable block (ram,0x801626e4) */
/* WARNING: Removing unreachable block (ram,0x801626f4) */
/* __thiscall dCamera_c::updatePad(void) */

void __thiscall dCamera_c::updatePad(dCamera_c *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  undefined4 uVar5;
  undefined8 in_f29;
  undefined8 in_f30;
  double dVar6;
  undefined8 in_f31;
  double dVar7;
  double dVar8;
  cSAngle local_48;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  if ((this->mEventFlags & 0x1000000) == 0) {
    iVar4 = this->mPadId;
    dVar8 = (double)m_Do_controller_pad::g_mDoCPd_cpadInfo[iVar4].mStickMainPosX;
    dVar6 = (double)m_Do_controller_pad::g_mDoCPd_cpadInfo[iVar4].mStickMainPosY;
    dVar7 = (double)m_Do_controller_pad::g_mDoCPd_cpadInfo[iVar4].mStickMainValue;
  }
  else {
    dVar7 = (double)d_camera::0_0;
    dVar6 = dVar7;
    dVar8 = dVar7;
  }
  cSAngle::cSAngle(&local_48,m_Do_controller_pad::g_mDoCPd_cpadInfo[this->mPadId].mStickMainAngle);
  this->mStickMainPosXDelta = (float)(dVar8 - (double)this->mStickMainPosXLast);
  this->mStickMainPosYDelta = (float)(dVar6 - (double)this->mStickMainPosYLast);
  this->mStickMainValueDelta = (float)(dVar7 - (double)this->mStickMainValueLast);
  this->mStickMainPosXLast = (float)dVar8;
  this->mStickMainPosYLast = (float)dVar6;
  this->mStickMainValueLast = (float)dVar7;
  fVar1 = d_camera::0_0;
  fVar2 = d_camera::0_0;
  fVar3 = d_camera::0_0;
  if ((this->mEventFlags & 0x800000) == 0) {
    iVar4 = this->mPadId;
    fVar1 = m_Do_controller_pad::g_mDoCPd_cpadInfo[iVar4].mStickCPosX;
    fVar2 = m_Do_controller_pad::g_mDoCPd_cpadInfo[iVar4].mStickCValue;
    fVar3 = m_Do_controller_pad::g_mDoCPd_cpadInfo[iVar4].mStickCPosY;
  }
  this->mStickCPosXDelta = fVar1 - this->mStickCPosXLast;
  this->mStickCPosYDelta = fVar3 - this->mStickCPosYLast;
  this->mStickCValueDelta = fVar2 - this->mStickCValueLast;
  this->mStickCPosXLast = fVar1;
  this->mStickCPosYLast = fVar3;
  this->mStickCValueLast = fVar2;
  fVar1 = m_Do_controller_pad::g_mDoCPd_cpadInfo[this->mPadId].mTriggerLeft;
  this->mTriggerLeftDelta = this->mTriggerLeftLast - fVar1;
  this->mTriggerLeftLast = fVar1;
  this->field_0x198 =
       1 - (m_Do_controller_pad::g_mDoCPd_cpadInfo[this->mPadId].mTriggerLeftLevel == 0);
  this->field_0x199 =
       1 - (m_Do_controller_pad::g_mDoCPd_cpadInfo[this->mPadId].mTriggerLeftEdge == 0);
  if (this->mTriggerLeftLast <= (this->mCamSetup).field_0xa0) {
    this->field_0x19b = 0;
    this->field_0x19a = 0;
  }
  else {
    if (this->field_0x19a == 0) {
      this->field_0x19b = 1;
    }
    else {
      this->field_0x19b = 0;
    }
    this->field_0x19a = 1;
  }
  fVar1 = m_Do_controller_pad::g_mDoCPd_cpadInfo[this->mPadId].mTriggerRight;
  this->mTriggerRightDelta = this->mTriggerRightLast - fVar1;
  this->mTriggerRightLast = fVar1;
  this->field_0x1a4 =
       1 - (m_Do_controller_pad::g_mDoCPd_cpadInfo[this->mPadId].mTriggerRightLevel == 0);
  this->field_0x1a5 =
       1 - (m_Do_controller_pad::g_mDoCPd_cpadInfo[this->mPadId].mTriggerRightEdge == 0);
  if (this->mTriggerRightLast <= (this->mCamSetup).field_0xa0) {
    this->field_0x1a7 = 0;
    this->field_0x1a6 = 0;
  }
  else {
    if (this->field_0x1a6 == 0) {
      this->field_0x1a7 = 1;
    }
    else {
      this->field_0x1a7 = 0;
    }
    this->field_0x1a6 = 1;
  }
  this->field_0x1a8 =
       1 - ((m_Do_controller_pad::g_mDoCPd_cpadInfo[this->mPadId].mButton1 >> 6 & 1) == 0);
  this->field_0x1a9 =
       1 - ((m_Do_controller_pad::g_mDoCPd_cpadInfo[this->mPadId].mButton3 >> 6 & 1) == 0);
  this->field_0x1aa =
       1 - ((m_Do_controller_pad::g_mDoCPd_cpadInfo[this->mPadId].mButton1 >> 5 & 1) == 0);
  this->field_0x1ab =
       1 - ((m_Do_controller_pad::g_mDoCPd_cpadInfo[this->mPadId].mButton3 >> 5 & 1) == 0);
  this->field_0x1ac = 1 - (-1 < (char)m_Do_controller_pad::g_mDoCPd_cpadInfo[this->mPadId].mButton1)
  ;
  this->field_0x1ad = 1 - (-1 < (char)m_Do_controller_pad::g_mDoCPd_cpadInfo[this->mPadId].mButton3)
  ;
  this->field_0x1ae = 0;
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  __psq_l0(auStack24,uVar5);
  __psq_l1(auStack24,uVar5);
  __psq_l0(auStack40,uVar5);
  __psq_l1(auStack40,uVar5);
  return;
}


/* __thiscall dCamera_c::initMonitor(void) */

void __thiscall dCamera_c::initMonitor(dCamera_c *this)

{
  float fVar1;
  cXyz local_18;
  
  if (this->mpPlayerActor == (fopAc_ac_c *)0x0) {
    (this->mMonitorPos).x = ::cXyz::Zero.x;
    (this->mMonitorPos).y = ::cXyz::Zero.y;
    (this->mMonitorPos).z = ::cXyz::Zero.z;
  }
  else {
    positionOf(&local_18,this,this->mpPlayerActor);
    (this->mMonitorPos).x = local_18.x;
    (this->mMonitorPos).y = local_18.y;
    (this->mMonitorPos).z = local_18.z;
  }
  fVar1 = d_camera::0_0;
  this->field_0x23c = d_camera::0_0;
  this->field_0x238 = fVar1;
  this->field_0x234 = fVar1;
  this->field_0x240 = 0;
  this->field_0x244 = fVar1;
  return;
}


/* __thiscall dCamera_c::updateMonitor(void) */

void __thiscall dCamera_c::updateMonitor(dCamera_c *this)

{
  double dVar1;
  cXyz local_28;
  cXyz local_1c;
  
  if (this->mpPlayerActor != (fopAc_ac_c *)0x0) {
    positionOf(&local_28,this,this->mpPlayerActor);
    local_1c.x = local_28.x;
    local_1c.y = local_28.y;
    local_1c.z = local_28.z;
    if (this->field_0x31d != 0) {
      dBgS::MoveBgMatrixCrrPos
                (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,&(this->mBG).field_0x74,true,
                 &this->mMonitorPos,(csXyz *)0x0,(csXyz *)0x0);
    }
    dVar1 = (double)dCamMath::xyzHorizontalDistance(&local_1c,&this->mMonitorPos);
    this->field_0x23c = (float)(dVar1 - (double)this->field_0x234);
    this->field_0x238 =
         (float)((double)this->field_0x238 +
                (double)(d_camera::_5310 * (float)(dVar1 - (double)this->field_0x238)));
    this->field_0x234 = (float)dVar1;
    (this->mMonitorPos).x = local_1c.x;
    (this->mMonitorPos).y = local_1c.y;
    (this->mMonitorPos).z = local_1c.z;
    if ((((this->field_0x144 != 0) || (m_Do_controller_pad::g_mDoCPd_cpadInfo[0]._48_2_ != 0)) ||
        (d_camera::_5311 <= this->mStickMainValueLast)) ||
       (d_camera::_5311 <= this->mStickCValueLast)) {
      this->field_0x240 = 0;
    }
    else {
      this->field_0x240 = this->field_0x240 + 1;
    }
    this->field_0x244 = this->field_0x8 - this->field_0x244;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f10 */
/* WARNING: Inlined function: FUN_80328f5c */
/* __thiscall dCamera_c::calcPeepAngle(void) */

void __thiscall dCamera_c::calcPeepAngle(dCamera_c *this)

{
  char cVar2;
  cM3dGPla *pcVar1;
  dCamera_c *in_r4;
  cBgS_PolyPassChk *pcVar3;
  cSAngle local_1d8 [2];
  cSAngle acStack468 [4];
  cSAngle local_1cc [2];
  cSAngle acStack456 [4];
  cSAngle local_1c0 [2];
  cSGlobe cStack444;
  cSGlobe cStack436;
  cXyz local_1ac;
  cXyz local_1a0;
  cXyz local_194;
  cXyz local_188;
  cXyz local_17c;
  cXyz local_170;
  cXyz local_164;
  cXyz local_158;
  cXyz local_14c;
  cXyz local_140;
  cXyz local_134;
  cXyz local_128;
  undefined local_11c [104];
  uint local_b4;
  undefined local_b0 [104];
  uint local_48;
  
  cSAngle::cSAngle(local_1c0,&cSAngle::_0);
  if (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[in_r4->mPadId * 4] & 0x20U) == 0) {
    if (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[in_r4->mPadId * 4] & 0x40U) != 0) {
      local_158.x = d_camera::0_0;
      local_158.y = d_camera::0_0;
      local_164.z = -d_camera::30_0;
      local_164.x = d_camera::_5573;
      local_164.y = d_camera::0_0;
      local_158.z = local_164.z;
      relationalPos(&local_1a0,in_r4,in_r4->mpPlayerActor,&local_158);
      local_170.x = local_1a0.x;
      local_170.y = local_1a0.y;
      local_170.z = local_1a0.z;
      relationalPos(&local_1ac,in_r4,in_r4->mpPlayerActor,&local_164);
      local_17c.x = local_1ac.x;
      local_17c.y = local_1ac.y;
      local_17c.z = local_1ac.z;
      local_11c._0_4_ = (cBgS_PolyPassChk *)0x0;
      local_11c._4_4_ = (cBgS_PolyPassChk *)0x0;
      local_11c[12] = true;
      local_11c._20_2_ = 0xffff;
      local_11c._22_2_ = 0x100;
      local_11c._24_4_ = (cBgW *)0x0;
      local_11c._28_4_ = -1;
      local_11c._16_4_ = &::cBgS_LinChk::__vt;
      local_11c._32_4_ = &PTR_80371fbc;
      local_11c._60_4_ = &::cM3dGLin::__vt;
      ::cBgS_LinChk::ct((cBgS_LinChk *)local_11c);
      pcVar3 = (cBgS_PolyPassChk *)(local_11c + 0x58);
      local_11c[92] = 0;
      local_11c[94] = 0;
      local_11c[95] = 0;
      local_11c[96] = 0;
      local_11c[97] = 0;
      local_11c[98] = 0;
      local_11c._4_4_ = pcVar3;
      if (pcVar3 != (cBgS_PolyPassChk *)0x0) {
        local_11c._4_4_ = (cBgS_PolyPassChk *)(local_11c + 100);
      }
      local_11c[93] = 1;
      local_11c._16_4_ = (undefined **)&dBgS_CamLinChk_NorWtr::__vt;
      local_11c._32_4_ = (undefined **)&DAT_803910b0;
      local_11c._88_4_ = (undefined **)&DAT_803910bc;
      local_11c._100_4_ = (undefined **)&DAT_803910c8;
      local_b4 = 3;
      local_11c._0_4_ = pcVar3;
      cVar2 = lineBGCheck(in_r4,&local_17c,&local_170,(dBgS_LinChk *)local_11c,0x7f);
      if (cVar2 != '\0') {
        pcVar1 = cBgS::GetTriPla((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                                 (uint)local_11c._22_2_,(uint)local_11c._20_2_);
        cSGlobe::cSGlobe(&cStack444,(cXyz *)pcVar1);
        directionOf((dCamera_c *)(acStack468 + 2),(fopAc_ac_c *)in_r4);
        cSAngle::operator__(acStack468,&cStack444.mAngleY);
        cSAngle::operator__(local_1d8,(cSAngle *)&cSAngle::_270);
        local_1c0[0] = local_1d8[0];
      }
      local_11c._88_4_ = &PTR_80371f44;
      local_11c._100_4_ = &PTR_80371f50;
      if (pcVar3 != (cBgS_PolyPassChk *)0x0) {
        local_11c._88_4_ = &::dBgS_Chk::__vt;
        local_11c._100_4_ = &PTR_80371f68;
        if (((undefined *)register0x00000004 != (undefined *)0xb8) &&
           (local_11c._100_4_ = &::dBgS_GrpPassChk::__vt,
           (undefined *)register0x00000004 != (undefined *)0xb8)) {
          local_11c._100_4_ = &::cBgS_GrpPassChk::__vt;
        }
        if ((pcVar3 != (cBgS_PolyPassChk *)0x0) &&
           (local_11c._88_4_ = &::dBgS_PolyPassChk::__vt, pcVar3 != (cBgS_PolyPassChk *)0x0)) {
          local_11c._88_4_ = &::cBgS_PolyPassChk::__vt;
        }
      }
      local_11c._16_4_ = &::cBgS_LinChk::__vt;
      local_11c._60_4_ = &::cM3dGLin::__vt;
      local_11c._32_4_ = &::cBgS_PolyInfo::__vt;
      cBgS_Chk::_cBgS_Chk((cBgS_Chk *)local_11c);
    }
  }
  else {
    local_128.x = d_camera::0_0;
    local_128.y = d_camera::0_0;
    local_134.z = -d_camera::30_0;
    local_134.x = -d_camera::_5573;
    local_134.y = d_camera::0_0;
    local_128.z = local_134.z;
    relationalPos(&local_188,in_r4,in_r4->mpPlayerActor,&local_128);
    local_140.x = local_188.x;
    local_140.y = local_188.y;
    local_140.z = local_188.z;
    relationalPos(&local_194,in_r4,in_r4->mpPlayerActor,&local_134);
    local_14c.x = local_194.x;
    local_14c.y = local_194.y;
    local_14c.z = local_194.z;
    local_b0._0_4_ = (cBgS_PolyPassChk *)0x0;
    local_b0._4_4_ = (cBgS_PolyPassChk *)0x0;
    local_b0[12] = true;
    local_b0._20_2_ = 0xffff;
    local_b0._22_2_ = 0x100;
    local_b0._24_4_ = (cBgW *)0x0;
    local_b0._28_4_ = -1;
    local_b0._16_4_ = &::cBgS_LinChk::__vt;
    local_b0._32_4_ = &PTR_80371fbc;
    local_b0._60_4_ = &::cM3dGLin::__vt;
    ::cBgS_LinChk::ct((cBgS_LinChk *)local_b0);
    pcVar3 = (cBgS_PolyPassChk *)(local_b0 + 0x58);
    local_b0[92] = 0;
    local_b0[94] = 0;
    local_b0[95] = 0;
    local_b0[96] = 0;
    local_b0[97] = 0;
    local_b0[98] = 0;
    local_b0._4_4_ = pcVar3;
    if (pcVar3 != (cBgS_PolyPassChk *)0x0) {
      local_b0._4_4_ = (cBgS_PolyPassChk *)(local_b0 + 100);
    }
    local_b0[93] = 1;
    local_b0._16_4_ = (undefined **)&dBgS_CamLinChk_NorWtr::__vt;
    local_b0._32_4_ = (undefined **)&DAT_803910b0;
    local_b0._88_4_ = (undefined **)&DAT_803910bc;
    local_b0._100_4_ = (undefined **)&DAT_803910c8;
    local_48 = 3;
    local_b0._0_4_ = pcVar3;
    cVar2 = lineBGCheck(in_r4,&local_14c,&local_140,(dBgS_LinChk *)local_b0,0x7f);
    if (cVar2 != '\0') {
      pcVar1 = cBgS::GetTriPla((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                               (uint)local_b0._22_2_,(uint)local_b0._20_2_);
      cSGlobe::cSGlobe(&cStack436,(cXyz *)pcVar1);
      directionOf((dCamera_c *)(acStack456 + 2),(fopAc_ac_c *)in_r4);
      cSAngle::operator__(acStack456,&cStack436.mAngleY);
      cSAngle::operator__(local_1cc,(cSAngle *)&cSAngle::_90);
      local_1c0[0] = local_1cc[0];
    }
    local_b0._88_4_ = &PTR_80371f44;
    local_b0._100_4_ = &PTR_80371f50;
    if (pcVar3 != (cBgS_PolyPassChk *)0x0) {
      local_b0._88_4_ = &::dBgS_Chk::__vt;
      local_b0._100_4_ = &PTR_80371f68;
      if (((undefined *)register0x00000004 != &DAT_0000004c) &&
         (local_b0._100_4_ = &::dBgS_GrpPassChk::__vt,
         (undefined *)register0x00000004 != &DAT_0000004c)) {
        local_b0._100_4_ = &::cBgS_GrpPassChk::__vt;
      }
      if ((pcVar3 != (cBgS_PolyPassChk *)0x0) &&
         (local_b0._88_4_ = &::dBgS_PolyPassChk::__vt, pcVar3 != (cBgS_PolyPassChk *)0x0)) {
        local_b0._88_4_ = &::cBgS_PolyPassChk::__vt;
      }
    }
    local_b0._16_4_ = &::cBgS_LinChk::__vt;
    local_b0._60_4_ = &::cM3dGLin::__vt;
    local_b0._32_4_ = &::cBgS_PolyInfo::__vt;
    cBgS_Chk::_cBgS_Chk((cBgS_Chk *)local_b0);
  }
  cSAngle::cSAngle((cSAngle *)this,local_1c0);
  return;
}


/* __thiscall dBgS_CamLinChk_NorWtr::~dBgS_CamLinChk_NorWtr(void) */

void __thiscall dBgS_CamLinChk_NorWtr::_dBgS_CamLinChk_NorWtr(dBgS_CamLinChk_NorWtr *this)

{
  bool bVar1;
  short in_r4;
  
  bVar1 = this != (dBgS_CamLinChk_NorWtr *)0x0;
  if (bVar1) {
    *(undefined1 **)(this + 0x10) = &__vt;
    *(undefined **)(this + 0x20) = &DAT_803910b0;
    *(undefined **)(this + 0x58) = &DAT_803910bc;
    *(undefined **)(this + 100) = &DAT_803910c8;
    if (bVar1) {
      *(undefined1 **)(this + 0x10) = &dBgS_CamLinChk::__vt;
      *(undefined **)(this + 0x20) = &DAT_803910e0;
      *(undefined **)(this + 0x58) = &DAT_803910ec;
      *(undefined **)(this + 100) = &DAT_803910f8;
      if (bVar1) {
        *(undefined ***)(this + 0x10) = &::dBgS_LinChk::__vt;
        *(undefined **)(this + 0x20) = &DAT_80371f38;
        *(undefined ***)(this + 0x58) = &PTR_80371f44;
        *(undefined ***)(this + 100) = &PTR_80371f50;
        if (this != (dBgS_CamLinChk_NorWtr *)0xffffffa8) {
          *(undefined ***)(this + 0x58) = &::dBgS_Chk::__vt;
          *(undefined ***)(this + 100) = &PTR_80371f68;
          if (this != (dBgS_CamLinChk_NorWtr *)0xffffff9c) {
            *(undefined ***)(this + 100) = &::dBgS_GrpPassChk::__vt;
            if (this != (dBgS_CamLinChk_NorWtr *)0xffffff9c) {
              *(undefined ***)(this + 100) = &::cBgS_GrpPassChk::__vt;
            }
          }
          if ((this != (dBgS_CamLinChk_NorWtr *)0xffffffa8) &&
             (*(undefined ***)(this + 0x58) = &::dBgS_PolyPassChk::__vt,
             this != (dBgS_CamLinChk_NorWtr *)0xffffffa8)) {
            *(undefined ***)(this + 0x58) = &::cBgS_PolyPassChk::__vt;
          }
        }
        if (this != (dBgS_CamLinChk_NorWtr *)0x0) {
          *(undefined ***)(this + 0x10) = &::cBgS_LinChk::__vt;
          *(undefined ***)(this + 0x20) = &PTR_80371fbc;
          if (this != (dBgS_CamLinChk_NorWtr *)0xffffffdc) {
            *(undefined ***)(this + 0x3c) = &::cM3dGLin::__vt;
          }
          if (this != (dBgS_CamLinChk_NorWtr *)0xffffffec) {
            *(undefined ***)(this + 0x20) = &::cBgS_PolyInfo::__vt;
          }
          cBgS_Chk::_cBgS_Chk((cBgS_Chk *)this);
        }
      }
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dBgS_CamLinChk::~dBgS_CamLinChk(void) */

void __thiscall dBgS_CamLinChk::_dBgS_CamLinChk(dBgS_CamLinChk *this)

{
  short in_r4;
  
  if (this != (dBgS_CamLinChk *)0x0) {
    *(undefined1 **)(this + 0x10) = &__vt;
    *(undefined **)(this + 0x20) = &DAT_803910e0;
    *(undefined **)(this + 0x58) = &DAT_803910ec;
    *(undefined **)(this + 100) = &DAT_803910f8;
    if (this != (dBgS_CamLinChk *)0x0) {
      *(undefined ***)(this + 0x10) = &::dBgS_LinChk::__vt;
      *(undefined **)(this + 0x20) = &DAT_80371f38;
      *(undefined ***)(this + 0x58) = &PTR_80371f44;
      *(undefined ***)(this + 100) = &PTR_80371f50;
      if (this != (dBgS_CamLinChk *)0xffffffa8) {
        *(undefined ***)(this + 0x58) = &::dBgS_Chk::__vt;
        *(undefined ***)(this + 100) = &PTR_80371f68;
        if (this != (dBgS_CamLinChk *)0xffffff9c) {
          *(undefined ***)(this + 100) = &::dBgS_GrpPassChk::__vt;
          if (this != (dBgS_CamLinChk *)0xffffff9c) {
            *(undefined ***)(this + 100) = &::cBgS_GrpPassChk::__vt;
          }
        }
        if ((this != (dBgS_CamLinChk *)0xffffffa8) &&
           (*(undefined ***)(this + 0x58) = &::dBgS_PolyPassChk::__vt,
           this != (dBgS_CamLinChk *)0xffffffa8)) {
          *(undefined ***)(this + 0x58) = &::cBgS_PolyPassChk::__vt;
        }
      }
      if (this != (dBgS_CamLinChk *)0x0) {
        *(undefined ***)(this + 0x10) = &::cBgS_LinChk::__vt;
        *(undefined ***)(this + 0x20) = &PTR_80371fbc;
        if (this != (dBgS_CamLinChk *)0xffffffdc) {
          *(undefined ***)(this + 0x3c) = &::cM3dGLin::__vt;
        }
        if (this != (dBgS_CamLinChk *)0xffffffec) {
          *(undefined ***)(this + 0x20) = &::cBgS_PolyInfo::__vt;
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


/* __thiscall dCamera_c::Att(void) */

void __thiscall dCamera_c::Att(dCamera_c *this)

{
  uint uVar1;
  fopAc_ac_c *pfVar2;
  
  if ((this->mpPlayerActor != (fopAc_ac_c *)0x0) && ((this->mEventFlags & 0x2000000) == 0)) {
    uVar1 = dAttention_c::LockonTruth(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAttention);
    if ((uVar1 & 0xff) == 0) {
      pfVar2 = (fopAc_ac_c *)0x0;
    }
    else {
      pfVar2 = dAttention_c::LockonTarget(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAttention,0);
    }
    this->mpLockonTarget = pfVar2;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dCamera_c::checkForceLockTarget(void) */

undefined4 __thiscall dCamera_c::checkForceLockTarget(dCamera_c *this)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  double dVar4;
  double dVar5;
  float fVar6;
  cXyz local_54;
  cXyz local_48;
  cXyz cStack60;
  cXyz cStack48;
  undefined4 local_20;
  uint uStack28;
  undefined4 local_18;
  uint uStack20;
  
  if (this->field_0x130 != -1) {
    uVar2 = GetForceLockOnActor(this);
    *(undefined4 *)&this->field_0x134 = uVar2;
    if (*(int *)&this->field_0x134 != 0) {
      bVar1 = true;
      uVar3 = dAttention_c::LockonTruth(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAttention);
      if (((uVar3 & 0xff) == 0) &&
         ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAttention.mFlags & 0x20000000) == 0)) {
        bVar1 = false;
      }
      if (!bVar1) {
        uStack28 = this->field_0x138 ^ 0x80000000;
        local_20 = 0x43300000;
        uStack20 = (this->mCamSetup).field_0x74 ^ 0x80000000;
        local_18 = 0x43300000;
        if ((float)((double)CONCAT44(0x43300000,uStack28) - d_camera::_5738) <=
            (float)((double)CONCAT44(0x43300000,uStack20) - d_camera::_5738)) {
          positionOf(&cStack48,this,*(fopAc_ac_c **)&this->field_0x134);
          positionOf(&cStack60,this,this->mpPlayerActor);
          ::cXyz::operator__(&local_48,&cStack48,&cStack60);
          local_54.x = local_48.x;
          local_54.y = local_48.y;
          local_54.z = local_48.z;
          fVar6 = mtx::PSVECSquareMag(&local_54);
          dVar5 = (double)fVar6;
          if ((double)d_camera::0_0 < dVar5) {
            dVar4 = 1.0 / SQRT(dVar5);
            dVar4 = d_camera::_5735 * dVar4 * (d_camera::_5736 - dVar5 * dVar4 * dVar4);
            dVar4 = d_camera::_5735 * dVar4 * (d_camera::_5736 - dVar5 * dVar4 * dVar4);
            dVar5 = (double)(float)(dVar5 * d_camera::_5735 * dVar4 *
                                            (d_camera::_5736 - dVar5 * dVar4 * dVar4));
          }
          if (dVar5 <= (double)(this->mCamSetup).field_0x70) {
            return 1;
          }
        }
      }
    }
  }
  return 0;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall dCamera_c::Run(void) */

dCamera_c * __thiscall dCamera_c::Run(dCamera_c *this)

{
  float fVar1;
  ushort uVar2;
  float fVar3;
  bool bVar4;
  uint uVar5;
  char cVar9;
  int iVar6;
  dDemo_camera_c *pdVar7;
  short sVar8;
  long next;
  dCamera_c *pdVar10;
  double dVar11;
  cSAngle local_58 [2];
  cSAngle local_54 [2];
  cSAngle local_50 [2];
  short local_4c;
  cSAngle acStack72 [2];
  cSAngle local_44 [2];
  cSAngle local_40 [2];
  cSAngle acStack60 [2];
  cSAngle acStack56 [2];
  cSAngle acStack52 [2];
  cSAngle local_30;
  cSAngle local_2c;
  cSAngle local_28;
  cSAngle local_24 [8];
  
  pdVar10 = (dCamera_c *)0x0;
  dCamForcusLine::Off(&this->mForcusLine);
  this->mEventFlags = this->mEventFlags & 0xefeb63fe;
  checkSpecialArea(this);
  checkGroundInfo(this);
  if ((this->field_0x530 != 0) && ((this->mEventFlags >> 0x15 & 1) == 0)) {
    if ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr.mCameraPlay == 0) &&
       ((this->mEventFlags & 0x20000000) == 0)) {
      dVar11 = (double)daObjPirateship::getShipOffsetY
                                 (&this->field_0x534,&this->field_0x536,d_camera::130_0);
      fVar1 = (float)(dVar11 * (double)*(float *)&this->field_0x540);
      fVar3 = fVar1 - *(float *)&this->field_0x538;
      if (((this->field_0x530 == 1) && (*(float *)&this->field_0x53c < d_camera::0_0)) &&
         (d_camera::0_0 < fVar3)) {
        this->field_0x254 = this->field_0x254 | 4;
      }
      *(float *)&this->field_0x53c = fVar3;
      *(float *)&this->field_0x538 = fVar1;
      (this->field_0x44).y =
           (this->field_0x44).y - *(float *)&this->field_0x53c * (this->mCamSetup).field_0xb8;
    }
  }
  updateMonitor(this);
  Att(this);
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].field_0x8 =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].field_0x8 &
       0xffffcbff;
  if ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr.mCameraPlay == 0) &&
     ((this->mEventFlags & 0x20000000) == 0)) {
    updatePad(this);
    dCstick_c::Shift(&(this->mCamSetup).mCstick,this->mPadId);
  }
  if (d_com_inf_game::g_dComIfG_gameInfo.field_0x5cda == 8) {
    updatePad(this);
    dCstick_c::Shift(&(this->mCamSetup).mCstick,this->mPadId);
  }
  bVar4 = true;
  uVar5 = dAttention_c::LockonTruth(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAttention);
  if (((uVar5 & 0xff) == 0) &&
     ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAttention.mFlags & 0x20000000) == 0)) {
    bVar4 = false;
  }
  if (bVar4) {
    this->mEventFlags = this->mEventFlags | 0x1000;
  }
  cVar9 = checkForceLockTarget(this);
  if (cVar9 == '\0') {
    this->field_0x130 = -1;
  }
  else {
    this->field_0x138 = this->field_0x138 + 1;
  }
  iVar6 = nextType(this,this->mCurType);
  this->mNextType = iVar6;
  if ((this->mNextType != this->mCurType) &&
     (cVar9 = onTypeChange(this,this->mCurType,this->mNextType), cVar9 != '\0')) {
    this->mCurType = this->mNextType;
  }
  iVar6 = nextMode(this,this->mCurMode);
  this->mNextMode = iVar6;
  next = this->mNextMode;
  if (next != this->mCurMode) {
    if ((-1 < types[this->mCurType].mStyles[next]) &&
       (cVar9 = onModeChange(this,this->mCurMode,next), cVar9 != '\0')) {
      this->mCurMode = this->mNextMode;
    }
  }
  if (types[this->mCurType].mStyles[this->mCurMode] < 0) {
    this->mCurMode = 0;
  }
  sVar8 = types[this->mCurType].mStyles[this->mCurMode];
  if (-1 < sVar8) {
    if ((this->mCurStyle != (int)sVar8) &&
       (cVar9 = onStyleChange(this,this->mCurStyle,(int)sVar8), cVar9 != '\0')) {
      this->mCurStyle = (int)types[this->mCurType].mStyles[this->mCurMode];
      dCamParam_c::Change(&this->mCamParam,this->mCurStyle);
    }
  }
  this->mEventFlags = this->mEventFlags & 0xffffffdf;
  if (this->mCurMode == 0xc) {
    this->mEventFlags = this->mEventFlags | 0x20;
  }
  this->mEventFlags = this->mEventFlags & 0x7fffffff;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].field_0x8 =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].field_0x8 &
       0xffffff7f;
  if ((((this->mCamParam).mpStyle)->mFlag & 4) == 0) {
LAB_801638d8:
    (this->field_0x148).v = cSAngle::_0;
  }
  else {
    if ((((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4] & 0x4000000U) != 0)
       || (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5ccc)[this->mPadId * 4] & 0x40000U) != 0))
    goto LAB_801638d8;
    forwardCheckAngle(&local_28,this);
    cSAngle::operator__(&local_2c,&local_28);
    cSAngle::operator_(&local_30,(this->mCamSetup).mBGChk.field_0x28);
    cSAngle::operator___(&this->field_0x148,&local_30);
  }
  defaultTriming(this);
  *(undefined4 *)&this->field_0x600 = 0xffffffff;
  this->field_0x68 = 9;
  if (((this->mEventFlags & 0x200000) == 0) ||
     (dCamParam_c::styles[this->mCurStyle].mEngineIdx == 0xb)) {
    pdVar7 = dDemo_object_c::getActiveCamera
                       (&(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpDemoMgr)->mDemoObj);
    if (pdVar7 != (dDemo_camera_c *)0x0) {
      if (((this->mCamParam).mpStyle)->mEngineIdx != 0xb) {
        pdVar10 = (dCamera_c *)demoCamera(this,0);
        goto LAB_80163a70;
      }
    }
    pdVar10 = this;
    Runtime.PPCEABI.H::__ptmf_scall
              (engine_tbl + dCamParam_c::styles[(int)(void *)this->mCurStyle].mEngineIdx,this,
               (void *)this->mCurStyle);
    *(int *)&this->field_0x7c = *(int *)&this->field_0x7c + 1;
    this->field_0x80 = this->field_0x80 + 1;
    this->field_0x118 = this->field_0x118 + 1;
    this->field_0x108 = this->field_0x108 + 1;
    this->field_0x11c = this->field_0x11c + 1;
  }
  else {
    iVar6 = this->mPadId;
    if (m_Do_controller_pad::g_mDoCPd_cpadInfo[iVar6].mStickMainValue <= d_camera::_6063) {
      if (m_Do_controller_pad::g_mDoCPd_cpadInfo[iVar6].mStickCValue <= d_camera::_6063) {
        if (*(short *)&m_Do_controller_pad::g_mDoCPd_cpadInfo[iVar6].mButton0 == 0) {
          bVar4 = false;
        }
        else {
          bVar4 = true;
        }
      }
      else {
        bVar4 = true;
      }
    }
    else {
      bVar4 = true;
    }
    if (!bVar4) {
      if (((this->field_0x234 <= d_camera::_6064) && (*(char *)&this->field_0x360 != '\0')) &&
         (*(char *)&this->field_0x31c == '\0')) goto LAB_80163a70;
    }
    this->mEventFlags = this->mEventFlags & 0xffdfffff;
  }
LAB_80163a70:
  if (((uint)pdVar10 & 0xff) == 0) {
    this->field_0x514 = 0;
  }
  if ((this->mEventFlags & 0x400) == 0) {
    cSAngle::operator_(acStack52,d_camera::_5311);
    cSAngle::operator___((cSAngle *)&this->field_0x5c,acStack52);
  }
  shakeCamera(this);
  this->mEventFlags = this->mEventFlags & 0xfff6ff7f;
  uVar2 = ((this->mCamParam).mpStyle)->mFlag;
  if ((uVar2 & 1) == 0) {
    if ((uVar2 & 2) != 0) {
      this->field_0x68 = 0xf;
    }
  }
  else {
    this->field_0x68 = 0x3f;
  }
  if ((((this->mCamParam).mpStyle)->mFlag & 0x400) != 0) {
    this->field_0x68 = this->field_0x68 | 0x40;
  }
  fVar1 = *(float *)&this->field_0x354 + (this->mCamSetup).mBGChk.field_0x0;
  if (fVar1 <= (this->field_0x44).y) {
    (this->mCenter).x = (this->field_0x44).x;
    (this->mCenter).y = (this->field_0x44).y;
    (this->mCenter).z = (this->field_0x44).z;
  }
  else {
    (this->mCenter).x = (this->field_0x44).x;
    (this->mCenter).z = (this->field_0x44).z;
    if ((dCamParam_c::styles[this->mCurStyle].mEngineIdx == 4) &&
       ((this->mEventFlags & 0x10000800) != 0)) {
      this->field_0x68 = this->field_0x68 & 0xfffffff7;
      (this->mCenter).y = (this->field_0x44).y;
    }
    else {
      (this->mCenter).y = fVar1;
    }
  }
  this->mFovY = this->field_0x60;
  (this->mBank).v = this->field_0x5c;
  bumpCheck(this,this->field_0x68);
  cSAngle::cSAngle(acStack56,m_Do_controller_pad::g_mDoCPd_cpadInfo[this->mPadId].mStickMainAngle);
  cSAngle::operator__(acStack60,acStack56);
  cSAngle::cSAngle(local_24,acStack60);
  if (this->mStickMainValueLast < (this->mCamSetup).field_0x88) {
LAB_80163c64:
    *(undefined *)&this->field_0x220 = 0;
  }
  else {
    cSAngle::cSAngle(local_40,(this->mCamSetup).field_0x8c);
    if ((((int)(short)(local_24[0] ^ local_40[0]) >> 1) -
         (int)(short)((local_24[0] ^ local_40[0]) & local_24[0]) < 0) ||
       (cSAngle::cSAngle(local_44,-(this->mCamSetup).field_0x8c),
       ((int)(short)(local_44[0] ^ local_24[0]) >> 1) -
       (int)(short)((local_44[0] ^ local_24[0]) & local_44[0]) < 0)) goto LAB_80163c64;
  }
  if (*(char *)&this->field_0x220 == '\0') {
    sVar8 = cSAngle::Inv(&this->field_0xe);
    cSAngle::cSAngle(local_50,sVar8);
    (this->mAngleY).v = local_50[0];
  }
  else {
    cSAngle::cSAngle(acStack72,m_Do_controller_pad::g_mDoCPd_cpadInfo[this->mPadId].mStickMainAngle)
    ;
    getDMCAngle((dCamera_c *)&local_4c,SUB42(this,0));
    (this->mAngleY).v = local_4c;
  }
  if ((this->mCenter).x == (this->mEye).x) {
    if ((this->mCenter).z == (this->mEye).z) {
      (this->mUp).x = d_camera::_6065;
      (this->mUp).y = d_camera::1_0;
      (this->mUp).z = d_camera::0_0;
      goto LAB_80163d84;
    }
  }
  cSAngle::cSAngle(local_54,d_camera::_6066);
  if ((((int)this->field_0xc >> 0x1f) +
       ((uint)((uint)(int)local_54[0] <= (uint)(int)this->field_0xc) - ((int)local_54[0] >> 0x1f)) &
      0xff) != 0) {
    cSAngle::cSAngle(local_58,d_camera::_6067);
    fVar1 = d_camera::0_0;
    if ((((int)local_58[0] >> 0x1f) +
         ((uint)((uint)(int)this->field_0xc <= (uint)(int)local_58[0]) -
         ((int)this->field_0xc >> 0x1f)) & 0xff) != 0) {
      (this->mUp).x = d_camera::0_0;
      (this->mUp).y = d_camera::1_0;
      (this->mUp).z = fVar1;
      goto LAB_80163d84;
    }
  }
  fVar1 = d_camera::0_0;
  (this->mUp).x = d_camera::0_0;
  (this->mUp).y = d_camera::_1_0;
  (this->mUp).z = fVar1;
LAB_80163d84:
  uVar5 = 0;
  iVar6 = 0;
  do {
    bVar4 = false;
    if ((this->field_0x254 & 1 << uVar5) != 0) {
      if ((*(uint *)&this->field_0x258 & 1 << uVar5) == 0) {
        bVar4 = true;
      }
    }
    if (bVar4) {
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,*(ulong *)(&this->field_0x248 + iVar6),(cXyz *)0x0,0,0,
                 d_camera::1_0,d_camera::1_0,d_camera::_1_0,d_camera::_1_0,0);
    }
    uVar5 = uVar5 + 1;
    iVar6 = iVar6 + 4;
  } while (uVar5 < 3);
  *(int *)&this->field_0x258 = this->field_0x254;
  bVar4 = false;
  this->field_0x254 = 0;
  if (((*(char *)&this->field_0x100 != '\0') && (*(char *)&this->field_0x101 != '\0')) &&
     (*(char *)&this->field_0x102 != '\0')) {
    bVar4 = true;
  }
  if (bVar4) {
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].field_0x8 =
         d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].field_0x8 | 0x10
    ;
  }
  else {
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].field_0x8 =
         d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].field_0x8 &
         0xffffffef;
  }
  if ((this->mEventFlags >> 0x12 & 1) == 0) {
    if (this->field_0x8 < (this->mCamSetup).field_0x48) {
      if ((this->mEventFlags & 0x800) != 0) {
        d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].field_0x8 =
             d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].field_0x8 |
             2;
      }
      if ((this->mEventFlags & 0x10000000) != 0) {
        d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].field_0x8 =
             d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].field_0x8 |
             0x20;
      }
    }
  }
  else {
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].field_0x8 =
         d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].field_0x8 | 2;
  }
  return pdVar10;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dCamera_c::NotRun(void) */

undefined4 __thiscall dCamera_c::NotRun(dCamera_c *this)

{
  this->mEventFlags = this->mEventFlags & 0x6feb63de;
  checkGroundInfo(this);
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].field_0x8 =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].field_0x8 &
       0xffffff7f;
  if ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr.mCameraPlay != 0) ||
     ((this->mEventFlags & 0x20000000) != 0)) {
    if (this->mCurType != this->mCamTypeEvent) {
      pushPos(this);
      this->field_0x404 = this->mCurType;
    }
    this->mCurType = this->mCamTypeEvent;
    eventCamera(this,(int)types[this->mCurType].mStyles[3]);
    *(int *)&this->field_0x7c = *(int *)&this->field_0x7c + 1;
    this->field_0x118 = this->field_0x118 + 1;
    this->field_0x108 = this->field_0x108 + 1;
    this->field_0x11c = this->field_0x11c + 1;
  }
  if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode != 0) {
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].field_0x8 =
         d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].field_0x8 &
         0xffffffb7;
  }
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].field_0x8 =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].field_0x8 | 0x14;
  this->mEventFlags = this->mEventFlags & 0xfff6ff7f;
  dCamForcusLine::Off(&this->mForcusLine);
  shakeCamera(this);
  this->field_0x5 = 0;
  if ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].field_0x8 & 8) !=
      0) {
    if ((this->mEventFlags & 0x400000) == 0) {
      setView(this,d_camera::0_0,d_camera::0_0,d_camera::640_0,d_camera::480_0);
    }
    else {
      setView(this,d_camera::_6117,d_camera::_6118,d_camera::320_0,d_camera::320_0);
    }
  }
  return 1;
}


/* __thiscall dCamera_c::SetTrimSize(long) */

undefined4 __thiscall dCamera_c::SetTrimSize(dCamera_c *this,long param_1)

{
  this->field_0x5fc = param_1;
  return 1;
}


/* __thiscall dCamera_c::SetTrimTypeForce(long) */

undefined4 __thiscall dCamera_c::SetTrimTypeForce(dCamera_c *this,long param_1)

{
  *(long *)&this->field_0x600 = param_1;
  return 1;
}


/* __thiscall dCamera_c::CalcTrimSize(void) */

void __thiscall dCamera_c::CalcTrimSize(dCamera_c *this)

{
  int iVar1;
  
  iVar1 = this->field_0x5fc;
  if (iVar1 == 2) {
    this->field_0x5f8 =
         this->field_0x5f8 + d_camera::0_25 * ((this->mCamSetup).field_0x68 - this->field_0x5f8);
    return;
  }
  if (1 < iVar1) {
    if (iVar1 == 4) {
      this->field_0x5f8 = d_camera::0_0;
      return;
    }
    if (3 < iVar1) {
      return;
    }
    this->field_0x5f8 = (this->mCamSetup).field_0x68;
    return;
  }
  if (iVar1 == 0) {
    this->field_0x5f8 = this->field_0x5f8 + d_camera::0_25 * -this->field_0x5f8;
    return;
  }
  if (iVar1 < 0) {
    return;
  }
  this->field_0x5f8 =
       this->field_0x5f8 + d_camera::0_25 * ((this->mCamSetup).field_0x64 - this->field_0x5f8);
  return;
}


/* __thiscall dCamera_c::Draw(void) */

undefined4 __thiscall dCamera_c::Draw(dCamera_c *this)

{
  dCamForcusLine::Draw(&this->mForcusLine);
  return 1;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall dCamera_c::nextMode(long) */

long __thiscall dCamera_c::nextMode(dCamera_c *this,long param_1)

{
  bool bVar1;
  fopAc_ac_c *pfVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  undefined4 local_48;
  cXyz cStack68;
  cXyz local_38;
  float local_2c;
  float local_28;
  float local_24;
  
  positionOf(&local_38,this,this->mpPlayerActor);
  local_2c = local_38.x;
  local_28 = local_38.y;
  local_24 = local_38.z;
  lVar5 = param_1;
  if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr.mCameraPlay == 0) {
    if (local_38.y < (this->mBG).field_0x58) {
      this->field_0x1ae = 0;
    }
    switch(param_1) {
    case 4:
    case 10:
    case 0xb:
    case 0xd:
    case 0xe:
      this->field_0x144 = 1;
      *(undefined4 *)&this->field_0x184 = 0;
      break;
    case 5:
    case 6:
      this->field_0x144 = 1;
      *(undefined4 *)&this->field_0x184 = 0;
    case 1:
      this->mpLockonTarget = (fopAc_ac_c *)0x0;
    default:
      if (this->field_0x19b == 0) {
        if ((d_camera::0_0 < this->mStickCPosYLast) ||
           (this->mStickCValueLast <= (this->mCamSetup).field_0x9c)) {
          if (((param_1 == 0) || (param_1 == 0x13)) &&
             (((positionOf(&cStack68,this,this->mpPlayerActor),
               this->mStickMainValueLast < d_camera::_6431 &&
               (uVar3 = dAttention_c::LockonTruth
                                  (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAttention),
               (uVar3 & 0xff) == 0)) &&
              (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4] & 0x100000U) ==
               0)))) {
            if (*(int *)&this->field_0x184 == 1) {
              if (this->mStickCPosYLast < (this->mCamSetup).mCstick.field_0x0) {
                *(undefined4 *)&this->field_0x184 = 0;
              }
            }
            else {
              if (this->mStickCPosYLast <= (this->mCamSetup).mCstick.field_0x4) {
                d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].field_0x8
                     = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].
                       field_0x8 | 0x400;
              }
              else {
                d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].field_0x8
                     = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].
                       field_0x8 | 0x1000;
                *(undefined4 *)&this->field_0x184 = 1;
                d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].field_0x8
                     = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].
                       field_0x8 | 0x400;
              }
            }
          }
        }
        else {
          this->field_0x144 = 0;
        }
      }
      else {
        this->field_0x144 = 1;
        *(undefined4 *)&this->field_0x184 = 0;
      }
      break;
    case 0xc:
      if (((this->mStickCValueLast < d_camera::_6065) &&
          (this->field_0x8 < (this->mCamSetup).field_0x98)) ||
         ((this->mEventFlags & 0x80000000) != 0)) {
        this->field_0x144 = 1;
        *(undefined4 *)&this->field_0x184 = 0;
      }
      else {
        if (this->field_0x19b != 0) {
          this->field_0x144 = 1;
          *(undefined4 *)&this->field_0x184 = 0;
        }
      }
    }
    if ((this->mEventFlags & 0x4000000) != 0) {
      if (this->field_0x144 == 0) {
        this->field_0x254 = this->field_0x254 | 1;
      }
      if (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4] & 0x80000000U) != 0)
      {
        this->mEventFlags = this->mEventFlags | 0x8000;
      }
      this->field_0x144 = 1;
      this->mEventFlags = this->mEventFlags & 0xfbffffff;
    }
    if (((this->field_0x130 != -1) && (*(int *)&this->field_0x134 != 0)) &&
       (*(short *)(*(int *)&this->field_0x134 + 8) == 0x171)) {
      this->field_0x144 = 1;
      lVar5 = 0;
    }
    if ((lVar5 == 0xc) && (this->field_0x144 != 0)) {
      param_1 = 0;
    }
    else {
      uVar3 = (&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4];
      if (((uVar3 & 0x200000) == 0) &&
         (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5ccc)[this->mPadId * 4] & 8U) == 0)) {
        if ((uVar3 & 0x80000080) == 0) {
          if ((uVar3 & 0x800000) == 0) {
            if (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5ccc)[this->mPadId * 4] & 0x10U) == 0)
            {
              if ((uVar3 & 0x2000) == 0) {
                if ((uVar3 & 0x25000) != 0) {
                  bVar1 = true;
                  uVar3 = dAttention_c::LockonTruth
                                    (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAttention);
                  if (((uVar3 & 0xff) == 0) &&
                     ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAttention.mFlags & 0x20000000) == 0
                     )) {
                    bVar1 = false;
                  }
                  if (!bVar1) {
                    param_1 = 10;
                    goto LAB_801647b0;
                  }
                }
                if (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4] & 0x80000U
                    ) != 0) {
                  bVar1 = true;
                  uVar3 = dAttention_c::LockonTruth
                                    (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAttention);
                  if (((uVar3 & 0xff) == 0) &&
                     ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAttention.mFlags & 0x20000000) == 0
                     )) {
                    bVar1 = false;
                  }
                  if (!bVar1) {
                    param_1 = 0xb;
                    goto LAB_801647b0;
                  }
                }
                if (this->field_0x144 == 0) {
                  param_1 = 0xc;
                }
                else {
                  if (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5ccc)[this->mPadId * 4] & 2U) ==
                      0) {
                    if (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5ccc)[this->mPadId * 4] & 4U)
                        == 0) {
                      uVar3 = (&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4];
                      if ((uVar3 & 0x60) == 0) {
                        if ((uVar3 & 0x61) == 0) {
                          if (((uVar3 & 0x406) == 0) || (lVar5 == 0xc)) {
                            uVar3 = dAttention_c::LockonTruth
                                              (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAttention)
                            ;
                            if (((uVar3 & 0xff) == 0) ||
                               (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)
                                 [this->mPadId * 4] & 0xc000000U) != 0)) {
                              bVar1 = true;
                              uVar3 = dAttention_c::LockonTruth
                                                (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.
                                                  mAttention);
                              if (((uVar3 & 0xff) == 0) &&
                                 ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAttention.mFlags &
                                  0x20000000) == 0)) {
                                bVar1 = false;
                              }
                              if (bVar1) {
                                param_1 = 1;
                              }
                              else {
                                iVar4 = this->mPadId;
                                if (((((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[iVar4 * 4]
                                      & 0x400000U) == 0) ||
                                    (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[iVar4 * 4]
                                     & 0x36a02371U) != 0)) ||
                                   (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5ccc)[iVar4 * 4] &
                                    0x11U) != 0)) {
                                  bVar1 = false;
                                  if ((((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5ccc)
                                        [iVar4 * 4] & 0x80000U) != 0) ||
                                     (daNpc_Md_c::m_mirror != '\0')) {
                                    bVar1 = true;
                                  }
                                  if (bVar1) {
                                    param_1 = 0x13;
                                  }
                                  else {
                                    if (this->field_0x130 == -1) {
                                      if (lVar5 == 0xc) {
                                        if (this->field_0x144 != 0) {
                                          param_1 = 0;
                                        }
                                      }
                                      else {
                                        param_1 = 0;
                                      }
                                    }
                                    else {
                                      if (*(fopAc_ac_c **)&this->field_0x134 == (fopAc_ac_c *)0x0) {
                                        param_1 = 0;
                                        this->field_0x130 = -1;
                                      }
                                      else {
                                        param_1 = 2;
                                        this->mpLockonTarget = *(fopAc_ac_c **)&this->field_0x134;
                                      }
                                    }
                                  }
                                }
                                else {
                                  if ((this->mpPlayerActor->parent).parent.mProcName == 0xa9) {
                                    local_48 = (**(code **)(*(int *)&this->mpPlayerActor[1].parent.
                                                                     parent.mPi.mMtdTg.parent.
                                                                     mbAdded + 0x54))();
                                    pfVar2 = f_op_actor_iter::fopAcIt_Judge
                                                       (f_pc_searcher::fpcSch_JudgeByID,&local_48);
                                  }
                                  else {
                                    pfVar2 = (fopAc_ac_c *)0x0;
                                  }
                                  this->mpLockonTarget = pfVar2;
                                  param_1 = 2;
                                  this->field_0x130 = -1;
                                }
                              }
                            }
                            else {
                              param_1 = 2;
                            }
                          }
                          else {
                            if (this->mpLockonTarget != (fopAc_ac_c *)0x0) {
                              param_1 = 8;
                            }
                          }
                        }
                        else {
                          param_1 = 5;
                        }
                      }
                      else {
                        param_1 = 6;
                      }
                    }
                    else {
                      param_1 = 6;
                    }
                  }
                  else {
                    param_1 = 5;
                  }
                }
              }
              else {
                param_1 = 4;
              }
            }
            else {
              param_1 = 0xf;
            }
          }
          else {
            if (this->field_0x144 == 0) {
              param_1 = 0xc;
            }
            else {
              param_1 = 0x12;
            }
          }
        }
        else {
          param_1 = 0x11;
        }
      }
      else {
        param_1 = 0xe;
      }
    }
  }
LAB_801647b0:
  if (param_1 != 2) {
    this->field_0x130 = -1;
  }
  if ((param_1 == 0xc) && (iVar4 = this->mCurType, types[iVar4].mStyles[0xc] < 0)) {
    if ((iVar4 != this->mCamTypeEvent) &&
       (((iVar4 != this->mCamTypeBoat && (iVar4 != this->mCamTypeBoatBattle)) &&
        (iVar4 != this->mCamTypeRestrict)))) {
      this->field_0x254 = this->field_0x254 | 1;
    }
    this->field_0x144 = 1;
    param_1 = lVar5;
  }
  if ((-1 < types[this->mCurType].mStyles[param_1]) && (lVar5 = param_1, param_1 == 1)) {
    this->mEventFlags = this->mEventFlags | 0x100000;
  }
  return lVar5;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dCamera_c::onModeChange(long,
                                      long) */

undefined4 __thiscall dCamera_c::onModeChange(dCamera_c *this,long cur,long next)

{
  if ((cur == 0xe) && ((((this->mCamParam).mpStyle)->mFlag & 0x10) != 0)) {
    setView(this,d_camera::0_0,d_camera::0_0,d_camera::640_0,d_camera::480_0);
  }
  this->field_0x108 = 0;
  *(undefined *)&this->field_0x100 = 0;
  *(undefined *)&this->field_0x101 = 0;
  *(undefined *)&this->field_0x102 = 0;
  *(undefined4 *)&this->field_0x10c = 0;
  this->field_0x110 = 1;
  this->field_0x14c = d_camera::0_0;
  this->mEventFlags = this->mEventFlags & 0xfffffee1;
  this->mEventFlags = this->mEventFlags & 0xffffdfff;
  if ((((cur < 10) && (cur != 4)) && (cur < 4)) && (2 < cur)) {
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].field_0x8 =
         d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].field_0x8 &
         0xfffffffb;
  }
  switch(next) {
  case 0:
    if ((cur == 1) && (types[this->mCurType].mStyles[0] == types[this->mCurType].mStyles[1])) {
      this->field_0x110 = 0;
    }
    break;
  case 1:
    if ((cur == 0) && (types[this->mCurType].mStyles[0] == types[this->mCurType].mStyles[1])) {
      this->field_0x110 = 0;
    }
    break;
  case 7:
    this->mEventFlags = this->mEventFlags | 0x10;
    break;
  case 0xc:
    if (cur != next) {
      this->field_0x254 = this->field_0x254 | 2;
    }
  }
  return 1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dCamera_c::nextType(long) */

int __thiscall dCamera_c::nextType(dCamera_c *this,int curType)

{
  int iVar1;
  int idx;
  int iVar2;
  int roomNo;
  uint uVar3;
  int iVar4;
  
  if ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr.mCameraPlay == 0) &&
     ((this->mEventFlags & 0x20000000) == 0)) {
    iVar4 = curType;
    if ((this->mpPlayerActor != (fopAc_ac_c *)0x0) && (this->field_0x514 != 1)) {
      if (curType == this->mCamTypeEvent) {
        iVar4 = this->field_0x404;
        this->field_0x404 = -1;
      }
      if (daNpc_kam_c::m_hyoi_kamome == 0) {
        iVar1 = this->mPadId;
        uVar3 = (&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[iVar1 * 4];
        if ((((uVar3 & 0x1010000) == 0) &&
            (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5ccc)[iVar1 * 4] & 0x80U) == 0)) ||
           (this->field_0x524 != 0xff)) {
          roomNo = -1;
          idx = this->mStageMapToolCameraIdx;
          if (idx == 0xff) {
            if (this->mRoomNo != -1) {
              roomNo = this->mRoomNo;
            }
            idx = this->mRoomMapToolCameraIdx;
          }
          iVar2 = this->field_0x524;
          if (iVar2 == 0xff) {
            if (idx == 0xff) {
              iVar1 = this->field_0x350;
              if (iVar1 < 1) {
                if ((uVar3 & 0x100000) == 0) {
                  iVar4 = this->mMapToolType;
                }
                else {
                  iVar4 = this->mCamTypeWater;
                }
              }
              else {
                if (iVar1 < mvBGType_num) {
                  iVar1 = GetCameraTypeFromCameraName(this,(&mvBGTypes)[iVar1]);
                  if (iVar1 != this->mCamTypeKeep) {
                    iVar4 = iVar1;
                  }
                  if (this->field_0x350 == 0x11) {
                    GetCameraTypeFromMapToolID
                              (this,0,(int)(char)(this->mpPlayerActor->mCurrent).mRoomNo);
                  }
                }
              }
            }
            else {
              if (idx == 0x1ff) {
                if (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5ccc)[iVar1 * 4] & 0x20U) == 0) {
                  if ((uVar3 & 0x100000) != 0) {
                    iVar4 = this->mCamTypeWater;
                  }
                }
                else {
                  iVar4 = this->mMapToolType;
                }
                if ((curType == this->mCamTypeBoat) ||
                   (iVar1 = GetCameraTypeFromCameraName(this,"BoatBattle"), curType == iVar1)) {
                  iVar4 = this->mCamTypeWater;
                }
              }
              else {
                iVar1 = GetCameraTypeFromMapToolID(this,idx,roomNo);
                iVar4 = curType;
                if ((iVar1 != this->mCamTypeKeep) && (iVar4 = iVar1, iVar1 == 0xff)) {
                  iVar4 = this->mMapToolType;
                }
              }
            }
          }
          else {
            iVar4 = iVar2;
            if ((fopAc_ac_c *)this->field_0x528 != (fopAc_ac_c *)0x0) {
              this->mpLockonTarget = (fopAc_ac_c *)this->field_0x528;
            }
          }
        }
        else {
          iVar4 = this->mCamTypeBoat;
        }
      }
      else {
        iVar4 = GetCameraTypeFromCameraName(this,"Seagal");
      }
    }
  }
  else {
    iVar4 = this->mCamTypeEvent;
    if ((curType != iVar4) &&
       (this->mEventFlags = this->mEventFlags & 0xffdfffff, curType != this->mCamTypeEvent)) {
      pushPos(this);
      this->field_0x404 = curType;
    }
  }
  this->field_0x524 = 0xff;
  this->field_0x528 = 0;
  return iVar4;
}


/* __thiscall dCamera_c::onTypeChange(long,
                                      long) */

undefined4 __thiscall dCamera_c::onTypeChange(dCamera_c *this,long cur,long next)

{
  int iVar1;
  char cVar2;
  long mode;
  
  this->field_0x118 = 0;
  this->field_0x114 = 0;
  mode = this->mCurMode;
  if ((this->field_0x144 == 0) && (-1 < types[next].mStyles[0])) {
    iVar1 = dCamParam_c::styles[types[next].mStyles[0]].mEngineIdx;
    if (iVar1 < 0xb) {
      if ((6 < iVar1) || (iVar1 < 5)) goto LAB_80164d7c;
    }
    else {
      if (0xd < iVar1) goto LAB_80164d7c;
    }
    mode = 0;
    this->field_0x144 = 1;
  }
LAB_80164d7c:
  cVar2 = onModeChange(this,this->mCurMode,mode);
  if (cVar2 != '\0') {
    this->field_0x11c = 0;
  }
  return 1;
}


/* __thiscall dCamera_c::SetTypeForce(char *,
                                      fopAc_ac_c *) */

void __thiscall dCamera_c::SetTypeForce(dCamera_c *this,char *param_1,fopAc_ac_c *param_2)

{
  int iVar1;
  
  iVar1 = GetCameraTypeFromCameraName(this,param_1);
  SetTypeForce(this,iVar1,param_2);
  return;
}


/* __thiscall dCamera_c::SetTypeForce(long,
                                      fopAc_ac_c *) */

int __thiscall dCamera_c::SetTypeForce(dCamera_c *this,long param_1,fopAc_ac_c *param_2)

{
  int iVar1;
  
  if (this->field_0x524 != 0xff) {
    return 0;
  }
  this->field_0x524 = param_1;
  this->field_0x528 = (int)param_2;
  iVar1 = -this->field_0x524 + 0xff;
  return iVar1 - ((uint)(iVar1 == 0) + -this->field_0x524 + 0xfe);
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dCamera_c::onStyleChange(long,
                                       long) */

undefined4 __thiscall dCamera_c::onStyleChange(dCamera_c *this,long param_1,long param_2)

{
  bool bVar1;
  int iVar2;
  
  this->field_0x11c = 0;
  bVar1 = false;
  iVar2 = dCamParam_c::styles[param_1].mEngineIdx;
  if (iVar2 == 4) {
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].field_0xc =
         d_camera::1_0;
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].field_0x8 =
         d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].field_0x8 &
         0xffffffb7;
  }
  else {
    if ((3 < iVar2) && (iVar2 < 7)) {
      if (*(char *)&this->field_0x220 == '\0') {
        setDMCAngle(this);
      }
      bVar1 = true;
    }
  }
  switch(dCamParam_c::styles[param_2].mEngineIdx) {
  case 1:
  case 8:
    if (dCamParam_c::styles[param_1].mEngineIdx == dCamParam_c::styles[param_2].mEngineIdx) {
      this->mEventFlags = this->mEventFlags | 0x8000;
    }
    break;
  case 5:
  case 6:
    if ((*(char *)&this->field_0x220 == '\0') || (bVar1)) {
      setDMCAngle(this);
    }
  case 4:
  case 0xc:
  case 0xd:
    if (this->field_0x144 == 0) {
      this->field_0x144 = 1;
    }
  }
  return 1;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall dCamera_c::GetCameraTypeFromMapToolID(long,
                                                    long) */

int __thiscall dCamera_c::GetCameraTypeFromMapToolID(dCamera_c *this,long idx,long roomNo)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  stage_arrow__entry *psVar5;
  stage_camera__entry *psVar6;
  uint uVar7;
  stage_camera_class *pCamera;
  int iVar8;
  stage_arrow_class *pArrow;
  
  if (roomNo == -1) {
    pCamera = (stage_camera_class *)
              (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getCamera)
                        (0x803c9d58);
    pArrow = (stage_arrow_class *)
             (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getArrow)
                       (0x803c9d58);
  }
  else {
    pCamera = d_com_inf_game::dComIfGp_getRoomCamera(roomNo);
    pArrow = d_com_inf_game::dComIfGp_getRoomArrow(roomNo);
    if (pCamera == (stage_camera_class *)0x0) {
      return 0xff;
    }
  }
  iVar1 = type_num;
  if (((idx < 0) || (pCamera == (stage_camera_class *)0x0)) ||
     ((pCamera != (stage_camera_class *)0x0 && (pCamera->mCount <= idx)))) {
    iVar3 = 0xff;
  }
  else {
    iVar3 = 0;
    iVar8 = 0;
    while ((iVar3 < iVar1 &&
           (iVar4 = MSL_C.PPCEABI.bare.H::strcmp
                              (pCamera->mpEntries[idx].mpTypeStr,types[0].mName + iVar8), iVar4 != 0
           ))) {
      iVar3 = iVar3 + 1;
      iVar8 = iVar8 + 0x40;
    }
    if (iVar3 == type_num) {
      iVar3 = 0xff;
    }
    else {
      psVar6 = pCamera->mpEntries + idx;
      uVar2 = *(undefined4 *)(psVar6->mpTypeStr + 4);
      *(undefined4 *)(this->mCurRoomCamEntry).mpTypeStr = *(undefined4 *)psVar6->mpTypeStr;
      *(undefined4 *)((this->mCurRoomCamEntry).mpTypeStr + 4) = uVar2;
      uVar2 = *(undefined4 *)(psVar6->mpTypeStr + 0xc);
      *(undefined4 *)((this->mCurRoomCamEntry).mpTypeStr + 8) =
           *(undefined4 *)(psVar6->mpTypeStr + 8);
      *(undefined4 *)((this->mCurRoomCamEntry).mpTypeStr + 0xc) = uVar2;
      (this->mCurRoomCamEntry).mArrowIdx = psVar6->mArrowIdx;
      (this->mCurRoomCamEntry).field_0x11 = psVar6->field_0x11;
      (this->mCurRoomCamEntry).field_0x12 = psVar6->field_0x12;
      (this->mCurRoomCamEntry).field_0x13 = psVar6->field_0x13;
      uVar7 = (uint)(this->mCurRoomCamEntry).mArrowIdx;
      if ((uVar7 == 0xffffffff) || (pArrow->mCount <= (int)uVar7)) {
        this->mCurArrowIdx = 0xff;
      }
      else {
        this->mCurArrowIdx = uVar7;
        psVar5 = pArrow->mpEntries + uVar7;
        (this->mCurRoomArrowEntry).mPos.x = (psVar5->mPos).x;
        (this->mCurRoomArrowEntry).mPos.y = (psVar5->mPos).y;
        (this->mCurRoomArrowEntry).mPos.z = (psVar5->mPos).z;
        (this->mCurRoomArrowEntry).mRot.x = (psVar5->mRot).x;
        (this->mCurRoomArrowEntry).mRot.y = (psVar5->mRot).y;
        (this->mCurRoomArrowEntry).mRot.z = (psVar5->mRot).z;
        (this->mCurRoomArrowEntry).field_0x12 = psVar5->field_0x12;
      }
    }
  }
  return iVar3;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dCamera_c::GetCameraTypeFromCameraName(char const *) */

int __thiscall dCamera_c::GetCameraTypeFromCameraName(dCamera_c *this,char *pName)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = MSL_C.PPCEABI.bare.H::strcmp(pName,types[this->mCurType].mName);
  iVar1 = type_num;
  if (iVar2 == 0) {
    iVar2 = this->mCurType;
  }
  else {
    iVar2 = 0;
    iVar4 = 0;
    while ((iVar2 < iVar1 &&
           (iVar3 = MSL_C.PPCEABI.bare.H::strcmp(pName,types[0].mName + iVar4), iVar3 != 0))) {
      iVar2 = iVar2 + 1;
      iVar4 = iVar4 + 0x40;
    }
    if (iVar2 == type_num) {
      iVar2 = 0xff;
    }
  }
  return iVar2;
}


/* __thiscall dCamera_c::pushPos(void) */

void __thiscall dCamera_c::pushPos(dCamera_c *this)

{
  (this->field_0x84).x = (this->field_0x44).x;
  (this->field_0x84).y = (this->field_0x44).y;
  (this->field_0x84).z = (this->field_0x44).z;
  (this->field_0x90).x = (this->field_0x50).x;
  (this->field_0x90).y = (this->field_0x50).y;
  (this->field_0x90).z = (this->field_0x50).z;
  this->field_0x9c = this->field_0x60;
  *(short *)&this->field_0xa0 = this->field_0x5c;
  return;
}


namespace d_camera {

/* __stdcall limited_range_addition(float *,
                                    float,
                                    float,
                                    float) */

undefined4
limited_range_addition(double param_1,double param_2,double param_3,float *param_4)

{
  double dVar1;
  
  dVar1 = param_3;
  if (param_3 < param_2) {
    param_1 = -param_1;
    dVar1 = param_2;
    param_2 = param_3;
  }
  *param_4 = (float)((double)*param_4 + param_1);
  if ((double)*param_4 < param_2) {
    *param_4 = (float)param_2;
    return 0;
  }
  if (dVar1 < (double)*param_4) {
    *param_4 = (float)dVar1;
    return 0;
  }
  return 1;
}

}

/* __thiscall dCamera_c::directionOf(fopAc_ac_c *) */

void __thiscall dCamera_c::directionOf(dCamera_c *this,fopAc_ac_c *param_1)

{
  int in_r5;
  
  cSAngle::cSAngle((cSAngle *)this,*(short *)(in_r5 + 0x20e));
  return;
}


/* __thiscall dCamera_c::positionOf(fopAc_ac_c *) */

cXyz * __thiscall
dCamera_c::positionOf(cXyz *__return_storage_ptr__,dCamera_c *this,fopAc_ac_c *param_1)

{
  __return_storage_ptr__->x = (param_1->mCurrent).mPos.x;
  __return_storage_ptr__->y = (param_1->mCurrent).mPos.y;
  __return_storage_ptr__->z = (param_1->mCurrent).mPos.z;
  return __return_storage_ptr__;
}


/* __thiscall dCamera_c::attentionPos(fopAc_ac_c *) */

cXyz * __thiscall
dCamera_c::attentionPos(cXyz *__return_storage_ptr__,dCamera_c *this,fopAc_ac_c *param_1)

{
  __return_storage_ptr__->x = (param_1->mAttentionPos).x;
  __return_storage_ptr__->y = (param_1->mAttentionPos).y;
  __return_storage_ptr__->z = (param_1->mAttentionPos).z;
  return __return_storage_ptr__;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dCamera_c::relationalPos(fopAc_ac_c *,
                                       cXyz *) */

cXyz * __thiscall
dCamera_c::relationalPos
          (cXyz *__return_storage_ptr__,dCamera_c *this,fopAc_ac_c *param_1,cXyz *param_2)

{
  cXyz *pcVar1;
  cSAngle local_48 [2];
  cSAngle local_44 [2];
  cSAngle acStack64 [2];
  cSGlobe cStack60;
  cXyz cStack52;
  cXyz acStack40 [2];
  
  if (param_1 == (fopAc_ac_c *)0x0) {
    pcVar1 = &::cXyz::Zero;
    __return_storage_ptr__->x = ::cXyz::Zero.x;
    __return_storage_ptr__->y = ::cXyz::Zero.y;
    __return_storage_ptr__->z = ::cXyz::Zero.z;
  }
  else {
    cSGlobe::cSGlobe(&cStack60,param_2);
    directionOf((dCamera_c *)acStack64,(fopAc_ac_c *)this);
    cSAngle::operator__(local_44,acStack64);
    cSAngle::cSAngle(local_48,local_44[0]);
    cStack60.mAngleY = local_48[0];
    attentionPos(acStack40,this,param_1);
    cSGlobe::Xyz(&cStack52,&cStack60);
    pcVar1 = ::cXyz::operator__(__return_storage_ptr__,acStack40,&cStack52);
  }
  return pcVar1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dCamera_c::relationalPos(fopAc_ac_c *,
                                       cXyz *,
                                       cSAngle) */

cXyz * __thiscall
dCamera_c::relationalPos
          (cXyz *__return_storage_ptr__,dCamera_c *this,fopAc_ac_c *param_1,cXyz *param_2,
          cSAngle param_3)

{
  cXyz *pcVar1;
  cSAngle local_48 [2];
  cSAngle local_44 [2];
  cSAngle acStack64 [2];
  cSAngle acStack60 [2];
  cSGlobe cStack56;
  cXyz cStack48;
  cXyz cStack36;
  
  if (param_1 == (fopAc_ac_c *)0x0) {
    pcVar1 = &::cXyz::Zero;
    __return_storage_ptr__->x = ::cXyz::Zero.x;
    __return_storage_ptr__->y = ::cXyz::Zero.y;
    __return_storage_ptr__->z = ::cXyz::Zero.z;
  }
  else {
    cSGlobe::cSGlobe(&cStack56,param_2);
    directionOf((dCamera_c *)acStack60,(fopAc_ac_c *)this);
    cSAngle::operator__(acStack64,acStack60);
    cSAngle::operator__(local_44,acStack64);
    cSAngle::cSAngle(local_48,local_44[0]);
    cStack56.mAngleY = local_48[0];
    attentionPos(&cStack36,this,param_1);
    cSGlobe::Xyz(&cStack48,&cStack56);
    pcVar1 = ::cXyz::operator__(__return_storage_ptr__,&cStack36,&cStack48);
  }
  return pcVar1;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x80165684) */
/* WARNING: Removing unreachable block (ram,0x8016568c) */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall dCamera_c::relationalPos(fopAc_ac_c *,
                                       fopAc_ac_c *,
                                       cXyz *,
                                       float) */

void __thiscall
dCamera_c::relationalPos
          (dCamera_c *this,fopAc_ac_c *param_1,fopAc_ac_c *param_2,cXyz *param_3,float param_4)

{
  cXyz *in_r7;
  undefined4 uVar1;
  double dVar2;
  double dVar3;
  undefined8 in_f30;
  undefined8 in_f31;
  double dVar4;
  cSAngle local_108 [2];
  cSAngle acStack260 [2];
  cSAngle local_100 [2];
  cSAngle acStack252 [2];
  cSAngle acStack248 [2];
  cSGlobe cStack244;
  cSGlobe local_ec;
  cXyz local_e4;
  cXyz cStack216;
  cXyz cStack204;
  cXyz cStack192;
  cXyz cStack180;
  cXyz local_a8;
  cXyz cStack156;
  cXyz cStack144;
  cXyz local_84;
  cXyz local_78 [2];
  cXyz local_60;
  cXyz local_54;
  cXyz local_48;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar2 = (double)param_4;
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  if (param_2 == (fopAc_ac_c *)0x0) {
    this->mpCamera = (camera_class *)::cXyz::Zero.x;
    *(float *)&this->field_0x4 = ::cXyz::Zero.y;
    this->field_0x8 = ::cXyz::Zero.z;
  }
  else {
    if (param_3 == (cXyz *)0x0) {
      relationalPos((cXyz *)this,(dCamera_c *)param_1,param_2,in_r7);
    }
    else {
      attentionPos(local_78,(dCamera_c *)param_1,param_2);
      local_48.x = local_78[0].x;
      local_48.y = local_78[0].y;
      local_48.z = local_78[0].z;
      attentionPos(&local_84,(dCamera_c *)param_1,(fopAc_ac_c *)param_3);
      local_54.x = local_84.x;
      local_54.y = local_84.y;
      local_54.z = local_84.z;
      ::cXyz::operator__(&cStack144,&local_54,&local_48);
      ::cXyz::operator_(&cStack156,&cStack144,d_camera::_6431);
      ::cXyz::operator__(&local_a8,&local_48,&cStack156);
      local_60.x = local_a8.x;
      local_60.y = local_a8.y;
      local_60.z = local_a8.z;
      ::cXyz::operator__(&cStack180,&local_54,&local_48);
      cSGlobe::cSGlobe(&local_ec,&cStack180);
      cSGlobe::cSGlobe(&cStack244,in_r7);
      directionOf((dCamera_c *)acStack252,param_1);
      cSAngle::operator__(local_100,acStack252);
      cSAngle::cSAngle(local_108,local_100[0]);
      cStack244.mAngleY = local_108[0];
      cSAngle::operator__(acStack260,
                          (cSAngle *)((int)&(param_1->parent).parent.mLnTg.parent.mpTagData + 2));
      cSAngle::cSAngle(acStack248,acStack260);
      dVar4 = (double)local_ec.mDistance;
      dVar3 = (double)cSAngle::Cos(acStack248);
      local_ec.mDistance =
           (float)(dVar2 * (double)(float)((double)(float)((double)d_camera::_6431 * dVar4) * dVar3)
                  );
      cSGlobe::Xyz(&cStack192,&local_ec);
      ::cXyz::operator__(&cStack204,&local_60,&cStack192);
      cSGlobe::Xyz(&cStack216,&cStack244);
      ::cXyz::operator__(&local_e4,&cStack204,&cStack216);
      this->mpCamera = (camera_class *)local_e4.x;
      *(float *)&this->field_0x4 = local_e4.y;
      this->field_0x8 = local_e4.z;
    }
  }
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  __psq_l0(auStack24,uVar1);
  __psq_l1(auStack24,uVar1);
  return;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall dCamera_c::setDMCAngle(void) */

void __thiscall dCamera_c::setDMCAngle(dCamera_c *this)

{
  short sVar1;
  cSAngle local_18 [2];
  cSAngle local_14 [8];
  
  *(undefined *)&this->field_0x220 = 1;
  sVar1 = cSAngle::Inv(&this->field_0xe);
  cSAngle::cSAngle(local_14,sVar1);
  ((cSAngle *)&this->field_0x222)->v = local_14[0];
  cSAngle::cSAngle(local_18,m_Do_controller_pad::g_mDoCPd_cpadInfo[this->mPadId].mStickMainAngle);
  ((cSAngle *)&this->field_0x224)->v = local_18[0];
  return;
}


/* __thiscall dCamera_c::getDMCAngle(cSAngle) */

void __thiscall dCamera_c::getDMCAngle(dCamera_c *this,cSAngle param_1)

{
  undefined2 in_register_00000010;
  
  cSAngle::cSAngle((cSAngle *)this,(cSAngle *)(CONCAT22(in_register_00000010,param_1) + 0x222));
  return;
}


/* WARNING: Removing unreachable block (ram,0x801657dc) */
/* WARNING: Removing unreachable block (ram,0x801657e4) */
/* __thiscall dCamera_c::pointInSight(cXyz *) */

undefined4 __thiscall dCamera_c::pointInSight(dCamera_c *this,cXyz *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 in_f30;
  double dVar4;
  undefined8 in_f31;
  double dVar5;
  cXyz local_38;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  iVar1 = f_op_camera_mng::fopCamM_GetParam(this->mpCamera);
  iVar1 = (char)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[iVar1].mDlstWindowIdx * 0x2c;
  dVar5 = (double)*(float *)((int)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mDlstWindow +
                            iVar1 + 0x20);
  dVar4 = (double)*(float *)((int)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mDlstWindow +
                            iVar1 + 0x24);
  m_Do_lib::mDoLib_project(param_1,&local_38);
  uVar2 = 0;
  if (((((double)d_camera::0_0 < (double)local_38.x) && ((double)local_38.x < dVar5)) &&
      ((double)d_camera::0_0 < (double)local_38.y)) && ((double)local_38.y < dVar4)) {
    uVar2 = 1;
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  __psq_l0(auStack24,uVar3);
  __psq_l1(auStack24,uVar3);
  return uVar2;
}


/* __thiscall dCamera_c::radiusActorInSight(fopAc_ac_c *,
                                            fopAc_ac_c *) */

void __thiscall
dCamera_c::radiusActorInSight(dCamera_c *this,fopAc_ac_c *param_1,fopAc_ac_c *param_2)

{
  radiusActorInSight(this,param_1,param_2,&this->field_0x44,&this->field_0x50,this->mFovY,
                     (this->mBank).v);
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Removing unreachable block (ram,0x80165c9c) */
/* WARNING: Removing unreachable block (ram,0x80165ca4) */
/* __thiscall dCamera_c::radiusActorInSight(fopAc_ac_c *,
                                            fopAc_ac_c *,
                                            cXyz *,
                                            cXyz *,
                                            float,
                                            short) */

double __thiscall
dCamera_c::radiusActorInSight
          (dCamera_c *this,fopAc_ac_c *param_1,fopAc_ac_c *param_2,cXyz *param_3,cXyz *param_4,
          float param_5,short param_6)

{
  int iVar1;
  undefined2 in_register_00000020;
  uint uVar2;
  undefined4 uVar3;
  double dVar4;
  undefined8 in_f30;
  double dVar5;
  undefined8 in_f31;
  double dVar6;
  cSAngle local_158 [2];
  cSAngle local_154 [2];
  cSAngle local_150 [2];
  cSAngle local_14c [2];
  cSAngle local_148 [2];
  cSAngle local_144 [2];
  cSAngle local_140 [2];
  cSAngle local_13c [2];
  cSAngle local_138;
  cSAngle local_134 [2];
  cSAngle local_130 [2];
  cSGlobe cStack300;
  cSGlobe cStack292;
  cSGlobe cStack284;
  cXyz cStack276;
  cXyz cStack264;
  cXyz cStack252;
  cXyz cStack240;
  cXyz cStack228;
  cXyz local_d8;
  cXyz local_cc;
  cXyz local_c0;
  cXyz cStack180;
  cXyz local_a8;
  cXyz local_9c;
  cXyz local_90;
  cXyz local_84;
  MTX34 MStack120;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar6 = (double)param_5;
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  ::cXyz::operator__(&cStack180,param_4,param_3);
  cSGlobe::cSGlobe(&cStack284,&cStack180);
  attentionPos(&local_c0,this,param_1);
  local_84.x = local_c0.x;
  local_84.y = local_c0.y;
  local_84.z = local_c0.z;
  attentionPos(&local_cc,this,param_2);
  local_90.x = local_cc.x;
  local_90.y = local_cc.y;
  local_90.z = local_cc.z;
  ::cXyz::operator__(&local_d8,&local_84,&local_90);
  local_9c.x = local_d8.x;
  local_9c.y = local_d8.y;
  local_9c.z = local_d8.z;
  ::cXyz::normalize(&cStack228);
  ::cXyz::operator_(&cStack240,&local_9c,d_camera::_5573);
  mtx::PSVECAdd(&local_84,&cStack240,&local_84);
  ::cXyz::operator_(&cStack252,&local_9c,d_camera::_5573);
  mtx::PSVECSubtract(&local_90,&cStack252,&local_90);
  iVar1 = f_op_camera_mng::fopCamM_GetParam(this->mpCamera);
  iVar1 = (char)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[iVar1].mDlstWindowIdx * 0x2c;
  cSAngle::cSAngle(local_130,
                   d_camera::_7227 *
                   (float)((double)d_camera::_6431 * dVar6) *
                   (*(float *)((int)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mDlstWindow +
                              iVar1 + 0x24) / d_camera::480_0));
  cSAngle::cSAngle(local_134,
                   d_camera::_7227 *
                   (*(float *)((int)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mDlstWindow +
                              iVar1 + 0x20) / d_camera::640_0) *
                   d_camera::_6431 * (float)(dVar6 * (double)this->field_0x604));
  ::cXyz::operator__(&cStack264,param_4,&local_84);
  cSGlobe::cSGlobe(&cStack292,&cStack264);
  ::cXyz::operator__(&cStack276,param_4,&local_90);
  cSGlobe::cSGlobe(&cStack300,&cStack276);
  uVar2 = 0;
  cSAngle::operator__(local_13c,&cStack292.mAngleY);
  local_138 = local_13c[0];
  cSAngle::operator__(local_140);
  if ((((int)(short)(local_140[0] ^ local_138) >> 1) -
       (int)(short)((local_140[0] ^ local_138) & local_140[0]) < 0) || (local_134[0] < local_138)) {
    uVar2 = 1;
  }
  cSAngle::operator__(local_144,&cStack292.mAngleX);
  local_138 = local_144[0];
  cSAngle::operator__(local_148);
  if ((((int)(short)(local_148[0] ^ local_138) >> 1) -
       (int)(short)((local_148[0] ^ local_138) & local_148[0]) < 0) || (local_130[0] < local_138)) {
    uVar2 = uVar2 | 2;
  }
  cSAngle::operator__(local_14c,&cStack300.mAngleY);
  local_138 = local_14c[0];
  cSAngle::operator__(local_150);
  if ((((int)(short)(local_150[0] ^ local_138) >> 1) -
       (int)(short)((local_150[0] ^ local_138) & local_150[0]) < 0) || (local_134[0] < local_138)) {
    uVar2 = uVar2 | 4;
  }
  cSAngle::operator__(local_154,&cStack300.mAngleX);
  local_138 = local_154[0];
  cSAngle::operator__(local_158);
  if ((((int)(short)(local_158[0] ^ local_138) >> 1) -
       (int)(short)((local_158[0] ^ local_138) & local_158[0]) < 0) || (local_130[0] < local_138)) {
    uVar2 = uVar2 | 8;
  }
  if (uVar2 == 0) {
    dVar6 = (double)d_camera::0_0;
  }
  else {
    dVar6 = (double)d_camera::0_0;
    m_Do_mtx::mDoMtx_lookAt
              (&MStack120,param_4,param_3,&this->mUp,CONCAT22(in_register_00000020,param_6));
    if ((uVar2 & 3) != 0) {
      mtx::PSMTXMultVec(&MStack120,&local_84,&local_a8);
      if ((uVar2 & 1) != 0) {
        dVar5 = (double)ABS(local_a8.x);
        dVar4 = (double)cSAngle::Tan(local_134);
        dVar4 = (double)(local_a8.z + (float)(dVar5 / dVar4));
        if ((double)d_camera::0_0 < dVar4) {
          dVar6 = dVar4;
        }
      }
      if ((uVar2 & 2) != 0) {
        dVar5 = (double)ABS(local_a8.y);
        dVar4 = (double)cSAngle::Tan(local_130);
        dVar4 = (double)(local_a8.z + (float)(dVar5 / dVar4));
        if (dVar6 < dVar4) {
          dVar6 = dVar4;
        }
      }
    }
    if ((uVar2 & 0xc) != 0) {
      mtx::PSMTXMultVec(&MStack120,&local_90,&local_a8);
      if ((uVar2 & 4) != 0) {
        dVar5 = (double)ABS(local_a8.x);
        dVar4 = (double)cSAngle::Tan(local_134);
        dVar4 = (double)(local_a8.z + (float)(dVar5 / dVar4));
        if (dVar6 < dVar4) {
          dVar6 = dVar4;
        }
      }
      if ((uVar2 & 8) != 0) {
        dVar5 = (double)ABS(local_a8.y);
        dVar4 = (double)cSAngle::Tan(local_130);
        dVar4 = (double)(local_a8.z + (float)(dVar5 / dVar4));
        if (dVar6 < dVar4) {
          dVar6 = dVar4;
        }
      }
    }
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  __psq_l0(auStack24,uVar3);
  __psq_l1(auStack24,uVar3);
  return dVar6;
}


/* WARNING: Inlined function: FUN_80328f0c */
/* WARNING: Inlined function: FUN_80328f58 */
/* WARNING: Removing unreachable block (ram,0x801660a8) */
/* __thiscall dCamera_c::groundHeight(cXyz *) */

double __thiscall dCamera_c::groundHeight(dCamera_c *this,cXyz *param_1)

{
  cBgS_PolyPassChk *pcVar1;
  cBgS_PolyPassChk *pcVar2;
  undefined4 uVar3;
  double dVar4;
  double dVar5;
  undefined8 in_f31;
  cBgS_GndChk local_f8;
  cBgS_PolyPassChk local_b8;
  undefined local_ac [8];
  cBgS_GndChk local_a4;
  cBgS_PolyPassChk local_64;
  undefined **local_58;
  undefined4 local_54;
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  ::cBgS_GndChk::cBgS_GndChk(&local_a4);
  pcVar2 = &local_64;
  local_64.mbObjThrough = 0;
  local_64.mbCamThrough = 0;
  local_64.mbLinkThrough = 0;
  local_64.mbArrowsAndLightThrough = 0;
  local_64.mbBombThrough = 0;
  local_64.mbBoomerangThrough = 0;
  local_64.mbHookshotThrough = 0;
  local_54 = 1;
  local_a4.parent.vtbl = &::dBgS_GndChk::__vt;
  local_a4.mPolyInfo.vtbl = &cBgS_PolyInfo__vtbl_80371f08;
  local_64.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
  local_58 = &PTR_80371f20;
  local_a4.parent.mpGrpPassChk = (cBgS_GrpPassChk *)pcVar2;
  if (pcVar2 != (cBgS_PolyPassChk *)0x0) {
    local_a4.parent.mpGrpPassChk = (cBgS_GrpPassChk *)&local_58;
  }
  local_a4.mPos.x = param_1->x;
  local_a4.mPos.y = param_1->y;
  local_a4.mPos.z = param_1->z;
  local_a4.parent.mpPolyPassChk = pcVar2;
  dVar4 = (double)cBgS::GroundCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,&local_a4);
  ::cBgS_GndChk::cBgS_GndChk(&local_f8);
  pcVar1 = &local_b8;
  local_b8.mbObjThrough = 0;
  local_b8.mbLinkThrough = 0;
  local_b8.mbArrowsAndLightThrough = 0;
  local_b8.mbBombThrough = 0;
  local_b8.mbBoomerangThrough = 0;
  local_b8.mbHookshotThrough = 0;
  local_f8.parent.mpGrpPassChk = (cBgS_GrpPassChk *)pcVar1;
  if (pcVar1 != (cBgS_PolyPassChk *)0x0) {
    local_f8.parent.mpGrpPassChk = (cBgS_GrpPassChk *)local_ac;
  }
  local_b8.mbCamThrough = 1;
  local_f8.parent.vtbl = (cBgS_Chk__vtbl *)&dBgS_CamGndChk_Wtr::__vt;
  local_f8.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&DAT_80391080;
  local_b8.vtbl = (cBgS_PolyPassChk__vtbl *)&DAT_8039108c;
  local_ac._0_4_ = (undefined **)&DAT_80391098;
  local_ac._4_4_ = 2;
  local_f8.mPos.x = param_1->x;
  local_f8.mPos.y = param_1->y;
  local_f8.mPos.z = param_1->z;
  local_f8.parent.mpPolyPassChk = pcVar1;
  dVar5 = (double)cBgS::GroundCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,&local_f8);
  if (dVar5 <= dVar4) {
    dVar5 = dVar4;
  }
  if ((double)d_camera::_5126 == dVar5) {
    dVar5 = (double)param_1->y;
  }
  local_b8.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
  local_ac._0_4_ = &PTR_80371f20;
  if (pcVar1 != (cBgS_PolyPassChk *)0x0) {
    local_b8.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
    local_ac._0_4_ = &PTR_80371f68;
    if (((undefined *)register0x00000004 != (undefined *)0xac) &&
       (local_ac._0_4_ = &::dBgS_GrpPassChk::__vt,
       (undefined *)register0x00000004 != (undefined *)0xac)) {
      local_ac._0_4_ = &::cBgS_GrpPassChk::__vt;
    }
    if ((pcVar1 != (cBgS_PolyPassChk *)0x0) &&
       (local_b8.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
       pcVar1 != (cBgS_PolyPassChk *)0x0)) {
      local_b8.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
    }
  }
  local_f8.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_GndChk::__vt;
  local_f8.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
  cBgS_Chk::_cBgS_Chk(&local_f8.parent);
  local_64.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
  local_58 = &PTR_80371f20;
  if (pcVar2 != (cBgS_PolyPassChk *)0x0) {
    local_64.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
    local_58 = &PTR_80371f68;
    if (((undefined *)register0x00000004 != (undefined *)0x58) &&
       (local_58 = &::dBgS_GrpPassChk::__vt, (undefined *)register0x00000004 != (undefined *)0x58))
    {
      local_58 = &::cBgS_GrpPassChk::__vt;
    }
    if ((pcVar2 != (cBgS_PolyPassChk *)0x0) &&
       (local_64.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
       pcVar2 != (cBgS_PolyPassChk *)0x0)) {
      local_64.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
    }
  }
  local_a4.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_GndChk::__vt;
  local_a4.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
  cBgS_Chk::_cBgS_Chk(&local_a4.parent);
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return dVar5;
}


/* __thiscall dBgS_CamGndChk_Wtr::~dBgS_CamGndChk_Wtr(void) */

void __thiscall dBgS_CamGndChk_Wtr::_dBgS_CamGndChk_Wtr(dBgS_CamGndChk_Wtr *this)

{
  bool bVar1;
  short in_r4;
  
  bVar1 = this != (dBgS_CamGndChk_Wtr *)0x0;
  if (bVar1) {
    *(undefined1 **)(this + 0x10) = &__vt;
    *(undefined **)(this + 0x20) = &DAT_80391080;
    *(undefined **)(this + 0x40) = &DAT_8039108c;
    *(undefined **)(this + 0x4c) = &DAT_80391098;
    if (bVar1) {
      *(undefined1 **)(this + 0x10) = &dBgS_CamGndChk::__vt;
      *(undefined **)(this + 0x20) = &DAT_80391200;
      *(undefined **)(this + 0x40) = &DAT_8039120c;
      *(undefined **)(this + 0x4c) = &DAT_80391218;
      if (bVar1) {
        *(cBgS_Chk__vtbl **)(this + 0x10) = &::dBgS_GndChk::__vt;
        *(cBgS_PolyInfo__vtbl **)(this + 0x20) = &cBgS_PolyInfo__vtbl_80371f08;
        *(undefined ***)(this + 0x40) = &PTR_80371f14;
        *(undefined ***)(this + 0x4c) = &PTR_80371f20;
        if (this != (dBgS_CamGndChk_Wtr *)0xffffffc0) {
          *(undefined ***)(this + 0x40) = &::dBgS_Chk::__vt;
          *(undefined ***)(this + 0x4c) = &PTR_80371f68;
          if (this != (dBgS_CamGndChk_Wtr *)0xffffffb4) {
            *(undefined ***)(this + 0x4c) = &::dBgS_GrpPassChk::__vt;
            if (this != (dBgS_CamGndChk_Wtr *)0xffffffb4) {
              *(undefined ***)(this + 0x4c) = &::cBgS_GrpPassChk::__vt;
            }
          }
          if ((this != (dBgS_CamGndChk_Wtr *)0xffffffc0) &&
             (*(undefined ***)(this + 0x40) = &::dBgS_PolyPassChk::__vt,
             this != (dBgS_CamGndChk_Wtr *)0xffffffc0)) {
            *(undefined ***)(this + 0x40) = &::cBgS_PolyPassChk::__vt;
          }
        }
        if (this != (dBgS_CamGndChk_Wtr *)0x0) {
          *(undefined1 **)(this + 0x10) = &::cBgS_GndChk::__vt;
          *(undefined ***)(this + 0x20) = &PTR_80371e90;
          if (this != (dBgS_CamGndChk_Wtr *)0xffffffec) {
            *(undefined ***)(this + 0x20) = &::cBgS_PolyInfo::__vt;
          }
          cBgS_Chk::_cBgS_Chk((cBgS_Chk *)this);
        }
      }
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dCamera_c::lineBGCheck(cXyz *,
                                     cXyz *,
                                     dBgS_LinChk *,
                                     unsigned long) */

bool __thiscall
dCamera_c::lineBGCheck
          (dCamera_c *this,cXyz *param_1,cXyz *param_2,dBgS_LinChk *param_3,ulong param_4)

{
  char cVar1;
  
  if ((param_4 & 0x80) == 0) {
    (param_3->mPolyPassChk).parent.mbObjThrough = 0;
    (param_3->mPolyPassChk).parent.mbCamThrough = 1;
  }
  else {
    (param_3->mPolyPassChk).parent.mbCamThrough = 0;
    (param_3->mPolyPassChk).parent.mbObjThrough = 1;
  }
  ::dBgS_LinChk::Set(param_3,param_1,param_2,(fopAc_ac_c *)0x0);
  if ((param_4 & 4) == 0) {
    (param_3->parent).mFlags = (param_3->parent).mFlags | 0x20000000;
  }
  else {
    (param_3->parent).mFlags = (param_3->parent).mFlags & 0xdfffffff;
  }
  if ((param_4 & 2) == 0) {
    (param_3->parent).mFlags = (param_3->parent).mFlags | 0x40000000;
  }
  else {
    (param_3->parent).mFlags = (param_3->parent).mFlags & 0xbfffffff;
  }
  if ((param_4 & 1) == 0) {
    (param_3->parent).mFlags = (param_3->parent).mFlags | 0x80000000;
  }
  else {
    (param_3->parent).mFlags = (param_3->parent).mFlags & 0x7fffffff;
  }
  if ((param_4 & 8) == 0) {
    (param_3->mGrpPassChk).parent.mAttr = (param_3->mGrpPassChk).parent.mAttr & 0xfffffffd;
  }
  else {
    (param_3->mGrpPassChk).parent.mAttr = (param_3->mGrpPassChk).parent.mAttr | 2;
  }
  cVar1 = cBgS::LineCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,&param_3->parent);
  return cVar1 != '\0';
}


/* WARNING: Inlined function: __save_gpr */
/* WARNING: Inlined function: __restore_gpr */
/* __thiscall dCamera_c::lineBGCheck(cXyz *,
                                     cXyz *,
                                     cXyz *,
                                     unsigned long) */

undefined4 __thiscall
dCamera_c::lineBGCheck(dCamera_c *this,cXyz *param_1,cXyz *param_2,cXyz *param_3,ulong param_4)

{
  char cVar2;
  undefined4 uVar1;
  cBgS_PolyPassChk *pcVar3;
  undefined local_b8 [104];
  uint local_50;
  
  local_b8._0_4_ = (cBgS_PolyPassChk *)0x0;
  local_b8._4_4_ = (cBgS_PolyPassChk *)0x0;
  local_b8[12] = true;
  local_b8._20_2_ = -1;
  local_b8._22_2_ = 0x100;
  local_b8._24_4_ = (cBgW *)0x0;
  local_b8._28_4_ = -1;
  local_b8._16_4_ = &::cBgS_LinChk::__vt;
  local_b8._32_4_ = &PTR_80371fbc;
  local_b8._60_4_ = &::cM3dGLin::__vt;
  ::cBgS_LinChk::ct((cBgS_LinChk *)local_b8);
  pcVar3 = (cBgS_PolyPassChk *)(local_b8 + 0x58);
  local_b8[92] = 0;
  local_b8[94] = 0;
  local_b8[95] = 0;
  local_b8[96] = 0;
  local_b8[97] = 0;
  local_b8[98] = 0;
  local_b8._4_4_ = pcVar3;
  if (pcVar3 != (cBgS_PolyPassChk *)0x0) {
    local_b8._4_4_ = (cBgS_PolyPassChk *)(local_b8 + 100);
  }
  local_b8[93] = 1;
  local_b8._16_4_ = (undefined **)&dBgS_CamLinChk_NorWtr::__vt;
  local_b8._32_4_ = (undefined **)&DAT_803910b0;
  local_b8._88_4_ = (undefined **)&DAT_803910bc;
  local_b8._100_4_ = (undefined **)&DAT_803910c8;
  local_50 = 3;
  local_b8._0_4_ = pcVar3;
  cVar2 = lineBGCheck(this,param_1,param_2,(dBgS_LinChk *)local_b8,param_4);
  if (cVar2 == '\0') {
    param_3->x = param_2->x;
    param_3->y = param_2->y;
    param_3->z = param_2->z;
    local_b8._88_4_ = &PTR_80371f44;
    local_b8._100_4_ = &PTR_80371f50;
    if (pcVar3 != (cBgS_PolyPassChk *)0x0) {
      local_b8._88_4_ = &::dBgS_Chk::__vt;
      local_b8._100_4_ = &PTR_80371f68;
      if (((undefined *)register0x00000004 != (undefined *)0x54) &&
         (local_b8._100_4_ = &::dBgS_GrpPassChk::__vt,
         (undefined *)register0x00000004 != (undefined *)0x54)) {
        local_b8._100_4_ = &::cBgS_GrpPassChk::__vt;
      }
      if ((pcVar3 != (cBgS_PolyPassChk *)0x0) &&
         (local_b8._88_4_ = &::dBgS_PolyPassChk::__vt, pcVar3 != (cBgS_PolyPassChk *)0x0)) {
        local_b8._88_4_ = &::cBgS_PolyPassChk::__vt;
      }
    }
    local_b8._16_4_ = &::cBgS_LinChk::__vt;
    local_b8._60_4_ = &::cM3dGLin::__vt;
    local_b8._32_4_ = &::cBgS_PolyInfo::__vt;
    cBgS_Chk::_cBgS_Chk((cBgS_Chk *)local_b8);
    uVar1 = 0;
  }
  else {
    param_3->x = local_b8._48_4_;
    param_3->y = local_b8._52_4_;
    param_3->z = local_b8._56_4_;
    local_b8._88_4_ = &PTR_80371f44;
    local_b8._100_4_ = &PTR_80371f50;
    if (pcVar3 != (cBgS_PolyPassChk *)0x0) {
      local_b8._88_4_ = &::dBgS_Chk::__vt;
      local_b8._100_4_ = &PTR_80371f68;
      if (((undefined *)register0x00000004 != (undefined *)0x54) &&
         (local_b8._100_4_ = &::dBgS_GrpPassChk::__vt,
         (undefined *)register0x00000004 != (undefined *)0x54)) {
        local_b8._100_4_ = &::cBgS_GrpPassChk::__vt;
      }
      if ((pcVar3 != (cBgS_PolyPassChk *)0x0) &&
         (local_b8._88_4_ = &::dBgS_PolyPassChk::__vt, pcVar3 != (cBgS_PolyPassChk *)0x0)) {
        local_b8._88_4_ = &::cBgS_PolyPassChk::__vt;
      }
    }
    local_b8._16_4_ = &::cBgS_LinChk::__vt;
    if ((undefined *)register0x00000004 != (undefined *)0x94) {
      local_b8._60_4_ = &::cM3dGLin::__vt;
    }
    local_b8._32_4_ = &::cBgS_PolyInfo::__vt;
    cBgS_Chk::_cBgS_Chk((cBgS_Chk *)local_b8);
    uVar1 = 1;
  }
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f08 */
/* WARNING: Inlined function: FUN_80328f54 */
/* __thiscall dCamera_c::lineBGCheck(cXyz *,
                                     cXyz *,
                                     unsigned long) */

undefined4 __thiscall
dCamera_c::lineBGCheck(dCamera_c *this,cXyz *param_1,cXyz *param_2,ulong param_3)

{
  undefined4 uVar1;
  cBgS_PolyPassChk *pcVar2;
  undefined local_b8 [104];
  uint local_50;
  
  local_b8._0_4_ = (cBgS_PolyPassChk *)0x0;
  local_b8._4_4_ = (cBgS_PolyPassChk *)0x0;
  local_b8[12] = true;
  local_b8._20_2_ = -1;
  local_b8._22_2_ = 0x100;
  local_b8._24_4_ = (cBgW *)0x0;
  local_b8._28_4_ = -1;
  local_b8._16_4_ = &::cBgS_LinChk::__vt;
  local_b8._32_4_ = &PTR_80371fbc;
  local_b8._60_4_ = &::cM3dGLin::__vt;
  ::cBgS_LinChk::ct((cBgS_LinChk *)local_b8);
  pcVar2 = (cBgS_PolyPassChk *)(local_b8 + 0x58);
  local_b8[92] = 0;
  local_b8[94] = 0;
  local_b8[95] = 0;
  local_b8[96] = 0;
  local_b8[97] = 0;
  local_b8[98] = 0;
  local_b8._4_4_ = pcVar2;
  if (pcVar2 != (cBgS_PolyPassChk *)0x0) {
    local_b8._4_4_ = (cBgS_PolyPassChk *)(local_b8 + 100);
  }
  local_b8[93] = 1;
  local_b8._16_4_ = (undefined **)&dBgS_CamLinChk_NorWtr::__vt;
  local_b8._32_4_ = (undefined **)&DAT_803910b0;
  local_b8._88_4_ = (undefined **)&DAT_803910bc;
  local_b8._100_4_ = (undefined **)&DAT_803910c8;
  local_50 = 3;
  local_b8._0_4_ = pcVar2;
  uVar1 = lineBGCheck(this,param_1,param_2,(dBgS_LinChk *)local_b8,param_3);
  local_b8._88_4_ = &PTR_80371f44;
  local_b8._100_4_ = &PTR_80371f50;
  if (pcVar2 != (cBgS_PolyPassChk *)0x0) {
    local_b8._88_4_ = &::dBgS_Chk::__vt;
    local_b8._100_4_ = &PTR_80371f68;
    if (((undefined *)register0x00000004 != (undefined *)0x54) &&
       (local_b8._100_4_ = &::dBgS_GrpPassChk::__vt,
       (undefined *)register0x00000004 != (undefined *)0x54)) {
      local_b8._100_4_ = &::cBgS_GrpPassChk::__vt;
    }
    if ((pcVar2 != (cBgS_PolyPassChk *)0x0) &&
       (local_b8._88_4_ = &::dBgS_PolyPassChk::__vt, pcVar2 != (cBgS_PolyPassChk *)0x0)) {
      local_b8._88_4_ = &::cBgS_PolyPassChk::__vt;
    }
  }
  local_b8._16_4_ = &::cBgS_LinChk::__vt;
  local_b8._60_4_ = &::cM3dGLin::__vt;
  local_b8._32_4_ = &::cBgS_PolyInfo::__vt;
  cBgS_Chk::_cBgS_Chk((cBgS_Chk *)local_b8);
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f08 */
/* WARNING: Inlined function: FUN_80328f54 */
/* __thiscall dCamera_c::lineBGCheckBack(cXyz *,
                                         cXyz *,
                                         unsigned long) */

undefined4 __thiscall
dCamera_c::lineBGCheckBack(dCamera_c *this,cXyz *param_1,cXyz *param_2,ulong param_3)

{
  undefined4 uVar1;
  cBgS_PolyPassChk *pcVar2;
  undefined local_b8 [104];
  uint local_50;
  
  local_b8._0_4_ = (cBgS_PolyPassChk *)0x0;
  local_b8._4_4_ = (cBgS_PolyPassChk *)0x0;
  local_b8[12] = true;
  local_b8._20_2_ = -1;
  local_b8._22_2_ = 0x100;
  local_b8._24_4_ = (cBgW *)0x0;
  local_b8._28_4_ = -1;
  local_b8._16_4_ = &::cBgS_LinChk::__vt;
  local_b8._32_4_ = &PTR_80371fbc;
  local_b8._60_4_ = &::cM3dGLin::__vt;
  ::cBgS_LinChk::ct((cBgS_LinChk *)local_b8);
  pcVar2 = (cBgS_PolyPassChk *)(local_b8 + 0x58);
  local_b8[92] = 0;
  local_b8[94] = 0;
  local_b8[95] = 0;
  local_b8[96] = 0;
  local_b8[97] = 0;
  local_b8[98] = 0;
  local_b8._4_4_ = pcVar2;
  if (pcVar2 != (cBgS_PolyPassChk *)0x0) {
    local_b8._4_4_ = (cBgS_PolyPassChk *)(local_b8 + 100);
  }
  local_b8[93] = 1;
  local_b8._16_4_ = (undefined **)&dBgS_CamLinChk_NorWtr::__vt;
  local_b8._32_4_ = (undefined **)&DAT_803910b0;
  local_b8._88_4_ = (undefined **)&DAT_803910bc;
  local_b8._100_4_ = (undefined **)&DAT_803910c8;
  local_50 = 3;
  local_b8[84] = 1;
  local_b8[83] = 0;
  local_b8._0_4_ = pcVar2;
  uVar1 = lineBGCheck(this,param_1,param_2,(dBgS_LinChk *)local_b8,param_3);
  local_b8._88_4_ = &PTR_80371f44;
  local_b8._100_4_ = &PTR_80371f50;
  if (pcVar2 != (cBgS_PolyPassChk *)0x0) {
    local_b8._88_4_ = &::dBgS_Chk::__vt;
    local_b8._100_4_ = &PTR_80371f68;
    if (((undefined *)register0x00000004 != (undefined *)0x54) &&
       (local_b8._100_4_ = &::dBgS_GrpPassChk::__vt,
       (undefined *)register0x00000004 != (undefined *)0x54)) {
      local_b8._100_4_ = &::cBgS_GrpPassChk::__vt;
    }
    if ((pcVar2 != (cBgS_PolyPassChk *)0x0) &&
       (local_b8._88_4_ = &::dBgS_PolyPassChk::__vt, pcVar2 != (cBgS_PolyPassChk *)0x0)) {
      local_b8._88_4_ = &::cBgS_PolyPassChk::__vt;
    }
  }
  local_b8._16_4_ = &::cBgS_LinChk::__vt;
  local_b8._60_4_ = &::cM3dGLin::__vt;
  local_b8._32_4_ = &::cBgS_PolyInfo::__vt;
  cBgS_Chk::_cBgS_Chk((cBgS_Chk *)local_b8);
  return uVar1;
}


/* __thiscall dCamera_c::lineBGCheckBoth(cXyz *,
                                         cXyz *,
                                         dBgS_LinChk *,
                                         unsigned long) */

void __thiscall
dCamera_c::lineBGCheckBoth
          (dCamera_c *this,cXyz *param_1,cXyz *param_2,dBgS_LinChk *param_3,ulong param_4)

{
  (param_3->parent).field_0x54 = 1;
  (param_3->parent).field_0x53 = 1;
  lineBGCheck(this,param_1,param_2,param_3,param_4);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dCamera_c::lineCollisionCheckBush(cXyz *,
                                                cXyz *) */

byte __thiscall dCamera_c::lineCollisionCheckBush(dCamera_c *this,cXyz *param_1,cXyz *param_2)

{
  uint uVar1;
  byte bVar2;
  cM3dGCps camCps;
  
  uVar1 = dCcMassS_Mng::GetResultCam(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.mMassMng);
  bVar2 = (uVar1 & 2) != 0;
  if ((uVar1 & 4) != 0) {
    bVar2 = bVar2 | 2;
  }
  if ((uVar1 & 8) != 0) {
    bVar2 = bVar2 | 4;
  }
  camCps.parent.vtbl = (undefined *)&::cM3dGCps::__vt;
  camCps.parent.mP0.x = param_1->x;
  camCps.parent.mP0.y = param_1->y;
  camCps.parent.mP0.z = param_1->z;
  camCps.parent.mP1.x = param_2->x;
  camCps.parent.mP1.y = param_2->y;
  camCps.parent.mP1.z = param_2->z;
  camCps.mRadius = d_camera::30_0;
  dCcMassS_Mng::SetCam(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.mMassMng,&camCps);
  return bVar2;
}


namespace d_camera {

/* WARNING: Removing unreachable block (ram,0x80166e84) */
/* __stdcall sph_chk_callback(dBgS_SphChk *,
                              cBgD_Vtx_t *,
                              int,
                              int,
                              int,
                              cM3dGPla *,
                              void *) */

void sph_chk_callback(void)

{
  cM3dGPla *in_r8;
  int in_r9;
  undefined4 uVar1;
  double dVar2;
  double dVar3;
  undefined8 in_f31;
  cXyz cStack56;
  cXyz local_2c;
  undefined auStack8 [8];
  
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  dVar2 = (double)SComponent::cM3d_SignedLenPlaAndPos(in_r8,(cXyz *)(in_r9 + 8));
  dVar3 = (double)mtx::PSVECDotProduct(in_r8,in_r9 + 0x14);
  if ((_7767 <= (float)((double)in_r8->mDist + dVar3)) && (dVar2 < (double)*(float *)(in_r9 + 4))) {
    local_2c.x = (in_r8->mNorm).x;
    local_2c.y = (in_r8->mNorm).y;
    local_2c.z = (in_r8->mNorm).z;
    ::cXyz::operator_(&cStack56,&local_2c,(float)((double)*(float *)(in_r9 + 4) - dVar2));
    mtx::PSVECAdd((cXyz *)(in_r9 + 8),&cStack56,(cXyz *)(in_r9 + 8));
  }
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  return;
}

}

/* WARNING: Inlined function: FUN_80328f10 */
/* WARNING: Inlined function: FUN_80328f5c */
/* WARNING: Removing unreachable block (ram,0x80167274) */
/* __thiscall dCamera_c::compWallMargin(cXyz *,
                                        float) */

void __thiscall dCamera_c::compWallMargin(dCamera_c *this,cXyz *param_1,float param_2)

{
  char cVar1;
  cXyz *in_r5;
  cBgS_PolyPassChk *pcVar2;
  undefined4 uVar3;
  double dVar4;
  undefined8 in_f31;
  undefined local_c8 [4];
  float local_c4;
  camera_class *local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  undefined auStack168 [72];
  uint local_60;
  code *local_5c;
  undefined auStack8 [8];
  
  dVar4 = (double)param_2;
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  auStack168[48] = true;
  pcVar2 = (cBgS_PolyPassChk *)(auStack168 + 0x38);
  auStack168[60] = 0;
  auStack168[62] = 0;
  auStack168[63] = 0;
  auStack168[64] = 0;
  auStack168[65] = 0;
  auStack168[66] = 0;
  local_60 = 1;
  auStack168._40_4_ = pcVar2;
  if (pcVar2 != (cBgS_PolyPassChk *)0x0) {
    auStack168._40_4_ = (cBgS_PolyPassChk *)(auStack168 + 0x44);
  }
  auStack168._44_4_ = -1;
  auStack168._20_2_ = -1;
  auStack168._22_2_ = 0x100;
  auStack168._24_4_ = (cBgW *)0x0;
  auStack168._28_4_ = -1;
  auStack168._16_4_ = (undefined **)&dBgS_CamSphChk::__vt;
  auStack168._32_4_ = (undefined **)&DAT_80390ff0;
  auStack168._52_4_ = (cBgS_Chk__vtbl *)&DAT_80390ffc;
  auStack168._56_4_ = (undefined **)&DAT_80391008;
  auStack168._68_4_ = (undefined **)&DAT_80391014;
  auStack168[61] = 1;
  local_c0 = (camera_class *)in_r5->x;
  local_bc = in_r5->y;
  local_b8 = in_r5->z;
  local_b4 = param_1[5].z;
  local_b0 = param_1[6].x;
  local_ac = param_1[6].y;
  local_5c = d_camera::sph_chk_callback;
  local_c4 = param_2;
  auStack168._36_4_ = pcVar2;
  ::cM3dGSph::SetC((cM3dGSph *)auStack168,in_r5);
  ::cM3dGSph::SetR((cM3dGSph *)auStack168,(float)dVar4);
  cVar1 = dBgS::SphChk(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,(dBgS_SphChk *)auStack168,
                       local_c8);
  if (cVar1 == '\0') {
    this->mpCamera = (camera_class *)in_r5->x;
    *(float *)&this->field_0x4 = in_r5->y;
    this->field_0x8 = in_r5->z;
    auStack168._16_4_ = &dBgS_SphChk::__vt;
    auStack168._32_4_ = &PTR_8039102c;
    auStack168._52_4_ = (cBgS_Chk__vtbl *)&DAT_80391038;
    auStack168._56_4_ = &PTR_80391044;
    auStack168._68_4_ = (undefined **)&DAT_80391050;
    if (pcVar2 != (cBgS_PolyPassChk *)0x0) {
      auStack168._56_4_ = &::dBgS_Chk::__vt;
      auStack168._68_4_ = &PTR_80371f68;
      if (((undefined *)register0x00000004 != (undefined *)0x64) &&
         (auStack168._68_4_ = &::dBgS_GrpPassChk::__vt,
         (undefined *)register0x00000004 != (undefined *)0x64)) {
        auStack168._68_4_ = &::cBgS_GrpPassChk::__vt;
      }
      if ((pcVar2 != (cBgS_PolyPassChk *)0x0) &&
         (auStack168._56_4_ = &::dBgS_PolyPassChk::__vt, pcVar2 != (cBgS_PolyPassChk *)0x0)) {
        auStack168._56_4_ = &::cBgS_PolyPassChk::__vt;
      }
    }
    cBgS_Chk::_cBgS_Chk((cBgS_Chk *)(auStack168 + 0x24));
  }
  else {
    this->mpCamera = local_c0;
    *(float *)&this->field_0x4 = local_bc;
    this->field_0x8 = local_b8;
    auStack168._16_4_ = &dBgS_SphChk::__vt;
    auStack168._32_4_ = &PTR_8039102c;
    auStack168._52_4_ = (cBgS_Chk__vtbl *)&DAT_80391038;
    auStack168._56_4_ = &PTR_80391044;
    auStack168._68_4_ = (undefined **)&DAT_80391050;
    if (pcVar2 != (cBgS_PolyPassChk *)0x0) {
      auStack168._56_4_ = &::dBgS_Chk::__vt;
      auStack168._68_4_ = &PTR_80371f68;
      if (((undefined *)register0x00000004 != (undefined *)0x64) &&
         (auStack168._68_4_ = &::dBgS_GrpPassChk::__vt,
         (undefined *)register0x00000004 != (undefined *)0x64)) {
        auStack168._68_4_ = &::cBgS_GrpPassChk::__vt;
      }
      if ((pcVar2 != (cBgS_PolyPassChk *)0x0) &&
         (auStack168._56_4_ = &::dBgS_PolyPassChk::__vt, pcVar2 != (cBgS_PolyPassChk *)0x0)) {
        auStack168._56_4_ = &::cBgS_PolyPassChk::__vt;
      }
    }
    cBgS_Chk::_cBgS_Chk((cBgS_Chk *)(auStack168 + 0x24));
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return;
}


/* __thiscall dBgS_CamSphChk::~dBgS_CamSphChk(void) */

void __thiscall dBgS_CamSphChk::_dBgS_CamSphChk(dBgS_CamSphChk *this)

{
  short in_r4;
  
  if (this != (dBgS_CamSphChk *)0x0) {
    *(undefined1 **)(this + 0x10) = &__vt;
    *(undefined **)(this + 0x20) = &DAT_80390ff0;
    *(undefined **)(this + 0x34) = &DAT_80390ffc;
    *(undefined **)(this + 0x38) = &DAT_80391008;
    *(undefined **)(this + 0x44) = &DAT_80391014;
    if (this != (dBgS_CamSphChk *)0x0) {
      *(undefined ***)(this + 0x10) = &dBgS_SphChk::__vt;
      *(undefined ***)(this + 0x20) = &PTR_8039102c;
      *(undefined **)(this + 0x34) = &DAT_80391038;
      *(undefined ***)(this + 0x38) = &PTR_80391044;
      *(undefined **)(this + 0x44) = &DAT_80391050;
      if (this != (dBgS_CamSphChk *)0xffffffc8) {
        *(undefined ***)(this + 0x38) = &::dBgS_Chk::__vt;
        *(undefined ***)(this + 0x44) = &PTR_80371f68;
        if (this != (dBgS_CamSphChk *)0xffffffbc) {
          *(undefined ***)(this + 0x44) = &::dBgS_GrpPassChk::__vt;
          if (this != (dBgS_CamSphChk *)0xffffffbc) {
            *(undefined ***)(this + 0x44) = &::cBgS_GrpPassChk::__vt;
          }
        }
        if (this != (dBgS_CamSphChk *)0xffffffc8) {
          *(undefined ***)(this + 0x38) = &::dBgS_PolyPassChk::__vt;
          if (this != (dBgS_CamSphChk *)0xffffffc8) {
            *(undefined ***)(this + 0x38) = &::cBgS_PolyPassChk::__vt;
          }
        }
      }
      cBgS_Chk::_cBgS_Chk((cBgS_Chk *)(this + 0x24));
      if (this != (dBgS_CamSphChk *)0xffffffec) {
        *(undefined ***)(this + 0x20) = &::cBgS_PolyInfo::__vt;
      }
      if (this != (dBgS_CamSphChk *)0x0) {
        *(undefined ***)(this + 0x10) = &::cM3dGSph::__vt;
      }
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dBgS_SphChk::~dBgS_SphChk(void) */

void __thiscall dBgS_SphChk::_dBgS_SphChk(dBgS_SphChk *this)

{
  short in_r4;
  
  if (this != (dBgS_SphChk *)0x0) {
    (this->mSph).vtbl = (undefined *)&__vt;
    (this->mPolyInfo).vtbl = (cBgS_PolyInfo__vtbl *)&PTR_8039102c;
    (this->mChk).vtbl = (cBgS_Chk__vtbl *)&DAT_80391038;
    (this->mDChk).mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80391044;
    (this->mDChk).mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&DAT_80391050;
    if (this != (dBgS_SphChk *)0xffffffc8) {
      (this->mDChk).mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
      (this->mDChk).mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_80371f68;
      if (this != (dBgS_SphChk *)0xffffffbc) {
        (this->mDChk).mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&::dBgS_GrpPassChk::__vt;
        if (this != (dBgS_SphChk *)0xffffffbc) {
          (this->mDChk).mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&::cBgS_GrpPassChk::__vt;
        }
      }
      if (this != (dBgS_SphChk *)0xffffffc8) {
        (this->mDChk).mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt
        ;
        if (this != (dBgS_SphChk *)0xffffffc8) {
          (this->mDChk).mPolyPassChk.parent.vtbl =
               (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
        }
      }
    }
    cBgS_Chk::_cBgS_Chk(&this->mChk);
    if (this != (dBgS_SphChk *)0xffffffec) {
      (this->mPolyInfo).vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
    }
    if (this != (dBgS_SphChk *)0x0) {
      (this->mSph).vtbl = (undefined *)&::cM3dGSph::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dCamera_c::defaultTriming(void) */

int __thiscall dCamera_c::defaultTriming(dCamera_c *this)

{
  if (*(int *)&this->field_0x600 < 0) {
    if ((this->mpPlayerActor->parent).parent.mProcName == 0xa9) {
      switch(this->mCurMode) {
      default:
        this->field_0x5fc = 0;
        break;
      case 1:
      case 2:
      case 8:
        this->field_0x5fc = 1;
        break;
      case 3:
        this->field_0x5fc = 2;
        break;
      case 4:
        this->field_0x5fc = 0;
        break;
      case 10:
      case 0xb:
        if (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4] & 0x40000U) == 0)
        {
          if (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4] & 0xa5000U) != 0
             ) {
            this->field_0x5fc = 1;
          }
        }
        else {
          this->field_0x5fc = 2;
        }
        break;
      case 0xc:
        if ((this->mEventFlags & 0x1000) == 0) {
          this->field_0x5fc = 0;
        }
        else {
          this->field_0x5fc = 1;
        }
      }
    }
    else {
      this->field_0x5fc = 1;
    }
  }
  else {
    this->field_0x5fc = *(int *)&this->field_0x600;
  }
  return this->field_0x5fc;
}


/* WARNING: Removing unreachable block (ram,0x8016769c) */
/* WARNING: Removing unreachable block (ram,0x8016768c) */
/* WARNING: Removing unreachable block (ram,0x80167694) */
/* WARNING: Removing unreachable block (ram,0x801676a4) */
/* __thiscall dCamera_c::setView(float,
                                 float,
                                 float,
                                 float) */

void __thiscall
dCamera_c::setView(dCamera_c *this,float param_1,float param_2,float param_3,float param_4)

{
  int iVar1;
  dDlst_window_c *this_00;
  undefined4 uVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  undefined8 in_f28;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar6 = (double)param_4;
  dVar5 = (double)param_3;
  dVar4 = (double)param_2;
  dVar3 = (double)param_1;
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  iVar1 = f_op_camera_mng::fopCamM_GetParam(this->mpCamera);
  iVar1 = (char)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[iVar1].mDlstWindowIdx * 0x2c;
  this_00 = (dDlst_window_c *)((int)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mDlstWindow + iVar1);
  dDlst_window_c::setViewPort
            (this_00,(float)dVar3,(float)dVar4,(float)dVar5,(float)dVar6,
             *(float *)((int)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mDlstWindow + iVar1 + 0x10),
             *(float *)((int)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mDlstWindow + iVar1 + 0x14));
  dDlst_window_c::setScissor(this_00,(float)dVar3,(float)dVar4,(float)dVar5,(float)dVar6);
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  __psq_l0(auStack24,uVar2);
  __psq_l1(auStack24,uVar2);
  __psq_l0(auStack40,uVar2);
  __psq_l1(auStack40,uVar2);
  __psq_l0(auStack56,uVar2);
  __psq_l1(auStack56,uVar2);
  return;
}


namespace dCamera_c {

/* WARNING: Inlined function: FUN_80328f08 */
/* WARNING: Inlined function: FUN_80328f54 */
/* WARNING: Removing unreachable block (ram,0x80167ee0) */
/* WARNING: Removing unreachable block (ram,0x80167ee8) */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall forwardCheckAngle(void) */

void forwardCheckAngle(cSAngle *param_1,dCamera_c *param_2)

{
  int iVar1;
  undefined *puVar2;
  fopAc_ac_c *pfVar3;
  short sVar5;
  char cVar6;
  cSAngle *pcVar4;
  cBgS_PolyPassChk *pcVar7;
  undefined4 uVar8;
  double dVar9;
  undefined8 in_f30;
  double dVar10;
  undefined8 in_f31;
  double dVar11;
  float fVar12;
  cSAngle local_238 [2];
  cSAngle acStack564 [2];
  cSAngle local_230 [2];
  cSAngle acStack556 [2];
  cSAngle local_228 [2];
  cSAngle local_224 [2];
  cSAngle local_220 [2];
  cSAngle local_21c [2];
  cSAngle local_218 [2];
  cSAngle local_214 [2];
  cSAngle local_210 [2];
  cSAngle local_20c;
  cSAngle local_208;
  cSAngle local_204 [2];
  float local_200;
  float local_1fc;
  cSGlobe cStack504;
  cSGlobe cStack496;
  cSGlobe cStack488;
  cSGlobe cStack480;
  cXyz cStack472;
  cXyz local_1cc;
  cXyz cStack448;
  cXyz cStack436;
  cXyz local_1a8;
  cXyz local_19c;
  cXyz cStack400;
  cXyz cStack388;
  cXyz local_178;
  cXyz cStack364;
  cXyz cStack352;
  cXyz local_154;
  cXyz local_148;
  cXyz cStack316;
  cXyz local_130;
  cXyz local_124;
  cXyz local_118;
  cXyz local_10c;
  cXyz local_100;
  cXyz local_f4;
  cXyz local_e8;
  cBgS_LinChk local_dc;
  cBgS_PolyPassChk local_84;
  undefined local_78 [8];
  longlong local_70;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar8 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  local_dc.parent.mpPolyPassChk = (cBgS_PolyPassChk *)0x0;
  local_dc.parent.mpGrpPassChk = (cBgS_GrpPassChk *)0x0;
  local_dc.parent.mbExcludeSameProcID = true;
  local_dc.mPolyInfo.mTriIdx = -1;
  local_dc.mPolyInfo.mBgIndex = 0x100;
  local_dc.mPolyInfo.mpBgW = (cBgW *)0x0;
  local_dc.mPolyInfo.mProcID = -1;
  local_dc.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_LinChk::__vt;
  local_dc.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&PTR_80371fbc;
  local_dc.mLin.vtbl = (undefined *)&::cM3dGLin::__vt;
  ::cBgS_LinChk::ct(&local_dc);
  pcVar7 = &local_84;
  local_84.mbObjThrough = 0;
  local_84.mbLinkThrough = 0;
  local_84.mbArrowsAndLightThrough = 0;
  local_84.mbBombThrough = 0;
  local_84.mbBoomerangThrough = 0;
  local_84.mbHookshotThrough = 0;
  local_dc.parent.mpGrpPassChk = (cBgS_GrpPassChk *)pcVar7;
  if (pcVar7 != (cBgS_PolyPassChk *)0x0) {
    local_dc.parent.mpGrpPassChk = (cBgS_GrpPassChk *)local_78;
  }
  local_84.mbCamThrough = 1;
  local_dc.parent.vtbl = (cBgS_Chk__vtbl *)&dBgS_CamLinChk_NorWtr::__vt;
  local_dc.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&DAT_803910b0;
  local_84.vtbl = (cBgS_PolyPassChk__vtbl *)&DAT_803910bc;
  local_78._0_4_ = (undefined **)&DAT_803910c8;
  local_78._4_4_ = 3;
  local_dc.parent.mpPolyPassChk = pcVar7;
  cSAngle::cSAngle(local_204,&cSAngle::_0);
  positionOf(&local_130,param_2,param_2->mpPlayerActor);
  local_e8.x = local_130.x;
  local_e8.z = local_130.z;
  pfVar3 = param_2->mpPlayerActor;
  if ((pfVar3->parent).parent.mProcName == 0xa9) {
    puVar2 = pfVar3[1].parent.parent.mLyTg.parent.parent.mpData;
  }
  else {
    puVar2 = (undefined *)(d_camera::_8357 * ((pfVar3->mEyePos).y - (pfVar3->mCurrent).mPos.y));
  }
  dVar11 = (double)(float)puVar2;
  local_e8.y = (float)((double)local_130.y + dVar11);
  iVar1 = (int)(d_camera::_8358 * (param_2->mCamSetup).mBGChk.field_0x8);
  local_70 = (longlong)iVar1;
  cSAngle::cSAngle(local_210,(short)iVar1);
  dVar10 = (double)(param_2->mCamSetup).mBGChk.field_0x4;
  sVar5 = cSAngle::Inv(&param_2->field_0xe);
  cSGlobe::cSGlobe(&cStack480,(float)(dVar11 * dVar10),local_210[0],sVar5);
  cSGlobe::Xyz(&cStack316,&cStack480);
  ::cXyz::operator__(&local_148,&local_e8,&cStack316);
  local_100.x = local_148.x;
  local_100.y = local_148.y;
  local_100.z = local_148.z;
  cVar6 = lineBGCheck(param_2,&local_e8,&local_100,&local_f4,0x7f);
  if (cVar6 != '\0') {
    ::cXyz::operator__(&local_154,&local_100,&local_e8);
    local_10c.x = local_154.x;
    local_10c.y = local_154.y;
    local_10c.z = local_154.z;
    fVar12 = mtx::PSVECSquareMag(&local_10c);
    dVar10 = (double)fVar12;
    if ((double)d_camera::0_0 < dVar10) {
      dVar9 = 1.0 / SQRT(dVar10);
      dVar9 = d_camera::_5735 * dVar9 * (d_camera::_5736 - dVar10 * dVar9 * dVar9);
      dVar9 = d_camera::_5735 * dVar9 * (d_camera::_5736 - dVar10 * dVar9 * dVar9);
      local_1fc = (float)(dVar10 * d_camera::_5735 * dVar9 *
                                   (d_camera::_5736 - dVar10 * dVar9 * dVar9));
      dVar10 = (double)local_1fc;
    }
    if ((double)d_camera::1_0 <= dVar10) {
      ::cXyz::norm(&cStack352);
      ::cXyz::operator_(&cStack364,&cStack352,(param_2->mCamSetup).mBGChk.field_0x24);
      ::cXyz::operator__(&local_178,&local_f4,&cStack364);
      local_100.x = local_178.x;
      local_100.y = local_178.y;
      local_100.z = local_178.z;
    }
    else {
      local_100.x = local_f4.x;
      local_100.y = local_f4.y;
      local_100.z = local_f4.z;
    }
  }
  local_f4.x = local_100.x;
  local_f4.y = local_100.y;
  local_f4.z = local_100.z;
  dVar10 = (double)groundHeight(param_2,&local_100);
  local_f4.y = (float)(dVar11 + dVar10);
  ::cXyz::operator__(&cStack388,&local_f4,&local_e8);
  cSGlobe::cSGlobe(&cStack488,&cStack388);
  if (cStack488.mAngleX < cSAngle::_0) {
    cSAngle::operator_(local_21c,(param_2->mCamSetup).mBGChk.field_0x10);
    local_208 = local_21c[0];
  }
  else {
    cSAngle::operator_(local_218,(param_2->mCamSetup).mBGChk.field_0xc);
    local_208 = local_218[0];
  }
  iVar1 = (int)(d_camera::_8358 * (param_2->mCamSetup).mBGChk.field_0x18);
  local_70 = (longlong)iVar1;
  cSAngle::cSAngle(local_214,(short)iVar1);
  dVar10 = (double)(param_2->mCamSetup).mBGChk.field_0x14;
  sVar5 = cSAngle::Inv(&param_2->field_0xe);
  cSGlobe::cSGlobe(&cStack496,(float)(dVar11 * dVar10),local_214[0],sVar5);
  cSGlobe::Xyz(&cStack400,&cStack496);
  ::cXyz::operator__(&local_19c,&local_e8,&cStack400);
  local_118.x = local_19c.x;
  local_118.y = local_19c.y;
  local_118.z = local_19c.z;
  cVar6 = lineBGCheck(param_2,&local_e8,&local_118,&local_f4,0x7f);
  if (cVar6 != '\0') {
    ::cXyz::operator__(&local_1a8,&local_118,&local_e8);
    local_124.x = local_1a8.x;
    local_124.y = local_1a8.y;
    local_124.z = local_1a8.z;
    fVar12 = mtx::PSVECSquareMag(&local_124);
    dVar10 = (double)fVar12;
    if ((double)d_camera::0_0 < dVar10) {
      dVar9 = 1.0 / SQRT(dVar10);
      dVar9 = d_camera::_5735 * dVar9 * (d_camera::_5736 - dVar10 * dVar9 * dVar9);
      dVar9 = d_camera::_5735 * dVar9 * (d_camera::_5736 - dVar10 * dVar9 * dVar9);
      local_200 = (float)(dVar10 * d_camera::_5735 * dVar9 *
                                   (d_camera::_5736 - dVar10 * dVar9 * dVar9));
      dVar10 = (double)local_200;
    }
    if ((double)d_camera::1_0 <= dVar10) {
      ::cXyz::norm(&cStack436);
      ::cXyz::operator_(&cStack448,&cStack436,(param_2->mCamSetup).mBGChk.field_0x24);
      ::cXyz::operator__(&local_1cc,&local_f4,&cStack448);
      local_118.x = local_1cc.x;
      local_118.y = local_1cc.y;
      local_118.z = local_1cc.z;
    }
    else {
      local_118.x = local_f4.x;
      local_118.y = local_f4.y;
      local_118.z = local_f4.z;
    }
  }
  local_f4.x = local_118.x;
  local_f4.y = local_118.y;
  local_f4.z = local_118.z;
  dVar10 = (double)groundHeight(param_2,&local_118);
  local_f4.y = (float)(dVar11 + dVar10);
  ::cXyz::operator__(&cStack472,&local_f4,&local_e8);
  cSGlobe::cSGlobe(&cStack504,&cStack472);
  if (cStack504.mAngleX < cSAngle::_0) {
    cSAngle::operator_(local_224,(param_2->mCamSetup).mBGChk.field_0x20);
    local_20c = local_224[0];
  }
  else {
    cSAngle::operator_(local_220,(param_2->mCamSetup).mBGChk.field_0x1c);
    local_20c = local_220[0];
  }
  if ((local_208 < cSAngle::_0) || (local_20c < cSAngle::_0)) {
    if ((cSAngle::_0 < local_208) || (cSAngle::_0 < local_20c)) {
      cSAngle::operator__(local_238);
      local_204[0] = local_238[0];
    }
    else {
      if (local_20c < local_208) {
        cSAngle::operator__(acStack564);
        pcVar4 = acStack564;
      }
      else {
        cSAngle::operator__(local_230);
        pcVar4 = local_230;
      }
      local_204[0] = pcVar4->v;
    }
  }
  else {
    if (local_208 < local_20c) {
      cSAngle::operator__(acStack556);
      pcVar4 = acStack556;
    }
    else {
      cSAngle::operator__(local_228);
      pcVar4 = local_228;
    }
    local_204[0] = pcVar4->v;
  }
  if (local_204[0] <= cSAngle::_0) {
    cSAngle::operator__(local_204,d_camera::_8359);
  }
  cSAngle::cSAngle(param_1,local_204);
  local_84.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f44;
  local_78._0_4_ = &PTR_80371f50;
  if (pcVar7 != (cBgS_PolyPassChk *)0x0) {
    local_84.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
    local_78._0_4_ = &PTR_80371f68;
    if (((undefined *)register0x00000004 != (undefined *)0x78) &&
       (local_78._0_4_ = &::dBgS_GrpPassChk::__vt,
       (undefined *)register0x00000004 != (undefined *)0x78)) {
      local_78._0_4_ = &::cBgS_GrpPassChk::__vt;
    }
    if ((pcVar7 != (cBgS_PolyPassChk *)0x0) &&
       (local_84.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
       pcVar7 != (cBgS_PolyPassChk *)0x0)) {
      local_84.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
    }
  }
  local_dc.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_LinChk::__vt;
  local_dc.mLin.vtbl = (undefined *)&::cM3dGLin::__vt;
  local_dc.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
  cBgS_Chk::_cBgS_Chk(&local_dc.parent);
  __psq_l0(auStack8,uVar8);
  __psq_l1(auStack8,uVar8);
  __psq_l0(auStack24,uVar8);
  __psq_l1(auStack24,uVar8);
  return;
}

}

/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x80168d1c) */
/* WARNING: Removing unreachable block (ram,0x80168d0c) */
/* WARNING: Removing unreachable block (ram,0x80168d04) */
/* WARNING: Removing unreachable block (ram,0x80168d14) */
/* WARNING: Removing unreachable block (ram,0x80168d24) */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall dCamera_c::bumpCheck(unsigned long) */

bool __thiscall dCamera_c::bumpCheck(dCamera_c *this,ulong param_1)

{
  float fVar1;
  short sVar2;
  int iVar3;
  fopAc_ac_c *pfVar4;
  uint uVar5;
  char cVar6;
  cM3dGPla *this_00;
  cM3dGPla *pcVar7;
  uint uVar8;
  undefined4 uVar9;
  double dVar10;
  double dVar11;
  undefined8 in_f27;
  undefined8 in_f28;
  double dVar12;
  undefined8 in_f29;
  double dVar13;
  undefined8 in_f30;
  double dVar14;
  undefined8 in_f31;
  cSAngle local_458 [2];
  cSAngle local_454 [2];
  cSAngle local_450 [2];
  cSAngle local_44c [2];
  cSAngle local_448 [2];
  cSAngle local_444 [2];
  cSAngle acStack1088 [2];
  cSAngle local_43c [2];
  cSAngle acStack1080 [2];
  cSAngle acStack1076 [2];
  cSAngle local_430 [2];
  cSAngle local_42c [2];
  cSAngle acStack1064 [2];
  cSAngle acStack1060 [2];
  cSAngle local_420 [2];
  cSAngle acStack1052 [2];
  cSAngle acStack1048 [2];
  cSAngle acStack1044 [2];
  cSAngle acStack1040 [2];
  cSAngle acStack1036 [2];
  cSAngle local_408 [2];
  int local_404;
  cDegree acStack1024 [4];
  cSGlobe local_3fc;
  cSGlobe local_3f4;
  cSGlobe local_3ec;
  cSGlobe cStack996;
  cSGlobe local_3dc;
  cXyz cStack980;
  camera_class *local_3c8;
  float local_3c4;
  float local_3c0;
  cXyz local_3bc;
  cXyz cStack944;
  cXyz cStack932;
  cXyz local_398;
  cXyz cStack908;
  cXyz cStack896;
  cXyz local_374;
  cXyz cStack872;
  cXyz cStack860;
  camera_class *local_350;
  float local_34c;
  float local_348;
  cXyz cStack836;
  cXyz cStack824;
  cXyz cStack812;
  cXyz cStack800;
  camera_class *local_314;
  float local_310;
  float local_30c;
  cXyz cStack776;
  cXyz cStack764;
  camera_class *local_2f0;
  float local_2ec;
  float local_2e8;
  camera_class *local_2e4;
  float local_2e0;
  float local_2dc;
  cXyz local_2d8;
  cXyz cStack716;
  cXyz local_2c0;
  cXyz cStack692;
  cXyz cStack680;
  cXyz local_29c;
  cXyz cStack656;
  cXyz local_284;
  cXyz local_278;
  cXyz cStack620;
  cXyz cStack608;
  cXyz local_254;
  cXyz cStack584;
  cXyz cStack572;
  cXyz local_230;
  cXyz cStack548;
  fopAc_ac_c *local_218;
  float local_214;
  fopAc_ac_c *local_210;
  cXyz local_20c;
  fopAc_ac_c *local_200;
  float local_1fc;
  fopAc_ac_c *local_1f8;
  fopAc_ac_c *local_1f4;
  float local_1f0;
  fopAc_ac_c *local_1ec;
  cXyz local_1e8;
  cXyz local_1dc;
  cXyz local_1d0;
  fopAc_ac_c *local_1c4;
  float local_1c0;
  fopAc_ac_c *local_1bc;
  cXyz local_1b8;
  cXyz local_1ac;
  cXyz local_1a0;
  cXyz local_194;
  TVec3_float_ TStack392;
  cXyz local_17c;
  float local_170;
  float local_16c;
  float local_168;
  cXyz cStack356;
  cXyz local_158;
  dBgS_LinChk dStack332;
  dBgS_LinChk dStack224;
  int local_70;
  uint uStack108;
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar9 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  __psq_st0(auStack72,(int)((ulonglong)in_f27 >> 0x20),0);
  __psq_st1(auStack72,(int)in_f27,0);
  if (d_camera::init_8382 == '\0') {
    d_camera::prev_hit_type_8381 = 0;
    d_camera::init_8382 = '\x01';
  }
  if (d_camera::init_8385 == '\0') {
    d_camera::prev_plat1_8384 = 0;
    d_camera::init_8385 = '\x01';
  }
  if (d_camera::init_8388 == '\0') {
    d_camera::prev_plat2_8387 = 0;
    d_camera::init_8388 = '\x01';
  }
  uVar8 = 0;
  dVar14 = (double)(this->mCamSetup).mBGChk.field_0x30;
  dVar13 = (double)(this->mCamSetup).mBGChk.field_0x34;
  cDegree::cDegree(acStack1024,(this->mCamSetup).mBGChk.field_0x44);
  dVar10 = (double)cDegree::Cos(acStack1024);
  dVar12 = (double)(this->mCamSetup).mBGChk.field_0x3c;
  if ((((this->mpPlayerActor->parent).parent.mProcName == 0xa9) &&
      (iVar3 = (**(code **)(*(int *)&this->mpPlayerActor[1].parent.parent.mPi.mMtdTg.parent.mbAdded
                           + 0x58))(), iVar3 != -1)) &&
     (local_404 = iVar3,
     pfVar4 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,&local_404),
     pfVar4 != (fopAc_ac_c *)0x0)) {
    sVar2 = (pfVar4->parent).parent.mProcName;
    if (sVar2 == 0x1cb) {
      uVar5 = ::daObj::PrmAbstract(pfVar4,4,0x18);
      if ((int)uVar5 < 9) {
        if ((int)uVar5 < 5) {
          if (0 < (int)uVar5) {
LAB_80168064:
            dVar12 = (double)d_camera::_9002;
            goto LAB_80168098;
          }
        }
        else {
          if (6 < (int)uVar5) goto LAB_80168064;
        }
      }
      else {
        if (((int)uVar5 < 0x10) && (0xc < (int)uVar5)) goto LAB_80168064;
      }
      dVar12 = (double)d_camera::_9003;
    }
    else {
      if (sVar2 == 0x171) {
        dVar12 = (double)d_camera::130_0;
      }
      else {
        if (sVar2 == 0x1d0) {
          dVar12 = (double)d_camera::_5129;
        }
        else {
          dVar12 = (double)d_camera::_9003;
        }
      }
    }
  }
LAB_80168098:
  local_158.x = (this->field_0x50).x;
  local_158.y = (this->field_0x50).y;
  local_158.z = (this->field_0x50).z;
  cSGlobe::cSGlobe(&local_3dc,&this->field_0x3c);
  if (((this->mEventFlags & 0x2000) != 0) && (this->mpLockonTarget != (fopAc_ac_c *)0x0)) {
    dVar11 = (double)radiusActorInSight(this,this->mpPlayerActor,this->mpLockonTarget);
    if (dVar11 <= (double)d_camera::0_0) {
      this->field_0x14c = this->field_0x14c - d_camera::_9006 * this->field_0x14c;
    }
    else {
      if ((double)d_camera::_9004 <= dVar11) {
        dVar11 = (double)d_camera::_9004;
      }
      this->field_0x14c =
           (float)((double)this->field_0x14c +
                  (double)(d_camera::_9005 * (float)(dVar11 - (double)this->field_0x14c)));
      uVar8 = 0x40;
    }
    uVar5 = this->field_0x108;
    fVar1 = d_camera::1_0;
    if (uVar5 < 10) {
      local_70 = 0x43300000;
      fVar1 = (float)((double)CONCAT44(0x43300000,uVar5) - d_camera::_9014) / d_camera::_6064;
      uStack108 = uVar5;
    }
    local_3dc.mDistance = this->field_0x14c * fVar1 + local_3dc.mDistance;
    cSGlobe::Xyz(&cStack548,&local_3dc);
    ::cXyz::operator__(&local_230,&this->field_0x44,&cStack548);
    local_158.x = local_230.x;
    local_158.y = local_230.y;
    local_158.z = local_230.z;
  }
  if (((param_1 & 0x40) != 0) && (*(int *)&this->field_0x364 != 0)) {
    ::cXyz::operator__(&cStack572,(cXyz *)&this->field_0x36c,&this->field_0x44);
    cSGlobe::cSGlobe(&cStack996,&cStack572);
    if (local_3dc.mAngleX < cStack996.mAngleX) {
      cSAngle::cSAngle(local_408,(cSAngle *)&this->field_0xc);
      cSAngle::operator__(acStack1040,&cStack996.mAngleX);
      cSAngle::operator_(acStack1044,d_camera::_5311);
      cSAngle::operator___(local_408,acStack1044);
      cSAngle::cSAngle(local_444,local_408[0]);
      local_3dc.mAngleX = local_444[0];
      cSGlobe::Xyz(&cStack584,&local_3dc);
      ::cXyz::operator__(&local_254,&this->field_0x44,&cStack584);
      local_158.x = local_254.x;
      local_158.y = local_254.y;
      local_158.z = local_254.z;
      uVar8 = uVar8 | 0x20;
    }
  }
  dBgS_CamLinChk_NorWtr::dBgS_CamLinChk_NorWtr((dBgS_CamLinChk_NorWtr *)&dStack224);
  dBgS_CamLinChk_NorWtr::dBgS_CamLinChk_NorWtr((dBgS_CamLinChk_NorWtr *)&dStack332);
  cVar6 = lineBGCheck(this,&this->mCenter,&local_158,&dStack224,param_1);
  if (cVar6 == '\0') {
    uVar5 = 0;
    if ((this->mEventFlags & 0x4000) == 0) {
      (this->mEye).x = local_158.x;
      (this->mEye).y = local_158.y;
      (this->mEye).z = local_158.z;
      this->field_0x8 = local_3dc.mDistance;
      ((cSAngle *)&this->field_0xc)->v = local_3dc.mAngleX;
      (this->field_0xe).v = local_3dc.mAngleY;
    }
    else {
      fVar1 = d_camera::_9011;
      if ((param_1 & 0x10) != 0) {
        fVar1 = (this->mCamSetup).mBGChk.field_0x40;
      }
      dVar10 = (double)fVar1;
      this->field_0x8 =
           this->field_0x8 +
           (float)(dVar10 * (double)((this->field_0x3c).mDistance - this->field_0x8));
      cSAngle::operator__(acStack1076,&(this->field_0x3c).mAngleX);
      cSAngle::operator_(acStack1080,(float)dVar10);
      cSAngle::operator__(local_43c,(cSAngle *)&this->field_0xc);
      cSAngle::cSAngle(local_454,local_43c[0]);
      ((cSAngle *)&this->field_0xc)->v = local_454[0];
      cSAngle::cSAngle(local_458,(this->field_0x3c).mAngleY.v);
      (this->field_0xe).v = local_458[0];
      cSGlobe::Xyz(&cStack944,(cSGlobe *)&this->field_0x8);
      ::cXyz::operator__(&local_3bc,&this->mCenter,&cStack944);
      (this->mEye).x = local_3bc.x;
      (this->mEye).y = local_3bc.y;
      (this->mEye).z = local_3bc.z;
      cVar6 = lineBGCheck(this,&this->mCenter,&this->mEye,&dStack224,param_1);
      if (cVar6 != '\0') {
        local_218 = (fopAc_ac_c *)dStack224.parent.mLin.mP1.x;
        local_214 = dStack224.parent.mLin.mP1.y;
        local_210 = (fopAc_ac_c *)dStack224.parent.mLin.mP1.z;
        compWallMargin((dCamera_c *)&local_3c8,(cXyz *)this,
                       (float)((double)d_camera::_6431 + dVar14));
        (this->mEye).x = (float)local_3c8;
        (this->mEye).y = local_3c4;
        (this->mEye).z = local_3c0;
      }
      cSAngle::operator__(acStack1088,(cSAngle *)&this->field_0xc);
      cSAngle::cSAngle(acStack1036,acStack1088);
      dVar10 = (double)cSAngle::Degree(acStack1036);
      if ((float)ABS(dVar10) < d_camera::_9011) {
        this->mEventFlags = this->mEventFlags & 0xffffbfff;
      }
    }
    goto LAB_80168c48;
  }
  this_00 = cBgS::GetTriPla((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                            (uint)(ushort)dStack224.parent.mPolyInfo.mBgIndex,
                            (uint)(ushort)dStack224.parent.mPolyInfo.mTriIdx);
  pcVar7 = (cM3dGPla *)0x0;
  if ((param_1 & 0x20) == 0) {
    uVar5 = 2;
  }
  else {
    cVar6 = lineBGCheck(this,&local_158,&this->mCenter,&dStack332,param_1);
    if (cVar6 == '\0') {
      if ((d_camera::prev_hit_type_8381 == 3) || (d_camera::prev_hit_type_8381 == 5)) {
        uVar5 = 5;
      }
      else {
        uVar5 = 2;
      }
    }
    else {
      pcVar7 = cBgS::GetTriPla((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                               (uint)(ushort)dStack332.parent.mPolyInfo.mBgIndex,
                               (uint)(ushort)dStack332.parent.mPolyInfo.mTriIdx);
      dVar11 = (double)mtx::PSVECDotProduct(this_00,pcVar7);
      mtx::PSVECCrossProduct(&this_00->mNorm,&pcVar7->mNorm,&TStack392);
      if ((dVar11 <= dVar10) || (ABS(TStack392.y) <= d_camera::_6431)) {
        if (d_camera::prev_hit_type_8381 == 3) {
          uVar5 = 5;
        }
        else {
          uVar5 = 4;
        }
      }
      else {
        uVar5 = 3;
      }
    }
  }
  if (uVar5 == 3) {
    uVar8 = uVar8 | 2;
    local_194.x = dStack224.parent.mLin.mP1.x;
    local_194.y = dStack224.parent.mLin.mP1.y;
    local_194.z = dStack224.parent.mLin.mP1.z;
    local_1a0.x = dStack332.parent.mLin.mP1.x;
    local_1a0.y = dStack332.parent.mLin.mP1.y;
    local_1a0.z = dStack332.parent.mLin.mP1.z;
    ::cXyz::operator__(&cStack608,&local_1a0,&local_194);
    ::cXyz::operator_(&cStack620,&cStack608,d_camera::_6431);
    ::cXyz::operator__(&local_278,&local_194,&cStack620);
    local_170 = local_278.x;
    local_16c = local_278.y;
    local_168 = local_278.z;
    iVar3 = SComponent::cM3d_2PlaneLinePosNearPos(this_00,pcVar7,&local_170,&cStack356);
    if (iVar3 != 0) {
      ::cXyz::operator__(&local_284,(cXyz *)this_00,(cXyz *)pcVar7);
      local_17c.x = local_284.x;
      local_17c.y = local_284.y;
      local_17c.z = local_284.z;
      ::cXyz::operator_(&cStack656,&local_17c,d_camera::_9007);
      ::cXyz::operator__(&local_29c,&cStack356,&cStack656);
      *(float *)&this->field_0x70 = local_29c.x;
      *(float *)&this->field_0x74 = local_29c.y;
      *(float *)&this->field_0x78 = local_29c.z;
      ::cXyz::operator__(&cStack680,(cXyz *)&this->field_0x70,&this->mCenter);
      cSGlobe::Val(&local_3ec,&cStack680);
      this->field_0x8 = local_3dc.mDistance;
      cSAngle::operator__(acStack1048,&local_3ec.mAngleX);
      cSAngle::operator_(acStack1052,d_camera::_5311);
      cSAngle::operator__(local_420,(cSAngle *)&this->field_0xc);
      cSAngle::cSAngle(local_448,local_420[0]);
      ((cSAngle *)&this->field_0xc)->v = local_448[0];
      cSAngle::operator__(acStack1060,&local_3ec.mAngleY);
      cSAngle::operator_(acStack1064,(float)dVar13);
      cSAngle::operator__(local_42c,&this->field_0xe);
      cSAngle::cSAngle(local_44c,local_42c[0]);
      (this->field_0xe).v = local_44c[0];
      cSGlobe::Xyz(&cStack692,(cSGlobe *)&this->field_0x8);
      ::cXyz::operator__(&local_2c0,&this->mCenter,&cStack692);
      local_1ac.x = local_2c0.x;
      local_1ac.y = local_2c0.y;
      local_1ac.z = local_2c0.z;
      local_3ec.mDistance = d_camera::_5573 + local_3ec.mDistance;
      cSGlobe::Xyz(&cStack716,&local_3ec);
      ::cXyz::operator__(&local_2d8,&this->mCenter,&cStack716);
      local_1b8.x = local_2d8.x;
      local_1b8.y = local_2d8.y;
      local_1b8.z = local_2d8.z;
      cVar6 = lineBGCheck(this,&this->mCenter,&local_1b8,0x7f);
      if (cVar6 == '\0') {
        cVar6 = lineBGCheck(this,(cXyz *)&this->field_0x70,&local_1ac,&dStack224,0x7f);
        if (cVar6 != '\0') {
          local_1c4 = (fopAc_ac_c *)dStack224.parent.mLin.mP1.x;
          local_1c0 = dStack224.parent.mLin.mP1.y;
          local_1bc = (fopAc_ac_c *)dStack224.parent.mLin.mP1.z;
          compWallMargin((dCamera_c *)&local_2e4,(cXyz *)this,(float)dVar14);
          local_1ac.x = (float)local_2e4;
          local_1ac.y = local_2e0;
          local_1ac.z = local_2dc;
        }
        lineBGCheck(this,&this->mCenter,&local_1ac,&dStack224,param_1);
        (this->mEye).x = local_1ac.x;
        (this->mEye).y = local_1ac.y;
        (this->mEye).z = local_1ac.z;
        this->mEventFlags = this->mEventFlags | 0x80000;
        goto LAB_80168c48;
      }
      uVar5 = 2;
    }
LAB_801686a0:
    this->mEventFlags = this->mEventFlags | 0x80;
    this->mEventFlags = this->mEventFlags | 0x80;
    local_1d0.x = dStack224.parent.mLin.mP1.x;
    local_1d0.y = dStack224.parent.mLin.mP1.y;
    local_1d0.z = dStack224.parent.mLin.mP1.z;
    compWallMargin((dCamera_c *)&local_2f0,(cXyz *)this,(float)((double)d_camera::_6431 + dVar14));
    local_1dc.x = (float)local_2f0;
    local_1dc.y = local_2ec;
    local_1dc.z = local_2e8;
    local_1e8.x = (float)local_2f0;
    local_1e8.y = local_2ec;
    local_1e8.z = local_2e8;
    if ((((this->mEventFlags & 8) == 0) || ((param_1 & 0x10) == 0)) || (uVar5 == 4)) {
      (this->mEye).x = (float)local_2f0;
      (this->mEye).y = local_2ec;
      (this->mEye).z = local_2e8;
    }
    else {
      dVar10 = (double)dCamMath::xyzHorizontalDistance(&local_1d0,&this->mCenter);
      attentionPos(&cStack764,this,this->mpPlayerActor);
      fVar1 = (this->mCenter).y;
      dVar12 = (double)(float)(dVar12 - (double)(fVar1 - cStack764.y));
      if ((double)d_camera::_9008 <= dVar10) {
        if (dVar10 <= (double)d_camera::320_0) {
          dVar12 = (double)(float)(dVar12 * (double)(d_camera::1_0 -
                                                    (float)(dVar10 - (double)d_camera::_9008) /
                                                    d_camera::_9009));
        }
        else {
          dVar12 = (double)d_camera::0_0;
        }
      }
      if (dVar12 <= (double)(local_1dc.y - fVar1)) {
        cVar6 = lineBGCheck(this,&local_1e8,&local_1dc,&dStack224,param_1);
        if (cVar6 != '\0') {
          local_200 = (fopAc_ac_c *)dStack224.parent.mLin.mP1.x;
          local_1fc = dStack224.parent.mLin.mP1.y;
          local_1f8 = (fopAc_ac_c *)dStack224.parent.mLin.mP1.z;
          compWallMargin((dCamera_c *)&local_350,(cXyz *)this,(float)dVar14);
          local_1dc.x = (float)local_350;
          local_1dc.y = local_34c;
          local_1dc.z = local_348;
        }
        ::cXyz::operator__(&cStack860,&local_1dc,&this->mEye);
        ::cXyz::operator_(&cStack872,&cStack860,(this->mCamSetup).mBGChk.field_0x40);
        mtx::PSVECAdd(&this->mEye,&cStack872,&this->mEye);
      }
      else {
        local_17c.x = (this_00->mNorm).x;
        local_17c.y = (this_00->mNorm).y;
        local_17c.z = (this_00->mNorm).z;
        cSGlobe::cSGlobe(&local_3f4,&local_17c);
        cSAngle::operator__(local_430,&local_3f4.mAngleX);
        cSAngle::cSAngle(local_450,local_430[0]);
        local_3f4.mAngleX = local_450[0];
        dVar10 = (double)cSAngle::Sin(&local_3f4.mAngleX);
        local_3f4.mDistance = (float)(dVar12 * dVar10);
        cSGlobe::Xyz(&cStack776,&local_3f4);
        mtx::PSVECAdd(&local_1dc,&cStack776,&local_1dc);
        cVar6 = lineBGCheck(this,&local_1e8,&local_1dc,&dStack224,param_1);
        if (cVar6 == '\0') {
          ::cXyz::operator__(&cStack824,&local_1dc,&this->mEye);
          ::cXyz::operator_(&cStack836,&cStack824,(this->mCamSetup).mBGChk.field_0x38);
          mtx::PSVECAdd(&this->mEye,&cStack836,&this->mEye);
        }
        else {
          local_1f4 = (fopAc_ac_c *)dStack224.parent.mLin.mP1.x;
          local_1f0 = dStack224.parent.mLin.mP1.y;
          local_1ec = (fopAc_ac_c *)dStack224.parent.mLin.mP1.z;
          compWallMargin((dCamera_c *)&local_314,(cXyz *)this,(float)dVar14);
          local_1dc.x = (float)local_314;
          local_1dc.y = local_310;
          local_1dc.z = local_30c;
          ::cXyz::operator__(&cStack800,&local_1dc,&this->mEye);
          ::cXyz::operator_(&cStack812,&cStack800,(this->mCamSetup).mBGChk.field_0x38);
          mtx::PSVECAdd(&this->mEye,&cStack812,&this->mEye);
        }
        this->mEventFlags = this->mEventFlags | 0x4000;
      }
    }
    iVar3 = ((this->mCamParam).mpStyle)->mEngineIdx;
    if ((iVar3 == 1) || (iVar3 == 10)) {
      attentionPos(&local_374,this,this->mpPlayerActor);
      local_20c.x = local_374.x;
      local_20c.y = local_374.y;
      local_20c.z = local_374.z;
      ::cXyz::operator__(&cStack896,&this->mEye,&local_20c);
      cSGlobe::cSGlobe(&local_3fc,&cStack896);
      if (local_3fc.mDistance < d_camera::_9010) {
        local_3fc.mDistance = d_camera::_9010;
        cSGlobe::Xyz(&cStack908,&local_3fc);
        ::cXyz::operator__(&local_398,&local_20c,&cStack908);
        (this->mEye).x = local_398.x;
        (this->mEye).y = local_398.y;
        (this->mEye).z = local_398.z;
      }
    }
    ::cXyz::operator__(&cStack932,&this->mEye,&this->mCenter);
    cSGlobe::Val((cSGlobe *)&this->field_0x8,&cStack932);
    uVar8 = uVar8 | 1;
  }
  else {
    if (uVar5 < 3) {
      if (1 < uVar5) goto LAB_801686a0;
    }
    else {
      if (uVar5 < 6) goto LAB_801686a0;
    }
    (this->mEye).x = local_158.x;
    (this->mEye).y = local_158.y;
    (this->mEye).z = local_158.z;
    this->field_0x8 = local_3dc.mDistance;
    ((cSAngle *)&this->field_0xc)->v = local_3dc.mAngleX;
    (this->field_0xe).v = local_3dc.mAngleY;
  }
LAB_80168c48:
  if (((param_1 & 8) != 0) &&
     (dVar10 = (double)getWaterSurfaceHeight(this,&this->mEye), (double)(this->mEye).y < dVar10)) {
    (this->mEye).y = (float)dVar10;
    ::cXyz::operator__(&cStack980,&this->mEye,&this->mCenter);
    cSGlobe::Val((cSGlobe *)&this->field_0x8,&cStack980);
    uVar8 = uVar8 | 8;
  }
  d_camera::prev_hit_type_8381 = uVar5;
  if ((*(char *)&this->field_0x78b != '\0') &&
     ((dCamParam_c::styles[this->mCurStyle].mEngineIdx != 4 ||
      ((this->mEventFlags & 0x10000800) == 0)))) {
    (this->mEye).y = (this->mEye).y + d_camera::_9012;
  }
  dBgS_CamLinChk_NorWtr::_dBgS_CamLinChk_NorWtr((dBgS_CamLinChk_NorWtr *)&dStack332);
  dBgS_CamLinChk_NorWtr::_dBgS_CamLinChk_NorWtr((dBgS_CamLinChk_NorWtr *)&dStack224);
  __psq_l0(auStack8,uVar9);
  __psq_l1(auStack8,uVar9);
  __psq_l0(auStack24,uVar9);
  __psq_l1(auStack24,uVar9);
  __psq_l0(auStack40,uVar9);
  __psq_l1(auStack40,uVar9);
  __psq_l0(auStack56,uVar9);
  __psq_l1(auStack56,uVar9);
  __psq_l0(auStack72,uVar9);
  __psq_l1(auStack72,uVar9);
  return uVar8 != 0;
}


/* __thiscall dBgS_CamLinChk_NorWtr::dBgS_CamLinChk_NorWtr(void) */

void __thiscall dBgS_CamLinChk_NorWtr::dBgS_CamLinChk_NorWtr(dBgS_CamLinChk_NorWtr *this)

{
  dBgS_CamLinChk_NorWtr *pdVar1;
  
  *(cBgS_Chk__vtbl **)(this + 0x10) = &cBgS_Chk::__vt;
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  this[0xc] = (dBgS_CamLinChk_NorWtr)0x1;
  *(undefined ***)(this + 0x20) = &::cBgS_PolyInfo::__vt;
  *(undefined2 *)(this + 0x14) = 0xffff;
  *(undefined2 *)(this + 0x16) = 0x100;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = 0xffffffff;
  *(undefined ***)(this + 0x10) = &::cBgS_LinChk::__vt;
  *(undefined ***)(this + 0x20) = &PTR_80371fbc;
  *(undefined ***)(this + 0x3c) = &::cM3dGLin::__vt;
  ::cBgS_LinChk::ct((cBgS_LinChk *)this);
  *(undefined ***)(this + 0x58) = &::cBgS_PolyPassChk::__vt;
  *(undefined ***)(this + 0x58) = &::dBgS_PolyPassChk::__vt;
  this[0x5c] = (dBgS_CamLinChk_NorWtr)0x0;
  this[0x5d] = (dBgS_CamLinChk_NorWtr)0x0;
  this[0x5e] = (dBgS_CamLinChk_NorWtr)0x0;
  this[0x5f] = (dBgS_CamLinChk_NorWtr)0x0;
  this[0x60] = (dBgS_CamLinChk_NorWtr)0x0;
  this[0x61] = (dBgS_CamLinChk_NorWtr)0x0;
  this[0x62] = (dBgS_CamLinChk_NorWtr)0x0;
  *(undefined ***)(this + 100) = &::cBgS_GrpPassChk::__vt;
  *(undefined ***)(this + 100) = &::dBgS_GrpPassChk::__vt;
  *(undefined4 *)(this + 0x68) = 1;
  *(undefined ***)(this + 0x58) = &::dBgS_Chk::__vt;
  *(undefined ***)(this + 100) = &PTR_80371f68;
  *(undefined ***)(this + 0x10) = &::dBgS_LinChk::__vt;
  *(undefined **)(this + 0x20) = &DAT_80371f38;
  *(undefined ***)(this + 0x58) = &PTR_80371f44;
  *(undefined ***)(this + 100) = &PTR_80371f50;
  *(dBgS_CamLinChk_NorWtr **)this = this + 0x58;
  pdVar1 = this + 0x58;
  if (pdVar1 != (dBgS_CamLinChk_NorWtr *)0x0) {
    pdVar1 = this + 100;
  }
  *(dBgS_CamLinChk_NorWtr **)(this + 4) = pdVar1;
  *(undefined1 **)(this + 0x10) = &dBgS_CamLinChk::__vt;
  *(undefined **)(this + 0x20) = &DAT_803910e0;
  *(undefined **)(this + 0x58) = &DAT_803910ec;
  *(undefined **)(this + 100) = &DAT_803910f8;
  this[0x5d] = (dBgS_CamLinChk_NorWtr)0x1;
  *(undefined1 **)(this + 0x10) = &__vt;
  *(undefined **)(this + 0x20) = &DAT_803910b0;
  *(undefined **)(this + 0x58) = &DAT_803910bc;
  *(undefined **)(this + 100) = &DAT_803910c8;
  *(uint *)(this + 0x68) = *(uint *)(this + 0x68) | 2;
  *(uint *)(this + 0x68) = *(uint *)(this + 0x68) | 1;
  return;
}


/* WARNING: Inlined function: __save_gpr */
/* WARNING: Inlined function: __restore_gpr */
/* WARNING: Removing unreachable block (ram,0x8016938c) */
/* __thiscall dCamera_c::getWaterSurfaceHeight(cXyz *) */

double __thiscall dCamera_c::getWaterSurfaceHeight(dCamera_c *this,cXyz *param_1)

{
  uint uVar1;
  cBgS_PolyPassChk *pcVar2;
  cBgS_PolyPassChk *pcVar3;
  undefined4 uVar4;
  double dVar5;
  undefined8 in_f31;
  double dVar6;
  float local_104;
  cBgS_GndChk local_fc;
  cBgS_PolyPassChk local_bc;
  undefined local_b0 [8];
  undefined local_a8 [52];
  uint local_74;
  float local_70;
  float local_6c;
  float local_68;
  undefined4 local_64;
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  dVar6 = (double)d_camera::_5126;
  local_fc.mPos.x = param_1->x;
  local_104 = param_1->y;
  local_fc.mPos.z = param_1->z;
  local_a8._0_2_ = -1;
  local_a8._2_2_ = 0x100;
  local_a8._4_4_ = (cBgW *)0x0;
  local_a8._8_4_ = -1;
  local_a8[28] = true;
  pcVar3 = (cBgS_PolyPassChk *)(local_a8 + 0x24);
  local_a8[40] = 0;
  local_a8[41] = 0;
  local_a8[42] = 0;
  local_a8[43] = 0;
  local_a8[44] = 0;
  local_a8[45] = 0;
  local_a8[46] = 0;
  local_74 = 1;
  local_a8._12_4_ = &dBgS_RoofChk::__vt;
  local_a8._32_4_ = &PTR_8037d40c;
  local_a8._36_4_ = &PTR_8037d418;
  local_a8._48_4_ = &PTR_8037d424;
  local_a8._20_4_ = pcVar3;
  if (pcVar3 != (cBgS_PolyPassChk *)0x0) {
    local_a8._20_4_ = (cBgS_PolyPassChk *)(local_a8 + 0x30);
  }
  local_a8._24_4_ = -1;
  local_64 = 0;
  local_a8._16_4_ = pcVar3;
  local_70 = local_fc.mPos.x;
  local_6c = local_104;
  local_68 = local_fc.mPos.z;
  dVar5 = (double)dBgS::RoofChk(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,
                                (dBgS_RoofChk *)local_a8);
  if ((double)local_104 < dVar5) {
    local_104 = (float)dVar5;
  }
  ::cBgS_GndChk::cBgS_GndChk(&local_fc);
  pcVar2 = &local_bc;
  local_bc.mbObjThrough = 0;
  local_bc.mbLinkThrough = 0;
  local_bc.mbArrowsAndLightThrough = 0;
  local_bc.mbBombThrough = 0;
  local_bc.mbBoomerangThrough = 0;
  local_bc.mbHookshotThrough = 0;
  local_fc.parent.mpGrpPassChk = (cBgS_GrpPassChk *)pcVar2;
  if (pcVar2 != (cBgS_PolyPassChk *)0x0) {
    local_fc.parent.mpGrpPassChk = (cBgS_GrpPassChk *)local_b0;
  }
  local_bc.mbCamThrough = 1;
  local_fc.parent.vtbl = (cBgS_Chk__vtbl *)&dBgS_CamGndChk_Wtr::__vt;
  local_fc.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&DAT_80391080;
  local_bc.vtbl = (cBgS_PolyPassChk__vtbl *)&DAT_8039108c;
  local_b0._0_4_ = (undefined **)&DAT_80391098;
  local_b0._4_4_ = 2;
  local_fc.mPos.y = local_104;
  local_fc.parent.mpPolyPassChk = pcVar2;
  dVar5 = (double)cBgS::GroundCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,&local_fc);
  if ((double)param_1->y < (double)(float)((double)d_camera::_9194 + dVar5)) {
    dVar6 = (double)(float)((double)d_camera::_9194 + dVar5);
  }
  uVar1 = d_a_sea::daSea_ChkArea(param_1->x,param_1->z);
  if ((uVar1 & 0xff) != 0) {
    dVar5 = (double)d_a_sea::daSea_calcWave((double)param_1->x,(double)param_1->z);
    dVar5 = (double)(float)((double)d_camera::_9008 + dVar5);
    if (((double)param_1->y < dVar5) && (dVar6 < dVar5)) {
      dVar6 = dVar5;
    }
  }
  if ((double)d_camera::_5126 == dVar6) {
    dVar6 = (double)param_1->y;
  }
  local_bc.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
  local_b0._0_4_ = &PTR_80371f20;
  if (pcVar2 != (cBgS_PolyPassChk *)0x0) {
    local_bc.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
    local_b0._0_4_ = &PTR_80371f68;
    if (((undefined *)register0x00000004 != (undefined *)0xb0) &&
       (local_b0._0_4_ = &::dBgS_GrpPassChk::__vt,
       (undefined *)register0x00000004 != (undefined *)0xb0)) {
      local_b0._0_4_ = &::cBgS_GrpPassChk::__vt;
    }
    if ((pcVar2 != (cBgS_PolyPassChk *)0x0) &&
       (local_bc.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
       pcVar2 != (cBgS_PolyPassChk *)0x0)) {
      local_bc.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
    }
  }
  local_fc.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_GndChk::__vt;
  local_fc.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
  cBgS_Chk::_cBgS_Chk(&local_fc.parent);
  local_a8._12_4_ = &dBgS_RoofChk::__vt;
  local_a8._32_4_ = &PTR_8037d40c;
  local_a8._36_4_ = &PTR_8037d418;
  local_a8._48_4_ = &PTR_8037d424;
  if (pcVar3 != (cBgS_PolyPassChk *)0x0) {
    local_a8._36_4_ = &::dBgS_Chk::__vt;
    local_a8._48_4_ = &PTR_80371f68;
    if (((undefined *)register0x00000004 != (undefined *)0x78) &&
       (local_a8._48_4_ = &::dBgS_GrpPassChk::__vt,
       (undefined *)register0x00000004 != (undefined *)0x78)) {
      local_a8._48_4_ = &::cBgS_GrpPassChk::__vt;
    }
    if ((pcVar3 != (cBgS_PolyPassChk *)0x0) &&
       (local_a8._36_4_ = &::dBgS_PolyPassChk::__vt, pcVar3 != (cBgS_PolyPassChk *)0x0)) {
      local_a8._36_4_ = &::cBgS_PolyPassChk::__vt;
    }
  }
  cBgS_Chk::_cBgS_Chk((cBgS_Chk *)(local_a8 + 0x10));
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return dVar6;
}


/* __thiscall dCamera_c::checkSpecialArea(void) */

void __thiscall dCamera_c::checkSpecialArea(dCamera_c *this)

{
  double dVar1;
  cXyz local_28;
  cXyz local_1c;
  
  if (d_camera::init_9216 == '\0') {
    d_camera::ofan_9214 = d_camera::0_0;
    DAT_803e48d4 = d_camera::_9246;
    DAT_803e48d8 = d_camera::0_0;
    Runtime.PPCEABI.H::__register_global_object(&d_camera::ofan_9214,::cXyz::_cXyz,&d_camera::_9215)
    ;
    d_camera::init_9216 = '\x01';
  }
  if (d_camera::init_9219 == '\0') {
    d_camera::dfan_9218 = d_camera::_9247;
    d_camera::init_9219 = '\x01';
  }
  if (d_camera::init_9223 == '\0') {
    d_camera::opixy_9221 = d_camera::_9248;
    DAT_803e48ec = d_camera::_9249;
    DAT_803e48f0 = d_camera::_9250;
    Runtime.PPCEABI.H::__register_global_object
              (&d_camera::opixy_9221,::cXyz::_cXyz,&d_camera::_9222);
    d_camera::init_9223 = '\x01';
  }
  if (d_camera::init_9226 == '\0') {
    d_camera::dpixy_9225 = d_camera::_9251;
    d_camera::init_9226 = '\x01';
  }
  positionOf(&local_28,this,this->mpPlayerActor);
  local_1c.x = local_28.x;
  local_1c.y = local_28.y;
  local_1c.z = local_28.z;
  *(undefined *)&this->field_0x787 = 0;
  if ((*(char *)&this->field_0x788 != '\0') &&
     (dVar1 = (double)dCamMath::xyzHorizontalDistance((cXyz *)&d_camera::ofan_9214,&local_1c),
     dVar1 < (double)d_camera::dfan_9218)) {
    *(undefined *)&this->field_0x787 = 1;
  }
  *(undefined *)&this->field_0x786 = 0;
  if ((*(char *)&this->field_0x780 != '\0') &&
     (dVar1 = (double)dCamMath::xyzHorizontalDistance((cXyz *)&d_camera::opixy_9221,&local_1c),
     dVar1 < (double)d_camera::dpixy_9225)) {
    *(undefined *)&this->field_0x786 = 1;
  }
  return;
}


/* WARNING: Inlined function: __save_gpr */
/* WARNING: Inlined function: __restore_gpr */
/* WARNING: Removing unreachable block (ram,0x8016a0d0) */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall dCamera_c::checkGroundInfo(void) */

void __thiscall dCamera_c::checkGroundInfo(dCamera_c *this)

{
  undefined *puVar1;
  fopAc_ac_c *pfVar2;
  char cVar5;
  int iVar3;
  uint uVar4;
  cBgS_PolyPassChk *pcVar6;
  cBgS_PolyPassChk *pcVar7;
  cBgS_PolyPassChk *pcVar8;
  undefined4 uVar9;
  double dVar10;
  double dVar11;
  undefined8 in_f31;
  cSAngle local_218 [2];
  cSAngle acStack532 [2];
  cSAngle local_210 [2];
  cXyz cStack524;
  cXyz cStack512;
  cXyz local_1f4;
  cXyz cStack488;
  cXyz cStack476;
  cXyz local_1d0;
  cXyz cStack452;
  cXyz local_1b8;
  cXyz local_1ac;
  cXyz local_1a0;
  cXyz local_194;
  cXyz local_188;
  cXyz local_17c;
  float local_170;
  float local_16c;
  float local_168;
  float local_164;
  float local_160;
  float local_15c;
  cBgS_GndChk local_158;
  cBgS_PolyPassChk local_118;
  undefined local_10c [8];
  cBgS_GndChk local_104;
  cBgS_PolyPassChk local_c4;
  undefined local_b8 [8];
  undefined local_b0 [52];
  uint local_7c;
  float local_78;
  float local_74;
  float local_70;
  undefined4 local_6c;
  undefined auStack8 [8];
  
  uVar9 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  positionOf(&local_1a0,this,this->mpPlayerActor);
  local_164 = local_1a0.x;
  local_15c = local_1a0.z;
  local_170 = local_1a0.x;
  local_16c = local_1a0.y;
  local_168 = local_1a0.z;
  pfVar2 = this->mpPlayerActor;
  if ((pfVar2->parent).parent.mProcName == 0xa9) {
    puVar1 = pfVar2[1].parent.parent.mLyTg.parent.parent.mpData;
  }
  else {
    puVar1 = (undefined *)(d_camera::_8357 * ((pfVar2->mEyePos).y - (pfVar2->mCurrent).mPos.y));
  }
  local_160 = local_1a0.y + (float)puVar1;
  local_b0._0_2_ = -1;
  local_b0._2_2_ = 0x100;
  local_b0._4_4_ = (cBgW *)0x0;
  local_b0._8_4_ = -NAN;
  local_b0[28] = true;
  pcVar8 = (cBgS_PolyPassChk *)(local_b0 + 0x24);
  local_b0[40] = 0;
  local_b0[41] = 0;
  local_b0[42] = 0;
  local_b0[43] = 0;
  local_b0[44] = 0;
  local_b0[45] = 0;
  local_b0[46] = 0;
  local_7c = 1;
  local_b0._12_4_ = &dBgS_RoofChk::__vt;
  local_b0._32_4_ = &PTR_8037d40c;
  local_b0._36_4_ = &PTR_8037d418;
  local_b0._48_4_ = &PTR_8037d424;
  local_b0._20_4_ = pcVar8;
  if (pcVar8 != (cBgS_PolyPassChk *)0x0) {
    local_b0._20_4_ = (cBgS_PolyPassChk *)(local_b0 + 0x30);
  }
  local_b0._24_4_ = -NAN;
  local_6c = 0;
  local_78 = local_1a0.x;
  local_74 = local_1a0.y;
  local_70 = local_1a0.z;
  local_b0._16_4_ = pcVar8;
  dVar10 = (double)dBgS::RoofChk(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,
                                 (dBgS_RoofChk *)local_b0);
  if ((double)local_16c < dVar10) {
    local_16c = (float)dVar10;
  }
  ::cBgS_GndChk::cBgS_GndChk(&local_104);
  pcVar7 = &local_c4;
  local_c4.mbLinkThrough = 0;
  local_c4.mbArrowsAndLightThrough = 0;
  local_c4.mbBombThrough = 0;
  local_c4.mbBoomerangThrough = 0;
  local_c4.mbHookshotThrough = 0;
  local_b8._4_4_ = 1.401298e-45;
  local_104.parent.mpGrpPassChk = (cBgS_GrpPassChk *)pcVar7;
  if (pcVar7 != (cBgS_PolyPassChk *)0x0) {
    local_104.parent.mpGrpPassChk = (cBgS_GrpPassChk *)local_b8;
  }
  local_104.parent.vtbl = (cBgS_Chk__vtbl *)&dBgS_CamGndChk::__vt;
  local_104.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&DAT_80391200;
  local_c4.vtbl = (cBgS_PolyPassChk__vtbl *)&DAT_8039120c;
  local_b8._0_4_ = (undefined **)&DAT_80391218;
  local_c4.mbCamThrough = 0;
  local_c4.mbObjThrough = 1;
  local_104.mPos.x = local_164;
  local_104.mPos.y = local_160;
  local_104.mPos.z = local_15c;
  local_104.parent.mpPolyPassChk = pcVar7;
  dVar10 = (double)cBgS::GroundCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,&local_104);
  *(undefined *)&(this->mBG).field_0xa5 = 1;
  *(undefined *)&(this->mBG).field_0xa4 = 0;
  *(float *)&(this->mBG).field_0x84 = local_164;
  *(float *)&(this->mBG).field_0x88 = local_160;
  *(float *)&(this->mBG).field_0x8c = local_15c;
  dVar11 = (double)cBgS::GroundCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                                     (cBgS_GndChk *)&(this->mBG).field_0x60);
  *(float *)&this->field_0x310 = (float)dVar11;
  if ((double)*(float *)&this->field_0x310 < dVar10) {
    *(float *)&this->field_0x310 = (float)dVar10;
    *(cBgS_PolyPassChk **)&(this->mBG).field_0x60 = local_104.parent.mpPolyPassChk;
    *(cBgS_GrpPassChk **)&(this->mBG).field_0x64 = local_104.parent.mpGrpPassChk;
    *(int *)&(this->mBG).field_0x68 = local_104.parent.mProcID;
    *(bool *)&(this->mBG).field_0x6c = local_104.parent.mbExcludeSameProcID;
    (this->mBG).field_0x74.mTriIdx = local_104.mPolyInfo.mTriIdx;
    (this->mBG).field_0x74.mBgIndex = local_104.mPolyInfo.mBgIndex;
    (this->mBG).field_0x74.mpBgW = local_104.mPolyInfo.mpBgW;
    (this->mBG).field_0x74.mProcID = local_104.mPolyInfo.mProcID;
    *(float *)&(this->mBG).field_0x84 = local_104.mPos.x;
    *(float *)&(this->mBG).field_0x88 = local_104.mPos.y;
    *(float *)&(this->mBG).field_0x8c = local_104.mPos.z;
    *(uint *)&(this->mBG).field_0x90 = local_104.mFlagIn;
    *(float *)&(this->mBG).field_0x94 = local_104.mRetY;
    *(int *)&(this->mBG).field_0x98 = local_104.mbChkWall;
    *(uint *)&(this->mBG).field_0x9c = local_104.mbChkGnd;
    *(byte *)&(this->mBG).field_0xa4 = local_c4.mbObjThrough;
    *(byte *)&(this->mBG).field_0xa5 = local_c4.mbCamThrough;
    *(byte *)&(this->mBG).field_0xa6 = local_c4.mbLinkThrough;
    *(byte *)&(this->mBG).field_0xa7 = local_c4.mbArrowsAndLightThrough;
    *(byte *)&(this->mBG).field_0xa8 = local_c4.mbBombThrough;
    *(byte *)&(this->mBG).field_0xa9 = local_c4.mbBoomerangThrough;
    *(byte *)&(this->mBG).field_0xaa = local_c4.mbHookshotThrough;
    *(float *)&this->field_0x30c = local_b8._4_4_;
  }
  *(bool *)&(this->mBG).field_0x5c = d_camera::_5126 != *(float *)&this->field_0x310;
  *(float *)&(this->mBG).field_0x28 = local_170;
  *(float *)&(this->mBG).field_0x2c = local_16c;
  *(float *)&(this->mBG).field_0x30 = local_168;
  dVar10 = (double)cBgS::GroundCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                                     (cBgS_GndChk *)&(this->mBG).field_0x4);
  (this->mBG).field_0x58 = (float)dVar10;
  *(bool *)&this->mBG = d_camera::_5126 != (this->mBG).field_0x58;
  *(float *)&this->field_0x354 = (this->mBG).field_0x58;
  if ((this->mpPlayerActor->mCurrent).mPos.y - *(float *)&this->field_0x310 <=
      (this->mCamSetup).mBGChk.field_0x0) {
    *(undefined *)&this->field_0x360 = 1;
  }
  else {
    *(undefined *)&this->field_0x360 = 0;
  }
  this->field_0x31d = 0;
  *(undefined4 *)&this->field_0x33c = 0;
  cVar5 = dBgS::ChkMoveBG(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,&(this->mBG).field_0x74);
  if (cVar5 == '\0') {
    *(undefined *)&this->field_0x31c = 0;
  }
  else {
    pfVar2 = cBgS::GetActorPointer
                       ((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                        (uint)(ushort)(this->mBG).field_0x74.mBgIndex);
    *(fopAc_ac_c **)&this->field_0x33c = pfVar2;
    if (*(fopAc_ac_c **)&this->field_0x33c != (fopAc_ac_c *)0x0) {
      positionOf(&local_1ac,this,*(fopAc_ac_c **)&this->field_0x33c);
      local_17c.x = local_1ac.x;
      local_17c.y = local_1ac.y;
      local_17c.z = local_1ac.z;
      directionOf((dCamera_c *)acStack532,(fopAc_ac_c *)this);
      cSAngle::cSAngle(local_210,acStack532);
      if (*(char *)&this->field_0x31c != '\0') {
        ::cXyz::operator__(&local_1b8,(cXyz *)&this->field_0x32c,&local_17c);
        *(float *)&this->field_0x320 = local_1b8.x;
        *(float *)&this->field_0x324 = local_1b8.y;
        *(float *)&this->field_0x328 = local_1b8.z;
        cSAngle::operator__(local_218,(cSAngle *)&this->field_0x33a);
        ((cSAngle *)&this->field_0x338)->v = local_218[0];
        if (*(short *)(*(int *)&this->field_0x33c + 8) == 0x3b) {
          (this->field_0x44).y =
               (this->field_0x44).y + *(float *)&this->field_0x324 * (this->mCamSetup).field_0xb8;
        }
      }
      *(undefined *)&this->field_0x31c = 1;
      if (((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr.mCameraPlay == 0) &&
          ((this->mEventFlags & 0x20000000) == 0)) && (*(char *)&this->field_0x360 != '\0')) {
        this->field_0x31d = 1;
      }
      if (this->field_0x31d != 0) {
        dBgS::MoveBgMatrixCrrPos
                  (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,&(this->mBG).field_0x74,true,
                   &this->field_0x44,(csXyz *)0x0,(csXyz *)0x0);
        dBgS::MoveBgMatrixCrrPos
                  (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,&(this->mBG).field_0x74,true,
                   &this->field_0x50,(csXyz *)0x0,(csXyz *)0x0);
        ::cXyz::operator__(&cStack452,&this->field_0x50,&this->field_0x44);
        cSGlobe::Val(&this->field_0x3c,&cStack452);
      }
      *(float *)&this->field_0x32c = local_17c.x;
      *(float *)&this->field_0x330 = local_17c.y;
      *(float *)&this->field_0x334 = local_17c.z;
      ((cSAngle *)&this->field_0x33a)->v = local_210[0];
    }
  }
  if (*(char *)&(this->mBG).field_0x5c == '\0') {
    this->field_0x350 = 0;
  }
  else {
    iVar3 = dBgS::GetCamMoveBG(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,
                               &(this->mBG).field_0x74);
    this->field_0x350 = iVar3;
  }
  this->mRoomNo = -1;
  if ((*(char *)&this->mBG == '\0') ||
     (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4] & 0x100000U) == 0)) {
    if (*(char *)&this->field_0x360 == '\0') {
      this->mRoomMapToolCameraIdx = 0x1ff;
    }
    else {
      if (*(char *)&(this->mBG).field_0x5c == '\0') {
        this->mRoomMapToolCameraIdx = 0xff;
      }
      else {
        iVar3 = dBgS::GetRoomCamId(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,
                                   &(this->mBG).field_0x74);
        this->mRoomMapToolCameraIdx = iVar3;
        if (this->mRoomMapToolCameraIdx == 0xff) {
          iVar3 = dBgS::GetPolyCamId(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,
                                     (uint)(ushort)(this->mBG).field_0x74.mBgIndex,
                                     (uint)(ushort)(this->mBG).field_0x74.mTriIdx);
          this->mRoomMapToolCameraIdx = iVar3;
        }
        else {
          iVar3 = dBgS::GetRoomId(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,
                                  &(this->mBG).field_0x74);
          this->mRoomNo = iVar3;
        }
      }
    }
  }
  else {
    iVar3 = dBgS::GetPolyCamId(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,
                               (uint)*(ushort *)&(this->mBG).field_0x1a,
                               (uint)*(ushort *)&(this->mBG).field_0x18);
    this->mRoomMapToolCameraIdx = iVar3;
  }
  uVar4 = d_a_sea::daSea_ChkArea(local_164,local_15c);
  if ((uVar4 & 0xff) == 0) {
    *(float *)&this->field_0x318 = d_camera::_5126;
    *(undefined *)&this->field_0x314 = 0;
  }
  else {
    dVar10 = (double)d_a_sea::daSea_calcWave((double)local_164,(double)local_15c);
    *(float *)&this->field_0x318 = (float)dVar10;
    *(undefined *)&this->field_0x314 = 1;
  }
  if (*(float *)&this->field_0x354 < *(float *)&this->field_0x318) {
    *(float *)&this->field_0x354 = *(float *)&this->field_0x318;
  }
  ::cBgS_GndChk::cBgS_GndChk(&local_158);
  pcVar6 = &local_118;
  local_118.mbObjThrough = 0;
  local_118.mbCamThrough = 0;
  local_118.mbLinkThrough = 0;
  local_118.mbArrowsAndLightThrough = 0;
  local_118.mbBombThrough = 0;
  local_118.mbBoomerangThrough = 0;
  local_118.mbHookshotThrough = 0;
  local_10c._4_4_ = 1;
  local_158.parent.vtbl = &::dBgS_GndChk::__vt;
  local_158.mPolyInfo.vtbl = &cBgS_PolyInfo__vtbl_80371f08;
  local_118.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
  local_10c._0_4_ = &PTR_80371f20;
  local_158.parent.mpGrpPassChk = (cBgS_GrpPassChk *)pcVar6;
  if (pcVar6 != (cBgS_PolyPassChk *)0x0) {
    local_158.parent.mpGrpPassChk = (cBgS_GrpPassChk *)local_10c;
  }
  local_158.mPos.x = (this->mEye).x;
  local_158.mPos.y = (this->mEye).y;
  local_158.mPos.z = (this->mEye).z;
  local_158.parent.mpPolyPassChk = pcVar6;
  dVar10 = (double)cBgS::GroundCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,&local_158);
  if ((double)(d_camera::_9010 + *(float *)&this->field_0x310) <= dVar10) {
    local_194.x = (this->mEye).x;
    local_194.y = (this->mEye).y;
    local_194.z = (this->mEye).z;
    attentionPos(&local_1f4,this,this->mpPlayerActor);
    local_188.x = local_1f4.x;
    local_188.y = local_1f4.y;
    local_188.z = local_1f4.z;
    ::cXyz::operator__(&cStack512,&local_194,&local_188);
    ::cXyz::operator_(&cStack524,&cStack512,d_camera::_6431);
    mtx::PSVECAdd(&local_188,&cStack524,&local_188);
  }
  else {
    local_188.x = (this->mEye).x;
    local_188.y = (this->mEye).y;
    local_188.z = (this->mEye).z;
    attentionPos(&local_1d0,this,this->mpPlayerActor);
    local_194.x = local_1d0.x;
    local_194.y = local_1d0.y;
    local_194.z = local_1d0.z;
    ::cXyz::operator__(&cStack476,&local_188,&local_194);
    ::cXyz::operator_(&cStack488,&cStack476,d_camera::_6431);
    mtx::PSVECAdd(&local_194,&cStack488,&local_194);
  }
  if (*(char *)&this->field_0x360 == '\0') {
    *(undefined4 *)&this->field_0x364 = 0;
    *(float *)&this->field_0x368 = d_camera::0_0;
  }
  else {
    uVar4 = lineCollisionCheckBush(this,&local_188,&local_194);
    *(uint *)&this->field_0x364 = uVar4 & 5;
    if ((*(uint *)&this->field_0x364 & 4) != 0) {
      *(float *)&this->field_0x368 = (this->mCamSetup).field_0xc0;
    }
    if ((*(uint *)&this->field_0x364 & 1) != 0) {
      *(float *)&this->field_0x368 = (this->mCamSetup).field_0xc4;
    }
    if (*(int *)&this->field_0x364 != 0) {
      dCcMassS_Mng::GetCamTopPos
                (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.mMassMng,(cXyz *)&this->field_0x36c)
      ;
    }
  }
  local_118.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
  local_10c._0_4_ = &PTR_80371f20;
  if (pcVar6 != (cBgS_PolyPassChk *)0x0) {
    local_118.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
    local_10c._0_4_ = &PTR_80371f68;
    if (((undefined *)register0x00000004 != (undefined *)0x10c) &&
       (local_10c._0_4_ = &::dBgS_GrpPassChk::__vt,
       (undefined *)register0x00000004 != (undefined *)0x10c)) {
      local_10c._0_4_ = &::cBgS_GrpPassChk::__vt;
    }
    if ((pcVar6 != (cBgS_PolyPassChk *)0x0) &&
       (local_118.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
       pcVar6 != (cBgS_PolyPassChk *)0x0)) {
      local_118.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
    }
  }
  local_158.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_GndChk::__vt;
  local_158.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
  cBgS_Chk::_cBgS_Chk(&local_158.parent);
  local_c4.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
  local_b8._0_4_ = &PTR_80371f20;
  if (pcVar7 != (cBgS_PolyPassChk *)0x0) {
    local_c4.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
    local_b8._0_4_ = &PTR_80371f68;
    if (((undefined *)register0x00000004 != (undefined *)0xb8) &&
       (local_b8._0_4_ = &::dBgS_GrpPassChk::__vt,
       (undefined *)register0x00000004 != (undefined *)0xb8)) {
      local_b8._0_4_ = &::cBgS_GrpPassChk::__vt;
    }
    if ((pcVar7 != (cBgS_PolyPassChk *)0x0) &&
       (local_c4.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
       pcVar7 != (cBgS_PolyPassChk *)0x0)) {
      local_c4.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
    }
  }
  local_104.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_GndChk::__vt;
  local_104.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
  cBgS_Chk::_cBgS_Chk(&local_104.parent);
  local_b0._12_4_ = &dBgS_RoofChk::__vt;
  local_b0._32_4_ = &PTR_8037d40c;
  local_b0._36_4_ = &PTR_8037d418;
  local_b0._48_4_ = &PTR_8037d424;
  if (pcVar8 != (cBgS_PolyPassChk *)0x0) {
    local_b0._36_4_ = &::dBgS_Chk::__vt;
    local_b0._48_4_ = &PTR_80371f68;
    if (((undefined *)register0x00000004 != (undefined *)0x80) &&
       (local_b0._48_4_ = &::dBgS_GrpPassChk::__vt,
       (undefined *)register0x00000004 != (undefined *)0x80)) {
      local_b0._48_4_ = &::cBgS_GrpPassChk::__vt;
    }
    if ((pcVar8 != (cBgS_PolyPassChk *)0x0) &&
       (local_b0._36_4_ = &::dBgS_PolyPassChk::__vt, pcVar8 != (cBgS_PolyPassChk *)0x0)) {
      local_b0._36_4_ = &::cBgS_PolyPassChk::__vt;
    }
  }
  cBgS_Chk::_cBgS_Chk((cBgS_Chk *)(local_b0 + 0x10));
  __psq_l0(auStack8,uVar9);
  __psq_l1(auStack8,uVar9);
  return;
}


/* __thiscall dCamera_c::followCamera2(long) */

void __thiscall dCamera_c::followCamera2(dCamera_c *this,long param_1)

{
  followCamera(this,param_1);
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Removing unreachable block (ram,0x8016c4d0) */
/* WARNING: Removing unreachable block (ram,0x8016c4c0) */
/* WARNING: Removing unreachable block (ram,0x8016c4b0) */
/* WARNING: Removing unreachable block (ram,0x8016c4a0) */
/* WARNING: Removing unreachable block (ram,0x8016c490) */
/* WARNING: Removing unreachable block (ram,0x8016c480) */
/* WARNING: Removing unreachable block (ram,0x8016c470) */
/* WARNING: Removing unreachable block (ram,0x8016c460) */
/* WARNING: Removing unreachable block (ram,0x8016c450) */
/* WARNING: Removing unreachable block (ram,0x8016c458) */
/* WARNING: Removing unreachable block (ram,0x8016c468) */
/* WARNING: Removing unreachable block (ram,0x8016c478) */
/* WARNING: Removing unreachable block (ram,0x8016c488) */
/* WARNING: Removing unreachable block (ram,0x8016c498) */
/* WARNING: Removing unreachable block (ram,0x8016c4a8) */
/* WARNING: Removing unreachable block (ram,0x8016c4b8) */
/* WARNING: Removing unreachable block (ram,0x8016c4c8) */
/* WARNING: Removing unreachable block (ram,0x8016c4d8) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dCamera_c::followCamera(long) */

undefined4 __thiscall dCamera_c::followCamera(dCamera_c *this,long param_1)

{
  bool bVar1;
  float fVar2;
  ushort uVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  short sVar12;
  char cVar14;
  cXyz *pcVar7;
  Vec *pVVar8;
  undefined4 uVar9;
  short sVar13;
  uint uVar10;
  std *psVar11;
  cAngle *this_00;
  ulong uVar15;
  fopAc_ac_c *pfVar16;
  cSAngle *pcVar17;
  cSAngle *pcVar18;
  uint uVar19;
  bool bVar20;
  undefined4 uVar21;
  double dVar22;
  double dVar23;
  double dVar24;
  double dVar25;
  double dVar26;
  double dVar27;
  double dVar28;
  double dVar29;
  double dVar30;
  double dVar31;
  double dVar32;
  double dVar33;
  double dVar34;
  double dVar35;
  double dVar36;
  double dVar37;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  double extraout_f1_02;
  double extraout_f1_03;
  double dVar38;
  undefined8 in_f14;
  undefined8 in_f15;
  undefined8 in_f16;
  undefined8 in_f17;
  undefined8 in_f18;
  undefined8 in_f19;
  undefined8 in_f20;
  undefined8 in_f21;
  undefined8 in_f22;
  undefined8 in_f23;
  undefined8 in_f24;
  undefined8 in_f25;
  double dVar39;
  undefined8 in_f26;
  double dVar40;
  undefined8 in_f27;
  undefined8 in_f28;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined8 uVar41;
  float fVar42;
  cSAngle acStack1352 [2];
  cSAngle acStack1348 [2];
  cSAngle acStack1344 [2];
  cSAngle acStack1340 [2];
  cSAngle acStack1336 [2];
  cSAngle acStack1332 [2];
  cSAngle acStack1328 [2];
  cSAngle acStack1324 [2];
  cSAngle acStack1320 [2];
  cSAngle acStack1316 [2];
  cSAngle acStack1312 [2];
  cSAngle acStack1308 [2];
  cSAngle acStack1304 [2];
  cSAngle acStack1300 [2];
  cSAngle acStack1296 [2];
  cSAngle acStack1292 [2];
  cSAngle acStack1288 [2];
  cSAngle acStack1284 [2];
  cSAngle acStack1280 [2];
  cSAngle acStack1276 [2];
  cSAngle acStack1272 [2];
  cSAngle acStack1268 [2];
  cSAngle acStack1264 [2];
  cSAngle acStack1260 [2];
  cSAngle acStack1256 [2];
  cSAngle acStack1252 [2];
  cSAngle acStack1248 [2];
  cSAngle acStack1244 [2];
  cSAngle acStack1240 [2];
  cSAngle acStack1236 [2];
  cSAngle local_4d0 [2];
  cSAngle local_4cc [2];
  cSAngle local_4c8 [2];
  cSAngle acStack1220 [2];
  cSAngle acStack1216 [2];
  cSAngle local_4bc [2];
  cSAngle acStack1208 [2];
  cSAngle acStack1204 [2];
  cSAngle local_4b0 [2];
  cSAngle local_4ac [2];
  cSAngle acStack1192 [2];
  cSAngle acStack1188 [2];
  cSAngle acStack1184 [2];
  cSAngle local_49c [2];
  cSAngle local_498 [2];
  cSAngle local_494 [2];
  cSAngle acStack1168 [2];
  cSGlobe cStack1164;
  cSGlobe local_484;
  cSGlobe cStack1148;
  cSGlobe local_474;
  cSGlobe cStack1132;
  cXyz cStack1124;
  cXyz cStack1112;
  cXyz cStack1100;
  cXyz cStack1088;
  cXyz cStack1076;
  cXyz cStack1064;
  cXyz cStack1052;
  cXyz cStack1040;
  cXyz cStack1028;
  cXyz cStack1016;
  cXyz cStack1004;
  cXyz cStack992;
  cXyz cStack980;
  cXyz cStack968;
  cXyz cStack956;
  cXyz cStack944;
  cXyz cStack932;
  cXyz cStack920;
  cXyz cStack908;
  cXyz cStack896;
  cXyz cStack884;
  cXyz cStack872;
  cXyz cStack860;
  cXyz cStack848;
  cXyz cStack836;
  cXyz cStack824;
  cXyz cStack812;
  cXyz cStack800;
  cXyz cStack788;
  cXyz cStack776;
  cXyz cStack764;
  cXyz cStack752;
  cXyz cStack740;
  cXyz cStack728;
  cXyz cStack716;
  cXyz cStack704;
  cXyz cStack692;
  cXyz cStack680;
  cXyz cStack668;
  cXyz cStack656;
  cXyz cStack644;
  cXyz cStack632;
  cXyz cStack620;
  cXyz cStack608;
  cXyz cStack596;
  cXyz cStack584;
  cXyz local_23c;
  dBgS_LinChk dStack560;
  dBgS_LinChk dStack452;
  double local_158;
  float local_150;
  float fStack332;
  double local_148;
  undefined auStack280 [16];
  undefined auStack264 [16];
  undefined auStack248 [16];
  undefined auStack232 [16];
  undefined auStack216 [16];
  undefined auStack200 [16];
  undefined auStack184 [16];
  undefined auStack168 [16];
  undefined auStack152 [16];
  undefined auStack136 [16];
  undefined auStack120 [16];
  undefined auStack104 [16];
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar21 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  __psq_st0(auStack72,(int)((ulonglong)in_f27 >> 0x20),0);
  __psq_st1(auStack72,(int)in_f27,0);
  __psq_st0(auStack88,(int)((ulonglong)in_f26 >> 0x20),0);
  __psq_st1(auStack88,(int)in_f26,0);
  __psq_st0(auStack104,(int)((ulonglong)in_f25 >> 0x20),0);
  __psq_st1(auStack104,(int)in_f25,0);
  __psq_st0(auStack120,(int)((ulonglong)in_f24 >> 0x20),0);
  __psq_st1(auStack120,(int)in_f24,0);
  __psq_st0(auStack136,(int)((ulonglong)in_f23 >> 0x20),0);
  __psq_st1(auStack136,(int)in_f23,0);
  __psq_st0(auStack152,(int)((ulonglong)in_f22 >> 0x20),0);
  __psq_st1(auStack152,(int)in_f22,0);
  __psq_st0(auStack168,(int)((ulonglong)in_f21 >> 0x20),0);
  __psq_st1(auStack168,(int)in_f21,0);
  __psq_st0(auStack184,(int)((ulonglong)in_f20 >> 0x20),0);
  __psq_st1(auStack184,(int)in_f20,0);
  __psq_st0(auStack200,(int)((ulonglong)in_f19 >> 0x20),0);
  __psq_st1(auStack200,(int)in_f19,0);
  __psq_st0(auStack216,(int)((ulonglong)in_f18 >> 0x20),0);
  __psq_st1(auStack216,(int)in_f18,0);
  __psq_st0(auStack232,(int)((ulonglong)in_f17 >> 0x20),0);
  __psq_st1(auStack232,(int)in_f17,0);
  __psq_st0(auStack248,(int)((ulonglong)in_f16 >> 0x20),0);
  __psq_st1(auStack248,(int)in_f16,0);
  __psq_st0(auStack264,(int)((ulonglong)in_f15 >> 0x20),0);
  __psq_st1(auStack264,(int)in_f15,0);
  __psq_st0(auStack280,(int)((ulonglong)in_f14 >> 0x20),0);
  __psq_st1(auStack280,(int)in_f14,0);
  dVar39 = (double)d_camera::_10129;
  cSAngle::cSAngle(acStack1220,(this->mCamSetup).field_0xa4);
  cSAngle::cSAngle(acStack1168,acStack1220);
  cSAngle::_cSAngle(acStack1220);
  uVar19 = (this->mCamSetup).field_0xa8;
  dVar40 = (double)(this->mCamSetup).field_0xac;
  cSAngle::cSAngle(local_494,d_camera::_10130);
  dVar22 = (double)dCamParam_c::Val(&this->mCamParam,param_1,1);
  dVar23 = (double)dCamParam_c::Val(&this->mCamParam,param_1,5);
  dVar24 = (double)dCamParam_c::Val(&this->mCamParam,param_1,0);
  dVar25 = (double)dCamParam_c::Val(&this->mCamParam,param_1,4);
  dVar26 = (double)dCamParam_c::Val(&this->mCamParam,param_1,3);
  dVar27 = (double)dCamParam_c::Val(&this->mCamParam,param_1,10);
  dVar28 = (double)dCamParam_c::Val(&this->mCamParam,param_1,0xb);
  dVar29 = (double)dCamParam_c::Val(&this->mCamParam,param_1,0xd);
  dVar30 = (double)dCamParam_c::Val(&this->mCamParam,param_1,0xe);
  dVar31 = (double)dCamParam_c::Val(&this->mCamParam,param_1,0xf);
  dVar32 = (double)dCamParam_c::Val(&this->mCamParam,param_1,0x10);
  cSAngle::cSAngle(local_498,(float)dVar32);
  dVar32 = (double)dCamParam_c::Val(&this->mCamParam,param_1,0x11);
  cSAngle::cSAngle(local_49c,(float)dVar32);
  dVar32 = (double)dCamParam_c::Val(&this->mCamParam,param_1,0x13);
  dVar33 = (double)dCamParam_c::Val(&this->mCamParam,param_1,0x12);
  dVar34 = (double)dCamParam_c::Val(&this->mCamParam,param_1,0x19);
  local_148 = (double)dCamParam_c::Val(&this->mCamParam,param_1,0x1d);
  dVar35 = (double)dCamParam_c::Val(&this->mCamParam,param_1,0x17);
  dVar36 = (double)dCamParam_c::Val(&this->mCamParam,param_1,0x18);
  uVar15 = 0x14;
  dVar37 = (double)dCamParam_c::Val(&this->mCamParam,param_1,0x14);
  d_a_himo2::dComIfGp_getAttention();
  fVar42 = d_camera::0_0;
  if (this->field_0x108 == 0) {
    (this->mEvBasePos).x = d_camera::0_0;
    (this->mEvBasePos).y = fVar42;
    *(undefined *)&this->field_0x3d9 = 0;
  }
  bVar1 = false;
  if ((daNpc_Cb1_c::m_flying != '\0') || (daNpc_Md_c::m_flying != '\0')) {
    bVar1 = true;
  }
  if (bVar1) {
    dVar39 = (double)d_camera::_10131;
    if (d_camera::init_9682 == '\0') {
      d_camera::SA_FLY_9681 = d_camera::_6118;
      d_camera::init_9682 = '\x01';
    }
    if (dVar31 < (double)d_camera::SA_FLY_9681) {
      dVar31 = (double)d_camera::SA_FLY_9681;
    }
    cSAngle::operator__(&this->field_0x148,d_camera::_9005);
    if (dVar27 < (double)d_camera::_10132) {
      dVar27 = (double)d_camera::_10132;
    }
    if (dVar28 < (double)d_camera::_10133) {
      dVar28 = (double)d_camera::_10133;
    }
    cSAngle::Val(local_49c,d_camera::_10130);
    if ((daNpc_Cb1_c::m_flying != '\0') && (*(char *)&this->field_0x788 != '\0')) {
      if (*(char *)&this->field_0x787 == '\0') {
        cSAngle::cSAngle(local_4cc,d_camera::_6064);
        uVar3 = local_4cc[0] ^ local_498[0];
        cSAngle::_cSAngle(local_4cc);
        if (((int)(short)uVar3 >> 1) - (int)(short)(uVar3 & local_4cc[0]) < 0) {
          cSAngle::Val(local_498,d_camera::_6064);
        }
      }
      else {
        cSAngle::cSAngle(local_4c8,d_camera::30_0);
        uVar3 = local_4c8[0] ^ local_498[0];
        cSAngle::_cSAngle(local_4c8);
        if (((int)(short)uVar3 >> 1) - (int)(short)(uVar3 & local_4c8[0]) < 0) {
          cSAngle::Val(local_498,d_camera::30_0);
        }
        if (dVar31 < (double)d_camera::_5573) {
          dVar31 = (double)d_camera::_5573;
        }
        dVar27 = (double)d_camera::_10134;
        dVar28 = (double)d_camera::_10135;
      }
    }
  }
  iVar6 = @unnamed@d_camera_cpp@::check_owner_action
                    ((_unnamed_d_camera_cpp_ *)this->mPadId,0x8100000,uVar15);
  if (iVar6 != 0) {
    cSAngle::cSAngle(local_4d0,d_camera::_10136);
    uVar3 = local_4d0[0] ^ local_498[0];
    cSAngle::_cSAngle(local_4d0);
    if (((int)(short)uVar3 >> 1) - (int)(short)(uVar3 & local_4d0[0]) < 0) {
      cSAngle::Val(local_498,d_camera::_10136);
    }
    if (dVar23 < (double)d_camera::_10137) {
      dVar23 = (double)d_camera::_10137;
    }
  }
  iVar6 = @unnamed@d_camera_cpp@::check_owner_action
                    ((_unnamed_d_camera_cpp_ *)this->mPadId,0x300,uVar15);
  if ((iVar6 == 0) ||
     (iVar6 = @unnamed@d_camera_cpp@::check_owner_action
                        ((_unnamed_d_camera_cpp_ *)this->mPadId,0x2000000,uVar15), iVar6 != 0)) {
    dVar38 = (double)(this->mEvBasePos).y;
    (this->mEvBasePos).y = (float)(dVar38 + (double)(d_camera::_10138 * (float)(dVar24 - dVar38)));
  }
  else {
    if ((double)d_camera::_10137 < dVar24) {
      (this->mEvBasePos).y = d_camera::_10137;
    }
  }
  iVar6 = @unnamed@d_camera_cpp@::check_owner_action1
                    ((_unnamed_d_camera_cpp_ *)this->mPadId,0x40000,uVar15);
  bVar1 = iVar6 != 0;
  if (bVar1) {
    cSAngle::operator__(&this->field_0x148,&cSAngle::_0);
    dVar31 = (double)d_camera::_10139;
    dVar28 = (double)d_camera::_10132;
    dVar34 = (double)d_camera::_10130;
    dVar23 = (double)d_camera::_10140;
    dVar27 = dVar28;
  }
  cSAngle::cSAngle(acStack1184,&cSAngle::_0);
  iVar6 = @unnamed@d_camera_cpp@::check_owner_action
                    ((_unnamed_d_camera_cpp_ *)this->mPadId,0x60,uVar15);
  if (iVar6 != 0) {
    calcPeepAngle((dCamera_c *)acStack1236);
    cSAngle::operator__(acStack1184,acStack1236);
    cSAngle::_cSAngle(acStack1236);
    iVar6 = @unnamed@d_camera_cpp@::check_owner_action
                      ((_unnamed_d_camera_cpp_ *)this->mPadId,0x20,uVar15);
    if (iVar6 != 0) {
      dVar22 = -dVar22;
    }
  }
  uVar15 = 0x200;
  sVar12 = dCamParam_c::Flag(&this->mCamParam,param_1,0x200);
  cVar14 = chkFlag(this,0x100000);
  if ((cVar14 == '\0') ||
     (iVar6 = @unnamed@d_camera_cpp@::check_owner_action
                        ((_unnamed_d_camera_cpp_ *)this->mPadId,0xa5000,uVar15), iVar6 == 0)) {
    bVar4 = false;
    if ((daNpc_Cb1_c::m_flying != '\0') || (daNpc_Md_c::m_flying != '\0')) {
      bVar4 = true;
    }
    if (bVar4) goto LAB_8016a6c8;
    dVar24 = (double)(this->mEvBasePos).x;
    (this->mEvBasePos).x = (float)(dVar24 + (double)(d_camera::_10138 * (float)(dVar22 - dVar24)));
  }
  else {
LAB_8016a6c8:
    if (this->mStickMainPosXLast < d_camera::_10141) {
      *(undefined *)&this->field_0x3d9 = 1;
    }
    if (d_camera::_9011 < this->mStickMainPosXLast) {
      *(undefined *)&this->field_0x3d9 = 0;
    }
    fVar42 = d_camera::_10144;
    if (*(char *)&this->field_0x3d9 != '\0') {
      fVar42 = d_camera::_10143;
    }
    (this->mEvBasePos).x = (this->mEvBasePos).x + d_camera::_10142 * (fVar42 - (this->mEvBasePos).x)
    ;
  }
  ::cXyz::cXyz(&local_23c,(this->mEvBasePos).x,(float)dVar23,(this->mEvBasePos).y);
  if (this->field_0x108 == 0) {
    ::cXyz::operator__(&cStack704,&this->field_0x50,&this->field_0x44);
    cSGlobe::Val(&this->field_0x3c,&cStack704);
    ::cXyz::_cXyz(&cStack704);
    *(undefined4 *)&this->field_0x378 = 0x464c4c57;
    this->mEvFovy = (float)dVar39;
    *(undefined4 *)&this->field_0x388 = 0x50;
    this->mEvBank = (float)dVar28;
    this->mpEvRelActor = (fopAc_ac_c *)(float)dVar27;
    *(undefined2 *)&this->field_0x390 = 0;
    *(undefined2 *)&this->field_0x392 = 0;
    *(undefined4 *)&this->field_0x38c = 0;
    dVar23 = (double)cSAngle::Degree((cSAngle *)&this->field_0xc);
    *(float *)&this->field_0x3bc = (float)dVar23;
    *(float *)this->mEvRelUseMask = (float)dVar23;
    ::cXyz::operator__((cXyz *)&this->field_0x3c0,&this->field_0x44);
    ::cXyz::operator__((cXyz *)&this->field_0x3cc,&this->field_0x50);
    fVar42 = d_camera::_6065;
    *(float *)&this->field_0x3e4 = d_camera::_6065;
    *(float *)&this->field_0x3e0 = fVar42;
    *(float *)&this->field_0x3e8 = fVar42;
    *(float *)&this->field_0x3dc = d_camera::_8359;
    *(float *)&this->field_0x3ec = (float)dVar26;
    *(float *)&this->field_0x3f0 = (float)dVar25;
    (this->mEvBasePos).z = 0.0;
    *(undefined *)&this->field_0x3d8 = 1;
    *(float *)&this->field_0x3a8 = this->field_0x60;
    *(float *)&this->field_0x3b8 = d_camera::0_0;
    *(undefined *)&this->field_0x3da = 0;
    positionOf(&cStack716,this,this->mpPlayerActor);
    this->mEvTimer = (int)cStack716.y;
    ::cXyz::_cXyz(&cStack716);
    cVar14 = chkFlag(this,0x8000);
    if ((cVar14 == '\0') && (this->field_0x110 != 0)) {
      relationalPos(&cStack728,this,this->mpPlayerActor,&local_23c);
      ::cXyz::cXyz(&cStack584,&cStack728);
      ::cXyz::_cXyz(&cStack728);
      cVar14 = chkFlag(this,0x100000);
      if (cVar14 == '\0') {
        cSAngle::Val(acStack1188,&(this->field_0x3c).mAngleY);
      }
      else {
        directionOf((dCamera_c *)acStack1240,(fopAc_ac_c *)this);
        sVar13 = cSAngle::Inv(acStack1240);
        cSAngle::Val(acStack1188,sVar13);
        cSAngle::_cSAngle(acStack1240);
      }
      cSAngle::cSAngle(acStack1244,(float)dVar31);
      dVar23 = (double)(float)dVar27;
      cSGlobe::cSGlobe(&cStack1132,(float)dVar27,acStack1244,acStack1188);
      cSAngle::_cSAngle(acStack1244);
      cSGlobe::Xyz(&cStack740,&cStack1132);
      ::cXyz::operator__(&cStack752,&cStack584,&cStack740);
      ::cXyz::cXyz(&cStack596,&cStack752);
      ::cXyz::_cXyz(&cStack752);
      ::cXyz::_cXyz(&cStack740);
      ::cXyz::operator__(&cStack764,&this->mEye,&cStack596);
      pcVar7 = &cStack764;
      ::cXyz::cXyz(&cStack776,pcVar7);
      ::cXyz::abs(&cStack776,(int)pcVar7);
      dVar22 = dVar23;
      ::cXyz::_cXyz(&cStack776);
      ::cXyz::_cXyz(&cStack764);
      ::cXyz::operator__(&cStack788,&this->mCenter,&cStack584);
      pcVar7 = &cStack788;
      ::cXyz::cXyz(&cStack800,pcVar7);
      ::cXyz::abs(&cStack800,(int)pcVar7);
      dVar23 = (double)(float)((double)d_camera::_10136 * dVar23);
      ::cXyz::_cXyz(&cStack800);
      pcVar7 = &cStack788;
      ::cXyz::_cXyz(pcVar7);
      if (dVar23 < dVar22) {
        dVar23 = dVar22;
      }
      fVar42 = std::fabsf((std *)pcVar7,(float)dVar23);
      dVar22 = (double)fVar42;
      psVar11 = (std *)heightOf(this,this->mpPlayerActor);
      dVar23 = (double)d_camera::_6064;
      if (dVar23 < extraout_f1) {
        dVar23 = extraout_f1;
      }
      fVar42 = std::sqrtf(psVar11,(float)(dVar22 / dVar23));
      local_158 = (double)(longlong)(int)(d_camera::_10145 * fVar42);
      *(int *)&this->field_0x37c = (int)(d_camera::_10145 * fVar42) + 1;
      ::cXyz::_cXyz(&cStack596);
      cSGlobe::_cSGlobe(&cStack1132);
      cSAngle::_cSAngle(acStack1188);
      ::cXyz::_cXyz(&cStack584);
    }
    else {
      *(undefined *)&this->field_0x102 = 1;
      *(undefined *)&this->field_0x101 = 1;
      *(undefined *)&this->field_0x100 = 1;
      *(undefined4 *)&this->field_0x37c = 1;
    }
    this->mpEvRelActor = (fopAc_ac_c *)this->field_0x8;
    this->mEvBank = (float)(fopAc_ac_c *)this->field_0x8;
    *(float *)&this->field_0x3a8 = this->mFovY;
    local_158 = (double)CONCAT44(0x43300000,
                                 *(int *)&this->field_0x37c * (*(int *)&this->field_0x37c + 1) >> 1
                                 ^ 0x80000000);
    *(float *)&this->field_0x380 = (float)(local_158 - d_camera::_5738);
    *(float *)&this->field_0x384 = d_camera::0_0;
  }
  relationalPos(&cStack812,this,this->mpPlayerActor,&local_23c);
  ::cXyz::cXyz(&cStack608,&cStack812);
  ::cXyz::_cXyz(&cStack812);
  directionOf((dCamera_c *)acStack1248,(fopAc_ac_c *)this);
  cSAngle::cSAngle(acStack1192,acStack1248);
  cSAngle::_cSAngle(acStack1248);
  pcVar17 = &(this->field_0x3c).mAngleY;
  cSAngle::operator__(acStack1252,acStack1192);
  cSAngle::cSAngle(local_4ac,acStack1252);
  cSAngle::_cSAngle(acStack1252);
  dVar23 = (double)getWaterSurfaceHeight(this,&cStack608);
  cStack608.y = (float)dVar23;
  if (*(char *)&this->field_0x100 == '\0') {
    if (this->field_0x31d != 0) {
      dBgS::MoveBgMatrixCrrPos
                (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,&(this->mBG).field_0x74,true,
                 (cXyz *)&this->field_0x3c0,(csXyz *)0x0,(csXyz *)0x0);
    }
    local_158 = (double)CONCAT44(0x43300000,
                                 *(int *)&this->field_0x37c - this->field_0x108 ^ 0x80000000);
    *(float *)&this->field_0x384 = (float)(local_158 - d_camera::_5738);
    dVar32 = (double)(*(float *)&this->field_0x384 / *(float *)&this->field_0x380);
    ::cXyz::operator__(&cStack824,&cStack608,(cXyz *)&this->field_0x3c0);
    ::cXyz::operator_(&cStack836,&cStack824,(float)dVar32);
    ::cXyz::operator___((cXyz *)&this->field_0x3c0,(Vec *)&cStack836);
    ::cXyz::_cXyz(&cStack836);
    ::cXyz::_cXyz(&cStack824);
    ::cXyz::operator__(&cStack848,(cXyz *)&this->field_0x3c0,&this->field_0x44);
    ::cXyz::operator_(&cStack860,&cStack848,(float)dVar26);
    ::cXyz::operator___(&this->field_0x44,(Vec *)&cStack860);
    ::cXyz::_cXyz(&cStack860);
    ::cXyz::_cXyz(&cStack848);
    pcVar7 = (cXyz *)dCamMath::xyzHorizontalDistance(&cStack608,(cXyz *)&this->field_0x3c0);
    if (local_23c.z < local_23c.x) {
      local_23c.z = local_23c.x;
    }
    dVar31 = extraout_f1_00;
    fVar42 = std::fabsf((std *)pcVar7,local_23c.z);
    if (dVar31 < (double)(d_camera::_9008 + fVar42)) {
      attentionPos(&cStack872,this,this->mpPlayerActor);
      ::cXyz::cXyz(&cStack620,&cStack872);
      ::cXyz::_cXyz(&cStack872);
      cStack620.y = cStack620.y - d_camera::_10146;
      dBgS_CamLinChk_NorWtr::dBgS_CamLinChk_NorWtr((dBgS_CamLinChk_NorWtr *)&dStack452);
      cVar14 = lineBGCheck(this,&cStack620,&this->field_0x44,&dStack452,0x7f);
      if (cVar14 != '\0') {
        pVVar8 = (Vec *)cBgS::GetTriPla((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                                        &dStack452.parent.mPolyInfo);
        pcVar7 = (cXyz *)::cBgS_LinChk::GetCross(&dStack452.parent);
        ::cXyz::operator__(&this->field_0x44,pcVar7);
        ::cXyz::operator___(&this->field_0x44,pVVar8);
      }
      dBgS_CamLinChk_NorWtr::_dBgS_CamLinChk_NorWtr((dBgS_CamLinChk_NorWtr *)&dStack452);
      pcVar7 = &cStack620;
      ::cXyz::_cXyz(pcVar7);
    }
    dVar31 = (double)@unnamed@d_camera_cpp@::limitf
                               ((_unnamed_d_camera_cpp_ *)pcVar7,(this->field_0x3c).mDistance,
                                (float)dVar28,(float)dVar27);
    pcVar18 = &(this->field_0x3c).mAngleX;
    cSAngle::operator__(local_4b0,pcVar18);
    if (local_4b0[0] < local_498[0]) {
      cSAngle::operator__(local_4b0,local_498);
    }
    if (local_49c[0] < local_4b0[0]) {
      cSAngle::operator__(local_4b0,local_49c);
    }
    sVar12 = cSAngle::Inv(&this->mAngleY);
    cSAngle::cSAngle(acStack1256,sVar12);
    cSGlobe::cSGlobe(&local_474,(float)dVar31,local_4b0,acStack1256);
    cSAngle::_cSAngle(acStack1256);
    fVar42 = (this->field_0x3c).mDistance;
    (this->field_0x3c).mDistance = fVar42 + (float)(dVar32 * (double)(local_474.mDistance - fVar42))
    ;
    cSAngle::operator__(acStack1260,&local_474.mAngleX);
    cSAngle::operator_(acStack1264,(float)dVar32);
    cSAngle::operator__(acStack1268,pcVar18);
    cSGlobe::V(&this->field_0x3c,acStack1268);
    cSAngle::_cSAngle(acStack1268);
    cSAngle::_cSAngle(acStack1264);
    cSAngle::_cSAngle(acStack1260);
    cVar14 = chkFlag(this,0x100000);
    if (cVar14 != '\0') {
      uVar9 = cSAngle::Inv(acStack1192);
      SComponent::operator__(acStack1272,uVar9,pcVar17);
      cSAngle::operator_(acStack1276,(float)dVar32);
      cSAngle::operator__(acStack1280,pcVar17);
      cSGlobe::U(&this->field_0x3c,acStack1280);
      cSAngle::_cSAngle(acStack1280);
      cSAngle::_cSAngle(acStack1276);
      cSAngle::_cSAngle(acStack1272);
    }
    cSGlobe::Xyz(&cStack884,&this->field_0x3c);
    ::cXyz::operator__(&cStack896,&this->field_0x44,&cStack884);
    pcVar7 = (cXyz *)::cXyz::operator__(&this->field_0x50,&cStack896);
    ::cXyz::operator__((cXyz *)&this->field_0x3cc,pcVar7);
    ::cXyz::_cXyz(&cStack896);
    ::cXyz::_cXyz(&cStack884);
    if (*(int *)&this->field_0x37c - 1U <= (uint)this->field_0x108) {
      *(undefined *)&this->field_0x102 = 1;
      *(undefined *)&this->field_0x101 = 1;
      *(undefined *)&this->field_0x100 = 1;
    }
    dVar31 = (double)cSAngle::Degree(pcVar18);
    *(float *)this->mEvRelUseMask = (float)dVar31;
    pfVar16 = (fopAc_ac_c *)(this->field_0x3c).mDistance;
    this->mpEvRelActor = pfVar16;
    this->mEvBank = (float)pfVar16;
    this->field_0x60 =
         (float)((double)this->field_0x60 +
                (double)(float)(dVar32 * (double)(float)(dVar34 - (double)this->field_0x60)));
    *(float *)&this->field_0x380 = *(float *)&this->field_0x380 - *(float *)&this->field_0x384;
    cSGlobe::_cSGlobe(&local_474);
    cSAngle::_cSAngle(local_4b0);
    cSAngle::_cSAngle(local_4ac);
    cSAngle::_cSAngle(acStack1192);
    ::cXyz::_cXyz(&cStack608);
    ::cXyz::_cXyz(&local_23c);
    cSAngle::_cSAngle(acStack1184);
    cSAngle::_cSAngle(local_49c);
    cSAngle::_cSAngle(local_498);
    cSAngle::_cSAngle(local_494);
    cSAngle::_cSAngle(acStack1168);
    goto LAB_8016c450;
  }
  pfVar16 = this->mpPlayerActor;
  positionOf(&cStack908,this,pfVar16);
  ::cXyz::cXyz(&cStack632,&cStack908);
  ::cXyz::_cXyz(&cStack908);
  cStack632.y = cStack632.y + d_camera::_6064;
  dVar22 = (double)(this->mpPlayerActor->mCurrent).mPos.y;
  dVar23 = (double)groundHeight(this,&cStack632);
  dVar23 = (double)(float)(dVar22 - dVar23);
  if ((((*(char *)&this->field_0x360 == '\0') &&
       (iVar6 = @unnamed@d_camera_cpp@::check_owner_action
                          ((_unnamed_d_camera_cpp_ *)this->mPadId,0x100000,(ulong)pfVar16),
       iVar6 == 0)) && (daNpc_kam_c::m_hyoi_kamome == 0)) ||
     (iVar6 = @unnamed@d_camera_cpp@::check_owner_action
                        ((_unnamed_d_camera_cpp_ *)this->mPadId,0x200,(ulong)pfVar16), iVar6 != 0))
  {
    if (*(int *)&this->field_0x388 < 0x50) {
      *(int *)&this->field_0x388 = *(int *)&this->field_0x388 + 1;
      local_158 = (double)CONCAT44(0x43300000,*(uint *)&this->field_0x388 ^ 0x80000000);
      dVar22 = (double)dCamMath::rationalBezierRatio
                                 ((float)(local_158 - d_camera::_5738) / d_camera::_10130,
                                  d_camera::_10147);
      this->mEvFovy =
           (float)((double)this->mEvFovy +
                  (double)(float)((double)(float)(dVar39 - (double)this->mEvFovy) * dVar22));
    }
  }
  else {
    this->mEvFovy = d_camera::0_0;
    *(undefined4 *)&this->field_0x388 = 0;
  }
  iVar6 = @unnamed@d_camera_cpp@::check_owner_action
                    ((_unnamed_d_camera_cpp_ *)this->mPadId,0x6800061,(ulong)pfVar16);
  if (((iVar6 != 0) ||
      (iVar6 = @unnamed@d_camera_cpp@::check_owner_action1
                         ((_unnamed_d_camera_cpp_ *)this->mPadId,0x10000,(ulong)pfVar16), iVar6 != 0
      )) && (*(char *)&this->field_0x220 == '\0')) {
    setDMCAngle(this);
  }
  iVar6 = @unnamed@d_camera_cpp@::check_owner_action
                    ((_unnamed_d_camera_cpp_ *)this->mPadId,0x2000161,(ulong)pfVar16);
  if (((iVar6 == 0) &&
      (iVar6 = @unnamed@d_camera_cpp@::check_owner_action1
                         ((_unnamed_d_camera_cpp_ *)this->mPadId,0x10000,(ulong)pfVar16), iVar6 == 0
      )) || ((__270 < local_4ac[0] && (local_4ac[0] < __90)))) {
    *(float *)&this->field_0x3ec = (float)dVar26;
  }
  else {
    *(float *)&this->field_0x3ec = d_camera::_10148;
  }
  if (*(int *)&this->field_0x388 == 0) {
    *(float *)&this->field_0x3f0 = (float)dVar25;
  }
  else {
    *(float *)&this->field_0x3f0 =
         (float)((double)d_camera::_10148 * dVar25) +
         (d_camera::1_0 - (float)((double)d_camera::_10148 * dVar25)) * this->mEvFovy;
    cVar14 = chkFlag(this,0x100000);
    if ((cVar14 == '\0') || (*(float *)&this->field_0x3ec <= d_camera::0_25)) {
      bVar4 = false;
      if ((daNpc_Cb1_c::m_flying != '\0') || (daNpc_Md_c::m_flying != '\0')) {
        bVar4 = true;
      }
      if ((!bVar4) &&
         (iVar6 = @unnamed@d_camera_cpp@::check_owner_action1
                            ((_unnamed_d_camera_cpp_ *)this->mPadId,0x40000,(ulong)pfVar16),
         iVar6 == 0)) goto LAB_8016b24c;
    }
    *(float *)&this->field_0x3ec = d_camera::0_25 + d_camera::_8359 * this->mEvFovy;
  }
LAB_8016b24c:
  ::cXyz::cXyz(&cStack644,*(float *)&this->field_0x3ec,*(float *)&this->field_0x3f0,
               *(float *)&this->field_0x3ec);
  bVar5 = true;
  bVar4 = false;
  cVar14 = chkFlag(this,0x80);
  if ((cVar14 != '\0') && ((double)this->field_0x8 < dVar28)) {
    bVar4 = true;
  }
  cVar14 = chkFlag(this,0x100000);
  if ((((cVar14 != '\0') ||
       (iVar6 = @unnamed@d_camera_cpp@::check_owner_action
                          ((_unnamed_d_camera_cpp_ *)this->mPadId,0x6820161,(ulong)pfVar16),
       iVar6 != 0)) ||
      (iVar6 = @unnamed@d_camera_cpp@::check_owner_action1
                         ((_unnamed_d_camera_cpp_ *)this->mPadId,0x10040,(ulong)pfVar16), iVar6 != 0
      )) || (*(int *)&this->field_0x388 != 0)) {
    bVar5 = false;
  }
  if (this->mCurMode == 1) {
    attentionPos(&cStack920,this,this->mpPlayerActor);
    bVar20 = cStack608.y < d_camera::_5573 + cStack920.y;
    ::cXyz::_cXyz(&cStack920);
    if (bVar20) {
      directionOf((dCamera_c *)acStack1284,(fopAc_ac_c *)this);
      sVar13 = cSAngle::Inv(acStack1284);
      cSGlobe::cSGlobe(&cStack1148,(float)dVar28,0,sVar13);
      cSAngle::_cSAngle(acStack1284);
      attentionPos(&cStack932,this,this->mpPlayerActor);
      ::cXyz::cXyz(&cStack656,&cStack932);
      ::cXyz::_cXyz(&cStack932);
      cSGlobe::Xyz(&cStack944,&cStack1148);
      ::cXyz::operator__(&cStack956,&cStack656,&cStack944);
      ::cXyz::cXyz(&cStack668,&cStack956);
      ::cXyz::_cXyz(&cStack956);
      ::cXyz::_cXyz(&cStack944);
      cVar14 = lineBGCheck(this,&cStack656,&cStack668,0x7f);
      if (cVar14 != '\0') {
        cStack608.y = d_camera::_5573 + cStack656.y;
      }
      ::cXyz::_cXyz(&cStack668);
      ::cXyz::_cXyz(&cStack656);
      cSGlobe::_cSGlobe(&cStack1148);
    }
  }
  ::cXyz::operator__(&cStack968,&cStack608,&this->field_0x44);
  ::cXyz::operator_(&cStack980,(Vec *)&cStack968);
  ::cXyz::operator___(&this->field_0x44,(Vec *)&cStack980);
  ::cXyz::_cXyz(&cStack980);
  ::cXyz::_cXyz(&cStack968);
  if (*(char *)&this->field_0x780 == '\0') {
    pfVar16 = this->mpPlayerActor;
    attentionPos(&cStack992,this,pfVar16);
    ::cXyz::cXyz(&cStack680,&cStack992);
    ::cXyz::_cXyz(&cStack992);
    iVar6 = @unnamed@d_camera_cpp@::check_owner_action
                      ((_unnamed_d_camera_cpp_ *)this->mPadId,0x8100100,(ulong)pfVar16);
    if (iVar6 == 0) {
      cStack680.y = cStack680.y - d_camera::_10146;
    }
    else {
      eyePos(&cStack1004,this,this->mpPlayerActor);
      cStack680.y = d_camera::30_0 + cStack1004.y;
      ::cXyz::_cXyz(&cStack1004);
    }
    dBgS_CamLinChk_NorWtr::dBgS_CamLinChk_NorWtr((dBgS_CamLinChk_NorWtr *)&dStack560);
    cVar14 = lineBGCheck(this,&cStack680,&this->field_0x44,&dStack560,0x7f);
    if (cVar14 != '\0') {
      pVVar8 = (Vec *)cBgS::GetTriPla((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                                      &dStack560.parent.mPolyInfo);
      pcVar7 = (cXyz *)::cBgS_LinChk::GetCross(&dStack560.parent);
      ::cXyz::operator__(&this->field_0x44,pcVar7);
      ::cXyz::operator___(&this->field_0x44,pVVar8);
    }
    dBgS_CamLinChk_NorWtr::_dBgS_CamLinChk_NorWtr((dBgS_CamLinChk_NorWtr *)&dStack560);
    ::cXyz::_cXyz(&cStack680);
  }
  pcVar7 = &this->field_0x44;
  ::cXyz::operator__(&cStack1016,&this->field_0x50,pcVar7);
  cSGlobe::cSGlobe(&local_484,&cStack1016);
  ::cXyz::_cXyz(&cStack1016);
  sVar13 = *(short *)&this->field_0x392;
  if ((sVar13 < 1) || ((int)uVar19 < (int)sVar13)) {
    cVar14 = chkFlag(this,0x100000);
    if ((cVar14 == '\0') && (daNpc_Cb1_c::m_flying == '\0')) {
      if ((daNpc_Md_c::m_flying == '\0') && (daNpc_kam_c::m_hyoi_kamome == 0)) {
        iVar6 = @unnamed@d_camera_cpp@::check_owner_action1
                          ((_unnamed_d_camera_cpp_ *)this->mPadId,0x40040,(ulong)pcVar7);
        if (iVar6 == 0) {
          *(undefined *)&this->field_0x3d8 = 1;
          if (*(char *)&this->field_0x220 == '\0') {
            if (this->mStickMainPosYLast < d_camera::0_0) {
              dVar22 = (double)dCamMath::rationalBezierRatio(this->mStickMainPosXLast,(float)dVar36)
              ;
              cSAngle::cSAngle(acStack1292,(float)((double)d_camera::180_0 * dVar22));
              dVar22 = (double)cSAngle::Cos(acStack1292);
              *(float *)&this->field_0x3b8 =
                   d_camera::1_0 - (d_camera::_8359 + (float)((double)d_camera::0_25 * dVar22));
              cSAngle::_cSAngle(acStack1292);
            }
            else {
              dVar22 = (double)dCamMath::rationalBezierRatio(this->mStickMainPosXLast,(float)dVar35)
              ;
              cSAngle::cSAngle(acStack1288,(float)((double)d_camera::180_0 * dVar22));
              dVar22 = (double)cSAngle::Cos(acStack1288);
              *(float *)&this->field_0x3b8 =
                   d_camera::1_0 -
                   (float)((double)d_camera::_6431 +
                          (double)(float)((double)d_camera::_6431 * dVar22));
              cSAngle::_cSAngle(acStack1288);
            }
          }
          else {
            *(float *)&this->field_0x3b8 = d_camera::0_0;
          }
          *(float *)&this->field_0x3b8 = *(float *)&this->field_0x3b8 * this->mStickMainValueLast;
          cVar14 = chkFlag(this,0x80000);
          if (cVar14 == '\0') {
            *(float *)&this->field_0x3b8 = *(float *)&this->field_0x3b8 * d_camera::_10148;
          }
          else {
            *(float *)&this->field_0x3b8 = *(float *)&this->field_0x3b8 * d_camera::_6431;
          }
          iVar6 = @unnamed@d_camera_cpp@::check_owner_action
                            ((_unnamed_d_camera_cpp_ *)this->mPadId,0x2000100,(ulong)pcVar7);
          if ((iVar6 == 0) &&
             (iVar6 = @unnamed@d_camera_cpp@::check_owner_action1
                                ((_unnamed_d_camera_cpp_ *)this->mPadId,0x10000,(ulong)pcVar7),
             iVar6 == 0)) {
            if (sVar12 == 0 && !bVar1) {
              *(float *)&this->field_0x3b8 = (float)((double)*(float *)&this->field_0x3b8 * dVar37);
              *(undefined4 *)&this->field_0x38c = 0;
            }
            else {
              if ((*(uint *)&this->field_0x38c == 0) &&
                 ((local_4ac[0] <= __270 || (__90 <= local_4ac[0])))) {
                *(undefined4 *)&this->field_0x38c = 1;
              }
              else {
                if (*(int *)&this->field_0x38c < 0xf) {
                  fStack332 = (float)(*(uint *)&this->field_0x38c ^ 0x80000000);
                  local_150 = 176.0;
                  *(float *)&this->field_0x3b8 =
                       d_camera::_10150 *
                       (float)((double)CONCAT44(0x43300000,fStack332) - d_camera::_5738);
                  *(int *)&this->field_0x38c = *(int *)&this->field_0x38c + 1;
                }
                else {
                  iVar6 = @unnamed@d_camera_cpp@::check_owner_action
                                    ((_unnamed_d_camera_cpp_ *)this->mPadId,0x60,(ulong)pcVar7);
                  if (iVar6 == 0) {
                    if (d_camera::_10148 <= this->mStickMainValueLast) {
                      psVar11 = (std *)cSAngle::Sin(local_4ac);
                      fVar42 = std::fabsf(psVar11,(float)extraout_f1_02);
                      dVar22 = (double)dCamMath::rationalBezierRatio(fVar42,d_camera::_10151);
                      *(float *)&this->field_0x3b8 = (float)dVar22;
                    }
                    else {
                      *(float *)&this->field_0x3b8 = d_camera::_5311;
                    }
                  }
                  else {
                    *(float *)&this->field_0x3b8 = d_camera::_10152;
                  }
                }
              }
            }
          }
          else {
            uVar10 = *(uint *)&this->field_0x38c;
            if (uVar10 == 0) {
              if ((__270 < local_4ac[0]) && (local_4ac[0] < __90)) {
                *(undefined4 *)&this->field_0x38c = 1;
              }
              else {
                *(undefined4 *)&this->field_0x38c = 0xffffffff;
              }
            }
            else {
              if ((int)uVar10 < 0) {
                *(uint *)&this->field_0x38c = uVar10 - 1;
                if (*(int *)&this->field_0x38c < -0x1f) {
                  *(undefined4 *)&this->field_0x38c = 0x10;
                }
              }
              else {
                if ((int)uVar10 < 0xf) {
                  fStack332 = (float)(uVar10 ^ 0x80000000);
                  local_150 = 176.0;
                  *(float *)&this->field_0x3b8 =
                       d_camera::_10150 *
                       (float)((double)CONCAT44(0x43300000,fStack332) - d_camera::_5738);
                  *(int *)&this->field_0x38c = *(int *)&this->field_0x38c + 1;
                }
                else {
                  iVar6 = @unnamed@d_camera_cpp@::check_owner_action
                                    ((_unnamed_d_camera_cpp_ *)this->mPadId,0x2000000,(ulong)pcVar7)
                  ;
                  if (iVar6 == 0) {
                    if (d_camera::_10148 <= this->mStickMainValueLast) {
                      psVar11 = (std *)cSAngle::Sin(local_4ac);
                      fVar42 = std::fabsf(psVar11,(float)extraout_f1_01);
                      dVar22 = (double)dCamMath::rationalBezierRatio(fVar42,d_camera::_10151);
                      *(float *)&this->field_0x3b8 = (float)dVar22;
                    }
                    else {
                      *(float *)&this->field_0x3b8 = d_camera::_5311;
                    }
                  }
                }
              }
            }
          }
        }
        else {
          if (*(char *)&this->field_0x3d8 != '\0') {
            *(float *)&this->field_0x3b8 = d_camera::_5311;
          }
          *(undefined *)&this->field_0x3d8 = 0;
          *(float *)&this->field_0x3b8 =
               *(float *)&this->field_0x3b8 +
               (d_camera::_6431 - *(float *)&this->field_0x3b8) * d_camera::_5311;
        }
      }
      else {
        *(undefined *)&this->field_0x3d8 = 1;
      }
    }
    else {
      if (*(char *)&this->field_0x3d8 != '\0') {
        *(float *)&this->field_0x3b8 = d_camera::_5311;
      }
      *(undefined *)&this->field_0x3d8 = 0;
      *(float *)&this->field_0x3b8 =
           *(float *)&this->field_0x3b8 +
           (d_camera::1_0 - *(float *)&this->field_0x3b8) * d_camera::_9011;
    }
  }
  else {
    local_158 = (double)CONCAT44(0x43300000,(int)sVar13 ^ 0x80000000);
    fStack332 = (float)(uVar19 ^ 0x80000000);
    local_150 = 176.0;
    dVar22 = (double)dCamMath::rationalBezierRatio
                               ((float)(local_158 - d_camera::_5738) /
                                (float)((double)CONCAT44(0x43300000,fStack332) - d_camera::_5738),
                                (float)dVar40);
    *(undefined *)&this->field_0x3d8 = 1;
    *(float *)&this->field_0x3b8 =
         (float)((double)(d_camera::1_0 - *(float *)&this->field_0x3b8) * dVar22);
  }
  cVar14 = chkFlag(this,0x80);
  if ((((cVar14 == '\0') || (cVar14 = chkFlag(this,0x80000), cVar14 != '\0')) ||
      (this->mCurMode != 0)) || (*(int *)&this->field_0x38c != 0)) {
    if (sVar12 == 0 && !bVar1) {
      sVar12 = cSAngle::Inv(acStack1192);
      cSAngle::cSAngle(acStack1300,sVar12);
      cSAngle::operator__(acStack1204,acStack1300);
      cSAngle::_cSAngle(acStack1300);
    }
    else {
      cSAngle::operator__(acStack1204,acStack1192);
      iVar6 = @unnamed@d_camera_cpp@::check_owner_action
                        ((_unnamed_d_camera_cpp_ *)this->mPadId,0x60,(ulong)pcVar7);
      if (iVar6 != 0) {
        cSAngle::operator___(acStack1204,acStack1184);
      }
    }
  }
  else {
    cSAngle::cSAngle(acStack1296,(this->field_0xe).v);
    cSAngle::operator__(acStack1204,acStack1296);
    cSAngle::_cSAngle(acStack1296);
  }
  cSAngle::cSAngle(acStack1208,0);
  cSAngle::operator__(acStack1304,acStack1204);
  pcVar18 = &local_484.mAngleX;
  dVar22 = (double)cSAngle::Cos(pcVar18);
  cSAngle::operator_(acStack1308,(float)((double)*(float *)&this->field_0x3b8 * dVar22));
  cSAngle::operator__(acStack1312,&local_484.mAngleY);
  pcVar17 = acStack1208;
  cSAngle::operator__(acStack1316,acStack1312);
  cSGlobe::U(&this->field_0x3c,acStack1316);
  cSAngle::_cSAngle(acStack1316);
  cSAngle::_cSAngle(acStack1312);
  cSAngle::_cSAngle(acStack1308);
  cSAngle::_cSAngle(acStack1304);
  iVar6 = @unnamed@d_camera_cpp@::check_owner_action1
                    ((_unnamed_d_camera_cpp_ *)this->mPadId,0x20000,(ulong)pcVar17);
  if (iVar6 == 0) {
    if (*(short *)&this->field_0x392 != 0) {
      *(float *)&this->field_0x3e0 = d_camera::0_0;
    }
    *(undefined2 *)&this->field_0x392 = 0;
    if (this->mCurMode == 1) {
      *(float *)&this->field_0x3e0 = d_camera::_6431;
      fVar42 = (float)((double)*(float *)this->mEvRelUseMask +
                      (double)(*(float *)&this->field_0x3b8 *
                              (float)(dVar31 - (double)*(float *)this->mEvRelUseMask)));
      *(float *)this->mEvRelUseMask = fVar42;
      *(float *)&this->field_0x3bc = fVar42;
      sVar12 = cAngle::d2s((cAngle *)0x0,*(float *)this->mEvRelUseMask);
      cSAngle::cSAngle(acStack1320,sVar12);
      cSAngle::operator__(local_4bc,acStack1320);
      cSAngle::_cSAngle(acStack1320);
      *(float *)&this->field_0x3e0 =
           (float)((double)*(float *)&this->field_0x3e0 +
                  (double)(d_camera::_6431 * (float)(dVar39 - (double)*(float *)&this->field_0x3e0))
                  );
    }
    else {
      if (*(int *)&this->field_0x388 == 0) {
        *(float *)&this->field_0x3bc =
             (float)((double)*(float *)&this->field_0x3bc +
                    (double)(float)(dVar30 * (double)(float)(dVar31 - (double)*(float *)&this->
                                                  field_0x3bc)));
        dVar22 = (double)d_camera::_6065;
        if ((this->mEvBasePos).z != 0.0) {
          dVar22 = (double)d_camera::0_25;
          dVar32 = dVar22;
        }
        this_00 = (cAngle *)cSAngle::Degree(&this->field_0x148);
        *(float *)this->mEvRelUseMask =
             *(float *)this->mEvRelUseMask +
             (float)(dVar32 * (double)((float)((double)*(float *)&this->field_0x3bc + extraout_f1_03
                                              ) - *(float *)this->mEvRelUseMask));
        sVar12 = cAngle::d2s(this_00,*(float *)this->mEvRelUseMask);
        cSAngle::cSAngle(acStack1324,sVar12);
        cSAngle::operator__(local_4bc,acStack1324);
        cSAngle::_cSAngle(acStack1324);
        cVar14 = chkFlag(this,0x80000);
        if (cVar14 == '\0') {
          if ((this->mEvBasePos).z == 0.0) {
            if ((d_camera::_6065 <= this->field_0x234) || (this->mCurMode != 0)) {
              *(float *)&this->field_0x3e0 =
                   (float)((double)*(float *)&this->field_0x3e0 +
                          (double)(float)(dVar22 * (double)(float)(dVar39 - (double)*(float *)&this
                                                  ->field_0x3e0)));
            }
            else {
              *(float *)&this->field_0x3e0 =
                   *(float *)&this->field_0x3e0 +
                   d_camera::_5311 * (d_camera::_10148 - *(float *)&this->field_0x3e0);
            }
          }
          else {
            *(float *)&this->field_0x3e0 =
                 (float)((double)*(float *)&this->field_0x3e0 +
                        (double)(float)(dVar22 * (double)(float)(dVar39 - (double)*(float *)&this->
                                                  field_0x3e0)));
          }
        }
        else {
          *(float *)&this->field_0x3e0 = d_camera::0_0;
        }
      }
      else {
        iVar6 = @unnamed@d_camera_cpp@::check_owner_action
                          ((_unnamed_d_camera_cpp_ *)this->mPadId,0x2000000,(ulong)pcVar17);
        if (iVar6 == 0) {
          uVar41 = @unnamed@d_camera_cpp@::check_owner_action1
                             ((_unnamed_d_camera_cpp_ *)this->mPadId,0x10000,(ulong)pcVar17);
          if ((int)((ulonglong)uVar41 >> 0x20) == 0) {
            cVar14 = @unnamed@d_camera_cpp@::isPlayerFlying
                               ((_unnamed_d_camera_cpp_ *)this->mPadId,(ulong)uVar41);
            if ((cVar14 == '\0') && (daNpc_kam_c::m_hyoi_kamome == 0)) {
              cSAngle::operator__(local_4bc,pcVar18);
              dVar32 = (double)cSAngle::Degree(local_4bc);
              *(float *)this->mEvRelUseMask = (float)dVar32;
              *(float *)&this->field_0x3bc = (float)dVar32;
              dVar32 = (double)dCamMath::rationalBezierRatio(this->mEvFovy,(float)dVar33);
              *(float *)&this->field_0x3e0 = (float)dVar32;
            }
            else {
              cSAngle::operator__(local_4bc,pcVar18);
              positionOf(&cStack1028,this,this->mpPlayerActor);
              fVar42 = (float)this->mEvTimer;
              ::cXyz::_cXyz(&cStack1028);
              if (cStack1028.y <= fVar42) {
                *(float *)&this->field_0x3e0 =
                     *(float *)&this->field_0x3e0 +
                     d_camera::_10152 * (d_camera::_8359 - *(float *)&this->field_0x3e0);
              }
              else {
                dVar32 = (double)dCamMath::rationalBezierRatio(this->mEvFovy,(float)dVar33);
                *(float *)&this->field_0x3e0 = (float)dVar32;
              }
              dVar32 = (double)cSAngle::Degree(local_4bc);
              *(float *)this->mEvRelUseMask = (float)dVar32;
              *(float *)&this->field_0x3bc = (float)dVar32;
            }
            goto LAB_8016bedc;
          }
        }
        cSAngle::operator__(local_4bc,pcVar18);
        dVar32 = (double)cSAngle::Degree(local_4bc);
        *(float *)this->mEvRelUseMask = (float)dVar32;
        *(float *)&this->field_0x3bc = (float)dVar32;
        *(float *)&this->field_0x3e0 = d_camera::_7227;
      }
    }
  }
  else {
    if ((int)uVar19 < (int)*(short *)&this->field_0x392) {
      cSAngle::operator__(local_4bc,acStack1168);
      *(float *)&this->field_0x3e0 = d_camera::1_0;
    }
    else {
      cSAngle::operator__(local_4bc,acStack1168);
      fStack332 = (float)((int)*(short *)&this->field_0x392 ^ 0x80000000);
      local_150 = 176.0;
      local_158 = (double)CONCAT44(0x43300000,uVar19 ^ 0x80000000);
      dVar32 = (double)dCamMath::rationalBezierRatio
                                 ((float)((double)CONCAT44(0x43300000,fStack332) - d_camera::_5738)
                                  / (float)(local_158 - d_camera::_5738),(float)dVar40);
      *(float *)&this->field_0x3e0 = (float)dVar32;
      setFlag(this,0x4000000);
      *(short *)&this->field_0x392 = *(short *)&this->field_0x392 + 1;
    }
    dVar32 = (double)cSAngle::Degree(local_4bc);
    *(float *)this->mEvRelUseMask = (float)dVar32;
    *(float *)&this->field_0x3bc = (float)dVar32;
  }
LAB_8016bedc:
  pfVar16 = this->mpPlayerActor;
  positionOf(&cStack1040,this,pfVar16);
  this->mEvTimer = (int)cStack1040.y;
  ::cXyz::_cXyz(&cStack1040);
  iVar6 = @unnamed@d_camera_cpp@::check_owner_action
                    ((_unnamed_d_camera_cpp_ *)this->mPadId,0x2000161,(ulong)pfVar16);
  if ((iVar6 == 0) &&
     (iVar6 = @unnamed@d_camera_cpp@::check_owner_action1
                        ((_unnamed_d_camera_cpp_ *)this->mPadId,0x10000,(ulong)pfVar16), iVar6 == 0)
     ) {
    (this->mEvBasePos).z = 0.0;
  }
  else {
    (this->mEvBasePos).z = 1.401298e-45;
  }
  if (local_4bc[0] < local_498[0]) {
    cSAngle::Val(local_4bc,local_498);
  }
  else {
    if (local_49c[0] < local_4bc[0]) {
      cSAngle::Val(local_4bc,local_49c);
    }
  }
  pcVar17 = &(this->field_0x3c).mAngleX;
  cSAngle::operator__(acStack1328,local_4bc);
  cSAngle::operator_(acStack1332,*(float *)&this->field_0x3e0);
  cSAngle::operator__(acStack1336,pcVar17);
  cSGlobe::V(&this->field_0x3c,acStack1336);
  cSAngle::_cSAngle(acStack1336);
  cSAngle::_cSAngle(acStack1332);
  cSAngle::_cSAngle(acStack1328);
  if (local_494[0] < pcVar17->v) {
    cSGlobe::V(&this->field_0x3c,local_494);
  }
  this->mEvBank =
       (float)((double)this->mEvBank +
              (double)(float)(dVar30 * (double)(float)(dVar28 - (double)this->mEvBank)));
  this->mpEvRelActor =
       (fopAc_ac_c *)
       (float)((double)(float)this->mpEvRelActor +
              (double)(float)(dVar30 * (double)(float)(dVar27 - (double)(float)this->mpEvRelActor)))
  ;
  if (this->mEvBank <= local_484.mDistance) {
    if (local_484.mDistance <= (float)this->mpEvRelActor) {
      *(float *)&this->field_0x3dc = d_camera::1_0;
    }
    else {
      *(float *)&this->field_0x3dc =
           (float)((double)*(float *)&this->field_0x3dc +
                  (double)(d_camera::_6065 * (float)(dVar29 - (double)*(float *)&this->field_0x3dc))
                  );
      local_484.mDistance = (float)this->mpEvRelActor;
    }
  }
  else {
    *(float *)&this->field_0x3dc =
         (float)((double)*(float *)&this->field_0x3dc +
                (double)(d_camera::_6065 * (float)(dVar29 - (double)*(float *)&this->field_0x3dc)));
    local_484.mDistance = this->mEvBank;
  }
  fVar42 = (this->field_0x3c).mDistance;
  (this->field_0x3c).mDistance =
       fVar42 + *(float *)&this->field_0x3dc * (local_484.mDistance - fVar42);
  cSGlobe::Xyz(&cStack1052,&this->field_0x3c);
  ::cXyz::operator__(&cStack1064,&this->field_0x44,&cStack1052);
  ::cXyz::operator__((cXyz *)&this->field_0x3cc,&cStack1064);
  ::cXyz::_cXyz(&cStack1064);
  ::cXyz::_cXyz(&cStack1052);
  if (((bVar4) && (bVar5)) && (sVar12 = dCamParam_c::Flag(&this->mCamParam,param_1,1), sVar12 != 0))
  {
    cSGlobe::cSGlobe(&cStack1164,&this->field_0x3c);
    cSAngle::cSAngle(acStack1340,(float)dVar31);
    cSGlobe::V(&cStack1164,acStack1340);
    cSAngle::_cSAngle(acStack1340);
    cSGlobe::Xyz(&cStack1076,&cStack1164);
    ::cXyz::operator__(&cStack1088,&this->field_0x44,&cStack1076);
    ::cXyz::cXyz(&cStack692,&cStack1088);
    ::cXyz::_cXyz(&cStack1088);
    ::cXyz::_cXyz(&cStack1076);
    cVar14 = lineBGCheck(this,&this->field_0x44,&cStack692,0x7f);
    if (cVar14 != '\0') {
      setFlag(this,8);
    }
    ::cXyz::_cXyz(&cStack692);
    cSGlobe::_cSGlobe(&cStack1164);
  }
  ::cXyz::operator__(&cStack1100,(cXyz *)&this->field_0x3cc,&this->field_0x50);
  ::cXyz::operator_(&cStack1112,&cStack1100,d_camera::_8359);
  ::cXyz::operator___(&this->field_0x50,(Vec *)&cStack1112);
  ::cXyz::_cXyz(&cStack1112);
  ::cXyz::_cXyz(&cStack1100);
  pcVar7 = &this->field_0x44;
  ::cXyz::operator__(&cStack1124,&this->field_0x50,pcVar7);
  cSGlobe::Val(&this->field_0x3c,&cStack1124);
  ::cXyz::_cXyz(&cStack1124);
  cVar14 = chkFlag(this,8);
  if (cVar14 != '\0') {
    *(undefined *)&this->field_0x3da = 1;
  }
  *(float *)&this->field_0x3e8 =
       (float)((double)*(float *)&this->field_0x3e8 +
              (double)(d_camera::_6065 * (float)(local_148 - (double)*(float *)&this->field_0x3e8)))
  ;
  this->field_0x60 =
       (float)((double)this->field_0x60 +
              (double)(*(float *)&this->field_0x3e8 * (float)(dVar34 - (double)this->field_0x60)));
  uVar41 = @unnamed@d_camera_cpp@::check_owner_action1
                     ((_unnamed_d_camera_cpp_ *)this->mPadId,0x40,(ulong)pcVar7);
  uVar15 = (ulong)uVar41;
  if ((int)((ulonglong)uVar41 >> 0x20) != 0) {
    fVar42 = SComponent::cM_rndFX((this->mCamSetup).field_0x78);
    this->field_0x60 = this->field_0x60 + fVar42;
  }
  cVar14 = @unnamed@d_camera_cpp@::isPlayerFlying((_unnamed_d_camera_cpp_ *)this->mPadId,uVar15);
  if ((cVar14 != '\0') || (daNpc_kam_c::m_hyoi_kamome != 0)) {
    if ((double)d_camera::_5129 <= dVar23) {
      fVar42 = this->mStickMainPosXLast;
      fVar2 = d_camera::_10142;
    }
    else {
      fVar2 = (float)(dVar23 / (double)d_camera::_5129);
      fVar42 = this->mStickMainPosXLast * fVar2;
      fVar2 = d_camera::1_0 - d_camera::_10153 * fVar2;
    }
    dVar27 = (double)fVar2;
    dVar28 = (double)fVar42;
    cSAngle::cSAngle(acStack1344,(short)(*(int *)&this->field_0x7c << 7));
    dVar31 = (double)(this->mCamSetup).field_0x7c;
    dVar32 = (double)cSAngle::Sin(acStack1344);
    this->field_0x60 = this->field_0x60 + (float)(dVar31 * dVar32);
    cSAngle::_cSAngle(acStack1344);
    dVar32 = (double)dCamSetup_c::FanBank(&this->mCamSetup);
    cSAngle::cSAngle(acStack1216,(float)(dVar28 * dVar32));
    cSAngle::operator__(acStack1348,acStack1216);
    cSAngle::operator_(acStack1352,(float)dVar27);
    cSAngle::operator___((cSAngle *)&this->field_0x5c,acStack1352);
    cSAngle::_cSAngle(acStack1352);
    cSAngle::_cSAngle(acStack1348);
    setFlag(this,0x400);
    cSAngle::_cSAngle(acStack1216);
  }
  cSAngle::_cSAngle(local_4bc);
  cSAngle::_cSAngle(acStack1208);
  cSAngle::_cSAngle(acStack1204);
  cSGlobe::_cSGlobe(&local_484);
  ::cXyz::_cXyz(&cStack644);
  ::cXyz::_cXyz(&cStack632);
  cSAngle::_cSAngle(local_4ac);
  cSAngle::_cSAngle(acStack1192);
  ::cXyz::_cXyz(&cStack608);
  ::cXyz::_cXyz(&local_23c);
  cSAngle::_cSAngle(acStack1184);
  cSAngle::_cSAngle(local_49c);
  cSAngle::_cSAngle(local_498);
  cSAngle::_cSAngle(local_494);
  cSAngle::_cSAngle(acStack1168);
LAB_8016c450:
  __psq_l0(auStack8,uVar21);
  __psq_l1(auStack8,uVar21);
  __psq_l0(auStack24,uVar21);
  __psq_l1(auStack24,uVar21);
  __psq_l0(auStack40,uVar21);
  __psq_l1(auStack40,uVar21);
  __psq_l0(auStack56,uVar21);
  __psq_l1(auStack56,uVar21);
  __psq_l0(auStack72,uVar21);
  __psq_l1(auStack72,uVar21);
  __psq_l0(auStack88,uVar21);
  __psq_l1(auStack88,uVar21);
  __psq_l0(auStack104,uVar21);
  __psq_l1(auStack104,uVar21);
  __psq_l0(auStack120,uVar21);
  __psq_l1(auStack120,uVar21);
  __psq_l0(auStack136,uVar21);
  __psq_l1(auStack136,uVar21);
  __psq_l0(auStack152,uVar21);
  __psq_l1(auStack152,uVar21);
  __psq_l0(auStack168,uVar21);
  __psq_l1(auStack168,uVar21);
  __psq_l0(auStack184,uVar21);
  __psq_l1(auStack184,uVar21);
  __psq_l0(auStack200,uVar21);
  __psq_l1(auStack200,uVar21);
  __psq_l0(auStack216,uVar21);
  __psq_l1(auStack216,uVar21);
  __psq_l0(auStack232,uVar21);
  __psq_l1(auStack232,uVar21);
  __psq_l0(auStack248,uVar21);
  __psq_l1(auStack248,uVar21);
  __psq_l0(auStack264,uVar21);
  __psq_l1(auStack264,uVar21);
  __psq_l0(auStack280,uVar21);
  __psq_l1(auStack280,uVar21);
  return 1;
}


/* __thiscall @unnamed@d_camera_cpp@::isPlayerFlying(unsigned long) */

undefined4 __thiscall
@unnamed@d_camera_cpp@::isPlayerFlying(_unnamed_d_camera_cpp_ *this,ulong param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (((((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5ccc)[(int)this * 4] & 0x20U) != 0) ||
      (daNpc_Cb1_c::m_flying != '\0')) || (daNpc_Md_c::m_flying != '\0')) {
    uVar1 = 1;
  }
  return uVar1;
}


/* __thiscall cAngle::d2s(float) */

int __thiscall cAngle::d2s(cAngle *this,float param_1)

{
  return (int)(d_camera::_8358 * param_1);
}


/* __thiscall dCamera_c::eyePos(fopAc_ac_c *) */

cXyz * __thiscall dCamera_c::eyePos(cXyz *__return_storage_ptr__,dCamera_c *this,fopAc_ac_c *pActor)

{
  __return_storage_ptr__->x = (pActor->mEyePos).x;
  __return_storage_ptr__->y = (pActor->mEyePos).y;
  __return_storage_ptr__->z = (pActor->mEyePos).z;
  return __return_storage_ptr__;
}


/* __thiscall cBgS::GetTriPla(cBgS_PolyInfo &) const */

void __thiscall cBgS::GetTriPla(cBgS *this,cBgS_PolyInfo *param_1)

{
  GetTriPla(this,(uint)(ushort)param_1->mBgIndex,(uint)(ushort)param_1->mTriIdx);
  return;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall dCamera_c::heightOf(fopAc_ac_c *) */

double __thiscall dCamera_c::heightOf(dCamera_c *this,fopAc_ac_c *param_1)

{
  if ((param_1->parent).parent.mProcName == 0xa9) {
    return (double)(float)param_1[1].parent.parent.mLyTg.parent.parent.mpData;
  }
  return (double)(d_camera::_8357 * ((param_1->mEyePos).y - (param_1->mCurrent).mPos.y));
}


/* __thiscall cXyz::cXyz(float,
                         float,
                         float) */

void __thiscall cXyz::cXyz(cXyz *this,float param_1,float param_2,float param_3)

{
  this->x = param_1;
  this->y = param_2;
  this->z = param_3;
  return;
}


/* __thiscall @unnamed@d_camera_cpp@::check_owner_action1(unsigned long,
                                                          unsigned long) */

uint __thiscall
@unnamed@d_camera_cpp@::check_owner_action1
          (_unnamed_d_camera_cpp_ *this,ulong param_1,ulong param_2)

{
  return (&d_com_inf_game::g_dComIfG_gameInfo.field_0x5ccc)[(int)this * 4] & param_1;
}


/* __thiscall @unnamed@d_camera_cpp@::check_owner_action(unsigned long,
                                                         unsigned long) */

uint __thiscall
@unnamed@d_camera_cpp@::check_owner_action(_unnamed_d_camera_cpp_ *this,ulong param_1,ulong param_2)

{
  return (&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[(int)this * 4] & param_1;
}


/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* WARNING: Removing unreachable block (ram,0x8016d7fc) */
/* WARNING: Removing unreachable block (ram,0x8016d7ec) */
/* WARNING: Removing unreachable block (ram,0x8016d7dc) */
/* WARNING: Removing unreachable block (ram,0x8016d7cc) */
/* WARNING: Removing unreachable block (ram,0x8016d7c4) */
/* WARNING: Removing unreachable block (ram,0x8016d7d4) */
/* WARNING: Removing unreachable block (ram,0x8016d7e4) */
/* WARNING: Removing unreachable block (ram,0x8016d7f4) */
/* WARNING: Removing unreachable block (ram,0x8016d804) */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall dCamera_c::lockonCamera(long) */

undefined4 __thiscall dCamera_c::lockonCamera(dCamera_c *this,long param_1)

{
  bool bVar1;
  uint uVar2;
  short sVar6;
  undefined4 uVar3;
  char cVar7;
  int iVar4;
  fopAc_ac_c *pfVar5;
  cSAngle *this_00;
  cSAngle *this_01;
  cSAngle *this_02;
  uint uVar8;
  uint uVar9;
  undefined4 uVar10;
  double dVar11;
  double dVar12;
  undefined8 in_f23;
  undefined8 in_f24;
  double dVar13;
  undefined8 in_f25;
  double dVar14;
  undefined8 in_f26;
  double dVar15;
  undefined8 in_f27;
  double dVar16;
  undefined8 in_f28;
  double dVar17;
  undefined8 in_f29;
  double dVar18;
  undefined8 in_f30;
  double dVar19;
  undefined8 in_f31;
  double dVar20;
  float fVar21;
  cSAngle acStack792 [2];
  undefined auStack788 [4];
  cSAngle acStack784 [2];
  cSAngle acStack780 [2];
  cSAngle acStack776 [2];
  cSAngle acStack772 [2];
  cSAngle acStack768 [2];
  undefined auStack764 [4];
  cSAngle acStack760 [2];
  cSAngle acStack756 [2];
  cSAngle local_2f0 [2];
  cSAngle acStack748 [2];
  cSAngle acStack744 [2];
  cSAngle acStack740 [2];
  cSAngle local_2e0 [2];
  cSAngle local_2dc [2];
  cSAngle local_2d8 [2];
  cSAngle acStack724 [2];
  cSAngle acStack720 [2];
  cSAngle acStack716 [2];
  cSAngle acStack712 [2];
  cSAngle acStack708 [2];
  cSAngle acStack704 [2];
  cSAngle acStack700 [2];
  cSAngle acStack696 [2];
  cSAngle acStack692 [2];
  cSAngle acStack688 [2];
  cSAngle acStack684 [2];
  cSAngle acStack680 [2];
  cSAngle acStack676 [2];
  cSAngle acStack672 [2];
  cSAngle acStack668 [2];
  cSAngle local_298 [2];
  cSAngle acStack660 [2];
  cSAngle acStack656 [2];
  cSAngle acStack652 [2];
  cSAngle acStack648 [2];
  cSAngle local_284 [2];
  cSAngle local_280 [2];
  cSAngle local_27c [2];
  cSAngle acStack632 [2];
  cSAngle local_274 [2];
  cSAngle local_270 [2];
  cSAngle acStack620 [2];
  cSAngle acStack616 [2];
  cSAngle acStack612 [2];
  cSAngle acStack608 [2];
  cSAngle local_25c [2];
  cSAngle local_258 [2];
  cSAngle acStack596 [2];
  cSAngle local_250 [2];
  float local_24c;
  float local_248;
  float local_244;
  cSGlobe local_240;
  cSGlobe cStack568;
  cSGlobe local_230;
  cXyz local_228;
  cXyz cStack540;
  cXyz local_210;
  cXyz local_204;
  cXyz local_1f8;
  cXyz cStack492;
  cXyz cStack480;
  cXyz local_1d4;
  cXyz local_1c8;
  cXyz cStack444;
  cXyz local_1b0;
  cXyz local_1a4;
  cXyz cStack408;
  cXyz cStack396;
  cXyz local_180;
  cXyz local_174;
  cXyz local_168;
  cXyz local_15c;
  cXyz cStack336;
  cXyz cStack324;
  cXyz local_138;
  cXyz local_12c;
  cXyz local_120;
  cXyz local_114;
  cXyz local_108;
  cXyz local_fc;
  cXyz local_f0;
  undefined *local_e0;
  undefined *puStack220;
  int local_d8;
  uint uStack212;
  int local_d0;
  uint uStack204;
  undefined4 local_c8;
  uint uStack196;
  undefined auStack136 [16];
  undefined auStack120 [16];
  undefined auStack104 [16];
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar10 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  __psq_st0(auStack72,(int)((ulonglong)in_f27 >> 0x20),0);
  __psq_st1(auStack72,(int)in_f27,0);
  __psq_st0(auStack88,(int)((ulonglong)in_f26 >> 0x20),0);
  __psq_st1(auStack88,(int)in_f26,0);
  __psq_st0(auStack104,(int)((ulonglong)in_f25 >> 0x20),0);
  __psq_st1(auStack104,(int)in_f25,0);
  __psq_st0(auStack120,(int)((ulonglong)in_f24 >> 0x20),0);
  __psq_st1(auStack120,(int)in_f24,0);
  __psq_st0(auStack136,(int)((ulonglong)in_f23 >> 0x20),0);
  __psq_st1(auStack136,(int)in_f23,0);
  uVar8 = (this->mCamSetup).field_0xb0;
  dVar19 = (double)(this->mCamSetup).field_0xb4;
  cSAngle::cSAngle(acStack648,(this->mCamSetup).field_0xa4);
  cSAngle::cSAngle(local_250,acStack648);
  uVar9 = (this->mCamSetup).field_0xa8;
  dVar18 = (double)(this->mCamSetup).field_0xac;
  dVar17 = (double)dCamParam_c::styles[param_1].field_0x18;
  dVar16 = (double)dCamParam_c::styles[param_1].field_0x14;
  if (this->field_0x108 == 0) {
    *(undefined *)&this->field_0x100 = 1;
    *(undefined *)&this->field_0x101 = 1;
    *(undefined *)&this->field_0x102 = 1;
    *(undefined4 *)&this->field_0x378 = 0x4c4f434b;
    *(undefined4 *)&this->field_0x380 = 0;
    *(float *)&this->field_0x384 = d_camera::1_0;
    *(undefined *)&this->field_0x38c = 0;
    *(undefined *)&this->mpEvRelActor = 0;
    *(float *)&this->field_0x390 = (this->field_0x44).x;
    this->mEvFovy = (this->field_0x44).y;
    this->mEvBank = (this->field_0x44).z;
    attentionPos(&cStack324,this,this->mpPlayerActor);
    ::cXyz::operator__(&cStack336,&this->field_0x44,&cStack324);
    cSGlobe::Val((cSGlobe *)&this->field_0x3a8,&cStack336);
    fVar21 = d_camera::0_0;
    (this->mEvBasePos).z = d_camera::0_0;
    (this->mEvBasePos).y = fVar21;
    *(float *)&this->field_0x3b8 = (this->mCamSetup).field_0x38;
    *(undefined4 *)&this->field_0x388 = 0;
    *(undefined *)((int)&this->mpEvRelActor + 1) = 0;
    *(undefined4 *)this->mEvRelUseMask = 0;
    this->mEvTimer = 0;
    if (this->mpLockonTarget != (fopAc_ac_c *)0x0) {
      radiusActorInSight(this,this->mpPlayerActor,this->mpLockonTarget);
    }
  }
  if (this->field_0x31d != 0) {
    dBgS::MoveBgMatrixCrrPos
              (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,&(this->mBG).field_0x74,true,
               (cXyz *)&this->field_0x390,(csXyz *)0x0,(csXyz *)0x0);
  }
  uVar2 = dAttention_c::LockonTruth(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAttention);
  if (((uVar2 & 0xff) == 0) &&
     (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4] & 0x400000U) != 0)) {
    *(undefined *)&this->mpEvRelActor = 1;
  }
  else {
    *(undefined *)&this->mpEvRelActor = 0;
  }
  if (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4] & 0x400U) == 0) {
    *(undefined *)((int)&this->mpEvRelActor + 1) = 0;
  }
  else {
    if (*(char *)((int)&this->mpEvRelActor + 1) == '\0') {
      local_15c.x = d_camera::0_0;
      local_15c.y = d_camera::1_0;
      local_15c.z = d_camera::0_0;
      dVibration_c::StartShock
                (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mVibration,2,0x10,&local_15c);
    }
    *(undefined *)((int)&this->mpEvRelActor + 1) = 1;
  }
  bVar1 = true;
  if (((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAttention.mFlags >> 3 & 1) == 0) &&
     ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAttention.mFlags & 0x20) == 0)) {
    bVar1 = false;
  }
  if (bVar1) {
    this->field_0x11c = 0;
    this->field_0x108 = 0;
    this->mEventFlags = this->mEventFlags & 0xfffffeff;
  }
  dVar15 = (double)(this->mCamSetup).field_0x4c;
  dVar11 = (double)dAttention_c::LockonReleaseDistanse
                             (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAttention);
  dVar14 = (double)d_camera::_10804;
  if (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4] & 0x61U) == 0) {
    if (this->mpLockonTarget == (fopAc_ac_c *)0x0) {
      directionOf((dCamera_c *)acStack656,(fopAc_ac_c *)this);
      cSGlobe::Val(&local_230,(this->mCamSetup).field_0x40,&cSAngle::_0,acStack656);
      dVar20 = (double)d_camera::1_0;
    }
    else {
      attentionPos(&local_168,this,this->mpLockonTarget);
      local_f0.x = local_168.x;
      local_f0.y = local_168.y;
      local_f0.z = local_168.z;
      attentionPos(&local_174,this,this->mpPlayerActor);
      local_fc.x = local_174.x;
      local_fc.y = local_174.y;
      local_fc.z = local_174.z;
      if ((this->mpLockonTarget->parent).parent.mProcName == 0xf0) {
        positionOf(&local_180,this,this->mpLockonTarget);
        local_f0.x = local_180.x;
        positionOf(&cStack396,this,this->mpLockonTarget);
        local_f0.z = cStack396.z;
      }
      ::cXyz::operator__(&cStack408,&local_f0,&local_fc);
      cSGlobe::Val(&local_230,&cStack408);
      dVar20 = (double)(float)((double)local_230.mDistance / dVar11);
      if ((double)d_camera::1_0 < (double)(float)((double)local_230.mDistance / dVar11)) {
        dVar20 = (double)d_camera::1_0;
      }
      dVar14 = (double)dCamMath::xyzHorizontalDistance(&local_f0,&local_fc);
    }
  }
  else {
    directionOf((dCamera_c *)acStack652,(fopAc_ac_c *)this);
    dVar11 = (double)(this->mCamSetup).field_0x40;
    sVar6 = cSAngle::Inv(acStack652);
    cSGlobe::Val(&local_230,(float)dVar11,0,sVar6);
    dVar20 = (double)d_camera::1_0;
    this->mpLockonTarget = (fopAc_ac_c *)0x0;
  }
  this_02 = &local_230.mAngleY;
  cSAngle::cSAngle(acStack596,this_02);
  sVar6 = dCamParam_c::LockonLongitude(&this->mCamParam,(float)dVar20);
  cSAngle::cSAngle(local_258,sVar6);
  if (((uint)this->field_0x11c < uVar8) && ((this->mEventFlags & 0x100) == 0)) {
    puStack220 = (undefined *)this->field_0x108;
    local_e0 = (undefined *)0x43300000;
    uStack212 = uVar8 ^ 0x80000000;
    local_d8 = 0x43300000;
    cSAngle::operator__(local_258,
                        (float)((double)CONCAT44(0x43300000,puStack220) - d_camera::_9014) /
                        (float)((double)CONCAT44(0x43300000,uStack212) - d_camera::_5738));
  }
  else {
    if (uVar8 <= (uint)this->field_0x11c) {
      this->mEventFlags = this->mEventFlags | 0x100;
    }
  }
  this_01 = &(this->field_0x3c).mAngleY;
  uVar3 = cSAngle::Inv(this_01);
  SComponent::operator__(acStack660,uVar3,acStack596);
  cSAngle::cSAngle(local_25c,acStack660);
  if (local_25c[0] < cSAngle::_0) {
    *(undefined4 *)this->mEvRelUseMask = 0;
    cSAngle::operator___(acStack596,local_258);
    cSAngle::operator__(local_298);
    local_25c[0] = local_298[0];
  }
  else {
    *(undefined4 *)this->mEvRelUseMask = 1;
    cSAngle::operator___(acStack596,local_258);
  }
  attentionPos(&local_1a4,this,this->mpPlayerActor);
  local_108.x = local_1a4.x;
  local_108.y = local_1a4.y;
  local_108.z = local_1a4.z;
  bVar1 = false;
  if ((this->mEventFlags & 0x80080) != 0) {
    attentionPos(&local_1b0,this,this->mpPlayerActor);
    local_114.x = local_1b0.x;
    local_114.y = local_1b0.y;
    local_114.z = local_1b0.z;
    cVar7 = pointInSight(this,&local_114);
    if (cVar7 == '\0') {
      if (*(int *)&this->field_0x388 == 0) {
        iVar4 = -*(int *)this->mEvRelUseMask + 1;
        this->mEvTimer = iVar4 - ((uint)(iVar4 == 0) + -*(int *)this->mEvRelUseMask);
      }
      bVar1 = true;
      *(undefined4 *)&this->field_0x388 = 0x3c;
    }
  }
  cVar7 = lineBGCheckBack(this,&this->field_0x44,&local_108,0x7f);
  if ((cVar7 != '\0') &&
     (cVar7 = lineBGCheck(this,&this->field_0x50,&this->field_0x44,0x7f), cVar7 != '\0')) {
    bVar1 = true;
    *(undefined4 *)&this->field_0x388 = 0x3c;
  }
  if (*(int *)&this->field_0x388 != 0) {
    *(int *)&this->field_0x388 = *(int *)&this->field_0x388 + -1;
    if ((*(int *)&this->field_0x388 == 0) && (this->mStickMainValueLast <= d_camera::_10148)) {
      *(undefined4 *)&this->field_0x388 = 1;
    }
    bVar1 = true;
  }
  dVar13 = (double)(d_camera::1_0 - ABS(this->mStickCPosYLast));
  dVar11 = (double)dCamParam_c::RadiusRatio(&this->mCamParam,(this->field_0x3c).mDistance);
  dCamMath::customRBRatio((float)dVar11,(float)dVar15);
  fVar21 = d_camera::_6065;
  if ((this->mEventFlags & 0x10) == 0) {
    if (*(char *)&this->field_0x360 == '\0') {
      fVar21 = (this->mCamSetup).field_0x3c;
    }
    else {
      fVar21 = (this->mCamSetup).field_0x38;
    }
  }
  else {
    *(float *)&this->field_0x3b8 = d_camera::_6065;
  }
  *(float *)&this->field_0x3b8 =
       *(float *)&this->field_0x3b8 +
       (fVar21 - *(float *)&this->field_0x3b8) * (this->mCamSetup).field_0x20;
  *(float *)&this->field_0x390 = local_108.x;
  this->mEvBank = local_108.z;
  if (bVar1) {
    dVar11 = (double)dCamParam_c::LockonCenterHeight(&this->mCamParam,(float)dVar20);
    dVar11 = (double)(float)((double)d_camera::_9012 + dVar11);
  }
  else {
    dVar11 = (double)dCamParam_c::LockonCenterHeight(&this->mCamParam,(float)dVar20);
  }
  this->mEvFovy =
       this->mEvFovy +
       *(float *)&this->field_0x3b8 * ((float)((double)local_108.y + dVar11) - this->mEvFovy);
  dVar11 = d_camera::_10805 * (double)local_230.mDistance;
  if (this->mpLockonTarget == (fopAc_ac_c *)0x0) {
    dVar15 = (double)cSAngle::Cos(local_25c);
    dVar15 = (double)local_230.mDistance * ABS(d_camera::_5735 + d_camera::_10807 * dVar15);
  }
  else {
    dVar12 = (double)cSAngle::Cos(local_25c);
    cSAngle::operator_(acStack668,d_camera::_10806);
    cSAngle::cSAngle(acStack672,acStack668);
    dVar15 = (double)cSAngle::Cos(acStack672);
    if (ABS(dVar12) < ABS(dVar15)) {
      dVar15 = dVar12;
    }
    dVar15 = ((double)local_230.mDistance - d_camera::_10808 * dVar11) *
             ABS(d_camera::_5735 + d_camera::_10807 * dVar15);
  }
  cSAngle::cSAngle(acStack608,this_02);
  dVar12 = (double)(this->mEvBasePos).z;
  (this->mEvBasePos).z =
       (float)(dVar12 + (double)((float)(dVar16 - dVar12) * (this->mCamSetup).field_0x20));
  dVar16 = (double)(this->mEvBasePos).y;
  (this->mEvBasePos).y =
       (float)(dVar16 + (double)((float)(dVar17 - dVar16) * (this->mCamSetup).field_0x20));
  cSAngle::operator__(acStack676,acStack608);
  cSAngle::operator_(acStack680,(this->mEvBasePos).z);
  cSAngle::operator__(acStack684,(cSAngle *)((int)&(this->mEvBasePos).x + 2));
  cSAngle::cSAngle(acStack612,acStack684);
  if (bVar1) {
    dVar16 = (double)(d_camera::_8359 * *(float *)&this->field_0x3a8);
    cSAngle::operator__(acStack688,&local_230.mAngleX);
    cSAngle::operator_(acStack692,d_camera::_5311);
    cSAngle::operator__(acStack696,(cSAngle *)&this->mEvBasePos);
    cSAngle::Val(acStack616,acStack696);
  }
  else {
    dVar16 = (double)(*(float *)&this->field_0x3a8 +
                     (this->mEvBasePos).y *
                     (*(float *)&this->field_0x384 * (float)(dVar15 + dVar11) -
                     *(float *)&this->field_0x3a8));
    cSAngle::operator__(acStack700,&local_230.mAngleX);
    cSAngle::operator_(acStack704,(this->mEvBasePos).z);
    cSAngle::operator__(acStack708,(cSAngle *)&this->mEvBasePos);
    cSAngle::Val(acStack616,acStack708);
  }
  cSGlobe::Val((cSGlobe *)&this->field_0x3a8,(float)dVar16,acStack616,acStack612);
  cSGlobe::Xyz(&cStack444,(cSGlobe *)&this->field_0x3a8);
  ::cXyz::operator__(&local_1c8,(cXyz *)&this->field_0x390,&cStack444);
  (this->field_0x44).x = local_1c8.x;
  (this->field_0x44).y = local_1c8.y;
  (this->field_0x44).z = local_1c8.z;
  if ((this->mpLockonTarget != (fopAc_ac_c *)0x0) && (this->field_0x130 != -1)) {
    attentionPos(&local_1d4,this,this->mpPlayerActor);
    local_120.x = local_1d4.x;
    local_120.y = local_1d4.y;
    local_120.z = local_1d4.z;
    cVar7 = lineBGCheck(this,&local_120,&this->field_0x44,0x7f);
    if (cVar7 != '\0') {
      ForceLockOff(this,this->field_0x130);
    }
  }
  ::cXyz::operator__(&cStack480,&this->mEye,&this->field_0x44);
  cSGlobe::cSGlobe(&cStack568,&cStack480);
  ::cXyz::operator__(&cStack492,&this->field_0x50,&this->field_0x44);
  cSGlobe::cSGlobe(&local_240,&cStack492);
  cSAngle::cSAngle(acStack620,this_01);
  this_00 = &(this->field_0x3c).mAngleX;
  cSAngle::cSAngle(local_270,this_00);
  dVar16 = (double)(this->field_0x3c).mDistance;
  cSAngle::operator__(acStack712,local_25c);
  cSAngle::cSAngle(local_274,acStack712);
  fVar21 = (this->mCamSetup).field_0x4c;
  dVar17 = (double)fVar21;
  if (bVar1) {
    if (this->mEvTimer == 1) {
      cSAngle::Val(acStack632,d_camera::_10146);
    }
    else {
      cSAngle::Val(acStack632,d_camera::_10809);
    }
    uVar3 = cSAngle::Inv(this_02);
    SComponent::operator__(acStack716,uVar3,acStack632);
    cSAngle::operator__(acStack720,acStack716);
    cSAngle::operator_(acStack724,d_camera::_5311);
    cSAngle::operator___(acStack620,acStack724);
  }
  else {
    if (this->mpLockonTarget == (fopAc_ac_c *)0x0) {
      dVar17 = (double)(this->mCamSetup).field_0x28;
    }
    else {
      if ((this->mEventFlags & 0x100) == 0) {
        if ((int)local_258[0] == (int)cSAngle::_0) {
          dVar17 = (double)d_camera::_10152;
        }
        else {
          uStack212 = this->field_0x11c;
          local_d8 = 0x43300000;
          puStack220 = (undefined *)(uVar8 ^ 0x80000000);
          local_e0 = (undefined *)0x43300000;
          dVar11 = (double)((float)((double)CONCAT44(0x43300000,uStack212) - d_camera::_9014) /
                           (float)((double)CONCAT44(0x43300000,puStack220) - d_camera::_5738));
          dVar17 = (double)*(float *)&dCamParam_c::styles[param_1].field_0x5c;
          uStack204 = (int)local_274[0] ^ 0x80000000;
          local_d0 = 0x43300000;
          uStack196 = (int)local_258[0] ^ 0x80000000;
          local_c8 = 0x43300000;
          fVar21 = dCamMath::customRBRatio
                             (-((float)((double)CONCAT44(0x43300000,uStack204) - d_camera::_5738) /
                               (float)((double)CONCAT44(0x43300000,uStack196) - d_camera::_5738)),
                              fVar21);
          dVar17 = (double)(float)((double)(float)(dVar17 * (double)fVar21) +
                                  (double)((float)((double)d_camera::1_0 - dVar11) *
                                          (float)(dVar19 - (double)(float)(dVar17 * (double)fVar21))
                                          ));
        }
      }
      else {
        if ((int)local_25c[0] < (int)local_258[0]) {
          dVar17 = (double)*(float *)&dCamParam_c::styles[param_1].field_0x5c;
          uStack196 = (int)local_274[0] ^ 0x80000000;
          local_c8 = 0x43300000;
          uStack204 = (int)local_258[0] ^ 0x80000000;
          local_d0 = 0x43300000;
          fVar21 = dCamMath::customRBRatio
                             (-((float)((double)CONCAT44(0x43300000,uStack196) - d_camera::_5738) /
                               (float)((double)CONCAT44(0x43300000,uStack204) - d_camera::_5738)),
                              fVar21);
          dVar17 = (double)(float)(dVar17 * (double)fVar21);
        }
        else {
          cSAngle::cSAngle(local_27c,d_camera::_10144);
          cSAngle::cSAngle(local_2d8,d_camera::_10810);
          if (((int)(short)(local_258[0] ^ local_2d8[0]) >> 1) -
              (int)(short)((local_258[0] ^ local_2d8[0]) & local_258[0]) < 0) {
            cSAngle::operator__(local_2dc,(cSAngle *)&cSAngle::_180);
            local_27c[0] = local_2dc[0];
          }
          uStack196 = (int)local_274[0] ^ 0x80000000;
          local_c8 = 0x43300000;
          uStack204 = (int)local_27c[0] ^ 0x80000000;
          local_d0 = 0x43300000;
          dVar19 = (double)*(float *)&dCamParam_c::styles[param_1].field_0x58;
          dVar17 = (double)dCamMath::rationalBezierRatio
                                     ((float)((double)CONCAT44(0x43300000,uStack196) -
                                             d_camera::_5738) /
                                      (float)((double)CONCAT44(0x43300000,uStack204) -
                                             d_camera::_5738),(float)dVar17);
          dVar17 = (double)(float)(dVar19 * dVar17);
          if (dVar14 < (double)d_camera::_10811) {
            dVar19 = (double)dCamMath::rationalBezierRatio
                                       ((float)(dVar14 / (double)d_camera::_10811),d_camera::1_0);
            dVar17 = (double)(float)(dVar17 * dVar19);
          }
        }
      }
    }
    uVar3 = cSAngle::Inv(acStack596);
    SComponent::operator__(local_2e0,uVar3,this_01);
    local_274[0] = local_2e0[0];
    cSAngle::Degree(local_274);
    cSAngle::operator_(acStack740,(float)dVar17);
    cSAngle::operator___(acStack620,acStack740);
  }
  if (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5ccc)[this->mPadId * 4] & 0x20000U) == 0) {
    if (bVar1) {
      cSAngle::operator_(local_2f0,d_camera::_10812);
      local_280[0] = local_2f0[0];
      cSAngle::operator__(acStack756,local_280);
      cSAngle::operator_(acStack760,d_camera::_10148);
      cSAngle::operator___(local_270,acStack760);
    }
    else {
      *(undefined4 *)&this->field_0x380 = 0;
      if ((this->mEventFlags & 0x10) == 0) {
        if ((*(char *)&this->field_0x360 == '\0') &&
           (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4] & 0x400U) == 0)) {
          cSAngle::operator__(acStack772,&local_240.mAngleX);
          cSAngle::operator_(acStack776,(float)dVar13);
          dVar17 = (double)cSAngle::Cos(this_00);
          cSAngle::operator_(acStack780,(float)ABS(dVar17));
          cSAngle::operator___(local_270,acStack780);
        }
        else {
          if ((this->mpPlayerActor->parent).parent.mProcName == 0xa9) {
            local_248 = (float)(**(code **)(*(int *)&this->mpPlayerActor[1].parent.parent.mPi.mMtdTg
                                                     .parent.mbAdded + 0x54))();
            pfVar5 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,&local_248);
          }
          else {
            pfVar5 = (fopAc_ac_c *)0x0;
          }
          if ((this->mpLockonTarget == pfVar5) && (*(char *)&this->field_0x784 != '\0')) {
            cSAngle::operator_(acStack784,(this->mCamSetup).field_0x28);
            cSAngle::operator___(local_270,acStack784);
          }
          else {
            uVar3 = dCamParam_c::LockonLatitude(&this->mCamParam,(float)dVar20);
            SComponent::operator__(auStack788,uVar3,local_270);
            cSAngle::operator_(acStack792,(this->mCamSetup).field_0x28);
            cSAngle::operator___(local_270,acStack792);
          }
          if ((this->mpLockonTarget != (fopAc_ac_c *)0x0) &&
             (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4] & 0x400U) != 0))
          {
            attentionPos(&local_1f8,this,this->mpLockonTarget);
            local_12c.x = local_1f8.x;
            local_12c.y = local_1f8.y;
            local_12c.z = local_1f8.z;
            attentionPos(&local_204,this,this->mpPlayerActor);
            local_138.x = local_204.x;
            local_138.z = local_204.z;
            local_138.y = d_camera::0_0;
            local_12c.y = d_camera::0_0;
            ::cXyz::operator__(&local_210,&local_12c,&local_138);
            local_12c.x = local_210.x;
            local_12c.y = local_210.y;
            local_12c.z = local_210.z;
            fVar21 = mtx::PSVECSquareMag(&local_12c);
            dVar17 = (double)fVar21;
            if ((double)d_camera::0_0 < dVar17) {
              dVar18 = 1.0 / SQRT(dVar17);
              dVar18 = d_camera::_5735 * dVar18 * (d_camera::_5736 - dVar17 * dVar18 * dVar18);
              dVar18 = d_camera::_5735 * dVar18 * (d_camera::_5736 - dVar17 * dVar18 * dVar18);
              local_24c = (float)(dVar17 * d_camera::_5735 * dVar18 *
                                           (d_camera::_5736 - dVar17 * dVar18 * dVar18));
            }
          }
        }
      }
      else {
        uVar3 = dCamParam_c::LockonLatitude(&this->mCamParam,(float)dVar20);
        SComponent::operator__(auStack764,uVar3,local_270);
        cSAngle::operator_(acStack768,d_camera::_5311);
        cSAngle::operator___(local_270,acStack768);
      }
      if (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4] & 0x1010000U) == 0)
      {
        local_284[0] = local_270[0];
        cVar7 = dCamSetup_c::CheckLatitudeRange(&this->mCamSetup,&local_284[0].v);
        if (cVar7 == '\0') {
          cSAngle::Val(local_270,local_284[0]);
        }
      }
      else {
        dVar17 = (double)cSAngle::Degree(local_270);
        if (dVar17 < (double)*(float *)&dCamParam_c::styles[param_1].field_0x48) {
          cSAngle::Val(local_270,*(float *)&dCamParam_c::styles[param_1].field_0x48);
        }
        if ((double)*(float *)&dCamParam_c::styles[param_1].field_0x4c < dVar17) {
          cSAngle::Val(local_270,*(float *)&dCamParam_c::styles[param_1].field_0x4c);
        }
      }
    }
  }
  else {
    if ((int)uVar9 < (int)*(uint *)&this->field_0x380) {
      local_270[0] = local_250[0];
    }
    else {
      uStack196 = *(uint *)&this->field_0x380 ^ 0x80000000;
      local_c8 = 0x43300000;
      uStack204 = uVar9 ^ 0x80000000;
      local_d0 = 0x43300000;
      dVar17 = (double)((float)((double)CONCAT44(0x43300000,uStack196) - d_camera::_5738) /
                       (float)((double)CONCAT44(0x43300000,uStack204) - d_camera::_5738));
      cSAngle::operator__(acStack744,local_250);
      dVar17 = (double)dCamMath::rationalBezierRatio((float)dVar17,(float)dVar18);
      cSAngle::operator_(acStack748,(float)dVar17);
      cSAngle::operator___(local_270,acStack748);
      this->mEventFlags = this->mEventFlags | 0x4000000;
      *(int *)&this->field_0x380 = *(int *)&this->field_0x380 + 1;
    }
  }
  if (bVar1) {
    fVar21 = (float)(dVar16 + (double)((float)((double)d_camera::_10813 - dVar16) * d_camera::_5311)
                    );
  }
  else {
    local_244 = local_240.mDistance;
    cVar7 = dCamParam_c::DefaultRadius(&this->mCamParam,&local_244);
    fVar21 = local_244;
    if (cVar7 == '\0') {
      fVar21 = (float)(dVar16 + (double)(d_camera::_5311 * (float)((double)local_244 - dVar16)));
    }
  }
  cSGlobe::Val(&this->field_0x3c,fVar21,local_270,acStack620);
  cSGlobe::Xyz(&cStack540,&this->field_0x3c);
  ::cXyz::operator__(&local_228,&this->field_0x44,&cStack540);
  (this->field_0x50).x = local_228.x;
  (this->field_0x50).y = local_228.y;
  (this->field_0x50).z = local_228.z;
  dVar17 = (double)(this->mCamSetup).field_0x28;
  dVar16 = (double)dCamParam_c::LockonFovy(&this->mCamParam,(float)dVar20);
  this->field_0x60 =
       (float)((double)this->field_0x60 +
              (double)(float)((double)(float)(dVar16 - (double)this->field_0x60) * dVar17));
  this->mEventFlags = this->mEventFlags | 0x2000;
  __psq_l0(auStack8,uVar10);
  __psq_l1(auStack8,uVar10);
  __psq_l0(auStack24,uVar10);
  __psq_l1(auStack24,uVar10);
  __psq_l0(auStack40,uVar10);
  __psq_l1(auStack40,uVar10);
  __psq_l0(auStack56,uVar10);
  __psq_l1(auStack56,uVar10);
  __psq_l0(auStack72,uVar10);
  __psq_l1(auStack72,uVar10);
  __psq_l0(auStack88,uVar10);
  __psq_l1(auStack88,uVar10);
  __psq_l0(auStack104,uVar10);
  __psq_l1(auStack104,uVar10);
  __psq_l0(auStack120,uVar10);
  __psq_l1(auStack120,uVar10);
  __psq_l0(auStack136,uVar10);
  __psq_l1(auStack136,uVar10);
  return 1;
}


/* __thiscall dCamera_c::getMsgCmdSpeaker(void) */

undefined4 __thiscall dCamera_c::getMsgCmdSpeaker(dCamera_c *this)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((0 < d_com_inf_game::g_dComIfG_gameInfo._23588_4_) &&
     (d_com_inf_game::g_dComIfG_gameInfo._23588_4_ < 0xb)) {
    uVar1 = *(undefined4 *)
             (d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems +
             d_com_inf_game::g_dComIfG_gameInfo._23588_4_ * 4 + 0x51);
  }
  if (d_com_inf_game::g_dComIfG_gameInfo.mMesgCameraTagInfo < 1) {
    return uVar1;
  }
  if (10 < d_com_inf_game::g_dComIfG_gameInfo.mMesgCameraTagInfo) {
    return uVar1;
  }
  return *(undefined4 *)
          (d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems +
          d_com_inf_game::g_dComIfG_gameInfo.mMesgCameraTagInfo * 4 + 0x51);
}


/* __thiscall dCamera_c::getMsgCmdCut(void) */

int __thiscall dCamera_c::getMsgCmdCut(dCamera_c *this)

{
  int iVar1;
  
  iVar1 = 0;
  if (((d_com_inf_game::g_dComIfG_gameInfo._23588_4_ < 1) ||
      (10 < d_com_inf_game::g_dComIfG_gameInfo._23588_4_)) &&
     (0 < d_com_inf_game::g_dComIfG_gameInfo._23588_4_)) {
    iVar1 = d_com_inf_game::g_dComIfG_gameInfo._23588_4_;
  }
  if ((0 < d_com_inf_game::g_dComIfG_gameInfo.mMesgCameraTagInfo) &&
     (d_com_inf_game::g_dComIfG_gameInfo.mMesgCameraTagInfo < 0xb)) {
    return iVar1;
  }
  if (d_com_inf_game::g_dComIfG_gameInfo.mMesgCameraTagInfo < 1) {
    return iVar1;
  }
  return d_com_inf_game::g_dComIfG_gameInfo.mMesgCameraTagInfo;
}


/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* WARNING: Removing unreachable block (ram,0x8017040c) */
/* WARNING: Removing unreachable block (ram,0x801703fc) */
/* WARNING: Removing unreachable block (ram,0x801703ec) */
/* WARNING: Removing unreachable block (ram,0x801703dc) */
/* WARNING: Removing unreachable block (ram,0x801703cc) */
/* WARNING: Removing unreachable block (ram,0x801703d4) */
/* WARNING: Removing unreachable block (ram,0x801703e4) */
/* WARNING: Removing unreachable block (ram,0x801703f4) */
/* WARNING: Removing unreachable block (ram,0x80170404) */
/* WARNING: Removing unreachable block (ram,0x80170414) */
/* __thiscall dCamera_c::talktoCamera(long) */

undefined4 __thiscall dCamera_c::talktoCamera(dCamera_c *this,long param_1)

{
  ushort uVar1;
  float fVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  fopAc_ac_c *pActor;
  float fVar6;
  short sVar7;
  std *this_00;
  char cVar8;
  fopAc_ac_c *pfVar9;
  fopAc_ac_c *in_r7;
  cSGlobe *this_01;
  fopAc_ac_c *pfVar10;
  undefined4 uVar11;
  fopAc_ac_c *pActor_00;
  cSAngle *pcVar12;
  cSAngle *pcVar13;
  undefined4 uVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  double dVar18;
  double dVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  double dVar23;
  double dVar24;
  double extraout_f1;
  undefined8 in_f22;
  undefined8 in_f23;
  undefined8 in_f24;
  undefined8 in_f25;
  undefined8 in_f26;
  undefined8 in_f27;
  undefined8 in_f28;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined6 uVar25;
  undefined auStack4248 [16];
  undefined auStack4232 [16];
  undefined auStack4216 [16];
  undefined auStack4200 [16];
  undefined auStack4184 [16];
  undefined auStack4168 [16];
  undefined auStack4152 [16];
  undefined auStack4136 [16];
  undefined auStack4120 [16];
  undefined auStack4104 [1736];
  cSAngle acStack2360 [2];
  cSAngle acStack2356 [2];
  cSAngle acStack2352 [2];
  cSAngle acStack2348 [2];
  cSAngle acStack2344 [2];
  cSAngle acStack2340 [2];
  cSAngle acStack2336 [2];
  cSAngle acStack2332 [2];
  undefined auStack2328 [8];
  cSAngle acStack2320 [2];
  cSAngle acStack2316 [2];
  undefined auStack2312 [8];
  cSAngle acStack2304 [2];
  cSAngle acStack2300 [2];
  undefined auStack2296 [8];
  cSAngle acStack2288 [2];
  cSAngle acStack2284 [2];
  cSAngle acStack2280 [2];
  cSAngle acStack2276 [2];
  cSAngle acStack2272 [2];
  cSAngle acStack2268 [2];
  cSAngle local_8d8 [2];
  cSAngle acStack2260 [2];
  cSAngle acStack2256 [2];
  cSAngle acStack2252 [2];
  cSAngle acStack2248 [2];
  cSAngle acStack2244 [2];
  cSAngle acStack2240 [2];
  cSAngle acStack2236 [2];
  cSAngle acStack2232 [2];
  cSAngle acStack2228 [2];
  cSAngle acStack2224 [2];
  cSAngle acStack2220 [2];
  cSAngle local_8a8 [2];
  cSAngle acStack2212 [2];
  cSAngle acStack2208 [2];
  cSAngle acStack2204 [2];
  cSAngle acStack2200 [2];
  cSAngle acStack2196 [2];
  cSAngle acStack2192 [2];
  cSAngle acStack2188 [2];
  cSAngle acStack2184 [2];
  cSAngle local_884 [2];
  cSAngle acStack2176 [2];
  cSAngle local_87c [2];
  cSAngle acStack2168 [2];
  cSAngle acStack2164 [2];
  cSAngle acStack2160 [2];
  cSAngle acStack2156 [2];
  cSAngle acStack2152 [2];
  cSAngle acStack2148 [2];
  cSAngle acStack2144 [2];
  cSAngle acStack2140 [2];
  cSAngle acStack2136 [2];
  cSAngle acStack2132 [2];
  cSAngle acStack2128 [2];
  cSAngle acStack2124 [2];
  cSAngle acStack2120 [2];
  cSAngle acStack2116 [2];
  cSAngle acStack2112 [2];
  cSAngle acStack2108 [2];
  cSAngle acStack2104 [2];
  cSAngle acStack2100 [2];
  cSAngle acStack2096 [2];
  cSAngle acStack2092 [2];
  cSAngle acStack2088 [2];
  cSAngle local_824 [2];
  cSAngle local_820 [2];
  cSAngle acStack2076 [2];
  cSAngle local_818 [2];
  cSAngle acStack2068 [2];
  cSAngle acStack2064 [2];
  cSAngle local_80c [2];
  cSAngle local_808 [2];
  cSAngle local_804 [2];
  cSAngle local_800 [2];
  undefined4 local_7fc;
  cSGlobe cStack2040;
  cSGlobe cStack2032;
  cSGlobe cStack2024;
  cSGlobe cStack2016;
  cSGlobe cStack2008;
  cSGlobe cStack2000;
  cSGlobe cStack1992;
  cSGlobe cStack1984;
  cSGlobe cStack1976;
  cSGlobe local_7b0;
  cXyz cStack1960;
  cXyz cStack1948;
  cXyz cStack1936;
  cXyz cStack1924;
  cXyz cStack1912;
  cXyz cStack1900;
  cXyz cStack1888;
  cXyz cStack1876;
  cXyz cStack1864;
  cXyz cStack1852;
  cXyz cStack1840;
  cXyz cStack1828;
  cXyz cStack1816;
  cXyz cStack1804;
  cXyz cStack1792;
  cXyz cStack1780;
  cXyz cStack1768;
  cXyz cStack1756;
  cXyz cStack1744;
  cXyz cStack1732;
  cXyz cStack1720;
  cXyz cStack1708;
  cXyz cStack1696;
  cXyz cStack1684;
  cXyz cStack1672;
  cXyz cStack1660;
  cXyz cStack1648;
  cXyz cStack1636;
  cXyz cStack1624;
  cXyz cStack1612;
  cXyz cStack1600;
  cXyz cStack1588;
  cXyz cStack1576;
  cXyz cStack1564;
  cXyz cStack1552;
  cXyz cStack1540;
  cXyz cStack1528;
  cXyz cStack1516;
  cXyz cStack1504;
  cXyz cStack1492;
  cXyz cStack1480;
  cXyz cStack1468;
  cXyz cStack1456;
  cXyz cStack1444;
  cXyz cStack1432;
  cXyz cStack1420;
  cXyz cStack1408;
  cXyz cStack1396;
  cXyz cStack1384;
  cXyz cStack1372;
  cXyz cStack1360;
  cXyz cStack1348;
  cXyz cStack1336;
  cXyz cStack1324;
  cXyz cStack1312;
  cXyz cStack1300;
  cXyz cStack1288;
  cXyz cStack1276;
  cXyz cStack1264;
  cXyz cStack1252;
  cXyz cStack1240;
  cXyz cStack1228;
  cXyz cStack1216;
  cXyz cStack1204;
  cXyz cStack1192;
  cXyz cStack1180;
  cXyz cStack1168;
  cXyz cStack1156;
  cXyz cStack1144;
  cXyz cStack1132;
  cXyz cStack1120;
  cXyz cStack1108;
  cXyz cStack1096;
  cXyz cStack1084;
  cXyz cStack1072;
  cXyz cStack1060;
  cXyz cStack1048;
  cXyz cStack1036;
  cXyz cStack1024;
  cXyz cStack1012;
  cXyz cStack1000;
  cXyz cStack988;
  cXyz cStack976;
  cXyz cStack964;
  cXyz cStack952;
  cXyz cStack940;
  cXyz cStack928;
  cXyz cStack916;
  cXyz cStack904;
  cXyz cStack892;
  cXyz cStack880;
  cXyz cStack868;
  cXyz cStack856;
  cXyz cStack844;
  cXyz cStack832;
  cXyz cStack820;
  cXyz cStack808;
  cXyz cStack796;
  cXyz cStack784;
  cXyz cStack772;
  cXyz cStack760;
  cXyz cStack748;
  cXyz cStack736;
  cXyz cStack724;
  cXyz cStack712;
  cXyz cStack700;
  cXyz cStack688;
  cXyz cStack676;
  cXyz cStack664;
  cXyz cStack652;
  cXyz cStack640;
  cXyz cStack628;
  cXyz cStack616;
  cXyz cStack604;
  cXyz cStack592;
  cXyz cStack580;
  cXyz cStack568;
  cXyz cStack556;
  cXyz cStack544;
  cXyz cStack532;
  cXyz cStack520;
  cXyz cStack508;
  cXyz cStack496;
  cXyz cStack484;
  cXyz cStack472;
  cXyz cStack460;
  cXyz cStack448;
  cXyz cStack436;
  cXyz cStack424;
  cXyz cStack412;
  cXyz cStack400;
  cXyz local_184;
  cXyz local_178;
  cXyz cStack364;
  cXyz cStack352;
  cXyz cStack340;
  cXyz cStack328;
  cXyz cStack316;
  cXyz cStack304;
  cXyz cStack292;
  cXyz cStack280;
  cXyz cStack268;
  cXyz cStack256;
  cXyz cStack244;
  cXyz cStack232;
  cXyz cStack220;
  fopAc_ac_c *local_d0;
  f_pc_profile__Profile_Actor *pfStack204;
  
  uVar14 = 0;
  __psq_st0(auStack4104,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack4104,(int)in_f31,0);
  __psq_st0(auStack4120,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack4120,(int)in_f30,0);
  __psq_st0(auStack4136,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack4136,(int)in_f29,0);
  __psq_st0(auStack4152,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack4152,(int)in_f28,0);
  __psq_st0(auStack4168,(int)((ulonglong)in_f27 >> 0x20),0);
  __psq_st1(auStack4168,(int)in_f27,0);
  __psq_st0(auStack4184,(int)((ulonglong)in_f26 >> 0x20),0);
  __psq_st1(auStack4184,(int)in_f26,0);
  __psq_st0(auStack4200,(int)((ulonglong)in_f25 >> 0x20),0);
  __psq_st1(auStack4200,(int)in_f25,0);
  __psq_st0(auStack4216,(int)((ulonglong)in_f24 >> 0x20),0);
  __psq_st1(auStack4216,(int)in_f24,0);
  __psq_st0(auStack4232,(int)((ulonglong)in_f23 >> 0x20),0);
  __psq_st1(auStack4232,(int)in_f23,0);
  __psq_st0(auStack4248,(int)((ulonglong)in_f22 >> 0x20),0);
  __psq_st1(auStack4248,(int)in_f22,0);
  dVar15 = (double)dCamParam_c::Val(&this->mCamParam,param_1,1);
  dVar16 = (double)dCamParam_c::Val(&this->mCamParam,param_1,5);
  dVar17 = (double)dCamParam_c::Val(&this->mCamParam,param_1,0);
  dVar18 = (double)dCamParam_c::Val(&this->mCamParam,param_1,10);
  dVar19 = (double)dCamParam_c::Val(&this->mCamParam,param_1,0x13);
  dVar20 = (double)dCamParam_c::Val(&this->mCamParam,param_1,0x12);
  dVar21 = (double)dCamParam_c::Val(&this->mCamParam,param_1,0xf);
  dVar22 = (double)dCamParam_c::Val(&this->mCamParam,param_1,3);
  dVar23 = (double)dCamParam_c::Val(&this->mCamParam,param_1,0x18);
  dVar24 = (double)dCamParam_c::Val(&this->mCamParam,param_1,0x19);
  uVar11 = 1;
  if (this->field_0x11c == 0) {
    *(undefined4 *)&this->field_0x378 = 0x54414c4b;
    *(undefined4 *)&this->field_0x3bc = 0;
    (this->mEvBasePos).y = -NAN;
    *(undefined4 *)&this->field_0x3c0 = 0x14;
    (this->mEvBasePos).z = 0.0;
    *(undefined4 *)&this->field_0x3b8 = 0xffffffff;
    *(float *)&this->field_0x3d8 = d_camera::_11355;
    *(float *)&this->field_0x3dc = (float)dVar21;
    iVar4 = d_camera::dComIfGp_evmng_cameraPlay();
    if (iVar4 == 0) {
      *(undefined2 *)&this->field_0x3ec = 0;
      *(undefined2 *)&this->field_0x3ee = 0;
      *(float *)&this->field_0x3d0 = (float)dVar18;
      *(float *)&this->field_0x3d4 = (float)dVar24;
      *(fopAc_ac_c **)&this->field_0x3e0 = this->mpPlayerActor;
      *(fopAc_ac_c **)&this->field_0x3e4 = this->mpLockonTarget;
    }
    else {
      getEvIntData(this,&local_7fc,"Smoothless",0);
      *(undefined2 *)&this->field_0x3ec = local_7fc._2_2_;
      getEvIntData(this,&local_7fc,"Mode",0);
      *(undefined2 *)&this->field_0x3ee = local_7fc._2_2_;
      getEvFloatData(this,(float *)&this->field_0x3d0,"Radius",(float)dVar18);
      getEvFloatData(this,(float *)&this->field_0x3d8,"Longitude",d_camera::_11355);
      getEvFloatData(this,(float *)&this->field_0x3d4,"Fovy",(float)dVar24);
      getEvFloatData(this,(float *)&this->field_0x3dc,"Latitude",(float)dVar21);
      uVar5 = getEvActor(this,"Listener","@STARTER");
      *(undefined4 *)&this->field_0x3e0 = uVar5;
      uVar5 = getEvActor(this,"Speaker","@TALKPARTNER");
      *(undefined4 *)&this->field_0x3e4 = uVar5;
    }
    *(undefined4 *)&this->field_0x3e8 = *(undefined4 *)&this->field_0x3e4;
  }
  pActor = (fopAc_ac_c *)getMsgCmdSpeaker(this);
  if (pActor == (fopAc_ac_c *)0x0) {
    iVar4 = d_camera::dComIfGp_evmng_cameraPlay();
    if (iVar4 == 0) {
      pActor_00 = this->mpPlayerActor;
      pActor = this->mpLockonTarget;
    }
    else {
      pActor_00 = *(fopAc_ac_c **)&this->field_0x3e0;
      if (this->field_0x11c == 0) {
        pActor = *(fopAc_ac_c **)&this->field_0x3e4;
      }
      else {
        pActor = (fopAc_ac_c *)getEvActor(this,"Speaker","@TALKPARTNER");
      }
    }
  }
  else {
    pActor_00 = *(fopAc_ac_c **)&this->field_0x3e0;
  }
  if (pActor_00 == pActor) {
    pActor = (fopAc_ac_c *)0x0;
  }
  if ((pActor_00 == (fopAc_ac_c *)0x0) || (pActor == (fopAc_ac_c *)0x0)) {
    *(undefined *)&this->field_0x102 = 1;
    *(undefined *)&this->field_0x101 = 1;
    *(undefined *)&this->field_0x100 = 1;
    uVar11 = 0;
    goto LAB_801703cc;
  }
  if (*(fopAc_ac_c **)&this->field_0x3e8 != pActor) {
    this->field_0x11c = 0;
    *(undefined *)&this->field_0x100 = 0;
    *(undefined4 *)&this->field_0x3bc = 0;
    *(fopAc_ac_c **)&this->field_0x3e8 = pActor;
  }
  fVar6 = (float)getMsgCmdCut(this);
  (this->mEvBasePos).z = fVar6;
  if ((this->mEvBasePos).z != *(float *)&this->field_0x3b8) {
    *(undefined4 *)&this->field_0x3bc = 0;
  }
  cSAngle::cSAngle(local_800,(float)dVar19);
  cSAngle::cSAngle(local_804,(float)dVar20);
  cSAngle::cSAngle(local_808,(float)((double)d_camera::180_0 - dVar23));
  cSAngle::cSAngle(local_80c,(float)dVar23);
  if (this->field_0x11c == 0) {
LAB_8016dcb4:
    ::cXyz::cXyz(&cStack220,(float)dVar15,(float)dVar16,(float)dVar17);
    attentionPos(&cStack460,this,pActor_00);
    ::cXyz::cXyz(&cStack232,&cStack460);
    ::cXyz::_cXyz(&cStack460);
    eyePos(&cStack472,this,pActor_00);
    cStack232.y = cStack472.y;
    ::cXyz::_cXyz(&cStack472);
    attentionPos(&cStack484,this,pActor);
    ::cXyz::cXyz(&cStack244,&cStack484);
    ::cXyz::_cXyz(&cStack484);
    eyePos(&cStack496,this,pActor);
    cStack244.y = cStack496.y;
    ::cXyz::_cXyz(&cStack496);
    pfVar9 = (fopAc_ac_c *)&cStack220;
    relationalPos((dCamera_c *)&cStack508,(fopAc_ac_c *)this,pActor_00,(cXyz *)pActor,d_camera::0_25
                 );
    ::cXyz::operator__((cXyz *)&this->field_0x37c,&cStack508);
    ::cXyz::_cXyz(&cStack508);
    if (d_camera::_11355 == *(float *)&this->field_0x3d8) {
      sVar7 = SComponent::cLib_targetAngleY((cXyz *)&this->field_0x37c,&this->field_0x50);
      cSAngle::Val(acStack2064,sVar7);
    }
    else {
      cSAngle::Val(acStack2064,*(float *)&this->field_0x3d8);
    }
    cSGlobe::operator__((cSGlobe *)this->mEvRelUseMask,&this->field_0x3c);
    ::cXyz::operator__(&cStack520,&cStack232,&cStack244);
    cSGlobe::cSGlobe(&local_7b0,&cStack520);
    ::cXyz::_cXyz(&cStack520);
    cSGlobe::operator__((cSGlobe *)&this->field_0x3a8,&local_7b0);
    *(undefined4 *)this->mEvRelUseMask = *(undefined4 *)&this->field_0x3d0;
    if (local_7b0.mDistance < d_camera::_11356) {
      local_7b0.mDistance = d_camera::_11356;
    }
    sVar7 = d_a_himo2::fopAcM_GetName(pActor);
    if (sVar7 == 0xa7) {
      sVar7 = SComponent::cLib_targetAngleY(&(pActor->mCurrent).mPos,&cStack244);
      cSAngle::cSAngle(acStack2068,sVar7);
      directionOf((dCamera_c *)acStack2116,(fopAc_ac_c *)this);
      cSAngle::operator__(acStack2120,acStack2116);
      cSAngle::cSAngle(local_818,acStack2120);
      cSAngle::_cSAngle(acStack2120);
      cSAngle::_cSAngle(acStack2116);
      if (local_818[0] < cSAngle::_0) {
        cSAngle::cSAngle(acStack2124,d_camera::_11357);
        cSAngle::operator__(acStack2076,acStack2124);
        cSAngle::_cSAngle(acStack2124);
      }
      else {
        cSAngle::cSAngle(acStack2128,d_camera::30_0);
        cSAngle::operator__(acStack2076,acStack2128);
        cSAngle::_cSAngle(acStack2128);
      }
      cSAngle::operator__(acStack2132,&local_7b0.mAngleY);
      cSGlobe::U((cSGlobe *)this->mEvRelUseMask,acStack2132);
      cSAngle::_cSAngle(acStack2132);
      cSAngle::cSAngle(acStack2136,(float)dVar21);
      cSGlobe::V((cSGlobe *)this->mEvRelUseMask,acStack2136);
      cSAngle::_cSAngle(acStack2136);
      cSAngle::_cSAngle(acStack2076);
      cSAngle::_cSAngle(local_818);
      cSAngle::_cSAngle(acStack2068);
    }
    else {
      sVar7 = d_a_himo2::fopAcM_GetName(pActor);
      if (sVar7 == 0xb7) {
        directionOf((dCamera_c *)acStack2140,(fopAc_ac_c *)this);
        cSGlobe::U(&local_7b0,acStack2140);
        cSAngle::_cSAngle(acStack2140);
        cSAngle::operator__(acStack2144,acStack2064);
        cSAngle::operator_(acStack2148,d_camera::0_25);
        cSAngle::operator__(acStack2152,&local_7b0.mAngleY);
        cSGlobe::U((cSGlobe *)this->mEvRelUseMask,acStack2152);
        cSAngle::_cSAngle(acStack2152);
        cSAngle::_cSAngle(acStack2148);
        cSAngle::_cSAngle(acStack2144);
        cSAngle::cSAngle(acStack2156,*(float *)&this->field_0x3dc);
        cSGlobe::V((cSGlobe *)this->mEvRelUseMask,acStack2156);
        cSAngle::_cSAngle(acStack2156);
      }
      else {
        sVar7 = d_a_himo2::fopAcM_GetName(pActor);
        if (sVar7 == 0x1b5) {
          *(float *)this->mEvRelUseMask = d_camera::_11358;
          directionOf((dCamera_c *)acStack2160,(fopAc_ac_c *)this);
          cSGlobe::U((cSGlobe *)this->mEvRelUseMask,acStack2160);
          cSAngle::_cSAngle(acStack2160);
          cSAngle::cSAngle(acStack2164,d_camera::_11359);
          cSGlobe::V((cSGlobe *)this->mEvRelUseMask,acStack2164);
          cSAngle::_cSAngle(acStack2164);
        }
        else {
          pcVar13 = &local_7b0.mAngleY;
          cSAngle::operator__(acStack2168,acStack2064);
          cSAngle::cSAngle(local_820,acStack2168);
          cSAngle::_cSAngle(acStack2168);
          if (local_808[0] < local_820[0]) {
            cSAngle::operator__(local_820,local_808);
          }
          if ((cSAngle::_0 < local_820[0]) && (local_820[0] < local_80c[0])) {
            cSAngle::operator__(local_820,local_80c);
          }
          cSAngle::operator__(local_87c);
          uVar1 = local_87c[0] ^ local_820[0];
          cSAngle::_cSAngle(local_87c);
          if (((int)(short)uVar1 >> 1) - (int)(short)(uVar1 & local_87c[0]) < 0) {
            cSAngle::operator__(acStack2176);
            cSAngle::operator__(local_820,acStack2176);
            cSAngle::_cSAngle(acStack2176);
          }
          if (local_820[0] < cSAngle::_0) {
            cSAngle::operator__(local_884);
            cSAngle::_cSAngle(local_884);
            if (((int)(short)(local_820[0] ^ local_884[0]) >> 1) -
                (int)(short)((local_820[0] ^ local_884[0]) & local_820[0]) < 0) {
              cSAngle::operator__(acStack2184);
              cSAngle::operator__(local_820,acStack2184);
              cSAngle::_cSAngle(acStack2184);
            }
          }
          cSAngle::operator__(acStack2188,pcVar13);
          cSGlobe::U((cSGlobe *)this->mEvRelUseMask,acStack2188);
          cSAngle::_cSAngle(acStack2188);
          cSAngle::operator__(acStack2192,pcVar13);
          cSAngle::cSAngle(acStack2196,acStack2192);
          dVar18 = (double)cSAngle::Cos(acStack2196);
          cSAngle::operator_(acStack2200,(float)((double)d_camera::_10148 + dVar18));
          cSAngle::operator_(acStack2204,(float)dVar22);
          cSAngle::cSAngle(acStack2208,(float)dVar21);
          cSAngle::operator__(acStack2212,acStack2204);
          cSAngle::cSAngle(local_824,acStack2212);
          cSAngle::_cSAngle(acStack2212);
          cSAngle::_cSAngle(acStack2208);
          cSAngle::_cSAngle(acStack2204);
          cSAngle::_cSAngle(acStack2200);
          cSAngle::_cSAngle(acStack2196);
          cSAngle::_cSAngle(acStack2192);
          if (local_800[0] < local_824[0]) {
            cSAngle::operator__(local_824,local_800);
          }
          if (local_824[0] < local_804[0]) {
            cSAngle::operator__(local_824,local_804);
          }
          cSGlobe::V((cSGlobe *)this->mEvRelUseMask,local_824);
          pcVar12 = (cSAngle *)((int)&this->mEvTimer + 2);
          cSAngle::operator__(local_8a8,pcVar13);
          uVar1 = local_8a8[0] ^ cSAngle::_0;
          cSAngle::_cSAngle(local_8a8);
          if (((int)(short)uVar1 >> 1) - (int)(short)(uVar1 & local_8a8[0]) < 0) {
            cSAngle::cSAngle(acStack2220,d_camera::_6064);
            cSAngle::operator__(acStack2088,acStack2220);
            cSAngle::_cSAngle(acStack2220);
          }
          else {
            cSAngle::cSAngle(acStack2224,d_camera::_10137);
            cSAngle::operator__(acStack2088,acStack2224);
            cSAngle::_cSAngle(acStack2224);
          }
          iVar4 = 0;
          dVar18 = (double)d_camera::_6064;
          do {
            cSAngle::operator__(acStack2228,pcVar12);
            cSAngle::cSAngle(acStack2092,acStack2228);
            cSAngle::_cSAngle(acStack2228);
            this_00 = (std *)cSAngle::Degree(acStack2092);
            fVar6 = std::fabsf(this_00,(float)extraout_f1);
            if (dVar18 <= (double)fVar6) {
              cSGlobe::Xyz(&cStack532,(cSGlobe *)this->mEvRelUseMask);
              ::cXyz::operator__(&cStack544,(cXyz *)&this->field_0x37c,&cStack532);
              ::cXyz::operator__((cXyz *)&this->field_0x388,&cStack544);
              ::cXyz::_cXyz(&cStack544);
              ::cXyz::_cXyz(&cStack532);
              positionOf(&cStack556,this,this->mpPlayerActor);
              fVar6 = *(float *)&this->field_0x38c;
              fVar2 = *(float *)&this->field_0x368 + cStack556.y;
              ::cXyz::_cXyz(&cStack556);
              if (fVar6 < fVar2) {
                positionOf(&cStack568,this,this->mpPlayerActor);
                *(float *)&this->field_0x38c =
                     d_camera::_6064 + *(float *)&this->field_0x368 + cStack568.y;
                ::cXyz::_cXyz(&cStack568);
                ::cXyz::operator__(&cStack580,(cXyz *)&this->field_0x388,(cXyz *)&this->field_0x37c)
                ;
                cSGlobe::Val((cSGlobe *)this->mEvRelUseMask,&cStack580);
                ::cXyz::_cXyz(&cStack580);
              }
              cVar8 = lineBGCheck(this,&cStack232,(cXyz *)&this->field_0x388,0x8f);
              if (((cVar8 == '\0') &&
                  (cVar8 = lineBGCheck(this,&cStack244,(cXyz *)&this->field_0x388,0x8f),
                  cVar8 == '\0')) &&
                 (cVar8 = lineBGCheck(this,(cXyz *)&this->field_0x37c,(cXyz *)&this->field_0x388,
                                      0x8f), cVar8 == '\0')) {
                ::cXyz::cXyz(&cStack592,&cStack232);
                ::cXyz::cXyz(&cStack604,(cXyz *)&this->field_0x388);
                cVar8 = @unnamed@d_camera_cpp@::lineCollisionCheck
                                  ((_unnamed_d_camera_cpp_ *)&cStack592,&cStack604,(cXyz *)pActor_00
                                   ,pActor,pfVar9);
                ::cXyz::_cXyz(&cStack604);
                ::cXyz::_cXyz(&cStack592);
                if (cVar8 == '\0') {
                  ::cXyz::cXyz(&cStack616,&cStack244);
                  ::cXyz::cXyz(&cStack628,(cXyz *)&this->field_0x388);
                  cVar8 = @unnamed@d_camera_cpp@::lineCollisionCheck
                                    ((_unnamed_d_camera_cpp_ *)&cStack616,&cStack628,
                                     (cXyz *)pActor_00,pActor,pfVar9);
                  ::cXyz::_cXyz(&cStack628);
                  ::cXyz::_cXyz(&cStack616);
                  if (cVar8 == '\0') {
                    cSAngle::_cSAngle(acStack2092);
                    break;
                  }
                }
              }
              cSAngle::operator__(acStack2236,pcVar12);
              cSGlobe::U((cSGlobe *)this->mEvRelUseMask,acStack2236);
              cSAngle::_cSAngle(acStack2236);
              cSAngle::operator__(acStack2240,pcVar13);
              cSAngle::cSAngle(acStack2244,acStack2240);
              dVar19 = (double)cSAngle::Cos(acStack2244);
              cSAngle::operator_(acStack2248,(float)((double)d_camera::_10148 + dVar19));
              cSAngle::operator_(acStack2252,(float)dVar22);
              cSAngle::cSAngle(acStack2256,(float)dVar21);
              cSAngle::operator__(acStack2260,acStack2252);
              cSAngle::operator__(local_824,acStack2260);
              cSAngle::_cSAngle(acStack2260);
              cSAngle::_cSAngle(acStack2256);
              cSAngle::_cSAngle(acStack2252);
              cSAngle::_cSAngle(acStack2248);
              cSAngle::_cSAngle(acStack2244);
              cSAngle::_cSAngle(acStack2240);
              if (local_800[0] < local_824[0]) {
                cSAngle::operator__(local_824,local_800);
              }
              if (local_824[0] < local_804[0]) {
                cSAngle::operator__(local_824,local_804);
              }
              cSGlobe::V((cSGlobe *)this->mEvRelUseMask,local_824);
              cSAngle::_cSAngle(acStack2092);
            }
            else {
              cSAngle::operator__(acStack2232,pcVar12);
              cSGlobe::U((cSGlobe *)this->mEvRelUseMask,acStack2232);
              cSAngle::_cSAngle(acStack2232);
              cSAngle::_cSAngle(acStack2092);
            }
            iVar4 = iVar4 + 1;
          } while (iVar4 < 0x24);
          cSAngle::_cSAngle(acStack2088);
          cSAngle::_cSAngle(local_824);
          cSAngle::_cSAngle(local_820);
        }
      }
    }
    pfStack204 = (f_pc_profile__Profile_Actor *)
                 (*(int *)&this->field_0x3c0 * (*(int *)&this->field_0x3c0 + 1) >> 1 ^ 0x80000000);
    local_d0 = (fopAc_ac_c *)0x43300000;
    *(float *)&this->field_0x3c4 =
         (float)((double)CONCAT44(0x43300000,pfStack204) - d_camera::_5738);
    cSGlobe::Xyz(&cStack640,(cSGlobe *)this->mEvRelUseMask);
    ::cXyz::operator__(&cStack652,(cXyz *)&this->field_0x37c,&cStack640);
    ::cXyz::operator__((cXyz *)&this->field_0x388,&cStack652);
    ::cXyz::_cXyz(&cStack652);
    ::cXyz::_cXyz(&cStack640);
    in_r7 = (fopAc_ac_c *)&this->field_0x388;
    dVar18 = (double)radiusActorInSight(this,pActor_00,pActor,(cXyz *)&this->field_0x37c,
                                        (cXyz *)in_r7,*(float *)&this->field_0x3d4,0);
    if ((double)d_camera::0_0 < dVar18) {
      *(float *)this->mEvRelUseMask = (float)(dVar18 + (double)*(float *)this->mEvRelUseMask);
      cSGlobe::Xyz(&cStack664,(cSGlobe *)this->mEvRelUseMask);
      ::cXyz::operator__(&cStack676,(cXyz *)&this->field_0x37c,&cStack664);
      ::cXyz::operator__((cXyz *)&this->field_0x388,&cStack676);
      ::cXyz::_cXyz(&cStack676);
      ::cXyz::_cXyz(&cStack664);
    }
    if ((this->mEvBasePos).y == -NAN) {
      cSAngle::operator__(local_8d8,&local_7b0.mAngleY);
      uVar1 = local_8d8[0] ^ cSAngle::_0;
      cSAngle::_cSAngle(local_8d8);
      if (((int)(short)uVar1 >> 1) - (int)(short)(uVar1 & local_8d8[0]) < 0) {
        (this->mEvBasePos).y = 0.0;
      }
      else {
        (this->mEvBasePos).y = 1.401298e-45;
      }
    }
    cSGlobe::_cSGlobe(&local_7b0);
    cSAngle::_cSAngle(acStack2064);
    ::cXyz::_cXyz(&cStack244);
    ::cXyz::_cXyz(&cStack232);
    pfVar9 = (fopAc_ac_c *)&DAT_ffffffff;
    ::cXyz::_cXyz(&cStack220);
  }
  else {
    uVar25 = d_a_himo2::fopAcM_GetName(pActor);
    pfVar9 = (fopAc_ac_c *)uVar25;
    if (((short)((uint6)uVar25 >> 0x20) == 0xa7) && ((uint)this->field_0x11c < 2))
    goto LAB_8016dcb4;
  }
  switch((this->mEvBasePos).z) {
  case 0.0:
    sVar7 = d_a_himo2::fopAcM_GetName(pActor);
    if (sVar7 == 0xa7) {
      ::cXyz::cXyz(&cStack256,(float)dVar15,(float)dVar16,(float)dVar17);
      relationalPos((dCamera_c *)&cStack688,(fopAc_ac_c *)this,pActor_00,(cXyz *)pActor,
                    d_camera::0_25);
      ::cXyz::operator__((cXyz *)&this->field_0x37c,&cStack688);
      ::cXyz::_cXyz(&cStack688);
      ::cXyz::_cXyz(&cStack256);
    }
    if (*(char *)&this->field_0x100 == '\0') {
      if (*(short *)&this->field_0x3ec == 0) {
        pfStack204 = (f_pc_profile__Profile_Actor *)
                     (*(int *)&this->field_0x3c0 - *(int *)&this->field_0x3bc ^ 0x80000000);
        local_d0 = (fopAc_ac_c *)0x43300000;
        *(float *)&this->field_0x3c8 =
             (float)((double)CONCAT44(0x43300000,pfStack204) - d_camera::_5738);
        dVar15 = (double)(*(float *)&this->field_0x3c8 / *(float *)&this->field_0x3c4);
        ::cXyz::operator__(&cStack724,(cXyz *)&this->field_0x37c,&this->field_0x44);
        ::cXyz::operator_(&cStack736,&cStack724,(float)dVar15);
        ::cXyz::operator___(&this->field_0x44,(Vec *)&cStack736);
        ::cXyz::_cXyz(&cStack736);
        ::cXyz::_cXyz(&cStack724);
        this_01 = &this->field_0x3c;
        fVar6 = (this->field_0x3c).mDistance;
        (this->field_0x3c).mDistance =
             fVar6 + (float)(dVar15 * (double)(*(float *)this->mEvRelUseMask - fVar6));
        cSAngle::operator__(acStack2268,(cSAngle *)&this->mEvTimer);
        cSAngle::operator_(acStack2272,(float)dVar15);
        cSAngle::operator__(acStack2276,&(this->field_0x3c).mAngleX);
        cSGlobe::V(this_01,acStack2276);
        cSAngle::_cSAngle(acStack2276);
        cSAngle::_cSAngle(acStack2272);
        cSAngle::_cSAngle(acStack2268);
        cSAngle::operator__(acStack2280,(cSAngle *)((int)&this->mEvTimer + 2));
        cSAngle::operator_(acStack2284,(float)dVar15);
        cSAngle::operator__(acStack2288,&(this->field_0x3c).mAngleY);
        cSGlobe::U(this_01,acStack2288);
        cSAngle::_cSAngle(acStack2288);
        cSAngle::_cSAngle(acStack2284);
        cSAngle::_cSAngle(acStack2280);
        cSGlobe::Xyz(&cStack748,this_01);
        ::cXyz::operator__(&cStack760,&this->field_0x44,&cStack748);
        ::cXyz::operator__(&this->field_0x50,&cStack760);
        ::cXyz::_cXyz(&cStack760);
        ::cXyz::_cXyz(&cStack748);
        this->field_0x60 =
             this->field_0x60 +
             (float)(dVar15 * (double)(*(float *)&this->field_0x3d4 - this->field_0x60));
        *(float *)&this->field_0x3c4 = *(float *)&this->field_0x3c4 - *(float *)&this->field_0x3c8;
        if (*(int *)&this->field_0x3c0 + -1 <= *(int *)&this->field_0x3bc) {
          *(undefined *)&this->field_0x102 = 1;
          *(undefined *)&this->field_0x101 = 1;
          *(undefined *)&this->field_0x100 = 1;
        }
        uVar11 = 0;
      }
      else {
        *(undefined *)&this->field_0x102 = 1;
        *(undefined *)&this->field_0x101 = 1;
        *(undefined *)&this->field_0x100 = 1;
      }
    }
    else {
      ::cXyz::operator__(&this->field_0x44,(cXyz *)&this->field_0x37c);
      cSGlobe::operator__(&this->field_0x3c,(cSGlobe *)this->mEvRelUseMask);
      cSGlobe::Xyz(&cStack700,&this->field_0x3c);
      ::cXyz::operator__(&cStack712,&this->field_0x44,&cStack700);
      ::cXyz::operator__(&this->field_0x50,&cStack712);
      ::cXyz::_cXyz(&cStack712);
      ::cXyz::_cXyz(&cStack700);
      this->field_0x60 = *(float *)&this->field_0x3d4;
    }
    break;
  case 1.541428e-44:
  case 1.681558e-44:
  case 4.203895e-44:
  case 4.344025e-44:
    fVar6 = (this->mEvBasePos).z;
    if ((fVar6 == 1.681558e-44) || (fVar6 == 4.344025e-44)) {
      fVar6 = (this->mEvBasePos).y;
      pfVar9 = pActor_00;
      pActor_00 = pActor;
    }
    else {
      uVar3 = countLeadingZeros((this->mEvBasePos).y);
      fVar6 = (float)(uVar3 >> 5);
      pfVar9 = pActor;
    }
    if (*(int *)&this->field_0x3bc == 0) {
      eyePos(&cStack1468,this,pActor_00);
      positionOf(&cStack1480,this,pActor_00);
      dVar15 = (double)(d_camera::_11368 * (cStack1468.y - cStack1480.y));
      ::cXyz::_cXyz(&cStack1480);
      ::cXyz::_cXyz(&cStack1468);
      eyePos(&cStack1492,this,pfVar9);
      eyePos(&cStack1504,this,pActor_00);
      dVar16 = (double)(d_camera::0_25 * (cStack1492.y - cStack1504.y));
      ::cXyz::_cXyz(&cStack1504);
      ::cXyz::_cXyz(&cStack1492);
      dVar15 = (double)(float)((double)(float)((double)d_camera::_6431 * dVar15) + dVar16);
      ::cXyz::cXyz(&local_178,d_camera::_9012,d_camera::0_0,
                   d_camera::0_25 * *(float *)&this->field_0x3a8);
      ::cXyz::cXyz(&local_184,d_camera::_11363,(float)dVar16,d_camera::_11369);
      if (fVar6 != 0.0) {
        local_178.x = -local_178.x;
        local_184.x = -local_184.x;
      }
      attentionPos(&cStack1516,this,pfVar9);
      attentionPos(&cStack1528,this,pActor_00);
      ::cXyz::operator__(&cStack1540,&cStack1516,&cStack1528);
      cSGlobe::cSGlobe(&cStack2024,&cStack1540);
      ::cXyz::_cXyz(&cStack1540);
      ::cXyz::_cXyz(&cStack1528);
      ::cXyz::_cXyz(&cStack1516);
      cSGlobe::cSGlobe(&cStack2032,&local_178);
      cSAngle::operator__(acStack2336,&cStack2032.mAngleY);
      cSGlobe::U(&cStack2032,acStack2336);
      cSAngle::_cSAngle(acStack2336);
      attentionPos(&cStack1552,this,pActor_00);
      cSGlobe::Xyz(&cStack1564,&cStack2032);
      ::cXyz::operator__(&cStack1576,&cStack1552,&cStack1564);
      ::cXyz::operator__(&this->field_0x44,&cStack1576);
      ::cXyz::_cXyz(&cStack1576);
      ::cXyz::_cXyz(&cStack1564);
      ::cXyz::_cXyz(&cStack1552);
      positionOf(&cStack1588,this,pActor_00);
      (this->field_0x44).y = (float)(dVar15 + (double)cStack1588.y);
      ::cXyz::_cXyz(&cStack1588);
      cSGlobe::Val(&cStack2032,&local_184);
      cSAngle::Inv(&cStack2024.mAngleY);
      cSAngle::operator__(acStack2340,(short)&cStack2032.mAngleY);
      cSGlobe::U(&cStack2032,acStack2340);
      cSAngle::_cSAngle(acStack2340);
      attentionPos(&cStack1600,this,pfVar9);
      cSGlobe::Xyz(&cStack1612,&cStack2032);
      ::cXyz::operator__(&cStack1624,&cStack1600,&cStack1612);
      ::cXyz::operator__(&this->field_0x50,&cStack1624);
      ::cXyz::_cXyz(&cStack1624);
      ::cXyz::_cXyz(&cStack1612);
      ::cXyz::_cXyz(&cStack1600);
      ::cXyz::operator__(&cStack1636,&this->field_0x50,&this->field_0x44);
      cSGlobe::Val(&this->field_0x3c,&cStack1636);
      ::cXyz::_cXyz(&cStack1636);
      *(undefined *)&this->field_0x102 = 1;
      *(undefined *)&this->field_0x101 = 1;
      *(undefined *)&this->field_0x100 = 1;
      fVar6 = (this->mEvBasePos).z;
      if ((fVar6 == 1.541428e-44) || (fVar6 == 1.681558e-44)) {
        this->field_0x60 = d_camera::_11370;
      }
      else {
        this->field_0x60 = d_camera::_11371;
      }
      cSGlobe::_cSGlobe(&cStack2032);
      cSGlobe::_cSGlobe(&cStack2024);
      ::cXyz::_cXyz(&local_184);
      ::cXyz::_cXyz(&local_178);
    }
    break;
  case 1.821688e-44:
    if (*(int *)&this->field_0x3bc == 0) {
      *(undefined *)&this->field_0x102 = 1;
      *(undefined *)&this->field_0x101 = 1;
      *(undefined *)&this->field_0x100 = 1;
    }
    ::cXyz::operator__(&this->field_0x44,(cXyz *)&this->field_0x37c);
    cSAngle::cSAngle(acStack2344,d_camera::_6118);
    cSGlobe::Val(&this->field_0x3c,d_camera::_10133,acStack2344,
                 (cSAngle *)((int)&this->mEvTimer + 2));
    cSAngle::_cSAngle(acStack2344);
    if (local_800[0] < (this->field_0x3c).mAngleX.v) {
      cSGlobe::V(&this->field_0x3c,local_800);
    }
    if ((this->field_0x3c).mAngleX.v < local_804[0]) {
      cSGlobe::V(&this->field_0x3c,local_804);
    }
    attentionPos(&cStack1648,this,pActor_00);
    ::cXyz::cXyz(&cStack400,&cStack1648);
    ::cXyz::_cXyz(&cStack1648);
    attentionPos(&cStack1660,this,pActor);
    ::cXyz::cXyz(&cStack412,&cStack1660);
    ::cXyz::_cXyz(&cStack1660);
    if ((this->mEvBasePos).y == 0.0) {
      cSAngle::cSAngle(acStack2352,d_camera::_11364);
      cSAngle::operator__(acStack2108,acStack2352);
      cSAngle::_cSAngle(acStack2352);
    }
    else {
      cSAngle::cSAngle(acStack2348,d_camera::_9008);
      cSAngle::operator__(acStack2108,acStack2348);
      cSAngle::_cSAngle(acStack2348);
    }
    iVar4 = 0;
    do {
      cSGlobe::Xyz(&cStack1672,&this->field_0x3c);
      ::cXyz::operator__(&cStack1684,&this->field_0x44,&cStack1672);
      ::cXyz::operator__(&this->field_0x50,&cStack1684);
      ::cXyz::_cXyz(&cStack1684);
      ::cXyz::_cXyz(&cStack1672);
      cVar8 = lineBGCheck(this,&cStack400,&this->field_0x50,0x8f);
      if ((cVar8 == '\0') &&
         (cVar8 = lineBGCheck(this,&cStack412,&this->field_0x50,0x8f), cVar8 == '\0')) {
        ::cXyz::cXyz(&cStack1696,&cStack400);
        ::cXyz::cXyz(&cStack1708,&this->field_0x50);
        cVar8 = @unnamed@d_camera_cpp@::lineCollisionCheck
                          ((_unnamed_d_camera_cpp_ *)&cStack1696,&cStack1708,(cXyz *)pActor_00,
                           pActor,in_r7);
        ::cXyz::_cXyz(&cStack1708);
        ::cXyz::_cXyz(&cStack1696);
        if (cVar8 == '\0') {
          ::cXyz::cXyz(&cStack1720,&cStack412);
          ::cXyz::cXyz(&cStack1732,&this->field_0x50);
          cVar8 = @unnamed@d_camera_cpp@::lineCollisionCheck
                            ((_unnamed_d_camera_cpp_ *)&cStack1720,&cStack1732,(cXyz *)pActor_00,
                             pActor,in_r7);
          ::cXyz::_cXyz(&cStack1732);
          ::cXyz::_cXyz(&cStack1720);
          if (cVar8 == '\0') break;
        }
      }
      cSAngle::operator__(acStack2356,&(this->field_0x3c).mAngleY);
      cSGlobe::U(&this->field_0x3c,acStack2356);
      cSAngle::_cSAngle(acStack2356);
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0x12);
    this->field_0x60 = d_camera::60_0;
    cSAngle::_cSAngle(acStack2108);
    ::cXyz::_cXyz(&cStack412);
    ::cXyz::_cXyz(&cStack400);
    break;
  case 1.961818e-44:
  case 2.101948e-44:
    pfVar10 = pActor_00;
    if ((this->mEvBasePos).z == 1.961818e-44) {
      pfVar10 = pActor;
      pActor = pActor_00;
    }
    @unnamed@d_camera_cpp@::hideActor((_unnamed_d_camera_cpp_ *)pActor,pfVar9);
    positionOf(&cStack1096,this,pfVar10);
    ::cXyz::operator__(&this->field_0x44,&cStack1096);
    ::cXyz::_cXyz(&cStack1096);
    if (*(int *)&this->field_0x3bc == 0) {
      eyePos(&cStack1108,this,pActor);
      eyePos(&cStack1120,this,pfVar10);
      ::cXyz::operator__(&cStack1132,&cStack1108,&cStack1120);
      cSGlobe::Val(&this->field_0x3c,&cStack1132);
      ::cXyz::_cXyz(&cStack1132);
      ::cXyz::_cXyz(&cStack1120);
      ::cXyz::_cXyz(&cStack1108);
      (this->field_0x3c).mDistance = (this->field_0x3c).mDistance - d_camera::_9194;
      *(undefined *)&this->field_0x102 = 1;
      *(undefined *)&this->field_0x101 = 1;
      *(undefined *)&this->field_0x100 = 1;
    }
    eyePos(&cStack1144,this,pfVar10);
    (this->field_0x44).y = cStack1144.y;
    ::cXyz::_cXyz(&cStack1144);
    cSGlobe::Xyz(&cStack1156,&this->field_0x3c);
    ::cXyz::operator__(&cStack1168,&this->field_0x44,&cStack1156);
    ::cXyz::operator__(&this->field_0x50,&cStack1168);
    ::cXyz::_cXyz(&cStack1168);
    ::cXyz::_cXyz(&cStack1156);
    this->field_0x60 = d_camera::_5573;
    break;
  case 2.242078e-44:
  case 2.382207e-44:
    pfVar10 = pActor_00;
    if ((this->mEvBasePos).z == 2.382207e-44) {
      pfVar10 = pActor;
      pActor = pActor_00;
    }
    @unnamed@d_camera_cpp@::hideActor((_unnamed_d_camera_cpp_ *)pActor,pfVar9);
    positionOf(&cStack880,this,pfVar10);
    ::cXyz::operator__(&this->field_0x44,&cStack880);
    ::cXyz::_cXyz(&cStack880);
    if (*(int *)&this->field_0x3bc == 0) {
      positionOf(&cStack892,this,pActor);
      ::cXyz::cXyz(&cStack292,&cStack892);
      ::cXyz::_cXyz(&cStack892);
      positionOf(&cStack904,this,pfVar10);
      ::cXyz::cXyz(&cStack304,&cStack904);
      ::cXyz::_cXyz(&cStack904);
      ::cXyz::operator__(&cStack916,&cStack292,&cStack304);
      cSGlobe::Val(&this->field_0x3c,&cStack916);
      ::cXyz::_cXyz(&cStack916);
      (this->field_0x3c).mDistance = d_camera::_11361;
      eyePos(&cStack928,this,pfVar10);
      positionOf(&cStack940,this,pfVar10);
      this->mEvBank = (cStack928.y - d_camera::_9194) - cStack940.y;
      ::cXyz::_cXyz(&cStack940);
      ::cXyz::_cXyz(&cStack928);
      *(undefined *)&this->field_0x102 = 1;
      *(undefined *)&this->field_0x101 = 1;
      *(undefined *)&this->field_0x100 = 1;
      ::cXyz::_cXyz(&cStack304);
      ::cXyz::_cXyz(&cStack292);
    }
    positionOf(&cStack952,this,pfVar10);
    (this->field_0x44).y = this->mEvBank + cStack952.y;
    ::cXyz::_cXyz(&cStack952);
    cSGlobe::Xyz(&cStack964,&this->field_0x3c);
    ::cXyz::operator__(&cStack976,&this->field_0x44,&cStack964);
    ::cXyz::operator__(&this->field_0x50,&cStack976);
    ::cXyz::_cXyz(&cStack976);
    ::cXyz::_cXyz(&cStack964);
    this->field_0x60 = d_camera::_5573;
    break;
  case 2.522337e-44:
  case 2.662467e-44:
    if ((this->mEvBasePos).z == 2.522337e-44) {
      fVar6 = (this->mEvBasePos).y;
      pfVar9 = pActor_00;
      pActor_00 = pActor;
    }
    else {
      uVar3 = countLeadingZeros((this->mEvBasePos).y);
      fVar6 = (float)(uVar3 >> 5);
      pfVar9 = pActor;
    }
    if (*(int *)&this->field_0x3bc == 0) {
      *(undefined *)&this->field_0x102 = 1;
      *(undefined *)&this->field_0x101 = 1;
      *(undefined *)&this->field_0x100 = 1;
      ::cXyz::cXyz(&cStack340,d_camera::0_0,d_camera::_10137,d_camera::_9008);
      eyePos(&cStack1180,this,pActor_00);
      attentionPos(&cStack1192,this,pfVar9);
      ::cXyz::operator__(&cStack1204,&cStack1180,&cStack1192);
      cSGlobe::cSGlobe(&cStack1976,&cStack1204);
      ::cXyz::_cXyz(&cStack1204);
      ::cXyz::_cXyz(&cStack1192);
      ::cXyz::_cXyz(&cStack1180);
      cSGlobe::cSGlobe(&cStack1984,&cStack340);
      cSAngle::operator__((cSAngle *)(auStack2296 + 4),&cStack1984.mAngleY);
      cSGlobe::U(&cStack1984,(cSAngle *)(auStack2296 + 4));
      cSAngle::_cSAngle((cSAngle *)(auStack2296 + 4));
      eyePos(&cStack1216,this,pfVar9);
      cSGlobe::Xyz(&cStack1228,&cStack1984);
      ::cXyz::operator__(&cStack1240,&cStack1216,&cStack1228);
      ::cXyz::operator__((cXyz *)&this->mEvFovy,&cStack1240);
      ::cXyz::_cXyz(&cStack1240);
      ::cXyz::_cXyz(&cStack1228);
      ::cXyz::_cXyz(&cStack1216);
      cSGlobe::_cSGlobe(&cStack1984);
      cSGlobe::_cSGlobe(&cStack1976);
      ::cXyz::_cXyz(&cStack340);
    }
    ::cXyz::operator__(&this->field_0x44,(cXyz *)&this->mEvFovy);
    fVar2 = d_camera::_11363;
    if (fVar6 != 0.0) {
      fVar2 = d_camera::_11362;
    }
    cSAngle::cSAngle(acStack2096,fVar2);
    directionOf((dCamera_c *)auStack2296,(fopAc_ac_c *)this);
    cSAngle::operator__(acStack2300,acStack2096);
    cSGlobe::Val(&this->field_0x3c,d_camera::_10810,&cSAngle::_0,acStack2300);
    cSAngle::_cSAngle(acStack2300);
    cSAngle::_cSAngle((cSAngle *)auStack2296);
    cSGlobe::Xyz(&cStack1252,&this->field_0x3c);
    ::cXyz::operator__(&cStack1264,&this->field_0x44,&cStack1252);
    ::cXyz::operator__(&this->field_0x50,&cStack1264);
    ::cXyz::_cXyz(&cStack1264);
    ::cXyz::_cXyz(&cStack1252);
    this->field_0x60 = d_camera::_5573;
    cSAngle::_cSAngle(acStack2096);
    break;
  case 2.802597e-44:
  case 2.942727e-44:
    pfVar10 = pActor_00;
    if ((this->mEvBasePos).z == 2.942727e-44) {
      pfVar10 = pActor;
      pActor = pActor_00;
    }
    @unnamed@d_camera_cpp@::hideActor((_unnamed_d_camera_cpp_ *)pActor,pfVar9);
    positionOf(&cStack772,this,pfVar10);
    ::cXyz::operator__(&this->field_0x44,&cStack772);
    ::cXyz::_cXyz(&cStack772);
    if (*(int *)&this->field_0x3bc == 0) {
      positionOf(&cStack784,this,pActor);
      ::cXyz::cXyz(&cStack268,&cStack784);
      ::cXyz::_cXyz(&cStack784);
      positionOf(&cStack796,this,pfVar10);
      ::cXyz::cXyz(&cStack280,&cStack796);
      ::cXyz::_cXyz(&cStack796);
      ::cXyz::operator__(&cStack808,&cStack268,&cStack280);
      cSGlobe::Val(&this->field_0x3c,&cStack808);
      ::cXyz::_cXyz(&cStack808);
      (this->field_0x3c).mDistance = d_camera::_10810;
      eyePos(&cStack820,this,pfVar10);
      positionOf(&cStack832,this,pfVar10);
      this->mEvBank = (cStack820.y - d_camera::_9012) - cStack832.y;
      ::cXyz::_cXyz(&cStack832);
      ::cXyz::_cXyz(&cStack820);
      *(undefined *)&this->field_0x102 = 1;
      *(undefined *)&this->field_0x101 = 1;
      *(undefined *)&this->field_0x100 = 1;
      ::cXyz::_cXyz(&cStack280);
      ::cXyz::_cXyz(&cStack268);
    }
    positionOf(&cStack844,this,pfVar10);
    (this->field_0x44).y = this->mEvBank + cStack844.y;
    ::cXyz::_cXyz(&cStack844);
    cSGlobe::Xyz(&cStack856,&this->field_0x3c);
    ::cXyz::operator__(&cStack868,&this->field_0x44,&cStack856);
    ::cXyz::operator__(&this->field_0x50,&cStack868);
    ::cXyz::_cXyz(&cStack868);
    ::cXyz::_cXyz(&cStack856);
    this->field_0x60 = d_camera::60_0;
    break;
  case 3.082857e-44:
  case 3.222986e-44:
    pfVar10 = pActor_00;
    if ((this->mEvBasePos).z == 3.222986e-44) {
      pfVar10 = pActor;
      pActor = pActor_00;
    }
    @unnamed@d_camera_cpp@::hideActor((_unnamed_d_camera_cpp_ *)pActor,pfVar9);
    positionOf(&cStack988,this,pfVar10);
    ::cXyz::operator__(&this->field_0x44,&cStack988);
    ::cXyz::_cXyz(&cStack988);
    if (*(int *)&this->field_0x3bc == 0) {
      positionOf(&cStack1000,this,pActor);
      ::cXyz::cXyz(&cStack316,&cStack1000);
      ::cXyz::_cXyz(&cStack1000);
      positionOf(&cStack1012,this,pfVar10);
      ::cXyz::cXyz(&cStack328,&cStack1012);
      ::cXyz::_cXyz(&cStack1012);
      ::cXyz::operator__(&cStack1024,&cStack316,&cStack328);
      cSGlobe::Val(&this->field_0x3c,&cStack1024);
      ::cXyz::_cXyz(&cStack1024);
      (this->field_0x3c).mDistance = d_camera::_10810;
      eyePos(&cStack1036,this,pfVar10);
      positionOf(&cStack1048,this,pfVar10);
      this->mEvBank = (cStack1036.y - d_camera::_10146) - cStack1048.y;
      ::cXyz::_cXyz(&cStack1048);
      ::cXyz::_cXyz(&cStack1036);
      *(undefined *)&this->field_0x102 = 1;
      *(undefined *)&this->field_0x101 = 1;
      *(undefined *)&this->field_0x100 = 1;
      ::cXyz::_cXyz(&cStack328);
      ::cXyz::_cXyz(&cStack316);
    }
    positionOf(&cStack1060,this,pfVar10);
    (this->field_0x44).y = this->mEvBank + cStack1060.y;
    ::cXyz::_cXyz(&cStack1060);
    cSGlobe::Xyz(&cStack1072,&this->field_0x3c);
    ::cXyz::operator__(&cStack1084,&this->field_0x44,&cStack1072);
    ::cXyz::operator__(&this->field_0x50,&cStack1084);
    ::cXyz::_cXyz(&cStack1084);
    ::cXyz::_cXyz(&cStack1072);
    this->field_0x60 = d_camera::_10144;
    break;
  case 3.363116e-44:
  case 3.503246e-44:
    if ((this->mEvBasePos).z == 3.363116e-44) {
      fVar6 = (this->mEvBasePos).y;
      pfVar9 = pActor_00;
      pActor_00 = pActor;
    }
    else {
      uVar3 = countLeadingZeros((this->mEvBasePos).y);
      fVar6 = (float)(uVar3 >> 5);
      pfVar9 = pActor;
    }
    if (*(int *)&this->field_0x3bc == 0) {
      *(undefined *)&this->field_0x102 = 1;
      *(undefined *)&this->field_0x101 = 1;
      *(undefined *)&this->field_0x100 = 1;
      ::cXyz::cXyz(&cStack352,d_camera::0_0,d_camera::_11364,d_camera::_9008);
      eyePos(&cStack1276,this,pActor_00);
      attentionPos(&cStack1288,this,pfVar9);
      ::cXyz::operator__(&cStack1300,&cStack1276,&cStack1288);
      cSGlobe::cSGlobe(&cStack1992,&cStack1300);
      ::cXyz::_cXyz(&cStack1300);
      ::cXyz::_cXyz(&cStack1288);
      ::cXyz::_cXyz(&cStack1276);
      cSGlobe::cSGlobe(&cStack2000,&cStack352);
      cSAngle::operator__(acStack2304,&cStack2000.mAngleY);
      cSGlobe::U(&cStack2000,acStack2304);
      cSAngle::_cSAngle(acStack2304);
      eyePos(&cStack1312,this,pfVar9);
      cSGlobe::Xyz(&cStack1324,&cStack2000);
      ::cXyz::operator__(&cStack1336,&cStack1312,&cStack1324);
      ::cXyz::operator__((cXyz *)&this->mEvFovy,&cStack1336);
      ::cXyz::_cXyz(&cStack1336);
      ::cXyz::_cXyz(&cStack1324);
      ::cXyz::_cXyz(&cStack1312);
      cSGlobe::_cSGlobe(&cStack2000);
      cSGlobe::_cSGlobe(&cStack1992);
      ::cXyz::_cXyz(&cStack352);
    }
    ::cXyz::operator__(&this->field_0x44,(cXyz *)&this->mEvFovy);
    fVar2 = d_camera::_10144;
    if (fVar6 != 0.0) {
      fVar2 = d_camera::_10143;
    }
    cSAngle::cSAngle(acStack2100,fVar2);
    cSAngle::cSAngle((cSAngle *)(auStack2312 + 4),d_camera::_9012);
    directionOf((dCamera_c *)auStack2312,(fopAc_ac_c *)this);
    cSAngle::operator__(acStack2316,acStack2100);
    cSGlobe::Val(&this->field_0x3c,d_camera::_11365,(cSAngle *)(auStack2312 + 4),acStack2316);
    cSAngle::_cSAngle(acStack2316);
    cSAngle::_cSAngle((cSAngle *)auStack2312);
    cSAngle::_cSAngle((cSAngle *)(auStack2312 + 4));
    cSGlobe::Xyz(&cStack1348,&this->field_0x3c);
    ::cXyz::operator__(&cStack1360,&this->field_0x44,&cStack1348);
    ::cXyz::operator__(&this->field_0x50,&cStack1360);
    ::cXyz::_cXyz(&cStack1360);
    ::cXyz::_cXyz(&cStack1348);
    this->field_0x60 = d_camera::_10144;
    cSAngle::_cSAngle(acStack2100);
    break;
  case 3.643376e-44:
  case 3.783506e-44:
    if ((this->mEvBasePos).z == 3.643376e-44) {
      fVar6 = (this->mEvBasePos).y;
      pfVar9 = pActor_00;
      pActor_00 = pActor;
    }
    else {
      uVar3 = countLeadingZeros((this->mEvBasePos).y);
      fVar6 = (float)(uVar3 >> 5);
      pfVar9 = pActor;
    }
    if (*(int *)&this->field_0x3bc == 0) {
      *(undefined *)&this->field_0x102 = 1;
      *(undefined *)&this->field_0x101 = 1;
      *(undefined *)&this->field_0x100 = 1;
      ::cXyz::cXyz(&cStack364,d_camera::0_0,d_camera::_11364,d_camera::_9008);
      attentionPos(&cStack1372,this,pActor_00);
      attentionPos(&cStack1384,this,pfVar9);
      ::cXyz::operator__(&cStack1396,&cStack1372,&cStack1384);
      cSGlobe::cSGlobe(&cStack2008,&cStack1396);
      ::cXyz::_cXyz(&cStack1396);
      ::cXyz::_cXyz(&cStack1384);
      ::cXyz::_cXyz(&cStack1372);
      cSGlobe::cSGlobe(&cStack2016,&cStack364);
      cSAngle::operator__(acStack2320,&cStack2016.mAngleY);
      cSGlobe::U(&cStack2016,acStack2320);
      cSAngle::_cSAngle(acStack2320);
      eyePos(&cStack1408,this,pfVar9);
      cSGlobe::Xyz(&cStack1420,&cStack2016);
      ::cXyz::operator__(&cStack1432,&cStack1408,&cStack1420);
      ::cXyz::operator__((cXyz *)&this->mEvFovy,&cStack1432);
      ::cXyz::_cXyz(&cStack1432);
      ::cXyz::_cXyz(&cStack1420);
      ::cXyz::_cXyz(&cStack1408);
      cSGlobe::_cSGlobe(&cStack2016);
      cSGlobe::_cSGlobe(&cStack2008);
      ::cXyz::_cXyz(&cStack364);
    }
    ::cXyz::operator__(&this->field_0x44,(cXyz *)&this->mEvFovy);
    fVar2 = d_camera::_6118;
    if (fVar6 != 0.0) {
      fVar2 = d_camera::_11357;
    }
    cSAngle::cSAngle(acStack2104,fVar2);
    cSAngle::cSAngle((cSAngle *)(auStack2328 + 4),d_camera::_11366);
    directionOf((dCamera_c *)auStack2328,(fopAc_ac_c *)this);
    cSAngle::operator__(acStack2332,acStack2104);
    cSGlobe::Val(&this->field_0x3c,d_camera::_11367,(cSAngle *)(auStack2328 + 4),acStack2332);
    cSAngle::_cSAngle(acStack2332);
    cSAngle::_cSAngle((cSAngle *)auStack2328);
    cSAngle::_cSAngle((cSAngle *)(auStack2328 + 4));
    cSGlobe::Xyz(&cStack1444,&this->field_0x3c);
    ::cXyz::operator__(&cStack1456,&this->field_0x44,&cStack1444);
    ::cXyz::operator__(&this->field_0x50,&cStack1456);
    ::cXyz::_cXyz(&cStack1456);
    ::cXyz::_cXyz(&cStack1444);
    this->field_0x60 = d_camera::_5573;
    cSAngle::_cSAngle(acStack2104);
    break;
  case 3.923636e-44:
    if (*(int *)&this->field_0x3bc == 0) {
      *(undefined *)&this->field_0x102 = 1;
      *(undefined *)&this->field_0x101 = 1;
      *(undefined *)&this->field_0x100 = 1;
    }
    attentionPos(&cStack1744,this,pActor);
    attentionPos(&cStack1756,this,pActor_00);
    ::cXyz::operator__(&cStack1768,&cStack1744,&cStack1756);
    ::cXyz::cXyz(&cStack424,&cStack1768);
    ::cXyz::_cXyz(&cStack1768);
    ::cXyz::_cXyz(&cStack1756);
    ::cXyz::_cXyz(&cStack1744);
    cSGlobe::cSGlobe(&cStack2040,&cStack424);
    if ((this->mEvBasePos).y == 0.0) {
      cSAngle::operator__(acStack2112,(cSAngle *)&cSAngle::_90);
    }
    else {
      cSAngle::operator__(acStack2112,(cSAngle *)&cSAngle::_270);
    }
    attentionPos(&cStack1780,this,pActor_00);
    ::cXyz::operator_(&cStack1792,&cStack424,d_camera::_6431);
    ::cXyz::operator__(&cStack1804,&cStack1780,&cStack1792);
    ::cXyz::operator__(&this->field_0x44,&cStack1804);
    ::cXyz::_cXyz(&cStack1804);
    ::cXyz::_cXyz(&cStack1792);
    ::cXyz::_cXyz(&cStack1780);
    (this->field_0x44).y = (this->field_0x44).y - d_camera::30_0;
    cSAngle::operator__(acStack2360,&cStack2040.mAngleY);
    cSGlobe::Val(&this->field_0x3c,d_camera::_5129,&cSAngle::_0,acStack2360);
    cSAngle::_cSAngle(acStack2360);
    cSGlobe::Xyz(&cStack1816,&this->field_0x3c);
    ::cXyz::operator__(&cStack1828,&this->field_0x44,&cStack1816);
    ::cXyz::operator__(&this->field_0x50,&cStack1828);
    ::cXyz::_cXyz(&cStack1828);
    ::cXyz::_cXyz(&cStack1816);
    this->field_0x60 = d_camera::60_0;
    dVar15 = (double)radiusActorInSight(this,pActor_00,pActor);
    if ((double)d_camera::0_0 < dVar15) {
      (this->field_0x3c).mDistance = (float)(dVar15 + (double)(this->field_0x3c).mDistance);
      cSGlobe::Xyz(&cStack1840,&this->field_0x3c);
      ::cXyz::operator__(&cStack1852,&this->field_0x44,&cStack1840);
      ::cXyz::operator__(&this->field_0x50,&cStack1852);
      ::cXyz::_cXyz(&cStack1852);
      ::cXyz::_cXyz(&cStack1840);
    }
    cSAngle::_cSAngle(acStack2112);
    cSGlobe::_cSGlobe(&cStack2040);
    ::cXyz::_cXyz(&cStack424);
    break;
  case 4.063766e-44:
    @unnamed@d_camera_cpp@::hideActor((_unnamed_d_camera_cpp_ *)pActor_00,pfVar9);
    positionOf(&cStack1864,this,pActor);
    ::cXyz::operator__(&this->field_0x44,&cStack1864);
    ::cXyz::_cXyz(&cStack1864);
    if (*(int *)&this->field_0x3bc == 0) {
      positionOf(&cStack1876,this,pActor_00);
      ::cXyz::cXyz(&cStack436,&cStack1876);
      ::cXyz::_cXyz(&cStack1876);
      positionOf(&cStack1888,this,pActor);
      ::cXyz::cXyz(&cStack448,&cStack1888);
      ::cXyz::_cXyz(&cStack1888);
      ::cXyz::operator__(&cStack1900,&cStack436,&cStack448);
      cSGlobe::Val(&this->field_0x3c,&cStack1900);
      ::cXyz::_cXyz(&cStack1900);
      (this->field_0x3c).mDistance = d_camera::_5129;
      attentionPos(&cStack1912,this,pActor);
      positionOf(&cStack1924,this,pActor);
      this->mEvBank = (cStack1912.y - d_camera::_11372) - cStack1924.y;
      ::cXyz::_cXyz(&cStack1924);
      ::cXyz::_cXyz(&cStack1912);
      *(undefined *)&this->field_0x102 = 1;
      *(undefined *)&this->field_0x101 = 1;
      *(undefined *)&this->field_0x100 = 1;
      ::cXyz::_cXyz(&cStack448);
      ::cXyz::_cXyz(&cStack436);
    }
    positionOf(&cStack1936,this,pActor);
    (this->field_0x44).y = this->mEvBank + cStack1936.y;
    ::cXyz::_cXyz(&cStack1936);
    cSGlobe::Xyz(&cStack1948,&this->field_0x3c);
    ::cXyz::operator__(&cStack1960,&this->field_0x44,&cStack1948);
    ::cXyz::operator__(&this->field_0x50,&cStack1960);
    ::cXyz::_cXyz(&cStack1960);
    ::cXyz::_cXyz(&cStack1948);
    this->field_0x60 = d_camera::_11370;
  }
  *(float *)&this->field_0x3b8 = (this->mEvBasePos).z;
  *(int *)&this->field_0x3bc = *(int *)&this->field_0x3bc + 1;
  cSAngle::_cSAngle(local_80c);
  cSAngle::_cSAngle(local_808);
  cSAngle::_cSAngle(local_804);
  cSAngle::_cSAngle(local_800);
LAB_801703cc:
  __psq_l0(auStack4104,uVar14);
  __psq_l1(auStack4104,uVar14);
  __psq_l0(auStack4120,uVar14);
  __psq_l1(auStack4120,uVar14);
  __psq_l0(auStack4136,uVar14);
  __psq_l1(auStack4136,uVar14);
  __psq_l0(auStack4152,uVar14);
  __psq_l1(auStack4152,uVar14);
  __psq_l0(auStack4168,uVar14);
  __psq_l1(auStack4168,uVar14);
  __psq_l0(auStack4184,uVar14);
  __psq_l1(auStack4184,uVar14);
  __psq_l0(auStack4200,uVar14);
  __psq_l1(auStack4200,uVar14);
  __psq_l0(auStack4216,uVar14);
  __psq_l1(auStack4216,uVar14);
  __psq_l0(auStack4232,uVar14);
  __psq_l1(auStack4232,uVar14);
  __psq_l0(auStack4248,uVar14);
  __psq_l1(auStack4248,uVar14);
  return uVar11;
}


/* __thiscall @unnamed@d_camera_cpp@::hideActor(fopAc_ac_c *) */

void __thiscall @unnamed@d_camera_cpp@::hideActor(_unnamed_d_camera_cpp_ *this,fopAc_ac_c *param_1)

{
  *(uint *)(this + 0x1c4) = *(uint *)(this + 0x1c4) | 0x1000000;
  return;
}


/* __thiscall @unnamed@d_camera_cpp@::lineCollisionCheck(cXyz,
                                                         cXyz,
                                                         fopAc_ac_c *,
                                                         fopAc_ac_c *) */

void __thiscall
@unnamed@d_camera_cpp@::lineCollisionCheck
          (_unnamed_d_camera_cpp_ *this,cXyz *param_1,cXyz *param_2,fopAc_ac_c *param_3,
          fopAc_ac_c *param_4)

{
  dCcS::ChkCamera(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS,(cXyz *)this,param_1,
                  d_camera::_10146,(fopAc_ac_c *)param_2,param_3);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x801708b8) */
/* WARNING: Removing unreachable block (ram,0x801708a8) */
/* WARNING: Removing unreachable block (ram,0x80170898) */
/* WARNING: Removing unreachable block (ram,0x801708a0) */
/* WARNING: Removing unreachable block (ram,0x801708b0) */
/* WARNING: Removing unreachable block (ram,0x801708c0) */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall dCamera_c::CalcSubjectAngle(short *,
                                          short *) */

bool __thiscall dCamera_c::CalcSubjectAngle(dCamera_c *this,short *param_1,short *param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  bool bVar4;
  fopAc_ac_c *pfVar5;
  undefined4 uVar6;
  undefined8 in_f26;
  double dVar7;
  undefined8 in_f27;
  double dVar8;
  undefined8 in_f28;
  double dVar9;
  undefined8 in_f29;
  double dVar10;
  undefined8 in_f30;
  double dVar11;
  undefined8 in_f31;
  double dVar12;
  short local_a8 [2];
  cSAngle local_a4 [2];
  cSAngle local_a0 [2];
  cSAngle local_9c [2];
  short local_98 [2];
  cSAngle local_94 [2];
  cSAngle local_90 [2];
  cSAngle local_8c [2];
  cSAngle local_88 [8];
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  __psq_st0(auStack72,(int)((ulonglong)in_f27 >> 0x20),0);
  __psq_st1(auStack72,(int)in_f27,0);
  __psq_st0(auStack88,(int)((ulonglong)in_f26 >> 0x20),0);
  __psq_st1(auStack88,(int)in_f26,0);
  if ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr.mCameraPlay == 0) ||
     (d_com_inf_game::g_dComIfG_gameInfo.field_0x5cda == 8)) {
    if (*(int *)&this->field_0x378 == 0x5355424a) {
      if (*(char *)&this->field_0x100 == '\0') {
        bVar4 = false;
      }
      else {
        bVar4 = *(char *)&this->field_0x37c != '\0';
        iVar3 = *(int *)&this->field_0x380;
        dVar12 = (double)dCamParam_c::styles[iVar3].mLockonLatitudeMax;
        dVar11 = (double)dCamParam_c::styles[iVar3].mLockonLongitudeMax;
        dVar10 = (double)*(float *)&dCamParam_c::styles[iVar3].field_0x5c;
        dVar9 = (double)(this->mCamSetup).field_0x30;
        if (!bVar4) {
          cSAngle::cSAngle(local_88,(float)(dVar11 * (double)*(float *)&this->field_0x384));
          cSAngle::cSAngle(local_8c,(float)(dVar12 * (double)*(float *)&this->field_0x388));
          SComponent::operator__(local_98,(int)local_88[0],&this->field_0x3ba);
          *param_2 = local_98[0];
          *param_1 = local_8c[0];
        }
        dVar8 = (double)m_Do_controller_pad::g_mDoCPd_cpadInfo[this->mPadId].mStickMainPosX;
        dVar7 = (double)m_Do_controller_pad::g_mDoCPd_cpadInfo[this->mPadId].mStickMainPosY;
        pfVar5 = this->mpPlayerActor;
        if ((pfVar5->parent).parent.mProcName == 0xa9) {
          cSAngle::cSAngle(local_9c,*(short *)&pfVar5[1].parent.parent.mLyTg.parent.mpTagData);
          ((cSAngle *)&this->field_0x3b8)->v = local_9c[0];
        }
        else {
          cSAngle::cSAngle(local_a0,(pfVar5->mCollisionRot).x);
          ((cSAngle *)&this->field_0x3b8)->v = local_a0[0];
        }
        cSAngle::cSAngle(local_a4,(this->mpPlayerActor->mCollisionRot).y);
        ((cSAngle *)&this->field_0x3ba)->v = local_a4[0];
        fVar2 = d_camera::1_0;
        if ((dVar8 <= (double)d_camera::_10812) &&
           (fVar2 = d_camera::_1_0, (double)d_camera::_11518 <= dVar8)) {
          fVar2 = (float)(dVar8 / (double)d_camera::_10812);
        }
        if (dVar7 <= (double)d_camera::_10812) {
          if ((double)d_camera::_11518 <= dVar7) {
            dVar7 = (double)(float)(dVar7 / (double)d_camera::_10812);
          }
          else {
            dVar7 = (double)d_camera::_1_0;
          }
        }
        else {
          dVar7 = (double)d_camera::1_0;
        }
        fVar1 = (this->mEye).y;
        if ((fVar1 <= *(float *)&this->field_0x354 + d_camera::_9194) ||
           (fVar1 <= *(float *)&this->field_0x310 + d_camera::_9194)) {
          if ((((double)d_camera::0_0 <= (double)*(float *)&this->field_0x388) &&
              ((double)d_camera::0_0 < dVar7)) ||
             (((double)*(float *)&this->field_0x388 < (double)d_camera::0_0 &&
              (dVar7 <= (double)d_camera::0_0)))) {
            dVar7 = (double)d_camera::0_0;
          }
        }
        if (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4] & 0x8000000U) != 0
           ) {
          dVar7 = (double)d_camera::0_0;
        }
        if (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4] & 0x40000U) == 0)
        {
          if ((dCamParam_c::styles[*(int *)&this->field_0x380].mFlag & 0x20) == 0) {
            dVar8 = (double)dCamMath::rationalBezierRatio(fVar2,(this->mCamSetup).field_0x4c);
            dVar7 = (double)dCamMath::rationalBezierRatio((float)dVar7,(this->mCamSetup).field_0x4c)
            ;
            if (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4] & 0x2000U) ==
                0) {
              if ((dCamParam_c::styles[*(int *)&this->field_0x380].mFlag & 0x10) == 0) {
                *(float *)&this->field_0x384 = (float)(-dVar8 * dVar10);
                *(float *)&this->field_0x388 =
                     *(float *)&this->field_0x388 + (float)(dVar7 * dVar10);
              }
              else {
                dVar9 = (double)(float)(dVar10 - (double)(*(float *)&this->field_0x38c *
                                                         (float)(dVar10 * dVar9)));
                *(float *)&this->field_0x384 = (float)(-dVar8 * dVar9);
                *(float *)&this->field_0x388 = *(float *)&this->field_0x388 + (float)(dVar7 * dVar9)
                ;
              }
            }
            else {
              *(float *)&this->field_0x384 = (float)(-dVar8 * dVar10);
              *(float *)&this->field_0x388 = *(float *)&this->field_0x388 + (float)(dVar7 * dVar10);
            }
            if (d_camera::1_0 < *(float *)&this->field_0x384) {
              *(float *)&this->field_0x384 = d_camera::1_0;
            }
            if (*(float *)&this->field_0x384 < d_camera::_1_0) {
              *(float *)&this->field_0x384 = d_camera::_1_0;
            }
            if (d_camera::1_0 < *(float *)&this->field_0x388) {
              *(float *)&this->field_0x388 = d_camera::1_0;
            }
            if (*(float *)&this->field_0x388 < d_camera::_1_0) {
              *(float *)&this->field_0x388 = d_camera::_1_0;
            }
          }
          else {
            *(float *)&this->field_0x384 = -fVar2;
            *(float *)&this->field_0x388 = (float)dVar7;
          }
        }
        else {
          *(float *)&this->field_0x384 = d_camera::0_0;
        }
        cSAngle::cSAngle(local_90,(float)(dVar11 * (double)*(float *)&this->field_0x384));
        cSAngle::cSAngle(local_94,(float)(dVar12 * (double)*(float *)&this->field_0x388));
        SComponent::operator__(local_a8,(int)local_90[0],&this->field_0x3ba);
        *param_2 = local_a8[0];
        *param_1 = local_94[0];
        *(undefined *)&this->field_0x37d = 0;
      }
    }
    else {
      bVar4 = false;
    }
  }
  else {
    bVar4 = false;
  }
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  __psq_l0(auStack24,uVar6);
  __psq_l1(auStack24,uVar6);
  __psq_l0(auStack40,uVar6);
  __psq_l1(auStack40,uVar6);
  __psq_l0(auStack56,uVar6);
  __psq_l1(auStack56,uVar6);
  __psq_l0(auStack72,uVar6);
  __psq_l1(auStack72,uVar6);
  __psq_l0(auStack88,uVar6);
  __psq_l1(auStack88,uVar6);
  return bVar4;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x8017199c) */
/* WARNING: Removing unreachable block (ram,0x8017198c) */
/* WARNING: Removing unreachable block (ram,0x8017197c) */
/* WARNING: Removing unreachable block (ram,0x8017196c) */
/* WARNING: Removing unreachable block (ram,0x80171964) */
/* WARNING: Removing unreachable block (ram,0x80171974) */
/* WARNING: Removing unreachable block (ram,0x80171984) */
/* WARNING: Removing unreachable block (ram,0x80171994) */
/* WARNING: Removing unreachable block (ram,0x801719a4) */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall dCamera_c::subjectCamera(long) */

undefined4 __thiscall dCamera_c::subjectCamera(dCamera_c *this,long param_1)

{
  ushort *puVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  short sVar6;
  uint uVar5;
  dCamMath *this_00;
  fopAc_ac_c *pfVar7;
  cSAngle *pcVar8;
  int iVar9;
  cSAngle *pcVar10;
  undefined4 uVar11;
  double extraout_f1;
  double extraout_f1_00;
  undefined8 in_f23;
  double dVar12;
  undefined8 in_f24;
  double dVar13;
  undefined8 in_f25;
  double dVar14;
  undefined8 in_f26;
  double dVar15;
  undefined8 in_f27;
  double dVar16;
  undefined8 in_f28;
  double dVar17;
  undefined8 in_f29;
  double dVar18;
  undefined8 in_f30;
  double dVar19;
  undefined8 in_f31;
  double dVar20;
  cSAngle local_2f8 [2];
  cSAngle local_2f4 [2];
  cSAngle local_2f0 [2];
  cSAngle local_2ec [2];
  cSAngle local_2e8 [2];
  cSAngle local_2e4 [2];
  cSAngle local_2e0 [2];
  cSAngle local_2dc [2];
  cSAngle local_2d8 [2];
  cSAngle local_2d4 [2];
  cSAngle local_2d0 [2];
  cSAngle acStack716 [2];
  cSAngle acStack712 [2];
  cSAngle local_2c4 [2];
  cSAngle acStack704 [2];
  cSAngle acStack700 [2];
  cSAngle acStack696 [2];
  cSAngle local_2b4 [2];
  cSAngle local_2b0 [2];
  cSAngle acStack684 [2];
  cSAngle acStack680 [2];
  cSAngle local_2a4 [2];
  cSAngle acStack672 [2];
  cSAngle acStack668 [2];
  cSAngle local_298 [2];
  cSAngle local_294 [2];
  cSAngle acStack656 [2];
  cSAngle acStack652 [2];
  cSAngle local_288 [2];
  cSAngle acStack644 [2];
  cSAngle acStack640 [2];
  cSAngle acStack636 [2];
  cSAngle local_278 [2];
  cSAngle acStack628 [2];
  cSAngle acStack624 [2];
  cSAngle acStack620 [2];
  cSAngle local_268 [2];
  cSAngle acStack612 [2];
  cSAngle local_260 [2];
  cSAngle local_25c [2];
  cSAngle local_258 [2];
  cSAngle acStack596 [2];
  cSAngle local_250 [2];
  cSAngle local_24c [2];
  cSAngle acStack584 [2];
  cSAngle acStack580 [2];
  cSAngle local_240 [2];
  cSAngle acStack572 [2];
  cSAngle acStack568 [2];
  cSAngle acStack564 [2];
  cSAngle local_230 [2];
  cSAngle acStack556 [2];
  cSAngle acStack552 [2];
  short local_224;
  short local_222;
  cSAngle local_220 [2];
  cSAngle local_21c [2];
  cSAngle acStack536 [2];
  cSGlobe cStack532;
  cSGlobe cStack524;
  cSGlobe local_204;
  cXyz local_1fc;
  cXyz cStack496;
  cXyz cStack484;
  cXyz cStack472;
  cXyz local_1cc;
  cXyz local_1c0;
  cXyz local_1b4;
  cXyz cStack424;
  cXyz cStack412;
  cXyz local_190;
  int local_184;
  float local_180;
  float local_17c;
  cXyz local_178;
  cXyz cStack364;
  cXyz cStack352;
  cXyz local_154;
  cXyz local_148;
  cXyz local_13c;
  cXyz cStack304;
  cXyz cStack292;
  cXyz cStack280;
  cXyz local_10c;
  cXyz local_100;
  cXyz local_f4;
  int local_e8;
  float local_e4;
  float local_e0;
  cXyz local_dc;
  cXyz local_d0;
  cXyz local_c4;
  float local_b8;
  float fStack180;
  undefined auStack136 [16];
  undefined auStack120 [16];
  undefined auStack104 [16];
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar11 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  __psq_st0(auStack72,(int)((ulonglong)in_f27 >> 0x20),0);
  __psq_st1(auStack72,(int)in_f27,0);
  __psq_st0(auStack88,(int)((ulonglong)in_f26 >> 0x20),0);
  __psq_st1(auStack88,(int)in_f26,0);
  __psq_st0(auStack104,(int)((ulonglong)in_f25 >> 0x20),0);
  __psq_st1(auStack104,(int)in_f25,0);
  __psq_st0(auStack120,(int)((ulonglong)in_f24 >> 0x20),0);
  __psq_st1(auStack120,(int)in_f24,0);
  __psq_st0(auStack136,(int)((ulonglong)in_f23 >> 0x20),0);
  __psq_st1(auStack136,(int)in_f23,0);
  dVar14 = (double)dCamParam_c::styles[param_1].field_0xc;
  dVar13 = (double)dCamParam_c::styles[param_1].mCenterHeightBase;
  dVar12 = (double)dCamParam_c::styles[param_1].field_0x8;
  dVar20 = (double)dCamParam_c::styles[param_1].field_0x30;
  dVar19 = (double)dCamParam_c::styles[param_1].mFovyBase;
  dVar18 = (double)*(float *)&dCamParam_c::styles[param_1].field_0x58;
  dVar17 = (double)dCamParam_c::styles[param_1].mLockonLatitudeMax;
  dVar16 = (double)dCamParam_c::styles[param_1].mLockonLongitudeMax;
  dVar15 = (double)dCamParam_c::styles[param_1].mFovyUpper;
  directionOf((dCamera_c *)acStack552,(fopAc_ac_c *)this);
  sVar6 = cSAngle::Inv(acStack552);
  cSAngle::cSAngle(acStack536,sVar6);
  if (this->field_0x108 == 0) {
    *(undefined4 *)&this->field_0x378 = 0x5355424a;
    *(undefined *)&this->field_0x37c = 0;
    *(undefined *)&this->field_0x37d = 1;
    *(long *)&this->field_0x380 = param_1;
    fVar2 = d_camera::0_0;
    *(float *)&this->field_0x384 = d_camera::0_0;
    *(float *)&this->field_0x388 = fVar2;
    *(float *)&this->field_0x38c = fVar2;
    *(undefined4 *)&this->field_0x3a8 = 100;
    *(undefined4 *)&this->field_0x3c0 = 0;
    *(undefined *)&this->field_0x3bc = 0;
    if (d_com_inf_game::g_dComIfG_gameInfo.field_0x5cda == 3) {
      *(undefined4 *)&this->field_0x3c0 = 2;
    }
    else {
      if ((((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4] & 0x2000U) == 0) &&
         ((dCamParam_c::styles[param_1].mFlag & 0x10) == 0)) {
        *(undefined4 *)&this->field_0x3c0 = 1;
      }
    }
    attentionPos(&cStack280,this,this->mpPlayerActor);
    if (d_camera::_9008 + *(float *)&this->field_0x354 <= cStack280.y) {
      *(undefined *)&this->field_0x3bd = 0;
    }
    else {
      *(undefined *)&this->field_0x3bd = 1;
    }
    if (d_camera::_12159 <= this->mStickCPosYLast) {
      *(undefined4 *)&this->field_0x3c4 = 0;
    }
    else {
      *(undefined4 *)&this->field_0x3c4 = 2;
    }
  }
  if (*(char *)&this->field_0x3bd != '\0') {
    dVar13 = (double)d_camera::60_0;
    dVar12 = (double)d_camera::_12160;
  }
  local_c4.x = (float)dVar14;
  local_c4.y = (float)dVar13;
  local_c4.z = (float)dVar12;
  puVar1 = &dCamParam_c::styles[param_1].mFlag;
  if ((*puVar1 & 0x80) != 0) {
    this->mEventFlags = this->mEventFlags | 0x800;
  }
  if ((*puVar1 & 0x100) != 0) {
    this->mEventFlags = this->mEventFlags | 0x10000000;
  }
  if (*(char *)&this->field_0x100 == '\0') {
    iVar9 = 10;
    if (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4] & 0x2000U) != 0) {
      iVar9 = 7;
    }
    fStack180 = (float)(iVar9 - this->field_0x108 ^ 0x80000000);
    local_b8 = 176.0;
    dVar12 = (double)(d_camera::1_0 /
                     (float)((double)CONCAT44(0x43300000,fStack180) - d_camera::_5738));
    iVar4 = *(int *)&this->field_0x3c0;
    if (iVar4 == 2) {
      local_d0.x = *(float *)&this->field_0xec;
      local_d0.y = *(float *)&this->field_0xf0;
      local_d0.z = *(float *)&this->field_0xf4;
      cSAngle::cSAngle(acStack564,*(short *)&this->field_0xfa);
      sVar6 = cSAngle::Inv(acStack564);
      cSAngle::Val(acStack536,sVar6);
    }
    else {
      if ((iVar4 < 2) && (0 < iVar4)) {
        cSGlobe::cSGlobe(&cStack524,&local_c4);
        directionOf((dCamera_c *)acStack556,(fopAc_ac_c *)this);
        cSAngle::operator__(local_230,acStack556);
        cSAngle::cSAngle(local_2d4,local_230[0]);
        cStack524.mAngleY = local_2d4[0];
        eyePos(&cStack292,this,this->mpPlayerActor);
        cSGlobe::Xyz(&cStack304,&cStack524);
        ::cXyz::operator__(&local_13c,&cStack292,&cStack304);
        local_d0.x = local_13c.x;
        local_d0.y = local_13c.y;
        local_d0.z = local_13c.z;
      }
      else {
        relationalPos(&local_148,this,this->mpPlayerActor,&local_c4);
        local_d0.x = local_148.x;
        local_d0.y = local_148.y;
        local_d0.z = local_148.z;
      }
    }
    ::cXyz::operator__(&local_154,&local_d0,&this->field_0x44);
    local_dc.x = local_154.x;
    local_dc.y = local_154.y;
    local_dc.z = local_154.z;
    ::cXyz::operator_(&cStack352,&local_dc,(float)dVar12);
    mtx::PSVECAdd(&this->field_0x44,&cStack352,&this->field_0x44);
    cSGlobe::Val(&local_204,(float)dVar20,&cSAngle::_0,acStack536);
    fVar2 = (this->field_0x3c).mDistance;
    (this->field_0x3c).mDistance = fVar2 + (float)(dVar12 * (double)(local_204.mDistance - fVar2));
    cSAngle::operator__(acStack568,&local_204.mAngleX);
    cSAngle::operator_(acStack572,(float)dVar12);
    cSAngle::operator__(local_240,&(this->field_0x3c).mAngleX);
    cSAngle::cSAngle(local_2d8,local_240[0]);
    (this->field_0x3c).mAngleX.v = local_2d8[0];
    cSAngle::operator__(acStack580,&local_204.mAngleY);
    cSAngle::operator_(acStack584,(float)dVar12);
    cSAngle::operator__(local_24c,&(this->field_0x3c).mAngleY);
    cSAngle::cSAngle(local_2dc,local_24c[0]);
    (this->field_0x3c).mAngleY.v = local_2dc[0];
    cSGlobe::Xyz(&cStack364,&this->field_0x3c);
    ::cXyz::operator__(&local_178,&this->field_0x44,&cStack364);
    (this->field_0x50).x = local_178.x;
    (this->field_0x50).y = local_178.y;
    (this->field_0x50).z = local_178.z;
    if ((*puVar1 & 0x10) == 0) {
      this->field_0x60 =
           (float)((double)this->field_0x60 +
                  (double)(float)(dVar12 * (double)(float)(dVar19 - (double)this->field_0x60)));
    }
    else {
      uVar5 = this->field_0x108;
      if (uVar5 < iVar9 - 6U) {
        if (uVar5 < iVar9 - 7U) {
          if (uVar5 == 0) {
            *(float *)this->mEvRelUseMask = this->field_0x60;
            this->mpEvRelActor = (fopAc_ac_c *)(d_camera::_12163 * this->field_0x60);
          }
        }
        else {
          if (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4] & 0x200000U) !=
              0) {
            d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].field_0x8 =
                 d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].
                 field_0x8 | 8;
          }
          if (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5ccc)[this->mPadId * 4] & 8U) != 0) {
            d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].field_0x8 =
                 d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].
                 field_0x8 | 0x40;
          }
          d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].field_0xc =
               d_camera::1_0;
        }
      }
      else {
        if (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4] & 0x200000U) != 0)
        {
          d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].field_0x8 =
               d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].field_0x8
               | 8;
        }
        if (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5ccc)[this->mPadId * 4] & 8U) != 0) {
          d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].field_0x8 =
               d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].field_0x8
               | 0x40;
        }
        fVar3 = d_camera::1_0;
        d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].field_0xc =
             d_camera::1_0;
        fVar2 = d_camera::320_0 +
                d_camera::640_0 *
                (d_com_inf_game::g_dComIfG_gameInfo.mPlay._18616_4_ - fVar3) * d_camera::_6431;
        if (((fVar2 < d_camera::640_0) &&
            (fVar3 <= d_com_inf_game::g_dComIfG_gameInfo.mPlay._18616_4_)) &&
           (d_com_inf_game::g_dComIfG_gameInfo.mPlay._18616_4_ <= d_camera::_12161)) {
          dVar12 = (double)((d_camera::640_0 - fVar2) / d_camera::320_0);
          if ((((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5ccc)[this->mPadId * 4] & 8U) != 0) ||
             (d_com_inf_game::g_dComIfG_gameInfo.field_0x5be5 != 0)) {
            setView(this,(float)((double)d_camera::_6117 * dVar12),
                    (float)((double)d_camera::_6118 * dVar12),fVar2,
                    d_camera::480_0 + (float)((double)d_camera::_12162 * dVar12));
          }
          this->field_0x60 =
               *(float *)this->mEvRelUseMask +
               (float)(dVar12 * (double)((float)this->mpEvRelActor - *(float *)this->mEvRelUseMask))
          ;
        }
      }
    }
    if (this->field_0x108 == iVar9 + -1) {
      *(undefined *)&this->field_0x100 = 1;
      *(undefined *)&this->field_0x101 = 1;
      *(undefined *)&this->field_0x102 = 1;
      fVar2 = d_camera::0_0;
      *(float *)&this->field_0x384 = d_camera::0_0;
      *(float *)&this->field_0x388 = fVar2;
      *(float *)&this->field_0x38c = fVar2;
      this->mpEvRelActor = (fopAc_ac_c *)this->field_0x60;
      this->mEvBank = 0.0;
      *(float *)&this->field_0x390 = fVar2;
    }
  }
  else {
    if (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4] & 0x8000000U) != 0) {
      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].field_0x8 =
           d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].field_0x8 |
           0x80;
    }
    if ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5be5 == 0) &&
       (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5ccc)[this->mPadId * 4] & 8U) == 0)) {
      if (*(char *)&this->field_0x3bc != '\0') {
        setView(this,d_camera::0_0,d_camera::0_0,d_camera::640_0,d_camera::480_0);
      }
    }
    else {
      setView(this,d_camera::_6117,d_camera::_6118,d_camera::320_0,d_camera::320_0);
      *(undefined *)&this->field_0x3bc = 1;
    }
    if (*(char *)&this->field_0x37d == '\0') {
      pfVar7 = this->mpPlayerActor;
      if ((pfVar7->parent).parent.mProcName == 0xa9) {
        cSAngle::cSAngle(local_25c,*(short *)&pfVar7[1].parent.parent.mLyTg.parent.mpTagData);
        local_220[0] = local_25c[0];
      }
      else {
        cSAngle::cSAngle(local_260,(pfVar7->mCollisionRot).x);
        local_220[0] = local_260[0];
      }
      cSAngle::cSAngle(acStack612,(this->mpPlayerActor->mCollisionRot).y);
      cSAngle::operator__(local_268,acStack612);
      local_21c[0] = local_268[0];
      dVar12 = (double)cSAngle::Degree(local_220);
      *(float *)&this->field_0x388 = (float)(dVar12 / dVar17);
      dVar12 = (double)cSAngle::Degree(local_21c);
      *(float *)&this->field_0x384 = (float)(dVar12 / dVar16);
    }
    else {
      *(undefined *)&this->field_0x37c = 1;
      CalcSubjectAngle(this,&local_222,&local_224);
      cSAngle::cSAngle(local_250,local_222);
      local_220[0] = local_250[0];
      cSAngle::cSAngle(acStack596,local_224);
      cSAngle::operator__(local_258,acStack596);
      local_21c[0] = local_258[0];
    }
    cSAngle::cSAngle(acStack620,local_220);
    dCamMath::xyzRotateX
              ((dCamMath *)&local_184,&local_c4,(cSAngle)((short)register0x00000004 + -0x26c));
    local_e8 = local_184;
    local_e4 = local_180;
    local_e0 = local_17c;
    cSAngle::cSAngle(acStack624,local_21c);
    dCamMath::xyzRotateY(&local_190,(cSAngle)((short)register0x00000004 + -0xe8));
    local_f4.x = local_190.x;
    local_f4.y = local_190.y;
    local_f4.z = local_190.z;
    iVar9 = *(int *)&this->field_0x3c0;
    if (iVar9 == 2) {
      (this->field_0x44).x = *(float *)&this->field_0xec;
      (this->field_0x44).y = *(float *)&this->field_0xf0;
      (this->field_0x44).z = *(float *)&this->field_0xf4;
      cSAngle::cSAngle(acStack636,*(short *)&this->field_0xfa);
      sVar6 = cSAngle::Inv(acStack636);
      cSAngle::Val(acStack536,sVar6);
    }
    else {
      if ((iVar9 < 2) && (0 < iVar9)) {
        cSGlobe::cSGlobe(&cStack532,&local_f4);
        directionOf((dCamera_c *)acStack628,(fopAc_ac_c *)this);
        cSAngle::operator__(local_278,acStack628);
        cSAngle::cSAngle(local_2e0,local_278[0]);
        cStack532.mAngleY = local_2e0[0];
        eyePos(&cStack412,this,this->mpPlayerActor);
        cSGlobe::Xyz(&cStack424,&cStack532);
        ::cXyz::operator__(&local_1b4,&cStack412,&cStack424);
        (this->field_0x44).x = local_1b4.x;
        (this->field_0x44).y = local_1b4.y;
        (this->field_0x44).z = local_1b4.z;
      }
      else {
        relationalPos(&local_1c0,this,this->mpPlayerActor,&local_f4);
        (this->field_0x44).x = local_1c0.x;
        (this->field_0x44).y = local_1c0.y;
        (this->field_0x44).z = local_1c0.z;
      }
    }
    if ((((this->mEventFlags >> 0x19 & 1) == 0) && (this->field_0x130 == -1)) ||
       (this->mpLockonTarget == (fopAc_ac_c *)0x0)) {
      if ((*(char *)&this->field_0x3bc == '\0') || ((this->mEventFlags & 0x2000000) == 0)) {
        cSAngle::operator__(acStack696,acStack536);
        cSGlobe::Val(&local_204,(float)dVar20,local_220,acStack696);
        fVar2 = (this->field_0x3c).mDistance;
        (this->field_0x3c).mDistance =
             fVar2 + (float)(dVar18 * (double)(local_204.mDistance - fVar2));
        cSAngle::operator__(acStack700,&local_204.mAngleX);
        cSAngle::operator_(acStack704,(float)dVar18);
        cSAngle::operator__(local_2c4,&(this->field_0x3c).mAngleX);
        cSAngle::cSAngle(local_2f4,local_2c4[0]);
        (this->field_0x3c).mAngleX.v = local_2f4[0];
        cSAngle::operator__(acStack712,&local_204.mAngleY);
        cSAngle::operator_(acStack716,(float)dVar18);
        cSAngle::operator__(local_2d0,&(this->field_0x3c).mAngleY);
        cSAngle::cSAngle(local_2f8,local_2d0[0]);
        (this->field_0x3c).mAngleY.v = local_2f8[0];
        if (*(int *)&this->field_0x3a8 < 10) {
          *(int *)&this->field_0x3a8 = *(int *)&this->field_0x3a8 + 1;
        }
        *(undefined *)&this->field_0x37c = 1;
      }
      else {
        local_10c.x = *(float *)&this->field_0xec;
        local_10c.y = *(float *)&this->field_0xf0;
        local_10c.z = *(float *)&this->field_0xf4;
        ::cXyz::operator__(&cStack484,&this->field_0x44,&local_10c);
        cSGlobe::Val(&local_204,&cStack484);
        local_204.mDistance = (float)dVar20;
        dVar12 = (double)(this->field_0x3c).mDistance;
        (this->field_0x3c).mDistance =
             (float)(dVar12 + (double)(d_camera::_5311 * (float)(dVar20 - dVar12)));
        pcVar8 = &(this->field_0x3c).mAngleX;
        cSAngle::operator__(acStack668,&local_204.mAngleX);
        cSAngle::operator_(acStack672,d_camera::_5311);
        cSAngle::operator__(local_2a4,pcVar8);
        cSAngle::cSAngle(local_2ec,local_2a4[0]);
        (this->field_0x3c).mAngleX.v = local_2ec[0];
        pcVar10 = &(this->field_0x3c).mAngleY;
        cSAngle::operator__(acStack680,&local_204.mAngleY);
        cSAngle::operator_(acStack684,d_camera::_5311);
        cSAngle::operator__(local_2b0,pcVar10);
        cSAngle::cSAngle(local_2f0,local_2b0[0]);
        (this->field_0x3c).mAngleY.v = local_2f0[0];
        cSAngle::operator__(local_2b4,pcVar10);
        local_21c[0] = local_2b4[0];
        local_220[0] = pcVar8->v;
        dVar12 = (double)cSAngle::Degree(local_21c);
        *(float *)&this->field_0x384 = (float)(dVar12 / dVar16);
        dVar12 = (double)cSAngle::Degree(local_220);
        *(float *)&this->field_0x388 = (float)(dVar12 / dVar17);
        *(undefined4 *)&this->field_0x3a8 = 0;
        *(undefined *)&this->field_0x37c = 0;
      }
    }
    else {
      attentionPos(&local_1cc,this,this->mpLockonTarget);
      local_100.x = local_1cc.x;
      local_100.z = local_1cc.z;
      local_100.y = local_1cc.y - d_camera::_9012;
      ::cXyz::operator__(&cStack472,&this->field_0x44,&local_100);
      cSGlobe::Val(&local_204,&cStack472);
      local_204.mDistance = (float)dVar20;
      dVar12 = (double)(this->field_0x3c).mDistance;
      (this->field_0x3c).mDistance =
           (float)(dVar12 + (double)(d_camera::_10142 * (float)(dVar20 - dVar12)));
      pcVar8 = &(this->field_0x3c).mAngleX;
      cSAngle::operator__(acStack640,&local_204.mAngleX);
      cSAngle::operator_(acStack644,d_camera::_10142);
      cSAngle::operator__(local_288,pcVar8);
      cSAngle::cSAngle(local_2e4,local_288[0]);
      (this->field_0x3c).mAngleX.v = local_2e4[0];
      pcVar10 = &(this->field_0x3c).mAngleY;
      cSAngle::operator__(acStack652,&local_204.mAngleY);
      cSAngle::operator_(acStack656,d_camera::_10142);
      cSAngle::operator__(local_294,pcVar10);
      cSAngle::cSAngle(local_2e8,local_294[0]);
      (this->field_0x3c).mAngleY.v = local_2e8[0];
      cSAngle::operator__(local_298,pcVar10);
      local_21c[0] = local_298[0];
      local_220[0] = pcVar8->v;
      dVar12 = (double)cSAngle::Degree(local_21c);
      *(float *)&this->field_0x384 = (float)(dVar12 / dVar16);
      dVar12 = (double)cSAngle::Degree(local_220);
      *(float *)&this->field_0x388 = (float)(dVar12 / dVar17);
      *(undefined4 *)&this->field_0x3a8 = 0;
      *(undefined *)&this->field_0x37c = 0;
    }
    cSGlobe::Xyz(&cStack496,&this->field_0x3c);
    ::cXyz::operator__(&local_1fc,&this->field_0x44,&cStack496);
    (this->field_0x50).x = local_1fc.x;
    (this->field_0x50).y = local_1fc.y;
    (this->field_0x50).z = local_1fc.z;
    if ((*puVar1 & 0x10) == 0) {
      this->field_0x60 =
           (float)((double)this->field_0x60 +
                  (double)(float)(dVar18 * (double)(float)(dVar19 - (double)this->field_0x60)));
    }
    else {
      dVar12 = (double)d_camera::0_0;
      dVar13 = (double)this->mStickCPosYLast;
      if (dVar12 < dVar13) {
        dVar13 = dVar12;
        this_00 = (dCamMath *)
                  dCamMath::rationalBezierRatio(this->mStickCPosYLast,(this->mCamSetup).field_0x4c);
        dVar12 = extraout_f1;
      }
      else {
        this_00 = (dCamMath *)
                  dCamMath::rationalBezierRatio((float)-dVar13,(this->mCamSetup).field_0x4c);
        dVar13 = extraout_f1_00;
      }
      fVar2 = *(float *)&this->field_0x38c +
              d_camera::_10148 * (float)(dVar15 * (double)(float)(dVar12 - dVar13));
      if (d_camera::0_0 <= fVar2) {
        if (fVar2 <= d_camera::1_0) {
          *(float *)&this->field_0x38c = fVar2;
        }
        else {
          *(float *)&this->field_0x38c = d_camera::1_0;
        }
      }
      else {
        *(float *)&this->field_0x38c = d_camera::0_0;
      }
      fVar2 = *(float *)&this->field_0x38c;
      if (((d_camera::0_0 == fVar2) || (d_camera::_6431 == fVar2)) || (d_camera::1_0 == fVar2)) {
        dVar12 = (double)d_camera::0_0;
        dVar13 = dVar12;
      }
      fVar2 = d_camera::1_0 + d_camera::_12164 * fVar2;
      dVar15 = (double)fVar2;
      dVar14 = (double)dCamMath::zoomFovy(this_00,d_camera::_6431 * (float)this->mpEvRelActor,fVar2)
      ;
      this->field_0x60 =
           this->field_0x60 +
           (float)(dVar18 * (double)((float)((double)d_camera::_9007 * dVar14) - this->field_0x60));
      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].field_0xc =
           (float)dVar15;
      if (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4] & 0x200000U) != 0) {
        d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].field_0x8 =
             d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].field_0x8 |
             8;
      }
      if (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5ccc)[this->mPadId * 4] & 8U) != 0) {
        d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].field_0x8 =
             d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].field_0x8 |
             0x40;
      }
      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].field_0x10 =
           d_camera::1_0 - d_camera::_12165 * ABS((float)(dVar12 - dVar13));
      mDoGph_gInf_c::mAutoForcus = 0;
    }
    *(undefined *)&this->field_0x37d = 1;
    if (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4] & 0x2000U) != 0) {
      if (*(int *)&this->field_0x3c4 == 2) {
        if (d_camera::_12166 <= this->mStickCPosYLast) {
          *(undefined4 *)&this->field_0x3c4 = 0;
        }
      }
      else {
        if ((*(int *)&this->field_0x3c4 != 1) || (d_camera::_12159 <= this->mStickCPosYLast)) {
          if (d_camera::_12166 <= this->mStickCPosYLast) {
            *(undefined4 *)&this->field_0x3c4 = 0;
          }
          else {
            *(undefined4 *)&this->field_0x3c4 = 1;
          }
        }
        else {
          *(undefined4 *)&this->field_0x3c4 = 2;
          d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].field_0x8 =
               d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].field_0x8
               | 0x2000;
        }
      }
    }
  }
  __psq_l0(auStack8,uVar11);
  __psq_l1(auStack8,uVar11);
  __psq_l0(auStack24,uVar11);
  __psq_l1(auStack24,uVar11);
  __psq_l0(auStack40,uVar11);
  __psq_l1(auStack40,uVar11);
  __psq_l0(auStack56,uVar11);
  __psq_l1(auStack56,uVar11);
  __psq_l0(auStack72,uVar11);
  __psq_l1(auStack72,uVar11);
  __psq_l0(auStack88,uVar11);
  __psq_l1(auStack88,uVar11);
  __psq_l0(auStack104,uVar11);
  __psq_l1(auStack104,uVar11);
  __psq_l0(auStack120,uVar11);
  __psq_l1(auStack120,uVar11);
  __psq_l0(auStack136,uVar11);
  __psq_l1(auStack136,uVar11);
  return 1;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Removing unreachable block (ram,0x80172bf8) */
/* WARNING: Removing unreachable block (ram,0x80172be8) */
/* WARNING: Removing unreachable block (ram,0x80172bd8) */
/* WARNING: Removing unreachable block (ram,0x80172bc8) */
/* WARNING: Removing unreachable block (ram,0x80172bb8) */
/* WARNING: Removing unreachable block (ram,0x80172ba8) */
/* WARNING: Removing unreachable block (ram,0x80172b98) */
/* WARNING: Removing unreachable block (ram,0x80172b88) */
/* WARNING: Removing unreachable block (ram,0x80172b78) */
/* WARNING: Removing unreachable block (ram,0x80172b80) */
/* WARNING: Removing unreachable block (ram,0x80172b90) */
/* WARNING: Removing unreachable block (ram,0x80172ba0) */
/* WARNING: Removing unreachable block (ram,0x80172bb0) */
/* WARNING: Removing unreachable block (ram,0x80172bc0) */
/* WARNING: Removing unreachable block (ram,0x80172bd0) */
/* WARNING: Removing unreachable block (ram,0x80172be0) */
/* WARNING: Removing unreachable block (ram,0x80172bf0) */
/* WARNING: Removing unreachable block (ram,0x80172c00) */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dCamera_c::towerCamera(long) */

undefined4 __thiscall dCamera_c::towerCamera(dCamera_c *this,long param_1)

{
  undefined *puVar1;
  ushort uVar2;
  bool bVar3;
  _unnamed_d_camera_cpp_ *this_00;
  fopAc_ac_c *pfVar4;
  cXyz *this_01;
  cM3dGPla *pcVar5;
  short sVar6;
  char cVar7;
  cSAngle *pcVar8;
  undefined4 uVar9;
  undefined8 in_f14;
  double dVar10;
  undefined8 in_f15;
  double dVar11;
  undefined8 in_f16;
  double dVar12;
  undefined8 in_f17;
  double dVar13;
  undefined8 in_f18;
  double dVar14;
  undefined8 in_f19;
  double dVar15;
  undefined8 in_f20;
  double dVar16;
  undefined8 in_f21;
  double dVar17;
  undefined8 in_f22;
  double dVar18;
  undefined8 in_f23;
  double dVar19;
  double dVar20;
  undefined8 in_f24;
  double dVar21;
  undefined8 in_f25;
  double dVar22;
  undefined8 in_f26;
  double dVar23;
  undefined8 in_f27;
  double dVar24;
  undefined8 in_f28;
  double dVar25;
  undefined8 in_f29;
  double dVar26;
  undefined8 in_f30;
  double dVar27;
  undefined8 in_f31;
  double dVar28;
  float fVar29;
  cSAngle local_498 [2];
  cSAngle local_494 [2];
  cSAngle local_490 [2];
  cSAngle local_48c [2];
  cSAngle local_488 [2];
  cSAngle acStack1156 [2];
  cSAngle acStack1152 [2];
  cSAngle local_47c [2];
  cSAngle acStack1144 [2];
  cSAngle acStack1140 [2];
  cSAngle acStack1136 [2];
  cSAngle acStack1132 [2];
  cSAngle acStack1128 [2];
  cSAngle acStack1124 [2];
  cSAngle acStack1120 [2];
  cSAngle acStack1116 [2];
  cSAngle acStack1112 [2];
  cSAngle acStack1108 [2];
  cSAngle acStack1104 [2];
  cSAngle acStack1100 [2];
  cSAngle acStack1096 [2];
  cSAngle acStack1092 [2];
  cSAngle acStack1088 [2];
  cSAngle acStack1084 [2];
  cSAngle acStack1080 [2];
  cSAngle acStack1076 [2];
  cSAngle acStack1072 [2];
  cSAngle local_42c [2];
  cSAngle local_428 [2];
  cSAngle acStack1060 [2];
  cSAngle acStack1056 [2];
  cSAngle acStack1052 [2];
  cSAngle local_418 [2];
  cSAngle local_414 [2];
  cSAngle acStack1040 [2];
  cSAngle local_40c [2];
  cSAngle local_408 [2];
  cSAngle local_404 [2];
  cSAngle local_400 [2];
  cSAngle acStack1020 [2];
  cSAngle acStack1016 [2];
  cSAngle acStack1012 [2];
  cSAngle local_3f0 [2];
  cSAngle acStack1004 [2];
  cSAngle local_3e8 [2];
  cSAngle local_3e4 [2];
  cSAngle local_3e0 [2];
  cSAngle acStack988 [2];
  cSAngle acStack984 [2];
  float local_3d4;
  float local_3d0;
  float local_3cc;
  cSGlobe local_3c8;
  cSGlobe local_3c0;
  cSGlobe cStack952;
  cSGlobe cStack944;
  cXyz local_3a8;
  cXyz cStack924;
  cXyz cStack912;
  cXyz local_384;
  cXyz cStack888;
  cXyz cStack876;
  cXyz local_360;
  cXyz local_354;
  cXyz cStack840;
  cXyz local_33c;
  cXyz cStack816;
  cXyz cStack804;
  cXyz cStack792;
  cXyz cStack780;
  cXyz local_300;
  cXyz cStack756;
  cXyz cStack744;
  cXyz cStack732;
  cXyz cStack720;
  cXyz local_2c4;
  cXyz local_2b8;
  cXyz local_2ac;
  cXyz local_2a0;
  cXyz local_294;
  cXyz cStack648;
  cXyz local_27c;
  undefined4 local_270;
  undefined4 local_26c;
  undefined4 local_268;
  cXyz local_264;
  cXyz local_258;
  cXyz local_24c;
  cXyz local_240;
  cXyz local_234;
  dBgS_LinChk dStack552;
  dBgS_LinChk dStack444;
  longlong local_150;
  undefined4 local_148;
  uint uStack324;
  undefined auStack280 [16];
  undefined auStack264 [16];
  undefined auStack248 [16];
  undefined auStack232 [16];
  undefined auStack216 [16];
  undefined auStack200 [16];
  undefined auStack184 [16];
  undefined auStack168 [16];
  undefined auStack152 [16];
  undefined auStack136 [16];
  undefined auStack120 [16];
  undefined auStack104 [16];
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar9 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  __psq_st0(auStack72,(int)((ulonglong)in_f27 >> 0x20),0);
  __psq_st1(auStack72,(int)in_f27,0);
  __psq_st0(auStack88,(int)((ulonglong)in_f26 >> 0x20),0);
  __psq_st1(auStack88,(int)in_f26,0);
  __psq_st0(auStack104,(int)((ulonglong)in_f25 >> 0x20),0);
  __psq_st1(auStack104,(int)in_f25,0);
  __psq_st0(auStack120,(int)((ulonglong)in_f24 >> 0x20),0);
  __psq_st1(auStack120,(int)in_f24,0);
  __psq_st0(auStack136,(int)((ulonglong)in_f23 >> 0x20),0);
  __psq_st1(auStack136,(int)in_f23,0);
  __psq_st0(auStack152,(int)((ulonglong)in_f22 >> 0x20),0);
  __psq_st1(auStack152,(int)in_f22,0);
  __psq_st0(auStack168,(int)((ulonglong)in_f21 >> 0x20),0);
  __psq_st1(auStack168,(int)in_f21,0);
  __psq_st0(auStack184,(int)((ulonglong)in_f20 >> 0x20),0);
  __psq_st1(auStack184,(int)in_f20,0);
  __psq_st0(auStack200,(int)((ulonglong)in_f19 >> 0x20),0);
  __psq_st1(auStack200,(int)in_f19,0);
  __psq_st0(auStack216,(int)((ulonglong)in_f18 >> 0x20),0);
  __psq_st1(auStack216,(int)in_f18,0);
  __psq_st0(auStack232,(int)((ulonglong)in_f17 >> 0x20),0);
  __psq_st1(auStack232,(int)in_f17,0);
  __psq_st0(auStack248,(int)((ulonglong)in_f16 >> 0x20),0);
  __psq_st1(auStack248,(int)in_f16,0);
  __psq_st0(auStack264,(int)((ulonglong)in_f15 >> 0x20),0);
  __psq_st1(auStack264,(int)in_f15,0);
  __psq_st0(auStack280,(int)((ulonglong)in_f14 >> 0x20),0);
  __psq_st1(auStack280,(int)in_f14,0);
  dVar18 = (double)d_camera::_10129;
  cSAngle::cSAngle(acStack1040,(this->mCamSetup).field_0xa4);
  cSAngle::cSAngle(acStack984,acStack1040);
  cSAngle::cSAngle(acStack988,d_camera::_10130);
  dVar19 = (double)dCamParam_c::styles[param_1].field_0xc;
  dVar15 = (double)dCamParam_c::styles[param_1].mCenterHeightBase;
  dVar14 = (double)dCamParam_c::styles[param_1].field_0x8;
  dVar13 = (double)dCamParam_c::styles[param_1].field_0x18;
  dVar26 = (double)dCamParam_c::styles[param_1].field_0x14;
  dVar12 = (double)dCamParam_c::styles[param_1].mCenterHeightUpper;
  dVar25 = (double)dCamParam_c::styles[param_1].field_0x30;
  dVar24 = (double)dCamParam_c::styles[param_1].field_0x34;
  dVar23 = (double)dCamParam_c::styles[param_1].field_0x3c;
  dVar22 = (double)dCamParam_c::styles[param_1].field_0x40;
  dVar27 = (double)dCamParam_c::styles[param_1].field_0x44;
  cSAngle::cSAngle(local_3e0,*(float *)&dCamParam_c::styles[param_1].field_0x48);
  cSAngle::cSAngle(local_3e4,*(float *)&dCamParam_c::styles[param_1].field_0x4c);
  dVar10 = (double)dCamParam_c::styles[param_1].mLockonLatitudeMax;
  dVar28 = (double)dCamParam_c::styles[param_1].mFovyBase;
  dVar21 = (double)dCamParam_c::styles[param_1].mFovyLower;
  dVar11 = (double)dCamParam_c::styles[param_1].mLockonFovyMax;
  cSAngle::cSAngle(local_3e8,dCamParam_c::styles[param_1].mLockonLongitudeMin);
  cSAngle::cSAngle(acStack1004,dCamParam_c::styles[param_1].mLockonLongitudeMax);
  dVar16 = (double)*(float *)&dCamParam_c::styles[param_1].field_0x58;
  dVar17 = (double)*(float *)&dCamParam_c::styles[param_1].field_0x5c;
  if (this->mCurArrowIdx == 0xff) {
    followCamera(this,param_1);
  }
  bVar3 = false;
  if ((daNpc_Cb1_c::m_flying != '\0') || (daNpc_Md_c::m_flying != '\0')) {
    bVar3 = true;
  }
  if (bVar3) {
    dVar18 = (double)d_camera::_10131;
    if (d_camera::init_12182 == '\0') {
      d_camera::SA_FLY_12181 = d_camera::_9008;
      d_camera::init_12182 = '\x01';
    }
    if (dVar27 < (double)d_camera::SA_FLY_12181) {
      dVar27 = (double)d_camera::SA_FLY_12181;
    }
    cSAngle::operator__(&this->field_0x148,d_camera::_9005);
  }
  if (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4] & 0x8100000U) != 0) {
    cSAngle::cSAngle(local_414,d_camera::_10136);
    if (((int)(short)(local_414[0] ^ local_3e0[0]) >> 1) -
        (int)(short)((local_414[0] ^ local_3e0[0]) & local_414[0]) < 0) {
      cSAngle::Val(local_3e0,d_camera::_10136);
    }
    if (dVar15 < (double)d_camera::_10137) {
      dVar15 = (double)d_camera::_10137;
    }
  }
  if (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5ccc)[this->mPadId * 4] & 0x40000U) != 0) {
    (this->field_0x148).v = cSAngle::_0;
    dVar27 = (double)d_camera::0_0;
  }
  if (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4] & 0x20U) != 0) {
    dVar19 = -dVar19;
  }
  if (this->field_0x108 == 0) {
    *(float *)&this->field_0x3a8 = d_camera::0_0;
    *(undefined *)&this->field_0x3d5 = 0;
  }
  if (((this->mEventFlags & 0x100000) == 0) ||
     (this_00 = (_unnamed_d_camera_cpp_ *)0xa0000,
     ((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4] & 0xa5000U) == 0)) {
    this_00 = (_unnamed_d_camera_cpp_ *)0x0;
    if ((daNpc_Cb1_c::m_flying != '\0') || (daNpc_Md_c::m_flying != '\0')) {
      this_00 = (_unnamed_d_camera_cpp_ *)&DAT_00000001;
    }
    if (this_00 == (_unnamed_d_camera_cpp_ *)0x0) {
      *(float *)&this->field_0x3a8 =
           (float)((double)*(float *)&this->field_0x3a8 +
                  (double)(d_camera::_10138 * (float)(dVar19 - (double)*(float *)&this->field_0x3a8)
                          ));
      goto LAB_80171d60;
    }
  }
  if (this->mStickMainPosXLast < d_camera::_10141) {
    *(undefined *)&this->field_0x3d5 = 1;
  }
  if (d_camera::_9011 < this->mStickMainPosXLast) {
    *(undefined *)&this->field_0x3d5 = 0;
  }
  fVar29 = d_camera::_10144;
  if (*(char *)&this->field_0x3d5 != '\0') {
    fVar29 = d_camera::_10143;
  }
  *(float *)&this->field_0x3a8 =
       *(float *)&this->field_0x3a8 + d_camera::_10142 * (fVar29 - *(float *)&this->field_0x3a8);
LAB_80171d60:
  dVar20 = (double)(float)(dVar25 - dVar24);
  dVar19 = (double)@unnamed@d_camera_cpp@::limitf
                             (this_00,(float)((double)(float)((double)(this->field_0x3c).mDistance -
                                                             dVar24) / dVar20),d_camera::0_0,
                              d_camera::1_0);
  local_234.x = *(float *)&this->field_0x3a8;
  local_234.z = (float)(dVar14 * dVar19);
  local_234.y = (float)(dVar12 + (double)(float)(dVar19 * (double)(float)(dVar15 - dVar12)));
  if (this->field_0x108 == 0) {
    *(undefined4 *)&this->field_0x378 = 0x544f5752;
    ::cXyz::operator__(&cStack648,&this->field_0x50,&this->field_0x44);
    cSGlobe::Val(&this->field_0x3c,&cStack648);
    *(float *)&this->field_0x390 = d_camera::0_0;
    this->mEvBank = this->field_0x8;
    this->mEvFovy = this->field_0x8;
    *(undefined4 *)&this->field_0x38c = 0;
    *(undefined4 *)&this->field_0x388 = 0;
    dVar15 = (double)cSAngle::Degree((cSAngle *)&this->field_0xc);
    (this->mEvBasePos).z = (float)dVar15;
    this->mpEvRelActor = (fopAc_ac_c *)(float)dVar15;
    *(float *)&this->field_0x3b8 = (this->field_0x44).x;
    *(float *)&this->field_0x3bc = (this->field_0x44).y;
    *(float *)&this->field_0x3c0 = (this->field_0x44).z;
    fVar29 = d_camera::_6065;
    *(float *)&this->field_0x3e0 = d_camera::_6065;
    *(float *)&this->field_0x3dc = fVar29;
    *(float *)&this->field_0x3e4 = fVar29;
    *(float *)&this->field_0x3d8 = d_camera::_8359;
    *(float *)&this->field_0x3e8 = (float)dVar26;
    *(float *)&this->field_0x3ec = (float)dVar13;
    (this->mEvBasePos).x = 0.0;
    *(undefined *)&this->field_0x3d4 = 1;
    this->mEvTimer = (int)this->mFovY;
    (this->mEvBasePos).y = d_camera::0_0;
    *(short *)this->mEvRelUseMask = (this->field_0x3c).mAngleY.v;
    *(float *)&this->field_0x3c4 = (this->mCurRoomArrowEntry).mPos.x;
    *(float *)&this->field_0x3c8 = (this->mCurRoomArrowEntry).mPos.y;
    *(float *)&this->field_0x3cc = (this->mCurRoomArrowEntry).mPos.z;
    *(uint *)&this->field_0x3d0 =
         ((int)__90 >> 0x1f) +
         ((uint)((uint)(int)local_3e8[0] <= (uint)(int)__90) - ((int)local_3e8[0] >> 0x1f));
    if (((this->mEventFlags & 0x8000) == 0) && (this->mCurMode != 1)) {
      relationalPos(&local_294,this,this->mpPlayerActor,&local_234);
      local_240.x = local_294.x;
      local_240.y = local_294.y;
      local_240.z = local_294.z;
      ::cXyz::operator__(&local_2a0,&this->mEye,&local_240);
      local_2ac.x = local_2a0.x;
      local_2ac.y = local_2a0.y;
      local_2ac.z = local_2a0.z;
      fVar29 = mtx::PSVECSquareMag(&local_2ac);
      dVar15 = (double)fVar29;
      if ((double)d_camera::0_0 < dVar15) {
        dVar12 = 1.0 / SQRT(dVar15);
        dVar12 = d_camera::_5735 * dVar12 * (d_camera::_5736 - dVar15 * dVar12 * dVar12);
        dVar12 = d_camera::_5735 * dVar12 * (d_camera::_5736 - dVar15 * dVar12 * dVar12);
        local_3d0 = (float)(dVar15 * d_camera::_5735 * dVar12 *
                                     (d_camera::_5736 - dVar15 * dVar12 * dVar12));
        dVar15 = (double)local_3d0;
      }
      dVar12 = (double)(float)(dVar15 - dVar25);
      ::cXyz::operator__(&local_2b8,&this->mCenter,&local_240);
      local_2c4.x = local_2b8.x;
      local_2c4.y = local_2b8.y;
      local_2c4.z = local_2b8.z;
      fVar29 = mtx::PSVECSquareMag(&local_2c4);
      dVar15 = (double)fVar29;
      if ((double)d_camera::0_0 < dVar15) {
        dVar13 = 1.0 / SQRT(dVar15);
        dVar13 = d_camera::_5735 * dVar13 * (d_camera::_5736 - dVar15 * dVar13 * dVar13);
        dVar13 = d_camera::_5735 * dVar13 * (d_camera::_5736 - dVar15 * dVar13 * dVar13);
        local_3d4 = (float)(dVar15 * d_camera::_5735 * dVar13 *
                                     (d_camera::_5736 - dVar15 * dVar13 * dVar13));
        dVar15 = (double)local_3d4;
      }
      dVar13 = (double)(float)(dVar15 - dVar25);
      if ((double)(float)(dVar15 - dVar25) < dVar12) {
        dVar13 = dVar12;
      }
      pfVar4 = this->mpPlayerActor;
      if ((pfVar4->parent).parent.mProcName == 0xa9) {
        puVar1 = pfVar4[1].parent.parent.mLyTg.parent.parent.mpData;
      }
      else {
        puVar1 = (undefined *)(d_camera::_8357 * ((pfVar4->mEyePos).y - (pfVar4->mCurrent).mPos.y));
      }
      if ((float)puVar1 < d_camera::_6064) {
        puVar1 = (undefined *)d_camera::_6064;
      }
      dVar15 = (double)((float)ABS(dVar13) / (float)puVar1);
      if ((double)d_camera::0_0 < dVar15) {
        dVar12 = 1.0 / SQRT(dVar15);
        dVar12 = d_camera::_5735 * dVar12 * (d_camera::_5736 - dVar15 * dVar12 * dVar12);
        dVar12 = d_camera::_5735 * dVar12 * (d_camera::_5736 - dVar15 * dVar12 * dVar12);
        local_3cc = (float)(dVar15 * d_camera::_5735 * dVar12 *
                                     (d_camera::_5736 - dVar15 * dVar12 * dVar12));
        dVar15 = (double)local_3cc;
      }
      local_150 = (longlong)(int)((double)d_camera::_12164 * dVar15);
      *(int *)&this->field_0x37c = (int)((double)d_camera::_12164 * dVar15) + 1;
      uStack324 = *(int *)&this->field_0x37c * (*(int *)&this->field_0x37c + 1) >> 1 ^ 0x80000000;
      local_148 = 0x43300000;
      *(float *)&this->field_0x380 =
           (float)((double)CONCAT44(0x43300000,uStack324) - d_camera::_5738);
    }
    else {
      *(undefined *)&this->field_0x102 = 1;
      *(undefined *)&this->field_0x101 = 1;
      *(undefined *)&this->field_0x100 = 1;
      *(undefined4 *)&this->field_0x37c = 1;
    }
    *(float *)&this->field_0x384 = d_camera::0_0;
  }
  attentionPos(&cStack720,this,this->mpPlayerActor);
  ::cXyz::operator__(&cStack732,&cStack720,(cXyz *)&this->field_0x3c4);
  cSGlobe::cSGlobe(&cStack944,&cStack732);
  cSGlobe::cSGlobe(&cStack952,&local_234);
  pcVar8 = &cStack944.mAngleY;
  cSAngle::operator__(local_418,&cStack952.mAngleY);
  cSAngle::cSAngle(local_48c,local_418[0]);
  cStack952.mAngleY = local_48c[0];
  attentionPos(&cStack744,this,this->mpPlayerActor);
  cSGlobe::Xyz(&cStack756,&cStack952);
  ::cXyz::operator__(&local_300,&cStack744,&cStack756);
  local_24c.x = local_300.x;
  local_24c.y = local_300.y;
  local_24c.z = local_300.z;
  dVar15 = (double)getWaterSurfaceHeight(this,&local_24c);
  local_24c.y = (float)dVar15;
  if (*(char *)&this->field_0x100 == '\0') {
    if (this->field_0x31d != 0) {
      dBgS::MoveBgMatrixCrrPos
                (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,&(this->mBG).field_0x74,true,
                 (cXyz *)&this->field_0x3b8,(csXyz *)0x0,(csXyz *)0x0);
    }
    uStack324 = *(int *)&this->field_0x37c - this->field_0x108 ^ 0x80000000;
    local_148 = 0x43300000;
    *(float *)&this->field_0x384 = (float)((double)CONCAT44(0x43300000,uStack324) - d_camera::_5738)
    ;
    dVar15 = (double)(*(float *)&this->field_0x384 / *(float *)&this->field_0x380);
    ::cXyz::operator__(&cStack780,&local_24c,(cXyz *)&this->field_0x3b8);
    ::cXyz::operator_(&cStack792,&cStack780,(float)dVar15);
    mtx::PSVECAdd((cXyz *)&this->field_0x3b8,&cStack792,(cXyz *)&this->field_0x3b8);
    ::cXyz::operator__(&cStack804,(cXyz *)&this->field_0x3b8,&this->field_0x44);
    ::cXyz::operator_(&cStack816,&cStack804,(float)dVar26);
    mtx::PSVECAdd(&this->field_0x44,&cStack816,&this->field_0x44);
    attentionPos(&local_33c,this,this->mpPlayerActor);
    local_258.x = local_33c.x;
    local_258.z = local_33c.z;
    local_258.y = local_33c.y - d_camera::_10146;
    dBgS_CamLinChk_NorWtr::dBgS_CamLinChk_NorWtr((dBgS_CamLinChk_NorWtr *)&dStack444);
    this_01 = (cXyz *)lineBGCheck(this,&local_258,&this->field_0x44,&dStack444,0x7f);
    if (((uint)this_01 & 0xff) != 0) {
      pcVar5 = cBgS::GetTriPla((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                               (uint)(ushort)dStack444.parent.mPolyInfo.mBgIndex,
                               (uint)(ushort)dStack444.parent.mPolyInfo.mTriIdx);
      (this->field_0x44).x = dStack444.parent.mLin.mP1.x;
      (this->field_0x44).y = dStack444.parent.mLin.mP1.y;
      (this->field_0x44).z = dStack444.parent.mLin.mP1.z;
      this_01 = &this->field_0x44;
      mtx::PSVECAdd(this_01,(cXyz *)pcVar5,this_01);
    }
    dVar27 = (double)@unnamed@d_camera_cpp@::limitf
                               ((_unnamed_d_camera_cpp_ *)this_01,(this->field_0x3c).mDistance,
                                (float)dVar24,(float)dVar25);
    pcVar8 = &(this->field_0x3c).mAngleX;
    local_3f0[0] = (this->field_0x3c).mAngleX.v;
    if (local_3f0[0] < local_3e0[0]) {
      local_3f0[0] = local_3e0[0];
    }
    if (local_3e4[0] < local_3f0[0]) {
      local_3f0[0] = local_3e4[0];
    }
    sVar6 = cSAngle::Inv(&this->mAngleY);
    cSAngle::cSAngle(acStack1052,sVar6);
    cSGlobe::cSGlobe(&local_3c0,(float)dVar27,local_3f0,acStack1052);
    fVar29 = (this->field_0x3c).mDistance;
    (this->field_0x3c).mDistance = fVar29 + (float)(dVar15 * (double)(local_3c0.mDistance - fVar29))
    ;
    cSAngle::operator__(acStack1056,&local_3c0.mAngleX);
    cSAngle::operator_(acStack1060,(float)dVar15);
    cSAngle::operator__(local_428,pcVar8);
    cSAngle::cSAngle(local_490,local_428[0]);
    (this->field_0x3c).mAngleX.v = local_490[0];
    cSGlobe::Xyz(&cStack840,&this->field_0x3c);
    ::cXyz::operator__(&local_354,&this->field_0x44,&cStack840);
    (this->field_0x50).x = local_354.x;
    (this->field_0x50).y = local_354.y;
    (this->field_0x50).z = local_354.z;
    if (*(int *)&this->field_0x37c - 1U <= (uint)this->field_0x108) {
      *(undefined *)&this->field_0x102 = 1;
      *(undefined *)&this->field_0x101 = 1;
      *(undefined *)&this->field_0x100 = 1;
    }
    dVar27 = (double)cSAngle::Degree(pcVar8);
    this->mpEvRelActor = (fopAc_ac_c *)(float)dVar27;
    fVar29 = (this->field_0x3c).mDistance;
    this->mEvBank = fVar29;
    this->mEvFovy = fVar29;
    this->field_0x60 =
         (float)((double)this->field_0x60 +
                (double)(float)(dVar15 * (double)(float)(dVar28 - (double)this->field_0x60)));
    *(float *)&this->field_0x380 = *(float *)&this->field_0x380 - *(float *)&this->field_0x384;
    dBgS_CamLinChk_NorWtr::_dBgS_CamLinChk_NorWtr((dBgS_CamLinChk_NorWtr *)&dStack444);
  }
  else {
    positionOf(&local_360,this,this->mpPlayerActor);
    local_264.x = local_360.x;
    local_264.z = local_360.z;
    local_264.y = local_360.y + d_camera::_6064;
    groundHeight(this,&local_264);
    if ((*(char *)&this->field_0x360 == '\0') &&
       (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4] & 0x100000U) == 0)) {
      if (*(int *)&this->field_0x388 < 0x50) {
        *(int *)&this->field_0x388 = *(int *)&this->field_0x388 + 1;
        uStack324 = *(uint *)&this->field_0x388 ^ 0x80000000;
        local_148 = 0x43300000;
        dVar15 = (double)dCamMath::rationalBezierRatio
                                   ((float)((double)CONCAT44(0x43300000,uStack324) - d_camera::_5738
                                           ) / d_camera::_10130,d_camera::_10147);
        *(float *)&this->field_0x390 =
             (float)((double)*(float *)&this->field_0x390 +
                    (double)(float)((double)(float)(dVar18 - (double)*(float *)&this->field_0x390) *
                                   dVar15));
      }
    }
    else {
      *(float *)&this->field_0x390 = d_camera::0_0;
      *(undefined4 *)&this->field_0x388 = 0;
    }
    cSAngle::operator__(local_42c,pcVar8);
    uVar2 = local_42c[0] ^ cSAngle::_0;
    directionOf((dCamera_c *)acStack1072,(fopAc_ac_c *)this);
    cSAngle::cSAngle(acStack1012,acStack1072);
    cSAngle::operator__(acStack1076,acStack1012);
    cSAngle::cSAngle(acStack1016,acStack1076);
    local_270 = *(undefined4 *)&this->field_0x3e8;
    local_26c = *(undefined4 *)&this->field_0x3ec;
    local_268 = local_270;
    ::cXyz::operator__(&cStack876,&local_24c,&this->field_0x44);
    ::cXyz::operator_(&cStack888,(Vec *)&cStack876);
    mtx::PSVECAdd(&this->field_0x44,&cStack888,&this->field_0x44);
    attentionPos(&local_384,this,this->mpPlayerActor);
    local_27c.x = local_384.x;
    local_27c.z = local_384.z;
    local_27c.y = local_384.y - d_camera::_10146;
    dBgS_CamLinChk_NorWtr::dBgS_CamLinChk_NorWtr((dBgS_CamLinChk_NorWtr *)&dStack552);
    cVar7 = lineBGCheck(this,&local_27c,&this->field_0x44,&dStack552,0x7f);
    if (cVar7 != '\0') {
      pcVar5 = cBgS::GetTriPla((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                               (uint)(ushort)dStack552.parent.mPolyInfo.mBgIndex,
                               (uint)(ushort)dStack552.parent.mPolyInfo.mTriIdx);
      (this->field_0x44).x = dStack552.parent.mLin.mP1.x;
      (this->field_0x44).y = dStack552.parent.mLin.mP1.y;
      (this->field_0x44).z = dStack552.parent.mLin.mP1.z;
      mtx::PSVECAdd(&this->field_0x44,(cXyz *)pcVar5,&this->field_0x44);
    }
    ::cXyz::operator__(&cStack912,&this->field_0x50,&this->field_0x44);
    cSGlobe::cSGlobe(&local_3c8,&cStack912);
    dVar15 = (double)(float)((double)(float)((double)(this->field_0x3c).mDistance - dVar24) / dVar20
                            );
    if (dVar15 < (double)d_camera::0_0) {
      dVar15 = (double)d_camera::0_0;
    }
    if ((double)d_camera::1_0 < dVar15) {
      dVar15 = (double)d_camera::1_0;
    }
    cSAngle::operator__(acStack1080,local_3e8);
    cSAngle::operator_(acStack1084,this->mStickMainValueLast);
    cSAngle::operator__(acStack1088,local_3e8);
    cSAngle::cSAngle(local_400,acStack1088);
    if (((int)(short)uVar2 >> 1) - (int)(short)(uVar2 & local_42c[0]) < 0) {
      cSAngle::operator__(acStack1112,pcVar8);
      cSAngle::cSAngle(local_408,acStack1112);
      dVar15 = (double)dCamMath::rationalBezierRatio((float)dVar15,(float)dVar21);
      if (local_400[0] < local_408[0]) {
        dVar15 = (double)d_camera::1_0;
      }
      cSAngle::operator__(acStack1116,pcVar8);
      cSAngle::operator__(acStack1120,acStack1116);
      cSAngle::operator_(acStack1124,(float)dVar15);
      cSAngle::operator__(acStack1128,&local_3c8.mAngleY);
      cSAngle::Val(acStack1020,acStack1128);
    }
    else {
      cSAngle::operator__(acStack1092,&local_3c8.mAngleY);
      cSAngle::cSAngle(local_404,acStack1092);
      dVar15 = (double)dCamMath::rationalBezierRatio((float)dVar15,(float)dVar21);
      if (local_400[0] < local_404[0]) {
        dVar15 = (double)d_camera::1_0;
      }
      cSAngle::operator__(acStack1096,pcVar8);
      cSAngle::operator__(acStack1100,acStack1096);
      cSAngle::operator_(acStack1104,(float)dVar15);
      cSAngle::operator__(acStack1108,&local_3c8.mAngleY);
      cSAngle::Val(acStack1020,acStack1108);
    }
    cSAngle::operator__(acStack1132,acStack1020);
    cSAngle::operator_(acStack1136,d_camera::_9005);
    cSAngle::operator___((cSAngle *)this->mEvRelUseMask,acStack1136);
    if ((((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4] & 0x2000161U) != 0)
       || (fVar29 = this->mStickMainValueLast,
          ((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5ccc)[this->mPadId * 4] & 0x10000U) != 0)) {
      fVar29 = d_camera::0_0;
    }
    *(float *)&this->field_0x3e0 = (float)(dVar17 + (double)(float)(dVar16 * (double)fVar29));
    cSAngle::operator__(acStack1140,(cSAngle *)this->mEvRelUseMask);
    cSAngle::operator_(acStack1144,*(float *)&this->field_0x3e0);
    cSAngle::operator__(local_47c,&(this->field_0x3c).mAngleY);
    cSAngle::cSAngle(local_494,local_47c[0]);
    (this->field_0x3c).mAngleY.v = local_494[0];
    this->mpEvRelActor =
         (fopAc_ac_c *)
         (float)((double)(float)this->mpEvRelActor +
                (double)(float)(dVar22 * (double)(float)(dVar27 - (double)(float)this->mpEvRelActor)
                               ));
    if ((dCamParam_c::styles[param_1].mFlag & 4) == 0) {
      (this->field_0x148).v = cSAngle::_0;
    }
    if (*(int *)&this->field_0x388 == 0) {
      dVar15 = (double)cSAngle::Degree(&this->field_0x148);
      cSAngle::Val(local_40c,(float)((double)(float)this->mpEvRelActor + dVar15));
      *(float *)&this->field_0x3dc =
           (float)((double)*(float *)&this->field_0x3dc +
                  (double)(d_camera::_6065 * (float)(dVar10 - (double)*(float *)&this->field_0x3dc))
                  );
    }
    else {
      local_40c[0] = local_3c8.mAngleX;
      dVar15 = (double)cSAngle::Degree(local_40c);
      this->mpEvRelActor = (fopAc_ac_c *)(float)dVar15;
      dVar15 = (double)dCamMath::rationalBezierRatio(*(float *)&this->field_0x390,d_camera::_10812);
      *(float *)&this->field_0x3dc = (float)dVar15;
    }
    if (local_40c[0] < local_3e0[0]) {
      cSAngle::Val(local_40c,local_3e0);
    }
    else {
      if (local_3e4[0] < local_40c[0]) {
        cSAngle::Val(local_40c,local_3e4);
      }
    }
    cSAngle::operator__(acStack1152,local_40c);
    cSAngle::operator_(acStack1156,*(float *)&this->field_0x3dc);
    cSAngle::operator__(local_488,&(this->field_0x3c).mAngleX);
    cSAngle::cSAngle(local_498,local_488[0]);
    (this->field_0x3c).mAngleX.v = local_498[0];
    this->mEvFovy =
         (float)((double)this->mEvFovy +
                (double)(float)(dVar22 * (double)(float)(dVar24 - (double)this->mEvFovy)));
    this->mEvBank =
         (float)((double)this->mEvBank +
                (double)(float)(dVar22 * (double)(float)(dVar25 - (double)this->mEvBank)));
    if (this->mEvFovy <= local_3c8.mDistance) {
      if (local_3c8.mDistance <= this->mEvBank) {
        *(float *)&this->field_0x3d8 = d_camera::1_0;
      }
      else {
        *(float *)&this->field_0x3d8 =
             (float)((double)*(float *)&this->field_0x3d8 +
                    (double)(d_camera::_6065 *
                            (float)(dVar23 - (double)*(float *)&this->field_0x3d8)));
        local_3c8.mDistance = this->mEvBank;
      }
    }
    else {
      *(float *)&this->field_0x3d8 =
           (float)((double)*(float *)&this->field_0x3d8 +
                  (double)(d_camera::_6065 * (float)(dVar23 - (double)*(float *)&this->field_0x3d8))
                  );
      local_3c8.mDistance = this->mEvFovy;
    }
    fVar29 = (this->field_0x3c).mDistance;
    (this->field_0x3c).mDistance =
         fVar29 + *(float *)&this->field_0x3d8 * (local_3c8.mDistance - fVar29);
    cSGlobe::Xyz(&cStack924,&this->field_0x3c);
    ::cXyz::operator__(&local_3a8,&this->field_0x44,&cStack924);
    (this->field_0x50).x = local_3a8.x;
    (this->field_0x50).y = local_3a8.y;
    (this->field_0x50).z = local_3a8.z;
    *(float *)&this->field_0x3e4 =
         (float)((double)*(float *)&this->field_0x3e4 +
                (double)(d_camera::_6065 * (float)(dVar11 - (double)*(float *)&this->field_0x3e4)));
    this->field_0x60 =
         (float)((double)this->field_0x60 +
                (double)(*(float *)&this->field_0x3e4 * (float)(dVar28 - (double)this->field_0x60)))
    ;
    dBgS_CamLinChk_NorWtr::_dBgS_CamLinChk_NorWtr((dBgS_CamLinChk_NorWtr *)&dStack552);
  }
  __psq_l0(auStack8,uVar9);
  __psq_l1(auStack8,uVar9);
  __psq_l0(auStack24,uVar9);
  __psq_l1(auStack24,uVar9);
  __psq_l0(auStack40,uVar9);
  __psq_l1(auStack40,uVar9);
  __psq_l0(auStack56,uVar9);
  __psq_l1(auStack56,uVar9);
  __psq_l0(auStack72,uVar9);
  __psq_l1(auStack72,uVar9);
  __psq_l0(auStack88,uVar9);
  __psq_l1(auStack88,uVar9);
  __psq_l0(auStack104,uVar9);
  __psq_l1(auStack104,uVar9);
  __psq_l0(auStack120,uVar9);
  __psq_l1(auStack120,uVar9);
  __psq_l0(auStack136,uVar9);
  __psq_l1(auStack136,uVar9);
  __psq_l0(auStack152,uVar9);
  __psq_l1(auStack152,uVar9);
  __psq_l0(auStack168,uVar9);
  __psq_l1(auStack168,uVar9);
  __psq_l0(auStack184,uVar9);
  __psq_l1(auStack184,uVar9);
  __psq_l0(auStack200,uVar9);
  __psq_l1(auStack200,uVar9);
  __psq_l0(auStack216,uVar9);
  __psq_l1(auStack216,uVar9);
  __psq_l0(auStack232,uVar9);
  __psq_l1(auStack232,uVar9);
  __psq_l0(auStack248,uVar9);
  __psq_l1(auStack248,uVar9);
  __psq_l0(auStack264,uVar9);
  __psq_l1(auStack264,uVar9);
  __psq_l0(auStack280,uVar9);
  __psq_l1(auStack280,uVar9);
  return 1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x80173444) */
/* WARNING: Removing unreachable block (ram,0x80173434) */
/* WARNING: Removing unreachable block (ram,0x8017343c) */
/* WARNING: Removing unreachable block (ram,0x8017344c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dCamera_c::crawlCamera(long) */

undefined4 __thiscall dCamera_c::crawlCamera(dCamera_c *this,long param_1)

{
  float fVar1;
  short sVar2;
  char cVar3;
  cSAngle *pcVar4;
  cSAngle *pcVar5;
  undefined4 uVar6;
  undefined8 in_f28;
  double dVar7;
  undefined8 in_f29;
  double dVar8;
  undefined8 in_f30;
  double dVar9;
  undefined8 in_f31;
  double dVar10;
  cSAngle local_198 [2];
  cSAngle acStack404 [2];
  undefined auStack400 [4];
  cSAngle local_18c [2];
  cSAngle acStack392 [2];
  cSAngle acStack388 [2];
  cSAngle local_180 [2];
  cSAngle acStack380 [2];
  cSAngle acStack376 [2];
  cSAngle acStack372 [2];
  cSAngle acStack368 [2];
  cSAngle acStack364 [2];
  cSAngle acStack360 [2];
  cSAngle acStack356 [2];
  cSAngle acStack352 [2];
  cSAngle acStack348 [2];
  cSAngle acStack344 [2];
  cSAngle acStack340 [2];
  undefined auStack336 [4];
  cSAngle local_14c [2];
  cSAngle local_148 [2];
  cSAngle local_144 [2];
  cSAngle local_140 [2];
  cSAngle local_13c [2];
  cSAngle acStack312 [2];
  cSAngle acStack308 [2];
  cSAngle acStack304 [2];
  cSAngle local_12c [2];
  cSAngle local_128 [2];
  cSAngle acStack292 [2];
  cSAngle acStack288 [2];
  cSAngle acStack284 [2];
  cSAngle local_118 [2];
  cXyz local_114;
  cXyz cStack264;
  cXyz cStack252;
  cXyz cStack240;
  cXyz cStack228;
  cXyz cStack216;
  cXyz cStack204;
  cXyz local_c0;
  cXyz cStack180;
  cXyz cStack168;
  cXyz cStack156;
  cXyz local_90;
  float local_84;
  float local_80;
  float local_7c;
  cXyz local_78;
  cXyz local_6c;
  int local_60;
  uint uStack92;
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  local_6c.x = dCamParam_c::styles[param_1].field_0xc;
  local_6c.y = dCamParam_c::styles[param_1].mCenterHeightBase;
  local_6c.z = dCamParam_c::styles[param_1].field_0x8;
  dVar8 = (double)dCamParam_c::styles[param_1].field_0x14;
  dVar7 = (double)dCamParam_c::styles[param_1].field_0x18;
  dVar9 = (double)dCamParam_c::styles[param_1].field_0x30;
  dVar10 = (double)dCamParam_c::styles[param_1].mFovyBase;
  directionOf((dCamera_c *)acStack308,(fopAc_ac_c *)this);
  pcVar4 = &(this->field_0x3c).mAngleY;
  cSAngle::operator__(acStack312,acStack308);
  cSAngle::cSAngle(local_118,acStack312);
  if (this->field_0x108 == 0) {
    *(undefined4 *)&this->field_0x378 = 0x4352574c;
    *(char *)&this->mEvBank = '\x01' - ((dCamParam_c::styles[param_1].mFlag & 0x80) == 0);
    *(undefined *)((int)&this->mEvBank + 1) = 0;
    *(undefined4 *)&this->field_0x37c = 10;
    if ((((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4] & 0x8000000U) != 0)
       && (this->field_0x1ae != 0)) {
      *(undefined4 *)&this->field_0x37c = 6;
    }
    this->mpEvRelActor = (fopAc_ac_c *)0x5;
    uStack92 = *(int *)&this->field_0x37c * (*(int *)&this->field_0x37c + 1) >> 1 ^ 0x80000000;
    local_60 = 0x43300000;
    *(float *)&this->field_0x380 = (float)((double)CONCAT44(0x43300000,uStack92) - d_camera::_5738);
    if ((dCamParam_c::styles[param_1].mFlag & 0x40) == 0) {
      *(undefined4 *)&this->field_0x388 = 1;
    }
    else {
      if ((__270 < local_118[0]) && (local_118[0] < __90)) {
        *(undefined4 *)&this->field_0x388 = 0;
      }
      else {
        *(undefined4 *)&this->field_0x388 = 1;
      }
    }
  }
  else {
    if ((dCamParam_c::styles[param_1].mFlag & 0x40) == 0) {
      *(undefined4 *)&this->field_0x388 = 1;
    }
    else {
      cSAngle::cSAngle(local_13c,d_camera::_11369);
      if ((((int)(short)(local_118[0] ^ local_13c[0]) >> 1) -
           (int)(short)((local_118[0] ^ local_13c[0]) & local_118[0]) < 0) &&
         (cSAngle::cSAngle(local_140,d_camera::_11363),
         ((int)(short)(local_140[0] ^ local_118[0]) >> 1) -
         (int)(short)((local_140[0] ^ local_118[0]) & local_140[0]) < 0)) {
        *(undefined4 *)&this->field_0x388 = 0;
      }
      else {
        cSAngle::cSAngle(local_144,d_camera::_13047);
        if ((((int)(short)(local_144[0] ^ local_118[0]) >> 1) -
             (int)(short)((local_144[0] ^ local_118[0]) & local_144[0]) < 0) ||
           (cSAngle::cSAngle(local_148,d_camera::_10810),
           ((int)(short)(local_118[0] ^ local_148[0]) >> 1) -
           (int)(short)((local_118[0] ^ local_148[0]) & local_118[0]) < 0)) {
          *(undefined4 *)&this->field_0x388 = 1;
        }
      }
    }
  }
  if (this->field_0x1ae != 0) {
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].field_0x8 =
         d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].field_0x8 | 0x80
    ;
  }
  if ((((dCamParam_c::styles[param_1].mFlag & 0x40) == 0) || (this->mCurArrowIdx == 0xff)) ||
     ((this->mCurRoomCamEntry).field_0x12 == 0xff)) {
    *(undefined *)((int)&this->mEvBank + 1) = 0;
  }
  else {
    cSAngle::operator__(local_14c,pcVar4,(this->mCurRoomArrowEntry).mRot.y);
    local_118[0] = local_14c[0];
    if ((__270 < local_14c[0]) && (local_14c[0] < __90)) {
      *(float *)&this->field_0x38c = (this->mCurRoomArrowEntry).mPos.x;
      *(float *)&this->field_0x390 = (this->mCurRoomArrowEntry).mPos.y;
      this->mEvFovy = (this->mCurRoomArrowEntry).mPos.z;
      *(undefined *)((int)&this->mEvBank + 1) = 1;
      *(undefined *)&this->field_0x102 = 1;
      *(undefined *)&this->field_0x101 = 1;
      *(undefined *)&this->field_0x100 = 1;
    }
  }
  if (*(char *)&this->field_0x100 == '\0') {
    uStack92 = *(int *)&this->field_0x37c - this->field_0x108 ^ 0x80000000;
    local_60 = 0x43300000;
    *(float *)&this->field_0x384 = (float)((double)CONCAT44(0x43300000,uStack92) - d_camera::_5738);
    dVar7 = (double)(*(float *)&this->field_0x384 / *(float *)&this->field_0x380);
    relationalPos(&local_90,this,this->mpPlayerActor,&local_6c);
    local_78.x = local_90.x;
    local_78.y = local_90.y;
    local_78.z = local_90.z;
    ::cXyz::operator__(&cStack156,&local_78,&this->field_0x44);
    ::cXyz::operator_(&cStack168,&cStack156,(float)dVar7);
    mtx::PSVECAdd(&this->field_0x44,&cStack168,&this->field_0x44);
    if ((dCamParam_c::styles[param_1].mFlag & 0x80) != 0) {
      dVar9 = (double)d_camera::_9007;
    }
    dVar8 = (double)(this->field_0x3c).mDistance;
    dVar8 = (double)(float)(dVar8 + (double)(float)(dVar7 * (double)(float)(dVar9 - dVar8)));
    pcVar5 = &(this->field_0x3c).mAngleX;
    SComponent::operator__(auStack336,(int)(this->mpPlayerActor->mCollisionRot).x,pcVar5);
    cSAngle::operator_(acStack340,(float)dVar7);
    cSAngle::operator__(acStack344,pcVar5);
    cSAngle::cSAngle(acStack284,acStack344);
    if (*(int *)&this->field_0x388 == 0) {
      directionOf((dCamera_c *)acStack352,(fopAc_ac_c *)this);
      cSAngle::Val(acStack288,acStack352);
    }
    else {
      directionOf((dCamera_c *)acStack348,(fopAc_ac_c *)this);
      sVar2 = cSAngle::Inv(acStack348);
      cSAngle::Val(acStack288,sVar2);
    }
    cSAngle::operator__(acStack356,acStack288);
    cSAngle::operator_(acStack360,(float)dVar7);
    cSAngle::operator__(acStack364,pcVar4);
    cSAngle::cSAngle(acStack292,acStack364);
    cSGlobe::Val(&this->field_0x3c,(float)dVar8,acStack284,acStack292);
    cSGlobe::Xyz(&cStack180,&this->field_0x3c);
    ::cXyz::operator__(&local_c0,&this->field_0x44,&cStack180);
    (this->field_0x50).x = local_c0.x;
    (this->field_0x50).y = local_c0.y;
    (this->field_0x50).z = local_c0.z;
    this->field_0x60 =
         (float)((double)this->field_0x60 +
                (double)(float)(dVar7 * (double)(float)(dVar10 - (double)this->field_0x60)));
    if (*(int *)&this->field_0x37c - 1U <= (uint)this->field_0x108) {
      *(undefined *)&this->field_0x102 = 1;
      *(undefined *)&this->field_0x101 = 1;
      *(undefined *)&this->field_0x100 = 1;
    }
    *(float *)&this->field_0x380 = *(float *)&this->field_0x380 - *(float *)&this->field_0x384;
  }
  else {
    local_84 = (float)dVar8;
    local_80 = (float)dVar7;
    local_7c = (float)dVar8;
    relationalPos(&cStack204,this,this->mpPlayerActor,&local_6c);
    ::cXyz::operator__(&cStack216,&cStack204,&this->field_0x44);
    ::cXyz::operator_(&cStack228,(Vec *)&cStack216);
    mtx::PSVECAdd(&this->field_0x44,&cStack228,&this->field_0x44);
    if ((*(char *)((int)&this->mEvBank + 1) == '\x01') &&
       (cVar3 = lineBGCheck(this,&this->field_0x44,(cXyz *)&this->field_0x38c,0x7f), cVar3 == '\0'))
    {
      (this->field_0x50).x = *(float *)&this->field_0x38c;
      (this->field_0x50).y = *(float *)&this->field_0x390;
      (this->field_0x50).z = this->mEvFovy;
      ::cXyz::operator__(&cStack240,&this->field_0x50,&this->field_0x44);
      cSGlobe::Val(&this->field_0x3c,&cStack240);
      if (*(char *)&this->field_0x220 == '\0') {
        setDMCAngle(this);
      }
      this->field_0x1ae = 0;
    }
    else {
      if (*(int *)&this->field_0x388 == 0) {
        directionOf((dCamera_c *)acStack372,(fopAc_ac_c *)this);
        cSAngle::Val(acStack304,acStack372);
      }
      else {
        directionOf((dCamera_c *)acStack368,(fopAc_ac_c *)this);
        sVar2 = cSAngle::Inv(acStack368);
        cSAngle::Val(acStack304,sVar2);
      }
      if (*(char *)&this->mEvBank == '\0') {
        dVar7 = (double)(this->field_0x3c).mDistance;
        dVar7 = (double)(float)(dVar7 + (double)(d_camera::0_25 * (float)(dVar9 - dVar7)));
        cSAngle::operator__(acStack388,acStack304);
        cSAngle::operator_(acStack392,d_camera::_9011);
        cSAngle::operator__(local_18c,pcVar4);
        local_128[0] = local_18c[0];
      }
      else {
        positionOf(&cStack252,this,this->mpPlayerActor);
        (this->field_0x44).y = d_camera::30_0 + cStack252.y;
        fVar1 = (this->field_0x3c).mDistance;
        dVar7 = (double)(fVar1 + d_camera::_13048 * (d_camera::_9007 - fVar1));
        cSAngle::operator__(acStack376,acStack304);
        cSAngle::operator_(acStack380,d_camera::_13048);
        cSAngle::operator__(local_180,pcVar4);
        local_128[0] = local_180[0];
        this->mEventFlags = this->mEventFlags | 0x800;
      }
      pcVar4 = &(this->field_0x3c).mAngleX;
      SComponent::operator__(auStack400,(int)(this->mpPlayerActor->mCollisionRot).x,pcVar4);
      cSAngle::operator_(acStack404,d_camera::0_25);
      cSAngle::operator__(local_198,pcVar4);
      local_12c[0] = local_198[0];
      cSGlobe::Val(&this->field_0x3c,(float)dVar7,local_12c,local_128);
      cSGlobe::Xyz(&cStack264,&this->field_0x3c);
      ::cXyz::operator__(&local_114,&this->field_0x44,&cStack264);
      (this->field_0x50).x = local_114.x;
      (this->field_0x50).y = local_114.y;
      (this->field_0x50).z = local_114.z;
    }
    this->field_0x60 =
         (float)((double)this->field_0x60 +
                (double)(d_camera::_6431 * (float)(dVar10 - (double)this->field_0x60)));
  }
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  __psq_l0(auStack24,uVar6);
  __psq_l1(auStack24,uVar6);
  __psq_l0(auStack40,uVar6);
  __psq_l1(auStack40,uVar6);
  __psq_l0(auStack56,uVar6);
  __psq_l1(auStack56,uVar6);
  return 1;
}


/* WARNING: Inlined function: __save_gpr */
/* WARNING: Inlined function: __restore_gpr */
/* WARNING: Removing unreachable block (ram,0x80173e18) */
/* WARNING: Removing unreachable block (ram,0x80173e08) */
/* WARNING: Removing unreachable block (ram,0x80173e10) */
/* WARNING: Removing unreachable block (ram,0x80173e20) */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall dCamera_c::hookshotCamera(long) */

undefined4 __thiscall dCamera_c::hookshotCamera(dCamera_c *this,long param_1)

{
  undefined *puVar1;
  uint uVar2;
  cBgS_PolyPassChk *pcVar3;
  fopAc_ac_c *pfVar4;
  char cVar5;
  uint uVar6;
  int iVar7;
  cBgS_PolyPassChk *pcVar8;
  undefined4 uVar9;
  double dVar10;
  undefined8 in_f28;
  undefined8 in_f29;
  double dVar11;
  undefined8 in_f30;
  double dVar12;
  undefined8 in_f31;
  double dVar13;
  float fVar14;
  cSAngle local_2b8 [2];
  cSAngle local_2b4 [2];
  cSAngle local_2b0 [2];
  cSAngle local_2ac [2];
  cSAngle local_2a8 [2];
  cSAngle acStack676 [2];
  cSAngle acStack672 [2];
  cSAngle local_29c [2];
  cSAngle acStack664 [2];
  cSAngle acStack660 [2];
  cSAngle local_290 [2];
  cSAngle local_28c [2];
  float local_288;
  int local_284;
  cSGlobe local_280;
  cSGlobe cStack632;
  cXyz local_270;
  cXyz cStack612;
  cXyz cStack600;
  cXyz cStack588;
  cXyz cStack576;
  cXyz local_234;
  cXyz local_228;
  cXyz cStack540;
  cXyz cStack528;
  cXyz local_204;
  cXyz local_1f8;
  cXyz cStack492;
  cXyz local_1e0;
  float local_1d4;
  float local_1d0;
  float local_1cc;
  float local_1c8;
  float local_1c4;
  float local_1c0;
  float local_1bc;
  float local_1b8;
  float local_1b4;
  float local_1b0;
  float local_1ac;
  float local_1a8;
  cXyz local_1a4;
  float local_198;
  float local_194;
  float local_190;
  cXyz local_18c;
  cXyz local_180;
  cXyz local_174;
  cXyz local_168;
  float local_15c [4];
  float local_14c;
  float local_148;
  float local_144;
  float local_140;
  float local_13c;
  float local_138;
  float local_134;
  float local_130;
  undefined local_12c [104];
  uint local_c4;
  undefined *local_c0;
  cBgS_PolyPassChk__vtbl *local_bc;
  cBgS_PolyInfo__vtbl *local_b8;
  undefined **local_b4;
  undefined **local_b0;
  cBgS_Chk__vtbl *local_ac;
  undefined **local_a8;
  undefined4 local_a4;
  undefined **local_a0;
  undefined **local_9c;
  undefined **local_98;
  undefined **local_94;
  undefined **local_90;
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar9 = 0;
  puVar1 = &stack0xfffffd40;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  local_174.x = dCamParam_c::styles[param_1].field_0xc;
  local_174.y = dCamParam_c::styles[param_1].mCenterHeightBase;
  local_174.z = dCamParam_c::styles[param_1].field_0x8;
  local_194 = dCamParam_c::styles[param_1].field_0x18;
  local_198 = dCamParam_c::styles[param_1].field_0x14;
  dVar13 = (double)dCamParam_c::styles[param_1].field_0x30;
  dVar12 = (double)dCamParam_c::styles[param_1].field_0x34;
  dVar11 = (double)dCamParam_c::styles[param_1].field_0x40;
  fVar14 = dCamParam_c::styles[param_1].mLockonLongitudeMin;
  dVar10 = (double)dCamParam_c::styles[param_1].mFovyBase;
  local_1b0 = d_camera::180_0;
  local_1ac = d_camera::_9010;
  local_1a8 = d_camera::_13450;
  local_15c[0] = d_camera::180_0;
  local_15c[1] = d_camera::_9010;
  local_15c[2] = d_camera::_13450;
  local_1bc = d_camera::_6117;
  local_1b8 = d_camera::_10130;
  local_1b4 = d_camera::_12162;
  local_15c[3] = d_camera::_6117;
  local_14c = d_camera::_10130;
  local_148 = d_camera::_12162;
  local_1c8 = d_camera::_9002;
  local_1c4 = d_camera::_11362;
  local_1c0 = d_camera::_13451;
  local_144 = d_camera::_9002;
  local_140 = d_camera::_11362;
  local_13c = d_camera::_13451;
  local_1d4 = d_camera::_10811;
  local_1d0 = d_camera::_13450;
  local_1cc = d_camera::_13452;
  local_138 = d_camera::_10811;
  local_134 = d_camera::_13450;
  local_130 = d_camera::_13452;
  if (this->field_0x11c == 0) {
    *(undefined4 *)&this->field_0x378 = 0x484f4f4b;
    *(float *)&this->field_0x380 = (this->field_0x44).x;
    *(float *)&this->field_0x384 = (this->field_0x44).y;
    *(float *)&this->field_0x388 = (this->field_0x44).z;
    local_284 = (**(code **)(*(int *)&this->mpPlayerActor[1].parent.parent.mPi.mMtdTg.parent.mbAdded
                            + 0x50))();
    *(undefined *)&this->mEvBank = 0;
    if (local_284 != -1) {
      pfVar4 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,&local_284);
      positionOf(&local_1e0,this,this->mpPlayerActor);
      local_180.x = local_1e0.x;
      local_180.y = local_1e0.y;
      local_180.z = local_1e0.z;
      positionOf(&cStack492,this,pfVar4);
      ::cXyz::operator__(&local_1f8,&cStack492,&local_180);
      local_204.x = local_1f8.x;
      local_204.y = local_1f8.y;
      local_204.z = local_1f8.z;
      fVar14 = mtx::PSVECSquareMag(&local_204);
      dVar10 = (double)fVar14;
      if ((double)d_camera::0_0 < dVar10) {
        dVar12 = 1.0 / SQRT(dVar10);
        dVar12 = d_camera::_5735 * dVar12 * (d_camera::_5736 - dVar10 * dVar12 * dVar12);
        dVar12 = d_camera::_5735 * dVar12 * (d_camera::_5736 - dVar10 * dVar12 * dVar12);
        local_288 = (float)(dVar10 * d_camera::_5735 * dVar12 *
                                     (d_camera::_5736 - dVar10 * dVar12 * dVar12));
        dVar10 = (double)local_288;
      }
      if (dVar11 < dVar10) {
        uVar6 = *(uint *)&this->field_0x7c >> 4 & 1;
        iVar7 = 0;
        local_b4 = &::cBgS_LinChk::__vt;
        pcVar8 = (cBgS_PolyPassChk *)(local_12c + 0x58);
        local_b0 = &::dBgS_Chk::__vt;
        local_b8 = (cBgS_PolyInfo__vtbl *)&DAT_803910b0;
        local_bc = (cBgS_PolyPassChk__vtbl *)&DAT_803910bc;
        local_c0 = local_12c;
        local_ac = &cBgS_Chk::__vt;
        local_a8 = &::cBgS_PolyInfo::__vt;
        local_a4 = 0xffff;
        local_a0 = &::cM3dGLin::__vt;
        local_9c = &::cBgS_PolyPassChk::__vt;
        local_98 = &::dBgS_PolyPassChk::__vt;
        local_94 = &::cBgS_GrpPassChk::__vt;
        local_90 = &::dBgS_GrpPassChk::__vt;
        do {
          uVar2 = *(int *)&this->field_0x7c + iVar7 & 3;
          local_18c.x = local_15c[uVar2 * 3];
          local_18c.y = local_15c[uVar2 * 3 + 1];
          local_18c.z = local_15c[uVar2 * 3 + 2];
          if ((uVar6 & 0xff) != 0) {
            local_18c.x = -local_18c.x;
          }
          cSGlobe::cSGlobe(&cStack632,&local_18c);
          cSAngle::operator__(local_28c,(short)puVar1 + 0x4e);
          cSAngle::cSAngle(local_2ac,local_28c[0]);
          cStack632.mAngleY = local_2ac[0];
          cSAngle::operator__(local_290,(short)puVar1 + 0x4c);
          cSAngle::cSAngle(local_2b0,local_290[0]);
          cStack632.mAngleX = local_2b0[0];
          positionOf(&cStack528,this,pfVar4);
          cSGlobe::Xyz(&cStack540,&cStack632);
          ::cXyz::operator__(&local_228,&cStack528,&cStack540);
          *(float *)&this->field_0x38c = local_228.x;
          *(float *)&this->field_0x390 = local_228.y;
          this->mEvFovy = local_228.z;
          local_12c._0_4_ = (cBgS_PolyPassChk *)0x0;
          local_12c._4_4_ = (cBgS_GrpPassChk *)0x0;
          local_12c[12] = true;
          local_12c._20_2_ = (short)local_a4;
          local_12c._22_2_ = 0x100;
          local_12c._24_4_ = (cBgW *)0x0;
          local_12c._28_4_ = -1;
          local_12c._16_4_ = local_b4;
          local_12c._32_4_ = &PTR_80371fbc;
          local_12c._60_4_ = local_a0;
          ::cBgS_LinChk::ct((cBgS_LinChk *)local_12c);
          local_12c[92] = 0;
          local_12c[94] = 0;
          local_12c[95] = 0;
          local_12c[96] = 0;
          local_12c[97] = 0;
          local_12c[98] = 0;
          local_c4 = 1;
          pcVar3 = pcVar8;
          if (pcVar8 != (cBgS_PolyPassChk *)0x0) {
            pcVar3 = (cBgS_PolyPassChk *)(local_12c + 100);
          }
          *(cBgS_PolyPassChk **)(local_c0 + 4) = pcVar3;
          local_12c[93] = 1;
          local_12c._16_4_ = (undefined **)&dBgS_CamLinChk_NorWtr::__vt;
          local_12c._32_4_ = &local_b8->field_0x0;
          local_12c._88_4_ = &local_bc->field_0x0;
          local_12c._100_4_ = (undefined **)&DAT_803910c8;
          local_c4 = local_c4 | 3;
          local_12c._0_4_ = pcVar8;
          cVar5 = lineBGCheck(this,&local_180,(cXyz *)&this->field_0x38c,(dBgS_LinChk *)local_12c,
                              0xf);
          if (cVar5 == '\0') {
            *(undefined *)&this->mEvBank = 1;
            local_12c._88_4_ = &PTR_80371f44;
            local_12c._100_4_ = &PTR_80371f50;
            if (pcVar8 != (cBgS_PolyPassChk *)0x0) {
              local_12c._88_4_ = &::dBgS_Chk::__vt;
              local_12c._100_4_ = &PTR_80371f68;
              if ((puVar1 != (undefined *)0xfffffe08) &&
                 (local_12c._100_4_ = &::dBgS_GrpPassChk::__vt, puVar1 != (undefined *)0xfffffe08))
              {
                local_12c._100_4_ = &::cBgS_GrpPassChk::__vt;
              }
              if ((pcVar8 != (cBgS_PolyPassChk *)0x0) &&
                 (local_12c._88_4_ = &::dBgS_PolyPassChk::__vt, pcVar8 != (cBgS_PolyPassChk *)0x0))
              {
                local_12c._88_4_ = &::cBgS_PolyPassChk::__vt;
              }
            }
            local_12c._16_4_ = &::cBgS_LinChk::__vt;
            local_12c._32_4_ = &PTR_80371fbc;
            if (puVar1 != (undefined *)0xfffffe48) {
              local_12c._60_4_ = &::cM3dGLin::__vt;
            }
            if (puVar1 != (undefined *)0xfffffe58) {
              local_12c._32_4_ = &::cBgS_PolyInfo::__vt;
            }
            cBgS_Chk::_cBgS_Chk((cBgS_Chk *)local_12c);
            break;
          }
          if (iVar7 == 3) {
            uVar6 = countLeadingZeros(uVar6 & 0xff);
            uVar6 = uVar6 >> 5;
          }
          local_12c._88_4_ = &PTR_80371f44;
          local_12c._100_4_ = &PTR_80371f50;
          if (pcVar8 != (cBgS_PolyPassChk *)0x0) {
            local_12c._88_4_ = &::dBgS_Chk::__vt;
            local_12c._100_4_ = &PTR_80371f68;
            if ((puVar1 != (undefined *)0xfffffe08) &&
               (local_12c._100_4_ = &::dBgS_GrpPassChk::__vt, puVar1 != (undefined *)0xfffffe08)) {
              local_12c._100_4_ = &::cBgS_GrpPassChk::__vt;
            }
            if ((pcVar8 != (cBgS_PolyPassChk *)0x0) &&
               (local_12c._88_4_ = &::dBgS_PolyPassChk::__vt, pcVar8 != (cBgS_PolyPassChk *)0x0)) {
              local_12c._88_4_ = &::cBgS_PolyPassChk::__vt;
            }
          }
          local_12c._16_4_ = local_b4;
          local_12c._32_4_ = &PTR_80371fbc;
          if (puVar1 != (undefined *)0xfffffe48) {
            local_12c._60_4_ = &::cM3dGLin::__vt;
          }
          if (puVar1 != (undefined *)0xfffffe58) {
            local_12c._32_4_ = &::cBgS_PolyInfo::__vt;
          }
          cBgS_Chk::_cBgS_Chk((cBgS_Chk *)local_12c);
          iVar7 = iVar7 + 1;
        } while (iVar7 < 8);
      }
    }
    *(undefined *)&this->field_0x102 = 1;
    *(undefined *)&this->field_0x101 = 1;
    *(undefined *)&this->field_0x100 = 1;
  }
  else {
    if ((*(char *)&this->mEvBank == '\0') || ((uint)this->field_0x11c < 9)) {
      local_168.x = (this->mEye).x;
      local_168.y = (this->mEye).y;
      local_168.z = (this->mEye).z;
    }
    else {
      local_168.x = *(float *)&this->field_0x38c;
      local_168.y = *(float *)&this->field_0x390;
      local_168.z = this->mEvFovy;
      fVar14 = d_camera::1_0;
    }
    dVar11 = (double)fVar14;
    local_190 = local_198;
    relationalPos(&local_234,this,this->mpPlayerActor,&local_174);
    local_1a4.x = local_234.x;
    local_1a4.y = local_234.y;
    local_1a4.z = local_234.z;
    if (this->field_0x31d != 0) {
      dBgS::MoveBgMatrixCrrPos
                (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,&(this->mBG).field_0x74,true,
                 (cXyz *)&this->field_0x380,(csXyz *)0x0,(csXyz *)0x0);
      dBgS::MoveBgMatrixCrrPos
                (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,&(this->mBG).field_0x74,true,
                 (cXyz *)&this->field_0x38c,(csXyz *)0x0,(csXyz *)0x0);
    }
    ::cXyz::operator__(&cStack576,&local_1a4,&this->field_0x44);
    ::cXyz::operator_(&cStack588,(Vec *)&cStack576);
    mtx::PSVECAdd(&this->field_0x44,&cStack588,&this->field_0x44);
    ::cXyz::operator__(&cStack600,&local_168,&this->field_0x44);
    cSGlobe::cSGlobe(&local_280,&cStack600);
    if ((double)local_280.mDistance < dVar12) {
      local_280.mDistance = (float)dVar12;
    }
    if (dVar13 < (double)local_280.mDistance) {
      local_280.mDistance = (float)dVar13;
    }
    fVar14 = (this->field_0x3c).mDistance;
    (this->field_0x3c).mDistance = fVar14 + (float)(dVar11 * (double)(local_280.mDistance - fVar14))
    ;
    cSAngle::operator__(acStack660,&local_280.mAngleX);
    cSAngle::operator_(acStack664,(float)dVar11);
    cSAngle::operator__(local_29c,&(this->field_0x3c).mAngleX);
    cSAngle::cSAngle(local_2b4,local_29c[0]);
    (this->field_0x3c).mAngleX.v = local_2b4[0];
    cSAngle::operator__(acStack672,&local_280.mAngleY);
    cSAngle::operator_(acStack676,(float)dVar11);
    cSAngle::operator__(local_2a8,&(this->field_0x3c).mAngleY);
    cSAngle::cSAngle(local_2b8,local_2a8[0]);
    (this->field_0x3c).mAngleY.v = local_2b8[0];
    cSGlobe::Xyz(&cStack612,&this->field_0x3c);
    ::cXyz::operator__(&local_270,&this->field_0x44,&cStack612);
    (this->field_0x50).x = local_270.x;
    (this->field_0x50).y = local_270.y;
    (this->field_0x50).z = local_270.z;
    this->field_0x60 =
         (float)((double)this->field_0x60 +
                (double)(float)(dVar11 * (double)(float)(dVar10 - (double)this->field_0x60)));
  }
  __psq_l0(auStack8,uVar9);
  __psq_l1(auStack8,uVar9);
  __psq_l0(auStack24,uVar9);
  __psq_l1(auStack24,uVar9);
  __psq_l0(auStack40,uVar9);
  __psq_l1(auStack40,uVar9);
  __psq_l0(auStack56,uVar9);
  __psq_l1(auStack56,uVar9);
  return 1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x80174e70) */
/* WARNING: Removing unreachable block (ram,0x80174e60) */
/* WARNING: Removing unreachable block (ram,0x80174e50) */
/* WARNING: Removing unreachable block (ram,0x80174e40) */
/* WARNING: Removing unreachable block (ram,0x80174e30) */
/* WARNING: Removing unreachable block (ram,0x80174e20) */
/* WARNING: Removing unreachable block (ram,0x80174e10) */
/* WARNING: Removing unreachable block (ram,0x80174e08) */
/* WARNING: Removing unreachable block (ram,0x80174e18) */
/* WARNING: Removing unreachable block (ram,0x80174e28) */
/* WARNING: Removing unreachable block (ram,0x80174e38) */
/* WARNING: Removing unreachable block (ram,0x80174e48) */
/* WARNING: Removing unreachable block (ram,0x80174e58) */
/* WARNING: Removing unreachable block (ram,0x80174e68) */
/* WARNING: Removing unreachable block (ram,0x80174e78) */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall dCamera_c::tornadoCamera(long) */

undefined4 __thiscall dCamera_c::tornadoCamera(dCamera_c *this,long param_1)

{
  float fVar1;
  cSAngle *pcVar2;
  fopAc_ac_c *pfVar3;
  cSGlobe *this_00;
  short sVar6;
  char cVar7;
  uint uVar4;
  undefined4 uVar5;
  int iVar8;
  undefined4 uVar9;
  undefined8 in_f17;
  double dVar10;
  undefined8 in_f18;
  double dVar11;
  undefined8 in_f19;
  double dVar12;
  undefined8 in_f20;
  double dVar13;
  undefined8 in_f21;
  double dVar14;
  undefined8 in_f22;
  double dVar15;
  undefined8 in_f23;
  double dVar16;
  undefined8 in_f24;
  double dVar17;
  undefined8 in_f25;
  double dVar18;
  undefined8 in_f26;
  double dVar19;
  undefined8 in_f27;
  double dVar20;
  undefined8 in_f28;
  double dVar21;
  undefined8 in_f29;
  double dVar22;
  undefined8 in_f30;
  double dVar23;
  undefined8 in_f31;
  double dVar24;
  cSAngle local_408 [2];
  cSAngle local_404 [2];
  cSAngle local_400 [2];
  cSAngle local_3fc [2];
  undefined2 local_3f8 [2];
  cSAngle local_3f4 [2];
  cSAngle local_3f0 [2];
  undefined2 local_3ec [2];
  cSAngle local_3e8 [2];
  cSAngle local_3e4 [2];
  undefined2 local_3e0;
  undefined2 local_3de;
  undefined2 local_3dc;
  undefined2 local_3da;
  cSAngle acStack984 [2];
  cSAngle acStack980 [2];
  cSAngle acStack976 [2];
  cSAngle acStack972 [2];
  cSAngle acStack968 [2];
  cSAngle acStack964 [2];
  cSAngle local_3c0 [2];
  cSAngle acStack956 [2];
  cSAngle acStack952 [2];
  cSAngle acStack948 [2];
  cSAngle acStack944 [2];
  cSAngle acStack940 [2];
  cSAngle acStack936 [2];
  cSAngle acStack932 [2];
  cSAngle local_3a0 [2];
  cSAngle acStack924 [2];
  cSAngle acStack920 [2];
  cSAngle local_394 [2];
  cSAngle acStack912 [2];
  cSAngle acStack908 [2];
  cSAngle local_388 [2];
  cSAngle acStack900 [2];
  cSAngle acStack896 [2];
  cSAngle acStack892 [2];
  cSAngle local_378 [2];
  cSAngle local_374 [2];
  cSAngle local_370 [2];
  cSAngle local_36c [2];
  cSAngle local_368 [2];
  cSAngle local_364 [2];
  cSAngle acStack864 [2];
  cSAngle acStack860 [2];
  cSAngle local_358 [2];
  cSAngle acStack852 [2];
  cSAngle acStack848 [2];
  cSAngle acStack844 [2];
  cSAngle local_348 [2];
  cSAngle acStack836 [2];
  cSAngle acStack832 [2];
  cSAngle acStack828 [2];
  cSAngle acStack824 [2];
  cSAngle acStack820 [2];
  cSAngle local_330 [2];
  cSAngle acStack812 [2];
  cSAngle local_328 [2];
  cSAngle local_324 [2];
  cSGlobe cStack800;
  cSGlobe cStack792;
  cSGlobe local_310;
  cSGlobe cStack776;
  cSGlobe cStack768;
  cSGlobe local_2f8;
  cXyz local_2f0;
  cXyz cStack740;
  cXyz cStack728;
  cXyz cStack716;
  cXyz cStack704;
  cXyz local_2b4;
  cXyz cStack680;
  cXyz cStack668;
  cXyz cStack656;
  cXyz local_284;
  cXyz cStack632;
  cXyz cStack620;
  float local_260;
  float local_25c;
  float local_258;
  cXyz cStack596;
  cXyz cStack584;
  cXyz cStack572;
  cXyz cStack560;
  cXyz local_224;
  cXyz cStack536;
  cXyz cStack524;
  cXyz local_200;
  cXyz cStack500;
  cXyz cStack488;
  cXyz cStack476;
  cXyz local_1d0;
  cXyz cStack452;
  cXyz cStack440;
  undefined *local_1ac;
  float local_1a8;
  float local_1a4;
  float local_1a0;
  undefined *local_19c;
  float local_198;
  cXyz local_194;
  cXyz cStack392;
  cXyz cStack380;
  float local_170;
  float local_16c;
  float local_168;
  float local_164;
  float local_160;
  float local_15c;
  cXyz cStack344;
  cXyz cStack332;
  cXyz cStack320;
  float local_134;
  float local_130;
  float local_12c;
  cXyz local_128;
  cXyz local_11c;
  double local_110;
  undefined auStack232 [16];
  undefined auStack216 [16];
  undefined auStack200 [16];
  undefined auStack184 [16];
  undefined auStack168 [16];
  undefined auStack152 [16];
  undefined auStack136 [16];
  undefined auStack120 [16];
  undefined auStack104 [16];
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar9 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  __psq_st0(auStack72,(int)((ulonglong)in_f27 >> 0x20),0);
  __psq_st1(auStack72,(int)in_f27,0);
  __psq_st0(auStack88,(int)((ulonglong)in_f26 >> 0x20),0);
  __psq_st1(auStack88,(int)in_f26,0);
  __psq_st0(auStack104,(int)((ulonglong)in_f25 >> 0x20),0);
  __psq_st1(auStack104,(int)in_f25,0);
  __psq_st0(auStack120,(int)((ulonglong)in_f24 >> 0x20),0);
  __psq_st1(auStack120,(int)in_f24,0);
  __psq_st0(auStack136,(int)((ulonglong)in_f23 >> 0x20),0);
  __psq_st1(auStack136,(int)in_f23,0);
  __psq_st0(auStack152,(int)((ulonglong)in_f22 >> 0x20),0);
  __psq_st1(auStack152,(int)in_f22,0);
  __psq_st0(auStack168,(int)((ulonglong)in_f21 >> 0x20),0);
  __psq_st1(auStack168,(int)in_f21,0);
  __psq_st0(auStack184,(int)((ulonglong)in_f20 >> 0x20),0);
  __psq_st1(auStack184,(int)in_f20,0);
  __psq_st0(auStack200,(int)((ulonglong)in_f19 >> 0x20),0);
  __psq_st1(auStack200,(int)in_f19,0);
  __psq_st0(auStack216,(int)((ulonglong)in_f18 >> 0x20),0);
  __psq_st1(auStack216,(int)in_f18,0);
  __psq_st0(auStack232,(int)((ulonglong)in_f17 >> 0x20),0);
  __psq_st1(auStack232,(int)in_f17,0);
  dVar11 = (double)dCamParam_c::styles[param_1].mCenterHeightBase;
  dVar12 = (double)dCamParam_c::styles[param_1].field_0x8;
  dVar24 = (double)dCamParam_c::styles[param_1].field_0xc;
  dVar23 = (double)dCamParam_c::styles[param_1].mLockonCenterHeightMin;
  dVar22 = (double)dCamParam_c::styles[param_1].field_0x14;
  dVar21 = (double)dCamParam_c::styles[param_1].field_0x18;
  dVar20 = (double)dCamParam_c::styles[param_1].field_0x30;
  dVar19 = (double)dCamParam_c::styles[param_1].field_0x3c;
  dVar10 = (double)dCamParam_c::styles[param_1].field_0x40;
  dVar18 = (double)dCamParam_c::styles[param_1].field_0x44;
  dVar17 = (double)dCamParam_c::styles[param_1].mLockonLatitudeMin;
  cSAngle::cSAngle(local_324,*(float *)&dCamParam_c::styles[param_1].field_0x48);
  cSAngle::cSAngle(local_328,*(float *)&dCamParam_c::styles[param_1].field_0x4c);
  dVar16 = (double)*(float *)&dCamParam_c::styles[param_1].field_0x58;
  dVar15 = (double)*(float *)&dCamParam_c::styles[param_1].field_0x5c;
  dVar14 = (double)dCamParam_c::styles[param_1].mFovyBase;
  dVar13 = (double)dCamParam_c::styles[param_1].mLockonFovyMin;
  pcVar2 = acStack812;
  cSAngle::cSAngle(pcVar2,dCamParam_c::styles[param_1].mLockonFovyMax);
  local_11c.x = d_camera::0_0;
  local_11c.y = (float)dVar11;
  local_11c.z = (float)dVar12;
  dVar10 = (double)@unnamed@d_camera_cpp@::limitf
                             ((_unnamed_d_camera_cpp_ *)pcVar2,
                              (float)((double)this->field_0x238 / dVar10),d_camera::0_0,
                              d_camera::1_0);
  local_3da = 0x1c0;
  pfVar3 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeForPName,&local_3da);
  *(fopAc_ac_c **)&this->field_0x380 = pfVar3;
  if (*(int *)&this->field_0x380 == 0) {
    local_3dc = 0x11d;
    pfVar3 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeForPName,&local_3dc);
    *(fopAc_ac_c **)&this->field_0x380 = pfVar3;
  }
  local_3de = 0xa7;
  pfVar3 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeForPName,&local_3de);
  *(fopAc_ac_c **)&this->field_0x37c = pfVar3;
  if (*(fopAc_ac_c **)&this->field_0x380 == (fopAc_ac_c *)0x0) {
    if (*(int *)&this->field_0x37c == 0) {
      directionOf((dCamera_c *)acStack864,(fopAc_ac_c *)this);
      cSAngle::Val(local_330,acStack864);
    }
    else {
      directionOf((dCamera_c *)acStack860,(fopAc_ac_c *)this);
      cSAngle::Val(local_330,acStack860);
    }
  }
  else {
    positionOf(&cStack320,this,*(fopAc_ac_c **)&this->field_0x380);
    positionOf(&cStack332,this,*(fopAc_ac_c **)&this->field_0x37c);
    ::cXyz::operator__(&cStack344,&cStack320,&cStack332);
    this_00 = &local_2f8;
    cSGlobe::cSGlobe(this_00,&cStack344);
    dVar11 = (double)@unnamed@d_camera_cpp@::limitf
                               ((_unnamed_d_camera_cpp_ *)this_00,
                                local_2f8.mDistance / d_camera::_14076,d_camera::0_0,d_camera::1_0);
    dVar10 = (double)(float)((double)d_camera::1_0 - dVar11);
    directionOf((dCamera_c *)acStack844,(fopAc_ac_c *)this);
    cSAngle::operator__(acStack848,acStack844);
    cSAngle::operator_(acStack852,(float)((double)d_camera::_6431 * dVar11));
    cSAngle::operator__(local_358,&local_2f8.mAngleY);
    local_330[0] = local_358[0];
  }
  if (this->field_0x11c == 0) {
    *(undefined4 *)&this->field_0x378 = 0x54524e44;
    this->mEvBank = ::cXyz::Zero.x;
    this->mpEvRelActor = (fopAc_ac_c *)::cXyz::Zero.y;
    *(float *)this->mEvRelUseMask = ::cXyz::Zero.z;
    *(undefined4 *)&this->field_0x388 = 0;
    *(undefined4 *)&this->field_0x384 = *(undefined4 *)&this->field_0x7c;
    if ((((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4] & 0x1000000U) == 0)
       && (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5ccc)[this->mPadId * 4] & 2U) == 0)) {
      if (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5ccc)[this->mPadId * 4] & 0x80U) == 0) {
        if (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4] & 0x1010000U) == 0
           ) {
          *(undefined4 *)&this->field_0x37c = 0;
        }
        else {
          this->mEvTimer = (int)(this->field_0x44).x;
          *(float *)&this->field_0x3a8 = (this->field_0x44).y;
          (this->mEvBasePos).x = (this->field_0x44).z;
          local_3f8[0] = 0xa7;
          pfVar3 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeForPName,local_3f8);
          *(fopAc_ac_c **)&this->field_0x37c = pfVar3;
        }
      }
      else {
        this->mEvTimer = (int)(this->field_0x44).x;
        *(float *)&this->field_0x3a8 = (this->field_0x44).y;
        (this->mEvBasePos).x = (this->field_0x44).z;
        local_3ec[0] = 0xa7;
        pfVar3 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeForPName,local_3ec);
        *(fopAc_ac_c **)&this->field_0x37c = pfVar3;
        if (d_camera::init_13500 == '\0') {
          local_1a0 = d_camera::_13450;
          local_19c = (undefined *)d_camera::_9008;
          local_198 = d_camera::_10813;
          d_camera::p_13498 = d_camera::_13450;
          DAT_803e4940 = d_camera::_9008;
          DAT_803e4944 = d_camera::_10813;
          Runtime.PPCEABI.H::__register_global_object
                    (&d_camera::p_13498,::cXyz::_cXyz,&d_camera::_13499);
          local_1ac = (undefined *)d_camera::_13450;
          local_1a8 = d_camera::_9008;
          local_1a4 = d_camera::_10813;
          DAT_803e4948 = d_camera::_13450;
          DAT_803e494c = d_camera::_9008;
          DAT_803e4950 = d_camera::_10813;
          Runtime.PPCEABI.H::__register_global_object(&DAT_803e4948,::cXyz::_cXyz,&d_camera::_13502)
          ;
          d_camera::init_13500 = '\x01';
        }
        cSGlobe::cSGlobe(&cStack776,
                         (cXyz *)(&d_camera::p_13498 + (*(uint *)&this->field_0x7c & 1) * 3));
        sVar6 = SComponent::cLib_targetAngleY
                          (&(this->mpPlayerActor->mCurrent).mPos,
                           (cXyz *)(*(int *)&this->field_0x37c + 0x1f8));
        cSAngle::cSAngle(acStack824,sVar6);
        cSAngle::operator__(local_370,acStack824);
        if ((((int)local_370[0] >> 0x1f) +
             ((uint)((uint)(int)cSAngle::_0 <= (uint)(int)local_370[0]) - ((int)cSAngle::_0 >> 0x1f)
             ) & 0xff) == 0) {
          cSAngle::operator__(local_378,local_330);
          cSAngle::cSAngle(local_3f4,local_378[0]);
          cStack776.mAngleY = local_3f4[0];
        }
        else {
          cSAngle::operator__(local_374,local_330);
          cSAngle::cSAngle(local_3f0,local_374[0]);
          cStack776.mAngleY = local_3f0[0];
        }
        positionOf(&cStack440,this,*(fopAc_ac_c **)&this->field_0x37c);
        cSGlobe::Xyz(&cStack452,&cStack776);
        ::cXyz::operator__(&local_1d0,&cStack440,&cStack452);
        *(float *)&this->field_0x38c = local_1d0.x;
        *(float *)&this->field_0x390 = local_1d0.y;
        this->mEvFovy = local_1d0.z;
        cVar7 = lineBGCheck(this,(cXyz *)&this->field_0x38c,&(this->mpPlayerActor->mCurrent).mPos,
                            0x7f);
        if (cVar7 == '\0') {
          *(undefined4 *)&this->field_0x388 = 1;
        }
      }
    }
    else {
      this->mEvTimer = (int)(this->field_0x44).x;
      *(float *)&this->field_0x3a8 = (this->field_0x44).y;
      (this->mEvBasePos).x = (this->field_0x44).z;
      local_3e0 = 0xa7;
      pfVar3 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeForPName,&local_3e0);
      *(fopAc_ac_c **)&this->field_0x37c = pfVar3;
      if (d_camera::init_13484 == '\0') {
        local_164 = d_camera::_13450;
        local_160 = d_camera::_5573;
        local_15c = d_camera::_10813;
        d_camera::p_13482 = d_camera::_13450;
        DAT_803e4910 = d_camera::_5573;
        DAT_803e4914 = d_camera::_10813;
        Runtime.PPCEABI.H::__register_global_object
                  (&d_camera::p_13482,::cXyz::_cXyz,&d_camera::_13483);
        local_170 = d_camera::240_0;
        local_16c = d_camera::_6117;
        local_168 = d_camera::_11362;
        DAT_803e4918 = d_camera::240_0;
        DAT_803e491c = d_camera::_6117;
        DAT_803e4920 = d_camera::_11362;
        Runtime.PPCEABI.H::__register_global_object(&DAT_803e4918,::cXyz::_cXyz,&d_camera::_13486);
        d_camera::init_13484 = '\x01';
      }
      cSGlobe::cSGlobe(&cStack768,
                       (cXyz *)(&d_camera::p_13482 + (*(uint *)&this->field_0x7c & 1) * 3));
      sVar6 = SComponent::cLib_targetAngleY
                        (&(this->mpPlayerActor->mCurrent).mPos,
                         (cXyz *)(*(int *)&this->field_0x37c + 0x1f8));
      cSAngle::cSAngle(acStack820,sVar6);
      cSAngle::operator__(local_364,acStack820);
      if ((((int)local_364[0] >> 0x1f) +
           ((uint)((uint)(int)cSAngle::_0 <= (uint)(int)local_364[0]) - ((int)cSAngle::_0 >> 0x1f))
          & 0xff) == 0) {
        cSAngle::operator__(local_36c,local_330);
        cSAngle::cSAngle(local_3e8,local_36c[0]);
        cStack768.mAngleY = local_3e8[0];
      }
      else {
        cSAngle::operator__(local_368,local_330);
        cSAngle::cSAngle(local_3e4,local_368[0]);
        cStack768.mAngleY = local_3e4[0];
      }
      positionOf(&cStack380,this,*(fopAc_ac_c **)&this->field_0x37c);
      cSGlobe::Xyz(&cStack392,&cStack768);
      ::cXyz::operator__(&local_194,&cStack380,&cStack392);
      *(float *)&this->field_0x38c = local_194.x;
      *(float *)&this->field_0x390 = local_194.y;
      this->mEvFovy = local_194.z;
      cVar7 = lineBGCheck(this,(cXyz *)&this->field_0x38c,&(this->mpPlayerActor->mCurrent).mPos,0x7f
                         );
      if (cVar7 == '\0') {
        *(undefined4 *)&this->field_0x388 = 1;
      }
    }
    ::cXyz::operator__(&cStack476,&this->field_0x50,&this->field_0x44);
    cSGlobe::Val(&this->field_0x3c,&cStack476);
    if ((this->mEventFlags & 0x8000) != 0) {
      *(undefined4 *)&this->field_0x388 = 2;
    }
  }
  if (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4] & 0x1010000U) == 0) {
    *(undefined4 *)&this->field_0x37c = 0;
  }
  dVar19 = (double)(float)(dVar20 + (double)(float)(dVar10 * (double)(float)(dVar19 * dVar10)));
  dVar12 = (double)(float)(dVar18 + (double)(float)(dVar10 * (double)(float)(dVar17 * dVar10)));
  dVar11 = (double)(float)(dVar14 + (double)(float)(dVar13 * dVar10));
  iVar8 = *(int *)&this->field_0x37c;
  if (iVar8 == 0) {
    directionOf((dCamera_c *)acStack892,(fopAc_ac_c *)this);
    sVar6 = cSAngle::Inv(acStack892);
    local_110 = (double)(longlong)(int)((double)d_camera::_8358 * dVar12);
    cSGlobe::Val(&local_310,(float)dVar19,(short)(int)((double)d_camera::_8358 * dVar12),sVar6);
  }
  else {
    if (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5ccc)[this->mPadId * 4] & 2U) == 0) {
      cSAngle::Val(acStack828,*(short *)(iVar8 + 0x364));
    }
    else {
      cSAngle::Val(acStack828,*(short *)(iVar8 + 0x398));
      dVar10 = (double)d_camera::1_0;
    }
    dVar13 = (double)cSAngle::Sin(acStack828);
    local_11c.x = local_11c.x - (float)(dVar10 * (double)(float)(dVar24 * dVar13));
    local_11c.y = local_11c.y + (float)(dVar23 * dVar10);
    dVar13 = (double)dCamMath::rationalBezierRatio(this->mStickCPosXLast,d_camera::1_0);
    dVar14 = (double)d_camera::0_0;
    if (dVar14 <= (double)this->mStickCPosYLast) {
      dVar14 = (double)dCamMath::rationalBezierRatio(this->mStickCPosYLast,d_camera::1_0);
    }
    fVar1 = d_camera::0_25;
    this->mEvBank =
         this->mEvBank +
         d_camera::0_25 * ((float)(dVar13 * (double)d_camera::_14078) - this->mEvBank);
    this->mpEvRelActor =
         (fopAc_ac_c *)
         ((float)this->mpEvRelActor +
         fVar1 * ((float)(dVar14 * (double)d_camera::_14079) - (float)this->mpEvRelActor));
    local_11c.x = local_11c.x + this->mEvBank;
    local_11c.y = local_11c.y + (float)this->mpEvRelActor;
    if ((dCamParam_c::styles[param_1].mFlag & 4) != 0) {
      cSGlobe::cSGlobe(&cStack792,d_camera::_5129,&cSAngle::_0,local_330);
      positionOf(&cStack488,this,*(fopAc_ac_c **)&this->field_0x37c);
      cSGlobe::Xyz(&cStack500,&cStack792);
      ::cXyz::operator__(&local_200,&cStack488,&cStack500);
      local_128.x = local_200.x;
      local_128.y = local_200.y;
      local_128.z = local_200.z;
      uVar4 = d_a_sea::daSea_ChkArea(local_200.x,local_200.z);
      if ((uVar4 & 0xff) != 0) {
        dVar13 = (double)d_a_sea::daSea_calcWave((double)local_128.x,(double)local_128.z);
        local_128.y = (float)dVar13;
        positionOf(&cStack524,this,*(fopAc_ac_c **)&this->field_0x37c);
        ::cXyz::operator__(&cStack536,&local_128,&cStack524);
        cSGlobe::Val(&cStack792,&cStack536);
        dVar13 = (double)cSAngle::Degree(&cStack792.mAngleX);
        dVar12 = (double)(float)(dVar12 + (double)(d_camera::_13048 * (float)(dVar10 * dVar13)));
      }
    }
    sVar6 = cSAngle::Inv(local_330);
    local_110 = (double)(longlong)(int)((double)d_camera::_8358 * dVar12);
    cSGlobe::Val(&local_310,(float)dVar19,(short)(int)((double)d_camera::_8358 * dVar12),sVar6);
  }
  relationalPos(&local_224,this,this->mpPlayerActor,&local_11c);
  this->mEvTimer = (int)local_224.x;
  *(float *)&this->field_0x3a8 = local_224.y;
  (this->mEvBasePos).x = local_224.z;
  if (*(char *)&this->field_0x100 == '\0') {
    iVar8 = *(int *)&this->field_0x388;
    if (iVar8 == 2) {
      iVar8 = 8;
      local_110 = (double)CONCAT44(0x43300000,8U - this->field_0x11c ^ 0x80000000);
      dVar10 = (double)(d_camera::1_0 / (float)(local_110 - d_camera::_5738));
      ::cXyz::operator__(&cStack596,(cXyz *)&this->mEvTimer,&this->field_0x44);
      local_260 = (float)dVar22;
      local_25c = (float)dVar21;
      local_258 = (float)dVar22;
      ::cXyz::operator_(&cStack620,(Vec *)&cStack596);
      mtx::PSVECAdd(&this->field_0x44,&cStack620,&this->field_0x44);
      cSAngle::operator__(acStack896,&local_310.mAngleY);
      cSAngle::operator_(acStack900,(float)dVar10);
      cSAngle::operator__(local_388,&(this->field_0x3c).mAngleY);
      cSAngle::cSAngle(local_3fc,local_388[0]);
      (this->field_0x3c).mAngleY.v = local_3fc[0];
      cSGlobe::Xyz(&cStack632,&this->field_0x3c);
      ::cXyz::operator__(&local_284,&this->field_0x44,&cStack632);
      (this->field_0x50).x = local_284.x;
      (this->field_0x50).y = local_284.y;
      (this->field_0x50).z = local_284.z;
    }
    else {
      if ((iVar8 < 2) && (0 < iVar8)) {
        iVar8 = 0x28;
        local_110 = (double)CONCAT44(0x43300000,0x28U - this->field_0x11c ^ 0x80000000);
        dVar10 = (double)(d_camera::1_0 / (float)(local_110 - d_camera::_5738));
        ::cXyz::operator__(&cStack560,(cXyz *)&this->mEvTimer,&this->field_0x44);
        ::cXyz::operator_(&cStack572,&cStack560,(float)dVar10);
        mtx::PSVECAdd(&this->field_0x44,&cStack572,&this->field_0x44);
        (this->field_0x50).x = *(float *)&this->field_0x38c;
        (this->field_0x50).y = *(float *)&this->field_0x390;
        (this->field_0x50).z = this->mEvFovy;
        ::cXyz::operator__(&cStack584,&this->field_0x50,&this->field_0x44);
        cSGlobe::Val(&this->field_0x3c,&cStack584);
      }
      else {
        iVar8 = 0x14;
        local_110 = (double)CONCAT44(0x43300000,0x14U - this->field_0x11c ^ 0x80000000);
        dVar10 = (double)(d_camera::1_0 / (float)(local_110 - d_camera::_5738));
        ::cXyz::operator__(&cStack656,(cXyz *)&this->mEvTimer,&this->field_0x44);
        ::cXyz::operator_(&cStack668,&cStack656,(float)dVar10);
        mtx::PSVECAdd(&this->field_0x44,&cStack668,&this->field_0x44);
        fVar1 = (this->field_0x3c).mDistance;
        (this->field_0x3c).mDistance =
             fVar1 + (float)(dVar10 * (double)(local_310.mDistance - fVar1));
        cSAngle::operator__(acStack908,&local_310.mAngleX);
        cSAngle::operator_(acStack912,(float)dVar10);
        cSAngle::operator__(local_394,&(this->field_0x3c).mAngleX);
        cSAngle::cSAngle(local_400,local_394[0]);
        (this->field_0x3c).mAngleX.v = local_400[0];
        cSAngle::operator__(acStack920,&local_310.mAngleY);
        cSAngle::operator_(acStack924,(float)dVar10);
        cSAngle::operator__(local_3a0,&(this->field_0x3c).mAngleY);
        cSAngle::cSAngle(local_404,local_3a0[0]);
        (this->field_0x3c).mAngleY.v = local_404[0];
        cSGlobe::Xyz(&cStack680,&this->field_0x3c);
        ::cXyz::operator__(&local_2b4,&this->field_0x44,&cStack680);
        (this->field_0x50).x = local_2b4.x;
        (this->field_0x50).y = local_2b4.y;
        (this->field_0x50).z = local_2b4.z;
      }
    }
    this->field_0x60 =
         (float)((double)this->field_0x60 +
                (double)(float)(dVar10 * (double)(float)(dVar11 - (double)this->field_0x60)));
    if (this->field_0x11c == iVar8 + -1) {
      *(undefined *)&this->field_0x102 = 1;
      *(undefined *)&this->field_0x101 = 1;
      *(undefined *)&this->field_0x100 = 1;
    }
  }
  else {
    local_134 = (float)dVar22;
    local_130 = (float)dVar21;
    local_12c = (float)dVar22;
    ::cXyz::operator__(&cStack704,(cXyz *)&this->mEvTimer,&this->field_0x44);
    ::cXyz::operator_(&cStack716,(Vec *)&cStack704);
    mtx::PSVECAdd(&this->field_0x44,&cStack716,&this->field_0x44);
    fVar1 = (this->field_0x3c).mDistance;
    dVar12 = (double)(fVar1 + (float)(dVar15 * (double)(local_310.mDistance - fVar1)));
    directionOf((dCamera_c *)acStack932,(fopAc_ac_c *)this);
    uVar5 = cSAngle::Inv(acStack932);
    pcVar2 = &(this->field_0x3c).mAngleY;
    SComponent::operator__(acStack936,uVar5,pcVar2);
    cSAngle::cSAngle(acStack832,acStack936);
    cSAngle::operator__(acStack940,&local_310.mAngleY);
    cSAngle::operator_(acStack944,(float)dVar16);
    cSAngle::operator__(acStack948,pcVar2);
    cSAngle::cSAngle(acStack836,acStack948);
    ::cXyz::operator__(&cStack728,&this->field_0x50,&this->field_0x44);
    cSGlobe::cSGlobe(&cStack800,&cStack728);
    dVar13 = (double)d_camera::1_0;
    if ((dCamParam_c::styles[param_1].mFlag & 4) != 0) {
      if ((double)d_camera::_6431 < dVar10) {
        dVar13 = (double)d_camera::0_0;
      }
      else {
        dVar13 = (double)(d_camera::_9007 * (float)((double)d_camera::_6431 - dVar10));
      }
    }
    cSAngle::operator__(acStack952,&cStack800.mAngleX);
    cSAngle::operator_(acStack956,(float)((double)d_camera::0_25 * dVar13));
    cSAngle::operator__(local_3c0,&local_310.mAngleX);
    cSAngle::cSAngle(local_408,local_3c0[0]);
    local_310.mAngleX = local_408[0];
    cSAngle::operator__(acStack964,&local_310.mAngleX);
    cSAngle::operator_(acStack968,(float)dVar15);
    cSAngle::operator__(acStack972,&(this->field_0x3c).mAngleX);
    cSAngle::cSAngle(local_348,acStack972);
    if (local_348[0] < local_324[0]) {
      cSAngle::Val(local_348,local_324);
    }
    else {
      if (local_328[0] < local_348[0]) {
        cSAngle::Val(local_348,local_328);
      }
    }
    cSGlobe::Val(&this->field_0x3c,(float)dVar12,local_348,acStack836);
    cSGlobe::Xyz(&cStack740,&this->field_0x3c);
    ::cXyz::operator__(&local_2f0,&this->field_0x44,&cStack740);
    (this->field_0x50).x = local_2f0.x;
    (this->field_0x50).y = local_2f0.y;
    (this->field_0x50).z = local_2f0.z;
    this->field_0x60 =
         (float)((double)this->field_0x60 +
                (double)(float)(dVar15 * (double)(float)(dVar11 - (double)this->field_0x60)));
    cSAngle::operator_(acStack976,this->mStickMainPosXLast);
    cSAngle::operator__(acStack980,acStack976);
    cSAngle::operator_(acStack984,d_camera::_6065 * (float)ABS(dVar10));
    cSAngle::operator___((cSAngle *)&this->field_0x5c,acStack984);
    this->mEventFlags = this->mEventFlags | 0x400;
  }
  __psq_l0(auStack8,uVar9);
  __psq_l1(auStack8,uVar9);
  __psq_l0(auStack24,uVar9);
  __psq_l1(auStack24,uVar9);
  __psq_l0(auStack40,uVar9);
  __psq_l1(auStack40,uVar9);
  __psq_l0(auStack56,uVar9);
  __psq_l1(auStack56,uVar9);
  __psq_l0(auStack72,uVar9);
  __psq_l1(auStack72,uVar9);
  __psq_l0(auStack88,uVar9);
  __psq_l1(auStack88,uVar9);
  __psq_l0(auStack104,uVar9);
  __psq_l1(auStack104,uVar9);
  __psq_l0(auStack120,uVar9);
  __psq_l1(auStack120,uVar9);
  __psq_l0(auStack136,uVar9);
  __psq_l1(auStack136,uVar9);
  __psq_l0(auStack152,uVar9);
  __psq_l1(auStack152,uVar9);
  __psq_l0(auStack168,uVar9);
  __psq_l1(auStack168,uVar9);
  __psq_l0(auStack184,uVar9);
  __psq_l1(auStack184,uVar9);
  __psq_l0(auStack200,uVar9);
  __psq_l1(auStack200,uVar9);
  __psq_l0(auStack216,uVar9);
  __psq_l1(auStack216,uVar9);
  __psq_l0(auStack232,uVar9);
  __psq_l1(auStack232,uVar9);
  return 1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x80176214) */
/* WARNING: Removing unreachable block (ram,0x80176204) */
/* WARNING: Removing unreachable block (ram,0x801761f4) */
/* WARNING: Removing unreachable block (ram,0x801761e4) */
/* WARNING: Removing unreachable block (ram,0x801761d4) */
/* WARNING: Removing unreachable block (ram,0x801761c4) */
/* WARNING: Removing unreachable block (ram,0x801761b4) */
/* WARNING: Removing unreachable block (ram,0x801761a4) */
/* WARNING: Removing unreachable block (ram,0x801761ac) */
/* WARNING: Removing unreachable block (ram,0x801761bc) */
/* WARNING: Removing unreachable block (ram,0x801761cc) */
/* WARNING: Removing unreachable block (ram,0x801761dc) */
/* WARNING: Removing unreachable block (ram,0x801761ec) */
/* WARNING: Removing unreachable block (ram,0x801761fc) */
/* WARNING: Removing unreachable block (ram,0x8017620c) */
/* WARNING: Removing unreachable block (ram,0x8017621c) */
/* __thiscall dCamera_c::rideCamera(long) */

undefined4 __thiscall dCamera_c::rideCamera(dCamera_c *this,long param_1)

{
  float fVar1;
  int iVar2;
  fopAc_ac_c *pfVar3;
  short sVar6;
  char cVar7;
  uint uVar4;
  undefined4 uVar5;
  fopAc_ac_c *in_r5;
  cSAngle *pcVar8;
  undefined4 uVar9;
  undefined8 in_f16;
  double dVar10;
  undefined8 in_f17;
  double dVar11;
  double in_f18;
  undefined8 in_f19;
  double dVar12;
  undefined8 in_f20;
  double dVar13;
  undefined8 in_f21;
  double dVar14;
  undefined8 in_f22;
  double dVar15;
  undefined8 in_f23;
  double dVar16;
  undefined8 in_f24;
  double dVar17;
  undefined8 in_f25;
  double dVar18;
  undefined8 in_f26;
  double dVar19;
  undefined8 in_f27;
  double dVar20;
  undefined8 in_f28;
  double dVar21;
  undefined8 in_f29;
  double dVar22;
  undefined8 in_f30;
  double dVar23;
  undefined8 in_f31;
  double dVar24;
  undefined2 local_3f8;
  undefined2 local_3f6;
  undefined2 local_3f4;
  undefined2 local_3f2;
  undefined2 local_3f0 [2];
  cSAngle acStack1004 [2];
  cSAngle acStack1000 [2];
  cSAngle acStack996 [2];
  cSAngle acStack992 [2];
  cSAngle acStack988 [2];
  cSAngle acStack984 [2];
  cSAngle acStack980 [2];
  cSAngle acStack976 [2];
  cSAngle acStack972 [2];
  cSAngle acStack968 [2];
  cSAngle acStack964 [2];
  cSAngle acStack960 [2];
  cSAngle acStack956 [2];
  cSAngle acStack952 [2];
  cSAngle acStack948 [2];
  cSAngle acStack944 [2];
  cSAngle acStack940 [2];
  cSAngle acStack936 [2];
  cSAngle acStack932 [2];
  cSAngle acStack928 [2];
  cSAngle acStack924 [2];
  cSAngle acStack920 [2];
  cSAngle acStack916 [2];
  cSAngle acStack912 [2];
  cSAngle acStack908 [2];
  cSAngle acStack904 [2];
  cSAngle local_384 [2];
  cSAngle acStack896 [2];
  cSAngle acStack892 [2];
  cSAngle local_378 [2];
  cSAngle acStack884 [2];
  cSAngle acStack880 [2];
  cSAngle local_36c [2];
  cSAngle local_368 [2];
  cSAngle acStack868 [2];
  cSAngle local_360 [2];
  cSAngle local_35c [2];
  cSAngle acStack856 [2];
  cSAngle acStack852 [2];
  cSAngle acStack848 [2];
  cSAngle acStack844 [2];
  cSAngle acStack840 [2];
  cSAngle local_344 [2];
  cSAngle local_340 [2];
  cSAngle acStack828 [2];
  cSAngle local_338 [2];
  cSAngle local_334 [2];
  cSGlobe cStack816;
  cSGlobe cStack808;
  cSGlobe local_320;
  cSGlobe cStack792;
  cSGlobe cStack784;
  cXyz cStack776;
  cXyz cStack764;
  cXyz cStack752;
  cXyz cStack740;
  cXyz cStack728;
  cXyz cStack716;
  cXyz cStack704;
  cXyz cStack692;
  cXyz cStack680;
  cXyz cStack668;
  cXyz cStack656;
  cXyz cStack644;
  cXyz cStack632;
  cXyz cStack620;
  cXyz cStack608;
  cXyz cStack596;
  cXyz cStack584;
  cXyz cStack572;
  cXyz cStack560;
  cXyz cStack548;
  cXyz local_218;
  cXyz cStack524;
  cXyz cStack512;
  cXyz cStack500;
  cXyz cStack488;
  cXyz cStack476;
  cXyz local_1d0;
  cXyz local_1c4;
  cXyz local_1b8;
  cXyz local_1ac;
  cXyz cStack416;
  cXyz cStack404;
  cXyz cStack392;
  cXyz cStack380;
  cXyz local_170;
  cXyz local_164;
  cXyz local_158;
  cXyz local_14c;
  float local_140;
  float local_13c;
  float local_138;
  cXyz local_134;
  cXyz local_128;
  double local_118;
  undefined auStack248 [16];
  undefined auStack232 [16];
  undefined auStack216 [16];
  undefined auStack200 [16];
  undefined auStack184 [16];
  undefined auStack168 [16];
  undefined auStack152 [16];
  undefined auStack136 [16];
  undefined auStack120 [16];
  undefined auStack104 [16];
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar9 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  __psq_st0(auStack72,(int)((ulonglong)in_f27 >> 0x20),0);
  __psq_st1(auStack72,(int)in_f27,0);
  __psq_st0(auStack88,(int)((ulonglong)in_f26 >> 0x20),0);
  __psq_st1(auStack88,(int)in_f26,0);
  __psq_st0(auStack104,(int)((ulonglong)in_f25 >> 0x20),0);
  __psq_st1(auStack104,(int)in_f25,0);
  __psq_st0(auStack120,(int)((ulonglong)in_f24 >> 0x20),0);
  __psq_st1(auStack120,(int)in_f24,0);
  __psq_st0(auStack136,(int)((ulonglong)in_f23 >> 0x20),0);
  __psq_st1(auStack136,(int)in_f23,0);
  __psq_st0(auStack152,(int)((ulonglong)in_f22 >> 0x20),0);
  __psq_st1(auStack152,(int)in_f22,0);
  __psq_st0(auStack168,(int)((ulonglong)in_f21 >> 0x20),0);
  __psq_st1(auStack168,(int)in_f21,0);
  __psq_st0(auStack184,(int)((ulonglong)in_f20 >> 0x20),0);
  __psq_st1(auStack184,(int)in_f20,0);
  __psq_st0(auStack200,(int)((ulonglong)in_f19 >> 0x20),0);
  __psq_st1(auStack200,(int)in_f19,0);
  __psq_st0(auStack216,(int)((ulonglong)in_f18 >> 0x20),0);
  __psq_st1(auStack216,SUB84(in_f18,0),0);
  __psq_st0(auStack232,(int)((ulonglong)in_f17 >> 0x20),0);
  __psq_st1(auStack232,(int)in_f17,0);
  __psq_st0(auStack248,(int)((ulonglong)in_f16 >> 0x20),0);
  __psq_st1(auStack248,(int)in_f16,0);
  dVar11 = (double)dCamParam_c::styles[param_1].mCenterHeightBase;
  dVar10 = (double)dCamParam_c::styles[param_1].field_0x8;
  dVar24 = (double)dCamParam_c::styles[param_1].field_0xc;
  dVar23 = (double)dCamParam_c::styles[param_1].mLockonCenterHeightMin;
  dVar22 = (double)dCamParam_c::styles[param_1].field_0x14;
  dVar21 = (double)dCamParam_c::styles[param_1].field_0x18;
  dVar20 = (double)dCamParam_c::styles[param_1].field_0x30;
  dVar19 = (double)dCamParam_c::styles[param_1].field_0x3c;
  dVar18 = (double)dCamParam_c::styles[param_1].field_0x40;
  dVar17 = (double)dCamParam_c::styles[param_1].field_0x44;
  dVar16 = (double)dCamParam_c::styles[param_1].mLockonLatitudeMin;
  cSAngle::cSAngle(local_334,*(float *)&dCamParam_c::styles[param_1].field_0x48);
  cSAngle::cSAngle(local_338,*(float *)&dCamParam_c::styles[param_1].field_0x4c);
  dVar12 = (double)*(float *)&dCamParam_c::styles[param_1].field_0x58;
  dVar15 = (double)*(float *)&dCamParam_c::styles[param_1].field_0x5c;
  dVar14 = (double)dCamParam_c::styles[param_1].mFovyBase;
  dVar13 = (double)dCamParam_c::styles[param_1].mLockonFovyMin;
  cSAngle::cSAngle(acStack828,dCamParam_c::styles[param_1].mLockonFovyMax);
  if ((this->mEventFlags & 0x100000) != 0) {
    dVar12 = (double)d_camera::1_0;
  }
  local_128.x = d_camera::0_0;
  local_128.y = (float)dVar11;
  local_128.z = (float)dVar10;
  if (this->field_0x11c == 0) {
    *(undefined *)&this->field_0x384 = 0;
  }
  iVar2 = @unnamed@d_camera_cpp@::check_owner_action1
                    ((_unnamed_d_camera_cpp_ *)this->mPadId,4,(ulong)in_r5);
  if (iVar2 == 0) {
    iVar2 = @unnamed@d_camera_cpp@::check_owner_action
                      ((_unnamed_d_camera_cpp_ *)this->mPadId,0x1010000,(ulong)in_r5);
    if (((iVar2 == 0) &&
        (iVar2 = @unnamed@d_camera_cpp@::check_owner_action1
                           ((_unnamed_d_camera_cpp_ *)this->mPadId,0x80,(ulong)in_r5), iVar2 == 0))
       && (iVar2 = @unnamed@d_camera_cpp@::check_owner_action1
                             ((_unnamed_d_camera_cpp_ *)this->mPadId,2,(ulong)in_r5), iVar2 == 0)) {
      in_r5 = this->mpPlayerActor;
      directionOf((dCamera_c *)acStack884,(fopAc_ac_c *)this);
      cSAngle::Val((cSAngle *)&(this->mEvBasePos).y,acStack884);
      *(undefined4 *)&this->field_0x37c = 0;
    }
    else {
      local_3f2 = 0xa7;
      pfVar3 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeForPName,&local_3f2);
      *(fopAc_ac_c **)&this->field_0x37c = pfVar3;
      in_r5 = this->mpPlayerActor;
      directionOf((dCamera_c *)acStack880,(fopAc_ac_c *)this);
      cSAngle::Val((cSAngle *)&(this->mEvBasePos).y,acStack880);
    }
  }
  else {
    local_3f0[0] = 0xa7;
    pfVar3 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeForPName,local_3f0);
    *(fopAc_ac_c **)&this->field_0x37c = pfVar3;
    cSAngle::cSAngle(local_340,
                     *(short *)(*(int *)&this->field_0x37c + 0x20e) +
                     *(short *)(*(int *)&this->field_0x37c + 0x394));
    if (this->field_0x11c == 0) {
      local_344[0] = cSAngle::_0;
    }
    else {
      in_r5 = (fopAc_ac_c *)local_340;
      cSAngle::operator__(acStack868,(cSAngle *)&(this->mEvBasePos).y);
      cSAngle::Val(local_344,acStack868);
    }
    cSAngle::cSAngle(local_368,d_camera::_1_0);
    if (((int)(short)(local_368[0] ^ local_344[0]) >> 1) -
        (int)(short)((local_368[0] ^ local_344[0]) & local_368[0]) < 0) {
      *(undefined *)&this->field_0x384 = 1;
    }
    cSAngle::cSAngle(local_36c,d_camera::1_0);
    if (((int)(short)(local_344[0] ^ local_36c[0]) >> 1) -
        (int)(short)((local_344[0] ^ local_36c[0]) & local_344[0]) < 0) {
      *(undefined *)&this->field_0x384 = 0;
    }
    *(short *)&(this->mEvBasePos).y = local_340[0];
  }
  if (this->field_0x11c == 0) {
    *(undefined4 *)&this->field_0x378 = 0x52494445;
    ::cXyz::operator__((cXyz *)&this->mEvBank,&::cXyz::Zero);
    *(undefined4 *)&this->field_0x388 = 0;
    *(undefined4 *)&this->field_0x380 = *(undefined4 *)&this->field_0x7c;
    *(undefined *)&this->field_0x385 = 1;
    fVar1 = d_camera::0_0;
    *(float *)&this->field_0x3c4 = d_camera::0_0;
    (this->mEvBasePos).z = (this->field_0x3c).mDistance;
    *(float *)&this->field_0x3b8 = fVar1;
    dVar10 = (double)cSAngle::Degree(&(this->field_0x3c).mAngleX);
    *(float *)&this->field_0x3bc = (float)dVar10;
    *(float *)&this->field_0x3c0 = d_camera::0_0;
    *(float *)&this->field_0x3c8 = d_camera::_9011;
    *(undefined4 *)&this->field_0x37c = 0;
    iVar2 = @unnamed@d_camera_cpp@::check_owner_action
                      ((_unnamed_d_camera_cpp_ *)this->mPadId,0x1000000,(ulong)in_r5);
    if (iVar2 == 0) {
      iVar2 = @unnamed@d_camera_cpp@::check_owner_action1
                        ((_unnamed_d_camera_cpp_ *)this->mPadId,0x80,(ulong)in_r5);
      if (iVar2 == 0) {
        iVar2 = @unnamed@d_camera_cpp@::check_owner_action
                          ((_unnamed_d_camera_cpp_ *)this->mPadId,0x1010000,(ulong)in_r5);
        if ((iVar2 == 0) &&
           (iVar2 = @unnamed@d_camera_cpp@::check_owner_action1
                              ((_unnamed_d_camera_cpp_ *)this->mPadId,2,(ulong)in_r5), iVar2 == 0))
        {
          ::cXyz::operator__((cXyz *)&this->mEvTimer,&this->field_0x44);
          *(undefined4 *)&this->field_0x37c = 0;
          ::cXyz::operator__((cXyz *)&this->field_0x38c,&this->field_0x44);
        }
        else {
          ::cXyz::operator__((cXyz *)&this->mEvTimer,&this->field_0x44);
          local_3f8 = 0xa7;
          pfVar3 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeForPName,&local_3f8);
          *(fopAc_ac_c **)&this->field_0x37c = pfVar3;
          ::cXyz::operator__((cXyz *)&this->field_0x38c,&this->field_0x44);
        }
      }
      else {
        local_3f6 = 0xa7;
        pfVar3 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeForPName,&local_3f6);
        *(fopAc_ac_c **)&this->field_0x37c = pfVar3;
        ::cXyz::operator__((cXyz *)&this->mEvTimer,&this->field_0x44);
        if (d_camera::init_14145 == '\0') {
          local_1ac.x = d_camera::320_0;
          local_1ac.y = d_camera::_5129;
          local_1ac.z = d_camera::_14644;
          ::cXyz::cXyz((cXyz *)&d_camera::p_14143,&local_1ac);
          Runtime.PPCEABI.H::__register_global_object();
          local_1b8.x = d_camera::320_0;
          local_1b8.y = d_camera::_5129;
          local_1b8.z = d_camera::_13450;
          ::cXyz::cXyz((cXyz *)&DAT_803e49f0,&local_1b8);
          Runtime.PPCEABI.H::__register_global_object();
          local_1c4.x = d_camera::320_0;
          local_1c4.y = d_camera::_10130;
          local_1c4.z = d_camera::_14644;
          ::cXyz::cXyz((cXyz *)&DAT_803e49fc,&local_1c4);
          Runtime.PPCEABI.H::__register_global_object();
          local_1d0.x = d_camera::_14645;
          local_1d0.y = d_camera::_14646;
          local_1d0.z = d_camera::_14647;
          ::cXyz::cXyz((cXyz *)&DAT_803e4a08,&local_1d0);
          Runtime.PPCEABI.H::__register_global_object();
          d_camera::init_14145 = '\x01';
        }
        cSGlobe::cSGlobe(&cStack792,
                         (cXyz *)(&d_camera::p_14143 + (*(uint *)&this->field_0x7c & 3) * 0xc));
        sVar6 = SComponent::cLib_targetAngleY
                          (&(this->mpPlayerActor->mCurrent).mPos,
                           (cXyz *)(*(int *)&this->field_0x37c + 0x1f8));
        cSAngle::cSAngle(acStack844,sVar6);
        cSAngle::operator__(local_384,acStack844);
        if ((((int)local_384[0] >> 0x1f) +
             ((uint)((uint)(int)cSAngle::_0 <= (uint)(int)local_384[0]) - ((int)cSAngle::_0 >> 0x1f)
             ) & 0xff) == 0) {
          cSAngle::operator__(acStack908,(cSAngle *)&(this->mEvBasePos).y);
          cSGlobe::U(&cStack792,acStack908);
        }
        else {
          cSAngle::operator__(acStack904,(cSAngle *)&(this->mEvBasePos).y);
          cSGlobe::U(&cStack792,acStack904);
        }
        positionOf(&cStack476,this,*(fopAc_ac_c **)&this->field_0x37c);
        ::cXyz::operator__(&this->field_0x44,&cStack476);
        positionOf(&cStack488,this,*(fopAc_ac_c **)&this->field_0x37c);
        cSGlobe::Xyz(&cStack500,&cStack792);
        ::cXyz::operator__(&cStack512,&cStack488,&cStack500);
        ::cXyz::operator__((cXyz *)&this->field_0x38c,&cStack512);
        cVar7 = lineBGCheck(this,(cXyz *)&this->field_0x38c,&(this->mpPlayerActor->mCurrent).mPos,
                            0x7f);
        if (cVar7 == '\0') {
          *(undefined4 *)&this->field_0x388 = 1;
        }
        cSGlobe::_cSGlobe(&cStack792);
      }
    }
    else {
      local_3f4 = 0xa7;
      pfVar3 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeForPName,&local_3f4);
      *(fopAc_ac_c **)&this->field_0x37c = pfVar3;
      ::cXyz::operator__((cXyz *)&this->mEvTimer,&this->field_0x44);
      if (d_camera::init_14130 == '\0') {
        local_14c.x = d_camera::_13450;
        local_14c.y = d_camera::_5573;
        local_14c.z = d_camera::_10813;
        ::cXyz::cXyz((cXyz *)&d_camera::p_14128,&local_14c);
        Runtime.PPCEABI.H::__register_global_object();
        local_158.x = d_camera::240_0;
        local_158.y = d_camera::_6117;
        local_158.z = d_camera::_11362;
        ::cXyz::cXyz((cXyz *)&DAT_803e4990,&local_158);
        Runtime.PPCEABI.H::__register_global_object();
        local_164.x = d_camera::240_0;
        local_164.y = d_camera::_11365;
        local_164.z = d_camera::_14643;
        ::cXyz::cXyz((cXyz *)&DAT_803e499c,&local_164);
        Runtime.PPCEABI.H::__register_global_object();
        local_170.x = d_camera::_5129;
        local_170.y = d_camera::_6117;
        local_170.z = d_camera::_11362;
        ::cXyz::cXyz((cXyz *)&DAT_803e49a8,&local_170);
        Runtime.PPCEABI.H::__register_global_object();
        d_camera::init_14130 = '\x01';
      }
      cSGlobe::cSGlobe(&cStack784,
                       (cXyz *)(&d_camera::p_14128 + (*(uint *)&this->field_0x7c & 3) * 0xc));
      sVar6 = SComponent::cLib_targetAngleY
                        (&(this->mpPlayerActor->mCurrent).mPos,
                         (cXyz *)(*(int *)&this->field_0x37c + 0x1f8));
      cSAngle::cSAngle(acStack840,sVar6);
      cSAngle::operator__(local_378,acStack840);
      if ((((int)local_378[0] >> 0x1f) +
           ((uint)((uint)(int)cSAngle::_0 <= (uint)(int)local_378[0]) - ((int)cSAngle::_0 >> 0x1f))
          & 0xff) == 0) {
        cSAngle::operator__(acStack896,(cSAngle *)&(this->mEvBasePos).y);
        cSGlobe::U(&cStack784,acStack896);
      }
      else {
        cSAngle::operator__(acStack892,(cSAngle *)&(this->mEvBasePos).y);
        cSGlobe::U(&cStack784,acStack892);
      }
      positionOf(&cStack380,this,*(fopAc_ac_c **)&this->field_0x37c);
      ::cXyz::operator__(&this->field_0x44,&cStack380);
      positionOf(&cStack392,this,*(fopAc_ac_c **)&this->field_0x37c);
      cSGlobe::Xyz(&cStack404,&cStack784);
      ::cXyz::operator__(&cStack416,&cStack392,&cStack404);
      ::cXyz::operator__((cXyz *)&this->field_0x38c,&cStack416);
      cVar7 = lineBGCheck(this,(cXyz *)&this->field_0x38c,&(this->mpPlayerActor->mCurrent).mPos,0x7f
                         );
      if (cVar7 == '\0') {
        *(undefined4 *)&this->field_0x388 = 1;
      }
      cSGlobe::_cSGlobe(&cStack784);
    }
    in_r5 = (fopAc_ac_c *)&this->field_0x44;
    ::cXyz::operator__(&cStack524,&this->field_0x50,(cXyz *)in_r5);
    cSGlobe::Val(&this->field_0x3c,&cStack524);
    if ((this->mEventFlags & 0x8000) != 0) {
      *(undefined4 *)&this->field_0x388 = 2;
    }
    if ((this->mEventFlags & 0x100000) != 0) {
      *(undefined *)&this->field_0x102 = 1;
      *(undefined *)&this->field_0x101 = 1;
      *(undefined *)&this->field_0x100 = 1;
    }
  }
  iVar2 = @unnamed@d_camera_cpp@::check_owner_action
                    ((_unnamed_d_camera_cpp_ *)this->mPadId,0x1010000,(ulong)in_r5);
  if (iVar2 == 0) {
    *(undefined4 *)&this->field_0x37c = 0;
  }
  dVar10 = (double)(float)((double)this->field_0x238 / dVar18);
  if (((this->field_0x23c <= d_camera::_9012) ||
      (iVar2 = @unnamed@d_camera_cpp@::check_owner_action1
                         ((_unnamed_d_camera_cpp_ *)this->mPadId,0x400,(ulong)in_r5), iVar2 == 0))
     || ((iVar2 = @unnamed@d_camera_cpp@::check_owner_action
                            ((_unnamed_d_camera_cpp_ *)this->mPadId,0x1000000,(ulong)in_r5),
         iVar2 != 0 ||
         (iVar2 = @unnamed@d_camera_cpp@::check_owner_action1
                            ((_unnamed_d_camera_cpp_ *)this->mPadId,0x80,(ulong)in_r5), iVar2 != 0))
        )) {
    if (dVar10 < (double)d_camera::_13048) {
      *(undefined *)&this->field_0x385 = 1;
    }
  }
  else {
    if (*(char *)&this->field_0x385 != '\0') {
      ResetBlure(this,0);
      dVar11 = (double)(this->field_0x23c / d_camera::_6067);
      if ((double)d_camera::1_0 < dVar11) {
        dVar11 = (double)d_camera::1_0;
      }
      local_118 = (double)(longlong)(int)((double)d_camera::30_0 * dVar11);
      SetBlureTimer(this,(int)((double)d_camera::30_0 * dVar11));
      SetBlureAlpha(this,(float)((double)d_camera::_14648 * dVar11));
      SetBlureScale(this,d_camera::_14649 - (float)((double)d_camera::_14650 * dVar11));
      local_218.x = d_camera::0_0;
      local_218.y = d_camera::1_0;
      local_218.z = d_camera::0_0;
      in_r5 = (fopAc_ac_c *)&DAT_00000020;
      dVibration_c::StartShock
                (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mVibration,7,0x20,&local_218);
      *(undefined *)&this->field_0x385 = 0;
    }
  }
  fVar1 = d_camera::_9006;
  dVar11 = (double)d_camera::_1_0;
  if ((dVar11 <= dVar10) && (dVar11 = dVar10, (double)d_camera::1_0 < dVar10)) {
    dVar11 = (double)d_camera::1_0;
  }
  dVar10 = (double)(this->mEvBasePos).z;
  (this->mEvBasePos).z = (float)(dVar10 + (double)(d_camera::_9006 * (float)(dVar20 - dVar10)));
  *(float *)&this->field_0x3b8 =
       (float)((double)*(float *)&this->field_0x3b8 +
              (double)(fVar1 * (float)(dVar19 - (double)*(float *)&this->field_0x3b8)));
  *(float *)&this->field_0x3bc =
       (float)((double)*(float *)&this->field_0x3bc +
              (double)(fVar1 * (float)(dVar17 - (double)*(float *)&this->field_0x3bc)));
  *(float *)&this->field_0x3c0 =
       (float)((double)*(float *)&this->field_0x3c0 +
              (double)(fVar1 * (float)(dVar16 - (double)*(float *)&this->field_0x3c0)));
  dVar10 = (double)((this->mEvBasePos).z +
                   (float)(dVar11 * (double)(float)((double)*(float *)&this->field_0x3b8 * dVar11)))
  ;
  dVar16 = (double)(*(float *)&this->field_0x3bc +
                   (float)(dVar11 * (double)(float)((double)*(float *)&this->field_0x3c0 * dVar11)))
  ;
  dVar13 = (double)(float)(dVar14 + (double)(float)(dVar13 * dVar11));
  if (*(int *)&this->field_0x37c == 0) {
    sVar6 = cSAngle::Inv((cSAngle *)&(this->mEvBasePos).y);
    local_118 = (double)(longlong)(int)((double)d_camera::_8358 * dVar16);
    cSGlobe::Val(&local_320,(float)dVar10,(short)(int)((double)d_camera::_8358 * dVar16),sVar6);
  }
  else {
    iVar2 = @unnamed@d_camera_cpp@::check_owner_action1
                      ((_unnamed_d_camera_cpp_ *)this->mPadId,2,(ulong)in_r5);
    if (iVar2 == 0) {
      iVar2 = @unnamed@d_camera_cpp@::check_owner_action1
                        ((_unnamed_d_camera_cpp_ *)this->mPadId,4,(ulong)in_r5);
      if (iVar2 == 0) {
        cSAngle::Val(acStack848,*(short *)(*(int *)&this->field_0x37c + 0x364));
        *(float *)&this->field_0x3c4 =
             (float)((double)*(float *)&this->field_0x3c4 +
                    (double)(d_camera::_10148 *
                            (float)(dVar11 - (double)*(float *)&this->field_0x3c4)));
      }
      else {
        directionOf((dCamera_c *)acStack912,(fopAc_ac_c *)this);
        cSAngle::operator__(acStack916,acStack912,
                            *(short *)(*(int *)&this->field_0x37c + 0x20e) +
                            *(short *)(*(int *)&this->field_0x37c + 0x394));
        cSAngle::operator__(acStack920,acStack916);
        cSAngle::Val(acStack848,acStack920);
        fVar1 = d_camera::1_0;
        if (*(char *)&this->field_0x384 != '\0') {
          fVar1 = d_camera::_1_0;
        }
        *(float *)&this->field_0x3c4 =
             *(float *)&this->field_0x3c4 + d_camera::_5311 * (fVar1 - *(float *)&this->field_0x3c4)
        ;
      }
    }
    else {
      cSAngle::Val(acStack848,*(short *)(*(int *)&this->field_0x37c + 0x398));
      *(float *)&this->field_0x3c4 =
           *(float *)&this->field_0x3c4 +
           d_camera::_5311 * (d_camera::1_0 - *(float *)&this->field_0x3c4);
    }
    dVar14 = (double)cSAngle::Sin(acStack848);
    local_128.x = local_128.x - *(float *)&this->field_0x3c4 * (float)(dVar24 * dVar14);
    local_128.y = local_128.y + (float)(dVar23 * dVar11);
    if (((*(char *)&this->field_0x314 != '\0') &&
        (*(float *)&this->field_0x318 == *(float *)&this->field_0x354)) &&
       ((dCamParam_c::styles[param_1].mFlag & 4) != 0)) {
      cSGlobe::cSGlobe(&cStack808,d_camera::_5129,&cSAngle::_0,(cSAngle *)&(this->mEvBasePos).y);
      positionOf(&cStack548,this,*(fopAc_ac_c **)&this->field_0x37c);
      cSGlobe::Xyz(&cStack560,&cStack808);
      ::cXyz::operator__(&cStack572,&cStack548,&cStack560);
      ::cXyz::cXyz(&local_134,&cStack572);
      uVar4 = d_a_sea::daSea_ChkArea(local_134.x,local_134.z);
      if ((uVar4 & 0xff) != 0) {
        dVar14 = (double)d_a_sea::daSea_calcWave((double)local_134.x,(double)local_134.z);
        local_134.y = (float)dVar14;
        positionOf(&cStack584,this,*(fopAc_ac_c **)&this->field_0x37c);
        ::cXyz::operator__(&cStack596,&local_134,&cStack584);
        cSGlobe::Val(&cStack808,&cStack596);
        dVar14 = (double)cSAngle::Degree(&cStack808.mAngleX);
        dVar16 = (double)(float)(dVar16 + (double)(d_camera::_13048 * (float)(dVar11 * dVar14)));
      }
      cSGlobe::_cSGlobe(&cStack808);
    }
    sVar6 = cSAngle::Inv((cSAngle *)&(this->mEvBasePos).y);
    local_118 = (double)(longlong)(int)((double)d_camera::_8358 * dVar16);
    cSGlobe::Val(&local_320,(float)dVar10,(short)(int)((double)d_camera::_8358 * dVar16),sVar6);
  }
  *(float *)&this->field_0x3c8 =
       *(float *)&this->field_0x3c8 +
       d_camera::_9011 * (d_camera::1_0 - *(float *)&this->field_0x3c8);
  relationalPos(&cStack608,this,this->mpPlayerActor,&local_128);
  ::cXyz::operator__(&cStack620,&cStack608,(cXyz *)&this->mEvTimer);
  ::cXyz::operator_(&cStack632,&cStack620,*(float *)&this->field_0x3c8);
  mtx::PSVECAdd((cXyz *)&this->mEvTimer,&cStack632,(cXyz *)&this->mEvTimer);
  if (*(char *)&this->field_0x100 == '\0') {
    iVar2 = *(int *)&this->field_0x388;
    if (iVar2 == 2) {
      iVar2 = 1;
    }
    else {
      if ((iVar2 < 2) && (0 < iVar2)) {
        iVar2 = 0x28;
        local_118 = (double)CONCAT44(0x43300000,0x28U - this->field_0x11c ^ 0x80000000);
        in_f18 = (double)(d_camera::1_0 / (float)(local_118 - d_camera::_5738));
        ::cXyz::operator__(&cStack644,(cXyz *)&this->mEvTimer,&this->field_0x44);
        ::cXyz::operator_(&cStack656,&cStack644,(float)in_f18);
        mtx::PSVECAdd(&this->field_0x44,&cStack656,&this->field_0x44);
        ::cXyz::operator__(&this->field_0x50,(cXyz *)&this->field_0x38c);
        ::cXyz::operator__(&cStack668,&this->field_0x50,&this->field_0x44);
        cSGlobe::Val(&this->field_0x3c,&cStack668);
      }
      else {
        iVar2 = 0x14;
        local_118 = (double)CONCAT44(0x43300000,0x14U - this->field_0x11c ^ 0x80000000);
        in_f18 = (double)(d_camera::1_0 / (float)(local_118 - d_camera::_5738));
        ::cXyz::operator__(&cStack680,(cXyz *)&this->mEvTimer,&this->field_0x44);
        ::cXyz::operator_(&cStack692,&cStack680,(float)in_f18);
        mtx::PSVECAdd(&this->field_0x44,&cStack692,&this->field_0x44);
        fVar1 = (this->field_0x3c).mDistance;
        (this->field_0x3c).mDistance =
             fVar1 + (float)(in_f18 * (double)(local_320.mDistance - fVar1));
        cSAngle::operator__(acStack924,&local_320.mAngleX);
        cSAngle::operator_(acStack928,(float)in_f18);
        cSAngle::operator__(acStack932,&(this->field_0x3c).mAngleX);
        cSGlobe::V(&this->field_0x3c,acStack932);
        cSAngle::operator__(acStack936,&local_320.mAngleY);
        cSAngle::operator_(acStack940,(float)in_f18);
        cSAngle::operator__(acStack944,&(this->field_0x3c).mAngleY);
        cSGlobe::U(&this->field_0x3c,acStack944);
        cSGlobe::Xyz(&cStack704,&this->field_0x3c);
        ::cXyz::operator__(&cStack716,&this->field_0x44,&cStack704);
        ::cXyz::operator__(&this->field_0x50,&cStack716);
      }
    }
    this->field_0x60 =
         (float)((double)this->field_0x60 +
                (double)(float)(in_f18 * (double)(float)(dVar13 - (double)this->field_0x60)));
    if (this->field_0x11c == iVar2 + -1) {
      *(undefined *)&this->field_0x102 = 1;
      *(undefined *)&this->field_0x101 = 1;
      *(undefined *)&this->field_0x100 = 1;
    }
    cSGlobe::_cSGlobe(&local_320);
  }
  else {
    local_140 = (float)dVar22;
    local_13c = (float)dVar21;
    local_138 = (float)dVar22;
    ::cXyz::operator__(&cStack728,(cXyz *)&this->mEvTimer,&this->field_0x44);
    ::cXyz::operator_(&cStack740,(Vec *)&cStack728);
    mtx::PSVECAdd(&this->field_0x44,&cStack740,&this->field_0x44);
    fVar1 = (this->field_0x3c).mDistance;
    dVar10 = (double)(fVar1 + (float)(dVar15 * (double)(local_320.mDistance - fVar1)));
    directionOf((dCamera_c *)acStack948,(fopAc_ac_c *)this);
    uVar5 = cSAngle::Inv(acStack948);
    pcVar8 = &(this->field_0x3c).mAngleY;
    SComponent::operator__(acStack952,uVar5,pcVar8);
    cSAngle::cSAngle(acStack852,acStack952);
    if ((this->mEventFlags & 0x100000) == 0) {
      cSAngle::Sin(acStack852);
    }
    cSAngle::operator__(acStack956,&local_320.mAngleY);
    cSAngle::operator_(acStack960,(float)dVar12);
    cSAngle::operator__(acStack964,pcVar8);
    cSAngle::cSAngle(acStack856,acStack964);
    ::cXyz::operator__(&cStack752,&this->field_0x50,&this->field_0x44);
    cSGlobe::cSGlobe(&cStack816,&cStack752);
    dVar12 = (double)d_camera::1_0;
    if (((*(char *)&this->field_0x314 != '\0') &&
        (*(float *)&this->field_0x318 == *(float *)&this->field_0x354)) &&
       ((dCamParam_c::styles[param_1].mFlag & 4) != 0)) {
      if ((double)d_camera::_6431 < dVar11) {
        dVar12 = (double)d_camera::0_0;
      }
      else {
        dVar12 = (double)(d_camera::_9007 * (float)((double)d_camera::_6431 - dVar11));
      }
    }
    cSAngle::operator__(acStack968,&cStack816.mAngleX);
    cSAngle::operator_(acStack972,(float)((double)d_camera::0_25 * dVar12));
    pcVar8 = acStack972;
    cSAngle::operator__(acStack976,&local_320.mAngleX);
    cSGlobe::V(&local_320,acStack976);
    iVar2 = @unnamed@d_camera_cpp@::check_owner_action1
                      ((_unnamed_d_camera_cpp_ *)this->mPadId,4,(ulong)pcVar8);
    if (iVar2 == 0) {
      local_35c[0] = local_320.mAngleX;
    }
    else {
      cSAngle::operator__(acStack980,(short)&local_320.mAngleX);
      cSAngle::Val(local_35c,acStack980);
      cSAngle::operator__(local_35c,d_camera::_14651);
    }
    cSAngle::operator__(acStack984,local_35c);
    cSAngle::operator_(acStack988,(float)dVar15);
    cSAngle::operator__(acStack992,&(this->field_0x3c).mAngleX);
    cSAngle::cSAngle(local_360,acStack992);
    if (local_360[0] < local_334[0]) {
      cSAngle::Val(local_360,local_334);
    }
    else {
      if (local_338[0] < local_360[0]) {
        cSAngle::Val(local_360,local_338);
      }
    }
    cSGlobe::Val(&this->field_0x3c,(float)dVar10,local_360,acStack856);
    cSGlobe::Xyz(&cStack764,&this->field_0x3c);
    ::cXyz::operator__(&cStack776,&this->field_0x44,&cStack764);
    ::cXyz::operator__(&this->field_0x50,&cStack776);
    this->field_0x60 =
         (float)((double)this->field_0x60 +
                (double)(float)(dVar15 * (double)(float)(dVar13 - (double)this->field_0x60)));
    cSAngle::operator_(acStack996,this->mStickMainPosXLast);
    cSAngle::operator__(acStack1000,acStack996);
    cSAngle::operator_(acStack1004,d_camera::_6065 * (float)ABS(dVar11));
    cSAngle::operator___((cSAngle *)&this->field_0x5c,acStack1004);
    this->mEventFlags = this->mEventFlags | 0x400;
    cSGlobe::_cSGlobe(&cStack816);
    cSGlobe::_cSGlobe(&local_320);
  }
  __psq_l0(auStack8,uVar9);
  __psq_l1(auStack8,uVar9);
  __psq_l0(auStack24,uVar9);
  __psq_l1(auStack24,uVar9);
  __psq_l0(auStack40,uVar9);
  __psq_l1(auStack40,uVar9);
  __psq_l0(auStack56,uVar9);
  __psq_l1(auStack56,uVar9);
  __psq_l0(auStack72,uVar9);
  __psq_l1(auStack72,uVar9);
  __psq_l0(auStack88,uVar9);
  __psq_l1(auStack88,uVar9);
  __psq_l0(auStack104,uVar9);
  __psq_l1(auStack104,uVar9);
  __psq_l0(auStack120,uVar9);
  __psq_l1(auStack120,uVar9);
  __psq_l0(auStack136,uVar9);
  __psq_l1(auStack136,uVar9);
  __psq_l0(auStack152,uVar9);
  __psq_l1(auStack152,uVar9);
  __psq_l0(auStack168,uVar9);
  __psq_l1(auStack168,uVar9);
  __psq_l0(auStack184,uVar9);
  __psq_l1(auStack184,uVar9);
  __psq_l0(auStack200,uVar9);
  __psq_l1(auStack200,uVar9);
  __psq_l0(auStack216,uVar9);
  __psq_l1(auStack216,uVar9);
  __psq_l0(auStack232,uVar9);
  __psq_l1(auStack232,uVar9);
  __psq_l0(auStack248,uVar9);
  __psq_l1(auStack248,uVar9);
  return 1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x80176f2c) */
/* WARNING: Removing unreachable block (ram,0x80176f1c) */
/* WARNING: Removing unreachable block (ram,0x80176f0c) */
/* WARNING: Removing unreachable block (ram,0x80176efc) */
/* WARNING: Removing unreachable block (ram,0x80176eec) */
/* WARNING: Removing unreachable block (ram,0x80176edc) */
/* WARNING: Removing unreachable block (ram,0x80176ed4) */
/* WARNING: Removing unreachable block (ram,0x80176ee4) */
/* WARNING: Removing unreachable block (ram,0x80176ef4) */
/* WARNING: Removing unreachable block (ram,0x80176f04) */
/* WARNING: Removing unreachable block (ram,0x80176f14) */
/* WARNING: Removing unreachable block (ram,0x80176f24) */
/* WARNING: Removing unreachable block (ram,0x80176f34) */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall dCamera_c::hungCamera(long) */

undefined4 __thiscall dCamera_c::hungCamera(dCamera_c *this,long param_1)

{
  int iVar1;
  undefined *puVar2;
  float fVar3;
  uint uVar4;
  undefined4 uVar5;
  cXyz *pcVar6;
  short sVar7;
  fopAc_ac_c *pfVar8;
  cSAngle *this_00;
  undefined4 uVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  undefined8 in_f19;
  undefined8 in_f20;
  double dVar13;
  undefined8 in_f21;
  double dVar14;
  undefined8 in_f22;
  double dVar15;
  undefined8 in_f23;
  double dVar16;
  undefined8 in_f24;
  double dVar17;
  undefined8 in_f25;
  double dVar18;
  undefined8 in_f26;
  double dVar19;
  undefined8 in_f27;
  double dVar20;
  undefined8 in_f28;
  double dVar21;
  undefined8 in_f29;
  double dVar22;
  undefined8 in_f30;
  double dVar23;
  undefined8 in_f31;
  double dVar24;
  float fVar25;
  cSAngle local_308 [2];
  cSAngle local_304 [2];
  cSAngle local_300 [2];
  cSAngle local_2fc [2];
  cSAngle local_2f8 [2];
  cSAngle acStack756 [2];
  cSAngle acStack752 [2];
  cSAngle acStack748 [2];
  cSAngle acStack744 [2];
  cSAngle acStack740 [2];
  cSAngle acStack736 [2];
  cSAngle acStack732 [2];
  cSAngle acStack728 [2];
  cSAngle acStack724 [6];
  cSAngle local_2c8 [2];
  cSAngle acStack708 [2];
  cSAngle acStack704 [2];
  cSAngle local_2bc [2];
  cSAngle acStack696 [2];
  cSAngle acStack692 [2];
  cSAngle acStack688 [2];
  cSAngle acStack684 [2];
  cSAngle acStack680 [2];
  cSAngle acStack676 [2];
  cSAngle acStack672 [2];
  cSAngle acStack668 [2];
  cSAngle acStack664 [2];
  cSAngle acStack660 [2];
  cSAngle local_290 [2];
  cSAngle local_28c [2];
  cSAngle acStack648 [2];
  cSAngle acStack644 [2];
  float local_280;
  float local_27c;
  cSGlobe local_278;
  cSGlobe local_270;
  cXyz cStack616;
  cXyz local_25c;
  cXyz cStack592;
  cXyz cStack580;
  cXyz cStack568;
  cXyz cStack556;
  cXyz cStack544;
  float local_214;
  undefined *local_210;
  float local_20c;
  cXyz local_208;
  cXyz local_1fc;
  cXyz cStack496;
  cXyz cStack484;
  cXyz cStack472;
  cXyz cStack460;
  cXyz local_1c0;
  cXyz cStack436;
  cXyz cStack424;
  cXyz cStack412;
  cXyz cStack400;
  cXyz cStack388;
  cXyz cStack376;
  cXyz cStack364;
  cXyz local_160;
  cXyz local_154;
  cXyz cStack328;
  cXyz cStack316;
  cXyz local_130;
  cXyz local_124;
  cXyz local_118;
  float local_10c;
  float local_108;
  float local_104;
  cXyz local_100;
  longlong local_f0;
  int local_e8;
  uint uStack228;
  undefined auStack200 [16];
  undefined auStack184 [16];
  undefined auStack168 [16];
  undefined auStack152 [16];
  undefined auStack136 [16];
  undefined auStack120 [16];
  undefined auStack104 [16];
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar9 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  __psq_st0(auStack72,(int)((ulonglong)in_f27 >> 0x20),0);
  __psq_st1(auStack72,(int)in_f27,0);
  __psq_st0(auStack88,(int)((ulonglong)in_f26 >> 0x20),0);
  __psq_st1(auStack88,(int)in_f26,0);
  __psq_st0(auStack104,(int)((ulonglong)in_f25 >> 0x20),0);
  __psq_st1(auStack104,(int)in_f25,0);
  __psq_st0(auStack120,(int)((ulonglong)in_f24 >> 0x20),0);
  __psq_st1(auStack120,(int)in_f24,0);
  __psq_st0(auStack136,(int)((ulonglong)in_f23 >> 0x20),0);
  __psq_st1(auStack136,(int)in_f23,0);
  __psq_st0(auStack152,(int)((ulonglong)in_f22 >> 0x20),0);
  __psq_st1(auStack152,(int)in_f22,0);
  __psq_st0(auStack168,(int)((ulonglong)in_f21 >> 0x20),0);
  __psq_st1(auStack168,(int)in_f21,0);
  __psq_st0(auStack184,(int)((ulonglong)in_f20 >> 0x20),0);
  __psq_st1(auStack184,(int)in_f20,0);
  __psq_st0(auStack200,(int)((ulonglong)in_f19 >> 0x20),0);
  __psq_st1(auStack200,(int)in_f19,0);
  local_100.x = dCamParam_c::styles[param_1].field_0xc;
  local_100.y = dCamParam_c::styles[param_1].mCenterHeightBase;
  local_100.z = dCamParam_c::styles[param_1].field_0x8;
  dVar19 = (double)dCamParam_c::styles[param_1].field_0x14;
  dVar18 = (double)dCamParam_c::styles[param_1].field_0x18;
  dVar17 = (double)dCamParam_c::styles[param_1].field_0x30;
  dVar16 = (double)dCamParam_c::styles[param_1].field_0x34;
  dVar21 = (double)dCamParam_c::styles[param_1].field_0x40;
  dVar15 = (double)dCamParam_c::styles[param_1].field_0x3c;
  dVar14 = (double)dCamParam_c::styles[param_1].field_0x44;
  dVar13 = (double)*(float *)&dCamParam_c::styles[param_1].field_0x48;
  dVar20 = (double)dCamParam_c::styles[param_1].mLockonLatitudeMax;
  dVar24 = (double)dCamParam_c::styles[param_1].mLockonLatitudeMin;
  dVar23 = (double)dCamParam_c::styles[param_1].mFovyBase;
  dVar22 = (double)dCamParam_c::styles[param_1].mLockonFovyMax;
  if ((((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4] & 0x100U) != 0) &&
     (d_camera::_10137 < local_100.z)) {
    local_100.z = d_camera::_10137;
  }
  if (this->field_0x11c == 0) {
    *(undefined4 *)&this->field_0x378 = 0x48554e47;
    (this->mEvBasePos).y = (this->field_0x44).x;
    (this->mEvBasePos).z = (this->field_0x44).y;
    *(float *)&this->field_0x3b8 = (this->field_0x44).z;
    *(float *)&this->field_0x390 = d_camera::0_0;
    *(undefined4 *)&this->field_0x388 = 0;
    positionOf(&cStack316,this,this->mpPlayerActor);
    this->mEvFovy = cStack316.y;
    (this->mEvBasePos).x = cStack316.y;
    fVar25 = d_camera::_8359;
    *(float *)&this->field_0x3c4 = d_camera::_8359;
    *(float *)&this->field_0x3c0 = fVar25;
    fVar25 = d_camera::0_0;
    *(float *)&this->field_0x3d8 = d_camera::0_0;
    *(float *)&this->field_0x3dc = fVar25;
    *(undefined *)&this->field_0x3bc = 0;
    this->mEvTimer = (int)(float)dVar18;
    *(undefined4 *)&this->field_0x38c = 0;
    relationalPos(&cStack328,this,this->mpPlayerActor,&local_100);
    ::cXyz::operator__(&local_154,&this->mCenter,&cStack328);
    local_160.x = local_154.x;
    local_160.y = local_154.y;
    local_160.z = local_154.z;
    fVar25 = mtx::PSVECSquareMag(&local_160);
    dVar11 = (double)fVar25;
    if ((double)d_camera::0_0 < dVar11) {
      dVar10 = 1.0 / SQRT(dVar11);
      dVar10 = d_camera::_5735 * dVar10 * (d_camera::_5736 - dVar11 * dVar10 * dVar10);
      dVar10 = d_camera::_5735 * dVar10 * (d_camera::_5736 - dVar11 * dVar10 * dVar10);
      local_280 = (float)(dVar11 * d_camera::_5735 * dVar10 *
                                   (d_camera::_5736 - dVar11 * dVar10 * dVar10));
      dVar11 = (double)local_280;
    }
    if (dVar11 < dVar17) {
      dVar11 = dVar17;
    }
    pfVar8 = this->mpPlayerActor;
    if ((pfVar8->parent).parent.mProcName == 0xa9) {
      puVar2 = pfVar8[1].parent.parent.mLyTg.parent.parent.mpData;
    }
    else {
      puVar2 = (undefined *)(d_camera::_8357 * ((pfVar8->mEyePos).y - (pfVar8->mCurrent).mPos.y));
    }
    dVar10 = (double)(float)puVar2;
    if (dVar10 < (double)d_camera::_6064) {
      dVar10 = (double)d_camera::_6064;
    }
    dVar10 = (double)(float)(dVar11 / dVar10);
    directionOf((dCamera_c *)acStack672,(fopAc_ac_c *)this);
    uVar5 = cSAngle::Inv(acStack672);
    SComponent::operator__(acStack676,uVar5,&(this->field_0x3c).mAngleY);
    cSAngle::cSAngle(acStack680,acStack676);
    dVar11 = (double)cSAngle::Norm(acStack680);
    if ((double)d_camera::0_0 < dVar10) {
      dVar12 = 1.0 / SQRT(dVar10);
      dVar12 = d_camera::_5735 * dVar12 * (d_camera::_5736 - dVar10 * dVar12 * dVar12);
      dVar12 = d_camera::_5735 * dVar12 * (d_camera::_5736 - dVar10 * dVar12 * dVar12);
      local_27c = (float)(dVar10 * d_camera::_5735 * dVar12 *
                                   (d_camera::_5736 - dVar10 * dVar12 * dVar12));
      dVar10 = (double)local_27c;
    }
    iVar1 = (int)((float)((double)d_camera::_9194 * dVar10) *
                 (d_camera::1_0 + ABS((float)((double)d_camera::_9007 * dVar11))));
    local_f0 = (longlong)iVar1;
    *(int *)&this->field_0x37c = iVar1 + 1;
    uStack228 = *(int *)&this->field_0x37c * (*(int *)&this->field_0x37c + 1) >> 1 ^ 0x80000000;
    local_e8 = 0x43300000;
    *(float *)&this->field_0x380 = (float)((double)CONCAT44(0x43300000,uStack228) - d_camera::_5738)
    ;
  }
  if (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4] & 0x80000000U) == 0) {
    positionOf(&cStack364,this,this->mpPlayerActor);
    this->mEvFovy = this->mEvFovy + d_camera::_5311 * (cStack364.y - this->mEvFovy);
  }
  if (*(char *)&this->field_0x100 == '\0') {
    uStack228 = *(int *)&this->field_0x37c - this->field_0x11c ^ 0x80000000;
    local_e8 = 0x43300000;
    *(float *)&this->field_0x384 = (float)((double)CONCAT44(0x43300000,uStack228) - d_camera::_5738)
    ;
    dVar13 = (double)(*(float *)&this->field_0x384 / *(float *)&this->field_0x380);
    relationalPos(&cStack376,this,this->mpPlayerActor,&local_100);
    ::cXyz::operator__(&cStack388,&cStack376,&this->field_0x44);
    ::cXyz::operator_(&cStack400,&cStack388,(float)dVar13);
    pcVar6 = (cXyz *)&(this->mEvBasePos).y;
    mtx::PSVECAdd(pcVar6,&cStack400,pcVar6);
    ::cXyz::operator__(&cStack412,(cXyz *)&(this->mEvBasePos).y,&this->field_0x44);
    ::cXyz::operator_(&cStack424,&cStack412,(float)dVar19);
    pcVar6 = &this->field_0x44;
    mtx::PSVECAdd(pcVar6,&cStack424,pcVar6);
    dVar18 = (double)@unnamed@d_camera_cpp@::limitf
                               ((_unnamed_d_camera_cpp_ *)pcVar6,(this->field_0x3c).mDistance,
                                (float)dVar16,(float)dVar17);
    cSAngle::cSAngle(acStack644,(float)dVar14);
    directionOf((dCamera_c *)acStack684,(fopAc_ac_c *)this);
    sVar7 = cSAngle::Inv(acStack684);
    cSAngle::cSAngle(acStack688,sVar7);
    cSGlobe::cSGlobe(&local_270,(float)dVar18,acStack644,acStack688);
    fVar25 = (this->field_0x3c).mDistance;
    (this->field_0x3c).mDistance = fVar25 + (float)(dVar13 * (double)(local_270.mDistance - fVar25))
    ;
    this_00 = &(this->field_0x3c).mAngleX;
    cSAngle::operator__(acStack692,&local_270.mAngleX);
    cSAngle::operator_(acStack696,(float)dVar13);
    cSAngle::operator__(local_2bc,this_00);
    cSAngle::cSAngle(local_2fc,local_2bc[0]);
    (this->field_0x3c).mAngleX.v = local_2fc[0];
    cSAngle::operator__(acStack704,&local_270.mAngleY);
    cSAngle::operator_(acStack708,(float)dVar13);
    cSAngle::operator__(local_2c8,&(this->field_0x3c).mAngleY);
    cSAngle::cSAngle(local_300,local_2c8[0]);
    (this->field_0x3c).mAngleY.v = local_300[0];
    cSGlobe::Xyz(&cStack436,&this->field_0x3c);
    ::cXyz::operator__(&local_1c0,&this->field_0x44,&cStack436);
    (this->field_0x50).x = local_1c0.x;
    (this->field_0x50).y = local_1c0.y;
    (this->field_0x50).z = local_1c0.z;
    dVar18 = (double)cSAngle::Degree(this_00);
    *(float *)this->mEvRelUseMask = (float)dVar18;
    pfVar8 = (fopAc_ac_c *)(this->field_0x3c).mDistance;
    this->mpEvRelActor = pfVar8;
    this->mEvBank = (float)pfVar8;
    this->field_0x60 =
         (float)((double)this->field_0x60 +
                (double)(float)(dVar13 * (double)(float)(dVar23 - (double)this->field_0x60)));
    *(float *)&this->field_0x380 = *(float *)&this->field_0x380 - *(float *)&this->field_0x384;
    if (*(int *)&this->field_0x37c - 1U <= (uint)this->field_0x11c) {
      *(undefined *)&this->field_0x102 = 1;
      *(undefined *)&this->field_0x101 = 1;
      *(undefined *)&this->field_0x100 = 1;
      *(float *)&this->field_0x384 = d_camera::0_0;
    }
  }
  else {
    if (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4] & 0x80000080U) != 0) {
      dVar11 = dVar18;
      positionOf(&cStack460,this,this->mpPlayerActor);
      fVar25 = d_camera::0_0;
      dVar10 = (double)d_camera::1_0;
      if ((float)((double)this->mEvFovy - dVar10) <= cStack460.y) {
        this->mEvTimer = (int)d_camera::0_0;
        *(float *)&this->field_0x384 = fVar25;
      }
      else {
        *(float *)&this->field_0x384 = (float)((double)*(float *)&this->field_0x384 + dVar10);
        this->mEvTimer =
             (int)((float)this->mEvTimer +
                  d_camera::_15074 * *(float *)&this->field_0x384 *
                  ((float)(dVar10 - dVar11) - (float)this->mEvTimer));
        dVar18 = (double)(float)(dVar11 + (double)(float)this->mEvTimer);
      }
    }
    local_10c = (float)dVar19;
    local_108 = (float)dVar18;
    local_104 = (float)dVar19;
    relationalPos(&cStack472,this,this->mpPlayerActor,&local_100);
    ::cXyz::operator__(&cStack484,&cStack472,&this->field_0x44);
    ::cXyz::operator_(&cStack496,(Vec *)&cStack484);
    mtx::PSVECAdd(&this->field_0x44,&cStack496,&this->field_0x44);
    dVar18 = (double)d_camera::0_0;
    if (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4] & 0x100U) == 0) {
      if (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4] & 0x80000080U) != 0)
      {
        dVar18 = (double)(d_camera::_10129 * (float)((double)d_camera::_6067 - dVar14));
        positionOf(&cStack544,this,this->mpPlayerActor);
        if (cStack544.y <= this->mEvFovy) {
          positionOf(&cStack568,this,this->mpPlayerActor);
          fVar25 = (cStack568.y - this->mEvFovy) / d_camera::_15076;
        }
        else {
          positionOf(&cStack556,this,this->mpPlayerActor);
          fVar25 = (cStack556.y - this->mEvFovy) / d_camera::_9247;
        }
        dVar19 = (double)fVar25;
        if ((double)d_camera::1_0 < (double)fVar25) {
          dVar19 = (double)d_camera::1_0;
        }
        if (dVar19 < (double)d_camera::0_0) {
          dVar19 = (double)d_camera::0_0;
        }
        dVar18 = (double)(float)(dVar18 * dVar19);
      }
    }
    else {
      ::daPy_py_c::getRopePos(&local_1fc,(daPy_py_c *)this->mpPlayerActor);
      local_118.x = local_1fc.x;
      local_118.y = local_1fc.y;
      local_118.z = local_1fc.z;
      positionOf(&local_208,this,this->mpPlayerActor);
      local_124.x = local_208.x;
      local_124.y = local_208.y;
      local_124.z = local_208.z;
      directionOf((dCamera_c *)(acStack724 + 4),(fopAc_ac_c *)this);
      dCamMath::xyzProjPosOnYZ
                ((dCamMath *)&local_214,(cSAngle)((short)register0x00000004 + -0x2cc),&local_124,
                 &local_118);
      local_130.x = local_214;
      local_130.y = (float)local_210;
      local_130.z = local_20c;
      dVar18 = (double)dCamMath::xyzHorizontalDistance(&local_124,&local_130);
      dVar18 = SComponent::cM_atan2f(dVar18,(double)(local_130.y - local_124.y));
      dVar18 = (double)(float)((double)d_camera::_15075 * dVar18);
      sVar7 = SComponent::cLib_targetAngleY(&local_118,&local_124);
      cSAngle::cSAngle(acStack648,sVar7);
      directionOf((dCamera_c *)(acStack724 + 2),(fopAc_ac_c *)this);
      cSAngle::operator__(acStack724,acStack648);
      cSAngle::cSAngle(acStack728,acStack724);
      dVar19 = (double)cSAngle::Cos(acStack728);
      if ((double)d_camera::0_0 < dVar19) {
        dVar18 = -dVar18;
      }
    }
    ::cXyz::operator__(&cStack580,&this->field_0x50,&this->field_0x44);
    cSGlobe::cSGlobe(&local_278,&cStack580);
    uVar4 = (&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4] & 0x80000000;
    if ((uVar4 == 0) || (9 < *(int *)&this->field_0x38c)) {
      if (uVar4 == 0) {
        *(undefined4 *)&this->field_0x38c = 0;
      }
      dVar19 = (double)local_278.mDistance;
      uVar4 = (&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4] & 0x80;
      if (uVar4 == 0) {
        if (dVar19 <= dVar17) {
          if (dVar19 < dVar16) {
            dVar19 = (double)(float)(dVar19 + (double)(float)(dVar15 * (double)(float)(dVar16 - 
                                                  dVar19)));
          }
        }
        else {
          dVar19 = (double)(float)(dVar19 + (double)(float)(dVar15 * (double)(float)(dVar17 - dVar19
                                                                                    )));
        }
      }
      else {
        dVar17 = (double)(this->field_0x3c).mDistance;
        dVar19 = (double)(float)(dVar17 + (double)(float)(dVar15 * (double)(float)(dVar16 - dVar17))
                                );
      }
      if (uVar4 == 0) {
        cSAngle::Val(local_28c,(float)(dVar14 + (double)(float)(dVar18 * dVar24)));
      }
      else {
        cSAngle::Val(local_28c,(float)dVar13);
      }
      directionOf((dCamera_c *)acStack732,(fopAc_ac_c *)this);
      sVar7 = cSAngle::Inv(acStack732);
      cSAngle::Val(local_290,sVar7);
    }
    else {
      dVar19 = (double)local_278.mDistance;
      local_28c[0] = local_278.mAngleX;
      local_290[0] = local_278.mAngleY;
      dVar18 = (double)d_camera::1_0;
      uStack228 = *(uint *)&this->field_0x38c ^ 0x80000000;
      local_e8 = 0x43300000;
      fVar25 = (float)(dVar18 - (double)((float)((double)CONCAT44(0x43300000,uStack228) -
                                                d_camera::_5738) / d_camera::_6064));
      dVar21 = (double)(float)(dVar21 + (double)((float)(dVar18 - dVar21) * fVar25));
      dVar20 = (double)(float)(dVar20 + (double)((float)(dVar18 - dVar20) * fVar25));
      *(uint *)&this->field_0x38c = *(uint *)&this->field_0x38c + 1;
    }
    if (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4] & 0x80000080U) != 0) {
      cSAngle::cSAngle(acStack660,d_camera::_11364);
      cSAngle::cSAngle(acStack664,d_camera::_11363);
      cSAngle::cSAngle(acStack668,d_camera::_15077);
      fVar25 = this->mStickCPosXLast;
      fVar3 = d_camera::1_0;
      if ((fVar25 <= d_camera::_10812) && (fVar3 = d_camera::_1_0, d_camera::_11518 <= fVar25)) {
        fVar3 = fVar25 / d_camera::_10812;
      }
      fVar25 = this->mStickCPosYLast;
      if (fVar25 <= d_camera::_10812) {
        if (d_camera::_11518 <= fVar25) {
          dVar18 = (double)(fVar25 / d_camera::_10812);
        }
        else {
          dVar18 = (double)d_camera::_1_0;
        }
      }
      else {
        dVar18 = (double)d_camera::1_0;
      }
      dVar13 = (double)dCamMath::rationalBezierRatio(fVar3,d_camera::_9007);
      dVar14 = (double)dCamMath::rationalBezierRatio((float)dVar18,d_camera::_9007);
      *(float *)&this->field_0x3d8 =
           (float)((double)*(float *)&this->field_0x3d8 +
                  (double)(d_camera::_10152 * (float)(dVar13 - (double)*(float *)&this->field_0x3d8)
                          ));
      *(float *)&this->field_0x3dc =
           (float)((double)*(float *)&this->field_0x3dc +
                  (double)(d_camera::_6431 * (float)(dVar14 - (double)*(float *)&this->field_0x3dc))
                  );
      if (dVar18 <= (double)d_camera::0_0) {
        dVar19 = (double)(float)(dVar19 - (double)(*(float *)&this->field_0x3dc *
                                                  (float)((double)d_camera::_15078 - dVar19)));
        cSAngle::operator__(acStack744,acStack664);
        cSAngle::operator_(acStack748,*(float *)&this->field_0x3dc);
        cSAngle::operator___(local_28c,acStack748);
      }
      else {
        dVar19 = (double)(float)(dVar19 + (double)(*(float *)&this->field_0x3dc *
                                                  (float)((double)d_camera::_10130 - dVar19)));
        cSAngle::operator__(acStack736,acStack660);
        cSAngle::operator_(acStack740,*(float *)&this->field_0x3dc);
        cSAngle::operator___(local_28c,acStack740);
      }
    }
    dVar18 = (double)(this->field_0x3c).mDistance;
    (this->field_0x3c).mDistance =
         (float)(dVar18 + (double)(float)(dVar21 * (double)(float)(dVar19 - dVar18)));
    cSAngle::operator__(acStack752,local_28c);
    cSAngle::operator_(acStack756,(float)dVar20);
    cSAngle::operator__(local_2f8,&(this->field_0x3c).mAngleX);
    cSAngle::cSAngle(local_304,local_2f8[0]);
    (this->field_0x3c).mAngleX.v = local_304[0];
    cSAngle::cSAngle(local_308,local_290[0]);
    (this->field_0x3c).mAngleY.v = local_308[0];
    cSGlobe::Xyz(&cStack592,&this->field_0x3c);
    ::cXyz::operator__(&local_25c,&this->field_0x44,&cStack592);
    (this->field_0x50).x = local_25c.x;
    (this->field_0x50).y = local_25c.y;
    (this->field_0x50).z = local_25c.z;
    this->field_0x60 =
         (float)((double)this->field_0x60 +
                (double)(float)(dVar22 * (double)(float)(dVar23 - (double)this->field_0x60)));
    positionOf(&cStack616,this,this->mpPlayerActor);
    (this->mEvBasePos).x = cStack616.y;
  }
  __psq_l0(auStack8,uVar9);
  __psq_l1(auStack8,uVar9);
  __psq_l0(auStack24,uVar9);
  __psq_l1(auStack24,uVar9);
  __psq_l0(auStack40,uVar9);
  __psq_l1(auStack40,uVar9);
  __psq_l0(auStack56,uVar9);
  __psq_l1(auStack56,uVar9);
  __psq_l0(auStack72,uVar9);
  __psq_l1(auStack72,uVar9);
  __psq_l0(auStack88,uVar9);
  __psq_l1(auStack88,uVar9);
  __psq_l0(auStack104,uVar9);
  __psq_l1(auStack104,uVar9);
  __psq_l0(auStack120,uVar9);
  __psq_l1(auStack120,uVar9);
  __psq_l0(auStack136,uVar9);
  __psq_l1(auStack136,uVar9);
  __psq_l0(auStack152,uVar9);
  __psq_l1(auStack152,uVar9);
  __psq_l0(auStack168,uVar9);
  __psq_l1(auStack168,uVar9);
  __psq_l0(auStack184,uVar9);
  __psq_l1(auStack184,uVar9);
  __psq_l0(auStack200,uVar9);
  __psq_l1(auStack200,uVar9);
  return 1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x80177914) */
/* WARNING: Removing unreachable block (ram,0x80177904) */
/* WARNING: Removing unreachable block (ram,0x801778f4) */
/* WARNING: Removing unreachable block (ram,0x801778e4) */
/* WARNING: Removing unreachable block (ram,0x801778d4) */
/* WARNING: Removing unreachable block (ram,0x801778c4) */
/* WARNING: Removing unreachable block (ram,0x801778cc) */
/* WARNING: Removing unreachable block (ram,0x801778dc) */
/* WARNING: Removing unreachable block (ram,0x801778ec) */
/* WARNING: Removing unreachable block (ram,0x801778fc) */
/* WARNING: Removing unreachable block (ram,0x8017790c) */
/* WARNING: Removing unreachable block (ram,0x8017791c) */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall dCamera_c::vomitCamera(long) */

undefined4 __thiscall dCamera_c::vomitCamera(dCamera_c *this,long styleIdx)

{
  int iVar1;
  undefined *puVar2;
  float fVar3;
  undefined4 uVar4;
  cXyz *pcVar5;
  short sVar6;
  fopAc_ac_c *pfVar7;
  cSAngle *this_00;
  undefined4 uVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  undefined8 in_f20;
  undefined8 in_f21;
  double dVar12;
  undefined8 in_f22;
  double dVar13;
  undefined8 in_f23;
  double dVar14;
  undefined8 in_f24;
  double dVar15;
  undefined8 in_f25;
  double dVar16;
  undefined8 in_f26;
  double dVar17;
  undefined8 in_f27;
  double dVar18;
  undefined8 in_f28;
  double dVar19;
  undefined8 in_f29;
  double dVar20;
  undefined8 in_f30;
  double dVar21;
  undefined8 in_f31;
  double dVar22;
  float fVar23;
  cSAngle local_2a8 [2];
  cSAngle local_2a4 [2];
  cSAngle local_2a0 [2];
  cSAngle local_29c [2];
  cSAngle local_298 [2];
  cSAngle acStack660 [2];
  cSAngle acStack656 [2];
  cSAngle acStack652 [2];
  cSAngle acStack648 [2];
  cSAngle local_284 [2];
  cSAngle acStack640 [2];
  cSAngle acStack636 [2];
  cSAngle local_278 [2];
  cSAngle acStack628 [2];
  cSAngle acStack624 [2];
  cSAngle acStack620 [2];
  cSAngle acStack616 [2];
  cSAngle acStack612 [2];
  cSAngle acStack608 [2];
  cSAngle acStack604 [2];
  cSAngle local_258 [2];
  cSAngle local_254 [2];
  cSAngle acStack592 [2];
  float local_24c;
  float local_248;
  cSGlobe local_244;
  cSGlobe local_23c;
  cXyz cStack564;
  cXyz local_228;
  cXyz cStack540;
  cXyz cStack528;
  cXyz cStack516;
  cXyz cStack504;
  cXyz cStack492;
  cXyz cStack480;
  cXyz cStack468;
  cXyz cStack456;
  cXyz cStack444;
  cXyz cStack432;
  cXyz local_1a4;
  cXyz cStack408;
  cXyz cStack396;
  cXyz cStack384;
  cXyz cStack372;
  cXyz cStack360;
  cXyz cStack348;
  cXyz cStack336;
  cXyz local_144;
  cXyz local_138;
  cXyz local_12c;
  cXyz cStack288;
  cXyz cStack276;
  cXyz local_108;
  float local_fc;
  float local_f8;
  float local_f4;
  cXyz local_f0;
  longlong local_e0;
  undefined *local_d8;
  float fStack212;
  undefined auStack184 [16];
  undefined auStack168 [16];
  undefined auStack152 [16];
  undefined auStack136 [16];
  undefined auStack120 [16];
  undefined auStack104 [16];
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar8 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  __psq_st0(auStack72,(int)((ulonglong)in_f27 >> 0x20),0);
  __psq_st1(auStack72,(int)in_f27,0);
  __psq_st0(auStack88,(int)((ulonglong)in_f26 >> 0x20),0);
  __psq_st1(auStack88,(int)in_f26,0);
  __psq_st0(auStack104,(int)((ulonglong)in_f25 >> 0x20),0);
  __psq_st1(auStack104,(int)in_f25,0);
  __psq_st0(auStack120,(int)((ulonglong)in_f24 >> 0x20),0);
  __psq_st1(auStack120,(int)in_f24,0);
  __psq_st0(auStack136,(int)((ulonglong)in_f23 >> 0x20),0);
  __psq_st1(auStack136,(int)in_f23,0);
  __psq_st0(auStack152,(int)((ulonglong)in_f22 >> 0x20),0);
  __psq_st1(auStack152,(int)in_f22,0);
  __psq_st0(auStack168,(int)((ulonglong)in_f21 >> 0x20),0);
  __psq_st1(auStack168,(int)in_f21,0);
  __psq_st0(auStack184,(int)((ulonglong)in_f20 >> 0x20),0);
  __psq_st1(auStack184,(int)in_f20,0);
  local_f0.x = dCamParam_c::styles[styleIdx].field_0xc;
  local_f0.y = dCamParam_c::styles[styleIdx].mCenterHeightBase;
  local_f0.z = dCamParam_c::styles[styleIdx].field_0x8;
  dVar22 = (double)dCamParam_c::styles[styleIdx].mCenterHeightLower;
  dVar21 = (double)dCamParam_c::styles[styleIdx].field_0x14;
  dVar20 = (double)dCamParam_c::styles[styleIdx].field_0x18;
  dVar19 = (double)dCamParam_c::styles[styleIdx].field_0x30;
  dVar12 = (double)dCamParam_c::styles[styleIdx].field_0x34;
  dVar18 = (double)dCamParam_c::styles[styleIdx].field_0x40;
  dVar17 = (double)dCamParam_c::styles[styleIdx].field_0x44;
  dVar16 = (double)dCamParam_c::styles[styleIdx].mLockonLatitudeMax;
  dVar15 = (double)dCamParam_c::styles[styleIdx].mFovyBase;
  dVar14 = (double)dCamParam_c::styles[styleIdx].mLockonFovyMax;
  fVar23 = d_camera::_12164;
  if ((this->mEventFlags & 0x8000) != 0) {
    fVar23 = d_camera::1_0;
  }
  dVar13 = (double)fVar23;
  if (this->field_0x11c == 0) {
    *(undefined4 *)&this->field_0x378 = 0x564d4954;
    (this->mEvBasePos).y = (this->field_0x44).x;
    (this->mEvBasePos).z = (this->field_0x44).y;
    *(float *)&this->field_0x3b8 = (this->field_0x44).z;
    positionOf(&local_108,this,this->mpPlayerActor);
    *(float *)&this->field_0x3bc = local_108.x;
    *(float *)&this->field_0x3c0 = local_108.y;
    *(float *)&this->field_0x3c4 = local_108.z;
    *(float *)&this->field_0x390 = d_camera::0_0;
    *(undefined4 *)&this->field_0x388 = 0;
    positionOf(&cStack276,this,this->mpPlayerActor);
    this->mEvFovy = cStack276.y;
    (this->mEvBasePos).x = cStack276.y;
    fVar23 = d_camera::_8359;
    *(float *)&this->field_0x3d0 = d_camera::_8359;
    *(float *)&this->field_0x3cc = fVar23;
    fVar23 = d_camera::0_0;
    *(float *)&this->field_0x3e4 = d_camera::0_0;
    *(float *)&this->field_0x3e8 = fVar23;
    *(undefined *)&this->field_0x3c8 = 0;
    this->mEvTimer = (int)(float)dVar20;
    *(undefined4 *)&this->field_0x38c = 0;
    relationalPos(&cStack288,this,this->mpPlayerActor,&local_f0);
    ::cXyz::operator__(&local_12c,&this->mCenter,&cStack288);
    local_138.x = local_12c.x;
    local_138.y = local_12c.y;
    local_138.z = local_12c.z;
    fVar23 = mtx::PSVECSquareMag(&local_138);
    dVar10 = (double)fVar23;
    if ((double)d_camera::0_0 < dVar10) {
      dVar9 = 1.0 / SQRT(dVar10);
      dVar9 = d_camera::_5735 * dVar9 * (d_camera::_5736 - dVar10 * dVar9 * dVar9);
      dVar9 = d_camera::_5735 * dVar9 * (d_camera::_5736 - dVar10 * dVar9 * dVar9);
      local_24c = (float)(dVar10 * d_camera::_5735 * dVar9 *
                                   (d_camera::_5736 - dVar10 * dVar9 * dVar9));
      dVar10 = (double)local_24c;
    }
    if (dVar10 < dVar19) {
      dVar10 = dVar19;
    }
    pfVar7 = this->mpPlayerActor;
    if ((pfVar7->parent).parent.mProcName == 0xa9) {
      puVar2 = pfVar7[1].parent.parent.mLyTg.parent.parent.mpData;
    }
    else {
      puVar2 = (undefined *)(d_camera::_8357 * ((pfVar7->mEyePos).y - (pfVar7->mCurrent).mPos.y));
    }
    dVar9 = (double)(float)puVar2;
    if (dVar9 < (double)d_camera::_6064) {
      dVar9 = (double)d_camera::_6064;
    }
    dVar9 = (double)(float)(dVar10 / dVar9);
    directionOf((dCamera_c *)acStack604,(fopAc_ac_c *)this);
    uVar4 = cSAngle::Inv(acStack604);
    SComponent::operator__(acStack608,uVar4,&(this->field_0x3c).mAngleY);
    cSAngle::cSAngle(acStack612,acStack608);
    dVar10 = (double)cSAngle::Norm(acStack612);
    if ((double)d_camera::0_0 < dVar9) {
      dVar11 = 1.0 / SQRT(dVar9);
      dVar11 = d_camera::_5735 * dVar11 * (d_camera::_5736 - dVar9 * dVar11 * dVar11);
      dVar11 = d_camera::_5735 * dVar11 * (d_camera::_5736 - dVar9 * dVar11 * dVar11);
      local_248 = (float)(dVar9 * d_camera::_5735 * dVar11 *
                                  (d_camera::_5736 - dVar9 * dVar11 * dVar11));
      dVar9 = (double)local_248;
    }
    iVar1 = (int)((float)(dVar13 * dVar9) *
                 (d_camera::1_0 + ABS((float)((double)d_camera::_9007 * dVar10))));
    local_e0 = (longlong)iVar1;
    *(int *)&this->field_0x37c = iVar1 + 1;
    fStack212 = (float)(*(int *)&this->field_0x37c * (*(int *)&this->field_0x37c + 1) >> 1 ^
                       0x80000000);
    local_d8 = (undefined *)0x43300000;
    *(float *)&this->field_0x380 = (float)((double)CONCAT44(0x43300000,fStack212) - d_camera::_5738)
    ;
  }
  if (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4] & 0x80U) != 0) {
    positionOf(&local_144,this,this->mpPlayerActor);
    *(float *)&this->field_0x3bc = local_144.x;
    *(float *)&this->field_0x3c0 = local_144.y;
    *(float *)&this->field_0x3c4 = local_144.z;
    positionOf(&cStack336,this,this->mpPlayerActor);
    this->mEvFovy = this->mEvFovy + d_camera::_5311 * (cStack336.y - this->mEvFovy);
  }
  if (*(char *)&this->field_0x100 == '\0') {
    fStack212 = (float)(*(int *)&this->field_0x37c - this->field_0x11c ^ 0x80000000);
    local_d8 = (undefined *)0x43300000;
    *(float *)&this->field_0x384 = (float)((double)CONCAT44(0x43300000,fStack212) - d_camera::_5738)
    ;
    dVar12 = (double)(*(float *)&this->field_0x384 / *(float *)&this->field_0x380);
    relationalPos(&cStack348,this,this->mpPlayerActor,&local_f0);
    ::cXyz::operator__(&cStack360,&cStack348,&this->field_0x44);
    ::cXyz::operator_(&cStack372,&cStack360,(float)dVar12);
    pcVar5 = (cXyz *)&(this->mEvBasePos).y;
    mtx::PSVECAdd(pcVar5,&cStack372,pcVar5);
    ::cXyz::operator__(&cStack384,(cXyz *)&(this->mEvBasePos).y,&this->field_0x44);
    ::cXyz::operator_(&cStack396,&cStack384,(float)dVar21);
    mtx::PSVECAdd(&this->field_0x44,&cStack396,&this->field_0x44);
    cSAngle::cSAngle(acStack592,(float)dVar17);
    directionOf((dCamera_c *)acStack616,(fopAc_ac_c *)this);
    sVar6 = cSAngle::Inv(acStack616);
    cSAngle::cSAngle(acStack620,sVar6);
    cSGlobe::cSGlobe(&local_23c,(float)dVar19,acStack592,acStack620);
    fVar23 = (this->field_0x3c).mDistance;
    (this->field_0x3c).mDistance = fVar23 + (float)(dVar12 * (double)(local_23c.mDistance - fVar23))
    ;
    this_00 = &(this->field_0x3c).mAngleX;
    cSAngle::operator__(acStack624,&local_23c.mAngleX);
    cSAngle::operator_(acStack628,(float)dVar12);
    cSAngle::operator__(local_278,this_00);
    cSAngle::cSAngle(local_29c,local_278[0]);
    (this->field_0x3c).mAngleX.v = local_29c[0];
    cSAngle::operator__(acStack636,&local_23c.mAngleY);
    cSAngle::operator_(acStack640,(float)dVar12);
    cSAngle::operator__(local_284,&(this->field_0x3c).mAngleY);
    cSAngle::cSAngle(local_2a0,local_284[0]);
    (this->field_0x3c).mAngleY.v = local_2a0[0];
    cSGlobe::Xyz(&cStack408,&this->field_0x3c);
    ::cXyz::operator__(&local_1a4,&this->field_0x44,&cStack408);
    (this->field_0x50).x = local_1a4.x;
    (this->field_0x50).y = local_1a4.y;
    (this->field_0x50).z = local_1a4.z;
    dVar20 = (double)cSAngle::Degree(this_00);
    *(float *)this->mEvRelUseMask = (float)dVar20;
    pfVar7 = (fopAc_ac_c *)(this->field_0x3c).mDistance;
    this->mpEvRelActor = pfVar7;
    this->mEvBank = (float)pfVar7;
    this->field_0x60 =
         (float)((double)this->field_0x60 +
                (double)(float)(dVar12 * (double)(float)(dVar15 - (double)this->field_0x60)));
    *(float *)&this->field_0x380 = *(float *)&this->field_0x380 - *(float *)&this->field_0x384;
    if (*(int *)&this->field_0x37c - 1U <= (uint)this->field_0x11c) {
      *(undefined *)&this->field_0x102 = 1;
      *(undefined *)&this->field_0x101 = 1;
      *(undefined *)&this->field_0x100 = 1;
      *(float *)&this->field_0x384 = d_camera::0_0;
    }
  }
  else {
    dVar13 = dVar20;
    positionOf(&cStack432,this,this->mpPlayerActor);
    dVar10 = (double)d_camera::1_0;
    if ((float)((double)this->mEvFovy - dVar10) <= cStack432.y) {
      positionOf(&cStack444,this,this->mpPlayerActor);
      positionOf(&cStack456,this,this->mpPlayerActor);
      fVar3 = d_camera::0_0;
      fVar23 = d_camera::1_0 - (float)((double)(cStack456.y - this->mEvFovy) / dVar22);
      local_f0.y = local_f0.y * fVar23;
      local_f0.z = local_f0.z * fVar23;
      this->mEvTimer = (int)d_camera::0_0;
      *(float *)&this->field_0x384 = fVar3;
    }
    else {
      *(float *)&this->field_0x384 = (float)((double)*(float *)&this->field_0x384 + dVar10);
      this->mEvTimer =
           (int)((float)this->mEvTimer +
                d_camera::_6065 * *(float *)&this->field_0x384 *
                ((float)(dVar10 - dVar13) - (float)this->mEvTimer));
      dVar20 = (double)(float)(dVar13 + (double)(float)this->mEvTimer);
    }
    local_fc = (float)dVar21;
    local_f8 = (float)dVar20;
    local_f4 = (float)dVar21;
    relationalPos(&cStack468,this,this->mpPlayerActor,&local_f0);
    ::cXyz::operator__(&cStack480,&cStack468,&this->field_0x44);
    ::cXyz::operator_(&cStack492,(Vec *)&cStack480);
    mtx::PSVECAdd(&this->field_0x44,&cStack492,&this->field_0x44);
    ::cXyz::operator__(&cStack504,&this->field_0x50,&this->field_0x44);
    cSGlobe::cSGlobe(&local_244,&cStack504);
    dVar20 = (double)local_244.mDistance;
    if (dVar20 < dVar12) {
      dVar20 = dVar12;
    }
    local_254[0] = local_244.mAngleX;
    dVar12 = dVar20;
    directionOf((dCamera_c *)acStack648,(fopAc_ac_c *)this);
    sVar6 = cSAngle::Inv(acStack648);
    cSAngle::Val(local_258,sVar6);
    if (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4] & 0x80000000U) == 0) {
      if (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4] & 0x80U) == 0) {
        *(undefined4 *)&this->field_0x38c = 0;
      }
      else {
        cSAngle::Val(local_254,(float)dVar17);
        directionOf((dCamera_c *)acStack652,(fopAc_ac_c *)this);
        sVar6 = cSAngle::Inv(acStack652);
        cSAngle::Val(local_258,sVar6);
        *(undefined4 *)&this->field_0x38c = 0;
        dVar20 = dVar19;
      }
    }
    else {
      positionOf(&cStack516,this,this->mpPlayerActor);
      if (this->mEvFovy - d_camera::1_0 <= cStack516.y) {
        positionOf(&cStack528,this,this->mpPlayerActor);
        if ((cStack528.y < (this->mEvBasePos).x) && (dVar19 < dVar12)) {
          dVar20 = dVar19;
        }
      }
      else {
        *(int *)&this->field_0x38c = *(int *)&this->field_0x38c + 1;
        dVar20 = dVar19;
      }
    }
    dVar19 = (double)(this->field_0x3c).mDistance;
    (this->field_0x3c).mDistance =
         (float)(dVar19 + (double)(float)(dVar18 * (double)(float)(dVar20 - dVar19)));
    cSAngle::operator__(acStack656,local_254);
    cSAngle::operator_(acStack660,(float)dVar16);
    cSAngle::operator__(local_298,&(this->field_0x3c).mAngleX);
    cSAngle::cSAngle(local_2a4,local_298[0]);
    (this->field_0x3c).mAngleX.v = local_2a4[0];
    cSAngle::cSAngle(local_2a8,local_258[0]);
    (this->field_0x3c).mAngleY.v = local_2a8[0];
    cSGlobe::Xyz(&cStack540,&this->field_0x3c);
    ::cXyz::operator__(&local_228,&this->field_0x44,&cStack540);
    (this->field_0x50).x = local_228.x;
    (this->field_0x50).y = local_228.y;
    (this->field_0x50).z = local_228.z;
    this->field_0x60 =
         (float)((double)this->field_0x60 +
                (double)(float)(dVar14 * (double)(float)(dVar15 - (double)this->field_0x60)));
    positionOf(&cStack564,this,this->mpPlayerActor);
    (this->mEvBasePos).x = cStack564.y;
  }
  __psq_l0(auStack8,uVar8);
  __psq_l1(auStack8,uVar8);
  __psq_l0(auStack24,uVar8);
  __psq_l1(auStack24,uVar8);
  __psq_l0(auStack40,uVar8);
  __psq_l1(auStack40,uVar8);
  __psq_l0(auStack56,uVar8);
  __psq_l1(auStack56,uVar8);
  __psq_l0(auStack72,uVar8);
  __psq_l1(auStack72,uVar8);
  __psq_l0(auStack88,uVar8);
  __psq_l1(auStack88,uVar8);
  __psq_l0(auStack104,uVar8);
  __psq_l1(auStack104,uVar8);
  __psq_l0(auStack120,uVar8);
  __psq_l1(auStack120,uVar8);
  __psq_l0(auStack136,uVar8);
  __psq_l1(auStack136,uVar8);
  __psq_l0(auStack152,uVar8);
  __psq_l1(auStack152,uVar8);
  __psq_l0(auStack168,uVar8);
  __psq_l1(auStack168,uVar8);
  __psq_l0(auStack184,uVar8);
  __psq_l1(auStack184,uVar8);
  return 1;
}


/* WARNING: Inlined function: FUN_80328f0c */
/* WARNING: Inlined function: FUN_80328f58 */
/* WARNING: Removing unreachable block (ram,0x80178790) */
/* WARNING: Removing unreachable block (ram,0x80178780) */
/* WARNING: Removing unreachable block (ram,0x80178770) */
/* WARNING: Removing unreachable block (ram,0x80178760) */
/* WARNING: Removing unreachable block (ram,0x80178768) */
/* WARNING: Removing unreachable block (ram,0x80178778) */
/* WARNING: Removing unreachable block (ram,0x80178788) */
/* WARNING: Removing unreachable block (ram,0x80178798) */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall dCamera_c::shieldCamera(long) */

undefined4 __thiscall dCamera_c::shieldCamera(dCamera_c *this,long param_1)

{
  int iVar1;
  undefined *puVar2;
  undefined4 uVar3;
  cXyz *this_00;
  cM3dGPla *pcVar4;
  short sVar6;
  char cVar7;
  cSAngle *pcVar5;
  fopAc_ac_c *pfVar8;
  fopAc_ac_c *pfVar9;
  cBgS_PolyPassChk *pcVar10;
  undefined4 uVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  double extraout_f1;
  undefined8 in_f24;
  undefined8 in_f25;
  double dVar15;
  undefined8 in_f26;
  double dVar16;
  undefined8 in_f27;
  double dVar17;
  undefined8 in_f28;
  double dVar18;
  undefined8 in_f29;
  double dVar19;
  undefined8 in_f30;
  double dVar20;
  undefined8 in_f31;
  double dVar21;
  float fVar22;
  cSAngle local_338 [2];
  cSAngle local_334 [2];
  cSAngle local_330 [2];
  cSAngle local_32c [2];
  cSAngle local_328 [2];
  cSAngle local_324 [2];
  cSAngle local_320 [2];
  cSAngle local_31c [2];
  cSAngle local_318 [2];
  cSAngle acStack788 [2];
  cSAngle acStack784 [2];
  cSAngle acStack780 [2];
  cSAngle acStack776 [2];
  cSAngle local_304 [2];
  cSAngle acStack768 [2];
  cSAngle acStack764 [2];
  cSAngle acStack760 [2];
  cSAngle acStack756 [2];
  cSAngle acStack752 [2];
  cSAngle local_2ec [2];
  cSAngle acStack744 [2];
  cSAngle acStack740 [2];
  cSAngle local_2e0 [2];
  cSAngle acStack732 [2];
  cSAngle acStack728 [2];
  cSAngle acStack724 [2];
  cSAngle acStack720 [2];
  cSAngle acStack716 [2];
  cSAngle acStack712 [2];
  cSAngle acStack708 [2];
  cSAngle acStack704 [2];
  cSAngle local_2bc [4];
  cSAngle acStack692 [2];
  cSAngle local_2b0 [2];
  cSAngle local_2ac [4];
  cSAngle acStack676 [2];
  cSAngle local_2a0 [2];
  cSAngle acStack668 [2];
  cSAngle acStack664 [2];
  cSAngle acStack660 [2];
  cSAngle acStack656 [2];
  float local_28c;
  float local_288;
  cSGlobe local_284;
  cSGlobe cStack636;
  cXyz local_274;
  cXyz cStack616;
  cXyz local_25c;
  cXyz local_250;
  cXyz cStack580;
  cXyz local_238;
  cXyz cStack556;
  cXyz cStack544;
  cXyz local_214;
  cXyz local_208;
  cXyz local_1fc;
  cXyz cStack496;
  cXyz cStack484;
  cXyz local_1d8;
  cXyz local_1cc;
  cXyz local_1c0;
  cXyz local_1b4;
  dBgS_LinChk local_1a8;
  undefined local_13c [104];
  undefined *local_d4;
  longlong local_d0;
  float local_c8;
  float fStack196;
  undefined auStack120 [16];
  undefined auStack104 [16];
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar11 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  __psq_st0(auStack72,(int)((ulonglong)in_f27 >> 0x20),0);
  __psq_st1(auStack72,(int)in_f27,0);
  __psq_st0(auStack88,(int)((ulonglong)in_f26 >> 0x20),0);
  __psq_st1(auStack88,(int)in_f26,0);
  __psq_st0(auStack104,(int)((ulonglong)in_f25 >> 0x20),0);
  __psq_st1(auStack104,(int)in_f25,0);
  __psq_st0(auStack120,(int)((ulonglong)in_f24 >> 0x20),0);
  __psq_st1(auStack120,(int)in_f24,0);
  local_1b4.x = dCamParam_c::styles[param_1].field_0xc;
  local_1b4.y = dCamParam_c::styles[param_1].mCenterHeightBase;
  local_1b4.z = dCamParam_c::styles[param_1].field_0x8;
  dVar21 = (double)dCamParam_c::styles[param_1].field_0x30;
  dVar20 = (double)dCamParam_c::styles[param_1].field_0x34;
  dVar19 = (double)dCamParam_c::styles[param_1].field_0x44;
  dVar18 = (double)dCamParam_c::styles[param_1].mLockonLongitudeMin;
  dVar17 = (double)dCamParam_c::styles[param_1].mLockonLatitudeMin;
  dVar16 = (double)dCamParam_c::styles[param_1].mFovyBase;
  dVar15 = (double)*(float *)&dCamParam_c::styles[param_1].field_0x58;
  cSGlobe::cSGlobe(&cStack636,&local_1b4);
  pfVar9 = this->mpPlayerActor;
  sVar6 = (pfVar9->parent).parent.mProcName;
  if (sVar6 == 0xa9) {
    cSAngle::operator__(local_2a0,&cStack636.mAngleX,
                        *(short *)&pfVar9[1].parent.parent.mLyTg.parent.mpTagData);
    cSAngle::cSAngle(local_31c,local_2a0[0]);
    cStack636.mAngleX = local_31c[0];
    cSAngle::operator__(acStack676,(short)register0x00000004 + -0x276);
    directionOf((dCamera_c *)(local_2ac + 2),(fopAc_ac_c *)this);
    cSAngle::operator__(local_2ac,acStack676);
    cSAngle::cSAngle(local_320,local_2ac[0]);
    cStack636.mAngleY = local_320[0];
  }
  else {
    if (sVar6 == 0x171) {
      cSAngle::operator__(local_2b0,&cStack636.mAngleX,pfVar9[0x13].parent.parent.mDtTg.mTimer);
      cSAngle::cSAngle(local_324,local_2b0[0]);
      cStack636.mAngleX = local_324[0];
      cSAngle::operator__(acStack692,(short)register0x00000004 + -0x276);
      directionOf((dCamera_c *)(local_2bc + 2),(fopAc_ac_c *)this);
      cSAngle::operator__(local_2bc,acStack692);
      cSAngle::cSAngle(local_328,local_2bc[0]);
      cStack636.mAngleY = local_328[0];
    }
  }
  attentionPos(&cStack484,this,this->mpPlayerActor);
  cSGlobe::Xyz(&cStack496,&cStack636);
  ::cXyz::operator__(&local_1fc,&cStack484,&cStack496);
  local_1c0.x = local_1fc.x;
  local_1c0.y = local_1fc.y;
  local_1c0.z = local_1fc.z;
  if (this->field_0x11c == 0) {
    *(undefined4 *)&this->field_0x378 = 0x53484c44;
    ::cXyz::operator__(&local_208,&this->mCenter,&local_1c0);
    local_214.x = local_208.x;
    local_214.y = local_208.y;
    local_214.z = local_208.z;
    fVar22 = mtx::PSVECSquareMag(&local_214);
    dVar14 = (double)fVar22;
    if ((double)d_camera::0_0 < dVar14) {
      dVar12 = 1.0 / SQRT(dVar14);
      dVar12 = d_camera::_5735 * dVar12 * (d_camera::_5736 - dVar14 * dVar12 * dVar12);
      dVar12 = d_camera::_5735 * dVar12 * (d_camera::_5736 - dVar14 * dVar12 * dVar12);
      local_28c = (float)(dVar14 * d_camera::_5735 * dVar12 *
                                   (d_camera::_5736 - dVar14 * dVar12 * dVar12));
      dVar14 = (double)local_28c;
    }
    if (dVar14 < dVar21) {
      dVar14 = dVar21;
    }
    pfVar9 = this->mpPlayerActor;
    if ((pfVar9->parent).parent.mProcName == 0xa9) {
      puVar2 = pfVar9[1].parent.parent.mLyTg.parent.parent.mpData;
    }
    else {
      puVar2 = (undefined *)(d_camera::_8357 * ((pfVar9->mEyePos).y - (pfVar9->mCurrent).mPos.y));
    }
    dVar12 = (double)(float)puVar2;
    if (dVar12 < (double)d_camera::_6064) {
      dVar12 = (double)d_camera::_6064;
    }
    dVar12 = (double)(float)(dVar14 / dVar12);
    directionOf((dCamera_c *)acStack704,(fopAc_ac_c *)this);
    uVar3 = cSAngle::Inv(acStack704);
    SComponent::operator__(acStack708,uVar3,&(this->field_0x3c).mAngleY);
    cSAngle::cSAngle(acStack712,acStack708);
    dVar14 = (double)cSAngle::Norm(acStack712);
    if ((double)d_camera::0_0 < dVar12) {
      dVar13 = 1.0 / SQRT(dVar12);
      dVar13 = d_camera::_5735 * dVar13 * (d_camera::_5736 - dVar12 * dVar13 * dVar13);
      dVar13 = d_camera::_5735 * dVar13 * (d_camera::_5736 - dVar12 * dVar13 * dVar13);
      local_288 = (float)(dVar12 * d_camera::_5735 * dVar13 *
                                   (d_camera::_5736 - dVar12 * dVar13 * dVar13));
      dVar12 = (double)local_288;
    }
    iVar1 = (int)((float)((double)d_camera::_12161 * dVar12) *
                 (d_camera::1_0 + ABS((float)((double)d_camera::_9007 * dVar14))));
    local_d0 = (longlong)iVar1;
    *(int *)&this->field_0x37c = iVar1 + 1;
    fStack196 = (float)(*(int *)&this->field_0x37c * (*(int *)&this->field_0x37c + 1) >> 1 ^
                       0x80000000);
    local_c8 = 176.0;
    *(float *)&this->field_0x380 = (float)((double)CONCAT44(0x43300000,fStack196) - d_camera::_5738)
    ;
  }
  if (*(char *)&this->field_0x100 == '\0') {
    fStack196 = (float)(*(int *)&this->field_0x37c - this->field_0x11c ^ 0x80000000);
    local_c8 = 176.0;
    *(float *)&this->field_0x384 = (float)((double)CONCAT44(0x43300000,fStack196) - d_camera::_5738)
    ;
    dVar15 = (double)(*(float *)&this->field_0x384 / *(float *)&this->field_0x380);
    ::cXyz::operator__(&cStack544,&local_1c0,&this->field_0x44);
    ::cXyz::operator_(&cStack556,&cStack544,(float)dVar15);
    mtx::PSVECAdd(&this->field_0x44,&cStack556,&this->field_0x44);
    attentionPos(&local_238,this,this->mpPlayerActor);
    local_1cc.x = local_238.x;
    local_1cc.z = local_238.z;
    local_1cc.y = local_238.y - d_camera::_10146;
    local_13c._0_4_ = (cBgS_PolyPassChk *)0x0;
    local_13c._4_4_ = (cBgS_PolyPassChk *)0x0;
    local_13c[12] = true;
    local_13c._20_2_ = 0xffff;
    local_13c._22_2_ = 0x100;
    local_13c._24_4_ = (cBgW *)0x0;
    local_13c._28_4_ = &DAT_ffffffff;
    local_13c._16_4_ = &::cBgS_LinChk::__vt;
    local_13c._32_4_ = &PTR_80371fbc;
    local_13c._60_4_ = &::cM3dGLin::__vt;
    ::cBgS_LinChk::ct((cBgS_LinChk *)local_13c);
    pcVar10 = (cBgS_PolyPassChk *)(local_13c + 0x58);
    local_13c[92] = 0;
    local_13c[94] = 0;
    local_13c[95] = 0;
    local_13c[96] = 0;
    local_13c[97] = 0;
    local_13c[98] = 0;
    local_13c._4_4_ = pcVar10;
    if (pcVar10 != (cBgS_PolyPassChk *)0x0) {
      local_13c._4_4_ = (cBgS_PolyPassChk *)(local_13c + 100);
    }
    local_13c[93] = 1;
    local_13c._16_4_ = (undefined **)&dBgS_CamLinChk_NorWtr::__vt;
    local_13c._32_4_ = (undefined **)&DAT_803910b0;
    local_13c._88_4_ = (undefined **)&DAT_803910bc;
    local_13c._100_4_ = (undefined **)&DAT_803910c8;
    local_d4 = &DAT_00000003;
    local_13c._0_4_ = pcVar10;
    this_00 = (cXyz *)dCamMath::xyzHorizontalDistance(&local_1c0,&this->field_0x44);
    fVar22 = local_1b4.z;
    if (local_1b4.z < local_1b4.x) {
      fVar22 = local_1b4.x;
    }
    if ((extraout_f1 < (double)(d_camera::_9008 + ABS(fVar22))) &&
       (this_00 = (cXyz *)lineBGCheck(this,&local_1cc,&this->field_0x44,(dBgS_LinChk *)local_13c,
                                      0x7f), ((uint)this_00 & 0xff) != 0)) {
      pcVar4 = cBgS::GetTriPla((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                               (uint)local_13c._22_2_,(uint)local_13c._20_2_);
      (this->field_0x44).x = local_13c._48_4_;
      (this->field_0x44).y = local_13c._52_4_;
      (this->field_0x44).z = local_13c._56_4_;
      this_00 = &this->field_0x44;
      mtx::PSVECAdd(this_00,(cXyz *)pcVar4,this_00);
    }
    dVar17 = (double)@unnamed@d_camera_cpp@::limitf
                               ((_unnamed_d_camera_cpp_ *)this_00,(this->field_0x3c).mDistance,
                                (float)dVar20,(float)dVar21);
    cSAngle::cSAngle(acStack716,(float)dVar19);
    directionOf((dCamera_c *)acStack720,(fopAc_ac_c *)this);
    sVar6 = cSAngle::Inv(acStack720);
    cSAngle::cSAngle(acStack724,sVar6);
    cSGlobe::cSGlobe(&local_284,(float)dVar17,acStack716,acStack724);
    fVar22 = (this->field_0x3c).mDistance;
    (this->field_0x3c).mDistance = fVar22 + (float)(dVar15 * (double)(local_284.mDistance - fVar22))
    ;
    pcVar5 = &(this->field_0x3c).mAngleX;
    cSAngle::operator__(acStack728,&local_284.mAngleX);
    cSAngle::operator_(acStack732,(float)dVar15);
    cSAngle::operator__(local_2e0,pcVar5);
    cSAngle::cSAngle(local_32c,local_2e0[0]);
    (this->field_0x3c).mAngleX.v = local_32c[0];
    cSAngle::operator__(acStack740,&local_284.mAngleY);
    cSAngle::operator_(acStack744,(float)dVar15);
    cSAngle::operator__(local_2ec,&(this->field_0x3c).mAngleY);
    cSAngle::cSAngle(local_330,local_2ec[0]);
    (this->field_0x3c).mAngleY.v = local_330[0];
    cSGlobe::Xyz(&cStack580,&this->field_0x3c);
    ::cXyz::operator__(&local_250,&this->field_0x44,&cStack580);
    (this->field_0x50).x = local_250.x;
    (this->field_0x50).y = local_250.y;
    (this->field_0x50).z = local_250.z;
    dVar17 = (double)cSAngle::Degree(pcVar5);
    *(float *)&this->field_0x390 = (float)dVar17;
    fVar22 = (this->field_0x3c).mDistance;
    *(float *)&this->field_0x38c = fVar22;
    *(float *)&this->field_0x388 = fVar22;
    this->field_0x60 =
         (float)((double)this->field_0x60 +
                (double)(float)(dVar15 * (double)(float)(dVar16 - (double)this->field_0x60)));
    *(float *)&this->field_0x380 = *(float *)&this->field_0x380 - *(float *)&this->field_0x384;
    if (*(int *)&this->field_0x37c - 1U <= (uint)this->field_0x11c) {
      *(undefined *)&this->field_0x102 = 1;
      *(undefined *)&this->field_0x101 = 1;
      *(undefined *)&this->field_0x100 = 1;
      *(float *)&this->field_0x384 = d_camera::0_0;
    }
    local_13c._88_4_ = &PTR_80371f44;
    local_13c._100_4_ = &PTR_80371f50;
    if (pcVar10 != (cBgS_PolyPassChk *)0x0) {
      local_13c._88_4_ = &::dBgS_Chk::__vt;
      local_13c._100_4_ = &PTR_80371f68;
      if (((undefined *)register0x00000004 != (undefined *)0xd8) &&
         (local_13c._100_4_ = &::dBgS_GrpPassChk::__vt,
         (undefined *)register0x00000004 != (undefined *)0xd8)) {
        local_13c._100_4_ = &::cBgS_GrpPassChk::__vt;
      }
      if ((pcVar10 != (cBgS_PolyPassChk *)0x0) &&
         (local_13c._88_4_ = &::dBgS_PolyPassChk::__vt, pcVar10 != (cBgS_PolyPassChk *)0x0)) {
        local_13c._88_4_ = &::cBgS_PolyPassChk::__vt;
      }
    }
    local_13c._16_4_ = &::cBgS_LinChk::__vt;
    local_13c._60_4_ = &::cM3dGLin::__vt;
    local_13c._32_4_ = &::cBgS_PolyInfo::__vt;
    cBgS_Chk::_cBgS_Chk((cBgS_Chk *)local_13c);
  }
  else {
    (this->field_0x44).x = local_1c0.x;
    (this->field_0x44).y = local_1c0.y;
    (this->field_0x44).z = local_1c0.z;
    attentionPos(&local_25c,this,this->mpPlayerActor);
    local_1d8.x = local_25c.x;
    local_1d8.z = local_25c.z;
    local_1d8.y = local_25c.y - d_camera::_10146;
    local_1a8.parent.parent.mpPolyPassChk = (cBgS_PolyPassChk *)0x0;
    local_1a8.parent.parent.mpGrpPassChk = (cBgS_GrpPassChk *)0x0;
    local_1a8.parent.parent.mbExcludeSameProcID = true;
    local_1a8.parent.mPolyInfo.mTriIdx = 0xffff;
    local_1a8.parent.mPolyInfo.mBgIndex = 0x100;
    local_1a8.parent.mPolyInfo.mpBgW = (cBgW *)0x0;
    local_1a8.parent.mPolyInfo.mProcID = (int)&DAT_ffffffff;
    local_1a8.parent.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_LinChk::__vt;
    local_1a8.parent.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&PTR_80371fbc;
    local_1a8.parent.mLin.vtbl = (undefined *)&::cM3dGLin::__vt;
    ::cBgS_LinChk::ct(&local_1a8.parent);
    pfVar9 = (fopAc_ac_c *)&local_1a8.mPolyPassChk;
    local_1a8.mPolyPassChk.parent.mbObjThrough = 0;
    local_1a8.mPolyPassChk.parent.mbLinkThrough = 0;
    local_1a8.mPolyPassChk.parent.mbArrowsAndLightThrough = 0;
    local_1a8.mPolyPassChk.parent.mbBombThrough = 0;
    local_1a8.mPolyPassChk.parent.mbBoomerangThrough = 0;
    local_1a8.mPolyPassChk.parent.mbHookshotThrough = 0;
    local_1a8.parent.parent.mpGrpPassChk = (cBgS_GrpPassChk *)pfVar9;
    if (pfVar9 != (fopAc_ac_c *)0x0) {
      local_1a8.parent.parent.mpGrpPassChk = (cBgS_GrpPassChk *)&local_1a8.mGrpPassChk;
    }
    local_1a8.mPolyPassChk.parent.mbCamThrough = 1;
    local_1a8.parent.parent.vtbl = (cBgS_Chk__vtbl *)&dBgS_CamLinChk_NorWtr::__vt;
    local_1a8.parent.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&DAT_803910b0;
    local_1a8.mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&DAT_803910bc;
    local_1a8.mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&DAT_803910c8;
    local_1a8.mGrpPassChk.parent.mAttr = (uint)&DAT_00000003;
    local_1a8.parent.parent.mpPolyPassChk = (cBgS_PolyPassChk *)pfVar9;
    cVar7 = lineBGCheck(this,&local_1d8,&this->field_0x44,&local_1a8,0x7f);
    if (cVar7 != '\0') {
      pcVar4 = cBgS::GetTriPla((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                               (uint)(ushort)local_1a8.parent.mPolyInfo.mBgIndex,
                               (uint)(ushort)local_1a8.parent.mPolyInfo.mTriIdx);
      (this->field_0x44).x = local_1a8.parent.mLin.mP1.x;
      (this->field_0x44).y = local_1a8.parent.mLin.mP1.y;
      (this->field_0x44).z = local_1a8.parent.mLin.mP1.z;
      mtx::PSVECAdd(&this->field_0x44,(cXyz *)pcVar4,&this->field_0x44);
    }
    cSAngle::cSAngle(acStack656,(float)dVar19);
    directionOf((dCamera_c *)acStack752,(fopAc_ac_c *)this);
    sVar6 = cSAngle::Inv(acStack752);
    cSAngle::cSAngle(acStack664,sVar6);
    pfVar8 = this->mpPlayerActor;
    sVar6 = (pfVar8->parent).parent.mProcName;
    if (sVar6 == 0xa9) {
      cSAngle::Val(acStack660,*(short *)&pfVar8[1].parent.parent.mLyTg.parent.mpTagData);
      cSAngle::Val(acStack668,*(short *)((int)&pfVar8[1].parent.parent.mLyTg.parent.mpTagData + 2));
    }
    else {
      if (sVar6 == 0x171) {
        cSAngle::Val(acStack660,pfVar8[0x13].parent.parent.mDtTg.mTimer);
        cSAngle::Val(acStack668,*(short *)&pfVar8[0x13].parent.parent.mDtTg.field_0x1a);
      }
      else {
        cSAngle::Val(acStack660,0);
        cSAngle::Val(acStack668,0);
      }
    }
    cSAngle::operator_(acStack756,(float)dVar17);
    cSAngle::operator__(acStack760,acStack656);
    cSAngle::operator__(acStack764,acStack760);
    cSAngle::operator_(acStack768,(float)dVar15);
    cSAngle::operator__(local_304,&(this->field_0x3c).mAngleX);
    cSAngle::cSAngle(local_334,local_304[0]);
    (this->field_0x3c).mAngleX.v = local_334[0];
    cSAngle::operator_(acStack776,(float)dVar18);
    cSAngle::operator__(acStack780,acStack664);
    cSAngle::operator__(acStack784,acStack780);
    cSAngle::operator_(acStack788,(float)dVar15);
    cSAngle::operator__(local_318,&(this->field_0x3c).mAngleY);
    pcVar5 = local_338;
    cSAngle::cSAngle(pcVar5,local_318[0]);
    (this->field_0x3c).mAngleY.v = local_338[0];
    dVar17 = (double)@unnamed@d_camera_cpp@::limitf
                               ((_unnamed_d_camera_cpp_ *)pcVar5,(this->field_0x3c).mDistance,
                                (float)dVar20,(float)dVar21);
    dVar18 = (double)(this->field_0x3c).mDistance;
    (this->field_0x3c).mDistance =
         (float)(dVar18 + (double)(float)(dVar15 * (double)(float)(dVar17 - dVar18)));
    cSGlobe::Xyz(&cStack616,&this->field_0x3c);
    ::cXyz::operator__(&local_274,&this->field_0x44,&cStack616);
    (this->field_0x50).x = local_274.x;
    (this->field_0x50).y = local_274.y;
    (this->field_0x50).z = local_274.z;
    this->field_0x60 =
         (float)((double)this->field_0x60 +
                (double)(float)(dVar15 * (double)(float)(dVar16 - (double)this->field_0x60)));
    local_1a8.mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f44;
    local_1a8.mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_80371f50;
    if (pfVar9 != (fopAc_ac_c *)0x0) {
      local_1a8.mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
      local_1a8.mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&PTR_80371f68;
      if (((undefined *)register0x00000004 != (undefined *)0x144) &&
         (local_1a8.mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&::dBgS_GrpPassChk::__vt,
         (undefined *)register0x00000004 != (undefined *)0x144)) {
        local_1a8.mGrpPassChk.parent.vtbl = (cBgS_GrpPassChk__vtbl *)&::cBgS_GrpPassChk::__vt;
      }
      if ((pfVar9 != (fopAc_ac_c *)0x0) &&
         (local_1a8.mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
         pfVar9 != (fopAc_ac_c *)0x0)) {
        local_1a8.mPolyPassChk.parent.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
      }
    }
    local_1a8.parent.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_LinChk::__vt;
    local_1a8.parent.mLin.vtbl = (undefined *)&::cM3dGLin::__vt;
    local_1a8.parent.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
    cBgS_Chk::_cBgS_Chk((cBgS_Chk *)&local_1a8);
  }
  __psq_l0(auStack8,uVar11);
  __psq_l1(auStack8,uVar11);
  __psq_l0(auStack24,uVar11);
  __psq_l1(auStack24,uVar11);
  __psq_l0(auStack40,uVar11);
  __psq_l1(auStack40,uVar11);
  __psq_l0(auStack56,uVar11);
  __psq_l1(auStack56,uVar11);
  __psq_l0(auStack72,uVar11);
  __psq_l1(auStack72,uVar11);
  __psq_l0(auStack88,uVar11);
  __psq_l1(auStack88,uVar11);
  __psq_l0(auStack104,uVar11);
  __psq_l1(auStack104,uVar11);
  __psq_l0(auStack120,uVar11);
  __psq_l1(auStack120,uVar11);
  return 1;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x801795a0) */
/* WARNING: Removing unreachable block (ram,0x80179590) */
/* WARNING: Removing unreachable block (ram,0x80179580) */
/* WARNING: Removing unreachable block (ram,0x80179570) */
/* WARNING: Removing unreachable block (ram,0x80179560) */
/* WARNING: Removing unreachable block (ram,0x80179550) */
/* WARNING: Removing unreachable block (ram,0x80179540) */
/* WARNING: Removing unreachable block (ram,0x80179530) */
/* WARNING: Removing unreachable block (ram,0x80179520) */
/* WARNING: Removing unreachable block (ram,0x80179528) */
/* WARNING: Removing unreachable block (ram,0x80179538) */
/* WARNING: Removing unreachable block (ram,0x80179548) */
/* WARNING: Removing unreachable block (ram,0x80179558) */
/* WARNING: Removing unreachable block (ram,0x80179568) */
/* WARNING: Removing unreachable block (ram,0x80179578) */
/* WARNING: Removing unreachable block (ram,0x80179588) */
/* WARNING: Removing unreachable block (ram,0x80179598) */
/* WARNING: Removing unreachable block (ram,0x801795a8) */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall dCamera_c::manualCamera(long) */

undefined4 __thiscall dCamera_c::manualCamera(dCamera_c *this,long param_1)

{
  float fVar1;
  bool bVar2;
  int iVar3;
  char cVar5;
  cM3dGPla *pcVar4;
  uint uVar6;
  cSAngle *this_00;
  undefined4 uVar7;
  undefined8 in_f14;
  undefined8 in_f15;
  double dVar8;
  undefined8 in_f16;
  double dVar9;
  undefined8 in_f17;
  double dVar10;
  undefined8 in_f18;
  double dVar11;
  undefined8 in_f19;
  double dVar12;
  undefined8 in_f20;
  double dVar13;
  undefined8 in_f21;
  double dVar14;
  undefined8 in_f22;
  double dVar15;
  undefined8 in_f23;
  double dVar16;
  undefined8 in_f24;
  double dVar17;
  undefined8 in_f25;
  double dVar18;
  undefined8 in_f26;
  double dVar19;
  undefined8 in_f27;
  double dVar20;
  double dVar21;
  undefined8 in_f28;
  double dVar22;
  undefined8 in_f29;
  double dVar23;
  undefined8 in_f30;
  double dVar24;
  undefined8 in_f31;
  double dVar25;
  float fVar26;
  cSAngle local_418 [2];
  cSAngle local_414 [2];
  cSAngle acStack1040 [2];
  cSAngle acStack1036 [2];
  cSAngle acStack1032 [2];
  cSAngle local_404 [2];
  cSAngle acStack1024 [2];
  cSAngle acStack1020 [2];
  cSAngle local_3f8 [2];
  cSAngle acStack1012 [2];
  cSAngle acStack1008 [2];
  cSAngle acStack1004 [2];
  float local_3e8;
  float local_3e4;
  float local_3e0;
  float local_3dc;
  float local_3d8;
  cXyz local_3d4;
  cXyz local_3c8;
  cXyz cStack956;
  cXyz cStack944;
  cXyz local_3a4;
  cXyz cStack920;
  cXyz cStack908;
  cXyz local_380;
  cXyz local_374;
  cXyz local_368;
  cXyz cStack860;
  cXyz local_350;
  cXyz local_344;
  cXyz cStack824;
  cXyz local_32c;
  cXyz local_320;
  camera_class *local_314;
  undefined4 local_310;
  float local_30c;
  cXyz cStack776;
  cXyz local_2fc;
  cXyz local_2f0;
  cXyz local_2e4;
  float local_2d8;
  float local_2d4;
  float local_2d0;
  cXyz local_2cc;
  cXyz local_2c0;
  float local_2b4;
  float local_2b0;
  float local_2ac;
  dBgS_LinChk dStack680;
  dBgS_LinChk dStack572;
  dBgS_LinChk dStack464;
  longlong local_160;
  longlong local_158;
  float local_150;
  float local_14c;
  float local_148;
  float local_144;
  float local_140;
  float local_13c;
  undefined auStack280 [16];
  undefined auStack264 [16];
  undefined auStack248 [16];
  undefined auStack232 [16];
  undefined auStack216 [16];
  undefined auStack200 [16];
  undefined auStack184 [16];
  undefined auStack168 [16];
  undefined auStack152 [16];
  undefined auStack136 [16];
  undefined auStack120 [16];
  undefined auStack104 [16];
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar7 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  __psq_st0(auStack72,(int)((ulonglong)in_f27 >> 0x20),0);
  __psq_st1(auStack72,(int)in_f27,0);
  __psq_st0(auStack88,(int)((ulonglong)in_f26 >> 0x20),0);
  __psq_st1(auStack88,(int)in_f26,0);
  __psq_st0(auStack104,(int)((ulonglong)in_f25 >> 0x20),0);
  __psq_st1(auStack104,(int)in_f25,0);
  __psq_st0(auStack120,(int)((ulonglong)in_f24 >> 0x20),0);
  __psq_st1(auStack120,(int)in_f24,0);
  __psq_st0(auStack136,(int)((ulonglong)in_f23 >> 0x20),0);
  __psq_st1(auStack136,(int)in_f23,0);
  __psq_st0(auStack152,(int)((ulonglong)in_f22 >> 0x20),0);
  __psq_st1(auStack152,(int)in_f22,0);
  __psq_st0(auStack168,(int)((ulonglong)in_f21 >> 0x20),0);
  __psq_st1(auStack168,(int)in_f21,0);
  __psq_st0(auStack184,(int)((ulonglong)in_f20 >> 0x20),0);
  __psq_st1(auStack184,(int)in_f20,0);
  __psq_st0(auStack200,(int)((ulonglong)in_f19 >> 0x20),0);
  __psq_st1(auStack200,(int)in_f19,0);
  __psq_st0(auStack216,(int)((ulonglong)in_f18 >> 0x20),0);
  __psq_st1(auStack216,(int)in_f18,0);
  __psq_st0(auStack232,(int)((ulonglong)in_f17 >> 0x20),0);
  __psq_st1(auStack232,(int)in_f17,0);
  __psq_st0(auStack248,(int)((ulonglong)in_f16 >> 0x20),0);
  __psq_st1(auStack248,(int)in_f16,0);
  __psq_st0(auStack264,(int)((ulonglong)in_f15 >> 0x20),0);
  __psq_st1(auStack264,(int)in_f15,0);
  __psq_st0(auStack280,(int)((ulonglong)in_f14 >> 0x20),0);
  __psq_st1(auStack280,(int)in_f14,0);
  dVar25 = (double)dCamParam_c::styles[param_1].field_0xc;
  dVar24 = (double)dCamParam_c::styles[param_1].field_0x8;
  dVar23 = (double)dCamParam_c::styles[param_1].field_0x14;
  dVar22 = (double)dCamParam_c::styles[param_1].field_0x18;
  dVar20 = (double)*(float *)&dCamParam_c::styles[param_1].field_0x5c;
  dVar19 = (double)*(float *)&dCamParam_c::styles[param_1].field_0x58;
  local_144 = dCamParam_c::styles[param_1].mLockonCenterHeightMax;
  dVar18 = (double)dCamParam_c::styles[param_1].mCenterHeightUpper;
  dVar17 = (double)dCamParam_c::styles[param_1].mCenterHeightLower;
  local_148 = dCamParam_c::styles[param_1].field_0x40;
  dVar16 = (double)dCamParam_c::styles[param_1].field_0x34;
  dVar15 = (double)dCamParam_c::styles[param_1].field_0x38;
  dVar14 = (double)dCamParam_c::styles[param_1].mLockonLongitudeMax;
  dVar13 = (double)dCamParam_c::styles[param_1].mLockonLatitudeMax;
  dVar12 = (double)*(float *)&dCamParam_c::styles[param_1].field_0x48;
  dVar11 = (double)*(float *)&dCamParam_c::styles[param_1].field_0x4c;
  local_14c = dCamParam_c::styles[param_1].mLockonFovyMax;
  dVar10 = (double)dCamParam_c::styles[param_1].mFovyUpper;
  local_150 = dCamParam_c::styles[param_1].mFovyLower;
  if (this->field_0x11c == 0) {
    *(undefined *)&this->field_0x100 = 1;
    *(undefined *)&this->field_0x101 = 1;
    *(undefined *)&this->field_0x102 = 1;
    if (((this->mEventFlags & 0x1000) == 0) || (this->mpLockonTarget == (fopAc_ac_c *)0x0)) {
      this->mEvFovy = d_camera::0_0;
    }
    else {
      this->mEvFovy = d_camera::1_0;
    }
    attentionPos(&local_2fc,this,this->mpPlayerActor);
    local_2b4 = local_2fc.x;
    local_2b0 = local_2fc.y;
    local_2ac = local_2fc.z;
    this->mEvBank = (this->field_0x44).y - local_2fc.y;
    this->mEvTimer = (int)(float)dVar16;
    ::cXyz::operator__(&cStack776,&this->field_0x50,&this->field_0x44);
    cSGlobe::Val(&this->field_0x3c,&cStack776);
    if (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5ccc)[this->mPadId * 4] & 0x20000U) == 0) {
      this->mEvRelUseMask[0] = '\0';
    }
    else {
      this->mEvRelUseMask[0] = '\x01';
    }
    *(float *)&this->field_0x3a8 = (this->field_0x3c).mDistance;
    *(short *)&(this->mEvBasePos).x = (this->field_0x3c).mAngleX.v;
    *(short *)((int)&(this->mEvBasePos).x + 2) = (this->field_0x3c).mAngleY.v;
    *(float *)&this->field_0x37c = ::cXyz::Zero.x;
    *(float *)&this->field_0x380 = ::cXyz::Zero.y;
    *(float *)&this->field_0x384 = ::cXyz::Zero.z;
    *(undefined4 *)&this->field_0x3b8 = 0;
  }
  iVar3 = this->mPadId;
  uVar6 = (&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[iVar3 * 4];
  if ((uVar6 & 0x8000000) == 0) {
    if (((uVar6 & 0x2800100) == 0) &&
       (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5ccc)[iVar3 * 4] & 0x10020U) == 0)) {
      bVar2 = false;
      if ((daNpc_Cb1_c::m_flying != '\0') || (daNpc_Md_c::m_flying != '\0')) {
        bVar2 = true;
      }
      if (!bVar2) {
        if (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5ccc)[iVar3 * 4] & 0x40000U) != 0) {
          dVar12 = (double)d_camera::_10137;
          dVar11 = (double)d_camera::_6064;
        }
        goto LAB_80178ab4;
      }
    }
    fVar26 = d_camera::_16395;
    if ((uVar6 & 0x2000000) != 0) {
      fVar26 = d_camera::_16394;
    }
    dVar12 = (double)fVar26;
    dVar11 = (double)d_camera::_16396;
    dVar13 = (double)d_camera::_10136;
    dVar23 = (double)d_camera::_16397;
    if ((double)d_camera::_14079 < dVar15) {
      dVar15 = (double)d_camera::_14079;
    }
  }
  else {
    if (dVar12 < (double)d_camera::_10136) {
      dVar12 = (double)d_camera::_10136;
    }
    if (dVar18 < (double)d_camera::_10137) {
      dVar18 = (double)d_camera::_10137;
    }
  }
LAB_80178ab4:
  if ((this->mEvRelUseMask[0] == '\0') &&
     (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5ccc)[iVar3 * 4] & 0x20000U) != 0)) {
    this->field_0x144 = 1;
    this->mEventFlags = this->mEventFlags | 0x4000000;
  }
  if ((((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4] & 0x800000U) != 0) &&
     (*(char *)&this->field_0x784 != '\0')) {
    dVar17 = (double)d_camera::0_0;
    dVar24 = (double)d_camera::1_0;
    dVar23 = (double)d_camera::_8359;
    dVar22 = (double)d_camera::0_25;
    dVar20 = (double)d_camera::_9011;
    dVar19 = (double)d_camera::_9005;
    local_144 = d_camera::0_0;
    local_148 = d_camera::1_0;
    dVar15 = (double)d_camera::_9009;
    dVar13 = (double)d_camera::_16398;
    dVar12 = (double)d_camera::60_0;
    dVar11 = (double)d_camera::_14643;
    local_14c = d_camera::1_0;
    dVar10 = (double)d_camera::_11370;
    local_150 = d_camera::_11370;
    dVar14 = dVar13;
    dVar16 = dVar15;
    dVar18 = dVar17;
    dVar25 = dVar17;
  }
  fVar26 = this->mStickCPosXLast;
  if (fVar26 < d_camera::_8359) {
    if (d_camera::_16399 < fVar26) {
      dVar9 = (double)dCamMath::rationalBezierRatio(d_camera::_16400 * fVar26,d_camera::_9007);
    }
    else {
      dVar9 = (double)d_camera::_1_0;
    }
  }
  else {
    dVar9 = (double)d_camera::1_0;
  }
  fVar26 = this->mStickCPosYLast;
  if (fVar26 < d_camera::_8359) {
    if (d_camera::_16399 < fVar26) {
      dVar8 = (double)dCamMath::rationalBezierRatio(d_camera::_16400 * fVar26,d_camera::_9007);
    }
    else {
      dVar8 = (double)d_camera::_1_0;
    }
  }
  else {
    dVar8 = (double)d_camera::1_0;
  }
  local_13c = (float)dVar20;
  local_140 = (float)dVar20;
  dVar21 = dVar20;
  if (((((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4] & 0x6800061U) != 0) ||
      (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5ccc)[this->mPadId * 4] & 0x10000U) != 0)) &&
     (*(char *)&this->field_0x220 == '\0')) {
    setDMCAngle(this);
  }
  local_3d8 = this->mEvBank;
  dVar8 = -dVar8;
  cVar5 = d_camera::limited_range_addition
                    ((double)(float)(dVar8 * (double)local_144),dVar18,dVar17,&local_3d8);
  if (cVar5 == '\0') {
    dVar20 = dVar19;
  }
  if ((((this->mEventFlags & 0x1000) != 0) && (this->mpLockonTarget != (fopAc_ac_c *)0x0)) &&
     ((*(char *)&this->field_0x784 != '\0' || (*(char *)&this->field_0x785 != '\0')))) {
    local_3d8 = d_camera::_16401;
  }
  this->mEvBank = this->mEvBank + (float)(dVar20 * (double)(local_3d8 - this->mEvBank));
  if (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4] & 0x100U) != 0) {
    if ((double)d_camera::_10137 < dVar24) {
      dVar24 = (double)d_camera::_10137;
    }
    if (this->mEvBank < d_camera::30_0) {
      this->mEvBank = d_camera::30_0;
    }
  }
  local_2c0.y = this->mEvBank;
  local_2c0.x = (float)dVar25;
  local_2c0.z = (float)dVar24;
  bVar2 = false;
  if (((this->mEventFlags & 0x1000) == 0) || (this->mpLockonTarget == (fopAc_ac_c *)0x0)) {
    bVar2 = true;
  }
  else {
    relationalPos((dCamera_c *)&local_314,(fopAc_ac_c *)this,this->mpPlayerActor,
                  (cXyz *)this->mpLockonTarget,d_camera::_6431);
    *(camera_class **)&this->field_0x388 = local_314;
    *(undefined4 *)&this->field_0x38c = local_310;
    *(float *)&this->field_0x390 = local_30c;
    relationalPos(&local_320,this,this->mpPlayerActor,&local_2c0);
    local_2cc.x = local_320.x;
    local_2cc.y = local_320.y;
    local_2cc.z = local_320.z;
    dBgS_CamLinChk_NorWtr::dBgS_CamLinChk_NorWtr((dBgS_CamLinChk_NorWtr *)&dStack464);
    dBgS_CamLinChk_NorWtr::dBgS_CamLinChk_NorWtr((dBgS_CamLinChk_NorWtr *)&dStack572);
    cVar5 = lineBGCheck(this,&local_2cc,(cXyz *)&this->field_0x388,&dStack464,0x7f);
    if ((cVar5 == '\0') ||
       (cVar5 = lineBGCheckBoth(this,&this->mEye,&local_2cc,&dStack572,0x7f), cVar5 == '\0')) {
      dVar18 = (double)getWaterSurfaceHeight(this,(cXyz *)&this->field_0x388);
      if ((double)*(float *)&this->field_0x38c < dVar18) {
        *(float *)&this->field_0x38c = (float)dVar18;
      }
      ::cXyz::operator__(&local_32c,(cXyz *)&this->field_0x388,&local_2cc);
      *(float *)&this->field_0x37c = local_32c.x;
      *(float *)&this->field_0x380 = local_32c.y;
      *(float *)&this->field_0x384 = local_32c.z;
      fVar26 = this->mEvFovy;
      if (d_camera::1_0 <= fVar26) {
        if (d_camera::1_0 < fVar26) {
          this->mEvFovy = d_camera::1_0;
        }
      }
      else {
        this->mEvFovy = fVar26 + d_camera::_5311;
        ::cXyz::operator_(&cStack824,(cXyz *)&this->field_0x37c,this->mEvFovy);
        ::cXyz::operator__(&local_344,&local_2cc,&cStack824);
        *(float *)&this->field_0x388 = local_344.x;
        *(float *)&this->field_0x38c = local_344.y;
        *(float *)&this->field_0x390 = local_344.z;
      }
    }
    else {
      pcVar4 = cBgS::GetTriPla((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                               (uint)(ushort)dStack572.parent.mPolyInfo.mBgIndex,
                               (uint)(ushort)dStack572.parent.mPolyInfo.mTriIdx);
      dVar18 = (double)mtx::PSVECDotProduct(pcVar4,&this->mEye);
      if ((float)((double)pcVar4->mDist + dVar18) < d_camera::0_0) {
        this->mEventFlags = this->mEventFlags | 0x80000000;
      }
    }
    dBgS_CamLinChk_NorWtr::_dBgS_CamLinChk_NorWtr((dBgS_CamLinChk_NorWtr *)&dStack572);
    dBgS_CamLinChk_NorWtr::_dBgS_CamLinChk_NorWtr((dBgS_CamLinChk_NorWtr *)&dStack464);
  }
  if (bVar2) {
    relationalPos(&local_350,this,this->mpPlayerActor,&local_2c0);
    *(float *)&this->field_0x388 = local_350.x;
    *(float *)&this->field_0x38c = local_350.y;
    *(float *)&this->field_0x390 = local_350.z;
    dVar18 = (double)getWaterSurfaceHeight(this,(cXyz *)&this->field_0x388);
    if ((double)*(float *)&this->field_0x38c < dVar18) {
      *(float *)&this->field_0x38c = (float)dVar18;
    }
    fVar26 = this->mEvFovy;
    if (fVar26 <= d_camera::0_0) {
      if (fVar26 < d_camera::0_0) {
        this->mEvFovy = d_camera::0_0;
      }
    }
    else {
      this->mEvFovy = fVar26 - d_camera::_5311;
      ::cXyz::operator_(&cStack860,(cXyz *)&this->field_0x37c,this->mEvFovy);
      ::cXyz::operator__(&local_368,(cXyz *)&this->field_0x388,&cStack860);
      *(float *)&this->field_0x388 = local_368.x;
      *(float *)&this->field_0x38c = local_368.y;
      *(float *)&this->field_0x390 = local_368.z;
    }
  }
  fVar26 = d_camera::_5311;
  if (this->field_0x11c == 0) {
    ::cXyz::operator__(&local_374,(cXyz *)&this->field_0x388,&this->field_0x44);
    local_380.x = local_374.x;
    local_380.y = local_374.y;
    local_380.z = local_374.z;
    fVar26 = mtx::PSVECSquareMag(&local_380);
    dVar18 = (double)fVar26;
    if ((double)d_camera::0_0 < dVar18) {
      dVar24 = 1.0 / SQRT(dVar18);
      dVar24 = d_camera::_5735 * dVar24 * (d_camera::_5736 - dVar18 * dVar24 * dVar24);
      dVar24 = d_camera::_5735 * dVar24 * (d_camera::_5736 - dVar18 * dVar24 * dVar24);
      local_3e8 = (float)(dVar18 * d_camera::_5735 * dVar24 *
                                   (d_camera::_5736 - dVar18 * dVar24 * dVar24));
      dVar18 = (double)local_3e8;
    }
    fVar26 = d_camera::0_0;
    if (dVar18 <= (double)d_camera::_10811) {
      fVar26 = d_camera::1_0 - (float)(dVar18 / (double)d_camera::_10811);
    }
    (this->mEvBasePos).y = (float)(dVar23 * (double)fVar26);
    (this->mEvBasePos).z = (float)(dVar22 * (double)fVar26);
  }
  else {
    dVar18 = (double)(this->mEvBasePos).y;
    (this->mEvBasePos).y = (float)(dVar18 + (double)(d_camera::_5311 * (float)(dVar23 - dVar18)));
    dVar18 = (double)(this->mEvBasePos).z;
    (this->mEvBasePos).z = (float)(dVar18 + (double)(fVar26 * (float)(dVar22 - dVar18)));
  }
  local_2d8 = (this->mEvBasePos).y;
  local_2d4 = (this->mEvBasePos).z;
  local_2d0 = local_2d8;
  ::cXyz::operator__(&cStack908,(cXyz *)&this->field_0x388,&this->field_0x44);
  ::cXyz::operator_(&cStack920,(Vec *)&cStack908);
  mtx::PSVECAdd(&this->field_0x44,&cStack920,&this->field_0x44);
  if ((this->mpLockonTarget == (fopAc_ac_c *)0x0) && (*(char *)&this->field_0x780 == '\0')) {
    attentionPos(&local_3a4,this,this->mpPlayerActor);
    local_2e4.x = local_3a4.x;
    local_2e4.y = local_3a4.y;
    local_2e4.z = local_3a4.z;
    if (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4] & 0x8100100U) == 0) {
      local_2e4.y = local_3a4.y - d_camera::_10146;
    }
    else {
      eyePos(&cStack944,this,this->mpPlayerActor);
      local_2e4.y = d_camera::30_0 + cStack944.y;
    }
    dBgS_CamLinChk_NorWtr::dBgS_CamLinChk_NorWtr((dBgS_CamLinChk_NorWtr *)&dStack680);
    cVar5 = lineBGCheck(this,&local_2e4,&this->field_0x44,&dStack680,0x7f);
    if (cVar5 != '\0') {
      pcVar4 = cBgS::GetTriPla((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                               (uint)(ushort)dStack680.parent.mPolyInfo.mBgIndex,
                               (uint)(ushort)dStack680.parent.mPolyInfo.mTriIdx);
      (this->field_0x44).x = dStack680.parent.mLin.mP1.x;
      (this->field_0x44).y = dStack680.parent.mLin.mP1.y;
      (this->field_0x44).z = dStack680.parent.mLin.mP1.z;
      mtx::PSVECAdd(&this->field_0x44,(cXyz *)pcVar4,&this->field_0x44);
    }
    dBgS_CamLinChk_NorWtr::_dBgS_CamLinChk_NorWtr((dBgS_CamLinChk_NorWtr *)&dStack680);
  }
  local_3dc = *(float *)&this->field_0x3a8;
  cVar5 = d_camera::limited_range_addition
                    ((double)(float)(dVar8 * (double)local_148),dVar16,dVar15,&local_3dc);
  if (cVar5 == '\0') {
    local_140 = (float)dVar19;
  }
  dVar18 = (double)cSAngle::Degree((cSAngle *)&this->mEvBasePos);
  local_3e0 = (float)dVar18;
  cVar5 = d_camera::limited_range_addition((double)(float)(dVar8 * dVar13),dVar12,dVar11,&local_3e0)
  ;
  if (cVar5 == '\0') {
    local_13c = (float)dVar19;
  }
  this_00 = (cSAngle *)((int)&(this->mEvBasePos).x + 2);
  dVar12 = (double)cSAngle::Degree(this_00);
  local_160 = (longlong)(int)(d_camera::_8358 * local_3e0);
  iVar3 = (int)(d_camera::_8358 * (float)(dVar12 + (double)(float)(dVar9 * dVar14)));
  local_158 = (longlong)iVar3;
  cSGlobe::Val((cSGlobe *)&this->field_0x3a8,local_3dc,(short)(int)(d_camera::_8358 * local_3e0),
               (short)iVar3);
  if (((this->mEventFlags & 0x1000) != 0) && (this->mpLockonTarget != (fopAc_ac_c *)0x0)) {
    this->mEventFlags = this->mEventFlags | 0x2000;
  }
  fVar26 = (this->field_0x3c).mDistance;
  (this->field_0x3c).mDistance = fVar26 + local_140 * (*(float *)&this->field_0x3a8 - fVar26);
  cSAngle::operator__(acStack1008,(cSAngle *)&this->mEvBasePos);
  cSAngle::operator_(acStack1012,local_13c);
  cSAngle::operator__(local_3f8,&(this->field_0x3c).mAngleX);
  cSAngle::cSAngle(local_414,local_3f8[0]);
  (this->field_0x3c).mAngleX.v = local_414[0];
  cSAngle::operator__(acStack1020,this_00);
  cSAngle::operator_(acStack1024,(float)dVar21);
  cSAngle::operator__(local_404,&(this->field_0x3c).mAngleY);
  cSAngle::cSAngle(local_418,local_404[0]);
  (this->field_0x3c).mAngleY.v = local_418[0];
  cSGlobe::Xyz(&cStack956,&this->field_0x3c);
  ::cXyz::operator__(&local_3c8,&this->field_0x44,&cStack956);
  (this->field_0x50).x = local_3c8.x;
  (this->field_0x50).y = local_3c8.y;
  (this->field_0x50).z = local_3c8.z;
  local_3e4 = this->field_0x60;
  cVar5 = d_camera::limited_range_addition
                    ((double)(float)(dVar8 * (double)local_14c),dVar10,(double)local_150,&local_3e4)
  ;
  if (cVar5 == '\0') {
    dVar20 = (double)*(float *)&dCamParam_c::styles[param_1].field_0x58;
  }
  this->field_0x60 = this->field_0x60 + (float)(dVar20 * (double)(local_3e4 - this->field_0x60));
  dVar20 = (double)(d_camera::1_0 - (float)((double)local_3dc - dVar16) / (float)(dVar15 - dVar16));
  if (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5ccc)[this->mPadId * 4] & 0x40U) != 0) {
    fVar26 = SComponent::cM_rndFX((float)(dVar20 * (double)(this->mCamSetup).field_0x78));
    this->field_0x60 = this->field_0x60 + fVar26;
  }
  if (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5ccc)[this->mPadId * 4] & 0x20U) != 0) {
    positionOf(&local_3d4,this,this->mpPlayerActor);
    local_2f0.x = local_3d4.x;
    local_2f0.z = local_3d4.z;
    local_2f0.y = local_3d4.y + d_camera::_6064;
    dVar14 = (double)(this->mpPlayerActor->mCurrent).mPos.y;
    dVar12 = (double)groundHeight(this,&local_2f0);
    if (d_camera::_5129 <= (float)(dVar14 - dVar12)) {
      fVar26 = this->mStickMainPosXLast;
      fVar1 = d_camera::_5311;
    }
    else {
      fVar1 = (float)(dVar14 - dVar12) / d_camera::_5129;
      fVar26 = this->mStickMainPosXLast * fVar1;
      fVar1 = d_camera::1_0 - d_camera::_7227 * fVar1;
    }
    dVar16 = (double)fVar1;
    dVar15 = (double)fVar26;
    cSAngle::cSAngle(acStack1032,(short)(*(int *)&this->field_0x7c << 7));
    dVar14 = (double)(this->mCamSetup).field_0x7c;
    dVar12 = (double)cSAngle::Sin(acStack1032);
    this->field_0x60 = this->field_0x60 + (float)(dVar20 * (double)(float)(dVar14 * dVar12));
    dVar12 = (double)dCamSetup_c::FanBank(&this->mCamSetup);
    cSAngle::cSAngle(acStack1004,(float)(dVar20 * (double)(float)(dVar15 * dVar12)));
    cSAngle::operator__(acStack1036,acStack1004);
    cSAngle::operator_(acStack1040,(float)dVar16);
    cSAngle::operator___((cSAngle *)&this->field_0x5c,acStack1040);
    this->mEventFlags = this->mEventFlags | 0x400;
  }
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  __psq_l0(auStack24,uVar7);
  __psq_l1(auStack24,uVar7);
  __psq_l0(auStack40,uVar7);
  __psq_l1(auStack40,uVar7);
  __psq_l0(auStack56,uVar7);
  __psq_l1(auStack56,uVar7);
  __psq_l0(auStack72,uVar7);
  __psq_l1(auStack72,uVar7);
  __psq_l0(auStack88,uVar7);
  __psq_l1(auStack88,uVar7);
  __psq_l0(auStack104,uVar7);
  __psq_l1(auStack104,uVar7);
  __psq_l0(auStack120,uVar7);
  __psq_l1(auStack120,uVar7);
  __psq_l0(auStack136,uVar7);
  __psq_l1(auStack136,uVar7);
  __psq_l0(auStack152,uVar7);
  __psq_l1(auStack152,uVar7);
  __psq_l0(auStack168,uVar7);
  __psq_l1(auStack168,uVar7);
  __psq_l0(auStack184,uVar7);
  __psq_l1(auStack184,uVar7);
  __psq_l0(auStack200,uVar7);
  __psq_l1(auStack200,uVar7);
  __psq_l0(auStack216,uVar7);
  __psq_l1(auStack216,uVar7);
  __psq_l0(auStack232,uVar7);
  __psq_l1(auStack232,uVar7);
  __psq_l0(auStack248,uVar7);
  __psq_l1(auStack248,uVar7);
  __psq_l0(auStack264,uVar7);
  __psq_l1(auStack264,uVar7);
  __psq_l0(auStack280,uVar7);
  __psq_l1(auStack280,uVar7);
  return 1;
}


/* WARNING: Removing unreachable block (ram,0x80179998) */
/* WARNING: Removing unreachable block (ram,0x80179988) */
/* WARNING: Removing unreachable block (ram,0x80179978) */
/* WARNING: Removing unreachable block (ram,0x80179980) */
/* WARNING: Removing unreachable block (ram,0x80179990) */
/* WARNING: Removing unreachable block (ram,0x801799a0) */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dCamera_c::nonOwnerCamera(long) */

undefined4 __thiscall dCamera_c::nonOwnerCamera(dCamera_c *this,long param_1)

{
  undefined4 uVar1;
  short sVar2;
  undefined4 uVar3;
  undefined8 in_f26;
  double dVar4;
  undefined8 in_f27;
  double dVar5;
  undefined8 in_f28;
  double dVar6;
  undefined8 in_f29;
  double dVar7;
  undefined8 in_f30;
  double dVar8;
  undefined8 in_f31;
  double dVar9;
  cSAngle local_168 [2];
  cSAngle local_164 [2];
  cSAngle local_160 [2];
  cSAngle local_15c [2];
  cSAngle local_158 [2];
  cSAngle acStack340 [2];
  cSAngle acStack336 [2];
  cSAngle acStack332 [2];
  cSAngle acStack328 [2];
  cSAngle local_144 [2];
  cSAngle acStack320 [2];
  cSAngle acStack316 [2];
  cSAngle acStack312 [2];
  cSAngle acStack308 [2];
  cSAngle acStack304 [2];
  cSAngle local_12c [2];
  cSAngle local_128 [2];
  cSAngle acStack292 [2];
  cSAngle acStack288 [2];
  cSAngle acStack284 [2];
  cSAngle acStack280 [2];
  cSAngle acStack276 [2];
  cSGlobe cStack272;
  cXyz local_108;
  cXyz cStack252;
  cXyz cStack240;
  cXyz cStack228;
  cXyz local_d8;
  cXyz cStack204;
  cXyz cStack192;
  cXyz local_b4;
  cXyz cStack168;
  cXyz local_9c;
  cXyz local_90;
  cXyz local_84;
  longlong local_78;
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  __psq_st0(auStack72,(int)((ulonglong)in_f27 >> 0x20),0);
  __psq_st1(auStack72,(int)in_f27,0);
  __psq_st0(auStack88,(int)((ulonglong)in_f26 >> 0x20),0);
  __psq_st1(auStack88,(int)in_f26,0);
  this->mpLockonTarget = _canon_p;
  if (this->mpLockonTarget == (fopAc_ac_c *)0x0) {
    uVar1 = 0;
  }
  else {
    local_84.x = dCamParam_c::styles[param_1].field_0xc;
    local_84.y = dCamParam_c::styles[param_1].mCenterHeightBase;
    local_84.z = dCamParam_c::styles[param_1].field_0x8;
    dVar7 = (double)dCamParam_c::styles[param_1].mLockonLongitudeMin;
    dVar6 = (double)dCamParam_c::styles[param_1].mLockonLatitudeMin;
    dVar5 = (double)dCamParam_c::styles[param_1].field_0x30;
    dVar4 = (double)dCamParam_c::styles[param_1].field_0x44;
    dVar9 = (double)dCamParam_c::styles[param_1].mFovyBase;
    dVar8 = (double)*(float *)&dCamParam_c::styles[param_1].field_0x58;
    if (this->field_0x11c == 0) {
      relationalPos(&local_9c,this,this->mpLockonTarget,&local_84);
      (this->field_0x44).x = local_9c.x;
      (this->field_0x44).y = local_9c.y;
      (this->field_0x44).z = local_9c.z;
      directionOf((dCamera_c *)acStack292,(fopAc_ac_c *)this);
      sVar2 = cSAngle::Inv(acStack292);
      local_78 = (longlong)(int)((double)d_camera::_8358 * dVar4);
      cSGlobe::Val(&this->field_0x3c,(float)dVar5,(short)(int)((double)d_camera::_8358 * dVar4),
                   sVar2);
      cSGlobe::Xyz(&cStack168,&this->field_0x3c);
      ::cXyz::operator__(&local_b4,&this->field_0x44,&cStack168);
      (this->field_0x50).x = local_b4.x;
      (this->field_0x50).y = local_b4.y;
      (this->field_0x50).z = local_b4.z;
      this->field_0x60 = (float)dVar9;
      *(undefined *)&this->field_0x100 = 1;
      *(undefined *)&this->field_0x101 = 1;
      *(undefined *)&this->field_0x102 = 1;
      uVar1 = 1;
    }
    else {
      cSGlobe::cSGlobe(&cStack272,&local_84);
      cSAngle::operator__(local_128,&cStack272.mAngleX,(this->mpLockonTarget->mCollisionRot).x);
      cSAngle::cSAngle(local_15c,local_128[0]);
      cStack272.mAngleX = local_15c[0];
      cSAngle::operator__(local_12c,(short)register0x00000004 + -0x10a);
      cSAngle::cSAngle(local_160,local_12c[0]);
      cStack272.mAngleY = local_160[0];
      attentionPos(&cStack192,this,this->mpLockonTarget);
      cSGlobe::Xyz(&cStack204,&cStack272);
      ::cXyz::operator__(&local_d8,&cStack192,&cStack204);
      local_90.x = local_d8.x;
      local_90.y = local_d8.y;
      local_90.z = local_d8.z;
      ::cXyz::operator__(&cStack228,&local_90,&this->field_0x44);
      ::cXyz::operator_(&cStack240,&cStack228,d_camera::_9011);
      mtx::PSVECAdd(&this->field_0x44,&cStack240,&this->field_0x44);
      cSAngle::cSAngle(acStack276,(float)dVar4);
      cSAngle::cSAngle(acStack284,0);
      cSAngle::Val(acStack280,(this->mpLockonTarget->mCollisionRot).x);
      directionOf((dCamera_c *)acStack304,(fopAc_ac_c *)this);
      sVar2 = cSAngle::Inv(acStack304);
      cSAngle::Val(acStack288,sVar2);
      cSAngle::operator_(acStack308,(float)dVar6);
      cSAngle::operator__(acStack312,acStack276);
      cSAngle::operator__(acStack316,acStack312);
      cSAngle::operator_(acStack320,(float)dVar8);
      cSAngle::operator__(local_144,&(this->field_0x3c).mAngleX);
      cSAngle::cSAngle(local_164,local_144[0]);
      (this->field_0x3c).mAngleX.v = local_164[0];
      cSAngle::operator_(acStack328,(float)dVar7);
      cSAngle::operator__(acStack332,acStack284);
      cSAngle::operator__(acStack336,acStack332);
      cSAngle::operator_(acStack340,(float)dVar8);
      cSAngle::operator__(local_158,&(this->field_0x3c).mAngleY);
      cSAngle::cSAngle(local_168,local_158[0]);
      (this->field_0x3c).mAngleY.v = local_168[0];
      dVar4 = (double)(this->field_0x3c).mDistance;
      (this->field_0x3c).mDistance =
           (float)(dVar4 + (double)(float)(dVar8 * (double)(float)(dVar5 - dVar4)));
      cSGlobe::Xyz(&cStack252,&this->field_0x3c);
      ::cXyz::operator__(&local_108,&this->field_0x44,&cStack252);
      (this->field_0x50).x = local_108.x;
      (this->field_0x50).y = local_108.y;
      (this->field_0x50).z = local_108.z;
      this->field_0x60 =
           (float)((double)this->field_0x60 +
                  (double)(float)(dVar8 * (double)(float)(dVar9 - (double)this->field_0x60)));
      uVar1 = 1;
    }
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  __psq_l0(auStack24,uVar3);
  __psq_l1(auStack24,uVar3);
  __psq_l0(auStack40,uVar3);
  __psq_l1(auStack40,uVar3);
  __psq_l0(auStack56,uVar3);
  __psq_l1(auStack56,uVar3);
  __psq_l0(auStack72,uVar3);
  __psq_l1(auStack72,uVar3);
  __psq_l0(auStack88,uVar3);
  __psq_l1(auStack88,uVar3);
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x80179f64) */
/* WARNING: Removing unreachable block (ram,0x80179f6c) */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall dCamera_c::fixedFrameCamera(long) */

undefined4 __thiscall dCamera_c::fixedFrameCamera(dCamera_c *this,long param_1)

{
  undefined *puVar1;
  uint uVar2;
  undefined4 uVar3;
  char cVar6;
  uint uVar4;
  fopAc_ac_c *pfVar5;
  cXyz *this_00;
  undefined4 uVar7;
  double dVar8;
  undefined8 in_f30;
  double dVar9;
  undefined8 in_f31;
  double dVar10;
  float fVar11;
  cSAngle local_148 [2];
  cSAngle local_144 [2];
  cSAngle local_140 [2];
  cSAngle acStack316 [2];
  cSAngle acStack312 [2];
  cSAngle local_134 [2];
  cSAngle acStack304 [2];
  cSAngle acStack300 [2];
  float local_128;
  float local_124;
  undefined auStack288 [4];
  cSGlobe local_11c;
  cXyz local_114;
  cXyz cStack264;
  cXyz cStack252;
  cXyz cStack240;
  cXyz local_e4;
  cXyz local_d8;
  cXyz local_cc;
  cXyz cStack192;
  cXyz cStack180;
  cXyz local_a8;
  cXyz local_9c;
  cXyz cStack144;
  float local_84;
  float local_80;
  float local_7c;
  cXyz local_78;
  fopAc_ac_c *local_6c;
  undefined4 local_68;
  int local_64;
  float local_60;
  float local_5c;
  float local_58;
  fopAc_ac_c *local_54;
  undefined4 local_50;
  int local_4c;
  float local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined **local_3c;
  double local_38;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar7 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  dVar10 = (double)dCamParam_c::styles[param_1].mLockonLongitudeMax;
  dVar9 = (double)dCamParam_c::styles[param_1].mFovyBase;
  this_00 = (cXyz *)&this->field_0x378;
  if (this->mCurArrowIdx == 0xff) {
    uVar3 = 0;
  }
  else {
    if (this->field_0x11c == 0) {
      local_7c = (this->mCurRoomArrowEntry).mPos.z;
      local_80 = (this->mCurRoomArrowEntry).mPos.y;
      local_84 = (this->mCurRoomArrowEntry).mPos.x;
      this_00->x = local_84;
      *(float *)&this->field_0x37c = local_80;
      *(float *)&this->field_0x380 = local_7c;
      cSGlobe::cSGlobe(&local_11c,d_camera::_16771,-(this->mCurRoomArrowEntry).mRot.x,
                       (this->mCurRoomArrowEntry).mRot.y);
      cSGlobe::Xyz(&cStack144,&local_11c);
      ::cXyz::operator__(&local_9c,this_00,&cStack144);
      *(float *)&this->field_0x3a8 = local_9c.x;
      (this->mEvBasePos).x = local_9c.y;
      (this->mEvBasePos).y = local_9c.z;
      this->mpEvRelActor = *(fopAc_ac_c **)&this->field_0x3a8;
      *(float *)this->mEvRelUseMask = (this->mEvBasePos).x;
      this->mEvTimer = (int)(this->mEvBasePos).y;
      local_3c = &::cM3dGLin::__vt;
      local_54 = this->mpEvRelActor;
      local_50 = *(undefined4 *)this->mEvRelUseMask;
      local_4c = this->mEvTimer;
      local_48 = this_00->x;
      local_44 = *(undefined4 *)&this->field_0x37c;
      local_40 = *(undefined4 *)&this->field_0x380;
      attentionPos(&local_a8,this,this->mpPlayerActor);
      local_60 = local_a8.x;
      local_5c = local_a8.y;
      local_58 = local_a8.z;
      cVar6 = SComponent::cM3d_Len3dSqPntAndSegLine(&local_54,&local_60,&local_6c,auStack288);
      if (cVar6 != '\0') {
        this->mpEvRelActor = local_6c;
        *(undefined4 *)this->mEvRelUseMask = local_68;
        this->mEvTimer = local_64;
      }
      ::cXyz::operator__(&cStack180,this_00,(cXyz *)&this->mpEvRelActor);
      cSGlobe::Val((cSGlobe *)&this->field_0x384,&cStack180);
      if ((this->field_0x530 != 0) && (*(float *)&this->field_0x384 < d_camera::_10133)) {
        local_11c.mDistance = d_camera::_10133;
        cSGlobe::Xyz(&cStack192,&local_11c);
        ::cXyz::operator__(&local_cc,this_00,&cStack192);
        this->mpEvRelActor = (fopAc_ac_c *)local_cc.x;
        *(float *)this->mEvRelUseMask = local_cc.y;
        this->mEvTimer = (int)local_cc.z;
        *(float *)&this->field_0x384 = d_camera::_10133;
      }
      uVar2 = (uint)(this->mCurRoomCamEntry).field_0x12;
      if (uVar2 != 0xff) {
        local_38 = (double)CONCAT44(0x43300000,uVar2);
        dVar9 = (double)(float)(local_38 - d_camera::_9014);
      }
      this->mEvBank = (float)dVar9;
      uVar4 = (uint)(this->mCurRoomCamEntry).field_0x13;
      uVar2 = 0xffffffff;
      if (uVar4 != 0xff) {
        uVar2 = uVar4;
      }
      if (uVar2 == 0xffffffff) {
        ::cXyz::operator__(&local_d8,this_00,&this->mEye);
        local_e4.x = local_d8.x;
        local_e4.y = local_d8.y;
        local_e4.z = local_d8.z;
        fVar11 = mtx::PSVECSquareMag(&local_e4);
        dVar9 = (double)fVar11;
        if ((double)d_camera::0_0 < dVar9) {
          dVar8 = 1.0 / SQRT(dVar9);
          dVar8 = d_camera::_5735 * dVar8 * (d_camera::_5736 - dVar9 * dVar8 * dVar8);
          dVar8 = d_camera::_5735 * dVar8 * (d_camera::_5736 - dVar9 * dVar8 * dVar8);
          local_128 = (float)(dVar9 * d_camera::_5735 * dVar8 *
                                      (d_camera::_5736 - dVar9 * dVar8 * dVar8));
          dVar9 = (double)local_128;
        }
        pfVar5 = this->mpPlayerActor;
        if ((pfVar5->parent).parent.mProcName == 0xa9) {
          puVar1 = pfVar5[1].parent.parent.mLyTg.parent.parent.mpData;
        }
        else {
          puVar1 = (undefined *)
                   (d_camera::_8357 * ((pfVar5->mEyePos).y - (pfVar5->mCurrent).mPos.y));
        }
        dVar9 = (double)(float)(dVar9 / (double)(float)puVar1);
        if ((double)d_camera::0_0 < dVar9) {
          dVar8 = 1.0 / SQRT(dVar9);
          dVar8 = d_camera::_5735 * dVar8 * (d_camera::_5736 - dVar9 * dVar8 * dVar8);
          dVar8 = d_camera::_5735 * dVar8 * (d_camera::_5736 - dVar9 * dVar8 * dVar8);
          local_124 = (float)(dVar9 * d_camera::_5735 * dVar8 *
                                      (d_camera::_5736 - dVar9 * dVar8 * dVar8));
          dVar9 = (double)local_124;
        }
        *(int *)&this->field_0x38c = (int)(dVar10 * dVar9) + 1;
      }
      else {
        *(uint *)&this->field_0x38c = uVar2;
      }
      local_38 = (double)CONCAT44(0x43300000,
                                  *(int *)&this->field_0x38c * (*(int *)&this->field_0x38c + 1) >> 1
                                  ^ 0x80000000);
      *(float *)&this->field_0x390 = (float)(local_38 - d_camera::_5738);
      local_3c = &::cM3dGLin::__vt;
    }
    if (*(char *)&this->field_0x100 == '\0') {
      local_38 = (double)CONCAT44(0x43300000,
                                  *(int *)&this->field_0x38c - this->field_0x11c ^ 0x80000000);
      this->mEvFovy = (float)(local_38 - d_camera::_5738);
      dVar9 = (double)(this->mEvFovy / *(float *)&this->field_0x390);
      *(float *)&this->field_0x390 = *(float *)&this->field_0x390 - this->mEvFovy;
      ::cXyz::operator__(&cStack240,(cXyz *)&this->mpEvRelActor,&this->field_0x44);
      ::cXyz::operator_(&cStack252,&cStack240,(float)dVar9);
      mtx::PSVECAdd(&this->field_0x44,&cStack252,&this->field_0x44);
      fVar11 = (this->field_0x3c).mDistance;
      (this->field_0x3c).mDistance =
           fVar11 + (float)(dVar9 * (double)(*(float *)&this->field_0x384 - fVar11));
      cSAngle::operator__(acStack300,(cSAngle *)&this->field_0x388);
      cSAngle::operator_(acStack304,(float)dVar9);
      cSAngle::operator__(local_134,&(this->field_0x3c).mAngleX);
      cSAngle::cSAngle(local_144,local_134[0]);
      (this->field_0x3c).mAngleX.v = local_144[0];
      cSAngle::operator__(acStack312,(cSAngle *)&this->field_0x38a);
      cSAngle::operator_(acStack316,(float)dVar9);
      cSAngle::operator__(local_140,&(this->field_0x3c).mAngleY);
      cSAngle::cSAngle(local_148,local_140[0]);
      (this->field_0x3c).mAngleY.v = local_148[0];
      cSGlobe::Xyz(&cStack264,&this->field_0x3c);
      ::cXyz::operator__(&local_114,&this->field_0x44,&cStack264);
      (this->field_0x50).x = local_114.x;
      (this->field_0x50).y = local_114.y;
      (this->field_0x50).z = local_114.z;
      cVar6 = lineBGCheck(this,&this->field_0x50,&this->field_0x44,&local_78,0x7f);
      if (cVar6 != '\0') {
        (this->field_0x44).x = local_78.x;
        (this->field_0x44).y = local_78.y;
        (this->field_0x44).z = local_78.z;
      }
      this->field_0x60 =
           this->field_0x60 + (float)(dVar9 * (double)(this->mEvBank - this->field_0x60));
      if (*(int *)&this->field_0x38c - 1U <= (uint)this->field_0x11c) {
        *(undefined *)&this->field_0x102 = 1;
        *(undefined *)&this->field_0x101 = 1;
        *(undefined *)&this->field_0x100 = 1;
      }
    }
    uVar3 = 1;
  }
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  __psq_l0(auStack24,uVar7);
  __psq_l1(auStack24,uVar7);
  return uVar3;
}


/* WARNING: Removing unreachable block (ram,0x8017a7e4) */
/* WARNING: Removing unreachable block (ram,0x8017a7d4) */
/* WARNING: Removing unreachable block (ram,0x8017a7c4) */
/* WARNING: Removing unreachable block (ram,0x8017a7b4) */
/* WARNING: Removing unreachable block (ram,0x8017a7a4) */
/* WARNING: Removing unreachable block (ram,0x8017a7ac) */
/* WARNING: Removing unreachable block (ram,0x8017a7bc) */
/* WARNING: Removing unreachable block (ram,0x8017a7cc) */
/* WARNING: Removing unreachable block (ram,0x8017a7dc) */
/* WARNING: Removing unreachable block (ram,0x8017a7ec) */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall dCamera_c::fixedPositionCamera(long) */

undefined4 __thiscall dCamera_c::fixedPositionCamera(dCamera_c *this,long param_1)

{
  undefined *puVar1;
  uint uVar2;
  char cVar4;
  fopAc_ac_c *pfVar3;
  undefined4 uVar5;
  undefined8 in_f22;
  double dVar6;
  undefined8 in_f23;
  double dVar7;
  undefined8 in_f24;
  double dVar8;
  undefined8 in_f25;
  double dVar9;
  undefined8 in_f26;
  double dVar10;
  undefined8 in_f27;
  double dVar11;
  undefined8 in_f28;
  double dVar12;
  undefined8 in_f29;
  double dVar13;
  undefined8 in_f30;
  double dVar14;
  undefined8 in_f31;
  double dVar15;
  float fVar16;
  cSAngle local_228 [2];
  cSAngle local_224 [2];
  cSAngle local_220 [2];
  cSAngle local_21c [2];
  cSAngle local_218 [2];
  cSAngle acStack532 [2];
  cSAngle acStack528 [2];
  cSAngle local_20c [2];
  cSAngle acStack520 [2];
  cSAngle acStack516 [2];
  cSAngle local_200 [2];
  cSAngle acStack508 [2];
  cSAngle acStack504 [2];
  cSAngle local_1f4 [2];
  cSAngle acStack496 [2];
  cSAngle acStack492 [2];
  float local_1e8;
  float local_1e4;
  float local_1e0;
  cSGlobe local_1dc;
  cSGlobe local_1d4;
  cXyz local_1cc;
  cXyz cStack448;
  cXyz cStack436;
  cXyz cStack424;
  cXyz cStack412;
  cXyz local_190;
  cXyz cStack388;
  cXyz cStack376;
  cXyz cStack364;
  cXyz cStack352;
  cXyz cStack340;
  cXyz cStack328;
  cXyz local_13c;
  cXyz local_130;
  cXyz local_124;
  cXyz cStack280;
  cXyz local_10c;
  cXyz local_100;
  cXyz local_f4;
  float local_e8;
  float local_e4;
  float local_e0;
  cXyz local_dc;
  cXyz local_d0;
  double local_c0;
  undefined4 local_b8;
  uint uStack180;
  undefined auStack152 [16];
  undefined auStack136 [16];
  undefined auStack120 [16];
  undefined auStack104 [16];
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  __psq_st0(auStack72,(int)((ulonglong)in_f27 >> 0x20),0);
  __psq_st1(auStack72,(int)in_f27,0);
  __psq_st0(auStack88,(int)((ulonglong)in_f26 >> 0x20),0);
  __psq_st1(auStack88,(int)in_f26,0);
  __psq_st0(auStack104,(int)((ulonglong)in_f25 >> 0x20),0);
  __psq_st1(auStack104,(int)in_f25,0);
  __psq_st0(auStack120,(int)((ulonglong)in_f24 >> 0x20),0);
  __psq_st1(auStack120,(int)in_f24,0);
  __psq_st0(auStack136,(int)((ulonglong)in_f23 >> 0x20),0);
  __psq_st1(auStack136,(int)in_f23,0);
  __psq_st0(auStack152,(int)((ulonglong)in_f22 >> 0x20),0);
  __psq_st1(auStack152,(int)in_f22,0);
  dVar8 = (double)dCamParam_c::styles[param_1].field_0xc;
  dVar7 = (double)dCamParam_c::styles[param_1].mCenterHeightBase;
  dVar6 = (double)dCamParam_c::styles[param_1].field_0x8;
  dVar15 = (double)dCamParam_c::styles[param_1].field_0x18;
  dVar14 = (double)dCamParam_c::styles[param_1].field_0x14;
  dVar13 = (double)dCamParam_c::styles[param_1].field_0x30;
  dVar12 = (double)dCamParam_c::styles[param_1].field_0x34;
  dVar11 = (double)dCamParam_c::styles[param_1].mLockonLongitudeMax;
  dVar10 = (double)dCamParam_c::styles[param_1].mLockonLongitudeMin;
  dVar9 = (double)dCamParam_c::styles[param_1].mFovyBase;
  if (this->field_0x11c == 0) {
    *(float *)&this->field_0x390 = ::cXyz::Zero.x;
    this->mEvFovy = ::cXyz::Zero.y;
    this->mEvBank = ::cXyz::Zero.z;
  }
  *(undefined *)&this->mpEvRelActor = 0;
  if (((dCamParam_c::styles[param_1].mFlag & 0x40) == 0) || (this->mCurArrowIdx == 0xff)) {
    local_d0.x = (this->mEye).x;
    local_d0.y = (this->mEye).y;
    local_d0.z = (this->mEye).z;
    uVar2 = 0xffffffff;
  }
  else {
    local_d0.x = (this->mCurRoomArrowEntry).mPos.x;
    local_d0.y = (this->mCurRoomArrowEntry).mPos.y;
    local_d0.z = (this->mCurRoomArrowEntry).mPos.z;
    cVar4 = ::cXyz::operator___((cXyz *)&this->field_0x390,&local_d0);
    if (cVar4 != '\0') {
      setDMCAngle(this);
    }
    *(float *)&this->field_0x390 = local_d0.x;
    this->mEvFovy = local_d0.y;
    this->mEvBank = local_d0.z;
    uVar2 = (uint)(this->mCurRoomCamEntry).field_0x12;
    if (uVar2 != 0xff) {
      local_c0 = (double)CONCAT44(0x43300000,uVar2);
      dVar9 = (double)(float)(local_c0 - d_camera::_9014);
    }
    uVar2 = (uint)(this->mCurRoomCamEntry).field_0x13;
    if (uVar2 == 0xff) {
      uVar2 = 0xffffffff;
    }
    else {
      *(undefined *)&this->mpEvRelActor = 1;
    }
  }
  local_dc.x = (float)dVar8;
  local_dc.y = (float)dVar7;
  local_dc.z = (float)dVar6;
  if (this->field_0x11c == 0) {
    if (*(char *)&this->mpEvRelActor == '\0') {
      ::cXyz::operator__(&local_100,&local_d0,&this->mEye);
      local_10c.x = local_100.x;
      local_10c.y = local_100.y;
      local_10c.z = local_100.z;
      fVar16 = mtx::PSVECSquareMag(&local_10c);
      dVar6 = (double)fVar16;
      if ((double)d_camera::0_0 < dVar6) {
        dVar7 = 1.0 / SQRT(dVar6);
        dVar7 = d_camera::_5735 * dVar7 * (d_camera::_5736 - dVar6 * dVar7 * dVar7);
        dVar7 = d_camera::_5735 * dVar7 * (d_camera::_5736 - dVar6 * dVar7 * dVar7);
        local_1e4 = (float)(dVar6 * d_camera::_5735 * dVar7 *
                                    (d_camera::_5736 - dVar6 * dVar7 * dVar7));
        dVar6 = (double)local_1e4;
      }
      if (dVar13 < dVar6) {
        dVar6 = dVar13;
      }
      relationalPos(&cStack280,this,this->mpPlayerActor,&local_dc);
      ::cXyz::operator__(&local_124,&this->mCenter,&cStack280);
      local_130.x = local_124.x;
      local_130.y = local_124.y;
      local_130.z = local_124.z;
      fVar16 = mtx::PSVECSquareMag(&local_130);
      dVar7 = (double)fVar16;
      if ((double)d_camera::0_0 < dVar7) {
        dVar8 = 1.0 / SQRT(dVar7);
        dVar8 = d_camera::_5735 * dVar8 * (d_camera::_5736 - dVar7 * dVar8 * dVar8);
        dVar8 = d_camera::_5735 * dVar8 * (d_camera::_5736 - dVar7 * dVar8 * dVar8);
        local_1e8 = (float)(dVar7 * d_camera::_5735 * dVar8 *
                                    (d_camera::_5736 - dVar7 * dVar8 * dVar8));
        dVar7 = (double)local_1e8;
      }
      if (dVar7 < dVar6) {
        dVar7 = dVar6;
      }
      pfVar3 = this->mpPlayerActor;
      if ((pfVar3->parent).parent.mProcName == 0xa9) {
        puVar1 = pfVar3[1].parent.parent.mLyTg.parent.parent.mpData;
      }
      else {
        puVar1 = (undefined *)(d_camera::_8357 * ((pfVar3->mEyePos).y - (pfVar3->mCurrent).mPos.y));
      }
      dVar6 = (double)(float)puVar1;
      if (dVar6 < (double)d_camera::_6064) {
        dVar6 = (double)d_camera::_6064;
      }
      dVar6 = (double)(float)(dVar7 / dVar6);
      if ((double)d_camera::0_0 < dVar6) {
        dVar7 = 1.0 / SQRT(dVar6);
        dVar7 = d_camera::_5735 * dVar7 * (d_camera::_5736 - dVar6 * dVar7 * dVar7);
        dVar7 = d_camera::_5735 * dVar7 * (d_camera::_5736 - dVar6 * dVar7 * dVar7);
        local_1e0 = (float)(dVar6 * d_camera::_5735 * dVar7 *
                                    (d_camera::_5736 - dVar6 * dVar7 * dVar7));
        dVar6 = (double)local_1e0;
      }
      local_c0 = (double)(longlong)(int)(dVar11 * dVar6);
      *(int *)&this->field_0x378 = (int)(dVar11 * dVar6) + 1;
      uStack180 = *(int *)&this->field_0x378 * (*(int *)&this->field_0x378 + 1) >> 1 ^ 0x80000000;
      *(float *)&this->field_0x37c =
           (float)((double)CONCAT44(0x43300000,uStack180) - d_camera::_5738);
    }
    else {
      *(uint *)&this->field_0x378 = uVar2;
      uStack180 = *(uint *)&this->field_0x378 ^ 0x80000000;
      *(float *)&this->field_0x37c =
           (float)((double)CONCAT44(0x43300000,uStack180) - d_camera::_5738);
    }
    local_b8 = 0x43300000;
    *(float *)&this->field_0x384 = (this->field_0x44).x;
    *(float *)&this->field_0x388 = (this->field_0x44).y;
    *(float *)&this->field_0x38c = (this->field_0x44).z;
  }
  local_e8 = (float)dVar14;
  local_e4 = (float)dVar15;
  local_e0 = (float)dVar14;
  relationalPos(&local_13c,this,this->mpPlayerActor,&local_dc);
  local_f4.x = local_13c.x;
  local_f4.y = local_13c.y;
  local_f4.z = local_13c.z;
  if (*(char *)&this->field_0x100 == '\0') {
    if (*(char *)&this->mpEvRelActor == '\0') {
      uStack180 = *(int *)&this->field_0x378 - this->field_0x11c ^ 0x80000000;
      local_b8 = 0x43300000;
      *(float *)&this->field_0x380 =
           (float)((double)CONCAT44(0x43300000,uStack180) - d_camera::_5738);
      fVar16 = *(float *)&this->field_0x380 / *(float *)&this->field_0x37c;
      *(float *)&this->field_0x37c = *(float *)&this->field_0x37c - *(float *)&this->field_0x380;
    }
    else {
      fVar16 = d_camera::1_0 / *(float *)&this->field_0x37c;
      *(float *)&this->field_0x37c = *(float *)&this->field_0x37c - d_camera::1_0;
    }
    dVar6 = (double)fVar16;
    ::cXyz::operator__(&cStack328,&local_f4,(cXyz *)&this->field_0x384);
    ::cXyz::operator_(&cStack340,&cStack328,(float)dVar6);
    mtx::PSVECAdd((cXyz *)&this->field_0x384,&cStack340,(cXyz *)&this->field_0x384);
    ::cXyz::operator__(&cStack352,(cXyz *)&this->field_0x384,&this->field_0x44);
    ::cXyz::operator_(&cStack364,(Vec *)&cStack352);
    mtx::PSVECAdd(&this->field_0x44,&cStack364,&this->field_0x44);
    ::cXyz::operator__(&cStack376,&local_d0,&this->field_0x44);
    cSGlobe::cSGlobe(&local_1d4,&cStack376);
    if ((double)local_1d4.mDistance < dVar12) {
      local_1d4.mDistance = (float)dVar12;
    }
    if (dVar13 < (double)local_1d4.mDistance) {
      local_1d4.mDistance = (float)dVar13;
    }
    fVar16 = (this->field_0x3c).mDistance;
    (this->field_0x3c).mDistance = fVar16 + (float)(dVar6 * (double)(local_1d4.mDistance - fVar16));
    cSAngle::operator__(acStack492,&local_1d4.mAngleX);
    cSAngle::operator_(acStack496,(float)dVar6);
    cSAngle::operator__(local_1f4,&(this->field_0x3c).mAngleX);
    cSAngle::cSAngle(local_21c,local_1f4[0]);
    (this->field_0x3c).mAngleX.v = local_21c[0];
    cSAngle::operator__(acStack504,&local_1d4.mAngleY);
    cSAngle::operator_(acStack508,(float)dVar6);
    cSAngle::operator__(local_200,&(this->field_0x3c).mAngleY);
    cSAngle::cSAngle(local_220,local_200[0]);
    (this->field_0x3c).mAngleY.v = local_220[0];
    cSGlobe::Xyz(&cStack388,&this->field_0x3c);
    ::cXyz::operator__(&local_190,&this->field_0x44,&cStack388);
    (this->field_0x50).x = local_190.x;
    (this->field_0x50).y = local_190.y;
    (this->field_0x50).z = local_190.z;
    this->field_0x60 =
         (float)((double)this->field_0x60 +
                (double)(float)(dVar6 * (double)(float)(dVar9 - (double)this->field_0x60)));
    if (*(int *)&this->field_0x378 - 1U <= (uint)this->field_0x11c) {
      *(undefined *)&this->field_0x102 = 1;
      *(undefined *)&this->field_0x101 = 1;
      *(undefined *)&this->field_0x100 = 1;
    }
  }
  else {
    ::cXyz::operator__(&cStack412,&local_f4,&this->field_0x44);
    ::cXyz::operator_(&cStack424,(Vec *)&cStack412);
    mtx::PSVECAdd(&this->field_0x44,&cStack424,&this->field_0x44);
    ::cXyz::operator__(&cStack436,&local_d0,&this->field_0x44);
    cSGlobe::cSGlobe(&local_1dc,&cStack436);
    if ((double)local_1dc.mDistance < dVar12) {
      local_1dc.mDistance = (float)dVar12;
    }
    if (dVar13 < (double)local_1dc.mDistance) {
      local_1dc.mDistance = (float)dVar13;
    }
    fVar16 = (this->field_0x3c).mDistance;
    (this->field_0x3c).mDistance = fVar16 + (float)(dVar10 * (double)(local_1dc.mDistance - fVar16))
    ;
    cSAngle::operator__(acStack516,&local_1dc.mAngleX);
    cSAngle::operator_(acStack520,(float)dVar10);
    cSAngle::operator__(local_20c,&(this->field_0x3c).mAngleX);
    cSAngle::cSAngle(local_224,local_20c[0]);
    (this->field_0x3c).mAngleX.v = local_224[0];
    cSAngle::operator__(acStack528,&local_1dc.mAngleY);
    cSAngle::operator_(acStack532,(float)dVar10);
    cSAngle::operator__(local_218,&(this->field_0x3c).mAngleY);
    cSAngle::cSAngle(local_228,local_218[0]);
    (this->field_0x3c).mAngleY.v = local_228[0];
    cSGlobe::Xyz(&cStack448,&this->field_0x3c);
    ::cXyz::operator__(&local_1cc,&this->field_0x44,&cStack448);
    (this->field_0x50).x = local_1cc.x;
    (this->field_0x50).y = local_1cc.y;
    (this->field_0x50).z = local_1cc.z;
    this->field_0x60 =
         (float)((double)this->field_0x60 +
                (double)(float)(dVar10 * (double)(float)(dVar9 - (double)this->field_0x60)));
  }
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  __psq_l0(auStack24,uVar5);
  __psq_l1(auStack24,uVar5);
  __psq_l0(auStack40,uVar5);
  __psq_l1(auStack40,uVar5);
  __psq_l0(auStack56,uVar5);
  __psq_l1(auStack56,uVar5);
  __psq_l0(auStack72,uVar5);
  __psq_l1(auStack72,uVar5);
  __psq_l0(auStack88,uVar5);
  __psq_l1(auStack88,uVar5);
  __psq_l0(auStack104,uVar5);
  __psq_l1(auStack104,uVar5);
  __psq_l0(auStack120,uVar5);
  __psq_l1(auStack120,uVar5);
  __psq_l0(auStack136,uVar5);
  __psq_l1(auStack136,uVar5);
  __psq_l0(auStack152,uVar5);
  __psq_l1(auStack152,uVar5);
  return 1;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall dCamera_c::eventCamera(long) */

undefined4 __thiscall dCamera_c::eventCamera(dCamera_c *this,long param_1)

{
  uint *puVar1;
  float fVar2;
  uint uVar3;
  bool bVar5;
  char cVar6;
  dCamera_c *pdVar4;
  uint *puVar7;
  void *extraout_r4;
  void *pvVar8;
  uint *puVar9;
  cBgS_PolyPassChk *pcVar10;
  int iVar11;
  longlong lVar12;
  int local_1e8 [3];
  undefined local_1dc [104];
  uint local_174;
  PTMF local_170;
  undefined4 local_164;
  undefined4 local_160;
  undefined *local_15c;
  undefined4 local_158;
  undefined4 local_154;
  undefined *local_150;
  undefined4 local_14c;
  undefined4 local_148;
  undefined *local_144;
  undefined4 local_140;
  undefined4 local_13c;
  undefined *local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined *local_12c;
  undefined4 local_128;
  undefined4 local_124;
  undefined *local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined *local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined *local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined *local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined *local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined *local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined *local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined *local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined *local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined *local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined *local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined *local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined *local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined *local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined *local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined *local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined *local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined *local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined *local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined *local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined *local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined *local_24;
  
  puVar9 = &local_174;
  puVar7 = (uint *)0x8035e9bc;
  iVar11 = 0x2a;
  do {
    puVar1 = puVar7 + 1;
    puVar7 = puVar7 + 2;
    uVar3 = *puVar7;
    puVar9[1] = *puVar1;
    puVar9 = puVar9 + 2;
    *puVar9 = uVar3;
    iVar11 = iVar11 + -1;
  } while (iVar11 != 0);
  local_170.this_delta = d_camera::_17078;
  local_170.vtbl_offset = DAT_80390d50;
  local_170.func = PTR_pauseEvCamera_80390d54;
  local_164 = d_camera::_17079;
  local_160 = DAT_80390d5c;
  local_15c = PTR_pauseEvCamera_80390d60;
  local_158 = d_camera::_17080;
  local_154 = DAT_80390d68;
  local_150 = PTR_talktoEvCamera_80390d6c;
  local_14c = d_camera::_17081;
  local_148 = DAT_80390d74;
  local_144 = PTR_fixedPositionEvCamera_80390d78;
  local_140 = d_camera::_17082;
  local_13c = DAT_80390d80;
  local_138 = PTR_fixedFrameEvCamera_80390d84;
  local_134 = d_camera::_17083;
  local_130 = DAT_80390d8c;
  local_12c = PTR_uniformTransEvCamera_80390d90;
  local_128 = d_camera::_17084;
  local_124 = DAT_80390d98;
  local_120 = PTR_watchActorEvCamera_80390d9c;
  local_11c = d_camera::_17085;
  local_118 = DAT_80390da4;
  local_114 = PTR_restorePosEvCamera_80390da8;
  local_110 = d_camera::_17086;
  local_10c = DAT_80390db0;
  local_108 = PTR_getItemEvCamera_80390db4;
  local_104 = d_camera::_17087;
  local_100 = DAT_80390dbc;
  local_fc = PTR_gameOverEvCamera_80390dc0;
  local_f8 = d_camera::_17088;
  local_f4 = DAT_80390dc8;
  local_f0 = PTR_turnToActorEvCamera_80390dcc;
  local_ec = d_camera::_17089;
  local_e8 = DAT_80390dd4;
  local_e4 = PTR_rollingEvCamera_80390dd8;
  local_e0 = d_camera::_17090;
  local_dc = DAT_80390de0;
  local_d8 = PTR_tactEvCamera_80390de4;
  local_d4 = d_camera::_17091;
  local_d0 = DAT_80390dec;
  local_cc = PTR_windDirectionEvCamera_80390df0;
  local_c8 = d_camera::_17092;
  local_c4 = DAT_80390df8;
  local_c0 = PTR_tornadoWarpEvCamera_80390dfc;
  local_bc = d_camera::_17093;
  local_b8 = DAT_80390e04;
  local_b4 = PTR_styleEvCamera_80390e08;
  local_b0 = d_camera::_17094;
  local_ac = DAT_80390e10;
  local_a8 = PTR_saveEvCamera_80390e14;
  local_a4 = d_camera::_17095;
  local_a0 = DAT_80390e1c;
  local_9c = PTR_loadEvCamera_80390e20;
  local_98 = d_camera::_17096;
  local_94 = DAT_80390e28;
  local_90 = PTR_useItem0EvCamera_80390e2c;
  local_8c = d_camera::_17097;
  local_88 = DAT_80390e34;
  local_84 = PTR_useItem1EvCamera_80390e38;
  local_80 = d_camera::_17098;
  local_7c = DAT_80390e40;
  local_78 = PTR_fixedFramesEvCamera_80390e44;
  local_74 = d_camera::_17099;
  local_70 = DAT_80390e4c;
  local_6c = PTR_bSplineEvCamera_80390e50;
  local_68 = d_camera::_17100;
  local_64 = DAT_80390e58;
  local_60 = PTR_possessedEvCamera_80390e5c;
  local_5c = d_camera::_17101;
  local_58 = DAT_80390e64;
  local_54 = PTR_twoActor0EvCamera_80390e68;
  local_50 = d_camera::_17102;
  local_4c = DAT_80390e70;
  local_48 = PTR_stokerEvCamera_80390e74;
  local_44 = d_camera::_17103;
  local_40 = DAT_80390e7c;
  local_3c = PTR_uniformBrakeEvCamera_80390e80;
  local_38 = d_camera::_17104;
  local_34 = DAT_80390e88;
  local_30 = PTR_uniformAcceleEvCamera_80390e8c;
  local_2c = d_camera::_17105;
  local_28 = DAT_80390e94;
  local_24 = PTR_maptoolIdEvCamera_80390e98;
  if (this->field_0x118 == 0) {
    *(float *)(this->field_0xa4 + 1) = (this->mCenter).x;
    *(float *)&this->field_0xa4[1].field_0x4 = (this->mCenter).y;
    *(float *)&this->field_0xa4[1].field_0x8 = (this->mCenter).z;
    *(undefined4 *)this->field_0xa4 = *(undefined4 *)(this->field_0xa4 + 1);
    *(undefined4 *)&this->field_0xa4[0].field_0x4 = *(undefined4 *)&this->field_0xa4[1].field_0x4;
    *(undefined4 *)&this->field_0xa4[0].field_0x8 = *(undefined4 *)&this->field_0xa4[1].field_0x8;
    *(float *)&this->field_0xa4[1].field_0xc = (this->mEye).x;
    *(float *)&this->field_0xa4[1].field_0x10 = (this->mEye).y;
    *(float *)&this->field_0xa4[1].field_0x14 = (this->mEye).z;
    *(undefined4 *)&this->field_0xa4[0].field_0xc = *(undefined4 *)&this->field_0xa4[1].field_0xc;
    *(undefined4 *)&this->field_0xa4[0].field_0x10 = *(undefined4 *)&this->field_0xa4[1].field_0x10;
    *(undefined4 *)&this->field_0xa4[0].field_0x14 = *(undefined4 *)&this->field_0xa4[1].field_0x14;
    fVar2 = this->mFovY;
    *(float *)&this->field_0xa4[1].field_0x18 = fVar2;
    *(float *)&this->field_0xa4[0].field_0x18 = fVar2;
    *(short *)&this->field_0xa4[1].field_0x1c = (this->mBank).v;
    *(undefined2 *)&this->field_0xa4[0].field_0x1c = *(undefined2 *)&this->field_0xa4[1].field_0x1c;
    *(undefined2 *)&this->field_0xa4[1].field_0x1e = 0;
    *(undefined2 *)&this->field_0xa4[0].field_0x1e = 0;
  }
  if ((this->mEventFlags & 0x20000000) == 0) {
    if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr.mCameraPlay == 0) {
      return 0;
    }
    iVar11 = dEvent_manager_c::getMyStaffId
                       (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,"CAMERA",
                        (fopAc_ac_c *)0x0,0);
    if (iVar11 < 0) {
      return 0;
    }
    if (this->mStaffIdx != iVar11) {
      this->mEventFlags = this->mEventFlags & 0xffdfffff;
      this->field_0x11c = 0;
      this->field_0x108 = 0;
      this->field_0x118 = 0;
    }
    this->mStaffIdx = iVar11;
    bVar5 = dEvent_manager_c::getIsAddvance
                      (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mStaffIdx);
    if (bVar5 != false) {
      *(undefined *)&this->field_0x102 = 0;
      *(undefined *)&this->field_0x101 = 0;
      *(undefined *)&this->field_0x100 = 0;
      this->field_0x11c = 0;
    }
    lVar12 = dEvent_manager_c::getMyActIdx
                       (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mStaffIdx,
                        &d_camera::ActionNames_17107,0x1c,0,0);
  }
  else {
    this->mStaffIdx = -1;
    if (this->field_0x118 == 0) {
      this->field_0x11c = 0;
    }
    lVar12 = CONCAT44(this->field_0x410,puVar7);
  }
  pvVar8 = (void *)lVar12;
  if ((lVar12 < 0) || (0x1bffffffff < lVar12)) {
    dEvent_manager_c::cutEnd(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mStaffIdx);
    return 0;
  }
  if (this->field_0x11c == 0) {
    if (this->field_0x118 == 0) {
      this->mEventFlags = this->mEventFlags & 0xffdfffff;
      *(undefined4 *)&this->field_0x414 = 2;
    }
    cVar6 = getEvStringData(this,(char *)local_1e8,"Trim","CINESCO");
    if (cVar6 != '\0') {
      if (local_1e8[0] == 0x5354414e) {
        *(undefined4 *)&this->field_0x414 = 0;
      }
      else {
        if (local_1e8[0] == 0x56495354) {
          *(undefined4 *)&this->field_0x414 = 1;
        }
        else {
          if (local_1e8[0] == 0x44454d4f) {
            *(undefined4 *)&this->field_0x414 = 3;
          }
          else {
            if (local_1e8[0] == 0x4e4f4e45) {
              *(undefined4 *)&this->field_0x414 = 4;
            }
            else {
              if (local_1e8[0] == 0x4b454550) {
                *(undefined4 *)&this->field_0x414 = 999;
              }
            }
          }
        }
      }
    }
    getEvIntData(this,(int *)&this->field_0x41c,"WaitAnyKey",0);
    if (*(int *)&this->field_0x41c != 0) {
      this->mEventFlags = this->mEventFlags | 0x200000;
    }
    getEvIntData(this,(int *)&this->field_0x418,"BGCheck",1);
    getEvIntData(this,(int *)&this->field_0x41c,"AutoForcus",1);
    if (*(int *)&this->field_0x41c == 0) {
      mDoGph_gInf_c::mAutoForcus = 0;
    }
    getEvIntData(this,(int *)&this->field_0x420,"MoveBGCheck",1);
    pvVar8 = extraout_r4;
  }
  iVar11 = *(int *)&this->field_0x418;
  if (iVar11 == 2) {
    this->field_0x68 = 0x3f;
  }
  else {
    if (iVar11 < 2) {
      if (0 < iVar11) {
        this->field_0x68 = 0xf;
        goto LAB_8017ae60;
      }
    }
    else {
      if (iVar11 < 5) {
        this->field_0x68 = 0;
        goto LAB_8017ae60;
      }
    }
    this->field_0x68 = 9;
  }
LAB_8017ae60:
  this->field_0x5fc = *(int *)&this->field_0x414;
  bVar5 = false;
  if (((*(char *)&this->field_0x100 != '\0') && (*(char *)&this->field_0x101 != '\0')) &&
     (*(char *)&this->field_0x102 != '\0')) {
    bVar5 = true;
  }
  if (bVar5) {
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].field_0x8 =
         d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].field_0x8 | 4;
  }
  else {
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].field_0x8 =
         d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[this->mCameraInfoIdx].field_0x8 &
         0xfffffffb;
  }
  pdVar4 = this;
  Runtime.PPCEABI.H::__ptmf_scall(&local_170 + (int)((ulonglong)lVar12 >> 0x20),this,pvVar8);
  if (((uint)pdVar4 & 0xff) != 0) {
    dEvent_manager_c::cutEnd(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mStaffIdx);
  }
  if (*(int *)&this->field_0x418 == 4) {
    local_1dc._0_4_ = (cBgS_PolyPassChk *)0x0;
    local_1dc._4_4_ = (cBgS_PolyPassChk *)0x0;
    local_1dc[12] = true;
    local_1dc._20_2_ = -1;
    local_1dc._22_2_ = 0x100;
    local_1dc._24_4_ = (cBgW *)0x0;
    local_1dc._28_4_ = -1;
    local_1dc._16_4_ = &::cBgS_LinChk::__vt;
    local_1dc._32_4_ = &PTR_80371fbc;
    local_1dc._60_4_ = &::cM3dGLin::__vt;
    ::cBgS_LinChk::ct((cBgS_LinChk *)local_1dc);
    pcVar10 = (cBgS_PolyPassChk *)(local_1dc + 0x58);
    local_1dc[92] = 0;
    local_1dc[93] = 0;
    local_1dc[94] = 0;
    local_1dc[95] = 0;
    local_1dc[96] = 0;
    local_1dc[97] = 0;
    local_1dc[98] = 0;
    local_174 = 1;
    local_1dc._16_4_ = &::dBgS_LinChk::__vt;
    local_1dc._32_4_ = (undefined **)&DAT_80371f38;
    local_1dc._88_4_ = &PTR_80371f44;
    local_1dc._100_4_ = &PTR_80371f50;
    local_1dc._4_4_ = pcVar10;
    if (pcVar10 != (cBgS_PolyPassChk *)0x0) {
      local_1dc._4_4_ = (cBgS_PolyPassChk *)(local_1dc + 100);
    }
    local_1dc._0_4_ = pcVar10;
    cVar6 = lineBGCheck(this,&this->field_0x44,&this->field_0x50,(dBgS_LinChk *)local_1dc,4);
    if (cVar6 != '\0') {
      (this->field_0x50).x = local_1dc._48_4_;
      (this->field_0x50).y = local_1dc._52_4_;
      (this->field_0x50).z = local_1dc._56_4_;
    }
    local_1dc._88_4_ = &PTR_80371f44;
    local_1dc._100_4_ = &PTR_80371f50;
    if (pcVar10 != (cBgS_PolyPassChk *)0x0) {
      local_1dc._88_4_ = &::dBgS_Chk::__vt;
      local_1dc._100_4_ = &PTR_80371f68;
      if (((undefined *)register0x00000004 != (undefined *)0x178) &&
         (local_1dc._100_4_ = &::dBgS_GrpPassChk::__vt,
         (undefined *)register0x00000004 != (undefined *)0x178)) {
        local_1dc._100_4_ = &::cBgS_GrpPassChk::__vt;
      }
      if ((pcVar10 != (cBgS_PolyPassChk *)0x0) &&
         (local_1dc._88_4_ = &::dBgS_PolyPassChk::__vt, pcVar10 != (cBgS_PolyPassChk *)0x0)) {
        local_1dc._88_4_ = &::cBgS_PolyPassChk::__vt;
      }
    }
    local_1dc._16_4_ = &::cBgS_LinChk::__vt;
    local_1dc._60_4_ = &::cM3dGLin::__vt;
    local_1dc._32_4_ = &::cBgS_PolyInfo::__vt;
    cBgS_Chk::_cBgS_Chk((cBgS_Chk *)local_1dc);
  }
  return 1;
}


/* __thiscall dCamera_c::demoCamera(long) */

undefined4 __thiscall dCamera_c::demoCamera(dCamera_c *this,long param_1)

{
  return 1;
}


/* __thiscall dCamera_c::letCamera(long) */

undefined4 __thiscall dCamera_c::letCamera(dCamera_c *this,long param_1)

{
  return 1;
}


/* __thiscall dCamera_c::Set(cXyz,
                             cXyz) */

undefined4 __thiscall dCamera_c::Set(dCamera_c *this,cXyz *param_1,cXyz *param_2)

{
  (this->mCenter).x = param_1->x;
  (this->mCenter).y = param_1->y;
  (this->mCenter).z = param_1->z;
  (this->mEye).x = param_2->x;
  (this->mEye).y = param_2->y;
  (this->mEye).z = param_2->z;
  return 1;
}


/* __thiscall dCamera_c::Set(cXyz,
                             cXyz,
                             float,
                             short) */

undefined4 __thiscall
dCamera_c::Set(dCamera_c *this,cXyz *param_1,cXyz *param_2,float param_3,short param_4)

{
  (this->mCenter).x = param_1->x;
  (this->mCenter).y = param_1->y;
  (this->mCenter).z = param_1->z;
  (this->mEye).x = param_2->x;
  (this->mEye).y = param_2->y;
  (this->mEye).z = param_2->z;
  this->mFovY = param_3;
  cSAngle::Val(&this->mBank,param_4);
  return 1;
}


/* __thiscall dCamera_c::Set(cXyz,
                             cXyz,
                             short,
                             float) */

undefined4 __thiscall
dCamera_c::Set(dCamera_c *this,cXyz *param_1,cXyz *param_2,short param_3,float param_4)

{
  (this->mCenter).x = param_1->x;
  (this->mCenter).y = param_1->y;
  (this->mCenter).z = param_1->z;
  (this->mEye).x = param_2->x;
  (this->mEye).y = param_2->y;
  (this->mEye).z = param_2->z;
  this->mFovY = param_4;
  cSAngle::Val(&this->mBank,param_3);
  return 1;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall dCamera_c::Reset(cXyz,
                               cXyz,
                               float,
                               short) */

void __thiscall
dCamera_c::Reset(dCamera_c *this,cXyz *param_1,cXyz *param_2,float param_3,short param_4)

{
  cSAngle local_18 [2];
  cXyz cStack20;
  
  (this->mCenter).x = param_1->x;
  (this->mCenter).y = param_1->y;
  (this->mCenter).z = param_1->z;
  (this->field_0x44).x = (this->mCenter).x;
  (this->field_0x44).y = (this->mCenter).y;
  (this->field_0x44).z = (this->mCenter).z;
  (this->mEye).x = param_2->x;
  (this->mEye).y = param_2->y;
  (this->mEye).z = param_2->z;
  (this->field_0x50).x = (this->mEye).x;
  (this->field_0x50).y = (this->mEye).y;
  (this->field_0x50).z = (this->mEye).z;
  this->mFovY = param_3;
  this->field_0x60 = param_3;
  cSAngle::cSAngle(local_18,param_4);
  (this->mBank).v = local_18[0];
  this->field_0x5c = (this->mBank).v;
  ::cXyz::operator__(&cStack20,&this->field_0x50,&this->field_0x44);
  cSGlobe::Val(&this->field_0x3c,&cStack20);
  Reset(this);
  return;
}


/* __thiscall dCamera_c::Reset(cXyz,
                               cXyz) */

void __thiscall dCamera_c::Reset(dCamera_c *this,cXyz *param_1,cXyz *param_2)

{
  cXyz cStack24;
  
  (this->mCenter).x = param_1->x;
  (this->mCenter).y = param_1->y;
  (this->mCenter).z = param_1->z;
  (this->field_0x44).x = (this->mCenter).x;
  (this->field_0x44).y = (this->mCenter).y;
  (this->field_0x44).z = (this->mCenter).z;
  (this->mEye).x = param_2->x;
  (this->mEye).y = param_2->y;
  (this->mEye).z = param_2->z;
  (this->field_0x50).x = (this->mEye).x;
  (this->field_0x50).y = (this->mEye).y;
  (this->field_0x50).z = (this->mEye).z;
  this->field_0x60 = this->mFovY;
  this->field_0x5c = (this->mBank).v;
  ::cXyz::operator__(&cStack24,&this->field_0x50,&this->field_0x44);
  cSGlobe::Val(&this->field_0x3c,&cStack24);
  Reset(this);
  return;
}


/* __thiscall dCamera_c::Reset(void) */

undefined4 __thiscall dCamera_c::Reset(dCamera_c *this)

{
  cXyz cStack40;
  cXyz acStack28 [2];
  
  (this->field_0x44).x = (this->mCenter).x;
  (this->field_0x44).y = (this->mCenter).y;
  (this->field_0x44).z = (this->mCenter).z;
  (this->field_0x50).x = (this->mEye).x;
  (this->field_0x50).y = (this->mEye).y;
  (this->field_0x50).z = (this->mEye).z;
  this->field_0x60 = this->mFovY;
  ::cXyz::operator__(acStack28,&this->mEye,&this->mCenter);
  cSGlobe::Val((cSGlobe *)&this->field_0x8,acStack28);
  (this->field_0x3c).mDistance = this->field_0x8;
  (this->field_0x3c).mAngleX.v = this->field_0xc;
  (this->field_0x3c).mAngleY.v = (this->field_0xe).v;
  this->field_0x5c = (this->mBank).v;
  ::cXyz::operator__(&cStack40,&this->field_0x50,&this->field_0x44);
  cSGlobe::Val(&this->field_0x3c,&cStack40);
  return 1;
}


/* __thiscall dCamera_c::ResetView(void) */

void __thiscall dCamera_c::ResetView(dCamera_c *this)

{
  setView(this,d_camera::0_0,d_camera::0_0,d_camera::640_0,d_camera::480_0);
  return;
}


/* __thiscall dCamera_c::Chtyp(long) */

bool __thiscall dCamera_c::Chtyp(dCamera_c *this,long nextType)

{
  char cVar1;
  
  cVar1 = onTypeChange(this,this->mCurType,nextType);
  if (cVar1 != '\0') {
    this->mCurType = nextType;
  }
  return cVar1 != '\0';
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall dCamera_c::U2(void) */

cSAngle __thiscall dCamera_c::U2(dCamera_c *this)

{
  return (cSAngle)(this->mAngleY).v;
}


/* WARNING: Removing unreachable block (ram,0x8017ba30) */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall dCamera_c::shakeCamera(void) */

double __thiscall dCamera_c::shakeCamera(dCamera_c *this)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined8 in_f31;
  double dVar7;
  float fVar8;
  cSAngle acStack136 [2];
  cSAngle local_84 [2];
  cXyz cStack128;
  cXyz cStack116;
  cXyz local_68;
  cXyz local_5c;
  cXyz local_50;
  cXyz local_44;
  cXyz local_38;
  longlong local_28;
  undefined auStack8 [8];
  
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  dVar7 = (double)d_camera::0_0;
  uVar3 = this->field_0x554;
  if ((int)uVar3 < this->field_0x550) {
    uVar4 = 1 << 0xf - (uVar3 & 7);
    iVar2 = 0;
    iVar5 = 4;
    fVar8 = d_camera::1_0;
    do {
      if ((uVar4 & *(ushort *)((int)(&this->mSpline2DPath)[1].mFrameIdx + ((int)uVar3 >> 3) + 0xc))
          == 0) {
        fVar8 = fVar8 * d_camera::_17595;
      }
      else {
        dVar7 = (double)(float)(dVar7 + (double)(fVar8 * *(float *)((int)&d_camera::wave_17461 +
                                                                   iVar2)));
      }
      uVar4 = (int)uVar4 >> 1;
      iVar2 = iVar2 + 4;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    this->field_0x554 = this->field_0x554 + 1;
    fVar8 = SComponent::cM_rndFX(d_camera::_5311);
    dVar7 = (double)(float)(dVar7 * (double)(d_camera::_7227 + fVar8));
    if ((this->field_0x554 & 1U) != 0) {
      dVar7 = -dVar7;
    }
    local_38.x = *(float *)&this->field_0x55c;
    local_38.y = *(float *)&this->field_0x560;
    local_38.z = *(float *)&this->field_0x564;
    fVar8 = SComponent::cM_rndFX(d_camera::_17596);
    local_38.x = local_38.x + fVar8;
    fVar8 = SComponent::cM_rndFX(d_camera::_17596);
    local_38.z = local_38.z + fVar8;
    ::cXyz::operator_(&local_5c,&local_38,(float)dVar7);
    local_38.x = local_5c.x;
    local_38.y = local_5c.y;
    local_38.z = local_5c.z;
    if ((*(uint *)&this->field_0x588 & 2) != 0) {
      (this->mEyeShake).x = local_5c.x;
      (this->mEyeShake).y = local_5c.y;
      (this->mEyeShake).z = local_5c.z;
      (this->mCenterShake).x = (this->mEyeShake).x;
      (this->mCenterShake).y = (this->mEyeShake).y;
      (this->mCenterShake).z = (this->mEyeShake).z;
    }
    if ((*(uint *)&this->field_0x588 & 4) != 0) {
      fVar8 = SComponent::cM_rndFX(d_camera::_5128);
      this->mFovYShake = (float)(dVar7 * (double)fVar8);
    }
    if ((*(uint *)&this->field_0x588 & 8) != 0) {
      fVar8 = SComponent::cM_rndFX(d_camera::_10152);
      cSAngle::cSAngle(local_84,(float)(dVar7 * (double)fVar8));
      ((cSAngle *)&this->field_0x584)->v = local_84[0];
    }
    if ((*(uint *)&this->field_0x588 & 0x10) == 0) {
      if ((*(uint *)&this->field_0x588 & 0x20) != 0) {
        if (this->mBlurePositionType == 0) {
          iVar2 = f_op_camera_mng::fopCamM_GetParam(this->mpCamera);
          iVar2 = (char)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[iVar2].mDlstWindowIdx *
                  0x2c;
          eyePos(&local_68,this,this->mpPlayerActor);
          local_44.x = local_68.x;
          local_44.y = local_68.y;
          local_44.z = local_68.z;
          m_Do_lib::mDoLib_project(&local_44,&local_50);
          (this->mBlurePosition).x =
               local_50.x /
               *(float *)((int)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mDlstWindow + iVar2 + 0x20);
          (this->mBlurePosition).y =
               local_50.y /
               *(float *)((int)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mDlstWindow + iVar2 + 0x24);
          (this->mBlurePosition).z = d_camera::0_0;
        }
        bVar1 = false;
        if (this->mBlureTimer < 1) {
          if (*(int *)&this->field_0x58c == 1) {
            bVar1 = true;
          }
        }
        else {
          this->mBlureTimer = this->mBlureTimer + -1;
        }
        if (!bVar1) {
          mtx::PSMTXTrans((double)(this->mBlurePosition).x,(double)(this->mBlurePosition).y,
                          (double)(this->mBlurePosition).z,&mDoMtx_stack_c::now);
          mDoMtx_stack_c::scaleM((this->mBlureScale).x,(this->mBlureScale).y,(this->mBlureScale).z);
          m_Do_mtx::mDoMtx_XrotM(&mDoMtx_stack_c::now,*(short *)&this->field_0x594);
          m_Do_mtx::mDoMtx_YrotM(&mDoMtx_stack_c::now,*(short *)&this->field_0x596);
          m_Do_mtx::mDoMtx_ZrotM(&mDoMtx_stack_c::now,*(short *)&this->field_0x598);
          mDoMtx_stack_c::transM
                    (-(this->mBlurePosition).x,-(this->mBlurePosition).y,-(this->mBlurePosition).z);
          mDoGph_gInf_c::onBlure(&mDoMtx_stack_c::now);
          iVar2 = (int)(d_camera::_17597 * this->mBlureAlpha);
          local_28 = (longlong)iVar2;
          mDoMtx_stack_c::scaleM((this->mBlureScale).x,(this->mBlureScale).y,(this->mBlureScale).z);
          mDoGph_gInf_c::mBlureRate = (undefined)iVar2;
        }
      }
    }
    else {
      local_28 = (longlong)(int)((double)d_camera::30_0 * dVar7);
      mDoGph_gInf_c::mBlureRate = (undefined)(int)((double)d_camera::30_0 * dVar7);
      mDoGph_gInf_c::onBlure();
      this->mBlureTimer = 0;
    }
  }
  else {
    ::cXyz::operator_(&cStack116,&this->mCenterShake,d_camera::_10148);
    mtx::PSVECSubtract(&this->mCenterShake,&cStack116,&this->mCenterShake);
    ::cXyz::operator_(&cStack128,&this->mEyeShake,d_camera::_10148);
    mtx::PSVECSubtract(&this->mEyeShake,&cStack128,&this->mEyeShake);
    fVar8 = d_camera::_10148;
    this->mFovYShake = this->mFovYShake - d_camera::_10148 * this->mFovYShake;
    cSAngle::operator_(acStack136,fVar8);
    cSAngle::operator___((cSAngle *)&this->field_0x584,acStack136);
    bVar1 = 0 < this->mBlureTimer;
    if (bVar1) {
      if (bVar1) {
        if (*(int *)&this->field_0x58c == 1) {
          mtx::PSMTXTrans((double)(this->mBlurePosition).x,(double)(this->mBlurePosition).y,
                          (double)(this->mBlurePosition).z,&mDoMtx_stack_c::now);
          mDoMtx_stack_c::scaleM((this->mBlureScale).x,(this->mBlureScale).y,(this->mBlureScale).z);
          m_Do_mtx::mDoMtx_XrotM(&mDoMtx_stack_c::now,*(short *)&this->field_0x594);
          m_Do_mtx::mDoMtx_YrotM(&mDoMtx_stack_c::now,*(short *)&this->field_0x596);
          m_Do_mtx::mDoMtx_ZrotM(&mDoMtx_stack_c::now,*(short *)&this->field_0x598);
          mDoMtx_stack_c::transM
                    (-(this->mBlurePosition).x,-(this->mBlurePosition).y,-(this->mBlurePosition).z);
          mDoGph_gInf_c::onBlure(&mDoMtx_stack_c::now);
          iVar2 = (int)(d_camera::_17597 * this->mBlureAlpha);
          local_28 = (longlong)iVar2;
          mDoMtx_stack_c::scaleM((this->mBlureScale).x,(this->mBlureScale).y,(this->mBlureScale).z);
          mDoGph_gInf_c::mBlureRate = (undefined)iVar2;
        }
        if ((this->mBlureTimer < (int)(d_camera::_17597 * this->mBlureAlpha)) &&
           (*(int *)&this->field_0x58c == 0)) {
          mDoGph_gInf_c::mBlureRate = (undefined)this->mBlureTimer;
        }
        this->mBlureTimer = this->mBlureTimer + -1;
      }
    }
    else {
      mDoGph_gInf_c::mBlureFlag = 0;
      *(uint *)&this->field_0x588 = *(uint *)&this->field_0x588 & 0xffffffdf;
      this->mBlureTimer = 0;
    }
  }
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  return dVar7;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dCamera_c::StartShake(long,
                                    unsigned char *,
                                    long,
                                    cXyz) */

undefined4 __thiscall
dCamera_c::StartShake(dCamera_c *this,long param_1,uchar *param_2,long param_3,cXyz *param_4)

{
  uchar uVar1;
  uchar *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  cXyz local_18;
  
  if ((param_1 < 0) || (_PatternLengthMax << 3 < param_1)) {
    param_1 = _PatternLengthMax << 3;
  }
  this->field_0x550 = param_1;
  iVar5 = param_1 >> 3;
  iVar4 = 0;
  iVar6 = _PatternLengthMax;
  if (0 < _PatternLengthMax) {
    do {
      iVar3 = (int)&this->mpCamera + iVar4;
      *(undefined *)(iVar3 + 0x548) = 0;
      *(undefined *)(iVar3 + 0x544) = 0;
      iVar4 = iVar4 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  iVar6 = 0;
  puVar2 = param_2;
  if (0 < iVar5) {
    do {
      iVar4 = (int)&this->mpCamera + iVar6;
      uVar1 = *puVar2;
      *(uchar *)(iVar4 + 0x548) = uVar1;
      *(uchar *)(iVar4 + 0x544) = uVar1;
      iVar6 = iVar6 + 1;
      puVar2 = puVar2 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  iVar4 = (int)&this->mpCamera + iVar6;
  *(byte *)(iVar4 + 0x544) = (byte)(0xff << 8 - (param_1 & 7U)) & param_2[iVar6];
  if (param_1 == _PatternLengthMax << 3) {
    *(byte *)(iVar4 + 0x548) =
         *(byte *)(iVar4 + 0x544) | (byte)((int)(uint)*param_2 >> (param_1 & 7U));
  }
  else {
    *(undefined *)(iVar4 + 0x548) = *(undefined *)(iVar4 + 0x544);
  }
  ::cXyz::norm(&local_18);
  *(float *)&this->field_0x55c = local_18.x;
  *(float *)&this->field_0x560 = local_18.y;
  *(float *)&this->field_0x564 = local_18.z;
  this->field_0x554 = 0;
  *(long *)&this->field_0x588 = param_3;
  return 1;
}


/* __thiscall dCamera_c::StopShake(void) */

undefined4 __thiscall dCamera_c::StopShake(dCamera_c *this)

{
  this->field_0x550 = 0;
  this->field_0x554 = 0;
  *(undefined4 *)&this->field_0x588 = 0;
  return 1;
}


/* __thiscall dCamera_c::ResetBlure(int) */

void __thiscall dCamera_c::ResetBlure(dCamera_c *this,int param_1)

{
  float fVar1;
  float fVar2;
  
  *(int *)&this->field_0x58c = param_1;
  this->mBlureAlpha = d_camera::_8359;
  this->mBlurePositionType = 0;
  fVar1 = d_camera::_6431;
  (this->mBlurePosition).x = d_camera::_6431;
  (this->mBlurePosition).y = fVar1;
  fVar1 = d_camera::0_0;
  (this->mBlurePosition).z = d_camera::0_0;
  fVar2 = d_camera::_14649;
  (this->mBlureScale).x = d_camera::_14649;
  (this->mBlureScale).y = fVar2;
  (this->mBlureScale).z = fVar1;
  *(undefined2 *)&this->field_0x594 = 0;
  *(undefined2 *)&this->field_0x596 = 0;
  *(undefined2 *)&this->field_0x598 = 0;
  this->mBlureTimer = 0;
  return;
}


/* __thiscall dCamera_c::SetBlureAlpha(float) */

void __thiscall dCamera_c::SetBlureAlpha(dCamera_c *this,float param_1)

{
  this->mBlureAlpha = param_1;
  return;
}


/* __thiscall dCamera_c::SetBlureScale(float,
                                       float,
                                       float) */

void __thiscall dCamera_c::SetBlureScale(dCamera_c *this,float param_1,float param_2,float param_3)

{
  (this->mBlureScale).x = param_1;
  (this->mBlureScale).y = param_2;
  (this->mBlureScale).z = param_3;
  return;
}


/* __thiscall dCamera_c::SetBlureScale(float) */

void __thiscall dCamera_c::SetBlureScale(dCamera_c *this,float param_1)

{
  (this->mBlureScale).x = param_1;
  (this->mBlureScale).y = param_1;
  (this->mBlureScale).z = d_camera::0_0;
  return;
}


/* WARNING: Inlined function: FUN_80328ea8 */
/* WARNING: Inlined function: FUN_80328ef4 */
/* __thiscall dCamera_c::SetBlurePosition(float,
                                          float,
                                          float) */

void __thiscall
dCamera_c::SetBlurePosition(dCamera_c *this,float param_1,float param_2,float param_3)

{
  double dVar1;
  double dVar2;
  double dVar3;
  
  dVar3 = (double)param_3;
  dVar2 = (double)param_2;
  dVar1 = (double)param_1;
  SetBlurePositionType(this,1);
  (this->mBlurePosition).x = (float)dVar1;
  (this->mBlurePosition).y = (float)dVar2;
  (this->mBlurePosition).z = (float)dVar3;
  return;
}


/* __thiscall dCamera_c::SetBlurePositionType(int) */

void __thiscall dCamera_c::SetBlurePositionType(dCamera_c *this,int param_1)

{
  this->mBlurePositionType = param_1;
  return;
}


/* __thiscall dCamera_c::SetBlureTimer(long) */

void __thiscall dCamera_c::SetBlureTimer(dCamera_c *this,long param_1)

{
  this->mBlureTimer = param_1;
  return;
}


/* __thiscall dCamera_c::SubjectLockOn(fopAc_ac_c *) */

undefined4 __thiscall dCamera_c::SubjectLockOn(dCamera_c *this,fopAc_ac_c *param_1)

{
  this->mEventFlags = this->mEventFlags | 0x3000000;
  this->mpLockonTarget = param_1;
  return 1;
}


/* __thiscall dCamera_c::SubjectLockOff(void) */

undefined4 __thiscall dCamera_c::SubjectLockOff(dCamera_c *this)

{
  this->mEventFlags = this->mEventFlags & 0xfcffffff;
  this->mpLockonTarget = (fopAc_ac_c *)0x0;
  return 1;
}


/* __thiscall dCamera_c::GetForceLockOnActor(void) */

void __thiscall dCamera_c::GetForceLockOnActor(dCamera_c *this)

{
  int local_8 [2];
  
  local_8[0] = this->field_0x130;
  f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,local_8);
  return;
}


/* __thiscall dCamera_c::ForceLockOn(unsigned int) */

undefined4 __thiscall dCamera_c::ForceLockOn(dCamera_c *this,uint param_1)

{
  undefined4 uVar1;
  
  this->field_0x130 = param_1;
  this->field_0x138 = 0;
  uVar1 = GetForceLockOnActor(this);
  *(undefined4 *)&this->field_0x134 = uVar1;
  return 1;
}


/* __thiscall dCamera_c::ForceLockOff(unsigned int) */

undefined4 __thiscall dCamera_c::ForceLockOff(dCamera_c *this,uint param_1)

{
  if ((param_1 != this->field_0x130) && (param_1 != 0xffffffff)) {
    return 0;
  }
  this->field_0x130 = -1;
  return 1;
}


/* __thiscall dCamera_c::SetExtendedPosition(cXyz *) */

undefined4 __thiscall dCamera_c::SetExtendedPosition(dCamera_c *this,cXyz *param_1)

{
  *(float *)&this->field_0xec = param_1->x;
  *(float *)&this->field_0xf0 = param_1->y;
  *(float *)&this->field_0xf4 = param_1->z;
  return 1;
}


/* __thiscall dCamera_c::ScopeViewMsgModeOff(void) */

undefined4 __thiscall dCamera_c::ScopeViewMsgModeOff(dCamera_c *this)

{
  this->mEventFlags = this->mEventFlags & 0xffbfffff;
  return 1;
}


namespace d_camera {

/* __stdcall dCam_isManual(camera_class *) */

uint dCam_isManual(int param_1)

{
  return *(uint *)(param_1 + 0x750) >> 5 & 1;
}


/* __stdcall dCam_getAngleY(camera_class *) */

void dCam_getAngleY(camera_class *param_1)

{
  ::cSAngle::Inv(&(param_1->mBody).field_0xe);
  return;
}


/* __stdcall dCam_getAngleX(camera_class *) */

int dCam_getAngleX(camera_class *param_1)

{
  return (int)(param_1->mBody).field_0xc;
}


/* __stdcall dCam_getControledAngleY(camera_class *) */

cSAngle dCam_getControledAngleY(camera_class *param_1)

{
  cSAngle cVar1;
  
  cVar1 = ::dCamera_c::U2(&param_1->mBody);
  return cVar1;
}


/* __stdcall dCam_getCamera(void) */

camera_class * dCam_getCamera(void)

{
  return d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera;
}


/* __stdcall dCam_getBody(void) */

dCamera_c * dCam_getBody(void)

{
  camera_class *pcVar1;
  
  pcVar1 = dCam_getCamera();
  return &pcVar1->mBody;
}


/* __stdcall preparation(camera_process_class *) */

void preparation(camera_class *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = f_op_camera_mng::fopCamM_GetParam(param_1);
  iVar4 = (char)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[iVar5].mDlstWindowIdx * 0x2c;
  fVar3 = 1_333333 * f_ap_game::g_HIO.aspectRatio;
  fVar1 = *(float *)((int)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mDlstWindow + iVar4 + 0xc);
  fVar2 = *(float *)((int)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mDlstWindow + iVar4 + 8);
  (param_1->mBody).field_0x5ec = fVar2;
  (param_1->mBody).field_0x5f0 = fVar1;
  (param_1->mBody).field_0x604 = fVar2 / fVar1;
  param_1->mAspect = fVar3;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[iVar5].field_0x8 =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[iVar5].field_0x8 & 0xffffffdc;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall view_setup(camera_process_class *) */

void view_setup(camera_class *pCam)

{
  float fVar1;
  int camIdx;
  stage_stag_info_class *pStagInfo;
  stage_stag_info_class *pStag;
  dDlst_window_c *pWindow;
  
  camIdx = f_op_camera_mng::fopCamM_GetParam(pCam);
  pWindow = (dDlst_window_c *)
            ((int)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mDlstWindow +
            (char)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[camIdx].mDlstWindowIdx * 0x2c
            );
  m_Do_mtx::mDoMtx_lookAt
            (&pCam->mViewMtx,&pCam->mEyePos,&pCam->mCenterPos,&pCam->mUpVec,(int)pCam->mBank);
  mtx::PSMTXCopy(&pCam->mViewMtx,&pCam->mViewMtxNoTrans);
  fVar1 = 0_0;
  (pCam->mViewMtxNoTrans).m[3] = 0_0;
  (pCam->mViewMtxNoTrans).m[1][3] = fVar1;
  (pCam->mViewMtxNoTrans).m[2][3] = fVar1;
  d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x22c = pWindow;
  d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x230 = pWindow;
  d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpCamera = pCam;
  if (d_com_inf_game::g_dComIfG_gameInfo.mbCamOverrideFarPlane == 0) {
    pStag = (stage_stag_info_class *)
            (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)
                      (0x803c9d58);
    fVar1 = (float)((double)CONCAT44(0x43300000,pStag->mSchbitEnableAndFarPlane & 0xffff) - _9014);
  }
  else {
    fVar1 = pCam->mFarPlane;
  }
  mDoLib_clipper::setup(pCam->mFovY,pCam->mAspect,pCam->mNearPlane,fVar1);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x8017c27c) */
/* WARNING: Type propagation algorithm not settling */
/* __stdcall store(camera_process_class *) */

void store(camera_class *pCamera)

{
  int iVar1;
  dDemo_camera_c *pDemoCamera;
  stage_stag_info_class *pStage;
  stage_stag_info_class *pStag_;
  short sVar2;
  dCamera_c *this;
  undefined4 uVar3;
  undefined8 in_f31;
  double oldFovy;
  cSAngle bank;
  short local_86;
  cSAngle local_84;
  cSAngle bank_;
  short local_7e;
  cXyz up_;
  cXyz eye_;
  cXyz center_;
  cXyz oldUp;
  cXyz oldEye;
  cXyz oldCenter;
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  this = &pCamera->mBody;
  iVar1 = f_op_camera_mng::fopCamM_GetParam(pCamera);
  oldCenter.x = (pCamera->mCenterPos).x;
  oldCenter.y = (pCamera->mCenterPos).y;
  oldCenter.z = (pCamera->mCenterPos).z;
  oldEye.x = (pCamera->mEyePos).x;
  oldEye.y = (pCamera->mEyePos).y;
  oldEye.z = (pCamera->mEyePos).z;
  oldUp.x = (pCamera->mUpVec).x;
  oldUp.y = (pCamera->mUpVec).y;
  oldUp.z = (pCamera->mUpVec).z;
  ::cSAngle::cSAngle(&bank_,pCamera->mBank);
  oldFovy = (double)pCamera->mFovY;
  pDemoCamera = dDemo_object_c::getActiveCamera
                          (&(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpDemoMgr)->mDemoObj);
  if (pDemoCamera == (dDemo_camera_c *)0x0) {
    if (((pCamera->mBody).mEventFlags & 1) == 0) {
      ::dCamera_c::Center(&center_,this);
      oldCenter.x = center_.x;
      oldCenter.y = center_.y;
      oldCenter.z = center_.z;
      ::dCamera_c::Eye(&eye_,this);
      oldEye.x = eye_.x;
      oldEye.y = eye_.y;
      oldEye.z = eye_.z;
      ::dCamera_c::Up(&up_,this);
      oldUp.x = up_.x;
      oldUp.y = up_.y;
      oldUp.z = up_.z;
      ::dCamera_c::Bank(&bank,this);
      bank_ = bank;
      oldFovy = (double)((pCamera->mBody).mFovY + (pCamera->mBody).mFovYShake);
    }
  }
  else {
    if ((pDemoCamera->mFlags & 0x40) != 0) {
      oldCenter.x = (pDemoCamera->mCenterPos).x;
      oldCenter.y = (pDemoCamera->mCenterPos).y;
      oldCenter.z = (pDemoCamera->mCenterPos).z;
    }
    if ((pDemoCamera->mFlags & 0x10) != 0) {
      oldEye.x = (pDemoCamera->mEyePos).x;
      oldEye.y = (pDemoCamera->mEyePos).y;
      oldEye.z = (pDemoCamera->mEyePos).z;
    }
    if ((pDemoCamera->mFlags & 0x20) != 0) {
      oldUp.x = (pDemoCamera->mUpVec).x;
      oldUp.y = (pDemoCamera->mUpVec).y;
      oldUp.z = (pDemoCamera->mUpVec).z;
    }
    if ((pDemoCamera->mFlags & 0x80) != 0) {
      ::cSAngle::cSAngle(&local_84,(short)(int)(_8358 * -pDemoCamera->mBank));
      bank_ = local_84;
    }
    if ((pDemoCamera->mFlags & 4) != 0) {
      oldFovy = (double)pDemoCamera->mFovy;
    }
  }
  (pCamera->mCenterPos).x = oldCenter.x;
  (pCamera->mCenterPos).y = oldCenter.y;
  (pCamera->mCenterPos).z = oldCenter.z;
  (pCamera->mEyePos).x = oldEye.x;
  (pCamera->mEyePos).y = oldEye.y;
  (pCamera->mEyePos).z = oldEye.z;
  (pCamera->mUpVec).x = oldUp.x;
  (pCamera->mUpVec).y = oldUp.y;
  (pCamera->mUpVec).z = oldUp.z;
  ((cSAngle *)&pCamera->mBank)->v = bank_;
  pCamera->mFovY = (float)oldFovy;
  if ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[iVar1].field_0x8 & 8) == 0) {
    pStage = (stage_stag_info_class *)
             (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)
                       (0x803c9d58);
    pCamera->mNearPlane = pStage->mNearPlane;
  }
  else {
    pCamera->mNearPlane = 30_0;
  }
  pStag_ = (stage_stag_info_class *)
           (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)
                     (0x803c9d58);
  pCamera->mFarPlane = pStag_->mFarPlane;
  sVar2 = ::cSAngle::Inv(&(pCamera->mBody).field_0xe);
  pCamera->field_0x232 = sVar2;
  pCamera->field_0x230 = (pCamera->mBody).field_0xc;
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return;
}


/* __stdcall camera_execute(camera_process_class *) */

undefined4 camera_execute(camera_class *pCam)

{
  dDemo_camera_c *pdVar1;
  
  preparation();
  pdVar1 = dDemo_object_c::getActiveCamera
                     (&(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpDemoMgr)->mDemoObj);
  if (pdVar1 != (dDemo_camera_c *)0x0) {
    ::dCamera_c::ResetView(&pCam->mBody);
  }
  if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr.mCameraPlay == 0) {
    mDoGph_gInf_c::mAutoForcus = 1;
  }
  if (((pCam->mBody).field_0x4 == 0) || ((pCam->mBody).field_0x5 != 0)) {
    ::dCamera_c::NotRun(&pCam->mBody);
  }
  else {
    ::dCamera_c::Run(&pCam->mBody);
  }
  ::dCamera_c::CalcTrimSize(&pCam->mBody);
  store(pCam);
  view_setup(pCam);
  return 1;
}


/* WARNING: Inlined function: FUN_80328f24 */
/* WARNING: Inlined function: FUN_80328f70 */
/* WARNING: Removing unreachable block (ram,0x8017c70c) */
/* __stdcall camera_draw(camera_process_class *) */

undefined4 camera_draw(camera_class *this)

{
  float fVar1;
  int iVar2;
  ulong uVar3;
  byte bVar4;
  cBgS_PolyPassChk *pcVar5;
  undefined4 uVar6;
  double dVar7;
  undefined8 in_f31;
  float local_c8;
  float local_c4;
  float local_c0;
  cBgS_GndChk local_bc;
  cBgS_PolyPassChk local_7c;
  undefined local_70 [8];
  longlong local_68;
  undefined4 local_60;
  uint uStack92;
  undefined4 local_58;
  uint uStack84;
  undefined4 local_50;
  uint uStack76;
  undefined4 local_48;
  uint uStack68;
  undefined auStack8 [8];
  
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  iVar2 = f_op_camera_mng::fopCamM_GetParam(this);
  bVar4 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[iVar2].mDlstWindowIdx;
  uVar3 = f_op_camera_mng::fopCamM_GetParam(this);
  uStack92 = (uint)(this->mBody).field_0x5f8;
  local_68 = (longlong)(int)uStack92;
  uStack92 = uStack92 ^ 0x80000000;
  local_60 = 0x43300000;
  uStack84 = (uint)*(ushort *)(mDoMch_render_c::mRenderModeObj + 4);
  local_58 = 0x43300000;
  uStack76 = (uint)*(ushort *)(mDoMch_render_c::mRenderModeObj + 6);
  local_50 = 0x43300000;
  local_48 = 0x43300000;
  uStack68 = uStack92;
  dDlst_window_c::setScissor
            ((dDlst_window_c *)
             ((int)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mDlstWindow + (char)bVar4 * 0x2c),0_0,
             (float)((double)CONCAT44(0x43300000,uStack92) - _5738),
             (float)((double)CONCAT44(0x43300000,uStack84) - _9014),
             (float)((double)CONCAT44(0x43300000,uStack76) - _9014) -
             _9007 * (float)((double)CONCAT44(0x43300000,uStack92) - _5738));
  mtx::C_MTXPerspective
            ((double)this->mFovY,(double)this->mAspect,(double)this->mNearPlane,
             (double)this->mFarPlane,&this->mProjMtx);
  m_Do_mtx::mDoMtx_lookAt
            (&this->mViewMtx,&this->mEyePos,&this->mCenterPos,&this->mUpVec,(int)this->mBank);
  mtx::PSMTXCopy(&this->mViewMtx,&J3DGraphBase::j3dSys.mCurViewMtx);
  mtx::PSMTXInverse(&this->mViewMtx,&this->mInvViewMtx);
  JAIZelBasic::getCameraInfo
            (JAIZelBasic::zel_basic,(Vec *)&this->mEyePos,(float *)&J3DGraphBase::j3dSys,uVar3);
  ::cBgS_GndChk::cBgS_GndChk(&local_bc);
  pcVar5 = &local_7c;
  local_7c.mbObjThrough = 0;
  local_7c.mbCamThrough = 0;
  local_7c.mbLinkThrough = 0;
  local_7c.mbArrowsAndLightThrough = 0;
  local_7c.mbBombThrough = 0;
  local_7c.mbBoomerangThrough = 0;
  local_7c.mbHookshotThrough = 0;
  local_70._4_4_ = 1;
  local_bc.parent.vtbl = &::dBgS_GndChk::__vt;
  local_bc.mPolyInfo.vtbl = &cBgS_PolyInfo__vtbl_80371f08;
  local_7c.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
  local_70._0_4_ = &PTR_80371f20;
  local_bc.parent.mpGrpPassChk = (cBgS_GrpPassChk *)pcVar5;
  if (pcVar5 != (cBgS_PolyPassChk *)0x0) {
    local_bc.parent.mpGrpPassChk = (cBgS_GrpPassChk *)local_70;
  }
  local_bc.mPos.x = (this->mEyePos).x;
  local_bc.mPos.y = (this->mEyePos).y;
  local_bc.mPos.z = (this->mEyePos).z;
  local_bc.parent.mpPolyPassChk = pcVar5;
  dVar7 = (double)::cBgS::GroundCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,&local_bc);
  if ((double)_5126 == dVar7) {
    JAIZelBasic::setCameraPolygonPos(JAIZelBasic::zel_basic,(Vec *)0x0);
  }
  else {
    uVar3 = dBgS::GetMtrlSndId(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,&local_bc.mPolyInfo);
    JAIZelBasic::getCameraMapInfo(JAIZelBasic::zel_basic,uVar3);
    bVar4 = dBgS::GetGrpSoundId(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,&local_bc.mPolyInfo);
    JAIZelBasic::setCameraGroupInfo(JAIZelBasic::zel_basic,bVar4);
    local_c8 = (this->mEyePos).x;
    local_c4 = (float)dVar7;
    local_c0 = (this->mEyePos).z;
    JAIZelBasic::setCameraPolygonPos(JAIZelBasic::zel_basic,(Vec *)&local_c8);
  }
  mtx::PSMTXCopy(&this->mViewMtx,&this->mViewMtxNoTrans);
  fVar1 = 0_0;
  (this->mViewMtxNoTrans).m[3] = 0_0;
  (this->mViewMtxNoTrans).m[1][3] = fVar1;
  (this->mViewMtxNoTrans).m[2][3] = fVar1;
  m_Do_mtx::mDoMtx_concatProjView(&this->mProjMtx,&this->mViewMtx,&this->field_0x1a0);
  ::dCamera_c::Draw(&this->mBody);
  iVar2 = f_pc_leaf::fpcLf_GetPriority(&this->parent);
  if ((short)iVar2 != 1) {
    f_op_camera_mng::fopCamM_GetParam(this);
    iVar2 = f_op_overlap_mng::fopOvlpM_IsDoingReq();
    if (iVar2 == 0) {
      dMap_c::draw((dMap_c *)(int)(char)dStage_roomControl_c::mStayNo,
                   ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).parent.
                   mCurrent.mPos.x,
                   ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).parent.
                   mCurrent.mPos.z,(int)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor,
                   ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).parent.
                   mCurrent.mPos.y);
    }
  }
  local_7c.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
  local_70._0_4_ = &PTR_80371f20;
  if (pcVar5 != (cBgS_PolyPassChk *)0x0) {
    local_7c.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
    local_70._0_4_ = &PTR_80371f68;
    if (((undefined *)register0x00000004 != (undefined *)0x70) &&
       (local_70._0_4_ = &::dBgS_GrpPassChk::__vt,
       (undefined *)register0x00000004 != (undefined *)0x70)) {
      local_70._0_4_ = &::cBgS_GrpPassChk::__vt;
    }
    if ((pcVar5 != (cBgS_PolyPassChk *)0x0) &&
       (local_7c.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
       pcVar5 != (cBgS_PolyPassChk *)0x0)) {
      local_7c.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
    }
  }
  local_bc.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_GndChk::__vt;
  local_bc.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
  cBgS_Chk::_cBgS_Chk(&local_bc.parent);
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  return 1;
}


/* __stdcall init_phase1(camera_class *) */

undefined4 init_phase1(camera_class *param_1)

{
  ulong uVar1;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  uVar1 = f_op_camera_mng::fopCamM_GetParam(param_1);
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[uVar1].mpCamera = param_1;
  param_1->field_0x22c = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[uVar1].mDlstWindowIdx;
  param_1->field_0x22d = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[uVar1].mCamIdx;
  param_1->field_0x22e = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[uVar1].field_0x6;
  local_18 = _18109;
  local_14 = DAT_8035eb24;
  local_10 = DAT_8035eb28;
  JAIZelBasic::getCameraInfo
            (JAIZelBasic::zel_basic,(Vec *)&local_18,(float *)&J3DGraphBase::j3dSys,uVar1);
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.field_0x4841 = 0;
  mDoGph_gInf_c::mAutoForcus = 1;
  return 2;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x8017c960) */
/* __stdcall init_phase2(camera_class *) */

undefined4 init_phase2(camera_class *pCamera)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  stage_stag_info_class *pStag;
  stage_stag_info_class *pStag_;
  daPy_lk_c *pAttn;
  undefined4 uVar6;
  undefined8 in_f31;
  double farPlane;
  undefined auStack8 [8];
  
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  iVar3 = f_op_camera_mng::fopCamM_GetParam(pCamera);
  iVar4 = f_op_camera_mng::fopCamM_GetParam(pCamera);
  pAttn = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor
          [(char)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[iVar4].mCamIdx * 2];
  if (pAttn == (daPy_lk_c *)0x0) {
    uVar5 = 0;
  }
  else {
    f_op_actor_mng::fopAcM_setStageLayer((fopAc_ac_c *)pAttn);
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.field_0x4841 = 1;
    if (&pCamera->mBody != (dCamera_c *)0x0) {
      ::dCamera_c::dCamera_c(&pCamera->mBody,pCamera);
    }
    farPlane = (double)_18178;
    pStag = (stage_stag_info_class *)
            (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)
                      (0x803c9d58);
    if (pStag != (stage_stag_info_class *)0x0) {
      (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)
                (0x803c9d58);
      pStag_ = (stage_stag_info_class *)
               (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)
                         (0x803c9d58);
      farPlane = (double)pStag_->mFarPlane;
    }
    iVar3 = (char)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[iVar3].mDlstWindowIdx * 0x2c;
    pCamera->mNearPlane = 1_0;
    pCamera->mFarPlane = (float)farPlane;
    pCamera->mFovY = 30_0;
    pCamera->mAspect =
         (*(float *)((int)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mDlstWindow + iVar3 + 8) /
         *(float *)((int)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mDlstWindow + iVar3 + 0xc)) *
         f_ap_game::g_HIO.aspectRatio;
    fVar1 = (pAttn->parent).parent.mCurrent.mPos.z;
    fVar2 = (pAttn->parent).parent.mCurrent.mPos.y;
    (pCamera->mCenterPos).x = (pAttn->parent).parent.mCurrent.mPos.x;
    (pCamera->mCenterPos).y = fVar2;
    (pCamera->mCenterPos).z = fVar1;
    pCamera->mBank = 0;
    store(pCamera);
    view_setup(pCamera);
    uVar5 = 2;
  }
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  return uVar5;
}


/* __stdcall camera_create(camera_class *) */

void camera_create(void *param_1)

{
  d_com_lib_game::dComLbG_PhaseHandler
            ((request_of_phase_process_class *)((int)param_1 + 0x23c),
             (cPhs__Handler *)&l_method_18182,param_1);
  return;
}


/* __stdcall camera_delete(camera_process_class *) */

undefined4 camera_delete(int param_1)

{
  ::dCamera_c::_dCamera_c((dCamera_c *)(param_1 + 0x244));
  return 1;
}


/* __stdcall is_camera_delete(void *) */

undefined4 is_camera_delete(void)

{
  return 1;
}

}

/* __thiscall dCamForcusLine::Init(void) */

void __thiscall dCamForcusLine::Init(dCamForcusLine *this)

{
  float fVar1;
  float fVar2;
  
  *(undefined *)&this->field_0x49 = 0;
  *(undefined *)&this->field_0x48 = 1;
  fVar2 = d_camera::240_0;
  fVar1 = d_camera::0_0;
  *(float *)&this->field_0x38 = d_camera::320_0;
  *(float *)&this->field_0x3c = fVar2;
  *(float *)&this->field_0x40 = fVar1;
  *(undefined *)&this->field_0x44 = 0xff;
  *(undefined *)&this->field_0x45 = 0xff;
  *(undefined *)&this->field_0x46 = 0xff;
  *(undefined *)&this->field_0x47 = 0x60;
  *(undefined4 *)&this->field_0x4c = 100;
  *(undefined4 *)&this->field_0x50 = 100;
  *(undefined4 *)&this->field_0x54 = 100;
  *(undefined2 *)&this->field_0x58 = 0x50;
  *(undefined2 *)&this->field_0x5a = 0;
  *(undefined2 *)&this->field_0x5c = 4;
  *(undefined2 *)&this->field_0x5e = 4;
  fVar2 = d_camera::180_0;
  *(float *)&this->field_0x68 = d_camera::180_0;
  *(float *)&this->field_0x6c = fVar1;
  *(float *)&this->field_0x60 = fVar2;
  *(float *)&this->field_0x64 = d_camera::60_0;
  return;
}


/* __thiscall dCamForcusLine::Draw(void) */

void __thiscall dCamForcusLine::Draw(dCamForcusLine *this)

{
  if (*(char *)&this->field_0x49 != '\0') {
    if (*(char *)&this->field_0x48 == '\0') {
      cM_rnd_c::init(&this->mRnd,*(int *)&this->field_0x4c,*(int *)&this->field_0x50,
                     *(int *)&this->field_0x54);
    }
    dDlst_effectLine_c::update
              ((dDlst_effectLine_c *)this,(cXyz *)&this->field_0x38,(_GXColor *)&this->field_0x44,
               *(ushort *)&this->field_0x58,*(ushort *)&this->field_0x5a,
               *(ushort *)&this->field_0x5c,*(ushort *)&this->field_0x5e,*(float *)&this->field_0x60
               ,*(float *)&this->field_0x64,*(float *)&this->field_0x68,*(float *)&this->field_0x6c)
    ;
  }
  return;
}


/* __thiscall dCamForcusLine::Off(void) */

uint __thiscall dCamForcusLine::Off(dCamForcusLine *this)

{
  uint uVar1;
  
  *(undefined *)&this->field_0x49 = 0;
  uVar1 = countLeadingZeros((uint)*(byte *)&this->field_0x49);
  return uVar1 >> 5;
}


/* __thiscall d2DBSplinePath::~d2DBSplinePath(void) */

void __thiscall d2DBSplinePath::_d2DBSplinePath(d2DBSplinePath *this)

{
  short in_r4;
  
  if ((this != (d2DBSplinePath *)0x0) && (this->vtbl = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


namespace dCamera_c {

/* __thiscall BG::~BG(void) */

void __thiscall BG::_BG(BG *this)

{
  cBgS_Chk *this_00;
  short in_r4;
  
  if (this != (BG *)0x0) {
    if ((this != (BG *)0xffffffa4) &&
       (this_00 = (cBgS_Chk *)&this->field_0x60, this_00 != (cBgS_Chk *)0x0)) {
      *(undefined1 **)&this->field_0x70 = &dBgS_CamGndChk::__vt;
      (this->field_0x74).vtbl = (cBgS_PolyInfo__vtbl *)&DAT_80391200;
      *(undefined **)&this->field_0xa0 = &DAT_8039120c;
      *(undefined **)&this->field_0xac = &DAT_80391218;
      if (this_00 != (cBgS_Chk *)0x0) {
        *(cBgS_Chk__vtbl **)&this->field_0x70 = &::dBgS_GndChk::__vt;
        (this->field_0x74).vtbl = &cBgS_PolyInfo__vtbl_80371f08;
        *(undefined ***)&this->field_0xa0 = &PTR_80371f14;
        *(undefined ***)&this->field_0xac = &PTR_80371f20;
        if (this != (BG *)0xffffff60) {
          *(undefined ***)&this->field_0xa0 = &::dBgS_Chk::__vt;
          *(undefined ***)&this->field_0xac = &PTR_80371f68;
          if ((this != (BG *)0xffffff54) &&
             (*(undefined ***)&this->field_0xac = &::dBgS_GrpPassChk::__vt, this != (BG *)0xffffff54
             )) {
            *(undefined ***)&this->field_0xac = &::cBgS_GrpPassChk::__vt;
          }
          if ((this != (BG *)0xffffff60) &&
             (*(undefined ***)&this->field_0xa0 = &::dBgS_PolyPassChk::__vt,
             this != (BG *)0xffffff60)) {
            *(undefined ***)&this->field_0xa0 = &::cBgS_PolyPassChk::__vt;
          }
        }
        if (this_00 != (cBgS_Chk *)0x0) {
          *(undefined1 **)&this->field_0x70 = &::cBgS_GndChk::__vt;
          (this->field_0x74).vtbl = (cBgS_PolyInfo__vtbl *)&PTR_80371e90;
          if (this != (BG *)0xffffff8c) {
            (this->field_0x74).vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
          }
          cBgS_Chk::_cBgS_Chk(this_00);
        }
      }
    }
    if (this != (BG *)0x0) {
      if (this != (BG *)0xfffffffc) {
        *(undefined1 **)&this->field_0x14 = &dBgS_CamGndChk::__vt;
        *(undefined **)&this->field_0x24 = &DAT_80391200;
        *(undefined **)&this->field_0x44 = &DAT_8039120c;
        *(undefined **)&this->field_0x50 = &DAT_80391218;
        if (this != (BG *)0xfffffffc) {
          *(cBgS_Chk__vtbl **)&this->field_0x14 = &::dBgS_GndChk::__vt;
          *(cBgS_PolyInfo__vtbl **)&this->field_0x24 = &cBgS_PolyInfo__vtbl_80371f08;
          *(undefined ***)&this->field_0x44 = &PTR_80371f14;
          *(undefined ***)&this->field_0x50 = &PTR_80371f20;
          if (this != (BG *)0xffffffbc) {
            *(undefined ***)&this->field_0x44 = &::dBgS_Chk::__vt;
            *(undefined ***)&this->field_0x50 = &PTR_80371f68;
            if (this != (BG *)0xffffffb0) {
              *(undefined ***)&this->field_0x50 = &::dBgS_GrpPassChk::__vt;
              if (this != (BG *)0xffffffb0) {
                *(undefined ***)&this->field_0x50 = &::cBgS_GrpPassChk::__vt;
              }
            }
            if (this != (BG *)0xffffffbc) {
              *(undefined ***)&this->field_0x44 = &::dBgS_PolyPassChk::__vt;
              if (this != (BG *)0xffffffbc) {
                *(undefined ***)&this->field_0x44 = &::cBgS_PolyPassChk::__vt;
              }
            }
          }
          if (this != (BG *)0xfffffffc) {
            *(undefined1 **)&this->field_0x14 = &::cBgS_GndChk::__vt;
            *(undefined ***)&this->field_0x24 = &PTR_80371e90;
            if (this != (BG *)0xffffffe8) {
              *(undefined ***)&this->field_0x24 = &::cBgS_PolyInfo::__vt;
            }
            cBgS_Chk::_cBgS_Chk((cBgS_Chk *)&this->field_0x4);
          }
        }
      }
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* __thiscall BG::BG(void) */

void __thiscall BG::BG(BG *this)

{
  int iVar1;
  
  ::cBgS_GndChk::cBgS_GndChk((cBgS_GndChk *)&this->field_0x4);
  *(undefined ***)&this->field_0x44 = &::cBgS_PolyPassChk::__vt;
  *(undefined ***)&this->field_0x44 = &::dBgS_PolyPassChk::__vt;
  *(undefined *)&this->field_0x48 = 0;
  *(undefined *)&this->field_0x49 = 0;
  *(undefined *)&this->field_0x4a = 0;
  *(undefined *)&this->field_0x4b = 0;
  *(undefined *)&this->field_0x4c = 0;
  *(undefined *)&this->field_0x4d = 0;
  *(undefined *)&this->field_0x4e = 0;
  *(undefined ***)&this->field_0x50 = &::cBgS_GrpPassChk::__vt;
  *(undefined ***)&this->field_0x50 = &::dBgS_GrpPassChk::__vt;
  *(undefined4 *)&this->field_0x54 = 1;
  *(undefined ***)&this->field_0x44 = &::dBgS_Chk::__vt;
  *(undefined ***)&this->field_0x50 = &PTR_80371f68;
  *(cBgS_Chk__vtbl **)&this->field_0x14 = &::dBgS_GndChk::__vt;
  *(cBgS_PolyInfo__vtbl **)&this->field_0x24 = &cBgS_PolyInfo__vtbl_80371f08;
  *(undefined ***)&this->field_0x44 = &PTR_80371f14;
  *(undefined ***)&this->field_0x50 = &PTR_80371f20;
  (((cBgS_GndChk *)&this->field_0x4)->parent).mpPolyPassChk = (cBgS_PolyPassChk *)&this->field_0x44;
  iVar1 = &this->field_0x44;
  if (iVar1 != 0) {
    iVar1 = &this->field_0x50;
  }
  *(int *)&this->field_0x8 = iVar1;
  *(undefined1 **)&this->field_0x14 = &dBgS_CamGndChk::__vt;
  *(undefined **)&this->field_0x24 = &DAT_80391200;
  *(undefined **)&this->field_0x44 = &DAT_8039120c;
  *(undefined **)&this->field_0x50 = &DAT_80391218;
  *(undefined *)&this->field_0x49 = 1;
  ::cBgS_GndChk::cBgS_GndChk((cBgS_GndChk *)&this->field_0x60);
  *(undefined ***)&this->field_0xa0 = &::cBgS_PolyPassChk::__vt;
  *(undefined ***)&this->field_0xa0 = &::dBgS_PolyPassChk::__vt;
  *(undefined *)&this->field_0xa4 = 0;
  *(undefined *)&this->field_0xa5 = 0;
  *(undefined *)&this->field_0xa6 = 0;
  *(undefined *)&this->field_0xa7 = 0;
  *(undefined *)&this->field_0xa8 = 0;
  *(undefined *)&this->field_0xa9 = 0;
  *(undefined *)&this->field_0xaa = 0;
  *(undefined ***)&this->field_0xac = &::cBgS_GrpPassChk::__vt;
  *(undefined ***)&this->field_0xac = &::dBgS_GrpPassChk::__vt;
  *(undefined4 *)(this + 1) = 1;
  *(undefined ***)&this->field_0xa0 = &::dBgS_Chk::__vt;
  *(undefined ***)&this->field_0xac = &PTR_80371f68;
  *(cBgS_Chk__vtbl **)&this->field_0x70 = &::dBgS_GndChk::__vt;
  (this->field_0x74).vtbl = &cBgS_PolyInfo__vtbl_80371f08;
  *(undefined ***)&this->field_0xa0 = &PTR_80371f14;
  *(undefined ***)&this->field_0xac = &PTR_80371f20;
  (((cBgS_GndChk *)&this->field_0x60)->parent).mpPolyPassChk = (cBgS_PolyPassChk *)&this->field_0xa0
  ;
  iVar1 = &this->field_0xa0;
  if (iVar1 != 0) {
    iVar1 = &this->field_0xac;
  }
  *(int *)&this->field_0x64 = iVar1;
  *(undefined1 **)&this->field_0x70 = &dBgS_CamGndChk::__vt;
  (this->field_0x74).vtbl = (cBgS_PolyInfo__vtbl *)&DAT_80391200;
  *(undefined **)&this->field_0xa0 = &DAT_8039120c;
  *(undefined **)&this->field_0xac = &DAT_80391218;
  *(undefined *)&this->field_0xa5 = 1;
  return;
}

}

/* __thiscall dBgS_CamGndChk::~dBgS_CamGndChk(void) */

void __thiscall dBgS_CamGndChk::_dBgS_CamGndChk(dBgS_CamGndChk *this)

{
  short in_r4;
  
  if (this != (dBgS_CamGndChk *)0x0) {
    *(undefined1 **)(this + 0x10) = &__vt;
    *(undefined **)(this + 0x20) = &DAT_80391200;
    *(undefined **)(this + 0x40) = &DAT_8039120c;
    *(undefined **)(this + 0x4c) = &DAT_80391218;
    if (this != (dBgS_CamGndChk *)0x0) {
      *(cBgS_Chk__vtbl **)(this + 0x10) = &::dBgS_GndChk::__vt;
      *(cBgS_PolyInfo__vtbl **)(this + 0x20) = &cBgS_PolyInfo__vtbl_80371f08;
      *(undefined ***)(this + 0x40) = &PTR_80371f14;
      *(undefined ***)(this + 0x4c) = &PTR_80371f20;
      if (this != (dBgS_CamGndChk *)0xffffffc0) {
        *(undefined ***)(this + 0x40) = &::dBgS_Chk::__vt;
        *(undefined ***)(this + 0x4c) = &PTR_80371f68;
        if (this != (dBgS_CamGndChk *)0xffffffb4) {
          *(undefined ***)(this + 0x4c) = &::dBgS_GrpPassChk::__vt;
          if (this != (dBgS_CamGndChk *)0xffffffb4) {
            *(undefined ***)(this + 0x4c) = &::cBgS_GrpPassChk::__vt;
          }
        }
        if ((this != (dBgS_CamGndChk *)0xffffffc0) &&
           (*(undefined ***)(this + 0x40) = &::dBgS_PolyPassChk::__vt,
           this != (dBgS_CamGndChk *)0xffffffc0)) {
          *(undefined ***)(this + 0x40) = &::cBgS_PolyPassChk::__vt;
        }
      }
      if (this != (dBgS_CamGndChk *)0x0) {
        *(undefined1 **)(this + 0x10) = &::cBgS_GndChk::__vt;
        *(undefined ***)(this + 0x20) = &PTR_80371e90;
        if (this != (dBgS_CamGndChk *)0xffffffec) {
          *(undefined ***)(this + 0x20) = &::cBgS_PolyInfo::__vt;
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


namespace dCamera_c {

/* __thiscall @class$4017d_camera_cpp::@class$4017d_camera_cpp(void) */

void __thiscall
@class$4017d_camera_cpp::_class_4017d_camera_cpp(_class_4017d_camera_cpp *this)

{
  return;
}


/* __thiscall @class$4017d_camera_cpp::~@class$4017d_camera_cpp(void) */

void __thiscall
@class$4017d_camera_cpp::__class_4017d_camera_cpp(_class_4017d_camera_cpp *this)

{
  short in_r4;
  
  if ((this != (_class_4017d_camera_cpp *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}

}

/* __thiscall daPy_py_c::getRopePos(void) const */

cXyz * __thiscall daPy_py_c::getRopePos(cXyz *__return_storage_ptr__,daPy_py_c *this)

{
  __return_storage_ptr__->x = (this->mRopePos).x;
  __return_storage_ptr__->y = (this->mRopePos).y;
  __return_storage_ptr__->z = (this->mRopePos).z;
  return __return_storage_ptr__;
}


/* __thiscall dCamera_c::setFlag(unsigned long) */

uint __thiscall dCamera_c::setFlag(dCamera_c *this,ulong param_1)

{
  uint uVar1;
  
  uVar1 = this->mEventFlags | param_1;
  this->mEventFlags = uVar1;
  return uVar1;
}


/* __thiscall dCamera_c::chkFlag(unsigned long) */

bool __thiscall dCamera_c::chkFlag(dCamera_c *this,ulong param_1)

{
  return (this->mEventFlags & param_1) != 0;
}


namespace dCamera_c {

/* __thiscall Bank(void) */

cSAngle * Bank(cSAngle *param_1,dCamera_c *param_2)

{
  cSAngle *pcVar1;
  
  pcVar1 = (cSAngle *)cSAngle::operator__(param_1,&param_2->mBank);
  return pcVar1;
}

}

/* __thiscall dCamera_c::Up(void) */

cXyz * __thiscall dCamera_c::Up(cXyz *__return_storage_ptr__,dCamera_c *this)

{
  __return_storage_ptr__->x = (this->mUp).x;
  __return_storage_ptr__->y = (this->mUp).y;
  __return_storage_ptr__->z = (this->mUp).z;
  return __return_storage_ptr__;
}


namespace dCamera_c {

/* __thiscall Center(void) */

cXyz * Center(cXyz *__return_storage_ptr__,dCamera_c *param_1)

{
  cXyz *pcVar1;
  
  pcVar1 = ::cXyz::operator__(__return_storage_ptr__,&param_1->mCenter,&param_1->mCenterShake);
  return pcVar1;
}

}

/* __thiscall dCamParam_c::Flag(long,
                                unsigned short) */

ushort __thiscall dCamParam_c::Flag(dCamParam_c *this,long styleIdx,ushort mask)

{
  return mask & styles[styleIdx].mFlag;
}


/* __thiscall cSAngle::operator =(cSAngle const &) */

void __thiscall cSAngle::operator__(cSAngle *this,cSAngle *param_1)

{
  this->v = param_1->v;
  return;
}


/* __thiscall dCamParam_c::Val(long,
                               int) */

double __thiscall dCamParam_c::Val(dCamParam_c *this,long param_1,int param_2)

{
  return (double)*(float *)(styles[param_1].mMagic + param_2 * 4 + 8);
}


namespace d_camera {

/* __stdcall dComIfGp_evmng_cameraPlay(void) */

int dComIfGp_evmng_cameraPlay(void)

{
  return d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr.mCameraPlay;
}


void __sinit_d_camera_cpp(void)

{
  ::dCamera_c::engine_tbl[0].this_delta = _4291;
  ::dCamera_c::engine_tbl[0].vtbl_offset = DAT_80390a14;
  ::dCamera_c::engine_tbl[0].func = PTR_letCamera_80390a18;
  ::dCamera_c::engine_tbl[1].this_delta = _4292;
  ::dCamera_c::engine_tbl[1].vtbl_offset = DAT_80390a20;
  ::dCamera_c::engine_tbl[1].func = PTR_followCamera_80390a24;
  ::dCamera_c::engine_tbl[2].this_delta = _4293;
  ::dCamera_c::engine_tbl[2].vtbl_offset = DAT_80390a2c;
  ::dCamera_c::engine_tbl[2].func = PTR_lockonCamera_80390a30;
  ::dCamera_c::engine_tbl[3].this_delta = _4294;
  ::dCamera_c::engine_tbl[3].vtbl_offset = DAT_80390a38;
  ::dCamera_c::engine_tbl[3].func = PTR_talktoCamera_80390a3c;
  ::dCamera_c::engine_tbl[4].this_delta = _4295;
  ::dCamera_c::engine_tbl[4].vtbl_offset = DAT_80390a44;
  ::dCamera_c::engine_tbl[4].func = PTR_subjectCamera_80390a48;
  ::dCamera_c::engine_tbl[5].this_delta = _4296;
  ::dCamera_c::engine_tbl[5].vtbl_offset = DAT_80390a50;
  ::dCamera_c::engine_tbl[5].func = PTR_fixedPositionCamera_80390a54;
  ::dCamera_c::engine_tbl[6].this_delta = _4297;
  ::dCamera_c::engine_tbl[6].vtbl_offset = DAT_80390a5c;
  ::dCamera_c::engine_tbl[6].func = PTR_fixedFrameCamera_80390a60;
  ::dCamera_c::engine_tbl[7].this_delta = _4298;
  ::dCamera_c::engine_tbl[7].vtbl_offset = DAT_80390a68;
  ::dCamera_c::engine_tbl[7].func = PTR_towerCamera_80390a6c;
  ::dCamera_c::engine_tbl[8].this_delta = _4299;
  ::dCamera_c::engine_tbl[8].vtbl_offset = DAT_80390a74;
  ::dCamera_c::engine_tbl[8].func = PTR_rideCamera_80390a78;
  ::dCamera_c::engine_tbl[9].this_delta = _4300;
  ::dCamera_c::engine_tbl[9].vtbl_offset = DAT_80390a80;
  ::dCamera_c::engine_tbl[9].func = PTR_hungCamera_80390a84;
  ::dCamera_c::engine_tbl[10].this_delta = _4301;
  ::dCamera_c::engine_tbl[10].vtbl_offset = DAT_80390a8c;
  ::dCamera_c::engine_tbl[10].func = PTR_manualCamera_80390a90;
  ::dCamera_c::engine_tbl[11].this_delta = _4302;
  ::dCamera_c::engine_tbl[11].vtbl_offset = DAT_80390a98;
  ::dCamera_c::engine_tbl[11].func = PTR_eventCamera_80390a9c;
  ::dCamera_c::engine_tbl[12].this_delta = _4303;
  ::dCamera_c::engine_tbl[12].vtbl_offset = DAT_80390aa4;
  ::dCamera_c::engine_tbl[12].func = PTR_crawlCamera_80390aa8;
  ::dCamera_c::engine_tbl[13].this_delta = _4304;
  ::dCamera_c::engine_tbl[13].vtbl_offset = DAT_80390ab0;
  ::dCamera_c::engine_tbl[13].func = PTR_hookshotCamera_80390ab4;
  ::dCamera_c::engine_tbl[14].this_delta = _4305;
  ::dCamera_c::engine_tbl[14].vtbl_offset = DAT_80390abc;
  ::dCamera_c::engine_tbl[14].func = PTR_tornadoCamera_80390ac0;
  ::dCamera_c::engine_tbl[15].this_delta = _4306;
  ::dCamera_c::engine_tbl[15].vtbl_offset = DAT_80390ac8;
  ::dCamera_c::engine_tbl[15].func = PTR_vomitCamera_80390acc;
  ::dCamera_c::engine_tbl[16].this_delta = _4307;
  ::dCamera_c::engine_tbl[16].vtbl_offset = DAT_80390ad4;
  ::dCamera_c::engine_tbl[16].func = PTR_shieldCamera_80390ad8;
  ::dCamera_c::engine_tbl[17].this_delta = _4308;
  ::dCamera_c::engine_tbl[17].vtbl_offset = DAT_80390ae0;
  ::dCamera_c::engine_tbl[17].func = PTR_nonOwnerCamera_80390ae4;
  ::dCamera_c::engine_tbl[18].this_delta = _4309;
  ::dCamera_c::engine_tbl[18].vtbl_offset = DAT_80390aec;
  ::dCamera_c::engine_tbl[18].func = PTR_followCamera2_80390af0;
  ::dCamera_c::engine_tbl[19].this_delta = _4310;
  ::dCamera_c::engine_tbl[19].vtbl_offset = DAT_80390af8;
  ::dCamera_c::engine_tbl[19].func = PTR_demoCamera_80390afc;
  return;
}

}

/* [thunk]:__thiscall dBgS_CamGndChk::~dBgS_CamGndChk(void) */

void __thiscall dBgS_CamGndChk::_dBgS_CamGndChk(dBgS_CamGndChk *this)

{
  _dBgS_CamGndChk(this + -0x14);
  return;
}


/* [thunk]:__thiscall dBgS_CamGndChk::~dBgS_CamGndChk(void) */

void __thiscall dBgS_CamGndChk::_dBgS_CamGndChk(dBgS_CamGndChk *this)

{
  _dBgS_CamGndChk(this + -0x4c);
  return;
}


/* [thunk]:__thiscall dBgS_CamGndChk::~dBgS_CamGndChk(void) */

void __thiscall dBgS_CamGndChk::_dBgS_CamGndChk(dBgS_CamGndChk *this)

{
  _dBgS_CamGndChk(this + -0x40);
  return;
}


/* [thunk]:__thiscall dBgS_CamLinChk::~dBgS_CamLinChk(void) */

void __thiscall dBgS_CamLinChk::_dBgS_CamLinChk(dBgS_CamLinChk *this)

{
  _dBgS_CamLinChk(this + -0x14);
  return;
}


/* [thunk]:__thiscall dBgS_CamLinChk::~dBgS_CamLinChk(void) */

void __thiscall dBgS_CamLinChk::_dBgS_CamLinChk(dBgS_CamLinChk *this)

{
  _dBgS_CamLinChk(this + -100);
  return;
}


/* [thunk]:__thiscall dBgS_CamLinChk::~dBgS_CamLinChk(void) */

void __thiscall dBgS_CamLinChk::_dBgS_CamLinChk(dBgS_CamLinChk *this)

{
  _dBgS_CamLinChk(this + -0x58);
  return;
}


/* [thunk]:__thiscall dBgS_CamLinChk_NorWtr::~dBgS_CamLinChk_NorWtr(void) */

void __thiscall dBgS_CamLinChk_NorWtr::_dBgS_CamLinChk_NorWtr(dBgS_CamLinChk_NorWtr *this)

{
  _dBgS_CamLinChk_NorWtr(this + -0x14);
  return;
}


/* [thunk]:__thiscall dBgS_CamLinChk_NorWtr::~dBgS_CamLinChk_NorWtr(void) */

void __thiscall dBgS_CamLinChk_NorWtr::_dBgS_CamLinChk_NorWtr(dBgS_CamLinChk_NorWtr *this)

{
  _dBgS_CamLinChk_NorWtr(this + -100);
  return;
}


/* [thunk]:__thiscall dBgS_CamLinChk_NorWtr::~dBgS_CamLinChk_NorWtr(void) */

void __thiscall dBgS_CamLinChk_NorWtr::_dBgS_CamLinChk_NorWtr(dBgS_CamLinChk_NorWtr *this)

{
  _dBgS_CamLinChk_NorWtr(this + -0x58);
  return;
}


/* [thunk]:__thiscall dBgS_CamGndChk_Wtr::~dBgS_CamGndChk_Wtr(void) */

void __thiscall dBgS_CamGndChk_Wtr::_dBgS_CamGndChk_Wtr(dBgS_CamGndChk_Wtr *this)

{
  _dBgS_CamGndChk_Wtr(this + -0x14);
  return;
}


/* [thunk]:__thiscall dBgS_CamGndChk_Wtr::~dBgS_CamGndChk_Wtr(void) */

void __thiscall dBgS_CamGndChk_Wtr::_dBgS_CamGndChk_Wtr(dBgS_CamGndChk_Wtr *this)

{
  _dBgS_CamGndChk_Wtr(this + -0x4c);
  return;
}


/* [thunk]:__thiscall dBgS_CamGndChk_Wtr::~dBgS_CamGndChk_Wtr(void) */

void __thiscall dBgS_CamGndChk_Wtr::_dBgS_CamGndChk_Wtr(dBgS_CamGndChk_Wtr *this)

{
  _dBgS_CamGndChk_Wtr(this + -0x40);
  return;
}


/* [thunk]:__thiscall dBgS_SphChk::~dBgS_SphChk(void) */

void __thiscall dBgS_SphChk::_dBgS_SphChk(dBgS_SphChk *this)

{
  _dBgS_SphChk((dBgS_SphChk *)&this[-1].mDChk.mPolyPassChk.parent.mbObjThrough);
  return;
}


/* [thunk]:__thiscall dBgS_SphChk::~dBgS_SphChk(void) */

void __thiscall dBgS_SphChk::_dBgS_SphChk(dBgS_SphChk *this)

{
  _dBgS_SphChk((dBgS_SphChk *)&this[-1].mChk.mProcID);
  return;
}


/* [thunk]:__thiscall dBgS_SphChk::~dBgS_SphChk(void) */

void __thiscall dBgS_SphChk::_dBgS_SphChk(dBgS_SphChk *this)

{
  _dBgS_SphChk((dBgS_SphChk *)&this[-1].mSph.mRadius);
  return;
}


/* [thunk]:__thiscall dBgS_SphChk::~dBgS_SphChk(void) */

void __thiscall dBgS_SphChk::_dBgS_SphChk(dBgS_SphChk *this)

{
  _dBgS_SphChk((dBgS_SphChk *)&this[-1].mPolyInfo.mpBgW);
  return;
}


/* [thunk]:__thiscall dBgS_CamSphChk::~dBgS_CamSphChk(void) */

void __thiscall dBgS_CamSphChk::_dBgS_CamSphChk(dBgS_CamSphChk *this)

{
  _dBgS_CamSphChk(this + -0x14);
  return;
}


/* [thunk]:__thiscall dBgS_CamSphChk::~dBgS_CamSphChk(void) */

void __thiscall dBgS_CamSphChk::_dBgS_CamSphChk(dBgS_CamSphChk *this)

{
  _dBgS_CamSphChk(this + -0x24);
  return;
}


/* [thunk]:__thiscall dBgS_CamSphChk::~dBgS_CamSphChk(void) */

void __thiscall dBgS_CamSphChk::_dBgS_CamSphChk(dBgS_CamSphChk *this)

{
  _dBgS_CamSphChk(this + -0x44);
  return;
}


/* [thunk]:__thiscall dBgS_CamSphChk::~dBgS_CamSphChk(void) */

void __thiscall dBgS_CamSphChk::_dBgS_CamSphChk(dBgS_CamSphChk *this)

{
  _dBgS_CamSphChk(this + -0x38);
  return;
}

