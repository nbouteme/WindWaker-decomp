#include <d_npc.h>
#include <SComponent/c_lib.h>
#include <MSL_C.PPCEABI.bare.H/arith.h>
#include <d_npc.h>
#include <SComponent/c_math.h>
#include <d_path.h>
#include <SComponent/c_xyz.h>
#include <mtx/vec.h>
#include <d_resorce.h>
#include <m_Do_ext.h>
#include <mtx/mtx.h>
#include <d_a_item.h>
#include <d_save.h>
#include <SComponent/c_m3d_g_cyl.h>
#include <SComponent/c_cc_s.h>
#include <f_op_msg_mng.h>
#include <Runtime.PPCEABI.H/ptmf.h>
#include <d_event_manager.h>
#include <d_a_nh.h>
#include <f_op_actor_iter.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <f_op_actor_mng.h>
#include <d_stage.h>
#include <dNpc_JntCtrl_c.h>
#include <fopNpc_npc_c.h>
#include <Demangler/dNpc_PathRun_c.h>
#include <dNpc_HeadAnm_c.h>
#include <dNpc_EventCut_c.h>


namespace d_npc {
undefined1 init$4569;
}

/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dNpc_JntCtrl_c::angCalcS(short *,
                                       short,
                                       short,
                                       short) */

uint __thiscall
dNpc_JntCtrl_c::angCalcS
          (dNpc_JntCtrl_c *this,short *outYRot,short desiredYRot,short speed,short maxVel)

{
  uint uVar1;
  int iVar2;
  short local_18 [4];
  short origYRot;
  
  origYRot = *outYRot;
  local_18[0] = origYRot - desiredYRot;
  SComponent::cLib_addCalcAngleS(local_18,0,speed,maxVel,0x60);
  iVar2 = MSL_C.PPCEABI.bare.H::abs((int)local_18[0]);
  if (speed < iVar2) {
    *outYRot = *outYRot + (local_18[0] - (origYRot - desiredYRot));
  }
  else {
    *outYRot = desiredYRot;
  }
  uVar1 = countLeadingZeros((int)desiredYRot - (int)*outYRot);
  return uVar1 >> 5;
}


/* __thiscall dNpc_JntCtrl_c::limitter(short *,
                                       short,
                                       short) */

void __thiscall
dNpc_JntCtrl_c::limitter(dNpc_JntCtrl_c *this,short *desiredDiff,short maxDiff,short minDiff)

{
  if (maxDiff < *desiredDiff) {
    *desiredDiff = maxDiff;
  }
  if (minDiff <= *desiredDiff) {
    return;
  }
  *desiredDiff = minDiff;
  return;
}


/* WARNING: Inlined function: FUN_80328f1c */
/* WARNING: Inlined function: FUN_80328f68 */
/* __thiscall dNpc_JntCtrl_c::follow(short *,
                                     short,
                                     short,
                                     int) */

bool __thiscall
dNpc_JntCtrl_c::follow
          (dNpc_JntCtrl_c *this,short *outYRot,short desiredYRot,short maxVel,int param_4)

{
  short sVar1;
  short sVar2;
  short *psVar3;
  int iVar4;
  int iVar5;
  short sVar6;
  short sVar7;
  
  sVar1 = *outYRot;
  angCalcS(this,outYRot,desiredYRot,4,maxVel);
  sVar1 = *outYRot - sVar1;
  sVar7 = 0;
  sVar6 = 0;
  sVar2 = desiredYRot - *outYRot;
  iVar5 = 1;
  iVar4 = 4;
  do {
    psVar3 = (short *)((int)&this->mHeadUpDownRot + iVar4 + param_4 * 2);
    sVar6 = sVar6 + *psVar3;
    if (((0 < sVar1) && (sVar2 < sVar6)) || ((sVar1 < 0 && (sVar6 < sVar2)))) {
      *psVar3 = sVar2 - sVar7;
      limitter(this,(short *)((int)&this->mHeadUpDownRot + iVar4 + param_4 * 2),psVar3[0xb],
               psVar3[7]);
    }
    sVar7 = sVar7 + *psVar3;
    iVar5 = iVar5 + -1;
    iVar4 = iVar4 + -4;
  } while (-1 < iVar5);
  return *outYRot != desiredYRot;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall dNpc_JntCtrl_c::move(short,
                                   int) */

bool __thiscall dNpc_JntCtrl_c::move(dNpc_JntCtrl_c *this,short rotDiff,int param_2)

{
  uint uVar1;
  short sVar2;
  int iVar3;
  short *psVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  short local_38 [2];
  short local_34 [2];
  int local_30 [4];
  
  iVar3 = 0;
  iVar5 = 0;
  iVar6 = 0;
  do {
    if (((iVar3 == 0) && (this->field_0xb == 1)) ||
       ((local_38[0] = rotDiff, iVar3 == 1 && (this->field_0xc == 1)))) {
      local_38[0] = 0;
    }
    psVar4 = (short *)((int)(&this->mHeadUpDownRot + param_2) + iVar6);
    limitter(this,local_38,psVar4[0xb],psVar4[7]);
    rotDiff = rotDiff - local_38[0];
    *(short *)((int)local_34 + iVar5) = local_38[0];
    local_30[0] = (int)*psVar4;
    SComponent::cLib_addCalcAngleL(local_30,(int)local_38[0],4,(int)psVar4[0xf],1);
    *psVar4 = (short)local_30[0];
    iVar3 = iVar3 + 1;
    iVar5 = iVar5 + 2;
    iVar6 = iVar6 + 4;
  } while (iVar3 < 2);
  iVar5 = 0;
  iVar7 = 0;
  iVar6 = 0;
  iVar3 = 0;
  do {
    psVar4 = (short *)((int)(&this->mHeadUpDownRot + param_2) + iVar6);
    sVar2 = SComponent::cLib_distanceAngleS(*(short *)((int)local_34 + iVar7),*psVar4);
    uVar1 = SEXT24(psVar4[0xf]);
    if ((int)sVar2 <= (int)(((int)uVar1 >> 1) + (uint)((int)uVar1 < 0 && (uVar1 & 1) != 0))) {
      iVar3 = iVar3 + 1;
    }
    iVar5 = iVar5 + 1;
    iVar7 = iVar7 + 2;
    iVar6 = iVar6 + 4;
  } while (iVar5 < 2);
  uVar1 = countLeadingZeros(iVar5 - iVar3);
  return (bool)(char)(uVar1 >> 5);
}


/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* WARNING: Removing unreachable block (ram,0x8021ac4c) */
/* __thiscall dNpc_JntCtrl_c::lookAtTarget(short *,
                                           cXyz *,
                                           cXyz,
                                           short,
                                           short,
                                           bool) */

undefined __thiscall
dNpc_JntCtrl_c::lookAtTarget
          (dNpc_JntCtrl_c *this,short *outYRot,cXyz *dstPos,cXyz *srcPos,short desiredYRot,
          short maxFollowRotVel,bool headOnlyFollow)

{
  short yRotDiff;
  int iVar1;
  short xRotDiff;
  bool bVar2;
  undefined4 uVar3;
  double dVar4;
  undefined8 in_f31;
  double xzDist;
  undefined auStack8 [8];
  float dstY;
  short maxHeadRot;
  short maxSpineRot;
  short minHeadRot;
  short minSpineRot;
  float srcY;
  float xDiff;
  float zDiff;
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (dstPos == (cXyz *)0x0) {
    xRotDiff = 0;
  }
  else {
    xDiff = dstPos->x - srcPos->x;
    dstY = dstPos->y;
    srcY = srcPos->y;
    zDiff = dstPos->z - srcPos->z;
    xzDist = (double)(xDiff * xDiff + zDiff * zDiff);
    if ((double)d_npc::0_0 < xzDist) {
      dVar4 = 1.0 / SQRT(xzDist);
      dVar4 = d_npc::_4096 * dVar4 * (d_npc::_4097 - xzDist * dVar4 * dVar4);
      dVar4 = d_npc::_4096 * dVar4 * (d_npc::_4097 - xzDist * dVar4 * dVar4);
      xzDist = (double)(float)(xzDist * d_npc::_4096 * dVar4 *
                                        (d_npc::_4097 - xzDist * dVar4 * dVar4));
    }
    iVar1 = SComponent::cM_atan2s(xDiff,zDiff);
    desiredYRot = (short)iVar1;
    iVar1 = SComponent::cM_atan2s(dstY - srcY,(float)xzDist);
    xRotDiff = (short)iVar1;
  }
  yRotDiff = desiredYRot - *outYRot;
  maxSpineRot = this->mMaxSpineRot;
  maxHeadRot = this->mMaxHeadRot;
  minSpineRot = this->mMinSpineRot;
  minHeadRot = this->mMinHeadRot;
  bVar2 = move(this,yRotDiff,1);
  if (((this->field_0xa != false) ||
      ((((int)maxSpineRot + (int)maxHeadRot <= (int)yRotDiff ||
        ((int)yRotDiff <= (int)minSpineRot + (int)minHeadRot)) && (bVar2 != false)))) &&
     (headOnlyFollow == false)) {
    bVar2 = (bool)follow(this,outYRot,desiredYRot,maxFollowRotVel,1);
    this->field_0xa = bVar2;
  }
  bVar2 = move(this,xRotDiff,0);
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return bVar2;
}


/* __thiscall dNpc_JntCtrl_c::setParam(short,
                                       short,
                                       short,
                                       short,
                                       short,
                                       short,
                                       short,
                                       short,
                                       short) */

void __thiscall
dNpc_JntCtrl_c::setParam
          (dNpc_JntCtrl_c *this,short param_1,short maxSpineRot,short param_3,short minSpineRot,
          short param_5,short maxHeadRot,short param_7,short minHeadRot,short param_9)

{
  this->field_0x1a = param_1;
  this->mMaxSpineRot = maxSpineRot;
  this->field_0x12 = param_3;
  this->mMinSpineRot = minSpineRot;
  this->field_0x16 = param_5;
  this->mMaxHeadRot = maxHeadRot;
  this->field_0xe = param_7;
  this->mMinHeadRot = minHeadRot;
  this->field_0x22 = param_9;
  this->field_0x24 = param_9;
  this->field_0x1e = param_9;
  this->field_0x20 = param_9;
  return;
}


/* __thiscall dNpc_PathRun_c::setInfDrct(dPath *) */

undefined4 __thiscall dNpc_PathRun_c::setInfDrct(dNpc_PathRun_c *this,dPath *pPath)

{
  this->mPath = pPath;
  this->mCurrPointIndex = 0;
  return 1;
}


/* __thiscall dNpc_PathRun_c::setInf(unsigned char,
                                     signed char,
                                     unsigned char) */

uint __thiscall
dNpc_PathRun_c::setInf(dNpc_PathRun_c *this,byte pathIndex,byte roomNo,bool bGoingForwards)

{
  uint pathIndex_00;
  dPath *pdVar1;
  
  this->mPath = (dPath *)0x0;
  this->mbGoingForwards = bGoingForwards;
  pathIndex_00 = (uint)pathIndex;
  if (pathIndex_00 != 0xff) {
    pdVar1 = d_path::dPath_GetRoomPath(pathIndex_00,(int)(char)roomNo);
    this->mPath = pdVar1;
    this->mCurrPointIndex = 0;
  }
  return (uint)(pathIndex_00 != 0xff);
}


/* __thiscall dNpc_PathRun_c::nextPath(signed char) */

dPath * __thiscall dNpc_PathRun_c::nextPath(dNpc_PathRun_c *this,char roomNo)

{
  dPath *pdVar1;
  
  pdVar1 = (dPath *)0x0;
  if (this->mPath != (dPath *)0x0) {
    pdVar1 = d_path::dPath_GetNextRoomPath(this->mPath,(int)roomNo);
  }
  return pdVar1;
}


namespace dNpc_PathRun_c {

/* __thiscall getPoint(unsigned char) */

void getPoint(cXyz *pDstPos,dNpc_PathRun_c *this,uchar pointIndex)

{
  cXyz *pcVar1;
  dPath *path;
  cXyz local_18;
  
  local_18.x = d_npc::0_0;
  local_18.y = d_npc::0_0;
  local_18.z = d_npc::0_0;
  path = this->mPath;
  if ((path != (dPath *)0x0) && ((ushort)pointIndex < path->mNum)) {
    pcVar1 = &path->mpPnt[pointIndex].mPos;
    local_18.x = pcVar1->x;
    local_18.y = pcVar1->y;
    local_18.z = pcVar1->z;
  }
  pDstPos->x = local_18.x;
  pDstPos->y = local_18.y;
  pDstPos->z = local_18.z;
  return;
}

}

/* WARNING: Removing unreachable block (ram,0x8021af80) */
/* WARNING: Removing unreachable block (ram,0x8021af78) */
/* WARNING: Removing unreachable block (ram,0x8021af88) */
/* __thiscall dNpc_PathRun_c::chkPointPass(cXyz,
                                           bool) */

bool __thiscall dNpc_PathRun_c::chkPointPass(dNpc_PathRun_c *this,cXyz *currPos,bool goingForwards)

{
  float fVar1;
  float fVar2;
  float fVar3;
  dPath__Point *currPoint;
  uint uVar4;
  dPath__Point *firstPoint;
  dPath *path;
  bool bVar5;
  undefined4 uVar6;
  undefined8 in_f29;
  double dVar7;
  undefined8 in_f30;
  double zDiff;
  undefined8 in_f31;
  double xDiff;
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
  bVar5 = false;
  path = this->mPath;
  if (path != (dPath *)0x0) {
    firstPoint = path->mpPnt;
    uVar4 = (uint)this->mCurrPointIndex;
    currPoint = firstPoint + uVar4;
    fVar1 = (currPoint->mPos).x;
    fVar2 = (currPoint->mPos).z;
    if (uVar4 == 0) {
      xDiff = (double)(firstPoint[1].mPos.x - (firstPoint->mPos).x);
      zDiff = (double)(firstPoint[1].mPos.z - (firstPoint->mPos).z);
    }
    else {
      if (uVar4 == path->mNum - 1) {
        firstPoint = firstPoint + path->mNum;
        xDiff = (double)(firstPoint[-1].mPos.x - firstPoint[-2].mPos.x);
        zDiff = (double)(firstPoint[-1].mPos.z - firstPoint[-2].mPos.z);
      }
      else {
        xDiff = (double)(currPoint[1].mPos.x - currPoint[-1].mPos.x);
        zDiff = (double)(currPoint[1].mPos.z - currPoint[-1].mPos.z);
      }
    }
    uVar4 = SComponent::cM_atan2s((float)xDiff,(float)zDiff);
    dVar7 = (double)(d_npc::_4177 *
                    JKernel::JMath::jmaSinTable
                    [(int)(uVar4 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f)]);
    uVar4 = SComponent::cM_atan2s((float)xDiff,(float)zDiff);
    fVar3 = d_npc::_4177 *
            JKernel::JMath::jmaCosTable
            [(int)(uVar4 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f)];
    fVar1 = -((float)(dVar7 * (double)fVar1) + fVar3 * fVar2);
    if (goingForwards == false) {
      bVar5 = fVar1 + (float)(dVar7 * (double)currPos->x) + fVar3 * currPos->z <= d_npc::0_0;
    }
    else {
      bVar5 = d_npc::0_0 < fVar1 + (float)(dVar7 * (double)currPos->x) + fVar3 * currPos->z;
    }
  }
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  __psq_l0(auStack24,uVar6);
  __psq_l1(auStack24,uVar6);
  __psq_l0(auStack40,uVar6);
  __psq_l1(auStack40,uVar6);
  return bVar5;
}


/* __thiscall dNpc_PathRun_c::incIdx(void) */

bool __thiscall dNpc_PathRun_c::incIdx(dNpc_PathRun_c *this)

{
  ushort uVar1;
  bool didNotHitEnd;
  
  didNotHitEnd = true;
  if (this->mPath != (dPath *)0x0) {
    this->mCurrPointIndex = this->mCurrPointIndex + 1;
    uVar1 = this->mPath->mNum;
    if (uVar1 <= this->mCurrPointIndex) {
      this->mCurrPointIndex = (char)uVar1 - 1;
      didNotHitEnd = false;
    }
  }
  return didNotHitEnd;
}


/* __thiscall dNpc_PathRun_c::incIdxLoop(void) */

bool __thiscall dNpc_PathRun_c::incIdxLoop(dNpc_PathRun_c *this)

{
  bool didNotHitEnd;
  
  didNotHitEnd = true;
  if ((this->mPath != (dPath *)0x0) &&
     (this->mCurrPointIndex = this->mCurrPointIndex + 1,
     this->mPath->mNum <= (ushort)this->mCurrPointIndex)) {
    this->mCurrPointIndex = 0;
    didNotHitEnd = false;
  }
  return didNotHitEnd;
}


/* __thiscall dNpc_PathRun_c::incIdxAuto(void) */

bool __thiscall dNpc_PathRun_c::incIdxAuto(dNpc_PathRun_c *this)

{
  ushort uVar1;
  bool local_r6_116;
  
  local_r6_116 = true;
  if (this->mPath != (dPath *)0x0) {
    if ((this->mPath->mLoops & 1) == 0) {
      this->mCurrPointIndex = this->mCurrPointIndex + 1;
      uVar1 = this->mPath->mNum;
      if (uVar1 <= this->mCurrPointIndex) {
        this->mCurrPointIndex = (char)uVar1 - 1;
        local_r6_116 = false;
      }
    }
    else {
      this->mCurrPointIndex = this->mCurrPointIndex + 1;
      if (this->mPath->mNum <= (ushort)this->mCurrPointIndex) {
        this->mCurrPointIndex = 0;
      }
    }
  }
  return local_r6_116;
}


/* __thiscall dNpc_PathRun_c::decIdx(void) */

bool __thiscall dNpc_PathRun_c::decIdx(dNpc_PathRun_c *this)

{
  bool didNotHitEnd;
  
  didNotHitEnd = true;
  if ((this->mPath != (dPath *)0x0) &&
     (this->mCurrPointIndex = this->mCurrPointIndex - 1,
     this->mPath->mNum <= (ushort)this->mCurrPointIndex)) {
    this->mCurrPointIndex = 0;
    didNotHitEnd = false;
  }
  return didNotHitEnd;
}


/* __thiscall dNpc_PathRun_c::decIdxLoop(void) */

undefined4 __thiscall dNpc_PathRun_c::decIdxLoop(dNpc_PathRun_c *this)

{
  ushort uVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  if (this->mPath != (dPath *)0x0) {
    this->mCurrPointIndex = this->mCurrPointIndex - 1;
    uVar1 = this->mPath->mNum;
    if (uVar1 <= this->mCurrPointIndex) {
      this->mCurrPointIndex = (char)uVar1 - 1;
      uVar2 = 0;
    }
  }
  return uVar2;
}


/* __thiscall dNpc_PathRun_c::decIdxAuto(void) */

undefined4 __thiscall dNpc_PathRun_c::decIdxAuto(dNpc_PathRun_c *this)

{
  ushort uVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  if (this->mPath != (dPath *)0x0) {
    if ((this->mPath->mLoops & 1) == 0) {
      this->mCurrPointIndex = this->mCurrPointIndex - 1;
      if (this->mPath->mNum <= (ushort)this->mCurrPointIndex) {
        this->mCurrPointIndex = 0;
        uVar2 = 0;
      }
    }
    else {
      this->mCurrPointIndex = this->mCurrPointIndex - 1;
      uVar1 = this->mPath->mNum;
      if (uVar1 <= this->mCurrPointIndex) {
        this->mCurrPointIndex = (char)uVar1 - 1;
      }
    }
  }
  return uVar2;
}


/* __thiscall dNpc_PathRun_c::nextIdx(void) */

bool __thiscall dNpc_PathRun_c::nextIdx(dNpc_PathRun_c *this)

{
  bool didNotHitEnd;
  
  if (this->mbGoingForwards == false) {
    didNotHitEnd = decIdx(this);
    if (didNotHitEnd == false) {
      incIdx(this);
    }
  }
  else {
    didNotHitEnd = incIdx(this);
    if (didNotHitEnd == false) {
      decIdx(this);
    }
  }
  return didNotHitEnd;
}


/* __thiscall dNpc_PathRun_c::nextIdxAuto(void) */

uint __thiscall dNpc_PathRun_c::nextIdxAuto(dNpc_PathRun_c *this)

{
  bool bVar2;
  uint uVar1;
  
  if (this->mbGoingForwards == false) {
    uVar1 = decIdxAuto(this);
    if ((uVar1 & 0xff) == 0) {
      incIdx(this);
    }
  }
  else {
    bVar2 = incIdxAuto(this);
    uVar1 = (uint)bVar2;
    if (bVar2 == false) {
      decIdx(this);
    }
  }
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dNpc_PathRun_c::absIdx(unsigned char,
                                     unsigned char) */

int __thiscall dNpc_PathRun_c::absIdx(dNpc_PathRun_c *this,uchar param_1,uchar param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  if (this->mPath == (dPath *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = (uint)param_1 - (uint)param_2;
    iVar2 = (uint)param_2 - (uint)param_1;
    if (iVar3 < 0) {
      uVar1 = maxPoint(this);
      iVar3 = iVar3 + (uVar1 & 0xff);
    }
    if (iVar2 < 0) {
      uVar1 = maxPoint(this);
      iVar2 = iVar2 + (uVar1 & 0xff);
    }
    if (iVar2 < iVar3) {
      iVar3 = iVar2;
    }
  }
  return iVar3;
}


/* __thiscall dNpc_PathRun_c::maxPoint(void) */

ushort __thiscall dNpc_PathRun_c::maxPoint(dNpc_PathRun_c *this)

{
  ushort uVar1;
  
  uVar1 = 0xff;
  if (this->mPath != (dPath *)0x0) {
    uVar1 = this->mPath->mNum & 0xff;
  }
  return uVar1;
}


/* __thiscall dNpc_PathRun_c::pointArg(unsigned char) */

byte __thiscall dNpc_PathRun_c::pointArg(dNpc_PathRun_c *this,uchar idx)

{
  dPath *pdVar1;
  byte bVar2;
  
  bVar2 = 0;
  pdVar1 = this->mPath;
  if ((pdVar1 != (dPath *)0x0) && ((ushort)idx < (pdVar1->mNum & 0xff))) {
    bVar2 = pdVar1->mpPnt[idx].mArg3;
  }
  return bVar2;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x8021b4ec) */
/* WARNING: Removing unreachable block (ram,0x8021b4e4) */
/* WARNING: Removing unreachable block (ram,0x8021b4f4) */
/* __thiscall dNpc_PathRun_c::setNearPathIndx(cXyz *,
                                              float) */

undefined4 __thiscall
dNpc_PathRun_c::setNearPathIndx(dNpc_PathRun_c *this,cXyz *param_1,float param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  undefined8 in_f29;
  undefined8 in_f30;
  double dVar9;
  undefined8 in_f31;
  double dVar10;
  float fVar11;
  cXyz local_84;
  cXyz local_78;
  cXyz local_6c;
  float local_60;
  float local_5c;
  float local_58;
  cXyz local_54;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar7 = (double)param_2;
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  uVar1 = 0;
  if (this->mPath != (dPath *)0x0) {
    dVar9 = (double)d_npc::_4365;
    uVar4 = 0;
    dVar10 = (double)d_npc::0_0;
    for (uVar3 = 0; uVar2 = maxPoint(this), (int)uVar3 < (int)(uVar2 & 0xff); uVar3 = uVar3 + 1) {
      getPoint(&local_6c,this,(uchar)uVar3);
      local_54.x = local_6c.x;
      local_54.y = local_6c.y;
      local_54.z = local_6c.z;
      ::cXyz::operator__(&local_78,param_1,&local_54);
      local_60 = local_78.x;
      local_5c = local_78.y;
      local_58 = local_78.z;
      local_84.x = local_78.x;
      local_84.y = (float)dVar10;
      local_84.z = local_78.z;
      fVar11 = mtx::PSVECSquareMag(&local_84);
      dVar8 = (double)((float)(dVar7 * (double)(local_5c * local_5c)) + fVar11);
      if (dVar10 < dVar8) {
        dVar6 = 1.0 / SQRT(dVar8);
        dVar6 = d_npc::_4096 * dVar6 * (d_npc::_4097 - dVar8 * dVar6 * dVar6);
        dVar6 = d_npc::_4096 * dVar6 * (d_npc::_4097 - dVar8 * dVar6 * dVar6);
        dVar8 = (double)(float)(dVar8 * d_npc::_4096 * dVar6 *
                                        (d_npc::_4097 - dVar8 * dVar6 * dVar6));
      }
      if (dVar8 < dVar9) {
        uVar4 = uVar3 & 0xff;
        dVar9 = dVar8;
      }
    }
    this->mCurrPointIndex = (byte)uVar4;
    uVar1 = 1;
  }
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  __psq_l0(auStack24,uVar5);
  __psq_l1(auStack24,uVar5);
  __psq_l0(auStack40,uVar5);
  __psq_l1(auStack40,uVar5);
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x8021b648) */
/* WARNING: Removing unreachable block (ram,0x8021b650) */
/* __thiscall dNpc_PathRun_c::setNearPathIndxMk(cXyz *) */

double __thiscall dNpc_PathRun_c::setNearPathIndxMk(dNpc_PathRun_c *this,cXyz *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  double dVar5;
  double dVar6;
  double in_f30;
  undefined8 in_f31;
  double dVar7;
  float fVar8;
  cXyz local_64;
  cXyz local_58;
  cXyz local_4c;
  cXyz local_40;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,SUB84(in_f30,0),0);
  if (this->mPath != (dPath *)0x0) {
    in_f30 = (double)d_npc::_4365;
    uVar3 = 0;
    dVar7 = (double)d_npc::0_0;
    for (uVar2 = 0; uVar1 = maxPoint(this), (int)uVar2 < (int)(uVar1 & 0xff); uVar2 = uVar2 + 1) {
      getPoint(&local_58,this,(uchar)uVar2);
      local_40.x = local_58.x;
      local_40.y = local_58.y;
      local_40.z = local_58.z;
      ::cXyz::operator__(&local_64,param_1,&local_40);
      local_4c.x = local_64.x;
      local_4c.y = local_64.y;
      local_4c.z = local_64.z;
      fVar8 = mtx::PSVECSquareMag(&local_4c);
      dVar6 = (double)fVar8;
      if (dVar7 < dVar6) {
        dVar5 = 1.0 / SQRT(dVar6);
        dVar5 = d_npc::_4096 * dVar5 * (d_npc::_4097 - dVar6 * dVar5 * dVar5);
        dVar5 = d_npc::_4096 * dVar5 * (d_npc::_4097 - dVar6 * dVar5 * dVar5);
        dVar6 = (double)(float)(dVar6 * d_npc::_4096 * dVar5 *
                                        (d_npc::_4097 - dVar6 * dVar5 * dVar5));
      }
      if (dVar6 < in_f30) {
        uVar3 = uVar2 & 0xff;
        in_f30 = dVar6;
      }
    }
    this->mCurrPointIndex = (byte)uVar3;
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  __psq_l0(auStack24,uVar4);
  __psq_l1(auStack24,uVar4);
  return in_f30;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* WARNING: Removing unreachable block (ram,0x8021b7f0) */
/* WARNING: Removing unreachable block (ram,0x8021b7e8) */
/* WARNING: Removing unreachable block (ram,0x8021b7f8) */
/* __thiscall dNpc_PathRun_c::setNearPathIndxMk2(cXyz *,
                                                 unsigned char,
                                                 unsigned char) */

undefined4 __thiscall
dNpc_PathRun_c::setNearPathIndxMk2(dNpc_PathRun_c *this,cXyz *param_1,uchar param_2,uchar param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  double dVar7;
  undefined8 in_f29;
  double dVar8;
  undefined8 in_f30;
  double dVar9;
  undefined8 in_f31;
  double dVar10;
  float fVar11;
  cXyz local_84;
  cXyz local_78;
  cXyz local_6c;
  cXyz local_60;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar3 = (uint)param_2;
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  uVar5 = 0;
  if (this->mPath != (dPath *)0x0) {
    dVar9 = (double)d_npc::_4365;
    dVar10 = (double)d_npc::0_0;
    for (uVar4 = 0; uVar2 = maxPoint(this), (int)uVar4 < (int)(uVar2 & 0xff); uVar4 = uVar4 + 1) {
      getPoint(&local_78,this,(uchar)uVar4);
      local_60.x = local_78.x;
      local_60.y = local_78.y;
      local_60.z = local_78.z;
      ::cXyz::operator__(&local_84,param_1,&local_60);
      local_6c.x = local_84.x;
      local_6c.y = local_84.y;
      local_6c.z = local_84.z;
      fVar11 = mtx::PSVECSquareMag(&local_6c);
      dVar8 = (double)fVar11;
      if (dVar10 < dVar8) {
        dVar7 = 1.0 / SQRT(dVar8);
        dVar7 = d_npc::_4096 * dVar7 * (d_npc::_4097 - dVar8 * dVar7 * dVar7);
        dVar7 = d_npc::_4096 * dVar7 * (d_npc::_4097 - dVar8 * dVar7 * dVar7);
        dVar8 = (double)(float)(dVar8 * d_npc::_4096 * dVar7 *
                                        (d_npc::_4097 - dVar8 * dVar7 * dVar7));
      }
      iVar1 = absIdx(this,param_2,(uchar)uVar4);
      if (((iVar1 <= (int)(uint)param_3) && (param_2 != uVar4)) && (dVar8 < dVar9)) {
        uVar3 = uVar4 & 0xff;
        uVar5 = 1;
        dVar9 = dVar8;
      }
    }
    this->mCurrPointIndex = (byte)uVar3;
  }
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  __psq_l0(auStack24,uVar6);
  __psq_l1(auStack24,uVar6);
  __psq_l0(auStack40,uVar6);
  __psq_l1(auStack40,uVar6);
  return uVar5;
}


/* __thiscall dNpc_PathRun_c::chkInside(cXyz *) */

undefined4 __thiscall dNpc_PathRun_c::chkInside(dNpc_PathRun_c *this,cXyz *param_1)

{
  short sVar1;
  short sVar2;
  short sVar3;
  cXyz local_58;
  cXyz local_4c;
  cXyz local_40;
  cXyz local_34;
  cXyz local_28;
  cXyz local_1c;
  
  setNearPathIndx(this,param_1,d_npc::0_0);
  getPoint(&local_40,this,this->mCurrPointIndex);
  local_28.x = local_40.x;
  local_28.y = local_40.y;
  local_28.z = local_40.z;
  decIdxLoop(this);
  getPoint(&local_4c,this,this->mCurrPointIndex);
  local_1c.x = local_4c.x;
  local_1c.y = local_4c.y;
  local_1c.z = local_4c.z;
  incIdxLoop(this);
  incIdxLoop(this);
  getPoint(&local_58,this,this->mCurrPointIndex);
  local_34.x = local_58.x;
  local_34.y = local_58.y;
  local_34.z = local_58.z;
  sVar1 = SComponent::cLib_targetAngleY(&local_28,&local_1c);
  sVar2 = SComponent::cLib_targetAngleY(&local_28,param_1);
  sVar3 = SComponent::cLib_targetAngleY(&local_28,&local_34);
  sVar2 = sVar2 - sVar3;
  sVar1 = sVar1 - sVar3;
  if (sVar2 < 1) {
    if ((sVar1 < 0) && (sVar2 < sVar1)) {
      return 1;
    }
  }
  else {
    if ((sVar1 < 0) || (sVar2 < sVar1)) {
      return 1;
    }
  }
  return 0;
}


/* __thiscall dNpc_EventCut_c::setActorInfo(char *,
                                            fopAc_ac_c *) */

void __thiscall
dNpc_EventCut_c::setActorInfo(dNpc_EventCut_c *this,char *param_1,fopAc_ac_c *param_2)

{
  float fVar1;
  
  this->mpEvtStaffName = param_1;
  this->mpActor = param_2;
  fVar1 = d_npc::0_0;
  (this->mTargetActorPos).x = d_npc::0_0;
  (this->mTargetActorPos).y = fVar1;
  (this->mTargetActorPos).z = fVar1;
  (this->mOffsetPos).x = fVar1;
  (this->mOffsetPos).y = fVar1;
  (this->mOffsetPos).z = fVar1;
  (this->mPos).x = fVar1;
  (this->mPos).y = fVar1;
  (this->mPos).z = fVar1;
  this->mCurActIdx = -1;
  return;
}


/* __thiscall dNpc_EventCut_c::setActorInfo2(char *,
                                             fopNpc_npc_c *) */

void __thiscall
dNpc_EventCut_c::setActorInfo2(dNpc_EventCut_c *this,char *pStaffName,fopNpc_npc_c *actor)

{
  float fVar1;
  
  this->mpEvtStaffName = pStaffName;
  this->mpActor = &actor->parent;
  this->mpTalkActor = actor;
  fVar1 = d_npc::0_0;
  (this->mTargetActorPos).x = d_npc::0_0;
  (this->mTargetActorPos).y = fVar1;
  (this->mTargetActorPos).z = fVar1;
  (this->mOffsetPos).x = fVar1;
  (this->mOffsetPos).y = fVar1;
  (this->mOffsetPos).z = fVar1;
  (this->mPos).x = fVar1;
  (this->mPos).y = fVar1;
  (this->mPos).z = fVar1;
  this->mCurActIdx = -1;
  return;
}


namespace d_npc {

/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x8021ba94) */
/* WARNING: Removing unreachable block (ram,0x8021ba9c) */
/* __stdcall dNpc_setAnmIDRes(mDoExt_McaMorf *,
                              int,
                              float,
                              float,
                              int,
                              int,
                              char const *) */

undefined4
dNpc_setAnmIDRes
          (double param_1,double param_2,mDoExt_McaMorf *param_3,int param_4,ushort param_5,
          int param_6,char *param_7)

{
  undefined4 uVar1;
  J3DAnmTransform *pAnimRes;
  void *pSoundAnimRes;
  undefined4 uVar2;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  pSoundAnimRes = (void *)0x0;
  uVar1 = 0;
  if (param_3 != (mDoExt_McaMorf *)0x0) {
    if (-1 < param_6) {
      pSoundAnimRes =
           dRes_control_c::getIDRes
                     (param_7,(ushort)param_6,
                      d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
    }
    pAnimRes = (J3DAnmTransform *)
               dRes_control_c::getIDRes
                         (param_7,param_5,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,
                          0x40);
    mDoExt_McaMorf::setAnm
              (param_3,pAnimRes,param_4,(float)param_1,(float)param_2,0_0,_5240,pSoundAnimRes);
    uVar1 = 1;
  }
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  __psq_l0(auStack24,uVar2);
  __psq_l1(auStack24,uVar2);
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x8021bb80) */
/* WARNING: Removing unreachable block (ram,0x8021bb88) */
/* __stdcall dNpc_setAnmFNDirect(mDoExt_McaMorf *,
                                 int,
                                 float,
                                 float,
                                 char *,
                                 char *,
                                 char const *) */

undefined4
dNpc_setAnmFNDirect
          (double param_1,double param_2,mDoExt_McaMorf *param_3,int param_4,char *param_5,
          char *param_6,char *param_7)

{
  undefined4 uVar1;
  J3DAnmTransform *pAnimRes;
  void *pSoundAnimRes;
  undefined4 uVar2;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  uVar1 = 0;
  if (((param_3 != (mDoExt_McaMorf *)0x0) && (param_5 != (char *)0x0)) && (param_7 != (char *)0x0))
  {
    pAnimRes = (J3DAnmTransform *)
               dRes_control_c::getRes
                         (param_7,param_5,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,
                          0x40);
    pSoundAnimRes = (void *)0x0;
    if (param_6 != (char *)0x0) {
      pSoundAnimRes =
           dRes_control_c::getRes
                     (param_7,param_6,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
    }
    mDoExt_McaMorf::setAnm
              (param_3,pAnimRes,param_4,(float)param_1,(float)param_2,0_0,_5240,pSoundAnimRes);
    uVar1 = 1;
  }
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  __psq_l0(auStack24,uVar2);
  __psq_l1(auStack24,uVar2);
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x8021bc64) */
/* WARNING: Removing unreachable block (ram,0x8021bc6c) */
/* __stdcall dNpc_setAnm(mDoExt_McaMorf *,
                         int,
                         float,
                         float,
                         int,
                         int,
                         char const *) */

undefined4
dNpc_setAnm(double param_1,double param_2,mDoExt_McaMorf *param_3,int param_4,long param_5,
                  int param_6,char *param_7)

{
  undefined4 uVar1;
  J3DAnmTransform *pAnimRes;
  void *pSoundAnimRes;
  undefined4 uVar2;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  pSoundAnimRes = (void *)0x0;
  uVar1 = 0;
  if (param_3 != (mDoExt_McaMorf *)0x0) {
    if (-1 < param_6) {
      pSoundAnimRes =
           dRes_control_c::getRes
                     (param_7,param_6,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
    }
    pAnimRes = (J3DAnmTransform *)
               dRes_control_c::getRes
                         (param_7,param_5,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,
                          0x40);
    mDoExt_McaMorf::setAnm
              (param_3,pAnimRes,param_4,(float)param_1,(float)param_2,0_0,_5240,pSoundAnimRes);
    uVar1 = 1;
  }
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  __psq_l0(auStack24,uVar2);
  __psq_l1(auStack24,uVar2);
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __stdcall dNpc_setShadowModel(J3DModel *,
                                 J3DModelData *,
                                 J3DModel *) */

void dNpc_setShadowModel(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  for (iVar1 = 0; iVar1 < (int)(uint)*(ushort *)(param_2 + 0x30); iVar1 = iVar1 + 1) {
    mtx::PSMTXCopy((MTX34 *)(*(int *)(param_3 + 0x90) + iVar2),
                   (MTX34 *)(*(int *)(param_1 + 0x90) + iVar2));
    iVar2 = iVar2 + 0x30;
  }
  iVar2 = 0;
  for (iVar1 = 0; iVar1 < (int)(uint)*(ushort *)(param_2 + 0x28); iVar1 = iVar1 + 1) {
    mtx::PSMTXCopy((MTX34 *)(*(int *)(param_3 + 0x8c) + iVar2),
                   (MTX34 *)(*(int *)(param_1 + 0x8c) + iVar2));
    iVar2 = iVar2 + 0x30;
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x8021bdc8) */
/* WARNING: Unable to use type for symbol pPlayer */
/* __stdcall dNpc_playerEyePos(float) */

void dNpc_playerEyePos(float param_1,cXyz *outPos)

{
  float fVar1;
  undefined4 uVar2;
  double dVar3;
  undefined8 in_f31;
  cXyz local_48;
  cXyz local_3c;
  cXyz local_30;
  undefined auStack8 [8];
  daPy_lk_c *pPlayer;
  
  pPlayer = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor;
  dVar3 = (double)param_1;
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  ::daPy_py_c::getHeadTopPos
            (&local_48,&(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent);
  local_30.x = local_48.x;
  local_30.y = local_48.y;
  local_30.z = local_48.z;
  SComponent::MtxTrans((double)local_48.x,(double)local_48.y,(double)local_48.z,false);
  local_30.x = 0_0;
  local_30.y = (float)dVar3;
  local_30.z = 0_0;
  SComponent::MtxPosition(&local_30,&local_3c);
  fVar1 = (pPlayer->parent).parent.mCurrent.mPos.z;
  outPos->x = (pPlayer->parent).parent.mCurrent.mPos.x;
  outPos->y = local_3c.y;
  outPos->z = fVar1;
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  return;
}


/* __stdcall dNpc_calc_DisXZ_AngY(cXyz,
                                  cXyz,
                                  float *,
                                  short *) */

void dNpc_calc_DisXZ_AngY(cXyz *param_1,cXyz *param_2,float *param_3,short *param_4)

{
  float fVar1;
  float fVar2;
  int iVar3;
  double dVar4;
  double dVar5;
  
  fVar1 = param_2->x - param_1->x;
  fVar2 = param_2->z - param_1->z;
  if (param_3 != (float *)0x0) {
    dVar5 = (double)(fVar1 * fVar1 + fVar2 * fVar2);
    if ((double)0_0 < dVar5) {
      dVar4 = 1.0 / SQRT(dVar5);
      dVar4 = _4096 * dVar4 * (_4097 - dVar5 * dVar4 * dVar4);
      dVar4 = _4096 * dVar4 * (_4097 - dVar5 * dVar4 * dVar4);
      dVar5 = (double)(float)(dVar5 * _4096 * dVar4 * (_4097 - dVar5 * dVar4 * dVar4));
    }
    *param_3 = (float)dVar5;
  }
  if (param_4 != (short *)0x0) {
    iVar3 = SComponent::cM_atan2s(fVar1,fVar2);
    *param_4 = (short)iVar3;
  }
  return;
}


/* __stdcall dNpc_chkArasoi(void) */

undefined4 dNpc_chkArasoi(void)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x1220);
  if ((iVar1 != 0) &&
     (iVar1 = dSv_event_c::isEventBit
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x1808),
     iVar1 == 0)) {
    uVar2 = 1;
  }
  return uVar2;
}


/* __stdcall dNpc_chkLetterPassed(void) */

uint dNpc_chkLetterPassed(void)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  iVar1 = dSv_player_get_bag_item_c::isReserve
                    (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,'\f');
  if (iVar1 != 0) {
    uVar2 = dSv_player_bag_item_c::checkReserveItem
                      (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem,0x98);
    uVar2 = countLeadingZeros(uVar2 & 0xff);
    uVar2 = uVar2 >> 5;
  }
  return uVar2;
}

}

/* __thiscall fopNpc_npc_c::setCollision(float,
                                         float) */

void __thiscall fopNpc_npc_c::setCollision(fopNpc_npc_c *this,float radius,float height)

{
  double dVar1;
  double dVar2;
  
  dVar2 = (double)height;
  dVar1 = (double)radius;
  ::cM3dGCyl::SetC(&(this->mCyl).mCylAttr.mCyl,&(this->parent).mCurrent.mPos);
  ::cM3dGCyl::SetR(&(this->mCyl).mCylAttr.mCyl,(float)dVar1);
  ::cM3dGCyl::SetH(&(this->mCyl).mCylAttr.mCyl,(float)dVar2);
  cCcS::Set(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.parent,(cCcD_Obj *)&this->mCyl);
  return;
}


/* __thiscall fopNpc_npc_c::talk(int) */

short __thiscall fopNpc_npc_c::talk(fopNpc_npc_c *this,int param_1)

{
  ulong uVar1;
  uint uVar2;
  short sVar3;
  msg_class *msg;
  short sVar4;
  
  sVar4 = 0xff;
  if (this->mCurrMsgBsPcId == 0xffffffff) {
    if (param_1 == 1) {
      uVar1 = (*(code *)this->vtbl->getMsg)();
      this->mCurrMsgID = uVar1;
    }
    uVar2 = f_op_msg_mng::fopMsgM_messageSet(this->mCurrMsgID,&this->parent);
    this->mCurrMsgBsPcId = uVar2;
    this->mpCurrMsg = (msg_class *)0x0;
  }
  else {
    msg = this->mpCurrMsg;
    if (msg == (msg_class *)0x0) {
      msg = f_op_msg_mng::fopMsgM_SearchByID(this->mCurrMsgBsPcId);
      this->mpCurrMsg = msg;
    }
    else {
      sVar4 = msg->mMode;
      if (sVar4 == 0xe) {
        sVar3 = (*(code *)this->vtbl->next_msgStatus)(this,&this->mCurrMsgID);
        this->mpCurrMsg->mMode = sVar3;
        if (this->mpCurrMsg->mMode == 0xf) {
          f_op_msg_mng::fopMsgM_messageSet(this->mCurrMsgID);
        }
      }
      else {
        if (sVar4 == 0x12) {
          msg->mMode = 0x13;
          this->mCurrMsgBsPcId = -1;
        }
      }
      (*(code *)this->vtbl->anmAtr)(this,sVar4);
    }
  }
  return sVar4;
}


namespace d_npc {

/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x8021c210) */
/* WARNING: Removing unreachable block (ram,0x8021c218) */
/* __stdcall dNpc_setAnm_2(mDoExt_McaMorf *,
                           int,
                           float,
                           float,
                           int,
                           int,
                           char const *) */

undefined4
dNpc_setAnm_2
          (double param_1,double param_2,mDoExt_McaMorf *param_3,int param_4,long param_5,
          int param_6,char *param_7)

{
  void *pSoundAnimRes;
  J3DAnmTransform *pJVar1;
  undefined4 uVar2;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  if (param_6 < 0) {
    pJVar1 = (J3DAnmTransform *)
             dRes_control_c::getRes
                       (param_7,param_5,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40
                       );
    mDoExt_McaMorf::setAnm
              (param_3,pJVar1,param_4,(float)param_1,(float)param_2,0_0,_5240,(void *)0x0);
  }
  else {
    pSoundAnimRes =
         dRes_control_c::getRes
                   (param_7,param_6,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
    pJVar1 = (J3DAnmTransform *)
             dRes_control_c::getRes
                       (param_7,param_5,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40
                       );
    mDoExt_McaMorf::setAnm
              (param_3,pJVar1,param_4,(float)param_1,(float)param_2,0_0,_5240,pSoundAnimRes);
  }
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  __psq_l0(auStack24,uVar2);
  __psq_l1(auStack24,uVar2);
  return 1;
}

}

/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dNpc_HeadAnm_c::swing_vertical_init(short,
                                                  short,
                                                  short,
                                                  int) */

void __thiscall
dNpc_HeadAnm_c::swing_vertical_init
          (dNpc_HeadAnm_c *this,short param_1,short param_2,short param_3,int param_4)

{
  int iVar1;
  bool bVar2;
  
  if ((param_4 == 0) ||
     (bVar2 = Runtime.PPCEABI.H::__ptmf_cmpr(&this->mFunc,(PTMF *)&d_npc::_5751), bVar2 != false)) {
    this->field_0x1c = 0;
    this->field_0x20 = param_1;
    this->field_0x1e = param_2;
    this->field_0x14 =
         (float)((double)CONCAT44(0x43300000,(int)param_3 ^ 0x80000000) - d_npc::_4768);
    iVar1 = DAT_80393bec;
    (this->mFunc).this_delta = d_npc::_5755;
    (this->mFunc).vtbl_offset = iVar1;
    (this->mFunc).func = PTR_swing_vertical_80393bf0;
  }
  return;
}


/* __thiscall dNpc_HeadAnm_c::swing_vertical(void) */

void __thiscall dNpc_HeadAnm_c::swing_vertical(dNpc_HeadAnm_c *this)

{
  int iVar1;
  short sVar2;
  
  sVar2 = this->field_0x1c;
  this->field_0x1c = sVar2 + this->field_0x1e;
  SComponent::cLib_addCalcAngleS
            (&this->field_0x0,
             (short)(int)(this->field_0x14 *
                         JKernel::JMath::jmaSinTable
                         [(int)((int)this->field_0x1c & 0xffffU) >>
                          (JKernel::JMath::jmaSinShift & 0x3f)]),4,0x1000,0x100);
  SComponent::cLib_addCalcAngleS(&this->field_0x2,0,4,0x1000,0x100);
  if (sVar2 < 0) {
    if (-1 < this->field_0x1c) {
      sVar2 = this->field_0x20 + -1;
      this->field_0x20 = sVar2;
      iVar1 = DAT_80370fbc;
      if (sVar2 < 1) {
        (this->mFunc).this_delta = Runtime.PPCEABI.H::__ptmf_null;
        (this->mFunc).vtbl_offset = iVar1;
        (this->mFunc).func = DAT_80370fc0;
      }
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dNpc_HeadAnm_c::swing_horizone_init(short,
                                                  short,
                                                  short,
                                                  int) */

void __thiscall
dNpc_HeadAnm_c::swing_horizone_init
          (dNpc_HeadAnm_c *this,short param_1,short param_2,short param_3,int param_4)

{
  int iVar1;
  bool bVar2;
  
  if ((param_4 == 0) ||
     (bVar2 = Runtime.PPCEABI.H::__ptmf_cmpr(&this->mFunc,(PTMF *)&d_npc::_5781), bVar2 != false)) {
    this->field_0x1c = 0;
    this->field_0x20 = param_1;
    this->field_0x1e = param_2;
    this->field_0x18 =
         (float)((double)CONCAT44(0x43300000,(int)param_3 ^ 0x80000000) - d_npc::_4768);
    iVar1 = DAT_80393c04;
    (this->mFunc).this_delta = d_npc::_5785;
    (this->mFunc).vtbl_offset = iVar1;
    (this->mFunc).func = PTR_swing_horizone_80393c08;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dNpc_HeadAnm_c::swing_horizone(void) */

void __thiscall dNpc_HeadAnm_c::swing_horizone(dNpc_HeadAnm_c *this)

{
  float fVar1;
  float fVar2;
  int iVar3;
  short sVar4;
  
  sVar4 = this->field_0x1c;
  this->field_0x1c = sVar4 + this->field_0x1e;
  fVar2 = JKernel::JMath::jmaSinTable
          [(int)((int)this->field_0x1c & 0xffffU) >> (JKernel::JMath::jmaSinShift & 0x3f)];
  fVar1 = this->field_0x18;
  SComponent::cLib_addCalcAngleS(&this->field_0x0,0,4,0x1000,0x100);
  SComponent::cLib_addCalcAngleS(&this->field_0x2,(short)(int)(fVar1 * fVar2),4,0x1000,0x100);
  if (sVar4 < 0) {
    if (-1 < this->field_0x1c) {
      sVar4 = this->field_0x20 + -1;
      this->field_0x20 = sVar4;
      iVar3 = DAT_80370fbc;
      if (sVar4 < 1) {
        (this->mFunc).this_delta = Runtime.PPCEABI.H::__ptmf_null;
        (this->mFunc).vtbl_offset = iVar3;
        (this->mFunc).func = DAT_80370fc0;
      }
    }
  }
  return;
}


/* __thiscall dNpc_HeadAnm_c::move(void) */

void __thiscall dNpc_HeadAnm_c::move(dNpc_HeadAnm_c *this)

{
  bool bVar1;
  void *in_r4;
  
  bVar1 = Runtime.PPCEABI.H::__ptmf_test(&this->mFunc);
  if (bVar1 == false) {
    SComponent::cLib_addCalcAngleS(&this->field_0x0,0,4,0x1000,0x100);
    SComponent::cLib_addCalcAngleS(&this->field_0x2,0,4,0x1000,0x100);
  }
  else {
    Runtime.PPCEABI.H::__ptmf_scall(&this->mFunc,this,in_r4);
  }
  return;
}


/* __thiscall dNpc_JntCtrl_c::chkLim(short,
                                     int,
                                     int) */

int __thiscall dNpc_JntCtrl_c::chkLim(dNpc_JntCtrl_c *this,short param_1,int param_2,int param_3)

{
  if ((&this->field_0x16)[param_2 * 2 + param_3] < param_1) {
    param_1 = (&this->field_0x16)[param_2 * 2 + param_3];
  }
  if (param_1 < (&this->field_0xe)[param_2 * 2 + param_3]) {
    param_1 = (&this->field_0xe)[param_2 * 2 + param_3];
  }
  return (int)param_1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dNpc_JntCtrl_c::turn_fromBackbone2Head(short,
                                                     short *,
                                                     short *,
                                                     bool) */

void __thiscall
dNpc_JntCtrl_c::turn_fromBackbone2Head
          (dNpc_JntCtrl_c *this,short param_1,short *param_2,short *param_3,bool param_4)

{
  short sVar1;
  
  *param_3 = 0;
  if (this->field_0xc == 0) {
    sVar1 = chkLim(this,param_1,1,1);
    *param_3 = sVar1;
    if ((this->field_0x32 != 0) && (*param_3 < 0)) {
      *param_3 = 0;
    }
  }
  *param_2 = 0;
  if (this->field_0xb == 0) {
    *param_2 = param_1 - *param_3;
    sVar1 = chkLim(this,*param_2,0,1);
    *param_2 = sVar1;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dNpc_JntCtrl_c::turn_fromHead2Backbone(short,
                                                     short *,
                                                     short *) */

void __thiscall
dNpc_JntCtrl_c::turn_fromHead2Backbone
          (dNpc_JntCtrl_c *this,short param_1,short *param_2,short *param_3)

{
  short sVar1;
  
  *param_2 = 0;
  if (this->field_0xb == 0) {
    *param_2 = param_1 - this->field_0x32;
    sVar1 = chkLim(this,*param_2,0,1);
    *param_2 = sVar1;
  }
  *param_3 = 0;
  if (this->field_0xc == 0) {
    *param_3 = param_1 - *param_2;
    sVar1 = chkLim(this,*param_3,1,1);
    *param_3 = sVar1;
  }
  return;
}


/* __thiscall dNpc_JntCtrl_c::follow_current(short *,
                                             short) */

int __thiscall dNpc_JntCtrl_c::follow_current(dNpc_JntCtrl_c *this,short *param_1,short param_2)

{
  short sVar1;
  
  sVar1 = *param_1;
  *param_1 = sVar1 - param_2;
  if ((sVar1 < 1) || (-1 < *param_1)) {
    if (-1 < sVar1) {
      return 0;
    }
    if (*param_1 < 1) {
      return 0;
    }
  }
  sVar1 = *param_1;
  *param_1 = 0;
  return (int)-sVar1;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall dNpc_JntCtrl_c::lookAtTarget_2(short *,
                                             cXyz *,
                                             cXyz,
                                             short,
                                             short,
                                             bool) */

void __thiscall
dNpc_JntCtrl_c::lookAtTarget_2
          (dNpc_JntCtrl_c *this,short *param_1,cXyz *param_2,cXyz *param_3,short param_4,
          short param_5,bool param_6)

{
  short sVar1;
  short sVar2;
  short sVar3;
  undefined2 uVar4;
  uint uVar5;
  uint uVar6;
  short local_38;
  short local_36;
  int local_34;
  int local_30 [4];
  
  if (param_2 == (cXyz *)0x0) {
    sVar3 = 0;
  }
  else {
    param_4 = SComponent::cLib_targetAngleY(param_3,param_2);
    sVar3 = SComponent::cLib_targetAngleX(param_3,param_2);
  }
  sVar1 = param_4 - *param_1;
  uVar6 = SEXT24(sVar1);
  sVar2 = this->field_0x32;
  if (sVar2 < 0) {
    if (((int)sVar2 < (int)uVar6) && (sVar2 != 0)) {
      turn_fromBackbone2Head(this,sVar1,&local_36,&local_38,(bool)((char)(sVar2 >> 7) + '\x01'));
    }
    else {
      turn_fromHead2Backbone(this,sVar1,&local_36,&local_38);
    }
  }
  else {
    if (((int)uVar6 < (int)sVar2) && (sVar2 != 0)) {
      turn_fromBackbone2Head(this,sVar1,&local_36,&local_38,(bool)((char)(sVar2 >> 7) + '\x01'));
    }
    else {
      turn_fromHead2Backbone(this,sVar1,&local_36,&local_38);
    }
  }
  *(short *)&this->field_0x2e = local_36;
  this->field_0x32 = local_38;
  sVar2 = this->field_0x32;
  local_30[0] = (int)this->mHeadLeftRightRot;
  local_34 = (int)this->mBackboneLeftRightRot;
  SComponent::cLib_addCalcAngleL
            (local_30,(int)*(short *)&this->field_0x2e,4,(int)this->field_0x1e,4);
  SComponent::cLib_addCalcAngleL(&local_34,(int)sVar2,4,(int)this->field_0x1e,4);
  this->mHeadLeftRightRot = (short)local_30[0];
  this->mBackboneLeftRightRot = (short)local_34;
  if ((this->field_0xa == false) || (param_6 != false)) {
    uVar5 = (int)*(short *)&this->field_0x2e + (int)this->field_0x32;
    if (sVar1 < 0) {
      this->field_0xa = SUB41(((int)(uVar5 ^ uVar6) >> 1) - ((uVar5 ^ uVar6) & uVar5) >> 0x1f,0);
    }
    else {
      this->field_0xa = SUB41(((int)(uVar6 ^ uVar5) >> 1) - ((uVar6 ^ uVar5) & uVar6) >> 0x1f,0);
    }
  }
  else {
    sVar2 = *param_1;
    SComponent::cLib_addCalcAngleS(param_1,param_4,4,param_5,0x100);
    sVar2 = *param_1 - sVar2;
    this->field_0xa = (bool)('\x01' - (sVar2 == 0));
    if (this->field_0xc == 0) {
      sVar2 = follow_current(this,&this->mBackboneLeftRightRot,sVar2);
    }
    if (this->field_0xb == 0) {
      follow_current(this,&this->mHeadLeftRightRot,sVar2);
    }
  }
  sVar2 = chkLim(this,sVar3,0,0);
  uVar4 = chkLim(this,sVar3 - sVar2,1,0);
  *(short *)&this->field_0x2c = sVar2;
  *(undefined2 *)&this->field_0x30 = uVar4;
  sVar3 = *(short *)&this->field_0x30;
  local_30[0] = (int)this->mHeadUpDownRot;
  local_34 = (int)this->mBackboneUpDownRot;
  SComponent::cLib_addCalcAngleL
            (local_30,(int)*(short *)&this->field_0x2c,4,(int)this->field_0x1e,4);
  SComponent::cLib_addCalcAngleL(&local_34,(int)sVar3,4,(int)this->field_0x1e,4);
  this->mHeadUpDownRot = (short)local_30[0];
  this->mBackboneUpDownRot = (short)local_34;
  return;
}


namespace d_npc {

/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x8021cc24) */
/* WARNING: Removing unreachable block (ram,0x8021cc1c) */
/* WARNING: Removing unreachable block (ram,0x8021cc2c) */
/* __stdcall dNpc_chkAttn(fopAc_ac_c *,
                          cXyz,
                          float,
                          float,
                          float,
                          bool) */

undefined4
dNpc_chkAttn(fopAc_ac_c *this,cXyz *destPos,double param_3,double param_4,double param_5,
                   bool param_6)

{
  short sVar2;
  int iVar1;
  undefined4 uVar3;
  undefined4 uVar4;
  double dVar5;
  double dVar6;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  float fVar7;
  cXyz local_64;
  cXyz local_58 [2];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  sVar2 = SComponent::cLib_targetAngleY(&(this->mCurrent).mPos,destPos);
  ::cXyz::operator__(local_58,&(this->mCurrent).mPos,destPos);
  local_64.x = local_58[0].x;
  local_64.y = 0_0;
  local_64.z = local_58[0].z;
  fVar7 = mtx::PSVECSquareMag(&local_64);
  dVar6 = (double)fVar7;
  if ((double)0_0 < dVar6) {
    dVar5 = 1.0 / SQRT(dVar6);
    dVar5 = _4096 * dVar5 * (_4097 - dVar6 * dVar5 * dVar5);
    dVar5 = _4096 * dVar5 * (_4097 - dVar6 * dVar5 * dVar5);
    dVar6 = (double)(float)(dVar6 * _4096 * dVar5 * (_4097 - dVar6 * dVar5 * dVar5));
  }
  if ((double)_5955 < param_5) {
    param_5 = (double)_5955;
  }
  if (param_5 < (double)0_0) {
    param_5 = (double)0_0;
  }
  if (param_6 != false) {
    param_3 = (double)(float)(param_3 + param_4);
  }
  uVar3 = 0;
  if ((dVar6 <= param_3) &&
     (iVar1 = MSL_C.PPCEABI.bare.H::abs((int)(short)(sVar2 - (this->mCurrent).mRot.y)),
     iVar1 <= (short)(int)((double)_5956 * param_5))) {
    uVar3 = 1;
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  __psq_l0(auStack24,uVar4);
  __psq_l1(auStack24,uVar4);
  __psq_l0(auStack40,uVar4);
  __psq_l1(auStack40,uVar4);
  return uVar3;
}

}

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dNpc_EventCut_c::cutProc(void) */

bool __thiscall dNpc_EventCut_c::cutProc(dNpc_EventCut_c *this)

{
  int iVar1;
  bool bVar2;
  void *pvVar3;
  
  if ((this->mpEvtStaffName == (char *)0x0) || (this->mpActor == (fopAc_ac_c *)0x0)) {
    bVar2 = false;
  }
  else {
    iVar1 = dEvent_manager_c::getMyStaffId
                      (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mpEvtStaffName,
                       (fopAc_ac_c *)0x0,0);
    this->mEvtStaffId = iVar1;
    if (this->mEvtStaffId == -1) {
      bVar2 = false;
    }
    else {
      if (d_npc::init_4569 == '\0') {
        d_npc::cut_tbl_4554 = d_npc::_4555;
        DAT_80393b38 = DAT_80393a90;
        DAT_80393b3c = PTR_cutWaitStart_80393a94;
        DAT_80393b40 = d_npc::_4556;
        DAT_80393b44 = DAT_80393a9c;
        DAT_80393b48 = PTR_cutWaitProc_80393aa0;
        DAT_80393b4c = d_npc::_4557;
        DAT_80393b50 = DAT_80393aa8;
        DAT_80393b54 = PTR_cutTurnToActorStart_80393aac;
        DAT_80393b58 = d_npc::_4558;
        DAT_80393b5c = DAT_80393ab4;
        DAT_80393b60 = PTR_cutTurnToActorProc_80393ab8;
        DAT_80393b64 = d_npc::_4559;
        DAT_80393b68 = DAT_80393ac0;
        DAT_80393b6c = PTR_cutMoveToActorStart_80393ac4;
        DAT_80393b70 = d_npc::_4560;
        DAT_80393b74 = DAT_80393acc;
        DAT_80393b78 = PTR_cutMoveToActorProc_80393ad0;
        DAT_80393b7c = d_npc::_4561;
        DAT_80393b80 = DAT_80393ad8;
        DAT_80393b84 = PTR_cutTurnToPosStart_80393adc;
        DAT_80393b88 = d_npc::_4562;
        DAT_80393b8c = DAT_80393ae4;
        DAT_80393b90 = PTR_cutTurnToPosProc_80393ae8;
        DAT_80393b94 = d_npc::_4563;
        DAT_80393b98 = DAT_80393af0;
        DAT_80393b9c = PTR_cutMoveToPosStart_80393af4;
        DAT_80393ba0 = d_npc::_4564;
        DAT_80393ba4 = DAT_80393afc;
        DAT_80393ba8 = PTR_cutMoveToPosProc_80393b00;
        DAT_80393bac = d_npc::_4565;
        DAT_80393bb0 = DAT_80393b08;
        DAT_80393bb4 = PTR_cutTalkMsgStart_80393b0c;
        DAT_80393bb8 = d_npc::_4566;
        DAT_80393bbc = DAT_80393b14;
        DAT_80393bc0 = PTR_cutTalkMsgProc_80393b18;
        DAT_80393bc4 = d_npc::_4567;
        DAT_80393bc8 = DAT_80393b20;
        DAT_80393bcc = PTR_cutContinueTalkStart_80393b24;
        DAT_80393bd0 = d_npc::_4568;
        DAT_80393bd4 = DAT_80393b2c;
        DAT_80393bd8 = PTR_cutTalkMsgProc_80393b30;
        d_npc::init_4569 = '\x01';
      }
      iVar1 = dEvent_manager_c::getMyActIdx
                        (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mEvtStaffId,
                         &d_npc::action_table_4553,7,1,0);
      this->mCurActIdx = iVar1;
      if (this->mCurActIdx == -1) {
        bVar2 = false;
      }
      else {
        pvVar3 = (void *)this->mEvtStaffId;
        bVar2 = dEvent_manager_c::getIsAddvance
                          (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,(int)pvVar3);
        if (bVar2 != false) {
          this->mbAttention = 0;
          Runtime.PPCEABI.H::__ptmf_scall
                    ((PTMF *)(&d_npc::cut_tbl_4554 + this->mCurActIdx * 6),this,pvVar3);
        }
        pvVar3 = (void *)(this->mCurActIdx * 0x18);
        Runtime.PPCEABI.H::__ptmf_scall((PTMF *)((int)pvVar3 + -0x7fc6c4c0),this,pvVar3);
        bVar2 = true;
      }
    }
  }
  return bVar2;
}


/* __thiscall dNpc_EventCut_c::cutWaitStart(void) */

void __thiscall dNpc_EventCut_c::cutWaitStart(dNpc_EventCut_c *this)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           dEvent_manager_c::getMySubstanceP
                     (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mEvtStaffId,"Timer",
                      Int);
  if (puVar1 == (undefined4 *)0x0) {
    this->mTimer = 0;
  }
  else {
    this->mTimer = (int)(short)*puVar1;
  }
  return;
}


/* __thiscall dNpc_EventCut_c::cutWaitProc(void) */

void __thiscall dNpc_EventCut_c::cutWaitProc(dNpc_EventCut_c *this)

{
  int iVar1;
  
  iVar1 = d_a_nh::cLib_calcTimer(&this->mTimer);
  if (iVar1 == 0) {
    dEvent_manager_c::cutEnd(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mEvtStaffId);
  }
  return;
}


/* __thiscall dNpc_EventCut_c::cutTurnToActorStart(void) */

void __thiscall dNpc_EventCut_c::cutTurnToActorStart(dNpc_EventCut_c *this)

{
  float fVar1;
  char *pActorName;
  int *pSetId;
  float *pfVar2;
  int *TurnType;
  undefined4 *puVar3;
  int *pTurnSpeed;
  void *pvVar4;
  
  pActorName = (char *)dEvent_manager_c::getMySubstanceP
                                 (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,
                                  this->mEvtStaffId,"ActorName",String);
  this->mpActorName = pActorName;
  pSetId = (int *)dEvent_manager_c::getMySubstanceP
                            (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mEvtStaffId,
                             "SetId",Int);
  if (pSetId == (int *)0x0) {
    this->mSetID = 0;
  }
  else {
    this->mSetID = *pSetId;
  }
  pfVar2 = (float *)dEvent_manager_c::getMySubstanceP
                              (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mEvtStaffId
                               ,"OffsetPos",Xyz);
  fVar1 = d_npc::0_0;
  if (pfVar2 == (float *)0x0) {
    (this->mOffsetPos).x = d_npc::0_0;
    (this->mOffsetPos).y = fVar1;
    (this->mOffsetPos).z = fVar1;
  }
  else {
    (this->mOffsetPos).x = *pfVar2;
    (this->mOffsetPos).y = pfVar2[1];
    (this->mOffsetPos).z = pfVar2[2];
  }
  TurnType = (int *)dEvent_manager_c::getMySubstanceP
                              (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mEvtStaffId
                               ,"TurnType",Int);
  if (TurnType == (int *)0x0) {
    this[1].mpEvtStaffName = (char *)0x1;
  }
  else {
    this[1].mpEvtStaffName = (char *)*TurnType;
  }
  puVar3 = (undefined4 *)
           dEvent_manager_c::getMySubstanceP
                     (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mEvtStaffId,"Timer",
                      Int);
  if (puVar3 == (undefined4 *)0x0) {
    this->mTimer = 1;
  }
  else {
    this->mTimer = (int)(short)*puVar3;
  }
  pTurnSpeed = (int *)dEvent_manager_c::getMySubstanceP
                                (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,
                                 this->mEvtStaffId,"TurnSpeed",Int);
  if (pTurnSpeed == (int *)0x0) {
    this->mTurnSpeed = 0;
  }
  else {
    this->mTurnSpeed = (short)*pTurnSpeed;
  }
  puVar3 = (undefined4 *)
           dEvent_manager_c::getMySubstanceP
                     (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mEvtStaffId,
                      "AddAngle",Int);
  if (puVar3 == (undefined4 *)0x0) {
    this->mAddAngle = 0;
  }
  else {
    this->mAddAngle = (short)*puVar3;
  }
  pfVar2 = (float *)dEvent_manager_c::getMySubstanceP
                              (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mEvtStaffId
                               ,"DelDistance",Float);
  if (pfVar2 == (float *)0x0) {
    this->pDelDistance = d_npc::0_0;
  }
  else {
    this->pDelDistance = *pfVar2;
  }
  pvVar4 = dEvent_manager_c::getMySubstanceP
                     (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mEvtStaffId,"NoTurn"
                      ,Int);
  if (pvVar4 == (void *)0x0) {
    this->mbNoTurn = 0;
  }
  else {
    this->mbNoTurn = 1;
  }
  this->field_0x44 = 0;
  return;
}


/* __thiscall dNpc_EventCut_c::cutTurnToActorProc(void) */

void __thiscall dNpc_EventCut_c::cutTurnToActorProc(dNpc_EventCut_c *this)

{
  short sVar1;
  float fVar2;
  char *turnType;
  uint uVar3;
  int iVar4;
  short sVar5;
  fopAc_ac_c *pfVar6;
  cXyz local_48;
  cXyz local_3c;
  cXyz cStack48;
  double local_20;
  undefined4 local_18;
  uint uStack20;
  
  fVar2 = d_npc::0_0;
  if (this->mSetID == 0) {
    if ((this->mpActorName == (char *)0x0) ||
       (iVar4 = MSL_C.PPCEABI.bare.H::strcmp(this->mpActorName,"Player"), fVar2 = d_npc::0_0,
       iVar4 == 0)) {
      this->mpTargetActor = (fopAc_ac_c *)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor;
    }
    else {
      (this->mTargetActorPos).x = d_npc::0_0;
      (this->mTargetActorPos).y = fVar2;
      (this->mTargetActorPos).z = fVar2;
      f_op_actor_iter::fopAcIt_Judge(findActorCallBack,this);
    }
  }
  else {
    (this->mTargetActorPos).x = d_npc::0_0;
    (this->mTargetActorPos).y = fVar2;
    (this->mTargetActorPos).z = fVar2;
    f_op_actor_iter::fopAcIt_Judge(findActorCallBack,this);
  }
  iVar4 = this[1].mEvtStaffId;
  if (iVar4 == 0) goto LAB_8021d2c4;
  turnType = this[1].mpEvtStaffName;
  if (turnType == (char *)0x1) {
LAB_8021d2a0:
    *(undefined *)(this[1].mEvtStaffId + 0xc) = 0;
  }
  else {
    if ((int)turnType < 1) {
      if (-1 < (int)turnType) {
        *(undefined *)(iVar4 + 0xc) = 1;
        goto LAB_8021d2c4;
      }
    }
    else {
      if ((int)turnType < 3) {
        *(undefined *)(iVar4 + 10) = 1;
        goto LAB_8021d2a0;
      }
    }
    *(undefined *)(iVar4 + 0xc) = 0;
  }
LAB_8021d2c4:
  if (this->mpTargetActor == (fopAc_ac_c *)0x0) {
    dEvent_manager_c::cutEnd(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mEvtStaffId);
  }
  if ((this->mpActorName == (char *)0x0) ||
     (iVar4 = MSL_C.PPCEABI.bare.H::strcmp(this->mpActorName,"Player"), iVar4 == 0)) {
    d_npc::dNpc_playerEyePos(d_npc::0_0,&cStack48);
    ::cXyz::operator__(&local_3c,&cStack48,&this->mOffsetPos);
    (this->mPos).x = local_3c.x;
    (this->mPos).y = local_3c.y;
    (this->mPos).z = local_3c.z;
  }
  else {
    sVar5 = this->mAddAngle;
    if ((sVar5 == 0) || (this->pDelDistance == d_npc::0_0)) {
      ::cXyz::operator__(&local_48,&(this->mpTargetActor->mCurrent).mPos,&this->mOffsetPos);
      (this->mPos).x = local_48.x;
      (this->mPos).y = local_48.y;
      (this->mPos).z = local_48.z;
    }
    else {
      pfVar6 = this->mpTargetActor;
      sVar1 = (pfVar6->mCollisionRot).y;
      (this->mPos).x = (pfVar6->mCurrent).mPos.x;
      (this->mPos).y = (pfVar6->mCurrent).mPos.y;
      (this->mPos).z = (pfVar6->mCurrent).mPos.z;
      uVar3 = (int)sVar1 + (int)sVar5 & 0xffff;
      (this->mPos).x =
           (this->mPos).x -
           this->pDelDistance *
           JKernel::JMath::jmaSinTable[(int)uVar3 >> (JKernel::JMath::jmaSinShift & 0x3f)];
      (this->mPos).z =
           (this->mPos).z -
           this->pDelDistance *
           JKernel::JMath::jmaCosTable[(int)uVar3 >> (JKernel::JMath::jmaSinShift & 0x3f)];
    }
  }
  this->mbAttention = 1;
  sVar5 = SComponent::cLib_targetAngleY(&(this->mpActor->mCurrent).mPos,&this->mPos);
  uStack20 = (int)sVar5 - (int)(this->mpActor->mCurrent).mRot.y ^ 0x80000000;
  local_20 = (double)CONCAT44(0x43300000,uStack20);
  uVar3 = (int)this->field_0x44 ^ 0x80000000;
  local_18 = 0x43300000;
  if (((float)((double)CONCAT44(0x43300000,uVar3) - d_npc::_4768) ==
       ABS((float)(local_20 - d_npc::_4768))) &&
     (local_18 = 0x43300000, uVar3 = uStack20,
     ABS((float)((double)CONCAT44(0x43300000,uStack20) - d_npc::_4768)) < d_npc::_4766)) {
    d_a_nh::cLib_calcTimer(&this->mTimer);
    uVar3 = uStack20;
  }
  uStack20 = uVar3;
  if (this->mTimer == 0) {
    this->mTurnSpeed = 0;
    dEvent_manager_c::cutEnd(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mEvtStaffId);
  }
  this->field_0x44 =
       (short)(int)ABS((float)((double)CONCAT44(0x43300000,
                                                (int)sVar5 - (int)(this->mpActor->mCurrent).mRot.y ^
                                                0x80000000) - d_npc::_4768));
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall dNpc_EventCut_c::cutMoveToActorStart(void) */

void __thiscall dNpc_EventCut_c::cutMoveToActorStart(dNpc_EventCut_c *this)

{
  float fVar1;
  char *pcVar2;
  int *piVar3;
  float *pfVar4;
  float *pfVar5;
  float *pfVar6;
  void *pvVar7;
  void *pvVar8;
  undefined4 *puVar9;
  
  pcVar2 = (char *)dEvent_manager_c::getMySubstanceP
                             (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mEvtStaffId,
                              "ActorName",String);
  this->mpActorName = pcVar2;
  piVar3 = (int *)dEvent_manager_c::getMySubstanceP
                            (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mEvtStaffId,
                             "SetId",Int);
  pfVar4 = (float *)dEvent_manager_c::getMySubstanceP
                              (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mEvtStaffId
                               ,"Speed",Float);
  pfVar5 = (float *)dEvent_manager_c::getMySubstanceP
                              (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mEvtStaffId
                               ,"DelDistance",Float);
  pfVar6 = (float *)dEvent_manager_c::getMySubstanceP
                              (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mEvtStaffId
                               ,"OffsetPos",Xyz);
  pvVar7 = dEvent_manager_c::getMySubstanceP
                     (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mEvtStaffId,
                      "Attention",Int);
  pvVar8 = dEvent_manager_c::getMySubstanceP
                     (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mEvtStaffId,"NoTurn"
                      ,Int);
  puVar9 = (undefined4 *)
           dEvent_manager_c::getMySubstanceP
                     (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mEvtStaffId,
                      "ShapeAngle",Int);
  if (pvVar8 == (void *)0x0) {
    this->mbNoTurn = 0;
  }
  else {
    this->mbNoTurn = 1;
  }
  if (pvVar7 == (void *)0x0) {
    this->mbAttention = 0;
  }
  else {
    this->mbAttention = 1;
  }
  fVar1 = d_npc::0_0;
  if (pfVar6 == (float *)0x0) {
    (this->mOffsetPos).x = d_npc::0_0;
    (this->mOffsetPos).y = fVar1;
    (this->mOffsetPos).z = fVar1;
  }
  else {
    (this->mOffsetPos).x = *pfVar6;
    (this->mOffsetPos).y = pfVar6[1];
    (this->mOffsetPos).z = pfVar6[2];
  }
  if (piVar3 == (int *)0x0) {
    this->mSetID = 0;
  }
  else {
    this->mSetID = *piVar3;
  }
  if (pfVar4 == (float *)0x0) {
    this->mSpeed = d_npc::2_0;
  }
  else {
    this->mSpeed = *pfVar4;
  }
  if (pfVar5 == (float *)0x0) {
    this->pDelDistance = d_npc::0_0;
  }
  else {
    this->pDelDistance = *pfVar5;
  }
  if (puVar9 == (undefined4 *)0x0) {
    this->mAddAngle = 0;
  }
  else {
    this->mAddAngle = (short)*puVar9;
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x8021d9c0) */
/* __thiscall dNpc_EventCut_c::cutMoveToActorProc(void) */

void __thiscall dNpc_EventCut_c::cutMoveToActorProc(dNpc_EventCut_c *this)

{
  int iVar1;
  uint uVar2;
  fopAc_ac_c *pfVar3;
  undefined4 uVar4;
  double dVar5;
  undefined8 in_f31;
  double dVar6;
  float fVar7;
  cXyz local_54;
  cXyz local_48;
  cXyz local_3c;
  cXyz local_30;
  undefined auStack8 [8];
  
  fVar7 = d_npc::0_0;
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (this->mSetID == 0) {
    if ((this->mpActorName == (char *)0x0) ||
       (iVar1 = MSL_C.PPCEABI.bare.H::strcmp(this->mpActorName,"Player"), fVar7 = d_npc::0_0,
       iVar1 == 0)) {
      this->mpTargetActor = (fopAc_ac_c *)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor;
    }
    else {
      (this->mTargetActorPos).x = d_npc::0_0;
      (this->mTargetActorPos).y = fVar7;
      (this->mTargetActorPos).z = fVar7;
      f_op_actor_iter::fopAcIt_Judge(findActorCallBack,this);
    }
  }
  else {
    (this->mTargetActorPos).x = d_npc::0_0;
    (this->mTargetActorPos).y = fVar7;
    (this->mTargetActorPos).z = fVar7;
    f_op_actor_iter::fopAcIt_Judge(findActorCallBack,this);
  }
  if (this->mpTargetActor == (fopAc_ac_c *)0x0) {
    dEvent_manager_c::cutEnd(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mEvtStaffId);
  }
  ::cXyz::operator__(&local_3c,&(this->mpTargetActor->mCurrent).mPos,&this->mOffsetPos);
  local_30.x = local_3c.x;
  local_30.y = local_3c.y;
  local_30.z = local_3c.z;
  uVar2 = f_op_actor_mng::fopAcM_searchActorAngleY(this->mpActor,this->mpTargetActor);
  if (this->mAddAngle != 0) {
    uVar2 = SEXT24((short)((this->mpTargetActor->mCollisionRot).y + this->mAddAngle));
  }
  iVar1 = (int)(uVar2 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f);
  local_30.x = local_30.x - this->pDelDistance * JKernel::JMath::jmaSinTable[iVar1];
  local_30.z = local_30.z - this->pDelDistance * JKernel::JMath::jmaCosTable[iVar1];
  if (d_npc::0_0 == this->mSpeed) {
    pfVar3 = this->mpActor;
    (pfVar3->mCurrent).mPos.x = local_30.x;
    (pfVar3->mCurrent).mPos.y = local_30.y;
    (pfVar3->mCurrent).mPos.z = local_30.z;
    dEvent_manager_c::cutEnd(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mEvtStaffId);
  }
  ::cXyz::operator__(&local_48,&local_30,&(this->mpActor->mCurrent).mPos);
  local_54.x = local_48.x;
  local_54.y = d_npc::0_0;
  local_54.z = local_48.z;
  fVar7 = mtx::PSVECSquareMag(&local_54);
  dVar6 = (double)fVar7;
  if ((double)d_npc::0_0 < dVar6) {
    dVar5 = 1.0 / SQRT(dVar6);
    dVar5 = d_npc::_4096 * dVar5 * (d_npc::_4097 - dVar6 * dVar5 * dVar5);
    dVar5 = d_npc::_4096 * dVar5 * (d_npc::_4097 - dVar6 * dVar5 * dVar5);
    dVar6 = (double)(float)(dVar6 * d_npc::_4096 * dVar5 * (d_npc::_4097 - dVar6 * dVar5 * dVar5));
  }
  SComponent::cLib_addCalc2((float *)&this->mpActor->mCurrent,local_30.x,d_npc::_4903,this->mSpeed);
  SComponent::cLib_addCalc2(&(this->mpActor->mCurrent).mPos.z,local_30.z,d_npc::_4903,this->mSpeed);
  if (dVar6 < (double)d_npc::_4904) {
    this->mSpeed = d_npc::0_0;
    dEvent_manager_c::cutEnd(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mEvtStaffId);
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return;
}


namespace dNpc_EventCut_c {

/* WARNING: Removing unreachable block (ram,0x8021dc5c) */
/* __thiscall findActorCallBack(fopAc_ac_c *,
                                                 void *) */

dNpc_EventCut_c * findActorCallBack(fopAc_ac_c *pActor,dNpc_EventCut_c *pData)

{
  dStage__ObjectNameTable *pdVar1;
  undefined4 uVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  undefined8 in_f31;
  float fVar6;
  cXyz cStack60;
  cXyz acStack48 [2];
  undefined auStack8 [8];
  
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (pData == (dNpc_EventCut_c *)0x0) {
    pActor = (fopAc_ac_c *)0x0;
  }
  else {
    if ((pData->mSetID == 0) || ((uint)(ushort)pActor->mSetID != pData->mSetID)) {
      if (pData->mpActorName == (char *)0x0) {
        pActor = (fopAc_ac_c *)0x0;
      }
      else {
        pdVar1 = d_stage::dStage_searchName(pData->mpActorName);
        if (pdVar1 == (dStage__ObjectNameTable *)0x0) {
          pActor = (fopAc_ac_c *)0x0;
        }
        else {
          if ((pdVar1->mProcName == (pActor->parent).parent.mBsTypeId) &&
             (pdVar1->mSubtype == pActor->mSubtype)) {
            fVar6 = mtx::PSVECSquareMag(&pData->mTargetActorPos);
            dVar5 = (double)fVar6;
            if ((double)d_npc::0_0 < dVar5) {
              dVar3 = 1.0 / SQRT(dVar5);
              dVar3 = d_npc::_4096 * dVar3 * (d_npc::_4097 - dVar5 * dVar3 * dVar3);
              dVar3 = d_npc::_4096 * dVar3 * (d_npc::_4097 - dVar5 * dVar3 * dVar3);
              dVar5 = (double)(float)(dVar5 * d_npc::_4096 * dVar3 *
                                              (d_npc::_4097 - dVar5 * dVar3 * dVar3));
            }
            if ((double)d_npc::0_0 == dVar5) {
              (pData->mTargetActorPos).x = (pActor->mCurrent).mPos.x;
              (pData->mTargetActorPos).y = (pActor->mCurrent).mPos.y;
              (pData->mTargetActorPos).z = (pActor->mCurrent).mPos.z;
              pData->mpTargetActor = pActor;
            }
            else {
              ::cXyz::operator__(acStack48,&pData->mTargetActorPos,&(pData->mpActor->mCurrent).mPos)
              ;
              fVar6 = mtx::PSVECSquareMag(acStack48);
              dVar5 = (double)fVar6;
              if ((double)d_npc::0_0 < dVar5) {
                dVar3 = 1.0 / SQRT(dVar5);
                dVar3 = d_npc::_4096 * dVar3 * (d_npc::_4097 - dVar5 * dVar3 * dVar3);
                dVar3 = d_npc::_4096 * dVar3 * (d_npc::_4097 - dVar5 * dVar3 * dVar3);
                dVar5 = (double)(float)(dVar5 * d_npc::_4096 * dVar3 *
                                                (d_npc::_4097 - dVar5 * dVar3 * dVar3));
              }
              ::cXyz::operator__(&cStack60,&(pActor->mCurrent).mPos,&(pData->mpActor->mCurrent).mPos
                                );
              fVar6 = mtx::PSVECSquareMag(&cStack60);
              dVar3 = (double)fVar6;
              if ((double)d_npc::0_0 < dVar3) {
                dVar4 = 1.0 / SQRT(dVar3);
                dVar4 = d_npc::_4096 * dVar4 * (d_npc::_4097 - dVar3 * dVar4 * dVar4);
                dVar4 = d_npc::_4096 * dVar4 * (d_npc::_4097 - dVar3 * dVar4 * dVar4);
                dVar3 = (double)(float)(dVar3 * d_npc::_4096 * dVar4 *
                                                (d_npc::_4097 - dVar3 * dVar4 * dVar4));
              }
              if (dVar3 < dVar5) {
                (pData->mTargetActorPos).x = (pActor->mCurrent).mPos.x;
                (pData->mTargetActorPos).y = (pActor->mCurrent).mPos.y;
                (pData->mTargetActorPos).z = (pActor->mCurrent).mPos.z;
                pData->mpTargetActor = pActor;
              }
            }
          }
          pActor = (fopAc_ac_c *)0x0;
        }
      }
    }
    else {
      (pData->mTargetActorPos).x = (pActor->mCurrent).mPos.x;
      (pData->mTargetActorPos).y = (pActor->mCurrent).mPos.y;
      (pData->mTargetActorPos).z = (pActor->mCurrent).mPos.z;
      pData->mpTargetActor = pActor;
    }
  }
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  return (dNpc_EventCut_c *)pActor;
}

}

/* __thiscall dNpc_EventCut_c::cutTurnToPosStart(void) */

void __thiscall dNpc_EventCut_c::cutTurnToPosStart(dNpc_EventCut_c *this)

{
  float fVar1;
  float *pfVar2;
  int *pTurnType;
  int *pTimer;
  short *pTurnSpeed;
  int *pNoTurn;
  int *pAddAngle;
  
  pfVar2 = (float *)dEvent_manager_c::getMySubstanceP
                              (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mEvtStaffId
                               ,"Pos",Xyz);
  fVar1 = d_npc::0_0;
  if (pfVar2 == (float *)0x0) {
    (this->mPos).x = d_npc::0_0;
    (this->mPos).y = fVar1;
    (this->mPos).z = fVar1;
  }
  else {
    (this->mPos).x = *pfVar2;
    (this->mPos).y = pfVar2[1];
    (this->mPos).z = pfVar2[2];
  }
  pTurnType = (int *)dEvent_manager_c::getMySubstanceP
                               (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,
                                this->mEvtStaffId,"TurnType",Int);
  if (pTurnType == (int *)0x0) {
    this[1].mpEvtStaffName = (char *)0x1;
  }
  else {
    this[1].mpEvtStaffName = (char *)*pTurnType;
  }
  pTimer = (int *)dEvent_manager_c::getMySubstanceP
                            (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mEvtStaffId,
                             "Timer",Int);
  if (pTimer == (int *)0x0) {
    this->mTimer = 1;
  }
  else {
    this->mTimer = (int)(short)*pTimer;
  }
  pTurnSpeed = (short *)dEvent_manager_c::getMySubstanceP
                                  (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,
                                   this->mEvtStaffId,"TurnSpeed",Int);
  if (pTurnSpeed == (short *)0x0) {
    this->mTurnSpeed = 0;
  }
  else {
    this->mTurnSpeed = (short)*(undefined4 *)pTurnSpeed;
  }
  pNoTurn = (int *)dEvent_manager_c::getMySubstanceP
                             (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mEvtStaffId,
                              "NoTurn",Int);
  if (pNoTurn == (int *)0x0) {
    this->mbNoTurn = 0;
  }
  else {
    this->mbNoTurn = 1;
  }
  pAddAngle = (int *)dEvent_manager_c::getMySubstanceP
                               (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,
                                this->mEvtStaffId,"AddAngle",Int);
  if (pAddAngle == (int *)0x0) {
    this->mAddAngle = 0;
  }
  else {
    this->mAddAngle = (short)*pAddAngle;
  }
  this->field_0x44 = 0;
  return;
}


/* __thiscall dNpc_EventCut_c::cutTurnToPosProc(void) */

void __thiscall dNpc_EventCut_c::cutTurnToPosProc(dNpc_EventCut_c *this)

{
  char *pcVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  double local_18;
  
  sVar2 = SComponent::cLib_targetAngleY(&(this->mpActor->mCurrent).mPos,&this->mPos);
  this->mbAttention = 1;
  iVar4 = this[1].mEvtStaffId;
  if (iVar4 == 0) goto LAB_8021deb0;
  pcVar1 = this[1].mpEvtStaffName;
  if (pcVar1 == (char *)0x1) {
LAB_8021de90:
    *(undefined *)(this[1].mEvtStaffId + 0xc) = 0;
  }
  else {
    if ((int)pcVar1 < 1) {
      if (-1 < (int)pcVar1) {
        *(undefined *)(iVar4 + 0xc) = 1;
        goto LAB_8021deb0;
      }
    }
    else {
      if ((int)pcVar1 < 3) {
        *(undefined *)(iVar4 + 10) = 1;
        goto LAB_8021de90;
      }
    }
    *(undefined *)(iVar4 + 0xc) = 0;
  }
LAB_8021deb0:
  uVar3 = (int)sVar2 - (int)(this->mpActor->mCurrent).mRot.y ^ 0x80000000;
  local_18 = (double)CONCAT44(0x43300000,uVar3);
  if (((float)((double)CONCAT44(0x43300000,(int)this->field_0x44 ^ 0x80000000) - d_npc::_4768) ==
       ABS((float)(local_18 - d_npc::_4768))) &&
     (ABS((float)((double)CONCAT44(0x43300000,uVar3) - d_npc::_4768)) < d_npc::_4766)) {
    d_a_nh::cLib_calcTimer(&this->mTimer);
  }
  if (this->mTimer == 0) {
    this->mTurnSpeed = 0;
    dEvent_manager_c::cutEnd(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mEvtStaffId);
  }
  this->field_0x44 =
       (short)(int)ABS((float)((double)CONCAT44(0x43300000,
                                                (int)sVar2 - (int)(this->mpActor->mCurrent).mRot.y ^
                                                0x80000000) - d_npc::_4768));
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall dNpc_EventCut_c::cutMoveToPosStart(void) */

void __thiscall dNpc_EventCut_c::cutMoveToPosStart(dNpc_EventCut_c *this)

{
  float fVar1;
  float *pPos;
  float *pfVar2;
  float *pfVar3;
  void *pvVar4;
  void *pvVar5;
  undefined4 *puVar6;
  
  pPos = (float *)dEvent_manager_c::getMySubstanceP
                            (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mEvtStaffId,
                             "Pos",Xyz);
  pfVar2 = (float *)dEvent_manager_c::getMySubstanceP
                              (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mEvtStaffId
                               ,"Speed",Float);
  pfVar3 = (float *)dEvent_manager_c::getMySubstanceP
                              (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mEvtStaffId
                               ,"DelDistance",Float);
  pvVar4 = dEvent_manager_c::getMySubstanceP
                     (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mEvtStaffId,
                      "Attention",Int);
  pvVar5 = dEvent_manager_c::getMySubstanceP
                     (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mEvtStaffId,"NoTurn"
                      ,Int);
  puVar6 = (undefined4 *)
           dEvent_manager_c::getMySubstanceP
                     (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mEvtStaffId,
                      "AddAngle",Int);
  if (pvVar5 == (void *)0x0) {
    this->mbNoTurn = 0;
  }
  else {
    this->mbNoTurn = 1;
  }
  fVar1 = d_npc::0_0;
  if (pPos == (float *)0x0) {
    (this->mPos).x = d_npc::0_0;
    (this->mPos).y = fVar1;
    (this->mPos).z = fVar1;
  }
  else {
    (this->mPos).x = *pPos;
    (this->mPos).y = pPos[1];
    (this->mPos).z = pPos[2];
  }
  if (pvVar4 == (void *)0x0) {
    this->mbAttention = 0;
  }
  else {
    this->mbAttention = 1;
  }
  if (pfVar2 == (float *)0x0) {
    this->mSpeed = d_npc::2_0;
  }
  else {
    this->mSpeed = *pfVar2;
  }
  if (pfVar3 == (float *)0x0) {
    this->pDelDistance = d_npc::0_0;
  }
  else {
    this->pDelDistance = *pfVar3;
  }
  if (puVar6 == (undefined4 *)0x0) {
    this->mAddAngle = 0;
  }
  else {
    this->mAddAngle = (short)*puVar6;
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x8021e31c) */
/* __thiscall dNpc_EventCut_c::cutMoveToPosProc(void) */

void __thiscall dNpc_EventCut_c::cutMoveToPosProc(dNpc_EventCut_c *this)

{
  int iVar1;
  short sVar3;
  fopAc_ac_c *pfVar2;
  undefined4 uVar4;
  double dVar5;
  undefined8 in_f31;
  double dVar6;
  float fVar7;
  cXyz local_44;
  cXyz local_38;
  cXyz local_2c [2];
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  sVar3 = SComponent::cLib_targetAngleY(&(this->mpActor->mCurrent).mPos,&this->mPos);
  local_2c[0].y = (this->mPos).y;
  iVar1 = (int)((int)sVar3 & 0xffffU) >> (JKernel::JMath::jmaSinShift & 0x3f);
  local_2c[0].x = (this->mPos).x - this->pDelDistance * JKernel::JMath::jmaSinTable[iVar1];
  local_2c[0].z = (this->mPos).z - this->pDelDistance * JKernel::JMath::jmaCosTable[iVar1];
  if (d_npc::0_0 == this->mSpeed) {
    pfVar2 = this->mpActor;
    (pfVar2->mCurrent).mPos.x = local_2c[0].x;
    (pfVar2->mCurrent).mPos.y = local_2c[0].y;
    (pfVar2->mCurrent).mPos.z = local_2c[0].z;
    dEvent_manager_c::cutEnd(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mEvtStaffId);
  }
  ::cXyz::operator__(&local_38,local_2c,&(this->mpActor->mCurrent).mPos);
  local_44.x = local_38.x;
  local_44.y = d_npc::0_0;
  local_44.z = local_38.z;
  fVar7 = mtx::PSVECSquareMag(&local_44);
  dVar6 = (double)fVar7;
  if ((double)d_npc::0_0 < dVar6) {
    dVar5 = 1.0 / SQRT(dVar6);
    dVar5 = d_npc::_4096 * dVar5 * (d_npc::_4097 - dVar6 * dVar5 * dVar5);
    dVar5 = d_npc::_4096 * dVar5 * (d_npc::_4097 - dVar6 * dVar5 * dVar5);
    dVar6 = (double)(float)(dVar6 * d_npc::_4096 * dVar5 * (d_npc::_4097 - dVar6 * dVar5 * dVar5));
  }
  SComponent::cLib_addCalc2
            ((float *)&this->mpActor->mCurrent,local_2c[0].x,d_npc::_4903,this->mSpeed);
  SComponent::cLib_addCalc2
            (&(this->mpActor->mCurrent).mPos.z,local_2c[0].z,d_npc::_4903,this->mSpeed);
  if (dVar6 < (double)d_npc::_4904) {
    this->mSpeed = d_npc::0_0;
    dEvent_manager_c::cutEnd(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mEvtStaffId);
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dNpc_EventCut_c::cutTalkMsgStart(void) */

void __thiscall dNpc_EventCut_c::cutTalkMsgStart(dNpc_EventCut_c *this)

{
  void *pvVar1;
  int *pMsgNum;
  int *pEndMsg;
  
  if (this->mpTalkActor != (fopNpc_npc_c *)0x0) {
    pvVar1 = dEvent_manager_c::getMySubstanceP
                       (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mEvtStaffId,
                        "Attention",Int);
    if (pvVar1 == (void *)0x0) {
      this->mbAttention = 0;
    }
    else {
      this->mbAttention = 1;
    }
    pMsgNum = (int *)dEvent_manager_c::getMySubstanceP
                               (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,
                                this->mEvtStaffId,"msg_num",Int);
    pEndMsg = (int *)dEvent_manager_c::getMySubstanceP
                               (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,
                                this->mEvtStaffId,"end_msg",Int);
    if (pMsgNum == (int *)0x0) {
      this->mpTalkActor->mCurrMsgID = 0;
    }
    else {
      this->mpTalkActor->mCurrMsgID = *pMsgNum;
    }
    if (pEndMsg == (int *)0x0) {
      this->mpTalkActor->mEndMsgID = 0xffffffff;
    }
    else {
      this->mpTalkActor->mEndMsgID = *pEndMsg;
    }
    this->field_0x52 = 1;
  }
  return;
}


/* __thiscall dNpc_EventCut_c::cutContinueTalkStart(void) */

void __thiscall dNpc_EventCut_c::cutContinueTalkStart(dNpc_EventCut_c *this)

{
  ulong *puVar1;
  
  if (this->mpTalkActor != (fopNpc_npc_c *)0x0) {
    puVar1 = (ulong *)dEvent_manager_c::getMySubstanceP
                                (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,
                                 this->mEvtStaffId,"end_num",Int);
    if (puVar1 == (ulong *)0x0) {
      this->mpTalkActor->mEndMsgID = 0xffffffff;
    }
    else {
      this->mpTalkActor->mEndMsgID = *puVar1;
    }
  }
  return;
}


/* __thiscall dNpc_EventCut_c::cutTalkMsgProc(void) */

void __thiscall dNpc_EventCut_c::cutTalkMsgProc(dNpc_EventCut_c *this)

{
  short sVar1;
  fopNpc_npc_c *pfVar2;
  
  if ((this->mpTalkActor == (fopNpc_npc_c *)0x0) || (this->field_0x52 == 0)) {
    dEvent_manager_c::cutEnd(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mEvtStaffId);
  }
  else {
    sVar1 = ::fopNpc_npc_c::talk(this->mpTalkActor,0);
    if (sVar1 == 0x12) {
      this->field_0x52 = 0;
      dEvent_manager_c::cutEnd
                (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mEvtStaffId);
    }
    else {
      if (((sVar1 == 2) || (sVar1 == 6)) &&
         (pfVar2 = this->mpTalkActor, pfVar2->mEndMsgID == pfVar2->mCurrMsgID)) {
        pfVar2->mEndMsgID = 0xffffffff;
        dEvent_manager_c::cutEnd
                  (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,this->mEvtStaffId);
      }
    }
  }
  return;
}

