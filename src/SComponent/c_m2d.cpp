#include <SComponent/c_m2d.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>


namespace SComponent {

/* WARNING: Removing unreachable block (ram,0x8024a0b8) */
/* WARNING: Removing unreachable block (ram,0x8024a0a8) */
/* WARNING: Removing unreachable block (ram,0x8024a098) */
/* WARNING: Removing unreachable block (ram,0x8024a088) */
/* WARNING: Removing unreachable block (ram,0x8024a090) */
/* WARNING: Removing unreachable block (ram,0x8024a0a0) */
/* WARNING: Removing unreachable block (ram,0x8024a0b0) */
/* WARNING: Removing unreachable block (ram,0x8024a0c0) */
/* __stdcall cM2d_CrossCirLin(cM2dGCir &,
                              float,
                              float,
                              float,
                              float,
                              float *,
                              float *) */

void cM2d_CrossCirLin
               (cM2dGCir *param_1,float param_2,float param_3,float param_4,float param_5,
               float *param_6,float *param_7)

{
  float fVar1;
  ulong uVar2;
  undefined4 uVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  undefined8 in_f24;
  undefined8 in_f25;
  undefined8 in_f26;
  undefined8 in_f27;
  undefined8 in_f28;
  double in_f29;
  undefined8 in_f30;
  double dVar10;
  undefined8 in_f31;
  double dVar11;
  undefined auStack120 [16];
  undefined auStack104 [16];
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar8 = (double)param_5;
  dVar6 = (double)param_4;
  dVar4 = (double)param_2;
  dVar5 = (double)param_3;
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,SUB84(in_f29,0),0);
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
  dVar7 = (double)(float)(dVar4 - (double)param_1->x);
  dVar9 = (double)(float)(dVar5 - (double)param_1->z);
  dVar11 = (double)((float)(dVar6 * dVar6) + (float)(dVar8 * dVar8));
  dVar10 = (double)(_2211 * ((float)(dVar6 * dVar7) + (float)(dVar8 * dVar9)));
  dVar7 = (double)(((float)(dVar7 * dVar7) + (float)(dVar9 * dVar9)) -
                  param_1->mRadius * param_1->mRadius);
  if ((double)_2212 <= dVar7) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"c_m2d.cpp",0x47,"c < 0.0f");
    m_Do_printf::OSPanic("c_m2d.cpp",0x47,&DAT_80364e6b);
  }
  if (G_CM3D_F_ABS_MIN <= (float)ABS(dVar11)) {
    dVar7 = (double)((float)(dVar10 * dVar10) -
                    (float)((double)(float)((double)_2213 * dVar11) * dVar7));
    if (G_CM3D_F_ABS_MIN <= (float)ABS(dVar7)) {
      if ((double)_2212 <= dVar7) {
        fVar1 = _2214 / (float)((double)_2211 * dVar11);
        dVar9 = dVar7;
        if ((double)_2212 < dVar7) {
          dVar9 = 1.0 / SQRT(dVar7);
          dVar9 = _2215 * dVar9 * (_2216 - dVar7 * dVar9 * dVar9);
          dVar9 = _2215 * dVar9 * (_2216 - dVar7 * dVar9 * dVar9);
          dVar9 = (double)(float)(dVar7 * _2215 * dVar9 * (_2216 - dVar7 * dVar9 * dVar9));
        }
        dVar9 = (double)(fVar1 * (float)(-dVar10 + dVar9));
        if ((double)_2212 < dVar7) {
          dVar11 = 1.0 / SQRT(dVar7);
          dVar11 = _2215 * dVar11 * (_2216 - dVar7 * dVar11 * dVar11);
          dVar11 = _2215 * dVar11 * (_2216 - dVar7 * dVar11 * dVar11);
          dVar7 = (double)(float)(dVar7 * _2215 * dVar11 * (_2216 - dVar7 * dVar11 * dVar11));
        }
        in_f29 = (double)(fVar1 * (float)(-dVar10 - dVar7));
        if (in_f29 < dVar9) {
          in_f29 = dVar9;
        }
      }
    }
    else {
      in_f29 = (double)(float)(-dVar10 / (double)(float)((double)_2211 * dVar11));
    }
  }
  else {
    if (G_CM3D_F_ABS_MIN <= (float)ABS(dVar10)) {
      in_f29 = (double)(float)(-dVar7 / dVar10);
    }
  }
  if (G_CM3D_F_ABS_MIN <= (float)ABS(in_f29)) {
    if (in_f29 < (double)_2212) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"c_m2d.cpp",0x89,"t >= 0.0f");
      m_Do_printf::OSPanic("c_m2d.cpp",0x89,&DAT_80364e6b);
    }
    *param_6 = (float)(dVar4 + (double)(float)(in_f29 * dVar6));
    *param_7 = (float)(dVar5 + (double)(float)(in_f29 * dVar8));
  }
  else {
    *param_6 = (float)dVar4;
    *param_7 = (float)dVar5;
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  __psq_l0(auStack24,uVar3);
  __psq_l1(auStack24,uVar3);
  __psq_l0(auStack40,uVar3);
  __psq_l1(auStack40,uVar3);
  __psq_l0(auStack56,uVar3);
  __psq_l1(auStack56,uVar3);
  __psq_l0(auStack72,uVar3);
  __psq_l1(auStack72,uVar3);
  __psq_l0(auStack88,uVar3);
  __psq_l1(auStack88,uVar3);
  __psq_l0(auStack104,uVar3);
  __psq_l1(auStack104,uVar3);
  __psq_l0(auStack120,uVar3);
  __psq_l1(auStack120,uVar3);
  return;
}

