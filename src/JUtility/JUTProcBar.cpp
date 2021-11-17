#include <JUtility/JUTProcBar.h>
#include <JUtility/JUTProcBar.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <JKernel/JKRHeap.h>
#include <os/OSTime.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <J2DGraph/J2DOrthoGraph.h>
#include <JUTProcBar/CTime.h>
#include <JUTProcBar.h>

struct JUTProcBar * JUTProcBar;

namespace JUtility {
undefined4 cnt$2296;
undefined1 init$2297;
undefined4 cntUser$2345;
undefined1 init$2346;
}

/* __thiscall JUTProcBar::JUTProcBar(void) */

void __thiscall JUTProcBar::JUTProcBar(JUTProcBar *this)

{
  ushort uVar1;
  uint uVar2;
  
  *(undefined4 *)&this->field_0x4 = 0;
  *(undefined4 *)&this->field_0x8 = 0;
  *(undefined4 *)&this->field_0xc = 0;
  *(undefined4 *)&this->field_0x18 = 0;
  *(undefined4 *)&this->field_0x1c = 0;
  *(undefined4 *)&this->field_0x20 = 0;
  *(undefined4 *)&this->field_0x2c = 0;
  *(undefined4 *)&this->field_0x30 = 0;
  *(undefined4 *)&this->field_0x34 = 0;
  *(undefined4 *)&this->field_0x40 = 0;
  *(undefined4 *)&this->field_0x44 = 0;
  *(undefined4 *)&this->field_0x48 = 0;
  *(undefined4 *)&this->field_0x54 = 0;
  *(undefined4 *)&this->field_0x58 = 0;
  *(undefined4 *)&this->field_0x5c = 0;
  Runtime.PPCEABI.H::__construct_array(this->mpTimeHistory,CTime::CTime,(undefined *)0x0,0x14,8);
  this->mbDrawProcessBar = 1;
  this->mbDrawHeapBar = 1;
  *(undefined4 *)&this->field_0x108 = 0;
  uVar1 = JUTVideo::sManager->mpRenderMode->field_0x8;
  uVar2 = (uint)uVar1;
  if (uVar1 < 0x191) {
    *(undefined4 *)&this->field_0x114 = 1;
    *(undefined4 *)&this->field_0x118 = 0x27;
    *(uint *)&this->field_0x11c = uVar2 - 0x14;
    *(undefined4 *)&this->field_0x120 = 0x232;
    *(uint *)&this->field_0x124 = uVar2 - 0x23;
  }
  else {
    *(undefined4 *)&this->field_0x114 = 2;
    *(undefined4 *)&this->field_0x118 = 0x27;
    *(uint *)&this->field_0x11c = uVar2 - 0x28;
    *(undefined4 *)&this->field_0x120 = 0x232;
    *(uint *)&this->field_0x124 = uVar2 - 0x46;
  }
  *(undefined4 *)&this->field_0x110 = 1;
  *(undefined4 *)&this->field_0x128 = 0;
  *(undefined4 *)&this->field_0x12c = 0;
  return;
}


/* __thiscall JUTProcBar::~JUTProcBar(void) */

void __thiscall JUTProcBar::_JUTProcBar(JUTProcBar *this)

{
  short in_r4;
  
  if ((this != (JUTProcBar *)0x0) && (sManager = (JUTProcBar *)0x0, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall JUTProcBar::create(void) */

JUTProcBar * __thiscall JUTProcBar::create(JUTProcBar *this)

{
  JUTProcBar *this_00;
  
  this_00 = sManager;
  if ((sManager == (JUTProcBar *)0x0) &&
     (this_00 = (JUTProcBar *)JKernel::operator_new(0x134), this_00 != (JUTProcBar *)0x0)) {
    JUTProcBar(this_00);
  }
  sManager = this_00;
  return sManager;
}


/* __thiscall JUTProcBar::destroy(void) */

void __thiscall JUTProcBar::destroy(JUTProcBar *this)

{
  if (sManager != (JUTProcBar *)0x0) {
    _JUTProcBar(sManager);
  }
  sManager = (JUTProcBar *)0x0;
  return;
}


/* __thiscall JUTProcBar::clear(void) */

void __thiscall JUTProcBar::clear(JUTProcBar *this)

{
  JUTProcBar *pJVar1;
  undefined4 uVar2;
  
  pJVar1 = sManager;
  *(undefined *)&sManager->field_0x10 = 0xff;
  *(undefined *)&pJVar1->field_0x11 = 0x81;
  *(undefined *)&pJVar1->field_0x12 = 0x1e;
  uVar2 = os::OSGetTick();
  *(undefined4 *)pJVar1 = uVar2;
  pJVar1 = sManager;
  *(undefined *)&sManager->field_0x38 = 0xff;
  *(undefined *)&pJVar1->field_0x39 = 0x81;
  *(undefined *)&pJVar1->field_0x3a = 0x1e;
  uVar2 = os::OSGetTick();
  *(undefined4 *)&pJVar1->field_0x28 = uVar2;
  pJVar1 = sManager;
  *(undefined *)&sManager->field_0x24 = 0xff;
  *(undefined *)&pJVar1->field_0x25 = 0x81;
  *(undefined *)&pJVar1->field_0x26 = 0x1e;
  uVar2 = os::OSGetTick();
  *(undefined4 *)&pJVar1->field_0x14 = uVar2;
  pJVar1 = sManager;
  *(undefined *)&sManager->field_0x60 = 0xff;
  *(undefined *)&pJVar1->field_0x61 = 0x81;
  *(undefined *)&pJVar1->field_0x62 = 0x1e;
  uVar2 = os::OSGetTick();
  *(undefined4 *)&pJVar1->field_0x50 = uVar2;
  *(undefined4 *)&sManager->field_0x104 = 0;
  JUtility::oneFrameRate = JUtility::_2224;
  JUtility::oneFrameRateUser = JUtility::_2225;
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall JUTProcBar::bar_subroutine(int,
                                         int,
                                         int,
                                         int,
                                         int,
                                         int,
                                         int,
                                         JUtility::TColor,
                                         JUtility::TColor) */

void __thiscall
JUTProcBar::bar_subroutine
          (JUTProcBar *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
          int param_7,TColor param_8,TColor param_9)

{
  uint uVar1;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40 [2];
  undefined4 local_38;
  uint uStack52;
  undefined4 local_30;
  uint uStack44;
  undefined4 local_28;
  uint uStack36;
  undefined4 local_20;
  uint uStack28;
  
  uVar1 = (param_7 * param_4) / param_5;
  local_40[0] = *(undefined4 *)param_8;
  uStack52 = param_1 ^ 0x80000000;
  local_38 = 0x43300000;
  uStack44 = param_2 ^ 0x80000000;
  local_30 = 0x43300000;
  uStack36 = (param_6 * param_4) / param_5 ^ 0x80000000;
  local_28 = 0x43300000;
  uStack28 = param_3 ^ 0x80000000;
  local_20 = 0x43300000;
  J2DGraph::J2DFillBox
            ((double)(float)((double)CONCAT44(0x43300000,uStack52) - JUtility::_2247),
             (double)(float)((double)CONCAT44(0x43300000,uStack44) - JUtility::_2247),
             (double)(float)((double)CONCAT44(0x43300000,uStack36) - JUtility::_2247),
             (double)(float)((double)CONCAT44(0x43300000,uStack28) - JUtility::_2247),local_40);
  if (-1 < (int)uVar1) {
    if ((int)uVar1 < 6) {
      local_44 = *(undefined4 *)param_9;
      uStack28 = param_1 ^ 0x80000000;
      local_20 = 0x43300000;
      uStack36 = param_2 ^ 0x80000000;
      local_28 = 0x43300000;
      uStack44 = uVar1 ^ 0x80000000;
      local_30 = 0x43300000;
      uStack52 = param_3 ^ 0x80000000;
      local_38 = 0x43300000;
      J2DGraph::J2DFillBox
                ((double)(float)((double)CONCAT44(0x43300000,uStack28) - JUtility::_2247),
                 (double)(float)((double)CONCAT44(0x43300000,uStack36) - JUtility::_2247),
                 (double)(float)((double)CONCAT44(0x43300000,uStack44) - JUtility::_2247),
                 (double)(float)((double)CONCAT44(0x43300000,uStack52) - JUtility::_2247),&local_44)
      ;
    }
    else {
      local_48 = *(undefined4 *)param_9;
      uStack28 = param_1 + (uVar1 - 6) ^ 0x80000000;
      local_20 = 0x43300000;
      uStack36 = param_2 ^ 0x80000000;
      local_28 = 0x43300000;
      uStack44 = param_3 ^ 0x80000000;
      local_30 = 0x43300000;
      J2DGraph::J2DFillBox
                ((double)(float)((double)CONCAT44(0x43300000,uStack28) - JUtility::_2247),
                 (double)(float)((double)CONCAT44(0x43300000,uStack36) - JUtility::_2247),
                 (double)JUtility::_2245,
                 (double)(float)((double)CONCAT44(0x43300000,uStack44) - JUtility::_2247),&local_48)
      ;
    }
  }
  return;
}


/* __thiscall JUTProcBar::adjustMeterLength(unsigned long,
                                            float *,
                                            float,
                                            float,
                                            int *) */

void __thiscall
JUTProcBar::adjustMeterLength
          (JUTProcBar *this,ulong param_1,float *param_2,float param_3,float param_4,int *param_5)

{
  float fVar1;
  bool bVar2;
  
  bVar2 = false;
  for (fVar1 = *param_2; param_3 < fVar1; fVar1 = fVar1 - JUtility::_2277) {
    if ((JUtility::_2274 * (float)((double)CONCAT44(0x43300000,param_1) - JUtility::_2281) * fVar1)
        / JUtility::_2275 <=
        (float)((double)CONCAT44(0x43300000,*(uint *)&this->field_0x120 ^ 0x80000000) -
               JUtility::_2247) - JUtility::_2276) break;
    bVar2 = true;
  }
  if (param_4 <= fVar1) {
    *param_5 = 0;
  }
  if (param_4 - JUtility::_2278 < fVar1) {
    fVar1 = param_4;
  }
  if (((!bVar2) && (fVar1 < param_4)) && (*param_5 = *param_5 + 1, 0x1d < *param_5)) {
    if ((JUtility::_2274 * (float)((double)CONCAT44(0x43300000,param_1) - JUtility::_2281) * fVar1)
        / JUtility::_2275 <
        (float)((double)CONCAT44(0x43300000,*(uint *)&this->field_0x120 ^ 0x80000000) -
               JUtility::_2247) - JUtility::_2279) {
      fVar1 = fVar1 + JUtility::_2278;
    }
  }
  *param_2 = fVar1;
  return;
}


/* __thiscall JUTProcBar::draw(void) */

void __thiscall JUTProcBar::draw(JUTProcBar *this)

{
  drawProcessBar(this);
  drawHeapBar(this);
  return;
}


/* WARNING: Inlined function: FUN_80328f20 */
/* WARNING: Inlined function: FUN_80328f6c */
/* WARNING: Removing unreachable block (ram,0x802c9cc4) */
/* __thiscall JUTProcBar::drawProcessBar(void) */

void __thiscall JUTProcBar::drawProcessBar(JUTProcBar *this)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  undefined4 uVar14;
  undefined8 in_f31;
  double dVar15;
  undefined local_160;
  undefined local_15f;
  undefined local_15e;
  undefined local_15d;
  undefined local_15c;
  undefined uStack347;
  undefined uStack346;
  undefined uStack345;
  undefined4 local_158;
  undefined4 local_154;
  undefined4 local_150;
  undefined4 local_14c;
  undefined4 local_148;
  undefined4 local_144;
  undefined4 local_140;
  undefined4 local_13c;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined local_12c;
  undefined local_12b;
  undefined local_12a;
  undefined local_129;
  undefined local_128;
  undefined uStack295;
  undefined uStack294;
  undefined uStack293;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  double local_88;
  undefined4 local_80;
  uint uStack124;
  undefined4 local_78;
  uint uStack116;
  undefined4 local_70;
  uint uStack108;
  undefined4 local_68;
  uint uStack100;
  undefined4 local_60;
  uint uStack92;
  undefined4 local_58;
  uint uStack84;
  double local_50;
  undefined4 local_48;
  uint uStack68;
  undefined auStack8 [8];
  
  uVar14 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (this->mbDrawProcessBar != 0) {
    uVar12 = 0x411a;
    if ((JUTVideo::sManager != (JUTVideo *)0x0) &&
       (((uint)JUTVideo::sManager->mpRenderMode->field_0x0 >> 2 & 0xf) == 1)) {
      uVar12 = 20000;
    }
    if (JUtility::init_2297 == '\0') {
      JUtility::cnt_2296 = 0;
      JUtility::init_2297 = '\x01';
    }
    adjustMeterLength(this,*(ulong *)&this->field_0x54,&JUtility::oneFrameRate,JUtility::_2546,
                      JUtility::_2225,&JUtility::cnt_2296);
    iVar4 = (int)(JUtility::_2274 * JUtility::oneFrameRate);
    iVar1 = *(int *)&this->field_0x114;
    uVar8 = iVar1 * 8;
    uVar3 = iVar1 << 1;
    uVar11 = iVar1 * 10;
    iVar1 = (*(int *)&this->field_0x120 + iVar4 + -4) / iVar4;
    uVar2 = *(int *)&this->field_0xc + 1;
    *(uint *)&this->field_0xc = uVar2;
    if ((0xf < uVar2) || (*(uint *)&this->field_0x8 <= *(uint *)&this->field_0x4)) {
      *(undefined4 *)&this->field_0x8 = *(undefined4 *)&this->field_0x4;
      *(undefined4 *)&this->field_0xc = 0;
    }
    uVar2 = *(int *)&this->field_0x20 + 1;
    *(uint *)&this->field_0x20 = uVar2;
    if ((0xf < uVar2) || (*(uint *)&this->field_0x1c <= *(uint *)&this->field_0x18)) {
      *(undefined4 *)&this->field_0x1c = *(undefined4 *)&this->field_0x18;
      *(undefined4 *)&this->field_0x20 = 0;
    }
    uVar2 = *(int *)&this->field_0x34 + 1;
    *(uint *)&this->field_0x34 = uVar2;
    if ((0xf < uVar2) || (*(uint *)&this->field_0x30 <= *(uint *)&this->field_0x2c)) {
      *(undefined4 *)&this->field_0x30 = *(undefined4 *)&this->field_0x2c;
      *(undefined4 *)&this->field_0x34 = 0;
    }
    iVar7 = *(int *)&this->field_0x2c;
    iVar13 = *(int *)&this->field_0x18 - *(int *)&this->field_0x40;
    local_90 = 13000;
    local_8c = 13000;
    local_88 = (double)CONCAT44(0x43300000,*(uint *)&this->field_0x118 ^ 0x80000000);
    uStack124 = *(uint *)&this->field_0x11c ^ 0x80000000;
    local_80 = 0x43300000;
    uStack116 = *(uint *)&this->field_0x120 ^ 0x80000000;
    local_78 = 0x43300000;
    uStack108 = uVar8 ^ 0x80000000;
    local_70 = 0x43300000;
    J2DGraph::J2DFillBox
              ((double)(float)(local_88 - JUtility::_2247),
               (double)(float)((double)CONCAT44(0x43300000,uStack124) - JUtility::_2247),
               (double)(float)((double)CONCAT44(0x43300000,uStack116) - JUtility::_2247),
               (double)(float)((double)CONCAT44(0x43300000,uStack108) - JUtility::_2247),&local_8c);
    local_98 = 0x323296ff;
    local_94 = 0x323296ff;
    uStack100 = *(uint *)&this->field_0x118 ^ 0x80000000;
    local_68 = 0x43300000;
    uStack92 = *(uint *)&this->field_0x11c ^ 0x80000000;
    local_60 = 0x43300000;
    uStack84 = *(uint *)&this->field_0x120 ^ 0x80000000;
    local_58 = 0x43300000;
    local_50 = (double)CONCAT44(0x43300000,uVar8 ^ 0x80000000);
    J2DGraph::J2DDrawFrame
              ((double)(float)((double)CONCAT44(0x43300000,uStack100) - JUtility::_2247),
               (double)(float)((double)CONCAT44(0x43300000,uStack92) - JUtility::_2247),
               (double)(float)((double)CONCAT44(0x43300000,uStack84) - JUtility::_2247),
               (double)(float)(local_50 - JUtility::_2247),&local_94,6);
    if (iVar1 < *(int *)&this->field_0x104) {
      local_a0 = 0xfa0000c8;
      local_9c = 0xfa0000c8;
      local_50 = (double)CONCAT44(0x43300000,*(uint *)&this->field_0x118 ^ 0x80000000);
      uStack84 = *(int *)&this->field_0x11c + uVar8 + 1 ^ 0x80000000;
      local_58 = 0x43300000;
      uStack92 = *(uint *)&this->field_0x120 ^ 0x80000000;
      local_60 = 0x43300000;
      J2DGraph::J2DFillBox
                ((double)(float)(local_50 - JUtility::_2247),
                 (double)(float)((double)CONCAT44(0x43300000,uStack84) - JUtility::_2247),
                 (double)(float)((double)CONCAT44(0x43300000,uStack92) - JUtility::_2247),
                 (double)JUtility::_2546,&local_9c);
    }
    else {
      local_a8 = 0xfafac8;
      local_a4 = 0xfafac8;
      local_50 = (double)CONCAT44(0x43300000,*(uint *)&this->field_0x118 ^ 0x80000000);
      uStack84 = *(int *)&this->field_0x11c + uVar8 + 1 ^ 0x80000000;
      local_58 = 0x43300000;
      uStack92 = *(int *)&this->field_0x104 * iVar4 + 2U ^ 0x80000000;
      local_60 = 0x43300000;
      J2DGraph::J2DFillBox
                ((double)(float)(local_50 - JUtility::_2247),
                 (double)(float)((double)CONCAT44(0x43300000,uStack84) - JUtility::_2247),
                 (double)(float)((double)CONCAT44(0x43300000,uStack92) - JUtility::_2247),
                 (double)JUtility::_2546,&local_a4);
    }
    uStack92 = (uint)(*(int *)&this->field_0x54 * iVar4) / uVar12;
    if (*(int *)&this->field_0x120 < (int)uStack92) {
      local_b0 = 0xff6400ff;
      local_ac = 0xff6400ff;
      local_50 = (double)CONCAT44(0x43300000,*(uint *)&this->field_0x118 ^ 0x80000000);
      uStack84 = *(uint *)&this->field_0x11c ^ 0x80000000;
      local_58 = 0x43300000;
      uStack92 = *(uint *)&this->field_0x120 ^ 0x80000000;
      local_60 = 0x43300000;
      J2DGraph::J2DFillBox
                ((double)(float)(local_50 - JUtility::_2247),
                 (double)(float)((double)CONCAT44(0x43300000,uStack84) - JUtility::_2247),
                 (double)(float)((double)CONCAT44(0x43300000,uStack92) - JUtility::_2247),
                 (double)JUtility::_2546,&local_ac);
    }
    else {
      local_b8 = 0x32ff00ff;
      local_b4 = 0x32ff00ff;
      local_50 = (double)CONCAT44(0x43300000,*(uint *)&this->field_0x118 ^ 0x80000000);
      uStack84 = *(uint *)&this->field_0x11c ^ 0x80000000;
      local_58 = 0x43300000;
      uStack92 = uStack92 ^ 0x80000000;
      local_60 = 0x43300000;
      J2DGraph::J2DFillBox
                ((double)(float)(local_50 - JUtility::_2247),
                 (double)(float)((double)CONCAT44(0x43300000,uStack84) - JUtility::_2247),
                 (double)(float)((double)CONCAT44(0x43300000,uStack92) - JUtility::_2247),
                 (double)JUtility::_2546,&local_b4);
    }
    if (*(int *)&this->field_0x110 == 0) {
      iVar7 = *(int *)&this->field_0x11c + *(int *)&this->field_0x114;
      local_c8 = 0x64ff78ff;
      local_c4 = 0x64ff78ff;
      local_c0 = 0x50ff50ff;
      local_bc = 0x50ff50ff;
      bar_subroutine(this,*(int *)&this->field_0x118 + 1,iVar7,uVar3,iVar4,uVar12,
                     *(int *)&this->field_0x18,*(int *)&this->field_0x1c,(TColor)&local_bc,
                     (TColor)&local_c4);
      iVar7 = iVar7 + *(int *)&this->field_0x114 * 2;
      local_d8 = 0xff6464ff;
      local_d4 = 0xff6464ff;
      local_d0 = 0xff5050ff;
      local_cc = 0xff5050ff;
      bar_subroutine(this,*(int *)&this->field_0x118 + 1,iVar7,uVar3,iVar4,uVar12,
                     *(int *)&this->field_0x2c,*(int *)&this->field_0x30,(TColor)&local_cc,
                     (TColor)&local_d4);
      local_e8 = 0xc8c8c8ff;
      local_e4 = 0xc8c8c8ff;
      local_e0 = 0xb4b4a0ff;
      local_dc = 0xb4b4a0ff;
      bar_subroutine(this,*(int *)&this->field_0x118 + 1,iVar7 + *(int *)&this->field_0x114 * 2,
                     uVar3,iVar4,uVar12,*(int *)&this->field_0x4,*(int *)&this->field_0x8,
                     (TColor)&local_dc,(TColor)&local_e4);
    }
    else {
      uVar2 = *(int *)&this->field_0x11c + *(int *)&this->field_0x114;
      iVar9 = *(int *)&this->field_0x118 + 1;
      local_f8 = 0x50ff50ff;
      local_f4 = 0x50ff50ff;
      local_f0 = 0x50ff50ff;
      local_ec = 0x50ff50ff;
      bar_subroutine(this,iVar9,uVar2,uVar3,iVar4,uVar12,iVar13,-1,(TColor)&local_ec,
                     (TColor)&local_f4);
      local_100 = 0xff00ff;
      local_fc = 0xff00ff;
      local_50 = (double)CONCAT44(0x43300000,iVar9 + (uint)(iVar13 * iVar4) / uVar12 ^ 0x80000000);
      uStack84 = uVar2 ^ 0x80000000;
      local_58 = 0x43300000;
      uStack92 = (uint)(*(int *)&this->field_0x40 * iVar4) / uVar12 ^ 0x80000000;
      local_60 = 0x43300000;
      uStack100 = uVar3 ^ 0x80000000;
      local_68 = 0x43300000;
      J2DGraph::J2DFillBox
                ((double)(float)(local_50 - JUtility::_2247),
                 (double)(float)((double)CONCAT44(0x43300000,uStack84) - JUtility::_2247),
                 (double)(float)((double)CONCAT44(0x43300000,uStack92) - JUtility::_2247),
                 (double)(float)((double)CONCAT44(0x43300000,uStack100) - JUtility::_2247),&local_fc
                );
      iVar5 = *(int *)&this->field_0x18;
      iVar10 = uVar2 + *(int *)&this->field_0x114 * 2;
      local_110 = 0xff5050ff;
      local_10c = 0xff5050ff;
      local_108 = 0xff5050ff;
      local_104 = 0xff5050ff;
      bar_subroutine(this,iVar9 + (uint)((iVar13 - iVar7) * iVar4) / uVar12,iVar10,uVar3,iVar4,
                     uVar12,*(int *)&this->field_0x2c,-1,(TColor)&local_104,(TColor)&local_10c);
      local_120 = 0xb4b4a0ff;
      local_11c = 0xb4b4a0ff;
      local_118 = 0xb4b4a0ff;
      local_114 = 0xb4b4a0ff;
      bar_subroutine(this,iVar9 + (uint)(iVar5 * iVar4) / uVar12,
                     iVar10 + *(int *)&this->field_0x114 * 2,uVar3,iVar4,uVar12,
                     *(int *)&this->field_0x4,-1,(TColor)&local_114,(TColor)&local_11c);
    }
    dVar15 = JUtility::_2247;
    for (iVar7 = 1; iVar7 < iVar1; iVar7 = iVar7 + 1) {
      if (iVar7 == (iVar7 / 5) * 5) {
        local_12c = 0xb4;
        local_12b = 0xff;
        local_12a = 0xff;
        local_129 = 0xff;
        puVar6 = (undefined4 *)&local_12c;
      }
      else {
        local_128 = 100;
        uStack295 = 100;
        uStack294 = 0xff;
        uStack293 = 0xff;
        puVar6 = (undefined4 *)&local_128;
      }
      local_124 = *puVar6;
      uStack92 = *(int *)&this->field_0x118 + iVar7 * iVar4 + 1 ^ 0x80000000;
      local_50 = (double)CONCAT44(0x43300000,uStack92);
      uStack84 = *(int *)&this->field_0x11c + *(int *)&this->field_0x114 ^ 0x80000000;
      local_58 = 0x43300000;
      local_60 = 0x43300000;
      uStack100 = (*(int *)&this->field_0x11c + uVar8) - *(int *)&this->field_0x114 ^ 0x80000000;
      local_68 = 0x43300000;
      J2DGraph::J2DDrawLine
                ((double)(float)(local_50 - dVar15),
                 (double)(float)((double)CONCAT44(0x43300000,uStack84) - dVar15),
                 (double)(float)((double)CONCAT44(0x43300000,uStack92) - dVar15),
                 (double)(float)((double)CONCAT44(0x43300000,uStack100) - dVar15),&local_124,0xc);
    }
    uVar8 = 0;
    iVar4 = 0;
    iVar1 = 8;
    do {
      iVar7 = &this->mpTimeHistory[0].field_0x0 + iVar4;
      uVar3 = *(int *)(iVar7 + 0xc) + 1;
      *(uint *)(iVar7 + 0xc) = uVar3;
      if ((0xf < uVar3) || (*(uint *)(iVar7 + 8) < *(uint *)(iVar7 + 4))) {
        *(undefined4 *)(iVar7 + 8) = *(undefined4 *)(iVar7 + 4);
        *(undefined4 *)(iVar7 + 0xc) = 0;
      }
      if (uVar8 < *(uint *)(iVar7 + 8)) {
        uVar8 = *(uint *)(iVar7 + 8);
      }
      iVar4 = iVar4 + 0x14;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    if (uVar8 != 0) {
      if (JUtility::init_2346 == '\0') {
        JUtility::cntUser_2345 = 0;
        JUtility::init_2346 = '\x01';
      }
      adjustMeterLength(this,uVar8,&JUtility::oneFrameRateUser,JUtility::_2546,JUtility::_2225,
                        &JUtility::cntUser_2345);
      iVar4 = (int)(JUtility::_2274 * JUtility::oneFrameRateUser);
      local_50 = (double)(longlong)iVar4;
      local_134 = 13000;
      local_130 = 13000;
      uStack84 = *(uint *)&this->field_0x118 ^ 0x80000000;
      local_58 = 0x43300000;
      uStack92 = *(uint *)&this->field_0x124 ^ 0x80000000;
      local_60 = 0x43300000;
      uStack100 = *(uint *)&this->field_0x120 ^ 0x80000000;
      local_68 = 0x43300000;
      uStack108 = uVar11 ^ 0x80000000;
      local_70 = 0x43300000;
      J2DGraph::J2DFillBox
                ((double)(float)((double)CONCAT44(0x43300000,uStack84) - JUtility::_2247),
                 (double)(float)((double)CONCAT44(0x43300000,uStack92) - JUtility::_2247),
                 (double)(float)((double)CONCAT44(0x43300000,uStack100) - JUtility::_2247),
                 (double)(float)((double)CONCAT44(0x43300000,uStack108) - JUtility::_2247),
                 &local_130);
      local_13c = 0x323296ff;
      local_138 = 0x323296ff;
      uStack116 = *(uint *)&this->field_0x118 ^ 0x80000000;
      local_78 = 0x43300000;
      uStack124 = *(uint *)&this->field_0x124 ^ 0x80000000;
      local_80 = 0x43300000;
      local_88 = (double)CONCAT44(0x43300000,*(uint *)&this->field_0x120 ^ 0x80000000);
      uStack68 = uVar11 ^ 0x80000000;
      local_48 = 0x43300000;
      J2DGraph::J2DDrawFrame
                ((double)(float)((double)CONCAT44(0x43300000,uStack116) - JUtility::_2247),
                 (double)(float)((double)CONCAT44(0x43300000,uStack124) - JUtility::_2247),
                 (double)(float)(local_88 - JUtility::_2247),
                 (double)(float)((double)CONCAT44(0x43300000,uStack68) - JUtility::_2247),&local_138
                 ,6);
      iVar1 = 0;
      iVar7 = 0;
      do {
        iVar13 = &this->mpTimeHistory[0].field_0x0 + iVar7;
        uVar8 = *(int *)(iVar13 + 0xc) + 1;
        *(uint *)(iVar13 + 0xc) = uVar8;
        if ((0xf < uVar8) || (*(uint *)(iVar13 + 8) < *(uint *)(iVar13 + 4))) {
          *(undefined4 *)(iVar13 + 8) = *(undefined4 *)(iVar13 + 4);
          *(undefined4 *)(iVar13 + 0xc) = 0;
        }
        iVar5 = *(int *)(iVar13 + 4);
        if ((iVar5 != 0) || (*(int *)(iVar13 + 8) != 0)) {
          uVar8 = (uint)(*(int *)(iVar13 + 8) * iVar4) / uVar12;
          *(undefined4 *)(iVar13 + 4) = 0;
          local_144 = CONCAT31(*(undefined3 *)(iVar13 + 0x10),0xff);
          local_140 = local_144;
          uStack92 = *(uint *)&this->field_0x114;
          uStack68 = *(int *)&this->field_0x118 + 1U ^ 0x80000000;
          local_48 = 0x43300000;
          local_50 = (double)CONCAT44(0x43300000,
                                      *(int *)&this->field_0x124 + uStack92 + iVar1 * uStack92 ^
                                      0x80000000);
          uStack84 = (uint)(iVar5 * iVar4) / uVar12 ^ 0x80000000;
          local_58 = 0x43300000;
          uStack92 = uStack92 ^ 0x80000000;
          local_60 = 0x43300000;
          J2DGraph::J2DFillBox
                    ((double)(float)((double)CONCAT44(0x43300000,uStack68) - JUtility::_2247),
                     (double)(float)(local_50 - JUtility::_2247),
                     (double)(float)((double)CONCAT44(0x43300000,uStack84) - JUtility::_2247),
                     (double)(float)((double)CONCAT44(0x43300000,uStack92) - JUtility::_2247),
                     &local_140);
          if (uVar8 < 3) {
            local_14c = 0xffc832ff;
            local_148 = 0xffc832ff;
            uStack92 = *(uint *)&this->field_0x114;
            uStack68 = *(uint *)&this->field_0x118 ^ 0x80000000;
            local_48 = 0x43300000;
            local_50 = (double)CONCAT44(0x43300000,
                                        *(int *)&this->field_0x124 + uStack92 + iVar1 * uStack92 ^
                                        0x80000000);
            uStack84 = uVar8 ^ 0x80000000;
            local_58 = 0x43300000;
            uStack92 = uStack92 ^ 0x80000000;
            local_60 = 0x43300000;
            J2DGraph::J2DFillBox
                      ((double)(float)((double)CONCAT44(0x43300000,uStack68) - JUtility::_2247),
                       (double)(float)(local_50 - JUtility::_2247),
                       (double)(float)((double)CONCAT44(0x43300000,uStack84) - JUtility::_2247),
                       (double)(float)((double)CONCAT44(0x43300000,uStack92) - JUtility::_2247),
                       &local_148);
          }
          else {
            local_154 = 0xffc832ff;
            local_150 = 0xffc832ff;
            uStack84 = *(uint *)&this->field_0x114;
            uStack68 = *(int *)&this->field_0x118 + (uVar8 - 3) ^ 0x80000000;
            local_48 = 0x43300000;
            local_50 = (double)CONCAT44(0x43300000,
                                        *(int *)&this->field_0x124 + uStack84 + iVar1 * uStack84 ^
                                        0x80000000);
            uStack84 = uStack84 ^ 0x80000000;
            local_58 = 0x43300000;
            J2DGraph::J2DFillBox
                      ((double)(float)((double)CONCAT44(0x43300000,uStack68) - JUtility::_2247),
                       (double)(float)(local_50 - JUtility::_2247),(double)JUtility::_2547,
                       (double)(float)((double)CONCAT44(0x43300000,uStack84) - JUtility::_2247),
                       &local_150);
          }
        }
        iVar1 = iVar1 + 1;
        iVar7 = iVar7 + 0x14;
      } while (iVar1 < 8);
      iVar1 = *(int *)&this->field_0x120;
      dVar15 = JUtility::_2247;
      for (iVar7 = 1; iVar7 < (iVar1 + iVar4 + -4) / iVar4; iVar7 = iVar7 + 1) {
        if (iVar7 == (iVar7 / 5) * 5) {
          local_160 = 0xb4;
          local_15f = 0xff;
          local_15e = 0xff;
          local_15d = 0xff;
          puVar6 = (undefined4 *)&local_160;
        }
        else {
          local_15c = 100;
          uStack347 = 100;
          uStack346 = 0xff;
          uStack345 = 0xff;
          puVar6 = (undefined4 *)&local_15c;
        }
        local_158 = *puVar6;
        uStack84 = *(int *)&this->field_0x118 + iVar7 * iVar4 + 1 ^ 0x80000000;
        local_48 = 0x43300000;
        local_50 = (double)CONCAT44(0x43300000,
                                    *(int *)&this->field_0x124 + *(int *)&this->field_0x114 ^
                                    0x80000000);
        local_58 = 0x43300000;
        uStack92 = (*(int *)&this->field_0x124 + uVar11) - *(int *)&this->field_0x114 ^ 0x80000000;
        local_60 = 0x43300000;
        uStack68 = uStack84;
        J2DGraph::J2DDrawLine
                  ((double)(float)((double)CONCAT44(0x43300000,uStack84) - dVar15),
                   (double)(float)(local_50 - dVar15),
                   (double)(float)((double)CONCAT44(0x43300000,uStack84) - dVar15),
                   (double)(float)((double)CONCAT44(0x43300000,uStack92) - dVar15),&local_158,0xc);
      }
    }
    *(undefined4 *)&this->field_0x108 = 0;
  }
  __psq_l0(auStack8,uVar14);
  __psq_l1(auStack8,uVar14);
  return;
}


namespace JUtility {

/* __stdcall addrToXPos(void *,
                        int) */

int addrToXPos(int param_1,uint param_2)

{
  return (int)((float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - _2247) *
              ((float)((double)CONCAT44(0x43300000,param_1 + -0x80000000) - _2281) /
              (float)((double)CONCAT44(0x43300000,JKRHeap::mMemorySize) - _2281)));
}


/* __stdcall byteToXLen(int,
                        int) */

int byteToXLen(uint param_1,uint param_2)

{
  return (int)((float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - _2247) *
              ((float)((double)CONCAT44(0x43300000,param_1 ^ 0x80000000) - _2247) /
              (float)((double)CONCAT44(0x43300000,JKRHeap::mMemorySize) - _2281)));
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __stdcall heapBar(JKRHeap *,
                     int,
                     int,
                     int,
                     int,
                     int) */

void heapBar(JKRHeap *param_1,int param_2,int param_3,undefined4 param_4,
                      undefined4 param_5,uint param_6)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  uint uStack84;
  undefined4 local_50;
  uint uStack76;
  undefined4 local_48;
  uint uStack68;
  undefined4 local_40;
  uint uStack60;
  undefined4 local_38;
  uint uStack52;
  undefined4 local_30;
  uint uStack44;
  undefined4 local_28;
  uint uStack36;
  undefined4 local_20;
  uint uStack28;
  
  iVar1 = addrToXPos(param_1->mpDataBegin,param_5);
  uStack52 = param_2 + iVar1;
  iVar1 = addrToXPos(param_1->mpDataEnd,param_5);
  uVar2 = JKRHeap::getTotalFreeSize(param_1);
  uStack36 = byteToXLen(uVar2,param_5);
  local_60 = 0xff00c8ff;
  local_5c = 0xff00c8ff;
  uStack28 = ((int)param_6 >> 1) + (uint)((int)param_6 < 0 && (param_6 & 1) != 0);
  uStack84 = uStack52 ^ 0x80000000;
  local_58 = 0x43300000;
  uStack44 = uStack28 + param_3 + param_6 * -2;
  uStack76 = uStack44 ^ 0x80000000;
  local_50 = 0x43300000;
  uStack68 = (param_2 + iVar1) - uStack52 ^ 0x80000000;
  local_48 = 0x43300000;
  uStack60 = uStack28 ^ 0x80000000;
  local_40 = 0x43300000;
  J2DGraph::J2DFillBox
            ((double)(float)((double)CONCAT44(0x43300000,uStack84) - _2247),
             (double)(float)((double)CONCAT44(0x43300000,uStack76) - _2247),
             (double)(float)((double)CONCAT44(0x43300000,uStack68) - _2247),
             (double)(float)((double)CONCAT44(0x43300000,uStack60) - _2247),&local_5c);
  local_64 = 0xffb4faff;
  uStack52 = uStack52 ^ 0x80000000;
  local_38 = 0x43300000;
  uStack44 = uStack44 ^ 0x80000000;
  local_30 = 0x43300000;
  uStack36 = uStack36 ^ 0x80000000;
  local_28 = 0x43300000;
  uStack28 = uStack28 ^ 0x80000000;
  local_20 = 0x43300000;
  J2DGraph::J2DFillBox
            ((double)(float)((double)CONCAT44(0x43300000,uStack52) - _2247),
             (double)(float)((double)CONCAT44(0x43300000,uStack44) - _2247),
             (double)(float)((double)CONCAT44(0x43300000,uStack36) - _2247),
             (double)(float)((double)CONCAT44(0x43300000,uStack28) - _2247),&local_64);
  return;
}

}

/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall JUTProcBar::drawHeapBar(void) */

void __thiscall JUTProcBar::drawHeapBar(JUTProcBar *this)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  JKRHeap *pJVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  uint uStack188;
  undefined4 local_b8;
  uint uStack180;
  undefined4 local_b0;
  uint uStack172;
  undefined4 local_a8;
  uint uStack164;
  undefined4 local_a0;
  uint uStack156;
  undefined4 local_98;
  uint uStack148;
  undefined4 local_90;
  uint uStack140;
  undefined4 local_88;
  uint uStack132;
  undefined4 local_80;
  uint uStack124;
  undefined4 local_78;
  uint uStack116;
  undefined4 local_70;
  uint uStack108;
  undefined4 local_68;
  uint uStack100;
  undefined4 local_60;
  uint uStack92;
  undefined4 local_58;
  uint uStack84;
  undefined4 local_50;
  uint uStack76;
  undefined4 local_48;
  uint uStack68;
  undefined4 local_40;
  uint uStack60;
  undefined4 local_38;
  uint uStack52;
  undefined4 local_30;
  uint uStack44;
  undefined4 local_28;
  uint uStack36;
  
  if (this->mbDrawHeapBar != 0) {
    uVar9 = *(uint *)&this->field_0x118;
    iVar8 = *(int *)&this->field_0x11c;
    uVar6 = *(uint *)&this->field_0x114;
    uVar1 = uVar6 << 1;
    uVar7 = *(uint *)&this->field_0x120;
    local_c8 = 0x640032c8;
    local_c4 = 0x640032c8;
    uStack188 = uVar9 ^ 0x80000000;
    local_c0 = 0x43300000;
    uStack52 = iVar8 + uVar6 * -4;
    uStack180 = uStack52 ^ 0x80000000;
    local_b8 = 0x43300000;
    uStack172 = uVar7 ^ 0x80000000;
    local_b0 = 0x43300000;
    uStack164 = uVar1 ^ 0x80000000;
    local_a8 = 0x43300000;
    J2DGraph::J2DFillBox
              ((double)(float)((double)CONCAT44(0x43300000,uStack188) - JUtility::_2247),
               (double)(float)((double)CONCAT44(0x43300000,uStack180) - JUtility::_2247),
               (double)(float)((double)CONCAT44(0x43300000,uStack172) - JUtility::_2247),
               (double)(float)((double)CONCAT44(0x43300000,uStack164) - JUtility::_2247),&local_c4);
    local_d0 = 0x643296ff;
    local_cc = 0x643296ff;
    uStack156 = uVar9 ^ 0x80000000;
    local_a0 = 0x43300000;
    uStack148 = uStack52 ^ 0x80000000;
    local_98 = 0x43300000;
    uStack140 = uVar7 ^ 0x80000000;
    local_90 = 0x43300000;
    uStack132 = uVar1 ^ 0x80000000;
    local_88 = 0x43300000;
    J2DGraph::J2DDrawFrame
              ((double)(float)((double)CONCAT44(0x43300000,uStack156) - JUtility::_2247),
               (double)(float)((double)CONCAT44(0x43300000,uStack148) - JUtility::_2247),
               (double)(float)((double)CONCAT44(0x43300000,uStack140) - JUtility::_2247),
               (double)(float)((double)CONCAT44(0x43300000,uStack132) - JUtility::_2247),&local_cc,6
              );
    iVar2 = JUtility::addrToXPos(JKRHeap::mCodeStart,uVar7);
    iVar3 = JUtility::addrToXPos(JKRHeap::mCodeEnd,uVar7);
    local_d8 = 0xff3296ff;
    local_d4 = 0xff3296ff;
    uStack124 = uVar9 + iVar2 ^ 0x80000000;
    local_80 = 0x43300000;
    uStack116 = uStack52 ^ 0x80000000;
    local_78 = 0x43300000;
    uStack108 = (uVar9 + iVar3) - (uVar9 + iVar2) ^ 0x80000000;
    local_70 = 0x43300000;
    uStack100 = uVar1 ^ 0x80000000;
    local_68 = 0x43300000;
    J2DGraph::J2DFillBox
              ((double)(float)((double)CONCAT44(0x43300000,uStack124) - JUtility::_2247),
               (double)(float)((double)CONCAT44(0x43300000,uStack116) - JUtility::_2247),
               (double)(float)((double)CONCAT44(0x43300000,uStack108) - JUtility::_2247),
               (double)(float)((double)CONCAT44(0x43300000,uStack100) - JUtility::_2247),&local_d4);
    iVar2 = JUtility::addrToXPos(JKRHeap::mUserRamStart,uVar7);
    uStack60 = uVar9 + iVar2;
    iVar2 = JUtility::addrToXPos(JKRHeap::mUserRamEnd,uVar7);
    local_e0 = 0x3296ff;
    local_dc = 0x3296ff;
    uStack92 = uStack60 ^ 0x80000000;
    local_60 = 0x43300000;
    uStack84 = uStack52 ^ 0x80000000;
    local_58 = 0x43300000;
    uStack76 = (uVar9 + iVar2) - uStack60 ^ 0x80000000;
    local_50 = 0x43300000;
    uStack68 = uVar1 ^ 0x80000000;
    local_48 = 0x43300000;
    J2DGraph::J2DFillBox
              ((double)(float)((double)CONCAT44(0x43300000,uStack92) - JUtility::_2247),
               (double)(float)((double)CONCAT44(0x43300000,uStack84) - JUtility::_2247),
               (double)(float)((double)CONCAT44(0x43300000,uStack76) - JUtility::_2247),
               (double)(float)((double)CONCAT44(0x43300000,uStack68) - JUtility::_2247),&local_dc);
    uVar4 = JKRHeap::getTotalFreeSize(JKRHeap::sRootHeap);
    uStack44 = JUtility::byteToXLen(uVar4,uVar7);
    local_e4 = 0xfafaff;
    uStack60 = uStack60 ^ 0x80000000;
    local_40 = 0x43300000;
    uStack52 = uStack52 ^ 0x80000000;
    local_38 = 0x43300000;
    uStack44 = uStack44 ^ 0x80000000;
    local_30 = 0x43300000;
    uStack36 = (int)(uVar1 | uVar6 >> 0x1f) >> 1 ^ 0x80000000;
    local_28 = 0x43300000;
    J2DGraph::J2DFillBox
              ((double)(float)((double)CONCAT44(0x43300000,uStack60) - JUtility::_2247),
               (double)(float)((double)CONCAT44(0x43300000,uStack52) - JUtility::_2247),
               (double)(float)((double)CONCAT44(0x43300000,uStack44) - JUtility::_2247),
               (double)(float)((double)CONCAT44(0x43300000,uStack36) - JUtility::_2247),&local_e4);
    if (*(int *)&this->field_0x128 == 0) {
      pJVar5 = JKRHeap::sCurrentHeap;
      if (*(JKRHeap **)&this->field_0x12c != (JKRHeap *)0x0) {
        pJVar5 = *(JKRHeap **)&this->field_0x12c;
      }
      if (pJVar5 != JKRHeap::sSystemHeap) {
        JUtility::heapBar(pJVar5,uVar9,iVar8,uVar1,uVar7,uVar1);
      }
    }
  }
  return;
}


namespace JUTProcBar {

/* __thiscall CTime::CTime(void) */

void __thiscall CTime::CTime(CTime *this)

{
  *(undefined4 *)&this->field_0x4 = 0;
  *(undefined4 *)&this->field_0x8 = 0;
  *(undefined4 *)&this->field_0xc = 0;
  return;
}

