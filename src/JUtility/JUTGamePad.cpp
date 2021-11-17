#include <JUtility/JUTGamePad.h>
#include <JKernel/JKRDisposer.h>
#include <JUtility/JUTGamePad.h>
#include <JSupport/JSUList.h>
#include <JKernel/JKRHeap.h>
#include <pad/Pad.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <pad/Padclamp.h>
#include <m_Do_printf.h>
#include <os/OSTime.h>
#include <os/OSResetSW.h>
#include <MSL_C.PPCEABI.bare.H/w_atan2.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <JUTGamePad.h>
#include <JUTGamePad/CRumble.h>
#include <JUTGamePad/CButton.h>
#include <JSUList<JUTGamePad>.h>
#include <JUTGamePad/CStick.h>

struct JSUPtrList JUTGamePad;
struct PADStatus JUTGamePad[4];
struct CButton JUTGamePad[4];
struct CStick JUTGamePad[4];
struct CStick JUTGamePad[4];
undefined1 JUTGamePad;
byte JUTGamePad[4];
undefined1 JUTGamePad;
int JUTGamePad;
undefined1 JUTGamePad;

namespace JUTGamePad {
byte CRumble[4];
int CRumble;

namespace C3ButtonReset {
undefined1 sCallback;
undefined1 sCallbackArg;
undefined1 sThreshold;
undefined1 sResetSwitchPushing;
undefined1 sResetOccurred;
undefined1 sResetOccurredPort;
}
}

/* __thiscall JUTGamePad::JUTGamePad(JUTGamePad::EPadPort) */

void __thiscall JUTGamePad::JUTGamePad(JUTGamePad *this,EPadPort param_1)

{
  JKRDisposer::JKRDisposer(&this->parent);
  (this->parent).vtbl = (JKRArchive__vtbl *)&__vt;
  CButton::clear(&this->mButton);
  CStick::clear(&this->mStickMain);
  CStick::clear(&this->mStickC);
  CRumble::clear(&this->mRumble,this);
  JSUPtrLink::JSUPtrLink(&this->mLink,this);
  *(undefined *)&this->field_0x98 = 0;
  this->mPortIdx = (short)param_1;
  mPadAssign[param_1] = mPadAssign[param_1] + 1;
  initList(this);
  JSUPtrList::append(&mPadList,&this->mLink);
  update(this);
  *(undefined4 *)&this->field_0x8c = 0;
  *(undefined4 *)&this->field_0x90 = 0;
  return;
}


/* __thiscall JUTGamePad::~JUTGamePad(void) */

void __thiscall JUTGamePad::_JUTGamePad(JUTGamePad *this)

{
  short in_r4;
  int iVar1;
  
  if (this != (JUTGamePad *)0x0) {
    (this->parent).vtbl = (JKRArchive__vtbl *)&__vt;
    iVar1 = (int)this->mPortIdx;
    if (iVar1 != -1) {
      mPadAssign[iVar1] = mPadAssign[iVar1] - 1;
      this->mPortIdx = -1;
    }
    JSUPtrList::remove(&mPadList,&this->mLink);
    if (this != (JUTGamePad *)0xffffff84) {
      JSUPtrLink::_JSUPtrLink(&this->mLink);
    }
    JKRDisposer::_JKRDisposer(&this->parent);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JUTGamePad::initList(void) */

JUTGamePad * __thiscall JUTGamePad::initList(JUTGamePad *this)

{
  if (mListInitialized == '\0') {
    this = (JUTGamePad *)JSUPtrList::initiate(&mPadList);
    mListInitialized = '\x01';
  }
  return this;
}


namespace JUTGamePad {

/* __thiscall init(void) */

void init(void)

{
  pad::PADSetSpec(5);
  sAnalogMode = 3;
  pad::PADSetAnalogMode(3);
  pad::PADInit();
  return;
}

}

/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JUTGamePad::read(void) */

void __thiscall JUTGamePad::read(JUTGamePad *this)

{
  sbyte sVar1;
  int iVar2;
  int iVar3;
  JUTGamePad *pJVar4;
  int *piVar5;
  JSUPtrLink *pJVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  PADStatus PStack56;
  
  _sRumbleSupported = pad::PADRead(mPadStatus);
  pad::PADClamp(mPadStatus);
  uVar11 = 0;
  iVar10 = 0;
  iVar9 = 0;
  iVar8 = 0;
  iVar7 = 0;
  do {
    sVar1 = (&mPadStatus[0].err)[iVar7];
    if (sVar1 == 0) {
      iVar2 = CStick::update((CStick *)((int)&mPadMStick[0].mPosX + iVar8),
                             (&mPadStatus[0].stickX)[iVar7],(&mPadStatus[0].stickY)[iVar7],
                             mStickMode,0);
      iVar3 = CStick::update((CStick *)((int)&mPadSStick[0].mPosX + iVar8),
                             (&mPadStatus[0].substickX)[iVar7],(&mPadStatus[0].substickY)[iVar7],
                             mStickMode,1);
      pJVar4 = (JUTGamePad *)
               CButton::update((CButton *)((int)&mPadButton[0].mButtonDown + iVar9),
                               (PADStatus *)((int)&mPadStatus[0].button + iVar7),
                               iVar2 << 0x18 | iVar3 << 0x10);
    }
    else {
      if (sVar1 == -1) {
        CStick::update((CStick *)((int)&mPadMStick[0].mPosX + iVar8),'\0','\0',mStickMode,0);
        CStick::update((CStick *)((int)&mPadSStick[0].mPosX + iVar8),'\0','\0',mStickMode,1);
        pJVar4 = (JUTGamePad *)
                 CButton::update((CButton *)((int)&mPadButton[0].mButtonDown + iVar9),
                                 (PADStatus *)0x0,0);
        if ((_mSuppressPadReset & 0x80000000U >> iVar10) == 0) {
          uVar11 = uVar11 | 0x80000000U >> iVar10;
        }
      }
      else {
        if (sVar1 != -3) {
          m_Do_printf::OSReport("game pad read error (%d)\n");
        }
        pJVar4 = (JUTGamePad *)((int)&mPadButton[0].mButtonDown + iVar9);
        *(undefined4 *)((int)&mPadButton[0].mButtonReleased + iVar9) = 0;
        *(undefined4 *)((int)&mPadButton[0].mButtonPressed + iVar9) = 0;
        *(undefined4 *)((int)&mPadButton[0].field_0x18 + iVar9) = 0;
      }
    }
    iVar10 = iVar10 + 1;
    iVar9 = iVar9 + 0x30;
    iVar8 = iVar8 + 0x10;
    iVar7 = iVar7 + 0xc;
    pJVar6 = mPadList.mpHead;
  } while (iVar10 < 4);
  for (; pJVar6 != (JSUPtrLink *)0x0; pJVar6 = pJVar6->mpNext) {
    pJVar4 = (JUTGamePad *)pJVar6->mpData;
    piVar5 = *(int **)&pJVar4->field_0x90;
    if (piVar5 == (int *)0x0) {
      if (pJVar4->mPortIdx == -1) {
        assign(pJVar4);
      }
      update((JUTGamePad *)pJVar6->mpData);
    }
    else {
      (**(code **)(*piVar5 + 0xc))(piVar5,&PStack56);
      iVar7 = CStick::update((CStick *)(pJVar6->mpData + 0x48),PStack56.stickX,PStack56.stickY,
                             mStickMode,0);
      iVar8 = CStick::update((CStick *)(pJVar6->mpData + 0x58),PStack56.substickX,PStack56.substickY
                             ,mStickMode,1);
      CButton::update((CButton *)(pJVar6->mpData + 0x18),&PStack56,iVar7 << 0x18 | iVar8 << 0x10);
    }
    pJVar4 = *(JUTGamePad **)(pJVar6->mpData + 0x8c);
    if (((pJVar4 != (JUTGamePad *)0x0) &&
        (iVar7 = (int)*(short *)(pJVar6->mpData + 0x78), iVar7 != -1)) &&
       (*(char *)((int)mPadStatus + iVar7 * 0xc + 10) == '\0')) {
      pJVar4 = (JUTGamePad *)(*(code *)((pJVar4->parent).vtbl)->becomeCurrent)();
    }
  }
  if (uVar11 != 0) {
    pJVar4 = (JUTGamePad *)pad::PADReset(uVar11);
  }
  checkResetSwitch(pJVar4);
  return;
}


/* __thiscall JUTGamePad::assign(void) */

void __thiscall JUTGamePad::assign(JUTGamePad *this)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  iVar1 = 0;
  pbVar2 = mPadAssign;
  iVar4 = 4;
  while (((&mPadStatus[0].err)[iVar1] != 0 || (*pbVar2 != 0))) {
    iVar3 = iVar3 + 1;
    pbVar2 = pbVar2 + 1;
    iVar1 = iVar1 + 0xc;
    iVar4 = iVar4 + -1;
    if (iVar4 == 0) {
      return;
    }
  }
  this->mPortIdx = (short)iVar3;
  mPadAssign[iVar3] = 1;
  CButton::setRepeat(mPadButton + iVar3,(this->mButton).field_0x24,(this->mButton).field_0x28,
                     (this->mButton).field_0x2c);
  CRumble::clear(&this->mRumble,this);
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JUTGamePad::checkResetCallback(long long) */

void __thiscall JUTGamePad::checkResetCallback(JUTGamePad *this,long_long param_1)

{
  uint in_r5;
  uint in_r6;
  
  if (-1 < this->mPortIdx) {
    if ((uint)(in_r6 < DAT_803f7894) + (_sThreshold ^ 0x80000000) <= (in_r5 ^ 0x80000000)) {
      C3ButtonReset::sResetOccurred = 1;
      _sResetOccurredPort = (int)this->mPortIdx;
      if (_sCallback != (code *)0x0) {
        (*_sCallback)((int)this->mPortIdx,_sCallbackArg);
      }
    }
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JUTGamePad::update(void) */

void __thiscall JUTGamePad::update(JUTGamePad *this)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = (int)this->mPortIdx;
  if (iVar1 != -1) {
    (this->mButton).mButtonDown = mPadButton[iVar1].mButtonDown;
    (this->mButton).mButtonReleased = mPadButton[iVar1].mButtonReleased;
    (this->mButton).mButtonPressed = mPadButton[iVar1].mButtonPressed;
    (this->mButton).mAnalogARaw = mPadButton[iVar1].mAnalogARaw;
    (this->mButton).mAnalogBRaw = mPadButton[iVar1].mAnalogBRaw;
    (this->mButton).mTriggerLeftRaw = mPadButton[iVar1].mTriggerLeftRaw;
    (this->mButton).mTriggerRightRaw = mPadButton[iVar1].mTriggerRightRaw;
    (this->mButton).mTriggerLeft = mPadButton[iVar1].mTriggerLeft;
    (this->mButton).mTriggerRight = mPadButton[iVar1].mTriggerRight;
    (this->mButton).field_0x18 = mPadButton[iVar1].field_0x18;
    (this->mButton).field_0x1c = mPadButton[iVar1].field_0x1c;
    (this->mButton).field_0x20 = mPadButton[iVar1].field_0x20;
    (this->mButton).field_0x24 = mPadButton[iVar1].field_0x24;
    (this->mButton).field_0x28 = mPadButton[iVar1].field_0x28;
    (this->mButton).field_0x2c = mPadButton[iVar1].field_0x2c;
    iVar1 = (int)this->mPortIdx;
    (this->mStickMain).mPosX = mPadMStick[iVar1].mPosX;
    (this->mStickMain).mPosY = mPadMStick[iVar1].mPosY;
    (this->mStickMain).mValue = mPadMStick[iVar1].mValue;
    (this->mStickMain).mAngle = mPadMStick[iVar1].mAngle;
    (this->mStickMain).mPosXRaw = mPadMStick[iVar1].mPosXRaw;
    (this->mStickMain).mPosYRaw = mPadMStick[iVar1].mPosYRaw;
    iVar1 = (int)this->mPortIdx;
    (this->mStickC).mPosX = mPadSStick[iVar1].mPosX;
    (this->mStickC).mPosY = mPadSStick[iVar1].mPosY;
    (this->mStickC).mValue = mPadSStick[iVar1].mValue;
    (this->mStickC).mAngle = mPadSStick[iVar1].mAngle;
    (this->mStickC).mPosXRaw = mPadSStick[iVar1].mPosXRaw;
    (this->mStickC).mPosYRaw = mPadSStick[iVar1].mPosYRaw;
    this->field_0x7a = *(byte *)((int)mPadStatus + this->mPortIdx * 0xc + 10);
    uVar2 = _sResetPattern;
    if (_sResetPattern == ((this->mButton).mButtonDown & _sResetMaskPattern)) {
      if (C3ButtonReset::sResetOccurred == '\0') {
        if (*(char *)&this->field_0x98 == '\x01') {
          os::OSGetTime();
          checkResetCallback(this,uVar2);
        }
        else {
          *(undefined *)&this->field_0x98 = 1;
          iVar1 = os::OSGetTime();
          *(uint *)&this->field_0xa4 = uVar2;
          *(int *)&this->field_0xa0 = iVar1;
        }
      }
    }
    else {
      *(undefined *)&this->field_0x98 = 0;
    }
    CRumble::update(&this->mRumble,this->mPortIdx);
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JUTGamePad::checkResetSwitch(void) */

JUTGamePad * __thiscall JUTGamePad::checkResetSwitch(JUTGamePad *this)

{
  if (C3ButtonReset::sResetOccurred == '\0') {
    this = (JUTGamePad *)os::OSGetResetSwitchState();
    if (this == (JUTGamePad *)0x0) {
      if (C3ButtonReset::sResetSwitchPushing == '\x01') {
        C3ButtonReset::sResetOccurred = '\x01';
        _sResetOccurredPort = 0xffffffff;
        if (_sCallback != (code *)0x0) {
          this = (JUTGamePad *)(*_sCallback)(0xffffffff,_sCallbackArg);
        }
      }
      C3ButtonReset::sResetSwitchPushing = '\0';
    }
    else {
      C3ButtonReset::sResetSwitchPushing = '\x01';
    }
  }
  return this;
}


/* __thiscall JUTGamePad::clearForReset(void) */

void __thiscall JUTGamePad::clearForReset(JUTGamePad *this)

{
  ulong in_r4;
  ulong extraout_r4;
  
  CRumble::setEnabled((CRumble *)0x0,in_r4);
  recalibrate((JUTGamePad *)0xf0000000,extraout_r4);
  return;
}


namespace JUTGamePad {

/* __thiscall CButton::clear(void) */

void __thiscall CButton::clear(CButton *this)

{
  this->mButtonDown = 0;
  this->mButtonReleased = 0;
  this->mButtonPressed = 0;
  this->field_0x18 = 0;
  this->mAnalogARaw = 0;
  this->mAnalogBRaw = 0;
  this->mTriggerLeftRaw = 0;
  this->mTriggerRightRaw = 0;
  this->field_0x1c = 0;
  this->field_0x20 = 0;
  this->field_0x24 = 0;
  this->field_0x28 = 0;
  this->field_0x2c = 0;
  return;
}


/* __thiscall CButton::update(PADStatus const *,
                                          unsigned long) */

void __thiscall CButton::update(CButton *this,PADStatus *pPadStatus,ulong param_2)

{
  float fVar1;
  double dVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  if (pPadStatus == (PADStatus *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = (uint)pPadStatus->button;
  }
  uVar3 = param_2 | uVar3;
  this->field_0x18 = 0;
  if (this->field_0x28 != 0) {
    if (this->field_0x24 != 0) {
      uVar6 = uVar3 & this->field_0x24;
      this->field_0x18 = 0;
      if (uVar6 == 0) {
        this->field_0x20 = 0;
        this->field_0x1c = 0;
      }
      else {
        if (this->field_0x20 == uVar6) {
          this->field_0x1c = this->field_0x1c + 1;
          uVar5 = this->field_0x1c;
          uVar4 = this->field_0x28;
          if ((uVar5 == uVar4) ||
             ((uVar4 < uVar5 &&
              (uVar5 - uVar4 == ((uVar5 - uVar4) / this->field_0x2c) * this->field_0x2c)))) {
            this->field_0x18 = uVar6;
          }
        }
        else {
          this->field_0x18 = uVar6 & (this->field_0x20 ^ 0xffffffff);
          this->field_0x20 = uVar6;
          this->field_0x1c = 0;
        }
      }
    }
  }
  this->mButtonReleased = uVar3 & (uVar3 ^ this->mButtonDown);
  this->mButtonPressed = this->mButtonDown & (uVar3 ^ this->mButtonDown);
  this->mButtonDown = uVar3;
  this->field_0x18 = this->field_0x18 | (this->field_0x24 ^ 0xffffffff) & this->mButtonReleased;
  if (pPadStatus == (PADStatus *)0x0) {
    this->mAnalogARaw = 0;
    this->mAnalogBRaw = 0;
    this->mTriggerLeftRaw = 0;
    this->mTriggerRightRaw = 0;
  }
  else {
    this->mAnalogARaw = pPadStatus->analogA;
    this->mAnalogBRaw = pPadStatus->analogB;
    this->mTriggerLeftRaw = pPadStatus->triggerLeft;
    this->mTriggerRightRaw = pPadStatus->triggerRight;
  }
  dVar2 = JUtility::_824;
  fVar1 = JUtility::_821;
  this->mTriggerLeft =
       (float)((double)CONCAT44(0x43300000,this->mTriggerLeftRaw ^ 0x80000000) - JUtility::_824) /
       JUtility::_821;
  this->mTriggerRight =
       (float)((double)CONCAT44(0x43300000,this->mTriggerRightRaw ^ 0x80000000) - dVar2) / fVar1;
  return;
}


/* __thiscall CStick::clear(void) */

void __thiscall CStick::clear(CStick *this)

{
  float fVar1;
  
  fVar1 = JUtility::0_0;
  this->mPosX = JUtility::0_0;
  this->mPosY = fVar1;
  this->mValue = fVar1;
  this->mAngle = 0;
  return;
}


/* __thiscall CStick::update(signed char,
                                         signed char,
                                         EStickMode,
                                         EWhichStick) */

void __thiscall
CStick::update
          (CStick *this,char param_1,char param_2,EStickMode param_3,EWhichStick param_4)

{
  uint uVar1;
  double dVar2;
  double dVar3;
  double local_18;
  
  uVar1 = 0x2a;
  if (param_4 == 0) {
    uVar1 = 0x36;
  }
  this->mPosXRaw = param_1;
  this->mPosYRaw = param_2;
  dVar3 = JUtility::_824;
  this->mPosX = (float)((double)CONCAT44(0x43300000,(int)param_1 ^ 0x80000000) - JUtility::_824) /
                (float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - JUtility::_824);
  local_18 = (double)CONCAT44(0x43300000,uVar1 ^ 0x80000000);
  this->mPosY = (float)((double)CONCAT44(0x43300000,(int)param_2 ^ 0x80000000) - dVar3) /
                (float)(local_18 - dVar3);
  dVar3 = (double)(this->mPosX * this->mPosX + this->mPosY * this->mPosY);
  if ((double)JUtility::0_0 < dVar3) {
    dVar2 = 1.0 / SQRT(dVar3);
    dVar2 = JUtility::_867 * dVar2 * (JUtility::_868 - dVar3 * dVar2 * dVar2);
    dVar2 = JUtility::_867 * dVar2 * (JUtility::_868 - dVar3 * dVar2 * dVar2);
    dVar3 = (double)(float)(dVar3 * JUtility::_867 * dVar2 *
                                    (JUtility::_868 - dVar3 * dVar2 * dVar2));
  }
  this->mValue = (float)dVar3;
  if (JUtility::1_0 < this->mValue) {
    if (param_3 == 1) {
      this->mPosX = this->mPosX / this->mValue;
      this->mPosY = this->mPosY / this->mValue;
    }
    this->mValue = JUtility::1_0;
  }
  dVar3 = (double)JUtility::0_0;
  if (dVar3 < (double)this->mValue) {
    if (dVar3 == (double)this->mPosY) {
      if ((double)this->mPosX <= dVar3) {
        this->mAngle = -0x4000;
      }
      else {
        this->mAngle = 0x4000;
      }
    }
    else {
      dVar3 = MSL_C.PPCEABI.bare.H::atan2((double)this->mPosX,-(double)this->mPosY);
      this->mAngle = (short)(int)(JUtility::10430_379 * (float)dVar3);
    }
  }
  getButton(this);
  return;
}


/* __thiscall CStick::getButton(void) */

uint __thiscall CStick::getButton(CStick *this)

{
  float fVar1;
  uint uVar2;
  
  uVar2 = 0;
  fVar1 = this->mPosX;
  if ((fVar1 <= JUtility::_0_25) || (JUtility::0_25 <= fVar1)) {
    if (JUtility::_0_5 < fVar1) {
      if (JUtility::0_5 <= fVar1) {
        uVar2 = 2;
      }
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 0;
  }
  fVar1 = this->mPosY;
  if ((fVar1 <= JUtility::_0_25) || (JUtility::0_25 <= fVar1)) {
    if (JUtility::_0_5 < fVar1) {
      if (JUtility::0_5 <= fVar1) {
        uVar2 = uVar2 | 8;
      }
    }
    else {
      uVar2 = uVar2 | 4;
    }
  }
  return uVar2;
}


/* __thiscall CRumble::clear(void) */

void __thiscall CRumble::clear(CRumble *this)

{
  this->field_0x0 = 0;
  this->field_0x4 = 0;
  this->field_0x8 = (uchar *)0x0;
  this->field_0xc = 0;
  mEnabled = -0x10000000;
  return;
}


/* __thiscall CRumble::clear(JUTGamePad *) */

void __thiscall CRumble::clear(CRumble *this,JUTGamePad *param_1)

{
  int iVar1;
  
  iVar1 = (int)param_1->mPortIdx;
  if ((-1 < iVar1) && (iVar1 < 4)) {
    mStatus[iVar1] = 0;
    stopMotorHard((int)param_1->mPortIdx);
  }
  clear(this);
  return;
}


/* __thiscall CRumble::startMotor(int) */

void __thiscall CRumble::startMotor(CRumble *this,int param_1)

{
  if ((mEnabled & JUtility::channel_mask[(int)this]) != 0) {
    pad::PADControlMotor(this,1);
    *(undefined *)&this[-0x7fc0879].field_0xc = 1;
  }
  return;
}


/* __thiscall CRumble::stopMotor(int) */

void __thiscall CRumble::stopMotor(CRumble *this,int param_1)

{
  if ((mEnabled & JUtility::channel_mask[(int)this]) != 0) {
    pad::PADControlMotor(this,0);
    *(undefined *)&this[-0x7fc0879].field_0xc = 0;
  }
  return;
}


namespace CRumble {

/* __thiscall stopMotorHard(int) */

void stopMotorHard(int index)

{
  if ((mEnabled & JUtility::channel_mask[index]) != 0) {
    pad::PADControlMotor(index,2);
    mStatus[index] = 0;
  }
  return;
}

}

/* __thiscall CRumble::update(short) */

void __thiscall CRumble::update(CRumble *this,short param_1)

{
  uint uVar1;
  undefined2 in_register_00000010;
  uint uVar2;
  int iVar3;
  
  iVar3 = (int)param_1;
  if ((mEnabled & JUtility::channel_mask[iVar3]) == 0) {
    this->field_0x0 = 0;
    this->field_0x4 = 0;
    this->field_0x8 = (uchar *)0x0;
    this->field_0xc = 0;
  }
  if (this->field_0x4 != 0) {
    uVar2 = this->field_0x0;
    if (uVar2 < this->field_0x4) {
      uVar1 = this->field_0xc;
      if (uVar1 == 0) {
        if (mStatus[iVar3] != 0) {
          return;
        }
        startMotor((CRumble *)(int)param_1,CONCAT22(in_register_00000010,param_1));
        return;
      }
      uVar2 = uVar2 - (uVar2 / uVar1) * uVar1;
      uVar2 = 0x80 >> (uVar2 & 7) & (uint)this->field_0x8[uVar2 >> 3];
      if ((uVar2 == 0) || (mStatus[iVar3] != 0)) {
        if ((uVar2 == 0) && (mStatus[iVar3] != 0)) {
          stopMotorHard((int)param_1);
        }
      }
      else {
        startMotor((CRumble *)(int)param_1,CONCAT22(in_register_00000010,param_1));
      }
    }
    else {
      stopMotorHard((int)param_1);
      this->field_0x4 = 0;
    }
    this->field_0x0 = this->field_0x0 + 1;
  }
  return;
}


/* __thiscall CRumble::triggerPatternedRumble(unsigned long) */

void __thiscall CRumble::triggerPatternedRumble(CRumble *this,ulong param_1)

{
  if (this->field_0x8 == (uchar *)0x0) {
    return;
  }
  if (this->field_0xc == 0) {
    return;
  }
  this->field_0x4 = param_1;
  this->field_0x0 = 0;
  return;
}


/* __thiscall CRumble::startPatternedRumble(unsigned char *,
                                                        CRumble::ERumble,
                                                        unsigned long) */

void __thiscall
CRumble::startPatternedRumble
          (CRumble *this,uchar *param_1,ERumble param_2,ulong param_3)

{
  this->field_0xc = (uint)*param_1 * 0x100 + (uint)param_1[1];
  this->field_0x8 = param_1 + 2;
  if (param_2 == 1) {
    triggerPatternedRumble(this,0xffffffff);
  }
  else {
    if ((int)param_2 < 1) {
      if (-1 < (int)param_2) {
        triggerPatternedRumble(this,this->field_0xc);
      }
    }
    else {
      if ((int)param_2 < 3) {
        triggerPatternedRumble(this,param_3);
      }
    }
  }
  return;
}


/* __thiscall CRumble::stopPatternedRumble(short) */

void __thiscall CRumble::stopPatternedRumble(CRumble *this,short param_1)

{
  this->field_0x4 = 0;
  stopMotorHard((int)param_1);
  return;
}


/* __thiscall CRumble::stopPatternedRumbleAtThePeriod(void) */

void __thiscall CRumble::stopPatternedRumbleAtThePeriod(CRumble *this)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = this->field_0xc;
  uVar1 = this->field_0x0 + (uVar2 - 1);
  this->field_0x4 = uVar1 - (uVar1 / uVar2) * uVar2;
  return;
}


/* __thiscall getGamePad(int) */

int getGamePad(int param_1)

{
  JSUPtrLink *pJVar1;
  
  pJVar1 = mPadList.mpHead;
  while( true ) {
    if (pJVar1 == (JSUPtrLink *)0x0) {
      return (int)(undefined *)0x0;
    }
    if (param_1 == *(short *)(pJVar1->mpData + 0x78)) break;
    pJVar1 = pJVar1->mpNext;
  }
  return (int)pJVar1->mpData;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall CRumble::setEnabled(unsigned long) */

void __thiscall CRumble::setEnabled(CRumble *this,ulong param_1)

{
  ulong extraout_r4;
  CRumble *this_00;
  int iVar1;
  byte *pbVar2;
  
  this_00 = (CRumble *)0x0;
  iVar1 = 0;
  pbVar2 = mStatus;
  do {
    if ((mEnabled & *(uint *)((int)JUtility::channel_mask + iVar1)) == 0) {
      if (*pbVar2 != 0) {
        stopMotor(this_00,param_1);
      }
      param_1 = getGamePad((int)this_00);
      if (param_1 != 0) {
        stopPatternedRumble((CRumble *)(param_1 + 0x68),*(short *)(param_1 + 0x78));
        param_1 = extraout_r4;
      }
    }
    this_00 = (CRumble *)((int)&this_00->field_0x0 + 1);
    pbVar2 = pbVar2 + 1;
    iVar1 = iVar1 + 4;
  } while ((int)this_00 < 4);
  mEnabled = (uint)this & 0xf0000000;
  return;
}


/* __thiscall CButton::setRepeat(unsigned long,
                                             unsigned long,
                                             unsigned long) */

void __thiscall
CButton::setRepeat(CButton *this,ulong param_1,ulong param_2,ulong param_3)

{
  this->field_0x20 = 0;
  this->field_0x1c = 0;
  this->field_0x24 = param_1;
  this->field_0x28 = param_2;
  this->field_0x2c = param_3;
  return;
}

}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JUTGamePad::recalibrate(unsigned long) */

bool __thiscall JUTGamePad::recalibrate(JUTGamePad *this,ulong param_1)

{
  int iVar1;
  int iVar2;
  undefined *local_18 [6];
  
  local_18[0] = JUtility::_1081;
  local_18[1] = (undefined *)DAT_8036bf7c;
  local_18[2] = (undefined *)DAT_8036bf80;
  local_18[3] = (undefined *)DAT_8036bf84;
  iVar1 = 0;
  iVar2 = 4;
  do {
    if ((_mSuppressPadReset & *(uint *)((int)local_18 + iVar1)) != 0) {
      this = (JUTGamePad *)((uint)this & (*(uint *)((int)local_18 + iVar1) ^ 0xffffffff));
    }
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar1 = pad::PADRecalibrate(this);
  return iVar1 != 0;
}


namespace JUtility {

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __sinit_JUTGamePad_cpp(void)

{
  JSUPtrList::JSUPtrList(&::JUTGamePad::mPadList,false);
  Runtime.PPCEABI.H::__register_global_object
            (&::JUTGamePad::mPadList,::JSUList<JUTGamePad>::_JSUList,&_498);
  Runtime.PPCEABI.H::__construct_array
            (::JUTGamePad::mPadButton,::JUTGamePad::CButton::CButton,(undefined *)0x0,0x30,4);
  Runtime.PPCEABI.H::__construct_array
            (::JUTGamePad::mPadMStick,::JUTGamePad::CStick::CStick,(undefined *)0x0,0x10,4);
  Runtime.PPCEABI.H::__construct_array
            (::JUTGamePad::mPadSStick,::JUTGamePad::CStick::CStick,(undefined *)0x0,0x10,4);
  _sThreshold = 0;
  DAT_803f7894 = ((DAT_800000f8 >> 2) / 0x3c) * 0x1e;
  return;
}

}

namespace JUTGamePad {

/* __thiscall CStick::CStick(void) */

void __thiscall CStick::CStick(CStick *this)

{
  clear(this);
  return;
}


/* __thiscall CButton::CButton(void) */

void __thiscall CButton::CButton(CButton *this)

{
  clear(this);
  return;
}

}

/* __thiscall JSUList<JUTGamePad>::~JSUList(void) */

JSUList_JUTGamePad_ * __thiscall JSUList<JUTGamePad>::_JSUList(JSUList_JUTGamePad_ *this)

{
  short in_r4;
  
  if ((this != (JSUList_JUTGamePad_ *)0x0) &&
     (JSUPtrList::_JSUPtrList((JSUPtrList *)this), 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return this;
}

