#include <JAZelAudio/JAIZelInst.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <JAudio/JAIBasic.h>
#include <JAudio/JAISound.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JAZelAudio/JAIZelInst.h>
#include <JAIZelInst.h>


/* __thiscall JAIZelInst::JAIZelInst(void) */

void __thiscall JAIZelInst::JAIZelInst(JAIZelInst *this)

{
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0xffffffff;
  *(undefined4 *)(this + 0x14) = 0x2f;
  this[0x1f] = (JAIZelInst)0x3;
  *(float *)(this + 0x20) = JAZelAudio::_769;
  *(float *)(this + 0x24) = JAZelAudio::_770;
  *(float *)(this + 0x28) = JAZelAudio::_771;
  *(float *)(this + 0x2c) = JAZelAudio::_772;
  *(float *)(this + 0x30) = JAZelAudio::_773 * *(float *)(this + 0x2c);
  this[0x1e] = (JAIZelInst)0x0;
  this[0x48] = (JAIZelInst)0x0;
  this[0x34] = (JAIZelInst)0x37;
  return;
}


/* __thiscall JAIZelInst::reset(void) */

void __thiscall JAIZelInst::reset(JAIZelInst *this)

{
  *(undefined4 *)(this + 0xc) = 0;
  this[0x1f] = (JAIZelInst)0x3;
  *(float *)(this + 0x20) = JAZelAudio::_769;
  *(float *)(this + 0x24) = JAZelAudio::_770;
  *(float *)(this + 0x28) = JAZelAudio::_771;
  *(float *)(this + 0x2c) = JAZelAudio::_772;
  *(float *)(this + 0x30) = JAZelAudio::_773 * *(float *)(this + 0x2c);
  this[0x1e] = (JAIZelInst)0x0;
  this[0x34] = (JAIZelInst)0x37;
  this[0x48] = (JAIZelInst)0x0;
  JAIZelBasic::seStop(JAIZelBasic::zel_basic,0x2867,0);
  JAIZelBasic::seStop(JAIZelBasic::zel_basic,0x887,0);
  JAIZelBasic::seStop(JAIZelBasic::zel_basic,0x888,0);
  JAIZelBasic::seStop(JAIZelBasic::zel_basic,0x8ed,0);
  JAIZelBasic::seStop(JAIZelBasic::zel_basic,0x8ee,0);
  JAIZelBasic::seStop(JAIZelBasic::zel_basic,0x893,0);
  JAIZelBasic::seStop(JAIZelBasic::zel_basic,0x894,0);
  JAIZelBasic::seStop(JAIZelBasic::zel_basic,0x895,0);
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x3c) = 0;
  *(undefined4 *)(this + 0x40) = 0;
  *(undefined4 *)(this + 0x44) = 0;
  return;
}


/* __thiscall JAIZelInst::playArmSwing(long,
                                       long) */

void __thiscall JAIZelInst::playArmSwing(JAIZelInst *this,long param_1,long param_2)

{
  byte bVar1;
  ulong uVar2;
  int iVar3;
  
  iVar3 = param_2 + param_1 * 5;
  if (0x18 < iVar3) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"JAIZelInst.cpp",0x5d,"pos < 25");
    m_Do_printf::OSPanic("JAIZelInst.cpp",0x5d,&DAT_8036a750);
  }
  bVar1 = (&m_stick_to_note_table)[iVar3];
  JAIZelBasic::seStart
            (JAIZelBasic::zel_basic,0x285f,(cXyz *)0x0,
             *(int *)(this + 0x14) * 0x10000 + bVar1 + 0x2f,0,JAZelAudio::_772,JAZelAudio::_772,
             JAZelAudio::_793,JAZelAudio::_793,0);
  *(uint *)(this + 0x14) = bVar1 + 0x2f;
  return;
}


/* __thiscall JAIZelInst::stopArmSwing(void) */

void __thiscall JAIZelInst::stopArmSwing(JAIZelInst *this)

{
  JAIZelBasic::seStop(JAIZelBasic::zel_basic,0x285f,0);
  *(undefined4 *)(this + 0x14) = 0x2f;
  return;
}


/* __thiscall JAIZelInst::setStickPos(long,
                                      long) */

int __thiscall JAIZelInst::setStickPos(JAIZelInst *this,long param_1,long param_2)

{
  JAIZelInst JVar1;
  ulong uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  iVar7 = param_2 + param_1 * 5;
  if (0x18 < iVar7) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"JAIZelInst.cpp",0x80,"pos < 25");
    m_Do_printf::OSPanic("JAIZelInst.cpp",0x80,&DAT_8036a750);
  }
  JVar1 = *(JAIZelInst *)(&m_stick_to_note_table + iVar7);
  *(uint *)(this + 0x10) = (byte)JVar1 + 0x2f;
  if (4 < *(int *)(this + 0xc)) {
    iVar7 = 0;
    iVar9 = 5;
    do {
      (this + iVar7)[4] = (this + iVar7)[5];
      iVar7 = iVar7 + 1;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    *(undefined4 *)(this + 0xc) = 4;
  }
  this[*(int *)(this + 0xc) + 4] = JVar1;
  *(int *)(this + 0xc) = *(int *)(this + 0xc) + 1;
  iVar7 = *(int *)(this + 0xc);
  if (1 < iVar7) {
    for (iVar9 = 0; iVar9 < iVar7; iVar9 = iVar9 + 1) {
      iVar3 = 0;
      iVar4 = 0;
      iVar6 = iVar7 - iVar9;
      do {
        iVar8 = 0;
        iVar5 = 0;
        iVar10 = iVar6;
        if (0 < iVar6) {
          do {
            if ((ushort)(byte)this[iVar8 + 4 + iVar9] !=
                *(ushort *)(&m_note_pattern + iVar4 + iVar5 + 2) >> 8) break;
            iVar8 = iVar8 + 1;
            iVar5 = iVar5 + 2;
            iVar10 = iVar10 + -1;
          } while (iVar10 != 0);
        }
        if (iVar8 == iVar6) {
          if (4 < iVar8) {
            return iVar3;
          }
          if (*(short *)(&m_note_pattern + iVar4 + iVar8 * 2 + 2) == -1) {
            return iVar3;
          }
        }
        iVar3 = iVar3 + 1;
        iVar4 = iVar4 + 0xc;
      } while (iVar3 < 6);
    }
  }
  return -1;
}


/* __thiscall JAIZelInst::play(void) */

void __thiscall JAIZelInst::play(JAIZelInst *this)

{
  if (-1 < *(int *)(this + 0x10)) {
    JAIBasic::startSoundVec
              ((JAIBasic *)JAIZelBasic::zel_basic,JA_SE_WINDTAKT_PLAY,(JAISound **)this,(Vec *)0x0,0
               ,0,'\x04');
    if (*(JAISound **)this != (JAISound *)0x0) {
      JAISound::setPortData(*(JAISound **)this,'\b',(ushort)*(undefined4 *)(this + 0x10));
    }
  }
  return;
}


/* __thiscall JAIZelInst::setBeat(long) */

void __thiscall JAIZelInst::setBeat(JAIZelInst *this,long param_1)

{
  JAIZelInst JVar1;
  
  if (param_1 == 2) {
    this[0x1f] = (JAIZelInst)0x6;
  }
  else {
    if (param_1 < 2) {
      if (param_1 != 0) {
        return;
      }
      this[0x1f] = (JAIZelInst)0x3;
    }
    else {
      if (param_1 != 4) {
        return;
      }
      this[0x1f] = (JAIZelInst)0x4;
    }
  }
  JVar1 = this[0x1f];
  if (JVar1 != (JAIZelInst)0x5) {
    if ((byte)JVar1 < 5) {
      if (JVar1 == (JAIZelInst)0x3) {
        *(float *)(this + 0x24) = JAZelAudio::_770;
        *(float *)(this + 0x28) = JAZelAudio::_771;
        *(float *)(this + 0x2c) = JAZelAudio::_772;
      }
      else {
        if (2 < (byte)JVar1) {
          *(float *)(this + 0x24) = JAZelAudio::_899;
          *(float *)(this + 0x28) = JAZelAudio::_900;
          *(float *)(this + 0x2c) = JAZelAudio::_901;
        }
      }
    }
    else {
      if ((byte)JVar1 < 7) {
        *(float *)(this + 0x24) = JAZelAudio::_902;
        *(float *)(this + 0x28) = JAZelAudio::_903;
        *(float *)(this + 0x2c) = JAZelAudio::_904;
      }
    }
  }
  *(float *)(this + 0x30) = JAZelAudio::_773 * *(float *)(this + 0x2c);
  return;
}


/* __thiscall JAIZelInst::setVolume(float) */

void __thiscall JAIZelInst::setVolume(JAIZelInst *this,float param_1)

{
  float fVar1;
  
  fVar1 = param_1 / JAZelAudio::_913;
  if (JAZelAudio::_772 < param_1 / JAZelAudio::_913) {
    fVar1 = JAZelAudio::_772;
  }
  if (fVar1 < JAZelAudio::_793) {
    fVar1 = JAZelAudio::_793;
  }
  *(float *)(this + 0x20) = JAZelAudio::_914 + JAZelAudio::_915 * fVar1;
  return;
}


/* __thiscall JAIZelInst::metronomePlay(long,
                                        long) */

undefined4 __thiscall JAIZelInst::metronomePlay(JAIZelInst *this,long param_1,long param_2)

{
  JAIZelInst JVar1;
  JAISound *pJVar2;
  
  if ((param_2 < 0) || (4 < param_2)) {
    m_Do_printf::OSReport("[JAIZelInst::metronomePlay] WARNING : c_pos over range!\n");
    return 0xfffffffe;
  }
  if (param_1 == 0) {
    JVar1 = this[0x1f];
    if (JVar1 != (JAIZelInst)0x5) {
      if ((byte)JVar1 < 5) {
        if (JVar1 == (JAIZelInst)0x3) {
          pJVar2 = (JAISound *)
                   JAIZelBasic::seStart
                             (JAIZelBasic::zel_basic,0x888,(cXyz *)0x0,0,0,JAZelAudio::_772,
                              *(float *)(this + 0x20),JAZelAudio::_793,JAZelAudio::_793,0);
          *(JAISound **)(this + 0x40) = pJVar2;
        }
        else {
          if (2 < (byte)JVar1) {
            pJVar2 = (JAISound *)
                     JAIZelBasic::seStart
                               (JAIZelBasic::zel_basic,0x8ed,(cXyz *)0x0,0,0,JAZelAudio::_772,
                                *(float *)(this + 0x20),JAZelAudio::_793,JAZelAudio::_793,0);
            *(JAISound **)(this + 0x40) = pJVar2;
          }
        }
      }
      else {
        if ((byte)JVar1 < 7) {
          pJVar2 = (JAISound *)
                   JAIZelBasic::seStart
                             (JAIZelBasic::zel_basic,0x8ee,(cXyz *)0x0,0,0,JAZelAudio::_772,
                              *(float *)(this + 0x20),JAZelAudio::_793,JAZelAudio::_793,0);
          *(JAISound **)(this + 0x40) = pJVar2;
        }
      }
    }
  }
  else {
    JVar1 = this[0x1f];
    if (JVar1 == (JAIZelInst)0x5) {
      return 0xfffffffe;
    }
    if ((byte)JVar1 < 5) {
      if (JVar1 == (JAIZelInst)0x3) {
        if (param_1 == 2) {
          pJVar2 = (JAISound *)
                   JAIZelBasic::seStart
                             (JAIZelBasic::zel_basic,0x2868,(cXyz *)0x0,0,0,JAZelAudio::_772,
                              *(float *)(this + 0x20),JAZelAudio::_793,JAZelAudio::_793,0);
          *(JAISound **)(this + 0x40) = pJVar2;
        }
        else {
          if ((1 < param_1) || (param_1 < 1)) {
            m_Do_printf::OSReport("[JAIZelInst::metronomePlay] WARNING : now_beat over range!\n");
            return 0xfffffffe;
          }
        }
      }
      else {
        if ((byte)JVar1 < 3) {
          return 0xfffffffe;
        }
        if (param_1 == 3) {
          pJVar2 = (JAISound *)
                   JAIZelBasic::seStart
                             (JAIZelBasic::zel_basic,0x2880,(cXyz *)0x0,0,0,JAZelAudio::_772,
                              *(float *)(this + 0x20),JAZelAudio::_793,JAZelAudio::_793,0);
          *(JAISound **)(this + 0x40) = pJVar2;
        }
        else {
          if ((2 < param_1) || (param_1 < 1)) {
            m_Do_printf::OSReport("[JAIZelInst::metronomePlay] WARNING : now_beat over range!\n");
            return 0xfffffffe;
          }
        }
      }
    }
    else {
      if (6 < (byte)JVar1) {
        return 0xfffffffe;
      }
      if (param_1 == 5) {
        pJVar2 = (JAISound *)
                 JAIZelBasic::seStart
                           (JAIZelBasic::zel_basic,0x2881,(cXyz *)0x0,0,0,JAZelAudio::_772,
                            *(float *)(this + 0x20),JAZelAudio::_793,JAZelAudio::_793,0);
        *(JAISound **)(this + 0x40) = pJVar2;
      }
      else {
        if ((4 < param_1) || (param_1 < 1)) {
          m_Do_printf::OSReport("[JAIZelInst::metronomePlay] WARNING : now_beat over range!\n");
          return 0xfffffffe;
        }
      }
    }
  }
  return 0xffffffff;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JAIZelInst::judge(long,
                                long) */

int __thiscall JAIZelInst::judge(JAIZelInst *this,long param_1,long param_2)

{
  JAIZelInst JVar1;
  int iVar2;
  JAISound *pJVar3;
  int iVar4;
  JAIZelInst *pJVar5;
  uint uVar6;
  uint uVar7;
  JAIZelInst *pJVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  ulong uVar12;
  
  if ((param_2 < 0) || (4 < param_2)) {
    m_Do_printf::OSReport("[JAIZelInst::metronomePlay] WARNING : c_pos over range!\n");
    iVar4 = -2;
  }
  else {
    uVar12 = 0;
    JVar1 = this[0x1f];
    if (JVar1 != (JAIZelInst)0x5) {
      if ((byte)JVar1 < 5) {
        if (JVar1 == (JAIZelInst)0x3) {
          uVar12 = (ulong)(byte)(&mCPosToNote3)[param_2];
        }
        else {
          if (2 < (byte)JVar1) {
            uVar12 = (ulong)(byte)(&mCPosToNote4)[param_2];
          }
        }
      }
      else {
        if ((byte)JVar1 < 7) {
          if (this[0x48] == (JAIZelInst)0x0) {
            uVar12 = (ulong)(byte)(&mCPosToNote61)[param_2];
          }
          else {
            uVar12 = (ulong)(byte)(&mCPosToNote62)[param_2];
          }
        }
      }
    }
    if (JVar1 != (JAIZelInst)0x5) {
      if ((byte)JVar1 < 5) {
        if (JVar1 == (JAIZelInst)0x3) {
          pJVar3 = (JAISound *)
                   JAIZelBasic::seStart
                             (JAIZelBasic::zel_basic,0x893,(cXyz *)0x0,uVar12,0,JAZelAudio::_772,
                              *(float *)(this + 0x20),JAZelAudio::_793,JAZelAudio::_793,0);
          *(JAISound **)(this + 0x44) = pJVar3;
        }
        else {
          if (2 < (byte)JVar1) {
            pJVar3 = (JAISound *)
                     JAIZelBasic::seStart
                               (JAIZelBasic::zel_basic,0x894,(cXyz *)0x0,uVar12,0,JAZelAudio::_772,
                                *(float *)(this + 0x20),JAZelAudio::_793,JAZelAudio::_793,0);
            *(JAISound **)(this + 0x44) = pJVar3;
          }
        }
      }
      else {
        if ((byte)JVar1 < 7) {
          pJVar3 = (JAISound *)
                   JAIZelBasic::seStart
                             (JAIZelBasic::zel_basic,0x895,(cXyz *)0x0,uVar12,0,JAZelAudio::_772,
                              *(float *)(this + 0x20),JAZelAudio::_793,JAZelAudio::_793,0);
          *(JAISound **)(this + 0x44) = pJVar3;
        }
      }
    }
    if (param_1 == 0) {
      this[0x1e] = (JAIZelInst)0x0;
      this[0x48] = (JAIZelInst)0x0;
      if ((this[0x1f] == (JAIZelInst)0x6) && (param_2 == 1)) {
        this[0x48] = (JAIZelInst)0x1;
      }
    }
    pJVar3 = (JAISound *)
             JAIZelBasic::seStart
                       (JAIZelBasic::zel_basic,0x887,(cXyz *)0x0,uVar12 + 0x6400,0,JAZelAudio::_772,
                        *(float *)(this + 0x20),JAZelAudio::_793,JAZelAudio::_793,0);
    *(JAISound **)(this + 0x3c) = pJVar3;
    if (param_1 == 5) {
      this[0x48] = (JAIZelInst)0x0;
    }
    if ((byte)this[0x1e] < 6) {
      this[0x1e] = (JAIZelInst)((char)this[0x1e] + 1);
    }
    else {
      this[0x1e] = (JAIZelInst)0x6;
      iVar4 = 0;
      iVar9 = 5;
      do {
        (this + iVar4)[0x18] = (this + iVar4)[0x19];
        iVar4 = iVar4 + 1;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
    }
    this[(byte)this[0x1e] + 0x17] = SUB41(param_2,0);
    uVar7 = (uint)(byte)this[0x1e];
    uVar6 = (uint)(byte)this[0x1f];
    if (uVar7 < uVar6) {
      iVar4 = -1;
    }
    else {
      iVar9 = 0;
      iVar4 = 0;
      do {
        pJVar8 = (JAIZelInst *)(&mMelodyPattern + iVar4);
        if (uVar6 == (byte)*pJVar8) {
          iVar10 = uVar7 - uVar6;
          iVar11 = 1;
          iVar2 = uVar7 - iVar10;
          pJVar5 = pJVar8;
          if (iVar10 < (int)uVar7) {
            do {
              pJVar5 = pJVar5 + 1;
              if (this[iVar10 + 0x18] != *pJVar5) break;
              iVar10 = iVar10 + 1;
              iVar11 = iVar11 + 1;
              iVar2 = iVar2 + -1;
            } while (iVar2 != 0);
          }
          if ((iVar11 == 7) || (pJVar8[iVar11] == (JAIZelInst)0xff)) goto LAB_802aeb34;
        }
        iVar9 = iVar9 + 1;
        iVar4 = iVar4 + 7;
      } while (iVar9 < 8);
      iVar9 = -1;
LAB_802aeb34:
      iVar4 = -1;
      if (-1 < iVar9) {
        iVar4 = iVar9;
      }
    }
  }
  return iVar4;
}


/* __thiscall JAIZelInst::ambientPlay(void) */

void __thiscall JAIZelInst::ambientPlay(JAIZelInst *this)

{
  JAISound *pJVar1;
  
  JAIZelBasic::seStart
            (JAIZelBasic::zel_basic,0x2066,(cXyz *)0x0,0,0,JAZelAudio::_772,*(float *)(this + 0x20),
             JAZelAudio::_793,JAZelAudio::_793,0);
  if ((*(JAISound **)(this + 0x38) != (JAISound *)0x0) &&
     (pJVar1 = *(JAISound **)*(JAISound **)(this + 0x38), pJVar1 != (JAISound *)0x0)) {
    JAISound::setVolume(pJVar1,*(float *)(this + 0x20),3,0);
  }
  if ((*(JAISound **)(this + 0x3c) != (JAISound *)0x0) &&
     (pJVar1 = *(JAISound **)*(JAISound **)(this + 0x3c), pJVar1 != (JAISound *)0x0)) {
    JAISound::setVolume(pJVar1,*(float *)(this + 0x20),3,0);
  }
  if ((*(JAISound **)(this + 0x40) != (JAISound *)0x0) &&
     (pJVar1 = *(JAISound **)*(JAISound **)(this + 0x40), pJVar1 != (JAISound *)0x0)) {
    JAISound::setVolume(pJVar1,*(float *)(this + 0x20),3,0);
  }
  if ((*(JAISound **)(this + 0x44) != (JAISound *)0x0) &&
     (pJVar1 = *(JAISound **)*(JAISound **)(this + 0x44), pJVar1 != (JAISound *)0x0)) {
    JAISound::setVolume(pJVar1,*(float *)(this + 0x20),3,0);
  }
  return;
}


/* __thiscall JAIZelInst::armSoundPlay(long) */

void __thiscall JAIZelInst::armSoundPlay(JAIZelInst *this,long param_1)

{
  JAIZelInst JVar1;
  JAIZelInst JVar2;
  
  JVar2 = (JAIZelInst)0x0;
  JVar1 = this[0x1f];
  if (JVar1 != (JAIZelInst)0x5) {
    if ((byte)JVar1 < 5) {
      if (JVar1 == (JAIZelInst)0x3) {
        JVar2 = *(JAIZelInst *)(&mCPosToNote3 + param_1);
      }
      else {
        if (2 < (byte)JVar1) {
          JVar2 = *(JAIZelInst *)(&mCPosToNote4 + param_1);
        }
      }
    }
    else {
      if ((byte)JVar1 < 7) {
        if (this[0x48] == (JAIZelInst)0x0) {
          JVar2 = *(JAIZelInst *)(&mCPosToNote61 + param_1);
        }
        else {
          JVar2 = *(JAIZelInst *)(&mCPosToNote62 + param_1);
        }
      }
    }
  }
  this[0x34] = JVar2;
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JAIZelInst::getMelodyPattern(long,
                                           long,
                                           long *) */

double __thiscall
JAIZelInst::getMelodyPattern(JAIZelInst *this,long param_1,long param_2,long *param_3)

{
  int iVar1;
  double dVar2;
  
  iVar1 = getMelodyBeat(this,param_1);
  if (param_2 < iVar1) {
    if ((byte)(&DAT_8039b5f5)[param_1 * 7 + param_2] == 0xff) {
      dVar2 = (double)JAZelAudio::_880;
    }
    else {
      *param_3 = (uint)(byte)(&DAT_8039b5f5)[param_1 * 7 + param_2];
      dVar2 = (double)getMelodyGFrames(this,param_1);
    }
  }
  else {
    dVar2 = (double)JAZelAudio::_880;
  }
  return dVar2;
}


/* __thiscall JAIZelInst::getMelodyBeat(long) */

undefined __thiscall JAIZelInst::getMelodyBeat(JAIZelInst *this,long param_1)

{
  ulong uVar1;
  
  if (7 < param_1) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JAIZelInst.cpp",0x33e,"melody_num < (8)");
    m_Do_printf::OSPanic("JAIZelInst.cpp",0x33e,&DAT_8036a750);
  }
  return (&mMelodyPattern)[param_1 * 7];
}


/* __thiscall JAIZelInst::getMelodyGFrames(long) */

double __thiscall JAIZelInst::getMelodyGFrames(JAIZelInst *this,long param_1)

{
  float fVar1;
  int iVar2;
  
  iVar2 = getMelodyBeat(this,param_1);
  fVar1 = JAZelAudio::_772;
  if (iVar2 != 5) {
    if (iVar2 < 5) {
      if ((iVar2 != 3) && (fVar1 = JAZelAudio::_901, iVar2 < 3)) {
        fVar1 = JAZelAudio::_772;
      }
    }
    else {
      if (iVar2 < 7) {
        fVar1 = JAZelAudio::_904;
      }
    }
  }
  return (double)(JAZelAudio::_773 * fVar1);
}


/* __thiscall JAIZelInst::melodyPlay(long) */

void __thiscall JAIZelInst::melodyPlay(JAIZelInst *this,long param_1)

{
  ulong uVar1;
  
  if (7 < param_1) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"JAIZelInst.cpp",0x366,"melody_num < (8)");
    m_Do_printf::OSPanic("JAIZelInst.cpp",0x366,&DAT_8036a750);
  }
  JAIZelBasic::seStart
            (JAIZelBasic::zel_basic,param_1 + 0x889,(cXyz *)0x0,0,0,JAZelAudio::_772,
             JAZelAudio::_772,JAZelAudio::_793,JAZelAudio::_793,0);
  return;
}


/* __thiscall JAIZelInst::melodyStop(void) */

void __thiscall JAIZelInst::melodyStop(JAIZelInst *this)

{
  JAIZelBasic::seStop(JAIZelBasic::zel_basic,0x889,0);
  JAIZelBasic::seStop(JAIZelBasic::zel_basic,0x88a,0);
  JAIZelBasic::seStop(JAIZelBasic::zel_basic,0x88b,0);
  JAIZelBasic::seStop(JAIZelBasic::zel_basic,0x88c,0);
  JAIZelBasic::seStop(JAIZelBasic::zel_basic,0x88d,0);
  JAIZelBasic::seStop(JAIZelBasic::zel_basic,0x88e,0);
  JAIZelBasic::seStop(JAIZelBasic::zel_basic,0x88f,0);
  JAIZelBasic::seStop(JAIZelBasic::zel_basic,0x890,0);
  JAIZelBasic::seStop(JAIZelBasic::zel_basic,0x891,0);
  JAIZelBasic::seStop(JAIZelBasic::zel_basic,0x892,0);
  return;
}

