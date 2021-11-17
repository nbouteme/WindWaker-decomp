#include <JMessage/control.h>
#include <JKernel/JKRHeap.h>
#include <JMessage/resource.h>
#include <JMessage/control.h>
#include <JMessage/processor.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <Demangler/JMessage/TControl.h>


namespace JMessage {

/* __thiscall TControl::TControl(void) */

void __thiscall TControl::TControl(TControl *this)

{
  *(undefined1 **)this = &__vt;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined2 *)(this + 0x14) = 0;
  *(undefined2 *)(this + 0x16) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x38) = 0;
  return;
}


/* __thiscall TControl::~TControl(void) */

void __thiscall TControl::_TControl(TControl *this)

{
  short in_r4;
  
  if ((this != (TControl *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall TControl::getResource_groupID(unsigned short) const */

int __thiscall TControl::getResource_groupID(TControl *this,ushort param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  
  bVar1 = false;
  iVar2 = *(int *)(this + 8);
  if ((iVar2 != 0) && (param_1 == *(ushort *)(*(int *)(iVar2 + 0xc) + 0xc))) {
    bVar1 = true;
  }
  if (!bVar1) {
    if (*(TResourceContainer **)(this + 4) == (TResourceContainer *)0x0) {
      iVar2 = 0;
    }
    else {
      uVar3 = TResourceContainer::Get_groupID(*(TResourceContainer **)(this + 4),param_1);
      *(undefined4 *)(this + 8) = uVar3;
      iVar2 = *(int *)(this + 8);
    }
  }
  return iVar2;
}


/* __thiscall TControl::getMessageData(unsigned short,
                                                 unsigned short) const */

int __thiscall TControl::getMessageData(TControl *this,ushort param_1,ushort param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = getResource_groupID(this,param_1);
  if (iVar1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    iVar1 = *(int *)(iVar1 + 0xc);
    if ((uint)param_2 < (uint)*(ushort *)(iVar1 + 8)) {
      piVar2 = (int *)(iVar1 + (uint)param_2 * (uint)*(ushort *)(iVar1 + 10) + 0x10);
    }
    else {
      piVar2 = (int *)0x0;
    }
  }
  if (piVar2 == (int *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(*(int *)(this + 8) + 0x10) + *piVar2;
  }
  return iVar1;
}


/* __thiscall TControl::reset(void) */

void __thiscall TControl::reset(TControl *this)

{
  reset_(this);
  if (*(TSequenceProcessor **)(this + 0xc) != (TSequenceProcessor *)0x0) {
    TSequenceProcessor::reset_(*(TSequenceProcessor **)(this + 0xc),(char *)0x0);
  }
  if (*(TProcessor **)(this + 0x10) != (TProcessor *)0x0) {
    TProcessor::reset_(*(TProcessor **)(this + 0x10),(char *)0x0);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall TControl::update(void) */

undefined4 __thiscall TControl::update(TControl *this)

{
  bool bVar1;
  undefined4 uVar2;
  char *pcVar3;
  int *this_00;
  
  bVar1 = false;
  if (((*(int *)(this + 0x18) != 0) && (*(int *)(this + 0x1c) != 0)) && (*(int *)(this + 0xc) != 0))
  {
    bVar1 = true;
  }
  if (bVar1) {
    if (*(int *)(this + 0x24) == 0) {
      *(undefined4 *)(this + 0x24) = *(undefined4 *)(this + 0x1c);
      pcVar3 = *(char **)(this + 0x1c);
      uVar2 = *(undefined4 *)(this + 0x18);
      this_00 = *(int **)(this + 0xc);
      TSequenceProcessor::reset_((TSequenceProcessor *)this_00,pcVar3);
      (**(code **)(*this_00 + 0x20))(this_00,uVar2,pcVar3);
    }
    uVar2 = TSequenceProcessor::process(*(TSequenceProcessor **)(this + 0xc),(char *)0x0);
    *(undefined4 *)(this + 0x24) = uVar2;
    if (*(int *)(this + 0x24) == 0) {
      *(undefined4 *)(this + 0x1c) = 0;
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall TControl::render(void) */

void __thiscall TControl::render(TControl *this)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  int *this_00;
  
  bVar1 = false;
  iVar3 = *(int *)(this + 0x18);
  if (((iVar3 != 0) && (*(int *)(this + 0x20) != 0)) && (*(int *)(this + 0x10) != 0)) {
    bVar1 = true;
  }
  if (bVar1) {
    pcVar4 = *(char **)(this + 0x20);
    this_00 = *(int **)(this + 0x10);
    TProcessor::reset_((TProcessor *)this_00,pcVar4);
    (**(code **)(*this_00 + 0x20))(this_00,iVar3,pcVar4);
    iVar3 = *(int *)(this + 0x10);
    uVar2 = *(undefined4 *)(this + 0x2c);
    *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(this + 0x28);
    *(undefined4 *)(iVar3 + 0x10) = uVar2;
    uVar2 = *(undefined4 *)(this + 0x34);
    *(undefined4 *)(iVar3 + 0x14) = *(undefined4 *)(this + 0x30);
    *(undefined4 *)(iVar3 + 0x18) = uVar2;
    *(undefined4 *)(iVar3 + 0x1c) = *(undefined4 *)(this + 0x38);
    TRenderingProcessor::process(*(TRenderingProcessor **)(this + 0x10),*(char **)(this + 0x24));
  }
  return;
}


/* __thiscall TControl::do_word(unsigned long) */

undefined4 __thiscall TControl::do_word(TControl *this,ulong param_1)

{
  return 0;
}


/* __thiscall TControl::setMessageCode_flush_(void) */

bool __thiscall TControl::setMessageCode_flush_(TControl *this)

{
  ushort uVar1;
  int iVar2;
  int *piVar3;
  
  reset_(this);
  uVar1 = *(ushort *)(this + 0x16);
  iVar2 = getResource_groupID(this,*(ushort *)(this + 0x14));
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(iVar2 + 0xc);
    if ((uint)uVar1 < (uint)*(ushort *)(iVar2 + 8)) {
      iVar2 = iVar2 + (uint)uVar1 * (uint)*(ushort *)(iVar2 + 10) + 0x10;
    }
    else {
      iVar2 = 0;
    }
  }
  *(int *)(this + 0x18) = iVar2;
  piVar3 = *(int **)(this + 0x18);
  if (piVar3 != (int *)0x0) {
    *(int *)(this + 0x1c) = *(int *)(*(int *)(this + 8) + 0x10) + *piVar3;
    *(undefined4 *)(this + 0x20) = *(undefined4 *)(this + 0x1c);
  }
  return piVar3 != (int *)0x0;
}


/* __thiscall TControl::reset_(void) */

void __thiscall TControl::reset_(TControl *this)

{
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x38) = 0;
  return;
}

