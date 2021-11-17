#include <d_envse.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <mtx/vec.h>
#include <SComponent/c_m3d.h>
#include <d_stage.h>
#include <d_a_grid.h>
#include <JAZelAudio/JAIZelAtmos.h>
#include <d_path.h>
#include <d_envse.h>
#include <d_com_inf_game.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <dEnvSe_c.h>


namespace d_envse {

/* __stdcall dEnvSe_Draw(dEnvSe_c *) */

undefined4 dEnvSe_Draw(void)

{
  return 1;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x8017d6e0) */
/* __stdcall dEnvSe_getNearPathPos(cXyz *,
                                   cXyz *,
                                   dPath *) */

void dEnvSe_getNearPathPos(cXyz *param_1,cXyz *param_2,dPath *param_3)

{
  dPath__Point *pdVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 in_f31;
  double dVar5;
  float fVar6;
  float local_68;
  uint local_64;
  uint local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  undefined **local_44;
  float local_40;
  float local_3c;
  float local_38;
  cXyz local_34;
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  iVar2 = 0;
  local_64 = _4097;
  local_60 = DAT_803fcf5c;
  dVar5 = (double)_4160;
  pdVar1 = param_3->mpPnt;
  local_44 = &::cM3dGLin::__vt;
  for (iVar3 = 0; iVar3 < (int)(uint)param_3->mNum; iVar3 = iVar3 + 1) {
    local_68 = mtx::PSVECSquareDistance(param_2,&pdVar1->mPos);
    if ((double)local_68 < dVar5) {
      iVar2 = iVar3;
      dVar5 = (double)local_68;
    }
    pdVar1 = pdVar1 + 1;
  }
  pdVar1 = param_3->mpPnt + iVar2;
  if (iVar2 != 0) {
    local_5c = pdVar1[-1].mPos.x;
    local_58 = pdVar1[-1].mPos.y;
    local_54 = pdVar1[-1].mPos.z;
    local_50 = (pdVar1->mPos).x;
    local_4c = (pdVar1->mPos).y;
    local_48 = (pdVar1->mPos).z;
    local_64 = SComponent::cM3d_Len3dSqPntAndSegLine(&local_5c,param_2,&local_40,&local_68);
    local_64 = local_64 & 0xff;
  }
  if (iVar2 != param_3->mNum - 1) {
    local_5c = (pdVar1->mPos).x;
    local_58 = (pdVar1->mPos).y;
    local_54 = (pdVar1->mPos).z;
    local_50 = pdVar1[1].mPos.x;
    local_4c = pdVar1[1].mPos.y;
    local_48 = pdVar1[1].mPos.z;
    local_60 = SComponent::cM3d_Len3dSqPntAndSegLine(&local_5c,param_2,&local_34,&local_68);
    local_60 = local_60 & 0xff;
  }
  if (local_64 == 0) {
    if (local_60 == 0) {
      param_1->x = (pdVar1->mPos).x;
      param_1->y = (pdVar1->mPos).y;
      param_1->z = (pdVar1->mPos).z;
    }
    else {
      param_1->x = local_34.x;
      param_1->y = local_34.y;
      param_1->z = local_34.z;
    }
  }
  else {
    if (local_60 == 0) {
      param_1->x = local_40;
      param_1->y = local_3c;
      param_1->z = local_38;
    }
    else {
      fVar6 = mtx::PSVECSquareDistance(&local_34,param_2);
      if (fVar6 <= local_68) {
        param_1->x = local_34.x;
        param_1->y = local_34.y;
        param_1->z = local_34.z;
      }
      else {
        param_1->x = local_40;
        param_1->y = local_3c;
        param_1->z = local_38;
      }
    }
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return;
}

}

/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Removing unreachable block (ram,0x8017dac0) */
/* __thiscall dEnvSe_c::execute(void) */

undefined4 __thiscall dEnvSe_c::execute(dEnvSe_c *this)

{
  dStage_roomStatus_c *pdVar1;
  dStage_SoundInfo_c *pSoundInf;
  dPath *pdVar2;
  int iVar3;
  char cVar4;
  ulong unaff_r27;
  int iVar5;
  char *pcVar6;
  int roomNo;
  undefined4 uVar7;
  undefined8 in_f31;
  double dVar8;
  float fVar9;
  cXyz local_68;
  cXyz local_5c;
  cXyz local_50;
  cXyz local_44;
  undefined auStack8 [8];
  byte soundKind;
  
  uVar7 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  roomNo = (int)(char)dStage_roomControl_c::mStayNo;
  pdVar1 = dStage_roomControl_c::getStatusRoomDt
                     (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mRoomCtrl,roomNo);
  if ((pdVar1 != (dStage_roomStatus_c *)0x0) &&
     (pSoundInf = (dStage_SoundInfo_c *)(*(code *)((pdVar1->parent).parent.vtbl)->getSoundInf)(),
     pSoundInf != (dStage_SoundInfo_c *)0x0)) {
    iVar5 = pSoundInf->mCount;
    pcVar6 = pSoundInf->mpData;
    dCamera_c::Eye(&local_68,
                   &(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo
                     [(char)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurCamera].mpCamera)->mBody);
    local_44.x = local_68.x;
    local_44.y = local_68.y;
    local_44.z = local_68.z;
    for (; iVar5 != 0; iVar5 = iVar5 + -1) {
      soundKind = pcVar6[0x17];
      if (soundKind == 0) {
        JAIZelBasic::initSeaEnvPos(JAIZelBasic::zel_basic);
        for (pdVar2 = d_path::dPath_GetRoomPath((uint)(byte)pcVar6[0x18],roomNo);
            pdVar2 != (dPath *)0x0; pdVar2 = d_path::dPath_GetNextRoomPath(pdVar2,roomNo)) {
          d_envse::dEnvSe_getNearPathPos(&(this->parent).mPos,&local_44,pdVar2);
          JAIZelBasic::registSeaEnvPos(JAIZelBasic::zel_basic,(Vec *)&(this->parent).mPos);
        }
        JAIZelBasic::seaEnvSePlay(JAIZelBasic::zel_basic,(uint)(byte)pcVar6[0x14],'\0');
      }
      else {
        if (soundKind == 1) {
          dVar8 = (double)d_envse::_4160;
          (this->parent).mPos.x = local_44.x;
          (this->parent).mPos.y = local_44.y;
          (this->parent).mPos.z = local_44.z;
          for (pdVar2 = d_path::dPath_GetRoomPath((uint)(byte)pcVar6[0x18],roomNo);
              pdVar2 != (dPath *)0x0; pdVar2 = d_path::dPath_GetNextRoomPath(pdVar2,roomNo)) {
            d_envse::dEnvSe_getNearPathPos(&local_50,&local_44,pdVar2);
            fVar9 = mtx::PSVECSquareDistance(&local_50,&local_44);
            if ((double)fVar9 < dVar8) {
              unaff_r27 = (ulong)pdVar2->mArg0;
              (this->parent).mPos.x = local_50.x;
              (this->parent).mPos.y = local_50.y;
              (this->parent).mPos.z = local_50.z;
              dVar8 = (double)fVar9;
            }
          }
          if (this->mAnimSC_01 == 0) {
            JAIZelBasic::seaShoreSE
                      (JAIZelBasic::zel_basic,unaff_r27,(Vec *)&(this->parent).mPos,0,'\0');
            this->field_0xfc = unaff_r27;
          }
          else {
            JAIZelBasic::seaShoreSE
                      (JAIZelBasic::zel_basic,this->field_0xfc,(Vec *)&(this->parent).mPos,1,'\0');
          }
          iVar3 = this->mAnimSC_01;
          d_com_inf_game::g_dComIfG_gameInfo._23792_2_ = (undefined2)iVar3;
          if (iVar3 == 99) {
            this->mAnimSC_01 = 0;
          }
          else {
            this->mAnimSC_01 = iVar3 + 1;
          }
        }
        else {
          if (soundKind == 2) {
            JAIZelBasic::initRiverPos(JAIZelBasic::zel_basic);
            for (pdVar2 = d_path::dPath_GetRoomPath((uint)(byte)pcVar6[0x18],roomNo);
                pdVar2 != (dPath *)0x0; pdVar2 = d_path::dPath_GetNextRoomPath(pdVar2,roomNo)) {
              d_envse::dEnvSe_getNearPathPos(&(this->parent).mPos,&local_44,pdVar2);
              JAIZelBasic::registRiverPos(JAIZelBasic::zel_basic,(Vec *)&(this->parent).mPos);
            }
            cVar4 = d_com_inf_game::dComIfGp_getReverb(roomNo);
            JAIZelBasic::riverSePlay(JAIZelBasic::zel_basic,pcVar6[0x14],cVar4);
          }
          else {
            if (soundKind == 3) {
              dVar8 = (double)d_envse::_4160;
              (this->parent).mPos.x = local_44.x;
              (this->parent).mPos.y = local_44.y;
              (this->parent).mPos.z = local_44.z;
              for (pdVar2 = d_path::dPath_GetRoomPath((uint)(byte)pcVar6[0x18],roomNo);
                  pdVar2 != (dPath *)0x0; pdVar2 = d_path::dPath_GetNextRoomPath(pdVar2,roomNo)) {
                d_envse::dEnvSe_getNearPathPos(&local_5c,&local_44,pdVar2);
                fVar9 = mtx::PSVECSquareDistance(&local_5c,&local_44);
                if ((double)fVar9 < dVar8) {
                  (this->parent).mPos.x = local_5c.x;
                  (this->parent).mPos.y = local_5c.y;
                  (this->parent).mPos.z = local_5c.z;
                  dVar8 = (double)fVar9;
                }
              }
              cVar4 = d_com_inf_game::dComIfGp_getReverb(roomNo);
              JAIZelBasic::waterfallSePlay
                        (JAIZelBasic::zel_basic,pcVar6[0x14],(Vec *)&(this->parent).mPos,cVar4);
            }
            else {
              if (soundKind == 4) {
                JAIZelBasic::initWindowPos(JAIZelBasic::zel_basic);
                for (pdVar2 = d_path::dPath_GetRoomPath((uint)(byte)pcVar6[0x18],roomNo);
                    pdVar2 != (dPath *)0x0; pdVar2 = d_path::dPath_GetNextRoomPath(pdVar2,roomNo)) {
                  d_envse::dEnvSe_getNearPathPos(&(this->parent).mPos,&local_44,pdVar2);
                  JAIZelBasic::registWindowPos(JAIZelBasic::zel_basic,(Vec *)&(this->parent).mPos);
                }
              }
            }
          }
        }
      }
      pcVar6 = pcVar6 + 0x1c;
    }
  }
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  return 1;
}


namespace d_envse {

/* __stdcall dEnvSe_Execute(dEnvSe_c *) */

void dEnvSe_Execute(dEnvSe_c *param_1)

{
  ::dEnvSe_c::execute(param_1);
  return;
}


/* __stdcall dEnvSe_IsDelete(dEnvSe_c *) */

undefined4 dEnvSe_IsDelete(void)

{
  return 1;
}


/* __stdcall dEnvSe_Delete(dEnvSe_c *) */

undefined4 dEnvSe_Delete(int param_1)

{
  JAIZelBasic::seDeleteObject(JAIZelBasic::zel_basic,(Vec *)(param_1 + 0xdc));
  return 1;
}


/* __stdcall dEnvSe_Create(kankyo_class *) */

undefined4 dEnvSe_Create(void)

{
  return 4;
}

