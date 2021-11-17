#include <JStudio/functionvalue.h>
#include <JStudio/functionvalue.h>
#include <JKernel/JKRHeap.h>
#include <JGadget/std-vector.h>
#include <MSL_C.PPCEABI.bare.H/w_fmod.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <MSL_C.PPCEABI.bare.H/s_floor.h>
#include <MSL_C.PPCEABI.bare.H/arith.h>
#include <JStudio/TFunctionValue_composite.h>
#include <std.h>
#include <JStudio/TFunctionValue_constant.h>
#include <JStudio/TFunctionValue_hermite.h>
#include <JStudio/TFunctionValue.h>
#include <JStudio/TFunctionValueAttribute_refer.h>
#include <JStudio/TFunctionValue_list_parameter.h>
#include <JStudio/TFunctionValue_list.h>
#include <JStudio/functionvalue.h>
#include <JStudio/TFunctionValue_transition.h>
#include <JGadget.h>
#include <JStudio/TFunctionValueAttribute_range.h>


namespace JStudio {

/* __thiscall TFunctionValue::toFunction_outside(int) */

undefined * __thiscall TFunctionValue::toFunction_outside(TFunctionValue *this,int param_1)

{
  undefined *puVar1;
  undefined **ppuVar2;
  undefined *local_8 [2];
  
  local_8[0] = (undefined *)0x0;
  ppuVar2 = local_8;
  if (this < (TFunctionValue *)&DAT_00000004) {
    ppuVar2 = &@unnamed@functionvalue_cpp@::gapfnExtrapolateParameter_ + (int)this;
  }
  puVar1 = *ppuVar2;
  if (*ppuVar2 == (undefined *)0x0) {
    puVar1 = @unnamed@functionvalue_cpp@::gapfnExtrapolateParameter_;
  }
  return puVar1;
}


/* __thiscall TFunctionValue::TFunctionValue(void) */

void __thiscall TFunctionValue::TFunctionValue(TFunctionValue *this)

{
  *(undefined1 **)this = &__vt;
  return;
}


/* __thiscall TFunctionValue::~TFunctionValue(void) */

void __thiscall TFunctionValue::_TFunctionValue(TFunctionValue *this)

{
  short in_r4;
  
  if ((this != (TFunctionValue *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall TFunctionValueAttribute_refer::refer_initialize(void) */

void __thiscall
TFunctionValueAttribute_refer::refer_initialize(TFunctionValueAttribute_refer *this)

{
  ::JGadget::TVector_pointer_void::erase
            ((TVector_pointer_void *)this,*(void ***)(this + 4),*(void ***)(this + 8));
  return;
}


/* __thiscall functionvalue::interpolateValue_hermite(double,
                                                               double,
                                                               double,
                                                               double,
                                                               double,
                                                               double,
                                                               double) */

double __thiscall
functionvalue::interpolateValue_hermite
          (functionvalue *this,double param_1,double param_2,double param_3,double param_4,
          double param_5,double param_6,double param_7)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  
  dVar2 = param_1 - param_2;
  dVar1 = dVar2 * (_765 / (param_5 - param_2));
  dVar3 = dVar1 - _765;
  dVar4 = (_766 + _767 * dVar1) * dVar1 * dVar1;
  return dVar1 * dVar3 * dVar2 * param_7 +
         dVar2 * dVar3 * dVar3 * param_4 + (_765 - dVar4) * param_3 + dVar4 * param_6;
}


/* __thiscall functionvalue::interpolateValue_BSpline_uniform(double,
                                                                       double,
                                                                       double,
                                                                       double,
                                                                       double) */

double __thiscall
functionvalue::interpolateValue_BSpline_uniform
          (functionvalue *this,double param_1,double param_2,double param_3,double param_4,
          double param_5)

{
  double dVar1;
  double dVar2;
  double dVar3;
  
  dVar1 = _765 - param_1;
  dVar2 = param_1 * param_1;
  dVar3 = dVar2 * param_1;
  return (_772 + _773 * ((param_1 + dVar2) - dVar3)) * param_4 +
         (_774 + (_773 * dVar3 - dVar2)) * param_3 +
         _772 * (dVar1 * dVar1 * dVar1 * param_2 + dVar3 * param_5);
}


/* __thiscall functionvalue::interpolateValue_BSpline_nonuniform(double,
                                                                          double const *,
                                                                          double const *) */

double __thiscall
functionvalue::interpolateValue_BSpline_nonuniform
          (functionvalue *this,double param_1,double *param_2,double *param_3)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  
  dVar2 = param_2[1];
  dVar3 = param_2[2];
  dVar4 = param_2[3];
  dVar5 = param_2[4];
  dVar6 = param_1 - dVar3;
  dVar1 = dVar4 - param_1;
  dVar7 = _765 / (dVar4 - dVar3);
  dVar9 = (dVar1 * dVar7) / (dVar4 - dVar2);
  dVar8 = (dVar6 * dVar7) / (dVar5 - dVar3);
  dVar4 = (dVar1 * dVar9) / (dVar4 - *param_2);
  dVar7 = ((param_1 - dVar2) * dVar9 + (dVar5 - param_1) * dVar8) / (dVar5 - dVar2);
  dVar3 = (dVar6 * dVar8) / (param_2[5] - dVar3);
  return dVar6 * dVar3 * *(double *)(this + 0x18) +
         ((param_1 - dVar2) * dVar7 + (param_2[5] - param_1) * dVar3) * *(double *)(this + 0x10) +
         dVar1 * dVar4 * *(double *)this +
         ((param_1 - *param_2) * dVar4 + (dVar5 - param_1) * dVar7) * *(double *)(this + 8);
}


/* __thiscall functionvalue::extrapolateParameter_turn(double,
                                                                double) */

double __thiscall
functionvalue::extrapolateParameter_turn(functionvalue *this,double param_1,double param_2)

{
  double dVar1;
  double __y;
  
  __y = _815 * param_2;
  dVar1 = MSL_C.PPCEABI.bare.H::fmod(param_1,__y);
  if (dVar1 < _625) {
    dVar1 = dVar1 + __y;
  }
  if (param_2 <= dVar1) {
    dVar1 = __y - dVar1;
  }
  return dVar1;
}


/* __thiscall TFunctionValueAttribute_range::range_initialize(void) */

void __thiscall
TFunctionValueAttribute_range::range_initialize(TFunctionValueAttribute_range *this)

{
  *(double *)this = (double)MSL_C.PPCEABI.bare.H::__float_nan;
  *(undefined8 *)(this + 8) = *(undefined8 *)this;
  *(undefined8 *)(this + 0x10) = *(undefined8 *)this;
  this[0x18] = (TFunctionValueAttribute_range)0x0;
  this[0x19] = (TFunctionValueAttribute_range)0x0;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  return;
}


/* __thiscall TFunctionValueAttribute_range::range_prepare(void) */

void __thiscall
TFunctionValueAttribute_range::range_prepare(TFunctionValueAttribute_range *this)

{
  TFunctionValueAttribute_range TVar1;
  
  TVar1 = this[0x18];
  if (TVar1 == (TFunctionValueAttribute_range)0x2) {
    *(undefined8 *)(this + 0x20) = *(undefined8 *)this;
    *(double *)(this + 0x28) = _840;
    return;
  }
  if ((char)TVar1 < '\x02') {
    if ((TVar1 != (TFunctionValueAttribute_range)0x0) && (-1 < (char)TVar1)) {
      *(double *)(this + 0x20) = _625;
      *(double *)(this + 0x28) = _840;
      return;
    }
  }
  else {
    if (TVar1 == (TFunctionValueAttribute_range)0x4) {
      *(double *)(this + 0x20) = _773 * (*(double *)this + *(double *)(this + 8));
      *(double *)(this + 0x28) = _840;
      return;
    }
    if ((char)TVar1 < '\x04') {
      *(undefined8 *)(this + 0x20) = *(undefined8 *)(this + 8);
      *(double *)(this + 0x28) = _840;
      return;
    }
  }
  *(double *)(this + 0x20) = _625;
  *(double *)(this + 0x28) = _765;
  return;
}


/* __thiscall TFunctionValueAttribute_range::range_set(double,
                                                                double) */

void __thiscall
TFunctionValueAttribute_range::range_set
          (TFunctionValueAttribute_range *this,double param_1,double param_2)

{
  *(double *)this = param_1;
  *(double *)(this + 8) = param_2;
  *(double *)(this + 0x10) = param_2 - param_1;
  return;
}


/* WARNING: Inlined function: FUN_80328ea8 */
/* WARNING: Inlined function: FUN_80328ef4 */
/* __thiscall TFunctionValueAttribute_range::range_getParameter(double,
                                                                         double,
                                                                         double) const */

double __thiscall
TFunctionValueAttribute_range::range_getParameter
          (TFunctionValueAttribute_range *this,double param_1,double param_2,double param_3)

{
  TFunctionValueAttribute_range TVar1;
  code *pcVar2;
  int in_r4;
  double dVar3;
  
  dVar3 = *(double *)(this + 0x20) + *(double *)(this + 0x28) * (param_1 - *(double *)(this + 0x20))
  ;
  TVar1 = this[0x19];
  if (TVar1 == (TFunctionValueAttribute_range)0x2) {
    dVar3 = (dVar3 + *(double *)(this + 8)) - *(double *)this;
    if (_625 <= dVar3) {
      if (*(double *)(this + 0x10) <= dVar3) {
        pcVar2 = (code *)TFunctionValue::toFunction_outside(*(TFunctionValue **)(this + 0x34),in_r4)
        ;
        dVar3 = (double)(*pcVar2)(dVar3,*(undefined8 *)(this + 0x10));
      }
    }
    else {
      pcVar2 = (code *)TFunctionValue::toFunction_outside(*(TFunctionValue **)(this + 0x30),in_r4);
      dVar3 = (double)(*pcVar2)(dVar3,*(undefined8 *)(this + 0x10));
    }
    return dVar3 + *(double *)this;
  }
  if ((char)TVar1 < '\x02') {
    if ((TVar1 != (TFunctionValueAttribute_range)0x0) && (-1 < (char)TVar1)) {
      dVar3 = (dVar3 + *(double *)this) - *(double *)this;
      if (_625 <= dVar3) {
        if (*(double *)(this + 0x10) <= dVar3) {
          pcVar2 = (code *)TFunctionValue::toFunction_outside
                                     (*(TFunctionValue **)(this + 0x34),in_r4);
          dVar3 = (double)(*pcVar2)(dVar3,*(undefined8 *)(this + 0x10));
        }
      }
      else {
        pcVar2 = (code *)TFunctionValue::toFunction_outside(*(TFunctionValue **)(this + 0x30),in_r4)
        ;
        dVar3 = (double)(*pcVar2)(dVar3,*(undefined8 *)(this + 0x10));
      }
      return dVar3 + *(double *)this;
    }
  }
  else {
    if (TVar1 == (TFunctionValueAttribute_range)0x4) {
      dVar3 = dVar3 - *(double *)this;
      if (_625 <= dVar3) {
        if (*(double *)(this + 0x10) <= dVar3) {
          pcVar2 = (code *)TFunctionValue::toFunction_outside
                                     (*(TFunctionValue **)(this + 0x34),in_r4);
          dVar3 = (double)(*pcVar2)(dVar3,*(undefined8 *)(this + 0x10));
        }
      }
      else {
        pcVar2 = (code *)TFunctionValue::toFunction_outside(*(TFunctionValue **)(this + 0x30),in_r4)
        ;
        dVar3 = (double)(*pcVar2)(dVar3,*(undefined8 *)(this + 0x10));
      }
      return param_2 + (((dVar3 + *(double *)this) - *(double *)this) * (param_3 - param_2)) /
                       *(double *)(this + 0x10);
    }
    if ((char)TVar1 < '\x04') {
      dVar3 = (dVar3 + _773 * (*(double *)this + *(double *)(this + 8))) - *(double *)this;
      if (_625 <= dVar3) {
        if (*(double *)(this + 0x10) <= dVar3) {
          pcVar2 = (code *)TFunctionValue::toFunction_outside
                                     (*(TFunctionValue **)(this + 0x34),in_r4);
          dVar3 = (double)(*pcVar2)(dVar3,*(undefined8 *)(this + 0x10));
        }
      }
      else {
        pcVar2 = (code *)TFunctionValue::toFunction_outside(*(TFunctionValue **)(this + 0x30),in_r4)
        ;
        dVar3 = (double)(*pcVar2)(dVar3,*(undefined8 *)(this + 0x10));
      }
      return dVar3 + *(double *)this;
    }
  }
  dVar3 = dVar3 - *(double *)this;
  if (_625 <= dVar3) {
    if (*(double *)(this + 0x10) <= dVar3) {
      pcVar2 = (code *)TFunctionValue::toFunction_outside(*(TFunctionValue **)(this + 0x34),in_r4);
      dVar3 = (double)(*pcVar2)(dVar3,*(undefined8 *)(this + 0x10));
    }
  }
  else {
    pcVar2 = (code *)TFunctionValue::toFunction_outside(*(TFunctionValue **)(this + 0x30),in_r4);
    dVar3 = (double)(*pcVar2)(dVar3,*(undefined8 *)(this + 0x10));
  }
  return dVar3 + *(double *)this;
}


/* __thiscall TFunctionValueAttribute_range::TFunctionValueAttribute_range(void) */

void __thiscall
TFunctionValueAttribute_range::TFunctionValueAttribute_range
          (TFunctionValueAttribute_range *this)

{
  *(double *)this = (double)MSL_C.PPCEABI.bare.H::__float_nan;
  *(undefined8 *)(this + 8) = *(undefined8 *)this;
  *(undefined8 *)(this + 0x10) = *(undefined8 *)this;
  this[0x18] = (TFunctionValueAttribute_range)0x0;
  this[0x19] = (TFunctionValueAttribute_range)0x0;
  *(undefined8 *)(this + 0x20) = *(undefined8 *)this;
  *(undefined8 *)(this + 0x28) = *(undefined8 *)this;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  return;
}


/* __thiscall TFunctionValue_composite::TFunctionValue_composite(void) */

void __thiscall
TFunctionValue_composite::TFunctionValue_composite(TFunctionValue_composite *this)

{
  TAllocator local_18 [20];
  
  TFunctionValue::TFunctionValue((TFunctionValue *)this);
  local_18[0] = _564;
  ::JGadget::TVector_pointer_void::TVector_pointer_void((TVector_pointer_void *)(this + 4),local_18)
  ;
  *(undefined1 **)this = &__vt;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  return;
}


/* __thiscall TFunctionValue_composite::getType(void) const */

undefined4 __thiscall TFunctionValue_composite::getType(TFunctionValue_composite *this)

{
  return 1;
}


/* __thiscall TFunctionValue_composite::getAttributeSet(void) */

void __thiscall TFunctionValue_composite::getAttributeSet(TFunctionValue_composite *this)

{
  int in_r4;
  
  if (in_r4 != 0) {
    in_r4 = in_r4 + 4;
  }
  *(int *)this = in_r4;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  return;
}


/* __thiscall TFunctionValue_composite::initialize(void) */

void __thiscall TFunctionValue_composite::initialize(TFunctionValue_composite *this)

{
  uint uStack20;
  
  TFunctionValueAttribute_refer::refer_initialize((TFunctionValueAttribute_refer *)(this + 4));
  *(undefined4 *)(this + 0x18) = 0;
  *(ulonglong *)(this + 0x20) = (ulonglong)uStack20;
  return;
}


/* __thiscall TFunctionValue_composite::prepare(void) */

void __thiscall TFunctionValue_composite::prepare(TFunctionValue_composite *this)

{
  return;
}


/* __thiscall TFunctionValue_composite::getValue(double) */

void __thiscall
TFunctionValue_composite::getValue(TFunctionValue_composite *this,double param_1)

{
  (**(code **)(this + 0x18))(this + 4,this + 0x20);
  return;
}


/* __thiscall
   TFunctionValue_composite::composite_raw(JGadget::TVector_pointer<TFunctionValue
   *> const &,
                                                               
   TFunctionValue_composite::TData const &,
                                                               double) */

double __thiscall
TFunctionValue_composite::composite_raw
          (TFunctionValue_composite *this,TVector_pointer *param_1,TData *param_2,double param_3)

{
  uint uVar1;
  int iVar2;
  double dVar3;
  
  iVar2 = *(int *)(this + 4);
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(int *)(this + 8) - iVar2;
    uVar1 = ((int)uVar1 >> 2) + (uint)((int)uVar1 < 0 && (uVar1 & 3) != 0);
  }
  dVar3 = _625;
  if (*(uint *)param_1 < uVar1) {
    dVar3 = (double)(**(code **)(**(int **)(iVar2 + *(uint *)param_1 * 4) + 0x1c))();
  }
  return dVar3;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall
   TFunctionValue_composite::composite_index(JGadget::TVector_pointer<TFunctionValue
   *> const &,
                                                                 
   TFunctionValue_composite::TData const &,
                                                                 double) */

double __thiscall
TFunctionValue_composite::composite_index
          (TFunctionValue_composite *this,TVector_pointer *param_1,TData *param_2,double param_3)

{
  uint uVar1;
  int iVar2;
  int __numer;
  int **ppiVar3;
  int iVar4;
  double dVar5;
  div_t dVar6;
  
  ppiVar3 = *(int ***)(this + 4);
  if (ppiVar3 == (int **)0x0) {
    iVar4 = 0;
  }
  else {
    uVar1 = *(int *)(this + 8) - (int)ppiVar3;
    iVar4 = ((int)uVar1 >> 2) + (uint)((int)uVar1 < 0 && (uVar1 & 3) != 0);
  }
  dVar5 = _625;
  if (1 < iVar4) {
    dVar5 = (double)(**(code **)(**ppiVar3 + 0x1c))(param_3);
    dVar5 = MSL_C.PPCEABI.bare.H::floor(dVar5);
    __numer = (int)dVar5;
    iVar2 = *(int *)param_1;
    if (iVar2 == 2) {
      if (iVar4 == 2) {
        __numer = 0;
      }
      else {
        iVar2 = (iVar4 + -2) * 2;
        dVar6 = MSL_C.PPCEABI.bare.H::div(__numer,iVar2);
        __numer = SUB84(dVar6,0);
        if (__numer < 0) {
          __numer = __numer + iVar2;
        }
        if (iVar4 + -1 <= __numer) {
          __numer = iVar2 - __numer;
        }
      }
    }
    else {
      if (((iVar2 < 2) && (iVar2 != 0)) && (-1 < iVar2)) {
        dVar6 = MSL_C.PPCEABI.bare.H::div(__numer,iVar4 + -1);
        __numer = SUB84(dVar6,0);
        if (__numer < 0) {
          __numer = iVar4 + __numer + -1;
        }
      }
      else {
        if (__numer < 0) {
          __numer = 0;
        }
        else {
          if (iVar4 + -1 <= __numer) {
            __numer = iVar4 + -2;
          }
        }
      }
    }
    dVar5 = (double)(**(code **)(*ppiVar3[__numer + 1] + 0x1c))(param_3);
  }
  return dVar5;
}


/* __thiscall
   TFunctionValue_composite::composite_parameter(JGadget::TVector_pointer<TFunctionValue
   *> const &,
                                                                     
   TFunctionValue_composite::TData const &,
                                                                     double) */

void __thiscall
TFunctionValue_composite::composite_parameter
          (TFunctionValue_composite *this,TVector_pointer *param_1,TData *param_2,double param_3)

{
  int **ppiVar1;
  double dVar2;
  int **local_18;
  
  dVar2 = param_3 - *(double *)param_1;
  ppiVar1 = *(int ***)(this + 8);
  local_18 = *(int ***)(this + 4);
  while (local_18 != ppiVar1) {
    dVar2 = (double)(**(code **)(**local_18 + 0x1c))(dVar2);
    local_18 = local_18 + 1;
  }
  return;
}


/* __thiscall
   TFunctionValue_composite::composite_add(JGadget::TVector_pointer<TFunctionValue
   *> const &,
                                                               
   TFunctionValue_composite::TData const &,
                                                               double) */

double __thiscall
TFunctionValue_composite::composite_add
          (TFunctionValue_composite *this,TVector_pointer *param_1,TData *param_2,double param_3)

{
  int **ppiVar1;
  double dVar2;
  double dVar3;
  int **local_28;
  
  dVar3 = *(double *)param_1;
  ppiVar1 = *(int ***)(this + 8);
  local_28 = *(int ***)(this + 4);
  while (local_28 != ppiVar1) {
    dVar2 = (double)(**(code **)(**local_28 + 0x1c))(param_3);
    dVar3 = dVar3 + dVar2;
    local_28 = local_28 + 1;
  }
  return dVar3;
}


/* __thiscall
   TFunctionValue_composite::composite_subtract(JGadget::TVector_pointer<TFunctionValue
   *> const &,
                                                                    
   TFunctionValue_composite::TData const &,
                                                                    double) */

double __thiscall
TFunctionValue_composite::composite_subtract
          (TFunctionValue_composite *this,TVector_pointer *param_1,TData *param_2,double param_3)

{
  int iVar1;
  uint uVar2;
  int **ppiVar3;
  double dVar4;
  double dVar5;
  int **local_28;
  
  local_28 = *(int ***)(this + 4);
  if (local_28 == (int **)0x0) {
    iVar1 = 0;
  }
  else {
    uVar2 = *(int *)(this + 8) - (int)local_28;
    iVar1 = ((int)uVar2 >> 2) + (uint)((int)uVar2 < 0 && (uVar2 & 3) != 0);
  }
  dVar4 = _625;
  if (iVar1 != 0) {
    ppiVar3 = *(int ***)(this + 8);
    dVar4 = (double)(**(code **)(**local_28 + 0x1c))(param_3);
    while (local_28 = local_28 + 1, local_28 != ppiVar3) {
      dVar5 = (double)(**(code **)(**local_28 + 0x1c))(param_3);
      dVar4 = dVar4 - dVar5;
    }
    dVar4 = dVar4 - *(double *)param_1;
  }
  return dVar4;
}


/* __thiscall
   TFunctionValue_composite::composite_multiply(JGadget::TVector_pointer<TFunctionValue
   *> const &,
                                                                    
   TFunctionValue_composite::TData const &,
                                                                    double) */

double __thiscall
TFunctionValue_composite::composite_multiply
          (TFunctionValue_composite *this,TVector_pointer *param_1,TData *param_2,double param_3)

{
  int **ppiVar1;
  double dVar2;
  double dVar3;
  int **local_28;
  
  dVar3 = *(double *)param_1;
  ppiVar1 = *(int ***)(this + 8);
  local_28 = *(int ***)(this + 4);
  while (local_28 != ppiVar1) {
    dVar2 = (double)(**(code **)(**local_28 + 0x1c))(param_3);
    dVar3 = dVar3 * dVar2;
    local_28 = local_28 + 1;
  }
  return dVar3;
}


/* __thiscall
   TFunctionValue_composite::composite_divide(JGadget::TVector_pointer<TFunctionValue
   *> const &,
                                                                  
   TFunctionValue_composite::TData const &,
                                                                  double) */

double __thiscall
TFunctionValue_composite::composite_divide
          (TFunctionValue_composite *this,TVector_pointer *param_1,TData *param_2,double param_3)

{
  int iVar1;
  uint uVar2;
  int **ppiVar3;
  double dVar4;
  double dVar5;
  int **local_28;
  
  local_28 = *(int ***)(this + 4);
  if (local_28 == (int **)0x0) {
    iVar1 = 0;
  }
  else {
    uVar2 = *(int *)(this + 8) - (int)local_28;
    iVar1 = ((int)uVar2 >> 2) + (uint)((int)uVar2 < 0 && (uVar2 & 3) != 0);
  }
  dVar4 = _625;
  if (iVar1 != 0) {
    ppiVar3 = *(int ***)(this + 8);
    dVar4 = (double)(**(code **)(**local_28 + 0x1c))(param_3);
    while (local_28 = local_28 + 1, local_28 != ppiVar3) {
      dVar5 = (double)(**(code **)(**local_28 + 0x1c))(param_3);
      dVar4 = dVar4 / dVar5;
    }
    dVar4 = dVar4 / *(double *)param_1;
  }
  return dVar4;
}


/* __thiscall TFunctionValue_constant::TFunctionValue_constant(void) */

void __thiscall
TFunctionValue_constant::TFunctionValue_constant(TFunctionValue_constant *this)

{
  TFunctionValue::TFunctionValue((TFunctionValue *)this);
  *(undefined1 **)this = &__vt;
  *(double *)(this + 8) = (double)MSL_C.PPCEABI.bare.H::__float_nan;
  return;
}


/* __thiscall TFunctionValue_constant::getType(void) const */

undefined4 __thiscall TFunctionValue_constant::getType(TFunctionValue_constant *this)

{
  return 2;
}


/* __thiscall TFunctionValue_constant::getAttributeSet(void) */

void __thiscall TFunctionValue_constant::getAttributeSet(TFunctionValue_constant *this)

{
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  return;
}


/* __thiscall TFunctionValue_constant::initialize(void) */

void __thiscall TFunctionValue_constant::initialize(TFunctionValue_constant *this)

{
  *(double *)(this + 8) = (double)MSL_C.PPCEABI.bare.H::__float_nan;
  return;
}


/* __thiscall TFunctionValue_constant::prepare(void) */

void __thiscall TFunctionValue_constant::prepare(TFunctionValue_constant *this)

{
  return;
}


/* __thiscall TFunctionValue_constant::getValue(double) */

undefined8 __thiscall
TFunctionValue_constant::getValue(TFunctionValue_constant *this,double param_1)

{
  return *(undefined8 *)(this + 8);
}


/* __thiscall TFunctionValue_transition::TFunctionValue_transition(void) */

void __thiscall
TFunctionValue_transition::TFunctionValue_transition(TFunctionValue_transition *this)

{
  TFunctionValue::TFunctionValue((TFunctionValue *)this);
  TFunctionValueAttribute_range::TFunctionValueAttribute_range
            ((TFunctionValueAttribute_range *)(this + 8));
  *(undefined4 *)(this + 0x40) = 0;
  *(undefined1 **)this = &__vt;
  *(double *)(this + 0x48) = (double)MSL_C.PPCEABI.bare.H::__float_nan;
  *(undefined8 *)(this + 0x50) = *(undefined8 *)(this + 0x48);
  return;
}


/* __thiscall TFunctionValue_transition::getType(void) const */

undefined4 __thiscall TFunctionValue_transition::getType(TFunctionValue_transition *this)

{
  return 3;
}


/* __thiscall TFunctionValue_transition::getAttributeSet(void) */

void __thiscall TFunctionValue_transition::getAttributeSet(TFunctionValue_transition *this)

{
  int in_r4;
  int iVar1;
  
  iVar1 = in_r4;
  if (in_r4 != 0) {
    iVar1 = in_r4 + 0x40;
    in_r4 = in_r4 + 8;
  }
  *(undefined4 *)this = 0;
  *(int *)(this + 4) = in_r4;
  *(int *)(this + 8) = iVar1;
  return;
}


/* __thiscall TFunctionValue_transition::initialize(void) */

void __thiscall TFunctionValue_transition::initialize(TFunctionValue_transition *this)

{
  TFunctionValueAttribute_range::range_initialize((TFunctionValueAttribute_range *)(this + 8));
  *(undefined4 *)(this + 0x40) = 0;
  *(double *)(this + 0x48) = (double)MSL_C.PPCEABI.bare.H::__float_nan;
  *(undefined8 *)(this + 0x50) = *(undefined8 *)(this + 0x48);
  return;
}


/* __thiscall TFunctionValue_transition::prepare(void) */

void __thiscall TFunctionValue_transition::prepare(TFunctionValue_transition *this)

{
  TFunctionValueAttribute_range::range_prepare((TFunctionValueAttribute_range *)(this + 8));
  return;
}


/* __thiscall TFunctionValue_transition::getValue(double) */

double __thiscall
TFunctionValue_transition::getValue(TFunctionValue_transition *this,double param_1)

{
  TFunctionValue_transition TVar1;
  int iVar2;
  code *pcVar3;
  functionvalue *this_00;
  int in_r4;
  double extraout_f1;
  double extraout_f1_00;
  double dVar4;
  double dVar5;
  
  dVar5 = (*(double *)(this + 0x28) +
          *(double *)(this + 0x30) * (param_1 - *(double *)(this + 0x28))) - *(double *)(this + 8);
  if (_625 <= dVar5) {
    this_00 = (functionvalue *)this;
    if (*(double *)(this + 0x18) <= dVar5) {
      pcVar3 = (code *)TFunctionValue::toFunction_outside(*(TFunctionValue **)(this + 0x3c),in_r4);
      this_00 = (functionvalue *)(*pcVar3)(dVar5,*(undefined8 *)(this + 0x18));
      dVar5 = extraout_f1_00;
    }
  }
  else {
    pcVar3 = (code *)TFunctionValue::toFunction_outside(*(TFunctionValue **)(this + 0x38),in_r4);
    this_00 = (functionvalue *)(*pcVar3)(dVar5,*(undefined8 *)(this + 0x18));
    dVar5 = extraout_f1;
  }
  dVar4 = *(double *)(this + 8);
  dVar5 = dVar5 + dVar4;
  TVar1 = this[0x21];
  if (TVar1 == (TFunctionValue_transition)0x3) goto LAB_80271fe4;
  if ((char)TVar1 < '\x03') {
    if ('\x01' < (char)TVar1) {
      if (dVar5 < *(double *)(this + 0x10)) {
        return *(double *)(this + 0x48);
      }
      return *(double *)(this + 0x50);
    }
  }
  else {
    if ((char)TVar1 < '\x05') {
      if (dVar5 < dVar4) {
        return *(double *)(this + 0x48);
      }
      if (*(double *)(this + 0x10) <= dVar5) {
        return *(double *)(this + 0x50);
      }
      iVar2 = *(int *)(this + 0x40);
      if (iVar2 == 2) {
        dVar5 = (double)functionvalue::interpolateValue_hermite
                                  (this_00,dVar5,dVar4,*(double *)(this + 0x48),_625,
                                   *(double *)(this + 0x10),*(double *)(this + 0x50),_625);
        return dVar5;
      }
      if (iVar2 < 2) {
        if ((iVar2 != 0) && (-1 < iVar2)) {
LAB_8027205c:
          return *(double *)(this + 0x48) +
                 ((dVar5 - dVar4) * (*(double *)(this + 0x50) - *(double *)(this + 0x48))) /
                 *(double *)(this + 0x18);
        }
      }
      else {
        if (iVar2 < 4) goto LAB_8027205c;
      }
LAB_80271fe4:
      if (dVar5 < _773 * (dVar4 + *(double *)(this + 0x10))) {
        return *(double *)(this + 0x48);
      }
      return *(double *)(this + 0x50);
    }
  }
  if (dVar4 <= dVar5) {
    dVar5 = *(double *)(this + 0x50);
  }
  else {
    dVar5 = *(double *)(this + 0x48);
  }
  return dVar5;
}


/* __thiscall TFunctionValue_list::TFunctionValue_list(void) */

void __thiscall TFunctionValue_list::TFunctionValue_list(TFunctionValue_list *this)

{
  TFunctionValue::TFunctionValue((TFunctionValue *)this);
  TFunctionValueAttribute_range::TFunctionValueAttribute_range
            ((TFunctionValueAttribute_range *)(this + 8));
  *(undefined4 *)(this + 0x40) = 0;
  *(undefined1 **)this = &__vt;
  *(undefined4 *)(this + 0x44) = 0;
  *(undefined4 *)(this + 0x48) = 0;
  *(double *)(this + 0x50) = (double)MSL_C.PPCEABI.bare.H::__float_nan;
  *(undefined4 *)(this + 0x58) = 0;
  return;
}


/* __thiscall TFunctionValue_list::getType(void) const */

undefined4 __thiscall TFunctionValue_list::getType(TFunctionValue_list *this)

{
  return 4;
}


/* __thiscall TFunctionValue_list::getAttributeSet(void) */

void __thiscall TFunctionValue_list::getAttributeSet(TFunctionValue_list *this)

{
  int in_r4;
  int iVar1;
  
  iVar1 = in_r4;
  if (in_r4 != 0) {
    iVar1 = in_r4 + 0x40;
    in_r4 = in_r4 + 8;
  }
  *(undefined4 *)this = 0;
  *(int *)(this + 4) = in_r4;
  *(int *)(this + 8) = iVar1;
  return;
}


/* __thiscall TFunctionValue_list::initialize(void) */

void __thiscall TFunctionValue_list::initialize(TFunctionValue_list *this)

{
  TFunctionValueAttribute_range::range_initialize((TFunctionValueAttribute_range *)(this + 8));
  *(undefined4 *)(this + 0x40) = 0;
  *(undefined4 *)(this + 0x44) = 0;
  *(undefined4 *)(this + 0x48) = 0;
  *(double *)(this + 0x50) = (double)MSL_C.PPCEABI.bare.H::__float_nan;
  *(undefined4 *)(this + 0x58) = 0;
  return;
}


/* __thiscall TFunctionValue_list::prepare(void) */

void __thiscall TFunctionValue_list::prepare(TFunctionValue_list *this)

{
  int iVar1;
  
  TFunctionValueAttribute_range::range_prepare((TFunctionValueAttribute_range *)(this + 8));
  iVar1 = *(int *)(this + 0x40);
  if (iVar1 == 2) {
    *(code **)(this + 0x58) = update_INTERPOLATE_PLATEAU_;
  }
  else {
    if (iVar1 < 2) {
      if ((iVar1 != 0) && (-1 < iVar1)) {
        *(code **)(this + 0x58) = update_INTERPOLATE_LINEAR_;
        return;
      }
    }
    else {
      if (iVar1 < 4) {
        *(code **)(this + 0x58) = update_INTERPOLATE_BSPLINE_dataMore3_;
        if (*(int *)(this + 0x48) != 2) {
          return;
        }
        *(code **)(this + 0x58) = update_INTERPOLATE_LINEAR_;
        return;
      }
    }
    *(code **)(this + 0x58) = update_INTERPOLATE_NONE_;
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x802725dc) */
/* WARNING: Removing unreachable block (ram,0x802725e4) */
/* __thiscall TFunctionValue_list::getValue(double) */

double __thiscall TFunctionValue_list::getValue(TFunctionValue_list *this,double param_1)

{
  TFunctionValue_list TVar1;
  code *pcVar2;
  int in_r4;
  int iVar3;
  undefined4 uVar4;
  double dVar5;
  undefined8 in_f30;
  undefined8 in_f31;
  double dVar6;
  double local_48;
  double local_40;
  undefined4 local_38;
  undefined4 local_30;
  int iStack44;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  dVar5 = *(double *)(this + 0x28) + *(double *)(this + 0x30) * (param_1 - *(double *)(this + 0x28))
  ;
  iVar3 = *(int *)(this + 0x48) + -1;
  TVar1 = this[0x21];
  local_30 = 0x43300000;
  dVar6 = (double)CONCAT44(0x43300000,iVar3) - _1489;
  iStack44 = iVar3;
  if (TVar1 == (TFunctionValue_list)0x2) {
    dVar5 = (dVar5 + *(double *)(this + 0x10)) - *(double *)(this + 8);
    if (_625 <= dVar5) {
      if (*(double *)(this + 0x18) <= dVar5) {
        pcVar2 = (code *)TFunctionValue::toFunction_outside(*(TFunctionValue **)(this + 0x3c),in_r4)
        ;
        dVar5 = (double)(*pcVar2)(dVar5,*(undefined8 *)(this + 0x18));
      }
    }
    else {
      pcVar2 = (code *)TFunctionValue::toFunction_outside(*(TFunctionValue **)(this + 0x38),in_r4);
      dVar5 = (double)(*pcVar2)(dVar5,*(undefined8 *)(this + 0x18));
    }
    local_48 = (dVar5 + *(double *)(this + 8)) / *(double *)(this + 0x50);
    goto LAB_80272580;
  }
  if ((char)TVar1 < '\x02') {
    if ((TVar1 != (TFunctionValue_list)0x0) && (-1 < (char)TVar1)) {
      dVar5 = (dVar5 + *(double *)(this + 8)) - *(double *)(this + 8);
      if (_625 <= dVar5) {
        if (*(double *)(this + 0x18) <= dVar5) {
          pcVar2 = (code *)TFunctionValue::toFunction_outside
                                     (*(TFunctionValue **)(this + 0x3c),in_r4);
          dVar5 = (double)(*pcVar2)(dVar5,*(undefined8 *)(this + 0x18));
        }
      }
      else {
        pcVar2 = (code *)TFunctionValue::toFunction_outside(*(TFunctionValue **)(this + 0x38),in_r4)
        ;
        dVar5 = (double)(*pcVar2)(dVar5,*(undefined8 *)(this + 0x18));
      }
      local_48 = (dVar5 + *(double *)(this + 8)) / *(double *)(this + 0x50);
      goto LAB_80272580;
    }
  }
  else {
    if (TVar1 == (TFunctionValue_list)0x4) {
      dVar5 = dVar5 - *(double *)(this + 8);
      if (_625 <= dVar5) {
        if (*(double *)(this + 0x18) <= dVar5) {
          pcVar2 = (code *)TFunctionValue::toFunction_outside
                                     (*(TFunctionValue **)(this + 0x3c),in_r4);
          dVar5 = (double)(*pcVar2)(dVar5,*(undefined8 *)(this + 0x18));
        }
      }
      else {
        pcVar2 = (code *)TFunctionValue::toFunction_outside(*(TFunctionValue **)(this + 0x38),in_r4)
        ;
        dVar5 = (double)(*pcVar2)(dVar5,*(undefined8 *)(this + 0x18));
      }
      local_48 = (dVar6 * ((dVar5 + *(double *)(this + 8)) - *(double *)(this + 8))) /
                 *(double *)(this + 0x18);
      goto LAB_80272580;
    }
    if ((char)TVar1 < '\x04') {
      dVar5 = (dVar5 + _773 * (*(double *)(this + 8) + *(double *)(this + 0x10))) -
              *(double *)(this + 8);
      if (_625 <= dVar5) {
        if (*(double *)(this + 0x18) <= dVar5) {
          pcVar2 = (code *)TFunctionValue::toFunction_outside
                                     (*(TFunctionValue **)(this + 0x3c),in_r4);
          dVar5 = (double)(*pcVar2)(dVar5,*(undefined8 *)(this + 0x18));
        }
      }
      else {
        pcVar2 = (code *)TFunctionValue::toFunction_outside(*(TFunctionValue **)(this + 0x38),in_r4)
        ;
        dVar5 = (double)(*pcVar2)(dVar5,*(undefined8 *)(this + 0x18));
      }
      local_48 = (dVar5 + *(double *)(this + 8)) / *(double *)(this + 0x50);
      goto LAB_80272580;
    }
  }
  dVar5 = dVar5 - *(double *)(this + 8);
  if (_625 <= dVar5) {
    if (*(double *)(this + 0x18) <= dVar5) {
      pcVar2 = (code *)TFunctionValue::toFunction_outside(*(TFunctionValue **)(this + 0x3c),in_r4);
      dVar5 = (double)(*pcVar2)(dVar5,*(undefined8 *)(this + 0x18));
    }
  }
  else {
    pcVar2 = (code *)TFunctionValue::toFunction_outside(*(TFunctionValue **)(this + 0x38),in_r4);
    dVar5 = (double)(*pcVar2)(dVar5,*(undefined8 *)(this + 0x18));
  }
  local_48 = (dVar5 + *(double *)(this + 8)) / *(double *)(this + 0x50);
LAB_80272580:
  if (_625 <= local_48) {
    if (local_48 < dVar6) {
      local_40 = MSL_C.PPCEABI.bare.H::floor(local_48);
      local_38 = Runtime.PPCEABI.H::__cvt_fp2unsigned();
      dVar5 = (double)(**(code **)(this + 0x58))(this,&local_48);
    }
    else {
      dVar5 = (double)*(float *)(*(int *)(this + 0x44) + iVar3 * 4);
    }
  }
  else {
    dVar5 = (double)**(float **)(this + 0x44);
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  __psq_l0(auStack24,uVar4);
  __psq_l1(auStack24,uVar4);
  return dVar5;
}


/* __thiscall TFunctionValue_list::update_INTERPOLATE_NONE_(TFunctionValue_list
   const &,
                                                                     
   TFunctionValue_list::TIndexData_ const &) */

double __thiscall
TFunctionValue_list::update_INTERPOLATE_NONE_
          (TFunctionValue_list *this,TFunctionValue_list *param_1,TIndexData_ *param_2)

{
  return (double)*(float *)(*(int *)(this + 0x44) + *(int *)(param_1 + 0x10) * 4);
}


/* __thiscall TFunctionValue_list::update_INTERPOLATE_LINEAR_(TFunctionValue_list
   const &,
                                                                       
   TFunctionValue_list::TIndexData_ const &) */

double __thiscall
TFunctionValue_list::update_INTERPOLATE_LINEAR_
          (TFunctionValue_list *this,TFunctionValue_list *param_1,TIndexData_ *param_2)

{
  double dVar1;
  
  dVar1 = (double)*(float *)(*(int *)(this + 0x44) + *(int *)(param_1 + 0x10) * 4);
  return dVar1 + ((double)*(float *)(*(int *)(this + 0x44) + *(int *)(param_1 + 0x10) * 4 + 4) -
                 dVar1) * (*(double *)param_1 - *(double *)(param_1 + 8));
}


/* __thiscall TFunctionValue_list::update_INTERPOLATE_PLATEAU_(TFunctionValue_list
   const &,
                                                                        
   TFunctionValue_list::TIndexData_ const &) */

void __thiscall
TFunctionValue_list::update_INTERPOLATE_PLATEAU_
          (TFunctionValue_list *this,TFunctionValue_list *param_1,TIndexData_ *param_2)

{
  functionvalue *this_00;
  
  this_00 = (functionvalue *)(*(int *)(this + 0x44) + *(int *)(param_1 + 0x10) * 4);
  functionvalue::interpolateValue_hermite
            (this_00,*(double *)param_1,*(double *)(param_1 + 8),
             (double)*(float *)(*(int *)(this + 0x44) + *(int *)(param_1 + 0x10) * 4),_625,
             _765 + *(double *)(param_1 + 8),(double)*(float *)(this_00 + 4),_625);
  return;
}


/* __thiscall
   TFunctionValue_list::update_INTERPOLATE_BSPLINE_dataMore3_(TFunctionValue_list
   const &,
                                                                                  
   TFunctionValue_list::TIndexData_ const &) */

void __thiscall
TFunctionValue_list::update_INTERPOLATE_BSPLINE_dataMore3_
          (TFunctionValue_list *this,TFunctionValue_list *param_1,TIndexData_ *param_2)

{
  int iVar1;
  functionvalue *pfVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  
  pfVar2 = *(functionvalue **)(param_1 + 0x10);
  dVar4 = (double)*(float *)(*(int *)(this + 0x44) + (int)pfVar2 * 4);
  iVar1 = *(int *)(this + 0x44) + (int)pfVar2 * 4;
  dVar5 = (double)*(float *)(iVar1 + 4);
  if (pfVar2 == (functionvalue *)0x0) {
    dVar3 = _815 * dVar4 - dVar5;
    dVar6 = (double)*(float *)(iVar1 + 8);
  }
  else {
    this = *(TFunctionValue_list **)(this + 0x48);
    if (pfVar2 == (functionvalue *)this + -2) {
      dVar3 = (double)*(float *)(iVar1 + -4);
      dVar6 = _815 * dVar5 - dVar4;
    }
    else {
      dVar3 = (double)*(float *)(iVar1 + -4);
      dVar6 = (double)*(float *)(iVar1 + 8);
    }
  }
  functionvalue::interpolateValue_BSpline_uniform
            ((functionvalue *)this,*(double *)param_1 - *(double *)(param_1 + 8),dVar3,dVar4,dVar5,
             dVar6);
  return;
}


/* __thiscall TFunctionValue_list_parameter::TFunctionValue_list_parameter(void) */

void __thiscall
TFunctionValue_list_parameter::TFunctionValue_list_parameter
          (TFunctionValue_list_parameter *this)

{
  TFunctionValue::TFunctionValue((TFunctionValue *)this);
  TFunctionValueAttribute_range::TFunctionValueAttribute_range
            ((TFunctionValueAttribute_range *)(this + 8));
  *(undefined4 *)(this + 0x40) = 0;
  *(undefined1 **)this = &__vt;
  *(undefined4 *)(this + 0x44) = 0;
  *(undefined4 *)(this + 0x48) = 0;
  *(undefined4 *)(this + 0x4c) = 0;
  *(undefined4 *)(this + 0x50) = *(undefined4 *)(this + 0x4c);
  *(undefined4 *)(this + 0x54) = *(undefined4 *)(this + 0x4c);
  *(undefined4 *)(this + 0x58) = 0;
  return;
}


/* __thiscall TFunctionValue_list_parameter::getType(void) const */

undefined4 __thiscall
TFunctionValue_list_parameter::getType(TFunctionValue_list_parameter *this)

{
  return 5;
}


/* __thiscall TFunctionValue_list_parameter::getAttributeSet(void) */

void __thiscall
TFunctionValue_list_parameter::getAttributeSet(TFunctionValue_list_parameter *this)

{
  int in_r4;
  int iVar1;
  
  iVar1 = in_r4;
  if (in_r4 != 0) {
    iVar1 = in_r4 + 0x40;
    in_r4 = in_r4 + 8;
  }
  *(undefined4 *)this = 0;
  *(int *)(this + 4) = in_r4;
  *(int *)(this + 8) = iVar1;
  return;
}


/* __thiscall TFunctionValue_list_parameter::data_set(float const *,
                                                               unsigned long) */

void __thiscall
TFunctionValue_list_parameter::data_set
          (TFunctionValue_list_parameter *this,float *param_1,ulong param_2)

{
  *(float **)(this + 0x44) = param_1;
  *(ulong *)(this + 0x48) = param_2;
  *(undefined4 *)(this + 0x4c) = *(undefined4 *)(this + 0x44);
  *(int *)(this + 0x50) = *(int *)(this + 0x44) + *(int *)(this + 0x48) * 8;
  *(undefined4 *)(this + 0x54) = *(undefined4 *)(this + 0x4c);
  return;
}


/* __thiscall TFunctionValue_list_parameter::initialize(void) */

void __thiscall
TFunctionValue_list_parameter::initialize(TFunctionValue_list_parameter *this)

{
  TFunctionValueAttribute_range::range_initialize((TFunctionValueAttribute_range *)(this + 8));
  *(undefined4 *)(this + 0x40) = 0;
  *(undefined4 *)(this + 0x44) = 0;
  *(undefined4 *)(this + 0x48) = 0;
  *(undefined4 *)(this + 0x4c) = 0;
  *(undefined4 *)(this + 0x50) = *(undefined4 *)(this + 0x4c);
  *(undefined4 *)(this + 0x54) = *(undefined4 *)(this + 0x4c);
  *(undefined4 *)(this + 0x58) = 0;
  return;
}


/* __thiscall TFunctionValue_list_parameter::prepare(void) */

void __thiscall TFunctionValue_list_parameter::prepare(TFunctionValue_list_parameter *this)

{
  int iVar1;
  
  TFunctionValueAttribute_range::range_prepare((TFunctionValueAttribute_range *)(this + 8));
  iVar1 = *(int *)(this + 0x40);
  if (iVar1 == 2) {
    *(code **)(this + 0x58) = update_INTERPOLATE_PLATEAU_;
  }
  else {
    if (iVar1 < 2) {
      if ((iVar1 != 0) && (-1 < iVar1)) {
        *(code **)(this + 0x58) = update_INTERPOLATE_LINEAR_;
        return;
      }
    }
    else {
      if (iVar1 < 4) {
        *(code **)(this + 0x58) = update_INTERPOLATE_BSPLINE_dataMore3_;
        if (*(int *)(this + 0x48) != 2) {
          return;
        }
        *(code **)(this + 0x58) = update_INTERPOLATE_LINEAR_;
        return;
      }
    }
    *(code **)(this + 0x58) = update_INTERPOLATE_NONE_;
  }
  return;
}


/* __thiscall TFunctionValue_list_parameter::getValue(double) */

double __thiscall
TFunctionValue_list_parameter::getValue(TFunctionValue_list_parameter *this,double param_1)

{
  int iVar1;
  double dVar2;
  double local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14 [4];
  
  local_28 = param_1;
  local_28 = (double)TFunctionValueAttribute_range::range_getParameter
                               ((TFunctionValueAttribute_range *)(this + 8),param_1,
                                (double)**(float **)(this + 0x44),
                                (double)(*(float **)(this + 0x44))[(*(int *)(this + 0x48) + -1) * 2]
                               );
  local_20 = *(undefined4 *)(this + 0x54);
  local_1c = *(undefined4 *)(this + 0x50);
  local_18 = *(undefined4 *)(this + 0x4c);
  ::JGadget::findUpperBound_binary_current
            ((JGadget *)local_14,(TIterator_data_)&local_18,(TIterator_data_)&local_1c,
             (TIterator_data_)&local_20,&local_28);
  *(undefined4 *)(this + 0x54) = local_14[0];
  iVar1 = *(int *)(this + 0x54);
  if (iVar1 == *(int *)(this + 0x4c)) {
    dVar2 = (double)*(float *)(iVar1 + 4);
  }
  else {
    if (iVar1 == *(int *)(this + 0x50)) {
      *(int *)(this + 0x54) = *(int *)(this + 0x54) + -8;
      dVar2 = (double)*(float *)(*(int *)(this + 0x54) + 4);
    }
    else {
      dVar2 = (double)(**(code **)(this + 0x58))(local_28,this);
    }
  }
  return dVar2;
}


/* __thiscall
   TFunctionValue_list_parameter::update_INTERPOLATE_NONE_(TFunctionValue_list_parameter
   const &,
                                                                               double) */

double __thiscall
TFunctionValue_list_parameter::update_INTERPOLATE_NONE_
          (TFunctionValue_list_parameter *this,TFunctionValue_list_parameter *param_1,double param_2
          )

{
  return (double)*(float *)(*(int *)(this + 0x54) + -4);
}


/* __thiscall
   TFunctionValue_list_parameter::update_INTERPOLATE_LINEAR_(TFunctionValue_list_parameter
   const &,
                                                                                 double) */

double __thiscall
TFunctionValue_list_parameter::update_INTERPOLATE_LINEAR_
          (TFunctionValue_list_parameter *this,TFunctionValue_list_parameter *param_1,double param_2
          )

{
  float *pfVar1;
  
  pfVar1 = *(float **)(this + 0x54);
  return (double)pfVar1[-1] +
         (((double)pfVar1[1] - (double)pfVar1[-1]) * (param_2 - (double)pfVar1[-2])) /
         ((double)*pfVar1 - (double)pfVar1[-2]);
}


/* __thiscall
   TFunctionValue_list_parameter::update_INTERPOLATE_PLATEAU_(TFunctionValue_list_parameter
   const &,
                                                                                  double) */

void __thiscall
TFunctionValue_list_parameter::update_INTERPOLATE_PLATEAU_
          (TFunctionValue_list_parameter *this,TFunctionValue_list_parameter *param_1,double param_2
          )

{
  float *this_00;
  
  this_00 = *(float **)(this + 0x54);
  functionvalue::interpolateValue_hermite
            ((functionvalue *)this_00,param_2,(double)this_00[-2],(double)this_00[-1],_625,
             (double)*this_00,(double)this_00[1],_625);
  return;
}


/* __thiscall
   TFunctionValue_list_parameter::update_INTERPOLATE_BSPLINE_dataMore3_(TFunctionValue_list_parameter
   const &,
                                                                                            double)
    */

void __thiscall
TFunctionValue_list_parameter::update_INTERPOLATE_BSPLINE_dataMore3_
          (TFunctionValue_list_parameter *this,TFunctionValue_list_parameter *param_1,double param_2
          )

{
  uint uVar1;
  int iVar2;
  float *pfVar3;
  double *pdVar4;
  double local_58;
  double local_50;
  double local_48;
  double local_40;
  double local_38;
  double local_30;
  double local_28;
  double local_20;
  double local_18;
  double local_10;
  
  pfVar3 = *(float **)(this + 0x54);
  local_50 = (double)pfVar3[-1];
  local_48 = (double)pfVar3[1];
  local_28 = (double)pfVar3[-2];
  local_20 = (double)*pfVar3;
  uVar1 = *(int *)(this + 0x50) - (int)pfVar3;
  pdVar4 = (double *)(((int)uVar1 >> 2) + (uint)((int)uVar1 < 0 && (uVar1 & 3) != 0));
  uVar1 = (int)pfVar3 - *(int *)(this + 0x4c);
  iVar2 = ((int)uVar1 >> 2) + (uint)((int)uVar1 < 0 && (uVar1 & 3) != 0);
  if (iVar2 != 3) {
    if (iVar2 < 3) {
      if (1 < iVar2) {
        local_58 = _815 * local_50 - local_48;
        local_40 = (double)pfVar3[3];
        local_18 = (double)pfVar3[2];
        local_30 = _815 * local_28 - local_20;
        local_38 = _815 * local_28 - local_18;
        if (pdVar4 != (double *)&DAT_00000003) {
          if ((int)pdVar4 < 3) {
            if (1 < (int)pdVar4) {
LAB_80272b1c:
              local_10 = _815 * local_18 - local_20;
              goto LAB_80272c9c;
            }
          }
          else {
            if ((int)pdVar4 < 5) goto LAB_80272b1c;
          }
        }
        local_10 = (double)pfVar3[4];
        goto LAB_80272c9c;
      }
    }
    else {
      if (iVar2 < 5) {
        local_58 = (double)pfVar3[-3];
        local_30 = (double)pfVar3[-4];
        local_38 = _815 * local_30 - local_28;
        if (pdVar4 != (double *)&DAT_00000003) {
          if ((int)pdVar4 < 3) {
            if (1 < (int)pdVar4) {
              local_40 = _815 * local_48 - local_50;
              local_18 = _815 * local_20 - local_28;
              local_10 = _815 * local_20 - local_30;
              goto LAB_80272c9c;
            }
          }
          else {
            if ((int)pdVar4 < 5) {
              local_40 = (double)pfVar3[3];
              local_18 = (double)pfVar3[2];
              local_10 = _815 * local_18 - local_20;
              goto LAB_80272c9c;
            }
          }
        }
        local_40 = (double)pfVar3[3];
        local_18 = (double)pfVar3[2];
        local_10 = (double)pfVar3[4];
        goto LAB_80272c9c;
      }
    }
  }
  local_58 = (double)pfVar3[-3];
  local_30 = (double)pfVar3[-4];
  local_38 = (double)pfVar3[-6];
  if (pdVar4 != (double *)&DAT_00000003) {
    if ((int)pdVar4 < 3) {
      if (1 < (int)pdVar4) {
        local_40 = _815 * local_48 - local_50;
        local_18 = _815 * local_20 - local_28;
        local_10 = _815 * local_20 - local_30;
        goto LAB_80272c9c;
      }
    }
    else {
      if ((int)pdVar4 < 5) {
        local_40 = (double)pfVar3[3];
        local_18 = (double)pfVar3[2];
        local_10 = _815 * local_18 - local_20;
        goto LAB_80272c9c;
      }
    }
  }
  local_40 = (double)pfVar3[3];
  local_18 = (double)pfVar3[2];
  local_10 = (double)pfVar3[4];
LAB_80272c9c:
  functionvalue::interpolateValue_BSpline_nonuniform
            ((functionvalue *)&local_58,param_2,&local_38,pdVar4);
  return;
}


/* __thiscall TFunctionValue_hermite::TFunctionValue_hermite(void) */

void __thiscall
TFunctionValue_hermite::TFunctionValue_hermite(TFunctionValue_hermite *this)

{
  TFunctionValue::TFunctionValue((TFunctionValue *)this);
  TFunctionValueAttribute_range::TFunctionValueAttribute_range
            ((TFunctionValueAttribute_range *)(this + 8));
  *(undefined1 **)this = &__vt;
  *(undefined4 *)(this + 0x40) = 0;
  *(undefined4 *)(this + 0x44) = 0;
  *(undefined4 *)(this + 0x48) = 0;
  *(undefined4 *)(this + 0x4c) = 0;
  *(undefined4 *)(this + 0x50) = *(undefined4 *)(this + 0x48);
  *(undefined4 *)(this + 0x54) = *(undefined4 *)(this + 0x4c);
  *(undefined4 *)(this + 0x58) = *(undefined4 *)(this + 0x50);
  *(undefined4 *)(this + 0x5c) = *(undefined4 *)(this + 0x4c);
  *(undefined4 *)(this + 0x60) = *(undefined4 *)(this + 0x50);
  return;
}


/* __thiscall TFunctionValue_hermite::getType(void) const */

undefined4 __thiscall TFunctionValue_hermite::getType(TFunctionValue_hermite *this)

{
  return 6;
}


/* __thiscall TFunctionValue_hermite::getAttributeSet(void) */

void __thiscall TFunctionValue_hermite::getAttributeSet(TFunctionValue_hermite *this)

{
  int in_r4;
  
  if (in_r4 != 0) {
    in_r4 = in_r4 + 8;
  }
  *(undefined4 *)this = 0;
  *(int *)(this + 4) = in_r4;
  *(undefined4 *)(this + 8) = 0;
  return;
}


/* __thiscall TFunctionValue_hermite::data_set(float const *,
                                                        unsigned long,
                                                        unsigned long) */

void __thiscall
TFunctionValue_hermite::data_set
          (TFunctionValue_hermite *this,float *param_1,ulong param_2,ulong param_3)

{
  *(float **)(this + 0x40) = param_1;
  *(ulong *)(this + 0x44) = param_2;
  *(ulong *)(this + 0x48) = param_3;
  *(undefined4 *)(this + 0x4c) = *(undefined4 *)(this + 0x40);
  *(undefined4 *)(this + 0x50) = *(undefined4 *)(this + 0x48);
  *(int *)(this + 0x54) = *(int *)(this + 0x40) + *(int *)(this + 0x44) * *(int *)(this + 0x48) * 4;
  *(int *)(this + 0x58) = *(int *)(this + 0x48);
  *(undefined4 *)(this + 0x5c) = *(undefined4 *)(this + 0x4c);
  *(undefined4 *)(this + 0x60) = *(undefined4 *)(this + 0x50);
  return;
}


/* __thiscall TFunctionValue_hermite::initialize(void) */

void __thiscall TFunctionValue_hermite::initialize(TFunctionValue_hermite *this)

{
  TFunctionValueAttribute_range::range_initialize((TFunctionValueAttribute_range *)(this + 8));
  *(undefined4 *)(this + 0x40) = 0;
  *(undefined4 *)(this + 0x44) = 0;
  *(undefined4 *)(this + 0x48) = 0;
  *(undefined4 *)(this + 0x4c) = 0;
  *(undefined4 *)(this + 0x50) = *(undefined4 *)(this + 0x48);
  *(undefined4 *)(this + 0x54) = *(undefined4 *)(this + 0x4c);
  *(undefined4 *)(this + 0x58) = *(undefined4 *)(this + 0x50);
  *(undefined4 *)(this + 0x5c) = *(undefined4 *)(this + 0x4c);
  *(undefined4 *)(this + 0x60) = *(undefined4 *)(this + 0x50);
  return;
}


/* __thiscall TFunctionValue_hermite::prepare(void) */

void __thiscall TFunctionValue_hermite::prepare(TFunctionValue_hermite *this)

{
  TFunctionValueAttribute_range::range_prepare((TFunctionValueAttribute_range *)(this + 8));
  return;
}


/* __thiscall TFunctionValue_hermite::getValue(double) */

double __thiscall
TFunctionValue_hermite::getValue(TFunctionValue_hermite *this,double param_1)

{
  float *pfVar1;
  float *pfVar2;
  double dVar3;
  double local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  local_38 = param_1;
  local_38 = (double)TFunctionValueAttribute_range::range_getParameter
                               ((TFunctionValueAttribute_range *)(this + 8),param_1,
                                (double)**(float **)(this + 0x40),
                                (double)(*(float **)(this + 0x40))
                                        [(*(int *)(this + 0x44) + -1) * *(int *)(this + 0x48)]);
  local_30 = *(undefined4 *)(this + 0x5c);
  local_2c = *(undefined4 *)(this + 0x60);
  local_28 = *(undefined4 *)(this + 0x54);
  local_24 = *(undefined4 *)(this + 0x58);
  local_20 = *(undefined4 *)(this + 0x4c);
  local_1c = *(undefined4 *)(this + 0x50);
  ::JGadget::findUpperBound_binary_current
            ((JGadget *)&local_18,(TIterator_data_)&local_20,(TIterator_data_)&local_28,
             (TIterator_data_)&local_30,&local_38);
  *(undefined4 *)(this + 0x5c) = local_18;
  *(undefined4 *)(this + 0x60) = local_14;
  pfVar2 = *(float **)(this + 0x5c);
  if (pfVar2 == *(float **)(this + 0x4c)) {
    dVar3 = (double)pfVar2[1];
  }
  else {
    if (pfVar2 == *(float **)(this + 0x54)) {
      *(int *)(this + 0x5c) = *(int *)(this + 0x5c) + *(int *)(this + 0x60) * -4;
      dVar3 = (double)*(float *)(*(int *)(this + 0x5c) + 4);
    }
    else {
      pfVar1 = pfVar2 + -*(int *)(this + 0x48);
      dVar3 = (double)functionvalue::interpolateValue_hermite
                                ((functionvalue *)(pfVar1 + *(int *)(this + 0x48)),local_38,
                                 (double)*pfVar1,(double)pfVar1[1],
                                 (double)(pfVar1 + *(int *)(this + 0x48))[-1],(double)*pfVar2,
                                 (double)pfVar2[1],(double)pfVar2[2]);
    }
  }
  return dVar3;
}


/* __thiscall functionvalue::extrapolateParameter_raw(double,
                                                               double) */

void __thiscall
functionvalue::extrapolateParameter_raw(functionvalue *this,double param_1,double param_2)

{
  return;
}


/* __thiscall functionvalue::extrapolateParameter_repeat(double,
                                                                  double) */

double __thiscall
functionvalue::extrapolateParameter_repeat
          (functionvalue *this,double param_1,double param_2)

{
  double dVar1;
  
  dVar1 = MSL_C.PPCEABI.bare.H::fmod(param_1,param_2);
  if (dVar1 < _625) {
    dVar1 = dVar1 + param_2;
  }
  return dVar1;
}


/* __thiscall functionvalue::extrapolateParameter_clamp(double,
                                                                 double) */

double __thiscall
functionvalue::extrapolateParameter_clamp
          (functionvalue *this,double param_1,double param_2)

{
  if (param_1 <= _625) {
    return _625;
  }
  if (param_1 < param_2) {
    return param_1;
  }
  return param_2;
}

}

/* __thiscall
   JGadget::findUpperBound_binary_current<JStudio::TFunctionValue_list_parameter::TIterator_data_,double>(JStudio::TFunctionValue_list_parameter::TIterator_data_,
   
   JStudio::TFunctionValue_list_parameter::TIterator_data_,
   
   JStudio::TFunctionValue_list_parameter::TIterator_data_,
   
   double const &) */

void __thiscall
JGadget::findUpperBound_binary_current
          (JGadget *this,TIterator_data_ param_1,TIterator_data_ param_2,TIterator_data_ param_3,
          double *param_4)

{
  undefined local_24 [4];
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18 [5];
  
  local_20 = *(undefined4 *)param_3;
  local_1c = *(undefined4 *)param_2;
  local_18[0] = *(undefined4 *)param_1;
  findUpperBound_binary_current
            (this,(TIterator_data_)local_18,(TIterator_data_)&local_1c,(TIterator_data_)&local_20,
             param_4,(less_double_)local_24);
  return;
}


/* __thiscall
   JGadget::findUpperBound_binary_current<JStudio::TFunctionValue_list_parameter::TIterator_data_,double,std::less<double><double>>(JStudio::TFunctionValue_list_parameter::TIterator_data_,
   
   JStudio::TFunctionValue_list_parameter::TIterator_data_,
   
   JStudio::TFunctionValue_list_parameter::TIterator_data_,
   
   double const &,
   
   std::less<double><double>) */

void __thiscall
JGadget::findUpperBound_binary_current
          (JGadget *this,TIterator_data_ param_1,TIterator_data_ param_2,TIterator_data_ param_3,
          double *param_4,less_double_ param_5)

{
  float *pfVar1;
  uint uVar2;
  uint uVar3;
  float **ppfVar4;
  int iVar5;
  undefined local_58 [4];
  undefined local_54 [4];
  undefined local_50;
  undefined local_4c;
  float *local_48;
  float *local_44;
  float *local_40;
  float *local_3c;
  float *local_38;
  float *local_34;
  float *local_30;
  float *local_2c;
  float *local_28;
  float *local_24;
  float *local_20;
  float *local_1c;
  float *local_18;
  float *local_14;
  float *local_10;
  float *local_c;
  
  uVar2 = countLeadingZeros(*(int *)param_2 - (int)*(float **)param_3);
  uVar3 = uVar2 >> 5;
  if ((uVar2 >> 5 & 0xff) == 0) {
    uVar3 = ((uint)(byte)((*param_4 < (double)**(float **)param_3) << 3) << 0x1c) >> 0x1f;
  }
  if ((uVar3 & 0xff) == 0) {
    local_40 = *(float **)param_3;
    local_1c = local_40;
    local_3c = *(float **)param_2;
    local_18 = local_3c;
    local_58[0] = *(undefined *)param_5;
    if (local_40 == local_3c) {
      local_20 = local_3c;
      ppfVar4 = &local_20;
    }
    else {
      uVar3 = (int)local_3c - (int)local_40;
      uVar3 = ((int)uVar3 >> 2) + (uint)((int)uVar3 < 0 && (uVar3 & 3) != 0) >> 1;
      iVar5 = 1;
      local_28 = local_40;
      while ((double)*local_28 <= *param_4) {
        local_1c = local_28;
        uVar3 = uVar3 - iVar5;
        pfVar1 = local_3c;
        if ((int)uVar3 < 1) goto LAB_802731fc;
        local_28 = local_28 + iVar5 * 2;
        iVar5 = iVar5 * 8;
      }
      pfVar1 = local_28;
      if (iVar5 == 1) {
        local_20 = local_28;
        ppfVar4 = &local_20;
      }
      else {
LAB_802731fc:
        local_28 = pfVar1;
        local_44 = local_28;
        local_48 = local_1c;
        local_50 = local_58[0];
        std::upper_bound((std *)&local_20,(TIterator_data_)&local_48,(TIterator_data_)&local_44,
                         param_4,(less_double_)local_58);
        ppfVar4 = &local_20;
      }
    }
  }
  else {
    local_30 = *(float **)param_1;
    local_14 = *(float **)param_3;
    local_54[0] = *(undefined *)param_5;
    if (local_30 == local_14) {
      ppfVar4 = &local_14;
    }
    else {
      local_2c = local_14 + -2;
      uVar3 = (int)local_2c - (int)local_30;
      uVar3 = ((int)uVar3 >> 2) + (uint)((int)uVar3 < 0 && (uVar3 & 3) != 0) >> 1;
      iVar5 = 1;
      local_24 = local_2c;
      local_c = local_2c;
      while (*param_4 < (double)*local_24) {
        local_c = local_24;
        uVar3 = uVar3 - iVar5;
        pfVar1 = local_30;
        if ((int)uVar3 < 1) goto LAB_80273120;
        local_24 = local_24 + iVar5 * -2;
        iVar5 = iVar5 * 8;
      }
      pfVar1 = local_24;
      if (iVar5 == 1) {
        local_14 = local_24 + 2;
        ppfVar4 = &local_14;
      }
      else {
LAB_80273120:
        local_24 = pfVar1;
        local_34 = local_c + 2;
        local_38 = local_24;
        local_4c = local_54[0];
        local_10 = local_30;
        local_c = local_34;
        std::upper_bound((std *)&local_14,(TIterator_data_)&local_38,(TIterator_data_)&local_34,
                         param_4,(less_double_)local_54);
        ppfVar4 = &local_14;
      }
    }
  }
  *(float **)this = *ppfVar4;
  return;
}


/* __thiscall
   JGadget::findUpperBound_binary_current<JStudio::TFunctionValue_hermite::TIterator_data_,double>(JStudio::TFunctionValue_hermite::TIterator_data_,
   
   JStudio::TFunctionValue_hermite::TIterator_data_,
   
   JStudio::TFunctionValue_hermite::TIterator_data_,
   
   double const &) */

void __thiscall
JGadget::findUpperBound_binary_current
          (JGadget *this,TIterator_data_ param_1,TIterator_data_ param_2,TIterator_data_ param_3,
          double *param_4)

{
  undefined local_24 [4];
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_20 = *(undefined4 *)param_3;
  local_1c = *(undefined4 *)(param_3 + 4);
  local_18 = *(undefined4 *)param_2;
  local_14 = *(undefined4 *)(param_2 + 4);
  local_10 = *(undefined4 *)param_1;
  local_c = *(undefined4 *)(param_1 + 4);
  findUpperBound_binary_current
            (this,(TIterator_data_)&local_10,(TIterator_data_)&local_18,(TIterator_data_)&local_20,
             param_4,(less_double_)local_24);
  return;
}


/* __thiscall
   JGadget::findUpperBound_binary_current<JStudio::TFunctionValue_hermite::TIterator_data_,double,std::less<double><double>>(JStudio::TFunctionValue_hermite::TIterator_data_,
   
   JStudio::TFunctionValue_hermite::TIterator_data_,
   
   JStudio::TFunctionValue_hermite::TIterator_data_,
   
   double const &,
   
   std::less<double><double>) */

void __thiscall
JGadget::findUpperBound_binary_current
          (JGadget *this,TIterator_data_ param_1,TIterator_data_ param_2,TIterator_data_ param_3,
          double *param_4,less_double_ param_5)

{
  float *pfVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  float **ppfVar5;
  int iVar6;
  undefined local_b8 [4];
  undefined local_b4 [4];
  undefined local_b0;
  undefined local_ac;
  float *local_a8;
  uint local_a4;
  float *local_a0;
  uint local_9c;
  float *local_98;
  uint local_94;
  float *local_90;
  uint local_8c;
  float *local_88;
  uint local_84;
  float *local_80;
  uint local_7c;
  float *local_78;
  uint local_74;
  float *local_70;
  uint local_6c;
  float *local_68;
  uint local_64;
  float *local_60;
  uint local_5c;
  float *local_58;
  uint local_54;
  float *local_50;
  uint local_4c;
  float *local_48;
  uint local_44;
  float *local_40;
  uint local_3c;
  float *local_38;
  uint local_34;
  float *local_30;
  uint local_2c;
  float *local_28;
  uint local_24;
  float *local_20;
  uint local_1c;
  float *local_18;
  uint local_14;
  
  uVar2 = countLeadingZeros(*(int *)param_2 - (int)*(float **)param_3);
  uVar3 = uVar2 >> 5;
  if ((uVar2 >> 5 & 0xff) == 0) {
    uVar3 = ((uint)(byte)((*param_4 < (double)**(float **)param_3) << 3) << 0x1c) >> 0x1f;
  }
  if ((uVar3 & 0xff) == 0) {
    local_a0 = *(float **)param_3;
    local_a4 = *(uint *)(param_3 + 4);
    local_38 = local_a0;
    local_34 = local_a4;
    local_78 = *(float **)param_2;
    local_74 = *(uint *)(param_2 + 4);
    local_30 = local_78;
    local_2c = local_74;
    local_b8[0] = *(undefined *)param_5;
    if (local_a0 == local_78) {
      local_40 = local_78;
      local_3c = local_74;
      ppfVar5 = &local_40;
    }
    else {
      uVar3 = (int)local_78 - (int)local_a0;
      uVar3 = (((int)uVar3 >> 2) + (uint)((int)uVar3 < 0 && (uVar3 & 3) != 0)) / local_74;
      iVar6 = 1;
      for (local_50 = local_a0; (double)*local_50 <= *param_4; local_50 = local_50 + iVar4) {
        local_38 = local_50;
        uVar3 = uVar3 - iVar6;
        pfVar1 = local_78;
        local_4c = local_74;
        if ((int)uVar3 < 1) goto LAB_80273538;
        iVar4 = local_a4 * iVar6;
        iVar6 = iVar6 << 3;
      }
      pfVar1 = local_50;
      local_4c = local_a4;
      if (iVar6 == 1) {
        local_40 = local_50;
        local_3c = local_a4;
        ppfVar5 = &local_40;
      }
      else {
LAB_80273538:
        local_50 = pfVar1;
        local_a8 = local_38;
        local_88 = local_50;
        local_84 = local_4c;
        local_90 = local_38;
        local_b0 = local_b8[0];
        local_9c = local_a4;
        local_8c = local_a4;
        local_80 = local_a0;
        local_7c = local_a4;
        std::upper_bound((std *)&local_40,(TIterator_data_)&local_90,(TIterator_data_)&local_88,
                         param_4,(less_double_)local_b8);
        ppfVar5 = &local_40;
      }
    }
  }
  else {
    local_60 = *(float **)param_1;
    local_5c = *(uint *)(param_1 + 4);
    local_28 = *(float **)param_3;
    local_64 = *(uint *)(param_3 + 4);
    local_b4[0] = *(undefined *)param_5;
    if (local_60 == local_28) {
      local_24 = local_64;
      ppfVar5 = &local_28;
    }
    else {
      local_58 = local_28 + -local_64;
      uVar3 = (int)local_58 - (int)local_60;
      uVar3 = (((int)uVar3 >> 2) + (uint)((int)uVar3 < 0 && (uVar3 & 3) != 0)) / local_64;
      iVar6 = 1;
      local_18 = local_58;
      for (local_48 = local_58; *param_4 < (double)*local_48; local_48 = local_48 + -iVar4) {
        local_18 = local_48;
        uVar3 = uVar3 - iVar6;
        pfVar1 = local_60;
        local_44 = local_5c;
        if ((int)uVar3 < 1) goto LAB_802733fc;
        iVar4 = local_64 * iVar6;
        iVar6 = iVar6 << 3;
      }
      pfVar1 = local_48;
      local_44 = local_64;
      if (iVar6 == 1) {
        local_28 = local_48 + local_64;
        local_24 = local_64;
        ppfVar5 = &local_28;
      }
      else {
LAB_802733fc:
        local_48 = pfVar1;
        local_68 = local_18 + local_64;
        local_98 = local_48;
        local_94 = local_44;
        local_70 = local_48;
        local_6c = local_44;
        local_ac = local_b4[0];
        local_54 = local_64;
        local_20 = local_60;
        local_1c = local_5c;
        local_18 = local_68;
        local_14 = local_64;
        std::upper_bound((std *)&local_28,(TIterator_data_)&local_70,(TIterator_data_)&local_68,
                         param_4,(less_double_)local_b4);
        ppfVar5 = &local_28;
      }
    }
  }
  *(float **)this = *ppfVar5;
  *(float **)(this + 4) = ppfVar5[1];
  return;
}


namespace JStudio {

/* __thiscall TFunctionValue_hermite::~TFunctionValue_hermite(void) */

void __thiscall
TFunctionValue_hermite::_TFunctionValue_hermite(TFunctionValue_hermite *this)

{
  short in_r4;
  
  if (this != (TFunctionValue_hermite *)0x0) {
    *(undefined1 **)this = &__vt;
    TFunctionValue::_TFunctionValue((TFunctionValue *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TFunctionValue_list_parameter::~TFunctionValue_list_parameter(void) */

void __thiscall
TFunctionValue_list_parameter::_TFunctionValue_list_parameter
          (TFunctionValue_list_parameter *this)

{
  short in_r4;
  
  if (this != (TFunctionValue_list_parameter *)0x0) {
    *(undefined1 **)this = &__vt;
    TFunctionValue::_TFunctionValue((TFunctionValue *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TFunctionValue_list::~TFunctionValue_list(void) */

void __thiscall TFunctionValue_list::_TFunctionValue_list(TFunctionValue_list *this)

{
  short in_r4;
  
  if (this != (TFunctionValue_list *)0x0) {
    *(undefined1 **)this = &__vt;
    TFunctionValue::_TFunctionValue((TFunctionValue *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TFunctionValue_transition::~TFunctionValue_transition(void) */

void __thiscall
TFunctionValue_transition::_TFunctionValue_transition(TFunctionValue_transition *this)

{
  short in_r4;
  
  if (this != (TFunctionValue_transition *)0x0) {
    *(undefined1 **)this = &__vt;
    TFunctionValue::_TFunctionValue((TFunctionValue *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TFunctionValue_constant::~TFunctionValue_constant(void) */

void __thiscall
TFunctionValue_constant::_TFunctionValue_constant(TFunctionValue_constant *this)

{
  short in_r4;
  
  if (this != (TFunctionValue_constant *)0x0) {
    *(undefined1 **)this = &__vt;
    TFunctionValue::_TFunctionValue((TFunctionValue *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TFunctionValue_composite::~TFunctionValue_composite(void) */

void __thiscall
TFunctionValue_composite::_TFunctionValue_composite(TFunctionValue_composite *this)

{
  short in_r4;
  
  if (this != (TFunctionValue_composite *)0x0) {
    *(undefined1 **)this = &__vt;
    if ((this != (TFunctionValue_composite *)0xfffffffc) &&
       (this != (TFunctionValue_composite *)0xfffffffc)) {
      ::JGadget::TVector_pointer_void::_TVector_pointer_void((TVector_pointer_void *)(this + 4));
    }
    TFunctionValue::_TFunctionValue((TFunctionValue *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}

}

/* __thiscall
   std::upper_bound<JStudio::TFunctionValue_list_parameter::TIterator_data_,double,std::less<double><double>>(JStudio::TFunctionValue_list_parameter::TIterator_data_,
   
   JStudio::TFunctionValue_list_parameter::TIterator_data_,
   
   double const &,
   
   std::less<double><double>) */

void __thiscall
std::upper_bound(std *this,TIterator_data_ param_1,TIterator_data_ param_2,double *param_3,
                less_double_ param_4)

{
  uint uVar1;
  float *pfVar2;
  uint uVar3;
  
  uVar1 = *(int *)param_2 - *(int *)param_1;
  uVar1 = ((int)uVar1 >> 2) + (uint)((int)uVar1 < 0 && (uVar1 & 3) != 0) >> 1;
  while (uVar3 = uVar1, 0 < (int)uVar3) {
    uVar1 = ((int)uVar3 >> 1) + (uint)((int)uVar3 < 0 && (uVar3 & 1) != 0);
    pfVar2 = (float *)(*(int *)param_1 + uVar1 * 8);
    if ((double)*pfVar2 <= *param_3) {
      *(float **)param_1 = pfVar2 + 2;
      uVar1 = uVar3 - (uVar1 + 1);
    }
  }
  *(undefined4 *)this = *(undefined4 *)param_1;
  return;
}


/* __thiscall
   std::upper_bound<JStudio::TFunctionValue_hermite::TIterator_data_,double,std::less<double><double>>(JStudio::TFunctionValue_hermite::TIterator_data_,
   
   JStudio::TFunctionValue_hermite::TIterator_data_,
   
   double const &,
   
   std::less<double><double>) */

void __thiscall
std::upper_bound(std *this,TIterator_data_ param_1,TIterator_data_ param_2,double *param_3,
                less_double_ param_4)

{
  uint uVar1;
  float *pfVar2;
  int iVar3;
  uint uVar4;
  
  uVar1 = *(int *)param_2 - *(int *)param_1;
  uVar1 = (((int)uVar1 >> 2) + (uint)((int)uVar1 < 0 && (uVar1 & 3) != 0)) / *(uint *)(param_2 + 4);
  while (uVar4 = uVar1, 0 < (int)uVar4) {
    iVar3 = *(int *)(param_1 + 4);
    uVar1 = ((int)uVar4 >> 1) + (uint)((int)uVar4 < 0 && (uVar4 & 1) != 0);
    pfVar2 = (float *)(*(int *)param_1 + iVar3 * uVar1 * 4);
    if ((double)*pfVar2 <= *param_3) {
      *(float **)param_1 = pfVar2 + iVar3;
      *(int *)(param_1 + 4) = iVar3;
      uVar1 = uVar4 - (uVar1 + 1);
    }
  }
  *(undefined4 *)this = *(undefined4 *)param_1;
  *(undefined4 *)(this + 4) = *(undefined4 *)(param_1 + 4);
  return;
}

