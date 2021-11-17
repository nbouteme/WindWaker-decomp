#include <DynamicLink.h>
#include <DynamicLink.h>
#include <JKernel/JKRHeap.h>
#include <os/OSThread.h>
#include <m_Do_printf.h>
#include <JUtility/JUTAssert.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JUtility/JUTConsole.h>
#include <m_Do_ext.h>
#include <JKernel/JKRFileCache.h>
#include <JKernel/JKRArchivePub.h>
#include <MSL_C.PPCEABI.bare.H/printf.h>
#include <JKernel/JKRFileLoader.h>
#include <JKernel/JKRDvdRipper.h>
#include <m_Do_dvd_thread.h>
#include <os/OSTime.h>
#include <os/OSLink.h>
#include <os/OSContext.h>
#include <DynamicModuleControl.h>
#include <DynamicModuleControlBase.h>
#include <Demangler/JKRArchive.h>

undefined1 DynamicModuleControlBase;
undefined1 DynamicModuleControlBase;
undefined1 DynamicModuleControl;
undefined1 DynamicModuleControl;
undefined1 DynamicModuleControl;

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall DynamicModuleControlBase::~DynamicModuleControlBase(void) */

void __thiscall DynamicModuleControlBase::_DynamicModuleControlBase(DynamicModuleControlBase *this)

{
  short in_r4;
  
  if (this != (DynamicModuleControlBase *)0x0) {
    this->vtbl = (DynamicModuleControlBase__vtbl *)&__vt;
    force_unlink(this);
    if (*(int *)&this->field_0x4 != 0) {
      *(undefined4 *)(*(int *)&this->field_0x4 + 8) = *(undefined4 *)&this->field_0x8;
    }
    if (*(int *)&this->field_0x8 != 0) {
      *(undefined4 *)(*(int *)&this->field_0x8 + 4) = *(undefined4 *)&this->field_0x4;
    }
    if (_mFirst == this) {
      _mFirst = *(DynamicModuleControlBase **)&this->field_0x8;
    }
    if (_mLast == this) {
      _mLast = *(DynamicModuleControlBase **)&this->field_0x4;
    }
    *(undefined4 *)&this->field_0x8 = 0;
    *(undefined4 *)&this->field_0x4 = 0;
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall DynamicModuleControlBase::DynamicModuleControlBase(void) */

void __thiscall DynamicModuleControlBase::DynamicModuleControlBase(DynamicModuleControlBase *this)

{
  this->vtbl = (DynamicModuleControlBase__vtbl *)&__vt;
  this->mLinkCount = 0;
  this->field_0x2 = 0;
  *(undefined4 *)&this->field_0x8 = 0;
  if (_mFirst == (DynamicModuleControlBase *)0x0) {
    _mFirst = this;
  }
  *(DynamicModuleControlBase **)&this->field_0x4 = _mLast;
  if (*(int *)&this->field_0x4 != 0) {
    *(DynamicModuleControlBase **)(*(int *)&this->field_0x4 + 8) = this;
  }
  _mLast = this;
  return;
}


/* __thiscall DynamicModuleControlBase::link(void) */

int __thiscall
DynamicModuleControlBase::link(DynamicModuleControlBase *this,char *__from,char *__to)

{
  OSThread *pOVar1;
  int iVar2;
  ulong uVar3;
  
  pOVar1 = (OSThread *)os::OSGetCurrentThread();
  if (pOVar1 != &m_Do_main::mainThread) {
    m_Do_printf::OSReport_Error("DynamicModuleControlBase::link not mainthread %08x\n");
  }
  if (this->mLinkCount == 0) {
    (*(code *)this->vtbl->do_load)(this);
    iVar2 = (*(code *)this->vtbl->do_link)(this);
    if (iVar2 == 0) {
      return 0;
    }
    if (this->field_0x2 != 0xffff) {
      this->field_0x2 = this->field_0x2 + 1;
    }
  }
  if (this->mLinkCount == 0xffff) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"DynamicLink.cpp",100,"mLinkCount < 65535");
    m_Do_printf::OSPanic("DynamicLink.cpp",100,"Halt");
  }
  if (this->mLinkCount != 0xffff) {
    this->mLinkCount = this->mLinkCount + 1;
  }
  return 1;
}


/* __thiscall DynamicModuleControlBase::unlink(void) */

int __thiscall DynamicModuleControlBase::unlink(DynamicModuleControlBase *this,char *__name)

{
  OSThread *pOVar1;
  
  pOVar1 = (OSThread *)os::OSGetCurrentThread();
  if (pOVar1 != &m_Do_main::mainThread) {
    m_Do_printf::OSReport_Error("DynamicModuleControlBase::unlink not mainthread %08x\n");
  }
  if (this->mLinkCount == 0) {
    m_Do_printf::OSReport_Warning
              ("%08x DynamicModuleControlBase::unlink() mLinkCount id already zero.\n",this);
  }
  else {
    this->mLinkCount = this->mLinkCount - 1;
    if (this->mLinkCount == 0) {
      (*(code *)this->vtbl->do_unlink)(this);
      (*(code *)this->vtbl->do_unload)(this);
    }
  }
  return 1;
}


/* __thiscall DynamicModuleControlBase::load_async(void) */

undefined4 __thiscall DynamicModuleControlBase::load_async(DynamicModuleControlBase *this)

{
  undefined4 uVar1;
  
  if (this->mLinkCount == 0) {
    uVar1 = (*(code *)this->vtbl->do_load_async)();
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


/* __thiscall DynamicModuleControlBase::force_unlink(void) */

undefined4 __thiscall DynamicModuleControlBase::force_unlink(DynamicModuleControlBase *this)

{
  if (this->mLinkCount != 0) {
    this->mLinkCount = 0;
    (*(code *)this->vtbl->do_unlink)();
  }
  return 1;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall DynamicModuleControlBase::dump(void) */

void __thiscall DynamicModuleControlBase::dump(DynamicModuleControlBase *this)

{
  short sVar1;
  short sVar2;
  int iVar3;
  undefined *puVar4;
  undefined4 uVar5;
  int iVar6;
  short *psVar7;
  
  psVar7 = _mFirst;
  iVar6 = 0;
  JUtility::JUTReportConsole_f("\nDynamicModuleControlBase::dump()\n");
  JUtility::JUTReportConsole_f("Do Ln Size      Name\n");
  for (; psVar7 != (short *)0x0; psVar7 = *(short **)(psVar7 + 4)) {
    sVar1 = psVar7[1];
    sVar2 = *psVar7;
    if ((sVar1 != 0) || (sVar2 != 0)) {
      iVar3 = (**(code **)(*(int *)(psVar7 + 6) + 0x10))(psVar7);
      puVar4 = (undefined *)(**(code **)(*(int *)(psVar7 + 6) + 0xc))(psVar7);
      if (iVar3 == -1) {
        if (puVar4 == (undefined *)0x0) {
          puVar4 = &UNK_80363c28;
        }
        uVar5 = (**(code **)(*(int *)(psVar7 + 6) + 0x14))(psVar7);
        JUtility::JUTReportConsole_f("%3d%3d ???? ????? %-4s %s\n",sVar1,sVar2,uVar5,puVar4);
      }
      else {
        if (puVar4 == (undefined *)0x0) {
          puVar4 = &UNK_80363c28;
        }
        uVar5 = (**(code **)(*(int *)(psVar7 + 6) + 0x14))(psVar7);
        JUtility::JUTReportConsole_f
                  ((double)((float)((double)CONCAT44(0x43300000,iVar3) - DynamicLink::_2628) *
                           DynamicLink::_2626),"%3d%3d%5.1f %05x %-4s %s\n",sVar1,sVar2,iVar3,uVar5,
                   puVar4);
        iVar6 = iVar6 + iVar3;
      }
      (**(code **)(*(int *)(psVar7 + 6) + 0x1c))(psVar7);
    }
  }
  JUtility::JUTReportConsole_f
            ((double)((float)((double)CONCAT44(0x43300000,iVar6) - DynamicLink::_2628) *
                     DynamicLink::_2626),"TotalSize %6.2f %06x\n\n",iVar6);
  return;
}


/* __thiscall DynamicModuleControl::DynamicModuleControl(char const *) */

void __thiscall DynamicModuleControl::DynamicModuleControl(DynamicModuleControl *this,char *name)

{
  DynamicModuleControlBase::DynamicModuleControlBase(&this->parent);
  (this->parent).vtbl = &__vt;
  this->mModule = (DynamicModule *)0x0;
  this->field_0x14 = 0;
  this->field_0x18 = 0;
  this->mpModuleName = name;
  this->mModuleType = Invalid;
  this->field_0x21 = 0;
  this->mCheckSum = 0;
  this->mDecompSize = 0;
  this->field_0x28 = 0;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall DynamicModuleControl::mountCallback(void *) */

int __thiscall DynamicModuleControl::mountCallback(DynamicModuleControl *this,void *param_1)

{
  JKRHeap *__special_file;
  char *in_r6;
  ulong in_r7;
  void *in_r8;
  
  __special_file = m_Do_ext::mDoExt_getArchiveHeap();
  _sFileCache = JKRFileCache::mount((JKRFileCache *)"/rels",(char *)__special_file,(char *)0x0,in_r6
                                    ,in_r7,in_r8);
  _sArchive = JKRArchive::mount((JKRArchive *)"RELS.arc",&DAT_00000004,(char *)__special_file,
                                &DAT_00000001,in_r7,in_r8);
  if (_sArchive == 0) {
    m_Do_printf::OSReport_Error
              ("マウント失敗ですが単にアーカイブを作ってないだけなら遅いだけです %s\n"
               ,"RELS.arc");
  }
  return _sArchive;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall DynamicModuleControl::initialize(void) */

undefined4 __thiscall DynamicModuleControl::initialize(DynamicModuleControl *this)

{
  void *in_r4;
  
  _sFileCache = 0;
  _sAllocBytes = 0;
  _sArchive = 0;
  mountCallback((DynamicModuleControl *)0x0,in_r4);
  return 1;
}


/* __thiscall DynamicModuleControl::callback(void *) */

void __thiscall DynamicModuleControl::callback(DynamicModuleControl *this,void *param_1)

{
  (*(code *)((this->parent).vtbl)->do_load)();
  return;
}


namespace DynamicLink {

/* __stdcall calcSum2(unsigned short const *,
                      unsigned long) */

int calcSum2(ushort *data,ulong size)

{
  int iVar1;
  
  iVar1 = 0;
  for (; size != 0; size = size - 2) {
    iVar1 = iVar1 + (uint)*data;
    data = data + 1;
  }
  return iVar1;
}

}

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall DynamicModuleControl::do_load(void) */

undefined4 __thiscall DynamicModuleControl::do_load(DynamicModuleControl *this)

{
  bool bVar1;
  byte bVar2;
  undefined4 uVar3;
  DynamicModule *pDVar4;
  int decompSize;
  short sVar5;
  char *pcVar6;
  JKRFileLoader *pJVar7;
  int iVar8;
  JKRFileLoader JStack88;
  
  if (this->mModule == (DynamicModule *)0x0) {
    iVar8 = 0;
    do {
      while( true ) {
        if (this->mModule != (DynamicModule *)0x0) {
          JKRHeap::free(this->mModule,(JKRHeap *)0x0);
          this->mModule = (DynamicModule *)0x0;
        }
        pcVar6 = "%s.rel";
        MSL_C.PPCEABI.bare.H::snprintf((char *)&JStack88,0x40,"%s.rel",this->mpModuleName);
        if ((this->mModule == (DynamicModule *)0x0) &&
           (pcVar6 = (char *)_sArchive, _sArchive != (JKRArchive *)0x0)) {
          pDVar4 = (DynamicModule *)
                   JKRArchive::getGlbResource(0x4d4d454d,(char *)&JStack88,_sArchive);
          this->mModule = pDVar4;
          if (this->mModule != (DynamicModule *)0x0) {
            this->mModuleType = LoadToMainRAM;
          }
          if (this->mModule == (DynamicModule *)0x0) {
            pcVar6 = (char *)_sArchive;
            pDVar4 = (DynamicModule *)
                     JKRArchive::getGlbResource(0x414d454d,(char *)&JStack88,_sArchive);
            this->mModule = pDVar4;
            if (this->mModule != (DynamicModule *)0x0) {
              this->mModuleType = LoadToARAM;
            }
          }
          if (this->mModule == (DynamicModule *)0x0) {
            pcVar6 = (char *)_sArchive;
            pDVar4 = (DynamicModule *)
                     JKRArchive::getGlbResource(0x444d454d,(char *)&JStack88,_sArchive);
            this->mModule = pDVar4;
            if (this->mModule != (DynamicModule *)0x0) {
              this->mModuleType = LoadToDVDRAM;
            }
          }
        }
        bVar1 = this->mModule == (DynamicModule *)0x0;
        if (bVar1) {
          if (bVar1) {
            MSL_C.PPCEABI.bare.H::snprintf((char *)&JStack88,0x40,"/rels/%s.rel",this->mpModuleName)
            ;
            pDVar4 = (DynamicModule *)
                     JKRDvdRipper::loadToMainRAM
                               ((char *)&JStack88,(uchar *)0x0,1,0,m_Do_ext::archiveHeap,1,0,
                                (int *)0x0);
            this->mModule = pDVar4;
            if (this->mModule != (DynamicModule *)0x0) {
              this->mDecompSize = 0;
              this->mModuleType = LoadFromDisk;
            }
          }
          if ((this->mModule == (DynamicModule *)0x0) && (_sFileCache != (int *)0x0)) {
            pJVar7 = &JStack88;
            pDVar4 = (DynamicModule *)(**(code **)(*_sFileCache + 0x18))(_sFileCache,0x72656c73);
            this->mModule = pDVar4;
            if (this->mModule != (DynamicModule *)0x0) {
              this->mDecompSize = 0;
              this->mModuleType = LoadFromCache;
              JKRFileLoader::detachResource((JKRFileLoader *)this->mModule,(void *)0x0,pJVar7);
            }
          }
        }
        else {
          decompSize = (*(code *)((_sArchive->parent).parent.vtbl)->getExpandedResSize)();
          this->mDecompSize = decompSize;
          JKRFileLoader::detachResource
                    ((JKRFileLoader *)this->mModule,(void *)0x0,(JKRFileLoader *)pcVar6);
        }
        if (this->mModule == (DynamicModule *)0x0) {
          m_Do_printf::OSReport_Error
                    ("DynamicModuleControl::do_load() リソース読み込み失敗 [%s]\n",
                     this->mpModuleName);
          return 0;
        }
        if (this->mDecompSize < 1) {
          if (this->field_0x21 != 0xff) {
            this->field_0x21 = this->field_0x21 + 1;
          }
          return 1;
        }
        sVar5 = DynamicLink::calcSum2((ushort *)this->mModule,this->mDecompSize);
        bVar2 = this->field_0x21;
        if (bVar2 != 0) break;
        this->mCheckSum = sVar5;
        this->field_0x21 = this->field_0x21 + 1;
      }
      if (sVar5 == this->mCheckSum) {
        if (bVar2 == 0xff) {
          return 1;
        }
        this->field_0x21 = bVar2 + 1;
        return 1;
      }
      m_Do_printf::OSReport_Error
                ("DynamicModuleControl::do_load() チェックサムエラー %04x %04x[%s]\n",sVar5
                 ,this->mCheckSum,this->mpModuleName);
      this->field_0x21 = 0;
      iVar8 = iVar8 + 1;
    } while (iVar8 < 3);
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}


/* __thiscall DynamicModuleControl::do_load_async(void) */

undefined4 __thiscall DynamicModuleControl::do_load_async(DynamicModuleControl *this)

{
  int iVar1;
  undefined4 uVar2;
  
  if (this->field_0x28 == 0) {
    if (this->mModule != (DynamicModule *)0x0) {
      return 1;
    }
    iVar1 = mDoDvdThd_callback_c::create(callback,this);
    this->field_0x28 = iVar1;
    if (this->field_0x28 == 0) {
      m_Do_printf::OSReport_Error
                ("DynamicModuleControl::do_load_async() 非同期読み込みコールバック登録失敗 [%s]\n"
                 ,this->mpModuleName);
    }
  }
  iVar1 = this->field_0x28;
  if ((iVar1 == 0) || (*(char *)(iVar1 + 0xc) == '\0')) {
    uVar2 = 0;
  }
  else {
    if (iVar1 != 0) {
      (**(code **)(*(int *)(iVar1 + 0x10) + 8))(iVar1,1);
    }
    this->field_0x28 = 0;
    uVar2 = 1;
  }
  return uVar2;
}


/* __thiscall DynamicModuleControl::do_unload(void) */

undefined4 __thiscall DynamicModuleControl::do_unload(DynamicModuleControl *this)

{
  if (this->mModule != (DynamicModule *)0x0) {
    JKRHeap::free(this->mModule,(JKRHeap *)0x0);
    this->mModule = (DynamicModule *)0x0;
  }
  return 1;
}


/* __thiscall DynamicModuleControl::dump2(void) */

void __thiscall DynamicModuleControl::dump2(DynamicModuleControl *this)

{
  DynamicModule *rel;
  
  rel = this->mModule;
  if (rel != (DynamicModule *)0x0) {
    m_Do_printf::OSReport
              ("mModule=%08x %08x %08x %08x %08x\n",rel,
               rel->mpSectionInfoOffset[1].mSectionOffsetAndFlag & 0xfffffffe,
               rel->mpSectionInfoOffset[1].mSectionSize,
               (int)rel->mpImpTable - (int)rel->mpRelocationTable,rel->mImpSize);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall DynamicModuleControl::do_link(void) */

undefined4 __thiscall DynamicModuleControl::do_link(DynamicModuleControl *this)

{
  uint uVar1;
  ulong uVar2;
  DynamicModule *rel;
  void *pvVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  void *pvVar7;
  char *in_r5;
  JKRHeap *this_00;
  char *in_r6;
  void *pvVar8;
  
  os::OSGetTime();
  if (this->mModule == (DynamicModule *)0x0) {
    (*(code *)((this->parent).vtbl)->do_load)(this);
  }
  if (this->mModule != (DynamicModule *)0x0) {
    if ((DynamicModule__SectionInfo *)0x7fffffff < this->mModule->mpSectionInfoOffset) {
      uVar2 = JUTAssertion::getSDevice();
      in_r6 = "mModule->info.sectionInfoOffset < 0x80000000";
      JUTAssertion::showAssert
                (uVar2,"DynamicLink.cpp",0x265,"mModule->info.sectionInfoOffset < 0x80000000");
      in_r5 = "Halt";
      m_Do_printf::OSPanic("DynamicLink.cpp",0x265);
    }
    if (0x81ffffff < (uint)((int)&this->mModule->mModuleID + this->mModule->mFixSize)) {
      uVar2 = JUTAssertion::getSDevice();
      in_r6 = "(u32)mModule + mModule->fixSize < 0x82000000";
      JUTAssertion::showAssert
                (uVar2,"DynamicLink.cpp",0x267,"(u32)mModule + mModule->fixSize < 0x82000000");
      in_r5 = "Halt";
      m_Do_printf::OSPanic("DynamicLink.cpp",0x267);
    }
    os::OSGetTime();
    os::OSGetTime();
    rel = this->mModule;
    if (rel->mRELFormatVersion < 3) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"DynamicLink.cpp",0x2d4,"0");
      m_Do_printf::OSPanic("DynamicLink.cpp",0x2d4,"Halt");
LAB_80240eb0:
      os::OSGetTime();
      iVar4 = (*(code *)((this->parent).vtbl)->getModuleSize)(this);
      _sAllocBytes = _sAllocBytes + iVar4;
      os::OSGetTime();
      uVar6 = (*(code *)this->mModule->mpProlog)();
      this->field_0x18 = uVar6;
      os::OSGetTime();
      return 1;
    }
    pvVar8 = (void *)rel->mFixSize;
    uVar1 = (int)pvVar8 + 0x1fU & 0xffffffe0;
    iVar4 = (int)&rel->mModuleID + uVar1;
    pvVar3 = (void *)JKRHeap::getSize((JKRHeap *)rel,(void *)0x0,(JKRHeap *)in_r5);
    if ((int)pvVar3 < 0) {
      iVar4 = JKRHeap::alloc(this->mModule->mBssSize,0x20,(JKRHeap *)0x0);
      if (iVar4 == 0) {
        m_Do_printf::OSReport_Error("BSSメモリ確保失敗\n");
      }
      else {
        this->field_0x14 = iVar4;
        iVar4 = os::OSLink(this->mModule);
        if (iVar4 != 0) goto LAB_80240eb0;
        m_Do_printf::OSReport_Error("リンク失敗\n");
      }
    }
    else {
      this_00 = (JKRHeap *)this->mModule;
      pvVar7 = (void *)(&((this_00->mMutex).thread)->field_0x0 + uVar1);
      if (pvVar7 < pvVar3) {
        iVar4 = os::OSLinkFixed((DynamicModule *)this_00,iVar4);
        if (iVar4 != 0) {
          iVar4 = JKRHeap::resize((JKRHeap *)this->mModule,
                                  (void *)(&((((JKRHeap *)this->mModule)->mMutex).thread)->field_0x0
                                          + uVar1),0,(JKRHeap *)in_r6);
          if (iVar4 < 0) {
            m_Do_printf::OSReport_Error("モジュールリサイズ(縮小)失敗\n");
          }
          goto LAB_80240eb0;
        }
        m_Do_printf::OSReport_Error("リンク失敗\n");
      }
      else {
        iVar5 = JKRHeap::resize(this_00,pvVar7,0,(JKRHeap *)in_r6);
        if (iVar5 < 1) {
          iVar4 = JKRHeap::alloc(this->mModule->mBssSize,0x20,(JKRHeap *)0x0);
          if (iVar4 == 0) {
            m_Do_printf::OSReport_Error("BSSメモリ確保失敗 [%x]\n",this->mModule->mBssSize);
          }
          else {
            this->field_0x14 = iVar4;
            iVar4 = os::OSLinkFixed(this->mModule,iVar4);
            if (iVar4 != 0) {
              iVar4 = JKRHeap::resize((JKRHeap *)this->mModule,pvVar8,0,(JKRHeap *)in_r6);
              if (iVar4 < 0) {
                m_Do_printf::OSReport_Error("モジュールリサイズ(縮小)失敗\n");
              }
              goto LAB_80240eb0;
            }
            m_Do_printf::OSReport_Error("リンク失敗\n");
          }
        }
        else {
          iVar4 = os::OSLinkFixed(this->mModule,iVar4);
          if (iVar4 != 0) goto LAB_80240eb0;
          m_Do_printf::OSReport_Error("リンク失敗\n");
        }
      }
    }
  }
  this->field_0x21 = 0;
  if ((void *)this->field_0x14 != (void *)0x0) {
    JKRHeap::free((void *)this->field_0x14,(JKRHeap *)0x0);
    this->field_0x14 = 0;
  }
  if (this->mModule != (DynamicModule *)0x0) {
    JKRHeap::free(this->mModule,(JKRHeap *)0x0);
    this->mModule = (DynamicModule *)0x0;
  }
  return 0;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall DynamicModuleControl::do_unlink(void) */

undefined4 __thiscall DynamicModuleControl::do_unlink(DynamicModuleControl *this)

{
  int iVar1;
  undefined4 uVar2;
  
  os::OSGetTime();
  (*(code *)this->mModule->mpEpilog)();
  os::OSGetTime();
  iVar1 = os::OSUnlink(this->mModule);
  os::OSGetTime();
  if (iVar1 == 0) {
    m_Do_printf::OSReport_Error
              ("アンリンク失敗 mModule=%08x mBss=%08x\n",this->mModule,this->field_0x14);
    uVar2 = 0;
  }
  else {
    iVar1 = (*(code *)((this->parent).vtbl)->getModuleSize)(this);
    _sAllocBytes = _sAllocBytes - iVar1;
    if ((void *)this->field_0x14 != (void *)0x0) {
      JKRHeap::free((void *)this->field_0x14,(JKRHeap *)0x0);
      this->field_0x14 = 0;
    }
    (*(code *)((this->parent).vtbl)->do_unload)(this);
    uVar2 = 1;
  }
  return uVar2;
}


/* __thiscall DynamicModuleControl::getModuleSize(void) const */

int __thiscall DynamicModuleControl::getModuleSize(DynamicModuleControl *this)

{
  int iVar1;
  JKRHeap *in_r5;
  
  if ((JKRHeap *)this->mModule == (JKRHeap *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = JKRHeap::getSize((JKRHeap *)this->mModule,(void *)0x0,in_r5);
    if ((JKRHeap *)this->field_0x14 != (JKRHeap *)0x0) {
      JKRHeap::getSize((JKRHeap *)this->field_0x14,(void *)0x0,in_r5);
    }
    iVar1 = iVar1 + this->mModule->mBssSize;
  }
  return iVar1;
}


/* __thiscall DynamicModuleControl::getModuleTypeString(void) const */

TerminatedCString * __thiscall DynamicModuleControl::getModuleTypeString(DynamicModuleControl *this)

{
  return DynamicLink::strings_3042[this->mModuleType & 3];
}


namespace DynamicLink {

void ModuleProlog(void)

{
  return;
}


void ModuleEpilog(void)

{
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */

void ModuleUnresolved(void)

{
  bool bVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  m_Do_printf::OSReport_Error
            ("\nError: リンクされていない関数が呼び出されました.\n");
  m_Do_printf::OSReport_Error("Address:      Back Chain    LR Save\n");
  uVar3 = 0;
  puVar2 = (undefined4 *)os::OSGetStackPointer();
  while (((puVar2 != (undefined4 *)0x0 && (puVar2 != (undefined4 *)&DAT_ffffffff)) &&
         (bVar1 = uVar3 < 0x10, uVar3 = uVar3 + 1, bVar1))) {
    m_Do_printf::OSReport_Error("0x%08x:   0x%08x    0x%08x\n",puVar2,*puVar2,puVar2[1]);
    puVar2 = (undefined4 *)*puVar2;
  }
  m_Do_printf::OSReport_Error("\n");
  return;
}


void ModuleConstructorsX(void **contructors)

{
  ulong uVar1;
  
  if (contructors == (void **)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"DynamicLink.cpp",0x352,"_ctors");
    m_Do_printf::OSPanic("DynamicLink.cpp",0x352,"Halt");
  }
  for (; (code *)*contructors != (code *)0x0; contructors = (code **)contructors + 1) {
    (*(code *)*contructors)();
  }
  return;
}


void ModuleDestructorsX(void **destructors)

{
  ulong uVar1;
  
  if (destructors == (void **)0x0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"DynamicLink.cpp",0x360,"_dtors");
    m_Do_printf::OSPanic("DynamicLink.cpp",0x360,"Halt");
  }
  for (; (code *)*destructors != (code *)0x0; destructors = (code **)destructors + 1) {
    (*(code *)*destructors)();
  }
  return;
}

}

/* __thiscall DynamicModuleControlBase::do_link(void) */

undefined4 __thiscall DynamicModuleControlBase::do_link(DynamicModuleControlBase *this)

{
  return 1;
}


/* __thiscall DynamicModuleControlBase::do_load(void) */

undefined4 __thiscall DynamicModuleControlBase::do_load(DynamicModuleControlBase *this)

{
  return 1;
}


/* __thiscall DynamicModuleControlBase::do_unload(void) */

undefined4 __thiscall DynamicModuleControlBase::do_unload(DynamicModuleControlBase *this)

{
  return 1;
}


/* __thiscall DynamicModuleControlBase::do_unlink(void) */

undefined4 __thiscall DynamicModuleControlBase::do_unlink(DynamicModuleControlBase *this)

{
  return 1;
}


/* __thiscall DynamicModuleControlBase::do_load_async(void) */

undefined4 __thiscall DynamicModuleControlBase::do_load_async(DynamicModuleControlBase *this)

{
  return 1;
}


/* __thiscall DynamicModuleControlBase::dump2(void) */

void __thiscall DynamicModuleControlBase::dump2(DynamicModuleControlBase *this)

{
  return;
}


/* __thiscall DynamicModuleControlBase::getModuleTypeString(void) const */

char * __thiscall DynamicModuleControlBase::getModuleTypeString(DynamicModuleControlBase *this)

{
  return "Base";
}


/* __thiscall DynamicModuleControlBase::getModuleSize(void) const */

undefined4 __thiscall DynamicModuleControlBase::getModuleSize(DynamicModuleControlBase *this)

{
  return 0;
}


/* __thiscall DynamicModuleControl::getModuleName(void) const */

char * __thiscall DynamicModuleControl::getModuleName(DynamicModuleControl *this)

{
  return this->mpModuleName;
}


/* __thiscall JKRArchive::getExpandedResSize(void const *) const */

void __thiscall JKRArchive::getExpandedResSize(JKRArchive *this,void *param_1)

{
  (*(code *)((this->parent).parent.vtbl)->getResSize)();
  return;
}

