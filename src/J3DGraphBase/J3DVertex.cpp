#include <J3DGraphBase/J3DVertex.h>
#include <JKernel/JKRHeap.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <J3DDrawMtxData.h>
#include <J3DVertexBuffer.h>
#include <J3DVertexData.h>


/* __thiscall J3DVertexData::J3DVertexData(void) */

void __thiscall J3DVertexData::J3DVertexData(J3DVertexData *this)

{
  int iVar1;
  int iVar2;
  
  this->mVertexCount = 0;
  this->mArrSizeNrm = 0;
  this->mArrSizeClr = 0;
  this->mpAttribFormats = (undefined *)0x0;
  this->mpVertexArr_Pos = (char *)0x0;
  this->mpVertexArr_Nrm = (char *)0x0;
  this->mpVertexArr_Nbt = (char *)0x0;
  iVar1 = 0;
  iVar2 = 2;
  do {
    *(undefined4 *)((int)this->mpVertexArr_Clr + iVar1) = 0;
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar1 = 0;
  iVar2 = 8;
  do {
    *(undefined4 *)((int)this->mpVertexArr_Tex + iVar1) = 0;
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined *)&this->mPacketCount = 0;
  *(undefined4 *)&this->field_0x4c = 4;
  *(undefined *)&this->field_0x50 = 0;
  *(undefined4 *)&this->field_0x54 = 4;
  return;
}


/* __thiscall J3DVertexData::~J3DVertexData(void) */

void __thiscall J3DVertexData::_J3DVertexData(J3DVertexData *this)

{
  short in_r4;
  
  if ((this != (J3DVertexData *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall J3DVertexBuffer::setVertexData(J3DVertexData *) */

void __thiscall J3DVertexBuffer::setVertexData(J3DVertexBuffer *this,J3DVertexData *param_1)

{
  this->mpVertexData = param_1;
  this->mpVertexArr_Pos = param_1->mpVertexArr_Pos;
  this->mpVertexArr_Nrm = param_1->mpVertexArr_Nrm;
  this->mpVertexArr_Clr = param_1->mpVertexArr_Clr[0];
  this->field_0x8 = (undefined *)0x0;
  this->field_0x10 = (undefined *)0x0;
  *(undefined4 *)&this->field_0x18 = 0;
  this->mpTransformedVtxPos[0] = param_1->mpVertexArr_Pos;
  this->mpTransformVtxNrm[0] = param_1->mpVertexArr_Nrm;
  this->mpTransformedVtxPos[1] = (undefined *)0x0;
  this->mpTransformVtxNrm[1] = (undefined *)0x0;
  this->mpCurrentVtxPos = this->mpVertexArr_Pos;
  this->mpCurrentVtxNrm = this->mpVertexArr_Nrm;
  this->mpCurrentVtxClr = this->mpVertexArr_Clr;
  return;
}


/* __thiscall J3DVertexBuffer::init(void) */

int __thiscall J3DVertexBuffer::init(J3DVertexBuffer *this,EVP_PKEY_CTX *ctx)

{
  this->mpVertexData = (J3DVertexData *)0x0;
  this->field_0x8 = (undefined *)0x0;
  this->mpVertexArr_Pos = (undefined *)0x0;
  this->field_0x10 = (undefined *)0x0;
  this->mpVertexArr_Nrm = (undefined *)0x0;
  *(undefined4 *)&this->field_0x18 = 0;
  this->mpVertexArr_Clr = (undefined *)0x0;
  this->mpTransformedVtxPos[1] = (undefined *)0x0;
  this->mpTransformedVtxPos[0] = (undefined *)0x0;
  this->mpTransformVtxNrm[1] = (undefined *)0x0;
  this->mpTransformVtxNrm[0] = (undefined *)0x0;
  this->mpCurrentVtxPos = (undefined *)0x0;
  this->mpCurrentVtxNrm = (undefined *)0x0;
  this->mpCurrentVtxClr = (undefined *)0x0;
  this->mpCurrentVtxPos = this->mpVertexArr_Pos;
  this->mpCurrentVtxNrm = this->mpVertexArr_Nrm;
  this->mpCurrentVtxClr = this->mpVertexArr_Clr;
  return (int)this;
}


/* __thiscall J3DVertexBuffer::~J3DVertexBuffer(void) */

void __thiscall J3DVertexBuffer::_J3DVertexBuffer(J3DVertexBuffer *this)

{
  short in_r4;
  
  if ((this != (J3DVertexBuffer *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall J3DVertexBuffer::setArray(void) const */

void __thiscall J3DVertexBuffer::setArray(J3DVertexBuffer *this)

{
  J3DGraphBase::j3dSys.mpCurVtxPos = (cXyz *)this->mpCurrentVtxPos;
  J3DGraphBase::j3dSys.mpCurVtxNrm = (cXyz *)this->mpCurrentVtxNrm;
  J3DGraphBase::j3dSys.mpCurVtxClr = (_GXColor *)this->mpCurrentVtxClr;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall J3DVertexBuffer::allocTransformedVtxPosArray(void) */

undefined4 __thiscall J3DVertexBuffer::allocTransformedVtxPosArray(J3DVertexBuffer *this)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if ((this->mpTransformedVtxPos[0] == (undefined *)0x0) ||
     (this->mpTransformedVtxPos[1] == (undefined *)0x0)) {
    iVar2 = 0;
    iVar3 = 0;
    do {
      if ((iVar2 == 0) || (*(int *)((int)this->mpTransformedVtxPos + iVar3) == 0)) {
        uVar1 = JKernel::operator_new__(this->mpVertexData->mVertexCount * 0xc,0x20);
        *(undefined4 *)((int)this->mpTransformedVtxPos + iVar3) = uVar1;
        if (*(int *)((int)this->mpTransformedVtxPos + iVar3) == 0) {
          return 4;
        }
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 4;
    } while (iVar2 < 2);
  }
  return 0;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall J3DVertexBuffer::allocTransformedVtxNrmArray(void) */

undefined4 __thiscall J3DVertexBuffer::allocTransformedVtxNrmArray(J3DVertexBuffer *this)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if ((this->mpTransformVtxNrm[0] == (undefined *)0x0) ||
     (this->mpTransformVtxNrm[1] == (undefined *)0x0)) {
    iVar2 = 0;
    iVar3 = 0;
    do {
      if ((iVar2 == 0) || (*(int *)((int)this->mpTransformVtxNrm + iVar3) == 0)) {
        uVar1 = JKernel::operator_new__(this->mpVertexData->mArrSizeNrm * 0xc,0x20);
        *(undefined4 *)((int)this->mpTransformVtxNrm + iVar3) = uVar1;
        if (*(int *)((int)this->mpTransformVtxNrm + iVar3) == 0) {
          return 4;
        }
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 4;
    } while (iVar2 < 2);
  }
  return 0;
}


/* __thiscall J3DDrawMtxData::J3DDrawMtxData(void) */

void __thiscall J3DDrawMtxData::J3DDrawMtxData(J3DDrawMtxData *this)

{
  this->mDrawMtxCount = 0;
  this->mpMtxTypeArray = (byte *)0x0;
  this->mpDataArray = (short *)0x0;
  return;
}


/* __thiscall J3DDrawMtxData::~J3DDrawMtxData(void) */

void __thiscall J3DDrawMtxData::_J3DDrawMtxData(J3DDrawMtxData *this)

{
  short in_r4;
  
  if ((this != (J3DDrawMtxData *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}

