#include <d_ev_camera.h>
#include <Runtime.PPCEABI.H/__va_arg.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <d_ev_camera.h>
#include <d_event_manager.h>
#include <d_event.h>
#include <f_op_actor_mng.h>
#include <d_camera.h>
#include <SComponent/c_xyz.h>
#include <SComponent/c_angle.h>
#include <mtx/vec.h>
#include <f_pc_searcher.h>
#include <f_op_actor_iter.h>
#include <m_Do_mtx.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <d_spline_path.h>
#include <d_door.h>
#include <d_cam_param.h>
#include <JKernel/JKRHeap.h>
#include <d_cc_s.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <Runtime.PPCEABI.H/ptmf.h>
#include <d_kankyo_wether.h>
#include <d_vibration.h>
#include <SComponent/c_m3d.h>
#include <SComponent/c_math.h>
#include <f_op_camera_mng.h>
#include <m_Do_lib.h>
#include <cXyz.h>
#include <dCamera_c/@class$5621d_ev_camera_cpp.h>
#include <dCamera_c/@class$6314d_ev_camera_cpp.h>
#include <cSGlobe.h>
#include <@unnamed@d_ev_camera_cpp@.h>
#include <dCamera_c.h>
#include <dCamera_c/@class$6993d_ev_camera_cpp.h>


namespace d_ev_camera {
undefined4 DefaultGap$5493;
undefined DefaultGap$7665;
undefined4 DefaultGap$8297;
undefined4 DefaultGap$9374;
undefined4 DefaultGap$11323;
undefined4 DefaultTimer$4539;
undefined1 init$4540;
undefined4 DefaultTimer$4555;
undefined1 init$4556;
float DefaultBank$4558;
undefined1 init$4559;
undefined4 DefaultTimer$4880;
undefined1 init$4881;
float DefaultBank$4883;
undefined1 init$4884;
undefined4 DefaultTimer$5052;
undefined1 init$5053;
float DefaultBank$5055;
undefined1 init$5056;
float DefaultRoll$5058;
undefined1 init$5059;
undefined1 init$5495;
float DefaultRadius$5497;
undefined1 init$5498;
float DefaultCtrCus$5500;
undefined1 init$5501;
undefined4 DefaultTimer$5503;
undefined1 init$5504;
float DefaultBank$5506;
undefined1 init$5507;
undefined4 DefaultTimer$5613;
undefined1 init$5614;
float DefaultBank$5616;
undefined1 init$5617;
undefined4 DefaultTimer$6306;
undefined1 init$6307;
float DefaultBank$6309;
undefined1 init$6310;
undefined4 DefaultTimer$6985;
undefined1 init$6986;
float DefaultBank$6988;
undefined1 init$6989;
undefined1 init$7667;
float DefaultCushion$7669;
undefined1 init$7670;
float DefaultNearDist$7672;
undefined1 init$7673;
float DefaultFarDist$7675;
undefined1 init$7676;
undefined4 DefaultNearTimer$7678;
undefined1 init$7679;
undefined4 DefaultFarTimer$7681;
undefined1 init$7682;
undefined4 DefaultJumpTimer$7684;
undefined1 init$7685;
float DefaultZoomDist$7687;
undefined1 init$7688;
float DefaultZoomVAngle$7690;
undefined1 init$7691;
float DefaultFrontAngle$7693;
undefined1 init$7694;
undefined1 init$8299;
float DefaultCushion$8301;
undefined1 init$8302;
float DefaultNearDist$8304;
undefined1 init$8305;
float DefaultFarDist$8307;
undefined1 init$8308;
undefined4 DefaultNearTimer$8310;
undefined1 init$8311;
undefined4 DefaultFarTimer$8313;
undefined1 init$8314;
float DefaultZoomDist$8316;
undefined1 init$8317;
float DefaultZoomVAngle$8319;
undefined1 init$8320;
undefined1 init$9376;
float DefaultCushion$9378;
undefined1 init$9379;
float DefaultDist$9381;
undefined1 init$9382;
undefined4 DefaultTimer$9384;
undefined1 init$9385;
float DefaultFrontAngle$9387;
undefined1 init$9388;
float DefaultCtrCus$11317;
undefined1 init$11318;
float DefaultEyeCus$11320;
undefined1 init$11321;
undefined1 init$11325;
float DefaultFovy$11327;
undefined1 init$11328;
float DefaultRadiusMin$11330;
undefined1 init$11331;
float DefaultRadiusMax$11333;
undefined1 init$11334;
float DefaultLatitudeMin$11336;
undefined1 init$11337;
float DefaultLatitudeMax$11339;
undefined1 init$11340;
float DefaultLongitudeMin$11342;
undefined1 init$11343;
float DefaultLongitudeMax$11345;
undefined1 init$11346;
float IllegalRatio$11348;
undefined1 init$11349;
}

/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dCamera_c::StartEventCamera(int,
                                          int,
                                          ...) */

undefined4 __thiscall
dCamera_c::StartEventCamera(dCamera_c *this,int param_1,int param_2,___ param_3)

{
  undefined4 uVar1;
  char **ppcVar2;
  int *piVar3;
  int iVar4;
  dCamera_c *pEvt;
  int iVar5;
  dCamera_c *local_88;
  int local_84;
  int local_80;
  ___ local_7c;
  undefined4 local_28;
  undefined *local_24;
  dCamera_c **local_20;
  
  if ((this->mEventFlags & 0x20000000) == 0) {
    this->field_0x40c = param_2;
    this->field_0x410 = param_1;
    local_28 = 0x3000000;
    local_24 = &stack0x00000008;
    local_20 = &local_88;
    iVar4 = 0;
    iVar5 = 0;
    local_88 = this;
    local_84 = param_1;
    local_80 = param_2;
    local_7c = param_3;
    do {
      ppcVar2 = (char **)Runtime.PPCEABI.H::__va_arg(&local_28,1);
      if (*ppcVar2 == (char *)0x0) {
        this->mEventParams[iVar4].mName[0] = '\0';
        break;
      }
      pEvt = (dCamera_c *)((int)&this->mpCamera + iVar5);
      MSL_C.PPCEABI.bare.H::strcpy(pEvt->mEventParams[0].mName,*ppcVar2);
      piVar3 = (int *)Runtime.PPCEABI.H::__va_arg(&local_28,1);
      pEvt->mEventParams[0].mValue = *piVar3;
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0x14;
    } while (iVar4 < 8);
    this->mEventFlags = this->mEventFlags | 0x20000000;
    this->field_0x11c = 0;
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


/* __thiscall dCamera_c::EndEventCamera(int) */

undefined4 __thiscall dCamera_c::EndEventCamera(dCamera_c *this,int param_1)

{
  if ((this->mEventFlags & 0x20000000) == 0) {
    return 0;
  }
  if ((this->field_0xe8 != -1) && (param_1 != this->field_0x40c)) {
    return 0;
  }
  this->mEventFlags = this->mEventFlags & 0xdfffffff;
  return 1;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dCamera_c::searchEventArgData(char *) */

int __thiscall dCamera_c::searchEventArgData(dCamera_c *this,char *param_1)

{
  bool bVar1;
  dCamera_c *pEventCamera;
  int iVar2;
  int iVar3;
  int iVar4;
  
  bVar1 = false;
  iVar3 = 0;
  iVar4 = 0;
  do {
    pEventCamera = (dCamera_c *)((int)&this->mpCamera + iVar4);
    if (pEventCamera->mEventParams[0].mName[0] == '\0') break;
    iVar2 = MSL_C.PPCEABI.bare.H::strcmp(pEventCamera->mEventParams[0].mName,param_1);
    if (iVar2 == 0) {
      bVar1 = true;
      break;
    }
    iVar3 = iVar3 + 1;
    iVar4 = iVar4 + 0x14;
  } while (iVar3 < 8);
  iVar4 = -1;
  if (bVar1) {
    iVar4 = iVar3;
  }
  return iVar4;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dCamera_c::getEvIntData(int *,
                                      char *) */

undefined4 __thiscall dCamera_c::getEvIntData(dCamera_c *this,int *param_1,char *param_2)

{
  int iVar1;
  int *piVar2;
  
  if ((this->mEventFlags & 0x20000000) == 0) {
    iVar1 = dEvent_manager_c::getMySubstanceNum
                      (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mStaffIdx,param_2);
    if (iVar1 == 0) {
      this->field_0x408 = 1;
      return 0;
    }
    piVar2 = (int *)dEvent_manager_c::getMySubstanceP
                              (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mStaffIdx,
                               param_2,Int);
    *param_1 = *piVar2;
  }
  else {
    iVar1 = searchEventArgData(this,param_2);
    if (iVar1 == -1) {
      return 0;
    }
    *param_1 = *(int *)this->mEventParams[iVar1].mValue;
  }
  return 1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dCamera_c::getEvStringPntData(char *) */

void * __thiscall dCamera_c::getEvStringPntData(dCamera_c *this,char *param_1)

{
  int iVar1;
  void *pvVar2;
  
  if ((this->mEventFlags & 0x20000000) == 0) {
    iVar1 = dEvent_manager_c::getMySubstanceNum
                      (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mStaffIdx,param_1);
    if (iVar1 == 0) {
      this->field_0x408 = 1;
      pvVar2 = (void *)0x0;
    }
    else {
      pvVar2 = dEvent_manager_c::getMySubstanceP
                         (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mStaffIdx,
                          param_1,String);
    }
  }
  else {
    iVar1 = searchEventArgData(this,param_1);
    if (iVar1 == -1) {
      pvVar2 = (void *)0x0;
    }
    else {
      pvVar2 = (void *)this->mEventParams[iVar1].mValue;
    }
  }
  return pvVar2;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dCamera_c::getEvIntData(int *,
                                      char *,
                                      int) */

undefined4 __thiscall
dCamera_c::getEvIntData(dCamera_c *this,int *param_1,char *param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  
  if ((this->mEventFlags & 0x20000000) == 0) {
    iVar1 = dEvent_manager_c::getMySubstanceNum
                      (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mStaffIdx,param_2);
    if (iVar1 == 0) {
      *param_1 = param_3;
      return 0;
    }
    piVar2 = (int *)dEvent_manager_c::getMySubstanceP
                              (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mStaffIdx,
                               param_2,Int);
    *param_1 = *piVar2;
  }
  else {
    iVar1 = searchEventArgData(this,param_2);
    if (iVar1 == -1) {
      *param_1 = param_3;
    }
    else {
      *param_1 = *(int *)this->mEventParams[iVar1].mValue;
    }
  }
  return 1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x800b053c) */
/* __thiscall dCamera_c::getEvFloatData(float *,
                                        char *,
                                        float) */

undefined4 __thiscall
dCamera_c::getEvFloatData(dCamera_c *this,float *param_1,char *param_2,float param_3)

{
  int iVar1;
  float *pfVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  double dVar5;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  dVar5 = (double)param_3;
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if ((this->mEventFlags & 0x20000000) == 0) {
    iVar1 = dEvent_manager_c::getMySubstanceNum
                      (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mStaffIdx,param_2);
    if (iVar1 == 0) {
      *param_1 = (float)dVar5;
      uVar3 = 0;
      goto LAB_800b053c;
    }
    pfVar2 = (float *)dEvent_manager_c::getMySubstanceP
                                (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mStaffIdx
                                 ,param_2,Float);
    *param_1 = *pfVar2;
  }
  else {
    iVar1 = searchEventArgData(this,param_2);
    if (iVar1 == -1) {
      *param_1 = (float)dVar5;
    }
    else {
      *param_1 = *(float *)this->mEventParams[iVar1].mValue;
    }
  }
  uVar3 = 1;
LAB_800b053c:
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return uVar3;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dCamera_c::getEvXyzData(cXyz *,
                                      char *,
                                      cXyz) */

undefined4 __thiscall
dCamera_c::getEvXyzData(dCamera_c *this,cXyz *param_1,char *param_2,cXyz *param_3)

{
  int iVar1;
  float *pfVar2;
  
  if ((this->mEventFlags & 0x20000000) == 0) {
    iVar1 = dEvent_manager_c::getMySubstanceNum
                      (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mStaffIdx,param_2);
    if (iVar1 == 0) {
      param_1->x = param_3->x;
      param_1->y = param_3->y;
      param_1->z = param_3->z;
      return 0;
    }
    pfVar2 = (float *)dEvent_manager_c::getMySubstanceP
                                (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mStaffIdx
                                 ,param_2,Xyz);
    param_1->x = *pfVar2;
    param_1->y = pfVar2[1];
    param_1->z = pfVar2[2];
  }
  else {
    iVar1 = searchEventArgData(this,param_2);
    if (iVar1 == -1) {
      param_1->x = param_3->x;
      param_1->y = param_3->y;
      param_1->z = param_3->z;
    }
    else {
      pfVar2 = (float *)this->mEventParams[iVar1].mValue;
      param_1->x = *pfVar2;
      param_1->y = pfVar2[1];
      param_1->z = pfVar2[2];
    }
  }
  return 1;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dCamera_c::getEvStringData(char *,
                                         char *,
                                         char *) */

undefined4 __thiscall
dCamera_c::getEvStringData(dCamera_c *this,char *param_1,char *param_2,char *param_3)

{
  int iVar1;
  char *__src;
  
  if ((this->mEventFlags & 0x20000000) == 0) {
    iVar1 = dEvent_manager_c::getMySubstanceNum
                      (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mStaffIdx,param_2);
    if (iVar1 == 0) {
      MSL_C.PPCEABI.bare.H::strcpy(param_1,param_3);
      return 0;
    }
    __src = (char *)dEvent_manager_c::getMySubstanceP
                              (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mStaffIdx,
                               param_2,String);
    MSL_C.PPCEABI.bare.H::strcpy(param_1,__src);
  }
  else {
    iVar1 = searchEventArgData(this,param_2);
    if (iVar1 == -1) {
      MSL_C.PPCEABI.bare.H::strcpy(param_1,param_3);
    }
    else {
      MSL_C.PPCEABI.bare.H::strcpy(param_1,(char *)this->mEventParams[iVar1].mValue);
    }
  }
  return 1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dCamera_c::getEvStringPntData(char *,
                                            char *) */

char * __thiscall dCamera_c::getEvStringPntData(dCamera_c *this,char *param_1,char *param_2)

{
  int iVar1;
  
  if ((this->mEventFlags & 0x20000000) == 0) {
    iVar1 = dEvent_manager_c::getMySubstanceNum
                      (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mStaffIdx,param_1);
    if (iVar1 != 0) {
      param_2 = (char *)dEvent_manager_c::getMySubstanceP
                                  (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,
                                   this->mStaffIdx,param_1,String);
    }
  }
  else {
    iVar1 = searchEventArgData(this,param_1);
    if (iVar1 != -1) {
      param_2 = (char *)this->mEventParams[iVar1].mValue;
    }
  }
  return param_2;
}


/* __thiscall dCamera_c::getEvActor(char *) */

fopAc_ac_c * __thiscall dCamera_c::getEvActor(dCamera_c *this,char *param_1)

{
  int *actorName;
  daPy_lk_c *pdVar1;
  int iVar2;
  
  actorName = (int *)getEvStringPntData(this,param_1);
  if (actorName == (int *)0x0) {
    pdVar1 = (daPy_lk_c *)0x0;
  }
  else {
    iVar2 = *actorName;
    if (iVar2 == 0x40504c41) {
      pdVar1 = (daPy_lk_c *)this->mpPlayerActor;
    }
    else {
      if (iVar2 == 0x40535441) {
        pdVar1 = (daPy_lk_c *)
                 dEvt_control_c::convPId
                           (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl,
                            d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mPt1);
      }
      else {
        if (iVar2 == 0x40504152) {
          pdVar1 = (daPy_lk_c *)
                   dEvt_control_c::convPId
                             (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl,
                              d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mPt2);
        }
        else {
          if (iVar2 == 0x4054414c) {
            pdVar1 = (daPy_lk_c *)
                     dEvt_control_c::convPId
                               (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl,
                                d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mPtTalk);
          }
          else {
            if ((iVar2 == 0x40544152) || (iVar2 == 0x40495445)) {
              pdVar1 = (daPy_lk_c *)
                       dEvt_control_c::convPId
                                 (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl,
                                  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mPtItem);
            }
            else {
              pdVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor;
              if (iVar2 != 0x4c696e6b) {
                pdVar1 = (daPy_lk_c *)f_op_actor_mng::fopAcM_searchFromName((char *)actorName,0,0);
              }
            }
          }
        }
      }
    }
  }
  return (fopAc_ac_c *)pdVar1;
}


/* __thiscall dCamera_c::getEvActor(char *,
                                    char *) */

daPy_lk_c * __thiscall dCamera_c::getEvActor(dCamera_c *this,char *param_1,char *param_2)

{
  daPy_lk_c *pdVar1;
  undefined4 local_18;
  
  local_18 = (uint)local_18._1_3_;
  getEvStringData(this,(char *)&local_18,param_1,param_2);
  if (local_18 == 0x40504c41) {
    pdVar1 = (daPy_lk_c *)this->mpPlayerActor;
  }
  else {
    if (local_18 == 0x40535441) {
      pdVar1 = (daPy_lk_c *)
               dEvt_control_c::convPId
                         (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl,
                          d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mPt1);
    }
    else {
      if (local_18 == 0x40504152) {
        pdVar1 = (daPy_lk_c *)
                 dEvt_control_c::convPId
                           (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl,
                            d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mPt2);
      }
      else {
        if (local_18 == 0x4054414c) {
          pdVar1 = (daPy_lk_c *)
                   dEvt_control_c::convPId
                             (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl,
                              d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mPtTalk);
        }
        else {
          if ((local_18 == 0x40544152) || (local_18 == 0x40495445)) {
            pdVar1 = (daPy_lk_c *)
                     dEvt_control_c::convPId
                               (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl,
                                d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mPtItem);
          }
          else {
            pdVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpLinkActor;
            if (local_18 != 0x4c696e6b) {
              pdVar1 = (daPy_lk_c *)f_op_actor_mng::fopAcM_searchFromName((char *)&local_18,0,0);
            }
          }
        }
      }
    }
  }
  return pdVar1;
}


/* __thiscall dCamera_c::pauseEvCamera(void) */

undefined4 __thiscall dCamera_c::pauseEvCamera(dCamera_c *this)

{
  undefined uVar2;
  undefined4 uVar1;
  
  if (d_ev_camera::init_4540 == '\0') {
    d_ev_camera::DefaultTimer_4539 = -1;
    d_ev_camera::init_4540 = '\x01';
  }
  if (this->field_0x11c == 0) {
    *(undefined *)&this->field_0x102 = 1;
    *(undefined *)&this->field_0x101 = 1;
    *(undefined *)&this->field_0x100 = 1;
    uVar2 = getEvIntData(this,(int *)&this->field_0x380,"Timer",d_ev_camera::DefaultTimer_4539);
    *(undefined *)&this->field_0x378 = uVar2;
    getEvIntData(this,(int *)&this->field_0x37c,"Stay",0);
  }
  if (*(int *)&this->field_0x37c != 0) {
    this->mEventFlags = this->mEventFlags | 1;
  }
  if ((*(char *)&this->field_0x378 == '\0') ||
     (*(uint *)&this->field_0x380 <= (uint)this->field_0x11c)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


/* WARNING: Removing unreachable block (ram,0x800b14b8) */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall dCamera_c::fixedFrameEvCamera(void) */

undefined4 __thiscall dCamera_c::fixedFrameEvCamera(dCamera_c *this)

{
  int iVar1;
  byte bVar4;
  undefined uVar5;
  fopAc_ac_c *pfVar2;
  char cVar6;
  undefined4 uVar3;
  undefined4 uVar7;
  double dVar8;
  double dVar9;
  undefined8 in_f31;
  double dVar10;
  float fVar11;
  cSAngle local_248 [2];
  cSAngle acStack580 [4];
  cSAngle acStack572 [4];
  cSAngle local_234 [2];
  cSAngle local_230 [2];
  float local_22c;
  float local_228;
  float local_224;
  float local_220;
  cSGlobe cStack540;
  cSGlobe cStack532;
  cXyz cStack524;
  cXyz local_200;
  cXyz cStack500;
  cXyz local_1e8;
  cXyz local_1dc;
  cXyz local_1d0;
  cXyz cStack452;
  cXyz local_1b8;
  cXyz local_1ac;
  cXyz local_1a0;
  cXyz cStack404;
  cXyz local_188;
  cXyz local_17c;
  cXyz cStack368;
  cXyz cStack356;
  cXyz local_158;
  cXyz local_14c;
  cXyz local_140;
  cXyz local_134;
  cXyz cStack296;
  cXyz local_11c;
  cXyz local_110;
  cXyz local_104;
  cXyz cStack248;
  cXyz local_ec;
  cXyz local_e0;
  cXyz local_d4;
  cXyz cStack200;
  cXyz local_bc;
  cXyz local_b0;
  cXyz cStack164;
  cXyz cStack152;
  cXyz local_8c;
  cXyz local_80;
  cXyz local_74;
  cXyz local_68;
  cXyz local_5c;
  cXyz local_50;
  cXyz local_44;
  cXyz local_38;
  longlong local_28;
  undefined auStack8 [8];
  
  uVar7 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (d_ev_camera::init_4556 == '\0') {
    d_ev_camera::DefaultTimer_4555 = -1;
    d_ev_camera::init_4556 = '\x01';
  }
  if (d_ev_camera::init_4559 == '\0') {
    d_ev_camera::DefaultBank_4558 = d_ev_camera::_4862;
    d_ev_camera::init_4559 = '\x01';
  }
  if (this->field_0x11c == 0) {
    local_68.x = (this->mEye).x;
    local_68.y = (this->mEye).y;
    local_68.z = (this->mEye).z;
    getEvXyzData(this,&local_44,"Eye",&local_68);
    local_74.x = (this->mCenter).x;
    local_74.y = (this->mCenter).y;
    local_74.z = (this->mCenter).z;
    getEvXyzData(this,&local_38,"Center",&local_74);
    local_80.x = ::cXyz::Zero.x;
    local_80.y = ::cXyz::Zero.y;
    local_80.z = ::cXyz::Zero.z;
    getEvXyzData(this,&this->mEvBasePos,"BasePos",&local_80);
    getEvFloatData(this,&this->mEvFovy,"Fovy",this->mFovY);
    bVar4 = getEvFloatData(this,&this->mEvBank,"Bank",d_ev_camera::DefaultBank_4558);
    this->field_0x3a8 = bVar4;
    uVar5 = getEvIntData(this,&this->mEvTimer,"Timer",d_ev_camera::DefaultTimer_4555);
    *(undefined *)&this->field_0x378 = uVar5;
    getEvStringData(this,this->mEvRelUseMask,"RelUseMask","oo");
    pfVar2 = getEvActor(this,"RelActor");
    this->mpEvRelActor = pfVar2;
    pfVar2 = this->mpEvRelActor;
    if ((pfVar2 == (fopAc_ac_c *)0x0) || (this->mEvRelUseMask[0] != 'o')) {
      cVar6 = this->mEvRelUseMask[0];
      if (cVar6 == 'n') {
        positionOf(&cStack152,this,pfVar2);
        ::cXyz::operator__(&cStack164,&this->mEye,&cStack152);
        cSGlobe::cSGlobe(&cStack532,&cStack164);
        directionOf((dCamera_c *)(acStack572 + 2),(fopAc_ac_c *)this);
        cSAngle::operator__(acStack572,&cStack532.mAngleY);
        cSAngle::cSAngle(local_230,acStack572);
        if (local_230[0] < cSAngle::_0) {
          local_38.x = -local_38.x;
        }
        relationalPos(&local_b0,this,this->mpEvRelActor,&local_38);
        *(float *)&this->field_0x388 = local_b0.x;
        *(float *)&this->field_0x38c = local_b0.y;
        *(float *)&this->field_0x390 = local_b0.z;
      }
      else {
        if (cVar6 == 'p') {
          relationalPos(&local_bc,this,pfVar2,&local_38);
          local_50.x = local_bc.x;
          local_50.y = local_bc.y;
          local_50.z = local_bc.z;
          positionOf(&cStack200,this,this->mpPlayerActor);
          ::cXyz::operator__(&local_d4,&local_50,&cStack200);
          local_e0.x = local_d4.x;
          local_e0.y = local_d4.y;
          local_e0.z = local_d4.z;
          fVar11 = mtx::PSVECSquareMag(&local_e0);
          dVar10 = (double)fVar11;
          if ((double)d_ev_camera::_4862 < dVar10) {
            dVar8 = 1.0 / SQRT(dVar10);
            dVar8 = d_ev_camera::_4863 * dVar8 * (d_ev_camera::_4864 - dVar10 * dVar8 * dVar8);
            dVar8 = d_ev_camera::_4863 * dVar8 * (d_ev_camera::_4864 - dVar10 * dVar8 * dVar8);
            local_220 = (float)(dVar10 * d_ev_camera::_4863 * dVar8 *
                                         (d_ev_camera::_4864 - dVar10 * dVar8 * dVar8));
            dVar10 = (double)local_220;
          }
          local_38.x = -local_38.x;
          relationalPos(&local_ec,this,this->mpEvRelActor,&local_38);
          local_50.x = local_ec.x;
          local_50.y = local_ec.y;
          local_50.z = local_ec.z;
          positionOf(&cStack248,this,this->mpPlayerActor);
          ::cXyz::operator__(&local_104,&local_50,&cStack248);
          local_110.x = local_104.x;
          local_110.y = local_104.y;
          local_110.z = local_104.z;
          fVar11 = mtx::PSVECSquareMag(&local_110);
          dVar8 = (double)fVar11;
          if ((double)d_ev_camera::_4862 < dVar8) {
            dVar9 = 1.0 / SQRT(dVar8);
            dVar9 = d_ev_camera::_4863 * dVar9 * (d_ev_camera::_4864 - dVar8 * dVar9 * dVar9);
            dVar9 = d_ev_camera::_4863 * dVar9 * (d_ev_camera::_4864 - dVar8 * dVar9 * dVar9);
            local_224 = (float)(dVar8 * d_ev_camera::_4863 * dVar9 *
                                        (d_ev_camera::_4864 - dVar8 * dVar9 * dVar9));
            dVar8 = (double)local_224;
          }
          if (dVar8 < dVar10) {
            local_38.x = -local_38.x;
          }
          relationalPos(&local_11c,this,this->mpEvRelActor,&local_38);
          *(float *)&this->field_0x388 = local_11c.x;
          *(float *)&this->field_0x38c = local_11c.y;
          *(float *)&this->field_0x390 = local_11c.z;
        }
        else {
          if (cVar6 == 't') {
            attentionPos(&cStack296,this,pfVar2);
            ::cXyz::operator__(&local_134,&cStack296,&local_38);
            *(float *)&this->field_0x388 = local_134.x;
            *(float *)&this->field_0x38c = local_134.y;
            *(float *)&this->field_0x390 = local_134.z;
          }
          else {
            *(float *)&this->field_0x388 = local_38.x;
            *(float *)&this->field_0x38c = local_38.y;
            *(float *)&this->field_0x390 = local_38.z;
          }
        }
      }
    }
    else {
      relationalPos(&local_8c,this,pfVar2,&local_38);
      *(float *)&this->field_0x388 = local_8c.x;
      *(float *)&this->field_0x38c = local_8c.y;
      *(float *)&this->field_0x390 = local_8c.z;
    }
    pfVar2 = this->mpEvRelActor;
    if ((pfVar2 == (fopAc_ac_c *)0x0) || (this->mEvRelUseMask[1] != 'o')) {
      if ((pfVar2 == (fopAc_ac_c *)0x0) || (this->mEvRelUseMask[1] != 'r')) {
        cVar6 = this->mEvRelUseMask[1];
        if (cVar6 == 'n') {
          positionOf(&cStack356,this,pfVar2);
          ::cXyz::operator__(&cStack368,&this->mEye,&cStack356);
          cSGlobe::cSGlobe(&cStack540,&cStack368);
          directionOf((dCamera_c *)(acStack580 + 2),(fopAc_ac_c *)this);
          cSAngle::operator__(acStack580,&cStack540.mAngleY);
          cSAngle::cSAngle(local_234,acStack580);
          if (local_234[0] < cSAngle::_0) {
            local_44.x = -local_44.x;
          }
          relationalPos(&local_17c,this,this->mpEvRelActor,&local_44);
          *(float *)&this->field_0x37c = local_17c.x;
          *(float *)&this->field_0x380 = local_17c.y;
          *(float *)&this->field_0x384 = local_17c.z;
          cVar6 = lineBGCheck(this,(cXyz *)&this->field_0x388,(cXyz *)&this->field_0x37c,0x8f);
          if (cVar6 != '\0') {
            local_44.x = -local_44.x;
          }
        }
        else {
          if (cVar6 == 'p') {
            relationalPos(&local_188,this,pfVar2,&local_44);
            local_5c.x = local_188.x;
            local_5c.y = local_188.y;
            local_5c.z = local_188.z;
            positionOf(&cStack404,this,this->mpPlayerActor);
            ::cXyz::operator__(&local_1a0,&local_5c,&cStack404);
            local_1ac.x = local_1a0.x;
            local_1ac.y = local_1a0.y;
            local_1ac.z = local_1a0.z;
            fVar11 = mtx::PSVECSquareMag(&local_1ac);
            dVar10 = (double)fVar11;
            if ((double)d_ev_camera::_4862 < dVar10) {
              dVar8 = 1.0 / SQRT(dVar10);
              dVar8 = d_ev_camera::_4863 * dVar8 * (d_ev_camera::_4864 - dVar10 * dVar8 * dVar8);
              dVar8 = d_ev_camera::_4863 * dVar8 * (d_ev_camera::_4864 - dVar10 * dVar8 * dVar8);
              local_228 = (float)(dVar10 * d_ev_camera::_4863 * dVar8 *
                                           (d_ev_camera::_4864 - dVar10 * dVar8 * dVar8));
              dVar10 = (double)local_228;
            }
            local_44.x = -local_44.x;
            relationalPos(&local_1b8,this,this->mpEvRelActor,&local_44);
            local_5c.x = local_1b8.x;
            local_5c.y = local_1b8.y;
            local_5c.z = local_1b8.z;
            positionOf(&cStack452,this,this->mpPlayerActor);
            ::cXyz::operator__(&local_1d0,&local_5c,&cStack452);
            local_1dc.x = local_1d0.x;
            local_1dc.y = local_1d0.y;
            local_1dc.z = local_1d0.z;
            fVar11 = mtx::PSVECSquareMag(&local_1dc);
            dVar8 = (double)fVar11;
            if ((double)d_ev_camera::_4862 < dVar8) {
              dVar9 = 1.0 / SQRT(dVar8);
              dVar9 = d_ev_camera::_4863 * dVar9 * (d_ev_camera::_4864 - dVar8 * dVar9 * dVar9);
              dVar9 = d_ev_camera::_4863 * dVar9 * (d_ev_camera::_4864 - dVar8 * dVar9 * dVar9);
              local_22c = (float)(dVar8 * d_ev_camera::_4863 * dVar9 *
                                          (d_ev_camera::_4864 - dVar8 * dVar9 * dVar9));
              dVar8 = (double)local_22c;
            }
            if (dVar8 < dVar10) {
              local_44.x = -local_44.x;
            }
            relationalPos(&local_1e8,this,this->mpEvRelActor,&local_44);
            *(float *)&this->field_0x37c = local_1e8.x;
            *(float *)&this->field_0x380 = local_1e8.y;
            *(float *)&this->field_0x384 = local_1e8.z;
          }
          else {
            if (cVar6 == 't') {
              attentionPos(&cStack500,this,pfVar2);
              ::cXyz::operator__(&local_200,&cStack500,&local_44);
              *(float *)&this->field_0x37c = local_200.x;
              *(float *)&this->field_0x380 = local_200.y;
              *(float *)&this->field_0x384 = local_200.z;
            }
            else {
              *(float *)&this->field_0x37c = local_44.x;
              *(float *)&this->field_0x380 = local_44.y;
              *(float *)&this->field_0x384 = local_44.z;
            }
          }
        }
      }
      else {
        if ((this->field_0x80 & 1) != 0) {
          local_44.x = -local_44.x;
        }
        relationalPos(&local_14c,this,this->mpEvRelActor,&local_44);
        *(float *)&this->field_0x37c = local_14c.x;
        *(float *)&this->field_0x380 = local_14c.y;
        *(float *)&this->field_0x384 = local_14c.z;
        cVar6 = lineBGCheck(this,(cXyz *)&this->field_0x388,(cXyz *)&this->field_0x37c,0x8f);
        if (cVar6 != '\0') {
          local_44.x = -local_44.x;
        }
        relationalPos(&local_158,this,this->mpEvRelActor,&local_44);
        *(float *)&this->field_0x37c = local_158.x;
        *(float *)&this->field_0x380 = local_158.y;
        *(float *)&this->field_0x384 = local_158.z;
      }
    }
    else {
      relationalPos(&local_140,this,pfVar2,&local_44);
      *(float *)&this->field_0x37c = local_140.x;
      *(float *)&this->field_0x380 = local_140.y;
      *(float *)&this->field_0x384 = local_140.z;
    }
    *(undefined *)&this->field_0x102 = 1;
    *(undefined *)&this->field_0x101 = 1;
    *(undefined *)&this->field_0x100 = 1;
  }
  (this->field_0x44).x = *(float *)&this->field_0x388;
  (this->field_0x44).y = *(float *)&this->field_0x38c;
  (this->field_0x44).z = *(float *)&this->field_0x390;
  (this->field_0x50).x = *(float *)&this->field_0x37c;
  (this->field_0x50).y = *(float *)&this->field_0x380;
  (this->field_0x50).z = *(float *)&this->field_0x384;
  ::cXyz::operator__(&cStack524,&this->field_0x50,&this->field_0x44);
  cSGlobe::Val(&this->field_0x3c,&cStack524);
  this->field_0x60 = this->mEvFovy;
  if (this->field_0x3a8 != 0) {
    iVar1 = (int)(d_ev_camera::_4865 * this->mEvBank);
    local_28 = (longlong)iVar1;
    cSAngle::cSAngle(local_248,(short)iVar1);
    ((cSAngle *)&this->field_0x5c)->v = local_248[0];
    this->mEventFlags = this->mEventFlags | 0x400;
  }
  if ((*(char *)&this->field_0x378 == '\0') || ((uint)this->mEvTimer <= (uint)this->field_0x11c)) {
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  return uVar3;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall dCamera_c::stokerEvCamera(void) */

undefined4 __thiscall dCamera_c::stokerEvCamera(dCamera_c *this)

{
  int iVar1;
  short sVar2;
  uint uVar3;
  undefined uVar6;
  fopAc_ac_c *pfVar4;
  undefined4 uVar5;
  cSAngle local_b8 [2];
  cSAngle local_b4 [2];
  cSAngle local_b0 [2];
  cSAngle local_ac [2];
  cSAngle local_a8 [2];
  cSAngle local_a4 [2];
  cSAngle local_a0 [2];
  cSAngle local_9c [2];
  cSAngle local_98 [2];
  int local_94;
  undefined4 local_90;
  cSGlobe cStack140;
  cXyz cStack132;
  cXyz local_78;
  cXyz cStack108;
  cXyz cStack96;
  cXyz local_54;
  cXyz cStack72;
  cXyz cStack60;
  cXyz local_30;
  cXyz local_24;
  longlong local_18;
  
  sVar2 = (short)register0x00000004;
  if (d_ev_camera::init_4881 == '\0') {
    d_ev_camera::DefaultTimer_4880 = -1;
    d_ev_camera::init_4881 = '\x01';
  }
  if (d_ev_camera::init_4884 == '\0') {
    d_ev_camera::DefaultBank_4883 = d_ev_camera::_4862;
    d_ev_camera::init_4884 = '\x01';
  }
  if (this->field_0x11c == 0) {
    local_24.x = ::cXyz::Zero.x;
    local_24.y = ::cXyz::Zero.y;
    local_24.z = ::cXyz::Zero.z;
    getEvXyzData(this,(cXyz *)&this->field_0x37c,"EyeGap",&local_24);
    local_30.x = ::cXyz::Zero.x;
    local_30.y = ::cXyz::Zero.y;
    local_30.z = ::cXyz::Zero.z;
    getEvXyzData(this,(cXyz *)&this->field_0x388,"CtrGap",&local_30);
    getEvFloatData(this,&this->mEvFovy,"Fovy",this->mFovY);
    uVar6 = getEvFloatData(this,&this->mEvBank,"Bank",d_ev_camera::DefaultBank_4883);
    *(undefined *)&this->field_0x379 = uVar6;
    uVar6 = getEvIntData(this,(int *)&(this->mEvBasePos).y,"Timer",d_ev_camera::DefaultTimer_4880);
    *(undefined *)&this->field_0x378 = uVar6;
    pfVar4 = (fopAc_ac_c *)getEvActor(this,"Stoker","@STARTER");
    this->mpEvRelActor = pfVar4;
    uVar5 = getEvActor(this,"Target","@PLAYER");
    *(undefined4 *)this->mEvRelUseMask = uVar5;
    pfVar4 = this->mpEvRelActor;
    if ((pfVar4 == (fopAc_ac_c *)0x0) || (*(int *)this->mEvRelUseMask == 0)) {
      return 1;
    }
    if (pfVar4 == (fopAc_ac_c *)0x0) {
      uVar3 = 0xffffffff;
    }
    else {
      uVar3 = (pfVar4->parent).parent.mBsPcId;
    }
    this->mEvTimer = uVar3;
    if (*(int *)this->mEvRelUseMask == 0) {
      uVar5 = 0xffffffff;
    }
    else {
      uVar5 = *(undefined4 *)(*(int *)this->mEvRelUseMask + 4);
    }
    *(undefined4 *)&this->field_0x3a8 = uVar5;
    *(undefined *)&this->field_0x102 = 1;
    *(undefined *)&this->field_0x101 = 1;
    *(undefined *)&this->field_0x100 = 1;
  }
  if (*(int *)this->mEvRelUseMask != 0) {
    local_90 = *(undefined4 *)&this->field_0x3a8;
    pfVar4 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,&local_90);
    if (pfVar4 == (fopAc_ac_c *)0x0) {
      return 1;
    }
    cSGlobe::Val(&cStack140,(cXyz *)&this->field_0x388);
    cSAngle::operator__(local_98,sVar2 + -0x88);
    cSAngle::cSAngle(local_ac,local_98[0]);
    cStack140.mAngleX = local_ac[0];
    cSAngle::operator__(local_9c,sVar2 + -0x86);
    cSAngle::cSAngle(local_b0,local_9c[0]);
    cStack140.mAngleY = local_b0[0];
    attentionPos(&cStack60,this,*(fopAc_ac_c **)this->mEvRelUseMask);
    cSGlobe::Xyz(&cStack72,&cStack140);
    ::cXyz::operator__(&local_54,&cStack60,&cStack72);
    (this->field_0x44).x = local_54.x;
    (this->field_0x44).y = local_54.y;
    (this->field_0x44).z = local_54.z;
  }
  if (this->mpEvRelActor != (fopAc_ac_c *)0x0) {
    local_94 = this->mEvTimer;
    pfVar4 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,&local_94);
    if (pfVar4 == (fopAc_ac_c *)0x0) {
      return 1;
    }
    cSGlobe::Val(&cStack140,(cXyz *)&this->field_0x37c);
    cSAngle::operator__(local_a0,sVar2 + -0x88);
    cSAngle::cSAngle(local_b4,local_a0[0]);
    cStack140.mAngleX = local_b4[0];
    cSAngle::operator__(local_a4,sVar2 + -0x86);
    cSAngle::cSAngle(local_b8,local_a4[0]);
    cStack140.mAngleY = local_b8[0];
    attentionPos(&cStack96,this,this->mpEvRelActor);
    cSGlobe::Xyz(&cStack108,&cStack140);
    ::cXyz::operator__(&local_78,&cStack96,&cStack108);
    (this->field_0x50).x = local_78.x;
    (this->field_0x50).y = local_78.y;
    (this->field_0x50).z = local_78.z;
  }
  ::cXyz::operator__(&cStack132,&this->field_0x50,&this->field_0x44);
  cSGlobe::Val(&this->field_0x3c,&cStack132);
  this->field_0x60 = this->mEvFovy;
  if (*(char *)&this->field_0x379 != '\0') {
    iVar1 = (int)(d_ev_camera::_4865 * this->mEvBank);
    local_18 = (longlong)iVar1;
    cSAngle::cSAngle(local_a8,(short)iVar1);
    ((cSAngle *)&this->field_0x5c)->v = local_a8[0];
    this->mEventFlags = this->mEventFlags | 0x400;
  }
  if ((*(char *)&this->field_0x378 == '\0') ||
     ((uint)(this->mEvBasePos).y <= (uint)this->field_0x11c)) {
    uVar5 = 1;
  }
  else {
    uVar5 = 0;
  }
  return uVar5;
}


/* WARNING: Removing unreachable block (ram,0x800b2664) */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall dCamera_c::rollingEvCamera(void) */

undefined4 __thiscall dCamera_c::rollingEvCamera(dCamera_c *this)

{
  int iVar1;
  undefined uVar4;
  fopAc_ac_c *pfVar2;
  char cVar5;
  undefined4 uVar3;
  undefined4 uVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  undefined8 in_f31;
  float fVar10;
  cSAngle local_318 [2];
  cSAngle local_314 [2];
  cSAngle local_310 [2];
  cSAngle local_30c [2];
  cSAngle acStack776 [2];
  cSAngle local_304 [2];
  cSAngle acStack768 [4];
  cSAngle acStack760 [4];
  cSAngle acStack752 [4];
  cSAngle local_2e8 [2];
  cSAngle local_2e4 [2];
  cSAngle local_2e0 [2];
  float local_2dc;
  float local_2d8;
  float local_2d4;
  float local_2d0;
  float local_2cc;
  float local_2c8;
  cSGlobe cStack708;
  cSGlobe cStack700;
  cSGlobe cStack692;
  cSGlobe cStack684;
  cXyz local_2a4;
  cXyz cStack664;
  cXyz cStack652;
  cXyz cStack640;
  cXyz cStack628;
  cXyz local_268;
  cXyz local_25c;
  cXyz local_250;
  cXyz cStack580;
  cXyz local_238;
  cXyz local_22c;
  cXyz local_220;
  cXyz cStack532;
  cXyz local_208;
  cXyz local_1fc;
  cXyz cStack496;
  cXyz cStack484;
  cXyz local_1d8;
  cXyz local_1cc;
  cXyz local_1c0;
  cXyz local_1b4;
  cXyz cStack424;
  cXyz local_19c;
  cXyz local_190;
  cXyz local_184;
  cXyz cStack376;
  cXyz local_16c;
  cXyz local_160;
  cXyz cStack340;
  cXyz cStack328;
  cXyz local_13c;
  cXyz local_130;
  cXyz local_124;
  cXyz local_118;
  cXyz local_10c;
  cXyz local_100;
  cXyz cStack244;
  cXyz local_e8;
  cXyz local_dc;
  cXyz local_d0;
  cXyz cStack196;
  cXyz local_b8;
  cXyz local_ac;
  cXyz cStack160;
  cXyz cStack148;
  cXyz local_88;
  cXyz cStack124;
  cXyz local_70;
  cXyz local_64;
  cXyz local_58;
  cXyz local_4c;
  cXyz local_40;
  undefined4 local_30;
  int iStack44;
  double local_28;
  undefined auStack8 [8];
  
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (d_ev_camera::init_5053 == '\0') {
    d_ev_camera::DefaultTimer_5052 = -1;
    d_ev_camera::init_5053 = '\x01';
  }
  if (d_ev_camera::init_5056 == '\0') {
    d_ev_camera::DefaultBank_5055 = d_ev_camera::_4862;
    d_ev_camera::init_5056 = '\x01';
  }
  if (d_ev_camera::init_5059 == '\0') {
    d_ev_camera::DefaultRoll_5058 = d_ev_camera::_5485;
    d_ev_camera::init_5059 = '\x01';
  }
  if (this->field_0x11c == 0) {
    local_64.x = (this->mEye).x;
    local_64.y = (this->mEye).y;
    local_64.z = (this->mEye).z;
    getEvXyzData(this,(cXyz *)&this->mEvFovy,"Eye",&local_64);
    local_70.x = (this->mCenter).x;
    local_70.y = (this->mCenter).y;
    local_70.z = (this->mCenter).z;
    getEvXyzData(this,(cXyz *)this->mEvRelUseMask,"Center",&local_70);
    getEvFloatData(this,(float *)&this->field_0x3d0,"CtrCus",d_ev_camera::_5486);
    getEvIntData(this,(int *)&this->field_0x3c0,"TransType",0);
    getEvFloatData(this,&(this->mEvBasePos).x,"Fovy",this->mFovY);
    uVar4 = getEvFloatData(this,&(this->mEvBasePos).y,"Bank",d_ev_camera::DefaultBank_5055);
    *(undefined *)&this->field_0x379 = uVar4;
    getEvFloatData(this,(float *)&this->field_0x3c4,"Roll",d_ev_camera::DefaultRoll_5058);
    getEvFloatData(this,(float *)&this->field_0x3c8,"RadiusAdd",d_ev_camera::_4862);
    ::cXyz::operator__(&cStack124,(cXyz *)&this->mEvFovy,(cXyz *)this->mEvRelUseMask);
    cSGlobe::cSGlobe(&cStack684,&cStack124);
    dVar9 = (double)cSAngle::Degree(&cStack684.mAngleX);
    getEvFloatData(this,(float *)&this->field_0x3cc,"Latitude",(float)dVar9);
    uVar4 = getEvIntData(this,(int *)&this->field_0x3bc,"Timer",d_ev_camera::DefaultTimer_5052);
    *(undefined *)&this->field_0x378 = uVar4;
    getEvStringData(this,(char *)&this->field_0x3b8,"RelUseMask","oo");
    pfVar2 = getEvActor(this,"RelActor");
    (this->mEvBasePos).z = (float)pfVar2;
    pfVar2 = (fopAc_ac_c *)(this->mEvBasePos).z;
    if (pfVar2 == (fopAc_ac_c *)0x0) {
      *(undefined4 *)&this->field_0x388 = *(undefined4 *)this->mEvRelUseMask;
      *(int *)&this->field_0x38c = this->mEvTimer;
      *(undefined4 *)&this->field_0x390 = *(undefined4 *)&this->field_0x3a8;
    }
    else {
      cVar5 = *(char *)&this->field_0x3b8;
      if (cVar5 == 'o') {
        relationalPos(&local_88,this,pfVar2,(cXyz *)this->mEvRelUseMask);
        *(float *)&this->field_0x388 = local_88.x;
        *(float *)&this->field_0x38c = local_88.y;
        *(float *)&this->field_0x390 = local_88.z;
      }
      else {
        if (cVar5 == 'n') {
          positionOf(&cStack148,this,pfVar2);
          ::cXyz::operator__(&cStack160,&this->mEye,&cStack148);
          cSGlobe::cSGlobe(&cStack692,&cStack160);
          directionOf((dCamera_c *)(acStack752 + 2),(fopAc_ac_c *)this);
          cSAngle::operator__(acStack752,&cStack692.mAngleY);
          cSAngle::cSAngle(local_2e0,acStack752);
          if (local_2e0[0] < cSAngle::_0) {
            *(float *)this->mEvRelUseMask = -*(float *)this->mEvRelUseMask;
          }
          relationalPos(&local_ac,this,(fopAc_ac_c *)(this->mEvBasePos).z,
                        (cXyz *)this->mEvRelUseMask);
          *(float *)&this->field_0x388 = local_ac.x;
          *(float *)&this->field_0x38c = local_ac.y;
          *(float *)&this->field_0x390 = local_ac.z;
        }
        else {
          if (cVar5 == 'p') {
            relationalPos(&local_b8,this,pfVar2,(cXyz *)this->mEvRelUseMask);
            local_40.x = local_b8.x;
            local_40.y = local_b8.y;
            local_40.z = local_b8.z;
            positionOf(&cStack196,this,this->mpPlayerActor);
            ::cXyz::operator__(&local_d0,&local_40,&cStack196);
            local_dc.x = local_d0.x;
            local_dc.y = local_d0.y;
            local_dc.z = local_d0.z;
            fVar10 = mtx::PSVECSquareMag(&local_dc);
            dVar9 = (double)fVar10;
            if ((double)d_ev_camera::_4862 < dVar9) {
              dVar7 = 1.0 / SQRT(dVar9);
              dVar7 = d_ev_camera::_4863 * dVar7 * (d_ev_camera::_4864 - dVar9 * dVar7 * dVar7);
              dVar7 = d_ev_camera::_4863 * dVar7 * (d_ev_camera::_4864 - dVar9 * dVar7 * dVar7);
              local_2c8 = (float)(dVar9 * d_ev_camera::_4863 * dVar7 *
                                          (d_ev_camera::_4864 - dVar9 * dVar7 * dVar7));
              dVar9 = (double)local_2c8;
            }
            *(float *)this->mEvRelUseMask = -*(float *)this->mEvRelUseMask;
            relationalPos(&local_e8,this,(fopAc_ac_c *)(this->mEvBasePos).z,
                          (cXyz *)this->mEvRelUseMask);
            local_40.x = local_e8.x;
            local_40.y = local_e8.y;
            local_40.z = local_e8.z;
            positionOf(&cStack244,this,this->mpPlayerActor);
            ::cXyz::operator__(&local_100,&local_40,&cStack244);
            local_10c.x = local_100.x;
            local_10c.y = local_100.y;
            local_10c.z = local_100.z;
            fVar10 = mtx::PSVECSquareMag(&local_10c);
            dVar7 = (double)fVar10;
            if ((double)d_ev_camera::_4862 < dVar7) {
              dVar8 = 1.0 / SQRT(dVar7);
              dVar8 = d_ev_camera::_4863 * dVar8 * (d_ev_camera::_4864 - dVar7 * dVar8 * dVar8);
              dVar8 = d_ev_camera::_4863 * dVar8 * (d_ev_camera::_4864 - dVar7 * dVar8 * dVar8);
              local_2cc = (float)(dVar7 * d_ev_camera::_4863 * dVar8 *
                                          (d_ev_camera::_4864 - dVar7 * dVar8 * dVar8));
              dVar7 = (double)local_2cc;
            }
            if (dVar7 < dVar9) {
              *(float *)this->mEvRelUseMask = -*(float *)this->mEvRelUseMask;
            }
            relationalPos(&local_118,this,(fopAc_ac_c *)(this->mEvBasePos).z,
                          (cXyz *)this->mEvRelUseMask);
            *(float *)&this->field_0x388 = local_118.x;
            *(float *)&this->field_0x38c = local_118.y;
            *(float *)&this->field_0x390 = local_118.z;
          }
        }
      }
    }
    pfVar2 = (fopAc_ac_c *)(this->mEvBasePos).z;
    if ((pfVar2 == (fopAc_ac_c *)0x0) || (*(char *)&this->field_0x3b9 != 'o')) {
      if ((pfVar2 == (fopAc_ac_c *)0x0) || (*(char *)&this->field_0x3b9 != 'r')) {
        if (*(char *)&this->field_0x3b9 == 'n') {
          positionOf(&cStack328,this,pfVar2);
          ::cXyz::operator__(&cStack340,&this->mEye,&cStack328);
          cSGlobe::cSGlobe(&cStack700,&cStack340);
          directionOf((dCamera_c *)(acStack760 + 2),(fopAc_ac_c *)this);
          cSAngle::operator__(acStack760,&cStack700.mAngleY);
          cSAngle::cSAngle(local_2e4,acStack760);
          if (local_2e4[0] < cSAngle::_0) {
            this->mEvFovy = -this->mEvFovy;
          }
          relationalPos(&local_160,this,(fopAc_ac_c *)(this->mEvBasePos).z,(cXyz *)&this->mEvFovy);
          *(float *)&this->field_0x37c = local_160.x;
          *(float *)&this->field_0x380 = local_160.y;
          *(float *)&this->field_0x384 = local_160.z;
        }
        else {
          if (*(char *)&this->field_0x3b9 == 'p') {
            relationalPos(&local_16c,this,pfVar2,(cXyz *)&this->mEvFovy);
            local_4c.x = local_16c.x;
            local_4c.y = local_16c.y;
            local_4c.z = local_16c.z;
            positionOf(&cStack376,this,this->mpPlayerActor);
            ::cXyz::operator__(&local_184,&local_4c,&cStack376);
            local_190.x = local_184.x;
            local_190.y = local_184.y;
            local_190.z = local_184.z;
            fVar10 = mtx::PSVECSquareMag(&local_190);
            dVar9 = (double)fVar10;
            if ((double)d_ev_camera::_4862 < dVar9) {
              dVar7 = 1.0 / SQRT(dVar9);
              dVar7 = d_ev_camera::_4863 * dVar7 * (d_ev_camera::_4864 - dVar9 * dVar7 * dVar7);
              dVar7 = d_ev_camera::_4863 * dVar7 * (d_ev_camera::_4864 - dVar9 * dVar7 * dVar7);
              local_2d0 = (float)(dVar9 * d_ev_camera::_4863 * dVar7 *
                                          (d_ev_camera::_4864 - dVar9 * dVar7 * dVar7));
              dVar9 = (double)local_2d0;
            }
            this->mEvFovy = -this->mEvFovy;
            relationalPos(&local_19c,this,(fopAc_ac_c *)(this->mEvBasePos).z,(cXyz *)&this->mEvFovy)
            ;
            local_4c.x = local_19c.x;
            local_4c.y = local_19c.y;
            local_4c.z = local_19c.z;
            positionOf(&cStack424,this,this->mpPlayerActor);
            ::cXyz::operator__(&local_1b4,&local_4c,&cStack424);
            local_1c0.x = local_1b4.x;
            local_1c0.y = local_1b4.y;
            local_1c0.z = local_1b4.z;
            fVar10 = mtx::PSVECSquareMag(&local_1c0);
            dVar7 = (double)fVar10;
            if ((double)d_ev_camera::_4862 < dVar7) {
              dVar8 = 1.0 / SQRT(dVar7);
              dVar8 = d_ev_camera::_4863 * dVar8 * (d_ev_camera::_4864 - dVar7 * dVar8 * dVar8);
              dVar8 = d_ev_camera::_4863 * dVar8 * (d_ev_camera::_4864 - dVar7 * dVar8 * dVar8);
              local_2d4 = (float)(dVar7 * d_ev_camera::_4863 * dVar8 *
                                          (d_ev_camera::_4864 - dVar7 * dVar8 * dVar8));
              dVar7 = (double)local_2d4;
            }
            if (dVar7 < dVar9) {
              this->mEvFovy = -this->mEvFovy;
            }
            relationalPos(&local_1cc,this,(fopAc_ac_c *)(this->mEvBasePos).z,(cXyz *)&this->mEvFovy)
            ;
            *(float *)&this->field_0x37c = local_1cc.x;
            *(float *)&this->field_0x380 = local_1cc.y;
            *(float *)&this->field_0x384 = local_1cc.z;
          }
          else {
            *(float *)&this->field_0x37c = this->mEvFovy;
            *(float *)&this->field_0x380 = this->mEvBank;
            *(fopAc_ac_c **)&this->field_0x384 = this->mpEvRelActor;
          }
        }
      }
      else {
        if ((this->field_0x80 & 1) != 0) {
          this->mEvFovy = -this->mEvFovy;
        }
        relationalPos(&local_130,this,(fopAc_ac_c *)(this->mEvBasePos).z,(cXyz *)&this->mEvFovy);
        *(float *)&this->field_0x37c = local_130.x;
        *(float *)&this->field_0x380 = local_130.y;
        *(float *)&this->field_0x384 = local_130.z;
        cVar5 = lineBGCheck(this,(cXyz *)&this->field_0x388,(cXyz *)&this->field_0x37c,0x8f);
        if (cVar5 != '\0') {
          this->mEvFovy = -this->mEvFovy;
        }
        relationalPos(&local_13c,this,(fopAc_ac_c *)(this->mEvBasePos).z,(cXyz *)&this->mEvFovy);
        *(float *)&this->field_0x37c = local_13c.x;
        *(float *)&this->field_0x380 = local_13c.y;
        *(float *)&this->field_0x384 = local_13c.z;
      }
    }
    else {
      relationalPos(&local_124,this,pfVar2,(cXyz *)&this->mEvFovy);
      *(float *)&this->field_0x37c = local_124.x;
      *(float *)&this->field_0x380 = local_124.y;
      *(float *)&this->field_0x384 = local_124.z;
    }
    *(undefined *)&this->field_0x102 = 1;
    *(undefined *)&this->field_0x101 = 1;
    *(undefined *)&this->field_0x100 = 1;
  }
  if (((*(int *)&this->field_0x3c0 == 1) || (*(int *)&this->field_0x3c0 == 2)) &&
     (pfVar2 = (fopAc_ac_c *)(this->mEvBasePos).z, pfVar2 != (fopAc_ac_c *)0x0)) {
    cVar5 = *(char *)&this->field_0x3b8;
    if (cVar5 == 'o') {
      relationalPos(&local_1d8,this,pfVar2,(cXyz *)this->mEvRelUseMask);
      *(float *)&this->field_0x388 = local_1d8.x;
      *(float *)&this->field_0x38c = local_1d8.y;
      *(float *)&this->field_0x390 = local_1d8.z;
    }
    else {
      if (cVar5 == 'n') {
        positionOf(&cStack484,this,pfVar2);
        ::cXyz::operator__(&cStack496,&this->mEye,&cStack484);
        cSGlobe::cSGlobe(&cStack708,&cStack496);
        directionOf((dCamera_c *)(acStack768 + 2),(fopAc_ac_c *)this);
        cSAngle::operator__(acStack768,&cStack708.mAngleY);
        cSAngle::cSAngle(local_2e8,acStack768);
        if (local_2e8[0] < cSAngle::_0) {
          *(float *)this->mEvRelUseMask = -*(float *)this->mEvRelUseMask;
        }
        relationalPos(&local_1fc,this,(fopAc_ac_c *)(this->mEvBasePos).z,(cXyz *)this->mEvRelUseMask
                     );
        *(float *)&this->field_0x388 = local_1fc.x;
        *(float *)&this->field_0x38c = local_1fc.y;
        *(float *)&this->field_0x390 = local_1fc.z;
      }
      else {
        if (cVar5 == 'p') {
          relationalPos(&local_208,this,pfVar2,(cXyz *)this->mEvRelUseMask);
          local_58.x = local_208.x;
          local_58.y = local_208.y;
          local_58.z = local_208.z;
          positionOf(&cStack532,this,this->mpPlayerActor);
          ::cXyz::operator__(&local_220,&local_58,&cStack532);
          local_22c.x = local_220.x;
          local_22c.y = local_220.y;
          local_22c.z = local_220.z;
          fVar10 = mtx::PSVECSquareMag(&local_22c);
          dVar9 = (double)fVar10;
          if ((double)d_ev_camera::_4862 < dVar9) {
            dVar7 = 1.0 / SQRT(dVar9);
            dVar7 = d_ev_camera::_4863 * dVar7 * (d_ev_camera::_4864 - dVar9 * dVar7 * dVar7);
            dVar7 = d_ev_camera::_4863 * dVar7 * (d_ev_camera::_4864 - dVar9 * dVar7 * dVar7);
            local_2d8 = (float)(dVar9 * d_ev_camera::_4863 * dVar7 *
                                        (d_ev_camera::_4864 - dVar9 * dVar7 * dVar7));
            dVar9 = (double)local_2d8;
          }
          *(float *)this->mEvRelUseMask = -*(float *)this->mEvRelUseMask;
          relationalPos(&local_238,this,(fopAc_ac_c *)(this->mEvBasePos).z,
                        (cXyz *)this->mEvRelUseMask);
          local_58.x = local_238.x;
          local_58.y = local_238.y;
          local_58.z = local_238.z;
          positionOf(&cStack580,this,this->mpPlayerActor);
          ::cXyz::operator__(&local_250,&local_58,&cStack580);
          local_25c.x = local_250.x;
          local_25c.y = local_250.y;
          local_25c.z = local_250.z;
          fVar10 = mtx::PSVECSquareMag(&local_25c);
          dVar7 = (double)fVar10;
          if ((double)d_ev_camera::_4862 < dVar7) {
            dVar8 = 1.0 / SQRT(dVar7);
            dVar8 = d_ev_camera::_4863 * dVar8 * (d_ev_camera::_4864 - dVar7 * dVar8 * dVar8);
            dVar8 = d_ev_camera::_4863 * dVar8 * (d_ev_camera::_4864 - dVar7 * dVar8 * dVar8);
            local_2dc = (float)(dVar7 * d_ev_camera::_4863 * dVar8 *
                                        (d_ev_camera::_4864 - dVar7 * dVar8 * dVar8));
            dVar7 = (double)local_2dc;
          }
          if (dVar7 < dVar9) {
            *(float *)this->mEvRelUseMask = -*(float *)this->mEvRelUseMask;
          }
          relationalPos(&local_268,this,(fopAc_ac_c *)(this->mEvBasePos).z,
                        (cXyz *)this->mEvRelUseMask);
          *(float *)&this->field_0x388 = local_268.x;
          *(float *)&this->field_0x38c = local_268.y;
          *(float *)&this->field_0x390 = local_268.z;
        }
      }
    }
  }
  ::cXyz::operator__(&cStack628,(cXyz *)&this->field_0x388,&this->field_0x44);
  ::cXyz::operator_(&cStack640,&cStack628,*(float *)&this->field_0x3d0);
  mtx::PSVECAdd(&this->field_0x44,&cStack640,&this->field_0x44);
  ::cXyz::operator__(&cStack652,(cXyz *)&this->field_0x37c,(cXyz *)&this->field_0x388);
  cSGlobe::Val(&this->field_0x3c,&cStack652);
  if (*(int *)&this->field_0x3c0 == 2) {
    cSAngle::cSAngle(local_304,*(float *)&this->field_0x3cc);
    cSAngle::cSAngle(local_314,local_304[0]);
    (this->field_0x3c).mAngleX.v = local_314[0];
  }
  iStack44 = this->field_0x11c;
  local_30 = 0x43300000;
  cSAngle::cSAngle(acStack776,
                   (float)((double)CONCAT44(0x43300000,iStack44) - d_ev_camera::_5488) *
                   *(float *)&this->field_0x3c4);
  cSAngle::operator__(local_30c,&(this->field_0x3c).mAngleY);
  cSAngle::cSAngle(local_318,local_30c[0]);
  (this->field_0x3c).mAngleY.v = local_318[0];
  local_28 = (double)CONCAT44(0x43300000,this->field_0x11c);
  (this->field_0x3c).mDistance =
       (float)(local_28 - d_ev_camera::_5488) * *(float *)&this->field_0x3c8 +
       (this->field_0x3c).mDistance;
  cSGlobe::Xyz(&cStack664,&this->field_0x3c);
  ::cXyz::operator__(&local_2a4,&this->field_0x44,&cStack664);
  (this->field_0x50).x = local_2a4.x;
  (this->field_0x50).y = local_2a4.y;
  (this->field_0x50).z = local_2a4.z;
  this->field_0x60 = (this->mEvBasePos).x;
  if (*(char *)&this->field_0x379 != '\0') {
    iVar1 = (int)(d_ev_camera::_4865 * (this->mEvBasePos).y);
    local_28 = (double)(longlong)iVar1;
    cSAngle::cSAngle(local_310,(short)iVar1);
    ((cSAngle *)&this->field_0x5c)->v = local_310[0];
    this->mEventFlags = this->mEventFlags | 0x400;
  }
  if ((*(char *)&this->field_0x378 == '\0') ||
     (*(uint *)&this->field_0x3bc <= (uint)this->field_0x11c)) {
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  return uVar3;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall dCamera_c::fixedPositionEvCamera(void) */

int __thiscall dCamera_c::fixedPositionEvCamera(dCamera_c *this)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  undefined uVar7;
  int iVar4;
  fopAc_ac_c *pfVar5;
  uint uVar6;
  int iVar8;
  cSAngle local_98 [2];
  undefined4 local_94;
  cXyz local_90;
  cXyz cStack132;
  cXyz cStack120;
  cXyz cStack108;
  cXyz cStack96;
  cXyz local_54;
  cXyz local_48;
  cXyz local_3c;
  cXyz local_30;
  cXyz local_24;
  undefined4 local_18;
  uint uStack20;
  double local_10;
  
  if (d_ev_camera::init_5495 == '\0') {
    d_ev_camera::DefaultGap_5493 = ::cXyz::Zero.x;
    DAT_803e2678 = ::cXyz::Zero.y;
    DAT_803e267c = ::cXyz::Zero.z;
    Runtime.PPCEABI.H::__register_global_object
              (&d_ev_camera::DefaultGap_5493,::cXyz::_cXyz,&d_ev_camera::_5494);
    d_ev_camera::init_5495 = '\x01';
  }
  if (d_ev_camera::init_5498 == '\0') {
    d_ev_camera::DefaultRadius_5497 = d_ev_camera::_5606;
    d_ev_camera::init_5498 = '\x01';
  }
  if (d_ev_camera::init_5501 == '\0') {
    d_ev_camera::DefaultCtrCus_5500 = d_ev_camera::_5486;
    d_ev_camera::init_5501 = '\x01';
  }
  if (d_ev_camera::init_5504 == '\0') {
    d_ev_camera::DefaultTimer_5503 = -1;
    d_ev_camera::init_5504 = '\x01';
  }
  if (d_ev_camera::init_5507 == '\0') {
    d_ev_camera::DefaultBank_5506 = d_ev_camera::_4862;
    d_ev_camera::init_5507 = '\x01';
  }
  iVar8 = 1;
  if (this->field_0x11c == 0) {
    local_30.x = (this->mEye).x;
    local_30.y = (this->mEye).y;
    local_30.z = (this->mEye).z;
    getEvXyzData(this,&local_24,"Eye",&local_30);
    local_3c.x = d_ev_camera::DefaultGap_5493;
    local_3c.y = DAT_803e2678;
    local_3c.z = DAT_803e267c;
    getEvXyzData(this,(cXyz *)&this->field_0x388,"CtrGap",&local_3c);
    getEvFloatData(this,(float *)this->mEvRelUseMask,"Fovy",this->mFovY);
    getEvFloatData(this,(float *)&this->field_0x3a8,"CtrCus",d_ev_camera::DefaultCtrCus_5500);
    getEvFloatData(this,&(this->mEvBasePos).y,"Radius",d_ev_camera::DefaultRadius_5497);
    getEvFloatData(this,&(this->mEvBasePos).x,"StartRadius",(this->mEvBasePos).y);
    uVar7 = getEvFloatData(this,(float *)&this->mEvTimer,"Bank",d_ev_camera::DefaultBank_5506);
    *(undefined *)&this->field_0x379 = uVar7;
    getEvStringData(this,(char *)&this->field_0x3c0,"RelUseMask","o");
    uVar7 = getEvIntData(this,(int *)&this->field_0x3c4,"Timer",d_ev_camera::DefaultTimer_5503);
    *(undefined *)&this->field_0x378 = uVar7;
    iVar4 = getEvActor(this,"Target","@PLAYER");
    *(int *)&this->field_0x3b8 = iVar4;
    if (iVar4 == 0) {
      return 1;
    }
    if (*(int *)&this->field_0x3b8 == 0) {
      uVar3 = 0xffffffff;
    }
    else {
      uVar3 = *(undefined4 *)(*(int *)&this->field_0x3b8 + 4);
    }
    *(undefined4 *)&this->field_0x3bc = uVar3;
    pfVar5 = getEvActor(this,"RelActor");
    (this->mEvBasePos).z = (float)pfVar5;
    pfVar5 = (fopAc_ac_c *)(this->mEvBasePos).z;
    if ((pfVar5 == (fopAc_ac_c *)0x0) || (*(char *)&this->field_0x3c0 == '-')) {
      *(float *)&this->field_0x37c = local_24.x;
      *(float *)&this->field_0x380 = local_24.y;
      *(float *)&this->field_0x384 = local_24.z;
    }
    else {
      relationalPos(&local_48,this,pfVar5,&local_24);
      *(float *)&this->field_0x37c = local_48.x;
      *(float *)&this->field_0x380 = local_48.y;
      *(float *)&this->field_0x384 = local_48.z;
    }
    this->mEvFovy = (this->mCenter).x;
    this->mEvBank = (this->mCenter).y;
    this->mpEvRelActor = (fopAc_ac_c *)(this->mCenter).z;
    *(undefined *)&this->field_0x102 = 1;
    *(undefined *)&this->field_0x101 = 1;
    *(undefined *)&this->field_0x100 = 1;
  }
  local_94 = *(undefined4 *)&this->field_0x3bc;
  pfVar5 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,&local_94);
  if (pfVar5 == (fopAc_ac_c *)0x0) {
    iVar8 = 1;
  }
  else {
    relationalPos(&local_54,this,*(fopAc_ac_c **)&this->field_0x3b8,(cXyz *)&this->field_0x388);
    this->mEvFovy = local_54.x;
    this->mEvBank = local_54.y;
    this->mpEvRelActor = (fopAc_ac_c *)local_54.z;
    ::cXyz::operator__(&cStack96,(cXyz *)&this->mEvFovy,&this->field_0x44);
    ::cXyz::operator_(&cStack108,&cStack96,*(float *)&this->field_0x3a8);
    mtx::PSVECAdd(&this->field_0x44,&cStack108,&this->field_0x44);
    (this->field_0x50).x = *(float *)&this->field_0x37c;
    (this->field_0x50).y = *(float *)&this->field_0x380;
    (this->field_0x50).z = *(float *)&this->field_0x384;
    ::cXyz::operator__(&cStack120,&this->field_0x50,&this->field_0x44);
    cSGlobe::Val(&this->field_0x3c,&cStack120);
    fVar1 = (this->mEvBasePos).y;
    if (*(char *)&this->field_0x378 != '\0') {
      uVar6 = this->field_0x11c;
      if (uVar6 < *(uint *)&this->field_0x3c4) {
        fVar2 = (this->mEvBasePos).x;
        local_18 = 0x43300000;
        local_10 = (double)CONCAT44(0x43300000,*(uint *)&this->field_0x3c4 ^ 0x80000000);
        fVar1 = fVar2 + (fVar1 - fVar2) *
                        ((float)((double)CONCAT44(0x43300000,uVar6) - d_ev_camera::_5488) /
                        (float)(local_10 - d_ev_camera::_5609));
        iVar8 = 0;
        uStack20 = uVar6;
      }
    }
    if (fVar1 < (this->field_0x3c).mDistance) {
      (this->field_0x3c).mDistance = fVar1;
      cSGlobe::Xyz(&cStack132,&this->field_0x3c);
      ::cXyz::operator__(&local_90,&this->field_0x44,&cStack132);
      (this->field_0x50).x = local_90.x;
      (this->field_0x50).y = local_90.y;
      (this->field_0x50).z = local_90.z;
    }
    this->field_0x60 = *(float *)this->mEvRelUseMask;
    if (*(char *)&this->field_0x379 != '\0') {
      iVar4 = (int)(d_ev_camera::_4865 * (float)this->mEvTimer);
      local_10 = (double)(longlong)iVar4;
      cSAngle::cSAngle(local_98,(short)iVar4);
      ((cSAngle *)&this->field_0x5c)->v = local_98[0];
      this->mEventFlags = this->mEventFlags | 0x400;
    }
    if (iVar8 != 0) {
      *(undefined *)&this->field_0x102 = 1;
      *(undefined *)&this->field_0x101 = 1;
      *(undefined *)&this->field_0x100 = 1;
    }
  }
  return iVar8;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x800b3ca8) */
/* __thiscall dCamera_c::uniformTransEvCamera(void) */

undefined4 __thiscall dCamera_c::uniformTransEvCamera(dCamera_c *this)

{
  undefined4 uVar1;
  char cVar5;
  undefined uVar6;
  byte bVar7;
  fopAc_ac_c *pfVar2;
  int iVar3;
  cSGlobe *pcVar4;
  cXyz *pcVar8;
  undefined4 uVar9;
  cXyz *pcVar10;
  undefined4 uVar11;
  double dVar12;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  double dVar13;
  undefined8 in_f31;
  cSAngle acStack1496 [2];
  cSAngle acStack1492 [2];
  cSAngle acStack1488 [2];
  cSAngle acStack1484 [2];
  cSAngle acStack1480 [2];
  cSAngle acStack1476 [2];
  cSAngle acStack1472 [2];
  cSAngle acStack1468 [2];
  cSAngle acStack1464 [4];
  cSAngle acStack1456 [4];
  cSAngle acStack1448 [2];
  cSAngle acStack1444 [2];
  cSAngle acStack1440 [2];
  cSAngle acStack1436 [4];
  cSAngle acStack1428 [4];
  cSAngle local_58c [2];
  cSAngle local_588 [2];
  float local_584;
  cSGlobe cStack1408;
  cSGlobe local_578;
  cSGlobe local_570;
  cSGlobe cStack1384;
  cSGlobe cStack1376;
  cSGlobe cStack1368;
  cSGlobe cStack1360;
  cSGlobe cStack1352;
  cSGlobe cStack1344;
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
  cXyz cStack388;
  cXyz cStack376;
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
  cXyz local_dc;
  cXyz cStack208;
  cXyz local_c4;
  cXyz cStack184;
  cXyz cStack172;
  cXyz cStack160;
  cXyz cStack148;
  cXyz cStack136;
  cXyz cStack124;
  cXyz cStack112;
  cXyz cStack100;
  cXyz cStack88;
  cXyz cStack76;
  undefined4 local_40;
  int iStack60;
  undefined4 local_38;
  uint uStack52;
  undefined auStack8 [8];
  
  uVar11 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (d_ev_camera::init_5614 == '\0') {
    d_ev_camera::DefaultTimer_5613 = 0xffffffff;
    d_ev_camera::init_5614 = '\x01';
  }
  if (d_ev_camera::init_5617 == '\0') {
    d_ev_camera::DefaultBank_5616 = d_ev_camera::_4862;
    d_ev_camera::init_5617 = '\x01';
  }
  pcVar10 = (cXyz *)&this->field_0x378;
  uVar9 = 0;
  if (this->field_0x11c == 0) {
    cVar5 = getEvIntData(this,(int *)&this->field_0x3c8,"Timer");
    if (cVar5 == '\0') {
      @class$5621d_ev_camera_cpp::__class_5621d_ev_camera_cpp
                ((_class_5621d_ev_camera_cpp *)&cStack112);
      @class$5621d_ev_camera_cpp::__class_5621d_ev_camera_cpp
                ((_class_5621d_ev_camera_cpp *)&cStack88);
      uVar9 = 1;
      goto LAB_800b3ca8;
    }
    getEvIntData(this,(int *)&this->field_0x3e0,"BSpCurve",1);
    if (*(int *)&this->field_0x3e0 != 0) {
      d2DBSplinePath::Init(&this->mSpline2DPath,4,*(long *)&this->field_0x3c8);
    }
    ::cXyz::cXyz(&cStack292,&this->mEye);
    getEvXyzData(this,(cXyz *)&this->mEvBank,"Eye",&cStack292);
    ::cXyz::cXyz(&cStack304,&this->mCenter);
    getEvXyzData(this,(cXyz *)&this->mEvTimer,"Center",&cStack304);
    getEvFloatData(this,&(this->mEvBasePos).y,"Fovy",this->mFovY);
    ::cXyz::cXyz(&cStack316,&this->mEye);
    getEvXyzData(this,pcVar10,"StartEye",&cStack316);
    ::cXyz::cXyz(&cStack328,&this->mCenter);
    getEvXyzData(this,(cXyz *)&this->field_0x384,"StartCenter",&cStack328);
    getEvFloatData(this,(float *)&this->field_0x390,"StartFovy",this->mFovY);
    dVar12 = (double)cSAngle::Degree(&this->mBank);
    uVar6 = getEvFloatData(this,&(this->mEvBasePos).z,"Bank",(float)dVar12);
    *(undefined *)&this->field_0x3dc = uVar6;
    dVar12 = (double)cSAngle::Degree(&this->mBank);
    bVar7 = getEvFloatData(this,&this->mEvFovy,"StartBank",(float)dVar12);
    *(byte *)&this->field_0x3dc = *(byte *)&this->field_0x3dc | bVar7;
    getEvIntData(this,(int *)&this->field_0x3cc,"TransType",0);
    getEvStringData(this,(char *)&this->field_0x3c0,"RelUseMask","--oo");
    pfVar2 = getEvActor(this,"RelActor");
    *(fopAc_ac_c **)&this->field_0x3b8 = pfVar2;
    dVar12 = (double)getEvFloatData(this,(float *)&this->field_0x3d0,"Cushion",d_ev_camera::_5486);
    iVar3 = *(int *)&this->field_0x3b8;
    if (iVar3 != 0) {
      if (iVar3 == 0) {
        uVar1 = 0xffffffff;
      }
      else {
        uVar1 = *(undefined4 *)(iVar3 + 4);
      }
      *(undefined4 *)&this->field_0x3bc = uVar1;
      if (*(char *)&this->field_0x3c1 == 'r') {
        relationalPos(&cStack340,this,*(fopAc_ac_c **)&this->field_0x3b8,(cXyz *)&this->field_0x384)
        ;
        ::cXyz::operator__(&cStack124,&cStack340);
        if ((this->field_0x80 & 1) != 0) {
          pcVar10->x = -pcVar10->x;
        }
        relationalPos(&cStack352,this,*(fopAc_ac_c **)&this->field_0x3b8,pcVar10);
        ::cXyz::operator__(&cStack136,&cStack352);
        cVar5 = lineBGCheck(this,&cStack124,&cStack136,0x8f);
        dVar12 = extraout_f1;
        if (cVar5 != '\0') {
          pcVar10->x = -pcVar10->x;
        }
      }
      if ((*(char *)&this->field_0x3c0 == 'n') || (*(char *)&this->field_0x3c1 == 'n')) {
        positionOf(&cStack364,this,*(fopAc_ac_c **)&this->field_0x3b8);
        ::cXyz::operator__(&cStack376,&this->mEye,&cStack364);
        cSGlobe::cSGlobe(&cStack1344,&cStack376);
        directionOf((dCamera_c *)(acStack1428 + 2),(fopAc_ac_c *)this);
        cSAngle::operator__(acStack1428,&cStack1344.mAngleY);
        cSAngle::cSAngle(local_588,acStack1428);
        if (local_588[0] < cSAngle::_0) {
          if (*(char *)&this->field_0x3c0 == 'n') {
            *(float *)&this->field_0x384 = -*(float *)&this->field_0x384;
          }
          if (*(char *)&this->field_0x3c1 == 'n') {
            pcVar10->x = -pcVar10->x;
          }
        }
        relationalPos(&cStack388,this,*(fopAc_ac_c **)&this->field_0x3b8,(cXyz *)&this->field_0x384)
        ;
        ::cXyz::operator__(&cStack148,&cStack388);
        relationalPos(&cStack400,this,*(fopAc_ac_c **)&this->field_0x3b8,pcVar10);
        ::cXyz::operator__(&cStack160,&cStack400);
        cVar5 = lineBGCheck(this,&cStack148,&cStack160,0x8f);
        if (cVar5 != '\0') {
          pcVar10->x = -pcVar10->x;
        }
        dVar12 = extraout_f1_00;
        cSGlobe::_cSGlobe(&cStack1344);
      }
      if ((*(char *)&this->field_0x3c2 == 'n') || (*(char *)&this->field_0x3c3 == 'n')) {
        positionOf(&cStack412,this,*(fopAc_ac_c **)&this->field_0x3b8);
        ::cXyz::operator__(&cStack424,(cXyz *)&this->mEvBank,&cStack412);
        cSGlobe::cSGlobe(&cStack1352,&cStack424);
        directionOf((dCamera_c *)(acStack1436 + 2),(fopAc_ac_c *)this);
        cSAngle::operator__(acStack1436,&cStack1352.mAngleY);
        cSAngle::cSAngle(local_58c,acStack1436);
        if (local_58c[0] < cSAngle::_0) {
          if (*(char *)&this->field_0x3c2 == 'n') {
            this->mEvTimer = (int)-(float)this->mEvTimer;
          }
          if (*(char *)&this->field_0x3c3 == 'n') {
            this->mEvBank = -this->mEvBank;
          }
        }
        relationalPos(&cStack436,this,*(fopAc_ac_c **)&this->field_0x3b8,(cXyz *)&this->mEvTimer);
        ::cXyz::operator__(&cStack172,&cStack436);
        relationalPos(&cStack448,this,*(fopAc_ac_c **)&this->field_0x3b8,(cXyz *)&this->mEvBank);
        ::cXyz::operator__(&cStack184,&cStack448);
        cVar5 = lineBGCheck(this,&cStack172,&cStack184,0x8f);
        if (cVar5 != '\0') {
          this->mEvBank = -this->mEvBank;
        }
        dVar12 = extraout_f1_01;
        cSGlobe::_cSGlobe(&cStack1352);
      }
      if (*(char *)&this->field_0x3c2 == 'p') {
        ::cXyz::cXyz(&local_c4,(cXyz *)&this->mEvTimer);
        relationalPos(&cStack460,this,*(fopAc_ac_c **)&this->field_0x3b8,&local_c4);
        ::cXyz::cXyz(&cStack208,&cStack460);
        positionOf(&cStack472,this,this->mpPlayerActor);
        ::cXyz::operator__(&cStack484,&cStack208,&cStack472);
        pcVar8 = &cStack484;
        ::cXyz::cXyz(&cStack496,pcVar8);
        ::cXyz::abs(&cStack496,(int)pcVar8);
        local_c4.x = -local_c4.x;
        relationalPos(&cStack508,this,*(fopAc_ac_c **)&this->field_0x3b8,&local_c4);
        dVar13 = dVar12;
        dVar12 = (double)::cXyz::operator__(&cStack208,&cStack508);
        positionOf(&cStack520,this,this->mpPlayerActor);
        ::cXyz::operator__(&cStack532,&cStack208,&cStack520);
        pcVar8 = &cStack532;
        ::cXyz::cXyz(&cStack544,pcVar8);
        ::cXyz::abs(&cStack544,(int)pcVar8);
        if (dVar13 < dVar12) {
          this->mEvTimer = (int)-(float)this->mEvTimer;
        }
      }
      if (*(char *)&this->field_0x3c3 == 'p') {
        ::cXyz::cXyz(&local_dc,(cXyz *)&this->mEvBank);
        relationalPos(&cStack556,this,*(fopAc_ac_c **)&this->field_0x3b8,&local_dc);
        ::cXyz::cXyz(&cStack232,&cStack556);
        positionOf(&cStack568,this,this->mpPlayerActor);
        ::cXyz::operator__(&cStack580,&cStack232,&cStack568);
        pcVar8 = &cStack580;
        ::cXyz::cXyz(&cStack592,pcVar8);
        ::cXyz::abs(&cStack592,(int)pcVar8);
        local_dc.x = -local_dc.x;
        relationalPos(&cStack604,this,*(fopAc_ac_c **)&this->field_0x3b8,&local_dc);
        dVar13 = (double)::cXyz::operator__(&cStack232,&cStack604);
        positionOf(&cStack616,this,this->mpPlayerActor);
        ::cXyz::operator__(&cStack628,&cStack232,&cStack616);
        pcVar8 = &cStack628;
        ::cXyz::cXyz(&cStack640,pcVar8);
        ::cXyz::abs(&cStack640,(int)pcVar8);
        if (dVar12 < dVar13) {
          this->mEvBank = -this->mEvBank;
        }
      }
      else {
        if (*(char *)&this->field_0x3c3 == 'r') {
          relationalPos(&cStack652,this,*(fopAc_ac_c **)&this->field_0x3b8,(cXyz *)&this->mEvTimer);
          ::cXyz::operator__(&cStack244,&cStack652);
          if ((this->field_0x80 & 1) != 0) {
            this->mEvBank = -this->mEvBank;
          }
          relationalPos(&cStack664,this,*(fopAc_ac_c **)&this->field_0x3b8,(cXyz *)&this->mEvBank);
          ::cXyz::operator__(&cStack256,&cStack664);
          cVar5 = lineBGCheck(this,&cStack244,&cStack256,0x8f);
          if (cVar5 != '\0') {
            this->mEvBank = -this->mEvBank;
          }
        }
      }
    }
    pcVar4 = (cSGlobe *)cSGlobe::Invert((cSGlobe *)&this->field_0x8);
    cSGlobe::operator__((cSGlobe *)&this->field_0x3d4,pcVar4);
    *(undefined *)&this->field_0x102 = 1;
    *(undefined *)&this->field_0x101 = 1;
    *(undefined *)&this->field_0x100 = 1;
  }
  if (*(int *)&this->field_0x3b8 != 0) {
    local_584 = *(float *)&this->field_0x3bc;
    pfVar2 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,&local_584);
    if (pfVar2 == (fopAc_ac_c *)0x0) {
      @class$5621d_ev_camera_cpp::__class_5621d_ev_camera_cpp
                ((_class_5621d_ev_camera_cpp *)&cStack112);
      @class$5621d_ev_camera_cpp::__class_5621d_ev_camera_cpp
                ((_class_5621d_ev_camera_cpp *)&cStack88);
      uVar9 = 1;
      goto LAB_800b3ca8;
    }
  }
  if ((uint)this->field_0x11c < *(uint *)&this->field_0x3c8) {
    if (*(int *)&this->field_0x3e0 == 0) {
      iStack60 = this->field_0x11c + 1;
      local_40 = 0x43300000;
      uStack52 = *(uint *)&this->field_0x3c8 ^ 0x80000000;
      local_38 = 0x43300000;
      dVar12 = (double)((float)((double)CONCAT44(0x43300000,iStack60) - d_ev_camera::_5488) /
                       (float)((double)CONCAT44(0x43300000,uStack52) - d_ev_camera::_5609));
    }
    else {
      d2DBSplinePath::Step(&this->mSpline2DPath);
      dVar12 = (double)d2DBSplinePath::Calc
                                 (&this->mSpline2DPath,(float *)&d_ev_camera::curvePoints_5622);
    }
  }
  else {
    uVar9 = 1;
    dVar12 = (double)d_ev_camera::_5486;
  }
  pfVar2 = *(fopAc_ac_c **)&this->field_0x3b8;
  if (pfVar2 == (fopAc_ac_c *)0x0) {
    ::cXyz::operator__(&cStack76,(cXyz *)&this->field_0x384);
    ::cXyz::operator__(&cStack88,pcVar10);
    ::cXyz::operator__(&cStack100,(cXyz *)&this->mEvTimer);
    ::cXyz::operator__(&cStack112,(cXyz *)&this->mEvBank);
  }
  else {
    cVar5 = *(char *)&this->field_0x3c0;
    if (cVar5 == 't') {
      attentionPos(&cStack676,this,pfVar2);
      ::cXyz::operator__(&cStack688,&cStack676,(cXyz *)&this->field_0x384);
      ::cXyz::operator__(&cStack76,&cStack688);
    }
    else {
      if (cVar5 == 'c') {
        cSGlobe::cSGlobe(&cStack1360,(cXyz *)&this->field_0x384);
        cSAngle::operator__(acStack1440,(cSAngle *)&this->field_0x3da);
        cSGlobe::U(&cStack1360,acStack1440);
        attentionPos(&cStack700,this,*(fopAc_ac_c **)&this->field_0x3b8);
        cSGlobe::Xyz(&cStack712,&cStack1360);
        ::cXyz::operator__(&cStack724,&cStack700,&cStack712);
        ::cXyz::operator__(&cStack76,&cStack724);
        cSGlobe::_cSGlobe(&cStack1360);
      }
      else {
        if (cVar5 == '-') {
          ::cXyz::operator__(&cStack76,(cXyz *)&this->field_0x384);
        }
        else {
          relationalPos(&cStack736,this,pfVar2,(cXyz *)&this->field_0x384);
          ::cXyz::operator__(&cStack76,&cStack736);
        }
      }
    }
    cVar5 = *(char *)&this->field_0x3c1;
    if (cVar5 == 't') {
      attentionPos(&cStack748,this,*(fopAc_ac_c **)&this->field_0x3b8);
      ::cXyz::operator__(&cStack760,&cStack748,pcVar10);
      ::cXyz::operator__(&cStack88,&cStack760);
    }
    else {
      if (cVar5 == 'c') {
        cSGlobe::cSGlobe(&cStack1368,pcVar10);
        cSAngle::operator__(acStack1444,(cSAngle *)&this->field_0x3da);
        cSGlobe::U(&cStack1368,acStack1444);
        attentionPos(&cStack772,this,*(fopAc_ac_c **)&this->field_0x3b8);
        cSGlobe::Xyz(&cStack784,&cStack1368);
        ::cXyz::operator__(&cStack796,&cStack772,&cStack784);
        ::cXyz::operator__(&cStack88,&cStack796);
        cSGlobe::_cSGlobe(&cStack1368);
      }
      else {
        if (cVar5 == '-') {
          ::cXyz::operator__(&cStack88,pcVar10);
        }
        else {
          relationalPos(&cStack808,this,*(fopAc_ac_c **)&this->field_0x3b8,pcVar10);
          ::cXyz::operator__(&cStack88,&cStack808);
        }
      }
    }
    cVar5 = *(char *)&this->field_0x3c2;
    if (cVar5 == 't') {
      attentionPos(&cStack820,this,*(fopAc_ac_c **)&this->field_0x3b8);
      ::cXyz::operator__(&cStack832,&cStack820,(cXyz *)&this->mEvTimer);
      ::cXyz::operator__(&cStack100,&cStack832);
    }
    else {
      if (cVar5 == 'c') {
        cSGlobe::cSGlobe(&cStack1376,(cXyz *)&this->mEvTimer);
        cSAngle::operator__(acStack1448,(cSAngle *)&this->field_0x3da);
        cSGlobe::U(&cStack1376,acStack1448);
        attentionPos(&cStack844,this,*(fopAc_ac_c **)&this->field_0x3b8);
        cSGlobe::Xyz(&cStack856,&cStack1376);
        ::cXyz::operator__(&cStack868,&cStack844,&cStack856);
        ::cXyz::operator__(&cStack100,&cStack868);
        cSGlobe::_cSGlobe(&cStack1376);
      }
      else {
        if (cVar5 == '-') {
          if (*(int *)&this->field_0x3cc == 2) {
            directionOf((dCamera_c *)(acStack1456 + 2),(fopAc_ac_c *)this);
            dCamMath::xyzRotateY(&cStack892,(cSAngle)((short)this + 0x3a4));
            ::cXyz::operator__(&cStack100,&cStack892);
          }
          else {
            ::cXyz::operator__(&cStack100,(cXyz *)&this->mEvTimer);
          }
        }
        else {
          relationalPos(&cStack880,this,*(fopAc_ac_c **)&this->field_0x3b8,(cXyz *)&this->mEvTimer);
          ::cXyz::operator__(&cStack100,&cStack880);
        }
      }
    }
    cVar5 = *(char *)&this->field_0x3c3;
    if (cVar5 == 't') {
      attentionPos(&cStack904,this,*(fopAc_ac_c **)&this->field_0x3b8);
      ::cXyz::operator__(&cStack916,&cStack904,(cXyz *)&this->mEvBank);
      ::cXyz::operator__(&cStack112,&cStack916);
    }
    else {
      if (cVar5 == 'c') {
        cSGlobe::cSGlobe(&cStack1384,(cXyz *)&this->mEvBank);
        cSAngle::operator__(acStack1456,(cSAngle *)&this->field_0x3da);
        cSGlobe::U(&cStack1384,acStack1456);
        attentionPos(&cStack928,this,*(fopAc_ac_c **)&this->field_0x3b8);
        cSGlobe::Xyz(&cStack940,&cStack1384);
        ::cXyz::operator__(&cStack952,&cStack928,&cStack940);
        ::cXyz::operator__(&cStack112,&cStack952);
        cSGlobe::_cSGlobe(&cStack1384);
      }
      else {
        if (cVar5 == '-') {
          if (*(int *)&this->field_0x3cc == 2) {
            directionOf((dCamera_c *)(acStack1464 + 2),(fopAc_ac_c *)this);
            dCamMath::xyzRotateY(&cStack976,(cSAngle)((short)this + 0x398));
            ::cXyz::operator__(&cStack112,&cStack976);
          }
          else {
            ::cXyz::operator__(&cStack112,(cXyz *)&this->mEvBank);
          }
        }
        else {
          relationalPos(&cStack964,this,*(fopAc_ac_c **)&this->field_0x3b8,(cXyz *)&this->mEvBank);
          ::cXyz::operator__(&cStack112,&cStack964);
        }
      }
    }
  }
  if (*(int *)&this->field_0x3cc == 1) {
    ::cXyz::operator__(&cStack988,&cStack100,&cStack76);
    ::cXyz::operator_(&cStack1000,&cStack988,(float)dVar12);
    ::cXyz::operator__(&cStack1012,&cStack76,&cStack1000);
    ::cXyz::operator__(&cStack268,&cStack1012);
    ::cXyz::operator__(&cStack1024,&cStack268,&this->field_0x44);
    ::cXyz::operator_(&cStack1036,&cStack1024,*(float *)&this->field_0x3d0);
    mtx::PSVECAdd(&this->field_0x44,&cStack1036,&this->field_0x44);
    ::cXyz::operator__(&cStack1048,&cStack88,&cStack76);
    cSGlobe::cSGlobe(&local_570,&cStack1048);
    ::cXyz::operator__(&cStack1060,&cStack112,&cStack100);
    cSGlobe::cSGlobe(&local_578,&cStack1060);
    cSAngle::operator__(acStack1464,&local_578.mAngleX);
    cSAngle::operator_(acStack1468,(float)dVar12);
    cSAngle::operator__(acStack1472,&local_570.mAngleX);
    cSAngle::operator__(acStack1476,&local_578.mAngleY);
    cSAngle::operator_(acStack1480,(float)dVar12);
    cSAngle::operator__(acStack1484,&local_570.mAngleY);
    cSGlobe::cSGlobe(&cStack1408,
                     local_570.mDistance +
                     (float)(dVar12 * (double)(local_578.mDistance - local_570.mDistance)),
                     acStack1472,acStack1484);
    cSGlobe::Xyz(&cStack1072,&cStack1408);
    ::cXyz::operator__(&cStack1084,&this->field_0x44,&cStack1072);
    ::cXyz::operator__(&cStack280,&cStack1084);
    ::cXyz::operator__(&cStack1096,&cStack280,&this->field_0x50);
    ::cXyz::operator_(&cStack1108,&cStack1096,*(float *)&this->field_0x3d0);
    mtx::PSVECAdd(&this->field_0x50,&cStack1108,&this->field_0x50);
    cSGlobe::_cSGlobe(&cStack1408);
    cSGlobe::_cSGlobe(&local_578);
    cSGlobe::_cSGlobe(&local_570);
  }
  else {
    if (*(int *)&this->field_0x3cc == 2) {
      ::cXyz::operator_(&cStack1120,&cStack100,(float)dVar12);
      ::cXyz::operator__(&cStack1132,&cStack76,&cStack1120);
      ::cXyz::operator__(&cStack268,&cStack1132);
      ::cXyz::operator__(&cStack1144,&cStack268,&this->field_0x44);
      ::cXyz::operator_(&cStack1156,&cStack1144,*(float *)&this->field_0x3d0);
      mtx::PSVECAdd(&this->field_0x44,&cStack1156,&this->field_0x44);
      ::cXyz::operator_(&cStack1168,&cStack112,(float)dVar12);
      ::cXyz::operator__(&cStack1180,&cStack88,&cStack1168);
      ::cXyz::operator__(&cStack280,&cStack1180);
      ::cXyz::operator__(&cStack1192,&cStack280,&this->field_0x50);
      ::cXyz::operator_(&cStack1204,&cStack1192,*(float *)&this->field_0x3d0);
      mtx::PSVECAdd(&this->field_0x50,&cStack1204,&this->field_0x50);
    }
    else {
      ::cXyz::operator__(&cStack1216,&cStack100,&cStack76);
      ::cXyz::operator_(&cStack1228,&cStack1216,(float)dVar12);
      ::cXyz::operator__(&cStack1240,&cStack76,&cStack1228);
      ::cXyz::operator__(&cStack268,&cStack1240);
      ::cXyz::operator__(&cStack1252,&cStack268,&this->field_0x44);
      ::cXyz::operator_(&cStack1264,&cStack1252,*(float *)&this->field_0x3d0);
      mtx::PSVECAdd(&this->field_0x44,&cStack1264,&this->field_0x44);
      ::cXyz::operator__(&cStack1276,&cStack112,&cStack88);
      ::cXyz::operator_(&cStack1288,&cStack1276,(float)dVar12);
      ::cXyz::operator__(&cStack1300,&cStack88,&cStack1288);
      ::cXyz::operator__(&cStack280,&cStack1300);
      ::cXyz::operator__(&cStack1312,&cStack280,&this->field_0x50);
      ::cXyz::operator_(&cStack1324,&cStack1312,*(float *)&this->field_0x3d0);
      mtx::PSVECAdd(&this->field_0x50,&cStack1324,&this->field_0x50);
    }
  }
  this->field_0x60 =
       this->field_0x60 +
       *(float *)&this->field_0x3d0 *
       ((*(float *)&this->field_0x390 +
        (float)(dVar12 * (double)((this->mEvBasePos).y - *(float *)&this->field_0x390))) -
       this->field_0x60);
  if (*(char *)&this->field_0x3dc != '\0') {
    cSAngle::cSAngle(acStack1488,
                     this->mEvFovy +
                     (float)(dVar12 * (double)((this->mEvBasePos).z - this->mEvFovy)));
    cSAngle::operator__(acStack1492,acStack1488);
    cSAngle::operator_(acStack1496,*(float *)&this->field_0x3d0);
    cSAngle::operator___((cSAngle *)&this->field_0x5c,acStack1496);
    this->mEventFlags = this->mEventFlags | 0x400;
  }
  ::cXyz::operator__(&cStack1336,&this->field_0x50,&this->field_0x44);
  cSGlobe::Val(&this->field_0x3c,&cStack1336);
  @class$5621d_ev_camera_cpp::__class_5621d_ev_camera_cpp((_class_5621d_ev_camera_cpp *)&cStack112);
  @class$5621d_ev_camera_cpp::__class_5621d_ev_camera_cpp((_class_5621d_ev_camera_cpp *)&cStack88);
LAB_800b3ca8:
  __psq_l0(auStack8,uVar11);
  __psq_l1(auStack8,uVar11);
  return uVar9;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall cSGlobe::U(cSAngle const &) */

void __thiscall cSGlobe::U(cSGlobe *this,cSAngle *param_1)

{
  cSAngle local_18 [10];
  
  cSAngle::cSAngle(local_18,param_1->v);
  (this->mAngleY).v = local_18[0];
  return;
}


/* __thiscall cSGlobe::operator =(cSGlobe const &) */

void __thiscall cSGlobe::operator__(cSGlobe *this,cSGlobe *param_1)

{
  this->mDistance = param_1->mDistance;
  (this->mAngleX).v = (param_1->mAngleX).v;
  (this->mAngleY).v = (param_1->mAngleY).v;
  return;
}


/* __thiscall cXyz::abs(void) const */

int __thiscall cXyz::abs(cXyz *this,int __x)

{
  mtx::PSVECSquareMag(this);
  return (int)this;
}


/* __thiscall cXyz::operator =(cXyz const &) */

void __thiscall cXyz::operator__(cXyz *this,cXyz *param_1)

{
  this->x = param_1->x;
  this->y = param_1->y;
  this->z = param_1->z;
  return;
}


/* __thiscall cXyz::cXyz(cXyz const &) */

void __thiscall cXyz::cXyz(cXyz *this,cXyz *param_1)

{
  this->x = param_1->x;
  this->y = param_1->y;
  this->z = param_1->z;
  return;
}


namespace dCamera_c {

/* __thiscall @class$5621d_ev_camera_cpp::~@class$5621d_ev_camera_cpp(void) */

void __thiscall
@class$5621d_ev_camera_cpp::__class_5621d_ev_camera_cpp(_class_5621d_ev_camera_cpp *this)

{
  short in_r4;
  
  if ((this != (_class_5621d_ev_camera_cpp *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}

}

/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x800b50f0) */
/* __thiscall dCamera_c::uniformBrakeEvCamera(void) */

undefined4 __thiscall dCamera_c::uniformBrakeEvCamera(dCamera_c *this)

{
  float fVar1;
  undefined4 uVar2;
  char cVar7;
  undefined uVar8;
  byte bVar9;
  fopAc_ac_c *pfVar3;
  int iVar4;
  cSGlobe *pcVar5;
  uint uVar6;
  cXyz *pcVar10;
  uint uVar11;
  undefined4 uVar12;
  cXyz *pcVar13;
  undefined4 uVar14;
  double dVar15;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  double dVar16;
  undefined8 in_f31;
  cSAngle acStack1496 [2];
  undefined auStack1492 [4];
  cSAngle acStack1488 [2];
  cSAngle acStack1484 [2];
  cSAngle acStack1480 [2];
  cSAngle acStack1476 [2];
  cSAngle acStack1472 [2];
  cSAngle acStack1468 [4];
  cSAngle acStack1460 [4];
  cSAngle acStack1452 [2];
  cSAngle acStack1448 [2];
  cSAngle acStack1444 [2];
  cSAngle acStack1440 [4];
  cSAngle acStack1432 [4];
  cSAngle local_590 [2];
  cSAngle local_58c [2];
  float local_588;
  cSGlobe cStack1412;
  cSGlobe local_57c;
  cSGlobe local_574;
  cSGlobe cStack1388;
  cSGlobe cStack1380;
  cSGlobe cStack1372;
  cSGlobe cStack1364;
  cSGlobe cStack1356;
  cSGlobe cStack1348;
  cXyz cStack1340;
  cXyz cStack1328;
  cXyz cStack1316;
  cXyz cStack1304;
  cXyz cStack1292;
  cXyz cStack1280;
  cXyz cStack1268;
  cXyz cStack1256;
  cXyz cStack1244;
  cXyz cStack1232;
  cXyz cStack1220;
  cXyz cStack1208;
  cXyz cStack1196;
  cXyz cStack1184;
  cXyz cStack1172;
  cXyz cStack1160;
  cXyz cStack1148;
  cXyz cStack1136;
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
  cXyz cStack572;
  cXyz cStack560;
  cXyz cStack548;
  cXyz cStack536;
  cXyz cStack524;
  cXyz cStack512;
  cXyz cStack500;
  cXyz cStack488;
  cXyz cStack476;
  cXyz cStack464;
  cXyz cStack452;
  cXyz cStack440;
  cXyz cStack428;
  cXyz cStack416;
  cXyz cStack404;
  cXyz cStack392;
  cXyz cStack380;
  cXyz cStack368;
  cXyz cStack356;
  cXyz cStack344;
  cXyz cStack332;
  cXyz cStack320;
  cXyz cStack308;
  cXyz cStack296;
  cXyz cStack284;
  cXyz cStack272;
  cXyz cStack260;
  cXyz cStack248;
  cXyz cStack236;
  cXyz local_e0;
  cXyz cStack212;
  cXyz local_c8;
  cXyz cStack188;
  cXyz cStack176;
  cXyz cStack164;
  cXyz cStack152;
  cXyz cStack140;
  cXyz cStack128;
  cXyz cStack116;
  cXyz cStack104;
  cXyz cStack92;
  cXyz cStack80;
  undefined4 local_40;
  uint uStack60;
  double local_38;
  undefined auStack8 [8];
  
  uVar14 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (d_ev_camera::init_6307 == '\0') {
    d_ev_camera::DefaultTimer_6306 = 0xffffffff;
    d_ev_camera::init_6307 = '\x01';
  }
  if (d_ev_camera::init_6310 == '\0') {
    d_ev_camera::DefaultBank_6309 = d_ev_camera::_4862;
    d_ev_camera::init_6310 = '\x01';
  }
  pcVar13 = (cXyz *)&this->field_0x378;
  uVar12 = 0;
  if (this->field_0x11c == 0) {
    cVar7 = getEvIntData(this,(int *)&this->field_0x3c8,"Timer");
    if (cVar7 == '\0') {
      @class$6314d_ev_camera_cpp::__class_6314d_ev_camera_cpp
                ((_class_6314d_ev_camera_cpp *)&cStack116);
      @class$6314d_ev_camera_cpp::__class_6314d_ev_camera_cpp
                ((_class_6314d_ev_camera_cpp *)&cStack92);
      uVar12 = 1;
      goto LAB_800b50f0;
    }
    getEvIntData(this,(int *)&this->field_0x3d0,"BrakingPoint",0);
    *(int *)&this->field_0x3d4 = *(int *)&this->field_0x3c8 - *(int *)&this->field_0x3d0;
    getEvIntData(this,(int *)&this->field_0x3d8,"BrakeType",0);
    dVar15 = d_ev_camera::_5609;
    if (*(int *)&this->field_0x3d8 == 1) {
      local_38 = (double)CONCAT44(0x43300000,1 << *(int *)&this->field_0x3d4 + -1 ^ 0x80000000);
      dVar15 = local_38 - d_ev_camera::_5609;
      uStack60 = *(uint *)&this->field_0x3d0 ^ 0x80000000;
      *(float *)&this->field_0x3cc =
           (float)((double)CONCAT44(0x43300000,uStack60) - d_ev_camera::_5609) * (float)dVar15;
      *(float *)&this->field_0x3cc =
           *(float *)&this->field_0x3cc + (d_ev_camera::_5485 * (float)dVar15 - d_ev_camera::_5486);
    }
    else {
      uStack60 = *(int *)&this->field_0x3d0 * *(int *)&this->field_0x3d4 ^ 0x80000000;
      *(float *)&this->field_0x3cc =
           (float)((double)CONCAT44(0x43300000,uStack60) - d_ev_camera::_5609);
      local_38 = (double)CONCAT44(0x43300000,
                                  *(int *)&this->field_0x3d4 * (*(int *)&this->field_0x3d4 + 1) >> 1
                                  ^ 0x80000000);
      *(float *)&this->field_0x3cc = *(float *)&this->field_0x3cc + (float)(local_38 - dVar15);
    }
    local_40 = 0x43300000;
    ::cXyz::cXyz(&cStack296,&this->mEye);
    getEvXyzData(this,(cXyz *)&this->mEvBank,"Eye",&cStack296);
    ::cXyz::cXyz(&cStack308,&this->mCenter);
    getEvXyzData(this,(cXyz *)&this->mEvTimer,"Center",&cStack308);
    getEvFloatData(this,&(this->mEvBasePos).y,"Fovy",this->mFovY);
    ::cXyz::cXyz(&cStack320,&this->mEye);
    getEvXyzData(this,pcVar13,"StartEye",&cStack320);
    ::cXyz::cXyz(&cStack332,&this->mCenter);
    getEvXyzData(this,(cXyz *)&this->field_0x384,"StartCenter",&cStack332);
    getEvFloatData(this,(float *)&this->field_0x390,"StartFovy",this->mFovY);
    dVar15 = (double)cSAngle::Degree(&this->mBank);
    uVar8 = getEvFloatData(this,&(this->mEvBasePos).z,"Bank",(float)dVar15);
    *(undefined *)&this->field_0x3f0 = uVar8;
    dVar15 = (double)cSAngle::Degree(&this->mBank);
    bVar9 = getEvFloatData(this,&this->mEvFovy,"StartBank",(float)dVar15);
    *(byte *)&this->field_0x3f0 = *(byte *)&this->field_0x3f0 | bVar9;
    getEvIntData(this,(int *)&this->field_0x3dc,"TransType",0);
    getEvStringData(this,(char *)&this->field_0x3c0,"RelUseMask","--oo");
    pfVar3 = getEvActor(this,"RelActor");
    *(fopAc_ac_c **)&this->field_0x3b8 = pfVar3;
    dVar15 = (double)getEvFloatData(this,(float *)&this->field_0x3e4,"Cushion",d_ev_camera::_5486);
    iVar4 = *(int *)&this->field_0x3b8;
    if (iVar4 != 0) {
      if (iVar4 == 0) {
        uVar2 = 0xffffffff;
      }
      else {
        uVar2 = *(undefined4 *)(iVar4 + 4);
      }
      *(undefined4 *)&this->field_0x3bc = uVar2;
      if (*(char *)&this->field_0x3c1 == 'r') {
        relationalPos(&cStack344,this,*(fopAc_ac_c **)&this->field_0x3b8,(cXyz *)&this->field_0x384)
        ;
        ::cXyz::operator__(&cStack128,&cStack344);
        if ((this->field_0x80 & 1) != 0) {
          pcVar13->x = -pcVar13->x;
        }
        relationalPos(&cStack356,this,*(fopAc_ac_c **)&this->field_0x3b8,pcVar13);
        ::cXyz::operator__(&cStack140,&cStack356);
        cVar7 = lineBGCheck(this,&cStack128,&cStack140,0x8f);
        dVar15 = extraout_f1;
        if (cVar7 != '\0') {
          pcVar13->x = -pcVar13->x;
        }
      }
      if ((*(char *)&this->field_0x3c0 == 'n') || (*(char *)&this->field_0x3c1 == 'n')) {
        positionOf(&cStack368,this,*(fopAc_ac_c **)&this->field_0x3b8);
        ::cXyz::operator__(&cStack380,&this->mEye,&cStack368);
        cSGlobe::cSGlobe(&cStack1348,&cStack380);
        directionOf((dCamera_c *)(acStack1432 + 2),(fopAc_ac_c *)this);
        cSAngle::operator__(acStack1432,&cStack1348.mAngleY);
        cSAngle::cSAngle(local_58c,acStack1432);
        if (local_58c[0] < cSAngle::_0) {
          if (*(char *)&this->field_0x3c0 == 'n') {
            *(float *)&this->field_0x384 = -*(float *)&this->field_0x384;
          }
          if (*(char *)&this->field_0x3c1 == 'n') {
            pcVar13->x = -pcVar13->x;
          }
        }
        relationalPos(&cStack392,this,*(fopAc_ac_c **)&this->field_0x3b8,(cXyz *)&this->field_0x384)
        ;
        ::cXyz::operator__(&cStack152,&cStack392);
        relationalPos(&cStack404,this,*(fopAc_ac_c **)&this->field_0x3b8,pcVar13);
        ::cXyz::operator__(&cStack164,&cStack404);
        cVar7 = lineBGCheck(this,&cStack152,&cStack164,0x8f);
        if (cVar7 != '\0') {
          pcVar13->x = -pcVar13->x;
        }
        dVar15 = extraout_f1_00;
        cSGlobe::_cSGlobe(&cStack1348);
      }
      if ((*(char *)&this->field_0x3c2 == 'n') || (*(char *)&this->field_0x3c3 == 'n')) {
        positionOf(&cStack416,this,*(fopAc_ac_c **)&this->field_0x3b8);
        ::cXyz::operator__(&cStack428,(cXyz *)&this->mEvBank,&cStack416);
        cSGlobe::cSGlobe(&cStack1356,&cStack428);
        directionOf((dCamera_c *)(acStack1440 + 2),(fopAc_ac_c *)this);
        cSAngle::operator__(acStack1440,&cStack1356.mAngleY);
        cSAngle::cSAngle(local_590,acStack1440);
        if (local_590[0] < cSAngle::_0) {
          if (*(char *)&this->field_0x3c2 == 'n') {
            this->mEvTimer = (int)-(float)this->mEvTimer;
          }
          if (*(char *)&this->field_0x3c3 == 'n') {
            this->mEvBank = -this->mEvBank;
          }
        }
        relationalPos(&cStack440,this,*(fopAc_ac_c **)&this->field_0x3b8,(cXyz *)&this->mEvTimer);
        ::cXyz::operator__(&cStack176,&cStack440);
        relationalPos(&cStack452,this,*(fopAc_ac_c **)&this->field_0x3b8,(cXyz *)&this->mEvBank);
        ::cXyz::operator__(&cStack188,&cStack452);
        cVar7 = lineBGCheck(this,&cStack176,&cStack188,0x8f);
        if (cVar7 != '\0') {
          this->mEvBank = -this->mEvBank;
        }
        dVar15 = extraout_f1_01;
        cSGlobe::_cSGlobe(&cStack1356);
      }
      if (*(char *)&this->field_0x3c2 == 'p') {
        ::cXyz::cXyz(&local_c8,(cXyz *)&this->mEvTimer);
        relationalPos(&cStack464,this,*(fopAc_ac_c **)&this->field_0x3b8,&local_c8);
        ::cXyz::cXyz(&cStack212,&cStack464);
        positionOf(&cStack476,this,this->mpPlayerActor);
        ::cXyz::operator__(&cStack488,&cStack212,&cStack476);
        pcVar10 = &cStack488;
        ::cXyz::cXyz(&cStack500,pcVar10);
        ::cXyz::abs(&cStack500,(int)pcVar10);
        local_c8.x = -local_c8.x;
        relationalPos(&cStack512,this,*(fopAc_ac_c **)&this->field_0x3b8,&local_c8);
        dVar16 = dVar15;
        dVar15 = (double)::cXyz::operator__(&cStack212,&cStack512);
        positionOf(&cStack524,this,this->mpPlayerActor);
        ::cXyz::operator__(&cStack536,&cStack212,&cStack524);
        pcVar10 = &cStack536;
        ::cXyz::cXyz(&cStack548,pcVar10);
        ::cXyz::abs(&cStack548,(int)pcVar10);
        if (dVar16 < dVar15) {
          this->mEvTimer = (int)-(float)this->mEvTimer;
        }
      }
      if (*(char *)&this->field_0x3c3 == 'p') {
        ::cXyz::cXyz(&local_e0,(cXyz *)&this->mEvBank);
        relationalPos(&cStack560,this,*(fopAc_ac_c **)&this->field_0x3b8,&local_e0);
        ::cXyz::cXyz(&cStack236,&cStack560);
        positionOf(&cStack572,this,this->mpPlayerActor);
        ::cXyz::operator__(&cStack584,&cStack236,&cStack572);
        pcVar10 = &cStack584;
        ::cXyz::cXyz(&cStack596,pcVar10);
        ::cXyz::abs(&cStack596,(int)pcVar10);
        local_e0.x = -local_e0.x;
        relationalPos(&cStack608,this,*(fopAc_ac_c **)&this->field_0x3b8,&local_e0);
        dVar16 = (double)::cXyz::operator__(&cStack236,&cStack608);
        positionOf(&cStack620,this,this->mpPlayerActor);
        ::cXyz::operator__(&cStack632,&cStack236,&cStack620);
        pcVar10 = &cStack632;
        ::cXyz::cXyz(&cStack644,pcVar10);
        ::cXyz::abs(&cStack644,(int)pcVar10);
        if (dVar15 < dVar16) {
          this->mEvBank = -this->mEvBank;
        }
      }
      else {
        if (*(char *)&this->field_0x3c3 == 'r') {
          relationalPos(&cStack656,this,*(fopAc_ac_c **)&this->field_0x3b8,(cXyz *)&this->mEvTimer);
          ::cXyz::operator__(&cStack248,&cStack656);
          if ((this->field_0x80 & 1) != 0) {
            this->mEvBank = -this->mEvBank;
          }
          relationalPos(&cStack668,this,*(fopAc_ac_c **)&this->field_0x3b8,(cXyz *)&this->mEvBank);
          ::cXyz::operator__(&cStack260,&cStack668);
          cVar7 = lineBGCheck(this,&cStack248,&cStack260,0x8f);
          if (cVar7 != '\0') {
            this->mEvBank = -this->mEvBank;
          }
        }
      }
    }
    pcVar5 = (cSGlobe *)cSGlobe::Invert((cSGlobe *)&this->field_0x8);
    cSGlobe::operator__((cSGlobe *)&this->field_0x3e8,pcVar5);
    *(float *)&this->field_0x3e0 = d_ev_camera::_4862;
    *(undefined *)&this->field_0x102 = 1;
    *(undefined *)&this->field_0x101 = 1;
    *(undefined *)&this->field_0x100 = 1;
  }
  if (*(int *)&this->field_0x3b8 != 0) {
    local_588 = *(float *)&this->field_0x3bc;
    pfVar3 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,&local_588);
    if (pfVar3 == (fopAc_ac_c *)0x0) {
      @class$6314d_ev_camera_cpp::__class_6314d_ev_camera_cpp
                ((_class_6314d_ev_camera_cpp *)&cStack116);
      @class$6314d_ev_camera_cpp::__class_6314d_ev_camera_cpp
                ((_class_6314d_ev_camera_cpp *)&cStack92);
      uVar12 = 1;
      goto LAB_800b50f0;
    }
  }
  uVar6 = this->field_0x11c;
  uVar11 = *(uint *)&this->field_0x3c8;
  if (uVar6 < uVar11) {
    if (*(int *)&this->field_0x3d8 == 1) {
      if (uVar6 < *(uint *)&this->field_0x3d0) {
        local_38 = (double)CONCAT44(0x43300000,1 << *(int *)&this->field_0x3d4 + -1 ^ 0x80000000);
        *(float *)&this->field_0x3e0 =
             *(float *)&this->field_0x3e0 + (float)(local_38 - d_ev_camera::_5609);
      }
      else {
        local_38 = (double)CONCAT44(0x43300000,1 << (uVar11 - uVar6) + -1 ^ 0x80000000);
        *(float *)&this->field_0x3e0 =
             *(float *)&this->field_0x3e0 + (float)(local_38 - d_ev_camera::_5609);
      }
    }
    else {
      if (uVar6 < *(uint *)&this->field_0x3d0) {
        local_38 = (double)CONCAT44(0x43300000,*(uint *)&this->field_0x3d4 ^ 0x80000000);
        *(float *)&this->field_0x3e0 =
             *(float *)&this->field_0x3e0 + (float)(local_38 - d_ev_camera::_5609);
      }
      else {
        local_38 = (double)CONCAT44(0x43300000,uVar11 - uVar6);
        *(float *)&this->field_0x3e0 =
             *(float *)&this->field_0x3e0 + (float)(local_38 - d_ev_camera::_5488);
      }
    }
    fVar1 = *(float *)&this->field_0x3e0 / *(float *)&this->field_0x3cc;
  }
  else {
    uVar12 = 1;
    fVar1 = d_ev_camera::_5486;
  }
  dVar15 = (double)fVar1;
  pfVar3 = *(fopAc_ac_c **)&this->field_0x3b8;
  if (pfVar3 == (fopAc_ac_c *)0x0) {
    ::cXyz::operator__(&cStack80,(cXyz *)&this->field_0x384);
    ::cXyz::operator__(&cStack92,pcVar13);
    ::cXyz::operator__(&cStack104,(cXyz *)&this->mEvTimer);
    ::cXyz::operator__(&cStack116,(cXyz *)&this->mEvBank);
  }
  else {
    cVar7 = *(char *)&this->field_0x3c0;
    if (cVar7 == 't') {
      attentionPos(&cStack680,this,pfVar3);
      ::cXyz::operator__(&cStack692,&cStack680,(cXyz *)&this->field_0x384);
      ::cXyz::operator__(&cStack80,&cStack692);
    }
    else {
      if (cVar7 == 'c') {
        cSGlobe::cSGlobe(&cStack1364,(cXyz *)&this->field_0x384);
        cSAngle::operator__(acStack1444,(cSAngle *)&this->field_0x3ee);
        cSGlobe::U(&cStack1364,acStack1444);
        attentionPos(&cStack704,this,*(fopAc_ac_c **)&this->field_0x3b8);
        cSGlobe::Xyz(&cStack716,&cStack1364);
        ::cXyz::operator__(&cStack728,&cStack704,&cStack716);
        ::cXyz::operator__(&cStack80,&cStack728);
        cSGlobe::_cSGlobe(&cStack1364);
      }
      else {
        if (cVar7 == '-') {
          ::cXyz::operator__(&cStack80,(cXyz *)&this->field_0x384);
        }
        else {
          relationalPos(&cStack740,this,pfVar3,(cXyz *)&this->field_0x384);
          ::cXyz::operator__(&cStack80,&cStack740);
        }
      }
    }
    cVar7 = *(char *)&this->field_0x3c1;
    if (cVar7 == 't') {
      attentionPos(&cStack752,this,*(fopAc_ac_c **)&this->field_0x3b8);
      ::cXyz::operator__(&cStack764,&cStack752,pcVar13);
      ::cXyz::operator__(&cStack92,&cStack764);
    }
    else {
      if (cVar7 == 'c') {
        cSGlobe::cSGlobe(&cStack1372,pcVar13);
        cSAngle::operator__(acStack1448,(cSAngle *)&this->field_0x3ee);
        cSGlobe::U(&cStack1372,acStack1448);
        attentionPos(&cStack776,this,*(fopAc_ac_c **)&this->field_0x3b8);
        cSGlobe::Xyz(&cStack788,&cStack1372);
        ::cXyz::operator__(&cStack800,&cStack776,&cStack788);
        ::cXyz::operator__(&cStack92,&cStack800);
        cSGlobe::_cSGlobe(&cStack1372);
      }
      else {
        if (cVar7 == '-') {
          ::cXyz::operator__(&cStack92,pcVar13);
        }
        else {
          relationalPos(&cStack812,this,*(fopAc_ac_c **)&this->field_0x3b8,pcVar13);
          ::cXyz::operator__(&cStack92,&cStack812);
        }
      }
    }
    cVar7 = *(char *)&this->field_0x3c2;
    if (cVar7 == 't') {
      attentionPos(&cStack824,this,*(fopAc_ac_c **)&this->field_0x3b8);
      ::cXyz::operator__(&cStack836,&cStack824,(cXyz *)&this->mEvTimer);
      ::cXyz::operator__(&cStack104,&cStack836);
    }
    else {
      if (cVar7 == 'c') {
        cSGlobe::cSGlobe(&cStack1380,(cXyz *)&this->mEvTimer);
        cSAngle::operator__(acStack1452,(cSAngle *)&this->field_0x3ee);
        cSGlobe::U(&cStack1380,acStack1452);
        attentionPos(&cStack848,this,*(fopAc_ac_c **)&this->field_0x3b8);
        cSGlobe::Xyz(&cStack860,&cStack1380);
        ::cXyz::operator__(&cStack872,&cStack848,&cStack860);
        ::cXyz::operator__(&cStack104,&cStack872);
        cSGlobe::_cSGlobe(&cStack1380);
      }
      else {
        if (cVar7 == '-') {
          if (*(int *)&this->field_0x3dc == 2) {
            directionOf((dCamera_c *)(acStack1460 + 2),(fopAc_ac_c *)this);
            dCamMath::xyzRotateY(&cStack896,(cSAngle)((short)this + 0x3a4));
            ::cXyz::operator__(&cStack104,&cStack896);
          }
          else {
            ::cXyz::operator__(&cStack104,(cXyz *)&this->mEvTimer);
          }
        }
        else {
          relationalPos(&cStack884,this,*(fopAc_ac_c **)&this->field_0x3b8,(cXyz *)&this->mEvTimer);
          ::cXyz::operator__(&cStack104,&cStack884);
        }
      }
    }
    cVar7 = *(char *)&this->field_0x3c3;
    if (cVar7 == 't') {
      attentionPos(&cStack908,this,*(fopAc_ac_c **)&this->field_0x3b8);
      ::cXyz::operator__(&cStack920,&cStack908,(cXyz *)&this->mEvBank);
      ::cXyz::operator__(&cStack116,&cStack920);
    }
    else {
      if (cVar7 == 'c') {
        cSGlobe::cSGlobe(&cStack1388,(cXyz *)&this->mEvBank);
        cSAngle::operator__(acStack1460,(cSAngle *)&this->field_0x3ee);
        cSGlobe::U(&cStack1388,acStack1460);
        attentionPos(&cStack932,this,*(fopAc_ac_c **)&this->field_0x3b8);
        cSGlobe::Xyz(&cStack944,&cStack1388);
        ::cXyz::operator__(&cStack956,&cStack932,&cStack944);
        ::cXyz::operator__(&cStack116,&cStack956);
        cSGlobe::_cSGlobe(&cStack1388);
      }
      else {
        if (cVar7 == '-') {
          if (*(int *)&this->field_0x3dc == 2) {
            directionOf((dCamera_c *)(acStack1468 + 2),(fopAc_ac_c *)this);
            dCamMath::xyzRotateY(&cStack980,(cSAngle)((short)this + 0x398));
            ::cXyz::operator__(&cStack116,&cStack980);
          }
          else {
            ::cXyz::operator__(&cStack116,(cXyz *)&this->mEvBank);
          }
        }
        else {
          relationalPos(&cStack968,this,*(fopAc_ac_c **)&this->field_0x3b8,(cXyz *)&this->mEvBank);
          ::cXyz::operator__(&cStack116,&cStack968);
        }
      }
    }
  }
  if (*(int *)&this->field_0x3dc == 1) {
    ::cXyz::operator__(&cStack992,&cStack104,&cStack80);
    ::cXyz::operator_(&cStack1004,&cStack992,(float)dVar15);
    ::cXyz::operator__(&cStack1016,&cStack80,&cStack1004);
    ::cXyz::operator__(&cStack272,&cStack1016);
    ::cXyz::operator__(&cStack1028,&cStack272,&this->field_0x44);
    ::cXyz::operator_(&cStack1040,&cStack1028,*(float *)&this->field_0x3e4);
    mtx::PSVECAdd(&this->field_0x44,&cStack1040,&this->field_0x44);
    ::cXyz::operator__(&cStack1052,&cStack92,&cStack80);
    cSGlobe::cSGlobe(&local_574,&cStack1052);
    ::cXyz::operator__(&cStack1064,&cStack116,&cStack104);
    cSGlobe::cSGlobe(&local_57c,&cStack1064);
    cSAngle::operator__(acStack1468,&local_57c.mAngleX);
    cSAngle::operator_(acStack1472,(float)dVar15);
    cSAngle::operator__(acStack1476,&local_574.mAngleX);
    cSAngle::operator__(acStack1480,&local_57c.mAngleY);
    cSAngle::operator_(acStack1484,(float)dVar15);
    cSAngle::operator__(acStack1488,&local_574.mAngleY);
    cSGlobe::cSGlobe(&cStack1412,
                     local_574.mDistance +
                     (float)(dVar15 * (double)(local_57c.mDistance - local_574.mDistance)),
                     acStack1476,acStack1488);
    cSGlobe::Xyz(&cStack1076,&cStack1412);
    ::cXyz::operator__(&cStack1088,&this->field_0x44,&cStack1076);
    ::cXyz::operator__(&cStack284,&cStack1088);
    ::cXyz::operator__(&cStack1100,&cStack284,&this->field_0x50);
    ::cXyz::operator_(&cStack1112,&cStack1100,*(float *)&this->field_0x3e4);
    mtx::PSVECAdd(&this->field_0x50,&cStack1112,&this->field_0x50);
    cSGlobe::_cSGlobe(&cStack1412);
    cSGlobe::_cSGlobe(&local_57c);
    cSGlobe::_cSGlobe(&local_574);
  }
  else {
    if (*(int *)&this->field_0x3dc == 2) {
      ::cXyz::operator_(&cStack1124,&cStack104,(float)dVar15);
      ::cXyz::operator__(&cStack1136,&cStack80,&cStack1124);
      ::cXyz::operator__(&cStack272,&cStack1136);
      ::cXyz::operator__(&cStack1148,&cStack272,&this->field_0x44);
      ::cXyz::operator_(&cStack1160,&cStack1148,*(float *)&this->field_0x3e4);
      mtx::PSVECAdd(&this->field_0x44,&cStack1160,&this->field_0x44);
      ::cXyz::operator_(&cStack1172,&cStack116,(float)dVar15);
      ::cXyz::operator__(&cStack1184,&cStack92,&cStack1172);
      ::cXyz::operator__(&cStack284,&cStack1184);
      ::cXyz::operator__(&cStack1196,&cStack284,&this->field_0x50);
      ::cXyz::operator_(&cStack1208,&cStack1196,*(float *)&this->field_0x3e4);
      mtx::PSVECAdd(&this->field_0x50,&cStack1208,&this->field_0x50);
    }
    else {
      ::cXyz::operator__(&cStack1220,&cStack104,&cStack80);
      ::cXyz::operator_(&cStack1232,&cStack1220,(float)dVar15);
      ::cXyz::operator__(&cStack1244,&cStack80,&cStack1232);
      ::cXyz::operator__(&cStack272,&cStack1244);
      ::cXyz::operator__(&cStack1256,&cStack272,&this->field_0x44);
      ::cXyz::operator_(&cStack1268,&cStack1256,*(float *)&this->field_0x3e4);
      mtx::PSVECAdd(&this->field_0x44,&cStack1268,&this->field_0x44);
      ::cXyz::operator__(&cStack1280,&cStack116,&cStack92);
      ::cXyz::operator_(&cStack1292,&cStack1280,(float)dVar15);
      ::cXyz::operator__(&cStack1304,&cStack92,&cStack1292);
      ::cXyz::operator__(&cStack284,&cStack1304);
      ::cXyz::operator__(&cStack1316,&cStack284,&this->field_0x50);
      ::cXyz::operator_(&cStack1328,&cStack1316,*(float *)&this->field_0x3e4);
      mtx::PSVECAdd(&this->field_0x50,&cStack1328,&this->field_0x50);
    }
  }
  this->field_0x60 =
       this->field_0x60 +
       *(float *)&this->field_0x3e4 *
       ((*(float *)&this->field_0x390 +
        (float)(dVar15 * (double)((this->mEvBasePos).y - *(float *)&this->field_0x390))) -
       this->field_0x60);
  if (*(char *)&this->field_0x3f0 != '\0') {
    iVar4 = (int)(d_ev_camera::_4865 *
                 (this->mEvFovy + (float)(dVar15 * (double)((this->mEvBasePos).z - this->mEvFovy))))
    ;
    local_38 = (double)(longlong)iVar4;
    SComponent::operator__(auStack1492,iVar4,&this->field_0x5c);
    cSAngle::operator_(acStack1496,*(float *)&this->field_0x3e4);
    cSAngle::operator___((cSAngle *)&this->field_0x5c,acStack1496);
    this->mEventFlags = this->mEventFlags | 0x400;
  }
  ::cXyz::operator__(&cStack1340,&this->field_0x50,&this->field_0x44);
  cSGlobe::Val(&this->field_0x3c,&cStack1340);
  @class$6314d_ev_camera_cpp::__class_6314d_ev_camera_cpp((_class_6314d_ev_camera_cpp *)&cStack116);
  @class$6314d_ev_camera_cpp::__class_6314d_ev_camera_cpp((_class_6314d_ev_camera_cpp *)&cStack92);
LAB_800b50f0:
  __psq_l0(auStack8,uVar14);
  __psq_l1(auStack8,uVar14);
  return uVar12;
}


namespace dCamera_c {

/* __thiscall @class$6314d_ev_camera_cpp::~@class$6314d_ev_camera_cpp(void) */

void __thiscall
@class$6314d_ev_camera_cpp::__class_6314d_ev_camera_cpp(_class_6314d_ev_camera_cpp *this)

{
  short in_r4;
  
  if ((this != (_class_6314d_ev_camera_cpp *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}

}

/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x800b6414) */
/* __thiscall dCamera_c::uniformAcceleEvCamera(void) */

undefined4 __thiscall dCamera_c::uniformAcceleEvCamera(dCamera_c *this)

{
  float fVar1;
  undefined4 uVar2;
  char cVar6;
  undefined uVar7;
  byte bVar8;
  fopAc_ac_c *pfVar3;
  int iVar4;
  cSGlobe *pcVar5;
  cXyz *pcVar9;
  uint uVar10;
  undefined4 uVar11;
  cXyz *pcVar12;
  undefined4 uVar13;
  double dVar14;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  double dVar15;
  undefined8 in_f31;
  cSAngle acStack1496 [2];
  undefined auStack1492 [4];
  cSAngle acStack1488 [2];
  cSAngle acStack1484 [2];
  cSAngle acStack1480 [2];
  cSAngle acStack1476 [2];
  cSAngle acStack1472 [2];
  cSAngle acStack1468 [4];
  cSAngle acStack1460 [4];
  cSAngle acStack1452 [2];
  cSAngle acStack1448 [2];
  cSAngle acStack1444 [2];
  cSAngle acStack1440 [4];
  cSAngle acStack1432 [4];
  cSAngle local_590 [2];
  cSAngle local_58c [2];
  float local_588;
  cSGlobe cStack1412;
  cSGlobe local_57c;
  cSGlobe local_574;
  cSGlobe cStack1388;
  cSGlobe cStack1380;
  cSGlobe cStack1372;
  cSGlobe cStack1364;
  cSGlobe cStack1356;
  cSGlobe cStack1348;
  cXyz cStack1340;
  cXyz cStack1328;
  cXyz cStack1316;
  cXyz cStack1304;
  cXyz cStack1292;
  cXyz cStack1280;
  cXyz cStack1268;
  cXyz cStack1256;
  cXyz cStack1244;
  cXyz cStack1232;
  cXyz cStack1220;
  cXyz cStack1208;
  cXyz cStack1196;
  cXyz cStack1184;
  cXyz cStack1172;
  cXyz cStack1160;
  cXyz cStack1148;
  cXyz cStack1136;
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
  cXyz cStack572;
  cXyz cStack560;
  cXyz cStack548;
  cXyz cStack536;
  cXyz cStack524;
  cXyz cStack512;
  cXyz cStack500;
  cXyz cStack488;
  cXyz cStack476;
  cXyz cStack464;
  cXyz cStack452;
  cXyz cStack440;
  cXyz cStack428;
  cXyz cStack416;
  cXyz cStack404;
  cXyz cStack392;
  cXyz cStack380;
  cXyz cStack368;
  cXyz cStack356;
  cXyz cStack344;
  cXyz cStack332;
  cXyz cStack320;
  cXyz cStack308;
  cXyz cStack296;
  cXyz cStack284;
  cXyz cStack272;
  cXyz cStack260;
  cXyz cStack248;
  cXyz cStack236;
  cXyz local_e0;
  cXyz cStack212;
  cXyz local_c8;
  cXyz cStack188;
  cXyz cStack176;
  cXyz cStack164;
  cXyz cStack152;
  cXyz cStack140;
  cXyz cStack128;
  cXyz cStack116;
  cXyz cStack104;
  cXyz cStack92;
  cXyz cStack80;
  undefined4 local_40;
  uint uStack60;
  double local_38;
  undefined auStack8 [8];
  
  uVar13 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (d_ev_camera::init_6986 == '\0') {
    d_ev_camera::DefaultTimer_6985 = 0xffffffff;
    d_ev_camera::init_6986 = '\x01';
  }
  if (d_ev_camera::init_6989 == '\0') {
    d_ev_camera::DefaultBank_6988 = d_ev_camera::_4862;
    d_ev_camera::init_6989 = '\x01';
  }
  pcVar12 = (cXyz *)&this->field_0x378;
  uVar11 = 0;
  if (this->field_0x11c == 0) {
    cVar6 = getEvIntData(this,(int *)&this->field_0x3c8,"Timer");
    if (cVar6 == '\0') {
      @class$6993d_ev_camera_cpp::__class_6993d_ev_camera_cpp
                ((_class_6993d_ev_camera_cpp *)&cStack116);
      @class$6993d_ev_camera_cpp::__class_6993d_ev_camera_cpp
                ((_class_6993d_ev_camera_cpp *)&cStack92);
      uVar11 = 1;
      goto LAB_800b6414;
    }
    getEvIntData(this,(int *)&this->field_0x3d4,"AcceleTimer",*(int *)&this->field_0x3c8);
    getEvIntData(this,(int *)&this->field_0x3d8,"AcceleType",0);
    *(int *)&this->field_0x3d0 = *(int *)&this->field_0x3c8 - *(int *)&this->field_0x3d4;
    dVar14 = d_ev_camera::_5609;
    if (*(int *)&this->field_0x3d8 == 1) {
      local_38 = (double)CONCAT44(0x43300000,1 << *(int *)&this->field_0x3d4 + -1 ^ 0x80000000);
      dVar14 = local_38 - d_ev_camera::_5609;
      uStack60 = *(uint *)&this->field_0x3d0 ^ 0x80000000;
      *(float *)&this->field_0x3cc =
           (float)((double)CONCAT44(0x43300000,uStack60) - d_ev_camera::_5609) * (float)dVar14;
      *(float *)&this->field_0x3cc =
           *(float *)&this->field_0x3cc + (d_ev_camera::_5485 * (float)dVar14 - d_ev_camera::_5486);
    }
    else {
      uStack60 = *(int *)&this->field_0x3d0 * *(int *)&this->field_0x3d4 ^ 0x80000000;
      *(float *)&this->field_0x3cc =
           (float)((double)CONCAT44(0x43300000,uStack60) - d_ev_camera::_5609);
      local_38 = (double)CONCAT44(0x43300000,
                                  *(int *)&this->field_0x3d4 * (*(int *)&this->field_0x3d4 + 1) >> 1
                                  ^ 0x80000000);
      *(float *)&this->field_0x3cc = *(float *)&this->field_0x3cc + (float)(local_38 - dVar14);
    }
    local_40 = 0x43300000;
    ::cXyz::cXyz(&cStack296,&this->mEye);
    getEvXyzData(this,(cXyz *)&this->mEvBank,"Eye",&cStack296);
    ::cXyz::cXyz(&cStack308,&this->mCenter);
    getEvXyzData(this,(cXyz *)&this->mEvTimer,"Center",&cStack308);
    getEvFloatData(this,&(this->mEvBasePos).y,"Fovy",this->mFovY);
    ::cXyz::cXyz(&cStack320,&this->mEye);
    getEvXyzData(this,pcVar12,"StartEye",&cStack320);
    ::cXyz::cXyz(&cStack332,&this->mCenter);
    getEvXyzData(this,(cXyz *)&this->field_0x384,"StartCenter",&cStack332);
    getEvFloatData(this,(float *)&this->field_0x390,"StartFovy",this->mFovY);
    dVar14 = (double)cSAngle::Degree(&this->mBank);
    uVar7 = getEvFloatData(this,&(this->mEvBasePos).z,"Bank",(float)dVar14);
    *(undefined *)&this->field_0x3f0 = uVar7;
    dVar14 = (double)cSAngle::Degree(&this->mBank);
    bVar8 = getEvFloatData(this,&this->mEvFovy,"StartBank",(float)dVar14);
    *(byte *)&this->field_0x3f0 = *(byte *)&this->field_0x3f0 | bVar8;
    getEvIntData(this,(int *)&this->field_0x3dc,"TransType",0);
    getEvStringData(this,(char *)&this->field_0x3c0,"RelUseMask","--oo");
    pfVar3 = getEvActor(this,"RelActor");
    *(fopAc_ac_c **)&this->field_0x3b8 = pfVar3;
    dVar14 = (double)getEvFloatData(this,(float *)&this->field_0x3e4,"Cushion",d_ev_camera::_5486);
    iVar4 = *(int *)&this->field_0x3b8;
    if (iVar4 != 0) {
      if (iVar4 == 0) {
        uVar2 = 0xffffffff;
      }
      else {
        uVar2 = *(undefined4 *)(iVar4 + 4);
      }
      *(undefined4 *)&this->field_0x3bc = uVar2;
      if (*(char *)&this->field_0x3c1 == 'r') {
        relationalPos(&cStack344,this,*(fopAc_ac_c **)&this->field_0x3b8,(cXyz *)&this->field_0x384)
        ;
        ::cXyz::operator__(&cStack128,&cStack344);
        if ((this->field_0x80 & 1) != 0) {
          pcVar12->x = -pcVar12->x;
        }
        relationalPos(&cStack356,this,*(fopAc_ac_c **)&this->field_0x3b8,pcVar12);
        ::cXyz::operator__(&cStack140,&cStack356);
        cVar6 = lineBGCheck(this,&cStack128,&cStack140,0x8f);
        dVar14 = extraout_f1;
        if (cVar6 != '\0') {
          pcVar12->x = -pcVar12->x;
        }
      }
      if ((*(char *)&this->field_0x3c0 == 'n') || (*(char *)&this->field_0x3c1 == 'n')) {
        positionOf(&cStack368,this,*(fopAc_ac_c **)&this->field_0x3b8);
        ::cXyz::operator__(&cStack380,&this->mEye,&cStack368);
        cSGlobe::cSGlobe(&cStack1348,&cStack380);
        directionOf((dCamera_c *)(acStack1432 + 2),(fopAc_ac_c *)this);
        cSAngle::operator__(acStack1432,&cStack1348.mAngleY);
        cSAngle::cSAngle(local_58c,acStack1432);
        if (local_58c[0] < cSAngle::_0) {
          if (*(char *)&this->field_0x3c0 == 'n') {
            *(float *)&this->field_0x384 = -*(float *)&this->field_0x384;
          }
          if (*(char *)&this->field_0x3c1 == 'n') {
            pcVar12->x = -pcVar12->x;
          }
        }
        relationalPos(&cStack392,this,*(fopAc_ac_c **)&this->field_0x3b8,(cXyz *)&this->field_0x384)
        ;
        ::cXyz::operator__(&cStack152,&cStack392);
        relationalPos(&cStack404,this,*(fopAc_ac_c **)&this->field_0x3b8,pcVar12);
        ::cXyz::operator__(&cStack164,&cStack404);
        cVar6 = lineBGCheck(this,&cStack152,&cStack164,0x8f);
        if (cVar6 != '\0') {
          pcVar12->x = -pcVar12->x;
        }
        dVar14 = extraout_f1_00;
        cSGlobe::_cSGlobe(&cStack1348);
      }
      if ((*(char *)&this->field_0x3c2 == 'n') || (*(char *)&this->field_0x3c3 == 'n')) {
        positionOf(&cStack416,this,*(fopAc_ac_c **)&this->field_0x3b8);
        ::cXyz::operator__(&cStack428,(cXyz *)&this->mEvBank,&cStack416);
        cSGlobe::cSGlobe(&cStack1356,&cStack428);
        directionOf((dCamera_c *)(acStack1440 + 2),(fopAc_ac_c *)this);
        cSAngle::operator__(acStack1440,&cStack1356.mAngleY);
        cSAngle::cSAngle(local_590,acStack1440);
        if (local_590[0] < cSAngle::_0) {
          if (*(char *)&this->field_0x3c2 == 'n') {
            this->mEvTimer = (int)-(float)this->mEvTimer;
          }
          if (*(char *)&this->field_0x3c3 == 'n') {
            this->mEvBank = -this->mEvBank;
          }
        }
        relationalPos(&cStack440,this,*(fopAc_ac_c **)&this->field_0x3b8,(cXyz *)&this->mEvTimer);
        ::cXyz::operator__(&cStack176,&cStack440);
        relationalPos(&cStack452,this,*(fopAc_ac_c **)&this->field_0x3b8,(cXyz *)&this->mEvBank);
        ::cXyz::operator__(&cStack188,&cStack452);
        cVar6 = lineBGCheck(this,&cStack176,&cStack188,0x8f);
        if (cVar6 != '\0') {
          this->mEvBank = -this->mEvBank;
        }
        dVar14 = extraout_f1_01;
        cSGlobe::_cSGlobe(&cStack1356);
      }
      if (*(char *)&this->field_0x3c2 == 'p') {
        ::cXyz::cXyz(&local_c8,(cXyz *)&this->mEvTimer);
        relationalPos(&cStack464,this,*(fopAc_ac_c **)&this->field_0x3b8,&local_c8);
        ::cXyz::cXyz(&cStack212,&cStack464);
        positionOf(&cStack476,this,this->mpPlayerActor);
        ::cXyz::operator__(&cStack488,&cStack212,&cStack476);
        pcVar9 = &cStack488;
        ::cXyz::cXyz(&cStack500,pcVar9);
        ::cXyz::abs(&cStack500,(int)pcVar9);
        local_c8.x = -local_c8.x;
        relationalPos(&cStack512,this,*(fopAc_ac_c **)&this->field_0x3b8,&local_c8);
        dVar15 = dVar14;
        dVar14 = (double)::cXyz::operator__(&cStack212,&cStack512);
        positionOf(&cStack524,this,this->mpPlayerActor);
        ::cXyz::operator__(&cStack536,&cStack212,&cStack524);
        pcVar9 = &cStack536;
        ::cXyz::cXyz(&cStack548,pcVar9);
        ::cXyz::abs(&cStack548,(int)pcVar9);
        if (dVar15 < dVar14) {
          this->mEvTimer = (int)-(float)this->mEvTimer;
        }
      }
      if (*(char *)&this->field_0x3c3 == 'p') {
        ::cXyz::cXyz(&local_e0,(cXyz *)&this->mEvBank);
        relationalPos(&cStack560,this,*(fopAc_ac_c **)&this->field_0x3b8,&local_e0);
        ::cXyz::cXyz(&cStack236,&cStack560);
        positionOf(&cStack572,this,this->mpPlayerActor);
        ::cXyz::operator__(&cStack584,&cStack236,&cStack572);
        pcVar9 = &cStack584;
        ::cXyz::cXyz(&cStack596,pcVar9);
        ::cXyz::abs(&cStack596,(int)pcVar9);
        local_e0.x = -local_e0.x;
        relationalPos(&cStack608,this,*(fopAc_ac_c **)&this->field_0x3b8,&local_e0);
        dVar15 = (double)::cXyz::operator__(&cStack236,&cStack608);
        positionOf(&cStack620,this,this->mpPlayerActor);
        ::cXyz::operator__(&cStack632,&cStack236,&cStack620);
        pcVar9 = &cStack632;
        ::cXyz::cXyz(&cStack644,pcVar9);
        ::cXyz::abs(&cStack644,(int)pcVar9);
        if (dVar14 < dVar15) {
          this->mEvBank = -this->mEvBank;
        }
      }
      else {
        if (*(char *)&this->field_0x3c3 == 'r') {
          relationalPos(&cStack656,this,*(fopAc_ac_c **)&this->field_0x3b8,(cXyz *)&this->mEvTimer);
          ::cXyz::operator__(&cStack248,&cStack656);
          if ((this->field_0x80 & 1) != 0) {
            this->mEvBank = -this->mEvBank;
          }
          relationalPos(&cStack668,this,*(fopAc_ac_c **)&this->field_0x3b8,(cXyz *)&this->mEvBank);
          ::cXyz::operator__(&cStack260,&cStack668);
          cVar6 = lineBGCheck(this,&cStack248,&cStack260,0x8f);
          if (cVar6 != '\0') {
            this->mEvBank = -this->mEvBank;
          }
        }
      }
    }
    pcVar5 = (cSGlobe *)cSGlobe::Invert((cSGlobe *)&this->field_0x8);
    cSGlobe::operator__((cSGlobe *)&this->field_0x3e8,pcVar5);
    *(float *)&this->field_0x3e0 = d_ev_camera::_4862;
    *(undefined *)&this->field_0x102 = 1;
    *(undefined *)&this->field_0x101 = 1;
    *(undefined *)&this->field_0x100 = 1;
  }
  if (*(int *)&this->field_0x3b8 != 0) {
    local_588 = *(float *)&this->field_0x3bc;
    pfVar3 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,&local_588);
    if (pfVar3 == (fopAc_ac_c *)0x0) {
      @class$6993d_ev_camera_cpp::__class_6993d_ev_camera_cpp
                ((_class_6993d_ev_camera_cpp *)&cStack116);
      @class$6993d_ev_camera_cpp::__class_6993d_ev_camera_cpp
                ((_class_6993d_ev_camera_cpp *)&cStack92);
      uVar11 = 1;
      goto LAB_800b6414;
    }
  }
  uVar10 = this->field_0x11c;
  if (uVar10 < *(uint *)&this->field_0x3c8) {
    if (*(int *)&this->field_0x3d8 == 1) {
      if (uVar10 < *(uint *)&this->field_0x3d4) {
        local_38 = (double)CONCAT44(0x43300000,1 << uVar10 - 1 ^ 0x80000000);
        *(float *)&this->field_0x3e0 =
             *(float *)&this->field_0x3e0 + (float)(local_38 - d_ev_camera::_5609);
      }
      else {
        local_38 = (double)CONCAT44(0x43300000,1 << *(uint *)&this->field_0x3d4 - 1 ^ 0x80000000);
        *(float *)&this->field_0x3e0 =
             *(float *)&this->field_0x3e0 + (float)(local_38 - d_ev_camera::_5609);
      }
    }
    else {
      if (uVar10 < *(uint *)&this->field_0x3d4) {
        local_38 = (double)CONCAT44(0x43300000,uVar10);
        *(float *)&this->field_0x3e0 =
             *(float *)&this->field_0x3e0 + (float)(local_38 - d_ev_camera::_5488);
      }
      else {
        local_38 = (double)CONCAT44(0x43300000,*(uint *)&this->field_0x3d4 ^ 0x80000000);
        *(float *)&this->field_0x3e0 =
             *(float *)&this->field_0x3e0 + (float)(local_38 - d_ev_camera::_5609);
      }
    }
    fVar1 = *(float *)&this->field_0x3e0 / *(float *)&this->field_0x3cc;
  }
  else {
    uVar11 = 1;
    fVar1 = d_ev_camera::_5486;
  }
  dVar14 = (double)fVar1;
  pfVar3 = *(fopAc_ac_c **)&this->field_0x3b8;
  if (pfVar3 == (fopAc_ac_c *)0x0) {
    ::cXyz::operator__(&cStack80,(cXyz *)&this->field_0x384);
    ::cXyz::operator__(&cStack92,pcVar12);
    ::cXyz::operator__(&cStack104,(cXyz *)&this->mEvTimer);
    ::cXyz::operator__(&cStack116,(cXyz *)&this->mEvBank);
  }
  else {
    cVar6 = *(char *)&this->field_0x3c0;
    if (cVar6 == 't') {
      attentionPos(&cStack680,this,pfVar3);
      ::cXyz::operator__(&cStack692,&cStack680,(cXyz *)&this->field_0x384);
      ::cXyz::operator__(&cStack80,&cStack692);
    }
    else {
      if (cVar6 == 'c') {
        cSGlobe::cSGlobe(&cStack1364,(cXyz *)&this->field_0x384);
        cSAngle::operator__(acStack1444,(cSAngle *)&this->field_0x3ee);
        cSGlobe::U(&cStack1364,acStack1444);
        attentionPos(&cStack704,this,*(fopAc_ac_c **)&this->field_0x3b8);
        cSGlobe::Xyz(&cStack716,&cStack1364);
        ::cXyz::operator__(&cStack728,&cStack704,&cStack716);
        ::cXyz::operator__(&cStack80,&cStack728);
        cSGlobe::_cSGlobe(&cStack1364);
      }
      else {
        if (cVar6 == '-') {
          ::cXyz::operator__(&cStack80,(cXyz *)&this->field_0x384);
        }
        else {
          relationalPos(&cStack740,this,pfVar3,(cXyz *)&this->field_0x384);
          ::cXyz::operator__(&cStack80,&cStack740);
        }
      }
    }
    cVar6 = *(char *)&this->field_0x3c1;
    if (cVar6 == 't') {
      attentionPos(&cStack752,this,*(fopAc_ac_c **)&this->field_0x3b8);
      ::cXyz::operator__(&cStack764,&cStack752,pcVar12);
      ::cXyz::operator__(&cStack92,&cStack764);
    }
    else {
      if (cVar6 == 'c') {
        cSGlobe::cSGlobe(&cStack1372,pcVar12);
        cSAngle::operator__(acStack1448,(cSAngle *)&this->field_0x3ee);
        cSGlobe::U(&cStack1372,acStack1448);
        attentionPos(&cStack776,this,*(fopAc_ac_c **)&this->field_0x3b8);
        cSGlobe::Xyz(&cStack788,&cStack1372);
        ::cXyz::operator__(&cStack800,&cStack776,&cStack788);
        ::cXyz::operator__(&cStack92,&cStack800);
        cSGlobe::_cSGlobe(&cStack1372);
      }
      else {
        if (cVar6 == '-') {
          ::cXyz::operator__(&cStack92,pcVar12);
        }
        else {
          relationalPos(&cStack812,this,*(fopAc_ac_c **)&this->field_0x3b8,pcVar12);
          ::cXyz::operator__(&cStack92,&cStack812);
        }
      }
    }
    cVar6 = *(char *)&this->field_0x3c2;
    if (cVar6 == 't') {
      attentionPos(&cStack824,this,*(fopAc_ac_c **)&this->field_0x3b8);
      ::cXyz::operator__(&cStack836,&cStack824,(cXyz *)&this->mEvTimer);
      ::cXyz::operator__(&cStack104,&cStack836);
    }
    else {
      if (cVar6 == 'c') {
        cSGlobe::cSGlobe(&cStack1380,(cXyz *)&this->mEvTimer);
        cSAngle::operator__(acStack1452,(cSAngle *)&this->field_0x3ee);
        cSGlobe::U(&cStack1380,acStack1452);
        attentionPos(&cStack848,this,*(fopAc_ac_c **)&this->field_0x3b8);
        cSGlobe::Xyz(&cStack860,&cStack1380);
        ::cXyz::operator__(&cStack872,&cStack848,&cStack860);
        ::cXyz::operator__(&cStack104,&cStack872);
        cSGlobe::_cSGlobe(&cStack1380);
      }
      else {
        if (cVar6 == '-') {
          if (*(int *)&this->field_0x3dc == 2) {
            directionOf((dCamera_c *)(acStack1460 + 2),(fopAc_ac_c *)this);
            dCamMath::xyzRotateY(&cStack896,(cSAngle)((short)this + 0x3a4));
            ::cXyz::operator__(&cStack104,&cStack896);
          }
          else {
            ::cXyz::operator__(&cStack104,(cXyz *)&this->mEvTimer);
          }
        }
        else {
          relationalPos(&cStack884,this,*(fopAc_ac_c **)&this->field_0x3b8,(cXyz *)&this->mEvTimer);
          ::cXyz::operator__(&cStack104,&cStack884);
        }
      }
    }
    cVar6 = *(char *)&this->field_0x3c3;
    if (cVar6 == 't') {
      attentionPos(&cStack908,this,*(fopAc_ac_c **)&this->field_0x3b8);
      ::cXyz::operator__(&cStack920,&cStack908,(cXyz *)&this->mEvBank);
      ::cXyz::operator__(&cStack116,&cStack920);
    }
    else {
      if (cVar6 == 'c') {
        cSGlobe::cSGlobe(&cStack1388,(cXyz *)&this->mEvBank);
        cSAngle::operator__(acStack1460,(cSAngle *)&this->field_0x3ee);
        cSGlobe::U(&cStack1388,acStack1460);
        attentionPos(&cStack932,this,*(fopAc_ac_c **)&this->field_0x3b8);
        cSGlobe::Xyz(&cStack944,&cStack1388);
        ::cXyz::operator__(&cStack956,&cStack932,&cStack944);
        ::cXyz::operator__(&cStack116,&cStack956);
        cSGlobe::_cSGlobe(&cStack1388);
      }
      else {
        if (cVar6 == '-') {
          if (*(int *)&this->field_0x3dc == 2) {
            directionOf((dCamera_c *)(acStack1468 + 2),(fopAc_ac_c *)this);
            dCamMath::xyzRotateY(&cStack980,(cSAngle)((short)this + 0x398));
            ::cXyz::operator__(&cStack116,&cStack980);
          }
          else {
            ::cXyz::operator__(&cStack116,(cXyz *)&this->mEvBank);
          }
        }
        else {
          relationalPos(&cStack968,this,*(fopAc_ac_c **)&this->field_0x3b8,(cXyz *)&this->mEvBank);
          ::cXyz::operator__(&cStack116,&cStack968);
        }
      }
    }
  }
  if (*(int *)&this->field_0x3dc == 1) {
    ::cXyz::operator__(&cStack992,&cStack104,&cStack80);
    ::cXyz::operator_(&cStack1004,&cStack992,(float)dVar14);
    ::cXyz::operator__(&cStack1016,&cStack80,&cStack1004);
    ::cXyz::operator__(&cStack272,&cStack1016);
    ::cXyz::operator__(&cStack1028,&cStack272,&this->field_0x44);
    ::cXyz::operator_(&cStack1040,&cStack1028,*(float *)&this->field_0x3e4);
    mtx::PSVECAdd(&this->field_0x44,&cStack1040,&this->field_0x44);
    ::cXyz::operator__(&cStack1052,&cStack92,&cStack80);
    cSGlobe::cSGlobe(&local_574,&cStack1052);
    ::cXyz::operator__(&cStack1064,&cStack116,&cStack104);
    cSGlobe::cSGlobe(&local_57c,&cStack1064);
    cSAngle::operator__(acStack1468,&local_57c.mAngleX);
    cSAngle::operator_(acStack1472,(float)dVar14);
    cSAngle::operator__(acStack1476,&local_574.mAngleX);
    cSAngle::operator__(acStack1480,&local_57c.mAngleY);
    cSAngle::operator_(acStack1484,(float)dVar14);
    cSAngle::operator__(acStack1488,&local_574.mAngleY);
    cSGlobe::cSGlobe(&cStack1412,
                     local_574.mDistance +
                     (float)(dVar14 * (double)(local_57c.mDistance - local_574.mDistance)),
                     acStack1476,acStack1488);
    cSGlobe::Xyz(&cStack1076,&cStack1412);
    ::cXyz::operator__(&cStack1088,&this->field_0x44,&cStack1076);
    ::cXyz::operator__(&cStack284,&cStack1088);
    ::cXyz::operator__(&cStack1100,&cStack284,&this->field_0x50);
    ::cXyz::operator_(&cStack1112,&cStack1100,*(float *)&this->field_0x3e4);
    mtx::PSVECAdd(&this->field_0x50,&cStack1112,&this->field_0x50);
    cSGlobe::_cSGlobe(&cStack1412);
    cSGlobe::_cSGlobe(&local_57c);
    cSGlobe::_cSGlobe(&local_574);
  }
  else {
    if (*(int *)&this->field_0x3dc == 2) {
      ::cXyz::operator_(&cStack1124,&cStack104,(float)dVar14);
      ::cXyz::operator__(&cStack1136,&cStack80,&cStack1124);
      ::cXyz::operator__(&cStack272,&cStack1136);
      ::cXyz::operator__(&cStack1148,&cStack272,&this->field_0x44);
      ::cXyz::operator_(&cStack1160,&cStack1148,*(float *)&this->field_0x3e4);
      mtx::PSVECAdd(&this->field_0x44,&cStack1160,&this->field_0x44);
      ::cXyz::operator_(&cStack1172,&cStack116,(float)dVar14);
      ::cXyz::operator__(&cStack1184,&cStack92,&cStack1172);
      ::cXyz::operator__(&cStack284,&cStack1184);
      ::cXyz::operator__(&cStack1196,&cStack284,&this->field_0x50);
      ::cXyz::operator_(&cStack1208,&cStack1196,*(float *)&this->field_0x3e4);
      mtx::PSVECAdd(&this->field_0x50,&cStack1208,&this->field_0x50);
    }
    else {
      ::cXyz::operator__(&cStack1220,&cStack104,&cStack80);
      ::cXyz::operator_(&cStack1232,&cStack1220,(float)dVar14);
      ::cXyz::operator__(&cStack1244,&cStack80,&cStack1232);
      ::cXyz::operator__(&cStack272,&cStack1244);
      ::cXyz::operator__(&cStack1256,&cStack272,&this->field_0x44);
      ::cXyz::operator_(&cStack1268,&cStack1256,*(float *)&this->field_0x3e4);
      mtx::PSVECAdd(&this->field_0x44,&cStack1268,&this->field_0x44);
      ::cXyz::operator__(&cStack1280,&cStack116,&cStack92);
      ::cXyz::operator_(&cStack1292,&cStack1280,(float)dVar14);
      ::cXyz::operator__(&cStack1304,&cStack92,&cStack1292);
      ::cXyz::operator__(&cStack284,&cStack1304);
      ::cXyz::operator__(&cStack1316,&cStack284,&this->field_0x50);
      ::cXyz::operator_(&cStack1328,&cStack1316,*(float *)&this->field_0x3e4);
      mtx::PSVECAdd(&this->field_0x50,&cStack1328,&this->field_0x50);
    }
  }
  this->field_0x60 =
       this->field_0x60 +
       *(float *)&this->field_0x3e4 *
       ((*(float *)&this->field_0x390 +
        (float)(dVar14 * (double)((this->mEvBasePos).y - *(float *)&this->field_0x390))) -
       this->field_0x60);
  if (*(char *)&this->field_0x3f0 != '\0') {
    iVar4 = (int)(d_ev_camera::_4865 *
                 (this->mEvFovy + (float)(dVar14 * (double)((this->mEvBasePos).z - this->mEvFovy))))
    ;
    local_38 = (double)(longlong)iVar4;
    SComponent::operator__(auStack1492,iVar4,&this->field_0x5c);
    cSAngle::operator_(acStack1496,*(float *)&this->field_0x3e4);
    cSAngle::operator___((cSAngle *)&this->field_0x5c,acStack1496);
    this->mEventFlags = this->mEventFlags | 0x400;
  }
  ::cXyz::operator__(&cStack1340,&this->field_0x50,&this->field_0x44);
  cSGlobe::Val(&this->field_0x3c,&cStack1340);
  @class$6993d_ev_camera_cpp::__class_6993d_ev_camera_cpp((_class_6993d_ev_camera_cpp *)&cStack116);
  @class$6993d_ev_camera_cpp::__class_6993d_ev_camera_cpp((_class_6993d_ev_camera_cpp *)&cStack92);
LAB_800b6414:
  __psq_l0(auStack8,uVar13);
  __psq_l1(auStack8,uVar13);
  return uVar11;
}


namespace dCamera_c {

/* __thiscall @class$6993d_ev_camera_cpp::~@class$6993d_ev_camera_cpp(void) */

void __thiscall
@class$6993d_ev_camera_cpp::__class_6993d_ev_camera_cpp(_class_6993d_ev_camera_cpp *this)

{
  short in_r4;
  
  if ((this != (_class_6993d_ev_camera_cpp *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}

}

/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Removing unreachable block (ram,0x800b7620) */
/* __thiscall dCamera_c::watchActorEvCamera(void) */

undefined4 __thiscall dCamera_c::watchActorEvCamera(dCamera_c *this)

{
  short sVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  float fVar5;
  undefined4 uVar6;
  char cVar8;
  fopAc_ac_c *pfVar7;
  fopAc_ac_c *in_r7;
  uint uVar9;
  cSGlobe *pcVar10;
  cSAngle *pcVar11;
  undefined4 uVar12;
  undefined8 in_f31;
  double dVar13;
  cSAngle acStack904 [2];
  cSAngle acStack900 [2];
  cSAngle acStack896 [2];
  cSAngle acStack892 [2];
  cSAngle acStack888 [4];
  cSAngle acStack880 [2];
  cSAngle acStack876 [2];
  cSAngle acStack872 [2];
  cSAngle acStack868 [2];
  cSAngle acStack864 [2];
  cSAngle local_35c [2];
  cSAngle acStack856 [2];
  cSAngle acStack852 [2];
  cSAngle acStack848 [2];
  cSAngle local_34c [2];
  cSAngle acStack840 [4];
  cSAngle acStack832 [2];
  cSAngle acStack828 [2];
  cSAngle acStack824 [2];
  cSAngle acStack820 [2];
  cSAngle acStack816 [2];
  cSAngle acStack812 [2];
  cSAngle acStack808 [2];
  cSAngle acStack804 [2];
  cSAngle acStack800 [2];
  cSAngle acStack796 [2];
  cSAngle acStack792 [4];
  cSAngle acStack784 [2];
  cSAngle acStack780 [2];
  cSAngle acStack776 [2];
  cSAngle acStack772 [2];
  cSAngle acStack768 [2];
  cSAngle local_2fc [2];
  cSAngle acStack760 [2];
  cSAngle acStack756 [2];
  cSAngle acStack752 [2];
  cSAngle local_2ec [2];
  cSAngle acStack744 [4];
  cSAngle acStack736 [2];
  cSAngle acStack732 [2];
  cSAngle acStack728 [2];
  cSAngle acStack724 [2];
  cSAngle acStack720 [2];
  cSAngle acStack716 [2];
  cSAngle acStack712 [2];
  cSAngle acStack708 [2];
  cSAngle acStack704 [2];
  cSAngle acStack700 [2];
  cSAngle acStack696 [2];
  cSAngle acStack692 [4];
  cSAngle acStack684 [2];
  cSAngle acStack680 [2];
  cSAngle acStack676 [2];
  cSAngle acStack672 [2];
  cSAngle local_29c [2];
  cSAngle acStack664 [2];
  cSAngle acStack660 [2];
  cSAngle acStack656 [2];
  cSAngle local_28c [2];
  cSAngle acStack648 [4];
  cSAngle acStack640 [2];
  cSAngle acStack636 [2];
  cSAngle acStack632 [2];
  cSAngle acStack628 [2];
  cSAngle acStack624 [4];
  cSAngle acStack616 [2];
  cSAngle acStack612 [2];
  cSAngle local_260 [2];
  cSAngle acStack604 [2];
  cSAngle acStack600 [2];
  cSAngle local_254 [2];
  cSAngle acStack592 [2];
  cSAngle acStack588 [2];
  cSAngle local_248 [2];
  cSAngle local_244 [2];
  float local_240;
  cSGlobe cStack572;
  cSGlobe local_234;
  cSGlobe cStack556;
  cSGlobe local_224;
  cSGlobe cStack540;
  cSGlobe cStack532;
  cSGlobe local_20c;
  cXyz cStack516;
  cXyz cStack504;
  cXyz cStack492;
  cXyz cStack480;
  cXyz cStack468;
  cXyz cStack456;
  cXyz cStack444;
  cXyz cStack432;
  cXyz cStack420;
  cXyz cStack408;
  cXyz cStack396;
  cXyz cStack384;
  cXyz cStack372;
  cXyz cStack360;
  cXyz cStack348;
  cXyz cStack336;
  cXyz cStack324;
  cXyz cStack312;
  cXyz cStack300;
  cXyz cStack288;
  cXyz cStack276;
  cXyz cStack264;
  cXyz cStack252;
  cXyz cStack240;
  cXyz cStack228;
  cXyz cStack216;
  cXyz cStack204;
  cXyz cStack192;
  cXyz cStack180;
  cXyz cStack168;
  cXyz cStack156;
  cXyz cStack144;
  cXyz cStack132;
  cXyz cStack120;
  cXyz cStack108;
  cXyz cStack96;
  cXyz cStack84;
  undefined4 local_48;
  float fStack68;
  undefined4 local_40;
  fopAc_ac_c *pfStack60;
  undefined auStack8 [8];
  
  uVar12 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (d_ev_camera::init_7667 == '\0') {
    ::cXyz::cXyz((cXyz *)&d_ev_camera::DefaultGap_7665,&::cXyz::Zero);
    Runtime.PPCEABI.H::__register_global_object();
    d_ev_camera::init_7667 = '\x01';
  }
  if (d_ev_camera::init_7670 == '\0') {
    d_ev_camera::DefaultCushion_7669 = d_ev_camera::_5486;
    d_ev_camera::init_7670 = '\x01';
  }
  if (d_ev_camera::init_7673 == '\0') {
    d_ev_camera::DefaultNearDist_7672 = d_ev_camera::_8269;
    d_ev_camera::init_7673 = '\x01';
  }
  if (d_ev_camera::init_7676 == '\0') {
    d_ev_camera::DefaultFarDist_7675 = d_ev_camera::_8270;
    d_ev_camera::init_7676 = '\x01';
  }
  if (d_ev_camera::init_7679 == '\0') {
    d_ev_camera::DefaultNearTimer_7678 = 0x14;
    d_ev_camera::init_7679 = '\x01';
  }
  if (d_ev_camera::init_7682 == '\0') {
    d_ev_camera::DefaultFarTimer_7681 = 0x1e;
    d_ev_camera::init_7682 = '\x01';
  }
  if (d_ev_camera::init_7685 == '\0') {
    d_ev_camera::DefaultJumpTimer_7684 = 1;
    d_ev_camera::init_7685 = '\x01';
  }
  if (d_ev_camera::init_7688 == '\0') {
    d_ev_camera::DefaultZoomDist_7687 = d_ev_camera::_8271;
    d_ev_camera::init_7688 = '\x01';
  }
  if (d_ev_camera::init_7691 == '\0') {
    d_ev_camera::DefaultZoomVAngle_7690 = d_ev_camera::_4862;
    d_ev_camera::init_7691 = '\x01';
  }
  if (d_ev_camera::init_7694 == '\0') {
    d_ev_camera::DefaultFrontAngle_7693 = d_ev_camera::_8272;
    d_ev_camera::init_7694 = '\x01';
  }
  if (this->field_0x11c == 0) {
    ::cXyz::cXyz(&cStack132,(cXyz *)&d_ev_camera::DefaultGap_7665);
    getEvXyzData(this,(cXyz *)&this->field_0x378,"CtrGap",&cStack132);
    getEvFloatData(this,(float *)&this->field_0x390,"Cushion",d_ev_camera::DefaultCushion_7669);
    getEvFloatData(this,&this->mEvBank,"NearDist",d_ev_camera::DefaultNearDist_7672);
    getEvFloatData(this,(float *)&this->mEvTimer,"ZoomDist",d_ev_camera::DefaultZoomDist_7687);
    getEvFloatData(this,(float *)&this->field_0x3a8,"ZoomVAngle",d_ev_camera::DefaultZoomVAngle_7690
                  );
    getEvFloatData(this,(float *)this->mEvRelUseMask,"FarDist",d_ev_camera::DefaultFarDist_7675);
    getEvIntData(this,(int *)&this->mEvFovy,"NearTimer",d_ev_camera::DefaultNearTimer_7678);
    getEvIntData(this,(int *)&this->mpEvRelActor,"FarTimer",d_ev_camera::DefaultFarTimer_7681);
    getEvFloatData(this,(float *)&this->field_0x3d4,"FrontAngle",d_ev_camera::DefaultFrontAngle_7693
                  );
    getEvIntData(this,(int *)&this->field_0x3d0,"Blure",0);
    fVar5 = (float)getEvActor(this,"Target","@STARTER");
    (this->mEvBasePos).x = fVar5;
    if (fVar5 == 0.0) {
      uVar6 = 1;
      goto LAB_800b7620;
    }
    fVar5 = (this->mEvBasePos).x;
    if (fVar5 == 0.0) {
      fVar5 = -NAN;
    }
    else {
      fVar5 = *(float *)((int)fVar5 + 4);
    }
    (this->mEvBasePos).y = fVar5;
    relationalPos(&cStack144,this,(fopAc_ac_c *)(this->mEvBasePos).x,(cXyz *)&this->field_0x378);
    ::cXyz::operator__((cXyz *)&this->field_0x384,&cStack144);
    ::cXyz::operator__(&cStack156,&this->field_0x50,(cXyz *)&this->field_0x384);
    cSGlobe::Val((cSGlobe *)&(this->mEvBasePos).z,&cStack156);
    fVar5 = (this->mEvBasePos).z;
    if (this->mEvBank <= fVar5) {
      if (*(float *)this->mEvRelUseMask <= fVar5) {
        *(undefined4 *)&this->field_0x3cc = 3;
      }
      else {
        *(undefined4 *)&this->field_0x3cc = 2;
      }
    }
    else {
      cVar8 = pointInSight(this,(cXyz *)&this->field_0x384);
      if (cVar8 == '\0') {
        *(undefined4 *)&this->field_0x3cc = 1;
      }
      else {
        *(undefined4 *)&this->field_0x3cc = 0;
      }
    }
    *(undefined *)&this->field_0x102 = 1;
    *(undefined *)&this->field_0x101 = 1;
    *(undefined *)&this->field_0x100 = 1;
  }
  local_240 = (this->mEvBasePos).y;
  pfVar7 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,&local_240);
  if (pfVar7 == (fopAc_ac_c *)0x0) {
    uVar6 = 1;
  }
  else {
    bVar3 = false;
    bVar2 = true;
    sVar1 = *(short *)((int)(this->mEvBasePos).x + 0xe);
    if ((((sVar1 == 0x12e) || (sVar1 == 0x12f)) || (sVar1 == 0x133)) || (sVar1 == 0x132)) {
      bVar3 = true;
    }
    iVar4 = *(int *)&this->field_0x3cc;
    if (iVar4 == 2) {
      if (this->field_0x11c == 0) {
        attentionPos(&cStack312,this,this->mpPlayerActor);
        ::cXyz::operator__(&cStack324,&cStack312,(cXyz *)&this->field_0x384);
        cSGlobe::cSGlobe(&local_224,&cStack324);
        if (d_ev_camera::_4862 != *(float *)&this->field_0x3a8) {
          cSAngle::cSAngle(acStack736,*(float *)&this->field_0x3a8);
          cSGlobe::V(&local_224,acStack736);
        }
        directionOf((dCamera_c *)(acStack744 + 2),(fopAc_ac_c *)this);
        pcVar11 = &local_224.mAngleY;
        cSAngle::operator__(acStack744,pcVar11);
        cSAngle::cSAngle(local_254,acStack744);
        cSAngle::cSAngle(local_2ec,-*(float *)&this->field_0x3d4);
        if (((int)(short)(local_2ec[0] ^ local_254[0]) >> 1) -
            (int)(short)((local_2ec[0] ^ local_254[0]) & local_2ec[0]) < 0) {
          directionOf((dCamera_c *)acStack752,(fopAc_ac_c *)this);
          cSAngle::cSAngle(acStack756,-*(float *)&this->field_0x3d4);
          cSAngle::operator__(acStack760,acStack752);
          cSGlobe::U(&local_224,acStack760);
        }
        else {
          cSAngle::cSAngle(local_2fc,*(float *)&this->field_0x3d4);
          if (((int)(short)(local_254[0] ^ local_2fc[0]) >> 1) -
              (int)(short)((local_254[0] ^ local_2fc[0]) & local_254[0]) < 0) {
            directionOf((dCamera_c *)acStack768,(fopAc_ac_c *)this);
            cSAngle::cSAngle(acStack772,*(float *)&this->field_0x3d4);
            cSAngle::operator__(acStack776,acStack768);
            cSGlobe::U(&local_224,acStack776);
          }
        }
        if (ABS(local_224.mDistance - (float)this->mEvTimer) < d_ev_camera::_8281) {
          cSAngle::operator__(acStack780,(short)pcVar11);
          cSGlobe::U(&local_224,acStack780);
        }
        cSGlobe::Val((cSGlobe *)&this->field_0x3c4,(float)this->mEvTimer,&local_224.mAngleX,pcVar11)
        ;
        if (local_254[0] < cSAngle::_0) {
          cSAngle::Val(acStack600,d_ev_camera::_8278);
        }
        else {
          cSAngle::Val(acStack600,d_ev_camera::_8277);
        }
        cSGlobe::cSGlobe(&cStack556,(cSGlobe *)&this->field_0x3c4);
        uVar9 = 0;
        do {
          cSGlobe::Xyz(&cStack336,&cStack556);
          ::cXyz::operator__(&cStack348,(cXyz *)&this->field_0x384,&cStack336);
          ::cXyz::operator__(&cStack108,&cStack348);
          if ((bVar2) &&
             (cVar8 = lineBGCheck(this,(cXyz *)&this->field_0x384,&cStack108,0x8f), cVar8 == '\0'))
          {
            ::cXyz::cXyz(&cStack360,(cXyz *)&this->field_0x384);
            ::cXyz::cXyz(&cStack372,&cStack108);
            cVar8 = @unnamed@d_ev_camera_cpp@::lineCollisionCheck
                              ((_unnamed_d_ev_camera_cpp_ *)&cStack360,&cStack372,
                               (cXyz *)this->mpPlayerActor,(fopAc_ac_c *)(this->mEvBasePos).x,in_r7)
            ;
            if (cVar8 == '\0') {
              cSGlobe::operator__((cSGlobe *)&this->field_0x3c4,&cStack556);
              break;
            }
          }
          cSAngle::operator__(acStack784,&cStack556.mAngleY);
          cSGlobe::U(&cStack556,acStack784);
          if (bVar3) {
            directionOf((dCamera_c *)(acStack792 + 2),(fopAc_ac_c *)this);
            cSAngle::operator__(acStack792,&cStack556.mAngleY);
            cSAngle::cSAngle(acStack604,acStack792);
            dVar13 = (double)cSAngle::Degree(acStack604);
            if (d_ev_camera::_8279 <= (float)ABS(dVar13)) {
              bVar2 = false;
            }
            else {
              bVar2 = true;
            }
          }
          fVar5 = d_ev_camera::_8274;
          if ((uVar9 & 2) != 0) {
            fVar5 = d_ev_camera::_8275;
          }
          cSAngle::cSAngle(acStack796,fVar5);
          cSAngle::operator__(acStack800,&cStack556.mAngleX);
          cSAngle::operator_(acStack804,d_ev_camera::_8280);
          cSAngle::operator__(acStack808,acStack800);
          cSGlobe::V(&cStack556,acStack808);
          uVar9 = uVar9 + 1;
        } while ((int)uVar9 < 0x2d);
        cSGlobe::_cSGlobe(&cStack556);
        cSGlobe::_cSGlobe(&local_224);
      }
      pfStack60 = (fopAc_ac_c *)this->field_0x11c;
      if (pfStack60 < this->mpEvRelActor) {
        local_40 = 0x43300000;
        fStack68 = (float)((uint)this->mpEvRelActor ^ 0x80000000);
        local_48 = 0x43300000;
        dVar13 = (double)((float)((double)CONCAT44(0x43300000,pfStack60) - d_ev_camera::_5488) /
                         (float)((double)CONCAT44(0x43300000,fStack68) - d_ev_camera::_5609));
        ::cXyz::operator__(&cStack384,(cXyz *)&this->field_0x384,&this->field_0x44);
        ::cXyz::operator_(&cStack396,&cStack384,(float)dVar13);
        mtx::PSVECAdd(&this->field_0x44,&cStack396,&this->field_0x44);
        pcVar10 = &this->field_0x3c;
        fVar5 = (this->field_0x3c).mDistance;
        (this->field_0x3c).mDistance =
             fVar5 + (float)(dVar13 * (double)(*(float *)&this->field_0x3c4 - fVar5));
        cSAngle::operator__(acStack812,(cSAngle *)&this->field_0x3ca);
        cSAngle::operator_(acStack816,(float)dVar13);
        cSAngle::operator__(acStack820,&(this->field_0x3c).mAngleY);
        cSGlobe::U(pcVar10,acStack820);
        cSAngle::operator__(acStack824,(cSAngle *)&this->field_0x3c8);
        cSAngle::operator_(acStack828,(float)dVar13);
        cSAngle::operator__(acStack832,&(this->field_0x3c).mAngleX);
        cSGlobe::V(pcVar10,acStack832);
        cSGlobe::Xyz(&cStack408,pcVar10);
        ::cXyz::operator__(&cStack420,&this->field_0x44,&cStack408);
        ::cXyz::operator__(&this->field_0x50,&cStack420);
        uVar6 = 0;
        goto LAB_800b7620;
      }
    }
    else {
      if (iVar4 < 2) {
        if (iVar4 == 0) {
          ::cXyz::operator__(&this->field_0x50,&this->mEye);
          cSGlobe::operator__(&this->field_0x3c,(cSGlobe *)&this->field_0x8);
        }
        else {
          if (-1 < iVar4) {
            if (this->field_0x11c == 0) {
              attentionPos(&cStack168,this,this->mpPlayerActor);
              ::cXyz::cXyz(&cStack84,&cStack168);
              cStack84.y = cStack84.y + d_ev_camera::_8273;
              ::cXyz::operator__(&cStack180,&cStack84,(cXyz *)&this->field_0x384);
              cSGlobe::cSGlobe(&local_20c,&cStack180);
              positionOf(&cStack192,this,(fopAc_ac_c *)(this->mEvBasePos).x);
              ::cXyz::operator__(&cStack204,&this->field_0x50,&cStack192);
              cSGlobe::cSGlobe(&cStack532,&cStack204);
              directionOf((dCamera_c *)(acStack624 + 2),(fopAc_ac_c *)this);
              cSAngle::operator__(acStack624,&cStack532.mAngleY);
              cSAngle::cSAngle(local_244,acStack624);
              if (local_244[0] < cSAngle::_0) {
                cSAngle::cSAngle(acStack628,d_ev_camera::_8274);
                cSAngle::operator__(acStack632,&local_20c.mAngleY);
                cSGlobe::U(&local_20c,acStack632);
              }
              else {
                cSAngle::cSAngle(acStack636,d_ev_camera::_8275);
                cSAngle::operator__(acStack640,&local_20c.mAngleY);
                cSGlobe::U(&local_20c,acStack640);
              }
              directionOf((dCamera_c *)(acStack648 + 2),(fopAc_ac_c *)this);
              cSAngle::operator__(acStack648,&local_20c.mAngleY);
              cSAngle::cSAngle(local_248,acStack648);
              cSAngle::cSAngle(local_28c,-*(float *)&this->field_0x3d4);
              if (((int)(short)(local_28c[0] ^ local_248[0]) >> 1) -
                  (int)(short)((local_28c[0] ^ local_248[0]) & local_28c[0]) < 0) {
                directionOf((dCamera_c *)acStack656,(fopAc_ac_c *)this);
                cSAngle::cSAngle(acStack660,-*(float *)&this->field_0x3d4);
                cSAngle::operator__(acStack664,acStack656);
                cSGlobe::U(&local_20c,acStack664);
              }
              else {
                cSAngle::cSAngle(local_29c,*(float *)&this->field_0x3d4);
                if (((int)(short)(local_248[0] ^ local_29c[0]) >> 1) -
                    (int)(short)((local_248[0] ^ local_29c[0]) & local_248[0]) < 0) {
                  directionOf((dCamera_c *)acStack672,(fopAc_ac_c *)this);
                  cSAngle::cSAngle(acStack676,*(float *)&this->field_0x3d4);
                  cSAngle::operator__(acStack680,acStack672);
                  cSGlobe::U(&local_20c,acStack680);
                }
              }
              cSGlobe::Val((cSGlobe *)&this->field_0x3c4,d_ev_camera::_8276 + local_20c.mDistance,
                           &local_20c.mAngleX,&local_20c.mAngleY);
              if (local_248[0] < cSAngle::_0) {
                cSAngle::Val(acStack588,d_ev_camera::_8278);
              }
              else {
                cSAngle::Val(acStack588,d_ev_camera::_8277);
              }
              cSGlobe::cSGlobe(&cStack540,(cSGlobe *)&this->field_0x3c4);
              uVar9 = 0;
              do {
                cSGlobe::Xyz(&cStack216,&cStack540);
                ::cXyz::operator__(&cStack228,(cXyz *)&this->field_0x384,&cStack216);
                ::cXyz::operator__(&cStack96,&cStack228);
                if ((bVar2) &&
                   (cVar8 = lineBGCheck(this,(cXyz *)&this->field_0x384,&cStack96,0x8f),
                   cVar8 == '\0')) {
                  ::cXyz::cXyz(&cStack240,(cXyz *)&this->field_0x384);
                  ::cXyz::cXyz(&cStack252,&cStack96);
                  cVar8 = @unnamed@d_ev_camera_cpp@::lineCollisionCheck
                                    ((_unnamed_d_ev_camera_cpp_ *)&cStack240,&cStack252,
                                     (cXyz *)this->mpPlayerActor,(fopAc_ac_c *)(this->mEvBasePos).x,
                                     in_r7);
                  if (cVar8 == '\0') {
                    cSGlobe::operator__((cSGlobe *)&this->field_0x3c4,&cStack540);
                    break;
                  }
                }
                cSAngle::operator__(acStack684,&cStack540.mAngleY);
                cSGlobe::U(&cStack540,acStack684);
                if (bVar3) {
                  directionOf((dCamera_c *)(acStack692 + 2),(fopAc_ac_c *)this);
                  cSAngle::operator__(acStack692,&cStack540.mAngleY);
                  cSAngle::cSAngle(acStack592,acStack692);
                  dVar13 = (double)cSAngle::Degree(acStack592);
                  if (d_ev_camera::_8279 <= (float)ABS(dVar13)) {
                    bVar2 = false;
                  }
                  else {
                    bVar2 = true;
                  }
                }
                fVar5 = d_ev_camera::_8274;
                if ((uVar9 & 2) != 0) {
                  fVar5 = d_ev_camera::_8275;
                }
                cSAngle::cSAngle(acStack696,fVar5);
                cSAngle::operator__(acStack700,&cStack540.mAngleX);
                cSAngle::operator_(acStack704,d_ev_camera::_8280);
                cSAngle::operator__(acStack708,acStack700);
                cSGlobe::V(&cStack540,acStack708);
                uVar9 = uVar9 + 1;
              } while ((int)uVar9 < 0x2d);
              cSGlobe::_cSGlobe(&cStack540);
              cSGlobe::_cSGlobe(&cStack532);
              cSGlobe::_cSGlobe(&local_20c);
            }
            fStack68 = (float)this->field_0x11c;
            if ((uint)fStack68 < (uint)this->mEvFovy) {
              local_48 = 0x43300000;
              pfStack60 = (fopAc_ac_c *)((uint)this->mEvFovy ^ 0x80000000);
              local_40 = 0x43300000;
              dVar13 = (double)((float)((double)CONCAT44(0x43300000,fStack68) - d_ev_camera::_5488)
                               / (float)((double)CONCAT44(0x43300000,pfStack60) - d_ev_camera::_5609
                                        ));
              ::cXyz::operator__(&cStack264,(cXyz *)&this->field_0x384,&this->field_0x44);
              ::cXyz::operator_(&cStack276,&cStack264,(float)dVar13);
              mtx::PSVECAdd(&this->field_0x44,&cStack276,&this->field_0x44);
              pcVar10 = &this->field_0x3c;
              fVar5 = (this->field_0x3c).mDistance;
              (this->field_0x3c).mDistance =
                   fVar5 + (float)(dVar13 * (double)(*(float *)&this->field_0x3c4 - fVar5));
              cSAngle::operator__(acStack712,(cSAngle *)&this->field_0x3ca);
              cSAngle::operator_(acStack716,(float)dVar13);
              cSAngle::operator__(acStack720,&(this->field_0x3c).mAngleY);
              cSGlobe::U(pcVar10,acStack720);
              cSAngle::operator__(acStack724,(cSAngle *)&this->field_0x3c8);
              cSAngle::operator_(acStack728,(float)dVar13);
              cSAngle::operator__(acStack732,&(this->field_0x3c).mAngleX);
              cSGlobe::V(pcVar10,acStack732);
              cSGlobe::Xyz(&cStack288,pcVar10);
              ::cXyz::operator__(&cStack300,&this->field_0x44,&cStack288);
              ::cXyz::operator__(&this->field_0x50,&cStack300);
              uVar6 = 0;
              goto LAB_800b7620;
            }
          }
        }
      }
      else {
        if (iVar4 < 4) {
          if (this->field_0x11c == 0) {
            ::cXyz::operator__(&this->field_0x44,(cXyz *)&this->field_0x384);
            attentionPos(&cStack432,this,this->mpPlayerActor);
            ::cXyz::operator__(&cStack444,&cStack432,(cXyz *)&this->field_0x384);
            cSGlobe::cSGlobe(&local_234,&cStack444);
            local_234.mDistance = (float)this->mEvTimer;
            directionOf((dCamera_c *)(acStack840 + 2),(fopAc_ac_c *)this);
            cSAngle::operator__(acStack840,&local_234.mAngleY);
            cSAngle::cSAngle(local_260,acStack840);
            cSAngle::cSAngle(local_34c,-*(float *)&this->field_0x3d4);
            if (((int)(short)(local_34c[0] ^ local_260[0]) >> 1) -
                (int)(short)((local_34c[0] ^ local_260[0]) & local_34c[0]) < 0) {
              directionOf((dCamera_c *)acStack848,(fopAc_ac_c *)this);
              cSAngle::cSAngle(acStack852,-*(float *)&this->field_0x3d4);
              cSAngle::operator__(acStack856,acStack848);
              cSGlobe::U(&local_234,acStack856);
            }
            else {
              cSAngle::cSAngle(local_35c,*(float *)&this->field_0x3d4);
              if (((int)(short)(local_260[0] ^ local_35c[0]) >> 1) -
                  (int)(short)((local_260[0] ^ local_35c[0]) & local_260[0]) < 0) {
                directionOf((dCamera_c *)acStack864,(fopAc_ac_c *)this);
                cSAngle::cSAngle(acStack868,*(float *)&this->field_0x3d4);
                cSAngle::operator__(acStack872,acStack864);
                cSGlobe::U(&local_234,acStack872);
              }
            }
            if (d_ev_camera::_4862 != *(float *)&this->field_0x3a8) {
              cSAngle::cSAngle(acStack876,*(float *)&this->field_0x3a8);
              cSGlobe::V(&local_234,acStack876);
            }
            cSGlobe::Val((cSGlobe *)&this->field_0x3c4,(float)this->mEvTimer,&local_234.mAngleX,
                         &local_234.mAngleY);
            if (local_260[0] < cSAngle::_0) {
              cSAngle::Val(acStack612,d_ev_camera::_8278);
            }
            else {
              cSAngle::Val(acStack612,d_ev_camera::_8277);
            }
            cSGlobe::cSGlobe(&cStack572,(cSGlobe *)&this->field_0x3c4);
            uVar9 = 0;
            do {
              cSGlobe::Xyz(&cStack456,&cStack572);
              ::cXyz::operator__(&cStack468,(cXyz *)&this->field_0x384,&cStack456);
              ::cXyz::operator__(&cStack120,&cStack468);
              if ((bVar2) &&
                 (cVar8 = lineBGCheck(this,(cXyz *)&this->field_0x384,&cStack120,0x8f),
                 cVar8 == '\0')) {
                ::cXyz::cXyz(&cStack480,(cXyz *)&this->field_0x384);
                ::cXyz::cXyz(&cStack492,&cStack120);
                cVar8 = @unnamed@d_ev_camera_cpp@::lineCollisionCheck
                                  ((_unnamed_d_ev_camera_cpp_ *)&cStack480,&cStack492,
                                   (cXyz *)this->mpPlayerActor,(fopAc_ac_c *)(this->mEvBasePos).x,
                                   in_r7);
                if (cVar8 == '\0') {
                  cSGlobe::operator__((cSGlobe *)&this->field_0x3c4,&cStack572);
                  break;
                }
              }
              cSAngle::operator__(acStack880,&cStack572.mAngleY);
              cSGlobe::U(&cStack572,acStack880);
              if (bVar3) {
                directionOf((dCamera_c *)(acStack888 + 2),(fopAc_ac_c *)this);
                cSAngle::operator__(acStack888,&cStack572.mAngleY);
                cSAngle::cSAngle(acStack616,acStack888);
                dVar13 = (double)cSAngle::Degree(acStack616);
                if (d_ev_camera::_8279 <= (float)ABS(dVar13)) {
                  bVar2 = false;
                }
                else {
                  bVar2 = true;
                }
              }
              fVar5 = d_ev_camera::_8274;
              if ((uVar9 & 2) != 0) {
                fVar5 = d_ev_camera::_8275;
              }
              cSAngle::cSAngle(acStack892,fVar5);
              cSAngle::operator__(acStack896,&cStack572.mAngleX);
              cSAngle::operator_(acStack900,d_ev_camera::_8280);
              cSAngle::operator__(acStack904,acStack896);
              cSGlobe::V(&cStack572,acStack904);
              uVar9 = uVar9 + 1;
            } while ((int)uVar9 < 0x2d);
            cSGlobe::_cSGlobe(&cStack572);
            cSGlobe::_cSGlobe(&local_234);
          }
          cSGlobe::operator__(&this->field_0x3c,(cSGlobe *)&this->field_0x3c4);
          cSGlobe::Xyz(&cStack504,&this->field_0x3c);
          ::cXyz::operator__(&cStack516,&this->field_0x44,&cStack504);
          ::cXyz::operator__(&this->field_0x50,&cStack516);
        }
      }
    }
    *(undefined *)&this->field_0x102 = 1;
    *(undefined *)&this->field_0x101 = 1;
    *(undefined *)&this->field_0x100 = 1;
    uVar6 = 1;
  }
LAB_800b7620:
  __psq_l0(auStack8,uVar12);
  __psq_l1(auStack8,uVar12);
  return uVar6;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall cSGlobe::V(cSAngle const &) */

void __thiscall cSGlobe::V(cSGlobe *this,cSAngle *param_1)

{
  cSAngle local_18 [10];
  
  cSAngle::cSAngle(local_18,param_1->v);
  (this->mAngleX).v = local_18[0];
  return;
}


/* __thiscall @unnamed@d_ev_camera_cpp@::lineCollisionCheck(cXyz,
                                                            cXyz,
                                                            fopAc_ac_c *,
                                                            fopAc_ac_c *) */

void __thiscall
@unnamed@d_ev_camera_cpp@::lineCollisionCheck
          (_unnamed_d_ev_camera_cpp_ *this,cXyz *param_1,cXyz *param_2,fopAc_ac_c *param_3,
          fopAc_ac_c *param_4)

{
  dCcS::ChkCamera(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS,(cXyz *)this,param_1,
                  d_ev_camera::_8291,(fopAc_ac_c *)param_2,param_3);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x800b7de0) */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall dCamera_c::restorePosEvCamera(void) */

undefined4 __thiscall dCamera_c::restorePosEvCamera(dCamera_c *this)

{
  int iVar1;
  float fVar2;
  undefined4 uVar3;
  char cVar4;
  undefined4 uVar5;
  undefined8 in_f31;
  double dVar6;
  cSAngle local_f8 [2];
  cSAngle local_f4 [2];
  cSAngle local_f0 [2];
  cSAngle acStack236 [2];
  cSAngle acStack232 [2];
  cSAngle local_e4 [2];
  cSAngle acStack224 [2];
  cSAngle acStack220 [2];
  cSGlobe local_d8;
  cXyz local_d0;
  cXyz cStack196;
  cXyz cStack184;
  cXyz local_ac;
  cXyz cStack160;
  cXyz cStack148;
  cXyz cStack136;
  cXyz cStack124;
  cXyz cStack112;
  cXyz cStack100;
  cXyz cStack88;
  cXyz local_4c;
  cXyz local_40;
  undefined4 local_30;
  fopAc_ac_c *pfStack44;
  undefined4 local_28;
  uint uStack36;
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (d_ev_camera::init_8299 == '\0') {
    d_ev_camera::DefaultGap_8297 = ::cXyz::Zero.x;
    DAT_803e26a8 = ::cXyz::Zero.y;
    DAT_803e26ac = ::cXyz::Zero.z;
    Runtime.PPCEABI.H::__register_global_object
              (&d_ev_camera::DefaultGap_8297,::cXyz::_cXyz,&d_ev_camera::_8298);
    d_ev_camera::init_8299 = '\x01';
  }
  if (d_ev_camera::init_8302 == '\0') {
    d_ev_camera::DefaultCushion_8301 = d_ev_camera::_5486;
    d_ev_camera::init_8302 = '\x01';
  }
  if (d_ev_camera::init_8305 == '\0') {
    d_ev_camera::DefaultNearDist_8304 = d_ev_camera::_8269;
    d_ev_camera::init_8305 = '\x01';
  }
  if (d_ev_camera::init_8308 == '\0') {
    d_ev_camera::DefaultFarDist_8307 = d_ev_camera::_8270;
    d_ev_camera::init_8308 = '\x01';
  }
  if (d_ev_camera::init_8311 == '\0') {
    d_ev_camera::DefaultNearTimer_8310 = 0x14;
    d_ev_camera::init_8311 = '\x01';
  }
  if (d_ev_camera::init_8314 == '\0') {
    d_ev_camera::DefaultFarTimer_8313 = 0x1e;
    d_ev_camera::init_8314 = '\x01';
  }
  if (d_ev_camera::init_8317 == '\0') {
    d_ev_camera::DefaultZoomDist_8316 = d_ev_camera::_8271;
    d_ev_camera::init_8317 = '\x01';
  }
  if (d_ev_camera::init_8320 == '\0') {
    d_ev_camera::DefaultZoomVAngle_8319 = d_ev_camera::_4862;
    d_ev_camera::init_8320 = '\x01';
  }
  if (this->field_0x11c == 0) {
    local_40.x = d_ev_camera::DefaultGap_8297;
    local_40.y = DAT_803e26a8;
    local_40.z = DAT_803e26ac;
    getEvXyzData(this,(cXyz *)&this->field_0x378,"CtrGap",&local_40);
    getEvFloatData(this,(float *)&this->field_0x390,"Cushion",d_ev_camera::DefaultCushion_8301);
    getEvFloatData(this,&this->mEvBank,"NearDist",d_ev_camera::DefaultNearDist_8304);
    getEvFloatData(this,(float *)this->mEvRelUseMask,"FarDist",d_ev_camera::DefaultFarDist_8307);
    getEvIntData(this,(int *)&this->mEvFovy,"NearTimer",d_ev_camera::DefaultNearTimer_8310);
    getEvIntData(this,(int *)&this->mpEvRelActor,"FarTimer",d_ev_camera::DefaultFarTimer_8313);
    getEvIntData(this,(int *)&this->field_0x3bc,"Dest",2);
    getEvIntData(this,(int *)&this->field_0x3e0,"TargetType",0);
    iVar1 = *(int *)&this->field_0x3bc;
    if (iVar1 == 1) {
      *(undefined4 *)&this->field_0x3c0 = *(undefined4 *)(this->field_0xa4 + 1);
      *(undefined4 *)&this->field_0x3c4 = *(undefined4 *)&this->field_0xa4[1].field_0x4;
      *(undefined4 *)&this->field_0x3c8 = *(undefined4 *)&this->field_0xa4[1].field_0x8;
      *(undefined4 *)&this->field_0x3cc = *(undefined4 *)&this->field_0xa4[1].field_0xc;
      *(undefined4 *)&this->field_0x3d0 = *(undefined4 *)&this->field_0xa4[1].field_0x10;
      *(undefined4 *)&this->field_0x3d4 = *(undefined4 *)&this->field_0xa4[1].field_0x14;
      *(undefined4 *)&this->field_0x3d8 = *(undefined4 *)&this->field_0xa4[1].field_0x18;
    }
    else {
      if (iVar1 < 1) {
        if (iVar1 < 0) {
LAB_800b79f0:
          *(float *)&this->field_0x3c0 = (this->field_0x84).x;
          *(float *)&this->field_0x3c4 = (this->field_0x84).y;
          *(float *)&this->field_0x3c8 = (this->field_0x84).z;
          *(float *)&this->field_0x3cc = (this->field_0x90).x;
          *(float *)&this->field_0x3d0 = (this->field_0x90).y;
          *(float *)&this->field_0x3d4 = (this->field_0x90).z;
          *(float *)&this->field_0x3d8 = this->field_0x9c;
        }
        else {
          *(undefined4 *)&this->field_0x3c0 = *(undefined4 *)this->field_0xa4;
          *(undefined4 *)&this->field_0x3c4 = *(undefined4 *)&this->field_0xa4[0].field_0x4;
          *(undefined4 *)&this->field_0x3c8 = *(undefined4 *)&this->field_0xa4[0].field_0x8;
          *(undefined4 *)&this->field_0x3cc = *(undefined4 *)&this->field_0xa4[0].field_0xc;
          *(undefined4 *)&this->field_0x3d0 = *(undefined4 *)&this->field_0xa4[0].field_0x10;
          *(undefined4 *)&this->field_0x3d4 = *(undefined4 *)&this->field_0xa4[0].field_0x14;
          *(undefined4 *)&this->field_0x3d8 = *(undefined4 *)&this->field_0xa4[0].field_0x18;
        }
      }
      else {
        if (iVar1 != 9) goto LAB_800b79f0;
        *(undefined4 *)&this->field_0x3c0 =
             d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0]._20_4_;
        *(undefined4 *)&this->field_0x3c4 =
             d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0]._24_4_;
        *(undefined4 *)&this->field_0x3c8 =
             d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0]._28_4_;
        *(undefined4 *)&this->field_0x3cc =
             d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0]._32_4_;
        *(undefined4 *)&this->field_0x3d0 =
             d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0]._36_4_;
        *(undefined4 *)&this->field_0x3d4 =
             d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0]._40_4_;
        *(undefined4 *)&this->field_0x3d8 =
             d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0]._44_4_;
        *(undefined2 *)&this->field_0x3dc =
             d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0]._48_2_;
      }
    }
    fVar2 = (float)getEvActor(this,"Target","@PLAYER");
    (this->mEvBasePos).x = fVar2;
    if (fVar2 == 0.0) {
      uVar3 = 1;
      goto LAB_800b7de0;
    }
    relationalPos(&local_4c,this,(fopAc_ac_c *)(this->mEvBasePos).x,(cXyz *)&this->field_0x378);
    *(float *)&this->field_0x384 = local_4c.x;
    *(float *)&this->field_0x388 = local_4c.y;
    *(float *)&this->field_0x38c = local_4c.z;
    ::cXyz::operator__(&cStack88,(cXyz *)&this->field_0x3cc,&this->field_0x44);
    cSGlobe::cSGlobe(&local_d8,&cStack88);
    if (this->mEvBank <= local_d8.mDistance) {
      if (*(float *)this->mEvRelUseMask <= local_d8.mDistance) {
        *(undefined4 *)&this->field_0x3b8 = 3;
      }
      else {
        cVar4 = lineBGCheck(this,&this->mEye,(cXyz *)&this->field_0x384,0x8f);
        if (cVar4 == '\0') {
          *(undefined4 *)&this->field_0x3b8 = 2;
        }
        else {
          *(undefined4 *)&this->field_0x3b8 = 3;
        }
      }
    }
    else {
      cVar4 = pointInSight(this,(cXyz *)&this->field_0x384);
      if (cVar4 == '\0') {
        *(undefined4 *)&this->field_0x3b8 = 1;
      }
      else {
        *(undefined4 *)&this->field_0x3b8 = 0;
      }
    }
    *(undefined *)&this->field_0x102 = 1;
    *(undefined *)&this->field_0x101 = 1;
    *(undefined *)&this->field_0x100 = 1;
  }
  iVar1 = *(int *)&this->field_0x3b8;
  if (iVar1 == 3) {
    if (this->field_0x11c == 0) {
      if (*(int *)&this->field_0x3e0 == 1) {
        (this->field_0x44).x = *(float *)&this->field_0x3c0;
        (this->field_0x44).y = *(float *)&this->field_0x3c4;
        (this->field_0x44).z = *(float *)&this->field_0x3c8;
      }
      else {
        (this->field_0x44).x = *(float *)&this->field_0x384;
        (this->field_0x44).y = *(float *)&this->field_0x388;
        (this->field_0x44).z = *(float *)&this->field_0x38c;
      }
      ::cXyz::operator__(&cStack184,(cXyz *)&this->field_0x3cc,(cXyz *)&this->field_0x3c0);
      cSGlobe::Val(&this->field_0x3c,&cStack184);
      cSGlobe::Xyz(&cStack196,&this->field_0x3c);
      ::cXyz::operator__(&local_d0,&this->field_0x44,&cStack196);
      (this->field_0x50).x = local_d0.x;
      (this->field_0x50).y = local_d0.y;
      (this->field_0x50).z = local_d0.z;
      this->field_0x60 = *(float *)&this->field_0x3d8;
    }
  }
  else {
    if (((iVar1 < 3) && (iVar1 != 0)) && (-1 < iVar1)) {
      if (this->field_0x11c == 0) {
        ::cXyz::operator__(&cStack100,(cXyz *)&this->field_0x3cc,(cXyz *)&this->field_0x3c0);
        cSGlobe::Val((cSGlobe *)&(this->mEvBasePos).y,&cStack100);
      }
      pfStack44 = (fopAc_ac_c *)this->field_0x11c;
      if (pfStack44 < this->mpEvRelActor) {
        local_30 = 0x43300000;
        uStack36 = (uint)this->mpEvRelActor ^ 0x80000000;
        local_28 = 0x43300000;
        dVar6 = (double)((float)((double)CONCAT44(0x43300000,pfStack44) - d_ev_camera::_5488) /
                        (float)((double)CONCAT44(0x43300000,uStack36) - d_ev_camera::_5609));
        if (*(int *)&this->field_0x3e0 == 1) {
          ::cXyz::operator__(&cStack112,(cXyz *)&this->field_0x3c0,&this->field_0x44);
          ::cXyz::operator_(&cStack124,&cStack112,(float)dVar6);
          mtx::PSVECAdd(&this->field_0x44,&cStack124,&this->field_0x44);
        }
        else {
          ::cXyz::operator__(&cStack136,(cXyz *)&this->field_0x384,&this->field_0x44);
          ::cXyz::operator_(&cStack148,&cStack136,(float)dVar6);
          mtx::PSVECAdd(&this->field_0x44,&cStack148,&this->field_0x44);
        }
        fVar2 = (this->field_0x3c).mDistance;
        (this->field_0x3c).mDistance =
             fVar2 + (float)(dVar6 * (double)((this->mEvBasePos).y - fVar2));
        cSAngle::operator__(acStack220,(cSAngle *)((int)&(this->mEvBasePos).z + 2));
        cSAngle::operator_(acStack224,(float)dVar6);
        cSAngle::operator__(local_e4,&(this->field_0x3c).mAngleY);
        cSAngle::cSAngle(local_f4,local_e4[0]);
        (this->field_0x3c).mAngleY.v = local_f4[0];
        cSAngle::operator__(acStack232,(cSAngle *)&(this->mEvBasePos).z);
        cSAngle::operator_(acStack236,(float)dVar6);
        cSAngle::operator__(local_f0,&(this->field_0x3c).mAngleX);
        cSAngle::cSAngle(local_f8,local_f0[0]);
        (this->field_0x3c).mAngleX.v = local_f8[0];
        cSGlobe::Xyz(&cStack160,&this->field_0x3c);
        ::cXyz::operator__(&local_ac,&this->field_0x44,&cStack160);
        (this->field_0x50).x = local_ac.x;
        (this->field_0x50).y = local_ac.y;
        (this->field_0x50).z = local_ac.z;
        this->field_0x60 =
             this->field_0x60 +
             (float)(dVar6 * (double)(*(float *)&this->field_0x3d8 - this->field_0x60));
        uVar3 = 0;
        goto LAB_800b7de0;
      }
    }
  }
  *(undefined *)&this->field_0x102 = 1;
  *(undefined *)&this->field_0x101 = 1;
  *(undefined *)&this->field_0x100 = 1;
  uVar3 = 1;
LAB_800b7de0:
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  return uVar3;
}


/* __thiscall dCamera_c::talktoEvCamera(void) */

undefined4 __thiscall dCamera_c::talktoEvCamera(dCamera_c *this)

{
  undefined4 uVar1;
  int iVar2;
  
  dEvt_control_c::convPId
            (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl,
             d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mPt1);
  iVar2 = (int)types[this->field_0x404].mStyles[3];
  if (this->field_0x108 == 0) {
    this->mEventFlags = this->mEventFlags & 0xffdfffff;
  }
  if (iVar2 < 0) {
    iVar2 = dCamParam_c::SearchStyle(&this->mCamParam,0x54543031);
  }
  talktoCamera(this,iVar2);
  uVar1 = 0;
  if (((*(char *)&this->field_0x100 != '\0') && (*(char *)&this->field_0x101 != '\0')) &&
     (*(char *)&this->field_0x102 != '\0')) {
    uVar1 = 1;
  }
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dCamera_c::maptoolIdEvCamera(void) */

uint __thiscall dCamera_c::maptoolIdEvCamera(dCamera_c *this)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  dStage_Event_dt_c *pdVar4;
  dStage_EventInfo_c *pEventInfo;
  uint uVar5;
  int iVar6;
  int id;
  
  if (this->field_0x108 == 0) {
    getEvIntData(this,&id,"ID",-1);
    this->field_0x400 = 0;
    this->field_0x11c = 0;
    if (id == -1) {
      pdVar4 = (dStage_Event_dt_c *)
               dEvt_control_c::getStageEventDt(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl);
    }
    else {
      pEventInfo = (dStage_EventInfo_c *)
                   (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->
                             getEventInfo)();
      if ((id < 0) || (pEventInfo->mCount <= id)) {
        pdVar4 = (dStage_Event_dt_c *)0x0;
      }
      else {
        pdVar4 = pEventInfo->mpEvents + id;
      }
    }
    this->field_0x4c4 = pdVar4;
  }
  pdVar4 = this->field_0x4c4;
  if (pdVar4 == (dStage_Event_dt_c *)0x0) {
    uVar5 = 1;
  }
  else {
    cVar1 = *(char *)&pdVar4->field_0x14;
    bVar2 = pdVar4->field_0x10;
    iVar6 = -1;
    if (pdVar4->field_0x12 != 0xff) {
      if ((pdVar4->field_0x12 & 1) != 0) {
        this->mEventFlags = this->mEventFlags & 0xffdfffff;
      }
      if ((this->field_0x4c4->field_0x12 & 2) != 0) {
        this->field_0x68 = 0;
      }
      bVar3 = this->field_0x4c4->field_0x12;
      if ((bVar3 & 0x80) != 0) {
        iVar6 = 0;
      }
      if ((bVar3 & 0x40) != 0) {
        iVar6 = 0x1e;
      }
    }
    if (this->field_0x108 == iVar6) {
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x806,(cXyz *)0x0,0,0,d_ev_camera::_5486,d_ev_camera::_5486,
                 d_ev_camera::_8558,d_ev_camera::_8558,0);
    }
    iVar6 = GetCameraTypeFromMapToolID(this,(uint)bVar2,(int)cVar1);
    this->field_0x404 = iVar6;
    if (this->field_0x404 == 0xff) {
      this->field_0x4c4 = (dStage_Event_dt_c *)0x0;
    }
    else {
      Runtime.PPCEABI.H::__ptmf_scall
                (engine_tbl +
                 dCamParam_c::styles[(int)(void *)(int)types[this->field_0x404].mStyles[0]].
                 mEngineIdx,this,(void *)(int)types[this->field_0x404].mStyles[0]);
      uVar5 = (uint)*(byte *)&this->field_0x4c4->field_0x11;
      if ((uVar5 == 0xff) || (uVar5 * 10 < (uint)this->field_0x11c)) {
        pdVar4 = (dStage_Event_dt_c *)
                 dEvt_control_c::nextStageEventDt
                           (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl,this->field_0x4c4);
        this->field_0x4c4 = pdVar4;
        *(undefined *)&this->field_0x102 = 0;
        *(undefined *)&this->field_0x101 = 0;
        *(undefined *)&this->field_0x100 = 0;
        if (this->field_0x4c4 != (dStage_Event_dt_c *)0x0) {
          this->field_0x11c = -1;
        }
      }
    }
    uVar5 = countLeadingZeros(this->field_0x4c4);
    uVar5 = uVar5 >> 5;
  }
  return uVar5;
}


/* __thiscall dCamera_c::styleEvCamera(void) */

undefined4 __thiscall dCamera_c::styleEvCamera(dCamera_c *this)

{
  ulong *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  
  if (this->field_0x108 == 0) {
    this->field_0x400 = 0;
    this->field_0x11c = 0;
  }
  puVar1 = (ulong *)getEvStringPntData(this,"Name","FN01");
  pvVar2 = (void *)dCamParam_c::SearchStyle(&this->mCamParam,*puVar1);
  Runtime.PPCEABI.H::__ptmf_scall
            (engine_tbl + dCamParam_c::styles[(int)pvVar2].mEngineIdx,this,pvVar2);
  uVar3 = 0;
  if (((*(char *)&this->field_0x100 != '\0') && (*(char *)&this->field_0x101 != '\0')) &&
     (*(char *)&this->field_0x102 != '\0')) {
    uVar3 = 1;
  }
  return uVar3;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dCamera_c::gameOverEvCamera(void) */

undefined4 __thiscall dCamera_c::gameOverEvCamera(dCamera_c *this)

{
  short sVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  char cVar9;
  cXyz *pcVar10;
  int iVar11;
  cSAngle acStack568 [2];
  cSAngle acStack564 [2];
  cSAngle acStack560 [2];
  cSAngle acStack556 [2];
  cSAngle acStack552 [2];
  cSAngle acStack548 [2];
  cSAngle acStack544 [2];
  cSAngle acStack540 [2];
  cSAngle acStack536 [2];
  cSAngle acStack532 [2];
  cSAngle local_210 [2];
  cXyz local_20c;
  cXyz local_200;
  cXyz cStack500;
  cXyz cStack488;
  cXyz local_1dc;
  cXyz cStack464;
  cXyz cStack452;
  cXyz local_1b8;
  cXyz local_1ac;
  cXyz cStack416;
  cXyz cStack404;
  cXyz local_188;
  cXyz cStack380;
  cXyz cStack368;
  cXyz local_164;
  cXyz local_158;
  cXyz cStack332;
  cXyz cStack320;
  cXyz local_134;
  cXyz cStack296;
  cXyz cStack284;
  cXyz local_110;
  cXyz local_104;
  float local_f8;
  float local_f4;
  float local_f0;
  float local_ec;
  float local_e8;
  float local_e4;
  float local_e0;
  float local_dc;
  float local_d8;
  float local_d4;
  float local_d0;
  float local_cc;
  float local_c8;
  float local_c4;
  float local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  float local_a8;
  cXyz local_a4;
  cXyz local_98;
  cXyz local_8c;
  cXyz local_80;
  cXyz local_74;
  cXyz local_68;
  cXyz local_5c;
  cXyz local_50;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  
  fVar7 = d_ev_camera::_8908;
  fVar6 = d_ev_camera::_8907;
  fVar5 = d_ev_camera::_8906;
  fVar4 = d_ev_camera::_8281;
  fVar3 = d_ev_camera::_8279;
  fVar2 = d_ev_camera::_4862;
  sVar1 = (short)register0x00000004;
  local_5c.x = d_ev_camera::_4862;
  local_5c.y = d_ev_camera::_8890;
  local_5c.z = d_ev_camera::_4862;
  local_c8 = d_ev_camera::_8891;
  local_c4 = d_ev_camera::_8892;
  local_c0 = d_ev_camera::_8893;
  local_50.x = d_ev_camera::_8891;
  local_50.y = d_ev_camera::_8892;
  local_50.z = d_ev_camera::_8893;
  local_d4 = d_ev_camera::_8894;
  local_d0 = d_ev_camera::_8895;
  local_cc = d_ev_camera::_8896;
  local_44 = d_ev_camera::_8894;
  local_40 = d_ev_camera::_8895;
  local_3c = d_ev_camera::_8896;
  local_e0 = d_ev_camera::_8893;
  local_dc = d_ev_camera::_8897;
  local_d8 = d_ev_camera::_8898;
  local_38 = d_ev_camera::_8893;
  local_34 = d_ev_camera::_8897;
  local_30 = d_ev_camera::_8898;
  local_ec = d_ev_camera::_8891;
  local_e8 = d_ev_camera::_8893;
  local_e4 = d_ev_camera::_8899;
  local_2c = d_ev_camera::_8891;
  local_28 = d_ev_camera::_8893;
  local_24 = d_ev_camera::_8899;
  local_f8 = d_ev_camera::_8273;
  local_f4 = d_ev_camera::_8900;
  local_f0 = d_ev_camera::_8901;
  local_20 = d_ev_camera::_8273;
  local_1c = d_ev_camera::_8900;
  local_18 = d_ev_camera::_8901;
  local_68.x = d_ev_camera::_4862;
  local_68.y = d_ev_camera::_8902;
  local_68.z = d_ev_camera::_8903;
  local_74.x = d_ev_camera::_4862;
  local_74.y = d_ev_camera::_8904;
  local_74.z = d_ev_camera::_8905;
  local_b0 = d_ev_camera::_4862;
  local_ac = d_ev_camera::_8906;
  local_a8 = d_ev_camera::_8281;
  local_bc = d_ev_camera::_8279;
  local_b8 = d_ev_camera::_8907;
  local_b4 = d_ev_camera::_8908;
  if (this->field_0x11c == 0) {
    *(undefined4 *)&this->field_0x378 = 0;
    *(undefined4 *)&this->field_0x37c = 0;
    if ((*(uint *)&this->field_0x7c & 2) == 0) {
      *(undefined4 *)&this->field_0x380 = 1;
    }
    else {
      *(undefined4 *)&this->field_0x380 = 0;
    }
    if (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4] & 0x100000U) != 0) {
      *(undefined4 *)&this->field_0x378 = 0x32;
    }
    *(undefined *)&this->field_0x102 = 1;
    *(undefined *)&this->field_0x101 = 1;
    *(undefined *)&this->field_0x100 = 1;
  }
  local_210[0] = cSAngle::_0;
  if (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4] & 0x10000U) != 0) {
    local_210[0] = (short)__270;
  }
  iVar8 = *(int *)&this->field_0x378;
  if (iVar8 == 5) goto LAB_800b8a08;
  if (iVar8 < 5) {
    if (iVar8 == 2) goto LAB_800b8618;
    if (iVar8 < 2) {
      if ((iVar8 == 0) || (iVar8 < 0)) goto LAB_800b83ec;
      goto LAB_800b83f4;
    }
    if (iVar8 < 4) goto LAB_800b8638;
  }
  else {
    if (iVar8 == 0x33) {
LAB_800b89b0:
      *(float *)&this->field_0x384 = fVar2;
      *(float *)&this->field_0x388 = fVar5;
      *(float *)&this->field_0x38c = fVar4;
      *(float *)&this->field_0x390 = fVar3;
      this->mEvFovy = fVar6;
      this->mEvBank = fVar7;
      *(int *)&this->field_0x378 = *(int *)&this->field_0x378 + 1;
LAB_800b89ec:
      if (*(int *)&this->field_0x37c == 0xa0) {
        *(undefined4 *)&this->field_0x378 = 5;
        *(undefined4 *)&this->field_0x37c = 0;
      }
      goto LAB_800b8a08;
    }
    if (iVar8 < 0x33) {
      if (0x31 < iVar8) {
        *(undefined4 *)&this->field_0x378 = 0x33;
        goto LAB_800b89b0;
      }
    }
    else {
      if (iVar8 < 0x35) goto LAB_800b89ec;
    }
LAB_800b83ec:
    *(undefined4 *)&this->field_0x378 = 1;
LAB_800b83f4:
    relationalPos(&local_104,this,this->mpPlayerActor,&local_5c);
    local_80.x = local_104.x;
    local_80.y = local_104.y;
    local_80.z = local_104.z;
    iVar8 = 0;
    iVar11 = 0;
    do {
      if (*(int *)&this->field_0x380 != 0) {
        *(float *)((int)&local_50.x + iVar11) = -*(float *)((int)&local_50.x + iVar11);
      }
      cSAngle::cSAngle(acStack532,local_210);
      pcVar10 = (cXyz *)((int)&local_50.x + iVar11);
      relationalPos(&local_110,this,this->mpPlayerActor,pcVar10,(cSAngle)(sVar1 + -0x214));
      local_8c.x = local_110.x;
      local_8c.y = local_110.y;
      local_8c.z = local_110.z;
      positionOf(&cStack284,this,this->mpPlayerActor);
      if (local_8c.y < *(float *)&this->field_0x368 + cStack284.y) {
        positionOf(&cStack296,this,this->mpPlayerActor);
        local_8c.y = *(float *)&this->field_0x368 + cStack296.y;
      }
      cVar9 = lineBGCheck(this,&local_80,&local_8c,0x7f);
      if (cVar9 == '\0') break;
      pcVar10->x = -pcVar10->x;
      cSAngle::cSAngle(acStack536,local_210);
      relationalPos(&local_134,this,this->mpPlayerActor,pcVar10,(cSAngle)(sVar1 + -0x218));
      local_8c.x = local_134.x;
      local_8c.y = local_134.y;
      local_8c.z = local_134.z;
      positionOf(&cStack320,this,this->mpPlayerActor);
      if (local_8c.y < *(float *)&this->field_0x368 + cStack320.y) {
        positionOf(&cStack332,this,this->mpPlayerActor);
        local_8c.y = *(float *)&this->field_0x368 + cStack332.y;
      }
      cVar9 = lineBGCheck(this,&local_80,&local_8c,0x7f);
      if (cVar9 == '\0') break;
      *(uint *)&this->field_0x380 = *(uint *)&this->field_0x380 ^ 1;
      iVar8 = iVar8 + 1;
      iVar11 = iVar11 + 0xc;
    } while (iVar8 < 5);
    (this->field_0x50).x = local_8c.x;
    (this->field_0x50).y = local_8c.y;
    (this->field_0x50).z = local_8c.z;
    *(float *)&this->field_0x384 = local_5c.x;
    *(float *)&this->field_0x388 = local_5c.y;
    *(float *)&this->field_0x38c = local_5c.z;
    *(float *)&this->field_0x390 = (&local_50)[iVar8].x;
    this->mEvFovy = (&local_50)[iVar8].y;
    this->mEvBank = (&local_50)[iVar8].z;
    *(int *)&this->field_0x378 = *(int *)&this->field_0x378 + 1;
LAB_800b8618:
    if (*(int *)&this->field_0x37c != 0x82) goto LAB_800b8a08;
    *(int *)&this->field_0x378 = *(int *)&this->field_0x378 + 1;
    *(undefined4 *)&this->field_0x37c = 0;
LAB_800b8638:
    cSAngle::cSAngle(acStack540,local_210);
    relationalPos(&local_158,this,this->mpPlayerActor,&local_68,(cSAngle)(sVar1 + -0x21c));
    local_98.x = local_158.x;
    local_98.y = local_158.y;
    local_98.z = local_158.z;
    cSAngle::cSAngle(acStack544,local_210);
    relationalPos(&local_164,this,this->mpPlayerActor,&local_74,(cSAngle)(sVar1 + -0x220));
    local_a4.x = local_164.x;
    local_a4.y = local_164.y;
    local_a4.z = local_164.z;
    positionOf(&cStack368,this,this->mpPlayerActor);
    if (local_a4.y < *(float *)&this->field_0x368 + cStack368.y) {
      positionOf(&cStack380,this,this->mpPlayerActor);
      local_a4.y = *(float *)&this->field_0x368 + cStack380.y;
    }
    cVar9 = lineBGCheck(this,&local_98,&local_a4,0x7f);
    if (cVar9 != '\0') {
      local_74.z = -local_74.z;
      cSAngle::cSAngle(acStack548,local_210);
      relationalPos(&local_188,this,this->mpPlayerActor,&local_74,(cSAngle)(sVar1 + -0x224));
      local_a4.x = local_188.x;
      local_a4.y = local_188.y;
      local_a4.z = local_188.z;
      positionOf(&cStack404,this,this->mpPlayerActor);
      if (local_a4.y < *(float *)&this->field_0x368 + cStack404.y) {
        positionOf(&cStack416,this,this->mpPlayerActor);
        local_a4.y = *(float *)&this->field_0x368 + cStack416.y;
      }
      cVar9 = lineBGCheck(this,&local_98,&local_a4,0x7f);
      if (cVar9 != '\0') {
        local_68.z = d_ev_camera::_4862;
        cSAngle::cSAngle(acStack552,local_210);
        relationalPos(&local_1ac,this,this->mpPlayerActor,&local_68,(cSAngle)(sVar1 + -0x228));
        local_98.x = local_1ac.x;
        local_98.y = local_1ac.y;
        local_98.z = local_1ac.z;
        cSAngle::cSAngle(acStack556,local_210);
        relationalPos(&local_1b8,this,this->mpPlayerActor,&local_74,(cSAngle)(sVar1 + -0x22c));
        local_a4.x = local_1b8.x;
        local_a4.y = local_1b8.y;
        local_a4.z = local_1b8.z;
        positionOf(&cStack452,this,this->mpPlayerActor);
        if (local_a4.y < *(float *)&this->field_0x368 + cStack452.y) {
          positionOf(&cStack464,this,this->mpPlayerActor);
          local_a4.y = *(float *)&this->field_0x368 + cStack464.y;
        }
        cVar9 = lineBGCheck(this,&local_98,&local_a4,0x7f);
        if (cVar9 != '\0') {
          local_74.z = -local_74.z;
          cSAngle::cSAngle(acStack560,local_210);
          relationalPos(&local_1dc,this,this->mpPlayerActor,&local_74,(cSAngle)(sVar1 + -0x230));
          local_a4.x = local_1dc.x;
          local_a4.y = local_1dc.y;
          local_a4.z = local_1dc.z;
          positionOf(&cStack488,this,this->mpPlayerActor);
          if (local_a4.y < *(float *)&this->field_0x368 + cStack488.y) {
            positionOf(&cStack500,this,this->mpPlayerActor);
            local_a4.y = *(float *)&this->field_0x368 + cStack500.y;
          }
          lineBGCheck(this,&local_98,&local_a4,0x7f);
        }
      }
    }
    *(float *)&this->field_0x384 = local_68.x;
    *(float *)&this->field_0x388 = local_68.y;
    *(float *)&this->field_0x38c = local_68.z;
    *(float *)&this->field_0x390 = local_74.x;
    this->mEvFovy = local_74.y;
    this->mEvBank = local_74.z;
    *(int *)&this->field_0x378 = *(int *)&this->field_0x378 + 1;
  }
  if (*(int *)&this->field_0x37c == 0x1e) {
    *(int *)&this->field_0x378 = *(int *)&this->field_0x378 + 1;
    *(undefined4 *)&this->field_0x37c = 0;
  }
LAB_800b8a08:
  cSAngle::cSAngle(acStack564,local_210);
  relationalPos(&local_200,this,this->mpPlayerActor,(cXyz *)&this->field_0x384,
                (cSAngle)(sVar1 + -0x234));
  (this->field_0x44).x = local_200.x;
  (this->field_0x44).y = local_200.y;
  (this->field_0x44).z = local_200.z;
  cSAngle::cSAngle(acStack568,local_210);
  relationalPos(&local_20c,this,this->mpPlayerActor,(cXyz *)&this->field_0x390,
                (cSAngle)(sVar1 + -0x238));
  (this->field_0x50).x = local_20c.x;
  (this->field_0x50).y = local_20c.y;
  (this->field_0x50).z = local_20c.z;
  *(int *)&this->field_0x37c = *(int *)&this->field_0x37c + 1;
  *(undefined *)&this->field_0x102 = 1;
  *(undefined *)&this->field_0x101 = 1;
  *(undefined *)&this->field_0x100 = 1;
  return 1;
}


/* __thiscall dCamera_c::tactEvCamera(void) */

undefined4 __thiscall dCamera_c::tactEvCamera(dCamera_c *this)

{
  char cVar1;
  cXyz local_48;
  cXyz local_3c;
  cXyz local_30;
  cXyz local_24;
  cXyz local_18;
  
  if (this->field_0x11c == 0) {
    *(undefined4 *)&this->field_0x37c = 0;
    if ((*(uint *)&this->field_0x7c & 2) == 0) {
      *(undefined4 *)&this->field_0x380 = 1;
    }
    else {
      *(undefined4 *)&this->field_0x380 = 0;
    }
    *(undefined *)&this->field_0x102 = 1;
    *(undefined *)&this->field_0x101 = 1;
    *(undefined *)&this->field_0x100 = 1;
    *(undefined4 *)&this->field_0x418 = 0;
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0]._48_2_ = this->field_0x5c;
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0]._44_4_ = this->field_0x60;
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0]._20_4_ = (this->field_0x44).x;
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0]._24_4_ = (this->field_0x44).y;
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0]._28_4_ = (this->field_0x44).z;
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0]._32_4_ = (this->field_0x50).x;
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0]._36_4_ = (this->field_0x50).y;
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0]._40_4_ = (this->field_0x50).z;
  }
  local_18.x = d_ev_camera::_8958;
  local_18.y = d_ev_camera::_8959;
  local_18.z = d_ev_camera::_8960;
  local_24.x = d_ev_camera::_8961;
  local_24.y = d_ev_camera::_8962;
  local_24.z = d_ev_camera::_8963;
  if (*(int *)&this->field_0x378 != 1) {
    *(undefined4 *)&this->field_0x378 = 1;
  }
  relationalPos(&local_30,this,this->mpPlayerActor,&local_18);
  (this->field_0x44).x = local_30.x;
  (this->field_0x44).y = local_30.y;
  (this->field_0x44).z = local_30.z;
  if (*(int *)&this->field_0x380 != 0) {
    local_24.x = -local_24.x;
  }
  relationalPos(&local_3c,this,this->mpPlayerActor,&local_24);
  (this->field_0x50).x = local_3c.x;
  (this->field_0x50).y = local_3c.y;
  (this->field_0x50).z = local_3c.z;
  cVar1 = lineBGCheck(this,&this->field_0x44,&this->field_0x50,0x8f);
  if (cVar1 != '\0') {
    local_24.x = -local_24.x;
    relationalPos(&local_48,this,this->mpPlayerActor,&local_24);
    (this->field_0x50).x = local_48.x;
    (this->field_0x50).y = local_48.y;
    (this->field_0x50).z = local_48.z;
  }
  this->field_0x60 = d_ev_camera::_8964;
  *(int *)&this->field_0x37c = *(int *)&this->field_0x37c + 1;
  return 1;
}


/* WARNING: Removing unreachable block (ram,0x800b9998) */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall dCamera_c::windDirectionEvCamera(void) */

undefined4 __thiscall dCamera_c::windDirectionEvCamera(dCamera_c *this)

{
  fopAc_ac_c *pfVar1;
  int iVar2;
  cSGlobe *pcVar3;
  char cVar4;
  undefined4 uVar5;
  double dVar6;
  double dVar7;
  undefined8 in_f31;
  float fVar8;
  cSAngle local_328 [2];
  cSAngle local_324 [2];
  cSAngle local_320 [2];
  cSAngle acStack796 [2];
  cSAngle acStack792 [2];
  cSAngle local_314 [2];
  cSAngle acStack784 [2];
  cSAngle acStack780 [4];
  float local_304;
  undefined auStack768 [4];
  cSGlobe local_2fc;
  cXyz local_2f4;
  cXyz local_2e8;
  cXyz cStack732;
  cXyz cStack720;
  cXyz cStack708;
  cXyz cStack696;
  cXyz cStack684;
  cXyz cStack672;
  cXyz cStack660;
  cXyz local_288;
  cXyz local_27c;
  cXyz local_270;
  cXyz cStack612;
  cXyz cStack600;
  cXyz local_24c;
  cXyz local_240;
  cXyz local_234;
  cXyz cStack552;
  cXyz local_21c;
  cXyz local_210;
  cXyz cStack516;
  cXyz cStack504;
  cXyz cStack492;
  cXyz local_1e0;
  cXyz local_1d4;
  cXyz cStack456;
  cXyz cStack444;
  cXyz cStack432;
  cXyz local_1a4;
  cXyz local_198;
  cXyz local_18c;
  cXyz local_180;
  cXyz local_174;
  cXyz cStack360;
  cXyz cStack348;
  cXyz local_150;
  cXyz local_144;
  cXyz local_138;
  cXyz local_12c;
  float local_120;
  float local_11c;
  float local_118;
  float local_114;
  float local_110;
  float local_10c;
  float local_108;
  float local_104;
  float local_100;
  float local_fc;
  float local_f8;
  float local_f4;
  float local_f0;
  float local_ec;
  float local_e8;
  float local_e4;
  float local_e0;
  float local_dc;
  float local_d8;
  float local_d4;
  float local_d0;
  float local_cc;
  float local_c8;
  float local_c4;
  cXyz local_c0;
  cXyz local_b4;
  cXyz local_a8;
  cXyz local_9c;
  undefined4 local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  undefined **local_78;
  cXyz local_74;
  cXyz local_68;
  cXyz local_5c;
  cXyz local_50;
  cXyz local_44;
  cXyz local_38;
  undefined4 local_28;
  uint uStack36;
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  local_e4 = d_ev_camera::_8890;
  local_e0 = d_ev_camera::_9352;
  local_dc = d_ev_camera::_4862;
  local_50.x = d_ev_camera::_8890;
  local_50.y = d_ev_camera::_9352;
  local_50.z = d_ev_camera::_4862;
  local_f0 = d_ev_camera::_8890;
  local_ec = d_ev_camera::_9352;
  local_e8 = d_ev_camera::_4862;
  local_44.x = d_ev_camera::_8890;
  local_44.y = d_ev_camera::_9352;
  local_44.z = d_ev_camera::_4862;
  local_fc = d_ev_camera::_8890;
  local_f8 = d_ev_camera::_9352;
  local_f4 = d_ev_camera::_4862;
  local_38.x = d_ev_camera::_8890;
  local_38.y = d_ev_camera::_9352;
  local_38.z = d_ev_camera::_4862;
  local_108 = d_ev_camera::_8902;
  local_104 = d_ev_camera::_9353;
  local_100 = d_ev_camera::_9354;
  local_74.x = d_ev_camera::_8902;
  local_74.y = d_ev_camera::_9353;
  local_74.z = d_ev_camera::_9354;
  local_114 = d_ev_camera::_8890;
  local_110 = d_ev_camera::_4862;
  local_10c = d_ev_camera::_9355;
  local_68.x = d_ev_camera::_8890;
  local_68.y = d_ev_camera::_4862;
  local_68.z = d_ev_camera::_9355;
  local_120 = d_ev_camera::_8890;
  local_11c = d_ev_camera::_9356;
  local_118 = d_ev_camera::_9355;
  local_5c.x = d_ev_camera::_8890;
  local_5c.y = d_ev_camera::_9356;
  local_5c.z = d_ev_camera::_9355;
  if (this->field_0x11c == 0) {
    *(undefined4 *)&this->field_0x378 = 0;
    *(undefined4 *)&this->field_0x37c = 0;
    cSGlobe::Val((cSGlobe *)&this->field_0x380,d_ev_camera::_5486,
                 d_kankyo::g_env_light.mTactWindAngleX,d_kankyo::g_env_light.mTactWindAngleY);
    pfVar1 = dEvt_control_c::convPId
                       (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl,
                        d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mPtItem);
    this->mEvBank = (float)pfVar1;
    getEvFloatData(this,(float *)&this->field_0x3d8,"BirdFlyDist",d_ev_camera::_9357);
    local_12c.x = d_ev_camera::_8899;
    local_12c.y = d_ev_camera::_9358;
    local_12c.z = d_ev_camera::_8273;
    getEvXyzData(this,(cXyz *)&(this->mEvBasePos).z,"Torishita",&local_12c);
    iVar2 = d_kankyo_wether::dKyw_get_tactwind_dir();
    if (iVar2 != 0) {
      (this->mEvBasePos).z = -(this->mEvBasePos).z;
    }
    pcVar3 = (cSGlobe *)cSGlobe::Invert((cSGlobe *)&this->field_0x380);
    cSGlobe::cSGlobe(&local_2fc,pcVar3);
    local_2fc.mDistance = *(float *)&this->field_0x3d8;
    local_9c.x = -(this->mEvBasePos).z;
    local_9c.y = d_ev_camera::_4862;
    local_9c.z = d_ev_camera::_4862;
    attentionPos(&local_138,this,this->mpPlayerActor);
    local_a8.x = local_138.x;
    local_a8.y = local_138.y;
    local_a8.z = local_138.z;
    relationalPos(&local_144,this,this->mpPlayerActor,&local_9c);
    local_b4.x = local_144.x;
    local_b4.y = local_144.y;
    local_b4.z = local_144.z;
    relationalPos(&local_150,this,(fopAc_ac_c *)this->mEvBank,(cXyz *)&(this->mEvBasePos).z);
    local_c0.x = local_150.x;
    local_c0.y = local_150.y;
    local_c0.z = local_150.z;
    iVar2 = 0;
    cVar4 = lineBGCheck(this,&local_a8,&local_c0,0x7f);
    if ((cVar4 != '\0') || (cVar4 = lineBGCheck(this,&local_b4,&local_c0,0x7f), cVar4 != '\0')) {
      iVar2 = 1;
    }
    getEvFloatData(this,(float *)&this->field_0x3c0,"StopDist",d_ev_camera::_8907);
    getEvIntData(this,(int *)&this->field_0x3c8,"UpCount",8);
    getEvIntData(this,(int *)&this->field_0x3cc,"SideFlag",0);
    getEvFloatData(this,(float *)&this->field_0x3c4,"FollowCushion",d_ev_camera::_9359);
    getEvFloatData(this,(float *)&this->field_0x3dc,"NearFovy",d_ev_camera::_8281);
    getEvFloatData(this,(float *)&this->field_0x3e0,"FarFovy",d_ev_camera::_8891);
    getEvFloatData(this,(float *)&this->field_0x3e4,"FovyCushion",d_ev_camera::_9360);
    positionOf(&cStack348,this,(fopAc_ac_c *)this->mEvBank);
    positionOf(&cStack360,this,this->mpPlayerActor);
    ::cXyz::operator__(&local_174,&cStack348,&cStack360);
    local_180.x = local_174.x;
    local_180.y = local_174.y;
    local_180.z = local_174.z;
    fVar8 = mtx::PSVECSquareMag(&local_180);
    dVar7 = (double)fVar8;
    if ((double)d_ev_camera::_4862 < dVar7) {
      dVar6 = 1.0 / SQRT(dVar7);
      dVar6 = d_ev_camera::_4863 * dVar6 * (d_ev_camera::_4864 - dVar7 * dVar6 * dVar6);
      dVar6 = d_ev_camera::_4863 * dVar6 * (d_ev_camera::_4864 - dVar7 * dVar6 * dVar6);
      local_304 = (float)(dVar7 * d_ev_camera::_4863 * dVar6 *
                                  (d_ev_camera::_4864 - dVar7 * dVar6 * dVar6));
      dVar7 = (double)local_304;
    }
    *(float *)&this->field_0x3d4 = (float)dVar7;
    this->field_0x60 = *(float *)&this->field_0x3e0;
    getEvIntData(this,(int *)&this->field_0x3d0,"Type",iVar2);
    if (*(int *)&this->field_0x3d0 == 1) {
      *(undefined4 *)&this->field_0x378 = 10;
    }
  }
  iVar2 = d_kankyo_wether::dKyw_get_tactwind_dir();
  if (iVar2 != 0) {
    local_50.x = -local_50.x;
    local_44.x = -local_44.x;
    local_38.x = -local_38.x;
    local_74.x = -local_74.x;
    local_68.x = -local_68.x;
    local_5c.x = -local_5c.x;
  }
  iVar2 = *(int *)&this->field_0x378;
  if (iVar2 == 0xc) {
    if ((int)*(uint *)&this->field_0x37c < *(int *)&this->field_0x3c8) {
      uStack36 = *(uint *)&this->field_0x37c ^ 0x80000000;
      local_28 = 0x43300000;
      *(float *)&this->field_0x3ec =
           *(float *)&this->field_0x3ec +
           (float)((double)CONCAT44(0x43300000,uStack36) - d_ev_camera::_5609);
      dVar7 = (double)(*(float *)&this->field_0x3ec / *(float *)&this->field_0x3e8);
      (this->field_0x3c).mDistance =
           *(float *)&this->field_0x388 +
           (float)(dVar7 * (double)(*(float *)&this->field_0x390 - *(float *)&this->field_0x388));
      cSAngle::operator__(acStack780,(cSAngle *)&this->mEvFovy);
      cSAngle::operator_(acStack784,(float)dVar7);
      cSAngle::operator__(local_314,(cSAngle *)&this->field_0x38c);
      cSAngle::cSAngle(local_324,local_314[0]);
      (this->field_0x3c).mAngleX.v = local_324[0];
      cSAngle::operator__(acStack792,(cSAngle *)((int)&this->mEvFovy + 2));
      cSAngle::operator_(acStack796,(float)dVar7);
      cSAngle::operator__(local_320,(cSAngle *)&this->field_0x38e);
      cSAngle::cSAngle(local_328,local_320[0]);
      (this->field_0x3c).mAngleY.v = local_328[0];
      (this->field_0x44).x = *(float *)&this->field_0x3a8;
      (this->field_0x44).y = (this->mEvBasePos).x;
      (this->field_0x44).z = (this->mEvBasePos).y;
      cSGlobe::Xyz(&cStack612,&this->field_0x3c);
      ::cXyz::operator__(&local_270,&this->field_0x44,&cStack612);
      (this->field_0x50).x = local_270.x;
      (this->field_0x50).y = local_270.y;
      (this->field_0x50).z = local_270.z;
      goto LAB_800b9844;
    }
    *(undefined4 *)&this->field_0x378 = 0xd;
LAB_800b9740:
    *(undefined4 *)&this->field_0x378 = 0xe;
    *(undefined4 *)&this->field_0x3c8 = 0;
    *(undefined4 *)&this->field_0x37c = 0;
  }
  else {
    if (iVar2 < 0xc) {
      if (iVar2 != 3) {
        if (2 < iVar2) {
          if (iVar2 == 10) {
            relationalPos(&local_210,this,this->mpPlayerActor,&local_50);
            (this->field_0x44).x = local_210.x;
            (this->field_0x44).y = local_210.y;
            (this->field_0x44).z = local_210.z;
            relationalPos(&local_21c,this,this->mpPlayerActor,&local_74);
            (this->field_0x50).x = local_21c.x;
            (this->field_0x50).y = local_21c.y;
            (this->field_0x50).z = local_21c.z;
            ::cXyz::operator__(&cStack552,&this->field_0x50,&this->field_0x44);
            cSGlobe::Val(&this->field_0x3c,&cStack552);
            *(undefined4 *)&this->field_0x3c8 = 0x1c;
            ResetBlure(this,0);
            SetBlureTimer(this,0x6e);
            SetBlureAlpha(this,d_ev_camera::_9361);
            SetBlureScale(this,d_ev_camera::_9362);
            local_234.x = d_ev_camera::_4862;
            local_234.y = d_ev_camera::_5486;
            local_234.z = d_ev_camera::_4862;
            dVibration_c::StartShock
                      (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mVibration,7,0x20,&local_234);
          }
          else {
            if (iVar2 < 10) goto LAB_800b916c;
          }
          if (*(int *)&this->field_0x3c8 < *(int *)&this->field_0x37c) {
            *(undefined4 *)&this->field_0x378 = 0xc;
            relationalPos(&local_240,this,this->mpPlayerActor,&local_44);
            *(float *)&this->field_0x3a8 = local_240.x;
            (this->mEvBasePos).x = local_240.y;
            (this->mEvBasePos).y = local_240.z;
            relationalPos(&local_24c,this,this->mpPlayerActor,&local_68);
            this->mpEvRelActor = (fopAc_ac_c *)local_24c.x;
            *(float *)this->mEvRelUseMask = local_24c.y;
            this->mEvTimer = (int)local_24c.z;
            ::cXyz::operator__(&cStack600,(cXyz *)&this->mpEvRelActor,(cXyz *)&this->field_0x3a8);
            cSGlobe::Val((cSGlobe *)&this->field_0x390,&cStack600);
            *(float *)&this->field_0x388 = (this->field_0x3c).mDistance;
            *(short *)&this->field_0x38c = (this->field_0x3c).mAngleX.v;
            *(short *)&this->field_0x38e = (this->field_0x3c).mAngleY.v;
            *(undefined4 *)&this->field_0x3c8 = 0x28;
            *(undefined4 *)&this->field_0x37c = 0;
            *(float *)&this->field_0x3ec = d_ev_camera::_4862;
            uStack36 = *(int *)&this->field_0x3c8 * (*(int *)&this->field_0x3c8 + 1) >> 1 ^
                       0x80000000;
            local_28 = 0x43300000;
            *(float *)&this->field_0x3e8 =
                 (float)((double)CONCAT44(0x43300000,uStack36) - d_ev_camera::_5609);
          }
          goto LAB_800b9844;
        }
        if (iVar2 == 1) {
          if (*(int *)&this->field_0x3c8 < *(int *)&this->field_0x37c) {
            *(undefined4 *)&this->field_0x378 = 2;
          }
          goto LAB_800b9844;
        }
        if (iVar2 < 1) {
LAB_800b916c:
          attentionPos(&local_18c,this,this->mpPlayerActor);
          (this->field_0x44).x = local_18c.x;
          (this->field_0x44).y = local_18c.y;
          (this->field_0x44).z = local_18c.z;
          relationalPos(&local_198,this,(fopAc_ac_c *)this->mEvBank,(cXyz *)&(this->mEvBasePos).z);
          (this->field_0x50).x = local_198.x;
          (this->field_0x50).y = local_198.y;
          (this->field_0x50).z = local_198.z;
          dVar7 = (double)dCamMath::xyzHorizontalDistance(&this->field_0x44,&this->field_0x50);
          ResetBlure(this,0);
          SetBlureTimer(this,0x6e);
          SetBlureAlpha(this,d_ev_camera::_9361);
          SetBlureScale(this,d_ev_camera::_9362);
          local_1a4.x = d_ev_camera::_4862;
          local_1a4.y = d_ev_camera::_5486;
          local_1a4.z = d_ev_camera::_4862;
          dVibration_c::StartShock
                    (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mVibration,7,0x20,&local_1a4);
          if (dVar7 < (double)*(float *)&this->field_0x3c0) {
            *(undefined4 *)&this->field_0x378 = 1;
            *(undefined4 *)&this->field_0x37c = 0;
          }
          goto LAB_800b9844;
        }
        *(float *)&this->field_0x3a8 = (this->field_0x44).x;
        (this->mEvBasePos).x = (this->field_0x44).y;
        (this->mEvBasePos).y = (this->field_0x44).z;
        *(undefined4 *)&this->field_0x378 = 3;
      }
      attentionPos(&cStack432,this,(fopAc_ac_c *)this->mEvBank);
      ::cXyz::operator__(&cStack444,&cStack432,(cXyz *)&this->field_0x3a8);
      ::cXyz::operator_(&cStack456,&cStack444,d_ev_camera::_9359);
      ::cXyz::operator__(&local_1d4,(cXyz *)&this->field_0x3a8,&cStack456);
      *(float *)&this->field_0x3a8 = local_1d4.x;
      (this->mEvBasePos).x = local_1d4.y;
      (this->mEvBasePos).y = local_1d4.z;
      local_78 = &::cM3dGLin::__vt;
      local_90 = *(undefined4 *)&this->field_0x3a8;
      local_8c = (this->mEvBasePos).x;
      local_88 = (this->mEvBasePos).y;
      local_84 = (this->field_0x50).x;
      local_80 = (this->field_0x50).y;
      local_7c = (this->field_0x50).z;
      attentionPos(&local_1e0,this,this->mpPlayerActor);
      local_cc = local_1e0.x;
      local_c8 = local_1e0.y;
      local_c4 = local_1e0.z;
      cVar4 = SComponent::cM3d_Len3dSqPntAndSegLine(&local_90,&local_cc,&local_d8,auStack768);
      if (cVar4 == '\0') {
        (this->field_0x44).x = *(float *)&this->field_0x3a8;
        (this->field_0x44).y = (this->mEvBasePos).x;
        (this->field_0x44).z = (this->mEvBasePos).y;
      }
      else {
        (this->field_0x44).x = local_d8;
        (this->field_0x44).y = local_d4;
        (this->field_0x44).z = local_d0;
      }
      if ((((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4] & 0x10000U) != 0)
         && (eyePos(&cStack492,this,this->mpPlayerActor), (this->field_0x50).y < cStack492.y)) {
        eyePos(&cStack504,this,this->mpPlayerActor);
        fVar8 = (this->field_0x50).y;
        (this->field_0x50).y = fVar8 + d_ev_camera::_9360 * (cStack504.y - fVar8);
      }
      ::cXyz::operator__(&cStack516,&this->field_0x50,&this->field_0x44);
      cSGlobe::Val(&this->field_0x3c,&cStack516);
      local_78 = &::cM3dGLin::__vt;
      goto LAB_800b9844;
    }
    if (iVar2 == 0xf) {
      ::cXyz::operator__(&cStack660,(cXyz *)&this->field_0x3a8,&this->field_0x44);
      ::cXyz::operator_(&cStack672,&cStack660,d_ev_camera::_9359);
      mtx::PSVECAdd(&this->field_0x44,&cStack672,&this->field_0x44);
      ::cXyz::operator__(&cStack684,(cXyz *)&this->mpEvRelActor,&this->field_0x50);
      ::cXyz::operator_(&cStack696,&cStack684,d_ev_camera::_9359);
      mtx::PSVECAdd(&this->field_0x50,&cStack696,&this->field_0x50);
      ::cXyz::operator__(&cStack708,&this->field_0x50,&this->field_0x44);
      cSGlobe::Val(&this->field_0x3c,&cStack708);
      goto LAB_800b9844;
    }
    if (0xe < iVar2) {
      if (iVar2 == 99) goto LAB_800b9844;
      goto LAB_800b916c;
    }
    if (iVar2 < 0xe) goto LAB_800b9740;
  }
  if (*(int *)&this->field_0x3c8 < *(int *)&this->field_0x37c) {
    *(undefined4 *)&this->field_0x378 = 0xf;
  }
  relationalPos(&local_27c,this,this->mpPlayerActor,&local_38);
  *(float *)&this->field_0x3a8 = local_27c.x;
  (this->mEvBasePos).x = local_27c.y;
  (this->mEvBasePos).y = local_27c.z;
  relationalPos(&local_288,this,this->mpPlayerActor,&local_5c);
  this->mpEvRelActor = (fopAc_ac_c *)local_288.x;
  *(float *)this->mEvRelUseMask = local_288.y;
  this->mEvTimer = (int)local_288.z;
LAB_800b9844:
  if (*(int *)&this->field_0x3d0 == 0) {
    positionOf(&cStack720,this,(fopAc_ac_c *)this->mEvBank);
    positionOf(&cStack732,this,this->mpPlayerActor);
    ::cXyz::operator__(&local_2e8,&cStack720,&cStack732);
    local_2f4.x = local_2e8.x;
    local_2f4.y = local_2e8.y;
    local_2f4.z = local_2e8.z;
    fVar8 = mtx::PSVECSquareMag(&local_2f4);
    dVar7 = (double)fVar8;
    if ((double)d_ev_camera::_4862 < dVar7) {
      dVar6 = 1.0 / SQRT(dVar7);
      dVar6 = d_ev_camera::_4863 * dVar6 * (d_ev_camera::_4864 - dVar7 * dVar6 * dVar6);
      dVar6 = d_ev_camera::_4863 * dVar6 * (d_ev_camera::_4864 - dVar7 * dVar6 * dVar6);
      dVar7 = (double)(float)(dVar7 * d_ev_camera::_4863 * dVar6 *
                                      (d_ev_camera::_4864 - dVar7 * dVar6 * dVar6));
    }
    dVar6 = (double)*(float *)&this->field_0x3c0;
    fVar8 = d_ev_camera::_4862;
    if ((dVar6 <= dVar7) &&
       (fVar8 = d_ev_camera::_5486, dVar7 <= (double)*(float *)&this->field_0x3d4)) {
      fVar8 = (float)(dVar7 - dVar6) / (float)((double)*(float *)&this->field_0x3d4 - dVar6);
    }
    this->field_0x60 =
         this->field_0x60 +
         *(float *)&this->field_0x3e4 *
         ((*(float *)&this->field_0x3dc +
          fVar8 * (*(float *)&this->field_0x3e0 - *(float *)&this->field_0x3dc)) - this->field_0x60)
    ;
  }
  else {
    *(undefined4 *)&this->field_0x418 = 1;
    this->field_0x60 = d_ev_camera::_9363;
  }
  *(int *)&this->field_0x37c = *(int *)&this->field_0x37c + 1;
  *(undefined *)&this->field_0x102 = 1;
  *(undefined *)&this->field_0x101 = 1;
  *(undefined *)&this->field_0x100 = 1;
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  return 1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x800b9f90) */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall dCamera_c::turnToActorEvCamera(void) */

undefined4 __thiscall dCamera_c::turnToActorEvCamera(dCamera_c *this)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  cXyz *pcVar4;
  undefined4 uVar5;
  undefined8 in_f31;
  double dVar6;
  cSAngle local_158 [2];
  cSAngle local_154 [2];
  cSAngle local_150 [2];
  cSAngle local_14c [2];
  cSAngle local_148 [2];
  cSAngle local_144 [2];
  cSAngle local_140 [2];
  cSAngle acStack316 [2];
  cSAngle acStack312 [2];
  cSAngle local_134 [2];
  cSAngle acStack304 [2];
  cSAngle acStack300 [2];
  cSAngle local_128 [2];
  cSAngle acStack292 [2];
  cSAngle acStack288 [2];
  cSAngle local_11c [2];
  cSAngle local_118 [2];
  cSAngle acStack276 [2];
  cSAngle acStack272 [2];
  cSAngle local_10c [2];
  cSAngle acStack264 [4];
  cSAngle local_100 [2];
  cSAngle acStack252 [2];
  cSAngle local_f8 [2];
  cSAngle acStack244 [2];
  cSAngle acStack240 [4];
  cSAngle local_e8 [2];
  cSAngle local_e4 [2];
  cSGlobe cStack224;
  cSGlobe cStack216;
  cXyz cStack208;
  cXyz local_c4;
  cXyz cStack184;
  cXyz cStack172;
  cXyz cStack160;
  cXyz local_94;
  cXyz cStack136;
  cXyz cStack124;
  cXyz cStack112;
  cXyz local_64;
  cXyz local_58;
  cXyz local_4c;
  cXyz local_40;
  undefined4 local_30;
  uint uStack44;
  int local_28;
  uint uStack36;
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (d_ev_camera::init_9376 == '\0') {
    d_ev_camera::DefaultGap_9374 = d_ev_camera::_4862;
    DAT_803e26c0 = d_ev_camera::_8899;
    DAT_803e26c4 = d_ev_camera::_4862;
    Runtime.PPCEABI.H::__register_global_object
              (&d_ev_camera::DefaultGap_9374,::cXyz::_cXyz,&d_ev_camera::_9375);
    d_ev_camera::init_9376 = '\x01';
  }
  if (d_ev_camera::init_9379 == '\0') {
    d_ev_camera::DefaultCushion_9378 = d_ev_camera::_5486;
    d_ev_camera::init_9379 = '\x01';
  }
  if (d_ev_camera::init_9382 == '\0') {
    d_ev_camera::DefaultDist_9381 = d_ev_camera::_8276;
    d_ev_camera::init_9382 = '\x01';
  }
  if (d_ev_camera::init_9385 == '\0') {
    d_ev_camera::DefaultTimer_9384 = 0x14;
    d_ev_camera::init_9385 = '\x01';
  }
  if (d_ev_camera::init_9388 == '\0') {
    d_ev_camera::DefaultFrontAngle_9387 = d_ev_camera::_8272;
    d_ev_camera::init_9388 = '\x01';
  }
  pcVar4 = (cXyz *)&this->field_0x378;
  if (this->field_0x11c == 0) {
    local_4c.x = d_ev_camera::DefaultGap_9374;
    local_4c.y = DAT_803e26c0;
    local_4c.z = DAT_803e26c4;
    getEvXyzData(this,pcVar4,"CtrGap",&local_4c);
    getEvFloatData(this,(float *)&this->mpEvRelActor,"Cushion",d_ev_camera::DefaultCushion_9378);
    getEvIntData(this,&this->mEvTimer,"Timer",d_ev_camera::DefaultTimer_9384);
    getEvFloatData(this,(float *)&this->field_0x3c8,"FrontAngle",d_ev_camera::DefaultFrontAngle_9387
                  );
    iVar2 = getEvActor(this,"Target","@STARTER");
    *(int *)&this->field_0x3a8 = iVar2;
    if (iVar2 == 0) {
      *(undefined *)&this->field_0x102 = 1;
      *(undefined *)&this->field_0x101 = 1;
      *(undefined *)&this->field_0x100 = 1;
      uVar3 = 1;
      goto LAB_800b9f90;
    }
    attentionPos(&local_58,this,*(fopAc_ac_c **)&this->field_0x3a8);
    *(float *)&this->field_0x384 = local_58.x;
    *(float *)&this->field_0x388 = local_58.y;
    *(float *)&this->field_0x38c = local_58.z;
    *(undefined *)&this->field_0x102 = 1;
    *(undefined *)&this->field_0x101 = 1;
    *(undefined *)&this->field_0x100 = 1;
  }
  if (this->field_0x11c == 0) {
    relationalPos(&local_64,this,this->mpPlayerActor,pcVar4);
    local_40.x = local_64.x;
    local_40.y = local_64.y;
    local_40.z = local_64.z;
    ::cXyz::operator__(&cStack112,&local_40,(cXyz *)&this->field_0x384);
    cSGlobe::cSGlobe(&cStack216,&cStack112);
    positionOf(&cStack124,this,*(fopAc_ac_c **)&this->field_0x3a8);
    ::cXyz::operator__(&cStack136,&this->field_0x50,&cStack124);
    cSGlobe::cSGlobe(&cStack224,&cStack136);
    directionOf((dCamera_c *)(acStack240 + 2),(fopAc_ac_c *)this);
    cSAngle::operator__(acStack240,&cStack224.mAngleY);
    cSAngle::cSAngle(local_e4,acStack240);
    if (local_e4[0] < cSAngle::_0) {
      cSAngle::cSAngle(acStack244,d_ev_camera::_8274);
      cSAngle::operator__(local_f8,&cStack216.mAngleY);
      cSAngle::cSAngle(local_144,local_f8[0]);
      cStack216.mAngleY = local_144[0];
    }
    else {
      cSAngle::cSAngle(acStack252,d_ev_camera::_8275);
      cSAngle::operator__(local_100,&cStack216.mAngleY);
      cSAngle::cSAngle(local_148,local_100[0]);
      cStack216.mAngleY = local_148[0];
    }
    directionOf((dCamera_c *)(acStack264 + 2),(fopAc_ac_c *)this);
    cSAngle::operator__(acStack264,&cStack216.mAngleY);
    cSAngle::cSAngle(local_e8,acStack264);
    cSAngle::cSAngle(local_10c,-*(float *)&this->field_0x3c8);
    if (((int)(short)(local_10c[0] ^ local_e8[0]) >> 1) -
        (int)(short)((local_10c[0] ^ local_e8[0]) & local_10c[0]) < 0) {
      directionOf((dCamera_c *)acStack272,(fopAc_ac_c *)this);
      cSAngle::cSAngle(acStack276,-*(float *)&this->field_0x3c8);
      cSAngle::operator__(local_118,acStack272);
      cSAngle::cSAngle(local_14c,local_118[0]);
      cStack216.mAngleY = local_14c[0];
    }
    else {
      cSAngle::cSAngle(local_11c,*(float *)&this->field_0x3c8);
      if (((int)(short)(local_e8[0] ^ local_11c[0]) >> 1) -
          (int)(short)((local_e8[0] ^ local_11c[0]) & local_e8[0]) < 0) {
        directionOf((dCamera_c *)acStack288,(fopAc_ac_c *)this);
        cSAngle::cSAngle(acStack292,*(float *)&this->field_0x3c8);
        cSAngle::operator__(local_128,acStack288);
        cSAngle::cSAngle(local_150,local_128[0]);
        cStack216.mAngleY = local_150[0];
      }
    }
    cSGlobe::Val((cSGlobe *)&this->field_0x3bc,d_ev_camera::_8276,&cStack216.mAngleX,
                 &cStack216.mAngleY);
    relationalPos(&local_94,this,this->mpPlayerActor,pcVar4);
    *(float *)&this->field_0x390 = local_94.x;
    this->mEvFovy = local_94.y;
    this->mEvBank = local_94.z;
  }
  uStack44 = this->field_0x11c;
  if (uStack44 < (uint)this->mEvTimer) {
    local_30 = 0x43300000;
    uStack36 = this->mEvTimer ^ 0x80000000;
    local_28 = 0x43300000;
    dVar6 = (double)((float)((double)CONCAT44(0x43300000,uStack44) - d_ev_camera::_5488) /
                    (float)((double)CONCAT44(0x43300000,uStack36) - d_ev_camera::_5609));
    ::cXyz::operator__(&cStack160,(cXyz *)&this->field_0x390,&this->field_0x44);
    ::cXyz::operator_(&cStack172,&cStack160,(float)dVar6);
    mtx::PSVECAdd(&this->field_0x44,&cStack172,&this->field_0x44);
    fVar1 = (this->field_0x3c).mDistance;
    (this->field_0x3c).mDistance =
         fVar1 + (float)(dVar6 * (double)(*(float *)&this->field_0x3bc - fVar1));
    cSAngle::operator__(acStack300,(cSAngle *)&this->field_0x3c2);
    cSAngle::operator_(acStack304,(float)dVar6);
    cSAngle::operator__(local_134,&(this->field_0x3c).mAngleY);
    cSAngle::cSAngle(local_154,local_134[0]);
    (this->field_0x3c).mAngleY.v = local_154[0];
    cSAngle::operator__(acStack312,(cSAngle *)&this->field_0x3c0);
    cSAngle::operator_(acStack316,(float)dVar6);
    cSAngle::operator__(local_140,&(this->field_0x3c).mAngleX);
    cSAngle::cSAngle(local_158,local_140[0]);
    (this->field_0x3c).mAngleX.v = local_158[0];
    cSGlobe::Xyz(&cStack184,&this->field_0x3c);
    ::cXyz::operator__(&local_c4,&this->field_0x44,&cStack184);
    (this->field_0x50).x = local_c4.x;
    (this->field_0x50).y = local_c4.y;
    (this->field_0x50).z = local_c4.z;
    ::cXyz::operator__(&cStack208,&this->field_0x50,&this->field_0x44);
    cSGlobe::Val(&this->field_0x3c,&cStack208);
    uVar3 = 0;
  }
  else {
    *(undefined *)&this->field_0x102 = 1;
    *(undefined *)&this->field_0x101 = 1;
    *(undefined *)&this->field_0x100 = 1;
    uVar3 = 1;
  }
LAB_800b9f90:
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  return uVar3;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x800ba660) */
/* WARNING: Removing unreachable block (ram,0x800ba668) */
/* __thiscall dCamera_c::tornadoWarpEvCamera(void) */

undefined4 __thiscall dCamera_c::tornadoWarpEvCamera(dCamera_c *this)

{
  int iVar1;
  fopAc_ac_c *pfVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  double dVar7;
  double dVar8;
  undefined8 in_f30;
  double dVar9;
  undefined8 in_f31;
  double dVar10;
  float fVar11;
  undefined2 local_258 [2];
  cSAngle acStack596 [2];
  cSAngle acStack592 [2];
  undefined auStack588 [4];
  cSAngle acStack584 [2];
  cSAngle acStack580 [2];
  cSAngle acStack576 [2];
  cSAngle acStack572 [2];
  f_pc_profile__Profile_Actor *local_238;
  cXyz cStack564;
  cXyz cStack552;
  cXyz cStack540;
  cXyz cStack528;
  cXyz cStack516;
  cXyz cStack504;
  cXyz cStack492;
  cXyz cStack480;
  cXyz cStack468;
  cXyz cStack456;
  cXyz local_1bc;
  cXyz cStack432;
  cXyz cStack420;
  cXyz cStack408;
  cXyz cStack396;
  cXyz cStack384;
  cXyz local_174;
  node_class *local_168;
  create_request *local_164;
  float local_160;
  cXyz local_15c;
  cXyz local_150;
  cXyz local_144;
  cXyz local_138;
  cXyz local_12c;
  cXyz local_120;
  cXyz local_114;
  float local_108;
  float local_104;
  float local_100;
  float local_fc;
  float local_f8;
  float local_f4;
  float local_f0;
  float local_ec;
  float local_e8;
  float local_e4;
  float local_e0;
  float local_dc;
  float local_d8;
  float local_d4;
  float local_d0;
  float local_cc;
  float local_c8;
  float local_c4;
  cXyz local_c0;
  cXyz local_b4;
  cXyz local_a8;
  cXyz local_9c;
  cXyz local_90;
  cXyz local_84;
  cXyz local_78;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  uint uStack68;
  longlong local_40;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  if (this->field_0x11c == 0) {
    *(undefined4 *)&this->field_0x378 = 0;
    *(undefined4 *)&this->field_0x37c = 0;
    *(undefined *)&this->field_0x102 = 1;
    *(undefined *)&this->field_0x101 = 1;
    *(undefined *)&this->field_0x100 = 1;
  }
  local_cc = d_ev_camera::_4862;
  local_c8 = d_ev_camera::_8902;
  local_c4 = d_ev_camera::_4862;
  local_84.x = d_ev_camera::_4862;
  local_84.y = d_ev_camera::_8902;
  local_84.z = d_ev_camera::_4862;
  local_d8 = d_ev_camera::_4862;
  local_d4 = d_ev_camera::_8896;
  local_d0 = d_ev_camera::_4862;
  local_90.x = d_ev_camera::_4862;
  local_90.y = d_ev_camera::_8896;
  local_90.z = d_ev_camera::_4862;
  local_e4 = d_ev_camera::_9864;
  local_e0 = d_ev_camera::_9865;
  local_dc = d_ev_camera::_4862;
  local_78.x = d_ev_camera::_9864;
  local_78.y = d_ev_camera::_9865;
  local_78.z = d_ev_camera::_4862;
  local_f0 = d_ev_camera::_9866;
  local_ec = d_ev_camera::_9865;
  local_e8 = d_ev_camera::_4862;
  local_6c = d_ev_camera::_9866;
  local_68 = d_ev_camera::_9865;
  local_64 = d_ev_camera::_4862;
  local_fc = d_ev_camera::_4862;
  local_f8 = d_ev_camera::_9865;
  local_f4 = d_ev_camera::_9864;
  local_60 = d_ev_camera::_4862;
  local_5c = d_ev_camera::_9865;
  local_58 = d_ev_camera::_9864;
  local_108 = d_ev_camera::_4862;
  local_104 = d_ev_camera::_9865;
  local_100 = d_ev_camera::_9866;
  local_54 = d_ev_camera::_4862;
  local_50 = d_ev_camera::_9865;
  local_4c = d_ev_camera::_9866;
  cSAngle::cSAngle(acStack572,d_ev_camera::_8898);
  iVar1 = *(int *)&this->field_0x378;
  if (iVar1 != 2) {
    if (iVar1 < 2) {
      if ((iVar1 == 0) || (iVar1 < 0)) goto LAB_800ba0e0;
    }
    else {
      if (iVar1 < 4) goto LAB_800ba65c;
LAB_800ba0e0:
      local_258[0] = 0xa7;
      pfVar2 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeForPName,local_258);
      *(fopAc_ac_c **)&this->field_0x38c = pfVar2;
      *(undefined4 *)&this->field_0x378 = 1;
      *(undefined4 *)&this->field_0x37c = 100;
      local_b4.x = d_ev_camera::_9867;
      local_b4.y = d_ev_camera::_8269;
      local_b4.z = d_ev_camera::_9868;
      relationalPos(&local_114,this,this->mpPlayerActor,&local_84);
      local_9c.x = local_114.x;
      local_9c.y = local_114.y;
      local_9c.z = local_114.z;
      if (*(char *)&this->field_0x786 == '\0') {
        iVar1 = 0;
        iVar4 = 0;
        do {
          cSAngle::cSAngle(acStack584,acStack572);
          pfVar2 = (fopAc_ac_c *)acStack584;
          relationalPos(&local_15c,this,this->mpPlayerActor,(cXyz *)((int)&local_78.x + iVar4),
                        SUB42(pfVar2,0));
          local_a8.x = local_15c.x;
          local_a8.y = local_15c.y;
          local_a8.z = local_15c.z;
          cVar3 = lineBGCheck(this,&local_9c,&local_a8,0x7f);
          if (cVar3 == '\0') {
            local_168 = (node_class *)local_9c.x;
            local_164 = (create_request *)local_9c.y;
            local_160 = local_9c.z;
            local_174.x = local_a8.x;
            local_174.y = local_a8.y;
            local_174.z = local_a8.z;
            cVar3 = @unnamed@d_ev_camera_cpp@::lineCollisionCheck
                              ((_unnamed_d_ev_camera_cpp_ *)&local_168,&local_174,
                               (cXyz *)this->mpPlayerActor,*(fopAc_ac_c **)&this->field_0x38c,pfVar2
                              );
            if (cVar3 == '\0') break;
          }
          iVar1 = iVar1 + 1;
          iVar4 = iVar4 + 0xc;
        } while (iVar1 < 4);
      }
      else {
        dVar9 = (double)d_ev_camera::_9869;
        iVar1 = 3;
        iVar4 = 0;
        iVar5 = 0;
        dVar10 = (double)d_ev_camera::_4862;
        do {
          cSAngle::cSAngle(acStack576,acStack572);
          relationalPos(&local_120,this,this->mpPlayerActor,(cXyz *)((int)&local_78.x + iVar5),
                        (cSAngle)((short)register0x00000004 + -0x240));
          local_a8.x = local_120.x;
          local_a8.y = local_120.y;
          local_a8.z = local_120.z;
          ::cXyz::operator__(&local_12c,&local_a8,&local_b4);
          local_138.x = local_12c.x;
          local_138.y = local_12c.y;
          local_138.z = local_12c.z;
          fVar11 = mtx::PSVECSquareMag(&local_138);
          dVar8 = (double)fVar11;
          if (dVar10 < dVar8) {
            dVar7 = 1.0 / SQRT(dVar8);
            dVar7 = d_ev_camera::_4863 * dVar7 * (d_ev_camera::_4864 - dVar8 * dVar7 * dVar7);
            dVar7 = d_ev_camera::_4863 * dVar7 * (d_ev_camera::_4864 - dVar8 * dVar7 * dVar7);
            local_238 = (f_pc_profile__Profile_Actor *)
                        (float)(dVar8 * d_ev_camera::_4863 * dVar7 *
                                        (d_ev_camera::_4864 - dVar8 * dVar7 * dVar7));
            dVar8 = (double)(float)local_238;
          }
          if (dVar8 < dVar9) {
            iVar1 = iVar4;
            dVar9 = dVar8;
          }
          iVar4 = iVar4 + 1;
          iVar5 = iVar5 + 0xc;
        } while (iVar4 < 4);
        cSAngle::cSAngle(acStack580,acStack572);
        dCamMath::xyzRotateY
                  (&local_144,(cSAngle)((short)register0x00000004 + -0x78 + (short)iVar1 * 0xc));
        local_c0.x = local_144.x;
        local_c0.y = local_144.y;
        local_c0.z = local_144.z;
        relationalPos(&local_150,this,this->mpPlayerActor,&local_c0);
        local_a8.x = local_150.x;
        local_a8.y = local_150.y;
        local_a8.z = local_150.z;
      }
      *(float *)&this->field_0x380 = local_a8.x;
      *(float *)&this->field_0x384 = local_a8.y;
      *(float *)&this->field_0x388 = local_a8.z;
    }
    relationalPos(&cStack384,this,this->mpPlayerActor,&local_84);
    ::cXyz::operator__(&cStack396,&cStack384,&this->field_0x44);
    ::cXyz::operator_(&cStack408,&cStack396,d_ev_camera::_9870);
    mtx::PSVECAdd(&this->field_0x44,&cStack408,&this->field_0x44);
    uStack68 = *(uint *)&this->field_0x37c ^ 0x80000000;
    local_48 = 176.0;
    dVar9 = (double)(d_ev_camera::_5486 /
                    (float)((double)CONCAT44(0x43300000,uStack68) - d_ev_camera::_5609));
    ::cXyz::operator__(&cStack420,(cXyz *)&this->field_0x380,&this->field_0x50);
    ::cXyz::operator_(&cStack432,&cStack420,(float)dVar9);
    ::cXyz::operator__(&local_1bc,&this->field_0x50,&cStack432);
    local_a8.x = local_1bc.x;
    local_a8.y = local_1bc.y;
    local_a8.z = local_1bc.z;
    ::cXyz::operator__(&cStack456,&local_a8,&this->field_0x50);
    ::cXyz::operator_(&cStack468,&cStack456,d_ev_camera::_9871);
    mtx::PSVECAdd(&this->field_0x50,&cStack468,&this->field_0x50);
    fVar11 = this->field_0x60;
    this->field_0x60 =
         fVar11 + d_ev_camera::_9871 *
                  ((fVar11 + (float)(dVar9 * (double)(d_ev_camera::_8279 - fVar11))) - fVar11);
    ::cXyz::operator__(&cStack480,&this->field_0x50,&this->field_0x44);
    cSGlobe::Val(&this->field_0x3c,&cStack480);
    fVar11 = SComponent::cM_rndFX((float)((double)d_ev_camera::_9872 * dVar9));
    local_40 = (longlong)(int)(d_ev_camera::_4865 * fVar11);
    SComponent::operator__(auStack588,(int)(d_ev_camera::_4865 * fVar11),&this->field_0x5c);
    cSAngle::operator_(acStack592,d_ev_camera::_9871);
    cSAngle::operator___((cSAngle *)&this->field_0x5c,acStack592);
    this->mEventFlags = this->mEventFlags | 0x400;
    iVar1 = *(int *)&this->field_0x37c + -1;
    *(int *)&this->field_0x37c = iVar1;
    if (iVar1 != 0) goto LAB_800ba65c;
    *(undefined4 *)&this->field_0x378 = 2;
    *(undefined4 *)&this->field_0x37c = 200;
  }
  relationalPos(&cStack492,this,this->mpPlayerActor,&local_90);
  ::cXyz::operator__(&cStack504,&cStack492,&this->field_0x44);
  ::cXyz::operator_(&cStack516,&cStack504,d_ev_camera::_9870);
  mtx::PSVECAdd(&this->field_0x44,&cStack516,&this->field_0x44);
  local_a8.x = *(float *)&this->field_0x380;
  local_a8.y = *(float *)&this->field_0x384;
  local_a8.z = *(float *)&this->field_0x388;
  attentionPos(&cStack528,this,this->mpPlayerActor);
  local_a8.y = cStack528.y;
  ::cXyz::operator__(&cStack540,&local_a8,&this->field_0x50);
  ::cXyz::operator_(&cStack552,&cStack540,d_ev_camera::_9360);
  mtx::PSVECAdd(&this->field_0x50,&cStack552,&this->field_0x50);
  this->field_0x60 = this->field_0x60 + d_ev_camera::_9360 * (d_ev_camera::_9355 - this->field_0x60)
  ;
  ::cXyz::operator__(&cStack564,&this->field_0x50,&this->field_0x44);
  cSGlobe::Val(&this->field_0x3c,&cStack564);
  cSAngle::operator_(acStack596,d_ev_camera::_9359);
  cSAngle::operator___((cSAngle *)&this->field_0x5c,acStack596);
  this->mEventFlags = this->mEventFlags | 0x400;
  iVar1 = *(int *)&this->field_0x37c + -1;
  *(int *)&this->field_0x37c = iVar1;
  if (iVar1 == 0) {
    *(undefined4 *)&this->field_0x378 = 3;
  }
LAB_800ba65c:
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  __psq_l0(auStack24,uVar6);
  __psq_l1(auStack24,uVar6);
  return 1;
}


/* __thiscall dCamera_c::saveEvCamera(void) */

undefined4 __thiscall dCamera_c::saveEvCamera(dCamera_c *this)

{
  _class_4017d_camera_cpp *p_Var1;
  float *pfVar2;
  int local_18 [5];
  
  getEvIntData(this,local_18,"Slot",0);
  if (local_18[0] == 9) {
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0]._48_2_ = this->field_0x5c;
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0]._44_4_ = this->field_0x60;
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0]._20_4_ = (this->field_0x44).x;
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0]._24_4_ = (this->field_0x44).y;
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0]._28_4_ = (this->field_0x44).z;
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0]._32_4_ = (this->field_0x50).x;
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0]._36_4_ = (this->field_0x50).y;
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0]._40_4_ = (this->field_0x50).z;
  }
  else {
    p_Var1 = this->field_0xa4 + local_18[0];
    *(float *)p_Var1 = (this->field_0x44).x;
    *(float *)&p_Var1->field_0x4 = (this->field_0x44).y;
    *(float *)&p_Var1->field_0x8 = (this->field_0x44).z;
    pfVar2 = (float *)&this->field_0xa4[local_18[0]].field_0xc;
    *pfVar2 = (this->field_0x50).x;
    pfVar2[1] = (this->field_0x50).y;
    pfVar2[2] = (this->field_0x50).z;
    *(float *)&this->field_0xa4[local_18[0]].field_0x18 = this->field_0x60;
    *(short *)&this->field_0xa4[local_18[0]].field_0x1c = this->field_0x5c;
    *(undefined2 *)&this->field_0xa4[local_18[0]].field_0x1e = 1;
  }
  *(undefined *)&this->field_0x102 = 1;
  *(undefined *)&this->field_0x101 = 1;
  *(undefined *)&this->field_0x100 = 1;
  return 1;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall dCamera_c::loadEvCamera(void) */

undefined4 __thiscall dCamera_c::loadEvCamera(dCamera_c *this)

{
  _class_4017d_camera_cpp *p_Var1;
  float *pfVar2;
  cSAngle local_28 [2];
  int local_24;
  cXyz acStack32 [2];
  
  getEvIntData(this,&local_24,"Slot",0);
  if (local_24 == 9) {
    (this->field_0x44).x = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0]._20_4_;
    (this->field_0x44).y = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0]._24_4_;
    (this->field_0x44).z = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0]._28_4_;
    (this->field_0x50).x = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0]._32_4_;
    (this->field_0x50).y = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0]._36_4_;
    (this->field_0x50).z = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0]._40_4_;
    this->field_0x60 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0]._44_4_;
    cSAngle::cSAngle(local_28,d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0]._48_2_);
    ((cSAngle *)&this->field_0x5c)->v = local_28[0];
  }
  else {
    p_Var1 = this->field_0xa4 + local_24;
    (this->field_0x44).x = *(float *)p_Var1;
    (this->field_0x44).y = *(float *)&p_Var1->field_0x4;
    (this->field_0x44).z = *(float *)&p_Var1->field_0x8;
    pfVar2 = (float *)&this->field_0xa4[local_24].field_0xc;
    (this->field_0x50).x = *pfVar2;
    (this->field_0x50).y = pfVar2[1];
    (this->field_0x50).z = pfVar2[2];
    this->field_0x60 = *(float *)&this->field_0xa4[local_24].field_0x18;
    this->field_0x5c = *(short *)&this->field_0xa4[local_24].field_0x1c;
    ::cXyz::operator__(acStack32,&this->field_0x50,&this->field_0x44);
    cSGlobe::Val(&this->field_0x3c,acStack32);
  }
  *(undefined *)&this->field_0x102 = 1;
  *(undefined *)&this->field_0x101 = 1;
  *(undefined *)&this->field_0x100 = 1;
  return 1;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* WARNING: Removing unreachable block (ram,0x800bb374) */
/* WARNING: Removing unreachable block (ram,0x800bb37c) */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall dCamera_c::useItem0EvCamera(void) */

undefined4 __thiscall dCamera_c::useItem0EvCamera(dCamera_c *this)

{
  float *pfVar1;
  undefined4 *puVar2;
  float **ppfVar3;
  undefined4 *puVar4;
  float **ppfVar5;
  float *pfVar6;
  undefined4 uVar7;
  float fVar8;
  char cVar9;
  float *pfVar10;
  float **ppfVar11;
  undefined4 *puVar12;
  float *pfVar13;
  float **ppfVar14;
  undefined4 *puVar15;
  fopAc_ac_c *in_r7;
  fopAc_ac_c *pfVar16;
  int iVar17;
  int iVar18;
  undefined4 uVar19;
  undefined8 in_f30;
  double dVar20;
  undefined8 in_f31;
  double dVar21;
  undefined2 local_418 [2];
  cSAngle acStack1044 [2];
  cSAngle acStack1040 [2];
  cSAngle acStack1036 [2];
  cSAngle acStack1032 [2];
  cSAngle local_404 [2];
  cSAngle local_400 [2];
  cXyz local_3fc;
  cXyz cStack1008;
  cXyz local_3e4;
  cXyz local_3d8;
  cXyz cStack972;
  cXyz local_3c0;
  cXyz local_3b4;
  cXyz cStack936;
  cXyz cStack924;
  cXyz cStack912;
  cXyz local_384;
  cXyz cStack888;
  cXyz local_36c;
  undefined4 local_360;
  undefined4 local_35c;
  undefined4 local_358;
  cXyz cStack852;
  cXyz cStack840;
  cXyz local_33c;
  cXyz local_330;
  float local_324;
  float local_320;
  float local_31c;
  float local_318;
  float local_314;
  float local_310;
  float local_30c;
  float local_308;
  float local_304;
  float local_300;
  float local_2fc;
  float local_2f8;
  float local_2f4;
  float local_2f0;
  float local_2ec;
  float local_2e8;
  float local_2e4;
  float local_2e0;
  float local_2dc;
  float local_2d8;
  float local_2d4;
  float local_2d0;
  float local_2cc;
  float local_2c8;
  float local_2c4;
  float local_2c0;
  float local_2bc;
  float local_2b8;
  float local_2b4;
  float local_2b0;
  float local_2ac;
  float local_2a8;
  float local_2a4;
  float local_2a0;
  float local_29c;
  float local_298;
  float local_294;
  float local_290;
  float local_28c;
  float local_288;
  float local_284;
  float local_280;
  float local_27c;
  float local_278;
  float local_274;
  float local_270;
  float local_26c;
  float local_268;
  float local_264;
  float local_260;
  float local_25c;
  float local_258;
  float local_254;
  float local_250;
  float local_24c;
  float local_248;
  float local_244;
  float local_240;
  float local_23c;
  float local_238;
  cXyz local_234;
  float local_228;
  float local_224;
  float local_220;
  float local_21c;
  float local_218;
  float local_214;
  float local_210;
  float local_20c;
  float local_208;
  cXyz local_204;
  float local_1f8;
  float local_1f4;
  float local_1f0;
  float local_1ec;
  float local_1e8;
  float local_1e4;
  float local_1e0 [6];
  undefined4 uStack456;
  undefined4 local_1c4 [6];
  undefined4 uStack428;
  undefined4 local_1a8 [6];
  undefined4 uStack400;
  int local_18c [6];
  undefined4 uStack372;
  float *local_170 [6];
  float *local_158;
  cXyz *local_154;
  float *local_150;
  cXyz *local_14c;
  float *local_148;
  float *local_144;
  float *local_140;
  float *local_13c;
  float local_138;
  float local_134;
  float local_130;
  float local_12c;
  float local_128;
  float local_124;
  float local_120;
  float local_11c;
  float local_118;
  float local_114;
  float local_110;
  float local_10c;
  float local_108;
  float local_104;
  float local_100;
  float local_fc;
  float local_f8;
  float local_f4;
  float local_f0;
  float local_ec;
  float local_e8;
  float local_e4;
  float local_e0;
  float local_dc;
  float local_d8;
  float local_d4;
  float local_d0;
  float local_cc;
  float local_c8;
  float local_c4;
  float local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  float local_a8;
  float local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  undefined4 local_50;
  uint uStack76;
  undefined4 local_48;
  uint uStack68;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar19 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  local_1ec = d_ev_camera::_10300;
  local_1e8 = d_ev_camera::_10301;
  local_1e4 = d_ev_camera::_10302;
  local_24c = d_ev_camera::_10303;
  local_248 = d_ev_camera::_10304;
  local_244 = d_ev_camera::_10305;
  local_138 = d_ev_camera::_10303;
  local_134 = d_ev_camera::_10304;
  local_130 = d_ev_camera::_10305;
  local_258 = d_ev_camera::_10306;
  local_254 = d_ev_camera::_10307;
  local_250 = d_ev_camera::_10308;
  local_12c = d_ev_camera::_10306;
  local_128 = d_ev_camera::_10307;
  local_124 = d_ev_camera::_10308;
  local_1f8 = d_ev_camera::_4862;
  local_1f4 = d_ev_camera::_10309;
  local_1f0 = d_ev_camera::_8291;
  local_264 = d_ev_camera::_10310;
  local_260 = d_ev_camera::_8892;
  local_25c = d_ev_camera::_10311;
  local_84 = d_ev_camera::_10310;
  local_80 = d_ev_camera::_8892;
  local_7c = d_ev_camera::_10311;
  local_270 = d_ev_camera::_10312;
  local_26c = d_ev_camera::_10313;
  local_268 = d_ev_camera::_10310;
  local_78 = d_ev_camera::_10312;
  local_74 = d_ev_camera::_10313;
  local_70 = d_ev_camera::_10310;
  local_27c = d_ev_camera::_8964;
  local_278 = d_ev_camera::_10314;
  local_274 = d_ev_camera::_10315;
  local_6c = d_ev_camera::_8964;
  local_68 = d_ev_camera::_10314;
  local_64 = d_ev_camera::_10315;
  local_288 = d_ev_camera::_10316;
  local_284 = d_ev_camera::_10317;
  local_280 = d_ev_camera::_8279;
  local_60 = d_ev_camera::_10316;
  local_5c = d_ev_camera::_10317;
  local_58 = d_ev_camera::_8279;
  local_204.x = d_ev_camera::_4862;
  local_204.y = d_ev_camera::_8902;
  local_204.z = d_ev_camera::_10318;
  local_294 = d_ev_camera::_10319;
  local_290 = d_ev_camera::_8896;
  local_28c = d_ev_camera::_10320;
  local_a8 = d_ev_camera::_10319;
  local_a4 = d_ev_camera::_8896;
  local_a0 = d_ev_camera::_10320;
  local_2a0 = d_ev_camera::_10321;
  local_29c = d_ev_camera::_8890;
  local_298 = d_ev_camera::_8905;
  local_9c = d_ev_camera::_10321;
  local_98 = d_ev_camera::_8890;
  local_94 = d_ev_camera::_8905;
  local_2ac = d_ev_camera::_8274;
  local_2a8 = d_ev_camera::_10321;
  local_2a4 = d_ev_camera::_8901;
  local_90 = d_ev_camera::_8274;
  local_8c = d_ev_camera::_10321;
  local_88 = d_ev_camera::_8901;
  local_210 = d_ev_camera::_4862;
  local_20c = d_ev_camera::_10322;
  local_208 = d_ev_camera::_10318;
  local_2b8 = d_ev_camera::_9354;
  local_2b4 = d_ev_camera::_8900;
  local_2b0 = d_ev_camera::_10323;
  local_d8 = d_ev_camera::_9354;
  local_d4 = d_ev_camera::_8900;
  local_d0 = d_ev_camera::_10323;
  local_2c4 = d_ev_camera::_10321;
  local_2c0 = d_ev_camera::_10324;
  local_2bc = d_ev_camera::_10325;
  local_cc = d_ev_camera::_10321;
  local_c8 = d_ev_camera::_10324;
  local_c4 = d_ev_camera::_10325;
  local_2d0 = d_ev_camera::_8274;
  local_2cc = d_ev_camera::_10321;
  local_2c8 = d_ev_camera::_8901;
  local_c0 = d_ev_camera::_8274;
  local_bc = d_ev_camera::_10321;
  local_b8 = d_ev_camera::_8901;
  local_2dc = d_ev_camera::_10326;
  local_2d8 = d_ev_camera::_8892;
  local_2d4 = d_ev_camera::_10327;
  local_b4 = d_ev_camera::_10326;
  local_b0 = d_ev_camera::_8892;
  local_ac = d_ev_camera::_10327;
  local_21c = d_ev_camera::_10328;
  local_218 = d_ev_camera::_10329;
  local_214 = d_ev_camera::_10330;
  local_2e8 = d_ev_camera::_10331;
  local_2e4 = d_ev_camera::_10332;
  local_2e0 = d_ev_camera::_10333;
  local_fc = d_ev_camera::_10331;
  local_f8 = d_ev_camera::_10332;
  local_f4 = d_ev_camera::_10333;
  local_2f4 = d_ev_camera::_10334;
  local_2f0 = d_ev_camera::_10335;
  local_2ec = d_ev_camera::_10336;
  local_f0 = d_ev_camera::_10334;
  local_ec = d_ev_camera::_10335;
  local_e8 = d_ev_camera::_10336;
  local_300 = d_ev_camera::_10331;
  local_2fc = d_ev_camera::_10332;
  local_2f8 = d_ev_camera::_10333;
  local_e4 = d_ev_camera::_10331;
  local_e0 = d_ev_camera::_10332;
  local_dc = d_ev_camera::_10333;
  local_228 = d_ev_camera::_10337;
  local_224 = d_ev_camera::_10338;
  local_220 = d_ev_camera::_10311;
  local_30c = d_ev_camera::_10339;
  local_308 = d_ev_camera::_10340;
  local_304 = d_ev_camera::_10341;
  local_120 = d_ev_camera::_10339;
  local_11c = d_ev_camera::_10340;
  local_118 = d_ev_camera::_10341;
  local_318 = d_ev_camera::_10342;
  local_314 = d_ev_camera::_10343;
  local_310 = d_ev_camera::_10344;
  local_114 = d_ev_camera::_10342;
  local_110 = d_ev_camera::_10343;
  local_10c = d_ev_camera::_10344;
  local_324 = d_ev_camera::_10345;
  local_320 = d_ev_camera::_10346;
  local_31c = d_ev_camera::_10347;
  local_108 = d_ev_camera::_10345;
  local_104 = d_ev_camera::_10346;
  local_100 = d_ev_camera::_10347;
  iVar18 = 3;
  ppfVar3 = (float **)&UNK_80359b8c;
  ppfVar5 = &local_158;
  do {
    ppfVar14 = ppfVar5;
    ppfVar11 = ppfVar3;
    pfVar6 = ppfVar11[2];
    ppfVar14[1] = ppfVar11[1];
    ppfVar14[2] = pfVar6;
    iVar18 = iVar18 + -1;
    ppfVar3 = ppfVar11 + 2;
    ppfVar5 = ppfVar14 + 2;
  } while (iVar18 != 0);
  ppfVar14[3] = ppfVar11[3];
  local_154 = &local_204;
  local_150 = &local_1f8;
  local_14c = &local_204;
  local_148 = &local_210;
  local_144 = &local_1ec;
  local_140 = &local_21c;
  local_13c = &local_228;
  iVar18 = 3;
  puVar2 = (undefined4 *)&UNK_80359ba8;
  puVar4 = &uStack372;
  do {
    puVar15 = puVar4;
    puVar12 = puVar2;
    uVar7 = puVar12[2];
    puVar15[1] = puVar12[1];
    puVar15[2] = uVar7;
    iVar18 = iVar18 + -1;
    puVar2 = puVar12 + 2;
    puVar4 = puVar15 + 2;
  } while (iVar18 != 0);
  puVar15[3] = puVar12[3];
  local_170[0] = &local_a8;
  local_170[1] = &local_84;
  local_170[2] = &local_a8;
  local_170[3] = &local_d8;
  local_170[4] = &local_138;
  local_170[5] = &local_fc;
  local_158 = &local_120;
  iVar18 = 3;
  puVar2 = (undefined4 *)&UNK_80359bc4;
  puVar4 = &uStack400;
  do {
    puVar15 = puVar4;
    puVar12 = puVar2;
    uVar7 = puVar12[2];
    puVar15[1] = puVar12[1];
    puVar15[2] = uVar7;
    iVar18 = iVar18 + -1;
    puVar2 = puVar12 + 2;
    puVar4 = puVar15 + 2;
  } while (iVar18 != 0);
  puVar15[3] = puVar12[3];
  iVar18 = 3;
  puVar2 = (undefined4 *)&UNK_80359be0;
  puVar4 = &uStack428;
  do {
    puVar15 = puVar4;
    puVar12 = puVar2;
    uVar7 = puVar12[2];
    puVar15[1] = puVar12[1];
    puVar15[2] = uVar7;
    iVar18 = iVar18 + -1;
    puVar2 = puVar12 + 2;
    puVar4 = puVar15 + 2;
  } while (iVar18 != 0);
  puVar15[3] = puVar12[3];
  iVar18 = 3;
  puVar2 = (undefined4 *)&UNK_80359bfc;
  puVar4 = &uStack456;
  do {
    puVar15 = puVar4;
    puVar12 = puVar2;
    uVar7 = puVar12[2];
    puVar15[1] = puVar12[1];
    puVar15[2] = uVar7;
    iVar18 = iVar18 + -1;
    puVar2 = puVar12 + 2;
    puVar4 = puVar15 + 2;
  } while (iVar18 != 0);
  puVar15[3] = puVar12[3];
  iVar18 = 3;
  pfVar6 = (float *)&UNK_80359c18;
  pfVar1 = &local_1e4;
  do {
    pfVar13 = pfVar1;
    pfVar10 = pfVar6;
    fVar8 = pfVar10[2];
    pfVar13[1] = pfVar10[1];
    pfVar13[2] = fVar8;
    iVar18 = iVar18 + -1;
    pfVar6 = pfVar10 + 2;
    pfVar1 = pfVar13 + 2;
  } while (iVar18 != 0);
  pfVar13[3] = pfVar10[3];
  uVar7 = 0;
  if (this->field_0x11c == 0) {
    *(undefined4 *)&this->field_0x378 = 0;
  }
  iVar18 = *(int *)&this->field_0x378;
  if (iVar18 == 10) {
LAB_800bae1c:
    *(undefined4 *)&this->field_0x378 = 10;
    fVar8 = (float)((int)this->mEvBank + 1);
    this->mEvBank = fVar8;
    if ((int)local_1e0[*(int *)&this->field_0x380] <= (int)fVar8) {
      this->mEvBank = 0.0;
      if ((((*(uint *)&this->field_0x7c & 7) == 0) &&
          (iVar18 = *(int *)&this->field_0x380, iVar18 < 4)) && (1 < iVar18)) {
        pfVar6 = local_170[iVar18];
        local_240 = *pfVar6;
        local_23c = pfVar6[1];
        local_238 = pfVar6[2];
        *pfVar6 = pfVar6[3];
        pfVar6[1] = pfVar6[4];
        pfVar6[2] = pfVar6[5];
        pfVar6 = local_170[*(int *)&this->field_0x380];
        pfVar6[3] = local_240;
        pfVar6[4] = local_23c;
        pfVar6[5] = local_238;
      }
      relationalPos(&local_330,this,this->mpPlayerActor,(&local_154)[*(int *)&this->field_0x380]);
      *(float *)&this->field_0x384 = local_330.x;
      *(float *)&this->field_0x388 = local_330.y;
      *(float *)&this->field_0x38c = local_330.z;
      iVar18 = 0;
      for (iVar17 = 0; iVar17 < local_18c[*(int *)&this->field_0x380]; iVar17 = iVar17 + 1) {
        relationalPos(&local_33c,this,this->mpPlayerActor,
                      (cXyz *)((int)local_170[*(int *)&this->field_0x380] + iVar18));
        local_234.x = local_33c.x;
        local_234.y = local_33c.y;
        local_234.z = local_33c.z;
        positionOf(&cStack840,this,this->mpPlayerActor);
        if (local_234.y < *(float *)&this->field_0x368 + cStack840.y) {
          positionOf(&cStack852,this,this->mpPlayerActor);
          local_234.y = *(float *)&this->field_0x368 + cStack852.y;
        }
        pfVar16 = (fopAc_ac_c *)0x0;
        if (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4] & 0x10000U) != 0)
        {
          local_418[0] = 0xa7;
          pfVar16 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeForPName,local_418);
        }
        cVar9 = lineBGCheck(this,(cXyz *)&this->field_0x384,&local_234,0x8f);
        if (cVar9 == '\0') {
          local_360 = *(undefined4 *)&this->field_0x384;
          local_35c = *(undefined4 *)&this->field_0x388;
          local_358 = *(undefined4 *)&this->field_0x38c;
          local_36c.x = local_234.x;
          local_36c.y = local_234.y;
          local_36c.z = local_234.z;
          cVar9 = @unnamed@d_ev_camera_cpp@::lineCollisionCheck
                            ((_unnamed_d_ev_camera_cpp_ *)&local_360,&local_36c,
                             (cXyz *)this->mpPlayerActor,pfVar16,in_r7);
          if (cVar9 == '\0') break;
        }
        iVar18 = iVar18 + 0xc;
      }
      ::cXyz::operator__(&cStack888,&local_234,(cXyz *)&this->field_0x384);
      cSGlobe::Val((cSGlobe *)&this->mpEvRelActor,&cStack888);
      *(undefined4 *)&this->field_0x390 = local_1a8[*(int *)&this->field_0x380];
      *(undefined4 *)&this->field_0x37c = local_1c4[*(int *)&this->field_0x380];
      *(undefined4 *)&this->field_0x378 = 1;
    }
  }
  else {
    if (iVar18 < 10) {
      if (iVar18 == 1) {
        uStack76 = (uint)this->mEvBank ^ 0x80000000;
        local_50 = 0x43300000;
        uStack68 = *(uint *)&this->field_0x37c ^ 0x80000000;
        local_48 = 0x43300000;
        dVar21 = (double)((float)((double)CONCAT44(0x43300000,uStack76) - d_ev_camera::_5609) /
                         (float)((double)CONCAT44(0x43300000,uStack68) - d_ev_camera::_5609));
        this->field_0x60 =
             this->field_0x60 +
             (float)(dVar21 * (double)(*(float *)&this->field_0x390 - this->field_0x60));
        relationalPos(&local_384,this,this->mpPlayerActor,(&local_154)[*(int *)&this->field_0x380]);
        *(float *)&this->field_0x384 = local_384.x;
        *(float *)&this->field_0x388 = local_384.y;
        *(float *)&this->field_0x38c = local_384.z;
        ::cXyz::operator__(&cStack912,(cXyz *)&this->field_0x384,&this->field_0x44);
        ::cXyz::operator_(&cStack924,&cStack912,(float)dVar21);
        mtx::PSVECAdd(&this->field_0x44,&cStack924,&this->field_0x44);
        fVar8 = (this->field_0x3c).mDistance;
        local_404[0] = (this->field_0x3c).mAngleX.v;
        local_400[0] = (this->field_0x3c).mAngleY.v;
        dVar20 = (double)(fVar8 + (float)(dVar21 * (double)((float)this->mpEvRelActor - fVar8)));
        cSAngle::operator__(acStack1032,(cSAngle *)this->mEvRelUseMask);
        cSAngle::operator_(acStack1036,(float)dVar21);
        cSAngle::operator___(local_404,acStack1036);
        cSAngle::operator__(acStack1040,(cSAngle *)(this->mEvRelUseMask + 2));
        cSAngle::operator_(acStack1044,(float)dVar21);
        cSAngle::operator___(local_400,acStack1044);
        cSGlobe::Val(&this->field_0x3c,(float)dVar20,local_404,local_400);
        cSGlobe::Xyz(&cStack936,&this->field_0x3c);
        ::cXyz::operator__(&local_3b4,&this->field_0x44,&cStack936);
        (this->field_0x50).x = local_3b4.x;
        (this->field_0x50).y = local_3b4.y;
        (this->field_0x50).z = local_3b4.z;
        if ((int)this->mEvBank < *(int *)&this->field_0x37c) goto LAB_800bb364;
        *(undefined4 *)&this->field_0x378 = 2;
      }
      else {
        if ((iVar18 < 1) || (2 < iVar18)) goto LAB_800badf4;
      }
      relationalPos(&local_3c0,this,this->mpPlayerActor,(&local_154)[*(int *)&this->field_0x380]);
      (this->field_0x44).x = local_3c0.x;
      (this->field_0x44).y = local_3c0.y;
      (this->field_0x44).z = local_3c0.z;
      cSGlobe::Xyz(&cStack972,&this->field_0x3c);
      ::cXyz::operator__(&local_3d8,&this->field_0x44,&cStack972);
      (this->field_0x50).x = local_3d8.x;
      (this->field_0x50).y = local_3d8.y;
      (this->field_0x50).z = local_3d8.z;
      this->mEvFovy = (float)((int)this->mEvFovy + 1);
      if ((*(int *)&this->field_0x380 == 0) && (this->mEvFovy == 1.401298e-45)) {
        *(undefined4 *)&this->field_0x378 = 10;
        *(undefined4 *)&this->field_0x380 = 4;
        goto LAB_800bb364;
      }
      *(undefined4 *)&this->field_0x378 = 99;
    }
    else {
      if (iVar18 != 99) {
LAB_800badf4:
        getEvIntData(this,(int *)&this->field_0x380,"Type",0);
        this->mEvFovy = 0.0;
        this->mEvBank = 0.0;
        goto LAB_800bae1c;
      }
    }
    *(undefined *)&this->field_0x102 = 1;
    *(undefined *)&this->field_0x101 = 1;
    *(undefined *)&this->field_0x100 = 1;
    relationalPos(&local_3e4,this,this->mpPlayerActor,(&local_154)[*(int *)&this->field_0x380]);
    (this->field_0x44).x = local_3e4.x;
    (this->field_0x44).y = local_3e4.y;
    (this->field_0x44).z = local_3e4.z;
    cSGlobe::Xyz(&cStack1008,&this->field_0x3c);
    ::cXyz::operator__(&local_3fc,&this->field_0x44,&cStack1008);
    (this->field_0x50).x = local_3fc.x;
    (this->field_0x50).y = local_3fc.y;
    (this->field_0x50).z = local_3fc.z;
    uVar7 = 1;
  }
LAB_800bb364:
  this->mEvBank = (float)((int)this->mEvBank + 1);
  __psq_l0(auStack8,uVar19);
  __psq_l1(auStack8,uVar19);
  __psq_l0(auStack24,uVar19);
  __psq_l1(auStack24,uVar19);
  return uVar7;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x800bbd60) */
/* WARNING: Removing unreachable block (ram,0x800bbd68) */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall dCamera_c::useItem1EvCamera(void) */

undefined4 __thiscall dCamera_c::useItem1EvCamera(dCamera_c *this)

{
  float *pfVar1;
  undefined4 *puVar2;
  float **ppfVar3;
  undefined4 *puVar4;
  float **ppfVar5;
  float *pfVar6;
  undefined4 uVar7;
  float fVar8;
  char cVar9;
  float *pfVar10;
  float **ppfVar11;
  undefined4 *puVar12;
  float *pfVar13;
  float **ppfVar14;
  undefined4 *puVar15;
  fopAc_ac_c *in_r7;
  int iVar16;
  int iVar17;
  undefined4 uVar18;
  undefined8 in_f30;
  double dVar19;
  undefined8 in_f31;
  double dVar20;
  cSAngle acStack1016 [2];
  cSAngle acStack1012 [2];
  cSAngle acStack1008 [2];
  cSAngle acStack1004 [2];
  cSAngle local_3e8 [2];
  cSAngle local_3e4 [2];
  cXyz local_3e0;
  cXyz cStack980;
  cXyz local_3c8;
  cXyz local_3bc;
  cXyz cStack944;
  cXyz local_3a4;
  cXyz local_398;
  cXyz cStack908;
  cXyz cStack896;
  cXyz cStack884;
  cXyz local_368;
  cXyz cStack860;
  cXyz local_350;
  undefined4 local_344;
  undefined4 local_340;
  undefined4 local_33c;
  cXyz cStack824;
  cXyz cStack812;
  cXyz local_320;
  cXyz local_314;
  float local_308;
  float local_304;
  float local_300;
  float local_2fc;
  float local_2f8;
  float local_2f4;
  float local_2f0;
  float local_2ec;
  float local_2e8;
  float local_2e4;
  float local_2e0;
  float local_2dc;
  float local_2d8;
  float local_2d4;
  float local_2d0;
  float local_2cc;
  float local_2c8;
  float local_2c4;
  float local_2c0;
  float local_2bc;
  float local_2b8;
  float local_2b4;
  float local_2b0;
  float local_2ac;
  float local_2a8;
  float local_2a4;
  float local_2a0;
  float local_29c;
  float local_298;
  float local_294;
  float local_290;
  float local_28c;
  float local_288;
  float local_284;
  float local_280;
  float local_27c;
  float local_278;
  float local_274;
  float local_270;
  float local_26c;
  float local_268;
  float local_264;
  float local_260;
  float local_25c;
  float local_258;
  float local_254;
  float local_250;
  float local_24c;
  float local_248;
  float local_244;
  float local_240;
  float local_23c;
  float local_238;
  float local_234;
  float local_230;
  float local_22c;
  float local_228;
  float local_224;
  float local_220;
  float local_21c;
  cXyz local_218;
  float local_20c;
  float local_208;
  float local_204;
  float local_200;
  float local_1fc;
  float local_1f8;
  float local_1f4;
  float local_1f0;
  float local_1ec;
  cXyz local_1e8;
  float local_1dc;
  float local_1d8;
  float local_1d4;
  float local_1d0;
  float local_1cc;
  float local_1c8;
  float local_1c4 [6];
  undefined4 uStack428;
  undefined4 local_1a8 [6];
  undefined4 uStack400;
  int local_18c [6];
  undefined4 uStack372;
  float *local_170 [6];
  float *local_158;
  cXyz *local_154;
  float *local_150;
  cXyz *local_14c;
  float *local_148;
  float *local_144;
  float *local_140;
  float *local_13c;
  float local_138;
  float local_134;
  float local_130;
  float local_12c;
  float local_128;
  float local_124;
  float local_120;
  float local_11c;
  float local_118;
  float local_114;
  float local_110;
  float local_10c;
  float local_108;
  float local_104;
  float local_100;
  float local_fc;
  float local_f8;
  float local_f4;
  float local_f0;
  float local_ec;
  float local_e8;
  float local_e4;
  float local_e0;
  float local_dc;
  float local_d8;
  float local_d4;
  float local_d0;
  float local_cc;
  float local_c8;
  float local_c4;
  float local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  float local_a8;
  float local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  undefined4 local_50;
  uint uStack76;
  undefined4 local_48;
  uint uStack68;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar18 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  local_1d0 = d_ev_camera::_4862;
  local_1cc = d_ev_camera::_10712;
  local_1c8 = d_ev_camera::_10713;
  local_230 = d_ev_camera::_10714;
  local_22c = d_ev_camera::_8964;
  local_228 = d_ev_camera::_10715;
  local_78 = d_ev_camera::_10714;
  local_74 = d_ev_camera::_8964;
  local_70 = d_ev_camera::_10715;
  local_23c = d_ev_camera::_10714;
  local_238 = d_ev_camera::_10716;
  local_234 = d_ev_camera::_9356;
  local_6c = d_ev_camera::_10714;
  local_68 = d_ev_camera::_10716;
  local_64 = d_ev_camera::_9356;
  local_248 = d_ev_camera::_9353;
  local_244 = d_ev_camera::_10717;
  local_240 = d_ev_camera::_8275;
  local_60 = d_ev_camera::_9353;
  local_5c = d_ev_camera::_10717;
  local_58 = d_ev_camera::_8275;
  local_1dc = d_ev_camera::_4862;
  local_1d8 = d_ev_camera::_10309;
  local_1d4 = d_ev_camera::_8291;
  local_254 = d_ev_camera::_10310;
  local_250 = d_ev_camera::_8892;
  local_24c = d_ev_camera::_10311;
  local_a8 = d_ev_camera::_10310;
  local_a4 = d_ev_camera::_8892;
  local_a0 = d_ev_camera::_10311;
  local_260 = d_ev_camera::_10312;
  local_25c = d_ev_camera::_10313;
  local_258 = d_ev_camera::_10310;
  local_9c = d_ev_camera::_10312;
  local_98 = d_ev_camera::_10313;
  local_94 = d_ev_camera::_10310;
  local_26c = d_ev_camera::_8964;
  local_268 = d_ev_camera::_10314;
  local_264 = d_ev_camera::_10315;
  local_90 = d_ev_camera::_8964;
  local_8c = d_ev_camera::_10314;
  local_88 = d_ev_camera::_10315;
  local_278 = d_ev_camera::_10316;
  local_274 = d_ev_camera::_10317;
  local_270 = d_ev_camera::_8279;
  local_84 = d_ev_camera::_10316;
  local_80 = d_ev_camera::_10317;
  local_7c = d_ev_camera::_8279;
  local_1e8.x = d_ev_camera::_4862;
  local_1e8.y = d_ev_camera::_8902;
  local_1e8.z = d_ev_camera::_10318;
  local_284 = d_ev_camera::_10319;
  local_280 = d_ev_camera::_8896;
  local_27c = d_ev_camera::_10320;
  local_cc = d_ev_camera::_10319;
  local_c8 = d_ev_camera::_8896;
  local_c4 = d_ev_camera::_10320;
  local_290 = d_ev_camera::_10321;
  local_28c = d_ev_camera::_8890;
  local_288 = d_ev_camera::_8905;
  local_c0 = d_ev_camera::_10321;
  local_bc = d_ev_camera::_8890;
  local_b8 = d_ev_camera::_8905;
  local_29c = d_ev_camera::_8274;
  local_298 = d_ev_camera::_10321;
  local_294 = d_ev_camera::_8901;
  local_b4 = d_ev_camera::_8274;
  local_b0 = d_ev_camera::_10321;
  local_ac = d_ev_camera::_8901;
  local_1f4 = d_ev_camera::_4862;
  local_1f0 = d_ev_camera::_10322;
  local_1ec = d_ev_camera::_10318;
  local_2a8 = d_ev_camera::_9354;
  local_2a4 = d_ev_camera::_8900;
  local_2a0 = d_ev_camera::_10323;
  local_f0 = d_ev_camera::_9354;
  local_ec = d_ev_camera::_8900;
  local_e8 = d_ev_camera::_10323;
  local_2b4 = d_ev_camera::_10321;
  local_2b0 = d_ev_camera::_10324;
  local_2ac = d_ev_camera::_10325;
  local_e4 = d_ev_camera::_10321;
  local_e0 = d_ev_camera::_10324;
  local_dc = d_ev_camera::_10325;
  local_2c0 = d_ev_camera::_8274;
  local_2bc = d_ev_camera::_10321;
  local_2b8 = d_ev_camera::_8901;
  local_d8 = d_ev_camera::_8274;
  local_d4 = d_ev_camera::_10321;
  local_d0 = d_ev_camera::_8901;
  local_200 = d_ev_camera::_8273;
  local_1fc = d_ev_camera::_10718;
  local_1f8 = d_ev_camera::_10718;
  local_2cc = d_ev_camera::_8291;
  local_2c8 = d_ev_camera::_10310;
  local_2c4 = d_ev_camera::_8898;
  local_114 = d_ev_camera::_8291;
  local_110 = d_ev_camera::_10310;
  local_10c = d_ev_camera::_8898;
  local_2d8 = d_ev_camera::_10719;
  local_2d4 = d_ev_camera::_8891;
  local_2d0 = d_ev_camera::_10720;
  local_108 = d_ev_camera::_10719;
  local_104 = d_ev_camera::_8891;
  local_100 = d_ev_camera::_10720;
  local_2e4 = d_ev_camera::_10721;
  local_2e0 = d_ev_camera::_8892;
  local_2dc = d_ev_camera::_10318;
  local_fc = d_ev_camera::_10721;
  local_f8 = d_ev_camera::_8892;
  local_f4 = d_ev_camera::_10318;
  local_20c = d_ev_camera::_10337;
  local_208 = d_ev_camera::_10338;
  local_204 = d_ev_camera::_10311;
  local_2f0 = d_ev_camera::_10339;
  local_2ec = d_ev_camera::_10340;
  local_2e8 = d_ev_camera::_10341;
  local_138 = d_ev_camera::_10339;
  local_134 = d_ev_camera::_10340;
  local_130 = d_ev_camera::_10341;
  local_2fc = d_ev_camera::_10342;
  local_2f8 = d_ev_camera::_10343;
  local_2f4 = d_ev_camera::_10344;
  local_12c = d_ev_camera::_10342;
  local_128 = d_ev_camera::_10343;
  local_124 = d_ev_camera::_10344;
  local_308 = d_ev_camera::_10345;
  local_304 = d_ev_camera::_10346;
  local_300 = d_ev_camera::_10347;
  local_120 = d_ev_camera::_10345;
  local_11c = d_ev_camera::_10346;
  local_118 = d_ev_camera::_10347;
  iVar17 = 3;
  ppfVar3 = (float **)&UNK_80359c34;
  ppfVar5 = &local_158;
  do {
    ppfVar14 = ppfVar5;
    ppfVar11 = ppfVar3;
    pfVar6 = ppfVar11[2];
    ppfVar14[1] = ppfVar11[1];
    ppfVar14[2] = pfVar6;
    iVar17 = iVar17 + -1;
    ppfVar3 = ppfVar11 + 2;
    ppfVar5 = ppfVar14 + 2;
  } while (iVar17 != 0);
  ppfVar14[3] = ppfVar11[3];
  local_154 = &local_1e8;
  local_150 = &local_1dc;
  local_14c = &local_1e8;
  local_148 = &local_1f4;
  local_144 = &local_1d0;
  local_140 = &local_200;
  local_13c = &local_20c;
  iVar17 = 3;
  puVar2 = (undefined4 *)&UNK_80359c50;
  puVar4 = &uStack372;
  do {
    puVar15 = puVar4;
    puVar12 = puVar2;
    uVar7 = puVar12[2];
    puVar15[1] = puVar12[1];
    puVar15[2] = uVar7;
    iVar17 = iVar17 + -1;
    puVar2 = puVar12 + 2;
    puVar4 = puVar15 + 2;
  } while (iVar17 != 0);
  puVar15[3] = puVar12[3];
  local_170[0] = &local_cc;
  local_170[1] = &local_a8;
  local_170[2] = &local_cc;
  local_170[3] = &local_f0;
  local_170[4] = &local_78;
  local_170[5] = &local_114;
  local_158 = &local_138;
  iVar17 = 3;
  puVar2 = (undefined4 *)&UNK_80359c6c;
  puVar4 = &uStack400;
  do {
    puVar15 = puVar4;
    puVar12 = puVar2;
    uVar7 = puVar12[2];
    puVar15[1] = puVar12[1];
    puVar15[2] = uVar7;
    iVar17 = iVar17 + -1;
    puVar2 = puVar12 + 2;
    puVar4 = puVar15 + 2;
  } while (iVar17 != 0);
  puVar15[3] = puVar12[3];
  iVar17 = 3;
  puVar2 = (undefined4 *)&UNK_80359c88;
  puVar4 = &uStack428;
  do {
    puVar15 = puVar4;
    puVar12 = puVar2;
    uVar7 = puVar12[2];
    puVar15[1] = puVar12[1];
    puVar15[2] = uVar7;
    iVar17 = iVar17 + -1;
    puVar2 = puVar12 + 2;
    puVar4 = puVar15 + 2;
  } while (iVar17 != 0);
  puVar15[3] = puVar12[3];
  iVar17 = 3;
  pfVar6 = (float *)&UNK_80359ca4;
  pfVar1 = &local_1c8;
  do {
    pfVar13 = pfVar1;
    pfVar10 = pfVar6;
    fVar8 = pfVar10[2];
    pfVar13[1] = pfVar10[1];
    pfVar13[2] = fVar8;
    iVar17 = iVar17 + -1;
    pfVar6 = pfVar10 + 2;
    pfVar1 = pfVar13 + 2;
  } while (iVar17 != 0);
  pfVar13[3] = pfVar10[3];
  uVar7 = 0;
  if (this->field_0x11c == 0) {
    *(undefined4 *)&this->field_0x378 = 0;
  }
  iVar17 = *(int *)&this->field_0x378;
  if (iVar17 == 10) {
LAB_800bb874:
    this->mEvBank = 0.0;
    if ((((*(uint *)&this->field_0x7c & 7) == 0) &&
        (iVar17 = *(int *)&this->field_0x380, iVar17 < 4)) && (1 < iVar17)) {
      pfVar6 = local_170[iVar17];
      local_224 = *pfVar6;
      local_220 = pfVar6[1];
      local_21c = pfVar6[2];
      *pfVar6 = pfVar6[3];
      pfVar6[1] = pfVar6[4];
      pfVar6[2] = pfVar6[5];
      pfVar6 = local_170[*(int *)&this->field_0x380];
      pfVar6[3] = local_224;
      pfVar6[4] = local_220;
      pfVar6[5] = local_21c;
    }
    relationalPos(&local_314,this,this->mpPlayerActor,(&local_154)[*(int *)&this->field_0x380]);
    *(float *)&this->field_0x384 = local_314.x;
    *(float *)&this->field_0x388 = local_314.y;
    *(float *)&this->field_0x38c = local_314.z;
    iVar16 = 0;
    for (iVar17 = 0; iVar17 < local_18c[*(int *)&this->field_0x380]; iVar17 = iVar17 + 1) {
      relationalPos(&local_320,this,this->mpPlayerActor,
                    (cXyz *)((int)local_170[*(int *)&this->field_0x380] + iVar16));
      local_218.x = local_320.x;
      local_218.y = local_320.y;
      local_218.z = local_320.z;
      positionOf(&cStack812,this,this->mpPlayerActor);
      if (local_218.y < *(float *)&this->field_0x368 + cStack812.y) {
        positionOf(&cStack824,this,this->mpPlayerActor);
        local_218.y = *(float *)&this->field_0x368 + cStack824.y;
      }
      cVar9 = lineBGCheck(this,(cXyz *)&this->field_0x384,&local_218,0x8f);
      if (cVar9 == '\0') {
        local_344 = *(undefined4 *)&this->field_0x384;
        local_340 = *(undefined4 *)&this->field_0x388;
        local_33c = *(undefined4 *)&this->field_0x38c;
        local_350.x = local_218.x;
        local_350.y = local_218.y;
        local_350.z = local_218.z;
        cVar9 = @unnamed@d_ev_camera_cpp@::lineCollisionCheck
                          ((_unnamed_d_ev_camera_cpp_ *)&local_344,&local_350,
                           (cXyz *)this->mpPlayerActor,(fopAc_ac_c *)0x0,in_r7);
        if (cVar9 == '\0') break;
      }
      iVar16 = iVar16 + 0xc;
    }
    ::cXyz::operator__(&cStack860,&local_218,(cXyz *)&this->field_0x384);
    cSGlobe::Val((cSGlobe *)&this->mpEvRelActor,&cStack860);
    *(undefined4 *)&this->field_0x390 = local_1a8[*(int *)&this->field_0x380];
    *(float *)&this->field_0x37c = local_1c4[*(int *)&this->field_0x380];
    *(undefined4 *)&this->field_0x378 = 1;
  }
  else {
    if (iVar17 < 10) {
      if (iVar17 == 1) {
        uStack76 = (uint)this->mEvBank ^ 0x80000000;
        local_50 = 0x43300000;
        uStack68 = *(uint *)&this->field_0x37c ^ 0x80000000;
        local_48 = 0x43300000;
        dVar20 = (double)((float)((double)CONCAT44(0x43300000,uStack76) - d_ev_camera::_5609) /
                         (float)((double)CONCAT44(0x43300000,uStack68) - d_ev_camera::_5609));
        this->field_0x60 =
             this->field_0x60 +
             (float)(dVar20 * (double)(*(float *)&this->field_0x390 - this->field_0x60));
        relationalPos(&local_368,this,this->mpPlayerActor,(&local_154)[*(int *)&this->field_0x380]);
        *(float *)&this->field_0x384 = local_368.x;
        *(float *)&this->field_0x388 = local_368.y;
        *(float *)&this->field_0x38c = local_368.z;
        ::cXyz::operator__(&cStack884,(cXyz *)&this->field_0x384,&this->field_0x44);
        ::cXyz::operator_(&cStack896,&cStack884,(float)dVar20);
        mtx::PSVECAdd(&this->field_0x44,&cStack896,&this->field_0x44);
        fVar8 = (this->field_0x3c).mDistance;
        local_3e8[0] = (this->field_0x3c).mAngleX.v;
        local_3e4[0] = (this->field_0x3c).mAngleY.v;
        dVar19 = (double)(fVar8 + (float)(dVar20 * (double)((float)this->mpEvRelActor - fVar8)));
        cSAngle::operator__(acStack1004,(cSAngle *)this->mEvRelUseMask);
        cSAngle::operator_(acStack1008,(float)dVar20);
        cSAngle::operator___(local_3e8,acStack1008);
        cSAngle::operator__(acStack1012,(cSAngle *)(this->mEvRelUseMask + 2));
        cSAngle::operator_(acStack1016,(float)dVar20);
        cSAngle::operator___(local_3e4,acStack1016);
        cSGlobe::Val(&this->field_0x3c,(float)dVar19,local_3e8,local_3e4);
        cSGlobe::Xyz(&cStack908,&this->field_0x3c);
        ::cXyz::operator__(&local_398,&this->field_0x44,&cStack908);
        (this->field_0x50).x = local_398.x;
        (this->field_0x50).y = local_398.y;
        (this->field_0x50).z = local_398.z;
        if ((int)this->mEvBank < *(int *)&this->field_0x37c) goto LAB_800bbd50;
        *(undefined4 *)&this->field_0x378 = 2;
      }
      else {
        if ((iVar17 < 1) || (2 < iVar17)) goto LAB_800bb850;
      }
      relationalPos(&local_3a4,this,this->mpPlayerActor,(&local_154)[*(int *)&this->field_0x380]);
      (this->field_0x44).x = local_3a4.x;
      (this->field_0x44).y = local_3a4.y;
      (this->field_0x44).z = local_3a4.z;
      cSGlobe::Xyz(&cStack944,&this->field_0x3c);
      ::cXyz::operator__(&local_3bc,&this->field_0x44,&cStack944);
      (this->field_0x50).x = local_3bc.x;
      (this->field_0x50).y = local_3bc.y;
      (this->field_0x50).z = local_3bc.z;
      this->mEvFovy = (float)((int)this->mEvFovy + 1);
      if ((*(int *)&this->field_0x380 == 0) && (this->mEvFovy == 1.401298e-45)) {
        *(undefined4 *)&this->field_0x378 = 10;
        *(undefined4 *)&this->field_0x380 = 4;
        goto LAB_800bbd50;
      }
      *(undefined4 *)&this->field_0x378 = 99;
    }
    else {
      if (iVar17 != 99) {
LAB_800bb850:
        getEvIntData(this,(int *)&this->field_0x380,"Type",0);
        this->mEvFovy = 0.0;
        goto LAB_800bb874;
      }
    }
    *(undefined *)&this->field_0x102 = 1;
    *(undefined *)&this->field_0x101 = 1;
    *(undefined *)&this->field_0x100 = 1;
    relationalPos(&local_3c8,this,this->mpPlayerActor,(&local_154)[*(int *)&this->field_0x380]);
    (this->field_0x44).x = local_3c8.x;
    (this->field_0x44).y = local_3c8.y;
    (this->field_0x44).z = local_3c8.z;
    cSGlobe::Xyz(&cStack980,&this->field_0x3c);
    ::cXyz::operator__(&local_3e0,&this->field_0x44,&cStack980);
    (this->field_0x50).x = local_3e0.x;
    (this->field_0x50).y = local_3e0.y;
    (this->field_0x50).z = local_3e0.z;
    uVar7 = 1;
  }
LAB_800bbd50:
  this->mEvBank = (float)((int)this->mEvBank + 1);
  __psq_l0(auStack8,uVar18);
  __psq_l1(auStack8,uVar18);
  __psq_l0(auStack24,uVar18);
  __psq_l1(auStack24,uVar18);
  return uVar7;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x800bc33c) */
/* WARNING: Removing unreachable block (ram,0x800bc344) */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall dCamera_c::getItemEvCamera(void) */

undefined4 __thiscall dCamera_c::getItemEvCamera(dCamera_c *this)

{
  float fVar1;
  int iVar2;
  char cVar3;
  fopAc_ac_c *in_r7;
  fopAc_ac_c *pfVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined8 in_f30;
  double dVar8;
  undefined8 in_f31;
  double dVar9;
  undefined2 local_1b8 [2];
  cSAngle acStack436 [2];
  cSAngle acStack432 [2];
  cSAngle acStack428 [2];
  cSAngle acStack424 [2];
  cSAngle local_1a4 [2];
  cSAngle local_1a0 [2];
  cXyz local_19c;
  cXyz cStack400;
  cXyz local_184;
  cXyz local_178;
  cXyz cStack364;
  cXyz local_160;
  cXyz local_154;
  cXyz cStack328;
  cXyz cStack316;
  cXyz cStack304;
  cXyz local_124;
  cXyz cStack280;
  cXyz local_10c;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  cXyz cStack244;
  cXyz cStack232;
  cXyz local_dc;
  cXyz local_d0;
  float local_c4;
  float local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  float local_a8;
  float local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  cXyz local_94;
  cXyz local_88;
  cXyz local_7c;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  undefined4 local_48;
  uint uStack68;
  undefined4 local_40;
  uint uStack60;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar7 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  local_88.x = d_ev_camera::_10916;
  local_88.y = d_ev_camera::_10917;
  local_88.z = d_ev_camera::_10918;
  local_a0 = d_ev_camera::_10919;
  local_9c = d_ev_camera::_10920;
  local_98 = d_ev_camera::_10921;
  local_7c.x = d_ev_camera::_10919;
  local_7c.y = d_ev_camera::_10920;
  local_7c.z = d_ev_camera::_10921;
  local_ac = d_ev_camera::_10922;
  local_a8 = d_ev_camera::_10923;
  local_a4 = d_ev_camera::_10924;
  local_70 = d_ev_camera::_10922;
  local_6c = d_ev_camera::_10923;
  local_68 = d_ev_camera::_10924;
  local_b8 = d_ev_camera::_10925;
  local_b4 = d_ev_camera::_10926;
  local_b0 = d_ev_camera::_10927;
  local_64 = d_ev_camera::_10925;
  local_60 = d_ev_camera::_10926;
  local_5c = d_ev_camera::_10927;
  local_c4 = d_ev_camera::_10919;
  local_c0 = d_ev_camera::_10920;
  local_bc = d_ev_camera::_10921;
  local_58 = d_ev_camera::_10919;
  local_54 = d_ev_camera::_10920;
  local_50 = d_ev_camera::_10921;
  uVar5 = 0;
  if (this->field_0x11c == 0) {
    *(undefined4 *)&this->field_0x378 = 0;
  }
  iVar2 = *(int *)&this->field_0x378;
  if (iVar2 == 0xb) {
LAB_800bc0c4:
    uStack68 = (uint)this->mEvBank ^ 0x80000000;
    local_48 = 0x43300000;
    uStack60 = *(uint *)&this->field_0x37c ^ 0x80000000;
    local_40 = 0x43300000;
    dVar9 = (double)((float)((double)CONCAT44(0x43300000,uStack68) - d_ev_camera::_5609) /
                    (float)((double)CONCAT44(0x43300000,uStack60) - d_ev_camera::_5609));
    this->field_0x60 =
         this->field_0x60 +
         (float)(dVar9 * (double)(*(float *)&this->field_0x390 - this->field_0x60));
    relationalPos(&local_124,this,this->mpPlayerActor,&local_88);
    *(float *)&this->field_0x384 = local_124.x;
    *(float *)&this->field_0x388 = local_124.y;
    *(float *)&this->field_0x38c = local_124.z;
    ::cXyz::operator__(&cStack304,(cXyz *)&this->field_0x384,&this->field_0x44);
    ::cXyz::operator_(&cStack316,&cStack304,(float)dVar9);
    mtx::PSVECAdd(&this->field_0x44,&cStack316,&this->field_0x44);
    fVar1 = (this->field_0x3c).mDistance;
    local_1a4[0] = (this->field_0x3c).mAngleX.v;
    local_1a0[0] = (this->field_0x3c).mAngleY.v;
    dVar8 = (double)(fVar1 + (float)(dVar9 * (double)((float)this->mpEvRelActor - fVar1)));
    cSAngle::operator__(acStack424,(cSAngle *)this->mEvRelUseMask);
    cSAngle::operator_(acStack428,(float)dVar9);
    cSAngle::operator___(local_1a4,acStack428);
    cSAngle::operator__(acStack432,(cSAngle *)(this->mEvRelUseMask + 2));
    cSAngle::operator_(acStack436,(float)dVar9);
    cSAngle::operator___(local_1a0,acStack436);
    cSGlobe::Val(&this->field_0x3c,(float)dVar8,local_1a4,local_1a0);
    cSGlobe::Xyz(&cStack328,&this->field_0x3c);
    ::cXyz::operator__(&local_154,&this->field_0x44,&cStack328);
    (this->field_0x50).x = local_154.x;
    (this->field_0x50).y = local_154.y;
    (this->field_0x50).z = local_154.z;
    if ((int)this->mEvBank < *(int *)&this->field_0x37c) goto LAB_800bc32c;
    *(undefined4 *)&this->field_0x378 = 0xc;
LAB_800bc250:
    relationalPos(&local_160,this,this->mpPlayerActor,&local_88);
    (this->field_0x44).x = local_160.x;
    (this->field_0x44).y = local_160.y;
    (this->field_0x44).z = local_160.z;
    cSGlobe::Xyz(&cStack364,&this->field_0x3c);
    ::cXyz::operator__(&local_178,&this->field_0x44,&cStack364);
    (this->field_0x50).x = local_178.x;
    (this->field_0x50).y = local_178.y;
    (this->field_0x50).z = local_178.z;
    *(undefined4 *)&this->field_0x378 = 99;
  }
  else {
    if (iVar2 < 0xb) {
      if (iVar2 != 1) {
        if ((0 < iVar2) && (9 < iVar2)) {
          this->mEvBank = 0.0;
          relationalPos(&local_d0,this,this->mpPlayerActor,&local_88);
          *(float *)&this->field_0x384 = local_d0.x;
          *(float *)&this->field_0x388 = local_d0.y;
          *(float *)&this->field_0x38c = local_d0.z;
          iVar6 = 0;
          iVar2 = 0;
          do {
            relationalPos(&local_dc,this,this->mpPlayerActor,(cXyz *)((int)&local_7c.x + iVar2));
            local_94.x = local_dc.x;
            local_94.y = local_dc.y;
            local_94.z = local_dc.z;
            positionOf(&cStack232,this,this->mpPlayerActor);
            if (local_94.y < *(float *)&this->field_0x368 + cStack232.y) {
              positionOf(&cStack244,this,this->mpPlayerActor);
              local_94.y = *(float *)&this->field_0x368 + cStack244.y;
            }
            pfVar4 = (fopAc_ac_c *)0x0;
            if (((&d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8)[this->mPadId * 4] & 0x10000U) !=
                0) {
              local_1b8[0] = 0xa7;
              pfVar4 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeForPName,local_1b8)
              ;
            }
            cVar3 = lineBGCheck(this,(cXyz *)&this->field_0x384,&local_94,0x8f);
            if (cVar3 == '\0') {
              local_100 = *(undefined4 *)&this->field_0x384;
              local_fc = *(undefined4 *)&this->field_0x388;
              local_f8 = *(undefined4 *)&this->field_0x38c;
              local_10c.x = local_94.x;
              local_10c.y = local_94.y;
              local_10c.z = local_94.z;
              cVar3 = @unnamed@d_ev_camera_cpp@::lineCollisionCheck
                                ((_unnamed_d_ev_camera_cpp_ *)&local_100,&local_10c,
                                 (cXyz *)this->mpPlayerActor,pfVar4,in_r7);
              if (cVar3 == '\0') break;
            }
            iVar6 = iVar6 + 1;
            iVar2 = iVar2 + 0xc;
          } while (iVar6 < 4);
          ::cXyz::operator__(&cStack280,&local_94,(cXyz *)&this->field_0x384);
          cSGlobe::Val((cSGlobe *)&this->mpEvRelActor,&cStack280);
          *(float *)&this->field_0x390 = d_ev_camera::_10928;
          *(undefined4 *)&this->field_0x37c = *(undefined4 *)&this->field_0x3c0;
          *(undefined4 *)&this->field_0x378 = 0xb;
          goto LAB_800bc0c4;
        }
LAB_800bbea8:
        getEvIntData(this,(int *)&this->field_0x3bc,"Timer1",0x1b);
        getEvIntData(this,(int *)&this->field_0x3c0,"Timer2",5);
        this->mEvFovy = 0.0;
        *(undefined4 *)&this->field_0x378 = 1;
        this->mEvBank = 0.0;
        *(undefined4 *)&this->field_0x37c = *(undefined4 *)&this->field_0x3bc;
      }
      this->mEventFlags = this->mEventFlags | 1;
      if (*(int *)&this->field_0x37c <= (int)this->mEvBank) {
        *(undefined4 *)&this->field_0x378 = 10;
      }
      goto LAB_800bc32c;
    }
    if (iVar2 != 99) {
      if ((0x62 < iVar2) || (0xc < iVar2)) goto LAB_800bbea8;
      goto LAB_800bc250;
    }
  }
  *(undefined *)&this->field_0x102 = 1;
  *(undefined *)&this->field_0x101 = 1;
  *(undefined *)&this->field_0x100 = 1;
  relationalPos(&local_184,this,this->mpPlayerActor,&local_88);
  (this->field_0x44).x = local_184.x;
  (this->field_0x44).y = local_184.y;
  (this->field_0x44).z = local_184.z;
  cSGlobe::Xyz(&cStack400,&this->field_0x3c);
  ::cXyz::operator__(&local_19c,&this->field_0x44,&cStack400);
  (this->field_0x50).x = local_19c.x;
  (this->field_0x50).y = local_19c.y;
  (this->field_0x50).z = local_19c.z;
  uVar5 = 1;
LAB_800bc32c:
  this->mEvBank = (float)((int)this->mEvBank + 1);
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  __psq_l0(auStack24,uVar7);
  __psq_l1(auStack24,uVar7);
  return uVar5;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x800bc9b8) */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall dCamera_c::possessedEvCamera(void) */

undefined4 __thiscall dCamera_c::possessedEvCamera(dCamera_c *this)

{
  int iVar1;
  float fVar2;
  fopAc_ac_c *pfVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined8 in_f31;
  double dVar6;
  cSAngle local_128 [2];
  cSAngle local_124 [2];
  cSAngle local_120 [2];
  cSAngle acStack284 [2];
  cSAngle acStack280 [2];
  cSAngle local_114 [2];
  cSAngle acStack272 [2];
  cSAngle acStack268 [2];
  cSAngle acStack264 [4];
  cSAngle acStack256 [4];
  float local_f8;
  cXyz local_f4;
  cXyz cStack232;
  cXyz cStack220;
  cXyz local_d0;
  cXyz cStack196;
  cXyz cStack184;
  cXyz cStack172;
  cXyz cStack160;
  cXyz local_94;
  cXyz local_88;
  cXyz local_7c;
  cXyz cStack112;
  cXyz cStack100;
  cXyz local_58;
  cXyz local_4c;
  cXyz local_40;
  cXyz local_34;
  undefined4 local_28;
  uint uStack36;
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  uVar4 = 0;
  if (this->field_0x11c == 0) {
    *(undefined4 *)&this->field_0x378 = 0;
  }
  iVar1 = *(int *)&this->field_0x378;
  if (iVar1 == 1) {
    uStack36 = *(uint *)&this->field_0x384 ^ 0x80000000;
    local_28 = 0x43300000;
    dVar6 = (double)(d_ev_camera::_5486 /
                    (float)((double)CONCAT44(0x43300000,uStack36) - d_ev_camera::_5609));
    eyePos(&cStack160,this,this->mpEvRelActor);
    ::cXyz::operator__(&cStack172,&cStack160,&this->field_0x44);
    ::cXyz::operator_(&cStack184,&cStack172,(float)dVar6);
    mtx::PSVECAdd(&this->field_0x44,&cStack184,&this->field_0x44);
    fVar2 = (this->field_0x3c).mDistance;
    (this->field_0x3c).mDistance =
         fVar2 + (float)(dVar6 * (double)(*(float *)this->mEvRelUseMask - fVar2));
    cSAngle::operator__(acStack268,(cSAngle *)&this->mEvTimer);
    cSAngle::operator_(acStack272,(float)dVar6);
    cSAngle::operator__(local_114,&(this->field_0x3c).mAngleX);
    cSAngle::cSAngle(local_124,local_114[0]);
    (this->field_0x3c).mAngleX.v = local_124[0];
    cSAngle::operator__(acStack280,(cSAngle *)((int)&this->mEvTimer + 2));
    cSAngle::operator_(acStack284,(float)dVar6);
    cSAngle::operator__(local_120,&(this->field_0x3c).mAngleY);
    cSAngle::cSAngle(local_128,local_120[0]);
    (this->field_0x3c).mAngleY.v = local_128[0];
    cSGlobe::Xyz(&cStack196,&this->field_0x3c);
    ::cXyz::operator__(&local_d0,&this->field_0x44,&cStack196);
    local_34.x = local_d0.x;
    local_34.y = local_d0.y;
    local_34.z = local_d0.z;
    ::cXyz::operator__(&cStack220,&local_34,&this->field_0x50);
    ::cXyz::operator_(&cStack232,&cStack220,this->mEvFovy);
    mtx::PSVECAdd(&this->field_0x50,&cStack232,&this->field_0x50);
    this->field_0x60 =
         this->field_0x60 +
         (float)(dVar6 * (double)(*(float *)&this->field_0x390 - this->field_0x60));
    if (this->mEvBank == 1.401298e-45) {
      iVar1 = f_op_camera_mng::fopCamM_GetParam(this->mpCamera);
      iVar1 = (char)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[iVar1].mDlstWindowIdx *
              0x2c;
      eyePos(&local_f4,this,this->mpEvRelActor);
      local_40.x = local_f4.x;
      local_40.y = local_f4.y;
      local_40.z = local_f4.z;
      m_Do_lib::mDoLib_project(&local_40,&local_4c);
      SetBlurePosition(this,local_4c.x /
                            *(float *)((int)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mDlstWindow +
                                      iVar1 + 0x20),
                       local_4c.y /
                       *(float *)((int)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mDlstWindow +
                                 iVar1 + 0x24),d_ev_camera::_4862);
      SetBlureAlpha(this,d_ev_camera::_11097 + (float)((double)d_ev_camera::_11099 * dVar6));
      SetBlureScale(this,d_ev_camera::_11100 + (float)((double)d_ev_camera::_11101 * dVar6),
                    d_ev_camera::_11102 - (float)((double)d_ev_camera::_11103 * dVar6),
                    d_ev_camera::_4862);
    }
    *(int *)&this->field_0x384 = *(int *)&this->field_0x384 + -1;
    if (*(int *)&this->field_0x384 < 1) {
      *(undefined4 *)&this->field_0x378 = 99;
    }
  }
  else {
    if ((iVar1 < 1) || (iVar1 != 99)) {
      pfVar3 = (fopAc_ac_c *)getEvActor(this,"Target","@PLAYER");
      this->mpEvRelActor = pfVar3;
      if (pfVar3 == (fopAc_ac_c *)0x0) {
        uVar4 = 1;
      }
      else {
        getEvIntData(this,(int *)&this->field_0x37c,"Type",0);
        getEvIntData(this,(int *)&this->field_0x380,"Timer",10);
        getEvFloatData(this,(float *)&this->field_0x388,"Radius",d_ev_camera::_8896);
        getEvFloatData(this,&this->mEvFovy,"Cushion",d_ev_camera::_5486);
        getEvFloatData(this,&local_f8,"Latitude",d_ev_camera::_8275);
        cSAngle::Val((cSAngle *)&this->field_0x38c,local_f8);
        getEvFloatData(this,&local_f8,"Longitude",d_ev_camera::_4862);
        cSAngle::Val((cSAngle *)&this->field_0x38e,local_f8);
        getEvFloatData(this,(float *)&this->field_0x390,"Fovy",d_ev_camera::_8898);
        getEvIntData(this,(int *)&this->mEvBank,"Blure",0);
        if (*(int *)&this->field_0x37c == 0) {
          directionOf((dCamera_c *)(acStack256 + 2),(fopAc_ac_c *)this);
          cSAngle::operator__(acStack256,(cSAngle *)&this->field_0x38e);
          cSGlobe::Val((cSGlobe *)this->mEvRelUseMask,*(float *)&this->field_0x388,
                       (cSAngle *)&this->field_0x38c,acStack256);
          *(float *)(this->field_0xa4 + 1) = (this->field_0x44).x;
          *(float *)&this->field_0xa4[1].field_0x4 = (this->field_0x44).y;
          *(float *)&this->field_0xa4[1].field_0x8 = (this->field_0x44).z;
          *(float *)&this->field_0xa4[1].field_0xc = (this->field_0x50).x;
          *(float *)&this->field_0xa4[1].field_0x10 = (this->field_0x50).y;
          *(float *)&this->field_0xa4[1].field_0x14 = (this->field_0x50).z;
          *(float *)&this->field_0xa4[1].field_0x18 = this->field_0x60;
          *(short *)&this->field_0xa4[1].field_0x1c = this->field_0x5c;
          *(undefined2 *)&this->field_0xa4[1].field_0x1e = 2;
        }
        else {
          eyePos(&local_58,this,this->mpEvRelActor);
          (this->field_0x44).x = local_58.x;
          (this->field_0x44).y = local_58.y;
          (this->field_0x44).z = local_58.z;
          ::cXyz::operator__(&cStack100,(cXyz *)&this->field_0xa4[1].field_0xc,
                             (cXyz *)(this->field_0xa4 + 1));
          cSGlobe::Val((cSGlobe *)this->mEvRelUseMask,&cStack100);
          directionOf((dCamera_c *)(acStack264 + 2),(fopAc_ac_c *)this);
          cSAngle::operator__(acStack264,(cSAngle *)&this->field_0x38e);
          cSGlobe::Val(&this->field_0x3c,*(float *)&this->field_0x388,(cSAngle *)&this->field_0x38c,
                       acStack264);
          cSGlobe::Xyz(&cStack112,&this->field_0x3c);
          ::cXyz::operator__(&local_7c,&this->field_0x44,&cStack112);
          (this->field_0x50).x = local_7c.x;
          (this->field_0x50).y = local_7c.y;
          (this->field_0x50).z = local_7c.z;
          this->field_0x60 = *(float *)&this->field_0x390;
        }
        *(undefined4 *)&this->field_0x378 = 1;
        *(undefined4 *)&this->field_0x384 = *(undefined4 *)&this->field_0x380;
        fVar2 = this->mEvBank;
        if (fVar2 == 2.802597e-45) {
          ResetBlure(this,0);
          SetBlurePositionType(this,0xb);
          SetBlureTimer(this,*(long *)&this->field_0x380);
          SetBlureAlpha(this,d_ev_camera::_11098);
          SetBlureScale(this,d_ev_camera::_9362);
          local_94.x = d_ev_camera::_4862;
          local_94.y = d_ev_camera::_5486;
          local_94.z = d_ev_camera::_4862;
          dVibration_c::StartShock
                    (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mVibration,1,0x20,&local_94);
        }
        else {
          if (((int)fVar2 < 2) && (0 < (int)fVar2)) {
            ResetBlure(this,1);
            SetBlurePositionType(this,0xb);
            SetBlureTimer(this,*(long *)&this->field_0x380);
            SetBlureAlpha(this,d_ev_camera::_11097);
            local_88.x = d_ev_camera::_4862;
            local_88.y = d_ev_camera::_5486;
            local_88.z = d_ev_camera::_4862;
            dVibration_c::StartShock
                      (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mVibration,1,0x20,&local_88);
          }
        }
      }
    }
    else {
      uVar4 = 1;
      *(undefined *)&this->field_0x102 = 1;
      *(undefined *)&this->field_0x101 = 1;
      *(undefined *)&this->field_0x100 = 1;
    }
  }
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  return uVar4;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dCamera_c::fixedFramesEvCamera(void) */

undefined4 __thiscall dCamera_c::fixedFramesEvCamera(dCamera_c *this)

{
  float fVar1;
  void *pvVar2;
  fopAc_ac_c *pfVar3;
  undefined uVar6;
  float *pfVar4;
  char cVar7;
  undefined4 uVar5;
  fopAc_ac_c *in_r7;
  int iVar8;
  int iVar9;
  int iVar10;
  cXyz cStack104;
  cXyz local_5c;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  cXyz local_44;
  cXyz local_38;
  cXyz local_2c;
  cXyz local_20;
  
  if (this->field_0x11c == 0) {
    (this->mEvBasePos).y = 1.401158e-41;
    fVar1 = (float)dEvent_manager_c::getMySubstanceNum
                             (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mStaffIdx,
                              "Centers");
    if (fVar1 == 0.0) {
      return 1;
    }
    pvVar2 = dEvent_manager_c::getMySubstanceP
                       (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mStaffIdx,
                        "Centers",Xyz);
    this->mEvBank = (float)pvVar2;
    if ((int)fVar1 < (int)(this->mEvBasePos).y) {
      (this->mEvBasePos).y = fVar1;
    }
    fVar1 = (float)dEvent_manager_c::getMySubstanceNum
                             (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mStaffIdx,
                              "Eyes");
    if (fVar1 == 0.0) {
      return 1;
    }
    pvVar2 = dEvent_manager_c::getMySubstanceP
                       (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mStaffIdx,"Eyes",
                        Xyz);
    this->mEvFovy = (float)pvVar2;
    if ((int)fVar1 < (int)(this->mEvBasePos).y) {
      (this->mEvBasePos).y = fVar1;
    }
    fVar1 = (float)dEvent_manager_c::getMySubstanceNum
                             (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mStaffIdx,
                              "Fovys");
    if (fVar1 == 0.0) {
      return 1;
    }
    pfVar3 = (fopAc_ac_c *)
             dEvent_manager_c::getMySubstanceP
                       (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mStaffIdx,"Fovys",
                        Float);
    this->mpEvRelActor = pfVar3;
    if ((int)fVar1 < (int)(this->mEvBasePos).y) {
      (this->mEvBasePos).y = fVar1;
    }
    uVar6 = getEvIntData(this,(int *)&this->mEvBasePos,"Timer",1);
    *(undefined *)&this->field_0x378 = uVar6;
    getEvStringData(this,(char *)&this->field_0x3a8,"RelUseMask","oo");
    pfVar3 = getEvActor(this,"RelActor");
    this->mEvTimer = (int)pfVar3;
    iVar9 = 0;
    iVar8 = 0;
    for (iVar10 = 0; iVar10 < (int)(this->mEvBasePos).y; iVar10 = iVar10 + 1) {
      pfVar4 = (float *)((int)this->mEvBank + iVar8);
      local_20.x = *pfVar4;
      local_20.y = pfVar4[1];
      local_20.z = pfVar4[2];
      pfVar4 = (float *)((int)this->mEvFovy + iVar8);
      local_2c.x = *pfVar4;
      local_2c.y = pfVar4[1];
      local_2c.z = pfVar4[2];
      if (((fopAc_ac_c *)this->mEvTimer == (fopAc_ac_c *)0x0) || (this->field_0x3a8 != 0x6f)) {
        *(float *)&this->field_0x37c = local_20.x;
        *(float *)&this->field_0x380 = local_20.y;
        *(float *)&this->field_0x384 = local_20.z;
      }
      else {
        relationalPos(&local_38,this,(fopAc_ac_c *)this->mEvTimer,&local_20);
        *(float *)&this->field_0x37c = local_38.x;
        *(float *)&this->field_0x380 = local_38.y;
        *(float *)&this->field_0x384 = local_38.z;
      }
      if (((fopAc_ac_c *)this->mEvTimer == (fopAc_ac_c *)0x0) ||
         (*(char *)&this->field_0x3a9 != 'o')) {
        *(float *)&this->field_0x388 = local_2c.x;
        *(float *)&this->field_0x38c = local_2c.y;
        *(float *)&this->field_0x390 = local_2c.z;
      }
      else {
        relationalPos(&local_44,this,(fopAc_ac_c *)this->mEvTimer,&local_2c);
        *(float *)&this->field_0x388 = local_44.x;
        *(float *)&this->field_0x38c = local_44.y;
        *(float *)&this->field_0x390 = local_44.z;
      }
      *(undefined4 *)this->mEvRelUseMask =
           *(undefined4 *)((int)&(this->mpEvRelActor->parent).parent.mBsType + iVar9);
      cVar7 = lineBGCheck(this,(cXyz *)&this->field_0x37c,(cXyz *)&this->field_0x388,0x8f);
      if (cVar7 == '\0') {
        local_50 = *(undefined4 *)&this->field_0x37c;
        local_4c = *(undefined4 *)&this->field_0x380;
        local_48 = *(undefined4 *)&this->field_0x384;
        local_5c.x = *(float *)&this->field_0x388;
        local_5c.y = *(float *)&this->field_0x38c;
        local_5c.z = *(float *)&this->field_0x390;
        cVar7 = @unnamed@d_ev_camera_cpp@::lineCollisionCheck
                          ((_unnamed_d_ev_camera_cpp_ *)&local_50,&local_5c,
                           (cXyz *)this->mpPlayerActor,(fopAc_ac_c *)this->mEvTimer,in_r7);
        if (cVar7 == '\0') break;
      }
      iVar9 = iVar9 + 4;
      iVar8 = iVar8 + 0xc;
    }
    *(undefined *)&this->field_0x102 = 1;
    *(undefined *)&this->field_0x101 = 1;
    *(undefined *)&this->field_0x100 = 1;
  }
  (this->field_0x44).x = *(float *)&this->field_0x37c;
  (this->field_0x44).y = *(float *)&this->field_0x380;
  (this->field_0x44).z = *(float *)&this->field_0x384;
  (this->field_0x50).x = *(float *)&this->field_0x388;
  (this->field_0x50).y = *(float *)&this->field_0x38c;
  (this->field_0x50).z = *(float *)&this->field_0x390;
  this->field_0x60 = *(float *)this->mEvRelUseMask;
  ::cXyz::operator__(&cStack104,&this->field_0x50,&this->field_0x44);
  cSGlobe::Val(&this->field_0x3c,&cStack104);
  if ((*(char *)&this->field_0x378 == '\0') ||
     ((uint)(this->mEvBasePos).x <= (uint)this->field_0x11c)) {
    uVar5 = 1;
  }
  else {
    uVar5 = 0;
  }
  return uVar5;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dCamera_c::bSplineEvCamera(void) */

undefined4 __thiscall dCamera_c::bSplineEvCamera(dCamera_c *this)

{
  int iVar1;
  void *pvVar2;
  char cVar3;
  undefined4 uVar4;
  double dVar5;
  cXyz cStack72;
  cXyz local_3c;
  cXyz local_30;
  
  uVar4 = 0;
  if (this->field_0x11c == 0) {
    *(undefined4 *)&this->field_0x388 = 9999;
    iVar1 = dEvent_manager_c::getMySubstanceNum
                      (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mStaffIdx,"Centers"
                      );
    if (iVar1 == 0) {
      return 1;
    }
    pvVar2 = dEvent_manager_c::getMySubstanceP
                       (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mStaffIdx,
                        "Centers",Xyz);
    *(void **)&this->field_0x378 = pvVar2;
    if (iVar1 < *(int *)&this->field_0x388) {
      *(int *)&this->field_0x388 = iVar1;
    }
    iVar1 = dEvent_manager_c::getMySubstanceNum
                      (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mStaffIdx,"Eyes");
    if (iVar1 == 0) {
      return 1;
    }
    pvVar2 = dEvent_manager_c::getMySubstanceP
                       (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mStaffIdx,"Eyes",
                        Xyz);
    *(void **)&this->field_0x37c = pvVar2;
    if (iVar1 < *(int *)&this->field_0x388) {
      *(int *)&this->field_0x388 = iVar1;
    }
    iVar1 = dEvent_manager_c::getMySubstanceNum
                      (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mStaffIdx,"Fovys");
    if (iVar1 == 0) {
      return 1;
    }
    pvVar2 = dEvent_manager_c::getMySubstanceP
                       (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mStaffIdx,"Fovys",
                        Float);
    *(void **)&this->field_0x380 = pvVar2;
    if (iVar1 < *(int *)&this->field_0x388) {
      *(int *)&this->field_0x388 = iVar1;
    }
    cVar3 = getEvIntData(this,(int *)&this->field_0x384,"Timer");
    if (cVar3 == '\0') {
      return 1;
    }
    d2DBSplinePath::Init
              (&this->mSpline2DPath,*(long *)&this->field_0x388,*(long *)&this->field_0x384);
    *(undefined *)&this->field_0x102 = 1;
    *(undefined *)&this->field_0x101 = 1;
    *(undefined *)&this->field_0x100 = 1;
  }
  cVar3 = d2DBSplinePath::Step(&this->mSpline2DPath);
  if (cVar3 == '\0') {
    uVar4 = 1;
  }
  else {
    d2DBSplinePath::Calc(&local_30,&this->mSpline2DPath,*(cXyz **)&this->field_0x378);
    (this->field_0x44).x = local_30.x;
    (this->field_0x44).y = local_30.y;
    (this->field_0x44).z = local_30.z;
    d2DBSplinePath::Calc(&local_3c,&this->mSpline2DPath,*(cXyz **)&this->field_0x37c);
    (this->field_0x50).x = local_3c.x;
    (this->field_0x50).y = local_3c.y;
    (this->field_0x50).z = local_3c.z;
    dVar5 = (double)d2DBSplinePath::Calc(&this->mSpline2DPath,*(float **)&this->field_0x380);
    this->field_0x60 = (float)dVar5;
    ::cXyz::operator__(&cStack72,&this->field_0x50,&this->field_0x44);
    cSGlobe::Val(&this->field_0x3c,&cStack72);
    if ((this->mSpline2DPath).mState == 3) {
      uVar4 = 1;
    }
  }
  return uVar4;
}


/* WARNING: Removing unreachable block (ram,0x800bd658) */
/* __thiscall dCamera_c::twoActor0EvCamera(void) */

undefined4 __thiscall dCamera_c::twoActor0EvCamera(dCamera_c *this)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  int iVar4;
  fopAc_ac_c *pfVar5;
  undefined4 uVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  undefined8 in_f31;
  cSAngle acStack232 [2];
  cSAngle acStack228 [2];
  cSAngle acStack224 [2];
  cSAngle acStack220 [2];
  undefined4 local_d8;
  undefined4 local_d4;
  cSGlobe cStack208;
  cXyz local_c8;
  cXyz cStack188;
  cXyz cStack176;
  cXyz cStack164;
  cXyz local_98;
  cXyz cStack140;
  cXyz cStack128;
  cXyz cStack116;
  camera_class *local_68;
  float local_64;
  float local_60;
  cXyz cStack92;
  cXyz cStack80;
  cXyz cStack68;
  cXyz local_38;
  cXyz local_2c;
  undefined auStack8 [8];
  
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (d_ev_camera::init_11318 == '\0') {
    d_ev_camera::DefaultCtrCus_11317 = d_ev_camera::_5486;
    d_ev_camera::init_11318 = '\x01';
  }
  if (d_ev_camera::init_11321 == '\0') {
    d_ev_camera::DefaultEyeCus_11320 = d_ev_camera::_5486;
    d_ev_camera::init_11321 = '\x01';
  }
  if (d_ev_camera::init_11325 == '\0') {
    d_ev_camera::DefaultGap_11323 = d_ev_camera::_4862;
    DAT_803e26d8 = d_ev_camera::_4862;
    DAT_803e26dc = d_ev_camera::_4862;
    Runtime.PPCEABI.H::__register_global_object
              (&d_ev_camera::DefaultGap_11323,::cXyz::_cXyz,&d_ev_camera::_11324);
    d_ev_camera::init_11325 = '\x01';
  }
  if (d_ev_camera::init_11328 == '\0') {
    d_ev_camera::DefaultFovy_11327 = d_ev_camera::_8896;
    d_ev_camera::init_11328 = '\x01';
  }
  if (d_ev_camera::init_11331 == '\0') {
    d_ev_camera::DefaultRadiusMin_11330 = d_ev_camera::_10315;
    d_ev_camera::init_11331 = '\x01';
  }
  if (d_ev_camera::init_11334 == '\0') {
    d_ev_camera::DefaultRadiusMax_11333 = d_ev_camera::_11502;
    d_ev_camera::init_11334 = '\x01';
  }
  if (d_ev_camera::init_11337 == '\0') {
    d_ev_camera::DefaultLatitudeMin_11336 = d_ev_camera::_11503;
    d_ev_camera::init_11337 = '\x01';
  }
  if (d_ev_camera::init_11340 == '\0') {
    d_ev_camera::DefaultLatitudeMax_11339 = d_ev_camera::_8896;
    d_ev_camera::init_11340 = '\x01';
  }
  if (d_ev_camera::init_11343 == '\0') {
    d_ev_camera::DefaultLongitudeMin_11342 = d_ev_camera::_11503;
    d_ev_camera::init_11343 = '\x01';
  }
  if (d_ev_camera::init_11346 == '\0') {
    d_ev_camera::DefaultLongitudeMax_11345 = d_ev_camera::_8896;
    d_ev_camera::init_11346 = '\x01';
  }
  if (d_ev_camera::init_11349 == '\0') {
    d_ev_camera::IllegalRatio_11348 = d_ev_camera::_11504;
    d_ev_camera::init_11349 = '\x01';
  }
  if (this->field_0x11c == 0) {
    uVar3 = getEvActor(this,"Actor1","@PLAYER");
    *(undefined4 *)&this->field_0x378 = uVar3;
    uVar3 = getEvActor(this,"Actor2","@STARTER");
    *(undefined4 *)&this->field_0x37c = uVar3;
    iVar4 = *(int *)&this->field_0x378;
    if ((iVar4 == 0) || (*(int *)&this->field_0x37c == 0)) goto LAB_800bd658;
    if (iVar4 == 0) {
      uVar3 = 0xffffffff;
    }
    else {
      uVar3 = *(undefined4 *)(iVar4 + 4);
    }
    *(undefined4 *)&this->field_0x380 = uVar3;
    if (*(int *)&this->field_0x37c == 0) {
      uVar3 = 0xffffffff;
    }
    else {
      uVar3 = *(undefined4 *)(*(int *)&this->field_0x37c + 4);
    }
    *(undefined4 *)&this->field_0x384 = uVar3;
    local_38.x = d_ev_camera::DefaultGap_11323;
    local_38.y = DAT_803e26d8;
    local_38.z = DAT_803e26dc;
    getEvXyzData(this,(cXyz *)&(this->mEvBasePos).y,"CtrGap",&local_38);
    getEvFloatData(this,&(this->mEvBasePos).x,"CtrRatio",d_ev_camera::IllegalRatio_11348);
    getEvFloatData(this,(float *)&this->field_0x388,"CtrCus",d_ev_camera::DefaultCtrCus_11317);
    getEvFloatData(this,(float *)&this->field_0x38c,"EyeCus",d_ev_camera::DefaultEyeCus_11320);
    getEvFloatData(this,(float *)&this->field_0x390,"RadiusMin",d_ev_camera::DefaultRadiusMin_11330)
    ;
    getEvFloatData(this,&this->mEvFovy,"RadiusMax",d_ev_camera::DefaultRadiusMax_11333);
    getEvFloatData(this,&this->mEvBank,"LatitudeMin",d_ev_camera::DefaultLatitudeMin_11336);
    getEvFloatData(this,(float *)&this->mpEvRelActor,"LatitudeMax",
                   d_ev_camera::DefaultLatitudeMax_11339);
    getEvFloatData(this,(float *)this->mEvRelUseMask,"LongitudeMin",
                   d_ev_camera::DefaultLongitudeMin_11342);
    getEvFloatData(this,(float *)&this->mEvTimer,"LongitudeMax",
                   d_ev_camera::DefaultLongitudeMax_11345);
    getEvFloatData(this,(float *)&this->field_0x3a8,"Fovy",d_ev_camera::DefaultFovy_11327);
    *(float *)&this->field_0x3bc = (this->field_0x3c).mDistance;
    dVar7 = (double)cSAngle::Degree(&(this->field_0x3c).mAngleX);
    *(float *)&this->field_0x3c0 = (float)dVar7;
    dVar7 = (double)cSAngle::Degree(&(this->field_0x3c).mAngleY);
    *(float *)&this->field_0x3c4 = (float)dVar7;
  }
  attentionPos(&cStack68,this,*(fopAc_ac_c **)&this->field_0x378);
  attentionPos(&cStack80,this,*(fopAc_ac_c **)&this->field_0x37c);
  ::cXyz::operator__(&cStack92,&cStack68,&cStack80);
  cSGlobe::cSGlobe(&cStack208,&cStack92);
  local_d4 = *(undefined4 *)&this->field_0x380;
  pfVar5 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,&local_d4);
  if (pfVar5 != (fopAc_ac_c *)0x0) {
    local_d8 = *(undefined4 *)&this->field_0x384;
    pfVar5 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,&local_d8);
    if (pfVar5 != (fopAc_ac_c *)0x0) {
      fVar1 = (this->mEvBasePos).x;
      if ((fVar1 < d_ev_camera::_4862) || (d_ev_camera::_5486 < fVar1)) {
        relationalPos((dCamera_c *)&local_68,(fopAc_ac_c *)this,*(fopAc_ac_c **)&this->field_0x378,
                      *(cXyz **)&this->field_0x37c,d_ev_camera::_9870);
        local_2c.x = (float)local_68;
        local_2c.y = local_64;
        local_2c.z = local_60;
      }
      else {
        attentionPos(&cStack116,this,*(fopAc_ac_c **)&this->field_0x378);
        attentionPos(&cStack128,this,*(fopAc_ac_c **)&this->field_0x37c);
        ::cXyz::operator__(&cStack140,&cStack116,&cStack128);
        ::cXyz::operator_(&local_98,&cStack140,(this->mEvBasePos).x);
        local_2c.x = local_98.x;
        local_2c.y = local_98.y;
        local_2c.z = local_98.z;
      }
      ::cXyz::operator__(&cStack164,&local_2c,&this->field_0x44);
      ::cXyz::operator_(&cStack176,&cStack164,*(float *)&this->field_0x388);
      mtx::PSVECAdd(&this->field_0x44,&cStack176,&this->field_0x44);
      cSAngle::operator__(acStack220,&cStack208.mAngleY);
      cSAngle::cSAngle(acStack224,acStack220);
      dVar8 = (double)cSAngle::Degree(acStack224);
      dVar7 = (double)*(float *)this->mEvRelUseMask;
      if ((dVar7 <= (double)*(float *)&this->field_0x3c4) &&
         (dVar7 = dVar8, (double)(float)this->mEvTimer < (double)*(float *)&this->field_0x3c4)) {
        dVar7 = (double)(float)this->mEvTimer;
      }
      dVar8 = (double)cSAngle::Degree(&cStack208.mAngleY);
      *(float *)&this->field_0x3c4 =
           *(float *)&this->field_0x3c4 +
           *(float *)&this->field_0x38c * ((float)(dVar7 + dVar8) - *(float *)&this->field_0x3c4);
      dVar8 = (double)cSAngle::Degree(&(this->field_0x3c).mAngleX);
      dVar9 = (double)*(float *)&this->field_0x3c0;
      dVar7 = (double)this->mEvBank;
      if ((dVar7 <= dVar9) && (dVar7 = dVar8, (double)(float)this->mpEvRelActor < dVar9)) {
        dVar7 = (double)(float)this->mpEvRelActor;
      }
      *(float *)&this->field_0x3c0 =
           *(float *)&this->field_0x3c0 + *(float *)&this->field_0x38c * (float)(dVar7 - dVar9);
      fVar1 = *(float *)&this->field_0x3bc;
      fVar2 = *(float *)&this->field_0x390;
      if ((fVar2 <= fVar1) && (fVar2 = (this->field_0x3c).mDistance, this->mEvFovy < fVar1)) {
        fVar2 = this->mEvFovy;
      }
      *(float *)&this->field_0x3bc =
           *(float *)&this->field_0x3bc + *(float *)&this->field_0x38c * (fVar2 - fVar1);
      cSAngle::cSAngle(acStack228,*(float *)&this->field_0x3c0);
      cSAngle::cSAngle(acStack232,*(float *)&this->field_0x3c4);
      cSGlobe::Val(&this->field_0x3c,*(float *)&this->field_0x3bc,acStack228,acStack232);
      cSGlobe::Xyz(&cStack188,&this->field_0x3c);
      ::cXyz::operator__(&local_c8,&this->field_0x44,&cStack188);
      (this->field_0x50).x = local_c8.x;
      (this->field_0x50).y = local_c8.y;
      (this->field_0x50).z = local_c8.z;
      this->field_0x60 =
           this->field_0x60 +
           *(float *)&this->field_0x388 * (*(float *)&this->field_0x3a8 - this->field_0x60);
    }
  }
LAB_800bd658:
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  return 1;
}

