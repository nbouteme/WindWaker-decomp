#include <d_bg_w.h>
#include <SComponent/c_bg_w.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <d_bg_s_acch.h>
#include <SComponent/c_m3d.h>
#include <d_bg_w.h>
#include <SComponent/c_math.h>
#include <SComponent/c_m2d.h>
#include <SComponent/c_m3d_g_cyl.h>
#include <d_bg_s.h>
#include <JKernel/JKRHeap.h>
#include <Demangler/cM3dGTri.h>
#include <dBgW.h>


/* __thiscall dBgW::dBgW(void) */

dBgW * __thiscall dBgW::dBgW(dBgW *this)

{
  cBgW::cBgW(&this->parent);
  (this->parent).vtbl = (undefined *)&__vt;
  this->mRotYDelta = 0;
  this->mOldRotY = 0;
  this->mpTransPosCb = (void *)0x0;
  this->mpRideCb = (void *)0x0;
  this->mpPushPullCb = (void *)0x0;
  this->mFlag = 0;
  this->mRoomNo = -1;
  this->mRoomNo2 = 0xff;
  return this;
}


/* __thiscall dBgW::Move(void) */

void __thiscall dBgW::Move(dBgW *this)

{
  this->mFlag = this->mFlag | 1;
  cBgW::Move(&this->parent);
  return;
}


/* __thiscall dBgW::positionWallCorrect(dBgS_Acch *,
                                        float,
                                        cM3dGPla &,
                                        cXyz *,
                                        float) */

void __thiscall
dBgW::positionWallCorrect
          (dBgW *this,dBgS_Acch *pAcch,float param_2,cM3dGPla *pPla,cXyz *pUpperPos,float param_5)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  ulong uVar4;
  
  pAcch->mFlags = pAcch->mFlags | 0x10;
  pUpperPos->x = pUpperPos->x + param_5 * param_2 * (pPla->mNorm).x;
  pUpperPos->z = pUpperPos->z + param_5 * param_2 * (pPla->mNorm).z;
  fVar1 = pUpperPos->x;
  uVar2 = (uint)fVar1 & 0x7f800000;
  if (uVar2 == 0x7f800000) {
    if (((uint)fVar1 & 0x7fffff) == 0) {
      iVar3 = 2;
    }
    else {
      iVar3 = 1;
    }
  }
  else {
    if ((uVar2 < 0x7f800000) && (uVar2 == 0)) {
      if (((uint)fVar1 & 0x7fffff) == 0) {
        iVar3 = 3;
      }
      else {
        iVar3 = 5;
      }
    }
    else {
      iVar3 = 4;
    }
  }
  if (iVar3 == 1) {
    uVar4 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar4,"d_bg_w.cpp",0xd0,
               "!(((sizeof(pupper_pos->x) == sizeof(float)) ? __fpclassifyf((float)(pupper_pos->x)) : __fpclassifyd((double)(pupper_pos->x)) ) == 1)"
              );
    m_Do_printf::OSPanic("d_bg_w.cpp",0xd0,"Halt");
  }
  fVar1 = pUpperPos->z;
  uVar2 = (uint)fVar1 & 0x7f800000;
  if (uVar2 == 0x7f800000) {
    if (((uint)fVar1 & 0x7fffff) == 0) {
      iVar3 = 2;
    }
    else {
      iVar3 = 1;
    }
  }
  else {
    if ((uVar2 < 0x7f800000) && (uVar2 == 0)) {
      if (((uint)fVar1 & 0x7fffff) == 0) {
        iVar3 = 3;
      }
      else {
        iVar3 = 5;
      }
    }
    else {
      iVar3 = 4;
    }
  }
  if (iVar3 == 1) {
    uVar4 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar4,"d_bg_w.cpp",0xd1,
               "!(((sizeof(pupper_pos->z) == sizeof(float)) ? __fpclassifyf((float)(pupper_pos->z)) : __fpclassifyd((double)(pupper_pos->z)) ) == 1)"
              );
    m_Do_printf::OSPanic("d_bg_w.cpp",0xd1,"Halt");
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f18 */
/* WARNING: Inlined function: FUN_80328f64 */
/* WARNING: Removing unreachable block (ram,0x800a6994) */
/* WARNING: Removing unreachable block (ram,0x800a6cfc) */
/* WARNING: Removing unreachable block (ram,0x800a6584) */
/* WARNING: Removing unreachable block (ram,0x800a6dd0) */
/* WARNING: Removing unreachable block (ram,0x800a6dc0) */
/* WARNING: Removing unreachable block (ram,0x800a6db0) */
/* WARNING: Removing unreachable block (ram,0x800a6da0) */
/* WARNING: Removing unreachable block (ram,0x800a6d90) */
/* WARNING: Removing unreachable block (ram,0x800a6d88) */
/* WARNING: Removing unreachable block (ram,0x800a6d98) */
/* WARNING: Removing unreachable block (ram,0x800a6da8) */
/* WARNING: Removing unreachable block (ram,0x800a6db8) */
/* WARNING: Removing unreachable block (ram,0x800a6dc8) */
/* WARNING: Removing unreachable block (ram,0x800a6dd8) */
/* __thiscall dBgW::RwgWallCorrect(dBgS_Acch *,
                                   unsigned short) */

undefined4 __thiscall dBgW::RwgWallCorrect(dBgW *this,dBgS_Acch *pAcch,ushort rwg)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  bool bVar10;
  char cVar13;
  uint uVar11;
  ulong uVar12;
  int iVar14;
  cXyz *pcVar15;
  int iVar16;
  int iVar17;
  undefined4 uVar18;
  cXyz *pcVar19;
  dBgW *pdVar20;
  cBgW_RwgElm *pcVar21;
  cBgD__Tri_t *pcVar22;
  int iVar23;
  cBgW_TriElm *pPla;
  int iVar24;
  undefined4 uVar25;
  double dVar26;
  double dVar27;
  double dVar28;
  double dVar29;
  double dVar30;
  double dVar31;
  undefined8 in_f21;
  undefined8 in_f22;
  undefined8 in_f23;
  double dVar32;
  undefined8 in_f24;
  double dVar33;
  undefined8 in_f25;
  double dVar34;
  undefined8 in_f26;
  double dVar35;
  undefined8 in_f27;
  double dVar36;
  undefined8 in_f28;
  undefined8 in_f29;
  undefined8 in_f30;
  double dVar37;
  undefined8 in_f31;
  float local_120;
  float local_11c;
  float local_118;
  float local_114;
  float local_110;
  float local_10c;
  float local_108;
  float local_104 [3];
  cXyz local_f8;
  undefined auStack168 [16];
  undefined auStack152 [16];
  undefined auStack136 [16];
  undefined auStack120 [16];
  undefined auStack104 [16];
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar25 = 0;
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
  __psq_st0(auStack104,(int)((ulonglong)in_f25 >> 0x20),0);
  __psq_st1(auStack104,(int)in_f25,0);
  __psq_st0(auStack120,(int)((ulonglong)in_f24 >> 0x20),0);
  __psq_st1(auStack120,(int)in_f24,0);
  __psq_st0(auStack136,(int)((ulonglong)in_f23 >> 0x20),0);
  __psq_st1(auStack136,(int)in_f23,0);
  __psq_st0(auStack152,(int)((ulonglong)in_f22 >> 0x20),0);
  __psq_st1(auStack152,(int)in_f22,0);
  __psq_st0(auStack168,(int)((ulonglong)in_f21 >> 0x20),0);
  __psq_st1(auStack168,(int)in_f21,0);
  uVar18 = 0;
  do {
    while( true ) {
      pcVar21 = (this->parent).mpRwg;
      uVar11 = (uint)rwg;
      cVar13 = (**(code **)((this->parent).vtbl + 0x18))(this,uVar11,(pAcch->mChk).mpPolyPassChk);
      if (cVar13 == '\0') break;
LAB_800a6d74:
      rwg = pcVar21[rwg].mNext;
      if (rwg == 0xffff) goto LAB_800a6d84;
    }
    pPla = (this->parent).mpTriElm + uVar11;
    fVar1 = (pPla->mPlane).mNorm.x;
    fVar2 = (pPla->mPlane).mNorm.z;
    dVar30 = (double)(fVar1 * fVar1 + fVar2 * fVar2);
    if ((double)d_bg_w::_3140 < dVar30) {
      dVar26 = 1.0 / SQRT(dVar30);
      dVar26 = d_bg_w::_3141 * dVar26 * (d_bg_w::_3142 - dVar30 * dVar26 * dVar26);
      dVar26 = d_bg_w::_3141 * dVar26 * (d_bg_w::_3142 - dVar30 * dVar26 * dVar26);
      dVar30 = (double)(float)(dVar30 * d_bg_w::_3141 * dVar26 *
                                        (d_bg_w::_3142 - dVar30 * dVar26 * dVar26));
    }
    if (SComponent::G_CM3D_F_ABS_MIN <= (float)ABS(dVar30)) {
      dVar30 = (double)(float)((double)d_bg_w::_3143 / dVar30);
      pcVar22 = ((this->parent).mpBgDt)->mpTriTbl + uVar11;
      iVar24 = 0;
      dVar26 = (double)d_bg_w::_3140;
      for (iVar23 = 0; iVar23 < pAcch->mAcchCirCount; iVar23 = iVar23 + 1) {
        fVar1 = (float)(dVar30 * (double)*(float *)((int)&pAcch->mpAcchCir->mWallRadius + iVar24));
        local_f8.x = fVar1 * (pPla->mPlane).mNorm.x;
        local_f8.y = (float)dVar26;
        local_f8.z = fVar1 * (pPla->mPlane).mNorm.z;
        iVar14 = (int)&(pAcch->mpAcchCir->mPolyInfo).mTriIdx + iVar24;
        if ((*(uint *)(iVar14 + 0x10) & 4) == 0) {
          pcVar19 = pAcch->mpPos;
          dVar32 = (double)*(float *)(iVar14 + 0x30);
          dVar28 = dVar26;
          if (pAcch->field_0x34 != (cXyz *)0x0) {
            dVar28 = (double)pAcch->field_0x34->y;
          }
          dVar27 = (double)dBgS_Acch::GetWallAddY(pAcch,&local_f8,iVar23);
          local_104[2] = (float)((double)(float)(dVar27 + (double)(float)((double)pcVar19->y +
                                                                         dVar32)) - dVar28);
        }
        else {
          local_104[2] = *(float *)(iVar14 + 0x38);
        }
        pcVar19 = (this->parent).mpVtxTbl;
        local_104[0] = pcVar19[(ushort)pcVar22->mVtxIdx0].y - local_104[2];
        dVar28 = (double)local_104[0];
        local_104[1] = pcVar19[(ushort)pcVar22->mVtxIdx1].y - local_104[2];
        local_104[2] = pcVar19[(ushort)pcVar22->mVtxIdx2].y - local_104[2];
        if ((((dVar28 <= dVar26) || ((double)local_104[1] <= dVar26)) ||
            ((double)local_104[2] <= dVar26)) &&
           (((dVar32 = (double)d_bg_w::_3140, dVar32 <= dVar28 || (dVar32 <= (double)local_104[1]))
            || (dVar32 <= (double)local_104[2])))) {
          cVar13 = (float)ABS(dVar28) < SComponent::G_CM3D_F_ABS_MIN;
          if (ABS(local_104[1]) < SComponent::G_CM3D_F_ABS_MIN) {
            cVar13 = cVar13 + '\x01';
          }
          if (ABS(local_104[2]) < SComponent::G_CM3D_F_ABS_MIN) {
            cVar13 = cVar13 + '\x01';
          }
          if (cVar13 != '\x01') {
            if ((((d_bg_w::_3140 < local_104[0]) && (local_104[1] <= d_bg_w::_3140)) &&
                (local_104[2] <= d_bg_w::_3140)) ||
               (((local_104[0] < d_bg_w::_3140 && (d_bg_w::_3140 <= local_104[1])) &&
                (d_bg_w::_3140 <= local_104[2])))) {
              iVar16 = 0;
              iVar14 = 1;
              iVar17 = 2;
            }
            else {
              if ((((d_bg_w::_3140 < local_104[1]) && (local_104[0] <= d_bg_w::_3140)) &&
                  (local_104[2] <= d_bg_w::_3140)) ||
                 (((local_104[1] < d_bg_w::_3140 && (d_bg_w::_3140 <= local_104[0])) &&
                  (d_bg_w::_3140 <= local_104[2])))) {
                iVar16 = 1;
                iVar14 = 0;
                iVar17 = 2;
              }
              else {
                iVar16 = 2;
                iVar14 = 0;
                iVar17 = 1;
              }
            }
            fVar1 = local_104[iVar16];
            fVar2 = local_104[iVar14];
            fVar8 = fVar1 - fVar2;
            fVar7 = local_104[iVar17];
            fVar1 = fVar1 - fVar7;
            if ((SComponent::G_CM3D_F_ABS_MIN <= ABS(fVar8)) &&
               (SComponent::G_CM3D_F_ABS_MIN <= ABS(fVar1))) {
              fVar8 = -fVar2 / fVar8;
              fVar1 = -fVar7 / fVar1;
              pcVar19 = (this->parent).mpVtxTbl;
              fVar2 = pcVar19[(ushort)pcVar22->mVtxIdx0].x;
              fVar7 = pcVar19[(ushort)pcVar22->mVtxIdx0].z;
              fVar3 = pcVar19[(ushort)pcVar22->mVtxIdx1].x;
              fVar4 = pcVar19[(ushort)pcVar22->mVtxIdx1].z;
              fVar5 = pcVar19[(ushort)pcVar22->mVtxIdx2].x;
              fVar6 = pcVar19[(ushort)pcVar22->mVtxIdx2].z;
              if (iVar16 == 0) {
                fVar9 = fVar3 + fVar8 * (fVar2 - fVar3);
                fVar8 = fVar4 + fVar8 * (fVar7 - fVar4);
                fVar5 = fVar5 + fVar1 * (fVar2 - fVar5);
                fVar6 = fVar6 + fVar1 * (fVar7 - fVar6);
              }
              else {
                if (iVar16 == 1) {
                  fVar9 = fVar2 + fVar8 * (fVar3 - fVar2);
                  fVar8 = fVar7 + fVar8 * (fVar4 - fVar7);
                  fVar5 = fVar5 + fVar1 * (fVar3 - fVar5);
                  fVar6 = fVar6 + fVar1 * (fVar4 - fVar6);
                }
                else {
                  fVar9 = fVar2 + fVar8 * (fVar5 - fVar2);
                  fVar8 = fVar7 + fVar8 * (fVar6 - fVar7);
                  fVar5 = fVar3 + fVar1 * (fVar5 - fVar3);
                  fVar6 = fVar4 + fVar1 * (fVar6 - fVar4);
                }
              }
              dVar36 = (double)(fVar9 + local_f8.x);
              dVar35 = (double)(fVar8 + local_f8.z);
              dVar34 = (double)(fVar5 + local_f8.x);
              dVar33 = (double)(fVar6 + local_f8.z);
              uVar11 = SComponent::cM3d_Len2dSqPntAndSegLine
                                 (pAcch->mpPos->x,pAcch->mpPos->z,fVar9 + local_f8.x,
                                  fVar8 + local_f8.z,fVar5 + local_f8.x,fVar6 + local_f8.z,
                                  &local_10c,&local_110,&local_108);
              pcVar19 = pAcch->mpPos;
              dVar32 = (double)pcVar19->x;
              dVar27 = (double)pcVar19->z;
              dVar37 = (double)*(float *)((int)&pAcch->mpAcchCir->field_0x28 + iVar24);
              dVar28 = (double)local_108;
              if (dVar28 <= dVar37) {
                dVar29 = (double)local_f8.x;
                dVar31 = (double)local_f8.z;
                if ((double)d_bg_w::_3140 <=
                    (double)((float)((double)(float)((double)local_10c - dVar32) * dVar29) +
                            (float)((double)(float)((double)local_110 - dVar27) * dVar31))) {
                  if ((uVar11 & 0xff) == 1) {
                    if ((double)d_bg_w::_3140 < dVar28) {
                      dVar32 = 1.0 / SQRT(dVar28);
                      dVar32 = d_bg_w::_3141 * dVar32 * (d_bg_w::_3142 - dVar28 * dVar32 * dVar32);
                      dVar32 = d_bg_w::_3141 * dVar32 * (d_bg_w::_3142 - dVar28 * dVar32 * dVar32);
                      dVar28 = (double)(float)(dVar28 * d_bg_w::_3141 * dVar32 *
                                                        (d_bg_w::_3142 - dVar28 * dVar32 * dVar32));
                    }
                    positionWallCorrect(this,pAcch,(float)dVar30,&pPla->mPlane,pcVar19,(float)dVar28
                                       );
                    dBgS_Acch::SetWallCir(pAcch);
                    pcVar15 = pAcch->mpPos;
                    pcVar19 = pAcch->mpOldPos;
                    (pAcch->mLin).mP0.x = pcVar19->x;
                    (pAcch->mLin).mP0.y = pcVar19->y;
                    (pAcch->mLin).mP0.z = pcVar19->z;
                    (pAcch->mLin).mP1.x = pcVar15->x;
                    (pAcch->mLin).mP1.y = pcVar15->y;
                    (pAcch->mLin).mP1.z = pcVar15->z;
                    dBgS_Acch::CalcWallBmdCyl(pAcch);
                    *(uint *)((int)&pAcch->mpAcchCir->mFlags + iVar24) =
                         *(uint *)((int)&pAcch->mpAcchCir->mFlags + iVar24) | 2;
                    if (pAcch->mAcchCirCount < iVar23) {
                      uVar12 = JUTAssertion::getSDevice();
                      JUTAssertion::showAssert(uVar12,"d_bg_s_acch.h",0x274,"index <= m_tbl_size");
                      m_Do_printf::OSPanic("d_bg_s_acch.h",0x274,"Halt");
                    }
                    iVar16 = pAcch->mChkElmProcID;
                    pdVar20 = pAcch->mChkElmBgW;
                    iVar17 = pAcch->mChkElmIdx;
                    iVar14 = (int)&(pAcch->mpAcchCir->mPolyInfo).mTriIdx + iVar24;
                    if (iVar17 < 0) {
                      uVar12 = JUTAssertion::getSDevice();
                      JUTAssertion::showAssert(uVar12,"c_bg_s_poly_info.h",0x59,"0 <= bg_index");
                      m_Do_printf::OSPanic("c_bg_s_poly_info.h",0x59,"Halt");
                    }
                    *(short *)(iVar14 + 2) = (short)iVar17;
                    *(dBgW **)(iVar14 + 4) = pdVar20;
                    *(int *)(iVar14 + 8) = iVar16;
                    *(ushort *)((int)&(pAcch->mpAcchCir->mPolyInfo).mTriIdx + iVar24) = rwg;
                    iVar14 = SComponent::cM_atan2s((pPla->mPlane).mNorm.x,(pPla->mPlane).mNorm.z);
                    *(short *)((int)&pAcch->mpAcchCir->field_0x3c + iVar24) = (short)iVar14;
                    uVar18 = 1;
                  }
                  else {
                    dVar36 = (double)(float)(dVar36 - dVar29);
                    dVar35 = (double)(float)(dVar35 - dVar31);
                    dVar34 = (double)(float)(dVar34 - dVar29);
                    dVar33 = (double)(float)(dVar33 - dVar31);
                    dVar29 = (double)((float)(dVar36 - dVar32) * (float)(dVar36 - dVar32) +
                                     (float)(dVar35 - dVar27) * (float)(dVar35 - dVar27));
                    dVar28 = (double)((float)(dVar34 - dVar32) * (float)(dVar34 - dVar32) +
                                     (float)(dVar33 - dVar27) * (float)(dVar33 - dVar27));
                    dVar27 = -(double)(pPla->mPlane).mNorm.x;
                    dVar32 = -(double)(pPla->mPlane).mNorm.z;
                    bVar10 = false;
                    if (((float)ABS(dVar27) < SComponent::G_CM3D_F_ABS_MIN) &&
                       ((float)ABS(dVar32) < SComponent::G_CM3D_F_ABS_MIN)) {
                      bVar10 = true;
                    }
                    if (bVar10) {
                      uVar12 = JUTAssertion::getSDevice();
                      JUTAssertion::showAssert
                                (uVar12,"d_bg_w.cpp",0x1cf,"!(cM3d_IsZero(onx) && cM3d_IsZero(ony))"
                                );
                      m_Do_printf::OSPanic("d_bg_w.cpp",0x1cf,"Halt");
                    }
                    if (dVar28 <= dVar29) {
                      if ((dVar28 <= dVar37) && (d_bg_w::_3144 <= ABS((float)(dVar28 - dVar37)))) {
                        if (pAcch->mAcchCirCount < iVar23) {
                          uVar12 = JUTAssertion::getSDevice();
                          JUTAssertion::showAssert
                                    (uVar12,"d_bg_s_acch.h",0x2f9,"index <= m_tbl_size");
                          m_Do_printf::OSPanic("d_bg_s_acch.h",0x2f9,"Halt");
                        }
                        SComponent::cM2d_CrossCirLin
                                  ((cM2dGCir *)((int)&(pAcch->mpAcchCir->mCir).parent.x + iVar24),
                                   (float)dVar34,(float)dVar33,(float)dVar27,(float)dVar32,
                                   &local_11c,&local_120);
                        pAcch->mpPos->x = pAcch->mpPos->x + (float)(dVar34 - (double)local_11c);
                        pAcch->mpPos->z = pAcch->mpPos->z + (float)(dVar33 - (double)local_120);
                        fVar1 = pAcch->mpPos->x;
                        uVar11 = (uint)fVar1 & 0x7f800000;
                        if (uVar11 == 0x7f800000) {
                          if (((uint)fVar1 & 0x7fffff) == 0) {
                            iVar14 = 2;
                          }
                          else {
                            iVar14 = 1;
                          }
                        }
                        else {
                          if ((uVar11 < 0x7f800000) && (uVar11 == 0)) {
                            if (((uint)fVar1 & 0x7fffff) == 0) {
                              iVar14 = 3;
                            }
                            else {
                              iVar14 = 5;
                            }
                          }
                          else {
                            iVar14 = 4;
                          }
                        }
                        if (iVar14 == 1) {
                          uVar12 = JUTAssertion::getSDevice();
                          JUTAssertion::showAssert
                                    (uVar12,"d_bg_w.cpp",0x20c,
                                     "!(((sizeof(pwi->GetPos()->x) == sizeof(float)) ? __fpclassifyf((float)(pwi->GetPos()->x)) : __fpclassifyd((double)(pwi->GetPos()->x)) ) == 1)"
                                    );
                          m_Do_printf::OSPanic("d_bg_w.cpp",0x20c,"Halt");
                        }
                        fVar1 = pAcch->mpPos->z;
                        uVar11 = (uint)fVar1 & 0x7f800000;
                        if (uVar11 == 0x7f800000) {
                          if (((uint)fVar1 & 0x7fffff) == 0) {
                            iVar14 = 2;
                          }
                          else {
                            iVar14 = 1;
                          }
                        }
                        else {
                          if ((uVar11 < 0x7f800000) && (uVar11 == 0)) {
                            if (((uint)fVar1 & 0x7fffff) == 0) {
                              iVar14 = 3;
                            }
                            else {
                              iVar14 = 5;
                            }
                          }
                          else {
                            iVar14 = 4;
                          }
                        }
                        if (iVar14 == 1) {
                          uVar12 = JUTAssertion::getSDevice();
                          JUTAssertion::showAssert
                                    (uVar12,"d_bg_w.cpp",0x20d,
                                     "!(((sizeof(pwi->GetPos()->z) == sizeof(float)) ? __fpclassifyf((float)(pwi->GetPos()->z)) : __fpclassifyd((double)(pwi->GetPos()->z)) ) == 1)"
                                    );
                          m_Do_printf::OSPanic("d_bg_w.cpp",0x20d,"Halt");
                        }
                        dBgS_Acch::SetWallCir(pAcch);
                        pcVar15 = pAcch->mpPos;
                        pcVar19 = pAcch->mpOldPos;
                        (pAcch->mLin).mP0.x = pcVar19->x;
                        (pAcch->mLin).mP0.y = pcVar19->y;
                        (pAcch->mLin).mP0.z = pcVar19->z;
                        (pAcch->mLin).mP1.x = pcVar15->x;
                        (pAcch->mLin).mP1.y = pcVar15->y;
                        (pAcch->mLin).mP1.z = pcVar15->z;
                        dBgS_Acch::CalcWallBmdCyl(pAcch);
                        *(uint *)((int)&pAcch->mpAcchCir->mFlags + iVar24) =
                             *(uint *)((int)&pAcch->mpAcchCir->mFlags + iVar24) | 2;
                        if (pAcch->mAcchCirCount < iVar23) {
                          uVar12 = JUTAssertion::getSDevice();
                          JUTAssertion::showAssert
                                    (uVar12,"d_bg_s_acch.h",0x274,"index <= m_tbl_size");
                          m_Do_printf::OSPanic("d_bg_s_acch.h",0x274,"Halt");
                        }
                        iVar17 = pAcch->mChkElmProcID;
                        pdVar20 = pAcch->mChkElmBgW;
                        iVar16 = pAcch->mChkElmIdx;
                        iVar14 = (int)&(pAcch->mpAcchCir->mPolyInfo).mTriIdx + iVar24;
                        if (iVar16 < 0) {
                          uVar12 = JUTAssertion::getSDevice();
                          JUTAssertion::showAssert(uVar12,"c_bg_s_poly_info.h",0x59,"0 <= bg_index")
                          ;
                          m_Do_printf::OSPanic("c_bg_s_poly_info.h",0x59,"Halt");
                        }
                        *(short *)(iVar14 + 2) = (short)iVar16;
                        *(dBgW **)(iVar14 + 4) = pdVar20;
                        *(int *)(iVar14 + 8) = iVar17;
                        *(ushort *)((int)&(pAcch->mpAcchCir->mPolyInfo).mTriIdx + iVar24) = rwg;
                        iVar14 = SComponent::cM_atan2s
                                           ((pPla->mPlane).mNorm.x,(pPla->mPlane).mNorm.z);
                        *(short *)((int)&pAcch->mpAcchCir->field_0x3c + iVar24) = (short)iVar14;
                        uVar18 = 1;
                        pAcch->mFlags = pAcch->mFlags | 0x10;
                      }
                    }
                    else {
                      if ((dVar29 <= dVar37) && (d_bg_w::_3144 <= ABS((float)(dVar29 - dVar37)))) {
                        if (pAcch->mAcchCirCount < iVar23) {
                          uVar12 = JUTAssertion::getSDevice();
                          JUTAssertion::showAssert
                                    (uVar12,"d_bg_s_acch.h",0x2f9,"index <= m_tbl_size");
                          m_Do_printf::OSPanic("d_bg_s_acch.h",0x2f9,"Halt");
                        }
                        SComponent::cM2d_CrossCirLin
                                  ((cM2dGCir *)((int)&(pAcch->mpAcchCir->mCir).parent.x + iVar24),
                                   (float)dVar36,(float)dVar35,(float)dVar27,(float)dVar32,
                                   &local_114,&local_118);
                        pAcch->mpPos->x = pAcch->mpPos->x + (float)(dVar36 - (double)local_114);
                        pAcch->mpPos->z = pAcch->mpPos->z + (float)(dVar35 - (double)local_118);
                        fVar1 = pAcch->mpPos->x;
                        uVar11 = (uint)fVar1 & 0x7f800000;
                        if (uVar11 == 0x7f800000) {
                          if (((uint)fVar1 & 0x7fffff) == 0) {
                            iVar14 = 2;
                          }
                          else {
                            iVar14 = 1;
                          }
                        }
                        else {
                          if ((uVar11 < 0x7f800000) && (uVar11 == 0)) {
                            if (((uint)fVar1 & 0x7fffff) == 0) {
                              iVar14 = 3;
                            }
                            else {
                              iVar14 = 5;
                            }
                          }
                          else {
                            iVar14 = 4;
                          }
                        }
                        if (iVar14 == 1) {
                          uVar12 = JUTAssertion::getSDevice();
                          JUTAssertion::showAssert
                                    (uVar12,"d_bg_w.cpp",0x1e4,
                                     "!(((sizeof(pwi->GetPos()->x) == sizeof(float)) ? __fpclassifyf((float)(pwi->GetPos()->x)) : __fpclassifyd((double)(pwi->GetPos()->x)) ) == 1)"
                                    );
                          m_Do_printf::OSPanic("d_bg_w.cpp",0x1e4,"Halt");
                        }
                        fVar1 = pAcch->mpPos->z;
                        uVar11 = (uint)fVar1 & 0x7f800000;
                        if (uVar11 == 0x7f800000) {
                          if (((uint)fVar1 & 0x7fffff) == 0) {
                            iVar14 = 2;
                          }
                          else {
                            iVar14 = 1;
                          }
                        }
                        else {
                          if ((uVar11 < 0x7f800000) && (uVar11 == 0)) {
                            if (((uint)fVar1 & 0x7fffff) == 0) {
                              iVar14 = 3;
                            }
                            else {
                              iVar14 = 5;
                            }
                          }
                          else {
                            iVar14 = 4;
                          }
                        }
                        if (iVar14 == 1) {
                          uVar12 = JUTAssertion::getSDevice();
                          JUTAssertion::showAssert
                                    (uVar12,"d_bg_w.cpp",0x1e5,
                                     "!(((sizeof(pwi->GetPos()->z) == sizeof(float)) ? __fpclassifyf((float)(pwi->GetPos()->z)) : __fpclassifyd((double)(pwi->GetPos()->z)) ) == 1)"
                                    );
                          m_Do_printf::OSPanic("d_bg_w.cpp",0x1e5,"Halt");
                        }
                        dBgS_Acch::SetWallCir(pAcch);
                        pcVar15 = pAcch->mpPos;
                        pcVar19 = pAcch->mpOldPos;
                        (pAcch->mLin).mP0.x = pcVar19->x;
                        (pAcch->mLin).mP0.y = pcVar19->y;
                        (pAcch->mLin).mP0.z = pcVar19->z;
                        (pAcch->mLin).mP1.x = pcVar15->x;
                        (pAcch->mLin).mP1.y = pcVar15->y;
                        (pAcch->mLin).mP1.z = pcVar15->z;
                        dBgS_Acch::CalcWallBmdCyl(pAcch);
                        *(uint *)((int)&pAcch->mpAcchCir->mFlags + iVar24) =
                             *(uint *)((int)&pAcch->mpAcchCir->mFlags + iVar24) | 2;
                        if (pAcch->mAcchCirCount < iVar23) {
                          uVar12 = JUTAssertion::getSDevice();
                          JUTAssertion::showAssert
                                    (uVar12,"d_bg_s_acch.h",0x274,"index <= m_tbl_size");
                          m_Do_printf::OSPanic("d_bg_s_acch.h",0x274,"Halt");
                        }
                        iVar17 = pAcch->mChkElmProcID;
                        pdVar20 = pAcch->mChkElmBgW;
                        iVar16 = pAcch->mChkElmIdx;
                        iVar14 = (int)&(pAcch->mpAcchCir->mPolyInfo).mTriIdx + iVar24;
                        if (iVar16 < 0) {
                          uVar12 = JUTAssertion::getSDevice();
                          JUTAssertion::showAssert(uVar12,"c_bg_s_poly_info.h",0x59,"0 <= bg_index")
                          ;
                          m_Do_printf::OSPanic("c_bg_s_poly_info.h",0x59,"Halt");
                        }
                        *(short *)(iVar14 + 2) = (short)iVar16;
                        *(dBgW **)(iVar14 + 4) = pdVar20;
                        *(int *)(iVar14 + 8) = iVar17;
                        *(ushort *)((int)&(pAcch->mpAcchCir->mPolyInfo).mTriIdx + iVar24) = rwg;
                        iVar14 = SComponent::cM_atan2s
                                           ((pPla->mPlane).mNorm.x,(pPla->mPlane).mNorm.z);
                        *(short *)((int)&pAcch->mpAcchCir->field_0x3c + iVar24) = (short)iVar14;
                        uVar18 = 1;
                        pAcch->mFlags = pAcch->mFlags | 0x10;
                      }
                    }
                  }
                }
              }
            }
          }
        }
        iVar24 = iVar24 + 0x40;
      }
      goto LAB_800a6d74;
    }
    rwg = pcVar21[rwg].mNext;
  } while (rwg != 0xffff);
LAB_800a6d84:
  __psq_l0(auStack8,uVar25);
  __psq_l1(auStack8,uVar25);
  __psq_l0(auStack24,uVar25);
  __psq_l1(auStack24,uVar25);
  __psq_l0(auStack40,uVar25);
  __psq_l1(auStack40,uVar25);
  __psq_l0(auStack56,uVar25);
  __psq_l1(auStack56,uVar25);
  __psq_l0(auStack72,uVar25);
  __psq_l1(auStack72,uVar25);
  __psq_l0(auStack88,uVar25);
  __psq_l1(auStack88,uVar25);
  __psq_l0(auStack104,uVar25);
  __psq_l1(auStack104,uVar25);
  __psq_l0(auStack120,uVar25);
  __psq_l1(auStack120,uVar25);
  __psq_l0(auStack136,uVar25);
  __psq_l1(auStack136,uVar25);
  __psq_l0(auStack152,uVar25);
  __psq_l1(auStack152,uVar25);
  __psq_l0(auStack168,uVar25);
  __psq_l1(auStack168,uVar25);
  return uVar18;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dBgW::WallCorrectRp(dBgS_Acch *,
                                  int) */

undefined4 __thiscall dBgW::WallCorrectRp(dBgW *this,dBgS_Acch *pAcch,int node)

{
  ushort uVar1;
  char cVar3;
  undefined4 uVar2;
  cBgD__Tree_t *pcVar4;
  
  cVar3 = SComponent::cM3d_Cross_AabCyl((this->parent).mpNodeTree + node,&pAcch->mCyl);
  if (cVar3 == '\0') {
    uVar2 = 0;
  }
  else {
    pcVar4 = ((this->parent).mpBgDt)->mpNodeTreeTbl + node;
    uVar2 = 0;
    if ((pcVar4->mFlag & 1) == 0) {
      if ((pcVar4->mChild0 != 0xffff) &&
         (cVar3 = WallCorrectRp(this,pAcch,(uint)pcVar4->mChild0), cVar3 != '\0')) {
        uVar2 = 1;
      }
      if ((pcVar4->mChild1 != 0xffff) &&
         (cVar3 = WallCorrectRp(this,pAcch,(uint)pcVar4->mChild1), cVar3 != '\0')) {
        uVar2 = 1;
      }
      if ((pcVar4->mChild2 != 0xffff) &&
         (cVar3 = WallCorrectRp(this,pAcch,(uint)pcVar4->mChild2), cVar3 != '\0')) {
        uVar2 = 1;
      }
      if ((pcVar4->mChild3 != 0xffff) &&
         (cVar3 = WallCorrectRp(this,pAcch,(uint)pcVar4->mChild3), cVar3 != '\0')) {
        uVar2 = 1;
      }
      if ((pcVar4->mChild4 != 0xffff) &&
         (cVar3 = WallCorrectRp(this,pAcch,(uint)pcVar4->mChild4), cVar3 != '\0')) {
        uVar2 = 1;
      }
      if ((pcVar4->mChild5 != 0xffff) &&
         (cVar3 = WallCorrectRp(this,pAcch,(uint)pcVar4->mChild5), cVar3 != '\0')) {
        uVar2 = 1;
      }
      if ((pcVar4->mChild6 != 0xffff) &&
         (cVar3 = WallCorrectRp(this,pAcch,(uint)pcVar4->mChild6), cVar3 != '\0')) {
        uVar2 = 1;
      }
      if ((pcVar4->mChild7 != 0xffff) &&
         (cVar3 = WallCorrectRp(this,pAcch,(uint)pcVar4->mChild7), cVar3 != '\0')) {
        uVar2 = 1;
      }
    }
    else {
      uVar1 = (this->parent).mpBlk[pcVar4->mChild0].mWallIdx;
      if ((uVar1 != 0xffff) && (cVar3 = RwgWallCorrect(this,pAcch,uVar1), cVar3 != '\0')) {
        uVar2 = 1;
      }
      uVar1 = (this->parent).mpBlk[pcVar4->mChild0].mRoofIdx;
      if ((uVar1 != 0xffff) && (cVar3 = RwgWallCorrect(this,pAcch,uVar1), cVar3 != '\0')) {
        uVar2 = 1;
      }
    }
  }
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dBgW::WallCorrectGrpRp(dBgS_Acch *,
                                     int,
                                     int) */

undefined4 __thiscall dBgW::WallCorrectGrpRp(dBgW *this,dBgS_Acch *param_1,int param_2,int param_3)

{
  ushort uVar1;
  char cVar3;
  undefined4 uVar2;
  uint uVar4;
  
  cVar3 = (**(code **)((this->parent).vtbl + 0x20))(this,param_2,(param_1->mChk).mpGrpPassChk);
  if (cVar3 == '\0') {
    cVar3 = SComponent::cM3d_Cross_AabCyl(&(this->parent).mpGrp[param_2].mAabb,&param_1->mCyl);
    if (cVar3 == '\0') {
      uVar2 = 0;
    }
    else {
      uVar2 = 0;
      uVar4 = (uint)((this->parent).mpBgDt)->mpGrpTbl[param_2].mTreIdx;
      if ((uVar4 != 0xffff) && (cVar3 = WallCorrectRp(this,param_1,uVar4), cVar3 != '\0')) {
        uVar2 = 1;
      }
      uVar1 = ((this->parent).mpBgDt)->mpGrpTbl[param_2].mFirstChild;
      while (uVar4 = (uint)uVar1, uVar4 != 0xffff) {
        cVar3 = WallCorrectGrpRp(this,param_1,uVar4,param_3 + 1);
        if (cVar3 != '\0') {
          uVar2 = 1;
        }
        uVar1 = ((this->parent).mpBgDt)->mpGrpTbl[uVar4].mNextSibling;
      }
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x800a7258) */
/* WARNING: Removing unreachable block (ram,0x800a72b8) */
/* WARNING: Removing unreachable block (ram,0x800a72c0) */
/* __thiscall dBgW::RwgRoofChk(unsigned short,
                               dBgS_RoofChk *) */

undefined4 __thiscall dBgW::RwgRoofChk(dBgW *this,ushort param_1,dBgS_RoofChk *param_2)

{
  float fVar1;
  uint uVar2;
  cBgW_TriElm *pcVar3;
  char cVar4;
  cXyz *pcVar5;
  cBgD__Tri_t *pcVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined8 in_f30;
  double dVar9;
  undefined8 in_f31;
  double dVar10;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar8 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  uVar7 = 0;
  dVar10 = (double)SComponent::G_CM3D_F_ABS_MIN;
  do {
    uVar2 = (uint)param_1;
    pcVar3 = (this->parent).mpTriElm + uVar2;
    fVar1 = (pcVar3->mPlane).mNorm.y;
    if (((dVar10 <= (double)ABS(fVar1)) &&
        (dVar9 = (double)(((-(pcVar3->mPlane).mNorm.x * (param_2->mPos).x -
                           (pcVar3->mPlane).mNorm.z * (param_2->mPos).z) - (pcVar3->mPlane).mDist) /
                         fVar1), (double)(param_2->mPos).y < dVar9)) &&
       (dVar9 < (double)(float)param_2[1].mPolyInfo.mpBgW)) {
      pcVar6 = ((this->parent).mpBgDt)->mpTriTbl + uVar2;
      pcVar5 = (this->parent).mpVtxTbl;
      cVar4 = SComponent::cM3d_CrossY_Tri
                        (pcVar5 + (ushort)pcVar6->mVtxIdx0,pcVar5 + (ushort)pcVar6->mVtxIdx1,
                         pcVar5 + (ushort)pcVar6->mVtxIdx2,(this->parent).mpTriElm + uVar2,
                         &param_2->mPos);
      if ((cVar4 != '\0') &&
         (cVar4 = (**(code **)((this->parent).vtbl + 0x18))
                            (this,param_1,(param_2->mChk).mpPolyPassChk), cVar4 == '\0')) {
        param_2[1].mPolyInfo.mpBgW = (cBgW *)(float)dVar9;
        (param_2->mPolyInfo).mTriIdx = param_1;
        uVar7 = 1;
      }
    }
    param_1 = (this->parent).mpRwg[uVar2].mNext;
  } while (param_1 != 0xffff);
  __psq_l0(auStack8,uVar8);
  __psq_l1(auStack8,uVar8);
  __psq_l0(auStack24,uVar8);
  __psq_l1(auStack24,uVar8);
  return uVar7;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dBgW::RoofChkRp(dBgS_RoofChk *,
                              int) */

undefined4 __thiscall dBgW::RoofChkRp(dBgW *this,dBgS_RoofChk *param_1,int param_2)

{
  float fVar1;
  ushort uVar2;
  bool bVar3;
  cBgW_NodeTree *pcVar4;
  undefined4 uVar5;
  char cVar6;
  cBgD__Tree_t *pcVar7;
  
  pcVar4 = (this->parent).mpNodeTree + param_2;
  fVar1 = (param_1->mPos).x;
  if ((((fVar1 < (pcVar4->mMin).x) || ((pcVar4->mMax).x < fVar1)) ||
      (fVar1 = (param_1->mPos).z, fVar1 < (pcVar4->mMin).z)) || ((pcVar4->mMax).z < fVar1)) {
    bVar3 = false;
  }
  else {
    bVar3 = true;
  }
  if (((!bVar3) || ((float)param_1[1].mPolyInfo.mpBgW <= (pcVar4->mMin).y)) ||
     ((pcVar4->mMax).y < (param_1->mPos).y)) {
    uVar5 = 0;
  }
  else {
    pcVar7 = ((this->parent).mpBgDt)->mpNodeTreeTbl + param_2;
    if ((pcVar7->mFlag & 1) == 0) {
      uVar5 = 0;
      if ((pcVar7->mChild0 != 0xffff) &&
         (cVar6 = RoofChkRp(this,param_1,(uint)pcVar7->mChild0), cVar6 != '\0')) {
        uVar5 = 1;
      }
      if ((pcVar7->mChild1 != 0xffff) &&
         (cVar6 = RoofChkRp(this,param_1,(uint)pcVar7->mChild1), cVar6 != '\0')) {
        uVar5 = 1;
      }
      if ((pcVar7->mChild2 != 0xffff) &&
         (cVar6 = RoofChkRp(this,param_1,(uint)pcVar7->mChild2), cVar6 != '\0')) {
        uVar5 = 1;
      }
      if ((pcVar7->mChild3 != 0xffff) &&
         (cVar6 = RoofChkRp(this,param_1,(uint)pcVar7->mChild3), cVar6 != '\0')) {
        uVar5 = 1;
      }
      if ((pcVar7->mChild4 != 0xffff) &&
         (cVar6 = RoofChkRp(this,param_1,(uint)pcVar7->mChild4), cVar6 != '\0')) {
        uVar5 = 1;
      }
      if ((pcVar7->mChild5 != 0xffff) &&
         (cVar6 = RoofChkRp(this,param_1,(uint)pcVar7->mChild5), cVar6 != '\0')) {
        uVar5 = 1;
      }
      if ((pcVar7->mChild6 != 0xffff) &&
         (cVar6 = RoofChkRp(this,param_1,(uint)pcVar7->mChild6), cVar6 != '\0')) {
        uVar5 = 1;
      }
      if ((pcVar7->mChild7 != 0xffff) &&
         (cVar6 = RoofChkRp(this,param_1,(uint)pcVar7->mChild7), cVar6 != '\0')) {
        uVar5 = 1;
      }
    }
    else {
      uVar2 = (this->parent).mpBlk[pcVar7->mChild0].mRoofIdx;
      if ((uVar2 == 0xffff) || (cVar6 = RwgRoofChk(this,uVar2,param_1), cVar6 == '\0')) {
        uVar5 = 0;
      }
      else {
        uVar5 = 1;
      }
    }
  }
  return uVar5;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dBgW::RoofChkGrpRp(dBgS_RoofChk *,
                                 int,
                                 int) */

undefined4 __thiscall dBgW::RoofChkGrpRp(dBgW *this,dBgS_RoofChk *param_1,int param_2,int param_3)

{
  float fVar1;
  ushort uVar2;
  bool bVar3;
  char cVar6;
  undefined4 uVar4;
  cBgW_GrpElm *pcVar5;
  uint uVar7;
  cBgD__Grp_t *pcVar8;
  
  cVar6 = (**(code **)((this->parent).vtbl + 0x20))(this,param_2,(param_1->mChk).mpGrpPassChk);
  if (cVar6 == '\0') {
    pcVar5 = (this->parent).mpGrp + param_2;
    fVar1 = (param_1->mPos).x;
    if ((((fVar1 < (pcVar5->mAabb).mMin.x) || ((pcVar5->mAabb).mMax.x < fVar1)) ||
        (fVar1 = (param_1->mPos).z, fVar1 < (pcVar5->mAabb).mMin.z)) ||
       ((pcVar5->mAabb).mMax.z < fVar1)) {
      bVar3 = false;
    }
    else {
      bVar3 = true;
    }
    if (((!bVar3) || ((float)param_1[1].mPolyInfo.mpBgW <= (pcVar5->mAabb).mMin.y)) ||
       ((pcVar5->mAabb).mMax.y < (param_1->mPos).y)) {
      uVar4 = 0;
    }
    else {
      uVar4 = 0;
      pcVar8 = ((this->parent).mpBgDt)->mpGrpTbl + param_2;
      uVar7 = (uint)pcVar8->mTreIdx;
      if ((uVar7 != 0xffff) && (cVar6 = RoofChkRp(this,param_1,uVar7), cVar6 != '\0')) {
        uVar4 = 1;
      }
      uVar2 = pcVar8->mFirstChild;
      while (uVar7 = (uint)uVar2, uVar7 != 0xffff) {
        cVar6 = RoofChkGrpRp(this,param_1,uVar7,param_3 + 1);
        if (cVar6 != '\0') {
          uVar4 = 1;
        }
        uVar2 = ((this->parent).mpBgDt)->mpGrpTbl[uVar7].mNextSibling;
      }
    }
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x800a77b4) */
/* WARNING: Removing unreachable block (ram,0x800a7814) */
/* WARNING: Removing unreachable block (ram,0x800a781c) */
/* __thiscall dBgW::RwgSplGrpChk(unsigned short,
                                 dBgS_SplGrpChk *) */

undefined4 __thiscall dBgW::RwgSplGrpChk(dBgW *this,ushort param_1,dBgS_SplGrpChk *param_2)

{
  float fVar1;
  uint uVar2;
  cBgW_TriElm *pcVar3;
  char cVar4;
  cXyz *pcVar5;
  cBgD__Tri_t *pcVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined8 in_f30;
  double dVar9;
  undefined8 in_f31;
  double dVar10;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar8 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  uVar7 = 0;
  dVar10 = (double)SComponent::G_CM3D_F_ABS_MIN;
  do {
    uVar2 = (uint)param_1;
    pcVar3 = (this->parent).mpTriElm + uVar2;
    fVar1 = (pcVar3->mPlane).mNorm.y;
    if (((dVar10 <= (double)ABS(fVar1)) &&
        (dVar9 = (double)(((-(pcVar3->mPlane).mNorm.x * (param_2->mStartPos).x -
                           (pcVar3->mPlane).mNorm.z * (param_2->mStartPos).z) -
                          (pcVar3->mPlane).mDist) / fVar1), dVar9 < (double)param_2->mEndPosY)) &&
       ((double)param_2->mHeight < dVar9)) {
      pcVar6 = ((this->parent).mpBgDt)->mpTriTbl + uVar2;
      pcVar5 = (this->parent).mpVtxTbl;
      cVar4 = SComponent::cM3d_CrossY_Tri
                        (pcVar5 + (ushort)pcVar6->mVtxIdx0,pcVar5 + (ushort)pcVar6->mVtxIdx1,
                         pcVar5 + (ushort)pcVar6->mVtxIdx2,(this->parent).mpTriElm + uVar2,
                         &param_2->mStartPos);
      if ((cVar4 != '\0') &&
         (cVar4 = (**(code **)((this->parent).vtbl + 0x18))
                            (this,param_1,(param_2->mChk).mpPolyPassChk), cVar4 == '\0')) {
        param_2->mHeight = (float)dVar9;
        (param_2->mPolyInfo).mTriIdx = param_1;
        uVar7 = 1;
      }
    }
    param_1 = (this->parent).mpRwg[uVar2].mNext;
  } while (param_1 != 0xffff);
  __psq_l0(auStack8,uVar8);
  __psq_l1(auStack8,uVar8);
  __psq_l0(auStack24,uVar8);
  __psq_l1(auStack24,uVar8);
  return uVar7;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dBgW::SplGrpChkRp(dBgS_SplGrpChk *,
                                int) */

undefined4 __thiscall dBgW::SplGrpChkRp(dBgW *this,dBgS_SplGrpChk *param_1,int param_2)

{
  float fVar1;
  ushort uVar2;
  bool bVar3;
  cBgW_NodeTree *pcVar4;
  undefined4 uVar5;
  char cVar6;
  cBgD__Tree_t *pcVar7;
  
  pcVar4 = (this->parent).mpNodeTree + param_2;
  fVar1 = (param_1->mStartPos).x;
  if ((((fVar1 < (pcVar4->mMin).x) || ((pcVar4->mMax).x < fVar1)) ||
      (fVar1 = (param_1->mStartPos).z, fVar1 < (pcVar4->mMin).z)) || ((pcVar4->mMax).z < fVar1)) {
    bVar3 = false;
  }
  else {
    bVar3 = true;
  }
  if (((!bVar3) || (param_1->mEndPosY <= (pcVar4->mMin).y)) || ((pcVar4->mMax).y < param_1->mHeight)
     ) {
    uVar5 = 0;
  }
  else {
    pcVar7 = ((this->parent).mpBgDt)->mpNodeTreeTbl + param_2;
    if ((pcVar7->mFlag & 1) == 0) {
      uVar5 = 0;
      if ((pcVar7->mChild0 != 0xffff) &&
         (cVar6 = SplGrpChkRp(this,param_1,(uint)pcVar7->mChild0), cVar6 != '\0')) {
        uVar5 = 1;
      }
      if ((pcVar7->mChild1 != 0xffff) &&
         (cVar6 = SplGrpChkRp(this,param_1,(uint)pcVar7->mChild1), cVar6 != '\0')) {
        uVar5 = 1;
      }
      if ((pcVar7->mChild2 != 0xffff) &&
         (cVar6 = SplGrpChkRp(this,param_1,(uint)pcVar7->mChild2), cVar6 != '\0')) {
        uVar5 = 1;
      }
      if ((pcVar7->mChild3 != 0xffff) &&
         (cVar6 = SplGrpChkRp(this,param_1,(uint)pcVar7->mChild3), cVar6 != '\0')) {
        uVar5 = 1;
      }
      if ((pcVar7->mChild4 != 0xffff) &&
         (cVar6 = SplGrpChkRp(this,param_1,(uint)pcVar7->mChild4), cVar6 != '\0')) {
        uVar5 = 1;
      }
      if ((pcVar7->mChild5 != 0xffff) &&
         (cVar6 = SplGrpChkRp(this,param_1,(uint)pcVar7->mChild5), cVar6 != '\0')) {
        uVar5 = 1;
      }
      if ((pcVar7->mChild6 != 0xffff) &&
         (cVar6 = SplGrpChkRp(this,param_1,(uint)pcVar7->mChild6), cVar6 != '\0')) {
        uVar5 = 1;
      }
      if ((pcVar7->mChild7 != 0xffff) &&
         (cVar6 = SplGrpChkRp(this,param_1,(uint)pcVar7->mChild7), cVar6 != '\0')) {
        uVar5 = 1;
      }
    }
    else {
      uVar2 = (this->parent).mpBlk[pcVar7->mChild0].mGroundIdx;
      if ((uVar2 == 0xffff) || (cVar6 = RwgSplGrpChk(this,uVar2,param_1), cVar6 == '\0')) {
        uVar5 = 0;
      }
      else {
        uVar5 = 1;
      }
    }
  }
  return uVar5;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dBgW::SplGrpChkGrpRp(dBgS_SplGrpChk *,
                                   int,
                                   int) */

undefined4 __thiscall
dBgW::SplGrpChkGrpRp(dBgW *this,dBgS_SplGrpChk *param_1,int param_2,int param_3)

{
  float fVar1;
  ushort uVar2;
  bool bVar3;
  char cVar6;
  undefined4 uVar4;
  cBgW_GrpElm *pcVar5;
  uint uVar7;
  cBgD__Grp_t *pcVar8;
  
  cVar6 = (**(code **)((this->parent).vtbl + 0x20))(this,param_2,(param_1->mChk).mpGrpPassChk);
  if (cVar6 == '\0') {
    pcVar5 = (this->parent).mpGrp + param_2;
    fVar1 = (param_1->mStartPos).x;
    if ((((fVar1 < (pcVar5->mAabb).mMin.x) || ((pcVar5->mAabb).mMax.x < fVar1)) ||
        (fVar1 = (param_1->mStartPos).z, fVar1 < (pcVar5->mAabb).mMin.z)) ||
       ((pcVar5->mAabb).mMax.z < fVar1)) {
      bVar3 = false;
    }
    else {
      bVar3 = true;
    }
    if (((!bVar3) || (param_1->mEndPosY <= (pcVar5->mAabb).mMin.y)) ||
       ((pcVar5->mAabb).mMax.y < param_1->mHeight)) {
      uVar4 = 0;
    }
    else {
      uVar4 = 0;
      pcVar8 = ((this->parent).mpBgDt)->mpGrpTbl + param_2;
      uVar7 = (uint)pcVar8->mTreIdx;
      if ((uVar7 != 0xffff) && (cVar6 = SplGrpChkRp(this,param_1,uVar7), cVar6 != '\0')) {
        uVar4 = 1;
      }
      uVar2 = pcVar8->mFirstChild;
      while (uVar7 = (uint)uVar2, uVar7 != 0xffff) {
        cVar6 = SplGrpChkGrpRp(this,param_1,uVar7,param_3 + 1);
        if (cVar6 != '\0') {
          uVar4 = 1;
        }
        uVar2 = ((this->parent).mpBgDt)->mpGrpTbl[uVar7].mNextSibling;
      }
    }
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}


/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* WARNING: Removing unreachable block (ram,0x800a7d48) */
/* __thiscall dBgW::RwgSphChk(unsigned short,
                              dBgS_SphChk *,
                              void *) */

undefined4 __thiscall dBgW::RwgSphChk(dBgW *this,ushort param_1,dBgS_SphChk *param_2,void *param_3)

{
  uint uVar1;
  char cVar3;
  cXyz *pcVar2;
  cXyz *pcVar4;
  cXyz *pcVar5;
  cBgW_TriElm *pcVar6;
  undefined4 uVar7;
  cBgD__Tri_t *pcVar8;
  cBgW_RwgElm *pcVar9;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  undefined **local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  
  local_58 = &cM3dGTri::__vt;
  uVar7 = 0;
  do {
    pcVar9 = (this->parent).mpRwg;
    uVar1 = (uint)param_1;
    cVar3 = (**(code **)((this->parent).vtbl + 0x18))(this,uVar1,(param_2->mChk).mpPolyPassChk);
    if (cVar3 == '\0') {
      pcVar8 = ((this->parent).mpBgDt)->mpTriTbl + uVar1;
      pcVar6 = (this->parent).mpTriElm + uVar1;
      pcVar2 = (this->parent).mpVtxTbl;
      pcVar5 = pcVar2 + (ushort)pcVar8->mVtxIdx2;
      pcVar4 = pcVar2 + (ushort)pcVar8->mVtxIdx1;
      pcVar2 = pcVar2 + (ushort)pcVar8->mVtxIdx0;
      local_54 = pcVar2->x;
      local_50 = pcVar2->y;
      local_4c = pcVar2->z;
      local_48 = pcVar4->x;
      local_44 = pcVar4->y;
      local_40 = pcVar4->z;
      local_3c = pcVar5->x;
      local_38 = pcVar5->y;
      local_34 = pcVar5->z;
      local_68 = (pcVar6->mPlane).mNorm.x;
      local_64 = (pcVar6->mPlane).mNorm.y;
      local_60 = (pcVar6->mPlane).mNorm.z;
      local_5c = (pcVar6->mPlane).mDist;
      cVar3 = SComponent::cM3d_Cross_SphTri(param_2,&local_68,0);
      if (cVar3 != '\0') {
        if ((code *)param_2->mCallBack != (code *)0x0) {
          (*(code *)param_2->mCallBack)
                    (param_2,(this->parent).mpVtxTbl,pcVar8->mVtxIdx0,pcVar8->mVtxIdx1,
                     pcVar8->mVtxIdx2,(this->parent).mpTriElm + uVar1,param_3);
        }
        (param_2->mPolyInfo).mTriIdx = param_1;
        uVar7 = 1;
      }
    }
    param_1 = pcVar9[param_1].mNext;
  } while (param_1 != 0xffff);
  return uVar7;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dBgW::SphChkRp(dBgS_SphChk *,
                             void *,
                             int) */

undefined4 __thiscall dBgW::SphChkRp(dBgW *this,dBgS_SphChk *param_1,void *param_2,int param_3)

{
  ushort uVar1;
  char cVar3;
  undefined4 uVar2;
  cBgD__Tree_t *pcVar4;
  
  cVar3 = SComponent::cM3d_Cross_AabSph((this->parent).mpNodeTree + param_3);
  if (cVar3 == '\0') {
    uVar2 = 0;
  }
  else {
    pcVar4 = ((this->parent).mpBgDt)->mpNodeTreeTbl + param_3;
    uVar2 = 0;
    if ((pcVar4->mFlag & 1) == 0) {
      if ((pcVar4->mChild0 != 0xffff) &&
         (cVar3 = SphChkRp(this,param_1,param_2,(uint)pcVar4->mChild0), cVar3 != '\0')) {
        uVar2 = 1;
      }
      if ((pcVar4->mChild1 != 0xffff) &&
         (cVar3 = SphChkRp(this,param_1,param_2,(uint)pcVar4->mChild1), cVar3 != '\0')) {
        uVar2 = 1;
      }
      if ((pcVar4->mChild2 != 0xffff) &&
         (cVar3 = SphChkRp(this,param_1,param_2,(uint)pcVar4->mChild2), cVar3 != '\0')) {
        uVar2 = 1;
      }
      if ((pcVar4->mChild3 != 0xffff) &&
         (cVar3 = SphChkRp(this,param_1,param_2,(uint)pcVar4->mChild3), cVar3 != '\0')) {
        uVar2 = 1;
      }
      if ((pcVar4->mChild4 != 0xffff) &&
         (cVar3 = SphChkRp(this,param_1,param_2,(uint)pcVar4->mChild4), cVar3 != '\0')) {
        uVar2 = 1;
      }
      if ((pcVar4->mChild5 != 0xffff) &&
         (cVar3 = SphChkRp(this,param_1,param_2,(uint)pcVar4->mChild5), cVar3 != '\0')) {
        uVar2 = 1;
      }
      if ((pcVar4->mChild6 != 0xffff) &&
         (cVar3 = SphChkRp(this,param_1,param_2,(uint)pcVar4->mChild6), cVar3 != '\0')) {
        uVar2 = 1;
      }
      if ((pcVar4->mChild7 != 0xffff) &&
         (cVar3 = SphChkRp(this,param_1,param_2,(uint)pcVar4->mChild7), cVar3 != '\0')) {
        uVar2 = 1;
      }
    }
    else {
      uVar1 = (this->parent).mpBlk[pcVar4->mChild0].mGroundIdx;
      if ((uVar1 != 0xffff) && (cVar3 = RwgSphChk(this,uVar1,param_1,param_2), cVar3 != '\0')) {
        uVar2 = 1;
      }
      uVar1 = (this->parent).mpBlk[pcVar4->mChild0].mRoofIdx;
      if ((uVar1 != 0xffff) && (cVar3 = RwgSphChk(this,uVar1,param_1,param_2), cVar3 != '\0')) {
        uVar2 = 1;
      }
      uVar1 = (this->parent).mpBlk[pcVar4->mChild0].mWallIdx;
      if ((uVar1 != 0xffff) && (cVar3 = RwgSphChk(this,uVar1,param_1,param_2), cVar3 != '\0')) {
        uVar2 = 1;
      }
    }
  }
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall dBgW::SphChkGrpRp(dBgS_SphChk *,
                                void *,
                                int,
                                int) */

undefined4 __thiscall
dBgW::SphChkGrpRp(dBgW *this,dBgS_SphChk *param_1,void *param_2,int param_3,int param_4)

{
  ushort uVar1;
  char cVar3;
  undefined4 uVar2;
  uint uVar4;
  cBgD__Grp_t *pcVar5;
  
  cVar3 = (**(code **)((this->parent).vtbl + 0x20))
                    (this,param_3,(param_1->mChk).mpGrpPassChk,param_4);
  if (cVar3 == '\0') {
    cVar3 = SComponent::cM3d_Cross_AabSph(&(this->parent).mpGrp[param_3].mAabb,param_1);
    if (cVar3 == '\0') {
      uVar2 = 0;
    }
    else {
      uVar2 = 0;
      pcVar5 = ((this->parent).mpBgDt)->mpGrpTbl + param_3;
      uVar4 = (uint)pcVar5->mTreIdx;
      if ((uVar4 != 0xffff) && (cVar3 = SphChkRp(this,param_1,param_2,uVar4), cVar3 != '\0')) {
        uVar2 = 1;
      }
      uVar1 = pcVar5->mFirstChild;
      while (uVar4 = (uint)uVar1, uVar4 != 0xffff) {
        cVar3 = SphChkGrpRp(this,param_1,param_2,uVar4,param_4 + 1);
        if (cVar3 != '\0') {
          uVar2 = 1;
        }
        uVar1 = ((this->parent).mpBgDt)->mpGrpTbl[uVar4].mNextSibling;
      }
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


/* __thiscall dBgW::positionWallCrrPos(cM3dGTri &,
                                       dBgS_CrrPos *,
                                       cXyz *,
                                       float,
                                       float) */

void __thiscall
dBgW::positionWallCrrPos
          (dBgW *this,cM3dGTri *param_1,dBgS_CrrPos *param_2,cXyz *param_3,float param_4,
          float param_5)

{
  float fVar1;
  
  param_2->field_0x38 = param_2->field_0x38 | 0x10;
  fVar1 = param_4 * (param_2->field_0x40 - param_5);
  param_3->x = param_3->x + fVar1 * (param_1->parent).mNorm.x;
  param_3->z = param_3->z + fVar1 * (param_1->parent).mNorm.z;
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* WARNING: Removing unreachable block (ram,0x800a893c) */
/* WARNING: Removing unreachable block (ram,0x800a892c) */
/* WARNING: Removing unreachable block (ram,0x800a851c) */
/* WARNING: Removing unreachable block (ram,0x800a8840) */
/* WARNING: Removing unreachable block (ram,0x800a8934) */
/* WARNING: Removing unreachable block (ram,0x800a8944) */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall dBgW::RwgWallCrrPos(unsigned short,
                                  dBgS_CrrPos *) */

int __thiscall dBgW::RwgWallCrrPos(dBgW *this,ushort param_1,dBgS_CrrPos *param_2)

{
  float fVar1;
  ushort uVar2;
  float fVar3;
  float fVar4;
  cXyz *pcVar5;
  char cVar6;
  cXyz *pcVar7;
  cXyz *pcVar8;
  cBgD__Tri_t *pcVar9;
  uint uVar10;
  int iVar11;
  cBgW_TriElm *pcVar12;
  uint uVar13;
  cBgW_RwgElm *pcVar14;
  undefined4 uVar15;
  double dVar16;
  double dVar17;
  undefined8 in_f28;
  undefined8 in_f29;
  undefined8 in_f30;
  double dVar18;
  undefined8 in_f31;
  double dVar19;
  float local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  float local_b0;
  cXyz local_ac;
  cM3dGTri local_a0;
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar15 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  iVar11 = 0;
  local_a0.parent.vtbl = (undefined *)&cM3dGTri::__vt;
  pcVar5 = param_2->mpPos;
  local_ac.x = pcVar5->x;
  local_ac.z = pcVar5->z;
  local_ac.y = pcVar5->y + param_2->mOffsY;
  pcVar5 = param_2->mpLine0;
  local_b8 = pcVar5->x;
  local_b0 = pcVar5->z;
  local_b4 = pcVar5->y + param_2->mOffsY;
  uVar13 = (uint)param_1;
  uVar10 = uVar13;
  do {
    while( true ) {
      pcVar14 = (this->parent).mpRwg;
      cVar6 = (**(code **)((this->parent).vtbl + 0x18))(this,uVar10,param_2->mpPolyPassChk);
      if (cVar6 == '\0') break;
LAB_800a8568:
      uVar2 = pcVar14[uVar10].mNext;
joined_r0x800a834c:
      uVar10 = (uint)uVar2;
      if (uVar10 == 0xffff) goto LAB_800a857c;
    }
    pcVar9 = ((this->parent).mpBgDt)->mpTriTbl + uVar10;
    pcVar12 = (this->parent).mpTriElm + uVar10;
    pcVar5 = (this->parent).mpVtxTbl;
    pcVar8 = pcVar5 + (ushort)pcVar9->mVtxIdx2;
    pcVar7 = pcVar5 + (ushort)pcVar9->mVtxIdx1;
    pcVar5 = pcVar5 + (ushort)pcVar9->mVtxIdx0;
    local_a0.mP0.x = pcVar5->x;
    local_a0.mP0.y = pcVar5->y;
    local_a0.mP0.z = pcVar5->z;
    local_a0.mP1.x = pcVar7->x;
    local_a0.mP1.y = pcVar7->y;
    local_a0.mP1.z = pcVar7->z;
    local_a0.mP2.x = pcVar8->x;
    local_a0.mP2.y = pcVar8->y;
    local_a0.mP2.z = pcVar8->z;
    local_a0.parent.mNorm.x = (pcVar12->mPlane).mNorm.x;
    local_a0.parent.mNorm.y = (pcVar12->mPlane).mNorm.y;
    local_a0.parent.mNorm.z = (pcVar12->mPlane).mNorm.z;
    local_a0.parent.mDist = (pcVar12->mPlane).mDist;
    dVar17 = (double)SComponent::cM3d_SignedLenPlaAndPos(&local_a0.parent,&local_ac);
    if (param_2->field_0x40 < (float)ABS(dVar17)) {
      uVar2 = pcVar14[uVar10].mNext;
      goto joined_r0x800a834c;
    }
    fVar1 = (pcVar12->mPlane).mNorm.x;
    dVar18 = (double)(pcVar12->mPlane).mNorm.z;
    dVar19 = (double)(fVar1 * fVar1 + (float)(dVar18 * dVar18));
    if ((double)d_bg_w::_3140 < dVar19) {
      dVar16 = 1.0 / SQRT(dVar19);
      dVar16 = d_bg_w::_3141 * dVar16 * (d_bg_w::_3142 - dVar19 * dVar16 * dVar16);
      dVar16 = d_bg_w::_3141 * dVar16 * (d_bg_w::_3142 - dVar19 * dVar16 * dVar16);
      dVar19 = (double)(float)(dVar19 * d_bg_w::_3141 * dVar16 *
                                        (d_bg_w::_3142 - dVar19 * dVar16 * dVar16));
    }
    if ((float)ABS(dVar19) < SComponent::G_CM3D_F_ABS_MIN) {
      uVar2 = pcVar14[uVar10].mNext;
    }
    else {
      dVar16 = (double)(float)((double)d_bg_w::_3143 / dVar19);
      dVar19 = (double)(float)(dVar16 * (double)(float)ABS(dVar18));
      if ((double)d_bg_w::_4042 <= dVar19) {
        fVar1 = local_a0.mP1.z;
        fVar4 = local_a0.mP0.z;
        if ((local_a0.mP0.z <= local_a0.mP1.z) &&
           (fVar1 = local_a0.mP0.z, local_a0.mP0.z < local_a0.mP1.z)) {
          fVar4 = local_a0.mP1.z;
        }
        fVar3 = local_a0.mP2.z;
        if ((fVar1 <= local_a0.mP2.z) && (fVar3 = fVar1, fVar4 < local_a0.mP2.z)) {
          fVar4 = local_a0.mP2.z;
        }
        if ((fVar3 - param_2->field_0x40 <= local_ac.z) &&
           (local_ac.z <= fVar4 + param_2->field_0x40)) {
          cVar6 = SComponent::cM3d_CrossZ_Tri(&local_a0,&local_ac,&local_bc);
          if ((cVar6 != '\0') &&
             (((float)ABS((double)(local_bc - local_ac.z)) <=
               (float)((double)param_2->field_0x40 / dVar19) &&
              ((float)((double)(local_bc - local_ac.z) * dVar18) <= d_bg_w::_4043)))) {
            positionWallCrrPos(this,&local_a0,param_2,(cXyz *)&param_2->field_0x4c,(float)dVar16,
                               (float)dVar17);
            (param_2->mPolyInfo).mTriIdx = (short)uVar10;
            iVar11 = 1;
            param_2->field_0x38 = param_2->field_0x38 | 0x40;
          }
          goto LAB_800a8568;
        }
        uVar2 = pcVar14[uVar10].mNext;
        goto joined_r0x800a834c;
      }
      uVar2 = pcVar14[uVar10].mNext;
    }
    uVar10 = (uint)uVar2;
  } while (uVar10 != 0xffff);
LAB_800a857c:
  do {
    pcVar14 = (this->parent).mpRwg;
    cVar6 = (**(code **)((this->parent).vtbl + 0x18))(this,uVar13,param_2->mpPolyPassChk);
    if (cVar6 == '\0') {
      pcVar9 = ((this->parent).mpBgDt)->mpTriTbl + uVar13;
      pcVar12 = (this->parent).mpTriElm + uVar13;
      pcVar5 = (this->parent).mpVtxTbl;
      pcVar8 = pcVar5 + (ushort)pcVar9->mVtxIdx2;
      pcVar7 = pcVar5 + (ushort)pcVar9->mVtxIdx1;
      pcVar5 = pcVar5 + (ushort)pcVar9->mVtxIdx0;
      local_a0.mP0.x = pcVar5->x;
      local_a0.mP0.y = pcVar5->y;
      local_a0.mP0.z = pcVar5->z;
      local_a0.mP1.x = pcVar7->x;
      local_a0.mP1.y = pcVar7->y;
      local_a0.mP1.z = pcVar7->z;
      local_a0.mP2.x = pcVar8->x;
      local_a0.mP2.y = pcVar8->y;
      local_a0.mP2.z = pcVar8->z;
      local_a0.parent.mNorm.x = (pcVar12->mPlane).mNorm.x;
      local_a0.parent.mNorm.y = (pcVar12->mPlane).mNorm.y;
      local_a0.parent.mNorm.z = (pcVar12->mPlane).mNorm.z;
      local_a0.parent.mDist = (pcVar12->mPlane).mDist;
      dVar17 = (double)SComponent::cM3d_SignedLenPlaAndPos(&local_a0.parent,&local_ac);
      if (param_2->field_0x40 < (float)ABS(dVar17)) {
        uVar2 = pcVar14[uVar13].mNext;
      }
      else {
        dVar18 = (double)(pcVar12->mPlane).mNorm.x;
        fVar1 = (pcVar12->mPlane).mNorm.z;
        dVar19 = (double)((float)(dVar18 * dVar18) + fVar1 * fVar1);
        if ((double)d_bg_w::_3140 < dVar19) {
          dVar16 = 1.0 / SQRT(dVar19);
          dVar16 = d_bg_w::_3141 * dVar16 * (d_bg_w::_3142 - dVar19 * dVar16 * dVar16);
          dVar16 = d_bg_w::_3141 * dVar16 * (d_bg_w::_3142 - dVar19 * dVar16 * dVar16);
          dVar19 = (double)(float)(dVar19 * d_bg_w::_3141 * dVar16 *
                                            (d_bg_w::_3142 - dVar19 * dVar16 * dVar16));
        }
        if ((float)ABS(dVar19) < SComponent::G_CM3D_F_ABS_MIN) {
          uVar2 = pcVar14[uVar13].mNext;
        }
        else {
          dVar19 = (double)(float)((double)d_bg_w::_3143 / dVar19);
          dVar16 = (double)(float)(dVar19 * (double)(float)ABS(dVar18));
          if (dVar16 < (double)d_bg_w::_4042) {
            uVar2 = pcVar14[uVar13].mNext;
          }
          else {
            fVar1 = local_a0.mP1.x;
            fVar4 = local_a0.mP0.x;
            if ((local_a0.mP0.x <= local_a0.mP1.x) &&
               (fVar1 = local_a0.mP0.x, local_a0.mP0.x < local_a0.mP1.x)) {
              fVar4 = local_a0.mP1.x;
            }
            fVar3 = local_a0.mP2.x;
            if ((fVar1 <= local_a0.mP2.x) && (fVar3 = fVar1, fVar4 < local_a0.mP2.x)) {
              fVar4 = local_a0.mP2.x;
            }
            if ((fVar3 - param_2->field_0x40 <= local_ac.x) &&
               (local_ac.x <= fVar4 + param_2->field_0x40)) {
              cVar6 = SComponent::cM3d_CrossX_Tri(&local_a0,&local_ac,&local_c0);
              if ((cVar6 != '\0') &&
                 (((float)ABS((double)(local_c0 - local_ac.x)) <=
                   (float)((double)param_2->field_0x40 / dVar16) &&
                  ((float)((double)(local_c0 - local_ac.x) * dVar18) <= d_bg_w::_4043)))) {
                positionWallCrrPos(this,&local_a0,param_2,(cXyz *)&param_2->field_0x4c,(float)dVar19
                                   ,(float)dVar17);
                (param_2->mPolyInfo).mTriIdx = (short)uVar13;
                iVar11 = 1;
                param_2->field_0x38 = param_2->field_0x38 | 0x20;
              }
              goto LAB_800a888c;
            }
            uVar2 = pcVar14[uVar13].mNext;
          }
        }
      }
    }
    else {
LAB_800a888c:
      uVar2 = pcVar14[uVar13].mNext;
    }
    uVar13 = (uint)uVar2;
    if (uVar13 == 0xffff) {
      if (iVar11 != 0) {
        dVar19 = (double)(d_bg_w::_4044 * param_2->mOffsY);
        dVar17 = (double)param_2->field_0x40;
        ::cM3dGCyl::SetC(&param_2->mCyl1,param_2->mpPos);
        ::cM3dGCyl::SetR(&param_2->mCyl1,(float)dVar17);
        ::cM3dGCyl::SetH(&param_2->mCyl1,(float)dVar19);
        pcVar7 = param_2->mpPos;
        pcVar5 = param_2->mpLine0;
        (param_2->mLin).mP0.x = pcVar5->x;
        (param_2->mLin).mP0.y = pcVar5->y;
        (param_2->mLin).mP0.z = pcVar5->z;
        (param_2->mLin).mP1.x = pcVar7->x;
        (param_2->mLin).mP1.y = pcVar7->y;
        (param_2->mLin).mP1.z = pcVar7->z;
      }
      __psq_l0(auStack8,uVar15);
      __psq_l1(auStack8,uVar15);
      __psq_l0(auStack24,uVar15);
      __psq_l1(auStack24,uVar15);
      __psq_l0(auStack40,uVar15);
      __psq_l1(auStack40,uVar15);
      __psq_l0(auStack56,uVar15);
      __psq_l1(auStack56,uVar15);
      return iVar11;
    }
  } while( true );
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dBgW::WallCrrPosRp(dBgS_CrrPos *,
                                 int) */

undefined4 __thiscall dBgW::WallCrrPosRp(dBgW *this,dBgS_CrrPos *param_1,int param_2)

{
  ushort uVar1;
  char cVar3;
  undefined4 uVar2;
  cBgD__Tree_t *pcVar4;
  
  cVar3 = SComponent::cM3d_Cross_AabCyl((this->parent).mpNodeTree + param_2,&param_1->mCyl1);
  if (cVar3 == '\0') {
    uVar2 = 0;
  }
  else {
    uVar2 = 0;
    pcVar4 = ((this->parent).mpBgDt)->mpNodeTreeTbl + param_2;
    if ((pcVar4->mFlag & 1) == 0) {
      if ((pcVar4->mChild0 != 0xffff) &&
         (cVar3 = WallCrrPosRp(this,param_1,(uint)pcVar4->mChild0), cVar3 != '\0')) {
        uVar2 = 1;
      }
      if ((pcVar4->mChild1 != 0xffff) &&
         (cVar3 = WallCrrPosRp(this,param_1,(uint)pcVar4->mChild1), cVar3 != '\0')) {
        uVar2 = 1;
      }
      if ((pcVar4->mChild2 != 0xffff) &&
         (cVar3 = WallCrrPosRp(this,param_1,(uint)pcVar4->mChild2), cVar3 != '\0')) {
        uVar2 = 1;
      }
      if ((pcVar4->mChild3 != 0xffff) &&
         (cVar3 = WallCrrPosRp(this,param_1,(uint)pcVar4->mChild3), cVar3 != '\0')) {
        uVar2 = 1;
      }
      if ((pcVar4->mChild4 != 0xffff) &&
         (cVar3 = WallCrrPosRp(this,param_1,(uint)pcVar4->mChild4), cVar3 != '\0')) {
        uVar2 = 1;
      }
      if ((pcVar4->mChild5 != 0xffff) &&
         (cVar3 = WallCrrPosRp(this,param_1,(uint)pcVar4->mChild5), cVar3 != '\0')) {
        uVar2 = 1;
      }
      if ((pcVar4->mChild6 != 0xffff) &&
         (cVar3 = WallCrrPosRp(this,param_1,(uint)pcVar4->mChild6), cVar3 != '\0')) {
        uVar2 = 1;
      }
      if ((pcVar4->mChild7 != 0xffff) &&
         (cVar3 = WallCrrPosRp(this,param_1,(uint)pcVar4->mChild7), cVar3 != '\0')) {
        uVar2 = 1;
      }
    }
    else {
      uVar1 = (this->parent).mpBlk[pcVar4->mChild0].mWallIdx;
      if ((uVar1 != 0xffff) && (cVar3 = RwgWallCrrPos(this,uVar1,param_1), cVar3 != '\0')) {
        uVar2 = 1;
      }
      uVar1 = (this->parent).mpBlk[pcVar4->mChild0].mRoofIdx;
      if ((uVar1 != 0xffff) && (cVar3 = RwgWallCrrPos(this,uVar1,param_1), cVar3 != '\0')) {
        uVar2 = 1;
      }
    }
  }
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dBgW::WallCrrPosGrpRp(dBgS_CrrPos *,
                                    int,
                                    int) */

undefined4 __thiscall dBgW::WallCrrPosGrpRp(dBgW *this,dBgS_CrrPos *param_1,int param_2,int param_3)

{
  ushort uVar1;
  char cVar3;
  undefined4 uVar2;
  uint uVar4;
  
  cVar3 = (**(code **)((this->parent).vtbl + 0x20))(this,param_2,param_1->mpGrpPassChk);
  if (cVar3 == '\0') {
    cVar3 = SComponent::cM3d_Cross_AabCyl(&(this->parent).mpGrp[param_2].mAabb,&param_1->mCyl1);
    if (cVar3 == '\0') {
      uVar2 = 0;
    }
    else {
      uVar2 = 0;
      uVar4 = (uint)((this->parent).mpBgDt)->mpGrpTbl[param_2].mTreIdx;
      if ((uVar4 != 0xffff) && (cVar3 = WallCrrPosRp(this,param_1,uVar4), cVar3 != '\0')) {
        uVar2 = 1;
      }
      uVar1 = ((this->parent).mpBgDt)->mpGrpTbl[param_2].mFirstChild;
      while (uVar4 = (uint)uVar1, uVar4 != 0xffff) {
        cVar3 = WallCrrPosGrpRp(this,param_1,uVar4,param_3 + 1);
        if (cVar3 != '\0') {
          uVar2 = 1;
        }
        uVar1 = ((this->parent).mpBgDt)->mpGrpTbl[uVar4].mNextSibling;
      }
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


/* __thiscall dBgW::WallCrrPos(dBgS_CrrPos *) */

void __thiscall dBgW::WallCrrPos(dBgW *this,dBgS_CrrPos *param_1)

{
  WallCrrPosGrpRp(this,param_1,(this->parent).mRootGrpIdx,1);
  return;
}


/* __thiscall dBgW::CrrPos(cBgS_PolyInfo &,
                           void *,
                           bool,
                           cXyz *,
                           csXyz *,
                           csXyz *) */

void __thiscall
dBgW::CrrPos(dBgW *this,cBgS_PolyInfo *pPolyInf,void *param_2,bool param_3,cXyz *param_4,
            csXyz *param_5,csXyz *param_6)

{
  if ((code *)this->mpTransPosCb != (code *)0x0) {
    (*(code *)this->mpTransPosCb)(this,param_2,pPolyInf);
  }
  return;
}


/* __thiscall dBgW::TransPos(cBgS_PolyInfo &,
                             void *,
                             bool,
                             cXyz *,
                             csXyz *,
                             csXyz *) */

void __thiscall
dBgW::TransPos(dBgW *this,cBgS_PolyInfo *pPolyInf,void *param_2,bool param_3,cXyz *param_4,
              csXyz *param_5,csXyz *param_6)

{
  if ((code *)this->mpTransPosCb != (code *)0x0) {
    (*(code *)this->mpTransPosCb)(this,param_2,pPolyInf);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dBgW::ChkPolyThrough(int,
                                   cBgS_PolyPassChk *) */

undefined4 __thiscall dBgW::ChkPolyThrough(dBgW *this,int poly_index,cBgS_PolyPassChk *param_2)

{
  bool bVar1;
  ulong uVar2;
  cBgD_t *pDt;
  uint id;
  
  if (param_2 != (cBgS_PolyPassChk *)0x0) {
    if (param_2->mbObjThrough != 0) {
      bVar1 = false;
      if ((-1 < poly_index) && (poly_index < ((this->parent).mpBgDt)->mTriCount)) {
        bVar1 = true;
      }
      if (!bVar1) {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert
                  (uVar2,"c_bg_w.h",0x2f1,"0 <= poly_index && poly_index < pm_bgd->m_t_num");
        m_Do_printf::OSPanic("c_bg_w.h",0x2f1,"Halt");
      }
      pDt = (this->parent).mpBgDt;
      id = (uint)(ushort)pDt->mpTriTbl[poly_index].mID;
      if (pDt->mTiCount <= (int)id) {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar2,"c_bg_w.h",0x307,"0 <= id && id < pm_bgd->m_ti_num");
        m_Do_printf::OSPanic("c_bg_w.h",0x307,"Halt");
      }
      if ((((this->parent).mpBgDt)->mpTiTbl[id].mPassFlag & 2) != 0) {
        return 1;
      }
    }
    if (param_2->mbCamThrough != 0) {
      bVar1 = false;
      if ((-1 < poly_index) && (poly_index < ((this->parent).mpBgDt)->mTriCount)) {
        bVar1 = true;
      }
      if (!bVar1) {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert
                  (uVar2,"c_bg_w.h",0x2f1,"0 <= poly_index && poly_index < pm_bgd->m_t_num");
        m_Do_printf::OSPanic("c_bg_w.h",0x2f1,"Halt");
      }
      pDt = (this->parent).mpBgDt;
      id = (uint)(ushort)pDt->mpTriTbl[poly_index].mID;
      if (pDt->mTiCount <= (int)id) {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar2,"c_bg_w.h",0x307,"0 <= id && id < pm_bgd->m_ti_num");
        m_Do_printf::OSPanic("c_bg_w.h",0x307,"Halt");
      }
      if ((((this->parent).mpBgDt)->mpTiTbl[id].mPassFlag & 1) != 0) {
        return 1;
      }
    }
    if (param_2->mbLinkThrough != 0) {
      bVar1 = false;
      if ((-1 < poly_index) && (poly_index < ((this->parent).mpBgDt)->mTriCount)) {
        bVar1 = true;
      }
      if (!bVar1) {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert
                  (uVar2,"c_bg_w.h",0x2f1,"0 <= poly_index && poly_index < pm_bgd->m_t_num");
        m_Do_printf::OSPanic("c_bg_w.h",0x2f1,"Halt");
      }
      pDt = (this->parent).mpBgDt;
      id = (uint)(ushort)pDt->mpTriTbl[poly_index].mID;
      if (pDt->mTiCount <= (int)id) {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar2,"c_bg_w.h",0x307,"0 <= id && id < pm_bgd->m_ti_num");
        m_Do_printf::OSPanic("c_bg_w.h",0x307,"Halt");
      }
      if ((((this->parent).mpBgDt)->mpTiTbl[id].mPassFlag & 4) != 0) {
        return 1;
      }
    }
    if (param_2->mbArrowsAndLightThrough != 0) {
      bVar1 = false;
      if ((-1 < poly_index) && (poly_index < ((this->parent).mpBgDt)->mTriCount)) {
        bVar1 = true;
      }
      if (!bVar1) {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert
                  (uVar2,"c_bg_w.h",0x2f1,"0 <= poly_index && poly_index < pm_bgd->m_t_num");
        m_Do_printf::OSPanic("c_bg_w.h",0x2f1,"Halt");
      }
      pDt = (this->parent).mpBgDt;
      id = (uint)(ushort)pDt->mpTriTbl[poly_index].mID;
      if (pDt->mTiCount <= (int)id) {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar2,"c_bg_w.h",0x307,"0 <= id && id < pm_bgd->m_ti_num");
        m_Do_printf::OSPanic("c_bg_w.h",0x307,"Halt");
      }
      if ((((this->parent).mpBgDt)->mpTiTbl[id].mPassFlag & 8) != 0) {
        return 1;
      }
    }
    if (param_2->mbBombThrough != 0) {
      bVar1 = false;
      if ((-1 < poly_index) && (poly_index < ((this->parent).mpBgDt)->mTriCount)) {
        bVar1 = true;
      }
      if (!bVar1) {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert
                  (uVar2,"c_bg_w.h",0x2f1,"0 <= poly_index && poly_index < pm_bgd->m_t_num");
        m_Do_printf::OSPanic("c_bg_w.h",0x2f1,"Halt");
      }
      pDt = (this->parent).mpBgDt;
      id = (uint)(ushort)pDt->mpTriTbl[poly_index].mID;
      if (pDt->mTiCount <= (int)id) {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar2,"c_bg_w.h",0x307,"0 <= id && id < pm_bgd->m_ti_num");
        m_Do_printf::OSPanic("c_bg_w.h",0x307,"Halt");
      }
      if ((((this->parent).mpBgDt)->mpTiTbl[id].mPassFlag & 0x20) != 0) {
        return 1;
      }
    }
    if (param_2->mbBoomerangThrough != 0) {
      bVar1 = false;
      if ((-1 < poly_index) && (poly_index < ((this->parent).mpBgDt)->mTriCount)) {
        bVar1 = true;
      }
      if (!bVar1) {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert
                  (uVar2,"c_bg_w.h",0x2f1,"0 <= poly_index && poly_index < pm_bgd->m_t_num");
        m_Do_printf::OSPanic("c_bg_w.h",0x2f1,"Halt");
      }
      pDt = (this->parent).mpBgDt;
      id = (uint)(ushort)pDt->mpTriTbl[poly_index].mID;
      if (pDt->mTiCount <= (int)id) {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar2,"c_bg_w.h",0x307,"0 <= id && id < pm_bgd->m_ti_num");
        m_Do_printf::OSPanic("c_bg_w.h",0x307,"Halt");
      }
      if ((((this->parent).mpBgDt)->mpTiTbl[id].mPassFlag & 0x40) != 0) {
        return 1;
      }
    }
    if (param_2->mbHookshotThrough != 0) {
      bVar1 = false;
      if ((-1 < poly_index) && (poly_index < ((this->parent).mpBgDt)->mTriCount)) {
        bVar1 = true;
      }
      if (!bVar1) {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert
                  (uVar2,"c_bg_w.h",0x2f1,"0 <= poly_index && poly_index < pm_bgd->m_t_num");
        m_Do_printf::OSPanic("c_bg_w.h",0x2f1,"Halt");
      }
      pDt = (this->parent).mpBgDt;
      id = (uint)(ushort)pDt->mpTriTbl[poly_index].mID;
      if (pDt->mTiCount <= (int)id) {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar2,"c_bg_w.h",0x307,"0 <= id && id < pm_bgd->m_ti_num");
        m_Do_printf::OSPanic("c_bg_w.h",0x307,"Halt");
      }
      if ((((this->parent).mpBgDt)->mpTiTbl[id].mPassFlag & 0x80) != 0) {
        return 1;
      }
    }
  }
  return 0;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dBgW::ChkShdwDrawThrough(int,
                                       cBgS_PolyPassChk *) */

undefined4 __thiscall dBgW::ChkShdwDrawThrough(dBgW *this,int param_1,cBgS_PolyPassChk *param_2)

{
  bool bVar1;
  ulong uVar2;
  undefined4 uVar3;
  cBgD_t *pcVar4;
  uint uVar5;
  
  bVar1 = false;
  if ((-1 < param_1) && (param_1 < ((this->parent).mpBgDt)->mTriCount)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar2,"c_bg_w.h",0x2f1,"0 <= poly_index && poly_index < pm_bgd->m_t_num");
    m_Do_printf::OSPanic("c_bg_w.h",0x2f1,"Halt");
  }
  pcVar4 = (this->parent).mpBgDt;
  uVar5 = (uint)(ushort)pcVar4->mpTriTbl[param_1].mID;
  if (pcVar4->mTiCount <= (int)uVar5) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"c_bg_w.h",0x2f8,"0 <= id && id < pm_bgd->m_ti_num");
    m_Do_printf::OSPanic("c_bg_w.h",0x2f8,"Halt");
  }
  pcVar4 = (this->parent).mpBgDt;
  if ((pcVar4->mpTiTbl[uVar5].mPolyID0 >> 0x1b & 1) == 0) {
    bVar1 = false;
    if ((-1 < param_1) && (param_1 < pcVar4->mTriCount)) {
      bVar1 = true;
    }
    if (!bVar1) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert
                (uVar2,"c_bg_w.h",0x2f1,"0 <= poly_index && poly_index < pm_bgd->m_t_num");
      m_Do_printf::OSPanic("c_bg_w.h",0x2f1,"Halt");
    }
    pcVar4 = (this->parent).mpBgDt;
    uVar5 = (uint)(ushort)pcVar4->mpTriTbl[param_1].mID;
    if (pcVar4->mTiCount <= (int)uVar5) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"c_bg_w.h",0x307,"0 <= id && id < pm_bgd->m_ti_num");
      m_Do_printf::OSPanic("c_bg_w.h",0x307,"Halt");
    }
    if ((((this->parent).mpBgDt)->mpTiTbl[uVar5].mPassFlag & 8) == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = 1;
    }
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}


/* __thiscall dBgW::ChkGrpThrough(int,
                                  cBgS_GrpPassChk *,
                                  int) */

undefined4 __thiscall dBgW::ChkGrpThrough(dBgW *this,int param_1,cBgS_GrpPassChk *param_2,int depth)

{
  uint uVar1;
  
  if (depth == 2) {
    if (param_2 != (cBgS_GrpPassChk *)0x0) {
      uVar1 = ((this->parent).mpBgDt)->mpGrpTbl[param_1].mAttr;
      if (((uVar1 & 0x80700) == 0) && ((param_2->mAttr & 1) != 0)) {
        return 0;
      }
      if (((uVar1 & 0x100) != 0) && ((param_2->mAttr & 2) != 0)) {
        return 0;
      }
      if (((uVar1 & 0x200) != 0) && ((param_2->mAttr & 4) != 0)) {
        return 0;
      }
      if (((uVar1 & 0x400) != 0) && ((param_2->mAttr & 8) != 0)) {
        return 0;
      }
      if (((uVar1 & 0x80000) != 0) && ((param_2->mAttr & 0x10) != 0)) {
        return 0;
      }
      return 1;
    }
  }
  return 0;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dBgW::ChangeAttributeCodeByPathPntNo(int,
                                                   unsigned long) */

void __thiscall dBgW::ChangeAttributeCodeByPathPntNo(dBgW *this,int param_1,ulong param_2)

{
  int iVar1;
  cBgD_t *pcVar2;
  int iVar3;
  int iVar4;
  
  if ((this->parent).mpBgDt != (cBgD_t *)0x0) {
    iVar4 = 0;
    for (iVar3 = 0; pcVar2 = (this->parent).mpBgDt, iVar3 < pcVar2->mTiCount; iVar3 = iVar3 + 1) {
      iVar1 = d_bg_s::dBgS_GetRoomPathPntNo
                        (*(undefined4 *)((int)&pcVar2->mpTiTbl->mPolyID2 + iVar4));
      if (iVar1 == param_1) {
        d_bg_s::dBgS_ChangeAttributeCode
                  (param_2,(int)&((this->parent).mpBgDt)->mpTiTbl->mPolyID1 + iVar4);
      }
      iVar4 = iVar4 + 0x10;
    }
  }
  return;
}


namespace d_bg_w {

/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall dBgW_NewSet(cBgD_t *,
                         unsigned long,
                         float *[][][]) */

dBgW * dBgW_NewSet(cBgD_t *param_1,cBgW__Flag param_2,MTX34 *param_3)

{
  dBgW *this;
  uint uVar1;
  
  this = (dBgW *)JKernel::operator_new(0xbc);
  if (this != (dBgW *)0x0) {
    this = ::dBgW::dBgW(this);
  }
  if (this == (dBgW *)0x0) {
    this = (dBgW *)0x0;
  }
  else {
    uVar1 = cBgW::Set(&this->parent,param_1,param_2,param_3);
    if ((uVar1 & 0xff) != 0) {
      this = (dBgW *)0x0;
    }
  }
  return this;
}

}

/* __thiscall cM3dGTri::~cM3dGTri(void) */

void __thiscall cM3dGTri::_cM3dGTri(cM3dGTri *this)

{
  short in_r4;
  
  if (this != (cM3dGTri *)0x0) {
    (this->parent).vtbl = (undefined *)&__vt;
    if (this != (cM3dGTri *)0x0) {
      (this->parent).vtbl = (undefined *)&cM3dGPla::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dBgW::~dBgW(void) */

void __thiscall dBgW::_dBgW(dBgW *this)

{
  short in_r4;
  
  if (this != (dBgW *)0x0) {
    (this->parent).vtbl = (undefined *)&__vt;
    cBgW::_cBgW(&this->parent);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}

