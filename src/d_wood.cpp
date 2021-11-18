#include <d_wood.h>
#include <mtx/mtx.h>
#include <d_wood.h>
#include <Runtime.PPCEABI.H/ptmf.h>
#include <m_Do_mtx.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <SComponent/c_lib.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <SComponent/c_bg_s_gnd_chk.h>
#include <SComponent/c_bg_s.h>
#include <SComponent/c_bg_s_chk.h>
#include <d_cc_mass_s.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <d_kankyo.h>
#include <d_particle.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <JKernel/JKRHeap.h>
#include <SComponent/c_m3d_g_cyl.h>
#include <d_kankyo_wether.h>
#include <SComponent/c_math.h>
#include <gf/GFGeometry.h>
#include <gx/GXDisplayList.h>
#include <gf/GFTev.h>
#include <gf/GFTransform.h>
#include <dWood/Unit_c.h>
#include <Demangler/dWood/Packet_c.h>
#include <dWood/Room_c.h>
#include <dWood/Anm_c.h>


namespace d_wood {

namespace Packet_c {
}
}

namespace dWood {
undefined1 Anm_c;
}

namespace d_wood {
undefined1 init$4196;
undefined4 anm_norm_num$5226;
undefined1 init$5227;
}

namespace dWood {

/* __thiscall Anm_c::Anm_c(void) */

void __thiscall Anm_c::Anm_c(Anm_c *this)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  mtx::PSMTXIdentity((MTX34 *)this);
  mtx::PSMTXIdentity((MTX34 *)&this->field_0x30);
  this->field_0x60 = 6;
  this->field_0x64 = 0;
  *(undefined2 *)&this->field_0x66 = 0;
  fVar1 = d_wood::_4183;
  *(float *)&this->field_0x68 = d_wood::_4183;
  *(float *)&this->field_0x6c = fVar1;
  *(float *)&this->field_0x70 = fVar1;
  *(float *)&this->field_0x74 = fVar1;
  iVar2 = 0;
  iVar4 = 2;
  do {
    iVar3 = &this->field_0x0 + iVar2;
    *(undefined2 *)(iVar3 + 0x78) = 0;
    *(undefined2 *)(iVar3 + 0x7c) = 0;
    *(undefined2 *)(iVar3 + 0x80) = 0;
    *(undefined2 *)(iVar3 + 0x84) = 0;
    iVar2 = iVar2 + 2;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  *(undefined2 *)&this->field_0x88 = 0;
  this->field_0x8a = 0xff;
  return;
}


/* __thiscall Anm_c::play(Packet_c *) */

void __thiscall Anm_c::play(Anm_c *this,Packet_c *param_1)

{
  if (this->field_0x60 != 6) {
    if (d_wood::init_4196 == '\0') {
      d_wood::mode_proc_4189 = d_wood::_4190;
      DAT_8037fc90 = DAT_8037fc48;
      DAT_8037fc94 = PTR_mode_cut_8037fc4c;
      DAT_8037fc98 = d_wood::_4191;
      DAT_8037fc9c = DAT_8037fc54;
      DAT_8037fca0 = PTR_mode_push_into_8037fc58;
      DAT_8037fca4 = d_wood::_4192;
      DAT_8037fca8 = DAT_8037fc60;
      DAT_8037fcac = PTR_mode_push_back_8037fc64;
      DAT_8037fcb0 = d_wood::_4193;
      DAT_8037fcb4 = DAT_8037fc6c;
      DAT_8037fcb8 = PTR_mode_fan_8037fc70;
      DAT_8037fcbc = d_wood::_4194;
      DAT_8037fcc0 = DAT_8037fc78;
      DAT_8037fcc4 = PTR_mode_norm_8037fc7c;
      DAT_8037fcc8 = d_wood::_4195;
      DAT_8037fccc = DAT_8037fc84;
      DAT_8037fcd0 = PTR_mode_to_norm_8037fc88;
      d_wood::init_4196 = '\x01';
    }
    Runtime.PPCEABI.H::__ptmf_scall
              ((PTMF *)(&d_wood::mode_proc_4189 + this->field_0x60 * 3),this,param_1);
  }
  return;
}


/* __thiscall Anm_c::copy_angamp(Anm_c const *) */

void __thiscall Anm_c::copy_angamp(Anm_c *this,Anm_c *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (this == param_1) {
    return;
  }
  iVar1 = 0;
  iVar4 = 2;
  do {
    iVar2 = &param_1->field_0x0 + iVar1;
    iVar3 = &this->field_0x0 + iVar1;
    *(undefined2 *)(iVar3 + 0x78) = *(undefined2 *)(iVar2 + 0x78);
    *(undefined2 *)(iVar3 + 0x7c) = *(undefined2 *)(iVar2 + 0x7c);
    *(undefined2 *)(iVar3 + 0x80) = *(undefined2 *)(iVar2 + 0x80);
    *(undefined2 *)(iVar3 + 0x84) = *(undefined2 *)(iVar2 + 0x84);
    iVar1 = iVar1 + 2;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return;
}


/* __thiscall Anm_c::mode_cut_init(Anm_c const *,
                                          short) */

void __thiscall Anm_c::mode_cut_init(Anm_c *this,Anm_c *param_1,short param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = 0;
  iVar4 = 2;
  do {
    iVar3 = &this->field_0x0 + iVar2;
    *(undefined2 *)(iVar3 + 0x78) = 0;
    *(undefined2 *)(iVar3 + 0x7c) = 0;
    *(undefined2 *)(iVar3 + 0x80) = 0;
    *(undefined2 *)(iVar3 + 0x84) = 0;
    iVar2 = iVar2 + 2;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  *(short *)&this->field_0x66 = param_2;
  *(undefined4 *)&this->field_0x74 = DAT_80359f9c;
  fVar1 = d_wood::_4183;
  *(float *)&this->field_0x6c = d_wood::_4183;
  *(float *)&this->field_0x70 = fVar1;
  this->field_0x8a = 0xff;
  this->field_0x64 = (ushort)DAT_80359f98;
  this->field_0x60 = 0;
  return;
}


/* __thiscall Anm_c::mode_cut(Packet_c *) */

void __thiscall Anm_c::mode_cut(Anm_c *this,Packet_c *param_1)

{
  int iVar1;
  
  *(float *)&this->field_0x74 = *(float *)&this->field_0x74 + DAT_80359fa0;
  if (*(float *)&this->field_0x74 < d_wood::_4245) {
    *(float *)&this->field_0x74 = d_wood::_4245;
  }
  *(float *)&this->field_0x6c = *(float *)&this->field_0x6c + *(float *)&this->field_0x74;
  *(float *)&this->field_0x70 = *(float *)&this->field_0x70 + DAT_80359fa4;
  *(short *)&this->field_0x7c = *(short *)&this->field_0x7c - DAT_80359fa8;
  m_Do_mtx::mDoMtx_YrotS(&mDoMtx_stack_c::now,(int)*(short *)&this->field_0x66);
  mDoMtx_stack_c::transM(d_wood::_4183,*(float *)&this->field_0x6c,*(float *)&this->field_0x70);
  m_Do_mtx::mDoMtx_XrotM(&mDoMtx_stack_c::now,*(short *)&this->field_0x7c);
  m_Do_mtx::mDoMtx_YrotM(&mDoMtx_stack_c::now,-*(short *)&this->field_0x66);
  mtx::PSMTXCopy(&mDoMtx_stack_c::now,(MTX34 *)this);
  if (this->field_0x64 < (short)(ushort)DAT_80359f99) {
    iVar1 = (uint)this->field_0x8a - (uint)DAT_80359f9a;
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    this->field_0x8a = (byte)iVar1;
  }
  if (0 < this->field_0x64) {
    this->field_0x64 = this->field_0x64 + -1;
  }
  return;
}


/* __thiscall Anm_c::mode_push_into_init(Anm_c const *,
                                                short) */

void __thiscall Anm_c::mode_push_into_init(Anm_c *this,Anm_c *param_1,short param_2)

{
  copy_angamp(this,param_1);
  *(short *)&this->field_0x66 = param_2;
  this->field_0x8a = 0xff;
  this->field_0x64 = 2;
  this->field_0x60 = 1;
  return;
}


/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* WARNING: Removing unreachable block (ram,0x800bdbfc) */
/* WARNING: Removing unreachable block (ram,0x800bdbec) */
/* WARNING: Removing unreachable block (ram,0x800bdbf4) */
/* WARNING: Removing unreachable block (ram,0x800bdc04) */
/* __thiscall Anm_c::mode_push_into(Packet_c *) */

void __thiscall Anm_c::mode_push_into(Anm_c *this,Packet_c *param_1)

{
  double dVar1;
  ushort uVar2;
  short target;
  short sVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  undefined8 in_f28;
  double dVar9;
  undefined8 in_f29;
  undefined8 in_f30;
  double dVar10;
  double dVar11;
  undefined8 in_f31;
  double dVar12;
  double local_78;
  double local_70;
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar8 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  sVar3 = this->field_0x64 + -1;
  this->field_0x64 = sVar3;
  if (sVar3 < 1) {
    mode_push_back_init(this);
  }
  else {
    dVar10 = (double)d_wood::_4183;
    iVar6 = 0;
    iVar5 = 0;
    iVar4 = 0;
    dVar11 = dVar10;
    dVar12 = d_wood::_4285;
    do {
      sVar3 = *(short *)((int)&DAT_80359f84 + iVar4);
      uVar2 = *(ushort *)((int)&DAT_80359f82 + iVar4);
      target = *(short *)((int)&DAT_80359f86 + iVar4);
      dVar9 = (double)*(float *)((int)&DAT_80359f88 + iVar4);
      iVar7 = &this->field_0x0 + iVar5;
      *(short *)(iVar7 + 0x78) = *(short *)(iVar7 + 0x78) + *(short *)((int)&DAT_80359f80 + iVar4);
      SComponent::cLib_chaseAngleS(iVar7 + 0x7c,0,(int)sVar3);
      SComponent::cLib_chaseS
                (iVar7 + 0x80,
                 (int)(short)(((short)uVar2 >> 2) + (ushort)((short)uVar2 < 0 && (uVar2 & 3) != 0)),
                 0x14);
      SComponent::cLib_addCalcAngleS((short *)(iVar7 + 0x84),target,8,0x14,5);
      local_78 = (double)CONCAT44(0x43300000,(int)*(short *)(iVar7 + 0x80) ^ 0x80000000);
      dVar1 = dVar11 + (double)((float)(local_78 - dVar12) *
                               JKernel::JMath::jmaCosTable
                               [(int)((int)*(short *)(iVar7 + 0x78) & 0xffffU) >>
                                (JKernel::JMath::jmaSinShift & 0x3f)]);
      dVar11 = (double)(float)dVar1;
      local_70 = (double)CONCAT44(0x43300000,(int)*(short *)(iVar7 + 0x84) ^ 0x80000000);
      dVar10 = (double)(float)(dVar10 + (double)((float)(local_70 - dVar12) *
                                                (float)(dVar9 + (double)JKernel::JMath::jmaCosTable
                                                                        [(int)((int)*(short *)(iVar7
                                                                                              + 0x7c
                                                  ) & 0xffffU) >>
                                                  (JKernel::JMath::jmaSinShift & 0x3f)])));
      iVar6 = iVar6 + 1;
      iVar5 = iVar5 + 2;
      iVar4 = iVar4 + 0xc;
    } while (iVar6 < 2);
    m_Do_mtx::mDoMtx_YrotS(this,(int)(short)((short)(int)dVar1 + *(short *)&this->field_0x66));
    m_Do_mtx::mDoMtx_XrotM((MTX34 *)this,(short)(int)dVar10);
    m_Do_mtx::mDoMtx_YrotM((MTX34 *)this,-*(short *)&this->field_0x66);
  }
  __psq_l0(auStack8,uVar8);
  __psq_l1(auStack8,uVar8);
  __psq_l0(auStack24,uVar8);
  __psq_l1(auStack24,uVar8);
  __psq_l0(auStack40,uVar8);
  __psq_l1(auStack40,uVar8);
  __psq_l0(auStack56,uVar8);
  __psq_l1(auStack56,uVar8);
  return;
}


/* __thiscall Anm_c::mode_push_back_init(void) */

void __thiscall Anm_c::mode_push_back_init(Anm_c *this)

{
  this->field_0x64 = (ushort)DAT_80359fcc;
  this->field_0x8a = 0xff;
  this->field_0x60 = 2;
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* WARNING: Removing unreachable block (ram,0x800bdea4) */
/* WARNING: Removing unreachable block (ram,0x800bde94) */
/* WARNING: Removing unreachable block (ram,0x800bde8c) */
/* WARNING: Removing unreachable block (ram,0x800bde9c) */
/* WARNING: Removing unreachable block (ram,0x800bdeac) */
/* __thiscall Anm_c::mode_push_back(Packet_c *) */

void __thiscall Anm_c::mode_push_back(Anm_c *this,Packet_c *param_1)

{
  double dVar1;
  short sVar2;
  short sVar3;
  AnmID_e AVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined8 in_f27;
  double dVar10;
  undefined8 in_f28;
  undefined8 in_f29;
  double dVar11;
  double dVar12;
  undefined8 in_f30;
  double dVar13;
  undefined8 in_f31;
  double dVar14;
  double local_a8;
  double local_88;
  double local_80;
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar9 = 0;
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
  sVar3 = this->field_0x64 + -1;
  this->field_0x64 = sVar3;
  if (sVar3 < 1) {
    AVar4 = Packet_c::search_anm(param_1,4);
    mode_to_norm_init(this,AVar4);
  }
  else {
    local_a8 = (double)CONCAT44(0x43300000,(int)this->field_0x64 ^ 0x80000000);
    dVar13 = (double)((float)(local_a8 - d_wood::_4285) *
                     (d_wood::_4325 /
                     (float)((double)CONCAT44(0x43300000,(uint)DAT_80359fcc) - d_wood::_4328)));
    dVar11 = (double)d_wood::_4183;
    iVar7 = 0;
    iVar6 = 0;
    iVar5 = 0;
    dVar12 = dVar11;
    dVar14 = d_wood::_4285;
    do {
      sVar3 = *(short *)((int)&DAT_80359f84 + iVar5);
      sVar2 = *(short *)((int)&DAT_80359f82 + iVar5);
      dVar1 = dVar13 * (double)(float)((double)CONCAT44(0x43300000,
                                                        (int)*(short *)((int)&DAT_80359f86 + iVar5)
                                                        ^ 0x80000000) - dVar14);
      dVar10 = (double)*(float *)((int)&DAT_80359f88 + iVar5);
      iVar8 = &this->field_0x0 + iVar6;
      *(short *)(iVar8 + 0x78) = *(short *)(iVar8 + 0x78) + *(short *)((int)&DAT_80359f80 + iVar5);
      *(short *)(iVar8 + 0x7c) = *(short *)(iVar8 + 0x7c) + sVar3;
      SComponent::cLib_chaseS
                (iVar8 + 0x80,
                 (int)(short)(int)(dVar13 * (double)(float)((double)CONCAT44(0x43300000,
                                                                             (int)sVar2 ^ 0x80000000
                                                                            ) - dVar14)),0x14);
      SComponent::cLib_chaseS(iVar8 + 0x84,(int)(short)(int)dVar1,0x14);
      local_88 = (double)CONCAT44(0x43300000,(int)*(short *)(iVar8 + 0x80) ^ 0x80000000);
      dVar1 = dVar12 + (double)((float)(local_88 - dVar14) *
                               JKernel::JMath::jmaCosTable
                               [(int)((int)*(short *)(iVar8 + 0x78) & 0xffffU) >>
                                (JKernel::JMath::jmaSinShift & 0x3f)]);
      dVar12 = (double)(float)dVar1;
      local_80 = (double)CONCAT44(0x43300000,(int)*(short *)(iVar8 + 0x84) ^ 0x80000000);
      dVar11 = (double)(float)(dVar11 + (double)((float)(local_80 - dVar14) *
                                                (float)(dVar10 + (double)JKernel::JMath::jmaCosTable
                                                                         [(int)((int)*(short *)(
                                                  iVar8 + 0x7c) & 0xffffU) >>
                                                  (JKernel::JMath::jmaSinShift & 0x3f)])));
      iVar7 = iVar7 + 1;
      iVar6 = iVar6 + 2;
      iVar5 = iVar5 + 0xc;
    } while (iVar7 < 2);
    m_Do_mtx::mDoMtx_YrotS(this,(int)(short)((short)(int)dVar1 + *(short *)&this->field_0x66));
    m_Do_mtx::mDoMtx_XrotM((MTX34 *)this,(short)(int)dVar11);
    m_Do_mtx::mDoMtx_YrotM((MTX34 *)this,-*(short *)&this->field_0x66);
  }
  __psq_l0(auStack8,uVar9);
  __psq_l1(auStack8,uVar9);
  __psq_l0(auStack24,uVar9);
  __psq_l1(auStack24,uVar9);
  __psq_l0(auStack40,uVar9);
  __psq_l1(auStack40,uVar9);
  __psq_l0(auStack56,uVar9);
  __psq_l1(auStack56,uVar9);
  __psq_l0(auStack72,uVar9);
  __psq_l1(auStack72,uVar9);
  return;
}


/* __thiscall Anm_c::mode_fan(Packet_c *) */

void __thiscall Anm_c::mode_fan(Anm_c *this,Packet_c *param_1)

{
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall Anm_c::mode_norm_init(void) */

void __thiscall Anm_c::mode_norm_init(Anm_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  this->field_0x60 = 4;
  iVar1 = 0;
  iVar2 = 0;
  iVar4 = 2;
  do {
    iVar3 = &this->field_0x0 + iVar2;
    *(short *)(iVar3 + 0x78) = (short)(_M_init_num << 0xd);
    *(short *)(iVar3 + 0x7c) = (short)(_M_init_num << 0xd);
    *(undefined2 *)(iVar3 + 0x80) = *(undefined2 *)((int)&DAT_80359f3a + iVar1);
    *(undefined2 *)(iVar3 + 0x84) = *(undefined2 *)((int)&DAT_80359f3e + iVar1);
    iVar1 = iVar1 + 0xc;
    iVar2 = iVar2 + 2;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  this->field_0x8a = 0xff;
  iVar1 = _M_init_num + 1 >> 0x1f;
  _M_init_num = (iVar1 * 8 | (uint)((_M_init_num + 1) * 0x20000000 + iVar1) >> 0x1d) - iVar1;
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* WARNING: Removing unreachable block (ram,0x800be120) */
/* WARNING: Removing unreachable block (ram,0x800be110) */
/* WARNING: Removing unreachable block (ram,0x800be118) */
/* WARNING: Removing unreachable block (ram,0x800be128) */
/* __thiscall Anm_c::mode_norm(Packet_c *) */

void __thiscall Anm_c::mode_norm(Anm_c *this,Packet_c *param_1)

{
  double dVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  short *psVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  undefined8 in_f28;
  double dVar12;
  undefined8 in_f29;
  undefined8 in_f30;
  double dVar13;
  double dVar14;
  undefined8 in_f31;
  double dVar15;
  double local_78;
  double local_70;
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar11 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  if (d_wood::_4394 <= *(float *)&this->field_0x68) {
    if (d_wood::_4395 <= *(float *)&this->field_0x68) {
      iVar5 = 2;
    }
    else {
      iVar5 = 1;
    }
  }
  else {
    iVar5 = 0;
  }
  dVar13 = (double)d_wood::_4183;
  iVar9 = 0;
  iVar8 = 0;
  iVar7 = 0;
  dVar14 = dVar13;
  dVar15 = d_wood::_4285;
  do {
    psVar6 = (short *)(&@unnamed@d_wood_cpp@::L_attr + iVar7 + iVar5 * 0x18);
    sVar2 = psVar6[2];
    sVar3 = psVar6[1];
    sVar4 = psVar6[3];
    dVar12 = (double)*(float *)(psVar6 + 4);
    iVar10 = &this->field_0x0 + iVar8;
    *(short *)(iVar10 + 0x78) = *(short *)(iVar10 + 0x78) + *psVar6;
    *(short *)(iVar10 + 0x7c) = *(short *)(iVar10 + 0x7c) + sVar2;
    SComponent::cLib_chaseS(iVar10 + 0x80,(int)sVar3,2);
    SComponent::cLib_chaseS(iVar10 + 0x84,(int)sVar4,2);
    local_78 = (double)CONCAT44(0x43300000,(int)*(short *)(iVar10 + 0x80) ^ 0x80000000);
    dVar1 = dVar14 + (double)((float)(local_78 - dVar15) *
                             JKernel::JMath::jmaCosTable
                             [(int)((int)*(short *)(iVar10 + 0x78) & 0xffffU) >>
                              (JKernel::JMath::jmaSinShift & 0x3f)]);
    dVar14 = (double)(float)dVar1;
    local_70 = (double)CONCAT44(0x43300000,(int)*(short *)(iVar10 + 0x84) ^ 0x80000000);
    dVar13 = (double)(float)(dVar13 + (double)((float)(local_70 - dVar15) *
                                              (float)(dVar12 + (double)JKernel::JMath::jmaCosTable
                                                                       [(int)((int)*(short *)(iVar10
                                                                                             + 0x7c)
                                                                             & 0xffffU) >>
                                                                        (JKernel::JMath::jmaSinShift
                                                                        & 0x3f)])));
    iVar9 = iVar9 + 1;
    iVar8 = iVar8 + 2;
    iVar7 = iVar7 + 0xc;
  } while (iVar9 < 2);
  m_Do_mtx::mDoMtx_YrotS(this,(int)(short)((short)(int)dVar1 + *(short *)&this->field_0x66));
  m_Do_mtx::mDoMtx_XrotM((MTX34 *)this,(short)(int)dVar13);
  m_Do_mtx::mDoMtx_YrotM((MTX34 *)this,-*(short *)&this->field_0x66);
  __psq_l0(auStack8,uVar11);
  __psq_l1(auStack8,uVar11);
  __psq_l0(auStack24,uVar11);
  __psq_l1(auStack24,uVar11);
  __psq_l0(auStack40,uVar11);
  __psq_l1(auStack40,uVar11);
  __psq_l0(auStack56,uVar11);
  __psq_l1(auStack56,uVar11);
  return;
}


/* __thiscall Anm_c::mode_norm_set_wind(float,
                                               short) */

void __thiscall Anm_c::mode_norm_set_wind(Anm_c *this,float param_1,short param_2)

{
  *(float *)&this->field_0x68 = param_1;
  *(short *)&this->field_0x66 = param_2;
  return;
}


/* __thiscall Anm_c::mode_to_norm_init(AnmID_e) */

void __thiscall Anm_c::mode_to_norm_init(Anm_c *this,AnmID_e param_1)

{
  bool bVar1;
  ulong uVar2;
  
  bVar1 = false;
  if ((-1 < (int)param_1) && ((int)param_1 < 8)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar2,"d_wood.cpp",0x4d7,"(anm_id_norm >= 0) && (anm_id_norm < AnmID_Norm_Max)");
    m_Do_printf::OSPanic("d_wood.cpp",0x4d7,&DAT_8035a010);
  }
  *(short *)&this->field_0x88 = (short)param_1;
  this->field_0x8a = 0xff;
  this->field_0x64 = 0x14;
  this->field_0x60 = 5;
  return;
}


/* WARNING: Inlined function: FUN_80328f24 */
/* WARNING: Inlined function: FUN_80328f70 */
/* WARNING: Removing unreachable block (ram,0x800be400) */
/* WARNING: Removing unreachable block (ram,0x800be3f0) */
/* WARNING: Removing unreachable block (ram,0x800be3f8) */
/* WARNING: Removing unreachable block (ram,0x800be408) */
/* __thiscall Anm_c::mode_to_norm(Packet_c *) */

void __thiscall Anm_c::mode_to_norm(Anm_c *this,Packet_c *param_1)

{
  double dVar1;
  short sVar2;
  short *psVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  Anm_c *pAVar10;
  undefined4 uVar11;
  undefined8 in_f28;
  double dVar12;
  undefined8 in_f29;
  undefined8 in_f30;
  double dVar13;
  double dVar14;
  undefined8 in_f31;
  double dVar15;
  double local_78;
  double local_70;
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar11 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  pAVar10 = param_1->mAnm + *(short *)&this->field_0x88;
  if (d_wood::_4394 <= *(float *)&pAVar10->field_0x68) {
    if (d_wood::_4395 <= *(float *)&pAVar10->field_0x68) {
      iVar4 = 2;
    }
    else {
      iVar4 = 1;
    }
  }
  else {
    iVar4 = 0;
  }
  SComponent::cLib_chaseAngleS(&this->field_0x66,(int)*(short *)&pAVar10->field_0x66,3000);
  dVar13 = (double)d_wood::_4183;
  iVar8 = 0;
  iVar7 = 0;
  iVar6 = 0;
  dVar14 = dVar13;
  dVar15 = d_wood::_4285;
  do {
    psVar3 = (short *)(&@unnamed@d_wood_cpp@::L_attr + iVar6 + iVar4 * 0x18);
    dVar12 = (double)*(float *)(psVar3 + 4);
    sVar2 = psVar3[2];
    iVar9 = &this->field_0x0 + iVar7;
    iVar5 = &pAVar10->field_0x0 + iVar7;
    SComponent::cLib_chaseS(iVar9 + 0x78,(int)*(short *)(iVar5 + 0x78),(int)(short)(*psVar3 + 3000))
    ;
    SComponent::cLib_chaseS(iVar9 + 0x7c,(int)*(short *)(iVar5 + 0x7c),(int)(short)(sVar2 + 3000));
    SComponent::cLib_chaseS(iVar9 + 0x80,(int)*(short *)(iVar5 + 0x80),0xf);
    SComponent::cLib_chaseS(iVar9 + 0x84,(int)*(short *)(iVar5 + 0x84),0xf);
    local_78 = (double)CONCAT44(0x43300000,(int)*(short *)(iVar9 + 0x80) ^ 0x80000000);
    dVar1 = dVar14 + (double)((float)(local_78 - dVar15) *
                             JKernel::JMath::jmaCosTable
                             [(int)((int)*(short *)(iVar9 + 0x78) & 0xffffU) >>
                              (JKernel::JMath::jmaSinShift & 0x3f)]);
    dVar14 = (double)(float)dVar1;
    local_70 = (double)CONCAT44(0x43300000,(int)*(short *)(iVar9 + 0x84) ^ 0x80000000);
    dVar13 = (double)(float)(dVar13 + (double)((float)(local_70 - dVar15) *
                                              (float)(dVar12 + (double)JKernel::JMath::jmaCosTable
                                                                       [(int)((int)*(short *)(iVar9 
                                                  + 0x7c) & 0xffffU) >>
                                                  (JKernel::JMath::jmaSinShift & 0x3f)])));
    iVar8 = iVar8 + 1;
    iVar7 = iVar7 + 2;
    iVar6 = iVar6 + 0xc;
  } while (iVar8 < 2);
  m_Do_mtx::mDoMtx_YrotS(this,(int)(short)((short)(int)dVar1 + *(short *)&this->field_0x66));
  m_Do_mtx::mDoMtx_XrotM((MTX34 *)this,(short)(int)dVar13);
  m_Do_mtx::mDoMtx_YrotM((MTX34 *)this,-*(short *)&this->field_0x66);
  if (0 < this->field_0x64) {
    this->field_0x64 = this->field_0x64 + -1;
  }
  __psq_l0(auStack8,uVar11);
  __psq_l1(auStack8,uVar11);
  __psq_l0(auStack24,uVar11);
  __psq_l1(auStack24,uVar11);
  __psq_l0(auStack40,uVar11);
  __psq_l1(auStack40,uVar11);
  __psq_l0(auStack56,uVar11);
  __psq_l1(auStack56,uVar11);
  return;
}


/* __thiscall Unit_c::Unit_c(void) */

void __thiscall Unit_c::Unit_c(Unit_c *this)

{
  *(undefined4 *)&this->field_0xdc = J3DGraphBase::j3dDefaultLightInfo;
  *(undefined4 *)&this->field_0xe0 = DAT_80370d1c;
  *(undefined4 *)&this->field_0xe4 = DAT_80370d20;
  *(undefined4 *)&this->field_0xe8 = DAT_80370d24;
  *(undefined4 *)&this->field_0xec = DAT_80370d28;
  *(undefined4 *)&this->field_0xf0 = DAT_80370d2c;
  *(undefined *)&this->field_0xf4 = DAT_80370d30;
  *(undefined *)&this->field_0xf5 = DAT_80370d31;
  *(undefined *)&this->field_0xf6 = DAT_80370d32;
  *(undefined *)&this->field_0xf7 = DAT_80370d33;
  *(undefined4 *)&this->field_0xf8 = DAT_80370d34;
  *(undefined4 *)&this->field_0xfc = DAT_80370d38;
  *(undefined4 *)&this->field_0x100 = DAT_80370d3c;
  *(undefined4 *)&this->field_0x104 = DAT_80370d40;
  *(undefined4 *)&this->field_0x108 = DAT_80370d44;
  *(undefined4 *)&this->field_0x10c = DAT_80370d48;
  clear(this);
  return;
}


/* WARNING: Inlined function: FUN_80328f20 */
/* WARNING: Inlined function: FUN_80328f6c */
/* WARNING: Removing unreachable block (ram,0x800be91c) */
/* __thiscall Unit_c::set_ground(void) */

undefined4 __thiscall Unit_c::set_ground(Unit_c *this)

{
  cM3dGPla *pcVar1;
  undefined4 uVar2;
  cBgS_PolyPassChk *pcVar3;
  undefined4 uVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  undefined8 in_f31;
  cBgS_GndChk local_9c;
  cBgS_PolyPassChk local_5c;
  undefined local_50 [20];
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  local_9c.mPos.z = (this->mPos).z;
  local_9c.mPos.y = d_wood::_4620 + (this->mPos).y;
  local_9c.mPos.x = (this->mPos).x;
  ::cBgS_GndChk::cBgS_GndChk(&local_9c);
  pcVar3 = &local_5c;
  local_5c.mbCamThrough = 0;
  local_5c.mbLinkThrough = 0;
  local_5c.mbArrowsAndLightThrough = 0;
  local_5c.mbBombThrough = 0;
  local_5c.mbBoomerangThrough = 0;
  local_5c.mbHookshotThrough = 0;
  local_50._4_4_ = 1;
  local_9c.parent.mpGrpPassChk = (cBgS_GrpPassChk *)pcVar3;
  if (pcVar3 != (cBgS_PolyPassChk *)0x0) {
    local_9c.parent.mpGrpPassChk = (cBgS_GrpPassChk *)local_50;
  }
  local_9c.parent.vtbl = &::dBgS_ObjGndChk::__vt;
  local_9c.mPolyInfo.vtbl = &cBgS_PolyInfo__vtbl_80371ed8;
  local_5c.vtbl = &cBgS_PolyPassChk__vtbl_80371ee4;
  local_50._0_4_ = &cBgS_GrpPassChk__vtbl_80371ef0;
  local_5c.mbObjThrough = 1;
  local_9c.parent.mpPolyPassChk = pcVar3;
  dVar7 = (double)cBgS::GroundCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,&local_9c);
  if (dVar7 <= (double)d_wood::_4621) {
    local_5c.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
    local_50._0_4_ = (cBgS_GrpPassChk__vtbl *)&PTR_80371f20;
    if (pcVar3 != (cBgS_PolyPassChk *)0x0) {
      local_5c.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
      local_50._0_4_ = (cBgS_GrpPassChk__vtbl *)&PTR_80371f68;
      if (((undefined *)register0x00000004 != (undefined *)0x50) &&
         (local_50._0_4_ = (cBgS_GrpPassChk__vtbl *)&::dBgS_GrpPassChk::__vt,
         (undefined *)register0x00000004 != (undefined *)0x50)) {
        local_50._0_4_ = (cBgS_GrpPassChk__vtbl *)&::cBgS_GrpPassChk::__vt;
      }
      if ((pcVar3 != (cBgS_PolyPassChk *)0x0) &&
         (local_5c.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
         pcVar3 != (cBgS_PolyPassChk *)0x0)) {
        local_5c.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
      }
    }
    local_9c.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_GndChk::__vt;
    local_9c.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
    cBgS_Chk::_cBgS_Chk(&local_9c.parent);
    uVar2 = 0;
  }
  else {
    (this->mPos).y = (float)dVar7;
    pcVar1 = cBgS::GetTriPla((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                             (uint)(ushort)local_9c.mPolyInfo.mBgIndex,
                             (uint)(ushort)local_9c.mPolyInfo.mTriIdx);
    mDoMtx_stack_c::now.m[0][1] = (pcVar1->mNorm).x;
    mDoMtx_stack_c::now.m[1][1] = (pcVar1->mNorm).y;
    mDoMtx_stack_c::now.m[2][1] = (pcVar1->mNorm).z;
    dVar8 = (double)(d_wood::_4325 - mDoMtx_stack_c::now.m[0][1] * mDoMtx_stack_c::now.m[0][1]);
    if ((double)d_wood::_4183 < dVar8) {
      dVar5 = 1.0 / SQRT(dVar8);
      dVar5 = d_wood::_4622 * dVar5 * (d_wood::_4623 - dVar8 * dVar5 * dVar5);
      dVar5 = d_wood::_4622 * dVar5 * (d_wood::_4623 - dVar8 * dVar5 * dVar5);
      dVar8 = (double)(float)(dVar8 * d_wood::_4622 * dVar5 *
                                      (d_wood::_4623 - dVar8 * dVar5 * dVar5));
    }
    dVar6 = (double)d_wood::_4183;
    dVar5 = dVar6;
    if (dVar6 != dVar8) {
      dVar6 = (double)(float)((double)mDoMtx_stack_c::now.m[1][1] * dVar8);
      dVar5 = (double)(float)(-(double)mDoMtx_stack_c::now.m[2][1] * dVar8);
    }
    mDoMtx_stack_c::now.m[0][0] = (float)dVar8;
    mDoMtx_stack_c::now.m[0][2] = d_wood::_4183;
    mDoMtx_stack_c::now.m[0][3] = (this->mPos).x;
    mDoMtx_stack_c::now.m[1][0] = (float)(-(double)mDoMtx_stack_c::now.m[0][1] * dVar6);
    mDoMtx_stack_c::now.m[1][2] = (float)dVar5;
    mDoMtx_stack_c::now.m[1][3] = (float)((double)d_wood::_4325 + dVar7);
    mDoMtx_stack_c::now.m[2][0] = (float)((double)mDoMtx_stack_c::now.m[0][1] * dVar5);
    mDoMtx_stack_c::now.m[2][2] = (float)dVar6;
    mDoMtx_stack_c::now.m[2][3] = (this->mPos).z;
    mDoMtx_stack_c::scaleM(DAT_80359fac,d_wood::_4325,DAT_80359fac);
    mtx::PSMTXCopy(&mDoMtx_stack_c::now,&this->field_0x78);
    local_5c.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
    local_50._0_4_ = (cBgS_GrpPassChk__vtbl *)&PTR_80371f20;
    if (pcVar3 != (cBgS_PolyPassChk *)0x0) {
      local_5c.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
      local_50._0_4_ = (cBgS_GrpPassChk__vtbl *)&PTR_80371f68;
      if (((undefined *)register0x00000004 != (undefined *)0x50) &&
         (local_50._0_4_ = (cBgS_GrpPassChk__vtbl *)&::dBgS_GrpPassChk::__vt,
         (undefined *)register0x00000004 != (undefined *)0x50)) {
        local_50._0_4_ = (cBgS_GrpPassChk__vtbl *)&::cBgS_GrpPassChk::__vt;
      }
      if ((pcVar3 != (cBgS_PolyPassChk *)0x0) &&
         (local_5c.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
         pcVar3 != (cBgS_PolyPassChk *)0x0)) {
        local_5c.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
      }
    }
    local_9c.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_GndChk::__vt;
    local_9c.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&PTR_80371e90;
    if ((undefined *)register0x00000004 != (undefined *)0x88) {
      local_9c.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
    }
    cBgS_Chk::_cBgS_Chk(&local_9c.parent);
    uVar2 = 1;
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall Unit_c::set_mtx(Anm_c *) */

void __thiscall Unit_c::set_mtx(Unit_c *this,Anm_c *param_1)

{
  int iVar1;
  
  iVar1 = this->mAnmIdx;
  mtx::PSMTXCopy((MTX34 *)(param_1 + iVar1),&mDoMtx_stack_c::now);
  mDoMtx_stack_c::now.m[0][3] = mDoMtx_stack_c::now.m[0][3] + (this->mPos).x;
  mDoMtx_stack_c::now.m[1][3] = mDoMtx_stack_c::now.m[1][3] + (this->mPos).y;
  mDoMtx_stack_c::now.m[2][3] = mDoMtx_stack_c::now.m[2][3] + (this->mPos).z;
  mtx::PSMTXConcat(&J3DGraphBase::j3dSys.mCurViewMtx,&mDoMtx_stack_c::now,&this->field_0x18);
  mtx::PSMTXCopy((MTX34 *)&param_1[iVar1].field_0x30,&mDoMtx_stack_c::now);
  mDoMtx_stack_c::now.m[0][3] = (this->mPos).x;
  mDoMtx_stack_c::now.m[1][3] = (this->mPos).y;
  mDoMtx_stack_c::now.m[2][3] = (this->mPos).z;
  mtx::PSMTXConcat(&J3DGraphBase::j3dSys.mCurViewMtx,&mDoMtx_stack_c::now,&this->field_0x48);
  mtx::PSMTXConcat(&J3DGraphBase::j3dSys.mCurViewMtx,&this->field_0x78,&this->field_0xa8);
  return;
}


/* __thiscall Unit_c::clear(void) */

void __thiscall Unit_c::clear(Unit_c *this)

{
  SComponent::cLib_memSet(this,0,0x18c);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x800bee7c) */
/* __thiscall Unit_c::cc_hit_before_cut(Packet_c *) */

void __thiscall Unit_c::cc_hit_before_cut(Unit_c *this,Packet_c *param_1)

{
  uint uVar1;
  cCcD_Obj__DamageTypes cVar2;
  int iVar3;
  short sVar4;
  int iVar5;
  undefined4 uVar6;
  undefined8 in_f31;
  double dVar7;
  fopAc_ac_c *local_48;
  dCcMassS_HitInf dStack68;
  undefined auStack8 [8];
  
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  dStack68.vtbl = (undefined *)&dCcMassS_HitInf::__vt;
  uVar1 = dCcMassS_Mng::Chk(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.mMassMng,&this->mPos,
                            &local_48,&dStack68);
  if (0 < *(short *)&this->field_0xc) {
    *(short *)&this->field_0xc = *(short *)&this->field_0xc + -1;
  }
  if ((((uVar1 & 1) != 0) && (dStack68.mpAtObj != (cCcD_Obj *)0x0)) &&
     ((((cVar2 = ((dStack68.mpAtObj)->parent).mObjAt.mDamageTypes, (cVar2 & DekuLeafWind) != 0 ||
        (((((cVar2 & Bomb) != 0 || ((cVar2 & Fire) != 0)) || ((cVar2 & NormalArrow) != 0)) ||
         (((cVar2 & FireArrows) != 0 || ((cVar2 & IceArrows) != 0)))))) ||
       (((cVar2 & LightArrow) != 0 || ((cVar2 & 0x8000) != 0)))) &&
      ((uVar1 = uVar1 & 0xfffffffe, local_48 != (fopAc_ac_c *)0x0 &&
       (*(short *)&this->field_0xc == 0)))))) {
    iVar3 = Packet_c::search_anm(param_1,1);
    *(undefined2 *)&this->field_0xc = 0x14;
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x6932,&this->mPos,0,0,d_wood::_4325,d_wood::_4325,
               d_wood::_4876,d_wood::_4876,0);
    iVar5 = this->mAnmIdx;
    if ((iVar5 < 8) && (iVar3 != -1)) {
      this->mAnmIdx = iVar3;
    }
    if ((7 < this->mAnmIdx) && (0 < param_1->mAnm[this->mAnmIdx].field_0x60)) {
      sVar4 = SComponent::cLib_targetAngleY(&(local_48->mCurrent).mPos,&this->mPos);
      Anm_c::mode_push_into_init(param_1->mAnm + this->mAnmIdx,param_1->mAnm + iVar5,sVar4);
    }
  }
  if (((((uVar1 & 2) != 0) && (local_48 != (fopAc_ac_c *)0x0)) &&
      (dStack68.mpCoObj != (cCcD_Obj *)0x0)) &&
     ((((dStack68.mpCoObj)->mpStts != (dCcD_Stts *)0x0 &&
       (iVar3 = Packet_c::search_anm(param_1,1), (local_48->parent).parent.mBsTypeId == 0xa9)) &&
      ((d_wood::_4877 <= dStack68.field_0xc && (*(short *)&this->field_0xc == 0)))))) {
    *(undefined2 *)&this->field_0xc = 0x14;
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x6932,&this->mPos,0,0,d_wood::_4325,d_wood::_4325,
               d_wood::_4876,d_wood::_4876,0);
    iVar5 = this->mAnmIdx;
    if ((iVar5 < 8) && (iVar3 != -1)) {
      this->mAnmIdx = iVar3;
    }
    if ((7 < this->mAnmIdx) && (0 < param_1->mAnm[this->mAnmIdx].field_0x60)) {
      sVar4 = SComponent::cLib_targetAngleY(&(local_48->mCurrent).mPos,&this->mPos);
      Anm_c::mode_push_into_init(param_1->mAnm + this->mAnmIdx,param_1->mAnm + iVar5,sVar4);
    }
  }
  if ((uVar1 & 1) != 0) {
    iVar3 = this->mAnmIdx;
    if ((iVar3 < 8) && (iVar5 = Packet_c::search_anm(param_1,0), iVar5 != -1)) {
      this->mAnmIdx = iVar5;
    }
    if ((7 < this->mAnmIdx) && (0 < param_1->mAnm[this->mAnmIdx].field_0x60)) {
      sVar4 = SComponent::cLib_targetAngleY(&(local_48->mCurrent).mPos,&this->mPos);
      Anm_c::mode_cut_init(param_1->mAnm + this->mAnmIdx,param_1->mAnm + iVar3,sVar4);
      dScnKy_env_light_c::settingTevStruct
                (&d_kankyo::g_env_light,BG0,&this->mPos,(dKy_tevstr_c *)&this->field_0xdc);
      dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0x3e0,&this->mPos,
                         (csXyz *)0x0,(cXyz *)0x0,0xff,(dPa_levelEcallBack *)0x0,-1,
                         (_GXColor *)&this->field_0x164,(_GXColor *)0x0,(cXyz *)0x0);
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x69d1,&this->mPos,0,0,d_wood::_4325,d_wood::_4325,
                 d_wood::_4876,d_wood::_4876,0);
      dVar7 = (double)(DAT_80359fb0 / DAT_80359fac);
      mtx::PSMTXCopy(&this->field_0x78,&mDoMtx_stack_c::now);
      mDoMtx_stack_c::scaleM((float)dVar7,d_wood::_4325,(float)dVar7);
      mtx::PSMTXCopy(&mDoMtx_stack_c::now,&this->field_0x78);
    }
  }
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  return;
}


/* __thiscall Unit_c::cc_hit_after_cut(Packet_c *) */

void __thiscall Unit_c::cc_hit_after_cut(Unit_c *this,Packet_c *param_1)

{
  return;
}


/* __thiscall Unit_c::proc(Packet_c *) */

void __thiscall Unit_c::proc(Unit_c *this,Packet_c *param_1)

{
  int iVar1;
  Anm_c *pAVar2;
  
  if (((this->mFlags & 1) != 0) && (7 < this->mAnmIdx)) {
    pAVar2 = param_1->mAnm + this->mAnmIdx;
    iVar1 = pAVar2->field_0x60;
    if (iVar1 == 5) {
      if (pAVar2->field_0x64 < 1) {
        this->mAnmIdx = (int)*(short *)&pAVar2->field_0x88;
        pAVar2->field_0x60 = 6;
      }
    }
    else {
      if (iVar1 == 0) {
        if (pAVar2->field_0x64 < 1) {
          iVar1 = Packet_c::search_anm(param_1,4);
          this->mAnmIdx = iVar1;
          pAVar2->field_0x60 = 6;
          this->mFlags = this->mFlags | 4;
        }
      }
      else {
        if (iVar1 == 6) {
          iVar1 = Packet_c::search_anm(param_1,4);
          this->mAnmIdx = iVar1;
        }
      }
    }
  }
  return;
}


/* __thiscall Room_c::Room_c(void) */

void __thiscall Room_c::Room_c(Room_c *this)

{
  this->mpUnit = (Unit_c *)0x0;
  return;
}


/* __thiscall Room_c::entry_unit(Unit_c *) */

void __thiscall Room_c::entry_unit(Room_c *this,Unit_c *param_1)

{
  param_1->mpNext = this->mpUnit;
  this->mpUnit = param_1;
  return;
}


/* __thiscall Room_c::delete_all_unit(void) */

void __thiscall Room_c::delete_all_unit(Room_c *this)

{
  Unit_c *this_00;
  
  while (this_00 = this->mpUnit, this_00 != (Unit_c *)0x0) {
    this->mpUnit = this_00->mpNext;
    JAIZelBasic::seDeleteObject(JAIZelBasic::zel_basic,(Vec *)this_00);
    Unit_c::clear(this_00);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall Packet_c::Packet_c(void) */

void __thiscall Packet_c::Packet_c(Packet_c *this)

{
  int iVar1;
  int iVar2;
  
  (this->parent).vtbl = (undefined *)&J3DPacket::__vt;
  (this->parent).mpNextSibling = (J3DPacket *)0x0;
  (this->parent).mpFirstChild = (J3DPacket *)0x0;
  (this->parent).field_0xc = (undefined *)0x0;
  (this->parent).vtbl = &__vt;
  Runtime.PPCEABI.H::__construct_array(this->mUnit,Unit_c::Unit_c,Unit_c::_Unit_c,0x18c,200);
  Runtime.PPCEABI.H::__construct_array(this->mAnm,Anm_c::Anm_c,(undefined *)0x0,0x8c,0x48);
  Runtime.PPCEABI.H::__construct_array(this->mRoom,Room_c::Room_c,(undefined *)0x0,4,0x40);
  iVar1 = 0;
  iVar2 = 0;
  do {
    Anm_c::mode_norm_init((Anm_c *)(&this->mAnm[0].field_0x0 + iVar2));
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x8c;
  } while (iVar1 < 8);
  return;
}


/* __thiscall Unit_c::~Unit_c(void) */

void __thiscall Unit_c::_Unit_c(Unit_c *this)

{
  short in_r4;
  
  if ((this != (Unit_c *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall Packet_c::~Packet_c(void) */

void __thiscall Packet_c::_Packet_c(Packet_c *this)

{
  short in_r4;
  
  if (this != (Packet_c *)0x0) {
    (this->parent).vtbl = &__vt;
    Runtime.PPCEABI.H::__destroy_arr(this->mUnit,Unit_c::_Unit_c,0x18c,200);
    if (this != (Packet_c *)0x0) {
      (this->parent).vtbl = (undefined *)&J3DPacket::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall Packet_c::delete_room(int) */

void __thiscall Packet_c::delete_room(Packet_c *this,int param_1)

{
  Room_c::delete_all_unit(this->mRoom + param_1);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall Packet_c::put_unit(cXyz const &,
                                        int) */

int __thiscall Packet_c::put_unit(Packet_c *this,cXyz *pPos,int room_no)

{
  bool bVar1;
  ulong uVar2;
  int iVar3;
  int iVar4;
  char cVar5;
  Unit_c *this_00;
  
  bVar1 = false;
  if ((-1 < room_no) && (room_no < 0x40)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_wood.cpp",0x6e0,"(room_no >= 0) && (room_no < L_Room_Max)");
    m_Do_printf::OSPanic("d_wood.cpp",0x6e0,&DAT_8035a010);
  }
  iVar3 = search_empty_UnitID(this);
  if (iVar3 != 200) {
    this_00 = this->mUnit + iVar3;
    this_00->mFlags = 1;
    (this_00->mPos).x = pPos->x;
    (this_00->mPos).y = pPos->y;
    (this_00->mPos).z = pPos->z;
    iVar4 = search_anm(this,4);
    this_00->mAnmIdx = iVar4;
    cVar5 = Unit_c::set_ground(this_00);
    if (cVar5 == '\0') {
      Unit_c::clear(this_00);
    }
    else {
      Room_c::entry_unit(this->mRoom + room_no,this_00);
    }
  }
  return iVar3;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x800bf3e4) */
/* __thiscall Packet_c::calc_cc(void) */

void __thiscall Packet_c::calc_cc(Packet_c *this)

{
  Unit_c *pUVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 in_f31;
  double dVar4;
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  iVar2 = (int)(char)dStage_roomControl_c::mStayNo;
  if ((-1 < iVar2) && (iVar2 < 0x40)) {
    dVar4 = (double)DAT_80359fbc;
    ::cM3dGCyl::SetR(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.mMassMng.mCylAttr.mCyl,
                     DAT_80359fb4);
    ::cM3dGCyl::SetH(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.mMassMng.mCylAttr.mCyl,
                     (float)dVar4);
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.mMassMng.mChkFlag = 0x13;
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.mMassMng.mResultCamBit = 1;
    for (pUVar1 = this->mRoom[iVar2].mpUnit; pUVar1 != (Unit_c *)0x0; pUVar1 = pUVar1->mpNext) {
      if ((pUVar1->mFlags & 4) == 0) {
        Unit_c::cc_hit_before_cut(pUVar1,this);
      }
    }
    dVar4 = (double)DAT_80359fc0;
    ::cM3dGCyl::SetR(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.mMassMng.mCylAttr.mCyl,
                     DAT_80359fb8);
    ::cM3dGCyl::SetH(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.mMassMng.mCylAttr.mCyl,
                     (float)dVar4);
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.mMassMng.mChkFlag = 0x12;
    d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.mMassMng.mResultCamBit = 1;
    for (pUVar1 = this->mRoom[iVar2].mpUnit; pUVar1 != (Unit_c *)0x0; pUVar1 = pUVar1->mpNext) {
      if ((pUVar1->mFlags & 4) != 0) {
        Unit_c::cc_hit_after_cut(pUVar1,this);
      }
    }
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x800bf4cc) */
/* __thiscall Packet_c::calc(void) */

void __thiscall Packet_c::calc(Packet_c *this)

{
  cXyz *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  double dVar6;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  calc_cc(this);
  pcVar1 = d_kankyo_wether::dKyw_get_wind_vec();
  dVar6 = d_kankyo_wether::dKyw_get_wind_pow();
  iVar2 = SComponent::cM_atan2s(pcVar1->x,pcVar1->z);
  iVar3 = 0;
  iVar4 = 0;
  do {
    Anm_c::mode_norm_set_wind((Anm_c *)(&this->mAnm[0].field_0x0 + iVar4),(float)dVar6,(short)iVar2)
    ;
    iVar3 = iVar3 + 1;
    iVar4 = iVar4 + 0x8c;
  } while (iVar3 < 8);
  iVar2 = 0;
  iVar3 = 0;
  do {
    Anm_c::play((Anm_c *)(&this->mAnm[0].field_0x0 + iVar3),this);
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 0x8c;
  } while (iVar2 < 0x48);
  iVar2 = 0;
  iVar3 = 0;
  do {
    Unit_c::proc((Unit_c *)((int)&this->mUnit[0].mPos.x + iVar3),this);
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 0x18c;
  } while (iVar2 < 200);
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall Packet_c::update(void) */

void __thiscall Packet_c::update(Packet_c *this)

{
  uint uVar1;
  Unit_c *this_00;
  int iVar2;
  cXyz local_2c;
  float local_20;
  float local_1c;
  float local_18;
  
  iVar2 = 0;
  this_00 = this->mUnit;
  do {
    if ((this_00->mFlags & 1) != 0) {
      local_2c.z = (this_00->mPos).z;
      local_2c.y = (this_00->mPos).y + DAT_80359fc8;
      local_2c.x = (this_00->mPos).x;
      local_20 = local_2c.x;
      local_1c = local_2c.y;
      local_18 = local_2c.z;
      uVar1 = J3DUClipper::clip(&mDoLib_clipper::mClipper,&J3DGraphBase::j3dSys.mCurViewMtx,
                                &local_2c,FLOAT_80359fc4);
      if (uVar1 == 0) {
        this_00->mFlags = this_00->mFlags & 0xfffffffd;
        Unit_c::set_mtx(this_00,this->mAnm);
      }
      else {
        this_00->mFlags = this_00->mFlags | 2;
      }
    }
    iVar2 = iVar2 + 1;
    this_00 = this_00 + 1;
  } while (iVar2 < 200);
  J3DGraphBase::j3dSys.mpCurDrawBuffers[1] =
       d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufWorldXlu;
  J3DDrawBuffer::entryImm(J3DGraphBase::j3dSys.mpCurDrawBuffers[0],&this->parent,0);
  J3DGraphBase::j3dSys.mpCurDrawBuffers[1] =
       d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelXlu;
  return;
}


/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall Packet_c::draw(void) */

void __thiscall Packet_c::draw(Packet_c *this)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  Unit_c *pUnit;
  Room_c *pRVar5;
  int iVar6;
  int iVar7;
  _GXColor local_48;
  _GXColor local_44;
  _GXColor local_40;
  _GXColor local_3c;
  _GXColor local_38;
  _GXColor local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  gf::GFSetVtxDescv(&d_wood::l_shadowVtxDescList_5139);
  gf::GFSetVtxAttrFmtv(0,&d_wood::l_shadowVtxAttrFmtList_5140);
  gf::GFSetArray(GX_VA_POS,(int)&d_tree::g_dTree_shadowPos,3);
  gf::GFSetArray(GX_VA_TEX0,(int)&d_tree::g_dTree_shadowTexCoord,2);
  d_kankyo::dKy_GxFog_set();
  gx::GXCallDisplayList(&d_tree::g_dTree_shadowMatDL,d_tree::g_dTree_shadowMatDL_SIZE & 0xffffffe0);
  local_38 = d_wood::l_shadowColor_5141;
  gf::GFSetTevColor(GX_TEVREG0,&local_38);
  uVar4 = d_tree::g_dTree_Oba_kage_32DL_SIZE;
  iVar6 = 0;
  pRVar5 = this->mRoom;
  do {
    pUnit = pRVar5->mpUnit;
    while( true ) {
      if (pUnit == (Unit_c *)0x0) break;
      if ((pUnit->mFlags & 2) == 0) {
        gf::GFLoadPosMtxImm(&pUnit->field_0xa8,0);
        gx::GXCallDisplayList(&d_tree::g_dTree_Oba_kage_32DL,uVar4 & 0xffffffe0);
      }
      pUnit = pUnit->mpNext;
    }
    iVar6 = iVar6 + 1;
    pRVar5 = pRVar5 + 1;
  } while (iVar6 < 0x40);
  local_34 = d_wood::_5155;
  gf::GFSetVtxDescv(&d_wood::l_vtxDescList_5156);
  gf::GFSetVtxAttrFmtv(0,&d_wood::l_vtxAttrFmtList_5157);
  gf::GFSetArray(GX_VA_POS,(int)&@unnamed@d_wood_cpp@::l_pos,0xc);
  gf::GFSetArray(GX_VA_CLR0,(int)&@unnamed@d_wood_cpp@::l_color,4);
  gf::GFSetArray(GX_VA_TEX0,(int)&@unnamed@d_wood_cpp@::l_texCoord,8);
  gx::GXCallDisplayList(&@unnamed@d_wood_cpp@::l_matDL,0xa0);
  gf::GFSetAlphaCompare(4,DAT_80359fcd,1,4,DAT_80359fcd);
  local_3c = local_34;
  gf::GFSetTevColor(GX_TEVREG2,&local_3c);
  iVar7 = 0;
  iVar6 = 0;
  pRVar5 = this->mRoom;
  do {
    local_30 = *(undefined4 *)((int)&dStage_roomControl_c::mStatus[0].mTevStr.mColorC0.r + iVar6);
    local_2c = *(undefined4 *)((int)&dStage_roomControl_c::mStatus[0].mTevStr.mColorC0.b + iVar6);
    gf::GFSetTevColorS10(GX_TEVREG0,(_GXColorS10 *)&local_30);
    local_40 = *(_GXColor *)(&dStage_roomControl_c::mStatus[0].mTevStr.mColorK0.r + iVar6);
    gf::GFSetTevColor(GX_TEVREG1,&local_40);
    d_kankyo::dKy_GfFog_tevstr_set
              ((dKy_tevstr_c *)
               ((int)&dStage_roomControl_c::mStatus[0].mTevStr.mLightObj.mPos.x + iVar6));
    pUnit = pRVar5->mpUnit;
    while( true ) {
      if (pUnit == (Unit_c *)0x0) break;
      if ((pUnit->mFlags & 2) == 0) {
        if ((pUnit->mFlags & 4) == 0) {
          bVar1 = this->mAnm[pUnit->mAnmIdx].field_0x8a;
          local_34 = (_GXColor)((uint)local_34 & 0xffffff00 | (uint)bVar1);
          iVar2 = -(uint)bVar1;
          iVar3 = iVar2 + 0xff;
          uVar4 = iVar3 - ((uint)(iVar3 == 0) + iVar2 + 0xfe);
          if ((uVar4 & 0xff) != 0) {
            gf::GFSetAlphaCompare(4,0,1,4,0);
          }
          local_44 = local_34;
          gf::GFSetTevColor(GX_TEVREG2,&local_44);
          gf::GFLoadPosMtxImm(&pUnit->field_0x18,0);
          gx::GXCallDisplayList(&@unnamed@d_wood_cpp@::l_Oba_swood_bDL,0x100);
          if ((uVar4 & 0xff) != 0) {
            gf::GFSetAlphaCompare(4,DAT_80359fcd,1,4,DAT_80359fcd);
          }
          local_34 = (_GXColor)CONCAT31(local_34._0_3_,0xff);
          local_48 = local_34;
          gf::GFSetTevColor(GX_TEVREG2,&local_48);
        }
        gf::GFLoadPosMtxImm(&pUnit->field_0x48,0);
        gx::GXCallDisplayList(&@unnamed@d_wood_cpp@::l_Oba_swood_b_cutDL,0xc0);
      }
      pUnit = pUnit->mpNext;
    }
    iVar7 = iVar7 + 1;
    iVar6 = iVar6 + 0x114;
    pRVar5 = pRVar5 + 1;
  } while (iVar7 < 0x40);
  _sOldVcdVatCmd = 0;
  return;
}


/* __thiscall Packet_c::search_empty_UnitID(void) const */

int __thiscall Packet_c::search_empty_UnitID(Packet_c *this)

{
  Unit_c *pUVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  pUVar1 = this->mUnit;
  iVar3 = 200;
  do {
    if (pUVar1->mFlags == 0) {
      return iVar2;
    }
    iVar2 = iVar2 + 1;
    pUVar1 = pUVar1 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return 200;
}


/* __thiscall Packet_c::search_anm(Anm_c::Mode_e) */

int __thiscall Packet_c::search_anm(Packet_c *this,Mode_e param_1)

{
  bool bVar1;
  ulong uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  bVar1 = false;
  if ((-1 < (int)param_1) && ((int)param_1 < 6)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_wood.cpp",0x80d,"(i_mode >= 0) && (i_mode < Anm_c::Mode_Max)")
    ;
    m_Do_printf::OSPanic("d_wood.cpp",0x80d,&DAT_8035a010);
  }
  if (param_1 == 4) {
    if (d_wood::init_5227 == '\0') {
      d_wood::anm_norm_num_5226 = 0;
      d_wood::init_5227 = '\x01';
    }
    iVar4 = d_wood::anm_norm_num_5226 + 1 >> 0x1f;
    iVar3 = d_wood::anm_norm_num_5226;
    d_wood::anm_norm_num_5226 =
         (iVar4 * 8 | (uint)((d_wood::anm_norm_num_5226 + 1) * 0x20000000 + iVar4) >> 0x1d) - iVar4;
  }
  else {
    iVar3 = 8;
    iVar4 = 0x460;
    iVar5 = 0x40;
    do {
      if (*(int *)((int)&this->mAnm[0].field_0x60 + iVar4) == 6) {
        return iVar3;
      }
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x8c;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    iVar3 = 8;
    iVar4 = 0x460;
    iVar5 = 0x40;
    do {
      if ((int)param_1 < *(int *)((int)&this->mAnm[0].field_0x60 + iVar4)) {
        return iVar3;
      }
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x8c;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    iVar3 = -1;
  }
  return iVar3;
}

}

namespace d_wood {

void __sinit_d_wood_cpp(void)

{
  DAT_8037fbb1 = 1;
  DAT_8037fbb2 = 0xbf;
  DAT_8037fbb3 = 0x70;
  return;
}

