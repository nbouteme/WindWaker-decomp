#include <d_demo.h>
#include <d_demo.h>
#include <JStage/JSGActor.h>
#include <JKernel/JKRHeap.h>
#include <f_pc_searcher.h>
#include <f_op_actor_iter.h>
#include <d_resorce.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <m_Do_ext.h>
#include <JStage/JSGFog.h>
#include <JStage/JSGLight.h>
#include <JStage/JSGAmbientLight.h>
#include <JStage/JSGCamera.h>
#include <f_op_actor_mng.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <d_mesg.h>
#include <JStudio/jstudio-control.h>
#include <JMessage/control.h>
#include <JStage/JSGSystem.h>
#include <JGadget/binary.h>
#include <JStudio/stb.h>
#include <JStudio/fvb.h>
#include <JUtility/JUTNameTab.h>
#include <mtx/mtx.h>
#include <dDemo_manager_c.h>
#include <dDemo_actor_c.h>
#include <dDemo_fog_c.h>
#include <dDemo_light_c.h>
#include <dDemo_system_c.h>
#include <dDemo_camera_c.h>
#include <dDemo_ambient_c.h>
#include <dMesg_tControl.h>
#include <dDemo_object_c.h>


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dDemo_actor_c::dDemo_actor_c(void) */

void __thiscall dDemo_actor_c::dDemo_actor_c(dDemo_actor_c *this)

{
  float fVar1;
  undefined *puVar2;
  
  (this->parent).parent.vtbl = (undefined *)&JStage::TObject::__vt;
  (this->parent).parent.vtbl = (undefined *)&JStage::TActor::__vt;
  (this->parent).parent.vtbl = &__vt;
  this->mFlags = 0;
  fVar1 = d_demo::_3999;
  (this->mTranslation).x = d_demo::_3999;
  (this->mTranslation).y = fVar1;
  (this->mTranslation).z = fVar1;
  fVar1 = d_demo::_4000;
  (this->mScaling).x = d_demo::_4000;
  (this->mScaling).y = fVar1;
  (this->mScaling).z = fVar1;
  (this->mRotation).x = 0;
  (this->mRotation).y = 0;
  (this->mRotation).z = 0;
  this->mpModel = (J3DModel *)0x0;
  puVar2 = __4001;
  this->mAnimationFrameMax = (float)__4001;
  this->mTexAnimationFrameMax = puVar2;
  return;
}


/* __thiscall dDemo_actor_c::~dDemo_actor_c(void) */

void __thiscall dDemo_actor_c::_dDemo_actor_c(dDemo_actor_c *this)

{
  int iVar1;
  short in_r4;
  
  if (this != (dDemo_actor_c *)0x0) {
    (this->parent).parent.vtbl = &__vt;
    iVar1 = getActor(this);
    if (iVar1 != 0) {
      *(undefined *)(iVar1 + 0x1c0) = 0;
    }
    this->mActorPcId = -1;
    this->mBckId = -1;
    this->mBtpId = -1;
    this->mBtkId = -1;
    this->mBrkId = -1;
    JStage::TActor::_TActor(&this->parent);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dDemo_actor_c::getActor(void) */

void __thiscall dDemo_actor_c::getActor(dDemo_actor_c *this)

{
  fopAc_ac_c *local_8;
  
  local_8 = (fopAc_ac_c *)this->mActorPcId;
  f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,&local_8);
  return;
}


/* __thiscall dDemo_actor_c::setActor(fopAc_ac_c *) */

void __thiscall dDemo_actor_c::setActor(dDemo_actor_c *this,fopAc_ac_c *pActor)

{
  uint uVar1;
  
  if (pActor == (fopAc_ac_c *)0x0) {
    this->mActorPcId = -1;
  }
  else {
    if (pActor == (fopAc_ac_c *)0x0) {
      uVar1 = 0xffffffff;
    }
    else {
      uVar1 = (pActor->parent).parent.mBsPcId;
    }
    this->mActorPcId = uVar1;
  }
  this->mBckId = -1;
  this->mBtpId = -1;
  this->mBtkId = -1;
  this->mBrkId = -1;
  return;
}


/* __thiscall dDemo_actor_c::getP_BtpData(char const *) */

void * __thiscall dDemo_actor_c::getP_BtpData(dDemo_actor_c *this,char *param_1)

{
  ulong uVar1;
  void *pvVar2;
  uint uVar3;
  
  if ((this->mFlags & 0x80U) == 0) {
    if ((this->mFlags & 1U) == 0) {
      return (void *)0x0;
    }
    pvVar2 = this->field_0x50;
    uVar1 = this->field_0x4c;
    if (uVar1 == 3) {
      return (void *)0x0;
    }
    if ((int)uVar1 < 3) {
      if (uVar1 == 1) {
        uVar3 = SEXT24(*(short *)((int)pvVar2 + 1));
      }
      else {
        if ((int)uVar1 < 1) {
          return (void *)0x0;
        }
        uVar3 = SEXT24(*(short *)((int)pvVar2 + 2));
      }
    }
    else {
      if (6 < (int)uVar1) {
        return (void *)0x0;
      }
      if ((int)uVar1 < 5) {
        uVar3 = *(uint *)((int)pvVar2 + 1);
      }
      else {
        uVar3 = *(uint *)((int)pvVar2 + 2);
      }
    }
  }
  else {
    uVar3 = this->mTexAnimation;
    param_1 = (char *)this;
  }
  if (uVar3 == this->mBtpId) {
    pvVar2 = (void *)0x0;
  }
  else {
    this->mBtpId = uVar3;
    if ((uVar3 & 0x10000) != 0) {
      param_1 = dStage_roomControl_c::mDemoArcName;
    }
    pvVar2 = dRes_control_c::getIDRes
                       (param_1,(ushort)uVar3,
                        d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
    if (pvVar2 != (void *)0x0) {
      this->mTexAnimationFrameMax =
           (undefined *)
           (float)((double)CONCAT44(0x43300000,(int)*(short *)((int)pvVar2 + 6) ^ 0x80000000) -
                  d_demo::_4087);
    }
  }
  return pvVar2;
}


/* __thiscall dDemo_actor_c::getP_BrkData(char const *) */

void * __thiscall dDemo_actor_c::getP_BrkData(dDemo_actor_c *this,char *param_1)

{
  void *pvVar1;
  uint uVar2;
  
  if ((this->mFlags & 1U) == 0) {
    pvVar1 = (void *)0x0;
  }
  else {
    if (this->field_0x4c == 6) {
      uVar2 = *(uint *)((int)this->field_0x50 + 10);
      if (uVar2 == this->mBrkId) {
        pvVar1 = (void *)0x0;
      }
      else {
        this->mBrkId = uVar2;
        if ((uVar2 & 0x10000) != 0) {
          param_1 = dStage_roomControl_c::mDemoArcName;
        }
        pvVar1 = dRes_control_c::getIDRes
                           (param_1,(ushort)uVar2,
                            d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
      }
    }
    else {
      pvVar1 = (void *)0x0;
    }
  }
  return pvVar1;
}


/* __thiscall dDemo_actor_c::getP_BtkData(char const *) */

void * __thiscall dDemo_actor_c::getP_BtkData(dDemo_actor_c *this,char *param_1)

{
  ulong uVar1;
  void *pvVar2;
  uint uVar3;
  
  if ((this->mFlags & 1U) == 0) {
    return (void *)0x0;
  }
  uVar1 = this->field_0x4c;
  if ((int)uVar1 < 5) {
    if (uVar1 == 2) {
      uVar3 = SEXT24(*(short *)((int)this->field_0x50 + 4));
LAB_80069648:
      if (uVar3 == this->mBtkId) {
        return (void *)0x0;
      }
      this->mBtkId = uVar3;
      if ((uVar3 & 0x10000) != 0) {
        param_1 = dStage_roomControl_c::mDemoArcName;
      }
      pvVar2 = dRes_control_c::getIDRes
                         (param_1,(ushort)uVar3,
                          d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
      return pvVar2;
    }
  }
  else {
    if ((int)uVar1 < 7) {
      uVar3 = *(uint *)((int)this->field_0x50 + 6);
      goto LAB_80069648;
    }
  }
  return (void *)0x0;
}


/* __thiscall dDemo_actor_c::getPrm_Morf(void) */

double __thiscall dDemo_actor_c::getPrm_Morf(dDemo_actor_c *this)

{
  ulong uVar1;
  void *pvVar2;
  double dVar3;
  
  if ((this->mFlags & 0x40U) == 0) {
    if ((this->mFlags & 1U) == 0) {
      dVar3 = (double)d_demo::_3999;
    }
    else {
      pvVar2 = this->field_0x50;
      uVar1 = this->field_0x4c;
      if (uVar1 == 4) {
        if (this->field_0x54 < 6) {
          dVar3 = (double)d_demo::_3999;
        }
        else {
          dVar3 = (double)(float)((double)CONCAT44(0x43300000,
                                                   (int)*(char *)((int)pvVar2 + 6) ^ 0x80000000) -
                                 d_demo::_4087);
        }
      }
      else {
        if ((int)uVar1 < 4) {
          if (uVar1 == 2) {
            if (this->field_0x54 < 7) {
              return (double)d_demo::_3999;
            }
            return (double)(float)((double)CONCAT44(0x43300000,
                                                    (int)*(char *)((int)pvVar2 + 7) ^ 0x80000000) -
                                  d_demo::_4087);
          }
          if (((int)uVar1 < 2) && (0 < (int)uVar1)) {
            if (this->field_0x54 < 4) {
              return (double)d_demo::_3999;
            }
            return (double)(float)((double)CONCAT44(0x43300000,
                                                    (int)*(char *)((int)pvVar2 + 4) ^ 0x80000000) -
                                  d_demo::_4087);
          }
        }
        else {
          if (uVar1 == 6) {
            if (this->field_0x54 < 0xf) {
              return (double)d_demo::_3999;
            }
            return (double)(float)((double)CONCAT44(0x43300000,
                                                    (int)*(char *)((int)pvVar2 + 0xf) ^ 0x80000000)
                                  - d_demo::_4087);
          }
          if ((int)uVar1 < 6) {
            if (this->field_0x54 < 0xb) {
              return (double)d_demo::_3999;
            }
            return (double)(float)((double)CONCAT44(0x43300000,
                                                    (int)*(char *)((int)pvVar2 + 0xb) ^ 0x80000000)
                                  - d_demo::_4087);
          }
        }
        dVar3 = (double)d_demo::_3999;
      }
    }
  }
  else {
    dVar3 = (double)this->mAnimationTransition;
  }
  return dVar3;
}


namespace d_demo {

/* __stdcall dDemo_getJaiPointer(char const *,
                                 unsigned long,
                                 int,
                                 unsigned short *) */

void * dDemo_getJaiPointer(char *param_1,short param_2,int param_3,int param_4)

{
  void *pvVar1;
  int iVar2;
  
  if (((0 < param_3) && (param_4 != 0)) && (iVar2 = 0, 0 < param_3)) {
    do {
      if (param_2 == *(short *)(param_4 + iVar2)) {
        pvVar1 = dRes_control_c::getIDRes
                           (param_1,*(ushort *)(param_4 + iVar2 + 2),
                            d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
        return pvVar1;
      }
      iVar2 = iVar2 + 4;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return (void *)0x0;
}


/* WARNING: Inlined function: FUN_80328f20 */
/* WARNING: Inlined function: FUN_80328f6c */
/* WARNING: Removing unreachable block (ram,0x80069a04) */
/* __stdcall dDemo_setDemoData(fopAc_ac_c *,
                               unsigned char,
                               mDoExt_McaMorf *,
                               char const *,
                               int,
                               unsigned short *,
                               unsigned long,
                               signed char) */

undefined4
dDemo_setDemoData
          (fopAc_ac_c *pActor,ushort flags,mDoExt_McaMorf *pMorf,char *pArcName,undefined4 param_5,
          undefined4 param_6,ulong param_7,char param_8)

{
  float fVar1;
  ushort uVar2;
  dDemo_actor_c *this;
  undefined4 uVar3;
  J3DAnmTransform *pAnimRes;
  ulong uVar4;
  void *pSoundAnimRes;
  uint uVar5;
  double dVar6;
  double local_48;
  double local_40;
  
  this = ::dDemo_object_c::getActor
                   (&(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpDemoMgr)->mDemoObj,
                    pActor->mDemoObjId);
  if (this == (dDemo_actor_c *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar2 = flags & 0xff & this->mFlags;
    if ((uVar2 & 2) != 0) {
      (pActor->mCurrent).mPos.x = (this->mTranslation).x;
      (pActor->mCurrent).mPos.y = (this->mTranslation).y;
      (pActor->mCurrent).mPos.z = (this->mTranslation).z;
      (pActor->mNext).mPos.x = (pActor->mCurrent).mPos.x;
      (pActor->mNext).mPos.y = (pActor->mCurrent).mPos.y;
      (pActor->mNext).mPos.z = (pActor->mCurrent).mPos.z;
    }
    if ((uVar2 & 8) != 0) {
      (pActor->mCollisionRot).x = (this->mRotation).x;
      (pActor->mCollisionRot).y = (this->mRotation).y;
      (pActor->mCollisionRot).z = (this->mRotation).z;
      (pActor->mCurrent).mRot.x = (pActor->mCollisionRot).x;
      (pActor->mCurrent).mRot.y = (pActor->mCollisionRot).y;
      (pActor->mCurrent).mRot.z = (pActor->mCollisionRot).z;
    }
    if ((uVar2 & 4) != 0) {
      (pActor->mScale).x = (this->mScaling).x;
      (pActor->mScale).y = (this->mScaling).y;
      (pActor->mScale).z = (this->mScaling).z;
    }
    if (pMorf == (mDoExt_McaMorf *)0x0) {
      uVar3 = 1;
    }
    else {
      this->mpModel = pMorf->mpModel;
      if (((uVar2 & 0x20) != 0) && (uVar5 = this->mNextBckId, uVar5 != this->mBckId)) {
        if ((uVar5 & 0x10000) != 0) {
          pArcName = dStage_roomControl_c::mDemoArcName;
        }
        this->mBckId = uVar5;
        pAnimRes = (J3DAnmTransform *)
                   dRes_control_c::getIDRes
                             (pArcName,(ushort)(uVar5 & 0xffff),
                              d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
        if (pAnimRes == (J3DAnmTransform *)0x0) {
          uVar4 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar4,"d_demo.cpp",0x198,"i_key != 0");
          m_Do_printf::OSPanic("d_demo.cpp",0x198,&DAT_80351e07);
        }
        pSoundAnimRes = (void *)dDemo_getJaiPointer(pArcName,uVar5 & 0xffff,param_5,param_6);
        dVar6 = (double)::dDemo_actor_c::getPrm_Morf(this);
        mDoExt_McaMorf::setAnm(pMorf,pAnimRes,-1,(float)dVar6,_4000,_3999,_4112,pSoundAnimRes);
        local_48 = (double)CONCAT44(0x43300000,(int)(pMorf->mFrameCtrl).mEndFrame ^ 0x80000000);
        this->mAnimationFrameMax = (float)(local_48 - _4087);
      }
      if ((uVar2 & 0x40) == 0) {
        mDoExt_McaMorf::play(pMorf,&(pActor->mCurrent).mPos,param_7,param_8);
      }
      else {
        fVar1 = this->mAnimationFrame;
        if (fVar1 <= _4000) {
          local_48 = (double)CONCAT44(0x43300000,(int)(short)(int)fVar1 ^ 0x80000000);
          (pMorf->mFrameCtrl).mCurrentTime = (float)(local_48 - _4087);
        }
        else {
          local_40 = (double)CONCAT44(0x43300000,(int)(short)(int)(fVar1 - _4000) ^ 0x80000000);
          (pMorf->mFrameCtrl).mCurrentTime = (float)(local_40 - _4087);
          mDoExt_McaMorf::play(pMorf,&(pActor->mCurrent).mPos,param_7,param_8);
        }
      }
      uVar3 = 1;
    }
  }
  return uVar3;
}

}

/* __thiscall dDemo_actor_c::JSGSetData(unsigned long,
                                        void const *,
                                        unsigned long) */

void __thiscall
dDemo_actor_c::JSGSetData(dDemo_actor_c *this,ulong param_1,void *param_2,ulong param_3)

{
  this->field_0x4c = param_1;
  this->field_0x50 = param_2;
  this->field_0x54 = param_3;
  this->mFlags = this->mFlags | 1;
  return;
}


/* __thiscall dDemo_actor_c::JSGSetTranslation(Vec const &) */

void __thiscall dDemo_actor_c::JSGSetTranslation(dDemo_actor_c *this,Vec *param_1)

{
  (this->mTranslation).x = *(float *)param_1;
  (this->mTranslation).y = *(float *)(param_1 + 4);
  (this->mTranslation).z = *(float *)(param_1 + 8);
  this->mFlags = this->mFlags | 2;
  return;
}


/* __thiscall dDemo_actor_c::JSGSetScaling(Vec const &) */

void __thiscall dDemo_actor_c::JSGSetScaling(dDemo_actor_c *this,cXyz *param_1)

{
  (this->mScaling).x = param_1->x;
  (this->mScaling).y = param_1->y;
  (this->mScaling).z = param_1->z;
  this->mFlags = this->mFlags | 4;
  return;
}


/* __thiscall dDemo_actor_c::JSGSetRotation(Vec const &) */

void __thiscall dDemo_actor_c::JSGSetRotation(dDemo_actor_c *this,cXyz *param_1)

{
  float fVar1;
  
  fVar1 = d_demo::_4306;
  (this->mRotation).x = (short)(int)(d_demo::_4306 * param_1->x);
  (this->mRotation).y = (short)(int)(fVar1 * param_1->y);
  (this->mRotation).z = (short)(int)(fVar1 * param_1->z);
  this->mFlags = this->mFlags | 8;
  return;
}


/* __thiscall dDemo_actor_c::JSGSetShape(unsigned long) */

void __thiscall dDemo_actor_c::JSGSetShape(dDemo_actor_c *this,ulong param_1)

{
  this->mShape = param_1;
  this->mFlags = this->mFlags | 0x10;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dDemo_actor_c::JSGSetAnimation(unsigned long) */

void __thiscall dDemo_actor_c::JSGSetAnimation(dDemo_actor_c *this,ulong param_1)

{
  this->mNextBckId = param_1;
  this->mAnimationFrameMax = __4001;
  this->mFlags = this->mFlags | 0x20;
  return;
}


/* __thiscall dDemo_actor_c::JSGSetAnimationFrame(float) */

void __thiscall dDemo_actor_c::JSGSetAnimationFrame(dDemo_actor_c *this,float param_1)

{
  this->mAnimationFrame = param_1;
  this->mFlags = this->mFlags | 0x40;
  return;
}


/* __thiscall dDemo_actor_c::JSGSetAnimationTransition(float) */

void __thiscall dDemo_actor_c::JSGSetAnimationTransition(dDemo_actor_c *this,float param_1)

{
  this->mAnimationTransition = param_1;
  this->mFlags = this->mFlags | 0x40;
  return;
}


/* __thiscall dDemo_actor_c::JSGSetTextureAnimation(unsigned long) */

void __thiscall dDemo_actor_c::JSGSetTextureAnimation(dDemo_actor_c *this,ulong param_1)

{
  this->mTexAnimation = param_1;
  this->mFlags = this->mFlags | 0x80;
  return;
}


/* __thiscall dDemo_actor_c::JSGSetTextureAnimationFrame(float) */

void __thiscall dDemo_actor_c::JSGSetTextureAnimationFrame(dDemo_actor_c *this,float param_1)

{
  this->mTexAnimationFrame = param_1;
  this->mFlags = this->mFlags | 0x100;
  return;
}


namespace d_demo {

/* __stdcall getView(void) */

camera_class * getView(void)

{
  if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.field_0x4841 == 0) {
    return (camera_class *)0x0;
  }
  return d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo
         [(char)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurCameraInfo].mpCamera;
}

}

/* __thiscall dDemo_camera_c::JSGGetProjectionNear(void) const */

double __thiscall dDemo_camera_c::JSGGetProjectionNear(dDemo_camera_c *this)

{
  float fVar1;
  camera_class *pcVar2;
  
  pcVar2 = d_demo::getView();
  fVar1 = d_demo::_3999;
  if (pcVar2 != (camera_class *)0x0) {
    fVar1 = pcVar2->mNearPlane;
  }
  return (double)fVar1;
}


/* __thiscall dDemo_camera_c::JSGSetProjectionNear(float) */

void __thiscall dDemo_camera_c::JSGSetProjectionNear(dDemo_camera_c *this,float param_1)

{
  this->mNearPlane = param_1;
  this->mFlags = this->mFlags | 1;
  return;
}


/* __thiscall dDemo_camera_c::JSGGetProjectionFar(void) const */

double __thiscall dDemo_camera_c::JSGGetProjectionFar(dDemo_camera_c *this)

{
  float fVar1;
  camera_class *pcVar2;
  
  pcVar2 = d_demo::getView();
  fVar1 = d_demo::_4000;
  if (pcVar2 != (camera_class *)0x0) {
    fVar1 = pcVar2->mFarPlane;
  }
  return (double)fVar1;
}


/* __thiscall dDemo_camera_c::JSGSetProjectionFar(float) */

void __thiscall dDemo_camera_c::JSGSetProjectionFar(dDemo_camera_c *this,float param_1)

{
  this->mFarPlane = param_1;
  this->mFlags = this->mFlags | 2;
  return;
}


/* __thiscall dDemo_camera_c::JSGGetProjectionFovy(void) const */

double __thiscall dDemo_camera_c::JSGGetProjectionFovy(dDemo_camera_c *this)

{
  float fVar1;
  camera_class *pcVar2;
  
  pcVar2 = d_demo::getView();
  fVar1 = d_demo::_4378;
  if (pcVar2 != (camera_class *)0x0) {
    fVar1 = pcVar2->mFovY;
  }
  return (double)fVar1;
}


/* __thiscall dDemo_camera_c::JSGSetProjectionFovy(float) */

void __thiscall dDemo_camera_c::JSGSetProjectionFovy(dDemo_camera_c *this,float param_1)

{
  this->mFovy = param_1;
  this->mFlags = this->mFlags | 4;
  return;
}


/* __thiscall dDemo_camera_c::JSGGetProjectionAspect(void) const */

double __thiscall dDemo_camera_c::JSGGetProjectionAspect(dDemo_camera_c *this)

{
  float fVar1;
  camera_class *pcVar2;
  
  pcVar2 = d_demo::getView();
  fVar1 = d_demo::_4390;
  if (pcVar2 != (camera_class *)0x0) {
    fVar1 = pcVar2->mAspect;
  }
  return (double)fVar1;
}


/* __thiscall dDemo_camera_c::JSGSetProjectionAspect(float) */

void __thiscall dDemo_camera_c::JSGSetProjectionAspect(dDemo_camera_c *this,float param_1)

{
  this->mAspect = param_1;
  this->mFlags = this->mFlags | 8;
  return;
}


/* __thiscall dDemo_camera_c::JSGGetViewPosition(Vec *) const */

void __thiscall dDemo_camera_c::JSGGetViewPosition(dDemo_camera_c *this,cXyz *param_1)

{
  float fVar1;
  camera_class *pcVar2;
  
  pcVar2 = d_demo::getView();
  fVar1 = d_demo::_3999;
  if (pcVar2 == (camera_class *)0x0) {
    param_1->x = d_demo::_3999;
    param_1->y = fVar1;
    param_1->z = fVar1;
  }
  param_1->x = (pcVar2->mEyePos).x;
  param_1->y = (pcVar2->mEyePos).y;
  param_1->z = (pcVar2->mEyePos).z;
  return;
}


/* __thiscall dDemo_camera_c::JSGSetViewPosition(Vec const &) */

void __thiscall dDemo_camera_c::JSGSetViewPosition(dDemo_camera_c *this,cXyz *param_1)

{
  (this->mEyePos).x = param_1->x;
  (this->mEyePos).y = param_1->y;
  (this->mEyePos).z = param_1->z;
  this->mFlags = this->mFlags | 0x10;
  return;
}


/* __thiscall dDemo_camera_c::JSGGetViewUpVector(Vec *) const */

void __thiscall dDemo_camera_c::JSGGetViewUpVector(dDemo_camera_c *this,cXyz *param_1)

{
  float fVar1;
  camera_class *pcVar2;
  
  pcVar2 = d_demo::getView();
  fVar1 = d_demo::_3999;
  if (pcVar2 == (camera_class *)0x0) {
    param_1->x = d_demo::_3999;
    param_1->y = d_demo::_4000;
    param_1->z = fVar1;
  }
  param_1->x = (pcVar2->mUpVec).x;
  param_1->y = (pcVar2->mUpVec).y;
  param_1->z = (pcVar2->mUpVec).z;
  return;
}


/* __thiscall dDemo_camera_c::JSGSetViewUpVector(Vec const &) */

void __thiscall dDemo_camera_c::JSGSetViewUpVector(dDemo_camera_c *this,cXyz *param_1)

{
  (this->mUpVec).x = param_1->x;
  (this->mUpVec).y = param_1->y;
  (this->mUpVec).z = param_1->z;
  this->mFlags = this->mFlags | 0x20;
  return;
}


/* __thiscall dDemo_camera_c::JSGGetViewTargetPosition(Vec *) const */

void __thiscall dDemo_camera_c::JSGGetViewTargetPosition(dDemo_camera_c *this,cXyz *param_1)

{
  float fVar1;
  camera_class *pcVar2;
  
  pcVar2 = d_demo::getView();
  fVar1 = d_demo::_3999;
  if (pcVar2 == (camera_class *)0x0) {
    param_1->x = d_demo::_3999;
    param_1->y = fVar1;
    param_1->z = d_demo::_4000;
  }
  param_1->x = (pcVar2->mCenterPos).x;
  param_1->y = (pcVar2->mCenterPos).y;
  param_1->z = (pcVar2->mCenterPos).z;
  return;
}


/* __thiscall dDemo_camera_c::JSGSetViewTargetPosition(Vec const &) */

void __thiscall dDemo_camera_c::JSGSetViewTargetPosition(dDemo_camera_c *this,cXyz *param_1)

{
  (this->mCenterPos).x = param_1->x;
  (this->mCenterPos).y = param_1->y;
  (this->mCenterPos).z = param_1->z;
  this->mFlags = this->mFlags | 0x40;
  return;
}


/* __thiscall dDemo_camera_c::JSGGetViewRoll(void) const */

double __thiscall dDemo_camera_c::JSGGetViewRoll(dDemo_camera_c *this)

{
  float fVar1;
  camera_class *pcVar2;
  
  pcVar2 = d_demo::getView();
  fVar1 = d_demo::_3999;
  if (pcVar2 != (camera_class *)0x0) {
    fVar1 = d_demo::_4441 *
            (float)((double)CONCAT44(0x43300000,(int)pcVar2->mBank ^ 0x80000000) - d_demo::_4087);
  }
  return (double)fVar1;
}


/* __thiscall dDemo_camera_c::JSGSetViewRoll(float) */

void __thiscall dDemo_camera_c::JSGSetViewRoll(dDemo_camera_c *this,float param_1)

{
  this->mBank = param_1;
  this->mFlags = this->mFlags | 0x80;
  return;
}


/* __thiscall dDemo_ambient_c::JSGSetColor(_GXColor) */

void __thiscall dDemo_ambient_c::JSGSetColor(dDemo_ambient_c *this,_GXColor *param_1)

{
  (this->mColor).r = param_1->r;
  (this->mColor).g = param_1->g;
  (this->mColor).b = param_1->b;
  (this->mColor).a = param_1->a;
  this->mFlags = this->mFlags | 1;
  return;
}


/* __thiscall dDemo_light_c::JSGSetLightType(JStage::TELight) */

void __thiscall dDemo_light_c::JSGSetLightType(dDemo_light_c *this,TELight param_1)

{
  this->mLightType = param_1;
  this->mFlags = this->mFlags | 1;
  return;
}


/* __thiscall dDemo_light_c::JSGSetPosition(Vec const &) */

void __thiscall dDemo_light_c::JSGSetPosition(dDemo_light_c *this,cXyz *param_1)

{
  (this->mPosition).x = param_1->x;
  (this->mPosition).y = param_1->y;
  (this->mPosition).z = param_1->z;
  this->mFlags = this->mFlags | 2;
  return;
}


/* __thiscall dDemo_light_c::JSGSetColor(_GXColor) */

void __thiscall dDemo_light_c::JSGSetColor(dDemo_light_c *this,_GXColor *param_1)

{
  (this->mColor).r = param_1->r;
  (this->mColor).g = param_1->g;
  (this->mColor).b = param_1->b;
  (this->mColor).a = param_1->a;
  this->mFlags = this->mFlags | 4;
  return;
}


/* __thiscall dDemo_light_c::JSGSetDistanceAttenuation(float,
                                                       float,
                                                       _GXDistAttnFn) */

void __thiscall
dDemo_light_c::JSGSetDistanceAttenuation
          (dDemo_light_c *this,float param_1,float param_2,undefined param_3)

{
  undefined3 in_register_00000010;
  
  this->mDistAttn0 = param_1;
  this->mDistAttn1 = param_2;
  this->mDistAttnFn = CONCAT31(in_register_00000010,param_3);
  this->mFlags = this->mFlags | 8;
  return;
}


/* __thiscall dDemo_light_c::JSGSetAngleAttenuation(float,
                                                    _GXSpotFn) */

void __thiscall
dDemo_light_c::JSGSetAngleAttenuation(dDemo_light_c *this,float param_1,_GXSpotFn param_2)

{
  this->mAngleAtten = param_1;
  this->mSpotFn = param_2;
  this->mFlags = this->mFlags | 0x10;
  return;
}


/* __thiscall dDemo_light_c::JSGSetDirection(Vec const &) */

void __thiscall dDemo_light_c::JSGSetDirection(dDemo_light_c *this,cXyz *param_1)

{
  (this->mDirection).x = param_1->x;
  (this->mDirection).y = param_1->y;
  (this->mDirection).z = param_1->z;
  this->mFlags = this->mFlags | 0x20;
  return;
}


/* __thiscall dDemo_fog_c::JSGSetFogFunction(_GXFogType) */

void __thiscall dDemo_fog_c::JSGSetFogFunction(dDemo_fog_c *this,_GXFogType param_1)

{
  this[5] = SUB41(param_1,0);
  this[4] = (dDemo_fog_c)((byte)this[4] | 1);
  return;
}


/* __thiscall dDemo_fog_c::JSGSetStartZ(float) */

void __thiscall dDemo_fog_c::JSGSetStartZ(dDemo_fog_c *this,float param_1)

{
  *(float *)(this + 8) = param_1;
  this[4] = (dDemo_fog_c)((byte)this[4] | 2);
  return;
}


/* __thiscall dDemo_fog_c::JSGSetEndZ(float) */

void __thiscall dDemo_fog_c::JSGSetEndZ(dDemo_fog_c *this,float param_1)

{
  *(float *)(this + 0xc) = param_1;
  this[4] = (dDemo_fog_c)((byte)this[4] | 4);
  return;
}


/* __thiscall dDemo_fog_c::JSGSetColor(_GXColor) */

void __thiscall dDemo_fog_c::JSGSetColor(dDemo_fog_c *this,_GXColor *param_1)

{
  this[0x10] = *(dDemo_fog_c *)&param_1->r;
  this[0x11] = *(dDemo_fog_c *)&param_1->g;
  this[0x12] = *(dDemo_fog_c *)&param_1->b;
  this[0x13] = *(dDemo_fog_c *)&param_1->a;
  this[4] = (dDemo_fog_c)((byte)this[4] | 8);
  return;
}


/* __thiscall dDemo_object_c::dDemo_object_c(void) */

void __thiscall dDemo_object_c::dDemo_object_c(dDemo_object_c *this)

{
  this->mNumActor = 0;
  this->mNumLight = 0;
  this->mpActiveCamera = (dDemo_camera_c *)0x0;
  this->mpAmbient = (dDemo_ambient_c *)0x0;
  *(undefined4 *)&this->field_0xac = 0;
  return;
}


/* __thiscall dDemo_object_c::~dDemo_object_c(void) */

void __thiscall dDemo_object_c::_dDemo_object_c(dDemo_object_c *this)

{
  short in_r4;
  
  if ((this != (dDemo_object_c *)0x0) && (remove(this), 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dDemo_object_c::appendActor(fopAc_ac_c *) */

dDemo_actor_c * __thiscall dDemo_object_c::appendActor(dDemo_object_c *this,fopAc_ac_c *pActor)

{
  byte bVar1;
  dDemo_actor_c *this_00;
  
  this_00 = getActor(&(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpDemoMgr)->mDemoObj,
                     pActor->mDemoObjId);
  if (this_00 == (dDemo_actor_c *)0x0) {
    if (this->mNumActor < 0x20) {
      this_00 = (dDemo_actor_c *)JKernel::operator_new(0x6c);
      if (this_00 != (dDemo_actor_c *)0x0) {
        dDemo_actor_c::dDemo_actor_c(this_00);
      }
      if (this_00 == (dDemo_actor_c *)0x0) {
        this_00 = (dDemo_actor_c *)0x0;
      }
      else {
        bVar1 = this->mNumActor;
        this->mNumActor = bVar1 + 1;
        this->mpActors[bVar1] = this_00;
        dDemo_actor_c::setActor(this_00,pActor);
        pActor->mDemoObjId = this->mNumActor;
      }
    }
    else {
      this_00 = (dDemo_actor_c *)0x0;
    }
  }
  return this_00;
}


/* __thiscall dDemo_object_c::getActor(unsigned char) */

dDemo_actor_c * __thiscall dDemo_object_c::getActor(dDemo_object_c *this,byte idx)

{
  if ((idx != 0) && (idx < 0x21)) {
    return this->mpActors[idx - 1];
  }
  return (dDemo_actor_c *)0x0;
}


/* __thiscall dDemo_object_c::createCamera(void) */

dDemo_camera_c * __thiscall dDemo_object_c::createCamera(dDemo_object_c *this)

{
  dDemo_camera_c *pdVar1;
  dDemo_camera_c *pCamera;
  
  pdVar1 = this->mpActiveCamera;
  if (pdVar1 == (dDemo_camera_c *)0x0) {
    pCamera = (dDemo_camera_c *)JKernel::operator_new(0x40);
    if (pCamera != (dDemo_camera_c *)0x0) {
      (pCamera->parent).vtbl = (undefined *)&JStage::TObject::__vt;
      (pCamera->parent).vtbl = &JStage::TCamera::__vt;
      (pCamera->parent).vtbl = &dDemo_camera_c::__vt;
      pCamera->mFlags = 0;
    }
    this->mpActiveCamera = pCamera;
    pdVar1 = this->mpActiveCamera;
  }
  return pdVar1;
}


/* __thiscall dDemo_object_c::getActiveCamera(void) */

dDemo_camera_c * __thiscall dDemo_object_c::getActiveCamera(dDemo_object_c *this)

{
  if (this->mpActiveCamera != (dDemo_camera_c *)0x0) {
    return this->mpActiveCamera;
  }
  return (dDemo_camera_c *)0x0;
}


/* __thiscall dDemo_object_c::createAmbient(void) */

dDemo_ambient_c * __thiscall dDemo_object_c::createAmbient(dDemo_object_c *this)

{
  dDemo_ambient_c *pdVar1;
  
  pdVar1 = this->mpAmbient;
  if (pdVar1 == (dDemo_ambient_c *)0x0) {
    pdVar1 = (dDemo_ambient_c *)JKernel::operator_new(0xc);
    if (pdVar1 != (dDemo_ambient_c *)0x0) {
      pdVar1->vtbl = (undefined *)&JStage::TObject::__vt;
      pdVar1->vtbl = &JStage::TAmbientLight::__vt;
      pdVar1->vtbl = &dDemo_ambient_c::__vt;
      pdVar1->mFlags = 0;
    }
    this->mpAmbient = pdVar1;
    pdVar1 = this->mpAmbient;
  }
  return pdVar1;
}


/* __thiscall dDemo_object_c::appendLight(void) */

dDemo_light_c * __thiscall dDemo_object_c::appendLight(dDemo_object_c *this)

{
  byte bVar1;
  dDemo_light_c *pLight;
  
  if (this->mNumLight < 8) {
    pLight = (dDemo_light_c *)JKernel::operator_new(0x3c);
    if (pLight == (dDemo_light_c *)0x0) {
      pLight = (dDemo_light_c *)0x0;
    }
    else {
      (pLight->parent).parent.vtbl = (undefined *)&JStage::TObject::__vt;
      (pLight->parent).parent.vtbl = &JStage::TLight::__vt;
      (pLight->parent).parent.vtbl = &dDemo_light_c::__vt;
      pLight->mFlags = 0;
      bVar1 = this->mNumLight;
      this->mNumLight = bVar1 + 1;
      this->mpLight[bVar1] = pLight;
    }
  }
  else {
    pLight = (dDemo_light_c *)0x0;
  }
  return pLight;
}


/* __thiscall dDemo_object_c::createFog(void) */

int __thiscall dDemo_object_c::createFog(dDemo_object_c *this)

{
  int iVar1;
  undefined **ppuVar2;
  
  iVar1 = *(int *)&this->field_0xac;
  if (iVar1 == 0) {
    ppuVar2 = (undefined **)JKernel::operator_new(0x14);
    if (ppuVar2 != (undefined **)0x0) {
      *ppuVar2 = (undefined *)&JStage::TObject::__vt;
      *ppuVar2 = &JStage::TFog::__vt;
      *ppuVar2 = &dDemo_fog_c::__vt;
      *(undefined *)(ppuVar2 + 1) = 0;
    }
    *(undefined ***)&this->field_0xac = ppuVar2;
    iVar1 = *(int *)&this->field_0xac;
  }
  return iVar1;
}


/* __thiscall dDemo_object_c::remove(void) */

int __thiscall dDemo_object_c::remove(dDemo_object_c *this)

{
  int iVar1;
  dDemo_camera_c *pdVar2;
  dDemo_ambient_c *pdVar3;
  int *piVar4;
  
  while (this->mNumActor != 0) {
    iVar1 = this->mNumActor - 1;
    this->mNumActor = (byte)iVar1;
    piVar4 = *(int **)((int)this->mpActors + (iVar1 * 4 & 0x3fcU));
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 8))(piVar4,1);
    }
  }
  pdVar2 = this->mpActiveCamera;
  if (pdVar2 != (dDemo_camera_c *)0x0) {
    if (pdVar2 != (dDemo_camera_c *)0x0) {
      (**(code **)((pdVar2->parent).vtbl + 8))(pdVar2,1);
    }
    this->mpActiveCamera = (dDemo_camera_c *)0x0;
  }
  pdVar3 = this->mpAmbient;
  if (pdVar3 != (dDemo_ambient_c *)0x0) {
    if (pdVar3 != (dDemo_ambient_c *)0x0) {
      (**(code **)(pdVar3->vtbl + 8))(pdVar3,1);
    }
    this->mpAmbient = (dDemo_ambient_c *)0x0;
  }
  while (this->mNumLight != 0) {
    iVar1 = this->mNumLight - 1;
    this->mNumLight = (byte)iVar1;
    piVar4 = *(int **)((int)this->mpLight + (iVar1 * 4 & 0x3fcU));
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 8))(piVar4,1);
    }
  }
  piVar4 = *(int **)&this->field_0xac;
  if (piVar4 != (int *)0x0) {
    if (piVar4 != (int *)0x0) {
      piVar4 = (int *)(**(code **)(*piVar4 + 8))(piVar4,1);
    }
    *(undefined4 *)&this->field_0xac = 0;
  }
  return (int)piVar4;
}


/* __thiscall dDemo_fog_c::~dDemo_fog_c(void) */

void __thiscall dDemo_fog_c::_dDemo_fog_c(dDemo_fog_c *this)

{
  short in_r4;
  
  if (this != (dDemo_fog_c *)0x0) {
    *(undefined1 **)this = &__vt;
    JStage::TFog::_TFog((TFog *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dDemo_light_c::~dDemo_light_c(void) */

void __thiscall dDemo_light_c::_dDemo_light_c(dDemo_light_c *this)

{
  short in_r4;
  
  if (this != (dDemo_light_c *)0x0) {
    (this->parent).parent.vtbl = &__vt;
    JStage::TLight::_TLight(&this->parent);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dDemo_ambient_c::~dDemo_ambient_c(void) */

void __thiscall dDemo_ambient_c::_dDemo_ambient_c(dDemo_ambient_c *this)

{
  short in_r4;
  
  if (this != (dDemo_ambient_c *)0x0) {
    this->vtbl = &__vt;
    JStage::TAmbientLight::_TAmbientLight((TAmbientLight *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dDemo_camera_c::~dDemo_camera_c(void) */

void __thiscall dDemo_camera_c::_dDemo_camera_c(dDemo_camera_c *this)

{
  short in_r4;
  
  if (this != (dDemo_camera_c *)0x0) {
    (this->parent).vtbl = &__vt;
    JStage::TCamera::_TCamera(&this->parent);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dDemo_system_c::JSGFindObject(char const *,
                                            JStage::TEObject) const */

undefined4 __thiscall
dDemo_system_c::JSGFindObject(dDemo_system_c *this,char *pName,TEObject objectType)

{
  dDemo_object_c *this_00;
  fopAc_ac_c *pActor;
  int iVar1;
  undefined4 uVar2;
  
  this_00 = this->mpRootObject;
  if (this_00 == (dDemo_object_c *)0x0) {
    return 0;
  }
  if ((objectType == 2) || (objectType == 0)) {
    pActor = (fopAc_ac_c *)f_op_actor_mng::fopAcM_searchFromName(pName,0,0);
    if (pActor == (fopAc_ac_c *)0x0) {
      if ((objectType != 2) || (iVar1 = MSL_C.PPCEABI.bare.H::strncmp(pName,"d_act",5), iVar1 != 0))
      {
        return 0;
      }
      pActor = (fopAc_ac_c *)f_op_actor_mng::fopAcM_fastCreate(pName,0,0,0xffffffff,0,0,0,0);
      if (pActor == (fopAc_ac_c *)0x0) {
        return 0;
      }
      f_op_actor_mng::fopAcM_setStageLayer(pActor);
    }
    uVar2 = dDemo_object_c::appendActor(this->mpRootObject,pActor);
    return uVar2;
  }
  if (objectType == 3) {
    uVar2 = dDemo_object_c::createCamera(this_00);
    return uVar2;
  }
  if (objectType != 4) {
    if (objectType == 5) {
      uVar2 = dDemo_object_c::appendLight(this_00);
      return uVar2;
    }
    if (objectType != 6) {
      return 0;
    }
    uVar2 = dDemo_object_c::createFog(this_00);
    return uVar2;
  }
  uVar2 = dDemo_object_c::createAmbient(this_00);
  return uVar2;
}


/* __thiscall dDemo_manager_c::dDemo_manager_c(void) */

void __thiscall dDemo_manager_c::dDemo_manager_c(dDemo_manager_c *this)

{
  JPAEmitterManager *pJVar1;
  JAIZelBasic *pJVar2;
  undefined *puVar3;
  dMesg_tControl *pdVar4;
  ulong uVar5;
  dDemo_system_c *pDemoSystem;
  TControl *pTVar6;
  undefined **ppuVar7;
  undefined4 *puVar8;
  undefined *puVar9;
  dDemo_system_c *pdVar10;
  
  dDemo_object_c::dDemo_object_c(&this->mDemoObj);
  this->field_0xd0 = (undefined *)0x0;
  this->field_0xd4 = (undefined *)0x0;
  pdVar4 = (dMesg_tControl *)JKernel::operator_new(0x74);
  if (pdVar4 != (dMesg_tControl *)0x0) {
    dMesg_tControl::dMesg_tControl(pdVar4);
  }
  this->mpMesgControl = pdVar4;
  if (this->mpMesgControl == (dMesg_tControl *)0x0) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar5,"d_demo.cpp",0x5b7,"mMesgControl != 0");
    m_Do_printf::OSPanic("d_demo.cpp",0x5b7,&DAT_80351e07);
  }
  pDemoSystem = (dDemo_system_c *)JKernel::operator_new(8);
  if (pDemoSystem != (dDemo_system_c *)0x0) {
    pDemoSystem->vtbl = (undefined *)&JStage::TObject::__vt;
    pDemoSystem->vtbl = &JStage::TSystem::__vt;
    pDemoSystem->vtbl = &dDemo_system_c::__vt;
    pDemoSystem->mpRootObject = (dDemo_object_c *)0x0;
  }
  this->mpSystem = pDemoSystem;
  if (this->mpSystem == (dDemo_system_c *)0x0) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar5,"d_demo.cpp",0x5ba,"mSystem != 0");
    m_Do_printf::OSPanic("d_demo.cpp",0x5ba,&DAT_80351e07);
  }
  pTVar6 = (TControl *)JKernel::operator_new(0xf8);
  if (pTVar6 != (TControl *)0x0) {
    JStudio::TControl::TControl(pTVar6);
  }
  this->mpControl = pTVar6;
  if (this->mpControl == (TControl *)0x0) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar5,"d_demo.cpp",0x5bc,"mControl != 0");
    m_Do_printf::OSPanic("d_demo.cpp",0x5bc,&DAT_80351e07);
  }
  ppuVar7 = (undefined **)JKernel::operator_new(0x10);
  if (ppuVar7 != (undefined **)0x0) {
    pdVar10 = this->mpSystem;
    *ppuVar7 = &JStudio::TCreateObject::__vt;
    ppuVar7[1] = (undefined *)0x0;
    ppuVar7[2] = (undefined *)0x0;
    *ppuVar7 = (undefined *)&JStudio_JStage::TCreateObject::__vt;
    ppuVar7[3] = (undefined *)pdVar10;
  }
  this->mpStage = (undefined *)ppuVar7;
  if (this->mpStage == (undefined *)0x0) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar5,"d_demo.cpp",0x5be,"mStage != 0");
    m_Do_printf::OSPanic("d_demo.cpp",0x5be,&DAT_80351e07);
  }
  puVar8 = (undefined4 *)JKernel::operator_new(0x10);
  pJVar2 = JAIZelBasic::zel_basic;
  if (puVar8 != (undefined4 *)0x0) {
    *puVar8 = &JStudio::TCreateObject::__vt;
    puVar8[1] = 0;
    puVar8[2] = 0;
    *puVar8 = &JStudio_JAudio::TCreateObject::__vt;
    puVar8[3] = pJVar2;
  }
  this->mpAudio = (undefined *)puVar8;
  if (this->mpAudio == (undefined *)0x0) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar5,"d_demo.cpp",0x5c0,"mAudio != 0");
    m_Do_printf::OSPanic("d_demo.cpp",0x5c0,&DAT_80351e07);
  }
  ppuVar7 = (undefined **)JKernel::operator_new(0x14);
  pJVar1 = dPa_control_c::mEmitterMng;
  if (ppuVar7 != (undefined **)0x0) {
    pdVar10 = this->mpSystem;
    *ppuVar7 = &JStudio::TCreateObject::__vt;
    ppuVar7[1] = (undefined *)0x0;
    ppuVar7[2] = (undefined *)0x0;
    *ppuVar7 = (undefined *)&JStudio_JParticle::TCreateObject::__vt;
    ppuVar7[3] = (undefined *)pJVar1;
    ppuVar7[4] = (undefined *)pdVar10;
  }
  this->mpParticle = (undefined *)ppuVar7;
  if (this->mpParticle == (undefined *)0x0) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar5,"d_demo.cpp",0x5c3,"mParticle != 0");
    m_Do_printf::OSPanic("d_demo.cpp",0x5c3,&DAT_80351e07);
  }
  puVar8 = (undefined4 *)JKernel::operator_new(0x10);
  if (puVar8 != (undefined4 *)0x0) {
    pdVar4 = this->mpMesgControl;
    *puVar8 = &JStudio::TCreateObject::__vt;
    puVar8[1] = 0;
    puVar8[2] = 0;
    *puVar8 = &JStudio_JMessage::TCreateObject_base::__vt;
    *puVar8 = &JStudio_JMessage::TCreateObject::__vt;
    puVar8[3] = pdVar4;
  }
  this->mpMessage = (undefined *)puVar8;
  if (this->mpMessage == (undefined *)0x0) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar5,"d_demo.cpp",0x5c6,"mMessage != 0");
    m_Do_printf::OSPanic("d_demo.cpp",0x5c6,&DAT_80351e07);
  }
  puVar8 = (undefined4 *)JKernel::operator_new(0x14);
  if (puVar8 != (undefined4 *)0x0) {
    *puVar8 = &JStudio::stb::TFactory::__vt;
    *puVar8 = &JStudio::TFactory::__vt;
    puVar8[2] = 0;
    puVar8[3] = 0;
    puVar8[1] = 0;
    puVar8[2] = puVar8 + 2;
    puVar8[3] = puVar8 + 2;
    puVar8[4] = &JStudio::fvb::TFactory::__vt;
  }
  this->field_0x14 = (undefined *)puVar8;
  if (this->field_0x14 == (undefined *)0x0) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar5,"d_demo.cpp",0x5c9,"mFactory != 0");
    m_Do_printf::OSPanic("d_demo.cpp",0x5c9,&DAT_80351e07);
  }
  *(double *)&this->mpControl->field_0x58 = d_demo::_4855;
  puVar9 = this->field_0x14;
  pTVar6 = this->mpControl;
  if (puVar9 == (undefined *)0x0) {
    puVar3 = (undefined *)0x0;
  }
  else {
    puVar3 = puVar9 + 0x10;
  }
  *(undefined **)&pTVar6->field_0xc = puVar9;
  *(undefined **)&pTVar6->field_0x64 = puVar3;
  JStudio::TFactory::appendCreateObject((TFactory *)this->field_0x14,(TCreateObject *)this->mpStage)
  ;
  JStudio::TFactory::appendCreateObject((TFactory *)this->field_0x14,(TCreateObject *)this->mpAudio)
  ;
  JStudio::TFactory::appendCreateObject
            ((TFactory *)this->field_0x14,(TCreateObject *)this->mpParticle);
  this->mpSystem->mpRootObject = &this->mDemoObj;
  JStudio::TFactory::appendCreateObject
            ((TFactory *)this->field_0x14,(TCreateObject *)this->mpMessage);
  this->mState = 0;
  return;
}


/* __thiscall dDemo_manager_c::~dDemo_manager_c(void) */

void __thiscall dDemo_manager_c::_dDemo_manager_c(dDemo_manager_c *this)

{
  int *piVar1;
  TControl *pTVar2;
  dDemo_system_c *pdVar3;
  short in_r4;
  
  if (this != (dDemo_manager_c *)0x0) {
    remove(this);
    piVar1 = (int *)this->field_0x14;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1,1);
    }
    piVar1 = (int *)this->mpMessage;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1,1);
    }
    piVar1 = (int *)this->mpParticle;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1,1);
    }
    piVar1 = (int *)this->mpAudio;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1,1);
    }
    piVar1 = (int *)this->mpStage;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1,1);
    }
    pTVar2 = this->mpControl;
    if (pTVar2 != (TControl *)0x0) {
      (**(code **)(*(int *)pTVar2 + 8))(pTVar2,1);
    }
    pdVar3 = this->mpSystem;
    if (pdVar3 != (dDemo_system_c *)0x0) {
      (**(code **)(pdVar3->vtbl + 8))(pdVar3,1);
    }
    piVar1 = (int *)this->mpMesgControl;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1,1);
    }
    dDemo_object_c::_dDemo_object_c(&this->mDemoObj);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dMesg_tControl::~dMesg_tControl(void) */

void __thiscall dMesg_tControl::_dMesg_tControl(dMesg_tControl *this)

{
  short in_r4;
  
  if (this != (dMesg_tControl *)0x0) {
    *(undefined1 **)this = &__vt;
    JMessage::TControl::_TControl((TControl *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dDemo_system_c::~dDemo_system_c(void) */

void __thiscall dDemo_system_c::_dDemo_system_c(dDemo_system_c *this)

{
  short in_r4;
  
  if (this != (dDemo_system_c *)0x0) {
    this->vtbl = &__vt;
    JStage::TSystem::_TSystem((TSystem *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dDemo_manager_c::create(unsigned char const *,
                                      cXyz *,
                                      float) */

undefined4 __thiscall
dDemo_manager_c::create(dDemo_manager_c *this,uchar *param_1,cXyz *pPos,float offsAngY)

{
  char cVar3;
  undefined4 uVar1;
  TControl *pTVar2;
  double dVar4;
  uchar *local_38;
  TParse parse;
  
  dVar4 = (double)offsAngY;
  JStudio::TParse::TParse(&parse,this->mpControl);
  local_38 = param_1;
  cVar3 = JGadget::binary::TParse_header_block::parse_next
                    ((TParse_header_block *)&parse,&local_38,0);
  if (cVar3 == '\0') {
    m_Do_printf::OSReport_Error(&DAT_80351e8d);
    JStudio::TParse::_TParse(&parse);
    uVar1 = 0;
  }
  else {
    JStudio::stb::TControl::forward((TControl *)this->mpControl,0);
    if (pPos == (cXyz *)0x0) {
      pTVar2 = this->mpControl;
      *(undefined *)&pTVar2->field_0x75 = 0;
      *(undefined *)&pTVar2->field_0x74 = 0;
    }
    else {
      pTVar2 = this->mpControl;
      *(undefined *)&pTVar2->field_0x75 = 1;
      *(undefined *)&pTVar2->field_0x74 = 1;
      pTVar2 = this->mpControl;
      JStudio::TControl::transformOnGet_setOrigin(pTVar2,pPos,(float)dVar4);
      JStudio::TControl::transformOnSet_setOrigin(pTVar2,pPos,(float)dVar4);
    }
    this->field_0xd4 = (undefined *)0x0;
    this->field_0xd8 = 0;
    this->field_0xd0 = param_1;
    this->mState = 1;
    JStudio::TParse::_TParse(&parse);
    uVar1 = 1;
  }
  return uVar1;
}


/* __thiscall dDemo_manager_c::remove(void) */

int __thiscall dDemo_manager_c::remove(dDemo_manager_c *this)

{
  int iVar1;
  TControl *this_00;
  
  this_00 = this->mpControl;
  JStudio::stb::TControl::destroyObject_all((TControl *)this_00);
  JStudio::fvb::TControl::destroyObject_all(&this_00->mControlFVB);
  iVar1 = dDemo_object_c::remove(&this->mDemoObj);
  this->field_0xd0 = (undefined *)0x0;
  this->mState = 0;
  return iVar1;
}


/* __thiscall dDemo_manager_c::update(void) */

undefined4 __thiscall dDemo_manager_c::update(dDemo_manager_c *this)

{
  undefined4 uVar1;
  char cVar2;
  
  if (this->field_0xd0 == (undefined *)0x0) {
    uVar1 = 0;
  }
  else {
    cVar2 = JStudio::stb::TControl::forward((TControl *)this->mpControl,1);
    if (cVar2 == '\0') {
      this->mState = 2;
    }
    else {
      this->field_0xd4 = this->field_0xd4 + 1;
      if (*(int *)&this->mpControl->field_0x54 < 1) {
        this->field_0xd8 = this->field_0xd8 + 1;
      }
    }
    uVar1 = 1;
  }
  return uVar1;
}


/* __thiscall dDemo_actor_c::JSGFindNodeID(char const *) const */

void __thiscall dDemo_actor_c::JSGFindNodeID(dDemo_actor_c *this,char *param_1)

{
  ulong uVar1;
  
  if (this->mpModel == (J3DModel *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_demo.h",0x4d,"mModel != 0");
    m_Do_printf::OSPanic("d_demo.h",0x4d,&DAT_80351e07);
  }
  JUTNameTab::getIndex((this->mpModel->mpModelData->mJointTree).mpNameTable,param_1);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dDemo_actor_c::JSGGetNodeTransformation(unsigned long,
                                                      float *[][][][]) const */

undefined4 __thiscall
dDemo_actor_c::JSGGetNodeTransformation(dDemo_actor_c *this,ulong param_1,MTX34 *param_2)

{
  ulong uVar1;
  
  if (this->mpModel == (J3DModel *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_demo.h",0x52,"mModel != 0");
    m_Do_printf::OSPanic("d_demo.h",0x52,&DAT_80351e07);
  }
  mtx::PSMTXCopy(this->mpModel->mpNodeMtx + (param_1 & 0xffff),param_2);
  return 1;
}


/* __thiscall dDemo_actor_c::JSGGetAnimationFrameMax(void) const */

double __thiscall dDemo_actor_c::JSGGetAnimationFrameMax(dDemo_actor_c *this)

{
  return (double)this->mAnimationFrameMax;
}


/* __thiscall dDemo_actor_c::JSGGetTextureAnimationFrameMax(void) const */

double __thiscall dDemo_actor_c::JSGGetTextureAnimationFrameMax(dDemo_actor_c *this)

{
  return (double)(float)this->mTexAnimationFrameMax;
}


/* __thiscall dDemo_actor_c::JSGGetTranslation(Vec *) const */

void __thiscall dDemo_actor_c::JSGGetTranslation(dDemo_actor_c *this,cXyz *param_1)

{
  param_1->x = (this->mTranslation).x;
  param_1->y = (this->mTranslation).y;
  param_1->z = (this->mTranslation).z;
  return;
}


/* __thiscall dDemo_actor_c::JSGGetScaling(Vec *) const */

void __thiscall dDemo_actor_c::JSGGetScaling(dDemo_actor_c *this,Vec *param_1)

{
  *(float *)param_1 = (this->mScaling).x;
  *(float *)(param_1 + 4) = (this->mScaling).y;
  *(float *)(param_1 + 8) = (this->mScaling).z;
  return;
}


/* __thiscall dDemo_actor_c::JSGGetRotation(Vec *) const */

void __thiscall dDemo_actor_c::JSGGetRotation(dDemo_actor_c *this,cXyz *param_1)

{
  double dVar1;
  float fVar2;
  
  fVar2 = d_demo::_4441;
  dVar1 = d_demo::_4087;
  param_1->x = d_demo::_4441 *
               (float)((double)CONCAT44(0x43300000,(int)(this->mRotation).x ^ 0x80000000) -
                      d_demo::_4087);
  param_1->y = fVar2 * (float)((double)CONCAT44(0x43300000,(int)(this->mRotation).y ^ 0x80000000) -
                              dVar1);
  param_1->z = fVar2 * (float)((double)CONCAT44(0x43300000,(int)(this->mRotation).z ^ 0x80000000) -
                              dVar1);
  return;
}

