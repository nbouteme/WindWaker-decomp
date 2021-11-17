#include <d_path.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <d_stage.h>
#include <d_bg_s.h>
#include <d_path.h>
#include <d_save.h>


namespace d_path {

/* __stdcall dPath_GetPnt(dPath *,
                          int) */

dPath__Point * dPath_GetPnt(dPath *pPath,int idx)

{
  bool bVar1;
  ulong uVar2;
  dPath__Point *pdVar3;
  
  if (pPath == (dPath *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_path.cpp",0x1e,"path != 0");
    m_Do_printf::OSPanic("d_path.cpp",0x1e,&DAT_80352bcd);
  }
  bVar1 = false;
  if (-1 < idx) {
    if (idx < (int)(uint)pPath->mNum) {
      bVar1 = true;
    }
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_path.cpp",0x1f,"0 <= pnt_index && pnt_index < path->m_num");
    m_Do_printf::OSPanic("d_path.cpp",0x1f,&DAT_80352bcd);
  }
  if ((((pPath == (dPath *)0x0) || (pPath->mpPnt == (dPath__Point *)0x0)) || (idx < 0)) ||
     ((int)(uint)pPath->mNum <= idx)) {
    pdVar3 = (dPath__Point *)0x0;
  }
  else {
    pdVar3 = pPath->mpPnt + idx;
  }
  return pdVar3;
}


/* __stdcall dPath_GetRoomPath(int,
                               int) */

dPath * dPath_GetRoomPath(int pathIndex,int roomNo)

{
  bool bVar1;
  ulong uVar2;
  dStage_roomStatus_c *pRoom;
  dStage_dPath_c *pPath;
  dPath *pdVar3;
  
  if (roomNo == -1) {
    pPath = (dStage_dPath_c *)
            (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getPath2Inf)();
  }
  else {
    bVar1 = false;
    if ((-1 < roomNo) && (roomNo < 0x40)) {
      bVar1 = true;
    }
    if (!bVar1) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"d_path.cpp",0x3d,"0 <= room_no && room_no < 64");
      m_Do_printf::OSPanic("d_path.cpp",0x3d,&DAT_80352bcd);
    }
    pRoom = dStage_roomControl_c::getStatusRoomDt
                      (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mRoomCtrl,roomNo);
    if (pRoom == (dStage_roomStatus_c *)0x0) {
      return (dPath *)0x0;
    }
    pPath = (dStage_dPath_c *)(*(code *)((pRoom->parent).parent.vtbl)->getPath2Inf)();
  }
  if (((pPath == (dStage_dPath_c *)0x0) || (pathIndex < 0)) || (pPath->mNum <= pathIndex)) {
    pdVar3 = (dPath *)0x0;
  }
  else {
    pdVar3 = pPath->mpPath + pathIndex;
  }
  return pdVar3;
}


/* __stdcall dPath_GetNextRoomPath(dPath *,
                                   int) */

dPath * dPath_GetNextRoomPath(dPath *pInPath,int roomNo)

{
  dStage_roomStatus_c *pdVar1;
  dPath *pdVar2;
  ulong uVar3;
  uint uVar4;
  dStage_dPath_c *pPath;
  
  if (roomNo == -1) {
    pPath = (dStage_dPath_c *)
            (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getPath2Inf)();
  }
  else {
    pdVar1 = dStage_roomControl_c::getStatusRoomDt
                       (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mRoomCtrl,roomNo);
    if (pdVar1 == (dStage_roomStatus_c *)0x0) {
      return (dPath *)0x0;
    }
    pPath = (dStage_dPath_c *)(*(code *)((pdVar1->parent).parent.vtbl)->getPath2Inf)();
  }
  uVar4 = (uint)pInPath->mNextPathId;
  if ((pPath == (dStage_dPath_c *)0x0) || (uVar4 == 0xffff)) {
    pdVar2 = (dPath *)0x0;
  }
  else {
    if (pPath->mNum <= (int)uVar4) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_path.cpp",0x72,"0 <= next_id && next_id < pd->num");
      m_Do_printf::OSPanic("d_path.cpp",0x72,&DAT_80352bcd);
    }
    if ((int)uVar4 < pPath->mNum) {
      pdVar2 = pPath->mpPath + uVar4;
    }
    else {
      pdVar2 = (dPath *)0x0;
    }
  }
  return pdVar2;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __stdcall dPath_GetPolyRoomPathVec(cBgS_PolyInfo &,
                                      cXyz *,
                                      int *) */

undefined4 dPath_GetPolyRoomPathVec(cBgS_PolyInfo *param_1,cXyz *param_2,uint *param_3)

{
  float fVar1;
  int iVar2;
  int pathIndex;
  undefined4 uVar3;
  dPath *pdVar4;
  bool bVar5;
  dPath__Point *pdVar6;
  dPath__Point *pdVar7;
  
  iVar2 = dBgS::GetRoomId(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,param_1);
  pathIndex = dBgS::GetRoomPathId(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,param_1);
  fVar1 = _4034;
  param_2->x = _4034;
  param_2->y = fVar1;
  param_2->z = fVar1;
  *param_3 = 0;
  if (iVar2 == -1) {
    uVar3 = 0;
  }
  else {
    pdVar4 = dPath_GetRoomPath(pathIndex,iVar2);
    if (pdVar4 == (dPath *)0x0) {
      uVar3 = 0;
    }
    else {
      if ((pdVar4->field_0x6 == 0xff) ||
         (bVar5 = dSv_info_c::isSwitch
                            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo,(uint)pdVar4->field_0x6,
                             iVar2), bVar5 == false)) {
        iVar2 = dBgS::GetRoomPathPntNo(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,param_1);
        if ((iVar2 == 0xff) || ((iVar2 < 0 || ((int)(uint)pdVar4->mNum <= iVar2)))) {
          uVar3 = 0;
        }
        else {
          pdVar6 = pdVar4->mpPnt;
          pdVar7 = pdVar6 + iVar2;
          if (iVar2 != pdVar4->mNum - 1) {
            pdVar6 = pdVar6 + iVar2 + 1;
          }
          param_2->x = (pdVar6->mPos).x - (pdVar7->mPos).x;
          param_2->y = (pdVar6->mPos).y - (pdVar7->mPos).y;
          param_2->z = (pdVar6->mPos).z - (pdVar7->mPos).z;
          *param_3 = (uint)pdVar4->mArg0;
          uVar3 = 1;
        }
      }
      else {
        uVar3 = 0;
      }
    }
  }
  return uVar3;
}

