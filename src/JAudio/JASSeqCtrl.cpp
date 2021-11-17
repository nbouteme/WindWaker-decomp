#include <JAudio/JASSeqCtrl.h>
#include <JUtility/JUTAssert.h>
#include <JASystem/TSeqCtrl.h>


namespace JASystem {

/* __thiscall TSeqCtrl::init(void) */

int __thiscall TSeqCtrl::init(TSeqCtrl *this,EVP_PKEY_CTX *ctx)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  iVar1 = 0;
  iVar2 = 0;
  iVar3 = 8;
  do {
    *(undefined4 *)(this + iVar2 + 0x10) = 0;
    *(undefined2 *)(this + iVar1 + 0x30) = 0;
    iVar1 = iVar1 + 2;
    iVar2 = iVar2 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined4 *)(this + 0x40) = 0;
  *(undefined4 *)(this + 0x44) = 0;
  return (int)this;
}


/* __thiscall TSeqCtrl::start(void *,
                                        unsigned long) */

void __thiscall TSeqCtrl::start(TSeqCtrl *this,void *param_1,ulong param_2)

{
  *(void **)this = param_1;
  *(ulong *)(this + 4) = *(int *)this + param_2;
  return;
}


/* __thiscall TSeqCtrl::loopEnd(void) */

undefined4 __thiscall TSeqCtrl::loopEnd(TSeqCtrl *this)

{
  ulong uVar1;
  undefined4 uVar2;
  short sVar3;
  
  if (*(int *)(this + 0xc) == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::setWarningMessage_f
              (uVar1,"JASSeqCtrl.cpp",0x2d,"%s",(___)"cannot loopE for call-stack is NULL");
    uVar2 = 0;
  }
  else {
    sVar3 = *(short *)(this + *(int *)(this + 0xc) * 2 + 0x2e);
    if (sVar3 != 0) {
      sVar3 = sVar3 + -1;
    }
    if (sVar3 == 0) {
      *(int *)(this + 0xc) = *(int *)(this + 0xc) + -1;
      uVar2 = 1;
    }
    else {
      *(short *)(this + *(int *)(this + 0xc) * 2 + 0x2e) = sVar3;
      *(undefined4 *)(this + 4) = *(undefined4 *)(this + *(int *)(this + 0xc) * 4 + 0xc);
      uVar2 = 1;
    }
  }
  return uVar2;
}


/* __thiscall TSeqCtrl::waitCountDown(void) */

undefined4 __thiscall TSeqCtrl::waitCountDown(TSeqCtrl *this)

{
  if ((0 < *(int *)(this + 8)) &&
     (*(int *)(this + 8) = *(int *)(this + 8) + -1, *(int *)(this + 8) != 0)) {
    return 0;
  }
  return 1;
}


/* __thiscall TSeqCtrl::callIntr(void *) */

undefined4 __thiscall TSeqCtrl::callIntr(TSeqCtrl *this,void *param_1)

{
  if (*(int *)(this + 0x44) != 0) {
    return 0;
  }
  *(undefined4 *)(this + 0x44) = *(undefined4 *)(this + 4);
  *(void **)(this + 4) = param_1;
  *(undefined4 *)(this + 0x40) = *(undefined4 *)(this + 8);
  *(undefined4 *)(this + 8) = 0;
  return 1;
}


/* __thiscall TSeqCtrl::retIntr(void) */

undefined4 __thiscall TSeqCtrl::retIntr(TSeqCtrl *this)

{
  if (*(int *)(this + 0x44) == 0) {
    return 0;
  }
  *(undefined4 *)(this + 8) = *(undefined4 *)(this + 0x40);
  *(undefined4 *)(this + 4) = *(undefined4 *)(this + 0x44);
  *(undefined4 *)(this + 0x44) = 0;
  return 1;
}


/* __thiscall TSeqCtrl::get16(unsigned long) const */

undefined2 __thiscall TSeqCtrl::get16(TSeqCtrl *this,ulong param_1)

{
  return CONCAT11(*(undefined *)(*(int *)this + param_1),*(undefined *)(*(int *)this + param_1 + 1))
  ;
}


/* __thiscall TSeqCtrl::get24(unsigned long) const */

uint __thiscall TSeqCtrl::get24(TSeqCtrl *this,ulong param_1)

{
  int iVar1;
  
  iVar1 = *(int *)this;
  return (uint)CONCAT21(CONCAT11(*(undefined *)(iVar1 + param_1),*(undefined *)(iVar1 + param_1 + 1)
                                ),*(undefined *)(iVar1 + param_1 + 2));
}


/* __thiscall TSeqCtrl::get32(unsigned long) const */

undefined4 __thiscall TSeqCtrl::get32(TSeqCtrl *this,ulong param_1)

{
  int iVar1;
  
  iVar1 = *(int *)this;
  return CONCAT31(CONCAT21(CONCAT11(*(undefined *)(iVar1 + param_1),
                                    *(undefined *)(iVar1 + param_1 + 1)),
                           *(undefined *)(iVar1 + param_1 + 2)),*(undefined *)(iVar1 + param_1 + 3))
  ;
}


/* __thiscall TSeqCtrl::read16(void) */

undefined2 __thiscall TSeqCtrl::read16(TSeqCtrl *this)

{
  undefined uVar1;
  undefined *puVar2;
  
  puVar2 = *(undefined **)(this + 4);
  *(undefined **)(this + 4) = puVar2 + 1;
  uVar1 = *puVar2;
  puVar2 = *(undefined **)(this + 4);
  *(undefined **)(this + 4) = puVar2 + 1;
  return CONCAT11(uVar1,*puVar2);
}


/* __thiscall TSeqCtrl::read24(void) */

uint __thiscall TSeqCtrl::read24(TSeqCtrl *this)

{
  undefined uVar1;
  undefined uVar2;
  undefined *puVar3;
  
  puVar3 = *(undefined **)(this + 4);
  *(undefined **)(this + 4) = puVar3 + 1;
  uVar1 = *puVar3;
  puVar3 = *(undefined **)(this + 4);
  *(undefined **)(this + 4) = puVar3 + 1;
  uVar2 = *puVar3;
  puVar3 = *(undefined **)(this + 4);
  *(undefined **)(this + 4) = puVar3 + 1;
  return (uint)CONCAT21(CONCAT11(uVar1,uVar2),*puVar3);
}

