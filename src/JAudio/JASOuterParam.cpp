#include <JAudio/JASOuterParam.h>
#include <JASystem/TTrack/TOuterParam.h>


namespace JASystem {

namespace TTrack {

/* __thiscall TOuterParam::TOuterParam(void) */

void __thiscall TOuterParam::TOuterParam(TOuterParam *this)

{
  float fVar1;
  int iVar2;
  int iVar3;
  
  *(undefined2 *)this = 0;
  *(undefined2 *)(this + 2) = 0;
  fVar1 = JAudio::_629;
  *(float *)(this + 4) = JAudio::_629;
  *(float *)(this + 8) = fVar1;
  *(float *)(this + 0xc) = fVar1;
  *(float *)(this + 0x10) = fVar1;
  *(float *)(this + 0x14) = fVar1;
  *(float *)(this + 0x18) = fVar1;
  iVar2 = 0;
  iVar3 = 8;
  do {
    *(undefined2 *)(this + iVar2 + 0x1c) = 0;
    iVar2 = iVar2 + 2;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}


/* __thiscall TOuterParam::initExtBuffer(void) */

void __thiscall TOuterParam::initExtBuffer(TOuterParam *this)

{
  *(undefined2 *)this = 0;
  *(undefined2 *)(this + 2) = 0;
  return;
}


/* __thiscall TOuterParam::setOuterSwitch(unsigned short) */

void __thiscall TOuterParam::setOuterSwitch(TOuterParam *this,ushort param_1)

{
  *(ushort *)this = param_1;
  return;
}


/* __thiscall TOuterParam::checkOuterSwitch(unsigned short) */

bool __thiscall TOuterParam::checkOuterSwitch(TOuterParam *this,ushort param_1)

{
  return (param_1 & *(ushort *)this) != 0;
}


/* __thiscall TOuterParam::setOuterUpdate(unsigned short) */

void __thiscall TOuterParam::setOuterUpdate(TOuterParam *this,ushort param_1)

{
  *(ushort *)(this + 2) = param_1;
  return;
}


/* __thiscall TOuterParam::getOuterUpdate(void) */

undefined2 __thiscall TOuterParam::getOuterUpdate(TOuterParam *this)

{
  return *(undefined2 *)(this + 2);
}


/* __thiscall TOuterParam::getIntFirFilter(unsigned char) */

int __thiscall TOuterParam::getIntFirFilter(TOuterParam *this,uchar param_1)

{
  return (int)*(short *)(this + (uint)param_1 * 2 + 0x1c);
}


/* __thiscall TOuterParam::setParam(unsigned char,
                                                      float) */

void __thiscall
TOuterParam::setParam(TOuterParam *this,uchar param_1,float param_2)

{
  float *pfVar1;
  
  if (param_1 == '\b') {
    pfVar1 = (float *)(this + 0x14);
  }
  else {
    if (param_1 < 8) {
      if (param_1 == '\x03') {
        return;
      }
      if (param_1 < 3) {
        if (param_1 == '\x01') {
          pfVar1 = (float *)(this + 4);
        }
        else {
          if (param_1 == '\0') {
            return;
          }
          pfVar1 = (float *)(this + 8);
        }
      }
      else {
        if (4 < param_1) {
          return;
        }
        pfVar1 = (float *)(this + 0xc);
      }
    }
    else {
      if (param_1 == '@') {
        pfVar1 = (float *)(this + 0x18);
      }
      else {
        if (0x3f < param_1) {
          return;
        }
        if (param_1 != '\x10') {
          return;
        }
        pfVar1 = (float *)(this + 0x10);
      }
    }
  }
  *pfVar1 = param_2;
  *(ushort *)(this + 2) = *(ushort *)(this + 2) | (ushort)param_1;
  return;
}


/* __thiscall TOuterParam::onSwitch(unsigned short) */

void __thiscall TOuterParam::onSwitch(TOuterParam *this,ushort param_1)

{
  *(ushort *)this = *(ushort *)this | param_1;
  *(ushort *)(this + 2) = *(ushort *)(this + 2) | param_1;
  return;
}


/* __thiscall TOuterParam::setFirFilter(short *) */

void __thiscall TOuterParam::setFirFilter(TOuterParam *this,short *param_1)

{
  byte bVar1;
  
  *(ushort *)(this + 2) = *(ushort *)(this + 2) | 0x80;
  *(ushort *)this = *(ushort *)this | 0x80;
  for (bVar1 = 0; bVar1 < 8; bVar1 = bVar1 + 1) {
    *(short *)(this + (uint)bVar1 * 2 + 0x1c) = param_1[bVar1];
  }
  return;
}

