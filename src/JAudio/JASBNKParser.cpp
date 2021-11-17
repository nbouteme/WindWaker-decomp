#include <JAudio/JASBNKParser.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JAudio/JASBank.h>
#include <JKernel/JKRHeap.h>
#include <JAudio/JASBasicBank.h>
#include <JAudio/JASBNKParser.h>
#include <JAudio/JASBasicInst.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <JAudio/JASCalc.h>
#include <JAudio/JASInstEffect.h>
#include <JAudio/JASInstSense.h>
#include <JAudio/JASDrumSet.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <JASystem/BNKParser.h>


namespace JASystem {
undefined1 BNKParser;

/* WARNING: Inlined function: __save_gpr */
/* WARNING: Inlined function: __restore_gpr */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall BNKParser::createBasicBank(void *) */

TBasicBank * __thiscall BNKParser::createBasicBank(BNKParser *this,void *param_1)

{
  void *pvVar1;
  float fVar2;
  uint uVar3;
  JKRHeap *this_00;
  int iVar4;
  TBasicBank *this_01;
  int iVar5;
  TBasicInst *this_02;
  ulong uVar6;
  THeader *pTVar7;
  Osc_ *pOVar8;
  BNKParser *pBVar9;
  int iVar10;
  undefined4 uVar11;
  byte *pbVar12;
  undefined4 *puVar13;
  uint *puVar14;
  byte *pbVar15;
  int *piVar16;
  undefined4 *puVar17;
  undefined4 *this_03;
  undefined4 *this_04;
  uint *puVar18;
  char *in_r6;
  int iVar19;
  int iVar20;
  int iVar21;
  uint uVar22;
  int iVar23;
  int iVar24;
  int iVar25;
  undefined8 uVar26;
  
  this_00 = (JKRHeap *)TBank::getCurrentHeap((TBank *)this);
  iVar4 = JKRHeap::getFreeSize(this_00);
  this_01 = (TBasicBank *)JKernel::operator_new(0x10,this_00,0);
  if (this_01 != (TBasicBank *)0x0) {
    TBasicBank::TBasicBank(this_01);
  }
  if (this_01 == (TBasicBank *)0x0) {
    this_01 = (TBasicBank *)0x0;
  }
  else {
    TBasicBank::setInstCount(this_01,0x100);
    iVar21 = 0;
    iVar19 = 0;
    do {
      iVar5 = JAudio::JSUConvertOffsetToPtr(this,*(undefined4 *)(this + iVar19 + 0x24));
      if (iVar5 != 0) {
        this_02 = (TBasicInst *)JKernel::operator_new(0x24,this_00,0);
        if (this_02 != (TBasicInst *)0x0) {
          TBasicInst::TBasicInst(this_02);
        }
        if (this_02 == (TBasicInst *)0x0) {
          uVar6 = JUTAssertion::getSDevice();
          in_r6 = "instp != 0";
          JUTAssertion::showAssert(uVar6,"JASBNKParser.cpp",0x38,"instp != 0");
          m_Do_printf::OSPanic("JASBNKParser.cpp",0x38,&DAT_80367ddc);
        }
        *(undefined4 *)(this_02 + 4) = *(undefined4 *)(iVar5 + 8);
        *(undefined4 *)(this_02 + 8) = *(undefined4 *)(iVar5 + 0xc);
        TBasicInst::setOscCount(this_02,2);
        iVar24 = 0;
        iVar25 = 0;
        iVar20 = 0;
        do {
          pTVar7 = (THeader *)
                   JAudio::JSUConvertOffsetToPtr(this,*(undefined4 *)(iVar5 + iVar20 + 0x10));
          if (pTVar7 != (THeader *)0x0) {
            pOVar8 = (Osc_ *)findOscPtr((BNKParser *)this_01,(TBasicBank *)this,pTVar7,(TOsc *)in_r6
                                       );
            if (pOVar8 == (Osc_ *)0x0) {
              pOVar8 = (Osc_ *)JKernel::operator_new(0x18,this_00,0);
              if (pOVar8 == (Osc_ *)0x0) {
                uVar6 = JUTAssertion::getSDevice();
                in_r6 = "osc != 0";
                JUTAssertion::showAssert(uVar6,"JASBNKParser.cpp",0x48,"osc != 0");
                m_Do_printf::OSPanic("JASBNKParser.cpp",0x48,&DAT_80367ddc);
              }
              *pOVar8 = (Osc_)*pTVar7;
              *(undefined4 *)((THeader *)pOVar8 + 4) = *(undefined4 *)(pTVar7 + 4);
              uVar26 = JAudio::JSUConvertOffsetToPtr(this,*(undefined4 *)(pTVar7 + 8));
              pBVar9 = (BNKParser *)((ulonglong)uVar26 >> 0x20);
              if (pBVar9 == (BNKParser *)0x0) {
                *(undefined4 *)((THeader *)pOVar8 + 8) = 0;
              }
              else {
                iVar10 = getOscTableEndPtr(pBVar9,(short *)uVar26);
                uVar3 = iVar10 - (int)pBVar9;
                pvVar1 = (void *)((((int)uVar3 >> 1) + (uint)((int)uVar3 < 0 && (uVar3 & 1) != 0)) *
                                 2);
                uVar11 = JKernel::operator_new__(pvVar1,this_00,0);
                *(undefined4 *)((THeader *)pOVar8 + 8) = uVar11;
                if (*(int *)((THeader *)pOVar8 + 8) == 0) {
                  uVar6 = JUTAssertion::getSDevice();
                  in_r6 = "osc->table != 0";
                  JUTAssertion::showAssert(uVar6,"JASBNKParser.cpp",0x52,"osc->table != 0");
                  m_Do_printf::OSPanic("JASBNKParser.cpp",0x52,&DAT_80367ddc);
                }
                Calc::bcopy((Calc *)pBVar9,*(void **)((THeader *)pOVar8 + 8),pvVar1,(size_t)in_r6);
              }
              uVar26 = JAudio::JSUConvertOffsetToPtr(this,*(undefined4 *)(pTVar7 + 0xc));
              pBVar9 = (BNKParser *)((ulonglong)uVar26 >> 0x20);
              if (pBVar9 == (BNKParser *)0x0) {
                *(undefined4 *)((THeader *)pOVar8 + 0xc) = 0;
              }
              else {
                iVar10 = getOscTableEndPtr(pBVar9,(short *)uVar26);
                uVar3 = iVar10 - (int)pBVar9;
                pvVar1 = (void *)((((int)uVar3 >> 1) + (uint)((int)uVar3 < 0 && (uVar3 & 1) != 0)) *
                                 2);
                uVar11 = JKernel::operator_new__(pvVar1,this_00,0);
                *(undefined4 *)((THeader *)pOVar8 + 0xc) = uVar11;
                if (*(int *)((THeader *)pOVar8 + 0xc) == 0) {
                  uVar6 = JUTAssertion::getSDevice();
                  in_r6 = "osc->rel_table != 0";
                  JUTAssertion::showAssert(uVar6,"JASBNKParser.cpp",0x5e,"osc->rel_table != 0");
                  m_Do_printf::OSPanic("JASBNKParser.cpp",0x5e,&DAT_80367ddc);
                }
                Calc::bcopy((Calc *)pBVar9,*(void **)((THeader *)pOVar8 + 0xc),pvVar1,(size_t)in_r6)
                ;
              }
              *(undefined4 *)((THeader *)pOVar8 + 0x10) = *(undefined4 *)(pTVar7 + 0x10);
              *(undefined4 *)((THeader *)pOVar8 + 0x14) = *(undefined4 *)(pTVar7 + 0x14);
            }
            TBasicInst::setOsc(this_02,iVar24,pOVar8);
            iVar24 = iVar24 + 1;
          }
          iVar25 = iVar25 + 1;
          iVar20 = iVar20 + 4;
        } while (iVar25 < 2);
        TBasicInst::setEffectCount(this_02,4);
        iVar20 = 0;
        iVar24 = 0;
        do {
          pbVar12 = (byte *)JAudio::JSUConvertOffsetToPtr
                                      (this,*(undefined4 *)(iVar5 + iVar24 + 0x18));
          if (pbVar12 != (byte *)0x0) {
            puVar13 = (undefined4 *)JKernel::operator_new(0x10,this_00,0);
            if (puVar13 == (undefined4 *)0x0) {
              uVar6 = JUTAssertion::getSDevice();
              in_r6 = "randp != 0";
              JUTAssertion::showAssert(uVar6,"JASBNKParser.cpp",0x78,"randp != 0");
              m_Do_printf::OSPanic("JASBNKParser.cpp",0x78,&DAT_80367ddc);
            }
            else {
              *puVar13 = &TInstEffect::__vt;
              *(undefined *)(puVar13 + 1) = 0;
              *puVar13 = &TInstRand::__vt;
              puVar13[2] = JAudio::_906;
              puVar13[3] = JAudio::_907;
            }
            TInstEffect::setTarget((TInstEffect *)puVar13,(uint)*pbVar12);
            puVar13[2] = *(undefined4 *)(pbVar12 + 4);
            puVar13[3] = *(undefined4 *)(pbVar12 + 8);
            TBasicInst::setEffect(this_02,iVar20,(TInstEffect *)puVar13);
          }
          iVar20 = iVar20 + 1;
          iVar24 = iVar24 + 4;
        } while (iVar20 < 2);
        iVar20 = 0;
        iVar24 = 0;
        do {
          pbVar12 = (byte *)JAudio::JSUConvertOffsetToPtr
                                      (this,*(undefined4 *)(iVar5 + iVar24 + 0x20));
          if (pbVar12 != (byte *)0x0) {
            puVar13 = (undefined4 *)JKernel::operator_new(0x14,this_00,0);
            if (puVar13 == (undefined4 *)0x0) {
              uVar6 = JUTAssertion::getSDevice();
              in_r6 = "sensep != 0";
              JUTAssertion::showAssert(uVar6,"JASBNKParser.cpp",0x85,"sensep != 0");
              m_Do_printf::OSPanic("JASBNKParser.cpp",0x85,&DAT_80367ddc);
            }
            else {
              *puVar13 = &TInstEffect::__vt;
              *(undefined *)(puVar13 + 1) = 0;
              *puVar13 = &TInstSense::__vt;
              *(undefined *)(puVar13 + 2) = 0;
              *(undefined *)((int)puVar13 + 9) = 0x3c;
              fVar2 = JAudio::_906;
              puVar13[3] = JAudio::_906;
              puVar13[4] = fVar2;
            }
            TInstEffect::setTarget((TInstEffect *)puVar13,(uint)*pbVar12);
            TInstSense::setParams
                      ((TInstSense *)puVar13,(uint)pbVar12[1],(uint)pbVar12[2],
                       *(float *)(pbVar12 + 4),*(float *)(pbVar12 + 8));
            TBasicInst::setEffect(this_02,iVar20 + 2,(TInstEffect *)puVar13);
          }
          iVar20 = iVar20 + 1;
          iVar24 = iVar24 + 4;
        } while (iVar20 < 2);
        TBasicInst::setKeyRegionCount(this_02,*(ulong *)(iVar5 + 0x28));
        iVar20 = 0;
        for (uVar3 = 0; uVar3 < *(uint *)(iVar5 + 0x28); uVar3 = uVar3 + 1) {
          puVar18 = (uint *)TBasicInst::getKeyRegion(this_02,uVar3);
          pbVar12 = (byte *)JAudio::JSUConvertOffsetToPtr
                                      (this,*(undefined4 *)(iVar5 + iVar20 + 0x2c));
          *puVar18 = (uint)*pbVar12;
          TBasicInst::TKeymap::setVeloRegionCount((TKeymap *)puVar18,*(ulong *)(pbVar12 + 4));
          iVar24 = 0;
          for (uVar22 = 0; uVar22 < *(uint *)(pbVar12 + 4); uVar22 = uVar22 + 1) {
            puVar14 = (uint *)TBasicInst::TKeymap::getVeloRegion((TKeymap *)puVar18,uVar22);
            pbVar15 = (byte *)JAudio::JSUConvertOffsetToPtr
                                        (this,*(undefined4 *)(pbVar12 + iVar24 + 8));
            *puVar14 = (uint)*pbVar15;
            puVar14[1] = *(uint *)(pbVar15 + 4) & 0xffff;
            puVar14[2] = *(uint *)(pbVar15 + 8);
            puVar14[3] = *(uint *)(pbVar15 + 0xc);
            iVar24 = iVar24 + 4;
          }
          iVar20 = iVar20 + 4;
        }
        TBasicBank::setInst(this_01,iVar21,(TInst *)this_02);
      }
      iVar21 = iVar21 + 1;
      iVar19 = iVar19 + 4;
    } while (iVar21 < 0x80);
    iVar21 = 0;
    iVar19 = 0;
    do {
      piVar16 = (int *)JAudio::JSUConvertOffsetToPtr(this,*(undefined4 *)(this + iVar19 + 0x3b4));
      if (piVar16 != (int *)0x0) {
        puVar13 = (undefined4 *)JKernel::operator_new(0x1004,this_00,0);
        if (puVar13 == (undefined4 *)0x0) {
          uVar6 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar6,"JASBNKParser.cpp",0xb7,"setp != 0");
          m_Do_printf::OSPanic("JASBNKParser.cpp",0xb7,&DAT_80367ddc);
        }
        else {
          *puVar13 = &TInst::__vt;
          *puVar13 = &TDrumSet::__vt;
          Runtime.PPCEABI.H::__construct_array
                    (puVar13 + 1,TDrumSet::TPerc::TPerc,TDrumSet::TPerc::_TPerc,0x20,0x80);
        }
        iVar24 = 0;
        iVar5 = 0;
        iVar20 = 0;
        do {
          puVar17 = (undefined4 *)
                    JAudio::JSUConvertOffsetToPtr
                              (this,*(undefined4 *)((int)piVar16 + iVar20 + 0x88));
          if (puVar17 != (undefined4 *)0x0) {
            this_03 = (undefined4 *)TDrumSet::getPerc((TDrumSet *)puVar13,iVar24);
            *this_03 = *puVar17;
            this_03[1] = puVar17[1];
            if (*piVar16 == 0x50455232) {
              this_03[2] = (float)((double)CONCAT44(0x43300000,
                                                    (int)*(char *)((int)piVar16 + iVar24 + 0x288) ^
                                                    0x80000000) - JAudio::_910) / JAudio::_908;
              TDrumSet::TPerc::setRelease
                        ((TPerc *)this_03,(uint)*(ushort *)((int)piVar16 + iVar5 + 0x308));
            }
            TDrumSet::TPerc::setEffectCount((TPerc *)this_03,2);
            iVar23 = 0;
            iVar10 = 0;
            iVar25 = 0;
            do {
              pbVar12 = (byte *)JAudio::JSUConvertOffsetToPtr
                                          (this,*(undefined4 *)((int)puVar17 + iVar25 + 8));
              if (pbVar12 != (byte *)0x0) {
                this_04 = (undefined4 *)JKernel::operator_new(0x10,this_00,0);
                if (this_04 == (undefined4 *)0x0) {
                  uVar6 = JUTAssertion::getSDevice();
                  JUTAssertion::showAssert(uVar6,"JASBNKParser.cpp",0xcf,"randp != 0");
                  m_Do_printf::OSPanic("JASBNKParser.cpp",0xcf,&DAT_80367ddc);
                }
                else {
                  *this_04 = &TInstEffect::__vt;
                  *(undefined *)(this_04 + 1) = 0;
                  *this_04 = &TInstRand::__vt;
                  this_04[2] = JAudio::_906;
                  this_04[3] = JAudio::_907;
                }
                TInstEffect::setTarget((TInstEffect *)this_04,(uint)*pbVar12);
                this_04[2] = *(undefined4 *)(pbVar12 + 4);
                this_04[3] = *(undefined4 *)(pbVar12 + 8);
                TDrumSet::TPerc::setEffect((TPerc *)this_03,iVar23,(TInstEffect *)this_04);
                iVar23 = iVar23 + 1;
              }
              iVar10 = iVar10 + 1;
              iVar25 = iVar25 + 4;
            } while (iVar10 < 2);
            TDrumSet::TPerc::setVeloRegionCount((TPerc *)this_03,puVar17[4]);
            iVar25 = 0;
            for (uVar3 = 0; uVar3 < (uint)puVar17[4]; uVar3 = uVar3 + 1) {
              puVar18 = (uint *)TDrumSet::TPerc::getVeloRegion((TPerc *)this_03,uVar3);
              pbVar12 = (byte *)JAudio::JSUConvertOffsetToPtr
                                          (this,*(undefined4 *)((int)puVar17 + iVar25 + 0x14));
              *puVar18 = (uint)*pbVar12;
              puVar18[1] = *(uint *)(pbVar12 + 4) & 0xffff;
              puVar18[2] = *(uint *)(pbVar12 + 8);
              puVar18[3] = *(uint *)(pbVar12 + 0xc);
              iVar25 = iVar25 + 4;
            }
          }
          iVar24 = iVar24 + 1;
          iVar5 = iVar5 + 2;
          iVar20 = iVar20 + 4;
        } while (iVar24 < 0x80);
        TBasicBank::setInst(this_01,iVar21 + 0xe4,(TInst *)puVar13);
      }
      iVar21 = iVar21 + 1;
      iVar19 = iVar19 + 4;
    } while (iVar21 < 0xc);
    iVar19 = JKRHeap::getFreeSize(this_00);
    _sUsedHeapSize = _sUsedHeapSize + (iVar4 - iVar19);
  }
  return this_01;
}


/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* __thiscall BNKParser::findOscPtr(TBasicBank *,
                                              BNKParser::THeader *,
                                              BNKParser::TOsc *) */

undefined4 __thiscall
BNKParser::findOscPtr(BNKParser *this,TBasicBank *param_1,THeader *param_2,TOsc *param_3)

{
  int iVar1;
  THeader *pTVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined local_78 [4];
  undefined4 local_74;
  int local_70;
  uint local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  undefined local_40;
  undefined2 local_3e;
  undefined4 local_3c;
  undefined4 local_38;
  
  iVar5 = 0;
  iVar7 = 0;
  do {
    iVar1 = JAudio::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(param_1 + iVar7 + 0x24));
    if (iVar1 != 0) {
      uVar4 = 0;
      iVar6 = 0;
      do {
        pTVar2 = (THeader *)
                 JAudio::JSUConvertOffsetToPtr(param_1,*(undefined4 *)(iVar1 + iVar6 + 0x10));
        if ((pTVar2 == param_2) &&
           (piVar3 = (int *)(**(code **)(*(int *)this + 0xc))(this,iVar5), piVar3 != (int *)0x0)) {
          local_78[0] = 0;
          local_74 = 0;
          local_70 = 0;
          local_6c = 0;
          local_68 = JAudio::_906;
          local_64 = JAudio::_906;
          local_60 = JAudio::_906;
          local_5c = JAudio::_906;
          local_58 = JAudio::_974;
          local_54 = JAudio::_907;
          local_50 = JAudio::_907;
          local_4c = JAudio::_974;
          local_48 = JAudio::_907;
          local_44 = JAudio::_907;
          local_40 = 0;
          local_3e = 0;
          local_3c = 0;
          local_38 = 0;
          (**(code **)(*piVar3 + 0xc))(piVar3,0x3c,0x7f,local_78);
          if (uVar4 < local_6c) {
            return *(undefined4 *)(local_70 + iVar6);
          }
        }
        uVar4 = uVar4 + 1;
        iVar6 = iVar6 + 4;
      } while ((int)uVar4 < 2);
    }
    iVar5 = iVar5 + 1;
    iVar7 = iVar7 + 4;
  } while (iVar5 < 0x80);
  return 0;
}


/* __thiscall BNKParser::getOscTableEndPtr(short *) */

void __thiscall BNKParser::getOscTableEndPtr(BNKParser *this,short *param_1)

{
  short sVar1;
  
  do {
    sVar1 = *(short *)this;
    this = (BNKParser *)((int)this + 6);
  } while (sVar1 < 0xb);
  return;
}

}

namespace JAudio {

/* __stdcall JSUConvertOffsetToPtr<JASystem::BNKParser::TPmap>(void const *,
                                                               unsigned long) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<JASystem::BNKParser::TPerc>(void const *,
                                                               unsigned long) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<JASystem::BNKParser::TVmap>(void const *,
                                                               unsigned long) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<JASystem::BNKParser::TKeymap>(void const *,
                                                                 unsigned long) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<JASystem::BNKParser::TSense>(void const *,
                                                                unsigned long) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<JASystem::BNKParser::TRand>(void const *,
                                                               unsigned long) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<short>(void const *,
                                          unsigned long) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<JASystem::BNKParser::TOsc>(void const *,
                                                              unsigned long) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}


/* __stdcall JSUConvertOffsetToPtr<JASystem::BNKParser::TInst>(void const *,
                                                               unsigned long) */

int JSUConvertOffsetToPtr(int param_1,int param_2)

{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}

