#include <JUtility/JUTResource.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JSupport/JSUInputStream.h>
#include <JUtility/JUTResource.h>
#include <JKernel/JKRArchivePub.h>
#include <JKernel/JKRFileLoader.h>
#include <JUTResReference.h>


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JUTResReference::getResource(JSUInputStream *,
                                           unsigned long,
                                           JKRArchive *) */

void __thiscall
JUTResReference::getResource
          (JUTResReference *this,JSUInputStream *param_1,ulong param_2,JKRArchive *param_3)

{
  JUTResReference JVar1;
  
  JSUInputStream::read(param_1,this,1);
  JSUInputStream::read(param_1,this + 1,1);
  JSUInputStream::read(param_1,this + 2,(uint)(byte)this[1]);
  JVar1 = *this;
  if (((JVar1 == (JUTResReference)0x2) || (JVar1 == (JUTResReference)0x3)) ||
     (JVar1 == (JUTResReference)0x4)) {
    this[(byte)this[1] + 2] = (JUTResReference)0x0;
  }
  getResource(this,param_2,param_3);
  return;
}


/* __thiscall JUTResReference::getResource(unsigned long,
                                           JKRArchive *) */

int __thiscall JUTResReference::getResource(JUTResReference *this,ulong param_1,JKRArchive *param_2)

{
  JUTResReference JVar1;
  int iVar2;
  
  iVar2 = 0;
  JVar1 = *this;
  if (JVar1 == (JUTResReference)0x3) {
    iVar2 = JKRFileLoader::getGlbResource((char *)(this + 2),&param_2->parent);
  }
  else {
    if ((byte)JVar1 < 3) {
      if ((JVar1 != (JUTResReference)0x1) && (JVar1 != (JUTResReference)0x0)) {
        iVar2 = JKRArchive::getGlbResource(param_1,(char *)(this + 2),param_2);
      }
    }
    else {
      if ((byte)JVar1 < 5) {
        iVar2 = JKRFileLoader::getGlbResource((char *)(this + 2));
      }
    }
  }
  return iVar2;
}

