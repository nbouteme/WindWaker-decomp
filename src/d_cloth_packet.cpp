#include <d_cloth_packet.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <gx/GXTexture.h>
#include <d_cloth_packet.h>
#include <JKernel/JKRHeap.h>
#include <m_Do_ext.h>
#include <m_Do_mtx.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <os/OSCache.h>
#include <mtx/mtx.h>
#include <mtx/mtxvec.h>
#include <mtx/vec.h>
#include <J3DGraphBase/J3DSys.h>
#include <gx/GXBump.h>
#include <d_kankyo.h>
#include <gx/GXAttr.h>
#include <gx/GXTransform.h>
#include <gx/GXGeometry.h>
#include <SComponent/c_xyz.h>
#include <J3DGraphBase/J3DDrawBuffer.h>
#include <gx/GXLight.h>
#include <gx/GXTev.h>
#include <gx/GXDisplayList.h>
#include <d_drawlist.h>
#include <cXyz.h>
#include <dClothVobj03_c.h>
#include <dClothVobj05_c.h>
#include <dClothVobj04_c.h>
#include <dCloth_packet_c.h>
#include <dCloth_packetXlu_c.h>
#include <dClothVobj07_0_c.h>

undefined1 dClothVobj03_c;
undefined1 dClothVobj04_c;
undefined1 dClothVobj05_c;
undefined1 dClothVobj07_0_c;

/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x80063088) */
/* WARNING: Removing unreachable block (ram,0x80063090) */
/* __thiscall dCloth_packet_c::dCloth_packet_c(ResTIMG *,
                                               int,
                                               int,
                                               float,
                                               float,
                                               dKy_tevstr_c *,
                                               cXyz * *) */

void __thiscall
dCloth_packet_c::dCloth_packet_c
          (dCloth_packet_c *this,ResTIMG *pToonImage,int flyGridSize,int hoistGridSize,
          float flyLength,float hoistLength,dKy_tevstr_c *param_6,cXyz **pPosArr)

{
  ulong uVar1;
  undefined4 uVar2;
  cXyz *pcVar3;
  int iVar4;
  undefined4 uVar5;
  double dVar6;
  double dVar7;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar7 = (double)hoistLength;
  dVar6 = (double)flyLength;
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  (this->parent).vtbl = (undefined *)&J3DPacket::__vt;
  (this->parent).mpNextSibling = (J3DPacket *)0x0;
  (this->parent).mpFirstChild = (J3DPacket *)0x0;
  (this->parent).field_0xc = (undefined *)0x0;
  (this->parent).vtbl = (undefined *)&__vt;
  if (pToonImage == (ResTIMG *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_cloth_packet.cpp",0x2b,"i_toonimage != 0");
    m_Do_printf::OSPanic("d_cloth_packet.cpp",0x2b,&DAT_8034fbac);
  }
  gx::GXInitTexObj(&this->mToonTex,&pToonImage->mTexFmt + pToonImage->mTexDataOffs,
                   (uint)pToonImage->mWidth,(uint)pToonImage->mHeight,pToonImage->mTexFmt,
                   pToonImage->mWrapS,pToonImage->mWrapT,
                   SUB41(1 - (uint)pToonImage->mMipmapCount >> 0x1f,0));
  gx::GXInitTexObjLOD((double)(d_cloth_packet::0_125 *
                              (float)((double)CONCAT44(0x43300000,
                                                       (int)(char)pToonImage->mMinLOD ^ 0x80000000)
                                     - d_cloth_packet::_4065)),
                      (double)(d_cloth_packet::0_125 *
                              (float)((double)CONCAT44(0x43300000,
                                                       (int)(char)pToonImage->mMaxLOD ^ 0x80000000)
                                     - d_cloth_packet::_4065)),
                      (double)(d_cloth_packet::0_01 *
                              (float)((double)CONCAT44(0x43300000,
                                                       (int)pToonImage->mLODBias ^ 0x80000000) -
                                     d_cloth_packet::_4065)),&this->mTexObj,pToonImage->mMinFilter,
                      pToonImage->mMagFilter,pToonImage->mbBiasClamp,pToonImage->mbDoEdgeLOD,
                      pToonImage->mMaxAniso);
  this->mFlyGridSize = flyGridSize;
  this->mHoistGridSize = hoistGridSize;
  this->mFlyLength = (float)dVar6;
  this->mHoistLength = (float)dVar7;
  this->mpTevstr = param_6;
  this->mCurArr = 0;
  setMtx(this,&m_Do_mtx::g_mDoMtx_identity);
  if (pPosArr == (cXyz **)0x0) {
    iVar4 = this->mFlyGridSize * this->mHoistGridSize;
    uVar2 = JKernel::operator_new__(iVar4 * 0xc + 0x10);
    pcVar3 = (cXyz *)Runtime.PPCEABI.H::__construct_new_array
                               (uVar2,::cXyz::cXyz,::cXyz::_cXyz,0xc,iVar4);
    this->mpPosArr[0] = pcVar3;
    iVar4 = this->mFlyGridSize * this->mHoistGridSize;
    uVar2 = JKernel::operator_new__(iVar4 * 0xc + 0x10);
    pcVar3 = (cXyz *)Runtime.PPCEABI.H::__construct_new_array
                               (uVar2,::cXyz::cXyz,::cXyz::_cXyz,0xc,iVar4);
    this->mpPosArr[1] = pcVar3;
  }
  else {
    this->mpPosArr[0] = *pPosArr;
    this->mpPosArr[1] = pPosArr[1];
  }
  iVar4 = this->mFlyGridSize * this->mHoistGridSize;
  uVar2 = JKernel::operator_new__(iVar4 * 0xc + 0x10);
  pcVar3 = (cXyz *)Runtime.PPCEABI.H::__construct_new_array
                             (uVar2,::cXyz::cXyz,::cXyz::_cXyz,0xc,iVar4);
  this->mpNrmArr[0] = pcVar3;
  iVar4 = this->mFlyGridSize * this->mHoistGridSize;
  uVar2 = JKernel::operator_new__(iVar4 * 0xc + 0x10);
  pcVar3 = (cXyz *)Runtime.PPCEABI.H::__construct_new_array
                             (uVar2,::cXyz::cXyz,::cXyz::_cXyz,0xc,iVar4);
  this->mpNrmArr[1] = pcVar3;
  iVar4 = this->mFlyGridSize * this->mHoistGridSize;
  uVar2 = JKernel::operator_new__(iVar4 * 0xc + 0x10);
  pcVar3 = (cXyz *)Runtime.PPCEABI.H::__construct_new_array
                             (uVar2,::cXyz::cXyz,::cXyz::_cXyz,0xc,iVar4);
  this->mpNrmArrBack[0] = pcVar3;
  iVar4 = this->mFlyGridSize * this->mHoistGridSize;
  uVar2 = JKernel::operator_new__(iVar4 * 0xc + 0x10);
  pcVar3 = (cXyz *)Runtime.PPCEABI.H::__construct_new_array
                             (uVar2,::cXyz::cXyz,::cXyz::_cXyz,0xc,iVar4);
  this->mpNrmArrBack[1] = pcVar3;
  iVar4 = this->mFlyGridSize * this->mHoistGridSize;
  uVar2 = JKernel::operator_new__(iVar4 * 0xc + 0x10);
  pcVar3 = (cXyz *)Runtime.PPCEABI.H::__construct_new_array
                             (uVar2,::cXyz::cXyz,::cXyz::_cXyz,0xc,iVar4);
  this->mpSpeedArr = pcVar3;
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  __psq_l0(auStack24,uVar5);
  __psq_l1(auStack24,uVar5);
  return;
}


/* __thiscall dCloth_packet_c::~dCloth_packet_c(void) */

void __thiscall dCloth_packet_c::_dCloth_packet_c(dCloth_packet_c *this)

{
  short in_r4;
  
  if (this != (dCloth_packet_c *)0x0) {
    (this->parent).vtbl = (undefined *)&__vt;
    if (this != (dCloth_packet_c *)0x0) {
      (this->parent).vtbl = (undefined *)&J3DPacket::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


namespace d_cloth_packet {

/* __stdcall default_factor_checkCB(dCloth_packet_c *,
                                    int,
                                    int) */

undefined4 default_factor_checkCB(dCloth_packet_c *pPkt,int x,int y)

{
  if ((x == 0) && ((y == 0 || (y == pPkt->mHoistGridSize + -1)))) {
    return 1;
  }
  return 0;
}

}

/* __thiscall dCloth_packet_c::init(void) */

int __thiscall dCloth_packet_c::init(dCloth_packet_c *this)

{
  float fVar1;
  float fVar2;
  double dVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  cXyz *pcVar7;
  cXyz *pcVar8;
  cXyz *pcVar9;
  int iVar10;
  uint uVar11;
  
  fVar4 = d_cloth_packet::0_0;
  dVar3 = d_cloth_packet::_4065;
  pcVar7 = this->mpPosArr[0];
  pcVar8 = this->mpPosArr[1];
  pcVar9 = this->mpSpeedArr;
  for (iVar10 = 0; iVar10 < this->mHoistGridSize; iVar10 = iVar10 + 1) {
    for (uVar11 = 0; iVar6 = this->mFlyGridSize, (int)uVar11 < iVar6; uVar11 = uVar11 + 1) {
      fVar1 = this->mFlyLength;
      fVar2 = this->mHoistLength;
      iVar5 = this->mHoistGridSize;
      pcVar7->x = fVar4;
      pcVar7->y = fVar2 * ((float)((double)CONCAT44(0x43300000,-iVar10 ^ 0x80000000U) - dVar3) /
                          (float)((double)CONCAT44(0x43300000,iVar5 - 1U ^ 0x80000000) - dVar3));
      pcVar7->z = fVar1 * ((float)((double)CONCAT44(0x43300000,uVar11 ^ 0x80000000) - dVar3) /
                          (float)((double)CONCAT44(0x43300000,iVar6 - 1U ^ 0x80000000) - dVar3));
      fVar1 = this->mFlyLength;
      iVar6 = this->mFlyGridSize;
      fVar2 = this->mHoistLength;
      iVar5 = this->mHoistGridSize;
      pcVar8->x = fVar4;
      pcVar8->y = fVar2 * ((float)((double)CONCAT44(0x43300000,-iVar10 ^ 0x80000000U) - dVar3) /
                          (float)((double)CONCAT44(0x43300000,iVar5 - 1U ^ 0x80000000) - dVar3));
      pcVar8->z = fVar1 * ((float)((double)CONCAT44(0x43300000,uVar11 ^ 0x80000000) - dVar3) /
                          (float)((double)CONCAT44(0x43300000,iVar6 - 1U ^ 0x80000000) - dVar3));
      pcVar9->x = fVar4;
      pcVar9->y = fVar4;
      pcVar9->z = fVar4;
      pcVar7 = pcVar7 + 1;
      pcVar8 = pcVar8 + 1;
      pcVar9 = pcVar9 + 1;
    }
  }
  setNrm(this);
  (this->mScale).x = ::cXyz::BaseXYZ.x;
  (this->mScale).y = ::cXyz::BaseXYZ.y;
  (this->mScale).z = ::cXyz::BaseXYZ.z;
  (this->mGlobalWind).x = ::cXyz::BaseZ.x;
  (this->mGlobalWind).y = ::cXyz::BaseZ.y;
  (this->mGlobalWind).z = ::cXyz::BaseZ.z;
  os::DCStoreRangeNoSync
            (this->mpPosArr[this->mCurArr],this->mFlyGridSize * this->mHoistGridSize * 0xc);
  os::DCStoreRangeNoSync
            (this->mpNrmArr[this->mCurArr],this->mFlyGridSize * this->mHoistGridSize * 0xc);
  os::DCStoreRangeNoSync
            (this->mpNrmArrBack[this->mCurArr],this->mFlyGridSize * this->mHoistGridSize * 0xc);
  this->mpFactorCheckCB = d_cloth_packet::default_factor_checkCB;
  return -0x7ffa0000;
}


/* __thiscall dCloth_packet_c::setGlobalWind(cXyz *) */

void __thiscall dCloth_packet_c::setGlobalWind(dCloth_packet_c *this,cXyz *pWind)

{
  MTX34 MStack56;
  
  mtx::PSMTXCopy(&this->mMtx,&MStack56);
  MStack56.m[2][3] = d_cloth_packet::0_0;
  MStack56.m[1][3] = d_cloth_packet::0_0;
  MStack56.m[0][3] = d_cloth_packet::0_0;
  mtx::PSMTXCopy(&MStack56,&mDoMtx_stack_c::now);
  mtx::PSMTXInverse(&mDoMtx_stack_c::now,&mDoMtx_stack_c::now);
  mtx::PSMTXMultVec(&mDoMtx_stack_c::now,pWind,&this->mGlobalWind);
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Removing unreachable block (ram,0x80063700) */
/* WARNING: Removing unreachable block (ram,0x800636f8) */
/* WARNING: Removing unreachable block (ram,0x80063708) */
/* __thiscall dCloth_packet_c::cloth_move(void) */

void __thiscall dCloth_packet_c::cloth_move(dCloth_packet_c *this)

{
  int iVar1;
  dCloth_packet_c *pPktCur;
  cXyz *pNew;
  cXyz *pOld;
  int x;
  int y;
  cXyz *pSpeed;
  cXyz *pPosNew;
  cXyz *pNrmOld;
  cXyz *pPosOld;
  undefined4 uVar2;
  double dVar3;
  undefined8 in_f29;
  double dVar4;
  undefined8 in_f30;
  double dVar5;
  undefined8 in_f31;
  double dVar6;
  cXyz local_84;
  cXyz factor;
  cXyz wind;
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
  wind.x = (this->mGlobalWind).x;
  wind.y = (this->mGlobalWind).y;
  wind.z = (this->mGlobalWind).z;
  mtx::PSVECScale(&wind,&wind,
                  this->mWindSpeed +
                  this->mWindSpeedWave *
                  JKernel::JMath::jmaSinTable
                  [(int)((int)this->mWave & 0xffffU) >> (JKernel::JMath::jmaSinShift & 0x3f)]);
  pPktCur = (dCloth_packet_c *)(this->mpPosArr + (this->mCurArr - 10));
  pPosOld = pPktCur->mpPosArr[0];
  pNrmOld = pPktCur->mpNrmArr[0];
  this->mCurArr = this->mCurArr ^ 1;
  pPosNew = this->mpPosArr[this->mCurArr];
  pSpeed = this->mpSpeedArr;
  dVar5 = (double)((this->mFlyLength /
                   (float)((double)CONCAT44(0x43300000,this->mFlyGridSize - 1U ^ 0x80000000) -
                          d_cloth_packet::_4065)) * this->mFlyFlex);
  dVar4 = (double)((this->mHoistLength /
                   (float)((double)CONCAT44(0x43300000,this->mHoistGridSize - 1U ^ 0x80000000) -
                          d_cloth_packet::_4065)) * this->mHoistFlex);
  dVar6 = (double)((float)(dVar5 * dVar5) + (float)(dVar4 * dVar4));
  if ((double)d_cloth_packet::0_0 < dVar6) {
    dVar3 = 1.0 / SQRT(dVar6);
    dVar3 = d_cloth_packet::_4220 * dVar3 * (d_cloth_packet::_4221 - dVar6 * dVar3 * dVar3);
    dVar3 = d_cloth_packet::_4220 * dVar3 * (d_cloth_packet::_4221 - dVar6 * dVar3 * dVar3);
    dVar6 = (double)(float)(dVar6 * d_cloth_packet::_4220 * dVar3 *
                                    (d_cloth_packet::_4221 - dVar6 * dVar3 * dVar3));
  }
  for (y = 0; y < this->mHoistGridSize; y = y + 1) {
    for (x = 0; x < this->mFlyGridSize; x = x + 1) {
      getFactor(&local_84,this,pPosOld,pNrmOld,&wind,(float)dVar5,(float)dVar4,(float)dVar6,x,y);
      factor.x = local_84.x;
      factor.y = local_84.y;
      factor.z = local_84.z;
      mtx::PSVECAdd(pSpeed + x + y * this->mFlyGridSize,&factor,pSpeed + x + y * this->mFlyGridSize)
      ;
      mtx::PSVECScale(pSpeed + x + y * this->mFlyGridSize,pSpeed + x + y * this->mFlyGridSize,
                      this->mDrag);
      iVar1 = x + y * this->mFlyGridSize;
      pOld = pPosOld + iVar1;
      pNew = pPosNew + iVar1;
      pNew->x = pOld->x;
      pNew->y = pOld->y;
      pNew->z = pOld->z;
      iVar1 = x + y * this->mFlyGridSize;
      pNew = pPosNew + iVar1;
      mtx::PSVECAdd(pNew,pSpeed + iVar1,pNew);
    }
  }
  setNrm(this);
  os::DCStoreRangeNoSync
            (this->mpPosArr[this->mCurArr],this->mFlyGridSize * this->mHoistGridSize * 0xc);
  os::DCStoreRangeNoSync
            (this->mpNrmArr[this->mCurArr],this->mFlyGridSize * this->mHoistGridSize * 0xc);
  os::DCStoreRangeNoSync
            (this->mpNrmArrBack[this->mCurArr],this->mFlyGridSize * this->mHoistGridSize * 0xc);
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  __psq_l0(auStack24,uVar2);
  __psq_l1(auStack24,uVar2);
  __psq_l0(auStack40,uVar2);
  __psq_l1(auStack40,uVar2);
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dCloth_packet_c::draw(void) */

void __thiscall dCloth_packet_c::draw(dCloth_packet_c *this)

{
  MTX34 MStack56;
  
  J3DSys::reinitGX(&J3DGraphBase::j3dSys);
  gx::GXSetNumIndStages(0);
  d_kankyo::dKy_GxFog_tevstr_set(this->mpTevstr);
  d_kankyo::dKy_setLight_mine(this->mpTevstr);
  gx::GXClearVtxDesc();
  gx::GXSetVtxDesc(GX_VA_POS,GX_INDEX8);
  gx::GXSetVtxDesc(GX_VA_NRM,GX_INDEX8);
  gx::GXSetVtxDesc(GX_VA_TEX0,GX_DIRECT);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_F32,0);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_NRM,GX_CLR_RGB,GX_F32,0);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX0,GX_CLR_RGBA,GX_F32,0);
  gx::GXSetArray(GX_VA_POS,this->mpPosArr[this->mCurArr],0xc);
  gx::GXSetArray(GX_VA_NRM,this->mpNrmArr[this->mCurArr],0xc);
  (**(code **)((this->parent).vtbl + 0x28))(this);
  gx::GXLoadTexObj(&this->mToonTex,1);
  (**(code **)((this->parent).vtbl + 0x2c))(this);
  mtx::PSMTXCopy(&this->mMtx,&mDoMtx_stack_c::now);
  mDoMtx_stack_c::scaleM((this->mScale).x,(this->mScale).y,(this->mScale).z);
  mtx::PSMTXConcat(&J3DGraphBase::j3dSys.mCurViewMtx,&mDoMtx_stack_c::now,&MStack56);
  gx::GXLoadPosMtxImm(&MStack56,0);
  gx::GXLoadNrmMtxImm(&MStack56,0);
  gx::GXSetCullMode(2);
  plot(this);
  gx::GXSetCullMode(1);
  gx::GXSetArray(GX_VA_NRM,this->mpNrmArrBack[this->mCurArr],0xc);
  plot(this);
  _sOldVcdVatCmd = 0;
  return;
}


namespace d_cloth_packet {

/* WARNING: Removing unreachable block (ram,0x800639ec) */
/* WARNING: Removing unreachable block (ram,0x800639f4) */
/* __stdcall get_cloth_anim_sub_factor(cXyz *,
                                       cXyz *,
                                       cXyz *,
                                       float,
                                       float) */

void get_cloth_anim_sub_factor
               (cXyz *pPos,cXyz *pOther,cXyz *pDst,float param_4,float param_5)

{
  undefined4 uVar1;
  double dVar2;
  double dVar3;
  double dist;
  double dVar4;
  undefined8 in_f30;
  undefined8 in_f31;
  float fVar5;
  cXyz local_64;
  cXyz local_58;
  cXyz local_4c;
  cXyz local_40;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar4 = (double)param_5;
  dVar3 = (double)param_4;
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  ::cXyz::operator__(&local_58,pOther,pPos);
  local_40.x = local_58.x;
  local_40.y = local_58.y;
  local_40.z = local_58.z;
  ::cXyz::normZP(&local_64,&local_40);
  local_4c.x = local_64.x;
  local_4c.y = local_64.y;
  local_4c.z = local_64.z;
  fVar5 = mtx::PSVECSquareMag(&local_40);
  dist = (double)fVar5;
  if ((double)0_0 < dist) {
    dVar2 = 1.0 / SQRT(dist);
    dVar2 = _4220 * dVar2 * (_4221 - dist * dVar2 * dVar2);
    dVar2 = _4220 * dVar2 * (_4221 - dist * dVar2 * dVar2);
    dist = (double)(float)(dist * _4220 * dVar2 * (_4221 - dist * dVar2 * dVar2));
  }
  mtx::PSVECScale(&local_4c,&local_4c,(float)((double)(float)(dist - dVar3) * dVar4));
  mtx::PSVECAdd(pDst,&local_4c,pDst);
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  __psq_l0(auStack24,uVar1);
  __psq_l1(auStack24,uVar1);
  return;
}

}

/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* WARNING: Removing unreachable block (ram,0x80063d5c) */
/* WARNING: Removing unreachable block (ram,0x80063d54) */
/* WARNING: Removing unreachable block (ram,0x80063d64) */
/* __thiscall dCloth_packet_c::getFactor(cXyz *,
                                         cXyz *,
                                         cXyz *,
                                         float,
                                         float,
                                         float,
                                         int,
                                         int) */

cXyz * __thiscall
dCloth_packet_c::getFactor
          (cXyz *__return_storage_ptr__,dCloth_packet_c *this,cXyz *pPos,cXyz *pNrm,cXyz *pSpeed,
          float distFly,float distHoist,float distBoth,int x,int y)

{
  int iVar1;
  cXyz *pcVar2;
  cXyz *pOut;
  undefined4 uVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  cXyz local_88;
  cXyz pos;
  cXyz ret;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  byte down;
  byte left;
  byte right;
  byte up;
  
  dVar7 = (double)distBoth;
  dVar6 = (double)distHoist;
  dVar4 = (double)distFly;
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  iVar1 = (*(code *)this->mpFactorCheckCB)(this,x,y);
  if (iVar1 == 0) {
    iVar1 = x + y * this->mFlyGridSize;
    pcVar2 = pPos + iVar1;
    pos.x = pcVar2->x;
    pos.y = pcVar2->y;
    pos.z = pcVar2->z;
    dVar5 = (double)mtx::PSVECDotProduct(pSpeed,pNrm + iVar1);
    ::cXyz::operator_(&local_88,pNrm + x + y * this->mFlyGridSize,(float)dVar5);
    ret.x = local_88.x;
    ret.z = local_88.z;
    ret.y = local_88.y + this->mGravity;
    down = 0;
    if (x != 0) {
      down = d_cloth_packet::left_bit_4273;
    }
    if (x != this->mFlyGridSize + -1) {
      down = down | d_cloth_packet::right_bit_4274;
    }
    if (y != 0) {
      down = down | d_cloth_packet::up_bit_4275;
    }
    pOut = (cXyz *)this->mHoistGridSize;
    if (y != (int)&pOut[-1].z + 3) {
      down = down | d_cloth_packet::down_bit_4276;
    }
    left = down & 1;
    if (left != 0) {
      pOut = &pos;
      d_cloth_packet::get_cloth_anim_sub_factor
                (pOut,pPos + x + y * this->mFlyGridSize + -1,&ret,(float)dVar4,this->mSpring);
    }
    right = down & 2;
    if (right != 0) {
      pOut = &pos;
      d_cloth_packet::get_cloth_anim_sub_factor
                (pOut,pPos + x + y * this->mFlyGridSize + 1,&ret,(float)dVar4,this->mSpring);
    }
    up = down & 4;
    if (up != 0) {
      pOut = &pos;
      d_cloth_packet::get_cloth_anim_sub_factor
                (pOut,pPos + x + (y + -1) * this->mFlyGridSize,&ret,(float)dVar6,this->mSpring);
    }
    down = down & 8;
    if (down != 0) {
      pOut = &pos;
      d_cloth_packet::get_cloth_anim_sub_factor
                (pOut,pPos + x + (y + 1) * this->mFlyGridSize,&ret,(float)dVar6,this->mSpring);
    }
    if ((left != 0) && (up != 0)) {
      pOut = &pos;
      d_cloth_packet::get_cloth_anim_sub_factor
                (pOut,pPos + x + (y + -1) * this->mFlyGridSize + -1,&ret,(float)dVar7,this->mSpring)
      ;
    }
    if ((left != 0) && (down != 0)) {
      pOut = &pos;
      d_cloth_packet::get_cloth_anim_sub_factor
                (pOut,pPos + x + (y + 1) * this->mFlyGridSize + -1,&ret,(float)dVar7,this->mSpring);
    }
    if ((right != 0) && (up != 0)) {
      pOut = &pos;
      d_cloth_packet::get_cloth_anim_sub_factor
                (pOut,pPos + x + (y + -1) * this->mFlyGridSize + 1,&ret,(float)dVar7,this->mSpring);
    }
    if ((right != 0) && (down != 0)) {
      pOut = &pos;
      d_cloth_packet::get_cloth_anim_sub_factor
                (pOut,pPos + x + (y + 1) * this->mFlyGridSize + 1,&ret,(float)dVar7,this->mSpring);
    }
    __return_storage_ptr__->x = ret.x;
    __return_storage_ptr__->y = ret.y;
    __return_storage_ptr__->z = ret.z;
  }
  else {
    pOut = &::cXyz::Zero;
    __return_storage_ptr__->x = ::cXyz::Zero.x;
    __return_storage_ptr__->y = ::cXyz::Zero.y;
    __return_storage_ptr__->z = ::cXyz::Zero.z;
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  __psq_l0(auStack24,uVar3);
  __psq_l1(auStack24,uVar3);
  __psq_l0(auStack40,uVar3);
  __psq_l1(auStack40,uVar3);
  return pOut;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* WARNING: Removing unreachable block (ram,0x800642b0) */
/* __thiscall dCloth_packet_c::setNrm(void) */

void __thiscall dCloth_packet_c::setNrm(dCloth_packet_c *this)

{
  float fVar1;
  float fVar2;
  dCloth_packet_c *pPktCur;
  cXyz *pcVar3;
  int x;
  int y;
  cXyz *pNrm;
  cXyz *pPos;
  undefined4 uVar4;
  undefined8 in_f31;
  double dVar5;
  cXyz local_148;
  cXyz local_13c;
  cXyz local_130;
  cXyz local_124;
  cXyz local_118;
  cXyz local_10c;
  cXyz local_100;
  cXyz local_f4;
  cXyz local_e8;
  cXyz local_dc;
  cXyz local_d0;
  cXyz local_c4;
  cXyz local_b8;
  cXyz local_ac;
  cXyz local_a0;
  cXyz local_94;
  cXyz pos;
  cXyz local_7c;
  cXyz local_70;
  cXyz local_64;
  cXyz n;
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  pPktCur = (dCloth_packet_c *)(this->mpPosArr + (this->mCurArr - 10));
  pPos = pPktCur->mpPosArr[0];
  pNrm = pPktCur->mpNrmArr[0];
  this->mWave = this->mWave + this->mWaveSpeed;
  this->field_0xf0 = this->field_0xf0 + this->field_0xf2;
  dVar5 = d_cloth_packet::_4065;
  for (y = 0; y < this->mHoistGridSize; y = y + 1) {
    for (x = 0; x < this->mFlyGridSize; x = x + 1) {
      pcVar3 = pPos + x + this->mFlyGridSize * y;
      pos.x = pcVar3->x;
      pos.y = pcVar3->y;
      pos.z = pcVar3->z;
      local_7c.x = ::cXyz::Zero.x;
      local_7c.y = ::cXyz::Zero.y;
      local_7c.z = ::cXyz::Zero.z;
      if (x != 0) {
        ::cXyz::operator__(&local_94,pPos + x + this->mFlyGridSize * y + -1,&pos);
        n.x = local_94.x;
        n.y = local_94.y;
        n.z = local_94.z;
        if (y != 0) {
          ::cXyz::operator__(&local_a0,pPos + x + this->mFlyGridSize * (y + -1),&pos);
          local_64.x = local_a0.x;
          local_64.y = local_a0.y;
          local_64.z = local_a0.z;
          ::cXyz::outprod(&local_ac,&local_64,&n);
          local_70.x = local_ac.x;
          local_70.y = local_ac.y;
          local_70.z = local_ac.z;
          ::cXyz::normZP(&local_b8,&local_70);
          local_70.x = local_b8.x;
          local_70.y = local_b8.y;
          local_70.z = local_b8.z;
          mtx::PSVECAdd(&local_7c,&local_70,&local_7c);
        }
        if (y != this->mHoistGridSize + -1) {
          ::cXyz::operator__(&local_c4,pPos + x + this->mFlyGridSize * (y + 1),&pos);
          local_64.x = local_c4.x;
          local_64.y = local_c4.y;
          local_64.z = local_c4.z;
          ::cXyz::outprod(&local_d0,&n,&local_64);
          local_70.x = local_d0.x;
          local_70.y = local_d0.y;
          local_70.z = local_d0.z;
          ::cXyz::normZP(&local_dc,&local_70);
          local_70.x = local_dc.x;
          local_70.y = local_dc.y;
          local_70.z = local_dc.z;
          mtx::PSVECAdd(&local_7c,&local_70,&local_7c);
        }
      }
      if (x != this->mFlyGridSize + -1) {
        ::cXyz::operator__(&local_e8,pPos + x + this->mFlyGridSize * y + 1,&pos);
        n.x = local_e8.x;
        n.y = local_e8.y;
        n.z = local_e8.z;
        if (y != 0) {
          ::cXyz::operator__(&local_f4,pPos + x + this->mFlyGridSize * (y + -1),&pos);
          local_64.x = local_f4.x;
          local_64.y = local_f4.y;
          local_64.z = local_f4.z;
          ::cXyz::outprod(&local_100,&n,&local_64);
          local_70.x = local_100.x;
          local_70.y = local_100.y;
          local_70.z = local_100.z;
          ::cXyz::normZP(&local_10c,&local_70);
          local_70.x = local_10c.x;
          local_70.y = local_10c.y;
          local_70.z = local_10c.z;
          mtx::PSVECAdd(&local_7c,&local_70,&local_7c);
        }
        if (y != this->mHoistGridSize + -1) {
          ::cXyz::operator__(&local_118,pPos + x + this->mFlyGridSize * (y + 1),&pos);
          local_64.x = local_118.x;
          local_64.y = local_118.y;
          local_64.z = local_118.z;
          ::cXyz::outprod(&local_124,&local_64,&n);
          local_70.x = local_124.x;
          local_70.y = local_124.y;
          local_70.z = local_124.z;
          ::cXyz::normZP(&local_130,&local_70);
          local_70.x = local_130.x;
          local_70.y = local_130.y;
          local_70.z = local_130.z;
          mtx::PSVECAdd(&local_7c,&local_70,&local_7c);
        }
      }
      ::cXyz::normZP(&local_13c,&local_7c);
      local_7c.x = local_13c.x;
      local_7c.y = local_13c.y;
      local_7c.z = local_13c.z;
      m_Do_mtx::mDoMtx_YrotS
                (&mDoMtx_stack_c::now,
                 (int)((float)((double)CONCAT44(0x43300000,(int)this->mRotateY ^ 0x80000000) - dVar5
                              ) *
                      JKernel::JMath::jmaSinTable
                      [(int)((int)this->mWave + (int)this->mRipple * (x + y) & 0xffffU) >>
                       (JKernel::JMath::jmaSinShift & 0x3f)]));
      mtx::PSMTXMultVec(&mDoMtx_stack_c::now,&local_7c,&local_70);
      ::cXyz::normZP(&local_148,&local_70);
      pcVar3 = pNrm + x + this->mFlyGridSize * y;
      pcVar3->x = local_148.x;
      pcVar3->y = local_148.y;
      pcVar3->z = local_148.z;
    }
  }
  pPos = this->mpNrmArrBack[this->mCurArr];
  for (y = 0; y < this->mHoistGridSize; y = y + 1) {
    for (x = 0; x < this->mFlyGridSize; x = x + 1) {
      fVar1 = pNrm->z;
      fVar2 = pNrm->y;
      pPos->x = -pNrm->x;
      pPos->y = -fVar2;
      pPos->z = -fVar1;
      pNrm = pNrm + 1;
      pPos = pPos + 1;
    }
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return;
}


/* __thiscall dCloth_packet_c::setMtx(float *[][][][]) */

void __thiscall dCloth_packet_c::setMtx(dCloth_packet_c *this,MTX34 *param_1)

{
  mtx::PSMTXCopy(param_1,&this->mMtx);
  return;
}


/* __thiscall dCloth_packet_c::cloth_draw(void) */

void __thiscall dCloth_packet_c::cloth_draw(dCloth_packet_c *this)

{
  J3DDrawBuffer::entryImm(J3DGraphBase::j3dSys.mpCurDrawBuffers[0],&this->parent,0);
  return;
}


/* __thiscall dCloth_packet_c::TexObjInit(ResTIMG *) */

void __thiscall dCloth_packet_c::TexObjInit(dCloth_packet_c *this,ResTIMG *param_1)

{
  gx::GXInitTexObj(&this->mTexObj,&param_1->mTexFmt + param_1->mTexDataOffs,(uint)param_1->mWidth,
                   (uint)param_1->mHeight,param_1->mTexFmt,param_1->mWrapS,param_1->mWrapT,
                   SUB41(1 - (uint)param_1->mMipmapCount >> 0x1f,0));
  gx::GXInitTexObjLOD((double)(d_cloth_packet::0_125 *
                              (float)((double)CONCAT44(0x43300000,
                                                       (int)(char)param_1->mMinLOD ^ 0x80000000) -
                                     d_cloth_packet::_4065)),
                      (double)(d_cloth_packet::0_125 *
                              (float)((double)CONCAT44(0x43300000,
                                                       (int)(char)param_1->mMaxLOD ^ 0x80000000) -
                                     d_cloth_packet::_4065)),
                      (double)(d_cloth_packet::0_01 *
                              (float)((double)CONCAT44(0x43300000,
                                                       (int)param_1->mLODBias ^ 0x80000000) -
                                     d_cloth_packet::_4065)),&this->mTexObj,param_1->mMinFilter,
                      param_1->mMagFilter,param_1->mbBiasClamp,param_1->mbDoEdgeLOD,
                      param_1->mMaxAniso);
  return;
}


/* __thiscall dCloth_packet_c::TexObjLoad(void) */

void __thiscall dCloth_packet_c::TexObjLoad(dCloth_packet_c *this)

{
  gx::GXLoadTexObj(&this->mTexObj,0);
  return;
}


/* __thiscall dCloth_packet_c::TevSetting(void) */

void __thiscall dCloth_packet_c::TevSetting(dCloth_packet_c *this)

{
  int lightMask;
  int iVar1;
  _GXColor local_18;
  _GXColor local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  gx::GXSetNumChans(1);
  if ((this->mpTevstr->mColorK1).a == 0) {
    iVar1 = 2;
    lightMask = 1;
  }
  else {
    iVar1 = 3;
    lightMask = 3;
  }
  gx::GXSetChanCtrl(GX_COLOR0,true,GX_SRC_REG,GX_SRC_REG,lightMask,GX_DF_CLAMP,GX_AF_NONE);
  gx::GXSetNumTexGens(2);
  gx::GXSetTexCoordGen2(GX_TEXCOORD0,GX_TG_MTX2x4,GX_TG_TEX0,GX_IDENTITY,false,GX_PTIDENTITY);
  gx::GXSetTexCoordGen2(GX_TEXCOORD1,GX_TG_SRTG,GX_TG_COLOR0,GX_IDENTITY,false,GX_PTIDENTITY);
  gx::GXSetNumTevStages(iVar1);
  gx::GXSetTevSwapMode(0,0,1);
  gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD1,GX_TEXMAP1,GX_COLOR0A0);
  gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_C0,GX_CC_C1,GX_CC_TEXC,GX_CC_ZERO);
  gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO);
  gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetTevSwapMode(1,0,0);
  gx::GXSetTevOrder(GX_TEVSTAGE1,GX_TEXCOORD0,GX_TEXMAP0,GX_COLOR_NULL);
  gx::GXSetTevColorIn(GX_TEVSTAGE1,GX_CC_ZERO,GX_CC_TEXC,GX_CC_CPREV,GX_CC_ZERO);
  gx::GXSetTevColorOp(GX_TEVSTAGE1,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetTevAlphaIn(GX_TEVSTAGE1,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_TEXA);
  gx::GXSetTevAlphaOp(GX_TEVSTAGE1,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  if (iVar1 == 3) {
    gx::GXSetTevSwapMode(2,0,2);
    gx::GXSetTevOrder(GX_TEVSTAGE2,GX_TEXCOORD1,GX_TEXMAP1,GX_COLOR_NULL);
    gx::GXSetTevColorIn(GX_TEVSTAGE2,GX_CC_ZERO,GX_CC_C2,GX_CC_TEXC,GX_CC_CPREV);
    gx::GXSetTevColorOp(GX_TEVSTAGE2,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    gx::GXSetTevAlphaIn(GX_TEVSTAGE2,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_APREV);
    gx::GXSetTevAlphaOp(GX_TEVSTAGE2,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  }
  local_10 = *(undefined4 *)&this->mpTevstr->mColorC0;
  local_c = *(undefined4 *)&(this->mpTevstr->mColorC0).b;
  gx::GXSetTevColorS10(GX_TEVREG0,(_GXColorS10 *)&local_10);
  local_14 = this->mpTevstr->mColorK0;
  gx::GXSetTevColor(GX_TEVREG1,&local_14);
  local_18 = this->mpTevstr->mColorK1;
  gx::GXSetTevColor(GX_TEVREG2,&local_18);
  gx::GXCallDisplayList(&d_cloth_packet::l_matDL,0x20);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x80064854) */
/* WARNING: Removing unreachable block (ram,0x8006484c) */
/* WARNING: Removing unreachable block (ram,0x8006485c) */
/* __thiscall dCloth_packet_c::plot(void) */

void __thiscall dCloth_packet_c::plot(dCloth_packet_c *this)

{
  float fVar1;
  int iVar2;
  byte f1;
  int f0;
  undefined4 uVar3;
  undefined8 in_f29;
  double dVar4;
  undefined8 in_f30;
  double dVar5;
  undefined8 in_f31;
  double dVar6;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  byte h;
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  dVar5 = (double)(d_cloth_packet::1_0 /
                  (float)((double)CONCAT44(0x43300000,this->mFlyGridSize - 1U ^ 0x80000000) -
                         d_cloth_packet::_4065));
  dVar4 = (double)(d_cloth_packet::1_0 /
                  (float)((double)CONCAT44(0x43300000,this->mHoistGridSize - 1U ^ 0x80000000) -
                         d_cloth_packet::_4065));
  f1 = 1;
  fVar1 = d_cloth_packet::0_0;
  for (f0 = 0; dVar6 = (double)fVar1, f0 < this->mFlyGridSize + -1; f0 = f0 + 1) {
    gx::GXBegin(0x98,0,(this->mHoistGridSize & 0x7fU) << 1);
    fVar1 = d_cloth_packet::0_0;
    for (iVar2 = 0; iVar2 < this->mHoistGridSize; iVar2 = iVar2 + 1) {
      h = (byte)iVar2;
      write_volatile_1(DAT_cc008000,(char)f0 + h * (char)this->mFlyGridSize);
      write_volatile_1(DAT_cc008000,(char)f0 + h * (char)this->mFlyGridSize);
      write_volatile_4(0xcc008000,(float)dVar6);
      write_volatile_4(0xcc008000,fVar1);
      write_volatile_1(DAT_cc008000,f1 + h * (char)this->mFlyGridSize);
      write_volatile_1(DAT_cc008000,f1 + h * (char)this->mFlyGridSize);
      write_volatile_4(0xcc008000,(float)(dVar6 + dVar5));
      write_volatile_4(0xcc008000,fVar1);
      fVar1 = (float)((double)fVar1 + dVar4);
    }
    fVar1 = (float)(dVar6 + dVar5);
    f1 = f1 + 1;
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  __psq_l0(auStack24,uVar3);
  __psq_l1(auStack24,uVar3);
  __psq_l0(auStack40,uVar3);
  __psq_l1(auStack40,uVar3);
  return;
}


namespace d_cloth_packet {

/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __stdcall dCloth_packet_create(ResTIMG *,
                                  ResTIMG *,
                                  int,
                                  int,
                                  float,
                                  float,
                                  dKy_tevstr_c *,
                                  cXyz * *) */

dCloth_packet_c *
dCloth_packet_create
          (ResTIMG *param_1,ResTIMG *param_2,int param_3,int param_4,float param_5,float param_6,
          dKy_tevstr_c *param_7,cXyz **param_8)

{
  bool bVar1;
  dCloth_packet_c *this;
  double dVar2;
  double dVar3;
  
  dVar3 = (double)param_6;
  dVar2 = (double)param_5;
  this = (dCloth_packet_c *)JKernel::operator_new(0xfc);
  if (this != (dCloth_packet_c *)0x0) {
    ::dCloth_packet_c::dCloth_packet_c
              (this,param_2,param_3,param_4,(float)dVar2,(float)dVar3,param_7,param_8);
  }
  if (this != (dCloth_packet_c *)0x0) {
    if (((((this->mpPosArr[0] == (cXyz *)0x0) || (this->mpPosArr[1] == (cXyz *)0x0)) ||
         (this->mpNrmArr[0] == (cXyz *)0x0)) ||
        ((this->mpNrmArr[1] == (cXyz *)0x0 || (this->mpNrmArrBack[0] == (cXyz *)0x0)))) ||
       ((this->mpNrmArrBack[1] == (cXyz *)0x0 || (this->mpSpeedArr == (cXyz *)0x0)))) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      return (dCloth_packet_c *)0x0;
    }
  }
  if ((this != (dCloth_packet_c *)0x0) && (param_1 != (ResTIMG *)0x0)) {
    (**(code **)((this->parent).vtbl + 0x24))(this,param_1);
    (**(code **)((this->parent).vtbl + 0x18))(this);
  }
  return this;
}

}

/* __thiscall dCloth_packetXlu_c::TevSetting(void) */

void __thiscall dCloth_packetXlu_c::TevSetting(dCloth_packetXlu_c *this)

{
  int lightMask;
  int iVar1;
  _GXColor local_18;
  _GXColor local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  gx::GXSetNumChans(1);
  if (*(char *)(*(int *)(this + 0x20) + 0x8f) == '\0') {
    iVar1 = 2;
    lightMask = 1;
  }
  else {
    iVar1 = 3;
    lightMask = 3;
  }
  gx::GXSetChanCtrl(GX_COLOR0,true,GX_SRC_REG,GX_SRC_REG,lightMask,GX_DF_CLAMP,GX_AF_NONE);
  gx::GXSetNumTexGens(2);
  gx::GXSetTexCoordGen2(GX_TEXCOORD0,GX_TG_MTX2x4,GX_TG_TEX0,GX_IDENTITY,false,GX_PTIDENTITY);
  gx::GXSetTexCoordGen2(GX_TEXCOORD1,GX_TG_SRTG,GX_TG_COLOR0,GX_IDENTITY,false,GX_PTIDENTITY);
  gx::GXSetNumTevStages(iVar1);
  gx::GXSetTevSwapMode(0,0,1);
  gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD1,GX_TEXMAP1,GX_COLOR0A0);
  gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_C0,GX_CC_C1,GX_CC_TEXC,GX_CC_ZERO);
  gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO);
  gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetTevSwapMode(1,0,0);
  gx::GXSetTevOrder(GX_TEVSTAGE1,GX_TEXCOORD0,GX_TEXMAP0,GX_COLOR_NULL);
  gx::GXSetTevColorIn(GX_TEVSTAGE1,GX_CC_ZERO,GX_CC_TEXC,GX_CC_CPREV,GX_CC_ZERO);
  gx::GXSetTevColorOp(GX_TEVSTAGE1,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetTevAlphaIn(GX_TEVSTAGE1,GX_CA_ZERO,GX_CA_A0,GX_CA_TEXA,GX_CA_ZERO);
  gx::GXSetTevAlphaOp(GX_TEVSTAGE1,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  if (iVar1 == 3) {
    gx::GXSetTevSwapMode(2,0,2);
    gx::GXSetTevOrder(GX_TEVSTAGE2,GX_TEXCOORD1,GX_TEXMAP1,GX_COLOR_NULL);
    gx::GXSetTevColorIn(GX_TEVSTAGE2,GX_CC_ZERO,GX_CC_C2,GX_CC_TEXC,GX_CC_CPREV);
    gx::GXSetTevColorOp(GX_TEVSTAGE2,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
    gx::GXSetTevAlphaIn(GX_TEVSTAGE2,GX_CA_ZERO,GX_CA_A0,GX_CA_TEXA,GX_CA_ZERO);
    gx::GXSetTevAlphaOp(GX_TEVSTAGE2,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  }
  local_10 = *(undefined4 *)(*(int *)(this + 0x20) + 0x80);
  local_c = *(undefined4 *)(*(int *)(this + 0x20) + 0x84);
  gx::GXSetTevColorS10(GX_TEVREG0,(_GXColorS10 *)&local_10);
  local_14 = *(_GXColor *)(*(int *)(this + 0x20) + 0x88);
  gx::GXSetTevColor(GX_TEVREG1,&local_14);
  local_18 = *(_GXColor *)(*(int *)(this + 0x20) + 0x8c);
  gx::GXSetTevColor(GX_TEVREG2,&local_18);
  gx::GXCallDisplayList(&d_cloth_packet::l_alpha_matDL,0x20);
  return;
}


/* __thiscall dCloth_packetXlu_c::cloth_draw(void) */

void __thiscall dCloth_packetXlu_c::cloth_draw(dCloth_packetXlu_c *this)

{
  float *pfVar1;
  cXyz local_18 [2];
  
  pfVar1 = *(float **)(this + (uint)(byte)this[0xf8] * 4 + 0x28);
  local_18[0].x = *pfVar1;
  local_18[0].y = pfVar1[1];
  local_18[0].z = pfVar1[2];
  dDlst_list_c::entryZSortXluDrawList
            (&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
             d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelXlu,(J3DPacket *)this,
             local_18);
  return;
}


namespace d_cloth_packet {

/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __stdcall dCloth_packetXlu_create(ResTIMG *,
                                     ResTIMG *,
                                     int,
                                     int,
                                     float,
                                     float,
                                     dKy_tevstr_c *,
                                     cXyz * *) */

dCloth_packet_c *
dCloth_packetXlu_create
          (double param_1,double param_2,int param_3,ResTIMG *param_4,int param_5,int param_6,
          dKy_tevstr_c *param_7,cXyz **param_8)

{
  bool bVar1;
  dCloth_packet_c *this;
  
  this = (dCloth_packet_c *)JKernel::operator_new(0x100);
  if (this != (dCloth_packet_c *)0x0) {
    ::dCloth_packet_c::dCloth_packet_c
              (this,param_4,param_5,param_6,(float)param_1,(float)param_2,param_7,param_8);
    (this->parent).vtbl = &::dCloth_packetXlu_c::__vt;
    if (((((this->mpPosArr[0] == (cXyz *)0x0) || (this->mpPosArr[1] == (cXyz *)0x0)) ||
         (this->mpNrmArr[0] == (cXyz *)0x0)) ||
        ((this->mpNrmArr[1] == (cXyz *)0x0 || (this->mpNrmArrBack[0] == (cXyz *)0x0)))) ||
       ((this->mpNrmArrBack[1] == (cXyz *)0x0 || (this->mpSpeedArr == (cXyz *)0x0)))) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      return (dCloth_packet_c *)0x0;
    }
  }
  if ((this != (dCloth_packet_c *)0x0) && (param_3 != 0)) {
    (**(code **)((this->parent).vtbl + 0x24))(this,param_3);
    (**(code **)((this->parent).vtbl + 0x18))(this);
  }
  return this;
}

}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dClothVobj03_c::cloth_copy(void) */

void __thiscall dClothVobj03_c::cloth_copy(dClothVobj03_c *this)

{
  this[0xf8] = (dClothVobj03_c)((byte)this[0xf8] ^ 1);
  copy_bytes(*(byte **)(this + (uint)(byte)this[0xf8] * 4 + 0x30),
             *(byte **)(_top_pointer + (uint)*(byte *)(_top_pointer + 0xf8) * 4 + 0x30),
             *(int *)(this + 0x10) * *(int *)(this + 0x14) * 0xc);
  copy_bytes(*(byte **)(this + (uint)(byte)this[0xf8] * 4 + 0x38),
             *(byte **)(_top_pointer + (uint)*(byte *)(_top_pointer + 0xf8) * 4 + 0x38),
             *(int *)(this + 0x10) * *(int *)(this + 0x14) * 0xc);
  copy_bytes(*(byte **)(this + 0x40),*(byte **)(_top_pointer + 0x40),
             *(int *)(this + 0x10) * *(int *)(this + 0x14) * 0xc);
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dClothVobj03_c::init(void) */

int __thiscall dClothVobj03_c::init(dClothVobj03_c *this,EVP_PKEY_CTX *ctx)

{
  int iVar1;
  
  if (_cloth_counter == g__Timer) {
    copy_bytes(*(byte **)(this + (uint)(byte)this[0xf8] * 4 + 0x30),
               *(byte **)(_top_pointer + (uint)*(byte *)(_top_pointer + 0xf8) * 4 + 0x30),
               *(int *)(this + 0x10) * *(int *)(this + 0x14) * 0xc);
    copy_bytes(*(byte **)(this + (uint)(byte)this[0xf8] * 4 + 0x38),
               *(byte **)(_top_pointer + (uint)*(byte *)(_top_pointer + 0xf8) * 4 + 0x38),
               *(int *)(this + 0x10) * *(int *)(this + 0x14) * 0xc);
    copy_bytes(*(byte **)(this + 0x40),*(byte **)(_top_pointer + 0x40),
               *(int *)(this + 0x10) * *(int *)(this + 0x14) * 0xc);
  }
  else {
    dCloth_packet_c::init((dCloth_packet_c *)this);
  }
  iVar1 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)();
  if ((*(uint *)(iVar1 + 0xc) >> 0x10 & 7) == 2) {
    this[0x109] = (dClothVobj03_c)0x1;
  }
  else {
    this[0x109] = (dClothVobj03_c)0x0;
  }
  return iVar1;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dClothVobj03_c::cloth_move(void) */

void __thiscall dClothVobj03_c::cloth_move(dClothVobj03_c *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar4 = d_cloth_packet::_4789;
  fVar3 = d_cloth_packet::0_0;
  if (this[0x108] != (dClothVobj03_c)0x0) {
    if (_cloth_counter == g__Timer) {
      cloth_copy(this);
      return;
    }
    _cloth_counter = g__Timer;
    _top_pointer = this;
  }
  fVar1 = d_cloth_packet::_4789 + d_s_play::g_regHIO.mChild[10].mFloats[5];
  fVar2 = d_cloth_packet::_4790 + d_s_play::g_regHIO.mChild[10].mFloats[6];
  if (this[0x109] == (dClothVobj03_c)0x0) {
    *(float *)(this + 0xd8) = d_cloth_packet::_4792;
    *(float *)(this + 0xdc) = d_cloth_packet::_4793;
    *(float *)(this + 0xe0) = d_cloth_packet::_4794;
    *(float *)(this + 0xe4) = d_cloth_packet::_4795;
    *(float *)(this + 0xe8) = d_cloth_packet::_4796;
    *(undefined2 *)(this + 0xee) = 0x400;
    *(undefined2 *)(this + 0xf2) = 0;
    *(undefined2 *)(this + 0xf4) = 900;
    *(undefined2 *)(this + 0xf6) = 0xfce0;
    *(float *)(this + 0x5c) = fVar4;
    *(float *)(this + 0x60) = d_cloth_packet::_4797;
  }
  else {
    fVar1 = fVar1 * d_cloth_packet::_4791;
    *(float *)(this + 0xd8) = d_cloth_packet::_4792;
    *(float *)(this + 0xdc) = d_cloth_packet::_4793;
    *(float *)(this + 0xe0) = d_cloth_packet::_4794;
    *(float *)(this + 0xe4) = d_cloth_packet::_4795;
    *(float *)(this + 0xe8) = d_cloth_packet::_4796;
    *(undefined2 *)(this + 0xee) = 0;
    *(undefined2 *)(this + 0xf2) = 0;
    *(undefined2 *)(this + 0xf4) = 900;
    *(undefined2 *)(this + 0xf6) = 0xfce0;
    *(float *)(this + 0x5c) = fVar4;
    *(float *)(this + 0x60) = d_cloth_packet::_4797;
    fVar2 = fVar3;
  }
  *(float *)(this + 0x5c) = fVar1;
  *(float *)(this + 0x60) = fVar2;
  dCloth_packet_c::cloth_move((dCloth_packet_c *)this);
  return;
}


/* __thiscall dClothVobj03_c::TexObjInit(ResTIMG *) */

void __thiscall dClothVobj03_c::TexObjInit(dClothVobj03_c *this,ResTIMG *param_1)

{
  gx::GXInitTlutObj(this + 0xfc,&param_1->mTexFmt + param_1->mTlutDataOffs,param_1->mTlutFmt,
                    param_1->mTlutCount);
  gx::GXInitTexObjCI(this + 0x68,&param_1->mTexFmt + param_1->mTexDataOffs,param_1->mWidth,
                     param_1->mHeight,param_1->mTexFmt,param_1->mWrapS,param_1->mWrapT,
                     1 - param_1->mMipmapCount >> 0x1f,0);
  gx::GXInitTexObjLOD((double)(d_cloth_packet::0_125 *
                              (float)((double)CONCAT44(0x43300000,
                                                       (int)(char)param_1->mMinLOD ^ 0x80000000) -
                                     d_cloth_packet::_4065)),
                      (double)(d_cloth_packet::0_125 *
                              (float)((double)CONCAT44(0x43300000,
                                                       (int)(char)param_1->mMaxLOD ^ 0x80000000) -
                                     d_cloth_packet::_4065)),
                      (double)(d_cloth_packet::0_01 *
                              (float)((double)CONCAT44(0x43300000,
                                                       (int)param_1->mLODBias ^ 0x80000000) -
                                     d_cloth_packet::_4065)),this + 0x68,param_1->mMinFilter,
                      param_1->mMagFilter,param_1->mbBiasClamp,param_1->mbDoEdgeLOD,
                      param_1->mMaxAniso);
  return;
}


/* __thiscall dClothVobj03_c::TexObjLoad(void) */

void __thiscall dClothVobj03_c::TexObjLoad(dClothVobj03_c *this)

{
  gx::GXLoadTlut(this + 0xfc,0);
  gx::GXLoadTexObj((GXTexObj *)(this + 0x68),0);
  return;
}


namespace d_cloth_packet {

/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __stdcall dClothVobj03_create(ResTIMG *,
                                 ResTIMG *,
                                 dKy_tevstr_c *,
                                 cXyz * *) */

dCloth_packet_c *
dClothVobj03_create
          (int param_1,ResTIMG *param_2,dKy_tevstr_c *param_3,cXyz **param_4)

{
  bool bVar1;
  dCloth_packet_c *this;
  
  this = (dCloth_packet_c *)JKernel::operator_new(0x10c);
  if (this != (dCloth_packet_c *)0x0) {
    ::dCloth_packet_c::dCloth_packet_c(this,param_2,5,5,_4841,_4842,param_3,param_4);
    (this->parent).vtbl = &::dClothVobj03_c::__vt;
    if (param_4 == (cXyz **)0x0) {
      *(undefined *)&this[1].parent.field_0xc = 0;
    }
    else {
      *(undefined *)&this[1].parent.field_0xc = 1;
    }
  }
  if (this != (dCloth_packet_c *)0x0) {
    if (((((this->mpPosArr[0] == (cXyz *)0x0) || (this->mpPosArr[1] == (cXyz *)0x0)) ||
         (this->mpNrmArr[0] == (cXyz *)0x0)) ||
        ((this->mpNrmArr[1] == (cXyz *)0x0 || (this->mpNrmArrBack[0] == (cXyz *)0x0)))) ||
       ((this->mpNrmArrBack[1] == (cXyz *)0x0 || (this->mpSpeedArr == (cXyz *)0x0)))) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      return (dCloth_packet_c *)0x0;
    }
  }
  if ((this != (dCloth_packet_c *)0x0) && (param_1 != 0)) {
    (**(code **)((this->parent).vtbl + 0x24))(this,param_1);
    (**(code **)((this->parent).vtbl + 0x18))(this);
  }
  return this;
}

}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dClothVobj04_c::cloth_copy(void) */

void __thiscall dClothVobj04_c::cloth_copy(dClothVobj04_c *this)

{
  this[0xf8] = (dClothVobj04_c)((byte)this[0xf8] ^ 1);
  copy_bytes(*(byte **)(this + (uint)(byte)this[0xf8] * 4 + 0x30),
             *(byte **)(_top_pointer + (uint)*(byte *)(_top_pointer + 0xf8) * 4 + 0x30),
             *(int *)(this + 0x10) * *(int *)(this + 0x14) * 0xc);
  copy_bytes(*(byte **)(this + (uint)(byte)this[0xf8] * 4 + 0x38),
             *(byte **)(_top_pointer + (uint)*(byte *)(_top_pointer + 0xf8) * 4 + 0x38),
             *(int *)(this + 0x10) * *(int *)(this + 0x14) * 0xc);
  copy_bytes(*(byte **)(this + 0x40),*(byte **)(_top_pointer + 0x40),
             *(int *)(this + 0x10) * *(int *)(this + 0x14) * 0xc);
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dClothVobj04_c::init(void) */

int __thiscall dClothVobj04_c::init(dClothVobj04_c *this,EVP_PKEY_CTX *ctx)

{
  int iVar1;
  
  if (_cloth_counter == g__Timer) {
    copy_bytes(*(byte **)(this + (uint)(byte)this[0xf8] * 4 + 0x30),
               *(byte **)(_top_pointer + (uint)*(byte *)(_top_pointer + 0xf8) * 4 + 0x30),
               *(int *)(this + 0x10) * *(int *)(this + 0x14) * 0xc);
    copy_bytes(*(byte **)(this + (uint)(byte)this[0xf8] * 4 + 0x38),
               *(byte **)(_top_pointer + (uint)*(byte *)(_top_pointer + 0xf8) * 4 + 0x38),
               *(int *)(this + 0x10) * *(int *)(this + 0x14) * 0xc);
    copy_bytes(*(byte **)(this + 0x40),*(byte **)(_top_pointer + 0x40),
               *(int *)(this + 0x10) * *(int *)(this + 0x14) * 0xc);
  }
  else {
    dCloth_packet_c::init((dCloth_packet_c *)this);
  }
  iVar1 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)();
  if ((*(uint *)(iVar1 + 0xc) >> 0x10 & 7) == 2) {
    this[0x109] = (dClothVobj04_c)0x1;
  }
  else {
    this[0x109] = (dClothVobj04_c)0x0;
  }
  return iVar1;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dClothVobj04_c::cloth_move(void) */

void __thiscall dClothVobj04_c::cloth_move(dClothVobj04_c *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar4 = d_cloth_packet::_4789;
  fVar3 = d_cloth_packet::0_0;
  if (this[0x108] != (dClothVobj04_c)0x0) {
    if (_cloth_counter == g__Timer) {
      cloth_copy(this);
      return;
    }
    _cloth_counter = g__Timer;
    _top_pointer = this;
  }
  fVar1 = d_cloth_packet::_4789 + d_s_play::g_regHIO.mChild[10].mFloats[5];
  fVar2 = d_cloth_packet::_4790 + d_s_play::g_regHIO.mChild[10].mFloats[6];
  if (this[0x109] == (dClothVobj04_c)0x0) {
    *(float *)(this + 0xd8) = d_cloth_packet::_4908;
    *(float *)(this + 0xdc) = d_cloth_packet::_4793;
    *(float *)(this + 0xe0) = d_cloth_packet::_4796;
    fVar3 = d_cloth_packet::_4909;
    *(float *)(this + 0xe4) = d_cloth_packet::_4909;
    *(float *)(this + 0xe8) = fVar3;
    *(undefined2 *)(this + 0xee) = 0x400;
    *(undefined2 *)(this + 0xf2) = 0;
    *(undefined2 *)(this + 0xf4) = 900;
    *(undefined2 *)(this + 0xf6) = 0xfce0;
    *(float *)(this + 0x5c) = fVar4;
    *(float *)(this + 0x60) = d_cloth_packet::_4797;
  }
  else {
    fVar1 = fVar1 * d_cloth_packet::_4791;
    *(float *)(this + 0xd8) = d_cloth_packet::_4908;
    *(float *)(this + 0xdc) = d_cloth_packet::_4793;
    *(float *)(this + 0xe0) = d_cloth_packet::_4796;
    fVar2 = d_cloth_packet::_4909;
    *(float *)(this + 0xe4) = d_cloth_packet::_4909;
    *(float *)(this + 0xe8) = fVar2;
    *(undefined2 *)(this + 0xee) = 0;
    *(undefined2 *)(this + 0xf2) = 0;
    *(undefined2 *)(this + 0xf4) = 900;
    *(undefined2 *)(this + 0xf6) = 0xfce0;
    *(float *)(this + 0x5c) = fVar4;
    *(float *)(this + 0x60) = d_cloth_packet::_4797;
    fVar2 = fVar3;
  }
  *(float *)(this + 0x5c) = fVar1;
  *(float *)(this + 0x60) = fVar2;
  dCloth_packet_c::cloth_move((dCloth_packet_c *)this);
  return;
}


/* __thiscall dClothVobj04_c::TexObjInit(ResTIMG *) */

void __thiscall dClothVobj04_c::TexObjInit(dClothVobj04_c *this,ResTIMG *param_1)

{
  gx::GXInitTlutObj(this + 0xfc,&param_1->mTexFmt + param_1->mTlutDataOffs,param_1->mTlutFmt,
                    param_1->mTlutCount);
  gx::GXInitTexObjCI(this + 0x68,&param_1->mTexFmt + param_1->mTexDataOffs,param_1->mWidth,
                     param_1->mHeight,param_1->mTexFmt,param_1->mWrapS,param_1->mWrapT,
                     1 - param_1->mMipmapCount >> 0x1f,0);
  gx::GXInitTexObjLOD((double)(d_cloth_packet::0_125 *
                              (float)((double)CONCAT44(0x43300000,
                                                       (int)(char)param_1->mMinLOD ^ 0x80000000) -
                                     d_cloth_packet::_4065)),
                      (double)(d_cloth_packet::0_125 *
                              (float)((double)CONCAT44(0x43300000,
                                                       (int)(char)param_1->mMaxLOD ^ 0x80000000) -
                                     d_cloth_packet::_4065)),
                      (double)(d_cloth_packet::0_01 *
                              (float)((double)CONCAT44(0x43300000,
                                                       (int)param_1->mLODBias ^ 0x80000000) -
                                     d_cloth_packet::_4065)),this + 0x68,param_1->mMinFilter,
                      param_1->mMagFilter,param_1->mbBiasClamp,param_1->mbDoEdgeLOD,
                      param_1->mMaxAniso);
  return;
}


/* __thiscall dClothVobj04_c::TexObjLoad(void) */

void __thiscall dClothVobj04_c::TexObjLoad(dClothVobj04_c *this)

{
  gx::GXLoadTlut(this + 0xfc,0);
  gx::GXLoadTexObj((GXTexObj *)(this + 0x68),0);
  return;
}


namespace d_cloth_packet {

/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __stdcall dClothVobj04_create(ResTIMG *,
                                 ResTIMG *,
                                 dKy_tevstr_c *,
                                 cXyz * *) */

dCloth_packet_c *
dClothVobj04_create
          (int param_1,ResTIMG *param_2,dKy_tevstr_c *param_3,cXyz **param_4)

{
  bool bVar1;
  dCloth_packet_c *this;
  
  this = (dCloth_packet_c *)JKernel::operator_new(0x10c);
  if (this != (dCloth_packet_c *)0x0) {
    ::dCloth_packet_c::dCloth_packet_c(this,param_2,5,5,_4841,_4842,param_3,param_4);
    (this->parent).vtbl = &::dClothVobj04_c::__vt;
    if (param_4 == (cXyz **)0x0) {
      *(undefined *)&this[1].parent.field_0xc = 0;
    }
    else {
      *(undefined *)&this[1].parent.field_0xc = 1;
    }
  }
  if (this != (dCloth_packet_c *)0x0) {
    if (((((this->mpPosArr[0] == (cXyz *)0x0) || (this->mpPosArr[1] == (cXyz *)0x0)) ||
         (this->mpNrmArr[0] == (cXyz *)0x0)) ||
        ((this->mpNrmArr[1] == (cXyz *)0x0 || (this->mpNrmArrBack[0] == (cXyz *)0x0)))) ||
       ((this->mpNrmArrBack[1] == (cXyz *)0x0 || (this->mpSpeedArr == (cXyz *)0x0)))) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      return (dCloth_packet_c *)0x0;
    }
  }
  if ((this != (dCloth_packet_c *)0x0) && (param_1 != 0)) {
    (**(code **)((this->parent).vtbl + 0x24))(this,param_1);
    (**(code **)((this->parent).vtbl + 0x18))(this);
  }
  return this;
}

}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dClothVobj05_c::cloth_copy(void) */

void __thiscall dClothVobj05_c::cloth_copy(dClothVobj05_c *this)

{
  this[0xf8] = (dClothVobj05_c)((byte)this[0xf8] ^ 1);
  copy_bytes(*(byte **)(this + (uint)(byte)this[0xf8] * 4 + 0x30),
             *(byte **)(_top_pointer + (uint)*(byte *)(_top_pointer + 0xf8) * 4 + 0x30),
             *(int *)(this + 0x10) * *(int *)(this + 0x14) * 0xc);
  copy_bytes(*(byte **)(this + (uint)(byte)this[0xf8] * 4 + 0x38),
             *(byte **)(_top_pointer + (uint)*(byte *)(_top_pointer + 0xf8) * 4 + 0x38),
             *(int *)(this + 0x10) * *(int *)(this + 0x14) * 0xc);
  copy_bytes(*(byte **)(this + 0x40),*(byte **)(_top_pointer + 0x40),
             *(int *)(this + 0x10) * *(int *)(this + 0x14) * 0xc);
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dClothVobj05_c::init(void) */

int __thiscall dClothVobj05_c::init(dClothVobj05_c *this,EVP_PKEY_CTX *ctx)

{
  int iVar1;
  
  if (_cloth_counter == g__Timer) {
    copy_bytes(*(byte **)(this + (uint)(byte)this[0xf8] * 4 + 0x30),
               *(byte **)(_top_pointer + (uint)*(byte *)(_top_pointer + 0xf8) * 4 + 0x30),
               *(int *)(this + 0x10) * *(int *)(this + 0x14) * 0xc);
    copy_bytes(*(byte **)(this + (uint)(byte)this[0xf8] * 4 + 0x38),
               *(byte **)(_top_pointer + (uint)*(byte *)(_top_pointer + 0xf8) * 4 + 0x38),
               *(int *)(this + 0x10) * *(int *)(this + 0x14) * 0xc);
    copy_bytes(*(byte **)(this + 0x40),*(byte **)(_top_pointer + 0x40),
               *(int *)(this + 0x10) * *(int *)(this + 0x14) * 0xc);
  }
  else {
    dCloth_packet_c::init((dCloth_packet_c *)this);
  }
  iVar1 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)();
  if ((*(uint *)(iVar1 + 0xc) >> 0x10 & 7) == 2) {
    this[0x109] = (dClothVobj05_c)0x1;
  }
  else {
    this[0x109] = (dClothVobj05_c)0x0;
  }
  return iVar1;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dClothVobj05_c::cloth_move(void) */

void __thiscall dClothVobj05_c::cloth_move(dClothVobj05_c *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar4 = d_cloth_packet::_4789;
  fVar3 = d_cloth_packet::0_0;
  if (this[0x108] != (dClothVobj05_c)0x0) {
    if (_cloth_counter == g__Timer) {
      cloth_copy(this);
      return;
    }
    _cloth_counter = g__Timer;
    _top_pointer = this;
  }
  fVar1 = d_cloth_packet::_4789 + d_s_play::g_regHIO.mChild[10].mFloats[5];
  fVar2 = d_cloth_packet::_4790 + d_s_play::g_regHIO.mChild[10].mFloats[6];
  if (this[0x109] == (dClothVobj05_c)0x0) {
    *(float *)(this + 0xd8) = d_cloth_packet::_4908;
    *(float *)(this + 0xdc) = d_cloth_packet::_5018;
    *(float *)(this + 0xe0) = d_cloth_packet::_5020;
    *(float *)(this + 0xe4) = d_cloth_packet::_5021;
    *(float *)(this + 0xe8) = d_cloth_packet::_5019;
    *(undefined2 *)(this + 0xee) = 0x200;
    *(undefined2 *)(this + 0xf2) = 0;
    *(undefined2 *)(this + 0xf4) = 900;
    *(undefined2 *)(this + 0xf6) = 0xfce0;
    *(float *)(this + 0x5c) = fVar4;
    *(float *)(this + 0x60) = d_cloth_packet::_4797;
  }
  else {
    fVar1 = fVar1 * d_cloth_packet::_4791;
    *(float *)(this + 0xd8) = d_cloth_packet::_4908;
    *(float *)(this + 0xdc) = d_cloth_packet::_5018;
    *(float *)(this + 0xe0) = d_cloth_packet::_4794;
    fVar2 = d_cloth_packet::_5019;
    *(float *)(this + 0xe4) = d_cloth_packet::_5019;
    *(float *)(this + 0xe8) = fVar2;
    *(undefined2 *)(this + 0xee) = 0;
    *(undefined2 *)(this + 0xf2) = 0;
    *(undefined2 *)(this + 0xf4) = 0;
    *(undefined2 *)(this + 0xf6) = 0;
    *(float *)(this + 0x5c) = fVar4;
    *(float *)(this + 0x60) = d_cloth_packet::_4797;
    fVar2 = fVar3;
  }
  *(float *)(this + 0x5c) = fVar1;
  *(float *)(this + 0x60) = fVar2;
  dCloth_packet_c::cloth_move((dCloth_packet_c *)this);
  return;
}


/* __thiscall dClothVobj05_c::TexObjInit(ResTIMG *) */

void __thiscall dClothVobj05_c::TexObjInit(dClothVobj05_c *this,ResTIMG *param_1)

{
  gx::GXInitTlutObj(this + 0xfc,&param_1->mTexFmt + param_1->mTlutDataOffs,param_1->mTlutFmt,
                    param_1->mTlutCount);
  gx::GXInitTexObjCI(this + 0x68,&param_1->mTexFmt + param_1->mTexDataOffs,param_1->mWidth,
                     param_1->mHeight,param_1->mTexFmt,param_1->mWrapS,param_1->mWrapT,
                     1 - param_1->mMipmapCount >> 0x1f,0);
  gx::GXInitTexObjLOD((double)(d_cloth_packet::0_125 *
                              (float)((double)CONCAT44(0x43300000,
                                                       (int)(char)param_1->mMinLOD ^ 0x80000000) -
                                     d_cloth_packet::_4065)),
                      (double)(d_cloth_packet::0_125 *
                              (float)((double)CONCAT44(0x43300000,
                                                       (int)(char)param_1->mMaxLOD ^ 0x80000000) -
                                     d_cloth_packet::_4065)),
                      (double)(d_cloth_packet::0_01 *
                              (float)((double)CONCAT44(0x43300000,
                                                       (int)param_1->mLODBias ^ 0x80000000) -
                                     d_cloth_packet::_4065)),this + 0x68,param_1->mMinFilter,
                      param_1->mMagFilter,param_1->mbBiasClamp,param_1->mbDoEdgeLOD,
                      param_1->mMaxAniso);
  return;
}


/* __thiscall dClothVobj05_c::TexObjLoad(void) */

void __thiscall dClothVobj05_c::TexObjLoad(dClothVobj05_c *this)

{
  gx::GXLoadTlut(this + 0xfc,0);
  gx::GXLoadTexObj((GXTexObj *)(this + 0x68),0);
  return;
}


namespace d_cloth_packet {

/* __stdcall dClothVobj05_VtxFactorCB(dCloth_packet_c *,
                                      int,
                                      int) */

uint dClothVobj05_VtxFactorCB(dCloth_packet_c *pPkt,int x,int y)

{
  uint uVar1;
  
  uVar1 = countLeadingZeros(x);
  return uVar1 >> 5;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __stdcall dClothVobj05_create(ResTIMG *,
                                 ResTIMG *,
                                 dKy_tevstr_c *,
                                 cXyz * *) */

dCloth_packet_c *
dClothVobj05_create
          (int param_1,ResTIMG *param_2,dKy_tevstr_c *param_3,cXyz **param_4)

{
  bool bVar1;
  dCloth_packet_c *this;
  
  this = (dCloth_packet_c *)JKernel::operator_new(0x10c);
  if (this != (dCloth_packet_c *)0x0) {
    ::dCloth_packet_c::dCloth_packet_c(this,param_2,5,5,_5072,_4841,param_3,param_4);
    (this->parent).vtbl = &::dClothVobj05_c::__vt;
    if (param_4 == (cXyz **)0x0) {
      *(undefined *)&this[1].parent.field_0xc = 0;
    }
    else {
      *(undefined *)&this[1].parent.field_0xc = 1;
    }
  }
  if (this != (dCloth_packet_c *)0x0) {
    if (((((this->mpPosArr[0] == (cXyz *)0x0) || (this->mpPosArr[1] == (cXyz *)0x0)) ||
         (this->mpNrmArr[0] == (cXyz *)0x0)) ||
        ((this->mpNrmArr[1] == (cXyz *)0x0 || (this->mpNrmArrBack[0] == (cXyz *)0x0)))) ||
       ((this->mpNrmArrBack[1] == (cXyz *)0x0 || (this->mpSpeedArr == (cXyz *)0x0)))) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      return (dCloth_packet_c *)0x0;
    }
  }
  if ((this != (dCloth_packet_c *)0x0) && (param_1 != 0)) {
    (**(code **)((this->parent).vtbl + 0x24))(this,param_1);
    (**(code **)((this->parent).vtbl + 0x18))(this);
    this->mpFactorCheckCB = dClothVobj05_VtxFactorCB;
  }
  return this;
}

}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dClothVobj07_0_c::cloth_copy(void) */

void __thiscall dClothVobj07_0_c::cloth_copy(dClothVobj07_0_c *this)

{
  this[0xf8] = (dClothVobj07_0_c)((byte)this[0xf8] ^ 1);
  copy_bytes(*(byte **)(this + (uint)(byte)this[0xf8] * 4 + 0x30),
             *(byte **)(_top_pointer + (uint)*(byte *)(_top_pointer + 0xf8) * 4 + 0x30),
             *(int *)(this + 0x10) * *(int *)(this + 0x14) * 0xc);
  copy_bytes(*(byte **)(this + (uint)(byte)this[0xf8] * 4 + 0x38),
             *(byte **)(_top_pointer + (uint)*(byte *)(_top_pointer + 0xf8) * 4 + 0x38),
             *(int *)(this + 0x10) * *(int *)(this + 0x14) * 0xc);
  copy_bytes(*(byte **)(this + 0x40),*(byte **)(_top_pointer + 0x40),
             *(int *)(this + 0x10) * *(int *)(this + 0x14) * 0xc);
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dClothVobj07_0_c::init(void) */

int __thiscall dClothVobj07_0_c::init(dClothVobj07_0_c *this,EVP_PKEY_CTX *ctx)

{
  int iVar1;
  
  if (_cloth_counter == g__Timer) {
    copy_bytes(*(byte **)(this + (uint)(byte)this[0xf8] * 4 + 0x30),
               *(byte **)(_top_pointer + (uint)*(byte *)(_top_pointer + 0xf8) * 4 + 0x30),
               *(int *)(this + 0x10) * *(int *)(this + 0x14) * 0xc);
    copy_bytes(*(byte **)(this + (uint)(byte)this[0xf8] * 4 + 0x38),
               *(byte **)(_top_pointer + (uint)*(byte *)(_top_pointer + 0xf8) * 4 + 0x38),
               *(int *)(this + 0x10) * *(int *)(this + 0x14) * 0xc);
    copy_bytes(*(byte **)(this + 0x40),*(byte **)(_top_pointer + 0x40),
               *(int *)(this + 0x10) * *(int *)(this + 0x14) * 0xc);
  }
  else {
    dCloth_packet_c::init((dCloth_packet_c *)this);
  }
  iVar1 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)();
  if ((*(uint *)(iVar1 + 0xc) >> 0x10 & 7) == 2) {
    this[0x109] = (dClothVobj07_0_c)0x1;
  }
  else {
    this[0x109] = (dClothVobj07_0_c)0x0;
  }
  return iVar1;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dClothVobj07_0_c::cloth_move(void) */

void __thiscall dClothVobj07_0_c::cloth_move(dClothVobj07_0_c *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar4 = d_cloth_packet::_4789;
  fVar3 = d_cloth_packet::0_0;
  if (this[0x108] != (dClothVobj07_0_c)0x0) {
    if (_cloth_counter == g__Timer) {
      cloth_copy(this);
      return;
    }
    _cloth_counter = g__Timer;
    _top_pointer = this;
  }
  fVar1 = d_cloth_packet::_4789 + d_s_play::g_regHIO.mChild[10].mFloats[5];
  fVar2 = d_cloth_packet::_4790 + d_s_play::g_regHIO.mChild[10].mFloats[6];
  if (this[0x109] == (dClothVobj07_0_c)0x0) {
    *(float *)(this + 0xd8) = d_cloth_packet::_4792;
    *(float *)(this + 0xdc) = d_cloth_packet::_5140;
    *(float *)(this + 0xe0) = d_cloth_packet::_4794;
    fVar3 = d_cloth_packet::_5139;
    *(float *)(this + 0xe4) = d_cloth_packet::_5139;
    *(float *)(this + 0xe8) = fVar3;
    *(undefined2 *)(this + 0xee) = 0x100;
    *(undefined2 *)(this + 0xf2) = 0;
    *(undefined2 *)(this + 0xf4) = 900;
    *(undefined2 *)(this + 0xf6) = 0xfce0;
    *(float *)(this + 0x5c) = fVar4;
    *(float *)(this + 0x60) = d_cloth_packet::_4797;
  }
  else {
    fVar1 = fVar1 * d_cloth_packet::_4791;
    *(float *)(this + 0xd8) = d_cloth_packet::_5138;
    *(float *)(this + 0xdc) = d_cloth_packet::_5018;
    *(float *)(this + 0xe0) = d_cloth_packet::_4794;
    fVar2 = d_cloth_packet::_5139;
    *(float *)(this + 0xe4) = d_cloth_packet::_5139;
    *(float *)(this + 0xe8) = fVar2;
    *(undefined2 *)(this + 0xee) = 0;
    *(undefined2 *)(this + 0xf2) = 0;
    *(undefined2 *)(this + 0xf4) = 900;
    *(undefined2 *)(this + 0xf6) = 0xfce0;
    *(float *)(this + 0x5c) = fVar4;
    *(float *)(this + 0x60) = d_cloth_packet::_4797;
    fVar2 = fVar3;
  }
  *(float *)(this + 0x5c) = fVar1;
  *(float *)(this + 0x60) = fVar2;
  dCloth_packet_c::cloth_move((dCloth_packet_c *)this);
  return;
}


/* __thiscall dClothVobj07_0_c::TexObjInit(ResTIMG *) */

void __thiscall dClothVobj07_0_c::TexObjInit(dClothVobj07_0_c *this,ResTIMG *param_1)

{
  gx::GXInitTlutObj(this + 0xfc,&param_1->mTexFmt + param_1->mTlutDataOffs,param_1->mTlutFmt,
                    param_1->mTlutCount);
  gx::GXInitTexObjCI(this + 0x68,&param_1->mTexFmt + param_1->mTexDataOffs,param_1->mWidth,
                     param_1->mHeight,param_1->mTexFmt,param_1->mWrapS,param_1->mWrapT,
                     1 - param_1->mMipmapCount >> 0x1f,0);
  gx::GXInitTexObjLOD((double)(d_cloth_packet::0_125 *
                              (float)((double)CONCAT44(0x43300000,
                                                       (int)(char)param_1->mMinLOD ^ 0x80000000) -
                                     d_cloth_packet::_4065)),
                      (double)(d_cloth_packet::0_125 *
                              (float)((double)CONCAT44(0x43300000,
                                                       (int)(char)param_1->mMaxLOD ^ 0x80000000) -
                                     d_cloth_packet::_4065)),
                      (double)(d_cloth_packet::0_01 *
                              (float)((double)CONCAT44(0x43300000,
                                                       (int)param_1->mLODBias ^ 0x80000000) -
                                     d_cloth_packet::_4065)),this + 0x68,param_1->mMinFilter,
                      param_1->mMagFilter,param_1->mbBiasClamp,param_1->mbDoEdgeLOD,
                      param_1->mMaxAniso);
  return;
}


/* __thiscall dClothVobj07_0_c::TexObjLoad(void) */

void __thiscall dClothVobj07_0_c::TexObjLoad(dClothVobj07_0_c *this)

{
  gx::GXLoadTlut(this + 0xfc,0);
  gx::GXLoadTexObj((GXTexObj *)(this + 0x68),0);
  return;
}


namespace d_cloth_packet {

/* __stdcall dClothVobj07_0_VtxFactorCB(dCloth_packet_c *,
                                        int,
                                        int) */

uint dClothVobj07_0_VtxFactorCB(dCloth_packet_c *pPkt,int x,int y)

{
  uint uVar1;
  
  uVar1 = countLeadingZeros(x);
  return uVar1 >> 5;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __stdcall dClothVobj07_0_create(ResTIMG *,
                                   ResTIMG *,
                                   dKy_tevstr_c *,
                                   cXyz * *) */

dCloth_packet_c *
dClothVobj07_0_create
          (int param_1,ResTIMG *param_2,dKy_tevstr_c *param_3,cXyz **param_4)

{
  bool bVar1;
  dCloth_packet_c *this;
  
  this = (dCloth_packet_c *)JKernel::operator_new(0x10c);
  if (this != (dCloth_packet_c *)0x0) {
    ::dCloth_packet_c::dCloth_packet_c(this,param_2,5,5,_4841,_5191,param_3,param_4);
    (this->parent).vtbl = &::dClothVobj07_0_c::__vt;
    if (param_4 == (cXyz **)0x0) {
      *(undefined *)&this[1].parent.field_0xc = 0;
    }
    else {
      *(undefined *)&this[1].parent.field_0xc = 1;
    }
  }
  if (this != (dCloth_packet_c *)0x0) {
    if (((((this->mpPosArr[0] == (cXyz *)0x0) || (this->mpPosArr[1] == (cXyz *)0x0)) ||
         (this->mpNrmArr[0] == (cXyz *)0x0)) ||
        ((this->mpNrmArr[1] == (cXyz *)0x0 || (this->mpNrmArrBack[0] == (cXyz *)0x0)))) ||
       ((this->mpNrmArrBack[1] == (cXyz *)0x0 || (this->mpSpeedArr == (cXyz *)0x0)))) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (!bVar1) {
      return (dCloth_packet_c *)0x0;
    }
  }
  if ((this != (dCloth_packet_c *)0x0) && (param_1 != 0)) {
    (**(code **)((this->parent).vtbl + 0x24))(this,param_1);
    (**(code **)((this->parent).vtbl + 0x18))(this);
    this->mpFactorCheckCB = dClothVobj07_0_VtxFactorCB;
  }
  return this;
}

}

/* __thiscall dClothVobj07_0_c::~dClothVobj07_0_c(void) */

void __thiscall dClothVobj07_0_c::_dClothVobj07_0_c(dClothVobj07_0_c *this)

{
  short in_r4;
  
  if (this != (dClothVobj07_0_c *)0x0) {
    *(undefined1 **)this = &__vt;
    dCloth_packet_c::_dCloth_packet_c((dCloth_packet_c *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dClothVobj05_c::~dClothVobj05_c(void) */

void __thiscall dClothVobj05_c::_dClothVobj05_c(dClothVobj05_c *this)

{
  short in_r4;
  
  if (this != (dClothVobj05_c *)0x0) {
    *(undefined1 **)this = &__vt;
    dCloth_packet_c::_dCloth_packet_c((dCloth_packet_c *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dClothVobj04_c::~dClothVobj04_c(void) */

void __thiscall dClothVobj04_c::_dClothVobj04_c(dClothVobj04_c *this)

{
  short in_r4;
  
  if (this != (dClothVobj04_c *)0x0) {
    *(undefined1 **)this = &__vt;
    dCloth_packet_c::_dCloth_packet_c((dCloth_packet_c *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dClothVobj03_c::~dClothVobj03_c(void) */

void __thiscall dClothVobj03_c::_dClothVobj03_c(dClothVobj03_c *this)

{
  short in_r4;
  
  if (this != (dClothVobj03_c *)0x0) {
    *(undefined1 **)this = &__vt;
    dCloth_packet_c::_dCloth_packet_c((dCloth_packet_c *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dCloth_packetXlu_c::~dCloth_packetXlu_c(void) */

void __thiscall dCloth_packetXlu_c::_dCloth_packetXlu_c(dCloth_packetXlu_c *this)

{
  short in_r4;
  
  if (this != (dCloth_packetXlu_c *)0x0) {
    *(undefined1 **)this = &__vt;
    dCloth_packet_c::_dCloth_packet_c((dCloth_packet_c *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}

