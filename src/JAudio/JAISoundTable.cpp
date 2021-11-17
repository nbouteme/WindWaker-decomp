#include <JAudio/JAISoundTable.h>
#include <m_Do_printf.h>
#include <JUtility/JUTAssert.h>
#include <JKernel/JKRHeap.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JAudio/JAIGlobalParameter.h>
#include <JAInter/SoundTable.h>


namespace JAInter {
undefined1 SoundTable;
undefined1 SoundTable;
undefined1 SoundTable;
undefined1 SoundTable;
undefined1 SoundTable;
undefined1 SoundTable;

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall SoundTable::init(unsigned char *,
                                        unsigned long) */

int __thiscall SoundTable::init(SoundTable *this,byte *ctx,ulong param_2)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  
  mVersion = this[3];
  _mDatasize = ctx;
  _mAddress = this;
  if ((_msCurrentHeap == 0) &&
     (m_Do_printf::OSReport
                ("JAIBasicのカレントヒープがありません（mCurrentHeap==NULL）\n"),
     _msCurrentHeap == 0)) {
    JUTAssertion::showAssert(3,"JAIBasic.h",0x94,"msCurrentHeap");
    m_Do_printf::OSPanic("JAIBasic.h",0x94,&DAT_80369d6d);
  }
  _mSoundMax = JKernel::operator_new__(0x24,_msCurrentHeap,4);
  if ((_msCurrentHeap == 0) &&
     (m_Do_printf::OSReport
                ("JAIBasicのカレントヒープがありません（mCurrentHeap==NULL）\n"),
     _msCurrentHeap == 0)) {
    JUTAssertion::showAssert(3,"JAIBasic.h",0x94,"msCurrentHeap");
    m_Do_printf::OSPanic("JAIBasic.h",0x94,&DAT_80369d6d);
  }
  iVar1 = JKernel::operator_new__(0x48,_msCurrentHeap,4);
  _mPointerCategory = iVar1;
  for (bVar3 = 0; bVar3 < 0x12; bVar3 = bVar3 + 1) {
    iVar2 = (uint)bVar3 * 4;
    *(undefined2 *)(_mSoundMax + (uint)bVar3 * 2) = *(undefined2 *)(_mAddress + iVar2 + 6);
    iVar1 = _mPointerCategory;
    *(SoundTable **)(_mPointerCategory + iVar2) =
         _mAddress + (uint)*(ushort *)(_mAddress + iVar2 + 8) * 0x10 + 0x50;
    if ((bVar3 < 0x10) && (iVar1 = _mSoundMax, *(short *)(_mSoundMax + (uint)bVar3 * 2) != 0)) {
      mCategotyMax = bVar3 + 1;
    }
  }
  return iVar1;
}


namespace SoundTable {

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall getInfoPointer(unsigned long) */

int getInfoPointer(ulong param_1)

{
  JAIGlobalParameter *pJVar1;
  uint uVar2;
  uint unaff_r30;
  int iVar3;
  
  pJVar1 = (JAIGlobalParameter *)param_1;
  if ((_mAddress == 0) &&
     (pJVar1 = (JAIGlobalParameter *)
               m_Do_printf::OSReport("getInfoPointer サウンドテーブルがありません\n"),
     _mAddress == 0)) {
    JUTAssertion::showAssert(3,"JAISoundTable.cpp",0x34,"mAddress");
    pJVar1 = (JAIGlobalParameter *)m_Do_printf::OSPanic("JAISoundTable.cpp",0x34,&DAT_80369d6d);
  }
  iVar3 = 0;
  uVar2 = param_1 & 0xc0000000;
  if (uVar2 == 0xc0000000) {
    unaff_r30 = 0x11;
  }
  else {
    if ((int)uVar2 < -0x40000000) {
      if ((int)uVar2 < -0x7fffffff) {
        unaff_r30 = 0x10;
        goto LAB_8029b878;
      }
    }
    else {
      if (uVar2 == 0) {
        unaff_r30 = param_1 >> 0xc & 0xff;
        uVar2 = JAIGlobalParameter::getParamSeCategoryMax(pJVar1);
        if (uVar2 <= unaff_r30) {
          pJVar1 = (JAIGlobalParameter *)
                   m_Do_printf::OSReport
                             (
                             "getInfoPointer 登録されていないSEカテゴリーナンバーが指定されました。\n"
                             );
          uVar2 = JAIGlobalParameter::getParamSeCategoryMax(pJVar1);
          if (uVar2 <= unaff_r30) {
            JUTAssertion::showAssert
                      (3,"JAISoundTable.cpp",0x3d,
                       "(_category<JAIGlobalParameter::getParamSeCategoryMax())");
            m_Do_printf::OSPanic("JAISoundTable.cpp",0x3d,&DAT_80369d6d);
          }
        }
        goto LAB_8029b878;
      }
    }
    m_Do_printf::OSReport("getInfoPointer サウンドカテゴリービットが異常です。\n")
    ;
    JUTAssertion::showAssert(3,"JAISoundTable.cpp",0x46,"0");
    m_Do_printf::OSPanic("JAISoundTable.cpp",0x46,&DAT_80369d6d);
  }
LAB_8029b878:
  if ((_mAddress != 0) && ((param_1 & 0x3ff) < (uint)*(ushort *)(_mSoundMax + unaff_r30 * 2))) {
    iVar3 = *(int *)(_mPointerCategory + unaff_r30 * 4) + (param_1 & 0x3ff) * 0x10;
  }
  return iVar3;
}

}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall SoundTable::getInfoFormat(unsigned long) */

undefined __thiscall SoundTable::getInfoFormat(SoundTable *this,ulong param_1)

{
  uint uVar1;
  undefined uVar2;
  
  uVar2 = 0;
  uVar1 = (uint)this & 0xc0000000;
  if (uVar1 == 0xc0000000) {
    uVar2 = _mAddress[2];
  }
  else {
    if ((int)uVar1 < -0x40000000) {
      if ((int)uVar1 < -0x7fffffff) {
        return _mAddress[1];
      }
    }
    else {
      if (uVar1 == 0) {
        return *_mAddress;
      }
    }
    m_Do_printf::OSReport("getInfoFormat サウンドカテゴリービットが異常です。\n");
    JUTAssertion::showAssert(3,"JAISoundTable.cpp",0x65,"0");
    m_Do_printf::OSPanic("JAISoundTable.cpp",0x65,&DAT_80369d6d);
  }
  return uVar2;
}


namespace SoundTable {

/* __thiscall getCategotyMax(void) */

undefined getCategotyMax(void)

{
  return mCategotyMax;
}

