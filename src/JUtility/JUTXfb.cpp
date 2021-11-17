#include <JUtility/JUTXfb.h>
#include <JUtility/JUTXfb.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <gx/GXFrameBuf.h>
#include <JKernel/JKRHeap.h>
#include <JUtility/JUTAssert.h>
#include <JUTXfb.h>

struct JUTXfb * JUTXfb;

/* __thiscall JUTXfb::clearIndex(void) */

void __thiscall JUTXfb::clearIndex(JUTXfb *this)

{
  *(undefined2 *)(this + 0x14) = 0xffff;
  *(undefined2 *)(this + 0x16) = 0xffff;
  *(undefined2 *)(this + 0x18) = 0xffff;
  return;
}


/* __thiscall JUTXfb::common_init(int) */

void __thiscall JUTXfb::common_init(JUTXfb *this,int param_1)

{
  *(int *)(this + 0x10) = param_1;
  clearIndex(this);
  *(undefined4 *)(this + 0x1c) = 99;
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall JUTXfb::JUTXfb(_GXRenderModeObj const *,
                             JKRHeap *,
                             JUTXfb::EXfbNumber) */

void __thiscall
JUTXfb::JUTXfb(JUTXfb *this,_GXRenderModeObj *param_1,JKRHeap *param_2,EXfbNumber param_3)

{
  ushort uVar1;
  short sVar2;
  ushort uVar3;
  _GXRenderModeObj *p_Var4;
  
  common_init(this,param_3);
  if (param_1 == (_GXRenderModeObj *)0x0) {
    p_Var4 = JUTVideo::sManager->mpRenderMode;
    uVar1 = p_Var4->field_0x4;
    sVar2 = p_Var4->field_0x6;
    gx::GXGetYScaleFactor(sVar2,p_Var4->field_0x8);
    uVar3 = gx::GXGetNumXfbLines(sVar2);
    initiate(this,uVar1,uVar3,param_2,param_3);
  }
  else {
    initiate(this,param_1->field_0x4,param_1->field_0x8,param_2,param_3);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JUTXfb::~JUTXfb(void) */

void __thiscall JUTXfb::_JUTXfb(JUTXfb *this)

{
  short in_r4;
  int iVar1;
  
  if (this != (JUTXfb *)0x0) {
    iVar1 = 0;
    do {
      delXfb(this,iVar1);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 3);
    sManager = (JUTXfb *)0x0;
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JUTXfb::delXfb(int) */

void __thiscall JUTXfb::delXfb(JUTXfb *this,int param_1)

{
  if ((this[param_1 + 0xc] != (JUTXfb)0x0) && (*(JKRHeap **)(this + param_1 * 4) != (JKRHeap *)0x0))
  {
    JKernel::operator_delete(*(JKRHeap **)(this + param_1 * 4));
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JUTXfb::createManager(_GXRenderModeObj const *,
                                    JKRHeap *,
                                    JUTXfb::EXfbNumber) */

JUTXfb * __thiscall
JUTXfb::createManager(JUTXfb *this,_GXRenderModeObj *param_1,JKRHeap *param_2,EXfbNumber param_3)

{
  uint uVar1;
  JUTAssertion *this_00;
  JUTXfb *this_01;
  char *in_r8;
  
  this_00 = (JUTAssertion *)JUTAssertion::getSDevice();
  uVar1 = countLeadingZeros(sManager);
  JUTAssertion::setConfirmMessage(this_00,(ulong)"JUTXfb.cpp",(char *)0xcb,uVar1 >> 5,true,in_r8);
  this_01 = sManager;
  if ((sManager == (JUTXfb *)0x0) &&
     (this_01 = (JUTXfb *)JKernel::operator_new(0x20), this_01 != (JUTXfb *)0x0)) {
    JUTXfb(this_01,(_GXRenderModeObj *)this,(JKRHeap *)param_1,(EXfbNumber)param_2);
  }
  sManager = this_01;
  return sManager;
}


/* __thiscall JUTXfb::destroyManager(void) */

void __thiscall JUTXfb::destroyManager(JUTXfb *this)

{
  JUTAssertion *this_00;
  char *in_r8;
  
  this_00 = (JUTAssertion *)JUTAssertion::getSDevice();
  JUTAssertion::setConfirmMessage
            (this_00,(ulong)"JUTXfb.cpp",(char *)0x158,(uint)(sManager != (JUTXfb *)0x0),true,in_r8)
  ;
  _JUTXfb(sManager);
  sManager = (JUTXfb *)0x0;
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JUTXfb::initiate(unsigned short,
                               unsigned short,
                               JKRHeap *,
                               JUTXfb::EXfbNumber) */

void __thiscall
JUTXfb::initiate(JUTXfb *this,ushort param_1,ushort param_2,JKRHeap *param_3,EXfbNumber param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_3 == (JKRHeap *)0x0) {
    param_3 = JKRHeap::sSystemHeap;
  }
  iVar1 = (param_1 + 0xf & 0xfff0) * (uint)param_2 * 2;
  uVar2 = JKernel::operator_new__(iVar1,param_3,0x20);
  *(undefined4 *)this = uVar2;
  this[0xc] = (JUTXfb)0x1;
  if ((int)param_4 < 2) {
    *(undefined4 *)(this + 4) = 0;
    this[0xd] = (JUTXfb)0x0;
  }
  else {
    uVar2 = JKernel::operator_new__(iVar1,param_3,0x20);
    *(undefined4 *)(this + 4) = uVar2;
    this[0xd] = (JUTXfb)0x1;
  }
  if ((int)param_4 < 3) {
    *(undefined4 *)(this + 8) = 0;
    this[0xe] = (JUTXfb)0x0;
  }
  else {
    uVar2 = JKernel::operator_new__(iVar1,param_3,0x20);
    *(undefined4 *)(this + 8) = uVar2;
    this[0xe] = (JUTXfb)0x1;
  }
  return;
}

