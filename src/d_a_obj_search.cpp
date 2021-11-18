#include <d_a_obj_search.h>
#include <d_a_obj_search.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <d_resorce.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <m_Do_ext.h>
#include <JKernel/JKRHeap.h>
#include <d_bg_w.h>
#include <SComponent/c_bg_w.h>
#include <mtx/mtx.h>
#include <m_Do_mtx.h>
#include <d_lib.h>
#include <f_pc_searcher.h>
#include <f_op_actor_iter.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <SComponent/c_xyz.h>
#include <SComponent/c_math.h>
#include <SComponent/c_lib.h>
#include <d_save.h>
#include <d_com_inf_game.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <d_event_manager.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <MSL_C.PPCEABI.bare.H/arith.h>
#include <f_op_actor_mng.h>
#include <d_a_item.h>
#include <d_bg_s_lin_chk.h>
#include <SComponent/c_bg_s.h>
#include <mtx/vec.h>
#include <d_a_nh.h>
#include <Runtime.PPCEABI.H/ptmf.h>
#include <SComponent/c_bg_s_lin_chk.h>
#include <d_bg_s.h>
#include <d_cc_d.h>
#include <d_path.h>
#include <d_kankyo.h>
#include <f_op_actor.h>
#include <d_a_arrow.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <c_damagereaction.h>
#include <d_particle.h>
#include <SComponent/c_bg_s_chk.h>
#include <mtx/mtxvec.h>
#include <SComponent/c_cc_s.h>
#include <J3DU/J3DUClipper.h>
#include <d_drawlist.h>
#include <dBgS_ObjLinChk.h>
#include <Demangler/daObj_Search/Act_c.h>
#include <csXyz.h>
#include <dCcD_Stts.h>
#include <daObj_Search/Bgc_c.h>
#include <dCcD_Cps.h>
#include <daObj_Search/Mthd.h>


namespace d_a_obj_search {
}

namespace daObj_Search {
}

namespace d_a_obj_search {
}

namespace d_a_obj_search {
undefined4 pos$4262;
undefined4 pos$4268;
undefined4 pos$4274;
undefined4 pos$4567;
undefined4 pos$4678;
undefined4 pos$4832;
undefined4 pos$4837;
undefined1 init$4264;
undefined1 init$4270;
undefined1 init$4276;
undefined1 init$4569;
undefined1 init$4680;
undefined1 init$4834;
undefined1 init$4839;
undefined1 init$4977;

namespace Act_c {
undefined1 m_find_flag;
}

/* __stdcall createHeap_CB(fopAc_ac_c *) */

void createHeap_CB(Act_c *param_1)

{
  daObj_Search::Act_c::_createHeap(param_1);
  return;
}

}

namespace daObj_Search {

/* __thiscall Act_c::_createHeap(void) */

bool __thiscall Act_c::_createHeap(Act_c *this)

{
  char cVar1;
  bool bVar2;
  
  cVar1 = searchCreateHeap(this);
  if (cVar1 == '\0') {
    bVar2 = false;
  }
  else {
    cVar1 = beamCreateHeap(this,0);
    if (cVar1 == '\0') {
      bVar2 = false;
    }
    else {
      cVar1 = beamCreateHeap(this,1);
      bVar2 = cVar1 != '\0';
    }
  }
  return bVar2;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall Act_c::searchCreateHeap(void) */

int __thiscall Act_c::searchCreateHeap(Act_c *this)

{
  J3DModelData *pModel;
  ulong uVar1;
  J3DModel *pJVar2;
  int iVar3;
  dBgW *this_00;
  cBgD_t *pData;
  uint uVar4;
  
  pModel = (J3DModelData *)
           dRes_control_c::getRes
                     ("Search",5,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
  if (pModel == (J3DModelData *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_a_obj_search.cpp",0x39,"modelData != 0");
    m_Do_printf::OSPanic("d_a_obj_search.cpp",0x39,&DAT_8035c112);
  }
  pJVar2 = m_Do_ext::mDoExt_J3DModel__create(pModel,0x80000,0x11000022);
  *(J3DModel **)(this + 0x5f4) = pJVar2;
  if (*(int *)(this + 0x5f4) == 0) {
    iVar3 = 0;
  }
  else {
    this_00 = (dBgW *)JKernel::operator_new(0xbc);
    if (this_00 != (dBgW *)0x0) {
      this_00 = dBgW::dBgW(this_00);
    }
    *(dBgW **)(this + 0x670) = this_00;
    if (*(int *)(this + 0x670) == 0) {
      iVar3 = 0;
    }
    else {
      pData = (cBgD_t *)
              dRes_control_c::getRes
                        ("Search",8,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
      uVar4 = cBgW::Set(*(cBgW **)(this + 0x670),pData,MoveBG,(MTX34 *)(this + 0x6d4));
      iVar3 = -(uVar4 & 0xff) + 1;
      iVar3 = iVar3 - ((uint)(iVar3 == 0) + -(uVar4 & 0xff));
    }
  }
  return iVar3;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall Act_c::beamCreateHeap(int) */

int __thiscall Act_c::beamCreateHeap(Act_c *this,int param_1)

{
  J3DModelData *pModel;
  int iVar1;
  J3DModel *pJVar2;
  dBgW *this_00;
  cBgD_t *pData;
  uint uVar3;
  Act_c *pAVar4;
  
  pModel = (J3DModelData *)
           dRes_control_c::getRes
                     ("Search",4,d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
  if (pModel == (J3DModelData *)0x0) {
    iVar1 = 0;
  }
  else {
    pJVar2 = m_Do_ext::mDoExt_J3DModel__create(pModel,0x80000,0x11000022);
    iVar1 = param_1 * 4;
    *(J3DModel **)(this + iVar1 + 0x5f8) = pJVar2;
    if (*(int *)(this + iVar1 + 0x5f8) == 0) {
      iVar1 = 0;
    }
    else {
      this_00 = (dBgW *)JKernel::operator_new(0xbc);
      if (this_00 != (dBgW *)0x0) {
        this_00 = dBgW::dBgW(this_00);
      }
      pAVar4 = this + iVar1;
      *(dBgW **)(pAVar4 + 0x668) = this_00;
      if (*(int *)(pAVar4 + 0x668) == 0) {
        iVar1 = 0;
      }
      else {
        pData = (cBgD_t *)
                dRes_control_c::getRes
                          ("Search",*(long *)(&d_a_obj_search::dzb_4138 + iVar1),
                           d_com_inf_game::g_dComIfG_gameInfo.mResCtrl.mObjectInfo,0x40);
        uVar3 = cBgW::Set(*(cBgW **)(pAVar4 + 0x668),pData,MoveBG,
                          (MTX34 *)(this + param_1 * 0x30 + 0x674));
        iVar1 = -(uVar3 & 0xff) + 1;
        iVar1 = iVar1 - ((uint)(iVar1 == 0) + -(uVar3 & 0xff));
      }
    }
  }
  return iVar1;
}

}

namespace d_a_obj_search {

/* __stdcall nodeControl_CB(J3DNode *,
                            int) */

undefined4 nodeControl_CB(J3DNode *param_1,int param_2)

{
  if (param_2 == 0) {
    if ((Act_c *)(J3DGraphBase::j3dSys.mpCurModel)->mpUserData != (Act_c *)0x0) {
      daObj_Search::Act_c::_nodeControl
                ((Act_c *)(J3DGraphBase::j3dSys.mpCurModel)->mpUserData,param_1,
                 J3DGraphBase::j3dSys.mpCurModel);
    }
  }
  return 1;
}

}

namespace daObj_Search {

/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall Act_c::_nodeControl(J3DNode *,
                                                J3DModel *) */

void __thiscall Act_c::_nodeControl(Act_c *this,J3DNode *param_1,J3DModel *param_2)

{
  short sVar1;
  float fVar2;
  int iVar3;
  short sVar4;
  uint uVar5;
  double local_38;
  double local_30;
  double local_28;
  
  uVar5 = (uint)(ushort)param_1->mAnmMatrixIdx;
  mtx::PSMTXCopy(param_2->mpNodeMtx + uVar5,&mDoMtx_stack_c::now);
  sVar4 = *(short *)(this + 0x7b0);
  sVar1 = *(short *)(this + 0x708);
  iVar3 = attr(this);
  fVar2 = d_a_obj_search::_4215 + *(float *)(iVar3 + 0x20);
  local_38 = (double)CONCAT44(0x43300000,(int)(short)(sVar1 - sVar4) ^ 0x80000000);
  local_38 = local_38 - d_a_obj_search::_4219;
  *(undefined2 *)(this + 0x7ae) = 0x2700;
  if (uVar5 == 6) {
    m_Do_mtx::mDoMtx_XrotM(&mDoMtx_stack_c::now,*(short *)(this + 0x70e));
    m_Do_mtx::mDoMtx_YrotM(&mDoMtx_stack_c::now,*(short *)(this + 0x70c));
  }
  else {
    if (uVar5 < 6) {
      if (uVar5 == 4) {
        m_Do_mtx::mDoMtx_YrotM(&mDoMtx_stack_c::now,*(short *)(this + 0x7ae));
        m_Do_mtx::mDoMtx_XrotM(&mDoMtx_stack_c::now,*(short *)(this + 0x7ac));
      }
      else {
        if (3 < uVar5) {
          m_Do_mtx::mDoMtx_XrotM(&mDoMtx_stack_c::now,*(short *)(this + 0x708));
          m_Do_mtx::mDoMtx_YrotM(&mDoMtx_stack_c::now,*(short *)(this + 0x706));
        }
      }
    }
    else {
      if (uVar5 < 8) {
        m_Do_mtx::mDoMtx_YrotM(&mDoMtx_stack_c::now,*(short *)(this + 0x7ae));
      }
    }
  }
  if (*(int *)(this + 0x290) != 2) {
    sVar4 = (short)(int)((float)local_38 * fVar2);
    if (uVar5 == 2) {
      iVar3 = attr(this);
      local_28 = (double)CONCAT44(0x43300000,(int)sVar4 ^ 0x80000000);
      local_30 = (double)CONCAT44(0x43300000,(int)*(short *)(this + 0x7aa) ^ 0x80000000);
      *(short *)(this + 0x7aa) =
           (short)(int)((float)(local_30 - d_a_obj_search::_4219) -
                       (float)(local_28 - d_a_obj_search::_4219) *
                       (d_a_obj_search::_4217 + *(float *)(iVar3 + 0x18)));
      m_Do_mtx::mDoMtx_XrotM(&mDoMtx_stack_c::now,*(short *)(this + 0x7aa));
    }
    else {
      if (uVar5 < 2) {
        if (uVar5 != 0) {
          iVar3 = attr(this);
          local_28 = (double)CONCAT44(0x43300000,(int)sVar4 ^ 0x80000000);
          local_30 = (double)CONCAT44(0x43300000,(int)*(short *)(this + 0x7a8) ^ 0x80000000);
          *(short *)(this + 0x7a8) =
               (short)(int)((float)(local_30 - d_a_obj_search::_4219) +
                           (float)(local_28 - d_a_obj_search::_4219) *
                           (d_a_obj_search::_4215 + *(float *)(iVar3 + 0x14)));
          m_Do_mtx::mDoMtx_XrotM(&mDoMtx_stack_c::now,*(short *)(this + 0x7a8));
        }
      }
      else {
        if (uVar5 < 4) {
          iVar3 = attr(this);
          local_30 = (double)CONCAT44(0x43300000,(int)sVar4 ^ 0x80000000);
          local_38 = (double)CONCAT44(0x43300000,(int)*(short *)(this + 0x7ac) ^ 0x80000000);
          *(short *)(this + 0x7ac) =
               (short)(int)((float)(local_38 - d_a_obj_search::_4219) +
                           (float)(local_30 - d_a_obj_search::_4219) *
                           (d_a_obj_search::_4216 + *(float *)(iVar3 + 0x1c)));
          m_Do_mtx::mDoMtx_XrotM(&mDoMtx_stack_c::now,*(short *)(this + 0x7ac));
        }
      }
    }
  }
  mtx::PSMTXCopy(&mDoMtx_stack_c::now,&J3DSys::mCurrentMtx);
  mtx::PSMTXCopy(&mDoMtx_stack_c::now,param_2->mpNodeMtx + uVar5);
  return;
}


/* __thiscall Act_c::modeSearchRndInit(void) */

void __thiscall Act_c::modeSearchRndInit(Act_c *this)

{
  return;
}


/* __thiscall Act_c::modeSearchRnd(void) */

void __thiscall Act_c::modeSearchRnd(Act_c *this)

{
  int iVar1;
  char cVar2;
  
  if (this[0x834] != (Act_c)0x0) {
    iVar1 = attr(this);
    if ((*(char *)(iVar1 + 0x38) != '\0') && (cVar2 = player_check(this), cVar2 != '\0')) {
      modeProc(this,0,5);
    }
  }
  *(undefined2 *)(this + 0x7b2) = *(undefined2 *)(this + 0x706);
  *(undefined2 *)(this + 0x7b4) = *(undefined2 *)(this + 0x70c);
  *(undefined2 *)(this + 0x7b0) = *(undefined2 *)(this + 0x708);
  iVar1 = attr(this);
  *(undefined2 *)(this + 0x706) = *(undefined2 *)(iVar1 + 8);
  iVar1 = attr(this);
  *(short *)(this + 0x708) =
       (short)(int)((float)((double)CONCAT44(0x43300000,(int)*(short *)(this + 0x708) ^ 0x80000000)
                           - d_a_obj_search::_4219) +
                   d_a_obj_search::_4237 * (d_a_obj_search::_4215 + *(float *)(iVar1 + 0x20)));
  *(short *)(this + 0x70c) = -*(short *)(this + 0x706);
  *(undefined2 *)(this + 0x70e) = *(undefined2 *)(this + 0x708);
  return;
}


/* __thiscall Act_c::modeSearchPathInit(void) */

void __thiscall Act_c::modeSearchPathInit(Act_c *this)

{
  char cVar1;
  
  cVar1 = is_path_info(this);
  if (cVar1 == '\0') {
    modeProc(this,0,0);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall Act_c::modeSearchPath(void) */

void __thiscall Act_c::modeSearchPath(Act_c *this)

{
  daPy_lk_c *pdVar1;
  short sVar2;
  int iVar3;
  fopAc_ac_c *pfVar4;
  fopAc_ac_c *pfVar5;
  int iVar6;
  char cVar7;
  short target;
  double dVar8;
  double dVar9;
  undefined2 local_e8 [2];
  float local_e4;
  float local_e0;
  float local_dc;
  float local_d8;
  undefined4 local_d4;
  cXyz local_d0;
  cXyz local_c4;
  cXyz cStack184;
  float local_ac;
  float local_a8;
  float local_a4;
  cXyz local_a0;
  cXyz cStack148;
  float local_88;
  float local_84;
  float local_80;
  cXyz local_7c;
  cXyz cStack112;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  cXyz local_4c;
  cXyz local_40;
  cXyz local_34;
  undefined4 local_28;
  uint uStack36;
  
  iVar3 = attr(this);
  uStack36 = (int)*(short *)(iVar3 + 2) ^ 0x80000000;
  local_28 = 0x43300000;
  d_lib::dLib_pathMove
            ((cXyz *)(this + 0x838),(byte *)(this + 0x844),*(dPath **)(this + 0x848),
             (float)((double)CONCAT44(0x43300000,uStack36) - d_a_obj_search::_4219),(undefined *)0x0
             ,(void *)0x0);
  if (this[0x834] != (Act_c)0x0) {
    local_e8[0] = 0xf3;
    pfVar4 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeForPName,local_e8);
    if ((*(int *)(this + 0x85c) == 0xff) || (pfVar4 == (fopAc_ac_c *)0x0)) {
      iVar3 = attr(this);
      if (*(char *)(iVar3 + 0x38) != '\0') {
        cVar7 = player_check(this);
        if (cVar7 == '\0') {
          *(undefined4 *)(this + 0x7a0) = 0;
        }
        else {
          if ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpDemoMgr)->mState != 1) {
            *(int *)(this + 0x7a0) = *(int *)(this + 0x7a0) + 1;
            iVar3 = attr(this);
            if ((int)*(short *)(iVar3 + 0x5e) < *(int *)(this + 0x7a0)) {
              modeProc(this,0,5);
              *(undefined4 *)(this + 0x7a0) = 0;
            }
          }
        }
      }
    }
    else {
      local_d4 = *(undefined4 *)(this + 0x84c);
      pfVar5 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,&local_d4);
      if (pfVar5 != (fopAc_ac_c *)0x0) {
        *(undefined2 *)&pfVar5[7].parent.parent.mLnTg.parent.parent.mpPrevNode =
             *(undefined2 *)(this + 0x7ac);
      }
      iVar3 = attr(this);
      if ((*(char *)(iVar3 + 0x39) != '\0') || (this[0x8d0] == (Act_c)0x4)) {
        modeProc(this,0,4);
        return;
      }
      iVar3 = attr(this);
      pdVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor;
      if (*(char *)(iVar3 + 0x3a) != '\0') {
        if (d_a_obj_search::init_4264 == '\0') {
          local_64 = d_a_obj_search::0_0;
          local_60 = d_a_obj_search::_4434;
          local_5c = d_a_obj_search::0_0;
          d_a_obj_search::pos_4262 = d_a_obj_search::0_0;
          DAT_803e434c = d_a_obj_search::_4434;
          DAT_803e4350 = d_a_obj_search::0_0;
          Runtime.PPCEABI.H::__register_global_object
                    (&d_a_obj_search::pos_4262,::cXyz::_cXyz,&d_a_obj_search::_4263);
          d_a_obj_search::init_4264 = '\x01';
        }
        local_34.x = d_a_obj_search::pos_4262;
        local_34.y = DAT_803e434c;
        local_34.z = DAT_803e4350;
        ::cXyz::operator__(&cStack112,&local_34,&(pdVar1->parent).parent.mCurrent.mPos);
        ::cXyz::operator__(&local_7c,&cStack112,(cXyz *)(this + 0x624));
        local_34.x = local_7c.x;
        local_34.y = local_7c.y;
        local_34.z = local_7c.z;
        *(undefined2 *)(this + 0x7b0) = *(undefined2 *)(this + 0x708);
        iVar3 = SComponent::cM_atan2s(local_7c.x,local_7c.z);
        sVar2 = *(short *)(this + 0x206);
        dVar9 = (double)(local_34.x * local_34.x + local_34.z * local_34.z);
        if ((double)d_a_obj_search::0_0 < dVar9) {
          dVar8 = 1.0 / SQRT(dVar9);
          dVar8 = d_a_obj_search::_4435 * dVar8 * (d_a_obj_search::_4436 - dVar9 * dVar8 * dVar8);
          dVar8 = d_a_obj_search::_4435 * dVar8 * (d_a_obj_search::_4436 - dVar9 * dVar8 * dVar8);
          local_d8 = (float)(dVar9 * d_a_obj_search::_4435 * dVar8 *
                                     (d_a_obj_search::_4436 - dVar9 * dVar8 * dVar8));
          dVar9 = (double)local_d8;
        }
        iVar6 = SComponent::cM_atan2s(local_34.y,(float)dVar9);
        SComponent::cLib_addCalcAngleS2
                  ((short *)(this + *(int *)(this + 0x830) * 6 + 0x708),(short)iVar3 - sVar2,10,
                   0x400);
        SComponent::cLib_addCalcAngleS2
                  ((short *)(this + *(int *)(this + 0x830) * 6 + 0x706),(short)iVar6,10,0x400);
        return;
      }
      if (this[0x8d0] == (Act_c)0x2) {
        if (d_a_obj_search::init_4270 == '\0') {
          local_88 = d_a_obj_search::0_0;
          local_84 = d_a_obj_search::_4434;
          local_80 = d_a_obj_search::0_0;
          d_a_obj_search::pos_4268 = d_a_obj_search::0_0;
          DAT_803e4364 = d_a_obj_search::_4434;
          DAT_803e4368 = d_a_obj_search::0_0;
          Runtime.PPCEABI.H::__register_global_object
                    (&d_a_obj_search::pos_4268,::cXyz::_cXyz,&d_a_obj_search::_4269);
          d_a_obj_search::init_4270 = '\x01';
        }
        local_40.x = d_a_obj_search::pos_4268;
        local_40.y = DAT_803e4364;
        local_40.z = DAT_803e4368;
        ::cXyz::operator__(&cStack148,&local_40,&(pdVar1->parent).parent.mCurrent.mPos);
        ::cXyz::operator__(&local_a0,&cStack148,(cXyz *)(this + 0x624));
        local_40.x = local_a0.x;
        local_40.y = local_a0.y;
        local_40.z = local_a0.z;
        *(undefined2 *)(this + 0x7b0) = *(undefined2 *)(this + 0x708);
        iVar3 = SComponent::cM_atan2s(local_a0.x,local_a0.z);
        sVar2 = *(short *)(this + 0x206);
        dVar9 = (double)(local_40.x * local_40.x + local_40.z * local_40.z);
        if ((double)d_a_obj_search::0_0 < dVar9) {
          dVar8 = 1.0 / SQRT(dVar9);
          dVar8 = d_a_obj_search::_4435 * dVar8 * (d_a_obj_search::_4436 - dVar9 * dVar8 * dVar8);
          dVar8 = d_a_obj_search::_4435 * dVar8 * (d_a_obj_search::_4436 - dVar9 * dVar8 * dVar8);
          local_dc = (float)(dVar9 * d_a_obj_search::_4435 * dVar8 *
                                     (d_a_obj_search::_4436 - dVar9 * dVar8 * dVar8));
          dVar9 = (double)local_dc;
        }
        iVar6 = SComponent::cM_atan2s(local_40.y,(float)dVar9);
        SComponent::cLib_addCalcAngleS2
                  ((short *)(this + *(int *)(this + 0x830) * 6 + 0x708),(short)iVar3 - sVar2,10,
                   0x400);
        SComponent::cLib_addCalcAngleS2
                  ((short *)(this + *(int *)(this + 0x830) * 6 + 0x706),(short)iVar6,10,0x400);
        return;
      }
      if (this[0x8d0] == (Act_c)0x3) {
        if (d_a_obj_search::init_4276 == '\0') {
          local_ac = d_a_obj_search::0_0;
          local_a8 = d_a_obj_search::_4434;
          local_a4 = d_a_obj_search::0_0;
          d_a_obj_search::pos_4274 = d_a_obj_search::0_0;
          DAT_803e437c = d_a_obj_search::_4434;
          DAT_803e4380 = d_a_obj_search::0_0;
          Runtime.PPCEABI.H::__register_global_object
                    (&d_a_obj_search::pos_4274,::cXyz::_cXyz,&d_a_obj_search::_4275);
          d_a_obj_search::init_4276 = '\x01';
        }
        local_4c.x = d_a_obj_search::pos_4274;
        local_4c.y = DAT_803e437c;
        local_4c.z = DAT_803e4380;
        ::cXyz::operator__(&cStack184,&local_4c,&(pfVar4->mCurrent).mPos);
        ::cXyz::operator__(&local_c4,&cStack184,(cXyz *)(this + 0x624));
        local_4c.x = local_c4.x;
        local_4c.y = local_c4.y;
        local_4c.z = local_c4.z;
        *(undefined2 *)(this + 0x7b0) = *(undefined2 *)(this + 0x708);
        iVar3 = SComponent::cM_atan2s(local_c4.x,local_c4.z);
        sVar2 = *(short *)(this + 0x206);
        dVar9 = (double)(local_4c.x * local_4c.x + local_4c.z * local_4c.z);
        if ((double)d_a_obj_search::0_0 < dVar9) {
          dVar8 = 1.0 / SQRT(dVar9);
          dVar8 = d_a_obj_search::_4435 * dVar8 * (d_a_obj_search::_4436 - dVar9 * dVar8 * dVar8);
          dVar8 = d_a_obj_search::_4435 * dVar8 * (d_a_obj_search::_4436 - dVar9 * dVar8 * dVar8);
          local_e0 = (float)(dVar9 * d_a_obj_search::_4435 * dVar8 *
                                     (d_a_obj_search::_4436 - dVar9 * dVar8 * dVar8));
          dVar9 = (double)local_e0;
        }
        iVar6 = SComponent::cM_atan2s(local_4c.y,(float)dVar9);
        SComponent::cLib_addCalcAngleS2
                  ((short *)(this + *(int *)(this + 0x830) * 6 + 0x708),(short)iVar3 - sVar2,10,
                   0x400);
        SComponent::cLib_addCalcAngleS2
                  ((short *)(this + *(int *)(this + 0x830) * 6 + 0x706),(short)iVar6,10,0x400);
        return;
      }
    }
  }
  *(undefined4 *)(this + 0x60c) = *(undefined4 *)(this + 0x838);
  *(undefined4 *)(this + 0x610) = *(undefined4 *)(this + 0x83c);
  *(undefined4 *)(this + 0x614) = *(undefined4 *)(this + 0x840);
  ::cXyz::operator__(&local_d0,(cXyz *)(this + 0x60c),(cXyz *)(this + 0x624));
  local_58 = local_d0.x;
  local_54 = local_d0.y;
  local_50 = local_d0.z;
  *(undefined2 *)(this + 0x7b0) = *(undefined2 *)(this + 0x708);
  *(undefined2 *)(this + 0x7b2) = *(undefined2 *)(this + 0x706);
  *(undefined2 *)(this + 0x7b4) = *(undefined2 *)(this + 0x70c);
  iVar3 = SComponent::cM_atan2s(local_d0.x,local_d0.z);
  sVar2 = (short)iVar3 - *(short *)(this + 0x206);
  dVar9 = (double)(local_58 * local_58 + local_50 * local_50);
  if ((double)d_a_obj_search::0_0 < dVar9) {
    dVar8 = 1.0 / SQRT(dVar9);
    dVar8 = d_a_obj_search::_4435 * dVar8 * (d_a_obj_search::_4436 - dVar9 * dVar8 * dVar8);
    dVar8 = d_a_obj_search::_4435 * dVar8 * (d_a_obj_search::_4436 - dVar9 * dVar8 * dVar8);
    local_e4 = (float)(dVar9 * d_a_obj_search::_4435 * dVar8 *
                               (d_a_obj_search::_4436 - dVar9 * dVar8 * dVar8));
    dVar9 = (double)local_e4;
  }
  iVar3 = SComponent::cM_atan2s(local_54,(float)dVar9);
  target = (short)iVar3;
  iVar3 = attr(this);
  if (*(char *)(iVar3 + 0x3e) == '\0') {
    if (d_s_play::g_regHIO.mChild[12].mShorts[4] == 0) {
      SComponent::cLib_addCalcAngleS2((short *)(this + 0x708),sVar2,0x1e,0x400);
      SComponent::cLib_addCalcAngleS2((short *)(this + 0x706),target,0x1e,0x400);
      *(undefined2 *)(this + 0x70e) = *(undefined2 *)(this + 0x708);
    }
    else {
      *(short *)(this + 0x708) = sVar2;
      *(short *)(this + 0x706) = target;
      *(undefined2 *)(this + 0x70e) = *(undefined2 *)(this + 0x708);
    }
  }
  else {
    SComponent::cLib_addCalcAngleS2((short *)(this + 0x708),sVar2,0x1e,0x400);
    SComponent::cLib_addCalcAngleS2((short *)(this + 0x706),target,0x1e,0x400);
    *(undefined2 *)(this + 0x70e) = *(undefined2 *)(this + 0x708);
  }
  iVar3 = attr(this);
  *(short *)(this + 0x70c) =
       (short)(int)(d_a_obj_search::_4437 *
                   (float)((double)CONCAT44(0x43300000,(int)*(short *)(iVar3 + 0x3c) ^ 0x80000000) -
                          d_a_obj_search::_4219));
  return;
}


/* __thiscall Act_c::modeStopInit(void) */

void __thiscall Act_c::modeStopInit(Act_c *this)

{
  *(undefined2 *)(this + 0x706) = 0x2300;
  *(undefined2 *)(this + 0x70c) = 0xdd00;
  return;
}


/* __thiscall Act_c::modeStop(void) */

void __thiscall Act_c::modeStop(Act_c *this)

{
  return;
}


/* __thiscall Act_c::modeToSearchInit(void) */

void __thiscall Act_c::modeToSearchInit(Act_c *this)

{
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall Act_c::modeToSearch(void) */

void __thiscall Act_c::modeToSearch(Act_c *this)

{
  short sVar1;
  short sVar2;
  
  sVar1 = SComponent::cLib_addCalcAngleS
                    ((short *)(this + 0x706),*(short *)(this + 0x7b2),10,0x200,0x100);
  sVar2 = SComponent::cLib_addCalcAngleS
                    ((short *)(this + 0x70c),*(short *)(this + 0x7b4),10,0x200,0x100);
  if ((sVar1 < 0x100) && (sVar2 < 0x100)) {
    modeProc(this,0,1);
  }
  return;
}


/* __thiscall Act_c::modeToStopInit(void) */

void __thiscall Act_c::modeToStopInit(Act_c *this)

{
  int iVar1;
  sbyte sVar2;
  
  *(undefined2 *)(this + 0x7b0) = *(undefined2 *)(this + 0x708);
  iVar1 = dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x201);
  if (iVar1 != 0) {
    sVar2 = d_com_inf_game::dComIfGp_getReverb((int)(char)this[0x20a]);
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x6939,(cXyz *)(this + 0x260),0,sVar2,d_a_obj_search::_4215,
               d_a_obj_search::_4215,d_a_obj_search::_4478,d_a_obj_search::_4478,0);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall Act_c::modeToStop(void) */

void __thiscall Act_c::modeToStop(Act_c *this)

{
  int iVar1;
  bool bVar6;
  fopAc_ac_c *pfVar2;
  char *__s1;
  int iVar3;
  sbyte sVar7;
  short sVar5;
  int iVar4;
  undefined4 local_28 [3];
  
  iVar1 = dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x201);
  if (((iVar1 == 0) || (iVar1 = attr(this), *(char *)(iVar1 + 0x42) != '\0')) &&
     (*(int *)(this + 0x85c) == 0xff)) {
    if (*(short *)(this + 0xf8) == 2) {
      *(undefined2 *)(this + 0x77e) = 0xff;
      iVar1 = dEvent_manager_c::getMyStaffId
                        (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,"Search",
                         (fopAc_ac_c *)0x0,0);
      bVar6 = dEvent_manager_c::endCheckOld
                        (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,"Search_Light_Up");
      if (bVar6 == false) {
        local_28[0] = *(undefined4 *)(this + 0x84c);
        pfVar2 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,local_28);
        if ((pfVar2 != (fopAc_ac_c *)0x0) &&
           (*(short *)((int)&pfVar2[1].parent.parent.mPi.parent.parent.mpNextNode + 2) < 5)) {
          *(undefined2 *)((int)&pfVar2[1].parent.parent.mPi.parent.parent.mpNextNode + 2) = 5;
        }
        __s1 = dEvent_manager_c::getMyNowCutName
                         (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,iVar1);
        iVar3 = MSL_C.PPCEABI.bare.H::strcmp(__s1,"BK_FIND");
        if (iVar3 == 0) {
          dEvent_manager_c::cutEnd(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,iVar1);
        }
        iVar3 = MSL_C.PPCEABI.bare.H::strcmp(__s1,"LIGHT_UP_SOUND");
        if (iVar3 == 0) {
          sVar7 = d_com_inf_game::dComIfGp_getReverb((int)(char)this[0x20a]);
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x6939,(cXyz *)(this + 0x260),0,sVar7,
                     d_a_obj_search::_4215,d_a_obj_search::_4215,d_a_obj_search::_4478,
                     d_a_obj_search::_4478,0);
          dEvent_manager_c::cutEnd(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,iVar1);
        }
        iVar3 = MSL_C.PPCEABI.bare.H::strcmp(__s1,"LIGHT_UP");
        if (iVar3 == 0) {
          sVar5 = SComponent::cLib_addCalcAngleS((short *)(this + 0x706),0x2300,0x1e,0x300,0x10);
          iVar3 = MSL_C.PPCEABI.bare.H::abs((int)sVar5);
          sVar5 = SComponent::cLib_addCalcAngleS((short *)(this + 0x70c),-0x2300,0x1e,0x300,0x10);
          iVar4 = MSL_C.PPCEABI.bare.H::abs((int)sVar5);
          if ((iVar3 < 0x100) && (iVar4 < 0x100)) {
            smoke_set(this,d_a_obj_search::_4548,10);
            dEvent_manager_c::cutEnd(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,iVar1);
          }
        }
      }
      else {
        d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mStateFlags =
             d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mStateFlags | 8;
        dSv_event_c::onEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x201);
        modeProc(this,0,2);
      }
    }
    else {
      f_op_actor_mng::fopAcM_orderOtherEvent2
                ((fopAc_ac_c *)this,"Search_Light_Up",RequiresPartnerPcId,0xffff);
    }
  }
  else {
    sVar5 = SComponent::cLib_addCalcAngleS((short *)(this + 0x706),0x2300,0x14,0x200,0x10);
    iVar1 = MSL_C.PPCEABI.bare.H::abs((int)sVar5);
    sVar5 = SComponent::cLib_addCalcAngleS((short *)(this + 0x70c),-0x2300,0x14,0x200,0x10);
    iVar3 = MSL_C.PPCEABI.bare.H::abs((int)sVar5);
    if ((iVar1 < 0x100) && (iVar3 < 0x100)) {
      smoke_set(this,d_a_obj_search::_4548,10);
      modeProc(this,0,2);
    }
  }
  return;
}


/* __thiscall Act_c::modeFindInit(void) */

void __thiscall Act_c::modeFindInit(Act_c *this)

{
  if (*(int *)(this + 0x85c) == 0xff) {
    if (this[0x8d0] != (Act_c)0x0) {
      dSv_event_c::onEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x340);
    }
    if (*(short *)(this + 0xf8) != 2) {
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x834,(cXyz *)0x0,0,0,d_a_obj_search::_4215,
                 d_a_obj_search::_4215,d_a_obj_search::_4478,d_a_obj_search::_4478,0);
    }
    *(undefined2 *)(this + 0x7b2) = *(undefined2 *)(this + 0x706);
    *(undefined2 *)(this + 0x7b4) = *(undefined2 *)(this + 0x70c);
    *(undefined2 *)(this + 0x7b0) = *(undefined2 *)(this + 0x708);
  }
  else {
    modeProc(this,0,6);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall Act_c::modeFind(void) */

void __thiscall Act_c::modeFind(Act_c *this)

{
  daPy_lk_c *pdVar1;
  short sVar2;
  short target;
  int iVar3;
  bool bVar4;
  double dVar5;
  double dVar6;
  cXyz local_54;
  cXyz cStack72;
  float local_3c;
  float local_38;
  float local_34;
  cXyz local_30 [2];
  
  dEvent_manager_c::getEventIdx
            (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,"Search_Light_Find",0xff);
  dEvent_manager_c::getEventIdx
            (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,"Search_Light_Find_With_Barrel",
             0xff);
  dEvent_manager_c::getEventIdx
            (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,"Search_Light_Find_Wall",0xff);
  pdVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor;
  player_check(this);
  iVar3 = attr(this);
  *(undefined2 *)(this + 0x78c) = *(undefined2 *)(iVar3 + 0x5c);
  iVar3 = attr(this);
  *(undefined2 *)(this + 0x78e) = *(undefined2 *)(iVar3 + 0x5c);
  if (d_a_obj_search::init_4569 == '\0') {
    local_3c = d_a_obj_search::0_0;
    local_38 = d_a_obj_search::_4434;
    local_34 = d_a_obj_search::0_0;
    d_a_obj_search::pos_4567 = d_a_obj_search::0_0;
    DAT_803e4394 = d_a_obj_search::_4434;
    DAT_803e4398 = d_a_obj_search::0_0;
    Runtime.PPCEABI.H::__register_global_object
              (&d_a_obj_search::pos_4567,::cXyz::_cXyz,&d_a_obj_search::_4568);
    d_a_obj_search::init_4569 = '\x01';
  }
  local_30[0].x = d_a_obj_search::pos_4567;
  local_30[0].y = DAT_803e4394;
  local_30[0].z = DAT_803e4398;
  ::cXyz::operator__(&cStack72,local_30,&(pdVar1->parent).parent.mCurrent.mPos);
  ::cXyz::operator__(&local_54,&cStack72,(cXyz *)(this + *(int *)(this + 0x830) * 0xc + 0x624));
  local_30[0].x = local_54.x;
  local_30[0].y = local_54.y;
  local_30[0].z = local_54.z;
  *(undefined2 *)(this + 0x7b0) = *(undefined2 *)(this + 0x708);
  iVar3 = SComponent::cM_atan2s(local_54.x,local_54.z);
  sVar2 = (short)iVar3 - *(short *)(this + 0x206);
  dVar6 = (double)(local_30[0].x * local_30[0].x + local_30[0].z * local_30[0].z);
  if ((double)d_a_obj_search::0_0 < dVar6) {
    dVar5 = 1.0 / SQRT(dVar6);
    dVar5 = d_a_obj_search::_4435 * dVar5 * (d_a_obj_search::_4436 - dVar6 * dVar5 * dVar5);
    dVar5 = d_a_obj_search::_4435 * dVar5 * (d_a_obj_search::_4436 - dVar6 * dVar5 * dVar5);
    dVar6 = (double)(float)(dVar6 * d_a_obj_search::_4435 * dVar5 *
                                    (d_a_obj_search::_4436 - dVar6 * dVar5 * dVar5));
  }
  iVar3 = SComponent::cM_atan2s(local_30[0].y,(float)dVar6);
  target = (short)iVar3;
  if (*(int *)(this + 0x830) == 0) {
    *(short *)(this + 0x70e) = sVar2;
  }
  else {
    target = -target;
    sVar2 = sVar2 + -0x8000;
    *(short *)(this + 0x708) = sVar2;
  }
  SComponent::cLib_addCalcAngleS2
            ((short *)(this + *(int *)(this + 0x830) * 6 + 0x708),sVar2,10,0x400);
  SComponent::cLib_addCalcAngleS2
            ((short *)(this + *(int *)(this + 0x830) * 6 + 0x706),target,10,0x400);
  if (*(short *)(this + 0xf8) == 2) {
    iVar3 = dEvent_manager_c::getMyStaffId
                      (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,"Search",
                       (fopAc_ac_c *)0x0,0);
    bVar4 = dEvent_manager_c::endCheckOld
                      (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,"Search_Light_Find");
    if (((bVar4 == false) &&
        (bVar4 = dEvent_manager_c::endCheckOld
                           (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,
                            "Search_Light_Find_With_Barrel"), bVar4 == false)) &&
       (bVar4 = dEvent_manager_c::endCheckOld
                          (&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,
                           "Search_Light_Find_Wall"), bVar4 == false)) {
      if (((d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8 & 1U) == 0) &&
         ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8 & 0x100U) == 0)) {
        pdVar1->field_0x304 = 3;
        pdVar1->field_0x30c = 0;
        sVar2 = *(short *)(this + *(int *)(this + 0x830) * 6 + 0x708) + *(short *)(this + 0x206);
        if (*(int *)(this + 0x830) == 0) {
          sVar2 = sVar2 + -0x8000;
        }
        SComponent::cLib_addCalcAngleS2((short *)(this + 0x7e0),sVar2,4,0x400);
        (*(code *)pdVar1->vtbl->setPlayerPosAndAngle1)
                  (pdVar1,&(pdVar1->parent).parent.mCurrent,(int)*(short *)(this + 0x7e0));
        sVar2 = SComponent::cLib_distanceAngleS(sVar2,*(short *)(this + 0x7e0));
        if (sVar2 < 0x500) {
          pdVar1->field_0x304 = 2;
          pdVar1->mDemoMode = 1;
        }
      }
      dEvent_manager_c::cutEnd(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEventMgr,iVar3);
      return;
    }
    JAIZelBasic::seStop(JAIZelBasic::zel_basic,0x834,0x14);
    iVar3 = attr(this);
    if (*(char *)(iVar3 + 0x43) == '\0') {
      d_com_inf_game::dComIfGp_setNextStage("majroom",0,0,0xff,d_a_obj_search::0_0,0,1,0);
    }
    else {
      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mStateFlags =
           d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mStateFlags | 8;
      modeProc(this,0,1);
    }
  }
  else {
    iVar3 = (*(code *)pdVar1->vtbl->checkPlayerFly)(pdVar1);
    if (iVar3 == 0) {
      if (d_a_obj_search::0_0 <= (pdVar1->parent).field_0x2b0) {
        if ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8 & 1U) == 0) {
          f_op_actor_mng::fopAcM_orderOtherEvent2
                    ((fopAc_ac_c *)this,"Search_Light_Find",RequiresPartnerPcId,0xffff);
        }
        else {
          f_op_actor_mng::fopAcM_orderOtherEvent2
                    ((fopAc_ac_c *)this,"Search_Light_Find_Wall",RequiresPartnerPcId,0xffff);
        }
      }
      else {
        f_op_actor_mng::fopAcM_orderOtherEvent2
                  ((fopAc_ac_c *)this,"Search_Light_Find_With_Barrel",RequiresPartnerPcId,0xffff);
      }
    }
  }
  return;
}


/* __thiscall Act_c::modeFind2ndInit(void) */

void __thiscall Act_c::modeFind2ndInit(Act_c *this)

{
  *(undefined2 *)(this + 0x7b2) = *(undefined2 *)(this + 0x706);
  *(undefined2 *)(this + 0x7b4) = *(undefined2 *)(this + 0x70c);
  *(undefined2 *)(this + 0x7b0) = *(undefined2 *)(this + 0x708);
  dSv_info_c::onSwitch
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo,*(int *)(this + 0x85c),
             (int)(char)dStage_roomControl_c::mStayNo);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall Act_c::modeFind2nd(void) */

void __thiscall Act_c::modeFind2nd(Act_c *this)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  daPy_lk_c *this_00;
  short target;
  short target_00;
  int iVar4;
  char cVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  double dVar9;
  double dVar10;
  cXyz local_64;
  cXyz local_58;
  cXyz cStack76;
  float local_40;
  float local_3c;
  float local_38;
  cXyz local_34;
  cXyz local_28;
  
  this_00 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor;
  player_check(this);
  if (d_a_obj_search::init_4680 == '\0') {
    local_40 = d_a_obj_search::0_0;
    local_3c = d_a_obj_search::_4434;
    local_38 = d_a_obj_search::0_0;
    d_a_obj_search::pos_4678 = d_a_obj_search::0_0;
    DAT_803e43ac = d_a_obj_search::_4434;
    DAT_803e43b0 = d_a_obj_search::0_0;
    Runtime.PPCEABI.H::__register_global_object
              (&d_a_obj_search::pos_4678,::cXyz::_cXyz,&d_a_obj_search::_4679);
    d_a_obj_search::init_4680 = '\x01';
  }
  local_28.x = d_a_obj_search::pos_4678;
  local_28.y = DAT_803e43ac;
  local_28.z = DAT_803e43b0;
  ::cXyz::operator__(&cStack76,&local_28,&(this_00->parent).parent.mCurrent.mPos);
  ::cXyz::operator__(&local_58,&cStack76,(cXyz *)(this + *(int *)(this + 0x830) * 0xc + 0x624));
  local_28.x = local_58.x;
  local_28.y = local_58.y;
  local_28.z = local_58.z;
  *(undefined2 *)(this + 0x7b0) = *(undefined2 *)(this + 0x708);
  iVar4 = SComponent::cM_atan2s(local_58.x,local_58.z);
  target = (short)iVar4 - *(short *)(this + 0x206);
  dVar10 = (double)(local_28.x * local_28.x + local_28.z * local_28.z);
  if ((double)d_a_obj_search::0_0 < dVar10) {
    dVar9 = 1.0 / SQRT(dVar10);
    dVar9 = d_a_obj_search::_4435 * dVar9 * (d_a_obj_search::_4436 - dVar10 * dVar9 * dVar9);
    dVar9 = d_a_obj_search::_4435 * dVar9 * (d_a_obj_search::_4436 - dVar10 * dVar9 * dVar9);
    dVar10 = (double)(float)(dVar10 * d_a_obj_search::_4435 * dVar9 *
                                      (d_a_obj_search::_4436 - dVar10 * dVar9 * dVar9));
  }
  iVar4 = SComponent::cM_atan2s(local_28.y,(float)dVar10);
  target_00 = (short)iVar4;
  uVar8 = SEXT24(target_00);
  bVar3 = false;
  uVar6 = SEXT24((short)(d_s_play::g_regHIO.mChild[12].mShorts[0] + 26000));
  uVar7 = SEXT24((short)(d_s_play::g_regHIO.mChild[12].mShorts[1] + -10000));
  uVar1 = ((int)uVar7 >> 0x1f) + ((uint)(uVar8 <= uVar7) - ((int)uVar8 >> 0x1f)) & 0xff;
  uVar2 = ((int)uVar8 >> 0x1f) + ((uint)(uVar6 <= uVar8) - ((int)uVar6 >> 0x1f)) & 0xff;
  if ((uVar2 != 0) && ((int)uVar8 < (int)uVar6)) {
    target_00 = d_s_play::g_regHIO.mChild[12].mShorts[0] + 26000;
  }
  if ((uVar1 != 0) && ((int)uVar7 < (int)target_00)) {
    target_00 = d_s_play::g_regHIO.mChild[12].mShorts[1] + -10000;
  }
  if ((uVar2 != 0) || (uVar1 != 0)) {
    bVar3 = true;
  }
  ::daPy_py_c::getHeadTopPos(&local_64,&this_00->parent);
  local_34.x = local_64.x;
  local_34.y = local_64.y;
  local_34.z = local_64.z;
  ::dBgS_LinChk::Set((dBgS_LinChk *)(this + 0x864),
                     (cXyz *)(this + *(int *)(this + 0x830) * 0xc + 0x624),&local_34,
                     (fopAc_ac_c *)this);
  cVar5 = cBgS::LineCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                          (cBgS_LinChk *)(this + 0x864));
  if (cVar5 != '\0') {
    bVar3 = true;
  }
  if (bVar3) {
    modeProc(this,0,1);
  }
  if (*(int *)(this + 0x830) == 0) {
    *(short *)(this + 0x70e) = target;
  }
  else {
    target_00 = -target_00;
    target = target + -0x8000;
    *(short *)(this + 0x708) = target;
  }
  SComponent::cLib_addCalcAngleS2
            ((short *)(this + *(int *)(this + 0x830) * 6 + 0x708),target,10,0x400);
  SComponent::cLib_addCalcAngleS2
            ((short *)(this + *(int *)(this + 0x830) * 6 + 0x706),target_00,10,0x400);
  return;
}


/* __thiscall Act_c::modeSearchBdkInit(void) */

void __thiscall Act_c::modeSearchBdkInit(Act_c *this)

{
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x800ffe58) */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall Act_c::modeSearchBdk(void) */

void __thiscall Act_c::modeSearchBdk(Act_c *this)

{
  bool bVar1;
  fopAc_ac_c *pfVar2;
  uint uVar3;
  short sVar4;
  int iVar5;
  Act_c AVar7;
  char cVar8;
  int iVar6;
  undefined4 uVar9;
  double dVar10;
  undefined8 in_f31;
  double dVar11;
  float fVar12;
  fopAc_ac_c *local_c0;
  cXyz local_bc;
  float local_b0;
  float local_ac;
  float local_a8;
  cXyz local_a4;
  cXyz cStack152;
  float local_8c;
  float local_88;
  float local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  cXyz local_68;
  float local_5c;
  float local_58;
  float local_54;
  cXyz local_50;
  float local_44;
  float local_40;
  float local_3c;
  double local_38;
  double local_30;
  undefined auStack8 [8];
  
  uVar9 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  iVar5 = f_op_actor_mng::fopAcM_SearchByName(0xf0,&local_c0);
  pfVar2 = local_c0;
  if ((iVar5 != 0) && (local_c0 != (fopAc_ac_c *)0x0)) {
    dVar11 = (double)d_s_play::g_regHIO.mChild[12].mFloats[0];
    local_44 = (local_c0->mCurrent).mPos.x;
    local_3c = (local_c0->mCurrent).mPos.z;
    local_40 = (local_c0->mCurrent).mPos.y + d_s_play::g_regHIO.mChild[12].mFloats[2];
    bVar1 = true;
    *(float *)(this + 0x8d4) = d_a_obj_search::_4942;
    *(float *)(this + 0x8d8) = d_a_obj_search::_4943;
    *(float *)(this + 0x8dc) = d_a_obj_search::_4944;
    *(float *)(this + 0x8e8) = d_a_obj_search::_4945 + d_s_play::g_regHIO.mChild[8].mFloats[0];
    *(float *)(this + 0x8e4) = d_a_obj_search::_4946 + d_s_play::g_regHIO.mChild[8].mFloats[5];
    *(short *)(this + 0x8ec) = d_s_play::g_regHIO.mChild[8].mShorts[0] + 0x3500;
    *(short *)(this + 0x8e0) = d_s_play::g_regHIO.mChild[8].mShorts[1];
    ::cXyz::operator__(&local_68,(cXyz *)(this + 0x8d4),&(local_c0->mCurrent).mPos);
    local_bc.x = local_68.x;
    local_bc.y = d_a_obj_search::0_0;
    local_bc.z = local_68.z;
    mtx::PSVECSquareMag(&local_bc);
    local_74 = *(undefined4 *)(this + 0x8d4);
    local_70 = *(undefined4 *)(this + 0x8d8);
    local_6c = *(undefined4 *)(this + 0x8dc);
    AVar7 = (Act_c)d_lib::dLib_checkActorInFan
                             ((double)*(float *)(this + 0x8e4),(double)d_a_obj_search::_4947,
                              &local_74,local_c0,(int)*(short *)(this + 0x8e0),
                              (int)*(short *)(this + 0x8ec));
    this[0x8ee] = AVar7;
    local_80 = *(undefined4 *)(this + 0x8d4);
    local_7c = *(undefined4 *)(this + 0x8d8);
    local_78 = *(undefined4 *)(this + 0x8dc);
    cVar8 = d_lib::dLib_checkActorInCircle
                      ((double)*(float *)(this + 0x8e8),(double)d_a_obj_search::_4943,&local_80,
                       local_c0);
    if (cVar8 != '\0') {
      this[0x8ee] = (Act_c)0x0;
    }
    switch(*(undefined2 *)((int)&pfVar2[1].parent.parent.mLnTg.parent.parent.mpPrevNode + 2)) {
    case 0:
    case 1:
    case 7:
      if (this[0x8ee] == (Act_c)0x0) {
        bVar1 = false;
      }
      else {
        dVar11 = (double)(float)(dVar11 + (double)d_a_obj_search::_4949);
        local_40 = local_40 + d_a_obj_search::_4434;
      }
      break;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 8:
    case 9:
      if (this[0x8ee] == (Act_c)0x0) {
        bVar1 = false;
      }
      else {
        dVar11 = (double)(float)(dVar11 + (double)d_a_obj_search::_4947);
        local_40 = local_40 + d_a_obj_search::_4948;
      }
      break;
    case 10:
      sVar4 = *(short *)&pfVar2[1].parent.parent.mLnTg.parent.parent.mpData;
      if (sVar4 == 8) {
        iVar5 = d_a_nh::cLib_calcTimer(this + 0x904);
        if (iVar5 == 0) {
          bVar1 = false;
        }
        else {
          local_44 = *(float *)(this + 0x8f4);
          local_40 = *(float *)(this + 0x8f8);
          local_3c = *(float *)(this + 0x8fc);
        }
      }
      else {
        if (sVar4 == 7) {
          fVar12 = SComponent::cM_rndF(d_a_obj_search::_4434);
          local_38 = (double)CONCAT44(0x43300000,
                                      (int)d_s_play::g_regHIO.mChild[8].mShorts[4] ^ 0x80000000);
          iVar5 = (int)((float)(local_38 - d_a_obj_search::_4219) + d_a_obj_search::_4950 + fVar12);
          local_30 = (double)(longlong)iVar5;
          *(int *)(this + 0x904) = iVar5;
          local_44 = *(float *)(this + 0x8f4);
          local_40 = *(float *)(this + 0x8f8);
          local_3c = *(float *)(this + 0x8fc);
        }
        else {
          if (sVar4 < 6) {
            if (sVar4 < 5) {
              bVar1 = false;
            }
            else {
              dVar11 = (double)(float)(dVar11 + (double)d_a_obj_search::_4434);
              local_40 = (float)((double)local_40 + (double)d_a_obj_search::_4434);
            }
          }
          else {
            *(float *)(this + 0x8f4) = local_44;
            *(float *)(this + 0x8f8) = local_40;
            *(float *)(this + 0x8fc) = local_3c;
          }
        }
      }
      break;
    default:
      bVar1 = false;
      break;
    case 0xf:
      bVar1 = false;
    }
    if (this == (Act_c *)0x0) {
      uVar3 = 0xffffffff;
    }
    else {
      uVar3 = *(uint *)(this + 4);
    }
    sVar4 = 1;
    if ((uVar3 & 1) == 1) {
      sVar4 = -1;
    }
    if (bVar1) {
      SComponent::cLib_addCalc2
                ((float *)(this + 0x7d4),(float)dVar11,d_a_obj_search::_4951,d_a_obj_search::_4434);
      *(float *)(this + 0x7d8) = d_a_obj_search::_4952 + d_s_play::g_regHIO.mChild[12].mFloats[1];
      *(short *)(this + 0x7de) = (d_s_play::g_regHIO.mChild[12].mShorts[0] + 0x150) * sVar4;
      *(float *)(this + 0x7bc) = local_44;
      *(float *)(this + 0x7c0) = local_40;
      *(float *)(this + 0x7c4) = local_3c;
      d_lib::dLib_setCirclePath((dLib_circle_path_c *)(this + 0x7bc));
      if (d_a_obj_search::init_4834 == '\0') {
        local_8c = d_a_obj_search::0_0;
        local_88 = d_a_obj_search::_4434;
        local_84 = d_a_obj_search::0_0;
        d_a_obj_search::pos_4832 = d_a_obj_search::0_0;
        DAT_803e43c4 = d_a_obj_search::_4434;
        DAT_803e43c8 = d_a_obj_search::0_0;
        Runtime.PPCEABI.H::__register_global_object
                  (&d_a_obj_search::pos_4832,::cXyz::_cXyz,&d_a_obj_search::_4833);
        d_a_obj_search::init_4834 = '\x01';
      }
      local_50.x = d_a_obj_search::pos_4832;
      local_50.y = DAT_803e43c4;
      local_50.z = DAT_803e43c8;
      ::cXyz::operator__(&cStack152,&local_50,(cXyz *)(this + 0x7c8));
      ::cXyz::operator__(&local_a4,&cStack152,(cXyz *)(this + 0x624));
      local_50.x = local_a4.x;
      local_50.y = local_a4.y;
      local_50.z = local_a4.z;
      *(undefined2 *)(this + 0x7b0) = *(undefined2 *)(this + 0x708);
      iVar5 = SComponent::cM_atan2s(local_a4.x,local_a4.z);
      sVar4 = *(short *)(this + 0x206);
      dVar11 = (double)(local_50.x * local_50.x + local_50.z * local_50.z);
      if ((double)d_a_obj_search::0_0 < dVar11) {
        dVar10 = 1.0 / SQRT(dVar11);
        dVar10 = d_a_obj_search::_4435 * dVar10 * (d_a_obj_search::_4436 - dVar11 * dVar10 * dVar10)
        ;
        dVar10 = d_a_obj_search::_4435 * dVar10 * (d_a_obj_search::_4436 - dVar11 * dVar10 * dVar10)
        ;
        dVar11 = (double)(float)(dVar11 * d_a_obj_search::_4435 * dVar10 *
                                          (d_a_obj_search::_4436 - dVar11 * dVar10 * dVar10));
      }
      iVar6 = SComponent::cM_atan2s(local_50.y,(float)dVar11);
      SComponent::cLib_addCalcAngleS2((short *)(this + 0x708),(short)iVar5 - sVar4,10,0x100);
      SComponent::cLib_addCalcAngleS2((short *)(this + 0x706),(short)iVar6,10,0x100);
      *(undefined2 *)(this + 0x70e) = *(undefined2 *)(this + 0x708);
      *(short *)(this + 0x70c) = -*(short *)(this + 0x706);
    }
    else {
      if (d_a_obj_search::init_4839 == '\0') {
        local_b0 = d_a_obj_search::0_0;
        local_ac = d_a_obj_search::_4434;
        local_a8 = d_a_obj_search::0_0;
        d_a_obj_search::pos_4837 = d_a_obj_search::0_0;
        DAT_803e43dc = d_a_obj_search::_4434;
        DAT_803e43e0 = d_a_obj_search::0_0;
        Runtime.PPCEABI.H::__register_global_object
                  (&d_a_obj_search::pos_4837,::cXyz::_cXyz,&d_a_obj_search::_4838);
        d_a_obj_search::init_4839 = '\x01';
      }
      local_5c = d_a_obj_search::pos_4837;
      local_58 = DAT_803e43dc;
      local_54 = DAT_803e43e0;
      if (*(int *)(this + 0x900) == 1) {
        sVar4 = d_s_play::g_regHIO.mChild[8].mShorts[7] + 0x3400;
      }
      else {
        sVar4 = d_s_play::g_regHIO.mChild[8].mShorts[8] + 0x2600;
      }
      iVar5 = d_a_nh::cLib_calcTimer(this + 0x8f0);
      if (iVar5 == 0) {
        fVar12 = SComponent::cM_rndF(d_a_obj_search::_4953 + d_s_play::g_regHIO.mChild[8].mFloats[5]
                                    );
        local_30 = (double)CONCAT44(0x43300000,
                                    (int)d_s_play::g_regHIO.mChild[8].mShorts[2] + 0x3cU ^
                                    0x80000000);
        iVar5 = (int)((float)(local_30 - d_a_obj_search::_4219) + fVar12);
        local_38 = (double)(longlong)iVar5;
        *(int *)(this + 0x8f0) = iVar5;
        if (*(int *)(this + 0x900) == 1) {
          *(undefined4 *)(this + 0x900) = 0xffffffff;
        }
        else {
          *(undefined4 *)(this + 0x900) = 1;
        }
      }
      *(undefined2 *)(this + 0x7b0) = *(undefined2 *)(this + 0x708);
      SComponent::cLib_addCalcAngleS2((short *)(this + 0x706),sVar4,0x14,0x20);
      *(short *)(this + 0x70c) = -*(short *)(this + 0x706);
    }
  }
  __psq_l0(auStack8,uVar9);
  __psq_l1(auStack8,uVar9);
  return;
}


/* __thiscall Act_c::modeProc(Act_c::Proc_e,
                                            int) */

void __thiscall Act_c::modeProc(Act_c *this,Proc_e param_1,int param_2)

{
  if (d_a_obj_search::init_4977 == '\0') {
    d_a_obj_search::mode_tbl_4960 = d_a_obj_search::_4961;
    DAT_8038d900 = DAT_8038d840;
    DAT_8038d904 = PTR_modeSearchRndInit_8038d844;
    DAT_8038d908 = d_a_obj_search::_4962;
    DAT_8038d90c = DAT_8038d84c;
    DAT_8038d910 = PTR_modeSearchRnd_8038d850;
    DAT_8038d918 = d_a_obj_search::_4963;
    DAT_8038d91c = DAT_8038d858;
    DAT_8038d920 = PTR_modeSearchPathInit_8038d85c;
    DAT_8038d924 = d_a_obj_search::_4964;
    DAT_8038d928 = DAT_8038d864;
    DAT_8038d92c = PTR_modeSearchPath_8038d868;
    DAT_8038d934 = d_a_obj_search::_4965;
    DAT_8038d938 = DAT_8038d870;
    DAT_8038d93c = PTR_modeStopInit_8038d874;
    DAT_8038d940 = d_a_obj_search::_4966;
    DAT_8038d944 = DAT_8038d87c;
    DAT_8038d948 = PTR_modeStop_8038d880;
    DAT_8038d950 = d_a_obj_search::_4967;
    DAT_8038d954 = DAT_8038d888;
    DAT_8038d958 = PTR_modeToSearchInit_8038d88c;
    DAT_8038d95c = d_a_obj_search::_4968;
    DAT_8038d960 = DAT_8038d894;
    DAT_8038d964 = PTR_modeToSearch_8038d898;
    DAT_8038d96c = d_a_obj_search::_4969;
    DAT_8038d970 = DAT_8038d8a0;
    DAT_8038d974 = PTR_modeToStopInit_8038d8a4;
    DAT_8038d978 = d_a_obj_search::_4970;
    DAT_8038d97c = DAT_8038d8ac;
    DAT_8038d980 = PTR_modeToStop_8038d8b0;
    DAT_8038d988 = d_a_obj_search::_4971;
    DAT_8038d98c = DAT_8038d8b8;
    DAT_8038d990 = PTR_modeFindInit_8038d8bc;
    DAT_8038d994 = d_a_obj_search::_4972;
    DAT_8038d998 = DAT_8038d8c4;
    DAT_8038d99c = PTR_modeFind_8038d8c8;
    DAT_8038d9a4 = d_a_obj_search::_4973;
    DAT_8038d9a8 = DAT_8038d8d0;
    DAT_8038d9ac = PTR_modeFind2ndInit_8038d8d4;
    DAT_8038d9b0 = d_a_obj_search::_4974;
    DAT_8038d9b4 = DAT_8038d8dc;
    DAT_8038d9b8 = PTR_modeFind2nd_8038d8e0;
    DAT_8038d9c0 = d_a_obj_search::_4975;
    DAT_8038d9c4 = DAT_8038d8e8;
    DAT_8038d9c8 = PTR_modeSearchBdkInit_8038d8ec;
    DAT_8038d9cc = d_a_obj_search::_4976;
    DAT_8038d9d0 = DAT_8038d8f4;
    DAT_8038d9d4 = PTR_modeSearchBdk_8038d8f8;
    d_a_obj_search::init_4977 = '\x01';
  }
  if (param_1 == 0) {
    *(int *)(this + 0x290) = param_2;
    Runtime.PPCEABI.H::__ptmf_scall
              ((PTMF *)(&d_a_obj_search::mode_tbl_4960 + *(int *)(this + 0x290) * 7),this,
               (void *)0x0);
  }
  else {
    if (param_1 == 1) {
      Runtime.PPCEABI.H::__ptmf_scall
                ((PTMF *)((int)(void *)(*(int *)(this + 0x290) * 0x1c) + -0x7fc726f8),this,
                 (void *)(*(int *)(this + 0x290) * 0x1c));
    }
  }
  return;
}


/* __thiscall Bgc_c::Bgc_c(void) */

void __thiscall Bgc_c::Bgc_c(Bgc_c *this)

{
  Bgc_c *pBVar1;
  
  *(cBgS_Chk__vtbl **)(this + 0x10) = &cBgS_Chk::__vt;
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  this[0xc] = (Bgc_c)0x1;
  *(undefined ***)(this + 0x20) = &::cBgS_PolyInfo::__vt;
  *(undefined2 *)(this + 0x14) = 0xffff;
  *(undefined2 *)(this + 0x16) = 0x100;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = 0xffffffff;
  *(undefined ***)(this + 0x10) = &::cBgS_LinChk::__vt;
  *(undefined ***)(this + 0x20) = &PTR_80371fbc;
  *(undefined ***)(this + 0x3c) = &::cM3dGLin::__vt;
  ::cBgS_LinChk::ct((cBgS_LinChk *)this);
  *(undefined ***)(this + 0x58) = &::cBgS_PolyPassChk::__vt;
  *(undefined ***)(this + 0x58) = &::dBgS_PolyPassChk::__vt;
  this[0x5c] = (Bgc_c)0x0;
  this[0x5d] = (Bgc_c)0x0;
  this[0x5e] = (Bgc_c)0x0;
  this[0x5f] = (Bgc_c)0x0;
  this[0x60] = (Bgc_c)0x0;
  this[0x61] = (Bgc_c)0x0;
  this[0x62] = (Bgc_c)0x0;
  *(undefined ***)(this + 100) = &::cBgS_GrpPassChk::__vt;
  *(undefined ***)(this + 100) = &::dBgS_GrpPassChk::__vt;
  *(undefined4 *)(this + 0x68) = 1;
  *(undefined ***)(this + 0x58) = &::dBgS_Chk::__vt;
  *(undefined ***)(this + 100) = &PTR_80371f68;
  *(undefined ***)(this + 0x10) = &::dBgS_LinChk::__vt;
  *(undefined **)(this + 0x20) = &DAT_80371f38;
  *(undefined ***)(this + 0x58) = &PTR_80371f44;
  *(undefined ***)(this + 100) = &PTR_80371f50;
  *(Bgc_c **)this = this + 0x58;
  pBVar1 = this + 0x58;
  if (pBVar1 != (Bgc_c *)0x0) {
    pBVar1 = this + 100;
  }
  *(Bgc_c **)(this + 4) = pBVar1;
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall Bgc_c::wall_pos(Act_c const *,
                                            cXyz *,
                                            cXyz *,
                                            bool *,
                                            float *) */

void __thiscall
Bgc_c::wall_pos
          (Bgc_c *this,Act_c *param_1,cXyz *param_2,cXyz *param_3,bool *param_4,float *param_5)

{
  char cVar2;
  cM3dGPla *pcVar1;
  double dVar3;
  cXyz local_48;
  cXyz cStack60;
  float local_30;
  float local_2c;
  float local_28;
  
  ::dBgS_LinChk::Set((dBgS_LinChk *)this,param_2,param_3,(fopAc_ac_c *)param_1);
  cVar2 = cBgS::LineCross((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,(cBgS_LinChk *)this);
  if (cVar2 == '\0') {
    *param_4 = false;
  }
  else {
    pcVar1 = cBgS::GetTriPla((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,
                             (uint)*(ushort *)(this + 0x16),(uint)*(ushort *)(this + 0x14));
    ::cXyz::operator__(&cStack60,param_3,param_2);
    ::cXyz::normZP(&local_48,&cStack60);
    local_30 = local_48.x;
    local_2c = local_48.y;
    local_28 = local_48.z;
    dVar3 = (double)mtx::PSVECDotProduct(&local_30,pcVar1);
    *param_5 = (float)dVar3;
    *(undefined4 *)(this + 0x6c) = *(undefined4 *)(this + 0x30);
    *(undefined4 *)(this + 0x70) = *(undefined4 *)(this + 0x34);
    *(undefined4 *)(this + 0x74) = *(undefined4 *)(this + 0x38);
    param_3->x = *(float *)(this + 0x6c);
    param_3->y = *(float *)(this + 0x70);
    param_3->z = *(float *)(this + 0x74);
    *param_4 = true;
  }
  return;
}


/* __thiscall Act_c::attr(void) const */

undefined1 * __thiscall Act_c::attr(Act_c *this)

{
  return &m_attr;
}


/* __thiscall Act_c::SetArgData(void) */

void __thiscall Act_c::SetArgData(Act_c *this)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  
  uVar3 = *(undefined4 *)(this + 0xb0);
  this[0x7e2] = SUB41((uint)uVar3 >> 0x18,0);
  this[0x837] = SUB41((uint)uVar3 >> 0x10,0);
  this[0x836] = SUB41(uVar3,0);
  this[0x8d0] = SUB41((uint)uVar3 >> 8,0);
  if (this[0x8d0] == (Act_c)0xff) {
    this[0x8d0] = (Act_c)0x0;
  }
  fVar2 = d_a_obj_search::_5132;
  fVar1 = d_a_obj_search::_4215;
  if (this[0x836] == (Act_c)0xff) {
    *(float *)(this + 0x214) = d_a_obj_search::_4215;
    *(float *)(this + 0x218) = fVar1;
    *(float *)(this + 0x21c) = fVar1;
  }
  else {
    if (this[0x836] == (Act_c)0x1) {
      *(float *)(this + 0x214) = d_a_obj_search::_5132;
      *(float *)(this + 0x218) = fVar2;
      *(float *)(this + 0x21c) = fVar2;
    }
  }
  *(uint *)(this + 0x85c) = (uint)(int)*(short *)(this + 0x1dc) >> 8 & 0xff;
  return;
}


/* __thiscall Act_c::CreateInit(void) */

void __thiscall Act_c::CreateInit(Act_c *this)

{
  short sVar1;
  char cVar4;
  dPath *pdVar2;
  int iVar3;
  int iVar5;
  ushort uVar6;
  double dVar7;
  double dVar8;
  cXyz local_34;
  float local_28;
  float local_24;
  float local_20;
  undefined4 local_18;
  uint uStack20;
  
  set_path_info(this);
  this[0x7b6] = (Act_c)0x0;
  this[0x7b7] = (Act_c)0x0;
  this[0x7b8] = (Act_c)0x0;
  *(int *)(this + 0x22c) = *(int *)(this + 0x5f8) + 0x24;
  f_op_actor_mng::fopAcM_setCullSizeBox
            ((fopAc_ac_c *)this,(double)d_a_obj_search::_5216,(double)d_a_obj_search::0_0,
             (double)d_a_obj_search::_5216,(double)d_a_obj_search::_4948,
             (double)d_a_obj_search::_5217,(double)d_a_obj_search::_4948);
  *(code **)(*(int *)(this + 0x668) + 0xa8) = d_bg_s::dBgS_MoveBGProc_Typical;
  *(code **)(*(int *)(this + 0x66c) + 0xa8) = d_bg_s::dBgS_MoveBGProc_Typical;
  *(code **)(*(int *)(this + 0x670) + 0xa8) = d_bg_s::dBgS_MoveBGProc_Typical;
  dBgS::Regist(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,*(dBgW **)(this + 0x668),
               (fopAc_ac_c *)this);
  dBgS::Regist(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,*(dBgW **)(this + 0x66c),
               (fopAc_ac_c *)this);
  dBgS::Regist(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mBgS,*(dBgW **)(this + 0x670),
               (fopAc_ac_c *)this);
  ::dCcD_Stts::Init((dCcD_Stts *)(this + 0x57c),0xff,0xff,(fopAc_ac_c *)this);
  ::dCcD_Cps::Set((dCcD_Cps *)(this + 0x30c),(dCcD_SrcCps *)&d_a_obj_search::cps_src);
  *(Act_c **)(this + 0x350) = this + 0x57c;
  *(undefined4 *)(this + 0x424) = *(undefined4 *)(this + 0x1f8);
  *(undefined4 *)(this + 0x428) = *(undefined4 *)(this + 0x1fc);
  *(undefined4 *)(this + 0x42c) = *(undefined4 *)(this + 0x200);
  *(undefined4 *)(this + 0x430) = *(undefined4 *)(this + 0x1f8);
  *(undefined4 *)(this + 0x434) = *(undefined4 *)(this + 0x1fc);
  *(undefined4 *)(this + 0x438) = *(undefined4 *)(this + 0x200);
  *(undefined4 *)(this + 0x440) = DAT_8035c0b8;
  ::dCcD_Stts::Init((dCcD_Stts *)(this + 0x5b8),0xff,0xff,(fopAc_ac_c *)this);
  ::dCcD_Cps::Set((dCcD_Cps *)(this + 0x444),(dCcD_SrcCps *)&d_a_obj_search::cps_src);
  *(Act_c **)(this + 0x488) = this + 0x5b8;
  *(undefined4 *)(this + 0x55c) = *(undefined4 *)(this + 0x1f8);
  *(undefined4 *)(this + 0x560) = *(undefined4 *)(this + 0x1fc);
  *(undefined4 *)(this + 0x564) = *(undefined4 *)(this + 0x200);
  *(undefined4 *)(this + 0x568) = *(undefined4 *)(this + 0x1f8);
  *(undefined4 *)(this + 0x56c) = *(undefined4 *)(this + 0x1fc);
  *(undefined4 *)(this + 0x570) = *(undefined4 *)(this + 0x200);
  *(undefined4 *)(this + 0x578) = DAT_8035c0b8;
  set_mtx_base(this);
  set_moveBG_mtx_base(this);
  *(Act_c **)(*(int *)(this + 0x5f4) + 0x14) = this;
  iVar5 = *(int *)(*(int *)(this + 0x5f4) + 4);
  for (uVar6 = 0; uVar6 < *(ushort *)(iVar5 + 0x28); uVar6 = uVar6 + 1) {
    if ((uVar6 < 8) && (uVar6 != 0)) {
      *(code **)(*(int *)(*(int *)(iVar5 + 0x2c) + (uint)uVar6 * 4) + 8) =
           d_a_obj_search::nodeControl_CB;
    }
  }
  (**(code **)(**(int **)(this + 0x5f4) + 0x10))();
  cVar4 = is_path_info(this);
  if (cVar4 != '\0') {
    pdVar2 = d_path::dPath_GetRoomPath((uint)(byte)this[0x837],(int)(char)this[0x20a]);
    *(dPath **)(this + 0x848) = pdVar2;
    uStack20 = (int)DAT_8035c092 ^ 0x80000000;
    local_18 = 0x43300000;
    d_lib::dLib_pathMove
              ((cXyz *)(this + 0x838),(byte *)(this + 0x844),*(dPath **)(this + 0x848),
               (float)((double)CONCAT44(0x43300000,uStack20) - d_a_obj_search::_4219),
               (undefined *)0x0,(void *)0x0);
    *(undefined4 *)(this + 0x60c) = *(undefined4 *)(this + 0x838);
    *(undefined4 *)(this + 0x610) = *(undefined4 *)(this + 0x83c);
    *(undefined4 *)(this + 0x614) = *(undefined4 *)(this + 0x840);
    ::cXyz::operator__(&local_34,(cXyz *)(this + 0x60c),(cXyz *)(this + 0x624));
    local_28 = local_34.x;
    local_24 = local_34.y;
    local_20 = local_34.z;
    *(undefined2 *)(this + 0x7b0) = *(undefined2 *)(this + 0x708);
    *(undefined2 *)(this + 0x7b2) = *(undefined2 *)(this + 0x706);
    *(undefined2 *)(this + 0x7b4) = *(undefined2 *)(this + 0x70c);
    iVar5 = SComponent::cM_atan2s(local_34.x,local_34.z);
    sVar1 = *(short *)(this + 0x206);
    dVar8 = (double)(local_28 * local_28 + local_20 * local_20);
    if ((double)d_a_obj_search::0_0 < dVar8) {
      dVar7 = 1.0 / SQRT(dVar8);
      dVar7 = d_a_obj_search::_4435 * dVar7 * (d_a_obj_search::_4436 - dVar8 * dVar7 * dVar7);
      dVar7 = d_a_obj_search::_4435 * dVar7 * (d_a_obj_search::_4436 - dVar8 * dVar7 * dVar7);
      dVar8 = (double)(float)(dVar8 * d_a_obj_search::_4435 * dVar7 *
                                      (d_a_obj_search::_4436 - dVar8 * dVar7 * dVar7));
    }
    iVar3 = SComponent::cM_atan2s(local_24,(float)dVar8);
    *(short *)(this + 0x708) = (short)iVar5 - sVar1;
    *(short *)(this + 0x706) = (short)iVar3;
    *(undefined2 *)(this + 0x70e) = *(undefined2 *)(this + 0x708);
  }
  if (this[0x8d0] == (Act_c)0x6) {
    *(undefined2 *)(this + 0x706) = 0x4000;
    *(short *)(this + 0x70c) = -*(short *)(this + 0x706);
  }
  set_mtx_light_A(this);
  set_mtx_light_B(this);
  set_moveBG_mtx_light_A(this);
  set_moveBG_mtx_light_B(this);
  *(undefined4 *)(this + 0x7a0) = 0;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall Act_c::_create(void) */

PhaseState __thiscall Act_c::_create(Act_c *this)

{
  short sVar1;
  float fVar2;
  PhaseState PVar3;
  uint uVar4;
  char cVar7;
  bool bVar8;
  int iVar5;
  int iVar6;
  double dVar9;
  double dVar10;
  cXyz local_64;
  cXyz local_58;
  cXyz local_4c;
  cXyz local_40;
  cXyz local_34;
  float local_28;
  float local_24;
  float local_20;
  cXyz local_1c;
  
  if ((*(uint *)(this + 0x1c8) & 8) == 0) {
    if (this != (Act_c *)0x0) {
      Act_c(this);
    }
    *(uint *)(this + 0x1c8) = *(uint *)(this + 0x1c8) | 8;
  }
  PVar3 = d_com_inf_game::dComIfG_resLoad((request_of_phase_process_class *)(this + 0x854),"Search")
  ;
  if (PVar3 == cPhs_COMPLEATE_e) {
    SetArgData(this);
    uVar4 = f_op_actor_mng::fopAcM_entrySolidHeap
                      ((fopAc_ac_c *)this,d_a_obj_search::createHeap_CB,0x4620);
    if ((uVar4 & 0xff) == 0) {
      PVar3 = cPhs_ERROR_e;
    }
    else {
      CreateInit(this);
      *(undefined4 *)(this + 0x624) = *(undefined4 *)(this + 0x1f8);
      *(undefined4 *)(this + 0x628) = *(undefined4 *)(this + 0x1fc);
      *(undefined4 *)(this + 0x62c) = *(undefined4 *)(this + 0x200);
      *(undefined4 *)(this + 0x630) = *(undefined4 *)(this + 0x1f8);
      *(undefined4 *)(this + 0x634) = *(undefined4 *)(this + 0x1fc);
      *(undefined4 *)(this + 0x638) = *(undefined4 *)(this + 0x200);
      if (this[0x8d0] == (Act_c)0x6) {
        modeProc(this,0,7);
      }
      else {
        if (this[0x8d0] == (Act_c)0x5) {
          this[0x860] = (Act_c)0x1;
          modeProc(this,0,2);
        }
        else {
          cVar7 = is_path_info(this);
          if (cVar7 == '\0') {
            local_34.x = d_a_obj_search::_4215;
            local_34.y = d_a_obj_search::_4215;
            local_34.z = d_a_obj_search::_4215;
            ::cXyz::operator__(&local_58,(cXyz *)(this + 0x624),&local_34);
            *(float *)(this + 0x60c) = local_58.x;
            *(float *)(this + 0x610) = local_58.y;
            *(float *)(this + 0x614) = local_58.z;
            ::cXyz::operator__(&local_64,(cXyz *)(this + 0x630),&local_34);
            *(float *)(this + 0x618) = local_64.x;
            *(float *)(this + 0x61c) = local_64.y;
            *(float *)(this + 0x620) = local_64.z;
            modeProc(this,0,2);
          }
          else {
            local_1c.x = d_a_obj_search::_4215;
            local_1c.y = d_a_obj_search::_4215;
            local_1c.z = d_a_obj_search::_4215;
            *(undefined4 *)(this + 0x60c) = *(undefined4 *)(this + 0x838);
            *(undefined4 *)(this + 0x610) = *(undefined4 *)(this + 0x83c);
            *(undefined4 *)(this + 0x614) = *(undefined4 *)(this + 0x840);
            ::cXyz::operator__(&local_40,(cXyz *)(this + 0x630),&local_1c);
            *(float *)(this + 0x618) = local_40.x;
            *(float *)(this + 0x61c) = local_40.y;
            *(float *)(this + 0x620) = local_40.z;
            bVar8 = dSv_info_c::isSwitch
                              (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo,(uint)(byte)this[0x7e2],
                               (int)(char)dStage_roomControl_c::mStayNo);
            if (bVar8 == false) {
              this[0x664] = (Act_c)0x1;
              modeProc(this,0,1);
              set_mtx_light_A(this);
              set_mtx_light_B(this);
              ::cXyz::operator__(&local_4c,(cXyz *)(this + 0x60c),(cXyz *)(this + 0x624));
              local_28 = local_4c.x;
              local_24 = local_4c.y;
              local_20 = local_4c.z;
              iVar5 = SComponent::cM_atan2s(local_4c.x,local_4c.z);
              sVar1 = *(short *)(this + 0x206);
              dVar10 = (double)(local_28 * local_28 + local_20 * local_20);
              if ((double)d_a_obj_search::0_0 < dVar10) {
                dVar9 = 1.0 / SQRT(dVar10);
                dVar9 = d_a_obj_search::_4435 * dVar9 *
                        (d_a_obj_search::_4436 - dVar10 * dVar9 * dVar9);
                dVar9 = d_a_obj_search::_4435 * dVar9 *
                        (d_a_obj_search::_4436 - dVar10 * dVar9 * dVar9);
                dVar10 = (double)(float)(dVar10 * d_a_obj_search::_4435 * dVar9 *
                                                  (d_a_obj_search::_4436 - dVar10 * dVar9 * dVar9));
              }
              iVar6 = SComponent::cM_atan2s(local_24,(float)dVar10);
              *(short *)(this + 0x708) = (short)iVar5 - sVar1;
              *(short *)(this + 0x706) = (short)iVar6;
              *(undefined2 *)(this + 0x70e) = *(undefined2 *)(this + 0x708);
            }
            else {
              this[0x664] = (Act_c)0x0;
              modeProc(this,0,2);
            }
          }
        }
      }
      *(undefined4 *)(this + 0x63c) = *(undefined4 *)(this + 0x60c);
      *(undefined4 *)(this + 0x640) = *(undefined4 *)(this + 0x610);
      *(undefined4 *)(this + 0x644) = *(undefined4 *)(this + 0x614);
      *(undefined4 *)(this + 0x648) = *(undefined4 *)(this + 0x618);
      *(undefined4 *)(this + 0x64c) = *(undefined4 *)(this + 0x61c);
      *(undefined4 *)(this + 0x650) = *(undefined4 *)(this + 0x620);
      d_kankyo::dKy_plight_set((LIGHT_INFLUENCE *)(this + 0x780));
      *(undefined4 *)(this + 0x780) = *(undefined4 *)(this + 0x1f8);
      *(undefined4 *)(this + 0x784) = *(undefined4 *)(this + 0x1fc);
      *(undefined4 *)(this + 0x788) = *(undefined4 *)(this + 0x200);
      *(undefined2 *)(this + 0x78c) = 0;
      *(undefined2 *)(this + 0x78e) = 0;
      *(undefined2 *)(this + 0x790) = 0;
      fVar2 = d_a_obj_search::0_0;
      *(float *)(this + 0x794) = d_a_obj_search::0_0;
      *(float *)(this + 0x798) = fVar2;
      if (this[0x8d0] == (Act_c)0x5) {
        *(undefined2 *)(this + 0x77e) = 0;
      }
      else {
        if ((d_a_obj_search::_5356 <=
             d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mCurTime) ||
           (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mCurTime <=
            d_a_obj_search::_4953)) {
          *(undefined2 *)(this + 0x77e) = 0xff;
        }
        else {
          *(undefined2 *)(this + 0x77e) = 0;
        }
      }
      this[0x82c] = (Act_c)0xeb;
      this[0x82d] = (Act_c)0x7d;
      _execute(this);
      _execute(this);
    }
  }
  return PVar3;
}


/* __thiscall Act_c::Act_c(void) */

void __thiscall Act_c::Act_c(Act_c *this)

{
  Act_c *pAVar1;
  
  fopAc_ac_c::fopAc_ac_c((fopAc_ac_c *)this);
  Bgc_c::Bgc_c((Bgc_c *)(this + 0x294));
  Runtime.PPCEABI.H::__construct_array
            (this + 0x30c,::dCcD_Cps::dCcD_Cps,::dCcD_Cps::_dCcD_Cps,0x138,2);
  Runtime.PPCEABI.H::__construct_array
            (this + 0x57c,::dCcD_Stts::dCcD_Stts,::dCcD_Stts::_dCcD_Stts,0x3c,2);
  Runtime.PPCEABI.H::__construct_array(this + 0x60c,::cXyz::cXyz,::cXyz::_cXyz,0xc,2);
  Runtime.PPCEABI.H::__construct_array(this + 0x624,::cXyz::cXyz,::cXyz::_cXyz,0xc,2);
  Runtime.PPCEABI.H::__construct_array(this + 0x63c,::cXyz::cXyz,::cXyz::_cXyz,0xc,2);
  Runtime.PPCEABI.H::__construct_array(this + 0x706,::csXyz::csXyz,::csXyz::_csXyz,6,2);
  ::dPa_smokeEcallBack::dPa_smokeEcallBack((dPa_smokeEcallBack *)(this + 0x808),1);
  *(cBgS_Chk__vtbl **)(this + 0x874) = &cBgS_Chk::__vt;
  *(undefined4 *)(this + 0x864) = 0;
  *(undefined4 *)(this + 0x868) = 0;
  this[0x870] = (Act_c)0x1;
  *(undefined ***)(this + 0x884) = &::cBgS_PolyInfo::__vt;
  *(undefined2 *)(this + 0x878) = 0xffff;
  *(undefined2 *)(this + 0x87a) = 0x100;
  *(undefined4 *)(this + 0x87c) = 0;
  *(undefined4 *)(this + 0x880) = 0xffffffff;
  *(undefined ***)(this + 0x874) = &::cBgS_LinChk::__vt;
  *(undefined ***)(this + 0x884) = &PTR_80371fbc;
  *(undefined ***)(this + 0x8a0) = &::cM3dGLin::__vt;
  ::cBgS_LinChk::ct((cBgS_LinChk *)(this + 0x864));
  *(undefined ***)(this + 0x8bc) = &::cBgS_PolyPassChk::__vt;
  *(undefined ***)(this + 0x8bc) = &::dBgS_PolyPassChk::__vt;
  this[0x8c0] = (Act_c)0x0;
  this[0x8c1] = (Act_c)0x0;
  this[0x8c2] = (Act_c)0x0;
  this[0x8c3] = (Act_c)0x0;
  this[0x8c4] = (Act_c)0x0;
  this[0x8c5] = (Act_c)0x0;
  this[0x8c6] = (Act_c)0x0;
  *(undefined ***)(this + 0x8c8) = &::cBgS_GrpPassChk::__vt;
  *(undefined ***)(this + 0x8c8) = &::dBgS_GrpPassChk::__vt;
  *(undefined4 *)(this + 0x8cc) = 1;
  *(undefined ***)(this + 0x8bc) = &::dBgS_Chk::__vt;
  *(undefined ***)(this + 0x8c8) = &PTR_80371f68;
  *(undefined ***)(this + 0x874) = &::dBgS_LinChk::__vt;
  *(undefined **)(this + 0x884) = &DAT_80371f38;
  *(undefined ***)(this + 0x8bc) = &PTR_80371f44;
  *(undefined ***)(this + 0x8c8) = &PTR_80371f50;
  (((cBgS_LinChk *)(this + 0x864))->parent).mpPolyPassChk = (cBgS_PolyPassChk *)(this + 0x8bc);
  pAVar1 = this + 0x8bc;
  if (pAVar1 != (Act_c *)0x0) {
    pAVar1 = this + 0x8c8;
  }
  *(Act_c **)(this + 0x868) = pAVar1;
  *(undefined1 **)(this + 0x874) = &::dBgS_ObjLinChk::__vt;
  *(undefined **)(this + 0x884) = &DAT_8038db80;
  *(undefined **)(this + 0x8bc) = &DAT_8038db8c;
  *(undefined **)(this + 0x8c8) = &DAT_8038db98;
  this[0x8c0] = (Act_c)0x1;
  return;
}

}

/* __thiscall dBgS_ObjLinChk::~dBgS_ObjLinChk(void) */

void __thiscall dBgS_ObjLinChk::_dBgS_ObjLinChk(dBgS_ObjLinChk *this)

{
  short in_r4;
  
  if (this != (dBgS_ObjLinChk *)0x0) {
    *(undefined1 **)(this + 0x10) = &__vt;
    *(undefined **)(this + 0x20) = &DAT_8038db80;
    *(undefined **)(this + 0x58) = &DAT_8038db8c;
    *(undefined **)(this + 100) = &DAT_8038db98;
    if (this != (dBgS_ObjLinChk *)0x0) {
      *(undefined ***)(this + 0x10) = &::dBgS_LinChk::__vt;
      *(undefined **)(this + 0x20) = &DAT_80371f38;
      *(undefined ***)(this + 0x58) = &PTR_80371f44;
      *(undefined ***)(this + 100) = &PTR_80371f50;
      if (this != (dBgS_ObjLinChk *)0xffffffa8) {
        *(undefined ***)(this + 0x58) = &::dBgS_Chk::__vt;
        *(undefined ***)(this + 100) = &PTR_80371f68;
        if (this != (dBgS_ObjLinChk *)0xffffff9c) {
          *(undefined ***)(this + 100) = &::dBgS_GrpPassChk::__vt;
          if (this != (dBgS_ObjLinChk *)0xffffff9c) {
            *(undefined ***)(this + 100) = &::cBgS_GrpPassChk::__vt;
          }
        }
        if ((this != (dBgS_ObjLinChk *)0xffffffa8) &&
           (*(undefined ***)(this + 0x58) = &::dBgS_PolyPassChk::__vt,
           this != (dBgS_ObjLinChk *)0xffffffa8)) {
          *(undefined ***)(this + 0x58) = &::cBgS_PolyPassChk::__vt;
        }
      }
      if (this != (dBgS_ObjLinChk *)0x0) {
        *(undefined ***)(this + 0x10) = &::cBgS_LinChk::__vt;
        *(undefined ***)(this + 0x20) = &PTR_80371fbc;
        if (this != (dBgS_ObjLinChk *)0xffffffdc) {
          *(undefined ***)(this + 0x3c) = &::cM3dGLin::__vt;
        }
        if (this != (dBgS_ObjLinChk *)0xffffffec) {
          *(undefined ***)(this + 0x20) = &::cBgS_PolyInfo::__vt;
        }
        cBgS_Chk::_cBgS_Chk((cBgS_Chk *)this);
      }
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall csXyz::csXyz(void) */

void __thiscall csXyz::csXyz(csXyz *this)

{
  return;
}


/* __thiscall dCcD_Stts::dCcD_Stts(void) */

void __thiscall dCcD_Stts::dCcD_Stts(dCcD_Stts *this)

{
  (this->parent).vtbl = &cCcD_Stts::__vt;
  ::dCcD_GStts::dCcD_GStts(&this->mGStts);
  (this->parent).vtbl = &__vt.parent;
  (this->mGStts).parent.vtbl = (cCcD_GStts__vtbl *)0x8037ec40;
  return;
}


/* __thiscall dCcD_Cps::dCcD_Cps(void) */

void __thiscall dCcD_Cps::dCcD_Cps(dCcD_Cps *this)

{
  dCcD_GObjInf::dCcD_GObjInf(&this->parent);
  (this->mAttr).parent.vtbl = (cCcD_ShapeAttr__vtbl *)&::cCcD_ShapeAttr::__vt;
  (this->mAttr).parent.mAab.vtbl = &::cM3dGAab::__vt;
  (this->mAttr).mCps.parent.vtbl = (undefined *)&::cM3dGLin::__vt;
  (this->mAttr).mCps.parent.vtbl = (undefined *)&::cM3dGCps::__vt;
  (this->mAttr).parent.vtbl = &::cCcD_CpsAttr::__vt;
  (this->mAttr).mCps.parent.vtbl = &DAT_8039520c;
  (this->parent).parent.parent.parent.vtbl = (cCcD_GObjInf__vtbl *)&__vt;
  (this->mAttr).parent.vtbl = (cCcD_ShapeAttr__vtbl *)&DAT_80389a8c;
  (this->mAttr).mCps.parent.vtbl = &DAT_80389ae0;
  return;
}


namespace daObj_Search {

/* WARNING: Removing unreachable block (ram,0x801010a4) */
/* __thiscall Act_c::smoke_set(float,
                                             int) */

void __thiscall Act_c::smoke_set(Act_c *this,float param_1,int param_2)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  double dVar4;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  dVar4 = (double)param_1;
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  *(undefined4 *)(this + 0x7f4) = *(undefined4 *)(this + 0x600);
  *(undefined4 *)(this + 0x7f8) = *(undefined4 *)(this + 0x604);
  *(undefined4 *)(this + 0x7fc) = *(undefined4 *)(this + 0x608);
  *(undefined2 *)(this + 0x800) = 0;
  *(undefined2 *)(this + 0x802) = 0;
  *(undefined2 *)(this + 0x804) = 0;
  if (*(int *)(this + 0x80c) == 0) {
    dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,2,0x2022,
                       (cXyz *)(this + 0x7f4),(csXyz *)(this + 0x800),(cXyz *)0x0,0xb9,
                       (dPa_levelEcallBack *)(this + 0x808),(char)this[0x20a],(_GXColor *)0x0,
                       (_GXColor *)0x0,(cXyz *)0x0);
  }
  if (*(int *)(this + 0x80c) != 0) {
    *(float *)(*(int *)(this + 0x80c) + 0x38) = (float)dVar4;
    *(float *)(*(int *)(this + 0x80c) + 0x5c) = d_a_obj_search::_4215;
    fVar1 = d_a_obj_search::_5617 + d_s_play::g_regHIO.mChild[12].mFloats[10];
    iVar2 = *(int *)(this + 0x80c);
    *(float *)(iVar2 + 0x1d8) = fVar1;
    *(float *)(iVar2 + 0x1dc) = fVar1;
    *(float *)(iVar2 + 0x1e0) = fVar1;
    *(float *)(iVar2 + 0x1f0) = fVar1;
    *(float *)(iVar2 + 500) = fVar1;
    *(float *)(iVar2 + 0x1f8) = fVar1;
    fVar1 = d_a_obj_search::_5618 + d_s_play::g_regHIO.mChild[12].mFloats[11];
    iVar2 = *(int *)(this + 0x80c);
    *(float *)(iVar2 + 0x1f0) = fVar1;
    *(float *)(iVar2 + 500) = fVar1;
    *(float *)(iVar2 + 0x1f8) = fVar1;
  }
  *(int *)(this + 0x828) = param_2;
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall Act_c::_execute(void) */

undefined4 __thiscall Act_c::_execute(Act_c *this)

{
  int iVar1;
  fopAc_ac_c *pfVar2;
  bool bVar3;
  sbyte sVar4;
  undefined2 local_28 [2];
  undefined4 local_24;
  float local_20;
  float local_1c;
  float local_18;
  cXyz local_14;
  
  if (m_attr == '\0') {
    iVar1 = d_a_nh::cLib_calcTimer(this + 0x828);
    if (iVar1 == 0) {
      (**(code **)(*(int *)(this + 0x808) + 0x20))(this + 0x808);
    }
    if ((this[0x8d0] != (Act_c)0x6) && (this[0x8d0] != (Act_c)0x5)) {
      local_24 = *(undefined4 *)(this + 0x84c);
      pfVar2 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,&local_24);
      if (pfVar2 == (fopAc_ac_c *)0x0) {
        if ((*(int *)(this + 0x850) != 0xff) &&
           (bVar3 = dSv_info_c::isSwitch
                              (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo,*(int *)(this + 0x850),
                               (int)(char)dStage_roomControl_c::mStayNo), bVar3 == false)) {
          dSv_info_c::onSwitch
                    (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo,*(int *)(this + 0x850),
                     (int)(char)dStage_roomControl_c::mStayNo);
        }
      }
      else {
        *(uint *)(this + 0x850) =
             (uint)*(byte *)((int)&pfVar2[1].parent.parent.mLyTg.parent.mpTagData + 3);
      }
    }
    *(undefined4 *)(this + 0x260) = *(undefined4 *)(this + 0x1f8);
    *(undefined4 *)(this + 0x264) = *(undefined4 *)(this + 0x1fc);
    *(undefined4 *)(this + 0x268) = *(undefined4 *)(this + 0x200);
    iVar1 = MSL_C.PPCEABI.bare.H::abs((int)*(short *)(this + 0x708) - (int)*(short *)(this + 0x7b0))
    ;
    if (((short)iVar1 != 0) && (*(int *)(this + 0x290) != 2)) {
      sVar4 = d_com_inf_game::dComIfGp_getReverb((int)(char)this[0x20a]);
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x6131,(cXyz *)(this + 0x260),0,sVar4,d_a_obj_search::_4215,
                 d_a_obj_search::_4215,d_a_obj_search::_4478,d_a_obj_search::_4478,0);
    }
    (**(code **)(**(int **)(this + 0x5f4) + 0x10))();
    local_20 = d_a_obj_search::0_0;
    local_1c = d_a_obj_search::0_0;
    local_18 = d_a_obj_search::0_0;
    local_14.x = d_a_obj_search::0_0;
    local_14.y = d_a_obj_search::0_0;
    local_14.z = d_a_obj_search::0_0;
    mtx::PSMTXCopy((MTX34 *)(*(int *)(*(int *)(this + 0x5f4) + 0x8c) + 0xf0),&mDoMtx_stack_c::now);
    mtx::PSMTXMultVec(&mDoMtx_stack_c::now,&local_14,(cXyz *)(this + 0x600));
    set_mtx_light_A(this);
    set_mtx_light_B(this);
    *(int *)(this + 0x7a4) = *(int *)(this + 0x7a4) + 1;
    if (3 < *(int *)(this + 0x7a4)) {
      *(undefined4 *)(this + 0x7a4) = 0;
    }
    if ((d_a_obj_search::_5356 <=
         d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mCurTime) ||
       (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB.mCurTime <=
        d_a_obj_search::_4953)) {
      if (this[0x860] == (Act_c)0x0) {
        this[0x834] = (Act_c)0x1;
      }
      else {
        this[0x834] = (Act_c)0x0;
      }
    }
    else {
      this[0x834] = (Act_c)0x0;
    }
    if (this[0x834] == (Act_c)0x0) {
      SComponent::cLib_chaseS
                (this + 0x77e,0,(int)(short)(d_s_play::g_regHIO.mChild[12].mShorts[0] + 0x14));
      *(float *)(this + 0x794) = d_a_obj_search::0_0;
    }
    else {
      SComponent::cLib_chaseS
                (this + 0x77e,0xff,(int)(short)(d_s_play::g_regHIO.mChild[12].mShorts[0] + 0x14));
    }
    local_28[0] = 0xf3;
    pfVar2 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeForPName,local_28);
    if (((*(int *)(this + 0x85c) == 0xff) || (pfVar2 == (fopAc_ac_c *)0x0)) &&
       (this[0x8d0] != (Act_c)0x5)) {
      check_bk_control(this);
    }
    modeProc(this,1,8);
    bg_check(this);
  }
  return 1;
}


/* __thiscall Act_c::check_bk_control(void) */

void __thiscall Act_c::check_bk_control(Act_c *this)

{
  fopAc_ac_c *pfVar1;
  undefined4 local_18 [5];
  
  local_18[0] = *(undefined4 *)(this + 0x84c);
  pfVar1 = f_op_actor_iter::fopAcIt_Judge(f_pc_searcher::fpcSch_JudgeByID,local_18);
  if (pfVar1 != (fopAc_ac_c *)0x0) {
    this[0x860] = (Act_c)0x0;
    *(undefined2 *)&pfVar1[7].parent.parent.mLnTg.parent.parent.mpPrevNode =
         *(undefined2 *)(this + 0x7ac);
    if ((this[0x664] == (Act_c)0x1) &&
       ((*(int *)(this + 0x290) == 4 || (*(int *)(this + 0x290) == 2)))) {
      modeProc(this,0,3);
    }
    else {
      if ((this[0x664] == (Act_c)0x0) &&
         ((*(int *)(this + 0x290) != 4 && (*(int *)(this + 0x290) != 2)))) {
        modeProc(this,0,4);
      }
    }
  }
  return;
}


/* __thiscall Act_c::set_mtx_base(void) */

void __thiscall Act_c::set_mtx_base(Act_c *this)

{
  int iVar1;
  
  iVar1 = *(int *)(this + 0x5f4);
  *(undefined4 *)(iVar1 + 0x18) = *(undefined4 *)(this + 0x214);
  *(undefined4 *)(iVar1 + 0x1c) = *(undefined4 *)(this + 0x218);
  *(undefined4 *)(iVar1 + 0x20) = *(undefined4 *)(this + 0x21c);
  mtx::PSMTXTrans((double)*(float *)(this + 0x1f8),(double)*(float *)(this + 0x1fc),
                  (double)*(float *)(this + 0x200),&mDoMtx_stack_c::now);
  m_Do_mtx::mDoMtx_YrotM(&mDoMtx_stack_c::now,*(short *)(this + 0x206));
  mtx::PSMTXCopy(&mDoMtx_stack_c::now,(MTX34 *)(*(int *)(this + 0x5f4) + 0x24));
  return;
}


/* WARNING: Removing unreachable block (ram,0x80101884) */
/* WARNING: Removing unreachable block (ram,0x8010188c) */
/* __thiscall Act_c::set_mtx_light_A(void) */

void __thiscall Act_c::set_mtx_light_A(Act_c *this)

{
  undefined4 uVar1;
  double dVar2;
  double dVar3;
  undefined8 in_f30;
  undefined8 in_f31;
  float fVar4;
  float local_c4;
  cXyz local_c0;
  cXyz cStack180;
  cXyz local_a8;
  cXyz cStack156;
  cXyz local_90;
  cXyz cStack132;
  cXyz local_78;
  cXyz cStack108;
  cXyz local_60;
  cXyz local_54;
  cXyz local_48;
  cXyz local_3c [2];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  local_3c[0].x = d_a_obj_search::0_0;
  local_3c[0].y = d_a_obj_search::0_0;
  local_3c[0].z = d_a_obj_search::0_0;
  local_48.x = d_a_obj_search::0_0;
  local_48.y = d_a_obj_search::0_0;
  local_48.z = DAT_8035c094;
  mtx::PSMTXCopy((MTX34 *)(*(int *)(*(int *)(this + 0x5f4) + 0x8c) + 0xf0),&mDoMtx_stack_c::now);
  mDoMtx_stack_c::transM(d_a_obj_search::_5839,d_a_obj_search::_5840,d_a_obj_search::_5841);
  m_Do_mtx::mDoMtx_XYZrotM(&mDoMtx_stack_c::now,0,0xffffff38,0);
  mtx::PSMTXMultVec(&mDoMtx_stack_c::now,local_3c,(cXyz *)(this + 0x624));
  if ((*(uint *)(this + 0x7a4) == (*(ushort *)(this + 0x1bc) & 3)) || (DAT_8035c0b4 != '\0')) {
    local_c4 = d_a_obj_search::0_0;
    mtx::PSMTXMultVec(&mDoMtx_stack_c::now,&local_48,(cXyz *)(this + 0x63c));
    if ((DAT_8035c0ce != '\0') || (*(int *)(this + 0x290) != 5)) {
      Bgc_c::wall_pos((Bgc_c *)(this + 0x294),this,(cXyz *)(this + 0x624),(cXyz *)(this + 0x63c),
                      (bool *)(this + 0x77c),&local_c4);
    }
    fVar4 = mtx::PSVECSquareDistance((cXyz *)(this + 0x624),(cXyz *)(this + 0x63c));
    dVar3 = (double)fVar4;
    if ((double)d_a_obj_search::0_0 < dVar3) {
      dVar2 = 1.0 / SQRT(dVar3);
      dVar2 = d_a_obj_search::_4435 * dVar2 * (d_a_obj_search::_4436 - dVar3 * dVar2 * dVar2);
      dVar2 = d_a_obj_search::_4435 * dVar2 * (d_a_obj_search::_4436 - dVar3 * dVar2 * dVar2);
      dVar3 = (double)(float)(dVar3 * d_a_obj_search::_4435 * dVar2 *
                                      (d_a_obj_search::_4436 - dVar3 * dVar2 * dVar2));
    }
    if (*(short *)(this + 0x1bc) == 0) {
      if (this[0x77c] != (Act_c)0x0) {
        fVar4 = d_a_obj_search::_5842 * (d_a_obj_search::_5843 + local_c4);
        if (this[0x8d0] == (Act_c)0x6) {
          fVar4 = -(d_a_obj_search::_5843 + local_c4) *
                  ((d_a_obj_search::_4949 + DAT_8035c0a0) - d_s_play::g_regHIO.mChild[12].mFloats[0]
                  );
        }
        dVar2 = (double)fVar4;
        dVar3 = (double)(float)(dVar3 + dVar2);
        ::cXyz::operator__(&cStack108,(cXyz *)(this + 0x63c),(cXyz *)(this + 0x624));
        ::cXyz::normZP(&local_78,&cStack108);
        local_54.x = local_78.x;
        local_54.y = local_78.y;
        local_54.z = local_78.z;
        ::cXyz::operator_(&cStack132,&local_54,(float)dVar2);
        ::cXyz::operator__(&local_90,(cXyz *)(this + 0x63c),&cStack132);
        *(float *)(this + 0x63c) = local_90.x;
        *(float *)(this + 0x640) = local_90.y;
        *(float *)(this + 0x644) = local_90.z;
      }
    }
    else {
      if (this[0x77c] != (Act_c)0x0) {
        fVar4 = (d_a_obj_search::_5843 + local_c4) * DAT_8035c0a0;
        if (this[0x8d0] == (Act_c)0x6) {
          fVar4 = -(d_a_obj_search::_5843 + local_c4) *
                  (d_s_play::g_regHIO.mChild[12].mFloats[0] + d_a_obj_search::_5844 + DAT_8035c0a0);
        }
        dVar2 = (double)fVar4;
        dVar3 = (double)(float)(dVar3 + dVar2);
        ::cXyz::operator__(&cStack156,(cXyz *)(this + 0x63c),(cXyz *)(this + 0x624));
        ::cXyz::normZP(&local_a8,&cStack156);
        local_60.x = local_a8.x;
        local_60.y = local_a8.y;
        local_60.z = local_a8.z;
        ::cXyz::operator_(&cStack180,&local_60,(float)dVar2);
        ::cXyz::operator__(&local_c0,(cXyz *)(this + 0x63c),&cStack180);
        *(float *)(this + 0x63c) = local_c0.x;
        *(float *)(this + 0x640) = local_c0.y;
        *(float *)(this + 0x644) = local_c0.z;
      }
    }
    *(float *)(this + 0x65c) = (float)dVar3;
    *(undefined4 *)(this + 0x654) = *(undefined4 *)(this + 0x65c);
  }
  m_Do_mtx::mDoMtx_XYZrotM(&mDoMtx_stack_c::now,0,0,0xc80);
  mDoMtx_stack_c::scaleM
            (*(float *)(this + 0x214),*(float *)(this + 0x218),
             d_a_obj_search::_5845 * *(float *)(this + 0x654));
  mtx::PSMTXCopy(&mDoMtx_stack_c::now,(MTX34 *)(*(int *)(this + 0x5f8) + 0x24));
  mtx::PSMTXCopy(&mDoMtx_stack_c::now,(MTX34 *)(this + 0x71c));
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  __psq_l0(auStack24,uVar1);
  __psq_l1(auStack24,uVar1);
  return;
}


/* WARNING: Removing unreachable block (ram,0x80101b88) */
/* WARNING: Removing unreachable block (ram,0x80101b90) */
/* __thiscall Act_c::set_mtx_light_B(void) */

void __thiscall Act_c::set_mtx_light_B(Act_c *this)

{
  undefined4 uVar1;
  double dVar2;
  double dVar3;
  undefined8 in_f30;
  undefined8 in_f31;
  float fVar4;
  float local_a4;
  cXyz local_a0;
  cXyz cStack148;
  cXyz local_88;
  cXyz cStack124;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  cXyz local_58;
  cXyz local_4c;
  cXyz local_40 [2];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  local_64 = d_a_obj_search::0_0;
  local_60 = d_a_obj_search::0_0;
  local_5c = d_a_obj_search::0_0;
  local_40[0].x = d_a_obj_search::0_0;
  local_40[0].y = d_a_obj_search::0_0;
  local_40[0].z = d_a_obj_search::0_0;
  local_70 = d_a_obj_search::0_0;
  local_6c = d_a_obj_search::0_0;
  local_68 = DAT_8035c094;
  local_4c.x = d_a_obj_search::0_0;
  local_4c.y = d_a_obj_search::0_0;
  local_4c.z = DAT_8035c094;
  mtx::PSMTXCopy((MTX34 *)(*(int *)(*(int *)(this + 0x5f4) + 0x8c) + 0x120),&mDoMtx_stack_c::now);
  mDoMtx_stack_c::transM(d_a_obj_search::_5925,d_a_obj_search::_5926,d_a_obj_search::_5927);
  m_Do_mtx::mDoMtx_XYZrotM(&mDoMtx_stack_c::now,0xffff8000,200,0);
  mtx::PSMTXMultVec(&mDoMtx_stack_c::now,local_40,(cXyz *)(this + 0x630));
  if ((*(uint *)(this + 0x7a4) == (*(ushort *)(this + 0x1bc) & 3)) || (DAT_8035c0b4 != '\0')) {
    local_a4 = d_a_obj_search::0_0;
    mtx::PSMTXMultVec(&mDoMtx_stack_c::now,&local_4c,(cXyz *)(this + 0x648));
    if ((DAT_8035c0ce != '\0') || (*(int *)(this + 0x290) != 5)) {
      Bgc_c::wall_pos((Bgc_c *)(this + 0x294),this,(cXyz *)(this + 0x630),(cXyz *)(this + 0x648),
                      (bool *)(this + 0x77d),&local_a4);
    }
    fVar4 = mtx::PSVECSquareDistance((cXyz *)(this + 0x630),(cXyz *)(this + 0x648));
    dVar3 = (double)fVar4;
    if ((double)d_a_obj_search::0_0 < dVar3) {
      dVar2 = 1.0 / SQRT(dVar3);
      dVar2 = d_a_obj_search::_4435 * dVar2 * (d_a_obj_search::_4436 - dVar3 * dVar2 * dVar2);
      dVar2 = d_a_obj_search::_4435 * dVar2 * (d_a_obj_search::_4436 - dVar3 * dVar2 * dVar2);
      dVar3 = (double)(float)(dVar3 * d_a_obj_search::_4435 * dVar2 *
                                      (d_a_obj_search::_4436 - dVar3 * dVar2 * dVar2));
    }
    if (this[0x77d] != (Act_c)0x0) {
      fVar4 = (d_a_obj_search::_5843 + local_a4) * DAT_8035c0a0;
      if (this[0x8d0] == (Act_c)0x6) {
        fVar4 = -(d_a_obj_search::_5843 + local_a4) *
                (d_s_play::g_regHIO.mChild[12].mFloats[0] + d_a_obj_search::_5844 + DAT_8035c0a0);
      }
      dVar2 = (double)fVar4;
      dVar3 = (double)(float)(dVar3 + dVar2);
      ::cXyz::operator__(&cStack124,(cXyz *)(this + 0x648),(cXyz *)(this + 0x630));
      ::cXyz::normZP(&local_88,&cStack124);
      local_58.x = local_88.x;
      local_58.y = local_88.y;
      local_58.z = local_88.z;
      ::cXyz::operator_(&cStack148,&local_58,(float)dVar2);
      ::cXyz::operator__(&local_a0,(cXyz *)(this + 0x648),&cStack148);
      *(float *)(this + 0x648) = local_a0.x;
      *(float *)(this + 0x64c) = local_a0.y;
      *(float *)(this + 0x650) = local_a0.z;
    }
    *(float *)(this + 0x660) = (float)dVar3;
    *(undefined4 *)(this + 0x658) = *(undefined4 *)(this + 0x660);
  }
  m_Do_mtx::mDoMtx_XYZrotM(&mDoMtx_stack_c::now,0,0,0xc80);
  mDoMtx_stack_c::scaleM
            (*(float *)(this + 0x214),*(float *)(this + 0x218),
             d_a_obj_search::_5845 * *(float *)(this + 0x658));
  mtx::PSMTXCopy(&mDoMtx_stack_c::now,(MTX34 *)(*(int *)(this + 0x5fc) + 0x24));
  mtx::PSMTXCopy(&mDoMtx_stack_c::now,(MTX34 *)(this + 0x74c));
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  __psq_l0(auStack24,uVar1);
  __psq_l1(auStack24,uVar1);
  return;
}


/* __thiscall Act_c::set_moveBG_mtx_base(void) */

void __thiscall Act_c::set_moveBG_mtx_base(Act_c *this)

{
  int iVar1;
  
  iVar1 = *(int *)(this + 0x5f4);
  *(undefined4 *)(iVar1 + 0x18) = *(undefined4 *)(this + 0x214);
  *(undefined4 *)(iVar1 + 0x1c) = *(undefined4 *)(this + 0x218);
  *(undefined4 *)(iVar1 + 0x20) = *(undefined4 *)(this + 0x21c);
  mtx::PSMTXTrans((double)*(float *)(this + 0x1f8),(double)*(float *)(this + 0x1fc),
                  (double)*(float *)(this + 0x200),&mDoMtx_stack_c::now);
  m_Do_mtx::mDoMtx_YrotM(&mDoMtx_stack_c::now,*(short *)(this + 0x206));
  mtx::PSMTXCopy(&mDoMtx_stack_c::now,(MTX34 *)(this + 0x6d4));
  dBgW::Move(*(dBgW **)(this + 0x670));
  return;
}


/* __thiscall Act_c::set_moveBG_mtx_light_A(void) */

void __thiscall Act_c::set_moveBG_mtx_light_A(Act_c *this)

{
  mtx::PSMTXCopy((MTX34 *)(*(int *)(*(int *)(this + 0x5f4) + 0x8c) + 0xf0),&mDoMtx_stack_c::now);
  m_Do_mtx::mDoMtx_XYZrotM(&mDoMtx_stack_c::now,0,0,0xffffc000);
  mDoMtx_stack_c::transM(d_a_obj_search::_5957,d_a_obj_search::_5958,d_a_obj_search::_5959);
  mtx::PSMTXCopy(&mDoMtx_stack_c::now,(MTX34 *)(this + 0x674));
  dBgW::Move(*(dBgW **)(this + 0x668));
  return;
}


/* __thiscall Act_c::set_moveBG_mtx_light_B(void) */

void __thiscall Act_c::set_moveBG_mtx_light_B(Act_c *this)

{
  mtx::PSMTXCopy((MTX34 *)(*(int *)(*(int *)(this + 0x5f4) + 0x8c) + 0x120),&mDoMtx_stack_c::now);
  m_Do_mtx::mDoMtx_XYZrotM(&mDoMtx_stack_c::now,0,0,0xffffc000);
  mDoMtx_stack_c::transM(d_a_obj_search::_5973,d_a_obj_search::_5958,d_a_obj_search::_5974);
  mtx::PSMTXCopy(&mDoMtx_stack_c::now,(MTX34 *)(this + 0x6a4));
  dBgW::Move(*(dBgW **)(this + 0x66c));
  return;
}


/* __thiscall Act_c::bg_check(void) */

void __thiscall Act_c::bg_check(Act_c *this)

{
  double dVar1;
  
  dVar1 = (double)f_op_actor_mng::fopAcM_searchActorDistance
                            (this,d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor);
  if ((dVar1 <= (double)d_a_obj_search::_5984) && (this[0x7b8] == (Act_c)0x0)) {
    set_moveBG_mtx_light_A(this);
    set_moveBG_mtx_light_B(this);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x80102324) */
/* WARNING: Removing unreachable block (ram,0x8010232c) */
/* __thiscall Act_c::player_check(void) */

undefined4 __thiscall Act_c::player_check(Act_c *this)

{
  undefined2 uVar1;
  daPy_lk_c *pdVar2;
  int iVar3;
  fopAc_ac_c *pfVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  double dVar7;
  double dVar8;
  undefined8 in_f30;
  undefined8 in_f31;
  double dVar9;
  float fVar10;
  cXyz local_180;
  cXyz cStack372;
  cXyz local_168;
  cXyz local_15c;
  cXyz local_150;
  cXyz local_144;
  cXyz cStack312;
  cXyz local_12c;
  cXyz local_120;
  cXyz local_114;
  cXyz local_108;
  cXyz cStack252;
  cXyz local_f0;
  cXyz local_e4;
  cXyz local_d8;
  cXyz local_cc;
  cXyz local_c0;
  cXyz local_b4;
  cXyz local_a8;
  float local_9c;
  float local_98;
  float local_94;
  cXyz local_90;
  cXyz local_84;
  float local_78;
  float local_74;
  float local_70;
  cXyz local_6c;
  cXyz local_60;
  float local_54;
  float local_50;
  float local_4c;
  cXyz local_48;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  pdVar2 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor;
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  ::cXyz::operator__(&local_c0,
                     &((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).parent.
                      mCurrent.mPos,(cXyz *)(this + 0x624));
  local_48.x = local_c0.x;
  local_48.y = local_c0.y;
  local_48.z = local_c0.z;
  fVar10 = mtx::PSVECSquareMag(&local_48);
  dVar9 = (double)fVar10;
  if ((double)d_a_obj_search::0_0 < dVar9) {
    dVar7 = 1.0 / SQRT(dVar9);
    dVar7 = d_a_obj_search::_4435 * dVar7 * (d_a_obj_search::_4436 - dVar9 * dVar7 * dVar7);
    dVar7 = d_a_obj_search::_4435 * dVar7 * (d_a_obj_search::_4436 - dVar9 * dVar7 * dVar7);
    dVar9 = (double)(float)(dVar9 * d_a_obj_search::_4435 * dVar7 *
                                    (d_a_obj_search::_4436 - dVar9 * dVar7 * dVar7));
  }
  ::cXyz::operator__(&local_cc,&(pdVar2->parent).parent.mCurrent.mPos,(cXyz *)(this + 0x630));
  local_48.x = local_cc.x;
  local_48.y = local_cc.y;
  local_48.z = local_cc.z;
  fVar10 = mtx::PSVECSquareMag(&local_48);
  dVar7 = (double)fVar10;
  if ((double)d_a_obj_search::0_0 < dVar7) {
    dVar8 = 1.0 / SQRT(dVar7);
    dVar8 = d_a_obj_search::_4435 * dVar8 * (d_a_obj_search::_4436 - dVar7 * dVar8 * dVar8);
    dVar8 = d_a_obj_search::_4435 * dVar8 * (d_a_obj_search::_4436 - dVar7 * dVar8 * dVar8);
    dVar7 = (double)(float)(dVar7 * d_a_obj_search::_4435 * dVar8 *
                                    (d_a_obj_search::_4436 - dVar7 * dVar8 * dVar8));
  }
  *(undefined4 *)(this + 0x424) = *(undefined4 *)(this + 0x624);
  *(undefined4 *)(this + 0x428) = *(undefined4 *)(this + 0x628);
  *(undefined4 *)(this + 0x42c) = *(undefined4 *)(this + 0x62c);
  *(undefined4 *)(this + 0x430) = *(undefined4 *)(this + 0x63c);
  *(undefined4 *)(this + 0x434) = *(undefined4 *)(this + 0x640);
  *(undefined4 *)(this + 0x438) = *(undefined4 *)(this + 0x644);
  *(undefined4 *)(this + 0x440) = DAT_8035c0b8;
  cCcS::Set(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.parent,(cCcD_Obj *)(this + 0x30c));
  iVar3 = dCcD_GObjInf::ChkCoHit((dCcD_GObjInf *)(this + 0x30c));
  if (iVar3 != 0) {
    pfVar4 = dCcD_GAtTgCoCommonBase::GetAc((dCcD_GAtTgCoCommonBase *)(this + 1000));
    ::cXyz::operator__(&local_d8,&(pfVar4->mCurrent).mPos,(cXyz *)(this + 0x624));
    local_54 = local_d8.x;
    local_50 = local_d8.y;
    local_4c = local_d8.z;
    ::cXyz::operator__(&local_e4,(cXyz *)(this + 0x63c),(cXyz *)(this + 0x624));
    local_6c.x = local_e4.x;
    local_6c.y = local_e4.y;
    local_6c.z = local_e4.z;
    ::cXyz::normZP(&local_f0,&local_6c);
    local_60.x = local_f0.x;
    local_60.y = local_f0.y;
    local_60.z = local_f0.z;
    dVar8 = (double)mtx::PSVECDotProduct(&local_60,&local_54);
    ::cXyz::operator_(&cStack252,&local_60,(float)(dVar8 - (double)d_a_obj_search::_6390));
    ::cXyz::operator__(&local_108,(cXyz *)(this + 0x624),&cStack252);
    *(float *)(this + 0x780) = local_108.x;
    *(float *)(this + 0x784) = local_108.y;
    *(float *)(this + 0x788) = local_108.z;
    uVar1 = DAT_8035c0e0;
    *(undefined2 *)(this + 0x78c) = DAT_8035c0e0;
    *(undefined2 *)(this + 0x78e) = uVar1;
    *(undefined4 *)(this + 0x794) = DAT_8035c0e4;
    if ((pfVar4->parent).parent.mProcName == 0xa9) {
      if ((dVar9 < (double)d_a_obj_search::_5984) || (dVar7 < (double)d_a_obj_search::_5984)) {
        uVar5 = 0;
        goto LAB_80102324;
      }
      if ((d_a_obj_search::_4951 <= ABS((pdVar2->parent).parent.mVelocityFwd)) ||
         (d_a_obj_search::0_0 <= (pdVar2->parent).field_0x2b0)) {
        uVar5 = 1;
        goto LAB_80102324;
      }
    }
  }
  *(undefined4 *)(this + 0x55c) = *(undefined4 *)(this + 0x630);
  *(undefined4 *)(this + 0x560) = *(undefined4 *)(this + 0x634);
  *(undefined4 *)(this + 0x564) = *(undefined4 *)(this + 0x638);
  *(undefined4 *)(this + 0x568) = *(undefined4 *)(this + 0x648);
  *(undefined4 *)(this + 0x56c) = *(undefined4 *)(this + 0x64c);
  *(undefined4 *)(this + 0x570) = *(undefined4 *)(this + 0x650);
  *(undefined4 *)(this + 0x578) = DAT_8035c0b8;
  cCcS::Set(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCcS.parent,(cCcD_Obj *)(this + 0x444));
  iVar3 = dCcD_GObjInf::ChkCoHit((dCcD_GObjInf *)(this + 0x444));
  if (iVar3 != 0) {
    pfVar4 = dCcD_GAtTgCoCommonBase::GetAc((dCcD_GAtTgCoCommonBase *)(this + 0x520));
    ::cXyz::operator__(&local_114,&(pfVar4->mCurrent).mPos,(cXyz *)(this + 0x630));
    local_78 = local_114.x;
    local_74 = local_114.y;
    local_70 = local_114.z;
    ::cXyz::operator__(&local_120,(cXyz *)(this + 0x648),(cXyz *)(this + 0x630));
    local_90.x = local_120.x;
    local_90.y = local_120.y;
    local_90.z = local_120.z;
    ::cXyz::normZP(&local_12c,&local_90);
    local_84.x = local_12c.x;
    local_84.y = local_12c.y;
    local_84.z = local_12c.z;
    dVar8 = (double)mtx::PSVECDotProduct(&local_84,&local_78);
    ::cXyz::operator_(&cStack312,&local_84,(float)(dVar8 - (double)d_a_obj_search::_6390));
    ::cXyz::operator__(&local_144,(cXyz *)(this + 0x630),&cStack312);
    *(float *)(this + 0x780) = local_144.x;
    *(float *)(this + 0x784) = local_144.y;
    *(float *)(this + 0x788) = local_144.z;
    uVar1 = DAT_8035c0e0;
    *(undefined2 *)(this + 0x78c) = DAT_8035c0e0;
    *(undefined2 *)(this + 0x78e) = uVar1;
    *(undefined4 *)(this + 0x794) = DAT_8035c0e4;
    if ((dVar9 < (double)d_a_obj_search::_5984) || (dVar7 < (double)d_a_obj_search::_5984)) {
      uVar5 = 0;
      goto LAB_80102324;
    }
    if ((d_a_obj_search::_4951 <= ABS((pdVar2->parent).parent.mVelocityFwd)) ||
       (d_a_obj_search::0_0 <= (pdVar2->parent).field_0x2b0)) {
      uVar5 = 1;
      goto LAB_80102324;
    }
  }
  iVar3 = dCcD_GObjInf::ChkCoHit((dCcD_GObjInf *)(this + 0x30c));
  if ((iVar3 == 0) && (iVar3 = dCcD_GObjInf::ChkCoHit((dCcD_GObjInf *)(this + 0x444)), iVar3 == 0))
  {
    ::cXyz::operator__(&local_150,(cXyz *)(this + 0x60c),(cXyz *)(this + 0x624));
    local_9c = local_150.x;
    local_98 = local_150.y;
    local_94 = local_150.z;
    ::cXyz::operator__(&local_15c,(cXyz *)(this + 0x63c),(cXyz *)(this + 0x624));
    local_b4.x = local_15c.x;
    local_b4.y = local_15c.y;
    local_b4.z = local_15c.z;
    ::cXyz::normZP(&local_168,&local_b4);
    local_a8.x = local_168.x;
    local_a8.y = local_168.y;
    local_a8.z = local_168.z;
    dVar9 = (double)mtx::PSVECDotProduct(&local_a8,&local_9c);
    ::cXyz::operator_(&cStack372,&local_a8,(float)(dVar9 - (double)d_a_obj_search::_6390));
    ::cXyz::operator__(&local_180,(cXyz *)(this + 0x624),&cStack372);
    *(float *)(this + 0x780) = local_180.x;
    *(float *)(this + 0x784) = local_180.y;
    *(float *)(this + 0x788) = local_180.z;
    uVar1 = DAT_8035c0e0;
    *(undefined2 *)(this + 0x78c) = DAT_8035c0e0;
    *(undefined2 *)(this + 0x78e) = uVar1;
    *(undefined4 *)(this + 0x794) = DAT_8035c0e4;
  }
  uVar5 = 0;
LAB_80102324:
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  __psq_l0(auStack24,uVar6);
  __psq_l1(auStack24,uVar6);
  return uVar5;
}


/* __thiscall Act_c::set_path_info(void) */

uint __thiscall Act_c::set_path_info(Act_c *this)

{
  uint uVar1;
  
  if ((byte)this[0x837] == 0xff) {
    uVar1 = 0;
  }
  else {
    uVar1 = d_lib::dLib_pathInfo((dPath **)(this + 0x848),(uint)(byte)this[0x837]);
  }
  return uVar1;
}


/* __thiscall Act_c::is_path_info(void) */

int __thiscall Act_c::is_path_info(Act_c *this)

{
  int iVar1;
  
  iVar1 = -(uint)(byte)this[0x837] + 0xff;
  return iVar1 - ((uint)(iVar1 == 0) + -(uint)(byte)this[0x837] + 0xfe);
}


/* __thiscall Act_c::_draw(void) */

undefined4 __thiscall Act_c::_draw(Act_c *this)

{
  Act_c AVar1;
  dDlst_alphaModel_c *pdVar2;
  undefined4 uVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  u8 uStack22;
  u8 uStack21;
  u8 uStack18;
  u8 uStack17;
  undefined4 local_10 [2];
  
  if (DAT_8035c091 == '\0') {
    mDoLib_clipper::mClipper.mFar = d_a_obj_search::_6526;
    J3DUClipper::calcViewFrustum(&mDoLib_clipper::mClipper);
    if (DAT_8035c0d4 == '\0') {
      uVar4 = f_op_actor_mng::fopAcM_checkCullingBox
                        ((MTX34 *)(*(int *)(this + 0x5f4) + 0x24),d_a_obj_search::_5216,
                         d_a_obj_search::0_0,d_a_obj_search::_5216,d_a_obj_search::_4948,
                         d_a_obj_search::_5217,d_a_obj_search::_4948);
      this[0x7b8] = SUB41(uVar4,0);
    }
    if (DAT_8035c0d5 == '\0') {
      uVar4 = f_op_actor_mng::fopAcM_checkCullingBox
                        ((MTX34 *)(*(int *)(this + 0x5f8) + 0x24),d_a_obj_search::_6527,
                         d_a_obj_search::_6527,d_a_obj_search::_6528,d_a_obj_search::_6529,
                         d_a_obj_search::_6529,d_a_obj_search::_6530);
      this[0x7b6] = SUB41(uVar4,0);
    }
    if (DAT_8035c0d6 == '\0') {
      uVar4 = f_op_actor_mng::fopAcM_checkCullingBox
                        ((MTX34 *)(*(int *)(this + 0x5fc) + 0x24),d_a_obj_search::_6527,
                         d_a_obj_search::_6527,d_a_obj_search::_6528,d_a_obj_search::_6529,
                         d_a_obj_search::_6529,d_a_obj_search::_6530);
      this[0x7b7] = SUB41(uVar4,0);
    }
    mDoLib_clipper::mClipper.mFar = mDoLib_clipper::mSystemFar;
    J3DUClipper::calcViewFrustum(&mDoLib_clipper::mClipper);
    if (this[0x7b8] == (Act_c)0x0) {
      if (this[0x836] == (Act_c)0x1) {
        dScnKy_env_light_c::settingTevStruct
                  (&d_kankyo::g_env_light,BG0,(cXyz *)(this + 0x1f8),(dKy_tevstr_c *)(this + 0x10c))
        ;
        *(s16 *)(this + 0x18c) = d_kankyo::g_env_light.mActorC0.r;
        *(s16 *)(this + 0x18e) = d_kankyo::g_env_light.mActorC0.g;
        *(s16 *)(this + 400) = d_kankyo::g_env_light.mActorC0.b;
        *(s16 *)(this + 0x192) = d_kankyo::g_env_light.mActorC0.a;
        this[0x194] = SUB21(d_kankyo::g_env_light.mActorK0.r,0);
        this[0x195] = SUB21(d_kankyo::g_env_light.mActorK0.g,0);
        this[0x196] = SUB21(d_kankyo::g_env_light.mActorK0.b,0);
      }
      else {
        dScnKy_env_light_c::settingTevStruct
                  (&d_kankyo::g_env_light,Actor,(cXyz *)(this + 0x1f8),
                   (dKy_tevstr_c *)(this + 0x10c));
      }
      dScnKy_env_light_c::setLightTevColorType
                (&d_kankyo::g_env_light,*(J3DModel **)(this + 0x5f4),(dKy_tevstr_c *)(this + 0x10c))
      ;
      m_Do_ext::mDoExt_modelEntryDL(*(J3DModel **)(this + 0x5f4));
    }
    if ((this[0x7b6] == (Act_c)0x0) &&
       (m_Do_ext::mDoExt_modelUpdateDL(*(J3DModel **)(this + 0x5f8)),
       0x80 < *(short *)(this + 0x77e))) {
      dDlst_alphaModel_c::set
                (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpAlphaModel0,BeamCheck,
                 (MTX34 *)(this + 0x71c),0x20);
      uVar3 = d_a_obj_search::_6426;
      pdVar2 = d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpAlphaModel0;
      AVar1 = this[0x82d];
      *(Act_c *)&((d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpAlphaModel0)->mColor).r =
           this[0x82c];
      *(Act_c *)&(pdVar2->mColor).g = AVar1;
      uStack18 = (u8)((uint)uVar3 >> 8);
      (pdVar2->mColor).b = uStack18;
      uStack17 = (u8)uVar3;
      (pdVar2->mColor).a = uStack17;
    }
    if ((this[0x7b7] == (Act_c)0x0) &&
       (m_Do_ext::mDoExt_modelUpdateDL(*(J3DModel **)(this + 0x5fc)),
       0x80 < *(short *)(this + 0x77e))) {
      dDlst_alphaModel_c::set
                (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpAlphaModel0,BeamCheck,
                 (MTX34 *)(this + 0x74c),0x20);
      uVar3 = d_a_obj_search::_6432;
      pdVar2 = d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpAlphaModel0;
      AVar1 = this[0x82d];
      *(Act_c *)&((d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpAlphaModel0)->mColor).r =
           this[0x82c];
      *(Act_c *)&(pdVar2->mColor).g = AVar1;
      uStack22 = (u8)((uint)uVar3 >> 8);
      (pdVar2->mColor).b = uStack22;
      uStack21 = (u8)uVar3;
      (pdVar2->mColor).a = uStack21;
    }
    piVar5 = *(int **)(**(int **)(*(int *)(*(int *)(this + 0x5f8) + 4) + 0x60) + 0x2c);
    iVar6 = (**(code **)(*piVar5 + 0x74))(piVar5,0);
    *(char *)(iVar6 + 3) = (char)*(undefined2 *)(this + 0x77e);
    if (DAT_8035c0d7 != '\0') {
      local_10[0] = d_a_obj_search::color_ng_6436;
      if (this[0x8ee] != (Act_c)0x0) {
        local_10[0] = CONCAT31(CONCAT21(CONCAT11(d_a_obj_search::color_ok_6435,UNK_803fa099),
                                        UNK_803fa09a),UNK_803fa09b);
      }
      d_lib::dLib_debugDrawFan
                ((double)*(float *)(this + 0x8e4),this + 0x8d4,(int)*(short *)(this + 0x8e0),
                 (int)*(short *)(this + 0x8ec),local_10);
    }
  }
  return 1;
}


/* __thiscall Act_c::_delete(void) */

undefined4 __thiscall Act_c::_delete(Act_c *this)

{
  bool bVar1;
  int iVar2;
  cBgW *pcVar3;
  
  d_kankyo::dKy_plight_cut((LIGHT_INFLUENCE *)(this + 0x780));
  pcVar3 = *(cBgW **)(this + 0x668);
  if (pcVar3 != (cBgW *)0x0) {
    if (((int)pcVar3->mCount < 0) || (0xff < (int)pcVar3->mCount)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      cBgS::Release((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,pcVar3);
    }
  }
  pcVar3 = *(cBgW **)(this + 0x66c);
  if (pcVar3 != (cBgW *)0x0) {
    if (((int)pcVar3->mCount < 0) || (0xff < (int)pcVar3->mCount)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      cBgS::Release((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,pcVar3);
    }
  }
  pcVar3 = *(cBgW **)(this + 0x670);
  if (pcVar3 != (cBgW *)0x0) {
    if (((int)pcVar3->mCount < 0) || (0xff < (int)pcVar3->mCount)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      cBgS::Release((cBgS *)&d_com_inf_game::g_dComIfG_gameInfo.mPlay,pcVar3);
    }
  }
  d_com_inf_game::dComIfG_resDelete((request_of_phase_process_class *)(this + 0x854),"Search");
  (**(code **)(*(int *)(this + 0x808) + 0x20))(this + 0x808);
  iVar2 = JAIZelBasic::checkSePlaying(JAIZelBasic::zel_basic,0x834);
  if (iVar2 != 0) {
    JAIZelBasic::seStop(JAIZelBasic::zel_basic,0x834,0);
  }
  return 1;
}


/* __thiscall Act_c::_isdelete(void) */

undefined4 __thiscall Act_c::_isdelete(Act_c *this)

{
  return 1;
}


/* __thiscall Mthd::Create(void *) */

void __thiscall Mthd::Create(Mthd *this,void *param_1)

{
  Act_c::_create((Act_c *)this);
  return;
}


/* __thiscall Mthd::Delete(void *) */

void __thiscall Mthd::Delete(Mthd *this,void *param_1)

{
  Act_c::_delete((Act_c *)this);
  return;
}


/* __thiscall Mthd::Execute(void *) */

void __thiscall Mthd::Execute(Mthd *this,void *param_1)

{
  Act_c::_execute((Act_c *)this);
  return;
}


/* __thiscall Mthd::Draw(void *) */

void __thiscall Mthd::Draw(Mthd *this,void *param_1)

{
  Act_c::_draw((Act_c *)this);
  return;
}


/* __thiscall Mthd::IsDelete(void *) */

void __thiscall Mthd::IsDelete(Mthd *this,void *param_1)

{
  Act_c::_isdelete((Act_c *)this);
  return;
}

}

/* [thunk]:__thiscall dBgS_ObjLinChk::~dBgS_ObjLinChk(void) */

void __thiscall dBgS_ObjLinChk::_dBgS_ObjLinChk(dBgS_ObjLinChk *this)

{
  _dBgS_ObjLinChk(this + -0x14);
  return;
}


/* [thunk]:__thiscall dBgS_ObjLinChk::~dBgS_ObjLinChk(void) */

void __thiscall dBgS_ObjLinChk::_dBgS_ObjLinChk(dBgS_ObjLinChk *this)

{
  _dBgS_ObjLinChk(this + -100);
  return;
}


/* [thunk]:__thiscall dBgS_ObjLinChk::~dBgS_ObjLinChk(void) */

void __thiscall dBgS_ObjLinChk::_dBgS_ObjLinChk(dBgS_ObjLinChk *this)

{
  _dBgS_ObjLinChk(this + -0x58);
  return;
}

