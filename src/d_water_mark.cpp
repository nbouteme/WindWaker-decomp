#include <d_water_mark.h>
#include <J3DU/J3DUClipper.h>
#include <m_Do_ext.h>
#include <SComponent/c_bg_s.h>
#include <SComponent/c_math.h>
#include <mtx/vec.h>
#include <mtx/mtx.h>
#include <m_Do_mtx.h>
#include <d_bg_s.h>
#include <f_op_kankyo_mng.h>
#include <d_water_mark.h>
#include <d_resorce.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <dWaterMark_c.h>

undefined1 dWaterMark_c;
undefined1 dWaterMark_c;
undefined1 dWaterMark_c;

namespace d_water_mark {

/* __stdcall dWaterMark_Draw(dWaterMark_c *) */

undefined4 dWaterMark_Draw(int param_1)

{
  uint uVar1;
  cXyz local_18;
  
  local_18.x = *(float *)(param_1 + 0xdc);
  local_18.y = *(float *)(param_1 + 0xe0);
  local_18.z = *(float *)(param_1 + 0xe4);
  uVar1 = J3DUClipper::clip(&mDoLib_clipper::mClipper,&J3DGraphBase::j3dSys.mCurViewMtx,&local_18,
                            _4139 * *(float *)(param_1 + 0xe8));
  if (uVar1 == 0) {
    ::mDoExt_brkAnm::entry
              ((mDoExt_brkAnm *)(param_1 + 0x100),*(J3DModelData **)(*(int *)(param_1 + 0xfc) + 4),
               *(float *)(*(int *)(param_1 + 0x104) + 0x10));
    ::mDoExt_btpAnm::entry
              ((mDoExt_btpAnm *)(param_1 + 0x118),*(J3DModelData **)(*(int *)(param_1 + 0xfc) + 4),
               (short)*(undefined4 *)(param_1 + 0xf4));
    m_Do_ext::mDoExt_modelUpdateDL(*(J3DModel **)(param_1 + 0xfc));
  }
  return 1;
}

}

/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Removing unreachable block (ram,0x8023de0c) */
/* __thiscall dWaterMark_c::setMatrix(void) */

undefined4 __thiscall dWaterMark_c::setMatrix(dWaterMark_c *this)

{
  short sVar1;
  uint uVar2;
  cM3dGPla *pcVar3;
  int iVar4;
  int iVar5;
  char cVar7;
  undefined4 uVar6;
  undefined4 uVar8;
  double dVar9;
  double dVar10;
  undefined8 in_f31;
  float fVar11;
  cXyz local_54;
  float local_48;
  float local_44;
  float local_40;
  undefined auStack8 [8];
  
  uVar8 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  DAT_803e80a8 = (this->parent).mPos.z;
  DAT_803e80a4 = d_water_mark::_4203 + (this->parent).mPos.y;
  DAT_803e80a0 = (this->parent).mPos.x;
  local_48 = DAT_803e80a0;
  local_44 = DAT_803e80a4;
  local_40 = DAT_803e80a8;
  dVar10 = (double)cBgS::GroundCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                                     (cBgS_GndChk *)&m_ground_check);
  (this->parent).mPos.y = (float)dVar10;
  if (d_water_mark::_4204 == (this->parent).mPos.y) {
    uVar6 = 0;
  }
  else {
    pcVar3 = cBgS::GetTriPla((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,(uint)DAT_803e8092,
                             (uint)DAT_803e8090);
    iVar4 = SComponent::cM_atan2s((pcVar3->mNorm).x,(pcVar3->mNorm).z);
    sVar1 = this->field_0x12e;
    local_54.z = (pcVar3->mNorm).z;
    local_54.x = (pcVar3->mNorm).x;
    local_54.y = d_water_mark::_4205;
    fVar11 = mtx::PSVECSquareMag(&local_54);
    dVar10 = (double)fVar11;
    if ((double)d_water_mark::_4205 < dVar10) {
      dVar9 = 1.0 / SQRT(dVar10);
      dVar9 = d_water_mark::_4206 * dVar9 * (d_water_mark::_4207 - dVar10 * dVar9 * dVar9);
      dVar9 = d_water_mark::_4206 * dVar9 * (d_water_mark::_4207 - dVar10 * dVar9 * dVar9);
      dVar10 = (double)(float)(dVar10 * d_water_mark::_4206 * dVar9 *
                                        (d_water_mark::_4207 - dVar10 * dVar9 * dVar9));
    }
    mtx::PSMTXTrans((double)(this->parent).mPos.x,
                    (double)(d_water_mark::_4208 + (this->parent).mPos.y),
                    (double)(this->parent).mPos.z,&mDoMtx_stack_c::now);
    uVar2 = (int)(short)((short)iVar4 - sVar1) & 0xffff;
    iVar4 = SComponent::cM_atan2s
                      ((float)(dVar10 * -(double)JKernel::JMath::jmaSinTable
                                                 [(int)uVar2 >> (JKernel::JMath::jmaSinShift & 0x3f)
                                                 ]),(pcVar3->mNorm).y);
    sVar1 = this->field_0x12e;
    iVar5 = SComponent::cM_atan2s
                      ((float)(dVar10 * (double)JKernel::JMath::jmaCosTable
                                                [(int)uVar2 >> (JKernel::JMath::jmaSinShift & 0x3f)]
                              ),(pcVar3->mNorm).y);
    m_Do_mtx::mDoMtx_ZXYrotM(&mDoMtx_stack_c::now,iVar5,(int)sVar1,iVar4);
    mtx::PSMTXCopy(&mDoMtx_stack_c::now,(MTX34 *)(*(int *)&this->field_0xfc + 0x24));
    cVar7 = dBgS::ChkMoveBG(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,
                            (cBgS_PolyInfo *)&DAT_803e8090);
    if (cVar7 == '\0') {
      *(undefined2 *)&this->field_0x12c = 0;
    }
    else {
      *(undefined2 *)&this->field_0x12c = 1;
    }
    uVar6 = 1;
  }
  __psq_l0(auStack8,uVar8);
  __psq_l1(auStack8,uVar8);
  return uVar6;
}


namespace d_water_mark {

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __stdcall dWaterMark_Execute(dWaterMark_c *) */

undefined4 dWaterMark_Execute(dWaterMark_c *param_1)

{
  short sVar1;
  short sVar2;
  bool bVar3;
  int iVar4;
  
  if (*(short *)&param_1->field_0x134 != -1) {
    sVar1 = *(short *)&param_1->field_0x130;
    sVar2 = *(short *)&param_1->field_0x132;
    if (sVar1 < sVar2) {
      if ((sVar1 <= _m_player_foot_now_id) && (_m_player_foot_now_id < sVar2)) {
        *(undefined2 *)&param_1->field_0x134 = 0xffff;
      }
    }
    else {
      if ((sVar1 <= _m_player_foot_now_id) || (_m_player_foot_now_id < sVar2)) {
        *(undefined2 *)&param_1->field_0x134 = 0xffff;
      }
    }
  }
  if (*(short *)&param_1->field_0x134 == -1) {
    ::mDoExt_baseAnm::play((mDoExt_baseAnm *)&param_1->field_0x100);
  }
  bVar3 = true;
  if ((*(byte *)(*(int *)&param_1->field_0x104 + 5) & 1) == 0) {
    if (_4205 != *(float *)(*(int *)&param_1->field_0x104 + 0xc)) {
      bVar3 = false;
    }
  }
  if (bVar3) {
    f_op_kankyo_mng::fopKyM_Delete(param_1);
  }
  else {
    if ((*(short *)&param_1->field_0x12c == 1) &&
       (iVar4 = ::dWaterMark_c::setMatrix(param_1), iVar4 == 0)) {
      f_op_kankyo_mng::fopKyM_Delete(param_1);
    }
  }
  return 1;
}


/* __stdcall dWaterMark_IsDelete(dWaterMark_c *) */

undefined4 dWaterMark_IsDelete(void)

{
  return 1;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __stdcall dWaterMark_Delete(dWaterMark_c *) */

undefined4 dWaterMark_Delete(int param_1)

{
  if (*(int *)(param_1 + 0xf8) != 0) {
    m_Do_ext::mDoExt_destroySolidHeap();
  }
  if (*(int *)(param_1 + 0xf4) == 1) {
    _m_circle_cnt = _m_circle_cnt + -1;
  }
  return 1;
}


/* __stdcall dWaterMark_Create(kankyo_class *) */

void dWaterMark_Create(dWaterMark_c *param_1)

{
  ::dWaterMark_c::create(param_1);
  return;
}

}

/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dWaterMark_c::create(void) */

undefined4 __thiscall dWaterMark_c::create(dWaterMark_c *this)

{
  int iVar1;
  undefined4 uVar2;
  JKRSolidHeap *pJVar3;
  J3DModelData *pModel;
  ulong uVar4;
  J3DModel *pJVar5;
  J3DAnmTevRegKey *pJVar6;
  uint uVar7;
  J3DAnmTexPattern *pJVar8;
  uint uVar9;
  
  if (this != (dWaterMark_c *)0x0) {
    *(undefined ***)&this->field_0x100 = &::mDoExt_baseAnm::__vt;
    *(undefined4 *)&this->field_0x104 = 0;
    *(undefined ***)&this->field_0x100 = &::mDoExt_brkAnm::__vt;
    *(undefined4 *)&this->field_0x10c = 0;
    *(undefined4 *)&this->field_0x110 = 0;
    *(undefined ***)&this->field_0x118 = &::mDoExt_baseAnm::__vt;
    *(undefined4 *)&this->field_0x11c = 0;
    *(undefined **)&this->field_0x118 = &::mDoExt_btpAnm::__vt;
    *(undefined4 *)&this->field_0x124 = 0;
  }
  this->field_0x12e = (short)((uint)(this->parent).mParameter >> 0x10);
  (this->parent).mParameter = (this->parent).mParameter & 0xffff;
  iVar1 = (this->parent).mParameter;
  if (((iVar1 == 0) || (iVar1 == 1)) || (iVar1 == 2)) {
    if ((iVar1 == 1) && (_m_circle_cnt = _m_circle_cnt + 1, 10 < _m_circle_cnt)) {
      uVar2 = 5;
    }
    else {
      pJVar3 = m_Do_ext::mDoExt_createSolidHeapFromGameToCurrent(0x12a0,0x20);
      this->field_0xf8 = &pJVar3->parent;
      if (this->field_0xf8 == (JKRHeap *)0x0) {
        uVar2 = 5;
      }
      else {
        pModel = (J3DModelData *)
                 dRes_control_c::getRes
                           ("Always",0x2f,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,
                            0x40);
        if (pModel == (J3DModelData *)0x0) {
          uVar4 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar4,"d_water_mark.cpp",0x130,"modelData != 0");
          m_Do_printf::OSPanic("d_water_mark.cpp",0x130,&DAT_80363a97);
        }
        pJVar5 = m_Do_ext::mDoExt_J3DModel__create(pModel,0x80000,0x11020022);
        *(J3DModel **)&this->field_0xfc = pJVar5;
        pJVar6 = (J3DAnmTevRegKey *)
                 dRes_control_c::getRes
                           ("Always",0x4d,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,
                            0x40);
        uVar7 = ::mDoExt_brkAnm::init
                          ((mDoExt_brkAnm *)&this->field_0x100,pModel,pJVar6,true,Once,
                           d_water_mark::_4349,0,-1,false,0);
        pJVar8 = (J3DAnmTexPattern *)
                 dRes_control_c::getRes
                           ("Always",99,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40
                           );
        uVar9 = ::mDoExt_btpAnm::init
                          ((mDoExt_btpAnm *)&this->field_0x118,pModel,pJVar8,0,0,d_water_mark::_4349
                           ,0,-1,false,0);
        m_Do_ext::mDoExt_restoreCurrentHeap();
        m_Do_ext::mDoExt_adjustSolidHeap((JKRSolidHeap *)this->field_0xf8);
        iVar1 = *(int *)&this->field_0xfc;
        if ((iVar1 == 0) || ((uVar7 & uVar9) == 0)) {
          uVar2 = 5;
        }
        else {
          *(float *)(iVar1 + 0x18) = (this->parent).mScale.x;
          *(float *)(iVar1 + 0x1c) = (this->parent).mScale.y;
          *(float *)(iVar1 + 0x20) = (this->parent).mScale.z;
          iVar1 = setMatrix(this);
          if (iVar1 == 0) {
            uVar2 = 5;
          }
          else {
            if ((this->parent).mParameter == 2) {
              *(short *)&this->field_0x134 = _m_player_foot_now_id;
              _m_player_foot_now_id = _m_player_foot_now_id + 1;
              if (_m_player_foot_now_id == 0x28) {
                _m_player_foot_now_id = 0;
              }
              *(short *)&this->field_0x130 = *(short *)&this->field_0x134 + 0x14;
              if (0x27 < *(short *)&this->field_0x130) {
                *(short *)&this->field_0x130 = *(short *)&this->field_0x130 + -0x28;
              }
              *(short *)&this->field_0x132 = *(short *)&this->field_0x130 + 0x14;
              if (0x27 < *(short *)&this->field_0x132) {
                *(short *)&this->field_0x132 = *(short *)&this->field_0x132 + -0x28;
              }
              (this->parent).mParameter = 0;
            }
            else {
              *(undefined2 *)&this->field_0x134 = 0xffff;
            }
            uVar2 = 4;
          }
        }
      }
    }
  }
  else {
    uVar2 = 5;
  }
  return uVar2;
}

