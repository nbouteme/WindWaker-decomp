#include <JMessage/processor.h>
#include <JMessage/processor.h>
#include <JMessage/control.h>
#include <JKernel/JKRHeap.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JMessage/@unnamed@processor_cpp@.h>
#include <JMessage/TSequenceProcessor.h>
#include <JMessage/TProcessor.h>
#include <JMessage/TRenderingProcessor.h>


namespace JMessage {

/* __thiscall @unnamed@processor_cpp@::process_setMessageIndex_reserved_(unsigned short)
    */

undefined4 __thiscall
@unnamed@processor_cpp@::process_setMessageIndex_reserved_
          (_unnamed_processor_cpp_ *this,ushort param_1)

{
  if (((uint)this & 0xffff) != 0xffff) {
    return 0;
  }
  return 0;
}


/* __thiscall @unnamed@processor_cpp@::process_setMessage_index_(TControl *,
                                                                           unsigned short) */

uint __thiscall
@unnamed@processor_cpp@::process_setMessage_index_
          (_unnamed_processor_cpp_ *this,TControl *param_1,ushort param_2)

{
  uint uVar1;
  char cVar2;
  
  if (((uint)param_1 & 0xffff) < 0xff00) {
    *(ushort *)(this + 0x16) = (ushort)param_1;
    cVar2 = TControl::setMessageCode_flush_((TControl *)this);
    uVar1 = (uint)(cVar2 != '\0');
  }
  else {
    uVar1 = process_setMessageIndex_reserved_((_unnamed_processor_cpp_ *)param_1,(ushort)param_1);
  }
  return uVar1;
}


/* __thiscall @unnamed@processor_cpp@::process_setMessage_code_(TControl *,
                                                                          unsigned long) */

uint __thiscall
@unnamed@processor_cpp@::process_setMessage_code_
          (_unnamed_processor_cpp_ *this,TControl *param_1,ulong param_2)

{
  uint uVar1;
  char cVar2;
  
  if ((_unnamed_processor_cpp_ *)((uint)param_1 & 0xffff) < (_unnamed_processor_cpp_ *)0xff00) {
    *(short *)(this + 0x14) = (short)((uint)param_1 >> 0x10);
    *(ushort *)(this + 0x16) = (ushort)param_1;
    cVar2 = TControl::setMessageCode_flush_((TControl *)this);
    uVar1 = (uint)(cVar2 != '\0');
  }
  else {
    uVar1 = process_setMessageIndex_reserved_
                      ((_unnamed_processor_cpp_ *)((uint)param_1 & 0xffff),(ushort)param_1);
  }
  return uVar1;
}


/* __thiscall TProcessor::pushCurrent(char const *) */

void __thiscall TProcessor::pushCurrent(TProcessor *this,char *param_1)

{
  if (param_1 == (char *)0x0) {
    return;
  }
  if (3 < *(uint *)(this + 0x1c)) {
    return;
  }
  *(undefined4 *)(this + *(uint *)(this + 0x1c) * 4 + 0xc) = *(undefined4 *)(this + 8);
  *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + 1;
  *(char **)(this + 8) = param_1;
  return;
}


/* __thiscall TProcessor::popCurrent(void) */

void __thiscall TProcessor::popCurrent(TProcessor *this)

{
  *(undefined4 *)(this + 8) = *(undefined4 *)(this + *(int *)(this + 0x1c) * 4 + 8);
  *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + -1;
  return;
}


/* __thiscall TProcessor::on_select_begin(char const * *(TProcessor *),
                                                    void const *,
                                                    char const *,
                                                    unsigned long) */

void __thiscall
TProcessor::on_select_begin
          (TProcessor *this,FuncDef581 *param_1,void *param_2,char *param_3,ulong param_4)

{
  char *pcVar1;
  
  if (*(uint *)(this + 0x1c) < 4) {
    *(code **)(this + 0x20) = process_onCharacterEnd_select_;
    *(FuncDef581 **)(this + 0x24) = param_1;
    *(char **)(this + 0x28) = param_3;
    *(void **)(this + 0x2c) = param_2;
    *(ulong *)(this + 0x30) = param_4;
    pcVar1 = (char *)(**(code **)(this + 0x24))();
    pushCurrent(this,pcVar1);
    (**(code **)(*(int *)this + 0x14))(this,param_4);
  }
  return;
}


/* __thiscall TProcessor::on_select_end(void) */

void __thiscall TProcessor::on_select_end(TProcessor *this)

{
  *(code **)(this + 0x20) = process_onCharacterEnd_normal_;
  popCurrent(this);
  (**(code **)(*(int *)this + 0x18))(this);
  return;
}


/* __thiscall TProcessor::on_select_separate(void) */

void __thiscall TProcessor::on_select_separate(TProcessor *this)

{
  char *pcVar1;
  
  popCurrent(this);
  pcVar1 = (char *)(**(code **)(this + 0x24))(this);
  pushCurrent(this,pcVar1);
  (**(code **)(*(int *)this + 0x1c))(this);
  return;
}


/* __thiscall TProcessor::do_character(int) */

void __thiscall TProcessor::do_character(TProcessor *this,int param_1)

{
  return;
}


/* __thiscall TProcessor::do_tag(unsigned long,
                                           void const *,
                                           unsigned long) */

undefined4 __thiscall
TProcessor::do_tag(TProcessor *this,ulong param_1,void *param_2,ulong param_3)

{
  return 0;
}


/* __thiscall TProcessor::do_systemTagCode(unsigned short,
                                                     void const *,
                                                     unsigned long) */

undefined4 __thiscall
TProcessor::do_systemTagCode(TProcessor *this,ushort param_1,void *param_2,ulong param_3)

{
  return 0;
}


/* __thiscall TProcessor::do_select_begin(unsigned long) */

void __thiscall TProcessor::do_select_begin(TProcessor *this,ulong param_1)

{
  return;
}


/* __thiscall TProcessor::do_select_end(void) */

void __thiscall TProcessor::do_select_end(TProcessor *this)

{
  return;
}


/* __thiscall TProcessor::do_select_separate(void) */

void __thiscall TProcessor::do_select_separate(TProcessor *this)

{
  return;
}


/* __thiscall TProcessor::~TProcessor(void) */

void __thiscall TProcessor::_TProcessor(TProcessor *this)

{
  short in_r4;
  
  if ((this != (TProcessor *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall TProcessor::reset_(char const *) */

void __thiscall TProcessor::reset_(TProcessor *this,char *param_1)

{
  *(char **)(this + 8) = param_1;
  *(undefined4 *)(this + 0x1c) = 0;
  *(code **)(this + 0x20) = process_onCharacterEnd_normal_;
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall TProcessor::on_tag_(void) */

void __thiscall TProcessor::on_tag_(TProcessor *this)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = *(int *)(this + 8);
  uVar4 = (uint)*(byte *)(iVar3 + 1);
  *(uint *)(this + 8) = iVar3 + uVar4;
  uVar2 = (uint)*(byte *)(iVar3 + 2) << 0x10 | (uint)*(byte *)(iVar3 + 3) << 8 |
          (uint)*(byte *)(iVar3 + 4);
  cVar1 = (**(code **)(*(int *)this + 0xc))(this,uVar2,iVar3 + 5,uVar4 - 5);
  if (cVar1 == '\0') {
    (**(code **)(*(int *)this + 0x28))(this,uVar2,iVar3 + 5,uVar4 - 5);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall TProcessor::do_tag_(unsigned long,
                                            void const *,
                                            unsigned long) */

void __thiscall
TProcessor::do_tag_(TProcessor *this,ulong param_1,void *param_2,ulong param_3)

{
  uint uVar1;
  uint uVar2;
  char cVar4;
  char *pcVar3;
  
  uVar1 = param_1 & 0xffff;
  uVar2 = param_1 >> 0x10 & 0xff;
  if (uVar2 == 0xfd) {
    pcVar3 = (char *)TControl::getMessageData
                               (*(TControl **)(this + 4),
                                *(ushort *)(*(TControl **)(this + 4) + 0x14),(ushort)uVar1);
    pushCurrent(this,pcVar3);
  }
  else {
    if (uVar2 < 0xfd) {
      if (uVar2 == 0xf6) {
        on_select_begin(this,process_select_limited_,param_2,(char *)((int)param_2 + param_3),uVar1)
        ;
      }
      else {
        if ((uVar2 < 0xf6) && (0xf4 < uVar2)) {
          on_select_begin(this,process_select_,param_2,(char *)((int)param_2 + param_3),uVar1);
        }
      }
    }
    else {
      if (uVar2 == 0xff) {
        cVar4 = (**(code **)(*(int *)this + 0x10))(this,uVar1);
        if (cVar4 == '\0') {
          (**(code **)(*(int *)this + 0x2c))(this,uVar1,param_2,param_3);
        }
      }
      else {
        if (uVar2 < 0xff) {
          pcVar3 = (char *)(**(code **)(**(int **)(this + 4) + 0xc))(*(int **)(this + 4),uVar1);
          pushCurrent(this,pcVar3);
        }
      }
    }
  }
  return;
}


/* __thiscall TProcessor::do_systemTagCode_(unsigned short,
                                                      void const *,
                                                      unsigned long) */

void __thiscall
TProcessor::do_systemTagCode_(TProcessor *this,ushort param_1,void *param_2,ulong param_3)

{
  char *pcVar1;
  
  if (param_1 == 5) {
                    /* WARNING: Load size is inaccurate */
    pcVar1 = (char *)TControl::getMessageData
                               (*(TControl **)(this + 4),(ushort)((uint)*param_2 >> 0x10),
                                (ushort)*param_2);
    pushCurrent(this,pcVar1);
  }
  return;
}


/* __thiscall TProcessor::process_character_(void) */

undefined4 __thiscall TProcessor::process_character_(TProcessor *this)

{
  byte bVar1;
  ushort uVar2;
  char cVar3;
  
  bVar1 = **(byte **)(this + 8);
  uVar2 = (ushort)bVar1;
  if (uVar2 == 0x1a) {
    on_tag_(this);
  }
  else {
    if ((uVar2 < 0x1a) && (uVar2 == 0)) {
      cVar3 = (**(code **)(this + 0x20))();
      if (cVar3 == '\0') {
        return 0;
      }
    }
    else {
      cVar3 = (**(code **)(*(int *)(*(int *)(this + 4) + 4) + 0x14))(uVar2);
      if (cVar3 != '\0') {
        *(int *)(this + 8) = *(int *)(this + 8) + 1;
        uVar2 = CONCAT11(bVar1,**(undefined **)(this + 8));
      }
      *(int *)(this + 8) = *(int *)(this + 8) + 1;
      (**(code **)(*(int *)this + 8))(this,uVar2);
    }
  }
  return 1;
}


/* __thiscall TProcessor::process_onCharacterEnd_normal_(TProcessor *) */

bool __thiscall
TProcessor::process_onCharacterEnd_normal_(TProcessor *this,TProcessor *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(this + 0x1c);
  if (iVar1 == 0) {
    (**(code **)(*(int *)this + 0x24))();
  }
  else {
    popCurrent(this);
  }
  return iVar1 != 0;
}


/* __thiscall TProcessor::process_onCharacterEnd_select_(TProcessor *) */

undefined4 __thiscall
TProcessor::process_onCharacterEnd_select_(TProcessor *this,TProcessor *param_1)

{
  *(int *)(this + 0x30) = *(int *)(this + 0x30) + -1;
  if (*(int *)(this + 0x30) == 0) {
    on_select_end(this);
  }
  else {
    on_select_separate(this);
  }
  return 1;
}


/* __thiscall TProcessor::process_select_limited_(TProcessor *) */

int __thiscall TProcessor::process_select_limited_(TProcessor *this,TProcessor *param_1)

{
  ushort uVar1;
  
  uVar1 = **(ushort **)(this + 0x2c);
  *(ushort **)(this + 0x2c) = *(ushort **)(this + 0x2c) + 1;
  return *(int *)(this + 0x28) + (uint)uVar1;
}


/* __thiscall TProcessor::process_select_(TProcessor *) */

int __thiscall TProcessor::process_select_(TProcessor *this,TProcessor *param_1)

{
  int iVar1;
  
  iVar1 = **(int **)(this + 0x2c);
  *(int **)(this + 0x2c) = *(int **)(this + 0x2c) + 1;
  return *(int *)(this + 0x28) + iVar1;
}


/* __thiscall TSequenceProcessor::TSequenceProcessor(TControl *) */

void __thiscall
TSequenceProcessor::TSequenceProcessor(TSequenceProcessor *this,TControl *param_1)

{
  *(undefined1 **)this = &TProcessor::__vt;
  *(TControl **)(this + 4) = param_1;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(code **)(this + 0x20) = TProcessor::process_onCharacterEnd_normal_;
  *(undefined1 **)this = &__vt;
  *(undefined4 *)(this + 0x34) = 0;
  return;
}


/* __thiscall TSequenceProcessor::~TSequenceProcessor(void) */

void __thiscall TSequenceProcessor::_TSequenceProcessor(TSequenceProcessor *this)

{
  short in_r4;
  
  if (this != (TSequenceProcessor *)0x0) {
    *(undefined1 **)this = &__vt;
    TProcessor::_TProcessor((TProcessor *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TSequenceProcessor::process(char const *) */

undefined4 __thiscall TSequenceProcessor::process(TSequenceProcessor *this,char *param_1)

{
  int iVar1;
  uint uVar2;
  char cVar3;
  
  do {
    iVar1 = *(int *)(this + 0x34);
    if (iVar1 == 3) {
      cVar3 = on_jump_isReady(this);
      if (cVar3 == '\0') {
        return *(undefined4 *)(this + 8);
      }
      *(undefined4 *)(this + 0x34) = 2;
      cVar3 = (**(code **)(this + 0x20))(this);
      if (cVar3 != '\0') {
        on_jump(this,*(void **)(*(int *)(this + 4) + 0x18),*(char **)(*(int *)(this + 4) + 0x1c));
      }
    }
    else {
      if ((2 < iVar1) && (iVar1 < 5)) {
        uVar2 = on_branch_queryResult(this);
        if (uVar2 < 0x10000) {
          *(undefined4 *)(this + 0x34) = 2;
          if ((uVar2 < *(uint *)(this + 0x28)) &&
             (cVar3 = (**(code **)(this + 0x20))(this), cVar3 != '\0')) {
            on_branch(this,*(void **)(*(int *)(this + 4) + 0x18),
                      *(char **)(*(int *)(this + 4) + 0x1c));
          }
        }
        else {
          if (uVar2 == 0xffffffff) {
            return *(undefined4 *)(this + 8);
          }
          if (((int)uVar2 < -1) && (-3 < (int)uVar2)) {
            *(undefined4 *)(this + 0x34) = 2;
          }
        }
      }
    }
    if (*(char **)(this + 8) == param_1) {
      (**(code **)(*(int *)this + 0x24))(this);
      return 0;
    }
    cVar3 = on_isReady(this);
    if (cVar3 == '\0') {
      return *(undefined4 *)(this + 8);
    }
    cVar3 = TProcessor::process_character_((TProcessor *)this);
  } while (cVar3 != '\0');
  return 0;
}


/* __thiscall TSequenceProcessor::on_isReady(void) */

void __thiscall TSequenceProcessor::on_isReady(TSequenceProcessor *this)

{
  (**(code **)(*(int *)this + 0x3c))();
  return;
}


/* __thiscall TSequenceProcessor::on_jump_register(bool *(TSequenceProcessor *),
                                                             unsigned long) */

void __thiscall
TSequenceProcessor::on_jump_register
          (TSequenceProcessor *this,FuncDef582 *param_1,ulong param_2)

{
  *(undefined4 *)(this + 0x34) = 3;
  *(FuncDef582 **)(this + 0x20) = param_1;
  *(ulong *)(this + 0x24) = param_2;
  return;
}


/* __thiscall TSequenceProcessor::on_jump_isReady(void) */

void __thiscall TSequenceProcessor::on_jump_isReady(TSequenceProcessor *this)

{
  (**(code **)(*(int *)this + 0x40))();
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall TSequenceProcessor::on_jump(void const *,
                                                    char const *) */

void __thiscall
TSequenceProcessor::on_jump(TSequenceProcessor *this,void *param_1,char *param_2)

{
  reset_(this,param_2);
  (**(code **)(*(int *)this + 0x44))(this,param_1,param_2);
  return;
}


/* __thiscall TSequenceProcessor::on_branch_register(bool *(TSequenceProcessor
   *,unsigned long),
                                                               void const *,
                                                               unsigned long) */

void __thiscall
TSequenceProcessor::on_branch_register
          (TSequenceProcessor *this,FuncDef583 *param_1,void *param_2,ulong param_3)

{
  *(FuncDef583 **)(this + 0x20) = param_1;
  *(void **)(this + 0x24) = param_2;
  *(ulong *)(this + 0x28) = param_3;
  return;
}


/* __thiscall TSequenceProcessor::on_branch_query(unsigned short) */

void __thiscall
TSequenceProcessor::on_branch_query(TSequenceProcessor *this,ushort param_1)

{
  *(undefined4 *)(this + 0x34) = 4;
  (**(code **)(*(int *)this + 0x48))();
  return;
}


/* __thiscall TSequenceProcessor::on_branch_queryResult(void) */

void __thiscall TSequenceProcessor::on_branch_queryResult(TSequenceProcessor *this)

{
  (**(code **)(*(int *)this + 0x4c))();
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall TSequenceProcessor::on_branch(void const *,
                                                      char const *) */

void __thiscall
TSequenceProcessor::on_branch(TSequenceProcessor *this,void *param_1,char *param_2)

{
  reset_(this,param_2);
  (**(code **)(*(int *)this + 0x50))(this,param_1,param_2);
  return;
}


/* __thiscall TSequenceProcessor::do_begin(void const *,
                                                     char const *) */

void __thiscall
TSequenceProcessor::do_begin(TSequenceProcessor *this,void *param_1,char *param_2)

{
  return;
}


/* __thiscall TSequenceProcessor::do_end(void) */

void __thiscall TSequenceProcessor::do_end(TSequenceProcessor *this)

{
  return;
}


/* __thiscall TSequenceProcessor::do_isReady(void) */

undefined4 __thiscall TSequenceProcessor::do_isReady(TSequenceProcessor *this)

{
  return 1;
}


/* __thiscall TSequenceProcessor::do_jump_isReady(void) */

undefined4 __thiscall TSequenceProcessor::do_jump_isReady(TSequenceProcessor *this)

{
  return 1;
}


/* __thiscall TSequenceProcessor::do_jump(void const *,
                                                    char const *) */

void __thiscall
TSequenceProcessor::do_jump(TSequenceProcessor *this,void *param_1,char *param_2)

{
  return;
}


/* __thiscall TSequenceProcessor::do_branch_query(unsigned short) */

void __thiscall
TSequenceProcessor::do_branch_query(TSequenceProcessor *this,ushort param_1)

{
  return;
}


/* __thiscall TSequenceProcessor::do_branch_queryResult(void) */

undefined4 __thiscall TSequenceProcessor::do_branch_queryResult(TSequenceProcessor *this)

{
  return 0xfffffffe;
}


/* __thiscall TSequenceProcessor::do_branch(void const *,
                                                      char const *) */

void __thiscall
TSequenceProcessor::do_branch(TSequenceProcessor *this,void *param_1,char *param_2)

{
  return;
}


/* __thiscall TSequenceProcessor::reset_(char const *) */

void __thiscall TSequenceProcessor::reset_(TSequenceProcessor *this,char *param_1)

{
  TProcessor::reset_((TProcessor *)this,param_1);
  *(undefined4 *)(this + 0x34) = 0;
  if (param_1 != (char *)0x0) {
    *(undefined4 *)(this + 0x34) = 2;
  }
  return;
}


/* __thiscall TSequenceProcessor::do_begin_(void const *,
                                                      char const *) */

void __thiscall
TSequenceProcessor::do_begin_(TSequenceProcessor *this,void *param_1,char *param_2)

{
  (**(code **)(*(int *)this + 0x34))();
  return;
}


/* __thiscall TSequenceProcessor::do_end_(void) */

void __thiscall TSequenceProcessor::do_end_(TSequenceProcessor *this)

{
  *(undefined4 *)(this + 0x34) = 1;
  (**(code **)(*(int *)this + 0x38))();
  return;
}


/* __thiscall TSequenceProcessor::do_tag_(unsigned long,
                                                    void const *,
                                                    unsigned long) */

void __thiscall
TSequenceProcessor::do_tag_
          (TSequenceProcessor *this,ulong param_1,void *param_2,ulong param_3)

{
  uint uVar1;
  uint uVar2;
  ushort uVar3;
  
  uVar1 = param_1 & 0xffff;
  uVar2 = param_1 >> 0x10 & 0xff;
  if (uVar2 == 0xfa) {
    on_branch_register(this,process_branch_,param_2,uVar1);
    return;
  }
  if (uVar2 < 0xfa) {
    uVar3 = (ushort)uVar1;
    if (uVar2 == 0xf8) {
                    /* WARNING: Load size is inaccurate */
      on_branch_register(this,process_branch_limited_,(void *)((int)param_2 + 2),(uint)*param_2);
      on_branch_query(this,uVar3);
      return;
    }
    if (0xf7 < uVar2) {
      on_branch_query(this,uVar3);
      return;
    }
    if (0xf6 < uVar2) {
                    /* WARNING: Load size is inaccurate */
      on_branch_register(this,process_branch_,(void *)((int)param_2 + 2),(uint)*param_2);
      on_branch_query(this,uVar3);
      return;
    }
  }
  else {
    if (uVar2 == 0xfc) {
      on_jump_register(this,process_jump_limited_,uVar1);
      return;
    }
    if (uVar2 < 0xfc) {
      on_branch_register(this,process_branch_limited_,param_2,uVar1);
      return;
    }
  }
  TProcessor::do_tag_((TProcessor *)this,param_1,param_2,param_3);
  return;
}


/* WARNING: Removing unreachable block (ram,0x8029fa00) */
/* __thiscall TSequenceProcessor::do_systemTagCode_(unsigned short,
                                                              void const *,
                                                              unsigned long) */

void __thiscall
TSequenceProcessor::do_systemTagCode_
          (TSequenceProcessor *this,ushort param_1,void *param_2,ulong param_3)

{
  if (param_1 == 6) {
                    /* WARNING: Load size is inaccurate */
    on_jump_register(this,process_jump_,*param_2);
  }
  else {
    if ((5 < param_1) || (3 < param_1)) {
      TProcessor::do_systemTagCode_((TProcessor *)this,param_1,param_2,param_3);
    }
  }
  return;
}


/* __thiscall TSequenceProcessor::process_jump_limited_(TSequenceProcessor *) */

void __thiscall
TSequenceProcessor::process_jump_limited_
          (TSequenceProcessor *this,TSequenceProcessor *param_1)

{
  ushort in_r5;
  
  @unnamed@processor_cpp@::process_setMessage_index_
            (*(_unnamed_processor_cpp_ **)(this + 4),(TControl *)(*(uint *)(this + 0x24) & 0xffff),
             in_r5);
  return;
}


/* __thiscall TSequenceProcessor::process_jump_(TSequenceProcessor *) */

void __thiscall
TSequenceProcessor::process_jump_(TSequenceProcessor *this,TSequenceProcessor *param_1)

{
  ulong in_r5;
  
  @unnamed@processor_cpp@::process_setMessage_code_
            (*(_unnamed_processor_cpp_ **)(this + 4),*(TControl **)(this + 0x24),in_r5);
  return;
}


/* __thiscall TSequenceProcessor::process_branch_limited_(TSequenceProcessor *,
                                                                    unsigned long) */

void __thiscall
TSequenceProcessor::process_branch_limited_
          (TSequenceProcessor *this,TSequenceProcessor *param_1,ulong param_2)

{
  @unnamed@processor_cpp@::process_setMessage_index_
            (*(_unnamed_processor_cpp_ **)(this + 4),
             (TControl *)(uint)*(ushort *)(*(int *)(this + 0x24) + (int)param_1 * 2),
             (ushort)*(int *)(this + 0x24));
  return;
}


/* __thiscall TSequenceProcessor::process_branch_(TSequenceProcessor *,
                                                            unsigned long) */

void __thiscall
TSequenceProcessor::process_branch_
          (TSequenceProcessor *this,TSequenceProcessor *param_1,ulong param_2)

{
  @unnamed@processor_cpp@::process_setMessage_code_
            (*(_unnamed_processor_cpp_ **)(this + 4),
             *(TControl **)(*(ulong *)(this + 0x24) + (int)param_1 * 4),*(ulong *)(this + 0x24));
  return;
}


/* __thiscall TRenderingProcessor::TRenderingProcessor(TControl *) */

void __thiscall
TRenderingProcessor::TRenderingProcessor(TRenderingProcessor *this,TControl *param_1)

{
  *(undefined1 **)this = &TProcessor::__vt;
  *(TControl **)(this + 4) = param_1;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(code **)(this + 0x20) = TProcessor::process_onCharacterEnd_normal_;
  *(undefined1 **)this = &__vt;
  return;
}


/* __thiscall TRenderingProcessor::~TRenderingProcessor(void) */

void __thiscall TRenderingProcessor::_TRenderingProcessor(TRenderingProcessor *this)

{
  short in_r4;
  
  if (this != (TRenderingProcessor *)0x0) {
    *(undefined1 **)this = &__vt;
    TProcessor::_TProcessor((TProcessor *)this);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall TRenderingProcessor::process(char const *) */

undefined4 __thiscall
TRenderingProcessor::process(TRenderingProcessor *this,char *param_1)

{
  char cVar1;
  
  do {
    if (*(char **)(this + 8) == param_1) {
      (**(code **)(*(int *)this + 0x24))(this);
      return 0;
    }
    cVar1 = TProcessor::process_character_((TProcessor *)this);
  } while (cVar1 != '\0');
  return 0;
}


/* __thiscall TRenderingProcessor::do_begin(void const *,
                                                      char const *) */

void __thiscall
TRenderingProcessor::do_begin(TRenderingProcessor *this,void *param_1,char *param_2)

{
  return;
}


/* __thiscall TRenderingProcessor::do_end(void) */

void __thiscall TRenderingProcessor::do_end(TRenderingProcessor *this)

{
  return;
}


/* __thiscall TRenderingProcessor::do_begin_(void const *,
                                                       char const *) */

void __thiscall
TRenderingProcessor::do_begin_(TRenderingProcessor *this,void *param_1,char *param_2)

{
  (**(code **)(*(int *)this + 0x34))();
  return;
}


/* __thiscall TRenderingProcessor::do_end_(void) */

void __thiscall TRenderingProcessor::do_end_(TRenderingProcessor *this)

{
  (**(code **)(*(int *)this + 0x38))();
  return;
}


/* __thiscall TRenderingProcessor::do_tag_(unsigned long,
                                                     void const *,
                                                     unsigned long) */

void __thiscall
TRenderingProcessor::do_tag_
          (TRenderingProcessor *this,ulong param_1,void *param_2,ulong param_3)

{
  uint uVar1;
  
  uVar1 = param_1 >> 0x10 & 0xff;
  if ((0xfc < uVar1) || (uVar1 < 0xf7)) {
    TProcessor::do_tag_((TProcessor *)this,param_1,param_2,param_3);
  }
  return;
}


/* __thiscall TRenderingProcessor::do_systemTagCode_(unsigned short,
                                                               void const *,
                                                               unsigned long) */

void __thiscall
TRenderingProcessor::do_systemTagCode_
          (TRenderingProcessor *this,ushort param_1,void *param_2,ulong param_3)

{
  if ((param_1 != 6) && ((5 < param_1 || (3 < param_1)))) {
    TProcessor::do_systemTagCode_((TProcessor *)this,param_1,param_2,param_3);
  }
  return;
}

