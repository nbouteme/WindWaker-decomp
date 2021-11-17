#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <JKernel/JKRHeap.h>
#include <__partial_array_destructor.h>


namespace Runtime.PPCEABI.H {

void __destroy_new_array(int param_1,code *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_1 != 0) {
    if (param_2 != (code *)0x0) {
      iVar2 = *(int *)(param_1 + -0x10);
      uVar3 = *(uint *)(param_1 + -0xc);
      iVar1 = param_1 + iVar2 * uVar3;
      for (uVar4 = 0; uVar4 < uVar3; uVar4 = uVar4 + 1) {
        iVar1 = iVar1 - iVar2;
        (*param_2)(iVar1,0xffffffff);
      }
    }
    JKernel::operator_delete__(param_1 + -0x10);
  }
  return;
}


void __destroy_arr(int param_1,code *param_2,int param_3,int param_4)

{
  param_1 = param_1 + param_3 * param_4;
  for (; param_4 != 0; param_4 = param_4 + -1) {
    param_1 = param_1 - param_3;
    (*param_2)(param_1,0xffffffff);
  }
  return;
}


void __construct_array
               (void *param_1,undefined *constructor,undefined *destructor,int elementSize,
               uint numElements)

{
  void *pvVar1;
  uint local_18;
  
  pvVar1 = param_1;
  for (local_18 = 0; local_18 < numElements; local_18 = local_18 + 1) {
    (*(code *)constructor)(pvVar1,1);
    pvVar1 = (void *)((int)pvVar1 + elementSize);
  }
  if ((local_18 < numElements) && (destructor != (undefined *)0x0)) {
    pvVar1 = (void *)((int)param_1 + elementSize * local_18);
    for (; local_18 != 0; local_18 = local_18 - 1) {
      pvVar1 = (void *)((int)pvVar1 - elementSize);
      (*(code *)destructor)(pvVar1,0xffffffff);
    }
  }
  return;
}

}

/* __thiscall __partial_array_destructor::~__partial_array_destructor(void) */

void __thiscall
__partial_array_destructor::___partial_array_destructor(__partial_array_destructor *this)

{
  short in_r4;
  int iVar1;
  
  if (this != (__partial_array_destructor *)0x0) {
    if ((*(uint *)(this + 0x10) < *(uint *)(this + 8)) && (*(int *)(this + 0xc) != 0)) {
      iVar1 = *(int *)this + *(int *)(this + 4) * *(uint *)(this + 0x10);
      while (*(int *)(this + 0x10) != 0) {
        iVar1 = iVar1 - *(int *)(this + 4);
        (**(code **)(this + 0xc))(iVar1,0xffffffff);
        *(int *)(this + 0x10) = *(int *)(this + 0x10) + -1;
      }
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


namespace Runtime.PPCEABI.H {

int * __construct_new_array
                (int *param_1,code *param_2,code *param_3,int param_4,uint param_5)

{
  int *piVar1;
  uint local_28;
  
  if (param_1 != (int *)0x0) {
    *param_1 = param_4;
    param_1[1] = param_5;
    param_1 = param_1 + 4;
    if (param_2 != (code *)0x0) {
      piVar1 = param_1;
      for (local_28 = 0; local_28 < param_5; local_28 = local_28 + 1) {
        (*param_2)(piVar1,1);
        piVar1 = (int *)((int)piVar1 + param_4);
      }
      if ((local_28 < param_5) && (param_3 != (code *)0x0)) {
        piVar1 = (int *)((int)param_1 + param_4 * local_28);
        for (; local_28 != 0; local_28 = local_28 - 1) {
          piVar1 = (int *)((int)piVar1 - param_4);
          (*param_3)(piVar1,0xffffffff);
        }
      }
    }
  }
  return param_1;
}

