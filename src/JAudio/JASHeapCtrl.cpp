#include <JAudio/JASHeapCtrl.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JSupport/JSUList.h>
#include <os/OSMutex.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <JAudio/JASHeapCtrl.h>
#include <JASystem/Kernel/TSolidHeap.h>
#include <JASystem/Kernel/THeap.h>
#include <Demangler/JASystem/Kernel/TDisposer.h>


namespace JASystem {

namespace Kernel {

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall THeap::THeap(TDisposer *) */

void __thiscall THeap::THeap(THeap *this,TDisposer *param_1)

{
  JSUPtrList::initiate((JSUPtrList *)this);
  JSUPtrLink::JSUPtrLink((JSUPtrLink *)(this + 0xc),this);
  *(TDisposer **)(this + 0x34) = param_1;
  *(undefined4 *)(this + 0x38) = 1;
  *(undefined4 *)(this + 0x3c) = 0;
  *(undefined4 *)(this + 0x40) = 0;
  *(undefined4 *)(this + 0x44) = 0;
  os::OSInitMutex((OSMutex *)(this + 0x1c));
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall THeap::initRootHeap(void *,
                                                    unsigned long,
                                                    THeap::Type) */

void __thiscall
THeap::initRootHeap(THeap *this,void *param_1,ulong param_2,Type param_3)

{
  ulong uVar1;
  
  if (*(int *)(this + 0x3c) != 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JASHeapCtrl.cpp",0x5c,"! isAllocated()");
    m_Do_printf::OSPanic("JASHeapCtrl.cpp",0x5c,&DAT_80367110);
  }
  os::OSLockMutex((OSMutex *)(this + 0x1c));
  *(uint *)(this + 0x3c) = (int)param_1 + 0x1fU & 0xffffffe0;
  *(undefined4 *)(this + 0x44) = 0;
  *(ulong *)(this + 0x40) = param_2 - (*(int *)(this + 0x3c) - (int)param_1);
  *(Type *)(this + 0x38) = param_3;
  os::OSUnlockMutex(this + 0x1c);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall THeap::alloc(THeap *,
                                             unsigned long) */

undefined4 __thiscall THeap::alloc(THeap *this,THeap *param_1,ulong param_2)

{
  uint uVar1;
  bool bVar2;
  uint uVar3;
  ulong uVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  THeap *pTVar8;
  void *pvVar9;
  void *pvVar10;
  THeap *pTVar11;
  uint uVar12;
  void *unaff_r31;
  
  if (param_1 == (THeap *)0x0) {
    uVar4 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar4,"JASHeapCtrl.cpp",0x76,"mother != 0");
    m_Do_printf::OSPanic("JASHeapCtrl.cpp",0x76,&DAT_80367110);
  }
  os::OSLockMutex((OSMutex *)(this + 0x1c));
  if (*(int *)(this + 0x3c) == 0) {
    if (*(int *)(param_1 + 0x3c) == 0) {
      os::OSUnlockMutex(this + 0x1c);
      uVar5 = 0;
    }
    else {
      uVar1 = param_2 + 0x1f & 0xffffffe0;
      iVar6 = getCurOffset(param_1);
      uVar7 = getTailOffset(param_1);
      if (uVar7 < iVar6 + uVar1) {
        uVar12 = 0xffffffff;
        pvVar10 = *(void **)(param_1 + 0x3c);
        bVar2 = false;
        pTVar8 = (THeap *)0x0;
        iVar6 = *(int *)param_1;
        if (iVar6 != 0) {
          iVar6 = iVar6 + -0xc;
        }
        pvVar9 = pvVar10;
        while ((iVar6 != 0 && (pvVar9 < (void *)((int)pvVar10 + uVar7)))) {
          pTVar11 = *(THeap **)(iVar6 + 0xc);
          uVar3 = *(int *)(pTVar11 + 0x3c) - (int)pvVar9;
          if ((uVar1 <= uVar3) && (uVar3 < uVar12)) {
            bVar2 = true;
            pTVar8 = pTVar11;
            uVar12 = uVar3;
            unaff_r31 = pvVar9;
          }
          pvVar9 = (void *)(*(int *)(pTVar11 + 0x3c) + *(int *)(pTVar11 + 0x40));
          iVar6 = *(int *)(iVar6 + 0x18);
          if (iVar6 != 0) {
            iVar6 = iVar6 + -0xc;
          }
        }
        if (pvVar9 != pvVar10) {
          if (pvVar9 < (void *)((int)pvVar10 + uVar7)) {
            uVar7 = (int)pvVar10 + (*(int *)(param_1 + 0x40) - (int)pvVar9);
            if ((uVar1 <= uVar7) && (uVar7 < uVar12)) {
              pTVar8 = (THeap *)0x0;
              bVar2 = true;
              unaff_r31 = pvVar9;
            }
          }
        }
        if (bVar2) {
          insertChild(param_1,this,pTVar8,unaff_r31,uVar1,false);
          os::OSUnlockMutex(this + 0x1c);
          uVar5 = 1;
        }
        else {
          m_Do_printf::OSReport
                    (
                    "[JASHeap::alloc] マザーメモリが足りないので確保できません。\n"
                    );
          os::OSUnlockMutex(this + 0x1c);
          uVar5 = 0;
        }
      }
      else {
        pTVar8 = (THeap *)getTailHeap(param_1);
        insertChild(param_1,this,pTVar8,(void *)(*(int *)(param_1 + 0x3c) + iVar6),uVar1,false);
        os::OSUnlockMutex(this + 0x1c);
        uVar5 = 1;
      }
    }
  }
  else {
    m_Do_printf::OSReport
              (
              "[JASHeap::alloc] すでにヒープは確保されています。初期化してからにしてください。\n"
              );
    os::OSUnlockMutex(this + 0x1c);
    uVar5 = 0;
  }
  return uVar5;
}


/* __thiscall THeap::free(void) */

void __thiscall THeap::free(THeap *this,void *__ptr)

{
  int iVar1;
  JSUPtrList *this_00;
  void *extraout_r4;
  void *__ptr_00;
  JSUPtrLink *pJVar2;
  int iVar3;
  
  os::OSLockMutex((OSMutex *)(this + 0x1c));
  if (*(int *)(this + 0x3c) == 0) {
    os::OSUnlockMutex(this + 0x1c);
  }
  else {
    iVar1 = *(int *)this;
    __ptr_00 = extraout_r4;
    if (iVar1 != 0) {
      iVar1 = iVar1 + -0xc;
    }
    while (iVar1 != 0) {
      iVar3 = *(int *)(iVar1 + 0x18);
      if (iVar3 != 0) {
        iVar3 = iVar3 + -0xc;
      }
      free(*(THeap **)(iVar1 + 0xc),__ptr_00);
      iVar1 = iVar3;
    }
    this_00 = *(JSUPtrList **)(this + 0x10);
    if (this_00 != (JSUPtrList *)0x0) {
      pJVar2 = this_00[1].mpHead;
      if (pJVar2[4].mpList == (JSUPtrList *)this) {
        iVar1 = *(int *)(this + 0x14);
        if (iVar1 != 0) {
          iVar1 = iVar1 + -0xc;
        }
        if (iVar1 == 0) {
          pJVar2[4].mpList = (JSUPtrList *)0x0;
        }
        else {
          pJVar2[4].mpList = *(JSUPtrList **)(iVar1 + 0xc);
        }
      }
      pJVar2 = (JSUPtrLink *)this;
      if (this != (THeap *)0x0) {
        pJVar2 = (JSUPtrLink *)(this + 0xc);
      }
      JSUPtrList::remove(this_00,pJVar2);
    }
    *(undefined4 *)(this + 0x3c) = 0;
    *(undefined4 *)(this + 0x44) = 0;
    *(undefined4 *)(this + 0x40) = 0;
    if (*(int **)(this + 0x34) != (int *)0x0) {
      (**(code **)(**(int **)(this + 0x34) + 8))();
    }
    os::OSUnlockMutex(this + 0x1c);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall THeap::insertChild(THeap *,
                                                   THeap *,
                                                   void *,
                                                   unsigned long,
                                                   bool) */

void __thiscall
THeap::insertChild
          (THeap *this,THeap *param_1,THeap *param_2,void *param_3,ulong param_4,bool param_5)

{
  bool bVar1;
  ulong uVar2;
  int iVar3;
  
  if (param_1 == (THeap *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"JASHeapCtrl.cpp",0x219,"heap != 0");
    m_Do_printf::OSPanic("JASHeapCtrl.cpp",0x219,&DAT_80367110);
  }
  bVar1 = false;
  if (param_2 != (THeap *)0x0) {
    if (this != *(THeap **)(param_2 + 0x10)) goto LAB_8027d104;
  }
  bVar1 = true;
LAB_8027d104:
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar2,"JASHeapCtrl.cpp",0x21a,"next == 0 || &mTree == next->mTree.getParent()");
    m_Do_printf::OSPanic("JASHeapCtrl.cpp",0x21a,&DAT_80367110);
  }
  os::OSLockMutex((OSMutex *)(this + 0x1c));
  if (param_5 == false) {
    if (param_2 == (THeap *)0x0) {
      iVar3 = *(int *)(this + 4);
      if (iVar3 != 0) {
        iVar3 = iVar3 + -0xc;
      }
    }
    else {
      iVar3 = *(int *)(param_2 + 0x14);
      if (iVar3 != 0) {
        iVar3 = iVar3 + -0xc;
      }
    }
    if (iVar3 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(iVar3 + 0xc);
    }
    if (*(int *)(this + 0x44) == iVar3) {
      *(THeap **)(this + 0x44) = param_1;
    }
  }
  *(void **)(param_1 + 0x3c) = param_3;
  *(ulong *)(param_1 + 0x40) = param_4;
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(this + 0x38);
  if (param_1 != (THeap *)0x0) {
    param_1 = param_1 + 0xc;
  }
  if (param_2 != (THeap *)0x0) {
    param_2 = param_2 + 0xc;
  }
  JSUPtrList::insert((JSUPtrList *)this,(JSUPtrLink *)param_2,(JSUPtrLink *)param_1);
  os::OSUnlockMutex(this + 0x1c);
  return;
}


/* __thiscall THeap::getTailHeap(void) */

undefined4 __thiscall THeap::getTailHeap(THeap *this)

{
  undefined4 uVar1;
  int iVar2;
  
  os::OSLockMutex((OSMutex *)(this + 0x1c));
  if (*(int *)(this + 0x44) == 0) {
    iVar2 = *(int *)this;
    if (iVar2 != 0) {
      iVar2 = iVar2 + -0xc;
    }
  }
  else {
    iVar2 = *(int *)(*(int *)(this + 0x44) + 0x18);
    if (iVar2 != 0) {
      iVar2 = iVar2 + -0xc;
    }
  }
  os::OSUnlockMutex(this + 0x1c);
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(iVar2 + 0xc);
  }
  return uVar1;
}


/* __thiscall THeap::getTailOffset(void) */

int __thiscall THeap::getTailOffset(THeap *this)

{
  int iVar1;
  
  os::OSLockMutex((OSMutex *)(this + 0x1c));
  iVar1 = getTailHeap(this);
  if (iVar1 == 0) {
    iVar1 = *(int *)(this + 0x40);
  }
  else {
    iVar1 = *(int *)(iVar1 + 0x3c) - *(int *)(this + 0x3c);
  }
  os::OSUnlockMutex(this + 0x1c);
  return iVar1;
}


/* __thiscall THeap::getCurOffset(void) */

int __thiscall THeap::getCurOffset(THeap *this)

{
  int iVar1;
  
  os::OSLockMutex((OSMutex *)(this + 0x1c));
  iVar1 = *(int *)(this + 0x44);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = (*(int *)(iVar1 + 0x3c) + *(int *)(iVar1 + 0x40)) - *(int *)(this + 0x3c);
  }
  os::OSUnlockMutex(this + 0x1c);
  return iVar1;
}


/* __thiscall TSolidHeap::TSolidHeap(void) */

void __thiscall TSolidHeap::TSolidHeap(TSolidHeap *this)

{
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  return;
}


/* __thiscall TSolidHeap::alloc(long) */

int __thiscall TSolidHeap::alloc(TSolidHeap *this,long param_1)

{
  int iVar1;
  uint uVar2;
  
  if (*(int *)this == 0) {
    m_Do_printf::OSReport
              (
              "[Nas_HeapAlloc] ヒープが取得できません（ヒープ取得元存在せず）。\n"
              );
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(this + 4);
    uVar2 = iVar1 + (param_1 + 0x1fU & 0xffffffe0);
    if ((uint)(*(int *)this + *(int *)(this + 8)) < uVar2) {
      m_Do_printf::OSReport
                (
                "[Nas_HeapAlloc] ヒープが取得できません（ヒープの取得元の残りサイズ不足）。\n"
                );
      iVar1 = 0;
    }
    else {
      *(uint *)(this + 4) = uVar2;
      *(int *)(this + 0xc) = *(int *)(this + 0xc) + 1;
      *(int *)(this + 0x10) = iVar1;
    }
  }
  return iVar1;
}


/* __thiscall TSolidHeap::freeAll(void) */

void __thiscall TSolidHeap::freeAll(TSolidHeap *this)

{
  *(undefined4 *)(this + 4) = *(undefined4 *)this;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  return;
}


/* __thiscall TSolidHeap::init(unsigned char *,
                                                 long) */

int __thiscall TSolidHeap::init(TSolidHeap *this,EVP_PKEY_CTX *ctx)

{
  int iVar1;
  int in_r5;
  
  iVar1 = 0;
  *(undefined4 *)(this + 0xc) = 0;
  if (ctx == (EVP_PKEY_CTX *)0x0) {
    iVar1 = m_Do_printf::OSReport
                      (
                      "[Nas_HeapInit] アドレス０からヒープを初期化しようとしています。\n"
                      );
    *(undefined4 *)(this + 8) = 0;
    *(undefined4 *)(this + 4) = 0;
    *(undefined4 *)(this + 0x10) = 0;
  }
  else {
    *(uint *)this = (uint)(ctx + 0x1f) & 0xffffffe0;
    *(undefined4 *)(this + 4) = *(undefined4 *)this;
    *(int *)(this + 8) = in_r5 - (*(int *)this - (int)ctx);
    *(undefined4 *)(this + 0x10) = 0;
  }
  return iVar1;
}


/* __thiscall TSolidHeap::getRemain(void) */

int __thiscall TSolidHeap::getRemain(TSolidHeap *this)

{
  return *(int *)(this + 8) - (*(int *)(this + 4) - *(int *)this);
}


/* __thiscall TDisposer::onDispose(void) */

void __thiscall TDisposer::onDispose(TDisposer *this)

{
  return;
}

