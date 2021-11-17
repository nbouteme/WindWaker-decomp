#include <d_a_sea.h>
#include <d_a_sea.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JKernel/JKRHeap.h>
#include <d_resorce.h>
#include <gx/GXTexture.h>
#include <m_Do_lib.h>
#include <SComponent/c_m2d_g_box.h>
#include <SComponent/c_m3d.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <d_stage.h>
#include <f_pc_searcher.h>
#include <f_op_actor_iter.h>
#include <d_save.h>
#include <d_kankyo.h>
#include <SComponent/c_math.h>
#include <m_Do_graphic.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <J3DGraphBase/J3DSys.h>
#include <os/OSCache.h>
#include <mtx/mtx.h>
#include <gx/GXTransform.h>
#include <gx/GXBump.h>
#include <gx/GXTev.h>
#include <gx/GXLight.h>
#include <gx/GXAttr.h>
#include <gx/GXGeometry.h>
#include <gx/GXPixel.h>
#include <J3DGraphBase/J3DDrawBuffer.h>
#include <f_op_actor.h>
#include <f_op_actor_mng.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <daSea_packet_c.h>
#include <daSea_WaveInfo.h>
#include <daSea_WaterHeightInfo_Mng.h>
#include <cM2dGBox.h>


namespace d_a_sea {
struct daSea_packet_c l_cloth;
float offset$4646[6];
}

/* __thiscall daSea_WaterHeightInfo_Mng::Pos2Index(float,
                                                   float *) */

int __thiscall
daSea_WaterHeightInfo_Mng::Pos2Index(daSea_WaterHeightInfo_Mng *this,float param_1,float *param_2)

{
  uint uVar1;
  double local_8;
  
  uVar1 = (uint)((param_1 + d_a_sea::450000_0) / d_a_sea::100000_0);
  if (param_2 != (float *)0x0) {
    local_8 = (double)CONCAT44(0x43300000,uVar1 ^ 0x80000000);
    *param_2 = (param_1 + d_a_sea::450000_0) - d_a_sea::100000_0 * (float)(local_8 - d_a_sea::_4046)
    ;
  }
  return uVar1;
}


/* __thiscall daSea_WaterHeightInfo_Mng::GetHeight(float,
                                                   float) */

float __thiscall
daSea_WaterHeightInfo_Mng::GetHeight(daSea_WaterHeightInfo_Mng *this,float param_1,float param_2)

{
  int iVar1;
  int iVar2;
  double dVar3;
  
  dVar3 = (double)param_2;
  iVar1 = Pos2Index(this,param_1,(float *)0x0);
  iVar2 = Pos2Index(this,(float)dVar3,(float *)0x0);
  dVar3 = (double)GetHeight(this,iVar1,iVar2);
  return (float)dVar3;
}


namespace d_a_sea {

/* __stdcall get_wave_max(int) */

byte get_wave_max(uint param_1)

{
  int iVar1;
  dStage_Multi_c *pMulti;
  dStage_Multi_c__Entry *pdVar2;
  
  pMulti = (dStage_Multi_c *)
           (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getMulti)();
  if (pMulti != (dStage_Multi_c *)0x0) {
    pdVar2 = pMulti->mEntries;
    iVar1 = pMulti->mCount;
    if (0 < iVar1) {
      do {
        if (param_1 == pdVar2->mRoomId) {
          return pdVar2->mWaveMax;
        }
        pdVar2 = pdVar2 + 1;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
    }
  }
  return 10;
}

}

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall daSea_WaterHeightInfo_Mng::GetHeight(int,
                                                   int) */

uint __thiscall
daSea_WaterHeightInfo_Mng::GetHeight(daSea_WaterHeightInfo_Mng *this,int param_1,int param_2)

{
  uint uVar1;
  stage_stag_info_class *pStag;
  
  if ((((param_1 < 0) || (8 < param_1)) || (param_2 < 0)) || (8 < param_2)) {
    uVar1 = 10;
  }
  else {
    pStag = (stage_stag_info_class *)
            (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)();
    if ((pStag->mStageTypeAndSchbit >> 0x10 & 7) == 7) {
      uVar1 = (uint)this->mHeight[param_2][param_1];
    }
    else {
      uVar1 = d_a_sea::get_wave_max((int)(char)dStage_roomControl_c::mStayNo);
    }
  }
  return uVar1;
}


namespace d_a_sea {

/* __stdcall calcMinMax(int,
                        float *,
                        float *) */

void calcMinMax(uint param_1,float *param_2,float *param_3)

{
  float fVar1;
  
  fVar1 = 100000_0;
  *param_2 = 100000_0 * (float)((double)CONCAT44(0x43300000,param_1 ^ 0x80000000) - _4046) -
             450000_0;
  *param_3 = fVar1 + *param_2;
  return;
}

}

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall daSea_WaterHeightInfo_Mng::GetArea(int,
                                                 int,
                                                 float *,
                                                 float *,
                                                 float *,
                                                 float *) */

void __thiscall
daSea_WaterHeightInfo_Mng::GetArea
          (daSea_WaterHeightInfo_Mng *this,int ix,int iz,float *pMinX,float *pMinZ,float *pMaxX,
          float *pMaxZ)

{
  d_a_sea::calcMinMax(ix,pMinX,pMaxX);
  d_a_sea::calcMinMax(iz,pMinZ,pMaxZ);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall daSea_WaterHeightInfo_Mng::SetInf(void) */

void __thiscall daSea_WaterHeightInfo_Mng::SetInf(daSea_WaterHeightInfo_Mng *this)

{
  dStage_Multi_c *pMulti;
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  pMulti = (dStage_Multi_c *)
           (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getMulti)();
  iVar4 = 0;
  iVar2 = 0;
  do {
    pbVar3 = this->mHeight + iVar2;
    iVar6 = 9;
    do {
      *pbVar3 = 10;
      pbVar3 = pbVar3 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    iVar4 = iVar4 + 1;
    iVar2 = iVar2 + 9;
  } while (iVar4 < 9);
  if (pMulti != (dStage_Multi_c *)0x0) {
    iVar4 = 1;
    iVar2 = 1;
    iVar6 = 9;
    do {
      iVar5 = 1;
      pbVar3 = this->mHeight + iVar6;
      do {
        pbVar3 = pbVar3 + 1;
        bVar1 = d_a_sea::get_wave_max(iVar4);
        *pbVar3 = bVar1;
        iVar5 = iVar5 + 1;
        iVar4 = iVar4 + 1;
      } while (iVar5 < 8);
      iVar2 = iVar2 + 1;
      iVar6 = iVar6 + 9;
    } while (iVar2 < 8);
  }
  return;
}


/* __thiscall daSea_WaveInfo::daSea_WaveInfo(void) */

void __thiscall daSea_WaveInfo::daSea_WaveInfo(daSea_WaveInfo *this)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  this->vtbl = (undefined *)&__vt;
  fVar1 = d_a_sea::0_0;
  iVar2 = 0;
  iVar4 = 4;
  do {
    iVar3 = (int)this->field_0x4 + iVar2 + -4;
    *(float *)(iVar3 + 4) = fVar1;
    *(undefined4 *)(iVar3 + 0x14) = 0;
    iVar2 = iVar2 + 4;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  this->mCurScale = d_a_sea::1_0;
  return;
}


/* __thiscall daSea_WaveInfo::~daSea_WaveInfo(void) */

void __thiscall daSea_WaveInfo::_daSea_WaveInfo(daSea_WaveInfo *this)

{
  short in_r4;
  
  if ((this != (daSea_WaveInfo *)0x0) && (this->vtbl = (undefined *)&__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall daSea_WaveInfo::AddCounter(void) */

void __thiscall daSea_WaveInfo::AddCounter(daSea_WaveInfo *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = 0;
  iVar2 = 0;
  iVar3 = 4;
  do {
    *(int *)((int)this->mCounters + iVar2) = *(int *)((int)this->mCounters + iVar2) + 1;
    if (*(int *)((int)&this->mWaveInfoTable->mCounterMax + iVar1) <=
        *(int *)((int)this->mCounters + iVar2)) {
      *(undefined4 *)((int)this->mCounters + iVar2) = 0;
    }
    iVar1 = iVar1 + 0x18;
    iVar2 = iVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}


/* __thiscall daSea_WaveInfo::GetRatio(int) */

double __thiscall daSea_WaveInfo::GetRatio(daSea_WaveInfo *this,int param_1)

{
  return (double)((float)((double)CONCAT44(0x43300000,this->mCounters[param_1] ^ 0x80000000) -
                         d_a_sea::_4046) /
                 (float)((double)CONCAT44(0x43300000,
                                          this->mWaveInfoTable[param_1].mCounterMax ^ 0x80000000) -
                        d_a_sea::_4046));
}


/* __thiscall daSea_WaveInfo::GetKm(int) */

double __thiscall daSea_WaveInfo::GetKm(daSea_WaveInfo *this,int param_1)

{
  return (double)(d_a_sea::6_28 * this->mWaveInfoTable[param_1].mKm);
}


/* __thiscall daSea_WaveInfo::GetScale(float) */

double __thiscall daSea_WaveInfo::GetScale(daSea_WaveInfo *this,float param_1)

{
  this->mCurScale = this->mCurScale + (param_1 - this->mCurScale) / d_a_sea::100_0;
  return (double)this->mCurScale;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall daSea_packet_c::create(cXyz &) */

bool __thiscall daSea_packet_c::create(daSea_packet_c *this,cXyz *param_1)

{
  bool bVar1;
  float *pfVar2;
  _GXTexFmt *p_Var3;
  ResTIMG *pResTIMG;
  
  BASE_HEIGHT = d_a_sea::1_0 + param_1->y;
  this->mFlatInter = d_a_sea::0_0;
  pfVar2 = (float *)JKernel::operator_new__(0x4204);
  this->mpHeightTable = pfVar2;
  bVar1 = this->mpHeightTable != (float *)0x0;
  if (bVar1) {
    daSea_WaterHeightInfo_Mng::SetInf(&this->mWaterHeightMgr);
    (this->mWaveInfo).mWaveInfoTable = d_a_sea::wi_prm_ocean;
    CleanUp(this);
    this->mbIsDelete = 1;
    this->mRoomNo = -1;
    this->mFlags = 0;
    this->mAnimCounter = 0;
    p_Var3 = (_GXTexFmt *)
             dRes_control_c::getRes
                       ("Always",0x6f,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
    gx::GXInitTexObj((GXTexObj *)&this->mTexSea0,p_Var3 + *(int *)(p_Var3 + 0x1c),
                     (uint)*(ushort *)(p_Var3 + 2),(uint)*(ushort *)(p_Var3 + 4),*p_Var3,p_Var3[6],
                     p_Var3[7],SUB41(1 - (uint)p_Var3[0x18] >> 0x1f,0));
    gx::GXInitTexObjLOD((double)(d_a_sea::0_125 *
                                (float)((double)CONCAT44(0x43300000,
                                                         (int)(char)p_Var3[0x16] ^ 0x80000000) -
                                       d_a_sea::_4046)),
                        (double)(d_a_sea::0_125 *
                                (float)((double)CONCAT44(0x43300000,
                                                         (int)(char)p_Var3[0x17] ^ 0x80000000) -
                                       d_a_sea::_4046)),(double)d_a_sea::_0_9,&this->mTexSea0,
                        p_Var3[0x14],p_Var3[0x15],p_Var3[0x12],p_Var3[0x11],p_Var3[0x13]);
    gx::GXInitTexObj((GXTexObj *)&this->mTexSea1,p_Var3 + *(int *)(p_Var3 + 0x1c),
                     (uint)*(ushort *)(p_Var3 + 2),(uint)*(ushort *)(p_Var3 + 4),*p_Var3,p_Var3[6],
                     p_Var3[7],SUB41(1 - (uint)p_Var3[0x18] >> 0x1f,0));
    gx::GXInitTexObjLOD((double)(d_a_sea::0_125 *
                                (float)((double)CONCAT44(0x43300000,
                                                         (int)(char)p_Var3[0x16] ^ 0x80000000) -
                                       d_a_sea::_4046)),
                        (double)(d_a_sea::0_125 *
                                (float)((double)CONCAT44(0x43300000,
                                                         (int)(char)p_Var3[0x17] ^ 0x80000000) -
                                       d_a_sea::_4046)),(double)d_a_sea::1_0,&this->mTexSea1,
                        p_Var3[0x14],p_Var3[0x15],p_Var3[0x12],p_Var3[0x11],p_Var3[0x13]);
    pResTIMG = (ResTIMG *)
               dRes_control_c::getRes
                         ("Always",0x70,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40
                         );
    m_Do_lib::mDoLib_setResTimgObj(pResTIMG,&this->mpTexWyurayura,0,(GXTlutObj *)0x0);
  }
  return bVar1;
}


/* __thiscall daSea_packet_c::CleanUp(void) */

void __thiscall daSea_packet_c::CleanUp(daSea_packet_c *this)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = 0;
  iVar3 = 0;
  do {
    iVar4 = 0x41;
    do {
      *(float *)((int)this->mpHeightTable + iVar2) = BASE_HEIGHT;
      fVar1 = d_a_sea::0_0;
      iVar2 = iVar2 + 4;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x41);
  (this->mCurPos).z = d_a_sea::0_0;
  (this->mCurPos).y = fVar1;
  (this->mCurPos).x = fVar1;
  return;
}


/* __thiscall daSea_packet_c::daSea_packet_c(void) */

void __thiscall daSea_packet_c::daSea_packet_c(daSea_packet_c *this)

{
  (this->parent).vtbl = (undefined *)&J3DPacket::__vt;
  (this->parent).mpNextSibling = (J3DPacket *)0x0;
  (this->parent).mpFirstChild = (J3DPacket *)0x0;
  (this->parent).field_0xc = (undefined *)0x0;
  (this->parent).vtbl = &__vt;
  (this->mWaterHeightMgr).vtbl = (undefined *)&daSea_WaterHeightInfo_Mng::__vt;
  daSea_WaveInfo::daSea_WaveInfo(&this->mWaveInfo);
  return;
}


/* __thiscall daSea_packet_c::SetFlat(void) */

void __thiscall daSea_packet_c::SetFlat(daSea_packet_c *this)

{
  this->mFlags = this->mFlags | 1;
  this->mFlatTarget = d_a_sea::0_0;
  this->mFlatInterCounter = d_a_sea::150_0;
  return;
}


/* __thiscall daSea_packet_c::ClrFlat(void) */

void __thiscall daSea_packet_c::ClrFlat(daSea_packet_c *this)

{
  this->mFlags = this->mFlags & 0xfffffffe;
  this->mFlatInterCounter = d_a_sea::150_0;
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* WARNING: Removing unreachable block (ram,0x8015b9f8) */
/* __thiscall daSea_packet_c::CalcFlatInterTarget(cXyz &) */

double __thiscall daSea_packet_c::CalcFlatInterTarget(daSea_packet_c *this,cXyz *param_1)

{
  int iVar1;
  int iVar2;
  int iz;
  int ix;
  int iVar3;
  undefined4 uVar4;
  double dVar5;
  double dVar6;
  undefined8 in_f31;
  cXy max;
  cXy min;
  cXy local_58;
  cM2dGBox box;
  undefined auStack8 [8];
  byte around;
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  local_58.x = param_1->x;
  local_58.y = param_1->z;
  iVar1 = daSea_WaterHeightInfo_Mng::GetHeight(&this->mWaterHeightMgr,this->mIdxX,this->mIdxZ);
  if (iVar1 == 0) {
    dVar5 = (double)d_a_sea::0_0;
  }
  else {
    dVar5 = (double)d_a_sea::1_0;
    iVar1 = 0;
    iVar3 = 0;
    do {
      around = d_a_sea::pos_around[iVar3];
      ix = this->mIdxX + (int)(char)around;
      iz = this->mIdxZ + (int)d_a_sea::pos_around[iVar3 + 1];
      iVar2 = daSea_WaterHeightInfo_Mng::GetHeight(&this->mWaterHeightMgr,ix,iz);
      if (iVar2 == 0) {
        daSea_WaterHeightInfo_Mng::GetArea(&this->mWaterHeightMgr,ix,iz,&min.x,&min.y,&max.x,&max.y)
        ;
        min.x = min.x - d_a_sea::12800_0;
        min.y = min.y - d_a_sea::12800_0;
        max.x = max.x + d_a_sea::12800_0;
        max.y = max.y + d_a_sea::12800_0;
        cM2dGBox::Set(&box,&min,&max);
        dVar6 = cM2dGBox::GetLen(&box,&local_58);
        if ((double)d_a_sea::12800_0 < dVar6) {
          dVar6 = (double)d_a_sea::12800_0;
        }
        if ((double)(float)(dVar6 / (double)d_a_sea::12800_0) < dVar5) {
          dVar5 = (double)(float)(dVar6 / (double)d_a_sea::12800_0);
        }
      }
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 2;
    } while (iVar1 < 8);
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return dVar5;
}


/* __thiscall daSea_packet_c::CalcFlatInter(void) */

void __thiscall daSea_packet_c::CalcFlatInter(daSea_packet_c *this)

{
  double target;
  
  if ((this->mFlags & 1U) == 0) {
    target = (double)CalcFlatInterTarget(this,(cXyz *)&this->mPlayerPos);
    if (d_a_sea::0_0 == this->mFlatInterCounter) {
      this->mFlatInter = (float)target;
    }
    else {
      this->mFlatInter =
           (float)((double)this->mFlatInter +
                  (double)((float)(target - (double)this->mFlatInter) / this->mFlatInterCounter));
      this->mFlatInterCounter = this->mFlatInterCounter - d_a_sea::1_0;
    }
  }
  else {
    if (d_a_sea::0_0 == this->mFlatInterCounter) {
      this->mFlatInter = this->mFlatTarget;
    }
    else {
      this->mFlatInter =
           this->mFlatInter + (this->mFlatTarget - this->mFlatInter) / this->mFlatInterCounter;
      this->mFlatInterCounter = this->mFlatInterCounter - d_a_sea::1_0;
    }
  }
  return;
}


namespace d_a_sea {

/* __stdcall daSea_Init(void) */

void daSea_Init(void)

{
  l_cloth.mbIsDelete = 0;
  l_cloth.mCullStopFlag = 1;
  l_cloth.field_0x13a = 1;
  return;
}


/* __stdcall daSea_ChkAreaBeforePos(float,
                                    float) */

int daSea_ChkAreaBeforePos(double param_1,double param_2)

{
  int iVar1;
  
  if (l_cloth.mbIsDelete == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = -0x7fc1b8ac;
    ::daSea_WaterHeightInfo_Mng::GetHeight(&l_cloth.mWaterHeightMgr,(float)param_1,(float)param_2);
    if ((iVar1 == 0) && (l_cloth.mCullStopFlag != 0)) {
      iVar1 = 0;
    }
    else {
      iVar1 = 1;
    }
  }
  return iVar1;
}


/* WARNING: Removing unreachable block (ram,0x8015bbdc) */
/* WARNING: Removing unreachable block (ram,0x8015bbe4) */
/* __stdcall daSea_ChkArea(float,
                           float) */

int daSea_ChkArea(float param_1,float param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  double dVar4;
  double dVar5;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar5 = (double)param_2;
  dVar4 = (double)param_1;
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  uVar1 = daSea_ChkAreaBeforePos(dVar4,dVar5);
  if ((uVar1 & 0xff) == 0) {
    iVar2 = 0;
  }
  else {
    if ((((dVar4 <= (double)l_cloth.mDrawMinX) || ((double)l_cloth.mDrawMaxX <= dVar4)) ||
        (dVar5 <= (double)l_cloth.mDrawMinZ)) || ((double)l_cloth.mDrawMaxZ <= dVar5)) {
      iVar2 = 0;
    }
    else {
      iVar2 = 1;
    }
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  __psq_l0(auStack24,uVar3);
  __psq_l1(auStack24,uVar3);
  return iVar2;
}


/* WARNING: Removing unreachable block (ram,0x8015bd90) */
/* WARNING: Removing unreachable block (ram,0x8015bd98) */
/* __stdcall daSea_calcWave(float,
                            float) */

double daSea_calcWave(double param_1,double param_2)

{
  int iVar1;
  int iVar2;
  float fVar3;
  uint uVar4;
  float *pfVar5;
  undefined4 uVar6;
  undefined8 in_f30;
  undefined8 in_f31;
  float local_88;
  TVec3_float_ local_84;
  TVec3_float_ local_78;
  TVec3_float_ local_6c;
  TVec3_float_ local_60;
  TVec3_float_ local_54;
  longlong local_48;
  longlong local_40;
  undefined4 local_38;
  uint uStack52;
  undefined4 local_30;
  uint uStack44;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  uVar4 = daSea_ChkArea((float)param_1,(float)param_2);
  fVar3 = ::daSea_packet_c::BASE_HEIGHT;
  if ((uVar4 & 0xff) != 0) {
    iVar1 = (int)(0_00125 * (float)(param_1 - (double)l_cloth.mDrawMinX));
    local_48 = (longlong)iVar1;
    iVar2 = (int)(0_00125 * (float)(param_2 - (double)l_cloth.mDrawMinZ));
    local_40 = (longlong)iVar2;
    pfVar5 = l_cloth.mpHeightTable + iVar1 + iVar2 * 0x41;
    uStack52 = iVar1 * 800 ^ 0x80000000;
    local_38 = 0x43300000;
    local_60.x = (float)((double)(float)((double)CONCAT44(0x43300000,uStack52) - _4046) +
                        (double)l_cloth.mDrawMinX);
    local_54.y = *pfVar5;
    uStack44 = iVar2 * 800 ^ 0x80000000;
    local_30 = 0x43300000;
    local_6c.z = (float)((double)(float)((double)CONCAT44(0x43300000,uStack44) - _4046) +
                        (double)l_cloth.mDrawMinZ);
    local_60.y = pfVar5[0x41];
    local_78.z = (float)((double)800_0 + (double)local_6c.z);
    local_78.x = (float)((double)800_0 + (double)local_60.x);
    local_6c.y = pfVar5[1];
    local_78.y = pfVar5[0x42];
    local_6c.x = local_78.x;
    local_60.z = local_78.z;
    local_54.x = local_60.x;
    local_54.z = local_6c.z;
    if ((float)(param_1 - (double)local_60.x) * 0_00125 +
        (float)(param_2 - (double)local_6c.z) * 0_00125 < 1_0) {
      SComponent::cM3d_CalcPla(&local_54,&local_60,&local_6c,&local_84,&local_88);
    }
    else {
      SComponent::cM3d_CalcPla(&local_60,&local_6c,&local_78,&local_84,&local_88);
    }
    fVar3 = -(local_88 +
             (float)((double)local_84.x * param_1) + (float)((double)local_84.z * param_2)) /
            local_84.y;
  }
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  __psq_l0(auStack24,uVar6);
  __psq_l1(auStack24,uVar6);
  return (double)fVar3;
}


/* WARNING: Inlined function: FUN_80328f14 */
/* WARNING: Inlined function: FUN_80328f60 */
/* WARNING: Removing unreachable block (ram,0x8015bfe8) */
/* WARNING: Removing unreachable block (ram,0x8015bff0) */
/* __stdcall daSea_GetPoly(void *,
                           void *(void *,cXyz &,cXyz &,cXyz &),
                           cXyz const &,
                           cXyz const &) */

void daSea_GetPoly(undefined4 param_1,code *param_2,cXyz *param_3,cXyz *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  undefined4 uVar11;
  undefined8 in_f30;
  double dVar12;
  undefined8 in_f31;
  double dVar13;
  float local_a8;
  undefined4 local_a4;
  float local_a0;
  float local_9c;
  undefined4 local_98;
  float local_94;
  float local_90;
  undefined4 local_8c;
  float local_88;
  float local_84;
  undefined4 local_80;
  float local_7c;
  longlong local_78;
  longlong local_70;
  double local_68;
  double local_60;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar11 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  uVar4 = daSea_ChkArea(param_3->x,param_3->z);
  if (((uVar4 & 0xff) != 0) && (uVar4 = daSea_ChkArea(param_4->x,param_4->z), (uVar4 & 0xff) != 0))
  {
    iVar1 = (int)(0_00125 * (param_3->x - l_cloth.mDrawMinX));
    local_78 = (longlong)iVar1;
    iVar7 = (int)(0_00125 * (param_3->z - l_cloth.mDrawMinZ));
    local_70 = (longlong)iVar7;
    iVar2 = (int)(0_00125 * (param_4->x - l_cloth.mDrawMinX));
    iVar3 = (int)(0_00125 * (param_4->z - l_cloth.mDrawMinZ));
    if ((((-1 < iVar1) && (((iVar1 < 0x40 && (-1 < iVar7)) && (iVar7 < 0x40)))) &&
        (((-1 < iVar2 && (iVar2 < 0x40)) && (-1 < iVar3)))) && (iVar3 < 0x40)) {
      dVar13 = (double)800_0;
      iVar10 = iVar7 * 0x104;
      uVar4 = iVar7 * 800;
      dVar12 = _4046;
      for (; iVar7 < iVar3 + 1; iVar7 = iVar7 + 1) {
        iVar8 = iVar1 << 2;
        uVar9 = iVar1 * 800;
        for (iVar6 = iVar1; iVar6 < iVar2 + 1; iVar6 = iVar6 + 1) {
          puVar5 = (undefined4 *)((int)l_cloth.mpHeightTable + iVar10 + iVar8);
          local_60 = (double)CONCAT44(0x43300000,uVar9 ^ 0x80000000);
          local_90 = (float)(local_60 - dVar12) + l_cloth.mDrawMinX;
          local_80 = *puVar5;
          local_68 = (double)CONCAT44(0x43300000,uVar4 ^ 0x80000000);
          local_94 = (float)(local_68 - dVar12) + l_cloth.mDrawMinZ;
          local_8c = puVar5[0x41];
          local_a0 = (float)(dVar13 + (double)local_94);
          local_a8 = (float)(dVar13 + (double)local_90);
          local_98 = puVar5[1];
          local_a4 = puVar5[0x42];
          local_9c = local_a8;
          local_88 = local_a0;
          local_84 = local_90;
          local_7c = local_94;
          (*param_2)(param_1,&local_84,&local_90,&local_a8);
          (*param_2)(param_1,&local_84,&local_a8,&local_9c);
          uVar9 = uVar9 + 800;
          iVar8 = iVar8 + 4;
        }
        uVar4 = uVar4 + 800;
        iVar10 = iVar10 + 0x104;
      }
    }
  }
  __psq_l0(auStack8,uVar11);
  __psq_l1(auStack8,uVar11);
  __psq_l0(auStack24,uVar11);
  __psq_l1(auStack24,uVar11);
  return;
}

}

/* __thiscall daSea_packet_c::SetCullStopFlag(void) */

void __thiscall daSea_packet_c::SetCullStopFlag(daSea_packet_c *this)

{
  float fVar1;
  int iVar2;
  float minX;
  float maxZ;
  float maxX;
  float minZ;
  
  iVar2 = MSL_C.PPCEABI.bare.H::strcmp
                    (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"A_umikz");
  if (iVar2 == 0) {
    this->mCullStopFlag = 0;
  }
  else {
    iVar2 = daSea_WaterHeightInfo_Mng::GetHeight(&this->mWaterHeightMgr,this->mIdxX,this->mIdxZ);
    if (iVar2 == 0) {
      daSea_WaterHeightInfo_Mng::GetArea
                (&this->mWaterHeightMgr,this->mIdxX,this->mIdxZ,&minX,&minZ,&maxX,&maxZ);
      fVar1 = (this->mPlayerPos).x;
      if ((((fVar1 <= minX + d_a_sea::25600_0) || (maxX - d_a_sea::25600_0 <= fVar1)) ||
          (fVar1 = (this->mPlayerPos).z, fVar1 <= minZ + d_a_sea::25600_0)) ||
         (maxZ - d_a_sea::25600_0 <= fVar1)) {
        this->mCullStopFlag = 0;
      }
      else {
        this->mCullStopFlag = 1;
      }
    }
    else {
      this->mCullStopFlag = 0;
    }
  }
  return;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall daSea_packet_c::CheckRoomChange(void) */

void __thiscall daSea_packet_c::CheckRoomChange(daSea_packet_c *this)

{
  dStage_roomStatus_c *pRoomStatus;
  fopAc_ac_c *pfVar1;
  bool bVar2;
  undefined2 uStack24;
  short local_16;
  
  pRoomStatus = dStage_roomControl_c::getStatusRoomDt
                          (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mRoomCtrl,
                           (int)(char)dStage_roomControl_c::mStayNo);
  if (pRoomStatus != (dStage_roomStatus_c *)0x0) {
    this->mRoomNo = (int)(char)dStage_roomControl_c::mStayNo;
                    /* daiocta */
    uStack24 = 0xe2;
    pfVar1 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeForPName,&uStack24);
    if (pfVar1 == (fopAc_ac_c *)0x0) {
      if ((this->mFlags & 1U) != 0) {
        ClrFlat(this);
      }
    }
    else {
      bVar2 = dSv_info_c::isSwitch
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo,
                         (uint)*(byte *)&pfVar1[2].parent.parent.mDtTg.parent.parent.mpNextNode,
                         (int)(char)(pfVar1->mOrig).mRoomNo);
      if (bVar2 == false) {
        SetFlat(this);
      }
      else {
        ClrFlat(this);
      }
    }
  }
  return;
}


namespace d_a_sea {

/* __stdcall daSea_execute(cXyz &) */

void daSea_execute(cXyz *param_1)

{
  if (l_cloth.mbIsDelete != 0) {
    ::daSea_packet_c::execute(&l_cloth,param_1);
  }
  return;
}

}

/* WARNING: Inlined function: __save_gpr */
/* WARNING: Inlined function: __restore_gpr */
/* WARNING: Removing unreachable block (ram,0x8015c734) */
/* WARNING: Removing unreachable block (ram,0x8015c724) */
/* WARNING: Removing unreachable block (ram,0x8015c72c) */
/* WARNING: Removing unreachable block (ram,0x8015c73c) */
/* __thiscall daSea_packet_c::execute(cXyz &) */

void __thiscall daSea_packet_c::execute(daSea_packet_c *this,cXyz *param_2)

{
  float fVar1;
  int idxX;
  int idxZ;
  daSea_WaterHeightInfo_Mng *this_00;
  daSea_WaveInfo__Table *pWaveInfoTable;
  int waveTheta0_DeltaZ;
  int waveTheta1_DeltaZ;
  int waveTheta3_DeltaZ;
  int waveTheta0_DeltaX;
  int waveTheta1_DeltaX;
  int waveTheta2_DeltaX;
  int waveTheta3_DeltaX;
  int waveTheta0_Phase;
  int waveTheta1_Phase;
  int waveTheta3_Phase;
  int iz;
  float *pHeight;
  uint waveTheta0;
  uint waveTheta1;
  uint waveTheta2;
  uint waveTheta3;
  int fadeZ;
  int iVar2;
  int iw;
  int fadeX;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int ix;
  undefined4 uVar7;
  double scale;
  double dVar8;
  undefined8 in_f28;
  undefined8 in_f29;
  double dVar9;
  undefined8 in_f30;
  double dVar10;
  undefined8 in_f31;
  double dVar11;
  short aOffsAnimTable [4];
  float aHeightTable [4];
  float aThetaZTable [4];
  float aThetaXTable [4];
  float aFadeTable [65];
  double local_98;
  int waveTheta2_Phase;
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar7 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  (this->mPlayerPos).x = param_2->x;
  (this->mPlayerPos).y = param_2->y;
  (this->mPlayerPos).z = param_2->z;
  idxX = daSea_WaterHeightInfo_Mng::Pos2Index
                   (&this->mWaterHeightMgr,(this->mPlayerPos).x,(float *)0x0);
  this->mIdxX = idxX;
  idxZ = daSea_WaterHeightInfo_Mng::Pos2Index
                   (&this->mWaterHeightMgr,(this->mPlayerPos).z,(float *)0x0);
  this->mIdxZ = idxZ;
  waveTheta0_DeltaZ =
       MSL_C.PPCEABI.bare.H::strcmp
                 (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"ADMumi");
  if (waveTheta0_DeltaZ == 0) {
    this->mFlatInter = d_a_sea::0_0;
  }
  if ((this->mRoomNo != (int)(char)dStage_roomControl_c::mStayNo) &&
     ((char)dStage_roomControl_c::mStayNo != 0)) {
    CheckRoomChange(this);
  }
  CalcFlatInter(this);
  d_kankyo::dKy_usonami_set((double)this->mFlatInter);
  fVar1 = d_a_sea::25600_0;
  this->mDrawMinX = param_2->x - d_a_sea::25600_0;
  this->mDrawMaxX = fVar1 + param_2->x;
  this->mDrawMinZ = param_2->z - fVar1;
  this->mDrawMaxZ = fVar1 + param_2->z;
  SetCullStopFlag(this);
  if (this->mCullStopFlag != 1) {
    this_00 = &this->mWaterHeightMgr;
    daSea_WaterHeightInfo_Mng::GetHeight(this_00,param_2->x,param_2->z);
    local_98 = (double)CONCAT44(0x43300000,(uint)this_00 ^ 0x80000000);
    scale = (double)daSea_WaveInfo::GetScale(&this->mWaveInfo,(float)(local_98 - d_a_sea::_4046));
    scale = (double)(float)((double)this->mFlatInter * scale);
    waveTheta3_DeltaZ = 0;
    waveTheta0_DeltaZ = 0;
    waveTheta1_DeltaZ = 0;
    iw = 0;
    dVar10 = (double)d_a_sea::0_5;
    dVar11 = (double)d_a_sea::65536_0;
    do {
      dVar9 = (double)*(float *)((int)&((this->mWaveInfo).mWaveInfoTable)->mScaleX + iw);
      dVar8 = (double)daSea_WaveInfo::GetKm(&this->mWaveInfo,waveTheta3_DeltaZ);
      *(float *)((int)aThetaXTable + waveTheta1_DeltaZ) = (float)(dVar8 * dVar9);
      dVar9 = (double)*(float *)((int)&((this->mWaveInfo).mWaveInfoTable)->mScaleZ + iw);
      dVar8 = (double)daSea_WaveInfo::GetKm(&this->mWaveInfo,waveTheta3_DeltaZ);
      *(float *)((int)aThetaZTable + waveTheta1_DeltaZ) = (float)(dVar8 * dVar9);
      dVar8 = (double)daSea_WaveInfo::GetRatio(&this->mWaveInfo,waveTheta3_DeltaZ);
      *(short *)((int)aOffsAnimTable + waveTheta0_DeltaZ) =
           (short)(int)(dVar11 * (double)(float)(dVar8 - dVar10));
      *(float *)((int)aHeightTable + waveTheta1_DeltaZ) =
           (float)(scale * (double)*(float *)((int)&((this->mWaveInfo).mWaveInfoTable)->mHeight + iw
                                             ));
      waveTheta3_DeltaZ = waveTheta3_DeltaZ + 1;
      waveTheta0_DeltaZ = waveTheta0_DeltaZ + 2;
      waveTheta1_DeltaZ = waveTheta1_DeltaZ + 4;
      iw = iw + 0x18;
    } while (waveTheta3_DeltaZ < 4);
    scale = (double)(d_a_sea::800_0 + this->mDrawMinZ);
    waveTheta0_DeltaZ = SComponent::cM_rad2s((double)(float)((double)aThetaZTable[0] * scale));
    dVar10 = (double)aThetaZTable[1];
    waveTheta1_DeltaZ = SComponent::cM_rad2s((double)(float)(dVar10 * scale));
    dVar11 = (double)aThetaZTable[2];
    iw = SComponent::cM_rad2s((double)(float)(dVar11 * scale));
    dVar8 = (double)aThetaZTable[3];
    waveTheta3_DeltaZ = SComponent::cM_rad2s((double)(float)(dVar8 * scale));
    pWaveInfoTable = (this->mWaveInfo).mWaveInfoTable;
    iVar6 = (waveTheta0_DeltaZ - aOffsAnimTable[0]) + (int)pWaveInfoTable->mPhase;
    iVar5 = (waveTheta1_DeltaZ - aOffsAnimTable[1]) + (int)pWaveInfoTable[1].mPhase;
    iVar4 = (iw - aOffsAnimTable[2]) + (int)pWaveInfoTable[2].mPhase;
    iVar3 = (waveTheta3_DeltaZ - aOffsAnimTable[3]) + (int)pWaveInfoTable[3].mPhase;
    waveTheta0_DeltaZ = SComponent::cM_rad2s((double)(d_a_sea::800_0 * aThetaZTable[0]));
    waveTheta1_DeltaZ = SComponent::cM_rad2s((double)(float)((double)d_a_sea::800_0 * dVar10));
    iw = SComponent::cM_rad2s((double)(float)((double)d_a_sea::800_0 * dVar11));
    waveTheta3_DeltaZ = SComponent::cM_rad2s((double)(float)((double)d_a_sea::800_0 * dVar8));
    waveTheta0_DeltaX = SComponent::cM_rad2s((double)(d_a_sea::800_0 * aThetaXTable[0]));
    dVar10 = (double)aThetaXTable[1];
    waveTheta1_DeltaX = SComponent::cM_rad2s((double)(float)((double)d_a_sea::800_0 * dVar10));
    dVar11 = (double)aThetaXTable[2];
    waveTheta2_DeltaX = SComponent::cM_rad2s((double)(float)((double)d_a_sea::800_0 * dVar11));
    dVar8 = (double)aThetaXTable[3];
    waveTheta3_DeltaX = SComponent::cM_rad2s((double)(float)((double)d_a_sea::800_0 * dVar8));
    scale = (double)(d_a_sea::800_0 + this->mDrawMinX);
    waveTheta0_Phase = SComponent::cM_rad2s((double)(float)((double)aThetaXTable[0] * scale));
    waveTheta1_Phase = SComponent::cM_rad2s((double)(float)(dVar10 * scale));
    waveTheta2_Phase = SComponent::cM_rad2s((double)(float)(dVar11 * scale));
    waveTheta3_Phase = SComponent::cM_rad2s((double)(float)(dVar8 * scale));
    iz = 0;
    fadeZ = 0x41;
    do {
      *(float *)((int)aFadeTable + iz) = d_a_sea::1_0;
      iz = iz + 4;
      fadeZ = fadeZ + -1;
    } while (fadeZ != 0);
    aFadeTable[64] = d_a_sea::0_0;
    aFadeTable[0] = d_a_sea::0_0;
    aFadeTable[63] = d_a_sea::1_6;
    aFadeTable[1] = d_a_sea::1_6;
    aFadeTable[62] = d_a_sea::2_6;
    aFadeTable[2] = d_a_sea::2_6;
    aFadeTable[61] = d_a_sea::0_5;
    aFadeTable[3] = d_a_sea::0_5;
    aFadeTable[60] = d_a_sea::4_6;
    aFadeTable[4] = d_a_sea::4_6;
    aFadeTable[59] = d_a_sea::5_6;
    aFadeTable[5] = d_a_sea::5_6;
    iz = 1;
    fadeZ = 4;
    iVar2 = 0x104;
    do {
      pHeight = (float *)((int)this->mpHeightTable + iVar2 + 4);
      waveTheta0 = waveTheta0_Phase + iVar6;
      waveTheta1 = waveTheta1_Phase + iVar5;
      waveTheta2 = waveTheta2_Phase + iVar4;
      waveTheta3 = waveTheta3_Phase + iVar3;
      fadeX = 4;
      ix = 0x3f;
      do {
        *pHeight = BASE_HEIGHT +
                   aHeightTable[3] *
                   JKernel::JMath::jmaCosTable
                   [(int)(waveTheta3 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f)] +
                   aHeightTable[2] *
                   JKernel::JMath::jmaCosTable
                   [(int)(waveTheta2 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f)] +
                   aHeightTable[0] *
                   JKernel::JMath::jmaCosTable
                   [(int)(waveTheta0 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f)] +
                   aHeightTable[1] *
                   JKernel::JMath::jmaCosTable
                   [(int)(waveTheta1 & 0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f)];
        *pHeight = *pHeight *
                   *(float *)((int)aFadeTable + fadeZ) * *(float *)((int)aFadeTable + fadeX);
        waveTheta0 = waveTheta0 + waveTheta0_DeltaX;
        waveTheta1 = waveTheta1 + waveTheta1_DeltaX;
        waveTheta2 = waveTheta2 + waveTheta2_DeltaX;
        waveTheta3 = waveTheta3 + waveTheta3_DeltaX;
        pHeight = pHeight + 1;
        fadeX = fadeX + 4;
        ix = ix + -1;
      } while (ix != 0);
      iVar6 = iVar6 + waveTheta0_DeltaZ;
      iVar5 = iVar5 + waveTheta1_DeltaZ;
      iVar4 = iVar4 + iw;
      iVar3 = iVar3 + waveTheta3_DeltaZ;
      iz = iz + 1;
      fadeZ = fadeZ + 4;
      iVar2 = iVar2 + 0x104;
    } while (iz < 0x40);
    daSea_WaveInfo::AddCounter(&this->mWaveInfo);
    (this->mCurPos).x = param_2->x;
    (this->mCurPos).y = param_2->y;
    (this->mCurPos).z = param_2->z;
  }
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  __psq_l0(auStack24,uVar7);
  __psq_l1(auStack24,uVar7);
  __psq_l0(auStack40,uVar7);
  __psq_l1(auStack40,uVar7);
  __psq_l0(auStack56,uVar7);
  __psq_l1(auStack56,uVar7);
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Removing unreachable block (ram,0x8015d7e4) */
/* WARNING: Removing unreachable block (ram,0x8015d7d4) */
/* WARNING: Removing unreachable block (ram,0x8015d7c4) */
/* WARNING: Removing unreachable block (ram,0x8015d7cc) */
/* WARNING: Removing unreachable block (ram,0x8015d7dc) */
/* WARNING: Removing unreachable block (ram,0x8015d7ec) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall daSea_packet_c::draw(void) */

void __thiscall daSea_packet_c::draw(daSea_packet_c *this)

{
  bool bVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  float *pDrawVtx;
  ulong uVar6;
  TVec3_float_ *pVtx;
  _GXTexFmt *p_Var7;
  ResTIMG *pResTIMG;
  float *pHeightTable;
  int iVar8;
  uint difG;
  uint difB;
  short sVar9;
  short sVar10;
  int iVar11;
  undefined4 uVar12;
  double dVar13;
  undefined8 in_f26;
  double dVar14;
  double dVar15;
  undefined8 in_f27;
  double dVar16;
  undefined8 in_f28;
  double dVar17;
  double dVar18;
  undefined8 in_f29;
  double dVar19;
  undefined8 in_f30;
  undefined8 in_f31;
  double dVar20;
  undefined4 local_138;
  undefined4 local_134;
  _GXColor local_130;
  undefined4 local_12c;
  undefined4 local_128;
  _GXColor colorDif;
  _GXColor colorAmb;
  double local_90;
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  uint difR;
  
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
  if (this->mCullStopFlag != 1) {
    pDrawVtx = (float *)mDoGph_gInf_c::alloc(0xc60c,0x20);
    this->mpDrawVtx = (TVec3_float_ *)pDrawVtx;
    bVar1 = this->mpDrawVtx != (TVec3_float_ *)0x0;
    if (bVar1) {
      if (!bVar1) {
        uVar6 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar6,"d_a_sea.cpp",0x518,"m_draw_vtx != 0");
        m_Do_printf::OSPanic("d_a_sea.cpp",0x518,"Halt");
      }
      J3DSys::reinitGX(&J3DGraphBase::j3dSys);
      fVar2 = d_a_sea::800_0;
      pVtx = this->mpDrawVtx;
      pHeightTable = this->mpHeightTable;
      fVar3 = this->mDrawMinZ;
      iVar8 = 0;
      do {
        fVar4 = this->mDrawMinX;
        iVar11 = 0x41;
        do {
          pVtx->x = fVar4;
          pVtx->y = *pHeightTable;
          pVtx->z = fVar3;
          fVar4 = fVar4 + fVar2;
          pVtx = pVtx + 1;
          pHeightTable = pHeightTable + 1;
          iVar11 = iVar11 + -1;
        } while (iVar11 != 0);
        fVar3 = fVar3 + fVar2;
        iVar8 = iVar8 + 1;
      } while (iVar8 < 0x41);
      os::DCStoreRange(this->mpDrawVtx,0xc60c);
                    /* b_sea_tex0and2.bti */
      p_Var7 = (_GXTexFmt *)
               dRes_control_c::getRes
                         ("Always",0x6f,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40
                         );
                    /* Sea Tex obj 1 */
      gx::GXInitTexObj((GXTexObj *)&this->mTexSea0,p_Var7 + *(int *)(p_Var7 + 0x1c),
                       (uint)*(ushort *)(p_Var7 + 2),(uint)*(ushort *)(p_Var7 + 4),*p_Var7,p_Var7[6]
                       ,p_Var7[7],SUB41(1 - (uint)p_Var7[0x18] >> 0x1f,0));
      gx::GXInitTexObjLOD((double)(d_a_sea::0_125 *
                                  (float)((double)CONCAT44(0x43300000,
                                                           (int)(char)p_Var7[0x16] ^ 0x80000000) -
                                         d_a_sea::_4046)),
                          (double)(d_a_sea::0_125 *
                                  (float)((double)CONCAT44(0x43300000,
                                                           (int)(char)p_Var7[0x17] ^ 0x80000000) -
                                         d_a_sea::_4046)),(double)d_a_sea::_0_9,&this->mTexSea0,
                          p_Var7[0x14],p_Var7[0x15],p_Var7[0x12],p_Var7[0x11],p_Var7[0x13]);
                    /* Sea Tex obj 2 */
      gx::GXInitTexObj((GXTexObj *)&this->mTexSea1,p_Var7 + *(int *)(p_Var7 + 0x1c),
                       (uint)*(ushort *)(p_Var7 + 2),(uint)*(ushort *)(p_Var7 + 4),*p_Var7,p_Var7[6]
                       ,p_Var7[7],SUB41(1 - (uint)p_Var7[0x18] >> 0x1f,0));
      gx::GXInitTexObjLOD((double)(d_a_sea::0_125 *
                                  (float)((double)CONCAT44(0x43300000,
                                                           (int)(char)p_Var7[0x16] ^ 0x80000000) -
                                         d_a_sea::_4046)),
                          (double)(d_a_sea::0_125 *
                                  (float)((double)CONCAT44(0x43300000,
                                                           (int)(char)p_Var7[0x17] ^ 0x80000000) -
                                         d_a_sea::_4046)),(double)d_a_sea::1_0,&this->mTexSea1,
                          p_Var7[0x14],p_Var7[0x15],p_Var7[0x12],p_Var7[0x11],p_Var7[0x13]);
                    /* b_wyurayura_tex1.bti */
      pResTIMG = (ResTIMG *)
                 dRes_control_c::getRes
                           ("Always",0x70,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,
                            0x40);
      m_Do_lib::mDoLib_setResTimgObj(pResTIMG,&this->mpTexWyurayura,0,(GXTlutObj *)0x0);
      mtx::PSMTXScale((double)d_a_sea::1_5,(double)d_a_sea::1_5,(double)d_a_sea::1_0,
                      &mDoMtx_stack_c::now);
      gx::GXLoadTexMtxImm(&mDoMtx_stack_c::now,GX_TEXMTX0,1);
      gx::GXLoadTexObj((GXTexObj *)&this->mTexSea0,0);
      this->mAnimCounter = this->mAnimCounter + 1;
      if (300 < this->mAnimCounter) {
        this->mAnimCounter = 0;
      }
      mtx::PSMTXTrans((double)d_a_sea::0_0,
                      (double)((float)((double)CONCAT44(0x43300000,
                                                        (int)this->mAnimCounter ^ 0x80000000) -
                                      d_a_sea::_4046) / d_a_sea::300_0),(double)d_a_sea::0_0,
                      &mDoMtx_stack_c::now);
      gx::GXLoadTexMtxImm(&mDoMtx_stack_c::now,GX_TEXMTX1,1);
      gx::GXLoadTexObj((GXTexObj *)&this->mpTexWyurayura,1);
      gx::GXSetIndTexOrder(0,1,1);
      d_a_sea::offset_4646[0] = d_a_sea::_4963;
      d_a_sea::offset_4646[1] = d_a_sea::0_0;
      d_a_sea::offset_4646[2] = d_a_sea::0_0;
      d_a_sea::offset_4646[3] = d_a_sea::0_0;
      d_a_sea::offset_4646[4] = d_a_sea::_4963;
      d_a_sea::offset_4646[5] = d_a_sea::0_0;
      gx::GXSetIndTexMtx(GX_ITM_0,(float (*) [6])d_a_sea::offset_4646,-1);
      gx::GXSetTevIndWarp(0,0,1,0,1);
      gx::GXSetTevIndWarp(1,0,1,0,1);
      mtx::PSMTXTrans((double)d_a_sea::_4964,(double)d_a_sea::_4965,(double)d_a_sea::0_0,
                      &mDoMtx_stack_c::now);
      gx::GXLoadTexMtxImm(&mDoMtx_stack_c::now,GX_TEXMTX2,1);
      gx::GXLoadTexObj((GXTexObj *)&this->mTexSea1,2);
      d_kankyo::dKy_get_seacolor(&colorAmb,&colorDif);
      fVar3 = this->mFlatInter * this->mFlatInter;
      difR = (uint)colorDif >> 0x18;
      difG = (uint)colorDif >> 0x10 & 0xff;
      difB = (uint)colorDif >> 8 & 0xff;
      local_128 = CONCAT31(CONCAT21(CONCAT11((char)(int)((float)((double)CONCAT44(0x43300000,difR) -
                                                                d_a_sea::_4977) +
                                                        fVar3 * ((float)((double)CONCAT44(0x43300000
                                                                                          ,(uint)
                                                  colorAmb.r) - d_a_sea::_4977) -
                                                  (float)((double)CONCAT44(0x43300000,difR) -
                                                         d_a_sea::_4977))),
                                             (char)(int)((float)((double)CONCAT44(0x43300000,difG) -
                                                                d_a_sea::_4977) +
                                                        fVar3 * ((float)((double)CONCAT44(0x43300000
                                                                                          ,(uint)
                                                  colorAmb.g) - d_a_sea::_4977) -
                                                  (float)((double)CONCAT44(0x43300000,difG) -
                                                         d_a_sea::_4977)))),
                                    (char)(int)((float)((double)CONCAT44(0x43300000,difB) -
                                                       d_a_sea::_4977) +
                                               fVar3 * ((float)((double)CONCAT44(0x43300000,
                                                                                 (uint)colorAmb.b) -
                                                               d_a_sea::_4977) -
                                                       (float)((double)CONCAT44(0x43300000,difB) -
                                                              d_a_sea::_4977)))),0xff);
      fVar3 = d_a_sea::1_0 - d_a_sea::0_1 * fVar3;
      fVar2 = (float)((double)CONCAT44(0x43300000,difR) - d_a_sea::_4977) * fVar3;
      fVar4 = (float)((double)CONCAT44(0x43300000,difG) - d_a_sea::_4977) * fVar3;
      fVar3 = (float)((double)CONCAT44(0x43300000,difB) - d_a_sea::_4977) * fVar3;
      if (d_a_sea::255_0 < fVar2) {
        fVar2 = d_a_sea::255_0;
      }
      if (d_a_sea::255_0 < fVar4) {
        fVar4 = d_a_sea::255_0;
      }
      if (d_a_sea::255_0 < fVar3) {
        fVar3 = d_a_sea::255_0;
      }
      local_12c = CONCAT31(CONCAT21(CONCAT11((char)(int)fVar2,(char)(int)fVar4),(char)(int)fVar3),
                           0xff);
      local_130 = colorDif;
      gx::GXSetTevColor(GX_TEVREG0,&local_130);
      gx::GXSetTevKColorSel(0,0xc);
      gx::GXSetTevKColorSel(1,0xd);
      local_134 = local_128;
      gx::GXSetTevKColor(0,&local_134);
      local_138 = local_12c;
      gx::GXSetTevKColor(1,&local_138);
      gx::GXSetNumIndStages(1);
      gx::GXSetNumChans(0);
      gx::GXSetNumTexGens(3);
      gx::GXSetNumTevStages(3);
      gx::GXSetCullMode(2);
      gx::GXSetCoPlanar(0);
      gx::GXSetTexCoordGen2(GX_TEXCOORD0,GX_TG_MTX2x4,GX_TG_TEX0,GX_TEXMTX0,false,GX_PTIDENTITY);
      gx::GXSetTexCoordGen2(GX_TEXCOORD1,GX_TG_MTX2x4,GX_TG_TEX0,GX_TEXMTX1,false,GX_PTIDENTITY);
      gx::GXSetTexCoordGen2(GX_TEXCOORD2,GX_TG_MTX2x4,GX_TG_TEX0,GX_TEXMTX2,false,GX_PTIDENTITY);
      gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD0,GX_TEXMAP0,GX_COLOR_NULL);
      gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_C0,GX_CC_KONST,GX_CC_TEXC,GX_CC_ZERO);
      gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVREG2);
      gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_KONST,GX_CA_TEXA,GX_CA_ZERO);
      gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
      gx::GXSetTevSwapMode(0,0,0);
      gx::GXSetTevOrder(GX_TEVSTAGE1,GX_TEXCOORD2,GX_TEXMAP2,GX_COLOR_NULL);
      gx::GXSetTevColorIn(GX_TEVSTAGE1,GX_CC_C0,GX_CC_KONST,GX_CC_TEXC,GX_CC_ZERO);
      gx::GXSetTevColorOp(GX_TEVSTAGE1,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
      gx::GXSetTevAlphaIn(GX_TEVSTAGE1,GX_CA_APREV,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO);
      gx::GXSetTevAlphaOp(GX_TEVSTAGE1,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
      gx::GXSetTevSwapMode(1,0,0);
      gx::GXSetTevOrder(GX_TEVSTAGE2,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR_NULL);
      gx::GXSetTevColorIn(GX_TEVSTAGE2,GX_CC_CPREV,GX_CC_C2,GX_CC_APREV,GX_CC_ZERO);
      gx::GXSetTevColorOp(GX_TEVSTAGE2,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
      gx::GXSetTevAlphaIn(GX_TEVSTAGE2,GX_CA_ZERO,GX_CA_KONST,GX_CA_APREV,GX_CA_ZERO);
      gx::GXSetTevAlphaOp(GX_TEVSTAGE2,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
      gx::GXSetTevSwapMode(2,0,0);
      gx::GXSetAlphaCompare(GX_ALWAYS,0,GX_AOP_OR,GX_ALWAYS,0);
      gx::GXSetZCompLoc(1);
      gx::GXSetPixelFmt(1,0);
      gx::GXSetZMode(true,GX_LEQUAL,true);
      gx::GXSetBlendMode(GX_BM_NONE,GX_BL_ZERO,GX_BL_ZERO,GX_LO_CLEAR);
      gx::GXSetColorUpdate(true);
      gx::GXSetAlphaUpdate(0);
      gx::GXSetDither(1);
      d_kankyo::dKy_GxFog_sea_set();
      gx::GXLoadPosMtxImm(&J3DGraphBase::j3dSys.mCurViewMtx,0);
      gx::GXSetClipMode(false);
      gx::GXClearVtxDesc();
      gx::GXSetVtxDesc(GX_VA_POS,GX_INDEX16);
      gx::GXSetVtxDesc(GX_VA_TEX0,GX_DIRECT);
      gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_F32,0);
      gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX0,GX_CLR_RGBA,GX_F32,0);
      gx::GXSetArray(GX_VA_POS,this->mpDrawVtx,0xc);
      sVar9 = 0;
      sVar10 = 0x41;
      pVtx = this->mpDrawVtx;
      dVar17 = (double)d_a_sea::_4968;
      iVar8 = 0;
      dVar16 = (double)d_a_sea::800_0;
      dVar13 = (double)(float)(dVar17 * (double)pVtx->z);
      do {
        dVar14 = (double)(float)(dVar17 * (double)(float)(dVar16 + (double)pVtx->z));
        dVar19 = dVar13;
        gx::GXBegin(0x98,0,0x82);
        iVar11 = 0x41;
        do {
          fVar3 = (float)(dVar17 * (double)pVtx->x);
          write_volatile_2(0xcc008000,sVar10);
          write_volatile_4(0xcc008000,fVar3);
          write_volatile_4(0xcc008000,(float)dVar14);
          write_volatile_2(0xcc008000,sVar9);
          write_volatile_4(0xcc008000,fVar3);
          write_volatile_4(0xcc008000,(float)dVar19);
          sVar9 = sVar9 + 1;
          sVar10 = sVar10 + 1;
          pVtx = pVtx + 1;
          iVar11 = iVar11 + -1;
        } while (iVar11 != 0);
        iVar8 = iVar8 + 1;
        dVar13 = dVar14;
      } while (iVar8 < 0x40);
      gx::GXClearVtxDesc();
      gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
      gx::GXSetVtxDesc(GX_VA_TEX0,GX_DIRECT);
      dVar13 = (double)d_a_sea::_450000_0;
      if (dVar13 < (double)this->mDrawMinZ) {
        dVar18 = (double)d_a_sea::225000_0;
        dVar16 = (double)(float)((double)this->mDrawMinZ - dVar13) / dVar18;
        dVar14 = (double)d_a_sea::_4968;
        dVar17 = (double)d_a_sea::_225_0;
        for (iVar8 = 0; iVar8 < (int)dVar16; iVar8 = iVar8 + 1) {
          dVar20 = (double)(float)(dVar18 + dVar13);
          dVar15 = (double)(float)(dVar14 * dVar20);
          dVar19 = dVar17;
          gx::GXBegin(0x98,0,10);
          iVar11 = 5;
          fVar3 = d_a_sea::_450000_0;
          do {
            fVar2 = (float)(dVar14 * (double)fVar3);
            write_volatile_4(0xcc008000,fVar3);
            write_volatile_4(0xcc008000,BASE_HEIGHT);
            write_volatile_4(0xcc008000,(float)dVar20);
            write_volatile_4(0xcc008000,fVar2);
            write_volatile_4(0xcc008000,(float)dVar15);
            write_volatile_4(0xcc008000,fVar3);
            write_volatile_4(0xcc008000,BASE_HEIGHT);
            write_volatile_4(0xcc008000,(float)dVar13);
            write_volatile_4(0xcc008000,fVar2);
            write_volatile_4(0xcc008000,(float)dVar19);
            fVar3 = (float)((double)fVar3 + dVar18);
            iVar11 = iVar11 + -1;
          } while (iVar11 != 0);
          dVar13 = (double)(float)(dVar13 + dVar18);
          dVar17 = dVar15;
        }
        if (dVar13 < (double)this->mDrawMinZ) {
          dVar16 = (double)(float)((double)d_a_sea::_4968 * (double)this->mDrawMinZ);
          gx::GXBegin(0x98,0,10);
          iVar8 = 5;
          fVar3 = d_a_sea::_450000_0;
          do {
            write_volatile_4(0xcc008000,fVar3);
            write_volatile_4(0xcc008000,BASE_HEIGHT);
            write_volatile_4(0xcc008000,this->mDrawMinZ);
            write_volatile_4(0xcc008000,d_a_sea::_4968 * fVar3);
            write_volatile_4(0xcc008000,(float)dVar16);
            write_volatile_4(0xcc008000,fVar3);
            write_volatile_4(0xcc008000,BASE_HEIGHT);
            write_volatile_4(0xcc008000,(float)dVar13);
            write_volatile_4(0xcc008000,d_a_sea::_4968 * fVar3);
            write_volatile_4(0xcc008000,(float)dVar17);
            fVar3 = fVar3 + d_a_sea::225000_0;
            iVar8 = iVar8 + -1;
            dVar19 = dVar17;
          } while (iVar8 != 0);
        }
      }
      dVar13 = (double)this->mDrawMaxZ;
      if (dVar13 < (double)d_a_sea::450000_0) {
        dVar18 = (double)d_a_sea::225000_0;
        dVar16 = (double)(float)((double)d_a_sea::450000_0 - dVar13) / dVar18;
        dVar14 = (double)d_a_sea::_4968;
        dVar17 = (double)(float)(dVar14 * dVar13);
        for (iVar8 = 0; iVar8 < (int)dVar16; iVar8 = iVar8 + 1) {
          dVar20 = (double)(float)(dVar18 + dVar13);
          dVar15 = (double)(float)(dVar14 * dVar20);
          dVar19 = dVar17;
          gx::GXBegin(0x98,0,10);
          iVar11 = 5;
          fVar3 = d_a_sea::_450000_0;
          do {
            fVar2 = (float)(dVar14 * (double)fVar3);
            write_volatile_4(0xcc008000,fVar3);
            write_volatile_4(0xcc008000,BASE_HEIGHT);
            write_volatile_4(0xcc008000,(float)dVar20);
            write_volatile_4(0xcc008000,fVar2);
            write_volatile_4(0xcc008000,(float)dVar15);
            write_volatile_4(0xcc008000,fVar3);
            write_volatile_4(0xcc008000,BASE_HEIGHT);
            write_volatile_4(0xcc008000,(float)dVar13);
            write_volatile_4(0xcc008000,fVar2);
            write_volatile_4(0xcc008000,(float)dVar19);
            fVar3 = (float)((double)fVar3 + dVar18);
            iVar11 = iVar11 + -1;
          } while (iVar11 != 0);
          dVar13 = (double)(float)(dVar13 + dVar18);
          dVar17 = dVar15;
        }
        if (dVar13 < (double)d_a_sea::450000_0) {
          gx::GXBegin(0x98,0,10);
          iVar8 = 5;
          fVar3 = d_a_sea::_450000_0;
          do {
            write_volatile_4(0xcc008000,fVar3);
            write_volatile_4(0xcc008000,BASE_HEIGHT);
            write_volatile_4(0xcc008000,d_a_sea::450000_0);
            write_volatile_4(0xcc008000,d_a_sea::_4968 * fVar3);
            write_volatile_4(0xcc008000,d_a_sea::_4972);
            write_volatile_4(0xcc008000,fVar3);
            write_volatile_4(0xcc008000,BASE_HEIGHT);
            write_volatile_4(0xcc008000,(float)dVar13);
            write_volatile_4(0xcc008000,d_a_sea::_4968 * fVar3);
            write_volatile_4(0xcc008000,(float)dVar17);
            fVar3 = fVar3 + d_a_sea::225000_0;
            iVar8 = iVar8 + -1;
            dVar19 = dVar17;
          } while (iVar8 != 0);
        }
      }
      dVar13 = (double)this->mDrawMinZ;
      if (dVar13 < (double)this->mDrawMaxZ) {
        iVar8 = (int)((float)((double)this->mDrawMaxZ - dVar13) / d_a_sea::225000_0);
        if (d_a_sea::_450000_0 < this->mDrawMinX) {
          fVar3 = this->mDrawMinX - d_a_sea::_450000_0;
          difR = (uint)(fVar3 / d_a_sea::225000_0);
          local_90 = (double)CONCAT44(0x43300000,difR ^ 0x80000000);
          difB = (uint)(d_a_sea::225000_0 * (float)(local_90 - d_a_sea::_4046) < fVar3);
          dVar18 = (double)d_a_sea::_4968;
          difG = (difR + difB + 1) * 2;
          dVar14 = (double)d_a_sea::_4972;
          dVar17 = (double)d_a_sea::225000_0;
          dVar16 = (double)(float)(dVar18 * dVar13);
          for (iVar11 = 0; iVar11 < iVar8; iVar11 = iVar11 + 1) {
            dVar15 = (double)d_a_sea::_4972;
            dVar19 = dVar16;
            gx::GXBegin(0x98,0,difG & 0xfffe);
            iVar5 = difR + 1;
            fVar3 = d_a_sea::_450000_0;
            if (-1 < (int)difR) {
              do {
                fVar2 = (float)(dVar18 * (double)fVar3);
                write_volatile_4(0xcc008000,fVar3);
                write_volatile_4(0xcc008000,BASE_HEIGHT);
                write_volatile_4(0xcc008000,(float)(dVar17 + dVar13));
                write_volatile_4(0xcc008000,fVar2);
                write_volatile_4(0xcc008000,(float)dVar14);
                write_volatile_4(0xcc008000,fVar3);
                write_volatile_4(0xcc008000,BASE_HEIGHT);
                write_volatile_4(0xcc008000,(float)dVar13);
                write_volatile_4(0xcc008000,fVar2);
                write_volatile_4(0xcc008000,(float)dVar19);
                fVar3 = (float)((double)fVar3 + dVar17);
                iVar5 = iVar5 + -1;
              } while (iVar5 != 0);
            }
            if (difB != 0) {
              fVar3 = d_a_sea::_4968 * this->mDrawMinX;
              write_volatile_4(0xcc008000,this->mDrawMinX);
              write_volatile_4(0xcc008000,BASE_HEIGHT);
              write_volatile_4(0xcc008000,(float)(dVar17 + dVar13));
              write_volatile_4(0xcc008000,fVar3);
              write_volatile_4(0xcc008000,d_a_sea::_4972);
              write_volatile_4(0xcc008000,this->mDrawMinX);
              write_volatile_4(0xcc008000,BASE_HEIGHT);
              write_volatile_4(0xcc008000,(float)dVar13);
              write_volatile_4(0xcc008000,fVar3);
              write_volatile_4(0xcc008000,(float)dVar19);
            }
            dVar13 = (double)(float)(dVar13 + dVar17);
            dVar16 = dVar15;
          }
          if (dVar13 < (double)this->mDrawMaxZ) {
            dVar17 = (double)(float)((double)d_a_sea::_4968 * (double)this->mDrawMaxZ);
            gx::GXBegin(0x98,0,difG & 0xfffe);
            iVar11 = difR + 1;
            fVar3 = d_a_sea::_450000_0;
            if (-1 < (int)difR) {
              do {
                write_volatile_4(0xcc008000,fVar3);
                write_volatile_4(0xcc008000,BASE_HEIGHT);
                write_volatile_4(0xcc008000,this->mDrawMaxZ);
                write_volatile_4(0xcc008000,d_a_sea::_4968 * fVar3);
                write_volatile_4(0xcc008000,(float)dVar17);
                write_volatile_4(0xcc008000,fVar3);
                write_volatile_4(0xcc008000,BASE_HEIGHT);
                write_volatile_4(0xcc008000,(float)dVar13);
                write_volatile_4(0xcc008000,d_a_sea::_4968 * fVar3);
                write_volatile_4(0xcc008000,(float)dVar16);
                fVar3 = fVar3 + d_a_sea::225000_0;
                iVar11 = iVar11 + -1;
              } while (iVar11 != 0);
            }
            dVar19 = dVar16;
            if (difB != 0) {
              fVar3 = d_a_sea::_4968 * this->mDrawMinX;
              write_volatile_4(0xcc008000,this->mDrawMinX);
              write_volatile_4(0xcc008000,BASE_HEIGHT);
              write_volatile_4(0xcc008000,this->mDrawMaxZ);
              write_volatile_4(0xcc008000,fVar3);
              write_volatile_4(0xcc008000,(float)dVar17);
              write_volatile_4(0xcc008000,this->mDrawMinX);
              write_volatile_4(0xcc008000,BASE_HEIGHT);
              write_volatile_4(0xcc008000,(float)dVar13);
              write_volatile_4(0xcc008000,fVar3);
              write_volatile_4(0xcc008000,(float)dVar16);
            }
          }
        }
        if (this->mDrawMaxX < d_a_sea::450000_0) {
          fVar3 = d_a_sea::450000_0 - this->mDrawMaxX;
          difR = (uint)(fVar3 / d_a_sea::225000_0);
          local_90 = (double)CONCAT44(0x43300000,difR ^ 0x80000000);
          difB = (uint)(d_a_sea::225000_0 * (float)(local_90 - d_a_sea::_4046) < fVar3);
          dVar17 = (double)this->mDrawMinZ;
          dVar13 = (double)d_a_sea::_4968;
          dVar14 = (double)(float)(dVar13 * dVar17);
          difG = (difR + difB + 1) * 2;
          dVar16 = (double)d_a_sea::225000_0;
          for (iVar11 = 0; iVar11 < iVar8; iVar11 = iVar11 + 1) {
            gx::GXBegin(0x98,0,difG & 0xfffe);
            fVar3 = this->mDrawMaxX;
            iVar5 = difR + 1;
            if (-1 < (int)difR) {
              do {
                fVar2 = (float)(dVar13 * (double)fVar3);
                write_volatile_4(0xcc008000,fVar3);
                write_volatile_4(0xcc008000,BASE_HEIGHT);
                write_volatile_4(0xcc008000,(float)(dVar16 + dVar17));
                write_volatile_4(0xcc008000,fVar2);
                write_volatile_4(0xcc008000,(float)dVar14);
                write_volatile_4(0xcc008000,fVar3);
                write_volatile_4(0xcc008000,BASE_HEIGHT);
                write_volatile_4(0xcc008000,(float)dVar17);
                write_volatile_4(0xcc008000,fVar2);
                write_volatile_4(0xcc008000,(float)dVar19);
                fVar3 = (float)((double)fVar3 + dVar16);
                iVar5 = iVar5 + -1;
              } while (iVar5 != 0);
            }
            if (difB != 0) {
              write_volatile_4(0xcc008000,d_a_sea::450000_0);
              write_volatile_4(0xcc008000,BASE_HEIGHT);
              write_volatile_4(0xcc008000,(float)(dVar16 + dVar17));
              write_volatile_4(0xcc008000,d_a_sea::_4972);
              write_volatile_4(0xcc008000,(float)dVar14);
              write_volatile_4(0xcc008000,d_a_sea::450000_0);
              write_volatile_4(0xcc008000,BASE_HEIGHT);
              write_volatile_4(0xcc008000,(float)dVar17);
              write_volatile_4(0xcc008000,d_a_sea::_4972);
              write_volatile_4(0xcc008000,(float)dVar19);
            }
            dVar17 = (double)(float)(dVar17 + dVar16);
          }
          if (dVar17 < (double)this->mDrawMaxZ) {
            dVar13 = (double)(float)((double)d_a_sea::_4968 * (double)this->mDrawMaxZ);
            gx::GXBegin(0x98,0,difG & 0xfffe);
            fVar3 = this->mDrawMaxX;
            iVar8 = difR + 1;
            if (-1 < (int)difR) {
              do {
                write_volatile_4(0xcc008000,fVar3);
                write_volatile_4(0xcc008000,BASE_HEIGHT);
                write_volatile_4(0xcc008000,this->mDrawMaxZ);
                write_volatile_4(0xcc008000,d_a_sea::_4968 * fVar3);
                write_volatile_4(0xcc008000,(float)dVar13);
                write_volatile_4(0xcc008000,fVar3);
                write_volatile_4(0xcc008000,BASE_HEIGHT);
                write_volatile_4(0xcc008000,(float)dVar17);
                write_volatile_4(0xcc008000,d_a_sea::_4968 * fVar3);
                write_volatile_4(0xcc008000,(float)dVar14);
                fVar3 = fVar3 + d_a_sea::225000_0;
                iVar8 = iVar8 + -1;
              } while (iVar8 != 0);
            }
            if (difB != 0) {
              write_volatile_4(0xcc008000,d_a_sea::450000_0);
              write_volatile_4(0xcc008000,BASE_HEIGHT);
              write_volatile_4(0xcc008000,this->mDrawMaxZ);
              write_volatile_4(0xcc008000,d_a_sea::_4972);
              write_volatile_4(0xcc008000,(float)dVar13);
              write_volatile_4(0xcc008000,d_a_sea::450000_0);
              write_volatile_4(0xcc008000,BASE_HEIGHT);
              write_volatile_4(0xcc008000,(float)dVar17);
              write_volatile_4(0xcc008000,d_a_sea::_4972);
              write_volatile_4(0xcc008000,(float)dVar14);
            }
          }
        }
      }
      gx::GXSetNumIndStages(0);
      _sOldVcdVatCmd = 0;
    }
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
  return;
}


namespace d_a_sea {

/* __stdcall daSea_Draw(sea_class *) */

undefined4 daSea_Draw(void)

{
  J3DGraphBase::j3dSys.mpCurDrawBuffers[0] =
       d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufSkyOpa;
  J3DGraphBase::j3dSys.mpCurDrawBuffers[1] =
       d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufSkyXlu;
  J3DDrawBuffer::entryImm
            (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufSkyXlu,&l_cloth.parent,0x1f);
  J3DGraphBase::j3dSys.mpCurDrawBuffers[0] =
       d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelOpa;
  J3DGraphBase::j3dSys.mpCurDrawBuffers[1] =
       d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelXlu;
  return 1;
}


/* __stdcall daSea_Execute(sea_class *) */

undefined4 daSea_Execute(void)

{
  cXyz pos;
  
  pos.x = ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).parent.mCurrent.mPos
          .x;
  pos.y = ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).parent.mCurrent.mPos
          .y;
  pos.z = ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).parent.mCurrent.mPos
          .z;
  ::daSea_packet_c::execute(&l_cloth,&pos);
  return 1;
}


/* __stdcall daSea_IsDelete(sea_class *) */

undefined4 daSea_IsDelete(void)

{
  l_cloth.mbIsDelete = 0;
  return 1;
}


/* __stdcall daSea_Delete(sea_class *) */

undefined4 daSea_Delete(void)

{
  return 1;
}


/* __stdcall CheckCreateHeap(fopAc_ac_c *) */

undefined CheckCreateHeap(fopAc_ac_c *param_1)

{
  undefined uVar1;
  
  uVar1 = ::daSea_packet_c::create(&l_cloth,&(param_1->mCurrent).mPos);
  return uVar1;
}


/* __stdcall daSea_Create(fopAc_ac_c *) */

undefined4 daSea_Create(fopAc_ac_c *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  if ((param_1->mCondition & Constructed) == 0) {
    if (param_1 != (fopAc_ac_c *)0x0) {
      fopAc_ac_c::fopAc_ac_c(param_1);
    }
    param_1->mCondition = param_1->mCondition | Constructed;
  }
  uVar1 = f_op_actor_mng::fopAcM_entrySolidHeap(param_1,CheckCreateHeap,0xa000);
  if ((uVar1 & 0xff) == 0) {
    uVar2 = 5;
  }
  else {
    uVar2 = 4;
  }
  return uVar2;
}

}

/* __thiscall daSea_WaterHeightInfo_Mng::~daSea_WaterHeightInfo_Mng(void) */

void __thiscall
daSea_WaterHeightInfo_Mng::_daSea_WaterHeightInfo_Mng(daSea_WaterHeightInfo_Mng *this)

{
  short in_r4;
  
  if ((this != (daSea_WaterHeightInfo_Mng *)0x0) && (this->vtbl = (undefined *)&__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall daSea_packet_c::~daSea_packet_c(void) */

void __thiscall daSea_packet_c::_daSea_packet_c(daSea_packet_c *this)

{
  short in_r4;
  
  if (this != (daSea_packet_c *)0x0) {
    (this->parent).vtbl = &__vt;
    daSea_WaveInfo::_daSea_WaveInfo(&this->mWaveInfo);
    if (this != (daSea_packet_c *)0xfffffff0) {
      (this->mWaterHeightMgr).vtbl = (undefined *)&daSea_WaterHeightInfo_Mng::__vt;
    }
    if (this != (daSea_packet_c *)0x0) {
      (this->parent).vtbl = (undefined *)&J3DPacket::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


namespace d_a_sea {

void __sinit_d_a_sea_cpp(void)

{
  ::daSea_packet_c::daSea_packet_c(&l_cloth);
  Runtime.PPCEABI.H::__register_global_object();
  return;
}

}

/* __thiscall cM2dGBox::~cM2dGBox(void) */

void __thiscall cM2dGBox::_cM2dGBox(cM2dGBox *this)

{
  short in_r4;
  
  if ((this != (cM2dGBox *)0x0) && (this[1].x0 = (float)&__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}

