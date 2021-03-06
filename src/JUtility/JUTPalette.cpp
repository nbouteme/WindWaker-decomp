#include <JUtility/JUTPalette.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <m_Do_printf.h>
#include <gx/GXTexture.h>
#include <Demangler/JUTPalette.h>


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JUTPalette::storeTLUT(_GXTlut,
                                    ResTLUT *) */

void __thiscall JUTPalette::storeTLUT(JUTPalette *this,_GXTlut param_1,ResTLUT *param_2)

{
  if (param_2 == (ResTLUT *)0x0) {
    m_Do_printf::OSPanic("JUTPalette.cpp",0x23,"JUTTexture: TLUT is NULL\n");
  }
  this->mTlut = (byte)param_1;
  this->mTlutFmt = param_2->mTlutFmt;
  this->mTransparency = param_2->mTransparency;
  this->mSize = param_2->mSize;
  this->mpData = param_2 + 1;
  gx::GXInitTlutObj(this,this->mpData,this->mTlutFmt,this->mSize);
  return;
}


/* __thiscall JUTPalette::storeTLUT(_GXTlut,
                                    _GXTlutFmt,
                                    JUTTransparency,
                                    unsigned short,
                                    void *) */

void __thiscall
JUTPalette::storeTLUT
          (JUTPalette *this,_GXTlut param_1,_GXTlutFmt param_2,JUTTransparency param_3,
          ushort param_4,void *param_5)

{
  this->mTlut = (byte)param_1;
  this->mTlutFmt = (byte)param_2;
  this->mTransparency = (byte)param_3;
  this->mSize = param_4;
  this->mpData = param_5;
  gx::GXInitTlutObj(this,this->mpData,this->mTlutFmt,this->mSize);
  return;
}


/* __thiscall JUTPalette::load(void) */

bool __thiscall JUTPalette::load(JUTPalette *this)

{
  bool bVar1;
  
  bVar1 = this->mSize != 0;
  if (bVar1) {
    gx::GXLoadTlut(this,this->mTlut);
  }
  return bVar1;
}

