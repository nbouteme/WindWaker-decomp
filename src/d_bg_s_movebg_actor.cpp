#include <d_bg_s_movebg_actor.h>
#include <f_op_actor.h>
#include <d_bg_s_movebg_actor.h>
#include <JKernel/JKRHeap.h>
#include <d_bg_w.h>
#include <d_resorce.h>
#include <SComponent/c_bg_w.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <mtx/mtx.h>
#include <m_Do_mtx.h>
#include <f_op_actor_mng.h>
#include <d_bg_s.h>
#include <SComponent/c_bg_s.h>
#include <dBgS_MoveBgActor.h>

pointer dBgS_MoveBgActor;
int dBgS_MoveBgActor;
pointer dBgS_MoveBgActor;

/* __thiscall dBgS_MoveBgActor::dBgS_MoveBgActor(void) */

void __thiscall dBgS_MoveBgActor::dBgS_MoveBgActor(dBgS_MoveBgActor *this)

{
  fopAc_ac_c::fopAc_ac_c(&this->parent);
  this->vtbl = (dBgS_MoveBgActor__vtbl *)&__vt;
  this->mpBgW = (dBgW *)0x0;
  return;
}


namespace d_bg_s_movebg_actor {

/* __stdcall CheckCreateHeap(fopAc_ac_c *) */

void CheckCreateHeap(dBgS_MoveBgActor *actor)

{
  ::dBgS_MoveBgActor::MoveBGCreateHeap(actor);
  return;
}

}

/* __thiscall dBgS_MoveBgActor::MoveBGCreateHeap(void) */

undefined4 __thiscall dBgS_MoveBgActor::MoveBGCreateHeap(dBgS_MoveBgActor *this)

{
  int iVar1;
  dBgW *this_00;
  cBgD_t *pData;
  uint uVar2;
  
  iVar1 = (*(code *)this->vtbl->CreateHeap)();
  if (iVar1 != 0) {
    this_00 = (dBgW *)JKernel::operator_new(0xbc);
    if (this_00 != (dBgW *)0x0) {
      this_00 = dBgW::dBgW(this_00);
    }
    this->mpBgW = this_00;
    if (this->mpBgW != (dBgW *)0x0) {
      pData = (cBgD_t *)
              dRes_control_c::getRes
                        (m_name,m_dzb_id,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,
                         0x40);
      uVar2 = cBgW::Set(&this->mpBgW->parent,pData,MoveBG,&this->mMtx);
      if ((uVar2 & 0xff) == 0) {
        if (m_set_func != (undefined *)0x0) {
          this->mpBgW->mpTransPosCb = m_set_func;
        }
        return 1;
      }
    }
    this->mpBgW = (dBgW *)0x0;
  }
  return 0;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dBgS_MoveBgActor::MoveBGCreate(char const *,
                                             int,
                                             void *(dBgW *,void *,cBgS_PolyInfo &,bool,cXyz *,csXyz
   *,csXyz *),
                                             unsigned long) */

PhaseState __thiscall
dBgS_MoveBgActor::MoveBGCreate
          (dBgS_MoveBgActor *this,char *arcName,int dzbFileIndex,FuncDef550 *param_3,
          ulong maxHeapSize)

{
  uint uVar1;
  PhaseState PVar2;
  char cVar4;
  int iVar3;
  
  mtx::PSMTXTrans((double)(this->parent).mCurrent.mPos.x,(double)(this->parent).mCurrent.mPos.y,
                  (double)(this->parent).mCurrent.mPos.z,&mDoMtx_stack_c::now);
  m_Do_mtx::mDoMtx_YrotM(&mDoMtx_stack_c::now,(this->parent).mCollisionRot.y);
  mDoMtx_stack_c::scaleM((this->parent).mScale.x,(this->parent).mScale.y,(this->parent).mScale.z);
  mtx::PSMTXCopy(&mDoMtx_stack_c::now,&this->mMtx);
  m_name = arcName;
  m_dzb_id = dzbFileIndex;
  m_set_func = param_3;
  uVar1 = f_op_actor_mng::fopAcM_entrySolidHeap
                    (&this->parent,d_bg_s_movebg_actor::CheckCreateHeap,maxHeapSize);
  if ((uVar1 & 0xff) == 0) {
    PVar2 = cPhs_ERROR_e;
  }
  else {
    cVar4 = dBgS::Regist(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,this->mpBgW,&this->parent);
    if (cVar4 == '\0') {
      iVar3 = (*(code *)this->vtbl->Create)(this);
      PVar2 = cPhs_ERROR_e - (iVar3 != 0);
    }
    else {
      PVar2 = cPhs_ERROR_e;
    }
  }
  return PVar2;
}


/* __thiscall dBgS_MoveBgActor::MoveBGDelete(void) */

undefined4 __thiscall dBgS_MoveBgActor::MoveBGDelete(dBgS_MoveBgActor *this)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  dBgW *pdVar4;
  
  uVar3 = (*(code *)this->vtbl->Delete)();
  pdVar4 = this->mpBgW;
  if (pdVar4 != (dBgW *)0x0) {
    uVar2 = (pdVar4->parent).mCount;
    if (((int)uVar2 < 0) || (0xff < (int)uVar2)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      cBgS::Release((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,&pdVar4->parent);
    }
  }
  return uVar3;
}


/* __thiscall dBgS_MoveBgActor::MoveBGExecute(void) */

undefined4 __thiscall dBgS_MoveBgActor::MoveBGExecute(dBgS_MoveBgActor *this)

{
  undefined4 uVar1;
  MTX34 *local_18 [4];
  
  local_18[0] = (MTX34 *)0x0;
  uVar1 = (*(code *)this->vtbl->Execute)(this,local_18);
  if (local_18[0] == (MTX34 *)0x0) {
    mtx::PSMTXTrans((double)(this->parent).mCurrent.mPos.x,(double)(this->parent).mCurrent.mPos.y,
                    (double)(this->parent).mCurrent.mPos.z,&mDoMtx_stack_c::now);
    m_Do_mtx::mDoMtx_YrotM(&mDoMtx_stack_c::now,(this->parent).mCollisionRot.y);
    mDoMtx_stack_c::scaleM((this->parent).mScale.x,(this->parent).mScale.y,(this->parent).mScale.z);
    mtx::PSMTXCopy(&mDoMtx_stack_c::now,&this->mMtx);
  }
  else {
    mtx::PSMTXCopy(local_18[0],&this->mMtx);
  }
  dBgW::Move(this->mpBgW);
  return uVar1;
}


/* __thiscall dBgS_MoveBgActor::CreateHeap(void) */

undefined4 __thiscall dBgS_MoveBgActor::CreateHeap(dBgS_MoveBgActor *this)

{
  return 1;
}


/* __thiscall dBgS_MoveBgActor::Create(void) */

undefined4 __thiscall dBgS_MoveBgActor::Create(dBgS_MoveBgActor *this)

{
  return 1;
}


/* __thiscall dBgS_MoveBgActor::Delete(void) */

undefined4 __thiscall dBgS_MoveBgActor::Delete(dBgS_MoveBgActor *this)

{
  return 1;
}


/* __thiscall dBgS_MoveBgActor::Execute(float * *[][][]) */

undefined4 __thiscall dBgS_MoveBgActor::Execute(dBgS_MoveBgActor *this,float **param_1)

{
  return 1;
}


/* __thiscall dBgS_MoveBgActor::Draw(void) */

undefined4 __thiscall dBgS_MoveBgActor::Draw(dBgS_MoveBgActor *this)

{
  return 1;
}


/* __thiscall dBgS_MoveBgActor::IsDelete(void) */

undefined4 __thiscall dBgS_MoveBgActor::IsDelete(dBgS_MoveBgActor *this)

{
  return 1;
}


/* __thiscall dBgS_MoveBgActor::ToFore(void) */

undefined4 __thiscall dBgS_MoveBgActor::ToFore(dBgS_MoveBgActor *this)

{
  return 1;
}


/* __thiscall dBgS_MoveBgActor::ToBack(void) */

undefined4 __thiscall dBgS_MoveBgActor::ToBack(dBgS_MoveBgActor *this)

{
  return 1;
}

