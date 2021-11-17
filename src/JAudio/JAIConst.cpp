#include <JAudio/JAIConst.h>
#include <m_Do_printf.h>
#include <JUtility/JUTAssert.h>
#include <JKernel/JKRHeap.h>
#include <JAudio/JASDvdThread.h>
#include <JKernel/JKRDvdRipper.h>
#include <JMath/random.h>
#include <JAInter.h>


namespace JAInter {

namespace Const {
undefined1 nullCamera;
undefined1 nullActor;
undefined1 camMtx;
undefined1 camTrans;
undefined1 camPreTrans;
undefined1 random;
}
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall JAInter::transInitDataFile(unsigned char *,
                                         unsigned long) */

void __thiscall JAInter::transInitDataFile(JAInter *this,uchar *param_1,ulong param_2)

{
  JAInter *pJVar1;
  
  if ((_msCurrentHeap == 0) &&
     (m_Do_printf::OSReport
                ("JAIBasicのカレントヒープがありません（mCurrentHeap==NULL）\n"),
     _msCurrentHeap == 0)) {
    JUTAssertion::showAssert(3,"JAIBasic.h",0x94,"msCurrentHeap");
    m_Do_printf::OSPanic("JAIBasic.h",0x94,&DAT_80368f1d);
  }
  pJVar1 = (JAInter *)JKernel::operator_new__(param_1,_msCurrentHeap,0x20);
  if ((pJVar1 != (JAInter *)0x0) && (param_1 != (uchar *)0x0)) {
    do {
      *pJVar1 = *this;
      pJVar1 = pJVar1 + 1;
      this = this + 1;
      param_1 = param_1 + -1;
    } while (param_1 != (uchar *)0x0);
  }
  return;
}


/* __thiscall JAInter::loadTmpDVDFile(char *,
                                      unsigned char * *) */

void __thiscall JAInter::loadTmpDVDFile(JAInter *this,char *param_1,uchar **param_2)

{
  ulong size;
  void *pvVar1;
  int iVar2;
  
  size = JASystem::Dvd::checkFile((Dvd *)this,param_1);
  if (size == 0) {
    *(undefined4 *)param_1 = 0;
  }
  else {
    pvVar1 = JKRHeap::alloc(JAudio::JASDram,size,-0x20);
    *(void **)param_1 = pvVar1;
    if ((*(int *)param_1 == 0) &&
       (m_Do_printf::OSReport("JAIBasic::loadTmpDVDFile Cannot Alloc Heap!!\n"),
       *(int *)param_1 == 0)) {
      JUTAssertion::showAssert(3,"JAIConst.cpp",0x71,"(*tmpPointer)");
      m_Do_printf::OSPanic("JAIConst.cpp",0x71,&DAT_80368f1d);
    }
    iVar2 = JKRDvdRipper::loadToMainRAM
                      ((char *)this,*(uchar **)param_1,0,0,(JKRHeap *)0x0,1,0,(int *)0x0);
    if (iVar2 == 0) {
      *(undefined4 *)param_1 = 0;
    }
  }
  return;
}


/* __thiscall JAInter::deleteTmpDVDFile(unsigned char * *) */

void __thiscall JAInter::deleteTmpDVDFile(JAInter *this,uchar **param_1)

{
  if (*(int *)this != 0) {
    JKRHeap::freeTail(JAudio::JASDram);
  }
  return;
}


/* __thiscall JAInter::routeToTrack(unsigned long) */

uint __thiscall JAInter::routeToTrack(JAInter *this,ulong param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  uVar1 = (uint)this & 0xf0000000;
  if (uVar1 == 0) {
    return 0;
  }
  if (uVar1 == 0x10000000) {
    uVar2 = 0xf;
  }
  else {
    if (uVar1 == 0x20000000) {
      uVar2 = 0xff;
    }
  }
  return (uint)this & uVar2;
}


namespace JAudio {

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __sinit_JAIConst_cpp(void)

{
  _nullCamera = &::JAInter::Const::camTrans;
  DAT_803ed054 = &::JAInter::Const::camPreTrans;
  DAT_803ed058 = &::JAInter::Const::camMtx;
  _nullActor = 0;
  DAT_803ed060 = 0;
  DAT_803ed064 = 0;
  DAT_803ed068 = 0;
  JKernel::JMath::TRandom_fast_::TRandom_fast_((TRandom_fast_ *)&::JAInter::Const::random,0);
  return;
}

