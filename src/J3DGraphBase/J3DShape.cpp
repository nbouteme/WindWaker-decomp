#include <J3DGraphBase/J3DShape.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <J3DGraphBase/J3DShape.h>
#include <gd/GDGeometry.h>
#include <gd/GDBase.h>
#include <J3DGraphBase/J3DGD.h>
#include <gx/GXDisplayList.h>
#include <gx/GXAttr.h>
#include <J3DGraphBase/J3DShapeMtx.h>
#include <J3DGraphBase/J3DSys.h>
#include <J3DShape.h>

byte J3DShape;
byte J3DShape;

/* __thiscall J3DShape::initialize(void) */

void __thiscall J3DShape::initialize(J3DShape *this)

{
  float fVar1;
  
  this->mpMaterial = (J3DMaterial *)0x0;
  this->mShapeIdx = -1;
  this->mMtxGroupNum = 0;
  this->mVisFlags = 0;
  fVar1 = J3DGraphBase::_1500;
  this->mBoundingSphereRadius = J3DGraphBase::_1500;
  (this->mBoundingBoxMin).x = fVar1;
  (this->mBoundingBoxMin).y = fVar1;
  (this->mBoundingBoxMin).z = fVar1;
  (this->mBoundingBoxMax).x = fVar1;
  (this->mBoundingBoxMax).y = fVar1;
  (this->mBoundingBoxMax).z = fVar1;
  this->mpAttrDecl = (undefined *)0x0;
  this->mpShapeMtx = (J3DShapeMtx **)0x0;
  this->mpShapeDraw = (J3DShapeDraw **)0x0;
  this->mpVertexData = (J3DVertexData *)0x0;
  this->mpDrawMtxData = (J3DDrawMtxData *)0x0;
  this->field_0x54 = (undefined *)0x0;
  this->field_0x58 = (undefined *)0x0;
  this->field_0x5c = (undefined *)0x0;
  this->field_0x60 = &J3DGraphBase::j3dDefaultViewNo;
  this->mbHasNBT = false;
  this->mbHasPNMTXIDX = false;
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall J3DShape::calcNBTScale(Vec const &,
                                     float *[][][],
                                     float *[][][]) */

void __thiscall J3DShape::calcNBTScale(J3DShape *this,Vec *param_1,float *param_2,float *param_3)

{
  ushort uVar1;
  
  for (uVar1 = 0; uVar1 < (ushort)this->mMtxGroupNum; uVar1 = uVar1 + 1) {
    (**(code **)(*(int *)this->mpShapeMtx[uVar1] + 0x1c))
              (this->mpShapeMtx[uVar1],param_1,param_2,param_3);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall J3DShape::countBumpMtxNum(void) const */

int __thiscall J3DShape::countBumpMtxNum(J3DShape *this)

{
  int iVar1;
  ushort uVar2;
  int iVar3;
  
  iVar3 = 0;
  for (uVar2 = 0; uVar2 < (ushort)this->mMtxGroupNum; uVar2 = uVar2 + 1) {
    iVar1 = (**(code **)(*(int *)this->mpShapeMtx[uVar2] + 0x10))();
    iVar3 = iVar3 + iVar1;
  }
  return iVar3;
}


namespace J3DGraphBase {

/* __stdcall J3DLoadCPCmd(unsigned char,
                          unsigned long) */

void J3DLoadCPCmd(undefined param_1,undefined4 param_2)

{
  write_volatile_1(DAT_cc008000,8);
  write_volatile_1(DAT_cc008000,param_1);
  write_volatile_4(0xcc008000,param_2);
  return;
}


/* __stdcall J3DLoadArrayBasePtr(_GXAttr,
                                 void *) */

void J3DLoadArrayBasePtr(int param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = 1;
  if (param_1 != 0x19) {
    iVar1 = param_1 + -9;
  }
  J3DLoadCPCmd(iVar1 + 0xa0U & 0xff,param_2 & 0x7fffffff);
  return;
}

}

/* __thiscall J3DShape::loadVtxArray(void) const */

void __thiscall J3DShape::loadVtxArray(J3DShape *this)

{
  J3DGraphBase::J3DLoadArrayBasePtr(9,J3DGraphBase::j3dSys.mpCurVtxPos);
  if (this->mbHasNBT == false) {
    J3DGraphBase::J3DLoadArrayBasePtr(10,J3DGraphBase::j3dSys.mpCurVtxNrm);
  }
  J3DGraphBase::J3DLoadArrayBasePtr(0xb,J3DGraphBase::j3dSys.mpCurVtxClr);
  return;
}


/* __thiscall J3DShape::isSameVcdVatCmd(J3DShape *) */

undefined4 __thiscall J3DShape::isSameVcdVatCmd(J3DShape *this,J3DShape *param_1)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  
  pcVar2 = param_1->mpVatVcdCmd;
  pcVar1 = this->mpVatVcdCmd;
  iVar3 = 0xc0;
  do {
    if (*pcVar2 != *pcVar1) {
      return 0;
    }
    pcVar1 = pcVar1 + 1;
    pcVar2 = pcVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return 1;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall J3DShape::makeVtxArrayCmd(void) */

void __thiscall J3DShape::makeVtxArrayCmd(J3DShape *this)

{
  int *piVar1;
  int iVar2;
  char *pcVar3;
  J3DVertexData *pJVar4;
  char *pcVar5;
  int iVar6;
  char *apcStack112 [3];
  undefined uStack97;
  char local_58 [12];
  int local_4c;
  char *local_48;
  
  piVar1 = (int *)this->mpVertexData->mpAttribFormats;
  iVar2 = 0;
  pcVar3 = local_58;
  iVar6 = 0xc;
  do {
    *pcVar3 = '\0';
    *(undefined4 *)((int)&local_4c + iVar2) = 0;
    iVar2 = iVar2 + 4;
    pcVar3 = pcVar3 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  for (; iVar2 = *piVar1, iVar2 != 0xff; piVar1 = piVar1 + 4) {
    if (iVar2 == 10) {
      if (piVar1[2] == 4) {
        local_58[1] = '\f';
      }
      else {
        local_58[1] = '\x06';
      }
      pJVar4 = this->mpVertexData;
      *(char **)(&stack0xffffffa0 + *piVar1 * 4 + -0x10) = pJVar4->mpVertexArr_Nrm;
      *(undefined *)&pJVar4->field_0x50 = *(undefined *)(piVar1 + 3);
      *(int *)&this->mpVertexData->field_0x54 = piVar1[2];
    }
    else {
      if (iVar2 < 10) {
        if (8 < iVar2) {
          if (piVar1[2] == 4) {
            (&stack0xffffffa0)[iVar2 + -1] = 0xc;
          }
          else {
            (&stack0xffffffa0)[iVar2 + -1] = 6;
          }
          pJVar4 = this->mpVertexData;
          *(char **)(&stack0xffffffa0 + *piVar1 * 4 + -0x10) = pJVar4->mpVertexArr_Pos;
          *(undefined *)&pJVar4->mPacketCount = *(undefined *)(piVar1 + 3);
          *(int *)&this->mpVertexData->field_0x4c = piVar1[2];
        }
      }
      else {
        if (iVar2 < 0x15) {
          if (iVar2 < 0xd) {
            (&stack0xffffffa0)[iVar2 + -1] = 4;
            *(undefined4 *)(&stack0xffffffa0 + *piVar1 * 4 + -0x10) =
                 *(undefined4 *)
                  ((int)this->mpVertexData->mpVertexArr_Clr + ((*piVar1 + -0xb) * 4 & 0x3fcU));
          }
          else {
            if (piVar1[2] == 4) {
              (&stack0xffffffa0)[iVar2 + -1] = 8;
            }
            else {
              (&stack0xffffffa0)[iVar2 + -1] = 4;
            }
            *(undefined4 *)(&stack0xffffffa0 + *piVar1 * 4 + -0x10) =
                 *(undefined4 *)
                  ((int)this->mpVertexData->mpVertexArr_Tex + ((*piVar1 + -0xd) * 4 & 0x3fcU));
          }
        }
      }
    }
  }
  piVar1 = (int *)this->mpAttrDecl;
  this->mbHasPNMTXIDX = false;
  for (; *piVar1 != 0xff; piVar1 = piVar1 + 2) {
    if ((*piVar1 == 0x19) && (piVar1[1] != 0)) {
      this->mbHasNBT = true;
      local_58[1] = local_58[1] * '\x03';
      local_48 = this->mpVertexData->mpVertexArr_Nbt;
    }
    if ((*piVar1 == 0) && (piVar1[1] != 0)) {
      this->mbHasPNMTXIDX = true;
    }
  }
  iVar2 = 0;
  iVar6 = 0;
  pcVar5 = local_58;
  pcVar3 = pcVar5;
  do {
    if (*(int *)((int)&local_4c + iVar6) == 0) {
      gd::GDSetArrayRaw(iVar2 + 9,0,*pcVar3);
    }
    else {
      gd::GDSetArray(iVar2 + 9,*(int *)((int)&local_4c + iVar6),*pcVar5);
    }
    iVar2 = iVar2 + 1;
    pcVar3 = pcVar3 + 1;
    pcVar5 = pcVar5 + 1;
    iVar6 = iVar6 + 4;
  } while (iVar2 < 0xc);
  return;
}


/* __thiscall J3DShape::makeVcdVatCmd(void) */

void __thiscall J3DShape::makeVcdVatCmd(J3DShape *this)

{
  undefined auStack24 [20];
  
  gd::GDInitGDLObj(auStack24,this->mpVatVcdCmd,0xc0);
  gd::__GDCurrentDL = auStack24;
  gd::GDSetVtxDescv(this->mpAttrDecl);
  makeVtxArrayCmd(this);
  J3DGraphBase::J3DGDSetVtxAttrFmtv(0,this->mpVertexData->mpAttribFormats,this->mbHasNBT);
  gd::GDPadCurr32();
  gd::GDFlushCurrToMem();
  gd::__GDCurrentDL = (undefined *)0x0;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall J3DShape::loadPreDrawSetting(void) const */

void __thiscall J3DShape::loadPreDrawSetting(J3DShape *this)

{
  if (_sOldVcdVatCmd != this->mpVatVcdCmd) {
    gx::GXCallDisplayList(this->mpVatVcdCmd,0xc0);
    _sOldVcdVatCmd = this->mpVatVcdCmd;
  }
  write_volatile_1(DAT_cc008000,8);
  write_volatile_1(DAT_cc008000,0x30);
  write_volatile_4(0xcc008000,this->field_0x40);
  write_volatile_1(DAT_cc008000,8);
  write_volatile_1(DAT_cc008000,0x40);
  write_volatile_4(0xcc008000,this->field_0x44);
  write_volatile_1(DAT_cc008000,0x10);
  write_volatile_2(0xcc008000,1);
  write_volatile_2(0xcc008000,0x1018);
  write_volatile_4(0xcc008000,this->field_0x40);
  write_volatile_4(0xcc008000,this->field_0x44);
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall J3DShape::setArrayAndBindPipeline(void) const */

void __thiscall J3DShape::setArrayAndBindPipeline(J3DShape *this)

{
  _sCurrentPipeline = (uint)this->mVisFlags >> 2 & 7;
  loadVtxArray(this);
  J3DGraphBase::j3dSys.mpCurDrawPosMtxArr =
       *(MTX34 **)(this->field_0x58 + *(int *)this->field_0x60 * 4);
  gx::GXSetArray(GX_POS_MTX_ARRAY,J3DGraphBase::j3dSys.mpCurDrawPosMtxArr,0x30);
  J3DGraphBase::j3dSys.mpCurDrawNrmMtxArr =
       *(MTX34 **)(this->field_0x5c + *(int *)this->field_0x60 * 4);
  gx::GXSetArray(GX_NRM_MTX_ARRAY,J3DGraphBase::j3dSys.mpCurDrawNrmMtxArr,0x24);
  J3DShapeMtx::sCurrentScaleFlag = (uint)this->field_0x54;
  J3DShapeMtx::sNBTFlag = this->mbHasNBT;
  sEnvelopeFlag = this->mbHasPNMTXIDX;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall J3DShape::drawFast(void) const */

void __thiscall J3DShape::drawFast(J3DShape *this)

{
  ushort uVar1;
  
  if (_sOldVcdVatCmd != this->mpVatVcdCmd) {
    gx::GXCallDisplayList(this->mpVatVcdCmd,0xc0);
    _sOldVcdVatCmd = this->mpVatVcdCmd;
  }
  if ((sEnvelopeFlag != 0) && (this->mbHasPNMTXIDX == false)) {
    write_volatile_1(DAT_cc008000,8);
    write_volatile_1(DAT_cc008000,0x30);
    write_volatile_4(0xcc008000,this->field_0x40);
    write_volatile_1(DAT_cc008000,8);
    write_volatile_1(DAT_cc008000,0x40);
    write_volatile_4(0xcc008000,this->field_0x44);
    write_volatile_1(DAT_cc008000,0x10);
    write_volatile_2(0xcc008000,1);
    write_volatile_2(0xcc008000,0x1018);
    write_volatile_4(0xcc008000,this->field_0x40);
    write_volatile_4(0xcc008000,this->field_0x44);
  }
  setArrayAndBindPipeline(this);
  if ((this->mVisFlags & 0x200U) == 0) {
    for (uVar1 = 0; uVar1 < (ushort)this->mMtxGroupNum; uVar1 = uVar1 + 1) {
      if ((int *)this->mpShapeMtx[uVar1] != (int *)0x0) {
        (**(code **)(*(int *)this->mpShapeMtx[uVar1] + 0x18))();
      }
      if (this->mpShapeDraw[uVar1] != (J3DShapeDraw *)0x0) {
        J3DShapeDraw::draw(this->mpShapeDraw[uVar1]);
      }
    }
  }
  else {
    J3DGraphBase::J3DFifoLoadPosMtxImm((J3DGraphBase::j3dSys.mpCurShapePacket)->mpViewMtx,0);
    J3DGraphBase::J3DFifoLoadNrmMtxImm((J3DGraphBase::j3dSys.mpCurShapePacket)->mpViewMtx,0);
    for (uVar1 = 0; uVar1 < (ushort)this->mMtxGroupNum; uVar1 = uVar1 + 1) {
      if (this->mpShapeDraw[uVar1] != (J3DShapeDraw *)0x0) {
        J3DShapeDraw::draw(this->mpShapeDraw[uVar1]);
      }
    }
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall J3DShape::draw(void) const */

void __thiscall J3DShape::draw(J3DShape *this)

{
  _sOldVcdVatCmd = 0;
  loadPreDrawSetting(this);
  (**(code **)(this->vtbl + 0xc))(this);
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall J3DShape::simpleDraw(void) const */

void __thiscall J3DShape::simpleDraw(J3DShape *this)

{
  ushort uVar1;
  
  _sOldVcdVatCmd = 0;
  loadPreDrawSetting(this);
  _sCurrentPipeline = (uint)this->mVisFlags >> 2 & 7;
  loadVtxArray(this);
  for (uVar1 = 0; uVar1 < (ushort)this->mMtxGroupNum; uVar1 = uVar1 + 1) {
    if (this->mpShapeDraw[uVar1] != (J3DShapeDraw *)0x0) {
      J3DShapeDraw::draw(this->mpShapeDraw[uVar1]);
    }
  }
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall J3DShape::simpleDrawCache(void) const */

void __thiscall J3DShape::simpleDrawCache(J3DShape *this)

{
  ushort uVar1;
  
  if (_sOldVcdVatCmd != this->mpVatVcdCmd) {
    gx::GXCallDisplayList(this->mpVatVcdCmd,0xc0);
    _sOldVcdVatCmd = this->mpVatVcdCmd;
  }
  if ((sEnvelopeFlag != 0) && (this->mbHasPNMTXIDX == false)) {
    write_volatile_1(DAT_cc008000,8);
    write_volatile_1(DAT_cc008000,0x30);
    write_volatile_4(0xcc008000,this->field_0x40);
    write_volatile_1(DAT_cc008000,8);
    write_volatile_1(DAT_cc008000,0x40);
    write_volatile_4(0xcc008000,this->field_0x44);
    write_volatile_1(DAT_cc008000,0x10);
    write_volatile_2(0xcc008000,1);
    write_volatile_2(0xcc008000,0x1018);
    write_volatile_4(0xcc008000,this->field_0x40);
    write_volatile_4(0xcc008000,this->field_0x44);
  }
  loadVtxArray(this);
  for (uVar1 = 0; uVar1 < (ushort)this->mMtxGroupNum; uVar1 = uVar1 + 1) {
    if (this->mpShapeDraw[uVar1] != (J3DShapeDraw *)0x0) {
      J3DShapeDraw::draw(this->mpShapeDraw[uVar1]);
    }
  }
  return;
}

