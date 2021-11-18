#include <d_message.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <MSL_C.PPCEABI.bare.H/printf.h>
#include <m_Do_ext.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <J2DGraph/J2DTextBox.h>
#include <f_op_msg_mng.h>
#include <JKernel/JKRArchivePub.h>
#include <os/OSCache.h>
#include <d_drawlist.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <d_message.h>
#include <MSL_C.PPCEABI.bare.H/arith.h>
#include <d_kankyo.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <JKernel/JKRFileLoader.h>
#include <J2DGraph/J2DScreen.h>
#include <gx/GXTransform.h>
#include <gx/GXFrameBuf.h>
#include <JKernel/JKRHeap.h>
#include <J2DGraph/J2DPane.h>
#include <J2DGraph/J2DPicture.h>
#include <d_save.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <dDlst_2DMSG2_c.h>
#include <dDlst_2DCopy_c.h>


namespace d_message {
}

namespace d_message {
undefined4 sScreen2;
undefined4 bbutton_icon;
undefined4 bbutton_kage;
undefined2 bbuttonTimer;
undefined4 board;
undefined4 capture;
undefined4 dMsg2_popSpeed;
undefined4 message;

/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __stdcall dMsg2_value_init(sub_msg2_class *,
                              unsigned char) */

void dMsg2_value_init(int param_1,uint param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  char acStack168 [32];
  char acStack136 [32];
  char acStack104 [32];
  char acStack72 [40];
  
  uVar7 = *(uint *)(&colorTable_4005 + (uint)*(ushort *)(param_1 + 0xea4) * 4);
  iVar6 = param_1 + (param_2 & 0xff) * 0x2a0;
  bVar1 = *(byte *)(iVar6 + 0x3ac);
  bVar2 = *(byte *)(iVar6 + 0x3ad);
  bVar3 = *(byte *)(iVar6 + 0x3ae);
  bVar4 = *(byte *)(iVar6 + 0x3af);
  MSL_C.PPCEABI.bare.H::sprintf(acStack72,"\x1bCC[%08x]\x1bGC[%08x]",uVar7 | bVar1,uVar7 | bVar2);
  MSL_C.PPCEABI.bare.H::sprintf(acStack136,"\x1bCC[%08x]\x1bGC[%08x]",uVar7 | bVar3,uVar7 | bVar4);
  MSL_C.PPCEABI.bare.H::sprintf(acStack104,"\x1bCC[%08x]\x1bGC[%08x]",(uint)bVar1,(uint)bVar2);
  MSL_C.PPCEABI.bare.H::sprintf(acStack168,"\x1bCC[%08x]\x1bGC[%08x]",(uint)bVar3,(uint)bVar4);
  uVar5 = m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0x100));
  iVar6 = (param_2 & 0xff) * 4;
  MSL_C.PPCEABI.bare.H::strcpy(*(char **)(param_1 + iVar6 + 0xe64),acStack72);
  MSL_C.PPCEABI.bare.H::strcpy(*(char **)(param_1 + iVar6 + 0xe70),acStack136);
  MSL_C.PPCEABI.bare.H::strcpy(*(char **)(param_1 + iVar6 + 0xe7c),acStack104);
  MSL_C.PPCEABI.bare.H::strcpy(*(char **)(param_1 + iVar6 + 0xe88),acStack168);
  m_Do_ext::mDoExt_setCurrentHeap(uVar5);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall dMsg2_setString(sub_msg2_class *,
                             unsigned char) */

void dMsg2_setString(int param_1,uint param_2,___ param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0x100));
  iVar2 = (param_2 & 0xff) * 0x38;
  iVar3 = (param_2 & 0xff) * 4;
  J2DTextBox::setString
            (*(J2DTextBox **)(param_1 + iVar2 + 0x910),*(char **)(param_1 + iVar3 + 0xe64),param_3);
  J2DTextBox::setString
            (*(J2DTextBox **)(param_1 + iVar2 + 0xa60),*(char **)(param_1 + iVar3 + 0xe70),param_3);
  J2DTextBox::setString
            (*(J2DTextBox **)(param_1 + iVar2 + 0x9b8),*(char **)(param_1 + iVar3 + 0xe7c),param_3);
  J2DTextBox::setString
            (*(J2DTextBox **)(param_1 + iVar2 + 0xb08),*(char **)(param_1 + iVar3 + 0xe88),param_3);
  m_Do_ext::mDoExt_setCurrentHeap(uVar1);
  return;
}


/* __stdcall dMsg2_messagePaneShow(sub_msg2_class *,
                                   unsigned char) */

void dMsg2_messagePaneShow(int param_1,uint param_2)

{
  param_1 = param_1 + (param_2 & 0xff) * 0x38;
  *(undefined *)(*(int *)(param_1 + 0x910) + 0xaa) = 1;
  *(undefined *)(*(int *)(param_1 + 0xa60) + 0xaa) = 1;
  return;
}


/* __stdcall dMsg2_messagePaneHide(sub_msg2_class *,
                                   unsigned char) */

void dMsg2_messagePaneHide(int param_1,uint param_2)

{
  param_1 = param_1 + (param_2 & 0xff) * 0x38;
  *(undefined *)(*(int *)(param_1 + 0x910) + 0xaa) = 0;
  *(undefined *)(*(int *)(param_1 + 0xa60) + 0xaa) = 0;
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* WARNING: Removing unreachable block (ram,0x801e76bc) */
/* __stdcall dMsg2_outFontHide(sub_msg2_class *,
                               unsigned char) */

void dMsg2_outFontHide(int param_1,uint param_2)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined8 in_f31;
  double dVar7;
  undefined auStack8 [8];
  
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  uVar1 = m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0x100));
  iVar3 = 0;
  iVar5 = 0;
  iVar4 = 0;
  dVar7 = (double)_4069;
  do {
    *(undefined *)(*(int *)((int)(&bbutton_icon + (param_2 & 0xff)) + iVar4) + 0xaa) = 0;
    *(undefined *)(*(int *)((int)(&bbutton_kage + (param_2 & 0xff)) + iVar4) + 0xaa) = 0;
    piVar2 = *(int **)((int)(&bbutton_icon + (param_2 & 0xff)) + iVar4);
    piVar2[0x29] = (int)(float)dVar7;
    (**(code **)(*piVar2 + 0x20))();
    piVar2 = *(int **)((int)(&bbutton_kage + (param_2 & 0xff)) + iVar4);
    piVar2[0x29] = (int)(float)dVar7;
    (**(code **)(*piVar2 + 0x20))();
    *(undefined2 *)((int)&bbuttonTimer + iVar5 + (param_2 & 0xff) * 2) = 0xffff;
    iVar3 = iVar3 + 1;
    iVar5 = iVar5 + 6;
    iVar4 = iVar4 + 0xc;
  } while (iVar3 < 8);
  m_Do_ext::mDoExt_setCurrentHeap(uVar1);
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  return;
}


/* __stdcall dMsg2_arrowUpShow(sub_msg2_class *) */

void dMsg2_arrowUpShow(int param_1)

{
  f_op_msg_mng::fopMsgM_setInitAlpha(param_1 + 0xbb0);
  f_op_msg_mng::fopMsgM_setInitAlpha(param_1 + 0xbe8);
  return;
}


/* __stdcall dMsg2_arrowUpHide(sub_msg2_class *) */

void dMsg2_arrowUpHide(int param_1)

{
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0xbb0));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0xbe8));
  return;
}


/* __stdcall dMsg2_arrowDownShow(sub_msg2_class *) */

void dMsg2_arrowDownShow(int param_1)

{
  f_op_msg_mng::fopMsgM_setInitAlpha(param_1 + 0xc20);
  f_op_msg_mng::fopMsgM_setInitAlpha(param_1 + 0xc58);
  return;
}


/* __stdcall dMsg2_arrowDownHide(sub_msg2_class *) */

void dMsg2_arrowDownHide(int param_1)

{
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0xc20));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0xc58));
  return;
}


/* __stdcall dMsg2_dotShow(sub_msg2_class *) */

void dMsg2_dotShow(int param_1)

{
  f_op_msg_mng::fopMsgM_setInitAlpha(param_1 + 0xc90);
  f_op_msg_mng::fopMsgM_setInitAlpha(param_1 + 0xcc8);
  return;
}


/* __stdcall dMsg2_dotHide(sub_msg2_class *) */

void dMsg2_dotHide(int param_1)

{
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0xc90));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0xcc8));
  return;
}


/* __stdcall dMsg2_multiTexInit(sub_msg2_class *) */

void dMsg2_multiTexInit(int param_1)

{
  JKRArchive::readTypeResource
            (*(void **)(param_1 + 0xe58),0x11800,0x54494d47,"hukidashi_0212.bti",
             d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpMsgArchive);
  os::DCStoreRangeNoSync(*(undefined4 *)(param_1 + 0xe58),0x11800);
  if (*(char *)(param_1 + 0x110) == '\x06') {
    JKRArchive::readTypeResource
              (*(void **)(param_1 + 0xe5c),0x11800,0x54494d47,"hukidashi_06.bti",
               d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpMsgArchive);
    os::DCStoreRangeNoSync(*(undefined4 *)(param_1 + 0xe5c),0x11800);
    dDlst_2Dm_c::init((dDlst_2Dm_c *)&board,*(ResTIMG **)(param_1 + 0xe58),
                      *(ResTIMG **)(param_1 + 0xe5c),_4125,_4125);
  }
  else {
    if (*(char *)(param_1 + 0x110) == '\a') {
      JKRArchive::readTypeResource
                (*(void **)(param_1 + 0xe5c),0x11800,0x54494d47,"hukidashi_07.bti",
                 d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpMsgArchive);
      os::DCStoreRangeNoSync(*(undefined4 *)(param_1 + 0xe5c),0x11800);
      dDlst_2Dm_c::init((dDlst_2Dm_c *)&board,*(ResTIMG **)(param_1 + 0xe58),
                        *(ResTIMG **)(param_1 + 0xe5c),_4125,_4125);
    }
    else {
      JKRArchive::readTypeResource
                (*(void **)(param_1 + 0xe5c),0x11800,0x54494d47,"hukidashi_02.bti",
                 d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpMsgArchive);
      os::DCStoreRangeNoSync(*(undefined4 *)(param_1 + 0xe5c),0x11800);
      dDlst_2Dm_c::init((dDlst_2Dm_c *)&board,*(ResTIMG **)(param_1 + 0xe58),
                        *(ResTIMG **)(param_1 + 0xe5c),_4125,_4125);
    }
  }
  return;
}


/* __stdcall dMsg2_fontdataInit(sub_msg2_class *) */

void dMsg2_fontdataInit(int param_1)

{
  JUTFont *pJVar1;
  ulong uVar2;
  
  pJVar1 = m_Do_ext::mDoExt_getMesgFont();
  *(JUTFont **)(param_1 + 0xe50) = pJVar1;
  if (*(int *)(param_1 + 0xe50) == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_message.cpp",0x22b,"i_Msg->mx != 0");
    m_Do_printf::OSPanic("d_message.cpp",0x22b,&DAT_80360c6a);
  }
  pJVar1 = m_Do_ext::mDoExt_getRubyFont();
  *(JUTFont **)(param_1 + 0xe54) = pJVar1;
  if (*(int *)(param_1 + 0xe54) == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_message.cpp",0x22e,"i_Msg->rx != 0");
    m_Do_printf::OSPanic("d_message.cpp",0x22e,&DAT_80360c6a);
  }
  return;
}


/* __stdcall dMsg2_screenDataSet(sub_msg2_class *,
                                 unsigned char) */

void dMsg2_screenDataSet(undefined4 param_1,undefined4 param_2)

{
  dMsg2_value_init();
  dMsg2_setString(param_1,param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f24 */
/* WARNING: Inlined function: FUN_80328f70 */
/* WARNING: Removing unreachable block (ram,0x801e8134) */
/* __stdcall dMsg2_screenDataInit(sub_msg2_class *,
                                  unsigned char) */

void dMsg2_screenDataInit(int param_1,byte param_2)

{
  double dVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  uint uVar5;
  double dVar6;
  J2DScreen *pJVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  double in_f31;
  undefined auStack8 [8];
  
  uVar11 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,SUB84(in_f31,0),0);
  uVar5 = (uint)param_2;
  pJVar7 = (J2DScreen *)
           (**(code **)(*(int *)(&sScreen2)[uVar5] + 0x30))((int *)(&sScreen2)[uVar5],0x74783233);
  iVar10 = param_1 + (uint)param_2 * 0x38;
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(iVar10 + 0x910),pJVar7);
  pJVar7 = (J2DScreen *)
           (**(code **)(*(int *)(&sScreen2)[uVar5] + 0x30))((int *)(&sScreen2)[uVar5],0x74783239);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(iVar10 + 0xa60),pJVar7);
  pJVar7 = (J2DScreen *)
           (**(code **)(*(int *)(&sScreen2)[uVar5] + 0x30))((int *)(&sScreen2)[uVar5],0x74783230);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(iVar10 + 0x9b8),pJVar7);
  pJVar7 = (J2DScreen *)
           (**(code **)(*(int *)(&sScreen2)[uVar5] + 0x30))((int *)(&sScreen2)[uVar5],0x74783236);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(iVar10 + 0xb08),pJVar7);
  *(undefined *)(*(int *)(iVar10 + 0x9b8) + 0xaa) = 0;
  *(undefined *)(*(int *)(iVar10 + 0xb08) + 0xaa) = 0;
  *(float *)(iVar10 + 0x938) = *(float *)(iVar10 + 0x938) + _4262;
  *(undefined4 *)(iVar10 + 0x940) = *(undefined4 *)(iVar10 + 0x938);
  f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(iVar10 + 0x910));
  *(float *)(iVar10 + 0x9e0) = *(float *)(iVar10 + 0x9e0) + _4262;
  *(undefined4 *)(iVar10 + 0x9e8) = *(undefined4 *)(iVar10 + 0x9e0);
  f_op_msg_mng::fopMsgM_cposMove((fopMsgM_pane_class *)(iVar10 + 0x9b8));
  pJVar7 = (J2DScreen *)
           (**(code **)(*(int *)(&sScreen2)[uVar5] + 0x30))((int *)(&sScreen2)[uVar5],0x6d733232);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(iVar10 + 0xd00),pJVar7);
  pJVar7 = (J2DScreen *)
           (**(code **)(*(int *)(&sScreen2)[uVar5] + 0x30))((int *)(&sScreen2)[uVar5],0x6d733230);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(iVar10 + 0xda8),pJVar7);
  iVar8 = (**(code **)(*(int *)(&sScreen2)[uVar5] + 0x30))((int *)(&sScreen2)[uVar5],0x74783234);
  *(undefined *)(iVar8 + 0xaa) = 0;
  iVar8 = (**(code **)(*(int *)(&sScreen2)[uVar5] + 0x30))((int *)(&sScreen2)[uVar5],0x74783330);
  *(undefined *)(iVar8 + 0xaa) = 0;
  iVar8 = (**(code **)(*(int *)(&sScreen2)[uVar5] + 0x30))((int *)(&sScreen2)[uVar5],0x74783231);
  *(undefined *)(iVar8 + 0xaa) = 0;
  iVar8 = (**(code **)(*(int *)(&sScreen2)[uVar5] + 0x30))((int *)(&sScreen2)[uVar5],0x74783237);
  *(undefined *)(iVar8 + 0xaa) = 0;
  iVar8 = *(int *)(iVar10 + 0xd00);
  *(undefined *)(iVar8 + 0x104) = 0;
  *(undefined *)(iVar8 + 0x105) = 0;
  *(undefined *)(iVar8 + 0x106) = 0;
  *(undefined *)(iVar8 + 0x107) = 0;
  iVar8 = *(int *)(iVar10 + 0xda8);
  *(undefined *)(iVar8 + 0x104) = 0;
  *(undefined *)(iVar8 + 0x105) = 0;
  *(undefined *)(iVar8 + 0x106) = 0;
  *(undefined *)(iVar8 + 0x107) = 0;
  if (param_2 == 0) {
    pJVar7 = (J2DScreen *)
             (**(code **)(*(int *)(&sScreen2)[uVar5] + 0x30))((int *)(&sScreen2)[uVar5],0x797a3231);
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0xbb0),pJVar7);
    pJVar7 = (J2DScreen *)
             (**(code **)(*(int *)(&sScreen2)[uVar5] + 0x30))((int *)(&sScreen2)[uVar5],0x797a3230);
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0xc20),pJVar7);
    pJVar7 = (J2DScreen *)
             (**(code **)(*(int *)(&sScreen2)[uVar5] + 0x30))((int *)(&sScreen2)[uVar5],0x64743230);
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0xc90),pJVar7);
    pJVar7 = (J2DScreen *)
             (**(code **)(*(int *)(&sScreen2)[uVar5] + 0x30))((int *)(&sScreen2)[uVar5],0x797a3233);
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0xbe8),pJVar7);
    pJVar7 = (J2DScreen *)
             (**(code **)(*(int *)(&sScreen2)[uVar5] + 0x30))((int *)(&sScreen2)[uVar5],0x797a3232);
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0xc58),pJVar7);
    pJVar7 = (J2DScreen *)
             (**(code **)(*(int *)(&sScreen2)[uVar5] + 0x30))((int *)(&sScreen2)[uVar5],0x64743231);
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0xcc8),pJVar7);
    iVar8 = *(int *)(param_1 + 0xbe8);
    *(undefined *)(iVar8 + 0x104) = 0;
    *(undefined *)(iVar8 + 0x105) = 0;
    *(undefined *)(iVar8 + 0x106) = 0;
    *(undefined *)(iVar8 + 0x107) = 0xff;
    iVar8 = *(int *)(param_1 + 0xc58);
    *(undefined *)(iVar8 + 0x104) = 0;
    *(undefined *)(iVar8 + 0x105) = 0;
    *(undefined *)(iVar8 + 0x106) = 0;
    *(undefined *)(iVar8 + 0x107) = 0xff;
    iVar8 = *(int *)(param_1 + 0xcc8);
    *(undefined *)(iVar8 + 0x104) = 0;
    *(undefined *)(iVar8 + 0x105) = 0;
    *(undefined *)(iVar8 + 0x106) = 0;
    *(undefined *)(iVar8 + 0x107) = 0xff;
  }
  else {
    iVar8 = (**(code **)(*(int *)(&sScreen2)[uVar5] + 0x30))((int *)(&sScreen2)[uVar5],0x797a3231);
    *(undefined *)(iVar8 + 0xaa) = 0;
    iVar8 = (**(code **)(*(int *)(&sScreen2)[uVar5] + 0x30))((int *)(&sScreen2)[uVar5],0x797a3230);
    *(undefined *)(iVar8 + 0xaa) = 0;
    iVar8 = (**(code **)(*(int *)(&sScreen2)[uVar5] + 0x30))((int *)(&sScreen2)[uVar5],0x64743230);
    *(undefined *)(iVar8 + 0xaa) = 0;
    iVar8 = (**(code **)(*(int *)(&sScreen2)[uVar5] + 0x30))((int *)(&sScreen2)[uVar5],0x797a3233);
    *(undefined *)(iVar8 + 0xaa) = 0;
    iVar8 = (**(code **)(*(int *)(&sScreen2)[uVar5] + 0x30))((int *)(&sScreen2)[uVar5],0x797a3232);
    *(undefined *)(iVar8 + 0xaa) = 0;
    iVar8 = (**(code **)(*(int *)(&sScreen2)[uVar5] + 0x30))((int *)(&sScreen2)[uVar5],0x64743231);
    *(undefined *)(iVar8 + 0xaa) = 0;
  }
  iVar9 = param_1 + (uint)param_2 * 0x38;
  J2DTextBox::setFont(*(J2DTextBox **)(iVar9 + 0x910),*(JUTFont **)(param_1 + 0xe50));
  J2DTextBox::setFont(*(J2DTextBox **)(iVar9 + 0xa60),*(JUTFont **)(param_1 + 0xe54));
  J2DTextBox::setFont(*(J2DTextBox **)(iVar10 + 0x9b8),*(JUTFont **)(param_1 + 0xe50));
  J2DTextBox::setFont(*(J2DTextBox **)(iVar10 + 0xb08),*(JUTFont **)(param_1 + 0xe54));
  dVar1 = (double)CONCAT44(0x43300000,(int)DAT_803e6bb4 ^ 0x80000000U) - _4264;
  fVar2 = (float)dVar1;
  fVar3 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e6bb4 ^ 0x80000000U) - _4264);
  iVar8 = *(int *)(iVar9 + 0x910);
  fVar4 = _4069;
  if (_4069 < fVar2) {
    fVar4 = fVar2;
  }
  *(float *)(iVar8 + 0xe8) = fVar4;
  fVar4 = _4069;
  if (_4069 < fVar3) {
    fVar4 = fVar3;
  }
  *(float *)(iVar8 + 0xec) = fVar4;
  iVar8 = *(int *)(iVar10 + 0x9b8);
  fVar4 = _4069;
  if (_4069 < fVar2) {
    fVar4 = fVar2;
  }
  *(float *)(iVar8 + 0xe8) = fVar4;
  fVar2 = _4069;
  if (_4069 < fVar3) {
    fVar2 = fVar3;
  }
  *(float *)(iVar8 + 0xec) = fVar2;
  fVar2 = _4069;
  *(float *)(*(int *)(iVar9 + 0x910) + 0xe0) = _4069;
  *(float *)(*(int *)(iVar9 + 0xa60) + 0xe0) = fVar2;
  *(float *)(*(int *)(iVar10 + 0x9b8) + 0xe0) = fVar2;
  (*(J2DTextBox **)(iVar10 + 0xb08))->field_0xe0 = fVar2;
  dVar6 = _4264;
  *(float *)(*(int *)(iVar9 + 0x910) + 0xe4) =
       (float)((double)CONCAT44(0x43300000,(int)DAT_803e6ba2 ^ 0x80000000) - _4264);
  *(float *)(*(int *)(iVar10 + 0x9b8) + 0xe4) =
       (float)((double)CONCAT44(0x43300000,(int)DAT_803e6ba2 ^ 0x80000000) - dVar6);
  *(int *)(param_1 + 0xeb4) = (int)dVar1;
  *(int *)(param_1 + 0xeb8) = (int)in_f31;
  __psq_l0(auStack8,uVar11);
  __psq_l1(auStack8,uVar11);
  return;
}


/* __stdcall dMsg2_ScreenDataValueInit(sub_msg2_class *) */

void dMsg2_ScreenDataValueInit(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x910);
  *(int *)(param_1 + 0xeb0) = (int)(*(float *)(iVar1 + 0xe4) * _4281);
  *(float *)(param_1 + 0xe94) =
       (float)((double)CONCAT44(0x43300000,(int)DAT_803e6c18 ^ 0x80000000) - _4264) +
       (*(float *)(iVar1 + 0x18) - *(float *)(iVar1 + 0x10));
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(param_1 + 0x910),(double)_4069,(double)_4069);
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(param_1 + 0x948),(double)_4069,
             (double)*(float *)(param_1 + 0xe94));
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(param_1 + 0x980),(double)_4069,
             -(double)*(float *)(param_1 + 0xe94));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0xbb0));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0xbe8));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0xc20));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0xc58));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0xc90));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0xcc8));
  iVar1 = 0;
  do {
    dMsg2_messageDataInit(param_1,iVar1);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 3);
  return;
}


/* __stdcall dMsg2_stickInfoInit(sub_msg2_class *) */

void dMsg2_stickInfoInit(int param_1)

{
  if ((_4298 < m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mStickMainPosY) ||
     (_4298 < m_Do_controller_pad::g_mDoCPd_cpadInfo[3].mStickMainPosY)) {
    *(undefined *)(param_1 + 0xedd) = 1;
    return;
  }
  if ((_4298 <= m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mStickMainPosY) &&
     (_4298 <= m_Do_controller_pad::g_mDoCPd_cpadInfo[3].mStickMainPosY)) {
    *(undefined *)(param_1 + 0xedd) = 0;
    return;
  }
  *(undefined *)(param_1 + 0xedd) = 2;
  return;
}


/* __stdcall dMsg2_stickInfoCheck(sub_msg2_class *) */

void dMsg2_stickInfoCheck(int param_1)

{
  if (*(char *)(param_1 + 0xedd) == '\x01') {
    if ((_4069 < m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mStickMainPosY) &&
       (_4069 < m_Do_controller_pad::g_mDoCPd_cpadInfo[3].mStickMainPosY)) {
      return;
    }
    *(undefined *)(param_1 + 0xedd) = 0;
    return;
  }
  if (*(char *)(param_1 + 0xedd) != '\x02') {
    return;
  }
  if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mStickMainPosY < _4069) &&
     (m_Do_controller_pad::g_mDoCPd_cpadInfo[3].mStickMainPosY < _4069)) {
    return;
  }
  *(undefined *)(param_1 + 0xedd) = 0;
  return;
}


/* WARNING: Removing unreachable block (ram,0x801e84cc) */
/* __stdcall dMsg2_multiTexDraw(sub_msg2_class *,
                                short,
                                short,
                                short,
                                short) */

void dMsg2_multiTexDraw
               (int param_1,short param_2,short param_3,short param_4,short param_5)

{
  undefined4 uVar1;
  undefined8 in_f31;
  double dVar2;
  undefined local_38;
  undefined uStack55;
  undefined uStack54;
  undefined uStack53;
  undefined local_34;
  undefined uStack51;
  undefined uStack50;
  undefined local_30;
  undefined uStack47;
  undefined uStack46;
  undefined uStack45;
  undefined local_2c;
  undefined uStack43;
  undefined uStack42;
  double local_28;
  undefined auStack8 [8];
  
  uVar1 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  local_28 = (double)CONCAT44(0x43300000,(uint)DAT_803e6c37);
  dVar2 = (double)((*(float *)(param_1 + 0xeac) * (float)(local_28 - _4348)) / _4346);
  dDlst_2Dm_c::setPos((dDlst_2Dm_c *)&board,param_2,param_3,param_2 + param_4,param_3 + param_5);
  if (*(char *)(param_1 + 0x110) == '\a') {
    local_2c = (undefined)((uint)_4321 >> 0x18);
    DAT_803e664c = local_2c;
    uStack43 = (undefined)((uint)_4321 >> 0x10);
    DAT_803e664d = uStack43;
    uStack42 = (undefined)((uint)_4321 >> 8);
    DAT_803e664e = uStack42;
    local_30 = (undefined)((uint)_4323 >> 0x18);
    DAT_803e6650 = local_30;
    uStack47 = (undefined)((uint)_4323 >> 0x10);
    DAT_803e6651 = uStack47;
    uStack46 = (undefined)((uint)_4323 >> 8);
    DAT_803e6652 = uStack46;
    uStack45 = (undefined)_4323;
    DAT_803e6653 = uStack45;
  }
  else {
    local_34 = (undefined)((uint)_4326 >> 0x18);
    DAT_803e664c = local_34;
    uStack51 = (undefined)((uint)_4326 >> 0x10);
    DAT_803e664d = uStack51;
    uStack50 = (undefined)((uint)_4326 >> 8);
    DAT_803e664e = uStack50;
    local_38 = (undefined)((uint)_4328 >> 0x18);
    DAT_803e6650 = local_38;
    uStack55 = (undefined)((uint)_4328 >> 0x10);
    DAT_803e6651 = uStack55;
    uStack54 = (undefined)((uint)_4328 >> 8);
    DAT_803e6652 = uStack54;
    uStack53 = (undefined)_4328;
    DAT_803e6653 = uStack53;
  }
  DAT_803e664f = (undefined)(int)dVar2;
  dDlst_2Dm_c::setScroll((dDlst_2Dm_c *)&board,0,0,0);
  dDlst_2Dm_c::setScroll((dDlst_2Dm_c *)&board,1,0,(short)*(undefined4 *)(param_1 + 0xec8));
  dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,(dDlst_base_c *)&board)
  ;
  __psq_l0(auStack8,uVar1);
  __psq_l1(auStack8,uVar1);
  return;
}


/* WARNING: Inlined function: FUN_80328f10 */
/* WARNING: Inlined function: FUN_80328f5c */
/* __stdcall dMsg2_messageOut(sub_msg2_class *,
                              unsigned char,
                              int) */

void dMsg2_messageOut(int param_1,uint param_2,undefined4 param_3)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  uVar2 = param_2 & 0xff;
  iVar9 = (param_2 & 0xff) * 4;
  *(undefined4 *)(param_1 + iVar9 + 0xecc) = 0;
  dMsg2_messagePaneShow();
  dMsg2_messageDataInit(param_1,uVar2);
  iVar5 = uVar2 * 0x2a0;
  iVar3 = param_1 + iVar5;
  *(undefined4 *)(iVar3 + 0x234) = 0;
  *(undefined4 *)(iVar3 + 0x254) = 0;
  *(undefined4 *)(iVar3 + 600) = param_3;
  dMsg2_yose_select(param_1,param_2);
  *(undefined *)(param_1 + iVar5 + 0x3b5) = 1;
  dMsg2_setCharAlpha(param_1,param_2);
  iVar5 = param_1 + iVar5;
  fopMsgM_msgDataProc_c::stringSet((fopMsgM_msgDataProc_c *)(iVar5 + 0x11c));
  iVar8 = 0;
  iVar7 = 0;
  iVar6 = 0;
  iVar3 = 0;
  do {
    cVar1 = *(char *)(iVar5 + iVar8 + 0x39d);
    iVar10 = *(int *)(iVar5 + iVar3 + 0x33c);
    if ((cVar1 != -1) && (*(short *)((int)&bbuttonTimer + iVar6 + uVar2 * 2) == -1)) {
      uVar4 = m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0x100));
      if ((((byte)(cVar1 - 10U) < 4) || ((cVar1 == '\x15' || (cVar1 == '\x17')))) && (iVar10 == 0))
      {
        iVar10 = -1;
      }
      f_op_msg_mng::fopMsgM_outFontSet
                (*(undefined4 *)((int)&bbutton_icon + iVar7 + iVar9),
                 *(undefined4 *)((int)&bbutton_kage + iVar7 + iVar9),
                 (int)&bbuttonTimer + iVar6 + uVar2 * 2,iVar10,cVar1);
      m_Do_ext::mDoExt_setCurrentHeap(uVar4);
    }
    iVar8 = iVar8 + 1;
    iVar7 = iVar7 + 0xc;
    iVar6 = iVar6 + 6;
    iVar3 = iVar3 + 4;
  } while (iVar8 < 8);
  dMsg2_setString(param_1,param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __stdcall dMsg2_yose_select(sub_msg2_class *,
                               unsigned char) */

void dMsg2_yose_select(int param_1,uint param_2)

{
  undefined4 uVar1;
  fopMsgM_msgDataProc_c *this;
  int iVar2;
  
  iVar2 = (param_2 & 0xff) * 0x2a0;
  this = (fopMsgM_msgDataProc_c *)(param_1 + iVar2 + 0x11c);
  uVar1 = fopMsgM_msgDataProc_c::stringLength(this);
  iVar2 = param_1 + iVar2;
  *(undefined4 *)(iVar2 + 0x234) = uVar1;
  *(undefined4 *)(param_1 + (param_2 & 0xff) * 4 + 0xecc) = *(undefined4 *)(iVar2 + 0x24c);
  *(undefined4 *)(iVar2 + 0x24c) = 0;
  fopMsgM_msgDataProc_c::stringShift(this);
  dMsg2_textPosition(param_1,param_2);
  return;
}


/* __stdcall dMsg2_textPosition(sub_msg2_class *,
                                unsigned char) */

void dMsg2_textPosition(int param_1,uint param_2)

{
  float fVar1;
  double dVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  fVar1 = _4069;
  iVar5 = *(int *)(param_1 + 0xeb0);
  iVar3 = *(int *)(param_1 + (param_2 & 0xff) * 4 + 0xecc);
  param_1 = param_1 + (param_2 & 0xff) * 0x38;
  iVar6 = *(int *)(param_1 + 0x910);
  *(float *)(iVar6 + 0xd8) = _4069;
  dVar2 = _4264;
  uVar4 = iVar5 * (3 - iVar3) ^ 0x80000000;
  *(float *)(iVar6 + 0xdc) = (float)((double)CONCAT44(0x43300000,uVar4) - _4264);
  iVar3 = *(int *)(param_1 + 0xa60);
  *(float *)(iVar3 + 0xd8) = fVar1;
  *(float *)(iVar3 + 0xdc) = (float)((double)CONCAT44(0x43300000,uVar4) - dVar2);
  iVar3 = *(int *)(param_1 + 0x9b8);
  *(float *)(iVar3 + 0xd8) = fVar1;
  *(float *)(iVar3 + 0xdc) = (float)((double)CONCAT44(0x43300000,uVar4) - dVar2);
  iVar3 = *(int *)(param_1 + 0xb08);
  *(float *)(iVar3 + 0xd8) = fVar1;
  *(float *)(iVar3 + 0xdc) = (float)((double)CONCAT44(0x43300000,uVar4) - dVar2);
  return;
}


/* __stdcall dMsg2_rubySet(sub_msg2_class *) */

void dMsg2_rubySet(int param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  sVar1 = *(short *)(param_1 + 0xf8);
  if ((((sVar1 != 5) && (sVar1 != 6)) && (sVar1 != 7)) && (sVar1 != 10)) {
    return;
  }
  iVar2 = 0;
  iVar3 = 3;
  do {
    if (DAT_803e6c27 == '\0') {
      *(undefined *)(*(int *)(param_1 + iVar2 + 0xa60) + 0xaa) = 0;
    }
    else {
      *(undefined *)(*(int *)(param_1 + iVar2 + 0xa60) + 0xaa) = 1;
    }
    iVar2 = iVar2 + 0x38;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}


/* __stdcall dMsg2_arrowMove(sub_msg2_class *) */

void dMsg2_arrowMove(int param_1)

{
  uint uVar1;
  
  *(int *)(param_1 + 0xebc) = *(int *)(param_1 + 0xebc) + 1;
  if (0xc < *(int *)(param_1 + 0xebc)) {
    *(int *)(param_1 + 0xebc) = *(int *)(param_1 + 0xebc) + -0xc;
  }
  uVar1 = MSL_C.PPCEABI.bare.H::abs(6 - *(int *)(param_1 + 0xebc));
  (**(code **)(**(int **)(param_1 + 0xc20) + 0x10))
            ((double)*(float *)(param_1 + 0xc24),
             (double)((*(float *)(param_1 + 0xc28) - _4453) -
                     (float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - _4264)));
  uVar1 = MSL_C.PPCEABI.bare.H::abs(6 - *(int *)(param_1 + 0xebc));
  (**(code **)(**(int **)(param_1 + 0xc58) + 0x10))
            ((double)*(float *)(param_1 + 0xc24),
             (double)((*(float *)(param_1 + 0xc28) - _4453) -
                     (float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - _4264)));
  uVar1 = MSL_C.PPCEABI.bare.H::abs(6 - *(int *)(param_1 + 0xebc));
  (**(code **)(**(int **)(param_1 + 0xbb0) + 0x10))
            ((double)*(float *)(param_1 + 0xbb4),
             (double)((*(float *)(param_1 + 3000) - _4453) +
                     (float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - _4264)));
  uVar1 = MSL_C.PPCEABI.bare.H::abs(6 - *(int *)(param_1 + 0xebc));
  (**(code **)(**(int **)(param_1 + 0xbe8) + 0x10))
            ((double)*(float *)(param_1 + 0xbb4),
             (double)((*(float *)(param_1 + 3000) - _4453) +
                     (float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - _4264)));
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall dMsg2_aimAlphaSqare(sub_msg2_class *,
                                 int,
                                 int) */

void dMsg2_aimAlphaSqare(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  if ((int)param_3 < 0) {
    param_3 = 0;
  }
  else {
    if ((int)param_2 < (int)param_3) {
      param_3 = param_2;
    }
  }
  uVar1 = dMsg2_aimBrightness();
  *(float *)(param_1 + 0xea8) =
       _4346 - (_4346 - (float)((double)CONCAT44(0x43300000,uVar1 & 0xff) - _4348)) *
               (((float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - _4264) *
                (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - _4264)) /
               ((float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - _4264) *
               (float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - _4264)));
  return;
}


/* WARNING: Removing unreachable block (ram,0x801e8b74) */
/* __stdcall dMsg2_aimAlphaSqrt(sub_msg2_class *,
                                int,
                                int) */

void dMsg2_aimAlphaSqrt(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  undefined4 uVar2;
  double dVar3;
  undefined8 in_f31;
  double dVar4;
  undefined auStack8 [8];
  
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if ((int)param_3 < 0) {
    param_3 = 0;
  }
  else {
    if ((int)param_2 < (int)param_3) {
      param_3 = param_2;
    }
  }
  dVar4 = (double)((float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - _4264) /
                  (float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - _4264));
  if ((double)_4069 < dVar4) {
    dVar3 = 1.0 / SQRT(dVar4);
    dVar3 = _4490 * dVar3 * (_4491 - dVar4 * dVar3 * dVar3);
    dVar3 = _4490 * dVar3 * (_4491 - dVar4 * dVar3 * dVar3);
    dVar4 = (double)(float)(dVar4 * _4490 * dVar3 * (_4491 - dVar4 * dVar3 * dVar3));
  }
  uVar1 = dMsg2_aimBrightness();
  *(float *)(param_1 + 0xea8) =
       _4346 - (float)((double)(_4346 - (float)((double)CONCAT44(0x43300000,uVar1 & 0xff) - _4348))
                      * dVar4);
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  return;
}


/* __stdcall dMsg2_kankyoBrightness(void) */

int dMsg2_kankyoBrightness(void)

{
  short *psVar1;
  
  psVar1 = (short *)d_kankyo::dKy_Get_DifCol();
  return (int)(_4498 * (float)((double)CONCAT44(0x43300000,(int)psVar1[2] ^ 0x80000000) - _4264) +
              _4499 * (float)((double)CONCAT44(0x43300000,(int)*psVar1 ^ 0x80000000) - _4264) +
              _4500 * (float)((double)CONCAT44(0x43300000,(int)psVar1[1] ^ 0x80000000) - _4264));
}


/* __stdcall dMsg2_aimBrightness(void) */

char dMsg2_aimBrightness(void)

{
  char cVar1;
  byte bVar2;
  
  bVar2 = dMsg2_kankyoBrightness();
  cVar1 = -1;
  if (DAT_803e6c05 < bVar2) {
    cVar1 = -1 - (bVar2 - DAT_803e6c05);
  }
  return cVar1;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __stdcall dMsg2_setCharAlpha(sub_msg2_class *,
                                unsigned char) */

void dMsg2_setCharAlpha(int param_1,uint param_2)

{
  undefined uVar1;
  undefined uVar2;
  undefined uVar3;
  float fVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  uVar5 = param_2 & 0xff;
  iVar6 = *(int *)(param_1 + (param_2 & 0xff) * 4 + 0xecc);
  fVar4 = (*(float *)(param_1 + 0xd08) - *(float *)(param_1 + 0xdb0)) +
          *(float *)(param_1 + uVar5 * 0x38 + 0x920) +
          (float)((double)CONCAT44(0x43300000,*(int *)(param_1 + 0xeb0) * (2 - iVar6) ^ 0x80000000)
                 - _4264);
  iVar7 = (int)fVar4;
  iVar6 = (int)*(float *)(*(int *)(param_1 + 0x910) + 0xe4) * iVar6;
  iVar9 = iVar7 + iVar6;
  iVar8 = (int)(fVar4 - (float)((double)CONCAT44(0x43300000,(int)DAT_803e6c14 ^ 0x80000000) - _4264)
               );
  iVar6 = iVar8 + iVar6;
  if (iVar9 < 0x3a) {
    iVar7 = (**(code **)(**(int **)(param_1 + 0xe50) + 0x24))();
    if (iVar9 < 0) {
      *(undefined *)(param_1 + uVar5 + 0xedf) = 0;
    }
    else {
      *(undefined *)(param_1 + uVar5 + 0xedf) = (&dMsg2_tex_i4_color)[iVar9];
    }
    if (iVar9 + iVar7 < 0) {
      *(undefined *)(param_1 + uVar5 + 0xee2) = 0;
    }
    else {
      *(undefined *)(param_1 + uVar5 + 0xee2) = (&dMsg2_tex_i4_color)[iVar9 + iVar7];
    }
  }
  else {
    if (iVar7 < 0xbc) {
      *(undefined *)(param_1 + uVar5 + 0xedf) = 0xff;
      *(undefined *)(param_1 + uVar5 + 0xee2) = 0xff;
    }
    else {
      iVar9 = (**(code **)(**(int **)(param_1 + 0xe50) + 0x24))();
      if (iVar7 < 0xf0) {
        *(undefined *)(param_1 + uVar5 + 0xedf) = (&dMsg2_tex_i4_color)[iVar7];
      }
      else {
        *(undefined *)(param_1 + uVar5 + 0xedf) = 0;
      }
      if (iVar7 + iVar9 < 0xf0) {
        *(undefined *)(param_1 + uVar5 + 0xee2) = (&dMsg2_tex_i4_color)[iVar7 + iVar9];
      }
      else {
        *(undefined *)(param_1 + uVar5 + 0xee2) = 0;
      }
    }
  }
  if (iVar6 < 0x3a) {
    iVar7 = (**(code **)(**(int **)(param_1 + 0xe54) + 0x24))();
    if (iVar6 < 0) {
      *(undefined *)(param_1 + uVar5 + 0xee5) = 0;
    }
    else {
      *(undefined *)(param_1 + uVar5 + 0xee5) = (&dMsg2_tex_i4_color)[iVar6];
    }
    if (iVar6 + iVar7 < 0) {
      *(undefined *)(param_1 + uVar5 + 0xee8) = 0;
    }
    else {
      *(undefined *)(param_1 + uVar5 + 0xee8) = (&dMsg2_tex_i4_color)[iVar6 + iVar7];
    }
  }
  else {
    if (iVar8 < 0xbc) {
      *(undefined *)(param_1 + uVar5 + 0xee5) = 0xff;
      *(undefined *)(param_1 + uVar5 + 0xee8) = 0xff;
    }
    else {
      iVar7 = (**(code **)(**(int **)(param_1 + 0xe54) + 0x24))();
      if (iVar8 < 0xf0) {
        *(undefined *)(param_1 + uVar5 + 0xee5) = (&dMsg2_tex_i4_color)[iVar8];
      }
      else {
        *(undefined *)(param_1 + uVar5 + 0xee5) = 0;
      }
      if (iVar8 + iVar7 < 0xf0) {
        *(undefined *)(param_1 + uVar5 + 0xee8) = (&dMsg2_tex_i4_color)[iVar8 + iVar7];
      }
      else {
        *(undefined *)(param_1 + uVar5 + 0xee8) = 0;
      }
    }
  }
  iVar7 = param_1 + uVar5;
  if (((int)*(float *)(param_1 + 0xeac) & 0xffU) < (uint)*(byte *)(iVar7 + 0xedf)) {
    *(char *)(iVar7 + 0xedf) = (char)(int)*(float *)(param_1 + 0xeac);
  }
  iVar8 = param_1 + uVar5;
  if (((int)*(float *)(param_1 + 0xeac) & 0xffU) < (uint)*(byte *)(iVar8 + 0xee2)) {
    *(char *)(iVar8 + 0xee2) = (char)(int)*(float *)(param_1 + 0xeac);
  }
  iVar6 = param_1 + uVar5;
  if (((int)*(float *)(param_1 + 0xeac) & 0xffU) < (uint)*(byte *)(iVar6 + 0xee5)) {
    *(char *)(iVar6 + 0xee5) = (char)(int)*(float *)(param_1 + 0xeac);
  }
  iVar9 = param_1 + uVar5;
  if (((int)*(float *)(param_1 + 0xeac) & 0xffU) < (uint)*(byte *)(iVar9 + 0xee8)) {
    *(char *)(iVar9 + 0xee8) = (char)(int)*(float *)(param_1 + 0xeac);
  }
  uVar1 = *(undefined *)(iVar9 + 0xee8);
  uVar2 = *(undefined *)(iVar6 + 0xee5);
  uVar3 = *(undefined *)(iVar8 + 0xee2);
  param_1 = param_1 + uVar5 * 0x2a0;
  *(undefined *)(param_1 + 0x3ac) = *(undefined *)(iVar7 + 0xedf);
  *(undefined *)(param_1 + 0x3ad) = uVar3;
  *(undefined *)(param_1 + 0x3ae) = uVar2;
  *(undefined *)(param_1 + 0x3af) = uVar1;
  return;
}


/* __stdcall dMsg2_messageShow(sub_msg2_class *) */

void dMsg2_messageShow(int param_1)

{
  uint uVar1;
  
  for (uVar1 = 0; (uVar1 & 0xff) < 3; uVar1 = uVar1 + 1) {
    dMsg2_screenDataSet(param_1,uVar1);
  }
  if (0 < *(int *)(param_1 + 0xec4)) {
    dMsg2_messageOut(param_1,*(undefined *)(param_1 + 0xe9c),
                     *(int *)(param_1 + 0xec4) - (uint)*(byte *)(param_1 + 0x11a));
  }
  dMsg2_messageOut(param_1,*(undefined *)(param_1 + 0xe9d),*(undefined4 *)(param_1 + 0xec4));
  if (*(char *)(param_1 + (uint)*(byte *)(param_1 + 0xe9d) * 0x2a0 + 0x398) == '\a') {
    dMsg2_messageOut(param_1,*(undefined *)(param_1 + 0xe9e),
                     *(int *)(param_1 + 0xec4) + (uint)*(byte *)(param_1 + 0x11a));
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x801e922c) */
/* WARNING: Removing unreachable block (ram,0x801e9234) */
/* __stdcall dMsg2_messageDataInit(sub_msg2_class *,
                                   int) */

void dMsg2_messageDataInit(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
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
  iVar7 = param_1 + param_2 * 0x38;
  dVar10 = (double)*(float *)(*(int *)(iVar7 + 0x910) + 0xe0);
  dVar9 = (double)*(float *)(*(int *)(iVar7 + 0xa60) + 0xe0);
  iVar6 = param_2 * 0x2a0;
  fopMsgM_msgDataProc_c::dataInit((fopMsgM_msgDataProc_c *)(param_1 + iVar6 + 0x11c));
  *(undefined4 *)(param_1 + iVar6 + 0x158) = *(undefined4 *)(param_1 + 0xe60);
  m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0x100));
  iVar2 = param_1 + param_2 * 4;
  uVar5 = *(undefined4 *)(iVar2 + 0xe88);
  uVar4 = *(undefined4 *)(iVar2 + 0xe7c);
  uVar3 = *(undefined4 *)(iVar2 + 0xe70);
  uVar1 = *(undefined4 *)(iVar2 + 0xe64);
  iVar2 = param_1 + iVar6;
  *(undefined4 *)(iVar2 + 0x17c) = uVar1;
  *(undefined4 *)(iVar2 + 0x15c) = uVar1;
  *(undefined4 *)(iVar2 + 0x180) = uVar3;
  *(undefined4 *)(iVar2 + 0x160) = uVar3;
  *(undefined4 *)(iVar2 + 0x184) = uVar4;
  *(undefined4 *)(iVar2 + 0x164) = uVar4;
  *(undefined4 *)(iVar2 + 0x188) = uVar5;
  *(undefined4 *)(iVar2 + 0x168) = uVar5;
  m_Do_ext::mDoExt_setCurrentHeap();
  iVar6 = param_1 + iVar6;
  *(undefined4 *)(iVar6 + 0x120) = *(undefined4 *)(param_1 + 0xe50);
  *(undefined4 *)(iVar6 + 0x124) = *(undefined4 *)(param_1 + 0xe54);
  *(int *)(iVar6 + 0x238) = (int)dVar10;
  *(int *)(iVar6 + 0x240) = (int)dVar9;
  *(int *)(iVar6 + 0x23c) = (int)*(float *)(*(int *)(iVar7 + 0x910) + 0xe4);
  *(int *)(iVar6 + 0x128) = param_1 + 0x104;
  *(undefined4 *)(iVar6 + 0x260) = *(undefined4 *)(param_1 + 0xeb4);
  *(undefined4 *)(iVar6 + 0x268) = *(undefined4 *)(param_1 + 0xeb8);
  *(undefined4 *)(iVar6 + 0x244) = 0x1f7;
  *(undefined4 *)(iVar6 + 0x248) = 0x1e6;
  *(undefined *)(iVar6 + 0x3b8) = 0;
  __psq_l0(auStack8,uVar8);
  __psq_l1(auStack8,uVar8);
  __psq_l0(auStack24,uVar8);
  __psq_l1(auStack24,uVar8);
  return;
}


/* __stdcall dMsg2_stopProc(sub_msg2_class *) */

undefined4 dMsg2_stopProc(int param_1)

{
  if (*(char *)(param_1 + 0xedd) == '\0') {
    if ((_4298 < m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mStickMainPosY) ||
       (_4298 < m_Do_controller_pad::g_mDoCPd_cpadInfo[3].mStickMainPosY)) {
      if (*(int *)(param_1 + 0xec4) != 0) {
        *(undefined *)(param_1 + 0xedd) = 1;
        dMsg2_screenDataSet(param_1,*(undefined *)(param_1 + 0xe9e));
        *(undefined *)(param_1 + 0xec0) = 3;
        *(uint *)(param_1 + 0xec4) = *(int *)(param_1 + 0xec4) - (uint)*(byte *)(param_1 + 0x11a);
        *(undefined2 *)(param_1 + 0xf8) = 5;
        JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x803,(cXyz *)0x0,0,0,_4125,_4125,_4673,_4673,0)
        ;
      }
    }
    else {
      if (((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) != 0) ||
         ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mStickMainPosY < _4674 ||
          (m_Do_controller_pad::g_mDoCPd_cpadInfo[3].mStickMainPosY < _4674)))) {
        *(undefined *)(param_1 + 0xedd) = 2;
        dMsg2_screenDataSet(param_1,*(undefined *)(param_1 + 0xe9c));
        *(undefined *)(param_1 + 0xec0) = 1;
        *(uint *)(param_1 + 0xec4) = *(int *)(param_1 + 0xec4) + (uint)*(byte *)(param_1 + 0x11a);
        *(undefined2 *)(param_1 + 0xf8) = 5;
        JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x803,(cXyz *)0x0,0,0,_4125,_4125,_4673,_4673,0)
        ;
      }
      else {
        d_meter::dMeter_Info = 1;
      }
    }
  }
  else {
    dMsg2_stickInfoCheck();
  }
  return 1;
}


/* __stdcall dMsg2_closewaitProc(sub_msg2_class *) */

undefined4 dMsg2_closewaitProc(int param_1)

{
  if (*(char *)(param_1 + 0xedd) == '\0') {
    if ((_4298 < m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mStickMainPosY) ||
       (_4298 < m_Do_controller_pad::g_mDoCPd_cpadInfo[3].mStickMainPosY)) {
      if (*(int *)(param_1 + 0xec4) != 0) {
        *(undefined *)(param_1 + 0xedd) = 1;
        dMsg2_screenDataSet(param_1,*(undefined *)(param_1 + 0xe9e));
        *(undefined *)(param_1 + 0xec0) = 3;
        *(uint *)(param_1 + 0xec4) = *(int *)(param_1 + 0xec4) - (uint)*(byte *)(param_1 + 0x11a);
        *(undefined2 *)(param_1 + 0xf8) = 5;
        JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x803,(cXyz *)0x0,0,0,_4125,_4125,_4673,_4673,0)
        ;
      }
    }
    else {
      if (((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) != 0) ||
         ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mStickMainPosY < _4674 ||
          (m_Do_controller_pad::g_mDoCPd_cpadInfo[3].mStickMainPosY < _4674)))) {
        *(undefined *)(param_1 + 0xedd) = 2;
        JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x80d,(cXyz *)0x0,0,0,_4125,_4125,_4673,_4673,0)
        ;
        *(undefined2 *)(param_1 + 0xf8) = 0x10;
      }
      else {
        d_meter::dMeter_Info = 4;
      }
    }
  }
  else {
    dMsg2_stickInfoCheck();
  }
  return 1;
}


/* __stdcall dMsg2_openProc(sub_msg2_class *) */

undefined4 dMsg2_openProc(int param_1)

{
  double dVar1;
  
  if (*(int *)(param_1 + 0xe98) == 0) {
    dMsg2_messageOut(param_1,*(undefined *)(param_1 + 0xe9d),*(undefined4 *)(param_1 + 0xec4));
    if (*(char *)(param_1 + (uint)*(byte *)(param_1 + 0xe9d) * 0x2a0 + 0x398) == '\a') {
      dMsg2_messageOut(param_1,*(undefined *)(param_1 + 0xe9e),
                       *(int *)(param_1 + 0xec4) + (uint)*(byte *)(param_1 + 0x11a));
    }
  }
  else {
    if (*(int *)(param_1 + 0xe98) == dMsg2_popSpeed) {
      *(ushort *)(param_1 + 0xf8) =
           (ushort)*(byte *)(param_1 + (uint)*(byte *)(param_1 + 0xe9d) * 0x2a0 + 0x398);
    }
  }
  dVar1 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                            (dMsg2_popSpeed,*(undefined4 *)(param_1 + 0xe98),0);
  *(float *)(param_1 + 0xeac) = (float)((double)_4346 * dVar1);
  if (*(int *)(param_1 + 0xe98) != 0) {
    dMsg2_messageShow(param_1);
  }
  if (*(char *)(param_1 + (uint)*(byte *)(param_1 + 0xe9d) * 0x2a0 + 0x398) == '\a') {
    *(char *)(param_1 + 0xc55) = (char)(int)*(float *)(param_1 + 0xeac);
    *(char *)(param_1 + 0xc8d) = (char)(int)*(float *)(param_1 + 0xeac);
  }
  else {
    *(char *)(param_1 + 0xcc5) = (char)(int)*(float *)(param_1 + 0xeac);
    *(char *)(param_1 + 0xcfd) = (char)(int)*(float *)(param_1 + 0xeac);
  }
  dMsg2_aimAlphaSqrt(param_1,dMsg2_popSpeed,*(undefined4 *)(param_1 + 0xe98));
  d_com_inf_game::g_dComIfG_gameInfo.field_0x1d1c1 = (byte)(int)*(float *)(param_1 + 0xea8);
  *(int *)(param_1 + 0xe98) = *(int *)(param_1 + 0xe98) + 1;
  return 1;
}


/* __stdcall dMsg2_closeProc(sub_msg2_class *) */

undefined4 dMsg2_closeProc(int param_1)

{
  uint uVar1;
  double dVar2;
  
  if (*(int *)(param_1 + 0xe98) == 0) {
    for (uVar1 = 0; (uVar1 & 0xff) < 3; uVar1 = uVar1 + 1) {
      dMsg2_messagePaneHide(param_1,uVar1);
      dMsg2_outFontHide(param_1,uVar1);
    }
    JKRFileLoader::removeResource(*(void **)(param_1 + 0x90c),(JKRFileLoader *)0x0);
    *(undefined2 *)(param_1 + 0xf8) = 0x12;
  }
  *(int *)(param_1 + 0xe98) = *(int *)(param_1 + 0xe98) + -1;
  if (*(int *)(param_1 + 0xe98) < 0) {
    *(undefined4 *)(param_1 + 0xe98) = 0;
  }
  dVar2 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                            (dMsg2_popSpeed,*(undefined4 *)(param_1 + 0xe98),0);
  *(float *)(param_1 + 0xeac) = (float)((double)_4346 * dVar2);
  if (*(char *)(param_1 + 0xbe5) != '\0') {
    *(char *)(param_1 + 0xbe5) = (char)(int)*(float *)(param_1 + 0xeac);
    *(char *)(param_1 + 0xc1d) = (char)(int)*(float *)(param_1 + 0xeac);
  }
  if (*(char *)(param_1 + 0xc55) != '\0') {
    *(char *)(param_1 + 0xc55) = (char)(int)*(float *)(param_1 + 0xeac);
    *(char *)(param_1 + 0xc8d) = (char)(int)*(float *)(param_1 + 0xeac);
  }
  if (*(char *)(param_1 + 0xcc5) != '\0') {
    *(char *)(param_1 + 0xcc5) = (char)(int)*(float *)(param_1 + 0xeac);
    *(char *)(param_1 + 0xcfd) = (char)(int)*(float *)(param_1 + 0xeac);
  }
  dMsg2_aimAlphaSqare(param_1,dMsg2_popSpeed,*(undefined4 *)(param_1 + 0xe98));
  d_com_inf_game::g_dComIfG_gameInfo.field_0x1d1c1 = (byte)(int)*(float *)(param_1 + 0xea8);
  return 1;
}


/* __stdcall dMsg2_outwaitProc(sub_msg2_class *) */

undefined4 dMsg2_outwaitProc(int param_1)

{
  char cVar1;
  byte bVar2;
  undefined uVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  
  cVar1 = *(char *)(param_1 + 0xec0);
  if ((cVar1 == '\x01') || (cVar1 == '\x02')) {
    *(int *)(param_1 + 0xec8) = *(int *)(param_1 + 0xec8) + 0xc;
  }
  else {
    if ((cVar1 == '\x03') || (cVar1 == '\x04')) {
      *(int *)(param_1 + 0xec8) = *(int *)(param_1 + 0xec8) + -0xc;
    }
  }
  iVar5 = *(int *)(param_1 + 0xec8);
  if (iVar5 < 0x3fd) {
    if (iVar5 < -0x3fc) {
      *(int *)(param_1 + 0xec8) = iVar5 + 0x7f8;
    }
  }
  else {
    *(int *)(param_1 + 0xec8) = iVar5 + -0x7f8;
  }
  fVar4 = _4837;
  cVar1 = *(char *)(param_1 + 0xec0);
  if (cVar1 == '\x01') {
    bVar2 = *(byte *)(param_1 + 0xe9c);
    iVar5 = 0;
    iVar6 = 3;
    do {
      *(float *)(param_1 + iVar5 + 0x920) = *(float *)(param_1 + iVar5 + 0x920) - fVar4;
      iVar5 = iVar5 + 0x38;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    *(char *)(param_1 + 0xede) = *(char *)(param_1 + 0xede) + -0x55;
    if (*(float *)(param_1 + (uint)bVar2 * 0x38 + 0x920) < -*(float *)(param_1 + 0xe94)) {
      *(undefined *)(param_1 + 0xec0) = 2;
      uVar3 = *(undefined *)(param_1 + 0xe9d);
      *(undefined *)(param_1 + 0xe9d) = *(undefined *)(param_1 + 0xe9e);
      *(undefined *)(param_1 + 0xe9e) = *(undefined *)(param_1 + 0xe9c);
      *(undefined *)(param_1 + 0xe9c) = uVar3;
      if (*(char *)(param_1 + (uint)*(byte *)(param_1 + 0xe9d) * 0x2a0 + 0x398) == '\a') {
        dMsg2_messageOut(param_1,*(undefined *)(param_1 + 0xe9e),
                         *(int *)(param_1 + 0xec4) + (uint)*(byte *)(param_1 + 0x11a));
      }
      else {
        dMsg2_messagePaneHide(param_1,*(undefined *)(param_1 + 0xe9e));
        dMsg2_outFontHide(param_1,*(undefined *)(param_1 + 0xe9e));
      }
      *(undefined *)(param_1 + 0xede) = 0;
      dMsg2_arrowUpHide(param_1);
      dMsg2_arrowDownHide(param_1);
      dMsg2_dotHide(param_1);
    }
  }
  else {
    if (cVar1 == '\x03') {
      bVar2 = *(byte *)(param_1 + 0xe9e);
      iVar5 = 0;
      iVar6 = 3;
      do {
        *(float *)(param_1 + iVar5 + 0x920) = *(float *)(param_1 + iVar5 + 0x920) + fVar4;
        iVar5 = iVar5 + 0x38;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      *(char *)(param_1 + 0xede) = *(char *)(param_1 + 0xede) + -0x7f;
      if (*(float *)(param_1 + 0xd28) < *(float *)(param_1 + (uint)bVar2 * 0x38 + 0x920)) {
        *(undefined *)(param_1 + 0xec0) = 4;
        uVar3 = *(undefined *)(param_1 + 0xe9d);
        *(undefined *)(param_1 + 0xe9d) = *(undefined *)(param_1 + 0xe9c);
        *(undefined *)(param_1 + 0xe9c) = *(undefined *)(param_1 + 0xe9e);
        *(undefined *)(param_1 + 0xe9e) = uVar3;
        if (*(int *)(param_1 + 0xec4) < 1) {
          dMsg2_messagePaneHide(param_1,*(undefined *)(param_1 + 0xe9c));
          dMsg2_outFontHide(param_1,*(undefined *)(param_1 + 0xe9c));
        }
        else {
          dMsg2_messageOut(param_1,*(undefined *)(param_1 + 0xe9c),
                           *(int *)(param_1 + 0xec4) - (uint)*(byte *)(param_1 + 0x11a));
        }
        *(undefined *)(param_1 + 0xede) = 0;
        dMsg2_arrowUpHide(param_1);
        dMsg2_arrowDownHide(param_1);
        dMsg2_dotHide(param_1);
      }
    }
    else {
      if (cVar1 == '\x02') {
        iVar5 = 0;
        iVar6 = 3;
        do {
          *(float *)(param_1 + iVar5 + 0x920) = *(float *)(param_1 + iVar5 + 0x920) - fVar4;
          iVar5 = iVar5 + 0x38;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
        *(char *)(param_1 + 0xede) = *(char *)(param_1 + 0xede) + '+';
        if (*(float *)(param_1 + (uint)*(byte *)(param_1 + 0xe9d) * 0x38 + 0x920) <=
            *(float *)(param_1 + 0x918)) {
          *(float *)(param_1 + (uint)*(byte *)(param_1 + 0xe9c) * 0x38 + 0x920) =
               *(float *)(param_1 + 0x918) - *(float *)(param_1 + 0xe94);
          *(undefined4 *)(param_1 + (uint)*(byte *)(param_1 + 0xe9d) * 0x38 + 0x920) =
               *(undefined4 *)(param_1 + 0x918);
          *(float *)(param_1 + (uint)*(byte *)(param_1 + 0xe9e) * 0x38 + 0x920) =
               *(float *)(param_1 + 0x918) + *(float *)(param_1 + 0xe94);
          *(undefined *)(param_1 + 0xec0) = 0;
          if (*(char *)(param_1 + (uint)*(byte *)(param_1 + 0xe9d) * 0x2a0 + 0x398) == '\a') {
            *(undefined2 *)(param_1 + 0xf8) = 7;
            dMsg2_arrowDownShow(param_1);
          }
          else {
            *(undefined2 *)(param_1 + 0xf8) = 0xe;
            dMsg2_dotShow(param_1);
          }
          *(undefined *)(param_1 + 0xede) = 0xff;
          if (*(int *)(param_1 + 0xec4) != 0) {
            dMsg2_arrowUpShow(param_1);
          }
        }
        dMsg2_messageShow(param_1);
      }
      else {
        if (cVar1 == '\x04') {
          iVar5 = 0;
          iVar6 = 3;
          do {
            *(float *)(param_1 + iVar5 + 0x920) = *(float *)(param_1 + iVar5 + 0x920) + fVar4;
            iVar5 = iVar5 + 0x38;
            iVar6 = iVar6 + -1;
          } while (iVar6 != 0);
          *(char *)(param_1 + 0xede) = *(char *)(param_1 + 0xede) + '%';
          if (*(float *)(param_1 + 0x918) <=
              *(float *)(param_1 + (uint)*(byte *)(param_1 + 0xe9d) * 0x38 + 0x920)) {
            *(float *)(param_1 + (uint)*(byte *)(param_1 + 0xe9c) * 0x38 + 0x920) =
                 *(float *)(param_1 + 0x918) - *(float *)(param_1 + 0xe94);
            *(undefined4 *)(param_1 + (uint)*(byte *)(param_1 + 0xe9d) * 0x38 + 0x920) =
                 *(undefined4 *)(param_1 + 0x918);
            *(float *)(param_1 + (uint)*(byte *)(param_1 + 0xe9e) * 0x38 + 0x920) =
                 *(float *)(param_1 + 0x918) + *(float *)(param_1 + 0xe94);
            *(undefined *)(param_1 + 0xec0) = 0;
            *(undefined2 *)(param_1 + 0xf8) = 7;
            *(undefined *)(param_1 + 0xede) = 0xff;
            dMsg2_arrowDownShow(param_1);
            if (*(int *)(param_1 + 0xec4) != 0) {
              dMsg2_arrowUpShow(param_1);
            }
          }
          dMsg2_messageShow(param_1);
        }
        else {
          dMsg2_messageShow(param_1);
        }
      }
    }
  }
  return 1;
}

}

/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dDlst_2DMSG2_c::draw(void) */

void __thiscall dDlst_2DMSG2_c::draw(dDlst_2DMSG2_c *this)

{
  J2DOrthoGraph *pCtx;
  int iVar1;
  
  pCtx = d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph;
  (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph)->parent).vtbl)->setPort)
            (d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph);
  iVar1 = 0;
  do {
    *(undefined *)((&d_message::sScreen2)[2 - iVar1] + 0xcc) = 1;
    J2DScreen::draw((J2DScreen *)(&d_message::sScreen2)[2 - iVar1],d_message::_4069,d_message::_4069
                    ,&pCtx->parent);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 3);
  outFontDraw(this);
  return;
}


/* WARNING: Inlined function: __save_gpr */
/* WARNING: Inlined function: __restore_gpr */
/* WARNING: Removing unreachable block (ram,0x801e9f9c) */
/* WARNING: Removing unreachable block (ram,0x801e9fa4) */
/* __thiscall dDlst_2DMSG2_c::outFontDraw(void) */

void __thiscall dDlst_2DMSG2_c::outFontDraw(dDlst_2DMSG2_c *this)

{
  double dVar1;
  char cVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  undefined4 uVar20;
  undefined8 in_f30;
  double dVar21;
  undefined8 in_f31;
  double dVar22;
  double local_88;
  double local_80;
  double local_78;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar20 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  dVar22 = (double)*(float *)(*(int *)(*(int *)(this + 4) + 0xd00) + 0x20);
  dVar21 = (double)*(float *)(*(int *)(*(int *)(this + 4) + 0xd00) + 0x28);
  iVar11 = 0;
  iVar19 = 0;
  iVar18 = 0;
  iVar17 = 0;
  iVar16 = 0;
  do {
    iVar10 = 0;
    iVar15 = 0;
    iVar14 = 0;
    iVar13 = 0;
    do {
      iVar7 = *(int *)(this + 4);
      cVar2 = *(char *)(iVar16 + iVar7 + iVar10 + 0x39d);
      iVar8 = iVar16 + iVar7 + iVar13 + 0x11c;
      uVar12 = *(uint *)(iVar8 + 0x1e0);
      if (cVar2 != -1) {
        iVar5 = *(int *)(iVar17 + iVar7 + 0x910);
        local_88 = (double)CONCAT44(0x43300000,*(uint *)(iVar8 + 0x168) ^ 0x80000000);
        dVar1 = local_88 - d_message::_4264;
        fVar3 = *(float *)(iVar5 + 0x1c);
        if (*(int *)(iVar7 + 0xeb4) < (int)uVar12) {
          if (*(int *)(iVar18 + iVar7 + 0xecc) < 2) {
            local_78 = (double)CONCAT44(0x43300000,*(int *)(iVar7 + 0xeb0) << 2 ^ 0x80000000);
            local_80 = (double)CONCAT44(0x43300000,
                                        ((int)uVar12 >> 1) +
                                        (uint)((int)uVar12 < 0 && (uVar12 & 1) != 0) ^ 0x80000000);
            uVar9 = (uint)(((float)(local_78 - d_message::_4264) + *(float *)(iVar5 + 0x20)) -
                          (float)(local_80 - d_message::_4264));
          }
          else {
            local_80 = (double)CONCAT44(0x43300000,
                                        *(int *)(iVar7 + 0xeb0) * (3 - *(int *)(iVar8 + 0x1a4)) ^
                                        0x80000000);
            local_88 = (double)CONCAT44(0x43300000,
                                        ((int)uVar12 >> 1) +
                                        (uint)((int)uVar12 < 0 && (uVar12 & 1) != 0) ^ 0x80000000);
            uVar9 = (uint)(((float)(local_80 - d_message::_4264) + *(float *)(iVar5 + 0x20)) -
                          (float)(local_88 - d_message::_4264));
          }
        }
        else {
          local_78 = (double)CONCAT44(0x43300000,
                                      *(int *)(iVar7 + 0xeb0) *
                                      ((3 - *(int *)(iVar18 + iVar7 + 0xecc)) +
                                      *(int *)(iVar8 + 0x1a4) * 2) ^ 0x80000000);
          uVar9 = (uint)((float)(local_78 - d_message::_4264) + *(float *)(iVar5 + 0x20));
        }
        fVar4 = *(float *)(iVar7 + 0xeac);
        uVar6 = m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(iVar7 + 0x100));
        local_80 = (double)CONCAT44(0x43300000,uVar9 ^ 0x80000000);
        if (dVar22 < (double)(float)(local_80 - d_message::_4264)) {
          local_78 = (double)CONCAT44(0x43300000,uVar9 ^ 0x80000000);
          local_80 = (double)CONCAT44(0x43300000,uVar12 ^ 0x80000000);
          if ((float)(local_78 - d_message::_4264) <
              (float)(dVar21 - (double)(float)(local_80 - d_message::_4264))) {
            f_op_msg_mng::fopMsgM_outFontDraw
                      (*(undefined4 *)((int)&d_message::bbutton_icon + iVar14 + iVar18),
                       *(undefined4 *)((int)&d_message::bbutton_kage + iVar14 + iVar18),
                       (int)((float)dVar1 + fVar3),uVar9,uVar12,
                       (int)&d_message::bbuttonTimer + iVar15 + iVar19,(int)fVar4 & 0xff,cVar2);
          }
        }
        m_Do_ext::mDoExt_setCurrentHeap(uVar6);
      }
      iVar10 = iVar10 + 1;
      iVar15 = iVar15 + 6;
      iVar14 = iVar14 + 0xc;
      iVar13 = iVar13 + 4;
    } while (iVar10 < 8);
    iVar11 = iVar11 + 1;
    iVar19 = iVar19 + 2;
    iVar18 = iVar18 + 4;
    iVar17 = iVar17 + 0x38;
    iVar16 = iVar16 + 0x2a0;
  } while (iVar11 < 3);
  __psq_l0(auStack8,uVar20);
  __psq_l1(auStack8,uVar20);
  __psq_l0(auStack24,uVar20);
  __psq_l1(auStack24,uVar20);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall dDlst_2DCopy_c::draw(void) */

void __thiscall dDlst_2DCopy_c::draw(dDlst_2DCopy_c *this)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  J2DOrthoGraph *pCtx;
  uint uVar4;
  
  pCtx = d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph;
  (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph)->parent).vtbl)->setPort)
            (d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph);
  uVar4 = (uint)d_message::_4930;
  uVar1 = (uint)d_message::_4931;
  uVar2 = (uint)d_message::_4932;
  uVar3 = (uint)d_message::_4933;
  gx::GXSetScissor(uVar4,uVar1,uVar2,uVar3);
  J2DScreen::draw(d_message::sScreen2,d_message::_4069,d_message::_4069,&pCtx->parent);
  gx::GXSetTexCopySrc(uVar4 & 0xffff,uVar1 & 0xffff,uVar2 & 0xffff,uVar3 & 0xffff);
  gx::GXSetTexCopyDst(uVar2 & 0xffff,uVar3 & 0xffff,4,0);
  uVar4 = countLeadingZeros((int)d_s_play::g_regHIO.mChild[1].mShorts[6]);
  gx::GXCopyTex(*(undefined4 *)(this + 8),uVar4 >> 5);
  return;
}


namespace d_message {

/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __stdcall dMsg2_Draw(sub_msg2_class *) */

undefined4 dMsg2_Draw(int param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  fVar1 = _4961 + *(float *)(param_1 + 0xdac);
  fVar2 = _4962 + *(float *)(param_1 + 0xdb0);
  iVar3 = 0;
  iVar5 = 0;
  do {
    iVar4 = param_1 + iVar5;
    *(char *)(iVar4 + 0x945) = (char)(int)*(float *)(param_1 + 0xeac);
    *(char *)(iVar4 + 0xa95) = (char)(int)*(float *)(param_1 + 0xeac);
    *(char *)(iVar4 + 0x9ed) = (char)(int)*(float *)(param_1 + 0xeac);
    *(char *)(iVar4 + 0xb3d) = (char)(int)*(float *)(param_1 + 0xeac);
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(iVar4 + 0x910));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(iVar4 + 0xa60));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(iVar4 + 0x9b8));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(iVar4 + 0xb08));
    iVar3 = iVar3 + 1;
    iVar5 = iVar5 + 0x38;
  } while (iVar3 < 3);
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0xbb0));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0xbe8));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0xc20));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0xc58));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0xc90));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0xcc8));
  dMsg2_multiTexDraw(param_1,(int)(short)((short)(int)fVar1 + -0x120),
                     (int)(short)((short)(int)fVar2 + -0x78),0x240,0xf0);
  dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                    (dDlst_base_c *)&message);
  return 1;
}


/* WARNING: Inlined function: FUN_80328f20 */
/* WARNING: Inlined function: FUN_80328f6c */
/* WARNING: Removing unreachable block (ram,0x801ea7a4) */
/* __stdcall dMsg2_Execute(sub_msg2_class *) */

undefined4 dMsg2_Execute(int param_1)

{
  uint uVar1;
  uint uVar2;
  short sVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  undefined8 in_f31;
  double dVar11;
  undefined local_e8;
  undefined uStack231;
  undefined uStack230;
  undefined uStack229;
  undefined local_e4;
  undefined uStack227;
  undefined uStack226;
  undefined uStack225;
  undefined local_e0;
  undefined uStack223;
  undefined uStack222;
  undefined uStack221;
  undefined local_dc;
  undefined uStack219;
  undefined uStack218;
  undefined uStack217;
  undefined local_d8;
  undefined uStack215;
  undefined uStack214;
  undefined uStack213;
  undefined local_d4;
  undefined uStack211;
  undefined uStack210;
  undefined uStack209;
  undefined local_d0;
  undefined uStack207;
  undefined uStack206;
  undefined uStack205;
  undefined local_cc;
  undefined uStack203;
  undefined uStack202;
  undefined uStack201;
  undefined local_c4;
  undefined uStack195;
  undefined uStack194;
  undefined uStack193;
  undefined local_bc;
  undefined uStack187;
  undefined uStack186;
  undefined uStack185;
  undefined local_b4;
  undefined uStack179;
  undefined uStack178;
  undefined uStack177;
  undefined local_ac;
  undefined uStack171;
  undefined uStack170;
  undefined uStack169;
  undefined auStack8 [8];
  
  uVar10 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  sVar3 = *(short *)(param_1 + 0xf8);
  if (sVar3 == 2) {
    dMsg2_openProc();
  }
  else {
    if (sVar3 == 5) {
      dMsg2_outwaitProc();
    }
    else {
      if (sVar3 == 7) {
        dMsg2_stopProc();
      }
      else {
        if (sVar3 == 0xe) {
          dMsg2_closewaitProc();
        }
        else {
          if (sVar3 == 0x10) {
            dMsg2_closeProc();
          }
          else {
            if (sVar3 == 0x13) {
              f_op_msg_mng::fopMsgM_Delete();
            }
          }
        }
      }
    }
  }
  dMsg2_arrowMove(param_1);
  uVar5 = 0;
  if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mConfig._0_1_ != '\0') {
    uVar5 = 0xfffffffc;
  }
  iVar8 = 0;
  iVar7 = 0;
  dVar11 = _4264;
  do {
    iVar9 = param_1 + iVar7;
    uVar1 = (uint)(*(float *)(iVar9 + 0x91c) +
                  (float)((double)CONCAT44(0x43300000,(int)DAT_803e6c34 ^ 0x80000000) - dVar11));
    uVar2 = (uint)(*(float *)(iVar9 + 0x920) +
                  (float)((double)CONCAT44(0x43300000,uVar5 ^ 0x80000000) - dVar11));
    (**(code **)(**(int **)(iVar9 + 0x910) + 0x10))
              ((double)(float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - dVar11),
               (double)(float)((double)CONCAT44(0x43300000,uVar2 ^ 0x80000000) - dVar11));
    (**(code **)(**(int **)(iVar9 + 0xa60) + 0x10))
              ((double)(float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - dVar11),
               (double)(float)((double)CONCAT44(0x43300000,uVar2 - (int)DAT_803e6c14 ^ 0x80000000) -
                              dVar11));
    (**(code **)(**(int **)(iVar9 + 0x9b8) + 0x10))
              ((double)(float)((double)CONCAT44(0x43300000,uVar1 + 2 ^ 0x80000000) - dVar11),
               (double)(float)((double)CONCAT44(0x43300000,uVar2 + 2 ^ 0x80000000) - dVar11));
    (**(code **)(**(int **)(iVar9 + 0xb08) + 0x10))
              ((double)(float)((double)CONCAT44(0x43300000,uVar1 + 2 ^ 0x80000000) - dVar11),
               (double)(float)((double)CONCAT44(0x43300000,
                                                (uVar2 + 2) - (int)DAT_803e6c14 ^ 0x80000000) -
                              dVar11));
    iVar8 = iVar8 + 1;
    iVar7 = iVar7 + 0x38;
  } while (iVar8 < 3);
  dMsg2_rubySet(param_1);
  iVar7 = 0;
  iVar8 = 3;
  do {
    uVar4 = DAT_803e6be1;
    iVar9 = param_1 + iVar7;
    iVar6 = *(int *)(iVar9 + 0x910);
    local_ac = (undefined)((uint)DAT_803e6be1 >> 0x18);
    *(undefined *)(iVar6 + 0xd0) = local_ac;
    uStack171 = (undefined)((uint)uVar4 >> 0x10);
    *(undefined *)(iVar6 + 0xd1) = uStack171;
    uStack170 = (undefined)((uint)uVar4 >> 8);
    *(undefined *)(iVar6 + 0xd2) = uStack170;
    uStack169 = (undefined)uVar4;
    *(undefined *)(iVar6 + 0xd3) = uStack169;
    *(undefined *)(iVar6 + 0xd4) = local_ac;
    *(undefined *)(iVar6 + 0xd5) = uStack171;
    *(undefined *)(iVar6 + 0xd6) = uStack170;
    *(undefined *)(iVar6 + 0xd7) = uStack169;
    uVar4 = DAT_803e6bf9;
    iVar6 = *(int *)(iVar9 + 0xa60);
    local_b4 = (undefined)((uint)DAT_803e6bf9 >> 0x18);
    *(undefined *)(iVar6 + 0xd0) = local_b4;
    uStack179 = (undefined)((uint)uVar4 >> 0x10);
    *(undefined *)(iVar6 + 0xd1) = uStack179;
    uStack178 = (undefined)((uint)uVar4 >> 8);
    *(undefined *)(iVar6 + 0xd2) = uStack178;
    uStack177 = (undefined)uVar4;
    *(undefined *)(iVar6 + 0xd3) = uStack177;
    *(undefined *)(iVar6 + 0xd4) = local_b4;
    *(undefined *)(iVar6 + 0xd5) = uStack179;
    *(undefined *)(iVar6 + 0xd6) = uStack178;
    *(undefined *)(iVar6 + 0xd7) = uStack177;
    uVar4 = DAT_803e6bed;
    iVar6 = *(int *)(iVar9 + 0x9b8);
    local_bc = (undefined)((uint)DAT_803e6bed >> 0x18);
    *(undefined *)(iVar6 + 0xd0) = local_bc;
    uStack187 = (undefined)((uint)uVar4 >> 0x10);
    *(undefined *)(iVar6 + 0xd1) = uStack187;
    uStack186 = (undefined)((uint)uVar4 >> 8);
    *(undefined *)(iVar6 + 0xd2) = uStack186;
    uStack185 = (undefined)uVar4;
    *(undefined *)(iVar6 + 0xd3) = uStack185;
    *(undefined *)(iVar6 + 0xd4) = local_bc;
    *(undefined *)(iVar6 + 0xd5) = uStack187;
    *(undefined *)(iVar6 + 0xd6) = uStack186;
    *(undefined *)(iVar6 + 0xd7) = uStack185;
    uVar4 = DAT_803e6bed;
    iVar6 = *(int *)(iVar9 + 0xb08);
    local_c4 = (undefined)((uint)DAT_803e6bed >> 0x18);
    *(undefined *)(iVar6 + 0xd0) = local_c4;
    uStack195 = (undefined)((uint)uVar4 >> 0x10);
    *(undefined *)(iVar6 + 0xd1) = uStack195;
    uStack194 = (undefined)((uint)uVar4 >> 8);
    *(undefined *)(iVar6 + 0xd2) = uStack194;
    uStack193 = (undefined)uVar4;
    *(undefined *)(iVar6 + 0xd3) = uStack193;
    *(undefined *)(iVar6 + 0xd4) = local_c4;
    *(undefined *)(iVar6 + 0xd5) = uStack195;
    *(undefined *)(iVar6 + 0xd6) = uStack194;
    *(undefined *)(iVar6 + 0xd7) = uStack193;
    uVar4 = DAT_803e6be5;
    iVar6 = *(int *)(iVar9 + 0x910);
    local_cc = (undefined)((uint)DAT_803e6be5 >> 0x18);
    *(undefined *)(iVar6 + 0xf4) = local_cc;
    uStack203 = (undefined)((uint)uVar4 >> 0x10);
    *(undefined *)(iVar6 + 0xf5) = uStack203;
    uStack202 = (undefined)((uint)uVar4 >> 8);
    *(undefined *)(iVar6 + 0xf6) = uStack202;
    uStack201 = (undefined)uVar4;
    *(undefined *)(iVar6 + 0xf7) = uStack201;
    uVar4 = DAT_803e6bfd;
    iVar6 = *(int *)(iVar9 + 0xa60);
    local_d0 = (undefined)((uint)DAT_803e6bfd >> 0x18);
    *(undefined *)(iVar6 + 0xf4) = local_d0;
    uStack207 = (undefined)((uint)uVar4 >> 0x10);
    *(undefined *)(iVar6 + 0xf5) = uStack207;
    uStack206 = (undefined)((uint)uVar4 >> 8);
    *(undefined *)(iVar6 + 0xf6) = uStack206;
    uStack205 = (undefined)uVar4;
    *(undefined *)(iVar6 + 0xf7) = uStack205;
    uVar4 = DAT_803e6bf1;
    iVar6 = *(int *)(iVar9 + 0x9b8);
    local_d4 = (undefined)((uint)DAT_803e6bf1 >> 0x18);
    *(undefined *)(iVar6 + 0xf4) = local_d4;
    uStack211 = (undefined)((uint)uVar4 >> 0x10);
    *(undefined *)(iVar6 + 0xf5) = uStack211;
    uStack210 = (undefined)((uint)uVar4 >> 8);
    *(undefined *)(iVar6 + 0xf6) = uStack210;
    uStack209 = (undefined)uVar4;
    *(undefined *)(iVar6 + 0xf7) = uStack209;
    uVar4 = DAT_803e6bf1;
    iVar6 = *(int *)(iVar9 + 0xb08);
    local_d8 = (undefined)((uint)DAT_803e6bf1 >> 0x18);
    *(undefined *)(iVar6 + 0xf4) = local_d8;
    uStack215 = (undefined)((uint)uVar4 >> 0x10);
    *(undefined *)(iVar6 + 0xf5) = uStack215;
    uStack214 = (undefined)((uint)uVar4 >> 8);
    *(undefined *)(iVar6 + 0xf6) = uStack214;
    uStack213 = (undefined)uVar4;
    *(undefined *)(iVar6 + 0xf7) = uStack213;
    uVar4 = DAT_803e6be9;
    iVar6 = *(int *)(iVar9 + 0x910);
    local_dc = (undefined)((uint)DAT_803e6be9 >> 0x18);
    *(undefined *)(iVar6 + 0xf8) = local_dc;
    uStack219 = (undefined)((uint)uVar4 >> 0x10);
    *(undefined *)(iVar6 + 0xf9) = uStack219;
    uStack218 = (undefined)((uint)uVar4 >> 8);
    *(undefined *)(iVar6 + 0xfa) = uStack218;
    uStack217 = (undefined)uVar4;
    *(undefined *)(iVar6 + 0xfb) = uStack217;
    uVar4 = DAT_803e6c01;
    iVar6 = *(int *)(iVar9 + 0xa60);
    local_e0 = (undefined)((uint)DAT_803e6c01 >> 0x18);
    *(undefined *)(iVar6 + 0xf8) = local_e0;
    uStack223 = (undefined)((uint)uVar4 >> 0x10);
    *(undefined *)(iVar6 + 0xf9) = uStack223;
    uStack222 = (undefined)((uint)uVar4 >> 8);
    *(undefined *)(iVar6 + 0xfa) = uStack222;
    uStack221 = (undefined)uVar4;
    *(undefined *)(iVar6 + 0xfb) = uStack221;
    uVar4 = DAT_803e6bf5;
    iVar6 = *(int *)(iVar9 + 0x9b8);
    local_e4 = (undefined)((uint)DAT_803e6bf5 >> 0x18);
    *(undefined *)(iVar6 + 0xf8) = local_e4;
    uStack227 = (undefined)((uint)uVar4 >> 0x10);
    *(undefined *)(iVar6 + 0xf9) = uStack227;
    uStack226 = (undefined)((uint)uVar4 >> 8);
    *(undefined *)(iVar6 + 0xfa) = uStack226;
    uStack225 = (undefined)uVar4;
    *(undefined *)(iVar6 + 0xfb) = uStack225;
    uVar4 = DAT_803e6bf5;
    iVar9 = *(int *)(iVar9 + 0xb08);
    local_e8 = (undefined)((uint)DAT_803e6bf5 >> 0x18);
    *(undefined *)(iVar9 + 0xf8) = local_e8;
    uStack231 = (undefined)((uint)uVar4 >> 0x10);
    *(undefined *)(iVar9 + 0xf9) = uStack231;
    uStack230 = (undefined)((uint)uVar4 >> 8);
    *(undefined *)(iVar9 + 0xfa) = uStack230;
    uStack229 = (undefined)uVar4;
    *(undefined *)(iVar9 + 0xfb) = uStack229;
    iVar7 = iVar7 + 0x38;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  iVar7 = 0;
  iVar8 = 3;
  do {
    if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mConfig._0_1_ == '\0') {
      if (*(char *)(*(int *)(param_1 + 0xa98) + 0xaa) != '\0') {
        *(undefined *)(*(int *)(param_1 + iVar7 + 0xa60) + 0xaa) = 1;
      }
      iVar9 = *(int *)(param_1 + iVar7 + 0xb08);
      if (*(char *)(iVar9 + 0xaa) != '\0') {
        *(undefined *)(iVar9 + 0xaa) = 1;
      }
    }
    else {
      *(undefined *)(*(int *)(param_1 + iVar7 + 0xa60) + 0xaa) = 0;
      *(undefined *)(*(int *)(param_1 + iVar7 + 0xb08) + 0xaa) = 0;
    }
    iVar7 = iVar7 + 0x38;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  __psq_l0(auStack8,uVar10);
  __psq_l1(auStack8,uVar10);
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5bca = (byte)*(undefined2 *)(param_1 + 0xf8);
  return 1;
}


/* __stdcall dMsg2_IsDelete(sub_msg2_class *) */

undefined4 dMsg2_IsDelete(void)

{
  return 1;
}


/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* __stdcall dMsg2_Delete(sub_msg2_class *) */

undefined4 dMsg2_Delete(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5bca = 0;
  d_com_inf_game::g_dComIfG_gameInfo.field_0x1d1c1 = 0xff;
  uVar1 = m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0x100));
  iVar4 = 0;
  iVar5 = 0;
  do {
    piVar2 = *(int **)((int)&sScreen2 + iVar5);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2,1);
    }
    iVar4 = iVar4 + 1;
    iVar5 = iVar5 + 4;
  } while (iVar4 < 3);
  JKRHeap::free(*(JKRHeap **)(param_1 + 0x100),*(void **)(param_1 + 0xe58));
  JKRHeap::free(*(JKRHeap **)(param_1 + 0x100),*(void **)(param_1 + 0xe5c));
  m_Do_ext::mDoExt_removeMesgFont();
  m_Do_ext::mDoExt_removeRubyFont();
  iVar4 = 0;
  iVar5 = 0;
  do {
    iVar3 = 0;
    iVar6 = 0;
    do {
      piVar2 = *(int **)((int)&bbutton_icon + iVar6 + iVar5);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2,1);
      }
      piVar2 = *(int **)((int)&bbutton_kage + iVar6 + iVar5);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2,1);
      }
      iVar3 = iVar3 + 1;
      iVar6 = iVar6 + 0xc;
    } while (iVar3 < 8);
    iVar3 = param_1 + iVar5;
    JKRHeap::free(*(JKRHeap **)(param_1 + 0x100),*(void **)(iVar3 + 0xe64));
    JKRHeap::free(*(JKRHeap **)(param_1 + 0x100),*(void **)(iVar3 + 0xe70));
    JKRHeap::free(*(JKRHeap **)(param_1 + 0x100),*(void **)(iVar3 + 0xe7c));
    JKRHeap::free(*(JKRHeap **)(param_1 + 0x100),*(void **)(iVar3 + 0xe88));
    iVar4 = iVar4 + 1;
    iVar5 = iVar5 + 4;
  } while (iVar4 < 3);
  (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpMsgArchive)->parent).parent.vtbl)->
            removeResourceAll)();
  JKRHeap::freeAll(*(JKRHeap **)(param_1 + 0x100));
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 = 0;
  m_Do_ext::mDoExt_setCurrentHeap(uVar1);
  return 1;
}


/* WARNING: Inlined function: FUN_80328f20 */
/* WARNING: Inlined function: FUN_80328f6c */
/* __stdcall dMsg2_Create(msg_class *) */

undefined4 dMsg2_Create(int param_1)

{
  undefined4 uVar1;
  J2DPane *this;
  void *pvVar2;
  ulong uVar3;
  J2DPicture *pJVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  byte bVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  TBox2_float_ local_58;
  undefined4 local_48;
  undefined2 local_44;
  undefined2 local_42;
  undefined2 local_40;
  undefined2 local_3e;
  undefined local_3c;
  undefined local_3b;
  undefined local_3a;
  undefined local_39;
  undefined local_38;
  undefined local_37;
  undefined local_36;
  undefined local_35;
  undefined local_34;
  undefined local_33;
  undefined local_32;
  undefined local_31;
  
  if ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 == 0) ||
     (d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 == 8)) {
    *(JKRExpHeap **)(param_1 + 0x100) = d_com_inf_game::g_dComIfG_gameInfo.field_0x5c1c;
    d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 = 8;
    uVar1 = m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0x100));
    bVar9 = 0;
    while( true ) {
      if (2 < bVar9) break;
      this = (J2DPane *)JKernel::operator_new(0xd4);
      if (this != (J2DPane *)0x0) {
        local_58.mTL.x = _4069;
        local_58.mTL.y = _4069;
        local_58.mBR.x = _5399;
        local_58.mBR.y = _5400;
        J2DPane::J2DPane(this,(J2DPane *)0x0,true,0x726f6f74,&local_58);
        this->vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
        *(undefined4 *)this[1].mMagic = 0xffffffff;
        *(undefined *)&this[1].vtbl = 0;
      }
      (&sScreen2)[bVar9] = this;
      J2DScreen::set((J2DScreen *)(&sScreen2)[bVar9],"hukidashi_02.blo",
                     d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpMsgArchive);
      bVar9 = bVar9 + 1;
    }
    pvVar2 = JKRHeap::alloc(*(JKRHeap **)(param_1 + 0x100),0x11800,0x20);
    *(void **)(param_1 + 0xe58) = pvVar2;
    if (*(int *)(param_1 + 0xe58) == 0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_message.cpp",0x8e2,"i_Msg->Tex[0] != 0");
      m_Do_printf::OSPanic("d_message.cpp",0x8e2,&DAT_80360c6a);
    }
    pvVar2 = JKRHeap::alloc(*(JKRHeap **)(param_1 + 0x100),0x11800,0x20);
    *(void **)(param_1 + 0xe5c) = pvVar2;
    if (*(int *)(param_1 + 0xe5c) == 0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_message.cpp",0x8e4,"i_Msg->Tex[1] != 0");
      m_Do_printf::OSPanic("d_message.cpp",0x8e4,&DAT_80360c6a);
    }
    dMsg2_fontdataInit(param_1);
    bVar9 = 0;
    while( true ) {
      if (2 < bVar9) break;
      iVar8 = 0;
      iVar7 = 0;
      iVar5 = 0;
      puVar11 = &bbutton_icon + bVar9;
      puVar10 = &bbutton_kage + bVar9;
      do {
        pJVar4 = (J2DPicture *)JKernel::operator_new(0x124);
        if (pJVar4 != (J2DPicture *)0x0) {
          J2DPicture::J2DPicture(pJVar4,"font_07_02.bti");
        }
        *(J2DPicture **)((int)puVar11 + iVar5) = pJVar4;
        pJVar4 = (J2DPicture *)JKernel::operator_new(0x124);
        if (pJVar4 != (J2DPicture *)0x0) {
          J2DPicture::J2DPicture(pJVar4,"font_07_02.bti");
        }
        *(J2DPicture **)((int)puVar10 + iVar5) = pJVar4;
        f_op_msg_mng::fopMsgM_blendInit(*(undefined4 *)((int)puVar11 + iVar5),"font_00.bti");
        f_op_msg_mng::fopMsgM_blendInit(*(undefined4 *)((int)puVar10 + iVar5),"font_00.bti");
        *(undefined *)(*(int *)((int)puVar11 + iVar5) + 0xaa) = 0;
        *(undefined *)(*(int *)((int)puVar10 + iVar5) + 0xaa) = 0;
        *(undefined *)(*(int *)((int)puVar11 + iVar5) + 0xac) = 0;
        *(undefined *)(*(int *)((int)puVar10 + iVar5) + 0xac) = 0;
        *(undefined2 *)((int)&bbuttonTimer + iVar7 + (uint)bVar9 * 2) = 0xffff;
        iVar8 = iVar8 + 1;
        iVar7 = iVar7 + 6;
        iVar5 = iVar5 + 0xc;
      } while (iVar8 < 8);
      bVar9 = bVar9 + 1;
    }
    for (bVar9 = 0; bVar9 < 3; bVar9 = bVar9 + 1) {
      pvVar2 = JKRHeap::alloc(*(JKRHeap **)(param_1 + 0x100),0x3e9,4);
      iVar5 = param_1 + (uint)bVar9 * 4;
      *(void **)(iVar5 + 0xe64) = pvVar2;
      if (*(int *)(iVar5 + 0xe64) == 0) {
        uVar3 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar3,"d_message.cpp",0x8fb,"i_Msg->output_text[i] != 0");
        m_Do_printf::OSPanic("d_message.cpp",0x8fb,&DAT_80360c6a);
      }
      pvVar2 = JKRHeap::alloc(*(JKRHeap **)(param_1 + 0x100),0x3e9,4);
      *(void **)(iVar5 + 0xe70) = pvVar2;
      if (*(int *)(iVar5 + 0xe70) == 0) {
        uVar3 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar3,"d_message.cpp",0x8fe,"i_Msg->output_ruby[i] != 0");
        m_Do_printf::OSPanic("d_message.cpp",0x8fe,&DAT_80360c6a);
      }
      pvVar2 = JKRHeap::alloc(*(JKRHeap **)(param_1 + 0x100),0x3e9,4);
      *(void **)(iVar5 + 0xe7c) = pvVar2;
      if (*(int *)(iVar5 + 0xe7c) == 0) {
        uVar3 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar3,"d_message.cpp",0x901,"i_Msg->output_textSdw[i] != 0");
        m_Do_printf::OSPanic("d_message.cpp",0x901,&DAT_80360c6a);
      }
      pvVar2 = JKRHeap::alloc(*(JKRHeap **)(param_1 + 0x100),0x3e9,4);
      *(void **)(iVar5 + 0xe88) = pvVar2;
      if (*(int *)(iVar5 + 0xe88) == 0) {
        uVar3 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar3,"d_message.cpp",0x904,"i_Msg->output_rubySdw[i] != 0");
        m_Do_printf::OSPanic("d_message.cpp",0x904,&DAT_80360c6a);
      }
    }
    m_Do_ext::mDoExt_setCurrentHeap(uVar1);
    if ((*(int *)(param_1 + 0xec) == 0x33a) &&
       (iVar5 = dSv_event_c::isEventBit
                          (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x2d80),
       iVar5 != 0)) {
      *(undefined4 *)(param_1 + 0xec) = 0x33b;
    }
    uVar1 = fopMsgM_msgGet_c::getMesgHeader
                      ((fopMsgM_msgGet_c *)(param_1 + 0x8fc),*(ulong *)(param_1 + 0xec));
    *(undefined4 *)(param_1 + 0x90c) = uVar1;
    if (*(int *)(param_1 + 0x90c) == 0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_message.cpp",0x914,"i_Msg->head_p");
      m_Do_printf::OSPanic("d_message.cpp",0x914,&DAT_80360c6a);
    }
    uVar1 = fopMsgM_msgGet_c::getMessage
                      ((fopMsgM_msgGet_c *)(param_1 + 0x8fc),*(mesg_header **)(param_1 + 0x90c));
    *(undefined4 *)(param_1 + 0xe60) = uVar1;
    fopMsgM_msgGet_c::getMesgEntry((fopMsgM_msgGet_c *)&local_48,(mesg_header *)(param_1 + 0x8fc));
    *(undefined4 *)(param_1 + 0x104) = local_48;
    *(undefined2 *)(param_1 + 0x108) = local_44;
    *(undefined2 *)(param_1 + 0x10a) = local_42;
    *(undefined2 *)(param_1 + 0x10c) = local_40;
    *(undefined2 *)(param_1 + 0x10e) = local_3e;
    *(undefined *)(param_1 + 0x110) = local_3c;
    *(undefined *)(param_1 + 0x111) = local_3b;
    *(undefined *)(param_1 + 0x112) = local_3a;
    *(undefined *)(param_1 + 0x113) = local_39;
    *(undefined *)(param_1 + 0x114) = local_38;
    *(undefined *)(param_1 + 0x115) = local_37;
    *(undefined *)(param_1 + 0x116) = local_36;
    *(undefined *)(param_1 + 0x117) = local_35;
    *(undefined *)(param_1 + 0x118) = local_34;
    *(undefined *)(param_1 + 0x119) = local_33;
    *(undefined *)(param_1 + 0x11a) = local_32;
    *(undefined *)(param_1 + 0x11b) = local_31;
    *(uint *)(param_1 + 0xea0) =
         (uint)*(ushort *)(param_1 + 0x904) << 8 | (uint)*(ushort *)(param_1 + 0x908);
    *(undefined2 *)(param_1 + 0xf8) = 2;
    dMsg2_multiTexInit(param_1);
    for (uVar6 = 0; (uVar6 & 0xff) < 3; uVar6 = uVar6 + 1) {
      dMsg2_screenDataInit(param_1,uVar6);
      dMsg2_screenDataSet(param_1,uVar6);
      dMsg2_messagePaneHide(param_1,uVar6);
    }
    dMsg2_ScreenDataValueInit(param_1);
    dMsg2_stickInfoInit(param_1);
    *(undefined *)(param_1 + 0xec0) = 0;
    *(undefined *)(param_1 + 0xe9c) = 2;
    *(undefined *)(param_1 + 0xe9d) = 0;
    *(undefined *)(param_1 + 0xe9e) = 1;
    dMsg2_popSpeed = (uint)DAT_803e6c17;
    d_com_inf_game::g_dComIfG_gameInfo.field_0x5bca = (byte)*(undefined2 *)(param_1 + 0xf8);
    uVar1 = 4;
    iRam803f7058 = param_1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

}

/* __thiscall dDlst_2DCopy_c::~dDlst_2DCopy_c(void) */

void __thiscall dDlst_2DCopy_c::_dDlst_2DCopy_c(dDlst_2DCopy_c *this)

{
  short in_r4;
  
  if (this != (dDlst_2DCopy_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dDlst_2DCopy_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dDlst_2DMSG2_c::~dDlst_2DMSG2_c(void) */

void __thiscall dDlst_2DMSG2_c::_dDlst_2DMSG2_c(dDlst_2DMSG2_c *this)

{
  short in_r4;
  
  if (this != (dDlst_2DMSG2_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dDlst_2DMSG2_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


namespace d_message {

void __sinit_d_message_cpp(void)

{
  message = &::dDlst_2DMSG2_c::__vt;
  Runtime.PPCEABI.H::__register_global_object(&message,::dDlst_2DMSG2_c::_dDlst_2DMSG2_c,&_3999);
  board = &dDlst_2Dm_c::__vt;
  Runtime.PPCEABI.H::__register_global_object(&board,dDlst_2Dm_c::_dDlst_2Dm_c,&_4000);
  capture = &::dDlst_2DCopy_c::__vt;
  Runtime.PPCEABI.H::__register_global_object(&capture,::dDlst_2DCopy_c::_dDlst_2DCopy_c,&_4001);
  return;
}

