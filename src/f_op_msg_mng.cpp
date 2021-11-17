#include <f_op_msg_mng.h>
#include <mtx/mtx.h>
#include <f_op_scene_mng.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <f_pc_base.h>
#include <f_pc_priority.h>
#include <f_pc_executor.h>
#include <f_pc_searcher.h>
#include <f_pc_layer_iter.h>
#include <f_pc_manager.h>
#include <SComponent/c_malloc.h>
#include <f_op_msg_mng.h>
#include <f_pc_layer.h>
#include <f_pc_stdcreate_req.h>
#include <JKernel/JKRFileLoader.h>
#include <JKernel/JKRHeap.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <J2DGraph/J2DTextBox.h>
#include <J2DGraph/J2DPicture.h>
#include <JKernel/JKRArchivePub.h>
#include <d_save.h>
#include <MSL_C.PPCEABI.bare.H/printf.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <d_lib.h>
#include <d_com_inf_game.h>
#include <m_Do_ext.h>
#include <JKernel/JKRExpHeap.h>
#include <fopMsgM_msgGet_c.h>
#include <MyPicture.h>
#include <J2DPane.h>
#include <Demangler/J2DPicture.h>
#include <fopMsgM_msgDataProc_c.h>
#include <fopMsgM_itemMsgGet_c.h>


namespace f_op_msg_mng {
struct STControl stick;
undefined1 pushButton;
undefined1 pushButton2;
undefined1 demoFlag;
undefined1 tactFlag;
undefined1 nextMsg;
undefined4 name$7641;
undefined1 init$7642;
undefined4 name$7700;
undefined1 init$7701;
}

/* __thiscall MyPicture::drawSelf(float,
                                  float) */

void __thiscall MyPicture::drawSelf(MyPicture *this,float param_1,float param_2)

{
  double dVar1;
  double dVar2;
  MTX34 MStack72;
  
  dVar2 = (double)param_2;
  dVar1 = (double)param_1;
  mtx::PSMTXIdentity(&MStack72);
  (*(code *)((this->parent).parent.vtbl)->drawSelf2)(dVar1,dVar2,this,&MStack72);
  return;
}


/* __thiscall MyPicture::drawSelf(float,
                                  float,
                                  float *[][][]) */

void __thiscall MyPicture::drawSelf(MyPicture *this,float param_1,float param_2,float *param_3)

{
  byte bVar1;
  
  if ((this->parent).mpTexture[0] != (JUTTexture *)0x0) {
    bVar1 = (this->parent).field_0xdf;
    (*(code *)(this->parent).parent.vtbl[1]._J2DPane)
              ((double)((this->parent).parent.mScreenPos.mTL.x + param_1),
               (double)((this->parent).parent.mScreenPos.mTL.y + param_2),
               (double)((this->parent).parent.mPosBR.x - (this->parent).parent.mPosTL.x),
               (double)((this->parent).parent.mPosBR.y - (this->parent).parent.mPosTL.y),this,
               (this->parent).field_0xde,bVar1 & 3,bVar1 >> 2 & 1,param_3);
  }
  return;
}


namespace f_op_msg_mng {

/* __stdcall fopMsgM_hyrule_language_check(unsigned long) */

bool fopMsgM_hyrule_language_check(int msg_id)

{
  if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mInfo.mNumGamesCompleted != 0) {
    return false;
  }
  if (msg_id != 0xd56) {
    if (0xd55 < msg_id) {
      if (msg_id == 0x117a) {
        return true;
      }
      if (msg_id < 0x117a) {
        if (msg_id == 0xd59) {
          return true;
        }
        if (msg_id < 0xd59) {
          if (0xd57 < msg_id) {
            return false;
          }
          return true;
        }
        if (msg_id != 0x1178) {
          return false;
        }
        return true;
      }
      if (msg_id == 0x196e) {
        return true;
      }
      if (0x196d < msg_id) {
        return false;
      }
      if (0x138a < msg_id) {
        return false;
      }
      if (5000 < msg_id) {
        return true;
      }
      return false;
    }
    if (msg_id != 0xd4e) {
      if (msg_id < 0xd4e) {
        if (msg_id == 0xd4b) {
          return true;
        }
        if (msg_id < 0xd4b) {
          if (msg_id == 0xd49) {
            return true;
          }
        }
        else {
          if (0xd4c < msg_id) {
            return true;
          }
        }
      }
      else {
        if (msg_id == 0xd51) {
          return true;
        }
        if (msg_id < 0xd51) {
          if (msg_id < 0xd50) {
            return true;
          }
        }
        else {
          if (0xd52 < msg_id) {
            return true;
          }
        }
      }
    }
  }
  return false;
}


/* __stdcall fopMsgM_setStageLayer(void *) */

void fopMsgM_setStageLayer(int param_1)

{
  scene_class *psVar1;
  ulong uVar2;
  bool bVar3;
  uint uVar4;
  
  psVar1 = f_op_scene_mng::fopScnM_SearchByID(dStage_roomControl_c::mProcID);
  if (psVar1 == (scene_class *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"f_op_msg_mng.cpp",0x189,"stageProc != 0");
    m_Do_printf::OSPanic("f_op_msg_mng.cpp",0x189,&DAT_8033c3e5);
  }
  bVar3 = f_pc_base::fpcBs_Is_JustOfType(f_pc_node::g_fpcNd_type,(psVar1->parent).parent.mSubType);
  if (bVar3 == false) {
    uVar4 = 0xffffffff;
  }
  else {
    uVar4 = (psVar1->parent).mLayer.mLayerID;
  }
  f_pc_priority::fpcPi_Change((process_priority_class *)(param_1 + 0x68),uVar4,0xfffd,0xfffd);
  return;
}


/* __stdcall fopMsgM_SearchByID(unsigned int) */

msg_class * fopMsgM_SearchByID(uint param_1)

{
  msg_class *pmVar1;
  
  pmVar1 = (msg_class *)f_pc_executor::fpcEx_SearchByID(param_1);
  return pmVar1;
}


/* __stdcall fopMsgM_SearchByName(short) */

void fopMsgM_SearchByName(undefined2 param_1)

{
  undefined2 local_8 [4];
  
  local_8[0] = param_1;
  f_pc_layer_iter::fpcLyIt_AllJudge(f_pc_searcher::fpcSch_JudgeForPName,local_8);
  return;
}


/* __stdcall fopMsgM_IsExecuting(unsigned int) */

void fopMsgM_IsExecuting(void)

{
  f_pc_executor::fpcEx_IsExist();
  return;
}


/* __stdcall fopMsgM_GetAppend(void *) */

fopMsgM_prm_class * fopMsgM_GetAppend(msg_class *param_1)

{
  return (fopMsgM_prm_class *)(param_1->parent).parent.mpUserData;
}


/* __stdcall fopMsgM_Delete(void *) */

void fopMsgM_Delete(base_process_class *param_1)

{
  f_pc_manager::fpcM_Delete(param_1);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __stdcall createAppend(fopAc_ac_c *,
                          cXyz *,
                          unsigned long *,
                          unsigned long *,
                          unsigned int) */

fopMsgM_prm_class *
createAppend(fopAc_ac_c *pActor,cXyz *pPos,int *param_3,int *param_4,int param_5)

{
  float fVar1;
  fopMsgM_prm_class *pAppend;
  
  pAppend = (fopMsgM_prm_class *)cMl::memalignB(-4,0x1c);
  if (pAppend == (fopMsgM_prm_class *)0x0) {
    pAppend = (fopMsgM_prm_class *)0x0;
  }
  else {
    pAppend->mpActor = pActor;
    if (param_3 != (int *)0x0) {
      pAppend->field_0x10 = *param_3;
    }
    if (param_4 != (int *)0x0) {
      pAppend->field_0x14 = *param_4;
    }
    fVar1 = 0_0;
    if (pPos == (cXyz *)0x0) {
      (pAppend->mPos).x = 0_0;
      (pAppend->mPos).y = fVar1;
      (pAppend->mPos).z = fVar1;
    }
    else {
      (pAppend->mPos).x = pPos->x;
      (pAppend->mPos).y = pPos->y;
      (pAppend->mPos).z = pPos->z;
    }
    pAppend->field_0x18 = param_5;
  }
  return pAppend;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __stdcall createMGameTermAppend(short,
                                   short,
                                   int,
                                   int,
                                   unsigned int) */

undefined4 *
createMGameTermAppend
          (undefined2 param_1,undefined2 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5)

{
  float fVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)cMl::memalignB(-4,0x28);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = 0;
    puVar2[4] = 0;
    puVar2[5] = 0;
    fVar1 = 0_0;
    puVar2[1] = 0_0;
    puVar2[2] = fVar1;
    puVar2[3] = fVar1;
    puVar2[6] = param_5;
    *(undefined2 *)(puVar2 + 9) = param_1;
    *(undefined2 *)((int)puVar2 + 0x26) = param_2;
    puVar2[7] = param_3;
    puVar2[8] = param_4;
  }
  return puVar2;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x8002b1a0) */
/* WARNING: Removing unreachable block (ram,0x8002b190) */
/* WARNING: Removing unreachable block (ram,0x8002b198) */
/* WARNING: Removing unreachable block (ram,0x8002b1a8) */
/* __stdcall createTimerAppend(int,
                               unsigned short,
                               unsigned char,
                               unsigned char,
                               float,
                               float,
                               float,
                               float,
                               unsigned int) */

fopMsgM_prm_class *
createTimerAppend
          (int param_1,int param_2,int param_3,float param_4,float param_5,float param_6,
          float param_7,int param_8)

{
  float fVar1;
  fopMsgM_prm_class *pfVar2;
  int in_r7;
  undefined4 uVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  undefined8 in_f28;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar6 = (double)param_6;
  dVar7 = (double)param_7;
  dVar5 = (double)param_5;
  dVar4 = (double)param_4;
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  pfVar2 = (fopMsgM_prm_class *)cMl::memalignB(-4,0x34);
  if (pfVar2 == (fopMsgM_prm_class *)0x0) {
    pfVar2 = (fopMsgM_prm_class *)0x0;
  }
  else {
    pfVar2->mpActor = (fopAc_ac_c *)0x0;
    pfVar2->field_0x10 = 0;
    pfVar2->field_0x14 = 0;
    fVar1 = 0_0;
    (pfVar2->mPos).x = 0_0;
    (pfVar2->mPos).y = fVar1;
    (pfVar2->mPos).z = fVar1;
    pfVar2->field_0x18 = in_r7;
    pfVar2[1].mpActor = (fopAc_ac_c *)param_1;
    *(short *)&pfVar2[1].mPos.x = (short)param_2;
    *(char *)((int)&pfVar2[1].mPos.x + 2) = (char)param_3;
    *(char *)((int)&pfVar2[1].mPos.x + 3) = (char)param_8;
    pfVar2[1].mPos.y = (float)dVar4;
    pfVar2[1].mPos.z = (float)dVar5;
    pfVar2[1].field_0x10 = (int)(float)dVar6;
    pfVar2[1].field_0x14 = (int)(float)dVar7;
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  __psq_l0(auStack24,uVar3);
  __psq_l1(auStack24,uVar3);
  __psq_l0(auStack40,uVar3);
  __psq_l1(auStack40,uVar3);
  __psq_l0(auStack56,uVar3);
  __psq_l1(auStack56,uVar3);
  return pfVar2;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall fopMsgM_create(short,
                            fopAc_ac_c *,
                            cXyz *,
                            unsigned long *,
                            unsigned long *,
                            int *(void *)) */

undefined4
fopMsgM_create
          (short param_1,fopAc_ac_c *param_2,cXyz *param_3,int *param_4,int *param_5,
          undefined *param_6)

{
  fopMsgM_prm_class *pfVar1;
  undefined4 uVar2;
  layer_class *plVar3;
  
  pfVar1 = createAppend(param_2,param_3,param_4,param_5,-1);
  if (pfVar1 == (fopMsgM_prm_class *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    plVar3 = f_pc_layer::fpcLy_CurrentLayer();
    uVar2 = f_pc_stdcreate_req::fpcSCtRq_Request(plVar3,param_1,param_6,(void *)0x0,pfVar1);
  }
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall fop_MGameTerm_create(short,
                                  short,
                                  short,
                                  int,
                                  int,
                                  int *(void *)) */

undefined4
fop_MGameTerm_create
          (short param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
          ,undefined *param_6)

{
  void *pvVar1;
  undefined4 uVar2;
  layer_class *plVar3;
  
  pvVar1 = (void *)createMGameTermAppend(param_2,param_3,param_4,param_5,0xffffffff);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    plVar3 = f_pc_layer::fpcLy_CurrentLayer();
    uVar2 = f_pc_stdcreate_req::fpcSCtRq_Request(plVar3,param_1,param_6,(void *)0x0,pvVar1);
  }
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall fop_Timer_create(short,
                              unsigned char,
                              unsigned short,
                              unsigned char,
                              unsigned char,
                              float,
                              float,
                              float,
                              float,
                              int *(void *)) */

undefined4
fop_Timer_create
          (double param_1,double param_2,double param_3,double param_4,short param_5,uint param_6,
          int param_7,int param_8,int param_9,undefined *param_10)

{
  fopMsgM_prm_class *pfVar1;
  undefined4 uVar2;
  layer_class *plVar3;
  
  pfVar1 = createTimerAppend(param_6 & 0xff,param_7,param_8,(float)param_1,(float)param_2,
                             (float)param_3,(float)param_4,param_9);
  if (pfVar1 == (fopMsgM_prm_class *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    plVar3 = f_pc_layer::fpcLy_CurrentLayer();
    uVar2 = f_pc_stdcreate_req::fpcSCtRq_Request(plVar3,param_5,param_10,(void *)0x0,pfVar1);
  }
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __stdcall fopMsgM_messageTypeSelect(fopAc_ac_c *,
                                       cXyz *,
                                       unsigned long *,
                                       unsigned long *) */

undefined4
fopMsgM_messageTypeSelect
          (fopAc_ac_c *param_1,cXyz *param_2,ulong *param_3,ulong *param_4)

{
  uint uVar1;
  undefined4 uVar2;
  mesg_header *pmVar3;
  int iVar4;
  undefined1 *local_48;
  undefined4 local_44;
  undefined2 local_40;
  undefined2 local_3e;
  undefined2 local_3c;
  fopMsgM_msgGet_c afStack56 [6];
  undefined2 local_32;
  char local_2c;
  byte local_26;
  byte local_25;
  
  local_48 = &::fopMsgM_msgGet_c::__vt;
  local_44 = 0;
  local_40 = 0;
  local_3e = 0;
  local_3c = 0;
  uVar1 = *param_3 >> 0x10;
  if (uVar1 == 99) {
    uVar2 = fopMsgM_create(499,param_1,param_2,(int *)param_3,(int *)param_4,(undefined *)0x0);
  }
  else {
    if (uVar1 == 0x59) {
      uVar2 = fopMsgM_create(500,param_1,param_2,(int *)param_3,(int *)param_4,(undefined *)0x0);
    }
    else {
      pmVar3 = (mesg_header *)
               ::fopMsgM_msgGet_c::getMesgHeader((fopMsgM_msgGet_c *)&local_48,*param_3);
      if (pmVar3 == (mesg_header *)0x0) {
        *param_3 = 1;
        *param_4 = *param_3;
        uVar2 = fopMsgM_create(0x1e7,param_1,param_2,(int *)param_3,(int *)param_4,(undefined *)0x0)
        ;
      }
      else {
        iVar4 = ::fopMsgM_msgGet_c::getMessage((fopMsgM_msgGet_c *)&local_48,pmVar3);
        if (iVar4 == 0) {
          *param_3 = 1;
          *param_4 = *param_3;
          uVar2 = fopMsgM_create(0x1e7,param_1,param_2,(int *)param_3,(int *)param_4,
                                 (undefined *)0x0);
        }
        else {
          ::fopMsgM_msgGet_c::getMesgEntry(afStack56,(mesg_header *)&local_48);
          d_com_inf_game::g_dComIfG_gameInfo.field_0x5bdb = local_25;
          d_com_inf_game::g_dComIfG_gameInfo._23588_4_ = (uint)local_26;
          d_com_inf_game::g_dComIfG_gameInfo._23484_2_ = local_32;
          if (((local_2c == '\x02') || (local_2c == '\x06')) || (local_2c == '\a')) {
            uVar2 = fopMsgM_create(0x1e8,param_1,param_2,(int *)param_3,(int *)param_4,
                                   (undefined *)0x0);
          }
          else {
            uVar2 = fopMsgM_create(0x1e7,param_1,param_2,(int *)param_3,(int *)param_4,
                                   (undefined *)0x0);
          }
        }
      }
      JKRFileLoader::removeResource(pmVar3,(JKRFileLoader *)0x0);
    }
  }
  return uVar2;
}

}

/* __thiscall fopMsgM_msgGet_c::~fopMsgM_msgGet_c(void) */

void __thiscall fopMsgM_msgGet_c::_fopMsgM_msgGet_c(fopMsgM_msgGet_c *this)

{
  short in_r4;
  
  if ((this != (fopMsgM_msgGet_c *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


namespace f_op_msg_mng {

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall fopMsgM_searchMessageNumber(unsigned long) */

uint fopMsgM_searchMessageNumber(uint param_1)

{
  mesg_header *pmVar1;
  int iVar2;
  uint uVar3;
  uint msg_id;
  undefined1 *local_28;
  undefined4 local_24;
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  
  local_28 = &::fopMsgM_msgGet_c::__vt;
  local_24 = 0;
  local_20 = 0;
  local_1e = 0;
  local_1c = 0;
  msg_id = param_1 & 0xffff;
  while ((uVar3 = param_1, msg_id < 0xffff &&
         ((pmVar1 = (mesg_header *)
                    ::fopMsgM_msgGet_c::getMesgHeader((fopMsgM_msgGet_c *)&local_28,msg_id),
          pmVar1 == (mesg_header *)0x0 ||
          (iVar2 = ::fopMsgM_msgGet_c::getMessage((fopMsgM_msgGet_c *)&local_28,pmVar1),
          uVar3 = msg_id, iVar2 == 0))))) {
    JKRFileLoader::removeResource(pmVar1,(JKRFileLoader *)0x0);
    msg_id = msg_id + 1;
  }
  return uVar3;
}


/* __stdcall fopMsgM_messageSet(unsigned long,
                                fopAc_ac_c *) */

uint fopMsgM_messageSet(ulong msgId,fopAc_ac_c *actor)

{
  uint uVar1;
  int iVar2;
  msg_class *pmVar3;
  ulong local_18;
  cXyz local_14;
  
  if ((((d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 == 0) ||
       (d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 == 7)) ||
      (d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 == 8)) ||
     (d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 == 9)) {
    d_com_inf_game::g_dComIfG_gameInfo.mMesgAnimeTagInfo = 0xff;
    d_com_inf_game::g_dComIfG_gameInfo.mMesgCameraTagInfo = -1;
    local_14.x = (actor->mEyePos).x;
    local_14.y = (actor->mEyePos).y;
    local_14.z = (actor->mEyePos).z;
    local_18 = msgId;
    if (i_msgID == 0xffffffff) {
      uVar1 = fopMsgM_messageTypeSelect(actor,&local_14,&local_18,&local_18);
      i_msgID = uVar1;
    }
    else {
      iVar2 = fopMsgM_IsExecuting();
      if (iVar2 == 0) {
        uVar1 = fopMsgM_messageTypeSelect(actor,&local_14,&local_18,&local_18);
        i_msgID = uVar1;
      }
      else {
        pmVar3 = fopMsgM_SearchByID(i_msgID);
        if (pmVar3 == (msg_class *)0x0) {
          i_msgID = 0xffffffff;
          uVar1 = i_msgID;
        }
        else {
          pmVar3->field_0xec = local_18;
          pmVar3->field_0xf0 = local_18;
          iVar2 = fopMsgM_SearchByName(499);
          if ((iVar2 != 0) || (iVar2 = fopMsgM_SearchByName(500), uVar1 = i_msgID, iVar2 != 0)) {
            fopMsgM_Delete(pmVar3);
            i_msgID = 0xffffffff;
            uVar1 = i_msgID;
          }
        }
      }
    }
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


/* __stdcall fopMsgM_messageSet(unsigned long,
                                cXyz *) */

uint fopMsgM_messageSet(ulong param_1,cXyz *param_2)

{
  uint uVar1;
  int iVar2;
  msg_class *pmVar3;
  ulong local_18 [5];
  
  if ((((d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 == 0) ||
       (d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 == 7)) ||
      (d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 == 8)) ||
     (d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 == 9)) {
    d_com_inf_game::g_dComIfG_gameInfo.mMesgAnimeTagInfo = 0xff;
    d_com_inf_game::g_dComIfG_gameInfo.mMesgCameraTagInfo = -1;
    local_18[0] = param_1;
    if (i_msgID == 0xffffffff) {
      uVar1 = fopMsgM_messageTypeSelect((fopAc_ac_c *)0x0,param_2,local_18,local_18);
      i_msgID = uVar1;
    }
    else {
      iVar2 = fopMsgM_IsExecuting();
      if (iVar2 == 0) {
        uVar1 = fopMsgM_messageTypeSelect((fopAc_ac_c *)0x0,param_2,local_18,local_18);
        i_msgID = uVar1;
      }
      else {
        pmVar3 = fopMsgM_SearchByID(i_msgID);
        if (pmVar3 == (msg_class *)0x0) {
          i_msgID = 0xffffffff;
          uVar1 = i_msgID;
        }
        else {
          pmVar3->field_0xec = local_18[0];
          pmVar3->field_0xf0 = local_18[0];
          iVar2 = fopMsgM_SearchByName(499);
          if ((iVar2 != 0) || (iVar2 = fopMsgM_SearchByName(500), uVar1 = i_msgID, iVar2 != 0)) {
            fopMsgM_Delete(pmVar3);
            i_msgID = 0xffffffff;
            uVar1 = i_msgID;
          }
        }
      }
    }
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


/* __stdcall fopMsgM_messageSet(unsigned long) */

uint fopMsgM_messageSet(ulong param_1)

{
  uint uVar1;
  int iVar2;
  msg_class *pmVar3;
  ulong local_18;
  cXyz local_14;
  
  if ((((d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 == 0) ||
       (d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 == 7)) ||
      (d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 == 8)) ||
     (d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 == 9)) {
    local_14.z = 0_0;
    local_14.y = 0_0;
    local_14.x = 0_0;
    local_18 = param_1;
    if (i_msgID == 0xffffffff) {
      uVar1 = fopMsgM_messageTypeSelect((fopAc_ac_c *)0x0,&local_14,&local_18,&local_18);
      i_msgID = uVar1;
    }
    else {
      iVar2 = fopMsgM_IsExecuting();
      if (iVar2 == 0) {
        uVar1 = fopMsgM_messageTypeSelect((fopAc_ac_c *)0x0,&local_14,&local_18,&local_18);
        i_msgID = uVar1;
      }
      else {
        pmVar3 = fopMsgM_SearchByID(i_msgID);
        if (pmVar3 == (msg_class *)0x0) {
          i_msgID = 0xffffffff;
          uVar1 = i_msgID;
        }
        else {
          pmVar3->field_0xec = local_18;
          pmVar3->field_0xf0 = local_18;
          iVar2 = fopMsgM_SearchByName(499);
          if ((iVar2 != 0) || (iVar2 = fopMsgM_SearchByName(500), uVar1 = i_msgID, iVar2 != 0)) {
            fopMsgM_Delete(pmVar3);
            i_msgID = 0xffffffff;
            uVar1 = i_msgID;
          }
        }
      }
    }
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


/* __stdcall fopMsgM_scopeMessageSet(unsigned long) */

uint fopMsgM_scopeMessageSet(ulong param_1)

{
  int iVar1;
  msg_class *pmVar2;
  
  iVar1 = fopMsgM_IsExecuting(i_msgID);
  if (iVar1 != 0) {
    pmVar2 = fopMsgM_SearchByID(i_msgID);
    if (pmVar2 == (msg_class *)0x0) {
      i_msgID = 0xffffffff;
    }
    else {
      if (((d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8 & 0x200000U) != 0) &&
         (d_com_inf_game::g_dComIfG_gameInfo.mbCamOverrideFarPlane == 0xb)) {
        d_com_inf_game::g_dComIfG_gameInfo.mbCamOverrideFarPlane = 2;
      }
      pmVar2->field_0xec = param_1;
      pmVar2->field_0xf0 = param_1;
    }
  }
  return i_msgID;
}


/* __stdcall fopMsgM_tactMessageSet(void) */

uint fopMsgM_tactMessageSet(void)

{
  int iVar1;
  msg_class *pmVar2;
  uint uVar3;
  ulong local_18;
  cXyz local_14;
  
  if ((((d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 == 0) ||
       (d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 == 7)) ||
      (d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 == 8)) ||
     (d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 == 9)) {
    local_18 = 0x5ac;
    local_14.z = 0_0;
    local_14.y = 0_0;
    local_14.x = 0_0;
    if (i_msgID == 0xffffffff) {
      i_msgID = fopMsgM_messageTypeSelect((fopAc_ac_c *)0x0,&local_14,&local_18,&local_18);
      fopMsgM_tactMsgFlagOn();
      uVar3 = i_msgID;
    }
    else {
      iVar1 = fopMsgM_IsExecuting();
      if (iVar1 == 0) {
        i_msgID = fopMsgM_messageTypeSelect((fopAc_ac_c *)0x0,&local_14,&local_18,&local_18);
        fopMsgM_tactMsgFlagOn();
        uVar3 = i_msgID;
      }
      else {
        pmVar2 = fopMsgM_SearchByID(i_msgID);
        if (pmVar2 == (msg_class *)0x0) {
          i_msgID = 0xffffffff;
          uVar3 = i_msgID;
        }
        else {
          pmVar2->field_0xec = local_18;
          pmVar2->field_0xf0 = local_18;
          iVar1 = fopMsgM_SearchByName(499);
          if ((iVar1 != 0) || (iVar1 = fopMsgM_SearchByName(500), uVar3 = i_msgID, iVar1 != 0)) {
            fopMsgM_Delete(pmVar2);
            i_msgID = 0xffffffff;
            uVar3 = i_msgID;
          }
        }
      }
    }
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __stdcall fopMsgM_messageGet(char *,
                                unsigned long) */

byte * fopMsgM_messageGet(byte *param_1,ulong param_2)

{
  uint *puVar1;
  byte bVar2;
  mesg_header *pmVar3;
  ulong uVar4;
  byte *pbVar5;
  size_t sVar6;
  byte *pbVar7;
  undefined1 *local_38;
  undefined4 local_34;
  undefined2 local_30;
  undefined2 local_2e;
  byte local_2c [24];
  
  local_38 = &::fopMsgM_itemMsgGet_c::__vt;
  local_34 = 0;
  local_30 = 0;
  local_2e = 0;
  pmVar3 = (mesg_header *)
           ::fopMsgM_itemMsgGet_c::getMesgHeader((fopMsgM_itemMsgGet_c *)&local_38,param_2);
  if (pmVar3 == (mesg_header *)0x0) {
    uVar4 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar4,"f_op_msg_mng.cpp",0x6bd,"head_p");
    m_Do_printf::OSPanic("f_op_msg_mng.cpp",0x6bd,&DAT_8033c3e5);
  }
  pbVar5 = (byte *)::fopMsgM_itemMsgGet_c::getMessage((fopMsgM_itemMsgGet_c *)&local_38,pmVar3);
  pbVar7 = param_1;
  while (bVar2 = *pbVar5, bVar2 != 0) {
    if (bVar2 == 0x1a) {
      puVar1 = (uint *)(pbVar5 + 1);
      if ((*puVar1 & 0xffffff) == 0x1e) {
        *pbVar7 = 0x1a;
        pbVar7 = pbVar7 + 1;
      }
      else {
        if ((*puVar1 & 0xffffff) == 0) {
          MSL_C.PPCEABI.bare.H::strcpy
                    ((char *)local_2c,
                     &d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mInfo.mPlayerName);
          if ((d_com_inf_game::g_dComIfG_gameInfo.mGameLanguage == 1) &&
             ((((param_2 == 0x33b || (param_2 == 0xc8b)) || (param_2 == 0x1d21)) ||
              (((param_2 == 0x31d7 || (param_2 == 0x37dd)) || (param_2 == 0x37de)))))) {
            sVar6 = MSL_C.PPCEABI.bare.H::strlen((char *)local_2c);
            bVar2 = local_2c[sVar6 - 1];
            if (((bVar2 == 0x73) || (bVar2 == 0x53)) ||
               ((bVar2 == 0x7a || (((bVar2 == 0x5a || (bVar2 == 0x78)) || (bVar2 == 0x58)))))) {
              MSL_C.PPCEABI.bare.H::strcat((char *)local_2c,"\'");
            }
            else {
              MSL_C.PPCEABI.bare.H::strcat((char *)local_2c,"s");
            }
          }
          for (pbVar5 = local_2c; *pbVar5 != 0; pbVar5 = pbVar5 + 1) {
            *pbVar7 = *pbVar5;
            pbVar7 = pbVar7 + 1;
          }
        }
      }
      pbVar5 = (byte *)((int)puVar1 + (char)*(byte *)puVar1 + -1);
    }
    else {
      if ((bVar2 >> 4 == 8) || (bVar2 >> 4 == 9)) {
        *pbVar7 = *pbVar5;
        pbVar7[1] = pbVar5[1];
        pbVar7 = pbVar7 + 2;
        pbVar5 = pbVar5 + 2;
      }
      else {
        *pbVar7 = *pbVar5;
        pbVar7 = pbVar7 + 1;
        pbVar5 = pbVar5 + 1;
      }
    }
  }
  *pbVar7 = 0;
  return param_1;
}

}

/* __thiscall fopMsgM_itemMsgGet_c::~fopMsgM_itemMsgGet_c(void) */

void __thiscall fopMsgM_itemMsgGet_c::_fopMsgM_itemMsgGet_c(fopMsgM_itemMsgGet_c *this)

{
  short in_r4;
  
  if ((this != (fopMsgM_itemMsgGet_c *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


namespace f_op_msg_mng {

/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __stdcall fopMsgM_passwordGet(char *,
                                 unsigned long) */

byte * fopMsgM_passwordGet(byte *param_1,ulong param_2)

{
  uint *puVar1;
  byte bVar2;
  mesg_header *pmVar3;
  ulong uVar4;
  byte *pbVar5;
  size_t sVar6;
  byte *pbVar7;
  undefined1 *local_38;
  undefined4 local_34;
  undefined2 local_30;
  undefined2 local_2e;
  byte local_2c [24];
  
  local_38 = &::fopMsgM_itemMsgGet_c::__vt;
  local_34 = 0;
  local_30 = 0;
  local_2e = 0;
  pmVar3 = (mesg_header *)
           ::fopMsgM_itemMsgGet_c::getMesgHeader((fopMsgM_itemMsgGet_c *)&local_38,param_2);
  if (pmVar3 == (mesg_header *)0x0) {
    uVar4 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar4,"f_op_msg_mng.cpp",0x735,"head_p");
    m_Do_printf::OSPanic("f_op_msg_mng.cpp",0x735,&DAT_8033c3e5);
  }
  pbVar5 = (byte *)::fopMsgM_itemMsgGet_c::getMessage((fopMsgM_itemMsgGet_c *)&local_38,pmVar3);
  pbVar7 = param_1;
  while (bVar2 = *pbVar5, bVar2 != 0) {
    if (bVar2 == 0x1a) {
      puVar1 = (uint *)(pbVar5 + 1);
      if ((*puVar1 & 0xffffff) == 0) {
        MSL_C.PPCEABI.bare.H::strcpy
                  ((char *)local_2c,
                   &d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mInfo.mPlayerName);
        if ((d_com_inf_game::g_dComIfG_gameInfo.mGameLanguage == 1) &&
           ((((param_2 == 0x33b || (param_2 == 0xc8b)) || (param_2 == 0x1d21)) ||
            (((param_2 == 0x31d7 || (param_2 == 0x37dd)) || (param_2 == 0x37de)))))) {
          sVar6 = MSL_C.PPCEABI.bare.H::strlen((char *)local_2c);
          bVar2 = local_2c[sVar6 - 1];
          if (((bVar2 == 0x73) || (bVar2 == 0x53)) ||
             ((bVar2 == 0x7a || (((bVar2 == 0x5a || (bVar2 == 0x78)) || (bVar2 == 0x58)))))) {
            MSL_C.PPCEABI.bare.H::strcat((char *)local_2c,"\'");
          }
          else {
            MSL_C.PPCEABI.bare.H::strcat((char *)local_2c,"s");
          }
        }
        for (pbVar5 = local_2c; *pbVar5 != 0; pbVar5 = pbVar5 + 1) {
          *pbVar7 = *pbVar5;
          pbVar7 = pbVar7 + 1;
        }
      }
      pbVar5 = (byte *)((int)puVar1 + (char)*(byte *)puVar1 + -1);
    }
    else {
      if ((bVar2 >> 4 == 8) || (bVar2 >> 4 == 9)) {
        *pbVar7 = *pbVar5;
        pbVar7[1] = pbVar5[1];
        pbVar7 = pbVar7 + 2;
        pbVar5 = pbVar5 + 2;
      }
      else {
        *pbVar7 = *pbVar5;
        pbVar7 = pbVar7 + 1;
        pbVar5 = pbVar5 + 1;
      }
    }
  }
  *pbVar7 = 0;
  return param_1;
}


/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* WARNING: Removing unreachable block (ram,0x8002c540) */
/* WARNING: Removing unreachable block (ram,0x8002c548) */
/* WARNING: Could not reconcile some variable overlaps */
/* __stdcall fopMsgM_selectMessageGet(J2DPane *,
                                      J2DPane *,
                                      char *,
                                      char *,
                                      char *,
                                      char *,
                                      unsigned long) */

void fopMsgM_selectMessageGet
               (int param_1,J2DTextBox *param_2,J2DTextBox *param_3,char *param_4,char *param_5,
               char *param_6,char *param_7,ulong param_8)

{
  int iVar1;
  char cVar2;
  float fVar3;
  short sVar4;
  short sVar5;
  bool bVar6;
  float fVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  mesg_header *pmVar11;
  ulong uVar12;
  short sVar13;
  undefined4 *puVar14;
  undefined4 *puVar15;
  short sVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  undefined4 uVar21;
  undefined8 in_f30;
  double dVar22;
  undefined8 in_f31;
  double dVar23;
  undefined1 *local_398;
  undefined4 local_394;
  undefined2 local_390;
  undefined2 local_38e;
  undefined4 local_38c;
  undefined2 local_388;
  undefined2 local_386;
  undefined2 local_384;
  undefined2 local_382;
  undefined local_380;
  undefined local_37f;
  undefined local_37e;
  undefined local_37d;
  undefined local_37c;
  undefined local_37b;
  undefined local_37a;
  undefined local_379;
  undefined local_378;
  undefined local_377;
  undefined local_376;
  undefined local_375;
  undefined4 local_374;
  undefined2 local_370;
  undefined2 local_36e;
  undefined2 local_36c;
  undefined2 local_36a;
  undefined local_368;
  undefined local_367;
  undefined local_366;
  undefined local_365;
  undefined local_364;
  undefined local_363;
  undefined local_362;
  undefined local_361;
  undefined local_360;
  undefined local_35f;
  undefined local_35e;
  undefined local_35d;
  short local_35c;
  short sStack858;
  short local_358;
  short local_356;
  short local_354 [4];
  undefined local_34c;
  undefined auStack840 [8];
  JUTResFont *local_340;
  undefined4 *local_33c;
  float local_328;
  undefined4 local_30c;
  char *local_308;
  char *local_304;
  char *local_300;
  char *local_2fc;
  char *local_2e8;
  char *local_2e4;
  char *local_2e0;
  char *local_2dc;
  int local_22c;
  int local_228;
  int local_224;
  int local_220;
  int local_21c;
  undefined4 local_218;
  int local_204;
  int local_1fc;
  undefined4 local_1ec;
  undefined4 local_1e8;
  undefined4 local_1e0 [15];
  int local_1a4 [55];
  char acStack199 [24];
  undefined local_af;
  undefined local_ac;
  longlong local_a8;
  longlong local_a0;
  longlong local_98;
  longlong local_90;
  longlong local_88;
  longlong local_80;
  longlong local_78;
  undefined4 local_70;
  uint uStack108;
  longlong local_68;
  longlong local_60;
  double local_58;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar21 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  ::fopMsgM_msgDataProc_c::fopMsgM_msgDataProc_c((fopMsgM_msgDataProc_c *)auStack840);
  local_398 = &::fopMsgM_itemMsgGet_c::__vt;
  local_394 = 0;
  local_390 = 0;
  local_38e = 0;
  MSL_C.PPCEABI.bare.H::strcpy(param_4,"\x1bCC[000000FF]\x1bGM[0]");
  MSL_C.PPCEABI.bare.H::strcpy(param_5,"");
  MSL_C.PPCEABI.bare.H::strcpy(param_6,"");
  MSL_C.PPCEABI.bare.H::strcpy(param_7,"");
  dVar23 = (double)param_3->mFontWidth;
  dVar22 = (double)param_2->mFontWidth;
  pmVar11 = (mesg_header *)
            ::fopMsgM_itemMsgGet_c::getMesgHeader((fopMsgM_itemMsgGet_c *)&local_398,param_8);
  if (pmVar11 == (mesg_header *)0x0) {
    uVar12 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar12,"f_op_msg_mng.cpp",0x79b,"head_p");
    m_Do_printf::OSPanic("f_op_msg_mng.cpp",0x79b,&DAT_8033c3e5);
  }
  local_30c = ::fopMsgM_itemMsgGet_c::getMessage((fopMsgM_itemMsgGet_c *)&local_398,pmVar11);
  ::fopMsgM_itemMsgGet_c::getMesgEntry((fopMsgM_itemMsgGet_c *)&local_38c,(mesg_header *)&local_398)
  ;
  local_374 = local_38c;
  local_370 = local_388;
  local_36e = local_386;
  local_36c = local_384;
  local_36a = local_382;
  local_368 = local_380;
  local_367 = local_37f;
  local_366 = local_37e;
  local_365 = local_37d;
  local_364 = local_37c;
  local_363 = local_37b;
  local_362 = local_37a;
  local_361 = local_379;
  local_360 = local_378;
  local_35f = local_377;
  local_35e = local_376;
  local_35d = local_375;
  ::fopMsgM_msgDataProc_c::dataInit((fopMsgM_msgDataProc_c *)auStack840);
  auStack840._4_4_ = param_2->mpFont;
  local_340 = param_3->mpFont;
  local_22c = (int)param_2->field_0xe0;
  local_a8 = (longlong)local_22c;
  local_224 = (int)param_3->field_0xe0;
  local_a0 = (longlong)local_224;
  local_228 = (int)param_2->mFontLeading;
  local_98 = (longlong)local_228;
  local_33c = &local_374;
  local_204 = (int)dVar22;
  local_90 = (longlong)local_204;
  local_1fc = (int)dVar23;
  local_88 = (longlong)local_1fc;
  local_220 = (int)((param_2->parent).mPosBR.x - (param_2->parent).mPosTL.x);
  local_80 = (longlong)local_220;
  local_1e8 = 2;
  local_1ec = 0;
  local_af = 1;
  local_ac = 0;
  local_308 = param_4;
  local_304 = param_5;
  local_300 = param_6;
  local_2fc = param_7;
  local_2e8 = param_4;
  local_2e4 = param_5;
  local_2e0 = param_6;
  local_2dc = param_7;
  local_21c = local_220;
  local_78 = local_80;
  ::fopMsgM_msgDataProc_c::stringLength((fopMsgM_msgDataProc_c *)auStack840);
  ::fopMsgM_msgDataProc_c::stringShift((fopMsgM_msgDataProc_c *)auStack840);
  ::fopMsgM_msgDataProc_c::iconIdxRefresh((fopMsgM_msgDataProc_c *)auStack840);
  fVar7 = 0_0;
  local_218 = 0;
  uStack108 = 2U - (int)local_218._2_2_ ^ 0x80000000;
  local_70 = 0x43300000;
  fVar3 = (float)((double)CONCAT44(0x43300000,uStack108) - _4895) * param_2->mFontLeading * 0_5;
  param_3->field_0xd8 = 0_0;
  param_3->field_0xdc = fVar3;
  param_2->field_0xd8 = fVar7;
  param_2->field_0xdc = fVar3;
  ::fopMsgM_msgDataProc_c::stringSet((fopMsgM_msgDataProc_c *)auStack840);
  J2DTextBox::setString(param_2,param_4,(___)pmVar11);
  J2DTextBox::setString(param_3,param_5,(___)pmVar11);
  iVar20 = (int)(param_2->mFontLeading * 0_5);
  local_68 = (longlong)iVar20;
  iVar19 = (int)(param_2->parent).mPosTL.x;
  local_60 = (longlong)iVar19;
  iVar1 = (int)(param_2->parent).mPosTL.y;
  local_58 = (double)(longlong)iVar1;
  bVar6 = false;
  iVar17 = 0;
  iVar18 = 0;
  sVar16 = (short)iVar19;
  sVar13 = (short)iVar1;
  iVar19 = 0xf;
  do {
    cVar2 = acStack199[iVar17];
    if (cVar2 != -1) {
      sVar4 = (short)iVar20;
      sVar5 = (short)(2U - (int)local_218._2_2_);
      if (cVar2 == '\x14') {
        if (bVar6) {
          local_354[0] = sVar16 + (short)*(undefined4 *)((int)local_1e0 + iVar18);
          sStack858 = local_354[0];
          local_354[2] = sVar13 + sVar4 * (sVar5 + (short)(*(int *)((int)local_1a4 + iVar18) << 1));
          local_356 = local_354[2];
        }
        else {
          local_35c = sVar16 + (short)*(undefined4 *)((int)local_1e0 + iVar18);
          local_358 = sVar13 + sVar4 * (sVar5 + (short)(*(int *)((int)local_1a4 + iVar18) << 1));
          bVar6 = true;
        }
      }
      else {
        if (cVar2 == '\x15') {
          local_34c = bVar6;
          if (bVar6) {
            local_354[0] = sVar16 + (short)*(undefined4 *)((int)local_1e0 + iVar18);
            sStack858 = local_354[0];
            local_354[2] = sVar13 + sVar4 * (sVar5 + (short)(*(int *)((int)local_1a4 + iVar18) << 1)
                                            );
            local_356 = local_354[2];
          }
          else {
            local_35c = sVar16 + (short)*(undefined4 *)((int)local_1e0 + iVar18);
            local_358 = sVar13 + sVar4 * (sVar5 + (short)(*(int *)((int)local_1a4 + iVar18) << 1));
            bVar6 = true;
          }
        }
      }
    }
    iVar17 = iVar17 + 1;
    iVar18 = iVar18 + 4;
    iVar19 = iVar19 + -1;
  } while (iVar19 != 0);
  local_58 = (double)CONCAT44(0x43300000,(int)sVar16 ^ 0x80000000);
  iVar20 = (int)((float)(local_58 - _4895) + local_328);
  local_60 = (longlong)iVar20;
  local_354[1] = (short)iVar20;
  local_354[3] = local_354[2];
  iVar20 = 2;
  puVar8 = (undefined4 *)&local_360;
  puVar9 = (undefined4 *)(param_1 + -4);
  do {
    puVar15 = puVar9;
    puVar14 = puVar8;
    uVar10 = puVar14[2];
    puVar15[1] = puVar14[1];
    puVar15[2] = uVar10;
    iVar20 = iVar20 + -1;
    puVar8 = puVar14 + 2;
    puVar9 = puVar15 + 2;
  } while (iVar20 != 0);
  *(undefined2 *)(puVar15 + 3) = *(undefined2 *)(puVar14 + 3);
  if ((undefined *)register0x00000004 != (undefined *)0x398) {
    local_398 = &::fopMsgM_itemMsgGet_c::__vt;
  }
  ::fopMsgM_msgDataProc_c::_fopMsgM_msgDataProc_c((fopMsgM_msgDataProc_c *)auStack840);
  __psq_l0(auStack8,uVar21);
  __psq_l1(auStack8,uVar21);
  __psq_l0(auStack24,uVar21);
  __psq_l1(auStack24,uVar21);
  return;
}


/* __stdcall fopMsgM_demoMsgFlagOn(void) */

void fopMsgM_demoMsgFlagOn(void)

{
  demoFlag = 1;
  return;
}


/* __stdcall fopMsgM_demoMsgFlagOff(void) */

void fopMsgM_demoMsgFlagOff(void)

{
  demoFlag = 0;
  return;
}


/* __stdcall fopMsgM_demoMsgFlagCheck(void) */

undefined fopMsgM_demoMsgFlagCheck(void)

{
  return demoFlag;
}


/* __stdcall fopMsgM_tactMsgFlagOn(void) */

void fopMsgM_tactMsgFlagOn(void)

{
  tactFlag = 1;
  return;
}


/* __stdcall fopMsgM_tactMsgFlagOff(void) */

void fopMsgM_tactMsgFlagOff(void)

{
  tactFlag = 0;
  return;
}


/* __stdcall fopMsgM_tactMsgFlagCheck(void) */

undefined fopMsgM_tactMsgFlagCheck(void)

{
  return tactFlag;
}


/* __stdcall fopMsgM_nextMsgFlagOff(void) */

void fopMsgM_nextMsgFlagOff(void)

{
  nextMsg = 0;
  return;
}


/* __stdcall fopMsgM_nextMsgFlagCheck(void) */

undefined fopMsgM_nextMsgFlagCheck(void)

{
  return nextMsg;
}


/* __stdcall fopMsgM_getScopeMode(void) */

undefined4 fopMsgM_getScopeMode(void)

{
  if ((((d_com_inf_game::g_dComIfG_gameInfo.field_0x5cc8 & 0x200000U) != 0) &&
      (d_com_inf_game::g_dComIfG_gameInfo.mbCamOverrideFarPlane == 0xb)) &&
     (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mMode == 0)) {
    d_com_inf_game::g_dComIfG_gameInfo.mbCamOverrideFarPlane = 0xd;
    return 1;
  }
  if (d_com_inf_game::g_dComIfG_gameInfo.mbCamOverrideFarPlane == 0x11) {
    d_com_inf_game::g_dComIfG_gameInfo.field_0x5bca = 0xd;
    return 1;
  }
  return 0;
}


/* __stdcall fopMsgM_forceSendOn(void) */

undefined4 fopMsgM_forceSendOn(void)

{
  if (d_com_inf_game::g_dComIfG_gameInfo.mbCamOverrideFarPlane == 10) {
    pushButton = 1;
    return 1;
  }
  return 0;
}


/* __stdcall fopMsgM_forceSendOff(void) */

void fopMsgM_forceSendOff(void)

{
  pushButton = 0;
  return;
}


/* __stdcall fopMsgM_checkForceSend(void) */

undefined fopMsgM_checkForceSend(void)

{
  return pushButton;
}


/* __stdcall fopMsgM_messageSendOn(void) */

void fopMsgM_messageSendOn(void)

{
  pushButton2 = 1;
  return;
}


/* __stdcall fopMsgM_messageSendOff(void) */

void fopMsgM_messageSendOff(void)

{
  pushButton2 = 0;
  return;
}


/* __stdcall fopMsgM_checkMessageSend(void) */

undefined fopMsgM_checkMessageSend(void)

{
  return pushButton2;
}


/* __stdcall fopMsgM_releaseScopeMode(void) */

undefined4 fopMsgM_releaseScopeMode(void)

{
  if (d_com_inf_game::g_dComIfG_gameInfo.mbCamOverrideFarPlane == 0xd) {
    d_com_inf_game::g_dComIfG_gameInfo.mbCamOverrideFarPlane = 0xb;
    return 1;
  }
  return 0;
}


/* __stdcall fopMsgM_outFontTex(int) */

undefined * fopMsgM_outFontTex(int param_1)

{
  return (&fopMsgM_buttonTex)[param_1];
}


/* __stdcall fopMsgM_outFontColorWhite(int) */

undefined4 fopMsgM_outFontColorWhite(int param_1)

{
  return *(undefined4 *)(&fopMsgM_buttonW + param_1 * 4);
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __stdcall fopMsgM_outFontSet(J2DPicture *,
                                J2DPicture *,
                                short *,
                                unsigned long,
                                unsigned char) */

void fopMsgM_outFontSet
               (J2DPicture *param_1,J2DPicture *param_2,undefined2 *param_3,undefined4 param_4,
               byte param_5)

{
  uint uVar1;
  float fVar2;
  undefined4 uVar3;
  u8 uStack102;
  u8 uStack101;
  u8 local_44;
  u8 uStack67;
  u8 local_34;
  u8 uStack51;
  
  if (param_5 == 0x17) {
    param_5 = 0x14;
  }
  else {
    if (param_5 == 0x18) {
      param_5 = 0x15;
    }
    else {
      if (param_5 == 0x19) {
        param_5 = 0x16;
      }
      else {
        if (param_5 == 0x1a) {
          param_5 = 0x17;
        }
      }
    }
  }
  (param_1->parent).mbDraw = 1;
  (param_2->parent).mbDraw = 1;
  uVar1 = (uint)param_5;
  fopMsgM_blendDraw(param_1,(&fopMsgM_buttonTex)[uVar1]);
  fopMsgM_blendDraw(param_2,(&fopMsgM_buttonTex)[uVar1]);
  if ((((byte)(param_5 - 10) < 4) || (param_5 == 0x15)) || (param_5 == 0x17)) {
    local_34 = (u8)((uint3)((uint3)(ushort)((uint)param_4 >> 0x10) << 8) >> 0x10);
    (param_1->mColorBase).r = local_34;
    uStack51 = (u8)((uint)param_4 >> 0x10);
    (param_1->mColorBase).g = uStack51;
    (param_1->mColorBase).b = (u8)((uint)param_4 >> 8);
    (param_1->mColorBase).a = 0xff;
    (param_1->mBgColor).r = 0;
    (param_1->mBgColor).g = 0;
    (param_1->mBgColor).b = 0;
    (param_1->mBgColor).a = 0;
  }
  else {
    uVar3 = *(undefined4 *)(&fopMsgM_buttonW + uVar1 * 4);
    uStack102 = (u8)((uint)uVar3 >> 8);
    uStack101 = (u8)uVar3;
    local_44 = (u8)((uint)uVar3 >> 0x18);
    (param_1->mColorBase).r = local_44;
    uStack67 = (u8)((uint)uVar3 >> 0x10);
    (param_1->mColorBase).g = uStack67;
    (param_1->mColorBase).b = uStack102;
    (param_1->mColorBase).a = uStack101;
    (param_1->mBgColor).r = 0;
    (param_1->mBgColor).g = 0;
    (param_1->mBgColor).b = 0;
    (param_1->mBgColor).a = 0;
  }
  (param_2->mColorBase).r = 0;
  (param_2->mColorBase).g = 0;
  (param_2->mColorBase).b = 0;
  (param_2->mColorBase).a = 0xff;
  (param_2->mBgColor).r = 0;
  (param_2->mBgColor).g = 0;
  (param_2->mBgColor).b = 0;
  (param_2->mBgColor).a = 0;
  param_1->mBlendKonstColorF[0] = 0_0;
  fVar2 = 1_0;
  param_1->mBlendKonstColorF[1] = 1_0;
  param_1->mBlendKonstColorF[2] = fVar2;
  param_1->mBlendKonstColorF[3] = fVar2;
  ::J2DPicture::setBlendKonstColor(param_1);
  param_1->mBlendKonstAlphaF[0] = 0_0;
  fVar2 = 1_0;
  param_1->mBlendKonstAlphaF[1] = 1_0;
  param_1->mBlendKonstAlphaF[2] = fVar2;
  param_1->mBlendKonstAlphaF[3] = fVar2;
  ::J2DPicture::setBlendKonstAlpha(param_1);
  param_2->mBlendKonstColorF[0] = 0_0;
  fVar2 = 1_0;
  param_2->mBlendKonstColorF[1] = 1_0;
  param_2->mBlendKonstColorF[2] = fVar2;
  param_2->mBlendKonstColorF[3] = fVar2;
  ::J2DPicture::setBlendKonstColor(param_2);
  param_2->mBlendKonstAlphaF[0] = 0_0;
  fVar2 = 1_0;
  param_2->mBlendKonstAlphaF[1] = 1_0;
  param_2->mBlendKonstAlphaF[2] = fVar2;
  param_2->mBlendKonstAlphaF[3] = fVar2;
  ::J2DPicture::setBlendKonstAlpha(param_2);
  *param_3 = 0;
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __stdcall fopMsgM_outFontSet(J2DPicture *,
                                short *,
                                unsigned long,
                                unsigned char) */

void fopMsgM_outFontSet
               (J2DPicture *param_1,undefined2 *param_2,undefined4 param_3,byte param_4)

{
  float fVar1;
  undefined4 uVar2;
  u8 uStack70;
  u8 uStack69;
  u8 local_34;
  u8 uStack51;
  u8 local_24;
  u8 uStack35;
  
  if (param_4 == 0x17) {
    param_4 = 0x14;
  }
  else {
    if (param_4 == 0x18) {
      param_4 = 0x15;
    }
    else {
      if (param_4 == 0x19) {
        param_4 = 0x16;
      }
      else {
        if (param_4 == 0x1a) {
          param_4 = 0x17;
        }
      }
    }
  }
  (param_1->parent).mbDraw = 1;
  fopMsgM_blendDraw(param_1,(&fopMsgM_buttonTex)[param_4]);
  if ((((byte)(param_4 - 10) < 4) || (param_4 == 0x15)) || (param_4 == 0x17)) {
    local_24 = (u8)((uint3)((uint3)(ushort)((uint)param_3 >> 0x10) << 8) >> 0x10);
    (param_1->mColorBase).r = local_24;
    uStack35 = (u8)((uint)param_3 >> 0x10);
    (param_1->mColorBase).g = uStack35;
    (param_1->mColorBase).b = (u8)((uint)param_3 >> 8);
    (param_1->mColorBase).a = 0xff;
    (param_1->mBgColor).r = 0;
    (param_1->mBgColor).g = 0;
    (param_1->mBgColor).b = 0;
    (param_1->mBgColor).a = 0;
  }
  else {
    uVar2 = *(undefined4 *)(&fopMsgM_buttonW + (uint)param_4 * 4);
    uStack70 = (u8)((uint)uVar2 >> 8);
    uStack69 = (u8)uVar2;
    local_34 = (u8)((uint)uVar2 >> 0x18);
    (param_1->mColorBase).r = local_34;
    uStack51 = (u8)((uint)uVar2 >> 0x10);
    (param_1->mColorBase).g = uStack51;
    (param_1->mColorBase).b = uStack70;
    (param_1->mColorBase).a = uStack69;
    (param_1->mBgColor).r = 0;
    (param_1->mBgColor).g = 0;
    (param_1->mBgColor).b = 0;
    (param_1->mBgColor).a = 0;
  }
  param_1->mBlendKonstColorF[0] = 0_0;
  fVar1 = 1_0;
  param_1->mBlendKonstColorF[1] = 1_0;
  param_1->mBlendKonstColorF[2] = fVar1;
  param_1->mBlendKonstColorF[3] = fVar1;
  ::J2DPicture::setBlendKonstColor(param_1);
  param_1->mBlendKonstAlphaF[0] = 0_0;
  fVar1 = 1_0;
  param_1->mBlendKonstAlphaF[1] = 1_0;
  param_1->mBlendKonstAlphaF[2] = fVar1;
  param_1->mBlendKonstAlphaF[3] = fVar1;
  ::J2DPicture::setBlendKonstAlpha(param_1);
  *param_2 = 0;
  return;
}


/* WARNING: Removing unreachable block (ram,0x8002ce88) */
/* WARNING: Removing unreachable block (ram,0x8002ce90) */
/* __stdcall fopMsgM_outFontStickAnimePiece(J2DPicture *,
                                            J2DPicture *,
                                            short,
                                            short) */

void fopMsgM_outFontStickAnimePiece
               (J2DPicture *param_1,J2DPicture *param_2,short param_3,short param_4)

{
  float fVar1;
  short sVar3;
  short sVar4;
  short sVar5;
  int iVar2;
  undefined4 uVar6;
  double dVar7;
  undefined8 in_f30;
  double dVar8;
  undefined8 in_f31;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  fVar1 = 1_0;
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  sVar3 = (ushort)DAT_803e6bcc + (ushort)DAT_803e6bcb * 2 + (ushort)DAT_803e6bcd;
  sVar4 = (ushort)DAT_803e6bcc + sVar3 * param_4;
  sVar5 = (ushort)DAT_803e6bcd + (ushort)DAT_803e6bcb + sVar4;
  iVar2 = (int)param_3;
  if (iVar2 < sVar4) {
    param_1->mBlendKonstColorF[0] = 0_0;
    fVar1 = 1_0;
    param_1->mBlendKonstColorF[1] = 1_0;
    param_1->mBlendKonstColorF[2] = fVar1;
    param_1->mBlendKonstColorF[3] = fVar1;
    ::J2DPicture::setBlendKonstColor(param_1);
    param_1->mBlendKonstAlphaF[0] = 0_0;
    fVar1 = 1_0;
    param_1->mBlendKonstAlphaF[1] = 1_0;
    param_1->mBlendKonstAlphaF[2] = fVar1;
    param_1->mBlendKonstAlphaF[3] = fVar1;
    ::J2DPicture::setBlendKonstAlpha(param_1);
    param_2->mBlendKonstColorF[0] = 0_0;
    fVar1 = 1_0;
    param_2->mBlendKonstColorF[1] = 1_0;
    param_2->mBlendKonstColorF[2] = fVar1;
    param_2->mBlendKonstColorF[3] = fVar1;
    ::J2DPicture::setBlendKonstColor(param_2);
    param_2->mBlendKonstAlphaF[0] = 0_0;
    fVar1 = 1_0;
    param_2->mBlendKonstAlphaF[1] = 1_0;
    param_2->mBlendKonstAlphaF[2] = fVar1;
    param_2->mBlendKonstAlphaF[3] = fVar1;
    ::J2DPicture::setBlendKonstAlpha(param_2);
  }
  else {
    if (iVar2 < (short)((ushort)DAT_803e6bcb + sVar4)) {
      dVar7 = (double)fopMsgM_valueIncrease(sVar3,iVar2 - sVar4,0);
      param_1->mBlendKonstColorF[0] = (float)dVar7;
      fVar1 = 1_0;
      dVar8 = (double)(float)((double)1_0 - dVar7);
      param_1->mBlendKonstColorF[1] = (float)((double)1_0 - dVar7);
      param_1->mBlendKonstColorF[2] = fVar1;
      param_1->mBlendKonstColorF[3] = fVar1;
      ::J2DPicture::setBlendKonstColor(param_1);
      param_1->mBlendKonstAlphaF[0] = (float)dVar7;
      param_1->mBlendKonstAlphaF[1] = (float)dVar8;
      fVar1 = 1_0;
      param_1->mBlendKonstAlphaF[2] = 1_0;
      param_1->mBlendKonstAlphaF[3] = fVar1;
      ::J2DPicture::setBlendKonstAlpha(param_1);
      param_2->mBlendKonstColorF[0] = (float)dVar7;
      param_2->mBlendKonstColorF[1] = (float)dVar8;
      fVar1 = 1_0;
      param_2->mBlendKonstColorF[2] = 1_0;
      param_2->mBlendKonstColorF[3] = fVar1;
      ::J2DPicture::setBlendKonstColor(param_2);
      param_2->mBlendKonstAlphaF[0] = (float)dVar7;
      param_2->mBlendKonstAlphaF[1] = (float)dVar8;
      fVar1 = 1_0;
      param_2->mBlendKonstAlphaF[2] = 1_0;
      param_2->mBlendKonstAlphaF[3] = fVar1;
      ::J2DPicture::setBlendKonstAlpha(param_2);
    }
    else {
      if (iVar2 < sVar5) {
        param_1->mBlendKonstColorF[0] = 1_0;
        param_1->mBlendKonstColorF[1] = 0_0;
        param_1->mBlendKonstColorF[2] = fVar1;
        param_1->mBlendKonstColorF[3] = fVar1;
        ::J2DPicture::setBlendKonstColor(param_1);
        fVar1 = 1_0;
        param_1->mBlendKonstAlphaF[0] = 1_0;
        param_1->mBlendKonstAlphaF[1] = 0_0;
        param_1->mBlendKonstAlphaF[2] = fVar1;
        param_1->mBlendKonstAlphaF[3] = fVar1;
        ::J2DPicture::setBlendKonstAlpha(param_1);
        fVar1 = 1_0;
        param_2->mBlendKonstColorF[0] = 1_0;
        param_2->mBlendKonstColorF[1] = 0_0;
        param_2->mBlendKonstColorF[2] = fVar1;
        param_2->mBlendKonstColorF[3] = fVar1;
        ::J2DPicture::setBlendKonstColor(param_2);
        fVar1 = 1_0;
        param_2->mBlendKonstAlphaF[0] = 1_0;
        param_2->mBlendKonstAlphaF[1] = 0_0;
        param_2->mBlendKonstAlphaF[2] = fVar1;
        param_2->mBlendKonstAlphaF[3] = fVar1;
        ::J2DPicture::setBlendKonstAlpha(param_2);
      }
      else {
        if (iVar2 < (short)((ushort)DAT_803e6bcb + sVar5)) {
          dVar7 = (double)fopMsgM_valueIncrease(sVar3,iVar2 - sVar5,0);
          fVar1 = 1_0;
          dVar8 = (double)(float)((double)1_0 - dVar7);
          param_1->mBlendKonstColorF[0] = (float)((double)1_0 - dVar7);
          param_1->mBlendKonstColorF[1] = (float)dVar7;
          param_1->mBlendKonstColorF[2] = fVar1;
          param_1->mBlendKonstColorF[3] = fVar1;
          ::J2DPicture::setBlendKonstColor(param_1);
          param_1->mBlendKonstAlphaF[0] = (float)dVar8;
          param_1->mBlendKonstAlphaF[1] = (float)dVar7;
          fVar1 = 1_0;
          param_1->mBlendKonstAlphaF[2] = 1_0;
          param_1->mBlendKonstAlphaF[3] = fVar1;
          ::J2DPicture::setBlendKonstAlpha(param_1);
          param_2->mBlendKonstColorF[0] = (float)dVar8;
          param_2->mBlendKonstColorF[1] = (float)dVar7;
          fVar1 = 1_0;
          param_2->mBlendKonstColorF[2] = 1_0;
          param_2->mBlendKonstColorF[3] = fVar1;
          ::J2DPicture::setBlendKonstColor(param_2);
          param_2->mBlendKonstAlphaF[0] = (float)dVar8;
          param_2->mBlendKonstAlphaF[1] = (float)dVar7;
          fVar1 = 1_0;
          param_2->mBlendKonstAlphaF[2] = 1_0;
          param_2->mBlendKonstAlphaF[3] = fVar1;
          ::J2DPicture::setBlendKonstAlpha(param_2);
        }
      }
    }
  }
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  __psq_l0(auStack24,uVar6);
  __psq_l1(auStack24,uVar6);
  return;
}


/* WARNING: Removing unreachable block (ram,0x8002d064) */
/* WARNING: Removing unreachable block (ram,0x8002d06c) */
/* __stdcall fopMsgM_outFontStickAnimePiece(J2DPicture *,
                                            short,
                                            short) */

void fopMsgM_outFontStickAnimePiece(J2DPicture *param_1,short param_2,short param_3)

{
  float fVar1;
  short sVar3;
  short sVar4;
  short sVar5;
  int iVar2;
  undefined4 uVar6;
  double dVar7;
  undefined8 in_f30;
  double dVar8;
  undefined8 in_f31;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  fVar1 = 1_0;
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  sVar3 = (ushort)DAT_803e6bcc + (ushort)DAT_803e6bcb * 2 + (ushort)DAT_803e6bcd;
  sVar4 = (ushort)DAT_803e6bcc + sVar3 * param_3;
  sVar5 = (ushort)DAT_803e6bcd + (ushort)DAT_803e6bcb + sVar4;
  iVar2 = (int)param_2;
  if (iVar2 < sVar4) {
    param_1->mBlendKonstColorF[0] = 0_0;
    fVar1 = 1_0;
    param_1->mBlendKonstColorF[1] = 1_0;
    param_1->mBlendKonstColorF[2] = fVar1;
    param_1->mBlendKonstColorF[3] = fVar1;
    ::J2DPicture::setBlendKonstColor(param_1);
    param_1->mBlendKonstAlphaF[0] = 0_0;
    fVar1 = 1_0;
    param_1->mBlendKonstAlphaF[1] = 1_0;
    param_1->mBlendKonstAlphaF[2] = fVar1;
    param_1->mBlendKonstAlphaF[3] = fVar1;
    ::J2DPicture::setBlendKonstAlpha(param_1);
  }
  else {
    if (iVar2 < (short)((ushort)DAT_803e6bcb + sVar4)) {
      dVar7 = (double)fopMsgM_valueIncrease(sVar3,iVar2 - sVar4,0);
      param_1->mBlendKonstColorF[0] = (float)dVar7;
      fVar1 = 1_0;
      dVar8 = (double)(float)((double)1_0 - dVar7);
      param_1->mBlendKonstColorF[1] = (float)((double)1_0 - dVar7);
      param_1->mBlendKonstColorF[2] = fVar1;
      param_1->mBlendKonstColorF[3] = fVar1;
      ::J2DPicture::setBlendKonstColor(param_1);
      param_1->mBlendKonstAlphaF[0] = (float)dVar7;
      param_1->mBlendKonstAlphaF[1] = (float)dVar8;
      fVar1 = 1_0;
      param_1->mBlendKonstAlphaF[2] = 1_0;
      param_1->mBlendKonstAlphaF[3] = fVar1;
      ::J2DPicture::setBlendKonstAlpha(param_1);
    }
    else {
      if (iVar2 < sVar5) {
        param_1->mBlendKonstColorF[0] = 1_0;
        param_1->mBlendKonstColorF[1] = 0_0;
        param_1->mBlendKonstColorF[2] = fVar1;
        param_1->mBlendKonstColorF[3] = fVar1;
        ::J2DPicture::setBlendKonstColor(param_1);
        fVar1 = 1_0;
        param_1->mBlendKonstAlphaF[0] = 1_0;
        param_1->mBlendKonstAlphaF[1] = 0_0;
        param_1->mBlendKonstAlphaF[2] = fVar1;
        param_1->mBlendKonstAlphaF[3] = fVar1;
        ::J2DPicture::setBlendKonstAlpha(param_1);
      }
      else {
        if (iVar2 < (short)((ushort)DAT_803e6bcb + sVar5)) {
          dVar7 = (double)fopMsgM_valueIncrease(sVar3,iVar2 - sVar5,0);
          fVar1 = 1_0;
          dVar8 = (double)(float)((double)1_0 - dVar7);
          param_1->mBlendKonstColorF[0] = (float)((double)1_0 - dVar7);
          param_1->mBlendKonstColorF[1] = (float)dVar7;
          param_1->mBlendKonstColorF[2] = fVar1;
          param_1->mBlendKonstColorF[3] = fVar1;
          ::J2DPicture::setBlendKonstColor(param_1);
          param_1->mBlendKonstAlphaF[0] = (float)dVar8;
          param_1->mBlendKonstAlphaF[1] = (float)dVar7;
          fVar1 = 1_0;
          param_1->mBlendKonstAlphaF[2] = 1_0;
          param_1->mBlendKonstAlphaF[3] = fVar1;
          ::J2DPicture::setBlendKonstAlpha(param_1);
        }
      }
    }
  }
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  __psq_l0(auStack24,uVar6);
  __psq_l1(auStack24,uVar6);
  return;
}

}

/* __thiscall J2DPane::calcMtx(void) */

void __thiscall J2DPane::calcMtx(J2DPane *this)

{
  if ((this->mParentLink).mpList != (JSUPtrList *)0x0) {
    (*(code *)this->vtbl->makeMatrix)((double)(this->mPosTL).x,(double)(this->mPosTL).y);
  }
  return;
}


/* __thiscall J2DPane::resize(float,
                              float) */

void __thiscall J2DPane::resize(J2DPane *this,float param_1,float param_2)

{
  (this->mPosBR).x = (this->mPosTL).x + param_1;
  (this->mPosBR).y = (this->mPosTL).y + param_2;
  return;
}


namespace f_op_msg_mng {

/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __stdcall fopMsgM_outFontStickAnime(J2DPicture *,
                                       J2DPicture *,
                                       int *,
                                       int *,
                                       int,
                                       short *) */

void fopMsgM_outFontStickAnime
               (int *param_1,int *param_2,int *param_3,int *param_4,int param_5,short *param_6)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = (int)(short)((ushort)DAT_803e6bcc + (ushort)DAT_803e6bcb * 2 + (ushort)DAT_803e6bcd);
  iVar4 = (int)*param_6;
  if (iVar4 < iVar5) {
    fopMsgM_outFontStickAnimePiece();
  }
  else {
    if (iVar4 < iVar5 << 1) {
      fopMsgM_outFontStickAnimePiece();
      *param_3 = *param_3 + param_5;
    }
    else {
      if (iVar4 < iVar5 * 3) {
        fopMsgM_outFontStickAnimePiece();
        *param_3 = *param_3 + param_5;
        *param_4 = *param_4 + param_5;
      }
      else {
        if (iVar4 < iVar5 << 2) {
          fopMsgM_outFontStickAnimePiece();
          *param_4 = *param_4 + param_5;
        }
      }
    }
  }
  fVar2 = 0_0;
  uVar3 = (int)*param_6 / iVar5;
  if ((int)*param_6 == uVar3 * iVar5) {
    fVar1 = _5408 * (float)((double)CONCAT44(0x43300000,uVar3 ^ 0x80000000) - _4895);
    param_1[0x27] = (int)0_0;
    param_1[0x28] = (int)fVar2;
    *(undefined *)(param_1 + 0x2a) = 0x7a;
    param_1[0x29] = (int)fVar1;
    (**(code **)(*param_1 + 0x20))(param_1);
    fVar1 = 0_0;
    fVar2 = _5408 * (float)((double)CONCAT44(0x43300000,(int)*param_6 / iVar5 ^ 0x80000000) - _4895)
    ;
    param_2[0x27] = (int)0_0;
    param_2[0x28] = (int)fVar1;
    *(undefined *)(param_2 + 0x2a) = 0x7a;
    param_2[0x29] = (int)fVar2;
    (**(code **)(*param_2 + 0x20))(param_2);
  }
  *param_6 = *param_6 + 1;
  if (iVar5 << 2 <= (int)*param_6) {
    *param_6 = 0;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __stdcall fopMsgM_outFontStickAnime(J2DPicture *,
                                       int *,
                                       int *,
                                       int *,
                                       int *,
                                       short *) */

void fopMsgM_outFontStickAnime
               (int *param_1,int *param_2,int *param_3,int *param_4,int *param_5,short *param_6)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = (int)(short)((ushort)DAT_803e6bcc + (ushort)DAT_803e6bcb * 2 + (ushort)DAT_803e6bcd);
  iVar4 = (int)*param_6;
  if (iVar4 < iVar5) {
    fopMsgM_outFontStickAnimePiece(param_1,iVar4,0);
  }
  else {
    if (iVar4 < iVar5 << 1) {
      fopMsgM_outFontStickAnimePiece(param_1,iVar4,1);
      iVar4 = *param_4;
      *param_4 = *param_5;
      *param_5 = iVar4;
      *param_2 = *param_2 + *param_5;
    }
    else {
      if (iVar4 < iVar5 * 3) {
        fopMsgM_outFontStickAnimePiece(param_1,iVar4,2);
        *param_2 = *param_2 + *param_4;
        *param_3 = *param_3 + *param_5;
      }
      else {
        if (iVar4 < iVar5 << 2) {
          fopMsgM_outFontStickAnimePiece(param_1,iVar4,3);
          iVar4 = *param_4;
          *param_4 = *param_5;
          *param_5 = iVar4;
          *param_3 = *param_3 + *param_4;
        }
      }
    }
  }
  fVar2 = 0_0;
  uVar3 = (int)*param_6 / iVar5;
  if ((int)*param_6 == uVar3 * iVar5) {
    fVar1 = _5408 * (float)((double)CONCAT44(0x43300000,uVar3 ^ 0x80000000) - _4895);
    param_1[0x27] = (int)0_0;
    param_1[0x28] = (int)fVar2;
    *(undefined *)(param_1 + 0x2a) = 0x7a;
    param_1[0x29] = (int)fVar1;
    (**(code **)(*param_1 + 0x20))(param_1);
  }
  *param_6 = *param_6 + 1;
  if (iVar5 << 2 <= (int)*param_6) {
    *param_6 = 0;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Removing unreachable block (ram,0x8002d600) */
/* __stdcall fopMsgM_outFontStickAnime2(J2DPicture *,
                                        J2DPicture *,
                                        int *,
                                        int *,
                                        int,
                                        short *,
                                        unsigned char) */

void fopMsgM_outFontStickAnime2
               (int *param_1,int *param_2,int *param_3,int *param_4,int param_5,short *param_6,
               char param_7)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 in_f31;
  double dVar5;
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  iVar3 = (int)(short)((ushort)DAT_803e6bcc + (ushort)DAT_803e6bcb * 2 + (ushort)DAT_803e6bcd);
  piVar2 = param_1;
  if (param_7 == '\0') {
    if (*param_6 < iVar3) {
      fopMsgM_outFontStickAnimePiece();
      *param_3 = *param_3 + param_5;
      piVar2 = (int *)&DAT_00000001;
    }
    else {
      if ((int)*param_6 < iVar3 << 1) {
        fopMsgM_outFontStickAnimePiece();
        *param_4 = *param_4 + param_5;
        piVar2 = (int *)&DAT_00000003;
      }
    }
  }
  else {
    if (*param_6 < iVar3) {
      fopMsgM_outFontStickAnimePiece();
      piVar2 = (int *)0x0;
    }
    else {
      if ((int)*param_6 < iVar3 << 1) {
        fopMsgM_outFontStickAnimePiece();
        *param_3 = *param_3 + param_5;
        *param_4 = *param_4 + param_5;
        piVar2 = (int *)&DAT_00000002;
      }
    }
  }
  fVar1 = 0_0;
  param_1[0x27] = (int)0_0;
  param_1[0x28] = (int)fVar1;
  *(undefined *)(param_1 + 0x2a) = 0x7a;
  fVar1 = _5408 * (float)((double)CONCAT44(0x43300000,(uint)piVar2 ^ 0x80000000) - _4895);
  dVar5 = (double)fVar1;
  param_1[0x29] = (int)fVar1;
  (**(code **)(*param_1 + 0x20))(param_1);
  fVar1 = 0_0;
  param_2[0x27] = (int)0_0;
  param_2[0x28] = (int)fVar1;
  *(undefined *)(param_2 + 0x2a) = 0x7a;
  param_2[0x29] = (int)(float)dVar5;
  (**(code **)(*param_2 + 0x20))(param_2);
  *param_6 = *param_6 + 1;
  if (iVar3 << 1 <= (int)*param_6) {
    *param_6 = 0;
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __stdcall fopMsgM_outFontStickAnime2(J2DPicture *,
                                        int *,
                                        int *,
                                        int *,
                                        int *,
                                        short *,
                                        unsigned char) */

void fopMsgM_outFontStickAnime2
               (int *param_1,int *param_2,int *param_3,int *param_4,int *param_5,short *param_6,
               char param_7)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = (int)(short)((ushort)DAT_803e6bcc + (ushort)DAT_803e6bcb * 2 + (ushort)DAT_803e6bcd);
  piVar2 = param_1;
  if (param_7 == '\0') {
    iVar3 = (int)*param_6;
    if (iVar3 < iVar4) {
      fopMsgM_outFontStickAnimePiece(param_1,iVar3,0);
      iVar3 = *param_4;
      *param_4 = *param_5;
      *param_5 = iVar3;
      *param_2 = *param_2 + *param_5;
      piVar2 = (int *)&DAT_00000001;
    }
    else {
      if (iVar3 < iVar4 << 1) {
        fopMsgM_outFontStickAnimePiece(param_1,iVar3,1);
        iVar3 = *param_4;
        *param_4 = *param_5;
        *param_5 = iVar3;
        *param_3 = *param_3 + *param_4;
        piVar2 = (int *)&DAT_00000003;
      }
    }
  }
  else {
    iVar3 = (int)*param_6;
    if (iVar3 < iVar4) {
      fopMsgM_outFontStickAnimePiece(param_1,iVar3,0);
      piVar2 = (int *)0x0;
    }
    else {
      if (iVar3 < iVar4 << 1) {
        fopMsgM_outFontStickAnimePiece(param_1,iVar3,1);
        *param_2 = *param_2 + *param_4;
        *param_3 = *param_3 + *param_5;
        piVar2 = (int *)&DAT_00000002;
      }
    }
  }
  fVar1 = 0_0;
  param_1[0x27] = (int)0_0;
  param_1[0x28] = (int)fVar1;
  *(undefined *)(param_1 + 0x2a) = 0x7a;
  param_1[0x29] =
       (int)(_5408 * (float)((double)CONCAT44(0x43300000,(uint)piVar2 ^ 0x80000000) - _4895));
  (**(code **)(*param_1 + 0x20))(param_1);
  *param_6 = *param_6 + 1;
  if (iVar4 << 1 <= (int)*param_6) {
    *param_6 = 0;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* WARNING: Removing unreachable block (ram,0x8002d93c) */
/* __stdcall fopMsgM_outFontStickAnime(J2DPicture *,
                                       J2DPicture *,
                                       int *,
                                       int *,
                                       int,
                                       short *,
                                       unsigned char) */

void fopMsgM_outFontStickAnime
               (int *param_1,int *param_2,int *param_3,int *param_4,int param_5,short *param_6,
               byte param_7)

{
  float fVar1;
  short sVar2;
  undefined4 uVar3;
  undefined8 in_f31;
  double dVar4;
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  sVar2 = (ushort)DAT_803e6bcc + (ushort)DAT_803e6bcb * 2 + (ushort)DAT_803e6bcd;
  if (*param_6 < sVar2) {
    fopMsgM_outFontStickAnimePiece();
    if (param_7 == 2) {
      *param_3 = *param_3 + param_5;
      *param_4 = *param_4 + param_5;
    }
    else {
      if (param_7 < 2) {
        if (param_7 != 0) {
          *param_3 = *param_3 + param_5;
        }
      }
      else {
        if (param_7 < 4) {
          *param_4 = *param_4 + param_5;
        }
      }
    }
  }
  fVar1 = 0_0;
  param_1[0x27] = (int)0_0;
  param_1[0x28] = (int)fVar1;
  *(undefined *)(param_1 + 0x2a) = 0x7a;
  fVar1 = _5408 * (float)((double)CONCAT44(0x43300000,(uint)param_7) - _5509);
  dVar4 = (double)fVar1;
  param_1[0x29] = (int)fVar1;
  (**(code **)(*param_1 + 0x20))(param_1);
  fVar1 = 0_0;
  param_2[0x27] = (int)0_0;
  param_2[0x28] = (int)fVar1;
  *(undefined *)(param_2 + 0x2a) = 0x7a;
  param_2[0x29] = (int)(float)dVar4;
  (**(code **)(*param_2 + 0x20))(param_2);
  *param_6 = *param_6 + 1;
  if (sVar2 <= *param_6) {
    *param_6 = 0;
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __stdcall fopMsgM_outFontStickAnime(J2DPicture *,
                                       int *,
                                       int *,
                                       int *,
                                       int *,
                                       short *,
                                       unsigned char) */

void fopMsgM_outFontStickAnime
               (int *param_1,int *param_2,int *param_3,int *param_4,int *param_5,short *param_6,
               byte param_7)

{
  float fVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = (int)(short)((ushort)DAT_803e6bcc + (ushort)DAT_803e6bcb * 2 + (ushort)DAT_803e6bcd);
  if (*param_6 < iVar3) {
    fopMsgM_outFontStickAnimePiece(param_1,(int)*param_6,0);
    if (param_7 == 2) {
      *param_2 = *param_2 + *param_4;
      *param_3 = *param_3 + *param_5;
    }
    else {
      if (param_7 < 2) {
        if (param_7 != 0) {
          iVar2 = *param_4;
          *param_4 = *param_5;
          *param_5 = (int)(short)iVar2;
          *param_2 = *param_2 + *param_5;
        }
      }
      else {
        if (param_7 < 4) {
          iVar2 = *param_4;
          *param_4 = *param_5;
          *param_5 = (int)(short)iVar2;
          *param_3 = *param_3 + *param_4;
        }
      }
    }
  }
  fVar1 = 0_0;
  param_1[0x27] = (int)0_0;
  param_1[0x28] = (int)fVar1;
  *(undefined *)(param_1 + 0x2a) = 0x7a;
  param_1[0x29] = (int)(_5408 * (float)((double)CONCAT44(0x43300000,(uint)param_7) - _5509));
  (**(code **)(*param_1 + 0x20))(param_1);
  *param_6 = *param_6 + 1;
  if (iVar3 <= *param_6) {
    *param_6 = 0;
  }
  return;
}


/* __stdcall fopMsgM_outFontArrow(J2DPicture *,
                                  J2DPicture *,
                                  int *,
                                  int *,
                                  int,
                                  unsigned char) */

void fopMsgM_outFontArrow
               (int *param_1,int *param_2,int *param_3,int *param_4,int param_5,char param_6)

{
  float fVar1;
  
  if (param_6 == '\n') {
    *param_3 = *param_3 + param_5;
    fVar1 = 0_0;
    param_1[0x27] = (int)0_0;
    param_1[0x28] = (int)fVar1;
    *(undefined *)(param_1 + 0x2a) = 0x7a;
    param_1[0x29] = (int)_5545;
    (**(code **)(*param_1 + 0x20))();
    fVar1 = 0_0;
    param_2[0x27] = (int)0_0;
    param_2[0x28] = (int)fVar1;
    *(undefined *)(param_2 + 0x2a) = 0x7a;
    param_2[0x29] = (int)_5545;
    (**(code **)(*param_2 + 0x20))(param_2);
  }
  else {
    if (param_6 == '\v') {
      *param_4 = *param_4 + param_5;
      fVar1 = 0_0;
      param_1[0x27] = (int)0_0;
      param_1[0x28] = (int)fVar1;
      *(undefined *)(param_1 + 0x2a) = 0x7a;
      param_1[0x29] = (int)_5546;
      (**(code **)(*param_1 + 0x20))();
      fVar1 = 0_0;
      param_2[0x27] = (int)0_0;
      param_2[0x28] = (int)fVar1;
      *(undefined *)(param_2 + 0x2a) = 0x7a;
      param_2[0x29] = (int)_5546;
      (**(code **)(*param_2 + 0x20))(param_2);
    }
    else {
      if (param_6 == '\f') {
        *param_3 = *param_3 + param_5;
        *param_4 = *param_4 + param_5;
        fVar1 = 0_0;
        param_1[0x27] = (int)0_0;
        param_1[0x28] = (int)fVar1;
        *(undefined *)(param_1 + 0x2a) = 0x7a;
        param_1[0x29] = (int)_5547;
        (**(code **)(*param_1 + 0x20))();
        fVar1 = 0_0;
        param_2[0x27] = (int)0_0;
        param_2[0x28] = (int)fVar1;
        *(undefined *)(param_2 + 0x2a) = 0x7a;
        param_2[0x29] = (int)_5547;
        (**(code **)(*param_2 + 0x20))(param_2);
      }
    }
  }
  return;
}


/* __stdcall fopMsgM_outFontArrow(J2DPicture *,
                                  int *,
                                  int *,
                                  int *,
                                  int *,
                                  unsigned char) */

void fopMsgM_outFontArrow
               (int *param_1,int *param_2,int *param_3,int *param_4,int *param_5,char param_6)

{
  float fVar1;
  int iVar2;
  
  if (param_6 == '\n') {
    iVar2 = *param_4;
    *param_4 = *param_5;
    *param_5 = iVar2;
    *param_2 = *param_2 + *param_5;
    fVar1 = 0_0;
    param_1[0x27] = (int)0_0;
    param_1[0x28] = (int)fVar1;
    *(undefined *)(param_1 + 0x2a) = 0x7a;
    param_1[0x29] = (int)_5545;
    (**(code **)(*param_1 + 0x20))();
  }
  else {
    if (param_6 == '\v') {
      iVar2 = *param_4;
      *param_4 = *param_5;
      *param_5 = iVar2;
      *param_3 = *param_3 + *param_4;
      fVar1 = 0_0;
      param_1[0x27] = (int)0_0;
      param_1[0x28] = (int)fVar1;
      *(undefined *)(param_1 + 0x2a) = 0x7a;
      param_1[0x29] = (int)_5546;
      (**(code **)(*param_1 + 0x20))();
    }
    else {
      if (param_6 == '\f') {
        *param_2 = *param_2 + *param_4;
        *param_3 = *param_3 + *param_5;
        fVar1 = 0_0;
        param_1[0x27] = (int)0_0;
        param_1[0x28] = (int)fVar1;
        *(undefined *)(param_1 + 0x2a) = 0x7a;
        param_1[0x29] = (int)_5547;
        (**(code **)(*param_1 + 0x20))();
      }
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __stdcall fopMsgM_outFontDraw(J2DPicture *,
                                 J2DPicture *,
                                 int,
                                 int,
                                 int,
                                 short *,
                                 unsigned char,
                                 unsigned char) */

void fopMsgM_outFontDraw
               (J2DPicture *param_1,J2DPicture *param_2,uint param_3,int param_4,uint param_5,
               undefined4 param_6,byte param_7,uint param_8)

{
  uint local_68;
  int local_64;
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
  
  local_68 = param_3;
  local_64 = param_4;
  switch(param_8 & 0xff) {
  case 9:
    fopMsgM_outFontStickAnime(param_1,param_2,&local_68,&local_64);
    break;
  case 10:
  case 0xb:
  case 0xc:
  case 0xd:
    fopMsgM_outFontArrow(param_1,param_2,&local_68,&local_64,param_5,param_8);
    break;
  case 0xe:
    fopMsgM_outFontStickAnime(param_1,param_2,&local_68,&local_64,param_5,param_6,1);
    break;
  case 0xf:
    fopMsgM_outFontStickAnime(param_1,param_2,&local_68,&local_64,param_5,param_6,3);
    break;
  case 0x10:
    fopMsgM_outFontStickAnime(param_1,param_2,&local_68,&local_64,param_5,param_6,0);
    break;
  case 0x11:
    fopMsgM_outFontStickAnime(param_1,param_2,&local_68,&local_64,param_5,param_6,2);
    break;
  case 0x12:
    fopMsgM_outFontStickAnime2(param_1,param_2,&local_68,&local_64,param_5,param_6,0);
    break;
  case 0x13:
    fopMsgM_outFontStickAnime2(param_1,param_2,&local_68,&local_64,param_5,param_6,1);
  }
  uStack92 = local_68 + 2 ^ 0x80000000;
  local_60 = 0x43300000;
  uStack84 = local_64 + DAT_803e6bae + 1U ^ 0x80000000;
  local_58 = 0x43300000;
  uStack76 = param_5 ^ 0x80000000;
  local_50 = 0x43300000;
  local_48 = 0x43300000;
  uStack68 = uStack76;
  ::J2DPicture::draw(param_2,(float)((double)CONCAT44(0x43300000,uStack92) - _4895),
                     (float)((double)CONCAT44(0x43300000,uStack84) - _4895),
                     (float)((double)CONCAT44(0x43300000,uStack76) - _4895),
                     (float)((double)CONCAT44(0x43300000,uStack76) - _4895),false,false,false);
  uStack60 = local_68 ^ 0x80000000;
  local_40 = 0x43300000;
  uStack52 = (local_64 + DAT_803e6bae) - 1U ^ 0x80000000;
  local_38 = 0x43300000;
  uStack44 = param_5 ^ 0x80000000;
  local_30 = 0x43300000;
  local_28 = 0x43300000;
  uStack36 = uStack44;
  ::J2DPicture::draw(param_1,(float)((double)CONCAT44(0x43300000,uStack60) - _4895),
                     (float)((double)CONCAT44(0x43300000,uStack52) - _4895),
                     (float)((double)CONCAT44(0x43300000,uStack44) - _4895),
                     (float)((double)CONCAT44(0x43300000,uStack44) - _4895),false,false,false);
  (param_1->parent).mAlpha = param_7;
  (param_2->parent).mAlpha = param_7;
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __stdcall fopMsgM_outFontDraw2(J2DPicture *,
                                  J2DPicture *,
                                  int,
                                  int,
                                  int,
                                  int,
                                  short *,
                                  unsigned char,
                                  unsigned char) */

void fopMsgM_outFontDraw2
               (int *param_1,int *param_2,uint param_3,uint param_4,uint param_5,uint param_6,
               undefined4 param_7,undefined param_8,undefined param_9)

{
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
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
  
  local_4c = 0;
  local_50 = 0;
  local_58 = param_5;
  local_54 = param_6;
  switch(param_9) {
  case 9:
    fopMsgM_outFontStickAnime(param_1,&local_4c,&local_50,&local_58,&local_54,param_7);
    break;
  case 10:
  case 0xb:
  case 0xc:
  case 0xd:
    fopMsgM_outFontArrow(param_1,&local_4c,&local_50,&local_58,&local_54);
    break;
  case 0xe:
    fopMsgM_outFontStickAnime(param_1,&local_4c,&local_50,&local_58,&local_54,param_7,1);
    break;
  case 0xf:
    fopMsgM_outFontStickAnime(param_1,&local_4c,&local_50,&local_58,&local_54,param_7,3);
    break;
  case 0x10:
    fopMsgM_outFontStickAnime(param_1,&local_4c,&local_50,&local_58,&local_54,param_7,0);
    break;
  case 0x11:
    fopMsgM_outFontStickAnime(param_1,&local_4c,&local_50,&local_58,&local_54,param_7,2);
    break;
  case 0x12:
    fopMsgM_outFontStickAnime2(param_1,&local_4c,&local_50,&local_58,&local_54,param_7,0);
    break;
  case 0x13:
    fopMsgM_outFontStickAnime2(param_1,&local_4c,&local_50,&local_58,&local_54,param_7,1);
  }
  uStack68 = param_3 ^ 0x80000000;
  local_48 = 0x43300000;
  uStack60 = param_4 ^ 0x80000000;
  local_40 = 0x43300000;
  (**(code **)(*param_2 + 0x10))
            ((double)(float)((double)CONCAT44(0x43300000,uStack68) - _4895),
             (double)(float)((double)CONCAT44(0x43300000,uStack60) - _4895),param_2);
  uStack52 = local_4c ^ 0x80000000;
  local_38 = 0x43300000;
  uStack44 = local_50 ^ 0x80000000;
  local_30 = 0x43300000;
  (**(code **)(*param_1 + 0x10))
            ((double)(float)((double)CONCAT44(0x43300000,uStack52) - _4895),
             (double)(float)((double)CONCAT44(0x43300000,uStack44) - _4895),param_1);
  uStack36 = local_58 ^ 0x80000000;
  local_28 = 0x43300000;
  uStack28 = local_54 ^ 0x80000000;
  local_20 = 0x43300000;
  (**(code **)(*param_1 + 0x18))
            ((double)(float)((double)CONCAT44(0x43300000,uStack36) - _4895),
             (double)(float)((double)CONCAT44(0x43300000,uStack28) - _4895),param_1);
  *(undefined *)(param_1 + 0x2b) = param_8;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall fopMsgM_Create(short,
                            int *(void *),
                            void *) */

void fopMsgM_Create(short param_1,undefined *param_2,void *param_3)

{
  layer_class *plVar1;
  
  plVar1 = f_pc_layer::fpcLy_CurrentLayer();
  f_pc_stdcreate_req::fpcSCtRq_Request(plVar1,param_1,param_2,(void *)0x0,param_3);
  return;
}

}

/* __thiscall fopMsgM_msgGet_c::getMesgHeader(unsigned long) */

void __thiscall fopMsgM_msgGet_c::getMesgHeader(fopMsgM_msgGet_c *this,ulong msg_id)

{
  bool is_text_hylian;
  
  *(short *)(this + 8) = (short)(msg_id >> 0x10);
  *(short *)(this + 10) = (short)msg_id;
  is_text_hylian = f_op_msg_mng::fopMsgM_hyrule_language_check(msg_id);
  if (is_text_hylian == false) {
    JKRArchive::getGlbResource
              (0x524f4f54,"zel_00.bmg",d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpEnglishTextArchive
              );
  }
  else {
    JKRArchive::getGlbResource
              (0x524f4f54,"zel_01.bmg",d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpHyruleTextArchive)
    ;
  }
  return;
}


/* __thiscall fopMsgM_msgGet_c::getMesgInfo(mesg_header *) */

mesg_header * __thiscall fopMsgM_msgGet_c::getMesgInfo(fopMsgM_msgGet_c *this,mesg_header *param_1)

{
  return param_1 + 0x20;
}


/* __thiscall fopMsgM_msgGet_c::getMesgData(mesg_header *) */

int __thiscall fopMsgM_msgGet_c::getMesgData(fopMsgM_msgGet_c *this,mesg_header *param_1)

{
  int iVar1;
  
  iVar1 = getMesgInfo(this,param_1);
  return iVar1 + *(int *)(iVar1 + 4);
}


/* __thiscall fopMsgM_msgGet_c::getMesgEntry(mesg_header *) */

void __thiscall fopMsgM_msgGet_c::getMesgEntry(fopMsgM_msgGet_c *this,mesg_header *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  mesg_header *in_r5;
  undefined4 *puVar5;
  
  iVar3 = getMesgInfo((fopMsgM_msgGet_c *)param_1,in_r5);
  puVar5 = (undefined4 *)(this + -4);
  puVar4 = (undefined4 *)(iVar3 + *(int *)(param_1 + 4) * 0x18 + 0xc);
  iVar3 = 3;
  do {
    puVar1 = puVar4 + 1;
    puVar4 = puVar4 + 2;
    uVar2 = *puVar4;
    puVar5[1] = *puVar1;
    puVar5 = puVar5 + 2;
    *puVar5 = uVar2;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall fopMsgM_msgGet_c::getMessage(mesg_header *) */

int __thiscall fopMsgM_msgGet_c::getMessage(fopMsgM_msgGet_c *this,mesg_header *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  ushort uVar4;
  
  iVar1 = getMesgInfo(this,param_1);
  iVar2 = getMesgData(this,param_1);
  uVar4 = 0;
  while( true ) {
    if (*(ushort *)(iVar1 + 8) <= uVar4) {
      return 0;
    }
    iVar3 = iVar1 + (uint)uVar4 * 0x18;
    if ((*(int *)(iVar3 + 0x10) != 0) &&
       (*(uint *)(this + 4) = (uint)uVar4, *(short *)(this + 10) == *(short *)(iVar3 + 0x14)))
    break;
    uVar4 = uVar4 + 1;
  }
  iVar1 = iVar1 + *(int *)(this + 4) * 0x18;
  iVar3 = *(int *)(iVar1 + 0x10);
  *(undefined2 *)(this + 0xc) = *(undefined2 *)(iVar1 + 0x14);
  return iVar2 + 8 + iVar3;
}


/* __thiscall fopMsgM_itemMsgGet_c::getMesgHeader(unsigned long) */

void __thiscall fopMsgM_itemMsgGet_c::getMesgHeader(fopMsgM_itemMsgGet_c *this,ulong param_1)

{
  bool bVar1;
  
  *(short *)(this + 8) = (short)param_1;
  bVar1 = f_op_msg_mng::fopMsgM_hyrule_language_check(param_1);
  if (bVar1 == false) {
    JKRArchive::getGlbResource
              (0x524f4f54,"zel_00.bmg",d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpEnglishTextArchive
              );
  }
  else {
    JKRArchive::getGlbResource
              (0x524f4f54,"zel_01.bmg",d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpHyruleTextArchive)
    ;
  }
  return;
}


/* __thiscall fopMsgM_itemMsgGet_c::getMesgInfo(mesg_header *) */

mesg_header * __thiscall
fopMsgM_itemMsgGet_c::getMesgInfo(fopMsgM_itemMsgGet_c *this,mesg_header *param_1)

{
  return param_1 + 0x20;
}


/* __thiscall fopMsgM_itemMsgGet_c::getMesgData(mesg_header *) */

int __thiscall fopMsgM_itemMsgGet_c::getMesgData(fopMsgM_itemMsgGet_c *this,mesg_header *param_1)

{
  int iVar1;
  
  iVar1 = getMesgInfo(this,param_1);
  return iVar1 + *(int *)(iVar1 + 4);
}


/* __thiscall fopMsgM_itemMsgGet_c::getMesgEntry(mesg_header *) */

void __thiscall fopMsgM_itemMsgGet_c::getMesgEntry(fopMsgM_itemMsgGet_c *this,mesg_header *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  mesg_header *in_r5;
  undefined4 *puVar5;
  
  iVar3 = getMesgInfo((fopMsgM_itemMsgGet_c *)param_1,in_r5);
  puVar5 = (undefined4 *)(this + -4);
  puVar4 = (undefined4 *)(iVar3 + *(int *)(param_1 + 4) * 0x18 + 0xc);
  iVar3 = 3;
  do {
    puVar1 = puVar4 + 1;
    puVar4 = puVar4 + 2;
    uVar2 = *puVar4;
    puVar5[1] = *puVar1;
    puVar5 = puVar5 + 2;
    *puVar5 = uVar2;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall fopMsgM_itemMsgGet_c::getMessage(mesg_header *) */

int __thiscall fopMsgM_itemMsgGet_c::getMessage(fopMsgM_itemMsgGet_c *this,mesg_header *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  ushort uVar4;
  
  iVar2 = getMesgInfo(this,param_1);
  iVar3 = getMesgData(this,param_1);
  for (uVar4 = 0; uVar4 < *(ushort *)(iVar2 + 8); uVar4 = uVar4 + 1) {
    iVar1 = iVar2 + (uint)uVar4 * 0x18;
    if ((*(int *)(iVar1 + 0x10) != 0) &&
       (*(uint *)(this + 4) = (uint)uVar4, *(short *)(this + 8) == *(short *)(iVar1 + 0x14))) break;
  }
  iVar2 = iVar2 + *(int *)(this + 4) * 0x18;
  iVar1 = *(int *)(iVar2 + 0x10);
  *(undefined2 *)(this + 10) = *(undefined2 *)(iVar2 + 0x14);
  return iVar3 + 8 + iVar1;
}


/* __thiscall fopMsgM_msgDataProc_c::fopMsgM_msgDataProc_c(void) */

void __thiscall fopMsgM_msgDataProc_c::fopMsgM_msgDataProc_c(fopMsgM_msgDataProc_c *this)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  this->vtbl = (undefined *)&__vt;
  fVar1 = f_op_msg_mng::0_0;
  this->field_0x14 = f_op_msg_mng::0_0;
  this->field_0x18 = fVar1;
  this->field_0x1c = fVar1;
  this->field_0x20 = fVar1;
  this->field_0x24 = fVar1;
  this->field_0x28 = fVar1;
  iVar2 = 0;
  iVar4 = 4;
  do {
    iVar5 = (int)&this->vtbl + iVar2;
    *(undefined4 *)(iVar5 + 0xd8) = 0;
    *(undefined4 *)(iVar5 + 0xf8) = 0;
    *(undefined4 *)(iVar5 + 0x108) = 0;
    *(undefined4 *)(iVar5 + 0xe8) = 0;
    iVar2 = iVar2 + 4;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  this->field_0x21c = 0;
  *(undefined *)&this->field_0xd6 = 0;
  *(undefined *)&this->field_0xd5 = 0;
  *(undefined *)&this->field_0xd4 = 0;
  this->field_0x2c = 0;
  this->field_0x30 = 0;
  this->field_0x34 = 0;
  this->field_0x38 = 0;
  this->field_0x118 = 0;
  this->field_0x11c = 0;
  this->field_0x124 = 0;
  this->field_0x120 = 0;
  this->field_0x128 = 0;
  this->field_0x12c = 0;
  this->field_0x130 = 0;
  this->field_0x134 = 0;
  this->field_0x138 = 0;
  this->field_0x13c = 0;
  this->field_0x140 = 0;
  this->field_0x144 = 0;
  this->field_0x148 = 0;
  this->field_0x14c = 0;
  this->field_0x150 = 0;
  this->field_0x154 = 0;
  this->field_0x158 = 0;
  this->field_0x15c = 1;
  this->field_0x160 = 1;
  this->field_0x164 = 0;
  this->field_0x25c = 0xffffffff;
  *(undefined *)&this->field_0x29d = 0;
  this->field_0x260 = 0;
  fVar1 = f_op_msg_mng::0_0;
  this->field_0x264 = f_op_msg_mng::0_0;
  this->field_0x268 = fVar1;
  this->field_0x26c = fVar1;
  this->field_0x270 = fVar1;
  this->field_0x278 = fVar1;
  this->field_0x274 = fVar1;
  *(undefined *)&this->field_0x293 = 0;
  *(undefined *)&this->field_0x292 = 0;
  *(undefined *)&this->field_0x291 = 0;
  *(undefined *)&this->field_0x290 = 0;
  *(undefined *)&this->field_0x27c = 6;
  this->field_0x27d = 0;
  *(undefined *)&this->field_0x27e = 0;
  *(undefined *)&this->field_0x27f = 0;
  *(undefined *)&this->field_0x280 = 0;
  iVar4 = 0;
  iVar2 = 0;
  iVar5 = 0xf;
  do {
    iVar3 = (int)&this->vtbl + iVar2;
    *(undefined4 *)(iVar3 + 0x168) = 0;
    *(undefined4 *)(iVar3 + 0x1a4) = 0;
    *(undefined4 *)(iVar3 + 0x1e0) = 0;
    *(undefined *)(&this->field_0x281 + iVar4) = 0xff;
    *(undefined4 *)(iVar3 + 0x220) = 0;
    iVar4 = iVar4 + 1;
    iVar2 = iVar2 + 4;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  this->field_0x10 = 0;
  *(undefined *)&this->field_0x299 = 0;
  *(undefined *)&this->field_0x29a = 0;
  *(undefined *)&this->field_0x294 = 0;
  *(undefined *)&this->field_0x29b = 0;
  *(undefined *)&this->field_0x297 = 0;
  *(undefined *)&this->field_0x298 = 0;
  *(undefined *)&this->field_0x29c = 0;
  *(undefined *)&this->field_0x295 = 0;
  *(undefined *)&this->field_0x296 = 0;
  return;
}


/* __thiscall fopMsgM_msgDataProc_c::~fopMsgM_msgDataProc_c(void) */

void __thiscall fopMsgM_msgDataProc_c::_fopMsgM_msgDataProc_c(fopMsgM_msgDataProc_c *this)

{
  short in_r4;
  
  if ((this != (fopMsgM_msgDataProc_c *)0x0) && (this->vtbl = (undefined *)&__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall fopMsgM_msgDataProc_c::dataInit(void) */

void __thiscall fopMsgM_msgDataProc_c::dataInit(fopMsgM_msgDataProc_c *this)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  fVar1 = f_op_msg_mng::0_0;
  this->field_0x14 = f_op_msg_mng::0_0;
  this->field_0x18 = fVar1;
  this->field_0x1c = fVar1;
  this->field_0x20 = fVar1;
  this->field_0x24 = fVar1;
  this->field_0x28 = fVar1;
  iVar2 = 0;
  iVar4 = 4;
  do {
    iVar5 = (int)&this->vtbl + iVar2;
    *(undefined4 *)(iVar5 + 0xd8) = 0;
    *(undefined4 *)(iVar5 + 0xf8) = 0;
    *(undefined4 *)(iVar5 + 0xe8) = 0;
    *(undefined4 *)(iVar5 + 0x108) = 0;
    iVar2 = iVar2 + 4;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  this->field_0x21c = 0;
  *(undefined *)&this->field_0xd6 = 0;
  *(undefined *)&this->field_0xd5 = 0;
  *(undefined *)&this->field_0xd4 = 0;
  this->field_0x2c = 0;
  this->field_0x30 = 0;
  this->field_0x34 = 0;
  this->field_0x38 = 0;
  this->field_0x118 = 0;
  this->field_0x11c = 0;
  this->field_0x124 = 0;
  this->field_0x120 = 0;
  this->field_0x128 = 0;
  this->field_0x12c = 0;
  this->field_0x130 = 0;
  this->field_0x134 = 0;
  this->field_0x138 = 0;
  this->field_0x13c = 0;
  this->field_0x140 = 0;
  this->field_0x144 = 0;
  this->field_0x148 = 0;
  this->field_0x14c = 0;
  this->field_0x150 = 0;
  this->field_0x154 = 0;
  this->field_0x158 = 0;
  this->field_0x15c = 1;
  this->field_0x160 = 1;
  this->field_0x164 = 0;
  *(undefined *)&this->field_0x29d = 0;
  this->field_0x260 = 0;
  fVar1 = f_op_msg_mng::0_0;
  this->field_0x264 = f_op_msg_mng::0_0;
  this->field_0x268 = fVar1;
  this->field_0x26c = fVar1;
  this->field_0x270 = fVar1;
  this->field_0x278 = fVar1;
  this->field_0x274 = fVar1;
  *(undefined *)&this->field_0x293 = 0;
  *(undefined *)&this->field_0x292 = 0;
  *(undefined *)&this->field_0x291 = 0;
  *(undefined *)&this->field_0x290 = 0;
  *(undefined *)&this->field_0x27c = 6;
  this->field_0x27d = 0;
  *(undefined *)&this->field_0x27e = 0;
  *(undefined *)&this->field_0x27f = 0;
  *(undefined *)&this->field_0x280 = 0;
  iVar4 = 0;
  iVar2 = 0;
  iVar5 = 0xf;
  do {
    iVar3 = (int)&this->vtbl + iVar2;
    *(undefined4 *)(iVar3 + 0x168) = 0;
    *(undefined4 *)(iVar3 + 0x1a4) = 0;
    *(undefined4 *)(iVar3 + 0x1e0) = 0;
    *(undefined *)(&this->field_0x281 + iVar4) = 0xff;
    *(undefined4 *)(iVar3 + 0x220) = 0;
    iVar4 = iVar4 + 1;
    iVar2 = iVar2 + 4;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  *(undefined *)&this->field_0x299 = 0;
  *(undefined *)&this->field_0x29a = 0;
  *(undefined *)&this->field_0x294 = 0;
  *(undefined *)&this->field_0x29b = 0;
  *(undefined *)&this->field_0x297 = 0;
  *(undefined *)&this->field_0x298 = 0;
  *(undefined *)&this->field_0x29c = 0;
  *(undefined *)&this->field_0x295 = 0;
  *(undefined *)&this->field_0x296 = 0;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x8002ea38) */
/* __thiscall fopMsgM_msgDataProc_c::charLength(int,
                                                int,
                                                bool) */

double __thiscall
fopMsgM_msgDataProc_c::charLength(fopMsgM_msgDataProc_c *this,int param_1,int param_2,bool param_3)

{
  float fVar1;
  uint uVar2;
  undefined4 uVar3;
  double dVar4;
  undefined8 in_f31;
  double dVar5;
  undefined uStack72;
  byte local_47;
  undefined4 local_40;
  uint uStack60;
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  (**(code **)(**(int **)&this->field_0x4 + 0x2c))(*(int **)&this->field_0x4,param_2,&uStack72);
  uStack60 = local_47 ^ 0x80000000;
  local_40 = 0x43300000;
  dVar5 = (double)(float)((double)CONCAT44(0x43300000,uStack60) - f_op_msg_mng::_4895);
  uVar2 = (**(code **)(**(int **)&this->field_0x4 + 0x30))(f_op_msg_mng::_4895);
  dVar4 = (double)((float)((double)CONCAT44(0x43300000,param_1 ^ 0x80000000) - f_op_msg_mng::_4895)
                  / (float)((double)CONCAT44(0x43300000,uVar2 ^ 0x80000000) - f_op_msg_mng::_4895));
  if (param_3 == false) {
    fVar1 = (float)((double)CONCAT44(0x43300000,this->field_0x11c ^ 0x80000000) -
                   f_op_msg_mng::_4895) + (float)(dVar5 * dVar4);
  }
  else {
    fVar1 = (float)(dVar5 * dVar4);
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return (double)fVar1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall fopMsgM_msgDataProc_c::rubyLength(int,
                                                bool) */

double __thiscall
fopMsgM_msgDataProc_c::rubyLength(fopMsgM_msgDataProc_c *this,int param_1,bool param_2)

{
  float fVar1;
  uint uVar2;
  undefined uStack72;
  byte local_47;
  
  (**(code **)(**(int **)&this->field_0x8 + 0x2c))(*(int **)&this->field_0x8,param_1,&uStack72);
  uVar2 = (**(code **)(**(int **)&this->field_0x8 + 0x30))();
  fVar1 = (float)((double)CONCAT44(0x43300000,this->field_0x14c ^ 0x80000000) - f_op_msg_mng::_4895)
          / (float)((double)CONCAT44(0x43300000,uVar2 ^ 0x80000000) - f_op_msg_mng::_4895);
  if (param_2 == false) {
    fVar1 = (float)((double)CONCAT44(0x43300000,this->field_0x124 ^ 0x80000000) -
                   f_op_msg_mng::_4895) +
            (float)((double)CONCAT44(0x43300000,local_47 ^ 0x80000000) - f_op_msg_mng::_4895) *
            fVar1;
  }
  else {
    fVar1 = (float)((double)CONCAT44(0x43300000,local_47 ^ 0x80000000) - f_op_msg_mng::_4895) *
            fVar1;
  }
  return (double)fVar1;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall fopMsgM_msgDataProc_c::stringLength(void) */

int __thiscall fopMsgM_msgDataProc_c::stringLength(fopMsgM_msgDataProc_c *this)

{
  byte bVar1;
  byte bVar2;
  short sVar3;
  float fVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  int iVar8;
  char cVar12;
  size_t sVar9;
  ulong uVar10;
  char *pcVar11;
  int iVar13;
  uint uVar14;
  int iVar15;
  byte *pbVar16;
  byte *pbVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  double dVar21;
  uint local_98;
  float local_94;
  int local_90;
  int local_8c;
  int local_88 [4];
  byte local_78 [20];
  byte local_64 [19];
  char acStack81 [25];
  undefined4 local_38;
  uint uStack52;
  double local_30;
  double local_28;
  
  local_8c = 0;
  local_90 = 0;
  iVar19 = 0;
  iVar18 = this->field_0x118;
  local_94 = f_op_msg_mng::0_0;
  bVar7 = false;
  bVar6 = false;
  this->field_0x130 = 0;
  local_98 = this->field_0x144;
  this->field_0x148 = this->field_0x144;
  iVar8 = 0;
  iVar20 = 4;
  do {
    *(undefined4 *)((int)local_88 + iVar8) = 0;
    iVar13 = (int)&this->vtbl + iVar8;
    *(undefined4 *)(iVar13 + 0xd8) = 0;
    *(undefined4 *)(iVar13 + 0xe8) = 0;
    *(undefined4 *)(iVar13 + 0x108) = 0;
    iVar8 = iVar8 + 4;
    iVar20 = iVar20 + -1;
    iVar13 = local_8c;
  } while (iVar20 != 0);
  do {
    while( true ) {
      while( true ) {
        local_8c = iVar13;
        iVar8 = iVar18;
        pcVar11 = (char *)(*(int *)&this->field_0x3c + iVar8);
        cVar12 = *pcVar11;
        if (cVar12 == '\0') {
          this->field_0x140 = this->field_0x13c;
          if (bVar6) {
            *(int *)(&this->field_0xe8 + local_8c * 4) = local_88[local_8c];
          }
          else {
            iVar18 = 0;
            iVar8 = 4;
            do {
              *(undefined4 *)(&this->field_0xd8 + iVar18) = *(undefined4 *)((int)local_88 + iVar18);
              iVar18 = iVar18 + 4;
              iVar8 = iVar8 + -1;
            } while (iVar8 != 0);
            if (((*(char *)&this->field_0x295 != '\0') && (this->field_0x130 == 0)) && (bVar7)) {
              this->field_0x130 = 1;
            }
          }
          this->field_0x134 = this->field_0x130;
          return iVar19;
        }
        if (cVar12 != '\x1a') break;
        cVar12 = pcVar11[2];
        if (((cVar12 == -1) && (pcVar11[3] == '\0')) && (pcVar11[4] == '\x01')) {
          uStack52 = *(ushort *)(pcVar11 + 5) ^ 0x80000000;
          local_38 = 0x43300000;
          fVar4 = f_op_msg_mng::_6433 *
                  (float)((double)CONCAT44(0x43300000,*(ushort *)(pcVar11 + 5) ^ 0x80000000) -
                         f_op_msg_mng::_4895);
          if (f_op_msg_mng::1_0 < fVar4) {
            bVar7 = true;
          }
          local_30 = (double)CONCAT44(0x43300000,this->field_0x144 ^ 0x80000000);
          local_98 = (uint)(f_op_msg_mng::0_5 + fVar4 * (float)(local_30 - f_op_msg_mng::_4895));
          local_28 = (double)(longlong)(int)local_98;
        }
        else {
          if (((cVar12 == '\0') && (pcVar11[3] == '\0')) && (pcVar11[4] == '\0')) {
            iVar18 = 0;
            pcVar11 = f_op_msg_mng::dComIfGs_getPlayerName();
            MSL_C.PPCEABI.bare.H::strcpy(acStack81 + 1,pcVar11);
            cVar12 = f_op_msg_mng::dComIfGs_getPalLanguage();
            if ((cVar12 == '\x01') &&
               (((((sVar3 = *(short *)(*(int *)&this->field_0xc + 4), sVar3 == 0x33b ||
                   (sVar3 == 0xc8b)) || (sVar3 == 0x1d21)) ||
                 ((sVar3 == 0x31d7 || (sVar3 == 0x37dd)))) || (sVar3 == 0x37de)))) {
              sVar9 = MSL_C.PPCEABI.bare.H::strlen(acStack81 + 1);
              cVar12 = (acStack81 + 1)[sVar9 - 1];
              if (((cVar12 == 's') || (cVar12 == 'S')) ||
                 ((cVar12 == 'z' || (((cVar12 == 'Z' || (cVar12 == 'x')) || (cVar12 == 'X')))))) {
                MSL_C.PPCEABI.bare.H::strcat(acStack81 + 1,"\'");
              }
              else {
                MSL_C.PPCEABI.bare.H::strcat(acStack81 + 1,"s");
              }
            }
            pbVar16 = (byte *)(acStack81 + 1);
            while (*pbVar16 != 0) {
              bVar1 = *pbVar16 >> 4;
              if ((bVar1 == 8) || (bVar1 == 9)) {
                uVar14 = (uint)CONCAT11((acStack81 + 1)[iVar18],(acStack81 + 1)[iVar18 + 1]);
                iVar18 = iVar18 + 2;
                pbVar16 = pbVar16 + 2;
              }
              else {
                uVar14 = (uint)(byte)acStack81[iVar18 + 1];
                iVar18 = iVar18 + 1;
                pbVar16 = pbVar16 + 1;
              }
              if (local_90 == 0) {
                dVar21 = (double)charLength(this,local_98,uVar14,true);
              }
              else {
                dVar21 = (double)charLength(this,local_98,uVar14,false);
                dVar21 = (double)(float)((double)local_94 + dVar21);
              }
              local_94 = (float)dVar21;
              local_90 = local_90 + 1;
            }
            local_28 = (double)(longlong)(int)(f_op_msg_mng::0_5 + local_94);
            local_88[local_8c] = (int)(f_op_msg_mng::0_5 + local_94);
          }
          else {
            if (((cVar12 == '\0') && (pcVar11[3] == '\0')) && (pcVar11[4] == '\b')) {
              bVar6 = true;
              iVar18 = 0;
              for (iVar20 = 0; iVar20 < local_8c; iVar20 = iVar20 + 1) {
                *(undefined4 *)(&this->field_0xd8 + iVar18) =
                     *(undefined4 *)((int)local_88 + iVar18);
                iVar18 = iVar18 + 4;
              }
              this->field_0x130 = local_8c + -1;
              local_8c = 0;
            }
            else {
              if (((cVar12 == '\0') && (pcVar11[3] == '\0')) && (pcVar11[4] == '\t')) {
                bVar6 = true;
                iVar18 = 0;
                for (iVar20 = 0; iVar20 < local_8c; iVar20 = iVar20 + 1) {
                  *(undefined4 *)(&this->field_0xd8 + iVar18) =
                       *(undefined4 *)((int)local_88 + iVar18);
                  *(undefined4 *)((int)local_88 + iVar18) = 0;
                  iVar18 = iVar18 + 4;
                }
                this->field_0x130 = local_8c + -1;
                local_8c = 0;
              }
              else {
                if (((cVar12 == '\0') && (pcVar11[3] == '\0')) && (pcVar11[4] == '\n')) {
                  if (((*(char *)&this->field_0x295 == '\0') && (this->field_0x130 == 0)) &&
                     (f_op_msg_mng::0_0 == this->field_0x14)) {
                    *(undefined *)&this->field_0x295 = 1;
                  }
                  local_28 = (double)CONCAT44(0x43300000,local_98 ^ 0x80000000);
                  local_94 = local_94 + (float)(local_28 - f_op_msg_mng::_4895);
                  local_30 = (double)(longlong)(int)(f_op_msg_mng::0_5 + local_94);
                  local_88[local_8c] = (int)(f_op_msg_mng::0_5 + local_94);
                  local_90 = local_90 + 1;
                }
                else {
                  if (((cVar12 == '\0') && (pcVar11[3] == '\0')) && (pcVar11[4] == '\v')) {
                    if (((*(char *)&this->field_0x295 == '\0') && (this->field_0x130 == 0)) &&
                       (f_op_msg_mng::0_0 == this->field_0x14)) {
                      *(undefined *)&this->field_0x295 = 1;
                    }
                    local_28 = (double)CONCAT44(0x43300000,local_98 ^ 0x80000000);
                    local_94 = local_94 + (float)(local_28 - f_op_msg_mng::_4895);
                    local_30 = (double)(longlong)(int)(f_op_msg_mng::0_5 + local_94);
                    local_88[local_8c] = (int)(f_op_msg_mng::0_5 + local_94);
                    local_90 = local_90 + 1;
                  }
                  else {
                    if (((cVar12 == '\0') && (pcVar11[3] == '\0')) && (pcVar11[4] == '\f')) {
                      if (((*(char *)&this->field_0x295 == '\0') && (this->field_0x130 == 0)) &&
                         (f_op_msg_mng::0_0 == this->field_0x14)) {
                        *(undefined *)&this->field_0x295 = 1;
                      }
                      local_28 = (double)CONCAT44(0x43300000,local_98 ^ 0x80000000);
                      local_94 = local_94 + (float)(local_28 - f_op_msg_mng::_4895);
                      local_30 = (double)(longlong)(int)(f_op_msg_mng::0_5 + local_94);
                      local_88[local_8c] = (int)(f_op_msg_mng::0_5 + local_94);
                      local_90 = local_90 + 1;
                    }
                    else {
                      if (((cVar12 == '\0') && (pcVar11[3] == '\0')) && (pcVar11[4] == '\r')) {
                        if (((*(char *)&this->field_0x295 == '\0') && (this->field_0x130 == 0)) &&
                           (f_op_msg_mng::0_0 == this->field_0x14)) {
                          *(undefined *)&this->field_0x295 = 1;
                        }
                        local_28 = (double)CONCAT44(0x43300000,local_98 ^ 0x80000000);
                        local_94 = local_94 + (float)(local_28 - f_op_msg_mng::_4895);
                        local_30 = (double)(longlong)(int)(f_op_msg_mng::0_5 + local_94);
                        local_88[local_8c] = (int)(f_op_msg_mng::0_5 + local_94);
                        local_90 = local_90 + 1;
                      }
                      else {
                        if (((cVar12 == '\0') && (pcVar11[3] == '\0')) && (pcVar11[4] == '\x0e')) {
                          if (((*(char *)&this->field_0x295 == '\0') && (this->field_0x130 == 0)) &&
                             (f_op_msg_mng::0_0 == this->field_0x14)) {
                            *(undefined *)&this->field_0x295 = 1;
                          }
                          local_28 = (double)CONCAT44(0x43300000,local_98 ^ 0x80000000);
                          local_94 = local_94 + (float)(local_28 - f_op_msg_mng::_4895);
                          local_30 = (double)(longlong)(int)(f_op_msg_mng::0_5 + local_94);
                          local_88[local_8c] = (int)(f_op_msg_mng::0_5 + local_94);
                          local_90 = local_90 + 1;
                        }
                        else {
                          if (((cVar12 == '\0') && (pcVar11[3] == '\0')) && (pcVar11[4] == '\x0f'))
                          {
                            if (((*(char *)&this->field_0x295 == '\0') && (this->field_0x130 == 0))
                               && (f_op_msg_mng::0_0 == this->field_0x14)) {
                              *(undefined *)&this->field_0x295 = 1;
                            }
                            local_28 = (double)CONCAT44(0x43300000,local_98 ^ 0x80000000);
                            local_94 = local_94 + (float)(local_28 - f_op_msg_mng::_4895);
                            local_30 = (double)(longlong)(int)(f_op_msg_mng::0_5 + local_94);
                            local_88[local_8c] = (int)(f_op_msg_mng::0_5 + local_94);
                            local_90 = local_90 + 1;
                          }
                          else {
                            if (((cVar12 == '\0') && (pcVar11[3] == '\0')) && (pcVar11[4] == '\x10')
                               ) {
                              if (((*(char *)&this->field_0x295 == '\0') && (this->field_0x130 == 0)
                                  ) && (f_op_msg_mng::0_0 == this->field_0x14)) {
                                *(undefined *)&this->field_0x295 = 1;
                              }
                              local_28 = (double)CONCAT44(0x43300000,local_98 ^ 0x80000000);
                              local_94 = local_94 + (float)(local_28 - f_op_msg_mng::_4895);
                              local_30 = (double)(longlong)(int)(f_op_msg_mng::0_5 + local_94);
                              local_88[local_8c] = (int)(f_op_msg_mng::0_5 + local_94);
                              local_90 = local_90 + 1;
                            }
                            else {
                              if (((cVar12 == '\0') && (pcVar11[3] == '\0')) &&
                                 (pcVar11[4] == '\x11')) {
                                if (((*(char *)&this->field_0x295 == '\0') &&
                                    (this->field_0x130 == 0)) &&
                                   (f_op_msg_mng::0_0 == this->field_0x14)) {
                                  *(undefined *)&this->field_0x295 = 1;
                                }
                                local_28 = (double)CONCAT44(0x43300000,local_98 ^ 0x80000000);
                                local_94 = local_94 + (float)(local_28 - f_op_msg_mng::_4895);
                                local_30 = (double)(longlong)(int)(f_op_msg_mng::0_5 + local_94);
                                local_88[local_8c] = (int)(f_op_msg_mng::0_5 + local_94);
                                local_90 = local_90 + 1;
                              }
                              else {
                                if (((cVar12 == '\0') && (pcVar11[3] == '\0')) &&
                                   (pcVar11[4] == '\x12')) {
                                  if (((*(char *)&this->field_0x295 == '\0') &&
                                      (this->field_0x130 == 0)) &&
                                     (f_op_msg_mng::0_0 == this->field_0x14)) {
                                    *(undefined *)&this->field_0x295 = 1;
                                  }
                                  local_28 = (double)CONCAT44(0x43300000,local_98 ^ 0x80000000);
                                  local_94 = local_94 + (float)(local_28 - f_op_msg_mng::_4895);
                                  local_30 = (double)(longlong)(int)(f_op_msg_mng::0_5 + local_94);
                                  local_88[local_8c] = (int)(f_op_msg_mng::0_5 + local_94);
                                  local_90 = local_90 + 1;
                                }
                                else {
                                  if (((cVar12 == '\0') && (pcVar11[3] == '\0')) &&
                                     (pcVar11[4] == '\x13')) {
                                    if (((*(char *)&this->field_0x295 == '\0') &&
                                        (this->field_0x130 == 0)) &&
                                       (f_op_msg_mng::0_0 == this->field_0x14)) {
                                      *(undefined *)&this->field_0x295 = 1;
                                    }
                                    local_28 = (double)CONCAT44(0x43300000,local_98 ^ 0x80000000);
                                    local_94 = local_94 + (float)(local_28 - f_op_msg_mng::_4895);
                                    local_30 = (double)(longlong)(int)(f_op_msg_mng::0_5 + local_94)
                                    ;
                                    local_88[local_8c] = (int)(f_op_msg_mng::0_5 + local_94);
                                    local_90 = local_90 + 1;
                                  }
                                  else {
                                    if (((cVar12 == '\0') && (pcVar11[3] == '\0')) &&
                                       (pcVar11[4] == '\x14')) {
                                      if (((*(char *)&this->field_0x295 == '\0') &&
                                          (this->field_0x130 == 0)) &&
                                         (f_op_msg_mng::0_0 == this->field_0x14)) {
                                        *(undefined *)&this->field_0x295 = 1;
                                      }
                                      local_28 = (double)CONCAT44(0x43300000,local_98 ^ 0x80000000);
                                      local_94 = local_94 + (float)(local_28 - f_op_msg_mng::_4895);
                                      local_30 = (double)(longlong)
                                                         (int)(f_op_msg_mng::0_5 + local_94);
                                      local_88[local_8c] = (int)(f_op_msg_mng::0_5 + local_94);
                                      local_90 = local_90 + 1;
                                    }
                                    else {
                                      if (((cVar12 == '\0') && (pcVar11[3] == '\0')) &&
                                         (pcVar11[4] == '\x15')) {
                                        if (((*(char *)&this->field_0x295 == '\0') &&
                                            (this->field_0x130 == 0)) &&
                                           (f_op_msg_mng::0_0 == this->field_0x14)) {
                                          *(undefined *)&this->field_0x295 = 1;
                                        }
                                        local_28 = (double)CONCAT44(0x43300000,local_98 ^ 0x80000000
                                                                   );
                                        local_94 = local_94 +
                                                   (float)(local_28 - f_op_msg_mng::_4895);
                                        local_30 = (double)(longlong)
                                                           (int)(f_op_msg_mng::0_5 + local_94);
                                        local_88[local_8c] = (int)(f_op_msg_mng::0_5 + local_94);
                                        local_90 = local_90 + 1;
                                      }
                                      else {
                                        if (((cVar12 == '\0') && (pcVar11[3] == '\0')) &&
                                           (pcVar11[4] == '\x16')) {
                                          if (((*(char *)&this->field_0x295 == '\0') &&
                                              (this->field_0x130 == 0)) &&
                                             (f_op_msg_mng::0_0 == this->field_0x14)) {
                                            *(undefined *)&this->field_0x295 = 1;
                                          }
                                          local_28 = (double)CONCAT44(0x43300000,
                                                                      local_98 ^ 0x80000000);
                                          local_94 = local_94 +
                                                     (float)(local_28 - f_op_msg_mng::_4895);
                                          local_30 = (double)(longlong)
                                                             (int)(f_op_msg_mng::0_5 + local_94);
                                          local_88[local_8c] = (int)(f_op_msg_mng::0_5 + local_94);
                                          local_90 = local_90 + 1;
                                        }
                                        else {
                                          if (((cVar12 == '\0') && (pcVar11[3] == '\0')) &&
                                             (pcVar11[4] == '\x17')) {
                                            if (((*(char *)&this->field_0x295 == '\0') &&
                                                (this->field_0x130 == 0)) &&
                                               (f_op_msg_mng::0_0 == this->field_0x14)) {
                                              *(undefined *)&this->field_0x295 = 1;
                                            }
                                            local_28 = (double)CONCAT44(0x43300000,
                                                                        local_98 ^ 0x80000000);
                                            local_94 = local_94 +
                                                       (float)(local_28 - f_op_msg_mng::_4895);
                                            local_30 = (double)(longlong)
                                                               (int)(f_op_msg_mng::0_5 + local_94);
                                            local_88[local_8c] = (int)(f_op_msg_mng::0_5 + local_94)
                                            ;
                                            local_90 = local_90 + 1;
                                          }
                                          else {
                                            if (((cVar12 == '\0') && (pcVar11[3] == '\0')) &&
                                               (pcVar11[4] == '\x18')) {
                                              if (((*(char *)&this->field_0x295 == '\0') &&
                                                  (this->field_0x130 == 0)) &&
                                                 (f_op_msg_mng::0_0 == this->field_0x14)) {
                                                *(undefined *)&this->field_0x295 = 1;
                                              }
                                              local_28 = (double)CONCAT44(0x43300000,
                                                                          local_98 ^ 0x80000000);
                                              local_94 = local_94 +
                                                         (float)(local_28 - f_op_msg_mng::_4895);
                                              local_30 = (double)(longlong)
                                                                 (int)(f_op_msg_mng::0_5 + local_94)
                                              ;
                                              local_88[local_8c] =
                                                   (int)(f_op_msg_mng::0_5 + local_94);
                                              local_90 = local_90 + 1;
                                            }
                                            else {
                                              if (((cVar12 == '\0') && (pcVar11[3] == '\0')) &&
                                                 (pcVar11[4] == '\x19')) {
                                                if (((*(char *)&this->field_0x295 == '\0') &&
                                                    (this->field_0x130 == 0)) &&
                                                   (f_op_msg_mng::0_0 == this->field_0x14)) {
                                                  *(undefined *)&this->field_0x295 = 1;
                                                }
                                                local_28 = (double)CONCAT44(0x43300000,
                                                                            local_98 ^ 0x80000000);
                                                local_94 = local_94 +
                                                           (float)(local_28 - f_op_msg_mng::_4895);
                                                local_30 = (double)(longlong)
                                                                   (int)(f_op_msg_mng::0_5 +
                                                                        local_94);
                                                local_88[local_8c] =
                                                     (int)(f_op_msg_mng::0_5 + local_94);
                                                local_90 = local_90 + 1;
                                              }
                                              else {
                                                if (((cVar12 == '\0') && (pcVar11[3] == '\0')) &&
                                                   (pcVar11[4] == '\x1a')) {
                                                  if (((*(char *)&this->field_0x295 == '\0') &&
                                                      (this->field_0x130 == 0)) &&
                                                     (f_op_msg_mng::0_0 == this->field_0x14)) {
                                                    *(undefined *)&this->field_0x295 = 1;
                                                  }
                                                  local_28 = (double)CONCAT44(0x43300000,
                                                                              local_98 ^ 0x80000000)
                                                  ;
                                                  local_94 = local_94 +
                                                             (float)(local_28 - f_op_msg_mng::_4895)
                                                  ;
                                                  local_30 = (double)(longlong)
                                                                     (int)(f_op_msg_mng::0_5 +
                                                                          local_94);
                                                  local_88[local_8c] =
                                                       (int)(f_op_msg_mng::0_5 + local_94);
                                                  local_90 = local_90 + 1;
                                                }
                                                else {
                                                  if (((cVar12 == '\0') && (pcVar11[3] == '\0')) &&
                                                     (pcVar11[4] == '\x1b')) {
                                                    if (((*(char *)&this->field_0x295 == '\0') &&
                                                        (this->field_0x130 == 0)) &&
                                                       (f_op_msg_mng::0_0 == this->field_0x14)) {
                                                      *(undefined *)&this->field_0x295 = 1;
                                                    }
                                                    local_28 = (double)CONCAT44(0x43300000,
                                                                                local_98 ^
                                                                                0x80000000);
                                                    local_94 = local_94 +
                                                               (float)(local_28 -
                                                                      f_op_msg_mng::_4895);
                                                    local_30 = (double)(longlong)
                                                                       (int)(f_op_msg_mng::0_5 +
                                                                            local_94);
                                                    local_88[local_8c] =
                                                         (int)(f_op_msg_mng::0_5 + local_94);
                                                    local_90 = local_90 + 1;
                                                  }
                                                  else {
                                                    if (((cVar12 == '\0') && (pcVar11[3] == '\0'))
                                                       && (pcVar11[4] == '\x1c')) {
                                                      if (((*(char *)&this->field_0x295 == '\0') &&
                                                          (this->field_0x130 == 0)) &&
                                                         (f_op_msg_mng::0_0 == this->field_0x14)) {
                                                        *(undefined *)&this->field_0x295 = 1;
                                                      }
                                                      local_28 = (double)CONCAT44(0x43300000,
                                                                                  local_98 ^
                                                                                  0x80000000);
                                                      local_94 = local_94 +
                                                                 (float)(local_28 -
                                                                        f_op_msg_mng::_4895);
                                                      local_30 = (double)(longlong)
                                                                         (int)(f_op_msg_mng::0_5 +
                                                                              local_94);
                                                      local_88[local_8c] =
                                                           (int)(f_op_msg_mng::0_5 + local_94);
                                                      local_90 = local_90 + 1;
                                                    }
                                                    else {
                                                      if (((cVar12 == '\0') && (pcVar11[3] == '\0'))
                                                         && (pcVar11[4] == '\x1d')) {
                                                        if (((*(char *)&this->field_0x295 == '\0')
                                                            && (this->field_0x130 == 0)) &&
                                                           (f_op_msg_mng::0_0 == this->field_0x14))
                                                        {
                                                          *(undefined *)&this->field_0x295 = 1;
                                                        }
                                                        local_28 = (double)CONCAT44(0x43300000,
                                                                                    local_98 ^
                                                                                    0x80000000);
                                                        local_94 = local_94 +
                                                                   (float)(local_28 -
                                                                          f_op_msg_mng::_4895);
                                                        local_30 = (double)(longlong)
                                                                           (int)(f_op_msg_mng::0_5 +
                                                                                local_94);
                                                        local_88[local_8c] =
                                                             (int)(f_op_msg_mng::0_5 + local_94);
                                                        local_90 = local_90 + 1;
                                                      }
                                                      else {
                                                        if (((cVar12 == '\0') &&
                                                            (pcVar11[3] == '\0')) &&
                                                           (pcVar11[4] == '\x1e')) {
                                                          local_28 = (double)CONCAT44(0x43300000,
                                                                                      local_98 ^
                                                                                      0x80000000);
                                                          local_94 = local_94 +
                                                                     (float)(local_28 -
                                                                            f_op_msg_mng::_4895);
                                                          local_90 = local_90 + 1;
                                                        }
                                                        else {
                                                          if (((cVar12 == '\0') &&
                                                              (pcVar11[3] == '\0')) &&
                                                             (pcVar11[4] == '\x1f')) {
                                                            local_28 = (double)CONCAT44(0x43300000,
                                                                                        local_98 ^
                                                                                        0x80000000);
                                                            local_94 = local_94 +
                                                                       (float)(local_28 -
                                                                              f_op_msg_mng::_4895);
                                                            local_90 = local_90 + 1;
                                                          }
                                                          else {
                                                            if (((cVar12 == '\0') &&
                                                                (pcVar11[3] == '\0')) &&
                                                               (pcVar11[4] == '9')) {
                                                              if (((*(char *)&this->field_0x295 ==
                                                                    '\0') &&
                                                                  (this->field_0x130 == 0)) &&
                                                                 (f_op_msg_mng::0_0 ==
                                                                  this->field_0x14)) {
                                                                *(undefined *)&this->field_0x295 = 1
                                                                ;
                                                              }
                                                              local_28 = (double)CONCAT44(0x43300000
                                                                                          ,local_98 
                                                  ^ 0x80000000);
                                                  local_94 = local_94 +
                                                             (float)(local_28 - f_op_msg_mng::_4895)
                                                  ;
                                                  local_30 = (double)(longlong)
                                                                     (int)(f_op_msg_mng::0_5 +
                                                                          local_94);
                                                  local_88[local_8c] =
                                                       (int)(f_op_msg_mng::0_5 + local_94);
                                                  local_90 = local_90 + 1;
                                                  }
                                                  else {
                                                    if (((cVar12 == '\0') && (pcVar11[3] == '\0'))
                                                       && (pcVar11[4] == ':')) {
                                                      if (((*(char *)&this->field_0x295 == '\0') &&
                                                          (this->field_0x130 == 0)) &&
                                                         (f_op_msg_mng::0_0 == this->field_0x14)) {
                                                        *(undefined *)&this->field_0x295 = 1;
                                                      }
                                                      local_28 = (double)CONCAT44(0x43300000,
                                                                                  local_98 ^
                                                                                  0x80000000);
                                                      local_94 = local_94 +
                                                                 (float)(local_28 -
                                                                        f_op_msg_mng::_4895);
                                                      local_30 = (double)(longlong)
                                                                         (int)(f_op_msg_mng::0_5 +
                                                                              local_94);
                                                      local_88[local_8c] =
                                                           (int)(f_op_msg_mng::0_5 + local_94);
                                                      local_90 = local_90 + 1;
                                                    }
                                                    else {
                                                      if (((cVar12 == '\0') && (pcVar11[3] == '\0'))
                                                         && (pcVar11[4] == ' ')) {
                                                        tag_len_kaisen_game(this,&local_90,&local_94
                                                                            ,local_88,
                                                                            (int *)&local_98,
                                                                            &local_8c);
                                                      }
                                                      else {
                                                        if (((((cVar12 == '\0') &&
                                                              (pcVar11[3] == '\0')) &&
                                                             (pcVar11[4] == '!')) ||
                                                            (((cVar12 == '\0' &&
                                                              (pcVar11[3] == '\0')) &&
                                                             (pcVar11[4] == '$')))) ||
                                                           (((((cVar12 == '\0' &&
                                                               (pcVar11[3] == '\0')) &&
                                                              (pcVar11[4] == '%')) ||
                                                             (((cVar12 == '\0' &&
                                                               (pcVar11[3] == '\0')) &&
                                                              (pcVar11[4] == ',')))) ||
                                                            (((cVar12 == '\0' &&
                                                              (pcVar11[3] == '\0')) &&
                                                             (pcVar11[4] == '6')))))) {
                                                          tag_len_rupee(this,&local_90,&local_94,
                                                                        local_88,(int *)&local_98,
                                                                        &local_8c);
                                                        }
                                                        else {
                                                          if ((((cVar12 == '\0') &&
                                                               (pcVar11[3] == '\0')) &&
                                                              (pcVar11[4] == '\"')) ||
                                                             (((cVar12 == '\0' &&
                                                               (pcVar11[3] == '\0')) &&
                                                              (pcVar11[4] == '#')))) {
                                                            if (pcVar11[4] == '\"') {
                                                              uVar10 = f_op_msg_mng::
                                                                       dComIfGp_getNpcNameMessageID
                                                                                 ();
                                                              getString(this,(char *)local_64,uVar10
                                                                       );
                                                            }
                                                            else {
                                                              if (pcVar11[4] == '#') {
                                                                uVar10 = f_op_msg_mng::
                                                                                                                                                  
                                                  dComIfGp_getItemNameMessageID();
                                                  getString(this,(char *)local_64,uVar10);
                                                  }
                                                  }
                                                  pbVar17 = local_64;
                                                  pbVar16 = pbVar17;
                                                  while (*pbVar16 != 0) {
                                                    bVar1 = *pbVar17;
                                                    pbVar16 = pbVar16 + 1;
                                                    pbVar17 = pbVar17 + 1;
                                                    if (local_90 == 0) {
                                                      dVar21 = (double)charLength(this,local_98,
                                                                                  (uint)bVar1,true);
                                                    }
                                                    else {
                                                      dVar21 = (double)charLength(this,local_98,
                                                                                  (uint)bVar1,false)
                                                      ;
                                                      dVar21 = (double)(float)((double)local_94 +
                                                                              dVar21);
                                                    }
                                                    local_94 = (float)dVar21;
                                                    local_90 = local_90 + 1;
                                                  }
                                                  local_28 = (double)(longlong)
                                                                     (int)(f_op_msg_mng::0_5 +
                                                                          local_94);
                                                  local_88[local_8c] =
                                                       (int)(f_op_msg_mng::0_5 + local_94);
                                                  }
                                                  else {
                                                    if (((cVar12 == '\0') && (pcVar11[3] == '\0'))
                                                       && (pcVar11[4] == '&')) {
                                                      tag_len_num_input(this,&local_90,&local_94,
                                                                        local_88,(int *)&local_98,
                                                                        &local_8c);
                                                    }
                                                    else {
                                                      if (((cVar12 == '\0') && (pcVar11[3] == '\0'))
                                                         && (pcVar11[4] == '\'')) {
                                                        local_28 = (double)CONCAT44(0x43300000,
                                                                                    local_98 ^
                                                                                    0x80000000);
                                                        local_94 = local_94 +
                                                                   (float)(local_28 -
                                                                          f_op_msg_mng::_4895);
                                                        local_90 = local_90 + 1;
                                                      }
                                                      else {
                                                        if (((cVar12 == '\0') &&
                                                            (pcVar11[3] == '\0')) &&
                                                           (pcVar11[4] == '(')) {
                                                          tag_len_sword_game(this,&local_90,
                                                                             &local_94,local_88,
                                                                             (int *)&local_98,
                                                                             &local_8c);
                                                        }
                                                        else {
                                                          if (((cVar12 == '\0') &&
                                                              (pcVar11[3] == '\0')) &&
                                                             (pcVar11[4] == ')')) {
                                                            uVar14 = f_op_msg_mng::
                                                                     dComIfGs_getEventReg(0xba0f);
                                                            getString(this,(char *)local_78,
                                                                      (uVar14 & 0xff) + 0x1b37);
                                                            pbVar17 = local_78;
                                                            pbVar16 = pbVar17;
                                                            while (*pbVar17 != 0) {
                                                              bVar1 = *pbVar16;
                                                              pbVar17 = pbVar17 + 1;
                                                              pbVar16 = pbVar16 + 1;
                                                              if (local_90 == 0) {
                                                                dVar21 = (double)charLength(this,
                                                  local_98,(uint)bVar1,true);
                                                  }
                                                  else {
                                                    dVar21 = (double)charLength(this,local_98,
                                                                                (uint)bVar1,false);
                                                    dVar21 = (double)(float)((double)local_94 +
                                                                            dVar21);
                                                  }
                                                  local_94 = (float)dVar21;
                                                  local_90 = local_90 + 1;
                                                  }
                                                  local_28 = (double)(longlong)
                                                                     (int)(f_op_msg_mng::0_5 +
                                                                          local_94);
                                                  local_88[local_8c] =
                                                       (int)(f_op_msg_mng::0_5 + local_94);
                                                  }
                                                  else {
                                                    if (((cVar12 == '\0') && (pcVar11[3] == '\0'))
                                                       && (pcVar11[4] == '*')) {
                                                      if (((*(char *)&this->field_0x295 == '\0') &&
                                                          (this->field_0x130 == 0)) &&
                                                         (f_op_msg_mng::0_0 == this->field_0x14)) {
                                                        *(undefined *)&this->field_0x295 = 1;
                                                      }
                                                      local_28 = (double)CONCAT44(0x43300000,
                                                                                  local_98 ^
                                                                                  0x80000000);
                                                      local_94 = local_94 +
                                                                 (float)(local_28 -
                                                                        f_op_msg_mng::_4895);
                                                      local_30 = (double)(longlong)
                                                                         (int)(f_op_msg_mng::0_5 +
                                                                              local_94);
                                                      local_88[local_8c] =
                                                           (int)(f_op_msg_mng::0_5 + local_94);
                                                      local_90 = local_90 + 1;
                                                    }
                                                    else {
                                                      if (((cVar12 == '\0') && (pcVar11[3] == '\0'))
                                                         && (pcVar11[4] == '+')) {
                                                        tag_len_letter_game(this,&local_90,&local_94
                                                                            ,local_88,
                                                                            (int *)&local_98,
                                                                            &local_8c);
                                                      }
                                                      else {
                                                        if (((cVar12 == '\0') &&
                                                            (pcVar11[3] == '\0')) &&
                                                           (pcVar11[4] == ';')) {
                                                          tag_len_letter_game_max
                                                                    (this,&local_90,&local_94,
                                                                     local_88,(int *)&local_98,
                                                                     &local_8c);
                                                        }
                                                        else {
                                                          if (((cVar12 == '\0') &&
                                                              (pcVar11[3] == '\0')) &&
                                                             (pcVar11[4] == '<')) {
                                                            tag_len_fish(this,&local_90,&local_94,
                                                                         local_88,(int *)&local_98,
                                                                         &local_8c);
                                                          }
                                                          else {
                                                            if (((cVar12 == '\0') &&
                                                                (pcVar11[3] == '\0')) &&
                                                               (pcVar11[4] == '=')) {
                                                              tag_len_fish_rupee(this,&local_90,
                                                                                 &local_94,local_88,
                                                                                 (int *)&local_98,
                                                                                 &local_8c);
                                                            }
                                                            else {
                                                              if (((cVar12 == '\0') &&
                                                                  (pcVar11[3] == '\0')) &&
                                                                 (pcVar11[4] == '-')) {
                                                                tag_len_letter(this,&local_90,
                                                                               &local_94,local_88,
                                                                               (int *)&local_98,
                                                                               &local_8c);
                                                              }
                                                              else {
                                                                if (((cVar12 == '\0') &&
                                                                    (pcVar11[3] == '\0')) &&
                                                                   (pcVar11[4] == '.')) {
                                                                  tag_len_rescue(this,&local_90,
                                                                                 &local_94,local_88,
                                                                                 (int *)&local_98,
                                                                                 &local_8c);
                                                                }
                                                                else {
                                                                  if (((cVar12 == '\0') &&
                                                                      (pcVar11[3] == '\0')) &&
                                                                     (pcVar11[4] == '/')) {
                                                                    tag_len_forest_timer
                                                                              (this,&local_90,
                                                                               &local_94,local_88,
                                                                               (int *)&local_98,
                                                                               &local_8c);
                                                                  }
                                                                  else {
                                                                    if ((((cVar12 == '\0') &&
                                                                         (pcVar11[3] == '\0')) &&
                                                                        (pcVar11[4] == '0')) ||
                                                                       (((cVar12 == '\0' &&
                                                                         (pcVar11[3] == '\0')) &&
                                                                        (pcVar11[4] == '1')))) {
                                                                      tag_len_birdman(this,&local_90
                                                                                      ,&local_94,
                                                                                      local_88,(int 
                                                  *)&local_98,&local_8c);
                                                  }
                                                  else {
                                                    if (((cVar12 == '\0') && (pcVar11[3] == '\0'))
                                                       && (pcVar11[4] == '2')) {
                                                      tag_len_point(this,&local_90,&local_94,
                                                                    local_88,(int *)&local_98,
                                                                    &local_8c);
                                                    }
                                                    else {
                                                      if (((cVar12 == '\0') && (pcVar11[3] == '\0'))
                                                         && (pcVar11[4] == '3')) {
                                                        tag_len_get_pendant(this,&local_90,&local_94
                                                                            ,local_88,
                                                                            (int *)&local_98,
                                                                            &local_8c);
                                                      }
                                                      else {
                                                        if (((cVar12 == '\0') &&
                                                            (pcVar11[3] == '\0')) &&
                                                           (pcVar11[4] == '4')) {
                                                          tag_len_rev_pendant(this,&local_90,
                                                                              &local_94,local_88,
                                                                              (int *)&local_98,
                                                                              &local_8c);
                                                        }
                                                        else {
                                                          if (((cVar12 == '\0') &&
                                                              (pcVar11[3] == '\0')) &&
                                                             (pcVar11[4] == '5')) {
                                                            tag_len_pig_timer(this,&local_90,
                                                                              &local_94,local_88,
                                                                              (int *)&local_98,
                                                                              &local_8c);
                                                          }
                                                          else {
                                                            if (((cVar12 == '\0') &&
                                                                (pcVar11[3] == '\0')) &&
                                                               (pcVar11[4] == '7')) {
                                                              tag_len_get_bomb(this,&local_90,
                                                                               &local_94,local_88,
                                                                               (int *)&local_98,
                                                                               &local_8c);
                                                            }
                                                            else {
                                                              if (((cVar12 == '\0') &&
                                                                  (pcVar11[3] == '\0')) &&
                                                                 (pcVar11[4] == '8')) {
                                                                tag_len_get_arrow(this,&local_90,
                                                                                  &local_94,local_88
                                                                                  ,(int *)&local_98,
                                                                                  &local_8c);
                                                              }
                                                              else {
                                                                if (((cVar12 == '\0') &&
                                                                    (pcVar11[3] == '\0')) &&
                                                                   (pcVar11[4] == '>')) {
                                                                  tag_len_stock_bokobaba
                                                                            (this,&local_90,
                                                                             &local_94,local_88,
                                                                             (int *)&local_98,
                                                                             &local_8c);
                                                                }
                                                                else {
                                                                  if (((cVar12 == '\0') &&
                                                                      (pcVar11[3] == '\0')) &&
                                                                     (pcVar11[4] == '?')) {
                                                                    tag_len_stock_dokuro
                                                                              (this,&local_90,
                                                                               &local_94,local_88,
                                                                               (int *)&local_98,
                                                                               &local_8c);
                                                                  }
                                                                  else {
                                                                    if (((cVar12 == '\0') &&
                                                                        (pcVar11[3] == '\0')) &&
                                                                       (pcVar11[4] == '@')) {
                                                                      tag_len_stock_chuchu
                                                                                (this,&local_90,
                                                                                 &local_94,local_88,
                                                                                 (int *)&local_98,
                                                                                 &local_8c);
                                                                    }
                                                                    else {
                                                                      if (((cVar12 == '\0') &&
                                                                          (pcVar11[3] == '\0')) &&
                                                                         (pcVar11[4] == 'A')) {
                                                                        tag_len_stock_pendant
                                                                                  (this,&local_90,
                                                                                   &local_94,
                                                                                   local_88,(int *)&
                                                  local_98,&local_8c);
                                                  }
                                                  else {
                                                    if (((cVar12 == '\0') && (pcVar11[3] == '\0'))
                                                       && (pcVar11[4] == 'B')) {
                                                      tag_len_stock_hane(this,&local_90,&local_94,
                                                                         local_88,(int *)&local_98,
                                                                         &local_8c);
                                                    }
                                                    else {
                                                      if (((cVar12 == '\0') && (pcVar11[3] == '\0'))
                                                         && (pcVar11[4] == 'C')) {
                                                        tag_len_stock_kenshi
                                                                  (this,&local_90,&local_94,local_88
                                                                   ,(int *)&local_98,&local_8c);
                                                      }
                                                      else {
                                                        if (((cVar12 == '\0') &&
                                                            (pcVar11[3] == '\0')) &&
                                                           (pcVar11[4] == 'D')) {
                                                          tag_len_terry_rupee(this,&local_90,
                                                                              &local_94,local_88,
                                                                              (int *)&local_98,
                                                                              &local_8c);
                                                        }
                                                        else {
                                                          if (((cVar12 == '\0') &&
                                                              (pcVar11[3] == '\0')) &&
                                                             (pcVar11[4] == 'E')) {
                                                            tag_len_input_bokobaba
                                                                      (this,&local_90,&local_94,
                                                                       local_88,(int *)&local_98,
                                                                       &local_8c);
                                                          }
                                                          else {
                                                            if (((cVar12 == '\0') &&
                                                                (pcVar11[3] == '\0')) &&
                                                               (pcVar11[4] == 'F')) {
                                                              tag_len_input_dokuro
                                                                        (this,&local_90,&local_94,
                                                                         local_88,(int *)&local_98,
                                                                         &local_8c);
                                                            }
                                                            else {
                                                              if (((cVar12 == '\0') &&
                                                                  (pcVar11[3] == '\0')) &&
                                                                 (pcVar11[4] == 'G')) {
                                                                tag_len_input_chuchu
                                                                          (this,&local_90,&local_94,
                                                                           local_88,(int *)&local_98
                                                                           ,&local_8c);
                                                              }
                                                              else {
                                                                if (((cVar12 == '\0') &&
                                                                    (pcVar11[3] == '\0')) &&
                                                                   (pcVar11[4] == 'H')) {
                                                                  tag_len_input_pendant
                                                                            (this,&local_90,
                                                                             &local_94,local_88,
                                                                             (int *)&local_98,
                                                                             &local_8c);
                                                                }
                                                                else {
                                                                  if (((cVar12 == '\0') &&
                                                                      (pcVar11[3] == '\0')) &&
                                                                     (pcVar11[4] == 'I')) {
                                                                    tag_len_input_hane(this,&
                                                  local_90,&local_94,local_88,(int *)&local_98,
                                                  &local_8c);
                                                  }
                                                  else {
                                                    if (((cVar12 == '\0') && (pcVar11[3] == '\0'))
                                                       && (pcVar11[4] == 'J')) {
                                                      tag_len_input_kenshi
                                                                (this,&local_90,&local_94,local_88,
                                                                 (int *)&local_98,&local_8c);
                                                    }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
        iVar18 = iVar8 + *(char *)(*(int *)&this->field_0x3c + iVar8 + 1);
        iVar13 = local_8c;
      }
      if ((*(char *)&this->field_0x295 != '\0') && (cVar12 != '\0')) {
        *(undefined *)&this->field_0x295 = 0;
      }
      pbVar16 = (byte *)(*(int *)&this->field_0x3c + iVar8);
      bVar1 = *pbVar16;
      uVar14 = (uint)bVar1;
      if (uVar14 != 10) break;
      local_90 = 0;
      local_94 = f_op_msg_mng::0_0;
      iVar18 = iVar8 + 1;
      if (*(char *)(*(int *)&this->field_0x3c + iVar18) == '\0') {
        this->field_0x140 = this->field_0x13c;
      }
      if (bVar6) {
        if (bVar6) {
          *(int *)(&this->field_0xe8 + local_8c * 4) = local_88[local_8c];
        }
        iVar13 = local_8c + 1;
      }
      else {
        if (bVar7) {
          if (this->field_0x13c == this->field_0x138) {
            local_8c = local_8c + 1;
            this->field_0x130 = this->field_0x130 + 1;
          }
          else {
            this->field_0x138 = this->field_0x138 + 1;
          }
          bVar7 = false;
        }
        if (this->field_0x13c == this->field_0x138) {
          iVar13 = local_8c + 1;
          if ((int)(uint)*(byte *)(*(int *)&this->field_0xc + 0x16) <= iVar13) {
            pcVar11 = (char *)(*(int *)&this->field_0x3c + iVar18);
            if ((((*pcVar11 != '\x1a') || (pcVar11[2] != '\0')) ||
                ((pcVar11[3] != '\0' || (pcVar11[4] != '\b')))) &&
               ((((*pcVar11 != '\x1a' || (pcVar11[2] != '\0')) || (pcVar11[3] != '\0')) ||
                (pcVar11[4] != '\t')))) {
              iVar18 = 0;
              iVar8 = 4;
              do {
                *(undefined4 *)(&this->field_0xd8 + iVar18) =
                     *(undefined4 *)((int)local_88 + iVar18);
                iVar18 = iVar18 + 4;
                iVar8 = iVar8 + -1;
              } while (iVar8 != 0);
              this->field_0x134 = this->field_0x130;
              return iVar19;
            }
            bVar6 = true;
            iVar20 = 0;
            for (iVar15 = 0; iVar15 < iVar13; iVar15 = iVar15 + 1) {
              *(undefined4 *)(&this->field_0xd8 + iVar20) = *(undefined4 *)((int)local_88 + iVar20);
              iVar20 = iVar20 + 4;
            }
            this->field_0x130 = local_8c;
            local_8c = 0;
            iVar18 = iVar18 + *(char *)(*(int *)&this->field_0x3c + iVar8 + 2);
            iVar13 = local_8c;
          }
        }
        else {
          this->field_0x138 = this->field_0x138 + 1;
          local_88[0] = 0;
          iVar19 = iVar18;
          iVar13 = local_8c;
        }
      }
    }
    if (((int)uVar14 >> 4 == 8) || ((int)uVar14 >> 4 == 9)) {
      bVar2 = pbVar16[1];
      uVar14 = (uint)CONCAT11(bVar1,bVar2);
      cVar12 = f_op_msg_mng::dComIfGs_getClearCount();
      if ((cVar12 == '\0') && (*(char *)(*(int *)&this->field_0xc + 0xc) == '\f')) {
        iVar18 = 0;
        iVar20 = 0x61;
        do {
          if (CONCAT11(bVar1,bVar2) == *(short *)((int)&f_op_msg_mng::zfont + iVar18)) {
            uVar14 = (uint)*(ushort *)((int)&DAT_8037238a + iVar18);
            break;
          }
          iVar18 = iVar18 + 4;
          iVar20 = iVar20 + -1;
        } while (iVar20 != 0);
      }
      bVar5 = false;
    }
    else {
      bVar5 = true;
    }
    if (local_90 == 0) {
      dVar21 = (double)charLength(this,local_98,uVar14,true);
    }
    else {
      dVar21 = (double)charLength(this,local_98,uVar14,false);
      dVar21 = (double)(float)((double)local_94 + dVar21);
    }
    local_94 = (float)dVar21;
    local_90 = local_90 + 1;
    iVar18 = local_88[local_8c];
    local_28 = (double)(longlong)(int)(f_op_msg_mng::0_5 + (float)dVar21);
    local_88[local_8c] = (int)(f_op_msg_mng::0_5 + (float)dVar21);
    if ((!bVar6) && (local_8c != this->field_0x130)) {
      this->field_0x130 = this->field_0x130 + 1;
    }
    if ((int)this->field_0x128 <= local_88[local_8c]) {
      local_88[local_8c] = iVar18;
      iVar18 = local_8c + 1;
      local_90 = 1;
      local_94 = f_op_msg_mng::0_0;
      if (*(char *)(*(int *)&this->field_0x3c + iVar8) == '\0') {
        this->field_0x140 = this->field_0x13c;
      }
      if (this->field_0x13c == this->field_0x138) {
        if (iVar18 < (int)(uint)*(byte *)(*(int *)&this->field_0xc + 0x16)) {
          local_8c = iVar18;
          dVar21 = (double)charLength(this,local_98,uVar14,false);
          local_94 = (float)dVar21;
          local_28 = (double)(longlong)(int)(f_op_msg_mng::0_5 + (float)dVar21);
          local_88[local_8c] = (int)(f_op_msg_mng::0_5 + (float)dVar21);
        }
        else {
          pcVar11 = (char *)(*(int *)&this->field_0x3c + iVar8);
          if (((((*pcVar11 != '\x1a') || (pcVar11[2] != '\0')) || (pcVar11[3] != '\0')) ||
              (pcVar11[4] != '\b')) &&
             (((*pcVar11 != '\x1a' || (pcVar11[2] != '\0')) ||
              ((pcVar11[3] != '\0' || (pcVar11[4] != '\t')))))) {
            this->field_0x134 = this->field_0x130;
            iVar18 = 0;
            iVar8 = 4;
            do {
              *(undefined4 *)(&this->field_0xd8 + iVar18) = *(undefined4 *)((int)local_88 + iVar18);
              iVar18 = iVar18 + 4;
              iVar8 = iVar8 + -1;
            } while (iVar8 != 0);
            return iVar19;
          }
          bVar6 = true;
          iVar20 = 0;
          for (iVar13 = 0; iVar13 < iVar18; iVar13 = iVar13 + 1) {
            *(undefined4 *)(&this->field_0xd8 + iVar20) = *(undefined4 *)((int)local_88 + iVar20);
            iVar20 = iVar20 + 4;
          }
          this->field_0x130 = local_8c;
          local_8c = 0;
          iVar8 = iVar8 + *(char *)(*(int *)&this->field_0x3c + iVar8 + 1);
        }
      }
      else {
        this->field_0x138 = this->field_0x138 + 1;
        local_8c = 0;
        this->field_0x130 = 0;
        local_88[0] = 0;
        dVar21 = (double)charLength(this,local_98,uVar14,false);
        local_94 = (float)dVar21;
        local_28 = (double)(longlong)(int)(f_op_msg_mng::0_5 + (float)dVar21);
        local_88[local_8c] = (int)(f_op_msg_mng::0_5 + (float)dVar21);
      }
    }
    iVar13 = local_8c;
    if (bVar5) {
      iVar18 = iVar8 + 1;
    }
    else {
      iVar18 = iVar8 + 2;
    }
  } while( true );
}


namespace f_op_msg_mng {

/* __stdcall dComIfGs_getClearCount(void) */

byte dComIfGs_getClearCount(void)

{
  return d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mInfo.mNumGamesCompleted;
}


/* __stdcall dComIfGs_getEventReg(unsigned short) */

int dComIfGs_getEventReg(ushort param_1)

{
  ushort uVar1;
  
  uVar1 = dSv_event_c::getEventReg(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,param_1)
  ;
  return (uint)uVar1;
}


/* __stdcall dComIfGp_getItemNameMessageID(void) */

int dComIfGp_getItemNameMessageID(void)

{
  return d_com_inf_game::g_dComIfG_gameInfo.mPlay.mItemNameMessageID;
}


/* __stdcall dComIfGp_getNpcNameMessageID(void) */

int dComIfGp_getNpcNameMessageID(void)

{
  return d_com_inf_game::g_dComIfG_gameInfo.mPlay.mNpcNameMessageID;
}


/* __stdcall dComIfGs_getPalLanguage(void) */

byte dComIfGs_getPalLanguage(void)

{
  return d_com_inf_game::g_dComIfG_gameInfo.mGameLanguage;
}


/* WARNING: Unknown calling convention yet parameter storage is locked */
/* __stdcall dComIfGs_getPlayerName(void) */

char * dComIfGs_getPlayerName(void)

{
  return &d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mInfo.mPlayerName;
}

}

/* WARNING: Removing unreachable block (ram,0x80031134) */
/* __thiscall fopMsgM_msgDataProc_c::stringShift(void) */

void __thiscall fopMsgM_msgDataProc_c::stringShift(fopMsgM_msgDataProc_c *this)

{
  byte bVar3;
  uint uVar1;
  int iVar2;
  int iVar4;
  int iVar5;
  char acStack40 [16];
  undefined4 local_18;
  uint uStack20;
  longlong local_10;
  
  bVar3 = *(byte *)(*(int *)&this->field_0xc + 0x10);
  if ((bVar3 != 3) && (*(char *)(*(int *)&this->field_0xc + 0xc) != '\r')) {
    bVar3 = 1;
  }
  if (bVar3 == 2) {
    iVar4 = 0;
    iVar5 = 4;
    do {
      iVar2 = (int)&this->vtbl + iVar4;
      *(int *)(iVar2 + 0xf8) = (this->field_0x128 - *(int *)(iVar2 + 0xd8)) + -1;
      iVar4 = iVar4 + 4;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  else {
    if (bVar3 < 2) {
      if (bVar3 != 0) {
        iVar4 = 0;
        iVar5 = 4;
        do {
          iVar2 = (int)&this->vtbl + iVar4;
          if (*(int *)(iVar2 + 0x108) == 0) {
            *(undefined4 *)(iVar2 + 0xf8) = 0;
          }
          else {
            *(int *)(iVar2 + 0xf8) = *(int *)(iVar2 + 0x108);
          }
          iVar4 = iVar4 + 4;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
        goto LAB_800311f0;
      }
    }
    else {
      if (3 < bVar3) goto LAB_800311f0;
    }
    iVar4 = 0;
    iVar5 = 4;
    do {
      iVar2 = (int)&this->vtbl + iVar4;
      if (*(int *)(iVar2 + 0x108) == 0) {
        uVar1 = this->field_0x12c - *(int *)(iVar2 + 0xd8);
        *(uint *)(iVar2 + 0xf8) = ((int)uVar1 >> 1) + (uint)((int)uVar1 < 0 && (uVar1 & 1) != 0);
      }
      else {
        *(int *)(iVar2 + 0xf8) = *(int *)(iVar2 + 0x108);
      }
      iVar4 = iVar4 + 4;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
LAB_800311f0:
  uStack20 = *(uint *)&this->field_0xf8 ^ 0x80000000;
  local_18 = 0x43300000;
  this->field_0x20 = (float)((double)CONCAT44(0x43300000,uStack20) - f_op_msg_mng::_4895);
  this->field_0x150 = 0;
  local_10 = (longlong)(int)this->field_0x20;
  MSL_C.PPCEABI.bare.H::sprintf(acStack40,"\x1bCR[%d]",(int)this->field_0x20);
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x60,acStack40);
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x68,acStack40);
  iVar4 = 0;
  iVar5 = 4;
  do {
    iVar2 = *(int *)(&this->field_0xe8 + iVar4);
    if ((int)this->field_0x21c < iVar2) {
      this->field_0x21c = iVar2;
    }
    iVar4 = iVar4 + 4;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  if (*(char *)(*(int *)&this->field_0xc + 0xc) == '\x05') {
    *(undefined *)&this->field_0x299 = 1;
  }
  return;
}


/* __thiscall fopMsgM_msgDataProc_c::iconSelect(int,
                                                unsigned char) */

void __thiscall
fopMsgM_msgDataProc_c::iconSelect(fopMsgM_msgDataProc_c *this,int param_1,uchar param_2)

{
  double dVar1;
  char acStack40 [16];
  double local_18;
  undefined4 local_10;
  uint uStack12;
  
  if (*(byte *)&this->field_0x280 < 0xf) {
    *(uchar *)(&this->field_0x281 + (uint)*(byte *)&this->field_0x280) = param_2;
    *(int *)(&this->field_0x168 + (uint)*(byte *)&this->field_0x280 * 4) = (int)this->field_0x20;
    *(undefined4 *)(&this->field_0x1a4 + (uint)*(byte *)&this->field_0x280 * 4) = this->field_0x130;
    *(int *)(&this->field_0x1e0 + (uint)*(byte *)&this->field_0x280 * 4) = param_1;
    *(undefined4 *)(&this->field_0x220 + (uint)*(byte *)&this->field_0x280 * 4) = this->field_0x25c;
    *(char *)&this->field_0x280 = *(char *)&this->field_0x280 + '\x01';
  }
  if (param_2 != '\x16') {
    this->field_0x150 = this->field_0x150 + 1;
    dVar1 = f_op_msg_mng::_4895;
    local_18 = (double)CONCAT44(0x43300000,param_1 ^ 0x80000000);
    this->field_0x14 = this->field_0x14 + (float)(local_18 - f_op_msg_mng::_4895);
    uStack12 = *(uint *)(&this->field_0xf8 + this->field_0x130 * 4) ^ 0x80000000;
    local_10 = 0x43300000;
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,uStack12) - dVar1) + this->field_0x14;
    MSL_C.PPCEABI.bare.H::sprintf(acStack40,"\x1bCR[%d]",param_1);
    MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x60,acStack40);
    MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x68,acStack40);
    this->field_0x118 =
         this->field_0x118 + (int)*(char *)(*(int *)&this->field_0x3c + this->field_0x118 + 1);
  }
  return;
}


/* __thiscall fopMsgM_msgDataProc_c::iconIdxRefresh(void) */

void __thiscall fopMsgM_msgDataProc_c::iconIdxRefresh(fopMsgM_msgDataProc_c *this)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 0xf;
  do {
    *(undefined *)(&this->field_0x281 + iVar1) = 0xff;
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined *)&this->field_0x280 = 0;
  return;
}


namespace f_op_msg_mng {

/* WARNING: Could not reconcile some variable overlaps */
/* __stdcall fopMsgM_arrowAnime(J2DPicture *,
                                short *) */

void fopMsgM_arrowAnime(int param_1,short *param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined uVar4;
  double dVar5;
  undefined uStack134;
  undefined uStack130;
  undefined uStack129;
  undefined local_7c;
  undefined uStack123;
  undefined local_74;
  undefined uStack115;
  uint local_70;
  undefined4 local_6c;
  double local_68;
  double local_58;
  double local_50;
  double local_40;
  double local_38;
  double local_28;
  double local_20;
  double local_10;
  
  iVar3 = (int)*param_2;
  if (iVar3 < 0x16) {
    dVar5 = (double)fopMsgM_valueIncrease(0x16,iVar3,2);
    local_68 = (double)CONCAT44(0x43300000,(uint)color1_6529);
    iVar3 = (int)((float)(local_68 - _5509) +
                 (float)(dVar5 * (double)(float)((double)CONCAT44(0x43300000,
                                                                  (uint)color2_6530 -
                                                                  (uint)color1_6529 ^ 0x80000000) -
                                                _4895)));
    local_50 = (double)CONCAT44(0x43300000,(uint)UNK_803f8111);
    uVar1 = (uint)((float)(local_50 - _5509) +
                  (float)(dVar5 * (double)(float)((double)CONCAT44(0x43300000,
                                                                   (uint)UNK_803f8115 -
                                                                   (uint)UNK_803f8111 ^ 0x80000000)
                                                 - _4895)));
    local_6c._1_3_ = CONCAT12((char)uVar1,0xff);
    local_38 = (double)CONCAT44(0x43300000,(uint)UNK_803f8112);
    uVar2 = (uint)((float)(local_38 - _5509) +
                  (float)(dVar5 * (double)(float)((double)CONCAT44(0x43300000,
                                                                   (uint)UNK_803f8116 -
                                                                   (uint)UNK_803f8112 ^ 0x80000000)
                                                 - _4895)));
    local_70 = iVar3 << 0x18 | (uVar1 & 0xff) << 0x10 | (uVar2 & 0xff) << 8;
    local_6c._2_2_ = (ushort)(byte)uVar2 << 8 | 0xff;
    local_6c = iVar3 << 0x18 | local_6c._1_3_ & 0xffff0000 | (uint)local_6c._2_2_;
    local_20 = (double)CONCAT44(0x43300000,(uint)DAT_803e6b70);
    uVar4 = (undefined)
            (int)((float)(local_20 - _5509) +
                 (float)(dVar5 * (double)(float)((double)CONCAT44(0x43300000,
                                                                  (uint)DAT_803e6b74 -
                                                                  (uint)DAT_803e6b70 ^ 0x80000000) -
                                                _4895)));
  }
  else {
    dVar5 = (double)fopMsgM_valueIncrease(0x16,iVar3 + -0x16,2);
    local_10 = (double)CONCAT44(0x43300000,(uint)color2_6530);
    iVar3 = (int)((float)(local_10 - _5509) +
                 (float)(dVar5 * (double)(float)((double)CONCAT44(0x43300000,
                                                                  (uint)color1_6529 -
                                                                  (uint)color2_6530 ^ 0x80000000) -
                                                _4895)));
    local_28 = (double)CONCAT44(0x43300000,(uint)UNK_803f8115);
    uVar1 = (uint)((float)(local_28 - _5509) +
                  (float)(dVar5 * (double)(float)((double)CONCAT44(0x43300000,
                                                                   (uint)UNK_803f8111 -
                                                                   (uint)UNK_803f8115 ^ 0x80000000)
                                                 - _4895)));
    local_6c._1_3_ = CONCAT12((char)uVar1,0xff);
    local_40 = (double)CONCAT44(0x43300000,(uint)UNK_803f8116);
    uVar2 = (uint)((float)(local_40 - _5509) +
                  (float)(dVar5 * (double)(float)((double)CONCAT44(0x43300000,
                                                                   (uint)UNK_803f8112 -
                                                                   (uint)UNK_803f8116 ^ 0x80000000)
                                                 - _4895)));
    local_70 = iVar3 << 0x18 | (uVar1 & 0xff) << 0x10 | (uVar2 & 0xff) << 8;
    local_6c._2_2_ = (ushort)(byte)uVar2 << 8 | 0xff;
    local_6c = iVar3 << 0x18 | local_6c._1_3_ & 0xffff0000 | (uint)local_6c._2_2_;
    local_58 = (double)CONCAT44(0x43300000,(uint)DAT_803e6b74);
    uVar4 = (undefined)
            (int)((float)(local_58 - _5509) +
                 (float)(dVar5 * (double)(float)((double)CONCAT44(0x43300000,
                                                                  (uint)DAT_803e6b70 -
                                                                  (uint)DAT_803e6b74 ^ 0x80000000) -
                                                _4895)));
  }
  *param_2 = *param_2 + 1;
  if (0x2c < *param_2) {
    *param_2 = 0;
  }
  uStack130 = (undefined)(local_6c >> 8);
  uStack129 = (undefined)local_6c;
  local_74 = (undefined)(local_6c >> 0x18);
  *(undefined *)(param_1 + 0x104) = local_74;
  uStack115 = (undefined)(local_6c >> 0x10);
  *(undefined *)(param_1 + 0x105) = uStack115;
  *(undefined *)(param_1 + 0x106) = uStack130;
  *(undefined *)(param_1 + 0x107) = uStack129;
  uStack134 = (undefined)(local_70 >> 8);
  local_7c = (undefined)(local_70 >> 0x18);
  *(undefined *)(param_1 + 0x108) = local_7c;
  uStack123 = (undefined)(local_70 >> 0x10);
  *(undefined *)(param_1 + 0x109) = uStack123;
  *(undefined *)(param_1 + 0x10a) = uStack134;
  *(undefined *)(param_1 + 0x10b) = 0;
  *(undefined *)(param_1 + 0xac) = uVar4;
  return;
}

}

/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall fopMsgM_msgDataProc_c::selectCheck2(J2DPane *,
                                                  int,
                                                  int,
                                                  int) */

byte __thiscall
fopMsgM_msgDataProc_c::selectCheck2
          (fopMsgM_msgDataProc_c *this,J2DPane *param_1,int param_2,int param_3,int param_4)

{
  float fVar1;
  double dVar2;
  uint uVar3;
  
  fVar1 = f_op_msg_mng::0_5;
  this->field_0x264 = ((param_1->mPosBR).x - (param_1->mPosTL).x) * f_op_msg_mng::0_5;
  this->field_0x268 = ((param_1->mPosBR).y - (param_1->mPosTL).y) * fVar1;
  dVar2 = f_op_msg_mng::_4895;
  this->field_0x278 =
       (float)((double)CONCAT44(0x43300000,(int)DAT_803e6bb4 ^ 0x80000000) - f_op_msg_mng::_4895);
  this->field_0x274 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e6bb4 ^ 0x80000000) - dVar2);
  uVar3 = this->field_0x164;
  uVar3 = uVar3 - 1 & (int)(-uVar3 & ~uVar3) >> 0x1f;
  this->field_0x164 = uVar3;
  if (uVar3 == 0) {
    if (m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mStickMainPosY <= f_op_msg_mng::_6617) {
      if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mStickMainPosY < f_op_msg_mng::_6619) &&
         (this->field_0x27d == 0)) {
        this->field_0x27d = 1;
        this->field_0x164 = 10;
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,0x83d,(cXyz *)0x0,0,0,f_op_msg_mng::1_0,f_op_msg_mng::1_0,
                   f_op_msg_mng::_6618,f_op_msg_mng::_6618,0);
      }
    }
    else {
      if (this->field_0x27d == 1) {
        this->field_0x27d = 0;
        this->field_0x164 = 10;
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,0x83d,(cXyz *)0x0,0,0,f_op_msg_mng::1_0,f_op_msg_mng::1_0,
                   f_op_msg_mng::_6618,f_op_msg_mng::_6618,0);
      }
    }
  }
  dVar2 = f_op_msg_mng::_4895;
  this->field_0x26c =
       (float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - f_op_msg_mng::_4895);
  this->field_0x270 =
       (float)((double)CONCAT44(0x43300000,param_3 + (uint)this->field_0x27d * param_4 ^ 0x80000000)
              - dVar2);
  return this->field_0x27d;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall fopMsgM_msgDataProc_c::selectCheck3(J2DPane *,
                                                  int,
                                                  int,
                                                  int) */

byte __thiscall
fopMsgM_msgDataProc_c::selectCheck3
          (fopMsgM_msgDataProc_c *this,J2DPane *param_1,int param_2,int param_3,int param_4)

{
  float fVar1;
  double dVar2;
  uint uVar3;
  
  fVar1 = f_op_msg_mng::0_5;
  this->field_0x264 = ((param_1->mPosBR).x - (param_1->mPosTL).x) * f_op_msg_mng::0_5;
  this->field_0x268 = ((param_1->mPosBR).y - (param_1->mPosTL).y) * fVar1;
  dVar2 = f_op_msg_mng::_4895;
  this->field_0x278 =
       (float)((double)CONCAT44(0x43300000,(int)DAT_803e6bb4 ^ 0x80000000) - f_op_msg_mng::_4895);
  this->field_0x274 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e6bb4 ^ 0x80000000) - dVar2);
  uVar3 = this->field_0x164;
  uVar3 = uVar3 - 1 & (int)(-uVar3 & ~uVar3) >> 0x1f;
  this->field_0x164 = uVar3;
  if (uVar3 == 0) {
    if (m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mStickMainPosY <= f_op_msg_mng::_6617) {
      if (m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mStickMainPosY < f_op_msg_mng::_6619) {
        if (this->field_0x27d == 0) {
          this->field_0x27d = 1;
          this->field_0x164 = 10;
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x83d,(cXyz *)0x0,0,0,f_op_msg_mng::1_0,
                     f_op_msg_mng::1_0,f_op_msg_mng::_6618,f_op_msg_mng::_6618,0);
        }
        else {
          if (this->field_0x27d == 1) {
            this->field_0x27d = 2;
            this->field_0x164 = 10;
            JAIZelBasic::seStart
                      (JAIZelBasic::zel_basic,0x83d,(cXyz *)0x0,0,0,f_op_msg_mng::1_0,
                       f_op_msg_mng::1_0,f_op_msg_mng::_6618,f_op_msg_mng::_6618,0);
          }
        }
      }
    }
    else {
      if (this->field_0x27d == 1) {
        this->field_0x27d = 0;
        this->field_0x164 = 10;
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,0x83d,(cXyz *)0x0,0,0,f_op_msg_mng::1_0,f_op_msg_mng::1_0,
                   f_op_msg_mng::_6618,f_op_msg_mng::_6618,0);
      }
      else {
        if (this->field_0x27d == 2) {
          this->field_0x27d = 1;
          this->field_0x164 = 10;
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x83d,(cXyz *)0x0,0,0,f_op_msg_mng::1_0,
                     f_op_msg_mng::1_0,f_op_msg_mng::_6618,f_op_msg_mng::_6618,0);
        }
      }
    }
  }
  dVar2 = f_op_msg_mng::_4895;
  this->field_0x26c =
       (float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - f_op_msg_mng::_4895);
  this->field_0x270 =
       (float)((double)CONCAT44(0x43300000,param_3 + (uint)this->field_0x27d * param_4 ^ 0x80000000)
              - dVar2);
  return this->field_0x27d;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall fopMsgM_msgDataProc_c::selectCheckYoko(J2DPane *,
                                                     int,
                                                     int,
                                                     int) */

byte __thiscall
fopMsgM_msgDataProc_c::selectCheckYoko
          (fopMsgM_msgDataProc_c *this,J2DPane *param_1,int param_2,int param_3,int param_4)

{
  float fVar1;
  double dVar2;
  uint uVar3;
  
  fVar1 = f_op_msg_mng::0_5;
  this->field_0x264 = ((param_1->mPosBR).x - (param_1->mPosTL).x) * f_op_msg_mng::0_5;
  this->field_0x268 = ((param_1->mPosBR).y - (param_1->mPosTL).y) * fVar1;
  dVar2 = f_op_msg_mng::_4895;
  this->field_0x278 =
       (float)((double)CONCAT44(0x43300000,(int)DAT_803e6bb4 ^ 0x80000000) - f_op_msg_mng::_4895);
  this->field_0x274 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e6bb4 ^ 0x80000000) - dVar2);
  uVar3 = this->field_0x164;
  uVar3 = uVar3 - 1 & (int)(-uVar3 & ~uVar3) >> 0x1f;
  this->field_0x164 = uVar3;
  if (uVar3 == 0) {
    if (f_op_msg_mng::_6619 <= m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mStickMainPosX) {
      if ((f_op_msg_mng::_6617 < m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mStickMainPosX) &&
         (this->field_0x27d == 0)) {
        this->field_0x27d = 1;
        this->field_0x164 = 10;
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,0x83d,(cXyz *)0x0,0,0,f_op_msg_mng::1_0,f_op_msg_mng::1_0,
                   f_op_msg_mng::_6618,f_op_msg_mng::_6618,0);
      }
    }
    else {
      if (this->field_0x27d == 1) {
        this->field_0x27d = 0;
        this->field_0x164 = 10;
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,0x83d,(cXyz *)0x0,0,0,f_op_msg_mng::1_0,f_op_msg_mng::1_0,
                   f_op_msg_mng::_6618,f_op_msg_mng::_6618,0);
      }
    }
  }
  dVar2 = f_op_msg_mng::_4895;
  this->field_0x26c =
       (float)((double)CONCAT44(0x43300000,param_2 + (uint)this->field_0x27d * param_4 ^ 0x80000000)
              - f_op_msg_mng::_4895);
  this->field_0x270 = (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - dVar2);
  return this->field_0x27d;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall fopMsgM_msgDataProc_c::inputNumber(int) */

byte __thiscall fopMsgM_msgDataProc_c::inputNumber(fopMsgM_msgDataProc_c *this,int param_1)

{
  byte bVar1;
  bool bVar2;
  char cVar4;
  ushort uVar3;
  ushort uVar5;
  
  uVar5 = d_com_inf_game::g_dComIfG_gameInfo.field_0x5bba;
  bVar2 = false;
  STControl::setWaitParm(&f_op_msg_mng::stick,5,2,3,2,f_op_msg_mng::0_9,f_op_msg_mng::0_5,0,0x2000);
  STControl::checkTrigger(&f_op_msg_mng::stick);
  cVar4 = STControl::checkRightTrigger(&f_op_msg_mng::stick);
  if (cVar4 == '\0') {
    cVar4 = STControl::checkLeftTrigger(&f_op_msg_mng::stick);
    if ((cVar4 != '\0') && ((int)(uint)this->field_0x27d < param_1 + -1)) {
      this->field_0x27d = this->field_0x27d + 1;
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x8e1,(cXyz *)0x0,0,0,f_op_msg_mng::1_0,f_op_msg_mng::1_0,
                 f_op_msg_mng::_6618,f_op_msg_mng::_6618,0);
    }
  }
  else {
    if (this->field_0x27d != 0) {
      this->field_0x27d = this->field_0x27d - 1;
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x8e1,(cXyz *)0x0,0,0,f_op_msg_mng::1_0,f_op_msg_mng::1_0,
                 f_op_msg_mng::_6618,f_op_msg_mng::_6618,0);
    }
  }
  cVar4 = STControl::checkUpTrigger(&f_op_msg_mng::stick);
  if (cVar4 == '\0') {
    cVar4 = STControl::checkDownTrigger(&f_op_msg_mng::stick);
    if (cVar4 != '\0') {
      bVar1 = this->field_0x27d;
      if (bVar1 == 0) {
        if (0 < (short)uVar5) {
          bVar2 = true;
          uVar5 = uVar5 - 1;
        }
      }
      else {
        if (bVar1 == 1) {
          if (0 < (short)uVar5) {
            uVar5 = uVar5 - 10;
            if ((short)uVar5 < 0) {
              uVar5 = 0;
            }
            bVar2 = true;
          }
        }
        else {
          if ((bVar1 == 2) && (0 < (short)uVar5)) {
            uVar5 = uVar5 - 100;
            if ((short)uVar5 < 0) {
              uVar5 = 0;
            }
            bVar2 = true;
          }
        }
      }
    }
  }
  else {
    bVar1 = this->field_0x27d;
    if (bVar1 == 0) {
      if ((short)uVar5 < 999) {
        bVar2 = true;
        uVar5 = uVar5 + 1;
      }
    }
    else {
      if (bVar1 == 1) {
        if ((short)uVar5 < 999) {
          uVar5 = uVar5 + 10;
          if (999 < (short)uVar5) {
            uVar5 = 99;
          }
          bVar2 = true;
        }
      }
      else {
        if ((bVar1 == 2) && ((short)uVar5 < 999)) {
          uVar5 = uVar5 + 100;
          if (999 < (short)uVar5) {
            uVar5 = 999;
          }
          bVar2 = true;
        }
      }
    }
  }
  uVar3 = uVar5;
  if (param_1 == 2) {
    uVar3 = (ushort)daNpc_Bs1_c::m_tag_buy_item_max;
    if ((short)uVar5 <= (short)uVar3) {
      if ((short)uVar5 < 1) {
        uVar3 = 1;
      }
      else {
        uVar3 = uVar5;
        if (bVar2) {
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x8e2,(cXyz *)0x0,0,0,f_op_msg_mng::1_0,
                     f_op_msg_mng::1_0,f_op_msg_mng::_6618,f_op_msg_mng::_6618,0);
        }
      }
    }
  }
  else {
    if (bVar2) {
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x8e2,(cXyz *)0x0,0,0,f_op_msg_mng::1_0,f_op_msg_mng::1_0,
                 f_op_msg_mng::_6618,f_op_msg_mng::_6618,0);
    }
  }
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5bba = uVar3;
  return this->field_0x27d;
}


/* WARNING: Removing unreachable block (ram,0x800321a4) */
/* WARNING: Removing unreachable block (ram,0x80032194) */
/* WARNING: Removing unreachable block (ram,0x8003219c) */
/* WARNING: Removing unreachable block (ram,0x800321ac) */
/* __thiscall fopMsgM_msgDataProc_c::selectArrow(J2DPicture *,
                                                 float,
                                                 float,
                                                 float,
                                                 float) */

void __thiscall
fopMsgM_msgDataProc_c::selectArrow
          (fopMsgM_msgDataProc_c *this,J2DPicture *param_1,float param_2,float param_3,float param_4
          ,float param_5)

{
  undefined4 uVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  undefined8 in_f28;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar5 = (double)param_4;
  dVar6 = (double)param_5;
  dVar4 = (double)param_3;
  dVar2 = (double)param_2;
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  dVar3 = (double)f_op_msg_mng::0_5;
  (param_1->parent).mBasePosition.x = (float)(dVar5 * dVar3);
  (param_1->parent).mBasePosition.y = (float)(dVar6 * dVar3);
  (param_1->parent).mRotationAxis = 'z';
  (param_1->parent).mRotation = f_op_msg_mng::_5546;
  (*(code *)((param_1->parent).vtbl)->calcMtx)(param_1);
  f_op_msg_mng::fopMsgM_arrowAnime(param_1,&this->field_0x260);
  J2DPicture::draw(param_1,(float)dVar2,(float)dVar4,(float)dVar5,(float)dVar6,false,false,false);
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  __psq_l0(auStack24,uVar1);
  __psq_l1(auStack24,uVar1);
  __psq_l0(auStack40,uVar1);
  __psq_l1(auStack40,uVar1);
  __psq_l0(auStack56,uVar1);
  __psq_l1(auStack56,uVar1);
  return;
}


/* WARNING: Removing unreachable block (ram,0x80032260) */
/* WARNING: Removing unreachable block (ram,0x80032268) */
/* __thiscall fopMsgM_msgDataProc_c::selectArrow(J2DPicture *,
                                                 float,
                                                 float) */

void __thiscall
fopMsgM_msgDataProc_c::selectArrow
          (fopMsgM_msgDataProc_c *this,J2DPicture *param_1,float param_2,float param_3)

{
  undefined4 uVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar4 = (double)param_3;
  dVar2 = (double)param_2;
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  dVar3 = (double)f_op_msg_mng::0_5;
  (param_1->parent).mBasePosition.x = (float)(dVar2 * dVar3);
  (param_1->parent).mBasePosition.y = (float)(dVar4 * dVar3);
  (param_1->parent).mRotationAxis = 'z';
  (param_1->parent).mRotation = f_op_msg_mng::_5546;
  (*(code *)((param_1->parent).vtbl)->calcMtx)(param_1);
  (*(code *)((param_1->parent).vtbl)->resize)(dVar2,dVar4,param_1);
  f_op_msg_mng::fopMsgM_arrowAnime(param_1,&this->field_0x260);
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  __psq_l0(auStack24,uVar1);
  __psq_l1(auStack24,uVar1);
  return;
}


/* __thiscall fopMsgM_msgDataProc_c::colorAnime(J2DPicture *) */

void __thiscall fopMsgM_msgDataProc_c::colorAnime(fopMsgM_msgDataProc_c *this,J2DPicture *param_1)

{
  f_op_msg_mng::fopMsgM_arrowAnime(param_1,&this->field_0x260);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x80034f1c) */
/* __thiscall fopMsgM_msgDataProc_c::stringSet(void) */

void __thiscall fopMsgM_msgDataProc_c::stringSet(fopMsgM_msgDataProc_c *this)

{
  uint uVar1;
  float fVar2;
  byte bVar3;
  float fVar4;
  short sVar5;
  bool bVar6;
  int iVar7;
  undefined4 uVar8;
  char cVar13;
  byte *pbVar9;
  char *pcVar10;
  char cVar14;
  size_t sVar11;
  ulong uVar12;
  int iVar15;
  uint uVar16;
  undefined4 uVar17;
  undefined8 in_f31;
  double dVar18;
  double dVar19;
  char local_140;
  undefined local_13f;
  undefined local_13e;
  char acStack316 [16];
  char acStack300 [16];
  char acStack284 [16];
  char acStack268 [16];
  char acStack252 [16];
  char acStack236 [16];
  char acStack220 [15];
  char acStack205 [21];
  char acStack184 [28];
  char acStack156 [28];
  char acStack128 [32];
  char acStack96 [32];
  undefined4 local_40;
  uint uStack60;
  double local_38;
  double local_30;
  undefined auStack8 [8];
  
  uVar17 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  cVar13 = (char)DAT_803e6bb0;
  *(undefined4 *)&this->field_0x60 = *(undefined4 *)&this->field_0x40;
  *(undefined4 *)&this->field_0x64 = *(undefined4 *)&this->field_0x44;
  *(undefined4 *)&this->field_0x68 = *(undefined4 *)&this->field_0x48;
  *(undefined4 *)&this->field_0x6c = *(undefined4 *)&this->field_0x4c;
  *(undefined *)&this->field_0x27c = 6;
  if (*(char *)(*(int *)&this->field_0x3c + this->field_0x118) == '\0') {
    if (*(char *)&this->field_0x27e != '\0') {
      *(undefined *)&this->field_0x27e = 0;
      *(undefined *)(*(int *)&this->field_0x60 + this->field_0x2c) = 0;
      *(undefined *)(*(int *)&this->field_0x68 + this->field_0x30) = 0;
      MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x60,(char *)&this->field_0xd4);
      MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x68,(char *)&this->field_0xd4);
    }
    if (*(char *)&this->field_0x27f != '\0') {
      *(undefined *)&this->field_0x27f = 0;
      *(undefined *)(*(int *)&this->field_0x64 + this->field_0x34) = 0;
      *(undefined *)(*(int *)&this->field_0x6c + this->field_0x38) = 0;
      MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x64,(char *)&this->field_0x70);
      MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x6c,(char *)&this->field_0x70);
    }
    cVar13 = *(char *)&this->field_0x27c;
    if ((((cVar13 != '\b') && (cVar13 != '\t')) && (cVar13 != '\x14')) && (cVar13 != '\x15')) {
      cVar13 = *(char *)(*(int *)&this->field_0xc + 0xc);
      if (((((cVar13 != '\x02') && (cVar13 != '\x06')) &&
           ((cVar13 != '\a' && ((cVar13 != '\v' && (cVar13 != '\x05')))))) && (cVar13 != '\r')) &&
         (cVar13 != '\t')) {
        iVar7 = f_op_msg_mng::dComIfGp_roomControl_getStayNo();
        if (iVar7 == 0) {
          f_op_msg_mng::mDoAud_messageSePlay(0,0,0);
        }
        else {
          f_op_msg_mng::dComIfGp_roomControl_getStayNo();
          uVar8 = d_com_inf_game::dComIfGp_getReverb();
          f_op_msg_mng::mDoAud_messageSePlay(0,0,uVar8);
        }
      }
      cVar13 = f_op_msg_mng::fopMsgM_nextMsgFlagCheck();
      if (cVar13 == '\0') {
        cVar13 = getAutoSendFlag(this);
        if ((cVar13 == '\0') && (cVar13 = getHandSendFlag(this), cVar13 == '\0')) {
          *(undefined *)&this->field_0x27c = 0xe;
        }
        else {
          *(undefined *)&this->field_0x27c = 10;
        }
      }
      else {
        if (*(short *)(*(int *)&this->field_0xc + 8) == 0) {
          *(undefined *)&this->field_0x27c = 0x10;
        }
        else {
          f_op_msg_mng::fopMsgM_messageSet();
          *(undefined *)&this->field_0x27c = 0xf;
        }
      }
    }
  }
  else {
LAB_80034d34:
    while( true ) {
      while( true ) {
        if (*(char *)(*(int *)&this->field_0x3c + this->field_0x118) == '\0') {
          if ((((*(char *)&this->field_0x299 != '\0') || (*(char *)&this->field_0x29a != '\0')) ||
              (*(char *)&this->field_0x297 != '\0')) ||
             ((*(char *)&this->field_0x298 != '\0' || (*(char *)&this->field_0x294 != '\0')))) {
            if (*(char *)&this->field_0x27e != '\0') {
              *(undefined *)&this->field_0x27e = 0;
              *(undefined *)(*(int *)&this->field_0x60 + this->field_0x2c) = 0;
              *(undefined *)(*(int *)&this->field_0x68 + this->field_0x30) = 0;
              MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x60,(char *)&this->field_0xd4);
              MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x68,(char *)&this->field_0xd4);
            }
            if (*(char *)&this->field_0x27f != '\0') {
              *(undefined *)&this->field_0x27f = 0;
              *(undefined *)(*(int *)&this->field_0x64 + this->field_0x34) = 0;
              *(undefined *)(*(int *)&this->field_0x6c + this->field_0x38) = 0;
              MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x64,(char *)&this->field_0x70);
              MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x6c,(char *)&this->field_0x70);
            }
            cVar13 = *(char *)&this->field_0x27c;
            if (((cVar13 != '\b') && (cVar13 != '\t')) && ((cVar13 != '\x14' && (cVar13 != '\x15')))
               ) {
              cVar13 = *(char *)(*(int *)&this->field_0xc + 0xc);
              if (((((cVar13 != '\x02') && (cVar13 != '\x06')) && (cVar13 != '\a')) &&
                  ((cVar13 != '\v' && (cVar13 != '\x05')))) &&
                 ((cVar13 != '\r' && (cVar13 != '\t')))) {
                iVar7 = f_op_msg_mng::dComIfGp_roomControl_getStayNo();
                if (iVar7 == 0) {
                  f_op_msg_mng::mDoAud_messageSePlay(0,0,0);
                }
                else {
                  f_op_msg_mng::dComIfGp_roomControl_getStayNo();
                  uVar8 = d_com_inf_game::dComIfGp_getReverb();
                  f_op_msg_mng::mDoAud_messageSePlay(0,0,uVar8);
                }
              }
              cVar13 = f_op_msg_mng::fopMsgM_nextMsgFlagCheck();
              if (cVar13 == '\0') {
                cVar13 = getAutoSendFlag(this);
                if ((cVar13 == '\0') && (cVar13 = getHandSendFlag(this), cVar13 == '\0')) {
                  *(undefined *)&this->field_0x27c = 0xe;
                }
                else {
                  *(undefined *)&this->field_0x27c = 10;
                }
              }
              else {
                if (*(short *)(*(int *)&this->field_0xc + 8) == 0) {
                  *(undefined *)&this->field_0x27c = 0x10;
                }
                else {
                  f_op_msg_mng::fopMsgM_messageSet();
                  *(undefined *)&this->field_0x27c = 0xf;
                }
              }
            }
          }
          goto LAB_80034f1c;
        }
        if (*(char *)&this->field_0x27e != '\0') {
          *(undefined *)&this->field_0x27e = 0;
          *(undefined *)(*(int *)&this->field_0x60 + this->field_0x2c) = 0;
          *(undefined *)(*(int *)&this->field_0x68 + this->field_0x30) = 0;
          MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x60,(char *)&this->field_0xd4);
          MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x68,(char *)&this->field_0xd4);
        }
        if (*(char *)&this->field_0x27f != '\0') {
          *(undefined *)&this->field_0x27f = 0;
          *(undefined *)(*(int *)&this->field_0x64 + this->field_0x34) = 0;
          *(undefined *)(*(int *)&this->field_0x6c + this->field_0x38) = 0;
          MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x64,(char *)&this->field_0x70);
          MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x6c,(char *)&this->field_0x70);
        }
        iVar7 = this->field_0x118;
        pbVar9 = (byte *)(*(int *)&this->field_0x3c + iVar7);
        bVar3 = *pbVar9;
        if (bVar3 != 0x1a) break;
        bVar3 = pbVar9[2];
        if (((bVar3 == 0xff) && (pbVar9[3] == 0)) && (pbVar9[4] == 0)) {
          sVar5 = *(short *)(*(int *)&this->field_0xc + 4);
          if ((((((sVar5 == 0x42) || (sVar5 == 0x43)) || (sVar5 == 0x44)) ||
               (((sVar5 == 0x45 || (sVar5 == 0x46)) ||
                ((sVar5 == 0x47 || ((sVar5 == 0x48 || (sVar5 == 0x49)))))))) || (sVar5 == 0x4a)) ||
             (sVar5 == 0x4b)) {
            this->field_0x25c =
                 *(undefined4 *)(&f_op_msg_mng::colorTable_6856 + (char)pbVar9[5] * 4);
            MSL_C.PPCEABI.bare.H::sprintf(acStack96,"\x1bCC[%08x]\x1bGM[0]",this->field_0x25c);
            MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x60,acStack96);
          }
          else {
            bVar3 = pbVar9[5];
            if ((-1 < (char)bVar3) && ((char)bVar3 < 9)) {
              cVar14 = *(char *)(*(int *)&this->field_0xc + 0xc);
              if ((cVar14 == '\x02') || ((cVar14 == '\x06' || (cVar14 == '\a')))) {
                this->field_0x25c =
                     *(undefined4 *)(&f_op_msg_mng::colorTable_6865 + (char)bVar3 * 4);
                MSL_C.PPCEABI.bare.H::sprintf
                          (acStack128,"\x1bCC[%08x]\x1bGC[%08x]",
                           this->field_0x25c | (uint)*(byte *)&this->field_0x290,
                           this->field_0x25c | (uint)*(byte *)&this->field_0x291);
                MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x60,acStack128);
              }
              else {
                if (cVar14 == '\v') {
                  this->field_0x25c =
                       *(undefined4 *)(&f_op_msg_mng::colorTable_6869 + (char)bVar3 * 4);
                  MSL_C.PPCEABI.bare.H::sprintf
                            (acStack156,"\x1bCC[%08x]\x1bGM[0]",this->field_0x25c);
                  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x60,acStack156);
                }
                else {
                  uVar8 = f_op_msg_mng::fopMsgM_getColorTable();
                  this->field_0x25c = uVar8;
                  MSL_C.PPCEABI.bare.H::sprintf
                            (acStack184,"\x1bCC[%08x]\x1bGM[0]",this->field_0x25c);
                  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x60,acStack184);
                }
              }
            }
          }
          this->field_0x118 =
               this->field_0x118 + (int)*(char *)(*(int *)&this->field_0x3c + this->field_0x118 + 1)
          ;
        }
        else {
          if (((bVar3 == 0xff) && (pbVar9[3] == 0)) && (pbVar9[4] == 1)) {
            uStack60 = *(ushort *)(pbVar9 + 5) ^ 0x80000000;
            local_40 = 0x43300000;
            dVar18 = (double)(f_op_msg_mng::_6433 *
                             (float)((double)CONCAT44(0x43300000,uStack60) - f_op_msg_mng::_4895));
            uVar8 = this->field_0x148;
            local_38 = (double)CONCAT44(0x43300000,this->field_0x144 ^ 0x80000000);
            iVar7 = (int)(f_op_msg_mng::0_5 +
                         (float)((double)(float)(local_38 - f_op_msg_mng::_4895) * dVar18));
            local_30 = (double)(longlong)iVar7;
            this->field_0x148 = iVar7;
            if (this->field_0x134 == 0) {
              f_op_msg_mng::fopMsgM_setFontsizeCenter
                        (*(undefined4 *)&this->field_0x60,*(undefined4 *)&this->field_0x68,
                         *(undefined4 *)&this->field_0x64,*(undefined4 *)&this->field_0x6c,uVar8,
                         this->field_0x148);
              if (((double)f_op_msg_mng::1_0 < dVar18) && (*(char *)&this->field_0x29d == '\0')) {
                *(undefined *)&this->field_0x29d = 1;
              }
            }
            else {
              if (((double)f_op_msg_mng::1_0 < dVar18) && (*(char *)&this->field_0x29d == '\0')) {
                MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x60,"\n");
                MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x64,"\n");
                MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x68,"\n");
                MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x6c,"\n");
                local_30 = (double)(longlong)(int)this->field_0x20;
                MSL_C.PPCEABI.bare.H::sprintf(acStack220,"\x1bCR[%d]",(int)this->field_0x20);
                MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x60,acStack220);
                MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x68,acStack220);
                *(undefined *)&this->field_0x29d = 1;
              }
              f_op_msg_mng::fopMsgM_setFontsizeCenter2
                        (*(undefined4 *)&this->field_0x60,*(undefined4 *)&this->field_0x68,
                         *(undefined4 *)&this->field_0x64,*(undefined4 *)&this->field_0x6c,uVar8,
                         this->field_0x148,this->field_0x144,this->field_0x120);
            }
            this->field_0x118 =
                 this->field_0x118 +
                 (int)*(char *)(*(int *)&this->field_0x3c + this->field_0x118 + 1);
          }
          else {
            if (((bVar3 == 0xff) && (pbVar9[3] == 0)) && (pbVar9[4] == 2)) {
              bVar3 = pbVar9[1];
              if (bVar3 == 5) {
                this->field_0x118 = this->field_0x118 + 5;
              }
              else {
                MSL_C.PPCEABI.bare.H::strcpy((char *)&this->field_0x70,"");
                fVar2 = f_op_msg_mng::0_0;
                this->field_0x18 = f_op_msg_mng::0_0;
                this->field_0x1c = fVar2;
                this->field_0x28 = this->field_0x20;
                this->field_0x154 =
                     (uint)*(byte *)(*(int *)&this->field_0x3c + this->field_0x118 + 5);
                this->field_0x118 = this->field_0x118 + 6;
                while ((int)this->field_0x118 < (int)(iVar7 + (uint)bVar3)) {
                  iVar15 = *(int *)&this->field_0x3c;
                  local_140 = *(char *)(iVar15 + this->field_0x118);
                  local_13f = *(undefined *)(iVar15 + this->field_0x118 + 1);
                  local_13e = 0;
                  uVar16 = (uint)*(ushort *)(iVar15 + this->field_0x118);
                  MSL_C.PPCEABI.bare.H::strcat((char *)&this->field_0x70,&local_140);
                  if (*(char *)&this->field_0x29b == '\0') {
                    dVar18 = (double)rubyLength(this,uVar16,true);
                    this->field_0x18 = (float)dVar18;
                    *(undefined *)&this->field_0x29b = 1;
                  }
                  else {
                    dVar18 = (double)rubyLength(this,uVar16,false);
                    this->field_0x18 = (float)((double)this->field_0x18 + dVar18);
                  }
                  this->field_0x118 = this->field_0x118 + 2;
                }
              }
            }
            else {
              if (((bVar3 == 0) && (pbVar9[3] == 0)) && (pbVar9[4] == 0)) {
                iVar7 = 0;
                pcVar10 = f_op_msg_mng::dComIfGs_getPlayerName();
                MSL_C.PPCEABI.bare.H::strcpy(acStack205 + 1,pcVar10);
                cVar14 = f_op_msg_mng::dComIfGs_getPalLanguage();
                if ((cVar14 == '\x01') &&
                   (((sVar5 = *(short *)(*(int *)&this->field_0xc + 4), sVar5 == 0x33b ||
                     (sVar5 == 0xc8b)) ||
                    ((sVar5 == 0x1d21 ||
                     (((sVar5 == 0x31d7 || (sVar5 == 0x37dd)) || (sVar5 == 0x37de)))))))) {
                  sVar11 = MSL_C.PPCEABI.bare.H::strlen(acStack205 + 1);
                  cVar14 = (acStack205 + 1)[sVar11 - 1];
                  if ((((cVar14 == 's') || (cVar14 == 'S')) || (cVar14 == 'z')) ||
                     (((cVar14 == 'Z' || (cVar14 == 'x')) || (cVar14 == 'X')))) {
                    MSL_C.PPCEABI.bare.H::strcat(acStack205 + 1,"\'");
                  }
                  else {
                    MSL_C.PPCEABI.bare.H::strcat(acStack205 + 1,"s");
                  }
                }
                pbVar9 = (byte *)(acStack205 + 1);
                while( true ) {
                  bVar3 = *pbVar9;
                  uVar16 = (uint)bVar3;
                  if (bVar3 == 0) break;
                  if (((int)uVar16 >> 4 == 8) || ((int)uVar16 >> 4 == 9)) {
                    *(char *)&this->field_0xd4 = (acStack205 + 1)[iVar7];
                    cVar14 = (acStack205 + 1)[iVar7 + 1];
                    uVar16 = (uint)CONCAT11(bVar3,cVar14);
                    *(char *)&this->field_0xd5 = cVar14;
                    *(undefined *)&this->field_0xd6 = 0;
                    iVar7 = iVar7 + 2;
                    pbVar9 = pbVar9 + 2;
                  }
                  else {
                    *(char *)&this->field_0xd4 = acStack205[iVar7 + 1];
                    *(undefined *)&this->field_0xd5 = 0;
                    iVar7 = iVar7 + 1;
                    pbVar9 = pbVar9 + 1;
                  }
                  if (this->field_0x150 == 0) {
                    dVar18 = (double)charLength(this,this->field_0x148,uVar16,true);
                    this->field_0x14 = (float)dVar18;
                  }
                  else {
                    dVar18 = (double)charLength(this,this->field_0x148,uVar16,false);
                    this->field_0x14 = (float)((double)this->field_0x14 + dVar18);
                  }
                  MSL_C.PPCEABI.bare.H::strcat
                            (*(char **)&this->field_0x60,(char *)&this->field_0xd4);
                  MSL_C.PPCEABI.bare.H::strcat
                            (*(char **)&this->field_0x68,(char *)&this->field_0xd4);
                  this->field_0x150 = this->field_0x150 + 1;
                }
                if (*(char *)&this->field_0x294 == '\x01') {
                  local_30 = (double)CONCAT44(0x43300000,
                                              *(uint *)(&this->field_0x108 + this->field_0x130 * 4)
                                              ^ 0x80000000);
                  this->field_0x20 =
                       f_op_msg_mng::0_5 +
                       (float)(local_30 - f_op_msg_mng::_4895) + this->field_0x14;
                }
                else {
                  local_30 = (double)CONCAT44(0x43300000,
                                              *(uint *)(&this->field_0xf8 + this->field_0x130 * 4) ^
                                              0x80000000);
                  this->field_0x20 =
                       f_op_msg_mng::0_5 +
                       (float)(local_30 - f_op_msg_mng::_4895) + this->field_0x14;
                }
                this->field_0x118 =
                     this->field_0x118 +
                     (int)*(char *)(*(int *)&this->field_0x3c + this->field_0x118 + 1);
              }
              else {
                if (((bVar3 == 0) && (pbVar9[3] == 0)) && (pbVar9[4] == 1)) {
                  *(undefined *)&this->field_0x29a = 1;
                  this->field_0x118 =
                       this->field_0x118 +
                       (int)*(char *)(*(int *)&this->field_0x3c + this->field_0x118 + 1);
                }
                else {
                  if (((bVar3 == 0) && (pbVar9[3] == 0)) && (pbVar9[4] == 2)) {
                    *(undefined *)&this->field_0x29a = 0;
                    this->field_0x118 =
                         this->field_0x118 +
                         (int)*(char *)(*(int *)&this->field_0x3c + this->field_0x118 + 1);
                  }
                  else {
                    if (((bVar3 == 0) && (pbVar9[3] == 0)) && (pbVar9[4] == 3)) {
                      this->field_0x158 = (uint)pbVar9[5] << 8;
                      this->field_0x158 =
                           this->field_0x158 |
                           (uint)*(byte *)(*(int *)&this->field_0x3c + this->field_0x118 + 6);
                      setAutoSendFlagOn(this);
                      this->field_0x118 =
                           this->field_0x118 +
                           (int)*(char *)(*(int *)&this->field_0x3c + this->field_0x118 + 1);
                    }
                    else {
                      if (((bVar3 == 0) && (pbVar9[3] == 0)) && (pbVar9[4] == 4)) {
                        cVar14 = *(char *)(*(int *)&this->field_0xc + 0xc);
                        if (((((cVar14 == '\0') || (cVar14 == '\x01')) || (cVar14 == '\x05')) ||
                            ((cVar14 == '\b' || (cVar14 == '\f')))) || (cVar14 == '\x0e')) {
                          *(undefined *)&this->field_0x296 = 1;
                        }
                        this->field_0x158 =
                             (uint)*(byte *)(*(int *)&this->field_0x3c + this->field_0x118 + 5) << 8
                        ;
                        this->field_0x158 =
                             this->field_0x158 |
                             (uint)*(byte *)(*(int *)&this->field_0x3c + this->field_0x118 + 6);
                        setAutoSendFlagOn(this);
                        this->field_0x118 =
                             this->field_0x118 +
                             (int)*(char *)(*(int *)&this->field_0x3c + this->field_0x118 + 1);
                      }
                      else {
                        if (((bVar3 == 0) && (pbVar9[3] == 0)) && (pbVar9[4] == 5)) {
                          this->field_0x158 = (uint)pbVar9[5] << 8;
                          this->field_0x158 =
                               this->field_0x158 |
                               (uint)*(byte *)(*(int *)&this->field_0x3c + this->field_0x118 + 6);
                          setHandSendFlagOn(this);
                          this->field_0x118 =
                               this->field_0x118 +
                               (int)*(char *)(*(int *)&this->field_0x3c + this->field_0x118 + 1);
                        }
                        else {
                          if (((bVar3 == 0) && (pbVar9[3] == 0)) && (pbVar9[4] == 6)) {
                            this->field_0x118 = this->field_0x118 + (int)(char)pbVar9[1];
                          }
                          else {
                            if (((bVar3 == 0) && (pbVar9[3] == 0)) && (pbVar9[4] == 7)) {
                              if (*(char *)&this->field_0x299 == '\0') {
                                cVar13 = *(char *)(*(int *)&this->field_0xc + 0xc);
                                if (((cVar13 == '\0') || (cVar13 == '\x01')) ||
                                   ((cVar13 == '\x05' ||
                                    (((cVar13 == '\b' || (cVar13 == '\f')) || (cVar13 == '\x0e')))))
                                   ) {
                                  *(undefined *)&this->field_0x296 = 1;
                                }
                                this->field_0x158 =
                                     (uint)*(byte *)(*(int *)&this->field_0x3c + this->field_0x118 +
                                                    5) << 8;
                                this->field_0x158 =
                                     this->field_0x158 |
                                     (uint)*(byte *)(*(int *)&this->field_0x3c + this->field_0x118 +
                                                    6);
                                this->field_0x118 =
                                     this->field_0x118 +
                                     (int)*(char *)(*(int *)&this->field_0x3c + this->field_0x118 +
                                                   1);
                                goto LAB_80034f1c;
                              }
                              cVar14 = *(char *)(*(int *)&this->field_0xc + 0xc);
                              if (((cVar14 == '\0') || (cVar14 == '\x01')) ||
                                 (((cVar14 == '\x05' || ((cVar14 == '\b' || (cVar14 == '\f')))) ||
                                  (cVar14 == '\x0e')))) {
                                *(undefined *)&this->field_0x296 = 1;
                                this->field_0x158 =
                                     (uint)*(byte *)(*(int *)&this->field_0x3c + this->field_0x118 +
                                                    5) << 8;
                                this->field_0x158 =
                                     this->field_0x158 |
                                     (uint)*(byte *)(*(int *)&this->field_0x3c + this->field_0x118 +
                                                    6);
                                this->field_0x118 =
                                     this->field_0x118 +
                                     (int)*(char *)(*(int *)&this->field_0x3c + this->field_0x118 +
                                                   1);
                                goto LAB_80034f1c;
                              }
                              this->field_0x118 = this->field_0x118 + (int)(char)pbVar9[1];
                            }
                            else {
                              if (((bVar3 == 0) && (pbVar9[3] == 0)) && (pbVar9[4] == 8)) {
                                setSelectFlagOn(this);
                                this->field_0x130 = 0;
                                local_30 = (double)CONCAT44(0x43300000,
                                                            *(uint *)(&this->field_0x108 +
                                                                     this->field_0x130 * 4) ^
                                                            0x80000000);
                                this->field_0x20 = (float)(local_30 - f_op_msg_mng::_4895);
                                this->field_0x118 =
                                     this->field_0x118 +
                                     (int)*(char *)(*(int *)&this->field_0x3c +
                                                   this->field_0x118 + 1);
                                *(undefined *)&this->field_0x27c = 8;
                                *(undefined4 *)&this->field_0x60 = *(undefined4 *)&this->field_0x50;
                                *(undefined4 *)&this->field_0x64 = *(undefined4 *)&this->field_0x54;
                                *(undefined4 *)&this->field_0x68 = *(undefined4 *)&this->field_0x58;
                                *(undefined4 *)&this->field_0x6c = *(undefined4 *)&this->field_0x5c;
                              }
                              else {
                                if (((bVar3 == 0) && (pbVar9[3] == 0)) && (pbVar9[4] == 9)) {
                                  setSelectFlagOn(this);
                                  this->field_0x130 = 0;
                                  local_30 = (double)CONCAT44(0x43300000,
                                                              *(uint *)(&this->field_0x108 +
                                                                       this->field_0x130 * 4) ^
                                                              0x80000000);
                                  this->field_0x20 = (float)(local_30 - f_op_msg_mng::_4895);
                                  this->field_0x118 =
                                       this->field_0x118 +
                                       (int)*(char *)(*(int *)&this->field_0x3c +
                                                     this->field_0x118 + 1);
                                  *(undefined *)&this->field_0x27c = 9;
                                  *(undefined4 *)&this->field_0x60 =
                                       *(undefined4 *)&this->field_0x50;
                                  *(undefined4 *)&this->field_0x64 =
                                       *(undefined4 *)&this->field_0x54;
                                  *(undefined4 *)&this->field_0x68 =
                                       *(undefined4 *)&this->field_0x58;
                                  *(undefined4 *)&this->field_0x6c =
                                       *(undefined4 *)&this->field_0x5c;
                                }
                                else {
                                  if (((bVar3 == 0) && (pbVar9[3] == 0)) && (pbVar9[4] == 10)) {
                                    iconSelect(this,this->field_0x148,'\0');
                                  }
                                  else {
                                    if (((bVar3 == 0) && (pbVar9[3] == 0)) && (pbVar9[4] == 0xb)) {
                                      iconSelect(this,this->field_0x148,'\x01');
                                    }
                                    else {
                                      if (((bVar3 == 0) && (pbVar9[3] == 0)) && (pbVar9[4] == 0xc))
                                      {
                                        iconSelect(this,this->field_0x148,'\x02');
                                      }
                                      else {
                                        if (((bVar3 == 0) && (pbVar9[3] == 0)) && (pbVar9[4] == 0xd)
                                           ) {
                                          iconSelect(this,this->field_0x148,'\x03');
                                        }
                                        else {
                                          if (((bVar3 == 0) && (pbVar9[3] == 0)) &&
                                             (pbVar9[4] == 0xe)) {
                                            iconSelect(this,this->field_0x148,'\x04');
                                          }
                                          else {
                                            if (((bVar3 == 0) && (pbVar9[3] == 0)) &&
                                               (pbVar9[4] == 0xf)) {
                                              iconSelect(this,this->field_0x148,'\x05');
                                            }
                                            else {
                                              if (((bVar3 == 0) && (pbVar9[3] == 0)) &&
                                                 (pbVar9[4] == 0x10)) {
                                                iconSelect(this,this->field_0x148,'\x06');
                                              }
                                              else {
                                                if (((bVar3 == 0) && (pbVar9[3] == 0)) &&
                                                   (pbVar9[4] == 0x11)) {
                                                  iconSelect(this,this->field_0x148,'\a');
                                                }
                                                else {
                                                  if (((bVar3 == 0) && (pbVar9[3] == 0)) &&
                                                     (pbVar9[4] == 0x12)) {
                                                    iconSelect(this,this->field_0x148,'\b');
                                                  }
                                                  else {
                                                    if (((bVar3 == 0) && (pbVar9[3] == 0)) &&
                                                       (pbVar9[4] == 0x13)) {
                                                      iconSelect(this,this->field_0x148,'\t');
                                                    }
                                                    else {
                                                      if (((bVar3 == 0) && (pbVar9[3] == 0)) &&
                                                         (pbVar9[4] == 0x14)) {
                                                        iconSelect(this,this->field_0x148,'\n');
                                                      }
                                                      else {
                                                        if (((bVar3 == 0) && (pbVar9[3] == 0)) &&
                                                           (pbVar9[4] == 0x15)) {
                                                          iconSelect(this,this->field_0x148,'\v');
                                                        }
                                                        else {
                                                          if (((bVar3 == 0) && (pbVar9[3] == 0)) &&
                                                             (pbVar9[4] == 0x16)) {
                                                            iconSelect(this,this->field_0x148,'\f');
                                                          }
                                                          else {
                                                            if (((bVar3 == 0) && (pbVar9[3] == 0))
                                                               && (pbVar9[4] == 0x17)) {
                                                              iconSelect(this,this->field_0x148,'\r'
                                                                        );
                                                            }
                                                            else {
                                                              if (((bVar3 == 0) && (pbVar9[3] == 0))
                                                                 && (pbVar9[4] == 0x18)) {
                                                                iconSelect(this,this->field_0x148,
                                                                           '\x0e');
                                                              }
                                                              else {
                                                                if (((bVar3 == 0) &&
                                                                    (pbVar9[3] == 0)) &&
                                                                   (pbVar9[4] == 0x19)) {
                                                                  iconSelect(this,this->field_0x148,
                                                                             '\x0f');
                                                                }
                                                                else {
                                                                  if (((bVar3 == 0) &&
                                                                      (pbVar9[3] == 0)) &&
                                                                     (pbVar9[4] == 0x1a)) {
                                                                    iconSelect(this,this->
                                                  field_0x148,'\x10');
                                                  }
                                                  else {
                                                    if (((bVar3 == 0) && (pbVar9[3] == 0)) &&
                                                       (pbVar9[4] == 0x1b)) {
                                                      iconSelect(this,this->field_0x148,'\x11');
                                                    }
                                                    else {
                                                      if (((bVar3 == 0) && (pbVar9[3] == 0)) &&
                                                         (pbVar9[4] == 0x1c)) {
                                                        iconSelect(this,this->field_0x148,'\x12');
                                                      }
                                                      else {
                                                        if (((bVar3 == 0) && (pbVar9[3] == 0)) &&
                                                           (pbVar9[4] == 0x1d)) {
                                                          iconSelect(this,this->field_0x148,'\x13');
                                                        }
                                                        else {
                                                          if (((bVar3 == 0) && (pbVar9[3] == 0)) &&
                                                             (pbVar9[4] == 0x1e)) {
                                                            setSelectFlagYokoOn(this);
                                                            iconSelect(this,this->field_0x148,'\x14'
                                                                      );
                                                            *(undefined *)&this->field_0x27c = 0x14;
                                                          }
                                                          else {
                                                            if (((bVar3 == 0) && (pbVar9[3] == 0))
                                                               && (pbVar9[4] == 0x1f)) {
                                                              if (*(char *)&this->field_0x294 ==
                                                                  '\0') {
                                                                this->field_0x27d = 0;
                                                              }
                                                              else {
                                                                this->field_0x27d = 1;
                                                              }
                                                              iconSelect(this,this->field_0x148,
                                                                         '\x15');
                                                            }
                                                            else {
                                                              if (((bVar3 == 0) && (pbVar9[3] == 0))
                                                                 && (pbVar9[4] == 0x39)) {
                                                                iconSelect(this,this->field_0x148,
                                                                           '\x18');
                                                              }
                                                              else {
                                                                if (((bVar3 == 0) &&
                                                                    (pbVar9[3] == 0)) &&
                                                                   (pbVar9[4] == 0x3a)) {
                                                                  iconSelect(this,this->field_0x148,
                                                                             '\x19');
                                                                }
                                                                else {
                                                                  if (((bVar3 == 0) &&
                                                                      (pbVar9[3] == 0)) &&
                                                                     (pbVar9[4] == 0x20)) {
                                                                    tag_kaisen_game(this);
                                                                  }
                                                                  else {
                                                                    if (((((bVar3 == 0) &&
                                                                          (pbVar9[3] == 0)) &&
                                                                         (pbVar9[4] == 0x21)) ||
                                                                        (((bVar3 == 0 &&
                                                                          (pbVar9[3] == 0)) &&
                                                                         (pbVar9[4] == 0x24)))) ||
                                                                       (((((bVar3 == 0 &&
                                                                           (pbVar9[3] == 0)) &&
                                                                          (pbVar9[4] == 0x25)) ||
                                                                         (((bVar3 == 0 &&
                                                                           (pbVar9[3] == 0)) &&
                                                                          (pbVar9[4] == 0x2c)))) ||
                                                                        (((bVar3 == 0 &&
                                                                          (pbVar9[3] == 0)) &&
                                                                         (pbVar9[4] == 0x36)))))) {
                                                                      tag_rupee(this);
                                                                    }
                                                                    else {
                                                                      if ((((bVar3 == 0) &&
                                                                           (pbVar9[3] == 0)) &&
                                                                          (pbVar9[4] == 0x22)) ||
                                                                         (((bVar3 == 0 &&
                                                                           (pbVar9[3] == 0)) &&
                                                                          (pbVar9[4] == 0x23)))) {
                                                                        if (pbVar9[4] == 0x22) {
                                                                          uVar12 = f_op_msg_mng::
                                                                                                                                                                      
                                                  dComIfGp_getNpcNameMessageID();
                                                  getString(this,*(char **)&this->field_0x60,
                                                            *(char **)&this->field_0x68,
                                                            *(char **)&this->field_0x64,
                                                            *(char **)&this->field_0x6c,uVar12,
                                                            &this->field_0x20,&this->field_0x24,
                                                            &this->field_0x150);
                                                  }
                                                  else {
                                                    if (pbVar9[4] == 0x23) {
                                                      uVar12 = f_op_msg_mng::
                                                               dComIfGp_getItemNameMessageID();
                                                      getString(this,*(char **)&this->field_0x60,
                                                                *(char **)&this->field_0x68,
                                                                *(char **)&this->field_0x64,
                                                                *(char **)&this->field_0x6c,uVar12,
                                                                &this->field_0x20,&this->field_0x24,
                                                                &this->field_0x150);
                                                    }
                                                  }
                                                  if (*(char *)&this->field_0x294 == '\x01') {
                                                    local_30 = (double)CONCAT44(0x43300000,
                                                                                *(uint *)(&this->
                                                  field_0x108 + this->field_0x130 * 4) ^ 0x80000000)
                                                  ;
                                                  this->field_0x14 =
                                                       this->field_0x20 -
                                                       (float)(local_30 - f_op_msg_mng::_4895);
                                                  }
                                                  else {
                                                    local_30 = (double)CONCAT44(0x43300000,
                                                                                *(uint *)(&this->
                                                  field_0xf8 + this->field_0x130 * 4) ^ 0x80000000);
                                                  this->field_0x14 =
                                                       this->field_0x20 -
                                                       (float)(local_30 - f_op_msg_mng::_4895);
                                                  }
                                                  this->field_0x118 =
                                                       this->field_0x118 +
                                                       (int)*(char *)(*(int *)&this->field_0x3c +
                                                                     this->field_0x118 + 1);
                                                  }
                                                  else {
                                                    if (((bVar3 == 0) && (pbVar9[3] == 0)) &&
                                                       (pbVar9[4] == 0x26)) {
                                                      tag_num_input(this);
                                                    }
                                                    else {
                                                      if (((bVar3 == 0) && (pbVar9[3] == 0)) &&
                                                         (pbVar9[4] == 0x27)) {
                                                        iconSelect(this,this->field_0x148,'\x17');
                                                      }
                                                      else {
                                                        if (((bVar3 == 0) && (pbVar9[3] == 0)) &&
                                                           (pbVar9[4] == 0x28)) {
                                                          tag_sword_game(this);
                                                        }
                                                        else {
                                                          if (((bVar3 == 0) && (pbVar9[3] == 0)) &&
                                                             (pbVar9[4] == 0x29)) {
                                                            uVar16 = f_op_msg_mng::
                                                                     dComIfGs_getEventReg(0xba0f);
                                                            getString(this,*(char **)&this->
                                                  field_0x60,*(char **)&this->field_0x68,
                                                  *(char **)&this->field_0x64,
                                                  *(char **)&this->field_0x6c,
                                                  (uVar16 & 0xff) + 0x1b37,&this->field_0x20,
                                                  &this->field_0x24,&this->field_0x150);
                                                  if (*(char *)&this->field_0x294 == '\x01') {
                                                    local_30 = (double)CONCAT44(0x43300000,
                                                                                *(uint *)(&this->
                                                  field_0x108 + this->field_0x130 * 4) ^ 0x80000000)
                                                  ;
                                                  this->field_0x14 =
                                                       this->field_0x20 -
                                                       (float)(local_30 - f_op_msg_mng::_4895);
                                                  }
                                                  else {
                                                    local_30 = (double)CONCAT44(0x43300000,
                                                                                *(uint *)(&this->
                                                  field_0xf8 + this->field_0x130 * 4) ^ 0x80000000);
                                                  this->field_0x14 =
                                                       this->field_0x20 -
                                                       (float)(local_30 - f_op_msg_mng::_4895);
                                                  }
                                                  this->field_0x118 =
                                                       this->field_0x118 +
                                                       (int)*(char *)(*(int *)&this->field_0x3c +
                                                                     this->field_0x118 + 1);
                                                  }
                                                  else {
                                                    if (((bVar3 == 0) && (pbVar9[3] == 0)) &&
                                                       (pbVar9[4] == 0x2a)) {
                                                      iconSelect(this,this->field_0x148,'\x1a');
                                                    }
                                                    else {
                                                      if (((bVar3 == 0) && (pbVar9[3] == 0)) &&
                                                         (pbVar9[4] == 0x2b)) {
                                                        tag_letter_game(this);
                                                      }
                                                      else {
                                                        if (((bVar3 == 0) && (pbVar9[3] == 0)) &&
                                                           (pbVar9[4] == 0x3b)) {
                                                          tag_letter_game_max(this);
                                                        }
                                                        else {
                                                          if (((bVar3 == 0) && (pbVar9[3] == 0)) &&
                                                             (pbVar9[4] == 0x3c)) {
                                                            tag_fish(this);
                                                          }
                                                          else {
                                                            if (((bVar3 == 0) && (pbVar9[3] == 0))
                                                               && (pbVar9[4] == 0x3d)) {
                                                              tag_fish_rupee(this);
                                                            }
                                                            else {
                                                              if (((bVar3 == 0) && (pbVar9[3] == 0))
                                                                 && (pbVar9[4] == 0x2d)) {
                                                                tag_letter(this);
                                                              }
                                                              else {
                                                                if (((bVar3 == 0) &&
                                                                    (pbVar9[3] == 0)) &&
                                                                   (pbVar9[4] == 0x2e)) {
                                                                  tag_rescue(this);
                                                                }
                                                                else {
                                                                  if (((bVar3 == 0) &&
                                                                      (pbVar9[3] == 0)) &&
                                                                     (pbVar9[4] == 0x2f)) {
                                                                    tag_forest_timer(this);
                                                                  }
                                                                  else {
                                                                    if ((((bVar3 == 0) &&
                                                                         (pbVar9[3] == 0)) &&
                                                                        (pbVar9[4] == 0x30)) ||
                                                                       (((bVar3 == 0 &&
                                                                         (pbVar9[3] == 0)) &&
                                                                        (pbVar9[4] == 0x31)))) {
                                                                      tag_birdman(this);
                                                                    }
                                                                    else {
                                                                      if (((bVar3 == 0) &&
                                                                          (pbVar9[3] == 0)) &&
                                                                         (pbVar9[4] == 0x32)) {
                                                                        tag_point(this);
                                                                      }
                                                                      else {
                                                                        if (((bVar3 == 0) &&
                                                                            (pbVar9[3] == 0)) &&
                                                                           (pbVar9[4] == 0x33)) {
                                                                          tag_get_pendant(this);
                                                                        }
                                                                        else {
                                                                          if (((bVar3 == 0) &&
                                                                              (pbVar9[3] == 0)) &&
                                                                             (pbVar9[4] == 0x34)) {
                                                                            tag_rev_pendant(this);
                                                                          }
                                                                          else {
                                                                            if (((bVar3 == 0) &&
                                                                                (pbVar9[3] == 0)) &&
                                                                               (pbVar9[4] == 0x35))
                                                                            {
                                                                              tag_pig_timer(this);
                                                                            }
                                                                            else {
                                                                              if (((bVar3 == 0) &&
                                                                                  (pbVar9[3] == 0))
                                                                                 && (pbVar9[4] ==
                                                                                     0x37)) {
                                                                                tag_get_bomb(this);
                                                                              }
                                                                              else {
                                                                                if (((bVar3 == 0) &&
                                                                                    (pbVar9[3] == 0)
                                                                                    ) && (pbVar9[4] 
                                                  == 0x38)) {
                                                    tag_get_arrow(this);
                                                  }
                                                  else {
                                                    if (((bVar3 == 0) && (pbVar9[3] == 0)) &&
                                                       (pbVar9[4] == 0x3e)) {
                                                      tag_stock_bokobaba(this);
                                                    }
                                                    else {
                                                      if (((bVar3 == 0) && (pbVar9[3] == 0)) &&
                                                         (pbVar9[4] == 0x3f)) {
                                                        tag_stock_dokuro(this);
                                                      }
                                                      else {
                                                        if (((bVar3 == 0) && (pbVar9[3] == 0)) &&
                                                           (pbVar9[4] == 0x40)) {
                                                          tag_stock_chuchu(this);
                                                        }
                                                        else {
                                                          if (((bVar3 == 0) && (pbVar9[3] == 0)) &&
                                                             (pbVar9[4] == 0x41)) {
                                                            tag_stock_pendant(this);
                                                          }
                                                          else {
                                                            if (((bVar3 == 0) && (pbVar9[3] == 0))
                                                               && (pbVar9[4] == 0x42)) {
                                                              tag_stock_hane(this);
                                                            }
                                                            else {
                                                              if (((bVar3 == 0) && (pbVar9[3] == 0))
                                                                 && (pbVar9[4] == 0x43)) {
                                                                tag_stock_kenshi(this);
                                                              }
                                                              else {
                                                                if (((bVar3 == 0) &&
                                                                    (pbVar9[3] == 0)) &&
                                                                   (pbVar9[4] == 0x44)) {
                                                                  tag_terry_rupee(this);
                                                                }
                                                                else {
                                                                  if (((bVar3 == 0) &&
                                                                      (pbVar9[3] == 0)) &&
                                                                     (pbVar9[4] == 0x45)) {
                                                                    tag_input_bokobaba(this);
                                                                  }
                                                                  else {
                                                                    if (((bVar3 == 0) &&
                                                                        (pbVar9[3] == 0)) &&
                                                                       (pbVar9[4] == 0x46)) {
                                                                      tag_input_dokuro(this);
                                                                    }
                                                                    else {
                                                                      if (((bVar3 == 0) &&
                                                                          (pbVar9[3] == 0)) &&
                                                                         (pbVar9[4] == 0x47)) {
                                                                        tag_input_chuchu(this);
                                                                      }
                                                                      else {
                                                                        if (((bVar3 == 0) &&
                                                                            (pbVar9[3] == 0)) &&
                                                                           (pbVar9[4] == 0x48)) {
                                                                          tag_input_pendant(this);
                                                                        }
                                                                        else {
                                                                          if (((bVar3 == 0) &&
                                                                              (pbVar9[3] == 0)) &&
                                                                             (pbVar9[4] == 0x49)) {
                                                                            tag_input_hane(this);
                                                                          }
                                                                          else {
                                                                            if (((bVar3 == 0) &&
                                                                                (pbVar9[3] == 0)) &&
                                                                               (pbVar9[4] == 0x4a))
                                                                            {
                                                                              tag_input_kenshi(this)
                                                                              ;
                                                                            }
                                                                            else {
                                                                              if (bVar3 == 1) {
                                                                                sVar5 = *(short *)(*
                                                  (int *)&this->field_0x3c + iVar7 + 3);
                                                  iVar7 = f_op_msg_mng::
                                                          dComIfGp_roomControl_getStayNo();
                                                  if (iVar7 == 0) {
                                                    if (sVar5 == 8) {
                                                      f_op_msg_mng::mDoAud_messageSePlay(8,0,0);
                                                    }
                                                    else {
                                                      f_op_msg_mng::mDoAud_messageSePlay
                                                                (sVar5,this->field_0x10,0);
                                                    }
                                                  }
                                                  else {
                                                    f_op_msg_mng::dComIfGp_roomControl_getStayNo();
                                                    uVar8 = d_com_inf_game::dComIfGp_getReverb();
                                                    if (sVar5 == 8) {
                                                      f_op_msg_mng::mDoAud_messageSePlay(8,0,uVar8);
                                                    }
                                                    else {
                                                      f_op_msg_mng::mDoAud_messageSePlay
                                                                (sVar5,this->field_0x10,uVar8);
                                                    }
                                                  }
                                                  this->field_0x118 =
                                                       this->field_0x118 +
                                                       (int)*(char *)(*(int *)&this->field_0x3c +
                                                                      this->field_0x118 + 1);
                                                  goto LAB_80034f1c;
                                                  }
                                                  if (bVar3 == 2) {
                                                    f_op_msg_mng::dComIfGp_setMesgCameraTagInfo
                                                              (*(undefined2 *)(pbVar9 + 3));
                                                    this->field_0x118 =
                                                         this->field_0x118 +
                                                         (int)*(char *)(*(int *)&this->field_0x3c +
                                                                       this->field_0x118 + 1);
                                                  }
                                                  else {
                                                    if (bVar3 == 3) {
                                                      f_op_msg_mng::dComIfGp_setMesgAnimeTagInfo
                                                                (pbVar9[4]);
                                                      this->field_0x118 =
                                                           this->field_0x118 +
                                                           (int)*(char *)(*(int *)&this->field_0x3c
                                                                         + this->field_0x118 + 1);
                                                    }
                                                    else {
                                                      this->field_0x118 =
                                                           this->field_0x118 + (int)(char)pbVar9[1];
                                                    }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      if (bVar3 == 10) break;
      if ((bVar3 >> 4 == 8) || (bVar3 >> 4 == 9)) {
        *(byte *)&this->field_0xd4 = bVar3;
        *(undefined *)&this->field_0xd5 =
             *(undefined *)(*(int *)&this->field_0x3c + this->field_0x118 + 1);
        *(undefined *)&this->field_0xd6 = 0;
        uVar16 = (uint)*(ushort *)(*(int *)&this->field_0x3c + this->field_0x118);
        cVar14 = f_op_msg_mng::dComIfGs_getClearCount();
        if ((cVar14 == '\0') && (*(char *)(*(int *)&this->field_0xc + 0xc) == '\f')) {
          iVar7 = 0;
          iVar15 = 0x61;
          do {
            if (uVar16 == *(ushort *)((int)&f_op_msg_mng::zfont + iVar7)) {
              *(char *)&this->field_0xd4 =
                   (char)((ushort)*(undefined2 *)((int)&DAT_8037238a + iVar7) >> 8);
              *(char *)&this->field_0xd5 = (char)*(undefined2 *)((int)&DAT_8037238a + iVar7);
              *(undefined *)&this->field_0xd6 = 0;
              uVar16 = (uint)*(ushort *)((int)&DAT_8037238a + iVar7);
              break;
            }
            iVar7 = iVar7 + 4;
            iVar15 = iVar15 + -1;
          } while (iVar15 != 0);
        }
        bVar6 = false;
      }
      else {
        *(byte *)&this->field_0xd4 = bVar3;
        *(undefined *)&this->field_0xd5 = 0;
        uVar16 = (uint)*(byte *)(*(int *)&this->field_0x3c + this->field_0x118);
        bVar6 = true;
      }
      if (this->field_0x150 == 0) {
        dVar18 = (double)charLength(this,this->field_0x148,uVar16,true);
        this->field_0x14 = (float)dVar18;
      }
      else {
        dVar18 = (double)charLength(this,this->field_0x148,uVar16,false);
        this->field_0x14 = (float)((double)this->field_0x14 + dVar18);
      }
      this->field_0x150 = this->field_0x150 + 1;
      if (*(char *)&this->field_0x294 == '\x01') {
        local_30 = (double)CONCAT44(0x43300000,
                                    *(uint *)(&this->field_0x108 + this->field_0x130 * 4) ^
                                    0x80000000);
        this->field_0x20 =
             f_op_msg_mng::0_5 + (float)(local_30 - f_op_msg_mng::_4895) + this->field_0x14;
      }
      else {
        local_30 = (double)CONCAT44(0x43300000,
                                    *(uint *)(&this->field_0xf8 + this->field_0x130 * 4) ^
                                    0x80000000);
        this->field_0x20 =
             f_op_msg_mng::0_5 + (float)(local_30 - f_op_msg_mng::_4895) + this->field_0x14;
      }
      iVar7 = (int)(f_op_msg_mng::0_5 + this->field_0x14);
      local_30 = (double)(longlong)iVar7;
      if ((int)this->field_0x128 <= iVar7) {
        MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x60,"\n");
        MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x64,"\n");
        MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x68,"\n");
        MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x6c,"\n");
        this->field_0x130 = this->field_0x130 + 1;
        this->field_0x24 = f_op_msg_mng::0_0;
        dVar18 = (double)charLength(this,this->field_0x148,uVar16,true);
        this->field_0x14 = (float)dVar18;
        if (*(char *)&this->field_0x294 == '\x01') {
          this->field_0x150 = 0;
          local_30 = (double)CONCAT44(0x43300000,
                                      *(uint *)(&this->field_0x108 + this->field_0x130 * 4) ^
                                      0x80000000);
          this->field_0x20 = (float)(local_30 - f_op_msg_mng::_4895);
          local_38 = (double)(longlong)(int)this->field_0x20;
          MSL_C.PPCEABI.bare.H::sprintf(acStack300,"\x1bCR[%d]",(int)this->field_0x20);
          MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x60,acStack300);
          MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x68,acStack300);
        }
        else {
          if ((int)this->field_0x130 < (int)(uint)*(byte *)(*(int *)&this->field_0xc + 0x16)) {
            this->field_0x150 = 0;
            local_30 = (double)CONCAT44(0x43300000,
                                        *(uint *)(&this->field_0xf8 + this->field_0x130 * 4) ^
                                        0x80000000);
            this->field_0x20 = (float)(local_30 - f_op_msg_mng::_4895);
            local_38 = (double)(longlong)(int)this->field_0x20;
            MSL_C.PPCEABI.bare.H::sprintf(acStack284,"\x1bCR[%d]",(int)this->field_0x20);
            MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x60,acStack284);
            MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x68,acStack284);
            if ((((*(char *)&this->field_0x299 == '\0') && (*(char *)&this->field_0x29a == '\0')) &&
                (*(char *)&this->field_0x297 == '\0')) &&
               ((*(char *)&this->field_0x298 == '\0' && (*(char *)&this->field_0x294 == '\0'))))
            goto LAB_80034f1c;
          }
          else {
            pcVar10 = (char *)(*(int *)&this->field_0x3c + this->field_0x118);
            cVar14 = *pcVar10;
            if (((cVar14 == '\x1a') && ((pcVar10[2] == '\0' && (pcVar10[3] == '\0')))) &&
               (pcVar10[4] == '\b')) {
              setSelectFlagOn(this);
              this->field_0x130 = 0;
              local_30 = (double)CONCAT44(0x43300000,
                                          *(uint *)(&this->field_0x108 + this->field_0x130 * 4) ^
                                          0x80000000);
              this->field_0x20 = (float)(local_30 - f_op_msg_mng::_4895);
              this->field_0x118 =
                   this->field_0x118 +
                   (int)*(char *)(*(int *)&this->field_0x3c + this->field_0x118 + 1);
              *(undefined *)&this->field_0x27c = 8;
              *(undefined4 *)&this->field_0x60 = *(undefined4 *)&this->field_0x50;
              *(undefined4 *)&this->field_0x64 = *(undefined4 *)&this->field_0x54;
              *(undefined4 *)&this->field_0x68 = *(undefined4 *)&this->field_0x58;
              *(undefined4 *)&this->field_0x6c = *(undefined4 *)&this->field_0x5c;
            }
            else {
              if ((((cVar14 != '\x1a') || (pcVar10[2] != '\0')) || (pcVar10[3] != '\0')) ||
                 (pcVar10[4] != '\t')) {
                if (cVar14 != '\0') {
                  *(undefined *)&this->field_0x27c = 7;
                }
                *(undefined *)&this->field_0x299 = 0;
                *(undefined *)&this->field_0x29a = 0;
                goto LAB_80034f1c;
              }
              setSelectFlagOn(this);
              this->field_0x130 = 0;
              local_30 = (double)CONCAT44(0x43300000,
                                          *(uint *)(&this->field_0x108 + this->field_0x130 * 4) ^
                                          0x80000000);
              this->field_0x20 = (float)(local_30 - f_op_msg_mng::_4895);
              this->field_0x118 =
                   this->field_0x118 +
                   (int)*(char *)(*(int *)&this->field_0x3c + this->field_0x118 + 1);
              *(undefined *)&this->field_0x27c = 9;
              *(undefined4 *)&this->field_0x60 = *(undefined4 *)&this->field_0x50;
              *(undefined4 *)&this->field_0x64 = *(undefined4 *)&this->field_0x54;
              *(undefined4 *)&this->field_0x68 = *(undefined4 *)&this->field_0x58;
              *(undefined4 *)&this->field_0x6c = *(undefined4 *)&this->field_0x5c;
            }
          }
        }
      }
      if ((this->field_0x154 != 0) &&
         (this->field_0x154 = this->field_0x154 + -1, this->field_0x154 == 0)) {
        this->field_0x1c = this->field_0x20 - this->field_0x28;
        dVar18 = (double)f_op_msg_mng::0_5;
        uVar1 = (uint)(dVar18 + (double)((this->field_0x28 +
                                         (float)((double)this->field_0x1c * dVar18)) -
                                        (float)((double)this->field_0x18 * dVar18)));
        local_30 = (double)(longlong)(int)uVar1;
        local_38 = (double)CONCAT44(0x43300000,uVar1 ^ 0x80000000);
        fVar2 = (float)(local_38 - f_op_msg_mng::_4895);
        fVar4 = this->field_0x24;
        if (fVar2 <= fVar4) {
          if (f_op_msg_mng::0_0 == fVar4) {
            dVar19 = (double)(fVar4 - fVar2);
            local_30 = (double)(longlong)(int)(dVar18 + dVar19);
            MSL_C.PPCEABI.bare.H::sprintf(acStack316,"\x1bCL[%d]",(int)(dVar18 + dVar19));
            MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x64,acStack316);
            MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x6c,acStack316);
            this->field_0x24 = (float)((double)this->field_0x24 - dVar19);
          }
        }
        else {
          dVar19 = (double)(fVar2 - fVar4);
          local_30 = (double)(longlong)(int)(dVar18 + dVar19);
          MSL_C.PPCEABI.bare.H::sprintf(acStack316,"\x1bCR[%d]",(int)(dVar18 + dVar19));
          MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x64,acStack316);
          MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x6c,acStack316);
          this->field_0x24 = (float)((double)this->field_0x24 + dVar19);
        }
        MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x64,(char *)&this->field_0x70);
        MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x6c,(char *)&this->field_0x70);
        this->field_0x24 = this->field_0x24 + this->field_0x18;
      }
      if (bVar6) {
        this->field_0x118 = this->field_0x118 + 1;
      }
      else {
        this->field_0x118 = this->field_0x118 + 2;
      }
      MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x60,(char *)&this->field_0xd4);
      MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x68,(char *)&this->field_0xd4);
      if (*(char *)&this->field_0x297 == '\0') {
        if ((uVar16 - 0x8140 < 2) || (uVar16 == 0x878c)) {
          this->field_0x158 = this->field_0x15c;
        }
        if ((uVar16 == 0x20) && (*(char *)&this->field_0x29c != '\0')) {
          this->field_0x158 = this->field_0x15c;
        }
      }
      if ((((*(char *)&this->field_0x299 == '\0') && (*(char *)&this->field_0x29a == '\0')) &&
          (*(char *)&this->field_0x297 == '\0')) &&
         ((*(char *)&this->field_0x298 == '\0' && (*(char *)&this->field_0x294 == '\0')))) {
        if (cVar13 == '\0') goto LAB_80034f1c;
        cVar13 = cVar13 + -1;
      }
    }
    if (this->field_0x154 != 0) {
      this->field_0x1c = this->field_0x20 - this->field_0x28;
      uVar16 = (uint)(f_op_msg_mng::0_5 +
                     ((this->field_0x28 + this->field_0x1c * f_op_msg_mng::0_5) -
                     this->field_0x18 * f_op_msg_mng::0_5));
      local_30 = (double)(longlong)(int)uVar16;
      local_38 = (double)CONCAT44(0x43300000,uVar16 ^ 0x80000000);
      fVar2 = (float)(local_38 - f_op_msg_mng::_4895);
      fVar4 = this->field_0x24;
      if (fVar2 <= fVar4) {
        if (f_op_msg_mng::0_0 == fVar4) {
          iVar7 = (int)(f_op_msg_mng::0_5 + (fVar4 - fVar2));
          local_30 = (double)(longlong)iVar7;
          MSL_C.PPCEABI.bare.H::sprintf(acStack236,"\x1bCL[%d]",iVar7);
          MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x64,acStack236);
          MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x6c,acStack236);
        }
      }
      else {
        iVar7 = (int)(f_op_msg_mng::0_5 + (fVar2 - fVar4));
        local_30 = (double)(longlong)iVar7;
        MSL_C.PPCEABI.bare.H::sprintf(acStack236,"\x1bCR[%d]",iVar7);
        MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x64,acStack236);
        MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x6c,acStack236);
      }
      MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x64,(char *)&this->field_0x70);
      MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x6c,(char *)&this->field_0x70);
      this->field_0x154 = 0;
    }
    MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x60,"\n");
    MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x64,"\n");
    MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x68,"\n");
    MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x6c,"\n");
    this->field_0x118 = this->field_0x118 + 1;
    this->field_0x130 = this->field_0x130 + 1;
    if (*(char *)&this->field_0x29d != '\0') {
      this->field_0x130 = this->field_0x130 + 1;
      *(undefined *)&this->field_0x29d = 0;
    }
    fVar2 = f_op_msg_mng::0_0;
    this->field_0x14 = f_op_msg_mng::0_0;
    this->field_0x24 = fVar2;
    *(undefined *)&this->field_0x29b = 0;
    if (*(char *)&this->field_0x294 == '\x01') {
      this->field_0x150 = 0;
      local_30 = (double)CONCAT44(0x43300000,
                                  *(uint *)(&this->field_0x108 + this->field_0x130 * 4) ^ 0x80000000
                                 );
      this->field_0x20 = (float)(local_30 - f_op_msg_mng::_4895);
      local_38 = (double)(longlong)(int)this->field_0x20;
      MSL_C.PPCEABI.bare.H::sprintf(acStack268,"\x1bCR[%d]",(int)this->field_0x20);
      MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x60,acStack268);
      MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x68,acStack268);
      goto LAB_80034d34;
    }
    if ((int)(uint)*(byte *)(*(int *)&this->field_0xc + 0x16) <= (int)this->field_0x130) {
      pcVar10 = (char *)(*(int *)&this->field_0x3c + this->field_0x118);
      cVar14 = *pcVar10;
      if ((((cVar14 == '\x1a') && (pcVar10[2] == '\0')) && (pcVar10[3] == '\0')) &&
         (pcVar10[4] == '\b')) {
        setSelectFlagOn(this);
        this->field_0x130 = 0;
        local_30 = (double)CONCAT44(0x43300000,
                                    *(uint *)(&this->field_0x108 + this->field_0x130 * 4) ^
                                    0x80000000);
        this->field_0x20 = (float)(local_30 - f_op_msg_mng::_4895);
        this->field_0x118 =
             this->field_0x118 + (int)*(char *)(*(int *)&this->field_0x3c + this->field_0x118 + 1);
        *(undefined *)&this->field_0x27c = 8;
        *(undefined4 *)&this->field_0x60 = *(undefined4 *)&this->field_0x50;
        *(undefined4 *)&this->field_0x64 = *(undefined4 *)&this->field_0x54;
        *(undefined4 *)&this->field_0x68 = *(undefined4 *)&this->field_0x58;
        *(undefined4 *)&this->field_0x6c = *(undefined4 *)&this->field_0x5c;
      }
      else {
        if (((cVar14 != '\x1a') || (pcVar10[2] != '\0')) ||
           ((pcVar10[3] != '\0' || (pcVar10[4] != '\t')))) {
          if (cVar14 != '\0') {
            *(undefined *)&this->field_0x27c = 7;
          }
          this->field_0x150 = 0;
          *(undefined *)&this->field_0x299 = 0;
          *(undefined *)&this->field_0x29a = 0;
          goto LAB_80034f1c;
        }
        setSelectFlagOn(this);
        this->field_0x130 = 0;
        local_30 = (double)CONCAT44(0x43300000,
                                    *(uint *)(&this->field_0x108 + this->field_0x130 * 4) ^
                                    0x80000000);
        this->field_0x20 = (float)(local_30 - f_op_msg_mng::_4895);
        this->field_0x118 =
             this->field_0x118 + (int)*(char *)(*(int *)&this->field_0x3c + this->field_0x118 + 1);
        *(undefined *)&this->field_0x27c = 9;
        *(undefined4 *)&this->field_0x60 = *(undefined4 *)&this->field_0x50;
        *(undefined4 *)&this->field_0x64 = *(undefined4 *)&this->field_0x54;
        *(undefined4 *)&this->field_0x68 = *(undefined4 *)&this->field_0x58;
        *(undefined4 *)&this->field_0x6c = *(undefined4 *)&this->field_0x5c;
      }
      goto LAB_80034d34;
    }
    this->field_0x150 = 0;
    local_30 = (double)CONCAT44(0x43300000,
                                *(uint *)(&this->field_0xf8 + this->field_0x130 * 4) ^ 0x80000000);
    this->field_0x20 = (float)(local_30 - f_op_msg_mng::_4895);
    local_38 = (double)(longlong)(int)this->field_0x20;
    MSL_C.PPCEABI.bare.H::sprintf(acStack252,"\x1bCR[%d]",(int)this->field_0x20);
    MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x60,acStack252);
    MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x68,acStack252);
    if (*(char *)&this->field_0x297 == '\0') {
      this->field_0x158 = this->field_0x15c;
    }
    if (((*(char *)&this->field_0x299 != '\0') || (*(char *)&this->field_0x29a != '\0')) ||
       ((*(char *)&this->field_0x297 != '\0' ||
        ((*(char *)&this->field_0x298 != '\0' || (*(char *)&this->field_0x294 != '\0'))))))
    goto LAB_80034d34;
  }
LAB_80034f1c:
  __psq_l0(auStack8,uVar17);
  __psq_l1(auStack8,uVar17);
  return;
}


namespace f_op_msg_mng {

/* __stdcall dComIfGp_setMesgAnimeTagInfo(unsigned char) */

void dComIfGp_setMesgAnimeTagInfo(byte param_1)

{
  d_com_inf_game::g_dComIfG_gameInfo.mMesgAnimeTagInfo = param_1;
  return;
}


/* __stdcall dComIfGp_setMesgCameraTagInfo(int) */

void dComIfGp_setMesgCameraTagInfo(int param_1)

{
  d_com_inf_game::g_dComIfG_gameInfo.mMesgCameraTagInfo = param_1;
  return;
}

}

/* __thiscall fopMsgM_msgDataProc_c::setSelectFlagYokoOn(void) */

void __thiscall fopMsgM_msgDataProc_c::setSelectFlagYokoOn(fopMsgM_msgDataProc_c *this)

{
  *(undefined *)&this->field_0x294 = 2;
  return;
}


/* __thiscall fopMsgM_msgDataProc_c::setSelectFlagOn(void) */

void __thiscall fopMsgM_msgDataProc_c::setSelectFlagOn(fopMsgM_msgDataProc_c *this)

{
  *(undefined *)&this->field_0x294 = 1;
  return;
}


/* __thiscall fopMsgM_msgDataProc_c::setHandSendFlagOn(void) */

void __thiscall fopMsgM_msgDataProc_c::setHandSendFlagOn(fopMsgM_msgDataProc_c *this)

{
  *(undefined *)&this->field_0x298 = 1;
  return;
}


/* __thiscall fopMsgM_msgDataProc_c::setAutoSendFlagOn(void) */

void __thiscall fopMsgM_msgDataProc_c::setAutoSendFlagOn(fopMsgM_msgDataProc_c *this)

{
  *(undefined *)&this->field_0x297 = 1;
  return;
}


/* __thiscall fopMsgM_msgDataProc_c::getHandSendFlag(void) */

undefined __thiscall fopMsgM_msgDataProc_c::getHandSendFlag(fopMsgM_msgDataProc_c *this)

{
  return *(undefined *)&this->field_0x298;
}


/* __thiscall fopMsgM_msgDataProc_c::getAutoSendFlag(void) */

undefined __thiscall fopMsgM_msgDataProc_c::getAutoSendFlag(fopMsgM_msgDataProc_c *this)

{
  return *(undefined *)&this->field_0x297;
}


namespace f_op_msg_mng {

/* __stdcall mDoAud_messageSePlay(unsigned short,
                                  Vec *,
                                  signed char) */

void mDoAud_messageSePlay(ushort param_1,Vec *param_2,char param_3)

{
  JAIZelBasic::messageSePlay(JAIZelBasic::zel_basic,param_1,param_2,param_3);
  return;
}


/* __stdcall dComIfGp_roomControl_getStayNo(void) */

int dComIfGp_roomControl_getStayNo(void)

{
  return (int)(char)dStage_roomControl_c::mStayNo;
}


/* __stdcall fopMsgM_itemNumIdx(unsigned char) */

undefined fopMsgM_itemNumIdx(uint param_1)

{
  return (&itemicon)[(param_1 & 0xff) * 8];
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall fopMsgM_itemNum(unsigned char) */

uint fopMsgM_itemNum(char param_1)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 0;
  while ((uVar3 = 0, (uVar2 & 0xff) < 0x3c &&
         (cVar1 = fopMsgM_itemNumIdx(uVar2), uVar3 = uVar2, param_1 != cVar1))) {
    uVar2 = uVar2 + 1;
  }
  return uVar3;
}


/* __stdcall fopMsgM_getColorTable(unsigned short) */

undefined4 fopMsgM_getColorTable(uint param_1)

{
  int iVar1;
  
  iVar1 = JKRArchive::getGlbResource
                    (0x524f4f54,"color.bmc",
                     d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpEnglishTextArchive);
  return *(undefined4 *)(iVar1 + (param_1 & 0xffff) * 4 + 0x2c);
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __stdcall fopMsgM_int_to_char(char *,
                                 int,
                                 bool) */

void fopMsgM_int_to_char(char *param_1,int param_2,char param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  char local_28;
  undefined local_27;
  
  iVar3 = 10000;
  bVar1 = false;
  local_27 = 0;
  if (param_3 == '\0') {
    MSL_C.PPCEABI.bare.H::strcpy(param_1,"");
  }
  iVar2 = 0;
  do {
    if (((param_2 / iVar3 != 0) || (bVar1)) || (iVar3 == 1)) {
      local_28 = (char)(param_2 / iVar3) + '0';
      MSL_C.PPCEABI.bare.H::strcat(param_1,&local_28);
      if (!bVar1) {
        bVar1 = true;
      }
    }
    param_2 = param_2 - (param_2 / iVar3) * iVar3;
    iVar3 = iVar3 / 10;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 5);
  return;
}


/* __stdcall fopMsgM_int_to_char2(char *,
                                  int) */

void fopMsgM_int_to_char2(char *param_1,int param_2)

{
  char local_18;
  undefined local_17;
  
  local_17 = 0;
  local_18 = (char)(param_2 / 10) + '0';
  MSL_C.PPCEABI.bare.H::strcat(param_1,&local_18);
  local_18 = (char)param_2 + (char)(param_2 / 10) * -10 + '0';
  MSL_C.PPCEABI.bare.H::strcat(param_1,&local_18);
  return;
}

}

/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall fopMsgM_msgDataProc_c::getString(char *,
                                               unsigned long) */

void __thiscall
fopMsgM_msgDataProc_c::getString(fopMsgM_msgDataProc_c *this,char *out_buffer,ulong msg_id)

{
  mesg_header *msg_header;
  size_t cur_buffer_length;
  char *out_buffer_cursor;
  char *char_cursor;
  char *last_char;
  int num_chars_read;
  int cur_offset;
  char *msg_source;
  undefined1 *local_48;
  undefined4 local_44;
  undefined2 local_40;
  undefined2 local_3e;
  undefined2 local_3c;
  char msg_dest [25];
  byte ctrl_code_length;
  char cur_char;
  
  local_48 = &fopMsgM_msgGet_c::__vt;
  local_44 = 0;
  local_40 = 0;
  local_3e = 0;
  local_3c = 0;
  if (f_op_msg_mng::init_7642 == '\0') {
    f_op_msg_mng::name_7641 = "no name";
    f_op_msg_mng::init_7642 = '\x01';
  }
  cur_offset = 0;
  num_chars_read = 0;
  last_char = out_buffer;
  msg_source = f_op_msg_mng::name_7641;
  if (msg_id != 0) {
    msg_header = (mesg_header *)
                 fopMsgM_msgGet_c::getMesgHeader((fopMsgM_msgGet_c *)&local_48,msg_id);
    msg_source = (char *)fopMsgM_msgGet_c::getMessage((fopMsgM_msgGet_c *)&local_48,msg_header);
  }
  while( true ) {
    char_cursor = msg_source + cur_offset;
    cur_char = *char_cursor;
    if (cur_char == '\0') break;
    if (cur_char == '\x1a') {
      ctrl_code_length = char_cursor[1];
      if (((char_cursor[2] == '\0') && (char_cursor[3] == '\0')) && (char_cursor[4] == '\0')) {
        MSL_C.PPCEABI.bare.H::strcpy
                  (msg_dest + 1,
                   &d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mInfo.mPlayerName);
        if ((d_com_inf_game::g_dComIfG_gameInfo.mGameLanguage == 1) &&
           ((((msg_id == 0x33b || (msg_id == 0xc8b)) ||
             ((msg_id == 0x1d21 || ((msg_id == 0x31d7 || (msg_id == 0x37dd)))))) ||
            (msg_id == 0x37de)))) {
          cur_buffer_length = MSL_C.PPCEABI.bare.H::strlen(msg_dest + 1);
          cur_char = (msg_dest + 1)[cur_buffer_length - 1];
          if (((((cur_char == 's') || (cur_char == 'S')) || (cur_char == 'z')) ||
              ((cur_char == 'Z' || (cur_char == 'x')))) || (cur_char == 'X')) {
            MSL_C.PPCEABI.bare.H::strcat(msg_dest + 1,"\'");
          }
          else {
            MSL_C.PPCEABI.bare.H::strcat(msg_dest + 1,"s");
          }
        }
        char_cursor = msg_dest;
        out_buffer_cursor = out_buffer + num_chars_read;
        while (char_cursor = char_cursor + 1, *char_cursor != '\0') {
          *out_buffer_cursor = *char_cursor;
          num_chars_read = num_chars_read + 1;
          last_char = last_char + 1;
          out_buffer_cursor = out_buffer_cursor + 1;
        }
      }
      cur_offset = cur_offset + (uint)ctrl_code_length;
    }
    else {
      *last_char = cur_char;
      cur_offset = cur_offset + 1;
      num_chars_read = num_chars_read + 1;
      last_char = last_char + 1;
    }
  }
  out_buffer[num_chars_read] = '\0';
  return;
}


/* WARNING: Inlined function: FUN_80328f08 */
/* WARNING: Inlined function: FUN_80328f54 */
/* WARNING: Removing unreachable block (ram,0x800359fc) */
/* WARNING: Removing unreachable block (ram,0x80035a04) */
/* __thiscall fopMsgM_msgDataProc_c::getString(char *,
                                               char *,
                                               char *,
                                               char *,
                                               unsigned long,
                                               float *,
                                               float *,
                                               int *) */

void __thiscall
fopMsgM_msgDataProc_c::getString
          (fopMsgM_msgDataProc_c *this,char *param_1,char *param_2,char *param_3,char *param_4,
          ulong param_5,float *param_6,float *param_7,int *param_8)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  mesg_header *pmVar4;
  char *pcVar5;
  size_t sVar6;
  uint uVar7;
  int iVar8;
  ushort *puVar9;
  byte *pbVar10;
  ushort *puVar11;
  uint unaff_r21;
  int iVar12;
  undefined4 uVar13;
  double dVar14;
  undefined8 in_f30;
  double dVar15;
  double in_f31;
  byte local_c8;
  byte local_c7;
  undefined local_c6;
  char acStack196 [16];
  char acStack180 [16];
  undefined1 *local_a4;
  undefined4 local_a0;
  undefined2 local_9c;
  undefined2 local_9a;
  undefined2 local_98;
  char acStack149 [21];
  double local_80;
  undefined4 local_78;
  uint uStack116;
  double local_70;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar13 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,SUB84(in_f31,0),0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  local_a4 = &fopMsgM_msgGet_c::__vt;
  local_a0 = 0;
  local_9c = 0;
  local_9a = 0;
  local_98 = 0;
  dVar15 = (double)f_op_msg_mng::0_0;
  if (f_op_msg_mng::init_7701 == '\0') {
    f_op_msg_mng::name_7700 = "no name";
    f_op_msg_mng::init_7701 = '\x01';
  }
  iVar12 = 0;
  pcVar5 = f_op_msg_mng::name_7700;
  if (param_5 != 0) {
    pmVar4 = (mesg_header *)fopMsgM_msgGet_c::getMesgHeader((fopMsgM_msgGet_c *)&local_a4,param_5);
    pcVar5 = (char *)fopMsgM_msgGet_c::getMessage((fopMsgM_msgGet_c *)&local_a4,pmVar4);
  }
  while( true ) {
    puVar11 = (ushort *)(pcVar5 + iVar12);
    bVar2 = *(byte *)puVar11;
    if (bVar2 == 0) break;
    if (bVar2 == 0x1a) {
      bVar2 = *(byte *)((int)puVar11 + 1);
      if (((*(byte *)(puVar11 + 1) == 0) && (*(byte *)((int)puVar11 + 3) == 0)) &&
         (*(byte *)(puVar11 + 2) == 0)) {
        MSL_C.PPCEABI.bare.H::strcpy
                  (acStack149 + 1,
                   &d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mInfo.mPlayerName);
        if ((d_com_inf_game::g_dComIfG_gameInfo.mGameLanguage == 1) &&
           (((param_5 == 0x33b || (param_5 == 0xc8b)) ||
            ((param_5 == 0x1d21 ||
             (((param_5 == 0x31d7 || (param_5 == 0x37dd)) || (param_5 == 0x37de)))))))) {
          sVar6 = MSL_C.PPCEABI.bare.H::strlen(acStack149 + 1);
          cVar3 = (acStack149 + 1)[sVar6 - 1];
          if (((cVar3 == 's') || (cVar3 == 'S')) ||
             ((cVar3 == 'z' || (((cVar3 == 'Z' || (cVar3 == 'x')) || (cVar3 == 'X')))))) {
            MSL_C.PPCEABI.bare.H::strcat(acStack149 + 1,"\'");
          }
          else {
            MSL_C.PPCEABI.bare.H::strcat(acStack149 + 1,"s");
          }
        }
        iVar8 = 0;
        while( true ) {
          pbVar10 = (byte *)(acStack149 + iVar8 + 1);
          bVar1 = *pbVar10;
          if (bVar1 == 0) break;
          local_c8 = bVar1;
          if ((bVar1 >> 4 == 8) || (bVar1 >> 4 == 9)) {
            local_c7 = acStack149[iVar8 + 2];
            local_c6 = 0;
            MSL_C.PPCEABI.bare.H::strcat(param_1,(char *)&local_c8);
            MSL_C.PPCEABI.bare.H::strcat(param_2,(char *)&local_c8);
            uVar7 = (uint)CONCAT11(*pbVar10,acStack149[iVar8 + 2]);
            iVar8 = iVar8 + 2;
          }
          else {
            local_c7 = 0;
            MSL_C.PPCEABI.bare.H::strcat(param_1,(char *)&local_c8);
            MSL_C.PPCEABI.bare.H::strcat(param_2,(char *)&local_c8);
            uVar7 = (uint)*pbVar10;
            iVar8 = iVar8 + 1;
          }
          if (*param_8 == 0) {
            dVar14 = (double)charLength(this,this->field_0x148,uVar7,true);
            local_80 = (double)CONCAT44(0x43300000,
                                        *(uint *)(&this->field_0xf8 + this->field_0x130 * 4) ^
                                        0x80000000);
            *param_6 = (float)((double)(float)(local_80 - f_op_msg_mng::_4895) + dVar14);
          }
          else {
            dVar14 = (double)charLength(this,this->field_0x148,uVar7,false);
            *param_6 = (float)((double)*param_6 + dVar14);
          }
          *param_8 = *param_8 + 1;
        }
      }
      else {
        if (((*(byte *)(puVar11 + 1) == 0xff) && (*(byte *)((int)puVar11 + 3) == 0)) &&
           (*(byte *)(puVar11 + 2) == 2)) {
          in_f31 = (double)f_op_msg_mng::0_0;
          dVar15 = (double)*param_6;
          unaff_r21 = (uint)*(byte *)((int)puVar11 + 5);
          MSL_C.PPCEABI.bare.H::strcpy(acStack180,"");
          for (iVar8 = 6; iVar8 < (int)(uint)bVar2; iVar8 = iVar8 + 2) {
            puVar9 = (ushort *)((int)puVar11 + iVar8);
            local_c8 = *(byte *)puVar9;
            local_c7 = *(byte *)((int)puVar9 + 1);
            local_c6 = 0;
            MSL_C.PPCEABI.bare.H::strcat(acStack180,(char *)&local_c8);
            dVar14 = (double)rubyLength(this,(uint)*puVar9,false);
            in_f31 = (double)(float)(in_f31 + dVar14);
          }
        }
      }
      iVar12 = iVar12 + (uint)bVar2;
    }
    else {
      local_c8 = bVar2;
      if ((bVar2 >> 4 == 8) || (bVar2 >> 4 == 9)) {
        local_c7 = *(byte *)((int)puVar11 + 1);
        local_c6 = 0;
        MSL_C.PPCEABI.bare.H::strcat(param_1,(char *)&local_c8);
        MSL_C.PPCEABI.bare.H::strcat(param_2,(char *)&local_c8);
        uVar7 = (uint)*puVar11;
        iVar12 = iVar12 + 2;
      }
      else {
        local_c7 = 0;
        MSL_C.PPCEABI.bare.H::strcat(param_1,(char *)&local_c8);
        MSL_C.PPCEABI.bare.H::strcat(param_2,(char *)&local_c8);
        uVar7 = (uint)*(byte *)puVar11;
        iVar12 = iVar12 + 1;
      }
      if (*param_8 == 0) {
        dVar14 = (double)charLength(this,this->field_0x148,uVar7,true);
        local_80 = (double)CONCAT44(0x43300000,
                                    *(uint *)(&this->field_0xf8 + this->field_0x130 * 4) ^
                                    0x80000000);
        *param_6 = (float)((double)(float)(local_80 - f_op_msg_mng::_4895) + dVar14);
      }
      else {
        dVar14 = (double)charLength(this,this->field_0x148,uVar7,false);
        *param_6 = (float)((double)*param_6 + dVar14);
      }
      *param_8 = *param_8 + 1;
      if ((unaff_r21 != 0) && (unaff_r21 = unaff_r21 - 1, unaff_r21 == 0)) {
        dVar14 = (double)f_op_msg_mng::0_5;
        uStack116 = (uint)(dVar14 + (double)((float)(dVar15 + (double)(float)((double)(float)((
                                                  double)*param_6 - dVar15) * dVar14)) -
                                            (float)(in_f31 * dVar14)));
        local_80 = (double)(longlong)(int)uStack116;
        uStack116 = uStack116 ^ 0x80000000;
        local_78 = 0x43300000;
        uVar7 = (uint)(dVar14 + (double)((float)((double)CONCAT44(0x43300000,uStack116) -
                                                f_op_msg_mng::_4895) - *param_7));
        local_70 = (double)(longlong)(int)uVar7;
        if ((int)uVar7 < 1) {
          if (uVar7 == 0) {
            MSL_C.PPCEABI.bare.H::sprintf(acStack196,"\x1bCL[%d]",0);
            MSL_C.PPCEABI.bare.H::strcat(param_3,acStack196);
            MSL_C.PPCEABI.bare.H::strcat(param_4,acStack196);
            local_70 = 4503601774854144.0;
            *param_7 = *param_7 - (float)(4503601774854144.0 - f_op_msg_mng::_4895);
          }
        }
        else {
          MSL_C.PPCEABI.bare.H::sprintf(acStack196,"\x1bCR[%d]",uVar7);
          MSL_C.PPCEABI.bare.H::strcat(param_3,acStack196);
          MSL_C.PPCEABI.bare.H::strcat(param_4,acStack196);
          local_70 = (double)CONCAT44(0x43300000,uVar7 ^ 0x80000000);
          *param_7 = *param_7 + (float)(local_70 - f_op_msg_mng::_4895);
        }
        *param_7 = (float)((double)*param_7 + in_f31);
        MSL_C.PPCEABI.bare.H::strcat(param_3,acStack180);
        MSL_C.PPCEABI.bare.H::strcat(param_4,acStack180);
      }
    }
  }
  __psq_l0(auStack8,uVar13);
  __psq_l1(auStack8,uVar13);
  __psq_l0(auStack24,uVar13);
  __psq_l1(auStack24,uVar13);
  return;
}


/* WARNING: Inlined function: FUN_80328f20 */
/* WARNING: Inlined function: FUN_80328f6c */
/* WARNING: Removing unreachable block (ram,0x80035d00) */
/* WARNING: Removing unreachable block (ram,0x80035d08) */
/* __thiscall fopMsgM_msgDataProc_c::getRubyString(char *,
                                                   char *,
                                                   char *,
                                                   char *,
                                                   char *,
                                                   char *,
                                                   float *,
                                                   float *,
                                                   int *) */

void __thiscall
fopMsgM_msgDataProc_c::getRubyString
          (fopMsgM_msgDataProc_c *this,char *param_1,char *param_2,char *param_3,char *param_4,
          char *param_5,char *param_6,float *param_7,float *param_8,int *param_9)

{
  uint uVar1;
  byte bVar2;
  float fVar3;
  byte *pbVar4;
  undefined4 uVar5;
  double dVar6;
  undefined8 in_f30;
  double dVar7;
  undefined8 in_f31;
  double dVar8;
  char acStack120 [16];
  double local_68;
  undefined4 local_60;
  uint uStack92;
  double local_58;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  dVar8 = (double)*param_7;
  pbVar4 = (byte *)param_5;
  while (*pbVar4 != 0) {
    bVar2 = *pbVar4;
    pbVar4 = pbVar4 + 1;
    if (*param_9 == 0) {
      dVar7 = (double)charLength(this,this->field_0x148,(uint)bVar2,true);
      this->field_0x14 = (float)dVar7;
    }
    else {
      dVar7 = (double)charLength(this,this->field_0x148,(uint)bVar2,false);
      this->field_0x14 = (float)((double)this->field_0x14 + dVar7);
    }
    *param_9 = *param_9 + 1;
  }
  MSL_C.PPCEABI.bare.H::strcat(param_1,param_5);
  MSL_C.PPCEABI.bare.H::strcat(param_2,param_5);
  pbVar4 = (byte *)param_6;
  if (*(char *)&this->field_0x294 == '\x01') {
    local_68 = (double)CONCAT44(0x43300000,
                                *(uint *)(&this->field_0x108 + this->field_0x130 * 4) ^ 0x80000000);
    *param_7 = f_op_msg_mng::0_5 + (float)(local_68 - f_op_msg_mng::_4895) + this->field_0x14;
    fVar3 = f_op_msg_mng::0_0;
  }
  else {
    local_68 = (double)CONCAT44(0x43300000,
                                *(uint *)(&this->field_0xf8 + this->field_0x130 * 4) ^ 0x80000000);
    *param_7 = f_op_msg_mng::0_5 + (float)(local_68 - f_op_msg_mng::_4895) + this->field_0x14;
    fVar3 = f_op_msg_mng::0_0;
  }
  for (; dVar7 = (double)fVar3, *pbVar4 != 0; pbVar4 = pbVar4 + 1) {
    dVar6 = (double)rubyLength(this,(uint)*pbVar4,false);
    fVar3 = (float)(dVar7 + dVar6);
  }
  dVar6 = (double)f_op_msg_mng::0_5;
  uStack92 = (uint)(dVar6 + (double)((float)(dVar8 + (double)(float)((double)(float)((double)*
                                                  param_7 - dVar8) * dVar6)) -
                                    (float)(dVar7 * dVar6)));
  local_68 = (double)(longlong)(int)uStack92;
  uStack92 = uStack92 ^ 0x80000000;
  local_60 = 0x43300000;
  uVar1 = (uint)(dVar6 + (double)((float)((double)CONCAT44(0x43300000,uStack92) -
                                         f_op_msg_mng::_4895) - *param_8));
  local_58 = (double)(longlong)(int)uVar1;
  if ((int)uVar1 < 1) {
    if (uVar1 == 0) {
      MSL_C.PPCEABI.bare.H::sprintf(acStack120,"\x1bCL[%d]",0);
      MSL_C.PPCEABI.bare.H::strcat(param_3,acStack120);
      MSL_C.PPCEABI.bare.H::strcat(param_4,acStack120);
      local_58 = 4503601774854144.0;
      *param_8 = *param_8 - (float)(4503601774854144.0 - f_op_msg_mng::_4895);
    }
  }
  else {
    MSL_C.PPCEABI.bare.H::sprintf(acStack120,"\x1bCR[%d]",uVar1);
    MSL_C.PPCEABI.bare.H::strcat(param_3,acStack120);
    MSL_C.PPCEABI.bare.H::strcat(param_4,acStack120);
    local_58 = (double)CONCAT44(0x43300000,uVar1 ^ 0x80000000);
    *param_8 = *param_8 + (float)(local_58 - f_op_msg_mng::_4895);
  }
  *param_8 = (float)((double)*param_8 + dVar7);
  MSL_C.PPCEABI.bare.H::strcat(param_3,param_6);
  MSL_C.PPCEABI.bare.H::strcat(param_4,param_6);
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  __psq_l0(auStack24,uVar5);
  __psq_l1(auStack24,uVar5);
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall fopMsgM_msgDataProc_c::tag_len_kaisen_game(int *,
                                                         float *,
                                                         int *,
                                                         int *,
                                                         int *) */

void __thiscall
fopMsgM_msgDataProc_c::tag_len_kaisen_game
          (fopMsgM_msgDataProc_c *this,int *param_1,float *param_2,int *param_3,int *param_4,
          int *param_5)

{
  byte bVar1;
  ushort uVar2;
  byte *pbVar3;
  byte *pbVar4;
  double dVar5;
  byte local_38 [24];
  
  uVar2 = dSv_event_c::getEventReg(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0xbeff);
  f_op_msg_mng::fopMsgM_int_to_char(local_38,uVar2 & 0xff,0);
  MSL_C.PPCEABI.bare.H::strcat((char *)local_38,"");
  pbVar3 = local_38;
  pbVar4 = pbVar3;
  while (*pbVar4 != 0) {
    bVar1 = *pbVar3;
    pbVar4 = pbVar4 + 1;
    pbVar3 = pbVar3 + 1;
    if (*param_1 == 0) {
      dVar5 = (double)charLength(this,*param_4,(uint)bVar1,true);
      *param_2 = (float)dVar5;
    }
    else {
      dVar5 = (double)charLength(this,*param_4,(uint)bVar1,false);
      *param_2 = (float)((double)*param_2 + dVar5);
    }
    *param_1 = *param_1 + 1;
  }
  param_3[*param_5] = (int)(f_op_msg_mng::0_5 + *param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall fopMsgM_msgDataProc_c::tag_len_rupee(int *,
                                                   float *,
                                                   int *,
                                                   int *,
                                                   int *) */

void __thiscall
fopMsgM_msgDataProc_c::tag_len_rupee
          (fopMsgM_msgDataProc_c *this,int *param_1,float *param_2,int *param_3,int *param_4,
          int *param_5)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  double dVar5;
  byte local_48 [40];
  
  iVar2 = (int)(short)d_com_inf_game::g_dComIfG_gameInfo.mCurrAuctionItemNameMsgID;
  f_op_msg_mng::fopMsgM_int_to_char(local_48,iVar2,0);
  if (iVar2 == 1) {
    MSL_C.PPCEABI.bare.H::strcat((char *)local_48," Rupee");
  }
  else {
    MSL_C.PPCEABI.bare.H::strcat((char *)local_48," Rupees");
  }
  pbVar3 = local_48;
  pbVar4 = pbVar3;
  while (*pbVar4 != 0) {
    bVar1 = *pbVar3;
    pbVar4 = pbVar4 + 1;
    pbVar3 = pbVar3 + 1;
    if (*param_1 == 0) {
      dVar5 = (double)charLength(this,*param_4,(uint)bVar1,true);
      *param_2 = (float)dVar5;
    }
    else {
      dVar5 = (double)charLength(this,*param_4,(uint)bVar1,false);
      *param_2 = (float)((double)*param_2 + dVar5);
    }
    *param_1 = *param_1 + 1;
  }
  param_3[*param_5] = (int)(f_op_msg_mng::0_5 + *param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall fopMsgM_msgDataProc_c::tag_len_num_input(int *,
                                                       float *,
                                                       int *,
                                                       int *,
                                                       int *) */

void __thiscall
fopMsgM_msgDataProc_c::tag_len_num_input
          (fopMsgM_msgDataProc_c *this,int *param_1,float *param_2,int *param_3,int *param_4,
          int *param_5)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  double dVar4;
  byte local_38 [24];
  
  if (*param_5 != this->field_0x130) {
    this->field_0x130 = *param_5;
  }
  MSL_C.PPCEABI.bare.H::strcpy((char *)local_38,"000 Rupee(s)");
  pbVar2 = local_38;
  pbVar3 = pbVar2;
  while (*pbVar3 != 0) {
    bVar1 = *pbVar2;
    pbVar3 = pbVar3 + 1;
    pbVar2 = pbVar2 + 1;
    if (*param_1 == 0) {
      dVar4 = (double)charLength(this,*param_4,(uint)bVar1,true);
      *param_2 = (float)dVar4;
    }
    else {
      dVar4 = (double)charLength(this,*param_4,(uint)bVar1,false);
      *param_2 = (float)((double)*param_2 + dVar4);
    }
    *param_1 = *param_1 + 1;
  }
  param_3[*param_5] = (int)(f_op_msg_mng::0_5 + *param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall fopMsgM_msgDataProc_c::tag_len_sword_game(int *,
                                                        float *,
                                                        int *,
                                                        int *,
                                                        int *) */

void __thiscall
fopMsgM_msgDataProc_c::tag_len_sword_game
          (fopMsgM_msgDataProc_c *this,int *param_1,float *param_2,int *param_3,int *param_4,
          int *param_5)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  double dVar5;
  byte local_48 [40];
  
  iVar2 = (int)(short)d_com_inf_game::g_dComIfG_gameInfo.mCurrAuctionItemNameMsgID;
  f_op_msg_mng::fopMsgM_int_to_char(local_48,iVar2,0);
  if (iVar2 == 1) {
    MSL_C.PPCEABI.bare.H::strcat((char *)local_48," blow");
  }
  else {
    MSL_C.PPCEABI.bare.H::strcat((char *)local_48," blows");
  }
  pbVar3 = local_48;
  pbVar4 = pbVar3;
  while (*pbVar4 != 0) {
    bVar1 = *pbVar3;
    pbVar4 = pbVar4 + 1;
    pbVar3 = pbVar3 + 1;
    if (*param_1 == 0) {
      dVar5 = (double)charLength(this,*param_4,(uint)bVar1,true);
      *param_2 = (float)dVar5;
    }
    else {
      dVar5 = (double)charLength(this,*param_4,(uint)bVar1,false);
      *param_2 = (float)((double)*param_2 + dVar5);
    }
    *param_1 = *param_1 + 1;
  }
  param_3[*param_5] = (int)(f_op_msg_mng::0_5 + *param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall fopMsgM_msgDataProc_c::tag_len_letter_game(int *,
                                                         float *,
                                                         int *,
                                                         int *,
                                                         int *) */

void __thiscall
fopMsgM_msgDataProc_c::tag_len_letter_game
          (fopMsgM_msgDataProc_c *this,int *param_1,float *param_2,int *param_3,int *param_4,
          int *param_5)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  double dVar4;
  byte local_48 [40];
  
  f_op_msg_mng::fopMsgM_int_to_char(local_48,(int)d_com_inf_game::g_dComIfG_gameInfo._23772_2_,0);
  pbVar2 = local_48;
  pbVar3 = pbVar2;
  while (*pbVar3 != 0) {
    bVar1 = *pbVar2;
    pbVar3 = pbVar3 + 1;
    pbVar2 = pbVar2 + 1;
    if (*param_1 == 0) {
      dVar4 = (double)charLength(this,*param_4,(uint)bVar1,true);
      *param_2 = (float)dVar4;
    }
    else {
      dVar4 = (double)charLength(this,*param_4,(uint)bVar1,false);
      *param_2 = (float)((double)*param_2 + dVar4);
    }
    *param_1 = *param_1 + 1;
  }
  param_3[*param_5] = (int)(f_op_msg_mng::0_5 + *param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall fopMsgM_msgDataProc_c::tag_len_letter_game_max(int *,
                                                             float *,
                                                             int *,
                                                             int *,
                                                             int *) */

void __thiscall
fopMsgM_msgDataProc_c::tag_len_letter_game_max
          (fopMsgM_msgDataProc_c *this,int *param_1,float *param_2,int *param_3,int *param_4,
          int *param_5)

{
  byte bVar1;
  ushort uVar2;
  byte *pbVar3;
  byte *pbVar4;
  double dVar5;
  byte local_48 [40];
  
  uVar2 = dSv_event_c::getEventReg(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x8aff);
  f_op_msg_mng::fopMsgM_int_to_char(local_48,uVar2 & 0xff,0);
  pbVar3 = local_48;
  pbVar4 = pbVar3;
  while (*pbVar4 != 0) {
    bVar1 = *pbVar3;
    pbVar4 = pbVar4 + 1;
    pbVar3 = pbVar3 + 1;
    if (*param_1 == 0) {
      dVar5 = (double)charLength(this,*param_4,(uint)bVar1,true);
      *param_2 = (float)dVar5;
    }
    else {
      dVar5 = (double)charLength(this,*param_4,(uint)bVar1,false);
      *param_2 = (float)((double)*param_2 + dVar5);
    }
    *param_1 = *param_1 + 1;
  }
  param_3[*param_5] = (int)(f_op_msg_mng::0_5 + *param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall fopMsgM_msgDataProc_c::tag_len_fish(int *,
                                                  float *,
                                                  int *,
                                                  int *,
                                                  int *) */

void __thiscall
fopMsgM_msgDataProc_c::tag_len_fish
          (fopMsgM_msgDataProc_c *this,int *param_1,float *param_2,int *param_3,int *param_4,
          int *param_5)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  double dVar4;
  byte local_48 [40];
  
  f_op_msg_mng::fopMsgM_int_to_char
            (local_48,(int)(short)d_com_inf_game::g_dComIfG_gameInfo.mCurrAuctionItemNameMsgID,0);
  pbVar2 = local_48;
  pbVar3 = pbVar2;
  while (*pbVar3 != 0) {
    bVar1 = *pbVar2;
    pbVar3 = pbVar3 + 1;
    pbVar2 = pbVar2 + 1;
    if (*param_1 == 0) {
      dVar4 = (double)charLength(this,*param_4,(uint)bVar1,true);
      *param_2 = (float)dVar4;
    }
    else {
      dVar4 = (double)charLength(this,*param_4,(uint)bVar1,false);
      *param_2 = (float)((double)*param_2 + dVar4);
    }
    *param_1 = *param_1 + 1;
  }
  param_3[*param_5] = (int)(f_op_msg_mng::0_5 + *param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall fopMsgM_msgDataProc_c::tag_len_fish_rupee(int *,
                                                        float *,
                                                        int *,
                                                        int *,
                                                        int *) */

void __thiscall
fopMsgM_msgDataProc_c::tag_len_fish_rupee
          (fopMsgM_msgDataProc_c *this,int *param_1,float *param_2,int *param_3,int *param_4,
          int *param_5)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  double dVar5;
  byte local_48 [40];
  
  iVar2 = (int)(short)d_com_inf_game::g_dComIfG_gameInfo.mCurrAuctionItemNameMsgID;
  f_op_msg_mng::fopMsgM_int_to_char(local_48,iVar2 * 10,0);
  if (iVar2 * 10 == 1) {
    MSL_C.PPCEABI.bare.H::strcat((char *)local_48," Rupee");
  }
  else {
    MSL_C.PPCEABI.bare.H::strcat((char *)local_48," Rupees");
  }
  pbVar3 = local_48;
  pbVar4 = pbVar3;
  while (*pbVar4 != 0) {
    bVar1 = *pbVar3;
    pbVar4 = pbVar4 + 1;
    pbVar3 = pbVar3 + 1;
    if (*param_1 == 0) {
      dVar5 = (double)charLength(this,*param_4,(uint)bVar1,true);
      *param_2 = (float)dVar5;
    }
    else {
      dVar5 = (double)charLength(this,*param_4,(uint)bVar1,false);
      *param_2 = (float)((double)*param_2 + dVar5);
    }
    *param_1 = *param_1 + 1;
  }
  param_3[*param_5] = (int)(f_op_msg_mng::0_5 + *param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall fopMsgM_msgDataProc_c::tag_len_letter(int *,
                                                    float *,
                                                    int *,
                                                    int *,
                                                    int *) */

void __thiscall
fopMsgM_msgDataProc_c::tag_len_letter
          (fopMsgM_msgDataProc_c *this,int *param_1,float *param_2,int *param_3,int *param_4,
          int *param_5)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  double dVar5;
  byte local_48 [40];
  
  iVar2 = (int)(short)d_com_inf_game::g_dComIfG_gameInfo.mCurrAuctionItemNameMsgID;
  f_op_msg_mng::fopMsgM_int_to_char(local_48,iVar2,0);
  if (iVar2 == 1) {
    MSL_C.PPCEABI.bare.H::strcat((char *)local_48," letter");
  }
  else {
    MSL_C.PPCEABI.bare.H::strcat((char *)local_48," letters");
  }
  pbVar3 = local_48;
  pbVar4 = pbVar3;
  while (*pbVar4 != 0) {
    bVar1 = *pbVar3;
    pbVar4 = pbVar4 + 1;
    pbVar3 = pbVar3 + 1;
    if (*param_1 == 0) {
      dVar5 = (double)charLength(this,*param_4,(uint)bVar1,true);
      *param_2 = (float)dVar5;
    }
    else {
      dVar5 = (double)charLength(this,*param_4,(uint)bVar1,false);
      *param_2 = (float)((double)*param_2 + dVar5);
    }
    *param_1 = *param_1 + 1;
  }
  param_3[*param_5] = (int)(f_op_msg_mng::0_5 + *param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall fopMsgM_msgDataProc_c::tag_len_rescue(int *,
                                                    float *,
                                                    int *,
                                                    int *,
                                                    int *) */

void __thiscall
fopMsgM_msgDataProc_c::tag_len_rescue
          (fopMsgM_msgDataProc_c *this,int *param_1,float *param_2,int *param_3,int *param_4,
          int *param_5)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  double dVar4;
  byte local_48 [40];
  
  f_op_msg_mng::fopMsgM_int_to_char
            (local_48,(int)(short)d_com_inf_game::g_dComIfG_gameInfo.mCurrAuctionItemNameMsgID,0);
  MSL_C.PPCEABI.bare.H::strcat((char *)local_48,"");
  pbVar2 = local_48;
  pbVar3 = pbVar2;
  while (*pbVar3 != 0) {
    bVar1 = *pbVar2;
    pbVar3 = pbVar3 + 1;
    pbVar2 = pbVar2 + 1;
    if (*param_1 == 0) {
      dVar4 = (double)charLength(this,*param_4,(uint)bVar1,true);
      *param_2 = (float)dVar4;
    }
    else {
      dVar4 = (double)charLength(this,*param_4,(uint)bVar1,false);
      *param_2 = (float)((double)*param_2 + dVar4);
    }
    *param_1 = *param_1 + 1;
  }
  param_3[*param_5] = (int)(f_op_msg_mng::0_5 + *param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall fopMsgM_msgDataProc_c::tag_len_forest_timer(int *,
                                                          float *,
                                                          int *,
                                                          int *,
                                                          int *) */

void __thiscall
fopMsgM_msgDataProc_c::tag_len_forest_timer
          (fopMsgM_msgDataProc_c *this,int *param_1,float *param_2,int *param_3,int *param_4,
          int *param_5)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  uint uVar4;
  byte *pbVar5;
  double dVar6;
  byte local_48 [40];
  
  uVar2 = dSv_player_item_record_c::getTimer
                    (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord);
  uVar4 = (uVar2 & 0xffff) / 0x708;
  f_op_msg_mng::fopMsgM_int_to_char(local_48,uVar4,0);
  MSL_C.PPCEABI.bare.H::strcat((char *)local_48,":");
  uVar2 = dSv_player_item_record_c::getTimer
                    (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord);
  uVar2 = ((uVar2 & 0xffff) % 0x708) / 0x1e;
  if ((uVar4 == 0) && (uVar2 == 0)) {
    uVar2 = 1;
  }
  f_op_msg_mng::fopMsgM_int_to_char2(local_48,uVar2);
  MSL_C.PPCEABI.bare.H::strcat((char *)local_48,"");
  pbVar3 = local_48;
  pbVar5 = pbVar3;
  while (*pbVar5 != 0) {
    bVar1 = *pbVar3;
    pbVar5 = pbVar5 + 1;
    pbVar3 = pbVar3 + 1;
    if (*param_1 == 0) {
      dVar6 = (double)charLength(this,*param_4,(uint)bVar1,true);
      *param_2 = (float)dVar6;
    }
    else {
      dVar6 = (double)charLength(this,*param_4,(uint)bVar1,false);
      *param_2 = (float)((double)*param_2 + dVar6);
    }
    *param_1 = *param_1 + 1;
  }
  param_3[*param_5] = (int)(f_op_msg_mng::0_5 + *param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall fopMsgM_msgDataProc_c::tag_len_birdman(int *,
                                                     float *,
                                                     int *,
                                                     int *,
                                                     int *) */

void __thiscall
fopMsgM_msgDataProc_c::tag_len_birdman
          (fopMsgM_msgDataProc_c *this,int *param_1,float *param_2,int *param_3,int *param_4,
          int *param_5)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  double dVar5;
  byte local_48 [40];
  
  iVar2 = (int)(short)d_com_inf_game::g_dComIfG_gameInfo.mCurrAuctionItemNameMsgID;
  f_op_msg_mng::fopMsgM_int_to_char(local_48,iVar2,0);
  if (iVar2 == 1) {
    MSL_C.PPCEABI.bare.H::strcat((char *)local_48," yard");
  }
  else {
    MSL_C.PPCEABI.bare.H::strcat((char *)local_48," yards");
  }
  pbVar3 = local_48;
  pbVar4 = pbVar3;
  while (*pbVar4 != 0) {
    bVar1 = *pbVar3;
    pbVar4 = pbVar4 + 1;
    pbVar3 = pbVar3 + 1;
    if (*param_1 == 0) {
      dVar5 = (double)charLength(this,*param_4,(uint)bVar1,true);
      *param_2 = (float)dVar5;
    }
    else {
      dVar5 = (double)charLength(this,*param_4,(uint)bVar1,false);
      *param_2 = (float)((double)*param_2 + dVar5);
    }
    *param_1 = *param_1 + 1;
  }
  param_3[*param_5] = (int)(f_op_msg_mng::0_5 + *param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall fopMsgM_msgDataProc_c::tag_len_point(int *,
                                                   float *,
                                                   int *,
                                                   int *,
                                                   int *) */

void __thiscall
fopMsgM_msgDataProc_c::tag_len_point
          (fopMsgM_msgDataProc_c *this,int *param_1,float *param_2,int *param_3,int *param_4,
          int *param_5)

{
  byte bVar1;
  ushort uVar2;
  byte *pbVar3;
  byte *pbVar4;
  double dVar5;
  byte local_48 [40];
  
  uVar2 = dSv_event_c::getEventReg(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x86ff);
  f_op_msg_mng::fopMsgM_int_to_char(local_48,uVar2 & 0xff,0);
  if ((uVar2 & 0xff) == 1) {
    MSL_C.PPCEABI.bare.H::strcat((char *)local_48," point");
  }
  else {
    MSL_C.PPCEABI.bare.H::strcat((char *)local_48," points");
  }
  pbVar3 = local_48;
  pbVar4 = pbVar3;
  while (*pbVar4 != 0) {
    bVar1 = *pbVar3;
    pbVar4 = pbVar4 + 1;
    pbVar3 = pbVar3 + 1;
    if (*param_1 == 0) {
      dVar5 = (double)charLength(this,*param_4,(uint)bVar1,true);
      *param_2 = (float)dVar5;
    }
    else {
      dVar5 = (double)charLength(this,*param_4,(uint)bVar1,false);
      *param_2 = (float)((double)*param_2 + dVar5);
    }
    *param_1 = *param_1 + 1;
  }
  param_3[*param_5] = (int)(f_op_msg_mng::0_5 + *param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall fopMsgM_msgDataProc_c::tag_len_get_pendant(int *,
                                                         float *,
                                                         int *,
                                                         int *,
                                                         int *) */

void __thiscall
fopMsgM_msgDataProc_c::tag_len_get_pendant
          (fopMsgM_msgDataProc_c *this,int *param_1,float *param_2,int *param_3,int *param_4,
          int *param_5)

{
  byte bVar1;
  char cVar2;
  byte *pbVar3;
  byte *pbVar4;
  double dVar5;
  byte local_48 [40];
  
  cVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItemRecord._7_1_;
  f_op_msg_mng::fopMsgM_int_to_char
            (local_48,d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItemRecord._7_1_,
             0);
  if (cVar2 == '\x01') {
    MSL_C.PPCEABI.bare.H::strcat((char *)local_48,"");
  }
  else {
    MSL_C.PPCEABI.bare.H::strcat((char *)local_48,"");
  }
  pbVar3 = local_48;
  pbVar4 = pbVar3;
  while (*pbVar4 != 0) {
    bVar1 = *pbVar3;
    pbVar4 = pbVar4 + 1;
    pbVar3 = pbVar3 + 1;
    if (*param_1 == 0) {
      dVar5 = (double)charLength(this,*param_4,(uint)bVar1,true);
      *param_2 = (float)dVar5;
    }
    else {
      dVar5 = (double)charLength(this,*param_4,(uint)bVar1,false);
      *param_2 = (float)((double)*param_2 + dVar5);
    }
    *param_1 = *param_1 + 1;
  }
  param_3[*param_5] = (int)(f_op_msg_mng::0_5 + *param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall fopMsgM_msgDataProc_c::tag_len_rev_pendant(int *,
                                                         float *,
                                                         int *,
                                                         int *,
                                                         int *) */

void __thiscall
fopMsgM_msgDataProc_c::tag_len_rev_pendant
          (fopMsgM_msgDataProc_c *this,int *param_1,float *param_2,int *param_3,int *param_4,
          int *param_5)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  byte *pbVar4;
  byte *pbVar5;
  double dVar6;
  byte local_48 [40];
  
  uVar2 = dSv_event_c::getEventReg(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0xc0ff);
  uVar3 = dSv_event_c::getEventReg(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0xc0ff);
  f_op_msg_mng::fopMsgM_int_to_char(local_48,uVar3 & 0xff,0);
  if ((uVar2 & 0xff) == 1) {
    MSL_C.PPCEABI.bare.H::strcat((char *)local_48,"");
  }
  else {
    MSL_C.PPCEABI.bare.H::strcat((char *)local_48,"");
  }
  pbVar4 = local_48;
  pbVar5 = pbVar4;
  while (*pbVar5 != 0) {
    bVar1 = *pbVar4;
    pbVar5 = pbVar5 + 1;
    pbVar4 = pbVar4 + 1;
    if (*param_1 == 0) {
      dVar6 = (double)charLength(this,*param_4,(uint)bVar1,true);
      *param_2 = (float)dVar6;
    }
    else {
      dVar6 = (double)charLength(this,*param_4,(uint)bVar1,false);
      *param_2 = (float)((double)*param_2 + dVar6);
    }
    *param_1 = *param_1 + 1;
  }
  param_3[*param_5] = (int)(f_op_msg_mng::0_5 + *param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall fopMsgM_msgDataProc_c::tag_len_pig_timer(int *,
                                                       float *,
                                                       int *,
                                                       int *,
                                                       int *) */

void __thiscall
fopMsgM_msgDataProc_c::tag_len_pig_timer
          (fopMsgM_msgDataProc_c *this,int *param_1,float *param_2,int *param_3,int *param_4,
          int *param_5)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  double dVar6;
  byte local_48 [40];
  
  iVar2 = (int)d_com_inf_game::g_dComIfG_gameInfo._23490_2_;
  f_op_msg_mng::fopMsgM_int_to_char(local_48,iVar2 / 0x708,0);
  MSL_C.PPCEABI.bare.H::strcat((char *)local_48,":");
  iVar3 = ((int)d_com_inf_game::g_dComIfG_gameInfo._23490_2_ % 0x708) / 0x1e;
  if ((iVar2 / 0x708 == 0) && (iVar3 == 0)) {
    iVar3 = 1;
  }
  f_op_msg_mng::fopMsgM_int_to_char2(local_48,iVar3);
  MSL_C.PPCEABI.bare.H::strcat((char *)local_48,"");
  pbVar4 = local_48;
  pbVar5 = pbVar4;
  while (*pbVar5 != 0) {
    bVar1 = *pbVar4;
    pbVar5 = pbVar5 + 1;
    pbVar4 = pbVar4 + 1;
    if (*param_1 == 0) {
      dVar6 = (double)charLength(this,*param_4,(uint)bVar1,true);
      *param_2 = (float)dVar6;
    }
    else {
      dVar6 = (double)charLength(this,*param_4,(uint)bVar1,false);
      *param_2 = (float)((double)*param_2 + dVar6);
    }
    *param_1 = *param_1 + 1;
  }
  param_3[*param_5] = (int)(f_op_msg_mng::0_5 + *param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall fopMsgM_msgDataProc_c::tag_len_get_bomb(int *,
                                                      float *,
                                                      int *,
                                                      int *,
                                                      int *) */

void __thiscall
fopMsgM_msgDataProc_c::tag_len_get_bomb
          (fopMsgM_msgDataProc_c *this,int *param_1,float *param_2,int *param_3,int *param_4,
          int *param_5)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  double dVar4;
  byte local_48 [40];
  
  bVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax.field_0x2;
  f_op_msg_mng::fopMsgM_int_to_char
            (local_48,d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax.field_0x2,0)
  ;
  if (bVar1 == 1) {
    MSL_C.PPCEABI.bare.H::strcat((char *)local_48," bomb");
  }
  else {
    MSL_C.PPCEABI.bare.H::strcat((char *)local_48," bombs");
  }
  pbVar2 = local_48;
  pbVar3 = pbVar2;
  while (*pbVar3 != 0) {
    bVar1 = *pbVar2;
    pbVar3 = pbVar3 + 1;
    pbVar2 = pbVar2 + 1;
    if (*param_1 == 0) {
      dVar4 = (double)charLength(this,*param_4,(uint)bVar1,true);
      *param_2 = (float)dVar4;
    }
    else {
      dVar4 = (double)charLength(this,*param_4,(uint)bVar1,false);
      *param_2 = (float)((double)*param_2 + dVar4);
    }
    *param_1 = *param_1 + 1;
  }
  param_3[*param_5] = (int)(f_op_msg_mng::0_5 + *param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall fopMsgM_msgDataProc_c::tag_len_get_arrow(int *,
                                                       float *,
                                                       int *,
                                                       int *,
                                                       int *) */

void __thiscall
fopMsgM_msgDataProc_c::tag_len_get_arrow
          (fopMsgM_msgDataProc_c *this,int *param_1,float *param_2,int *param_3,int *param_4,
          int *param_5)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  double dVar4;
  byte local_48 [40];
  
  bVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax.field_0x1;
  f_op_msg_mng::fopMsgM_int_to_char
            (local_48,d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax.field_0x1,0)
  ;
  if (bVar1 == 1) {
    MSL_C.PPCEABI.bare.H::strcat((char *)local_48," arrow");
  }
  else {
    MSL_C.PPCEABI.bare.H::strcat((char *)local_48," arrows");
  }
  pbVar2 = local_48;
  pbVar3 = pbVar2;
  while (*pbVar3 != 0) {
    bVar1 = *pbVar2;
    pbVar3 = pbVar3 + 1;
    pbVar2 = pbVar2 + 1;
    if (*param_1 == 0) {
      dVar4 = (double)charLength(this,*param_4,(uint)bVar1,true);
      *param_2 = (float)dVar4;
    }
    else {
      dVar4 = (double)charLength(this,*param_4,(uint)bVar1,false);
      *param_2 = (float)((double)*param_2 + dVar4);
    }
    *param_1 = *param_1 + 1;
  }
  param_3[*param_5] = (int)(f_op_msg_mng::0_5 + *param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall fopMsgM_msgDataProc_c::tag_len_stock_bokobaba(int *,
                                                            float *,
                                                            int *,
                                                            int *,
                                                            int *) */

void __thiscall
fopMsgM_msgDataProc_c::tag_len_stock_bokobaba
          (fopMsgM_msgDataProc_c *this,int *param_1,float *param_2,int *param_3,int *param_4,
          int *param_5)

{
  byte bVar1;
  char cVar2;
  byte *pbVar3;
  byte *pbVar4;
  double dVar5;
  byte local_48 [40];
  
  cVar2 = daNpc_Bs1_c::m_tag_buy_item;
  f_op_msg_mng::fopMsgM_int_to_char(local_48,daNpc_Bs1_c::m_tag_buy_item,0);
  if (cVar2 == '\x01') {
    MSL_C.PPCEABI.bare.H::strcat((char *)local_48," seed");
  }
  else {
    MSL_C.PPCEABI.bare.H::strcat((char *)local_48," seeds");
  }
  pbVar3 = local_48;
  pbVar4 = pbVar3;
  while (*pbVar4 != 0) {
    bVar1 = *pbVar3;
    pbVar4 = pbVar4 + 1;
    pbVar3 = pbVar3 + 1;
    if (*param_1 == 0) {
      dVar5 = (double)charLength(this,*param_4,(uint)bVar1,true);
      *param_2 = (float)dVar5;
    }
    else {
      dVar5 = (double)charLength(this,*param_4,(uint)bVar1,false);
      *param_2 = (float)((double)*param_2 + dVar5);
    }
    *param_1 = *param_1 + 1;
  }
  param_3[*param_5] = (int)(f_op_msg_mng::0_5 + *param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall fopMsgM_msgDataProc_c::tag_len_stock_dokuro(int *,
                                                          float *,
                                                          int *,
                                                          int *,
                                                          int *) */

void __thiscall
fopMsgM_msgDataProc_c::tag_len_stock_dokuro
          (fopMsgM_msgDataProc_c *this,int *param_1,float *param_2,int *param_3,int *param_4,
          int *param_5)

{
  byte bVar1;
  char cVar2;
  byte *pbVar3;
  byte *pbVar4;
  double dVar5;
  byte local_48 [40];
  
  cVar2 = daNpc_Bs1_c::m_tag_buy_item;
  f_op_msg_mng::fopMsgM_int_to_char(local_48,daNpc_Bs1_c::m_tag_buy_item,0);
  if (cVar2 == '\x01') {
    MSL_C.PPCEABI.bare.H::strcat((char *)local_48," neckalce");
  }
  else {
    MSL_C.PPCEABI.bare.H::strcat((char *)local_48," neckalces");
  }
  pbVar3 = local_48;
  pbVar4 = pbVar3;
  while (*pbVar4 != 0) {
    bVar1 = *pbVar3;
    pbVar4 = pbVar4 + 1;
    pbVar3 = pbVar3 + 1;
    if (*param_1 == 0) {
      dVar5 = (double)charLength(this,*param_4,(uint)bVar1,true);
      *param_2 = (float)dVar5;
    }
    else {
      dVar5 = (double)charLength(this,*param_4,(uint)bVar1,false);
      *param_2 = (float)((double)*param_2 + dVar5);
    }
    *param_1 = *param_1 + 1;
  }
  param_3[*param_5] = (int)(f_op_msg_mng::0_5 + *param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall fopMsgM_msgDataProc_c::tag_len_stock_chuchu(int *,
                                                          float *,
                                                          int *,
                                                          int *,
                                                          int *) */

void __thiscall
fopMsgM_msgDataProc_c::tag_len_stock_chuchu
          (fopMsgM_msgDataProc_c *this,int *param_1,float *param_2,int *param_3,int *param_4,
          int *param_5)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  double dVar4;
  byte local_48 [40];
  
  f_op_msg_mng::fopMsgM_int_to_char(local_48,daNpc_Bs1_c::m_tag_buy_item,0);
  MSL_C.PPCEABI.bare.H::strcat((char *)local_48,"");
  pbVar2 = local_48;
  pbVar3 = pbVar2;
  while (*pbVar3 != 0) {
    bVar1 = *pbVar2;
    pbVar3 = pbVar3 + 1;
    pbVar2 = pbVar2 + 1;
    if (*param_1 == 0) {
      dVar4 = (double)charLength(this,*param_4,(uint)bVar1,true);
      *param_2 = (float)dVar4;
    }
    else {
      dVar4 = (double)charLength(this,*param_4,(uint)bVar1,false);
      *param_2 = (float)((double)*param_2 + dVar4);
    }
    *param_1 = *param_1 + 1;
  }
  param_3[*param_5] = (int)(f_op_msg_mng::0_5 + *param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall fopMsgM_msgDataProc_c::tag_len_stock_pendant(int *,
                                                           float *,
                                                           int *,
                                                           int *,
                                                           int *) */

void __thiscall
fopMsgM_msgDataProc_c::tag_len_stock_pendant
          (fopMsgM_msgDataProc_c *this,int *param_1,float *param_2,int *param_3,int *param_4,
          int *param_5)

{
  byte bVar1;
  char cVar2;
  byte *pbVar3;
  byte *pbVar4;
  double dVar5;
  byte local_48 [40];
  
  cVar2 = daNpc_Bs1_c::m_tag_buy_item;
  f_op_msg_mng::fopMsgM_int_to_char(local_48,daNpc_Bs1_c::m_tag_buy_item,0);
  if (cVar2 == '\x01') {
    MSL_C.PPCEABI.bare.H::strcat((char *)local_48," necklace");
  }
  else {
    MSL_C.PPCEABI.bare.H::strcat((char *)local_48," necklaces");
  }
  pbVar3 = local_48;
  pbVar4 = pbVar3;
  while (*pbVar4 != 0) {
    bVar1 = *pbVar3;
    pbVar4 = pbVar4 + 1;
    pbVar3 = pbVar3 + 1;
    if (*param_1 == 0) {
      dVar5 = (double)charLength(this,*param_4,(uint)bVar1,true);
      *param_2 = (float)dVar5;
    }
    else {
      dVar5 = (double)charLength(this,*param_4,(uint)bVar1,false);
      *param_2 = (float)((double)*param_2 + dVar5);
    }
    *param_1 = *param_1 + 1;
  }
  param_3[*param_5] = (int)(f_op_msg_mng::0_5 + *param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall fopMsgM_msgDataProc_c::tag_len_stock_hane(int *,
                                                        float *,
                                                        int *,
                                                        int *,
                                                        int *) */

void __thiscall
fopMsgM_msgDataProc_c::tag_len_stock_hane
          (fopMsgM_msgDataProc_c *this,int *param_1,float *param_2,int *param_3,int *param_4,
          int *param_5)

{
  byte bVar1;
  char cVar2;
  byte *pbVar3;
  byte *pbVar4;
  double dVar5;
  byte local_48 [40];
  
  cVar2 = daNpc_Bs1_c::m_tag_buy_item;
  f_op_msg_mng::fopMsgM_int_to_char(local_48,daNpc_Bs1_c::m_tag_buy_item,0);
  if (cVar2 == '\x01') {
    MSL_C.PPCEABI.bare.H::strcat((char *)local_48," feather");
  }
  else {
    MSL_C.PPCEABI.bare.H::strcat((char *)local_48," feathers");
  }
  pbVar3 = local_48;
  pbVar4 = pbVar3;
  while (*pbVar4 != 0) {
    bVar1 = *pbVar3;
    pbVar4 = pbVar4 + 1;
    pbVar3 = pbVar3 + 1;
    if (*param_1 == 0) {
      dVar5 = (double)charLength(this,*param_4,(uint)bVar1,true);
      *param_2 = (float)dVar5;
    }
    else {
      dVar5 = (double)charLength(this,*param_4,(uint)bVar1,false);
      *param_2 = (float)((double)*param_2 + dVar5);
    }
    *param_1 = *param_1 + 1;
  }
  param_3[*param_5] = (int)(f_op_msg_mng::0_5 + *param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall fopMsgM_msgDataProc_c::tag_len_stock_kenshi(int *,
                                                          float *,
                                                          int *,
                                                          int *,
                                                          int *) */

void __thiscall
fopMsgM_msgDataProc_c::tag_len_stock_kenshi
          (fopMsgM_msgDataProc_c *this,int *param_1,float *param_2,int *param_3,int *param_4,
          int *param_5)

{
  byte bVar1;
  char cVar2;
  byte *pbVar3;
  byte *pbVar4;
  double dVar5;
  byte local_48 [40];
  
  cVar2 = daNpc_Bs1_c::m_tag_buy_item;
  f_op_msg_mng::fopMsgM_int_to_char(local_48,daNpc_Bs1_c::m_tag_buy_item,0);
  if (cVar2 == '\x01') {
    MSL_C.PPCEABI.bare.H::strcat((char *)local_48," crest");
  }
  else {
    MSL_C.PPCEABI.bare.H::strcat((char *)local_48," crests");
  }
  pbVar3 = local_48;
  pbVar4 = pbVar3;
  while (*pbVar4 != 0) {
    bVar1 = *pbVar3;
    pbVar4 = pbVar4 + 1;
    pbVar3 = pbVar3 + 1;
    if (*param_1 == 0) {
      dVar5 = (double)charLength(this,*param_4,(uint)bVar1,true);
      *param_2 = (float)dVar5;
    }
    else {
      dVar5 = (double)charLength(this,*param_4,(uint)bVar1,false);
      *param_2 = (float)((double)*param_2 + dVar5);
    }
    *param_1 = *param_1 + 1;
  }
  param_3[*param_5] = (int)(f_op_msg_mng::0_5 + *param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall fopMsgM_msgDataProc_c::tag_len_terry_rupee(int *,
                                                         float *,
                                                         int *,
                                                         int *,
                                                         int *) */

void __thiscall
fopMsgM_msgDataProc_c::tag_len_terry_rupee
          (fopMsgM_msgDataProc_c *this,int *param_1,float *param_2,int *param_3,int *param_4,
          int *param_5)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  double dVar5;
  byte local_48 [40];
  
  iVar2 = (int)_m_tag_pay_rupee;
  f_op_msg_mng::fopMsgM_int_to_char(local_48,iVar2,0);
  if (iVar2 == 1) {
    MSL_C.PPCEABI.bare.H::strcat((char *)local_48," Rupee");
  }
  else {
    MSL_C.PPCEABI.bare.H::strcat((char *)local_48," Rupees");
  }
  pbVar3 = local_48;
  pbVar4 = pbVar3;
  while (*pbVar4 != 0) {
    bVar1 = *pbVar3;
    pbVar4 = pbVar4 + 1;
    pbVar3 = pbVar3 + 1;
    if (*param_1 == 0) {
      dVar5 = (double)charLength(this,*param_4,(uint)bVar1,true);
      *param_2 = (float)dVar5;
    }
    else {
      dVar5 = (double)charLength(this,*param_4,(uint)bVar1,false);
      *param_2 = (float)((double)*param_2 + dVar5);
    }
    *param_1 = *param_1 + 1;
  }
  param_3[*param_5] = (int)(f_op_msg_mng::0_5 + *param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall fopMsgM_msgDataProc_c::tag_len_input_bokobaba(int *,
                                                            float *,
                                                            int *,
                                                            int *,
                                                            int *) */

void __thiscall
fopMsgM_msgDataProc_c::tag_len_input_bokobaba
          (fopMsgM_msgDataProc_c *this,int *param_1,float *param_2,int *param_3,int *param_4,
          int *param_5)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  double dVar4;
  byte local_48 [40];
  
  if (*param_5 != this->field_0x130) {
    this->field_0x130 = *param_5;
  }
  MSL_C.PPCEABI.bare.H::strcpy((char *)local_48,"00 seed(s)");
  pbVar2 = local_48;
  pbVar3 = pbVar2;
  while (*pbVar3 != 0) {
    bVar1 = *pbVar2;
    pbVar3 = pbVar3 + 1;
    pbVar2 = pbVar2 + 1;
    if (*param_1 == 0) {
      dVar4 = (double)charLength(this,*param_4,(uint)bVar1,true);
      *param_2 = (float)dVar4;
    }
    else {
      dVar4 = (double)charLength(this,*param_4,(uint)bVar1,false);
      *param_2 = (float)((double)*param_2 + dVar4);
    }
    *param_1 = *param_1 + 1;
  }
  param_3[*param_5] = (int)(f_op_msg_mng::0_5 + *param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall fopMsgM_msgDataProc_c::tag_len_input_dokuro(int *,
                                                          float *,
                                                          int *,
                                                          int *,
                                                          int *) */

void __thiscall
fopMsgM_msgDataProc_c::tag_len_input_dokuro
          (fopMsgM_msgDataProc_c *this,int *param_1,float *param_2,int *param_3,int *param_4,
          int *param_5)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  double dVar4;
  byte local_48 [40];
  
  if (*param_5 != this->field_0x130) {
    this->field_0x130 = *param_5;
  }
  MSL_C.PPCEABI.bare.H::strcpy((char *)local_48,"00 necklace(s)");
  pbVar2 = local_48;
  pbVar3 = pbVar2;
  while (*pbVar3 != 0) {
    bVar1 = *pbVar2;
    pbVar3 = pbVar3 + 1;
    pbVar2 = pbVar2 + 1;
    if (*param_1 == 0) {
      dVar4 = (double)charLength(this,*param_4,(uint)bVar1,true);
      *param_2 = (float)dVar4;
    }
    else {
      dVar4 = (double)charLength(this,*param_4,(uint)bVar1,false);
      *param_2 = (float)((double)*param_2 + dVar4);
    }
    *param_1 = *param_1 + 1;
  }
  param_3[*param_5] = (int)(f_op_msg_mng::0_5 + *param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall fopMsgM_msgDataProc_c::tag_len_input_chuchu(int *,
                                                          float *,
                                                          int *,
                                                          int *,
                                                          int *) */

void __thiscall
fopMsgM_msgDataProc_c::tag_len_input_chuchu
          (fopMsgM_msgDataProc_c *this,int *param_1,float *param_2,int *param_3,int *param_4,
          int *param_5)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  double dVar4;
  byte local_48 [40];
  
  if (*param_5 != this->field_0x130) {
    this->field_0x130 = *param_5;
  }
  MSL_C.PPCEABI.bare.H::strcpy((char *)local_48,"00 ");
  pbVar2 = local_48;
  pbVar3 = pbVar2;
  while (*pbVar3 != 0) {
    bVar1 = *pbVar2;
    pbVar3 = pbVar3 + 1;
    pbVar2 = pbVar2 + 1;
    if (*param_1 == 0) {
      dVar4 = (double)charLength(this,*param_4,(uint)bVar1,true);
      *param_2 = (float)dVar4;
    }
    else {
      dVar4 = (double)charLength(this,*param_4,(uint)bVar1,false);
      *param_2 = (float)((double)*param_2 + dVar4);
    }
    *param_1 = *param_1 + 1;
  }
  param_3[*param_5] = (int)(f_op_msg_mng::0_5 + *param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall fopMsgM_msgDataProc_c::tag_len_input_pendant(int *,
                                                           float *,
                                                           int *,
                                                           int *,
                                                           int *) */

void __thiscall
fopMsgM_msgDataProc_c::tag_len_input_pendant
          (fopMsgM_msgDataProc_c *this,int *param_1,float *param_2,int *param_3,int *param_4,
          int *param_5)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  double dVar4;
  byte local_48 [40];
  
  if (*param_5 != this->field_0x130) {
    this->field_0x130 = *param_5;
  }
  MSL_C.PPCEABI.bare.H::strcpy((char *)local_48,"00 pendant(s)");
  pbVar2 = local_48;
  pbVar3 = pbVar2;
  while (*pbVar3 != 0) {
    bVar1 = *pbVar2;
    pbVar3 = pbVar3 + 1;
    pbVar2 = pbVar2 + 1;
    if (*param_1 == 0) {
      dVar4 = (double)charLength(this,*param_4,(uint)bVar1,true);
      *param_2 = (float)dVar4;
    }
    else {
      dVar4 = (double)charLength(this,*param_4,(uint)bVar1,false);
      *param_2 = (float)((double)*param_2 + dVar4);
    }
    *param_1 = *param_1 + 1;
  }
  param_3[*param_5] = (int)(f_op_msg_mng::0_5 + *param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall fopMsgM_msgDataProc_c::tag_len_input_hane(int *,
                                                        float *,
                                                        int *,
                                                        int *,
                                                        int *) */

void __thiscall
fopMsgM_msgDataProc_c::tag_len_input_hane
          (fopMsgM_msgDataProc_c *this,int *param_1,float *param_2,int *param_3,int *param_4,
          int *param_5)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  double dVar4;
  byte local_48 [40];
  
  if (*param_5 != this->field_0x130) {
    this->field_0x130 = *param_5;
  }
  MSL_C.PPCEABI.bare.H::strcpy((char *)local_48,"00 feather(s)");
  pbVar2 = local_48;
  pbVar3 = pbVar2;
  while (*pbVar3 != 0) {
    bVar1 = *pbVar2;
    pbVar3 = pbVar3 + 1;
    pbVar2 = pbVar2 + 1;
    if (*param_1 == 0) {
      dVar4 = (double)charLength(this,*param_4,(uint)bVar1,true);
      *param_2 = (float)dVar4;
    }
    else {
      dVar4 = (double)charLength(this,*param_4,(uint)bVar1,false);
      *param_2 = (float)((double)*param_2 + dVar4);
    }
    *param_1 = *param_1 + 1;
  }
  param_3[*param_5] = (int)(f_op_msg_mng::0_5 + *param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall fopMsgM_msgDataProc_c::tag_len_input_kenshi(int *,
                                                          float *,
                                                          int *,
                                                          int *,
                                                          int *) */

void __thiscall
fopMsgM_msgDataProc_c::tag_len_input_kenshi
          (fopMsgM_msgDataProc_c *this,int *param_1,float *param_2,int *param_3,int *param_4,
          int *param_5)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  double dVar4;
  byte local_48 [40];
  
  if (*param_5 != this->field_0x130) {
    this->field_0x130 = *param_5;
  }
  MSL_C.PPCEABI.bare.H::strcpy((char *)local_48,"00 crest(s)");
  pbVar2 = local_48;
  pbVar3 = pbVar2;
  while (*pbVar3 != 0) {
    bVar1 = *pbVar2;
    pbVar3 = pbVar3 + 1;
    pbVar2 = pbVar2 + 1;
    if (*param_1 == 0) {
      dVar4 = (double)charLength(this,*param_4,(uint)bVar1,true);
      *param_2 = (float)dVar4;
    }
    else {
      dVar4 = (double)charLength(this,*param_4,(uint)bVar1,false);
      *param_2 = (float)((double)*param_2 + dVar4);
    }
    *param_1 = *param_1 + 1;
  }
  param_3[*param_5] = (int)(f_op_msg_mng::0_5 + *param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall fopMsgM_msgDataProc_c::tag_kaisen_game(void) */

void __thiscall fopMsgM_msgDataProc_c::tag_kaisen_game(fopMsgM_msgDataProc_c *this)

{
  byte bVar1;
  ushort uVar2;
  byte *pbVar3;
  byte *pbVar4;
  double dVar5;
  char acStack64 [12];
  byte local_34 [12];
  undefined4 local_28;
  uint uStack36;
  
  uVar2 = dSv_event_c::getEventReg(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0xbeff);
  f_op_msg_mng::fopMsgM_int_to_char(local_34,uVar2 & 0xff,0);
  pbVar3 = local_34;
  pbVar4 = pbVar3;
  while (*pbVar4 != 0) {
    bVar1 = *pbVar3;
    pbVar4 = pbVar4 + 1;
    pbVar3 = pbVar3 + 1;
    if (this->field_0x150 == 0) {
      dVar5 = (double)charLength(this,this->field_0x148,(uint)bVar1,true);
      this->field_0x14 = (float)dVar5;
    }
    else {
      dVar5 = (double)charLength(this,this->field_0x148,(uint)bVar1,false);
      this->field_0x14 = (float)((double)this->field_0x14 + dVar5);
    }
    this->field_0x150 = this->field_0x150 + 1;
  }
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x60,(char *)local_34);
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x68,(char *)local_34);
  if (*(char *)&this->field_0x294 == '\x01') {
    uStack36 = *(uint *)(&this->field_0x108 + this->field_0x130 * 4) ^ 0x80000000;
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,uStack36) - f_op_msg_mng::_4895) + this->field_0x14;
  }
  else {
    uStack36 = *(uint *)(&this->field_0xf8 + this->field_0x130 * 4) ^ 0x80000000;
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,uStack36) - f_op_msg_mng::_4895) + this->field_0x14;
  }
  local_28 = 0x43300000;
  dSv_event_c::getEventReg(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0xbeff);
  MSL_C.PPCEABI.bare.H::strcpy(acStack64,"");
  getRubyString(this,*(char **)&this->field_0x60,*(char **)&this->field_0x68,
                *(char **)&this->field_0x64,*(char **)&this->field_0x6c,acStack64,"",
                &this->field_0x20,&this->field_0x24,&this->field_0x150);
  this->field_0x118 =
       this->field_0x118 + (int)*(char *)(*(int *)&this->field_0x3c + this->field_0x118 + 1);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall fopMsgM_msgDataProc_c::tag_rupee(void) */

void __thiscall fopMsgM_msgDataProc_c::tag_rupee(fopMsgM_msgDataProc_c *this)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  double dVar5;
  byte local_38 [40];
  
  iVar2 = (int)(short)d_com_inf_game::g_dComIfG_gameInfo.mCurrAuctionItemNameMsgID;
  f_op_msg_mng::fopMsgM_int_to_char(local_38,iVar2,0);
  if (iVar2 == 1) {
    MSL_C.PPCEABI.bare.H::strcat((char *)local_38," Rupee");
  }
  else {
    MSL_C.PPCEABI.bare.H::strcat((char *)local_38," Rupees");
  }
  pbVar3 = local_38;
  pbVar4 = pbVar3;
  while (*pbVar4 != 0) {
    bVar1 = *pbVar3;
    pbVar4 = pbVar4 + 1;
    pbVar3 = pbVar3 + 1;
    if (this->field_0x150 == 0) {
      dVar5 = (double)charLength(this,this->field_0x148,(uint)bVar1,true);
      this->field_0x14 = (float)dVar5;
    }
    else {
      dVar5 = (double)charLength(this,this->field_0x148,(uint)bVar1,false);
      this->field_0x14 = (float)((double)this->field_0x14 + dVar5);
    }
    this->field_0x150 = this->field_0x150 + 1;
  }
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x60,(char *)local_38);
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x68,(char *)local_38);
  if (*(char *)&this->field_0x294 == '\x01') {
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,
                                  *(uint *)(&this->field_0x108 + this->field_0x130 * 4) ^ 0x80000000
                                 ) - f_op_msg_mng::_4895) + this->field_0x14;
  }
  else {
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,
                                  *(uint *)(&this->field_0xf8 + this->field_0x130 * 4) ^ 0x80000000)
                - f_op_msg_mng::_4895) + this->field_0x14;
  }
  this->field_0x118 =
       this->field_0x118 + (int)*(char *)(*(int *)&this->field_0x3c + this->field_0x118 + 1);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall fopMsgM_msgDataProc_c::tag_num_input(void) */

void __thiscall fopMsgM_msgDataProc_c::tag_num_input(fopMsgM_msgDataProc_c *this)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  double dVar4;
  byte local_38 [8];
  char acStack48 [16];
  undefined4 local_20;
  uint uStack28;
  
  uStack28 = (this->field_0x148 + this->field_0x11c) * 3;
  *(undefined *)&this->field_0x294 = 3;
  iconSelect(this,this->field_0x148,'\x16');
  *(undefined *)&this->field_0x27c = 0x15;
  MSL_C.PPCEABI.bare.H::sprintf(acStack48,"\x1bCR[%d]",uStack28);
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x60,acStack48);
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x68,acStack48);
  uStack28 = uStack28 ^ 0x80000000;
  local_20 = 0x43300000;
  this->field_0x14 = (float)((double)CONCAT44(0x43300000,uStack28) - f_op_msg_mng::_4895);
  this->field_0x150 = this->field_0x150 + 3;
  MSL_C.PPCEABI.bare.H::strcpy((char *)local_38," Rupee(s)");
  pbVar2 = local_38;
  pbVar3 = pbVar2;
  while (*pbVar3 != 0) {
    bVar1 = *pbVar2;
    pbVar3 = pbVar3 + 1;
    pbVar2 = pbVar2 + 1;
    if (this->field_0x150 == 0) {
      dVar4 = (double)charLength(this,this->field_0x148,(uint)bVar1,true);
      this->field_0x14 = (float)dVar4;
    }
    else {
      dVar4 = (double)charLength(this,this->field_0x148,(uint)bVar1,false);
      this->field_0x14 = (float)((double)this->field_0x14 + dVar4);
    }
    this->field_0x150 = this->field_0x150 + 1;
  }
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x60,(char *)local_38);
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x68,(char *)local_38);
  if (*(char *)&this->field_0x294 == '\x01') {
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,
                                  *(uint *)(&this->field_0x108 + this->field_0x130 * 4) ^ 0x80000000
                                 ) - f_op_msg_mng::_4895) + this->field_0x14;
  }
  else {
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,
                                  *(uint *)(&this->field_0xf8 + this->field_0x130 * 4) ^ 0x80000000)
                - f_op_msg_mng::_4895) + this->field_0x14;
  }
  this->field_0x118 =
       this->field_0x118 + (int)*(char *)(*(int *)&this->field_0x3c + this->field_0x118 + 1);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall fopMsgM_msgDataProc_c::tag_sword_game(void) */

void __thiscall fopMsgM_msgDataProc_c::tag_sword_game(fopMsgM_msgDataProc_c *this)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  int iVar4;
  double dVar5;
  char acStack64 [12];
  byte local_34 [20];
  undefined4 local_20;
  uint uStack28;
  
  iVar4 = (int)(short)d_com_inf_game::g_dComIfG_gameInfo.mCurrAuctionItemNameMsgID;
  f_op_msg_mng::fopMsgM_int_to_char(local_34,iVar4,0);
  pbVar2 = local_34;
  pbVar3 = pbVar2;
  while (*pbVar3 != 0) {
    bVar1 = *pbVar2;
    pbVar3 = pbVar3 + 1;
    pbVar2 = pbVar2 + 1;
    if (this->field_0x150 == 0) {
      dVar5 = (double)charLength(this,this->field_0x148,(uint)bVar1,true);
      this->field_0x14 = (float)dVar5;
    }
    else {
      dVar5 = (double)charLength(this,this->field_0x148,(uint)bVar1,false);
      this->field_0x14 = (float)((double)this->field_0x14 + dVar5);
    }
    this->field_0x150 = this->field_0x150 + 1;
  }
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x60,(char *)local_34);
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x68,(char *)local_34);
  if (*(char *)&this->field_0x294 == '\x01') {
    uStack28 = *(uint *)(&this->field_0x108 + this->field_0x130 * 4) ^ 0x80000000;
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,uStack28) - f_op_msg_mng::_4895) + this->field_0x14;
  }
  else {
    uStack28 = *(uint *)(&this->field_0xf8 + this->field_0x130 * 4) ^ 0x80000000;
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,uStack28) - f_op_msg_mng::_4895) + this->field_0x14;
  }
  local_20 = 0x43300000;
  if (iVar4 == 1) {
    MSL_C.PPCEABI.bare.H::strcpy(acStack64," blow");
  }
  else {
    MSL_C.PPCEABI.bare.H::strcpy(acStack64," blows");
  }
  getRubyString(this,*(char **)&this->field_0x60,*(char **)&this->field_0x68,
                *(char **)&this->field_0x64,*(char **)&this->field_0x6c,acStack64,"",
                &this->field_0x20,&this->field_0x24,&this->field_0x150);
  this->field_0x118 =
       this->field_0x118 + (int)*(char *)(*(int *)&this->field_0x3c + this->field_0x118 + 1);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall fopMsgM_msgDataProc_c::tag_letter_game(void) */

void __thiscall fopMsgM_msgDataProc_c::tag_letter_game(fopMsgM_msgDataProc_c *this)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  double dVar4;
  byte local_38 [40];
  
  f_op_msg_mng::fopMsgM_int_to_char(local_38,(int)d_com_inf_game::g_dComIfG_gameInfo._23772_2_,0);
  pbVar2 = local_38;
  pbVar3 = pbVar2;
  while (*pbVar3 != 0) {
    bVar1 = *pbVar2;
    pbVar3 = pbVar3 + 1;
    pbVar2 = pbVar2 + 1;
    if (this->field_0x150 == 0) {
      dVar4 = (double)charLength(this,this->field_0x148,(uint)bVar1,true);
      this->field_0x14 = (float)dVar4;
    }
    else {
      dVar4 = (double)charLength(this,this->field_0x148,(uint)bVar1,false);
      this->field_0x14 = (float)((double)this->field_0x14 + dVar4);
    }
    this->field_0x150 = this->field_0x150 + 1;
  }
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x60,(char *)local_38);
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x68,(char *)local_38);
  if (*(char *)&this->field_0x294 == '\x01') {
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,
                                  *(uint *)(&this->field_0x108 + this->field_0x130 * 4) ^ 0x80000000
                                 ) - f_op_msg_mng::_4895) + this->field_0x14;
  }
  else {
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,
                                  *(uint *)(&this->field_0xf8 + this->field_0x130 * 4) ^ 0x80000000)
                - f_op_msg_mng::_4895) + this->field_0x14;
  }
  this->field_0x118 =
       this->field_0x118 + (int)*(char *)(*(int *)&this->field_0x3c + this->field_0x118 + 1);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall fopMsgM_msgDataProc_c::tag_letter_game_max(void) */

void __thiscall fopMsgM_msgDataProc_c::tag_letter_game_max(fopMsgM_msgDataProc_c *this)

{
  byte bVar1;
  ushort uVar2;
  byte *pbVar3;
  byte *pbVar4;
  double dVar5;
  byte local_38 [40];
  
  uVar2 = dSv_event_c::getEventReg(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x8aff);
  f_op_msg_mng::fopMsgM_int_to_char(local_38,uVar2 & 0xff,0);
  pbVar3 = local_38;
  pbVar4 = pbVar3;
  while (*pbVar4 != 0) {
    bVar1 = *pbVar3;
    pbVar4 = pbVar4 + 1;
    pbVar3 = pbVar3 + 1;
    if (this->field_0x150 == 0) {
      dVar5 = (double)charLength(this,this->field_0x148,(uint)bVar1,true);
      this->field_0x14 = (float)dVar5;
    }
    else {
      dVar5 = (double)charLength(this,this->field_0x148,(uint)bVar1,false);
      this->field_0x14 = (float)((double)this->field_0x14 + dVar5);
    }
    this->field_0x150 = this->field_0x150 + 1;
  }
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x60,(char *)local_38);
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x68,(char *)local_38);
  if (*(char *)&this->field_0x294 == '\x01') {
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,
                                  *(uint *)(&this->field_0x108 + this->field_0x130 * 4) ^ 0x80000000
                                 ) - f_op_msg_mng::_4895) + this->field_0x14;
  }
  else {
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,
                                  *(uint *)(&this->field_0xf8 + this->field_0x130 * 4) ^ 0x80000000)
                - f_op_msg_mng::_4895) + this->field_0x14;
  }
  this->field_0x118 =
       this->field_0x118 + (int)*(char *)(*(int *)&this->field_0x3c + this->field_0x118 + 1);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall fopMsgM_msgDataProc_c::tag_fish(void) */

void __thiscall fopMsgM_msgDataProc_c::tag_fish(fopMsgM_msgDataProc_c *this)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  double dVar4;
  byte local_38 [40];
  
  f_op_msg_mng::fopMsgM_int_to_char
            (local_38,(int)(short)d_com_inf_game::g_dComIfG_gameInfo.mCurrAuctionItemNameMsgID,0);
  pbVar2 = local_38;
  pbVar3 = pbVar2;
  while (*pbVar3 != 0) {
    bVar1 = *pbVar2;
    pbVar3 = pbVar3 + 1;
    pbVar2 = pbVar2 + 1;
    if (this->field_0x150 == 0) {
      dVar4 = (double)charLength(this,this->field_0x148,(uint)bVar1,true);
      this->field_0x14 = (float)dVar4;
    }
    else {
      dVar4 = (double)charLength(this,this->field_0x148,(uint)bVar1,false);
      this->field_0x14 = (float)((double)this->field_0x14 + dVar4);
    }
    this->field_0x150 = this->field_0x150 + 1;
  }
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x60,(char *)local_38);
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x68,(char *)local_38);
  if (*(char *)&this->field_0x294 == '\x01') {
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,
                                  *(uint *)(&this->field_0x108 + this->field_0x130 * 4) ^ 0x80000000
                                 ) - f_op_msg_mng::_4895) + this->field_0x14;
  }
  else {
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,
                                  *(uint *)(&this->field_0xf8 + this->field_0x130 * 4) ^ 0x80000000)
                - f_op_msg_mng::_4895) + this->field_0x14;
  }
  this->field_0x118 =
       this->field_0x118 + (int)*(char *)(*(int *)&this->field_0x3c + this->field_0x118 + 1);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall fopMsgM_msgDataProc_c::tag_fish_rupee(void) */

void __thiscall fopMsgM_msgDataProc_c::tag_fish_rupee(fopMsgM_msgDataProc_c *this)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  double dVar5;
  byte local_38 [40];
  
  iVar2 = (int)(short)d_com_inf_game::g_dComIfG_gameInfo.mCurrAuctionItemNameMsgID;
  f_op_msg_mng::fopMsgM_int_to_char(local_38,iVar2 * 10,0);
  if (iVar2 * 10 == 1) {
    MSL_C.PPCEABI.bare.H::strcat((char *)local_38," Rupee");
  }
  else {
    MSL_C.PPCEABI.bare.H::strcat((char *)local_38," Rupees");
  }
  pbVar3 = local_38;
  pbVar4 = pbVar3;
  while (*pbVar4 != 0) {
    bVar1 = *pbVar3;
    pbVar4 = pbVar4 + 1;
    pbVar3 = pbVar3 + 1;
    if (this->field_0x150 == 0) {
      dVar5 = (double)charLength(this,this->field_0x148,(uint)bVar1,true);
      this->field_0x14 = (float)dVar5;
    }
    else {
      dVar5 = (double)charLength(this,this->field_0x148,(uint)bVar1,false);
      this->field_0x14 = (float)((double)this->field_0x14 + dVar5);
    }
    this->field_0x150 = this->field_0x150 + 1;
  }
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x60,(char *)local_38);
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x68,(char *)local_38);
  if (*(char *)&this->field_0x294 == '\x01') {
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,
                                  *(uint *)(&this->field_0x108 + this->field_0x130 * 4) ^ 0x80000000
                                 ) - f_op_msg_mng::_4895) + this->field_0x14;
  }
  else {
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,
                                  *(uint *)(&this->field_0xf8 + this->field_0x130 * 4) ^ 0x80000000)
                - f_op_msg_mng::_4895) + this->field_0x14;
  }
  this->field_0x118 =
       this->field_0x118 + (int)*(char *)(*(int *)&this->field_0x3c + this->field_0x118 + 1);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall fopMsgM_msgDataProc_c::tag_letter(void) */

void __thiscall fopMsgM_msgDataProc_c::tag_letter(fopMsgM_msgDataProc_c *this)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  int iVar4;
  double dVar5;
  char acStack64 [12];
  byte local_34 [20];
  undefined4 local_20;
  uint uStack28;
  
  iVar4 = (int)(short)d_com_inf_game::g_dComIfG_gameInfo.mCurrAuctionItemNameMsgID;
  f_op_msg_mng::fopMsgM_int_to_char(local_34,iVar4,0);
  pbVar2 = local_34;
  pbVar3 = pbVar2;
  while (*pbVar3 != 0) {
    bVar1 = *pbVar2;
    pbVar3 = pbVar3 + 1;
    pbVar2 = pbVar2 + 1;
    if (this->field_0x150 == 0) {
      dVar5 = (double)charLength(this,this->field_0x148,(uint)bVar1,true);
      this->field_0x14 = (float)dVar5;
    }
    else {
      dVar5 = (double)charLength(this,this->field_0x148,(uint)bVar1,false);
      this->field_0x14 = (float)((double)this->field_0x14 + dVar5);
    }
    this->field_0x150 = this->field_0x150 + 1;
  }
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x60,(char *)local_34);
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x68,(char *)local_34);
  if (*(char *)&this->field_0x294 == '\x01') {
    uStack28 = *(uint *)(&this->field_0x108 + this->field_0x130 * 4) ^ 0x80000000;
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,uStack28) - f_op_msg_mng::_4895) + this->field_0x14;
  }
  else {
    uStack28 = *(uint *)(&this->field_0xf8 + this->field_0x130 * 4) ^ 0x80000000;
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,uStack28) - f_op_msg_mng::_4895) + this->field_0x14;
  }
  local_20 = 0x43300000;
  if (iVar4 == 1) {
    MSL_C.PPCEABI.bare.H::strcpy(acStack64," letter");
  }
  else {
    MSL_C.PPCEABI.bare.H::strcpy(acStack64," letters");
  }
  getRubyString(this,*(char **)&this->field_0x60,*(char **)&this->field_0x68,
                *(char **)&this->field_0x64,*(char **)&this->field_0x6c,acStack64,"",
                &this->field_0x20,&this->field_0x24,&this->field_0x150);
  this->field_0x118 =
       this->field_0x118 + (int)*(char *)(*(int *)&this->field_0x3c + this->field_0x118 + 1);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall fopMsgM_msgDataProc_c::tag_rescue(void) */

void __thiscall fopMsgM_msgDataProc_c::tag_rescue(fopMsgM_msgDataProc_c *this)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  double dVar4;
  byte local_30 [24];
  undefined4 local_18;
  uint uStack20;
  
  f_op_msg_mng::fopMsgM_int_to_char
            (local_30,(int)(short)d_com_inf_game::g_dComIfG_gameInfo.mCurrAuctionItemNameMsgID,0);
  pbVar2 = local_30;
  pbVar3 = pbVar2;
  while (*pbVar3 != 0) {
    bVar1 = *pbVar2;
    pbVar3 = pbVar3 + 1;
    pbVar2 = pbVar2 + 1;
    if (this->field_0x150 == 0) {
      dVar4 = (double)charLength(this,this->field_0x148,(uint)bVar1,true);
      this->field_0x14 = (float)dVar4;
    }
    else {
      dVar4 = (double)charLength(this,this->field_0x148,(uint)bVar1,false);
      this->field_0x14 = (float)((double)this->field_0x14 + dVar4);
    }
    this->field_0x150 = this->field_0x150 + 1;
  }
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x60,(char *)local_30);
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x68,(char *)local_30);
  if (*(char *)&this->field_0x294 == '\x01') {
    uStack20 = *(uint *)(&this->field_0x108 + this->field_0x130 * 4) ^ 0x80000000;
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,uStack20) - f_op_msg_mng::_4895) + this->field_0x14;
  }
  else {
    uStack20 = *(uint *)(&this->field_0xf8 + this->field_0x130 * 4) ^ 0x80000000;
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,uStack20) - f_op_msg_mng::_4895) + this->field_0x14;
  }
  local_18 = 0x43300000;
  getRubyString(this,*(char **)&this->field_0x60,*(char **)&this->field_0x68,
                *(char **)&this->field_0x64,*(char **)&this->field_0x6c,"","",&this->field_0x20,
                &this->field_0x24,&this->field_0x150);
  this->field_0x118 =
       this->field_0x118 + (int)*(char *)(*(int *)&this->field_0x3c + this->field_0x118 + 1);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall fopMsgM_msgDataProc_c::tag_forest_timer(void) */

void __thiscall fopMsgM_msgDataProc_c::tag_forest_timer(fopMsgM_msgDataProc_c *this)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  byte *pbVar5;
  double dVar6;
  char acStack64 [4];
  byte local_3c [20];
  undefined4 local_28;
  uint uStack36;
  
  uVar2 = dSv_player_item_record_c::getTimer
                    (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord);
  uVar2 = (uVar2 & 0xffff) / 0x708;
  f_op_msg_mng::fopMsgM_int_to_char(local_3c,uVar2,0);
  pbVar4 = local_3c;
  pbVar5 = pbVar4;
  while (*pbVar5 != 0) {
    bVar1 = *pbVar4;
    pbVar5 = pbVar5 + 1;
    pbVar4 = pbVar4 + 1;
    if (this->field_0x150 == 0) {
      dVar6 = (double)charLength(this,this->field_0x148,(uint)bVar1,true);
      this->field_0x14 = (float)dVar6;
    }
    else {
      dVar6 = (double)charLength(this,this->field_0x148,(uint)bVar1,false);
      this->field_0x14 = (float)((double)this->field_0x14 + dVar6);
    }
    this->field_0x150 = this->field_0x150 + 1;
  }
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x60,(char *)local_3c);
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x68,(char *)local_3c);
  if (*(char *)&this->field_0x294 == '\x01') {
    uStack36 = *(uint *)(&this->field_0x108 + this->field_0x130 * 4) ^ 0x80000000;
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,uStack36) - f_op_msg_mng::_4895) + this->field_0x14;
  }
  else {
    uStack36 = *(uint *)(&this->field_0xf8 + this->field_0x130 * 4) ^ 0x80000000;
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,uStack36) - f_op_msg_mng::_4895) + this->field_0x14;
  }
  local_28 = 0x43300000;
  MSL_C.PPCEABI.bare.H::strcpy(acStack64,":");
  getRubyString(this,*(char **)&this->field_0x60,*(char **)&this->field_0x68,
                *(char **)&this->field_0x64,*(char **)&this->field_0x6c,acStack64,"",
                &this->field_0x20,&this->field_0x24,&this->field_0x150);
  local_3c[0] = 0;
  uVar3 = dSv_player_item_record_c::getTimer
                    (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord);
  uVar3 = ((uVar3 & 0xffff) % 0x708) / 0x1e;
  if ((uVar2 == 0) && (uVar3 == 0)) {
    uVar3 = 1;
  }
  f_op_msg_mng::fopMsgM_int_to_char2(local_3c,uVar3);
  pbVar4 = local_3c;
  pbVar5 = pbVar4;
  while (*pbVar4 != 0) {
    bVar1 = *pbVar5;
    pbVar4 = pbVar4 + 1;
    pbVar5 = pbVar5 + 1;
    if (this->field_0x150 == 0) {
      dVar6 = (double)charLength(this,this->field_0x148,(uint)bVar1,true);
      this->field_0x14 = (float)dVar6;
    }
    else {
      dVar6 = (double)charLength(this,this->field_0x148,(uint)bVar1,false);
      this->field_0x14 = (float)((double)this->field_0x14 + dVar6);
    }
    this->field_0x150 = this->field_0x150 + 1;
  }
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x60,(char *)local_3c);
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x68,(char *)local_3c);
  if (*(char *)&this->field_0x294 == '\x01') {
    uStack36 = *(uint *)(&this->field_0x108 + this->field_0x130 * 4) ^ 0x80000000;
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,uStack36) - f_op_msg_mng::_4895) + this->field_0x14;
  }
  else {
    uStack36 = *(uint *)(&this->field_0xf8 + this->field_0x130 * 4) ^ 0x80000000;
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,uStack36) - f_op_msg_mng::_4895) + this->field_0x14;
  }
  local_28 = 0x43300000;
  getRubyString(this,*(char **)&this->field_0x60,*(char **)&this->field_0x68,
                *(char **)&this->field_0x64,*(char **)&this->field_0x6c,"","",&this->field_0x20,
                &this->field_0x24,&this->field_0x150);
  this->field_0x118 =
       this->field_0x118 + (int)*(char *)(*(int *)&this->field_0x3c + this->field_0x118 + 1);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall fopMsgM_msgDataProc_c::tag_birdman(void) */

void __thiscall fopMsgM_msgDataProc_c::tag_birdman(fopMsgM_msgDataProc_c *this)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  double dVar5;
  byte local_38 [40];
  
  iVar2 = (int)(short)d_com_inf_game::g_dComIfG_gameInfo.mCurrAuctionItemNameMsgID;
  f_op_msg_mng::fopMsgM_int_to_char(local_38,iVar2,0);
  if (iVar2 == 1) {
    MSL_C.PPCEABI.bare.H::strcat((char *)local_38," yard");
  }
  else {
    MSL_C.PPCEABI.bare.H::strcat((char *)local_38," yards");
  }
  pbVar3 = local_38;
  pbVar4 = pbVar3;
  while (*pbVar4 != 0) {
    bVar1 = *pbVar3;
    pbVar4 = pbVar4 + 1;
    pbVar3 = pbVar3 + 1;
    if (this->field_0x150 == 0) {
      dVar5 = (double)charLength(this,this->field_0x148,(uint)bVar1,true);
      this->field_0x14 = (float)dVar5;
    }
    else {
      dVar5 = (double)charLength(this,this->field_0x148,(uint)bVar1,false);
      this->field_0x14 = (float)((double)this->field_0x14 + dVar5);
    }
    this->field_0x150 = this->field_0x150 + 1;
  }
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x60,(char *)local_38);
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x68,(char *)local_38);
  if (*(char *)&this->field_0x294 == '\x01') {
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,
                                  *(uint *)(&this->field_0x108 + this->field_0x130 * 4) ^ 0x80000000
                                 ) - f_op_msg_mng::_4895) + this->field_0x14;
  }
  else {
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,
                                  *(uint *)(&this->field_0xf8 + this->field_0x130 * 4) ^ 0x80000000)
                - f_op_msg_mng::_4895) + this->field_0x14;
  }
  this->field_0x118 =
       this->field_0x118 + (int)*(char *)(*(int *)&this->field_0x3c + this->field_0x118 + 1);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall fopMsgM_msgDataProc_c::tag_point(void) */

void __thiscall fopMsgM_msgDataProc_c::tag_point(fopMsgM_msgDataProc_c *this)

{
  byte bVar1;
  ushort uVar2;
  byte *pbVar3;
  byte *pbVar4;
  double dVar5;
  byte local_38 [40];
  
  uVar2 = dSv_event_c::getEventReg(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x86ff);
  f_op_msg_mng::fopMsgM_int_to_char(local_38,uVar2 & 0xff,0);
  if ((uVar2 & 0xff) == 1) {
    MSL_C.PPCEABI.bare.H::strcat((char *)local_38," point");
  }
  else {
    MSL_C.PPCEABI.bare.H::strcat((char *)local_38," points");
  }
  pbVar3 = local_38;
  pbVar4 = pbVar3;
  while (*pbVar4 != 0) {
    bVar1 = *pbVar3;
    pbVar4 = pbVar4 + 1;
    pbVar3 = pbVar3 + 1;
    if (this->field_0x150 == 0) {
      dVar5 = (double)charLength(this,this->field_0x148,(uint)bVar1,true);
      this->field_0x14 = (float)dVar5;
    }
    else {
      dVar5 = (double)charLength(this,this->field_0x148,(uint)bVar1,false);
      this->field_0x14 = (float)((double)this->field_0x14 + dVar5);
    }
    this->field_0x150 = this->field_0x150 + 1;
  }
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x60,(char *)local_38);
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x68,(char *)local_38);
  if (*(char *)&this->field_0x294 == '\x01') {
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,
                                  *(uint *)(&this->field_0x108 + this->field_0x130 * 4) ^ 0x80000000
                                 ) - f_op_msg_mng::_4895) + this->field_0x14;
  }
  else {
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,
                                  *(uint *)(&this->field_0xf8 + this->field_0x130 * 4) ^ 0x80000000)
                - f_op_msg_mng::_4895) + this->field_0x14;
  }
  this->field_0x118 =
       this->field_0x118 + (int)*(char *)(*(int *)&this->field_0x3c + this->field_0x118 + 1);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall fopMsgM_msgDataProc_c::tag_get_pendant(void) */

void __thiscall fopMsgM_msgDataProc_c::tag_get_pendant(fopMsgM_msgDataProc_c *this)

{
  byte bVar1;
  char cVar2;
  byte *pbVar3;
  byte *pbVar4;
  double dVar5;
  char acStack64 [12];
  byte local_34 [20];
  undefined4 local_20;
  uint uStack28;
  
  cVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItemRecord._7_1_;
  f_op_msg_mng::fopMsgM_int_to_char
            (local_34,d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItemRecord._7_1_,
             0);
  pbVar3 = local_34;
  pbVar4 = pbVar3;
  while (*pbVar4 != 0) {
    bVar1 = *pbVar3;
    pbVar4 = pbVar4 + 1;
    pbVar3 = pbVar3 + 1;
    if (this->field_0x150 == 0) {
      dVar5 = (double)charLength(this,this->field_0x148,(uint)bVar1,true);
      this->field_0x14 = (float)dVar5;
    }
    else {
      dVar5 = (double)charLength(this,this->field_0x148,(uint)bVar1,false);
      this->field_0x14 = (float)((double)this->field_0x14 + dVar5);
    }
    this->field_0x150 = this->field_0x150 + 1;
  }
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x60,(char *)local_34);
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x68,(char *)local_34);
  if (*(char *)&this->field_0x294 == '\x01') {
    uStack28 = *(uint *)(&this->field_0x108 + this->field_0x130 * 4) ^ 0x80000000;
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,uStack28) - f_op_msg_mng::_4895) + this->field_0x14;
  }
  else {
    uStack28 = *(uint *)(&this->field_0xf8 + this->field_0x130 * 4) ^ 0x80000000;
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,uStack28) - f_op_msg_mng::_4895) + this->field_0x14;
  }
  local_20 = 0x43300000;
  if (cVar2 == '\x01') {
    MSL_C.PPCEABI.bare.H::strcpy(acStack64,"");
  }
  else {
    MSL_C.PPCEABI.bare.H::strcpy(acStack64,"");
  }
  getRubyString(this,*(char **)&this->field_0x60,*(char **)&this->field_0x68,
                *(char **)&this->field_0x64,*(char **)&this->field_0x6c,acStack64,"",
                &this->field_0x20,&this->field_0x24,&this->field_0x150);
  this->field_0x118 =
       this->field_0x118 + (int)*(char *)(*(int *)&this->field_0x3c + this->field_0x118 + 1);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall fopMsgM_msgDataProc_c::tag_rev_pendant(void) */

void __thiscall fopMsgM_msgDataProc_c::tag_rev_pendant(fopMsgM_msgDataProc_c *this)

{
  byte bVar1;
  ushort uVar2;
  byte *pbVar3;
  byte *pbVar4;
  double dVar5;
  char acStack64 [12];
  byte local_34 [20];
  undefined4 local_20;
  uint uStack28;
  
  uVar2 = dSv_event_c::getEventReg(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0xc0ff);
  f_op_msg_mng::fopMsgM_int_to_char(local_34,uVar2 & 0xff,0);
  pbVar3 = local_34;
  pbVar4 = pbVar3;
  while (*pbVar4 != 0) {
    bVar1 = *pbVar3;
    pbVar4 = pbVar4 + 1;
    pbVar3 = pbVar3 + 1;
    if (this->field_0x150 == 0) {
      dVar5 = (double)charLength(this,this->field_0x148,(uint)bVar1,true);
      this->field_0x14 = (float)dVar5;
    }
    else {
      dVar5 = (double)charLength(this,this->field_0x148,(uint)bVar1,false);
      this->field_0x14 = (float)((double)this->field_0x14 + dVar5);
    }
    this->field_0x150 = this->field_0x150 + 1;
  }
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x60,(char *)local_34);
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x68,(char *)local_34);
  if (*(char *)&this->field_0x294 == '\x01') {
    uStack28 = *(uint *)(&this->field_0x108 + this->field_0x130 * 4) ^ 0x80000000;
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,uStack28) - f_op_msg_mng::_4895) + this->field_0x14;
  }
  else {
    uStack28 = *(uint *)(&this->field_0xf8 + this->field_0x130 * 4) ^ 0x80000000;
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,uStack28) - f_op_msg_mng::_4895) + this->field_0x14;
  }
  local_20 = 0x43300000;
  if ((uVar2 & 0xff) == 1) {
    MSL_C.PPCEABI.bare.H::strcpy(acStack64,"");
  }
  else {
    MSL_C.PPCEABI.bare.H::strcpy(acStack64,"");
  }
  getRubyString(this,*(char **)&this->field_0x60,*(char **)&this->field_0x68,
                *(char **)&this->field_0x64,*(char **)&this->field_0x6c,acStack64,"",
                &this->field_0x20,&this->field_0x24,&this->field_0x150);
  this->field_0x118 =
       this->field_0x118 + (int)*(char *)(*(int *)&this->field_0x3c + this->field_0x118 + 1);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall fopMsgM_msgDataProc_c::tag_pig_timer(void) */

void __thiscall fopMsgM_msgDataProc_c::tag_pig_timer(fopMsgM_msgDataProc_c *this)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  double dVar6;
  char acStack64 [4];
  byte local_3c [20];
  undefined4 local_28;
  uint uStack36;
  
  iVar2 = (int)d_com_inf_game::g_dComIfG_gameInfo._23490_2_;
  f_op_msg_mng::fopMsgM_int_to_char(local_3c,iVar2 / 0x708,0);
  pbVar4 = local_3c;
  pbVar5 = pbVar4;
  while (*pbVar5 != 0) {
    bVar1 = *pbVar4;
    pbVar5 = pbVar5 + 1;
    pbVar4 = pbVar4 + 1;
    if (this->field_0x150 == 0) {
      dVar6 = (double)charLength(this,this->field_0x148,(uint)bVar1,true);
      this->field_0x14 = (float)dVar6;
    }
    else {
      dVar6 = (double)charLength(this,this->field_0x148,(uint)bVar1,false);
      this->field_0x14 = (float)((double)this->field_0x14 + dVar6);
    }
    this->field_0x150 = this->field_0x150 + 1;
  }
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x60,(char *)local_3c);
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x68,(char *)local_3c);
  if (*(char *)&this->field_0x294 == '\x01') {
    uStack36 = *(uint *)(&this->field_0x108 + this->field_0x130 * 4) ^ 0x80000000;
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,uStack36) - f_op_msg_mng::_4895) + this->field_0x14;
  }
  else {
    uStack36 = *(uint *)(&this->field_0xf8 + this->field_0x130 * 4) ^ 0x80000000;
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,uStack36) - f_op_msg_mng::_4895) + this->field_0x14;
  }
  local_28 = 0x43300000;
  MSL_C.PPCEABI.bare.H::strcpy(acStack64,":");
  getRubyString(this,*(char **)&this->field_0x60,*(char **)&this->field_0x68,
                *(char **)&this->field_0x64,*(char **)&this->field_0x6c,acStack64,"",
                &this->field_0x20,&this->field_0x24,&this->field_0x150);
  local_3c[0] = 0;
  iVar3 = ((int)d_com_inf_game::g_dComIfG_gameInfo._23490_2_ % 0x708) / 0x1e;
  if ((iVar2 / 0x708 == 0) && (iVar3 == 0)) {
    iVar3 = 1;
  }
  f_op_msg_mng::fopMsgM_int_to_char2(local_3c,iVar3);
  pbVar4 = local_3c;
  pbVar5 = pbVar4;
  while (*pbVar4 != 0) {
    bVar1 = *pbVar5;
    pbVar4 = pbVar4 + 1;
    pbVar5 = pbVar5 + 1;
    if (this->field_0x150 == 0) {
      dVar6 = (double)charLength(this,this->field_0x148,(uint)bVar1,true);
      this->field_0x14 = (float)dVar6;
    }
    else {
      dVar6 = (double)charLength(this,this->field_0x148,(uint)bVar1,false);
      this->field_0x14 = (float)((double)this->field_0x14 + dVar6);
    }
    this->field_0x150 = this->field_0x150 + 1;
  }
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x60,(char *)local_3c);
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x68,(char *)local_3c);
  if (*(char *)&this->field_0x294 == '\x01') {
    uStack36 = *(uint *)(&this->field_0x108 + this->field_0x130 * 4) ^ 0x80000000;
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,uStack36) - f_op_msg_mng::_4895) + this->field_0x14;
  }
  else {
    uStack36 = *(uint *)(&this->field_0xf8 + this->field_0x130 * 4) ^ 0x80000000;
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,uStack36) - f_op_msg_mng::_4895) + this->field_0x14;
  }
  local_28 = 0x43300000;
  getRubyString(this,*(char **)&this->field_0x60,*(char **)&this->field_0x68,
                *(char **)&this->field_0x64,*(char **)&this->field_0x6c,"","",&this->field_0x20,
                &this->field_0x24,&this->field_0x150);
  this->field_0x118 =
       this->field_0x118 + (int)*(char *)(*(int *)&this->field_0x3c + this->field_0x118 + 1);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall fopMsgM_msgDataProc_c::tag_get_bomb(void) */

void __thiscall fopMsgM_msgDataProc_c::tag_get_bomb(fopMsgM_msgDataProc_c *this)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  byte *pbVar4;
  double dVar5;
  char acStack64 [12];
  byte local_34 [20];
  undefined4 local_20;
  uint uStack28;
  
  bVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax.field_0x2;
  f_op_msg_mng::fopMsgM_int_to_char
            (local_34,d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax.field_0x2,0)
  ;
  pbVar3 = local_34;
  pbVar4 = pbVar3;
  while (*pbVar4 != 0) {
    bVar1 = *pbVar3;
    pbVar4 = pbVar4 + 1;
    pbVar3 = pbVar3 + 1;
    if (this->field_0x150 == 0) {
      dVar5 = (double)charLength(this,this->field_0x148,(uint)bVar1,true);
      this->field_0x14 = (float)dVar5;
    }
    else {
      dVar5 = (double)charLength(this,this->field_0x148,(uint)bVar1,false);
      this->field_0x14 = (float)((double)this->field_0x14 + dVar5);
    }
    this->field_0x150 = this->field_0x150 + 1;
  }
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x60,(char *)local_34);
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x68,(char *)local_34);
  if (*(char *)&this->field_0x294 == '\x01') {
    uStack28 = *(uint *)(&this->field_0x108 + this->field_0x130 * 4) ^ 0x80000000;
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,uStack28) - f_op_msg_mng::_4895) + this->field_0x14;
  }
  else {
    uStack28 = *(uint *)(&this->field_0xf8 + this->field_0x130 * 4) ^ 0x80000000;
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,uStack28) - f_op_msg_mng::_4895) + this->field_0x14;
  }
  local_20 = 0x43300000;
  if (bVar2 == 1) {
    MSL_C.PPCEABI.bare.H::strcpy(acStack64," bomb");
  }
  else {
    MSL_C.PPCEABI.bare.H::strcpy(acStack64," bombs");
  }
  getRubyString(this,*(char **)&this->field_0x60,*(char **)&this->field_0x68,
                *(char **)&this->field_0x64,*(char **)&this->field_0x6c,acStack64,"",
                &this->field_0x20,&this->field_0x24,&this->field_0x150);
  this->field_0x118 =
       this->field_0x118 + (int)*(char *)(*(int *)&this->field_0x3c + this->field_0x118 + 1);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall fopMsgM_msgDataProc_c::tag_get_arrow(void) */

void __thiscall fopMsgM_msgDataProc_c::tag_get_arrow(fopMsgM_msgDataProc_c *this)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  byte *pbVar4;
  double dVar5;
  char acStack64 [12];
  byte local_34 [20];
  undefined4 local_20;
  uint uStack28;
  
  bVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax.field_0x1;
  f_op_msg_mng::fopMsgM_int_to_char
            (local_34,d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax.field_0x1,0)
  ;
  pbVar3 = local_34;
  pbVar4 = pbVar3;
  while (*pbVar4 != 0) {
    bVar1 = *pbVar3;
    pbVar4 = pbVar4 + 1;
    pbVar3 = pbVar3 + 1;
    if (this->field_0x150 == 0) {
      dVar5 = (double)charLength(this,this->field_0x148,(uint)bVar1,true);
      this->field_0x14 = (float)dVar5;
    }
    else {
      dVar5 = (double)charLength(this,this->field_0x148,(uint)bVar1,false);
      this->field_0x14 = (float)((double)this->field_0x14 + dVar5);
    }
    this->field_0x150 = this->field_0x150 + 1;
  }
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x60,(char *)local_34);
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x68,(char *)local_34);
  if (*(char *)&this->field_0x294 == '\x01') {
    uStack28 = *(uint *)(&this->field_0x108 + this->field_0x130 * 4) ^ 0x80000000;
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,uStack28) - f_op_msg_mng::_4895) + this->field_0x14;
  }
  else {
    uStack28 = *(uint *)(&this->field_0xf8 + this->field_0x130 * 4) ^ 0x80000000;
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,uStack28) - f_op_msg_mng::_4895) + this->field_0x14;
  }
  local_20 = 0x43300000;
  if (bVar2 == 1) {
    MSL_C.PPCEABI.bare.H::strcpy(acStack64," arrow");
  }
  else {
    MSL_C.PPCEABI.bare.H::strcpy(acStack64," arrows");
  }
  getRubyString(this,*(char **)&this->field_0x60,*(char **)&this->field_0x68,
                *(char **)&this->field_0x64,*(char **)&this->field_0x6c,acStack64,"",
                &this->field_0x20,&this->field_0x24,&this->field_0x150);
  this->field_0x118 =
       this->field_0x118 + (int)*(char *)(*(int *)&this->field_0x3c + this->field_0x118 + 1);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall fopMsgM_msgDataProc_c::tag_stock_bokobaba(void) */

void __thiscall fopMsgM_msgDataProc_c::tag_stock_bokobaba(fopMsgM_msgDataProc_c *this)

{
  byte bVar1;
  char cVar2;
  byte *pbVar3;
  byte *pbVar4;
  double dVar5;
  char acStack64 [12];
  byte local_34 [20];
  undefined4 local_20;
  uint uStack28;
  
  cVar2 = daNpc_Bs1_c::m_tag_buy_item;
  f_op_msg_mng::fopMsgM_int_to_char(local_34,daNpc_Bs1_c::m_tag_buy_item,0);
  pbVar3 = local_34;
  pbVar4 = pbVar3;
  while (*pbVar4 != 0) {
    bVar1 = *pbVar3;
    pbVar4 = pbVar4 + 1;
    pbVar3 = pbVar3 + 1;
    if (this->field_0x150 == 0) {
      dVar5 = (double)charLength(this,this->field_0x148,(uint)bVar1,true);
      this->field_0x14 = (float)dVar5;
    }
    else {
      dVar5 = (double)charLength(this,this->field_0x148,(uint)bVar1,false);
      this->field_0x14 = (float)((double)this->field_0x14 + dVar5);
    }
    this->field_0x150 = this->field_0x150 + 1;
  }
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x60,(char *)local_34);
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x68,(char *)local_34);
  if (*(char *)&this->field_0x294 == '\x01') {
    uStack28 = *(uint *)(&this->field_0x108 + this->field_0x130 * 4) ^ 0x80000000;
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,uStack28) - f_op_msg_mng::_4895) + this->field_0x14;
  }
  else {
    uStack28 = *(uint *)(&this->field_0xf8 + this->field_0x130 * 4) ^ 0x80000000;
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,uStack28) - f_op_msg_mng::_4895) + this->field_0x14;
  }
  local_20 = 0x43300000;
  if (cVar2 == '\x01') {
    MSL_C.PPCEABI.bare.H::strcpy(acStack64," seed");
  }
  else {
    MSL_C.PPCEABI.bare.H::strcpy(acStack64," seeds");
  }
  getRubyString(this,*(char **)&this->field_0x60,*(char **)&this->field_0x68,
                *(char **)&this->field_0x64,*(char **)&this->field_0x6c,acStack64,"",
                &this->field_0x20,&this->field_0x24,&this->field_0x150);
  this->field_0x118 =
       this->field_0x118 + (int)*(char *)(*(int *)&this->field_0x3c + this->field_0x118 + 1);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall fopMsgM_msgDataProc_c::tag_stock_dokuro(void) */

void __thiscall fopMsgM_msgDataProc_c::tag_stock_dokuro(fopMsgM_msgDataProc_c *this)

{
  byte bVar1;
  char cVar2;
  byte *pbVar3;
  byte *pbVar4;
  double dVar5;
  char acStack64 [12];
  byte local_34 [20];
  undefined4 local_20;
  uint uStack28;
  
  cVar2 = daNpc_Bs1_c::m_tag_buy_item;
  f_op_msg_mng::fopMsgM_int_to_char(local_34,daNpc_Bs1_c::m_tag_buy_item,0);
  pbVar3 = local_34;
  pbVar4 = pbVar3;
  while (*pbVar4 != 0) {
    bVar1 = *pbVar3;
    pbVar4 = pbVar4 + 1;
    pbVar3 = pbVar3 + 1;
    if (this->field_0x150 == 0) {
      dVar5 = (double)charLength(this,this->field_0x148,(uint)bVar1,true);
      this->field_0x14 = (float)dVar5;
    }
    else {
      dVar5 = (double)charLength(this,this->field_0x148,(uint)bVar1,false);
      this->field_0x14 = (float)((double)this->field_0x14 + dVar5);
    }
    this->field_0x150 = this->field_0x150 + 1;
  }
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x60,(char *)local_34);
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x68,(char *)local_34);
  if (*(char *)&this->field_0x294 == '\x01') {
    uStack28 = *(uint *)(&this->field_0x108 + this->field_0x130 * 4) ^ 0x80000000;
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,uStack28) - f_op_msg_mng::_4895) + this->field_0x14;
  }
  else {
    uStack28 = *(uint *)(&this->field_0xf8 + this->field_0x130 * 4) ^ 0x80000000;
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,uStack28) - f_op_msg_mng::_4895) + this->field_0x14;
  }
  local_20 = 0x43300000;
  if (cVar2 == '\x01') {
    MSL_C.PPCEABI.bare.H::strcpy(acStack64," necklace");
  }
  else {
    MSL_C.PPCEABI.bare.H::strcpy(acStack64," necklaces");
  }
  getRubyString(this,*(char **)&this->field_0x60,*(char **)&this->field_0x68,
                *(char **)&this->field_0x64,*(char **)&this->field_0x6c,acStack64,"",
                &this->field_0x20,&this->field_0x24,&this->field_0x150);
  this->field_0x118 =
       this->field_0x118 + (int)*(char *)(*(int *)&this->field_0x3c + this->field_0x118 + 1);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall fopMsgM_msgDataProc_c::tag_stock_chuchu(void) */

void __thiscall fopMsgM_msgDataProc_c::tag_stock_chuchu(fopMsgM_msgDataProc_c *this)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  double dVar4;
  byte local_30 [24];
  undefined4 local_18;
  uint uStack20;
  
  f_op_msg_mng::fopMsgM_int_to_char(local_30,daNpc_Bs1_c::m_tag_buy_item,0);
  pbVar2 = local_30;
  pbVar3 = pbVar2;
  while (*pbVar3 != 0) {
    bVar1 = *pbVar2;
    pbVar3 = pbVar3 + 1;
    pbVar2 = pbVar2 + 1;
    if (this->field_0x150 == 0) {
      dVar4 = (double)charLength(this,this->field_0x148,(uint)bVar1,true);
      this->field_0x14 = (float)dVar4;
    }
    else {
      dVar4 = (double)charLength(this,this->field_0x148,(uint)bVar1,false);
      this->field_0x14 = (float)((double)this->field_0x14 + dVar4);
    }
    this->field_0x150 = this->field_0x150 + 1;
  }
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x60,(char *)local_30);
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x68,(char *)local_30);
  if (*(char *)&this->field_0x294 == '\x01') {
    uStack20 = *(uint *)(&this->field_0x108 + this->field_0x130 * 4) ^ 0x80000000;
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,uStack20) - f_op_msg_mng::_4895) + this->field_0x14;
  }
  else {
    uStack20 = *(uint *)(&this->field_0xf8 + this->field_0x130 * 4) ^ 0x80000000;
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,uStack20) - f_op_msg_mng::_4895) + this->field_0x14;
  }
  local_18 = 0x43300000;
  getRubyString(this,*(char **)&this->field_0x60,*(char **)&this->field_0x68,
                *(char **)&this->field_0x64,*(char **)&this->field_0x6c,"","",&this->field_0x20,
                &this->field_0x24,&this->field_0x150);
  this->field_0x118 =
       this->field_0x118 + (int)*(char *)(*(int *)&this->field_0x3c + this->field_0x118 + 1);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall fopMsgM_msgDataProc_c::tag_stock_pendant(void) */

void __thiscall fopMsgM_msgDataProc_c::tag_stock_pendant(fopMsgM_msgDataProc_c *this)

{
  byte bVar1;
  char cVar2;
  byte *pbVar3;
  byte *pbVar4;
  double dVar5;
  char acStack64 [12];
  byte local_34 [20];
  undefined4 local_20;
  uint uStack28;
  
  cVar2 = daNpc_Bs1_c::m_tag_buy_item;
  f_op_msg_mng::fopMsgM_int_to_char(local_34,daNpc_Bs1_c::m_tag_buy_item,0);
  pbVar3 = local_34;
  pbVar4 = pbVar3;
  while (*pbVar4 != 0) {
    bVar1 = *pbVar3;
    pbVar4 = pbVar4 + 1;
    pbVar3 = pbVar3 + 1;
    if (this->field_0x150 == 0) {
      dVar5 = (double)charLength(this,this->field_0x148,(uint)bVar1,true);
      this->field_0x14 = (float)dVar5;
    }
    else {
      dVar5 = (double)charLength(this,this->field_0x148,(uint)bVar1,false);
      this->field_0x14 = (float)((double)this->field_0x14 + dVar5);
    }
    this->field_0x150 = this->field_0x150 + 1;
  }
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x60,(char *)local_34);
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x68,(char *)local_34);
  if (*(char *)&this->field_0x294 == '\x01') {
    uStack28 = *(uint *)(&this->field_0x108 + this->field_0x130 * 4) ^ 0x80000000;
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,uStack28) - f_op_msg_mng::_4895) + this->field_0x14;
  }
  else {
    uStack28 = *(uint *)(&this->field_0xf8 + this->field_0x130 * 4) ^ 0x80000000;
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,uStack28) - f_op_msg_mng::_4895) + this->field_0x14;
  }
  local_20 = 0x43300000;
  if (cVar2 == '\x01') {
    MSL_C.PPCEABI.bare.H::strcpy(acStack64," necklace");
  }
  else {
    MSL_C.PPCEABI.bare.H::strcpy(acStack64," necklaces");
  }
  getRubyString(this,*(char **)&this->field_0x60,*(char **)&this->field_0x68,
                *(char **)&this->field_0x64,*(char **)&this->field_0x6c,acStack64,"",
                &this->field_0x20,&this->field_0x24,&this->field_0x150);
  this->field_0x118 =
       this->field_0x118 + (int)*(char *)(*(int *)&this->field_0x3c + this->field_0x118 + 1);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall fopMsgM_msgDataProc_c::tag_stock_hane(void) */

void __thiscall fopMsgM_msgDataProc_c::tag_stock_hane(fopMsgM_msgDataProc_c *this)

{
  byte bVar1;
  char cVar2;
  byte *pbVar3;
  byte *pbVar4;
  double dVar5;
  char acStack64 [12];
  byte local_34 [20];
  undefined4 local_20;
  uint uStack28;
  
  cVar2 = daNpc_Bs1_c::m_tag_buy_item;
  f_op_msg_mng::fopMsgM_int_to_char(local_34,daNpc_Bs1_c::m_tag_buy_item,0);
  pbVar3 = local_34;
  pbVar4 = pbVar3;
  while (*pbVar4 != 0) {
    bVar1 = *pbVar3;
    pbVar4 = pbVar4 + 1;
    pbVar3 = pbVar3 + 1;
    if (this->field_0x150 == 0) {
      dVar5 = (double)charLength(this,this->field_0x148,(uint)bVar1,true);
      this->field_0x14 = (float)dVar5;
    }
    else {
      dVar5 = (double)charLength(this,this->field_0x148,(uint)bVar1,false);
      this->field_0x14 = (float)((double)this->field_0x14 + dVar5);
    }
    this->field_0x150 = this->field_0x150 + 1;
  }
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x60,(char *)local_34);
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x68,(char *)local_34);
  if (*(char *)&this->field_0x294 == '\x01') {
    uStack28 = *(uint *)(&this->field_0x108 + this->field_0x130 * 4) ^ 0x80000000;
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,uStack28) - f_op_msg_mng::_4895) + this->field_0x14;
  }
  else {
    uStack28 = *(uint *)(&this->field_0xf8 + this->field_0x130 * 4) ^ 0x80000000;
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,uStack28) - f_op_msg_mng::_4895) + this->field_0x14;
  }
  local_20 = 0x43300000;
  if (cVar2 == '\x01') {
    MSL_C.PPCEABI.bare.H::strcpy(acStack64," feather");
  }
  else {
    MSL_C.PPCEABI.bare.H::strcpy(acStack64," feathers");
  }
  getRubyString(this,*(char **)&this->field_0x60,*(char **)&this->field_0x68,
                *(char **)&this->field_0x64,*(char **)&this->field_0x6c,acStack64,"",
                &this->field_0x20,&this->field_0x24,&this->field_0x150);
  this->field_0x118 =
       this->field_0x118 + (int)*(char *)(*(int *)&this->field_0x3c + this->field_0x118 + 1);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall fopMsgM_msgDataProc_c::tag_stock_kenshi(void) */

void __thiscall fopMsgM_msgDataProc_c::tag_stock_kenshi(fopMsgM_msgDataProc_c *this)

{
  byte bVar1;
  char cVar2;
  byte *pbVar3;
  byte *pbVar4;
  double dVar5;
  char acStack64 [12];
  byte local_34 [20];
  undefined4 local_20;
  uint uStack28;
  
  cVar2 = daNpc_Bs1_c::m_tag_buy_item;
  f_op_msg_mng::fopMsgM_int_to_char(local_34,daNpc_Bs1_c::m_tag_buy_item,0);
  pbVar3 = local_34;
  pbVar4 = pbVar3;
  while (*pbVar4 != 0) {
    bVar1 = *pbVar3;
    pbVar4 = pbVar4 + 1;
    pbVar3 = pbVar3 + 1;
    if (this->field_0x150 == 0) {
      dVar5 = (double)charLength(this,this->field_0x148,(uint)bVar1,true);
      this->field_0x14 = (float)dVar5;
    }
    else {
      dVar5 = (double)charLength(this,this->field_0x148,(uint)bVar1,false);
      this->field_0x14 = (float)((double)this->field_0x14 + dVar5);
    }
    this->field_0x150 = this->field_0x150 + 1;
  }
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x60,(char *)local_34);
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x68,(char *)local_34);
  if (*(char *)&this->field_0x294 == '\x01') {
    uStack28 = *(uint *)(&this->field_0x108 + this->field_0x130 * 4) ^ 0x80000000;
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,uStack28) - f_op_msg_mng::_4895) + this->field_0x14;
  }
  else {
    uStack28 = *(uint *)(&this->field_0xf8 + this->field_0x130 * 4) ^ 0x80000000;
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,uStack28) - f_op_msg_mng::_4895) + this->field_0x14;
  }
  local_20 = 0x43300000;
  if (cVar2 == '\x01') {
    MSL_C.PPCEABI.bare.H::strcpy(acStack64," crest");
  }
  else {
    MSL_C.PPCEABI.bare.H::strcpy(acStack64," crests");
  }
  getRubyString(this,*(char **)&this->field_0x60,*(char **)&this->field_0x68,
                *(char **)&this->field_0x64,*(char **)&this->field_0x6c,acStack64,"",
                &this->field_0x20,&this->field_0x24,&this->field_0x150);
  this->field_0x118 =
       this->field_0x118 + (int)*(char *)(*(int *)&this->field_0x3c + this->field_0x118 + 1);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall fopMsgM_msgDataProc_c::tag_terry_rupee(void) */

void __thiscall fopMsgM_msgDataProc_c::tag_terry_rupee(fopMsgM_msgDataProc_c *this)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  double dVar5;
  byte local_38 [40];
  
  iVar2 = (int)_m_tag_pay_rupee;
  f_op_msg_mng::fopMsgM_int_to_char(local_38,iVar2,0);
  if (iVar2 == 1) {
    MSL_C.PPCEABI.bare.H::strcat((char *)local_38," Rupee");
  }
  else {
    MSL_C.PPCEABI.bare.H::strcat((char *)local_38," Rupees");
  }
  pbVar3 = local_38;
  pbVar4 = pbVar3;
  while (*pbVar4 != 0) {
    bVar1 = *pbVar3;
    pbVar4 = pbVar4 + 1;
    pbVar3 = pbVar3 + 1;
    if (this->field_0x150 == 0) {
      dVar5 = (double)charLength(this,this->field_0x148,(uint)bVar1,true);
      this->field_0x14 = (float)dVar5;
    }
    else {
      dVar5 = (double)charLength(this,this->field_0x148,(uint)bVar1,false);
      this->field_0x14 = (float)((double)this->field_0x14 + dVar5);
    }
    this->field_0x150 = this->field_0x150 + 1;
  }
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x60,(char *)local_38);
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x68,(char *)local_38);
  if (*(char *)&this->field_0x294 == '\x01') {
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,
                                  *(uint *)(&this->field_0x108 + this->field_0x130 * 4) ^ 0x80000000
                                 ) - f_op_msg_mng::_4895) + this->field_0x14;
  }
  else {
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,
                                  *(uint *)(&this->field_0xf8 + this->field_0x130 * 4) ^ 0x80000000)
                - f_op_msg_mng::_4895) + this->field_0x14;
  }
  this->field_0x118 =
       this->field_0x118 + (int)*(char *)(*(int *)&this->field_0x3c + this->field_0x118 + 1);
  return;
}


/* __thiscall fopMsgM_msgDataProc_c::tag_input_bokobaba(void) */

void __thiscall fopMsgM_msgDataProc_c::tag_input_bokobaba(fopMsgM_msgDataProc_c *this)

{
  uint uVar1;
  double dVar2;
  char acStack32 [16];
  undefined4 local_10;
  uint uStack12;
  
  uVar1 = (this->field_0x148 + this->field_0x11c) * 2;
  *(undefined *)&this->field_0x294 = 3;
  iconSelect(this,this->field_0x148,'\x16');
  *(undefined *)&this->field_0x27c = 0x15;
  MSL_C.PPCEABI.bare.H::sprintf(acStack32,"\x1bCR[%d]",uVar1);
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x60,acStack32);
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x68,acStack32);
  dVar2 = f_op_msg_mng::_4895;
  this->field_0x14 = (float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - f_op_msg_mng::_4895);
  this->field_0x150 = this->field_0x150 + 2;
  if (*(char *)&this->field_0x294 == '\x01') {
    uStack12 = *(uint *)(&this->field_0x108 + this->field_0x130 * 4) ^ 0x80000000;
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,uStack12) - dVar2) + this->field_0x14;
  }
  else {
    uStack12 = *(uint *)(&this->field_0xf8 + this->field_0x130 * 4) ^ 0x80000000;
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,uStack12) - dVar2) + this->field_0x14;
  }
  local_10 = 0x43300000;
  getRubyString(this,*(char **)&this->field_0x60,*(char **)&this->field_0x68,
                *(char **)&this->field_0x64,*(char **)&this->field_0x6c,"seed(s)","",
                &this->field_0x20,&this->field_0x24,&this->field_0x150);
  this->field_0x118 =
       this->field_0x118 + (int)*(char *)(*(int *)&this->field_0x3c + this->field_0x118 + 1);
  return;
}


/* __thiscall fopMsgM_msgDataProc_c::tag_input_dokuro(void) */

void __thiscall fopMsgM_msgDataProc_c::tag_input_dokuro(fopMsgM_msgDataProc_c *this)

{
  uint uVar1;
  double dVar2;
  char acStack32 [16];
  undefined4 local_10;
  uint uStack12;
  
  uVar1 = (this->field_0x148 + this->field_0x11c) * 2;
  *(undefined *)&this->field_0x294 = 3;
  iconSelect(this,this->field_0x148,'\x16');
  *(undefined *)&this->field_0x27c = 0x15;
  MSL_C.PPCEABI.bare.H::sprintf(acStack32,"\x1bCR[%d]",uVar1);
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x60,acStack32);
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x68,acStack32);
  dVar2 = f_op_msg_mng::_4895;
  this->field_0x14 = (float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - f_op_msg_mng::_4895);
  this->field_0x150 = this->field_0x150 + 2;
  if (*(char *)&this->field_0x294 == '\x01') {
    uStack12 = *(uint *)(&this->field_0x108 + this->field_0x130 * 4) ^ 0x80000000;
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,uStack12) - dVar2) + this->field_0x14;
  }
  else {
    uStack12 = *(uint *)(&this->field_0xf8 + this->field_0x130 * 4) ^ 0x80000000;
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,uStack12) - dVar2) + this->field_0x14;
  }
  local_10 = 0x43300000;
  getRubyString(this,*(char **)&this->field_0x60,*(char **)&this->field_0x68,
                *(char **)&this->field_0x64,*(char **)&this->field_0x6c,"necklace(s)","",
                &this->field_0x20,&this->field_0x24,&this->field_0x150);
  this->field_0x118 =
       this->field_0x118 + (int)*(char *)(*(int *)&this->field_0x3c + this->field_0x118 + 1);
  return;
}


/* __thiscall fopMsgM_msgDataProc_c::tag_input_chuchu(void) */

void __thiscall fopMsgM_msgDataProc_c::tag_input_chuchu(fopMsgM_msgDataProc_c *this)

{
  uint uVar1;
  double dVar2;
  char acStack32 [16];
  undefined4 local_10;
  uint uStack12;
  
  uVar1 = (this->field_0x148 + this->field_0x11c) * 2;
  *(undefined *)&this->field_0x294 = 3;
  iconSelect(this,this->field_0x148,'\x16');
  *(undefined *)&this->field_0x27c = 0x15;
  MSL_C.PPCEABI.bare.H::sprintf(acStack32,"\x1bCR[%d]",uVar1);
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x60,acStack32);
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x68,acStack32);
  dVar2 = f_op_msg_mng::_4895;
  this->field_0x14 = (float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - f_op_msg_mng::_4895);
  this->field_0x150 = this->field_0x150 + 2;
  if (*(char *)&this->field_0x294 == '\x01') {
    uStack12 = *(uint *)(&this->field_0x108 + this->field_0x130 * 4) ^ 0x80000000;
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,uStack12) - dVar2) + this->field_0x14;
  }
  else {
    uStack12 = *(uint *)(&this->field_0xf8 + this->field_0x130 * 4) ^ 0x80000000;
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,uStack12) - dVar2) + this->field_0x14;
  }
  local_10 = 0x43300000;
  getRubyString(this,*(char **)&this->field_0x60,*(char **)&this->field_0x68,
                *(char **)&this->field_0x64,*(char **)&this->field_0x6c,"","",&this->field_0x20,
                &this->field_0x24,&this->field_0x150);
  this->field_0x118 =
       this->field_0x118 + (int)*(char *)(*(int *)&this->field_0x3c + this->field_0x118 + 1);
  return;
}


/* __thiscall fopMsgM_msgDataProc_c::tag_input_pendant(void) */

void __thiscall fopMsgM_msgDataProc_c::tag_input_pendant(fopMsgM_msgDataProc_c *this)

{
  uint uVar1;
  double dVar2;
  char acStack32 [16];
  undefined4 local_10;
  uint uStack12;
  
  uVar1 = (this->field_0x148 + this->field_0x11c) * 2;
  *(undefined *)&this->field_0x294 = 3;
  iconSelect(this,this->field_0x148,'\x16');
  *(undefined *)&this->field_0x27c = 0x15;
  MSL_C.PPCEABI.bare.H::sprintf(acStack32,"\x1bCR[%d]",uVar1);
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x60,acStack32);
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x68,acStack32);
  dVar2 = f_op_msg_mng::_4895;
  this->field_0x14 = (float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - f_op_msg_mng::_4895);
  this->field_0x150 = this->field_0x150 + 2;
  if (*(char *)&this->field_0x294 == '\x01') {
    uStack12 = *(uint *)(&this->field_0x108 + this->field_0x130 * 4) ^ 0x80000000;
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,uStack12) - dVar2) + this->field_0x14;
  }
  else {
    uStack12 = *(uint *)(&this->field_0xf8 + this->field_0x130 * 4) ^ 0x80000000;
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,uStack12) - dVar2) + this->field_0x14;
  }
  local_10 = 0x43300000;
  getRubyString(this,*(char **)&this->field_0x60,*(char **)&this->field_0x68,
                *(char **)&this->field_0x64,*(char **)&this->field_0x6c,"pendant(s)","",
                &this->field_0x20,&this->field_0x24,&this->field_0x150);
  this->field_0x118 =
       this->field_0x118 + (int)*(char *)(*(int *)&this->field_0x3c + this->field_0x118 + 1);
  return;
}


/* __thiscall fopMsgM_msgDataProc_c::tag_input_hane(void) */

void __thiscall fopMsgM_msgDataProc_c::tag_input_hane(fopMsgM_msgDataProc_c *this)

{
  uint uVar1;
  double dVar2;
  char acStack32 [16];
  undefined4 local_10;
  uint uStack12;
  
  uVar1 = (this->field_0x148 + this->field_0x11c) * 2;
  *(undefined *)&this->field_0x294 = 3;
  iconSelect(this,this->field_0x148,'\x16');
  *(undefined *)&this->field_0x27c = 0x15;
  MSL_C.PPCEABI.bare.H::sprintf(acStack32,"\x1bCR[%d]",uVar1);
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x60,acStack32);
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x68,acStack32);
  dVar2 = f_op_msg_mng::_4895;
  this->field_0x14 = (float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - f_op_msg_mng::_4895);
  this->field_0x150 = this->field_0x150 + 2;
  if (*(char *)&this->field_0x294 == '\x01') {
    uStack12 = *(uint *)(&this->field_0x108 + this->field_0x130 * 4) ^ 0x80000000;
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,uStack12) - dVar2) + this->field_0x14;
  }
  else {
    uStack12 = *(uint *)(&this->field_0xf8 + this->field_0x130 * 4) ^ 0x80000000;
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,uStack12) - dVar2) + this->field_0x14;
  }
  local_10 = 0x43300000;
  getRubyString(this,*(char **)&this->field_0x60,*(char **)&this->field_0x68,
                *(char **)&this->field_0x64,*(char **)&this->field_0x6c,"feather(s)","",
                &this->field_0x20,&this->field_0x24,&this->field_0x150);
  this->field_0x118 =
       this->field_0x118 + (int)*(char *)(*(int *)&this->field_0x3c + this->field_0x118 + 1);
  return;
}


/* __thiscall fopMsgM_msgDataProc_c::tag_input_kenshi(void) */

void __thiscall fopMsgM_msgDataProc_c::tag_input_kenshi(fopMsgM_msgDataProc_c *this)

{
  uint uVar1;
  double dVar2;
  char acStack32 [16];
  undefined4 local_10;
  uint uStack12;
  
  uVar1 = (this->field_0x148 + this->field_0x11c) * 2;
  *(undefined *)&this->field_0x294 = 3;
  iconSelect(this,this->field_0x148,'\x16');
  *(undefined *)&this->field_0x27c = 0x15;
  MSL_C.PPCEABI.bare.H::sprintf(acStack32,"\x1bCR[%d]",uVar1);
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x60,acStack32);
  MSL_C.PPCEABI.bare.H::strcat(*(char **)&this->field_0x68,acStack32);
  dVar2 = f_op_msg_mng::_4895;
  this->field_0x14 = (float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - f_op_msg_mng::_4895);
  this->field_0x150 = this->field_0x150 + 2;
  if (*(char *)&this->field_0x294 == '\x01') {
    uStack12 = *(uint *)(&this->field_0x108 + this->field_0x130 * 4) ^ 0x80000000;
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,uStack12) - dVar2) + this->field_0x14;
  }
  else {
    uStack12 = *(uint *)(&this->field_0xf8 + this->field_0x130 * 4) ^ 0x80000000;
    this->field_0x20 =
         f_op_msg_mng::0_5 +
         (float)((double)CONCAT44(0x43300000,uStack12) - dVar2) + this->field_0x14;
  }
  local_10 = 0x43300000;
  getRubyString(this,*(char **)&this->field_0x60,*(char **)&this->field_0x68,
                *(char **)&this->field_0x64,*(char **)&this->field_0x6c,"crest(s)","",
                &this->field_0x20,&this->field_0x24,&this->field_0x150);
  this->field_0x118 =
       this->field_0x118 + (int)*(char *)(*(int *)&this->field_0x3c + this->field_0x118 + 1);
  return;
}


namespace f_op_msg_mng {

/* __stdcall fopMsgM_centerPosCalc(fopMsgM_f2d_class,
                                   fopMsgM_f2d_class) */

undefined8 fopMsgM_centerPosCalc(cXy *param_1,cXy *param_2)

{
  return CONCAT44(param_1->x + param_2->x * 0_5,param_1->y + param_2->y * 0_5);
}


/* __stdcall fopMsgM_pane_parts_set(fopMsgM_pane_class *) */

void fopMsgM_pane_parts_set(fopMsgM_pane_class *this)

{
  undefined8 uVar1;
  cXy local_28;
  cXy local_20;
  
  (this->mPosTopLeftOrig).x = (this->mpPane->parent).mPosTL.x;
  (this->mPosTopLeftOrig).y = (this->mpPane->parent).mPosTL.y;
  (this->mSizeOrig).x = (this->mpPane->parent).mPosBR.x - (this->mpPane->parent).mPosTL.x;
  (this->mSizeOrig).y = (this->mpPane->parent).mPosBR.y - (this->mpPane->parent).mPosTL.y;
  local_28.x = (this->mSizeOrig).x;
  local_28.y = (this->mSizeOrig).y;
  local_20.x = (this->mPosTopLeftOrig).x;
  local_20.y = (this->mPosTopLeftOrig).y;
  uVar1 = fopMsgM_centerPosCalc(&local_20,&local_28);
  (this->mPosCenterOrig).x = (float)((ulonglong)uVar1 >> 0x20);
  (this->mPosCenterOrig).y = (float)uVar1;
  this->mAlphaOrig = (this->mpPane->parent).mAlpha;
  (this->mPosTopLeft).x = (this->mPosTopLeftOrig).x;
  (this->mPosTopLeft).y = (this->mPosTopLeftOrig).y;
  (this->mPosCenter).x = (this->mPosCenterOrig).x;
  (this->mPosCenter).y = (this->mPosCenterOrig).y;
  (this->mSize).x = (this->mSizeOrig).x;
  (this->mSize).y = (this->mSizeOrig).y;
  this->mAlpha = 0;
  this->mUserData = 0;
  return;
}


/* __stdcall fopMsgM_pane_parts_set(fopMsgM_pane_alpha_class *) */

void fopMsgM_pane_parts_set(int *param_1)

{
  *(undefined *)(param_1 + 1) = *(undefined *)(*param_1 + 0xac);
  *(undefined *)((int)param_1 + 5) = 0;
  return;
}


/* __stdcall fopMsgM_setPaneData(fopMsgM_pane_class *,
                                 J2DPane *) */

void fopMsgM_setPaneData(fopMsgM_pane_class *param_1,J2DScreen *param_2)

{
  if (param_2 != (J2DScreen *)0x0) {
    param_1->mpPane = param_2;
    fopMsgM_pane_parts_set(param_1);
  }
  return;
}


/* __stdcall fopMsgM_setPaneData(fopMsgM_pane_class *,
                                 J2DScreen *,
                                 unsigned long) */

void fopMsgM_setPaneData(fopMsgM_pane_class *pPane,J2DScreen *pScreen,int fourcc)

{
  J2DPane *pJVar1;
  
  pJVar1 = (J2DPane *)(*(code *)((pScreen->parent).vtbl)->search)(pScreen,fourcc);
  if (pJVar1 != (J2DPane *)0x0) {
    pPane->mpPane = (J2DScreen *)pJVar1;
    fopMsgM_pane_parts_set(pPane);
  }
  return;
}


/* __stdcall fopMsgM_setPaneData(fopMsgM_pane_alpha_class *,
                                 J2DPane *) */

void fopMsgM_setPaneData(fopMsgM_pane_class *this,J2DScreen *pData)

{
  if (pData != (J2DScreen *)0x0) {
    this->mpPane = pData;
    fopMsgM_pane_parts_set();
  }
  return;
}


/* __stdcall fopMsgM_setPaneData(fopMsgM_pane_alpha_class *,
                                 J2DScreen *,
                                 unsigned long) */

void fopMsgM_setPaneData(int *param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  ulong uVar2;
  
  iVar1 = (**(code **)(*param_2 + 0x30))(param_2,param_3);
  if (iVar1 == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"f_op_msg_mng.cpp",0x398d,"0");
    m_Do_printf::OSPanic("f_op_msg_mng.cpp",0x398d,&DAT_8033c3e5);
  }
  else {
    *param_1 = iVar1;
    fopMsgM_pane_parts_set(param_1);
  }
  return;
}


/* __stdcall fopMsgM_paneTrans(fopMsgM_pane_class *,
                               float,
                               float) */

void fopMsgM_paneTrans(fopMsgM_pane_class *param_1,double x,double y)

{
  (param_1->mPosCenter).x = (float)((double)(param_1->mPosCenterOrig).x + x);
  (param_1->mPosCenter).y = (float)((double)(param_1->mPosCenterOrig).y + y);
  fopMsgM_cposMove(param_1);
  return;
}


/* __stdcall fopMsgM_paneScaleX(fopMsgM_pane_class *,
                                float) */

void fopMsgM_paneScaleX(double param_1,fopMsgM_pane_class *param_2)

{
  (param_2->mSize).x = (float)((double)(param_2->mSizeOrig).x * param_1);
  fopMsgM_cposMove(param_2);
  return;
}


/* __stdcall fopMsgM_paneScaleY(fopMsgM_pane_class *,
                                float) */

void fopMsgM_paneScaleY(double param_1,fopMsgM_pane_class *param_2)

{
  (param_2->mSize).y = (float)((double)(param_2->mSizeOrig).y * param_1);
  fopMsgM_cposMove(param_2);
  return;
}


/* __stdcall fopMsgM_paneScale(fopMsgM_pane_class *,
                               float,
                               float) */

void fopMsgM_paneScale(double param_1,double param_2,fopMsgM_pane_class *param_3)

{
  (param_3->mSize).x = (float)((double)(param_3->mSizeOrig).x * param_1);
  (param_3->mSize).y = (float)((double)(param_3->mSizeOrig).y * param_2);
  fopMsgM_cposMove(param_3);
  return;
}


/* __stdcall fopMsgM_paneScaleXY(fopMsgM_pane_class *,
                                 float) */

void fopMsgM_paneScaleXY(fopMsgM_pane_class *param_1,float param_2)

{
  (param_1->mSize).x = (param_1->mSizeOrig).x * param_2;
  (param_1->mSize).y = (param_1->mSizeOrig).y * param_2;
  fopMsgM_cposMove(param_1);
  return;
}


/* __stdcall fopMsgM_cposMove(fopMsgM_pane_class *) */

void fopMsgM_cposMove(fopMsgM_pane_class *this)

{
  float fVar1;
  
  fVar1 = 0_5;
  (this->mPosTopLeft).x = (this->mPosCenter).x - (this->mSize).x * 0_5;
  (this->mPosTopLeft).y = (this->mPosCenter).y - (this->mSize).y * fVar1;
  (*(code *)((this->mpPane->parent).vtbl)->move)
            ((double)(this->mPosTopLeft).x,(double)(this->mPosTopLeft).y);
  (*(code *)((this->mpPane->parent).vtbl)->resize)((double)(this->mSize).x,(double)(this->mSize).y);
  return;
}


/* __stdcall fopMsgM_setAlpha(fopMsgM_pane_class *) */

void fopMsgM_setAlpha(fopMsgM_pane_class *param_1)

{
  (param_1->mpPane->parent).mAlpha = param_1->mAlpha;
  return;
}


/* __stdcall fopMsgM_setInitAlpha(fopMsgM_pane_class *) */

void fopMsgM_setInitAlpha(int param_1)

{
  *(undefined *)(param_1 + 0x35) = *(undefined *)(param_1 + 0x34);
  return;
}


/* __stdcall fopMsgM_setNowAlpha(fopMsgM_pane_class *,
                                 float) */

void fopMsgM_setNowAlpha(fopMsgM_pane_class *this,float alpha)

{
  this->mAlpha = (byte)(int)((float)((double)CONCAT44(0x43300000,(uint)this->mAlphaOrig) - _5509) *
                            alpha);
  return;
}


/* __stdcall fopMsgM_setNowAlphaZero(fopMsgM_pane_class *) */

void fopMsgM_setNowAlphaZero(fopMsgM_pane_class *param_1)

{
  param_1->mAlpha = 0;
  return;
}


/* __stdcall fopMsgM_setAlpha(fopMsgM_pane_alpha_class *) */

void fopMsgM_setAlpha(int *param_1)

{
  *(undefined *)(*param_1 + 0xac) = *(undefined *)((int)param_1 + 5);
  return;
}


/* __stdcall fopMsgM_setNowAlpha(fopMsgM_pane_alpha_class *,
                                 float) */

void fopMsgM_setNowAlpha(double param_1,int param_2)

{
  *(char *)(param_2 + 5) =
       (char)(int)((double)(float)((double)CONCAT44(0x43300000,(uint)*(byte *)(param_2 + 4)) - _5509
                                  ) * param_1);
  return;
}


/* WARNING: Removing unreachable block (ram,0x8003bf4c) */
/* __stdcall fopMsgM_valueIncrease(int,
                                   int,
                                   unsigned char) */

double fopMsgM_valueIncrease(uint param_1,uint param_2,byte param_3)

{
  double dVar1;
  double dVar2;
  double local_8;
  
  if ((int)param_1 < 1) {
    dVar2 = (double)1_0;
  }
  else {
    if ((int)param_2 < 0) {
      param_2 = 0;
    }
    else {
      if ((int)param_1 < (int)param_2) {
        param_2 = param_1;
      }
    }
    local_8 = (double)CONCAT44(0x43300000,param_1 ^ 0x80000000);
    dVar2 = (double)((float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - _4895) /
                    (float)(local_8 - _4895));
    if (param_3 == 3) {
      dVar2 = (double)((float)((double)_5001 * (double)((float)((double)_5001 * dVar2) - 1_0)) - 1_0
                      );
    }
    else {
      if (param_3 < 3) {
        if (param_3 == 1) {
          if ((double)0_0 < dVar2) {
            dVar1 = 1.0 / SQRT(dVar2);
            dVar1 = _4999 * dVar1 * (_5000 - dVar2 * dVar1 * dVar1);
            dVar1 = _4999 * dVar1 * (_5000 - dVar2 * dVar1 * dVar1);
            dVar2 = (double)(float)(dVar2 * _4999 * dVar1 * (_5000 - dVar2 * dVar1 * dVar1));
          }
        }
        else {
          if (param_3 == 0) {
            dVar2 = (double)(float)(dVar2 * dVar2);
          }
        }
      }
      else {
        if (param_3 == 5) {
          dVar2 = (double)(JKernel::JMath::jmaSinTable
                           [(int)((int)(0_5 * (float)((double)_9135 * dVar2)) & 0xffffU) >>
                            (JKernel::JMath::jmaSinShift & 0x3f)] *
                          JKernel::JMath::jmaSinTable
                          [(int)((int)(0_5 * (float)((double)_9135 * dVar2)) & 0xffffU) >>
                           (JKernel::JMath::jmaSinShift & 0x3f)]);
        }
        else {
          if (param_3 < 5) {
            dVar2 = (double)(JKernel::JMath::jmaSinTable
                             [(int)((int)(0_5 * (float)((double)_9134 * dVar2)) & 0xffffU) >>
                              (JKernel::JMath::jmaSinShift & 0x3f)] *
                            JKernel::JMath::jmaSinTable
                            [(int)((int)(0_5 * (float)((double)_9134 * dVar2)) & 0xffffU) >>
                             (JKernel::JMath::jmaSinShift & 0x3f)]);
          }
        }
      }
    }
  }
  return dVar2;
}


/* __stdcall fopMsgM_blendInit(fopMsgM_pane_class *,
                               char const *) */

void fopMsgM_blendInit(fopMsgM_pane_class *param_1,char *param_2)

{
  float fVar1;
  J2DPicture *this;
  
  ::J2DPicture::insert
            ((J2DPicture *)param_1->mpPane,param_2,((J2DPicture *)param_1->mpPane)->mNumTexture,1_0)
  ;
  this = (J2DPicture *)param_1->mpPane;
  this->mBlendKonstColorF[0] = 0_0;
  fVar1 = 1_0;
  this->mBlendKonstColorF[1] = 1_0;
  this->mBlendKonstColorF[2] = fVar1;
  this->mBlendKonstColorF[3] = fVar1;
  ::J2DPicture::setBlendKonstColor(this);
  this->mBlendKonstAlphaF[0] = 0_0;
  fVar1 = 1_0;
  this->mBlendKonstAlphaF[1] = 1_0;
  this->mBlendKonstAlphaF[2] = fVar1;
  this->mBlendKonstAlphaF[3] = fVar1;
  ::J2DPicture::setBlendKonstAlpha(this);
  return;
}


/* __stdcall fopMsgM_blendInit(J2DPicture *,
                               char const *) */

void fopMsgM_blendInit(J2DPicture *param_1,char *param_2)

{
  float fVar1;
  
  ::J2DPicture::insert(param_1,param_2,param_1->mNumTexture,1_0);
  param_1->mBlendKonstColorF[0] = 0_0;
  fVar1 = 1_0;
  param_1->mBlendKonstColorF[1] = 1_0;
  param_1->mBlendKonstColorF[2] = fVar1;
  param_1->mBlendKonstColorF[3] = fVar1;
  ::J2DPicture::setBlendKonstColor(param_1);
  param_1->mBlendKonstAlphaF[0] = 0_0;
  fVar1 = 1_0;
  param_1->mBlendKonstAlphaF[1] = 1_0;
  param_1->mBlendKonstAlphaF[2] = fVar1;
  param_1->mBlendKonstAlphaF[3] = fVar1;
  ::J2DPicture::setBlendKonstAlpha(param_1);
  return;
}


/* __stdcall fopMsgM_blendDraw(fopMsgM_pane_class *,
                               char const *) */

void fopMsgM_blendDraw(J2DPicture **param_1,char *param_2)

{
  ((*param_1)->parent).mbDraw = 1;
  ::J2DPicture::remove(*param_1,(char *)((*param_1)->mNumTexture - 1 & 0xff));
  ::J2DPicture::insert(*param_1,param_2,(*param_1)->mNumTexture,1_0);
  return;
}


/* __stdcall fopMsgM_blendDraw(J2DPicture *,
                               char const *) */

void fopMsgM_blendDraw(J2DPicture *pPic,char *param_2)

{
  (pPic->parent).mbDraw = 1;
  ::J2DPicture::remove(pPic,(char *)(pPic->mNumTexture - 1 & 0xff));
  ::J2DPicture::insert(pPic,param_2,pPic->mNumTexture,1_0);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall fopMsgM_setFontsizeCenter(char *,
                                       char *,
                                       char *,
                                       char *,
                                       int,
                                       int) */

void fopMsgM_setFontsizeCenter
               (char *param_1,char *param_2,char *param_3,char *param_4,int param_5,int param_6)

{
  uint uVar1;
  int iVar2;
  char local_48 [12];
  char acStack60 [44];
  
  uVar1 = param_6 - param_5;
  iVar2 = ((int)uVar1 >> 1) + (uint)((int)uVar1 < 0 && (uVar1 & 1) != 0);
  if (iVar2 < 1) {
    if (iVar2 < 0) {
      MSL_C.PPCEABI.bare.H::sprintf(acStack60,"\x1bFX[%d]\x1bFY[%d]",param_6,param_6);
      local_48[0] = '\0';
      MSL_C.PPCEABI.bare.H::strcat(param_1,acStack60);
      MSL_C.PPCEABI.bare.H::strcat(param_2,acStack60);
      MSL_C.PPCEABI.bare.H::strcat(param_3,local_48);
      MSL_C.PPCEABI.bare.H::strcat(param_4,local_48);
    }
    else {
      if (param_5 != param_6) {
        MSL_C.PPCEABI.bare.H::sprintf(acStack60,"\x1bFX[%d]\x1bFY[%d]",param_6,param_6);
        MSL_C.PPCEABI.bare.H::strcat(param_1,acStack60);
        MSL_C.PPCEABI.bare.H::strcat(param_2,acStack60);
      }
    }
  }
  else {
    MSL_C.PPCEABI.bare.H::sprintf(acStack60,"\x1bFX[%d]\x1bFY[%d]",param_6,param_6);
    local_48[0] = '\0';
    MSL_C.PPCEABI.bare.H::strcat(param_1,acStack60);
    MSL_C.PPCEABI.bare.H::strcat(param_2,acStack60);
    MSL_C.PPCEABI.bare.H::strcat(param_3,local_48);
    MSL_C.PPCEABI.bare.H::strcat(param_4,local_48);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall fopMsgM_setFontsizeCenter2(char *,
                                        char *,
                                        char *,
                                        char *,
                                        int,
                                        int,
                                        int,
                                        int) */

void fopMsgM_setFontsizeCenter2
               (char *param_1,char *param_2,char *param_3,char *param_4,undefined4 param_5,
               undefined4 param_6)

{
  char local_48 [12];
  char acStack60 [44];
  
  MSL_C.PPCEABI.bare.H::sprintf(acStack60,"\x1bFX[%d]\x1bFY[%d]",param_6,param_6);
  local_48[0] = '\0';
  MSL_C.PPCEABI.bare.H::strcat(param_1,acStack60);
  MSL_C.PPCEABI.bare.H::strcat(param_2,acStack60);
  MSL_C.PPCEABI.bare.H::strcat(param_3,local_48);
  MSL_C.PPCEABI.bare.H::strcat(param_4,local_48);
  return;
}


/* __stdcall fopMsgM_createExpHeap(unsigned long) */

JKRHeap * fopMsgM_createExpHeap(ulong param_1)

{
  JKRExpHeap *pJVar1;
  
  pJVar1 = m_Do_ext::mDoExt_getGameHeap();
  pJVar1 = JKRExpHeap::create(param_1,&pJVar1->parent,false);
  return &pJVar1->parent;
}


/* __stdcall fopMsgM_destroyExpHeap(JKRExpHeap *) */

void fopMsgM_destroyExpHeap(JKRHeap *param_1)

{
  JKRHeap::destroy(param_1);
  return;
}

}

/* __thiscall MyPicture::~MyPicture(void) */

void __thiscall MyPicture::_MyPicture(MyPicture *this)

{
  short in_r4;
  
  if (this != (MyPicture *)0x0) {
    (this->parent).parent.vtbl = (J2DPane__vtable *)&__vt;
    J2DPicture::_J2DPicture(&this->parent,0);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J2DPicture::getTypeID(void) */

J2DTypeID __thiscall J2DPicture::getTypeID(J2DPicture *this)

{
  return J2DPicture;
}


/* __thiscall J2DPicture::drawOut(float,
                                  float,
                                  float,
                                  float,
                                  float,
                                  float,
                                  float,
                                  float) */

void __thiscall
J2DPicture::drawOut(J2DPicture *this,float param_1,float param_2,float param_3,float param_4,
                   float param_5,float param_6,float param_7,float param_8)

{
  TBox2_float_ local_28;
  TBox2_float_ local_18;
  
  local_28.mBR.x = param_5 + param_7;
  local_28.mBR.y = param_6 + param_8;
  local_18.mBR.x = param_1 + param_3;
  local_18.mBR.y = param_2 + param_4;
  local_28.mTL.x = param_5;
  local_28.mTL.y = param_6;
  local_18.mTL.x = param_1;
  local_18.mTL.y = param_2;
  drawOut(this,&local_18,&local_28);
  return;
}


/* __thiscall J2DPicture::drawOut(float,
                                  float,
                                  float,
                                  float,
                                  float,
                                  float) */

void __thiscall
J2DPicture::drawOut(J2DPicture *this,float param_1,float param_2,float param_3,float param_4,
                   float param_5,float param_6)

{
  ResTIMG *pRVar1;
  TBox2_float_ local_38;
  TBox2_float_ local_28;
  undefined4 local_18;
  uint uStack20;
  undefined4 local_10;
  uint uStack12;
  
  if (this->mpTexture[0] != (JUTTexture *)0x0) {
    pRVar1 = this->mpTexture[0]->mpTIMG;
    uStack20 = pRVar1->mWidth ^ 0x80000000;
    local_18 = 0x43300000;
    local_38.mBR.x = param_5 + (float)((double)CONCAT44(0x43300000,uStack20) - f_op_msg_mng::_4895);
    uStack12 = pRVar1->mHeight ^ 0x80000000;
    local_10 = 0x43300000;
    local_38.mBR.y = param_6 + (float)((double)CONCAT44(0x43300000,uStack12) - f_op_msg_mng::_4895);
    local_28.mBR.x = param_1 + param_3;
    local_28.mBR.y = param_2 + param_4;
    local_38.mTL.x = param_5;
    local_38.mTL.y = param_6;
    local_28.mTL.x = param_1;
    local_28.mTL.y = param_2;
    drawOut(this,&local_28,&local_38);
  }
  return;
}


/* __thiscall J2DPane::setConnectParent(bool) */

undefined4 __thiscall J2DPane::setConnectParent(J2DPane *this,bool param_1)

{
  this->field_0xaf = 0;
  return 0;
}


/* __thiscall J2DPane::update(void) */

void __thiscall J2DPane::update(J2DPane *this)

{
  return;
}


namespace f_op_msg_mng {

void __sinit_f_op_msg_mng_cpp(void)

{
  stick.vtbl = (undefined *)&STControl::__vt;
  STControl::setWaitParm(&stick,0xf,0xf,0,0,0_9,0_5,0,0x2000);
  STControl::init(&stick);
  return;
}

