#include <m_Do_controller_pad.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JUtility/JUTGamePad.h>
#include <SComponent/c_lib.h>
#include <m_Do_controller_pad.h>
#include <m_Do_gba_com.h>
#include <JKernel/JKRHeap.h>
#include <pad/Pad.h>
#include <m_Do_Reset.h>
#include <JUtility/JUTGba.h>


namespace m_Do_controller_pad {
struct JUTGamePad * g_mDoCPd_gamePad[4];
struct interface_of_controller_pad g_mDoCPd_cpadInfo[4];

/* __stdcall mDoCPd_Convert(interface_of_controller_pad *,
                            JUTGamePad *) */

undefined4 mDoCPd_Convert(interface_of_controller_pad *pDst,JUTGamePad *pJUT)

{
  pDst->mButton0 = (byte)(((pJUT->mButton).mButtonDown >> 3 & 1) << 4) | pDst->mButton0 & 0xef;
  pDst->mButton0 = (byte)(((pJUT->mButton).mButtonDown >> 2 & 1) << 5) | pDst->mButton0 & 0xdf;
  pDst->mButton0 = (byte)(((pJUT->mButton).mButtonDown & 1) << 7) | pDst->mButton0 & 0x7f;
  pDst->mButton0 = (byte)(((pJUT->mButton).mButtonDown >> 1 & 1) << 6) | pDst->mButton0 & 0xbf;
  pDst->mButton0 = (byte)(((pJUT->mButton).mButtonDown >> 4 & 1) << 3) | pDst->mButton0 & 0xf7;
  pDst->mButton0 = (byte)(((pJUT->mButton).mButtonDown >> 5 & 1) << 2) | pDst->mButton0 & 0xfb;
  pDst->mButton0 = (byte)(((pJUT->mButton).mButtonDown >> 6 & 1) << 1) | pDst->mButton0 & 0xfd;
  pDst->mButton0 = (byte)((pJUT->mButton).mButtonDown >> 8) & 1 | pDst->mButton0 & 0xfe;
  pDst->mButton1 = (byte)(((pJUT->mButton).mButtonDown >> 9 & 1) << 7) | pDst->mButton1 & 0x7f;
  pDst->mButton1 = (byte)(((pJUT->mButton).mButtonDown >> 10 & 1) << 6) | pDst->mButton1 & 0xbf;
  pDst->mButton1 = (byte)(((pJUT->mButton).mButtonDown >> 0xb & 1) << 5) | pDst->mButton1 & 0xdf;
  pDst->mButton1 = (byte)(((pJUT->mButton).mButtonDown >> 0xc & 1) << 4) | pDst->mButton1 & 0xef;
  pDst->mButton2 = (byte)(((pJUT->mButton).mButtonReleased >> 3 & 1) << 4) | pDst->mButton2 & 0xef;
  pDst->mButton2 = (byte)(((pJUT->mButton).mButtonReleased >> 2 & 1) << 5) | pDst->mButton2 & 0xdf;
  pDst->mButton2 = (byte)(((pJUT->mButton).mButtonReleased & 1) << 7) | pDst->mButton2 & 0x7f;
  pDst->mButton2 = (byte)(((pJUT->mButton).mButtonReleased >> 1 & 1) << 6) | pDst->mButton2 & 0xbf;
  pDst->mButton2 = (byte)(((pJUT->mButton).mButtonReleased >> 4 & 1) << 3) | pDst->mButton2 & 0xf7;
  pDst->mButton2 = (byte)(((pJUT->mButton).mButtonReleased >> 5 & 1) << 2) | pDst->mButton2 & 0xfb;
  pDst->mButton2 = (byte)(((pJUT->mButton).mButtonReleased >> 6 & 1) << 1) | pDst->mButton2 & 0xfd;
  pDst->mButton2 = (byte)((pJUT->mButton).mButtonReleased >> 8) & 1 | pDst->mButton2 & 0xfe;
  pDst->mButton3 = (byte)(((pJUT->mButton).mButtonReleased >> 9 & 1) << 7) | pDst->mButton3 & 0x7f;
  pDst->mButton3 = (byte)(((pJUT->mButton).mButtonReleased >> 10 & 1) << 6) | pDst->mButton3 & 0xbf;
  pDst->mButton3 = (byte)(((pJUT->mButton).mButtonReleased >> 0xb & 1) << 5) | pDst->mButton3 & 0xdf
  ;
  pDst->mButton3 = (byte)(((pJUT->mButton).mButtonReleased >> 0xc & 1) << 4) | pDst->mButton3 & 0xef
  ;
  pDst->mStickMainPosX = (pJUT->mStickMain).mPosX;
  pDst->mStickMainPosY = (pJUT->mStickMain).mPosY;
  pDst->mStickMainValue = (pJUT->mStickMain).mValue;
  pDst->mStickMainAngle = (pJUT->mStickMain).mAngle;
  pDst->mStickCPosX = (pJUT->mStickC).mPosX;
  pDst->mStickCPosY = (pJUT->mStickC).mPosY;
  pDst->mStickCValue = (pJUT->mStickC).mValue;
  pDst->mStickCAngle = (pJUT->mStickC).mAngle;
  pDst->mAnalogA =
       1_15_0 * (float)((double)CONCAT44(0x43300000,(uint)(pJUT->mButton).mAnalogARaw) - _4042);
  if (1_0 < pDst->mAnalogA) {
    pDst->mAnalogA = 1_0;
  }
  pDst->mAnalogB =
       1_15_0 * (float)((double)CONCAT44(0x43300000,(uint)(pJUT->mButton).mAnalogBRaw) - _4042);
  if (1_0 < pDst->mAnalogB) {
    pDst->mAnalogB = 1_0;
  }
  pDst->mTriggerLeft =
       1_140_0 * (float)((double)CONCAT44(0x43300000,(uint)(pJUT->mButton).mTriggerLeftRaw) - _4042)
  ;
  if (1_0 < pDst->mTriggerLeft) {
    pDst->mTriggerLeft = 1_0;
  }
  pDst->mTriggerRight =
       1_140_0 * (float)((double)CONCAT44(0x43300000,(uint)(pJUT->mButton).mTriggerRightRaw) - _4042
                        );
  if (1_0 < pDst->mTriggerRight) {
    pDst->mTriggerRight = 1_0;
  }
  pDst->field_0x34 = pJUT->field_0x7a;
  return 1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall mDoCPd_Read(void) */

undefined4 mDoCPd_Read(JUTGamePad *param_1)

{
  bool bVar1;
  float fVar2;
  float fVar3;
  JUTGamePad **ppJVar4;
  interface_of_controller_pad *pDst;
  int iVar5;
  int iVar6;
  float trig;
  
  JUTGamePad::read(param_1);
  if ((*mDoRst::mResetData == 0) && (mDoRst::mResetData[2] != 0)) {
    iVar5 = JUTGamePad::getGamePad(mDoRst::mResetData[3]);
    bVar1 = false;
    if ((*(short *)(iVar5 + 0x78) != -1) && (*(char *)(iVar5 + 0x98) != '\0')) {
      bVar1 = true;
    }
    if (!bVar1) {
      mDoRst::mResetData[2] = 0;
    }
  }
  ppJVar4 = g_mDoCPd_gamePad;
  pDst = g_mDoCPd_cpadInfo;
  iVar5 = 0;
  do {
    if (*ppJVar4 == (JUTGamePad *)0x0) {
      SComponent::cLib_memSet(pDst,0,0x3c);
    }
    else {
      mDoCPd_Convert(pDst,*ppJVar4);
    }
    fVar3 = f_ap_game::g_HIO.mTriggerThreshHi;
    fVar2 = f_ap_game::g_HIO.mTriggerThreshLo;
    pDst = pDst + 1;
    iVar5 = iVar5 + 1;
    ppJVar4 = ppJVar4 + 1;
  } while (iVar5 < 4);
  iVar5 = 0;
  iVar6 = 4;
  do {
    trig = *(float *)((int)&g_mDoCPd_cpadInfo[0].mTriggerLeft + iVar5);
    (&g_mDoCPd_cpadInfo[0].mTriggerLeftEdge)[iVar5] = 0;
    (&g_mDoCPd_cpadInfo[0].mTriggerRightEdge)[iVar5] = 0;
    if (trig <= fVar2) {
      if (trig < fVar3) {
        (&g_mDoCPd_cpadInfo[0].mTriggerLeftLevel)[iVar5] = 0;
      }
    }
    else {
      if ((&g_mDoCPd_cpadInfo[0].mTriggerLeftLevel)[iVar5] != 1) {
        (&g_mDoCPd_cpadInfo[0].mTriggerLeftEdge)[iVar5] = 1;
      }
      (&g_mDoCPd_cpadInfo[0].mTriggerLeftLevel)[iVar5] = 1;
    }
    trig = *(float *)((int)&g_mDoCPd_cpadInfo[0].mTriggerRight + iVar5);
    if (trig <= fVar2) {
      if (trig < fVar3) {
        (&g_mDoCPd_cpadInfo[0].mTriggerRightLevel)[iVar5] = 0;
      }
    }
    else {
      if ((&g_mDoCPd_cpadInfo[0].mTriggerRightLevel)[iVar5] != 1) {
        (&g_mDoCPd_cpadInfo[0].mTriggerRightEdge)[iVar5] = 1;
      }
      (&g_mDoCPd_cpadInfo[0].mTriggerRightLevel)[iVar5] = 1;
    }
    iVar5 = iVar5 + 0x3c;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  mDoGaC_agbCom_c::mDoGaC_Connect((mDoGaC_agbCom_c *)&m_Do_ext::m_Do_gba_com::g_mDoGaC_gbaCom);
  return 1;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __stdcall mDoCPd_Create(void) */

undefined4 mDoCPd_Create(void)

{
  JUTGamePad *pJVar1;
  int *this;
  int iVar2;
  int iVar3;
  
  _mSuppressPadReset = 1;
  pJVar1 = (JUTGamePad *)JKernel::operator_new(0xa8);
  if (pJVar1 != (JUTGamePad *)0x0) {
    JUTGamePad::JUTGamePad(pJVar1,0);
  }
  g_mDoCPd_gamePad[1] = (JUTGamePad *)0x0;
  g_mDoCPd_gamePad[0] = pJVar1;
  if (mDoMain::developmentMode == '\0') {
    g_mDoCPd_gamePad[2] = (JUTGamePad *)0x0;
    g_mDoCPd_gamePad[3] = (JUTGamePad *)0x0;
    pJVar1 = g_mDoCPd_gamePad[3];
  }
  else {
    pJVar1 = (JUTGamePad *)JKernel::operator_new(0xa8);
    if (pJVar1 != (JUTGamePad *)0x0) {
      JUTGamePad::JUTGamePad(pJVar1,2);
    }
    g_mDoCPd_gamePad[2] = pJVar1;
    pJVar1 = (JUTGamePad *)JKernel::operator_new(0xa8);
    if (pJVar1 != (JUTGamePad *)0x0) {
      JUTGamePad::JUTGamePad(pJVar1,3);
    }
  }
  g_mDoCPd_gamePad[3] = pJVar1;
  JUTGamePad::sAnalogMode = 3;
  pad::PADSetAnalogMode(3);
  this = mDoRst::mResetData;
  if (*mDoRst::mResetData == 0) {
    JUTGamePad::C3ButtonReset::sResetOccurred = 0;
    this = (int *)0x80010000;
    _sCallback = m_Do_Reset::mDoRst_resetCallBack;
    _sCallbackArg = 0;
  }
  JUTGba::create((JUTGba *)this);
  mDoGaC_agbCom_c::mDoGaC_Initial
            ((mDoGaC_agbCom_c *)&m_Do_ext::m_Do_gba_com::g_mDoGaC_gbaCom,
             (mDoGaC_DataManag_c *)&m_Do_ext::m_Do_gba_com::TestDataManager,'\x10');
  iVar2 = 0;
  iVar3 = 4;
  do {
    (&g_mDoCPd_cpadInfo[0].mTriggerLeftEdge)[iVar2] = 0;
    (&g_mDoCPd_cpadInfo[0].mTriggerLeftLevel)[iVar2] = 0;
    (&g_mDoCPd_cpadInfo[0].mTriggerRightEdge)[iVar2] = 0;
    (&g_mDoCPd_cpadInfo[0].mTriggerRightLevel)[iVar2] = 0;
    iVar2 = iVar2 + 0x3c;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return 1;
}

