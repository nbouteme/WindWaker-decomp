#include <d_s_actor_data_mng.h>
#include <SComponent/c_data_tbl.h>
#include <JKernel/JKRHeap.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <d_s_actor_data_mng.h>
#include <dADM_CharTbl.h>
#include <dADM.h>


/* __thiscall dADM_CharTbl::dADM_CharTbl(void) */

void __thiscall dADM_CharTbl::dADM_CharTbl(dADM_CharTbl *this)

{
  cDT::cDT(&this->parent);
  return;
}


/* __thiscall dADM_CharTbl::~dADM_CharTbl(void) */

void __thiscall dADM_CharTbl::_dADM_CharTbl(dADM_CharTbl *this)

{
  short in_r4;
  
  if ((this != (dADM_CharTbl *)0x0) && (cDT::_cDT(&this->parent), 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall dADM_CharTbl::SetData(unsigned long,
                                    unsigned long,
                                    unsigned long,
                                    unsigned long,
                                    unsigned long,
                                    unsigned long,
                                    unsigned long) */

void __thiscall
dADM_CharTbl::SetData
          (dADM_CharTbl *this,void *pData,ulong row_num,ulong pRow,ulong column_num,ulong pColumn,
          ulong dat_size,ulong data)

{
  int *piVar1;
  ulong uVar2;
  
  piVar1 = (int *)pRow;
  uVar2 = row_num;
  if (row_num != 0) {
    do {
      *piVar1 = *piVar1 + (int)pData;
      piVar1 = piVar1 + 1;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  piVar1 = (int *)pColumn;
  uVar2 = column_num;
  if (column_num != 0) {
    do {
      *piVar1 = *piVar1 + (int)pData;
      piVar1 = piVar1 + 1;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  if (dat_size != row_num * column_num) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_s_actor_data_mng.cpp",0x39,"dat_size == row_num * colum_num");
    m_Do_printf::OSPanic("d_s_actor_data_mng.cpp",0x39,"Halt");
  }
  cDT::Set(&this->parent,row_num,(char **)pRow,column_num,(char **)pColumn,(byte *)data);
  SetUpIndex(this);
  return;
}


/* __thiscall dADM_CharTbl::SetUpIndex(void) */

void __thiscall dADM_CharTbl::SetUpIndex(dADM_CharTbl *this)

{
  int iVar1;
  
  iVar1 = cDT_NamePTbl::GetIndex((cDT_NamePTbl *)this,"ARG",0);
  this->mIndex_ARG = iVar1;
  iVar1 = cDT_NamePTbl::GetIndex((cDT_NamePTbl *)this,"N_ITEM0",0);
  this->mIndex_N_ITEM0 = iVar1;
  iVar1 = cDT_NamePTbl::GetIndex((cDT_NamePTbl *)this,"N_ITEM1",0);
  this->mIndex_N_ITEM1 = iVar1;
  iVar1 = cDT_NamePTbl::GetIndex((cDT_NamePTbl *)this,"N_ITEM2",0);
  this->mIndex_N_ITEM2 = iVar1;
  iVar1 = cDT_NamePTbl::GetIndex((cDT_NamePTbl *)this,"N_ITEM3",0);
  this->mIndex_N_ITEM3 = iVar1;
  iVar1 = cDT_NamePTbl::GetIndex((cDT_NamePTbl *)this,"N_ITEM4",0);
  this->mIndex_N_ITEM4 = iVar1;
  iVar1 = cDT_NamePTbl::GetIndex((cDT_NamePTbl *)this,"N_ITEM5",0);
  this->mIndex_N_ITEM5 = iVar1;
  iVar1 = cDT_NamePTbl::GetIndex((cDT_NamePTbl *)this,"N_ITEM6",0);
  this->mIndex_N_ITEM6 = iVar1;
  iVar1 = cDT_NamePTbl::GetIndex((cDT_NamePTbl *)this,"N_ITEM7",0);
  this->mIndex_N_ITEM7 = iVar1;
  iVar1 = cDT_NamePTbl::GetIndex((cDT_NamePTbl *)this,"N_ITEM8",0);
  this->mIndex_N_ITEM8 = iVar1;
  iVar1 = cDT_NamePTbl::GetIndex((cDT_NamePTbl *)this,"N_ITEM9",0);
  this->mIndex_N_ITEM9 = iVar1;
  iVar1 = cDT_NamePTbl::GetIndex((cDT_NamePTbl *)this,"N_ITEM10",0);
  this->mIndex_N_ITEM10 = iVar1;
  iVar1 = cDT_NamePTbl::GetIndex((cDT_NamePTbl *)this,"N_ITEM11",0);
  this->mIndex_N_ITEM11 = iVar1;
  iVar1 = cDT_NamePTbl::GetIndex((cDT_NamePTbl *)this,"N_ITEM12",0);
  this->mIndex_N_ITEM12 = iVar1;
  iVar1 = cDT_NamePTbl::GetIndex((cDT_NamePTbl *)this,"N_ITEM13",0);
  this->mIndex_N_ITEM13 = iVar1;
  iVar1 = cDT_NamePTbl::GetIndex((cDT_NamePTbl *)this,"N_ITEM14",0);
  this->mIndex_N_ITEM14 = iVar1;
  iVar1 = cDT_NamePTbl::GetIndex((cDT_NamePTbl *)this,"N_ITEM15",0);
  this->mIndex_N_ITEM15 = iVar1;
  iVar1 = cDT_NamePTbl::GetIndex((cDT_NamePTbl *)this,"percent",0);
  this->mIndex_percent = iVar1;
  iVar1 = cDT_NamePTbl::GetIndex((cDT_NamePTbl *)this,"ITEM0",0);
  this->mIndex_ITEM0 = iVar1;
  iVar1 = cDT_NamePTbl::GetIndex((cDT_NamePTbl *)this,"ITEM1",0);
  this->mIndex_ITEM1 = iVar1;
  iVar1 = cDT_NamePTbl::GetIndex((cDT_NamePTbl *)this,"ITEM2",0);
  this->mIndex_ITEM2 = iVar1;
  iVar1 = cDT_NamePTbl::GetIndex((cDT_NamePTbl *)this,"ITEM3",0);
  this->mIndex_ITEM3 = iVar1;
  iVar1 = cDT_NamePTbl::GetIndex((cDT_NamePTbl *)this,"ITEM4",0);
  this->mIndex_ITEM4 = iVar1;
  iVar1 = cDT_NamePTbl::GetIndex((cDT_NamePTbl *)this,"ITEM5",0);
  this->mIndex_ITEM5 = iVar1;
  iVar1 = cDT_NamePTbl::GetIndex((cDT_NamePTbl *)this,"ITEM6",0);
  this->mIndex_ITEM6 = iVar1;
  iVar1 = cDT_NamePTbl::GetIndex((cDT_NamePTbl *)this,"ITEM7",0);
  this->mIndex_ITEM7 = iVar1;
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dADM_CharTbl::GetNameIndex2(char const *,
                                          int) const */

int __thiscall dADM_CharTbl::GetNameIndex2(dADM_CharTbl *this,char *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    iVar2 = cDT_NamePTbl::GetIndex((cDT_NamePTbl *)&(this->parent).mName,param_1,iVar2);
    if (iVar2 == -1) {
      return -1;
    }
    uVar1 = cDT::GetInf(&this->parent,this->mIndex_ARG,iVar2);
    if (param_2 == (uVar1 & 0xff)) break;
    iVar2 = iVar2 + 1;
  }
  return iVar2;
}


/* __thiscall dADM::dADM(void) */

void __thiscall dADM::dADM(dADM *this)

{
  this->vtbl = (undefined *)&__vt;
  dADM_CharTbl::dADM_CharTbl(&this->mCharTbl);
  this->mBlockCount = 0;
  this->mpData = (void *)0x0;
  return;
}


/* __thiscall dADM::~dADM(void) */

void __thiscall dADM::_dADM(dADM *this)

{
  short in_r4;
  
  if (this != (dADM *)0x0) {
    this->vtbl = (undefined *)&__vt;
    dADM_CharTbl::_dADM_CharTbl(&this->mCharTbl);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dADM::FindTag(unsigned long,
                            unsigned long *,
                            unsigned long *) */

undefined4 __thiscall dADM::FindTag(dADM *this,ulong tag,ulong *pSize,ulong *pOffs)

{
  int iVar1;
  ulong *data;
  
  data = (ulong *)this->mpData;
  iVar1 = this->mBlockCount;
  if (0 < iVar1) {
    do {
      if (tag == *data) {
        *pSize = data[1];
        *pOffs = data[2];
        return 1;
      }
      data = data + 3;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return 0;
}


/* __thiscall dADM::SetData(void *) */

void __thiscall dADM::SetData(dADM *this,void *param_1)

{
  void *pvVar1;
  char cVar3;
  ulong uVar2;
  int iVar4;
  ulong local_28;
  ulong dat_size;
  ulong local_20;
  ulong name;
  ulong local_18;
  ulong row;
  
                    /* WARNING: Load size is inaccurate */
  this->mBlockCount = *param_1;
  this->mpData = (void *)((int)param_1 + 4);
  pvVar1 = this->mpData;
  iVar4 = 0;
  while( true ) {
    if (this->mBlockCount <= iVar4) break;
    *(int *)((int)pvVar1 + 8) = *(int *)((int)pvVar1 + 8) + (int)param_1;
    pvVar1 = (void *)((int)pvVar1 + 0xc);
    iVar4 = iVar4 + 1;
  }
  cVar3 = FindTag(this,0x4143464e,&row,&local_18);
  if (cVar3 != '\0') {
    cVar3 = FindTag(this,0x41434e41,&name,&local_20);
    if ((cVar3 != '\0') && (cVar3 = FindTag(this,0x41434453,&dat_size,&local_28), cVar3 != '\0')) {
      if (dat_size != row * name) {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar2,"d_s_actor_data_mng.cpp",0xca,"row * name == dat_size");
        m_Do_printf::OSPanic("d_s_actor_data_mng.cpp",0xca,"Halt");
      }
      dADM_CharTbl::SetData(&this->mCharTbl,param_1,row,local_18,name,local_20,dat_size,local_28);
    }
  }
  return;
}

