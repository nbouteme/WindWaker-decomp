#include <d_2dnumber.h>
#include <JKernel/JKRHeap.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <J2DGraph/J2DPicture.h>
#include <MSL_C.PPCEABI.bare.H/printf.h>
#include <d_2dnumber.h>
#include <f_op_msg_mng.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <J2DGraph/J2DTextBox.h>
#include <dDlst_2DOutFont_c.h>
#include <dDlst_2DNumber_c.h>
#include <dDlst_2DMinigame_c.h>
#include <dDlst_2DBattery_c.h>
#include <dDlst_2DObject_c.h>


/* __thiscall dDlst_2DNumber_c::dDlst_2DNumber_c(void) */

void __thiscall dDlst_2DNumber_c::dDlst_2DNumber_c(dDlst_2DNumber_c *this)

{
  *(undefined ***)this = &dDlst_base_c::__vt;
  *(undefined ***)this = &__vt;
  return;
}


/* __thiscall dDlst_2DNumber_c::~dDlst_2DNumber_c(void) */

void __thiscall dDlst_2DNumber_c::_dDlst_2DNumber_c(dDlst_2DNumber_c *this)

{
  short in_r4;
  
  if (this != (dDlst_2DNumber_c *)0x0) {
    *(undefined ***)this = &__vt;
    if (this != (dDlst_2DNumber_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* WARNING: Removing unreachable block (ram,0x800c8624) */
/* __thiscall dDlst_2DNumber_c::init(int,
                                     short,
                                     short,
                                     short,
                                     short,
                                     unsigned char) */

int __thiscall
dDlst_2DNumber_c::init
          (dDlst_2DNumber_c *this,int param_1,short param_2,short param_3,short width,short height,
          byte param_6)

{
  J2DPicture *this_00;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined8 in_f31;
  double dVar6;
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  this->mNumDigits = (byte)param_1;
  this->mFlags = param_6;
  dVar6 = d_2dnumber::_4012;
  this->mpWidth = (float)((double)CONCAT44(0x43300000,(int)width ^ 0x80000000) - d_2dnumber::_4012);
  this->mpHeight = (float)((double)CONCAT44(0x43300000,(int)height ^ 0x80000000) - dVar6);
  iVar4 = 0;
  iVar3 = 0;
  iVar2 = 0;
  do {
    if ((int)(uint)this->mNumDigits <= iVar4) {
      iVar2 = 1;
LAB_800c8624:
      __psq_l0(auStack8,uVar5);
      __psq_l1(auStack8,uVar5);
      return iVar2;
    }
    this_00 = (J2DPicture *)JKernel::operator_new(0x124);
    if (this_00 != (J2DPicture *)0x0) {
      J2DPicture::J2DPicture(this_00,"rupy_num_00.bti");
    }
    *(J2DPicture **)((int)this->mpPic + iVar2) = this_00;
    if (*(int *)((int)this->mpPic + iVar2) == 0) {
      iVar2 = 0;
      goto LAB_800c8624;
    }
    iVar1 = (int)this->mpPic + iVar3 + -4;
    *(float *)(iVar1 + 0x14) =
         (float)((double)CONCAT44(0x43300000,(int)param_2 - width * iVar4 ^ 0x80000000) - dVar6);
    *(float *)(iVar1 + 0x18) =
         (float)((double)CONCAT44(0x43300000,(int)param_3 ^ 0x80000000) - dVar6);
    iVar4 = iVar4 + 1;
    iVar3 = iVar3 + 8;
    iVar2 = iVar2 + 4;
  } while( true );
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall dDlst_2DNumber_c::draw(void) */

void __thiscall dDlst_2DNumber_c::draw(dDlst_2DNumber_c *this)

{
  dDlst_2DNumber_c *pNumPos;
  int digit;
  int iVar1;
  int iVar2;
  int iVar3;
  int value;
  char local_38 [28];
  
  value = this->mValue;
  (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph)->parent).vtbl)->setPort)();
  if ((this->mFlags & 2) == 0) {
    iVar3 = 0;
    iVar2 = 0;
    for (iVar1 = 0; iVar1 < (int)(uint)this->mNumDigits; iVar1 = iVar1 + 1) {
      if (((iVar1 != 0) && (value == 0)) && ((this->mFlags & 1) == 0)) {
        return;
      }
      digit = value % 10;
      value = value / 10;
      MSL_C.PPCEABI.bare.H::sprintf(local_38,"rupy_num_%02d.bti",digit);
      J2DPicture::changeTexture(*(J2DPicture **)((int)this->mpPic + iVar2),local_38,0);
      pNumPos = (dDlst_2DNumber_c *)((int)this->mpPic + iVar3 + -4);
      J2DPicture::draw(*(J2DPicture **)((int)this->mpPic + iVar2),pNumPos->mpDigitPos[0].x,
                       pNumPos->mpDigitPos[0].y,this->mpWidth,this->mpHeight,false,false,false);
      iVar3 = iVar3 + 8;
      iVar2 = iVar2 + 4;
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dDlst_2DMinigame_c::init(ResTIMG *,
                                       ResTIMG *) */

int __thiscall dDlst_2DMinigame_c::init(dDlst_2DMinigame_c *this,ResTIMG *ctx,ResTIMG *param_2)

{
  float fVar1;
  double dVar2;
  J2DPicture *pJVar3;
  int iVar4;
  
  pJVar3 = (J2DPicture *)JKernel::operator_new(0x124);
  if (pJVar3 != (J2DPicture *)0x0) {
    J2DPicture::J2DPicture(pJVar3,ctx);
  }
  *(J2DPicture **)(this + 4) = pJVar3;
  if (*(int *)(this + 4) == 0) {
    iVar4 = 0;
  }
  else {
    pJVar3 = (J2DPicture *)JKernel::operator_new(0x124);
    if (pJVar3 != (J2DPicture *)0x0) {
      J2DPicture::J2DPicture(pJVar3,param_2);
    }
    *(J2DPicture **)(this + 8) = pJVar3;
    if (*(int *)(this + 8) == 0) {
      iVar4 = 0;
    }
    else {
      pJVar3 = (J2DPicture *)JKernel::operator_new(0x124);
      if (pJVar3 != (J2DPicture *)0x0) {
        J2DPicture::J2DPicture(pJVar3,param_2);
      }
      *(J2DPicture **)(this + 0xc) = pJVar3;
      dVar2 = d_2dnumber::_4080;
      fVar1 = d_2dnumber::_4077;
      if (*(int *)(this + 0xc) == 0) {
        iVar4 = 0;
      }
      else {
        *(float *)(this + 0x18) =
             d_2dnumber::_4077 *
             (float)((double)CONCAT44(0x43300000,(uint)ctx->mWidth) - d_2dnumber::_4080);
        *(float *)(this + 0x1c) =
             fVar1 * (float)((double)CONCAT44(0x43300000,(uint)ctx->mHeight) - dVar2);
        fVar1 = d_2dnumber::_4078;
        *(float *)(this + 0x28) =
             d_2dnumber::_4078 * (float)((double)CONCAT44(0x43300000,(uint)param_2->mWidth) - dVar2)
        ;
        *(float *)(this + 0x2c) =
             fVar1 * (float)((double)CONCAT44(0x43300000,(uint)param_2->mHeight) - dVar2);
        iVar4 = *(int *)(this + 0xc);
        *(undefined *)(iVar4 + 0x10c) = 0;
        *(undefined *)(iVar4 + 0x10d) = 0;
        *(undefined *)(iVar4 + 0x10e) = 0;
        *(undefined *)(iVar4 + 0x10f) = 0xff;
        *(undefined *)(iVar4 + 0x110) = 0;
        *(undefined *)(iVar4 + 0x111) = 0;
        *(undefined *)(iVar4 + 0x112) = 0;
        *(undefined *)(iVar4 + 0x113) = 0xff;
        *(undefined *)(iVar4 + 0x114) = 0;
        *(undefined *)(iVar4 + 0x115) = 0;
        *(undefined *)(iVar4 + 0x116) = 0;
        *(undefined *)(iVar4 + 0x117) = 0xff;
        *(undefined *)(iVar4 + 0x118) = 0;
        *(undefined *)(iVar4 + 0x119) = 0;
        *(undefined *)(iVar4 + 0x11a) = 0;
        *(undefined *)(iVar4 + 0x11b) = 0xff;
        iVar4 = 1;
      }
    }
  }
  return iVar4;
}


/* __thiscall dDlst_2DMinigame_c::draw(void) */

void __thiscall dDlst_2DMinigame_c::draw(dDlst_2DMinigame_c *this)

{
  (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph)->parent).vtbl)->setPort)();
  J2DPicture::draw(*(J2DPicture **)(this + 0xc),d_2dnumber::_4089 + *(float *)(this + 0x20),
                   d_2dnumber::_4089 + *(float *)(this + 0x24),*(float *)(this + 0x28),
                   *(float *)(this + 0x2c),false,false,false);
  J2DPicture::draw(*(J2DPicture **)(this + 8),*(float *)(this + 0x20),*(float *)(this + 0x24),
                   *(float *)(this + 0x28),*(float *)(this + 0x2c),false,false,false);
  J2DPicture::draw(*(J2DPicture **)(this + 4),*(float *)(this + 0x10),*(float *)(this + 0x14),
                   *(float *)(this + 0x18),*(float *)(this + 0x1c),false,false,false);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dDlst_2DBattery_c::init(ResTIMG *,
                                      ResTIMG *,
                                      ResTIMG *,
                                      ResTIMG *) */

int __thiscall dDlst_2DBattery_c::init(dDlst_2DBattery_c *this,EVP_PKEY_CTX *ctx)

{
  double dVar1;
  float fVar2;
  J2DPicture *pJVar3;
  int iVar4;
  ResTIMG *in_r5;
  ResTIMG *in_r6;
  ResTIMG *in_r7;
  int iVar5;
  dDlst_2DBattery_c *pdVar6;
  
  pJVar3 = (J2DPicture *)JKernel::operator_new(0x124);
  if (pJVar3 != (J2DPicture *)0x0) {
    J2DPicture::J2DPicture(pJVar3,(ResTIMG *)ctx);
  }
  *(J2DPicture **)(this + 4) = pJVar3;
  dVar1 = d_2dnumber::_4080;
  if (*(int *)(this + 4) == 0) {
    iVar4 = 0;
  }
  else {
    *(float *)(this + 0x38) =
         (float)((double)CONCAT44(0x43300000,(uint)*(ushort *)(ctx + 2)) - d_2dnumber::_4080);
    *(float *)(this + 0x3c) =
         (float)((double)CONCAT44(0x43300000,(uint)*(ushort *)(ctx + 4)) - dVar1);
    pJVar3 = (J2DPicture *)JKernel::operator_new(0x124);
    if (pJVar3 != (J2DPicture *)0x0) {
      J2DPicture::J2DPicture(pJVar3,in_r5);
    }
    *(J2DPicture **)(this + 8) = pJVar3;
    dVar1 = d_2dnumber::_4080;
    if (*(int *)(this + 8) == 0) {
      iVar4 = 0;
    }
    else {
      *(float *)(this + 0x40) =
           (float)((double)CONCAT44(0x43300000,(uint)in_r5->mWidth) - d_2dnumber::_4080);
      *(float *)(this + 0x44) = (float)((double)CONCAT44(0x43300000,(uint)in_r5->mHeight) - dVar1);
      pJVar3 = (J2DPicture *)JKernel::operator_new(0x124);
      if (pJVar3 != (J2DPicture *)0x0) {
        J2DPicture::J2DPicture(pJVar3,in_r6);
      }
      *(J2DPicture **)(this + 0xc) = pJVar3;
      dVar1 = d_2dnumber::_4080;
      if (*(int *)(this + 0xc) == 0) {
        iVar4 = 0;
      }
      else {
        *(float *)(this + 0x48) =
             (float)((double)CONCAT44(0x43300000,(uint)in_r6->mWidth) - d_2dnumber::_4080);
        *(float *)(this + 0x4c) = (float)((double)CONCAT44(0x43300000,(uint)in_r6->mHeight) - dVar1)
        ;
        iVar5 = 0;
        iVar4 = 0;
        do {
          pJVar3 = (J2DPicture *)JKernel::operator_new(0x124);
          if (pJVar3 != (J2DPicture *)0x0) {
            J2DPicture::J2DPicture(pJVar3,in_r7);
          }
          pdVar6 = this + iVar4;
          *(J2DPicture **)(pdVar6 + 0x10) = pJVar3;
          if (*(int *)(pdVar6 + 0x10) == 0) {
            return 0;
          }
          pJVar3 = (J2DPicture *)JKernel::operator_new(0x124);
          if (pJVar3 != (J2DPicture *)0x0) {
            J2DPicture::J2DPicture(pJVar3,"rupy_num_00.bti");
          }
          *(J2DPicture **)(pdVar6 + 0x18) = pJVar3;
          if (*(int *)(pdVar6 + 0x18) == 0) {
            return 0;
          }
          pJVar3 = (J2DPicture *)JKernel::operator_new(0x124);
          if (pJVar3 != (J2DPicture *)0x0) {
            J2DPicture::J2DPicture(pJVar3,"rupy_num_00.bti");
          }
          *(J2DPicture **)(pdVar6 + 0x20) = pJVar3;
          if (*(int *)(pdVar6 + 0x20) == 0) {
            return 0;
          }
          iVar5 = iVar5 + 1;
          iVar4 = iVar4 + 4;
        } while (iVar5 < 2);
        *(undefined *)(*(int *)(this + 8) + 0xac) = 200;
        dVar1 = d_2dnumber::_4080;
        *(float *)(this + 0x50) =
             (float)((double)CONCAT44(0x43300000,(uint)in_r7->mWidth) - d_2dnumber::_4080);
        *(float *)(this + 0x54) = (float)((double)CONCAT44(0x43300000,(uint)in_r7->mHeight) - dVar1)
        ;
        fVar2 = d_2dnumber::_4243;
        *(float *)(this + 0x2c) = d_2dnumber::_4243;
        *(float *)(this + 0x28) = fVar2;
        *(float *)(this + 0x30) = d_2dnumber::_4244;
        *(float *)(this + 0x34) = d_2dnumber::_4245 + *(float *)(this + 0x4c) * d_2dnumber::_4246;
        *(undefined *)(*(int *)(this + 4) + 0xac) = 0x80;
        iVar4 = *(int *)(this + 4);
        *(undefined *)(iVar4 + 0x104) = 0xff;
        *(undefined *)(iVar4 + 0x105) = 0xff;
        *(undefined *)(iVar4 + 0x106) = 0xff;
        *(undefined *)(iVar4 + 0x107) = 0xff;
        iVar4 = *(int *)(this + 4);
        *(undefined *)(iVar4 + 0x108) = 0xff;
        *(undefined *)(iVar4 + 0x109) = 0xff;
        *(undefined *)(iVar4 + 0x10a) = 0xff;
        *(undefined *)(iVar4 + 0x10b) = 0;
        iVar4 = *(int *)(this + 0x10);
        *(undefined *)(iVar4 + 0x104) = 0xff;
        *(undefined *)(iVar4 + 0x105) = 200;
        *(undefined *)(iVar4 + 0x106) = 0;
        *(undefined *)(iVar4 + 0x107) = 0xff;
        iVar4 = *(int *)(this + 0x14);
        *(undefined *)(iVar4 + 0x10c) = 0;
        *(undefined *)(iVar4 + 0x10d) = 0;
        *(undefined *)(iVar4 + 0x10e) = 0;
        *(undefined *)(iVar4 + 0x10f) = 0xff;
        *(undefined *)(iVar4 + 0x110) = 0;
        *(undefined *)(iVar4 + 0x111) = 0;
        *(undefined *)(iVar4 + 0x112) = 0;
        *(undefined *)(iVar4 + 0x113) = 0xff;
        *(undefined *)(iVar4 + 0x114) = 0;
        *(undefined *)(iVar4 + 0x115) = 0;
        *(undefined *)(iVar4 + 0x116) = 0;
        *(undefined *)(iVar4 + 0x117) = 0xff;
        *(undefined *)(iVar4 + 0x118) = 0;
        *(undefined *)(iVar4 + 0x119) = 0;
        *(undefined *)(iVar4 + 0x11a) = 0;
        *(undefined *)(iVar4 + 0x11b) = 0xff;
        *(undefined *)(*(int *)(this + 0x14) + 0xac) = 0x50;
        iVar4 = *(int *)(this + 0x18);
        *(undefined *)(iVar4 + 0x104) = 0xff;
        *(undefined *)(iVar4 + 0x105) = 200;
        *(undefined *)(iVar4 + 0x106) = 0;
        *(undefined *)(iVar4 + 0x107) = 0xff;
        iVar4 = *(int *)(this + 0x1c);
        *(undefined *)(iVar4 + 0x10c) = 0;
        *(undefined *)(iVar4 + 0x10d) = 0;
        *(undefined *)(iVar4 + 0x10e) = 0;
        *(undefined *)(iVar4 + 0x10f) = 0xff;
        *(undefined *)(iVar4 + 0x110) = 0;
        *(undefined *)(iVar4 + 0x111) = 0;
        *(undefined *)(iVar4 + 0x112) = 0;
        *(undefined *)(iVar4 + 0x113) = 0xff;
        *(undefined *)(iVar4 + 0x114) = 0;
        *(undefined *)(iVar4 + 0x115) = 0;
        *(undefined *)(iVar4 + 0x116) = 0;
        *(undefined *)(iVar4 + 0x117) = 0xff;
        *(undefined *)(iVar4 + 0x118) = 0;
        *(undefined *)(iVar4 + 0x119) = 0;
        *(undefined *)(iVar4 + 0x11a) = 0;
        *(undefined *)(iVar4 + 0x11b) = 0xff;
        *(undefined *)(*(int *)(this + 0x1c) + 0xac) = 0x50;
        iVar4 = *(int *)(this + 0x20);
        *(undefined *)(iVar4 + 0x104) = 0xff;
        *(undefined *)(iVar4 + 0x105) = 200;
        *(undefined *)(iVar4 + 0x106) = 0;
        *(undefined *)(iVar4 + 0x107) = 0xff;
        iVar4 = *(int *)(this + 0x24);
        *(undefined *)(iVar4 + 0x10c) = 0;
        *(undefined *)(iVar4 + 0x10d) = 0;
        *(undefined *)(iVar4 + 0x10e) = 0;
        *(undefined *)(iVar4 + 0x10f) = 0xff;
        *(undefined *)(iVar4 + 0x110) = 0;
        *(undefined *)(iVar4 + 0x111) = 0;
        *(undefined *)(iVar4 + 0x112) = 0;
        *(undefined *)(iVar4 + 0x113) = 0xff;
        *(undefined *)(iVar4 + 0x114) = 0;
        *(undefined *)(iVar4 + 0x115) = 0;
        *(undefined *)(iVar4 + 0x116) = 0;
        *(undefined *)(iVar4 + 0x117) = 0xff;
        *(undefined *)(iVar4 + 0x118) = 0;
        *(undefined *)(iVar4 + 0x119) = 0;
        *(undefined *)(iVar4 + 0x11a) = 0;
        *(undefined *)(iVar4 + 0x11b) = 0xff;
        *(undefined *)(*(int *)(this + 0x24) + 0xac) = 0x50;
        *(float *)(this + 0x58) = d_2dnumber::_4247;
        iVar4 = 1;
      }
    }
  }
  return iVar4;
}


/* WARNING: Removing unreachable block (ram,0x800c90d0) */
/* __thiscall dDlst_2DBattery_c::setRotate(float) */

void __thiscall dDlst_2DBattery_c::setRotate(dDlst_2DBattery_c *this,float param_1)

{
  int iVar1;
  float fVar2;
  undefined4 uVar3;
  double dVar4;
  undefined8 in_f31;
  char acStack56 [16];
  longlong local_28;
  undefined auStack8 [8];
  
  dVar4 = (double)param_1;
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  iVar1 = (int)(d_2dnumber::_4246 +
               d_2dnumber::_4265 +
               d_2dnumber::_4266 *
               (float)((double)(float)(dVar4 - (double)d_2dnumber::_4267) /
                      (double)d_2dnumber::_4267));
  local_28 = (longlong)iVar1;
  MSL_C.PPCEABI.bare.H::sprintf(acStack56,"rupy_num_%02d.bti",iVar1 / 10);
  J2DPicture::changeTexture(*(J2DPicture **)(this + 0x20),acStack56,0);
  J2DPicture::changeTexture(*(J2DPicture **)(this + 0x24),acStack56,0);
  MSL_C.PPCEABI.bare.H::sprintf(acStack56,"rupy_num_%02d.bti",iVar1 % 10);
  J2DPicture::changeTexture(*(J2DPicture **)(this + 0x18),acStack56,0);
  J2DPicture::changeTexture(*(J2DPicture **)(this + 0x1c),acStack56,0);
  fVar2 = d_2dnumber::_4268;
  if (((double)d_2dnumber::_4247 <= dVar4) &&
     (fVar2 = d_2dnumber::_4270, dVar4 <= (double)d_2dnumber::_4269)) {
    fVar2 = d_2dnumber::_4271 -
            (d_2dnumber::_4265 + d_2dnumber::_4272 * (float)(dVar4 - (double)d_2dnumber::_4247));
  }
  *(float *)(this + 0x58) = fVar2;
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return;
}


/* __thiscall dDlst_2DBattery_c::draw(void) */

void __thiscall dDlst_2DBattery_c::draw(dDlst_2DBattery_c *this)

{
  int iVar1;
  float fVar2;
  int *piVar3;
  
  (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph)->parent).vtbl)->setPort)();
  iVar1 = *(int *)(this + 0x58);
  fVar2 = *(float *)(this + 0x44) * d_2dnumber::_4246;
  piVar3 = *(int **)(this + 8);
  piVar3[0x27] = *(int *)(this + 0x40);
  piVar3[0x28] = (int)fVar2;
  *(undefined *)(piVar3 + 0x2a) = 0x7a;
  piVar3[0x29] = iVar1;
  (**(code **)(*piVar3 + 0x20))();
  J2DPicture::draw(*(J2DPicture **)(this + 4),d_2dnumber::_4288 + *(float *)(this + 0x28),
                   d_2dnumber::_4289 + *(float *)(this + 0x2c),*(float *)(this + 0x38),
                   *(float *)(this + 0x3c),false,false,false);
  J2DPicture::draw(*(J2DPicture **)(this + 8),d_2dnumber::_4290 + *(float *)(this + 0x28),
                   d_2dnumber::_4291 + *(float *)(this + 0x2c),*(float *)(this + 0x40),
                   *(float *)(this + 0x44),false,false,false);
  J2DPicture::draw(*(J2DPicture **)(this + 0xc),d_2dnumber::_4244 + *(float *)(this + 0x28),
                   d_2dnumber::_4245 + *(float *)(this + 0x2c),*(float *)(this + 0x48),
                   *(float *)(this + 0x4c),false,false,false);
  J2DPicture::draw(*(J2DPicture **)(this + 0x24),
                   d_2dnumber::_4292 + d_2dnumber::_4089 + *(float *)(this + 0x30),
                   d_2dnumber::_4089 + *(float *)(this + 0x34),*(float *)(this + 0x50),
                   *(float *)(this + 0x54),false,false,false);
  J2DPicture::draw(*(J2DPicture **)(this + 0x1c),
                   d_2dnumber::_4293 +
                   d_2dnumber::_4089 + *(float *)(this + 0x30) + *(float *)(this + 0x50),
                   d_2dnumber::_4089 + *(float *)(this + 0x34),*(float *)(this + 0x50),
                   *(float *)(this + 0x54),false,false,false);
  J2DPicture::draw(*(J2DPicture **)(this + 0x14),
                   d_2dnumber::_4089 +
                   *(float *)(this + 0x30) + d_2dnumber::_4294 * *(float *)(this + 0x50),
                   d_2dnumber::_4089 + *(float *)(this + 0x34),*(float *)(this + 0x50),
                   *(float *)(this + 0x54),false,false,false);
  J2DPicture::draw(*(J2DPicture **)(this + 0x20),d_2dnumber::_4292 + *(float *)(this + 0x30),
                   *(float *)(this + 0x34),*(float *)(this + 0x50),*(float *)(this + 0x54),false,
                   false,false);
  J2DPicture::draw(*(J2DPicture **)(this + 0x18),
                   d_2dnumber::_4293 + *(float *)(this + 0x30) + *(float *)(this + 0x50),
                   *(float *)(this + 0x34),*(float *)(this + 0x50),*(float *)(this + 0x54),false,
                   false,false);
  J2DPicture::draw(*(J2DPicture **)(this + 0x10),
                   *(float *)(this + 0x30) + d_2dnumber::_4294 * *(float *)(this + 0x50),
                   *(float *)(this + 0x34),*(float *)(this + 0x50),*(float *)(this + 0x54),false,
                   false,false);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dDlst_2DObject_c::init(ResTIMG *,
                                     ResTIMG *) */

int __thiscall dDlst_2DObject_c::init(dDlst_2DObject_c *this,ResTIMG *pTex1,ResTIMG *pTex2)

{
  double dVar1;
  J2DPicture *pJVar2;
  int iVar3;
  
  pJVar2 = (J2DPicture *)JKernel::operator_new(0x124);
  if (pJVar2 != (J2DPicture *)0x0) {
    J2DPicture::J2DPicture(pJVar2,pTex1);
  }
  this->mpPic1 = pJVar2;
  dVar1 = d_2dnumber::_4080;
  if (this->mpPic1 == (J2DPicture *)0x0) {
    iVar3 = 0;
  }
  else {
    (this->mPic1Size).x =
         (float)((double)CONCAT44(0x43300000,(uint)pTex1->mWidth) - d_2dnumber::_4080);
    (this->mPic1Size).y = (float)((double)CONCAT44(0x43300000,(uint)pTex1->mHeight) - dVar1);
    pJVar2 = (J2DPicture *)JKernel::operator_new(0x124);
    if (pJVar2 != (J2DPicture *)0x0) {
      J2DPicture::J2DPicture(pJVar2,pTex2);
    }
    this->mpPic2 = pJVar2;
    dVar1 = d_2dnumber::_4080;
    if (this->mpPic2 == (J2DPicture *)0x0) {
      iVar3 = 0;
    }
    else {
      (this->mPic2Size).x =
           (float)((double)CONCAT44(0x43300000,(uint)pTex2->mWidth) - d_2dnumber::_4080);
      (this->mPic2Size).y = (float)((double)CONCAT44(0x43300000,(uint)pTex2->mHeight) - dVar1);
      this->mScale = d_2dnumber::1_0;
      this->mWhichPic = 0;
      iVar3 = 1;
    }
  }
  return iVar3;
}


/* __thiscall dDlst_2DObject_c::draw(void) */

void __thiscall dDlst_2DObject_c::draw(dDlst_2DObject_c *this)

{
  (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph)->parent).vtbl)->setPort)();
  if (this->mWhichPic == 0) {
    J2DPicture::draw(this->mpPic1,(this->mPos).x,(this->mPos).y,(this->mPic1Size).x * this->mScale,
                     (this->mPic1Size).y * this->mScale,false,false,false);
  }
  else {
    J2DPicture::draw(this->mpPic2,(this->mPos).x,(this->mPos).y,(this->mPic2Size).x * this->mScale,
                     (this->mPic2Size).y * this->mScale,false,false,false);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dDlst_2DOutFont_c::initial(void) */

void __thiscall dDlst_2DOutFont_c::initial(dDlst_2DOutFont_c *this)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  dDlst_2DOutFont_c *pdVar4;
  int iVar5;
  int iVar6;
  
  fVar1 = d_2dnumber::_4243;
  *(float *)(this + 0x68) = d_2dnumber::_4243;
  this[0x84] = (dDlst_2DOutFont_c)0x0;
  *(float *)(this + 0x34) = fVar1;
  *(float *)(this + 0x30) = fVar1;
  *(undefined2 *)(this + 0x82) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  if (*(int *)(this + 0x14) != 0) {
    *(undefined *)(*(int *)(this + 0x14) + 0xaa) = 1;
    *(undefined4 *)this = *(undefined4 *)(*(int *)(this + 0x14) + 0xe8);
    *(undefined4 *)(this + 4) = *(undefined4 *)(*(int *)(this + 0x14) + 0xec);
    *(undefined4 *)(this + 0x6c) = *(undefined4 *)this;
    *(undefined4 *)(this + 0x70) = *(undefined4 *)(*(int *)(this + 0x14) + 0xe0);
    *(undefined4 *)(this + 0x28) = *(undefined4 *)(this + 0x24);
  }
  iVar3 = 0;
  iVar6 = 0;
  iVar5 = 0;
  do {
    fVar1 = d_2dnumber::_4243;
    pdVar4 = this + iVar5;
    if (*(int *)(pdVar4 + 8) != 0) {
      *(float *)(pdVar4 + 0x44) = d_2dnumber::_4243;
      *(float *)(pdVar4 + 0x38) = fVar1;
      *(float *)(pdVar4 + 0x5c) = fVar1;
      *(float *)(pdVar4 + 0x50) = fVar1;
      *(undefined *)(*(int *)(pdVar4 + 8) + 0xaa) = 0;
      piVar2 = *(int **)(pdVar4 + 8);
      piVar2[0x27] = (int)fVar1;
      piVar2[0x28] = (int)fVar1;
      *(undefined *)(piVar2 + 0x2a) = 0x7a;
      piVar2[0x29] = (int)fVar1;
      (**(code **)(*piVar2 + 0x20))();
      if (this[0x74] == (dDlst_2DOutFont_c)0x0) {
        (**(code **)(**(int **)(pdVar4 + 8) + 0x18))
                  ((double)*(float *)(this + 0x6c),(double)*(float *)(this + 0x6c));
      }
      else {
        (**(code **)(**(int **)(pdVar4 + 8) + 0x18))
                  ((double)*(float *)this,(double)*(float *)(this + 4));
      }
      *(undefined2 *)(this + iVar6 + 0x7c) = 0;
      this[iVar3 + 0x85] = (dDlst_2DOutFont_c)0x0;
      *(undefined2 *)(this + iVar6 + 0x76) = 0xffff;
    }
    iVar3 = iVar3 + 1;
    iVar6 = iVar6 + 2;
    iVar5 = iVar5 + 4;
  } while (iVar3 < 3);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dDlst_2DOutFont_c::setPane(JUTFont *,
                                         fopMsgM_pane_class *,
                                         fopMsgM_pane_class *,
                                         fopMsgM_pane_class *,
                                         fopMsgM_pane_class *) */

void __thiscall
dDlst_2DOutFont_c::setPane
          (dDlst_2DOutFont_c *this,JUTFont *param_1,fopMsgM_pane_class *param_2,
          fopMsgM_pane_class *param_3,fopMsgM_pane_class *param_4,fopMsgM_pane_class *param_5)

{
  int iVar1;
  int iVar2;
  
  *(JUTFont **)(this + 0x1c) = param_1;
  *(J2DScreen **)(this + 0x14) = param_2->mpPane;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  if (param_3 != (fopMsgM_pane_class *)0x0) {
    *(J2DScreen **)(this + 8) = param_3->mpPane;
  }
  if (param_4 != (fopMsgM_pane_class *)0x0) {
    *(J2DScreen **)(this + 0xc) = param_4->mpPane;
  }
  if (param_5 != (fopMsgM_pane_class *)0x0) {
    *(J2DScreen **)(this + 0x10) = param_5->mpPane;
  }
  *(undefined4 *)(this + 0x24) = 0;
  initial(this);
  iVar1 = 0;
  iVar2 = 0;
  do {
    if (*(J2DPicture **)(this + iVar2 + 8) != (J2DPicture *)0x0) {
      J2DPicture::changeTexture(*(J2DPicture **)(this + iVar2 + 8),"font_07_02.bti",0);
      J2DPicture::insert(*(J2DPicture **)(this + iVar2 + 8),"font_07_02.bti",
                         (*(J2DPicture **)(this + iVar2 + 8))->mNumTexture,d_2dnumber::1_0);
    }
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 4;
  } while (iVar1 < 3);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dDlst_2DOutFont_c::setPaneEx(JUTFont *,
                                           fopMsgM_pane_class *,
                                           fopMsgM_pane_class *,
                                           fopMsgM_pane_class *,
                                           fopMsgM_pane_class *,
                                           char *) */

void __thiscall
dDlst_2DOutFont_c::setPaneEx
          (dDlst_2DOutFont_c *this,JUTFont *param_1,fopMsgM_pane_class *param_2,
          fopMsgM_pane_class *param_3,fopMsgM_pane_class *param_4,fopMsgM_pane_class *param_5,
          char *param_6)

{
  int iVar1;
  int iVar2;
  
  *(JUTFont **)(this + 0x1c) = param_1;
  *(J2DScreen **)(this + 0x14) = param_2->mpPane;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  if (param_3 != (fopMsgM_pane_class *)0x0) {
    *(J2DScreen **)(this + 8) = param_3->mpPane;
  }
  if (param_4 != (fopMsgM_pane_class *)0x0) {
    *(J2DScreen **)(this + 0xc) = param_4->mpPane;
  }
  if (param_5 != (fopMsgM_pane_class *)0x0) {
    *(J2DScreen **)(this + 0x10) = param_5->mpPane;
  }
  *(char **)(this + 0x24) = param_6;
  initial(this);
  iVar1 = 0;
  iVar2 = 0;
  do {
    if (*(J2DPicture **)(this + iVar2 + 8) != (J2DPicture *)0x0) {
      J2DPicture::changeTexture(*(J2DPicture **)(this + iVar2 + 8),"font_07_02.bti",0);
      J2DPicture::insert(*(J2DPicture **)(this + iVar2 + 8),"font_07_02.bti",
                         (*(J2DPicture **)(this + iVar2 + 8))->mNumTexture,d_2dnumber::1_0);
    }
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 4;
  } while (iVar1 < 3);
  return;
}


/* __thiscall dDlst_2DOutFont_c::setRuby(JUTFont *,
                                         fopMsgM_pane_class *) */

void __thiscall
dDlst_2DOutFont_c::setRuby(dDlst_2DOutFont_c *this,JUTFont *param_1,fopMsgM_pane_class *param_2)

{
  *(JUTFont **)(this + 0x20) = param_1;
  *(J2DScreen **)(this + 0x18) = param_2->mpPane;
  return;
}


/* __thiscall dDlst_2DOutFont_c::setRubyEx(JUTFont *,
                                           fopMsgM_pane_class *,
                                           char *) */

void __thiscall
dDlst_2DOutFont_c::setRubyEx
          (dDlst_2DOutFont_c *this,JUTFont *param_1,fopMsgM_pane_class *param_2,char *param_3)

{
  *(JUTFont **)(this + 0x20) = param_1;
  *(J2DScreen **)(this + 0x18) = param_2->mpPane;
  return;
}


/* __thiscall dDlst_2DOutFont_c::charWidth(int) */

double __thiscall dDlst_2DOutFont_c::charWidth(dDlst_2DOutFont_c *this,int param_1)

{
  uint uVar1;
  undefined uStack40;
  byte local_27;
  
  (**(code **)(**(int **)(this + 0x1c) + 0x2c))(*(int **)(this + 0x1c),param_1,&uStack40);
  uVar1 = (**(code **)(**(int **)(this + 0x1c) + 0x30))();
  return (double)(*(float *)(this + 0x70) +
                 (float)((double)CONCAT44(0x43300000,local_27 ^ 0x80000000) - d_2dnumber::_4012) *
                 (*(float *)(this + 0x6c) /
                 (float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - d_2dnumber::_4012)));
}


/* WARNING: Removing unreachable block (ram,0x800c99a0) */
/* __thiscall dDlst_2DOutFont_c::rubyCharWidth(int) */

double __thiscall dDlst_2DOutFont_c::rubyCharWidth(dDlst_2DOutFont_c *this,int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined8 in_f31;
  double dVar3;
  undefined uStack56;
  byte local_37;
  undefined auStack8 [8];
  
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  dVar3 = (double)*(float *)(*(int *)(this + 0x18) + 0xe8);
  (**(code **)(**(int **)(this + 0x20) + 0x2c))(*(int **)(this + 0x20),param_1,&uStack56);
  uVar1 = (**(code **)(**(int **)(this + 0x20) + 0x30))();
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  return (double)(*(float *)(this + 0x70) +
                 (float)((double)CONCAT44(0x43300000,local_37 ^ 0x80000000) - d_2dnumber::_4012) *
                 (float)(dVar3 / (double)(float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) -
                                                d_2dnumber::_4012)));
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x800c9d3c) */
/* __thiscall dDlst_2DOutFont_c::iconset(int,
                                         char * *) */

double __thiscall dDlst_2DOutFont_c::iconset(dDlst_2DOutFont_c *this,int param_1,char **param_2)

{
  char cVar1;
  float fVar2;
  char *pcVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  char *pcVar7;
  J2DPicture *this_00;
  undefined4 uVar8;
  undefined8 in_f31;
  double dVar9;
  undefined uStack86;
  undefined uStack85;
  undefined local_44;
  undefined uStack67;
  char local_40 [16];
  longlong local_30;
  undefined auStack8 [8];
  
  uVar8 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  dVar9 = (double)d_2dnumber::_4243;
  if ((byte)this[0x84] < 3) {
    *(undefined4 *)(this + (uint)(byte)this[0x84] * 4 + 0x38) = *(undefined4 *)(this + 0x68);
    *(undefined *)(*(int *)(this + (uint)(byte)this[0x84] * 4 + 8) + 0xaa) = 1;
    J2DPicture::remove(*(J2DPicture **)(this + (uint)(byte)this[0x84] * 4 + 8),
                       (char *)((*(J2DPicture **)(this + (uint)(byte)this[0x84] * 4 + 8))->
                                mNumTexture - 1 & 0xff));
    pcVar3 = (char *)f_op_msg_mng::fopMsgM_outFontTex(param_1);
    J2DPicture::insert(*(J2DPicture **)(this + (uint)(byte)this[0x84] * 4 + 8),pcVar3,
                       (*(J2DPicture **)(this + (uint)(byte)this[0x84] * 4 + 8))->mNumTexture,
                       d_2dnumber::1_0);
    this_00 = *(J2DPicture **)(this + (uint)(byte)this[0x84] * 4 + 8);
    this_00->mBlendKonstColorF[0] = d_2dnumber::_4243;
    fVar2 = d_2dnumber::1_0;
    this_00->mBlendKonstColorF[1] = d_2dnumber::1_0;
    this_00->mBlendKonstColorF[2] = fVar2;
    this_00->mBlendKonstColorF[3] = fVar2;
    J2DPicture::setBlendKonstColor(this_00);
    this_00->mBlendKonstAlphaF[0] = d_2dnumber::_4243;
    fVar2 = d_2dnumber::1_0;
    this_00->mBlendKonstAlphaF[1] = d_2dnumber::1_0;
    this_00->mBlendKonstAlphaF[2] = fVar2;
    this_00->mBlendKonstAlphaF[3] = fVar2;
    J2DPicture::setBlendKonstAlpha(this_00);
    uVar4 = f_op_msg_mng::fopMsgM_outFontColorWhite(param_1);
    uStack86 = (undefined)((uint)uVar4 >> 8);
    uStack85 = (undefined)uVar4;
    iVar5 = *(int *)(this + (uint)(byte)this[0x84] * 4 + 8);
    local_44 = (undefined)((uint)uVar4 >> 0x18);
    *(undefined *)(iVar5 + 0x104) = local_44;
    uStack67 = (undefined)((uint)uVar4 >> 0x10);
    *(undefined *)(iVar5 + 0x105) = uStack67;
    *(undefined *)(iVar5 + 0x106) = uStack86;
    *(undefined *)(iVar5 + 0x107) = uStack85;
    iVar5 = *(int *)(this + (uint)(byte)this[0x84] * 4 + 8);
    *(undefined *)(iVar5 + 0x108) = 0;
    *(undefined *)(iVar5 + 0x109) = 0;
    *(undefined *)(iVar5 + 0x10a) = 0;
    *(undefined *)(iVar5 + 0x10b) = 0;
    this[(byte)this[0x84] + 0x85] = SUB41(param_1,0);
    *(undefined2 *)(this + (uint)(byte)this[0x84] * 2 + 0x76) = *(undefined2 *)(this + 0x82);
    if (param_1 == 0xb) {
      *(float *)(this + (uint)(byte)this[0x84] * 4 + 0x44) =
           *(float *)(this + (uint)(byte)this[0x84] * 4 + 0x44) + *(float *)(this + 0x6c);
      fVar2 = d_2dnumber::_4243;
      piVar6 = *(int **)(this + (uint)(byte)this[0x84] * 4 + 8);
      piVar6[0x27] = (int)d_2dnumber::_4243;
      piVar6[0x28] = (int)fVar2;
      *(undefined *)(piVar6 + 0x2a) = 0x7a;
      piVar6[0x29] = (int)d_2dnumber::_4528;
      (**(code **)(*piVar6 + 0x20))();
    }
    else {
      if (param_1 < 0xb) {
        if (9 < param_1) {
          *(float *)(this + (uint)(byte)this[0x84] * 4 + 0x38) =
               *(float *)(this + (uint)(byte)this[0x84] * 4 + 0x38) + *(float *)(this + 0x6c);
          fVar2 = d_2dnumber::_4243;
          piVar6 = *(int **)(this + (uint)(byte)this[0x84] * 4 + 8);
          piVar6[0x27] = (int)d_2dnumber::_4243;
          piVar6[0x28] = (int)fVar2;
          *(undefined *)(piVar6 + 0x2a) = 0x7a;
          piVar6[0x29] = (int)d_2dnumber::_4527;
          (**(code **)(*piVar6 + 0x20))();
        }
      }
      else {
        if (param_1 < 0xd) {
          *(float *)(this + (uint)(byte)this[0x84] * 4 + 0x38) =
               *(float *)(this + (uint)(byte)this[0x84] * 4 + 0x38) + *(float *)(this + 0x6c);
          *(float *)(this + (uint)(byte)this[0x84] * 4 + 0x44) =
               *(float *)(this + (uint)(byte)this[0x84] * 4 + 0x44) + *(float *)(this + 0x6c);
          fVar2 = d_2dnumber::_4243;
          piVar6 = *(int **)(this + (uint)(byte)this[0x84] * 4 + 8);
          piVar6[0x27] = (int)d_2dnumber::_4243;
          piVar6[0x28] = (int)fVar2;
          *(undefined *)(piVar6 + 0x2a) = 0x7a;
          piVar6[0x29] = (int)d_2dnumber::_4529;
          (**(code **)(*piVar6 + 0x20))();
        }
      }
    }
    dVar9 = (double)(*(float *)(this + 0x6c) + *(float *)(this + 0x70));
    local_30 = (longlong)(int)((double)d_2dnumber::_4246 + dVar9);
    MSL_C.PPCEABI.bare.H::sprintf(local_40,"\x1bCR[%d]",(int)((double)d_2dnumber::_4246 + dVar9));
    for (pcVar3 = local_40; cVar1 = *pcVar3, cVar1 != '\0'; pcVar3 = pcVar3 + 1) {
      pcVar7 = *param_2;
      *param_2 = pcVar7 + 1;
      *pcVar7 = cVar1;
    }
    this[0x84] = (dDlst_2DOutFont_c)((char)this[0x84] + '\x01');
  }
  __psq_l0(auStack8,uVar8);
  __psq_l1(auStack8,uVar8);
  return dVar9;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* WARNING: Removing unreachable block (ram,0x800ca880) */
/* WARNING: Removing unreachable block (ram,0x800ca870) */
/* WARNING: Removing unreachable block (ram,0x800ca878) */
/* WARNING: Removing unreachable block (ram,0x800ca888) */
/* __thiscall dDlst_2DOutFont_c::messageSet(unsigned long) */

void __thiscall dDlst_2DOutFont_c::messageSet(dDlst_2DOutFont_c *this,ulong param_1)

{
  uint *puVar1;
  float fVar2;
  uint uVar3;
  byte bVar4;
  byte bVar5;
  mesg_header *pmVar6;
  ulong uVar7;
  byte *pbVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  char *in_r5;
  byte *pbVar12;
  byte *pbVar13;
  uint uVar14;
  int iVar15;
  undefined4 uVar16;
  double dVar17;
  double dVar18;
  undefined8 in_f28;
  undefined8 in_f29;
  double dVar19;
  undefined8 in_f30;
  undefined8 in_f31;
  double dVar20;
  double dVar21;
  byte *local_1d8;
  float local_1d4;
  float local_1d0;
  char local_1cc [16];
  char local_1bc [16];
  char acStack428 [16];
  undefined1 *local_19c;
  undefined4 local_198;
  undefined2 local_194;
  undefined2 local_192;
  byte *local_190 [7];
  byte local_174 [52];
  char local_140 [100];
  byte abStack220 [100];
  double local_78;
  undefined4 local_70;
  uint uStack108;
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar16 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  local_19c = &fopMsgM_itemMsgGet_c::__vt;
  local_198 = 0;
  local_194 = 0;
  local_192 = 0;
  pmVar6 = (mesg_header *)
           fopMsgM_itemMsgGet_c::getMesgHeader((fopMsgM_itemMsgGet_c *)&local_19c,param_1);
  if (pmVar6 == (mesg_header *)0x0) {
    uVar7 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar7,"d_2dnumber.cpp",0x26b,"head_p");
    in_r5 = "Halt";
    m_Do_printf::OSPanic("d_2dnumber.cpp",0x26b);
  }
  pbVar8 = (byte *)fopMsgM_itemMsgGet_c::getMessage((fopMsgM_itemMsgGet_c *)&local_19c,pmVar6);
  local_1d8 = abStack220;
  dVar20 = (double)d_2dnumber::_4243;
  uVar14 = 0;
  dVar19 = dVar20;
  dVar21 = dVar20;
  initial(this);
  this[0x88] = (dDlst_2DOutFont_c)0x0;
  local_140[0] = '\0';
  this[0xec] = (dDlst_2DOutFont_c)0x0;
  while (bVar5 = *pbVar8, bVar5 != 0) {
    if (bVar5 == 0x1a) {
      puVar1 = (uint *)(pbVar8 + 1);
      uVar3 = *puVar1 & 0xffffff;
      if (uVar3 == 0xff0000) {
        uVar9 = f_op_msg_mng::fopMsgM_getColorTable((int)(char)pbVar8[5]);
        MSL_C.PPCEABI.bare.H::sprintf((char *)local_190,"\x1bCC[%08x]\x1bGM[0]",uVar9);
        for (in_r5 = (char *)local_190; *in_r5 != 0; in_r5 = (char *)((int)in_r5 + 1)) {
          *local_1d8 = *in_r5;
          local_1d8 = local_1d8 + 1;
        }
      }
      else {
        if (uVar3 == 0xff0002) {
          if ((*(int *)(this + 0x20) != 0) && (bVar5 = *(byte *)puVar1, bVar5 != 5)) {
            pbVar13 = pbVar8 + 6;
            pbVar12 = local_174;
            local_174[0] = 0;
            dVar20 = (double)*(float *)(this + 0x68);
            uVar14 = (uint)pbVar8[5];
            fVar2 = d_2dnumber::_4243;
            for (iVar10 = 0; dVar21 = (double)fVar2, iVar10 < (int)(bVar5 - 6); iVar10 = iVar10 + 2)
            {
              in_r5 = (char *)(int)(char)*pbVar13;
              *pbVar12 = *pbVar13;
              bVar4 = pbVar13[1];
              pbVar12[1] = bVar4;
              pbVar13 = pbVar13 + 2;
              pbVar12 = pbVar12 + 2;
              dVar17 = (double)rubyCharWidth(this,((uint)in_r5 & 0xff) << 8 |
                                                  (int)(char)bVar4 & 0xffU);
              fVar2 = (float)(dVar21 + dVar17);
            }
            *pbVar12 = 0;
          }
        }
        else {
          if (uVar3 == 10) {
            in_r5 = (char *)&local_1d8;
            dVar17 = (double)iconset(this,0,(char **)in_r5);
            *(float *)(this + 0x68) = (float)((double)*(float *)(this + 0x68) + dVar17);
          }
          else {
            if (uVar3 == 0xb) {
              in_r5 = (char *)&local_1d8;
              dVar17 = (double)iconset(this,1,(char **)in_r5);
              *(float *)(this + 0x68) = (float)((double)*(float *)(this + 0x68) + dVar17);
            }
            else {
              if (uVar3 == 0xc) {
                in_r5 = (char *)&local_1d8;
                dVar17 = (double)iconset(this,2,(char **)in_r5);
                *(float *)(this + 0x68) = (float)((double)*(float *)(this + 0x68) + dVar17);
              }
              else {
                if (uVar3 == 0xd) {
                  in_r5 = (char *)&local_1d8;
                  dVar17 = (double)iconset(this,3,(char **)in_r5);
                  *(float *)(this + 0x68) = (float)((double)*(float *)(this + 0x68) + dVar17);
                }
                else {
                  if (uVar3 == 0xe) {
                    in_r5 = (char *)&local_1d8;
                    dVar17 = (double)iconset(this,4,(char **)in_r5);
                    *(float *)(this + 0x68) = (float)((double)*(float *)(this + 0x68) + dVar17);
                  }
                  else {
                    if (uVar3 == 0xf) {
                      in_r5 = (char *)&local_1d8;
                      dVar17 = (double)iconset(this,5,(char **)in_r5);
                      *(float *)(this + 0x68) = (float)((double)*(float *)(this + 0x68) + dVar17);
                    }
                    else {
                      if (uVar3 == 0x10) {
                        in_r5 = (char *)&local_1d8;
                        dVar17 = (double)iconset(this,6,(char **)in_r5);
                        *(float *)(this + 0x68) = (float)((double)*(float *)(this + 0x68) + dVar17);
                      }
                      else {
                        if (uVar3 == 0x11) {
                          in_r5 = (char *)&local_1d8;
                          dVar17 = (double)iconset(this,7,(char **)in_r5);
                          *(float *)(this + 0x68) =
                               (float)((double)*(float *)(this + 0x68) + dVar17);
                        }
                        else {
                          if (uVar3 == 0x12) {
                            in_r5 = (char *)&local_1d8;
                            dVar17 = (double)iconset(this,8,(char **)in_r5);
                            *(float *)(this + 0x68) =
                                 (float)((double)*(float *)(this + 0x68) + dVar17);
                          }
                          else {
                            if (uVar3 == 0x13) {
                              in_r5 = (char *)&local_1d8;
                              dVar17 = (double)iconset(this,9,(char **)in_r5);
                              *(float *)(this + 0x68) =
                                   (float)((double)*(float *)(this + 0x68) + dVar17);
                            }
                            else {
                              if (uVar3 == 0x14) {
                                in_r5 = (char *)&local_1d8;
                                dVar17 = (double)iconset(this,10,(char **)in_r5);
                                *(float *)(this + 0x68) =
                                     (float)((double)*(float *)(this + 0x68) + dVar17);
                              }
                              else {
                                if (uVar3 == 0x15) {
                                  in_r5 = (char *)&local_1d8;
                                  dVar17 = (double)iconset(this,0xb,(char **)in_r5);
                                  *(float *)(this + 0x68) =
                                       (float)((double)*(float *)(this + 0x68) + dVar17);
                                }
                                else {
                                  if (uVar3 == 0x16) {
                                    in_r5 = (char *)&local_1d8;
                                    dVar17 = (double)iconset(this,0xc,(char **)in_r5);
                                    *(float *)(this + 0x68) =
                                         (float)((double)*(float *)(this + 0x68) + dVar17);
                                  }
                                  else {
                                    if (uVar3 == 0x17) {
                                      in_r5 = (char *)&local_1d8;
                                      dVar17 = (double)iconset(this,0xd,(char **)in_r5);
                                      *(float *)(this + 0x68) =
                                           (float)((double)*(float *)(this + 0x68) + dVar17);
                                    }
                                    else {
                                      if (uVar3 == 0x18) {
                                        in_r5 = (char *)&local_1d8;
                                        dVar17 = (double)iconset(this,0xe,(char **)in_r5);
                                        *(float *)(this + 0x68) =
                                             (float)((double)*(float *)(this + 0x68) + dVar17);
                                      }
                                      else {
                                        if (uVar3 == 0x19) {
                                          in_r5 = (char *)&local_1d8;
                                          dVar17 = (double)iconset(this,0xf,(char **)in_r5);
                                          *(float *)(this + 0x68) =
                                               (float)((double)*(float *)(this + 0x68) + dVar17);
                                        }
                                        else {
                                          if (uVar3 == 0x1a) {
                                            in_r5 = (char *)&local_1d8;
                                            dVar17 = (double)iconset(this,0x10,(char **)in_r5);
                                            *(float *)(this + 0x68) =
                                                 (float)((double)*(float *)(this + 0x68) + dVar17);
                                          }
                                          else {
                                            if (uVar3 == 0x1b) {
                                              in_r5 = (char *)&local_1d8;
                                              dVar17 = (double)iconset(this,0x11,(char **)in_r5);
                                              *(float *)(this + 0x68) =
                                                   (float)((double)*(float *)(this + 0x68) + dVar17)
                                              ;
                                            }
                                            else {
                                              if (uVar3 == 0x1c) {
                                                in_r5 = (char *)&local_1d8;
                                                dVar17 = (double)iconset(this,0x12,(char **)in_r5);
                                                *(float *)(this + 0x68) =
                                                     (float)((double)*(float *)(this + 0x68) +
                                                            dVar17);
                                              }
                                              else {
                                                if (uVar3 == 0x1d) {
                                                  in_r5 = (char *)&local_1d8;
                                                  dVar17 = (double)iconset(this,0x13,(char **)in_r5)
                                                  ;
                                                  *(float *)(this + 0x68) =
                                                       (float)((double)*(float *)(this + 0x68) +
                                                              dVar17);
                                                }
                                                else {
                                                  if (uVar3 == 0x27) {
                                                    in_r5 = (char *)&local_1d8;
                                                    dVar17 = (double)iconset(this,0x14,
                                                                             (char **)in_r5);
                                                    *(float *)(this + 0x68) =
                                                         (float)((double)*(float *)(this + 0x68) +
                                                                dVar17);
                                                  }
                                                  else {
                                                    if (uVar3 == 0x39) {
                                                      in_r5 = (char *)&local_1d8;
                                                      dVar17 = (double)iconset(this,0x15,
                                                                               (char **)in_r5);
                                                      *(float *)(this + 0x68) =
                                                           (float)((double)*(float *)(this + 0x68) +
                                                                  dVar17);
                                                    }
                                                    else {
                                                      if (uVar3 == 0x3a) {
                                                        in_r5 = (char *)&local_1d8;
                                                        dVar17 = (double)iconset(this,0x16,
                                                                                 (char **)in_r5);
                                                        *(float *)(this + 0x68) =
                                                             (float)((double)*(float *)(this + 0x68)
                                                                    + dVar17);
                                                      }
                                                    }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      pbVar8 = (byte *)((int)puVar1 + (char)*(byte *)puVar1 + -1);
    }
    else {
      if ((bVar5 >> 4 == 8) || (bVar5 >> 4 == 9)) {
        bVar5 = *pbVar8;
        pbVar12 = local_1d8 + 1;
        *local_1d8 = bVar5;
        bVar4 = pbVar8[1];
        in_r5 = (char *)(uint)bVar4;
        local_1d8 = local_1d8 + 2;
        *pbVar12 = bVar4;
        pbVar8 = pbVar8 + 2;
        dVar17 = (double)charWidth(this,((int)(char)bVar5 & 0xffU) << 8 | (uint)bVar4);
        *(float *)(this + 0x68) = (float)((double)*(float *)(this + 0x68) + dVar17);
        if ((uVar14 != 0) && (uVar14 = uVar14 - 1, uVar14 == 0)) {
          dVar18 = (double)d_2dnumber::_4246;
          dVar17 = (double)((float)(dVar20 + (double)(float)((double)(float)((double)*(float *)(this
                                                                                               + 
                                                  0x68) - dVar20) * dVar18)) -
                           (float)(dVar21 * dVar18));
          if (dVar17 <= dVar19) {
            if (dVar17 < dVar19) {
              dVar17 = (double)(float)(dVar19 - dVar17);
              in_r5 = (char *)(int)(dVar18 + dVar17);
              local_78 = (double)(longlong)(int)in_r5;
              MSL_C.PPCEABI.bare.H::sprintf(acStack428,"\x1bCL[%d]");
              MSL_C.PPCEABI.bare.H::strcat(local_140,acStack428);
              dVar19 = (double)(float)(dVar19 - dVar17);
            }
          }
          else {
            dVar17 = (double)(float)(dVar17 - dVar19);
            in_r5 = (char *)(int)(dVar18 + dVar17);
            local_78 = (double)(longlong)(int)in_r5;
            MSL_C.PPCEABI.bare.H::sprintf(acStack428,"\x1bCR[%d]");
            MSL_C.PPCEABI.bare.H::strcat(local_140,acStack428);
            dVar19 = (double)(float)(dVar19 + dVar17);
          }
          dVar19 = (double)(float)(dVar19 + dVar21);
          MSL_C.PPCEABI.bare.H::strcat(local_140,(char *)local_174);
        }
      }
      else {
        bVar5 = *pbVar8;
        in_r5 = (char *)(uint)bVar5;
        pbVar12 = local_1d8 + 1;
        *local_1d8 = bVar5;
        pbVar8 = pbVar8 + 1;
        local_1d8 = pbVar12;
        if ((char)bVar5 == 10) {
          *pbVar12 = 0;
          uVar3 = (uint)(((*(float *)(*(int *)(this + 0x14) + 0x14) -
                          *(float *)(*(int *)(this + 0x14) + 0xc)) - *(float *)(this + 0x68)) *
                        d_2dnumber::_4246);
          local_78 = (double)(longlong)(int)uVar3;
          if ((int)uVar3 < 1) {
            local_1bc[0] = '\0';
          }
          else {
            MSL_C.PPCEABI.bare.H::sprintf(local_1bc,"\x1bCR[%d]",uVar3);
            dVar19 = d_2dnumber::_4012;
            iVar10 = 0;
            iVar11 = 0;
            in_r5 = (char *)0x43300000;
            iVar15 = 3;
            do {
              if (*(short *)(this + 0x82) == *(short *)(this + iVar11 + 0x76)) {
                local_78 = (double)CONCAT44(0x43300000,uVar3 ^ 0x80000000);
                *(float *)(this + iVar10 + 0x38) =
                     *(float *)(this + iVar10 + 0x38) + (float)(local_78 - dVar19);
              }
              iVar10 = iVar10 + 4;
              iVar11 = iVar11 + 2;
              iVar15 = iVar15 + -1;
            } while (iVar15 != 0);
          }
          MSL_C.PPCEABI.bare.H::strcat((char *)(this + 0x88),local_1bc);
          MSL_C.PPCEABI.bare.H::strcat((char *)(this + 0x88),(char *)abStack220);
          *(short *)(this + 0x82) = *(short *)(this + 0x82) + 1;
          dVar19 = (double)d_2dnumber::_4243;
          *(float *)(this + 0x68) = d_2dnumber::_4243;
          local_1d8 = abStack220;
          if (*(int *)(this + 0x20) != 0) {
            MSL_C.PPCEABI.bare.H::strcat((char *)(this + 0xec),local_1bc);
            MSL_C.PPCEABI.bare.H::strcat((char *)(this + 0xec),local_140);
            MSL_C.PPCEABI.bare.H::strcat((char *)(this + 0xec),"\n");
            local_140[0] = '\0';
          }
        }
        else {
          dVar17 = (double)charWidth(this,(int)(char)bVar5);
          *(float *)(this + 0x68) = (float)((double)*(float *)(this + 0x68) + dVar17);
        }
      }
    }
  }
  *local_1d8 = 0;
  fVar2 = d_2dnumber::_4243;
  if (this[0x74] == (dDlst_2DOutFont_c)0x0) {
    iVar10 = *(int *)(this + 0x14);
    local_78 = (double)CONCAT44(0x43300000,(int)*(short *)(this + 0x82) ^ 0x80000000);
    fVar2 = (((*(float *)(iVar10 + 0x18) - *(float *)(iVar10 + 0x10)) - *(float *)(this + 0x6c)) -
            (float)(local_78 - d_2dnumber::_4012) * *(float *)(iVar10 + 0xe4)) * d_2dnumber::_4246;
  }
  dVar19 = (double)fVar2;
  uVar14 = (uint)(((*(float *)(*(int *)(this + 0x14) + 0x14) -
                   *(float *)(*(int *)(this + 0x14) + 0xc)) - *(float *)(this + 0x68)) *
                 d_2dnumber::_4246);
  local_78 = (double)(longlong)(int)uVar14;
  if ((int)uVar14 < 1) {
    local_1cc[0] = '\0';
  }
  else {
    MSL_C.PPCEABI.bare.H::sprintf(local_1cc,"\x1bCR[%d]",uVar14);
    iVar10 = 0;
    iVar11 = 0;
    iVar15 = 3;
    do {
      in_r5 = (char *)(int)*(short *)(this + 0x82);
      if ((byte **)in_r5 == (byte **)(int)*(short *)(this + iVar11 + 0x76)) {
        in_r5 = (char *)(iVar10 + 0x38);
        local_78 = (double)CONCAT44(0x43300000,uVar14 ^ 0x80000000);
        *(float *)(this + (int)in_r5) =
             *(float *)(this + (int)in_r5) + (float)(local_78 - d_2dnumber::_4012);
      }
      if ((int)*(short *)(this + iVar11 + 0x76) != 0xffffffff) {
        in_r5 = (char *)(iVar10 + 0x44);
        local_78 = (double)CONCAT44(0x43300000,(int)*(short *)(this + iVar11 + 0x76) ^ 0x80000000);
        *(float *)(this + (int)in_r5) =
             *(float *)(this + (int)in_r5) +
             (float)(dVar19 + (double)((float)(local_78 - d_2dnumber::_4012) *
                                      *(float *)(*(int *)(this + 0x14) + 0xe4)));
      }
      iVar10 = iVar10 + 4;
      iVar11 = iVar11 + 2;
      iVar15 = iVar15 + -1;
    } while (iVar15 != 0);
  }
  MSL_C.PPCEABI.bare.H::strcat((char *)(this + 0x88),local_1cc);
  MSL_C.PPCEABI.bare.H::strcat((char *)(this + 0x88),(char *)abStack220);
  iVar10 = *(int *)(this + 0x14);
  *(float *)(iVar10 + 0xd8) = d_2dnumber::_4243;
  *(float *)(iVar10 + 0xdc) = (float)dVar19;
  if (*(char **)(this + 0x28) == (char *)0x0) {
    J2DTextBox::setString(*(J2DTextBox **)(this + 0x14),(char *)(this + 0x88),(___)in_r5);
  }
  else {
    MSL_C.PPCEABI.bare.H::strcpy(*(char **)(this + 0x28),(char *)(this + 0x88));
  }
  iVar10 = *(int *)(this + 0x18);
  if (iVar10 != 0) {
    *(float *)(iVar10 + 0xd8) = d_2dnumber::_4243;
    *(float *)(iVar10 + 0xdc) = (float)dVar19;
    MSL_C.PPCEABI.bare.H::strcat((char *)(this + 0xec),local_1cc);
    MSL_C.PPCEABI.bare.H::strcat((char *)(this + 0xec),local_140);
    if (*(char **)(this + 0x2c) == (char *)0x0) {
      J2DTextBox::setString(*(J2DTextBox **)(this + 0x18),(char *)(this + 0xec),(___)in_r5);
    }
    else {
      MSL_C.PPCEABI.bare.H::strcpy(*(char **)(this + 0x2c),(char *)(this + 0xec));
    }
  }
  if (this[0x74] != (dDlst_2DOutFont_c)0x0) {
    fVar2 = *(float *)(*(int *)(this + 0x14) + 0x14) - *(float *)(*(int *)(this + 0x14) + 0xc);
    if (fVar2 < *(float *)(this + 0x68)) {
      uStack108 = (uint)(*(float *)this * (fVar2 / *(float *)(this + 0x68)));
      local_78 = (double)(longlong)(int)uStack108;
      uStack108 = uStack108 ^ 0x80000000;
      local_70 = 0x43300000;
      *(float *)this = (float)((double)CONCAT44(0x43300000,uStack108) - d_2dnumber::_4012);
      local_1d4 = *(float *)this;
      local_1d0 = *(float *)(this + 4);
      iVar10 = *(int *)(this + 0x14);
      fVar2 = d_2dnumber::_4243;
      if (d_2dnumber::_4243 < local_1d4) {
        fVar2 = local_1d4;
      }
      *(float *)(iVar10 + 0xe8) = fVar2;
      fVar2 = d_2dnumber::_4243;
      if (d_2dnumber::_4243 < local_1d0) {
        fVar2 = local_1d0;
      }
      *(float *)(iVar10 + 0xec) = fVar2;
      messageSet(this,param_1);
    }
  }
  __psq_l0(auStack8,uVar16);
  __psq_l1(auStack8,uVar16);
  __psq_l0(auStack24,uVar16);
  __psq_l1(auStack24,uVar16);
  __psq_l0(auStack40,uVar16);
  __psq_l1(auStack40,uVar16);
  __psq_l0(auStack56,uVar16);
  __psq_l1(auStack56,uVar16);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dDlst_2DOutFont_c::outFontStickAnime1(unsigned char) */

void __thiscall dDlst_2DOutFont_c::outFontStickAnime1(dDlst_2DOutFont_c *this,uchar param_1)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  dDlst_2DOutFont_c *pdVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  dDlst_2DOutFont_c *pdVar9;
  
  iVar8 = (int)(short)((ushort)DAT_803e6bcc + (ushort)DAT_803e6bcb * 2 + (ushort)DAT_803e6bcd);
  uVar1 = (uint)param_1;
  pdVar9 = this + (uint)param_1 * 2;
  iVar7 = (int)*(short *)(pdVar9 + 0x7c);
  if (iVar7 < iVar8) {
    outFontStickAnimePiece(this,param_1,'\0');
    fVar3 = d_2dnumber::_4243;
    if (this[0x74] == (dDlst_2DOutFont_c)0x0) {
      *(float *)(this + uVar1 * 4 + 0x50) = d_2dnumber::_4243;
      *(float *)(this + uVar1 * 4 + 0x5c) = fVar3;
    }
    else {
      pdVar4 = this + uVar1 * 4;
      *(float *)(pdVar4 + 0x50) = d_2dnumber::_4243;
      *(float *)(pdVar4 + 0x5c) = fVar3;
      (**(code **)(**(int **)(pdVar4 + 8) + 0x18))
                ((double)*(float *)this,(double)*(float *)(this + 4));
    }
  }
  else {
    if (iVar7 < iVar8 << 1) {
      outFontStickAnimePiece(this,param_1,'\x01');
      if (this[0x74] == (dDlst_2DOutFont_c)0x0) {
        *(undefined4 *)(this + uVar1 * 4 + 0x50) = *(undefined4 *)(this + 0x6c);
        *(float *)(this + uVar1 * 4 + 0x5c) = d_2dnumber::_4243;
      }
      else {
        pdVar4 = this + uVar1 * 4;
        *(undefined4 *)(pdVar4 + 0x50) = *(undefined4 *)this;
        *(float *)(pdVar4 + 0x5c) = d_2dnumber::_4243;
        (**(code **)(**(int **)(pdVar4 + 8) + 0x18))
                  ((double)*(float *)(this + 4),(double)*(float *)this);
      }
    }
    else {
      if (iVar7 < iVar8 * 3) {
        outFontStickAnimePiece(this,param_1,'\x02');
        if (this[0x74] == (dDlst_2DOutFont_c)0x0) {
          *(undefined4 *)(this + uVar1 * 4 + 0x50) = *(undefined4 *)(this + 0x6c);
          *(undefined4 *)(this + uVar1 * 4 + 0x5c) = *(undefined4 *)(this + 0x6c);
        }
        else {
          pdVar4 = this + uVar1 * 4;
          *(undefined4 *)(pdVar4 + 0x50) = *(undefined4 *)this;
          *(undefined4 *)(pdVar4 + 0x5c) = *(undefined4 *)(this + 4);
          (**(code **)(**(int **)(pdVar4 + 8) + 0x18))
                    ((double)*(float *)this,(double)*(float *)(this + 4));
        }
      }
      else {
        if (iVar7 < iVar8 << 2) {
          outFontStickAnimePiece(this,param_1,'\x03');
          if (this[0x74] == (dDlst_2DOutFont_c)0x0) {
            *(float *)(this + uVar1 * 4 + 0x50) = d_2dnumber::_4243;
            *(undefined4 *)(this + uVar1 * 4 + 0x5c) = *(undefined4 *)(this + 0x6c);
          }
          else {
            pdVar4 = this + uVar1 * 4;
            *(float *)(pdVar4 + 0x50) = d_2dnumber::_4243;
            *(undefined4 *)(pdVar4 + 0x5c) = *(undefined4 *)(this + 4);
            (**(code **)(**(int **)(pdVar4 + 8) + 0x18))
                      ((double)*(float *)(this + 4),(double)*(float *)this);
          }
        }
      }
    }
  }
  fVar3 = d_2dnumber::_4243;
  uVar5 = (int)*(short *)(pdVar9 + 0x7c) / iVar8;
  if ((int)*(short *)(pdVar9 + 0x7c) == uVar5 * iVar8) {
    fVar2 = d_2dnumber::_4798 *
            (float)((double)CONCAT44(0x43300000,uVar5 ^ 0x80000000) - d_2dnumber::_4012);
    piVar6 = *(int **)(this + uVar1 * 4 + 8);
    piVar6[0x27] = (int)d_2dnumber::_4243;
    piVar6[0x28] = (int)fVar3;
    *(undefined *)(piVar6 + 0x2a) = 0x7a;
    piVar6[0x29] = (int)fVar2;
    (**(code **)(*piVar6 + 0x20))();
  }
  *(short *)(pdVar9 + 0x7c) = *(short *)(pdVar9 + 0x7c) + 1;
  if (iVar8 << 2 <= (int)*(short *)(pdVar9 + 0x7c)) {
    *(undefined2 *)(pdVar9 + 0x7c) = 0;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x800cabd8) */
/* __thiscall dDlst_2DOutFont_c::outFontStickAnime2(unsigned char,
                                                    unsigned char) */

void __thiscall
dDlst_2DOutFont_c::outFontStickAnime2(dDlst_2DOutFont_c *this,uchar param_1,uchar param_2)

{
  uint uVar1;
  float fVar2;
  short sVar3;
  dDlst_2DOutFont_c *pdVar4;
  int *piVar5;
  dDlst_2DOutFont_c *pdVar6;
  
  sVar3 = (ushort)DAT_803e6bcc + (ushort)DAT_803e6bcb * 2 + (ushort)DAT_803e6bcd;
  uVar1 = (uint)param_1;
  pdVar6 = this + (uint)param_1 * 2;
  if (*(short *)(pdVar6 + 0x7c) < sVar3) {
    outFontStickAnimePiece(this,param_1,'\0');
    fVar2 = d_2dnumber::_4243;
    if (param_2 == '\x02') {
      if (this[0x74] == (dDlst_2DOutFont_c)0x0) {
        *(undefined4 *)(this + uVar1 * 4 + 0x50) = *(undefined4 *)(this + 0x6c);
        *(undefined4 *)(this + uVar1 * 4 + 0x5c) = *(undefined4 *)(this + 0x6c);
      }
      else {
        pdVar4 = this + uVar1 * 4;
        *(undefined4 *)(pdVar4 + 0x50) = *(undefined4 *)this;
        *(undefined4 *)(pdVar4 + 0x5c) = *(undefined4 *)(this + 4);
        (**(code **)(**(int **)(pdVar4 + 8) + 0x18))
                  ((double)*(float *)this,(double)*(float *)(this + 4));
      }
    }
    else {
      if (param_2 < 2) {
        if (param_2 == '\0') {
          if (this[0x74] == (dDlst_2DOutFont_c)0x0) {
            *(float *)(this + uVar1 * 4 + 0x50) = d_2dnumber::_4243;
            *(float *)(this + uVar1 * 4 + 0x5c) = fVar2;
          }
          else {
            pdVar4 = this + uVar1 * 4;
            *(float *)(pdVar4 + 0x50) = d_2dnumber::_4243;
            *(float *)(pdVar4 + 0x5c) = fVar2;
            (**(code **)(**(int **)(pdVar4 + 8) + 0x18))
                      ((double)*(float *)this,(double)*(float *)(this + 4));
          }
        }
        else {
          if (this[0x74] == (dDlst_2DOutFont_c)0x0) {
            *(undefined4 *)(this + uVar1 * 4 + 0x50) = *(undefined4 *)(this + 0x6c);
            *(float *)(this + uVar1 * 4 + 0x5c) = d_2dnumber::_4243;
          }
          else {
            pdVar4 = this + uVar1 * 4;
            *(undefined4 *)(pdVar4 + 0x50) = *(undefined4 *)this;
            *(float *)(pdVar4 + 0x5c) = d_2dnumber::_4243;
            (**(code **)(**(int **)(pdVar4 + 8) + 0x18))
                      ((double)*(float *)(this + 4),(double)*(float *)this);
          }
        }
      }
      else {
        if (param_2 < 4) {
          if (this[0x74] == (dDlst_2DOutFont_c)0x0) {
            *(float *)(this + uVar1 * 4 + 0x50) = d_2dnumber::_4243;
            *(undefined4 *)(this + uVar1 * 4 + 0x5c) = *(undefined4 *)(this + 0x6c);
          }
          else {
            pdVar4 = this + uVar1 * 4;
            *(float *)(pdVar4 + 0x50) = d_2dnumber::_4243;
            *(undefined4 *)(pdVar4 + 0x5c) = *(undefined4 *)(this + 4);
            (**(code **)(**(int **)(pdVar4 + 8) + 0x18))
                      ((double)*(float *)(this + 4),(double)*(float *)this);
          }
        }
      }
    }
  }
  fVar2 = d_2dnumber::_4243;
  piVar5 = *(int **)(this + uVar1 * 4 + 8);
  piVar5[0x27] = (int)d_2dnumber::_4243;
  piVar5[0x28] = (int)fVar2;
  *(undefined *)(piVar5 + 0x2a) = 0x7a;
  piVar5[0x29] = (int)(d_2dnumber::_4798 *
                      (float)((double)CONCAT44(0x43300000,(uint)param_2) - d_2dnumber::_4080));
  (**(code **)(*piVar5 + 0x20))();
  *(short *)(pdVar6 + 0x7c) = *(short *)(pdVar6 + 0x7c) + 1;
  if (sVar3 <= *(short *)(pdVar6 + 0x7c)) {
    *(undefined2 *)(pdVar6 + 0x7c) = 0;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dDlst_2DOutFont_c::outFontStickAnime3(unsigned char,
                                                    unsigned char) */

void __thiscall
dDlst_2DOutFont_c::outFontStickAnime3(dDlst_2DOutFont_c *this,uchar param_1,uchar param_2)

{
  uint uVar1;
  float fVar2;
  dDlst_2DOutFont_c *pdVar3;
  int *piVar4;
  int iVar5;
  uint in_LR;
  
  iVar5 = (int)(short)((ushort)DAT_803e6bcc + (ushort)DAT_803e6bcb * 2 + (ushort)DAT_803e6bcd);
  if (param_2 == '\0') {
    uVar1 = (uint)param_1;
    if (*(short *)(this + (uint)param_1 * 2 + 0x7c) < iVar5) {
      outFontStickAnimePiece(this,param_1,'\0');
      if (this[0x74] == (dDlst_2DOutFont_c)0x0) {
        *(undefined4 *)(this + uVar1 * 4 + 0x50) = *(undefined4 *)(this + 0x6c);
        *(float *)(this + uVar1 * 4 + 0x5c) = d_2dnumber::_4243;
      }
      else {
        pdVar3 = this + uVar1 * 4;
        *(undefined4 *)(pdVar3 + 0x50) = *(undefined4 *)this;
        *(float *)(pdVar3 + 0x5c) = d_2dnumber::_4243;
        (**(code **)(**(int **)(pdVar3 + 8) + 0x18))
                  ((double)*(float *)(this + 4),(double)*(float *)this);
      }
      in_LR = 1;
    }
    else {
      if ((int)*(short *)(this + (uint)param_1 * 2 + 0x7c) < iVar5 << 1) {
        outFontStickAnimePiece(this,param_1,'\x01');
        if (this[0x74] == (dDlst_2DOutFont_c)0x0) {
          *(float *)(this + uVar1 * 4 + 0x50) = d_2dnumber::_4243;
          *(undefined4 *)(this + uVar1 * 4 + 0x5c) = *(undefined4 *)(this + 0x6c);
        }
        else {
          pdVar3 = this + uVar1 * 4;
          *(float *)(pdVar3 + 0x50) = d_2dnumber::_4243;
          *(undefined4 *)(pdVar3 + 0x5c) = *(undefined4 *)(this + 4);
          (**(code **)(**(int **)(pdVar3 + 8) + 0x18))
                    ((double)*(float *)(this + 4),(double)*(float *)this);
        }
        in_LR = 3;
      }
    }
  }
  else {
    uVar1 = (uint)param_1;
    if (*(short *)(this + (uint)param_1 * 2 + 0x7c) < iVar5) {
      outFontStickAnimePiece(this,param_1,'\0');
      fVar2 = d_2dnumber::_4243;
      if (this[0x74] == (dDlst_2DOutFont_c)0x0) {
        *(float *)(this + uVar1 * 4 + 0x50) = d_2dnumber::_4243;
        *(float *)(this + uVar1 * 4 + 0x5c) = fVar2;
      }
      else {
        pdVar3 = this + uVar1 * 4;
        *(float *)(pdVar3 + 0x50) = d_2dnumber::_4243;
        *(float *)(pdVar3 + 0x5c) = fVar2;
        (**(code **)(**(int **)(pdVar3 + 8) + 0x18))
                  ((double)*(float *)this,(double)*(float *)(this + 4));
      }
      in_LR = 0;
    }
    else {
      if ((int)*(short *)(this + (uint)param_1 * 2 + 0x7c) < iVar5 << 1) {
        outFontStickAnimePiece(this,param_1,'\x01');
        if (this[0x74] == (dDlst_2DOutFont_c)0x0) {
          *(undefined4 *)(this + uVar1 * 4 + 0x50) = *(undefined4 *)(this + 0x6c);
          *(undefined4 *)(this + uVar1 * 4 + 0x5c) = *(undefined4 *)(this + 0x6c);
        }
        else {
          pdVar3 = this + uVar1 * 4;
          *(undefined4 *)(pdVar3 + 0x50) = *(undefined4 *)this;
          *(undefined4 *)(pdVar3 + 0x5c) = *(undefined4 *)(this + 4);
          (**(code **)(**(int **)(pdVar3 + 8) + 0x18))
                    ((double)*(float *)this,(double)*(float *)(this + 4));
        }
        in_LR = 2;
      }
    }
  }
  fVar2 = d_2dnumber::_4243;
  piVar4 = *(int **)(this + (uint)param_1 * 4 + 8);
  piVar4[0x27] = (int)d_2dnumber::_4243;
  piVar4[0x28] = (int)fVar2;
  *(undefined *)(piVar4 + 0x2a) = 0x7a;
  piVar4[0x29] = (int)(d_2dnumber::_4798 *
                      (float)((double)CONCAT44(0x43300000,in_LR ^ 0x80000000) - d_2dnumber::_4012));
  (**(code **)(*piVar4 + 0x20))();
  pdVar3 = this + (uint)param_1 * 2;
  *(short *)(pdVar3 + 0x7c) = *(short *)(pdVar3 + 0x7c) + 1;
  if (iVar5 << 1 <= (int)*(short *)(pdVar3 + 0x7c)) {
    *(undefined2 *)(pdVar3 + 0x7c) = 0;
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x800cb2b8) */
/* WARNING: Removing unreachable block (ram,0x800cb2c0) */
/* __thiscall dDlst_2DOutFont_c::outFontStickAnimePiece(unsigned char,
                                                        unsigned char) */

void __thiscall
dDlst_2DOutFont_c::outFontStickAnimePiece(dDlst_2DOutFont_c *this,uchar param_1,uchar param_2)

{
  uint uVar1;
  float fVar2;
  short sVar4;
  short sVar5;
  short sVar6;
  int iVar3;
  J2DPicture *pJVar7;
  undefined4 uVar8;
  double dVar9;
  undefined8 in_f30;
  double dVar10;
  undefined8 in_f31;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  fVar2 = d_2dnumber::1_0;
  uVar8 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  sVar4 = (ushort)DAT_803e6bcc + (ushort)DAT_803e6bcb * 2 + (ushort)DAT_803e6bcd;
  sVar5 = (ushort)DAT_803e6bcc + sVar4 * (ushort)param_2;
  sVar6 = (ushort)DAT_803e6bcd + (ushort)DAT_803e6bcb + sVar5;
  uVar1 = (uint)param_1;
  iVar3 = (int)*(short *)(this + (uint)param_1 * 2 + 0x7c);
  if (iVar3 < sVar5) {
    pJVar7 = *(J2DPicture **)(this + uVar1 * 4 + 8);
    pJVar7->mBlendKonstColorF[0] = d_2dnumber::_4243;
    fVar2 = d_2dnumber::1_0;
    pJVar7->mBlendKonstColorF[1] = d_2dnumber::1_0;
    pJVar7->mBlendKonstColorF[2] = fVar2;
    pJVar7->mBlendKonstColorF[3] = fVar2;
    J2DPicture::setBlendKonstColor(pJVar7);
    pJVar7->mBlendKonstAlphaF[0] = d_2dnumber::_4243;
    fVar2 = d_2dnumber::1_0;
    pJVar7->mBlendKonstAlphaF[1] = d_2dnumber::1_0;
    pJVar7->mBlendKonstAlphaF[2] = fVar2;
    pJVar7->mBlendKonstAlphaF[3] = fVar2;
    J2DPicture::setBlendKonstAlpha(pJVar7);
  }
  else {
    if (iVar3 < (short)((ushort)DAT_803e6bcb + sVar5)) {
      dVar9 = (double)f_op_msg_mng::fopMsgM_valueIncrease(sVar4,iVar3 - sVar5,0);
      pJVar7 = *(J2DPicture **)(this + uVar1 * 4 + 8);
      pJVar7->mBlendKonstColorF[0] = (float)dVar9;
      fVar2 = d_2dnumber::1_0;
      dVar10 = (double)(float)((double)d_2dnumber::1_0 - dVar9);
      pJVar7->mBlendKonstColorF[1] = (float)((double)d_2dnumber::1_0 - dVar9);
      pJVar7->mBlendKonstColorF[2] = fVar2;
      pJVar7->mBlendKonstColorF[3] = fVar2;
      J2DPicture::setBlendKonstColor(pJVar7);
      pJVar7->mBlendKonstAlphaF[0] = (float)dVar9;
      pJVar7->mBlendKonstAlphaF[1] = (float)dVar10;
      fVar2 = d_2dnumber::1_0;
      pJVar7->mBlendKonstAlphaF[2] = d_2dnumber::1_0;
      pJVar7->mBlendKonstAlphaF[3] = fVar2;
      J2DPicture::setBlendKonstAlpha(pJVar7);
    }
    else {
      if (iVar3 < sVar6) {
        pJVar7 = *(J2DPicture **)(this + uVar1 * 4 + 8);
        pJVar7->mBlendKonstColorF[0] = d_2dnumber::1_0;
        pJVar7->mBlendKonstColorF[1] = d_2dnumber::_4243;
        pJVar7->mBlendKonstColorF[2] = fVar2;
        pJVar7->mBlendKonstColorF[3] = fVar2;
        J2DPicture::setBlendKonstColor(pJVar7);
        fVar2 = d_2dnumber::1_0;
        pJVar7->mBlendKonstAlphaF[0] = d_2dnumber::1_0;
        pJVar7->mBlendKonstAlphaF[1] = d_2dnumber::_4243;
        pJVar7->mBlendKonstAlphaF[2] = fVar2;
        pJVar7->mBlendKonstAlphaF[3] = fVar2;
        J2DPicture::setBlendKonstAlpha(pJVar7);
      }
      else {
        if (iVar3 < (short)((ushort)DAT_803e6bcb + sVar6)) {
          dVar9 = (double)f_op_msg_mng::fopMsgM_valueIncrease(sVar4,iVar3 - sVar6,0);
          fVar2 = d_2dnumber::1_0;
          pJVar7 = *(J2DPicture **)(this + uVar1 * 4 + 8);
          dVar10 = (double)(float)((double)d_2dnumber::1_0 - dVar9);
          pJVar7->mBlendKonstColorF[0] = (float)((double)d_2dnumber::1_0 - dVar9);
          pJVar7->mBlendKonstColorF[1] = (float)dVar9;
          pJVar7->mBlendKonstColorF[2] = fVar2;
          pJVar7->mBlendKonstColorF[3] = fVar2;
          J2DPicture::setBlendKonstColor(pJVar7);
          pJVar7->mBlendKonstAlphaF[0] = (float)dVar10;
          pJVar7->mBlendKonstAlphaF[1] = (float)dVar9;
          fVar2 = d_2dnumber::1_0;
          pJVar7->mBlendKonstAlphaF[2] = d_2dnumber::1_0;
          pJVar7->mBlendKonstAlphaF[3] = fVar2;
          J2DPicture::setBlendKonstAlpha(pJVar7);
        }
      }
    }
  }
  __psq_l0(auStack8,uVar8);
  __psq_l1(auStack8,uVar8);
  __psq_l0(auStack24,uVar8);
  __psq_l1(auStack24,uVar8);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x800cb454) */
/* __thiscall dDlst_2DOutFont_c::move(void) */

void __thiscall dDlst_2DOutFont_c::move(dDlst_2DOutFont_c *this)

{
  uchar uVar1;
  dDlst_2DOutFont_c *pdVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined8 in_f31;
  double dVar6;
  undefined auStack8 [8];
  
  uVar5 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  for (iVar3 = 0; iVar3 < (int)(uint)(byte)this[0x84]; iVar3 = iVar3 + 1) {
    uVar1 = (uchar)iVar3;
    switch(this[iVar3 + 0x85]) {
    case (dDlst_2DOutFont_c)0x9:
      outFontStickAnime1(this,uVar1);
      break;
    case (dDlst_2DOutFont_c)0xe:
      outFontStickAnime2(this,uVar1,'\x01');
      break;
    case (dDlst_2DOutFont_c)0xf:
      outFontStickAnime2(this,uVar1,'\x03');
      break;
    case (dDlst_2DOutFont_c)0x10:
      outFontStickAnime2(this,uVar1,'\0');
      break;
    case (dDlst_2DOutFont_c)0x11:
      outFontStickAnime2(this,uVar1,'\x02');
      break;
    case (dDlst_2DOutFont_c)0x12:
      outFontStickAnime3(this,uVar1,'\0');
      break;
    case (dDlst_2DOutFont_c)0x13:
      outFontStickAnime3(this,uVar1,'\x01');
    }
  }
  iVar3 = 0;
  iVar4 = 0;
  dVar6 = (double)d_2dnumber::1_0;
  do {
    pdVar2 = this + iVar4;
    if (*(int **)(pdVar2 + 8) != (int *)0x0) {
      (**(code **)(**(int **)(pdVar2 + 8) + 0x10))
                ((double)(*(float *)(pdVar2 + 0x50) +
                         *(float *)(this + 0x30) + *(float *)(pdVar2 + 0x38)),
                 (double)(float)((double)(*(float *)(pdVar2 + 0x5c) +
                                         *(float *)(this + 0x34) + *(float *)(pdVar2 + 0x44)) -
                                dVar6));
    }
    iVar3 = iVar3 + 1;
    iVar4 = iVar4 + 4;
  } while (iVar3 < 3);
  if (*(int **)(this + 0x14) != (int *)0x0) {
    (**(code **)(**(int **)(this + 0x14) + 0x10))
              ((double)*(float *)(this + 0x30),(double)*(float *)(this + 0x34));
  }
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  return;
}


/* __thiscall dDlst_2DOutFont_c::setAlpha(unsigned char) */

void __thiscall dDlst_2DOutFont_c::setAlpha(dDlst_2DOutFont_c *this,uchar param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 3;
  do {
    if (*(int *)(this + iVar1 + 8) != 0) {
      *(uchar *)(*(int *)(this + iVar1 + 8) + 0xac) = param_1;
    }
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  if (*(int *)(this + 0x14) == 0) {
    return;
  }
  *(uchar *)(*(int *)(this + 0x14) + 0xac) = param_1;
  return;
}


/* __thiscall dDlst_2DObject_c::~dDlst_2DObject_c(void) */

void __thiscall dDlst_2DObject_c::_dDlst_2DObject_c(dDlst_2DObject_c *this)

{
  short in_r4;
  
  if (this != (dDlst_2DObject_c *)0x0) {
    *(undefined ***)this = &__vt;
    if (this != (dDlst_2DObject_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dDlst_2DBattery_c::~dDlst_2DBattery_c(void) */

void __thiscall dDlst_2DBattery_c::_dDlst_2DBattery_c(dDlst_2DBattery_c *this)

{
  short in_r4;
  
  if (this != (dDlst_2DBattery_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dDlst_2DBattery_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dDlst_2DMinigame_c::~dDlst_2DMinigame_c(void) */

void __thiscall dDlst_2DMinigame_c::_dDlst_2DMinigame_c(dDlst_2DMinigame_c *this)

{
  short in_r4;
  
  if (this != (dDlst_2DMinigame_c *)0x0) {
    *(undefined ***)this = &__vt;
    if (this != (dDlst_2DMinigame_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}

