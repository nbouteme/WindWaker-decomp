#include <d_magma.h>
#include <gx/GXTransform.h>
#include <gx/GXAttr.h>
#include <gx/GXTexture.h>
#include <gx/GXDisplayList.h>
#include <mtx/vec.h>
#include <m_Do_audio.h>
#include <mtx/mtx.h>
#include <d_path.h>
#include <SComponent/c_math.h>
#include <m_Do_mtx.h>
#include <gx/GXTev.h>
#include <d_magma.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <JKernel/JKRHeap.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <d_resorce.h>
#include <m_Do_lib.h>
#include <J3DGraphBase/J3DSys.h>
#include <gx/GXBump.h>
#include <d_kankyo.h>
#include <J3DGraphBase/J3DDrawBuffer.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <dMagma_floor_c.h>
#include <dMagma_ballPath_c.h>
#include <dMagma_ball_c.h>
#include <dMagma_room_c.h>
#include <dMagma_packet_c.h>


namespace d_magma {
struct MTX34 l_kuroOrthoMtx;
struct MTX34 l_colOrthoMtx;
}
GXTexObj dMagma_packet_c;
struct MTX34 dMagma_packet_c;
GXTexObj dMagma_packet_c;
struct MTX34 dMagma_packet_c;
struct MTX34 dMagma_packet_c;

namespace dMagma_ball_c {

/* __thiscall draw(void) */

void draw(dMagma_ballPath_c *this)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  gx::GXLoadTexMtxImm(&this->mTexMtx0,GX_TEXMTX2,0);
  gx::GXSetTexCoordGen2(GX_TEXCOORD0,GX_TG_MTX3x4,GX_TG_POS,GX_TEXMTX2,false,GX_PTTEXMTX0);
  uVar1 = gx::GXGetTexObjHeight(&dMagma_packet_c::mKuroTexObj);
  uVar2 = gx::GXGetTexObjWidth(&dMagma_packet_c::mKuroTexObj);
  gx::GXSetTexCoordScaleManually(0,1,uVar2,uVar1);
  gx::GXSetTexCoordBias(0,0,0);
  gx::GXSetTexCoordGen2(GX_TEXCOORD1,GX_TG_MTX3x4,GX_TG_POS,GX_TEXMTX2,false,GX_PTTEXMTX1);
  uVar1 = gx::GXGetTexObjHeight(&dMagma_packet_c::mColTexObj);
  uVar2 = gx::GXGetTexObjWidth(&dMagma_packet_c::mColTexObj);
  gx::GXSetTexCoordScaleManually(1,1,uVar2,uVar1);
  gx::GXSetTexCoordBias(1,0,0);
  gx::GXLoadPosMtxImm(&this->mPosMtx,0);
  gx::GXCallDisplayList(&d_magma::l_YballDL,0x60);
  return;
}


/* __thiscall rangeCheck(cXyz &,
                                        float *) */

undefined4 rangeCheck(dMagma_ballPath_c *this,cXyz *pPos,float *param_3)

{
  undefined4 uVar1;
  double dVar2;
  double dVar3;
  float fVar4;
  cXyz thisPosXZ;
  cXyz posXZ;
  float rad1;
  
  thisPosXZ.z = (this->mPos).z;
  thisPosXZ.x = (this->mPos).x;
  thisPosXZ.y = d_magma::_4010;
  posXZ.z = pPos->z;
  posXZ.x = pPos->x;
  posXZ.y = d_magma::_4010;
  fVar4 = mtx::PSVECSquareDistance(&thisPosXZ,&posXZ);
  rad1 = d_magma::_4011 * this->mScale;
  if (rad1 * rad1 <= fVar4) {
    uVar1 = 0;
  }
  else {
    rad1 = d_magma::_4012 * this->mScale;
    dVar3 = (double)(rad1 * rad1 - fVar4);
    if ((double)d_magma::_4010 < dVar3) {
      dVar2 = 1.0 / SQRT(dVar3);
      dVar2 = d_magma::_4013 * dVar2 * (d_magma::_4014 - dVar3 * dVar2 * dVar2);
      dVar2 = d_magma::_4013 * dVar2 * (d_magma::_4014 - dVar3 * dVar2 * dVar2);
      dVar3 = (double)(float)(dVar3 * d_magma::_4013 * dVar2 *
                                      (d_magma::_4014 - dVar3 * dVar2 * dVar2));
    }
    *param_3 = (float)((double)((this->mPos).y - (rad1 - d_magma::_4015)) + dVar3);
    uVar1 = 1;
  }
  return uVar1;
}

}

/* __thiscall dMagma_ballPath_c::calc(float,
                                      unsigned char,
                                      int) */

void __thiscall
dMagma_ballPath_c::calc(dMagma_ballPath_c *this,float param_1,uchar pathIndex,int roomNo)

{
  char cVar1;
  undefined3 in_register_00000010;
  
  if (this->mWave < 0) {
    (**(code **)(this->vtbl + 0x14))((double)param_1,this,CONCAT31(in_register_00000010,pathIndex));
    this->mWaveTimer = 0;
    this->mWave = 0;
  }
  cVar1 = m_Do_audio::cLib_calcTimer(&this->mWaveTimer);
  if (cVar1 == '\0') {
    this->mWave = this->mWave + 200;
    (this->mPos).y =
         this->mBaseY +
         d_magma::_4029 *
         (JKernel::JMath::jmaSinTable
          [(int)((int)this->mWave & 0xffffU) >> (JKernel::JMath::jmaSinShift & 0x3f)] -
         d_magma::_4030);
  }
  return;
}


/* __thiscall dMagma_ballPath_c::update(void) */

void __thiscall dMagma_ballPath_c::update(dMagma_ballPath_c *this)

{
  (this->mTexMtx0).m[1][3] = (this->mPos).y;
  mtx::PSMTXConcat(&J3DGraphBase::j3dSys.mCurViewMtx,&this->mTexMtx0,&this->mPosMtx);
  return;
}


/* WARNING: Removing unreachable block (ram,0x80075a4c) */
/* __thiscall dMagma_ballPath_c::setup(float,
                                       unsigned char,
                                       int) */

void __thiscall
dMagma_ballPath_c::setup(dMagma_ballPath_c *this,float yOffset,uchar pathIndex,int roomNo)

{
  dPath *pdVar1;
  dPath__Point *pdVar2;
  undefined4 uVar3;
  double dVar4;
  undefined8 in_f31;
  float fVar5;
  undefined auStack8 [8];
  
  dVar4 = (double)yOffset;
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  pdVar1 = d_path::dPath_GetRoomPath((uint)pathIndex,roomNo);
  fVar5 = SComponent::cM_rndF((float)((double)CONCAT44(0x43300000,pdVar1->mNum - 1 ^ 0x80000000) -
                                     d_magma::_4057));
  pdVar2 = pdVar1->mpPnt + (int)fVar5;
  fVar5 = SComponent::cM_rndFX
                    (d_magma::_4029 *
                     (float)((double)CONCAT44(0x43300000,(uint)pdVar2->mArg3) - d_magma::_4060));
  (this->mPos).x = (pdVar2->mPos).x + fVar5;
  fVar5 = SComponent::cM_rndFX
                    (d_magma::_4029 *
                     (float)((double)CONCAT44(0x43300000,(uint)pdVar2->mArg3) - d_magma::_4060));
  (this->mPos).z = (pdVar2->mPos).z + fVar5;
  fVar5 = SComponent::cM_rndF(d_magma::_4030);
  this->mScale = d_magma::_4030 + fVar5;
  fVar5 = SComponent::cM_rndF(d_magma::_4053);
  this->mBaseY = (float)(dVar4 - (double)fVar5);
  fVar5 = SComponent::cM_rndF(d_magma::_4055);
  this->mWave = (short)(int)(d_magma::_4054 * fVar5);
  (this->mPos).y =
       this->mBaseY +
       d_magma::_4029 *
       (JKernel::JMath::jmaSinTable
        [(int)((int)this->mWave & 0xffffU) >> (JKernel::JMath::jmaSinShift & 0x3f)] - d_magma::_4030
       );
  this->mWaveTimer = 0;
  mtx::PSMTXTrans((double)(this->mPos).x,(double)(this->mPos).y,(double)(this->mPos).z,
                  &mDoMtx_stack_c::now);
  mDoMtx_stack_c::scaleM(this->mScale,d_magma::_4030,this->mScale);
  mtx::PSMTXCopy(&mDoMtx_stack_c::now,&this->mTexMtx0);
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall dMagma_floor_c::draw(void) */

void __thiscall dMagma_floor_c::draw(dMagma_floor_c *this)

{
  undefined4 uVar1;
  undefined4 uVar2;
  dMagma_ball_c **ppdVar3;
  int iVar4;
  
  gx::GXSetArray(GX_VA_POS,&d_magma::l_YfloorPos,0xc);
  gx::GXLoadTexMtxImm(&this->mTexMtx0,GX_TEXMTX2,0);
  gx::GXLoadTexMtxImm(&dMagma_packet_c::mKuroMtx,0x40,0);
  gx::GXSetTexCoordGen2(GX_TEXCOORD0,GX_TG_MTX3x4,GX_TG_POS,GX_TEXMTX2,false,GX_PTTEXMTX0);
  uVar1 = gx::GXGetTexObjHeight(&dMagma_packet_c::mKuroTexObj);
  uVar2 = gx::GXGetTexObjWidth(&dMagma_packet_c::mKuroTexObj);
  gx::GXSetTexCoordScaleManually(0,1,uVar2,uVar1);
  gx::GXSetTexCoordBias(0,0,0);
  gx::GXCallDisplayList(&d_magma::l_YfloorMatDL,0x40);
  gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD0,GX_TEXMAP0,GX_COLOR_NULL);
  gx::GXLoadPosMtxImm(&this->mPosMtx,0);
  gx::GXCallDisplayList(&d_magma::l_YfloorDL,0x20);
  gx::GXSetArray(GX_VA_POS,&d_magma::l_YballPos,0xc);
  gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD0,GX_TEXMAP0,GX_COLOR_NULL);
  gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_TEXA,GX_CC_HALF,GX_CC_ONE,GX_CC_ZERO);
  gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_COMP_RGB8_GT,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO);
  gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetTevOrder(GX_TEVSTAGE1,GX_TEXCOORD1,GX_TEXMAP1,GX_COLOR_NULL);
  gx::GXSetTevColorIn(GX_TEVSTAGE1,GX_CC_TEXC,GX_CC_C1,GX_CC_CPREV,GX_CC_ZERO);
  gx::GXSetTevColorOp(GX_TEVSTAGE1,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetTevAlphaIn(GX_TEVSTAGE1,GX_CA_APREV,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO);
  gx::GXSetTevAlphaOp(GX_TEVSTAGE1,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXCallDisplayList(&d_magma::l_YballMatDL,0x40);
  gx::GXLoadTexMtxImm(&this->mBallPostMtx0,0x43,0);
  ppdVar3 = this->mpBalls;
  for (iVar4 = 0; iVar4 < (int)(uint)this->mBallNum; iVar4 = iVar4 + 1) {
    dMagma_ball_c::draw((dMagma_ballPath_c *)*ppdVar3);
    ppdVar3 = ppdVar3 + 1;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dMagma_floor_c::calc(int) */

void __thiscall dMagma_floor_c::calc(dMagma_floor_c *this,int roomNo)

{
  int iVar1;
  int **ppiVar2;
  
  mtx::PSMTXScale((double)d_magma::_4030,(double)d_magma::_4092,(double)d_magma::_4030,
                  &mDoMtx_stack_c::now);
  iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                    (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"M_DragB");
  if ((iVar1 == 0) ||
     (iVar1 = MSL_C.PPCEABI.bare.H::strcmp
                        (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"Xboss0"),
     iVar1 == 0)) {
    mDoMtx_stack_c::transM(d_magma::_4010,-(d_magma::_4053 + (this->mBallPos).y),d_magma::_4010);
  }
  else {
    mDoMtx_stack_c::transM(d_magma::_4010,-(d_magma::_4093 + (this->mBallPos).y),d_magma::_4010);
  }
  mtx::PSMTXConcat(&d_magma::l_colOrthoMtx,&mDoMtx_stack_c::now,&this->mBallPostMtx0);
  ppiVar2 = (int **)this->mpBalls;
  for (iVar1 = 0; iVar1 < (int)(uint)this->mBallNum; iVar1 = iVar1 + 1) {
    (**(code **)(**ppiVar2 + 0xc))((double)(this->mBallPos).y,*ppiVar2,this->mPathNo,roomNo);
    ppiVar2 = ppiVar2 + 1;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dMagma_floor_c::update(void) */

void __thiscall dMagma_floor_c::update(dMagma_floor_c *this)

{
  int iVar1;
  int **ppiVar2;
  
  mtx::PSMTXConcat(&J3DGraphBase::j3dSys.mCurViewMtx,&this->mTexMtx0,&this->mPosMtx);
  ppiVar2 = (int **)this->mpBalls;
  for (iVar1 = 0; iVar1 < (int)(uint)this->mBallNum; iVar1 = iVar1 + 1) {
    (**(code **)(**ppiVar2 + 0x10))();
    ppiVar2 = ppiVar2 + 1;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall dMagma_floor_c::create(cXyz &,
                                     cXyz &,
                                     short,
                                     unsigned char,
                                     int) */

dMagma_ball_c ** __thiscall
dMagma_floor_c::create
          (dMagma_floor_c *this,cXyz *param_1,cXyz *param_2,short param_3,uchar param_4,int param_5)

{
  float fVar1;
  float fVar2;
  dMagma_ball_c **ppdVar3;
  int *piVar4;
  undefined **ppuVar5;
  byte bVar6;
  int **ppiVar7;
  
  fVar1 = param_1->z;
  fVar2 = d_magma::_4187 + param_1->y;
  (this->mBallPos).x = param_1->x;
  (this->mBallPos).y = fVar2;
  (this->mBallPos).z = fVar1;
  ppdVar3 = (dMagma_ball_c **)JKernel::operator_new__((uint)param_4 << 2);
  this->mpBalls = ppdVar3;
  if (this->mpBalls == (dMagma_ball_c **)0x0) {
    ppdVar3 = (dMagma_ball_c **)0x0;
  }
  else {
    this->mBallNum = param_4;
    if (param_3 < 0) {
      ppiVar7 = (int **)this->mpBalls;
      for (bVar6 = 0; bVar6 < this->mBallNum; bVar6 = bVar6 + 1) {
        piVar4 = (int *)JKernel::operator_new(0x80);
        if (piVar4 != (int *)0x0) {
          *piVar4 = (int)&dMagma_ball_c::__vt;
          *piVar4 = (int)&dMagma_ballBoss_c::__vt;
        }
        *ppiVar7 = piVar4;
        piVar4 = *ppiVar7;
        if (piVar4 == (int *)0x0) {
          this->mBallNum = bVar6;
        }
        else {
          (**(code **)(*piVar4 + 0x14))((double)(this->mBallPos).y,piVar4,bVar6,param_5);
          ppiVar7 = ppiVar7 + 1;
        }
      }
    }
    else {
      ppiVar7 = (int **)this->mpBalls;
      for (bVar6 = 0; bVar6 < this->mBallNum; bVar6 = bVar6 + 1) {
        ppuVar5 = (undefined **)JKernel::operator_new(0x80);
        if (ppuVar5 != (undefined **)0x0) {
          *ppuVar5 = &dMagma_ball_c::__vt;
          *ppuVar5 = (undefined *)&dMagma_ballPath_c::__vt;
        }
        *ppiVar7 = (int *)ppuVar5;
        piVar4 = *ppiVar7;
        if (piVar4 == (int *)0x0) {
          this->mBallNum = bVar6;
        }
        else {
          (**(code **)(*piVar4 + 0x14))((double)(this->mBallPos).y,piVar4,param_3 & 0xff,param_5);
          ppiVar7 = ppiVar7 + 1;
        }
      }
    }
    this->field_0x14 = param_2->x;
    this->field_0x18 = param_2->z;
    this->mPathNo = (byte)param_3;
    mtx::PSMTXTrans((double)(this->mBallPos).x,(double)(this->mBallPos).y,(double)(this->mBallPos).z
                    ,&mDoMtx_stack_c::now);
    mDoMtx_stack_c::scaleM(this->field_0x14,d_magma::_4030,this->field_0x18);
    mtx::PSMTXCopy(&mDoMtx_stack_c::now,&this->mTexMtx0);
    update(this);
    ppdVar3 = this->mpBalls;
  }
  return ppdVar3;
}


/* __thiscall dMagma_ball_c::~dMagma_ball_c(void) */

void __thiscall dMagma_ball_c::_dMagma_ball_c(dMagma_ball_c *this)

{
  short in_r4;
  
  if ((this != (dMagma_ball_c *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dMagma_floor_c::remove(void) */

int __thiscall dMagma_floor_c::remove(dMagma_floor_c *this)

{
  int *piVar1;
  JKRHeap *pJVar2;
  int iVar3;
  int **ppiVar4;
  
  ppiVar4 = (int **)this->mpBalls;
  for (iVar3 = 0; iVar3 < (int)(uint)this->mBallNum; iVar3 = iVar3 + 1) {
    piVar1 = *ppiVar4;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1,1);
    }
    ppiVar4 = ppiVar4 + 1;
  }
  pJVar2 = (JKRHeap *)this->mpBalls;
  JKernel::operator_delete(pJVar2);
  this->mpBalls = (dMagma_ball_c **)0x0;
  return (int)pJVar2;
}


/* __thiscall dMagma_room_c::newFloor(dMagma_floor_c *) */

void __thiscall dMagma_room_c::newFloor(dMagma_room_c *this,dMagma_floor_c *pRoom)

{
  pRoom->mpNext = this->mpFirst;
  this->mpFirst = pRoom;
  return;
}


/* __thiscall dMagma_room_c::deleteFloor(void) */

void __thiscall dMagma_room_c::deleteFloor(dMagma_room_c *this)

{
  while (this->mpFirst != (dMagma_floor_c *)0x0) {
    dMagma_floor_c::remove(this->mpFirst);
    this->mpFirst = this->mpFirst->mpNext;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dMagma_packet_c::dMagma_packet_c(void) */

void __thiscall dMagma_packet_c::dMagma_packet_c(dMagma_packet_c *this)

{
  ResTIMG *pRVar1;
  
  (this->parent).vtbl = (undefined *)&J3DPacket::__vt;
  (this->parent).mpNextSibling = (J3DPacket *)0x0;
  (this->parent).mpFirstChild = (J3DPacket *)0x0;
  (this->parent).field_0xc = (undefined *)0x0;
  (this->parent).vtbl = &__vt;
  Runtime.PPCEABI.H::__construct_array
            (this->mFloor,dMagma_floor_c::dMagma_floor_c,dMagma_floor_c::_dMagma_floor_c,0xb0,8);
  Runtime.PPCEABI.H::__construct_array
            (this->mRoom,dMagma_room_c::dMagma_room_c,(undefined *)0x0,4,0x40);
  dRes_control_c::setRes
            ("Magma",d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40,"/res/Object/",0,
             (JKRHeap *)0x0);
  pRVar1 = (ResTIMG *)
           dRes_control_c::getRes
                     ("Magma",4,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
  m_Do_lib::mDoLib_setResTimgObj(pRVar1,&mKuroTexObj,0,(GXTlutObj *)0x0);
  mtx::C_MTXLightOrtho
            (d_magma::_4030,d_magma::_4240,d_magma::_4240,d_magma::_4030,d_magma::_4241,
             d_magma::_4242,d_magma::_4241,d_magma::_4241,&d_magma::l_kuroOrthoMtx);
  mtx::PSMTXCopy(&d_magma::l_kuroOrthoMtx,&d_magma::l_colOrthoMtx);
  pRVar1 = (ResTIMG *)
           dRes_control_c::getRes
                     ("Magma",3,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
  m_Do_lib::mDoLib_setResTimgObj(pRVar1,&mColTexObj,0,(GXTlutObj *)0x0);
  mtx::PSMTXIdentity(&mFloorMtx);
  mtx::PSMTXIdentity(&mBallMtx);
  this->mTimer = d_magma::_4010;
  return;
}


/* __thiscall dMagma_room_c::dMagma_room_c(void) */

void __thiscall dMagma_room_c::dMagma_room_c(dMagma_room_c *this)

{
  this->mpFirst = (dMagma_floor_c *)0x0;
  return;
}


/* __thiscall dMagma_floor_c::~dMagma_floor_c(void) */

void __thiscall dMagma_floor_c::_dMagma_floor_c(dMagma_floor_c *this)

{
  short in_r4;
  
  if ((this != (dMagma_floor_c *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall dMagma_floor_c::dMagma_floor_c(void) */

void __thiscall dMagma_floor_c::dMagma_floor_c(dMagma_floor_c *this)

{
  this->mpBalls = (dMagma_ball_c **)0x0;
  return;
}


/* __thiscall dMagma_packet_c::~dMagma_packet_c(void) */

void __thiscall dMagma_packet_c::_dMagma_packet_c(dMagma_packet_c *this)

{
  short in_r4;
  
  if (this != (dMagma_packet_c *)0x0) {
    (this->parent).vtbl = &__vt;
    dRes_control_c::deleteRes("Magma",d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
    Runtime.PPCEABI.H::__destroy_arr(this->mFloor,dMagma_floor_c::_dMagma_floor_c,0xb0,8);
    if (this != (dMagma_packet_c *)0x0) {
      (this->parent).vtbl = (undefined *)&J3DPacket::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dMagma_packet_c::draw(void) */

void __thiscall dMagma_packet_c::draw(dMagma_packet_c *this)

{
  int iVar1;
  dMagma_floor_c *this_00;
  _GXColor_conflict local_18;
  
  J3DSys::reinitGX(&J3DGraphBase::j3dSys);
  gx::GXSetNumIndStages(0);
  gx::GXClearVtxDesc();
  gx::GXSetVtxDesc(GX_VA_POS,GX_INDEX8);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_F32,0);
  gx::GXLoadTexObj(&mKuroTexObj,0);
  gx::GXLoadTexObj(&mColTexObj,1);
  d_kankyo::dKy_GxFog_set();
  gx::GXSetAlphaCompare(GX_GREATER,0,GX_AOP_OR,GX_GREATER,0);
  local_18 = this->mColor1;
  gx::GXSetTevColor(GX_TEVREG1,(_GXColor *)&local_18);
  gx::GXSetCurrentMtx(0);
  this_00 = this->mFloor;
  iVar1 = 0;
  do {
    if (this_00->mpBalls != (dMagma_ball_c **)0x0) {
      dMagma_floor_c::draw(this_00);
    }
    iVar1 = iVar1 + 1;
    this_00 = this_00 + 1;
  } while (iVar1 < 8);
  gx::GXSetTexCoordScaleManually(0,0,0,0);
  gx::GXSetTexCoordScaleManually(1,0,0,0);
  _sOldVcdVatCmd = 0;
  return;
}


namespace d_magma {

/* __stdcall morfCalc(float,
                      float,
                      float) */

double morfCalc(double param_1,double param_2,double param_3)

{
  return (double)(float)(param_1 + (double)(float)(param_3 * (double)(float)(param_2 - param_1)));
}

}

/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x80076750) */
/* __thiscall dMagma_packet_c::calc(void) */

void __thiscall dMagma_packet_c::calc(dMagma_packet_c *this)

{
  float fVar1;
  float fVar2;
  dMagma_floor_c *this_00;
  byte *pbVar3;
  int iVar4;
  dMagma_room_c *pdVar5;
  undefined4 uVar6;
  double dVar7;
  undefined8 in_f31;
  double dVar8;
  undefined auStack8 [8];
  
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  d_magma::l_kuroOrthoMtx.m[0][3] = d_magma::l_kuroOrthoMtx.m[0][3] + d_magma::_4318;
  if (d_magma::_4319 <= d_magma::l_kuroOrthoMtx.m[0][3]) {
    d_magma::l_kuroOrthoMtx.m[0][3] = d_magma::l_kuroOrthoMtx.m[0][3] - d_magma::_4030;
  }
  d_magma::l_kuroOrthoMtx.m[1][3] = d_magma::l_kuroOrthoMtx.m[0][3];
  mtx::PSMTXScale((double)d_magma::_4320,(double)d_magma::_4321,(double)d_magma::_4322,
                  &mDoMtx_stack_c::now);
  m_Do_mtx::mDoMtx_XrotM(&mDoMtx_stack_c::now,0x4000);
  mtx::PSMTXConcat(&d_magma::l_kuroOrthoMtx,&mDoMtx_stack_c::now,&mKuroMtx);
  pdVar5 = this->mRoom;
  iVar4 = 0;
  do {
    for (this_00 = pdVar5->mpFirst; this_00 != (dMagma_floor_c *)0x0; this_00 = this_00->mpNext) {
      if (this_00->mpBalls != (dMagma_ball_c **)0x0) {
        dMagma_floor_c::calc(this_00,iVar4);
      }
    }
    iVar4 = iVar4 + 1;
    pdVar5 = pdVar5 + 1;
  } while (iVar4 < 0x40);
  this->mTimer = this->mTimer + d_magma::_4030;
  if (d_magma::_4323 <= this->mTimer) {
    this->mTimer = this->mTimer - d_magma::_4323;
  }
  pbVar3 = &DAT_80377b70;
  iVar4 = 2;
  do {
    fVar1 = (float)((double)CONCAT44(0x43300000,(uint)pbVar3[3]) - d_magma::_4060);
    if (this->mTimer < fVar1) break;
    pbVar3 = pbVar3 + 4;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  fVar2 = (float)((double)CONCAT44(0x43300000,(uint)pbVar3[-1]) - d_magma::_4060);
  dVar8 = (double)((this->mTimer - fVar2) / (fVar1 - fVar2));
  dVar7 = (double)d_magma::morfCalc((double)(float)((double)CONCAT44(0x43300000,(uint)pbVar3[-4]) -
                                                   d_magma::_4060),
                                    (double)(float)((double)CONCAT44(0x43300000,(uint)*pbVar3) -
                                                   d_magma::_4060),dVar8);
  (this->mColor1).r = (u8)(int)dVar7;
  dVar7 = (double)d_magma::morfCalc((double)(float)((double)CONCAT44(0x43300000,(uint)pbVar3[-3]) -
                                                   d_magma::_4060),
                                    (double)(float)((double)CONCAT44(0x43300000,(uint)pbVar3[1]) -
                                                   d_magma::_4060),dVar8);
  (this->mColor1).g = (u8)(int)dVar7;
  dVar7 = (double)d_magma::morfCalc((double)(float)((double)CONCAT44(0x43300000,(uint)pbVar3[-2]) -
                                                   d_magma::_4060),
                                    (double)(float)((double)CONCAT44(0x43300000,(uint)pbVar3[2]) -
                                                   d_magma::_4060),dVar8);
  (this->mColor1).b = (u8)(int)dVar7;
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dMagma_packet_c::update(void) */

void __thiscall dMagma_packet_c::update(dMagma_packet_c *this)

{
  int iVar1;
  dMagma_floor_c *this_00;
  
  this_00 = this->mFloor;
  iVar1 = 0;
  do {
    if (this_00->mpBalls != (dMagma_ball_c **)0x0) {
      dMagma_floor_c::update(this_00);
    }
    iVar1 = iVar1 + 1;
    this_00 = this_00 + 1;
  } while (iVar1 < 8);
  J3DDrawBuffer::entryImm(J3DGraphBase::j3dSys.mpCurDrawBuffers[0],&this->parent,0);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x80076904) */
/* __thiscall dMagma_packet_c::checkYpos(cXyz &) */

double __thiscall dMagma_packet_c::checkYpos(dMagma_packet_c *this,cXyz *pPos)

{
  float fVar1;
  dMagma_ballPath_c *pdVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  dMagma_floor_c *pdVar6;
  undefined4 uVar7;
  undefined8 in_f31;
  double dVar8;
  float local_38 [5];
  undefined auStack8 [8];
  
  uVar7 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  dVar8 = (double)d_magma::_4392;
  pdVar6 = this->mFloor;
  iVar5 = 0;
  do {
    pdVar2 = (dMagma_ballPath_c *)pdVar6->mpBalls;
    if ((((pdVar2 != (dMagma_ballPath_c *)0x0) &&
         (ABS(pPos->y - (pdVar6->mBallPos).y) <= d_magma::_4393)) &&
        (ABS(pPos->x - (pdVar6->mBallPos).x) <= d_magma::_4394 * pdVar6->field_0x14)) &&
       (ABS(pPos->z - (pdVar6->mBallPos).z) <= d_magma::_4394 * pdVar6->field_0x18)) {
      for (iVar4 = 0; iVar4 < (int)(uint)pdVar6->mBallNum; iVar4 = iVar4 + 1) {
        iVar3 = dMagma_ball_c::rangeCheck(*(dMagma_ballPath_c **)pdVar2,pPos,local_38);
        if (iVar3 != 0) {
          fVar1 = (pdVar6->mBallPos).y;
          if (local_38[0] < fVar1) {
            local_38[0] = fVar1;
          }
          if (dVar8 < (double)local_38[0]) {
            dVar8 = (double)local_38[0];
          }
        }
        pdVar2 = (dMagma_ballPath_c *)((int)pdVar2 + 4);
      }
    }
    iVar5 = iVar5 + 1;
    pdVar6 = pdVar6 + 1;
  } while (iVar5 < 8);
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  return dVar8;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall dMagma_packet_c::newFloor(cXyz &,
                                        cXyz &,
                                        int,
                                        short) */

dMagma_floor_c * __thiscall
dMagma_packet_c::newFloor
          (dMagma_packet_c *this,cXyz *param_1,cXyz *param_2,int param_3,short param_4)

{
  bool bVar1;
  uint uVar2;
  ulong uVar3;
  dPath *pdVar4;
  uchar uVar5;
  dMagma_floor_c *this_00;
  int iVar6;
  
  bVar1 = false;
  if ((-1 < param_3) && (param_3 < 0x40)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"d_magma.cpp",0x36e,"0 <= i_roomNo && i_roomNo < 64");
    m_Do_printf::OSPanic("d_magma.cpp",0x36e,&DAT_803529fd);
  }
  this_00 = this->mFloor;
  iVar6 = 8;
  while (this_00->mpBalls != (dMagma_ball_c **)0x0) {
    this_00 = this_00 + 1;
    iVar6 = iVar6 + -1;
    if (iVar6 == 0) {
      return (dMagma_floor_c *)0x0;
    }
  }
  iVar6 = 0;
  uVar5 = '\0';
  if (param_4 < 0) {
    uVar5 = -(char)param_4;
  }
  else {
    pdVar4 = d_path::dPath_GetRoomPath((int)param_4,param_3);
    if (pdVar4 == (dPath *)0x0) {
      return (dMagma_floor_c *)0x0;
    }
    for (uVar2 = (uint)pdVar4->mNum; uVar2 != 0; uVar2 = uVar2 - 1) {
      iVar6 = iVar6 + (int)(d_magma::_4424 *
                           (float)((double)CONCAT44(0x43300000,(uint)pdVar4->mpPnt->mArg3) -
                                  d_magma::_4060));
      uVar5 = (uchar)iVar6;
    }
  }
  iVar6 = dMagma_floor_c::create(this_00,param_1,param_2,param_4,uVar5,param_3);
  if (iVar6 == 0) {
    return (dMagma_floor_c *)0x0;
  }
  dMagma_room_c::newFloor(this->mRoom + param_3,this_00);
  return this_00;
}


/* __thiscall dMagma_ballPath_c::~dMagma_ballPath_c(void) */

void __thiscall dMagma_ballPath_c::_dMagma_ballPath_c(dMagma_ballPath_c *this)

{
  short in_r4;
  
  if (this != (dMagma_ballPath_c *)0x0) {
    this->vtbl = (undefined *)&__vt;
    if (this != (dMagma_ballPath_c *)0x0) {
      this->vtbl = &dMagma_ball_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}

