#include <JAudio/JASRegisterParam.h>
#include <JASystem/TRegisterParam.h>


namespace JASystem {

/* __thiscall TRegisterParam::TRegisterParam(void) */

void __thiscall TRegisterParam::TRegisterParam(TRegisterParam *this)

{
  *(undefined2 *)this = 0;
  *(undefined2 *)(this + 2) = 0;
  *(undefined2 *)(this + 4) = 0;
  *(undefined2 *)(this + 6) = 0;
  *(undefined2 *)(this + 8) = 0;
  *(undefined2 *)(this + 10) = 0;
  *(undefined2 *)(this + 0xc) = 0;
  *(undefined2 *)(this + 0xe) = 0;
  *(undefined2 *)(this + 0x1a) = 0;
  *(undefined2 *)(this + 0x10) = 0;
  *(undefined2 *)(this + 0x12) = 0;
  *(undefined2 *)(this + 0x14) = 0;
  *(undefined2 *)(this + 0x16) = 0;
  *(undefined2 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  return;
}


/* __thiscall TRegisterParam::init(void) */

int __thiscall TRegisterParam::init(TRegisterParam *this,EVP_PKEY_CTX *ctx)

{
  *(undefined2 *)this = 0;
  *(undefined2 *)(this + 2) = 0;
  *(undefined2 *)(this + 4) = 0;
  *(undefined2 *)(this + 6) = 0;
  *(undefined2 *)(this + 8) = 0;
  *(undefined2 *)(this + 10) = 0;
  *(undefined2 *)(this + 0xc) = 0xf0;
  *(undefined2 *)(this + 0xe) = 0xc;
  *(undefined2 *)(this + 0x1a) = 0x40;
  *(undefined2 *)(this + 0x10) = 0;
  *(undefined2 *)(this + 0x12) = 1;
  *(undefined2 *)(this + 0x14) = 1;
  *(undefined2 *)(this + 0x16) = 0x7fff;
  *(undefined2 *)(this + 0x18) = 0x4000;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  return (int)this;
}


/* __thiscall TRegisterParam::inherit(TRegisterParam const &) */

void __thiscall TRegisterParam::inherit(TRegisterParam *this,TRegisterParam *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  *(undefined2 *)this = 0;
  *(undefined2 *)(this + 2) = 0;
  *(undefined2 *)(this + 4) = 0;
  *(undefined2 *)(this + 6) = 0;
  *(undefined2 *)(this + 8) = 0;
  *(undefined2 *)(this + 10) = 0;
  *(undefined2 *)(this + 0xc) = *(undefined2 *)(param_1 + 0xc);
  *(undefined2 *)(this + 0xe) = *(undefined2 *)(param_1 + 0xe);
  *(undefined2 *)(this + 0x1a) = *(undefined2 *)(param_1 + 0x1a);
  iVar2 = 5;
  do {
    *(undefined2 *)(this + iVar1 + 0x10) = *(undefined2 *)(param_1 + iVar1 + 0x10);
    iVar1 = iVar1 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  return;
}


/* __thiscall TRegisterParam::getBankNumber(void) const */

ushort __thiscall TRegisterParam::getBankNumber(TRegisterParam *this)

{
  return *(ushort *)(this + 0xc) >> 8;
}


/* __thiscall TRegisterParam::getProgramNumber(void) const */

ushort __thiscall TRegisterParam::getProgramNumber(TRegisterParam *this)

{
  return *(ushort *)(this + 0xc) & 0xff;
}

