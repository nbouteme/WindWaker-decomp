#include <m_Do_hostIO.h>
#include <m_Do_printf.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <m_Do_hostIO.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <JKernel/JKRHeap.h>
#include <mDoHIO_root_c.h>
#include <mDoHIO_subRoot_c.h>
#include <mDoHIO_child_c.h>


namespace m_Do_hostIO {
undefined4 mDoHIO_root;
}

/* __thiscall mDoHIO_root_c::update(void) */

void __thiscall mDoHIO_root_c::update(mDoHIO_root_c *this)

{
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall mDoHIO_subRoot_c::createChild(char const *,
                                            JORReflexible *) */

int __thiscall
mDoHIO_subRoot_c::createChild(mDoHIO_subRoot_c *this,char *name,JORReflexible *param_2)

{
  int iVar1;
  mDoHIO_subRoot_c *pRoot;
  char cVar2;
  int iVar3;
  
  iVar1 = 0;
  iVar3 = 0x40;
  do {
    if (*(JORReflexible **)((int)&this->mChild[0].mReflexible + iVar1) == param_2) {
      m_Do_printf::OSReport_Error
                (
                "危険：既に登録されているホストIOをふたたび登録しようとしています<%s>\n"
                );
      return -1;
    }
    iVar1 = iVar1 + 0x20;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  cVar2 = '\0';
  iVar1 = 0;
  iVar3 = 0x40;
  do {
    pRoot = (mDoHIO_subRoot_c *)((int)this->mChild + iVar1 + -4);
    if (pRoot->mChild[0].mReflexible == (JORReflexible *)0x0) {
      MSL_C.PPCEABI.bare.H::strncpy((char *)pRoot->mChild,name,0x18);
      *(JORReflexible **)((int)&this->mChild[0].mReflexible + iVar1) = param_2;
      return (int)cVar2;
    }
    cVar2 = cVar2 + '\x01';
    iVar1 = iVar1 + 0x20;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  m_Do_printf::OSReport_Error
            (
            "ホストIOの空きエントリがありません。登録できませんでした。\n"
            );
  return -1;
}


/* __thiscall mDoHIO_subRoot_c::deleteChild(signed char) */

void __thiscall mDoHIO_subRoot_c::deleteChild(mDoHIO_subRoot_c *this,char param_1)

{
  JORReflexible **ppJVar1;
  
  if (-1 < param_1) {
    ppJVar1 = &this->mChild[param_1 + -1].mReflexible;
    if (ppJVar1[8] == (JORReflexible *)0x0) {
      m_Do_printf::OSReport_Error
                ("危険：すでに削除されているホストIOをさらに削除しようとしています<%s>\n"
                 ,this->mChild + param_1);
    }
    else {
      ppJVar1[8] = (JORReflexible *)0x0;
    }
  }
  return;
}


namespace m_Do_hostIO {

void __sinit_m_Do_hostIO_cpp(void)

{
  mDoHIO_root = &::mDoHIO_root_c::__vt;
  mDoHIO_subRoot_c_803a5778.vtbl = (undefined *)&::mDoHIO_subRoot_c::__vt;
  Runtime.PPCEABI.H::__construct_array
            (mDoHIO_subRoot_c_803a5778.mChild,::mDoHIO_child_c::mDoHIO_child_c,
             ::mDoHIO_child_c::_mDoHIO_child_c,0x20,0x40);
  Runtime.PPCEABI.H::__register_global_object(&mDoHIO_root,::mDoHIO_root_c::_mDoHIO_root_c,&_3967);
  return;
}

}

/* __thiscall mDoHIO_root_c::~mDoHIO_root_c(void) */

void __thiscall mDoHIO_root_c::_mDoHIO_root_c(mDoHIO_root_c *this)

{
  short in_r4;
  
  if (this != (mDoHIO_root_c *)0x0) {
    *(undefined ***)this = &__vt;
    if (this != (mDoHIO_root_c *)0xfffffffc) {
      *(undefined ***)(this + 4) = &mDoHIO_subRoot_c::__vt;
      Runtime.PPCEABI.H::__destroy_arr(this + 8,mDoHIO_child_c::_mDoHIO_child_c,0x20,0x40);
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall mDoHIO_subRoot_c::~mDoHIO_subRoot_c(void) */

void __thiscall mDoHIO_subRoot_c::_mDoHIO_subRoot_c(mDoHIO_subRoot_c *this)

{
  short in_r4;
  
  if (this != (mDoHIO_subRoot_c *)0x0) {
    this->vtbl = (undefined *)&__vt;
    Runtime.PPCEABI.H::__destroy_arr(this->mChild,mDoHIO_child_c::_mDoHIO_child_c,0x20,0x40);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall mDoHIO_child_c::~mDoHIO_child_c(void) */

void __thiscall mDoHIO_child_c::_mDoHIO_child_c(mDoHIO_child_c *this)

{
  short in_r4;
  
  if ((this != (mDoHIO_child_c *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall mDoHIO_child_c::mDoHIO_child_c(void) */

void __thiscall mDoHIO_child_c::mDoHIO_child_c(mDoHIO_child_c *this)

{
  *(undefined *)&this->unk = 0;
  this->mReflexible = (JORReflexible *)0x0;
  return;
}

