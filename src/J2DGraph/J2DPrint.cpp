#include <J2DGraph/J2DPrint.h>
#include <J2DGraph/J2DPrint.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <JKernel/JKRHeap.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <JUtility/JUTFont.h>
#include <MSL_C.PPCEABI.bare.H/strtoul.h>
#include <J2DPrint.h>

char * J2DPrint;
undefined1 J2DPrint;
int J2DPrint;
undefined1 J2DPrint;

/* __thiscall J2DPrint::J2DPrint(JUTFont *,
                                 float,
                                 float,
                                 JUtility::TColor,
                                 JUtility::TColor,
                                 JUtility::TColor,
                                 JUtility::TColor) */

void __thiscall
J2DPrint::J2DPrint(J2DPrint *this,JUTFont *param_1,float param_2,float param_3,_GXColor *param_4,
                  _GXColor *param_5,_GXColor *param_6,_GXColor *param_7)

{
  _GXColor local_18;
  _GXColor local_14;
  _GXColor local_10;
  _GXColor local_c;
  
  *(undefined ***)this = &__vt;
  this->mColorTop = (_GXColor)0xffffffff;
  this->mColorBottom = (_GXColor)0xffffffff;
  this->field_0x38 = (_GXColor)0xffffffff;
  this->field_0x3c = (_GXColor)0xffffffff;
  this->field_0x40 = (_GXColor)0xffffffff;
  this->field_0x44 = (_GXColor)0xffffffff;
  local_18 = *param_7;
  local_14 = *param_6;
  local_10 = *param_5;
  local_c = *param_4;
  private_initiate(this,param_1,param_2,param_3,&local_c,&local_10,&local_14,&local_18,false);
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Removing unreachable block (ram,0x802ce35c) */
/* WARNING: Removing unreachable block (ram,0x802ce364) */
/* __thiscall J2DPrint::private_initiate(JUTFont *,
                                         float,
                                         float,
                                         JUtility::TColor,
                                         JUtility::TColor,
                                         JUtility::TColor,
                                         JUtility::TColor,
                                         bool) */

void __thiscall
J2DPrint::private_initiate
          (J2DPrint *this,JUTFont *param_1,float param_2,float param_3,_GXColor *param_4,
          _GXColor *param_5,_GXColor *param_6,_GXColor *param_7,bool param_8)

{
  int iVar1;
  undefined4 uVar2;
  double dVar3;
  double dVar4;
  undefined8 in_f30;
  undefined8 in_f31;
  _GXColor local_58;
  _GXColor local_54;
  undefined4 local_50;
  uint uStack76;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar3 = (double)param_3;
  dVar4 = (double)param_2;
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  if (mStrBuff == (char *)0x0) {
    setBuffer(0x400);
  }
  this->mpFont = param_1;
  this->field_0x48 = (float)dVar4;
  this->field_0x4c = J2DGraph::_582;
  if (this->mpFont != (JUTFont *)0x0) {
    if (param_8 != false) {
      uStack76 = (*(code *)this->mpFont->vtbl->getLeading)();
      uStack76 = uStack76 ^ 0x80000000;
      local_50 = 0x43300000;
      dVar3 = (double)(float)((double)CONCAT44(0x43300000,uStack76) - J2DGraph::_588);
    }
    this->field_0x4c = (float)dVar3;
  }
  *(undefined *)&this->field_0x5a = 1;
  locate(this,J2DGraph::0_0,J2DGraph::0_0);
  (this->field_0x40).r = param_4->r;
  (this->field_0x40).g = param_4->g;
  (this->field_0x40).b = param_4->b;
  (this->field_0x40).a = param_4->a;
  (this->field_0x44).r = param_5->r;
  (this->field_0x44).g = param_5->g;
  (this->field_0x44).b = param_5->b;
  (this->field_0x44).a = param_5->a;
  (this->field_0x38).r = param_6->r;
  (this->field_0x38).g = param_6->g;
  (this->field_0x38).b = param_6->b;
  (this->field_0x38).a = param_6->a;
  (this->field_0x3c).r = param_7->r;
  (this->field_0x3c).g = param_7->g;
  (this->field_0x3c).b = param_7->b;
  (this->field_0x3c).a = param_7->a;
  if (this->mpFont == (JUTFont *)0x0) {
    *(undefined2 *)&this->field_0x58 = 0x50;
  }
  else {
    iVar1 = (*(code *)this->mpFont->vtbl->getWidth)();
    *(short *)&this->field_0x58 = (short)(iVar1 << 2);
  }
  if (this->mpFont != (JUTFont *)0x0) {
    setFontSize(this);
    local_58 = this->field_0x3c;
    local_54 = this->field_0x38;
    (*(code *)this->mpFont->vtbl->setGX_)(this->mpFont,&local_54,&local_58);
  }
  initchar(this);
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  __psq_l0(auStack24,uVar2);
  __psq_l1(auStack24,uVar2);
  return;
}


namespace J2DPrint {

/* __thiscall setBuffer(unsigned long) */

char * setBuffer(ulong param_1)

{
  char *pcVar1;
  ulong uVar2;
  
  if (param_1 == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"J2DPrint.cpp",0x144,"size > 0");
    m_Do_printf::OSPanic("J2DPrint.cpp",0x144,&DAT_80370bb6);
  }
  pcVar1 = mStrBuff;
  if (mHeapFlag != '\0') {
    JKernel::operator_delete((JKRHeap *)mStrBuff);
  }
  mStrBuff = (char *)JKernel::operator_new__(param_1,JKRHeap::sSystemHeap,0);
  mHeapFlag = 1;
  mStrBuffSize = param_1;
  return pcVar1;
}

}

/* __thiscall J2DPrint::setFontSize(void) */

void __thiscall J2DPrint::setFontSize(J2DPrint *this)

{
  uint uVar1;
  
  if (this->mpFont != (JUTFont *)0x0) {
    uVar1 = (*(code *)this->mpFont->vtbl->getCellWidth)();
    this->mWidth = (float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - J2DGraph::_588);
    uVar1 = (*(code *)this->mpFont->vtbl->getCellHeight)();
    this->mHeight = (float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - J2DGraph::_588);
  }
  return;
}


/* __thiscall J2DPrint::locate(float,
                               float) */

void __thiscall J2DPrint::locate(J2DPrint *this,float param_1,float param_2)

{
  this->field_0x24 = param_1;
  this->field_0x28 = param_2;
  this->field_0x2c = param_1;
  this->field_0x30 = param_2;
  this->field_0x34 = J2DGraph::0_0;
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Removing unreachable block (ram,0x802ce860) */
/* WARNING: Removing unreachable block (ram,0x802ce850) */
/* WARNING: Removing unreachable block (ram,0x802ce840) */
/* WARNING: Removing unreachable block (ram,0x802ce848) */
/* WARNING: Removing unreachable block (ram,0x802ce858) */
/* WARNING: Removing unreachable block (ram,0x802ce868) */
/* __thiscall J2DPrint::printReturn(char const *,
                                    float,
                                    float,
                                    J2DTextBoxHBinding,
                                    J2DTextBoxVBinding,
                                    float,
                                    float,
                                    unsigned char) */

void __thiscall
J2DPrint::printReturn
          (J2DPrint *this,char *param_1,float param_2,float param_3,J2DTextBoxHBindingType hBinding,
          J2DTextBoxVBindingType vBinding,float param_6,float param_7,uchar param_8)

{
  int iVar1;
  int iVar2;
  size_t sVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  undefined8 in_f26;
  undefined8 in_f27;
  undefined8 in_f28;
  undefined8 in_f29;
  undefined8 in_f30;
  double dVar11;
  undefined8 in_f31;
  double dVar12;
  TSize TStack696;
  ushort local_2b0 [260];
  double local_a8;
  double local_a0;
  double local_98;
  double local_90;
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar10 = (double)param_6;
  dVar11 = (double)param_7;
  dVar9 = (double)param_3;
  dVar7 = (double)param_2;
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  __psq_st0(auStack72,(int)((ulonglong)in_f27 >> 0x20),0);
  __psq_st1(auStack72,(int)in_f27,0);
  __psq_st0(auStack88,(int)((ulonglong)in_f26 >> 0x20),0);
  __psq_st1(auStack88,(int)in_f26,0);
  if (this->mpFont != (JUTFont *)0x0) {
    initchar(this);
    dVar8 = J2DGraph::_588;
    local_a8 = (double)(longlong)(int)this->field_0x2c;
    local_a0 = (double)CONCAT44(0x43300000,(int)this->field_0x2c ^ 0x80000000);
    this->field_0x24 = (float)(local_a0 - J2DGraph::_588);
    local_98 = (double)(longlong)(int)this->field_0x30;
    local_90 = (double)CONCAT44(0x43300000,(int)this->field_0x30 ^ 0x80000000);
    this->field_0x28 = (float)(local_90 - dVar8);
    sVar3 = MSL_C.PPCEABI.bare.H::strlen(param_1);
    if ((uint)mStrBuffSize <= sVar3) {
      sVar3 = mStrBuffSize - 1;
      mBufferNotEnough = 1;
    }
    iVar1 = (int)dVar7;
    local_90 = (double)(longlong)iVar1;
    dVar8 = (double)parse(this,(uchar *)param_1,sVar3,iVar1,local_2b0,&TStack696,param_8,false);
    uVar4 = (*(code *)this->mpFont->vtbl->getCellHeight)();
    local_98 = (double)CONCAT44(0x43300000,uVar4 ^ 0x80000000);
    dVar12 = (double)(this->mHeight / (float)(local_98 - J2DGraph::_588));
    uVar4 = (*(code *)this->mpFont->vtbl->getAscent)();
    local_a0 = (double)CONCAT44(0x43300000,uVar4 ^ 0x80000000);
    dVar12 = (double)(float)((double)(float)(local_a0 - J2DGraph::_588) * dVar12);
    if (vBinding == VBindingBottom) {
      uVar4 = (uint)(J2DGraph::_730 + (float)(dVar8 + dVar12));
      local_90 = (double)(longlong)(int)uVar4;
      local_98 = (double)CONCAT44(0x43300000,uVar4 ^ 0x80000000);
      dVar11 = (double)(float)(dVar11 + (double)(float)(dVar9 - (double)(float)(local_98 -
                                                                               J2DGraph::_588)));
    }
    else {
      if (((int)vBinding < 1) && (-1 < (int)vBinding)) {
        uVar4 = (uint)(J2DGraph::_730 + (float)(dVar8 + dVar12));
        local_90 = (double)(longlong)(int)uVar4;
        local_98 = (double)CONCAT44(0x43300000,uVar4 ^ 0x80000000);
        dVar11 = (double)(float)(dVar11 + (double)((float)(dVar9 - (double)(float)(local_98 -
                                                                                  J2DGraph::_588)) *
                                                  J2DGraph::_730));
      }
    }
    for (iVar5 = 0; uVar4 = (uint)*(ushort *)((int)local_2b0 + iVar5), uVar4 != 0xffff;
        iVar5 = iVar5 + 2) {
      if (hBinding == HBindingRight) {
        local_90 = (double)CONCAT44(0x43300000,uVar4);
        iVar2 = (int)(dVar7 - (double)(float)(local_90 - J2DGraph::_736));
        local_98 = (double)(longlong)iVar2;
        *(short *)((int)local_2b0 + iVar5) = (short)iVar2;
      }
      else {
        if ((int)hBinding < 1) {
          if (-1 < (int)hBinding) {
            local_90 = (double)CONCAT44(0x43300000,uVar4);
            iVar2 = (int)((float)(dVar7 - (double)(float)(local_90 - J2DGraph::_736)) *
                         J2DGraph::_730);
            local_98 = (double)(longlong)iVar2;
            *(short *)((int)local_2b0 + iVar5) = (short)iVar2;
          }
        }
        else {
          if ((int)hBinding < 3) {
            *(undefined2 *)((int)local_2b0 + iVar5) = 0;
          }
        }
      }
    }
    initchar(this);
    this->field_0x2c = (float)((double)this->field_0x2c + dVar10);
    this->field_0x30 = this->field_0x30 + (float)(dVar11 + dVar12);
    dVar7 = J2DGraph::_588;
    local_90 = (double)(longlong)(int)this->field_0x2c;
    local_98 = (double)CONCAT44(0x43300000,(int)this->field_0x2c ^ 0x80000000);
    this->field_0x24 = (float)(local_98 - J2DGraph::_588);
    local_a0 = (double)(longlong)(int)this->field_0x30;
    local_a8 = (double)CONCAT44(0x43300000,(int)this->field_0x30 ^ 0x80000000);
    this->field_0x28 = (float)(local_a8 - dVar7);
    parse(this,(uchar *)param_1,sVar3,iVar1,local_2b0,&TStack696,param_8,true);
  }
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  __psq_l0(auStack24,uVar6);
  __psq_l1(auStack24,uVar6);
  __psq_l0(auStack40,uVar6);
  __psq_l1(auStack40,uVar6);
  __psq_l0(auStack56,uVar6);
  __psq_l1(auStack56,uVar6);
  __psq_l0(auStack72,uVar6);
  __psq_l1(auStack72,uVar6);
  __psq_l0(auStack88,uVar6);
  __psq_l1(auStack88,uVar6);
  return;
}


/* WARNING: Inlined function: FUN_80328f1c */
/* WARNING: Inlined function: FUN_80328f68 */
/* WARNING: Removing unreachable block (ram,0x802cef74) */
/* WARNING: Removing unreachable block (ram,0x802cef64) */
/* WARNING: Removing unreachable block (ram,0x802cef54) */
/* WARNING: Removing unreachable block (ram,0x802cef44) */
/* WARNING: Removing unreachable block (ram,0x802cef34) */
/* WARNING: Removing unreachable block (ram,0x802cef3c) */
/* WARNING: Removing unreachable block (ram,0x802cef4c) */
/* WARNING: Removing unreachable block (ram,0x802cef5c) */
/* WARNING: Removing unreachable block (ram,0x802cef6c) */
/* WARNING: Removing unreachable block (ram,0x802cef7c) */
/* __thiscall J2DPrint::parse(unsigned char const *,
                              int,
                              int,
                              unsigned short *,
                              J2DPrint::TSize &,
                              unsigned char,
                              bool) */

double __thiscall
J2DPrint::parse(J2DPrint *this,uchar *pText,int param_2,int param_3,ushort *param_4,TSize *pDstSize,
               uchar alpha,bool param_7)

{
  bool bVar1;
  byte bVar2;
  bool bVar3;
  _GXColor *p_Var4;
  char cVar8;
  short sVar7;
  JUTFont *pJVar5;
  uint uVar6;
  uint uVar9;
  uint uVar10;
  undefined4 uVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  undefined8 in_f22;
  undefined8 in_f23;
  double dVar17;
  undefined8 in_f24;
  undefined8 in_f25;
  double dVar18;
  undefined8 in_f26;
  undefined8 in_f27;
  double dVar19;
  undefined8 in_f28;
  undefined8 in_f29;
  double dVar20;
  undefined8 in_f30;
  double dVar21;
  undefined8 in_f31;
  double dVar22;
  byte *local_108;
  TWidth uStack260;
  _GXColor local_100;
  _GXColor local_fc;
  _GXColor local_f8;
  _GXColor local_f4;
  double local_f0;
  longlong local_e8;
  undefined4 local_e0;
  uint uStack220;
  double local_d8;
  undefined auStack152 [16];
  undefined auStack136 [16];
  undefined auStack120 [16];
  undefined auStack104 [16];
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar11 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  __psq_st0(auStack72,(int)((ulonglong)in_f27 >> 0x20),0);
  __psq_st1(auStack72,(int)in_f27,0);
  __psq_st0(auStack88,(int)((ulonglong)in_f26 >> 0x20),0);
  __psq_st1(auStack88,(int)in_f26,0);
  __psq_st0(auStack104,(int)((ulonglong)in_f25 >> 0x20),0);
  __psq_st1(auStack104,(int)in_f25,0);
  __psq_st0(auStack120,(int)((ulonglong)in_f24 >> 0x20),0);
  __psq_st1(auStack120,(int)in_f24,0);
  __psq_st0(auStack136,(int)((ulonglong)in_f23 >> 0x20),0);
  __psq_st1(auStack136,(int)in_f23,0);
  __psq_st0(auStack152,(int)((ulonglong)in_f22 >> 0x20),0);
  __psq_st1(auStack152,(int)in_f22,0);
  if (this->mpFont == (JUTFont *)0x0) {
    dVar15 = (double)J2DGraph::0_0;
LAB_802cef34:
    __psq_l0(auStack8,uVar11);
    __psq_l1(auStack8,uVar11);
    __psq_l0(auStack24,uVar11);
    __psq_l1(auStack24,uVar11);
    __psq_l0(auStack40,uVar11);
    __psq_l1(auStack40,uVar11);
    __psq_l0(auStack56,uVar11);
    __psq_l1(auStack56,uVar11);
    __psq_l0(auStack72,uVar11);
    __psq_l1(auStack72,uVar11);
    __psq_l0(auStack88,uVar11);
    __psq_l1(auStack88,uVar11);
    __psq_l0(auStack104,uVar11);
    __psq_l1(auStack104,uVar11);
    __psq_l0(auStack120,uVar11);
    __psq_l1(auStack120,uVar11);
    __psq_l0(auStack136,uVar11);
    __psq_l1(auStack136,uVar11);
    __psq_l0(auStack152,uVar11);
    __psq_l1(auStack152,uVar11);
    return dVar15;
  }
  uVar10 = 0;
  dVar22 = (double)this->field_0x2c;
  dVar21 = (double)this->field_0x30;
  dVar15 = (double)J2DGraph::0_0;
  local_108 = pText + 1;
  bVar2 = *pText;
  dVar12 = (double)this->field_0x2c;
  dVar13 = (double)this->field_0x30;
  local_f4 = (_GXColor)
             ((uint)this->mColorTop & 0xffffff00 |
             (((uint)this->mColorTop & 0xff) * (uint)alpha) / 0xff & 0xff);
  local_f8 = (_GXColor)
             ((uint)this->mColorBottom & 0xffffff00 |
             (((uint)this->mColorBottom & 0xff) * (uint)alpha) / 0xff & 0xff);
  p_Var4 = &local_f4;
  if (this->field_0x22 != 0) {
    p_Var4 = &local_f8;
  }
  local_100 = *p_Var4;
  local_fc = local_f4;
  dVar18 = dVar13;
  dVar19 = dVar12;
  dVar20 = dVar15;
  JUTFont::setGradColor(this->mpFont,&local_fc,&local_100);
LAB_802ce9c8:
  uVar9 = (uint)bVar2;
  cVar8 = (*(code *)this->mpFont->vtbl->isLeadByte)(this->mpFont,uVar9);
  bVar1 = cVar8 != '\0';
  if (bVar1) {
    uVar9 = (uint)CONCAT11(bVar2,*local_108);
    local_108 = local_108 + 1;
  }
  if ((uVar9 == 0) || ((uint)param_2 < (uint)((int)local_108 - (int)pText))) {
    if ((param_7 == false) && (param_4 != (ushort *)0x0)) {
      local_f0 = (double)(longlong)(int)((double)J2DGraph::_730 + dVar20);
      param_4[uVar10 & 0xffff] = (ushort)(int)((double)J2DGraph::_730 + dVar20);
    }
    goto LAB_802ceec4;
  }
  bVar3 = true;
  dVar17 = (double)this->field_0x2c;
  if (uVar9 < 0x20) {
    if (uVar9 == 0x1b) {
      sVar7 = doEscapeCode(this,&local_108,alpha);
      uVar9 = uVar10;
      if (sVar7 == 0x484d) {
        if ((param_7 == false) && (param_4 != (ushort *)0x0)) {
          local_f0 = (double)(longlong)(int)((double)J2DGraph::_730 + dVar20);
          param_4[uVar10 & 0xffff] = (ushort)(int)((double)J2DGraph::_730 + dVar20);
        }
        this->field_0x2c = (float)dVar22;
        this->field_0x30 = (float)dVar21;
        uVar9 = uVar10 + 1;
        if ((uVar9 & 0xffff) == 0x100) goto LAB_802ceec4;
        dVar20 = (double)J2DGraph::0_0;
      }
      uVar10 = uVar9;
      if (sVar7 != 0) {
        bVar3 = false;
      }
    }
    else {
      doCtrlCode(this,uVar9);
      bVar3 = false;
      if (uVar9 == 10) {
        if ((param_7 == false) && (param_4 != (ushort *)0x0)) {
          local_f0 = (double)(longlong)(int)((double)J2DGraph::_730 + dVar20);
          param_4[uVar10 & 0xffff] = (ushort)(int)((double)J2DGraph::_730 + dVar20);
        }
        if ((uVar10 + 1 & 0xffff) == 0x100) goto LAB_802ceec4;
        dVar20 = (double)J2DGraph::0_0;
        uVar10 = uVar10 + 1;
      }
    }
  }
  else {
    if ((bVar1) && ((uint)param_2 < (uint)((int)local_108 - (int)pText))) {
      if ((param_7 == false) && (param_4 != (ushort *)0x0)) {
        local_f0 = (double)(longlong)(int)((double)J2DGraph::_730 + dVar20);
        param_4[uVar10 & 0xffff] = (ushort)(int)((double)J2DGraph::_730 + dVar20);
      }
LAB_802ceec4:
      if (param_4 != (ushort *)0x0) {
        *(undefined2 *)((int)param_4 + ((uVar10 + 1) * 2 & 0x1fffe)) = 0xffff;
      }
      pDstSize->mWidth = (float)(dVar12 - dVar19);
      uVar10 = (*(code *)this->mpFont->vtbl->getLeading)();
      local_d8 = (double)CONCAT44(0x43300000,uVar10 ^ 0x80000000);
      pDstSize->mHeight = (float)(dVar13 - dVar18) + (float)(local_d8 - J2DGraph::_588);
      if (param_7 == false) {
        this->field_0x2c = (float)dVar22;
        this->field_0x30 = (float)dVar21;
      }
      goto LAB_802cef34;
    }
    pJVar5 = this->mpFont;
    if (pJVar5->field_0x5 == 0) {
      (*(code *)pJVar5->vtbl->getWidthEntry)(pJVar5,uVar9,&uStack260);
      local_f0 = (double)CONCAT44(0x43300000,(uint)uStack260.mAdvance);
      this->field_0x34 = (float)(local_f0 - J2DGraph::_736);
    }
    else {
      local_f0 = (double)CONCAT44(0x43300000,pJVar5->mWidth ^ 0x80000000);
      this->field_0x34 = (float)(local_f0 - J2DGraph::_588);
    }
    uVar6 = (*(code *)this->mpFont->vtbl->getCellWidth)();
    dVar14 = J2DGraph::_588;
    local_f0 = (double)CONCAT44(0x43300000,uVar6 ^ 0x80000000);
    this->field_0x34 = this->field_0x34 * (this->field_0x18 / (float)(local_f0 - J2DGraph::_588));
    dVar16 = (double)this->field_0x2c;
    uStack220 = (uint)(J2DGraph::_858 *
                      ((float)(dVar16 + (double)this->field_0x34) - this->field_0x24));
    local_e8 = (longlong)(int)uStack220;
    uStack220 = uStack220 ^ 0x80000000;
    local_e0 = 0x43300000;
    local_d8 = (double)CONCAT44(0x43300000,param_3 ^ 0x80000000);
    if (((float)((double)CONCAT44(0x43300000,uStack220) - dVar14) / J2DGraph::_858 <=
         (float)(local_d8 - dVar14)) || (dVar16 <= dVar22)) {
      if (param_7 != false) {
        if (param_4 == (ushort *)0x0) {
          (*(code *)this->mpFont->vtbl->drawChar_scale)
                    (dVar16,(double)this->field_0x30,(double)this->field_0x18,
                     (double)this->field_0x1c,this->mpFont,uVar9,1);
        }
        else {
          local_d8 = (double)CONCAT44(0x43300000,(int)(short)param_4[uVar10 & 0xffff] ^ 0x80000000);
          (*(code *)this->mpFont->vtbl->drawChar_scale)
                    ((double)(float)(dVar16 + (double)(float)(local_d8 - J2DGraph::_588)),
                     (double)this->field_0x30,(double)this->field_0x18,(double)this->field_0x1c,
                     this->mpFont,uVar9,1);
        }
      }
      this->field_0x2c = this->field_0x2c + this->field_0x34;
    }
    else {
      local_108 = local_108 + (-1 - (uint)bVar1);
      this->field_0x30 = this->field_0x30 + this->field_0x14;
      if ((param_7 == false) && (param_4 != (ushort *)0x0)) {
        local_d8 = (double)(longlong)(int)((double)J2DGraph::_730 + dVar20);
        param_4[uVar10 & 0xffff] = (ushort)(int)((double)J2DGraph::_730 + dVar20);
      }
      if ((uVar10 + 1 & 0xffff) == 0x100) goto LAB_802ceec4;
      this->field_0x2c = this->field_0x24;
      dVar20 = (double)J2DGraph::0_0;
      bVar3 = false;
      uVar10 = uVar10 + 1;
    }
  }
  if (bVar3) {
    dVar14 = (double)(float)((double)this->field_0x2c - dVar22);
    if (dVar20 < dVar14) {
      dVar20 = dVar14;
    }
    this->field_0x2c = this->field_0x2c + this->field_0x10;
    this->field_0x34 = this->field_0x34 + this->field_0x10;
    uVar9 = (*(code *)this->mpFont->vtbl->getDescent)();
    local_d8 = (double)CONCAT44(0x43300000,uVar9 ^ 0x80000000);
    dVar14 = (double)(float)(local_d8 - J2DGraph::_588);
    uStack220 = (*(code *)this->mpFont->vtbl->getHeight)();
    uStack220 = uStack220 ^ 0x80000000;
    local_e0 = 0x43300000;
    dVar16 = (double)this->field_0x30;
    dVar14 = (double)(float)(dVar16 + (double)(float)((double)(this->field_0x1c /
                                                              (float)((double)CONCAT44(0x43300000,
                                                                                       uStack220) -
                                                                     J2DGraph::_588)) * dVar14));
    if (dVar15 < dVar14) {
      dVar15 = dVar14;
    }
    dVar14 = (double)this->field_0x2c;
    if (dVar12 < dVar14) {
      dVar12 = dVar14;
    }
    if (dVar14 < dVar19) {
      dVar19 = dVar14;
    }
    if (dVar17 < dVar19) {
      dVar19 = dVar17;
    }
    if (dVar13 < dVar16) {
      dVar13 = dVar16;
    }
    if (dVar16 < dVar18) {
      dVar18 = dVar16;
    }
  }
  bVar2 = *local_108;
  local_108 = local_108 + 1;
  goto LAB_802ce9c8;
}


/* __thiscall J2DPrint::doCtrlCode(int) */

void __thiscall J2DPrint::doCtrlCode(J2DPrint *this,int param_1)

{
  float fVar1;
  int iVar2;
  
  switch(param_1) {
  case 8:
    this->field_0x2c = this->field_0x2c - this->field_0x34;
    this->field_0x34 = J2DGraph::0_0;
    break;
  case 9:
    iVar2 = (int)this->field_0x20;
    if (0 < this->field_0x20) {
      fVar1 = this->field_0x2c;
      this->field_0x2c =
           (float)((double)CONCAT44(0x43300000,iVar2 + iVar2 * ((int)fVar1 / iVar2) ^ 0x80000000) -
                  J2DGraph::_588);
      this->field_0x34 = this->field_0x2c - fVar1;
    }
    break;
  case 10:
    this->field_0x34 = J2DGraph::0_0;
    this->field_0x2c = this->field_0x24;
    this->field_0x30 = this->field_0x30 + this->field_0x14;
    break;
  case 0xd:
    this->field_0x34 = J2DGraph::0_0;
    this->field_0x2c = this->field_0x24;
    break;
  case 0x1c:
    this->field_0x2c = this->field_0x2c + J2DGraph::1_0;
    break;
  case 0x1d:
    this->field_0x2c = this->field_0x2c - J2DGraph::1_0;
    break;
  case 0x1e:
    this->field_0x30 = this->field_0x30 - J2DGraph::1_0;
    break;
  case 0x1f:
    this->field_0x30 = this->field_0x30 + J2DGraph::1_0;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Could not reconcile some variable overlaps */
/* __thiscall J2DPrint::doEscapeCode(unsigned char const * *,
                                     unsigned char) */

uint __thiscall J2DPrint::doEscapeCode(J2DPrint *this,uchar **param_1,uchar param_2)

{
  uint uVar1;
  char cVar4;
  _GXColor *p_Var2;
  undefined4 uVar3;
  int iVar5;
  uint uVar6;
  uchar *puVar7;
  double dVar8;
  _GXColor local_48;
  _GXColor local_44;
  _GXColor local_40;
  _GXColor local_3c;
  undefined4 local_38;
  _GXColor local_34;
  _GXColor local_30;
  undefined4 local_2c;
  _GXColor local_28;
  _GXColor local_24 [3];
  
  puVar7 = *param_1;
  uVar6 = 0;
  iVar5 = 0;
  do {
    cVar4 = (*(code *)this->mpFont->vtbl->isLeadByte)(this->mpFont,**param_1);
    if (cVar4 == '\0') {
      uVar1 = (uint)**param_1;
      *param_1 = *param_1 + 1;
    }
    else {
      uVar1 = (uint)*(ushort *)*param_1;
      *param_1 = (uchar *)((int)*param_1 + 2);
    }
    if ((0x7f < uVar1) || (uVar1 < 0x20)) {
      *param_1 = puVar7;
      return 0;
    }
    uVar6 = (uVar6 & 0xff) << 8 | uVar1;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 2);
  local_24[0] = this->mColorTop;
  local_28 = this->mColorBottom;
  if (uVar6 == 0x474d) {
    uVar6 = countLeadingZeros((uint)this->field_0x22);
    uVar3 = getNumberS32(this,param_1,uVar6 >> 5 & 0xff,(uint)this->field_0x22,10);
    uVar6 = countLeadingZeros(uVar3);
    uVar6 = countLeadingZeros(uVar6 >> 5 & 0xff);
    this->field_0x22 = (byte)(uVar6 >> 5);
    local_24[0] = (_GXColor)
                  ((uint)local_24[0] & 0xffffff00 |
                  (((uint)local_24[0] & 0xff) * (uint)param_2) / 0xff & 0xff);
    local_28 = (_GXColor)
               ((uint)local_28 & 0xffffff00 |
               (((uint)local_28 & 0xff) * (uint)param_2) / 0xff & 0xff);
    p_Var2 = local_24;
    if (this->field_0x22 != 0) {
      p_Var2 = &local_28;
    }
    local_48 = *p_Var2;
    local_44 = local_24[0];
    JUTFont::setGradColor(this->mpFont,&local_44,&local_48);
    return 0x474d;
  }
  if (uVar6 < 0x474d) {
    if (uVar6 == 0x4355) {
      dVar8 = (double)getNumberF32(this,param_1,J2DGraph::1_0,J2DGraph::0_0,10);
      this->field_0x30 = (float)((double)this->field_0x30 - dVar8);
      return 0x4355;
    }
    if (uVar6 < 0x4355) {
      if (uVar6 == 0x434c) {
        dVar8 = (double)getNumberF32(this,param_1,J2DGraph::1_0,J2DGraph::0_0,10);
        this->field_0x2c = (float)((double)this->field_0x2c - dVar8);
        return 0x434c;
      }
      if (uVar6 < 0x434c) {
        if (uVar6 == 0x4344) {
          dVar8 = (double)getNumberF32(this,param_1,J2DGraph::1_0,J2DGraph::0_0,10);
          this->field_0x30 = (float)((double)this->field_0x30 + dVar8);
          return 0x4344;
        }
        if ((uVar6 < 0x4344) && (0x4342 < uVar6)) {
          local_2c = getNumberS32(this,param_1,(long)this->field_0x40,(long)this->mColorTop,0x10);
          local_2c._0_1_ = (u8)((uint)local_2c >> 0x18);
          (this->mColorTop).r = local_2c._0_1_;
          local_2c._1_1_ = (u8)((uint)local_2c >> 0x10);
          (this->mColorTop).g = local_2c._1_1_;
          local_2c._2_1_ = (u8)((uint)local_2c >> 8);
          (this->mColorTop).b = local_2c._2_1_;
          (this->mColorTop).a = (u8)local_2c;
          local_24[0] = (_GXColor)
                        (((uint)(this->mColorTop).a * (uint)param_2) / 0xff & 0xff |
                        (uint)*(uint3 *)&this->mColorTop << 8);
          local_28 = (_GXColor)
                     ((uint)local_28 & 0xffffff00 |
                     (((uint)local_28 & 0xff) * (uint)param_2) / 0xff & 0xff);
          p_Var2 = local_24;
          if (this->field_0x22 != 0) {
            p_Var2 = &local_28;
          }
          local_34 = *p_Var2;
          local_30 = local_24[0];
          JUTFont::setGradColor(this->mpFont,&local_30,&local_34);
          return uVar6;
        }
      }
      else {
        if (uVar6 == 0x4352) {
          dVar8 = (double)getNumberF32(this,param_1,J2DGraph::1_0,J2DGraph::0_0,10);
          this->field_0x2c = (float)((double)this->field_0x2c + dVar8);
          return 0x4352;
        }
      }
    }
    else {
      if (uVar6 == 0x4659) {
        dVar8 = (double)getNumberF32(this,param_1,this->mHeight,this->field_0x1c,10);
        if (dVar8 < (double)J2DGraph::0_0) {
          return 0x4659;
        }
        this->field_0x1c = (float)dVar8;
        return 0x4659;
      }
      if (uVar6 < 0x4659) {
        if (0x4657 < uVar6) {
          dVar8 = (double)getNumberF32(this,param_1,this->mWidth,this->field_0x18,10);
          if (dVar8 < (double)J2DGraph::0_0) {
            return uVar6;
          }
          this->field_0x18 = (float)dVar8;
          return uVar6;
        }
      }
      else {
        if (uVar6 == 0x4743) {
          local_38 = getNumberS32(this,param_1,(long)this->field_0x44,(long)this->mColorBottom,0x10)
          ;
          local_38._0_1_ = (u8)((uint)local_38 >> 0x18);
          (this->mColorBottom).r = local_38._0_1_;
          local_38._1_1_ = (u8)((uint)local_38 >> 0x10);
          (this->mColorBottom).g = local_38._1_1_;
          local_38._2_1_ = (u8)((uint)local_38 >> 8);
          (this->mColorBottom).b = local_38._2_1_;
          (this->mColorBottom).a = (u8)local_38;
          local_24[0] = (_GXColor)
                        ((uint)local_24[0] & 0xffffff00 |
                        (((uint)local_24[0] & 0xff) * (uint)param_2) / 0xff & 0xff);
          local_28 = (_GXColor)
                     (((uint)(this->mColorBottom).a * (uint)param_2) / 0xff & 0xff |
                     (uint)*(uint3 *)&this->mColorBottom << 8);
          p_Var2 = local_24;
          if (this->field_0x22 != 0) {
            p_Var2 = &local_28;
          }
          local_40 = *p_Var2;
          local_3c = local_24[0];
          JUTFont::setGradColor(this->mpFont,&local_3c,&local_40);
          return 0x4743;
        }
      }
    }
  }
  else {
    if (uVar6 == 0x5348) {
      dVar8 = (double)getNumberF32(this,param_1,this->field_0x48,this->field_0x10,10);
      this->field_0x10 = (float)dVar8;
      return 0x5348;
    }
    if (uVar6 < 0x5348) {
      if (uVar6 == 0x4c44) {
        this->field_0x30 = this->field_0x30 + this->field_0x14;
        return 0x4c44;
      }
      if (uVar6 < 0x4c44) {
        if (uVar6 == 0x484d) {
          return 0x484d;
        }
      }
      else {
        if (uVar6 == 0x4c55) {
          this->field_0x30 = this->field_0x30 - this->field_0x14;
          return 0x4c55;
        }
      }
    }
    else {
      if (uVar6 != 0x5355) {
        if (uVar6 < 0x5355) {
          if (0x5353 < uVar6) {
            iVar5 = getNumberS32(this,param_1,(int)this->field_0x20,(int)this->field_0x20,10);
            if (iVar5 < 1) {
              return uVar6;
            }
            this->field_0x20 = (short)iVar5;
            return uVar6;
          }
        }
        else {
          if (uVar6 < 0x5357) {
            dVar8 = (double)getNumberF32(this,param_1,this->field_0x4c,this->field_0x14,10);
            this->field_0x14 = (float)dVar8;
            return uVar6;
          }
        }
      }
    }
  }
  *param_1 = puVar7;
  return 0;
}


/* __thiscall J2DPrint::initchar(void) */

void __thiscall J2DPrint::initchar(J2DPrint *this)

{
  (this->mColorTop).r = (this->field_0x40).r;
  (this->mColorTop).g = (this->field_0x40).g;
  (this->mColorTop).b = (this->field_0x40).b;
  (this->mColorTop).a = (this->field_0x40).a;
  (this->mColorBottom).r = (this->field_0x44).r;
  (this->mColorBottom).g = (this->field_0x44).g;
  (this->mColorBottom).b = (this->field_0x44).b;
  (this->mColorBottom).a = (this->field_0x44).a;
  this->field_0x10 = this->field_0x48;
  this->field_0x14 = this->field_0x4c;
  this->field_0x22 = *(byte *)&this->field_0x5a;
  this->field_0x20 = *(short *)&this->field_0x58;
  this->field_0x18 = this->mWidth;
  this->field_0x1c = this->mHeight;
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall J2DPrint::getNumberS32(unsigned char const * *,
                                     long,
                                     long,
                                     int) */

ulong __thiscall
J2DPrint::getNumberS32(J2DPrint *this,uchar **param_1,long param_2,long param_3,int param_4)

{
  ulong uVar1;
  uchar *puVar2;
  uchar *local_18 [2];
  
  puVar2 = *param_1;
  uVar1 = param_2;
  if (*puVar2 == '[') {
    *param_1 = puVar2 + 1;
    uVar1 = 0;
    if (param_4 == 10) {
      uVar1 = MSL_C.PPCEABI.bare.H::strtol((char *)*param_1,(char **)local_18,10);
    }
    else {
      if (param_4 == 0x10) {
        uVar1 = MSL_C.PPCEABI.bare.H::strtoul((char *)*param_1,(char **)local_18,0x10);
        if ((int)local_18[0] - (int)*param_1 != 8) {
          if ((int)local_18[0] - (int)*param_1 != 6) {
            *param_1 = puVar2;
            return param_3;
          }
          uVar1 = uVar1 << 8 | 0xff;
        }
      }
    }
    if (*local_18[0] == ']') {
      if (*param_1 == local_18[0]) {
        *param_1 = local_18[0] + 1;
        uVar1 = param_2;
      }
      else {
        *param_1 = local_18[0] + 1;
      }
    }
    else {
      *param_1 = puVar2;
      uVar1 = param_3;
    }
  }
  return uVar1;
}


/* __thiscall J2DPrint::~J2DPrint(void) */

void __thiscall J2DPrint::_J2DPrint(J2DPrint *this,short flag)

{
  if ((this != (J2DPrint *)0x0) && (*(undefined ***)this = &__vt, 0 < flag)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}

