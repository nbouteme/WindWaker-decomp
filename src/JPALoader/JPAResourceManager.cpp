#include <JPALoader/JPAResourceManager.h>
#include <JKernel/JKRHeap.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <JPALoader/JPATexture.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JPALoader/JPAEmitterLoader.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <JUtility/JUTTexture.h>
#include <JPATextureResource.h>
#include <JPAEmitterResource.h>
#include <JPAResourceManager.h>


/* __thiscall JPATextureResource::JPATextureResource(unsigned long,
                                                     JKRHeap *) */

void __thiscall
JPATextureResource::JPATextureResource(JPATextureResource *this,ulong texNum,JKRHeap *pHeap)

{
  JPATexture **ppJVar1;
  ulong uVar2;
  
  (this->mDefaultTexture).mpImgBuf = (byte *)0x0;
  this->mTexNum = 0;
  this->mTexCapacity = texNum;
  ppJVar1 = (JPATexture **)JKernel::operator_new__(this->mTexCapacity << 2,pHeap,0);
  this->mpTexArray = ppJVar1;
  if (this->mpTexArray == (JPATexture **)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"JPAResourceManager.cpp",0x18,"pTexResArray");
    m_Do_printf::OSPanic("JPAResourceManager.cpp",0x18,&DAT_8036663c);
  }
  JPADefaultTexture::initialize(&this->mDefaultTexture,pHeap);
  return;
}


/* __thiscall JPATextureResource::registration(JPATexture *) */

void __thiscall JPATextureResource::registration(JPATextureResource *this,JPATexture *pTexture)

{
  ulong uVar1;
  
  if ((uint)this->mTexCapacity <= (uint)this->mTexNum) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JPAResourceManager.cpp",0x4c,"registNum < maxNum");
    m_Do_printf::OSPanic("JPAResourceManager.cpp",0x4c,&DAT_8036663c);
  }
  this->mpTexArray[this->mTexNum] = pTexture;
  this->mTexNum = this->mTexNum + 1;
  return;
}


/* __thiscall JPAEmitterResource::JPAEmitterResource(unsigned long,
                                                     JKRHeap *) */

void __thiscall
JPAEmitterResource::JPAEmitterResource(JPAEmitterResource *this,ulong capacity,JKRHeap *pHeap)

{
  JPAEmitterData **ppJVar1;
  ulong uVar2;
  
  this->mEmitterNum = 0;
  this->mEmitterCapacity = capacity;
  ppJVar1 = (JPAEmitterData **)JKernel::operator_new__(this->mEmitterCapacity << 2,pHeap,0);
  this->mpEmitterDataArray = ppJVar1;
  if (this->mpEmitterDataArray == (JPAEmitterData **)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"JPAResourceManager.cpp",0x5d,"pEmtrResArray");
    m_Do_printf::OSPanic("JPAResourceManager.cpp",0x5d,&DAT_8036663c);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall JPAEmitterResource::registration(JPAEmitterData *,
                                               unsigned short) */

void __thiscall
JPAEmitterResource::registration(JPAEmitterResource *this,JPAEmitterData *param_1,ushort param_2)

{
  ulong uVar1;
  
  if ((uint)this->mEmitterCapacity <= (uint)this->mEmitterNum) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JPAResourceManager.cpp",0x6b,"registNum < maxNum");
    m_Do_printf::OSPanic("JPAResourceManager.cpp",0x6b,&DAT_8036663c);
  }
  if ((uint)this->mEmitterNum < (uint)this->mEmitterCapacity) {
    param_1->mUserIndex = param_2;
    this->mpEmitterDataArray[this->mEmitterNum] = param_1;
  }
  this->mEmitterNum = this->mEmitterNum + 1;
  return;
}


/* __thiscall JPAEmitterResource::getByUserIndex(unsigned short) */

JPAEmitterData * __thiscall
JPAEmitterResource::getByUserIndex(JPAEmitterResource *this,ushort param_1)

{
  int iVar1;
  int iVar2;
  JPAEmitterData *pJVar3;
  
  iVar1 = 0;
  iVar2 = this->mEmitterNum;
  while( true ) {
    if (iVar2 == 0) {
      return (JPAEmitterData *)0x0;
    }
    pJVar3 = *(JPAEmitterData **)((int)this->mpEmitterDataArray + iVar1);
    if (param_1 == pJVar3->mUserIndex) break;
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + -1;
  }
  return pJVar3;
}


/* __thiscall JPAEmitterResource::checkUserIndexDuplication(unsigned short) */

undefined4 __thiscall
JPAEmitterResource::checkUserIndexDuplication(JPAEmitterResource *this,ushort param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = this->mEmitterNum;
  while( true ) {
    if (iVar2 == 0) {
      return 0;
    }
    if (param_1 == *(ushort *)(*(int *)((int)this->mpEmitterDataArray + iVar1) + 6)) break;
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + -1;
  }
  return 1;
}


/* __thiscall JPAResourceManager::JPAResourceManager(void const *,
                                                     JKRHeap *) */

void __thiscall
JPAResourceManager::JPAResourceManager(JPAResourceManager *this,void *param_1,JKRHeap *param_2)

{
  JKRHeap *pJVar1;
  
  pJVar1 = JKRHeap::sCurrentHeap;
  if (param_2 != (JKRHeap *)0x0) {
    pJVar1 = param_2;
  }
  this->mpHeap = pJVar1;
  JPAEmitterArchiveLoaderDataBase::load
            (param_1,this->mpHeap,&this->mpEmitterResource,&this->mpTextureResource);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall JPAResourceManager::swapTexture(ResTIMG const *,
                                              char const *) */

void __thiscall
JPAResourceManager::swapTexture(JPAResourceManager *this,ResTIMG *param_1,char *param_2)

{
  char *__s2;
  int iVar1;
  JUTTexture *this_00;
  uint uVar2;
  int iVar3;
  
  uVar2 = 0;
  iVar3 = 0;
  while( true ) {
    if ((uint)this->mpTextureResource->mTexNum <= uVar2) {
      return;
    }
    __s2 = (char *)(**(code **)(**(int **)((int)this->mpTextureResource->mpTexArray + iVar3) + 0xc))
                             ();
    iVar1 = MSL_C.PPCEABI.bare.H::strcmp(param_2,__s2);
    if (iVar1 == 0) break;
    uVar2 = uVar2 + 1;
    iVar3 = iVar3 + 4;
  }
  this_00 = (JUTTexture *)
            (**(code **)(**(int **)((int)this->mpTextureResource->mpTexArray + iVar3) + 0x14))();
  JUTTexture::storeTIMG(this_00,param_1,'\0');
  return;
}

