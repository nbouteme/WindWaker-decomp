#include <JUtility/JUTFader.h>
#include <J2DGraph/J2DOrthoGraph.h>
#include <J2DGraph/J2DGrafContext.h>
#include <JKernel/JKRHeap.h>
#include <JUTFader.h>


/* __thiscall JUTFader::JUTFader(int,
                                 int,
                                 int,
                                 int,
                                 JUtility::TColor) */

void __thiscall
JUTFader::JUTFader(JUTFader *this,int param_1,int param_2,int param_3,int param_4,TColor param_5)

{
  double dVar1;
  
  *(undefined1 **)this = &__vt;
  *(undefined4 *)(this + 0xc) = *(undefined4 *)param_5;
  dVar1 = JUtility::_2158;
  *(float *)(this + 0x10) =
       (float)((double)CONCAT44(0x43300000,param_1 ^ 0x80000000) - JUtility::_2158);
  *(float *)(this + 0x14) = (float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - dVar1);
  *(float *)(this + 0x18) =
       (float)((double)CONCAT44(0x43300000,param_1 + param_3 ^ 0x80000000) - dVar1);
  *(float *)(this + 0x1c) =
       (float)((double)CONCAT44(0x43300000,param_2 + param_4 ^ 0x80000000) - dVar1);
  *(undefined4 *)(this + 4) = 0;
  *(undefined2 *)(this + 8) = 0;
  *(undefined2 *)(this + 10) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x20) = 0xffffffff;
  return;
}


/* __thiscall JUTFader::control(void) */

void __thiscall JUTFader::control(JUTFader *this)

{
  short sVar1;
  int iVar2;
  
  iVar2 = *(int *)(this + 0x20);
  if ((-1 < iVar2) && (*(int *)(this + 0x20) = iVar2 + -1, iVar2 == 0)) {
    *(undefined4 *)(this + 4) = *(undefined4 *)(this + 0x24);
  }
  iVar2 = *(int *)(this + 4);
  if (iVar2 != 1) {
    if (iVar2 == 2) {
      sVar1 = *(short *)(this + 10);
      *(ushort *)(this + 10) = sVar1 + 1U;
      this[0xf] = (JUTFader)
                  (-1 - (char)(((uint)(ushort)(sVar1 + 1U) * 0xff) / (uint)*(ushort *)(this + 8)));
      if (*(ushort *)(this + 8) <= *(ushort *)(this + 10)) {
        *(undefined4 *)(this + 4) = 1;
      }
    }
    else {
      if (iVar2 < 2) {
        if (iVar2 == 0) {
          this[0xf] = (JUTFader)0xff;
        }
      }
      else {
        if (iVar2 < 4) {
          sVar1 = *(short *)(this + 10);
          *(ushort *)(this + 10) = sVar1 + 1U;
          this[0xf] = SUB41(((uint)(ushort)(sVar1 + 1U) * 0xff) / (uint)*(ushort *)(this + 8),0);
          if (*(ushort *)(this + 8) <= *(ushort *)(this + 10)) {
            *(undefined4 *)(this + 4) = 0;
          }
        }
      }
    }
    (**(code **)(*(int *)this + 0x14))();
  }
  return;
}


/* __thiscall JUTFader::draw(void) */

void __thiscall JUTFader::draw(JUTFader *this)

{
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  J2DOrthoGraph local_e4;
  
  if (this[0xf] != (JUTFader)0x0) {
    J2DOrthoGraph::J2DOrthoGraph(&local_e4);
    local_f8 = *(undefined4 *)(this + 0xc);
    local_f4 = local_f8;
    local_f0 = local_f8;
    local_ec = local_f8;
    local_e8 = local_f8;
    J2DGrafContext::setColor
              (&local_e4.parent,(TColor)&local_f8,(TColor)&local_f4,(TColor)&local_f0,
               (TColor)&local_ec);
    J2DGrafContext::fillBox(&local_e4.parent,(TBox2_float_ *)(this + 0x10));
  }
  return;
}


/* __thiscall JUTFader::startFadeIn(int) */

uint __thiscall JUTFader::startFadeIn(JUTFader *this,int param_1)

{
  uint uVar1;
  
  uVar1 = countLeadingZeros(*(undefined4 *)(this + 4));
  if ((uVar1 >> 5 & 0xff) != 0) {
    *(undefined4 *)(this + 4) = 2;
    *(undefined2 *)(this + 10) = 0;
    *(short *)(this + 8) = (short)param_1;
  }
  return uVar1 >> 5;
}


/* __thiscall JUTFader::startFadeOut(int) */

uint __thiscall JUTFader::startFadeOut(JUTFader *this,int param_1)

{
  uint uVar1;
  
  uVar1 = countLeadingZeros(1 - *(int *)(this + 4));
  if ((uVar1 >> 5 & 0xff) != 0) {
    *(undefined4 *)(this + 4) = 3;
    *(undefined2 *)(this + 10) = 0;
    *(short *)(this + 8) = (short)param_1;
  }
  return uVar1 >> 5;
}


/* __thiscall JUTFader::~JUTFader(void) */

void __thiscall JUTFader::_JUTFader(JUTFader *this)

{
  short in_r4;
  
  if ((this != (JUTFader *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}

