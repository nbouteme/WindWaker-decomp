#include <JKernel/JKRFileLoader.h>
#include <JKernel/JKRDisposer.h>
#include <JSupport/JSUList.h>
#include <JKernel/JKRHeap.h>
#include <JKernel/JKRFileLoader.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <JKRFileLoader.h>
#include <JSUList<JKRFileLoader>.h>

struct JSUPtrList JKRFileLoader;
undefined1 JKRFileLoader;

/* __thiscall JKRFileLoader::JKRFileLoader(void) */

void __thiscall JKRFileLoader::JKRFileLoader(JKRFileLoader *this)

{
  JKRDisposer::JKRDisposer(&this->parent);
  (this->parent).vtbl = (JKRArchive__vtbl *)&__vt;
  JSUPtrLink::JSUPtrLink(&this->mVolumeLink,this);
  this->field_0x28 = 0;
  this->field_0x2c = 0;
  this->field_0x34 = 0;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JKRFileLoader::~JKRFileLoader(void) */

void __thiscall JKRFileLoader::_JKRFileLoader(JKRFileLoader *this)

{
  short in_r4;
  
  if (this != (JKRFileLoader *)0x0) {
    (this->parent).vtbl = (JKRArchive__vtbl *)&__vt;
    if (_sCurrentVolume == this) {
      _sCurrentVolume = (JKRFileLoader *)0x0;
    }
    if (this != (JKRFileLoader *)0xffffffe8) {
      JSUPtrLink::_JSUPtrLink(&this->mVolumeLink);
    }
    JKRDisposer::_JKRDisposer(&this->parent);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall JKRFileLoader::unmount(void) */

void __thiscall JKRFileLoader::unmount(JKRFileLoader *this)

{
  int iVar1;
  
  if (this->field_0x34 != 0) {
    iVar1 = this->field_0x34 + -1;
    this->field_0x34 = iVar1;
    if ((iVar1 == 0) && (this != (JKRFileLoader *)0x0)) {
      (*(code *)((this->parent).vtbl)->_)(this,1);
    }
  }
  return;
}


namespace JKRFileLoader {

/* __thiscall getGlbResource(char const *) */

undefined4 getGlbResource(char *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  char *local_8 [2];
  
  local_8[0] = param_1;
  piVar1 = (int *)findVolume(local_8);
  if (piVar1 == (int *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = (**(code **)(*piVar1 + 0x14))(piVar1,local_8[0]);
  }
  return uVar2;
}


/* __thiscall getGlbResource(char const *,
                                            JKRFileLoader *) */

int getGlbResource(char *param_1,JKRFileLoader *param_2)

{
  int iVar1;
  JSUPtrLink *pJVar2;
  
  iVar1 = 0;
  pJVar2 = sVolumeList.mpHead;
  if (param_2 == (JKRFileLoader *)0x0) {
    while ((pJVar2 != (JSUPtrLink *)0x0 &&
           (iVar1 = (**(code **)(*(int *)pJVar2->mpData + 0x18))(pJVar2->mpData,0,param_1),
           iVar1 == 0))) {
      pJVar2 = pJVar2->mpNext;
    }
  }
  else {
    iVar1 = (*(code *)((param_2->parent).vtbl)->getResource2)(param_2,0,param_1);
  }
  return iVar1;
}


/* __thiscall removeResource(void *,
                                            JKRFileLoader *) */

undefined4 removeResource(void *param_1,JKRFileLoader *param_2)

{
  undefined4 uVar1;
  char cVar2;
  JSUPtrLink *pJVar3;
  
  pJVar3 = sVolumeList.mpHead;
  if (param_2 == (JKRFileLoader *)0x0) {
    for (; pJVar3 != (JSUPtrLink *)0x0; pJVar3 = pJVar3->mpNext) {
      cVar2 = (**(code **)(*(int *)pJVar3->mpData + 0x28))(pJVar3->mpData,param_1);
      if (cVar2 != '\0') {
        return 1;
      }
    }
    uVar1 = 0;
  }
  else {
    uVar1 = (*(code *)((param_2->parent).vtbl)->removeResource)(param_2,param_1);
  }
  return uVar1;
}

}

/* __thiscall JKRFileLoader::detachResource(void *,
                                            JKRFileLoader *) */

undefined4 __thiscall
JKRFileLoader::detachResource(JKRFileLoader *this,void *param_1,JKRFileLoader *param_2)

{
  undefined4 uVar1;
  char cVar2;
  JSUPtrLink *pLink;
  
  pLink = sVolumeList.mpHead;
  if (param_1 == (void *)0x0) {
    for (; pLink != (JSUPtrLink *)0x0; pLink = pLink->mpNext) {
      cVar2 = (**(code **)(*(int *)pLink->mpData + 0x2c))(pLink->mpData,this);
      if (cVar2 != '\0') {
        return 1;
      }
    }
    uVar1 = 0;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    uVar1 = (**(code **)(*param_1 + 0x2c))(param_1,this);
  }
  return uVar1;
}


namespace JKRFileLoader {

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall findVolume(char const * *) */

int findVolume(char **param_1)

{
  char *pcVar1;
  int iVar2;
  undefined *puVar3;
  JSUPtrLink *pJVar4;
  char acStack280 [276];
  
  puVar3 = _sCurrentVolume;
  if (**param_1 == '/') {
    pcVar1 = fetchVolumeName(acStack280,0x101,*param_1);
    *param_1 = pcVar1;
    for (pJVar4 = sVolumeList.mpHead; pJVar4 != (JSUPtrLink *)0x0; pJVar4 = pJVar4->mpNext) {
      iVar2 = MSL_C.PPCEABI.bare.H::strcmp(acStack280,*(char **)(pJVar4->mpData + 0x28));
      if (iVar2 == 0) {
        return (int)pJVar4->mpData;
      }
    }
    puVar3 = (undefined *)0x0;
  }
  return (int)puVar3;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall fetchVolumeName(char *,
                                             long,
                                             char const *) */

char * fetchVolumeName(char *param_1,long param_2,char *param_3)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  
  iVar2 = MSL_C.PPCEABI.bare.H::strcmp(param_3,"/");
  if (iVar2 == 0) {
    MSL_C.PPCEABI.bare.H::strcpy(param_1,&JKernel::rootPath_2460);
    pcVar3 = &JKernel::rootPath_2460;
  }
  else {
    for (pcVar3 = param_3 + 1; (cVar1 = *pcVar3, cVar1 != '\0' && (cVar1 != '/'));
        pcVar3 = pcVar3 + 1) {
      if (1 < param_2) {
        if ((int)cVar1 == 0xffffffff) {
          cVar1 = -1;
        }
        else {
          cVar1 = (&MSL_C.PPCEABI.bare.H::__lower_map)[(int)cVar1 & 0xff];
        }
        *param_1 = cVar1;
        param_1 = param_1 + 1;
        param_2 = param_2 + -1;
      }
    }
    *param_1 = '\0';
    if (*pcVar3 == '\0') {
      pcVar3 = &JKernel::rootPath_2460;
    }
  }
  return pcVar3;
}

}

namespace JKernel {

void __sinit_JKRFileLoader_cpp(void)

{
  JSUPtrList::initiate(&::JKRFileLoader::sVolumeList);
  Runtime.PPCEABI.H::__register_global_object
            (&::JKRFileLoader::sVolumeList,::JSUList<JKRFileLoader>::_JSUList,&_2144);
  return;
}

}

/* __thiscall JSUList<JKRFileLoader>::~JSUList(void) */

JSUList_JKRFileLoader_ * __thiscall JSUList<JKRFileLoader>::_JSUList(JSUList_JKRFileLoader_ *this)

{
  short in_r4;
  
  if ((this != (JSUList_JKRFileLoader_ *)0x0) &&
     (JSUPtrList::_JSUPtrList((JSUPtrList *)this), 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return this;
}

