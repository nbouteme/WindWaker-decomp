#include <d_map.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <d_save.h>
#include <d_stage.h>
#include <d_map.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <MSL_C.PPCEABI.bare.H/printf.h>
#include <d_resorce.h>
#include <m_Do_lib.h>
#include <d_drawlist.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <m_Do_gba_com.h>
#include <gx/GXAttr.h>
#include <gx/GXLight.h>
#include <gx/GXTev.h>
#include <gx/GXPixel.h>
#include <gx/GXGeometry.h>
#include <d_a_agb.h>
#include <MSL_C.PPCEABI.bare.H/s_floor.h>
#include <d_attention.h>
#include <gx/GXTexture.h>
#include <MSL_C.PPCEABI.bare.H/w_fmod.h>
#include <gx/GXTransform.h>
#include <mtx/mtx.h>
#include <m_Do_mtx.h>
#include <os/OSCache.h>
#include <JKernel/JKRArchivePub.h>
#include <f_op_msg_mng.h>
#include <JKernel/JKRHeap.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <dMap_RoomInfoCtrl_c.h>
#include <dMap_2DTri_c.h>
#include <dMap_2DAGBScrDsp_c.h>
#include <dMap_2DAGBCursor_c.h>
#include <dMap_2DSQ_c.h>
#include <dMap_2DT2_c.h>
#include <dMap_2DMtMapSpcl_tex_c.h>
#include <dMap_2DPoint_c.h>
#include <dMap_2DMtMapSpcl_c.h>
#include <dMap_Dmap_c.h>
#include <dDlst_base_c.h>
#include <dMap_RoomInfo_c.h>
#include <dMap_c.h>

struct JKRExpHeap * dMap_c;
struct JKRExpHeap * dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
struct dMap__CollectPointData dMap_c[64];
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
byte dMap_c;
struct FmapChkPnt * dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
float dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
undefined1 dMap_c;
struct dMap_RoomInfoCtrl_c dMap_c;
undefined1 dMap_c;

namespace d_map {

/* __stdcall onSaveArriveGridForAgbUseGridPos(int,
                                              int) */

void onSaveArriveGridForAgbUseGridPos(int param_1,int param_2)

{
  bool bVar1;
  ulong uVar2;
  
  bVar1 = false;
  if ((((-4 < param_1) && (param_1 < 4)) && (-4 < param_2)) && (param_2 < 4)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar2,"d_map.cpp",0x4a4,
               "(i_gridX >= -3) && (i_gridX <= 3) && (i_gridY >= -3) && (i_gridY <= 3)");
    m_Do_printf::OSPanic("d_map.cpp",0x4a4,&DAT_8034f1dd);
  }
  dSv_player_map_c::onSaveArriveGridForAgb
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,
             param_1 + (param_2 + 3) * 7 + 3);
  return;
}


/* __stdcall isSaveArriveGridForAgbUseGridPos(int,
                                              int) */

void isSaveArriveGridForAgbUseGridPos(int param_1,int param_2)

{
  bool bVar1;
  ulong uVar2;
  
  bVar1 = false;
  if ((((-4 < param_1) && (param_1 < 4)) && (-4 < param_2)) && (param_2 < 4)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar2,"d_map.cpp",0x4a4,
               "(i_gridX >= -3) && (i_gridX <= 3) && (i_gridY >= -3) && (i_gridY <= 3)");
    m_Do_printf::OSPanic("d_map.cpp",0x4a4,&DAT_8034f1dd);
  }
  dSv_player_map_c::isSaveArriveGridForAgb
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,
             param_1 + (param_2 + 3) * 7 + 3);
  return;
}


/* __stdcall IsFloorNo(int) */

undefined4 IsFloorNo(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((0x7a < param_1) && (param_1 < 0x85)) {
    uVar1 = 1;
  }
  return uVar1;
}


/* __stdcall getFloorInfo_WithRoom(int) */

int getFloorInfo_WithRoom(int param_1)

{
  dStage_roomStatus_c *pdVar1;
  int iVar2;
  
  iVar2 = 0;
  if ((-1 < param_1) &&
     (pdVar1 = dStage_roomControl_c::getStatusRoomDt
                         (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mRoomCtrl,param_1),
     pdVar1 != (dStage_roomStatus_c *)0x0)) {
    iVar2 = (*(code *)((pdVar1->parent).parent.vtbl)->getFloorInfo)();
  }
  if (iVar2 == 0) {
    iVar2 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getFloorInfo)();
  }
  return iVar2;
}


/* WARNING: Removing unreachable block (ram,0x800458c0) */
/* __stdcall mapOffsetY(void) */

double mapOffsetY(void)

{
  int iVar1;
  stage_stag_info_class *pStg0;
  stage_stag_info_class *pStg1;
  int iVar2;
  int *piVar3;
  ulong uVar4;
  undefined4 uVar5;
  undefined8 in_f31;
  double dVar6;
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  dVar6 = (double)_4426;
  pStg0 = (stage_stag_info_class *)
          (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)
                    (0x803c9d58);
  if ((((pStg0->mStageTypeAndSchbit >> 0x10 & 7) == 3) ||
      (pStg1 = (stage_stag_info_class *)
               (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)
                         (0x803c9d58), (pStg1->mStageTypeAndSchbit >> 0x10 & 7) == 6)) &&
     (iVar2 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getDMap)
                        (0x803c9d58), iVar2 != 0)) {
    piVar3 = (int *)(*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getDMap)
                              (0x803c9d58);
    iVar2 = piVar3[1];
    if (*piVar3 != 1) {
      uVar4 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar4,"d_map.cpp",0x587,"pinf->num == 1");
      m_Do_printf::OSPanic("d_map.cpp",0x587,&DAT_8034f1dd);
    }
    iVar1 = *piVar3;
    if (0 < iVar1) {
      do {
        dVar6 = (double)*(float *)(iVar2 + 0xc);
        iVar2 = iVar2 + 0x10;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
    }
  }
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  return dVar6;
}


/* __stdcall dMap_GetTopBottomFloorNo(dStage_dt_c *,
                                      unsigned char *,
                                      unsigned char *) */

undefined4 dMap_GetTopBottomFloorNo(dStage_dt_c *param_1,byte *param_2,byte *param_3)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  byte bVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  if (param_1 != (dStage_dt_c *)0x0) {
    piVar2 = (int *)(*(code *)param_1->vtbl->getFloorInfo)();
    if ((piVar2 == (int *)0x0) || (*piVar2 < 1)) {
      bVar4 = 0x80;
      bVar5 = 0x80;
    }
    else {
      iVar6 = piVar2[1];
      bVar4 = 0x7b;
      bVar5 = 0x84;
      for (iVar7 = 0; iVar7 < *piVar2; iVar7 = iVar7 + 1) {
        iVar3 = 0;
        iVar8 = 0xe;
        do {
          if (*(char *)(iVar6 + iVar3 + 5) != -1) {
            bVar1 = *(byte *)(iVar6 + 4);
            if (bVar4 < bVar1) {
              bVar4 = bVar1;
            }
            if (bVar1 < bVar5) {
              bVar5 = bVar1;
            }
            break;
          }
          iVar3 = iVar3 + 1;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
        iVar6 = iVar6 + 0x14;
      }
    }
    if (param_2 != (byte *)0x0) {
      *param_2 = bVar4;
    }
    if (param_3 != (byte *)0x0) {
      *param_3 = bVar5;
    }
  }
  return 0;
}


/* __stdcall dMap_GetFloorInfoDtP(dStage_FloorInfo_c *,
                                  float) */

float * dMap_GetFloorInfoDtP(double param_1,float *param_2)

{
  bool bVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  
  bVar1 = false;
  if ((param_2 != (float *)0x0) && (fVar2 = *param_2, 0 < (int)fVar2)) {
    param_2 = (float *)param_2[1];
    iVar3 = 0;
    fVar4 = fVar2;
    if (0 < (int)fVar2) {
      do {
        if (iVar3 == (int)fVar2 + -1) {
          if ((fVar2 == 1.401298e-45) || ((double)*param_2 <= param_1)) {
            bVar1 = true;
            break;
          }
        }
        else {
          if (iVar3 == 0) {
            if (param_1 < (double)param_2[5]) {
              bVar1 = true;
              break;
            }
          }
          else {
            if (((double)*param_2 <= param_1) && (param_1 < (double)param_2[5])) {
              bVar1 = true;
              break;
            }
          }
        }
        iVar3 = iVar3 + 1;
        param_2 = param_2 + 5;
        fVar4 = (float)((int)fVar4 + -1);
      } while (fVar4 != 0.0);
    }
  }
  if (bVar1) {
    return param_2;
  }
  return (float *)0x0;
}


/* __stdcall dMap_GetFloorInfoDtPFromFloorNo(dStage_FloorInfo_c *,
                                             unsigned char) */

int dMap_GetFloorInfoDtPFromFloorNo(int *param_1,char param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  
  bVar1 = false;
  if (param_1 != (int *)0x0) {
    param_3 = param_1[1];
    iVar2 = *param_1;
    if (0 < iVar2) {
      do {
        if (param_2 == *(char *)(param_3 + 4)) {
          bVar1 = true;
          break;
        }
        param_3 = param_3 + 0x14;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
  }
  if (!bVar1) {
    param_3 = 0;
  }
  return param_3;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x80045c04) */
/* __stdcall dMap_GetFloorNoForDmap(dStage_dt_c *,
                                    int,
                                    float) */

undefined dMap_GetFloorNoForDmap(double param_1,int *param_2,int param_3)

{
  float fVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  float *pfVar5;
  int iVar6;
  undefined uVar7;
  undefined4 uVar8;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  uVar8 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  piVar3 = (int *)(**(code **)(*param_2 + 0xf8))();
  uVar7 = 0x80;
  iVar4 = dMap_GetFloorInfoDtP(param_1);
  if (iVar4 != 0) {
    bVar2 = false;
    for (iVar6 = 0; (!bVar2 && (iVar6 < 0xe)); iVar6 = iVar6 + 1) {
      if (*(char *)(iVar4 + iVar6 + 5) == param_3) {
        bVar2 = true;
        uVar7 = *(undefined *)(iVar4 + 4);
      }
    }
    if (!bVar2) {
      pfVar5 = (float *)piVar3[1];
      fVar1 = _4550;
      for (iVar4 = 0; iVar4 < *piVar3; iVar4 = iVar4 + 1) {
        bVar2 = false;
        for (iVar6 = 0; (!bVar2 && (iVar6 < 0xe)); iVar6 = iVar6 + 1) {
          if (*(char *)((int)pfVar5 + iVar6 + 5) == param_3) {
            bVar2 = true;
          }
        }
        if ((bVar2) && (ABS((float)((double)*pfVar5 - param_1)) < fVar1)) {
          uVar7 = *(undefined *)(pfVar5 + 1);
          fVar1 = ABS((float)((double)*pfVar5 - param_1));
        }
        pfVar5 = pfVar5 + 5;
      }
    }
  }
  __psq_l0(auStack8,uVar8);
  __psq_l1(auStack8,uVar8);
  return uVar7;
}


/* __stdcall dMap_GetFloorNo_WithRoom(int,
                                      float) */

undefined dMap_GetFloorNo_WithRoom(undefined8 param_1)

{
  int iVar1;
  undefined uVar2;
  
  getFloorInfo_WithRoom();
  iVar1 = dMap_GetFloorInfoDtP(param_1);
  if (iVar1 == 0) {
    uVar2 = 0x80;
  }
  else {
    uVar2 = *(undefined *)(iVar1 + 4);
  }
  return uVar2;
}


/* __stdcall dMap_GetFloorNo(dStage_dt_c *,
                             float) */

void dMap_GetFloorNo(void)

{
  dMap_GetFloorNo_WithRoom(0xffffffff);
  return;
}

}

/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dMap_RoomInfo_c::getRoomDspFloorNo(unsigned char,
                                                 int) */

byte __thiscall dMap_RoomInfo_c::getRoomDspFloorNo(dMap_RoomInfo_c *this,uchar param_1,int param_2)

{
  bool bVar1;
  ulong uVar2;
  char cVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = param_1 - 0x7b;
  bVar1 = false;
  if ((-1 < iVar5) && (iVar5 < 10)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar2,"d_map.cpp",0x702,"(no >= 0) && (no < (Floor_5F - Floor_B5F + 1))");
    m_Do_printf::OSPanic("d_map.cpp",0x702,&DAT_8034f1dd);
  }
  bVar4 = this->field_0x2[param_1 - 0x7b];
  if ((param_2 != 0) && (cVar3 = d_map::IsFloorNo(bVar4), cVar3 == '\0')) {
    while ((cVar3 = d_map::IsFloorNo(bVar4), iVar6 = iVar5, cVar3 == '\0' &&
           (iVar6 = iVar5 + -1, -1 < iVar6))) {
      bVar1 = false;
      if ((-1 < iVar6) && (iVar6 < 10)) {
        bVar1 = true;
      }
      if (!bVar1) {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert
                  (uVar2,"d_map.cpp",0x70f,"(no >= 0) && (no < (Floor_5F - Floor_B5F + 1))");
        m_Do_printf::OSPanic("d_map.cpp",0x70f,&DAT_8034f1dd);
      }
      bVar4 = this->field_0x2[iVar5 + -1];
      iVar5 = iVar6;
    }
    cVar3 = d_map::IsFloorNo(bVar4);
    if (cVar3 == '\0') {
      while ((cVar3 = d_map::IsFloorNo(bVar4), cVar3 == '\0' && (iVar5 = iVar6 + 1, iVar5 < 10))) {
        bVar1 = false;
        if ((-1 < iVar5) && (iVar5 < 10)) {
          bVar1 = true;
        }
        if (!bVar1) {
          uVar2 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert
                    (uVar2,"d_map.cpp",0x718,"(no >= 0) && (no < (Floor_5F - Floor_B5F + 1))");
          m_Do_printf::OSPanic("d_map.cpp",0x718,&DAT_8034f1dd);
        }
        bVar4 = this->field_0x2[iVar6 + 1];
        iVar6 = iVar5;
      }
      cVar3 = d_map::IsFloorNo(bVar4);
      if (cVar3 == '\0') {
        bVar4 = 0xff;
      }
    }
  }
  return bVar4;
}


/* __thiscall dMap_RoomInfo_c::init(dMap_RoomInfo_c *,
                                    int) */

void __thiscall dMap_RoomInfo_c::init(dMap_RoomInfo_c *this,dMap_RoomInfo_c *param_1,int param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  
  this->field_0x0 = 0;
  this->field_0x1 = 0;
  iVar2 = 0;
  iVar3 = 10;
  do {
    this->field_0x2[iVar2] = 0xff;
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  this->field_0xc = 0xff;
  this->field_0x10 = -1;
  this->field_0x14 = param_2;
  fVar1 = d_map::_4426;
  this->field_0x18 = d_map::_4426;
  this->field_0x1c = fVar1;
  this->field_0x20 = fVar1;
  this->field_0x24 = fVar1;
  dMap_2DAGBScrDsp_c::init((dMap_2DAGBScrDsp_c *)&this->field_0x8c,(EVP_PKEY_CTX *)0x0);
  *(undefined *)&this->field_0x44 = 0;
  dMap_2DMtMapSpcl_c::init((dMap_2DMtMapSpcl_c *)&this->field_0x30,(EVP_PKEY_CTX *)&DAT_00000001);
  *(undefined4 *)&this->field_0xe4 = 0;
  *(undefined4 *)&this->field_0xe8 = 0;
  if (param_1 != (dMap_RoomInfo_c *)0x0) {
    *(dMap_RoomInfo_c **)&param_1->field_0xe4 = this;
  }
  return;
}


/* WARNING: Inlined function: __save_gpr */
/* WARNING: Inlined function: __restore_gpr */
/* WARNING: Removing unreachable block (ram,0x800462f4) */
/* __thiscall dMap_RoomInfo_c::getRoomImage(int,
                                            unsigned char,
                                            int,
                                            ResTIMG * *,
                                            ResTIMG * *,
                                            map_dt_c * *,
                                            stage_map_info_class * *,
                                            unsigned char *) */

uint __thiscall
dMap_RoomInfo_c::getRoomImage
          (dMap_RoomInfo_c *this,int param_1,uchar param_2,int param_3,ResTIMG **param_4,
          ResTIMG **param_5,map_dt_c **param_6,stage_map_info_class **param_7,uchar *param_8)

{
  bool bVar1;
  char cVar4;
  dStage_roomStatus_c *pdVar2;
  ulong uVar3;
  undefined3 in_register_00000014;
  uint uVar5;
  byte bVar6;
  uint unaff_r23;
  uint uVar7;
  stage_map_info_class *psVar8;
  map_dt_c *pmVar9;
  ResTIMG *pRVar10;
  ResTIMG *pRVar11;
  undefined4 uVar12;
  undefined8 in_f31;
  double dVar13;
  char acStack164 [32];
  char acStack132 [44];
  undefined auStack8 [8];
  
  uVar7 = CONCAT31(in_register_00000014,param_2);
  uVar12 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  bVar1 = false;
  pRVar11 = (ResTIMG *)0x0;
  pRVar10 = (ResTIMG *)0x0;
  pmVar9 = (map_dt_c *)0x0;
  psVar8 = (stage_map_info_class *)0x0;
  bVar6 = 0;
  cVar4 = d_map::IsFloorNo(param_2);
  if (cVar4 != '\0') {
    MSL_C.PPCEABI.bare.H::sprintf(acStack132,"Room%d",param_1);
    do {
      if (bVar1) break;
      uVar5 = uVar7 & 0xff;
      cVar4 = d_map::IsFloorNo(uVar5);
      if (cVar4 == '\0') break;
      MSL_C.PPCEABI.bare.H::sprintf(acStack164,"s%d.bti",uVar5);
      pRVar11 = (ResTIMG *)
                dRes_control_c::getRes
                          (acStack132,acStack164,
                           d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mStageInfo,0x40);
      MSL_C.PPCEABI.bare.H::sprintf(acStack164,"m%d.bti",uVar5);
      pRVar10 = (ResTIMG *)
                dRes_control_c::getRes
                          (acStack132,acStack164,
                           d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mStageInfo,0x40);
      MSL_C.PPCEABI.bare.H::sprintf(acStack164,"m%d.amp",uVar5);
      pmVar9 = (map_dt_c *)
               dRes_control_c::getRes
                         (acStack132,acStack164,
                          d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mStageInfo,0x40);
      psVar8 = (stage_map_info_class *)0x0;
      uVar5 = uVar7;
      while (psVar8 == (stage_map_info_class *)0x0) {
        cVar4 = d_map::IsFloorNo(uVar5 & 0xff);
        if (cVar4 == '\0') break;
        pdVar2 = dStage_roomControl_c::getStatusRoomDt
                           (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mRoomCtrl,param_1);
        psVar8 = (stage_map_info_class *)
                 (*(code *)((pdVar2->parent).parent.vtbl)->getMapInfo2)(pdVar2,uVar5 & 0xff);
        uVar5 = uVar5 - 1;
      }
      if ((((pRVar11 == (ResTIMG *)0x0) || (pRVar10 == (ResTIMG *)0x0)) ||
          (pmVar9 == (map_dt_c *)0x0)) || (psVar8 == (stage_map_info_class *)0x0)) {
        uVar7 = uVar7 - 1;
      }
      else {
        bVar1 = true;
      }
    } while (param_3 != 0);
    if (((pRVar11 != (ResTIMG *)0x0) && (psVar8 != (stage_map_info_class *)0x0)) &&
       ((*(float *)&psVar8->field_0x8 != *(float *)psVar8 &&
        (*(float *)&psVar8->field_0xc != *(float *)&psVar8->field_0x4)))) {
      bVar6 = 2;
    }
    unaff_r23 = uVar7;
    if ((pRVar10 != (ResTIMG *)0x0) &&
       ((((pRVar10->mWidth == 0x80 && (pRVar10->mHeight < 0x1e1)) ||
         (((pRVar10->mWidth & 7) == 0 && (pRVar10->mHeight == 8)))) &&
        (psVar8 != (stage_map_info_class *)0x0)))) {
      if (psVar8 == (stage_map_info_class *)0x0) {
        uVar3 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar3,"d_map.cpp",0x2cf,"i_mapInfoP != 0");
        m_Do_printf::OSPanic("d_map.cpp",0x2cf,&DAT_8034f1dd);
      }
      dVar13 = (double)*(float *)&psVar8->field_0x18;
      if (psVar8 == (stage_map_info_class *)0x0) {
        uVar3 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar3,"d_map.cpp",0x2db,"i_mapInfoP != 0");
        m_Do_printf::OSPanic("d_map.cpp",0x2db,&DAT_8034f1dd);
      }
      if ((double)*(float *)&psVar8->field_0x20 != dVar13) {
        if (psVar8 == (stage_map_info_class *)0x0) {
          uVar3 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar3,"d_map.cpp",0x2d5,"i_mapInfoP != 0");
          m_Do_printf::OSPanic("d_map.cpp",0x2d5,&DAT_8034f1dd);
        }
        dVar13 = (double)*(float *)&psVar8->field_0x1c;
        if (psVar8 == (stage_map_info_class *)0x0) {
          uVar3 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar3,"d_map.cpp",0x2e1,"i_mapInfoP != 0");
          m_Do_printf::OSPanic("d_map.cpp",0x2e1,&DAT_8034f1dd);
        }
        if ((double)*(float *)&psVar8->field_0x24 != dVar13) {
          bVar6 = bVar6 | 1;
        }
      }
    }
  }
  if (bVar6 != 3) {
    bVar6 = 0;
  }
  if (param_4 != (ResTIMG **)0x0) {
    *param_4 = pRVar11;
  }
  if (param_5 != (ResTIMG **)0x0) {
    *param_5 = pRVar10;
  }
  if (param_6 != (map_dt_c **)0x0) {
    *param_6 = pmVar9;
  }
  if (param_7 != (stage_map_info_class **)0x0) {
    *param_7 = psVar8;
  }
  if (param_8 != (uchar *)0x0) {
    *param_8 = bVar6;
  }
  if (!bVar1) {
    unaff_r23 = 0xff;
  }
  __psq_l0(auStack8,uVar12);
  __psq_l1(auStack8,uVar12);
  return unaff_r23;
}


/* WARNING: Inlined function: FUN_80328f24 */
/* WARNING: Inlined function: FUN_80328f70 */
/* __thiscall dMap_RoomInfo_c::makeRoomDspFloorNoTbl(int) */

undefined4 __thiscall dMap_RoomInfo_c::makeRoomDspFloorNoTbl(dMap_RoomInfo_c *this,int param_1)

{
  byte bVar1;
  bool bVar2;
  int *piVar3;
  char cVar5;
  byte bVar6;
  ulong uVar4;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  
  piVar3 = (int *)d_map::getFloorInfo_WithRoom(param_1);
  iVar7 = 0;
  iVar10 = 10;
  do {
    this->field_0x2[iVar7] = 0xff;
    iVar7 = iVar7 + 1;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  if (piVar3 == (int *)0x0) {
    this->field_0x2[5] = 0x80;
  }
  else {
    iVar10 = piVar3[1];
    for (iVar7 = 0; iVar7 < *piVar3; iVar7 = iVar7 + 1) {
      bVar1 = *(byte *)(iVar10 + 4);
      uVar9 = (uint)bVar1;
      cVar5 = d_map::IsFloorNo(uVar9);
      if (cVar5 != '\0') {
        iVar8 = 0;
        do {
          if (param_1 == *(char *)(iVar10 + iVar8 + 5)) {
            bVar6 = getRoomImage(this,param_1,bVar1,1,(ResTIMG **)0x0,(ResTIMG **)0x0,
                                 (map_dt_c **)0x0,(stage_map_info_class **)0x0,(uchar *)0x0);
            bVar2 = false;
            if ((-1 < (int)(uVar9 - 0x7b)) && ((int)(uVar9 - 0x7b) < 10)) {
              bVar2 = true;
            }
            if (!bVar2) {
              uVar4 = JUTAssertion::getSDevice();
              JUTAssertion::showAssert
                        (uVar4,"d_map.cpp",0x893,
                         "((floorNo - Floor_B5F) >= 0) && ((floorNo - Floor_B5F) < (Floor_5F - Floor_B5F + 1))"
                        );
              m_Do_printf::OSPanic("d_map.cpp",0x893,&DAT_8034f1dd);
            }
            this->field_0x2[uVar9 - 0x7b] = bVar6;
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 < 0xe);
      }
      iVar10 = iVar10 + 0x14;
    }
  }
  return 1;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x80046a30) */
/* WARNING: Removing unreachable block (ram,0x80046a38) */
/* __thiscall dMap_RoomInfo_c::roomEntryRoom(int,
                                             unsigned char,
                                             int,
                                             unsigned char,
                                             dMap_RoomInfo_c *,
                                             short,
                                             short,
                                             float) */

dMap_RoomInfo_c * __thiscall
dMap_RoomInfo_c::roomEntryRoom
          (dMap_RoomInfo_c *this,int param_1,uchar param_2,int param_3,uchar param_4,
          dMap_RoomInfo_c *param_5,short param_6,short param_7,float param_8)

{
  stage_map_info_class *psVar1;
  stage_map_info_class *psVar2;
  uint uVar3;
  ulong uVar4;
  byte bVar5;
  char cVar6;
  stage_stag_info_class *local_r3_1216;
  stage_stag_info_class *pStag;
  undefined4 uVar7;
  double dVar8;
  undefined8 in_f30;
  double dVar9;
  undefined8 in_f31;
  byte local_60 [4];
  undefined4 local_5c;
  stage_map_info_class *local_58;
  undefined2 *local_54;
  ResTIMG *local_50;
  ResTIMG *local_4c;
  undefined4 local_48;
  uint uStack68;
  undefined4 local_40;
  uint uStack60;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar8 = (double)param_8;
  uVar7 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  if (param_1 < 0) {
    uVar4 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar4,"d_map.cpp",0x8c1,"i_roomNo >= 0");
    m_Do_printf::OSPanic("d_map.cpp",0x8c1,&DAT_8034f1dd);
  }
  if (this->field_0x0 == 0) {
    this->field_0x1 = 0;
    *(undefined4 *)&this->field_0xe8 = 0;
    local_60[0] = 0;
    makeRoomDspFloorNoTbl(this,param_1);
    uVar3 = countLeadingZeros(param_3 - param_1);
    bVar5 = getRoomDspFloorNo(this,param_2,uVar3 >> 5 & 0xff);
    local_4c = (ResTIMG *)0x0;
    local_50 = (ResTIMG *)0x0;
    local_54 = (undefined2 *)0x0;
    local_58 = (stage_map_info_class *)0x0;
    cVar6 = d_map::IsFloorNo(bVar5);
    if (cVar6 != '\0') {
      getRoomImage(this,param_1,bVar5,0,&local_4c,&local_50,(map_dt_c **)&local_54,&local_58,
                   local_60);
    }
    if (local_60[0] != 3) {
      local_60[0] = 0;
    }
    this->field_0x10 = param_1;
    this->field_0xc = bVar5;
    if (param_1 != -1) {
      *(stage_map_info_class **)&this->field_0xe8 = local_58;
      *(undefined *)&this->field_0x44 = 0;
      if (local_60[0] != 3) {
        local_60[0] = 0;
      }
      this->field_0x1 = local_60[0];
      if ((local_60[0] & 2) == 0) {
        *(undefined *)&this->field_0x44 = 0;
      }
      else {
        local_5c = d_map::_4740;
        dMap_2DMtMapSpcl_tex_c::init
                  ((dMap_2DMtMapSpcl_tex_c *)&this->field_0x44,(EVP_PKEY_CTX *)local_4c);
        dMap_2DMtMapSpcl_tex_c::setScroll
                  ((dMap_2DMtMapSpcl_tex_c *)&this->field_0x44,d_map::_4426,d_map::_4426,
                   d_map::_4611,d_map::_4611);
        *(undefined *)&this->field_0x44 = 1;
        dVar9 = d_map::_4818;
        if (local_58 == (stage_map_info_class *)0x0) {
          uVar4 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar4,"d_map.cpp",0x91b,"0");
          m_Do_printf::OSPanic("d_map.cpp",0x91b,&DAT_8034f1dd);
        }
        else {
          uStack68 = (int)param_6 ^ 0x80000000;
          local_48 = 0x43300000;
          this->field_0x18 =
               (float)((double)CONCAT44(0x43300000,uStack68) - d_map::_4818) /
               (*(float *)&local_58->field_0x8 - *(float *)local_58);
          uStack60 = (int)param_7 ^ 0x80000000;
          local_40 = 0x43300000;
          this->field_0x1c =
               (float)((double)CONCAT44(0x43300000,uStack60) - dVar9) /
               (*(float *)&local_58->field_0xc - *(float *)&local_58->field_0x4);
        }
      }
      dMap_2DMtMapSpcl_c::init
                ((dMap_2DMtMapSpcl_c *)&this->field_0x30,(EVP_PKEY_CTX *)&DAT_00000001);
      if ((local_60[0] & 1) != 0) {
        if (local_54 == (undefined2 *)0x0) {
          uVar4 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar4,"d_map.cpp",0x92a,"l_mapDtP != 0");
          m_Do_printf::OSPanic("d_map.cpp",0x92a,&DAT_8034f1dd);
        }
        if (local_50 == (ResTIMG *)0x0) {
          uVar4 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar4,"d_map.cpp",0x92b,"l_image1P != 0");
          m_Do_printf::OSPanic("d_map.cpp",0x92b,&DAT_8034f1dd);
        }
        if (local_58 == (stage_map_info_class *)0x0) {
          uVar4 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar4,"d_map.cpp",0x92c,"l_mapInfoP != 0");
          m_Do_printf::OSPanic("d_map.cpp",0x92c,&DAT_8034f1dd);
        }
        dMap_2DAGBScrDsp_c::setImage
                  ((dMap_2DAGBScrDsp_c *)&this->field_0x8c,local_50,(map_dt_c *)local_54);
        uStack60 = m_Do_lib::mDoLib_cnvind16(*local_54);
        uStack60 = uStack60 & 0xffff;
        local_40 = 0x43300000;
        *(float *)&this->field_0x28 = (float)((double)CONCAT44(0x43300000,uStack60) - d_map::_4820);
        uStack68 = m_Do_lib::mDoLib_cnvind16(local_54[1]);
        psVar1 = local_58;
        uStack68 = uStack68 & 0xffff;
        local_48 = 0x43300000;
        *(float *)&this->field_0x2c = (float)((double)CONCAT44(0x43300000,uStack68) - d_map::_4820);
        if (local_58 == (stage_map_info_class *)0x0) {
          uVar4 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar4,"d_map.cpp",0x2cf,"i_mapInfoP != 0");
          m_Do_printf::OSPanic("d_map.cpp",0x2cf,&DAT_8034f1dd);
        }
        psVar2 = local_58;
        dVar9 = (double)*(float *)&psVar1->field_0x18;
        if (local_58 == (stage_map_info_class *)0x0) {
          uVar4 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar4,"d_map.cpp",0x2db,"i_mapInfoP != 0");
          m_Do_printf::OSPanic("d_map.cpp",0x2db,&DAT_8034f1dd);
        }
        psVar1 = local_58;
        this->field_0x20 =
             *(float *)&this->field_0x28 / (float)((double)*(float *)&psVar2->field_0x20 - dVar9);
        if (local_58 == (stage_map_info_class *)0x0) {
          uVar4 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar4,"d_map.cpp",0x2d5,"i_mapInfoP != 0");
          m_Do_printf::OSPanic("d_map.cpp",0x2d5,&DAT_8034f1dd);
        }
        psVar2 = local_58;
        dVar9 = (double)*(float *)&psVar1->field_0x1c;
        if (local_58 == (stage_map_info_class *)0x0) {
          uVar4 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar4,"d_map.cpp",0x2e1,"i_mapInfoP != 0");
          m_Do_printf::OSPanic("d_map.cpp",0x2e1,&DAT_8034f1dd);
        }
        this->field_0x24 =
             *(float *)&this->field_0x2c / (float)((double)*(float *)&psVar2->field_0x24 - dVar9);
        local_r3_1216 =
             (stage_stag_info_class *)
             (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)
                       (0x803c9d58);
        if ((local_r3_1216->mStageTypeAndSchbit >> 0x10 & 7) == 1) {
          if (d_map::18_0 <= *(float *)&local_58->field_0x30) {
            *(undefined *)(local_54 + 0x19) = 1;
          }
          else {
            *(undefined *)(local_54 + 0x19) = 0;
          }
          if (param_2 < 0x80) {
            *(uchar *)(local_54 + 3) = param_2 + 0x80;
          }
          else {
            *(uchar *)(local_54 + 3) = param_2 + 0x81;
          }
        }
        else {
          pStag = (stage_stag_info_class *)
                  (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->
                            getStagInfo)(0x803c9d58);
          if ((pStag->mStageTypeAndSchbit >> 0x10 & 7) == 6) {
            dVar9 = (double)d_map::mapOffsetY();
            bVar5 = d_map::dMap_GetFloorNo((double)(float)(dVar8 + dVar9),0x803c9d58);
            if (bVar5 < 0x80) {
              *(byte *)(local_54 + 3) = bVar5 + 0x80;
            }
            else {
              *(byte *)(local_54 + 3) = bVar5 + 0x81;
            }
          }
          else {
            *(undefined *)(local_54 + 0x19) = 0;
            *(undefined *)(local_54 + 3) = 0;
          }
        }
      }
    }
    if (param_1 != -1) {
      this->field_0x0 = 1;
    }
  }
  else {
    this = (dMap_RoomInfo_c *)0x0;
  }
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  __psq_l0(auStack24,uVar7);
  __psq_l1(auStack24,uVar7);
  return this;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Removing unreachable block (ram,0x80046ee0) */
/* WARNING: Removing unreachable block (ram,0x80046ee8) */
/* __thiscall dMap_RoomInfo_c::Changeimage(unsigned char,
                                           unsigned char,
                                           int,
                                           short,
                                           short,
                                           float) */

undefined4 __thiscall
dMap_RoomInfo_c::Changeimage
          (dMap_RoomInfo_c *this,uchar param_1,uchar param_2,int param_3,short param_4,short param_5
          ,float param_6)

{
  stage_map_info_class *psVar1;
  stage_map_info_class *psVar2;
  uint uVar3;
  char cVar7;
  undefined4 uVar4;
  ulong uVar5;
  int iVar6;
  byte bVar8;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  byte unaff_r26;
  undefined4 uVar9;
  double dVar10;
  undefined8 in_f30;
  double dVar11;
  undefined8 in_f31;
  stage_map_info_class *local_6c;
  undefined2 *local_68;
  ResTIMG *local_64;
  ResTIMG *local_60 [2];
  undefined4 local_58;
  uint uStack84;
  undefined4 local_50;
  uint uStack76;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar10 = (double)param_6;
  uVar9 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  local_60[0] = (ResTIMG *)0x0;
  local_64 = (ResTIMG *)0x0;
  local_68 = (undefined2 *)0x0;
  local_6c = (stage_map_info_class *)0x0;
  cVar7 = d_map::IsFloorNo(dVar10,param_1,CONCAT31(in_register_00000010,param_1),
                           CONCAT31(in_register_00000014,param_2));
  if (cVar7 == '\0') {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar5,"d_map.cpp",0x995,"0");
    m_Do_printf::OSPanic("d_map.cpp",0x995,&DAT_8034f1dd);
  }
  else {
    uVar3 = countLeadingZeros(param_3 - this->field_0x10);
    unaff_r26 = getRoomDspFloorNo(this,param_1,uVar3 >> 5 & 0xff);
  }
  if (unaff_r26 == this->field_0xc) {
    uVar4 = 0;
  }
  else {
    *(undefined4 *)&this->field_0xe8 = 0;
    this->field_0xc = unaff_r26;
    this->field_0x1 = 0;
    cVar7 = d_map::IsFloorNo();
    if (cVar7 != '\0') {
      getRoomImage(this,this->field_0x10,unaff_r26,0,local_60,&local_64,(map_dt_c **)&local_68,
                   &local_6c,&this->field_0x1);
    }
    if (local_6c != (stage_map_info_class *)0x0) {
      *(stage_map_info_class **)&this->field_0xe8 = local_6c;
    }
    if ((this->field_0x1 & 2) != 0) {
      dMap_2DMtMapSpcl_tex_c::init
                ((dMap_2DMtMapSpcl_tex_c *)&this->field_0x44,(EVP_PKEY_CTX *)local_60[0]);
      dMap_2DMtMapSpcl_tex_c::setScroll
                ((dMap_2DMtMapSpcl_tex_c *)&this->field_0x44,d_map::_4426,d_map::_4426,d_map::_4611,
                 d_map::_4611);
      *(undefined *)&this->field_0x44 = 1;
      dVar11 = d_map::_4818;
      if (local_6c != (stage_map_info_class *)0x0) {
        uStack84 = (int)param_4 ^ 0x80000000;
        local_58 = 0x43300000;
        this->field_0x18 =
             (float)((double)CONCAT44(0x43300000,uStack84) - d_map::_4818) /
             (*(float *)&local_6c->field_0x8 - *(float *)local_6c);
        uStack76 = (int)param_5 ^ 0x80000000;
        local_50 = 0x43300000;
        this->field_0x1c =
             (float)((double)CONCAT44(0x43300000,uStack76) - dVar11) /
             (*(float *)&local_6c->field_0xc - *(float *)&local_6c->field_0x4);
      }
      dMap_2DMtMapSpcl_c::init
                ((dMap_2DMtMapSpcl_c *)&this->field_0x30,(EVP_PKEY_CTX *)&DAT_00000001);
    }
    if ((this->field_0x1 & 1) != 0) {
      dMap_2DAGBScrDsp_c::setImage
                ((dMap_2DAGBScrDsp_c *)&this->field_0x8c,local_64,(map_dt_c *)local_68);
      uStack76 = m_Do_lib::mDoLib_cnvind16(*local_68);
      uStack76 = uStack76 & 0xffff;
      local_50 = 0x43300000;
      *(float *)&this->field_0x28 = (float)((double)CONCAT44(0x43300000,uStack76) - d_map::_4820);
      uStack84 = m_Do_lib::mDoLib_cnvind16(local_68[1]);
      psVar1 = local_6c;
      uStack84 = uStack84 & 0xffff;
      local_58 = 0x43300000;
      *(float *)&this->field_0x2c = (float)((double)CONCAT44(0x43300000,uStack84) - d_map::_4820);
      if (local_6c == (stage_map_info_class *)0x0) {
        uVar5 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar5,"d_map.cpp",0x2cf,"i_mapInfoP != 0");
        m_Do_printf::OSPanic("d_map.cpp",0x2cf,&DAT_8034f1dd);
      }
      psVar2 = local_6c;
      dVar11 = (double)*(float *)&psVar1->field_0x18;
      if (local_6c == (stage_map_info_class *)0x0) {
        uVar5 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar5,"d_map.cpp",0x2db,"i_mapInfoP != 0");
        m_Do_printf::OSPanic("d_map.cpp",0x2db,&DAT_8034f1dd);
      }
      psVar1 = local_6c;
      this->field_0x20 =
           *(float *)&this->field_0x28 / (float)((double)*(float *)&psVar2->field_0x20 - dVar11);
      if (local_6c == (stage_map_info_class *)0x0) {
        uVar5 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar5,"d_map.cpp",0x2d5,"i_mapInfoP != 0");
        m_Do_printf::OSPanic("d_map.cpp",0x2d5,&DAT_8034f1dd);
      }
      psVar2 = local_6c;
      dVar11 = (double)*(float *)&psVar1->field_0x1c;
      if (local_6c == (stage_map_info_class *)0x0) {
        uVar5 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar5,"d_map.cpp",0x2e1,"i_mapInfoP != 0");
        m_Do_printf::OSPanic("d_map.cpp",0x2e1,&DAT_8034f1dd);
      }
      this->field_0x24 =
           *(float *)&this->field_0x2c / (float)((double)*(float *)&psVar2->field_0x24 - dVar11);
      iVar6 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)
                        (0x803c9d58);
      if ((*(uint *)(iVar6 + 0xc) >> 0x10 & 7) == 1) {
        if (d_map::18_0 <= *(float *)&local_6c->field_0x30) {
          *(undefined *)(local_68 + 0x19) = 1;
        }
        else {
          *(undefined *)(local_68 + 0x19) = 0;
        }
        if (param_1 < 0x80) {
          *(uchar *)(local_68 + 3) = param_1 + 0x80;
        }
        else {
          *(uchar *)(local_68 + 3) = param_1 + 0x81;
        }
      }
      else {
        iVar6 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)
                          (0x803c9d58);
        if ((*(uint *)(iVar6 + 0xc) >> 0x10 & 7) == 6) {
          dVar11 = (double)d_map::mapOffsetY();
          bVar8 = d_map::dMap_GetFloorNo((double)(float)(dVar10 + dVar11),0x803c9d58);
          if (bVar8 < 0x80) {
            *(byte *)(local_68 + 3) = bVar8 + 0x80;
          }
          else {
            *(byte *)(local_68 + 3) = bVar8 + 0x81;
          }
        }
        else {
          *(undefined *)(local_68 + 0x19) = 0;
          *(undefined *)(local_68 + 3) = 0;
        }
      }
    }
    uVar4 = 1;
  }
  __psq_l0(auStack8,uVar9);
  __psq_l1(auStack8,uVar9);
  __psq_l0(auStack24,uVar9);
  __psq_l1(auStack24,uVar9);
  return uVar4;
}


/* __thiscall dMap_RoomInfo_c::deleteRoom(void) */

undefined4 __thiscall dMap_RoomInfo_c::deleteRoom(dMap_RoomInfo_c *this)

{
  float fVar1;
  int iVar2;
  int iVar3;
  
  this->field_0x10 = -1;
  this->field_0x0 = 0;
  *(undefined4 *)&this->field_0xe8 = 0;
  this->field_0x1 = 0;
  iVar2 = 0;
  iVar3 = 10;
  do {
    this->field_0x2[iVar2] = 0xff;
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  this->field_0xc = 0xff;
  this->field_0x10 = -1;
  fVar1 = d_map::_4426;
  this->field_0x18 = d_map::_4426;
  this->field_0x1c = fVar1;
  this->field_0x20 = fVar1;
  this->field_0x24 = fVar1;
  *(float *)&this->field_0x28 = fVar1;
  *(float *)&this->field_0x2c = fVar1;
  dMap_2DAGBScrDsp_c::init((dMap_2DAGBScrDsp_c *)&this->field_0x8c,(EVP_PKEY_CTX *)0x0);
  *(undefined *)&this->field_0x44 = 0;
  dMap_2DMtMapSpcl_c::init((dMap_2DMtMapSpcl_c *)&this->field_0x30,(EVP_PKEY_CTX *)&DAT_00000001);
  return 1;
}


/* WARNING: Removing unreachable block (ram,0x800470bc) */
/* __thiscall dMap_RoomInfo_c::enlagementSizeTextureCordCalc(float *,
                                                             float *,
                                                             float *,
                                                             float *,
                                                             float,
                                                             float,
                                                             float,
                                                             float,
                                                             float,
                                                             float) */

undefined4 __thiscall
dMap_RoomInfo_c::enlagementSizeTextureCordCalc
          (dMap_RoomInfo_c *this,float *param_1,float *param_2,float *param_3,float *param_4,
          float param_5,float param_6,float param_7,float param_8,float param_9,float param_10)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  undefined4 uVar10;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  fVar3 = param_5 - d_map::_4929 * param_6;
  fVar4 = param_5 + d_map::_4929 * param_6;
  fVar1 = *param_3;
  fVar7 = (d_map::_4611 / param_9) * fVar1;
  fVar2 = *param_4;
  fVar8 = (d_map::_4611 / param_9) * fVar2;
  fVar5 = param_8 + fVar7;
  fVar6 = param_8 + fVar8;
  uVar10 = 0;
  if (((d_map::_4426 != param_9) || (fVar5 <= fVar4)) || (fVar3 <= fVar6)) {
    fVar9 = d_map::_4929 + ((param_8 - param_5) * param_7) / param_10;
    *param_1 = fVar9 + fVar7 / param_6;
    *param_2 = fVar9 + fVar8 / param_6;
    fVar7 = d_map::_4426;
    if (fVar5 < fVar3) {
      *param_1 = d_map::_4426;
      fVar1 = (fVar3 - param_8) * param_9;
      *param_1 = fVar7;
    }
    fVar3 = d_map::_4611;
    if (fVar4 < fVar6) {
      *param_2 = d_map::_4611;
      fVar2 = (fVar4 - param_8) * param_9;
      *param_2 = fVar3;
    }
    *param_3 = fVar1;
    *param_4 = fVar2;
    uVar10 = 1;
  }
  __psq_l0(auStack8,0);
  __psq_l1(auStack8,0);
  return uVar10;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x80047590) */
/* WARNING: Removing unreachable block (ram,0x80047580) */
/* WARNING: Removing unreachable block (ram,0x80047570) */
/* WARNING: Removing unreachable block (ram,0x80047560) */
/* WARNING: Removing unreachable block (ram,0x80047550) */
/* WARNING: Removing unreachable block (ram,0x80047558) */
/* WARNING: Removing unreachable block (ram,0x80047568) */
/* WARNING: Removing unreachable block (ram,0x80047578) */
/* WARNING: Removing unreachable block (ram,0x80047588) */
/* WARNING: Removing unreachable block (ram,0x80047598) */
/* __thiscall dMap_RoomInfo_c::roomDrawRoomEnlargementSize(int,
                                                           int,
                                                           int,
                                                           int,
                                                           float,
                                                           float,
                                                           float,
                                                           float,
                                                           unsigned char) */

void __thiscall
dMap_RoomInfo_c::roomDrawRoomEnlargementSize
          (dMap_RoomInfo_c *this,int param_1,int param_2,int param_3,int param_4,float param_5,
          float param_6,float param_7,float param_8,uchar param_9)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  ulong uVar7;
  char cVar8;
  undefined4 uVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  undefined8 in_f22;
  undefined8 in_f23;
  undefined8 in_f24;
  undefined8 in_f25;
  undefined8 in_f26;
  undefined8 in_f27;
  double dVar14;
  double dVar15;
  double dVar16;
  undefined8 in_f28;
  undefined8 in_f29;
  double dVar17;
  undefined8 in_f30;
  double dVar18;
  undefined8 in_f31;
  double dVar19;
  float local_108;
  float local_104;
  float local_100;
  float local_fc;
  float local_f8;
  float local_f4;
  float local_f0;
  float local_ec;
  undefined4 local_e8;
  uint uStack228;
  undefined4 local_e0;
  uint uStack220;
  longlong local_d8;
  longlong local_d0;
  longlong local_c8;
  longlong local_c0;
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
  
  dVar12 = (double)param_7;
  dVar13 = (double)param_8;
  dVar11 = (double)param_6;
  dVar10 = (double)param_5;
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
  if ((this->field_0x1 & 2) != 0) {
    if (*(int *)&this->field_0xe8 == 0) {
      uVar7 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar7,"d_map.h",0x467,"mStageMapInfoP != 0");
      m_Do_printf::OSPanic("d_map.h",0x467,&DAT_8034f1dd);
    }
    dVar14 = (double)**(float **)&this->field_0xe8;
    if (*(float **)&this->field_0xe8 == (float *)0x0) {
      uVar7 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar7,"d_map.h",0x467,"mStageMapInfoP != 0");
      m_Do_printf::OSPanic("d_map.h",0x467,&DAT_8034f1dd);
    }
    dVar14 = (double)(float)((double)*(float *)(*(int *)&this->field_0xe8 + 8) - dVar14);
    if (*(int *)&this->field_0xe8 == 0) {
      uVar7 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar7,"d_map.h",0x467,"mStageMapInfoP != 0");
      m_Do_printf::OSPanic("d_map.h",0x467,&DAT_8034f1dd);
    }
    dVar15 = (double)*(float *)(*(int *)&this->field_0xe8 + 4);
    if (*(int *)&this->field_0xe8 == 0) {
      uVar7 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar7,"d_map.h",0x467,"mStageMapInfoP != 0");
      m_Do_printf::OSPanic("d_map.h",0x467,&DAT_8034f1dd);
    }
    dVar16 = (double)(float)((double)*(float *)(*(int *)&this->field_0xe8 + 0xc) - dVar15);
    dVar15 = (double)this->field_0x18;
    dVar19 = (double)this->field_0x1c;
    *(undefined *)&this->field_0x44 = 0;
    uStack228 = param_3 ^ 0x80000000;
    local_e8 = 0x43300000;
    local_100 = d_map::_4929 * (float)((double)CONCAT44(0x43300000,uStack228) - d_map::_4818);
    dVar18 = (double)local_100;
    local_fc = (float)-dVar18;
    uStack220 = param_4 ^ 0x80000000;
    local_e0 = 0x43300000;
    local_108 = d_map::_4929 * (float)((double)CONCAT44(0x43300000,uStack220) - d_map::_4818);
    dVar17 = (double)local_108;
    local_104 = (float)-dVar17;
    if (*(int *)&this->field_0xe8 == 0) {
      uVar7 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar7,"d_map.h",0x467,"mStageMapInfoP != 0");
      m_Do_printf::OSPanic("d_map.h",0x467,&DAT_8034f1dd);
    }
    uStack220 = param_3 ^ 0x80000000;
    local_e0 = 0x43300000;
    cVar8 = enlagementSizeTextureCordCalc
                      (this,&local_ec,&local_f0,&local_fc,&local_100,
                       *(float *)(*(int *)&this->field_0xe8 + 0x10),(float)dVar14,(float)dVar15,
                       (float)dVar10,(float)dVar12,
                       (float)((double)CONCAT44(0x43300000,uStack220) - d_map::_4818));
    if (cVar8 != '\0') {
      if (*(int *)&this->field_0xe8 == 0) {
        uVar7 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar7,"d_map.h",0x467,"mStageMapInfoP != 0");
        m_Do_printf::OSPanic("d_map.h",0x467,&DAT_8034f1dd);
      }
      uStack220 = param_4 ^ 0x80000000;
      local_e0 = 0x43300000;
      cVar8 = enlagementSizeTextureCordCalc
                        (this,&local_f4,&local_f8,&local_104,&local_108,
                         *(float *)(*(int *)&this->field_0xe8 + 0x14),(float)dVar16,(float)dVar19,
                         (float)dVar11,(float)dVar13,
                         (float)((double)CONCAT44(0x43300000,uStack220) - d_map::_4818));
      if ((((cVar8 != '\0') && (local_ec <= d_map::_4611)) && (d_map::_4426 <= local_f0)) &&
         ((local_f4 <= d_map::_4611 && (d_map::_4426 <= local_f8)))) {
        *(undefined *)&this->field_0x44 = 1;
        dMap_2DMtMapSpcl_tex_c::setScroll
                  ((dMap_2DMtMapSpcl_tex_c *)&this->field_0x44,local_ec,local_f4,local_f0 - local_ec
                   ,local_f8 - local_f4);
        *(undefined *)&this->field_0x74 = 0xff;
        *(undefined *)&this->field_0x75 = 0xff;
        *(undefined *)&this->field_0x76 = 0xff;
        *(uchar *)&this->field_0x77 = param_9;
        uStack220 = param_1 ^ 0x80000000;
        local_e0 = 0x43300000;
        fVar1 = (float)((double)(float)((double)CONCAT44(0x43300000,uStack220) - d_map::_4818) +
                       dVar18);
        uStack228 = param_2 ^ 0x80000000;
        local_e8 = 0x43300000;
        fVar2 = (float)((double)(float)((double)CONCAT44(0x43300000,uStack228) - d_map::_4818) +
                       dVar17);
        iVar3 = (int)(fVar1 + local_fc);
        local_d8 = (longlong)iVar3;
        iVar4 = (int)(fVar2 + local_104);
        local_d0 = (longlong)iVar4;
        iVar5 = (int)(fVar1 + local_100);
        local_c8 = (longlong)iVar5;
        iVar6 = (int)(fVar2 + local_108);
        local_c0 = (longlong)iVar6;
        dMap_2DMtMapSpcl_c::setPos
                  ((dMap_2DMtMapSpcl_c *)&this->field_0x30,(short)iVar3,(short)iVar4,(short)iVar5,
                   (short)iVar6);
        *(undefined *)&this->field_0x35 = 1;
        dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                          &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                          &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                          (dDlst_base_c *)&this->field_0x30);
      }
    }
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
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x8004780c) */
/* WARNING: Removing unreachable block (ram,0x800477fc) */
/* WARNING: Removing unreachable block (ram,0x800477ec) */
/* WARNING: Removing unreachable block (ram,0x800477f4) */
/* WARNING: Removing unreachable block (ram,0x80047804) */
/* WARNING: Removing unreachable block (ram,0x80047814) */
/* __thiscall dMap_RoomInfo_c::roomDrawRoomRealSize(int,
                                                    int,
                                                    int,
                                                    int,
                                                    float,
                                                    float,
                                                    float,
                                                    float,
                                                    float,
                                                    float,
                                                    unsigned char) */

void __thiscall
dMap_RoomInfo_c::roomDrawRoomRealSize
          (dMap_RoomInfo_c *this,int param_1,int param_2,int param_3,int param_4,float param_5,
          float param_6,float param_7,float param_8,float param_9,float param_10,uchar param_11)

{
  ulong uVar1;
  undefined4 uVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  undefined8 in_f26;
  undefined8 in_f27;
  double dVar6;
  undefined8 in_f28;
  double dVar7;
  undefined8 in_f29;
  double dVar8;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar7 = (double)param_9;
  dVar6 = (double)param_10;
  dVar4 = (double)param_7;
  dVar5 = (double)param_8;
  dVar8 = (double)param_6;
  dVar3 = (double)param_5;
  uVar2 = 0;
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
  if ((this->field_0x1 & 1) != 0) {
    if (*(int *)&this->field_0xe8 == 0) {
      uVar1 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar1,"d_map.h",0x467,"mStageMapInfoP != 0");
      m_Do_printf::OSPanic("d_map.h",0x467,&DAT_8034f1dd);
    }
    dVar7 = (double)(float)((double)*(float *)(*(int *)&this->field_0xe8 + 0x30) / dVar7);
    if (*(int *)&this->field_0xe8 == 0) {
      uVar1 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar1,"d_map.h",0x467,"mStageMapInfoP != 0");
      m_Do_printf::OSPanic("d_map.h",0x467,&DAT_8034f1dd);
    }
    dVar6 = (double)(float)((double)*(float *)(*(int *)&this->field_0xe8 + 0x30) / dVar6);
    if (*(int *)&this->field_0xe8 == 0) {
      uVar1 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar1,"d_map.h",0x467,"mStageMapInfoP != 0");
      m_Do_printf::OSPanic("d_map.h",0x467,&DAT_8034f1dd);
    }
    dVar8 = (double)(d_map::_4929 * *(float *)&this->field_0x2c +
                    (float)(dVar8 - dVar5) / *(float *)(*(int *)&this->field_0xe8 + 0x30));
    if (*(int *)&this->field_0xe8 == 0) {
      uVar1 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar1,"d_map.h",0x467,"mStageMapInfoP != 0");
      m_Do_printf::OSPanic("d_map.h",0x467,&DAT_8034f1dd);
    }
    *(float *)&this->field_0xd0 =
         d_map::_4929 * *(float *)&this->field_0x28 +
         (float)(dVar3 - dVar4) / *(float *)(*(int *)&this->field_0xe8 + 0x30);
    *(float *)&this->field_0xd4 = (float)dVar8;
    dMap_2DAGBScrDsp_c::setScale((dMap_2DAGBScrDsp_c *)&this->field_0x8c,(float)dVar7,(float)dVar6);
    dMap_2DAGBScrDsp_c::setPos
              ((dMap_2DAGBScrDsp_c *)&this->field_0x8c,(short)param_1,(short)param_2,
               (short)param_1 + (short)param_3,(short)param_2 + (short)param_4);
    *(uchar *)&this->field_0xe0 = param_11;
    dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                      &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                      &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                      (dDlst_base_c *)&this->field_0x8c);
  }
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  __psq_l0(auStack24,uVar2);
  __psq_l1(auStack24,uVar2);
  __psq_l0(auStack40,uVar2);
  __psq_l1(auStack40,uVar2);
  __psq_l0(auStack56,uVar2);
  __psq_l1(auStack56,uVar2);
  __psq_l0(auStack72,uVar2);
  __psq_l1(auStack72,uVar2);
  __psq_l0(auStack88,uVar2);
  __psq_l1(auStack88,uVar2);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dMap_RoomInfoCtrl_c::roomExistenceCheck(int,
                                                      dMap_RoomInfo_c * *) */

int __thiscall
dMap_RoomInfoCtrl_c::roomExistenceCheck
          (dMap_RoomInfoCtrl_c *this,int param_1,dMap_RoomInfo_c **param_2)

{
  dMap_RoomInfo_c *pdVar1;
  ulong uVar2;
  int iVar3;
  
  if (param_2 == (dMap_RoomInfo_c **)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_map.cpp",0xb83,"roomInfoPP != 0");
    m_Do_printf::OSPanic("d_map.cpp",0xb83,&DAT_8034f1dd);
  }
  iVar3 = 0;
  *param_2 = (dMap_RoomInfo_c *)0x0;
  pdVar1 = this->mpRoomInfo[0];
  if (pdVar1 == (dMap_RoomInfo_c *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_map.cpp",0xb8b,"roomInfoP != 0");
    m_Do_printf::OSPanic("d_map.cpp",0xb8b,&DAT_8034f1dd);
  }
  for (; (iVar3 == 0 && (pdVar1 != (dMap_RoomInfo_c *)0x0));
      pdVar1 = *(dMap_RoomInfo_c **)&pdVar1->field_0xe4) {
    if (pdVar1->field_0x0 == 0) {
      if (*param_2 == (dMap_RoomInfo_c *)0x0) {
        *param_2 = pdVar1;
      }
    }
    else {
      if (param_1 == pdVar1->field_0x10) {
        *param_2 = pdVar1;
        iVar3 = 1;
      }
    }
  }
  return iVar3;
}


/* __thiscall dMap_RoomInfoCtrl_c::getNextRoomP(dMap_RoomInfo_c *) */

dMap_RoomInfo_c * __thiscall
dMap_RoomInfoCtrl_c::getNextRoomP(dMap_RoomInfoCtrl_c *this,dMap_RoomInfo_c *param_1)

{
  if (param_1 != (dMap_RoomInfo_c *)0x0) {
    return *(dMap_RoomInfo_c **)&param_1->field_0xe4;
  }
  if (this->mpRoomInfo[0] != (dMap_RoomInfo_c *)0x0) {
    return this->mpRoomInfo[0];
  }
  return (dMap_RoomInfo_c *)0x0;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall dMap_RoomInfoCtrl_c::ctrlEntryRoom(int,
                                                 unsigned char,
                                                 int,
                                                 unsigned char,
                                                 short,
                                                 short,
                                                 float) */

dMap_RoomInfo_c * __thiscall
dMap_RoomInfoCtrl_c::ctrlEntryRoom
          (dMap_RoomInfoCtrl_c *this,int param_1,uchar param_2,int param_3,uchar param_4,
          short param_5,short param_6,float param_7)

{
  char cVar3;
  ulong uVar1;
  int iVar2;
  dMap_RoomInfo_c *pdVar4;
  double dVar5;
  dMap_RoomInfo_c *local_38 [4];
  
  dVar5 = (double)param_7;
  cVar3 = roomExistenceCheck(this,param_1,local_38);
  if (cVar3 == '\0') {
    local_38[0] = this->mpRoomInfo[0];
    if (local_38[0] == (dMap_RoomInfo_c *)0x0) {
      uVar1 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar1,"d_map.cpp",0xbfd,"roomInfoP != 0");
      m_Do_printf::OSPanic("d_map.cpp",0xbfd,&DAT_8034f1dd);
    }
    pdVar4 = (dMap_RoomInfo_c *)0x0;
    if (local_38[0] == (dMap_RoomInfo_c *)0x0) {
      local_38[0] = (dMap_RoomInfo_c *)0x0;
    }
    else {
      for (; (local_38[0] != (dMap_RoomInfo_c *)0x0 && (local_38[0]->field_0x0 != 0));
          local_38[0] = *(dMap_RoomInfo_c **)&local_38[0]->field_0xe4) {
        pdVar4 = local_38[0];
      }
      if ((local_38[0] == (dMap_RoomInfo_c *)0x0) ||
         (iVar2 = dMap_RoomInfo_c::roomEntryRoom
                            (local_38[0],param_1,param_2,param_3,param_4,pdVar4,param_5,param_6,
                             (float)dVar5), iVar2 == 0)) {
        local_38[0] = (dMap_RoomInfo_c *)0x0;
      }
    }
  }
  else {
    local_38[0] = (dMap_RoomInfo_c *)0x0;
  }
  return local_38[0];
}


/* __thiscall dMap_RoomInfoCtrl_c::deleteRoom(int) */

undefined4 __thiscall dMap_RoomInfoCtrl_c::deleteRoom(dMap_RoomInfoCtrl_c *this,int param_1)

{
  char cVar1;
  dMap_RoomInfo_c *local_8 [2];
  
  cVar1 = roomExistenceCheck(this,param_1,local_8);
  if (cVar1 != '\0') {
    dMap_RoomInfo_c::deleteRoom(local_8[0]);
  }
  return 0;
}


/* WARNING: Inlined function: FUN_80328ea4 */
/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328ef0 */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall dMap_RoomInfoCtrl_c::ctrlDrawRoomEnlargementSize(int,
                                                               int,
                                                               int,
                                                               int,
                                                               int,
                                                               float,
                                                               float,
                                                               float,
                                                               float,
                                                               unsigned char) */

void __thiscall
dMap_RoomInfoCtrl_c::ctrlDrawRoomEnlargementSize
          (dMap_RoomInfoCtrl_c *this,int param_1,int param_2,int param_3,int param_4,int param_5,
          float param_6,float param_7,float param_8,float param_9,uchar param_10)

{
  dMap_RoomInfo_c *this_00;
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  
  dVar3 = (double)param_8;
  dVar4 = (double)param_9;
  dVar2 = (double)param_7;
  dVar1 = (double)param_6;
  this_00 = (dMap_RoomInfo_c *)0x0;
  while (this_00 = (dMap_RoomInfo_c *)getNextRoomP(this,this_00), this_00 != (dMap_RoomInfo_c *)0x0)
  {
    if (this_00->field_0x0 != 0) {
      if (param_1 == this_00->field_0x10) {
        dMap_RoomInfo_c::roomDrawRoomEnlargementSize
                  (this_00,param_2,param_3,param_4,param_5,(float)dVar1,(float)dVar2,(float)dVar3,
                   (float)dVar4,param_10);
      }
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328e9c */
/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328ee8 */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall dMap_RoomInfoCtrl_c::ctrlDrawRoomRealSize(int,
                                                        int,
                                                        int,
                                                        int,
                                                        int,
                                                        float,
                                                        float,
                                                        float,
                                                        float,
                                                        float,
                                                        float,
                                                        unsigned char) */

void __thiscall
dMap_RoomInfoCtrl_c::ctrlDrawRoomRealSize
          (dMap_RoomInfoCtrl_c *this,int param_1,int param_2,int param_3,int param_4,int param_5,
          float param_6,float param_7,float param_8,float param_9,float param_10,float param_11,
          uchar param_12)

{
  dMap_RoomInfo_c *this_00;
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  
  dVar5 = (double)param_10;
  dVar6 = (double)param_11;
  dVar3 = (double)param_8;
  dVar4 = (double)param_9;
  dVar2 = (double)param_7;
  dVar1 = (double)param_6;
  this_00 = (dMap_RoomInfo_c *)0x0;
  while (this_00 = (dMap_RoomInfo_c *)getNextRoomP(this,this_00), this_00 != (dMap_RoomInfo_c *)0x0)
  {
    if (this_00->field_0x0 != 0) {
      if (param_1 == this_00->field_0x10) {
        dMap_RoomInfo_c::roomDrawRoomRealSize
                  (this_00,param_2,param_3,param_4,param_5,(float)dVar1,(float)dVar2,(float)dVar3,
                   (float)dVar4,(float)dVar5,(float)dVar6,param_12);
      }
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dMap_RoomInfoCtrl_c::init(void) */

int __thiscall dMap_RoomInfoCtrl_c::init(dMap_RoomInfoCtrl_c *this)

{
  dMap_RoomInfo_c *pdVar1;
  dMap_RoomInfo_c *pdVar2;
  dMap_RoomInfo_c *this_00;
  int iVar3;
  int iVar4;
  
  this_00 = this->mpRoomInfo[0];
  iVar4 = 0;
  pdVar1 = (dMap_RoomInfo_c *)this;
  pdVar2 = (dMap_RoomInfo_c *)0x0;
  for (iVar3 = 0; iVar3 < this->mCount; iVar3 = iVar3 + 1) {
    pdVar1 = this_00;
    dMap_RoomInfo_c::init(this_00,pdVar2,iVar4);
    iVar4 = iVar4 + 1;
    this_00 = this_00 + 1;
    pdVar2 = pdVar1;
  }
  return (int)pdVar1;
}


namespace dMap_c {

/* WARNING: Inlined function: FUN_80328f1c */
/* WARNING: Inlined function: FUN_80328f68 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall create(void) */

void create(void)

{
  dMap_c *pdVar1;
  EVP_PKEY_CTX *pEVar2;
  ulong uVar3;
  dMap_2DMtMapSpcl_tex_c *this;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  mCompAlpha = 0;
  mAlpha = 0;
  mDrawPointCntPlayer = 0;
  mDrawPointCntEnemy = 0;
  mDrawPointCntAgbCursor = 0;
  mDoorNum = 0;
  mTboxNum = 0;
  mAGBMapSendStatus = 0;
  mSetCursorFlg = 0;
  mIconDispMode = 0;
  mIconFreeAlpha = 0;
  mIconSelfAlpha = 0;
  mAGBMapSendStopFlg = 0;
  mPlayerStayAgbMapTypeNow = 0;
  mPlayerStayAgbMapTypeOld = 0xff;
  mMapAGBCursorFlashFrmCnt = 0;
  mPlGridX = 0x80;
  mPlGridY = 0x80;
  mPlGridX_Old = 0x80;
  mPlGridY_Old = 0x80;
  mNowFloorNo = 0;
  _mIconFreePosX = 0;
  _mIconFreePosY = 0;
  _mAGBPointValueC = 0;
  _mAGBPointValueE = 0;
  _mAGBPointValueAll = 0;
  _mAGBPointValueRoomAll = 0;
  pdVar1 = (dMap_c *)MSL_C.PPCEABI.bare.H::strcpy(&mAgbSendNowStageName,"");
  _mAgbSendNowRoomNo = 0xffffffff;
  _mAgbSendNowDspFloorNo = 0xffff;
  mFmapChkPntValue = 0;
  mFmapChkPntData_p = (FmapChkPnt *)0x0;
  _mEnlargementSizeCenterX = d_map::_4426;
  _mEnlargementSizeCenterZ = d_map::_4426;
  _mEnlargementSizeScaleX = d_map::_4611;
  _mEnlargementSizeScaleZ = d_map::_4611;
  _mDispPosLeftUpX = 0;
  _mDispPosLeftUpY = 0;
  _mDispSizeX = 0;
  _mDispSizeY = 0;
  _mScissorOrigY = 0;
  _mScissorOrigX = 0;
  _mScissorWidth = 0;
  _mScissorHeight = 0;
  mIconFreeScale = d_map::_4426;
  _mIconSelfScale = d_map::_4426;
  _mNowCenterX = d_map::_4426;
  _mNowCenterZ = d_map::_4426;
  _mNowScaleX = d_map::_4426;
  _mNowScaleZ = d_map::_4426;
  _mNowRoomInfoP = 0;
  mMapDispMode = 0;
  mNowFloorNo = 0xff;
  setFmapChkDtPrm(pdVar1);
  mRoomInfoCtrl.mCount = 0x14;
  mRoomInfoCtrl.mpRoomInfo = (dMap_RoomInfo_c *)&mRoomInfo;
  dMap_RoomInfoCtrl_c::init(&mRoomInfoCtrl);
  _mNowRoomInfoP = 0;
  pdVar1 = (dMap_c *)dMap_2DTri_c::init((dMap_2DTri_c *)&mCursor,(EVP_PKEY_CTX *)0x0);
  mAlpha = 0;
  mapAGBSendStatInit(pdVar1);
  iVar8 = 0;
  mAGBMapSendStatus = 0;
  _mDispPosLeftUpX = 0x19;
  _mDispPosLeftUpY = 0x152;
  _mDispSizeX = 0x78;
  _mDispSizeY = 0x78;
  _mIconFreePosX = 0x55;
  _mIconFreePosY = 0x144;
  iVar7 = 0;
  iVar6 = 0;
  iVar5 = 0;
  iVar4 = 0;
  do {
    pEVar2 = (EVP_PKEY_CTX *)
             dRes_control_c::getRes
                       ("Always",*(long *)((int)&d_map::frameArcIdx_5155 + iVar8),
                        d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
    if (pEVar2 == (EVP_PKEY_CTX *)0x0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_map.cpp",0xd7a,"timg != 0");
      m_Do_printf::OSPanic("d_map.cpp",0xd7a,&DAT_8034f1dd);
    }
    this = (dMap_2DMtMapSpcl_tex_c *)(&mFrameTexture + iVar4);
    dMap_2DMtMapSpcl_tex_c::init(this,pEVar2);
    *this = (dMap_2DMtMapSpcl_tex_c)0x1;
    dMap_2DMtMapSpcl_tex_c::setScroll
              (this,*(float *)((int)&d_map::cord_5156 + iVar5),
               *(float *)((int)&DAT_8034f04c + iVar5),*(float *)((int)&DAT_8034f050 + iVar5),
               *(float *)((int)&DAT_8034f054 + iVar5));
    dMap_2DMtMapSpcl_c::init
              ((dMap_2DMtMapSpcl_c *)(&mFrameTex + iVar6),(EVP_PKEY_CTX *)&DAT_00000001);
    iVar7 = iVar7 + 1;
    iVar6 = iVar6 + 0x14;
    iVar5 = iVar5 + 0x10;
    iVar4 = iVar4 + 0x48;
    iVar8 = iVar8 + 4;
  } while (iVar7 < 8);
  pEVar2 = (EVP_PKEY_CTX *)
           dRes_control_c::getRes
                     ("Always",0x73,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
  if (pEVar2 == (EVP_PKEY_CTX *)0x0) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"d_map.cpp",0xd94,"timg != 0");
    m_Do_printf::OSPanic("d_map.cpp",0xd94,&DAT_8034f1dd);
  }
  dMap_2DMtMapSpcl_tex_c::init((dMap_2DMtMapSpcl_tex_c *)&mIconFreeTexture,pEVar2);
  mIconFreeTexture = 1;
  dMap_2DMtMapSpcl_tex_c::setScroll
            ((dMap_2DMtMapSpcl_tex_c *)&mIconFreeTexture,d_map::_4426,d_map::_4426,d_map::_4611,
             d_map::_4611);
  dMap_2DMtMapSpcl_c::init((dMap_2DMtMapSpcl_c *)&mIconFreeTex,(EVP_PKEY_CTX *)&DAT_00000001);
  pEVar2 = (EVP_PKEY_CTX *)
           dRes_control_c::getRes
                     ("Always",0x74,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
  if (pEVar2 == (EVP_PKEY_CTX *)0x0) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"d_map.cpp",0xda1,"timg != 0");
    m_Do_printf::OSPanic("d_map.cpp",0xda1,&DAT_8034f1dd);
  }
  dMap_2DMtMapSpcl_tex_c::init((dMap_2DMtMapSpcl_tex_c *)&mIconSelfTexture,pEVar2);
  mIconSelfTexture = 1;
  dMap_2DMtMapSpcl_tex_c::setScroll
            ((dMap_2DMtMapSpcl_tex_c *)&mIconSelfTexture,d_map::_4426,d_map::_4426,d_map::_4611,
             d_map::_4611);
  dMap_2DMtMapSpcl_c::init((dMap_2DMtMapSpcl_c *)&mIconSelfTex,(EVP_PKEY_CTX *)&DAT_00000001);
  pEVar2 = (EVP_PKEY_CTX *)
           dRes_control_c::getRes
                     ("Always",0x75,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
  if (pEVar2 == (EVP_PKEY_CTX *)0x0) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"d_map.cpp",0xdae,"timg != 0");
    m_Do_printf::OSPanic("d_map.cpp",0xdae,&DAT_8034f1dd);
  }
  dMap_2DT2_c::init((dMap_2DT2_c *)&mShip,pEVar2);
  pEVar2 = (EVP_PKEY_CTX *)
           dRes_control_c::getRes
                     ("Always",0x80,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
  if (pEVar2 == (EVP_PKEY_CTX *)0x0) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"d_map.cpp",0xdb7,"timg != 0");
    m_Do_printf::OSPanic("d_map.cpp",0xdb7,&DAT_8034f1dd);
  }
  iVar4 = 0;
  iVar5 = 0;
  do {
    dMap_2DT2_c::init((dMap_2DT2_c *)(&mTbox + iVar5),pEVar2);
    iVar4 = iVar4 + 1;
    iVar5 = iVar5 + 0x5c;
  } while (iVar4 < 8);
  pEVar2 = (EVP_PKEY_CTX *)
           dRes_control_c::getRes
                     ("Always",0x72,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
  iVar4 = 0;
  iVar5 = 0;
  do {
    pdVar1 = (dMap_c *)dMap_2DT2_c::init((dMap_2DT2_c *)(&mDoor + iVar5),pEVar2);
    iVar4 = iVar4 + 1;
    iVar5 = iVar5 + 0x5c;
  } while (iVar4 < 0x10);
  initPoint(pdVar1);
  return;
}

}

/* __thiscall dMap_c::isEnableEnlargementScroll(void) */

uint __thiscall dMap_c::isEnableEnlargementScroll(dMap_c *this)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)();
  uVar1 = countLeadingZeros(7 - (*(uint *)(iVar2 + 0xc) >> 0x10 & 7));
  return uVar1 >> 5 & 0xff;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dMap_c::isEnableDispMap(void) */

undefined4 __thiscall dMap_c::isEnableDispMap(dMap_c *this)

{
  if (_mNowRoomInfoP == 0) {
    return 0;
  }
  if (*(char *)(_mNowRoomInfoP + 1) != '\x03') {
    return 0;
  }
  return 1;
}


/* __thiscall dMap_c::getKindMapType(void) */

uint __thiscall dMap_c::getKindMapType(dMap_c *this)

{
  stage_stag_info_class *pStag;
  uint roomType;
  
  pStag = (stage_stag_info_class *)
          (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)();
  roomType = pStag->mStageTypeAndSchbit >> 0x10 & 7;
  if (((roomType == 1) || (roomType == 5)) || (roomType == 6)) {
    roomType = 2;
  }
  else {
    roomType = countLeadingZeros(7 - roomType);
    roomType = roomType >> 5;
  }
  return roomType;
}


/* __thiscall dMap_c::remove(void) */

int __thiscall dMap_c::remove(dMap_c *this,char *__filename)

{
  int iVar1;
  
  iVar1 = mDoGaC_agbCom_c::mDoGaC_SendEntry
                    ((mDoGaC_agbCom_c *)&m_Do_ext::m_Do_gba_com::g_mDoGaC_gbaCom,'\x01',1);
  return iVar1;
}


namespace dMap_c {

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall setImage(int,
                               int,
                               float) */

void setImage(int param_1,int param_2,float param_3)

{
  uchar uVar1;
  char cVar3;
  ulong uVar2;
  uchar uVar4;
  int extraout_r4;
  int iVar5;
  double dVar6;
  undefined8 uVar7;
  
  dVar6 = (double)param_3;
  if (-1 < param_2) {
    cVar3 = d_map::IsFloorNo(mNowFloorNo);
    if (cVar3 == '\0') {
      mNowFloorNo = d_map::dMap_GetFloorNo_WithRoom(dVar6,param_2);
      cVar3 = d_map::IsFloorNo(mNowFloorNo);
      if (cVar3 == '\0') {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar2,"d_map.cpp",0xe6e,"0");
        m_Do_printf::OSPanic("d_map.cpp",0xe6e,&DAT_8034f1dd);
      }
    }
    uVar1 = mNowFloorNo;
    uVar4 = d_map::dMap_GetFloorNo_WithRoom(dVar6,param_2);
    uVar7 = dMap_RoomInfoCtrl_c::ctrlEntryRoom
                      (&mRoomInfoCtrl,param_1,uVar4,param_2,uVar1,0x78,0x78,(float)dVar6);
    iVar5 = (int)uVar7;
    if ((int)((ulonglong)uVar7 >> 0x20) == 0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"d_map.cpp",0xe82,"0");
      m_Do_printf::OSPanic("d_map.cpp",0xe82,&DAT_8034f1dd);
      iVar5 = extraout_r4;
    }
    if (((_mNowRoomInfoP == 0) && (param_1 == param_2)) && (param_2 != -1)) {
      setNowRoom((dMap_c *)param_2,iVar5);
    }
  }
  return;
}

}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dMap_c::deleteImage(int) */

void __thiscall dMap_c::deleteImage(dMap_c *this,int param_1)

{
  if ((-1 < (int)this) &&
     (dMap_RoomInfoCtrl_c::deleteRoom(&mRoomInfoCtrl,(int)this),
     this == (dMap_c *)(int)(char)dStage_roomControl_c::mStayNo)) {
    _mNowRoomInfoP = 0;
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dMap_c::setNowRoom(int) */

int __thiscall dMap_c::setNowRoom(dMap_c *this,int param_1)

{
  dMap_RoomInfo_c *pdVar1;
  ulong uVar2;
  int iVar3;
  dMap_RoomInfo_c *pdVar4;
  int iVar5;
  
  iVar5 = 0;
  _mNowRoomInfoP = (dMap_RoomInfo_c *)0x0;
  pdVar4 = (dMap_RoomInfo_c *)0x0;
  do {
    pdVar4 = (dMap_RoomInfo_c *)dMap_RoomInfoCtrl_c::getNextRoomP(&mRoomInfoCtrl,pdVar4);
    if (pdVar4 == (dMap_RoomInfo_c *)0x0) goto LAB_80048548;
  } while (this != (dMap_c *)pdVar4->field_0x10);
  iVar5 = 1;
  _mNowRoomInfoP = pdVar4;
LAB_80048548:
  pdVar1 = _mNowRoomInfoP;
  if (iVar5 != 0) {
    if ((_mNowRoomInfoP->field_0x1 & 2) != 0) {
      if (*(int *)&_mNowRoomInfoP->field_0xe8 == 0) {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar2,"d_map.h",0x467,"mStageMapInfoP != 0");
        m_Do_printf::OSPanic("d_map.h",0x467,&DAT_8034f1dd);
      }
      pdVar4 = _mNowRoomInfoP;
      _mEnlargementSizeCenterX = *(undefined4 *)(*(int *)&pdVar1->field_0xe8 + 0x10);
      if (*(int *)&_mNowRoomInfoP->field_0xe8 == 0) {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar2,"d_map.h",0x467,"mStageMapInfoP != 0");
        m_Do_printf::OSPanic("d_map.h",0x467,&DAT_8034f1dd);
      }
      _mEnlargementSizeCenterZ = *(undefined4 *)(*(int *)&pdVar4->field_0xe8 + 0x14);
      _mEnlargementSizeScaleX = _mNowRoomInfoP->field_0x18;
      _mEnlargementSizeScaleZ = _mNowRoomInfoP->field_0x1c;
      pdVar4 = _mNowRoomInfoP;
    }
    iVar3 = getKindMapType((dMap_c *)pdVar4);
    if (((iVar3 != 1) && (mAGBMapSendStopFlg == '\0')) && (mAGBMapSendStatus != '\0')) {
      mAGBMapSendStatus = '\0';
    }
  }
  return iVar5;
}


/* __thiscall dMap_2DSQ_c::draw(void) */

void __thiscall dMap_2DSQ_c::draw(dMap_2DSQ_c *this)

{
  _GXColor local_208;
  undefined auStack516 [436];
  undefined4 local_50;
  uint uStack76;
  undefined4 local_48;
  uint uStack68;
  undefined4 local_40;
  uint uStack60;
  undefined4 local_38;
  uint uStack52;
  undefined4 local_30;
  uint uStack44;
  undefined4 local_28;
  uint uStack36;
  undefined4 local_20;
  uint uStack28;
  undefined4 local_18;
  uint uStack20;
  
  gx::GXGetVtxAttrFmtv(0,auStack516);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_F32,0);
  gx::GXClearVtxDesc();
  gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
  gx::GXSetNumChans(1);
  gx::GXSetNumTexGens(0);
  gx::GXSetChanCtrl(GX_COLOR0,false,GX_SRC_REG,GX_SRC_REG,0,GX_DF_NONE,GX_AF_NONE);
  gx::GXSetNumTevStages(1);
  gx::GXSetZMode(false,GX_LEQUAL,false);
  if (*(int *)(this + 0x18) == 0) {
    gx::GXSetAlphaCompare(GX_ALWAYS,0,GX_AOP_OR,GX_ALWAYS,0);
    gx::GXSetZMode(false,GX_LEQUAL,false);
    gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR_NULL);
    gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR0A0);
    gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_ZERO,GX_CC_ZERO,GX_CC_ZERO,GX_CC_ZERO);
    gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_KONST);
    gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    gx::GXSetBlendMode(GX_BM_BLEND,GX_BL_ONE,GX_BL_ZERO,GX_LO_SET);
    gx::GXSetColorUpdate(false);
    gx::GXSetAlphaUpdate(1);
    gx::GXSetDstAlpha(1,this[0x14]);
  }
  else {
    if (*(int *)(this + 0x18) == 1) {
      gx::GXSetAlphaCompare(GX_ALWAYS,0,GX_AOP_OR,GX_ALWAYS,0);
      gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR0A0);
      local_208 = *(_GXColor *)(this + 0x1c);
      gx::GXSetTevColor(GX_TEVREG0,&local_208);
      gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_ZERO,GX_CC_ZERO,GX_CC_ZERO,GX_CC_C0);
      gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
      gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_KONST);
      gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
      gx::GXSetBlendMode(GX_BM_BLEND,GX_BL_DSTALPHA,GX_BL_INVDSTALPHA,GX_LO_SET);
      gx::GXSetColorUpdate(true);
      gx::GXSetAlphaUpdate(0);
      gx::GXSetDstAlpha(0,0);
    }
  }
  gx::GXBegin(0x80,0,4);
  uStack76 = *(uint *)(this + 0xc) ^ 0x80000000;
  local_50 = 0x43300000;
  uStack68 = *(uint *)(this + 4) ^ 0x80000000;
  local_48 = 0x43300000;
  write_volatile_4(0xcc008000,(float)((double)CONCAT44(0x43300000,uStack68) - d_map::_4818));
  write_volatile_4(0xcc008000,(float)((double)CONCAT44(0x43300000,uStack76) - d_map::_4818));
  write_volatile_4(0xcc008000,d_map::_4426);
  uStack60 = *(uint *)(this + 0xc) ^ 0x80000000;
  local_40 = 0x43300000;
  uStack52 = *(uint *)(this + 8) ^ 0x80000000;
  local_38 = 0x43300000;
  write_volatile_4(0xcc008000,(float)((double)CONCAT44(0x43300000,uStack52) - d_map::_4818));
  write_volatile_4(0xcc008000,(float)((double)CONCAT44(0x43300000,uStack60) - d_map::_4818));
  write_volatile_4(0xcc008000,d_map::_4426);
  uStack44 = *(uint *)(this + 0x10) ^ 0x80000000;
  local_30 = 0x43300000;
  uStack36 = *(uint *)(this + 8) ^ 0x80000000;
  local_28 = 0x43300000;
  write_volatile_4(0xcc008000,(float)((double)CONCAT44(0x43300000,uStack36) - d_map::_4818));
  write_volatile_4(0xcc008000,(float)((double)CONCAT44(0x43300000,uStack44) - d_map::_4818));
  write_volatile_4(0xcc008000,d_map::_4426);
  uStack28 = *(uint *)(this + 0x10) ^ 0x80000000;
  local_20 = 0x43300000;
  uStack20 = *(uint *)(this + 4) ^ 0x80000000;
  local_18 = 0x43300000;
  write_volatile_4(0xcc008000,(float)((double)CONCAT44(0x43300000,uStack20) - d_map::_4818));
  write_volatile_4(0xcc008000,(float)((double)CONCAT44(0x43300000,uStack28) - d_map::_4818));
  write_volatile_4(0xcc008000,d_map::_4426);
  gx::GXSetColorUpdate(true);
  gx::GXSetAlphaUpdate(0);
  gx::GXSetDstAlpha(0,0xff);
  gx::GXSetVtxAttrFmtv(0,auStack516);
  return;
}


/* __thiscall dMap_c::mapDrawIconFree(short,
                                      short,
                                      unsigned char) */

void __thiscall dMap_c::mapDrawIconFree(dMap_c *this,short param_1,short param_2,uchar param_3)

{
  uint uVar1;
  
  if ((param_2 & 0xffU) != 0) {
    uVar1 = (int)(short)this ^ 0x80000000;
    dMap_2DMtMapSpcl_c::setPos
              ((dMap_2DMtMapSpcl_c *)&mIconFreeTex,
               (short)(int)((float)((double)CONCAT44(0x43300000,uVar1) - d_map::_4818) -
                           d_map::_5373 * mIconFreeScale),
               (short)(int)((float)((double)CONCAT44(0x43300000,(int)param_1 ^ 0x80000000U) -
                                   d_map::_4818) - d_map::_5372 * mIconFreeScale),
               (short)(int)((float)((double)CONCAT44(0x43300000,uVar1) - d_map::_4818) +
                           d_map::_5373 * mIconFreeScale),
               (short)(int)((float)((double)CONCAT44(0x43300000,(int)param_1 ^ 0x80000000U) -
                                   d_map::_4818) + d_map::_5372 * mIconFreeScale));
    DAT_803c38ec = 0xff;
    DAT_803c38ed = 0xd2;
    DAT_803c38ee = 0;
    DAT_803c38ef = (undefined)param_2;
    dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                      &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                      &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                      (dDlst_base_c *)&mIconFreeTex);
  }
  return;
}


/* __thiscall dMap_c::mapDrawIconSelf(short,
                                      short,
                                      unsigned char) */

void __thiscall dMap_c::mapDrawIconSelf(dMap_c *this,short param_1,short param_2,uchar param_3)

{
  uint uVar1;
  
  if ((param_2 & 0xffU) != 0) {
    uVar1 = (int)(short)this ^ 0x80000000;
    dMap_2DMtMapSpcl_c::setPos
              ((dMap_2DMtMapSpcl_c *)&mIconSelfTex,
               (short)(int)((float)((double)CONCAT44(0x43300000,uVar1) - d_map::_4818) -
                           d_map::_5373 * mIconFreeScale),
               (short)(int)((float)((double)CONCAT44(0x43300000,(int)param_1 ^ 0x80000000U) -
                                   d_map::_4818) - d_map::_5372 * mIconFreeScale),
               (short)(int)((float)((double)CONCAT44(0x43300000,uVar1) - d_map::_4818) +
                           d_map::_5373 * mIconFreeScale),
               (short)(int)((float)((double)CONCAT44(0x43300000,(int)param_1 ^ 0x80000000U) -
                                   d_map::_4818) + d_map::_5372 * mIconFreeScale));
    DAT_803c3960 = 0xff;
    DAT_803c3961 = 0xff;
    DAT_803c3962 = 0xff;
    DAT_803c3963 = (undefined)param_2;
    dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                      &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                      &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                      (dDlst_base_c *)&mIconSelfTex);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f1c */
/* WARNING: Inlined function: FUN_80328f68 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dMap_c::mapDrawFrame(unsigned char) */

void __thiscall dMap_c::mapDrawFrame(dMap_c *this,uchar param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (((uint)this & 0xff) != 0) {
    iVar4 = 0;
    iVar3 = 0;
    iVar2 = 0;
    iVar1 = 0;
    do {
      dMap_2DMtMapSpcl_c::setPos
                ((dMap_2DMtMapSpcl_c *)(dDlst_base_c *)(&mFrameTex + iVar2),
                 _mDispPosLeftUpX + *(short *)((int)&d_map::position_5408 + iVar1),
                 _mDispPosLeftUpY + *(short *)((int)&DAT_8034f0ca + iVar1),
                 _mDispPosLeftUpX + *(short *)((int)&DAT_8034f0cc + iVar1),
                 _mDispPosLeftUpY + *(short *)((int)&DAT_8034f0ce + iVar1));
      (&DAT_803c3680)[iVar3] = 0xff;
      (&DAT_803c3681)[iVar3] = 0xff;
      (&DAT_803c3682)[iVar3] = 0xff;
      (&DAT_803c3683)[iVar3] = (char)this;
      dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                        &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                        &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                        (dDlst_base_c *)(&mFrameTex + iVar2));
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 0x48;
      iVar2 = iVar2 + 0x14;
      iVar1 = iVar1 + 8;
    } while (iVar4 < 8);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328ea4 */
/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328ef0 */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dMap_c::mapDrawEnlargementSize(float,
                                             float,
                                             float,
                                             float,
                                             unsigned char) */

void __thiscall
dMap_c::mapDrawEnlargementSize
          (dMap_c *this,float param_1,float param_2,float param_3,float param_4,uchar param_5)

{
  int iVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  
  dVar4 = (double)param_3;
  dVar5 = (double)param_4;
  dVar3 = (double)param_2;
  dVar2 = (double)param_1;
  if (((uint)this & 0xff) != 0) {
    DAT_803c3bd4 = (int)_mDispPosLeftUpX;
    DAT_803c3bdc = (int)_mDispPosLeftUpY;
    DAT_803c3bd8 = DAT_803c3bd4 + _mDispSizeX;
    DAT_803c3be0 = DAT_803c3bdc + _mDispSizeY;
    DAT_803c3be8 = 0;
    DAT_803c3be4 = (uchar)this;
    dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                      &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                      &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                      (dDlst_base_c *)&m2DSQdraw);
    if ((*(byte *)(_mNowRoomInfoP + 1) & 2) != 0) {
      dMap_RoomInfoCtrl_c::ctrlDrawRoomEnlargementSize
                (&mRoomInfoCtrl,*(int *)(_mNowRoomInfoP + 0x10),(int)_mDispPosLeftUpX,
                 (int)_mDispPosLeftUpY,(int)_mDispSizeX,(int)_mDispSizeY,(float)dVar2,(float)dVar3,
                 (float)dVar4,(float)dVar5,(uchar)this);
    }
    DAT_803c3c00 = (int)_mDispPosLeftUpX;
    DAT_803c3c08 = (int)_mDispPosLeftUpY;
    DAT_803c3c04 = DAT_803c3c00 + _mDispSizeX;
    DAT_803c3c0c = DAT_803c3c08 + _mDispSizeY;
    iVar1 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)
                      (0x803c9d58);
    if (((*(uint *)(iVar1 + 0xc) >> 0x10 & 7) == 0) ||
       (iVar1 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)
                          (0x803c9d58), (*(uint *)(iVar1 + 0xc) >> 0x10 & 7) == 7)) {
      DAT_803c3c18 = d_map::l_color_field_5431;
      DAT_803c3c19 = UNK_803f8209;
      DAT_803c3c1a = UNK_803f820a;
      DAT_803c3c1b = UNK_803f820b;
    }
    else {
      DAT_803c3c18 = d_map::l_color_dungeon_5432;
      DAT_803c3c19 = UNK_803f820d;
      DAT_803c3c1a = UNK_803f820e;
      DAT_803c3c1b = UNK_803f820f;
    }
    DAT_803c3c14 = 1;
    dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                      &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                      &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                      (dDlst_base_c *)&m2DSQdraw2);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x8004932c) */
/* WARNING: Removing unreachable block (ram,0x8004931c) */
/* WARNING: Removing unreachable block (ram,0x80049314) */
/* WARNING: Removing unreachable block (ram,0x80049324) */
/* WARNING: Removing unreachable block (ram,0x80049334) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dMap_c::mapDrawRealSize(float,
                                      float,
                                      unsigned char) */

void __thiscall dMap_c::mapDrawRealSize(dMap_c *this,float param_1,float param_2,uchar param_3)

{
  int iVar1;
  ulong uVar2;
  int iVar3;
  undefined4 uVar4;
  double dVar5;
  double dVar6;
  undefined8 in_f27;
  undefined8 in_f28;
  undefined8 in_f29;
  double dVar7;
  undefined8 in_f30;
  double dVar8;
  undefined8 in_f31;
  double dVar9;
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar6 = (double)param_2;
  dVar5 = (double)param_1;
  uVar4 = 0;
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
  if (((uint)this & 0xff) != 0) {
    DAT_803c3bd4 = (int)_mDispPosLeftUpX;
    DAT_803c3bdc = (int)_mDispPosLeftUpY;
    DAT_803c3bd8 = DAT_803c3bd4 + _mDispSizeX;
    DAT_803c3be0 = DAT_803c3bdc + _mDispSizeY;
    DAT_803c3be8 = 0;
    DAT_803c3be4 = (uchar)this;
    dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                      &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                      &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                      (dDlst_base_c *)&m2DSQdraw);
    iVar3 = _mNowRoomInfoP;
    if ((*(byte *)(_mNowRoomInfoP + 1) & 1) != 0) {
      if (*(int *)(_mNowRoomInfoP + 0xe8) == 0) {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar2,"d_map.h",0x467,"mStageMapInfoP != 0");
        m_Do_printf::OSPanic("d_map.h",0x467,&DAT_8034f1dd);
      }
      iVar1 = _mNowRoomInfoP;
      dVar9 = (double)*(float *)(*(int *)(iVar3 + 0xe8) + 0x30);
      if (*(int *)(_mNowRoomInfoP + 0xe8) == 0) {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar2,"d_map.h",0x467,"mStageMapInfoP != 0");
        m_Do_printf::OSPanic("d_map.h",0x467,&DAT_8034f1dd);
      }
      iVar3 = _mNowRoomInfoP;
      dVar8 = (double)*(float *)(*(int *)(iVar1 + 0xe8) + 0x30);
      if (*(int *)(_mNowRoomInfoP + 0xe8) == 0) {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar2,"d_map.h",0x467,"mStageMapInfoP != 0");
        m_Do_printf::OSPanic("d_map.h",0x467,&DAT_8034f1dd);
      }
      iVar3 = *(int *)(iVar3 + 0xe8);
      if (iVar3 == 0) {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar2,"d_map.cpp",0x2ed,"i_mapInfoP != 0");
        m_Do_printf::OSPanic("d_map.cpp",0x2ed,&DAT_8034f1dd);
      }
      iVar1 = _mNowRoomInfoP;
      dVar7 = (double)*(float *)(iVar3 + 0x2c);
      if (*(int *)(_mNowRoomInfoP + 0xe8) == 0) {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar2,"d_map.h",0x467,"mStageMapInfoP != 0");
        m_Do_printf::OSPanic("d_map.h",0x467,&DAT_8034f1dd);
      }
      iVar3 = *(int *)(iVar1 + 0xe8);
      if (iVar3 == 0) {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar2,"d_map.cpp",0x2e7,"i_mapInfoP != 0");
        m_Do_printf::OSPanic("d_map.cpp",0x2e7,&DAT_8034f1dd);
      }
      dMap_RoomInfoCtrl_c::ctrlDrawRoomRealSize
                (&mRoomInfoCtrl,*(int *)(_mNowRoomInfoP + 0x10),(int)_mDispPosLeftUpX,
                 (int)_mDispPosLeftUpY,(int)_mDispSizeX,(int)_mDispSizeY,(float)dVar5,(float)dVar6,
                 *(float *)(iVar3 + 0x28),(float)dVar7,(float)dVar8,(float)dVar9,(uchar)this);
    }
    DAT_803c3c00 = (int)_mDispPosLeftUpX;
    DAT_803c3c08 = (int)_mDispPosLeftUpY;
    DAT_803c3c04 = DAT_803c3c00 + _mDispSizeX;
    DAT_803c3c0c = DAT_803c3c08 + _mDispSizeY;
    iVar3 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)
                      (0x803c9d58);
    if (((*(uint *)(iVar3 + 0xc) >> 0x10 & 7) == 0) ||
       (iVar3 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)
                          (0x803c9d58), (*(uint *)(iVar3 + 0xc) >> 0x10 & 7) == 7)) {
      DAT_803c3c18 = d_map::l_color_field_5490;
      DAT_803c3c19 = UNK_803f8211;
      DAT_803c3c1a = UNK_803f8212;
      DAT_803c3c1b = UNK_803f8213;
    }
    else {
      DAT_803c3c18 = d_map::l_color_dungeon_5491;
      DAT_803c3c19 = UNK_803f8215;
      DAT_803c3c1a = UNK_803f8216;
      DAT_803c3c1b = UNK_803f8217;
    }
    DAT_803c3c14 = 1;
    dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                      &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                      &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                      (dDlst_base_c *)&m2DSQdraw2);
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  __psq_l0(auStack24,uVar4);
  __psq_l1(auStack24,uVar4);
  __psq_l0(auStack40,uVar4);
  __psq_l1(auStack40,uVar4);
  __psq_l0(auStack56,uVar4);
  __psq_l1(auStack56,uVar4);
  __psq_l0(auStack72,uVar4);
  __psq_l1(auStack72,uVar4);
  return;
}


/* __thiscall dMap_c::mapAGBSendIslandData(void) */

dMap_c * __thiscall dMap_c::mapAGBSendIslandData(dMap_c *this)

{
  char cVar1;
  char cVar2;
  char cVar3;
  float fVar4;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  JKRExpHeap **ppJVar8;
  int iVar9;
  int iVar10;
  
  if (mFmapChkPntData_p != (FmapChkPnt *)0x0) {
    ppJVar8 = dStage_roomControl_c::mMemoryBlock + 0x34;
    iVar9 = 0;
    iVar5 = 0;
    uVar6 = (uint)mFmapChkPntValue;
    iVar10 = 0x31;
    do {
      if (iVar9 < (int)uVar6) {
        pcVar7 = &mFmapChkPntData_p->mSectorX + iVar5;
        fVar4 = d_map::_5602 *
                ((d_map::_5603 +
                 (float)((double)CONCAT44(0x43300000,(int)*(short *)(pcVar7 + 4) ^ 0x80000000) -
                        d_map::_4818)) / d_map::_5604);
        cVar1 = pcVar7[6];
        cVar2 = *pcVar7;
        cVar3 = pcVar7[1];
        *(char *)ppJVar8 =
             (char)(int)(d_map::_5602 *
                        ((d_map::_5603 +
                         (float)((double)CONCAT44(0x43300000,
                                                  (int)*(short *)(pcVar7 + 2) ^ 0x80000000) -
                                d_map::_4818)) / d_map::_5604));
        *(char *)((int)ppJVar8 + 1) = (char)(int)fVar4;
        *(char *)((int)ppJVar8 + 2) = cVar1;
        *(char *)((int)ppJVar8 + 3) = cVar2 + (cVar3 + '\x03') * '\a' + '\x03';
      }
      else {
        *(undefined *)ppJVar8 = 0;
        *(undefined *)((int)ppJVar8 + 1) = 0;
        *(undefined *)((int)ppJVar8 + 2) = 0;
        *(undefined *)((int)ppJVar8 + 3) = 0xff;
      }
      iVar9 = iVar9 + 1;
      iVar5 = iVar5 + 8;
      ppJVar8 = ppJVar8 + 1;
      iVar10 = iVar10 + -1;
    } while (iVar10 != 0);
    this = (dMap_c *)
           mDoGaC_agbCom_c::mDoGaC_SendDataSet
                     ((mDoGaC_agbCom_c *)&m_Do_ext::m_Do_gba_com::g_mDoGaC_gbaCom,
                      (ulong *)(dStage_roomControl_c::mMemoryBlock + 0x34),0xc4,'\x0e',0);
  }
  return this;
}


/* __thiscall dMap_c::setPlayerStayAgbMapTypeNow(float,
                                                 float) */

void __thiscall dMap_c::setPlayerStayAgbMapTypeNow(dMap_c *this,float param_1,float param_2)

{
  bool in_r4;
  
  mPlayerStayAgbMapTypeNow = getPosAgbMapType((dMap_c *)&DAT_00000001,param_1,param_2,in_r4);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dMap_c::agbMapNoSet(unsigned char,
                                  unsigned char) */

void __thiscall dMap_c::agbMapNoSet(dMap_c *this,uchar param_1,uchar param_2)

{
  daAgb_c *this_00;
  int iVar1;
  undefined3 in_register_00000010;
  undefined3 in_register_00000014;
  
  this_00 = d_com_inf_game::g_dComIfG_gameInfo.mpAgb;
  if (d_com_inf_game::g_dComIfG_gameInfo.mpAgb != (daAgb_c *)0x0) {
    iVar1 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)
                      (0x803c9d58,CONCAT31(in_register_00000010,param_1),
                       CONCAT31(in_register_00000014,param_2));
    daAgb_c::MapNoSet(this_00,*(byte *)(iVar1 + 9) >> 1,(uchar)this,param_1);
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dMap_c::agbMapNoSetCall(void) */

void __thiscall dMap_c::agbMapNoSetCall(dMap_c *this)

{
  uint uVar1;
  int iVar2;
  uchar in_r5;
  
  iVar2 = getKindMapType(this);
  if (iVar2 == 1) {
    if ((-4 < (char)mPlGridX) && ((char)mPlGridX < '\x04')) {
      if ((-4 < (char)mPlGridY) && ((char)mPlGridY < '\x04')) {
        uVar1 = countLeadingZeros(3 - (uint)mPlayerStayAgbMapTypeNow);
        agbMapNoSet((dMap_c *)((uint)mPlGridX + (mPlGridY + 3) * 7 + 4 & 0xff),(uchar)(uVar1 >> 5),
                    in_r5);
      }
    }
  }
  else {
    if (-1 < (int)*(uint *)(_mNowRoomInfoP + 0x10)) {
      agbMapNoSet((dMap_c *)(*(uint *)(_mNowRoomInfoP + 0x10) & 0xff),'\0',in_r5);
    }
  }
  return;
}


/* __thiscall dMap_c::agbIsMsgSend(void) */

undefined __thiscall dMap_c::agbIsMsgSend(dMap_c *this)

{
  if (d_com_inf_game::g_dComIfG_gameInfo.mpAgb == (daAgb_c *)0x0) {
    return 0;
  }
  return *(undefined *)&(d_com_inf_game::g_dComIfG_gameInfo.mpAgb)->field_0x678;
}


/* __thiscall dMap_c::agbResetCursor(void) */

void __thiscall dMap_c::agbResetCursor(dMap_c *this)

{
  if (d_com_inf_game::g_dComIfG_gameInfo.mpAgb != (daAgb_c *)0x0) {
    daAgb_c::resetCursor(d_com_inf_game::g_dComIfG_gameInfo.mpAgb,true);
  }
  return;
}


/* __thiscall dMap_c::agbScrollX(void) */

undefined2 __thiscall dMap_c::agbScrollX(dMap_c *this)

{
  if (d_com_inf_game::g_dComIfG_gameInfo.mpAgb == (daAgb_c *)0x0) {
    return 0;
  }
  return *(undefined2 *)&(d_com_inf_game::g_dComIfG_gameInfo.mpAgb)->field_0x630;
}


/* __thiscall dMap_c::agbScrollY(void) */

undefined2 __thiscall dMap_c::agbScrollY(dMap_c *this)

{
  if (d_com_inf_game::g_dComIfG_gameInfo.mpAgb == (daAgb_c *)0x0) {
    return 0;
  }
  return *(undefined2 *)&(d_com_inf_game::g_dComIfG_gameInfo.mpAgb)->field_0x632;
}


/* __thiscall dMap_c::agbFlashCheck(void) */

undefined4 __thiscall dMap_c::agbFlashCheck(dMap_c *this)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (d_com_inf_game::g_dComIfG_gameInfo.mpAgb != (daAgb_c *)0x0) {
    uVar1 = daAgb_c::FlashCheck(d_com_inf_game::g_dComIfG_gameInfo.mpAgb);
  }
  return uVar1;
}


/* __thiscall dMap_c::agbIsActive(void) */

undefined __thiscall dMap_c::agbIsActive(dMap_c *this)

{
  if (d_com_inf_game::g_dComIfG_gameInfo.mpAgb == (daAgb_c *)0x0) {
    return 0;
  }
  return *(undefined *)&(d_com_inf_game::g_dComIfG_gameInfo.mpAgb)->field_0x672;
}


/* WARNING: Removing unreachable block (ram,0x80049af4) */
/* WARNING: Removing unreachable block (ram,0x80049afc) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dMap_c::isInDspArea(float,
                                  float,
                                  bool) */

undefined4 __thiscall dMap_c::isInDspArea(dMap_c *this,float param_1,float param_2,bool param_3)

{
  int iVar1;
  ulong uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  double dVar6;
  double dVar7;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  iVar3 = _mNowRoomInfoP;
  dVar7 = (double)param_2;
  dVar6 = (double)param_1;
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  uVar4 = 0;
  if (_mNowRoomInfoP != 0) {
    if (((uint)this & 0xff) == 0) {
      if ((*(byte *)(_mNowRoomInfoP + 1) & 2) != 0) {
        if (*(int *)(_mNowRoomInfoP + 0xe8) == 0) {
          uVar2 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar2,"d_map.h",0x467,"mStageMapInfoP != 0");
          m_Do_printf::OSPanic("d_map.h",0x467,&DAT_8034f1dd);
        }
        iVar1 = _mNowRoomInfoP;
        if ((double)**(float **)(iVar3 + 0xe8) <= dVar6) {
          if (*(int *)(_mNowRoomInfoP + 0xe8) == 0) {
            uVar2 = JUTAssertion::getSDevice();
            JUTAssertion::showAssert(uVar2,"d_map.h",0x467,"mStageMapInfoP != 0");
            m_Do_printf::OSPanic("d_map.h",0x467,&DAT_8034f1dd);
          }
          iVar3 = _mNowRoomInfoP;
          if (dVar6 <= (double)*(float *)(*(int *)(iVar1 + 0xe8) + 8)) {
            if (*(int *)(_mNowRoomInfoP + 0xe8) == 0) {
              uVar2 = JUTAssertion::getSDevice();
              JUTAssertion::showAssert(uVar2,"d_map.h",0x467,"mStageMapInfoP != 0");
              m_Do_printf::OSPanic("d_map.h",0x467,&DAT_8034f1dd);
            }
            iVar1 = _mNowRoomInfoP;
            if ((double)*(float *)(*(int *)(iVar3 + 0xe8) + 4) <= dVar7) {
              if (*(int *)(_mNowRoomInfoP + 0xe8) == 0) {
                uVar2 = JUTAssertion::getSDevice();
                JUTAssertion::showAssert(uVar2,"d_map.h",0x467,"mStageMapInfoP != 0");
                m_Do_printf::OSPanic("d_map.h",0x467,&DAT_8034f1dd);
              }
              if (dVar7 <= (double)*(float *)(*(int *)(iVar1 + 0xe8) + 0xc)) {
                uVar4 = 1;
              }
            }
          }
        }
      }
    }
    else {
      if ((*(byte *)(_mNowRoomInfoP + 1) & 1) != 0) {
        if (*(int *)(_mNowRoomInfoP + 0xe8) == 0) {
          uVar2 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar2,"d_map.h",0x467,"mStageMapInfoP != 0");
          m_Do_printf::OSPanic("d_map.h",0x467,&DAT_8034f1dd);
        }
        iVar3 = *(int *)(iVar3 + 0xe8);
        if (iVar3 == 0) {
          uVar2 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar2,"d_map.cpp",0x2cf,"i_mapInfoP != 0");
          m_Do_printf::OSPanic("d_map.cpp",0x2cf,&DAT_8034f1dd);
        }
        iVar1 = _mNowRoomInfoP;
        if ((double)*(float *)(iVar3 + 0x18) <= dVar6) {
          if (*(int *)(_mNowRoomInfoP + 0xe8) == 0) {
            uVar2 = JUTAssertion::getSDevice();
            JUTAssertion::showAssert(uVar2,"d_map.h",0x467,"mStageMapInfoP != 0");
            m_Do_printf::OSPanic("d_map.h",0x467,&DAT_8034f1dd);
          }
          iVar3 = *(int *)(iVar1 + 0xe8);
          if (iVar3 == 0) {
            uVar2 = JUTAssertion::getSDevice();
            JUTAssertion::showAssert(uVar2,"d_map.cpp",0x2db,"i_mapInfoP != 0");
            m_Do_printf::OSPanic("d_map.cpp",0x2db,&DAT_8034f1dd);
          }
          iVar1 = _mNowRoomInfoP;
          if (dVar6 <= (double)*(float *)(iVar3 + 0x20)) {
            if (*(int *)(_mNowRoomInfoP + 0xe8) == 0) {
              uVar2 = JUTAssertion::getSDevice();
              JUTAssertion::showAssert(uVar2,"d_map.h",0x467,"mStageMapInfoP != 0");
              m_Do_printf::OSPanic("d_map.h",0x467,&DAT_8034f1dd);
            }
            iVar3 = *(int *)(iVar1 + 0xe8);
            if (iVar3 == 0) {
              uVar2 = JUTAssertion::getSDevice();
              JUTAssertion::showAssert(uVar2,"d_map.cpp",0x2d5,"i_mapInfoP != 0");
              m_Do_printf::OSPanic("d_map.cpp",0x2d5,&DAT_8034f1dd);
            }
            iVar1 = _mNowRoomInfoP;
            if ((double)*(float *)(iVar3 + 0x1c) <= dVar7) {
              if (*(int *)(_mNowRoomInfoP + 0xe8) == 0) {
                uVar2 = JUTAssertion::getSDevice();
                JUTAssertion::showAssert(uVar2,"d_map.h",0x467,"mStageMapInfoP != 0");
                m_Do_printf::OSPanic("d_map.h",0x467,&DAT_8034f1dd);
              }
              iVar3 = *(int *)(iVar1 + 0xe8);
              if (iVar3 == 0) {
                uVar2 = JUTAssertion::getSDevice();
                JUTAssertion::showAssert(uVar2,"d_map.cpp",0x2e1,"i_mapInfoP != 0");
                m_Do_printf::OSPanic("d_map.cpp",0x2e1,&DAT_8034f1dd);
              }
              if (dVar7 <= (double)*(float *)(iVar3 + 0x24)) {
                uVar4 = 1;
              }
            }
          }
        }
      }
    }
  }
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  __psq_l0(auStack24,uVar5);
  __psq_l1(auStack24,uVar5);
  return uVar4;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dMap_c::mapAGBSendStatInit(void) */

void __thiscall dMap_c::mapAGBSendStatInit(dMap_c *this)

{
  mAGBMapSendStopFlg = 0;
  FUN_800033a8((int)&mAgbSendNowStageName,0,8);
  _mAgbSendNowRoomNo = 0xffffffff;
  _mAgbSendNowDspFloorNo = 0xffff;
  mAgbSendNowAgbMapType = 0xff;
  return;
}


/* WARNING: Removing unreachable block (ram,0x8004a380) */
/* WARNING: Removing unreachable block (ram,0x8004a370) */
/* WARNING: Removing unreachable block (ram,0x8004a368) */
/* WARNING: Removing unreachable block (ram,0x8004a378) */
/* WARNING: Removing unreachable block (ram,0x8004a388) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dMap_c::calcEnlargementSizeParameter(float,
                                                   float) */

void __thiscall dMap_c::calcEnlargementSizeParameter(dMap_c *this,float param_1,float param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  char cVar6;
  ulong uVar5;
  undefined4 uVar7;
  double dVar8;
  undefined8 in_f27;
  undefined8 in_f28;
  undefined8 in_f29;
  double dVar9;
  undefined8 in_f30;
  double dVar10;
  undefined8 in_f31;
  double dVar11;
  double dVar12;
  double dVar13;
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar13 = (double)param_2;
  dVar9 = (double)param_1;
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
  cVar6 = isEnableEnlargementScroll(this);
  iVar3 = _mNowRoomInfoP;
  if ((cVar6 != '\0') && ((*(byte *)(_mNowRoomInfoP + 1) & 2) != 0)) {
    if (*(int *)(_mNowRoomInfoP + 0xe8) == 0) {
      uVar5 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar5,"d_map.h",0x467,"mStageMapInfoP != 0");
      m_Do_printf::OSPanic("d_map.h",0x467,&DAT_8034f1dd);
    }
    iVar4 = _mNowRoomInfoP;
    dVar11 = (double)*(float *)(*(int *)(iVar3 + 0xe8) + 0x10);
    if (*(int *)(_mNowRoomInfoP + 0xe8) == 0) {
      uVar5 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar5,"d_map.h",0x467,"mStageMapInfoP != 0");
      m_Do_printf::OSPanic("d_map.h",0x467,&DAT_8034f1dd);
    }
    iVar3 = _mNowRoomInfoP;
    dVar11 = (double)(d_map::_6065 *
                     ABS((float)((double)*(float *)(*(int *)(iVar4 + 0xe8) + 8) - dVar11)));
    if (*(int *)(_mNowRoomInfoP + 0xe8) == 0) {
      uVar5 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar5,"d_map.h",0x467,"mStageMapInfoP != 0");
      m_Do_printf::OSPanic("d_map.h",0x467,&DAT_8034f1dd);
    }
    iVar4 = _mNowRoomInfoP;
    dVar12 = (double)*(float *)(*(int *)(iVar3 + 0xe8) + 0x14);
    if (*(int *)(_mNowRoomInfoP + 0xe8) == 0) {
      uVar5 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar5,"d_map.h",0x467,"mStageMapInfoP != 0");
      m_Do_printf::OSPanic("d_map.h",0x467,&DAT_8034f1dd);
    }
    iVar3 = _mNowRoomInfoP;
    dVar12 = (double)(d_map::_6065 *
                     ABS((float)((double)*(float *)(*(int *)(iVar4 + 0xe8) + 0xc) - dVar12)));
    if (*(int *)(_mNowRoomInfoP + 0xe8) == 0) {
      uVar5 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar5,"d_map.h",0x467,"mStageMapInfoP != 0");
      m_Do_printf::OSPanic("d_map.h",0x467,&DAT_8034f1dd);
    }
    iVar4 = _mNowRoomInfoP;
    dVar9 = (double)(float)(dVar9 - (double)*(float *)(*(int *)(iVar3 + 0xe8) + 0x10));
    if (*(int *)(_mNowRoomInfoP + 0xe8) == 0) {
      uVar5 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar5,"d_map.h",0x467,"mStageMapInfoP != 0");
      m_Do_printf::OSPanic("d_map.h",0x467,&DAT_8034f1dd);
    }
    iVar3 = _mNowRoomInfoP;
    fVar1 = (float)(dVar13 - (double)*(float *)(*(int *)(iVar4 + 0xe8) + 0x14));
    fVar2 = d_map::_6066;
    if ((double)d_map::_4426 <= dVar9) {
      fVar2 = d_map::_4611;
    }
    dVar13 = (double)fVar2;
    fVar2 = d_map::_6066;
    if (d_map::_4426 <= fVar1) {
      fVar2 = d_map::_4611;
    }
    dVar10 = (double)fVar2;
    dVar8 = (double)(float)ABS(dVar9);
    if (dVar8 <= dVar11) {
      dVar11 = (double)d_map::_4426;
    }
    else {
      dVar11 = (double)(d_map::_6067 * (float)(dVar8 - dVar11));
      if (dVar8 < dVar11) {
        dVar11 = dVar8;
      }
    }
    dVar8 = (double)ABS(fVar1);
    if (dVar8 <= dVar12) {
      dVar12 = (double)d_map::_4426;
    }
    else {
      dVar12 = (double)(d_map::_6067 * (float)(dVar8 - dVar12));
      if (dVar8 < dVar12) {
        dVar12 = dVar8;
      }
    }
    if (((double)d_map::_4426 != dVar11) || ((double)d_map::_4426 != dVar12)) {
      if (dVar11 <= dVar12) {
        dVar11 = (double)((float)(dVar12 * (double)(float)ABS(dVar9)) / ABS(fVar1));
      }
      else {
        dVar12 = (double)((float)(dVar11 * (double)ABS(fVar1)) / (float)ABS(dVar9));
      }
    }
    if (*(int *)(_mNowRoomInfoP + 0xe8) == 0) {
      uVar5 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar5,"d_map.h",0x467,"mStageMapInfoP != 0");
      m_Do_printf::OSPanic("d_map.h",0x467,&DAT_8034f1dd);
    }
    iVar4 = _mNowRoomInfoP;
    _mEnlargementSizeCenterX = (float)(dVar13 * dVar11) + *(float *)(*(int *)(iVar3 + 0xe8) + 0x10);
    if (*(int *)(_mNowRoomInfoP + 0xe8) == 0) {
      uVar5 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar5,"d_map.h",0x467,"mStageMapInfoP != 0");
      m_Do_printf::OSPanic("d_map.h",0x467,&DAT_8034f1dd);
    }
    _mEnlargementSizeCenterZ = (float)(dVar10 * dVar12) + *(float *)(*(int *)(iVar4 + 0xe8) + 0x14);
    _mEnlargementSizeScaleX = *(undefined4 *)(_mNowRoomInfoP + 0x18);
    _mEnlargementSizeScaleZ = *(undefined4 *)(_mNowRoomInfoP + 0x1c);
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
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dMap_c::calcScissor(void) */

void __thiscall dMap_c::calcScissor(dMap_c *this)

{
  _mScissorOrigX =
       (int)((d_map::_6086 *
             ((float)((double)CONCAT44(0x43300000,(int)_mDispPosLeftUpX ^ 0x80000000) - d_map::_4818
                     ) - d_map::_6087)) / d_map::_6088);
  _mScissorOrigY =
       (int)((d_map::_6089 *
             ((float)((double)CONCAT44(0x43300000,(int)_mDispPosLeftUpY ^ 0x80000000) - d_map::_4818
                     ) - d_map::_6090)) / d_map::_6091);
  _mScissorWidth = 0x74;
  _mScissorHeight = 0x6d;
  if (_mScissorOrigX < 0) {
    _mScissorWidth = _mScissorOrigX + 0x74;
    if (_mScissorWidth < 0) {
      _mScissorWidth = 0;
    }
    _mScissorOrigX = 0;
  }
  if (_mScissorOrigY < 0) {
    _mScissorHeight = _mScissorOrigY + 0x6d;
    if (_mScissorHeight < 0) {
      _mScissorHeight = 0;
    }
    _mScissorOrigY = 0;
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x8004a6c0) */
/* WARNING: Removing unreachable block (ram,0x8004a6b8) */
/* WARNING: Removing unreachable block (ram,0x8004a6c8) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dMap_c::mapMoveAll(float,
                                 float,
                                 int,
                                 float) */

void __thiscall
dMap_c::mapMoveAll(dMap_c *this,float param_1,float param_2,int param_3,float param_4)

{
  dMap_c dVar1;
  uint uVar2;
  dMap_c *pdVar3;
  dMap_c *pdVar4;
  int extraout_r4;
  int iVar5;
  dMap_c *extraout_r4_00;
  undefined4 uVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined8 uVar10;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar9 = (double)param_4;
  dVar8 = (double)param_2;
  dVar7 = (double)param_1;
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  setPlayerStayAgbMapTypeNow(this,param_1,param_2);
  uVar10 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)();
  iVar5 = (int)uVar10;
  uVar2 = *(uint *)((int)((ulonglong)uVar10 >> 0x20) + 0xc) >> 0x10 & 7;
  if ((((uVar2 != 5) && (uVar2 != 7)) && (-1 < (int)this)) && ((int)this < 0x40)) {
    dSv_memBit_c::onVisitedRoom
              ((dSv_memBit_c *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMemory,(int)this);
    iVar5 = extraout_r4;
  }
  if ((this != (dMap_c *)&DAT_ffffffff) && (_mNowRoomInfoP == (dMap_c *)0x0)) {
    setNowRoom(this,iVar5);
  }
  if (_mNowRoomInfoP != (dMap_c *)0x0) {
    pdVar3 = (dMap_c *)d_map::dMap_GetFloorNo_WithRoom(dVar9,this);
    pdVar4 = pdVar3;
    if ((_mNowRoomInfoP != (dMap_c *)0x0) &&
       (pdVar4 = (dMap_c *)((uint)pdVar3 & 0xff),
       (dMap_c *)((uint)pdVar3 & 0xff) != (dMap_c *)(uint)mNowFloorNo)) {
      dVar1 = _mNowRoomInfoP[0xc];
      mNowFloorNo = (byte)pdVar3;
      dMap_RoomInfoCtrl_c::checkFloorMoveImageChangeRoom
                (&mRoomInfoCtrl,mNowFloorNo,mNowFloorNo,(int)this,0x78,0x78,(float)dVar9);
      pdVar4 = _mNowRoomInfoP;
      pdVar3 = extraout_r4_00;
      if (dVar1 != _mNowRoomInfoP[0xc]) {
        mAGBMapSendStatus = 0;
        mAGBMapSendStopFlg = 0;
      }
    }
    if ((this != (dMap_c *)&DAT_ffffffff) &&
       (pdVar4 = _mNowRoomInfoP, this != *(dMap_c **)(_mNowRoomInfoP + 0x10))) {
      pdVar4 = (dMap_c *)setNowRoom(this,(int)pdVar3);
    }
    if (_mNowRoomInfoP != (dMap_c *)0x0) {
      pdVar4 = (dMap_c *)calcEnlargementSizeParameter(pdVar4,(float)dVar7,(float)dVar8);
      mapAGBSendMapMain(pdVar4,(float)dVar7,(float)dVar8);
      if (mMapDispMode == '\x01') {
        if (((byte)_mNowRoomInfoP[1] & 2) != 0) {
          _mNowCenterX = _mEnlargementSizeCenterX;
          _mNowCenterZ = _mEnlargementSizeCenterZ;
          _mNowScaleX = _mEnlargementSizeScaleX;
          _mNowScaleZ = _mEnlargementSizeScaleZ;
        }
      }
      else {
        if (((byte)_mNowRoomInfoP[1] & 1) != 0) {
          _mNowCenterX = (float)dVar7;
          _mNowCenterZ = (float)dVar8;
          _mNowScaleX = *(undefined4 *)(_mNowRoomInfoP + 0x20);
          _mNowScaleZ = *(undefined4 *)(_mNowRoomInfoP + 0x24);
        }
      }
      calcScissor(_mNowRoomInfoP);
      if (*(int *)(_mNowRoomInfoP + 0xe8) == 0) {
        mCompAlpha = 0;
      }
      else {
        mCompAlpha = (undefined)
                     ((uint)mAlpha * (uint)*(byte *)(*(int *)(_mNowRoomInfoP + 0xe8) + 0x34) >> 8);
      }
      setCollectPoint(0x14,9,d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mRestart.mLinkRestartPos.x,
                      d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mRestart.mLinkRestartPos.y,
                      d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mRestart.mLinkRestartPos.z,
                      d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mRestart.mRestartCode,
                      d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mRestart.mParameter,0,0,0,0);
    }
  }
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  __psq_l0(auStack24,uVar6);
  __psq_l1(auStack24,uVar6);
  __psq_l0(auStack40,uVar6);
  __psq_l1(auStack40,uVar6);
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dMap_c::mapDrawIcon(void) */

dMap_c * __thiscall dMap_c::mapDrawIcon(dMap_c *this)

{
  uchar in_r6;
  
  if (mIconDispMode == '\x02') {
    this = (dMap_c *)
           mapDrawIconSelf((dMap_c *)(int)_mIconFreePosX,_mIconFreePosY,(ushort)mIconSelfAlpha,in_r6
                          );
  }
  else {
    if (mIconDispMode == '\x01') {
      this = (dMap_c *)
             mapDrawIconFree((dMap_c *)(int)_mIconFreePosX,_mIconFreePosY,(ushort)mIconFreeAlpha,
                             in_r6);
    }
  }
  return this;
}


/* WARNING: Inlined function: FUN_80328ea8 */
/* WARNING: Inlined function: FUN_80328ef4 */
/* __thiscall dMap_c::draw(float,
                           float,
                           int,
                           float) */

void __thiscall dMap_c::draw(dMap_c *this,float param_1,float param_2,int param_3,float param_4)

{
  dMap_c *this_00;
  int extraout_r4;
  double dVar1;
  double dVar2;
  double dVar3;
  
  dVar3 = (double)param_4;
  dVar2 = (double)param_2;
  dVar1 = (double)param_1;
  if ((-1 < (int)this) &&
     (mapMoveAll(this,param_1,param_2,param_3,param_4), f_ap_game::g_HIO._9_1_ != '\0')) {
    this_00 = (dMap_c *)mapDrawAll(this,(float)dVar1,(float)dVar2,extraout_r4,(float)dVar3);
    mapDrawIcon(this_00);
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x8004a954) */
/* WARNING: Removing unreachable block (ram,0x8004a95c) */
/* __thiscall dMap_c::point2Grid(float,
                                 float,
                                 signed char *,
                                 signed char *) */

void __thiscall
dMap_c::point2Grid(dMap_c *this,float param_1,float param_2,char *param_3,char *param_4)

{
  ulong uVar1;
  dMap_c dVar2;
  char cVar3;
  undefined4 uVar4;
  double dVar5;
  double dVar6;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar6 = (double)param_2;
  dVar5 = (double)param_1;
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  if (this == (dMap_c *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_map.cpp",0x1677,"i_gridX_p != 0");
    m_Do_printf::OSPanic("d_map.cpp",0x1677,&DAT_8034f1dd);
  }
  if (param_3 == (char *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_map.cpp",0x1678,"i_gridY_p != 0");
    m_Do_printf::OSPanic("d_map.cpp",0x1678,&DAT_8034f1dd);
  }
  dVar5 = MSL_C.PPCEABI.bare.H::floor
                    ((double)(d_map::_4929 + (float)(dVar5 / (double)d_map::_5604)));
  dVar2 = SUB41((int)dVar5,0);
  if ((char)dVar2 < -3) {
    dVar2 = (dMap_c)0xfd;
  }
  if ('\x03' < (char)dVar2) {
    dVar2 = (dMap_c)0x3;
  }
  *this = dVar2;
  dVar5 = MSL_C.PPCEABI.bare.H::floor
                    ((double)(d_map::_4929 + (float)(dVar6 / (double)d_map::_5604)));
  cVar3 = (char)(int)dVar5;
  if (cVar3 < -3) {
    cVar3 = -3;
  }
  if ('\x03' < cVar3) {
    cVar3 = '\x03';
  }
  *param_3 = cVar3;
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  __psq_l0(auStack24,uVar4);
  __psq_l1(auStack24,uVar4);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x8004ab88) */
/* WARNING: Removing unreachable block (ram,0x8004ab90) */
/* __thiscall dMap_c::point2GridAndLocal(float,
                                         float,
                                         signed char *,
                                         signed char *,
                                         short *,
                                         short *) */

void __thiscall
dMap_c::point2GridAndLocal
          (dMap_c *this,float param_1,float param_2,char *param_3,char *param_4,short *param_5,
          short *param_6)

{
  float fVar1;
  ulong uVar2;
  char cVar3;
  dMap_c dVar4;
  undefined4 uVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar9 = (double)param_2;
  dVar6 = (double)param_1;
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  if (this == (dMap_c *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_map.cpp",0x16ab,"i_gridX_p != 0");
    m_Do_printf::OSPanic("d_map.cpp",0x16ab,&DAT_8034f1dd);
  }
  if (param_3 == (char *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_map.cpp",0x16ac,"i_gridY_p != 0");
    m_Do_printf::OSPanic("d_map.cpp",0x16ac,&DAT_8034f1dd);
  }
  if (param_4 == (char *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_map.cpp",0x16ad,"i_localX_p != 0");
    m_Do_printf::OSPanic("d_map.cpp",0x16ad,&DAT_8034f1dd);
  }
  if (param_5 == (short *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_map.cpp",0x16ae,"i_localY_p != 0");
    m_Do_printf::OSPanic("d_map.cpp",0x16ae,&DAT_8034f1dd);
  }
  dVar7 = MSL_C.PPCEABI.bare.H::floor
                    ((double)(d_map::_4929 + (float)(dVar6 / (double)d_map::_5604)));
  dVar8 = MSL_C.PPCEABI.bare.H::floor
                    ((double)(d_map::_4929 + (float)(dVar9 / (double)d_map::_5604)));
  cVar3 = (char)(int)dVar8;
  dVar4 = SUB41((int)dVar7,0);
  if ((char)dVar4 < -3) {
    dVar4 = (dMap_c)0xfd;
  }
  if ('\x03' < (char)dVar4) {
    dVar4 = (dMap_c)0x3;
  }
  if (cVar3 < -3) {
    cVar3 = -3;
  }
  if ('\x03' < cVar3) {
    cVar3 = '\x03';
  }
  *this = dVar4;
  *param_3 = cVar3;
  fVar1 = d_map::_5604;
  dVar7 = d_map::_4818;
  *(short *)param_4 =
       (short)(int)(dVar6 - (double)(d_map::_5604 *
                                    (float)((double)CONCAT44(0x43300000,
                                                             (int)(char)dVar4 ^ 0x80000000) -
                                           d_map::_4818)));
  *param_5 = (short)(int)(dVar9 - (double)(fVar1 * (float)((double)CONCAT44(0x43300000,
                                                                            (int)cVar3 ^ 0x80000000)
                                                          - dVar7)));
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  __psq_l0(auStack24,uVar5);
  __psq_l1(auStack24,uVar5);
  return;
}


/* __thiscall dMap_c::getCheckPointUseGrid(signed char,
                                           signed char) */

int __thiscall dMap_c::getCheckPointUseGrid(dMap_c *this,char param_1,char param_2)

{
  uint uVar1;
  char *pcVar2;
  undefined3 in_register_00000010;
  int iVar3;
  int iVar4;
  
  pcVar2 = (char *)getFmapChkPntDtPnt((dMap_c *)0x0,CONCAT31(in_register_00000010,param_1));
  iVar3 = 0;
  uVar1 = (uint)mFmapChkPntValue;
  for (; (iVar4 = -1, uVar1 != 0 &&
         (((char)this != *pcVar2 || (iVar4 = iVar3, param_1 != pcVar2[1])))); pcVar2 = pcVar2 + 8) {
    iVar3 = iVar3 + 1;
    uVar1 = uVar1 - 1;
  }
  return iVar4;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dMap_c::getFmapChkPntPrm(int,
                                       signed char *,
                                       signed char *,
                                       short *,
                                       short *,
                                       unsigned char *) */

void __thiscall
dMap_c::getFmapChkPntPrm
          (dMap_c *this,int param_1,char *param_2,char *param_3,short *param_4,short *param_5,
          uchar *param_6)

{
  undefined *puVar1;
  
  puVar1 = (undefined *)getFmapChkPntDtPnt(this,param_1);
  if (param_1 != 0) {
    *(undefined *)param_1 = *puVar1;
  }
  if (param_2 != (char *)0x0) {
    *param_2 = puVar1[1];
  }
  if (param_3 != (char *)0x0) {
    *(undefined2 *)param_3 = *(undefined2 *)(puVar1 + 2);
  }
  if (param_4 != (short *)0x0) {
    *param_4 = *(short *)(puVar1 + 4);
  }
  if (param_5 != (short *)0x0) {
    *(undefined *)param_5 = puVar1[6];
  }
  return;
}


/* __thiscall dMap_c::setFmapChkDtPrm(void) */

void __thiscall dMap_c::setFmapChkDtPrm(dMap_c *this)

{
  if (d_com_inf_game::g_dComIfG_gameInfo.mpFmapDataArchive == (FmapData *)0x0) {
    return;
  }
  mFmapChkPntValue = (byte)(d_com_inf_game::g_dComIfG_gameInfo.mpFmapDataArchive)->mNumSectors;
  mFmapChkPntData_p = (d_com_inf_game::g_dComIfG_gameInfo.mpFmapDataArchive)->mSectors;
  return;
}


/* __thiscall dMap_c::getFmapChkPntDtPnt(int) */

FmapChkPnt * __thiscall dMap_c::getFmapChkPntDtPnt(dMap_c *this,int param_1)

{
  ulong uVar1;
  FmapChkPnt *pFVar2;
  
  if (mFmapChkPntData_p == (FmapChkPnt *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_map.cpp",0x17bb,"mFmapChkPntData_p != 0");
    m_Do_printf::OSPanic("d_map.cpp",0x17bb,&DAT_8034f1dd);
  }
  pFVar2 = (FmapChkPnt *)0x0;
  if (((int)this < 0) || ((int)(uint)mFmapChkPntValue < (int)this)) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_map.cpp",0x17c2,"0");
    m_Do_printf::OSPanic("d_map.cpp",0x17c2,&DAT_8034f1dd);
  }
  else {
    pFVar2 = mFmapChkPntData_p + (int)this;
  }
  return pFVar2;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dMap_c::initPoint(void) */

void __thiscall dMap_c::initPoint(dMap_c *this)

{
  undefined1 *puVar1;
  int iVar2;
  
  mDrawPointCntPlayer = 0;
  mDrawPointCntEnemy = 0;
  mDrawPointCntAgbCursor = 0;
  mTboxNum = 0;
  mDoorNum = 0;
  _mAGBPointValueC = 0;
  _mAGBPointValueE = 0;
  _mAGBPointValueAll = 0;
  _mAGBPointValueRoomAll = 0;
  mPointFriendNum = 0;
  mDrawPointCntShip = 0;
  mSetCursorFlg = 0;
  mDrawPointRestartCnt = 0;
  mCollectPointDataCnt = 0;
  puVar1 = &mCollectPointDataLinkList;
  iVar2 = 0x15;
  do {
    *puVar1 = 0xff;
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dMap_c::setGbaPoint_ocean(unsigned char,
                                        float,
                                        float,
                                        short,
                                        unsigned char,
                                        unsigned char,
                                        unsigned char,
                                        unsigned char) */

void __thiscall
dMap_c::setGbaPoint_ocean
          (dMap_c *this,uchar param_1,float param_2,float param_3,short param_4,uchar param_5,
          uchar param_6,uchar param_7,uchar param_8)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  dMap_c *this_00;
  short sVar5;
  undefined2 uVar6;
  undefined in_register_00000012;
  undefined uVar7;
  short sVar8;
  short sVar9;
  double local_30;
  
  uVar1 = (uint)(d_map::_6400 * (d_map::_6401 + d_map::_5603 + param_2));
  uVar2 = (uint)(d_map::_6400 * (d_map::_6401 + d_map::_5603 + param_3));
  this_00 = (dMap_c *)agbScrollX(this);
  sVar9 = (short)uVar1;
  sVar5 = agbScrollY(this_00);
  sVar8 = (short)uVar2;
  if ((((uint)this & 0xff) != 1) && (((uint)this & 0xff) != 3)) {
    if (sVar9 < -8) {
      return;
    }
    if (0x708 < sVar9) {
      return;
    }
    if (sVar8 < -8) {
      return;
    }
    if (0x708 < sVar8) {
      return;
    }
    uVar4 = (int)(short)(sVar9 - (short)this_00) ^ 0x80000000;
    local_30 = (double)CONCAT44(0x43300000,uVar4);
    if ((float)(local_30 - d_map::_4818) < d_map::_6402) {
      return;
    }
    local_30 = (double)CONCAT44(0x43300000,uVar4);
    if (d_map::_6403 < (float)(local_30 - d_map::_4818)) {
      return;
    }
    uVar4 = (int)(short)(sVar8 - sVar5) ^ 0x80000000;
    local_30 = (double)CONCAT44(0x43300000,uVar4);
    if ((float)(local_30 - d_map::_4818) < d_map::_6402) {
      return;
    }
    local_30 = (double)CONCAT44(0x43300000,uVar4);
    if (d_map::_6403 < (float)(local_30 - d_map::_4818)) {
      return;
    }
  }
  uVar7 = (undefined)param_4;
  switch((uint)this & 0xff) {
  case 1:
    dStage_roomControl_c::mMemoryBlock[19]._2_2_ = m_Do_lib::mDoLib_cnvind16(uVar1 & 0xffff);
    dStage_roomControl_c::mMemoryBlock[20]._0_2_ = m_Do_lib::mDoLib_cnvind16(uVar2 & 0xffff);
    mSetCursorFlg = mSetCursorFlg | 1;
    _mAGBPointValueC = _mAGBPointValueC + 1;
    _mAGBPointValueAll = _mAGBPointValueAll + 1;
    dStage_roomControl_c::mMemoryBlock[20]._2_1_ = in_register_00000012;
    dStage_roomControl_c::mMemoryBlock[20]._3_1_ = (char)this;
    dStage_roomControl_c::mMemoryBlock[21]._0_1_ = uVar7;
    dStage_roomControl_c::mMemoryBlock[21]._1_1_ = param_5;
    break;
  case 2:
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
  case 10:
  case 0xb:
  case 0xc:
  case 0xd:
  case 0x10:
  case 0x15:
    if ((((uint)this & 0xff) != 6) || (param_7 != '\x18')) {
      if (((uint)this & 0xff) == 2) {
        getKindMapType((dMap_c *)&d_map::_6406);
      }
      if (((((uint)this & 0xff) != 2) || (param_7 != '\x15')) &&
         ((((uint)this & 0xff) != 2 || (param_7 != '\x16')))) {
        uVar4 = (uint)_mAGBPointValueE;
        if (uVar4 < 0xe) {
          iVar3 = uVar4 * 8;
          uVar6 = m_Do_lib::mDoLib_cnvind16(uVar1 & 0xffff);
          *(undefined2 *)((int)dStage_roomControl_c::mMemoryBlock + iVar3 + 0x5e) = uVar6;
          uVar6 = m_Do_lib::mDoLib_cnvind16(uVar2 & 0xffff);
          *(undefined2 *)(dStage_roomControl_c::mMemoryBlock + uVar4 * 2 + 0x18) = uVar6;
          *(undefined *)((int)dStage_roomControl_c::mMemoryBlock + iVar3 + 0x62) =
               in_register_00000012;
          if (((uint)this & 0xff) == 2) {
            this = (dMap_c *)((uint)this & 0xff | (uint)this & 0x3f | (param_6 & 3) << 6);
          }
          *(char *)((int)dStage_roomControl_c::mMemoryBlock + iVar3 + 99) = (char)this;
          *(undefined *)(dStage_roomControl_c::mMemoryBlock + uVar4 * 2 + 0x19) = uVar7;
          *(uchar *)((int)dStage_roomControl_c::mMemoryBlock + iVar3 + 0x65) = param_5;
          _mAGBPointValueE = _mAGBPointValueE + 1;
        }
        _mAGBPointValueAll = _mAGBPointValueAll + 1;
      }
    }
    break;
  case 3:
    dStage_roomControl_c::mMemoryBlock[21]._2_2_ = m_Do_lib::mDoLib_cnvind16(uVar1 & 0xffff);
    dStage_roomControl_c::mMemoryBlock[22]._0_2_ = m_Do_lib::mDoLib_cnvind16(uVar2 & 0xffff);
    mSetCursorFlg = mSetCursorFlg | 2;
    _mAGBPointValueC = _mAGBPointValueC + 1;
    _mAGBPointValueAll = _mAGBPointValueAll + 1;
    dStage_roomControl_c::mMemoryBlock[22]._2_1_ = in_register_00000012;
    dStage_roomControl_c::mMemoryBlock[22]._3_1_ = (char)this;
    dStage_roomControl_c::mMemoryBlock[23]._0_1_ = uVar7;
    dStage_roomControl_c::mMemoryBlock[23]._1_1_ = param_5;
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dMap_c::isPointStayInDspNowRoomAgbScr(short,
                                                    short) */

undefined4 __thiscall
dMap_c::isPointStayInDspNowRoomAgbScr(dMap_c *this,short param_1,short param_2)

{
  if ((((-9 < (short)this) &&
       ((float)((double)CONCAT44(0x43300000,(int)(short)this ^ 0x80000000) - d_map::_4818) <=
        d_map::_6423 + *(float *)(_mNowRoomInfoP + 0x28))) && (-9 < param_1)) &&
     ((float)((double)CONCAT44(0x43300000,(int)param_1 ^ 0x80000000) - d_map::_4818) <=
      d_map::_6423 + *(float *)(_mNowRoomInfoP + 0x2c))) {
    return 1;
  }
  return 0;
}


namespace dMap_c {

/* WARNING: Inlined function: FUN_80328ea8 */
/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328ef4 */
/* WARNING: Inlined function: FUN_80328f74 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall setCollectPoint(unsigned char,
                                      unsigned char,
                                      float,
                                      float,
                                      float,
                                      signed char,
                                      short,
                                      unsigned char,
                                      unsigned char,
                                      unsigned char,
                                      unsigned char) */

void setCollectPoint
               (byte param_1,byte param_2,float x,float y,float z,byte param_6,short param_7,
               GbaNames gbaName,byte param_9,byte param_10,byte param_11)

{
  byte bVar1;
  uint uVar2;
  bool bVar3;
  undefined3 in_register_0000000c;
  int iVar4;
  ulong uVar5;
  uint uVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  
  dVar9 = (double)z;
  dVar8 = (double)y;
  dVar7 = (double)x;
  if ((mCollectPointDataCnt < 0x40) &&
     ((((iVar4 = getKindMapType((dMap_c *)CONCAT31(in_register_0000000c,param_1)), iVar4 == 1 ||
        (param_1 == 1)) || (param_1 == 3)) ||
      (((char)param_6 == -1 ||
       ((_mNowRoomInfoP != 0 && ((int)(char)param_6 == *(int *)(_mNowRoomInfoP + 0x10))))))))) {
    uVar2 = (uint)param_1;
    bVar3 = false;
    if ((-1 < (int)(uVar2 - 1)) && ((int)(uVar2 - 1) < 0x15)) {
      bVar3 = true;
    }
    if (!bVar3) {
      uVar5 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert
                (uVar5,"d_map.cpp",0x1929,"(typeNo >= 0) && (typeNo < AGB_POINT_TYPE_NUM)");
      m_Do_printf::OSPanic("d_map.cpp",0x1929,&DAT_8034f1dd);
    }
    bVar1 = (&mCollectPointData[0x3f].field_0x17)[uVar2];
    uVar6 = (uint)mCollectPointDataCnt;
    (&mCollectPointData[0x3f].field_0x17)[uVar2] = mCollectPointDataCnt;
    mCollectPointData[uVar6].mPos.x = (float)dVar7;
    mCollectPointData[uVar6].mPos.y = (float)dVar8;
    mCollectPointData[uVar6].mPos.z = (float)dVar9;
    mCollectPointData[uVar6].field_0xc = param_7;
    mCollectPointData[uVar6].mPointType = param_1;
    mCollectPointData[uVar6].field_0x10 = param_2;
    mCollectPointData[uVar6].field_0xe = param_6;
    mCollectPointData[uVar6].mGbaName = gbaName;
    mCollectPointData[uVar6].field_0x12 = param_9;
    mCollectPointData[uVar6].field_0x13 = param_10;
    mCollectPointData[uVar6].field_0x14 = param_11;
    mCollectPointData[uVar6].field_0x16 = bVar1;
    mCollectPointDataCnt = mCollectPointDataCnt + 1;
  }
  return;
}

}

/* WARNING: Inlined function: FUN_80328f24 */
/* WARNING: Inlined function: FUN_80328f70 */
/* WARNING: Removing unreachable block (ram,0x8004b7ec) */
/* WARNING: Removing unreachable block (ram,0x8004b7f4) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dMap_c::setGbaPoint_dungeon(unsigned char,
                                          float,
                                          float,
                                          short,
                                          unsigned char,
                                          unsigned char,
                                          unsigned char,
                                          unsigned char) */

void __thiscall
dMap_c::setGbaPoint_dungeon
          (dMap_c *this,uchar param_1,float param_2,float param_3,short param_4,uchar param_5,
          uchar param_6,uchar param_7,uchar param_8)

{
  bool bVar1;
  dMap_c *pdVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  ulong uVar6;
  dMap_c *pdVar7;
  short sVar8;
  char cVar10;
  undefined2 uVar9;
  undefined in_register_00000012;
  undefined extraout_r4;
  undefined extraout_r4_00;
  undefined uVar11;
  short sVar12;
  undefined uVar13;
  undefined uVar14;
  int iVar15;
  undefined4 uVar16;
  double dVar17;
  double dVar18;
  undefined8 in_f30;
  undefined8 in_f31;
  double local_58;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  pdVar2 = _mNowRoomInfoP;
  dVar18 = (double)param_3;
  dVar17 = (double)param_2;
  uVar16 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  if ((_mNowRoomInfoP == (dMap_c *)0x0) || (_mNowRoomInfoP[1] == (dMap_c)0x0)) goto LAB_8004b7ec;
  sVar12 = param_4;
  if (*(int *)(_mNowRoomInfoP + 0xe8) == 0) {
    uVar6 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar6,"d_map.h",0x467,"mStageMapInfoP != 0");
    sVar12 = -0xe23;
    m_Do_printf::OSPanic("d_map.h",0x467);
  }
  iVar15 = *(int *)(pdVar2 + 0xe8);
  if (iVar15 == 0) {
    uVar6 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar6,"d_map.cpp",0x2cf,"i_mapInfoP != 0");
    sVar12 = -0xe23;
    m_Do_printf::OSPanic("d_map.cpp",0x2cf);
  }
  pdVar7 = _mNowRoomInfoP;
  pdVar2 = (dMap_c *)
           (int)((float)(dVar17 - (double)*(float *)(iVar15 + 0x18)) *
                *(float *)(_mNowRoomInfoP + 0x20));
  if (*(int *)(_mNowRoomInfoP + 0xe8) == 0) {
    uVar6 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar6,"d_map.h",0x467,"mStageMapInfoP != 0");
    sVar12 = -0xe23;
    m_Do_printf::OSPanic("d_map.h",0x467);
  }
  iVar15 = *(int *)(pdVar7 + 0xe8);
  if (iVar15 == 0) {
    uVar6 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar6,"d_map.cpp",0x2d5,"i_mapInfoP != 0");
    sVar12 = -0xe23;
    m_Do_printf::OSPanic("d_map.cpp",0x2d5);
  }
  uVar3 = (uint)((float)(dVar18 - (double)*(float *)(iVar15 + 0x1c)) *
                *(float *)(_mNowRoomInfoP + 0x24));
  pdVar7 = (dMap_c *)agbScrollX(_mNowRoomInfoP);
  sVar8 = agbScrollY(pdVar7);
  bVar1 = ((uint)this & 0xff) == 1;
  uVar11 = extraout_r4;
  if ((!bVar1) &&
     ((bVar1 || (cVar10 = isPointStayInDspNowRoomAgbScr(pdVar2,(short)uVar3,sVar12),
                uVar11 = extraout_r4_00, cVar10 == '\0')))) goto LAB_8004b7ec;
  if ((((uint)this & 0xff) != 1) && (((uint)this & 0xff) != 3)) {
    uVar4 = (int)(short)((short)pdVar2 - (short)pdVar7) ^ 0x80000000;
    local_58 = (double)CONCAT44(0x43300000,uVar4);
    if (((float)(local_58 - d_map::_4818) < d_map::_6402) ||
       (local_58 = (double)CONCAT44(0x43300000,uVar4),
       d_map::_6403 < (float)(local_58 - d_map::_4818))) goto LAB_8004b7ec;
    uVar4 = (int)(short)((short)uVar3 - sVar8) ^ 0x80000000;
    local_58 = (double)CONCAT44(0x43300000,uVar4);
    if (((float)(local_58 - d_map::_4818) < d_map::_6402) ||
       (local_58 = (double)CONCAT44(0x43300000,uVar4),
       d_map::_6403 < (float)(local_58 - d_map::_4818))) goto LAB_8004b7ec;
  }
  uVar4 = (uint)this & 0xff;
  uVar13 = SUB41(this,0);
  uVar14 = (undefined)param_4;
  if (uVar4 == 3) {
    dStage_roomControl_c::mMemoryBlock[21]._2_2_ = m_Do_lib::mDoLib_cnvind16((uint)pdVar2 & 0xffff);
    dStage_roomControl_c::mMemoryBlock[22]._0_2_ = m_Do_lib::mDoLib_cnvind16(uVar3 & 0xffff);
    mSetCursorFlg = mSetCursorFlg | 2;
    _mAGBPointValueC = _mAGBPointValueC + 1;
    _mAGBPointValueAll = _mAGBPointValueAll + 1;
    dStage_roomControl_c::mMemoryBlock[22]._2_1_ = in_register_00000012;
    dStage_roomControl_c::mMemoryBlock[22]._3_1_ = uVar13;
    dStage_roomControl_c::mMemoryBlock[23]._0_1_ = uVar14;
    dStage_roomControl_c::mMemoryBlock[23]._1_1_ = param_5;
    goto LAB_8004b7ec;
  }
  if (uVar4 < 3) {
    if (uVar4 == 1) {
      dStage_roomControl_c::mMemoryBlock[19]._2_2_ =
           m_Do_lib::mDoLib_cnvind16((uint)pdVar2 & 0xffff);
      dStage_roomControl_c::mMemoryBlock[20]._0_2_ = m_Do_lib::mDoLib_cnvind16(uVar3 & 0xffff);
      _mAGBPointValueC = _mAGBPointValueC + 1;
      _mAGBPointValueAll = _mAGBPointValueAll + 1;
      mSetCursorFlg = mSetCursorFlg | 1;
      dStage_roomControl_c::mMemoryBlock[20]._2_1_ = in_register_00000012;
      dStage_roomControl_c::mMemoryBlock[20]._3_1_ = uVar13;
      dStage_roomControl_c::mMemoryBlock[21]._0_1_ = uVar14;
      dStage_roomControl_c::mMemoryBlock[21]._1_1_ = param_5;
      goto LAB_8004b7ec;
    }
    if (uVar4 != 0) goto LAB_8004b6b4;
  }
  else {
    if ((uVar4 != 0x12) && ((uVar4 < 0x12 || (uVar4 < 0x16)))) {
LAB_8004b6b4:
      cVar10 = getPosAgbMapType((dMap_c *)&DAT_00000001,(float)dVar17,(float)dVar18,(bool)uVar11);
      if (((cVar10 != '\x03') ||
          ((((((uint)this & 0xff) != 0xe && (((uint)this & 0xff) != 0xf)) ||
            (*(int *)(_mNowRoomInfoP + 0x10) != 0xb)) && (param_7 != '\x05')))) &&
         (((((uint)this & 0xff) != 2 || (param_7 != '\x15')) &&
          ((((uint)this & 0xff) != 2 || (param_7 != '\x16')))))) {
        uVar5 = (uint)_mAGBPointValueE;
        if (uVar5 < 0xe) {
          iVar15 = uVar5 * 8;
          uVar9 = m_Do_lib::mDoLib_cnvind16((uint)pdVar2 & 0xffff);
          *(undefined2 *)((int)dStage_roomControl_c::mMemoryBlock + iVar15 + 0x5e) = uVar9;
          uVar9 = m_Do_lib::mDoLib_cnvind16(uVar3 & 0xffff);
          *(undefined2 *)(dStage_roomControl_c::mMemoryBlock + uVar5 * 2 + 0x18) = uVar9;
          *(undefined *)((int)dStage_roomControl_c::mMemoryBlock + iVar15 + 0x62) =
               in_register_00000012;
          *(undefined *)((int)dStage_roomControl_c::mMemoryBlock + iVar15 + 99) = uVar13;
          if (((uint)this & 0xff) == 2) {
            *(byte *)((int)dStage_roomControl_c::mMemoryBlock + iVar15 + 99) =
                 *(byte *)((int)dStage_roomControl_c::mMemoryBlock + iVar15 + 99) |
                 (byte)uVar4 & 0x3f | param_6 << 6;
          }
          *(undefined *)(dStage_roomControl_c::mMemoryBlock + uVar5 * 2 + 0x19) = uVar14;
          *(uchar *)((int)dStage_roomControl_c::mMemoryBlock + iVar15 + 0x65) = param_5;
          _mAGBPointValueE = _mAGBPointValueE + 1;
        }
        _mAGBPointValueAll = _mAGBPointValueAll + 1;
      }
      goto LAB_8004b7ec;
    }
  }
  uVar6 = JUTAssertion::getSDevice();
  JUTAssertion::showAssert(uVar6,"d_map.cpp",0x1a05,"0");
  m_Do_printf::OSPanic("d_map.cpp",0x1a05,&DAT_8034f1dd);
LAB_8004b7ec:
  __psq_l0(auStack8,uVar16);
  __psq_l1(auStack8,uVar16);
  __psq_l0(auStack24,uVar16);
  __psq_l1(auStack24,uVar16);
  return;
}


/* __thiscall dMap_c::getPosAgbMapType(float,
                                       float,
                                       bool) */

undefined4 __thiscall
dMap_c::getPosAgbMapType(dMap_c *this,float param_1,float param_2,bool param_3)

{
  dMap_c *this_00;
  char cVar3;
  undefined4 uVar1;
  int iVar2;
  bool extraout_r4;
  double dVar4;
  double dVar5;
  
  dVar5 = (double)param_2;
  dVar4 = (double)param_1;
  this_00 = (dMap_c *)getKindMapType(this);
  if (this_00 == (dMap_c *)&DAT_00000001) {
    cVar3 = isInDspArea(this,(float)dVar4,(float)dVar5,extraout_r4);
    if (cVar3 == '\0') {
      uVar1 = 2;
    }
    else {
      uVar1 = 3;
    }
  }
  else {
    iVar2 = getKindMapType(this_00);
    if (iVar2 == 2) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}


/* __thiscall dMap_c::setGbaPoint(unsigned char,
                                  float,
                                  float,
                                  short,
                                  unsigned char,
                                  unsigned char,
                                  unsigned char,
                                  unsigned char) */

void __thiscall
dMap_c::setGbaPoint(dMap_c *this,uchar param_1,float param_2,float param_3,short param_4,
                   uchar param_5,uchar param_6,uchar param_7,uchar param_8)

{
  if (mPlayerStayAgbMapTypeNow != '\0') {
    if (mPlayerStayAgbMapTypeNow == '\x02') {
      setGbaPoint_ocean(this,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
    }
    else {
      setGbaPoint_dungeon(this,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
    }
  }
  return;
}


/* __thiscall dMap_c::setArriveInfo(float,
                                    float) */

void __thiscall dMap_c::setArriveInfo(dMap_c *this,float param_1,float param_2)

{
  int iVar1;
  dMap_c *this_00;
  short *in_r7;
  double dVar2;
  double dVar3;
  char local_18;
  dMap_c local_17;
  short sStack22;
  char acStack20 [20];
  
  dVar3 = (double)param_2;
  dVar2 = (double)param_1;
  if ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode == 0) &&
     (iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                        (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"sea"),
     iVar1 == 0)) {
    point2GridAndLocal(&local_17,(float)dVar2,(float)dVar3,&local_18,acStack20,&sStack22,in_r7);
    if ((mPlGridX != local_17) || (mPlGridY != local_18)) {
      mPlGridX = local_17;
      mPlGridY = local_18;
      this_00 = (dMap_c *)(int)(char)local_17;
      if ((((-4 < (int)this_00) && ((int)this_00 < 4)) && (-4 < local_18)) && (local_18 < '\x04')) {
        this_00 = (dMap_c *)d_map::onSaveArriveGridForAgbUseGridPos();
      }
      agbMapNoSetCall(this_00);
    }
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dMap_c::drawPointPlayer(float,
                                      float,
                                      short) */

void __thiscall dMap_c::drawPointPlayer(dMap_c *this,float param_1,float param_2,short param_3)

{
  dMap_2DTri_c::setPos((dMap_2DTri_c *)&mCursor,(short)(int)param_1,(short)(int)param_2);
  DAT_803c398f = mAlpha;
  DAT_803c3990 = (short)this;
  DAT_803c3994 = d_map::_6629;
  DAT_803c3998 = d_map::_6630;
  DAT_803c399c = _mScissorOrigX;
  DAT_803c39a0 = _mScissorOrigY;
  DAT_803c39a4 = _mScissorWidth;
  DAT_803c39a8 = _mScissorHeight;
  mDrawPointCntPlayer = mDrawPointCntPlayer + '\x01';
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dMap_c::drawPointTbox(float,
                                    float,
                                    float,
                                    float) */

dMap_c * __thiscall
dMap_c::drawPointTbox(dMap_c *this,float param_1,float param_2,float param_3,float param_4)

{
  undefined uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  float fVar5;
  int iVar6;
  undefined uStack13;
  
  uVar1 = mAlpha;
  if (mTboxNum < 8) {
    iVar6 = (uint)mTboxNum * 0x5c;
    this = (dMap_c *)(&mTbox + iVar6);
    *(float *)(&DAT_803c3c4c + iVar6) = param_1;
    *(float *)(&DAT_803c3c50 + iVar6) = param_2;
    (&DAT_803c3c64)[iVar6] = 0xff;
    (&DAT_803c3c65)[iVar6] = 0xff;
    (&DAT_803c3c66)[iVar6] = 0;
    (&DAT_803c3c67)[iVar6] = uVar1;
    (&DAT_803c3c68)[iVar6] = 0;
    (&DAT_803c3c69)[iVar6] = 0;
    (&DAT_803c3c6a)[iVar6] = 0;
    (&DAT_803c3c6b)[iVar6] = uStack13;
    fVar5 = d_map::_6423;
    *(float *)(&DAT_803c3c54 + iVar6) = d_map::_6423 * param_3;
    *(float *)(&DAT_803c3c58 + iVar6) = fVar5 * param_4;
    fVar5 = d_map::_4611;
    *(float *)(&DAT_803c3c5c + iVar6) = d_map::_4611;
    *(float *)(&DAT_803c3c60 + iVar6) = fVar5;
    uVar4 = _mScissorHeight;
    uVar3 = _mScissorWidth;
    uVar2 = _mScissorOrigY;
    *(undefined4 *)(&DAT_803c3c6c + iVar6) = _mScissorOrigX;
    *(undefined4 *)(&DAT_803c3c70 + iVar6) = uVar2;
    *(undefined4 *)(&DAT_803c3c74 + iVar6) = uVar3;
    *(undefined4 *)(&DAT_803c3c78 + iVar6) = uVar4;
    mTboxNum = mTboxNum + 1;
  }
  return this;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dMap_c::drawPointDoor(float,
                                    float,
                                    float,
                                    float,
                                    short,
                                    unsigned char) */

void __thiscall
dMap_c::drawPointDoor
          (dMap_c *this,float param_1,float param_2,float param_3,float param_4,short param_5,
          uchar param_6)

{
  undefined uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  float fVar5;
  int iVar6;
  
  if (mDoorNum < 0x10) {
    uVar1 = (undefined)d_map::_6712;
    iVar6 = (uint)mDoorNum * 0x5c;
    *(float *)(&DAT_803c3f38 + iVar6) = param_1;
    *(float *)(&DAT_803c3f3c + iVar6) = param_2;
    (&DAT_803c3f50)[iVar6] = 0xa8;
    (&DAT_803c3f51)[iVar6] = 0xa8;
    (&DAT_803c3f52)[iVar6] = 0xa8;
    (&DAT_803c3f53)[iVar6] = (char)param_5;
    (&DAT_803c3f54)[iVar6] = 0;
    (&DAT_803c3f55)[iVar6] = 0;
    (&DAT_803c3f56)[iVar6] = 0;
    (&DAT_803c3f57)[iVar6] = uVar1;
    fVar5 = d_map::_6423;
    *(float *)(&DAT_803c3f40 + iVar6) = d_map::_6423 * param_3;
    *(float *)(&DAT_803c3f44 + iVar6) = fVar5 * param_4;
    *(short *)(&DAT_803c3f68 + iVar6) = -(short)this;
    uVar4 = _mScissorHeight;
    uVar3 = _mScissorWidth;
    uVar2 = _mScissorOrigY;
    *(undefined4 *)(&DAT_803c3f58 + iVar6) = _mScissorOrigX;
    *(undefined4 *)(&DAT_803c3f5c + iVar6) = uVar2;
    *(undefined4 *)(&DAT_803c3f60 + iVar6) = uVar3;
    *(undefined4 *)(&DAT_803c3f64 + iVar6) = uVar4;
    mDoorNum = mDoorNum + 1;
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dMap_c::drawPointShip(float,
                                    float,
                                    short,
                                    float,
                                    float) */

void __thiscall
dMap_c::drawPointShip
          (dMap_c *this,float param_1,float param_2,short param_3,float param_4,float param_5)

{
  DAT_803c45a4 = param_1;
  DAT_803c45a8 = param_2;
  DAT_803c45ac = d_map::_6423 * param_4;
  DAT_803c45b0 = d_map::_5372 * param_5;
  DAT_803c45b4 = d_map::_4611;
  DAT_803c45b8 = d_map::_4611;
  DAT_803c45bc = 0xff;
  DAT_803c45bd = 0x46;
  DAT_803c45be = 0;
  DAT_803c45bf = mAlpha;
  DAT_803c45c0 = 0;
  DAT_803c45c1 = 0;
  DAT_803c45c2 = 0;
  DAT_803c45c3 = (char)d_map::_6775;
  DAT_803c45c4 = _mScissorOrigX;
  DAT_803c45c8 = _mScissorOrigY;
  DAT_803c45cc = _mScissorWidth;
  DAT_803c45d0 = _mScissorHeight;
  DAT_803c45d4 = -(short)this;
  mDrawPointCntShip = mDrawPointCntShip + '\x01';
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x8004cc54) */
/* WARNING: Removing unreachable block (ram,0x8004cc5c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dMap_c::drawPointGc(unsigned char,
                                  float,
                                  float,
                                  float,
                                  signed char,
                                  short,
                                  unsigned char,
                                  unsigned char,
                                  unsigned char,
                                  unsigned char) */

void __thiscall
dMap_c::drawPointGc(dMap_c *this,uchar param_1,float param_2,float param_3,float param_4,
                   char param_5,short param_6,uchar param_7,uchar param_8,uchar param_9,
                   uchar param_10)

{
  uint uVar1;
  char cVar5;
  char cVar6;
  dMap_c *pdVar2;
  int iVar3;
  dMap_c *pdVar4;
  short extraout_r4;
  short extraout_r4_00;
  short extraout_r4_01;
  short extraout_r4_02;
  undefined3 in_register_00000014;
  uchar uVar7;
  short sVar8;
  short sVar9;
  undefined4 uVar10;
  double dVar11;
  double dVar12;
  undefined8 in_f30;
  undefined8 in_f31;
  double local_48;
  double local_40;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  pdVar4 = (dMap_c *)CONCAT31(in_register_00000014,param_5);
  dVar12 = (double)param_4;
  dVar11 = (double)param_2;
  uVar10 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  if ((((((uint)this & 0xff) != 0) && (_mNowRoomInfoP != 0)) &&
      (*(char *)(_mNowRoomInfoP + 1) != '\0')) &&
     (((char)param_1 == -1 || ((int)(char)param_1 == *(int *)(_mNowRoomInfoP + 0x10))))) {
    pdVar2 = pdVar4;
    cVar5 = d_map::dMap_GetFloorNo_WithRoom((double)param_3,(int)(char)param_1);
    uVar7 = (uchar)pdVar2;
    if ((((((uint)this & 0xff) == 1) || (((uint)this & 0xff) == 2)) ||
        (((cVar6 = d_map::IsFloorNo(cVar5), cVar6 != '\0' &&
          (cVar6 = d_map::IsFloorNo(mNowFloorNo), cVar6 != '\0')) && (mNowFloorNo == cVar5)))) &&
       (((((mMapDispMode != '\x01' || (uVar1 = (uint)this & 0xff, uVar1 == 1)) || (uVar1 == 2)) ||
         ((uVar1 == 6 || (uVar1 == 7)))) || ((uVar1 == 9 || ((uVar1 == 5 || (uVar1 == 8)))))))) {
      uVar1 = 4;
      if (((uint)this & 0xff) == 2) {
        uVar1 = 0x10;
      }
      uVar1 = uVar1 >> 1;
      sVar9 = (short)(int)(_mNowScaleX * (float)(dVar11 - (double)_mNowCenterX));
      if ((-0x79 < (int)((int)sVar9 + uVar1)) && ((int)((int)sVar9 - uVar1) < 0x79)) {
        sVar8 = (short)(int)(_mNowScaleZ * (float)(dVar12 - (double)_mNowCenterZ));
        if ((-0x79 < (int)((int)sVar8 + uVar1)) && ((int)((int)sVar8 - uVar1) < 0x79)) {
          sVar9 = sVar9 + _mDispPosLeftUpX + 0x3c;
          sVar8 = sVar8 + _mDispPosLeftUpY + 0x3c;
          switch((uint)this & 0xff) {
          case 1:
            local_40 = (double)CONCAT44(0x43300000,(int)sVar9 ^ 0x80000000);
            local_48 = (double)CONCAT44(0x43300000,(int)sVar8 ^ 0x80000000);
            drawPointPlayer(pdVar4,(float)(local_40 - d_map::_4818),(float)(local_48 - d_map::_4818)
                            ,(short)uVar1);
            break;
          case 2:
            if ((param_6 & 0xffU) == 0) {
              local_40 = (double)CONCAT44(0x43300000,(int)sVar9 ^ 0x80000000);
              local_48 = (double)CONCAT44(0x43300000,(int)sVar8 ^ 0x80000000);
              drawPointAgbCursor((dMap_c *)0x43300000,(float)(local_40 - d_map::_4818),
                                 (float)(local_48 - d_map::_4818));
            }
            break;
          case 3:
            iVar3 = getKindMapType((dMap_c *)&d_map::_6955);
            if ((iVar3 == 2) &&
               (iVar3 = dSv_memBit_c::isDungeonItem
                                  ((dSv_memBit_c *)
                                   &d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMemory,1),
               iVar3 != 0)) {
              local_40 = (double)CONCAT44(0x43300000,(int)sVar9 ^ 0x80000000);
              local_48 = (double)CONCAT44(0x43300000,(int)sVar8 ^ 0x80000000);
              drawPointEnemy((dMap_c *)0x43300000,(float)(local_40 - d_map::_4818),
                             (float)(local_48 - d_map::_4818));
            }
            break;
          case 4:
            pdVar4 = (dMap_c *)getKindMapType((dMap_c *)&d_map::_6955);
            if (pdVar4 == (dMap_c *)&DAT_00000001) {
              if (param_9 == '\x18') {
                local_40 = (double)CONCAT44(0x43300000,(int)sVar9 ^ 0x80000000);
                local_48 = (double)CONCAT44(0x43300000,(int)sVar8 ^ 0x80000000);
                drawPointEnemy((dMap_c *)0x43300000,(float)(local_40 - d_map::_4818),
                               (float)(local_48 - d_map::_4818));
              }
            }
            else {
              iVar3 = getKindMapType(pdVar4);
              if (iVar3 == 2) {
                if (param_9 == '\x17') {
                  iVar3 = dSv_memBit_c::isDungeonItem
                                    ((dSv_memBit_c *)
                                     &d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMemory,1);
                  if (iVar3 != 0) {
                    local_40 = (double)CONCAT44(0x43300000,(int)sVar9 ^ 0x80000000);
                    local_48 = (double)CONCAT44(0x43300000,(int)sVar8 ^ 0x80000000);
                    drawPointEnemy((dMap_c *)0x43300000,(float)(local_40 - d_map::_4818),
                                   (float)(local_48 - d_map::_4818));
                  }
                }
                else {
                  local_40 = (double)CONCAT44(0x43300000,(int)sVar9 ^ 0x80000000);
                  local_48 = (double)CONCAT44(0x43300000,(int)sVar8 ^ 0x80000000);
                  drawPointEnemy((dMap_c *)0x43300000,(float)(local_40 - d_map::_4818),
                                 (float)(local_48 - d_map::_4818));
                }
              }
            }
            break;
          case 5:
            pdVar2 = (dMap_c *)getKindMapType((dMap_c *)&d_map::_6955);
            if (pdVar2 == (dMap_c *)&DAT_00000002) {
              if (mMapDispMode == '\0') {
                local_40 = (double)CONCAT44(0x43300000,(int)sVar9 ^ 0x80000000);
                local_48 = (double)CONCAT44(0x43300000,(int)sVar8 ^ 0x80000000);
                drawPointShip(pdVar4,(float)(local_40 - d_map::_4818),
                              (float)(local_48 - d_map::_4818),extraout_r4,d_map::_6943,d_map::_6944
                             );
              }
              else {
                local_40 = (double)CONCAT44(0x43300000,(int)sVar9 ^ 0x80000000);
                local_48 = (double)CONCAT44(0x43300000,(int)sVar8 ^ 0x80000000);
                drawPointShip(pdVar4,(float)(local_40 - d_map::_4818),
                              (float)(local_48 - d_map::_4818),extraout_r4,d_map::_4611,d_map::_4611
                             );
              }
            }
            else {
              iVar3 = getKindMapType(pdVar2);
              if (iVar3 == 1) {
                if (mMapDispMode == '\0') {
                  local_40 = (double)CONCAT44(0x43300000,(int)sVar9 ^ 0x80000000);
                  local_48 = (double)CONCAT44(0x43300000,(int)sVar8 ^ 0x80000000);
                  drawPointShip(pdVar4,(float)(local_40 - d_map::_4818),
                                (float)(local_48 - d_map::_4818),extraout_r4_00,d_map::_6943,
                                d_map::_6944);
                }
                else {
                  local_40 = (double)CONCAT44(0x43300000,(int)sVar9 ^ 0x80000000);
                  local_48 = (double)CONCAT44(0x43300000,(int)sVar8 ^ 0x80000000);
                  drawPointShip(pdVar4,(float)(local_40 - d_map::_4818),
                                (float)(local_48 - d_map::_4818),extraout_r4_00,d_map::_4611,
                                d_map::_4611);
                }
              }
            }
            break;
          case 6:
            if (((param_6 & 0xffU) != 0xf) && ((param_6 & 0xffU) != 0x10)) {
              pdVar4 = (dMap_c *)getKindMapType((dMap_c *)&d_map::_6955);
              if (pdVar4 == (dMap_c *)&DAT_00000002) {
                iVar3 = dSv_memBit_c::isDungeonItem
                                  ((dSv_memBit_c *)
                                   &d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMemory,1);
                if (iVar3 != 0) {
                  if (mMapDispMode == '\0') {
                    local_40 = (double)CONCAT44(0x43300000,(int)sVar9 ^ 0x80000000);
                    local_48 = (double)CONCAT44(0x43300000,(int)sVar8 ^ 0x80000000);
                    drawPointTbox((dMap_c *)0x43300000,(float)(local_40 - d_map::_4818),
                                  (float)(local_48 - d_map::_4818),d_map::_6945,d_map::_6067);
                  }
                  else {
                    local_40 = (double)CONCAT44(0x43300000,(int)sVar9 ^ 0x80000000);
                    local_48 = (double)CONCAT44(0x43300000,(int)sVar8 ^ 0x80000000);
                    drawPointTbox((dMap_c *)0x43300000,(float)(local_40 - d_map::_4818),
                                  (float)(local_48 - d_map::_4818),d_map::_6067,d_map::_6946);
                  }
                }
              }
              else {
                iVar3 = getKindMapType(pdVar4);
                if ((iVar3 == 1) && (mMapDispMode == '\0')) {
                  local_40 = (double)CONCAT44(0x43300000,(int)sVar9 ^ 0x80000000);
                  local_48 = (double)CONCAT44(0x43300000,(int)sVar8 ^ 0x80000000);
                  drawPointTbox((dMap_c *)0x43300000,(float)(local_40 - d_map::_4818),
                                (float)(local_48 - d_map::_4818),d_map::_6945,d_map::_6067);
                }
              }
            }
            break;
          case 7:
            pdVar2 = (dMap_c *)getKindMapType((dMap_c *)&d_map::_6955);
            if (pdVar2 == (dMap_c *)&DAT_00000002) {
              if (mMapDispMode == '\0') {
                local_40 = (double)CONCAT44(0x43300000,(int)sVar9 ^ 0x80000000);
                local_48 = (double)CONCAT44(0x43300000,(int)sVar8 ^ 0x80000000);
                drawPointDoor(pdVar4,(float)(local_40 - d_map::_4818),
                              (float)(local_48 - d_map::_4818),d_map::_6767,d_map::_6946,
                              (ushort)mCompAlpha,uVar7);
              }
              else {
                local_40 = (double)CONCAT44(0x43300000,(int)sVar9 ^ 0x80000000);
                local_48 = (double)CONCAT44(0x43300000,(int)sVar8 ^ 0x80000000);
                drawPointDoor(pdVar4,(float)(local_40 - d_map::_4818),
                              (float)(local_48 - d_map::_4818),d_map::_6947,d_map::_6948,
                              (ushort)mAlpha,uVar7);
              }
            }
            else {
              iVar3 = getKindMapType(pdVar2);
              if (iVar3 == 1) {
                if (*(int *)(_mNowRoomInfoP + 0x10) == 1) {
                  if (mMapDispMode == '\0') {
                    local_40 = (double)CONCAT44(0x43300000,(int)sVar9 ^ 0x80000000);
                    local_48 = (double)CONCAT44(0x43300000,(int)sVar8 ^ 0x80000000);
                    drawPointDoor(pdVar4,(float)(local_40 - d_map::_4818),
                                  (float)(local_48 - d_map::_4818),d_map::_6767,d_map::_6946,
                                  (ushort)mCompAlpha,uVar7);
                  }
                  else {
                    local_40 = (double)CONCAT44(0x43300000,(int)sVar9 ^ 0x80000000);
                    local_48 = (double)CONCAT44(0x43300000,(int)sVar8 ^ 0x80000000);
                    drawPointDoor(pdVar4,(float)(local_40 - d_map::_4818),
                                  (float)(local_48 - d_map::_4818),d_map::_6947,d_map::_6948,
                                  (ushort)mAlpha,uVar7);
                  }
                }
                else {
                  if (mMapDispMode == '\0') {
                    local_40 = (double)CONCAT44(0x43300000,(int)sVar9 ^ 0x80000000);
                    local_48 = (double)CONCAT44(0x43300000,(int)sVar8 ^ 0x80000000);
                    drawPointDoor(pdVar4,(float)(local_40 - d_map::_4818),
                                  (float)(local_48 - d_map::_4818),d_map::_6945,d_map::_4611,
                                  (ushort)mAlpha,uVar7);
                  }
                }
              }
            }
            break;
          case 8:
            pdVar4 = (dMap_c *)getKindMapType((dMap_c *)&d_map::_6955);
            if (pdVar4 == (dMap_c *)&DAT_00000002) {
              iVar3 = dSv_memBit_c::isDungeonItem
                                ((dSv_memBit_c *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMemory
                                 ,1);
              if (iVar3 != 0) {
                if (mMapDispMode == '\0') {
                  local_40 = (double)CONCAT44(0x43300000,(int)sVar9 ^ 0x80000000);
                  local_48 = (double)CONCAT44(0x43300000,(int)sVar8 ^ 0x80000000);
                  drawPointFriend((dMap_c *)0x43300000,(float)(local_40 - d_map::_4818),
                                  (float)(local_48 - d_map::_4818),d_map::_6067);
                }
                else {
                  local_40 = (double)CONCAT44(0x43300000,(int)sVar9 ^ 0x80000000);
                  local_48 = (double)CONCAT44(0x43300000,(int)sVar8 ^ 0x80000000);
                  drawPointFriend((dMap_c *)0x43300000,(float)(local_40 - d_map::_4818),
                                  (float)(local_48 - d_map::_4818),d_map::_6951);
                }
              }
            }
            else {
              iVar3 = getKindMapType(pdVar4);
              if (iVar3 == 1) {
                if (mMapDispMode == '\0') {
                  local_40 = (double)CONCAT44(0x43300000,(int)sVar9 ^ 0x80000000);
                  local_48 = (double)CONCAT44(0x43300000,(int)sVar8 ^ 0x80000000);
                  drawPointFriend((dMap_c *)0x43300000,(float)(local_40 - d_map::_4818),
                                  (float)(local_48 - d_map::_4818),d_map::_6952);
                }
                else {
                  local_40 = (double)CONCAT44(0x43300000,(int)sVar9 ^ 0x80000000);
                  local_48 = (double)CONCAT44(0x43300000,(int)sVar8 ^ 0x80000000);
                  drawPointFriend((dMap_c *)0x43300000,(float)(local_40 - d_map::_4818),
                                  (float)(local_48 - d_map::_4818),d_map::_6067);
                }
              }
            }
            break;
          case 9:
            pdVar2 = (dMap_c *)getKindMapType((dMap_c *)&d_map::_6955);
            if (pdVar2 == (dMap_c *)&DAT_00000002) {
              if (mMapDispMode == '\0') {
                local_40 = (double)CONCAT44(0x43300000,(int)sVar9 ^ 0x80000000);
                local_48 = (double)CONCAT44(0x43300000,(int)sVar8 ^ 0x80000000);
                drawPointRestart(pdVar4,(float)(local_40 - d_map::_4818),
                                 (float)(local_48 - d_map::_4818),extraout_r4_01,d_map::_4611,
                                 d_map::_6949);
              }
              else {
                local_40 = (double)CONCAT44(0x43300000,(int)sVar9 ^ 0x80000000);
                local_48 = (double)CONCAT44(0x43300000,(int)sVar8 ^ 0x80000000);
                drawPointRestart(pdVar4,(float)(local_40 - d_map::_4818),
                                 (float)(local_48 - d_map::_4818),extraout_r4_01,d_map::_4611,
                                 d_map::_6949);
              }
            }
            else {
              iVar3 = getKindMapType(pdVar2);
              if (iVar3 == 1) {
                if (mMapDispMode == '\0') {
                  local_40 = (double)CONCAT44(0x43300000,(int)sVar9 ^ 0x80000000);
                  local_48 = (double)CONCAT44(0x43300000,(int)sVar8 ^ 0x80000000);
                  drawPointRestart(pdVar4,(float)(local_40 - d_map::_4818),
                                   (float)(local_48 - d_map::_4818),extraout_r4_02,d_map::_4611,
                                   d_map::_6949);
                }
                else {
                  local_40 = (double)CONCAT44(0x43300000,(int)sVar9 ^ 0x80000000);
                  local_48 = (double)CONCAT44(0x43300000,(int)sVar8 ^ 0x80000000);
                  drawPointRestart(pdVar4,(float)(local_40 - d_map::_4818),
                                   (float)(local_48 - d_map::_4818),extraout_r4_02,d_map::_6950,
                                   d_map::_4611);
                }
              }
            }
          }
        }
      }
    }
  }
  __psq_l0(auStack8,uVar10);
  __psq_l1(auStack8,uVar10);
  __psq_l0(auStack24,uVar10);
  __psq_l1(auStack24,uVar10);
  return;
}


/* WARNING: Inlined function: FUN_80328ea8 */
/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328ef4 */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall dMap_c::drawPointMain(unsigned char,
                                    unsigned char,
                                    float,
                                    float,
                                    float,
                                    signed char,
                                    short,
                                    unsigned char,
                                    unsigned char,
                                    unsigned char,
                                    unsigned char) */

void __thiscall
dMap_c::drawPointMain
          (dMap_c *this,uchar param_1,uchar param_2,float param_3,float param_4,float param_5,
          char param_6,short param_7,uchar param_8,uchar param_9,uchar param_10,uchar param_11)

{
  int iVar1;
  undefined3 in_register_00000010;
  uchar uVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  
  dVar5 = (double)param_5;
  dVar4 = (double)param_4;
  dVar3 = (double)param_3;
  uVar2 = param_10;
  iVar1 = mDoGaC_agbCom_c::mDoGaC_GbaLink
                    ((mDoGaC_agbCom_c *)&m_Do_ext::m_Do_gba_com::g_mDoGaC_gbaCom);
  if ((iVar1 != 0) &&
     (iVar1 = mDoGaC_agbCom_c::mDoGaC_SendStatusCheck
                        ((mDoGaC_agbCom_c *)&m_Do_ext::m_Do_gba_com::g_mDoGaC_gbaCom,'\x03'),
     iVar1 != 0)) {
    drawPointAgb(this,param_2,(float)dVar3,(float)dVar4,(float)dVar5,param_6,param_7,param_8,param_9
                 ,param_10,uVar2);
  }
  drawPointGc((dMap_c *)CONCAT31(in_register_00000010,param_1),param_2,(float)dVar3,(float)dVar4,
              (float)dVar5,param_6,param_7,param_8,param_9,param_10,uVar2);
  return;
}


/* WARNING: Inlined function: FUN_80328ea8 */
/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328ef4 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dMap_c::drawPointAgb(unsigned char,
                                   float,
                                   float,
                                   float,
                                   signed char,
                                   short,
                                   unsigned char,
                                   unsigned char,
                                   unsigned char,
                                   unsigned char) */

void __thiscall
dMap_c::drawPointAgb
          (dMap_c *this,uchar param_1,float param_2,float param_3,float param_4,char param_5,
          short param_6,uchar param_7,uchar param_8,uchar param_9,uchar param_10)

{
  bool bVar1;
  dMap_c *this_00;
  int iVar2;
  char cVar3;
  char cVar4;
  uchar uVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  
  dVar8 = (double)param_4;
  dVar7 = (double)param_3;
  dVar6 = (double)param_2;
  this_00 = (dMap_c *)(uint)_mAGBPointValueRoomAll;
  _mAGBPointValueRoomAll = _mAGBPointValueRoomAll + 1;
  uVar5 = param_9;
  iVar2 = getKindMapType(this_00);
  if (iVar2 == 1) {
    setGbaPoint(this,param_5,(float)dVar6,(float)dVar8,param_6,param_7,param_8,param_9,uVar5);
  }
  else {
    if (((_mNowRoomInfoP != 0) && (*(char *)(_mNowRoomInfoP + 1) != '\0')) &&
       ((((uint)this & 0xff) == 1 ||
        (((((uint)this & 0xff) == 3 || ((char)param_1 == -1)) ||
         ((int)(char)param_1 == *(int *)(_mNowRoomInfoP + 0x10))))))) {
      cVar3 = d_map::dMap_GetFloorNo_WithRoom(dVar7,(int)(char)param_1);
      bVar1 = false;
      if ((6 < ((uint)this & 0xff)) && (((uint)this & 0xff) < 0xc)) {
        bVar1 = true;
      }
      if (((bVar1) || (((uint)this & 0xff) == 1)) ||
         ((((uint)this & 0xff) == 3 ||
          (((cVar4 = d_map::IsFloorNo(cVar3), cVar4 != '\0' &&
            (cVar4 = d_map::IsFloorNo(mNowFloorNo), cVar4 != '\0')) && (mNowFloorNo == cVar3)))))) {
        setGbaPoint(this,param_5,(float)dVar6,(float)dVar8,param_6,param_7,param_8,param_9,uVar5);
      }
    }
  }
  return;
}


namespace dMap_c {

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall getTypeAgbGcFromTypeAcs(unsigned char,
                                              unsigned char *,
                                              unsigned char *) */

byte getTypeAgbGcFromTypeAcs(uchar param_1,uchar *param_2,uchar *param_3)

{
  ulong uVar1;
  byte bVar2;
  
  bVar2 = param_1;
  if (0x18 < param_1) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar1,"d_map.cpp",0x1e86,"(i_typeAcs >= 0) && (i_typeAcs < ACS_MAP_POINT_TYPE_MAX)");
    bVar2 = m_Do_printf::OSPanic("d_map.cpp",0x1e86,&DAT_8034f1dd);
  }
  if (param_2 != (uchar *)0x0) {
    bVar2 = 8;
    *param_2 = (&d_map::statusMapNo2TypeNoTbl_6998)[(uint)param_1 * 2];
  }
  if (param_3 != (uchar *)0x0) {
    bVar2 = (char)((uint)param_1 * 2) + 8;
    *param_3 = (&DAT_8034f109)[(uint)param_1 * 2];
  }
  return bVar2;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall drawPointSingle(unsigned char,
                                      float,
                                      float,
                                      float,
                                      signed char,
                                      short,
                                      unsigned char,
                                      unsigned char,
                                      unsigned char) */

void drawPointSingle
               (byte param_1,float param_2,float param_3,float param_4,byte param_5,short param_6,
               byte param_7,byte param_8,uchar param_9)

{
  uint uVar1;
  ulong uVar2;
  
  if ((-1 < (char)dStage_roomControl_c::mStayNo) && (_mNowRoomInfoP != 0)) {
    uVar1 = param_1 - 1;
    if (((int)uVar1 < 0) || (0x14 < uVar1)) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"d_map.cpp",0x1edd,"0");
      m_Do_printf::OSPanic("d_map.cpp",0x1edd,&DAT_8034f1dd);
    }
    else {
      if ((char)(&DAT_8034f13b)[param_1] < '\0') {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar2,"d_map.cpp",0x1ee4,"0");
        m_Do_printf::OSPanic("d_map.cpp",0x1ee4,&DAT_8034f1dd);
      }
      else {
        setCollectPoint(param_1,(&DAT_8034f13b)[param_1],param_2,param_3,param_4,param_5,param_6,
                        param_7,param_8,param_9,0);
      }
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall drawActorPointMiniMap(fopAc_ac_c *) */

void drawActorPointMiniMap(fopAc_ac_c *param_1)

{
  fopAcM__Status fVar1;
  byte local_r3_60;
  fopAc_ac_c *pfVar2;
  uint uVar3;
  byte local_r25_372;
  byte bVar4;
  GbaNames gbaName;
  short sVar5;
  byte local_28;
  byte local_27;
  byte local_25;
  fopAcM__Status temp_e13ada9351;
  
  if (_mNowRoomInfoP != 0) {
    gbaName = 0;
    fVar1 = param_1->mStatus & 0x1f;
    local_r3_60 = (byte)fVar1;
    local_r3_60 = getTypeAgbGcFromTypeAcs(local_r3_60,&local_27,&local_28);
    sVar5 = -0x8000;
    bVar4 = (param_1->mCurrent).mRoomNo;
    if (local_27 == 4) {
      if ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8 & 0x10000U) != 0) {
        return;
      }
      sVar5 = (param_1->mCollisionRot).y;
    }
    else {
      if (local_27 == 0x11) {
        if (fVar1 != 0xb) {
          bVar4 = *(byte *)&param_1[1].parent.parent.mLnTg.parent.parent.mpNextNode;
        }
        sVar5 = (param_1->mOrig).mRot.y;
      }
      else {
        if (local_27 == 1) {
          setArriveInfo((dMap_c *)(uint)local_r3_60,(param_1->mCurrent).mPos.x,
                        (param_1->mCurrent).mPos.z);
          sVar5 = (param_1->mCollisionRot).y;
          if (fVar1 == 0x11) {
            gbaName = Bokoblin;
          }
          else {
            if (fVar1 == 0x12) {
              gbaName = 2;
            }
            else {
              if (fVar1 == 0x13) {
                gbaName = 3;
              }
              else {
                if (fVar1 == 0x14) {
                  gbaName = Stalfos;
                }
              }
            }
          }
        }
        else {
          if (local_27 == 0x13) {
            if (fVar1 == 0xc) {
              gbaName = Bokoblin;
            }
            else {
              if (fVar1 == 0xd) {
                gbaName = 2;
              }
              else {
                if (fVar1 == 0xe) {
                  gbaName = 3;
                }
                else {
                  if (fVar1 == 0xf) {
                    gbaName = Stalfos;
                  }
                }
              }
            }
          }
        }
      }
    }
    local_r25_372 = 0;
    if ((local_27 == 2) &&
       (pfVar2 = dAttention_c::LockonTarget(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAttention,0),
       param_1 == pfVar2)) {
      uVar3 = dAttention_c::LockonTruth(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAttention);
      if ((uVar3 & 0xff) == 0) {
        local_r25_372 = 1;
      }
      else {
        local_r25_372 = 2;
      }
    }
    setCollectPoint(local_27,local_28,(param_1->mCurrent).mPos.x,(param_1->mCurrent).mPos.y,
                    (param_1->mCurrent).mPos.z,bVar4,sVar5,gbaName,param_1->mGbaName,local_r25_372,
                    local_r3_60);
  }
  return;
}

}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dMap_c::mapBufferSendAGB_commonCursor(void) */

dMap_c * __thiscall dMap_c::mapBufferSendAGB_commonCursor(dMap_c *this)

{
  int iVar1;
  uint uVar2;
  
  if ((mSetCursorFlg & 3) == 1) {
    this = (dMap_c *)(dStage_roomControl_c::mMemoryBlock + 0x13);
    dStage_roomControl_c::mMemoryBlock[21]._2_2_ = dStage_roomControl_c::mMemoryBlock[19]._2_2_;
    dStage_roomControl_c::mMemoryBlock[22]._0_2_ = dStage_roomControl_c::mMemoryBlock[20]._0_2_;
    dStage_roomControl_c::mMemoryBlock[22]._2_1_ = 0x80;
    dStage_roomControl_c::mMemoryBlock[22]._3_1_ = 3;
    dStage_roomControl_c::mMemoryBlock[23]._0_1_ = dStage_roomControl_c::mMemoryBlock[21]._0_1_;
    _mAGBPointValueC = 2;
  }
  if (((((mSetCursorFlg & 1) == 1) && (mAGBMapSendStopFlg == '\0')) &&
      (this = (dMap_c *)
              mDoGaC_agbCom_c::mDoGaC_GbaLink
                        ((mDoGaC_agbCom_c *)&m_Do_ext::m_Do_gba_com::g_mDoGaC_gbaCom),
      (JKRExpHeap **)this != (JKRExpHeap **)0x0)) &&
     (this = (dMap_c *)
             mDoGaC_agbCom_c::mDoGaC_SendStatusCheck
                       ((mDoGaC_agbCom_c *)&m_Do_ext::m_Do_gba_com::g_mDoGaC_gbaCom,'\x03'),
     (JKRExpHeap **)this != (JKRExpHeap **)0x0)) {
    iVar1 = agbIsActive(this);
    uVar2 = _mAGBPointValueE + 2;
    if (iVar1 == 0) {
      dStage_roomControl_c::mMemoryBlock[19]._0_2_ = m_Do_lib::mDoLib_cnvind16(uVar2 & 0xffff);
    }
    else {
      dStage_roomControl_c::mMemoryBlock[19]._0_2_ =
           m_Do_lib::mDoLib_cnvind16(_mAGBPointValueE + 0x102 & 0xffff);
    }
    this = (dMap_c *)
           mDoGaC_agbCom_c::mDoGaC_SendDataSet
                     ((mDoGaC_agbCom_c *)&m_Do_ext::m_Do_gba_com::g_mDoGaC_gbaCom,
                      (ulong *)(dStage_roomControl_c::mMemoryBlock + 0x13),uVar2 * 8 + 2,'\x03',0);
  }
  return this;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dMap_c::mapBufferSendAGB_ocean(void) */

void __thiscall dMap_c::mapBufferSendAGB_ocean(dMap_c *this)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  ulong uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  mapBufferSendAGB_commonCursor(this);
  iVar3 = mDoGaC_agbCom_c::mDoGaC_GbaLink
                    ((mDoGaC_agbCom_c *)&m_Do_ext::m_Do_gba_com::g_mDoGaC_gbaCom);
  if ((iVar3 != 0) &&
     (iVar3 = mDoGaC_agbCom_c::mDoGaC_SendStatusCheck
                        ((mDoGaC_agbCom_c *)&m_Do_ext::m_Do_gba_com::g_mDoGaC_gbaCom,'\v'),
     iVar3 != 0)) {
    puVar4 = &mGbaSendMapOceanDt;
    iVar3 = 7;
    do {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    iVar3 = -3;
    do {
      iVar9 = -3;
      do {
        bVar1 = false;
        if ((((-4 < iVar9) && (iVar9 < 4)) && (-4 < iVar3)) && (iVar3 < 4)) {
          bVar1 = true;
        }
        if (!bVar1) {
          uVar5 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert
                    (uVar5,"d_map.cpp",0x4a4,
                     "(i_gridX >= -3) && (i_gridX <= 3) && (i_gridY >= -3) && (i_gridY <= 3)");
          m_Do_printf::OSPanic("d_map.cpp",0x4a4,&DAT_8034f1dd);
        }
        uVar6 = iVar9 + (iVar3 + 3) * 7 + 3;
        iVar8 = ((int)uVar6 >> 3) + (uint)((int)uVar6 < 0 && (uVar6 & 7) != 0);
        iVar2 = (int)uVar6 >> 0x1f;
        iVar7 = d_map::isSaveArriveGridForAgbUseGridPos(iVar9,iVar3);
        (&mGbaSendMapOceanDt)[iVar8] =
             (&mGbaSendMapOceanDt)[iVar8] |
             (iVar7 != 0) << (iVar2 * 8 | uVar6 * 0x20000000 + iVar2 >> 0x1d) - iVar2;
        iVar9 = iVar9 + 1;
      } while (iVar9 < 4);
      iVar3 = iVar3 + 1;
    } while (iVar3 < 4);
    mDoGaC_agbCom_c::mDoGaC_SendDataSet
              ((mDoGaC_agbCom_c *)&m_Do_ext::m_Do_gba_com::g_mDoGaC_gbaCom,
               (ulong *)&mGbaSendMapOceanDt,8,'\v',0);
  }
  return;
}


/* __thiscall dMap_c::mapBufferSendAGB_dungeon(void) */

void __thiscall dMap_c::mapBufferSendAGB_dungeon(dMap_c *this)

{
  if (mAGBMapSendStatus == '\x04') {
    mapBufferSendAGB_commonCursor(this);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dMap_c::mapSetPointAll(void) */

void __thiscall dMap_c::mapSetPointAll(dMap_c *this)

{
  bool bVar1;
  ulong uVar2;
  byte bVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  uchar in_stack_ffffffeb;
  
  uVar6 = 0;
  pcVar5 = "\x01\x03\x15\x02\x04\x13\x14\a\x11\x12\f\b\t\n\v\x10\r\x05\x0f\x0e\x06";
  do {
    iVar4 = (int)(char)(*pcVar5 + -1);
    bVar1 = false;
    if ((-1 < iVar4) && (iVar4 < 0x15)) {
      bVar1 = true;
    }
    if (!bVar1) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert
                (uVar2,"d_map.cpp",0x20eb,"(typeNo >= 0) && (typeNo < AGB_POINT_TYPE_NUM)");
      m_Do_printf::OSPanic("d_map.cpp",0x20eb,&DAT_8034f1dd);
    }
    bVar3 = (&mCollectPointDataLinkList)[iVar4];
    while (-1 < (char)bVar3) {
      iVar4 = (int)(char)bVar3;
      drawPointMain((dMap_c *)(uint)mCollectPointData[iVar4].mPointType,
                    mCollectPointData[iVar4].field_0x10,mCollectPointData[iVar4].field_0xe,
                    mCollectPointData[iVar4].mPos.x,mCollectPointData[iVar4].mPos.y,
                    mCollectPointData[iVar4].mPos.z,(char)mCollectPointData[iVar4].field_0xc,
                    (ushort)mCollectPointData[iVar4].mGbaName,mCollectPointData[iVar4].field_0x12,
                    mCollectPointData[iVar4].field_0x13,mCollectPointData[iVar4].field_0x14,
                    in_stack_ffffffeb);
      bVar3 = mCollectPointData[iVar4].field_0x16;
    }
    uVar6 = uVar6 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar6 < 0x15);
  return;
}


namespace dMap_c {

/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall mapBufferSendAGB(int) */

void mapBufferSendAGB(int param_1)

{
  dComIfG_inf_c *pdVar1;
  int iVar2;
  dComIfG_inf_c *pdVar3;
  int iVar4;
  
  if (((char)dStage_roomControl_c::mStayNo < '\0') ||
     (pdVar1 = (dComIfG_inf_c *)&dStage_roomControl_c::mStatus[0x20].mTevStr.mInitTimer,
     _mNowRoomInfoP != 0)) {
    mapSetPointAll((dMap_c *)&dStage_roomControl_c::mStatus[0x20].mTevStr.mInitTimer);
    pdVar1 = &d_com_inf_game::g_dComIfG_gameInfo;
    if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNextStage.mbHasNext == 0) {
      pdVar1 = (dComIfG_inf_c *)getKindMapType((dMap_c *)&d_com_inf_game::g_dComIfG_gameInfo);
      if (pdVar1 == (dComIfG_inf_c *)&DAT_00000001) {
        if (mPlayerStayAgbMapTypeNow == '\x03') {
          if (mAGBMapSendStatus == '\x04') {
            pdVar1 = (dComIfG_inf_c *)mapBufferSendAGB_ocean((dMap_c *)&DAT_00000001);
          }
        }
        else {
          pdVar1 = (dComIfG_inf_c *)mapBufferSendAGB_ocean((dMap_c *)&DAT_00000001);
        }
      }
      else {
        pdVar1 = (dComIfG_inf_c *)getKindMapType((dMap_c *)pdVar1);
        if (pdVar1 == (dComIfG_inf_c *)&DAT_00000002) {
          pdVar1 = (dComIfG_inf_c *)mapBufferSendAGB_dungeon((dMap_c *)&DAT_00000002);
        }
      }
    }
    iVar2 = agbFlashCheck((dMap_c *)pdVar1);
    if (iVar2 == 0) {
      if (mDrawPointCntAgbCursor != '\0') {
        dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                          &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                          &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                          (dDlst_base_c *)&mAgbCursor);
      }
      if (mDrawPointRestartCnt != '\0') {
        dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                          &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                          &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                          (dDlst_base_c *)&mPointRestart);
      }
      iVar4 = 0;
      pdVar1 = &d_com_inf_game::g_dComIfG_gameInfo;
      pdVar3 = (dComIfG_inf_c *)&d_com_inf_game::g_dComIfG_gameInfo.mDlstList;
      for (iVar2 = 0; iVar2 < (int)(uint)mDoorNum; iVar2 = iVar2 + 1) {
        pdVar1 = pdVar3;
        dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                          &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                          &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                          (dDlst_base_c *)(&mDoor + iVar4));
        iVar4 = iVar4 + 0x5c;
      }
      iVar4 = 0;
      for (iVar2 = 0; iVar2 < (int)(uint)mTboxNum; iVar2 = iVar2 + 1) {
        pdVar1 = pdVar3;
        dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                          &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                          &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                          (dDlst_base_c *)(&mTbox + iVar4));
        iVar4 = iVar4 + 0x5c;
      }
      if (mDrawPointCntShip != '\0') {
        pdVar1 = pdVar3;
        dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                          &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                          &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                          (dDlst_base_c *)&mShip);
      }
      iVar4 = 0;
      for (iVar2 = 0; iVar2 < (int)(uint)mDrawPointCntEnemy; iVar2 = iVar2 + 1) {
        pdVar1 = pdVar3;
        dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                          &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                          &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                          (dDlst_base_c *)(&mPoint + iVar4));
        iVar4 = iVar4 + 0x20;
      }
      iVar4 = 0;
      for (iVar2 = 0; iVar2 < (int)(uint)mPointFriendNum; iVar2 = iVar2 + 1) {
        pdVar1 = pdVar3;
        dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                          &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                          &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                          (dDlst_base_c *)(&mPointFriend + iVar4));
        iVar4 = iVar4 + 0x20;
      }
      if (mDrawPointCntPlayer != '\0') {
        dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                          &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                          &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                          (dDlst_base_c *)&mCursor);
        pdVar1 = pdVar3;
      }
    }
    else {
      if (mDrawPointRestartCnt != '\0') {
        dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                          &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                          &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                          (dDlst_base_c *)&mPointRestart);
      }
      iVar4 = 0;
      pdVar1 = &d_com_inf_game::g_dComIfG_gameInfo;
      pdVar3 = (dComIfG_inf_c *)&d_com_inf_game::g_dComIfG_gameInfo.mDlstList;
      for (iVar2 = 0; iVar2 < (int)(uint)mDoorNum; iVar2 = iVar2 + 1) {
        pdVar1 = pdVar3;
        dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                          &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                          &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                          (dDlst_base_c *)(&mDoor + iVar4));
        iVar4 = iVar4 + 0x5c;
      }
      iVar4 = 0;
      for (iVar2 = 0; iVar2 < (int)(uint)mTboxNum; iVar2 = iVar2 + 1) {
        pdVar1 = pdVar3;
        dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                          &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                          &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                          (dDlst_base_c *)(&mTbox + iVar4));
        iVar4 = iVar4 + 0x5c;
      }
      if (mDrawPointCntShip != '\0') {
        pdVar1 = pdVar3;
        dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                          &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                          &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                          (dDlst_base_c *)&mShip);
      }
      iVar4 = 0;
      for (iVar2 = 0; iVar2 < (int)(uint)mDrawPointCntEnemy; iVar2 = iVar2 + 1) {
        pdVar1 = pdVar3;
        dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                          &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                          &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                          (dDlst_base_c *)(&mPoint + iVar4));
        iVar4 = iVar4 + 0x20;
      }
      iVar4 = 0;
      for (iVar2 = 0; iVar2 < (int)(uint)mPointFriendNum; iVar2 = iVar2 + 1) {
        pdVar1 = pdVar3;
        dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                          &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                          &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                          (dDlst_base_c *)(&mPointFriend + iVar4));
        iVar4 = iVar4 + 0x20;
      }
      if (mDrawPointCntPlayer != '\0') {
        pdVar1 = pdVar3;
        dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                          &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                          &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                          (dDlst_base_c *)&mCursor);
      }
      if (mDrawPointCntAgbCursor != '\0') {
        dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                          &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                          &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                          (dDlst_base_c *)&mAgbCursor);
        pdVar1 = pdVar3;
      }
    }
  }
  initPoint((dMap_c *)pdVar1);
  mPlayerStayAgbMapTypeOld = mPlayerStayAgbMapTypeNow;
  return;
}

}

/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall dMap_RoomInfoCtrl_c::checkFloorMoveImageChangeRoom(unsigned char,
                                                                 unsigned char,
                                                                 int,
                                                                 short,
                                                                 short,
                                                                 float) */

void __thiscall
dMap_RoomInfoCtrl_c::checkFloorMoveImageChangeRoom
          (dMap_RoomInfoCtrl_c *this,uchar param_1,uchar param_2,int param_3,short param_4,
          short param_5,float param_6)

{
  dMap_RoomInfo_c *this_00;
  double dVar1;
  
  dVar1 = (double)param_6;
  this_00 = (dMap_RoomInfo_c *)0x0;
  while (this_00 = (dMap_RoomInfo_c *)getNextRoomP(this,this_00), this_00 != (dMap_RoomInfo_c *)0x0)
  {
    if (this_00->field_0x0 != 0) {
      dMap_RoomInfo_c::Changeimage(this_00,param_1,param_2,param_3,param_4,param_5,(float)dVar1);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dMap_2DMtMapSpcl_tex_c::init(ResTIMG *,
                                           unsigned long,
                                           _GXColor const &) */

int __thiscall dMap_2DMtMapSpcl_tex_c::init(dMap_2DMtMapSpcl_tex_c *this,EVP_PKEY_CTX *ctx)

{
  int iVar1;
  undefined4 in_r5;
  dMap_2DMtMapSpcl_tex_c *in_r6;
  
  *(undefined4 *)(this + 0x44) = in_r5;
  if (ctx[8] == (EVP_PKEY_CTX)0x0) {
    gx::GXInitTexObj((GXTexObj *)(this + 4),ctx + *(int *)(ctx + 0x1c),(uint)*(ushort *)(ctx + 2),
                     (uint)*(ushort *)(ctx + 4),(_GXTexFmt)*ctx,(_GXTexWrapMode)ctx[6],
                     (_GXTexWrapMode)ctx[7],SUB41(1 - (uint)(byte)ctx[0x18] >> 0x1f,0));
    this[1] = (dMap_2DMtMapSpcl_tex_c)0x0;
  }
  else {
    gx::GXInitTlutObj(this + 0x24,ctx + *(int *)(ctx + 0xc),ctx[9],*(undefined2 *)(ctx + 10));
    gx::GXInitTexObjCI(this + 4,ctx + *(int *)(ctx + 0x1c),*(undefined2 *)(ctx + 2),
                       *(undefined2 *)(ctx + 4),*ctx,ctx[6],ctx[7],1 - (byte)ctx[0x18] >> 0x1f);
    this[1] = (dMap_2DMtMapSpcl_tex_c)0x1;
  }
  iVar1 = gx::GXInitTexObjLOD((double)(d_map::_7319 *
                                      (float)((double)CONCAT44(0x43300000,
                                                               (int)(char)ctx[0x16] ^ 0x80000000) -
                                             d_map::_4818)),
                              (double)(d_map::_7319 *
                                      (float)((double)CONCAT44(0x43300000,
                                                               (int)(char)ctx[0x17] ^ 0x80000000) -
                                             d_map::_4818)),
                              (double)(d_map::_7320 *
                                      (float)((double)CONCAT44(0x43300000,
                                                               (int)*(short *)(ctx + 0x1a) ^
                                                               0x80000000) - d_map::_4818)),this + 4
                              ,ctx[0x14],ctx[0x15],ctx[0x12],ctx[0x11],ctx[0x13]);
  this[0x30] = *in_r6;
  this[0x31] = in_r6[1];
  this[0x32] = in_r6[2];
  this[0x33] = in_r6[3];
  *this = (dMap_2DMtMapSpcl_tex_c)0x1;
  return iVar1;
}


/* __thiscall dMap_2DMtMapSpcl_tex_c::setScroll(float,
                                                float,
                                                float,
                                                float) */

void __thiscall
dMap_2DMtMapSpcl_tex_c::setScroll
          (dMap_2DMtMapSpcl_tex_c *this,float param_1,float param_2,float param_3,float param_4)

{
  *(float *)(this + 0x34) = param_1;
  *(float *)(this + 0x38) = param_2;
  *(float *)(this + 0x3c) = param_3;
  *(float *)(this + 0x40) = param_4;
  return;
}


/* __thiscall dMap_2DMtMapSpcl_c::init(int,
                                       dMap_2DMtMapSpcl_tex_c *) */

int __thiscall dMap_2DMtMapSpcl_c::init(dMap_2DMtMapSpcl_c *this,EVP_PKEY_CTX *ctx)

{
  undefined4 in_r5;
  
  this[5] = (dMap_2DMtMapSpcl_c)0x0;
  this[4] = SUB41(ctx,0);
  *(undefined4 *)(this + 8) = in_r5;
  return (int)this;
}


/* __thiscall dMap_2DMtMapSpcl_c::setPos(short,
                                         short,
                                         short,
                                         short) */

void __thiscall
dMap_2DMtMapSpcl_c::setPos
          (dMap_2DMtMapSpcl_c *this,short param_1,short param_2,short param_3,short param_4)

{
  *(short *)(this + 0xc) = param_1;
  *(short *)(this + 0xe) = param_2;
  *(short *)(this + 0x10) = param_3;
  *(short *)(this + 0x12) = param_4;
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x8004de0c) */
/* __thiscall dMap_2DMtMapSpcl_c::draw(void) */

void __thiscall dMap_2DMtMapSpcl_c::draw(dMap_2DMtMapSpcl_c *this)

{
  dMap_2DMtMapSpcl_c dVar1;
  GXTevColorArg GVar2;
  GXTevAlphaArg GVar3;
  int iVar4;
  char *pcVar5;
  GXTevStageID dst_coord;
  int iVar6;
  _GXColor local_1d8;
  undefined auStack468 [444];
  
  gx::GXGetVtxAttrFmtv(0,auStack468);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_RGBA4,0);
  gx::GXClearVtxDesc();
  gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
  gx::GXSetZMode(false,GX_LEQUAL,false);
  pcVar5 = *(char **)(this + 8);
  dst_coord = GX_TEVSTAGE0;
  iVar6 = 0;
  for (iVar4 = 0; iVar4 < (int)(uint)(byte)this[4]; iVar4 = iVar4 + 1) {
    if (*pcVar5 != '\0') {
      if (pcVar5[1] != '\0') {
        gx::GXLoadTlut(pcVar5 + 0x24,*(undefined4 *)(pcVar5 + 0x44));
      }
      gx::GXLoadTexObj((GXTexObj *)(pcVar5 + 4),dst_coord);
      gx::GXSetVtxAttrFmt(GX_VTXFMT0,dst_coord + GX_TEVSTAGE13,GX_CLR_RGBA,GX_F32,0);
      gx::GXSetVtxDesc(dst_coord + GX_TEVSTAGE13,GX_DIRECT);
      local_1d8 = *(_GXColor *)(pcVar5 + 0x30);
      gx::GXSetTevColor(dst_coord + GX_TEVREG0,&local_1d8);
      gx::GXSetTexCoordGen2
                (dst_coord,GX_TG_MTX2x4,dst_coord + GX_TEVSTAGE4,GX_IDENTITY,false,GX_PTIDENTITY);
      gx::GXSetTevOrder(dst_coord,dst_coord,dst_coord,GX_COLOR_NULL);
      GVar2 = GX_CC_ZERO;
      if (dst_coord != GX_TEVSTAGE0) {
        GVar2 = GX_CC_CPREV;
      }
      gx::GXSetTevColorIn(dst_coord,GX_CC_ZERO,iVar6 + GX_CC_C0,GX_CC_TEXC,GVar2);
      gx::GXSetTevColorOp(dst_coord,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
      GVar3 = GX_CA_ZERO;
      if (dst_coord != GX_TEVSTAGE0) {
        GVar3 = GX_CA_APREV;
      }
      gx::GXSetTevAlphaIn(dst_coord,GX_CA_ZERO,dst_coord + GX_TEVREG0,GX_CA_TEXA,GVar3);
      gx::GXSetTevAlphaOp(dst_coord,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
      dst_coord = dst_coord + GX_TEVSTAGE1;
      iVar6 = iVar6 + 2;
      if (2 < (int)dst_coord) break;
    }
    pcVar5 = pcVar5 + 0x48;
  }
  if (dst_coord == GX_TEVSTAGE0) {
    return;
  }
  gx::GXSetNumChans(0);
  gx::GXSetNumTexGens(dst_coord & 0xff);
  gx::GXSetNumTevStages(dst_coord & 0xff);
  dVar1 = this[5];
  if (dVar1 != (dMap_2DMtMapSpcl_c)0x2) {
    if (1 < (byte)dVar1) {
      if ((byte)dVar1 < 4) {
        gx::GXSetBlendMode(GX_BM_BLEND,GX_BL_SRCALPHA,GX_BL_ONE,GX_LO_SET);
      }
      goto LAB_8004de88;
    }
    if (dVar1 == (dMap_2DMtMapSpcl_c)0x0) {
      gx::GXSetBlendMode(GX_BM_BLEND,GX_BL_SRCALPHA,GX_BL_INVSRCALPHA,GX_LO_SET);
      goto LAB_8004de88;
    }
    gx::GXSetBlendMode(GX_BM_BLEND,GX_BL_SRCALPHA,GX_BL_INVSRCALPHA,GX_LO_SET);
    gx::GXSetDstAlpha(1,0);
    gx::GXSetAlphaUpdate(1);
  }
  gx::GXSetBlendMode(GX_BM_BLEND,GX_BL_DSTALPHA,GX_BL_INVDSTALPHA,GX_LO_SET);
LAB_8004de88:
  gx::GXSetAlphaCompare(GX_GREATER,0,GX_AOP_AND,GX_ALWAYS,0);
  gx::GXBegin(0x80,0,4);
  write_volatile_2(0xcc008000,*(undefined2 *)(this + 0xc));
  write_volatile_2(0xcc008000,*(undefined2 *)(this + 0xe));
  write_volatile_2(0xcc008000,0);
  pcVar5 = *(char **)(this + 8);
  for (iVar4 = 0; iVar4 < (int)(uint)(byte)this[4]; iVar4 = iVar4 + 1) {
    if (*pcVar5 != '\0') {
      write_volatile_4(0xcc008000,*(undefined4 *)(pcVar5 + 0x34));
      write_volatile_4(0xcc008000,*(undefined4 *)(pcVar5 + 0x38));
    }
    pcVar5 = pcVar5 + 0x48;
  }
  write_volatile_2(0xcc008000,*(undefined2 *)(this + 0x10));
  write_volatile_2(0xcc008000,*(undefined2 *)(this + 0xe));
  write_volatile_2(0xcc008000,0);
  pcVar5 = *(char **)(this + 8);
  for (iVar4 = 0; iVar4 < (int)(uint)(byte)this[4]; iVar4 = iVar4 + 1) {
    if (*pcVar5 != '\0') {
      write_volatile_4(0xcc008000,*(float *)(pcVar5 + 0x34) + *(float *)(pcVar5 + 0x3c));
      write_volatile_4(0xcc008000,*(undefined4 *)(pcVar5 + 0x38));
    }
    pcVar5 = pcVar5 + 0x48;
  }
  write_volatile_2(0xcc008000,*(undefined2 *)(this + 0x10));
  write_volatile_2(0xcc008000,*(undefined2 *)(this + 0x12));
  write_volatile_2(0xcc008000,0);
  pcVar5 = *(char **)(this + 8);
  for (iVar4 = 0; iVar4 < (int)(uint)(byte)this[4]; iVar4 = iVar4 + 1) {
    if (*pcVar5 != '\0') {
      write_volatile_4(0xcc008000,*(float *)(pcVar5 + 0x34) + *(float *)(pcVar5 + 0x3c));
      write_volatile_4(0xcc008000,*(float *)(pcVar5 + 0x38) + *(float *)(pcVar5 + 0x40));
    }
    pcVar5 = pcVar5 + 0x48;
  }
  write_volatile_2(0xcc008000,*(undefined2 *)(this + 0xc));
  write_volatile_2(0xcc008000,*(undefined2 *)(this + 0x12));
  write_volatile_2(0xcc008000,0);
  pcVar5 = *(char **)(this + 8);
  for (iVar4 = 0; iVar4 < (int)(uint)(byte)this[4]; iVar4 = iVar4 + 1) {
    if (*pcVar5 != '\0') {
      write_volatile_4(0xcc008000,*(undefined4 *)(pcVar5 + 0x34));
      write_volatile_4(0xcc008000,*(float *)(pcVar5 + 0x38) + *(float *)(pcVar5 + 0x40));
    }
    pcVar5 = pcVar5 + 0x48;
  }
  gx::GXSetDstAlpha(0,0);
  gx::GXSetAlphaUpdate(0);
  gx::GXSetVtxAttrFmtv(0,auStack468);
  return;
}


/* __thiscall dMap_2DAGBScrDsp_c::setImage(ResTIMG *,
                                           map_dt_c *) */

void __thiscall
dMap_2DAGBScrDsp_c::setImage(dMap_2DAGBScrDsp_c *this,ResTIMG *param_1,map_dt_c *param_2)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;
  
  *(map_dt_c **)(this + 4) = param_2;
  *(ResTIMG **)(this + 8) = param_1;
  if ((*(int *)(this + 4) == 0) || (iVar2 = *(int *)(this + 8), iVar2 == 0)) {
    *(undefined4 *)(this + 0x38) = 0;
  }
  else {
    gx::GXInitTlutObj(this + 0x2c,iVar2 + *(int *)(iVar2 + 0xc),*(undefined *)(iVar2 + 9),
                      *(undefined2 *)(iVar2 + 10));
    puVar3 = *(undefined **)(this + 8);
    gx::GXInitTexObjCI(this + 0xc,puVar3 + *(int *)(puVar3 + 0x1c),*(undefined2 *)(puVar3 + 2),
                       *(undefined2 *)(puVar3 + 4),*puVar3,puVar3[6],puVar3[7],
                       1 - (byte)puVar3[0x18] >> 0x1f,0);
    iVar2 = *(int *)(this + 8);
    gx::GXInitTexObjLOD((double)(d_map::_7319 *
                                (float)((double)CONCAT44(0x43300000,
                                                         (int)*(char *)(iVar2 + 0x16) ^ 0x80000000)
                                       - d_map::_4818)),
                        (double)(d_map::_7319 *
                                (float)((double)CONCAT44(0x43300000,
                                                         (int)*(char *)(iVar2 + 0x17) ^ 0x80000000)
                                       - d_map::_4818)),
                        (double)(d_map::_7320 *
                                (float)((double)CONCAT44(0x43300000,
                                                         (int)*(short *)(iVar2 + 0x1a) ^ 0x80000000)
                                       - d_map::_4818)),this + 0xc,0,0,*(undefined *)(iVar2 + 0x12),
                        *(undefined *)(iVar2 + 0x11),*(undefined *)(iVar2 + 0x13));
    iVar2 = m_Do_lib::mDoLib_cnvind32(*(undefined4 *)(*(int *)(this + 4) + 0x38));
    iVar1 = m_Do_lib::mDoLib_cnvind32(*(undefined4 *)(*(int *)(this + 4) + 0xc));
    *(int *)(this + 0x38) = iVar1 + iVar2 + 0x3c;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328ea4 */
/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328ef0 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall dMap_2DAGBScrDsp_c::init(map_dt_c *,
                                       ResTIMG *,
                                       float,
                                       float,
                                       short,
                                       short,
                                       short,
                                       short,
                                       float,
                                       float,
                                       unsigned char) */

int __thiscall dMap_2DAGBScrDsp_c::init(dMap_2DAGBScrDsp_c *this,EVP_PKEY_CTX *ctx)

{
  int iVar1;
  ResTIMG *in_r5;
  undefined2 in_r6;
  undefined2 in_r7;
  undefined2 in_r8;
  undefined2 in_r9;
  dMap_2DAGBScrDsp_c in_r10;
  double in_f1;
  double in_f2;
  double in_f3;
  double in_f4;
  
  iVar1 = setImage(this,in_r5,(map_dt_c *)ctx);
  *(float *)(this + 0x44) = (float)in_f1;
  *(float *)(this + 0x48) = (float)in_f2;
  *(undefined2 *)(this + 0x3c) = in_r6;
  *(undefined2 *)(this + 0x3e) = in_r7;
  *(undefined2 *)(this + 0x40) = in_r8;
  *(undefined2 *)(this + 0x42) = in_r9;
  *(float *)(this + 0x4c) = (float)in_f3;
  *(float *)(this + 0x50) = (float)in_f4;
  this[0x54] = in_r10;
  return iVar1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x8004e35c) */
/* WARNING: Removing unreachable block (ram,0x8004e364) */
/* __thiscall dMap_2DAGBScrDsp_c::getScrnPrm(float,
                                             float,
                                             int,
                                             float,
                                             int *,
                                             float *,
                                             float *) */

void __thiscall
dMap_2DAGBScrDsp_c::getScrnPrm
          (dMap_2DAGBScrDsp_c *this,float param_1,float param_2,int param_3,float param_4,
          int *param_5,float *param_6,float *param_7)

{
  undefined4 uVar1;
  double dVar2;
  undefined8 in_f30;
  double __y;
  undefined8 in_f31;
  double __x;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  if (d_map::_7488 == (double)param_4) {
    if (param_5 != (int *)0x0) {
      *param_5 = 0;
    }
    if (param_6 != (float *)0x0) {
      *param_6 = d_map::_4426;
    }
    if (param_7 != (float *)0x0) {
      *param_7 = d_map::_4426;
    }
  }
  else {
    __y = (double)(float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - d_map::_4818);
    __x = (double)(param_1 + param_2 * (float)((double)d_map::_4611 / (double)param_4));
    dVar2 = MSL_C.PPCEABI.bare.H::floor((double)(float)(__x / __y));
    if (param_5 != (int *)0x0) {
      *param_5 = (int)dVar2;
    }
    dVar2 = MSL_C.PPCEABI.bare.H::fmod(__x,__y);
    dVar2 = MSL_C.PPCEABI.bare.H::fmod((double)(float)(__y + (double)(float)dVar2),__y);
    if (param_6 != (float *)0x0) {
      *param_6 = (float)dVar2;
    }
    if (param_7 != (float *)0x0) {
      *param_7 = (float)((double)(float)dVar2 / __y);
    }
  }
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  __psq_l0(auStack24,uVar1);
  __psq_l1(auStack24,uVar1);
  return;
}


/* WARNING: Inlined function: FUN_80328ea8 */
/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328ef4 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dMap_2DAGBScrDsp_c::getScrnPrmXY(float,
                                               float,
                                               float,
                                               float,
                                               int,
                                               int,
                                               float,
                                               float,
                                               int *,
                                               int *,
                                               float *,
                                               float *,
                                               float *,
                                               float *) */

void __thiscall
dMap_2DAGBScrDsp_c::getScrnPrmXY
          (dMap_2DAGBScrDsp_c *this,float param_1,float param_2,float param_3,float param_4,
          int param_5,int param_6,float param_7,float param_8,int *param_9,int *param_10,
          float *param_11,float *param_12,float *param_13,float *param_14)

{
  double dVar1;
  double dVar2;
  double dVar3;
  
  dVar3 = (double)param_8;
  dVar2 = (double)param_4;
  dVar1 = (double)param_2;
  getScrnPrm(this,param_1,param_3,param_5,param_7,param_9,param_11,param_13);
  getScrnPrm(this,(float)dVar1,(float)dVar2,param_6,(float)dVar3,param_10,param_12,param_14);
  return;
}


/* WARNING: Inlined function: FUN_80328f18 */
/* WARNING: Inlined function: FUN_80328f64 */
/* WARNING: Removing unreachable block (ram,0x8004e670) */
/* WARNING: Removing unreachable block (ram,0x8004e660) */
/* WARNING: Removing unreachable block (ram,0x8004e650) */
/* WARNING: Removing unreachable block (ram,0x8004e658) */
/* WARNING: Removing unreachable block (ram,0x8004e668) */
/* WARNING: Removing unreachable block (ram,0x8004e678) */
/* __thiscall dMap_2DAGBScrDsp_c::calc_standard_prm(unsigned short,
                                                    unsigned short,
                                                    float,
                                                    float,
                                                    short,
                                                    short,
                                                    short,
                                                    short,
                                                    float,
                                                    float,
                                                    int *,
                                                    int *,
                                                    int *,
                                                    int *,
                                                    float *,
                                                    float *,
                                                    float *,
                                                    float *,
                                                    float *,
                                                    float *) */

void __thiscall
dMap_2DAGBScrDsp_c::calc_standard_prm
          (dMap_2DAGBScrDsp_c *this,ushort param_1,ushort param_2,float param_3,float param_4,
          short param_5,short param_6,short param_7,short param_8,float param_9,float param_10,
          int *param_11,int *param_12,int *param_13,int *param_14,float *param_15,float *param_16,
          float *param_17,float *param_18,float *param_19,float *param_20)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  undefined8 in_f26;
  undefined8 in_f27;
  undefined8 in_f28;
  undefined8 in_f29;
  double dVar8;
  undefined8 in_f30;
  double dVar9;
  undefined8 in_f31;
  float local_d0;
  float local_cc;
  int local_c8;
  int local_c4;
  int local_c0;
  int local_bc;
  undefined4 local_b8;
  uint uStack180;
  undefined4 local_b0;
  uint uStack172;
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar6 = (double)param_9;
  dVar7 = (double)param_10;
  dVar5 = (double)param_4;
  dVar4 = (double)param_3;
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
  uStack180 = (int)param_7 - (int)param_5 ^ 0x80000000;
  local_b8 = 0x43300000;
  dVar9 = (double)(d_map::_4929 * (float)((double)CONCAT44(0x43300000,uStack180) - d_map::_4818));
  uStack172 = (int)param_8 - (int)param_6 ^ 0x80000000;
  local_b0 = 0x43300000;
  dVar8 = (double)(d_map::_4929 * (float)((double)CONCAT44(0x43300000,uStack172) - d_map::_4818));
  uVar1 = (uint)param_1;
  uVar2 = (uint)param_2;
  getScrnPrmXY(this,param_3,param_4,d_map::_4426,d_map::_4426,uVar1,uVar2,param_9,param_10,&local_c4
               ,&local_c8,&local_cc,&local_d0,(float *)0x0,(float *)0x0);
  getScrnPrmXY(this,(float)dVar4,(float)dVar5,(float)-dVar9,(float)-dVar8,uVar1,uVar2,(float)dVar6,
               (float)dVar7,param_13,param_14,(float *)0x0,(float *)0x0,param_17,param_19);
  getScrnPrmXY(this,(float)dVar4,(float)dVar5,(float)dVar9,(float)dVar8,uVar1,uVar2,(float)dVar6,
               (float)dVar7,&local_bc,&local_c0,(float *)0x0,(float *)0x0,param_18,param_20);
  *param_11 = (local_bc - *param_13) + 1;
  *param_12 = (local_c0 - *param_14) + 1;
  dVar4 = d_map::_4818;
  *param_15 = -(float)(dVar6 * (double)(local_cc +
                                       (float)((double)CONCAT44(0x43300000,
                                                                uVar1 * (local_c4 - *param_13) ^
                                                                0x80000000) - d_map::_4818)));
  *param_16 = -(float)(dVar7 * (double)(local_d0 +
                                       (float)((double)CONCAT44(0x43300000,
                                                                uVar2 * (local_c8 - *param_14) ^
                                                                0x80000000) - dVar4)));
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
  return;
}


/* WARNING: Inlined function: FUN_80328f20 */
/* WARNING: Inlined function: FUN_80328f6c */
/* WARNING: Removing unreachable block (ram,0x8004ee08) */
/* WARNING: Removing unreachable block (ram,0x8004edf8) */
/* WARNING: Removing unreachable block (ram,0x8004ede8) */
/* WARNING: Removing unreachable block (ram,0x8004edd8) */
/* WARNING: Removing unreachable block (ram,0x8004edc8) */
/* WARNING: Removing unreachable block (ram,0x8004edb8) */
/* WARNING: Removing unreachable block (ram,0x8004eda8) */
/* WARNING: Removing unreachable block (ram,0x8004ed98) */
/* WARNING: Removing unreachable block (ram,0x8004ed88) */
/* WARNING: Removing unreachable block (ram,0x8004ed90) */
/* WARNING: Removing unreachable block (ram,0x8004eda0) */
/* WARNING: Removing unreachable block (ram,0x8004edb0) */
/* WARNING: Removing unreachable block (ram,0x8004edc0) */
/* WARNING: Removing unreachable block (ram,0x8004edd0) */
/* WARNING: Removing unreachable block (ram,0x8004ede0) */
/* WARNING: Removing unreachable block (ram,0x8004edf0) */
/* WARNING: Removing unreachable block (ram,0x8004ee00) */
/* WARNING: Removing unreachable block (ram,0x8004ee10) */
/* __thiscall dMap_2DAGBScrDsp_c::draw(void) */

void __thiscall dMap_2DAGBScrDsp_c::draw(dMap_2DAGBScrDsp_c *this)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  double dVar13;
  undefined8 in_f14;
  double dVar14;
  undefined8 in_f15;
  double dVar15;
  undefined8 in_f16;
  double dVar16;
  undefined8 in_f17;
  double dVar17;
  undefined8 in_f18;
  double dVar18;
  undefined8 in_f19;
  double dVar19;
  undefined8 in_f20;
  double dVar20;
  undefined8 in_f21;
  double dVar21;
  undefined8 in_f22;
  double dVar22;
  undefined8 in_f23;
  double dVar23;
  undefined8 in_f24;
  double dVar24;
  undefined8 in_f25;
  double dVar25;
  undefined8 in_f26;
  double dVar26;
  undefined8 in_f27;
  double dVar27;
  undefined8 in_f28;
  double dVar28;
  undefined8 in_f29;
  double dVar29;
  undefined8 in_f30;
  double dVar30;
  undefined8 in_f31;
  double dVar31;
  _GXColor local_360;
  float local_35c;
  float local_358;
  float local_354;
  float local_350;
  float local_34c;
  float local_348;
  int local_344;
  int local_340;
  int local_33c;
  int local_338;
  _GXColor local_334;
  undefined auStack816 [432];
  undefined4 local_180;
  uint uStack380;
  undefined4 local_178;
  uint uStack372;
  undefined4 local_170;
  uint uStack364;
  undefined4 local_168;
  uint uStack356;
  double local_160;
  double local_158;
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
  
  uVar12 = 0;
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
  if ((((*(int *)(this + 4) != 0) && (*(int *)(this + 8) != 0)) &&
      (d_map::_4426 != *(float *)(this + 0x4c))) && (d_map::_4426 != *(float *)(this + 0x50))) {
    copy_bytes(&local_334.r,&d_map::masterTevColor_7508,4);
    gx::GXGetVtxAttrFmtv(0,auStack816);
    gx::GXLoadTlut(this + 0x2c,0);
    gx::GXLoadTexObj((GXTexObj *)(this + 0xc),0);
    gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_F32,0);
    gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX0,GX_CLR_RGBA,GX_F32,0);
    gx::GXClearVtxDesc();
    gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
    gx::GXSetVtxDesc(GX_VA_TEX0,GX_DIRECT);
    gx::GXSetNumChans(0);
    gx::GXSetNumTexGens(1);
    gx::GXSetTexCoordGen2(GX_TEXCOORD0,GX_TG_MTX2x4,GX_TG_TEX0,GX_IDENTITY,false,GX_PTIDENTITY);
    gx::GXSetNumTevStages(1);
    local_334 = (_GXColor)((uint)local_334 & 0xffffff00 | (uint)(byte)this[0x54]);
    local_360 = local_334;
    gx::GXSetTevColor(GX_TEVREG0,&local_360);
    gx::GXSetZMode(false,GX_LEQUAL,false);
    gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD0,GX_TEXMAP0,GX_COLOR_NULL);
    gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_ZERO,GX_CC_ZERO,GX_CC_ZERO,GX_CC_TEXC);
    gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_A0,GX_CA_TEXA,GX_CA_ZERO);
    gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    gx::GXSetBlendMode(GX_BM_BLEND,GX_BL_SRCALPHA,GX_BL_INVSRCALPHA,GX_LO_SET);
    gx::GXSetCullMode(0);
    gx::GXSetAlphaCompare(GX_GEQUAL,(byte)this[0x54],GX_AOP_AND,GX_ALWAYS,0);
    gx::GXSetColorUpdate(true);
    gx::GXSetAlphaUpdate(1);
    gx::GXSetDstAlpha(1,0);
    uStack380 = *(ushort *)(*(int *)(this + 8) + 2) ^ 0x80000000;
    local_180 = 0x43300000;
    dVar21 = (double)(d_map::_6423 / (float)((double)CONCAT44(0x43300000,uStack380) - d_map::_4818))
    ;
    uStack372 = *(ushort *)(*(int *)(this + 8) + 4) ^ 0x80000000;
    local_178 = 0x43300000;
    dVar20 = (double)(d_map::_6423 / (float)((double)CONCAT44(0x43300000,uStack372) - d_map::_4818))
    ;
    iVar7 = *(int *)(this + 4);
    bVar1 = *(byte *)(iVar7 + 0x30);
    bVar2 = *(byte *)(iVar7 + 0x31);
    uStack364 = (int)*(short *)(this + 0x40) + (int)*(short *)(this + 0x3c) ^ 0x80000000;
    local_170 = 0x43300000;
    dVar19 = (double)(d_map::_4929 * (float)((double)CONCAT44(0x43300000,uStack364) - d_map::_4818))
    ;
    uStack356 = (int)*(short *)(this + 0x42) + (int)*(short *)(this + 0x3e) ^ 0x80000000;
    local_168 = 0x43300000;
    dVar18 = (double)(d_map::_4929 * (float)((double)CONCAT44(0x43300000,uStack356) - d_map::_4818))
    ;
    iVar3 = m_Do_lib::mDoLib_cnvind32(*(undefined4 *)(iVar7 + 0x34));
    iVar7 = *(int *)(this + 4);
    calc_standard_prm(this,8,8,*(float *)(this + 0x44),*(float *)(this + 0x48),
                      *(short *)(this + 0x3c),*(short *)(this + 0x3e),*(short *)(this + 0x40),
                      *(short *)(this + 0x42),*(float *)(this + 0x4c),*(float *)(this + 0x50),
                      &local_338,&local_33c,&local_340,&local_344,&local_348,&local_34c,&local_350,
                      &local_354,&local_358,&local_35c);
    uVar9 = 0;
    local_160 = (double)d_map::_6423;
    dVar28 = d_map::_4818;
    for (iVar11 = 0; iVar11 < local_33c; iVar11 = iVar11 + 1) {
      uStack356 = uVar9 ^ 0x80000000;
      local_168 = 0x43300000;
      dVar15 = (double)(float)(dVar18 + (double)(local_34c +
                                                (float)((double)*(float *)(this + 0x50) *
                                                       (double)(float)((double)CONCAT44(0x43300000,
                                                                                        uStack356) -
                                                                      dVar28))));
      dVar14 = (double)(float)(dVar15 + (double)(float)(local_160 * (double)*(float *)(this + 0x50))
                              );
      iVar5 = iVar11 + local_344;
      if ((-1 < iVar5) && (iVar5 < (int)(uint)bVar2)) {
        dVar31 = (double)d_map::_7599;
        dVar30 = (double)d_map::_7600;
        if (iVar11 == 0) {
          dVar31 = (double)local_358;
          uStack356 = (int)*(short *)(this + 0x3e) ^ 0x80000000;
          dVar15 = (double)(float)((double)CONCAT44(0x43300000,uStack356) - dVar28);
        }
        else {
          if (iVar11 == local_33c + -1) {
            dVar30 = (double)local_35c;
            uStack356 = (int)*(short *)(this + 0x42) ^ 0x80000000;
            dVar14 = (double)(float)((double)CONCAT44(0x43300000,uStack356) - dVar28);
          }
        }
        local_168 = 0x43300000;
        uVar8 = 0;
        dVar27 = (double)(float)((double)d_map::_4611 - dVar31);
        dVar26 = (double)(float)((double)d_map::_4611 - dVar30);
        local_158 = (double)d_map::_6423;
        dVar29 = d_map::_4818;
        for (iVar10 = 0; iVar10 < local_338; iVar10 = iVar10 + 1) {
          uStack356 = uVar8 ^ 0x80000000;
          local_168 = 0x43300000;
          dVar17 = (double)(float)(dVar19 + (double)(local_348 +
                                                    (float)((double)*(float *)(this + 0x4c) *
                                                           (double)(float)((double)CONCAT44(
                                                  0x43300000,uStack356) - dVar29))));
          dVar16 = (double)(float)(dVar17 + (double)(float)(local_158 *
                                                           (double)*(float *)(this + 0x4c)));
          iVar6 = iVar10 + local_340;
          if ((-1 < iVar6) && (iVar6 < (int)(uint)bVar1)) {
            dVar22 = (double)d_map::_7599;
            dVar23 = (double)d_map::_7600;
            if (iVar10 == 0) {
              dVar22 = (double)local_350;
              uStack356 = (int)*(short *)(this + 0x3c) ^ 0x80000000;
              dVar17 = (double)(float)((double)CONCAT44(0x43300000,uStack356) - dVar29);
            }
            else {
              if (iVar10 == local_338 + -1) {
                dVar23 = (double)local_354;
                uStack356 = (int)*(short *)(this + 0x40) ^ 0x80000000;
                dVar16 = (double)(float)((double)CONCAT44(0x43300000,uStack356) - dVar29);
              }
            }
            local_168 = 0x43300000;
            uVar4 = m_Do_lib::mDoLib_cnvind16
                              (*(undefined2 *)(iVar7 + iVar3 + iVar5 * (uint)bVar1 * 2 + iVar6 * 2))
            ;
            dVar13 = dVar30;
            dVar24 = dVar31;
            if ((uVar4 & 0x800) != 0) {
              dVar13 = dVar26;
              dVar24 = dVar27;
            }
            if ((uVar4 & 0x400) != 0) {
              dVar22 = (double)(float)((double)d_map::_4611 - dVar22);
              dVar23 = (double)(float)((double)d_map::_4611 - dVar23);
            }
            uStack364 = uVar4 & 0xf ^ 0x80000000;
            local_168 = 0x43300000;
            dVar25 = (double)(float)(dVar21 * (double)(float)((double)(float)((double)CONCAT44(
                                                  0x43300000,uStack364) - d_map::_4818) + dVar22));
            local_170 = 0x43300000;
            dVar23 = (double)(float)(dVar21 * (double)(float)((double)(float)((double)CONCAT44(
                                                  0x43300000,uStack364) - d_map::_4818) + dVar23));
            uStack380 = (uVar4 & 0xffff) >> 4 & 0x3f ^ 0x80000000;
            local_178 = 0x43300000;
            dVar24 = (double)(float)(dVar20 * (double)(float)((double)(float)((double)CONCAT44(
                                                  0x43300000,uStack380) - d_map::_4818) + dVar24));
            local_180 = 0x43300000;
            dVar22 = (double)(float)(dVar20 * (double)(float)((double)(float)((double)CONCAT44(
                                                  0x43300000,uStack380) - d_map::_4818) + dVar13));
            uStack372 = uStack380;
            uStack356 = uStack364;
            gx::GXBegin(0x80,0,4);
            write_volatile_4(0xcc008000,(float)dVar17);
            write_volatile_4(0xcc008000,(float)dVar15);
            write_volatile_4(0xcc008000,d_map::_4426);
            write_volatile_4(0xcc008000,(float)dVar25);
            write_volatile_4(0xcc008000,(float)dVar24);
            write_volatile_4(0xcc008000,(float)dVar16);
            write_volatile_4(0xcc008000,(float)dVar15);
            write_volatile_4(0xcc008000,d_map::_4426);
            write_volatile_4(0xcc008000,(float)dVar23);
            write_volatile_4(0xcc008000,(float)dVar24);
            write_volatile_4(0xcc008000,(float)dVar16);
            write_volatile_4(0xcc008000,(float)dVar14);
            write_volatile_4(0xcc008000,d_map::_4426);
            write_volatile_4(0xcc008000,(float)dVar23);
            write_volatile_4(0xcc008000,(float)dVar22);
            write_volatile_4(0xcc008000,(float)dVar17);
            write_volatile_4(0xcc008000,(float)dVar14);
            write_volatile_4(0xcc008000,d_map::_4426);
            write_volatile_4(0xcc008000,(float)dVar25);
            write_volatile_4(0xcc008000,(float)dVar22);
          }
          uVar8 = uVar8 + 8;
        }
      }
      uVar9 = uVar9 + 8;
    }
    gx::GXSetColorUpdate(true);
    gx::GXSetAlphaUpdate(0);
    gx::GXSetDstAlpha(0,0);
    gx::GXSetAlphaCompare(GX_ALWAYS,0,GX_AOP_OR,GX_ALWAYS,0);
    gx::GXSetVtxAttrFmtv(0,auStack816);
  }
  __psq_l0(auStack8,uVar12);
  __psq_l1(auStack8,uVar12);
  __psq_l0(auStack24,uVar12);
  __psq_l1(auStack24,uVar12);
  __psq_l0(auStack40,uVar12);
  __psq_l1(auStack40,uVar12);
  __psq_l0(auStack56,uVar12);
  __psq_l1(auStack56,uVar12);
  __psq_l0(auStack72,uVar12);
  __psq_l1(auStack72,uVar12);
  __psq_l0(auStack88,uVar12);
  __psq_l1(auStack88,uVar12);
  __psq_l0(auStack104,uVar12);
  __psq_l1(auStack104,uVar12);
  __psq_l0(auStack120,uVar12);
  __psq_l1(auStack120,uVar12);
  __psq_l0(auStack136,uVar12);
  __psq_l1(auStack136,uVar12);
  __psq_l0(auStack152,uVar12);
  __psq_l1(auStack152,uVar12);
  __psq_l0(auStack168,uVar12);
  __psq_l1(auStack168,uVar12);
  __psq_l0(auStack184,uVar12);
  __psq_l1(auStack184,uVar12);
  __psq_l0(auStack200,uVar12);
  __psq_l1(auStack200,uVar12);
  __psq_l0(auStack216,uVar12);
  __psq_l1(auStack216,uVar12);
  __psq_l0(auStack232,uVar12);
  __psq_l1(auStack232,uVar12);
  __psq_l0(auStack248,uVar12);
  __psq_l1(auStack248,uVar12);
  __psq_l0(auStack264,uVar12);
  __psq_l1(auStack264,uVar12);
  __psq_l0(auStack280,uVar12);
  __psq_l1(auStack280,uVar12);
  return;
}


/* __thiscall dMap_2DAGBScrDsp_c::setPos(short,
                                         short,
                                         short,
                                         short) */

void __thiscall
dMap_2DAGBScrDsp_c::setPos
          (dMap_2DAGBScrDsp_c *this,short param_1,short param_2,short param_3,short param_4)

{
  *(short *)(this + 0x3c) = param_1;
  *(short *)(this + 0x3e) = param_2;
  *(short *)(this + 0x40) = param_3;
  *(short *)(this + 0x42) = param_4;
  return;
}


/* __thiscall dMap_2DAGBScrDsp_c::setScale(float,
                                           float) */

void __thiscall dMap_2DAGBScrDsp_c::setScale(dMap_2DAGBScrDsp_c *this,float param_1,float param_2)

{
  *(float *)(this + 0x4c) = param_1;
  *(float *)(this + 0x50) = param_2;
  return;
}


/* __thiscall dMap_2DTri_c::init(short,
                                 short,
                                 _GXColor const &,
                                 float,
                                 float,
                                 short) */

int __thiscall dMap_2DTri_c::init(dMap_2DTri_c *this,EVP_PKEY_CTX *ctx)

{
  undefined2 in_r5;
  dMap_2DTri_c *in_r6;
  undefined2 in_r7;
  double in_f1;
  double in_f2;
  
  *(short *)(this + 4) = (short)ctx;
  *(undefined2 *)(this + 6) = in_r5;
  *(float *)(this + 0x10) = (float)in_f1;
  *(float *)(this + 0x14) = (float)in_f2;
  this[8] = *in_r6;
  this[9] = in_r6[1];
  this[10] = in_r6[2];
  this[0xb] = in_r6[3];
  *(undefined2 *)(this + 0xc) = in_r7;
  return (int)this;
}


/* __thiscall dMap_2DTri_c::draw(void) */

void __thiscall dMap_2DTri_c::draw(dMap_2DTri_c *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  undefined4 local_38;
  short local_34 [4];
  short local_2c [6];
  longlong local_20;
  longlong local_18;
  
  iVar7 = (int)((int)*(short *)(this + 0xc) & 0xffffU) >> (JKernel::JMath::jmaSinShift & 0x3f);
  fVar3 = JKernel::JMath::jmaCosTable[iVar7];
  fVar4 = JKernel::JMath::jmaSinTable[iVar7];
  uVar9 = 0;
  iVar7 = 0;
  iVar10 = 3;
  do {
    fVar1 = *(float *)(this + 0x10);
    iVar8 = (int)(uVar9 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f);
    fVar5 = JKernel::JMath::jmaSinTable[iVar8];
    fVar2 = *(float *)(this + 0x14);
    fVar6 = JKernel::JMath::jmaCosTable[iVar8];
    iVar8 = (int)(fVar1 * fVar5 * fVar3 + fVar2 * fVar6 * fVar4);
    local_20 = (longlong)iVar8;
    *(short *)((int)local_2c + iVar7) = *(short *)(this + 4) + (short)iVar8;
    iVar8 = (int)(fVar2 * fVar6 * fVar3 - fVar1 * fVar5 * fVar4);
    local_18 = (longlong)iVar8;
    *(short *)((int)local_34 + iVar7) = *(short *)(this + 6) + (short)iVar8;
    uVar9 = uVar9 - 0x5555;
    iVar7 = iVar7 + 2;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  gx::GXClearVtxDesc();
  gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
  gx::GXSetNumChans(1);
  gx::GXSetChanCtrl(GX_COLOR0A0,false,GX_SRC_REG,GX_SRC_REG,0,GX_DF_NONE,GX_AF_NONE);
  local_38 = *(undefined4 *)(this + 8);
  gx::GXSetChanMatColor(4,&local_38);
  gx::GXSetNumTexGens(0);
  gx::GXSetNumTevStages(1);
  gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR0A0);
  gx::GXSetTevOp(0,4);
  gx::GXSetBlendMode(GX_BM_BLEND,GX_BL_SRCALPHA,GX_BL_INVSRCALPHA,GX_LO_SET);
  gx::GXSetZMode(false,GX_LEQUAL,false);
  gx::GXSetScissor(*(undefined4 *)(this + 0x18),*(undefined4 *)(this + 0x1c),
                   *(undefined4 *)(this + 0x20),*(undefined4 *)(this + 0x24));
  gx::GXBegin(0x90,0,3);
  write_volatile_2(0xcc008000,local_2c[0]);
  write_volatile_2(0xcc008000,local_34[0]);
  write_volatile_2(0xcc008000,0);
  write_volatile_2(0xcc008000,local_2c[1]);
  write_volatile_2(0xcc008000,local_34[1]);
  write_volatile_2(0xcc008000,0);
  write_volatile_2(0xcc008000,local_2c[2]);
  write_volatile_2(0xcc008000,local_34[2]);
  write_volatile_2(0xcc008000,0);
  gx::GXSetScissor(0,0,0x280,0x1e0);
  return;
}


/* __thiscall dMap_2DTri_c::setPos(short,
                                   short) */

void __thiscall dMap_2DTri_c::setPos(dMap_2DTri_c *this,short param_1,short param_2)

{
  *(short *)(this + 4) = param_1;
  *(short *)(this + 6) = param_2;
  return;
}


/* __thiscall dMap_2DPoint_c::init(short,
                                   short,
                                   _GXColor const &,
                                   unsigned char) */

int __thiscall dMap_2DPoint_c::init(dMap_2DPoint_c *this,EVP_PKEY_CTX *ctx)

{
  undefined2 in_r5;
  dMap_2DPoint_c *in_r6;
  dMap_2DPoint_c in_r7;
  
  *(short *)(this + 0x14) = (short)ctx;
  *(undefined2 *)(this + 0x16) = in_r5;
  this[0x18] = *in_r6;
  this[0x19] = in_r6[1];
  this[0x1a] = in_r6[2];
  this[0x1b] = in_r6[3];
  this[0x1c] = in_r7;
  return (int)this;
}


/* __thiscall dMap_2DPoint_c::draw(void) */

void __thiscall dMap_2DPoint_c::draw(dMap_2DPoint_c *this)

{
  undefined4 local_18 [5];
  
  gx::GXClearVtxDesc();
  gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
  gx::GXSetNumChans(1);
  gx::GXSetChanCtrl(GX_COLOR0A0,false,GX_SRC_REG,GX_SRC_REG,0,GX_DF_NONE,GX_AF_NONE);
  local_18[0] = *(undefined4 *)(this + 0x18);
  gx::GXSetChanMatColor(4,local_18);
  gx::GXSetNumTexGens(0);
  gx::GXSetNumTevStages(1);
  gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR0A0);
  gx::GXSetTevOp(0,4);
  gx::GXSetBlendMode(GX_BM_BLEND,GX_BL_SRCALPHA,GX_BL_INVSRCALPHA,GX_LO_SET);
  gx::GXSetPointSize(this[0x1c],0);
  gx::GXSetZMode(false,GX_LEQUAL,false);
  gx::GXSetScissor(*(undefined4 *)(this + 4),*(undefined4 *)(this + 8),*(undefined4 *)(this + 0xc),
                   *(undefined4 *)(this + 0x10));
  gx::GXBegin(0xb8,0,1);
  write_volatile_2(0xcc008000,*(undefined2 *)(this + 0x14));
  write_volatile_2(0xcc008000,*(undefined2 *)(this + 0x16));
  write_volatile_2(0xcc008000,0);
  gx::GXSetScissor(0,0,0x280,0x1e0);
  return;
}


/* __thiscall dMap_2DAGBCursor_c::init(short,
                                       short,
                                       _GXColor const &,
                                       unsigned char) */

int __thiscall dMap_2DAGBCursor_c::init(dMap_2DAGBCursor_c *this,EVP_PKEY_CTX *ctx)

{
  undefined2 in_r5;
  dMap_2DAGBCursor_c *in_r6;
  dMap_2DAGBCursor_c in_r7;
  
  *(short *)(this + 0x14) = (short)ctx;
  *(undefined2 *)(this + 0x16) = in_r5;
  this[0x18] = *in_r6;
  this[0x19] = in_r6[1];
  this[0x1a] = in_r6[2];
  this[0x1b] = in_r6[3];
  this[0x1c] = in_r7;
  return (int)this;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dMap_2DAGBCursor_c::draw(void) */

void __thiscall dMap_2DAGBCursor_c::draw(dMap_2DAGBCursor_c *this)

{
  dMap_2DAGBCursor_c dVar1;
  short sVar2;
  undefined4 local_18 [3];
  
  dVar1 = this[0x1c];
  gx::GXClearVtxDesc();
  gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
  gx::GXSetNumChans(1);
  gx::GXSetChanCtrl(GX_COLOR0A0,false,GX_SRC_REG,GX_SRC_REG,0,GX_DF_NONE,GX_AF_NONE);
  local_18[0] = *(undefined4 *)(this + 0x18);
  gx::GXSetChanMatColor(4,local_18);
  gx::GXSetNumTexGens(0);
  gx::GXSetNumTevStages(1);
  gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR0A0);
  gx::GXSetTevOp(0,4);
  gx::GXSetBlendMode(GX_BM_BLEND,GX_BL_SRCALPHA,GX_BL_INVSRCALPHA,GX_LO_SET);
  gx::GXSetPointSize((byte)dVar1 / 3,0);
  gx::GXSetZMode(false,GX_LEQUAL,false);
  gx::GXSetScissor(*(undefined4 *)(this + 4),*(undefined4 *)(this + 8),*(undefined4 *)(this + 0xc),
                   *(undefined4 *)(this + 0x10));
  gx::GXBegin(0xb8,0,5);
  write_volatile_2(0xcc008000,*(undefined2 *)(this + 0x14));
  write_volatile_2(0xcc008000,*(undefined2 *)(this + 0x16));
  write_volatile_2(0xcc008000,0);
  sVar2 = (short)(((byte)dVar1 / 3) / 6);
  write_volatile_2(0xcc008000,*(short *)(this + 0x14) + sVar2);
  write_volatile_2(0xcc008000,*(undefined2 *)(this + 0x16));
  write_volatile_2(0xcc008000,0);
  write_volatile_2(0xcc008000,*(short *)(this + 0x14) - sVar2);
  write_volatile_2(0xcc008000,*(undefined2 *)(this + 0x16));
  write_volatile_2(0xcc008000,0);
  write_volatile_2(0xcc008000,*(undefined2 *)(this + 0x14));
  write_volatile_2(0xcc008000,*(short *)(this + 0x16) + sVar2);
  write_volatile_2(0xcc008000,0);
  write_volatile_2(0xcc008000,*(undefined2 *)(this + 0x14));
  write_volatile_2(0xcc008000,*(short *)(this + 0x16) - sVar2);
  write_volatile_2(0xcc008000,0);
  gx::GXSetScissor(0,0,0x280,0x1e0);
  return;
}


/* WARNING: Removing unreachable block (ram,0x8004f754) */
/* WARNING: Removing unreachable block (ram,0x8004f744) */
/* WARNING: Removing unreachable block (ram,0x8004f734) */
/* WARNING: Removing unreachable block (ram,0x8004f73c) */
/* WARNING: Removing unreachable block (ram,0x8004f74c) */
/* WARNING: Removing unreachable block (ram,0x8004f75c) */
/* __thiscall dMap_2DT2_c::draw(void) */

void __thiscall dMap_2DT2_c::draw(dMap_2DT2_c *this)

{
  float fVar1;
  undefined4 uVar2;
  double dVar3;
  double dVar4;
  undefined8 in_f26;
  undefined8 in_f27;
  double dVar5;
  undefined8 in_f28;
  undefined8 in_f29;
  double dVar6;
  undefined8 in_f30;
  double dVar7;
  undefined8 in_f31;
  double dVar8;
  _GXColor local_78;
  _GXColor local_74;
  _GXColor local_70 [3];
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar2 = 0;
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
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGB,GX_F32,0);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX0,GX_CLR_RGBA,GX_F32,0);
  gx::GXClearVtxDesc();
  gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
  gx::GXSetVtxDesc(GX_VA_TEX0,GX_DIRECT);
  gx::GXLoadTexObj((GXTexObj *)(this + 4),0);
  gx::GXSetNumChans(0);
  local_70[0] = *(_GXColor *)(this + 0x3c);
  gx::GXSetTevColor(GX_TEVREG0,local_70);
  local_74 = *(_GXColor *)(this + 0x40);
  gx::GXSetTevColor(GX_TEVREG1,&local_74);
  gx::GXSetNumTexGens(1);
  gx::GXSetTexCoordGen2(GX_TEXCOORD0,GX_TG_MTX2x4,GX_TG_TEX0,GX_IDENTITY,false,GX_PTIDENTITY);
  gx::GXSetNumTevStages(1);
  gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD0,GX_TEXMAP0,GX_COLOR_NULL);
  gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_C1,GX_CC_C0,GX_CC_TEXC,GX_CC_ZERO);
  gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  if (this[0x58] == (dMap_2DT2_c)0x0) {
    gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_A0,GX_CA_TEXA,GX_CA_ZERO);
  }
  else {
    gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_A0);
  }
  gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetZCompLoc(0);
  gx::GXSetZMode(false,GX_ALWAYS,false);
  gx::GXSetBlendMode(GX_BM_BLEND,GX_BL_SRCALPHA,GX_BL_INVSRCALPHA,GX_LO_CLEAR);
  gx::GXSetAlphaCompare(GX_GREATER,0,GX_AOP_OR,GX_GREATER,0);
  local_78 = d_com_inf_game::g_clearColor;
  gx::GXSetFog(GX_FOG_NONE,d_map::_4426,d_map::_4426,d_map::_4426,d_map::_4426,&local_78);
  gx::GXSetCullMode(0);
  gx::GXSetDither(1);
  gx::GXSetClipMode(true);
  mtx::PSMTXTrans((double)*(float *)(this + 0x24),(double)*(float *)(this + 0x28),
                  (double)d_map::_4426,&mDoMtx_stack_c::now);
  m_Do_mtx::mDoMtx_ZrotM(&mDoMtx_stack_c::now,*(short *)(this + 0x54));
  gx::GXLoadPosMtxImm(&mDoMtx_stack_c::now,0);
  gx::GXSetCurrentMtx(0);
  gx::GXSetScissor(*(undefined4 *)(this + 0x44),*(undefined4 *)(this + 0x48),
                   *(undefined4 *)(this + 0x4c),*(undefined4 *)(this + 0x50));
  dVar8 = (double)(d_map::_4929 * *(float *)(this + 0x2c));
  dVar7 = (double)(d_map::_4929 * *(float *)(this + 0x30));
  dVar3 = (double)d_map::_4426;
  dVar6 = dVar3;
  if (dVar3 != (double)*(float *)(this + 0x34)) {
    fVar1 = d_map::_4929 * (float)((double)d_map::_4611 / (double)*(float *)(this + 0x34));
    dVar3 = (double)(d_map::_4929 + fVar1);
    dVar6 = (double)(d_map::_4929 - fVar1);
  }
  dVar4 = (double)d_map::_4426;
  dVar5 = dVar4;
  if (dVar4 != (double)*(float *)(this + 0x38)) {
    fVar1 = d_map::_4929 * (float)((double)d_map::_4611 / (double)*(float *)(this + 0x38));
    dVar4 = (double)(d_map::_4929 + fVar1);
    dVar5 = (double)(d_map::_4929 - fVar1);
  }
  gx::GXBegin(0x80,0,4);
  write_volatile_4(0xcc008000,(float)-dVar8);
  write_volatile_4(0xcc008000,(float)-dVar7);
  write_volatile_4(0xcc008000,(float)dVar6);
  write_volatile_4(0xcc008000,(float)dVar5);
  write_volatile_4(0xcc008000,(float)dVar8);
  write_volatile_4(0xcc008000,(float)-dVar7);
  write_volatile_4(0xcc008000,(float)dVar3);
  write_volatile_4(0xcc008000,(float)dVar5);
  write_volatile_4(0xcc008000,(float)dVar8);
  write_volatile_4(0xcc008000,(float)dVar7);
  write_volatile_4(0xcc008000,(float)dVar3);
  write_volatile_4(0xcc008000,(float)dVar4);
  write_volatile_4(0xcc008000,(float)-dVar8);
  write_volatile_4(0xcc008000,(float)dVar7);
  write_volatile_4(0xcc008000,(float)dVar6);
  write_volatile_4(0xcc008000,(float)dVar4);
  gx::GXSetScissor(0,0,0x280,0x1e0);
  (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph)->parent).vtbl)->setup2D)();
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  __psq_l0(auStack24,uVar2);
  __psq_l1(auStack24,uVar2);
  __psq_l0(auStack40,uVar2);
  __psq_l1(auStack40,uVar2);
  __psq_l0(auStack56,uVar2);
  __psq_l1(auStack56,uVar2);
  __psq_l0(auStack72,uVar2);
  __psq_l1(auStack72,uVar2);
  __psq_l0(auStack88,uVar2);
  __psq_l1(auStack88,uVar2);
  return;
}


/* WARNING: Inlined function: FUN_80328e9c */
/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328ee8 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dMap_2DT2_c::init(ResTIMG *,
                                float,
                                float,
                                float,
                                float,
                                unsigned char,
                                unsigned char,
                                unsigned char,
                                float,
                                float,
                                short) */

int __thiscall dMap_2DT2_c::init(dMap_2DT2_c *this,EVP_PKEY_CTX *ctx)

{
  undefined4 uVar1;
  int iVar2;
  dMap_2DT2_c in_r5;
  dMap_2DT2_c in_r6;
  dMap_2DT2_c in_r7;
  undefined2 in_r8;
  double in_f1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  dMap_2DT2_c local_58;
  dMap_2DT2_c dStack87;
  dMap_2DT2_c dStack86;
  dMap_2DT2_c dStack85;
  dMap_2DT2_c local_54;
  dMap_2DT2_c dStack83;
  dMap_2DT2_c dStack82;
  dMap_2DT2_c dStack81;
  
  iVar2 = m_Do_lib::mDoLib_setResTimgObj((ResTIMG *)ctx,this + 4,0,(GXTlutObj *)0x0);
  *(float *)(this + 0x24) = (float)in_f1;
  *(float *)(this + 0x28) = (float)in_f2;
  *(float *)(this + 0x2c) = (float)in_f3;
  *(float *)(this + 0x30) = (float)in_f4;
  *(float *)(this + 0x34) = (float)in_f5;
  *(float *)(this + 0x38) = (float)in_f6;
  *(undefined2 *)(this + 0x54) = in_r8;
  uVar1 = d_map::_7779;
  local_54 = SUB41((uint)d_map::_7779 >> 0x18,0);
  this[0x3c] = local_54;
  dStack83 = SUB41((uint)uVar1 >> 0x10,0);
  this[0x3d] = dStack83;
  dStack82 = SUB41((uint)uVar1 >> 8,0);
  this[0x3e] = dStack82;
  dStack81 = SUB41(uVar1,0);
  this[0x3f] = dStack81;
  uVar1 = d_map::_7781;
  local_58 = SUB41((uint)d_map::_7781 >> 0x18,0);
  this[0x40] = local_58;
  dStack87 = SUB41((uint)uVar1 >> 0x10,0);
  this[0x41] = dStack87;
  dStack86 = SUB41((uint)uVar1 >> 8,0);
  this[0x42] = dStack86;
  dStack85 = SUB41(uVar1,0);
  this[0x43] = dStack85;
  this[0x56] = in_r6;
  if ((this[0x56] != (dMap_2DT2_c)0x0) && (iVar2 = gx::GXGetTexObjWrapS(this + 4), iVar2 == 2)) {
    this[0x56] = (dMap_2DT2_c)0x0;
  }
  this[0x57] = in_r7;
  if ((this[0x57] != (dMap_2DT2_c)0x0) && (iVar2 = gx::GXGetTexObjWrapT(this + 4), iVar2 == 2)) {
    this[0x57] = (dMap_2DT2_c)0x0;
  }
  this[0x58] = in_r5;
  return iVar2;
}


/* WARNING: Inlined function: FUN_80328f1c */
/* WARNING: Inlined function: FUN_80328f68 */
/* WARNING: Removing unreachable block (ram,0x8004fc48) */
/* __thiscall dMap_Dmap_c::setTlut(dmap_dmap_tlut_s *,
                                   unsigned char,
                                   unsigned char,
                                   unsigned char,
                                   float) */

void __thiscall
dMap_Dmap_c::setTlut
          (dMap_Dmap_c *this,dmap_dmap_tlut_s *param_1,uchar param_2,uchar param_3,uchar param_4,
          float param_5)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  stage_stag_info_class *pStag;
  int iVar4;
  undefined3 in_register_00000014;
  char *pcVar5;
  ushort *puVar6;
  undefined4 uVar7;
  undefined8 in_f31;
  double dVar8;
  undefined auStack8 [8];
  
  dVar8 = (double)param_5;
  uVar7 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  uVar2 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getFloorInfo)
                    (0x803c9d58);
  iVar3 = d_map::dMap_GetFloorInfoDtPFromFloorNo(uVar2,CONCAT31(in_register_00000014,param_2));
  if (iVar3 != 0) {
    if ((double)d_map::_4611 < dVar8) {
      dVar8 = (double)(float)((double)d_map::_4611 - dVar8);
    }
    pcVar5 = (char *)(iVar3 + 5);
    iVar3 = 0;
    do {
      if (*pcVar5 != -1) {
        puVar6 = (ushort *)0x0;
        if (-1 < (char)this[iVar3 + -0x4f4 + (uint)param_2 * 0x10]) {
          puVar6 = (ushort *)(param_1 + (char)this[iVar3 + -0x4f4 + (uint)param_2 * 0x10] * 2);
        }
        if (puVar6 != (ushort *)0x0) {
          pStag = (stage_stag_info_class *)
                  (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->
                            getStagInfo)(0x803c9d58);
          if (((pStag->mStageTypeAndSchbit >> 0x10 & 7) == 3) || ((int)*pcVar5 != (uint)param_3)) {
            iVar4 = dSv_memBit_c::isDungeonItem
                              ((dSv_memBit_c *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMemory,0
                              );
            if (iVar4 == 0) {
              iVar4 = dSv_memBit_c::isVisitedRoom
                                ((dSv_memBit_c *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMemory
                                 ,(int)*pcVar5);
              if (iVar4 == 0) {
                if (UNK_803f82e7 < 0xe0) {
                  uVar1 = (UNK_803f82e7 & 0xe0) << 7 |
                          (ushort)(UNK_803f82e6 >> 4) |
                          (d_map::color_off_map_none_7800 & 0xf0) << 4 | UNK_803f82e5 & 0xf0;
                }
                else {
                  uVar1 = (ushort)(UNK_803f82e6 >> 3) |
                          (d_map::color_off_map_none_7800 & 0xf8) << 7 | (UNK_803f82e5 & 0xf8) << 2
                          | 0x8000;
                }
                *puVar6 = uVar1;
              }
              else {
                if (UNK_803f82df < 0xe0) {
                  uVar1 = (UNK_803f82df & 0xe0) << 7 |
                          (ushort)(UNK_803f82de >> 4) |
                          (d_map::color_on_7798 & 0xf0) << 4 | UNK_803f82dd & 0xf0;
                }
                else {
                  uVar1 = (ushort)(UNK_803f82de >> 3) |
                          (d_map::color_on_7798 & 0xf8) << 7 | (UNK_803f82dd & 0xf8) << 2 | 0x8000;
                }
                *puVar6 = uVar1;
              }
            }
            else {
              iVar4 = dSv_memBit_c::isVisitedRoom
                                ((dSv_memBit_c *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMemory
                                 ,(int)*pcVar5);
              if (iVar4 == 0) {
                if (UNK_803f82e3 < 0xe0) {
                  uVar1 = (UNK_803f82e3 & 0xe0) << 7 |
                          (ushort)(UNK_803f82e2 >> 4) |
                          (d_map::color_off_map_possession_7799 & 0xf0) << 4 | UNK_803f82e1 & 0xf0;
                }
                else {
                  uVar1 = (ushort)(UNK_803f82e2 >> 3) |
                          (d_map::color_off_map_possession_7799 & 0xf8) << 7 |
                          (UNK_803f82e1 & 0xf8) << 2 | 0x8000;
                }
                *puVar6 = uVar1;
              }
              else {
                if (UNK_803f82df < 0xe0) {
                  uVar1 = (UNK_803f82df & 0xe0) << 7 |
                          (ushort)(UNK_803f82de >> 4) |
                          (d_map::color_on_7798 & 0xf0) << 4 | UNK_803f82dd & 0xf0;
                }
                else {
                  uVar1 = (ushort)(UNK_803f82de >> 3) |
                          (d_map::color_on_7798 & 0xf8) << 7 | (UNK_803f82dd & 0xf8) << 2 | 0x8000;
                }
                *puVar6 = uVar1;
              }
            }
          }
          else {
            *puVar6 = (ushort)((uint)(int)((float)((double)CONCAT44(0x43300000,(uint)UNK_803f82ea) -
                                                  d_map::_4820) +
                                          (float)(dVar8 * (double)(float)((double)CONCAT44(
                                                  0x43300000,
                                                  (uint)UNK_803f82de - (uint)UNK_803f82ea ^
                                                  0x80000000) - d_map::_4818))) >> 3) & 0x1f |
                      (ushort)((int)((float)((double)CONCAT44(0x43300000,
                                                              (uint)d_map::flash_color_7801) -
                                            d_map::_4820) +
                                    (float)(dVar8 * (double)(float)((double)CONCAT44(0x43300000,
                                                                                     (uint)d_map::
                                                  color_on_7798 - (uint)d_map::flash_color_7801 ^
                                                  0x80000000) - d_map::_4818))) << 7) & 0x7c00 |
                      (ushort)((int)((float)((double)CONCAT44(0x43300000,(uint)UNK_803f82e9) -
                                            d_map::_4820) +
                                    (float)(dVar8 * (double)(float)((double)CONCAT44(0x43300000,
                                                                                     (uint)
                                                  UNK_803f82dd - (uint)UNK_803f82e9 ^ 0x80000000) -
                                                  d_map::_4818))) << 2) & 0x3e0 | 0x8000;
          }
        }
      }
      iVar3 = iVar3 + 1;
      pcVar5 = pcVar5 + 1;
    } while (iVar3 < 0xe);
  }
  os::DCStoreRange(param_1,0x20);
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  return;
}


/* WARNING: Inlined function: FUN_80328f24 */
/* WARNING: Inlined function: FUN_80328f70 */
/* WARNING: Removing unreachable block (ram,0x8004ffa8) */
/* __thiscall dMap_Dmap_c::setFloorTextureOne(unsigned char) */

void __thiscall dMap_Dmap_c::setFloorTextureOne(dMap_Dmap_c *this,uchar param_1)

{
  bool bVar1;
  undefined *puVar2;
  ulong uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  undefined8 in_f31;
  double dVar11;
  char acStack112 [32];
  undefined4 local_50;
  uint uStack76;
  undefined4 local_48;
  uint uStack68;
  undefined4 local_40;
  uint uStack60;
  undefined auStack8 [8];
  
  uVar10 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  iVar7 = param_1 - 0x7b;
  if ((iVar7 <= (int)((byte)this[0x2b4] - 0x7b)) && ((int)((byte)this[0x2b5] - 0x7b) <= iVar7)) {
    MSL_C.PPCEABI.bare.H::sprintf(acStack112,"dmap%d.bti");
    puVar2 = (undefined *)
             dRes_control_c::getRes
                       ("Stage",acStack112,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mStageInfo,
                        0x40);
    if (puVar2 != (undefined *)0x0) {
      *(ushort *)(this + 0x36e) = *(ushort *)(this + 0x36e) | (ushort)(1 << iVar7);
      iVar4 = 0;
      iVar8 = 0x10;
      do {
        (this + iVar7 * 0x10)[iVar4 + 699] = (dMap_Dmap_c)0xff;
        iVar4 = iVar4 + 1;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
      iVar8 = 0;
      iVar4 = 0;
      do {
        iVar6 = 0;
        iVar5 = 0;
        iVar9 = 0x10;
        do {
          if (*(short *)(puVar2 + *(int *)(puVar2 + 0xc) + iVar4) ==
              *(short *)((int)&d_map::l_indexColor_7884 + iVar5)) break;
          iVar6 = iVar6 + 1;
          iVar5 = iVar5 + 2;
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
        if (iVar6 != 0x10) {
          (this + iVar7 * 0x10)[iVar6 + 699] = SUB41(iVar8,0);
        }
        iVar8 = iVar8 + 1;
        iVar4 = iVar4 + 2;
      } while (iVar8 < 0x10);
      iVar8 = 0;
      iVar6 = 0;
      iVar5 = 0;
      iVar4 = iVar7 * 0x20;
      do {
        FUN_800033a8((int)(this + iVar5 + iVar4 + 0x20),0,0x20);
        gx::GXInitTlutObj(this + iVar6 + iVar7 * 0xc + 0x4b0,this + iVar5 + iVar4 + 0x20,puVar2[9],
                          *(undefined2 *)(puVar2 + 10));
        if (*(short *)(puVar2 + 10) != 0x10) {
          uVar3 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar3,"d_map.cpp",0x2899,"imageP->numColors == (16)");
          m_Do_printf::OSPanic("d_map.cpp",0x2899,&DAT_8034f1dd);
        }
        iVar8 = iVar8 + 1;
        iVar6 = iVar6 + 0x78;
        iVar5 = iVar5 + 0x140;
      } while (iVar8 < 2);
      gx::GXInitTexObjCI(this + iVar4 + 0x370,puVar2 + *(int *)(puVar2 + 0x1c),
                         *(undefined2 *)(puVar2 + 2),*(undefined2 *)(puVar2 + 4),*puVar2,puVar2[6],
                         puVar2[7],1 - (byte)puVar2[0x18] >> 0x1f,iVar7);
      uStack76 = (int)(char)puVar2[0x16] ^ 0x80000000;
      local_50 = 0x43300000;
      uStack68 = (int)(char)puVar2[0x17] ^ 0x80000000;
      local_48 = 0x43300000;
      uStack60 = (int)*(short *)(puVar2 + 0x1a) ^ 0x80000000;
      local_40 = 0x43300000;
      gx::GXInitTexObjLOD((double)(d_map::_7319 *
                                  (float)((double)CONCAT44(0x43300000,uStack76) - d_map::_4818)),
                          (double)(d_map::_7319 *
                                  (float)((double)CONCAT44(0x43300000,uStack68) - d_map::_4818)),
                          (double)(d_map::_7320 *
                                  (float)((double)CONCAT44(0x43300000,uStack60) - d_map::_4818)),
                          this + iVar4 + 0x370,puVar2[0x14],puVar2[0x15],puVar2[0x12],puVar2[0x11],
                          puVar2[0x13]);
      bVar1 = false;
      if ((this[0x2b7] == (dMap_Dmap_c)0x0) || (this[0x2b7] == (dMap_Dmap_c)0x1)) {
        bVar1 = true;
      }
      if (!bVar1) {
        uVar3 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert
                  (uVar3,"d_map.cpp",0x28b3,"(mNowTlutDblBufNo == 0) || (mNowTlutDblBufNo == 1)");
        m_Do_printf::OSPanic("d_map.cpp",0x28b3,&DAT_8034f1dd);
      }
      iVar7 = 0;
      iVar8 = 0;
      dVar11 = d_map::_4820;
      do {
        uStack60 = (uint)(byte)this[0x2ba];
        local_40 = 0x43300000;
        setTlut(this,(dmap_dmap_tlut_s *)(this + iVar8 + iVar4 + 0x20),param_1,(uchar)this[0x2b8],
                (uchar)this[0x2b9],(float)((double)CONCAT44(0x43300000,uStack60) - dVar11));
        iVar7 = iVar7 + 1;
        iVar8 = iVar8 + 0x140;
      } while (iVar7 < 2);
    }
  }
  __psq_l0(auStack8,uVar10);
  __psq_l1(auStack8,uVar10);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dMap_Dmap_c::init(short,
                                short,
                                short,
                                short,
                                short,
                                short,
                                short,
                                short,
                                short,
                                unsigned char,
                                unsigned char,
                                unsigned char,
                                unsigned char,
                                unsigned char) */

int __thiscall dMap_Dmap_c::init(dMap_Dmap_c *this,EVP_PKEY_CTX *ctx)

{
  int iVar1;
  ulong uVar2;
  void *pvVar3;
  int iVar4;
  undefined2 in_r5;
  undefined2 in_r6;
  undefined2 in_r7;
  undefined2 in_r8;
  undefined2 in_r9;
  _GXTexFmt *p_Var5;
  undefined2 in_r10;
  undefined2 in_stack_0000000a;
  undefined2 in_stack_0000000e;
  dMap_Dmap_c in_stack_00000013;
  dMap_Dmap_c in_stack_00000017;
  dMap_Dmap_c in_stack_0000001b;
  dMap_Dmap_c in_stack_0000001f;
  dMap_Dmap_c in_stack_00000023;
  
  *(short *)(this + 0x35c) = (short)ctx;
  *(undefined2 *)(this + 0x35e) = in_r5;
  *(undefined2 *)(this + 0x360) = in_r6;
  *(undefined2 *)(this + 0x362) = in_r7;
  *(undefined2 *)(this + 0x364) = in_r8;
  *(undefined2 *)(this + 0x366) = in_r9;
  *(undefined2 *)(this + 0x368) = in_r10;
  *(undefined2 *)(this + 0x36a) = in_stack_0000000a;
  *(undefined2 *)(this + 0x36c) = in_stack_0000000e;
  this[0x2b4] = in_stack_00000013;
  this[0x2b5] = in_stack_00000017;
  this[0x2b8] = in_stack_0000001b;
  this[0x2b9] = in_stack_0000001f;
  this[0x2b6] = in_stack_00000023;
  this[0x2b7] = (dMap_Dmap_c)0x0;
  this[0x2ba] = (dMap_Dmap_c)0x0;
  *(undefined2 *)(this + 0x36e) = 0;
  iVar1 = JKRArchive::getGlbResource(0x54494d47,"dtmap_mask.bti",*(JKRArchive **)(this + 0x2a0));
  *(int *)(this + 0x2a4) = iVar1;
  if (*(int *)(this + 0x2a4) == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_map.cpp",0x2908,"mImageP != 0");
    m_Do_printf::OSPanic("d_map.cpp",0x2908,&DAT_8034f1dd);
  }
  iVar1 = JKRArchive::getGlbResource(0x54494d47,"menu_note_02_2.bti",*(JKRArchive **)(this + 0x2a0))
  ;
  *(int *)(this + 0x2a8) = iVar1;
  if (*(int *)(this + 0x2a8) == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_map.cpp",0x290f,"mImageSeetP !=0");
    m_Do_printf::OSPanic("d_map.cpp",0x290f,&DAT_8034f1dd);
  }
  iVar1 = JKRArchive::getGlbResource(0x54494d47,"grid_32.bti",*(JKRArchive **)(this + 0x2a0));
  *(int *)(this + 0x2ac) = iVar1;
  if (*(int *)(this + 0x2ac) == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_map.cpp",0x2917,"mImageGridP !=0");
    m_Do_printf::OSPanic("d_map.cpp",0x2917,&DAT_8034f1dd);
  }
  pvVar3 = dRes_control_c::getRes
                     ("Stage","dmap_back.bti",d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mStageInfo
                      ,0x40);
  *(void **)(this + 0x2b0) = pvVar3;
  p_Var5 = *(_GXTexFmt **)(this + 0x2a4);
  gx::GXInitTexObj((GXTexObj *)(this + 0x5c0),p_Var5 + *(int *)(p_Var5 + 0x1c),
                   (uint)*(ushort *)(p_Var5 + 2),(uint)*(ushort *)(p_Var5 + 4),*p_Var5,p_Var5[6],
                   p_Var5[7],SUB41(1 - (uint)p_Var5[0x18] >> 0x1f,0));
  iVar1 = *(int *)(this + 0x2a4);
  gx::GXInitTexObjLOD((double)(d_map::_7319 *
                              (float)((double)CONCAT44(0x43300000,
                                                       (int)*(char *)(iVar1 + 0x16) ^ 0x80000000) -
                                     d_map::_4818)),
                      (double)(d_map::_7319 *
                              (float)((double)CONCAT44(0x43300000,
                                                       (int)*(char *)(iVar1 + 0x17) ^ 0x80000000) -
                                     d_map::_4818)),
                      (double)(d_map::_7320 *
                              (float)((double)CONCAT44(0x43300000,
                                                       (int)*(short *)(iVar1 + 0x1a) ^ 0x80000000) -
                                     d_map::_4818)),this + 0x5c0,*(undefined *)(iVar1 + 0x14),
                      *(undefined *)(iVar1 + 0x15),*(undefined *)(iVar1 + 0x12),
                      *(undefined *)(iVar1 + 0x11),*(undefined *)(iVar1 + 0x13));
  p_Var5 = *(_GXTexFmt **)(this + 0x2a8);
  gx::GXInitTexObj((GXTexObj *)(this + 0x5a0),p_Var5 + *(int *)(p_Var5 + 0x1c),
                   (uint)*(ushort *)(p_Var5 + 2),(uint)*(ushort *)(p_Var5 + 4),*p_Var5,p_Var5[6],
                   p_Var5[7],SUB41(1 - (uint)p_Var5[0x18] >> 0x1f,0));
  iVar1 = *(int *)(this + 0x2a8);
  gx::GXInitTexObjLOD((double)(d_map::_7319 *
                              (float)((double)CONCAT44(0x43300000,
                                                       (int)*(char *)(iVar1 + 0x16) ^ 0x80000000) -
                                     d_map::_4818)),
                      (double)(d_map::_7319 *
                              (float)((double)CONCAT44(0x43300000,
                                                       (int)*(char *)(iVar1 + 0x17) ^ 0x80000000) -
                                     d_map::_4818)),
                      (double)(d_map::_7320 *
                              (float)((double)CONCAT44(0x43300000,
                                                       (int)*(short *)(iVar1 + 0x1a) ^ 0x80000000) -
                                     d_map::_4818)),this + 0x5a0,*(undefined *)(iVar1 + 0x14),
                      *(undefined *)(iVar1 + 0x15),*(undefined *)(iVar1 + 0x12),
                      *(undefined *)(iVar1 + 0x11),*(undefined *)(iVar1 + 0x13));
  p_Var5 = *(_GXTexFmt **)(this + 0x2ac);
  gx::GXInitTexObj((GXTexObj *)(this + 0x5e0),p_Var5 + *(int *)(p_Var5 + 0x1c),
                   (uint)*(ushort *)(p_Var5 + 2),(uint)*(ushort *)(p_Var5 + 4),*p_Var5,p_Var5[6],
                   p_Var5[7],SUB41(1 - (uint)p_Var5[0x18] >> 0x1f,0));
  iVar1 = *(int *)(this + 0x2ac);
  gx::GXInitTexObjLOD((double)(d_map::_7319 *
                              (float)((double)CONCAT44(0x43300000,
                                                       (int)*(char *)(iVar1 + 0x16) ^ 0x80000000) -
                                     d_map::_4818)),
                      (double)(d_map::_7319 *
                              (float)((double)CONCAT44(0x43300000,
                                                       (int)*(char *)(iVar1 + 0x17) ^ 0x80000000) -
                                     d_map::_4818)),
                      (double)(d_map::_7320 *
                              (float)((double)CONCAT44(0x43300000,
                                                       (int)*(short *)(iVar1 + 0x1a) ^ 0x80000000) -
                                     d_map::_4818)),this + 0x5e0,*(undefined *)(iVar1 + 0x14),
                      *(undefined *)(iVar1 + 0x15),*(undefined *)(iVar1 + 0x12),
                      *(undefined *)(iVar1 + 0x11),*(undefined *)(iVar1 + 0x13));
  p_Var5 = *(_GXTexFmt **)(this + 0x2b0);
  if (p_Var5 != (_GXTexFmt *)0x0) {
    gx::GXInitTexObj((GXTexObj *)(this + 0x600),p_Var5 + *(int *)(p_Var5 + 0x1c),
                     (uint)*(ushort *)(p_Var5 + 2),(uint)*(ushort *)(p_Var5 + 4),*p_Var5,p_Var5[6],
                     p_Var5[7],SUB41(1 - (uint)p_Var5[0x18] >> 0x1f,0));
    iVar1 = *(int *)(this + 0x2b0);
    gx::GXInitTexObjLOD((double)(d_map::_7319 *
                                (float)((double)CONCAT44(0x43300000,
                                                         (int)*(char *)(iVar1 + 0x16) ^ 0x80000000)
                                       - d_map::_4818)),
                        (double)(d_map::_7319 *
                                (float)((double)CONCAT44(0x43300000,
                                                         (int)*(char *)(iVar1 + 0x17) ^ 0x80000000)
                                       - d_map::_4818)),
                        (double)(d_map::_7320 *
                                (float)((double)CONCAT44(0x43300000,
                                                         (int)*(short *)(iVar1 + 0x1a) ^ 0x80000000)
                                       - d_map::_4818)),this + 0x600,*(undefined *)(iVar1 + 0x14),
                        *(undefined *)(iVar1 + 0x15),*(undefined *)(iVar1 + 0x12),
                        *(undefined *)(iVar1 + 0x11),*(undefined *)(iVar1 + 0x13));
  }
  iVar1 = 0;
  do {
    iVar4 = setFloorTextureOne(this,(char)iVar1 + '{');
    iVar1 = iVar1 + 1;
  } while (iVar1 < 10);
  return iVar4;
}


/* WARNING: Inlined function: FUN_80328f10 */
/* WARNING: Inlined function: FUN_80328f5c */
/* WARNING: Removing unreachable block (ram,0x80051784) */
/* WARNING: Removing unreachable block (ram,0x80051774) */
/* WARNING: Removing unreachable block (ram,0x80051764) */
/* WARNING: Removing unreachable block (ram,0x80051754) */
/* WARNING: Removing unreachable block (ram,0x8005174c) */
/* WARNING: Removing unreachable block (ram,0x8005175c) */
/* WARNING: Removing unreachable block (ram,0x8005176c) */
/* WARNING: Removing unreachable block (ram,0x8005177c) */
/* WARNING: Removing unreachable block (ram,0x8005178c) */
/* __thiscall dMap_Dmap_c::draw(void) */

void __thiscall dMap_Dmap_c::draw(dMap_Dmap_c *this)

{
  short sVar1;
  short sVar2;
  bool bVar3;
  uint3 uVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  ulong uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  GXTexObj *pGVar13;
  undefined4 uVar14;
  double dVar15;
  double dVar16;
  undefined8 in_f23;
  double dVar17;
  double dVar18;
  undefined8 in_f24;
  double dVar19;
  undefined8 in_f25;
  double dVar20;
  undefined8 in_f26;
  double dVar21;
  undefined8 in_f27;
  double dVar22;
  undefined8 in_f28;
  double dVar23;
  undefined8 in_f29;
  double dVar24;
  undefined8 in_f30;
  undefined8 in_f31;
  _GXColor local_2e8;
  _GXColor local_2e4;
  undefined4 local_2e0;
  undefined4 local_2dc;
  int local_2d8;
  _GXColor local_2d4;
  _GXColor local_2d0;
  undefined4 local_2cc;
  undefined4 local_2c8;
  int local_2c4;
  undefined auStack704 [432];
  undefined4 local_110;
  uint uStack268;
  undefined4 local_108;
  uint uStack260;
  undefined4 local_100;
  uint uStack252;
  undefined4 local_f8;
  uint uStack244;
  undefined4 local_f0;
  uint uStack236;
  undefined4 local_e8;
  uint uStack228;
  undefined4 local_e0;
  uint uStack220;
  undefined4 local_d8;
  uint uStack212;
  undefined auStack136 [16];
  undefined auStack120 [16];
  undefined auStack104 [16];
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar14 = 0;
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
  uStack268 = (int)*(short *)(this + 0x362) ^ 0x80000000;
  local_110 = 0x43300000;
  if (d_map::_4426 == (float)((double)CONCAT44(0x43300000,uStack268) - d_map::_4818)) {
    uVar9 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar9,"d_map.cpp",0x29a7,"mMaskHeight != 0.0f");
    m_Do_printf::OSPanic("d_map.cpp",0x29a7,&DAT_8034f1dd);
  }
  uStack268 = (int)*(short *)(this + 0x368) ^ 0x80000000;
  local_110 = 0x43300000;
  dVar22 = (double)((float)((double)CONCAT44(0x43300000,uStack268) - d_map::_4818) * d_map::_8200);
  uStack260 = (int)*(short *)(this + 0x36a) ^ 0x80000000;
  local_108 = 0x43300000;
  dVar21 = (double)((float)((double)CONCAT44(0x43300000,uStack260) - d_map::_4818) * d_map::_8200);
  uStack252 = gx::GXGetTexObjWidth(this + 0x5e0);
  uStack252 = uStack252 & 0xffff;
  local_100 = 0x43300000;
  dVar17 = (double)(d_map::_4611 / (float)((double)CONCAT44(0x43300000,uStack252) - d_map::_4820));
  uStack244 = gx::GXGetTexObjHeight(this + 0x5e0);
  uStack244 = uStack244 & 0xffff;
  local_f8 = 0x43300000;
  dVar20 = (double)(d_map::_4611 / (float)((double)CONCAT44(0x43300000,uStack244) - d_map::_4820));
  dVar15 = (double)f_op_msg_mng::fopMsgM_valueIncrease(0x28,this[0x2ba],2);
  dVar15 = (double)(float)((double)d_map::_6067 * dVar15);
  if ((double)d_map::_4611 < dVar15) {
    dVar15 = (double)(float)((double)d_map::_6067 - dVar15);
  }
  sVar1 = *(short *)(this + 0x362);
  sVar2 = *(short *)(this + 0x35e);
  sVar5 = *(short *)(this + 0x364) - (*(short *)(this + 0x368) >> 1);
  sVar6 = *(short *)(this + 0x364) + (*(short *)(this + 0x368) >> 1);
  sVar7 = *(short *)(this + 0x366) +
          *(short *)(this + 0x36c) + (*(short *)(this + 0x36a) + *(short *)(this + 0x36c)) * 4 +
          (*(short *)(this + 0x36a) >> 1);
  gx::GXGetVtxAttrFmtv(0,auStack704);
  gx::GXLoadPosMtxImm(&m_Do_mtx::g_mDoMtx_identity,0);
  gx::GXSetCurrentMtx(0);
  bVar3 = false;
  if ((this[0x2b7] == (dMap_Dmap_c)0x0) || (this[0x2b7] == (dMap_Dmap_c)0x1)) {
    bVar3 = true;
  }
  if (!bVar3) {
    uVar9 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar9,"d_map.h",0x170,"(mNowTlutDblBufNo == 0) || (mNowTlutDblBufNo == 1)");
    m_Do_printf::OSPanic("d_map.h",0x170,&DAT_8034f1dd);
  }
  this[0x2b7] = (dMap_Dmap_c)('\x01' - (char)this[0x2b7]);
  bVar3 = false;
  if ((this[0x2b7] == (dMap_Dmap_c)0x0) || (this[0x2b7] == (dMap_Dmap_c)0x1)) {
    bVar3 = true;
  }
  if (!bVar3) {
    uVar9 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar9,"d_map.h",0x165,"(mNowTlutDblBufNo == 0) || (mNowTlutDblBufNo == 1)");
    m_Do_printf::OSPanic("d_map.h",0x165,&DAT_8034f1dd);
  }
  iVar12 = 0;
  iVar11 = 0;
  iVar10 = 0;
  dVar17 = (double)(float)((double)d_map::_5209 - dVar17);
  do {
    if (sVar7 < 0x1e1) {
      sVar8 = sVar7 + *(short *)(this + 0x36a);
      if (sVar8 < 0) break;
      if (((((uint)*(ushort *)(this + 0x36e) & 1 << iVar12) != 0) &&
          (iVar12 <= (int)((byte)this[0x2b4] - 0x7b))) &&
         ((int)((byte)this[0x2b5] - 0x7b) <= iVar12)) {
        bVar3 = false;
        if ((this[0x2b7] == (dMap_Dmap_c)0x0) || (this[0x2b7] == (dMap_Dmap_c)0x1)) {
          bVar3 = true;
        }
        if (!bVar3) {
          uVar9 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert
                    (uVar9,"d_map.h",0x168,"(mNowTlutDblBufNo == 0) || (mNowTlutDblBufNo == 1)");
          m_Do_printf::OSPanic("d_map.h",0x168,&DAT_8034f1dd);
        }
        setTlut(this,(dmap_dmap_tlut_s *)(this + (uint)(byte)this[0x2b7] * 0x140 + iVar10 + 0x20),
                (char)iVar12 + '{',(uchar)this[0x2b8],(uchar)this[0x2b9],(float)dVar15);
        uStack244 = (int)sVar7 ^ 0x80000000;
        local_f8 = 0x43300000;
        uStack252 = (int)(short)(sVar2 - (sVar1 >> 1)) ^ 0x80000000;
        local_100 = 0x43300000;
        uStack260 = (int)*(short *)(this + 0x362) ^ 0x80000000;
        local_108 = 0x43300000;
        dVar24 = (double)(((float)((double)CONCAT44(0x43300000,uStack244) - d_map::_4818) -
                          (float)((double)CONCAT44(0x43300000,uStack252) - d_map::_4818)) /
                         (float)((double)CONCAT44(0x43300000,uStack260) - d_map::_4818));
        uStack268 = (int)sVar8 ^ 0x80000000;
        local_110 = 0x43300000;
        local_f0 = 0x43300000;
        local_e8 = 0x43300000;
        dVar23 = (double)(((float)((double)CONCAT44(0x43300000,uStack268) - d_map::_4818) -
                          (float)((double)CONCAT44(0x43300000,uStack252) - d_map::_4818)) /
                         (float)((double)CONCAT44(0x43300000,uStack260) - d_map::_4818));
        pGVar13 = (GXTexObj *)(this + iVar10 + 0x370);
        uStack236 = uStack252;
        uStack228 = uStack260;
        uStack220 = gx::GXGetTexObjWidth(pGVar13);
        uStack220 = uStack220 & 0xffff;
        local_e0 = 0x43300000;
        dVar19 = (double)(d_map::_8201 /
                         (float)((double)CONCAT44(0x43300000,uStack220) - d_map::_4820));
        uStack212 = gx::GXGetTexObjHeight(pGVar13);
        uStack212 = uStack212 & 0xffff;
        local_d8 = 0x43300000;
        dVar18 = (double)(d_map::_8201 /
                         (float)((double)CONCAT44(0x43300000,uStack212) - d_map::_4820));
        uVar4 = CONCAT21(CONCAT11(d_map::backColorWhite_8018,UNK_803f82ed),UNK_803f82ee);
        local_2d0 = (_GXColor)
                    CONCAT31(CONCAT21(CONCAT11(d_map::backColorBlack_8019,UNK_803f82f1),UNK_803f82f2
                                     ),UNK_803f82f3);
        local_2d4 = (_GXColor)(uint)UNK_803f82fb;
        if (*(int *)(this + 0x2b0) == 0) {
          local_2c4 = (uint)uVar4 << 8;
        }
        else {
          local_2c4 = CONCAT31(uVar4,0x60);
        }
        local_2c8 = 0x80800080;
        local_2cc = CONCAT31(CONCAT21(CONCAT11(d_map::edgeColor_8022,UNK_803f82fd),UNK_803f82fe),
                             this[0x2b6]);
        local_2d8 = local_2c4;
        gx::GXSetTevKColor(0,&local_2d8);
        local_2dc = local_2c8;
        gx::GXSetTevKColor(1,&local_2dc);
        local_2e0 = local_2cc;
        gx::GXSetTevKColor(2,&local_2e0);
        local_2e4 = local_2d0;
        gx::GXSetTevColor(GX_TEVREG0,&local_2e4);
        local_2e8 = local_2d4;
        gx::GXSetTevColor(GX_TEVREG1,&local_2e8);
        gx::GXSetTevKColorSel(0,0xc);
        gx::GXSetTevKColorSel(1,0xd);
        gx::GXSetTevKColorSel(7,0xe);
        gx::GXSetTevKColorSel(9,0x1d);
        gx::GXSetTevKAlphaSel(1,0x1c);
        gx::GXSetTevKAlphaSel(0xb,0x1e);
        gx::GXLoadTexObj((GXTexObj *)(this + 0x5a0),0);
        bVar3 = false;
        if ((this[0x2b7] == (dMap_Dmap_c)0x0) || (this[0x2b7] == (dMap_Dmap_c)0x1)) {
          bVar3 = true;
        }
        if (!bVar3) {
          uVar9 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert
                    (uVar9,"d_map.h",0x168,"(mNowTlutDblBufNo == 0) || (mNowTlutDblBufNo == 1)");
          m_Do_printf::OSPanic("d_map.h",0x168,&DAT_8034f1dd);
        }
        gx::GXLoadTlut(this + (uint)(byte)this[0x2b7] * 0x78 + iVar11 + 0x4b0,iVar12);
        gx::GXLoadTexObj(pGVar13,1);
        gx::GXLoadTexObj((GXTexObj *)(this + 0x5e0),2);
        gx::GXLoadTexObj((GXTexObj *)(this + 0x5c0),3);
        if (*(int *)(this + 0x2b0) != 0) {
          gx::GXLoadTexObj((GXTexObj *)(this + 0x600),4);
        }
        gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_RGBA4,0);
        gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX0,GX_CLR_RGBA,GX_F32,0);
        gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX1,GX_CLR_RGBA,GX_F32,0);
        gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX2,GX_CLR_RGBA,GX_F32,0);
        gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX3,GX_CLR_RGBA,GX_F32,0);
        gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX4,GX_CLR_RGBA,GX_F32,0);
        gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX5,GX_CLR_RGBA,GX_F32,0);
        gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX6,GX_CLR_RGBA,GX_F32,0);
        gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX7,GX_CLR_RGBA,GX_F32,0);
        gx::GXClearVtxDesc();
        gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
        gx::GXSetVtxDesc(GX_VA_TEX0,GX_DIRECT);
        gx::GXSetVtxDesc(GX_VA_TEX1,GX_DIRECT);
        gx::GXSetVtxDesc(GX_VA_TEX2,GX_DIRECT);
        gx::GXSetVtxDesc(GX_VA_TEX3,GX_DIRECT);
        gx::GXSetVtxDesc(GX_VA_TEX4,GX_DIRECT);
        gx::GXSetVtxDesc(GX_VA_TEX5,GX_DIRECT);
        gx::GXSetVtxDesc(GX_VA_TEX6,GX_DIRECT);
        gx::GXSetVtxDesc(GX_VA_TEX7,GX_DIRECT);
        gx::GXSetNumChans(0);
        gx::GXSetNumTexGens(8);
        gx::GXSetTexCoordGen2(GX_TEXCOORD0,GX_TG_MTX2x4,GX_TG_TEX0,GX_IDENTITY,false,GX_PTIDENTITY);
        gx::GXSetTexCoordGen2(GX_TEXCOORD1,GX_TG_MTX2x4,GX_TG_TEX1,GX_IDENTITY,false,GX_PTIDENTITY);
        gx::GXSetTexCoordGen2(GX_TEXCOORD2,GX_TG_MTX2x4,GX_TG_TEX2,GX_IDENTITY,false,GX_PTIDENTITY);
        gx::GXSetTexCoordGen2(GX_TEXCOORD3,GX_TG_MTX2x4,GX_TG_TEX3,GX_IDENTITY,false,GX_PTIDENTITY);
        gx::GXSetTexCoordGen2(GX_TEXCOORD4,GX_TG_MTX2x4,GX_TG_TEX4,GX_IDENTITY,false,GX_PTIDENTITY);
        gx::GXSetTexCoordGen2(GX_TEXCOORD5,GX_TG_MTX2x4,GX_TG_TEX5,GX_IDENTITY,false,GX_PTIDENTITY);
        gx::GXSetTexCoordGen2(GX_TEXCOORD6,GX_TG_MTX2x4,GX_TG_TEX6,GX_IDENTITY,false,GX_PTIDENTITY);
        gx::GXSetTexCoordGen2(GX_TEXCOORD7,GX_TG_MTX2x4,GX_TG_TEX7,GX_IDENTITY,false,GX_PTIDENTITY);
        gx::GXSetNumTevStages(0xc);
        gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD0,GX_TEXMAP0,GX_COLOR_NULL);
        if (*(int *)(this + 0x2b0) == 0) {
          gx::GXSetTevOrder(GX_TEVSTAGE7,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR_NULL);
        }
        else {
          gx::GXSetTevOrder(GX_TEVSTAGE1,GX_TEXCOORD5,GX_TEXMAP4,GX_COLOR_NULL);
        }
        gx::GXSetTevOrder(GX_TEVSTAGE2,GX_TEXCOORD0,GX_TEXMAP0,GX_COLOR_NULL);
        gx::GXSetTevOrder(GX_TEVSTAGE3,GX_TEXCOORD1,GX_TEXMAP1,GX_COLOR_NULL);
        gx::GXSetTevOrder(GX_TEVSTAGE4,GX_TEXCOORD2,GX_TEXMAP1,GX_COLOR_NULL);
        gx::GXSetTevOrder(GX_TEVSTAGE5,GX_TEXCOORD3,GX_TEXMAP1,GX_COLOR_NULL);
        gx::GXSetTevOrder(GX_TEVSTAGE6,GX_TEXCOORD4,GX_TEXMAP1,GX_COLOR_NULL);
        gx::GXSetTevOrder(GX_TEVSTAGE7,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR_NULL);
        gx::GXSetTevOrder(GX_TEVSTAGE8,GX_TEXCOORD5,GX_TEXMAP1,GX_COLOR_NULL);
        gx::GXSetTevOrder(GX_TEVSTAGE9,GX_TEXCOORD6,GX_TEXMAP2,GX_COLOR_NULL);
        gx::GXSetTevOrder(GX_TEVSTAGE10,GX_TEXCOORD6,GX_TEXMAP2,GX_COLOR_NULL);
        gx::GXSetTevOrder(GX_TEVSTAGE11,GX_TEXCOORD7,GX_TEXMAP3,GX_COLOR_NULL);
        gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_C0,GX_CC_KONST,GX_CC_TEXC,GX_CC_ZERO);
        gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVREG2);
        if (*(int *)(this + 0x2b0) == 0) {
          gx::GXSetTevColorIn(GX_TEVSTAGE1,GX_CC_ZERO,GX_CC_ZERO,GX_CC_ZERO,GX_CC_ZERO);
          gx::GXSetTevColorOp(GX_TEVSTAGE1,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
          gx::GXSetTevColorIn(GX_TEVSTAGE2,GX_CC_ZERO,GX_CC_ZERO,GX_CC_ZERO,GX_CC_C2);
          gx::GXSetTevColorOp(GX_TEVSTAGE2,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVREG2);
        }
        else {
          gx::GXSetTevColorIn(GX_TEVSTAGE1,GX_CC_C1,GX_CC_KONST,GX_CC_TEXC,GX_CC_ZERO);
          gx::GXSetTevColorOp(GX_TEVSTAGE1,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
          gx::GXSetTevColorIn(GX_TEVSTAGE2,GX_CC_C2,GX_CC_CPREV,GX_CC_APREV,GX_CC_ZERO);
          gx::GXSetTevColorOp(GX_TEVSTAGE2,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVREG2);
        }
        gx::GXSetTevColorIn(GX_TEVSTAGE3,GX_CC_ZERO,GX_CC_ONE,GX_CC_TEXA,GX_CC_ZERO);
        gx::GXSetTevColorOp(GX_TEVSTAGE3,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
        gx::GXSetTevColorIn(GX_TEVSTAGE4,GX_CC_ZERO,GX_CC_ONE,GX_CC_TEXA,GX_CC_CPREV);
        gx::GXSetTevColorOp(GX_TEVSTAGE4,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
        gx::GXSetTevColorIn(GX_TEVSTAGE5,GX_CC_ZERO,GX_CC_ONE,GX_CC_TEXA,GX_CC_CPREV);
        gx::GXSetTevColorOp(GX_TEVSTAGE5,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
        gx::GXSetTevColorIn(GX_TEVSTAGE6,GX_CC_ZERO,GX_CC_ONE,GX_CC_TEXA,GX_CC_CPREV);
        gx::GXSetTevColorOp(GX_TEVSTAGE6,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
        gx::GXSetTevColorIn(GX_TEVSTAGE7,GX_CC_C2,GX_CC_KONST,GX_CC_CPREV,GX_CC_ZERO);
        gx::GXSetTevColorOp(GX_TEVSTAGE7,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
        gx::GXSetTevColorIn(GX_TEVSTAGE8,GX_CC_CPREV,GX_CC_TEXC,GX_CC_TEXA,GX_CC_ZERO);
        gx::GXSetTevColorOp(GX_TEVSTAGE8,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVREG2);
        gx::GXSetTevColorIn(GX_TEVSTAGE9,GX_CC_ZERO,GX_CC_TEXA,GX_CC_KONST,GX_CC_ZERO);
        gx::GXSetTevColorOp(GX_TEVSTAGE9,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
        gx::GXSetTevColorIn(GX_TEVSTAGE10,GX_CC_C2,GX_CC_TEXC,GX_CC_CPREV,GX_CC_ZERO);
        gx::GXSetTevColorOp(GX_TEVSTAGE10,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
        gx::GXSetTevColorIn(GX_TEVSTAGE11,GX_CC_ZERO,GX_CC_ZERO,GX_CC_ZERO,GX_CC_CPREV);
        gx::GXSetTevColorOp(GX_TEVSTAGE11,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
        gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO);
        gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
        if (*(int *)(this + 0x2b0) == 0) {
          gx::GXSetTevAlphaIn(GX_TEVSTAGE1,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO);
          gx::GXSetTevAlphaOp(GX_TEVSTAGE1,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
        }
        else {
          gx::GXSetTevAlphaIn(GX_TEVSTAGE1,GX_CA_ZERO,GX_CA_TEXA,GX_CA_KONST,GX_CA_ZERO);
          gx::GXSetTevAlphaOp(GX_TEVSTAGE1,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
        }
        gx::GXSetTevAlphaIn(GX_TEVSTAGE2,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO);
        gx::GXSetTevAlphaOp(GX_TEVSTAGE2,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
        gx::GXSetTevAlphaIn(GX_TEVSTAGE3,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO);
        gx::GXSetTevAlphaOp(GX_TEVSTAGE3,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
        gx::GXSetTevAlphaIn(GX_TEVSTAGE4,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO);
        gx::GXSetTevAlphaOp(GX_TEVSTAGE4,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
        gx::GXSetTevAlphaIn(GX_TEVSTAGE5,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO);
        gx::GXSetTevAlphaOp(GX_TEVSTAGE5,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
        gx::GXSetTevAlphaIn(GX_TEVSTAGE6,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO);
        gx::GXSetTevAlphaOp(GX_TEVSTAGE6,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
        gx::GXSetTevAlphaIn(GX_TEVSTAGE7,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO);
        gx::GXSetTevAlphaOp(GX_TEVSTAGE7,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
        gx::GXSetTevAlphaIn(GX_TEVSTAGE8,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO);
        gx::GXSetTevAlphaOp(GX_TEVSTAGE8,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
        gx::GXSetTevAlphaIn(GX_TEVSTAGE9,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO);
        gx::GXSetTevAlphaOp(GX_TEVSTAGE9,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
        gx::GXSetTevAlphaIn(GX_TEVSTAGE10,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO);
        gx::GXSetTevAlphaOp(GX_TEVSTAGE10,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
        gx::GXSetTevAlphaIn(GX_TEVSTAGE11,GX_CA_ZERO,GX_CA_KONST,GX_CA_TEXA,GX_CA_ZERO);
        gx::GXSetTevAlphaOp(GX_TEVSTAGE11,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
        gx::GXSetZMode(false,GX_LEQUAL,false);
        gx::GXSetBlendMode(GX_BM_BLEND,GX_BL_SRCALPHA,GX_BL_INVSRCALPHA,GX_LO_SET);
        gx::GXSetCullMode(0);
        gx::GXSetAlphaCompare(GX_GREATER,0,GX_AOP_OR,GX_GREATER,0);
        gx::GXBegin(0x80,0,4);
        write_volatile_2(0xcc008000,sVar5);
        write_volatile_2(0xcc008000,sVar7);
        write_volatile_2(0xcc008000,0);
        write_volatile_4(0xcc008000,d_map::_4426);
        write_volatile_4(0xcc008000,d_map::_4426);
        write_volatile_4(0xcc008000,(float)-dVar19);
        write_volatile_4(0xcc008000,d_map::_4426);
        write_volatile_4(0xcc008000,(float)dVar19);
        write_volatile_4(0xcc008000,d_map::_4426);
        write_volatile_4(0xcc008000,d_map::_4426);
        write_volatile_4(0xcc008000,(float)dVar18);
        write_volatile_4(0xcc008000,d_map::_4426);
        write_volatile_4(0xcc008000,(float)-dVar18);
        write_volatile_4(0xcc008000,d_map::_4426);
        write_volatile_4(0xcc008000,d_map::_4426);
        write_volatile_4(0xcc008000,d_map::_4426);
        write_volatile_4(0xcc008000,(float)dVar20);
        write_volatile_4(0xcc008000,d_map::_4426);
        write_volatile_4(0xcc008000,(float)dVar24);
        write_volatile_2(0xcc008000,sVar6);
        write_volatile_2(0xcc008000,sVar7);
        write_volatile_2(0xcc008000,0);
        write_volatile_4(0xcc008000,(float)dVar22);
        write_volatile_4(0xcc008000,d_map::_4426);
        dVar16 = (double)d_map::_4611;
        write_volatile_4(0xcc008000,(float)(dVar16 - dVar19));
        write_volatile_4(0xcc008000,d_map::_4426);
        write_volatile_4(0xcc008000,(float)(dVar16 + dVar19));
        write_volatile_4(0xcc008000,d_map::_4426);
        write_volatile_4(0xcc008000,d_map::_4611);
        write_volatile_4(0xcc008000,(float)dVar18);
        write_volatile_4(0xcc008000,d_map::_4611);
        write_volatile_4(0xcc008000,(float)-dVar18);
        write_volatile_4(0xcc008000,d_map::_4611);
        write_volatile_4(0xcc008000,d_map::_4426);
        write_volatile_4(0xcc008000,(float)dVar17);
        write_volatile_4(0xcc008000,(float)dVar20);
        write_volatile_4(0xcc008000,d_map::_4611);
        write_volatile_4(0xcc008000,(float)dVar24);
        write_volatile_2(0xcc008000,sVar6);
        write_volatile_2(0xcc008000,sVar8);
        write_volatile_2(0xcc008000,0);
        write_volatile_4(0xcc008000,(float)dVar22);
        write_volatile_4(0xcc008000,(float)dVar21);
        write_volatile_4(0xcc008000,(float)(dVar16 - dVar19));
        write_volatile_4(0xcc008000,d_map::_4611);
        write_volatile_4(0xcc008000,(float)(dVar16 + dVar19));
        write_volatile_4(0xcc008000,d_map::_4611);
        write_volatile_4(0xcc008000,d_map::_4611);
        write_volatile_4(0xcc008000,(float)(dVar16 + dVar18));
        write_volatile_4(0xcc008000,d_map::_4611);
        write_volatile_4(0xcc008000,(float)(dVar16 - dVar18));
        write_volatile_4(0xcc008000,d_map::_4611);
        write_volatile_4(0xcc008000,d_map::_4611);
        write_volatile_4(0xcc008000,(float)dVar17);
        write_volatile_4(0xcc008000,d_map::_5209);
        write_volatile_4(0xcc008000,d_map::_4611);
        write_volatile_4(0xcc008000,(float)dVar23);
        write_volatile_2(0xcc008000,sVar5);
        write_volatile_2(0xcc008000,sVar8);
        write_volatile_2(0xcc008000,0);
        write_volatile_4(0xcc008000,d_map::_4426);
        write_volatile_4(0xcc008000,(float)dVar21);
        write_volatile_4(0xcc008000,(float)-dVar19);
        write_volatile_4(0xcc008000,d_map::_4611);
        write_volatile_4(0xcc008000,(float)dVar19);
        write_volatile_4(0xcc008000,d_map::_4611);
        write_volatile_4(0xcc008000,d_map::_4426);
        write_volatile_4(0xcc008000,(float)(dVar16 + dVar18));
        write_volatile_4(0xcc008000,d_map::_4426);
        write_volatile_4(0xcc008000,(float)(dVar16 - dVar18));
        write_volatile_4(0xcc008000,d_map::_4426);
        write_volatile_4(0xcc008000,d_map::_4611);
        write_volatile_4(0xcc008000,d_map::_4426);
        write_volatile_4(0xcc008000,d_map::_5209);
        write_volatile_4(0xcc008000,d_map::_4426);
        write_volatile_4(0xcc008000,(float)dVar23);
      }
    }
    sVar7 = sVar7 - (*(short *)(this + 0x36a) + *(short *)(this + 0x36c));
    iVar12 = iVar12 + 1;
    iVar11 = iVar11 + 0xc;
    iVar10 = iVar10 + 0x20;
  } while (iVar12 < 10);
  gx::GXSetVtxAttrFmtv(0,auStack704);
  this[0x2ba] = (dMap_Dmap_c)((char)this[0x2ba] + '\x01');
  if (0x28 < (byte)this[0x2ba]) {
    this[0x2ba] = (dMap_Dmap_c)0x0;
  }
  __psq_l0(auStack8,uVar14);
  __psq_l1(auStack8,uVar14);
  __psq_l0(auStack24,uVar14);
  __psq_l1(auStack24,uVar14);
  __psq_l0(auStack40,uVar14);
  __psq_l1(auStack40,uVar14);
  __psq_l0(auStack56,uVar14);
  __psq_l1(auStack56,uVar14);
  __psq_l0(auStack72,uVar14);
  __psq_l1(auStack72,uVar14);
  __psq_l0(auStack88,uVar14);
  __psq_l1(auStack88,uVar14);
  __psq_l0(auStack104,uVar14);
  __psq_l1(auStack104,uVar14);
  __psq_l0(auStack120,uVar14);
  __psq_l1(auStack120,uVar14);
  __psq_l0(auStack136,uVar14);
  __psq_l1(auStack136,uVar14);
  return;
}


/* __thiscall dMap_Dmap_c::~dMap_Dmap_c(void) */

void __thiscall dMap_Dmap_c::_dMap_Dmap_c(dMap_Dmap_c *this)

{
  short in_r4;
  
  if (this != (dMap_Dmap_c *)0x0) {
    *(undefined ***)this = &__vt;
    if (this != (dMap_Dmap_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dDlst_base_c::~dDlst_base_c(void) */

void __thiscall dDlst_base_c::_dDlst_base_c(dDlst_base_c *this)

{
  short in_r4;
  
  if ((this != (dDlst_base_c *)0x0) && (this->vtbl = (undefined *)&__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall dDlst_base_c::draw(void) */

void __thiscall dDlst_base_c::draw(dDlst_base_c *this)

{
  return;
}


/* __thiscall dMap_2DT2_c::~dMap_2DT2_c(void) */

void __thiscall dMap_2DT2_c::_dMap_2DT2_c(dMap_2DT2_c *this)

{
  short in_r4;
  
  if (this != (dMap_2DT2_c *)0x0) {
    *(undefined ***)this = &__vt;
    if (this != (dMap_2DT2_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dMap_2DAGBCursor_c::~dMap_2DAGBCursor_c(void) */

void __thiscall dMap_2DAGBCursor_c::_dMap_2DAGBCursor_c(dMap_2DAGBCursor_c *this)

{
  short in_r4;
  
  if (this != (dMap_2DAGBCursor_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dMap_2DAGBCursor_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dMap_2DPoint_c::~dMap_2DPoint_c(void) */

void __thiscall dMap_2DPoint_c::_dMap_2DPoint_c(dMap_2DPoint_c *this)

{
  short in_r4;
  
  if (this != (dMap_2DPoint_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dMap_2DPoint_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dMap_2DTri_c::~dMap_2DTri_c(void) */

void __thiscall dMap_2DTri_c::_dMap_2DTri_c(dMap_2DTri_c *this)

{
  short in_r4;
  
  if (this != (dMap_2DTri_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dMap_2DTri_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dMap_2DAGBScrDsp_c::~dMap_2DAGBScrDsp_c(void) */

void __thiscall dMap_2DAGBScrDsp_c::_dMap_2DAGBScrDsp_c(dMap_2DAGBScrDsp_c *this)

{
  short in_r4;
  
  if (this != (dMap_2DAGBScrDsp_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dMap_2DAGBScrDsp_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dMap_2DMtMapSpcl_c::~dMap_2DMtMapSpcl_c(void) */

void __thiscall dMap_2DMtMapSpcl_c::_dMap_2DMtMapSpcl_c(dMap_2DMtMapSpcl_c *this)

{
  short in_r4;
  
  if (this != (dMap_2DMtMapSpcl_c *)0x0) {
    *(undefined ***)this = &__vt;
    if (this != (dMap_2DMtMapSpcl_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dMap_2DSQ_c::~dMap_2DSQ_c(void) */

void __thiscall dMap_2DSQ_c::_dMap_2DSQ_c(dMap_2DSQ_c *this)

{
  short in_r4;
  
  if (this != (dMap_2DSQ_c *)0x0) {
    *(undefined ***)this = &__vt;
    if (this != (dMap_2DSQ_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


namespace d_map {

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __sinit_d_map_cpp(void)

{
  Runtime.PPCEABI.H::__construct_array
            (&::dMap_c::mRoomInfo,::dMap_RoomInfo_c::dMap_RoomInfo_c,
             ::dMap_RoomInfo_c::_dMap_RoomInfo_c,0xec,0x14);
  Runtime.PPCEABI.H::__register_global_object(0,__arraydtor_4184,&_4185);
  Runtime.PPCEABI.H::__construct_array
            (&::dMap_c::mFrameTex,::dMap_2DMtMapSpcl_c::dMap_2DMtMapSpcl_c,
             ::dMap_2DMtMapSpcl_c::_dMap_2DMtMapSpcl_c,0x14,8);
  Runtime.PPCEABI.H::__register_global_object(0,__arraydtor_4186,&_4187);
  Runtime.PPCEABI.H::__construct_array
            (&::dMap_c::mFrameTexture,::dMap_2DMtMapSpcl_tex_c::dMap_2DMtMapSpcl_tex_c,
             ::dMap_2DMtMapSpcl_tex_c::_dMap_2DMtMapSpcl_tex_c,0x48,8);
  Runtime.PPCEABI.H::__register_global_object(0,__arraydtor_4188,&_4189);
  _mIconFreeTex = &::dMap_2DMtMapSpcl_c::__vt;
  Runtime.PPCEABI.H::__register_global_object
            (&::dMap_c::mIconFreeTex,::dMap_2DMtMapSpcl_c::_dMap_2DMtMapSpcl_c,&_4190);
  Runtime.PPCEABI.H::__register_global_object
            (&::dMap_c::mIconFreeTexture,::dMap_2DMtMapSpcl_tex_c::_dMap_2DMtMapSpcl_tex_c,&_4191);
  _mIconSelfTex = &::dMap_2DMtMapSpcl_c::__vt;
  Runtime.PPCEABI.H::__register_global_object
            (&::dMap_c::mIconSelfTex,::dMap_2DMtMapSpcl_c::_dMap_2DMtMapSpcl_c,&_4192);
  Runtime.PPCEABI.H::__register_global_object
            (&::dMap_c::mIconSelfTexture,::dMap_2DMtMapSpcl_tex_c::_dMap_2DMtMapSpcl_tex_c,&_4193);
  _mCursor = &::dMap_2DTri_c::__vt;
  Runtime.PPCEABI.H::__register_global_object
            (&::dMap_c::mCursor,::dMap_2DTri_c::_dMap_2DTri_c,&_4194);
  _mAgbCursor = &::dMap_2DAGBCursor_c::__vt;
  Runtime.PPCEABI.H::__register_global_object
            (&::dMap_c::mAgbCursor,::dMap_2DAGBCursor_c::_dMap_2DAGBCursor_c,&_4195);
  Runtime.PPCEABI.H::__construct_array
            (&::dMap_c::mPoint,::dMap_2DPoint_c::dMap_2DPoint_c,::dMap_2DPoint_c::_dMap_2DPoint_c,
             0x20,0xf);
  Runtime.PPCEABI.H::__register_global_object(0,__arraydtor_4196,&_4197);
  _m2DSQdraw = &::dMap_2DSQ_c::__vt;
  Runtime.PPCEABI.H::__register_global_object
            (&::dMap_c::m2DSQdraw,::dMap_2DSQ_c::_dMap_2DSQ_c,&_4198);
  _m2DSQdraw2 = &::dMap_2DSQ_c::__vt;
  Runtime.PPCEABI.H::__register_global_object
            (&::dMap_c::m2DSQdraw2,::dMap_2DSQ_c::_dMap_2DSQ_c,&_4199);
  Runtime.PPCEABI.H::__construct_array
            (&::dMap_c::mTbox,::dMap_2DT2_c::dMap_2DT2_c,::dMap_2DT2_c::_dMap_2DT2_c,0x5c,8);
  Runtime.PPCEABI.H::__register_global_object(0,__arraydtor_4200,&_4201);
  Runtime.PPCEABI.H::__construct_array
            (&::dMap_c::mDoor,::dMap_2DT2_c::dMap_2DT2_c,::dMap_2DT2_c::_dMap_2DT2_c,0x5c,0x10);
  Runtime.PPCEABI.H::__register_global_object(0,__arraydtor_4202,&_4203);
  _mPointRestart = &::dMap_2DTri_c::__vt;
  Runtime.PPCEABI.H::__register_global_object
            (&::dMap_c::mPointRestart,::dMap_2DTri_c::_dMap_2DTri_c,&_4204);
  Runtime.PPCEABI.H::__construct_array
            (&::dMap_c::mPointFriend,::dMap_2DPoint_c::dMap_2DPoint_c,
             ::dMap_2DPoint_c::_dMap_2DPoint_c,0x20,3);
  Runtime.PPCEABI.H::__register_global_object(0,__arraydtor_4205,&_4206);
  _mShip = &::dMap_2DT2_c::__vt;
  Runtime.PPCEABI.H::__register_global_object(&::dMap_c::mShip,::dMap_2DT2_c::_dMap_2DT2_c,&_4207);
  return;
}


void __arraydtor_4205(void)

{
  Runtime.PPCEABI.H::__destroy_arr(&::dMap_c::mPointFriend,::dMap_2DPoint_c::_dMap_2DPoint_c,0x20,3)
  ;
  return;
}


void __arraydtor_4202(void)

{
  Runtime.PPCEABI.H::__destroy_arr(&::dMap_c::mDoor,::dMap_2DT2_c::_dMap_2DT2_c,0x5c,0x10);
  return;
}


void __arraydtor_4200(void)

{
  Runtime.PPCEABI.H::__destroy_arr(&::dMap_c::mTbox,::dMap_2DT2_c::_dMap_2DT2_c,0x5c,8);
  return;
}

}

/* __thiscall dMap_2DT2_c::dMap_2DT2_c(void) */

void __thiscall dMap_2DT2_c::dMap_2DT2_c(dMap_2DT2_c *this)

{
  *(undefined ***)this = &dDlst_base_c::__vt;
  *(undefined ***)this = &__vt;
  return;
}


namespace d_map {

void __arraydtor_4196(void)

{
  Runtime.PPCEABI.H::__destroy_arr(&::dMap_c::mPoint,::dMap_2DPoint_c::_dMap_2DPoint_c,0x20,0xf);
  return;
}

}

/* __thiscall dMap_2DPoint_c::dMap_2DPoint_c(void) */

void __thiscall dMap_2DPoint_c::dMap_2DPoint_c(dMap_2DPoint_c *this)

{
  *(undefined ***)this = &dDlst_base_c::__vt;
  *(undefined1 **)this = &__vt;
  return;
}


namespace d_map {

void __arraydtor_4188(void)

{
  Runtime.PPCEABI.H::__destroy_arr
            (&::dMap_c::mFrameTexture,::dMap_2DMtMapSpcl_tex_c::_dMap_2DMtMapSpcl_tex_c,0x48,8);
  return;
}

}

/* __thiscall dMap_2DMtMapSpcl_tex_c::~dMap_2DMtMapSpcl_tex_c(void) */

void __thiscall dMap_2DMtMapSpcl_tex_c::_dMap_2DMtMapSpcl_tex_c(dMap_2DMtMapSpcl_tex_c *this)

{
  short in_r4;
  
  if ((this != (dMap_2DMtMapSpcl_tex_c *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall dMap_2DMtMapSpcl_tex_c::dMap_2DMtMapSpcl_tex_c(void) */

void __thiscall dMap_2DMtMapSpcl_tex_c::dMap_2DMtMapSpcl_tex_c(dMap_2DMtMapSpcl_tex_c *this)

{
  return;
}


namespace d_map {

void __arraydtor_4186(void)

{
  Runtime.PPCEABI.H::__destroy_arr
            (&::dMap_c::mFrameTex,::dMap_2DMtMapSpcl_c::_dMap_2DMtMapSpcl_c,0x14,8);
  return;
}

}

/* __thiscall dMap_2DMtMapSpcl_c::dMap_2DMtMapSpcl_c(void) */

void __thiscall dMap_2DMtMapSpcl_c::dMap_2DMtMapSpcl_c(dMap_2DMtMapSpcl_c *this)

{
  *(undefined ***)this = &dDlst_base_c::__vt;
  *(undefined ***)this = &__vt;
  return;
}


namespace d_map {

void __arraydtor_4184(void)

{
  Runtime.PPCEABI.H::__destroy_arr
            (&::dMap_c::mRoomInfo,::dMap_RoomInfo_c::_dMap_RoomInfo_c,0xec,0x14);
  return;
}

}

/* __thiscall dMap_RoomInfo_c::~dMap_RoomInfo_c(void) */

void __thiscall dMap_RoomInfo_c::_dMap_RoomInfo_c(dMap_RoomInfo_c *this)

{
  short in_r4;
  
  if (this != (dMap_RoomInfo_c *)0x0) {
    if (this != (dMap_RoomInfo_c *)0xffffff74) {
      *(undefined1 **)&this->field_0x8c = &dMap_2DAGBScrDsp_c::__vt;
      if (this != (dMap_RoomInfo_c *)0xffffff74) {
        *(undefined ***)&this->field_0x8c = &dDlst_base_c::__vt;
      }
    }
    Runtime.PPCEABI.H::__destroy_arr
              (&this->field_0x44,dMap_2DMtMapSpcl_tex_c::_dMap_2DMtMapSpcl_tex_c,0x48,1);
    if (this != (dMap_RoomInfo_c *)0xffffffd0) {
      *(undefined ***)&this->field_0x30 = &dMap_2DMtMapSpcl_c::__vt;
      if (this != (dMap_RoomInfo_c *)0xffffffd0) {
        *(undefined ***)&this->field_0x30 = &dDlst_base_c::__vt;
      }
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dMap_RoomInfo_c::dMap_RoomInfo_c(void) */

void __thiscall dMap_RoomInfo_c::dMap_RoomInfo_c(dMap_RoomInfo_c *this)

{
  *(undefined ***)&this->field_0x30 = &dDlst_base_c::__vt;
  *(undefined ***)&this->field_0x30 = &dMap_2DMtMapSpcl_c::__vt;
  Runtime.PPCEABI.H::__construct_array
            ((void *)&this->field_0x44,dMap_2DMtMapSpcl_tex_c::dMap_2DMtMapSpcl_tex_c,
             dMap_2DMtMapSpcl_tex_c::_dMap_2DMtMapSpcl_tex_c,0x48,1);
  *(undefined ***)&this->field_0x8c = &dDlst_base_c::__vt;
  *(undefined1 **)&this->field_0x8c = &dMap_2DAGBScrDsp_c::__vt;
  return;
}

