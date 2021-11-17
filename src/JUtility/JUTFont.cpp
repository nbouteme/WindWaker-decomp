#include <JUtility/JUTFont.h>
#include <JUtility/JUTFont.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JUTFont.h>


/* __thiscall JUTFont::JUTFont(void) */

void __thiscall JUTFont::JUTFont(JUTFont *this)

{
  this->vtbl = (JUTFont__vtbl *)&__vt;
  this->field_0xc = (_GXColor)0xffffffff;
  this->field_0x10 = (_GXColor)0xffffffff;
  this->field_0x14 = (_GXColor)0xffffffff;
  this->field_0x18 = (_GXColor)0xffffffff;
  this->mValid = 0;
  return;
}


/* __thiscall JUTFont::initialize_state(void) */

void __thiscall JUTFont::initialize_state(JUTFont *this)

{
  _GXColor local_14 [4];
  
  local_14[0] = (_GXColor)0xffffffff;
  setCharColor(this,local_14);
  this->field_0x5 = 0;
  this->mWidth = 0;
  this->mValid = 0;
  return;
}


/* __thiscall JUTFont::setCharColor(JUtility::TColor) */

void __thiscall JUTFont::setCharColor(JUTFont *this,_GXColor *pColor)

{
  (this->field_0xc).r = pColor->r;
  (this->field_0xc).g = pColor->g;
  (this->field_0xc).b = pColor->b;
  (this->field_0xc).a = pColor->a;
  (this->field_0x10).r = pColor->r;
  (this->field_0x10).g = pColor->g;
  (this->field_0x10).b = pColor->b;
  (this->field_0x10).a = pColor->a;
  (this->field_0x14).r = pColor->r;
  (this->field_0x14).g = pColor->g;
  (this->field_0x14).b = pColor->b;
  (this->field_0x14).a = pColor->a;
  (this->field_0x18).r = pColor->r;
  (this->field_0x18).g = pColor->g;
  (this->field_0x18).b = pColor->b;
  (this->field_0x18).a = pColor->a;
  return;
}


/* __thiscall JUTFont::setGradColor(JUtility::TColor,
                                    JUtility::TColor) */

void __thiscall JUTFont::setGradColor(JUTFont *this,_GXColor *pColorTop,_GXColor *pColorBottom)

{
  (this->field_0xc).r = pColorTop->r;
  (this->field_0xc).g = pColorTop->g;
  (this->field_0xc).b = pColorTop->b;
  (this->field_0xc).a = pColorTop->a;
  (this->field_0x10).r = pColorTop->r;
  (this->field_0x10).g = pColorTop->g;
  (this->field_0x10).b = pColorTop->b;
  (this->field_0x10).a = pColorTop->a;
  (this->field_0x14).r = pColorBottom->r;
  (this->field_0x14).g = pColorBottom->g;
  (this->field_0x14).b = pColorBottom->b;
  (this->field_0x14).a = pColorBottom->a;
  (this->field_0x18).r = pColorBottom->r;
  (this->field_0x18).g = pColorBottom->g;
  (this->field_0x18).b = pColorBottom->b;
  (this->field_0x18).a = pColorBottom->a;
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x802c201c) */
/* WARNING: Removing unreachable block (ram,0x802c200c) */
/* WARNING: Removing unreachable block (ram,0x802c2004) */
/* WARNING: Removing unreachable block (ram,0x802c2014) */
/* WARNING: Removing unreachable block (ram,0x802c2024) */
/* __thiscall JUTFont::drawString_size_scale(float,
                                             float,
                                             float,
                                             float,
                                             char const *,
                                             unsigned long,
                                             bool) */

double __thiscall
JUTFont::drawString_size_scale
          (JUTFont *this,float param_1,float param_2,float param_3,float param_4,char *param_5,
          ulong param_6,bool param_7)

{
  byte bVar1;
  char cVar2;
  ushort uVar3;
  undefined3 in_register_00000018;
  undefined4 uVar4;
  undefined4 uVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  undefined8 in_f27;
  double dVar10;
  undefined8 in_f28;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  double dVar11;
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar4 = CONCAT31(in_register_00000018,param_7);
  dVar9 = (double)param_4;
  dVar8 = (double)param_3;
  dVar7 = (double)param_2;
  dVar10 = (double)param_1;
  uVar5 = 0;
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
  dVar11 = dVar10;
  for (; param_6 != 0; param_6 = param_6 - 1) {
    bVar1 = *param_5;
    uVar3 = (ushort)bVar1;
    cVar2 = (*(code *)this->vtbl->isLeadByte)(this);
    if (cVar2 != '\0') {
      param_5 = (char *)((byte *)param_5 + 1);
      uVar3 = CONCAT11(bVar1,*param_5);
      param_6 = param_6 - 1;
    }
    dVar6 = (double)(*(code *)this->vtbl->drawChar_scale)(dVar10,dVar7,dVar8,dVar9,this,uVar3,uVar4)
    ;
    dVar10 = (double)(float)(dVar10 + dVar6);
    uVar4 = 1;
    param_5 = (char *)((byte *)param_5 + 1);
  }
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  __psq_l0(auStack24,uVar5);
  __psq_l1(auStack24,uVar5);
  __psq_l0(auStack40,uVar5);
  __psq_l1(auStack40,uVar5);
  __psq_l0(auStack56,uVar5);
  __psq_l1(auStack56,uVar5);
  __psq_l0(auStack72,uVar5);
  __psq_l1(auStack72,uVar5);
  return (double)(float)(dVar10 - dVar11);
}

