#include <SComponent/c_data_tbl.h>
#include <JKernel/JKRHeap.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <SComponent/c_data_tbl.h>
#include <cDT_Name.h>
#include <cDT_DataSrc.h>
#include <cDT.h>
#include <cDT_NamePTbl.h>
#include <cDT_Format.h>


/* __thiscall cDT_NamePTbl::cDT_NamePTbl(void) */

void __thiscall cDT_NamePTbl::cDT_NamePTbl(cDT_NamePTbl *this)

{
  this->vtbl = (undefined *)&__vt;
  this->mCount = 0;
  this->mpNames = (char **)0x0;
  return;
}


/* __thiscall cDT_NamePTbl::~cDT_NamePTbl(void) */

void __thiscall cDT_NamePTbl::_cDT_NamePTbl(cDT_NamePTbl *this)

{
  short in_r4;
  
  if ((this != (cDT_NamePTbl *)0x0) && (this->vtbl = (undefined *)&__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall cDT_NamePTbl::Set(unsigned long,
                                char * *) */

void __thiscall cDT_NamePTbl::Set(cDT_NamePTbl *this,ulong param_1,char **param_2)

{
  this->mCount = param_1;
  this->mpNames = param_2;
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall cDT_NamePTbl::GetIndex(char const *,
                                     int) const */

uint __thiscall cDT_NamePTbl::GetIndex(cDT_NamePTbl *this,char *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_2 << 2;
  while( true ) {
    if (this->mCount <= (uint)param_2) {
      return 0xffffffff;
    }
    iVar1 = MSL_C.PPCEABI.bare.H::strcmp(param_1,*(char **)((int)this->mpNames + iVar2));
    if (iVar1 == 0) break;
    param_2 = param_2 + 1;
    iVar2 = iVar2 + 4;
  }
  return param_2;
}


/* __thiscall cDT_Format::cDT_Format(void) */

void __thiscall cDT_Format::cDT_Format(cDT_Format *this)

{
  cDT_NamePTbl::cDT_NamePTbl(&this->parent);
  (this->parent).vtbl = (undefined *)&__vt;
  return;
}


/* __thiscall cDT_Format::~cDT_Format(void) */

void __thiscall cDT_Format::_cDT_Format(cDT_Format *this)

{
  short in_r4;
  
  if (this != (cDT_Format *)0x0) {
    (this->parent).vtbl = (undefined *)&__vt;
    cDT_NamePTbl::_cDT_NamePTbl(&this->parent);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall cDT_Name::cDT_Name(void) */

void __thiscall cDT_Name::cDT_Name(cDT_Name *this)

{
  cDT_NamePTbl::cDT_NamePTbl(&this->parent);
  (this->parent).vtbl = (undefined *)&__vt;
  return;
}


/* __thiscall cDT_Name::~cDT_Name(void) */

void __thiscall cDT_Name::_cDT_Name(cDT_Name *this)

{
  short in_r4;
  
  if (this != (cDT_Name *)0x0) {
    (this->parent).vtbl = (undefined *)&__vt;
    cDT_NamePTbl::_cDT_NamePTbl(&this->parent);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall cDT_DataSrc::cDT_DataSrc(void) */

void __thiscall cDT_DataSrc::cDT_DataSrc(cDT_DataSrc *this)

{
  this[1].mRowNum = (ulong)&__vt;
  this->mRowNum = 0;
  this->mColNum = 0;
  this->mpData = (uchar *)0x0;
  return;
}


/* __thiscall cDT_DataSrc::~cDT_DataSrc(void) */

void __thiscall cDT_DataSrc::_cDT_DataSrc(cDT_DataSrc *this)

{
  short in_r4;
  
  if ((this != (cDT_DataSrc *)0x0) && (this[1].mRowNum = (ulong)&__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall cDT_DataSrc::Set(unsigned long,
                               unsigned long,
                               unsigned char *) */

void __thiscall cDT_DataSrc::Set(cDT_DataSrc *this,ulong param_1,ulong param_2,uchar *param_3)

{
  this->mRowNum = param_1;
  this->mColNum = param_2;
  this->mpData = param_3;
  return;
}


/* __thiscall cDT_DataSrc::GetInf(int,
                                  int) const */

uchar __thiscall cDT_DataSrc::GetInf(cDT_DataSrc *this,int param_1,int param_2)

{
  if ((((-1 < param_1) && ((uint)param_1 < this->mRowNum)) && (-1 < param_2)) &&
     ((uint)param_2 < this->mColNum)) {
    return this->mpData[param_1 + param_2 * this->mRowNum];
  }
  return 0xff;
}


/* __thiscall cDT::cDT(void) */

void __thiscall cDT::cDT(cDT *this)

{
  cDT_Format::cDT_Format(&this->mFmt);
  cDT_Name::cDT_Name(&this->mName);
  cDT_DataSrc::cDT_DataSrc(&this->mSrc);
  return;
}


/* __thiscall cDT::~cDT(void) */

void __thiscall cDT::_cDT(cDT *this)

{
  short in_r4;
  
  if (this != (cDT *)0x0) {
    cDT_DataSrc::_cDT_DataSrc(&this->mSrc);
    cDT_Name::_cDT_Name(&this->mName);
    cDT_Format::_cDT_Format(&this->mFmt);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall cDT::Set(unsigned long,
                       char * *,
                       unsigned long,
                       char * *,
                       unsigned char *) */

void __thiscall
cDT::Set(cDT *this,ulong param_1,char **param_2,ulong param_3,char **param_4,byte *param_5)

{
  cDT_NamePTbl::Set((cDT_NamePTbl *)this,param_1,param_2);
  cDT_NamePTbl::Set((cDT_NamePTbl *)&this->mName,param_3,param_4);
  cDT_DataSrc::Set(&this->mSrc,param_1,param_3,param_5);
  return;
}


/* __thiscall cDT::GetInf(int,
                          int) const */

uint __thiscall cDT::GetInf(cDT *this,int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = cDT_DataSrc::GetInf(&this->mSrc,param_1,param_2);
  return uVar1;
}

