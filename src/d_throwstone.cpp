#include <d_throwstone.h>
#include <d_throwstone.h>
#include <d_resorce.h>
#include <m_Do_ext.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <d_com_inf_game.h>
#include <f_op_actor.h>
#include <f_op_actor_mng.h>
#include <mtx/mtx.h>
#include <m_Do_mtx.h>
#include <d_demo.h>
#include <d_save.h>
#include <d_kankyo.h>
#include <daThrowstone_c.h>


namespace d_throwstone {

/* __stdcall CheckCreateHeap(fopAc_ac_c *) */

void CheckCreateHeap(daThrowstone_c *param_1)

{
  ::daThrowstone_c::CreateHeap(param_1);
  return;
}

}

/* __thiscall daThrowstone_c::CreateHeap(void) */

bool __thiscall daThrowstone_c::CreateHeap(daThrowstone_c *this)

{
  J3DModelData *pModel;
  J3DModel *pJVar1;
  bool bVar2;
  
  pModel = (J3DModelData *)
           dRes_control_c::getRes
                     ("Aisi",3,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
  if (pModel == (J3DModelData *)0x0) {
    bVar2 = false;
  }
  else {
    pJVar1 = m_Do_ext::mDoExt_J3DModel__create(pModel,0x80000,0x11000002);
    *(J3DModel **)(this + 0x298) = pJVar1;
    bVar2 = *(int *)(this + 0x298) != 0;
  }
  return bVar2;
}


namespace d_throwstone {

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall daThrowstoneCreate(void *) */

PhaseState daThrowstoneCreate(fopAc_ac_c *param_1)

{
  PhaseState PVar1;
  uint uVar2;
  MTX34 *pMVar3;
  
  PVar1 = d_com_inf_game::dComIfG_resLoad((request_of_phase_process_class *)(param_1 + 1),"Aisi");
  if (PVar1 == cPhs_COMPLEATE_e) {
    if ((param_1->mCondition & Constructed) == 0) {
      if (param_1 != (fopAc_ac_c *)0x0) {
        fopAc_ac_c::fopAc_ac_c(param_1);
      }
      param_1->mCondition = param_1->mCondition | Constructed;
    }
    uVar2 = f_op_actor_mng::fopAcM_entrySolidHeap(param_1,CheckCreateHeap,0x4c0);
    if ((uVar2 & 0xff) == 0) {
      PVar1 = cPhs_ERROR_e;
    }
    else {
      mtx::PSMTXTrans((double)(param_1->mCurrent).mPos.x,(double)(param_1->mCurrent).mPos.y,
                      (double)(param_1->mCurrent).mPos.z,&mDoMtx_stack_c::now);
      m_Do_mtx::mDoMtx_YrotM(&mDoMtx_stack_c::now,(param_1->mCollisionRot).y);
      mDoMtx_stack_c::scaleM((param_1->mScale).x,(param_1->mScale).y,(param_1->mScale).z);
      pMVar3 = (MTX34 *)&param_1[1].parent.parent.mInitState;
      mtx::PSMTXCopy(&mDoMtx_stack_c::now,pMVar3);
      param_1->mpCullMtx = (MTX34 *)(*(int *)&param_1[1].parent.parent.mProcName + 0x24);
      mtx::PSMTXCopy((MTX34 *)(*(int *)&param_1[1].parent.parent.mProcName + 0x24),pMVar3);
    }
  }
  return PVar1;
}


/* __stdcall daThrowstoneDelete(void *) */

undefined4 daThrowstoneDelete(int param_1)

{
  d_com_inf_game::dComIfG_resDelete((request_of_phase_process_class *)(param_1 + 0x290),"Aisi");
  return 1;
}


/* __stdcall daThrowstoneExecute(void *) */

undefined4 daThrowstoneExecute(fopAc_ac_c *param_1)

{
  int iVar1;
  
  d_demo::dDemo_setDemoData(param_1,0x6a,(mDoExt_McaMorf *)0x0,(char *)0x0,0,0,0,'\0');
  iVar1 = *(int *)&param_1[1].parent.parent.mProcName;
  *(float *)(iVar1 + 0x18) = (param_1->mScale).x;
  *(float *)(iVar1 + 0x1c) = (param_1->mScale).y;
  *(float *)(iVar1 + 0x20) = (param_1->mScale).z;
  mtx::PSMTXTrans((double)(param_1->mCurrent).mPos.x,(double)(param_1->mCurrent).mPos.y,
                  (double)(param_1->mCurrent).mPos.z,&mDoMtx_stack_c::now);
  m_Do_mtx::mDoMtx_ZXYrotM
            (&mDoMtx_stack_c::now,(int)(param_1->mCollisionRot).x,(int)(param_1->mCollisionRot).y,
             (int)(param_1->mCollisionRot).z);
  mtx::PSMTXCopy(&mDoMtx_stack_c::now,(MTX34 *)(*(int *)&param_1[1].parent.parent.mProcName + 0x24))
  ;
  mtx::PSMTXCopy(&mDoMtx_stack_c::now,(MTX34 *)&param_1[1].parent.parent.mInitState);
  return 0;
}


/* __stdcall daThrowstoneDraw(void *) */

undefined4 daThrowstoneDraw(int param_1)

{
  int iVar1;
  
  iVar1 = dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x310);
  if (iVar1 != 0) {
    dScnKy_env_light_c::settingTevStruct
              (&d_kankyo::g_env_light,Actor,(cXyz *)(param_1 + 0x1f8),
               (dKy_tevstr_c *)(param_1 + 0x10c));
    dScnKy_env_light_c::setLightTevColorType
              (&d_kankyo::g_env_light,*(J3DModel **)(param_1 + 0x298),
               (dKy_tevstr_c *)(param_1 + 0x10c));
    m_Do_ext::mDoExt_modelUpdateDL(*(J3DModel **)(param_1 + 0x298));
  }
  return 1;
}


/* __stdcall daThrowstoneIsDelete(void *) */

undefined4 daThrowstoneIsDelete(void)

{
  return 1;
}

