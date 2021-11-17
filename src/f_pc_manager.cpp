#include <f_pc_manager.h>
#include <f_pc_draw.h>
#include <f_pc_layer.h>
#include <f_pc_layer_iter.h>
#include <f_pc_executor.h>
#include <f_pc_deletor.h>
#include <f_pc_creator.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JKernel/JKRHeap.h>
#include <J2DGraph/J2DTextBox.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <J2DGraph/J2DPicture.h>
#include <JUtility/JUTResFont.h>
#include <gx/GXPixel.h>
#include <J3DGraphBase/J3DSys.h>
#include <J2DGraph/J2DOrthoGraph.h>
#include <f_pc_manager.h>
#include <JAudio/JAIStreamMgr.h>
#include <dvd/dvd.h>
#include <m_Do_Reset.h>
#include <SComponent/c_lib.h>
#include <SComponent/c_API_graphic.h>
#include <f_pc_priority.h>
#include <f_pc_line.h>
#include <f_pc_fstcreate_req.h>
#include <f_pc_pause.h>
#include <f_pc_create_iter.h>


namespace f_pc_manager {
struct layer_class rootlayer$4264;
struct node_list_class queue$4265[10];
undefined4 l_dvdError$4230;
undefined1 init$4231;

/* __stdcall fpcM_Draw(void *) */

void fpcM_Draw(void *param_1)

{
  f_pc_draw::fpcDw_Execute((base_process_class *)param_1);
  return;
}


/* __stdcall fpcM_DrawIterater(int *(void *,void *)) */

void fpcM_DrawIterater(undefined4 param_1)

{
  layer_class *plVar1;
  
  plVar1 = f_pc_layer::fpcLy_RootLayer();
  f_pc_layer_iter::fpcLyIt_OnlyHere(plVar1,param_1,0);
  return;
}


/* __stdcall fpcM_Execute(void *) */

void fpcM_Execute(void *param_1)

{
  f_pc_executor::fpcEx_Execute((base_process_class *)param_1);
  return;
}


/* __stdcall fpcM_Delete(void *) */

void fpcM_Delete(base_process_class *param_1)

{
  f_pc_deletor::fpcDt_Delete(param_1);
  return;
}


/* __stdcall fpcM_IsCreating(unsigned int) */

void fpcM_IsCreating(void)

{
  f_pc_creator::fpcCt_IsCreatingByID();
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Removing unreachable block (ram,0x8003e9c8) */
/* WARNING: Removing unreachable block (ram,0x8003e9d0) */
/* __stdcall messageSet(unsigned long) */

void messageSet(int param_1)

{
  char cVar1;
  float fVar2;
  J2DTextBox *this;
  ulong uVar3;
  J2DTextBox *this_00;
  J2DPicture *this_01;
  JUTResFont *this_02;
  int iVar4;
  int iVar5;
  short sVar6;
  char *pcVar7;
  int iVar8;
  undefined4 uVar9;
  undefined8 in_f30;
  undefined8 in_f31;
  double dVar10;
  double dVar11;
  undefined uStack232;
  byte local_e7;
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
  float local_ac;
  float local_a8;
  float local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  TBox2_float_ local_94;
  TBox2_float_ local_84;
  TBox2_float_ local_74;
  float local_64 [7];
  undefined4 local_48;
  uint uStack68;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar9 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  pcVar7 = &UNK_8033c728 + DAT_8033c724 + *(int *)(&DAT_8033c730 + param_1 * 4);
  this = (J2DTextBox *)JKernel::operator_new(0x100);
  if (this != (J2DTextBox *)0x0) {
    local_74.mTL.x = _4141;
    local_74.mTL.y = _4141;
    local_74.mBR.x = _4142;
    local_74.mBR.y = _4143;
    J2DTextBox::J2DTextBox(this,0x54585431,&local_74,(ResFONT *)"FONTbfn1",pcVar7,0,0);
  }
  if (this == (J2DTextBox *)0x0) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"f_pc_manager.cpp",0x141,"tpane != 0");
    m_Do_printf::OSPanic("f_pc_manager.cpp",0x141,&DAT_8034ebdc);
  }
  this_00 = (J2DTextBox *)JKernel::operator_new(0x100);
  if (this_00 != (J2DTextBox *)0x0) {
    local_84.mTL.x = _4141;
    local_84.mTL.y = _4141;
    local_84.mBR.x = _4142;
    local_84.mBR.y = _4143;
    J2DTextBox::J2DTextBox(this_00,0x54585432,&local_84,(ResFONT *)"FONTbfn1",pcVar7,0,0);
  }
  if (this_00 == (J2DTextBox *)0x0) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"f_pc_manager.cpp",0x149,"spane != 0");
    m_Do_printf::OSPanic("f_pc_manager.cpp",0x149,&DAT_8034ebdc);
  }
  this_01 = (J2DPicture *)JKernel::operator_new(0x124);
  if (this_01 != (J2DPicture *)0x0) {
    local_94.mTL.x = _4141;
    local_94.mTL.y = _4141;
    local_94.mBR.x = _4144;
    local_94.mBR.y = _4145;
    J2DPicture::J2DPicture(this_01,0x50494331,&local_94,(ResTIMG *)&black_tex,(ResTLUT *)0x0);
  }
  if (this_01 == (J2DPicture *)0x0) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"f_pc_manager.cpp",0x14e,"ppane != 0");
    m_Do_printf::OSPanic("f_pc_manager.cpp",0x14e,&DAT_8034ebdc);
  }
  local_ac = _4146;
  local_9c = _4146;
  local_98 = _4146;
  local_a4 = _4146;
  local_a0 = _4146;
  fVar2 = _4141;
  if (_4141 < _4146) {
    fVar2 = _4146;
  }
  this->mFontWidth = fVar2;
  fVar2 = _4141;
  if (_4141 < local_ac) {
    fVar2 = local_ac;
  }
  this->mFontHeight = fVar2;
  local_b4 = 0xffc800ff;
  local_b0 = 0xffc800ff;
  local_d8 = 0xffc800ff;
  this->mColorGradient[0].r = 0xff;
  this->mColorGradient[0].g = 200;
  this->mColorGradient[0].b = 0;
  this->mColorGradient[0].a = 0xff;
  local_bc = 0xffb400ff;
  local_b8 = 0xffb400ff;
  local_dc = 0xffb400ff;
  this->mColorGradient[1].r = 0xff;
  this->mColorGradient[1].g = 0xb4;
  this->mColorGradient[1].b = 0;
  this->mColorGradient[1].a = 0xff;
  fVar2 = _4141;
  this->field_0xe0 = _4141;
  this->mFontLeading = _4146;
  local_c4 = 0xffffff00;
  local_c0 = 0xffffff00;
  (this->mTextBgColor).r = 0xff;
  (this->mTextBgColor).g = 0xff;
  (this->mTextBgColor).b = 0xff;
  (this->mTextBgColor).a = 0;
  local_a8 = local_ac;
  if (fVar2 < local_ac) {
    fVar2 = local_ac;
  }
  this_00->mFontWidth = fVar2;
  fVar2 = _4141;
  if (_4141 < local_ac) {
    fVar2 = local_ac;
  }
  this_00->mFontHeight = fVar2;
  local_cc = 200;
  local_c8 = 200;
  local_e0 = 200;
  this_00->mColorGradient[0].r = 0;
  this_00->mColorGradient[0].g = 0;
  this_00->mColorGradient[0].b = 0;
  this_00->mColorGradient[0].a = 200;
  local_d4 = 200;
  local_d0 = 200;
  local_e4 = 200;
  this_00->mColorGradient[1].r = 0;
  this_00->mColorGradient[1].g = 0;
  this_00->mColorGradient[1].b = 0;
  this_00->mColorGradient[1].a = 200;
  this_00->field_0xe0 = _4141;
  this_00->mFontLeading = _4146;
  (this_01->parent).mAlpha = 0x82;
  this_02 = (JUTResFont *)JKernel::operator_new(0x70);
  if (this_02 != (JUTResFont *)0x0) {
    JUTResFont::JUTResFont(this_02,(ResFONT *)"FONTbfn1",(JKRHeap *)0x0);
  }
  sVar6 = 0x1b;
  dVar10 = (double)_4141;
  iVar5 = 0;
  iVar4 = 0;
  iVar8 = 6;
  do {
    *(float *)((int)local_64 + iVar4) = _4141;
    iVar4 = iVar4 + 4;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  for (; cVar1 = *pcVar7, cVar1 != '\0'; pcVar7 = pcVar7 + 1) {
    if (cVar1 == '\n') {
      sVar6 = sVar6 + 0x1b;
      iVar5 = iVar5 + 4;
    }
    else {
      (*(code *)((this_02->parent).vtbl)->getWidthEntry)(this_02,cVar1,&uStack232);
      uStack68 = local_e7 ^ 0x80000000;
      local_48 = 0x43300000;
      *(float *)((int)local_64 + iVar5) =
           *(float *)((int)local_64 + iVar5) +
           (float)((double)CONCAT44(0x43300000,local_e7 ^ 0x80000000) - _4156);
    }
  }
  iVar4 = 0;
  iVar5 = 6;
  do {
    if (dVar10 < (double)*(float *)((int)local_64 + iVar4)) {
      dVar10 = (double)*(float *)((int)local_64 + iVar4);
    }
    iVar4 = iVar4 + 4;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  dVar10 = (double)(_4147 + (float)((double)_4148 - dVar10) * _4149);
  uStack68 = 0x20cU - (int)sVar6 ^ 0x80000000;
  local_48 = 0x43300000;
  dVar11 = (double)(_4150 + (float)((double)CONCAT44(0x43300000,uStack68) - _4156) * _4149);
  J2DPicture::draw(this_01,_4151,_4152,_4144,_4145,false,false,false);
  dVar11 = (double)(float)((double)_4154 + dVar11);
  J2DTextBox::draw(this_00,(float)((double)_4153 + dVar10),(float)((double)_4153 + dVar11),_4142,2);
  J2DTextBox::draw(this,(float)dVar10,(float)dVar11,_4142,2);
  if (this_02 != (JUTResFont *)0x0) {
    (*(code *)((this_02->parent).vtbl)->_)(this_02,1);
  }
  if (this_01 != (J2DPicture *)0x0) {
    (*(code *)((this_01->parent).vtbl)->_J2DPane)(this_01,1);
  }
  if (this != (J2DTextBox *)0x0) {
    (*(code *)((this->parent).vtbl)->_J2DPane)(this,1);
  }
  if (this_00 != (J2DTextBox *)0x0) {
    (*(code *)((this_00->parent).vtbl)->_J2DPane)(this_00,1);
  }
  __psq_l0(auStack8,uVar9);
  __psq_l1(auStack8,uVar9);
  __psq_l0(auStack24,uVar9);
  __psq_l1(auStack24,uVar9);
  return;
}


/* __stdcall drawDvdCondition(long) */

void drawDvdCondition(___ param_1)

{
  undefined4 uVar1;
  JFWDisplay *pJVar2;
  StreamLib *this;
  ulong uVar3;
  u8 uStack246;
  u8 uStack245;
  u8 local_f4;
  u8 uStack243;
  TBox2_float_ local_ec;
  J2DOrthoGraph local_dc;
  
  JFWDisplay::sManager->mpFader = (JUTFader *)0x0;
  pJVar2 = JFWDisplay::sManager;
  uVar1 = mDoGph_gInf_c::mBackColor;
  uStack246 = (u8)((uint)mDoGph_gInf_c::mBackColor >> 8);
  uStack245 = (u8)mDoGph_gInf_c::mBackColor;
  local_f4 = (u8)((uint)mDoGph_gInf_c::mBackColor >> 0x18);
  (JFWDisplay::sManager->mClearColor).r = local_f4;
  uStack243 = (u8)((uint)uVar1 >> 0x10);
  (pJVar2->mClearColor).g = uStack243;
  (pJVar2->mClearColor).b = uStack246;
  (pJVar2->mClearColor).a = uStack245;
  (**(code **)(*(int *)JFWDisplay::sManager + 8))();
  gx::GXSetAlphaUpdate(0);
  J3DSys::drawInit(&J3DGraphBase::j3dSys);
  J2DOrthoGraph::J2DOrthoGraph(&local_dc,_4141,_4141,_4217,_4218,_4219,_4220);
  local_ec.mTL.x = _4147;
  local_ec.mTL.y = _4150;
  local_ec.mBR.x = _4221;
  local_ec.mBR.y = _4222;
  J2DOrthoGraph::setOrtho(&local_dc,&local_ec,_4219,_4220);
  J2DOrthoGraph::setPort(&local_dc);
  d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph = &local_dc;
  if (param_1 == 4) {
    messageSet(2);
  }
  else {
    if (param_1 == 5) {
      messageSet(1);
    }
    else {
      if (param_1 == 6) {
        messageSet(3);
      }
      else {
        if (param_1 == 0xb) {
          messageSet(4);
        }
        else {
          if (param_1 == 1) {
            messageSet(0);
          }
          else {
            if (param_1 == 0xffffffff) {
              this = (StreamLib *)messageSet(5);
              JAInter::StreamLib::stop(this);
            }
            else {
              uVar3 = JUTAssertion::getSDevice();
              JUTAssertion::setWarningMessage_f
                        (uVar3,"f_pc_manager.cpp",0x1e1,"Dvd Error !! <%d>\n",param_1);
            }
          }
        }
      }
    }
  }
  (**(code **)(*(int *)JFWDisplay::sManager + 0xc))();
  return;
}


/* __stdcall checkDvdCondition(void) */

int checkDvdCondition(void)

{
  int iVar1;
  
  if (init_4231 == '\0') {
    l_dvdError_4230 = 0;
    init_4231 = '\x01';
  }
  iVar1 = dvd::DVDGetDriveStatus();
  if ((iVar1 != 0) && (iVar1 != 1)) {
    l_dvdError_4230 = 1;
  }
  if (l_dvdError_4230 != 0) {
    if (iVar1 == 0) {
      l_dvdError_4230 = 0;
    }
    else {
      if (*mDoRst::mResetData == 0) {
        drawDvdCondition();
      }
      else {
        *mDoRst::mResetData = 0;
        mDoRst::mResetData[1] = 0;
        m_Do_Reset::mDoRst_reset(1,0x80000000,0);
      }
    }
  }
  return l_dvdError_4230;
}


/* __stdcall fpcM_Management(void *(void),
                             void *(void)) */

void fpcM_Management(code *param_1,code *param_2)

{
  int iVar1;
  ulong uVar2;
  
  SComponent::MtxInit();
  iVar1 = checkDvdCondition();
  if (iVar1 == 0) {
    SComponent::cAPIGph_Painter();
    f_pc_deletor::fpcDt_Handler();
    iVar1 = f_pc_priority::fpcPi_Handler();
    if (iVar1 == 0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"f_pc_manager.cpp",0x224,"0");
      m_Do_printf::OSPanic("f_pc_manager.cpp",0x224,&DAT_8034ebdc);
    }
    iVar1 = f_pc_creator::fpcCt_Handler();
    if (iVar1 == 0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"f_pc_manager.cpp",0x228,"0");
      m_Do_printf::OSPanic("f_pc_manager.cpp",0x228,&DAT_8034ebdc);
    }
    if (param_1 != (code *)0x0) {
      (*param_1)();
    }
    f_pc_executor::fpcEx_Handler(fpcM_Execute);
    f_pc_draw::fpcDw_Handler(fpcM_DrawIterater,fpcM_Draw);
    if (param_2 != (code *)0x0) {
      (*param_2)();
    }
  }
  return;
}


/* __stdcall fpcM_Init(void) */

void fpcM_Init(void)

{
  f_pc_layer::fpcLy_Create(&rootlayer_4264,(void *)0x0,queue_4265,10);
  f_pc_line::fpcLn_Create();
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall fpcM_FastCreate(short,
                             int *(void *),
                             void *,
                             void *) */

void fpcM_FastCreate(short param_1,undefined *param_2,void *param_3,void *param_4)

{
  layer_class *plVar1;
  
  plVar1 = f_pc_layer::fpcLy_CurrentLayer();
  f_pc_fstcreate_req::fpcFCtRq_Request(plVar1,param_1,param_2,param_3,param_4);
  return;
}


/* __stdcall fpcM_IsPause(void *,
                          unsigned char) */

void fpcM_IsPause(base_process_class *param_1,undefined1 param_2)

{
  f_pc_pause::fpcPause_IsEnable(param_1,param_2);
  return;
}


/* __stdcall fpcM_PauseEnable(void *,
                              unsigned char) */

void fpcM_PauseEnable(process_node_class *param_1,byte param_2)

{
  f_pc_pause::fpcPause_Enable(param_1,param_2);
  return;
}


/* __stdcall fpcM_PauseDisable(void *,
                               unsigned char) */

void fpcM_PauseDisable(base_process_class *param_1,byte param_2)

{
  f_pc_pause::fpcPause_Disable(param_1,param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall fpcM_JudgeInLayer(unsigned int,
                               void * *(void *,void *),
                               void *) */

int fpcM_JudgeInLayer(uint param_1,undefined4 param_2,undefined4 param_3)

{
  layer_class *plVar1;
  int iVar2;
  
  plVar1 = f_pc_layer::fpcLy_Layer(param_1);
  if (plVar1 == (layer_class *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = f_pc_create_iter::fpcCtIt_JudgeInLayer(param_1,param_2,param_3);
    if (iVar2 == 0) {
      iVar2 = f_pc_layer_iter::fpcLyIt_Judge(plVar1,param_2,param_3);
    }
  }
  return iVar2;
}

