#include <c_dylink.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <m_Do_ext.h>
#include <JKernel/JKRSolidHeap.h>
#include <JKernel/JKRHeap.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <DynamicLink.h>
#include <JKernel/JKRFileCache.h>
#include <JKernel/JKRFileLoader.h>
#include <os/OSLink.h>
#include <c_dylink.h>
#include <m_Do_dvd_thread.h>
#include <d_com_lib_game.h>
#include <DynamicModuleControl.h>
#include <DynamicModuleControlBase.h>
#include <cDylPhs.h>


namespace c_dylink {
struct DynamicModuleControl * DMC[501];
undefined1 DMC_initialized;
undefined4 cDyl_Initialized;
undefined4 cDyl_DVD;

/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* __stdcall cCc_Init(void) */

undefined4 cCc_Init(void)

{
  ulong uVar1;
  JKRHeap *pJVar2;
  JKRSolidHeap *this;
  char *__s2;
  int iVar3;
  DynamicModuleControl *this_00;
  uint uVar4;
  int iVar5;
  int iVar6;
  ushort *puVar7;
  uint uVar8;
  
  if (DMC_initialized != '\0') {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"c_dylink.cpp",0x2a,"!DMC_initialized");
    m_Do_printf::OSPanic("c_dylink.cpp",0x2a,"Halt");
  }
  pJVar2 = m_Do_ext::mDoExt_getArchiveHeap();
  this = JKRSolidHeap::create(0x5648,pJVar2,false);
  pJVar2 = (JKRHeap *)JKRHeap::becomeCurrentHeap(&this->parent);
  FUN_800033a8((int)DMC,0,0x7d8);
  uVar8 = 0;
  iVar6 = 0;
  do {
    puVar7 = (ushort *)((int)&DynamicNameTable[0].mPName + iVar6);
    if (*(int *)((int)&DynamicNameTable[0].mRelFilename + iVar6) != 0) {
      if (0x1f5 < *puVar7) {
        uVar1 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert
                  (uVar1,"c_dylink.cpp",0x39,"d.mKey < (sizeof(DMC) / sizeof(DMC[0]))");
        m_Do_printf::OSPanic("c_dylink.cpp",0x39,"Halt");
      }
      if (DMC[(short)*puVar7] != (DynamicModuleControl *)0x0) {
        uVar1 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar1,"c_dylink.cpp",0x3a,"DMC[d.mKey] == 0");
        m_Do_printf::OSPanic("c_dylink.cpp",0x3a,"Halt");
      }
      uVar4 = 0;
      iVar5 = 0;
      do {
        if (*(int *)((int)DMC + iVar5) != 0) {
          __s2 = (char *)(**(code **)(*(int *)(*(int *)((int)DMC + iVar5) + 0xc) + 0xc))();
          iVar3 = MSL_C.PPCEABI.bare.H::strcmp
                            (*(char **)((int)&DynamicNameTable[0].mRelFilename + iVar6),__s2);
          if (iVar3 == 0) {
            DMC[(short)*puVar7] = *(DynamicModuleControl **)((int)DMC + iVar5);
            break;
          }
        }
        uVar4 = uVar4 + 1;
        iVar5 = iVar5 + 4;
      } while (uVar4 < 0x1f6);
      if (DMC[(short)*puVar7] == (DynamicModuleControl *)0x0) {
        this_00 = (DynamicModuleControl *)JKernel::operator_new(0x2c);
        if (this_00 != (DynamicModuleControl *)0x0) {
          ::DynamicModuleControl::DynamicModuleControl
                    (this_00,*(char **)((int)&DynamicNameTable[0].mRelFilename + iVar6));
        }
        DMC[(short)*puVar7] = this_00;
      }
    }
    uVar8 = uVar8 + 1;
    iVar6 = iVar6 + 8;
    if (0x1ad < uVar8) {
      JKRSolidHeap::adjustSize(this);
      JKRHeap::becomeCurrentHeap(pJVar2);
      DMC_initialized = 1;
      return 1;
    }
  } while( true );
}


/* __stdcall cDyl_IsLinked(short) */

bool cDyl_IsLinked(short param_1)

{
  ulong uVar1;
  bool bVar2;
  
  if (cDyl_Initialized == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"c_dylink.cpp",0xae,"cDyl_Initialized");
    m_Do_printf::OSPanic("c_dylink.cpp",0xae,"Halt");
  }
  if (DMC[param_1] == (DynamicModuleControl *)0x0) {
    bVar2 = true;
  }
  else {
    bVar2 = (DMC[param_1]->parent).mLinkCount != 0;
  }
  return bVar2;
}


/* __stdcall cDyl_Unlink(short) */

int cDyl_Unlink(ushort param_1,char *param_2)

{
  ulong uVar1;
  int iVar2;
  char *extraout_r4;
  char *extraout_r4_00;
  
  if (cDyl_Initialized == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"c_dylink.cpp",0xc5,"cDyl_Initialized");
    m_Do_printf::OSPanic("c_dylink.cpp",0xc5,"Halt");
    param_2 = extraout_r4;
  }
  if (0x1f5 < param_1) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar1,"c_dylink.cpp",0xc6,"i_ProfName < (sizeof(DMC) / sizeof(DMC[0]))");
    m_Do_printf::OSPanic("c_dylink.cpp",0xc6,"Halt");
    param_2 = extraout_r4_00;
  }
  if (DMC[(short)param_1] == (DynamicModuleControl *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = ::DynamicModuleControlBase::unlink(&DMC[(short)param_1]->parent,param_2);
  }
  return iVar2;
}


/* __stdcall cDyl_LinkASync(short) */

undefined4 cDyl_LinkASync(ushort param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  int iVar3;
  char *in_r5;
  DynamicModuleControl *this;
  undefined8 uVar4;
  
  if (DMC_initialized == '\0') {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"c_dylink.cpp",0x101,"DMC_initialized");
    in_r5 = "Halt";
    m_Do_printf::OSPanic("c_dylink.cpp",0x101);
  }
  if (cDyl_Initialized == 0) {
    uVar2 = 0;
  }
  else {
    if (param_1 < 0x1f6) {
      if (param_1 >= 0x1f6) {
        uVar1 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert
                  (uVar1,"c_dylink.cpp",0x111,"i_ProfName < (sizeof(DMC) / sizeof(DMC[0]))");
        in_r5 = "Halt";
        m_Do_printf::OSPanic("c_dylink.cpp",0x111);
      }
      this = DMC[(short)param_1];
      if (this == (DynamicModuleControl *)0x0) {
        uVar2 = 4;
      }
      else {
        if (cDyl_Initialized == 0) {
          uVar1 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar1,"c_dylink.cpp",0x115,"cDyl_Initialized");
          in_r5 = "Halt";
          m_Do_printf::OSPanic("c_dylink.cpp",0x115);
        }
        uVar4 = ::DynamicModuleControlBase::load_async(&this->parent);
        if ((int)((ulonglong)uVar4 >> 0x20) == 0) {
          uVar2 = 0;
        }
        else {
          iVar3 = ::DynamicModuleControlBase::link(&this->parent,(char *)uVar4,in_r5);
          if (iVar3 == 0) {
            m_Do_printf::OSReport_Error
                      ("cDyl_LinkASync: リンクに失敗しました。諦めます\n");
            uVar2 = 5;
          }
          else {
            uVar2 = 4;
          }
        }
      }
    }
    else {
      m_Do_printf::OSReport_Error("cDyl_Link i_ProfName=%d\n");
      uVar2 = 5;
    }
  }
  return uVar2;
}


/* __stdcall cDyl_InitCallback(void *) */

undefined4 cDyl_InitCallback(void)

{
  ulong uVar1;
  JKRHeap *__special_file;
  DynamicModuleControl *this;
  JKRFileLoader *this_00;
  char *__from;
  JKRFileLoader *__to;
  char *in_r6;
  ulong in_r7;
  void *in_r8;
  DynamicModuleControl DStack56;
  
  if (cDyl_Initialized != 0) {
    uVar1 = JUTAssertion::getSDevice();
    in_r6 = "!cDyl_Initialized";
    JUTAssertion::showAssert(uVar1,"c_dylink.cpp",0x12f,"!cDyl_Initialized");
    m_Do_printf::OSPanic("c_dylink.cpp",0x12f,"Halt");
  }
  __special_file = m_Do_ext::mDoExt_getArchiveHeap();
  __to = (JKRFileLoader *)0x0;
  this = (DynamicModuleControl *)
         JKRFileCache::mount((JKRFileCache *)"/",(char *)__special_file,(char *)0x0,in_r6,in_r7,
                             in_r8);
  ::DynamicModuleControl::initialize(this);
  this_00 = (JKRFileLoader *)JKRFileLoader::getGlbResource("/dvd/framework.str");
  JKRFileLoader::detachResource(this_00,this,__to);
  (**(code **)(*(int *)&this->parent + 0xc))(this);
  os::OSSetStringTable(this_00);
  __from = "f_pc_profile_lst";
  ::DynamicModuleControl::DynamicModuleControl(&DStack56,"f_pc_profile_lst");
  ::DynamicModuleControlBase::link(&DStack56.parent,__from,(char *)__to);
  cDyl_Initialized = 1;
  DStack56.parent.vtbl = &::DynamicModuleControl::__vt;
  ::DynamicModuleControlBase::_DynamicModuleControlBase(&DStack56.parent);
  return 1;
}


/* __stdcall cDyl_InitAsync(void) */

void cDyl_InitAsync(void)

{
  ulong uVar1;
  
  cCc_Init();
  if (cDyl_DVD != 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"c_dylink.cpp",0x145,"cDyl_DVD == 0");
    m_Do_printf::OSPanic("c_dylink.cpp",0x145,"Halt");
  }
  cDyl_DVD = mDoDvdThd_callback_c::create(cDyl_InitCallback,(void *)0x0);
  return;
}


/* __stdcall cDyl_InitAsyncIsDone(void) */

undefined4 cDyl_InitAsyncIsDone(void)

{
  undefined4 uVar1;
  
  if (cDyl_DVD == 0) {
    uVar1 = 1;
  }
  else {
    if (*(char *)(cDyl_DVD + 0xc) == '\0') {
      uVar1 = 0;
    }
    else {
      if (cDyl_DVD != 0) {
        (**(code **)(*(int *)(cDyl_DVD + 0x10) + 8))(cDyl_DVD,1);
      }
      cDyl_DVD = 0;
      uVar1 = 1;
    }
  }
  return uVar1;
}

}

/* __thiscall cDylPhs::phase_01(void *) */

undefined4 __thiscall cDylPhs::phase_01(cDylPhs *this,void *param_1)

{
  return 2;
}


/* __thiscall cDylPhs::phase_02(short *) */

int __thiscall cDylPhs::phase_02(cDylPhs *this,short *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = c_dylink::cDyl_LinkASync(*(ushort *)this);
  iVar1 = 2;
  if (iVar2 != 4) {
    iVar1 = iVar2;
  }
  return iVar1;
}


/* __thiscall cDylPhs::phase_03(void *) */

undefined4 __thiscall cDylPhs::phase_03(cDylPhs *this,void *param_1)

{
  return 0;
}


/* __thiscall cDylPhs::Link(request_of_phase_process_class *,
                            short) */

undefined4 __thiscall
cDylPhs::Link(cDylPhs *this,request_of_phase_process_class *param_1,short param_2)

{
  undefined4 uVar1;
  undefined2 local_8 [4];
  
  local_8[0] = SUB42(param_1,0);
  if (*(int *)(this + 4) == 2) {
    uVar1 = 4;
  }
  else {
    uVar1 = d_com_lib_game::dComLbG_PhaseHandler
                      ((request_of_phase_process_class *)this,
                       (cPhs__Handler *)&c_dylink::l_method_2679,local_8);
  }
  return uVar1;
}


/* __thiscall cDylPhs::Unlink(request_of_phase_process_class *,
                              short) */

int __thiscall cDylPhs::Unlink(cDylPhs *this,request_of_phase_process_class *param_1,short param_2)

{
  ulong uVar1;
  int iVar2;
  request_of_phase_process_class *extraout_r4;
  request_of_phase_process_class *prVar3;
  
  prVar3 = param_1;
  if (*(int *)(this + 4) == 1) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"c_dylink.cpp",0x1a6,"i_phase->id != 1");
    m_Do_printf::OSPanic("c_dylink.cpp",0x1a6,"Halt");
    prVar3 = extraout_r4;
  }
  if (*(int *)(this + 4) == 2) {
    iVar2 = c_dylink::cDyl_Unlink((ushort)param_1,(char *)prVar3);
    *(undefined4 *)(this + 4) = 0;
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}


/* __thiscall DynamicModuleControlBase::getModuleName(void) const */

undefined4 __thiscall DynamicModuleControlBase::getModuleName(DynamicModuleControlBase *this)

{
  return 0;
}


/* __thiscall DynamicModuleControl::~DynamicModuleControl(void) */

void __thiscall DynamicModuleControl::_DynamicModuleControl(DynamicModuleControl *this)

{
  short in_r4;
  
  if (this != (DynamicModuleControl *)0x0) {
    (this->parent).vtbl = &__vt;
    DynamicModuleControlBase::_DynamicModuleControlBase(&this->parent);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}

