#include <JAudio/JASOscillator.h>
#include <m_Do_printf.h>
#include <JAudio/JASOscillator.h>
#include <JAudio/JASDriverIF.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JASystem/TOscillator.h>


namespace JASystem {

/* __thiscall TOscillator::init(void) */

int __thiscall TOscillator::init(TOscillator *this,EVP_PKEY_CTX *ctx)

{
  float fVar1;
  
  *(undefined4 *)this = 0;
  this[4] = (TOscillator)0x1;
  this[5] = (TOscillator)0x0;
  *(undefined2 *)(this + 6) = 0;
  fVar1 = JAudio::_394;
  *(float *)(this + 8) = JAudio::_394;
  *(float *)(this + 0xc) = fVar1;
  *(float *)(this + 0x10) = fVar1;
  *(float *)(this + 0x14) = fVar1;
  *(undefined2 *)(this + 0x18) = 0;
  *(float *)(this + 0x1c) = fVar1;
  return (int)this;
}


/* __thiscall TOscillator::initStart(void) */

void __thiscall TOscillator::initStart(TOscillator *this)

{
  float fVar1;
  
  this[4] = (TOscillator)0x2;
  *(undefined2 *)(this + 0x18) = 0;
  if ((*(int *)this != 0) && (*(int *)(*(int *)this + 8) != 0)) {
    *(undefined2 *)(this + 6) = 0;
    fVar1 = JAudio::_394;
    *(float *)(this + 8) = JAudio::_394;
    *(float *)(this + 0x10) = fVar1;
    *(undefined2 *)(this + 0x18) = 0;
    *(float *)(this + 8) = *(float *)(this + 8) - *(float *)(*(int *)this + 4);
    return;
  }
  *(float *)(this + 0xc) = JAudio::_394;
  return;
}


/* WARNING: Removing unreachable block (ram,0x8028df84) */
/* __thiscall TOscillator::getOffset(void) */

double __thiscall TOscillator::getOffset(TOscillator *this)

{
  TOscillator TVar1;
  int iVar2;
  short *psVar3;
  double dVar4;
  
  iVar2 = *(int *)this;
  if (iVar2 == 0) {
    m_Do_printf::OSReport("----- Oscillator is NULL\n");
    dVar4 = (double)JAudio::_427;
    *(float *)(this + 0xc) = JAudio::_427;
    return dVar4;
  }
  TVar1 = this[4];
  if (TVar1 != (TOscillator)0x2) {
    if ((byte)TVar1 < 2) {
      if (TVar1 == (TOscillator)0x0) {
        return (double)JAudio::_427;
      }
      this[4] = (TOscillator)0x2;
      m_Do_printf::OSReport("----- Error Initialize\n");
    }
    else {
      if ((byte)TVar1 < 4) {
        return (double)(*(float *)(iVar2 + 0x14) + *(float *)(this + 0xc) * *(float *)(iVar2 + 0x10)
                       );
      }
    }
  }
  TVar1 = this[4];
  if (TVar1 == (TOscillator)0x4) {
    psVar3 = *(short **)(*(int *)this + 0xc);
  }
  else {
    if (TVar1 == (TOscillator)0x5) {
      psVar3 = (short *)&oscTableForceStop;
    }
    else {
      psVar3 = *(short **)(*(int *)this + 8);
    }
  }
  if ((psVar3 == (short *)0x0) && (TVar1 != (TOscillator)0x6)) {
    dVar4 = (double)JAudio::_427;
    *(float *)(this + 0xc) = JAudio::_427;
  }
  else {
    if (TVar1 == (TOscillator)0x5) {
      *(float *)(this + 8) = *(float *)(this + 8) - JAudio::_427;
    }
    else {
      *(float *)(this + 8) = *(float *)(this + 8) - *(float *)(*(int *)this + 4);
    }
    dVar4 = (double)calc(this,psVar3);
  }
  return dVar4;
}


/* __thiscall TOscillator::forceStop(void) */

undefined4 __thiscall TOscillator::forceStop(TOscillator *this)

{
  if (this[4] == (TOscillator)0x5) {
    return 0;
  }
  *(undefined2 *)(this + 6) = 0;
  *(float *)(this + 8) = JAudio::_394;
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(this + 0xc);
  this[4] = (TOscillator)0x5;
  return 1;
}


/* WARNING: Removing unreachable block (ram,0x8028e21c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall TOscillator::release(void) */

undefined4 __thiscall TOscillator::release(TOscillator *this)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined8 in_f31;
  double dVar4;
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if (this[4] == (TOscillator)0x5) {
    uVar1 = 0;
  }
  else {
    if (*(int *)(*(int *)this + 8) != *(int *)(*(int *)this + 0xc)) {
      *(undefined2 *)(this + 6) = 0;
      *(float *)(this + 8) = JAudio::_394;
      *(undefined4 *)(this + 0x10) = *(undefined4 *)(this + 0xc);
    }
    if ((*(int *)(*(Driver **)this + 0xc) == 0) && (*(short *)(this + 0x18) == 0)) {
      *(undefined2 *)(this + 0x18) = 0x10;
    }
    if (*(short *)(this + 0x18) == 0) {
      this[4] = (TOscillator)0x4;
    }
    else {
      this[4] = (TOscillator)0x6;
      this[5] = SUB21((ushort)*(undefined2 *)(this + 0x18) >> 0xe,0);
      dVar4 = (double)((float)((double)CONCAT44(0x43300000,
                                                *(ushort *)(this + 0x18) & 0x3fff ^ 0x80000000) -
                              JAudio::_468) * ((_gDacRate / JAudio::_465) / JAudio::_466));
      uVar2 = Driver::getUpdateInterval(*(Driver **)this);
      *(float *)(this + 8) =
           (float)(dVar4 / (double)(float)((double)CONCAT44(0x43300000,uVar2 & 0xff) - JAudio::_470)
                  );
      if (*(float *)(this + 8) < JAudio::_427) {
        *(float *)(this + 8) = JAudio::_427;
      }
      *(undefined4 *)(this + 0x1c) = *(undefined4 *)(this + 8);
      *(float *)(this + 0x10) = JAudio::_394;
      if (this[5] == (TOscillator)0x0) {
        *(float *)(this + 0x14) =
             (*(float *)(this + 0x10) - *(float *)(this + 0xc)) / *(float *)(this + 8);
      }
      else {
        *(float *)(this + 0x14) = *(float *)(this + 0x10) - *(float *)(this + 0xc);
      }
    }
    uVar1 = 1;
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return uVar1;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x8028e5c4) */
/* WARNING: Removing unreachable block (ram,0x8028e5cc) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall TOscillator::calc(short *) */

double __thiscall TOscillator::calc(TOscillator *this,short *param_1)

{
  TOscillator TVar1;
  float fVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short *this_00;
  uint uVar6;
  undefined1 *puVar7;
  undefined4 uVar8;
  undefined8 in_f30;
  double dVar9;
  undefined8 in_f31;
  double dVar10;
  double dVar11;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar8 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  dVar10 = (double)JAudio::_394;
LAB_8028e408:
  do {
    if (dVar10 < (double)*(float *)(this + 8)) {
LAB_8028e418:
      if ((double)JAudio::_394 == (double)*(float *)(*(int *)this + 0x10)) {
        dVar10 = (double)*(float *)(*(int *)this + 0x14);
      }
      else {
        dVar10 = (double)*(float *)(this + 0x1c);
        if (JAudio::_539 == dVar10) {
          fVar2 = *(float *)(this + 0x10);
          *(float *)(this + 0xc) = fVar2;
        }
        else {
          TVar1 = this[5];
          if ((TVar1 == (TOscillator)0x0) ||
             (dVar11 = (double)*(float *)(this + 0x14), (double)JAudio::_394 == dVar11)) {
            fVar2 = *(float *)(this + 0x10) - *(float *)(this + 0x14) * *(float *)(this + 8);
            *(float *)(this + 0xc) = fVar2;
          }
          else {
            if (((TVar1 == (TOscillator)0x3) || (TVar1 == (TOscillator)0x1)) ||
               (TVar1 == (TOscillator)0x2)) {
              puVar7 = (undefined1 *)0x0;
              if (TVar1 == (TOscillator)0x2) {
                puVar7 = &relTableSqRoot;
              }
              else {
                if ((byte)TVar1 < 2) {
                  if (TVar1 != (TOscillator)0x0) {
                    puVar7 = &relTableSquare;
                  }
                }
                else {
                  if ((byte)TVar1 < 4) {
                    puVar7 = &relTableSampleCell;
                  }
                }
              }
              if ((double)JAudio::_394 <= dVar11) {
                fVar2 = (float)((double)*(float *)(this + 8) / dVar10);
              }
              else {
                fVar2 = JAudio::_427 - (float)((double)*(float *)(this + 8) / dVar10);
              }
              dVar10 = (double)(JAudio::_540 * fVar2);
              uVar6 = Runtime.PPCEABI.H::__cvt_fp2unsigned(dVar10);
              fVar2 = (float)(dVar10 - (double)(float)((double)CONCAT44(0x43300000,uVar6) -
                                                      JAudio::_470));
              if (0xf < uVar6) {
                uVar6 = 0xf;
                fVar2 = JAudio::_427;
              }
              fVar2 = ABS((float)(dVar11 * (double)(*(float *)(puVar7 + uVar6 * 4) +
                                                   fVar2 * (*(float *)(puVar7 + uVar6 * 4 + 4) -
                                                           *(float *)(puVar7 + uVar6 * 4)))));
              if (JAudio::_394 <= *(float *)(this + 0x14)) {
                fVar2 = *(float *)(this + 0x10) - (*(float *)(this + 0x14) - fVar2);
              }
              else {
                fVar2 = *(float *)(this + 0x10) + fVar2;
              }
              *(float *)(this + 0xc) = fVar2;
            }
            else {
              fVar2 = *(float *)(this + 0x10) - (float)(dVar11 * (double)*(float *)(this + 8));
              *(float *)(this + 0xc) = fVar2;
            }
          }
        }
        dVar10 = (double)(*(float *)(*(int *)this + 0x14) + fVar2 * *(float *)(*(int *)this + 0x10))
        ;
      }
LAB_8028e5c4:
      __psq_l0(auStack8,uVar8);
      __psq_l1(auStack8,uVar8);
      __psq_l0(auStack24,uVar8);
      __psq_l1(auStack24,uVar8);
      return dVar10;
    }
    *(undefined4 *)(this + 0xc) = *(undefined4 *)(this + 0x10);
    if (this[4] == (TOscillator)0x6) {
      this[4] = (TOscillator)0x0;
      goto LAB_8028e418;
    }
    this_00 = param_1 + (uint)*(ushort *)(this + 6) * 3;
    sVar3 = *this_00;
    sVar4 = this_00[1];
    sVar5 = this_00[2];
    if (sVar3 == 0xd) {
      *(short *)(this + 6) = sVar5;
      goto LAB_8028e408;
    }
    if (sVar3 == 0xf) {
      this[4] = (TOscillator)0x0;
      goto LAB_8028e418;
    }
    if (sVar3 == 0xe) {
      this[4] = (TOscillator)0x3;
      dVar10 = (double)(*(float *)(*(int *)this + 0x14) +
                       *(float *)(this + 0xc) * *(float *)(*(int *)this + 0x10));
      goto LAB_8028e5c4;
    }
    this[5] = SUB21(sVar3,0);
    if (sVar4 == 0) {
      *(float *)(this + 0x10) =
           (float)((double)CONCAT44(0x43300000,(int)sVar5 ^ 0x80000000) - JAudio::_468) /
           JAudio::_538;
      *(short *)(this + 6) = *(short *)(this + 6) + 1;
    }
    else {
      dVar9 = (double)_gDacRate;
      uVar6 = Driver::getUpdateInterval((Driver *)this_00);
      dVar11 = JAudio::_468;
      *(float *)(this + 8) =
           ((float)((double)CONCAT44(0x43300000,(int)sVar4 ^ 0x80000000) - JAudio::_468) *
           ((float)(dVar9 / (double)JAudio::_465) / JAudio::_466)) /
           (float)((double)CONCAT44(0x43300000,uVar6 & 0xff) - JAudio::_470);
      *(undefined4 *)(this + 0x1c) = *(undefined4 *)(this + 8);
      *(float *)(this + 0x10) =
           (float)((double)CONCAT44(0x43300000,(int)sVar5 ^ 0x80000000) - dVar11) / JAudio::_538;
      if (this[5] == (TOscillator)0x0) {
        *(float *)(this + 0x14) =
             (*(float *)(this + 0x10) - *(float *)(this + 0xc)) / *(float *)(this + 8);
      }
      else {
        *(float *)(this + 0x14) = *(float *)(this + 0x10) - *(float *)(this + 0xc);
      }
      *(short *)(this + 6) = *(short *)(this + 6) + 1;
    }
  } while( true );
}

