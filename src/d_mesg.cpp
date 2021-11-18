#include <d_mesg.h>
#include <JKernel/JKRHeap.h>
#include <J2DGraph/J2DPicture.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <f_op_msg_mng.h>
#include <d_mesg.h>
#include <JMessage/control.h>
#include <JMessage/processor.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <MSL_C.PPCEABI.bare.H/printf.h>
#include <d_save.h>
#include <d_com_inf_game.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <J2DGraph/J2DTextBox.h>
#include <J2DGraph/J2DPane.h>
#include <J2DGraph/J2DScreen.h>
#include <JKernel/JKRArchivePub.h>
#include <d_particle.h>
#include <JMessage/resource.h>
#include <JGadget/linklist.h>
#include <JGadget/binary.h>
#include <JKernel/JKRExpHeap.h>
#include <m_Do_ext.h>
#include <d_drawlist.h>
#include <JKernel/JKRFileLoader.h>
#include <dMesg_outFont_c.h>
#include <dMesg_screenDataItem_c.h>
#include <dMesg_tMeasureProcessor.h>
#include <dMesg_tSequenceProcessor.h>
#include <dMesg_tRenderingProcessor.h>
#include <dMesg_tControl.h>
#include <dMesg_screenData_c.h>
#include <dMesg_screenDataTalk_c.h>
#include <JMessage/TResourceContainer.h>


namespace d_mesg {
}

namespace JGadget {

namespace TLinkList_factory<JMessage::TResource,0> {
}
}

namespace d_mesg {
undefined4 dMesg_gpResourceContainer;
undefined4 dMesg_gpControl;
undefined4 dMesg_gpSequenceProcessor;
undefined4 dMesg_gpRenderingProcessor;
undefined4 dMesg_gpFont;
undefined4 dMesg_gpRFont;
undefined1 dMesg_gbUpdate;
undefined1 m_strSizeFlag;
undefined1 s_strSizeFlag;
undefined4 header;
undefined4 nowMesgCode;
undefined4 oldMesgCode;
undefined4 header2;
undefined1 headerFlag;
undefined2 messageOffsetY;
undefined1 zenkaku;
undefined2 zenkakuCode;
undefined4 retFlag;
undefined4 oParse;
}

/* __thiscall dMesg_outFont_c::_create(void) */

void __thiscall dMesg_outFont_c::_create(dMesg_outFont_c *this)

{
  J2DPicture *pJVar1;
  ulong uVar2;
  
  pJVar1 = (J2DPicture *)JKernel::operator_new(0x124);
  if (pJVar1 != (J2DPicture *)0x0) {
    J2DPicture::J2DPicture(pJVar1,"font_07_02.bti");
  }
  *(J2DPicture **)(this + 4) = pJVar1;
  if (*(int *)(this + 4) == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_mesg.cpp",0x75,"icon != 0");
    m_Do_printf::OSPanic("d_mesg.cpp",0x75,&DAT_803609f8);
  }
  pJVar1 = (J2DPicture *)JKernel::operator_new(0x124);
  if (pJVar1 != (J2DPicture *)0x0) {
    J2DPicture::J2DPicture(pJVar1,"font_07_02.bti");
  }
  *(J2DPicture **)(this + 8) = pJVar1;
  if (*(int *)(this + 8) == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_mesg.cpp",0x77,"kage != 0");
    m_Do_printf::OSPanic("d_mesg.cpp",0x77,&DAT_803609f8);
  }
  f_op_msg_mng::fopMsgM_blendInit(*(undefined4 *)(this + 4),"font_00.bti");
  f_op_msg_mng::fopMsgM_blendInit(*(undefined4 *)(this + 8),"font_00.bti");
  _initialize(this);
  return;
}


/* __thiscall dMesg_outFont_c::_delete(void) */

void __thiscall dMesg_outFont_c::_delete(dMesg_outFont_c *this)

{
  int *piVar1;
  
  piVar1 = *(int **)(this + 4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,1);
  }
  piVar1 = *(int **)(this + 8);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,1);
  }
  return;
}


/* __thiscall dMesg_outFont_c::_initialize(void) */

void __thiscall dMesg_outFont_c::_initialize(dMesg_outFont_c *this)

{
  int *piVar1;
  
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined2 *)(this + 0x14) = 0;
  *(undefined2 *)(this + 0x12) = 0;
  *(undefined2 *)(this + 0x10) = 0;
  *(undefined2 *)(this + 0x16) = 0xffff;
  this[0x19] = (dMesg_outFont_c)0xff;
  *(undefined *)(*(int *)(this + 4) + 0xaa) = 0;
  piVar1 = *(int **)(this + 4);
  piVar1[0x29] = (int)d_mesg::_4035;
  (**(code **)(*piVar1 + 0x20))();
  *(undefined *)(*(int *)(this + 4) + 0xac) = 0;
  *(undefined *)(*(int *)(this + 8) + 0xaa) = 0;
  piVar1 = *(int **)(this + 8);
  piVar1[0x29] = (int)d_mesg::_4035;
  (**(code **)(*piVar1 + 0x20))();
  *(undefined *)(*(int *)(this + 8) + 0xac) = 0;
  return;
}


/* __thiscall dMesg_outFont_c::_set(short,
                                    short,
                                    short,
                                    unsigned long,
                                    unsigned char) */

bool __thiscall
dMesg_outFont_c::_set
          (dMesg_outFont_c *this,short param_1,short param_2,short param_3,ulong param_4,
          uchar param_5)

{
  dMesg_outFont_c dVar1;
  
  dVar1 = this[0x19];
  if (dVar1 == (dMesg_outFont_c)0xff) {
    *(short *)(this + 0x10) = param_1;
    *(short *)(this + 0x12) = param_2;
    *(short *)(this + 0x14) = param_3;
    *(ulong *)(this + 0xc) = param_4;
    this[0x19] = (dMesg_outFont_c)param_5;
    f_op_msg_mng::fopMsgM_outFontSet
              (*(undefined4 *)(this + 4),*(undefined4 *)(this + 8),this + 0x16,
               *(undefined4 *)(this + 0xc),this[0x19]);
  }
  return dVar1 == (dMesg_outFont_c)0xff;
}


/* __thiscall dMesg_outFont_c::_draw(void) */

void __thiscall dMesg_outFont_c::_draw(dMesg_outFont_c *this)

{
  if (this[0x19] != (dMesg_outFont_c)0xff) {
    f_op_msg_mng::fopMsgM_outFontDraw
              (*(undefined4 *)(this + 4),*(undefined4 *)(this + 8),(int)*(short *)(this + 0x10),
               (int)*(short *)(this + 0x12),(int)*(short *)(this + 0x14),this + 0x16,this[0x18]);
  }
  return;
}


/* __thiscall dMesg_outFont_c::_setAlpha(unsigned char) */

void __thiscall dMesg_outFont_c::_setAlpha(dMesg_outFont_c *this,uchar param_1)

{
  if (this[0x19] == (dMesg_outFont_c)0xff) {
    return;
  }
  this[0x18] = (dMesg_outFont_c)param_1;
  return;
}


/* __thiscall dMesg_tControl::dMesg_tControl(void) */

void __thiscall dMesg_tControl::dMesg_tControl(dMesg_tControl *this)

{
  float fVar1;
  
  JMessage::TControl::TControl((TControl *)this);
  *(undefined1 **)this = &__vt;
  *(undefined4 *)(this + 0x3c) = 0;
  *(undefined4 *)(this + 0x54) = 0;
  *(undefined4 *)(this + 0x58) = 0;
  *(int *)(this + 0x5c) = (int)DAT_803e6bb4;
  *(int *)(this + 0x60) = (int)DAT_803e6bb4;
  *(undefined4 *)(this + 100) = 0;
  *(undefined4 *)(this + 0x68) = 0;
  *(undefined4 *)(this + 0x6c) = 0x1e6;
  this[0x70] = (dMesg_tControl)0x0;
  this[0x71] = (dMesg_tControl)0x0;
  fVar1 = d_mesg::_4035;
  *(float *)(this + 0x50) = d_mesg::_4035;
  *(float *)(this + 0x4c) = fVar1;
  *(float *)(this + 0x48) = fVar1;
  *(float *)(this + 0x44) = fVar1;
  return;
}


/* __thiscall dMesg_tControl::do_word(unsigned long) */

undefined * __thiscall dMesg_tControl::do_word(dMesg_tControl *this,ulong param_1)

{
  return (&d_mesg::name_4067)[param_1];
}


/* __thiscall dMesg_tSequenceProcessor::dMesg_tSequenceProcessor(JMessage::TControl *) */

void __thiscall
dMesg_tSequenceProcessor::dMesg_tSequenceProcessor(dMesg_tSequenceProcessor *this,TControl *param_1)

{
  float fVar1;
  
  JMessage::TSequenceProcessor::TSequenceProcessor((TSequenceProcessor *)this,param_1);
  *(undefined1 **)this = &__vt;
  fVar1 = d_mesg::_4035;
  *(float *)(this + 0x44) = d_mesg::_4035;
  *(float *)(this + 0x48) = fVar1;
  *(float *)(this + 0x4c) = fVar1;
  *(float *)(this + 0x50) = fVar1;
  *(float *)(this + 0x54) = fVar1;
  *(undefined4 *)(this + 0x6c) = 0xffffffff;
  *(undefined4 *)(this + 0x70) = 0;
  *(undefined4 *)(this + 0x74) = 0;
  *(undefined4 *)(this + 0x8c) = 1;
  *(undefined4 *)(this + 0x90) = 0;
  this[0x15f] = (dMesg_tSequenceProcessor)0x0;
  this[0x160] = (dMesg_tSequenceProcessor)0x0;
  this[0x161] = (dMesg_tSequenceProcessor)0x0;
  this[0x162] = (dMesg_tSequenceProcessor)0x0;
  this[0x163] = (dMesg_tSequenceProcessor)0x0;
  this[0x96] = (dMesg_tSequenceProcessor)0x0;
  this[0x95] = (dMesg_tSequenceProcessor)0x0;
  this[0x94] = (dMesg_tSequenceProcessor)0x0;
  *(undefined4 *)(this + 0x88) = 0;
  *(undefined4 *)(this + 0x84) = 0;
  *(undefined4 *)(this + 0x80) = 0;
  *(undefined4 *)(this + 0x7c) = 0;
  *(undefined4 *)(this + 0x68) = 0;
  *(undefined4 *)(this + 100) = 0;
  *(undefined4 *)(this + 0x60) = 0;
  *(undefined4 *)(this + 0x5c) = 0;
  MSL_C.PPCEABI.bare.H::strcpy((char *)(this + 0x97),"");
  MSL_C.PPCEABI.bare.H::strcpy((char *)(this + 0xfb),"");
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dMesg_tSequenceProcessor::initialize(int) */

void __thiscall dMesg_tSequenceProcessor::initialize(dMesg_tSequenceProcessor *this,int param_1)

{
  undefined4 *puVar1;
  float fVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  char *pcVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  char acStack152 [12];
  undefined4 uStack140;
  undefined4 local_88 [4];
  char local_78;
  undefined1 *local_70 [22];
  double local_18;
  
  iVar9 = *(int *)(this + 4);
  if (d_mesg::retFlag != 0) {
    d_mesg::retFlag = 0;
  }
  d_mesg::s_strSizeFlag = 0;
  d_mesg::m_strSizeFlag = '\0';
  dMesg_tMeasureProcessor::dMesg_tMeasureProcessor
            ((dMesg_tMeasureProcessor *)local_70,*(TControl **)(this + 4),param_1);
  pcVar8 = *(char **)(this + 0x40);
  uVar10 = *(undefined4 *)(this + 0x3c);
  JMessage::TSequenceProcessor::reset_((TSequenceProcessor *)local_70,pcVar8);
  (**(code **)(local_70[0] + 0x20))(local_70,uVar10,pcVar8);
  JMessage::TSequenceProcessor::process((TSequenceProcessor *)local_70,(char *)0x0);
  uVar3 = d_mesg::nowMesgCode;
  iVar11 = *(int *)(iVar9 + 0x54);
  iVar4 = JMessage::TControl::getResource_groupID
                    (d_mesg::dMesg_gpControl,(ushort)(d_mesg::nowMesgCode >> 0x10));
  if (iVar4 == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = *(int *)(iVar4 + 0xc);
    if ((uVar3 & 0xffff) < (uint)*(ushort *)(iVar4 + 8)) {
      iVar4 = iVar4 + (uVar3 & 0xffff) * (uint)*(ushort *)(iVar4 + 10) + 0x10;
    }
    else {
      iVar4 = 0;
    }
  }
  puVar7 = &uStack140;
  puVar5 = (undefined4 *)(iVar4 + -4);
  iVar4 = 3;
  do {
    puVar1 = puVar5 + 1;
    puVar5 = puVar5 + 2;
    uVar10 = *puVar5;
    puVar7[1] = *puVar1;
    puVar7 = puVar7 + 2;
    *puVar7 = uVar10;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  iVar4 = 0;
  iVar6 = 0;
  if (local_78 == '\x03') {
    if (0 < iVar11) {
      do {
        iVar6 = (int)*(float *)(iVar9 + iVar4 + 0x44);
        local_18 = (double)(longlong)iVar6;
        *(int *)(this + iVar4 + 0x7c) = iVar6;
        iVar4 = iVar4 + 4;
        iVar11 = iVar11 + -1;
      } while (iVar11 != 0);
    }
  }
  else {
    if (0 < iVar11) {
      do {
        *(undefined4 *)(this + iVar6 + 0x7c) = 0;
        iVar6 = iVar6 + 4;
        iVar11 = iVar11 + -1;
      } while (iVar11 != 0);
    }
  }
  *(undefined4 *)(iVar9 + 0x60) = *(undefined4 *)(iVar9 + 0x5c);
  *(undefined4 *)(iVar9 + 0x68) = 0;
  *(undefined *)(iVar9 + 0x70) = 0;
  *(undefined *)(iVar9 + 0x71) = 0;
  fVar2 = d_mesg::_4035;
  *(float *)(this + 0x44) = d_mesg::_4035;
  *(float *)(this + 0x50) = fVar2;
  *(undefined4 *)(this + 0x70) = 0;
  this[0x161] = (dMesg_tSequenceProcessor)0x0;
  this[0x15f] = (dMesg_tSequenceProcessor)0x0;
  this[0x160] = (dMesg_tSequenceProcessor)0x0;
  this[0x162] = (dMesg_tSequenceProcessor)0x0;
  this[0x163] = (dMesg_tSequenceProcessor)0x0;
  *(undefined4 *)(this + 0x68) = 0;
  *(undefined4 *)(this + 100) = 0;
  *(undefined4 *)(this + 0x60) = 0;
  *(undefined4 *)(this + 0x5c) = 0;
  if (d_mesg::m_strSizeFlag != '\0') {
    d_mesg::retFlag = d_mesg::retFlag + -1;
  }
  uVar3 = (int)DAT_803e6ba2 * (4 - (*(int *)(iVar9 + 0x54) - d_mesg::retFlag));
  dMesg_screenData_c::shiftSet
            (*(dMesg_screenData_c **)(*(int *)(this + 0x38) + 0x14c),0,
             ((int)uVar3 >> 1) + (uint)((int)uVar3 < 0 && (uVar3 & 1) != 0));
  MSL_C.PPCEABI.bare.H::sprintf
            (acStack152,"\x1bCR[%d]",*(undefined4 *)(this + *(int *)(this + 0x70) * 4 + 0x7c));
  MSL_C.PPCEABI.bare.H::strcat(*(char **)(*(int *)(this + 0x38) + 0x154),acStack152);
  MSL_C.PPCEABI.bare.H::strcat(*(char **)(*(int *)(this + 0x38) + 0x15c),acStack152);
  local_18 = (double)CONCAT44(0x43300000,
                              *(uint *)(this + *(int *)(this + 0x70) * 4 + 0x7c) ^ 0x80000000);
  *(float *)(this + 0x44) = (float)(local_18 - d_mesg::_4147);
  *(undefined4 *)(this + 0x8c) = 1;
  *(undefined4 *)(this + 0x90) = 0;
  local_70[0] = &dMesg_tMeasureProcessor::__vt;
  JMessage::TSequenceProcessor::_TSequenceProcessor((TSequenceProcessor *)local_70);
  return;
}


/* __thiscall dMesg_tMeasureProcessor::~dMesg_tMeasureProcessor(void) */

void __thiscall dMesg_tMeasureProcessor::_dMesg_tMeasureProcessor(dMesg_tMeasureProcessor *this)

{
  short in_r4;
  
  if (this != (dMesg_tMeasureProcessor *)0x0) {
    *(undefined1 **)this = &__vt;
    JMessage::TSequenceProcessor::_TSequenceProcessor((TSequenceProcessor *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dMesg_tSequenceProcessor::do_begin(void const *,
                                                 char const *) */

void __thiscall
dMesg_tSequenceProcessor::do_begin(dMesg_tSequenceProcessor *this,void *param_1,char *param_2)

{
  *(void **)(this + 0x3c) = param_1;
  *(char **)(this + 0x40) = param_2;
  initialize(this,0);
  return;
}


/* __thiscall dMesg_tSequenceProcessor::do_end(void) */

void __thiscall dMesg_tSequenceProcessor::do_end(dMesg_tSequenceProcessor *this)

{
  setCharacter(this);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dMesg_tSequenceProcessor::do_isReady(void) */

undefined4 __thiscall dMesg_tSequenceProcessor::do_isReady(dMesg_tSequenceProcessor *this)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined4 uStack44;
  undefined4 local_28 [3];
  char local_1b;
  
  uVar2 = d_mesg::nowMesgCode;
  uVar7 = 0;
  if (this[0x15f] == (dMesg_tSequenceProcessor)0x0) {
    iVar4 = JMessage::TControl::getResource_groupID
                      (d_mesg::dMesg_gpControl,(ushort)(d_mesg::nowMesgCode >> 0x10));
    if (iVar4 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(iVar4 + 0xc);
      if ((uVar2 & 0xffff) < (uint)*(ushort *)(iVar4 + 8)) {
        iVar4 = iVar4 + (uVar2 & 0xffff) * (uint)*(ushort *)(iVar4 + 10) + 0x10;
      }
      else {
        iVar4 = 0;
      }
    }
    puVar6 = &uStack44;
    puVar5 = (undefined4 *)(iVar4 + -4);
    iVar4 = 3;
    do {
      puVar1 = puVar5 + 1;
      puVar5 = puVar5 + 2;
      uVar3 = *puVar5;
      puVar6[1] = *puVar1;
      puVar6 = puVar6 + 2;
      *puVar6 = uVar3;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    if (local_1b == '\x01') {
      this[0x161] = (dMesg_tSequenceProcessor)0x1;
      if (this[0x160] != (dMesg_tSequenceProcessor)0x0) {
        this[0x161] = (dMesg_tSequenceProcessor)0x0;
      }
    }
    else {
      if (local_1b == '\x02') {
        this[0x161] = (dMesg_tSequenceProcessor)0x0;
      }
    }
    if (((((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) != 0) ||
         ((char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 < '\0')) && (local_1b != '\x02'))
       && (this[0x160] == (dMesg_tSequenceProcessor)0x0)) {
      this[0x161] = (dMesg_tSequenceProcessor)0x1;
    }
    if ((*(int *)(this + 0x90) < 1) || (this[0x161] != (dMesg_tSequenceProcessor)0x0)) {
      uVar7 = 1;
      this[0x160] = (dMesg_tSequenceProcessor)0x0;
    }
    else {
      *(int *)(this + 0x90) = *(int *)(this + 0x90) + -1;
    }
    if (d_mesg::zenkaku != '\0') {
      uVar7 = 1;
    }
  }
  return uVar7;
}


/* __thiscall dMesg_tSequenceProcessor::do_jump_isReady(void) */

undefined4 __thiscall dMesg_tSequenceProcessor::do_jump_isReady(dMesg_tSequenceProcessor *this)

{
  if (((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) == 0) &&
     (-1 < (char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3)) {
    return 0;
  }
  return 1;
}


/* __thiscall dMesg_tSequenceProcessor::do_jump(void const *,
                                                char const *) */

void __thiscall
dMesg_tSequenceProcessor::do_jump(dMesg_tSequenceProcessor *this,void *param_1,char *param_2)

{
  *(undefined4 *)(this + 0x90) = 0;
  return;
}


/* __thiscall dMesg_tSequenceProcessor::do_branch_query(unsigned short) */

void __thiscall
dMesg_tSequenceProcessor::do_branch_query(dMesg_tSequenceProcessor *this,ushort param_1)

{
  return;
}


/* __thiscall dMesg_tSequenceProcessor::do_branch_queryResult(void) */

undefined4 __thiscall
dMesg_tSequenceProcessor::do_branch_queryResult(dMesg_tSequenceProcessor *this)

{
  return 0xff;
}


/* __thiscall dMesg_tSequenceProcessor::do_branch(void const *,
                                                  char const *) */

void __thiscall
dMesg_tSequenceProcessor::do_branch(dMesg_tSequenceProcessor *this,void *param_1,char *param_2)

{
  *(undefined4 *)(this + 0x90) = 0;
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x801e0dc8) */
/* __thiscall dMesg_tSequenceProcessor::do_character(int) */

void __thiscall dMesg_tSequenceProcessor::do_character(dMesg_tSequenceProcessor *this,int param_1)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  double dVar8;
  undefined8 in_f31;
  double dVar9;
  undefined uStack88;
  byte local_57;
  char acStack84 [16];
  char local_44 [20];
  undefined4 local_30;
  uint uStack44;
  double local_28;
  undefined auStack8 [8];
  
  uVar7 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  iVar5 = *(int *)(this + 4);
  iVar4 = 0;
  setCharacter(this);
  if (d_mesg::headerFlag == '\0') {
    this[0x94] = SUB41(param_1,0);
    this[0x95] = (dMesg_tSequenceProcessor)0x0;
    *(int *)(iVar5 + 0x68) = param_1;
    if (param_1 == 10) {
      iVar4 = 1;
    }
    else {
      if (param_1 == 0) {
        iVar4 = 2;
      }
    }
  }
  else {
    if ((((param_1 & 0xf0U) == 0x80) || ((param_1 & 0xf0U) == 0x90)) || (d_mesg::zenkaku != '\0')) {
      if (d_mesg::zenkaku == '\0') {
        d_mesg::zenkakuCode = (ushort)(param_1 << 8);
        d_mesg::zenkaku = '\x01';
        goto LAB_801e0dc8;
      }
      uVar2 = (uint)d_mesg::zenkakuCode | param_1 & 0xffffU;
      d_mesg::zenkakuCode = (ushort)uVar2;
      iVar3 = 0;
      d_mesg::zenkaku = '\0';
      iVar6 = 0x61;
      do {
        if (uVar2 == *(ushort *)((int)&f_op_msg_mng::zfont + iVar3)) {
          param_1 = ZEXT24(*(ushort *)((int)&DAT_8037238a + iVar3));
          break;
        }
        iVar3 = iVar3 + 4;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      *(int *)(iVar5 + 0x68) = param_1;
      this[0x94] = SUB41((uint)param_1 >> 8,0);
      this[0x95] = SUB41(param_1,0);
    }
    else {
      this[0x94] = SUB41(param_1,0);
      this[0x95] = (dMesg_tSequenceProcessor)0x0;
      *(int *)(iVar5 + 0x68) = param_1;
      if (param_1 == 10) {
        iVar4 = 1;
      }
      else {
        if (param_1 == 0) {
          iVar4 = 2;
        }
      }
      d_mesg::zenkaku = '\0';
    }
  }
  uVar2 = *(uint *)(iVar5 + 0x60);
  uStack44 = (**(code **)(**(int **)(iVar5 + 0x3c) + 0x30))();
  uStack44 = uStack44 ^ 0x80000000;
  local_30 = 0x43300000;
  local_28 = (double)CONCAT44(0x43300000,uVar2 ^ 0x80000000);
  dVar9 = (double)((float)(local_28 - d_mesg::_4147) /
                  (float)((double)CONCAT44(0x43300000,uStack44) - d_mesg::_4147));
  (**(code **)(**(int **)(iVar5 + 0x3c) + 0x2c))
            (*(int **)(iVar5 + 0x3c),*(undefined4 *)(iVar5 + 0x68),&uStack88);
  if (*(char *)(iVar5 + 0x70) == '\0') {
    local_28 = (double)CONCAT44(0x43300000,local_57 ^ 0x80000000);
    *(float *)(this + 0x44) =
         *(float *)(this + 0x44) + (float)((double)(float)(local_28 - d_mesg::_4147) * dVar9);
    *(undefined *)(iVar5 + 0x70) = 1;
  }
  else {
    local_28 = (double)CONCAT44(0x43300000,local_57 ^ 0x80000000);
    uStack44 = *(uint *)(iVar5 + 100) ^ 0x80000000;
    local_30 = 0x43300000;
    *(float *)(this + 0x44) =
         *(float *)(this + 0x44) +
         (float)((double)(float)(local_28 - d_mesg::_4147) * dVar9) +
         (float)((double)CONCAT44(0x43300000,uStack44) - d_mesg::_4147);
  }
  if ((0 < *(int *)(this + 0x74)) &&
     (*(int *)(this + 0x74) = *(int *)(this + 0x74) + -1, *(int *)(this + 0x74) == 0)) {
    dVar9 = (double)((*(float *)(this + 0x48) +
                     (*(float *)(this + 0x44) - *(float *)(this + 0x48)) * d_mesg::_4324) -
                    *(float *)(this + 0x54) * d_mesg::_4324);
    local_44[0] = '\0';
    if (this[0x163] != (dMesg_tSequenceProcessor)0x0) {
      *(undefined *)(*(int *)(*(int *)(this + 0x38) + 0x158) + *(int *)(this + 0x60)) = 0;
      *(undefined *)(*(int *)(*(int *)(this + 0x38) + 0x160) + *(int *)(this + 0x68)) = 0;
      MSL_C.PPCEABI.bare.H::strcat(*(char **)(*(int *)(this + 0x38) + 0x158),(char *)(this + 0xfb));
      MSL_C.PPCEABI.bare.H::strcat(*(char **)(*(int *)(this + 0x38) + 0x160),(char *)(this + 0xfb));
      this[0x163] = (dMesg_tSequenceProcessor)0x0;
    }
    dVar8 = (double)*(float *)(this + 0x50);
    if (dVar9 <= dVar8) {
      if ((double)d_mesg::_4035 == dVar8) {
        dVar9 = (double)(float)(dVar8 - dVar9);
        local_28 = (double)(longlong)(int)((double)d_mesg::_4324 + dVar9);
        MSL_C.PPCEABI.bare.H::sprintf(local_44,"\x1bCL[%d]",(int)((double)d_mesg::_4324 + dVar9));
        *(float *)(this + 0x50) = (float)((double)*(float *)(this + 0x50) - dVar9);
      }
    }
    else {
      dVar9 = (double)(float)(dVar9 - dVar8);
      local_28 = (double)(longlong)(int)((double)d_mesg::_4324 + dVar9);
      MSL_C.PPCEABI.bare.H::sprintf(local_44,"\x1bCR[%d]",(int)((double)d_mesg::_4324 + dVar9));
      *(float *)(this + 0x50) = (float)((double)*(float *)(this + 0x50) + dVar9);
    }
    *(float *)(this + 0x50) = *(float *)(this + 0x50) + *(float *)(this + 0x54);
    MSL_C.PPCEABI.bare.H::strcat(*(char **)(*(int *)(this + 0x38) + 0x158),local_44);
    MSL_C.PPCEABI.bare.H::strcat(*(char **)(*(int *)(this + 0x38) + 0x160),local_44);
    MSL_C.PPCEABI.bare.H::strcat(*(char **)(*(int *)(this + 0x38) + 0x158),(char *)(this + 0x97));
    MSL_C.PPCEABI.bare.H::strcat(*(char **)(*(int *)(this + 0x38) + 0x160),(char *)(this + 0x97));
    MSL_C.PPCEABI.bare.H::strcpy((char *)(this + 0xfb),(char *)(this + 0x97));
  }
  if (iVar4 == 1) {
    MSL_C.PPCEABI.bare.H::strcat(*(char **)(*(int *)(this + 0x38) + 0x154),(char *)(this + 0x94));
    MSL_C.PPCEABI.bare.H::strcat(*(char **)(*(int *)(this + 0x38) + 0x158),(char *)(this + 0x94));
    MSL_C.PPCEABI.bare.H::strcat(*(char **)(*(int *)(this + 0x38) + 0x15c),(char *)(this + 0x94));
    MSL_C.PPCEABI.bare.H::strcat(*(char **)(*(int *)(this + 0x38) + 0x160),(char *)(this + 0x94));
    fVar1 = d_mesg::_4035;
    *(float *)(this + 0x44) = d_mesg::_4035;
    *(float *)(this + 0x50) = fVar1;
    *(int *)(this + 0x70) = *(int *)(this + 0x70) + 1;
    if (*(int *)(this + 0x70) == *(int *)(iVar5 + 0x54)) {
      this[0x15f] = (dMesg_tSequenceProcessor)0x1;
      goto LAB_801e0dc8;
    }
    *(undefined *)(iVar5 + 0x70) = 0;
    MSL_C.PPCEABI.bare.H::sprintf
              (acStack84,"\x1bCR[%d]",*(undefined4 *)(this + *(int *)(this + 0x70) * 4 + 0x7c));
    MSL_C.PPCEABI.bare.H::strcat(*(char **)(*(int *)(this + 0x38) + 0x154),acStack84);
    MSL_C.PPCEABI.bare.H::strcat(*(char **)(*(int *)(this + 0x38) + 0x15c),acStack84);
    local_28 = (double)CONCAT44(0x43300000,
                                *(uint *)(this + *(int *)(this + 0x70) * 4 + 0x7c) ^ 0x80000000);
    *(float *)(this + 0x44) = (float)(local_28 - d_mesg::_4147);
  }
  else {
    MSL_C.PPCEABI.bare.H::strcat(*(char **)(*(int *)(this + 0x38) + 0x154),(char *)(this + 0x94));
    MSL_C.PPCEABI.bare.H::strcat(*(char **)(*(int *)(this + 0x38) + 0x15c),(char *)(this + 0x94));
  }
  iVar5 = *(int *)(iVar5 + 0x68);
  if (((iVar5 == 0x8140) || (iVar5 == 0x8141)) || ((iVar5 == 0x20 || (iVar4 == 1)))) {
    if (*(int *)(this + 0x8c) != 0) {
      *(undefined4 *)(this + 0x90) = 1;
    }
  }
  else {
    *(undefined4 *)(this + 0x90) = *(undefined4 *)(this + 0x8c);
  }
LAB_801e0dc8:
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* WARNING: Removing unreachable block (ram,0x801e15f4) */
/* WARNING: Removing unreachable block (ram,0x801e15ec) */
/* WARNING: Removing unreachable block (ram,0x801e15fc) */
/* __thiscall dMesg_tSequenceProcessor::do_tag(unsigned long,
                                               void const *,
                                               unsigned long) */

undefined4 __thiscall
dMesg_tSequenceProcessor::do_tag
          (dMesg_tSequenceProcessor *this,ulong param_1,void *param_2,ulong param_3)

{
  undefined4 *puVar1;
  byte bVar2;
  undefined4 uVar3;
  size_t sVar4;
  ushort uVar6;
  uint uVar5;
  char cVar7;
  undefined4 *puVar8;
  uint uVar9;
  undefined4 *puVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  byte *pbVar14;
  undefined4 uVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  undefined4 uVar19;
  undefined8 in_f29;
  double dVar20;
  undefined8 in_f30;
  double dVar21;
  undefined8 in_f31;
  double dVar22;
  undefined uStack216;
  byte local_d7;
  undefined uStack212;
  byte local_d3;
  byte local_d0;
  byte local_cf;
  undefined local_ce;
  char local_cc;
  char local_cb;
  undefined local_ca;
  char acStack200 [16];
  byte local_b8 [16];
  undefined4 uStack168;
  undefined4 local_a4;
  short local_a0;
  char acStack141 [21];
  undefined4 local_78;
  uint uStack116;
  double local_70;
  undefined4 local_68;
  uint uStack100;
  double local_60;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar19 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  iVar18 = *(int *)(this + 4);
  uVar9 = param_1 & 0xff0000;
  uVar15 = 0;
  if (this[0x162] != (dMesg_tSequenceProcessor)0x0) {
    *(undefined *)(*(int *)(*(int *)(this + 0x38) + 0x154) + *(int *)(this + 0x5c)) = 0;
    *(undefined *)(*(int *)(*(int *)(this + 0x38) + 0x15c) + *(int *)(this + 100)) = 0;
    this[0x162] = (dMesg_tSequenceProcessor)0x0;
    MSL_C.PPCEABI.bare.H::strcat(*(char **)(*(int *)(this + 0x38) + 0x154),(char *)(this + 0x94));
    MSL_C.PPCEABI.bare.H::strcat(*(char **)(*(int *)(this + 0x38) + 0x15c),(char *)(this + 0x94));
    this[0x96] = (dMesg_tSequenceProcessor)0x0;
    this[0x95] = (dMesg_tSequenceProcessor)0x0;
    this[0x94] = (dMesg_tSequenceProcessor)0x0;
  }
  uVar5 = d_mesg::nowMesgCode;
  if (uVar9 == 0x20000) {
    d_com_inf_game::g_dComIfG_gameInfo.mMesgCameraTagInfo = param_1 & 0xffff;
    uVar15 = 1;
  }
  else {
    if (uVar9 < 0x20000) {
      if (uVar9 == 0x10000) {
        cVar7 = d_com_inf_game::dComIfGp_getReverb((int)(char)dStage_roomControl_c::mStayNo);
        uVar6 = (ushort)(param_1 & 0xffff);
        if ((param_1 & 0xffff) == 8) {
          JAIZelBasic::messageSePlay(JAIZelBasic::zel_basic,uVar6,(Vec *)0x0,cVar7);
        }
        else {
          JAIZelBasic::messageSePlay(JAIZelBasic::zel_basic,uVar6,(Vec *)0x0,cVar7);
        }
        uVar15 = 1;
      }
      else {
        if ((uVar9 < 0x10000) && (uVar9 == 0)) {
          switch(param_1) {
          case 0:
            uVar15 = 1;
            iVar16 = 0;
            iVar17 = JMessage::TControl::getResource_groupID
                               (d_mesg::dMesg_gpControl,(ushort)(d_mesg::nowMesgCode >> 0x10));
            if (iVar17 == 0) {
              iVar17 = 0;
            }
            else {
              iVar17 = *(int *)(iVar17 + 0xc);
              if ((uVar5 & 0xffff) < (uint)*(ushort *)(iVar17 + 8)) {
                iVar17 = iVar17 + (uVar5 & 0xffff) * (uint)*(ushort *)(iVar17 + 10) + 0x10;
              }
              else {
                iVar17 = 0;
              }
            }
            puVar10 = &uStack168;
            puVar8 = (undefined4 *)(iVar17 + -4);
            iVar17 = 3;
            do {
              puVar1 = puVar8 + 1;
              puVar8 = puVar8 + 2;
              uVar3 = *puVar8;
              puVar10[1] = *puVar1;
              puVar10 = puVar10 + 2;
              *puVar10 = uVar3;
              iVar17 = iVar17 + -1;
            } while (iVar17 != 0);
            MSL_C.PPCEABI.bare.H::strcpy
                      (acStack141 + 1,
                       &d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mInfo.mPlayerName);
            if ((d_com_inf_game::g_dComIfG_gameInfo.mGameLanguage == 1) &&
               ((((local_a0 == 0x33b || (local_a0 == 0xc8b)) || (local_a0 == 0x1d21)) ||
                (((local_a0 == 0x31d7 || (local_a0 == 0x37dd)) || (local_a0 == 0x37de)))))) {
              sVar4 = MSL_C.PPCEABI.bare.H::strlen(acStack141 + 1);
              cVar7 = acStack141[sVar4];
              if (((cVar7 == 's') || (cVar7 == 'S')) ||
                 ((cVar7 == 'z' || (((cVar7 == 'Z' || (cVar7 == 'x')) || (cVar7 == 'X')))))) {
                MSL_C.PPCEABI.bare.H::strcat(acStack141 + 1,"\'");
              }
              else {
                MSL_C.PPCEABI.bare.H::strcat(acStack141 + 1,"s");
              }
            }
            dVar21 = (double)d_mesg::_4035;
            pbVar14 = (byte *)(acStack141 + 1);
            dVar22 = d_mesg::_4147;
            while( true ) {
              bVar2 = *pbVar14;
              uVar9 = (uint)bVar2;
              if (bVar2 == 0) break;
              if (((int)uVar9 >> 4 == 8) || ((int)uVar9 >> 4 == 9)) {
                local_cc = (acStack141 + 1)[iVar16];
                local_cb = (acStack141 + 1)[iVar16 + 1];
                uVar9 = (uint)CONCAT11(bVar2,local_cb);
                local_ca = 0;
                iVar16 = iVar16 + 2;
                pbVar14 = pbVar14 + 2;
              }
              else {
                local_cc = acStack141[iVar16 + 1];
                local_cb = '\0';
                iVar16 = iVar16 + 1;
                pbVar14 = pbVar14 + 1;
              }
              uVar5 = *(uint *)(iVar18 + 0x60);
              uStack116 = (**(code **)(**(int **)(iVar18 + 0x3c) + 0x30))();
              uStack116 = uStack116 ^ 0x80000000;
              local_78 = 0x43300000;
              local_70 = (double)CONCAT44(0x43300000,uVar5 ^ 0x80000000);
              dVar20 = (double)((float)(local_70 - dVar22) /
                               (float)((double)CONCAT44(0x43300000,uStack116) - dVar22));
              (**(code **)(**(int **)(iVar18 + 0x3c) + 0x2c))
                        (*(int **)(iVar18 + 0x3c),uVar9,&uStack212);
              if (dVar21 == (double)*(float *)(this + 0x44)) {
                local_70 = (double)CONCAT44(0x43300000,local_d3 ^ 0x80000000);
                *(float *)(this + 0x44) =
                     (float)((double)(float)(local_70 - d_mesg::_4147) * dVar20);
              }
              else {
                local_70 = (double)CONCAT44(0x43300000,local_d3 ^ 0x80000000);
                uStack116 = *(uint *)(iVar18 + 100) ^ 0x80000000;
                local_78 = 0x43300000;
                *(float *)(this + 0x44) =
                     (float)((double)*(float *)(this + 0x44) +
                            (double)((float)((double)(float)(local_70 - d_mesg::_4147) * dVar20) +
                                    (float)((double)CONCAT44(0x43300000,uStack116) - d_mesg::_4147))
                            );
              }
              MSL_C.PPCEABI.bare.H::strcat(*(char **)(*(int *)(this + 0x38) + 0x154),&local_cc);
              MSL_C.PPCEABI.bare.H::strcat(*(char **)(*(int *)(this + 0x38) + 0x15c),&local_cc);
            }
            break;
          case 1:
            *(undefined4 *)(this + 0x8c) = 0;
            uVar15 = 1;
            break;
          case 2:
            *(undefined4 *)(this + 0x8c) = 1;
            uVar15 = 1;
            break;
          case 3:
            uVar15 = 1;
            break;
          case 4:
            uVar15 = 1;
                    /* WARNING: Load size is inaccurate */
            *(uint *)(this + 0x90) = (uint)*param_2;
            this[0x160] = (dMesg_tSequenceProcessor)0x1;
            this[0x15f] = (dMesg_tSequenceProcessor)0x2;
            break;
          case 5:
          case 6:
            uVar15 = 1;
            break;
          case 7:
            uVar15 = 1;
                    /* WARNING: Load size is inaccurate */
            *(uint *)(this + 0x90) = (uint)*param_2;
            this[0x160] = (dMesg_tSequenceProcessor)0x1;
            break;
          case 8:
          case 9:
            *(undefined4 *)(this + 0x8c) = 0;
            uVar15 = 1;
            break;
          case 10:
          case 0xb:
          case 0xc:
          case 0xd:
          case 0xe:
          case 0xf:
          case 0x10:
          case 0x11:
          case 0x12:
          case 0x13:
          case 0x14:
          case 0x15:
          case 0x16:
          case 0x17:
          case 0x18:
          case 0x19:
          case 0x1a:
          case 0x1b:
          case 0x1c:
          case 0x1d:
            iVar17 = (int)(d_mesg::_4324 +
                          *(float *)(this + 0x44) +
                          *(float *)(*(int *)(*(int *)(this + 0x38) + 0x14c) + 0x8c));
            local_70 = (double)(longlong)iVar17;
            uStack116 = *(int *)(this + 0x70) * (int)DAT_803e6ba2 ^ 0x80000000;
            local_78 = 0x43300000;
            uVar9 = (int)DAT_803e6ba2 * (4 - *(int *)(iVar18 + 0x54));
            uStack100 = ((int)uVar9 >> 1) + (uint)((int)uVar9 < 0 && (uVar9 & 1) != 0) ^ 0x80000000;
            local_68 = 0x43300000;
            iVar16 = (int)((float)((double)CONCAT44(0x43300000,uStack116) - d_mesg::_4147) +
                          *(float *)(*(int *)(*(int *)(this + 0x38) + 0x14c) + 0x90) +
                          (float)((double)CONCAT44(0x43300000,uStack100) - d_mesg::_4147));
            local_60 = (double)(longlong)iVar16;
            setCharacter(this);
            iVar11 = 0;
            iVar13 = 0;
            do {
              cVar7 = dMesg_outFont_c::_set
                                (*(dMesg_outFont_c **)(*(int *)(this + 0x38) + iVar13 + 0x104),
                                 (short)iVar17,(short)iVar16,(short)*(undefined4 *)(iVar18 + 0x60),
                                 *(ulong *)(this + 0x6c),(byte)param_1 - 10);
              if (cVar7 != '\0') {
                dMesg_outFont_c::_setAlpha
                          (*(dMesg_outFont_c **)(*(int *)(this + 0x38) + iVar13 + 0x104),0xff);
                break;
              }
              iVar11 = iVar11 + 1;
              iVar13 = iVar13 + 4;
            } while (iVar11 < 0x12);
            local_60 = (double)CONCAT44(0x43300000,
                                        *(int *)(iVar18 + 0x60) + *(int *)(iVar18 + 100) ^
                                        0x80000000);
            *(float *)(this + 0x44) = *(float *)(this + 0x44) + (float)(local_60 - d_mesg::_4147);
            MSL_C.PPCEABI.bare.H::sprintf(acStack200,"\x1bCR[%d]",*(undefined4 *)(iVar18 + 0x60));
            MSL_C.PPCEABI.bare.H::strcat(*(char **)(*(int *)(this + 0x38) + 0x154),acStack200);
            MSL_C.PPCEABI.bare.H::strcat(*(char **)(*(int *)(this + 0x38) + 0x15c),acStack200);
            *(undefined4 *)(this + 0x90) = *(undefined4 *)(this + 0x8c);
            uVar15 = 1;
            break;
          case 0x29:
            uVar15 = 1;
            iVar17 = 0;
            uVar6 = dSv_event_c::getEventReg
                              (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0xba0f);
            f_op_msg_mng::fopMsgM_passwordGet(local_b8,(uVar6 & 0xff) + 0x1b37);
            dVar21 = (double)d_mesg::_4035;
            pbVar14 = local_b8;
            dVar22 = d_mesg::_4147;
            while( true ) {
              bVar2 = *pbVar14;
              uVar9 = (uint)bVar2;
              if (bVar2 == 0) break;
              if (((int)uVar9 >> 4 == 8) || ((int)uVar9 >> 4 == 9)) {
                local_d0 = local_b8[iVar17];
                local_cf = local_b8[iVar17 + 1];
                uVar9 = (uint)CONCAT11(bVar2,local_cf);
                local_ce = 0;
                iVar17 = iVar17 + 2;
                pbVar14 = pbVar14 + 2;
              }
              else {
                local_d0 = local_b8[iVar17];
                local_cf = 0;
                iVar17 = iVar17 + 1;
                pbVar14 = pbVar14 + 1;
              }
              uVar12 = *(uint *)(iVar18 + 0x60);
              uVar5 = (**(code **)(**(int **)(iVar18 + 0x3c) + 0x30))();
              local_60 = (double)CONCAT44(0x43300000,uVar5 ^ 0x80000000);
              uStack100 = uVar12 ^ 0x80000000;
              local_68 = 0x43300000;
              dVar20 = (double)((float)((double)CONCAT44(0x43300000,uStack100) - dVar22) /
                               (float)(local_60 - dVar22));
              (**(code **)(**(int **)(iVar18 + 0x3c) + 0x2c))
                        (*(int **)(iVar18 + 0x3c),uVar9,&uStack216);
              if (dVar21 == (double)*(float *)(this + 0x44)) {
                local_60 = (double)CONCAT44(0x43300000,local_d7 ^ 0x80000000);
                *(float *)(this + 0x44) =
                     (float)((double)(float)(local_60 - d_mesg::_4147) * dVar20);
              }
              else {
                local_60 = (double)CONCAT44(0x43300000,local_d7 ^ 0x80000000);
                uStack100 = *(uint *)(iVar18 + 100) ^ 0x80000000;
                local_68 = 0x43300000;
                *(float *)(this + 0x44) =
                     (float)((double)*(float *)(this + 0x44) +
                            (double)((float)((double)(float)(local_60 - d_mesg::_4147) * dVar20) +
                                    (float)((double)CONCAT44(0x43300000,uStack100) - d_mesg::_4147))
                            );
              }
              MSL_C.PPCEABI.bare.H::strcat
                        (*(char **)(*(int *)(this + 0x38) + 0x154),(char *)&local_d0);
              MSL_C.PPCEABI.bare.H::strcat
                        (*(char **)(*(int *)(this + 0x38) + 0x15c),(char *)&local_d0);
            }
          }
        }
      }
    }
    else {
      if (uVar9 == 0x30000) {
        uVar15 = 1;
        d_com_inf_game::g_dComIfG_gameInfo.mMesgAnimeTagInfo = (byte)param_1;
      }
    }
  }
  __psq_l0(auStack8,uVar19);
  __psq_l1(auStack8,uVar19);
  __psq_l0(auStack24,uVar19);
  __psq_l1(auStack24,uVar19);
  __psq_l0(auStack40,uVar19);
  __psq_l1(auStack40,uVar19);
  return uVar15;
}


/* __thiscall dMesg_tSequenceProcessor::setCharacter(void) */

void __thiscall dMesg_tSequenceProcessor::setCharacter(dMesg_tSequenceProcessor *this)

{
  if (this[0x162] != (dMesg_tSequenceProcessor)0x0) {
    *(undefined *)(*(int *)(*(int *)(this + 0x38) + 0x154) + *(int *)(this + 0x5c)) = 0;
    *(undefined *)(*(int *)(*(int *)(this + 0x38) + 0x15c) + *(int *)(this + 100)) = 0;
    MSL_C.PPCEABI.bare.H::strcat(*(char **)(*(int *)(this + 0x38) + 0x154),(char *)(this + 0x94));
    MSL_C.PPCEABI.bare.H::strcat(*(char **)(*(int *)(this + 0x38) + 0x15c),(char *)(this + 0x94));
    this[0x162] = (dMesg_tSequenceProcessor)0x0;
  }
  if (this[0x163] != (dMesg_tSequenceProcessor)0x0) {
    *(undefined *)(*(int *)(*(int *)(this + 0x38) + 0x158) + *(int *)(this + 0x60)) = 0;
    *(undefined *)(*(int *)(*(int *)(this + 0x38) + 0x160) + *(int *)(this + 0x68)) = 0;
    MSL_C.PPCEABI.bare.H::strcat(*(char **)(*(int *)(this + 0x38) + 0x158),(char *)(this + 0xfb));
    MSL_C.PPCEABI.bare.H::strcat(*(char **)(*(int *)(this + 0x38) + 0x160),(char *)(this + 0xfb));
    this[0x163] = (dMesg_tSequenceProcessor)0x0;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x801e1838) */
/* __thiscall dMesg_tSequenceProcessor::ruby_character(char *,
                                                       int) */

undefined * __thiscall
dMesg_tSequenceProcessor::ruby_character(dMesg_tSequenceProcessor *this,char *param_1,int param_2)

{
  undefined2 *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  double dVar5;
  undefined8 in_f31;
  double dVar6;
  undefined uStack72;
  byte local_47;
  undefined local_44;
  undefined local_43;
  undefined local_42;
  undefined4 local_40;
  uint uStack60;
  undefined4 local_38;
  uint uStack52;
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  iVar3 = *(int *)(this + 4);
  uStack60 = (**(code **)(**(int **)(iVar3 + 0x40) + 0x30))();
  uStack60 = uStack60 ^ 0x80000000;
  local_40 = 0x43300000;
  uStack52 = (int)DAT_803e6bac ^ 0x80000000;
  local_38 = 0x43300000;
  dVar6 = (double)((float)((double)CONCAT44(0x43300000,uStack52) - d_mesg::_4147) /
                  (float)((double)CONCAT44(0x43300000,uStack60) - d_mesg::_4147));
  puVar1 = (undefined2 *)(param_1 + param_2);
  local_44 = *(undefined *)puVar1;
  local_43 = *(undefined *)((int)puVar1 + 1);
  local_42 = 0;
  piVar2 = *(int **)(iVar3 + 0x40);
  (**(code **)(*piVar2 + 0x2c))(piVar2,*puVar1,&uStack72);
  dVar5 = (double)(float)((double)CONCAT44(0x43300000,local_47 ^ 0x80000000) - d_mesg::_4147);
  if (param_2 == 1) {
    if (d_mesg::_4035 == *(float *)(this + 0x50)) {
      *(float *)(this + 0x54) = (float)(dVar5 * dVar6);
    }
    else {
      *(float *)(this + 0x54) = (float)(dVar5 * dVar6);
    }
  }
  else {
    *(float *)(this + 0x54) =
         *(float *)(this + 0x54) +
         (float)((double)CONCAT44(0x43300000,(int)DAT_803e6ba0 ^ 0x80000000) - d_mesg::_4147) +
         (float)(dVar5 * dVar6);
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return &local_44;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x801e18d4) */
/* __thiscall dMesg_tSequenceProcessor::do_systemTagCode(unsigned short,
                                                         void const *,
                                                         unsigned long) */

undefined4 __thiscall
dMesg_tSequenceProcessor::do_systemTagCode
          (dMesg_tSequenceProcessor *this,ushort param_1,void *param_2,ulong param_3)

{
  int iVar1;
  float fVar2;
  ushort uVar3;
  char *__src;
  int iVar4;
  undefined4 uVar5;
  char acStack88 [16];
  char acStack72 [32];
  undefined4 local_28;
  uint uStack36;
  double local_20;
  
  iVar4 = *(int *)(this + 4);
  if (this[0x162] != (dMesg_tSequenceProcessor)0x0) {
    *(undefined *)(*(int *)(*(int *)(this + 0x38) + 0x154) + *(int *)(this + 0x5c)) = 0;
    *(undefined *)(*(int *)(*(int *)(this + 0x38) + 0x15c) + *(int *)(this + 100)) = 0;
    this[0x162] = (dMesg_tSequenceProcessor)0x0;
  }
  if (param_1 != 3) {
    if (param_1 < 3) {
      if (param_1 != 1) {
        if (param_1 != 0) {
          fVar2 = *(float *)(this + 0x44);
          if (d_mesg::_4035 == fVar2) {
            *(float *)(this + 0x48) = fVar2;
          }
          else {
            local_20 = (double)CONCAT44(0x43300000,*(uint *)(iVar4 + 100) ^ 0x80000000);
            *(float *)(this + 0x48) = fVar2 + (float)(local_20 - d_mesg::_4147);
          }
          *(float *)(this + 0x54) = d_mesg::_4035;
          MSL_C.PPCEABI.bare.H::strcpy((char *)(this + 0x97),"");
                    /* WARNING: Load size is inaccurate */
          *(uint *)(this + 0x74) = (uint)*param_2;
          for (iVar4 = 1; iVar4 < (int)param_3; iVar4 = iVar4 + 2) {
            __src = (char *)ruby_character(this,(char *)param_2,iVar4);
            MSL_C.PPCEABI.bare.H::strcat((char *)(this + 0x97),__src);
          }
          return 1;
        }
        if (param_3 != 1) {
          return 1;
        }
                    /* WARNING: Load size is inaccurate */
        *(undefined4 *)(this + 0x6c) =
             *(undefined4 *)(&d_mesg::colorTable_4548 + (uint)*param_2 * 4);
        MSL_C.PPCEABI.bare.H::sprintf
                  (acStack72,"\x1bCC[%08x]\x1bGM[0]",*(undefined4 *)(this + 0x6c));
        MSL_C.PPCEABI.bare.H::strcat(*(char **)(*(int *)(this + 0x38) + 0x154),acStack72);
        return 1;
      }
    }
    else {
      if (param_1 != 6) {
        return 1;
      }
    }
    if (param_3 == 2) {
                    /* WARNING: Load size is inaccurate */
      uVar3 = *param_2;
      uVar5 = *(undefined4 *)(iVar4 + 0x60);
      uStack36 = (uint)uVar3 * *(int *)(iVar4 + 0x5c) ^ 0x80000000;
      local_28 = 0x43300000;
      iVar1 = (int)(d_mesg::_4324 +
                   (float)((double)CONCAT44(0x43300000,uStack36) - d_mesg::_4147) / d_mesg::_4585);
      local_20 = (double)(longlong)iVar1;
      *(int *)(iVar4 + 0x60) = iVar1;
      if (*(int *)(this + 0x70) == 0) {
        d_mesg::dMesg_fontsizeCenter(*(undefined4 *)(this + 0x38),uVar5,iVar1);
      }
      else {
        if ((100 < uVar3) && (d_mesg::s_strSizeFlag == '\0')) {
          MSL_C.PPCEABI.bare.H::strcat(*(char **)(*(int *)(this + 0x38) + 0x154),"\n");
          MSL_C.PPCEABI.bare.H::strcat(*(char **)(*(int *)(this + 0x38) + 0x158),"\n");
          MSL_C.PPCEABI.bare.H::strcat(*(char **)(*(int *)(this + 0x38) + 0x15c),"\n");
          MSL_C.PPCEABI.bare.H::strcat(*(char **)(*(int *)(this + 0x38) + 0x160),"\n");
          local_20 = (double)(longlong)(int)*(float *)(this + 0x44);
          MSL_C.PPCEABI.bare.H::sprintf(acStack88,"\x1bCR[%d]",(int)*(float *)(this + 0x44));
          MSL_C.PPCEABI.bare.H::strcat(*(char **)(*(int *)(this + 0x38) + 0x154),acStack88);
          MSL_C.PPCEABI.bare.H::strcat(*(char **)(*(int *)(this + 0x38) + 0x15c),acStack88);
          d_mesg::s_strSizeFlag = '\x01';
        }
        d_mesg::dMesg_fontsizeCenter
                  (*(undefined4 *)(this + 0x38),uVar5,iVar1,*(undefined4 *)(iVar4 + 0x5c),
                   (int)DAT_803e6ba2);
      }
    }
  }
  return 1;
}


/* __thiscall dMesg_tMeasureProcessor::dMesg_tMeasureProcessor(JMessage::TControl *,
                                                               int) */

void __thiscall
dMesg_tMeasureProcessor::dMesg_tMeasureProcessor
          (dMesg_tMeasureProcessor *this,TControl *param_1,int param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  JMessage::TSequenceProcessor::TSequenceProcessor((TSequenceProcessor *)this,param_1);
  *(undefined1 **)this = &__vt;
  fVar1 = d_mesg::_4035;
  *(float *)(this + 0x48) = d_mesg::_4035;
  *(int *)(this + 0x4c) = param_2;
  iVar2 = 0;
  *(undefined4 *)(this + 0x50) = 0;
  this[0x54] = (dMesg_tMeasureProcessor)0x0;
  d_mesg::linemax = 4;
  iVar3 = *(int *)(this + 4);
  *(undefined4 *)(iVar3 + 0x60) = *(undefined4 *)(iVar3 + 0x5c);
  *(undefined4 *)(iVar3 + 0x54) = 0;
  *(undefined4 *)(iVar3 + 0x68) = 0;
  *(undefined *)(iVar3 + 0x70) = 0;
  *(undefined *)(iVar3 + 0x71) = 0;
  iVar4 = 4;
  do {
    *(float *)(this + iVar2 + 0x38) = fVar1;
    *(float *)(iVar3 + iVar2 + 0x44) = fVar1;
    iVar2 = iVar2 + 4;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x801e1ea0) */
/* __thiscall dMesg_tMeasureProcessor::do_character(int) */

void __thiscall dMesg_tMeasureProcessor::do_character(dMesg_tMeasureProcessor *this,int param_1)

{
  undefined4 *puVar1;
  bool bVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  undefined8 in_f31;
  double dVar12;
  undefined4 uStack88;
  undefined4 local_54 [3];
  char local_48;
  undefined4 local_38;
  uint uStack52;
  undefined4 local_30;
  uint uStack44;
  undefined auStack8 [8];
  
  uVar3 = d_mesg::nowMesgCode;
  uVar11 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  iVar9 = *(int *)(this + 4);
  iVar8 = *(int *)(this + 0x50) - *(int *)(this + 0x4c);
  bVar2 = false;
  if (param_1 == 10) {
    if ((-1 < iVar8) && (iVar8 < d_mesg::linemax + -1)) {
      d_mesg::retFlag = d_mesg::retFlag + 1;
    }
    *(int *)(this + 0x50) = *(int *)(this + 0x50) + 1;
    *(undefined *)(iVar9 + 0x70) = 0;
  }
  else {
    if (((d_mesg::retFlag != 0) && (-1 < iVar8)) && (iVar8 < d_mesg::linemax)) {
      d_mesg::retFlag = 0;
    }
    bVar2 = true;
    iVar5 = JMessage::TControl::getResource_groupID
                      (d_mesg::dMesg_gpControl,(ushort)(d_mesg::nowMesgCode >> 0x10));
    if (iVar5 == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = *(int *)(iVar5 + 0xc);
      if ((uVar3 & 0xffff) < (uint)*(ushort *)(iVar5 + 8)) {
        iVar5 = iVar5 + (uVar3 & 0xffff) * (uint)*(ushort *)(iVar5 + 10) + 0x10;
      }
      else {
        iVar5 = 0;
      }
    }
    puVar7 = &uStack88;
    puVar6 = (undefined4 *)(iVar5 + -4);
    iVar5 = 3;
    do {
      puVar1 = puVar6 + 1;
      puVar6 = puVar6 + 2;
      uVar4 = *puVar6;
      puVar7[1] = *puVar1;
      puVar7 = puVar7 + 2;
      *puVar7 = uVar4;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    if ((d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mInfo.mNumGamesCompleted == 0) &&
       (local_48 == '\f')) {
      iVar5 = 0;
      iVar10 = 0x61;
      do {
        if ((param_1 & 0xffffU) == (uint)*(ushort *)((int)&f_op_msg_mng::zfont + iVar5)) {
          param_1 = ZEXT24(*(ushort *)((int)&DAT_8037238a + iVar5));
          break;
        }
        iVar5 = iVar5 + 4;
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
    }
    *(int *)(iVar9 + 0x68) = param_1;
  }
  if (((bVar2) && (-1 < iVar8)) && (iVar8 <= d_mesg::linemax)) {
    uStack44 = *(uint *)(iVar9 + 0x60);
    uStack52 = (**(code **)(**(int **)(iVar9 + 0x3c) + 0x30))();
    uStack52 = uStack52 ^ 0x80000000;
    local_38 = 0x43300000;
    uStack44 = uStack44 ^ 0x80000000;
    local_30 = 0x43300000;
    dVar12 = (double)((float)((double)CONCAT44(0x43300000,uStack44) - d_mesg::_4147) /
                     (float)((double)CONCAT44(0x43300000,uStack52) - d_mesg::_4147));
    (**(code **)(**(int **)(iVar9 + 0x3c) + 0x2c))
              (*(int **)(iVar9 + 0x3c),*(undefined4 *)(iVar9 + 0x68),&uStack88);
    if (*(char *)(iVar9 + 0x70) == '\0') {
      *(float *)(this + iVar8 * 4 + 0x38) =
           *(float *)(this + iVar8 * 4 + 0x38) +
           (float)((double)(float)((double)CONCAT44(0x43300000,uStack88._1_1_ ^ 0x80000000) -
                                  d_mesg::_4147) * dVar12);
      *(undefined *)(iVar9 + 0x70) = 1;
    }
    else {
      *(float *)(this + iVar8 * 4 + 0x38) =
           *(float *)(this + iVar8 * 4 + 0x38) +
           (float)((double)(float)((double)CONCAT44(0x43300000,uStack88._1_1_ ^ 0x80000000) -
                                  d_mesg::_4147) * dVar12) +
           (float)((double)CONCAT44(0x43300000,*(uint *)(iVar9 + 100) ^ 0x80000000) - d_mesg::_4147)
      ;
    }
  }
  __psq_l0(auStack8,uVar11);
  __psq_l1(auStack8,uVar11);
  return;
}


/* __thiscall dMesg_tMeasureProcessor::do_end(void) */

void __thiscall dMesg_tMeasureProcessor::do_end(dMesg_tMeasureProcessor *this)

{
  float fVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  iVar3 = *(int *)(this + 4);
  iVar2 = (*(int *)(this + 0x50) - *(int *)(this + 0x4c)) + 1;
  if (d_mesg::linemax < iVar2) {
    iVar2 = (int)d_mesg::linemax;
  }
  *(int *)(iVar3 + 0x54) = iVar2;
  *(int *)(iVar3 + 0x58) = *(int *)(this + 0x4c) + iVar2;
  uVar4 = 0;
  iVar2 = 0;
  iVar5 = 4;
  do {
    if ((this[0x54] == (dMesg_tMeasureProcessor)0x2) && ((uVar4 == 1 || (uVar4 == 2)))) {
      fVar1 = *(float *)(this + 0x48);
    }
    else {
      if ((this[0x54] == (dMesg_tMeasureProcessor)0x3) && ((uVar4 < 2 || (uVar4 == 2)))) {
        fVar1 = *(float *)(this + 0x48);
      }
      else {
        fVar1 = ((float)((double)CONCAT44(0x43300000,*(uint *)(iVar3 + 0x6c) ^ 0x80000000) -
                        d_mesg::_4147) - *(float *)(this + iVar2 + 0x38)) * d_mesg::_4324;
      }
    }
    *(float *)(iVar3 + iVar2 + 0x44) = fVar1;
    uVar4 = uVar4 + 1;
    iVar2 = iVar2 + 4;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  return;
}


/* WARNING: Inlined function: FUN_80328f24 */
/* WARNING: Inlined function: FUN_80328f70 */
/* WARNING: Removing unreachable block (ram,0x801e2794) */
/* WARNING: Removing unreachable block (ram,0x801e278c) */
/* WARNING: Removing unreachable block (ram,0x801e279c) */
/* __thiscall dMesg_tMeasureProcessor::do_tag(unsigned long,
                                              void const *,
                                              unsigned long) */

undefined4 __thiscall
dMesg_tMeasureProcessor::do_tag
          (dMesg_tMeasureProcessor *this,ulong param_1,void *param_2,ulong param_3)

{
  undefined4 *puVar1;
  char cVar2;
  byte bVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  size_t sVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  ushort uVar10;
  uint uVar11;
  byte *pbVar12;
  int iVar13;
  undefined4 uVar14;
  int iVar15;
  int iVar16;
  undefined4 uVar17;
  undefined8 in_f29;
  double dVar18;
  undefined8 in_f30;
  double dVar19;
  undefined8 in_f31;
  double dVar20;
  undefined uStack184;
  byte local_b7;
  undefined uStack180;
  byte local_b3;
  undefined uStack176;
  byte local_af;
  undefined uStack172;
  byte local_ab;
  byte local_a8 [16];
  undefined4 uStack152;
  undefined4 local_94;
  short local_90;
  char acStack125 [21];
  undefined4 local_68;
  uint uStack100;
  undefined4 local_60;
  uint uStack92;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar4 = d_mesg::nowMesgCode;
  uVar17 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  iVar16 = *(int *)(this + 4);
  iVar15 = *(int *)(this + 0x50) - *(int *)(this + 0x4c);
  uVar14 = 0;
  uVar11 = param_1 & 0xff0000;
  if (uVar11 == 0x20000) {
    uVar14 = 1;
  }
  else {
    if (uVar11 < 0x20000) {
      if (uVar11 == 0x10000) {
        uVar14 = 1;
      }
      else {
        if ((uVar11 < 0x10000) && (uVar11 == 0)) {
          if (param_1 == 9) {
            this[0x54] = (dMesg_tMeasureProcessor)0x3;
            iVar15 = 0;
            dVar19 = (double)d_mesg::_4035;
            dVar20 = d_mesg::_4147;
            do {
              uVar11 = *(uint *)(iVar16 + 0x60);
              uStack92 = (**(code **)(**(int **)(iVar16 + 0x3c) + 0x30))();
              uStack92 = uStack92 ^ 0x80000000;
              local_60 = 0x43300000;
              uStack100 = uVar11 ^ 0x80000000;
              local_68 = 0x43300000;
              dVar18 = (double)((float)((double)CONCAT44(0x43300000,uStack100) - dVar20) /
                               (float)((double)CONCAT44(0x43300000,uStack92) - dVar20));
              (**(code **)(**(int **)(iVar16 + 0x3c) + 0x2c))
                        (*(int **)(iVar16 + 0x3c),0x48,&uStack180);
              uStack92 = (uint)local_b3;
              if (dVar19 == (double)*(float *)(this + 0x48)) {
                *(float *)(this + 0x48) =
                     (float)((double)(float)((double)CONCAT44(0x43300000,uStack92 ^ 0x80000000) -
                                            d_mesg::_4147) * dVar18);
              }
              else {
                uStack100 = *(uint *)(iVar16 + 100) ^ 0x80000000;
                local_68 = 0x43300000;
                *(float *)(this + 0x48) =
                     (float)((double)*(float *)(this + 0x48) +
                            (double)((float)((double)(float)((double)CONCAT44(0x43300000,
                                                                              uStack92 ^ 0x80000000)
                                                            - d_mesg::_4147) * dVar18) +
                                    (float)((double)CONCAT44(0x43300000,uStack100) - d_mesg::_4147))
                            );
              }
              uStack92 = uStack92 ^ 0x80000000;
              local_60 = 0x43300000;
              iVar15 = iVar15 + 1;
            } while (iVar15 < 2);
            uVar14 = 1;
          }
          else {
            if ((int)param_1 < 9) {
              if (param_1 == 0) {
                uVar14 = 1;
                iVar13 = 0;
                iVar6 = JMessage::TControl::getResource_groupID
                                  (d_mesg::dMesg_gpControl,(ushort)(d_mesg::nowMesgCode >> 0x10));
                if (iVar6 == 0) {
                  iVar6 = 0;
                }
                else {
                  iVar6 = *(int *)(iVar6 + 0xc);
                  if ((uVar4 & 0xffff) < (uint)*(ushort *)(iVar6 + 8)) {
                    iVar6 = iVar6 + (uVar4 & 0xffff) * (uint)*(ushort *)(iVar6 + 10) + 0x10;
                  }
                  else {
                    iVar6 = 0;
                  }
                }
                puVar9 = &uStack152;
                puVar8 = (undefined4 *)(iVar6 + -4);
                iVar6 = 3;
                do {
                  puVar1 = puVar8 + 1;
                  puVar8 = puVar8 + 2;
                  uVar5 = *puVar8;
                  puVar9[1] = *puVar1;
                  puVar9 = puVar9 + 2;
                  *puVar9 = uVar5;
                  iVar6 = iVar6 + -1;
                } while (iVar6 != 0);
                MSL_C.PPCEABI.bare.H::strcpy
                          (acStack125 + 1,
                           &d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mInfo.
                            mPlayerName);
                if ((d_com_inf_game::g_dComIfG_gameInfo.mGameLanguage == 1) &&
                   (((((local_90 == 0x33b || (local_90 == 0xc8b)) || (local_90 == 0x1d21)) ||
                     ((local_90 == 0x31d7 || (local_90 == 0x37dd)))) || (local_90 == 0x37de)))) {
                  sVar7 = MSL_C.PPCEABI.bare.H::strlen(acStack125 + 1);
                  cVar2 = acStack125[sVar7];
                  if (((cVar2 == 's') || (cVar2 == 'S')) ||
                     ((cVar2 == 'z' || (((cVar2 == 'Z' || (cVar2 == 'x')) || (cVar2 == 'X')))))) {
                    MSL_C.PPCEABI.bare.H::strcat(acStack125 + 1,"\'");
                  }
                  else {
                    MSL_C.PPCEABI.bare.H::strcat(acStack125 + 1,"s");
                  }
                }
                if (((d_mesg::retFlag != 0) && (-1 < iVar15)) && (iVar15 < d_mesg::linemax)) {
                  d_mesg::retFlag = 0;
                }
                iVar6 = iVar15 * 4 + 0x38;
                pbVar12 = (byte *)(acStack125 + 1);
                dVar20 = d_mesg::_4147;
                while (*pbVar12 != 0) {
                  bVar3 = *pbVar12 >> 4;
                  if ((bVar3 == 8) || (bVar3 == 9)) {
                    uVar10 = CONCAT11((acStack125 + 1)[iVar13],(acStack125 + 1)[iVar13 + 1]);
                    iVar13 = iVar13 + 2;
                    pbVar12 = pbVar12 + 2;
                  }
                  else {
                    uVar10 = (ushort)(byte)acStack125[iVar13 + 1];
                    iVar13 = iVar13 + 1;
                    pbVar12 = pbVar12 + 1;
                  }
                  uVar11 = *(uint *)(iVar16 + 0x60);
                  uStack100 = (**(code **)(**(int **)(iVar16 + 0x3c) + 0x30))();
                  uStack100 = uStack100 ^ 0x80000000;
                  local_68 = 0x43300000;
                  uStack92 = uVar11 ^ 0x80000000;
                  local_60 = 0x43300000;
                  dVar19 = (double)((float)((double)CONCAT44(0x43300000,uStack92) - dVar20) /
                                   (float)((double)CONCAT44(0x43300000,uStack100) - dVar20));
                  (**(code **)(**(int **)(iVar16 + 0x3c) + 0x2c))
                            (*(int **)(iVar16 + 0x3c),uVar10,&uStack172);
                  if ((-1 < iVar15) && (iVar15 <= d_mesg::linemax)) {
                    if (d_mesg::_4035 == *(float *)(this + iVar6)) {
                      uStack92 = local_ab ^ 0x80000000;
                      local_60 = 0x43300000;
                      *(float *)(this + iVar6) =
                           (float)((double)(float)((double)CONCAT44(0x43300000,uStack92) -
                                                  d_mesg::_4147) * dVar19);
                    }
                    else {
                      uStack92 = local_ab ^ 0x80000000;
                      local_60 = 0x43300000;
                      uStack100 = *(uint *)(iVar16 + 100) ^ 0x80000000;
                      local_68 = 0x43300000;
                      *(float *)(this + iVar6) =
                           *(float *)(this + iVar6) +
                           (float)((double)(float)((double)CONCAT44(0x43300000,uStack92) -
                                                  d_mesg::_4147) * dVar19) +
                           (float)((double)CONCAT44(0x43300000,uStack100) - d_mesg::_4147);
                    }
                  }
                }
              }
              else {
                if (-1 < (int)param_1) {
                  if ((int)param_1 < 8) {
                    uVar14 = 1;
                  }
                  else {
                    this[0x54] = (dMesg_tMeasureProcessor)0x2;
                    iVar15 = 0;
                    dVar19 = (double)d_mesg::_4035;
                    dVar20 = d_mesg::_4147;
                    do {
                      uVar11 = *(uint *)(iVar16 + 0x60);
                      uStack92 = (**(code **)(**(int **)(iVar16 + 0x3c) + 0x30))();
                      uStack92 = uStack92 ^ 0x80000000;
                      local_60 = 0x43300000;
                      uStack100 = uVar11 ^ 0x80000000;
                      local_68 = 0x43300000;
                      dVar18 = (double)((float)((double)CONCAT44(0x43300000,uStack100) - dVar20) /
                                       (float)((double)CONCAT44(0x43300000,uStack92) - dVar20));
                      (**(code **)(**(int **)(iVar16 + 0x3c) + 0x2c))
                                (*(int **)(iVar16 + 0x3c),0x48,&uStack176);
                      uStack92 = (uint)local_af;
                      if (dVar19 == (double)*(float *)(this + 0x48)) {
                        *(float *)(this + 0x48) =
                             (float)((double)(float)((double)CONCAT44(0x43300000,
                                                                      uStack92 ^ 0x80000000) -
                                                    d_mesg::_4147) * dVar18);
                      }
                      else {
                        uStack100 = *(uint *)(iVar16 + 100) ^ 0x80000000;
                        local_68 = 0x43300000;
                        *(float *)(this + 0x48) =
                             (float)((double)*(float *)(this + 0x48) +
                                    (double)((float)((double)(float)((double)CONCAT44(0x43300000,
                                                                                      uStack92 ^
                                                                                      0x80000000) -
                                                                    d_mesg::_4147) * dVar18) +
                                            (float)((double)CONCAT44(0x43300000,uStack100) -
                                                   d_mesg::_4147)));
                      }
                      uStack92 = uStack92 ^ 0x80000000;
                      local_60 = 0x43300000;
                      iVar15 = iVar15 + 1;
                    } while (iVar15 < 2);
                    uVar14 = 1;
                  }
                }
              }
            }
            else {
              if (param_1 == 0x29) {
                uVar14 = 1;
                iVar6 = 0;
                uVar10 = dSv_event_c::getEventReg
                                   (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0xba0f)
                ;
                f_op_msg_mng::fopMsgM_passwordGet(local_a8,(uVar10 & 0xff) + 0x1b37);
                if (((d_mesg::retFlag != 0) && (-1 < iVar15)) && (iVar15 < d_mesg::linemax)) {
                  d_mesg::retFlag = 0;
                }
                iVar13 = iVar15 * 4 + 0x38;
                pbVar12 = local_a8;
                dVar20 = d_mesg::_4147;
                while (*pbVar12 != 0) {
                  bVar3 = *pbVar12 >> 4;
                  if ((bVar3 == 8) || (bVar3 == 9)) {
                    uVar10 = CONCAT11(local_a8[iVar6],local_a8[iVar6 + 1]);
                    iVar6 = iVar6 + 2;
                    pbVar12 = pbVar12 + 2;
                  }
                  else {
                    uVar10 = (ushort)local_a8[iVar6];
                    iVar6 = iVar6 + 1;
                    pbVar12 = pbVar12 + 1;
                  }
                  uVar11 = *(uint *)(iVar16 + 0x60);
                  uStack92 = (**(code **)(**(int **)(iVar16 + 0x3c) + 0x30))();
                  uStack92 = uStack92 ^ 0x80000000;
                  local_60 = 0x43300000;
                  uStack100 = uVar11 ^ 0x80000000;
                  local_68 = 0x43300000;
                  dVar19 = (double)((float)((double)CONCAT44(0x43300000,uStack100) - dVar20) /
                                   (float)((double)CONCAT44(0x43300000,uStack92) - dVar20));
                  (**(code **)(**(int **)(iVar16 + 0x3c) + 0x2c))
                            (*(int **)(iVar16 + 0x3c),uVar10,&uStack184);
                  if ((-1 < iVar15) && (iVar15 <= d_mesg::linemax)) {
                    if (d_mesg::_4035 == *(float *)(this + iVar13)) {
                      uStack92 = local_b7 ^ 0x80000000;
                      local_60 = 0x43300000;
                      *(float *)(this + iVar13) =
                           (float)((double)(float)((double)CONCAT44(0x43300000,uStack92) -
                                                  d_mesg::_4147) * dVar19);
                    }
                    else {
                      uStack92 = local_b7 ^ 0x80000000;
                      local_60 = 0x43300000;
                      uStack100 = *(uint *)(iVar16 + 100) ^ 0x80000000;
                      local_68 = 0x43300000;
                      *(float *)(this + iVar13) =
                           *(float *)(this + iVar13) +
                           (float)((double)(float)((double)CONCAT44(0x43300000,uStack92) -
                                                  d_mesg::_4147) * dVar19) +
                           (float)((double)CONCAT44(0x43300000,uStack100) - d_mesg::_4147);
                    }
                  }
                }
              }
              else {
                if (((int)param_1 < 0x29) && ((int)param_1 < 0x1e)) {
                  if ((d_mesg::retFlag != 0) && ((-1 < iVar15 && (iVar15 < d_mesg::linemax)))) {
                    d_mesg::retFlag = 0;
                  }
                  if ((-1 < iVar15) && (iVar15 < 4)) {
                    *(float *)(this + iVar15 * 4 + 0x38) =
                         *(float *)(this + iVar15 * 4 + 0x38) +
                         (float)((double)CONCAT44(0x43300000,
                                                  *(int *)(iVar16 + 0x60) + *(int *)(iVar16 + 100) ^
                                                  0x80000000) - d_mesg::_4147);
                  }
                  uVar14 = 1;
                }
              }
            }
          }
        }
      }
    }
    else {
      if (uVar11 == 0x30000) {
        uVar14 = 1;
      }
    }
  }
  __psq_l0(auStack8,uVar17);
  __psq_l1(auStack8,uVar17);
  __psq_l0(auStack24,uVar17);
  __psq_l1(auStack24,uVar17);
  __psq_l0(auStack40,uVar17);
  __psq_l1(auStack40,uVar17);
  return uVar14;
}


/* WARNING: Removing unreachable block (ram,0x801e27f0) */
/* __thiscall dMesg_tMeasureProcessor::do_systemTagCode(unsigned short,
                                                        void const *,
                                                        unsigned long) */

undefined4 __thiscall
dMesg_tMeasureProcessor::do_systemTagCode
          (dMesg_tMeasureProcessor *this,ushort param_1,void *param_2,ulong param_3)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(this + 0x4c);
  iVar2 = *(int *)(this + 0x50);
  if (((param_1 < 4) && (param_1 == 1)) && (param_3 == 2)) {
                    /* WARNING: Load size is inaccurate */
    uVar1 = *param_2;
    *(int *)(*(int *)(this + 4) + 0x60) =
         (int)(d_mesg::_4324 +
              (float)((double)CONCAT44(0x43300000,
                                       (uint)uVar1 * *(int *)(*(int *)(this + 4) + 0x5c) ^
                                       0x80000000) - d_mesg::_4147) / d_mesg::_4585);
    if (((0 < iVar2 - iVar3) && (iVar2 - iVar3 < 3)) &&
       ((100 < uVar1 && (d_mesg::m_strSizeFlag == '\0')))) {
      d_mesg::linemax = d_mesg::linemax + -1;
      d_mesg::m_strSizeFlag = '\x01';
    }
  }
  return 1;
}


/* __thiscall dMesg_tRenderingProcessor::dMesg_tRenderingProcessor(JMessage::TControl *) */

void __thiscall
dMesg_tRenderingProcessor::dMesg_tRenderingProcessor
          (dMesg_tRenderingProcessor *this,TControl *param_1)

{
  JMessage::TRenderingProcessor::TRenderingProcessor((TRenderingProcessor *)this,param_1);
  *(undefined1 **)this = &__vt;
  return;
}


/* __thiscall dMesg_tRenderingProcessor::do_begin(void const *,
                                                  char const *) */

void __thiscall
dMesg_tRenderingProcessor::do_begin(dMesg_tRenderingProcessor *this,void *param_1,char *param_2)

{
  return;
}


/* __thiscall dMesg_tRenderingProcessor::do_end(void) */

void __thiscall dMesg_tRenderingProcessor::do_end(dMesg_tRenderingProcessor *this)

{
  return;
}


/* __thiscall dMesg_tRenderingProcessor::do_character(int) */

void __thiscall dMesg_tRenderingProcessor::do_character(dMesg_tRenderingProcessor *this,int param_1)

{
  return;
}


/* __thiscall dMesg_tRenderingProcessor::do_tag(unsigned long,
                                                void const *,
                                                unsigned long) */

undefined4 __thiscall
dMesg_tRenderingProcessor::do_tag
          (dMesg_tRenderingProcessor *this,ulong param_1,void *param_2,ulong param_3)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  uVar1 = param_1 & 0xff0000;
  if (uVar1 == 0x20000) {
    return 1;
  }
  if (0x1ffff < uVar1) {
    if (uVar1 != 0x30000) {
      return uVar2;
    }
    return 1;
  }
  if (uVar1 == 0x10000) {
    return 1;
  }
  if (0xffff < uVar1) {
    return uVar2;
  }
  if (uVar1 != 0) {
    return uVar2;
  }
  if (param_1 != 0x29) {
    if (0x28 < (int)param_1) {
      return uVar2;
    }
    if (0x1d < (int)param_1) {
      return uVar2;
    }
    if ((int)param_1 < 0) {
      return uVar2;
    }
  }
  return 1;
}


/* WARNING: Removing unreachable block (ram,0x801e2990) */
/* __thiscall dMesg_tRenderingProcessor::do_systemTagCode(unsigned short,
                                                          void const *,
                                                          unsigned long) */

undefined4 __thiscall
dMesg_tRenderingProcessor::do_systemTagCode
          (dMesg_tRenderingProcessor *this,ushort param_1,void *param_2,ulong param_3)

{
  if ((param_1 != 6) && ((5 < param_1 || (3 < param_1)))) {
    return 1;
  }
  return 1;
}


/* __thiscall dMesg_screenData_c::setCommonData(void) */

void __thiscall dMesg_screenData_c::setCommonData(dMesg_screenData_c *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  double dVar4;
  undefined4 uVar5;
  int iVar6;
  dMesg_screenData_c local_68;
  dMesg_screenData_c dStack103;
  dMesg_screenData_c dStack102;
  dMesg_screenData_c dStack101;
  dMesg_screenData_c local_64;
  dMesg_screenData_c dStack99;
  dMesg_screenData_c dStack98;
  dMesg_screenData_c dStack97;
  
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x88),*(JUTFont **)(this + 0x10));
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0xc0),*(JUTFont **)(this + 0x14));
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0xf8),*(JUTFont **)(this + 0x10));
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x130),*(JUTFont **)(this + 0x14));
  fVar1 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e6bb4 ^ 0x80000000U) - d_mesg::_4147);
  fVar2 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e6bb4 ^ 0x80000000U) - d_mesg::_4147);
  iVar6 = *(int *)(this + 0x88);
  fVar3 = d_mesg::_4035;
  if (d_mesg::_4035 < fVar1) {
    fVar3 = fVar1;
  }
  *(float *)(iVar6 + 0xe8) = fVar3;
  fVar3 = d_mesg::_4035;
  if (d_mesg::_4035 < fVar2) {
    fVar3 = fVar2;
  }
  *(float *)(iVar6 + 0xec) = fVar3;
  iVar6 = *(int *)(this + 0xf8);
  fVar3 = d_mesg::_4035;
  if (d_mesg::_4035 < fVar1) {
    fVar3 = fVar1;
  }
  *(float *)(iVar6 + 0xe8) = fVar3;
  fVar1 = d_mesg::_4035;
  if (d_mesg::_4035 < fVar2) {
    fVar1 = fVar2;
  }
  *(float *)(iVar6 + 0xec) = fVar1;
  dVar4 = d_mesg::_4147;
  *(float *)(*(int *)(this + 0x88) + 0xe0) =
       (float)((double)CONCAT44(0x43300000,(int)DAT_803e6b9e ^ 0x80000000) - d_mesg::_4147);
  *(float *)(*(int *)(this + 0xc0) + 0xe0) =
       (float)((double)CONCAT44(0x43300000,(int)DAT_803e6ba0 ^ 0x80000000) - dVar4);
  *(float *)(*(int *)(this + 0xf8) + 0xe0) =
       (float)((double)CONCAT44(0x43300000,(int)DAT_803e6b9e ^ 0x80000000) - dVar4);
  *(float *)(*(int *)(this + 0x130) + 0xe0) =
       (float)((double)CONCAT44(0x43300000,(int)DAT_803e6ba0 ^ 0x80000000) - dVar4);
  *(float *)(*(int *)(this + 0x88) + 0xe4) =
       (float)((double)CONCAT44(0x43300000,(int)DAT_803e6ba2 ^ 0x80000000) - dVar4);
  *(float *)(*(int *)(this + 0xf8) + 0xe4) =
       (float)((double)CONCAT44(0x43300000,(int)DAT_803e6ba2 ^ 0x80000000) - dVar4);
  *(undefined2 *)(this + 0x1a8) = 0;
  uVar5 = *(undefined4 *)(*(int *)(this + 0x18) + 0x108);
  local_64 = SUB41((uint)uVar5 >> 0x18,0);
  this[0x1b0] = local_64;
  dStack99 = SUB41((uint)uVar5 >> 0x10,0);
  this[0x1b1] = dStack99;
  dStack98 = SUB41((uint)uVar5 >> 8,0);
  this[0x1b2] = dStack98;
  dStack97 = SUB41(uVar5,0);
  this[0x1b3] = dStack97;
  uVar5 = *(undefined4 *)(*(int *)(this + 0x18) + 0x104);
  local_68 = SUB41((uint)uVar5 >> 0x18,0);
  this[0x1ac] = local_68;
  dStack103 = SUB41((uint)uVar5 >> 0x10,0);
  this[0x1ad] = dStack103;
  dStack102 = SUB41((uint)uVar5 >> 8,0);
  this[0x1ae] = dStack102;
  dStack101 = SUB41(uVar5,0);
  this[0x1af] = dStack101;
  return;
}


/* __thiscall dMesg_screenData_c::initString(char *,
                                             int) */

void __thiscall dMesg_screenData_c::initString(dMesg_screenData_c *this,char *param_1,int param_2)

{
  char acStack40 [36];
  
  if (param_2 == 1) {
    MSL_C.PPCEABI.bare.H::strcpy(param_1,"\x1bCC[FFFFFFFF]\x1bGM[0]");
  }
  else {
    if (param_2 < 1) {
      if (-1 < param_2) {
        MSL_C.PPCEABI.bare.H::sprintf
                  (acStack40,"\x1bCC[%08x]\x1bGM[0]",
                   *(undefined4 *)(d_mesg::dMesg_gpSequenceProcessor + 0x6c));
        MSL_C.PPCEABI.bare.H::strcpy(param_1,acStack40);
      }
    }
    else {
      if (param_2 < 4) {
        MSL_C.PPCEABI.bare.H::strcpy(param_1,"\x1bCC[000000FF]\x1bGM[0]");
      }
    }
  }
  return;
}


/* __thiscall dMesg_screenData_c::setString(char *,
                                            int) */

void __thiscall dMesg_screenData_c::setString(dMesg_screenData_c *this,char *param_1,int param_2)

{
  J2DTextBox::setString(*(J2DTextBox **)(this + param_2 * 0x38 + 0x88),param_1,param_2);
  return;
}


/* __thiscall dMesg_screenData_c::shiftSet(int,
                                           int) */

void __thiscall dMesg_screenData_c::shiftSet(dMesg_screenData_c *this,int param_1,int param_2)

{
  double dVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  dVar1 = d_mesg::_4147;
  iVar3 = 0;
  iVar4 = 4;
  do {
    iVar2 = *(int *)(this + iVar3 + 0x88);
    *(float *)(iVar2 + 0xd8) = (float)((double)CONCAT44(0x43300000,param_1 ^ 0x80000000) - dVar1);
    *(float *)(iVar2 + 0xdc) = (float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - dVar1);
    iVar3 = iVar3 + 0x38;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return;
}


/* __thiscall dMesg_screenData_c::arwAnimeInit(void) */

void __thiscall dMesg_screenData_c::arwAnimeInit(dMesg_screenData_c *this)

{
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x50));
  *(undefined4 *)(this + 0x6c) = *(undefined4 *)(this + 100);
  *(undefined4 *)(this + 0x70) = *(undefined4 *)(this + 0x68);
  *(undefined4 *)(this + 0x7c) = *(undefined4 *)(this + 0x74);
  *(undefined4 *)(this + 0x80) = *(undefined4 *)(this + 0x78);
  *(undefined2 *)(this + 0x1a8) = 0;
  return;
}


/* __thiscall dMesg_screenData_c::arwAnime(void) */

void __thiscall dMesg_screenData_c::arwAnime(dMesg_screenData_c *this)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  double dVar6;
  
  *(short *)(this + 0x1a8) = *(short *)(this + 0x1a8) + 1;
  fVar1 = d_mesg::_5168;
  if ((byte)this[0x85] < (byte)this[0x84]) {
    dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,(int)*(short *)(this + 0x1a8),0);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x50),(float)dVar6);
    if (*(short *)(this + 0x1a8) == 10) {
      *(undefined2 *)(this + 0x1a8) = 0;
    }
  }
  else {
    uVar3 = SEXT24(*(short *)(this + 0x1a8));
    uVar4 = SEXT24(d_mesg::step_5121);
    fVar2 = fVar1;
    if ((int)uVar4 < (int)uVar3) {
      uVar5 = SEXT24(DAT_803609be);
      if ((int)uVar5 < (int)uVar3) {
        uVar4 = SEXT24(DAT_803609c0);
        if ((int)uVar4 < (int)uVar3) {
          uVar5 = SEXT24(DAT_803609c2);
          if ((int)uVar5 < (int)uVar3) {
            if ((int)DAT_803609c4 < (int)uVar3) {
              *(undefined2 *)(this + 0x1a8) = 0;
            }
            else {
              fVar1 = (float)((double)CONCAT44(0x43300000,uVar3 ^ 0x80000000) - d_mesg::_4147) -
                      (float)((double)CONCAT44(0x43300000,uVar5 ^ 0x80000000) - d_mesg::_4147);
              uVar3 = (int)DAT_803609c4 - uVar5 ^ 0x80000000;
              fVar2 = (fVar1 * fVar1) /
                      ((float)((double)CONCAT44(0x43300000,uVar3) - d_mesg::_4147) *
                      (float)((double)CONCAT44(0x43300000,uVar3) - d_mesg::_4147));
              fVar1 = DAT_803609a0 + fVar2 * (DAT_803609a4 - DAT_803609a0);
              fVar2 = DAT_803609b4 + fVar2 * (DAT_803609b8 - DAT_803609b4);
            }
          }
          else {
            fVar1 = (float)((double)CONCAT44(0x43300000,uVar3 ^ 0x80000000) - d_mesg::_4147) -
                    (float)((double)CONCAT44(0x43300000,uVar4 ^ 0x80000000) - d_mesg::_4147);
            uVar3 = uVar5 - uVar4 ^ 0x80000000;
            fVar2 = (fVar1 * fVar1) /
                    ((float)((double)CONCAT44(0x43300000,uVar3) - d_mesg::_4147) *
                    (float)((double)CONCAT44(0x43300000,uVar3) - d_mesg::_4147));
            fVar1 = DAT_8036099c + fVar2 * (DAT_803609a0 - DAT_8036099c);
            fVar2 = DAT_803609b0 + fVar2 * (DAT_803609b4 - DAT_803609b0);
          }
        }
        else {
          fVar1 = (float)((double)CONCAT44(0x43300000,uVar3 ^ 0x80000000) - d_mesg::_4147) -
                  (float)((double)CONCAT44(0x43300000,uVar5 ^ 0x80000000) - d_mesg::_4147);
          uVar3 = uVar4 - uVar5 ^ 0x80000000;
          fVar2 = (fVar1 * fVar1) /
                  ((float)((double)CONCAT44(0x43300000,uVar3) - d_mesg::_4147) *
                  (float)((double)CONCAT44(0x43300000,uVar3) - d_mesg::_4147));
          fVar1 = DAT_80360998 + fVar2 * (DAT_8036099c - DAT_80360998);
          fVar2 = DAT_803609ac + fVar2 * (DAT_803609b0 - DAT_803609ac);
        }
      }
      else {
        fVar1 = (float)((double)CONCAT44(0x43300000,uVar3 ^ 0x80000000) - d_mesg::_4147) -
                (float)((double)CONCAT44(0x43300000,uVar4 ^ 0x80000000) - d_mesg::_4147);
        uVar3 = uVar5 - uVar4 ^ 0x80000000;
        fVar2 = (fVar1 * fVar1) /
                ((float)((double)CONCAT44(0x43300000,uVar3) - d_mesg::_4147) *
                (float)((double)CONCAT44(0x43300000,uVar3) - d_mesg::_4147));
        fVar1 = d_mesg::scaleX_5119 + fVar2 * (DAT_80360998 - d_mesg::scaleX_5119);
        fVar2 = d_mesg::scaleY_5120 + fVar2 * (DAT_803609ac - d_mesg::scaleY_5120);
      }
    }
    *(float *)(this + 0x7c) = *(float *)(this + 0x74) * fVar1;
    *(float *)(this + 0x80) = *(float *)(this + 0x78) * fVar2;
    *(float *)(this + 0x70) =
         (float)((double)CONCAT44(0x43300000,(int)DAT_803e6baa ^ 0x80000000) - d_mesg::_4147) +
         ((float)((double)CONCAT44(0x43300000,*(uint *)(this + 0x1a4) ^ 0x80000000) - d_mesg::_4147)
         - *(float *)(this + 0x80) * d_mesg::_4324);
    f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(this + 0x50));
  }
  return;
}


/* __thiscall dMesg_screenData_c::dotAnimeInit(void) */

void __thiscall dMesg_screenData_c::dotAnimeInit(dMesg_screenData_c *this)

{
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x18));
  *(undefined2 *)(this + 0x1a8) = 0;
  return;
}


/* WARNING: Removing unreachable block (ram,0x801e3684) */
/* WARNING: Removing unreachable block (ram,0x801e3674) */
/* WARNING: Removing unreachable block (ram,0x801e3664) */
/* WARNING: Removing unreachable block (ram,0x801e365c) */
/* WARNING: Removing unreachable block (ram,0x801e366c) */
/* WARNING: Removing unreachable block (ram,0x801e367c) */
/* WARNING: Removing unreachable block (ram,0x801e368c) */
/* WARNING: Could not reconcile some variable overlaps */
/* __thiscall dMesg_screenData_c::dotAnime(void) */

void __thiscall dMesg_screenData_c::dotAnime(dMesg_screenData_c *this)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  undefined4 uVar4;
  double dVar5;
  undefined8 in_f25;
  double dVar6;
  undefined8 in_f26;
  double dVar7;
  undefined8 in_f27;
  double dVar8;
  undefined8 in_f28;
  double dVar9;
  undefined8 in_f29;
  double dVar10;
  undefined8 in_f30;
  double dVar11;
  undefined8 in_f31;
  double dVar12;
  undefined local_f8;
  undefined uStack247;
  undefined uStack246;
  undefined uStack245;
  undefined local_f4;
  undefined uStack243;
  undefined uStack242;
  undefined uStack241;
  undefined4 local_f0;
  undefined4 local_ec;
  double local_e8;
  double local_e0;
  double local_d8;
  double local_d0;
  double local_c8;
  double local_c0;
  double local_b8;
  double local_b0;
  double local_a8;
  double local_a0;
  double local_98;
  double local_90;
  double local_88;
  double local_80;
  undefined auStack104 [16];
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar4 = 0;
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
  local_e8 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x1b0]);
  dVar12 = (double)(d_mesg::_5221 - (float)(local_e8 - d_mesg::_5225));
  local_e0 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x1b1]);
  dVar11 = (double)(d_mesg::_5221 - (float)(local_e0 - d_mesg::_5225));
  local_d8 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x1b2]);
  dVar10 = (double)(d_mesg::_5221 - (float)(local_d8 - d_mesg::_5225));
  local_d0 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x1ac]);
  dVar9 = (double)(d_mesg::_5222 - (float)(local_d0 - d_mesg::_5225));
  local_c8 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x1ad]);
  dVar8 = (double)(d_mesg::_5222 - (float)(local_c8 - d_mesg::_5225));
  local_c0 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x1ae]);
  dVar7 = (double)(d_mesg::_5223 - (float)(local_c0 - d_mesg::_5225));
  local_b8 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x4c]);
  dVar6 = (double)(d_mesg::_5222 - (float)(local_b8 - d_mesg::_5225));
  *(short *)(this + 0x1a8) = *(short *)(this + 0x1a8) + 1;
  local_ec = CONCAT31(0xffffff,this[0x1b3]);
  local_f0 = CONCAT31(0xffffff,this[0x1af]);
  if ((byte)this[0x4d] < (byte)this[0x4c]) {
    dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,(int)*(short *)(this + 0x1a8),0);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x18),(float)dVar6);
    if (*(short *)(this + 0x1a8) == 10) {
      *(undefined2 *)(this + 0x1a8) = 0;
    }
  }
  else {
    iVar3 = (int)*(short *)(this + 0x1a8);
    if (iVar3 < 0x3c) {
      uVar1 = (ushort)local_ec;
      uVar2 = (ushort)local_f0;
      if (iVar3 < 0x1f) {
        dVar5 = (double)f_op_msg_mng::fopMsgM_valueIncrease(0x1e,iVar3,0);
        local_80 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x1b0]);
        local_90 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x1b1]);
        local_a0 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x1b2]);
        local_ec._2_2_ =
             uVar1 & 0xff |
             (ushort)(byte)(int)((float)(local_a0 - d_mesg::_5225) + (float)(dVar10 * dVar5)) << 8;
        local_ec = (int)((float)(local_80 - d_mesg::_5225) + (float)(dVar12 * dVar5)) << 0x18 |
                   CONCAT12((char)(int)((float)(local_90 - d_mesg::_5225) + (float)(dVar11 * dVar5))
                            ,uVar1) & 0xffff0000 | (uint)local_ec._2_2_;
        local_b0 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x1ac]);
        local_c0 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x1ad]);
        local_d0 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x1ae]);
        local_f0._2_2_ =
             uVar2 & 0xff |
             (ushort)(byte)(int)((float)(local_d0 - d_mesg::_5225) + (float)(dVar7 * dVar5)) << 8;
        local_f0 = (int)((float)(local_b0 - d_mesg::_5225) + (float)(dVar9 * dVar5)) << 0x18 |
                   CONCAT12((char)(int)((float)(local_c0 - d_mesg::_5225) + (float)(dVar8 * dVar5)),
                            uVar2) & 0xffff0000 | (uint)local_f0._2_2_;
        local_e0 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x4c]);
        this[0x4d] = SUB41((int)((float)(local_e0 - d_mesg::_5225) + (float)(dVar6 * dVar5)),0);
      }
      else {
        dVar5 = (double)f_op_msg_mng::fopMsgM_valueIncrease(0x1e,0x3c - iVar3,0);
        local_b8 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x1b0]);
        local_c8 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x1b1]);
        local_d8 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x1b2]);
        local_ec._2_2_ =
             uVar1 & 0xff |
             (ushort)(byte)(int)((float)(local_d8 - d_mesg::_5225) + (float)(dVar10 * dVar5)) << 8;
        local_ec = (int)((float)(local_b8 - d_mesg::_5225) + (float)(dVar12 * dVar5)) << 0x18 |
                   CONCAT12((char)(int)((float)(local_c8 - d_mesg::_5225) + (float)(dVar11 * dVar5))
                            ,uVar1) & 0xffff0000 | (uint)local_ec._2_2_;
        local_e8 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x1ac]);
        local_a8 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x1ad]);
        local_98 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x1ae]);
        local_f0._2_2_ =
             uVar2 & 0xff |
             (ushort)(byte)(int)((float)(local_98 - d_mesg::_5225) + (float)(dVar7 * dVar5)) << 8;
        local_f0 = (int)((float)(local_e8 - d_mesg::_5225) + (float)(dVar9 * dVar5)) << 0x18 |
                   CONCAT12((char)(int)((float)(local_a8 - d_mesg::_5225) + (float)(dVar8 * dVar5)),
                            uVar2) & 0xffff0000 | (uint)local_f0._2_2_;
        local_88 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x4c]);
        this[0x4d] = SUB41((int)((float)(local_88 - d_mesg::_5225) + (float)(dVar6 * dVar5)),0);
      }
    }
    else {
      local_ec = *(uint *)(this + 0x1b0);
      local_f0 = *(uint *)(this + 0x1ac);
      f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x18);
      *(undefined2 *)(this + 0x1a8) = 0;
    }
    iVar3 = *(int *)(this + 0x18);
    local_f4 = (undefined)(local_ec >> 0x18);
    *(undefined *)(iVar3 + 0x108) = local_f4;
    uStack243 = (undefined)(local_ec >> 0x10);
    *(undefined *)(iVar3 + 0x109) = uStack243;
    uStack242 = (undefined)(local_ec >> 8);
    *(undefined *)(iVar3 + 0x10a) = uStack242;
    uStack241 = (undefined)local_ec;
    *(undefined *)(iVar3 + 0x10b) = uStack241;
    iVar3 = *(int *)(this + 0x18);
    local_f8 = (undefined)(local_f0 >> 0x18);
    *(undefined *)(iVar3 + 0x104) = local_f8;
    uStack247 = (undefined)(local_f0 >> 0x10);
    *(undefined *)(iVar3 + 0x105) = uStack247;
    uStack246 = (undefined)(local_f0 >> 8);
    *(undefined *)(iVar3 + 0x106) = uStack246;
    uStack245 = (undefined)local_f0;
    *(undefined *)(iVar3 + 0x107) = uStack245;
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  __psq_l0(auStack24,uVar4);
  __psq_l1(auStack24,uVar4);
  __psq_l0(auStack40,uVar4);
  __psq_l1(auStack40,uVar4);
  __psq_l0(auStack56,uVar4);
  __psq_l1(auStack56,uVar4);
  __psq_l0(auStack72,uVar4);
  __psq_l1(auStack72,uVar4);
  __psq_l0(auStack88,uVar4);
  __psq_l1(auStack88,uVar4);
  __psq_l0(auStack104,uVar4);
  __psq_l1(auStack104,uVar4);
  return;
}


/* __thiscall dMesg_screenDataTalk_c::createScreen(void) */

void __thiscall dMesg_screenDataTalk_c::createScreen(dMesg_screenDataTalk_c *this)

{
  J2DPane *this_00;
  ulong uVar1;
  J2DScreen *pJVar2;
  int iVar3;
  TBox2_float_ local_18;
  
  this_00 = (J2DPane *)JKernel::operator_new(0xd4);
  if (this_00 != (J2DPane *)0x0) {
    local_18.mTL.x = d_mesg::_4035;
    local_18.mTL.y = d_mesg::_4035;
    local_18.mBR.x = d_mesg::_5289;
    local_18.mBR.y = d_mesg::_5290;
    J2DPane::J2DPane(this_00,(J2DPane *)0x0,true,0x726f6f74,&local_18);
    this_00->vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
    *(undefined4 *)this_00[1].mMagic = 0xffffffff;
    *(undefined *)&this_00[1].vtbl = 0;
  }
  *(J2DPane **)(this + 0xc) = this_00;
  if (*(int *)(this + 0xc) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_mesg.cpp",0x861,"scrn != 0");
    m_Do_printf::OSPanic("d_mesg.cpp",0x861,&DAT_803609f8);
  }
  J2DScreen::set(*(J2DScreen **)(this + 0xc),"hukidashi_d00.blo",
                 d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpDmsgArchive);
  pJVar2 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x64743030);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x18),pJVar2);
  pJVar2 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x797a3030);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x50),pJVar2);
  pJVar2 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x74783032);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x88),pJVar2);
  pJVar2 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x74783033);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0xc0),pJVar2);
  pJVar2 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x74787430);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0xf8),pJVar2);
  pJVar2 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x74783031);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x130),pJVar2);
  pJVar2 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x6d733030);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x168),pJVar2);
  if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mConfig._0_1_ == '\0') {
    *(undefined *)(*(int *)(this + 0xc0) + 0xaa) = 1;
    *(undefined *)(*(int *)(this + 0x130) + 0xaa) = 1;
    d_mesg::messageOffsetY = 0;
  }
  else {
    *(undefined *)(*(int *)(this + 0xc0) + 0xaa) = 0;
    *(undefined *)(*(int *)(this + 0x130) + 0xaa) = 0;
    d_mesg::messageOffsetY = 0xfffc;
  }
  iVar3 = *(int *)(this + 0x168);
  *(undefined *)(iVar3 + 0x104) = 0x1e;
  *(undefined *)(iVar3 + 0x105) = 0x1e;
  *(undefined *)(iVar3 + 0x106) = 0x1e;
  *(undefined *)(iVar3 + 0x107) = 0xd7;
  iVar3 = *(int *)(this + 0x168);
  *(undefined *)(iVar3 + 0x108) = 0x1e;
  *(undefined *)(iVar3 + 0x109) = 0x1e;
  *(undefined *)(iVar3 + 0x10a) = 0x4b;
  *(undefined *)(iVar3 + 0x10b) = 0;
  dMesg_screenData_c::setCommonData((dMesg_screenData_c *)this);
  return;
}


/* __thiscall dMesg_screenDataTalk_c::changeFont(JUTFont *) */

void __thiscall dMesg_screenDataTalk_c::changeFont(dMesg_screenDataTalk_c *this,JUTFont *param_1)

{
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x88),param_1);
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0xc0),param_1);
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0xf8),param_1);
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x130),param_1);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x801e3b94) */
/* WARNING: Removing unreachable block (ram,0x801e3b84) */
/* WARNING: Removing unreachable block (ram,0x801e3b8c) */
/* WARNING: Removing unreachable block (ram,0x801e3b9c) */
/* __thiscall dMesg_screenDataTalk_c::openAnime(void) */

undefined4 __thiscall dMesg_screenDataTalk_c::openAnime(dMesg_screenDataTalk_c *this)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  double dVar5;
  undefined8 in_f28;
  double dVar6;
  undefined8 in_f29;
  double dVar7;
  undefined8 in_f30;
  double dVar8;
  undefined8 in_f31;
  double dVar9;
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  uVar2 = 0;
  *(short *)(this + 0x1a8) = *(short *)(this + 0x1a8) + 1;
  iVar1 = (int)*(short *)(this + 0x1a8);
  if (iVar1 < 0xd) {
    if (iVar1 < 10) {
      dVar9 = (double)d_mesg::_4585;
      dVar8 = (double)(float)((double)(float)(dVar9 * (double)*(float *)(this + 400)) /
                             (double)*(float *)(this + 0x18c));
      dVar7 = (double)(float)((double)*(float *)(this + 0x18c) - dVar9);
      dVar6 = (double)(float)((double)*(float *)(this + 400) - dVar8);
      dVar5 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,iVar1,0);
    }
    else {
      dVar9 = (double)*(float *)(this + 0x18c);
      dVar8 = (double)*(float *)(this + 400);
      dVar7 = (double)(float)((double)d_mesg::_5323 - dVar9);
      dVar6 = (double)(float)((double)(float)((double)(float)((double)d_mesg::_5323 * dVar8) / dVar9
                                             ) - dVar8);
      dVar5 = (double)JKernel::JMath::jmaSinTable
                      [(int)((int)(d_mesg::_5324 *
                                  (float)((double)CONCAT44(0x43300000,iVar1 - 10U ^ 0x80000000) -
                                         d_mesg::_4147)) & 0xffffU) >>
                       (JKernel::JMath::jmaSinShift & 0x3f)];
    }
    *(float *)(this + 0x194) = (float)(dVar9 + (double)(float)(dVar7 * dVar5));
    *(float *)(this + 0x198) = (float)(dVar8 + (double)(float)(dVar6 * dVar5));
    f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(this + 0x168));
    dVar9 = (double)f_op_msg_mng::fopMsgM_valueIncrease(0xd,(int)*(short *)(this + 0x1a8),0);
    *(float *)(this + 0x1b4) = (float)dVar9;
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x168),*(float *)(this + 0x1b4))
    ;
  }
  else {
    *(undefined4 *)(this + 0x184) = *(undefined4 *)(this + 0x17c);
    *(undefined4 *)(this + 0x188) = *(undefined4 *)(this + 0x180);
    f_op_msg_mng::fopMsgM_paneScaleXY((fopMsgM_pane_class *)(this + 0x168),d_mesg::_5168);
    f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x168);
    iVar1 = 0;
    iVar3 = 0;
    do {
      f_op_msg_mng::fopMsgM_setInitAlpha(this + iVar3 + 0x88);
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 0x38;
    } while (iVar1 < 4);
    uVar2 = 1;
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  __psq_l0(auStack24,uVar4);
  __psq_l1(auStack24,uVar4);
  __psq_l0(auStack40,uVar4);
  __psq_l1(auStack40,uVar4);
  __psq_l0(auStack56,uVar4);
  __psq_l1(auStack56,uVar4);
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x801e3cb8) */
/* WARNING: Removing unreachable block (ram,0x801e3cb0) */
/* WARNING: Removing unreachable block (ram,0x801e3cc0) */
/* __thiscall dMesg_screenDataTalk_c::closeAnime(void) */

bool __thiscall dMesg_screenDataTalk_c::closeAnime(dMesg_screenDataTalk_c *this)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  double dVar4;
  undefined8 in_f29;
  double dVar5;
  undefined8 in_f30;
  double dVar6;
  undefined8 in_f31;
  double dVar7;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  if (*(short *)(this + 0x1a8) == 0) {
    iVar1 = 0;
    iVar2 = 0;
    do {
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar2 + 0x88));
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x38;
    } while (iVar1 < 4);
  }
  *(short *)(this + 0x1a8) = *(short *)(this + 0x1a8) + 1;
  iVar1 = (int)*(short *)(this + 0x1a8);
  if (iVar1 < 10) {
    dVar7 = (double)*(float *)(this + 0x18c);
    dVar6 = (double)*(float *)(this + 400);
    dVar5 = (double)(float)((double)(d_mesg::_5346 * (float)(dVar6 / dVar7)) - dVar6);
    dVar4 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,iVar1,0);
    *(float *)(this + 0x194) =
         (float)(dVar7 + (double)(float)((double)(float)((double)d_mesg::_5346 - dVar7) * dVar4));
    *(float *)(this + 0x198) = (float)(dVar6 + (double)(float)(dVar5 * dVar4));
    *(float *)(this + 0x1b4) = (float)((double)d_mesg::_5168 - dVar4);
    f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(this + 0x168));
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x168),*(float *)(this + 0x1b4))
    ;
  }
  else {
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x168));
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  __psq_l0(auStack24,uVar3);
  __psq_l1(auStack24,uVar3);
  __psq_l0(auStack40,uVar3);
  __psq_l1(auStack40,uVar3);
  return iVar1 >= 10;
}


/* __thiscall dMesg_screenDataTalk_c::setTextPosition(unsigned char) */

void __thiscall dMesg_screenDataTalk_c::setTextPosition(dMesg_screenDataTalk_c *this,uchar param_1)

{
  double dVar1;
  float fVar2;
  double local_10;
  
  if (param_1 == '\x01') {
    *(float *)(this + 0x170) = d_mesg::_5357;
    fVar2 = d_mesg::_5358;
    *(float *)(this + 0x58) = d_mesg::_5358;
    *(float *)(this + 0x20) = fVar2;
    dVar1 = d_mesg::_4147;
    *(float *)(this + 0x90) =
         (float)((double)CONCAT44(0x43300000,(int)d_mesg::messageOffsetY + 0x40U ^ 0x80000000) -
                d_mesg::_4147);
    *(float *)(this + 200) =
         (float)((double)CONCAT44(0x43300000,(int)d_mesg::messageOffsetY + 0x33U ^ 0x80000000) -
                dVar1);
    *(float *)(this + 0x100) =
         (float)((double)CONCAT44(0x43300000,(int)d_mesg::messageOffsetY + 0x42U ^ 0x80000000) -
                dVar1);
    local_10 = (double)CONCAT44(0x43300000,(int)d_mesg::messageOffsetY + 0x35U ^ 0x80000000);
    *(float *)(this + 0x138) = (float)(local_10 - dVar1);
  }
  else {
    if (param_1 == '\x02') {
      *(float *)(this + 0x170) = d_mesg::_5359;
      fVar2 = d_mesg::_5360;
      *(float *)(this + 0x58) = d_mesg::_5360;
      *(float *)(this + 0x20) = fVar2;
      dVar1 = d_mesg::_4147;
      local_10 = (double)CONCAT44(0x43300000,(int)d_mesg::messageOffsetY + 0xb8U ^ 0x80000000);
      *(float *)(this + 0x90) = (float)(local_10 - d_mesg::_4147);
      *(float *)(this + 200) =
           (float)((double)CONCAT44(0x43300000,(int)d_mesg::messageOffsetY + 0xabU ^ 0x80000000) -
                  dVar1);
      *(float *)(this + 0x100) =
           (float)((double)CONCAT44(0x43300000,(int)d_mesg::messageOffsetY + 0xbaU ^ 0x80000000) -
                  dVar1);
      *(float *)(this + 0x138) =
           (float)((double)CONCAT44(0x43300000,(int)d_mesg::messageOffsetY + 0xadU ^ 0x80000000) -
                  dVar1);
    }
    else {
      *(float *)(this + 0x170) = d_mesg::_5361;
      fVar2 = d_mesg::_5362;
      *(float *)(this + 0x58) = d_mesg::_5362;
      *(float *)(this + 0x20) = fVar2;
      dVar1 = d_mesg::_4147;
      local_10 = (double)CONCAT44(0x43300000,(int)d_mesg::messageOffsetY + 0x13eU ^ 0x80000000);
      *(float *)(this + 0x90) = (float)(local_10 - d_mesg::_4147);
      *(float *)(this + 200) =
           (float)((double)CONCAT44(0x43300000,(int)d_mesg::messageOffsetY + 0x131U ^ 0x80000000) -
                  dVar1);
      *(float *)(this + 0x100) =
           (float)((double)CONCAT44(0x43300000,(int)d_mesg::messageOffsetY + 0x140U ^ 0x80000000) -
                  dVar1);
      *(float *)(this + 0x138) =
           (float)((double)CONCAT44(0x43300000,(int)d_mesg::messageOffsetY + 0x133U ^ 0x80000000) -
                  dVar1);
    }
  }
  *(float *)(this + 0x180) = *(float *)(this + 0x170) + *(float *)(this + 400) * d_mesg::_4324;
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x168),(double)d_mesg::_4035,(double)d_mesg::_4035);
  *(float *)(this + 0x68) = *(float *)(this + 0x58) + *(float *)(this + 0x78) * d_mesg::_4324;
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x50),(double)d_mesg::_4035,(double)d_mesg::_4035);
  *(float *)(this + 0x30) = *(float *)(this + 0x20) + *(float *)(this + 0x40) * d_mesg::_4324;
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x18),(double)d_mesg::_4035,(double)d_mesg::_4035);
  *(float *)(this + 0xa0) = *(float *)(this + 0x90) + *(float *)(this + 0xb0) * d_mesg::_4324;
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x88),(double)d_mesg::_4035,(double)d_mesg::_4035);
  *(float *)(this + 0xd8) = *(float *)(this + 200) + *(float *)(this + 0xe8) * d_mesg::_4324;
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0xc0),(double)d_mesg::_4035,(double)d_mesg::_4035);
  *(float *)(this + 0x110) = *(float *)(this + 0x100) + *(float *)(this + 0x120) * d_mesg::_4324;
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0xf8),(double)d_mesg::_4035,(double)d_mesg::_4035);
  *(float *)(this + 0x148) = *(float *)(this + 0x138) + *(float *)(this + 0x158) * d_mesg::_4324;
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x130),(double)d_mesg::_4035,(double)d_mesg::_4035);
  *(int *)(this + 0x1a4) = (int)(*(float *)(this + 0x60) + *(float *)(this + 0x78));
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dMesg_screenDataTalk_c::draw(void) */

void __thiscall dMesg_screenDataTalk_c::draw(dMesg_screenDataTalk_c *this)

{
  J2DOrthoGraph *pCtx;
  int iVar1;
  int iVar2;
  
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x18));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x50));
  iVar1 = 0;
  iVar2 = 0;
  do {
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar2 + 0x88));
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x38;
  } while (iVar1 < 4);
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x168));
  pCtx = d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph;
  (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph)->parent).vtbl)->setPort)
            (d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph);
  J2DScreen::draw(*(J2DScreen **)(this + 0xc),d_mesg::_4035,d_mesg::_4035,&pCtx->parent);
  return;
}


/* __thiscall dMesg_screenDataItem_c::createScreen(void) */

void __thiscall dMesg_screenDataItem_c::createScreen(dMesg_screenDataItem_c *this)

{
  float *pfVar1;
  uint uVar2;
  float fVar3;
  J2DPane *this_00;
  ulong uVar4;
  void *pvVar5;
  J2DScreen *pJVar6;
  int iVar7;
  JPABaseEmitter *pJVar8;
  float *pfVar9;
  float *pfVar10;
  TBox2_float_ local_68;
  cXyz local_58;
  float local_4c;
  ushort local_48;
  undefined4 local_30;
  uint uStack44;
  undefined4 local_28;
  uint uStack36;
  undefined4 local_20;
  uint uStack28;
  undefined4 local_18;
  uint uStack20;
  longlong local_10;
  
  this_00 = (J2DPane *)JKernel::operator_new(0xd4);
  if (this_00 != (J2DPane *)0x0) {
    local_68.mTL.x = d_mesg::_4035;
    local_68.mTL.y = d_mesg::_4035;
    local_68.mBR.x = d_mesg::_5289;
    local_68.mBR.y = d_mesg::_5290;
    J2DPane::J2DPane(this_00,(J2DPane *)0x0,true,0x726f6f74,&local_68);
    this_00->vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
    *(undefined4 *)this_00[1].mMagic = 0xffffffff;
    *(undefined *)&this_00[1].vtbl = 0;
  }
  *(J2DPane **)(this + 0xc) = this_00;
  if (*(int *)(this + 0xc) == 0) {
    uVar4 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar4,"d_mesg.cpp",0x975,"scrn != 0");
    m_Do_printf::OSPanic("d_mesg.cpp",0x975,&DAT_803609f8);
  }
  pvVar5 = JKRHeap::alloc(*(JKRHeap **)(this + 4),0xc00,0x20);
  *(void **)(this + 0x3ec) = pvVar5;
  if (*(int *)(this + 0x3ec) == 0) {
    uVar4 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar4,"d_mesg.cpp",0x978,"texBuffer != 0");
    m_Do_printf::OSPanic("d_mesg.cpp",0x978,&DAT_803609f8);
  }
  *(undefined4 *)(this + 0x3e4) = 0;
  J2DScreen::set(*(J2DScreen **)(this + 0xc),"hukidashi_d09.blo",
                 d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpDmsgArchive);
  pJVar6 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x64743930);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x18),pJVar6);
  pJVar6 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x797a3930);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x50),pJVar6);
  pJVar6 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x74783932);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x88),pJVar6);
  pJVar6 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x74783933);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0xc0),pJVar6);
  pJVar6 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x74783930);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0xf8),pJVar6);
  pJVar6 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x74783931);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x130),pJVar6);
  pJVar6 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x6d733930);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x168),pJVar6);
  pJVar6 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x6974656d);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1b4),pJVar6);
  pJVar6 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x72696e31);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x1ec),pJVar6);
  pJVar6 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x6c696731);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x224),pJVar6);
  pJVar6 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x6c696732);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x25c),pJVar6);
  pJVar6 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x6c696733);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x294),pJVar6);
  pJVar6 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x6c696734);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x2cc),pJVar6);
  pJVar6 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x6c696735);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x304),pJVar6);
  pJVar6 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x6c696736);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x33c),pJVar6);
  pJVar6 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x6c696737);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x374),pJVar6);
  pJVar6 = (J2DScreen *)
           (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x6c696738);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0x3ac),pJVar6);
  if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mConfig._0_1_ == '\0') {
    *(undefined *)(*(int *)(this + 0xc0) + 0xaa) = 1;
    *(undefined *)(*(int *)(this + 0x130) + 0xaa) = 1;
    d_mesg::messageOffsetY = 0;
  }
  else {
    *(undefined *)(*(int *)(this + 0xc0) + 0xaa) = 0;
    *(undefined *)(*(int *)(this + 0x130) + 0xaa) = 0;
    d_mesg::messageOffsetY = -4;
  }
  uVar2 = d_mesg::nowMesgCode;
  iVar7 = JMessage::TControl::getResource_groupID
                    (d_mesg::dMesg_gpControl,(ushort)(d_mesg::nowMesgCode >> 0x10));
  if (iVar7 == 0) {
    iVar7 = 0;
  }
  else {
    iVar7 = *(int *)(iVar7 + 0xc);
    if ((uVar2 & 0xffff) < (uint)*(ushort *)(iVar7 + 8)) {
      iVar7 = iVar7 + (uVar2 & 0xffff) * (uint)*(ushort *)(iVar7 + 10) + 0x10;
    }
    else {
      iVar7 = 0;
    }
  }
  pfVar10 = &local_58.z;
  pfVar9 = (float *)(iVar7 + -4);
  iVar7 = 3;
  do {
    pfVar1 = pfVar9 + 1;
    pfVar9 = pfVar9 + 2;
    fVar3 = *pfVar9;
    pfVar10[1] = *pfVar1;
    pfVar10 = pfVar10 + 2;
    *pfVar10 = fVar3;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  if (dItem_data::item_resource[local_48 - 0x65 & 0xff].mIconFilename != (char *)0x0) {
    JKRArchive::readTypeResource
              (*(void **)(this + 0x3ec),0xc00,0x54494d47,
               dItem_data::item_resource[local_48 - 0x65 & 0xff].mIconFilename,
               d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpItemIconArchive);
    J2DPicture::changeTexture(*(J2DPicture **)(this + 0x1b4),*(ResTIMG **)(this + 0x3ec),'\0');
  }
  *(float *)(this + 0x170) = *(float *)(this + 0x170) + d_mesg::_5168;
  *(float *)(this + 0x180) = *(float *)(this + 0x170) + *(float *)(this + 400) * d_mesg::_4324;
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x168),(double)d_mesg::_4035,(double)d_mesg::_4035);
  *(float *)(this + 0x58) = *(float *)(this + 0x58) + d_mesg::_5168;
  *(float *)(this + 0x68) = *(float *)(this + 0x58) + *(float *)(this + 0x78) * d_mesg::_4324;
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x50),(double)d_mesg::_4035,(double)d_mesg::_4035);
  *(float *)(this + 0x20) = *(float *)(this + 0x20) + d_mesg::_5168;
  *(float *)(this + 0x30) = *(float *)(this + 0x20) + *(float *)(this + 0x40) * d_mesg::_4324;
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x18),(double)d_mesg::_4035,(double)d_mesg::_4035);
  uStack44 = (int)d_mesg::messageOffsetY + 5U ^ 0x80000000;
  local_30 = 0x43300000;
  *(float *)(this + 0x90) =
       *(float *)(this + 0x90) - (float)((double)CONCAT44(0x43300000,uStack44) - d_mesg::_4147);
  *(float *)(this + 0xa0) = *(float *)(this + 0x90) + *(float *)(this + 0xb0) * d_mesg::_4324;
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x88),(double)d_mesg::_4035,(double)d_mesg::_4035);
  uStack36 = (int)d_mesg::messageOffsetY + 8U ^ 0x80000000;
  local_28 = 0x43300000;
  *(float *)(this + 200) =
       *(float *)(this + 200) - (float)((double)CONCAT44(0x43300000,uStack36) - d_mesg::_4147);
  *(float *)(this + 0xd8) = *(float *)(this + 200) + *(float *)(this + 0xe8) * d_mesg::_4324;
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0xc0),(double)d_mesg::_4035,(double)d_mesg::_4035);
  uStack28 = (int)d_mesg::messageOffsetY + 5U ^ 0x80000000;
  local_20 = 0x43300000;
  *(float *)(this + 0x100) =
       *(float *)(this + 0x100) - (float)((double)CONCAT44(0x43300000,uStack28) - d_mesg::_4147);
  *(float *)(this + 0x110) = *(float *)(this + 0x100) + *(float *)(this + 0x120) * d_mesg::_4324;
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0xf8),(double)d_mesg::_4035,(double)d_mesg::_4035);
  uStack20 = (int)d_mesg::messageOffsetY + 8U ^ 0x80000000;
  local_18 = 0x43300000;
  *(float *)(this + 0x138) =
       *(float *)(this + 0x138) - (float)((double)CONCAT44(0x43300000,uStack20) - d_mesg::_4147);
  *(float *)(this + 0x148) = *(float *)(this + 0x138) + *(float *)(this + 0x158) * d_mesg::_4324;
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0x130),(double)d_mesg::_4035,(double)d_mesg::_4035);
  dMesg_screenData_c::setCommonData((dMesg_screenData_c *)this);
  local_10 = (longlong)(int)(*(float *)(this + 0x60) + *(float *)(this + 0x78));
  *(int *)(this + 0x1a4) = (int)(*(float *)(this + 0x60) + *(float *)(this + 0x78));
  if (d_mesg::nowMesgCode == 0x113a) {
    *(undefined *)(*(int *)(this + 0x1b4) + 0xaa) = 0;
  }
  else {
    if (d_mesg::nowMesgCode == 0x7f) {
      local_58.y = ((*(float *)(this + 0x1e4) * d_mesg::_4324 +
                    *(float *)(*(int *)(this + 0x1b4) + 0x20)) - d_mesg::_5475) - d_mesg::_5476;
      local_58.x = d_mesg::_5476 +
                   ((*(float *)(this + 0x1e0) * d_mesg::_4324 +
                    *(float *)(*(int *)(this + 0x1b4) + 0x1c)) - d_mesg::_5477);
      local_58.z = d_mesg::_4035;
      pJVar8 = dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,7,0x2e1,
                                  &local_58,(csXyz *)0x0,(cXyz *)0x0,0xff,(dPa_levelEcallBack *)0x0,
                                  -1,(_GXColor *)0x0,(_GXColor *)0x0,(cXyz *)0x0);
      *(JPABaseEmitter **)(this + 0x3e4) = pJVar8;
    }
  }
  return;
}


/* __thiscall dMesg_screenDataItem_c::changeFont(JUTFont *) */

void __thiscall dMesg_screenDataItem_c::changeFont(dMesg_screenDataItem_c *this,JUTFont *param_1)

{
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x88),param_1);
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0xc0),param_1);
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0xf8),param_1);
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0x130),param_1);
  return;
}


/* __thiscall dMesg_screenDataItem_c::deleteScreen(void) */

void __thiscall dMesg_screenDataItem_c::deleteScreen(dMesg_screenDataItem_c *this)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(this + 0xc);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,1);
  }
  iVar2 = *(int *)(this + 0x3e4);
  if (iVar2 != 0) {
    *(undefined4 *)(iVar2 + 0x60) = 0xffffffff;
    *(uint *)(iVar2 + 0x20c) = *(uint *)(iVar2 + 0x20c) | 1;
    *(uint *)(*(int *)(this + 0x3e4) + 0x20c) =
         *(uint *)(*(int *)(this + 0x3e4) + 0x20c) & 0xffffffbf;
  }
  JKRHeap::free(*(JKRHeap **)(this + 4),*(void **)(this + 0x3ec));
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x801e4ac8) */
/* __thiscall dMesg_screenDataItem_c::openAnime(void) */

undefined4 __thiscall dMesg_screenDataItem_c::openAnime(dMesg_screenDataItem_c *this)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  double dVar5;
  undefined8 in_f31;
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  uVar2 = 0;
  *(short *)(this + 0x1a8) = *(short *)(this + 0x1a8) + 1;
  iVar1 = (int)*(short *)(this + 0x1a8);
  if (iVar1 < 8) {
    if (iVar1 < 6) {
      dVar5 = (double)f_op_msg_mng::fopMsgM_valueIncrease(5,iVar1,0);
      f_op_msg_mng::fopMsgM_paneScaleXY
                ((fopMsgM_pane_class *)(this + 0x168),
                 d_mesg::frameScale_5509 +
                 (float)(dVar5 * (double)(DAT_803609cc - d_mesg::frameScale_5509)));
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x168),(float)dVar5);
    }
    else {
      dVar5 = (double)f_op_msg_mng::fopMsgM_valueIncrease(3,iVar1 + -5,0);
      f_op_msg_mng::fopMsgM_paneScaleXY
                ((fopMsgM_pane_class *)(this + 0x168),
                 DAT_803609cc + (float)(dVar5 * (double)(DAT_803609d0 - DAT_803609cc)));
      f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x168);
    }
  }
  else {
    *(undefined4 *)(this + 0x184) = *(undefined4 *)(this + 0x17c);
    *(undefined4 *)(this + 0x188) = *(undefined4 *)(this + 0x180);
    f_op_msg_mng::fopMsgM_paneScaleXY((fopMsgM_pane_class *)(this + 0x168),d_mesg::_5168);
    f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x168);
    iVar1 = 0;
    iVar3 = 0;
    do {
      f_op_msg_mng::fopMsgM_setInitAlpha(this + iVar3 + 0x88);
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + 0x38;
    } while (iVar1 < 4);
    uVar2 = 1;
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x801e4c18) */
/* WARNING: Removing unreachable block (ram,0x801e4c10) */
/* WARNING: Removing unreachable block (ram,0x801e4c20) */
/* __thiscall dMesg_screenDataItem_c::closeAnime(void) */

bool __thiscall dMesg_screenDataItem_c::closeAnime(dMesg_screenDataItem_c *this)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  double dVar4;
  undefined8 in_f29;
  double dVar5;
  undefined8 in_f30;
  double dVar6;
  undefined8 in_f31;
  double dVar7;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  if (*(short *)(this + 0x1a8) == 0) {
    iVar1 = 0;
    iVar2 = 0;
    do {
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar2 + 0x88));
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x38;
    } while (iVar1 < 4);
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x1b4));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x1ec));
    iVar1 = 0;
    iVar2 = 0;
    do {
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar2 + 0x224));
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x38;
    } while (iVar1 < 8);
  }
  *(short *)(this + 0x1a8) = *(short *)(this + 0x1a8) + 1;
  iVar1 = (int)*(short *)(this + 0x1a8);
  if (iVar1 < 10) {
    dVar7 = (double)*(float *)(this + 0x18c);
    dVar6 = (double)*(float *)(this + 400);
    dVar5 = (double)(float)((double)(d_mesg::_5346 * (float)(dVar6 / dVar7)) - dVar6);
    dVar4 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,iVar1,0);
    *(float *)(this + 0x194) =
         (float)(dVar7 + (double)(float)((double)(float)((double)d_mesg::_5346 - dVar7) * dVar4));
    *(float *)(this + 0x198) = (float)(dVar6 + (double)(float)(dVar5 * dVar4));
    *(float *)(this + 1000) = (float)((double)d_mesg::_5168 - dVar4);
    f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(this + 0x168));
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x168),*(float *)(this + 1000));
  }
  else {
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x168));
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  __psq_l0(auStack24,uVar3);
  __psq_l1(auStack24,uVar3);
  __psq_l0(auStack40,uVar3);
  __psq_l1(auStack40,uVar3);
  return iVar1 >= 10;
}


/* __thiscall dMesg_screenDataItem_c::move(void) */

void __thiscall dMesg_screenDataItem_c::move(dMesg_screenDataItem_c *this)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  ringMove(this);
  lightMove(this);
  cornerMove(this);
  fVar2 = d_mesg::_4035;
  iVar3 = *(int *)(this + 0x3e4);
  if (iVar3 != 0) {
    fVar1 = ((*(float *)(this + 0x1e4) * d_mesg::_4324 + *(float *)(*(int *)(this + 0x1b4) + 0x20))
            - d_mesg::_5475) - d_mesg::_5476;
    *(float *)(iVar3 + 0x1e4) =
         d_mesg::_5476 +
         ((*(float *)(this + 0x1e0) * d_mesg::_4324 + *(float *)(*(int *)(this + 0x1b4) + 0x1c)) -
         d_mesg::_5477);
    *(float *)(iVar3 + 0x1e8) = fVar1;
    *(float *)(iVar3 + 0x1ec) = fVar2;
    *(uint *)(*(int *)(this + 0x3e4) + 0x20c) =
         *(uint *)(*(int *)(this + 0x3e4) + 0x20c) & 0xfffffffb;
    *(dMesg_screenDataItem_c *)(*(int *)(this + 0x3e4) + 0x1ff) = this[0x1e9];
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dMesg_screenDataItem_c::draw(void) */

void __thiscall dMesg_screenDataItem_c::draw(dMesg_screenDataItem_c *this)

{
  J2DOrthoGraph *pCtx;
  dMesg_outFont_c *this_00;
  int iVar1;
  int iVar2;
  
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x18));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x50));
  iVar1 = 0;
  iVar2 = 0;
  do {
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar2 + 0x88));
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x38;
  } while (iVar1 < 4);
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x168));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x1b4));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x1ec));
  iVar1 = 0;
  iVar2 = 0;
  do {
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar2 + 0x224));
    pCtx = d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph;
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x38;
  } while (iVar1 < 8);
  (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph)->parent).vtbl)->setPort)
            (d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph);
  J2DScreen::draw(*(J2DScreen **)(this + 0xc),d_mesg::_4035,d_mesg::_4035,&pCtx->parent);
  iVar1 = 0;
  iVar2 = 0;
  do {
    this_00 = *(dMesg_outFont_c **)(*(int *)(this + 8) + iVar2 + 0x104);
    if ((this_00 != (dMesg_outFont_c *)0x0) && (*(short *)(this_00 + 0x16) != -1)) {
      dMesg_outFont_c::_draw(this_00);
    }
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 4;
  } while (iVar1 < 0x12);
  return;
}


/* __thiscall dMesg_screenDataItem_c::ringMove(void) */

void __thiscall dMesg_screenDataItem_c::ringMove(dMesg_screenDataItem_c *this)

{
  int iVar1;
  double dVar2;
  
  *(short *)(this + 0x222) = *(short *)(this + 0x222) + 1;
  if (0x77 < *(short *)(this + 0x222)) {
    *(undefined2 *)(this + 0x222) = 0;
  }
  iVar1 = (int)*(short *)(this + 0x222);
  if (iVar1 < 0x3c) {
    dVar2 = (double)f_op_msg_mng::fopMsgM_valueIncrease(0x3c,iVar1,0);
  }
  else {
    dVar2 = (double)f_op_msg_mng::fopMsgM_valueIncrease(0x3c,0x78 - iVar1,0);
  }
  if ((this[0x19d] == this[0x19c]) && (*(float *)(this + 0x194) == *(float *)(this + 0x18c))) {
    f_op_msg_mng::fopMsgM_setNowAlpha
              ((fopMsgM_pane_class *)(this + 0x1ec),
               (float)((double)d_mesg::_5629 + (double)(float)((double)d_mesg::_5629 * dVar2)));
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x801e5224) */
/* WARNING: Removing unreachable block (ram,0x801e522c) */
/* __thiscall dMesg_screenDataItem_c::lightMove(void) */

void __thiscall dMesg_screenDataItem_c::lightMove(dMesg_screenDataItem_c *this)

{
  double dVar1;
  float fVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined8 in_f30;
  double dVar7;
  undefined8 in_f31;
  double dVar8;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  *(short *)(this + 0x25a) = *(short *)(this + 0x25a) + 1;
  if (799 < *(short *)(this + 0x25a)) {
    *(undefined2 *)(this + 0x25a) = 0;
  }
  dVar8 = (double)(d_mesg::_5669 *
                  ((float)((double)CONCAT44(0x43300000,(int)*(short *)(this + 0x25a) ^ 0x80000000) -
                          d_mesg::_4147) / d_mesg::_5670));
  piVar3 = *(int **)(this + 0x224);
  piVar3[0x27] = (int)(float)((double)CONCAT44(0x43300000,(int)*(float *)(this + 0x250) ^ 0x80000000
                                              ) - d_mesg::_4147);
  piVar3[0x28] = (int)d_mesg::_4035;
  *(undefined *)(piVar3 + 0x2a) = 0x7a;
  dVar7 = -dVar8;
  piVar3[0x29] = (int)(float)dVar7;
  (**(code **)(*piVar3 + 0x20))();
  fVar2 = d_mesg::_4035;
  piVar3 = *(int **)(this + 0x25c);
  piVar3[0x27] = (int)d_mesg::_4035;
  piVar3[0x28] = (int)fVar2;
  *(undefined *)(piVar3 + 0x2a) = 0x7a;
  piVar3[0x29] = (int)(float)dVar7;
  (**(code **)(*piVar3 + 0x20))();
  dVar1 = (double)CONCAT44(0x43300000,(int)*(float *)(this + 0x2c4) ^ 0x80000000) - d_mesg::_4147;
  piVar3 = *(int **)(this + 0x294);
  piVar3[0x27] = (int)(float)((double)CONCAT44(0x43300000,(int)*(float *)(this + 0x2c0) ^ 0x80000000
                                              ) - d_mesg::_4147);
  piVar3[0x28] = (int)(float)dVar1;
  *(undefined *)(piVar3 + 0x2a) = 0x7a;
  piVar3[0x29] = (int)(float)dVar7;
  (**(code **)(*piVar3 + 0x20))();
  dVar1 = (double)CONCAT44(0x43300000,(int)*(float *)(this + 0x2fc) ^ 0x80000000) - d_mesg::_4147;
  piVar3 = *(int **)(this + 0x2cc);
  piVar3[0x27] = (int)d_mesg::_4035;
  piVar3[0x28] = (int)(float)dVar1;
  *(undefined *)(piVar3 + 0x2a) = 0x7a;
  piVar3[0x29] = (int)(float)dVar7;
  (**(code **)(*piVar3 + 0x20))();
  piVar3 = *(int **)(this + 0x304);
  piVar3[0x27] = (int)(float)((double)CONCAT44(0x43300000,(int)*(float *)(this + 0x330) ^ 0x80000000
                                              ) - d_mesg::_4147);
  piVar3[0x28] = (int)d_mesg::_4035;
  *(undefined *)(piVar3 + 0x2a) = 0x7a;
  piVar3[0x29] = (int)(float)dVar8;
  (**(code **)(*piVar3 + 0x20))();
  fVar2 = d_mesg::_4035;
  piVar3 = *(int **)(this + 0x33c);
  piVar3[0x27] = (int)d_mesg::_4035;
  piVar3[0x28] = (int)fVar2;
  *(undefined *)(piVar3 + 0x2a) = 0x7a;
  piVar3[0x29] = (int)(float)dVar8;
  (**(code **)(*piVar3 + 0x20))();
  dVar1 = (double)CONCAT44(0x43300000,(int)*(float *)(this + 0x3a4) ^ 0x80000000) - d_mesg::_4147;
  piVar3 = *(int **)(this + 0x374);
  piVar3[0x27] = (int)(float)((double)CONCAT44(0x43300000,(int)*(float *)(this + 0x3a0) ^ 0x80000000
                                              ) - d_mesg::_4147);
  piVar3[0x28] = (int)(float)dVar1;
  *(undefined *)(piVar3 + 0x2a) = 0x7a;
  piVar3[0x29] = (int)(float)dVar8;
  (**(code **)(*piVar3 + 0x20))();
  dVar1 = (double)CONCAT44(0x43300000,(int)*(float *)(this + 0x3dc) ^ 0x80000000) - d_mesg::_4147;
  piVar3 = *(int **)(this + 0x3ac);
  piVar3[0x27] = (int)d_mesg::_4035;
  piVar3[0x28] = (int)(float)dVar1;
  *(undefined *)(piVar3 + 0x2a) = 0x7a;
  piVar3[0x29] = (int)(float)dVar8;
  (**(code **)(*piVar3 + 0x20))();
  if ((this[0x19d] == this[0x19c]) && (*(float *)(this + 0x194) == *(float *)(this + 0x18c))) {
    iVar4 = 0;
    iVar5 = 0;
    do {
      f_op_msg_mng::fopMsgM_setInitAlpha(this + iVar5 + 0x224);
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0x38;
    } while (iVar4 < 8);
    f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x1b4);
  }
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  __psq_l0(auStack24,uVar6);
  __psq_l1(auStack24,uVar6);
  return;
}


/* __thiscall dMesg_screenDataItem_c::cornerMove(void) */

void __thiscall dMesg_screenDataItem_c::cornerMove(dMesg_screenDataItem_c *this)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  double dVar6;
  undefined local_f8;
  undefined uStack247;
  undefined uStack246;
  undefined uStack245;
  undefined local_f4;
  undefined uStack243;
  undefined uStack242;
  undefined uStack241;
  undefined local_f0;
  undefined uStack239;
  undefined uStack238;
  undefined uStack237;
  undefined local_ec;
  undefined uStack235;
  undefined uStack234;
  undefined uStack233;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  
  uVar1 = (uint)DAT_803e6bc3;
  *(short *)(this + 0x19e) = *(short *)(this + 0x19e) + 1;
  if ((int)(uVar1 << 2) <= (int)*(short *)(this + 0x19e)) {
    *(undefined2 *)(this + 0x19e) = 0;
  }
  uVar1 = (uint)DAT_803e6bc3;
  dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                            (uVar1,(int)*(short *)(this + 0x19e) -
                                   ((int)*(short *)(this + 0x19e) / (int)uVar1) * uVar1,2);
  iVar3 = 0;
  iVar2 = 0;
  iVar5 = 4;
  do {
    iVar4 = iVar3 + 1;
    if (3 < iVar4) {
      iVar4 = 0;
    }
    *(char *)((int)&local_68 + iVar2) =
         (char)(int)((float)((double)CONCAT44(0x43300000,(uint)(byte)(&d_mesg::cc_r_5691)[iVar3]) -
                            d_mesg::_5225) +
                    (float)(dVar6 * (double)(float)((double)CONCAT44(0x43300000,
                                                                     (uint)(byte)(&d_mesg::cc_r_5691
                                                                                 )[iVar4] -
                                                                     (uint)(byte)(&d_mesg::cc_r_5691
                                                                                 )[iVar3] ^
                                                                     0x80000000) - d_mesg::_4147)));
    *(char *)((int)&local_68 + iVar2 + 1) =
         (char)(int)((float)((double)CONCAT44(0x43300000,(uint)(byte)(&d_mesg::cc_g_5692)[iVar3]) -
                            d_mesg::_5225) +
                    (float)(dVar6 * (double)(float)((double)CONCAT44(0x43300000,
                                                                     (uint)(byte)(&d_mesg::cc_g_5692
                                                                                 )[iVar4] -
                                                                     (uint)(byte)(&d_mesg::cc_g_5692
                                                                                 )[iVar3] ^
                                                                     0x80000000) - d_mesg::_4147)));
    *(char *)((int)&local_68 + iVar2 + 2) =
         (char)(int)((float)((double)CONCAT44(0x43300000,(uint)(byte)(&d_mesg::cc_b_5693)[iVar3]) -
                            d_mesg::_5225) +
                    (float)(dVar6 * (double)(float)((double)CONCAT44(0x43300000,
                                                                     (uint)(byte)(&d_mesg::cc_b_5693
                                                                                 )[iVar4] -
                                                                     (uint)(byte)(&d_mesg::cc_b_5693
                                                                                 )[iVar3] ^
                                                                     0x80000000) - d_mesg::_4147)));
    *(undefined *)((int)&local_68 + iVar2 + 3) = 0xff;
    iVar3 = iVar3 + 1;
    iVar2 = iVar2 + 4;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  iVar2 = (int)*(short *)(this + 0x19e);
  uVar1 = (uint)DAT_803e6bc3;
  uStack233 = (undefined)local_60;
  uStack234 = (undefined)((uint)local_60 >> 8);
  uStack235 = (undefined)((uint)local_60 >> 0x10);
  local_ec = (undefined)((uint)local_60 >> 0x18);
  uStack237 = (undefined)local_5c;
  uStack238 = (undefined)((uint)local_5c >> 8);
  uStack239 = (undefined)((uint)local_5c >> 0x10);
  local_f0 = (undefined)((uint)local_5c >> 0x18);
  uStack241 = (undefined)local_64;
  uStack242 = (undefined)((uint)local_64 >> 8);
  uStack243 = (undefined)((uint)local_64 >> 0x10);
  local_f4 = (undefined)((uint)local_64 >> 0x18);
  uStack245 = (undefined)local_68;
  uStack246 = (undefined)((uint)local_68 >> 8);
  uStack247 = (undefined)((uint)local_68 >> 0x10);
  local_f8 = (undefined)((uint)local_68 >> 0x18);
  if (iVar2 < (int)uVar1) {
    iVar2 = *(int *)(this + 0x168);
    *(undefined *)(iVar2 + 0x10c) = local_f8;
    *(undefined *)(iVar2 + 0x10d) = uStack247;
    *(undefined *)(iVar2 + 0x10e) = uStack246;
    *(undefined *)(iVar2 + 0x10f) = uStack245;
    *(undefined *)(iVar2 + 0x110) = local_f4;
    *(undefined *)(iVar2 + 0x111) = uStack243;
    *(undefined *)(iVar2 + 0x112) = uStack242;
    *(undefined *)(iVar2 + 0x113) = uStack241;
    *(undefined *)(iVar2 + 0x114) = local_f0;
    *(undefined *)(iVar2 + 0x115) = uStack239;
    *(undefined *)(iVar2 + 0x116) = uStack238;
    *(undefined *)(iVar2 + 0x117) = uStack237;
    *(undefined *)(iVar2 + 0x118) = local_ec;
    *(undefined *)(iVar2 + 0x119) = uStack235;
    *(undefined *)(iVar2 + 0x11a) = uStack234;
    *(undefined *)(iVar2 + 0x11b) = uStack233;
  }
  else {
    if (iVar2 < (int)(uVar1 << 1)) {
      iVar2 = *(int *)(this + 0x168);
      *(undefined *)(iVar2 + 0x10c) = local_f4;
      *(undefined *)(iVar2 + 0x10d) = uStack243;
      *(undefined *)(iVar2 + 0x10e) = uStack242;
      *(undefined *)(iVar2 + 0x10f) = uStack241;
      *(undefined *)(iVar2 + 0x110) = local_ec;
      *(undefined *)(iVar2 + 0x111) = uStack235;
      *(undefined *)(iVar2 + 0x112) = uStack234;
      *(undefined *)(iVar2 + 0x113) = uStack233;
      *(undefined *)(iVar2 + 0x114) = local_f8;
      *(undefined *)(iVar2 + 0x115) = uStack247;
      *(undefined *)(iVar2 + 0x116) = uStack246;
      *(undefined *)(iVar2 + 0x117) = uStack245;
      *(undefined *)(iVar2 + 0x118) = local_f0;
      *(undefined *)(iVar2 + 0x119) = uStack239;
      *(undefined *)(iVar2 + 0x11a) = uStack238;
      *(undefined *)(iVar2 + 0x11b) = uStack237;
    }
    else {
      if (iVar2 < (int)(uVar1 * 3)) {
        iVar2 = *(int *)(this + 0x168);
        *(undefined *)(iVar2 + 0x10c) = local_ec;
        *(undefined *)(iVar2 + 0x10d) = uStack235;
        *(undefined *)(iVar2 + 0x10e) = uStack234;
        *(undefined *)(iVar2 + 0x10f) = uStack233;
        *(undefined *)(iVar2 + 0x110) = local_f0;
        *(undefined *)(iVar2 + 0x111) = uStack239;
        *(undefined *)(iVar2 + 0x112) = uStack238;
        *(undefined *)(iVar2 + 0x113) = uStack237;
        *(undefined *)(iVar2 + 0x114) = local_f4;
        *(undefined *)(iVar2 + 0x115) = uStack243;
        *(undefined *)(iVar2 + 0x116) = uStack242;
        *(undefined *)(iVar2 + 0x117) = uStack241;
        *(undefined *)(iVar2 + 0x118) = local_f8;
        *(undefined *)(iVar2 + 0x119) = uStack247;
        *(undefined *)(iVar2 + 0x11a) = uStack246;
        *(undefined *)(iVar2 + 0x11b) = uStack245;
      }
      else {
        iVar2 = *(int *)(this + 0x168);
        *(undefined *)(iVar2 + 0x10c) = local_f0;
        *(undefined *)(iVar2 + 0x10d) = uStack239;
        *(undefined *)(iVar2 + 0x10e) = uStack238;
        *(undefined *)(iVar2 + 0x10f) = uStack237;
        *(undefined *)(iVar2 + 0x110) = local_f8;
        *(undefined *)(iVar2 + 0x111) = uStack247;
        *(undefined *)(iVar2 + 0x112) = uStack246;
        *(undefined *)(iVar2 + 0x113) = uStack245;
        *(undefined *)(iVar2 + 0x114) = local_ec;
        *(undefined *)(iVar2 + 0x115) = uStack235;
        *(undefined *)(iVar2 + 0x116) = uStack234;
        *(undefined *)(iVar2 + 0x117) = uStack233;
        *(undefined *)(iVar2 + 0x118) = local_f4;
        *(undefined *)(iVar2 + 0x119) = uStack243;
        *(undefined *)(iVar2 + 0x11a) = uStack242;
        *(undefined *)(iVar2 + 0x11b) = uStack241;
      }
    }
  }
  return;
}


namespace d_mesg {

/* __stdcall dMesg_initialize(sub_mesg_class *) */

void dMesg_initialize(undefined4 param_1)

{
  TResourceContainer *this;
  ulong uVar1;
  dMesg_tSequenceProcessor *this_00;
  dMesg_tRenderingProcessor *this_01;
  
  this = (TResourceContainer *)JKernel::operator_new(0x18);
  if (this != (TResourceContainer *)0x0) {
    JMessage::TResourceContainer::TResourceContainer(this);
  }
  dMesg_gpResourceContainer = this;
  if (this == (TResourceContainer *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_mesg.cpp",0xb55,"dMesg_gpResourceContainer != 0");
    m_Do_printf::OSPanic("d_mesg.cpp",0xb55,&DAT_803609f8);
  }
  dMesg_gpControl = (TControl *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpDemoMgr)->mpMesgControl;
  this_00 = (dMesg_tSequenceProcessor *)JKernel::operator_new(0x164);
  if (this_00 != (dMesg_tSequenceProcessor *)0x0) {
    ::dMesg_tSequenceProcessor::dMesg_tSequenceProcessor(this_00,dMesg_gpControl);
  }
  dMesg_gpSequenceProcessor = this_00;
  if (this_00 == (dMesg_tSequenceProcessor *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_mesg.cpp",0xb5a,"dMesg_gpSequenceProcessor != 0");
    m_Do_printf::OSPanic("d_mesg.cpp",0xb5a,&DAT_803609f8);
  }
  this_01 = (dMesg_tRenderingProcessor *)JKernel::operator_new(0x34);
  if (this_01 != (dMesg_tRenderingProcessor *)0x0) {
    ::dMesg_tRenderingProcessor::dMesg_tRenderingProcessor(this_01,dMesg_gpControl);
  }
  dMesg_gpRenderingProcessor = this_01;
  if (this_01 == (dMesg_tRenderingProcessor *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_mesg.cpp",0xb5d,"dMesg_gpRenderingProcessor != 0");
    m_Do_printf::OSPanic("d_mesg.cpp",0xb5d,&DAT_803609f8);
  }
  *(TResourceContainer **)(dMesg_gpControl + 4) = dMesg_gpResourceContainer;
  *(dMesg_tSequenceProcessor **)(dMesg_gpControl + 0xc) = dMesg_gpSequenceProcessor;
  *(dMesg_tRenderingProcessor **)(dMesg_gpControl + 0x10) = dMesg_gpRenderingProcessor;
  *(undefined4 *)(dMesg_gpControl + 0x3c) = dMesg_gpFont;
  *(undefined4 *)(dMesg_gpControl + 0x40) = dMesg_gpRFont;
  *(undefined4 *)(dMesg_gpSequenceProcessor + 0x38) = param_1;
  oldMesgCode = 0;
  return;
}


/* __stdcall dMesg_finalize(void) */

void dMesg_finalize(void)

{
  if (dMesg_gpResourceContainer != 0) {
    (**(code **)(*(int *)(dMesg_gpResourceContainer + 0xc) + 8))(dMesg_gpResourceContainer,1);
  }
  if (dMesg_gpSequenceProcessor != (int *)0x0) {
    (**(code **)(*dMesg_gpSequenceProcessor + 0x30))(dMesg_gpSequenceProcessor,1);
  }
  if (dMesg_gpRenderingProcessor != (int *)0x0) {
    (**(code **)(*dMesg_gpRenderingProcessor + 0x30))(dMesg_gpRenderingProcessor,1);
  }
  return;
}

}

/* __thiscall dMesg_tRenderingProcessor::~dMesg_tRenderingProcessor(void) */

void __thiscall
dMesg_tRenderingProcessor::_dMesg_tRenderingProcessor(dMesg_tRenderingProcessor *this)

{
  short in_r4;
  
  if (this != (dMesg_tRenderingProcessor *)0x0) {
    *(undefined1 **)this = &__vt;
    JMessage::TRenderingProcessor::_TRenderingProcessor((TRenderingProcessor *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dMesg_tSequenceProcessor::~dMesg_tSequenceProcessor(void) */

void __thiscall dMesg_tSequenceProcessor::_dMesg_tSequenceProcessor(dMesg_tSequenceProcessor *this)

{
  short in_r4;
  
  if (this != (dMesg_tSequenceProcessor *)0x0) {
    *(undefined1 **)this = &__vt;
    JMessage::TSequenceProcessor::_TSequenceProcessor((TSequenceProcessor *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


namespace JMessage {

/* __thiscall TResourceContainer::~TResourceContainer(void) */

void __thiscall TResourceContainer::_TResourceContainer(TResourceContainer *this)

{
  bool bVar1;
  short in_r4;
  
  bVar1 = this != (TResourceContainer *)0x0;
  if (bVar1) {
    *(undefined1 **)(this + 0xc) = &__vt;
    if ((bVar1) &&
       (*(undefined1 **)(this + 0xc) = &JGadget::TLinkList_factory<TResource,0>::__vt,
       bVar1)) {
      JGadget::TNodeLinkList::_TNodeLinkList((TNodeLinkList *)this);
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}

}

namespace d_mesg {

/* __stdcall dMesg_parse(void) */

undefined4 dMesg_parse(void)

{
  ulong uVar1;
  TParse_header_block *this;
  void *local_8;
  void *local_4;
  
  headerFlag = 0;
  header = (void *)JKRArchive::getGlbResource
                             (0x524f4f54,"zel_00.bmg",
                              d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpEnglishTextArchive);
  if (header == (void *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_mesg.cpp",0xb8c,"header != 0");
    m_Do_printf::OSPanic("d_mesg.cpp",0xb8c,&DAT_803609f8);
  }
  header2 = (void *)JKRArchive::getGlbResource
                              (0x524f4f54,"zel_01.bmg",
                               d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpHyruleTextArchive);
  if (header2 == (void *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_mesg.cpp",0xb91,"header2 != 0");
    m_Do_printf::OSPanic("d_mesg.cpp",0xb91,&DAT_803609f8);
  }
  this = (TParse_header_block *)JKernel::operator_new(0xc);
  if (this != (TParse_header_block *)0x0) {
    JMessage::TParse::TParse((TParse *)this,dMesg_gpResourceContainer);
  }
  oParse = this;
  if (this == (TParse_header_block *)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_mesg.cpp",0xb94,"oParse != 0");
    m_Do_printf::OSPanic("d_mesg.cpp",0xb94,&DAT_803609f8);
  }
  local_4 = header;
  JGadget::binary::TParse_header_block::parse_next(oParse,&local_4,0);
  local_8 = header2;
  JGadget::binary::TParse_header_block::parse_next(oParse,&local_8,0);
  return 1;
}


/* __stdcall dMesg_reset(void) */

void dMesg_reset(void)

{
  JMessage::TControl::reset(dMesg_gpControl);
  return;
}


/* __stdcall dMesg_update(void) */

void dMesg_update(void)

{
  dMesg_gbUpdate = JMessage::TControl::update(dMesg_gpControl);
  return;
}


/* __stdcall dMesg_render(void) */

void dMesg_render(void)

{
  JMessage::TControl::render(dMesg_gpControl);
  return;
}


/* __stdcall dMesg_fontsizeCenter(sub_mesg_class *,
                                  int,
                                  int) */

void dMesg_fontsizeCenter(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  char local_38 [12];
  char acStack44 [40];
  
  uVar1 = param_3 - param_2;
  iVar2 = ((int)uVar1 >> 1) + (uint)((int)uVar1 < 0 && (uVar1 & 1) != 0);
  if (iVar2 < 1) {
    if (iVar2 < 0) {
      MSL_C.PPCEABI.bare.H::sprintf(acStack44,"\x1bFX[%d]\x1bFY[%d]",param_3,param_3);
      local_38[0] = '\0';
      MSL_C.PPCEABI.bare.H::strcat(*(char **)(param_1 + 0x154),acStack44);
      MSL_C.PPCEABI.bare.H::strcat(*(char **)(param_1 + 0x158),local_38);
      MSL_C.PPCEABI.bare.H::strcat(*(char **)(param_1 + 0x15c),acStack44);
      MSL_C.PPCEABI.bare.H::strcat(*(char **)(param_1 + 0x160),local_38);
    }
    else {
      if (param_2 != param_3) {
        MSL_C.PPCEABI.bare.H::sprintf(acStack44,"\x1bFX[%d]\x1bFY[%d]",param_3,param_3);
        MSL_C.PPCEABI.bare.H::strcat(*(char **)(param_1 + 0x154),acStack44);
        MSL_C.PPCEABI.bare.H::strcat(*(char **)(param_1 + 0x15c),acStack44);
      }
    }
  }
  else {
    MSL_C.PPCEABI.bare.H::sprintf(acStack44,"\x1bFX[%d]\x1bFY[%d]",param_3,param_3);
    local_38[0] = '\0';
    MSL_C.PPCEABI.bare.H::strcat(*(char **)(param_1 + 0x154),acStack44);
    MSL_C.PPCEABI.bare.H::strcat(*(char **)(param_1 + 0x158),local_38);
    MSL_C.PPCEABI.bare.H::strcat(*(char **)(param_1 + 0x15c),acStack44);
    MSL_C.PPCEABI.bare.H::strcat(*(char **)(param_1 + 0x160),local_38);
  }
  return;
}


/* __stdcall dMesg_hyrule_language_check(unsigned long) */

undefined4 dMesg_hyrule_language_check(int param_1)

{
  TControl *this;
  
  this = dMesg_gpControl;
  if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mInfo.mNumGamesCompleted != 0) {
    return 0;
  }
  if (param_1 != 0x3b0) {
    if (param_1 < 0x3b0) {
      if (param_1 == 0x3a9) {
        *(undefined2 *)(dMesg_gpControl + 0x14) = 1;
        *(undefined2 *)(this + 0x16) = 3;
        JMessage::TControl::setMessageCode_flush_(this);
        return 1;
      }
      if (param_1 < 0x3a9) {
        if (param_1 == 0x3a5) {
          *(undefined2 *)(dMesg_gpControl + 0x14) = 1;
          *(undefined2 *)(this + 0x16) = 1;
          JMessage::TControl::setMessageCode_flush_(this);
          return 1;
        }
        if (param_1 < 0x3a5) {
          if (param_1 == 0x3a3) {
            *(undefined2 *)(dMesg_gpControl + 0x14) = 1;
            *(undefined2 *)(this + 0x16) = 0;
            JMessage::TControl::setMessageCode_flush_(this);
            return 1;
          }
        }
        else {
          if (param_1 == 0x3a7) {
            *(undefined2 *)(dMesg_gpControl + 0x14) = 1;
            *(undefined2 *)(this + 0x16) = 2;
            JMessage::TControl::setMessageCode_flush_(this);
            return 1;
          }
        }
      }
      else {
        if (param_1 == 0x3ad) {
          *(undefined2 *)(dMesg_gpControl + 0x14) = 1;
          *(undefined2 *)(this + 0x16) = 5;
          JMessage::TControl::setMessageCode_flush_(this);
          return 1;
        }
        if (0x3ac < param_1) {
          if (param_1 < 0x3af) {
            *(undefined2 *)(dMesg_gpControl + 0x14) = 1;
            *(undefined2 *)(this + 0x16) = 6;
            JMessage::TControl::setMessageCode_flush_(this);
            return 1;
          }
          *(undefined2 *)(dMesg_gpControl + 0x14) = 1;
          *(undefined2 *)(this + 0x16) = 7;
          JMessage::TControl::setMessageCode_flush_(this);
          return 1;
        }
        if (param_1 == 0x3ab) {
          *(undefined2 *)(dMesg_gpControl + 0x14) = 1;
          *(undefined2 *)(this + 0x16) = 4;
          JMessage::TControl::setMessageCode_flush_(this);
          return 1;
        }
      }
    }
    else {
      if (param_1 == 0x4ea) {
        *(undefined2 *)(dMesg_gpControl + 0x14) = 1;
        *(undefined2 *)(this + 0x16) = 0xb;
        JMessage::TControl::setMessageCode_flush_(this);
        return 1;
      }
      if (param_1 < 0x4ea) {
        if (param_1 == 0x3b3) {
          *(undefined2 *)(dMesg_gpControl + 0x14) = 1;
          *(undefined2 *)(this + 0x16) = 9;
          JMessage::TControl::setMessageCode_flush_(this);
          return 1;
        }
        if (param_1 < 0x3b3) {
          if (param_1 < 0x3b2) {
            *(undefined2 *)(dMesg_gpControl + 0x14) = 1;
            *(undefined2 *)(this + 0x16) = 8;
            JMessage::TControl::setMessageCode_flush_(this);
            return 1;
          }
        }
        else {
          if (param_1 == 0x4e8) {
            *(undefined2 *)(dMesg_gpControl + 0x14) = 1;
            *(undefined2 *)(this + 0x16) = 10;
            JMessage::TControl::setMessageCode_flush_(this);
            return 1;
          }
        }
      }
      else {
        if (param_1 == 0x501) {
          *(undefined2 *)(dMesg_gpControl + 0x14) = 1;
          *(undefined2 *)(this + 0x16) = 0xd;
          JMessage::TControl::setMessageCode_flush_(this);
          return 1;
        }
        if (param_1 < 0x501) {
          if (0x4ff < param_1) {
            *(undefined2 *)(dMesg_gpControl + 0x14) = 1;
            *(undefined2 *)(this + 0x16) = 0xc;
            JMessage::TControl::setMessageCode_flush_(this);
            return 1;
          }
        }
        else {
          if (param_1 == 0x70a) {
            *(undefined2 *)(dMesg_gpControl + 0x14) = 1;
            *(undefined2 *)(this + 0x16) = 0xe;
            JMessage::TControl::setMessageCode_flush_(this);
            return 1;
          }
        }
      }
    }
  }
  return 0;
}


/* __stdcall dMesg_fontsizeCenter(sub_mesg_class *,
                                  int,
                                  int,
                                  int,
                                  int) */

void dMesg_fontsizeCenter(int param_1,undefined4 param_2,undefined4 param_3)

{
  char local_38 [12];
  char acStack44 [40];
  
  MSL_C.PPCEABI.bare.H::sprintf(acStack44,"\x1bFX[%d]\x1bFY[%d]",param_3,param_3);
  local_38[0] = '\0';
  MSL_C.PPCEABI.bare.H::strcat(*(char **)(param_1 + 0x154),acStack44);
  MSL_C.PPCEABI.bare.H::strcat(*(char **)(param_1 + 0x158),local_38);
  MSL_C.PPCEABI.bare.H::strcat(*(char **)(param_1 + 0x15c),acStack44);
  MSL_C.PPCEABI.bare.H::strcat(*(char **)(param_1 + 0x160),local_38);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __stdcall dMesg_waitProc(sub_mesg_class *) */

void dMesg_waitProc(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 uVar3;
  char cVar10;
  JKRExpHeap *pJVar4;
  undefined4 uVar5;
  void *pvVar6;
  ulong uVar7;
  int *piVar8;
  undefined **ppuVar9;
  undefined4 *puVar11;
  undefined4 *puVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  undefined4 uStack60;
  undefined4 local_38 [3];
  char local_2c;
  undefined local_2a;
  
  nowMesgCode = *(uint *)(dMesg_gpControl + 0x14);
  zenkaku = 0;
  zenkakuCode = 0;
  if (oldMesgCode != nowMesgCode) {
    cVar10 = dMesg_hyrule_language_check(*(undefined4 *)(dMesg_gpControl + 0x14));
    if (cVar10 == '\0') {
      if (headerFlag != '\0') {
        *(undefined4 *)(dMesg_gpControl + 0x3c) = dMesg_gpFont;
        headerFlag = '\0';
      }
    }
    else {
      nowMesgCode = *(uint *)(dMesg_gpControl + 0x14);
      if (headerFlag == '\0') {
        *(undefined4 *)(dMesg_gpControl + 0x3c) = dMesg_gpRFont;
        headerFlag = '\x01';
      }
    }
    pJVar4 = JKRExpHeap::create(0xa32d,*(JKRHeap **)(param_1 + 0xfc),false);
    *(JKRExpHeap **)(param_1 + 0x100) = pJVar4;
    uVar5 = m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0x100));
    iVar13 = 0;
    iVar15 = 0;
    do {
      iVar14 = iVar15 + 0x154;
      if (*(int *)(param_1 + iVar14) == 0) {
        pvVar6 = JKRHeap::alloc(*(JKRHeap **)(param_1 + 0x100),0x3e9,4);
        *(void **)(param_1 + iVar14) = pvVar6;
        if (*(int *)(param_1 + iVar14) == 0) {
          uVar7 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar7,"d_mesg.cpp",0xce8,"i_Msg->text[i] != 0");
          m_Do_printf::OSPanic("d_mesg.cpp",0xce8,&DAT_803609f8);
        }
      }
      uVar2 = nowMesgCode;
      iVar13 = iVar13 + 1;
      iVar15 = iVar15 + 4;
    } while (iVar13 < 4);
    piVar8 = *(int **)(param_1 + 0x14c);
    if (piVar8 == (int *)0x0) {
      iVar13 = JMessage::TControl::getResource_groupID
                         (dMesg_gpControl,(ushort)(nowMesgCode >> 0x10));
      if (iVar13 == 0) {
        iVar13 = 0;
      }
      else {
        iVar13 = *(int *)(iVar13 + 0xc);
        if ((uVar2 & 0xffff) < (uint)*(ushort *)(iVar13 + 8)) {
          iVar13 = iVar13 + (uVar2 & 0xffff) * (uint)*(ushort *)(iVar13 + 10) + 0x10;
        }
        else {
          iVar13 = 0;
        }
      }
      puVar12 = &uStack60;
      puVar11 = (undefined4 *)(iVar13 + -4);
      iVar13 = 3;
      do {
        puVar1 = puVar11 + 1;
        puVar11 = puVar11 + 2;
        uVar3 = *puVar11;
        puVar12[1] = *puVar1;
        puVar12 = puVar12 + 2;
        *puVar12 = uVar3;
        iVar13 = iVar13 + -1;
      } while (iVar13 != 0);
      if (local_2c == '\t') {
        ppuVar9 = (undefined **)JKernel::operator_new(0x3f0);
        if (ppuVar9 != (undefined **)0x0) {
          *ppuVar9 = (undefined *)&dDlst_base_c::__vt;
          *ppuVar9 = &::dMesg_screenData_c::__vt;
          ppuVar9[0x6b] = (undefined *)0xffffffff;
          ppuVar9[0x6c] = (undefined *)0xffffffff;
          *ppuVar9 = &::dMesg_screenDataItem_c::__vt;
        }
        *(undefined ***)(param_1 + 0x14c) = ppuVar9;
      }
      else {
        ppuVar9 = (undefined **)JKernel::operator_new(0x1b8);
        if (ppuVar9 != (undefined **)0x0) {
          *ppuVar9 = (undefined *)&dDlst_base_c::__vt;
          *ppuVar9 = &::dMesg_screenData_c::__vt;
          ppuVar9[0x6b] = (undefined *)0xffffffff;
          ppuVar9[0x6c] = (undefined *)0xffffffff;
          *ppuVar9 = &::dMesg_screenDataTalk_c::__vt;
        }
        *(undefined ***)(param_1 + 0x14c) = ppuVar9;
      }
      if (*(int *)(param_1 + 0x14c) == 0) {
        uVar7 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar7,"d_mesg.cpp",0xcf5,"i_Msg->screen != 0");
        m_Do_printf::OSPanic("d_mesg.cpp",0xcf5,&DAT_803609f8);
      }
      *(int *)(*(int *)(param_1 + 0x14c) + 8) = param_1;
      *(undefined4 *)(*(int *)(param_1 + 0x14c) + 4) = *(undefined4 *)(param_1 + 0x100);
      uVar3 = dMesg_gpRFont;
      if (headerFlag == '\0') {
        iVar13 = *(int *)(param_1 + 0x14c);
        *(undefined4 *)(iVar13 + 0x10) = dMesg_gpFont;
        *(undefined4 *)(iVar13 + 0x14) = uVar3;
      }
      else {
        iVar13 = *(int *)(param_1 + 0x14c);
        *(undefined4 *)(iVar13 + 0x10) = dMesg_gpRFont;
        *(undefined4 *)(iVar13 + 0x14) = uVar3;
      }
      (**(code **)(**(int **)(param_1 + 0x14c) + 0x10))();
      (**(code **)(**(int **)(param_1 + 0x14c) + 0x24))(*(int **)(param_1 + 0x14c),local_2a);
      dMesg_gbUpdate = 1;
      *(undefined *)(param_1 + 0x164) = 2;
      *(undefined4 *)(dMesg_gpSequenceProcessor + 0x6c) = 0xffffffff;
      JAIZelBasic::talkIn(JAIZelBasic::zel_basic);
      JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x80c,(cXyz *)0x0,0,0,_5168,_5168,_6382,_6382,0);
    }
    else {
      if (headerFlag == '\0') {
        (**(code **)(*piVar8 + 0x14))(piVar8,dMesg_gpFont);
      }
      else {
        (**(code **)(*piVar8 + 0x14))(piVar8,dMesg_gpRFont);
      }
    }
    iVar13 = 0;
    iVar15 = 0;
    do {
      iVar14 = iVar15 + 0x104;
      if (*(int *)(param_1 + iVar14) == 0) {
        puVar11 = (undefined4 *)JKernel::operator_new(0x1c);
        if (puVar11 != (undefined4 *)0x0) {
          *puVar11 = &::dMesg_outFont_c::__vt;
        }
        *(undefined4 **)(param_1 + iVar14) = puVar11;
        if (*(int *)(param_1 + iVar14) == 0) {
          uVar7 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar7,"d_mesg.cpp",0xd20,"i_Msg->outfont[i]");
          m_Do_printf::OSPanic("d_mesg.cpp",0xd20,&DAT_803609f8);
        }
        ::dMesg_outFont_c::_create(*(dMesg_outFont_c **)(param_1 + iVar14));
      }
      iVar13 = iVar13 + 1;
      iVar15 = iVar15 + 4;
    } while (iVar13 < 0x12);
    oldMesgCode = nowMesgCode;
    m_Do_ext::mDoExt_setCurrentHeap(uVar5);
  }
  return;
}

}

/* __thiscall dMesg_screenData_c::changeFont(JUTFont *) */

void __thiscall dMesg_screenData_c::changeFont(dMesg_screenData_c *this,JUTFont *param_1)

{
  return;
}


/* __thiscall dMesg_screenData_c::setTextPosition(unsigned char) */

void __thiscall dMesg_screenData_c::setTextPosition(dMesg_screenData_c *this,uchar param_1)

{
  return;
}


/* __thiscall dMesg_screenData_c::createScreen(void) */

void __thiscall dMesg_screenData_c::createScreen(dMesg_screenData_c *this)

{
  return;
}


/* __thiscall dMesg_screenData_c::~dMesg_screenData_c(void) */

void __thiscall dMesg_screenData_c::_dMesg_screenData_c(dMesg_screenData_c *this)

{
  short in_r4;
  
  if (this != (dMesg_screenData_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dMesg_screenData_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


namespace d_mesg {

/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __stdcall dMesg_openProc(sub_mesg_class *) */

void dMesg_openProc(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char cVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  undefined4 uStack60;
  undefined4 local_38 [4];
  byte local_27;
  
  uVar4 = m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0x100));
  cVar5 = (**(code **)(**(int **)(param_1 + 0x14c) + 0x1c))();
  if (cVar5 != '\0') {
    iVar8 = 0;
    iVar9 = 0;
    do {
      ::dMesg_screenData_c::initString
                (*(dMesg_screenData_c **)(param_1 + 0x14c),*(char **)(param_1 + iVar9 + 0x154),iVar8
                );
      ::dMesg_screenData_c::setString
                (*(dMesg_screenData_c **)(param_1 + 0x14c),*(char **)(param_1 + iVar9 + 0x154),iVar8
                );
      iVar8 = iVar8 + 1;
      iVar9 = iVar9 + 4;
    } while (iVar8 < 4);
    *(undefined *)(param_1 + 0x164) = 6;
    uVar2 = nowMesgCode;
    iVar8 = JMessage::TControl::getResource_groupID(dMesg_gpControl,(ushort)(nowMesgCode >> 0x10));
    if (iVar8 == 0) {
      iVar8 = 0;
    }
    else {
      iVar8 = *(int *)(iVar8 + 0xc);
      if ((uVar2 & 0xffff) < (uint)*(ushort *)(iVar8 + 8)) {
        iVar8 = iVar8 + (uVar2 & 0xffff) * (uint)*(ushort *)(iVar8 + 10) + 0x10;
      }
      else {
        iVar8 = 0;
      }
    }
    puVar7 = &uStack60;
    puVar6 = (undefined4 *)(iVar8 + -4);
    iVar8 = 3;
    do {
      puVar1 = puVar6 + 1;
      puVar6 = puVar6 + 2;
      uVar3 = *puVar6;
      puVar7[1] = *puVar1;
      puVar7 = puVar7 + 2;
      *puVar7 = uVar3;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
    if (local_27 != 0) {
      cVar5 = d_com_inf_game::dComIfGp_getReverb((int)(char)dStage_roomControl_c::mStayNo);
      JAIZelBasic::messageSePlay(JAIZelBasic::zel_basic,(ushort)local_27,(Vec *)0x0,cVar5);
    }
  }
  m_Do_ext::mDoExt_setCurrentHeap(uVar4);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall dMesg_outnowProc(sub_mesg_class *) */

void dMesg_outnowProc(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0x100));
  dMesg_update();
  dMesg_render();
  iVar2 = 0;
  iVar3 = 0;
  do {
    ::dMesg_screenData_c::setString
              (*(dMesg_screenData_c **)(param_1 + 0x14c),*(char **)(param_1 + iVar3 + 0x154),iVar2);
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + 4;
  } while (iVar2 < 4);
  if (*(char *)(dMesg_gpSequenceProcessor + 0x15f) == '\x01') {
    ::dMesg_screenData_c::arwAnimeInit(*(dMesg_screenData_c **)(param_1 + 0x14c));
    *(undefined *)(param_1 + 0x164) = 5;
  }
  else {
    if (*(char *)(dMesg_gpSequenceProcessor + 0x15f) == '\x02') {
      *(undefined *)(param_1 + 0x164) = 7;
    }
    else {
      if (dMesg_gbUpdate == '\0') {
        ::dMesg_screenData_c::dotAnimeInit(*(dMesg_screenData_c **)(param_1 + 0x14c));
        *(undefined *)(param_1 + 0x164) = 10;
      }
    }
  }
  m_Do_ext::mDoExt_setCurrentHeap(uVar1);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __stdcall dMesg_outwaitProc(sub_mesg_class *) */

void dMesg_outwaitProc(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0x100));
  if (((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) == 0) &&
     (-1 < (char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3)) {
    ::dMesg_screenData_c::arwAnime(*(dMesg_screenData_c **)(param_1 + 0x14c));
  }
  else {
    iVar2 = 0;
    iVar3 = 0;
    do {
      ::dMesg_screenData_c::initString
                (*(dMesg_screenData_c **)(param_1 + 0x14c),*(char **)(param_1 + iVar3 + 0x154),iVar2
                );
      ::dMesg_screenData_c::setString
                (*(dMesg_screenData_c **)(param_1 + 0x14c),*(char **)(param_1 + iVar3 + 0x154),iVar2
                );
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 4;
    } while (iVar2 < 4);
    ::dMesg_screenData_c::arwAnimeInit(*(dMesg_screenData_c **)(param_1 + 0x14c));
    ::dMesg_tSequenceProcessor::initialize
              (dMesg_gpSequenceProcessor,*(int *)(dMesg_gpControl + 0x58));
    if ((char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 < '\0') {
      dMesg_gpSequenceProcessor[0x161] = (dMesg_tSequenceProcessor)0x1;
    }
    iVar2 = 0;
    iVar3 = 0;
    do {
      ::dMesg_outFont_c::_initialize(*(dMesg_outFont_c **)(param_1 + iVar3 + 0x104));
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 4;
    } while (iVar2 < 0x12);
    *(undefined *)(param_1 + 0x164) = 6;
    JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x80b,(cXyz *)0x0,0,0,_5168,_5168,_6382,_6382,0);
  }
  m_Do_ext::mDoExt_setCurrentHeap(uVar1);
  return;
}


/* __stdcall dMesg_stopProc(sub_mesg_class *) */

void dMesg_stopProc(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0x100));
  iVar2 = *(int *)(dMesg_gpSequenceProcessor + 0x90);
  if (iVar2 < 1) {
    iVar2 = 0;
  }
  else {
    *(int *)(dMesg_gpSequenceProcessor + 0x90) = iVar2 + -1;
  }
  if (iVar2 == 0) {
    *(undefined *)(param_1 + 0x164) = 0x12;
    JAIZelBasic::talkOut(JAIZelBasic::zel_basic);
    JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x80d,(cXyz *)0x0,0,0,_5168,_5168,_6382,_6382,0);
  }
  m_Do_ext::mDoExt_setCurrentHeap(uVar1);
  return;
}


/* __stdcall dMesg_closewaitProc(sub_mesg_class *) */

void dMesg_closewaitProc(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0x100));
  if (((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) == 0) &&
     (-1 < (char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3)) {
    ::dMesg_screenData_c::dotAnime(*(dMesg_screenData_c **)(param_1 + 0x14c));
  }
  else {
    ::dMesg_screenData_c::dotAnimeInit(*(dMesg_screenData_c **)(param_1 + 0x14c));
    *(undefined *)(param_1 + 0x164) = 0x12;
    JAIZelBasic::talkOut(JAIZelBasic::zel_basic);
    JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x80d,(cXyz *)0x0,0,0,_5168,_5168,_6382,_6382,0);
  }
  m_Do_ext::mDoExt_setCurrentHeap(uVar1);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __stdcall dMesg_closeProc(sub_mesg_class *) */

void dMesg_closeProc(int param_1)

{
  undefined4 uVar1;
  char cVar3;
  int *piVar2;
  dMesg_outFont_c *this;
  int iVar4;
  int iVar5;
  int iVar6;
  
  uVar1 = m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0x100));
  cVar3 = (**(code **)(**(int **)(param_1 + 0x14c) + 0x20))();
  if (cVar3 == '\0') {
    iVar4 = 0;
    iVar6 = 0;
    do {
      this = *(dMesg_outFont_c **)(param_1 + iVar6 + 0x104);
      if (this != (dMesg_outFont_c *)0x0) {
        ::dMesg_outFont_c::_setAlpha(this,'\0');
      }
      iVar4 = iVar4 + 1;
      iVar6 = iVar6 + 4;
    } while (iVar4 < 0x12);
    m_Do_ext::mDoExt_setCurrentHeap(uVar1);
  }
  else {
    piVar2 = *(int **)(*(int *)(param_1 + 0x14c) + 0xc);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2,1);
    }
    (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpDmsgArchive)->parent).parent.vtbl)->
              removeResourceAll)();
    JKernel::operator_delete(*(JKRHeap **)(param_1 + 0x14c));
    *(undefined4 *)(param_1 + 0x14c) = 0;
    dMesg_reset();
    iVar4 = 0;
    iVar6 = 0;
    do {
      iVar5 = iVar6 + 0x104;
      if (*(dMesg_outFont_c **)(param_1 + iVar5) != (dMesg_outFont_c *)0x0) {
        ::dMesg_outFont_c::_delete(*(dMesg_outFont_c **)(param_1 + iVar5));
        JKernel::operator_delete(*(JKRHeap **)(param_1 + iVar5));
        *(undefined4 *)(param_1 + iVar5) = 0;
      }
      iVar4 = iVar4 + 1;
      iVar6 = iVar6 + 4;
    } while (iVar4 < 0x12);
    iVar4 = 0;
    iVar6 = 0;
    do {
      JKRHeap::free(*(JKRHeap **)(param_1 + 0x100),*(void **)(param_1 + iVar6 + 0x154));
      *(undefined4 *)(param_1 + iVar6 + 0x154) = 0;
      iVar4 = iVar4 + 1;
      iVar6 = iVar6 + 4;
    } while (iVar4 < 4);
    m_Do_ext::mDoExt_setCurrentHeap(uVar1);
    JKRHeap::freeAll(*(JKRHeap **)(param_1 + 0x100));
    JKRHeap::destroy(*(JKRHeap **)(param_1 + 0x100));
    *(undefined4 *)(param_1 + 0x100) = 0;
    *(undefined *)(param_1 + 0x164) = 0;
    *(int *)&(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpDemoMgr)->mpControl->field_0x40 =
         *(int *)&(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpDemoMgr)->mpControl->field_0x40 + -1;
  }
  return;
}


/* __stdcall dMsg_Draw(sub_mesg_class *) */

undefined4 dMsg_Draw(int param_1)

{
  if (*(dDlst_base_c **)(param_1 + 0x14c) != (dDlst_base_c *)0x0) {
    dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                      &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                      &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                      *(dDlst_base_c **)(param_1 + 0x14c));
  }
  return 1;
}


/* __stdcall dMsg_Execute(sub_mesg_class *) */

undefined4 dMsg_Execute(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0xfc));
  cVar1 = *(char *)(param_1 + 0x164);
  if (cVar1 == '\0') {
    dMesg_waitProc(param_1);
  }
  else {
    if (cVar1 == '\x02') {
      dMesg_openProc(param_1);
    }
    else {
      if (cVar1 == '\x06') {
        dMesg_outnowProc(param_1);
      }
      else {
        if (cVar1 == '\x05') {
          dMesg_outwaitProc(param_1);
        }
        else {
          if (cVar1 == '\a') {
            dMesg_stopProc(param_1);
          }
          else {
            if (cVar1 == '\n') {
              dMesg_closewaitProc(param_1);
            }
            else {
              if (cVar1 == '\x12') {
                dMesg_closeProc(param_1);
              }
            }
          }
        }
      }
    }
  }
  if (*(int **)(param_1 + 0x14c) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x14c) + 0x18))();
  }
  m_Do_ext::mDoExt_setCurrentHeap(uVar2);
  return 1;
}

}

/* __thiscall dMesg_screenData_c::move(void) */

void __thiscall dMesg_screenData_c::move(dMesg_screenData_c *this)

{
  return;
}


namespace d_mesg {

/* __stdcall dMsg_IsDelete(sub_mesg_class *) */

undefined4 dMsg_IsDelete(void)

{
  return 1;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __stdcall dMsg_Delete(sub_mesg_class *) */

undefined4 dMsg_Delete(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  TNodeLinkList aTStack48 [4];
  int local_2c;
  int local_28;
  int local_24;
  
  uVar1 = m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0xfc));
  m_Do_ext::mDoExt_removeMesgFont();
  m_Do_ext::mDoExt_removeRubyFont();
  piVar2 = dMesg_gpResourceContainer;
  if (*(int *)(param_1 + 0x100) != 0) {
    m_Do_ext::mDoExt_setCurrentHeap();
    if (*(int *)(param_1 + 0x14c) != 0) {
      piVar2 = *(int **)(*(int *)(param_1 + 0x14c) + 0xc);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2,1);
      }
      (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpDmsgArchive)->parent).parent.vtbl)->
                removeResourceAll)();
      JKernel::operator_delete(*(JKRHeap **)(param_1 + 0x14c));
      *(undefined4 *)(param_1 + 0x14c) = 0;
    }
    iVar3 = 0;
    iVar5 = 0;
    do {
      iVar4 = iVar5 + 0x104;
      if (*(dMesg_outFont_c **)(param_1 + iVar4) != (dMesg_outFont_c *)0x0) {
        ::dMesg_outFont_c::_delete(*(dMesg_outFont_c **)(param_1 + iVar4));
        JKernel::operator_delete(*(JKRHeap **)(param_1 + iVar4));
        *(undefined4 *)(param_1 + iVar4) = 0;
      }
      iVar3 = iVar3 + 1;
      iVar5 = iVar5 + 4;
    } while (iVar3 < 0x12);
    iVar3 = 0;
    iVar5 = 0;
    do {
      JKRHeap::free(*(JKRHeap **)(param_1 + 0x100),*(void **)(param_1 + iVar5 + 0x154));
      *(undefined4 *)(param_1 + iVar5 + 0x154) = 0;
      iVar3 = iVar3 + 1;
      iVar5 = iVar5 + 4;
    } while (iVar3 < 4);
    piVar2 = dMesg_gpResourceContainer;
    if (*(JKRHeap **)(param_1 + 0x100) != (JKRHeap *)0x0) {
      JKRHeap::freeAll(*(JKRHeap **)(param_1 + 0x100));
      JKRHeap::destroy(*(JKRHeap **)(param_1 + 0x100));
      *(undefined4 *)(param_1 + 0x100) = 0;
      piVar2 = dMesg_gpResourceContainer;
    }
  }
  while (*piVar2 != 0) {
    iVar3 = piVar2[1];
    local_2c = iVar3;
    local_28 = iVar3;
    local_24 = iVar3;
    JGadget::TNodeLinkList::erase(aTStack48,(iterator)piVar2);
    (**(code **)(piVar2[3] + 0x10))(piVar2,iVar3);
  }
  dMesg_finalize();
  if (header != (void *)0x0) {
    JKRFileLoader::removeResource(header,(JKRFileLoader *)0x0);
  }
  if (header2 != (void *)0x0) {
    JKRFileLoader::removeResource(header2,(JKRFileLoader *)0x0);
  }
  if ((oParse != (int *)0x0) && (oParse != (int *)0x0)) {
    (**(code **)(*oParse + 8))(oParse,1);
  }
  m_Do_ext::mDoExt_setCurrentHeap(uVar1);
  f_op_msg_mng::fopMsgM_destroyExpHeap(*(undefined4 *)(param_1 + 0xfc));
  return 1;
}


/* __stdcall dMsg_Create(msg_class *) */

undefined4 dMsg_Create(int param_1)

{
  JKRHeap *pJVar1;
  ulong uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  pJVar1 = f_op_msg_mng::fopMsgM_createExpHeap(0xb6b5);
  *(JKRHeap **)(param_1 + 0xfc) = pJVar1;
  if (*(int *)(param_1 + 0xfc) == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_mesg.cpp",0xf18,"i_Msg->heap != 0");
    m_Do_printf::OSPanic("d_mesg.cpp",0xf18,&DAT_803609f8);
  }
  uVar3 = m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0xfc));
  dMesg_gpFont = m_Do_ext::mDoExt_getMesgFont();
  if (dMesg_gpFont == (JUTFont *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_mesg.cpp",0xf1d,"dMesg_gpFont != 0");
    m_Do_printf::OSPanic("d_mesg.cpp",0xf1d,&DAT_803609f8);
  }
  dMesg_gpRFont = m_Do_ext::mDoExt_getRubyFont();
  if (dMesg_gpRFont == (JUTFont *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_mesg.cpp",0xf20,"dMesg_gpRFont != 0");
    m_Do_printf::OSPanic("d_mesg.cpp",0xf20,&DAT_803609f8);
  }
  dMesg_initialize(param_1);
  dMesg_parse();
  iVar4 = 0;
  iVar5 = 4;
  do {
    *(undefined4 *)(param_1 + iVar4 + 0x154) = 0;
    iVar4 = iVar4 + 4;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  *(undefined *)(param_1 + 0x164) = 0;
  m_Do_ext::mDoExt_setCurrentHeap(uVar3);
  return 4;
}

}

/* __thiscall dMesg_outFont_c::~dMesg_outFont_c(void) */

void __thiscall dMesg_outFont_c::_dMesg_outFont_c(dMesg_outFont_c *this)

{
  short in_r4;
  
  if ((this != (dMesg_outFont_c *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall dMesg_screenData_c::draw(void) */

void __thiscall dMesg_screenData_c::draw(dMesg_screenData_c *this)

{
  return;
}


/* __thiscall dMesg_screenDataItem_c::~dMesg_screenDataItem_c(void) */

void __thiscall dMesg_screenDataItem_c::_dMesg_screenDataItem_c(dMesg_screenDataItem_c *this)

{
  bool bVar1;
  short in_r4;
  
  bVar1 = this != (dMesg_screenDataItem_c *)0x0;
  if (bVar1) {
    *(undefined1 **)this = &__vt;
    if ((bVar1) && (*(undefined1 **)this = &dMesg_screenData_c::__vt, bVar1)) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dMesg_screenDataTalk_c::~dMesg_screenDataTalk_c(void) */

void __thiscall dMesg_screenDataTalk_c::_dMesg_screenDataTalk_c(dMesg_screenDataTalk_c *this)

{
  bool bVar1;
  short in_r4;
  
  bVar1 = this != (dMesg_screenDataTalk_c *)0x0;
  if (bVar1) {
    *(undefined1 **)this = &__vt;
    if ((bVar1) && (*(undefined1 **)this = &dMesg_screenData_c::__vt, bVar1)) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}

