#include <J3DGraphBase/J3DTevs.h>
#include <gd/GDBase.h>
#include <J3DGraphBase/J3DGD.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <J3DGraphBase/J3DTransform.h>
#include <mtx/mtx.h>
#include <J3DTexMtx.h>
#include <Demangler/J3DLightObj.h>


namespace J3DGraphBase {
undefined1 j3dTexCoordTable;
undefined1 j3dTevSwapTableTable;
undefined1 j3dAlphaCmpTable;
undefined1 j3dZModeTable;
undefined4 dualReg$1374;
undefined1 init$1375;
}

/* __thiscall J3DLightObj::load(unsigned long) const */

void __thiscall J3DLightObj::load(J3DLightObj *this,ulong param_1)

{
  GXLightID lightID;
  _GXColor local_18;
  
  if (*(uint *)(gd::__GDCurrentDL + 0xc) < *(int *)(gd::__GDCurrentDL + 8) + 0x48U) {
    gd::GDOverflowed();
  }
  lightID = 1 << param_1;
  J3DGraphBase::J3DGDSetLightPos
            ((double)(this->mPos).x,(double)(this->mPos).y,(double)(this->mPos).z,lightID);
  J3DGraphBase::J3DGDSetLightAttn
            ((double)(this->mCosAtten).x,(double)(this->mCosAtten).y,(double)(this->mCosAtten).z,
             (double)(this->mDistAtten).x,(double)(this->mDistAtten).y,(double)(this->mDistAtten).z,
             lightID);
  local_18 = this->mColor;
  J3DGraphBase::J3DGDSetLightColor(lightID,&local_18);
  J3DGraphBase::J3DGDSetLightDir
            ((double)(this->mDir).x,(double)(this->mDir).y,(double)(this->mDir).z,lightID);
  return;
}


namespace J3DGraphBase {

/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __stdcall loadTexCoordGens(unsigned long,
                              J3DTexCoord *) */

void loadTexCoordGens(uint param_1,int param_2)

{
  undefined uVar1;
  undefined uVar2;
  undefined4 uVar3;
  undefined *puVar4;
  int iVar5;
  uint uVar6;
  
  if (*(uint *)(gd::__GDCurrentDL + 0xc) < param_1 * 8 + *(int *)(gd::__GDCurrentDL + 8) + 10) {
    gd::GDOverflowed();
  }
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = 0x10;
  iVar5 = (param_1 & 0xff) - 1;
  uVar1 = (undefined)((uint)iVar5 >> 8);
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = uVar1;
  uVar2 = (undefined)iVar5;
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = uVar2;
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = 0x10;
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = 0x40;
  uVar6 = 0;
  iVar5 = 0;
  while( true ) {
    if (param_1 <= uVar6) break;
    J3DGDSetTexCoordGen(*(undefined *)(param_2 + iVar5),((undefined *)(param_2 + iVar5))[1]);
    uVar6 = uVar6 + 1;
    iVar5 = iVar5 + 4;
  }
  if (init_1375 == '\0') {
    dualReg_1374 = 0x3d;
    init_1375 = '\x01';
  }
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = 0x10;
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = uVar1;
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = uVar2;
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = 0x10;
  puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
  *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
  *puVar4 = 0x50;
  if (param_1 != 0) {
    do {
      uVar3 = dualReg_1374;
      uVar6 = (uint)dualReg_1374 >> 0x18;
      puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
      *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
      *puVar4 = (char)uVar6;
      puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
      *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
      *puVar4 = (char)((uint)uVar3 >> 0x10);
      puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
      *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
      *puVar4 = (char)((uint)uVar3 >> 8);
      puVar4 = *(undefined **)(gd::__GDCurrentDL + 8);
      *(undefined **)(gd::__GDCurrentDL + 8) = puVar4 + 1;
      *puVar4 = (char)uVar3;
      param_1 = param_1 - 1;
    } while (param_1 != 0);
  }
  return;
}

}

/* __thiscall J3DTexMtx::calc(void) */

void __thiscall J3DTexMtx::calc(J3DTexMtx *this)

{
  float *pfVar1;
  byte bVar2;
  float fVar3;
  uint uVar4;
  float *pfVar5;
  float *pfVar6;
  int iVar7;
  float local_148;
  float local_144;
  float local_140;
  float local_13c;
  float local_138;
  float local_134;
  float local_130;
  float local_12c;
  float local_128;
  float local_124;
  float local_120;
  float local_11c;
  float local_118;
  float local_114;
  float local_110;
  float local_10c;
  float local_108;
  float local_104;
  float local_100;
  float local_fc;
  float local_f8;
  float local_f4;
  float local_f0;
  float local_ec;
  MTX34 local_e8;
  MTX34 local_b8;
  MTX34 MStack136;
  MTX34 MStack72;
  
  pfVar6 = local_e8.m[2] + 3;
  pfVar5 = (float *)0x80370cb4;
  iVar7 = 6;
  do {
    pfVar1 = pfVar5 + 1;
    pfVar5 = pfVar5 + 2;
    fVar3 = *pfVar5;
    pfVar6[1] = *pfVar1;
    pfVar6 = pfVar6 + 2;
    *pfVar6 = fVar3;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  pfVar6 = &local_ec;
  pfVar5 = (float *)&UNK_80370ce4;
  iVar7 = 6;
  do {
    pfVar1 = pfVar5 + 1;
    pfVar5 = pfVar5 + 2;
    fVar3 = *pfVar5;
    pfVar6[1] = *pfVar1;
    pfVar6 = pfVar6 + 2;
    *pfVar6 = fVar3;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  bVar2 = (this->mInfo).mInfo;
  uVar4 = bVar2 & 0x7f;
  if ((uVar4 - 8 < 2) || (uVar4 == 0xb)) {
    if ((char)bVar2 < '\0') {
      if ((char)bVar2 < '\0') {
        J3DGraphBase::J3DGetTextureMtxMaya(&(this->mInfo).mSRTInfo,&MStack136);
      }
    }
    else {
      local_f4 = (this->mInfo).mCenter.x;
      local_f0 = (this->mInfo).mCenter.y;
      local_ec = (this->mInfo).mCenter.z;
      J3DGraphBase::J3DGetTextureMtx(&(this->mInfo).mSRTInfo,&local_f4,&MStack136);
    }
    mtx::PSMTXConcat(&MStack136,&local_b8,&MStack136);
    J3DGraphBase::J3DMtxProjConcat(&MStack136,&(this->mInfo).mEffectMtx,&MStack72);
    mtx::PSMTXConcat(&MStack72,(MTX34 *)(this + 1),&this->mOutputMatrix);
  }
  else {
    if (uVar4 == 7) {
      if ((char)bVar2 < '\0') {
        if ((char)bVar2 < '\0') {
          J3DGraphBase::J3DGetTextureMtxMaya(&(this->mInfo).mSRTInfo,&MStack72);
        }
      }
      else {
        local_100 = (this->mInfo).mCenter.x;
        local_fc = (this->mInfo).mCenter.y;
        local_f8 = (this->mInfo).mCenter.z;
        J3DGraphBase::J3DGetTextureMtx(&(this->mInfo).mSRTInfo,&local_100,&MStack72);
      }
      mtx::PSMTXConcat(&MStack72,&local_b8,&MStack72);
      mtx::PSMTXConcat(&MStack72,(MTX34 *)(this + 1),&this->mOutputMatrix);
    }
    else {
      if (uVar4 == 10) {
        if ((char)bVar2 < '\0') {
          if ((char)bVar2 < '\0') {
            J3DGraphBase::J3DGetTextureMtxMayaOld(&(this->mInfo).mSRTInfo,&MStack136);
          }
        }
        else {
          local_10c = (this->mInfo).mCenter.x;
          local_108 = (this->mInfo).mCenter.y;
          local_104 = (this->mInfo).mCenter.z;
          J3DGraphBase::J3DGetTextureMtxOld(&(this->mInfo).mSRTInfo,&local_10c,&MStack136);
        }
        mtx::PSMTXConcat(&MStack136,&local_e8,&MStack136);
        J3DGraphBase::J3DMtxProjConcat(&MStack136,&(this->mInfo).mEffectMtx,&MStack72);
        mtx::PSMTXConcat(&MStack72,(MTX34 *)(this + 1),&this->mOutputMatrix);
      }
      else {
        if (uVar4 == 6) {
          if ((char)bVar2 < '\0') {
            if ((char)bVar2 < '\0') {
              J3DGraphBase::J3DGetTextureMtxMayaOld(&(this->mInfo).mSRTInfo,&MStack72);
            }
          }
          else {
            local_118 = (this->mInfo).mCenter.x;
            local_114 = (this->mInfo).mCenter.y;
            local_110 = (this->mInfo).mCenter.z;
            J3DGraphBase::J3DGetTextureMtxOld(&(this->mInfo).mSRTInfo,&local_118,&MStack72);
          }
          mtx::PSMTXConcat(&MStack72,&local_e8,&MStack72);
          mtx::PSMTXConcat(&MStack72,(MTX34 *)(this + 1),&this->mOutputMatrix);
        }
        else {
          if (uVar4 == 1) {
            if ((char)bVar2 < '\0') {
              if ((char)bVar2 < '\0') {
                J3DGraphBase::J3DGetTextureMtxMayaOld(&(this->mInfo).mSRTInfo,&MStack72);
              }
            }
            else {
              local_124 = (this->mInfo).mCenter.x;
              local_120 = (this->mInfo).mCenter.y;
              local_11c = (this->mInfo).mCenter.z;
              J3DGraphBase::J3DGetTextureMtxOld(&(this->mInfo).mSRTInfo,&local_124,&MStack72);
            }
            mtx::PSMTXConcat(&MStack72,(MTX34 *)(this + 1),&this->mOutputMatrix);
          }
          else {
            if ((uVar4 - 2 < 2) || (uVar4 == 5)) {
              if ((char)bVar2 < '\0') {
                if ((char)bVar2 < '\0') {
                  J3DGraphBase::J3DGetTextureMtxMayaOld(&(this->mInfo).mSRTInfo,&MStack136);
                }
              }
              else {
                local_130 = (this->mInfo).mCenter.x;
                local_12c = (this->mInfo).mCenter.y;
                local_128 = (this->mInfo).mCenter.z;
                J3DGraphBase::J3DGetTextureMtxOld(&(this->mInfo).mSRTInfo,&local_130,&MStack136);
              }
              J3DGraphBase::J3DMtxProjConcat(&MStack136,&(this->mInfo).mEffectMtx,&MStack72);
              mtx::PSMTXConcat(&MStack72,(MTX34 *)(this + 1),&this->mOutputMatrix);
            }
            else {
              if (uVar4 == 4) {
                if ((char)bVar2 < '\0') {
                  if ((char)bVar2 < '\0') {
                    J3DGraphBase::J3DGetTextureMtxMayaOld(&(this->mInfo).mSRTInfo,&MStack136);
                  }
                }
                else {
                  local_13c = (this->mInfo).mCenter.x;
                  local_138 = (this->mInfo).mCenter.y;
                  local_134 = (this->mInfo).mCenter.z;
                  J3DGraphBase::J3DGetTextureMtxOld(&(this->mInfo).mSRTInfo,&local_13c,&MStack136);
                }
                J3DGraphBase::J3DMtxProjConcat
                          (&MStack136,&(this->mInfo).mEffectMtx,&this->mOutputMatrix);
              }
              else {
                if ((char)bVar2 < '\0') {
                  if ((char)bVar2 < '\0') {
                    J3DGraphBase::J3DGetTextureMtxMayaOld
                              (&(this->mInfo).mSRTInfo,&this->mOutputMatrix);
                  }
                }
                else {
                  local_148 = (this->mInfo).mCenter.x;
                  local_144 = (this->mInfo).mCenter.y;
                  local_140 = (this->mInfo).mCenter.z;
                  J3DGraphBase::J3DGetTextureMtxOld
                            (&(this->mInfo).mSRTInfo,&local_148,&this->mOutputMatrix);
                }
              }
            }
          }
        }
      }
    }
  }
  return;
}


namespace J3DGraphBase {

/* __stdcall isTexNoReg(void *) */

undefined4 isTexNoReg(int param_1)

{
  if ((0x7f < *(byte *)(param_1 + 1)) && (*(byte *)(param_1 + 1) < 0xbc)) {
    return 1;
  }
  return 0;
}


/* __stdcall getTexNoReg(void *) */

uint getTexNoReg(int param_1)

{
  return *(uint *)(param_1 + 1) & 0xffff;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall loadTexNo(unsigned long,
                       unsigned short const &) */

void loadTexNo(int param_1,ushort *param_2)

{
  int iVar1;
  undefined4 uVar2;
  ResTIMG *pRVar3;
  
  pRVar3 = (j3dSys.mpCurTex)->mpTexData + *param_2;
  *(ushort *)(&::J3DSys::sTexCoordScaleTable + param_1 * 8) = pRVar3->mWidth;
  (&DAT_803edbca)[param_1 * 4] = pRVar3->mHeight;
  if (*(uint *)(gd::__GDCurrentDL + 0xc) < *(int *)(gd::__GDCurrentDL + 8) + 0x14U) {
    gd::GDOverflowed();
  }
  J3DGDSetTexImgPtr(param_1,&pRVar3->mTexFmt + pRVar3->mTexDataOffs);
  J3DGDSetTexImgAttr(param_1,pRVar3->mWidth,pRVar3->mHeight,pRVar3->mTexFmt & GX_CTF_R4);
  J3DGDSetTexLookupMode
            ((double)(0_125 * (float)((double)CONCAT44(0x43300000,
                                                       (int)(char)pRVar3->mMinLOD ^ 0x80000000) -
                                     _1544)),
             (double)(0_125 * (float)((double)CONCAT44(0x43300000,
                                                       (int)(char)pRVar3->mMaxLOD ^ 0x80000000) -
                                     _1544)),
             (double)(0_01 * (float)((double)CONCAT44(0x43300000,(int)pRVar3->mLODBias ^ 0x80000000)
                                    - _1544)),param_1,pRVar3->mWrapS,pRVar3->mWrapT,
             pRVar3->mMinFilter,pRVar3->mMagFilter,pRVar3->mbBiasClamp,pRVar3->mbDoEdgeLOD,
             pRVar3->mMaxAniso);
  if (pRVar3->mbHasTlut == 1) {
    uVar2 = 1;
    if (0x10 < (ushort)pRVar3->mTlutCount) {
      uVar2 = 0x10;
    }
    if (*(uint *)(gd::__GDCurrentDL + 0xc) < *(int *)(gd::__GDCurrentDL + 8) + 0x14U) {
      gd::GDOverflowed();
    }
    iVar1 = param_1 * 0x2000 + 0xf0000;
    J3DGDLoadTlut(&pRVar3->mTexFmt + pRVar3->mTlutDataOffs,iVar1,uVar2);
    J3DGDSetTexTlut(param_1,iVar1,pRVar3->mTlutFmt);
  }
  return;
}


/* __stdcall patchTexNo_PtrToIdx(unsigned long,
                                 unsigned short const &) */

void patchTexNo_PtrToIdx(undefined4 param_1,undefined2 *param_2)

{
  J3DGDSetTexImgPtrRaw(param_1,*param_2);
  return;
}


/* __stdcall loadNBTScale(J3DNBTScale &) */

void loadNBTScale(char *param_1)

{
  if (*param_1 == '\x01') {
    j3dSys.mCurNBTScale.z = (float)(param_1 + 4);
    return;
  }
  j3dSys.mCurNBTScale.z = 0.0;
  return;
}


/* __stdcall makeTexCoordTable(void) */

void makeTexCoordTable(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  undefined4 local_18;
  undefined4 local_14;
  undefined2 local_10;
  undefined local_e;
  
  local_18 = _1570;
  local_14 = DAT_80370e4c;
  local_10 = DAT_80370e50;
  local_e = DAT_80370e52;
  uVar5 = 0;
  iVar2 = 0;
  do {
    uVar6 = 0;
    iVar3 = 0;
    do {
      iVar7 = 0;
      puVar4 = &local_18;
      iVar8 = 0xb;
      do {
        iVar1 = (iVar7 + iVar3 + iVar2) * 3;
        (&j3dTexCoordTable)[iVar1] = (char)uVar5;
        (&DAT_803edc19)[iVar1] = (char)uVar6;
        (&DAT_803edc1a)[iVar1] = *(undefined *)puVar4;
        iVar7 = iVar7 + 1;
        puVar4 = (undefined4 *)((int)puVar4 + 1);
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
      uVar6 = uVar6 + 1;
      iVar3 = iVar3 + 0xb;
    } while (uVar6 < 0x15);
    uVar5 = uVar5 + 1;
    iVar2 = iVar2 + 0xe7;
  } while (uVar5 < 0xb);
  return;
}


/* __stdcall makeAlphaCmpTable(void) */

void makeAlphaCmpTable(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  uVar4 = 0;
  iVar2 = 0;
  do {
    iVar5 = 0;
    iVar3 = 0;
    do {
      iVar6 = 0;
      iVar7 = 8;
      do {
        iVar1 = (iVar6 + iVar2 + iVar3) * 3;
        (&j3dAlphaCmpTable)[iVar1] = (char)uVar4;
        (&DAT_803efde1)[iVar1] = (char)iVar5;
        (&DAT_803efde2)[iVar1] = (char)iVar6;
        iVar6 = iVar6 + 1;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      iVar5 = iVar5 + 1;
      iVar3 = iVar3 + 8;
    } while (iVar5 < 4);
    uVar4 = uVar4 + 1;
    iVar2 = iVar2 + 0x20;
  } while (uVar4 < 8);
  return;
}


/* __stdcall makeZModeTable(void) */

void makeZModeTable(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  iVar4 = 0;
  iVar2 = 0;
  do {
    uVar5 = 0;
    iVar3 = 0;
    do {
      iVar6 = 0;
      iVar7 = 2;
      do {
        iVar1 = (iVar6 + iVar3 + iVar2) * 3;
        (&j3dZModeTable)[iVar1] = (char)iVar4;
        (&DAT_803f00e1)[iVar1] = (char)uVar5;
        (&DAT_803f00e2)[iVar1] = (char)iVar6;
        iVar6 = iVar6 + 1;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      uVar5 = uVar5 + 1;
      iVar3 = iVar3 + 2;
    } while (uVar5 < 8);
    iVar4 = iVar4 + 1;
    iVar2 = iVar2 + 0x10;
  } while (iVar4 < 2);
  return;
}


/* __stdcall makeTevSwapTable(void) */

void makeTevSwapTable(void)

{
  undefined1 *puVar1;
  uint uVar2;
  
  puVar1 = &j3dTevSwapTableTable;
  uVar2 = 0;
  do {
    *puVar1 = (char)((int)uVar2 >> 6);
    puVar1[1] = (byte)(uVar2 >> 4) & 3;
    puVar1[2] = (byte)(uVar2 >> 2) & 3;
    puVar1[3] = (byte)uVar2 & 3;
    uVar2 = uVar2 + 1;
    puVar1 = puVar1 + 4;
  } while ((int)uVar2 < 0x100);
  return;
}

