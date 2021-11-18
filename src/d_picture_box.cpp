#include <d_picture_box.h>
#include <d_save.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <f_op_msg_mng.h>
#include <d_picture_box.h>
#include <J2DGraph/J2DTextBox.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <J2DGraph/J2DPicture.h>
#include <m_Do_graphic.h>
#include <d_meter.h>
#include <d_snap.h>
#include <os/OSCache.h>
#include <gx/GXTransform.h>
#include <gx/GXLight.h>
#include <gx/GXAttr.h>
#include <gx/GXTev.h>
#include <gx/GXPixel.h>
#include <gx/GXGeometry.h>
#include <gx/GXBump.h>
#include <mtx/mtx44.h>
#include <gx/GXTexture.h>
#include <gx/GXMisc.h>
#include <d_camera.h>
#include <d_lib.h>
#include <m_Do_MemCardRWmng.h>
#include <JKernel/JKRAram.h>
#include <MSL_C.PPCEABI.bare.H/s_sin.h>
#include <MSL_C.PPCEABI.bare.H/s_cos.h>
#include <J2DGraph/J2DOrthoGraph.h>
#include <JKernel/JKRFileLoader.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <MSL_C.PPCEABI.bare.H/printf.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <JKernel/JKRHeap.h>
#include <J2DGraph/J2DPane.h>
#include <J2DGraph/J2DScreen.h>
#include <m_Do_ext.h>
#include <m_Do_dvd_thread.h>
#include <d_drawlist.h>
#include <dJle_Pb_c.h>


namespace d_picture_box {
}

namespace d_picture_box {
undefined1 init$4902;

/* __stdcall dPb_erasePicture(void) */

void dPb_erasePicture(void)

{
  ushort uVar1;
  uint uVar2;
  
  uVar2 = (uint)d_com_inf_game::g_dComIfG_gameInfo._23553_1_;
  uVar1 = dSv_event_c::getEventReg(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x89ff);
  if (uVar2 < 3) {
    dSv_event_c::setEventReg
              (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x89ff,
               (byte)uVar1 | (byte)(1 << uVar2));
    d_com_inf_game::g_dComIfG_gameInfo.mPlay._18654_2_ =
         d_com_inf_game::g_dComIfG_gameInfo.mPlay._18654_2_ + -1;
  }
  return;
}

}

/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall dJle_Pb_c::screenSet(void) */

void __thiscall dJle_Pb_c::screenSet(dJle_Pb_c *this)

{
  float fVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  dJle_Pb_c *pdVar5;
  int iVar6;
  int iVar7;
  dJle_Pb_c local_38;
  dJle_Pb_c dStack55;
  dJle_Pb_c dStack54;
  dJle_Pb_c dStack53;
  dJle_Pb_c local_34;
  dJle_Pb_c dStack51;
  dJle_Pb_c dStack50;
  dJle_Pb_c dStack49;
  dJle_Pb_c local_30;
  dJle_Pb_c dStack47;
  dJle_Pb_c dStack46;
  dJle_Pb_c dStack45;
  dJle_Pb_c local_2c;
  dJle_Pb_c dStack43;
  dJle_Pb_c dStack42;
  dJle_Pb_c dStack41;
  
  iVar4 = 0;
  iVar6 = 0;
  iVar7 = 0;
  do {
    pdVar5 = this + iVar7;
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(pdVar5 + 0x2b0),*(J2DScreen **)(this + 8),
               *(int *)((int)&d_picture_box::sb_l_4135 + iVar6));
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(pdVar5 + 0x10),*(J2DScreen **)(this + 8),
               *(int *)((int)&d_picture_box::st_l_4136 + iVar6));
    *(short *)(pdVar5 + 0x2e6) = (short)(int)*(float *)(*(int *)(pdVar5 + 0x2b0) + 0xa4);
    iVar4 = iVar4 + 1;
    iVar6 = iVar6 + 4;
    iVar7 = iVar7 + 0x38;
  } while (iVar4 < 0xc);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x550),*(J2DScreen **)(this + 4),0x796c6967);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x588),*(J2DScreen **)(this + 4),0x796c6566);
  iVar4 = 0;
  iVar6 = 0;
  iVar7 = 0;
  do {
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(this + iVar7 + 0x5c0),*(J2DScreen **)(this + 4),
               *(int *)((int)&d_picture_box::icn_l_4137 + iVar6));
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(this + iVar7 + 0x668),*(J2DScreen **)(this + 4),
               *(int *)((int)&d_picture_box::emp_l_4138 + iVar6));
    iVar4 = iVar4 + 1;
    iVar6 = iVar6 + 4;
    iVar7 = iVar7 + 0x38;
  } while (iVar4 < 3);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x710),*(J2DScreen **)(this + 4),0x637431);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0x748),*(J2DScreen **)(this + 4),0x637432);
  iVar4 = 0;
  iVar6 = 0;
  iVar7 = 0;
  do {
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(this + iVar7 + 0x780),*(J2DScreen **)(this + 4),
               *(int *)((int)&d_picture_box::sp_l_4139 + iVar6));
    iVar4 = iVar4 + 1;
    iVar6 = iVar6 + 4;
    iVar7 = iVar7 + 0x38;
  } while (iVar4 < 8);
  iVar4 = 0;
  iVar7 = 0;
  iVar6 = 0;
  do {
    pdVar5 = this + iVar6;
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(pdVar5 + 0x940),*(J2DScreen **)(this + 4),
               *(int *)((int)&d_picture_box::no_l_4140 + iVar7));
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(pdVar5 + 0x9e8),*(J2DScreen **)(this + 4),
               *(int *)("no3no1bno2bno3bno1kno2kno3k/res/Photo/KOKUOU.DDS" + iVar7 + 3));
    f_op_msg_mng::fopMsgM_setPaneData
              ((fopMsgM_pane_class *)(pdVar5 + 0xa90),*(J2DScreen **)(this + 4),
               *(int *)("no3no1bno2bno3bno1kno2kno3k/res/Photo/KOKUOU.DDS" + iVar7 + 0xf));
    iVar4 = iVar4 + 1;
    iVar7 = iVar7 + 4;
    iVar6 = iVar6 + 0x38;
  } while (iVar4 < 3);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0xb38),*(J2DScreen **)(this + 4),0x6231);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0xb70),*(J2DScreen **)(this + 4),0x6232);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0xba8),*(J2DScreen **)(this + 4),0x776e756d);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0xbe0),*(J2DScreen **)(this + 4),0x776e756b);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0xc18),*(J2DScreen **)(this + 4),0x77706261);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0xc50),*(J2DScreen **)(this + 4),0x77626170);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0xc88),*(J2DScreen **)(this + 4),0x77707363);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0xcc0),*(J2DScreen **)(this + 4),0x7972746e);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0xcf8),*(J2DScreen **)(this + 4),0x797a6f6d);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0xd30),*(J2DScreen **)(this + 4),0x6372746e);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0xd68),*(J2DScreen **)(this + 4),0x637a6f6d);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0xda0),*(J2DScreen **)(this + 4),0x6c72746e);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0xdd8),*(J2DScreen **)(this + 4),0x727a6f6d);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0xe10),*(J2DScreen **)(this + 4),0x73687574);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0xe48),*(J2DScreen **)(this + 4),0x66643030);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0xf28),*(J2DScreen **)(this + 4),0x77703033);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0xef0),*(J2DScreen **)(this + 4),0x77703032);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0xeb8),*(J2DScreen **)(this + 4),0x77703031);
  f_op_msg_mng::fopMsgM_setPaneData
            ((fopMsgM_pane_class *)(this + 0xe80),*(J2DScreen **)(this + 4),0x77703034);
  uVar2 = *(undefined4 *)(*(int *)(this + 0x5c0) + 0x104);
  local_2c = SUB41((uint)uVar2 >> 0x18,0);
  this[0x125c] = local_2c;
  dStack43 = SUB41((uint)uVar2 >> 0x10,0);
  this[0x125d] = dStack43;
  dStack42 = SUB41((uint)uVar2 >> 8,0);
  this[0x125e] = dStack42;
  dStack41 = SUB41(uVar2,0);
  this[0x125f] = dStack41;
  uVar2 = *(undefined4 *)(*(int *)(this + 0x5c0) + 0x108);
  local_30 = SUB41((uint)uVar2 >> 0x18,0);
  this[0x1260] = local_30;
  dStack47 = SUB41((uint)uVar2 >> 0x10,0);
  this[0x1261] = dStack47;
  dStack46 = SUB41((uint)uVar2 >> 8,0);
  this[0x1262] = dStack46;
  dStack45 = SUB41(uVar2,0);
  this[0x1263] = dStack45;
  uVar2 = *(undefined4 *)(*(int *)(this + 0x668) + 0x104);
  local_34 = SUB41((uint)uVar2 >> 0x18,0);
  this[0x1264] = local_34;
  dStack51 = SUB41((uint)uVar2 >> 0x10,0);
  this[0x1265] = dStack51;
  dStack50 = SUB41((uint)uVar2 >> 8,0);
  this[0x1266] = dStack50;
  dStack49 = SUB41(uVar2,0);
  this[0x1267] = dStack49;
  uVar2 = *(undefined4 *)(*(int *)(this + 0x668) + 0x108);
  local_38 = SUB41((uint)uVar2 >> 0x18,0);
  this[0x1268] = local_38;
  dStack55 = SUB41((uint)uVar2 >> 0x10,0);
  this[0x1269] = dStack55;
  dStack54 = SUB41((uint)uVar2 >> 8,0);
  this[0x126a] = dStack54;
  dStack53 = SUB41(uVar2,0);
  this[0x126b] = dStack53;
  *(float *)(this + 0xcd4) = *(float *)(this + 0xcd4) - d_picture_box::_4201;
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0xcc0),(double)d_picture_box::_4202,
             (double)d_picture_box::_4202);
  *(float *)(this + 0xd0c) = *(float *)(this + 0xd0c) - d_picture_box::_4201;
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0xcf8),(double)d_picture_box::_4202,
             (double)d_picture_box::_4202);
  *(float *)(this + 0xd44) = *(float *)(this + 0xd44) - d_picture_box::_4201;
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0xd30),(double)d_picture_box::_4202,
             (double)d_picture_box::_4202);
  *(float *)(this + 0xd7c) = *(float *)(this + 0xd7c) - d_picture_box::_4201;
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0xd68),(double)d_picture_box::_4202,
             (double)d_picture_box::_4202);
  shutterHide(this);
  f_op_msg_mng::fopMsgM_blendInit((fopMsgM_pane_class *)(this + 0xd30),"font_09_02.bti");
  f_op_msg_mng::fopMsgM_blendInit((fopMsgM_pane_class *)(this + 0xd68),"font_09_02.bti");
  fVar1 = *(float *)(this + 0xd90) * d_picture_box::_4203;
  piVar3 = *(int **)(this + 0xd68);
  piVar3[0x27] = (int)(*(float *)(this + 0xd8c) * d_picture_box::_4203);
  piVar3[0x28] = (int)fVar1;
  *(undefined *)(piVar3 + 0x2a) = 0x7a;
  piVar3[0x29] = (int)d_picture_box::_4204;
  (**(code **)(*piVar3 + 0x20))();
  f_op_msg_mng::fopMsgM_blendInit((fopMsgM_pane_class *)(this + 0x550),"cursor_00_02.bti");
  f_op_msg_mng::fopMsgM_blendInit((fopMsgM_pane_class *)(this + 0x588),"cursor_00_02.bti");
  f_op_msg_mng::fopMsgM_blendInit((fopMsgM_pane_class *)(this + 0xcc0),"cursor_00_02.bti");
  f_op_msg_mng::fopMsgM_blendInit((fopMsgM_pane_class *)(this + 0xcf8),"cursor_00_02.bti");
  return;
}


/* __thiscall dJle_Pb_c::screenSet2(void) */

void __thiscall dJle_Pb_c::screenSet2(dJle_Pb_c *this)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  
  iVar3 = (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x797a3830);
  *(undefined *)(iVar3 + 0xaa) = 0;
  iVar3 = (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x64743830);
  *(undefined *)(iVar3 + 0xaa) = 0;
  uVar4 = (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x74783832);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0xf60),uVar4);
  uVar4 = (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x74783833);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0xf68),uVar4);
  uVar4 = (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x74783830);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0xf70),uVar4);
  uVar4 = (**(code **)(**(int **)(this + 0xc) + 0x30))(*(int **)(this + 0xc),0x74783831);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(this + 0xf78),uVar4);
  if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mConfig._0_1_ != '\0') {
    piVar5 = *(int **)(this + 0xf60);
    (**(code **)(*piVar5 + 0x10))
              ((double)(float)piVar5[3],(double)((float)piVar5[4] - d_picture_box::_4292));
    piVar5 = *(int **)(this + 0xf70);
    (**(code **)(*piVar5 + 0x10))
              ((double)(float)piVar5[3],(double)((float)piVar5[4] - d_picture_box::_4292));
  }
  piVar5 = *(int **)(this + 0xf68);
  (**(code **)(*piVar5 + 0x10))
            ((double)(float)piVar5[3],(double)((float)piVar5[4] - d_picture_box::_4293));
  piVar5 = *(int **)(this + 0xf78);
  (**(code **)(*piVar5 + 0x10))
            ((double)(float)piVar5[3],(double)((float)piVar5[4] - d_picture_box::_4293));
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0xf60),*(JUTFont **)(this + 0xf90));
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0xf68),*(JUTFont **)(this + 0xf94));
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0xf70),*(JUTFont **)(this + 0xf90));
  J2DTextBox::setFont(*(J2DTextBox **)(this + 0xf78),*(JUTFont **)(this + 0xf94));
  fVar1 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e6bb4 ^ 0x80000000) - d_picture_box::_4296
                 );
  iVar3 = *(int *)(this + 0xf60);
  fVar2 = d_picture_box::_4202;
  if (d_picture_box::_4202 < fVar1) {
    fVar2 = fVar1;
  }
  *(float *)(iVar3 + 0xe8) = fVar2;
  fVar2 = d_picture_box::_4202;
  if (d_picture_box::_4202 < fVar1) {
    fVar2 = fVar1;
  }
  *(float *)(iVar3 + 0xec) = fVar2;
  iVar3 = *(int *)(this + 0xf70);
  fVar2 = d_picture_box::_4202;
  if (d_picture_box::_4202 < fVar1) {
    fVar2 = fVar1;
  }
  *(float *)(iVar3 + 0xe8) = fVar2;
  fVar2 = d_picture_box::_4202;
  if (d_picture_box::_4202 < fVar1) {
    fVar2 = fVar1;
  }
  *(float *)(iVar3 + 0xec) = fVar2;
  fVar1 = d_picture_box::_4202;
  *(float *)(*(int *)(this + 0xf60) + 0xe0) = d_picture_box::_4202;
  *(float *)(*(int *)(this + 0xf68) + 0xe0) = fVar1;
  *(float *)(*(int *)(this + 0xf70) + 0xe0) = fVar1;
  *(float *)(*(int *)(this + 0xf78) + 0xe0) = fVar1;
  fVar1 = d_picture_box::_4294;
  *(float *)(*(int *)(this + 0xf60) + 0xe4) = d_picture_box::_4294;
  *(float *)(*(int *)(this + 0xf70) + 0xe4) = fVar1;
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dJle_Pb_c::cameraAlphaInc(float) */

void __thiscall dJle_Pb_c::cameraAlphaInc(dJle_Pb_c *this,float param_1)

{
  int iVar1;
  int iVar2;
  double dVar3;
  
  dVar3 = (double)param_1;
  iVar1 = 0;
  iVar2 = 0;
  do {
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + iVar2 + 0x2b0),(float)dVar3);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + iVar2 + 0x10),(float)dVar3);
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x38;
  } while (iVar1 < 0xc);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xba8),(float)dVar3);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xbe0),(float)dVar3);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xc18),(float)dVar3);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xc50),(float)dVar3);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xc88),(float)dVar3);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xcc0),(float)dVar3);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xcf8),(float)dVar3);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xd30),(float)dVar3);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xd68),(float)dVar3);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xda0),(float)dVar3);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xdd8),(float)dVar3);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xe48),(float)dVar3);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xf28),(float)dVar3);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xef0),(float)dVar3);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xeb8),(float)dVar3);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xe80),(float)dVar3);
  f_op_msg_mng::fopMsgM_setNowAlpha(dVar3,this + 0xf60);
  f_op_msg_mng::fopMsgM_setNowAlpha(dVar3,this + 0xf68);
  f_op_msg_mng::fopMsgM_setNowAlpha(dVar3,this + 0xf70);
  f_op_msg_mng::fopMsgM_setNowAlpha(dVar3,this + 0xf78);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dJle_Pb_c::browseAlphaInc(float) */

void __thiscall dJle_Pb_c::browseAlphaInc(dJle_Pb_c *this,float param_1)

{
  int iVar1;
  dJle_Pb_c *pdVar2;
  int iVar3;
  double dVar4;
  
  dVar4 = (double)param_1;
  iVar1 = 0;
  iVar3 = 0;
  do {
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + iVar3 + 0x2b0),(float)dVar4);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + iVar3 + 0x10),(float)dVar4);
    iVar1 = iVar1 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar1 < 0xc);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x550),(float)dVar4);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x588),(float)dVar4);
  iVar1 = 0;
  iVar3 = 0;
  do {
    if (this[iVar1 + 0x1371] != (dJle_Pb_c)0x0) {
      f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + iVar3 + 0x5c0),(float)dVar4);
    }
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + iVar3 + 0x668),(float)dVar4);
    iVar1 = iVar1 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar1 < 3);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x710),(float)dVar4);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x748),(float)dVar4);
  iVar1 = 0;
  iVar3 = 0;
  do {
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + iVar3 + 0x780),(float)dVar4);
    iVar1 = iVar1 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar1 < 8);
  iVar1 = 0;
  iVar3 = 0;
  do {
    pdVar2 = this + iVar3;
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(pdVar2 + 0x940),(float)dVar4);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(pdVar2 + 0x9e8),(float)dVar4);
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(pdVar2 + 0xa90),(float)dVar4);
    iVar1 = iVar1 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar1 < 3);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xb38),(float)dVar4);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xb70),(float)dVar4);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xe10),(float)dVar4);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xf28),(float)dVar4);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xef0),(float)dVar4);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xeb8),(float)dVar4);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xe80),(float)dVar4);
  f_op_msg_mng::fopMsgM_setNowAlpha(dVar4,this + 0xf60);
  f_op_msg_mng::fopMsgM_setNowAlpha(dVar4,this + 0xf68);
  f_op_msg_mng::fopMsgM_setNowAlpha(dVar4,this + 0xf70);
  f_op_msg_mng::fopMsgM_setNowAlpha(dVar4,this + 0xf78);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dJle_Pb_c::getAlphaInc(float) */

void __thiscall dJle_Pb_c::getAlphaInc(dJle_Pb_c *this,float param_1)

{
  int iVar1;
  int iVar2;
  double dVar3;
  
  dVar3 = (double)param_1;
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x710),param_1);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x748),(float)dVar3);
  iVar1 = 0;
  iVar2 = 0;
  do {
    f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + iVar2 + 0x780),(float)dVar3);
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x38;
  } while (iVar1 < 8);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x940),(float)dVar3);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0x9e8),(float)dVar3);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xa90),(float)dVar3);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xb38),(float)dVar3);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xb70),(float)dVar3);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xe10),(float)dVar3);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xf28),(float)dVar3);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xef0),(float)dVar3);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xeb8),(float)dVar3);
  f_op_msg_mng::fopMsgM_setNowAlpha((fopMsgM_pane_class *)(this + 0xe80),(float)dVar3);
  f_op_msg_mng::fopMsgM_setNowAlpha(dVar3,this + 0xf60);
  f_op_msg_mng::fopMsgM_setNowAlpha(dVar3,this + 0xf68);
  f_op_msg_mng::fopMsgM_setNowAlpha(dVar3,this + 0xf70);
  f_op_msg_mng::fopMsgM_setNowAlpha(dVar3,this + 0xf78);
  return;
}


/* __thiscall dJle_Pb_c::alphaDec(float) */

void __thiscall dJle_Pb_c::alphaDec(dJle_Pb_c *this,float param_1)

{
  double dVar1;
  double dVar2;
  int iVar3;
  dJle_Pb_c *pdVar4;
  int iVar5;
  double local_178;
  double local_170;
  double local_168;
  double local_160;
  
  dVar1 = d_picture_box::_4455;
  iVar3 = 0;
  iVar5 = 0xc;
  do {
    pdVar4 = this + iVar3;
    local_178 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar4[0x2e5]);
    *(char *)(*(int *)(pdVar4 + 0x2b0) + 0xac) = (char)(int)((float)(local_178 - dVar1) * param_1);
    local_168 = (double)CONCAT44(0x43300000,(uint)(byte)pdVar4[0x45]);
    *(char *)(*(int *)(pdVar4 + 0x10) + 0xac) = (char)(int)((float)(local_168 - dVar1) * param_1);
    dVar2 = d_picture_box::_4455;
    iVar3 = iVar3 + 0x38;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  local_160 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x585]);
  *(char *)(*(int *)(this + 0x550) + 0xac) =
       (char)(int)((float)(local_160 - d_picture_box::_4455) * param_1);
  local_170 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x5bd]);
  *(char *)(*(int *)(this + 0x588) + 0xac) = (char)(int)((float)(local_170 - dVar2) * param_1);
  *(char *)(*(int *)(this + 0xba8) + 0xac) =
       (char)(int)((float)((double)CONCAT44(0x43300000,(uint)(byte)this[0xbdd]) - dVar2) * param_1);
  *(char *)(*(int *)(this + 0xbe0) + 0xac) =
       (char)(int)((float)((double)CONCAT44(0x43300000,(uint)(byte)this[0xc15]) - dVar2) * param_1);
  *(char *)(*(int *)(this + 0xc18) + 0xac) =
       (char)(int)((float)((double)CONCAT44(0x43300000,(uint)(byte)this[0xc4d]) - dVar2) * param_1);
  *(char *)(*(int *)(this + 0xc50) + 0xac) =
       (char)(int)((float)((double)CONCAT44(0x43300000,(uint)(byte)this[0xc85]) - dVar2) * param_1);
  *(char *)(*(int *)(this + 0xc88) + 0xac) =
       (char)(int)((float)((double)CONCAT44(0x43300000,(uint)(byte)this[0xcbd]) - dVar2) * param_1);
  *(char *)(*(int *)(this + 0xcc0) + 0xac) =
       (char)(int)((float)((double)CONCAT44(0x43300000,(uint)(byte)this[0xcf5]) - dVar2) * param_1);
  *(char *)(*(int *)(this + 0xcf8) + 0xac) =
       (char)(int)((float)((double)CONCAT44(0x43300000,(uint)(byte)this[0xd2d]) - dVar2) * param_1);
  *(char *)(*(int *)(this + 0xd30) + 0xac) =
       (char)(int)((float)((double)CONCAT44(0x43300000,(uint)(byte)this[0xd65]) - dVar2) * param_1);
  *(char *)(*(int *)(this + 0xd68) + 0xac) =
       (char)(int)((float)((double)CONCAT44(0x43300000,(uint)(byte)this[0xd9d]) - dVar2) * param_1);
  *(char *)(*(int *)(this + 0xda0) + 0xac) =
       (char)(int)((float)((double)CONCAT44(0x43300000,(uint)(byte)this[0xdd5]) - dVar2) * param_1);
  *(char *)(*(int *)(this + 0xdd8) + 0xac) =
       (char)(int)((float)((double)CONCAT44(0x43300000,(uint)(byte)this[0xe0d]) - dVar2) * param_1);
  *(char *)(*(int *)(this + 0xe10) + 0xac) =
       (char)(int)((float)((double)CONCAT44(0x43300000,(uint)(byte)this[0xe45]) - dVar2) * param_1);
  *(char *)(*(int *)(this + 0xe48) + 0xac) =
       (char)(int)((float)((double)CONCAT44(0x43300000,(uint)(byte)this[0xe7d]) - dVar2) * param_1);
  *(char *)(*(int *)(this + 0xf28) + 0xac) =
       (char)(int)((float)((double)CONCAT44(0x43300000,(uint)(byte)this[0xf5d]) - dVar2) * param_1);
  *(char *)(*(int *)(this + 0xef0) + 0xac) =
       (char)(int)((float)((double)CONCAT44(0x43300000,(uint)(byte)this[0xf25]) - dVar2) * param_1);
  *(char *)(*(int *)(this + 0xeb8) + 0xac) =
       (char)(int)((float)((double)CONCAT44(0x43300000,(uint)(byte)this[0xeed]) - dVar2) * param_1);
  *(char *)(*(int *)(this + 0xe80) + 0xac) =
       (char)(int)((float)((double)CONCAT44(0x43300000,(uint)(byte)this[0xeb5]) - dVar2) * param_1);
  *(char *)(*(int *)(this + 0xf60) + 0xac) =
       (char)(int)((float)((double)CONCAT44(0x43300000,(uint)(byte)this[0xf65]) - dVar2) * param_1);
  *(char *)(*(int *)(this + 0xf68) + 0xac) =
       (char)(int)((float)((double)CONCAT44(0x43300000,(uint)(byte)this[0xf6d]) - dVar2) * param_1);
  *(char *)(*(int *)(this + 0xf70) + 0xac) =
       (char)(int)((float)((double)CONCAT44(0x43300000,(uint)(byte)this[0xf75]) - dVar2) * param_1);
  *(char *)(*(int *)(this + 0xf78) + 0xac) =
       (char)(int)((float)((double)CONCAT44(0x43300000,(uint)(byte)this[0xf7d]) - dVar2) * param_1);
  return;
}


/* __thiscall dJle_Pb_c::zoomScale(void) */

void __thiscall dJle_Pb_c::zoomScale(dJle_Pb_c *this)

{
  float fVar1;
  ulong uVar2;
  bool bVar3;
  
  fVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].field_0xc;
  if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].field_0xc < d_picture_box::_4527) {
    fVar1 = d_picture_box::_4527;
  }
  if (d_picture_box::_4528 < fVar1) {
    fVar1 = d_picture_box::_4528;
  }
  if (fVar1 != *(float *)(this + 0x127c)) {
    bVar3 = d_picture_box::_4202 != *(float *)(this + 0x127c);
    *(float *)(this + 0x127c) = fVar1;
    changeScale(this,(int)*(float *)(this + 0x127c));
    if ((d_picture_box::_4527 == *(float *)(this + 0x127c)) ||
       (d_picture_box::_4528 == *(float *)(this + 0x127c))) {
      if (bVar3) {
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,0x809,(cXyz *)0x0,0,0,d_picture_box::_4527,
                   d_picture_box::_4527,d_picture_box::_4529,d_picture_box::_4529,0);
      }
    }
    else {
      uVar2 = Runtime.PPCEABI.H::__cvt_fp2unsigned
                        ((double)(d_picture_box::_4203 +
                                 d_picture_box::_4530 *
                                 d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].field_0x10)
                        );
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,8,(cXyz *)0x0,uVar2,0,d_picture_box::_4527,
                 d_picture_box::_4527,d_picture_box::_4529,d_picture_box::_4529,0);
    }
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x80226c40) */
/* WARNING: Removing unreachable block (ram,0x80226c48) */
/* __thiscall dJle_Pb_c::changeScale(int) */

void __thiscall dJle_Pb_c::changeScale(dJle_Pb_c *this,int param_1)

{
  float fVar1;
  undefined4 uVar2;
  undefined8 in_f30;
  double dVar3;
  undefined8 in_f31;
  double dVar4;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  dVar4 = (double)((*(float *)(this + 0xc90) + *(float *)(this + 0xc78) * d_picture_box::_4203) -
                  *(float *)(this + 0xc68));
  dVar3 = (double)(((*(float *)(this + 0xc90) + *(float *)(this + 0xcb0)) -
                   *(float *)(this + 0xc78) * d_picture_box::_4203) - *(float *)(this + 0xc68));
  J2DPicture::changeTexture
            (*(J2DPicture **)(this + 0xba8),(&PTR_s__res_Photo_TIKENJA_DDS_80393f88)[param_1],0);
  J2DPicture::changeTexture
            (*(J2DPicture **)(this + 0xbe0),(&PTR_s__res_Photo_TIKENJA_DDS_80393f88)[param_1],0);
  fVar1 = *(float *)(this + 0x127c);
  if (d_picture_box::_4545 <= fVar1) {
    dVar3 = (double)((fVar1 - d_picture_box::_4545) * d_picture_box::_4546) * dVar4;
  }
  else {
    dVar3 = (double)((d_picture_box::_4545 - fVar1) * d_picture_box::_4546) * dVar3;
  }
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(this + 0xc50),(double)d_picture_box::_4202,(double)(float)dVar3)
  ;
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  __psq_l0(auStack24,uVar2);
  __psq_l1(auStack24,uVar2);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x80227130) */
/* WARNING: Removing unreachable block (ram,0x80227138) */
/* __thiscall dJle_Pb_c::up_downIconMove(void) */

void __thiscall dJle_Pb_c::up_downIconMove(dJle_Pb_c *this)

{
  float fVar1;
  float fVar2;
  int iVar3;
  J2DPicture *pJVar4;
  undefined4 uVar5;
  double dVar6;
  double dVar7;
  undefined8 in_f30;
  double dVar8;
  undefined8 in_f31;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  *(short *)(this + 0xd66) = *(short *)(this + 0xd66) + 1;
  iVar3 = (int)*(short *)(this + 0xd66);
  if (iVar3 < 10) {
    dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease(0x14,iVar3,0);
    pJVar4 = *(J2DPicture **)(this + 0xcc0);
    pJVar4->mBlendKonstColorF[0] = d_picture_box::_4202;
    fVar2 = d_picture_box::_4527;
    pJVar4->mBlendKonstColorF[1] = d_picture_box::_4527;
    pJVar4->mBlendKonstColorF[2] = fVar2;
    pJVar4->mBlendKonstColorF[3] = fVar2;
    J2DPicture::setBlendKonstColor(pJVar4);
    pJVar4->mBlendKonstAlphaF[0] = d_picture_box::_4202;
    fVar2 = d_picture_box::_4527;
    pJVar4->mBlendKonstAlphaF[1] = d_picture_box::_4527;
    pJVar4->mBlendKonstAlphaF[2] = fVar2;
    pJVar4->mBlendKonstAlphaF[3] = fVar2;
    J2DPicture::setBlendKonstAlpha(pJVar4);
    pJVar4 = *(J2DPicture **)(this + 0xcf8);
    pJVar4->mBlendKonstColorF[0] = d_picture_box::_4202;
    fVar2 = d_picture_box::_4527;
    pJVar4->mBlendKonstColorF[1] = d_picture_box::_4527;
    pJVar4->mBlendKonstColorF[2] = fVar2;
    pJVar4->mBlendKonstColorF[3] = fVar2;
    J2DPicture::setBlendKonstColor(pJVar4);
    pJVar4->mBlendKonstAlphaF[0] = d_picture_box::_4202;
    fVar2 = d_picture_box::_4527;
    pJVar4->mBlendKonstAlphaF[1] = d_picture_box::_4527;
    pJVar4->mBlendKonstAlphaF[2] = fVar2;
    pJVar4->mBlendKonstAlphaF[3] = fVar2;
    J2DPicture::setBlendKonstAlpha(pJVar4);
    fVar2 = d_picture_box::_4527;
    dVar7 = (double)d_picture_box::_4527;
    if ((dVar7 != (double)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].field_0xc) &&
       (*(short *)(this + 0xcf6) == 0)) {
      pJVar4 = *(J2DPicture **)(this + 0xd30);
      pJVar4->mBlendKonstColorF[0] = (float)dVar6;
      fVar1 = (float)(dVar7 - dVar6);
      dVar7 = (double)fVar1;
      pJVar4->mBlendKonstColorF[1] = fVar1;
      pJVar4->mBlendKonstColorF[2] = fVar2;
      pJVar4->mBlendKonstColorF[3] = fVar2;
      J2DPicture::setBlendKonstColor(pJVar4);
      pJVar4->mBlendKonstAlphaF[0] = (float)dVar6;
      pJVar4->mBlendKonstAlphaF[1] = (float)dVar7;
      fVar2 = d_picture_box::_4527;
      pJVar4->mBlendKonstAlphaF[2] = d_picture_box::_4527;
      pJVar4->mBlendKonstAlphaF[3] = fVar2;
      J2DPicture::setBlendKonstAlpha(pJVar4);
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0xcc0),(double)d_picture_box::_4202,
                 (double)d_picture_box::_4661);
    }
    if ((d_picture_box::_4528 != d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].field_0xc)
       && (*(short *)(this + 0xd2e) == 0)) {
      pJVar4 = *(J2DPicture **)(this + 0xd68);
      pJVar4->mBlendKonstColorF[0] = (float)dVar6;
      fVar2 = d_picture_box::_4527;
      dVar7 = (double)(float)((double)d_picture_box::_4527 - dVar6);
      pJVar4->mBlendKonstColorF[1] = (float)((double)d_picture_box::_4527 - dVar6);
      pJVar4->mBlendKonstColorF[2] = fVar2;
      pJVar4->mBlendKonstColorF[3] = fVar2;
      J2DPicture::setBlendKonstColor(pJVar4);
      pJVar4->mBlendKonstAlphaF[0] = (float)dVar6;
      pJVar4->mBlendKonstAlphaF[1] = (float)dVar7;
      fVar2 = d_picture_box::_4527;
      pJVar4->mBlendKonstAlphaF[2] = d_picture_box::_4527;
      pJVar4->mBlendKonstAlphaF[3] = fVar2;
      J2DPicture::setBlendKonstAlpha(pJVar4);
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0xcf8),(double)d_picture_box::_4202,
                 (double)d_picture_box::_4662);
    }
  }
  else {
    dVar6 = (double)f_op_msg_mng::fopMsgM_valueIncrease(0x14,iVar3 + -10,0);
    fVar2 = d_picture_box::_4527;
    pJVar4 = *(J2DPicture **)(this + 0xcc0);
    pJVar4->mBlendKonstColorF[0] = d_picture_box::_4527;
    pJVar4->mBlendKonstColorF[1] = d_picture_box::_4202;
    pJVar4->mBlendKonstColorF[2] = fVar2;
    pJVar4->mBlendKonstColorF[3] = fVar2;
    J2DPicture::setBlendKonstColor(pJVar4);
    fVar2 = d_picture_box::_4527;
    pJVar4->mBlendKonstAlphaF[0] = d_picture_box::_4527;
    pJVar4->mBlendKonstAlphaF[1] = d_picture_box::_4202;
    pJVar4->mBlendKonstAlphaF[2] = fVar2;
    pJVar4->mBlendKonstAlphaF[3] = fVar2;
    J2DPicture::setBlendKonstAlpha(pJVar4);
    fVar2 = d_picture_box::_4527;
    pJVar4 = *(J2DPicture **)(this + 0xcf8);
    pJVar4->mBlendKonstColorF[0] = d_picture_box::_4527;
    pJVar4->mBlendKonstColorF[1] = d_picture_box::_4202;
    pJVar4->mBlendKonstColorF[2] = fVar2;
    pJVar4->mBlendKonstColorF[3] = fVar2;
    J2DPicture::setBlendKonstColor(pJVar4);
    fVar2 = d_picture_box::_4527;
    pJVar4->mBlendKonstAlphaF[0] = d_picture_box::_4527;
    pJVar4->mBlendKonstAlphaF[1] = d_picture_box::_4202;
    pJVar4->mBlendKonstAlphaF[2] = fVar2;
    pJVar4->mBlendKonstAlphaF[3] = fVar2;
    J2DPicture::setBlendKonstAlpha(pJVar4);
    fVar2 = d_picture_box::_4527;
    dVar7 = (double)d_picture_box::_4527;
    if (dVar7 == (double)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].field_0xc) {
      if (*(short *)(this + 0xcf6) == 0) {
        pJVar4 = *(J2DPicture **)(this + 0xd30);
        dVar8 = (double)(float)(dVar7 - dVar6);
        pJVar4->mBlendKonstColorF[0] = (float)(dVar7 - dVar6);
        pJVar4->mBlendKonstColorF[1] = (float)dVar6;
        pJVar4->mBlendKonstColorF[2] = fVar2;
        pJVar4->mBlendKonstColorF[3] = fVar2;
        J2DPicture::setBlendKonstColor(pJVar4);
        pJVar4->mBlendKonstAlphaF[0] = (float)dVar8;
        pJVar4->mBlendKonstAlphaF[1] = (float)dVar6;
        fVar2 = d_picture_box::_4527;
        pJVar4->mBlendKonstAlphaF[2] = d_picture_box::_4527;
        pJVar4->mBlendKonstAlphaF[3] = fVar2;
        J2DPicture::setBlendKonstAlpha(pJVar4);
        f_op_msg_mng::fopMsgM_paneTrans
                  ((fopMsgM_pane_class *)(this + 0xcc0),(double)d_picture_box::_4202,
                   (double)d_picture_box::_4202);
      }
      if (*(short *)(this + 0xd66) == 0x14) {
        *(undefined2 *)(this + 0xcf6) = 1;
      }
    }
    else {
      if (*(short *)(this + 0xcf6) == 0) {
        pJVar4 = *(J2DPicture **)(this + 0xd30);
        dVar8 = (double)(float)(dVar7 - dVar6);
        pJVar4->mBlendKonstColorF[0] = (float)(dVar7 - dVar6);
        pJVar4->mBlendKonstColorF[1] = (float)dVar6;
        pJVar4->mBlendKonstColorF[2] = fVar2;
        pJVar4->mBlendKonstColorF[3] = fVar2;
        J2DPicture::setBlendKonstColor(pJVar4);
        pJVar4->mBlendKonstAlphaF[0] = (float)dVar8;
        pJVar4->mBlendKonstAlphaF[1] = (float)dVar6;
        fVar2 = d_picture_box::_4527;
        pJVar4->mBlendKonstAlphaF[2] = d_picture_box::_4527;
        pJVar4->mBlendKonstAlphaF[3] = fVar2;
        J2DPicture::setBlendKonstAlpha(pJVar4);
        f_op_msg_mng::fopMsgM_paneTrans
                  ((fopMsgM_pane_class *)(this + 0xcc0),(double)d_picture_box::_4202,
                   (double)d_picture_box::_4202);
      }
      else {
        if (*(short *)(this + 0xd66) == 0x14) {
          *(undefined2 *)(this + 0xcf6) = 0;
        }
      }
    }
    fVar2 = d_picture_box::_4527;
    if (d_picture_box::_4528 == d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].field_0xc) {
      if (*(short *)(this + 0xd2e) == 0) {
        pJVar4 = *(J2DPicture **)(this + 0xd68);
        dVar7 = (double)(float)((double)d_picture_box::_4527 - dVar6);
        pJVar4->mBlendKonstColorF[0] = (float)((double)d_picture_box::_4527 - dVar6);
        pJVar4->mBlendKonstColorF[1] = (float)dVar6;
        pJVar4->mBlendKonstColorF[2] = fVar2;
        pJVar4->mBlendKonstColorF[3] = fVar2;
        J2DPicture::setBlendKonstColor(pJVar4);
        pJVar4->mBlendKonstAlphaF[0] = (float)dVar7;
        pJVar4->mBlendKonstAlphaF[1] = (float)dVar6;
        fVar2 = d_picture_box::_4527;
        pJVar4->mBlendKonstAlphaF[2] = d_picture_box::_4527;
        pJVar4->mBlendKonstAlphaF[3] = fVar2;
        J2DPicture::setBlendKonstAlpha(pJVar4);
        f_op_msg_mng::fopMsgM_paneTrans
                  ((fopMsgM_pane_class *)(this + 0xcf8),(double)d_picture_box::_4202,
                   (double)d_picture_box::_4202);
      }
      if (*(short *)(this + 0xd66) == 0x14) {
        *(undefined2 *)(this + 0xd2e) = 1;
      }
    }
    else {
      if (*(short *)(this + 0xd2e) == 0) {
        pJVar4 = *(J2DPicture **)(this + 0xd68);
        dVar7 = (double)(float)((double)d_picture_box::_4527 - dVar6);
        pJVar4->mBlendKonstColorF[0] = (float)((double)d_picture_box::_4527 - dVar6);
        pJVar4->mBlendKonstColorF[1] = (float)dVar6;
        pJVar4->mBlendKonstColorF[2] = fVar2;
        pJVar4->mBlendKonstColorF[3] = fVar2;
        J2DPicture::setBlendKonstColor(pJVar4);
        pJVar4->mBlendKonstAlphaF[0] = (float)dVar7;
        pJVar4->mBlendKonstAlphaF[1] = (float)dVar6;
        fVar2 = d_picture_box::_4527;
        pJVar4->mBlendKonstAlphaF[2] = d_picture_box::_4527;
        pJVar4->mBlendKonstAlphaF[3] = fVar2;
        J2DPicture::setBlendKonstAlpha(pJVar4);
        f_op_msg_mng::fopMsgM_paneTrans
                  ((fopMsgM_pane_class *)(this + 0xcf8),(double)d_picture_box::_4202,
                   (double)d_picture_box::_4202);
      }
      else {
        if (*(short *)(this + 0xd66) == 0x14) {
          *(undefined2 *)(this + 0xd2e) = 0;
        }
      }
    }
  }
  if (d_picture_box::_4527 == d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].field_0xc) {
    *(undefined *)(*(int *)(this + 0xcc0) + 0xaa) = 0;
    *(undefined *)(*(int *)(this + 0xcf8) + 0xaa) = 1;
  }
  else {
    if (d_picture_box::_4528 == d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].field_0xc) {
      *(undefined *)(*(int *)(this + 0xcc0) + 0xaa) = 1;
      *(undefined *)(*(int *)(this + 0xcf8) + 0xaa) = 0;
    }
    else {
      *(undefined *)(*(int *)(this + 0xcc0) + 0xaa) = 1;
      *(undefined *)(*(int *)(this + 0xcf8) + 0xaa) = 1;
    }
  }
  if (0x13 < *(short *)(this + 0xd66)) {
    *(undefined2 *)(this + 0xd66) = 0;
  }
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  __psq_l0(auStack24,uVar5);
  __psq_l1(auStack24,uVar5);
  return;
}


/* __thiscall dJle_Pb_c::left_rightIconMove(void) */

void __thiscall dJle_Pb_c::left_rightIconMove(dJle_Pb_c *this)

{
  float fVar1;
  J2DPicture *pJVar2;
  
  *(short *)(this + 0x586) = *(short *)(this + 0x586) + 1;
  fVar1 = d_picture_box::_4527;
  if (*(short *)(this + 0x586) < 10) {
    if (this[0x136e] != (dJle_Pb_c)0x2) {
      pJVar2 = *(J2DPicture **)(this + 0x550);
      pJVar2->mBlendKonstColorF[0] = d_picture_box::_4202;
      fVar1 = d_picture_box::_4527;
      pJVar2->mBlendKonstColorF[1] = d_picture_box::_4527;
      pJVar2->mBlendKonstColorF[2] = fVar1;
      pJVar2->mBlendKonstColorF[3] = fVar1;
      J2DPicture::setBlendKonstColor(pJVar2);
      pJVar2->mBlendKonstAlphaF[0] = d_picture_box::_4202;
      fVar1 = d_picture_box::_4527;
      pJVar2->mBlendKonstAlphaF[1] = d_picture_box::_4527;
      pJVar2->mBlendKonstAlphaF[2] = fVar1;
      pJVar2->mBlendKonstAlphaF[3] = fVar1;
      J2DPicture::setBlendKonstAlpha(pJVar2);
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0x550),(double)d_picture_box::_4661,
                 (double)d_picture_box::_4202);
    }
    if (this[0x136e] != (dJle_Pb_c)0x1) {
      pJVar2 = *(J2DPicture **)(this + 0x588);
      pJVar2->mBlendKonstColorF[0] = d_picture_box::_4202;
      fVar1 = d_picture_box::_4527;
      pJVar2->mBlendKonstColorF[1] = d_picture_box::_4527;
      pJVar2->mBlendKonstColorF[2] = fVar1;
      pJVar2->mBlendKonstColorF[3] = fVar1;
      J2DPicture::setBlendKonstColor(pJVar2);
      pJVar2->mBlendKonstAlphaF[0] = d_picture_box::_4202;
      fVar1 = d_picture_box::_4527;
      pJVar2->mBlendKonstAlphaF[1] = d_picture_box::_4527;
      pJVar2->mBlendKonstAlphaF[2] = fVar1;
      pJVar2->mBlendKonstAlphaF[3] = fVar1;
      J2DPicture::setBlendKonstAlpha(pJVar2);
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0x588),(double)d_picture_box::_4662,
                 (double)d_picture_box::_4202);
    }
  }
  else {
    if (this[0x136e] != (dJle_Pb_c)0x2) {
      pJVar2 = *(J2DPicture **)(this + 0x550);
      pJVar2->mBlendKonstColorF[0] = d_picture_box::_4527;
      pJVar2->mBlendKonstColorF[1] = d_picture_box::_4202;
      pJVar2->mBlendKonstColorF[2] = fVar1;
      pJVar2->mBlendKonstColorF[3] = fVar1;
      J2DPicture::setBlendKonstColor(pJVar2);
      fVar1 = d_picture_box::_4527;
      pJVar2->mBlendKonstAlphaF[0] = d_picture_box::_4527;
      pJVar2->mBlendKonstAlphaF[1] = d_picture_box::_4202;
      pJVar2->mBlendKonstAlphaF[2] = fVar1;
      pJVar2->mBlendKonstAlphaF[3] = fVar1;
      J2DPicture::setBlendKonstAlpha(pJVar2);
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0x550),(double)d_picture_box::_4202,
                 (double)d_picture_box::_4202);
    }
    fVar1 = d_picture_box::_4527;
    if (this[0x136e] != (dJle_Pb_c)0x1) {
      pJVar2 = *(J2DPicture **)(this + 0x588);
      pJVar2->mBlendKonstColorF[0] = d_picture_box::_4527;
      pJVar2->mBlendKonstColorF[1] = d_picture_box::_4202;
      pJVar2->mBlendKonstColorF[2] = fVar1;
      pJVar2->mBlendKonstColorF[3] = fVar1;
      J2DPicture::setBlendKonstColor(pJVar2);
      fVar1 = d_picture_box::_4527;
      pJVar2->mBlendKonstAlphaF[0] = d_picture_box::_4527;
      pJVar2->mBlendKonstAlphaF[1] = d_picture_box::_4202;
      pJVar2->mBlendKonstAlphaF[2] = fVar1;
      pJVar2->mBlendKonstAlphaF[3] = fVar1;
      J2DPicture::setBlendKonstAlpha(pJVar2);
      f_op_msg_mng::fopMsgM_paneTrans
                ((fopMsgM_pane_class *)(this + 0x588),(double)d_picture_box::_4202,
                 (double)d_picture_box::_4202);
    }
  }
  if (0x13 < *(short *)(this + 0x586)) {
    *(undefined2 *)(this + 0x586) = 0;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Removing unreachable block (ram,0x802274f8) */
/* WARNING: Removing unreachable block (ram,0x802274e8) */
/* WARNING: Removing unreachable block (ram,0x802274f0) */
/* WARNING: Removing unreachable block (ram,0x80227500) */
/* __thiscall dJle_Pb_c::clickShutterMode(void) */

void __thiscall dJle_Pb_c::clickShutterMode(dJle_Pb_c *this)

{
  float fVar1;
  float fVar2;
  int iVar3;
  short sVar5;
  int *piVar4;
  dJle_Pb_c *pdVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  double dVar10;
  undefined8 in_f28;
  double dVar11;
  undefined8 in_f29;
  undefined8 in_f30;
  double dVar12;
  undefined8 in_f31;
  double dVar13;
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
  iVar3 = (int)DAT_803e6a2c;
  iVar8 = (int)(short)(iVar3 << 1);
  sVar5 = *(short *)(this + 0x1362);
  if (sVar5 < iVar3) {
    *(short *)(this + 0x1362) = sVar5 + 1;
    dVar10 = (double)f_op_msg_mng::fopMsgM_valueIncrease(iVar3,(int)*(short *)(this + 0x1362),0);
  }
  else {
    if (sVar5 == iVar3) {
      sVar5 = m_Do_graphic::mDoGph_getCaptureStep();
      if (sVar5 == 5) {
        *(short *)(this + 0x1362) = *(short *)(this + 0x1362) + 1;
        d_meter::dMenu_flagSet(1);
      }
      dVar10 = (double)d_picture_box::_4527;
    }
    else {
      *(short *)(this + 0x1362) = sVar5 + 1;
      dVar10 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                 (iVar3,iVar8 - *(short *)(this + 0x1362),0);
    }
  }
  iVar3 = 0;
  iVar7 = 0;
  dVar13 = (double)d_picture_box::_4203;
  dVar12 = d_picture_box::_4296;
  do {
    pdVar6 = this + iVar7;
    fVar2 = (float)((double)CONCAT44(0x43300000,(int)*(short *)(pdVar6 + 0x2e6) ^ 0x80000000) -
                   dVar12) + (float)((double)DAT_803e692c * dVar10);
    dVar11 = (double)fVar2;
    fVar1 = *(float *)(pdVar6 + 0x2d8);
    piVar4 = *(int **)(pdVar6 + 0x2b0);
    piVar4[0x27] = (int)(float)((double)*(float *)(pdVar6 + 0x2d4) * dVar13);
    piVar4[0x28] = (int)(float)((double)fVar1 * dVar13);
    *(undefined *)(piVar4 + 0x2a) = 0x7a;
    piVar4[0x29] = (int)fVar2;
    (**(code **)(*piVar4 + 0x20))();
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(pdVar6 + 0x10),(double)d_picture_box::_4202,
               (double)(float)(dVar10 * -(double)(*(float *)(pdVar6 + 0x18) -
                                                 (float)((double)*(float *)(pdVar6 + 0x2d8) * dVar13
                                                        ))));
    shutterLineRotateCenter(this,(float)dVar11,iVar3);
    iVar3 = iVar3 + 1;
    iVar7 = iVar7 + 0x38;
  } while (iVar3 < 0xc);
  shutterLineMove(this);
  if (*(short *)(this + 0x1362) == iVar8) {
    this[0x136c] = (dJle_Pb_c)0x2;
    shutterHide(this);
    messageSet(this,0xedd);
  }
  __psq_l0(auStack8,uVar9);
  __psq_l1(auStack8,uVar9);
  __psq_l0(auStack24,uVar9);
  __psq_l1(auStack24,uVar9);
  __psq_l0(auStack40,uVar9);
  __psq_l1(auStack40,uVar9);
  __psq_l0(auStack56,uVar9);
  __psq_l1(auStack56,uVar9);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dJle_Pb_c::selectMode(void) */

void __thiscall dJle_Pb_c::selectMode(dJle_Pb_c *this)

{
  dJle_Pb_c dVar3;
  short sVar2;
  undefined4 uVar1;
  byte bVar4;
  byte *src;
  byte *dst;
  
  dVar3 = (dJle_Pb_c)
          fopMsgM_msgDataProc_c::selectCheckYoko
                    ((fopMsgM_msgDataProc_c *)(this + 0xfbc),*(J2DPane **)(this + 0xf8c),
                     *(int *)(this + 0x1340),*(int *)(this + 0x1348),
                     *(int *)(this + 0x1344) - *(int *)(this + 0x1340));
  if (dVar3 != this[0x136f]) {
    this[0x136f] = dVar3;
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x83d,(cXyz *)0x0,0,0,d_picture_box::_4527,
               d_picture_box::_4527,d_picture_box::_4529,d_picture_box::_4529,0);
  }
  if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) == 0) {
    if (((char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 < '\0') &&
       (sVar2 = m_Do_graphic::mDoGph_getCaptureStep(), sVar2 == 5)) {
      m_Do_graphic::mDoGph_setCaptureStep(6);
      remainMessageSet(this,d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord.
                            _2_1_);
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x8d5,(cXyz *)0x0,0,0,d_picture_box::_4527,
                 d_picture_box::_4527,d_picture_box::_4529,d_picture_box::_4529,0);
      this[0x136c] = (dJle_Pb_c)0x0;
      d_com_inf_game::g_dComIfG_gameInfo.mbCamOverrideFarPlane = 0xb;
      d_meter::dMenu_flagSet(0);
    }
  }
  else {
    sVar2 = m_Do_graphic::mDoGph_getCaptureStep();
    if (sVar2 == 5) {
      m_Do_graphic::mDoGph_setCaptureStep(6);
      bVar4 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._2_1_;
      if (dVar3 == (dJle_Pb_c)0x0) {
        dst = *(byte **)(this + (uint)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.
                                      mItemRecord._2_1_ * 4 + 0x126c);
        d_com_inf_game::g_dComIfG_gameInfo._23547_1_ =
             d_com_inf_game::g_dComIfG_gameInfo._23547_1_ | 7;
        uVar1 = d_snap::dSnap_GetResult();
        *(undefined4 *)(dst + 0x1ee0) = uVar1;
        bVar4 = d_snap::dSnap_GetResultDetail();
        dst[0x1ee4] = bVar4;
        *(dJle_Pb_c *)(dst + 0x1ee5) = this[0x1376];
        src = (byte *)m_Do_graphic::mDoGph_getCaptureTextureBuffer();
        copy_bytes(dst,src,0x1ee0);
        os::DCStoreRangeNoSync(dst,0x1ee0);
        d_com_inf_game::g_dComIfG_gameInfo.mPlay._18654_2_ =
             d_com_inf_game::g_dComIfG_gameInfo.mPlay._18654_2_ + 1;
        bVar4 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._2_1_ + 1;
        this[d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._2_1_ + 0x1371] =
             (dJle_Pb_c)0x1;
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,0x8d4,(cXyz *)0x0,0,0,d_picture_box::_4527,
                   d_picture_box::_4527,d_picture_box::_4529,d_picture_box::_4529,0);
      }
      else {
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,0x8d5,(cXyz *)0x0,0,0,d_picture_box::_4527,
                   d_picture_box::_4527,d_picture_box::_4529,d_picture_box::_4529,0);
      }
      remainMessageSet(this,bVar4);
      this[0x136c] = (dJle_Pb_c)0x0;
      d_com_inf_game::g_dComIfG_gameInfo.mbCamOverrideFarPlane = 0xb;
      d_meter::dMenu_flagSet(0);
    }
  }
  return;
}


/* __thiscall dJle_Pb_c::cameraMode(void) */

void __thiscall dJle_Pb_c::cameraMode(dJle_Pb_c *this)

{
  short sVar1;
  
  if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) == 0) {
    if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 2 & 1) == 0) {
      if ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].field_0x8 & 0x40) == 0) {
        this[0x136b] = (dJle_Pb_c)0x6;
      }
      else {
        sVar1 = m_Do_graphic::mDoGph_getCaptureStep();
        if (sVar1 == -1) {
          ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).field_0x29c =
               ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).field_0x29c |
               0x80000;
          this[0x136b] = (dJle_Pb_c)0x6;
        }
        else {
          zoomScale(this);
        }
      }
    }
    else {
      this[0x1370] = (dJle_Pb_c)0x1;
      *(undefined2 *)(this + 0x1362) = 0;
      shutterShow(this);
      this[0x136e] = (dJle_Pb_c)0x0;
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x8d3,(cXyz *)0x0,0,0,d_picture_box::_4527,
                 d_picture_box::_4527,d_picture_box::_4529,d_picture_box::_4529,0);
    }
  }
  else {
    sVar1 = m_Do_graphic::mDoGph_getCaptureStep();
    if ((sVar1 == 0) &&
       (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._2_1_ < 3)) {
      *(undefined2 *)(this + 0x1362) = 0;
      this[0x136c] = (dJle_Pb_c)0x1;
      if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.field_0x8 == PictoBox) {
        this[0x1376] = (dJle_Pb_c)0x1;
      }
      else {
        this[0x1376] = (dJle_Pb_c)0x4;
      }
      m_Do_graphic::mDoGph_setCaptureCaptureFormat(this[0x1376]);
      m_Do_graphic::mDoGph_setCaptureTextureFormat(0xe);
      m_Do_graphic::mDoGph_setCaptureStep(1);
      d_com_inf_game::g_dComIfG_gameInfo.mbCamOverrideFarPlane = 7;
      shutterShow(this);
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x878,(cXyz *)0x0,0,0,d_picture_box::_4527,
                 d_picture_box::_4527,d_picture_box::_4529,d_picture_box::_4529,0);
      d_snap::dSnap_ReleaseShutter();
    }
  }
  up_downIconMove(this);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dJle_Pb_c::pictureDraw(unsigned char,
                                     int) */

void __thiscall dJle_Pb_c::pictureDraw(dJle_Pb_c *this,uchar param_1,int param_2)

{
  int iVar1;
  int iVar2;
  dJle_Pb_c *pdVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  void *pvVar7;
  short sVar8;
  double dVar9;
  _GXColor local_d8;
  _GXColor local_d4;
  _GXColor local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  GXTexObj GStack188;
  float local_9c;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  undefined auStack132 [28];
  MTX44 MStack104;
  longlong local_28;
  longlong local_20;
  
  pvVar7 = *(void **)(this + param_2 * 4 + 0x126c);
  pdVar3 = this + (param_2 & ~-(uint)(param_2 == 3)) * 0x38;
  iVar1 = (int)((*(float *)(pdVar3 + 0x94c) + d_s_play::g_regHIO.mChild[6].mFloats[0] +
                *(float *)(pdVar3 + 0x94c) + d_s_play::g_regHIO.mChild[6].mFloats[0] +
                *(float *)(pdVar3 + 0x964)) * d_picture_box::_4203);
  local_28 = (longlong)iVar1;
  iVar2 = (int)((*(float *)(pdVar3 + 0x950) + d_s_play::g_regHIO.mChild[6].mFloats[1] +
                *(float *)(pdVar3 + 0x950) + d_s_play::g_regHIO.mChild[6].mFloats[1] +
                *(float *)(pdVar3 + 0x968)) * d_picture_box::_4203);
  local_20 = (longlong)iVar2;
  if (d_picture_box::init_4902 == '\0') {
    d_picture_box::mCaptureMonoColor1_4901 =
         (_GXColor)((uint)d_picture_box::mCaptureMonoColor1_4901 & 0xffffff00 | (uint)param_1);
    d_picture_box::init_4902 = '\x01';
  }
  gx::GXGetProjectionv(auStack132);
  gx::GXGetViewportv(&local_9c);
  gx::GXGetScissor(&local_c0,&local_c4,&local_c8,&local_cc);
  dVar9 = (double)d_picture_box::_4202;
  gx::GXSetViewport(dVar9,dVar9,(double)d_picture_box::_4927,(double)d_picture_box::_4928,dVar9,
                    (double)d_picture_box::_4527);
  gx::GXSetNumChans(0);
  gx::GXSetNumTexGens(1);
  gx::GXSetTexCoordGen2(GX_TEXCOORD0,GX_TG_MTX2x4,GX_TG_TEX0,GX_IDENTITY,false,GX_PTIDENTITY);
  gx::GXSetNumTevStages(1);
  local_d0 = d_picture_box::mCaptureMonoColor0_4900;
  gx::GXSetTevColor(GX_TEVREG0,&local_d0);
  local_d4 = d_picture_box::mCaptureMonoColor1_4901;
  gx::GXSetTevColor(GX_TEVREG1,&local_d4);
  gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD0,GX_TEXMAP0,GX_COLOR_NULL);
  gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_C0,GX_CC_C1,GX_CC_TEXC,GX_CC_ZERO);
  gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_KONST);
  gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetZCompLoc(1);
  gx::GXSetZMode(false,GX_ALWAYS,false);
  gx::GXSetBlendMode(GX_BM_BLEND,GX_BL_SRCALPHA,GX_BL_INVSRCALPHA,GX_LO_COPY);
  gx::GXSetAlphaCompare(GX_ALWAYS,0,GX_AOP_OR,GX_ALWAYS,0);
  local_d8 = d_com_inf_game::g_clearColor;
  gx::GXSetFog(GX_FOG_NONE,d_picture_box::_4202,d_picture_box::_4202,d_picture_box::_4202,
               d_picture_box::_4202,&local_d8);
  gx::GXSetClipMode(true);
  gx::GXSetCullMode(0);
  gx::GXSetDither(1);
  gx::GXSetNumIndStages(0);
  gx::GXSetTevDirect(0);
  mtx::C_MTXOrtho(d_picture_box::_4929,d_picture_box::_4930,d_picture_box::_4931,
                  d_picture_box::_4932,d_picture_box::_4202,d_picture_box::_4933,&MStack104);
  gx::GXSetProjection(&MStack104,GX_ORTHOGRAPHIC);
  gx::GXLoadPosMtxImm(&m_Do_mtx::g_mDoMtx_identity,0);
  gx::GXSetCurrentMtx(0);
  gx::GXClearVtxDesc();
  gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
  gx::GXSetVtxDesc(GX_VA_TEX0,GX_DIRECT);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_RGBA4,0);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX0,GX_CLR_RGBA,GX_RGB8,0);
  gx::GXInitTexObj(&GStack188,pvVar7,0x98,0x68,GX_TF_CMPR,GX_CLAMP,GX_CLAMP,false);
  gx::GXLoadTexObj(&GStack188,0);
  sVar6 = (short)iVar1;
  sVar8 = sVar6 + -0x98;
  sVar5 = (short)iVar2;
  sVar4 = sVar5 + -0x68;
  sVar6 = sVar6 + 0x98;
  sVar5 = sVar5 + 0x68;
  gx::GXBegin(0x80,0,4);
  write_volatile_2(0xcc008000,sVar8);
  write_volatile_2(0xcc008000,sVar4);
  write_volatile_2(0xcc008000,0);
  write_volatile_1(DAT_cc008000,0);
  write_volatile_1(DAT_cc008000,0);
  write_volatile_2(0xcc008000,sVar6);
  write_volatile_2(0xcc008000,sVar4);
  write_volatile_2(0xcc008000,0);
  write_volatile_1(DAT_cc008000,1);
  write_volatile_1(DAT_cc008000,0);
  write_volatile_2(0xcc008000,sVar6);
  write_volatile_2(0xcc008000,sVar5);
  write_volatile_2(0xcc008000,0);
  write_volatile_1(DAT_cc008000,1);
  write_volatile_1(DAT_cc008000,1);
  write_volatile_2(0xcc008000,sVar8);
  write_volatile_2(0xcc008000,sVar5);
  write_volatile_2(0xcc008000,0);
  write_volatile_1(DAT_cc008000,0);
  write_volatile_1(DAT_cc008000,1);
  gx::GXSetProjectionv(auStack132);
  gx::GXSetViewport((double)local_9c,(double)local_98,(double)local_94,(double)local_90,
                    (double)local_8c,(double)local_88);
  gx::GXSetScissor(local_c0,local_c4,local_c8,local_cc);
  gx::GXSetClipMode(false);
  gx::GXDrawDone();
  return;
}


/* __thiscall dJle_Pb_c::pictureEraseWait(void) */

void __thiscall dJle_Pb_c::pictureEraseWait(dJle_Pb_c *this)

{
  dJle_Pb_c dVar1;
  
  dVar1 = (dJle_Pb_c)
          fopMsgM_msgDataProc_c::selectCheckYoko
                    ((fopMsgM_msgDataProc_c *)(this + 0xfbc),*(J2DPane **)(this + 0xf8c),
                     *(int *)(this + 0x1340),*(int *)(this + 0x1348),
                     *(int *)(this + 0x1344) - *(int *)(this + 0x1340));
  if (dVar1 != this[0x136f]) {
    this[0x136f] = dVar1;
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x83d,(cXyz *)0x0,0,0,d_picture_box::_4527,
               d_picture_box::_4527,d_picture_box::_4529,d_picture_box::_4529,0);
  }
  if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) == 0) {
    if ((char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 < '\0') {
      existMessageSet(this,d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord.
                           _2_1_);
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x8d9,(cXyz *)0x0,0,0,d_picture_box::_4527,
                 d_picture_box::_4527,d_picture_box::_4529,d_picture_box::_4529,0);
      this[0x136c] = (dJle_Pb_c)0x0;
      d_com_inf_game::g_dComIfG_gameInfo.mbCamOverrideFarPlane = 0xb;
    }
  }
  else {
    if (dVar1 == (dJle_Pb_c)0x0) {
      pictureErase(this);
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x8d8,(cXyz *)0x0,0,0,d_picture_box::_4527,
                 d_picture_box::_4527,d_picture_box::_4529,d_picture_box::_4529,0);
    }
    else {
      existMessageSet(this,d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord.
                           _2_1_);
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x8d9,(cXyz *)0x0,0,0,d_picture_box::_4527,
                 d_picture_box::_4527,d_picture_box::_4529,d_picture_box::_4529,0);
    }
    this[0x136c] = (dJle_Pb_c)0x0;
    d_com_inf_game::g_dComIfG_gameInfo.mbCamOverrideFarPlane = 0xb;
  }
  return;
}


/* __thiscall dJle_Pb_c::pictureDecide(void) */

void __thiscall dJle_Pb_c::pictureDecide(dJle_Pb_c *this)

{
  dJle_Pb_c dVar1;
  int iVar2;
  
  dVar1 = (dJle_Pb_c)
          fopMsgM_msgDataProc_c::selectCheckYoko
                    ((fopMsgM_msgDataProc_c *)(this + 0xfbc),*(J2DPane **)(this + 0xf8c),
                     *(int *)(this + 0x1340),*(int *)(this + 0x1348),
                     *(int *)(this + 0x1344) - *(int *)(this + 0x1340));
  if (dVar1 != this[0x136f]) {
    this[0x136f] = dVar1;
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x83d,(cXyz *)0x0,0,0,d_picture_box::_4527,
               d_picture_box::_4527,d_picture_box::_4529,d_picture_box::_4529,0);
  }
  if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) == 0) {
    if ((char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 < '\0') {
      existMessageSet(this,d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord.
                           _2_1_);
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x8d9,(cXyz *)0x0,0,0,d_picture_box::_4527,
                 d_picture_box::_4527,d_picture_box::_4529,d_picture_box::_4529,0);
      this[0x136c] = (dJle_Pb_c)0x0;
      d_com_inf_game::g_dComIfG_gameInfo.mbCamOverrideFarPlane = 0xb;
    }
  }
  else {
    if (dVar1 == (dJle_Pb_c)0x0) {
      d_com_inf_game::g_dComIfG_gameInfo._23553_1_ = this[0x136e];
      iVar2 = *(int *)(this + (uint)(byte)d_com_inf_game::g_dComIfG_gameInfo._23553_1_ * 4 + 0x126c)
      ;
      d_com_inf_game::g_dComIfG_gameInfo.field_0x5c00 = *(byte *)(iVar2 + 0x1ee5);
      d_com_inf_game::g_dComIfG_gameInfo.field_0x5bfe = 1;
      d_com_inf_game::g_dComIfG_gameInfo.field_0x5bfc = (byte)*(undefined4 *)(iVar2 + 0x1ee0);
      d_com_inf_game::g_dComIfG_gameInfo.field_0x5bfd = *(byte *)(iVar2 + 0x1ee4);
      ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).field_0x29c =
           ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).field_0x29c |
           0x80000;
      this[0x136b] = (dJle_Pb_c)0x6;
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x90c,(cXyz *)0x0,0,0,d_picture_box::_4527,
                 d_picture_box::_4527,d_picture_box::_4529,d_picture_box::_4529,0);
    }
    else {
      existMessageSet(this,d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord.
                           _2_1_);
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x8d9,(cXyz *)0x0,0,0,d_picture_box::_4527,
                 d_picture_box::_4527,d_picture_box::_4529,d_picture_box::_4529,0);
    }
    this[0x136c] = (dJle_Pb_c)0x0;
    d_com_inf_game::g_dComIfG_gameInfo.mbCamOverrideFarPlane = 0xb;
  }
  return;
}


/* __thiscall dJle_Pb_c::pictureErase(void) */

void __thiscall dJle_Pb_c::pictureErase(dJle_Pb_c *this)

{
  if (this[(byte)this[0x136e] + 0x1371] != (dJle_Pb_c)0x0) {
    this[0x1374] = (dJle_Pb_c)0x1;
    this[(byte)this[0x136e] + 0x1371] = (dJle_Pb_c)0x0;
    f_op_msg_mng::fopMsgM_setNowAlphaZero
              ((fopMsgM_pane_class *)(this + (uint)(byte)this[0x136e] * 0x38 + 0x5c0));
    d_com_inf_game::g_dComIfG_gameInfo.mPlay._18654_2_ =
         d_com_inf_game::g_dComIfG_gameInfo.mPlay._18654_2_ + -1;
    d_com_inf_game::g_dComIfG_gameInfo._23547_1_ = d_com_inf_game::g_dComIfG_gameInfo._23547_1_ | 7;
  }
  existMessageSet(this,d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._2_1_ +
                       0xff);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x8022825c) */
/* WARNING: Removing unreachable block (ram,0x8022824c) */
/* WARNING: Removing unreachable block (ram,0x80228244) */
/* WARNING: Removing unreachable block (ram,0x80228254) */
/* WARNING: Removing unreachable block (ram,0x80228264) */
/* __thiscall dJle_Pb_c::pictureTransX(float,
                                       float,
                                       float,
                                       float,
                                       float) */

void __thiscall
dJle_Pb_c::pictureTransX
          (dJle_Pb_c *this,float param_1,float param_2,float param_3,float param_4,float param_5)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  double x;
  double x_00;
  double x_01;
  double x_02;
  double y;
  undefined8 in_f27;
  undefined8 in_f28;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  y = (double)param_5;
  x_01 = (double)param_3;
  x_02 = (double)param_4;
  x_00 = (double)param_2;
  x = (double)param_1;
  uVar3 = 0;
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
  iVar1 = 0;
  iVar2 = 0;
  do {
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(this + iVar2 + 0x940),x,(double)d_picture_box::_4202);
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(this + iVar2 + 0x9e8),x,(double)d_picture_box::_4202);
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x38;
  } while (iVar1 < 3);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0xa90),x_00,-y);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0xac8),x_01,y);
  f_op_msg_mng::fopMsgM_paneTrans((fopMsgM_pane_class *)(this + 0xb00),x_02,y);
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
  return;
}


/* WARNING: Removing unreachable block (ram,0x80228448) */
/* WARNING: Removing unreachable block (ram,0x80228450) */
/* __thiscall dJle_Pb_c::changePicture(void) */

void __thiscall dJle_Pb_c::changePicture(dJle_Pb_c *this)

{
  float fVar1;
  dJle_Pb_c dVar2;
  int iVar3;
  undefined4 uVar4;
  double dVar5;
  undefined8 in_f30;
  double dVar6;
  undefined8 in_f31;
  double dVar7;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  iVar3 = (int)(short)((int)DAT_803e6a2c << 1);
  dVar7 = (double)(*(float *)(this + 0x954) - *(float *)(this + 0x98c));
  dVar6 = (double)(*(float *)(this + 0xaa8) - *(float *)(this + 0xae0));
  *(short *)(this + 0x1362) = *(short *)(this + 0x1362) + 1;
  dVar2 = this[0x136c];
  if (dVar2 == (dJle_Pb_c)0x2) {
    dVar5 = (double)f_op_msg_mng::fopMsgM_valueIncrease(iVar3,iVar3 - *(short *)(this + 0x1362),0);
    fVar1 = (float)((double)(*(float *)(this + 0xb14) - *(float *)(this + 0xaa4)) * dVar5);
    pictureTransX(this,(float)(dVar7 * dVar5),fVar1,
                  (float)((double)(*(float *)(this + 0xaa4) - *(float *)(this + 0xadc)) * dVar5),
                  fVar1,(float)(dVar6 * dVar5));
  }
  else {
    if (dVar2 == (dJle_Pb_c)0x3) {
      dVar5 = (double)f_op_msg_mng::fopMsgM_valueIncrease(iVar3,(int)*(short *)(this + 0x1362),0);
      fVar1 = (float)((double)(*(float *)(this + 0xadc) - *(float *)(this + 0xaa4)) * dVar5);
      pictureTransX(this,(float)(-dVar7 * dVar5),fVar1,fVar1,
                    (float)((double)(*(float *)(this + 0xaa4) - *(float *)(this + 0xb14)) * dVar5),
                    (float)(dVar6 * dVar5));
    }
    else {
      if (dVar2 == (dJle_Pb_c)0x4) {
        dVar5 = (double)f_op_msg_mng::fopMsgM_valueIncrease(iVar3,(int)*(short *)(this + 0x1362),0);
        fVar1 = (float)((double)(*(float *)(this + 0xb14) - *(float *)(this + 0xaa4)) * dVar5);
        pictureTransX(this,(float)(dVar7 * dVar5),fVar1,
                      (float)((double)(*(float *)(this + 0xaa4) - *(float *)(this + 0xadc)) * dVar5)
                      ,fVar1,(float)(dVar6 * dVar5));
      }
      else {
        if (dVar2 == (dJle_Pb_c)0x5) {
          dVar5 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                                    (iVar3,iVar3 - *(short *)(this + 0x1362),0);
          fVar1 = (float)((double)(*(float *)(this + 0xadc) - *(float *)(this + 0xaa4)) * dVar5);
          pictureTransX(this,(float)(-dVar7 * dVar5),fVar1,fVar1,
                        (float)((double)(*(float *)(this + 0xaa4) - *(float *)(this + 0xb14)) *
                               dVar5),(float)(dVar6 * dVar5));
        }
      }
    }
  }
  if (*(short *)(this + 0x1362) == iVar3) {
    this[0x136c] = (dJle_Pb_c)0x0;
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  __psq_l0(auStack24,uVar4);
  __psq_l1(auStack24,uVar4);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x80228628) */
/* WARNING: Removing unreachable block (ram,0x80228618) */
/* WARNING: Removing unreachable block (ram,0x80228620) */
/* WARNING: Removing unreachable block (ram,0x80228630) */
/* __thiscall dJle_Pb_c::shutterChange(void) */

void __thiscall dJle_Pb_c::shutterChange(dJle_Pb_c *this)

{
  float fVar1;
  short sVar2;
  float fVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  dJle_Pb_c *pdVar7;
  undefined4 uVar8;
  double dVar9;
  undefined8 in_f28;
  double dVar10;
  undefined8 in_f29;
  undefined8 in_f30;
  double dVar11;
  undefined8 in_f31;
  double dVar12;
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
  iVar5 = (int)DAT_803e6a2c;
  iVar6 = (int)(short)(iVar5 << 1);
  sVar2 = *(short *)(this + 0x1362);
  if (sVar2 < iVar5) {
    *(short *)(this + 0x1362) = sVar2 + 1;
    dVar9 = (double)f_op_msg_mng::fopMsgM_valueIncrease(iVar5,(int)*(short *)(this + 0x1362),0);
  }
  else {
    if (sVar2 == iVar5) {
      *(short *)(this + 0x1362) = sVar2 + 1;
      dVar9 = (double)d_picture_box::_4527;
      if (this[0x136d] == (dJle_Pb_c)0x0) {
        changeCameraToBrowse(this);
      }
      else {
        changeBrowseToCamera(this);
      }
    }
    else {
      *(short *)(this + 0x1362) = sVar2 + 1;
      dVar9 = (double)f_op_msg_mng::fopMsgM_valueIncrease(iVar5,iVar6 - *(short *)(this + 0x1362),0)
      ;
      if (*(short *)(this + 0x1362) == iVar6) {
        shutterHide(this);
        this[0x1370] = (dJle_Pb_c)0x0;
      }
    }
  }
  iVar5 = 0;
  iVar6 = 0;
  dVar12 = (double)d_picture_box::_4203;
  dVar11 = d_picture_box::_4296;
  do {
    pdVar7 = this + iVar6;
    fVar3 = (float)((double)CONCAT44(0x43300000,(int)*(short *)(pdVar7 + 0x2e6) ^ 0x80000000) -
                   dVar11) + (float)((double)DAT_803e692c * dVar9);
    dVar10 = (double)fVar3;
    fVar1 = *(float *)(pdVar7 + 0x2d8);
    piVar4 = *(int **)(pdVar7 + 0x2b0);
    piVar4[0x27] = (int)(float)((double)*(float *)(pdVar7 + 0x2d4) * dVar12);
    piVar4[0x28] = (int)(float)((double)fVar1 * dVar12);
    *(undefined *)(piVar4 + 0x2a) = 0x7a;
    piVar4[0x29] = (int)fVar3;
    (**(code **)(*piVar4 + 0x20))();
    f_op_msg_mng::fopMsgM_paneTrans
              ((fopMsgM_pane_class *)(pdVar7 + 0x10),(double)d_picture_box::_4202,
               (double)(float)(dVar9 * -(double)(*(float *)(pdVar7 + 0x18) -
                                                (float)((double)*(float *)(pdVar7 + 0x2d8) * dVar12)
                                                )));
    shutterLineRotateInitPos(this,(float)dVar10,iVar5);
    iVar5 = iVar5 + 1;
    iVar6 = iVar6 + 0x38;
  } while (iVar5 < 0xc);
  shutterLineMove(this);
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


/* __thiscall dJle_Pb_c::moveCamera(void) */

void __thiscall dJle_Pb_c::moveCamera(dJle_Pb_c *this)

{
  camera_class *pcVar1;
  
  pcVar1 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera;
  if (this[0x136c] == (dJle_Pb_c)0x1) {
    dCamera_c::Stay(&(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera)->mBody);
    clickShutterMode(this);
    d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd1 = 0;
    d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0;
    if ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5bfe != 2) &&
       (d_com_inf_game::g_dComIfG_gameInfo.field_0x5bfe != 3)) {
      d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd0 = 0;
    }
    d_com_inf_game::g_dComIfG_gameInfo.field_0x5bcd = 0;
  }
  else {
    if (this[0x136c] == (dJle_Pb_c)0x2) {
      dCamera_c::Stay(&(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].mpCamera)->mBody);
      selectMode(this);
      d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0x17;
      d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd1 = 7;
    }
    else {
      cameraMode(this);
      if (this[0x136c] == (dJle_Pb_c)0x1) {
        dCamera_c::Stay(&pcVar1->mBody);
      }
      if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._2_1_ < 3) {
        d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0x20;
      }
      else {
        d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0;
      }
      d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd1 = 7;
      if ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5bfe != 2) &&
         (d_com_inf_game::g_dComIfG_gameInfo.field_0x5bfe != 3)) {
        d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd0 = 0x22;
      }
    }
  }
  return;
}


/* __thiscall dJle_Pb_c::moveBrowse(void) */

void __thiscall dJle_Pb_c::moveBrowse(dJle_Pb_c *this)

{
  char cVar1;
  
  STControl::checkTrigger(*(STControl **)(this + 0xf98));
  if (this[0x136c] != (dJle_Pb_c)0x0) {
    if (this[0x136c] == (dJle_Pb_c)0x1) {
      pictureEraseWait(this);
      if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._2_1_ == '\0') {
        d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0;
      }
      else {
        d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0x17;
      }
      d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd1 = 7;
    }
    else {
      changePicture(this);
      d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0;
    }
    goto LAB_80228b84;
  }
  if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 2 & 1) == 0) {
    if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) == 0) {
      cVar1 = STControl::checkRightTrigger(*(STControl **)(this + 0xf98));
      if (cVar1 == '\0') {
        cVar1 = STControl::checkLeftTrigger(*(STControl **)(this + 0xf98));
        if (cVar1 == '\0') {
          if (-1 < (char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3) {
            if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 6 & 1) != 0) {
              if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                  mInventorySlotIndexOnButton[0] == 8) goto LAB_80228a70;
            }
            if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 5 & 1) != 0) {
              if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                  mInventorySlotIndexOnButton[1] == 8) goto LAB_80228a70;
            }
            if (((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 3 & 1) == 0) ||
               (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                mInventorySlotIndexOnButton[2] != 8)) {
              left_rightIconMove(this);
              goto LAB_80228ac8;
            }
          }
LAB_80228a70:
          ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).field_0x29c =
               ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).field_0x29c |
               0x80000;
          this[0x136b] = (dJle_Pb_c)0x6;
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x824,(cXyz *)0x0,0,0,d_picture_box::_4527,
                     d_picture_box::_4527,d_picture_box::_4529,d_picture_box::_4529,0);
        }
        else {
          if (this[0x136e] == (dJle_Pb_c)0x0) {
            setColorInit(this,'\0');
            this[0x136e] = (dJle_Pb_c)0x1;
            *(undefined2 *)(this + 0x1362) = 0;
            this[0x136c] = (dJle_Pb_c)0x4;
            JAIZelBasic::seStart
                      (JAIZelBasic::zel_basic,0x8d6,(cXyz *)0x0,0,0,d_picture_box::_4527,
                       d_picture_box::_4527,d_picture_box::_4529,d_picture_box::_4529,0);
          }
          else {
            if (this[0x136e] == (dJle_Pb_c)0x2) {
              setColorInit(this,'\x02');
              this[0x136e] = (dJle_Pb_c)0x0;
              *(undefined2 *)(this + 0x1362) = 0;
              this[0x136c] = (dJle_Pb_c)0x5;
              JAIZelBasic::seStart
                        (JAIZelBasic::zel_basic,0x8d6,(cXyz *)0x0,0,0,d_picture_box::_4527,
                         d_picture_box::_4527,d_picture_box::_4529,d_picture_box::_4529,0);
            }
          }
        }
      }
      else {
        if (this[0x136e] == (dJle_Pb_c)0x1) {
          setColorInit(this,'\x01');
          this[0x136e] = (dJle_Pb_c)0x0;
          *(undefined2 *)(this + 0x1362) = 0;
          this[0x136c] = (dJle_Pb_c)0x2;
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x8d6,(cXyz *)0x0,0,0,d_picture_box::_4527,
                     d_picture_box::_4527,d_picture_box::_4529,d_picture_box::_4529,0);
        }
        else {
          if (this[0x136e] == (dJle_Pb_c)0x0) {
            setColorInit(this,'\0');
            this[0x136e] = (dJle_Pb_c)0x2;
            *(undefined2 *)(this + 0x1362) = 0;
            this[0x136c] = (dJle_Pb_c)0x3;
            JAIZelBasic::seStart
                      (JAIZelBasic::zel_basic,0x8d6,(cXyz *)0x0,0,0,d_picture_box::_4527,
                       d_picture_box::_4527,d_picture_box::_4529,d_picture_box::_4529,0);
          }
        }
      }
    }
    else {
      if (this[(byte)this[0x136e] + 0x1371] != (dJle_Pb_c)0x0) {
        this[0x136c] = (dJle_Pb_c)0x1;
        messageSet(this,0xee2);
        d_com_inf_game::g_dComIfG_gameInfo.mbCamOverrideFarPlane = 7;
        JAIZelBasic::seStart
                  (JAIZelBasic::zel_basic,0x8d7,(cXyz *)0x0,0,0,d_picture_box::_4527,
                   d_picture_box::_4527,d_picture_box::_4529,d_picture_box::_4529,0);
      }
    }
  }
  else {
    this[0x1370] = (dJle_Pb_c)0x1;
    *(undefined2 *)(this + 0x1362) = 0;
    shutterShow(this);
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x8d3,(cXyz *)0x0,0,0,d_picture_box::_4527,
               d_picture_box::_4527,d_picture_box::_4529,d_picture_box::_4529,0);
  }
LAB_80228ac8:
  if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._2_1_ == '\0') {
    d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0;
  }
  else {
    d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0x17;
  }
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd1 = 7;
  if ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5bfe != 2) &&
     (d_com_inf_game::g_dComIfG_gameInfo.field_0x5bfe != 3)) {
    d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd0 = 0x22;
  }
LAB_80228b84:
  setColorAnime(this,(uchar)this[0x136e]);
  return;
}


/* __thiscall dJle_Pb_c::selectBrowse(void) */

void __thiscall dJle_Pb_c::selectBrowse(dJle_Pb_c *this)

{
  char cVar1;
  
  STControl::checkTrigger(*(STControl **)(this + 0xf98));
  if (this[0x136c] != (dJle_Pb_c)0x0) {
    if (this[0x136c] == (dJle_Pb_c)0x1) {
      pictureDecide(this);
      d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0x17;
      d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd1 = 7;
    }
    else {
      changePicture(this);
      d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0;
    }
    goto LAB_80228f20;
  }
  if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) == 0) {
    if ((char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 < '\0') {
LAB_80228c78:
      ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).field_0x29c =
           ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).field_0x29c |
           0x80000;
      d_com_inf_game::g_dComIfG_gameInfo.field_0x5bfe = 0;
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x8d9,(cXyz *)0x0,0,0,d_picture_box::_4527,
                 d_picture_box::_4527,d_picture_box::_4529,d_picture_box::_4529,0);
      this[0x136b] = (dJle_Pb_c)0x6;
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x824,(cXyz *)0x0,0,0,d_picture_box::_4527,
                 d_picture_box::_4527,d_picture_box::_4529,d_picture_box::_4529,0);
    }
    else {
      if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 6 & 1) != 0) {
        if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
            mInventorySlotIndexOnButton[0] == 8) goto LAB_80228c78;
      }
      if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 5 & 1) != 0) {
        if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
            mInventorySlotIndexOnButton[1] == 8) goto LAB_80228c78;
      }
      if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 3 & 1) != 0) {
        if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
            mInventorySlotIndexOnButton[2] == 8) goto LAB_80228c78;
      }
      cVar1 = STControl::checkRightTrigger(*(STControl **)(this + 0xf98));
      if (cVar1 == '\0') {
        cVar1 = STControl::checkLeftTrigger(*(STControl **)(this + 0xf98));
        if (cVar1 == '\0') {
          left_rightIconMove(this);
        }
        else {
          if (this[0x136e] == (dJle_Pb_c)0x0) {
            setColorInit(this,'\0');
            this[0x136e] = (dJle_Pb_c)0x1;
            *(undefined2 *)(this + 0x1362) = 0;
            this[0x136c] = (dJle_Pb_c)0x4;
            JAIZelBasic::seStart
                      (JAIZelBasic::zel_basic,0x8d6,(cXyz *)0x0,0,0,d_picture_box::_4527,
                       d_picture_box::_4527,d_picture_box::_4529,d_picture_box::_4529,0);
          }
          else {
            if (this[0x136e] == (dJle_Pb_c)0x2) {
              setColorInit(this,'\x02');
              this[0x136e] = (dJle_Pb_c)0x0;
              *(undefined2 *)(this + 0x1362) = 0;
              this[0x136c] = (dJle_Pb_c)0x5;
              JAIZelBasic::seStart
                        (JAIZelBasic::zel_basic,0x8d6,(cXyz *)0x0,0,0,d_picture_box::_4527,
                         d_picture_box::_4527,d_picture_box::_4529,d_picture_box::_4529,0);
            }
          }
        }
      }
      else {
        if (this[0x136e] == (dJle_Pb_c)0x1) {
          setColorInit(this,'\x01');
          this[0x136e] = (dJle_Pb_c)0x0;
          *(undefined2 *)(this + 0x1362) = 0;
          this[0x136c] = (dJle_Pb_c)0x2;
          JAIZelBasic::seStart
                    (JAIZelBasic::zel_basic,0x8d6,(cXyz *)0x0,0,0,d_picture_box::_4527,
                     d_picture_box::_4527,d_picture_box::_4529,d_picture_box::_4529,0);
        }
        else {
          if (this[0x136e] == (dJle_Pb_c)0x0) {
            setColorInit(this,'\0');
            this[0x136e] = (dJle_Pb_c)0x2;
            *(undefined2 *)(this + 0x1362) = 0;
            this[0x136c] = (dJle_Pb_c)0x3;
            JAIZelBasic::seStart
                      (JAIZelBasic::zel_basic,0x8d6,(cXyz *)0x0,0,0,d_picture_box::_4527,
                       d_picture_box::_4527,d_picture_box::_4529,d_picture_box::_4529,0);
          }
        }
      }
    }
  }
  else {
    if (this[(byte)this[0x136e] + 0x1371] != (dJle_Pb_c)0x0) {
      messageSet(this,0xee3);
      this[0x136c] = (dJle_Pb_c)0x1;
    }
  }
  if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._2_1_ == '\0') {
    d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0;
  }
  else {
    d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0x17;
  }
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd1 = 7;
  if ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5bfe != 2) &&
     (d_com_inf_game::g_dComIfG_gameInfo.field_0x5bfe != 3)) {
    d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd0 = 0x22;
  }
LAB_80228f20:
  setColorAnime(this,(uchar)this[0x136e]);
  return;
}


/* __thiscall dJle_Pb_c::getBrowse(void) */

void __thiscall dJle_Pb_c::getBrowse(dJle_Pb_c *this)

{
  if (((((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) == 0) &&
       (-1 < (char)m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3)) &&
      (((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 6 & 1) == 0 ||
       (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
        mInventorySlotIndexOnButton[0] != 8)))) &&
     (((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton3 >> 5 & 1) == 0 ||
      (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mInventorySlotIndexOnButton
       [1] != 8)))) {
    if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 >> 3 & 1) == 0) {
      d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd1 = 7;
      d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0x19;
      return;
    }
    if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
        mInventorySlotIndexOnButton[2] != 8) {
      d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd1 = 7;
      d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0x19;
      return;
    }
  }
  d_com_inf_game::g_dComIfG_gameInfo._23547_1_ = d_com_inf_game::g_dComIfG_gameInfo._23547_1_ | 7;
  copy_bytes(*(byte **)(this + (uint)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.
                                     mItemRecord._2_1_ * 4 + 0x126c),*(byte **)(this + 0x1278),
             0x2000);
  os::DCStoreRangeNoSync
            (*(undefined4 *)
              (this + (uint)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord.
                            _2_1_ * 4 + 0x126c),0x2000);
  d_com_inf_game::g_dComIfG_gameInfo.mPlay._18654_2_ =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay._18654_2_ + 1;
  this[d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._2_1_ + 0x1371] =
       (dJle_Pb_c)0x1;
  ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).field_0x29c =
       ((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).field_0x29c | 0x80000;
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5bfe = 0;
  JAIZelBasic::seStart
            (JAIZelBasic::zel_basic,0x8d9,(cXyz *)0x0,0,0,d_picture_box::_4527,d_picture_box::_4527,
             d_picture_box::_4529,d_picture_box::_4529,0);
  this[0x136b] = (dJle_Pb_c)0x6;
  JAIZelBasic::seStart
            (JAIZelBasic::zel_basic,0x824,(cXyz *)0x0,0,0,d_picture_box::_4527,d_picture_box::_4527,
             d_picture_box::_4529,d_picture_box::_4529,0);
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd1 = 7;
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0x19;
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dJle_Pb_c::changeBrowseToCamera(void) */

void __thiscall dJle_Pb_c::changeBrowseToCamera(dJle_Pb_c *this)

{
  int iVar1;
  dJle_Pb_c *pdVar2;
  int iVar3;
  
  this[0x136d] = (dJle_Pb_c)0x0;
  setColorInit(this,(uchar)this[0x136e]);
  pictureTransX(this,d_picture_box::_4202,d_picture_box::_4202,d_picture_box::_4202,
                d_picture_box::_4202,d_picture_box::_4202);
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x588));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x550));
  iVar1 = 0;
  iVar3 = 0;
  do {
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar3 + 0x5c0));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar3 + 0x668));
    iVar1 = iVar1 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar1 < 3);
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x710));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0x748));
  iVar1 = 0;
  iVar3 = 0;
  do {
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar3 + 0x780));
    iVar1 = iVar1 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar1 < 8);
  iVar1 = 0;
  iVar3 = 0;
  do {
    pdVar2 = this + iVar3;
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar2 + 0x940));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar2 + 0x9e8));
    f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(pdVar2 + 0xa90));
    iVar1 = iVar1 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar1 < 3);
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0xb38));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0xb70));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0xe10));
  f_op_msg_mng::fopMsgM_setInitAlpha(this + 0xba8);
  f_op_msg_mng::fopMsgM_setInitAlpha(this + 0xbe0);
  f_op_msg_mng::fopMsgM_setInitAlpha(this + 0xc18);
  f_op_msg_mng::fopMsgM_setInitAlpha(this + 0xc50);
  f_op_msg_mng::fopMsgM_setInitAlpha(this + 0xc88);
  f_op_msg_mng::fopMsgM_setInitAlpha(this + 0xcc0);
  f_op_msg_mng::fopMsgM_setInitAlpha(this + 0xcf8);
  f_op_msg_mng::fopMsgM_setInitAlpha(this + 0xd30);
  f_op_msg_mng::fopMsgM_setInitAlpha(this + 0xd68);
  f_op_msg_mng::fopMsgM_setInitAlpha(this + 0xda0);
  f_op_msg_mng::fopMsgM_setInitAlpha(this + 0xdd8);
  f_op_msg_mng::fopMsgM_setInitAlpha(this + 0xe48);
  changeData(this);
  remainMessageSet(this,d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._2_1_);
  d_meter::dMenu_flagSet(0);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dJle_Pb_c::changeCameraToBrowse(void) */

void __thiscall dJle_Pb_c::changeCameraToBrowse(dJle_Pb_c *this)

{
  int iVar1;
  dJle_Pb_c *pdVar2;
  int iVar3;
  
  this[0x136d] = (dJle_Pb_c)0x1;
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0xba8));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0xbe0));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0xc18));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0xc50));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0xc88));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0xcc0));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0xcf8));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0xd30));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0xd68));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0xda0));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0xdd8));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + 0xe48));
  f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x588);
  f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x550);
  iVar1 = 0;
  iVar3 = 0;
  do {
    if (this[iVar1 + 0x1371] == (dJle_Pb_c)0x0) {
      f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(this + iVar3 + 0x5c0));
    }
    else {
      f_op_msg_mng::fopMsgM_setInitAlpha(this + iVar3 + 0x5c0);
    }
    f_op_msg_mng::fopMsgM_setInitAlpha(this + iVar3 + 0x668);
    iVar1 = iVar1 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar1 < 3);
  f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x710);
  f_op_msg_mng::fopMsgM_setInitAlpha(this + 0x748);
  iVar1 = 0;
  iVar3 = 0;
  do {
    f_op_msg_mng::fopMsgM_setInitAlpha(this + iVar3 + 0x780);
    iVar1 = iVar1 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar1 < 8);
  iVar1 = 0;
  iVar3 = 0;
  do {
    pdVar2 = this + iVar3;
    f_op_msg_mng::fopMsgM_setInitAlpha(pdVar2 + 0x940);
    f_op_msg_mng::fopMsgM_setInitAlpha(pdVar2 + 0x9e8);
    f_op_msg_mng::fopMsgM_setInitAlpha(pdVar2 + 0xa90);
    iVar1 = iVar1 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar1 < 3);
  f_op_msg_mng::fopMsgM_setInitAlpha(this + 0xb38);
  f_op_msg_mng::fopMsgM_setInitAlpha(this + 0xb70);
  f_op_msg_mng::fopMsgM_setInitAlpha(this + 0xe10);
  existMessageSet(this,d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._2_1_);
  d_meter::dMenu_flagSet(1);
  return;
}


/* __thiscall dJle_Pb_c::setColorInit(unsigned char) */

void __thiscall dJle_Pb_c::setColorInit(dJle_Pb_c *this,uchar param_1)

{
  undefined4 uVar1;
  dJle_Pb_c *pdVar2;
  int iVar3;
  int iVar4;
  undefined local_18;
  undefined uStack23;
  undefined uStack22;
  undefined uStack21;
  undefined local_14;
  undefined uStack19;
  undefined uStack18;
  undefined uStack17;
  undefined local_10;
  undefined uStack15;
  undefined uStack14;
  undefined uStack13;
  
  uVar1 = *(undefined4 *)(this + 0x125c);
  iVar4 = (uint)param_1 * 0x38;
  pdVar2 = this + iVar4;
  iVar3 = *(int *)(pdVar2 + 0x5c0);
  local_10 = (undefined)((uint)uVar1 >> 0x18);
  *(undefined *)(iVar3 + 0x104) = local_10;
  uStack15 = (undefined)((uint)uVar1 >> 0x10);
  *(undefined *)(iVar3 + 0x105) = uStack15;
  uStack14 = (undefined)((uint)uVar1 >> 8);
  *(undefined *)(iVar3 + 0x106) = uStack14;
  uStack13 = (undefined)uVar1;
  *(undefined *)(iVar3 + 0x107) = uStack13;
  uVar1 = *(undefined4 *)(this + 0x1264);
  iVar3 = *(int *)(pdVar2 + 0x668);
  local_14 = (undefined)((uint)uVar1 >> 0x18);
  *(undefined *)(iVar3 + 0x104) = local_14;
  uStack19 = (undefined)((uint)uVar1 >> 0x10);
  *(undefined *)(iVar3 + 0x105) = uStack19;
  uStack18 = (undefined)((uint)uVar1 >> 8);
  *(undefined *)(iVar3 + 0x106) = uStack18;
  uStack17 = (undefined)uVar1;
  *(undefined *)(iVar3 + 0x107) = uStack17;
  uVar1 = *(undefined4 *)(this + 0x1268);
  iVar3 = *(int *)(pdVar2 + 0x668);
  local_18 = (undefined)((uint)uVar1 >> 0x18);
  *(undefined *)(iVar3 + 0x108) = local_18;
  uStack23 = (undefined)((uint)uVar1 >> 0x10);
  *(undefined *)(iVar3 + 0x109) = uStack23;
  uStack22 = (undefined)((uint)uVar1 >> 8);
  *(undefined *)(iVar3 + 0x10a) = uStack22;
  uStack21 = (undefined)uVar1;
  *(undefined *)(iVar3 + 0x10b) = uStack21;
  *(undefined2 *)(pdVar2 + 0x5f6) = 0;
  if (this[param_1 + 0x1371] != (dJle_Pb_c)0x0) {
    f_op_msg_mng::fopMsgM_setInitAlpha(this + iVar4 + 0x5c0);
  }
  f_op_msg_mng::fopMsgM_setInitAlpha(this + iVar4 + 0x668);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x80229960) */
/* __thiscall dJle_Pb_c::setColorAnime(unsigned char) */

void __thiscall dJle_Pb_c::setColorAnime(dJle_Pb_c *this,uchar param_1)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  double dVar17;
  dJle_Pb_c *pdVar18;
  int iVar19;
  uint uVar20;
  int iVar21;
  undefined4 uVar22;
  double dVar23;
  undefined8 in_f31;
  double local_30;
  undefined auStack8 [8];
  
  uVar22 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  iVar21 = (uint)param_1 * 0x38;
  pdVar18 = this + iVar21;
  *(short *)(pdVar18 + 0x5f6) = *(short *)(pdVar18 + 0x5f6) + 1;
  if (0x27 < *(short *)(pdVar18 + 0x5f6)) {
    *(undefined2 *)(pdVar18 + 0x5f6) = 0;
  }
  iVar19 = (int)*(short *)(pdVar18 + 0x5f6);
  if (iVar19 < 0x14) {
    dVar23 = (double)f_op_msg_mng::fopMsgM_valueIncrease(0x14,iVar19,0);
  }
  else {
    dVar23 = (double)f_op_msg_mng::fopMsgM_valueIncrease(0x14,0x28 - iVar19,0);
  }
  dVar17 = d_picture_box::_4455;
  dVar1 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x125d]) - d_picture_box::_4455;
  fVar11 = (float)((double)CONCAT44(0x43300000,(uint)(byte)this[0x125d]) - d_picture_box::_4455) -
           d_picture_box::_5695;
  dVar2 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x125e]) - d_picture_box::_4455;
  fVar12 = (float)((double)CONCAT44(0x43300000,(uint)(byte)this[0x125e]) - d_picture_box::_4455) -
           d_picture_box::_5695;
  dVar3 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x1264]) - d_picture_box::_4455;
  fVar9 = (float)((double)CONCAT44(0x43300000,(uint)(byte)this[0x1264]) - d_picture_box::_4455) -
          d_picture_box::_5694;
  dVar4 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x1265]) - d_picture_box::_4455;
  fVar13 = (float)((double)CONCAT44(0x43300000,(uint)(byte)this[0x1265]) - d_picture_box::_4455) -
           d_picture_box::_5695;
  dVar5 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x1266]) - d_picture_box::_4455;
  fVar14 = (float)((double)CONCAT44(0x43300000,(uint)(byte)this[0x1266]) - d_picture_box::_4455) -
           d_picture_box::_5695;
  dVar6 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x1268]) - d_picture_box::_4455;
  fVar10 = (float)((double)CONCAT44(0x43300000,(uint)(byte)this[0x1268]) - d_picture_box::_4455) -
           d_picture_box::_5694;
  dVar7 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x1269]) - d_picture_box::_4455;
  fVar15 = (float)((double)CONCAT44(0x43300000,(uint)(byte)this[0x1269]) - d_picture_box::_4455) -
           d_picture_box::_5695;
  dVar8 = (double)CONCAT44(0x43300000,(uint)(byte)this[0x126a]) - d_picture_box::_4455;
  fVar16 = (float)((double)CONCAT44(0x43300000,(uint)(byte)this[0x126a]) - d_picture_box::_4455) -
           d_picture_box::_5695;
  pdVar18 = this + iVar21;
  iVar19 = *(int *)(pdVar18 + 0x5c0);
  *(char *)(iVar19 + 0x104) =
       (char)(int)((float)((double)CONCAT44(0x43300000,(uint)(byte)this[0x125c]) -
                          d_picture_box::_4455) -
                  (float)(dVar23 * (double)((float)((double)CONCAT44(0x43300000,
                                                                     (uint)(byte)this[0x125c]) -
                                                   d_picture_box::_4455) - d_picture_box::_5694)));
  *(char *)(iVar19 + 0x105) = (char)(int)((float)dVar1 - (float)(dVar23 * (double)fVar11));
  *(char *)(iVar19 + 0x106) = (char)(int)((float)dVar2 - (float)(dVar23 * (double)fVar12));
  *(undefined *)(iVar19 + 0x107) = 0xff;
  iVar19 = *(int *)(pdVar18 + 0x668);
  *(char *)(iVar19 + 0x104) = (char)(int)((float)dVar3 - (float)(dVar23 * (double)fVar9));
  *(char *)(iVar19 + 0x105) = (char)(int)((float)dVar4 - (float)(dVar23 * (double)fVar13));
  *(char *)(iVar19 + 0x106) = (char)(int)((float)dVar5 - (float)(dVar23 * (double)fVar14));
  *(undefined *)(iVar19 + 0x107) = 0xff;
  iVar19 = *(int *)(pdVar18 + 0x668);
  *(char *)(iVar19 + 0x108) = (char)(int)((float)dVar6 - (float)(dVar23 * (double)fVar10));
  *(char *)(iVar19 + 0x109) = (char)(int)((float)dVar7 - (float)(dVar23 * (double)fVar15));
  *(char *)(iVar19 + 0x10a) = (char)(int)((float)dVar8 - (float)(dVar23 * (double)fVar16));
  *(undefined *)(iVar19 + 0x10b) = 0;
  if (this[param_1 + 0x1371] != (dJle_Pb_c)0x0) {
    uVar20 = (uint)(byte)pdVar18[0x5f4];
    local_30 = (double)CONCAT44(0x43300000,uVar20);
    f_op_msg_mng::fopMsgM_setNowAlpha
              ((fopMsgM_pane_class *)(this + iVar21 + 0x5c0),
               ((float)(local_30 - dVar17) -
               (float)((double)((float)((double)CONCAT44(0x43300000,uVar20) - dVar17) -
                               d_picture_box::_5696) * dVar23)) /
               (float)((double)CONCAT44(0x43300000,uVar20) - dVar17));
  }
  uVar20 = (uint)(byte)this[iVar21 + 0x69c];
  local_30 = (double)CONCAT44(0x43300000,uVar20);
  f_op_msg_mng::fopMsgM_setNowAlpha
            ((fopMsgM_pane_class *)(this + iVar21 + 0x668),
             ((float)(local_30 - d_picture_box::_4455) -
             (float)((double)((float)((double)CONCAT44(0x43300000,uVar20) - d_picture_box::_4455) -
                             d_picture_box::_5696) * dVar23)) /
             (float)((double)CONCAT44(0x43300000,uVar20) - d_picture_box::_4455));
  __psq_l0(auStack8,uVar22);
  __psq_l1(auStack8,uVar22);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall dJle_Pb_c::changeData(void) */

void __thiscall dJle_Pb_c::changeData(dJle_Pb_c *this)

{
  int in_r10;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = 0;
  iVar4 = 0;
  iVar1 = 0;
  iVar3 = 0;
  do {
    if (this[iVar1 + 0x1371] != (dJle_Pb_c)0x0) {
      if (iVar1 != iVar2) {
        this[iVar1 + 0x1371] = (dJle_Pb_c)0x0;
        this[iVar2 + 0x1371] = (dJle_Pb_c)0x1;
        copy_bytes(*(byte **)(this + iVar4 + 0x126c),*(byte **)(this + iVar3 + 0x126c),0x2000);
        os::DCStoreRangeNoSync(*(undefined4 *)(this + iVar4 + 0x126c),0x2000);
      }
      m_Do_MemCardRWmng::mDoMemCdRWm_SetCheckSumPictData(*(undefined4 *)(this + iVar3 + 0x126c));
      JKRAram::mainRamToAram
                (*(JKRAram **)(this + iVar3 + 0x126c),
                 *(uchar **)
                  ((int)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mDlstWindow + iVar4 + -0x44),
                 (JKRAramBlock *)0x2000,0,0,0,(JKRHeap *)&DAT_ffffffff,in_r10);
      iVar2 = iVar2 + 1;
      iVar4 = iVar4 + 4;
    }
    iVar1 = iVar1 + 1;
    iVar3 = iVar3 + 4;
  } while (iVar1 < 3);
  dSv_event_c::setEventReg(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x89ff,0);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dJle_Pb_c::label_sort(void) */

undefined4 __thiscall dJle_Pb_c::label_sort(dJle_Pb_c *this)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  iVar2 = 0;
  do {
    this[iVar2 + 0x1368] = (dJle_Pb_c)0xff;
    cVar1 = getPicLabelData(this,(uchar)SUB41(iVar2,0));
    if (cVar1 == '\0') {
      this[(uVar3 & 0xff) + 0x1368] = SUB41(iVar2,0);
      uVar3 = uVar3 + 1;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 3);
  return 1;
}


/* __thiscall dJle_Pb_c::getPicLabelData(unsigned char) */

uint __thiscall dJle_Pb_c::getPicLabelData(dJle_Pb_c *this,uchar param_1)

{
  uint uVar1;
  ushort uVar2;
  
  uVar2 = dSv_event_c::getEventReg(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x89ff);
  uVar1 = 0;
  if (param_1 < 3) {
    uVar1 = (uint)uVar2 & 1 << param_1 & 0xff;
  }
  return uVar1;
}


/* WARNING: Removing unreachable block (ram,0x80229d20) */
/* WARNING: Removing unreachable block (ram,0x80229d10) */
/* WARNING: Removing unreachable block (ram,0x80229d00) */
/* WARNING: Removing unreachable block (ram,0x80229cf0) */
/* WARNING: Removing unreachable block (ram,0x80229ce0) */
/* WARNING: Removing unreachable block (ram,0x80229cd8) */
/* WARNING: Removing unreachable block (ram,0x80229ce8) */
/* WARNING: Removing unreachable block (ram,0x80229cf8) */
/* WARNING: Removing unreachable block (ram,0x80229d08) */
/* WARNING: Removing unreachable block (ram,0x80229d18) */
/* WARNING: Removing unreachable block (ram,0x80229d28) */
/* __thiscall dJle_Pb_c::shutterLineRotateCenter(float,
                                                 int) */

void __thiscall dJle_Pb_c::shutterLineRotateCenter(dJle_Pb_c *this,float param_1,int param_2)

{
  dJle_Pb_c *pdVar1;
  undefined4 uVar2;
  double dVar3;
  undefined8 in_f21;
  double theta;
  undefined8 in_f22;
  double dVar4;
  undefined8 in_f23;
  double dVar5;
  undefined8 in_f24;
  double dVar6;
  undefined8 in_f25;
  double dVar7;
  undefined8 in_f26;
  double dVar8;
  undefined8 in_f27;
  double dVar9;
  undefined8 in_f28;
  double dVar10;
  undefined8 in_f29;
  double dVar11;
  undefined8 in_f30;
  double dVar12;
  undefined8 in_f31;
  double dVar13;
  undefined auStack168 [16];
  undefined auStack152 [16];
  undefined auStack136 [16];
  undefined auStack120 [16];
  undefined auStack104 [16];
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar2 = 0;
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
  __psq_st0(auStack120,(int)((ulonglong)in_f24 >> 0x20),0);
  __psq_st1(auStack120,(int)in_f24,0);
  __psq_st0(auStack136,(int)((ulonglong)in_f23 >> 0x20),0);
  __psq_st1(auStack136,(int)in_f23,0);
  __psq_st0(auStack152,(int)((ulonglong)in_f22 >> 0x20),0);
  __psq_st1(auStack152,(int)in_f22,0);
  __psq_st0(auStack168,(int)((ulonglong)in_f21 >> 0x20),0);
  __psq_st1(auStack168,(int)in_f21,0);
  pdVar1 = this + param_2 * 0x38;
  dVar10 = (double)(*(float *)(pdVar1 + 0x14) + *(float *)(pdVar1 + 0x2d4) * d_picture_box::_4203);
  dVar9 = (double)(*(float *)(pdVar1 + 0x20) - *(float *)(pdVar1 + 0x2d8) * d_picture_box::_4203);
  dVar8 = (double)(float)(dVar10 + (double)*(float *)(pdVar1 + 0x34));
  theta = (double)(d_picture_box::_5780 * (param_1 / d_picture_box::_4204));
  dVar3 = MSL_C.PPCEABI.bare.H::sin(theta);
  dVar7 = (double)(float)dVar3;
  dVar3 = MSL_C.PPCEABI.bare.H::cos(theta);
  dVar6 = (double)(float)dVar3;
  dVar3 = MSL_C.PPCEABI.bare.H::cos(theta);
  dVar5 = (double)(float)dVar3;
  dVar3 = MSL_C.PPCEABI.bare.H::sin(theta);
  dVar4 = (double)(float)dVar3;
  dVar3 = MSL_C.PPCEABI.bare.H::sin(theta);
  dVar13 = (double)(float)dVar3;
  dVar3 = MSL_C.PPCEABI.bare.H::cos(theta);
  dVar12 = (double)(float)dVar3;
  dVar3 = MSL_C.PPCEABI.bare.H::cos(theta);
  dVar11 = (double)(float)dVar3;
  dVar3 = MSL_C.PPCEABI.bare.H::sin(theta);
  pdVar1 = this + param_2 * 4;
  *(float *)(pdVar1 + 0x1280) =
       ((float)(dVar10 * dVar6) - (float)(dVar9 * dVar7)) + *(float *)(this + 0x954);
  *(float *)(pdVar1 + 0x12b0) =
       (float)(dVar10 * dVar4) + (float)(dVar9 * dVar5) + *(float *)(this + 0x958);
  *(float *)(pdVar1 + 0x12e0) =
       ((float)(dVar8 * dVar12) - (float)(dVar9 * dVar13)) + *(float *)(this + 0x954);
  *(float *)(pdVar1 + 0x1310) =
       (float)(dVar8 * (double)(float)dVar3) + (float)(dVar9 * dVar11) + *(float *)(this + 0x958);
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  __psq_l0(auStack24,uVar2);
  __psq_l1(auStack24,uVar2);
  __psq_l0(auStack40,uVar2);
  __psq_l1(auStack40,uVar2);
  __psq_l0(auStack56,uVar2);
  __psq_l1(auStack56,uVar2);
  __psq_l0(auStack72,uVar2);
  __psq_l1(auStack72,uVar2);
  __psq_l0(auStack88,uVar2);
  __psq_l1(auStack88,uVar2);
  __psq_l0(auStack104,uVar2);
  __psq_l1(auStack104,uVar2);
  __psq_l0(auStack120,uVar2);
  __psq_l1(auStack120,uVar2);
  __psq_l0(auStack136,uVar2);
  __psq_l1(auStack136,uVar2);
  __psq_l0(auStack152,uVar2);
  __psq_l1(auStack152,uVar2);
  __psq_l0(auStack168,uVar2);
  __psq_l1(auStack168,uVar2);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x80229f14) */
/* WARNING: Removing unreachable block (ram,0x80229f04) */
/* WARNING: Removing unreachable block (ram,0x80229ef4) */
/* WARNING: Removing unreachable block (ram,0x80229ee4) */
/* WARNING: Removing unreachable block (ram,0x80229ed4) */
/* WARNING: Removing unreachable block (ram,0x80229ecc) */
/* WARNING: Removing unreachable block (ram,0x80229edc) */
/* WARNING: Removing unreachable block (ram,0x80229eec) */
/* WARNING: Removing unreachable block (ram,0x80229efc) */
/* WARNING: Removing unreachable block (ram,0x80229f0c) */
/* WARNING: Removing unreachable block (ram,0x80229f1c) */
/* __thiscall dJle_Pb_c::shutterLineRotateInitPos(float,
                                                  int) */

void __thiscall dJle_Pb_c::shutterLineRotateInitPos(dJle_Pb_c *this,float param_1,int param_2)

{
  dJle_Pb_c *pdVar1;
  dJle_Pb_c *pdVar2;
  undefined4 uVar3;
  double dVar4;
  undefined8 in_f21;
  double theta;
  undefined8 in_f22;
  double dVar5;
  undefined8 in_f23;
  double dVar6;
  undefined8 in_f24;
  double dVar7;
  undefined8 in_f25;
  double dVar8;
  undefined8 in_f26;
  double dVar9;
  undefined8 in_f27;
  double dVar10;
  undefined8 in_f28;
  double dVar11;
  undefined8 in_f29;
  double dVar12;
  undefined8 in_f30;
  double dVar13;
  undefined8 in_f31;
  double dVar14;
  undefined auStack168 [16];
  undefined auStack152 [16];
  undefined auStack136 [16];
  undefined auStack120 [16];
  undefined auStack104 [16];
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
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
  __psq_st0(auStack136,(int)((ulonglong)in_f23 >> 0x20),0);
  __psq_st1(auStack136,(int)in_f23,0);
  __psq_st0(auStack152,(int)((ulonglong)in_f22 >> 0x20),0);
  __psq_st1(auStack152,(int)in_f22,0);
  __psq_st0(auStack168,(int)((ulonglong)in_f21 >> 0x20),0);
  __psq_st1(auStack168,(int)in_f21,0);
  pdVar1 = this + param_2 * 0x38;
  dVar11 = (double)(*(float *)(pdVar1 + 0x14) + *(float *)(pdVar1 + 0x2d4) * d_picture_box::_4203);
  dVar10 = (double)(*(float *)(pdVar1 + 0x20) - *(float *)(pdVar1 + 0x2d8) * d_picture_box::_4203);
  dVar9 = (double)(float)(dVar11 + (double)*(float *)(pdVar1 + 0x34));
  theta = (double)(d_picture_box::_5780 * (param_1 / d_picture_box::_4204));
  dVar4 = MSL_C.PPCEABI.bare.H::sin(theta);
  dVar8 = (double)(float)dVar4;
  dVar4 = MSL_C.PPCEABI.bare.H::cos(theta);
  dVar7 = (double)(float)dVar4;
  dVar4 = MSL_C.PPCEABI.bare.H::cos(theta);
  dVar6 = (double)(float)dVar4;
  dVar4 = MSL_C.PPCEABI.bare.H::sin(theta);
  dVar5 = (double)(float)dVar4;
  dVar4 = MSL_C.PPCEABI.bare.H::sin(theta);
  dVar14 = (double)(float)dVar4;
  dVar4 = MSL_C.PPCEABI.bare.H::cos(theta);
  dVar13 = (double)(float)dVar4;
  dVar4 = MSL_C.PPCEABI.bare.H::cos(theta);
  dVar12 = (double)(float)dVar4;
  dVar4 = MSL_C.PPCEABI.bare.H::sin(theta);
  pdVar2 = this + param_2 * 0x38;
  pdVar1 = this + param_2 * 4;
  *(float *)(pdVar1 + 0x1280) =
       ((float)(dVar11 * dVar7) - (float)(dVar10 * dVar8)) + *(float *)(pdVar2 + 0x2c4);
  *(float *)(pdVar1 + 0x12b0) =
       (float)(dVar11 * dVar5) + (float)(dVar10 * dVar6) + *(float *)(pdVar2 + 0x2c8);
  *(float *)(pdVar1 + 0x12e0) =
       ((float)(dVar9 * dVar13) - (float)(dVar10 * dVar14)) + *(float *)(pdVar2 + 0x2c4);
  *(float *)(pdVar1 + 0x1310) =
       (float)(dVar9 * (double)(float)dVar4) + (float)(dVar10 * dVar12) + *(float *)(pdVar2 + 0x2c8)
  ;
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
  __psq_l0(auStack136,uVar3);
  __psq_l1(auStack136,uVar3);
  __psq_l0(auStack152,uVar3);
  __psq_l1(auStack152,uVar3);
  __psq_l0(auStack168,uVar3);
  __psq_l1(auStack168,uVar3);
  return;
}


/* __thiscall dJle_Pb_c::shutterLineMove(void) */

void __thiscall dJle_Pb_c::shutterLineMove(dJle_Pb_c *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  int iVar9;
  dJle_Pb_c *pdVar10;
  dJle_Pb_c *pdVar11;
  int iVar12;
  int iVar13;
  float local_68 [12];
  float local_38 [14];
  
  iVar12 = 0;
  iVar9 = 0;
  iVar13 = 0xc;
  do {
    pdVar11 = this + iVar9;
    fVar1 = *(float *)(pdVar11 + 0x1280);
    fVar3 = d_picture_box::_4527;
    fVar4 = d_picture_box::_4202;
    fVar6 = fVar1;
    if (fVar1 != *(float *)(pdVar11 + 0x12e0)) {
      fVar3 = -(*(float *)(pdVar11 + 0x12b0) - *(float *)(pdVar11 + 0x1310)) /
              (fVar1 - *(float *)(pdVar11 + 0x12e0));
      fVar4 = d_picture_box::_4527;
      fVar6 = *(float *)(pdVar11 + 0x12b0) + fVar3 * fVar1;
    }
    pdVar10 = this + (iVar12 + 1U & ~-(uint)(iVar12 == 0xb)) * 4;
    fVar2 = *(float *)(pdVar10 + 0x1280);
    fVar5 = d_picture_box::_4527;
    fVar7 = d_picture_box::_4202;
    if (fVar2 != *(float *)(pdVar10 + 0x12e0)) {
      fVar5 = -(*(float *)(pdVar10 + 0x12b0) - *(float *)(pdVar10 + 0x1310)) /
              (fVar2 - *(float *)(pdVar10 + 0x12e0));
      fVar2 = *(float *)(pdVar10 + 0x12b0) + fVar5 * fVar2;
      fVar7 = d_picture_box::_4527;
    }
    fVar8 = fVar3 * fVar7 - fVar5 * fVar4;
    if (fVar8 == d_picture_box::_4202) {
      *(float *)((int)local_38 + iVar9) = fVar1;
      *(undefined4 *)((int)local_68 + iVar9) = *(undefined4 *)(pdVar11 + 0x12b0);
    }
    else {
      *(float *)((int)local_38 + iVar9) = (fVar7 * fVar6 - fVar4 * fVar2) / fVar8;
      *(float *)((int)local_68 + iVar9) = (-fVar5 * fVar6 + fVar3 * fVar2) / fVar8;
    }
    iVar12 = iVar12 + 1;
    iVar9 = iVar9 + 4;
    iVar13 = iVar13 + -1;
  } while (iVar13 != 0);
  iVar9 = 0;
  iVar12 = 0xc;
  do {
    *(undefined4 *)(this + iVar9 + 0x1280) = *(undefined4 *)((int)local_38 + iVar9);
    *(undefined4 *)(this + iVar9 + 0x12b0) = *(undefined4 *)((int)local_68 + iVar9);
    iVar9 = iVar9 + 4;
    iVar12 = iVar12 + -1;
  } while (iVar12 != 0);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dJle_Pb_c::shutterLineDraw(unsigned char) */

void __thiscall dJle_Pb_c::shutterLineDraw(dJle_Pb_c *this,uchar param_1)

{
  uint uVar1;
  dJle_Pb_c *pdVar2;
  int iVar3;
  int iVar4;
  uint local_18;
  uint local_14;
  
  local_14 = CONCAT31(0xffff00,param_1) | 0xff00;
  uVar1 = local_14;
  iVar3 = 0;
  iVar4 = 0;
  do {
    local_18 = uVar1;
    pdVar2 = this + iVar4;
    J2DGraph::J2DDrawLine
              ((double)*(float *)(pdVar2 + 0x1280),(double)*(float *)(pdVar2 + 0x12b0),
               (double)*(float *)(pdVar2 + 0x12e0),(double)*(float *)(pdVar2 + 0x1310),&local_18,0xc
              );
    iVar3 = iVar3 + 1;
    iVar4 = iVar4 + 4;
  } while (iVar3 < 0xc);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x8022a780) */
/* WARNING: Removing unreachable block (ram,0x8022a788) */
/* __thiscall dJle_Pb_c::messageSet(unsigned long) */

void __thiscall dJle_Pb_c::messageSet(dJle_Pb_c *this,ulong param_1)

{
  dJle_Pb_c dVar1;
  float fVar2;
  bool bVar3;
  float fVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  ulong uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  ___ _Var11;
  int iVar12;
  undefined4 uVar13;
  undefined8 in_f30;
  double dVar14;
  undefined8 in_f31;
  double dVar15;
  undefined1 *local_c8;
  undefined4 local_c4;
  undefined2 local_c0;
  undefined2 local_be;
  undefined2 local_bc;
  undefined4 local_b8;
  undefined2 local_b4;
  undefined2 local_b2;
  undefined2 local_b0;
  undefined2 local_ae;
  dJle_Pb_c local_ac;
  dJle_Pb_c local_ab;
  dJle_Pb_c local_aa;
  dJle_Pb_c local_a9;
  dJle_Pb_c local_a8;
  dJle_Pb_c local_a7;
  dJle_Pb_c local_a6;
  dJle_Pb_c local_a5;
  dJle_Pb_c local_a4;
  dJle_Pb_c local_a3;
  dJle_Pb_c local_a2;
  dJle_Pb_c local_a1;
  char acStack160 [28];
  char acStack132 [28];
  longlong local_68;
  longlong local_60;
  double local_58;
  longlong local_50;
  double local_48;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar13 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  local_c8 = &fopMsgM_msgGet_c::__vt;
  local_c4 = 0;
  local_c0 = 0;
  local_be = 0;
  local_bc = 0;
  uVar5 = f_op_msg_mng::fopMsgM_getColorTable(0);
  bVar3 = false;
  this[0x136f] = (dJle_Pb_c)0x0;
  dVar15 = (double)*(float *)(*(int *)(this + 0xf60) + 0xe8);
  dVar14 = (double)*(float *)(*(int *)(this + 0xf68) + 0xe8);
  *(undefined *)(*(int *)(this + 0xf84) + 0xaa) = 0;
  *(undefined *)(*(int *)(this + 0xf88) + 0xaa) = 0;
  *(undefined *)(*(int *)(this + 0xf8c) + 0xaa) = 0;
  *(undefined *)(*(int *)(this + 0xf84) + 0xac) = 0;
  *(undefined *)(*(int *)(this + 0xf88) + 0xac) = 0;
  *(undefined *)(*(int *)(this + 0xf8c) + 0xac) = 0;
  this[0x1375] = (dJle_Pb_c)0xff;
  *(undefined2 *)(this + 0x1366) = 0xffff;
  if (*(void **)(this + 4000) != (void *)0x0) {
    JKRFileLoader::removeResource(*(void **)(this + 4000),(JKRFileLoader *)0x0);
    *(undefined4 *)(this + 4000) = 0;
  }
  uVar6 = fopMsgM_msgGet_c::getMesgHeader((fopMsgM_msgGet_c *)&local_c8,param_1);
  *(undefined4 *)(this + 4000) = uVar6;
  if (*(int *)(this + 4000) == 0) {
    uVar7 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar7,"d_picture_box.cpp",0x759,"head_p");
    m_Do_printf::OSPanic("d_picture_box.cpp",0x759,&DAT_8036270a);
  }
  uVar6 = fopMsgM_msgGet_c::getMessage((fopMsgM_msgGet_c *)&local_c8,*(mesg_header **)(this + 4000))
  ;
  fopMsgM_msgGet_c::getMesgEntry((fopMsgM_msgGet_c *)&local_b8,(mesg_header *)&local_c8);
  *(undefined4 *)(this + 0xfa4) = local_b8;
  *(undefined2 *)(this + 0xfa8) = local_b4;
  *(undefined2 *)(this + 0xfaa) = local_b2;
  *(undefined2 *)(this + 0xfac) = local_b0;
  *(undefined2 *)(this + 0xfae) = local_ae;
  this[0xfb0] = local_ac;
  this[0xfb1] = local_ab;
  this[0xfb2] = local_aa;
  this[0xfb3] = local_a9;
  this[0xfb4] = local_a8;
  this[0xfb5] = local_a7;
  this[0xfb6] = local_a6;
  this[0xfb7] = local_a5;
  this[0xfb8] = local_a4;
  this[0xfb9] = local_a3;
  this[0xfba] = local_a2;
  this[0xfbb] = local_a1;
  MSL_C.PPCEABI.bare.H::sprintf(acStack132,"\x1bCC[%08x]\x1bGM[0]",uVar5);
  MSL_C.PPCEABI.bare.H::sprintf(acStack160,"\x1bCC[000000FF]\x1bGM[0]");
  MSL_C.PPCEABI.bare.H::strcpy(*(char **)(this + 0x1350),acStack132);
  MSL_C.PPCEABI.bare.H::strcpy(*(char **)(this + 0x1354),acStack132);
  MSL_C.PPCEABI.bare.H::strcpy(*(char **)(this + 0x1358),acStack160);
  MSL_C.PPCEABI.bare.H::strcpy(*(char **)(this + 0x135c),acStack160);
  fopMsgM_msgDataProc_c::dataInit((fopMsgM_msgDataProc_c *)(this + 0xfbc));
  *(undefined4 *)(this + 0xff8) = uVar6;
  _Var11 = *(___ *)(this + 0x135c);
  *(undefined4 *)(this + 0x101c) = *(undefined4 *)(this + 0x1350);
  *(undefined4 *)(this + 0xffc) = *(undefined4 *)(this + 0x1350);
  *(undefined4 *)(this + 0x1020) = *(undefined4 *)(this + 0x1354);
  *(undefined4 *)(this + 0x1000) = *(undefined4 *)(this + 0x1354);
  *(undefined4 *)(this + 0x1024) = *(undefined4 *)(this + 0x1358);
  *(undefined4 *)(this + 0x1004) = *(undefined4 *)(this + 0x1358);
  *(___ *)(this + 0x1028) = _Var11;
  *(___ *)(this + 0x1008) = _Var11;
  *(undefined4 *)(this + 0xfc0) = *(undefined4 *)(this + 0xf90);
  *(undefined4 *)(this + 0xfc4) = *(undefined4 *)(this + 0xf94);
  local_68 = (longlong)(int)*(float *)(*(int *)(this + 0xf60) + 0xe0);
  *(int *)(this + 0x10d8) = (int)*(float *)(*(int *)(this + 0xf60) + 0xe0);
  local_60 = (longlong)(int)*(float *)(*(int *)(this + 0xf68) + 0xe0);
  *(int *)(this + 0x10e0) = (int)*(float *)(*(int *)(this + 0xf68) + 0xe0);
  local_58 = (double)(longlong)(int)*(float *)(*(int *)(this + 0xf60) + 0xe4);
  *(int *)(this + 0x10dc) = (int)*(float *)(*(int *)(this + 0xf60) + 0xe4);
  *(dJle_Pb_c **)(this + 0xfc8) = this + 0xfa4;
  local_50 = (longlong)(int)dVar15;
  *(int *)(this + 0x1100) = (int)dVar15;
  local_48 = (double)(longlong)(int)dVar14;
  *(int *)(this + 0x1108) = (int)dVar14;
  *(undefined4 *)(this + 0x10e4) = 0x1f7;
  *(undefined4 *)(this + 0x10e8) = 0x1e6;
  *(uint *)(this + 0x111c) = (uint)DAT_803e6bc6;
  *(int *)(this + 0x1118) = (int)DAT_803e6bb0;
  this[0x1255] = (dJle_Pb_c)0x1;
  if (DAT_803e6bc7 == '\0') {
    this[0x1258] = (dJle_Pb_c)0x0;
  }
  else {
    this[0x1258] = (dJle_Pb_c)0x1;
  }
  fopMsgM_msgDataProc_c::stringLength((fopMsgM_msgDataProc_c *)(this + 0xfbc));
  fopMsgM_msgDataProc_c::stringShift((fopMsgM_msgDataProc_c *)(this + 0xfbc));
  fopMsgM_msgDataProc_c::iconIdxRefresh((fopMsgM_msgDataProc_c *)(this + 0xfbc));
  *(short *)(this + 0x1364) = (short)*(undefined4 *)(this + 0x10ec);
  iVar9 = 0;
  *(undefined4 *)(this + 0x10ec) = 0;
  fVar4 = d_picture_box::_4202;
  local_48 = (double)CONCAT44(0x43300000,2U - (int)*(short *)(this + 0x1364) ^ 0x80000000);
  dVar14 = local_48 - d_picture_box::_4296;
  fVar2 = *(float *)(*(int *)(this + 0xf60) + 0xe4) * d_picture_box::_4203;
  iVar12 = 4;
  do {
    iVar8 = *(int *)(this + iVar9 + 0xf60);
    *(float *)(iVar8 + 0xd8) = fVar4;
    *(float *)(iVar8 + 0xdc) = (float)dVar14 * fVar2;
    iVar9 = iVar9 + 8;
    iVar12 = iVar12 + -1;
  } while (iVar12 != 0);
  fopMsgM_msgDataProc_c::stringSet((fopMsgM_msgDataProc_c *)(this + 0xfbc));
  iVar9 = 0;
  iVar12 = 0;
  iVar8 = 0;
  do {
    J2DTextBox::setString
              (*(J2DTextBox **)(this + iVar8 + 0xf60),*(char **)(this + iVar12 + 0x1350),_Var11);
    iVar9 = iVar9 + 1;
    iVar12 = iVar12 + 4;
    iVar8 = iVar8 + 8;
  } while (iVar9 < 4);
  iVar9 = 0;
  iVar12 = 0;
  dVar14 = (double)d_picture_box::_4203;
  do {
    dVar15 = d_picture_box::_4296;
    iVar10 = *(int *)(this + 0xf60);
    iVar8 = (int)((double)*(float *)(iVar10 + 0xe4) * dVar14);
    local_48 = (double)(longlong)iVar8;
    dVar1 = this[iVar9 + 0x123d];
    if (dVar1 == (dJle_Pb_c)0x14) {
      local_48 = (double)CONCAT44(0x43300000,*(uint *)(this + iVar12 + 0x1124) ^ 0x80000000);
      iVar10 = (int)(*(float *)(iVar10 + 0xc) + (float)(local_48 - d_picture_box::_4296));
      local_50 = (longlong)iVar10;
      *(int *)(this + 0x1340) = iVar10;
      local_58 = (double)CONCAT44(0x43300000,
                                  iVar8 * ((2 - *(short *)(this + 0x1364)) +
                                          *(int *)(this + iVar12 + 0x1160) * 2) ^ 0x80000000);
      iVar8 = (int)(*(float *)(*(int *)(this + 0xf60) + 0x10) + (float)(local_58 - dVar15));
      local_60 = (longlong)iVar8;
      *(int *)(this + 0x1348) = iVar8;
      *(undefined *)(*(int *)(this + 0xf8c) + 0xaa) = 1;
      *(undefined *)(*(int *)(this + 0xf8c) + 0xac) = 0xff;
      this[0x1375] = SUB41(iVar9,0);
      if (bVar3) {
        bVar3 = false;
        this[0x136f] = (dJle_Pb_c)0x0;
      }
      else {
        bVar3 = true;
        this[0x136f] = (dJle_Pb_c)0x1;
      }
    }
    else {
      if (dVar1 == (dJle_Pb_c)0x15) {
        local_48 = (double)CONCAT44(0x43300000,*(uint *)(this + iVar12 + 0x1124) ^ 0x80000000);
        iVar10 = (int)(*(float *)(iVar10 + 0xc) + (float)(local_48 - d_picture_box::_4296));
        local_50 = (longlong)iVar10;
        *(int *)(this + 0x1344) = iVar10;
        local_58 = (double)CONCAT44(0x43300000,
                                    iVar8 * ((1 - *(short *)(this + 0x1364)) +
                                            *(int *)(this + iVar12 + 0x1160) * 2) ^ 0x80000000);
        iVar8 = (int)(*(float *)(*(int *)(this + 0xf60) + 0x10) + (float)(local_58 - dVar15));
        local_60 = (longlong)iVar8;
        *(int *)(this + 0x134c) = iVar8;
        *(undefined *)(*(int *)(this + 0xf8c) + 0xaa) = 1;
        *(undefined *)(*(int *)(this + 0xf8c) + 0xac) = 0xff;
        this[0x1375] = SUB41(iVar9,0);
        if (bVar3) {
          this[0x136f] = (dJle_Pb_c)0x1;
        }
        else {
          this[0x136f] = (dJle_Pb_c)0x0;
        }
      }
      else {
        if ((dVar1 != (dJle_Pb_c)0xff) && (*(short *)(this + 0x1366) == -1)) {
          f_op_msg_mng::fopMsgM_outFontSet
                    (*(undefined4 *)(this + 0xf84),*(undefined4 *)(this + 0xf88),this + 0x1366,
                     *(undefined4 *)(this + 0x1218));
        }
      }
    }
    iVar9 = iVar9 + 1;
    iVar12 = iVar12 + 4;
  } while (iVar9 < 0xf);
  if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mConfig._0_1_ == '\0') {
    if (*(char *)(*(int *)(this + 0xf68) + 0xaa) != '\0') {
      *(undefined *)(*(int *)(this + 0xf68) + 0xaa) = 1;
    }
    if (*(char *)(*(int *)(this + 0xf78) + 0xaa) != '\0') {
      *(undefined *)(*(int *)(this + 0xf78) + 0xaa) = 1;
    }
  }
  else {
    *(undefined *)(*(int *)(this + 0xf68) + 0xaa) = 0;
    *(undefined *)(*(int *)(this + 0xf78) + 0xaa) = 0;
  }
  __psq_l0(auStack8,uVar13);
  __psq_l1(auStack8,uVar13);
  __psq_l0(auStack24,uVar13);
  __psq_l1(auStack24,uVar13);
  return;
}


/* __thiscall dJle_Pb_c::remainMessageSet(unsigned char) */

void __thiscall dJle_Pb_c::remainMessageSet(dJle_Pb_c *this,uchar param_1)

{
  if (param_1 == '\0') {
    messageSet(this,0xed9);
  }
  else {
    if (param_1 == '\x01') {
      messageSet(this,0xeda);
    }
    else {
      if (param_1 == '\x02') {
        messageSet(this,0xedb);
      }
      else {
        if (param_1 == '\x03') {
          messageSet(this,0xedc);
        }
      }
    }
  }
  return;
}


/* __thiscall dJle_Pb_c::existMessageSet(unsigned char) */

void __thiscall dJle_Pb_c::existMessageSet(dJle_Pb_c *this,uchar param_1)

{
  if (param_1 == '\0') {
    messageSet(this,0xee1);
  }
  else {
    if (param_1 == '\x01') {
      messageSet(this,0xee0);
    }
    else {
      if (param_1 == '\x02') {
        messageSet(this,0xedf);
      }
      else {
        if (param_1 == '\x03') {
          messageSet(this,0xede);
        }
      }
    }
  }
  return;
}


/* __thiscall dJle_Pb_c::shutterShow(void) */

void __thiscall dJle_Pb_c::shutterShow(dJle_Pb_c *this)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 0xc;
  do {
    *(undefined *)(*(int *)(this + iVar1 + 0x2b0) + 0xaa) = 1;
    *(undefined *)(*(int *)(this + iVar1 + 0x10) + 0xaa) = 1;
    iVar1 = iVar1 + 0x38;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


/* __thiscall dJle_Pb_c::shutterHide(void) */

void __thiscall dJle_Pb_c::shutterHide(dJle_Pb_c *this)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 0xc;
  do {
    *(undefined *)(*(int *)(this + iVar1 + 0x2b0) + 0xaa) = 0;
    *(undefined *)(*(int *)(this + iVar1 + 0x10) + 0xaa) = 0;
    iVar1 = iVar1 + 0x38;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x8022af24) */
/* __thiscall dJle_Pb_c::_create(JKRExpHeap *) */

void __thiscall dJle_Pb_c::_create(dJle_Pb_c *this,JKRExpHeap *param_1)

{
  J2DPane *pJVar1;
  ulong uVar2;
  JUTFont *pJVar3;
  STControl *this_00;
  J2DPicture *pJVar4;
  undefined4 uVar5;
  dJle_Pb_c *pdVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  undefined8 in_f31;
  double dVar11;
  TBox2_float_ local_60;
  TBox2_float_ local_50;
  TBox2_float_ local_40;
  undefined4 local_30;
  uint uStack44;
  undefined auStack8 [8];
  
  uVar10 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  iVar8 = 0;
  iVar7 = 0;
  pJVar1 = (J2DPane *)JKernel::operator_new(0xd4);
  if (pJVar1 != (J2DPane *)0x0) {
    local_40.mTL.x = d_picture_box::_4202;
    local_40.mTL.y = d_picture_box::_4202;
    local_40.mBR.x = d_picture_box::_4927;
    local_40.mBR.y = d_picture_box::_4928;
    J2DPane::J2DPane(pJVar1,(J2DPane *)0x0,true,0x726f6f74,&local_40);
    pJVar1->vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
    *(undefined4 *)pJVar1[1].mMagic = 0xffffffff;
    *(undefined *)&pJVar1[1].vtbl = 0;
  }
  *(J2DPane **)(this + 4) = pJVar1;
  if (*(int *)(this + 4) == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_picture_box.cpp",0x826,"scrn != 0");
    m_Do_printf::OSPanic("d_picture_box.cpp",0x826,&DAT_8036270a);
  }
  J2DScreen::set(*(J2DScreen **)(this + 4),"wipe_01_01.blo",
                 d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCamResArchive);
  pJVar1 = (J2DPane *)JKernel::operator_new(0xd4);
  if (pJVar1 != (J2DPane *)0x0) {
    local_50.mTL.x = d_picture_box::_4202;
    local_50.mTL.y = d_picture_box::_4202;
    local_50.mBR.x = d_picture_box::_4927;
    local_50.mBR.y = d_picture_box::_4928;
    J2DPane::J2DPane(pJVar1,(J2DPane *)0x0,true,0x726f6f74,&local_50);
    pJVar1->vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
    *(undefined4 *)pJVar1[1].mMagic = 0xffffffff;
    *(undefined *)&pJVar1[1].vtbl = 0;
  }
  *(J2DPane **)(this + 8) = pJVar1;
  if (*(int *)(this + 8) == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_picture_box.cpp",0x82a,"scrn1 != 0");
    m_Do_printf::OSPanic("d_picture_box.cpp",0x82a,&DAT_8036270a);
  }
  J2DScreen::set(*(J2DScreen **)(this + 8),"wipe_01_02.blo",
                 d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCamResArchive);
  pJVar1 = (J2DPane *)JKernel::operator_new(0xd4);
  if (pJVar1 != (J2DPane *)0x0) {
    local_60.mTL.x = d_picture_box::_4202;
    local_60.mTL.y = d_picture_box::_4202;
    local_60.mBR.x = d_picture_box::_4927;
    local_60.mBR.y = d_picture_box::_4928;
    J2DPane::J2DPane(pJVar1,(J2DPane *)0x0,true,0x726f6f74,&local_60);
    pJVar1->vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
    *(undefined4 *)pJVar1[1].mMagic = 0xffffffff;
    *(undefined *)&pJVar1[1].vtbl = 0;
  }
  *(J2DPane **)(this + 0xc) = pJVar1;
  if (*(int *)(this + 0xc) == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_picture_box.cpp",0x82e,"scrn2 != 0");
    m_Do_printf::OSPanic("d_picture_box.cpp",0x82e,&DAT_8036270a);
  }
  J2DScreen::set(*(J2DScreen **)(this + 0xc),"hukidashi_08.blo",
                 d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpMsgArchive);
  pJVar3 = m_Do_ext::mDoExt_getMesgFont();
  *(JUTFont **)(this + 0xf90) = pJVar3;
  if (*(int *)(this + 0xf90) == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_picture_box.cpp",0x832,"font0 != 0");
    m_Do_printf::OSPanic("d_picture_box.cpp",0x832,&DAT_8036270a);
  }
  pJVar3 = m_Do_ext::mDoExt_getRubyFont();
  *(JUTFont **)(this + 0xf94) = pJVar3;
  if (*(int *)(this + 0xf94) == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_picture_box.cpp",0x836,"font1 != 0");
    m_Do_printf::OSPanic("d_picture_box.cpp",0x836,&DAT_8036270a);
  }
  this_00 = (STControl *)JKernel::operator_new(0x28);
  if (this_00 != (STControl *)0x0) {
    STControl::STControl(this_00,5,2,3,2,d_picture_box::_6248,d_picture_box::_4203,0,0x2000);
  }
  *(STControl **)(this + 0xf98) = this_00;
  if (*(int *)(this + 0xf98) == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_picture_box.cpp",0x83b,"stick != 0");
    m_Do_printf::OSPanic("d_picture_box.cpp",0x83b,&DAT_8036270a);
  }
  pJVar4 = (J2DPicture *)JKernel::operator_new(0x124);
  if (pJVar4 != (J2DPicture *)0x0) {
    J2DPicture::J2DPicture(pJVar4,"font_07_02.bti");
  }
  *(J2DPicture **)(this + 0xf84) = pJVar4;
  pJVar4 = (J2DPicture *)JKernel::operator_new(0x124);
  if (pJVar4 != (J2DPicture *)0x0) {
    J2DPicture::J2DPicture(pJVar4,"font_07_02.bti");
  }
  *(J2DPicture **)(this + 0xf88) = pJVar4;
  pJVar4 = (J2DPicture *)JKernel::operator_new(0x124);
  if (pJVar4 != (J2DPicture *)0x0) {
    J2DPicture::J2DPicture(pJVar4,"font_10.bti");
  }
  *(J2DPicture **)(this + 0xf8c) = pJVar4;
  *(undefined4 *)(this + 0xf80) = 0;
  f_op_msg_mng::fopMsgM_blendInit(*(undefined4 *)(this + 0xf84),"font_00.bti");
  f_op_msg_mng::fopMsgM_blendInit(*(undefined4 *)(this + 0xf88),"font_00.bti");
  f_op_msg_mng::fopMsgM_blendInit(*(undefined4 *)(this + 0xf8c),"font_10.bti");
  *(undefined *)(*(int *)(this + 0xf84) + 0xaa) = 0;
  *(undefined *)(*(int *)(this + 0xf88) + 0xaa) = 0;
  *(undefined *)(*(int *)(this + 0xf8c) + 0xaa) = 0;
  *(undefined *)(*(int *)(this + 0xf84) + 0xac) = 0;
  *(undefined *)(*(int *)(this + 0xf88) + 0xac) = 0;
  *(undefined *)(*(int *)(this + 0xf8c) + 0xac) = 0;
  *(undefined2 *)(this + 0x1366) = 0xffff;
  screenSet(this);
  screenSet2(this);
  *(float *)(this + 0x127c) = d_picture_box::_4202;
  *(undefined2 *)(this + 0x1360) = 0;
  *(undefined2 *)(this + 0x1362) = 0;
  this[0x1370] = (dJle_Pb_c)0x0;
  this[0x1375] = (dJle_Pb_c)0xff;
  if (d_com_inf_game::g_dComIfG_gameInfo.field_0x5bfe == 2) {
    this[0x136b] = (dJle_Pb_c)0x2;
    this[0x136d] = (dJle_Pb_c)0x1;
  }
  else {
    if (d_com_inf_game::g_dComIfG_gameInfo.field_0x5bfe == 3) {
      this[0x136b] = (dJle_Pb_c)0x4;
      uVar5 = mDoDvdThd_toMainRam_c::create
                        (*(char **)(&d_picture_box::photo_data +
                                   (uint)d_com_inf_game::g_dComIfG_gameInfo._23551_1_ * 4),0,
                         &param_1->parent);
      *(undefined4 *)(this + 0xf80) = uVar5;
      this[0x136d] = (dJle_Pb_c)0x2;
    }
    else {
      this[0x136b] = (dJle_Pb_c)0x0;
      this[0x136d] = (dJle_Pb_c)0x0;
    }
  }
  this[0x136c] = (dJle_Pb_c)0x0;
  zoomScale(this);
  this[0x136e] = (dJle_Pb_c)0x0;
  *(undefined4 *)(this + 4000) = 0;
  this[0x1374] = (dJle_Pb_c)0x0;
  this[0x1376] = (dJle_Pb_c)0x1;
  *(undefined2 *)(this + 0x1364) = 0;
  *(undefined4 *)(this + 0x134c) = 0;
  *(undefined4 *)(this + 0x1348) = 0;
  *(undefined4 *)(this + 0x1344) = 0;
  *(undefined4 *)(this + 0x1340) = 0;
  label_sort(this);
  iVar9 = 0;
  do {
    pdVar6 = this + iVar9;
    pdVar6[0x1371] = (dJle_Pb_c)0x0;
    if ((iVar9 < (int)(uint)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord.
                            _2_1_) && (pdVar6[0x1368] != (dJle_Pb_c)0xff)) {
      this[iVar8 + 0x1371] = (dJle_Pb_c)0x1;
      JKRAram::aramToMainRam
                (*(JKRAramBlock **)
                  ((int)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mDlstWindow +
                  (uint)(byte)pdVar6[0x1368] * 4 + -0x44),*(uchar **)(this + iVar7 + 0x126c),0x2000,
                 0,0,0,(JKRHeap *)0x0,-1,(ulong *)0x0);
      iVar8 = iVar8 + 1;
      iVar7 = iVar7 + 4;
    }
    iVar9 = iVar9 + 1;
  } while (iVar9 < 3);
  iVar7 = 0;
  iVar8 = 0;
  dVar11 = d_picture_box::_4296;
  do {
    uStack44 = (int)*(short *)(this + iVar8 + 0x2e6) ^ 0x80000000;
    local_30 = 0x43300000;
    shutterLineRotateInitPos(this,(float)((double)CONCAT44(0x43300000,uStack44) - dVar11),iVar7);
    iVar7 = iVar7 + 1;
    iVar8 = iVar8 + 0x38;
  } while (iVar7 < 0xc);
  __psq_l0(auStack8,uVar10);
  __psq_l1(auStack8,uVar10);
  return;
}


/* __thiscall dJle_Pb_c::_copen(void) */

void __thiscall dJle_Pb_c::_copen(dJle_Pb_c *this)

{
  double dVar1;
  
  if (*(short *)(this + 0x1360) == 0) {
    remainMessageSet(this,d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._2_1_
                    );
  }
  *(short *)(this + 0x1360) = *(short *)(this + 0x1360) + 1;
  dVar1 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,(int)*(short *)(this + 0x1360),0);
  cameraAlphaInc(this,(float)dVar1);
  if (*(short *)(this + 0x1360) == 10) {
    d_com_inf_game::g_dComIfG_gameInfo.mbCamOverrideFarPlane = 0xb;
    this[0x136b] = (dJle_Pb_c)0x1;
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x823,(cXyz *)0x0,0,0,d_picture_box::_4527,
               d_picture_box::_4527,d_picture_box::_4529,d_picture_box::_4529,0);
  }
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0;
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd1 = 0;
  up_downIconMove(this);
  return;
}


/* __thiscall dJle_Pb_c::_bopen(void) */

void __thiscall dJle_Pb_c::_bopen(dJle_Pb_c *this)

{
  double dVar1;
  
  if (*(short *)(this + 0x1360) == 0) {
    if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._2_1_ == '\0') {
      messageSet(this,0xee4);
    }
    else {
      existMessageSet(this,d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord.
                           _2_1_);
    }
  }
  *(short *)(this + 0x1360) = *(short *)(this + 0x1360) + 1;
  dVar1 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,(int)*(short *)(this + 0x1360),0);
  browseAlphaInc(this,(float)dVar1);
  if (*(short *)(this + 0x1360) == 10) {
    d_com_inf_game::g_dComIfG_gameInfo.mbCamOverrideFarPlane = 0xb;
    this[0x136b] = (dJle_Pb_c)0x3;
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x823,(cXyz *)0x0,0,0,d_picture_box::_4527,
               d_picture_box::_4527,d_picture_box::_4529,d_picture_box::_4529,0);
  }
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd1 = 0;
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0;
  return;
}


/* __thiscall dJle_Pb_c::_gopen(void) */

void __thiscall dJle_Pb_c::_gopen(dJle_Pb_c *this)

{
  byte *dst;
  double dVar1;
  
  if (*(short *)(this + 0x1360) == 0) {
    messageSet(this,0xee5);
  }
  if (*(short *)(this + 0x1360) < 10) {
    *(short *)(this + 0x1360) = *(short *)(this + 0x1360) + 1;
    dVar1 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,(int)*(short *)(this + 0x1360),0);
    getAlphaInc(this,(float)dVar1);
  }
  else {
    if (*(char *)(*(int *)(this + 0xf80) + 0xc) != '\0') {
      dst = *(byte **)(this + 0x1278);
      copy_bytes(dst,*(byte **)(*(int *)(this + 0xf80) + 0x1c),0x1ee0);
      os::DCStoreRangeNoSync(dst,0x1ee0);
      *(uint *)(dst + 0x1ee0) =
           (uint)(byte)(&d_picture_box::photo_idx)[d_com_inf_game::g_dComIfG_gameInfo._23551_1_];
      dst[0x1ee4] = 0;
      dst[0x1ee5] = 0xe;
      d_com_inf_game::g_dComIfG_gameInfo.mbCamOverrideFarPlane = 0xb;
      this[0x136b] = (dJle_Pb_c)0x5;
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x823,(cXyz *)0x0,0,0,d_picture_box::_4527,
                 d_picture_box::_4527,d_picture_box::_4529,d_picture_box::_4529,0);
    }
  }
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd1 = 0;
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0;
  return;
}


/* __thiscall dJle_Pb_c::_close(void) */

void __thiscall dJle_Pb_c::_close(dJle_Pb_c *this)

{
  double dVar1;
  
  *(short *)(this + 0x1360) = *(short *)(this + 0x1360) + -1;
  dVar1 = (double)f_op_msg_mng::fopMsgM_valueIncrease(10,(int)*(short *)(this + 0x1360),0);
  alphaDec(this,(float)dVar1);
  if (*(short *)(this + 0x1360) == 0) {
    changeData(this);
    this[0x136b] = (dJle_Pb_c)0x7;
    d_meter::dMenu_flagSet(0);
  }
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd1 = 0;
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0;
  return;
}


/* __thiscall dJle_Pb_c::_cmove(void) */

void __thiscall dJle_Pb_c::_cmove(dJle_Pb_c *this)

{
  if (this[0x1370] == (dJle_Pb_c)0x0) {
    if (this[0x136d] == (dJle_Pb_c)0x0) {
      moveCamera(this);
    }
    else {
      moveBrowse(this);
    }
  }
  else {
    shutterChange(this);
  }
  return;
}


/* __thiscall dJle_Pb_c::_bmove(void) */

void __thiscall dJle_Pb_c::_bmove(dJle_Pb_c *this)

{
  selectBrowse(this);
  return;
}


/* __thiscall dJle_Pb_c::_gmove(void) */

void __thiscall dJle_Pb_c::_gmove(dJle_Pb_c *this)

{
  getBrowse(this);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall dJle_Pb_c::draw(void) */

void __thiscall dJle_Pb_c::draw(dJle_Pb_c *this)

{
  dJle_Pb_c dVar1;
  J2DOrthoGraph *pJVar2;
  int iVar3;
  int iVar4;
  dJle_Pb_c *pdVar5;
  uint uVar6;
  double local_48;
  double local_40;
  double local_38;
  double local_30;
  double local_28;
  
  if ((this[0x136b] != (dJle_Pb_c)0x6) && (this[0x136b] != (dJle_Pb_c)0x7)) {
    iVar3 = 0;
    iVar4 = 0;
    do {
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar4 + 0x2b0));
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar4 + 0x10));
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x38;
    } while (iVar3 < 0xc);
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x550));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x588));
    iVar3 = 0;
    iVar4 = 0;
    do {
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar4 + 0x5c0));
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar4 + 0x668));
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x38;
    } while (iVar3 < 3);
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x710));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0x748));
    iVar3 = 0;
    iVar4 = 0;
    do {
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + iVar4 + 0x780));
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x38;
    } while (iVar3 < 8);
    iVar3 = 0;
    iVar4 = 0;
    do {
      pdVar5 = this + iVar4;
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(pdVar5 + 0x940));
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(pdVar5 + 0x9e8));
      f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(pdVar5 + 0xa90));
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x38;
    } while (iVar3 < 3);
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0xb38));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0xb70));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0xba8));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0xbe0));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0xc18));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0xc50));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0xc88));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0xcc0));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0xcf8));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0xd30));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0xd68));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0xda0));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0xdd8));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0xe10));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0xe48));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0xf28));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0xef0));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0xeb8));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(this + 0xe80));
    f_op_msg_mng::fopMsgM_setAlpha(this + 0xf60);
    f_op_msg_mng::fopMsgM_setAlpha(this + 0xf68);
    f_op_msg_mng::fopMsgM_setAlpha(this + 0xf70);
    f_op_msg_mng::fopMsgM_setAlpha(this + 0xf78);
  }
  pJVar2 = d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph;
  (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph)->parent).vtbl)->setPort)
            (d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph);
  if (this[0x1370] == (dJle_Pb_c)0x0) {
    J2DScreen::draw(*(J2DScreen **)(this + 8),d_picture_box::_4202,d_picture_box::_4202,
                    &pJVar2->parent);
    shutterLineDraw(this,DAT_803e6a28);
    J2DScreen::draw(*(J2DScreen **)(this + 4),d_picture_box::_4202,d_picture_box::_4202,
                    &pJVar2->parent);
    J2DScreen::draw(*(J2DScreen **)(this + 0xc),d_picture_box::_4202,d_picture_box::_4202,
                    &pJVar2->parent);
    dVar1 = this[0x136b];
    if (dVar1 != (dJle_Pb_c)0x7) {
      if (this[0x136d] == (dJle_Pb_c)0x2) {
        if (((dVar1 == (dJle_Pb_c)0x5) || (dVar1 == (dJle_Pb_c)0x6)) &&
           (*(char *)(*(int *)(this + 0xf80) + 0xc) != '\0')) {
          pictureDraw(this,(uchar)this[0xf65],3);
        }
      }
      else {
        if (this[0x136d] == (dJle_Pb_c)0x1) {
          iVar3 = 0;
          do {
            if (this[iVar3 + 0x1371] != (dJle_Pb_c)0x0) {
              pictureDraw(this,(uchar)this[0xf65],iVar3);
            }
            iVar3 = iVar3 + 1;
          } while (iVar3 < 3);
        }
      }
    }
    (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph)->parent).vtbl)->setPort)();
    uVar6 = 0;
    iVar3 = 0;
    do {
      if (uVar6 == (byte)this[0x1375]) {
        local_48 = (double)CONCAT44(0x43300000,
                                    *(int *)(this + 0x1340) +
                                    (uint)(byte)this[0x136f] *
                                    (*(int *)(this + 0x1344) - *(int *)(this + 0x1340)) ^ 0x80000000
                                   );
        local_40 = (double)CONCAT44(0x43300000,*(uint *)(this + 0x1348) ^ 0x80000000);
        local_38 = (double)CONCAT44(0x43300000,(int)DAT_803e6bb4 ^ 0x80000000U);
        local_30 = (double)CONCAT44(0x43300000,(int)DAT_803e6bb4 ^ 0x80000000U);
        fopMsgM_msgDataProc_c::selectArrow
                  ((fopMsgM_msgDataProc_c *)(this + 0xfbc),*(J2DPicture **)(this + 0xf8c),
                   (float)(local_48 - d_picture_box::_4296),(float)(local_40 - d_picture_box::_4296)
                   ,(float)(local_38 - d_picture_box::_4296),
                   (float)(local_30 - d_picture_box::_4296));
      }
      else {
        dVar1 = this[uVar6 + 0x123d];
        if (((dVar1 != (dJle_Pb_c)0xff) && (dVar1 != (dJle_Pb_c)0x14)) && (dVar1 != (dJle_Pb_c)0x15)
           ) {
          pdVar5 = this + iVar3;
          iVar4 = *(int *)(this + 0xf60);
          local_30 = (double)CONCAT44(0x43300000,*(uint *)(pdVar5 + 0x1124) ^ 0x80000000);
          local_48 = (double)CONCAT44(0x43300000,
                                      (int)(*(float *)(iVar4 + 0xe4) * d_picture_box::_4203) *
                                      ((2 - *(short *)(this + 0x1364)) +
                                      *(int *)(pdVar5 + 0x1160) * 2) ^ 0x80000000);
          f_op_msg_mng::fopMsgM_outFontDraw
                    (*(undefined4 *)(this + 0xf84),*(undefined4 *)(this + 0xf88),
                     (int)((float)(local_30 - d_picture_box::_4296) + *(float *)(iVar4 + 0xc)),
                     (int)((float)(local_48 - d_picture_box::_4296) + *(float *)(iVar4 + 0x10)),
                     *(undefined4 *)(pdVar5 + 0x119c),this + 0x1366,*(undefined *)(iVar4 + 0xac));
        }
      }
      uVar6 = uVar6 + 1;
      iVar3 = iVar3 + 4;
    } while ((int)uVar6 < 0xf);
  }
  else {
    J2DScreen::draw(*(J2DScreen **)(this + 4),d_picture_box::_4202,d_picture_box::_4202,
                    &pJVar2->parent);
    J2DScreen::draw(*(J2DScreen **)(this + 0xc),d_picture_box::_4202,d_picture_box::_4202,
                    &pJVar2->parent);
    dVar1 = this[0x136b];
    if (dVar1 != (dJle_Pb_c)0x7) {
      if (this[0x136d] == (dJle_Pb_c)0x2) {
        if (((dVar1 == (dJle_Pb_c)0x5) || (dVar1 == (dJle_Pb_c)0x6)) &&
           (*(char *)(*(int *)(this + 0xf80) + 0xc) != '\0')) {
          pictureDraw(this,(uchar)this[0xf65],3);
        }
      }
      else {
        if (this[0x136d] == (dJle_Pb_c)0x1) {
          iVar3 = 0;
          do {
            if (this[iVar3 + 0x1371] != (dJle_Pb_c)0x0) {
              pictureDraw(this,(uchar)this[0xf65],iVar3);
            }
            iVar3 = iVar3 + 1;
          } while (iVar3 < 3);
        }
      }
    }
    pJVar2 = d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph;
    (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph)->parent).vtbl)->setPort)
              (d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph);
    uVar6 = 0;
    iVar3 = 0;
    do {
      if (uVar6 == (byte)this[0x1375]) {
        local_28 = (double)CONCAT44(0x43300000,
                                    *(int *)(this + 0x1340) +
                                    (uint)(byte)this[0x136f] *
                                    (*(int *)(this + 0x1344) - *(int *)(this + 0x1340)) ^ 0x80000000
                                   );
        local_30 = (double)CONCAT44(0x43300000,*(uint *)(this + 0x1348) ^ 0x80000000);
        local_38 = (double)CONCAT44(0x43300000,(int)DAT_803e6bb4 ^ 0x80000000U);
        local_40 = (double)CONCAT44(0x43300000,(int)DAT_803e6bb4 ^ 0x80000000U);
        fopMsgM_msgDataProc_c::selectArrow
                  ((fopMsgM_msgDataProc_c *)(this + 0xfbc),*(J2DPicture **)(this + 0xf8c),
                   (float)(local_28 - d_picture_box::_4296),(float)(local_30 - d_picture_box::_4296)
                   ,(float)(local_38 - d_picture_box::_4296),
                   (float)(local_40 - d_picture_box::_4296));
      }
      else {
        dVar1 = this[uVar6 + 0x123d];
        if (((dVar1 != (dJle_Pb_c)0xff) && (dVar1 != (dJle_Pb_c)0x14)) && (dVar1 != (dJle_Pb_c)0x15)
           ) {
          pdVar5 = this + iVar3;
          iVar4 = *(int *)(this + 0xf60);
          local_28 = (double)CONCAT44(0x43300000,*(uint *)(pdVar5 + 0x1124) ^ 0x80000000);
          local_40 = (double)CONCAT44(0x43300000,
                                      (int)(*(float *)(iVar4 + 0xe4) * d_picture_box::_4203) *
                                      ((2 - *(short *)(this + 0x1364)) +
                                      *(int *)(pdVar5 + 0x1160) * 2) ^ 0x80000000);
          f_op_msg_mng::fopMsgM_outFontDraw
                    (*(undefined4 *)(this + 0xf84),*(undefined4 *)(this + 0xf88),
                     (int)((float)(local_28 - d_picture_box::_4296) + *(float *)(iVar4 + 0xc)),
                     (int)((float)(local_40 - d_picture_box::_4296) + *(float *)(iVar4 + 0x10)),
                     *(undefined4 *)(pdVar5 + 0x119c),this + 0x1366,*(undefined *)(iVar4 + 0xac));
        }
      }
      uVar6 = uVar6 + 1;
      iVar3 = iVar3 + 4;
    } while ((int)uVar6 < 0xf);
    J2DScreen::draw(*(J2DScreen **)(this + 8),d_picture_box::_4202,d_picture_box::_4202,
                    &pJVar2->parent);
    shutterLineDraw(this,DAT_803e6a28);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dJle_Pb_c::_delete(JKRExpHeap *) */

void __thiscall dJle_Pb_c::_delete(dJle_Pb_c *this,JKRExpHeap *param_1)

{
  short sVar2;
  int *piVar1;
  int iVar3;
  int iVar4;
  
  if (*(void **)(this + 4000) != (void *)0x0) {
    JKRFileLoader::removeResource(*(void **)(this + 4000),(JKRFileLoader *)0x0);
  }
  sVar2 = m_Do_graphic::mDoGph_getCaptureStep();
  if (sVar2 != 0) {
    m_Do_graphic::mDoGph_CaptureCansel();
  }
  m_Do_ext::mDoExt_removeMesgFont();
  m_Do_ext::mDoExt_removeRubyFont();
  iVar3 = 0;
  iVar4 = 0;
  do {
    JKRHeap::free(&param_1->parent,*(void **)(this + iVar4 + 0x1350));
    iVar3 = iVar3 + 1;
    iVar4 = iVar4 + 4;
  } while (iVar3 < 4);
  iVar3 = *(int *)(this + 0xf80);
  if ((iVar3 != 0) && (iVar3 != 0)) {
    (**(code **)(*(int *)(iVar3 + 0x10) + 8))(iVar3,1);
  }
  piVar1 = *(int **)(this + 4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,1);
  }
  piVar1 = *(int **)(this + 0xc);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,1);
  }
  JKernel::operator_delete(*(JKRHeap **)(this + 0xf98));
  piVar1 = *(int **)(this + 0xf84);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,1);
  }
  piVar1 = *(int **)(this + 0xf88);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,1);
  }
  piVar1 = *(int **)(this + 0xf8c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,1);
  }
  return;
}


namespace d_picture_box {

/* __stdcall dPb_Draw(sub_pb_class *) */

undefined4 dPb_Draw(int param_1)

{
  dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                    *(dDlst_base_c **)(param_1 + 0x100));
  return 1;
}


/* __stdcall dPb_Execute(sub_pb_class *) */

undefined4 dPb_Execute(int param_1)

{
  dJle_Pb_c dVar1;
  undefined4 uVar2;
  dJle_Pb_c *this;
  
  uVar2 = m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0xfc));
  this = *(dJle_Pb_c **)(param_1 + 0x100);
  dVar1 = this[0x136b];
  if (dVar1 == (dJle_Pb_c)0x0) {
    ::dJle_Pb_c::_copen(this);
  }
  else {
    if (dVar1 == (dJle_Pb_c)0x2) {
      ::dJle_Pb_c::_bopen(this);
    }
    else {
      if (dVar1 == (dJle_Pb_c)0x4) {
        ::dJle_Pb_c::_gopen(this);
      }
      else {
        if (dVar1 == (dJle_Pb_c)0x1) {
          ::dJle_Pb_c::_cmove(this);
          d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].field_0x8 =
               d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo[0].field_0x8 | 2;
        }
        else {
          if (dVar1 == (dJle_Pb_c)0x3) {
            ::dJle_Pb_c::_bmove(this);
          }
          else {
            if (dVar1 == (dJle_Pb_c)0x5) {
              ::dJle_Pb_c::_gmove(this);
            }
            else {
              if (dVar1 == (dJle_Pb_c)0x6) {
                ::dJle_Pb_c::_close(this);
                if (*(char *)(*(int *)(param_1 + 0x100) + 0x136b) == '\a') {
                  *(undefined2 *)(param_1 + 0xf8) = 0x12;
                }
              }
              else {
                if ((dVar1 == (dJle_Pb_c)0x7) && (*(short *)(param_1 + 0xf8) == 0x13)) {
                  f_op_msg_mng::fopMsgM_Delete(param_1);
                }
              }
            }
          }
        }
      }
    }
  }
  m_Do_ext::mDoExt_setCurrentHeap(uVar2);
  return 1;
}


/* __stdcall dPb_IsDelete(sub_pb_class *) */

undefined4 dPb_IsDelete(void)

{
  return 1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall dPb_Delete(sub_pb_class *) */

undefined4 dPb_Delete(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0xfc));
  ::dJle_Pb_c::_delete(*(dJle_Pb_c **)(param_1 + 0x100),*(JKRExpHeap **)(param_1 + 0xfc));
  piVar2 = *(int **)(param_1 + 0x100);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2,1);
  }
  iVar3 = 0;
  iVar4 = 0;
  do {
    JKRHeap::free(*(JKRHeap **)(param_1 + 0xfc),*(void **)(param_1 + iVar4 + 0x104));
    iVar3 = iVar3 + 1;
    iVar4 = iVar4 + 4;
  } while (iVar3 < 4);
  (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpMsgArchive)->parent).parent.vtbl)->
            removeResourceAll)();
  (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCamResArchive)->parent).parent.vtbl)->
            removeResourceAll)();
  JKRHeap::freeAll(*(JKRHeap **)(param_1 + 0xfc));
  m_Do_ext::mDoExt_setCurrentHeap(uVar1);
  d_com_inf_game::g_dComIfG_gameInfo.mbCamOverrideFarPlane = 0;
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5bcd = 0;
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd0 = 0;
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd1 = 0;
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0;
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 = 0;
  return 1;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __stdcall dPb_Create(msg_class *) */

undefined4 dPb_Create(int param_1)

{
  undefined4 uVar1;
  ulong uVar2;
  undefined **ppuVar3;
  void *pvVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 == 0) ||
     (d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 == 6)) {
    if (3 < d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._2_1_) {
      d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._2_1_ = 0;
    }
    *(JKRExpHeap **)(param_1 + 0xfc) = d_com_inf_game::g_dComIfG_gameInfo.field_0x5c1c;
    d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 = 6;
    if (*(int *)(param_1 + 0xfc) == 0) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"d_picture_box.cpp",0xaec,"i_Pb->heap != 0");
      m_Do_printf::OSPanic("d_picture_box.cpp",0xaec,&DAT_8036270a);
    }
    uVar1 = m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0xfc));
    ppuVar3 = (undefined **)JKernel::operator_new(0x1378);
    if (ppuVar3 != (undefined **)0x0) {
      *ppuVar3 = (undefined *)&dDlst_base_c::__vt;
      *ppuVar3 = &::dJle_Pb_c::__vt;
      fopMsgM_msgDataProc_c::fopMsgM_msgDataProc_c((fopMsgM_msgDataProc_c *)(ppuVar3 + 0x3ef));
      ppuVar3[0x497] = (undefined *)0xffffffff;
      ppuVar3[0x498] = (undefined *)0xffffffff;
      ppuVar3[0x499] = (undefined *)0xffffffff;
      ppuVar3[0x49a] = (undefined *)0xffffffff;
    }
    *(undefined ***)(param_1 + 0x100) = ppuVar3;
    iVar5 = 0;
    iVar7 = 0;
    do {
      pvVar4 = JKRHeap::alloc(*(JKRHeap **)(param_1 + 0xfc),0x2000,0x20);
      iVar6 = iVar7 + 0x104;
      *(void **)(param_1 + iVar6) = pvVar4;
      if (*(int *)(param_1 + iVar6) == 0) {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar2,"d_picture_box.cpp",0xaf5,"i_Pb->buffer[i] != 0");
        m_Do_printf::OSPanic("d_picture_box.cpp",0xaf5,&DAT_8036270a);
      }
      *(undefined4 *)(*(int *)(param_1 + 0x100) + iVar7 + 0x126c) = *(undefined4 *)(param_1 + iVar6)
      ;
      iVar5 = iVar5 + 1;
      iVar7 = iVar7 + 4;
    } while (iVar5 < 4);
    iVar5 = 0;
    iVar7 = 0;
    do {
      pvVar4 = JKRHeap::alloc(*(JKRHeap **)(param_1 + 0xfc),1000,4);
      *(void **)(*(int *)(param_1 + 0x100) + iVar7 + 0x1350) = pvVar4;
      if (pvVar4 == (void *)0x0) {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar2,"d_picture_box.cpp",0xafc,"buffer != 0");
        m_Do_printf::OSPanic("d_picture_box.cpp",0xafc,&DAT_8036270a);
      }
      iVar5 = iVar5 + 1;
      iVar7 = iVar7 + 4;
    } while (iVar5 < 4);
    ::dJle_Pb_c::_create(*(dJle_Pb_c **)(param_1 + 0x100),*(JKRExpHeap **)(param_1 + 0xfc));
    m_Do_ext::mDoExt_setCurrentHeap(uVar1);
    d_com_inf_game::g_dComIfG_gameInfo.mbCamOverrideFarPlane = 0;
    if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._2_1_ < 3) {
      d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0x20;
    }
    else {
      d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd2 = 0;
    }
    if (d_com_inf_game::g_dComIfG_gameInfo.field_0x5bfe == 2) {
      d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd1 = 7;
      d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd0 = 0x3e;
    }
    else {
      if (d_com_inf_game::g_dComIfG_gameInfo.field_0x5bfe == 3) {
        d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd1 = 0x3e;
        d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd0 = 0x3e;
      }
      else {
        d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd1 = 7;
        d_com_inf_game::g_dComIfG_gameInfo.field_0x5bd0 = 0x22;
      }
    }
    uVar1 = 4;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

}

/* __thiscall dJle_Pb_c::~dJle_Pb_c(void) */

void __thiscall dJle_Pb_c::_dJle_Pb_c(dJle_Pb_c *this)

{
  short in_r4;
  
  if (this != (dJle_Pb_c *)0x0) {
    *(undefined1 **)this = &__vt;
    fopMsgM_msgDataProc_c::_fopMsgM_msgDataProc_c((fopMsgM_msgDataProc_c *)(this + 0xfbc));
    if (this != (dJle_Pb_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}

