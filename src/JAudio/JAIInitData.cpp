#include <JAudio/JAIInitData.h>
#include <JAudio/JAIGlobalParameter.h>
#include <JAudio/JAISystemInterface.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <JKernel/JKRHeap.h>
#include <MSL_C.PPCEABI.bare.H/printf.h>
#include <JAudio/JAIConst.h>
#include <JAudio/JAIInitData.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JAudio/JAISoundTable.h>
#include <JUtility/JUTAssert.h>
#include <JAudio/JAIBankWave.h>
#include <JAInter/InitData.h>


namespace JAInter {
undefined1 InitData;

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall InitData::checkInitDataFile(void) */

bool __thiscall InitData::checkInitDataFile(InitData *this)

{
  bool bVar1;
  JAIGlobalParameter *pJVar2;
  char *pcVar3;
  size_t sVar4;
  JAIGlobalParameter *this_00;
  JAInter *this_01;
  InitData *this_02;
  uchar **extraout_r4;
  uchar **in_r5;
  undefined8 uVar5;
  
  uVar5 = JAIGlobalParameter::getParamInitDataFileName((JAIGlobalParameter *)this);
  pJVar2 = (JAIGlobalParameter *)
           SystemInterface::checkFileExsistence
                     ((SystemInterface *)((ulonglong)uVar5 >> 0x20),(char *)uVar5);
  if (pJVar2 == (JAIGlobalParameter *)0x0) {
    pcVar3 = (char *)JAIGlobalParameter::getParamInitDataFileName((JAIGlobalParameter *)0x0);
    pJVar2 = (JAIGlobalParameter *)MSL_C.PPCEABI.bare.H::strlen(pcVar3);
    pcVar3 = (char *)JAIGlobalParameter::getParamAudioResPath(pJVar2);
    sVar4 = MSL_C.PPCEABI.bare.H::strlen(pcVar3);
    pJVar2 = (JAIGlobalParameter *)JKRHeap::alloc(JAudio::JASDram,(ulong)(pJVar2 + sVar4 + 1),0);
    this_00 = (JAIGlobalParameter *)JAIGlobalParameter::getParamInitDataFileName(pJVar2);
    in_r5 = (uchar **)JAIGlobalParameter::getParamAudioResPath(this_00);
    pcVar3 = "%s%s%c";
    MSL_C.PPCEABI.bare.H::sprintf((char *)pJVar2,"%s%s%c",in_r5,this_00,0);
    pJVar2 = (JAIGlobalParameter *)JAIGlobalParameter::setParamInitDataFileName(pJVar2,pcVar3);
    uVar5 = JAIGlobalParameter::getParamInitDataFileName(pJVar2);
    pJVar2 = (JAIGlobalParameter *)
             SystemInterface::checkFileExsistence
                       ((SystemInterface *)((ulonglong)uVar5 >> 0x20),(char *)uVar5);
    if (pJVar2 == (JAIGlobalParameter *)0x0) {
      return false;
    }
  }
  this_01 = (JAInter *)JAIGlobalParameter::getParamInitDataFileName(pJVar2);
  this_02 = (InitData *)loadTmpDVDFile(this_01,&aafPointer,in_r5);
  bVar1 = _aafPointer != 0;
  if (bVar1) {
    checkInitDataOnMemory(this_02);
    deleteTmpDVDFile((JAInter *)&aafPointer,extraout_r4);
  }
  return bVar1;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall InitData::checkInitDataOnMemory(void) */

void __thiscall InitData::checkInitDataOnMemory(InitData *this)

{
  bool bVar1;
  uint uVar2;
  ulonglong uVar3;
  uint uVar4;
  SoundTable *this_00;
  ulong uVar5;
  undefined *puVar6;
  JAIGlobalParameter **ppJVar7;
  JAIGlobalParameter *pJVar8;
  undefined4 in_r4;
  int *piVar9;
  int *in_r5;
  undefined **ppuVar10;
  byte *ctx;
  int iVar11;
  int iVar12;
  undefined8 uVar13;
  ulonglong uVar14;
  
  bVar1 = true;
  iVar12 = 0;
  uVar14 = CONCAT44(_initOnCodeBnk,in_r4);
  while (_initOnCodeBnk = (int *)(uint)(uVar14 >> 0x20), uVar3 = uVar14 & 0xffffffff00000000, bVar1)
  {
    uVar4 = *(uint *)(_aafPointer + iVar12 * 4);
    iVar11 = iVar12 + 1;
    if (uVar4 < 9) {
      switch(uVar4) {
      case 0:
        bVar1 = false;
        this = (InitData *)&JAudio::_836;
        iVar12 = iVar11;
        uVar14 = uVar14 & 0xffffffff00000000 | (ulonglong)_aafPointer;
        break;
      case 1:
        ctx = *(byte **)(_aafPointer + (iVar12 + 2) * 4);
        this_00 = (SoundTable *)
                  transInitDataFile((JAInter *)(_aafPointer + *(int *)(_aafPointer + iVar11 * 4)),
                                    ctx,(ulong)in_r5);
        this = (InitData *)SoundTable::init(this_00,ctx,(ulong)in_r5);
        iVar12 = iVar12 + 4;
        uVar14 = CONCAT44(_initOnCodeBnk,ctx);
        break;
      case 2:
        uVar4 = 0;
        in_r5 = (int *)0x0;
        while (*(int *)(_aafPointer + (iVar11 + (int)in_r5) * 4) != 0) {
          in_r5 = (int *)((int)in_r5 + 3);
        }
        uVar14 = transInitDataFile((JAInter *)(_aafPointer + iVar11 * 4),
                                   (uchar *)(((uint)in_r5 / 3) * 0xc + 4),(ulong)in_r5);
        for (this = (InitData *)(iVar11 * 4); _initOnCodeBnk = (int *)(uVar14 >> 0x20),
            piVar9 = _initOnCodeBnk, *(int *)(_aafPointer + (int)this) != 0;
            this = (InitData *)((int)this + 0xc)) {
          uVar2 = uVar4 & 0xff;
          _initOnCodeBnk[uVar2 * 3] = _aafPointer + _initOnCodeBnk[uVar2 * 3];
          uVar14 = CONCAT44(_initOnCodeBnk,uVar2 * 0xc);
          uVar4 = uVar4 + 1;
          iVar11 = iVar11 + 3;
          in_r5 = piVar9;
        }
        iVar12 = iVar11 + 1;
        break;
      case 3:
        uVar4 = 0;
        in_r5 = (int *)0x0;
        while (*(int *)(_aafPointer + (iVar11 + (int)in_r5) * 4) != 0) {
          in_r5 = (int *)((int)in_r5 + 3);
        }
        uVar14 = transInitDataFile((JAInter *)(_aafPointer + iVar11 * 4),
                                   (uchar *)(((uint)in_r5 / 3) * 0xc + 4),(ulong)in_r5);
        for (this = (InitData *)(iVar11 * 4); _initOnCodeWs = (int *)(uVar14 >> 0x20),
            piVar9 = _initOnCodeWs, *(int *)(_aafPointer + (int)this) != 0;
            this = (InitData *)((int)this + 0xc)) {
          _initOnCodeWs[(uVar4 & 0xff) * 3] = _aafPointer + _initOnCodeWs[(uVar4 & 0xff) * 3];
          uVar14 = CONCAT44(_initOnCodeWs,_wsMax);
          _wsMax = _wsMax + 1;
          iVar11 = iVar11 + 3;
          uVar4 = uVar4 + 1;
          in_r5 = piVar9;
        }
        iVar12 = iVar11 + 1;
        uVar14 = uVar14 & 0xffffffff | ZEXT48(_initOnCodeBnk) << 0x20;
        break;
      case 4:
        uVar5 = JUTAssertion::getSDevice();
        in_r5 = (int *)0x78;
        uVar14 = JUTAssertion::setWarningMessage_f
                           (uVar5,"JAIInitData.cpp",0x78,"%s",
                            (___)"Hed file is not needed. Remove this file(\'aaf\')\n");
        this = (InitData *)(undefined **)(uVar14 >> 0x20);
        iVar12 = iVar12 + 4;
        uVar14 = uVar14 & 0xffffffff | ZEXT48(_initOnCodeBnk) << 0x20;
        break;
      case 5:
        _initOnCodeStrm =
             (undefined **)
             transInitDataFile((JAInter *)(_aafPointer + iVar11 * 4),&DAT_00000008,(ulong)in_r5);
        piVar9 = (int *)(_aafPointer + iVar11 * 4);
        puVar6 = (undefined *)
                 transInitDataFile((JAInter *)(_aafPointer + *piVar9),(uchar *)piVar9[1],
                                   (ulong)in_r5);
        ppuVar10 = _initOnCodeStrm;
        *_initOnCodeStrm = puVar6;
        _streamList = *_initOnCodeStrm;
        this = (InitData *)_initOnCodeStrm;
        iVar12 = iVar12 + 4;
        uVar14 = CONCAT44(_initOnCodeBnk,ppuVar10);
        break;
      case 6:
        in_r5 = (int *)(_aafPointer + iVar11 * 4);
        uVar13 = transInitDataFile((JAInter *)(_aafPointer + *in_r5),(uchar *)in_r5[1],(ulong)in_r5)
        ;
        ppJVar7 = (JAIGlobalParameter **)((ulonglong)uVar13 >> 0x20);
        JAIGlobalParameter::setParamSoundSceneMax(*ppJVar7,(ulong)uVar13);
        pJVar8 = _msBasic;
        *(JAIGlobalParameter ***)(_msBasic + 0x1c) = ppJVar7 + 1;
        iVar11 = 0;
        for (ppuVar10 = (undefined **)0x0;
            uVar14 = JAIGlobalParameter::getParamSoundSceneMax(pJVar8),
            this = (InitData *)(undefined **)(uVar14 >> 0x20), ppuVar10 < this;
            ppuVar10 = (undefined **)((int)ppuVar10 + 1)) {
          pJVar8 = *(JAIGlobalParameter **)(_msBasic + 0x1c);
          *(int *)(pJVar8 + iVar11) = *(int *)(pJVar8 + iVar11) + (int)ppJVar7;
          iVar11 = iVar11 + 4;
        }
        iVar12 = iVar12 + 4;
        uVar14 = uVar14 & 0xffffffff | ZEXT48(_initOnCodeBnk) << 0x20;
        break;
      case 7:
        in_r5 = (int *)(_aafPointer + iVar11 * 4);
        uVar14 = transInitDataFile((JAInter *)(_aafPointer + *in_r5),(uchar *)in_r5[1],(ulong)in_r5)
        ;
        this = (InitData *)(undefined **)(uVar14 >> 0x20);
        iVar12 = iVar12 + 4;
        _initOnCodeFxScene = (undefined **)this;
        uVar14 = uVar14 & 0xffffffff | ZEXT48(_initOnCodeBnk) << 0x20;
        break;
      case 8:
        in_r5 = (int *)(_aafPointer + iVar11 * 4);
        this = (InitData *)
               transInitDataFile((JAInter *)(_aafPointer + *in_r5),
                                 (uchar *)((in_r5[1] & 0xfff0U) + 0x10),(ulong)in_r5);
        pJVar8 = _msBasic;
        *(InitData **)(_msBasic + 0x18) = this;
        iVar12 = iVar12 + 4;
        uVar14 = CONCAT44(_initOnCodeBnk,pJVar8);
      }
    }
    else {
      this = (InitData *)(iVar11 * 4);
      do {
        piVar9 = (int *)(_aafPointer + (int)this);
        iVar11 = iVar11 + 1;
        this = (InitData *)((int)this + 4);
        iVar12 = iVar11;
        uVar14 = uVar3 | _aafPointer;
      } while (*piVar9 != 0);
    }
  }
  BankWave::init((BankWave *)this,(EVP_PKEY_CTX *)uVar14);
  return;
}

