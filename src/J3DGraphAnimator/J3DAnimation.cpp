#include <J3DGraphAnimator/J3DAnimation.h>
#include <J3DGraphAnimator/J3DAnimation.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JUtility/JUTNameTab.h>
#include <JMath/JMath.h>
#include <JKernel/JKRHeap.h>
#include <J3DAnmColorKey.h>
#include <Demangler/J3DAnmTexPattern.h>
#include <Demangler/J3DAnmTevRegKey.h>
#include <J3DAnmVtxColorFull.h>
#include <J3DAnmClusterFull.h>
#include <J3DAnmVtxColorKey.h>
#include <J3DAnmColorFull.h>
#include <J3DFrameCtrl.h>
#include <J3DAnmTransformFull.h>
#include <J3DAnmClusterKey.h>
#include <J3DAnmVtxColor.h>
#include <Demangler/J3DAnmColor.h>
#include <Demangler/J3DAnmVisibilityFull.h>
#include <J3DAnmCluster.h>
#include <J3DAnmTransformKey.h>
#include <Demangler/J3DAnmTextureSRTKey.h>


/* __thiscall J3DFrameCtrl::init(short) */

int __thiscall J3DFrameCtrl::init(J3DFrameCtrl *this,short ctx)

{
  this->mLoopMode = Repeat;
  this->mFlags = 0;
  this->mStartFrame = 0;
  this->mEndFrame = ctx;
  this->mLoopFrame = 0;
  this->mSpeed = J3DGraphAnimator::_1502;
  this->mCurrentTime = J3DGraphAnimator::_1503;
  return (int)this;
}


/* WARNING: Removing unreachable block (ram,0x802ef630) */
/* __thiscall J3DFrameCtrl::checkPass(float) */

undefined4 __thiscall J3DFrameCtrl::checkPass(J3DFrameCtrl *this,float param_1)

{
  float fVar1;
  J3DFrameCtrl__LoopMode JVar2;
  float fVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  fVar3 = this->mCurrentTime;
  fVar1 = fVar3 + this->mSpeed;
  JVar2 = this->mLoopMode;
  if (JVar2 == Repeat) {
    uVar7 = SEXT24(this->mStartFrame);
    uVar6 = uVar7 ^ 0x80000000;
    if (fVar3 < (float)((double)CONCAT44(0x43300000,uVar6) - J3DGraphAnimator::_1625)) {
      while ((fVar1 < (float)((double)CONCAT44(0x43300000,uVar6) - J3DGraphAnimator::_1625) &&
             (uVar4 = (int)this->mLoopFrame - uVar7 ^ 0x80000000,
             J3DGraphAnimator::_1503 <
             (float)((double)CONCAT44(0x43300000,uVar4) - J3DGraphAnimator::_1625)))) {
        fVar1 = fVar1 + (float)((double)CONCAT44(0x43300000,uVar4) - J3DGraphAnimator::_1625);
      }
      if ((param_1 < fVar1) ||
         ((float)((double)CONCAT44(0x43300000,(int)this->mLoopFrame ^ 0x80000000) -
                 J3DGraphAnimator::_1625) <= param_1)) {
        uVar5 = 0;
      }
      else {
        uVar5 = 1;
      }
    }
    else {
      uVar8 = SEXT24(this->mEndFrame);
      uVar4 = uVar8 ^ 0x80000000;
      if ((float)((double)CONCAT44(0x43300000,uVar4) - J3DGraphAnimator::_1625) <= fVar3) {
        while (((float)((double)CONCAT44(0x43300000,uVar4) - J3DGraphAnimator::_1625) <= fVar1 &&
               (uVar6 = uVar8 - (int)this->mLoopFrame ^ 0x80000000,
               J3DGraphAnimator::_1503 <
               (float)((double)CONCAT44(0x43300000,uVar6) - J3DGraphAnimator::_1625)))) {
          fVar1 = fVar1 - (float)((double)CONCAT44(0x43300000,uVar6) - J3DGraphAnimator::_1625);
        }
        if ((param_1 < (float)((double)CONCAT44(0x43300000,(int)this->mLoopFrame ^ 0x80000000) -
                              J3DGraphAnimator::_1625)) || (fVar1 <= param_1)) {
          uVar5 = 0;
        }
        else {
          uVar5 = 1;
        }
      }
      else {
        if (fVar1 < (float)((double)CONCAT44(0x43300000,uVar6) - J3DGraphAnimator::_1625)) {
          while ((fVar1 < (float)((double)CONCAT44(0x43300000,uVar6) - J3DGraphAnimator::_1625) &&
                 (uVar4 = (int)this->mLoopFrame - uVar7 ^ 0x80000000,
                 J3DGraphAnimator::_1503 <
                 (float)((double)CONCAT44(0x43300000,uVar4) - J3DGraphAnimator::_1625)))) {
            fVar1 = fVar1 + (float)((double)CONCAT44(0x43300000,uVar4) - J3DGraphAnimator::_1625);
          }
          if ((((float)((double)CONCAT44(0x43300000,uVar7 ^ 0x80000000) - J3DGraphAnimator::_1625)
                <= param_1) && (param_1 < fVar3)) ||
             ((fVar1 <= param_1 &&
              (param_1 < (float)((double)CONCAT44(0x43300000,(int)this->mLoopFrame ^ 0x80000000) -
                                J3DGraphAnimator::_1625))))) {
            uVar5 = 1;
          }
          else {
            uVar5 = 0;
          }
        }
        else {
          if (fVar1 < (float)((double)CONCAT44(0x43300000,uVar4) - J3DGraphAnimator::_1625)) {
            if (fVar1 < fVar3) {
              if ((param_1 < fVar1) || (fVar3 <= param_1)) {
                uVar5 = 0;
              }
              else {
                uVar5 = 1;
              }
            }
            else {
              if ((param_1 < fVar3) || (fVar1 <= param_1)) {
                uVar5 = 0;
              }
              else {
                uVar5 = 1;
              }
            }
          }
          else {
            while (((float)((double)CONCAT44(0x43300000,uVar4) - J3DGraphAnimator::_1625) <= fVar1
                   && (uVar6 = uVar8 - (int)this->mLoopFrame ^ 0x80000000,
                      J3DGraphAnimator::_1503 <
                      (float)((double)CONCAT44(0x43300000,uVar6) - J3DGraphAnimator::_1625)))) {
              fVar1 = fVar1 - (float)((double)CONCAT44(0x43300000,uVar6) - J3DGraphAnimator::_1625);
            }
            if (((fVar3 <= param_1) &&
                (param_1 < (float)((double)CONCAT44(0x43300000,uVar8 ^ 0x80000000) -
                                  J3DGraphAnimator::_1625))) ||
               (((float)((double)CONCAT44(0x43300000,(int)this->mLoopFrame ^ 0x80000000) -
                        J3DGraphAnimator::_1625) <= param_1 && (param_1 < fVar1)))) {
              uVar5 = 1;
            }
            else {
              uVar5 = 0;
            }
          }
        }
      }
    }
  }
  else {
    if (JVar2 < Repeat) {
      uVar6 = (int)this->mStartFrame ^ 0x80000000;
      if (fVar1 < (float)((double)CONCAT44(0x43300000,uVar6) - J3DGraphAnimator::_1625)) {
        fVar1 = (float)((double)CONCAT44(0x43300000,uVar6) - J3DGraphAnimator::_1625);
      }
      uVar6 = (int)this->mEndFrame ^ 0x80000000;
      if ((float)((double)CONCAT44(0x43300000,uVar6) - J3DGraphAnimator::_1625) <= fVar1) {
        fVar1 = (float)((double)CONCAT44(0x43300000,uVar6) - J3DGraphAnimator::_1625) -
                J3DGraphAnimator::_1623;
      }
      if (fVar1 < fVar3) {
        if ((param_1 < fVar1) || (fVar3 <= param_1)) {
          uVar5 = 0;
        }
        else {
          uVar5 = 1;
        }
      }
      else {
        if ((param_1 < fVar3) || (fVar1 <= param_1)) {
          uVar5 = 0;
        }
        else {
          uVar5 = 1;
        }
      }
    }
    else {
      if (JVar2 < (OnceAndRepeat|MirroredRepeat)) {
        uVar6 = (int)this->mEndFrame ^ 0x80000000;
        if ((float)((double)CONCAT44(0x43300000,uVar6) - J3DGraphAnimator::_1625) <= fVar1) {
          fVar1 = (float)((double)CONCAT44(0x43300000,uVar6) - J3DGraphAnimator::_1625) -
                  J3DGraphAnimator::_1623;
        }
        uVar6 = (int)this->mStartFrame ^ 0x80000000;
        if (fVar1 < (float)((double)CONCAT44(0x43300000,uVar6) - J3DGraphAnimator::_1625)) {
          fVar1 = (float)((double)CONCAT44(0x43300000,uVar6) - J3DGraphAnimator::_1625);
        }
        if (fVar1 < fVar3) {
          if ((param_1 < fVar1) || (fVar3 <= param_1)) {
            uVar5 = 0;
          }
          else {
            uVar5 = 1;
          }
        }
        else {
          if ((param_1 < fVar3) || (fVar1 <= param_1)) {
            uVar5 = 0;
          }
          else {
            uVar5 = 1;
          }
        }
      }
      else {
        uVar5 = 0;
      }
    }
  }
  return uVar5;
}


/* WARNING: Removing unreachable block (ram,0x802efbe0) */
/* __thiscall J3DFrameCtrl::update(void) */

void __thiscall J3DFrameCtrl::update(J3DFrameCtrl *this)

{
  J3DFrameCtrl__LoopMode JVar1;
  double dVar2;
  float fVar3;
  float fVar4;
  double dVar5;
  uint uVar6;
  
  this->mFlags = 0;
  this->mCurrentTime = this->mCurrentTime + this->mSpeed;
  dVar5 = J3DGraphAnimator::_1625;
  fVar4 = J3DGraphAnimator::_1503;
  JVar1 = this->mLoopMode;
  if (JVar1 != Repeat) {
    if (JVar1 < Repeat) {
      if (JVar1 == Once) {
        uVar6 = (int)this->mStartFrame ^ 0x80000000;
        if (this->mCurrentTime <
            (float)((double)CONCAT44(0x43300000,uVar6) - J3DGraphAnimator::_1625)) {
          this->mCurrentTime = (float)((double)CONCAT44(0x43300000,uVar6) - J3DGraphAnimator::_1625)
          ;
          this->mSpeed = J3DGraphAnimator::_1503;
          this->mFlags = this->mFlags | 1;
        }
        uVar6 = (int)this->mEndFrame ^ 0x80000000;
        if ((float)((double)CONCAT44(0x43300000,uVar6) - J3DGraphAnimator::_1625) <=
            this->mCurrentTime) {
          this->mCurrentTime =
               (float)((double)CONCAT44(0x43300000,uVar6) - J3DGraphAnimator::_1625) -
               J3DGraphAnimator::_1623;
          this->mSpeed = J3DGraphAnimator::_1503;
          this->mFlags = this->mFlags | 1;
        }
      }
      else {
        uVar6 = (int)this->mStartFrame ^ 0x80000000;
        if (this->mCurrentTime <
            (float)((double)CONCAT44(0x43300000,uVar6) - J3DGraphAnimator::_1625)) {
          this->mCurrentTime = (float)((double)CONCAT44(0x43300000,uVar6) - J3DGraphAnimator::_1625)
          ;
          this->mSpeed = J3DGraphAnimator::_1503;
          this->mFlags = this->mFlags | 1;
        }
        if ((float)((double)CONCAT44(0x43300000,(int)this->mEndFrame ^ 0x80000000) -
                   J3DGraphAnimator::_1625) <= this->mCurrentTime) {
          this->mCurrentTime =
               (float)((double)CONCAT44(0x43300000,(int)this->mStartFrame ^ 0x80000000) -
                      J3DGraphAnimator::_1625);
          this->mSpeed = J3DGraphAnimator::_1503;
          this->mFlags = this->mFlags | 1;
        }
      }
    }
    else {
      if (JVar1 == MirroredRepeat) {
        uVar6 = (int)this->mEndFrame ^ 0x80000000;
        if ((float)((double)CONCAT44(0x43300000,uVar6) - J3DGraphAnimator::_1625) <=
            this->mCurrentTime) {
          this->mCurrentTime =
               (float)((double)CONCAT44(0x43300000,uVar6) - J3DGraphAnimator::_1625) -
               J3DGraphAnimator::_1623;
          this->mSpeed = -this->mSpeed;
        }
        uVar6 = (int)this->mStartFrame ^ 0x80000000;
        if (this->mCurrentTime <
            (float)((double)CONCAT44(0x43300000,uVar6) - J3DGraphAnimator::_1625)) {
          this->mCurrentTime = (float)((double)CONCAT44(0x43300000,uVar6) - J3DGraphAnimator::_1625)
          ;
          this->mSpeed = -this->mSpeed;
          this->mFlags = this->mFlags | 2;
        }
      }
      else {
        if (JVar1 < MirroredRepeat) {
          uVar6 = (int)this->mEndFrame ^ 0x80000000;
          if ((float)((double)CONCAT44(0x43300000,uVar6) - J3DGraphAnimator::_1625) <=
              this->mCurrentTime) {
            this->mCurrentTime =
                 (float)((double)CONCAT44(0x43300000,uVar6) - J3DGraphAnimator::_1625) -
                 J3DGraphAnimator::_1623;
            this->mSpeed = -this->mSpeed;
          }
          uVar6 = (int)this->mStartFrame ^ 0x80000000;
          if (this->mCurrentTime <
              (float)((double)CONCAT44(0x43300000,uVar6) - J3DGraphAnimator::_1625)) {
            this->mCurrentTime =
                 (float)((double)CONCAT44(0x43300000,uVar6) - J3DGraphAnimator::_1625);
            this->mSpeed = J3DGraphAnimator::_1503;
            this->mFlags = this->mFlags | 1;
          }
        }
      }
    }
    return;
  }
  while (dVar2 = J3DGraphAnimator::_1625, fVar3 = J3DGraphAnimator::_1503,
        this->mCurrentTime <
        (float)((double)CONCAT44(0x43300000,(int)this->mStartFrame ^ 0x80000000) - dVar5)) {
    this->mFlags = this->mFlags | 2;
    uVar6 = (int)this->mLoopFrame - (int)this->mStartFrame ^ 0x80000000;
    dVar2 = J3DGraphAnimator::_1625;
    fVar3 = J3DGraphAnimator::_1503;
    if ((float)((double)CONCAT44(0x43300000,uVar6) - dVar5) <= fVar4) break;
    this->mCurrentTime = this->mCurrentTime + (float)((double)CONCAT44(0x43300000,uVar6) - dVar5);
  }
  while( true ) {
    if (this->mCurrentTime <
        (float)((double)CONCAT44(0x43300000,(int)this->mEndFrame ^ 0x80000000) - dVar2)) {
      return;
    }
    this->mFlags = this->mFlags | 2;
    uVar6 = (int)this->mEndFrame - (int)this->mLoopFrame ^ 0x80000000;
    if ((float)((double)CONCAT44(0x43300000,uVar6) - dVar2) <= fVar3) break;
    this->mCurrentTime = this->mCurrentTime - (float)((double)CONCAT44(0x43300000,uVar6) - dVar2);
  }
  return;
}


/* __thiscall J3DAnmTransformFull::getTransform(unsigned short,
                                                J3DTransformInfo *) const */

void __thiscall
J3DAnmTransformFull::getTransform
          (J3DAnmTransformFull *this,ushort param_1,J3DTransformInfo *param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  double local_8;
  
  iVar3 = *(int *)(this + 0x24);
  iVar2 = (uint)param_1 * 0x24;
  fVar1 = *(float *)(this + 8);
  if ((fVar1 < J3DGraphAnimator::_1503) ||
     (local_8 = (double)CONCAT44(0x43300000,(uint)*(ushort *)(iVar3 + iVar2)),
     (float)(local_8 - J3DGraphAnimator::_1784) <= fVar1)) {
    if (J3DGraphAnimator::_1503 <= fVar1) {
      (param_2->mScale).x =
           *(float *)(*(int *)(this + 0x10) +
                     ((uint)*(ushort *)(iVar3 + iVar2) + (uint)*(ushort *)(iVar3 + iVar2 + 2) + -1)
                     * 4);
    }
    else {
      (param_2->mScale).x =
           *(float *)(*(int *)(this + 0x10) + (uint)*(ushort *)(iVar3 + iVar2 + 2) * 4);
    }
  }
  else {
    (param_2->mScale).x =
         *(float *)(*(int *)(this + 0x10) + ((int)fVar1 + (uint)*(ushort *)(iVar3 + iVar2 + 2)) * 4)
    ;
  }
  iVar3 = *(int *)(this + 0x24);
  fVar1 = *(float *)(this + 8);
  if ((fVar1 < J3DGraphAnimator::_1503) ||
     (local_8 = (double)CONCAT44(0x43300000,(uint)*(ushort *)(iVar3 + iVar2)),
     (float)(local_8 - J3DGraphAnimator::_1784) <= fVar1)) {
    if (J3DGraphAnimator::_1503 <= fVar1) {
      (param_2->mScale).x =
           *(float *)(*(int *)(this + 0x10) +
                     ((uint)*(ushort *)(iVar3 + iVar2) + (uint)*(ushort *)(iVar3 + iVar2 + 2) + -1)
                     * 4);
    }
    else {
      (param_2->mScale).x =
           *(float *)(*(int *)(this + 0x10) + (uint)*(ushort *)(iVar3 + iVar2 + 2) * 4);
    }
  }
  else {
    (param_2->mScale).x =
         *(float *)(*(int *)(this + 0x10) + ((int)fVar1 + (uint)*(ushort *)(iVar3 + iVar2 + 2)) * 4)
    ;
  }
  iVar3 = *(int *)(this + 0x24);
  uVar4 = (uint)*(ushort *)(iVar3 + iVar2 + 0xc);
  fVar1 = *(float *)(this + 8);
  if ((fVar1 < J3DGraphAnimator::_1503) ||
     (local_8 = (double)CONCAT44(0x43300000,uVar4),
     (float)(local_8 - J3DGraphAnimator::_1784) <= fVar1)) {
    if (J3DGraphAnimator::_1503 <= fVar1) {
      (param_2->mScale).y =
           *(float *)(*(int *)(this + 0x10) + (uVar4 + *(ushort *)(iVar3 + iVar2 + 0xe) + -1) * 4);
    }
    else {
      (param_2->mScale).y =
           *(float *)(*(int *)(this + 0x10) + (uint)*(ushort *)(iVar3 + iVar2 + 0xe) * 4);
    }
  }
  else {
    (param_2->mScale).y =
         *(float *)(*(int *)(this + 0x10) +
                   ((int)fVar1 + (uint)*(ushort *)(iVar3 + iVar2 + 0xe)) * 4);
  }
  iVar3 = *(int *)(this + 0x24);
  uVar4 = (uint)*(ushort *)(iVar3 + iVar2 + 0x18);
  fVar1 = *(float *)(this + 8);
  if ((fVar1 < J3DGraphAnimator::_1503) ||
     (local_8 = (double)CONCAT44(0x43300000,uVar4),
     (float)(local_8 - J3DGraphAnimator::_1784) <= fVar1)) {
    if (J3DGraphAnimator::_1503 <= fVar1) {
      (param_2->mScale).z =
           *(float *)(*(int *)(this + 0x10) + (uVar4 + *(ushort *)(iVar3 + iVar2 + 0x1a) + -1) * 4);
    }
    else {
      (param_2->mScale).z =
           *(float *)(*(int *)(this + 0x10) + (uint)*(ushort *)(iVar3 + iVar2 + 0x1a) * 4);
    }
  }
  else {
    (param_2->mScale).z =
         *(float *)(*(int *)(this + 0x10) +
                   ((int)fVar1 + (uint)*(ushort *)(iVar3 + iVar2 + 0x1a)) * 4);
  }
  iVar3 = *(int *)(this + 0x24);
  uVar4 = (uint)*(ushort *)(iVar3 + iVar2 + 4);
  fVar1 = *(float *)(this + 8);
  if ((fVar1 < J3DGraphAnimator::_1503) ||
     (local_8 = (double)CONCAT44(0x43300000,uVar4),
     (float)(local_8 - J3DGraphAnimator::_1784) <= fVar1)) {
    if (J3DGraphAnimator::_1503 <= fVar1) {
      (param_2->mRot).x =
           *(short *)(*(int *)(this + 0x14) + (uVar4 + *(ushort *)(iVar3 + iVar2 + 6) + -1) * 2);
    }
    else {
      (param_2->mRot).x =
           *(short *)(*(int *)(this + 0x14) + (uint)*(ushort *)(iVar3 + iVar2 + 6) * 2);
    }
  }
  else {
    (param_2->mRot).x =
         *(short *)(*(int *)(this + 0x14) + ((int)fVar1 + (uint)*(ushort *)(iVar3 + iVar2 + 6)) * 2)
    ;
  }
  iVar3 = *(int *)(this + 0x24);
  uVar4 = (uint)*(ushort *)(iVar3 + iVar2 + 0x10);
  fVar1 = *(float *)(this + 8);
  if ((fVar1 < J3DGraphAnimator::_1503) ||
     (local_8 = (double)CONCAT44(0x43300000,uVar4),
     (float)(local_8 - J3DGraphAnimator::_1784) <= fVar1)) {
    if (J3DGraphAnimator::_1503 <= fVar1) {
      (param_2->mRot).y =
           *(short *)(*(int *)(this + 0x14) + (uVar4 + *(ushort *)(iVar3 + iVar2 + 0x12) + -1) * 2);
    }
    else {
      (param_2->mRot).y =
           *(short *)(*(int *)(this + 0x14) + (uint)*(ushort *)(iVar3 + iVar2 + 0x12) * 2);
    }
  }
  else {
    (param_2->mRot).y =
         *(short *)(*(int *)(this + 0x14) +
                   ((int)fVar1 + (uint)*(ushort *)(iVar3 + iVar2 + 0x12)) * 2);
  }
  iVar3 = *(int *)(this + 0x24);
  uVar4 = (uint)*(ushort *)(iVar3 + iVar2 + 0x1c);
  fVar1 = *(float *)(this + 8);
  if ((fVar1 < J3DGraphAnimator::_1503) ||
     (local_8 = (double)CONCAT44(0x43300000,uVar4),
     (float)(local_8 - J3DGraphAnimator::_1784) <= fVar1)) {
    if (J3DGraphAnimator::_1503 <= fVar1) {
      (param_2->mRot).z =
           *(short *)(*(int *)(this + 0x14) + (uVar4 + *(ushort *)(iVar3 + iVar2 + 0x1e) + -1) * 2);
    }
    else {
      (param_2->mRot).z =
           *(short *)(*(int *)(this + 0x14) + (uint)*(ushort *)(iVar3 + iVar2 + 0x1e) * 2);
    }
  }
  else {
    (param_2->mRot).z =
         *(short *)(*(int *)(this + 0x14) +
                   ((int)fVar1 + (uint)*(ushort *)(iVar3 + iVar2 + 0x1e)) * 2);
  }
  iVar3 = *(int *)(this + 0x24);
  uVar4 = (uint)*(ushort *)(iVar3 + iVar2 + 8);
  fVar1 = *(float *)(this + 8);
  if ((fVar1 < J3DGraphAnimator::_1503) ||
     (local_8 = (double)CONCAT44(0x43300000,uVar4),
     (float)(local_8 - J3DGraphAnimator::_1784) <= fVar1)) {
    if (J3DGraphAnimator::_1503 <= fVar1) {
      (param_2->mTranslation).x =
           *(float *)(*(int *)(this + 0x18) + (uVar4 + *(ushort *)(iVar3 + iVar2 + 10) + -1) * 4);
    }
    else {
      (param_2->mTranslation).x =
           *(float *)(*(int *)(this + 0x18) + (uint)*(ushort *)(iVar3 + iVar2 + 10) * 4);
    }
  }
  else {
    (param_2->mTranslation).x =
         *(float *)(*(int *)(this + 0x18) + ((int)fVar1 + (uint)*(ushort *)(iVar3 + iVar2 + 10)) * 4
                   );
  }
  iVar3 = *(int *)(this + 0x24);
  uVar4 = (uint)*(ushort *)(iVar3 + iVar2 + 0x14);
  fVar1 = *(float *)(this + 8);
  if ((fVar1 < J3DGraphAnimator::_1503) ||
     (local_8 = (double)CONCAT44(0x43300000,uVar4),
     (float)(local_8 - J3DGraphAnimator::_1784) <= fVar1)) {
    if (J3DGraphAnimator::_1503 <= fVar1) {
      (param_2->mTranslation).y =
           *(float *)(*(int *)(this + 0x18) + (uVar4 + *(ushort *)(iVar3 + iVar2 + 0x16) + -1) * 4);
    }
    else {
      (param_2->mTranslation).y =
           *(float *)(*(int *)(this + 0x18) + (uint)*(ushort *)(iVar3 + iVar2 + 0x16) * 4);
    }
  }
  else {
    (param_2->mTranslation).y =
         *(float *)(*(int *)(this + 0x18) +
                   ((int)fVar1 + (uint)*(ushort *)(iVar3 + iVar2 + 0x16)) * 4);
  }
  iVar3 = *(int *)(this + 0x24);
  uVar4 = (uint)*(ushort *)(iVar3 + iVar2 + 0x20);
  fVar1 = *(float *)(this + 8);
  if ((J3DGraphAnimator::_1503 <= fVar1) &&
     (local_8 = (double)CONCAT44(0x43300000,uVar4),
     fVar1 < (float)(local_8 - J3DGraphAnimator::_1784))) {
    (param_2->mTranslation).z =
         *(float *)(*(int *)(this + 0x18) +
                   ((int)fVar1 + (uint)*(ushort *)(iVar3 + iVar2 + 0x22)) * 4);
    return;
  }
  if (J3DGraphAnimator::_1503 <= fVar1) {
    (param_2->mTranslation).z =
         *(float *)(*(int *)(this + 0x18) + (uVar4 + *(ushort *)(iVar3 + iVar2 + 0x22) + -1) * 4);
  }
  else {
    (param_2->mTranslation).z =
         *(float *)(*(int *)(this + 0x18) + (uint)*(ushort *)(iVar3 + iVar2 + 0x22) * 4);
  }
  return;
}


namespace J3DGraphAnimator {

/* WARNING: Removing unreachable block (ram,0x802f06f0) */
/* WARNING: Removing unreachable block (ram,0x802f06e0) */
/* WARNING: Removing unreachable block (ram,0x802f06d8) */
/* WARNING: Removing unreachable block (ram,0x802f06dc) */
/* WARNING: Removing unreachable block (ram,0x802f06e8) */
/* WARNING: Removing unreachable block (ram,0x802f06fc) */
/* __stdcall J3DHermiteInterpolationS(float,
                                      short *,
                                      short *,
                                      short *,
                                      short *,
                                      short *,
                                      short *) */

double J3DHermiteInterpolationS
                 (double param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  float fVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  
  uVar2 = __psq_l0(param_2,0x70007);
  uVar4 = __psq_l0(param_5,0x70007);
  uVar3 = __psq_l0(param_3,0x70007);
  dVar7 = (double)(float)((double)CONCAT44(uVar4,0x3f800000) - (double)CONCAT44(uVar2,0x3f800000));
  uVar5 = __psq_l0(param_6,0x70007);
  uVar4 = __psq_l0(param_7,0x70007);
  dVar8 = (double)(float)((double)(float)(param_1 - (double)CONCAT44(uVar2,0x3f800000)) / dVar7);
  uVar2 = __psq_l0(param_4,0x70007);
  fVar1 = -(float)(dVar7 * (double)CONCAT44(uVar2,0x3f800000) -
                  (double)(float)((double)CONCAT44(uVar5,0x3f800000) -
                                 (double)CONCAT44(uVar3,0x3f800000)));
  dVar6 = (double)((float)(dVar8 * dVar8) *
                  ((float)((double)(float)((double)CONCAT44(uVar4,0x3f800000) * dVar7 +
                                          (double)CONCAT44(uVar3,0x3f800000)) -
                          (double)CONCAT44(uVar5,0x3f800000)) - fVar1));
  return (double)(float)((double)(fVar1 * (float)(dVar8 * dVar8) +
                                 (float)((double)(float)(dVar7 * (double)CONCAT44(uVar2,0x3f800000)
                                                        + dVar6) * dVar8 +
                                        (double)CONCAT44(uVar3,0x3f800000))) - dVar6);
}


/* __stdcall J3DGetKeyFrameInterpolationS(float,
                                          J3DAnmKeyTableBase *,
                                          short *) */

double J3DGetKeyFrameInterpolationS(double param_1,ushort *param_2,short *param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  double dVar4;
  
  if (param_2[2] == 0) {
    if ((double)(float)((double)CONCAT44(0x43300000,(int)*param_3 ^ 0x80000000) - _1625) <= param_1)
    {
      iVar1 = *param_2 - 1;
      uVar3 = (uint)*param_2;
      if (param_1 < (double)(float)((double)CONCAT44(0x43300000,(int)param_3[iVar1 * 3] ^ 0x80000000
                                                    ) - _1625)) {
        while (uVar2 = uVar3, 1 < (int)uVar2) {
          uVar3 = ((int)uVar2 >> 1) + (uint)((int)uVar2 < 0 && (uVar2 & 1) != 0);
          if ((double)(float)((double)CONCAT44(0x43300000,(int)param_3[uVar3 * 3] ^ 0x80000000) -
                             _1625) <= param_1) {
            param_3 = param_3 + uVar3 * 3;
            uVar3 = uVar2 - uVar3;
          }
        }
        dVar4 = (double)J3DHermiteInterpolationS
                                  (param_3,param_3 + 1,param_3 + 2,param_3 + 3,param_3 + 4,
                                   param_3 + 5);
      }
      else {
        dVar4 = (double)(float)((double)CONCAT44(0x43300000,(int)param_3[iVar1 * 3 + 1] ^ 0x80000000
                                                ) - _1625);
      }
    }
    else {
      dVar4 = (double)(float)((double)CONCAT44(0x43300000,(int)param_3[1] ^ 0x80000000) - _1625);
    }
  }
  else {
    if ((double)(float)((double)CONCAT44(0x43300000,(int)*param_3 ^ 0x80000000) - _1625) <= param_1)
    {
      iVar1 = *param_2 - 1;
      uVar3 = (uint)*param_2;
      if (param_1 < (double)(float)((double)CONCAT44(0x43300000,(int)param_3[iVar1 * 4] ^ 0x80000000
                                                    ) - _1625)) {
        while (uVar2 = uVar3, 1 < (int)uVar2) {
          uVar3 = ((int)uVar2 >> 1) + (uint)((int)uVar2 < 0 && (uVar2 & 1) != 0);
          if ((double)(float)((double)CONCAT44(0x43300000,(int)param_3[uVar3 * 4] ^ 0x80000000) -
                             _1625) <= param_1) {
            param_3 = param_3 + uVar3 * 4;
            uVar3 = uVar2 - uVar3;
          }
        }
        dVar4 = (double)J3DHermiteInterpolationS
                                  (param_3,param_3 + 1,param_3 + 3,param_3 + 4,param_3 + 5,
                                   param_3 + 6);
      }
      else {
        dVar4 = (double)(float)((double)CONCAT44(0x43300000,(int)param_3[iVar1 * 4 + 1] ^ 0x80000000
                                                ) - _1625);
      }
    }
    else {
      dVar4 = (double)(float)((double)CONCAT44(0x43300000,(int)param_3[1] ^ 0x80000000) - _1625);
    }
  }
  return dVar4;
}

}

/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x802f0da4) */
/* WARNING: Removing unreachable block (ram,0x802f0cb8) */
/* WARNING: Removing unreachable block (ram,0x802f0b88) */
/* WARNING: Removing unreachable block (ram,0x802f0a84) */
/* WARNING: Removing unreachable block (ram,0x802f09a4) */
/* WARNING: Removing unreachable block (ram,0x802f0a0c) */
/* WARNING: Removing unreachable block (ram,0x802f0afc) */
/* WARNING: Removing unreachable block (ram,0x802f0c20) */
/* WARNING: Removing unreachable block (ram,0x802f0d28) */
/* WARNING: Removing unreachable block (ram,0x802f0e00) */
/* __thiscall J3DAnmTransformKey::calcTransform(float,
                                                unsigned short,
                                                J3DTransformInfo *) const */

void __thiscall
J3DAnmTransformKey::calcTransform
          (J3DAnmTransformKey *this,float param_1,ushort param_2,J3DTransformInfo *param_3)

{
  short sVar1;
  uint uVar2;
  short *psVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  double dVar7;
  double dVar8;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  dVar8 = (double)param_1;
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  uVar2 = (uint)param_2;
  iVar5 = uVar2 * 0x36;
  psVar3 = (short *)(*(int *)&this->field_0x28 + iVar5);
  if (*psVar3 == 1) {
    (param_3->mScale).x =
         *(float *)(*(int *)&(this->parent).field_0x10 + (uint)(ushort)psVar3[1] * 4);
  }
  else {
    if (*psVar3 == 0) {
      (param_3->mScale).x = J3DGraphAnimator::_1502;
    }
    else {
      dVar7 = (double)J3DGraphAnimator::J3DGetKeyFrameInterpolation
                                (dVar8,psVar3,
                                 *(int *)&(this->parent).field_0x10 +
                                 (uint)*(ushort *)(*(int *)&this->field_0x28 + iVar5 + 2) * 4);
      (param_3->mScale).x = (float)dVar7;
    }
  }
  iVar4 = *(int *)&this->field_0x28;
  sVar1 = *(short *)(iVar4 + iVar5 + 0x12);
  if (sVar1 == 1) {
    (param_3->mScale).y =
         *(float *)(*(int *)&(this->parent).field_0x10 + (uint)*(ushort *)(iVar4 + iVar5 + 0x14) * 4
                   );
  }
  else {
    if (sVar1 == 0) {
      (param_3->mScale).y = J3DGraphAnimator::_1502;
    }
    else {
      dVar7 = (double)J3DGraphAnimator::J3DGetKeyFrameInterpolation
                                (dVar8,iVar4 + (uVar2 * 3 + 1) * 0x12,
                                 *(int *)&(this->parent).field_0x10 +
                                 (uint)*(ushort *)(iVar4 + iVar5 + 0x14) * 4);
      (param_3->mScale).y = (float)dVar7;
    }
  }
  iVar4 = *(int *)&this->field_0x28;
  sVar1 = *(short *)(iVar4 + iVar5 + 0x24);
  if (sVar1 == 1) {
    (param_3->mScale).z =
         *(float *)(*(int *)&(this->parent).field_0x10 + (uint)*(ushort *)(iVar4 + iVar5 + 0x26) * 4
                   );
  }
  else {
    if (sVar1 == 0) {
      (param_3->mScale).z = J3DGraphAnimator::_1502;
    }
    else {
      dVar7 = (double)J3DGraphAnimator::J3DGetKeyFrameInterpolation
                                (dVar8,iVar4 + (uVar2 * 3 + 2) * 0x12,
                                 *(int *)&(this->parent).field_0x10 +
                                 (uint)*(ushort *)(iVar4 + iVar5 + 0x26) * 4);
      (param_3->mScale).z = (float)dVar7;
    }
  }
  iVar4 = *(int *)&this->field_0x28;
  sVar1 = *(short *)(iVar4 + iVar5 + 6);
  if (sVar1 == 1) {
    (param_3->mRot).x =
         (short)((int)*(short *)(*(int *)&(this->parent).field_0x14 +
                                (uint)*(ushort *)(iVar4 + iVar5 + 8) * 2) <<
                *(int *)&this->field_0x24);
  }
  else {
    if (sVar1 == 0) {
      (param_3->mRot).x = 0;
    }
    else {
      dVar7 = (double)J3DGraphAnimator::J3DGetKeyFrameInterpolationS
                                (dVar8,iVar4 + iVar5 + 6,
                                 *(int *)&(this->parent).field_0x14 +
                                 (uint)*(ushort *)(iVar4 + iVar5 + 8) * 2);
      (param_3->mRot).x = (short)((int)dVar7 << *(int *)&this->field_0x24);
    }
  }
  iVar4 = *(int *)&this->field_0x28;
  sVar1 = *(short *)(iVar4 + iVar5 + 0x18);
  if (sVar1 == 1) {
    (param_3->mRot).y =
         (short)((int)*(short *)(*(int *)&(this->parent).field_0x14 +
                                (uint)*(ushort *)(iVar4 + iVar5 + 0x1a) * 2) <<
                *(int *)&this->field_0x24);
  }
  else {
    if (sVar1 == 0) {
      (param_3->mRot).y = 0;
    }
    else {
      dVar7 = (double)J3DGraphAnimator::J3DGetKeyFrameInterpolationS
                                (dVar8,iVar4 + (uVar2 * 3 + 1) * 0x12 + 6,
                                 *(int *)&(this->parent).field_0x14 +
                                 (uint)*(ushort *)(iVar4 + iVar5 + 0x1a) * 2);
      (param_3->mRot).y = (short)((int)dVar7 << *(int *)&this->field_0x24);
    }
  }
  iVar4 = *(int *)&this->field_0x28;
  sVar1 = *(short *)(iVar4 + iVar5 + 0x2a);
  if (sVar1 == 1) {
    (param_3->mRot).z =
         (short)((int)*(short *)(*(int *)&(this->parent).field_0x14 +
                                (uint)*(ushort *)(iVar4 + iVar5 + 0x2c) * 2) <<
                *(int *)&this->field_0x24);
  }
  else {
    if (sVar1 == 0) {
      (param_3->mRot).z = 0;
    }
    else {
      dVar7 = (double)J3DGraphAnimator::J3DGetKeyFrameInterpolationS
                                (dVar8,iVar4 + (uVar2 * 3 + 2) * 0x12 + 6,
                                 *(int *)&(this->parent).field_0x14 +
                                 (uint)*(ushort *)(iVar4 + iVar5 + 0x2c) * 2);
      (param_3->mRot).z = (short)((int)dVar7 << *(int *)&this->field_0x24);
    }
  }
  iVar4 = *(int *)&this->field_0x28;
  sVar1 = *(short *)(iVar4 + iVar5 + 0xc);
  if (sVar1 == 1) {
    (param_3->mTranslation).x =
         *(float *)(*(int *)&(this->parent).field_0x18 + (uint)*(ushort *)(iVar4 + iVar5 + 0xe) * 4)
    ;
  }
  else {
    if (sVar1 == 0) {
      (param_3->mTranslation).x = J3DGraphAnimator::_1503;
    }
    else {
      dVar7 = (double)J3DGraphAnimator::J3DGetKeyFrameInterpolation
                                (dVar8,iVar4 + iVar5 + 0xc,
                                 *(int *)&(this->parent).field_0x18 +
                                 (uint)*(ushort *)(iVar4 + iVar5 + 0xe) * 4);
      (param_3->mTranslation).x = (float)dVar7;
    }
  }
  iVar4 = *(int *)&this->field_0x28;
  sVar1 = *(short *)(iVar4 + iVar5 + 0x1e);
  if (sVar1 == 1) {
    (param_3->mTranslation).y =
         *(float *)(*(int *)&(this->parent).field_0x18 + (uint)*(ushort *)(iVar4 + iVar5 + 0x20) * 4
                   );
  }
  else {
    if (sVar1 == 0) {
      (param_3->mTranslation).y = J3DGraphAnimator::_1503;
    }
    else {
      dVar7 = (double)J3DGraphAnimator::J3DGetKeyFrameInterpolation
                                (dVar8,iVar4 + (uVar2 * 3 + 1) * 0x12 + 0xc,
                                 *(int *)&(this->parent).field_0x18 +
                                 (uint)*(ushort *)(iVar4 + iVar5 + 0x20) * 4);
      (param_3->mTranslation).y = (float)dVar7;
    }
  }
  iVar4 = *(int *)&this->field_0x28;
  sVar1 = *(short *)(iVar4 + iVar5 + 0x30);
  if (sVar1 == 1) {
    (param_3->mTranslation).z =
         *(float *)(*(int *)&(this->parent).field_0x18 + (uint)*(ushort *)(iVar4 + iVar5 + 0x32) * 4
                   );
  }
  else {
    if (sVar1 == 0) {
      (param_3->mTranslation).z = J3DGraphAnimator::_1503;
    }
    else {
      dVar8 = (double)J3DGraphAnimator::J3DGetKeyFrameInterpolation
                                (dVar8,iVar4 + (uVar2 * 3 + 2) * 0x12 + 0xc,
                                 *(int *)&(this->parent).field_0x18 +
                                 (uint)*(ushort *)(iVar4 + iVar5 + 0x32) * 4);
      (param_3->mTranslation).z = (float)dVar8;
    }
  }
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x802f1058) */
/* WARNING: Removing unreachable block (ram,0x802f0f50) */
/* WARNING: Removing unreachable block (ram,0x802f0e70) */
/* WARNING: Removing unreachable block (ram,0x802f0ed8) */
/* WARNING: Removing unreachable block (ram,0x802f0fe8) */
/* WARNING: Removing unreachable block (ram,0x802f10b4) */
/* __thiscall J3DAnmTextureSRTKey::calcTransform(float,
                                                 unsigned short,
                                                 J3DTextureSRTInfo *) const */

void __thiscall
J3DAnmTextureSRTKey::calcTransform
          (J3DAnmTextureSRTKey *this,float param_1,ushort param_2,J3DTextureSRTInfo *param_3)

{
  short sVar1;
  uint uVar2;
  short *psVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  double dVar7;
  double dVar8;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  dVar8 = (double)param_1;
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  uVar2 = (uint)param_2;
  iVar5 = uVar2 * 0x36;
  psVar3 = (short *)(*(int *)&this->field_0x18 + iVar5);
  if (*psVar3 == 1) {
    param_3->mScaleX = *(float *)(*(int *)&this->field_0x24 + (uint)(ushort)psVar3[1] * 4);
  }
  else {
    if (*psVar3 == 0) {
      param_3->mScaleX = J3DGraphAnimator::_1502;
    }
    else {
      dVar7 = (double)J3DGraphAnimator::J3DGetKeyFrameInterpolation
                                (dVar8,psVar3,
                                 *(int *)&this->field_0x24 +
                                 (uint)*(ushort *)(*(int *)&this->field_0x18 + iVar5 + 2) * 4);
      param_3->mScaleX = (float)dVar7;
    }
  }
  iVar4 = *(int *)&this->field_0x18;
  sVar1 = *(short *)(iVar4 + iVar5 + 0x12);
  if (sVar1 == 1) {
    param_3->mScaleY =
         *(float *)(*(int *)&this->field_0x24 + (uint)*(ushort *)(iVar4 + iVar5 + 0x14) * 4);
  }
  else {
    if (sVar1 == 0) {
      param_3->mScaleY = J3DGraphAnimator::_1502;
    }
    else {
      dVar7 = (double)J3DGraphAnimator::J3DGetKeyFrameInterpolation
                                (dVar8,iVar4 + (uVar2 * 3 + 1) * 0x12,
                                 *(int *)&this->field_0x24 +
                                 (uint)*(ushort *)(iVar4 + iVar5 + 0x14) * 4);
      param_3->mScaleY = (float)dVar7;
    }
  }
  iVar4 = *(int *)&this->field_0x18;
  sVar1 = *(short *)(iVar4 + iVar5 + 0x2a);
  if (sVar1 == 1) {
    param_3->mRotation =
         (short)((int)*(short *)(*(int *)&this->field_0x28 +
                                (uint)*(ushort *)(iVar4 + iVar5 + 0x2c) * 2) <<
                (int)this->field_0x10);
  }
  else {
    if (sVar1 == 0) {
      param_3->mRotation = 0;
    }
    else {
      dVar7 = (double)J3DGraphAnimator::J3DGetKeyFrameInterpolationS
                                (dVar8,iVar4 + (uVar2 * 3 + 2) * 0x12 + 6,
                                 *(int *)&this->field_0x28 +
                                 (uint)*(ushort *)(iVar4 + iVar5 + 0x2c) * 2);
      param_3->mRotation = (short)((int)dVar7 << (int)this->field_0x10);
    }
  }
  iVar4 = *(int *)&this->field_0x18;
  sVar1 = *(short *)(iVar4 + iVar5 + 0xc);
  if (sVar1 == 1) {
    param_3->mTransX =
         *(float *)(*(int *)&this->field_0x2c + (uint)*(ushort *)(iVar4 + iVar5 + 0xe) * 4);
  }
  else {
    if (sVar1 == 0) {
      param_3->mTransX = J3DGraphAnimator::_1503;
    }
    else {
      dVar7 = (double)J3DGraphAnimator::J3DGetKeyFrameInterpolation
                                (dVar8,iVar4 + iVar5 + 0xc,
                                 *(int *)&this->field_0x2c +
                                 (uint)*(ushort *)(iVar4 + iVar5 + 0xe) * 4);
      param_3->mTransX = (float)dVar7;
    }
  }
  iVar4 = *(int *)&this->field_0x18;
  sVar1 = *(short *)(iVar4 + iVar5 + 0x1e);
  if (sVar1 == 1) {
    param_3->mTransY =
         *(float *)(*(int *)&this->field_0x2c + (uint)*(ushort *)(iVar4 + iVar5 + 0x20) * 4);
  }
  else {
    if (sVar1 == 0) {
      param_3->mTransY = J3DGraphAnimator::_1503;
    }
    else {
      dVar8 = (double)J3DGraphAnimator::J3DGetKeyFrameInterpolation
                                (dVar8,iVar4 + (uVar2 * 3 + 1) * 0x12 + 0xc,
                                 *(int *)&this->field_0x2c +
                                 (uint)*(ushort *)(iVar4 + iVar5 + 0x20) * 4);
      param_3->mTransY = (float)dVar8;
    }
  }
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  return;
}


/* __thiscall J3DAnmClusterFull::getWeight(unsigned short) const */

double __thiscall J3DAnmClusterFull::getWeight(J3DAnmClusterFull *this,ushort param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  double local_8;
  
  iVar3 = *(int *)(this + 0x14);
  iVar2 = (uint)param_1 * 4;
  fVar1 = *(float *)(this + 8);
  if ((J3DGraphAnimator::_1503 <= fVar1) &&
     (local_8 = (double)CONCAT44(0x43300000,(uint)*(ushort *)(iVar3 + iVar2)),
     fVar1 < (float)(local_8 - J3DGraphAnimator::_1784))) {
    return (double)*(float *)(*(int *)(this + 0x10) +
                             ((int)fVar1 + (uint)*(ushort *)(iVar3 + iVar2 + 2)) * 4);
  }
  if (J3DGraphAnimator::_1503 <= fVar1) {
    fVar1 = *(float *)(*(int *)(this + 0x10) +
                      ((uint)*(ushort *)(iVar3 + iVar2) + (uint)*(ushort *)(iVar3 + iVar2 + 2) + -1)
                      * 4);
  }
  else {
    fVar1 = *(float *)(*(int *)(this + 0x10) + (uint)*(ushort *)(iVar3 + iVar2 + 2) * 4);
  }
  return (double)fVar1;
}


/* __thiscall J3DAnmClusterKey::getWeight(unsigned short) const */

double __thiscall J3DAnmClusterKey::getWeight(J3DAnmClusterKey *this,ushort param_1)

{
  short sVar1;
  short *psVar2;
  double dVar3;
  
  psVar2 = (short *)(*(int *)(this + 0x14) + (uint)param_1 * 6);
  sVar1 = *psVar2;
  if ((sVar1 == 0) || (sVar1 == 1)) {
    if (sVar1 == 0) {
      dVar3 = (double)J3DGraphAnimator::_1502;
    }
    else {
      dVar3 = (double)*(float *)(*(int *)(this + 0x10) +
                                (uint)*(ushort *)(*(int *)(this + 0x14) + (uint)param_1 * 6 + 2) * 4
                                );
    }
  }
  else {
    dVar3 = (double)J3DGraphAnimator::J3DGetKeyFrameInterpolation
                              ((double)*(float *)(this + 8),psVar2,
                               *(int *)(this + 0x10) + (uint)(ushort)psVar2[1] * 4);
  }
  return dVar3;
}


/* __thiscall J3DAnmVtxColorFull::getColor(unsigned char,
                                           unsigned short,
                                           _GXColor *) const */

void __thiscall
J3DAnmVtxColorFull::getColor
          (J3DAnmVtxColorFull *this,uchar param_1,ushort param_2,_GXColor *param_3)

{
  float fVar1;
  int iVar2;
  J3DAnmVtxColorFull *pJVar3;
  uint uVar4;
  int iVar5;
  double local_8;
  
  pJVar3 = this + (uint)param_1 * 4;
  iVar5 = *(int *)(pJVar3 + 0x1c);
  iVar2 = (uint)param_2 * 0x10;
  fVar1 = *(float *)(this + 8);
  if ((fVar1 < J3DGraphAnimator::_1503) ||
     (local_8 = (double)CONCAT44(0x43300000,(uint)*(ushort *)(iVar5 + iVar2)),
     (float)(local_8 - J3DGraphAnimator::_1784) <= fVar1)) {
    if (J3DGraphAnimator::_1503 <= fVar1) {
      param_3->r = *(u8 *)(*(int *)(this + 0x24) + (uint)*(ushort *)(iVar5 + iVar2) +
                           (uint)*(ushort *)(iVar5 + iVar2 + 2) + -1);
    }
    else {
      param_3->r = *(u8 *)(*(int *)(this + 0x24) + (uint)*(ushort *)(iVar5 + iVar2 + 2));
    }
  }
  else {
    param_3->r = *(u8 *)(*(int *)(this + 0x24) + (int)fVar1 + (uint)*(ushort *)(iVar5 + iVar2 + 2));
  }
  iVar5 = *(int *)(pJVar3 + 0x1c);
  uVar4 = (uint)*(ushort *)(iVar5 + iVar2 + 4);
  fVar1 = *(float *)(this + 8);
  if ((fVar1 < J3DGraphAnimator::_1503) ||
     (local_8 = (double)CONCAT44(0x43300000,uVar4),
     (float)(local_8 - J3DGraphAnimator::_1784) <= fVar1)) {
    if (J3DGraphAnimator::_1503 <= fVar1) {
      param_3->g = *(u8 *)(*(int *)(this + 0x28) + uVar4 + (uint)*(ushort *)(iVar5 + iVar2 + 6) + -1
                          );
    }
    else {
      param_3->g = *(u8 *)(*(int *)(this + 0x28) + (uint)*(ushort *)(iVar5 + iVar2 + 6));
    }
  }
  else {
    param_3->g = *(u8 *)(*(int *)(this + 0x28) + (int)fVar1 + (uint)*(ushort *)(iVar5 + iVar2 + 6));
  }
  iVar5 = *(int *)(pJVar3 + 0x1c);
  uVar4 = (uint)*(ushort *)(iVar5 + iVar2 + 8);
  fVar1 = *(float *)(this + 8);
  if ((fVar1 < J3DGraphAnimator::_1503) ||
     (local_8 = (double)CONCAT44(0x43300000,uVar4),
     (float)(local_8 - J3DGraphAnimator::_1784) <= fVar1)) {
    if (J3DGraphAnimator::_1503 <= fVar1) {
      param_3->b = *(u8 *)(*(int *)(this + 0x2c) + uVar4 + (uint)*(ushort *)(iVar5 + iVar2 + 10) +
                          -1);
    }
    else {
      param_3->b = *(u8 *)(*(int *)(this + 0x2c) + (uint)*(ushort *)(iVar5 + iVar2 + 10));
    }
  }
  else {
    param_3->b = *(u8 *)(*(int *)(this + 0x2c) + (int)fVar1 + (uint)*(ushort *)(iVar5 + iVar2 + 10))
    ;
  }
  iVar5 = *(int *)(pJVar3 + 0x1c);
  uVar4 = (uint)*(ushort *)(iVar5 + iVar2 + 0xc);
  fVar1 = *(float *)(this + 8);
  if ((J3DGraphAnimator::_1503 <= fVar1) &&
     (local_8 = (double)CONCAT44(0x43300000,uVar4),
     fVar1 < (float)(local_8 - J3DGraphAnimator::_1784))) {
    param_3->a = *(u8 *)(*(int *)(this + 0x30) + (int)fVar1 + (uint)*(ushort *)(iVar5 + iVar2 + 0xe)
                        );
    return;
  }
  if (J3DGraphAnimator::_1503 <= fVar1) {
    param_3->a = *(u8 *)(*(int *)(this + 0x30) + uVar4 + (uint)*(ushort *)(iVar5 + iVar2 + 0xe) + -1
                        );
  }
  else {
    param_3->a = *(u8 *)(*(int *)(this + 0x30) + (uint)*(ushort *)(iVar5 + iVar2 + 0xe));
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x802f1798) */
/* WARNING: Removing unreachable block (ram,0x802f16e4) */
/* WARNING: Removing unreachable block (ram,0x802f1630) */
/* WARNING: Removing unreachable block (ram,0x802f157c) */
/* WARNING: Removing unreachable block (ram,0x802f1508) */
/* WARNING: Removing unreachable block (ram,0x802f15b4) */
/* WARNING: Removing unreachable block (ram,0x802f1668) */
/* WARNING: Removing unreachable block (ram,0x802f171c) */
/* WARNING: Removing unreachable block (ram,0x802f17b0) */
/* __thiscall J3DAnmVtxColorKey::getColor(unsigned char,
                                          unsigned short,
                                          _GXColor *) const */

void __thiscall
J3DAnmVtxColorKey::getColor(J3DAnmVtxColorKey *this,uchar param_1,ushort param_2,_GXColor *param_3)

{
  short sVar1;
  short *psVar2;
  int iVar3;
  J3DAnmVtxColorKey *pJVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  double dVar8;
  undefined8 in_f31;
  u8 local_38 [4];
  u8 local_34 [4];
  u8 local_30 [4];
  u8 local_2c [12];
  undefined auStack8 [8];
  
  uVar7 = 0x40004;
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  pJVar4 = this + (uint)param_1 * 4;
  iVar5 = (uint)param_2 * 0x18;
  psVar2 = (short *)(*(int *)(pJVar4 + 0x1c) + iVar5);
  if (*psVar2 == 1) {
    param_3->r = (u8)*(undefined2 *)(*(int *)(this + 0x24) + (uint)(ushort)psVar2[1] * 2);
  }
  else {
    if (*psVar2 == 0) {
      param_3->r = 0;
    }
    else {
      dVar8 = (double)J3DGraphAnimator::J3DGetKeyFrameInterpolationS
                                ((double)*(float *)(this + 8),psVar2,
                                 *(int *)(this + 0x24) +
                                 (uint)*(ushort *)(*(int *)(pJVar4 + 0x1c) + iVar5 + 2) * 2);
      if ((double)J3DGraphAnimator::_1503 < dVar8) {
        if ((double)J3DGraphAnimator::_2108 < dVar8) {
          param_3->r = 0xff;
        }
        else {
          __psq_st0(local_2c,(int)((ulonglong)dVar8 >> 0x20),uVar7);
          param_3->r = local_2c[0];
        }
      }
      else {
        param_3->r = 0;
      }
    }
  }
  iVar3 = *(int *)(pJVar4 + 0x1c);
  sVar1 = *(short *)(iVar3 + iVar5 + 6);
  if (sVar1 == 1) {
    param_3->g = (u8)*(undefined2 *)
                      (*(int *)(this + 0x28) + (uint)*(ushort *)(iVar3 + iVar5 + 8) * 2);
  }
  else {
    if (sVar1 == 0) {
      param_3->g = 0;
    }
    else {
      dVar8 = (double)J3DGraphAnimator::J3DGetKeyFrameInterpolationS
                                ((double)*(float *)(this + 8),iVar3 + iVar5 + 6,
                                 *(int *)(this + 0x28) + (uint)*(ushort *)(iVar3 + iVar5 + 8) * 2);
      if ((double)J3DGraphAnimator::_1503 < dVar8) {
        if ((double)J3DGraphAnimator::_2108 < dVar8) {
          param_3->g = 0xff;
        }
        else {
          __psq_st0(local_30,(int)((ulonglong)dVar8 >> 0x20),uVar7);
          param_3->g = local_30[0];
        }
      }
      else {
        param_3->g = 0;
      }
    }
  }
  iVar3 = *(int *)(pJVar4 + 0x1c);
  sVar1 = *(short *)(iVar3 + iVar5 + 0xc);
  if (sVar1 == 1) {
    param_3->b = (u8)*(undefined2 *)
                      (*(int *)(this + 0x2c) + (uint)*(ushort *)(iVar3 + iVar5 + 0xe) * 2);
  }
  else {
    if (sVar1 == 0) {
      param_3->b = 0;
    }
    else {
      dVar8 = (double)J3DGraphAnimator::J3DGetKeyFrameInterpolationS
                                ((double)*(float *)(this + 8),iVar3 + iVar5 + 0xc,
                                 *(int *)(this + 0x2c) + (uint)*(ushort *)(iVar3 + iVar5 + 0xe) * 2)
      ;
      if ((double)J3DGraphAnimator::_1503 < dVar8) {
        if ((double)J3DGraphAnimator::_2108 < dVar8) {
          param_3->b = 0xff;
        }
        else {
          __psq_st0(local_34,(int)((ulonglong)dVar8 >> 0x20),uVar7);
          param_3->b = local_34[0];
        }
      }
      else {
        param_3->b = 0;
      }
    }
  }
  iVar3 = *(int *)(pJVar4 + 0x1c);
  sVar1 = *(short *)(iVar3 + iVar5 + 0x12);
  if (sVar1 == 1) {
    param_3->a = (u8)*(undefined2 *)
                      (*(int *)(this + 0x30) + (uint)*(ushort *)(iVar3 + iVar5 + 0x14) * 2);
  }
  else {
    if (sVar1 == 0) {
      param_3->a = 0;
    }
    else {
      dVar8 = (double)J3DGraphAnimator::J3DGetKeyFrameInterpolationS
                                ((double)*(float *)(this + 8),iVar3 + iVar5 + 0x12,
                                 *(int *)(this + 0x30) + (uint)*(ushort *)(iVar3 + iVar5 + 0x14) * 2
                                );
      if ((double)J3DGraphAnimator::_1503 < dVar8) {
        if ((double)J3DGraphAnimator::_2108 < dVar8) {
          param_3->a = 0xff;
        }
        else {
          __psq_st0(local_38,(int)((ulonglong)dVar8 >> 0x20),uVar7);
          param_3->a = local_38[0];
        }
      }
      else {
        param_3->a = 0;
      }
    }
  }
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall J3DAnmColor::searchUpdateMaterialID(J3DMaterialTable *) */

void __thiscall J3DAnmColor::searchUpdateMaterialID(J3DAnmColor *this,J3DMaterialTable *param_1)

{
  char *pcVar1;
  int iVar2;
  ushort uVar3;
  JUTNameTab *this_00;
  
  for (uVar3 = 0; uVar3 < *(ushort *)(this + 0x18); uVar3 = uVar3 + 1) {
    this_00 = param_1->mpNameTab;
    pcVar1 = (char *)JUTNameTab::getName((JUTNameTab *)(this + 0x20),uVar3);
    iVar2 = JUTNameTab::getIndex(this_00,pcVar1);
    if (iVar2 == -1) {
      *(undefined2 *)(*(int *)(this + 0x1c) + (uint)uVar3 * 2) = 0xffff;
    }
    else {
      *(short *)(*(int *)(this + 0x1c) + (uint)uVar3 * 2) = (short)iVar2;
    }
  }
  return;
}


/* __thiscall J3DAnmColor::searchUpdateMaterialID(J3DModelData *) */

void __thiscall J3DAnmColor::searchUpdateMaterialID(J3DAnmColor *this,J3DModelData *param_1)

{
  searchUpdateMaterialID(this,&param_1->mMaterialTable);
  return;
}


/* __thiscall J3DAnmColorFull::getColor(unsigned short,
                                        _GXColor *) const */

void __thiscall J3DAnmColorFull::getColor(J3DAnmColorFull *this,ushort param_1,_GXColor *param_2)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  double local_8;
  
  iVar2 = (uint)param_1 * 0x10;
  uVar3 = (uint)*(ushort *)(*(int *)(this + 0x40) + iVar2);
  if (*(float *)(this + 8) < J3DGraphAnimator::_1503) {
    param_2->r = *(u8 *)(*(int *)(this + 0x30) +
                        (uint)*(ushort *)(*(int *)(this + 0x40) + iVar2 + 2));
  }
  local_8 = (double)CONCAT44(0x43300000,uVar3);
  if ((float)(local_8 - J3DGraphAnimator::_1784) <= *(float *)(this + 8)) {
    param_2->r = *(u8 *)(*(int *)(this + 0x30) + uVar3 +
                         (uint)*(ushort *)(*(int *)(this + 0x40) + iVar2 + 2) + -1);
  }
  fVar1 = *(float *)(this + 8);
  if (J3DGraphAnimator::_1503 <= fVar1) {
    local_8 = (double)CONCAT44(0x43300000,uVar3);
    if (fVar1 < (float)(local_8 - J3DGraphAnimator::_1784)) {
      param_2->r = *(u8 *)(*(int *)(this + 0x30) +
                          (int)fVar1 + (uint)*(ushort *)(*(int *)(this + 0x40) + iVar2 + 2));
    }
  }
  uVar3 = (uint)*(ushort *)(*(int *)(this + 0x40) + iVar2 + 4);
  if (*(float *)(this + 8) < J3DGraphAnimator::_1503) {
    param_2->g = *(u8 *)(*(int *)(this + 0x34) +
                        (uint)*(ushort *)(*(int *)(this + 0x40) + iVar2 + 6));
  }
  local_8 = (double)CONCAT44(0x43300000,uVar3);
  if ((float)(local_8 - J3DGraphAnimator::_1784) <= *(float *)(this + 8)) {
    param_2->g = *(u8 *)(*(int *)(this + 0x34) + uVar3 +
                         (uint)*(ushort *)(*(int *)(this + 0x40) + iVar2 + 6) + -1);
  }
  fVar1 = *(float *)(this + 8);
  if (J3DGraphAnimator::_1503 <= fVar1) {
    local_8 = (double)CONCAT44(0x43300000,uVar3);
    if (fVar1 < (float)(local_8 - J3DGraphAnimator::_1784)) {
      param_2->g = *(u8 *)(*(int *)(this + 0x34) +
                          (int)fVar1 + (uint)*(ushort *)(*(int *)(this + 0x40) + iVar2 + 6));
    }
  }
  uVar3 = (uint)*(ushort *)(*(int *)(this + 0x40) + iVar2 + 8);
  if (*(float *)(this + 8) < J3DGraphAnimator::_1503) {
    param_2->b = *(u8 *)(*(int *)(this + 0x38) +
                        (uint)*(ushort *)(*(int *)(this + 0x40) + iVar2 + 10));
  }
  local_8 = (double)CONCAT44(0x43300000,uVar3);
  if ((float)(local_8 - J3DGraphAnimator::_1784) <= *(float *)(this + 8)) {
    param_2->b = *(u8 *)(*(int *)(this + 0x38) + uVar3 +
                         (uint)*(ushort *)(*(int *)(this + 0x40) + iVar2 + 10) + -1);
  }
  fVar1 = *(float *)(this + 8);
  if (J3DGraphAnimator::_1503 <= fVar1) {
    local_8 = (double)CONCAT44(0x43300000,uVar3);
    if (fVar1 < (float)(local_8 - J3DGraphAnimator::_1784)) {
      param_2->b = *(u8 *)(*(int *)(this + 0x38) +
                          (int)fVar1 + (uint)*(ushort *)(*(int *)(this + 0x40) + iVar2 + 10));
    }
  }
  uVar3 = (uint)*(ushort *)(*(int *)(this + 0x40) + iVar2 + 0xc);
  if (*(float *)(this + 8) < J3DGraphAnimator::_1503) {
    param_2->a = *(u8 *)(*(int *)(this + 0x3c) +
                        (uint)*(ushort *)(*(int *)(this + 0x40) + iVar2 + 0xe));
  }
  local_8 = (double)CONCAT44(0x43300000,uVar3);
  if ((float)(local_8 - J3DGraphAnimator::_1784) <= *(float *)(this + 8)) {
    param_2->a = *(u8 *)(*(int *)(this + 0x3c) + uVar3 +
                         (uint)*(ushort *)(*(int *)(this + 0x40) + iVar2 + 0xe) + -1);
  }
  fVar1 = *(float *)(this + 8);
  if (J3DGraphAnimator::_1503 <= fVar1) {
    local_8 = (double)CONCAT44(0x43300000,uVar3);
    if (fVar1 < (float)(local_8 - J3DGraphAnimator::_1784)) {
      param_2->a = *(u8 *)(*(int *)(this + 0x3c) +
                          (int)fVar1 + (uint)*(ushort *)(*(int *)(this + 0x40) + iVar2 + 0xe));
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x802f1da0) */
/* WARNING: Removing unreachable block (ram,0x802f1c20) */
/* WARNING: Removing unreachable block (ram,0x802f1cdc) */
/* WARNING: Removing unreachable block (ram,0x802f1e64) */
/* __thiscall J3DAnmColorKey::getColor(unsigned short,
                                       _GXColor *) const */

void __thiscall J3DAnmColorKey::getColor(J3DAnmColorKey *this,ushort param_1,_GXColor *param_2)

{
  short sVar1;
  J3DAnmKeyTableBase *animationTrack;
  int iVar2;
  int iVar3;
  double dVar4;
  
  iVar3 = (uint)param_1 * 0x18;
  animationTrack = (J3DAnmKeyTableBase *)(*(int *)(this + 0x40) + iVar3);
  if (animationTrack->mCount == 1) {
    param_2->r = (u8)*(undefined2 *)(*(int *)(this + 0x30) + (uint)animationTrack->mIndex * 2);
  }
  else {
    if (animationTrack->mCount == 0) {
      param_2->r = 0;
    }
    else {
      dVar4 = (double)J3DGraphAnimator::J3DGetKeyFrameInterpolation
                                ((double)*(float *)(this + 8),animationTrack,
                                 *(int *)(this + 0x30) +
                                 (uint)*(ushort *)(*(int *)(this + 0x40) + iVar3 + 2) * 2);
      if (dVar4 < (double)J3DGraphAnimator::_1503) {
        param_2->r = 0;
      }
      if ((double)J3DGraphAnimator::_2108 < dVar4) {
        param_2->r = 0xff;
      }
      if (((double)J3DGraphAnimator::_1503 <= dVar4) && (dVar4 <= (double)J3DGraphAnimator::_2108))
      {
        param_2->r = (u8)(int)dVar4;
      }
    }
  }
  iVar2 = *(int *)(this + 0x40);
  sVar1 = *(short *)(iVar2 + iVar3 + 6);
  if (sVar1 == 1) {
    param_2->g = (u8)*(undefined2 *)
                      (*(int *)(this + 0x34) + (uint)*(ushort *)(iVar2 + iVar3 + 8) * 2);
  }
  else {
    if (sVar1 == 0) {
      param_2->g = 0;
    }
    else {
      dVar4 = (double)J3DGraphAnimator::J3DGetKeyFrameInterpolation
                                ((double)*(float *)(this + 8),
                                 (J3DAnmKeyTableBase *)(iVar2 + iVar3 + 6),
                                 *(int *)(this + 0x34) + (uint)*(ushort *)(iVar2 + iVar3 + 8) * 2);
      if (dVar4 < (double)J3DGraphAnimator::_1503) {
        param_2->g = 0;
      }
      if ((double)J3DGraphAnimator::_2108 < dVar4) {
        param_2->g = 0xff;
      }
      if (((double)J3DGraphAnimator::_1503 <= dVar4) && (dVar4 <= (double)J3DGraphAnimator::_2108))
      {
        param_2->g = (u8)(int)dVar4;
      }
    }
  }
  iVar2 = *(int *)(this + 0x40);
  sVar1 = *(short *)(iVar2 + iVar3 + 0xc);
  if (sVar1 == 1) {
    param_2->b = (u8)*(undefined2 *)
                      (*(int *)(this + 0x38) + (uint)*(ushort *)(iVar2 + iVar3 + 0xe) * 2);
  }
  else {
    if (sVar1 == 0) {
      param_2->b = 0;
    }
    else {
      dVar4 = (double)J3DGraphAnimator::J3DGetKeyFrameInterpolation
                                ((double)*(float *)(this + 8),
                                 (J3DAnmKeyTableBase *)(iVar2 + iVar3 + 0xc),
                                 *(int *)(this + 0x38) + (uint)*(ushort *)(iVar2 + iVar3 + 0xe) * 2)
      ;
      if (dVar4 < (double)J3DGraphAnimator::_1503) {
        param_2->b = 0;
      }
      if ((double)J3DGraphAnimator::_2108 < dVar4) {
        param_2->b = 0xff;
      }
      if (((double)J3DGraphAnimator::_1503 <= dVar4) && (dVar4 <= (double)J3DGraphAnimator::_2108))
      {
        param_2->b = (u8)(int)dVar4;
      }
    }
  }
  iVar2 = *(int *)(this + 0x40);
  sVar1 = *(short *)(iVar2 + iVar3 + 0x12);
  if (sVar1 == 1) {
    param_2->a = (u8)*(undefined2 *)
                      (*(int *)(this + 0x3c) + (uint)*(ushort *)(iVar2 + iVar3 + 0x14) * 2);
  }
  else {
    if (sVar1 == 0) {
      param_2->a = 0;
    }
    else {
      dVar4 = (double)J3DGraphAnimator::J3DGetKeyFrameInterpolation
                                ((double)*(float *)(this + 8),
                                 (J3DAnmKeyTableBase *)(iVar2 + iVar3 + 0x12),
                                 *(int *)(this + 0x3c) + (uint)*(ushort *)(iVar2 + iVar3 + 0x14) * 2
                                );
      if (dVar4 < (double)J3DGraphAnimator::_1503) {
        param_2->a = 0;
      }
      if ((double)J3DGraphAnimator::_2108 < dVar4) {
        param_2->a = 0xff;
      }
      if (((double)J3DGraphAnimator::_1503 <= dVar4) && (dVar4 <= (double)J3DGraphAnimator::_2108))
      {
        param_2->a = (u8)(int)dVar4;
      }
    }
  }
  return;
}


/* __thiscall J3DAnmTexPattern::getTexNo(unsigned short,
                                         unsigned short *) const */

void __thiscall J3DAnmTexPattern::getTexNo(J3DAnmTexPattern *this,ushort param_1,ushort *param_2)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  double local_8;
  
  iVar2 = (uint)param_1 * 8;
  uVar3 = (uint)*(ushort *)(this->field_0x14 + iVar2);
  fVar1 = this->field_0x8;
  if (J3DGraphAnimator::_1503 <= fVar1) {
    local_8 = (double)CONCAT44(0x43300000,uVar3);
    if (fVar1 < (float)(local_8 - J3DGraphAnimator::_1784)) {
      *param_2 = *(ushort *)
                  (this->field_0x10 +
                  ((int)fVar1 + (uint)*(ushort *)(this->field_0x14 + iVar2 + 2)) * 2);
    }
  }
  if (this->field_0x8 < J3DGraphAnimator::_1503) {
    *param_2 = *(ushort *)(this->field_0x10 + (uint)*(ushort *)(this->field_0x14 + iVar2 + 2) * 2);
  }
  local_8 = (double)CONCAT44(0x43300000,uVar3);
  if ((float)(local_8 - J3DGraphAnimator::_1784) <= this->field_0x8) {
    *param_2 = *(ushort *)
                (this->field_0x10 + (uVar3 + *(ushort *)(this->field_0x14 + iVar2 + 2) + -1) * 2);
  }
  return;
}


/* __thiscall J3DAnmVisibilityFull::getVisibility(unsigned short,
                                                  unsigned char *) const */

void __thiscall
J3DAnmVisibilityFull::getVisibility(J3DAnmVisibilityFull *this,ushort param_1,uchar *param_2)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  double local_8;
  
  iVar2 = (uint)param_1 * 4;
  uVar3 = (uint)*(ushort *)(*(int *)(this + 0x14) + iVar2);
  fVar1 = *(float *)(this + 8);
  if (J3DGraphAnimator::_1503 <= fVar1) {
    local_8 = (double)CONCAT44(0x43300000,uVar3);
    if (fVar1 < (float)(local_8 - J3DGraphAnimator::_1784)) {
      *param_2 = *(uchar *)(*(int *)(this + 0x18) +
                           (int)fVar1 + (uint)*(ushort *)(*(int *)(this + 0x14) + iVar2 + 2));
    }
  }
  if (*(float *)(this + 8) < J3DGraphAnimator::_1503) {
    *param_2 = *(uchar *)(*(int *)(this + 0x18) +
                         (uint)*(ushort *)(*(int *)(this + 0x14) + iVar2 + 2));
  }
  local_8 = (double)CONCAT44(0x43300000,uVar3);
  if ((float)(local_8 - J3DGraphAnimator::_1784) <= *(float *)(this + 8)) {
    *param_2 = *(uchar *)(*(int *)(this + 0x18) + uVar3 +
                          (uint)*(ushort *)(*(int *)(this + 0x14) + iVar2 + 2) + -1);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall J3DAnmTexPattern::searchUpdateMaterialID(J3DMaterialTable *) */

void __thiscall
J3DAnmTexPattern::searchUpdateMaterialID(J3DAnmTexPattern *this,J3DMaterialTable *param_1)

{
  char *pcVar1;
  int iVar2;
  ushort uVar3;
  JUTNameTab *this_00;
  
  for (uVar3 = 0; uVar3 < *(ushort *)&this[1].field_0x2; uVar3 = uVar3 + 1) {
    this_00 = param_1->mpNameTab;
    pcVar1 = (char *)JUTNameTab::getName((JUTNameTab *)&this[1].field_0x8,uVar3);
    iVar2 = JUTNameTab::getIndex(this_00,pcVar1);
    if (iVar2 == -1) {
      *(undefined2 *)(*(int *)&this[1].field_0x4 + (uint)uVar3 * 2) = 0xffff;
    }
    else {
      *(short *)(*(int *)&this[1].field_0x4 + (uint)uVar3 * 2) = (short)iVar2;
    }
  }
  return;
}


/* __thiscall J3DAnmTexPattern::searchUpdateMaterialID(J3DModelData *) */

void __thiscall
J3DAnmTexPattern::searchUpdateMaterialID(J3DAnmTexPattern *this,J3DModelData *param_1)

{
  searchUpdateMaterialID(this,&param_1->mMaterialTable);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall J3DAnmTextureSRTKey::searchUpdateMaterialID(J3DMaterialTable *) */

void __thiscall
J3DAnmTextureSRTKey::searchUpdateMaterialID(J3DAnmTextureSRTKey *this,J3DMaterialTable *param_1)

{
  char *pcVar1;
  int iVar2;
  ushort uVar3;
  JUTNameTab *pJVar4;
  
  for (uVar3 = 0; (uint)uVar3 < (ushort)this->mTrackCount / 3; uVar3 = uVar3 + 1) {
    pJVar4 = param_1->mpNameTab;
    pcVar1 = (char *)JUTNameTab::getName((JUTNameTab *)&(this->mMaterialNameTable).mpStrData,uVar3);
    iVar2 = JUTNameTab::getIndex(pJVar4,pcVar1);
    if (iVar2 == -1) {
      ((this->mMaterialNameTable).mpRes)->mEntries[uVar3 - 2] = -1;
    }
    else {
      ((this->mMaterialNameTable).mpRes)->mEntries[uVar3 - 2] = (short)iVar2;
    }
  }
  for (uVar3 = 0; (uint)uVar3 < *(ushort *)&this->field_0x60 / 3; uVar3 = uVar3 + 1) {
    pJVar4 = param_1->mpNameTab;
    pcVar1 = (char *)JUTNameTab::getName((JUTNameTab *)&this->field_0x70,uVar3);
    iVar2 = JUTNameTab::getIndex(pJVar4,pcVar1);
    if (iVar2 == -1) {
      *(undefined2 *)(*(int *)&this->field_0x6c + (uint)uVar3 * 2) = 0xffff;
    }
    else {
      *(short *)(*(int *)&this->field_0x6c + (uint)uVar3 * 2) = (short)iVar2;
    }
  }
  return;
}


/* __thiscall J3DAnmTextureSRTKey::searchUpdateMaterialID(J3DModelData *) */

void __thiscall
J3DAnmTextureSRTKey::searchUpdateMaterialID(J3DAnmTextureSRTKey *this,J3DModelData *param_1)

{
  searchUpdateMaterialID(this,&param_1->mMaterialTable);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x802f24a4) */
/* WARNING: Removing unreachable block (ram,0x802f2324) */
/* WARNING: Removing unreachable block (ram,0x802f23e0) */
/* WARNING: Removing unreachable block (ram,0x802f2568) */
/* __thiscall J3DAnmTevRegKey::getTevColorReg(unsigned short,
                                              _GXColorS10 *) const */

void __thiscall
J3DAnmTevRegKey::getTevColorReg(J3DAnmTevRegKey *this,ushort param_1,_BAD__GXColorS10 *param_2)

{
  short sVar1;
  J3DAnmKeyTableBase *animationTrack;
  int iVar2;
  int iVar3;
  double dVar4;
  
  iVar3 = (uint)param_1 * 0x1c;
  animationTrack = (J3DAnmKeyTableBase *)(*(int *)(this + 0x4c) + iVar3);
  if (animationTrack->mCount == 1) {
    *(undefined2 *)param_2 =
         *(undefined2 *)(*(int *)(this + 0x54) + (uint)animationTrack->mIndex * 2);
  }
  else {
    if (animationTrack->mCount == 0) {
      *(undefined2 *)param_2 = 0;
    }
    else {
      dVar4 = (double)J3DGraphAnimator::J3DGetKeyFrameInterpolation
                                ((double)*(float *)(this + 8),animationTrack,
                                 *(int *)(this + 0x54) +
                                 (uint)*(ushort *)(*(int *)(this + 0x4c) + iVar3 + 2) * 2);
      if (dVar4 < (double)J3DGraphAnimator::_2369) {
        *(undefined2 *)param_2 = 0xfc00;
      }
      if ((double)J3DGraphAnimator::_2370 < dVar4) {
        *(undefined2 *)param_2 = 0x3ff;
      }
      if (((double)J3DGraphAnimator::_2369 <= dVar4) && (dVar4 <= (double)J3DGraphAnimator::_2370))
      {
        *(short *)param_2 = (short)(int)dVar4;
      }
    }
  }
  iVar2 = *(int *)(this + 0x4c);
  sVar1 = *(short *)(iVar2 + iVar3 + 6);
  if (sVar1 == 1) {
    *(undefined2 *)(param_2 + 2) =
         *(undefined2 *)(*(int *)(this + 0x58) + (uint)*(ushort *)(iVar2 + iVar3 + 8) * 2);
  }
  else {
    if (sVar1 == 0) {
      *(undefined2 *)(param_2 + 2) = 0;
    }
    else {
      dVar4 = (double)J3DGraphAnimator::J3DGetKeyFrameInterpolation
                                ((double)*(float *)(this + 8),
                                 (J3DAnmKeyTableBase *)(iVar2 + iVar3 + 6),
                                 *(int *)(this + 0x58) + (uint)*(ushort *)(iVar2 + iVar3 + 8) * 2);
      if (dVar4 < (double)J3DGraphAnimator::_2369) {
        *(undefined2 *)(param_2 + 2) = 0xfc00;
      }
      if ((double)J3DGraphAnimator::_2370 < dVar4) {
        *(undefined2 *)(param_2 + 2) = 0x3ff;
      }
      if (((double)J3DGraphAnimator::_2369 <= dVar4) && (dVar4 <= (double)J3DGraphAnimator::_2370))
      {
        *(short *)(param_2 + 2) = (short)(int)dVar4;
      }
    }
  }
  iVar2 = *(int *)(this + 0x4c);
  sVar1 = *(short *)(iVar2 + iVar3 + 0xc);
  if (sVar1 == 1) {
    *(undefined2 *)(param_2 + 4) =
         *(undefined2 *)(*(int *)(this + 0x5c) + (uint)*(ushort *)(iVar2 + iVar3 + 0xe) * 2);
  }
  else {
    if (sVar1 == 0) {
      *(undefined2 *)(param_2 + 4) = 0;
    }
    else {
      dVar4 = (double)J3DGraphAnimator::J3DGetKeyFrameInterpolation
                                ((double)*(float *)(this + 8),
                                 (J3DAnmKeyTableBase *)(iVar2 + iVar3 + 0xc),
                                 *(int *)(this + 0x5c) + (uint)*(ushort *)(iVar2 + iVar3 + 0xe) * 2)
      ;
      if (dVar4 < (double)J3DGraphAnimator::_2369) {
        *(undefined2 *)(param_2 + 4) = 0xfc00;
      }
      if ((double)J3DGraphAnimator::_2370 < dVar4) {
        *(undefined2 *)(param_2 + 4) = 0x3ff;
      }
      if (((double)J3DGraphAnimator::_2369 <= dVar4) && (dVar4 <= (double)J3DGraphAnimator::_2370))
      {
        *(short *)(param_2 + 4) = (short)(int)dVar4;
      }
    }
  }
  iVar2 = *(int *)(this + 0x4c);
  sVar1 = *(short *)(iVar2 + iVar3 + 0x12);
  if (sVar1 == 1) {
    *(undefined2 *)(param_2 + 6) =
         *(undefined2 *)(*(int *)(this + 0x60) + (uint)*(ushort *)(iVar2 + iVar3 + 0x14) * 2);
  }
  else {
    if (sVar1 == 0) {
      *(undefined2 *)(param_2 + 6) = 0;
    }
    else {
      dVar4 = (double)J3DGraphAnimator::J3DGetKeyFrameInterpolation
                                ((double)*(float *)(this + 8),
                                 (J3DAnmKeyTableBase *)(iVar2 + iVar3 + 0x12),
                                 *(int *)(this + 0x60) + (uint)*(ushort *)(iVar2 + iVar3 + 0x14) * 2
                                );
      if (dVar4 < (double)J3DGraphAnimator::_2369) {
        *(undefined2 *)(param_2 + 6) = 0xfc00;
      }
      if ((double)J3DGraphAnimator::_2370 < dVar4) {
        *(undefined2 *)(param_2 + 6) = 0x3ff;
      }
      if (((double)J3DGraphAnimator::_2369 <= dVar4) && (dVar4 <= (double)J3DGraphAnimator::_2370))
      {
        *(short *)(param_2 + 6) = (short)(int)dVar4;
      }
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x802f27e8) */
/* WARNING: Removing unreachable block (ram,0x802f2668) */
/* WARNING: Removing unreachable block (ram,0x802f2724) */
/* WARNING: Removing unreachable block (ram,0x802f28ac) */
/* __thiscall J3DAnmTevRegKey::getTevKonstReg(unsigned short,
                                              _GXColor *) const */

void __thiscall
J3DAnmTevRegKey::getTevKonstReg(J3DAnmTevRegKey *this,ushort param_1,_GXColor *param_2)

{
  short sVar1;
  J3DAnmKeyTableBase *animationTrack;
  int iVar2;
  int iVar3;
  double dVar4;
  
  iVar3 = (uint)param_1 * 0x1c;
  animationTrack = (J3DAnmKeyTableBase *)(*(int *)(this + 0x50) + iVar3);
  if (animationTrack->mCount == 1) {
    param_2->r = (u8)*(undefined2 *)(*(int *)(this + 100) + (uint)animationTrack->mIndex * 2);
  }
  else {
    if (animationTrack->mCount == 0) {
      param_2->r = 0;
    }
    else {
      dVar4 = (double)J3DGraphAnimator::J3DGetKeyFrameInterpolation
                                ((double)*(float *)(this + 8),animationTrack,
                                 *(int *)(this + 100) +
                                 (uint)*(ushort *)(*(int *)(this + 0x50) + iVar3 + 2) * 2);
      if (dVar4 < (double)J3DGraphAnimator::_1503) {
        param_2->r = 0;
      }
      if ((double)J3DGraphAnimator::_2108 < dVar4) {
        param_2->r = 0xff;
      }
      if (((double)J3DGraphAnimator::_1503 <= dVar4) && (dVar4 <= (double)J3DGraphAnimator::_2108))
      {
        param_2->r = (u8)(int)dVar4;
      }
    }
  }
  iVar2 = *(int *)(this + 0x50);
  sVar1 = *(short *)(iVar2 + iVar3 + 6);
  if (sVar1 == 1) {
    param_2->g = (u8)*(undefined2 *)
                      (*(int *)(this + 0x68) + (uint)*(ushort *)(iVar2 + iVar3 + 8) * 2);
  }
  else {
    if (sVar1 == 0) {
      param_2->g = 0;
    }
    else {
      dVar4 = (double)J3DGraphAnimator::J3DGetKeyFrameInterpolation
                                ((double)*(float *)(this + 8),
                                 (J3DAnmKeyTableBase *)(iVar2 + iVar3 + 6),
                                 *(int *)(this + 0x68) + (uint)*(ushort *)(iVar2 + iVar3 + 8) * 2);
      if (dVar4 < (double)J3DGraphAnimator::_1503) {
        param_2->g = 0;
      }
      if ((double)J3DGraphAnimator::_2108 < dVar4) {
        param_2->g = 0xff;
      }
      if (((double)J3DGraphAnimator::_1503 <= dVar4) && (dVar4 <= (double)J3DGraphAnimator::_2108))
      {
        param_2->g = (u8)(int)dVar4;
      }
    }
  }
  iVar2 = *(int *)(this + 0x50);
  sVar1 = *(short *)(iVar2 + iVar3 + 0xc);
  if (sVar1 == 1) {
    param_2->b = (u8)*(undefined2 *)
                      (*(int *)(this + 0x6c) + (uint)*(ushort *)(iVar2 + iVar3 + 0xe) * 2);
  }
  else {
    if (sVar1 == 0) {
      param_2->b = 0;
    }
    else {
      dVar4 = (double)J3DGraphAnimator::J3DGetKeyFrameInterpolation
                                ((double)*(float *)(this + 8),
                                 (J3DAnmKeyTableBase *)(iVar2 + iVar3 + 0xc),
                                 *(int *)(this + 0x6c) + (uint)*(ushort *)(iVar2 + iVar3 + 0xe) * 2)
      ;
      if (dVar4 < (double)J3DGraphAnimator::_1503) {
        param_2->b = 0;
      }
      if ((double)J3DGraphAnimator::_2108 < dVar4) {
        param_2->b = 0xff;
      }
      if (((double)J3DGraphAnimator::_1503 <= dVar4) && (dVar4 <= (double)J3DGraphAnimator::_2108))
      {
        param_2->b = (u8)(int)dVar4;
      }
    }
  }
  iVar2 = *(int *)(this + 0x50);
  sVar1 = *(short *)(iVar2 + iVar3 + 0x12);
  if (sVar1 == 1) {
    param_2->a = (u8)*(undefined2 *)
                      (*(int *)(this + 0x70) + (uint)*(ushort *)(iVar2 + iVar3 + 0x14) * 2);
  }
  else {
    if (sVar1 == 0) {
      param_2->a = 0;
    }
    else {
      dVar4 = (double)J3DGraphAnimator::J3DGetKeyFrameInterpolation
                                ((double)*(float *)(this + 8),
                                 (J3DAnmKeyTableBase *)(iVar2 + iVar3 + 0x12),
                                 *(int *)(this + 0x70) + (uint)*(ushort *)(iVar2 + iVar3 + 0x14) * 2
                                );
      if (dVar4 < (double)J3DGraphAnimator::_1503) {
        param_2->a = 0;
      }
      if ((double)J3DGraphAnimator::_2108 < dVar4) {
        param_2->a = 0xff;
      }
      if (((double)J3DGraphAnimator::_1503 <= dVar4) && (dVar4 <= (double)J3DGraphAnimator::_2108))
      {
        param_2->a = (u8)(int)dVar4;
      }
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall J3DAnmTevRegKey::searchUpdateMaterialID(J3DMaterialTable *) */

void __thiscall
J3DAnmTevRegKey::searchUpdateMaterialID(J3DAnmTevRegKey *this,J3DMaterialTable *param_1)

{
  char *pcVar1;
  int iVar2;
  ushort uVar3;
  JUTNameTab *pJVar4;
  
  for (uVar3 = 0; uVar3 < *(ushort *)(this + 0x10); uVar3 = uVar3 + 1) {
    pJVar4 = param_1->mpNameTab;
    pcVar1 = (char *)JUTNameTab::getName((JUTNameTab *)(this + 0x28),uVar3);
    iVar2 = JUTNameTab::getIndex(pJVar4,pcVar1);
    if (iVar2 == -1) {
      *(undefined2 *)(*(int *)(this + 0x24) + (uint)uVar3 * 2) = 0xffff;
    }
    else {
      *(short *)(*(int *)(this + 0x24) + (uint)uVar3 * 2) = (short)iVar2;
    }
  }
  for (uVar3 = 0; uVar3 < *(ushort *)(this + 0x12); uVar3 = uVar3 + 1) {
    pJVar4 = param_1->mpNameTab;
    pcVar1 = (char *)JUTNameTab::getName((JUTNameTab *)(this + 0x3c),uVar3);
    iVar2 = JUTNameTab::getIndex(pJVar4,pcVar1);
    if (iVar2 == -1) {
      *(undefined2 *)(*(int *)(this + 0x38) + (uint)uVar3 * 2) = 0xffff;
    }
    else {
      *(short *)(*(int *)(this + 0x38) + (uint)uVar3 * 2) = (short)iVar2;
    }
  }
  return;
}


/* __thiscall J3DAnmTevRegKey::searchUpdateMaterialID(J3DModelData *) */

void __thiscall J3DAnmTevRegKey::searchUpdateMaterialID(J3DAnmTevRegKey *this,J3DModelData *param_1)

{
  searchUpdateMaterialID(this,&param_1->mMaterialTable);
  return;
}


namespace J3DGraphAnimator {

/* __stdcall J3DGetKeyFrameInterpolation<short>(float,
                                                J3DAnmKeyTableBase *,
                                                short *) */

double J3DGetKeyFrameInterpolation
                 (double param_1,J3DAnmKeyTableBase *animationTrack,short *trackData)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  double dVar4;
  
  if (animationTrack->mTangentType == 0) {
    if ((double)(float)((double)CONCAT44(0x43300000,(int)*trackData ^ 0x80000000) - _1625) <=
        param_1) {
      iVar1 = animationTrack->mCount - 1;
      uVar3 = (uint)animationTrack->mCount;
      if (param_1 < (double)(float)((double)CONCAT44(0x43300000,
                                                     (int)trackData[iVar1 * 3] ^ 0x80000000) - _1625
                                   )) {
        while (uVar2 = uVar3, 1 < (int)uVar2) {
          uVar3 = ((int)uVar2 >> 1) + (uint)((int)uVar2 < 0 && (uVar2 & 1) != 0);
          if ((double)(float)((double)CONCAT44(0x43300000,(int)trackData[uVar3 * 3] ^ 0x80000000) -
                             _1625) <= param_1) {
            trackData = trackData + uVar3 * 3;
            uVar3 = uVar2 - uVar3;
          }
        }
        dVar4 = (double)JKernel::JMath::JMAHermiteInterpolation
                                  (param_1,(double)(float)((double)CONCAT44(0x43300000,
                                                                            (int)*trackData ^
                                                                            0x80000000) - _1625),
                                   (double)(float)((double)CONCAT44(0x43300000,
                                                                    (int)trackData[1] ^ 0x80000000)
                                                  - _1625),
                                   (double)(float)((double)CONCAT44(0x43300000,
                                                                    (int)trackData[2] ^ 0x80000000)
                                                  - _1625),
                                   (double)(float)((double)CONCAT44(0x43300000,
                                                                    (int)trackData[3] ^ 0x80000000)
                                                  - _1625),
                                   (double)(float)((double)CONCAT44(0x43300000,
                                                                    (int)trackData[4] ^ 0x80000000)
                                                  - _1625),
                                   (double)(float)((double)CONCAT44(0x43300000,
                                                                    (int)trackData[5] ^ 0x80000000)
                                                  - _1625));
      }
      else {
        dVar4 = (double)(float)((double)CONCAT44(0x43300000,
                                                 (int)trackData[iVar1 * 3 + 1] ^ 0x80000000) - _1625
                               );
      }
    }
    else {
      dVar4 = (double)(float)((double)CONCAT44(0x43300000,(int)trackData[1] ^ 0x80000000) - _1625);
    }
  }
  else {
    if ((double)(float)((double)CONCAT44(0x43300000,(int)*trackData ^ 0x80000000) - _1625) <=
        param_1) {
      iVar1 = animationTrack->mCount - 1;
      uVar3 = (uint)animationTrack->mCount;
      if (param_1 < (double)(float)((double)CONCAT44(0x43300000,
                                                     (int)trackData[iVar1 * 4] ^ 0x80000000) - _1625
                                   )) {
        while (uVar2 = uVar3, 1 < (int)uVar2) {
          uVar3 = ((int)uVar2 >> 1) + (uint)((int)uVar2 < 0 && (uVar2 & 1) != 0);
          if ((double)(float)((double)CONCAT44(0x43300000,(int)trackData[uVar3 * 4] ^ 0x80000000) -
                             _1625) <= param_1) {
            trackData = trackData + uVar3 * 4;
            uVar3 = uVar2 - uVar3;
          }
        }
        dVar4 = (double)JKernel::JMath::JMAHermiteInterpolation
                                  (param_1,(double)(float)((double)CONCAT44(0x43300000,
                                                                            (int)*trackData ^
                                                                            0x80000000) - _1625),
                                   (double)(float)((double)CONCAT44(0x43300000,
                                                                    (int)trackData[1] ^ 0x80000000)
                                                  - _1625),
                                   (double)(float)((double)CONCAT44(0x43300000,
                                                                    (int)trackData[3] ^ 0x80000000)
                                                  - _1625),
                                   (double)(float)((double)CONCAT44(0x43300000,
                                                                    (int)trackData[4] ^ 0x80000000)
                                                  - _1625),
                                   (double)(float)((double)CONCAT44(0x43300000,
                                                                    (int)trackData[5] ^ 0x80000000)
                                                  - _1625),
                                   (double)(float)((double)CONCAT44(0x43300000,
                                                                    (int)trackData[6] ^ 0x80000000)
                                                  - _1625));
      }
      else {
        dVar4 = (double)(float)((double)CONCAT44(0x43300000,
                                                 (int)trackData[iVar1 * 4 + 1] ^ 0x80000000) - _1625
                               );
      }
    }
    else {
      dVar4 = (double)(float)((double)CONCAT44(0x43300000,(int)trackData[1] ^ 0x80000000) - _1625);
    }
  }
  return dVar4;
}


/* __stdcall J3DGetKeyFrameInterpolation<float>(float,
                                                J3DAnmKeyTableBase *,
                                                float *) */

double J3DGetKeyFrameInterpolation(double param_1,ushort *param_2,float *param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  double dVar4;
  
  if (param_2[2] == 0) {
    if ((double)*param_3 <= param_1) {
      iVar1 = *param_2 - 1;
      uVar3 = (uint)*param_2;
      if (param_1 < (double)param_3[iVar1 * 3]) {
        while (uVar2 = uVar3, 1 < (int)uVar2) {
          uVar3 = ((int)uVar2 >> 1) + (uint)((int)uVar2 < 0 && (uVar2 & 1) != 0);
          if ((double)param_3[uVar3 * 3] <= param_1) {
            param_3 = param_3 + uVar3 * 3;
            uVar3 = uVar2 - uVar3;
          }
        }
        dVar4 = (double)JKernel::JMath::JMAHermiteInterpolation
                                  (param_1,(double)*param_3,(double)param_3[1],(double)param_3[2],
                                   (double)param_3[3],(double)param_3[4],(double)param_3[5]);
      }
      else {
        dVar4 = (double)param_3[iVar1 * 3 + 1];
      }
    }
    else {
      dVar4 = (double)param_3[1];
    }
  }
  else {
    if ((double)*param_3 <= param_1) {
      iVar1 = *param_2 - 1;
      uVar3 = (uint)*param_2;
      if (param_1 < (double)param_3[iVar1 * 4]) {
        while (uVar2 = uVar3, 1 < (int)uVar2) {
          uVar3 = ((int)uVar2 >> 1) + (uint)((int)uVar2 < 0 && (uVar2 & 1) != 0);
          if ((double)param_3[uVar3 * 4] <= param_1) {
            param_3 = param_3 + uVar3 * 4;
            uVar3 = uVar2 - uVar3;
          }
        }
        dVar4 = (double)JKernel::JMath::JMAHermiteInterpolation
                                  (param_1,(double)*param_3,(double)param_3[1],(double)param_3[3],
                                   (double)param_3[4],(double)param_3[5],(double)param_3[6]);
      }
      else {
        dVar4 = (double)param_3[iVar1 * 4 + 1];
      }
    }
    else {
      dVar4 = (double)param_3[1];
    }
  }
  return dVar4;
}

}

/* __thiscall J3DAnmColorKey::~J3DAnmColorKey(void) */

void __thiscall J3DAnmColorKey::_J3DAnmColorKey(J3DAnmColorKey *this)

{
  short in_r4;
  
  if (this != (J3DAnmColorKey *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (J3DAnmColorKey *)0x0) {
      *(undefined1 **)this = &J3DAnmColor::__vt;
      if (this != (J3DAnmColorKey *)0xffffffe0) {
        *(undefined1 **)(this + 0x20) = &JUTNameTab::__vt;
      }
      if (this != (J3DAnmColorKey *)0x0) {
        *(undefined ***)this = &J3DAnmBase::__vt;
      }
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DAnmColor::~J3DAnmColor(void) */

void __thiscall J3DAnmColor::_J3DAnmColor(J3DAnmColor *this)

{
  short in_r4;
  
  if (this != (J3DAnmColor *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (J3DAnmColor *)0xffffffe0) {
      *(undefined1 **)(this + 0x20) = &JUTNameTab::__vt;
    }
    if (this != (J3DAnmColor *)0x0) {
      *(undefined ***)this = &J3DAnmBase::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DAnmColor::getColor(unsigned short,
                                    _GXColor *) const */

void __thiscall J3DAnmColor::getColor(J3DAnmColor *this,ushort param_1,_GXColor *param_2)

{
  return;
}


/* __thiscall J3DAnmColorFull::~J3DAnmColorFull(void) */

void __thiscall J3DAnmColorFull::_J3DAnmColorFull(J3DAnmColorFull *this)

{
  short in_r4;
  
  if (this != (J3DAnmColorFull *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (J3DAnmColorFull *)0x0) {
      *(undefined1 **)this = &J3DAnmColor::__vt;
      if (this != (J3DAnmColorFull *)0xffffffe0) {
        *(undefined1 **)(this + 0x20) = &JUTNameTab::__vt;
      }
      if (this != (J3DAnmColorFull *)0x0) {
        *(undefined ***)this = &J3DAnmBase::__vt;
      }
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DAnmVtxColorKey::~J3DAnmVtxColorKey(void) */

void __thiscall J3DAnmVtxColorKey::_J3DAnmVtxColorKey(J3DAnmVtxColorKey *this)

{
  bool bVar1;
  short in_r4;
  
  bVar1 = this != (J3DAnmVtxColorKey *)0x0;
  if (bVar1) {
    *(undefined1 **)this = &__vt;
    if ((bVar1) && (*(undefined1 **)this = &J3DAnmVtxColor::__vt, bVar1)) {
      *(undefined ***)this = &J3DAnmBase::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DAnmVtxColor::~J3DAnmVtxColor(void) */

void __thiscall J3DAnmVtxColor::_J3DAnmVtxColor(J3DAnmVtxColor *this)

{
  short in_r4;
  
  if (this != (J3DAnmVtxColor *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (J3DAnmVtxColor *)0x0) {
      *(undefined ***)this = &J3DAnmBase::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DAnmVtxColor::getColor(unsigned char,
                                       unsigned short,
                                       _GXColor *) const */

void __thiscall
J3DAnmVtxColor::getColor(J3DAnmVtxColor *this,uchar param_1,ushort param_2,_GXColor *param_3)

{
  return;
}


/* __thiscall J3DAnmVtxColorFull::~J3DAnmVtxColorFull(void) */

void __thiscall J3DAnmVtxColorFull::_J3DAnmVtxColorFull(J3DAnmVtxColorFull *this)

{
  bool bVar1;
  short in_r4;
  
  bVar1 = this != (J3DAnmVtxColorFull *)0x0;
  if (bVar1) {
    *(undefined1 **)this = &__vt;
    if ((bVar1) && (*(undefined1 **)this = &J3DAnmVtxColor::__vt, bVar1)) {
      *(undefined ***)this = &J3DAnmBase::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DAnmClusterKey::~J3DAnmClusterKey(void) */

void __thiscall J3DAnmClusterKey::_J3DAnmClusterKey(J3DAnmClusterKey *this)

{
  bool bVar1;
  short in_r4;
  
  bVar1 = this != (J3DAnmClusterKey *)0x0;
  if (bVar1) {
    *(undefined1 **)this = &__vt;
    if ((bVar1) && (*(undefined1 **)this = &J3DAnmCluster::__vt, bVar1)) {
      *(undefined ***)this = &J3DAnmBase::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DAnmCluster::~J3DAnmCluster(void) */

void __thiscall J3DAnmCluster::_J3DAnmCluster(J3DAnmCluster *this)

{
  short in_r4;
  
  if (this != (J3DAnmCluster *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (J3DAnmCluster *)0x0) {
      *(undefined ***)this = &J3DAnmBase::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DAnmCluster::getWeight(unsigned short) const */

double __thiscall J3DAnmCluster::getWeight(J3DAnmCluster *this,ushort param_1)

{
  return (double)J3DGraphAnimator::_1502;
}


/* __thiscall J3DAnmClusterFull::~J3DAnmClusterFull(void) */

void __thiscall J3DAnmClusterFull::_J3DAnmClusterFull(J3DAnmClusterFull *this)

{
  bool bVar1;
  short in_r4;
  
  bVar1 = this != (J3DAnmClusterFull *)0x0;
  if (bVar1) {
    *(undefined1 **)this = &__vt;
    if ((bVar1) && (*(undefined1 **)this = &J3DAnmCluster::__vt, bVar1)) {
      *(undefined ***)this = &J3DAnmBase::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DAnmTransformFull::~J3DAnmTransformFull(void) */

void __thiscall J3DAnmTransformFull::_J3DAnmTransformFull(J3DAnmTransformFull *this)

{
  bool bVar1;
  short in_r4;
  
  bVar1 = this != (J3DAnmTransformFull *)0x0;
  if (bVar1) {
    *(undefined ***)this = &__vt;
    if ((bVar1) && (*(undefined ***)this = &J3DAnmTransform::__vt, bVar1)) {
      *(undefined ***)this = &J3DAnmBase::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}

