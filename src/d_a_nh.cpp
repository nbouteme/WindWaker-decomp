#include <d_a_nh.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <m_Do_hostIO.h>
#include <d_cc_d.h>
#include <d_bg_s_acch.h>
#include <f_op_actor.h>
#include <JKernel/JKRHeap.h>
#include <mtx/mtx.h>
#include <m_Do_mtx.h>
#include <mtx/mtxvec.h>
#include <d_resorce.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <m_Do_ext.h>
#include <d_a_nh.h>
#include <f_op_actor_mng.h>
#include <Runtime.PPCEABI.H/ptmf.h>
#include <d_attention.h>
#include <SComponent/c_xyz.h>
#include <mtx/vec.h>
#include <SComponent/c_lib.h>
#include <SComponent/c_bg_s_gnd_chk.h>
#include <SComponent/c_bg_s.h>
#include <d_bg_s.h>
#include <SComponent/c_bg_s_chk.h>
#include <d_a_arrow.h>
#include <m_Do_audio.h>
#include <MSL_C.PPCEABI.bare.H/arith.h>
#include <SComponent/c_m3d_g_cyl.h>
#include <SComponent/c_cc_s.h>
#include <d_kankyo.h>
#include <J3DGraphAnimator/J3DMaterialAttach.h>
#include <d_drawlist.h>
#include <SComponent/c_math.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <daNh_HIO_c.h>
#include <daNh_c.h>


namespace d_a_nh {
undefined l_HIO;
undefined4 a_heap_size_tbl$4111;
undefined1 init$4112;
}

/* __thiscall daNh_HIO_c::daNh_HIO_c(void) */

void __thiscall daNh_HIO_c::daNh_HIO_c(daNh_HIO_c *this)

{
  *(undefined **)this = &__vt;
  this[4] = (daNh_HIO_c)0xff;
  *(undefined4 *)(this + 8) = d_a_nh::init_data_3995;
  *(undefined4 *)(this + 0xc) = DAT_8035bf84;
  *(undefined4 *)(this + 0x10) = DAT_8035bf88;
  *(undefined4 *)(this + 0x14) = DAT_8035bf8c;
  *(undefined4 *)(this + 0x18) = DAT_8035bf90;
  *(undefined4 *)(this + 0x1c) = DAT_8035bf94;
  *(undefined4 *)(this + 0x20) = DAT_8035bf98;
  *(undefined4 *)(this + 0x24) = DAT_8035bf9c;
  *(undefined4 *)(this + 0x28) = DAT_8035bfa0;
  *(undefined4 *)(this + 0x2c) = DAT_8035bfa4;
  *(undefined4 *)(this + 0x30) = DAT_8035bfa8;
  *(undefined4 *)(this + 0x34) = DAT_8035bfac;
  *(undefined4 *)(this + 0x38) = DAT_8035bfb0;
  *(undefined2 *)(this + 0x3c) = DAT_8035bfb4;
  *(undefined2 *)(this + 0x3e) = DAT_8035bfb6;
  *(undefined2 *)(this + 0x40) = DAT_8035bfb8;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall daNh_c::~daNh_c(void) */

void __thiscall daNh_c::_daNh_c(daNh_c *this)

{
  short in_r4;
  
  if (this != (daNh_c *)0x0) {
    if (-1 < DAT_803e4248) {
      mDoHIO_subRoot_c::deleteChild(&mDoHIO_subRoot_c_803a5778,DAT_803e4248);
      DAT_803e4248 = -1;
    }
    if (this != (daNh_c *)0xfffff9d0) {
      *(undefined ***)(this + 0x63c) = &::cBgS_PolyInfo::__vt;
    }
    if (this != (daNh_c *)0xfffff9f4) {
      *(undefined ***)(this + 0x60c) = &::mDoExt_brkAnm::__vt;
      if (this != (daNh_c *)0xfffff9f4) {
        *(undefined ***)(this + 0x60c) = &::mDoExt_baseAnm::__vt;
      }
    }
    if (this != (daNh_c *)0xfffffb24) {
      *(dCcD_Cyl__vtbl **)(this + 0x518) = &::dCcD_Cyl::__vt;
      *(undefined4 *)(this + 0x5f0) = 0x8038af30;
      *(undefined4 *)(this + 0x608) = 0x8038af84;
      if (this != (daNh_c *)0xfffffa2c) {
        *(cCcD_ShapeAttr__vtbl **)(this + 0x5f0) = &::cCcD_CylAttr::__vt;
        *(cCcD_CylAttr__vtbl **)(this + 0x608) = &cCcD_CylAttr__vtbl_803951ac;
        if (this != (daNh_c *)0xfffffa0c) {
          *(undefined ***)(this + 0x608) = &::cM3dGCyl::__vt;
        }
        if (this != (daNh_c *)0xfffffa2c) {
          *(undefined ***)(this + 0x5f0) = &::cCcD_ShapeAttr::__vt;
          if (this != (daNh_c *)0xfffffa2c) {
            *(cM3dGAab__vtbl **)(this + 0x5ec) = &::cM3dGAab::__vt;
          }
        }
      }
      dCcD_GObjInf::_dCcD_GObjInf((dCcD_GObjInf *)(this + 0x4dc));
    }
    if (this != (daNh_c *)0xfffffb60) {
      *(dCcD_Stts__vtbl **)(this + 0x4b8) = &::dCcD_Stts::__vt;
      *(undefined4 *)(this + 0x4bc) = 0x8037ec40;
      if (this != (daNh_c *)0xfffffb44) {
        *(undefined ***)(this + 0x4bc) = &::dCcD_GStts::__vt;
        if (this != (daNh_c *)0xfffffb44) {
          *(undefined ***)(this + 0x4bc) = &::cCcD_GStts::__vt;
        }
      }
      if (this != (daNh_c *)0xfffffb60) {
        *(cCcD_Stts__vtbl **)(this + 0x4b8) = &cCcD_Stts::__vt;
      }
    }
    if (this != (daNh_c *)0xfffffba0) {
      *(undefined ***)(this + 0x46c) = &::dBgS_AcchCir::__vt;
      if (this != (daNh_c *)0xfffffb8c) {
        *(undefined ***)(this + 0x480) = &::cM3dGCir::__vt;
        if (this != (daNh_c *)0xfffffb8c) {
          *(undefined ***)(this + 0x480) = &::cM2dGCir::__vt;
        }
      }
      if (this != (daNh_c *)0xfffffba0) {
        *(undefined ***)(this + 0x46c) = &::cBgS_PolyInfo::__vt;
      }
    }
    if (this != (daNh_c *)0xfffffd64) {
      *(dBgS_ObjAcch__vtbl **)(this + 0x2ac) = &::dBgS_ObjAcch::__vt;
      *(undefined4 *)(this + 0x2b0) = 0x8037e9e4;
      *(undefined4 *)(this + 700) = 0x8037e9f0;
      dBgS_Acch::_dBgS_Acch((dBgS_Acch *)(this + 0x29c));
    }
    fopAc_ac_c::_fopAc_ac_c((fopAc_ac_c *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall daNh_c::setBaseMtx(void) */

void __thiscall daNh_c::setBaseMtx(daNh_c *this)

{
  undefined4 uVar1;
  int iVar2;
  cXyz local_28;
  cXyz local_1c;
  
  uVar1 = DAT_803e427c;
  iVar2 = *(int *)(this + 0x298);
  *(undefined4 *)(this + 0x214) = DAT_803e427c;
  *(undefined4 *)(this + 0x218) = uVar1;
  *(undefined4 *)(this + 0x21c) = uVar1;
  *(undefined4 *)(iVar2 + 0x18) = *(undefined4 *)(this + 0x214);
  *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)(this + 0x218);
  *(undefined4 *)(iVar2 + 0x20) = *(undefined4 *)(this + 0x21c);
  mtx::PSMTXTrans((double)*(float *)(this + 0x1f8),(double)*(float *)(this + 0x1fc),
                  (double)*(float *)(this + 0x200),&mDoMtx_stack_c::now);
  m_Do_mtx::mDoMtx_YrotM(&mDoMtx_stack_c::now,*(short *)(this + 0x20e));
  mtx::PSMTXCopy(&mDoMtx_stack_c::now,(MTX34 *)(iVar2 + 0x24));
  local_1c.z = d_a_nh::_4090;
  local_1c.x = d_a_nh::_4090;
  local_1c.y = DAT_803e4258;
  mtx::PSMTXMultVec(&mDoMtx_stack_c::now,&local_1c,&local_28);
  mtx::PSMTXTrans((double)local_28.x,(double)local_28.y,(double)local_28.z,&mDoMtx_stack_c::now);
  mDoMtx_stack_c::scaleM(DAT_803e425c,DAT_803e425c,DAT_803e425c);
  mtx::PSMTXCopy(&mDoMtx_stack_c::now,(MTX34 *)(this + 0x64c));
  return;
}


/* __thiscall daNh_c::createHeap(void) */

bool __thiscall daNh_c::createHeap(daNh_c *this)

{
  J3DModelData *pModel;
  ulong uVar1;
  J3DModel *pJVar2;
  int iVar3;
  bool bVar4;
  
  pModel = (J3DModelData *)
           dRes_control_c::getRes
                     ("Always",0x34,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
  if (pModel == (J3DModelData *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_a_nh.cpp",0x167,"modelData != 0");
    m_Do_printf::OSPanic("d_a_nh.cpp",0x167,&DAT_8035bfdd);
  }
  pJVar2 = m_Do_ext::mDoExt_J3DModel__create(pModel,0,0x11020203);
  *(J3DModel **)(this + 0x298) = pJVar2;
  if (*(int *)(this + 0x298) == 0) {
    bVar4 = false;
  }
  else {
    iVar3 = initBrkAnm(this,false);
    bVar4 = iVar3 != 0;
  }
  return bVar4;
}


namespace d_a_nh {

/* __stdcall checkCreateHeap(fopAc_ac_c *) */

void checkCreateHeap(daNh_c *param_1)

{
  ::daNh_c::createHeap(param_1);
  return;
}

}

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall daNh_c::create(void) */

undefined4 __thiscall daNh_c::create(daNh_c *this)

{
  uint uVar1;
  int iVar2;
  code *pcVar3;
  undefined4 uVar4;
  undefined5 uVar5;
  
  if (d_a_nh::init_4112 == '\0') {
    d_a_nh::a_heap_size_tbl_4111 = 0x4000;
    d_a_nh::init_4112 = '\x01';
  }
  uVar4 = 4;
  if ((*(uint *)(this + 0x1c8) & 8) == 0) {
    if (this != (daNh_c *)0x0) {
      fopAc_ac_c::fopAc_ac_c((fopAc_ac_c *)this);
      dBgS_Acch::dBgS_Acch((dBgS_Acch *)(this + 0x29c));
      *(dBgS_ObjAcch__vtbl **)(this + 0x2ac) = &::dBgS_ObjAcch::__vt;
      *(undefined4 *)(this + 0x2b0) = 0x8037e9e4;
      *(undefined4 *)(this + 700) = 0x8037e9f0;
      this[0x2b4] = (daNh_c)0x1;
      ::dBgS_AcchCir::dBgS_AcchCir((dBgS_AcchCir *)(this + 0x460));
      *(cCcD_Stts__vtbl **)(this + 0x4b8) = &cCcD_Stts::__vt;
      ::dCcD_GStts::dCcD_GStts((dCcD_GStts *)(this + 0x4bc));
      *(dCcD_Stts__vtbl **)(this + 0x4b8) = &::dCcD_Stts::__vt;
      *(undefined4 *)(this + 0x4bc) = 0x8037ec40;
      dCcD_GObjInf::dCcD_GObjInf((dCcD_GObjInf *)(this + 0x4dc));
      *(undefined ***)(this + 0x5f0) = &::cCcD_ShapeAttr::__vt;
      *(cM3dGAab__vtbl **)(this + 0x5ec) = &::cM3dGAab::__vt;
      *(undefined ***)(this + 0x608) = &::cM3dGCyl::__vt;
      *(cCcD_ShapeAttr__vtbl **)(this + 0x5f0) = &::cCcD_CylAttr::__vt;
      *(cCcD_CylAttr__vtbl **)(this + 0x608) = &cCcD_CylAttr__vtbl_803951ac;
      *(dCcD_Cyl__vtbl **)(this + 0x518) = &::dCcD_Cyl::__vt;
      *(undefined4 *)(this + 0x5f0) = 0x8038af30;
      *(undefined4 *)(this + 0x608) = 0x8038af84;
      *(undefined ***)(this + 0x60c) = &::mDoExt_baseAnm::__vt;
      *(undefined4 *)(this + 0x610) = 0;
      *(undefined ***)(this + 0x60c) = &::mDoExt_brkAnm::__vt;
      *(undefined4 *)(this + 0x618) = 0;
      *(undefined4 *)(this + 0x61c) = 0;
      *(undefined ***)(this + 0x63c) = &::cBgS_PolyInfo::__vt;
      *(undefined2 *)(this + 0x630) = 0xffff;
      *(undefined2 *)(this + 0x632) = 0x100;
      *(undefined4 *)(this + 0x634) = 0;
      *(undefined4 *)(this + 0x638) = 0xffffffff;
    }
    *(uint *)(this + 0x1c8) = *(uint *)(this + 0x1c8) | 8;
  }
  pcVar3 = d_a_nh::checkCreateHeap;
  uVar1 = f_op_actor_mng::fopAcM_entrySolidHeap
                    ((fopAc_ac_c *)this,d_a_nh::checkCreateHeap,d_a_nh::a_heap_size_tbl_4111);
  if ((uVar1 & 0xff) == 0) {
    uVar4 = 5;
  }
  else {
    *(int *)(this + 0x22c) = *(int *)(this + 0x298) + 0x24;
    uVar5 = CONCAT14(DAT_803e4248,pcVar3);
    if (DAT_803e4248 < '\0') {
      uVar5 = mDoHIO_subRoot_c::createChild
                        (&mDoHIO_subRoot_c_803a5778,"森のほたる",
                         (JORReflexible *)&d_a_nh::l_HIO);
      DAT_803e4288 = this;
    }
    DAT_803e4248 = (char)((uint5)uVar5 >> 0x20);
    iVar2 = init(this,(EVP_PKEY_CTX *)uVar5);
    if (iVar2 == 0) {
      uVar4 = 5;
    }
  }
  return uVar4;
}


/* __thiscall daNh_c::init(void) */

int __thiscall daNh_c::init(daNh_c *this,EVP_PKEY_CTX *ctx)

{
  float fVar1;
  
  this[0x691] = SUB41(*(undefined4 *)(this + 0xb0),0);
  *(float *)(this + 0x224) = d_a_nh::_4273;
  *(undefined4 *)(this + 600) = DAT_803e4270;
  this[0x68e] = SUB21(DAT_803e4282,0);
  fVar1 = d_a_nh::_4090;
  *(float *)(this + 0x67c) = d_a_nh::_4090;
  *(undefined4 *)(this + 0x688) = 0xff;
  *(int *)(this + 0x684) = (int)DAT_803e4284;
  *(float *)(this + 0x680) = fVar1;
  BGCheck(this);
  ::dCcD_Stts::Init((dCcD_Stts *)(this + 0x4a0),0xff,0xff,(fopAc_ac_c *)this);
  ::dCcD_Cyl::Set((dCcD_Cyl *)(this + 0x4dc),(dCcD_SrcCyl *)&d_a_nh::l_cyl_src);
  *(daNh_c **)(this + 0x520) = this + 0x4a0;
  setBaseMtx(this);
  *(undefined4 *)(this + 0x274) = *(undefined4 *)(this + 0x1f8);
  *(undefined4 *)(this + 0x278) = *(undefined4 *)(this + 0x1fc);
  *(undefined4 *)(this + 0x27c) = *(undefined4 *)(this + 0x200);
  *(undefined4 *)(this + 0x260) = *(undefined4 *)(this + 0x274);
  *(undefined4 *)(this + 0x264) = *(undefined4 *)(this + 0x278);
  *(undefined4 *)(this + 0x268) = *(undefined4 *)(this + 0x27c);
  return 1;
}


/* __thiscall daNh_c::action(void *) */

void __thiscall daNh_c::action(daNh_c *this,void *param_1)

{
  bool bVar1;
  undefined4 local_18;
  undefined4 local_14;
  undefined *local_10;
  
  bVar1 = Runtime.PPCEABI.H::__ptmf_test((PTMF *)(this + 0x640));
  if (bVar1 == false) {
    *(float *)(this + 0x254) = d_a_nh::_4090;
    local_18 = d_a_nh::_4279;
    local_14 = DAT_8038d190;
    local_10 = PTR_waitAction_8038d194;
    setAction(this,(FuncDef552 *)&local_18,(void *)0x0);
  }
  Runtime.PPCEABI.H::__ptmf_scall((PTMF *)(this + 0x640),this,param_1);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall daNh_c::setAction(int ()(void const *,void *,void *),
                                void *) */

undefined4 __thiscall daNh_c::setAction(daNh_c *this,FuncDef552 *param_1,void *param_2)

{
  undefined4 uVar1;
  bool bVar2;
  
  bVar2 = Runtime.PPCEABI.H::__ptmf_cmpr((PTMF *)(this + 0x640),(PTMF *)param_1);
  if (bVar2 != false) {
    bVar2 = Runtime.PPCEABI.H::__ptmf_test((PTMF *)(this + 0x640));
    if (bVar2 != false) {
      this[0x68d] = (daNh_c)0xff;
      Runtime.PPCEABI.H::__ptmf_scall((PTMF *)(this + 0x640),this,param_2);
    }
    uVar1 = *(undefined4 *)(param_1 + 4);
    *(undefined4 *)(this + 0x640) = *(undefined4 *)param_1;
    *(undefined4 *)(this + 0x644) = uVar1;
    *(undefined4 *)(this + 0x648) = *(undefined4 *)(param_1 + 8);
    this[0x68d] = (daNh_c)0x0;
    *(undefined2 *)(this + 0x694) = 0;
    *(undefined2 *)(this + 0x696) = 0;
    *(undefined2 *)(this + 0x698) = 0;
    *(undefined2 *)(this + 0x69a) = 0;
    *(float *)(this + 0x6a0) = d_a_nh::_4090;
    Runtime.PPCEABI.H::__ptmf_scall((PTMF *)(this + 0x640),this,param_2);
  }
  return 1;
}


/* __thiscall daNh_c::checkBinCatch(void) */

bool __thiscall daNh_c::checkBinCatch(daNh_c *this)

{
  short sVar1;
  
  sVar1 = *(short *)(this + 0xf8);
  if (sVar1 != 6) {
    dAttCatch_c::request
              (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAttention.mCatch,(fopAc_ac_c *)this,'X',
               DAT_803e424c,DAT_803e4250,DAT_803e4254,DAT_803e4280,1);
    *(ushort *)(this + 0xfa) = *(ushort *)(this + 0xfa) | 0x40;
  }
  else {
    f_op_actor_mng::fopAcM_delete((base_process_class *)this);
  }
  return sVar1 == 6;
}


/* WARNING: Removing unreachable block (ram,0x800fa0e0) */
/* WARNING: Removing unreachable block (ram,0x800fa0e8) */
/* __thiscall daNh_c::searchPlayer(void) */

undefined4 __thiscall daNh_c::searchPlayer(daNh_c *this)

{
  undefined4 uVar1;
  undefined4 uVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  undefined8 in_f30;
  double dVar6;
  undefined8 in_f31;
  float fVar7;
  cXyz local_64;
  undefined4 local_58;
  undefined4 local_54;
  undefined *local_50;
  cXyz local_4c;
  undefined4 local_40;
  undefined4 local_3c;
  undefined *local_38;
  float local_34;
  float local_30;
  float local_2c;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  if (this[0x691] == (daNh_c)0x1) {
    local_40 = d_a_nh::_4314;
    local_3c = DAT_8038d19c;
    local_38 = PTR_escapeAction_8038d1a0;
    setAction(this,(FuncDef552 *)&local_40,(void *)0x0);
    uVar1 = 1;
  }
  else {
    ::cXyz::operator__(&local_4c,
                       &((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).parent
                        .mNext.mPos,
                       &((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).parent
                        .mCurrent.mPos);
    local_34 = local_4c.x;
    local_30 = local_4c.y;
    local_2c = local_4c.z;
    dVar4 = (double)f_op_actor_mng::fopAcM_searchActorDistance
                              (this,d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor);
    dVar6 = (double)(float)((double)*(float *)(this + 0x67c) - dVar4);
    *(float *)(this + 0x67c) = (float)dVar4;
    local_64.x = local_34;
    local_64.y = d_a_nh::_4090;
    local_64.z = local_2c;
    fVar7 = mtx::PSVECSquareMag(&local_64);
    dVar5 = (double)fVar7;
    if ((double)d_a_nh::_4090 < dVar5) {
      dVar3 = 1.0 / SQRT(dVar5);
      dVar3 = d_a_nh::_4362 * dVar3 * (d_a_nh::_4363 - dVar5 * dVar3 * dVar3);
      dVar3 = d_a_nh::_4362 * dVar3 * (d_a_nh::_4363 - dVar5 * dVar3 * dVar3);
      dVar5 = (double)(float)(dVar5 * d_a_nh::_4362 * dVar3 *
                                      (d_a_nh::_4363 - dVar5 * dVar3 * dVar3));
    }
    if (((dVar5 <= (double)d_a_nh::_4364) || ((double)d_a_nh::_4365 <= dVar4)) ||
       (dVar6 <= (double)DAT_803e4260)) {
      uVar1 = 0;
    }
    else {
      local_58 = d_a_nh::_4321;
      local_54 = DAT_8038d1a8;
      local_50 = PTR_escapeAction_8038d1ac;
      setAction(this,(FuncDef552 *)&local_58,(void *)0x0);
      uVar1 = 1;
    }
  }
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  __psq_l0(auStack24,uVar2);
  __psq_l1(auStack24,uVar2);
  return uVar1;
}


/* WARNING: Removing unreachable block (ram,0x800fa178) */
/* WARNING: Removing unreachable block (ram,0x800fa180) */
/* __thiscall daNh_c::moveProc(float,
                               float,
                               short) */

undefined4 __thiscall daNh_c::moveProc(daNh_c *this,float param_1,float param_2,short param_3)

{
  int iVar1;
  undefined4 uVar2;
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
  SComponent::cLib_chaseAngleS(this + 0x206,param_3,0x400);
  *(undefined2 *)(this + 0x20e) = *(undefined2 *)(this + 0x206);
  iVar1 = SComponent::cLib_chaseF((float *)(this + 0x254),(float)dVar4,(float)dVar5);
  if ((iVar1 == 0) || ((double)d_a_nh::_4090 != dVar4)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  __psq_l0(auStack24,uVar3);
  __psq_l1(auStack24,uVar3);
  return uVar2;
}


/* __thiscall daNh_c::getHomeDistance(void) */

double __thiscall daNh_c::getHomeDistance(daNh_c *this)

{
  double dVar1;
  double dVar2;
  float fVar3;
  cXyz local_24;
  cXyz local_18;
  float local_c;
  float local_8;
  float local_4;
  
  ::cXyz::operator__(&local_18,(cXyz *)(this + 0x1d0),(cXyz *)(this + 0x1f8));
  local_c = local_18.x;
  local_8 = local_18.y;
  local_4 = local_18.z;
  local_24.x = local_18.x;
  local_24.y = d_a_nh::_4090;
  local_24.z = local_18.z;
  fVar3 = mtx::PSVECSquareMag(&local_24);
  dVar2 = (double)fVar3;
  if ((double)d_a_nh::_4090 < dVar2) {
    dVar1 = 1.0 / SQRT(dVar2);
    dVar1 = d_a_nh::_4362 * dVar1 * (d_a_nh::_4363 - dVar2 * dVar1 * dVar1);
    dVar1 = d_a_nh::_4362 * dVar1 * (d_a_nh::_4363 - dVar2 * dVar1 * dVar1);
    dVar2 = (double)(float)(dVar2 * d_a_nh::_4362 * dVar1 * (d_a_nh::_4363 - dVar2 * dVar1 * dVar1))
    ;
  }
  return dVar2;
}


/* __thiscall daNh_c::checkTimer(void) */

undefined4 __thiscall daNh_c::checkTimer(daNh_c *this)

{
  int iVar1;
  
  if ((this[0x691] == (daNh_c)0x1) && (iVar1 = d_a_nh::cLib_calcTimer(this + 0x684), iVar1 == 0)) {
    *(int *)(this + 0x688) = *(int *)(this + 0x688) + -4;
    if (*(int *)(this + 0x688) < 0) {
      *(undefined4 *)(this + 0x688) = 0;
    }
    if (*(int *)(this + 0x688) == 0) {
      f_op_actor_mng::fopAcM_delete((base_process_class *)this);
      return 1;
    }
  }
  return 0;
}


/* WARNING: Inlined function: FUN_80328f10 */
/* WARNING: Inlined function: FUN_80328f5c */
/* __thiscall daNh_c::BGCheck(void) */

void __thiscall daNh_c::BGCheck(daNh_c *this)

{
  daNh_c dVar1;
  cBgS_PolyPassChk *pcVar2;
  double dVar3;
  cBgS_GndChk local_98;
  cBgS_PolyPassChk local_58;
  undefined local_4c [16];
  
  ::cBgS_GndChk::cBgS_GndChk(&local_98);
  pcVar2 = &local_58;
  local_58.mbCamThrough = 0;
  local_58.mbLinkThrough = 0;
  local_58.mbArrowsAndLightThrough = 0;
  local_58.mbBombThrough = 0;
  local_58.mbBoomerangThrough = 0;
  local_58.mbHookshotThrough = 0;
  local_98.parent.mpGrpPassChk = (cBgS_GrpPassChk *)pcVar2;
  if (pcVar2 != (cBgS_PolyPassChk *)0x0) {
    local_98.parent.mpGrpPassChk = (cBgS_GrpPassChk *)local_4c;
  }
  local_58.mbObjThrough = 1;
  local_98.parent.vtbl = &dBgS_ObjGndChk_All::__vt;
  local_98.mPolyInfo.vtbl = &cBgS_PolyInfo__vtbl_8037d43c;
  local_58.vtbl = &cBgS_PolyPassChk__vtbl_8037d448;
  local_4c._0_4_ = &cBgS_GrpPassChk__vtbl_8037d454;
  local_4c._4_4_ = 0xf;
  local_98.mPos.x = *(float *)(this + 0x1f8);
  local_98.mPos.y = *(float *)(this + 0x1fc);
  local_98.mPos.z = *(float *)(this + 0x200);
  local_98.parent.mpPolyPassChk = pcVar2;
  dVar3 = (double)cBgS::GroundCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,&local_98);
  if ((double)d_a_nh::_4490 != dVar3) {
    *(float *)(this + 0x680) = (float)dVar3;
    dVar1 = (daNh_c)dBgS::GetRoomId(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,
                                    &local_98.mPolyInfo);
    this[0x20a] = dVar1;
    this[0x1b5] = dVar1;
    dVar1 = (daNh_c)dBgS::GetPolyColor(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,
                                       &local_98.mPolyInfo);
    this[0x1b6] = dVar1;
  }
  local_58.vtbl = (cBgS_PolyPassChk__vtbl *)&PTR_80371f14;
  local_4c._0_4_ = (cBgS_GrpPassChk__vtbl *)&PTR_80371f20;
  if (pcVar2 != (cBgS_PolyPassChk *)0x0) {
    local_58.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_Chk::__vt;
    local_4c._0_4_ = (cBgS_GrpPassChk__vtbl *)&PTR_80371f68;
    if (((undefined *)register0x00000004 != &DAT_0000004c) &&
       (local_4c._0_4_ = (cBgS_GrpPassChk__vtbl *)&::dBgS_GrpPassChk::__vt,
       (undefined *)register0x00000004 != &DAT_0000004c)) {
      local_4c._0_4_ = (cBgS_GrpPassChk__vtbl *)&::cBgS_GrpPassChk::__vt;
    }
    if ((pcVar2 != (cBgS_PolyPassChk *)0x0) &&
       (local_58.vtbl = (cBgS_PolyPassChk__vtbl *)&::dBgS_PolyPassChk::__vt,
       pcVar2 != (cBgS_PolyPassChk *)0x0)) {
      local_58.vtbl = (cBgS_PolyPassChk__vtbl *)&::cBgS_PolyPassChk::__vt;
    }
  }
  local_98.parent.vtbl = (cBgS_Chk__vtbl *)&::cBgS_GndChk::__vt;
  local_98.mPolyInfo.vtbl = (cBgS_PolyInfo__vtbl *)&::cBgS_PolyInfo::__vt;
  cBgS_Chk::_cBgS_Chk(&local_98.parent);
  return;
}


/* __thiscall daNh_c::airMove(void) */

void __thiscall daNh_c::airMove(daNh_c *this)

{
  if (*(float *)(this + 0x1fc) < (*(float *)(this + 0x680) + DAT_803e4264) - d_a_nh::_4589) {
    *(undefined4 *)(this + 0x25c) = DAT_803e4268;
    return;
  }
  if (*(float *)(this + 0x1fc) <= d_a_nh::_4589 + *(float *)(this + 0x680) + DAT_803e4264) {
    return;
  }
  *(undefined4 *)(this + 0x25c) = DAT_803e426c;
  return;
}


/* __thiscall daNh_c::waitAction(void *) */

undefined4 __thiscall daNh_c::waitAction(daNh_c *this,void *param_1)

{
  double dVar1;
  undefined4 local_18;
  undefined4 local_14;
  undefined *local_10;
  
  if (this[0x68d] == (daNh_c)0x0) {
    this[0x68d] = (daNh_c)0x1;
    dVar1 = (double)f_op_actor_mng::fopAcM_searchActorDistance
                              (this,d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor);
    *(float *)(this + 0x67c) = (float)dVar1;
  }
  else {
    if (this[0x68d] != (daNh_c)0xff) {
      SComponent::cLib_addCalc
                ((float *)(this + 0x254),d_a_nh::_4090,d_a_nh::_4609,d_a_nh::_4589,d_a_nh::_4273);
      dVar1 = (double)getHomeDistance(this);
      if ((double)d_a_nh::_4610 < dVar1) {
        local_18 = d_a_nh::_4601;
        local_14 = DAT_8038d1b4;
        local_10 = PTR_returnAction_8038d1b8;
        setAction(this,(FuncDef552 *)&local_18,(void *)0x0);
      }
    }
  }
  return 1;
}


/* __thiscall daNh_c::checkEscapeEnd(void) */

undefined4 __thiscall daNh_c::checkEscapeEnd(daNh_c *this)

{
  short sVar1;
  float fVar2;
  cXyz local_48;
  undefined4 local_3c;
  undefined4 local_38;
  undefined *local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined *local_28;
  cXyz local_24;
  float local_18;
  float local_14;
  float local_10;
  
  ::cXyz::operator__(&local_24,(cXyz *)(this + 0x1d0),(cXyz *)(this + 0x1f8));
  local_18 = local_24.x;
  local_14 = local_24.y;
  local_10 = local_24.z;
  if (this[0x691] != (daNh_c)0x1) {
    sVar1 = d_a_arrow::cLib_calcTimer(this + 0x694);
    if (sVar1 == 0) {
      local_30 = d_a_nh::_4618;
      local_2c = DAT_8038d1c0;
      local_28 = PTR_waitAction_8038d1c4;
      setAction(this,(FuncDef552 *)&local_30,(void *)0x0);
      return 1;
    }
    local_48.x = local_18;
    local_48.y = d_a_nh::_4090;
    local_48.z = local_10;
    fVar2 = mtx::PSVECSquareMag(&local_48);
    if (DAT_803e4274 * DAT_803e4274 < fVar2) {
      local_3c = d_a_nh::_4623;
      local_38 = DAT_8038d1cc;
      local_34 = PTR_returnAction_8038d1d0;
      setAction(this,(FuncDef552 *)&local_3c,(void *)0x0);
      return 1;
    }
  }
  return 0;
}


/* __thiscall daNh_c::escapeAction(void *) */

undefined4 __thiscall daNh_c::escapeAction(daNh_c *this,void *param_1)

{
  short sVar1;
  int iVar2;
  short sVar3;
  char cVar4;
  daNh_c dVar5;
  
  if (this[0x68d] == (daNh_c)0x0) {
    this[0x68d] = (daNh_c)0x1;
    this[0x68f] = (daNh_c)0x0;
    this[0x690] = (daNh_c)0x0;
    *(undefined2 *)(this + 0x694) = 0x96;
  }
  else {
    if (this[0x68d] != (daNh_c)0xff) {
      iVar2 = checkEscapeEnd(this);
      if (iVar2 == 0) {
        sVar3 = f_op_actor_mng::fopAcM_searchActorAngleY
                          ((fopAc_ac_c *)this,
                           (fopAc_ac_c *)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor);
        cVar4 = m_Do_audio::cLib_calcTimer(this + 0x690);
        if (cVar4 == '\0') {
          this[0x68f] = (daNh_c)((byte)this[0x68f] ^ 1);
          dVar5 = (daNh_c)d_a_nh::cLib_getRndValue(0xf,0x14);
          this[0x690] = dVar5;
        }
        sVar1 = 0x2000;
        if (this[0x68f] != (daNh_c)0x0) {
          sVar1 = -0x2000;
        }
        moveProc(this,d_a_nh::_4675,d_a_nh::_4676,sVar3 + -0x8000 + sVar1);
      }
    }
  }
  return 1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall daNh_c::returnAction(void *) */

undefined4 __thiscall daNh_c::returnAction(daNh_c *this,void *param_1)

{
  short sVar2;
  short sVar3;
  int iVar1;
  char cVar4;
  daNh_c dVar5;
  double dVar6;
  float fVar7;
  cXyz local_48;
  cXyz local_3c;
  undefined4 local_30;
  undefined4 local_2c;
  undefined *local_28;
  float local_24;
  float local_20;
  float local_1c;
  
  if (this[0x68d] == (daNh_c)0x0) {
    this[0x68d] = (daNh_c)0x1;
    this[0x68f] = (daNh_c)0x0;
    this[0x690] = (daNh_c)0x0;
    *(undefined2 *)(this + 0x694) = 0x96;
  }
  else {
    if (this[0x68d] != (daNh_c)0xff) {
      dVar6 = (double)getHomeDistance(this);
      if ((double)d_a_nh::_4610 <= dVar6) {
        sVar2 = SComponent::cLib_targetAngleY((cXyz *)(this + 0x1f8),(cXyz *)(this + 0x1d0));
        ::cXyz::operator__(&local_3c,(cXyz *)(this + 0x1d0),(cXyz *)(this + 0x1f8));
        local_24 = local_3c.x;
        local_20 = local_3c.y;
        local_1c = local_3c.z;
        local_48.x = local_3c.x;
        local_48.y = d_a_nh::_4090;
        local_48.z = local_3c.z;
        fVar7 = mtx::PSVECSquareMag(&local_48);
        if (fVar7 < DAT_803e4274 * DAT_803e4274) {
          sVar3 = f_op_actor_mng::fopAcM_searchActorAngleY
                            ((fopAc_ac_c *)this,
                             (fopAc_ac_c *)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor
                            );
          iVar1 = MSL_C.PPCEABI.bare.H::abs((int)(short)(sVar2 - sVar3));
          if (iVar1 < 0x1000) {
            if ((short)(sVar2 - sVar3) < 0) {
              sVar2 = sVar2 + -0x4000;
            }
            else {
              sVar2 = sVar2 + 0x4000;
            }
          }
        }
        cVar4 = m_Do_audio::cLib_calcTimer(this + 0x690);
        if (cVar4 == '\0') {
          this[0x68f] = (daNh_c)((byte)this[0x68f] ^ 1);
          dVar5 = (daNh_c)d_a_nh::cLib_getRndValue(0xf,0x14);
          this[0x690] = dVar5;
        }
        sVar3 = 0x2000;
        if (this[0x68f] != (daNh_c)0x0) {
          sVar3 = -0x2000;
        }
        moveProc(this,d_a_nh::_4675,d_a_nh::_4676,sVar2 + sVar3);
      }
      else {
        local_30 = d_a_nh::_4688;
        local_2c = DAT_8038d1d8;
        local_28 = PTR_waitAction_8038d1dc;
        setAction(this,(FuncDef552 *)&local_30,(void *)0x0);
      }
    }
  }
  return 1;
}


/* __thiscall daNh_c::execute(void) */

undefined4 __thiscall daNh_c::execute(daNh_c *this)

{
  float fVar1;
  int iVar2;
  cXyz local_18;
  
  playBrkAnm(this);
  this[0x68e] = SUB21(DAT_803e4282,0);
  fVar1 = *(float *)(this + 0x224);
  if (fVar1 <= *(float *)(this + 0x25c)) {
    if (fVar1 < *(float *)(this + 0x25c)) {
      *(float *)(this + 0x224) = fVar1 + *(float *)(this + 600);
      if (*(float *)(this + 0x25c) < *(float *)(this + 0x224)) {
        *(float *)(this + 0x224) = *(float *)(this + 0x25c);
      }
    }
  }
  else {
    *(float *)(this + 0x224) = fVar1 - *(float *)(this + 600);
    if (*(float *)(this + 0x224) < *(float *)(this + 0x25c)) {
      *(float *)(this + 0x224) = *(float *)(this + 0x25c);
    }
  }
  *(float *)(this + 0x220) =
       *(float *)(this + 0x254) *
       JKernel::JMath::jmaSinTable
       [(int)((int)*(short *)(this + 0x206) & 0xffffU) >> (JKernel::JMath::jmaSinShift & 0x3f)];
  *(float *)(this + 0x228) =
       *(float *)(this + 0x254) *
       JKernel::JMath::jmaCosTable
       [(int)((int)*(short *)(this + 0x206) & 0xffffU) >> (JKernel::JMath::jmaSinShift & 0x3f)];
  f_op_actor_mng::fopAcM_posMove((fopAc_ac_c *)this,(cXyz *)(this + 0x4a0));
  BGCheck(this);
  local_18.x = *(float *)(this + 0x1f8);
  local_18.z = *(float *)(this + 0x200);
  local_18.y = *(float *)(this + 0x1fc) - d_a_nh::_4589;
  ::cM3dGCyl::SetC((cM3dGCyl *)(this + 0x5f4),&local_18);
  cCcS::Set(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.parent,(cCcD_Obj *)(this + 0x4dc));
  checkTimer(this);
  iVar2 = checkBinCatch(this);
  if (iVar2 == 0) {
    airMove(this);
    searchPlayer(this);
    action(this,(void *)0x0);
  }
  setBaseMtx(this);
  *(undefined4 *)(this + 0x274) = *(undefined4 *)(this + 0x1f8);
  *(undefined4 *)(this + 0x278) = *(undefined4 *)(this + 0x1fc);
  *(undefined4 *)(this + 0x27c) = *(undefined4 *)(this + 0x200);
  *(undefined4 *)(this + 0x260) = *(undefined4 *)(this + 0x274);
  *(undefined4 *)(this + 0x264) = *(undefined4 *)(this + 0x278);
  *(undefined4 *)(this + 0x268) = *(undefined4 *)(this + 0x27c);
  return 1;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall daNh_c::initBrkAnm(bool) */

bool __thiscall daNh_c::initBrkAnm(daNh_c *this,bool param_1)

{
  J3DAnmTevRegKey *pJVar1;
  ulong uVar2;
  int iVar3;
  J3DModelData *pJVar4;
  
  pJVar4 = *(J3DModelData **)(*(int *)(this + 0x298) + 4);
  pJVar1 = (J3DAnmTevRegKey *)
           dRes_control_c::getRes
                     ("Always",0x4e,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
  if (pJVar1 == (J3DAnmTevRegKey *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_a_nh.cpp",0x373,"a_brk != 0");
    m_Do_printf::OSPanic("d_a_nh.cpp",0x373,&DAT_8035bfdd);
  }
  iVar3 = ::mDoExt_brkAnm::init
                    ((mDoExt_brkAnm *)(this + 0x60c),pJVar4,pJVar1,true,Repeat,d_a_nh::_4273,0,-1,
                     param_1,0);
  return iVar3 != 0;
}


/* __thiscall daNh_c::playBrkAnm(void) */

void __thiscall daNh_c::playBrkAnm(daNh_c *this)

{
  ::mDoExt_baseAnm::play((mDoExt_baseAnm *)(this + 0x60c));
  return;
}


/* __thiscall daNh_c::draw(void) */

undefined4 __thiscall daNh_c::draw(daNh_c *this)

{
  J3DMaterial *pJVar1;
  short *psVar2;
  int iVar3;
  J3DModelData *pJVar4;
  J3DTevBlock *pJVar5;
  
  dScnKy_env_light_c::settingTevStruct
            (&d_kankyo::g_env_light,Actor,(cXyz *)(this + 0x1f8),(dKy_tevstr_c *)(this + 0x10c));
  dScnKy_env_light_c::setLightTevColorType
            (&d_kankyo::g_env_light,*(J3DModel **)(this + 0x298),(dKy_tevstr_c *)(this + 0x10c));
  pJVar4 = *(J3DModelData **)(*(int *)(this + 0x298) + 4);
  ::mDoExt_brkAnm::entry
            ((mDoExt_brkAnm *)(this + 0x60c),pJVar4,*(float *)(*(int *)(this + 0x610) + 0x10));
  m_Do_ext::mDoExt_modelUpdateDL(*(J3DModel **)(this + 0x298));
  J3DMaterialTable::removeTevRegAnimator
            (&pJVar4->mMaterialTable,*(J3DAnmTevRegKey **)(this + 0x614));
  pJVar1 = *(pJVar4->mMaterialTable).mpMaterials;
  if ((pJVar1 != (J3DMaterial *)0x0) && (pJVar5 = pJVar1->mpTevBlock, pJVar5 != (J3DTevBlock *)0x0))
  {
    psVar2 = (short *)(*(code *)pJVar5->vtbl->getTevColor)(pJVar5,1);
    if (psVar2 != (short *)0x0) {
      this[0x68e] = SUB41(((int)*psVar2 + (int)psVar2[1] + (int)psVar2[2]) / 3 >> 2,0);
    }
    iVar3 = (*(code *)pJVar5->vtbl->getTevKColor)(pJVar5,3);
    if (iVar3 != 0) {
      *(char *)(iVar3 + 3) = (char)*(undefined4 *)(this + 0x688);
    }
  }
  dDlst_alphaModel_c::set
            (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpAlphaModel0,Bonbori,
             (MTX34 *)(this + 0x64c),(byte)this[0x68e]);
  return 1;
}


namespace d_a_nh {

/* __stdcall daNh_Draw(daNh_c *) */

void daNh_Draw(daNh_c *param_1)

{
  ::daNh_c::draw(param_1);
  return;
}


/* __stdcall daNh_Execute(daNh_c *) */

void daNh_Execute(daNh_c *param_1)

{
  ::daNh_c::execute(param_1);
  return;
}


/* __stdcall daNh_IsDelete(daNh_c *) */

undefined4 daNh_IsDelete(void)

{
  return 1;
}


/* __stdcall daNh_Delete(daNh_c *) */

undefined4 daNh_Delete(daNh_c *param_1)

{
  ::daNh_c::_daNh_c(param_1);
  return 1;
}


/* __stdcall daNh_Create(fopAc_ac_c *) */

void daNh_Create(daNh_c *param_1)

{
  ::daNh_c::create(param_1);
  return;
}

}

/* __thiscall daNh_HIO_c::~daNh_HIO_c(void) */

void __thiscall daNh_HIO_c::_daNh_HIO_c(daNh_HIO_c *this)

{
  short in_r4;
  
  if ((this != (daNh_HIO_c *)0x0) && (*(undefined **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


namespace d_a_nh {

/* __stdcall cLib_calcTimer<int>(int *) */

int cLib_calcTimer(int *param_1)

{
  if (*param_1 != 0) {
    *param_1 = *param_1 + -1;
  }
  return *param_1;
}


/* __stdcall cLib_getRndValue<int>(int,
                                   int) */

int cLib_getRndValue(uint param_1,uint param_2)

{
  float fVar1;
  
  fVar1 = SComponent::cM_rndF((float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - _4900));
  return (int)((float)((double)CONCAT44(0x43300000,param_1 ^ 0x80000000) - _4900) + fVar1);
}


void __sinit_d_a_nh_cpp(void)

{
  ::daNh_HIO_c::daNh_HIO_c((daNh_HIO_c *)&l_HIO);
  Runtime.PPCEABI.H::__register_global_object();
  return;
}

