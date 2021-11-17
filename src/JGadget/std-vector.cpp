#include <JGadget/std-vector.h>
#include <JGadget/std-vector.h>
#include <JKernel/JKRHeap.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JGadget/TVector_pointer_void.h>
#include <JGadget/TVector<void*,JGadget::TAllocator<void*>>.h>
#include <JGadget/vector.h>


namespace JGadget {

/* __thiscall vector::extend_default(unsigned long,
                                              unsigned long,
                                              unsigned long) */

int __thiscall
vector::extend_default(vector *this,ulong param_1,ulong param_2,ulong param_3)

{
  return param_1 << 1;
}


/* __thiscall TVector_pointer_void::TVector_pointer_void(TAllocator<void *> const
   &) */

void __thiscall
TVector_pointer_void::TVector_pointer_void(TVector_pointer_void *this,TAllocator *param_1)

{
  *this = *(TVector_pointer_void *)param_1;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = *(undefined4 *)(this + 4);
  *(undefined4 *)(this + 0xc) = 0;
  *(code **)(this + 0x10) = vector::extend_default;
  return;
}


/* WARNING: Removing unreachable block (ram,0x802bff8c) */
/* __thiscall TVector_pointer_void::~TVector_pointer_void(void) */

void __thiscall TVector_pointer_void::_TVector_pointer_void(TVector_pointer_void *this)

{
  int iVar1;
  short in_r4;
  
  if (this != (TVector_pointer_void *)0x0) {
    if (this != (TVector_pointer_void *)0x0) {
      for (iVar1 = *(int *)(this + 4); iVar1 != *(int *)(this + 8); iVar1 = iVar1 + 4) {
      }
      *(int *)(this + 8) = *(int *)(this + 4);
      JKernel::operator_delete(*(JKRHeap **)(this + 4));
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TVector_pointer_void::insert(void * *,
                                                    void const * &) */

void __thiscall
TVector_pointer_void::insert(TVector_pointer_void *this,void **param_1,void **param_2)

{
  TVector<void*,TAllocator<void*>>::insert
            ((TVector_void__JGadget__TAllocator_void___ *)this,param_1,param_2);
  return;
}


/* __thiscall TVector_pointer_void::erase(void * *,
                                                   void * *) */

void ** __thiscall
TVector_pointer_void::erase(TVector_pointer_void *this,void **param_1,void **param_2)

{
  void **ppvVar1;
  void **ppvVar2;
  uint uVar3;
  
  uVar3 = (uint)((int)*(void ***)(this + 8) + (3 - (int)param_2)) >> 2;
  ppvVar2 = param_1;
  if (param_2 < *(void ***)(this + 8)) {
    do {
      *ppvVar2 = *param_2;
      param_2 = param_2 + 1;
      ppvVar2 = ppvVar2 + 1;
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  for (ppvVar1 = ppvVar2; ppvVar1 != *(void ***)(this + 8); ppvVar1 = ppvVar1 + 1) {
  }
  *(void ***)(this + 8) = ppvVar2;
  return param_1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall TVector<void *,TAllocator<void *>>::insert(void * *,
                                                                           unsigned long,
                                                                           void const * &) */

void __thiscall
TVector<void*,TAllocator<void*>>::insert
          (TVector_void__JGadget__TAllocator_void___ *this,void **param_1,ulong param_2,
          void **param_3)

{
  void **ppvVar1;
  
  if (((param_2 != 0) &&
      (ppvVar1 = (void **)Insert_raw(this,param_1,param_2), ppvVar1 != *(void ***)(this + 8))) &&
     (param_2 != 0)) {
    do {
      if (ppvVar1 != (void **)0x0) {
        *ppvVar1 = *param_3;
      }
      ppvVar1 = ppvVar1 + 1;
      param_2 = param_2 - 1;
    } while (param_2 != 0);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall TVector<void *,TAllocator<void *>>::Insert_raw(void * *,
                                                                               unsigned long) */

void ** __thiscall
TVector<void*,TAllocator<void*>>::Insert_raw
          (TVector_void__JGadget__TAllocator_void___ *this,void **param_1,ulong param_2)

{
  int iVar1;
  void **ppvVar2;
  void **ppvVar3;
  void **ppvVar4;
  JKRHeap *pJVar5;
  int iVar6;
  JKRHeap *pJVar7;
  void **ppvVar8;
  uint uVar9;
  uint uVar10;
  
  if (param_2 != 0) {
    iVar6 = *(int *)(this + 4);
    if (iVar6 == 0) {
      iVar1 = 0;
    }
    else {
      uVar9 = *(int *)(this + 8) - iVar6;
      iVar1 = ((int)uVar9 >> 2) + (uint)((int)uVar9 < 0 && (uVar9 & 3) != 0);
    }
    if (*(uint *)(this + 0xc) < param_2 + iVar1) {
      if (iVar6 == 0) {
        iVar6 = 0;
      }
      else {
        uVar9 = *(int *)(this + 8) - iVar6;
        iVar6 = ((int)uVar9 >> 2) + (uint)((int)uVar9 < 0 && (uVar9 & 3) != 0);
      }
      uVar9 = (**(code **)(this + 0x10))(*(uint *)(this + 0xc),iVar6,param_2);
      if (uVar9 < iVar6 + param_2) {
        uVar9 = iVar6 + param_2;
      }
      ppvVar3 = (void **)JKernel::operator_new(uVar9 << 2);
      if (ppvVar3 == (void **)0x0) {
        param_1 = *(void ***)(this + 8);
      }
      else {
        ppvVar4 = *(void ***)(this + 4);
        uVar10 = (uint)((int)param_1 + (3 - (int)ppvVar4)) >> 2;
        ppvVar8 = ppvVar3;
        if (ppvVar4 < param_1) {
          do {
            *ppvVar8 = *ppvVar4;
            ppvVar8 = ppvVar8 + 1;
            ppvVar4 = ppvVar4 + 1;
            uVar10 = uVar10 - 1;
          } while (uVar10 != 0);
        }
        ppvVar4 = ppvVar8 + param_2;
        uVar10 = (uint)((int)*(void ***)(this + 8) + (3 - (int)param_1)) >> 2;
        if (param_1 < *(void ***)(this + 8)) {
          do {
            *ppvVar4 = *param_1;
            ppvVar4 = ppvVar4 + 1;
            param_1 = param_1 + 1;
            uVar10 = uVar10 - 1;
          } while (uVar10 != 0);
        }
        pJVar7 = *(JKRHeap **)(this + 4);
        for (pJVar5 = pJVar7; pJVar5 != *(JKRHeap **)(this + 8);
            pJVar5 = (JKRHeap *)&pJVar5->field_0x4) {
        }
        uVar10 = *(int *)(this + 8) - *(int *)(this + 4);
        *(void ***)(this + 8) =
             ppvVar3 + param_2 + ((int)uVar10 >> 2) + (uint)((int)uVar10 < 0 && (uVar10 & 3) != 0);
        *(void ***)(this + 4) = ppvVar3;
        *(uint *)(this + 0xc) = uVar9;
        JKernel::operator_delete(pJVar7);
        param_1 = ppvVar8;
      }
    }
    else {
      ppvVar3 = param_1 + param_2;
      ppvVar8 = *(void ***)(this + 8);
      if (ppvVar3 < ppvVar8) {
        ppvVar4 = ppvVar8 + -param_2;
        uVar9 = (uint)((int)ppvVar8 + (3 - (int)ppvVar4)) >> 2;
        ppvVar2 = ppvVar4;
        if (ppvVar4 < ppvVar8) {
          do {
            *ppvVar8 = *ppvVar2;
            ppvVar8 = ppvVar8 + 1;
            ppvVar2 = ppvVar2 + 1;
            uVar9 = uVar9 - 1;
          } while (uVar9 != 0);
        }
        ppvVar8 = *(void ***)(this + 8);
        uVar9 = (uint)((int)ppvVar4 + (3 - (int)param_1)) >> 2;
        ppvVar2 = param_1;
        if (param_1 < ppvVar4) {
          do {
            ppvVar4 = ppvVar4 + -1;
            ppvVar8 = ppvVar8 + -1;
            *ppvVar8 = *ppvVar4;
            uVar9 = uVar9 - 1;
          } while (uVar9 != 0);
        }
        for (; ppvVar2 != ppvVar3; ppvVar2 = ppvVar2 + 1) {
        }
        *(ulong *)(this + 8) = *(int *)(this + 8) + param_2 * 4;
      }
      else {
        uVar9 = (uint)((int)ppvVar8 + (3 - (int)param_1)) >> 2;
        ppvVar4 = param_1;
        if (param_1 < ppvVar8) {
          do {
            *ppvVar3 = *ppvVar4;
            ppvVar3 = ppvVar3 + 1;
            ppvVar4 = ppvVar4 + 1;
            uVar9 = uVar9 - 1;
          } while (uVar9 != 0);
        }
        for (ppvVar3 = param_1; ppvVar3 != *(void ***)(this + 8); ppvVar3 = ppvVar3 + 1) {
        }
        *(ulong *)(this + 8) = *(int *)(this + 8) + param_2 * 4;
      }
    }
  }
  return param_1;
}


/* __thiscall TVector<void *,TAllocator<void *>>::insert(void * *,
                                                                           void const * &) */

int __thiscall
TVector<void*,TAllocator<void*>>::insert
          (TVector_void__JGadget__TAllocator_void___ *this,void **param_1,void **param_2)

{
  uint uVar1;
  
  uVar1 = (int)param_1 - *(int *)(this + 4);
  insert(this,param_1,1,param_2);
  return *(int *)(this + 4) + (((int)uVar1 >> 2) + (uint)((int)uVar1 < 0 && (uVar1 & 3) != 0)) * 4;
}

