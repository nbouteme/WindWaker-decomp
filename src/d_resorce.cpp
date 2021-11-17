#include <d_resorce.h>
#include <m_Do_ext.h>
#include <JKernel/JKRHeap.h>
#include <MSL_C.PPCEABI.bare.H/printf.h>
#include <m_Do_dvd_thread.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <JUtility/JUTNameTab.h>
#include <os/OSInterrupt.h>
#include <gd/GDBase.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <JKernel/JKRArchivePub.h>
#include <J3DGraphLoader/J3DModelLoader.h>
#include <d_resorce.h>
#include <J3DGraphAnimator/J3DMaterialAnm.h>
#include <J3DGraphLoader/J3DClusterLoader.h>
#include <J3DGraphLoader/J3DAnmLoader.h>
#include <SComponent/c_bg_s.h>
#include <os/OSCache.h>
#include <JUtility/JUTConsole.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <d_save.h>
#include <dRes_control_c.h>
#include <JKRFileFinder.h>
#include <mDoExt_transAnmBas.h>
#include <J3DAnmBase.h>
#include <dRes_info_c.h>
#include <J3DAnmTransformKey.h>
#include <J3DAnmTransform.h>


namespace d_resorce {
undefined4 mode$4439;
undefined1 init$4440;
undefined4 allocMode$4442;
undefined1 init$4443;
}

/* __thiscall dRes_info_c::dRes_info_c(void) */

void __thiscall dRes_info_c::dRes_info_c(dRes_info_c *this)

{
  this->mRefCount = 0;
  this->mpDvdThdCommand = (mDoDvdThd_mountArchive_c *)0x0;
  this->mpArchive = (JKRArchive *)0x0;
  this->mpParentHeap = (JKRHeap *)0x0;
  this->mpDataHeap = (JKRHeap *)0x0;
  this->mpRes = (undefined *)0x0;
  return;
}


/* __thiscall dRes_info_c::~dRes_info_c(void) */

void __thiscall dRes_info_c::_dRes_info_c(dRes_info_c *this)

{
  mDoDvdThd_mountArchive_c *pmVar1;
  short in_r4;
  
  if (this != (dRes_info_c *)0x0) {
    pmVar1 = this->mpDvdThdCommand;
    if (pmVar1 == (mDoDvdThd_mountArchive_c *)0x0) {
      if (this->mpArchive != (JKRArchive *)0x0) {
        if (this->mpDataHeap != (JKRHeap *)0x0) {
          m_Do_ext::mDoExt_destroySolidHeap();
          this->mpDataHeap = (JKRHeap *)0x0;
        }
        if (this->mpRes != (undefined *)0x0) {
          this->mpRes = (undefined *)0x0;
        }
        (*(code *)((this->mpArchive->parent).parent.vtbl)->unmount)();
        this->mpArchive = (JKRArchive *)0x0;
      }
    }
    else {
      if (pmVar1 != (mDoDvdThd_mountArchive_c *)0x0) {
        (*(code *)((pmVar1->parent).vtbl)->_mDoDvdThd_toMainRam_c)(pmVar1,1);
      }
      this->mpDvdThdCommand = (mDoDvdThd_mountArchive_c *)0x0;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dRes_info_c::set(char const *,
                               char const *,
                               unsigned char,
                               JKRHeap *) */

bool __thiscall
dRes_info_c::set(dRes_info_c *this,char *param_1,char *param_2,uchar param_3,JKRHeap *param_4)

{
  bool bVar1;
  mDoDvdThd_mountArchive_c *pmVar2;
  char name [40];
  
  MSL_C.PPCEABI.bare.H::snprintf(name,0x28,"%s%s.arc",param_2,param_1);
  pmVar2 = (mDoDvdThd_mountArchive_c *)mDoDvdThd_mountArchive_c::create(name,param_3,param_4);
  this->mpDvdThdCommand = pmVar2;
  bVar1 = this->mpDvdThdCommand != (mDoDvdThd_mountArchive_c *)0x0;
  if (bVar1) {
    MSL_C.PPCEABI.bare.H::strncpy(this->mName,param_1,0xe);
  }
  return bVar1;
}


namespace d_resorce {

/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __stdcall setToonTex(J3DModelData *) */

void setToonTex(J3DModelData *pModel)

{
  uint uVar1;
  char *pcVar2;
  ResTIMG *pTexRes;
  ResTIMG *pRVar3;
  int iVar4;
  ushort uVar6;
  undefined4 uVar5;
  ushort uVar8;
  J3DDisplayListObj *pJVar7;
  JUTNameTab *this;
  J3DMaterial *pJVar9;
  J3DTexture *pJVar10;
  J3DTevBlock *pJVar11;
  
  pJVar10 = (pModel->mMaterialTable).mpTexture;
  if ((pJVar10 != (J3DTexture *)0x0) &&
     (this = (pModel->mMaterialTable).mpTexNameTab, this != (JUTNameTab *)0x0)) {
    for (uVar8 = 0; uVar8 < (ushort)pJVar10->mCount; uVar8 = uVar8 + 1) {
      pcVar2 = (char *)JUTNameTab::getName(this,uVar8);
      pTexRes = dDlst_list_c::mToonExImage;
      pRVar3 = dDlst_list_c::mToonImage;
      if (*pcVar2 == 'Z') {
        if (pcVar2[1] == 'A') {
          uVar1 = (uint)uVar8;
          pTexRes = pJVar10->mpTexData + uVar1;
          pTexRes->mTexFmt = dDlst_list_c::mToonImage->mTexFmt;
          pTexRes->mTranslucency = pRVar3->mTranslucency;
          pTexRes->mWidth = pRVar3->mWidth;
          pTexRes->mHeight = pRVar3->mHeight;
          pTexRes->mWrapS = pRVar3->mWrapS;
          pTexRes->mWrapT = pRVar3->mWrapT;
          pTexRes->mbHasTlut = pRVar3->mbHasTlut;
          pTexRes->mTlutFmt = pRVar3->mTlutFmt;
          pTexRes->mTlutCount = pRVar3->mTlutCount;
          pTexRes->mTlutDataOffs = pRVar3->mTlutDataOffs;
          pTexRes->mbMipmapEnabled = pRVar3->mbMipmapEnabled;
          pTexRes->mbDoEdgeLOD = pRVar3->mbDoEdgeLOD;
          pTexRes->mbBiasClamp = pRVar3->mbBiasClamp;
          pTexRes->mMaxAniso = pRVar3->mMaxAniso;
          pTexRes->mMinFilter = pRVar3->mMinFilter;
          pTexRes->mMagFilter = pRVar3->mMagFilter;
          pTexRes->mMinLOD = pRVar3->mMinLOD;
          pTexRes->mMaxLOD = pRVar3->mMaxLOD;
          pTexRes->mMipmapCount = pRVar3->mMipmapCount;
          pTexRes->field_0x19 = pRVar3->field_0x19;
          pTexRes->mLODBias = pRVar3->mLODBias;
          pTexRes->mTexDataOffs = pRVar3->mTexDataOffs;
          pTexRes = pJVar10->mpTexData + uVar1;
          pTexRes->mTexDataOffs = (int)pRVar3 + (pTexRes->mTexDataOffs - (int)pTexRes);
          pTexRes = pJVar10->mpTexData + uVar1;
          pTexRes->mTlutDataOffs = (int)pRVar3 + (pTexRes->mTlutDataOffs - (int)pTexRes);
        }
        else {
          if (pcVar2[1] == 'B') {
            uVar1 = (uint)uVar8;
            pRVar3 = pJVar10->mpTexData + uVar1;
            pRVar3->mTexFmt = dDlst_list_c::mToonExImage->mTexFmt;
            pRVar3->mTranslucency = pTexRes->mTranslucency;
            pRVar3->mWidth = pTexRes->mWidth;
            pRVar3->mHeight = pTexRes->mHeight;
            pRVar3->mWrapS = pTexRes->mWrapS;
            pRVar3->mWrapT = pTexRes->mWrapT;
            pRVar3->mbHasTlut = pTexRes->mbHasTlut;
            pRVar3->mTlutFmt = pTexRes->mTlutFmt;
            pRVar3->mTlutCount = pTexRes->mTlutCount;
            pRVar3->mTlutDataOffs = pTexRes->mTlutDataOffs;
            pRVar3->mbMipmapEnabled = pTexRes->mbMipmapEnabled;
            pRVar3->mbDoEdgeLOD = pTexRes->mbDoEdgeLOD;
            pRVar3->mbBiasClamp = pTexRes->mbBiasClamp;
            pRVar3->mMaxAniso = pTexRes->mMaxAniso;
            pRVar3->mMinFilter = pTexRes->mMinFilter;
            pRVar3->mMagFilter = pTexRes->mMagFilter;
            pRVar3->mMinLOD = pTexRes->mMinLOD;
            pRVar3->mMaxLOD = pTexRes->mMaxLOD;
            pRVar3->mMipmapCount = pTexRes->mMipmapCount;
            pRVar3->field_0x19 = pTexRes->field_0x19;
            pRVar3->mLODBias = pTexRes->mLODBias;
            pRVar3->mTexDataOffs = pTexRes->mTexDataOffs;
            pRVar3 = pJVar10->mpTexData + uVar1;
            pRVar3->mTexDataOffs = (int)pTexRes + (pRVar3->mTexDataOffs - (int)pRVar3);
            pRVar3 = pJVar10->mpTexData + uVar1;
            pRVar3->mTlutDataOffs = (int)pTexRes + (pRVar3->mTlutDataOffs - (int)pRVar3);
          }
        }
      }
    }
    uVar1 = countLeadingZeros(1 - (pModel->mJointTree).mbIsBDL);
    J3DGraphBase::j3dSys.mpCurTex = pJVar10;
    for (uVar8 = 0; uVar8 < (pModel->mMaterialTable).mMaterialCount; uVar8 = uVar8 + 1) {
      pJVar9 = (pModel->mMaterialTable).mpMaterials[uVar8];
      pJVar11 = pJVar9->mpTevBlock;
      if (pJVar11 != (J3DTevBlock *)0x0) {
        iVar4 = (*(code *)pJVar11->vtbl->getTevColor)(pJVar11,3);
        if (iVar4 != 0) {
          uVar6 = (*(code *)pJVar11->vtbl->getTevStageNum)(pJVar11);
          *(ushort *)(iVar4 + 6) = uVar6 & 0xff;
        }
        if ((uVar1 >> 5 & 0xff) != 0) {
          pJVar7 = pJVar9->mpDLObj;
          uVar5 = os::OSDisableInterrupts();
          gd::GDInitGDLObj(&J3DDisplayListObj::sGDLObj,pJVar7->mpData[0],pJVar7->mSize);
          gd::__GDCurrentDL = &J3DDisplayListObj::sGDLObj;
          (*(code *)pJVar11->vtbl->patchTexNoAndTexCoordScale)(pJVar11);
          os::OSRestoreInterrupts(uVar5);
          gd::__GDCurrentDL = (undefined1 *)0x0;
        }
      }
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall setToonTex(J3DMaterialTable *) */

void setToonTex(J3DMaterialTable *pMat)

{
  uint uVar1;
  char *pcVar2;
  ResTIMG *pMdlTex;
  _GXColorS10 *pColor;
  ushort uVar3;
  JUTNameTab *this;
  J3DTevBlock *pTev;
  J3DTexture *pJVar4;
  ushort i;
  ResTIMG *pToonImage;
  
  pJVar4 = pMat->mpTexture;
  if ((pJVar4 != (J3DTexture *)0x0) && (this = pMat->mpTexNameTab, this != (JUTNameTab *)0x0)) {
    for (i = 0; i < (ushort)pJVar4->mCount; i = i + 1) {
      pcVar2 = (char *)JUTNameTab::getName(this,i);
      pMdlTex = dDlst_list_c::mToonExImage;
      pToonImage = dDlst_list_c::mToonImage;
      if (*pcVar2 == 'Z') {
        if (pcVar2[1] == 'A') {
          uVar1 = (uint)i;
          pMdlTex = pJVar4->mpTexData + uVar1;
          pMdlTex->mTexFmt = dDlst_list_c::mToonImage->mTexFmt;
          pMdlTex->mTranslucency = pToonImage->mTranslucency;
          pMdlTex->mWidth = pToonImage->mWidth;
          pMdlTex->mHeight = pToonImage->mHeight;
          pMdlTex->mWrapS = pToonImage->mWrapS;
          pMdlTex->mWrapT = pToonImage->mWrapT;
          pMdlTex->mbHasTlut = pToonImage->mbHasTlut;
          pMdlTex->mTlutFmt = pToonImage->mTlutFmt;
          pMdlTex->mTlutCount = pToonImage->mTlutCount;
          pMdlTex->mTlutDataOffs = pToonImage->mTlutDataOffs;
          pMdlTex->mbMipmapEnabled = pToonImage->mbMipmapEnabled;
          pMdlTex->mbDoEdgeLOD = pToonImage->mbDoEdgeLOD;
          pMdlTex->mbBiasClamp = pToonImage->mbBiasClamp;
          pMdlTex->mMaxAniso = pToonImage->mMaxAniso;
          pMdlTex->mMinFilter = pToonImage->mMinFilter;
          pMdlTex->mMagFilter = pToonImage->mMagFilter;
          pMdlTex->mMinLOD = pToonImage->mMinLOD;
          pMdlTex->mMaxLOD = pToonImage->mMaxLOD;
          pMdlTex->mMipmapCount = pToonImage->mMipmapCount;
          pMdlTex->field_0x19 = pToonImage->field_0x19;
          pMdlTex->mLODBias = pToonImage->mLODBias;
          pMdlTex->mTexDataOffs = pToonImage->mTexDataOffs;
          pMdlTex = pJVar4->mpTexData + uVar1;
          pMdlTex->mTexDataOffs = (int)pToonImage + (pMdlTex->mTexDataOffs - (int)pMdlTex);
          pMdlTex = pJVar4->mpTexData + uVar1;
          pMdlTex->mTlutDataOffs = (int)pToonImage + (pMdlTex->mTlutDataOffs - (int)pMdlTex);
        }
        else {
          if (pcVar2[1] == 'B') {
            uVar1 = (uint)i;
            pToonImage = pJVar4->mpTexData + uVar1;
            pToonImage->mTexFmt = dDlst_list_c::mToonExImage->mTexFmt;
            pToonImage->mTranslucency = pMdlTex->mTranslucency;
            pToonImage->mWidth = pMdlTex->mWidth;
            pToonImage->mHeight = pMdlTex->mHeight;
            pToonImage->mWrapS = pMdlTex->mWrapS;
            pToonImage->mWrapT = pMdlTex->mWrapT;
            pToonImage->mbHasTlut = pMdlTex->mbHasTlut;
            pToonImage->mTlutFmt = pMdlTex->mTlutFmt;
            pToonImage->mTlutCount = pMdlTex->mTlutCount;
            pToonImage->mTlutDataOffs = pMdlTex->mTlutDataOffs;
            pToonImage->mbMipmapEnabled = pMdlTex->mbMipmapEnabled;
            pToonImage->mbDoEdgeLOD = pMdlTex->mbDoEdgeLOD;
            pToonImage->mbBiasClamp = pMdlTex->mbBiasClamp;
            pToonImage->mMaxAniso = pMdlTex->mMaxAniso;
            pToonImage->mMinFilter = pMdlTex->mMinFilter;
            pToonImage->mMagFilter = pMdlTex->mMagFilter;
            pToonImage->mMinLOD = pMdlTex->mMinLOD;
            pToonImage->mMaxLOD = pMdlTex->mMaxLOD;
            pToonImage->mMipmapCount = pMdlTex->mMipmapCount;
            pToonImage->field_0x19 = pMdlTex->field_0x19;
            pToonImage->mLODBias = pMdlTex->mLODBias;
            pToonImage->mTexDataOffs = pMdlTex->mTexDataOffs;
            pToonImage = pJVar4->mpTexData + uVar1;
            pToonImage->mTexDataOffs = (int)pMdlTex + (pToonImage->mTexDataOffs - (int)pToonImage);
            pToonImage = pJVar4->mpTexData + uVar1;
            pToonImage->mTlutDataOffs = (int)pMdlTex + (pToonImage->mTlutDataOffs - (int)pToonImage)
            ;
          }
        }
      }
    }
    for (i = 0; i < pMat->mMaterialCount; i = i + 1) {
      pTev = pMat->mpMaterials[i]->mpTevBlock;
      if ((pTev != (J3DTevBlock *)0x0) &&
         (pColor = (_GXColorS10 *)(*(code *)pTev->vtbl->getTevColor)(pTev,3),
         pColor != (_GXColorS10 *)0x0)) {
        uVar3 = (*(code *)pTev->vtbl->getTevStageNum)(pTev);
        pColor->a = uVar3 & 0xff;
      }
    }
  }
  return;
}

}

/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* __thiscall dRes_info_c::loadResource(void) */

undefined4 __thiscall dRes_info_c::loadResource(dRes_info_c *this)

{
  char *pcVar1;
  ulong uVar2;
  undefined *puVar3;
  undefined4 uVar4;
  int iVar5;
  char **ppcVar6;
  J3DMaterialAnm *pJVar7;
  mDoExt_transAnmBas *pAnm;
  void *pRes;
  void *pvVar8;
  ulong pWhich;
  ushort uVar10;
  int *piVar9;
  int iVar11;
  J3DMaterial *pJVar12;
  uint uVar13;
  
  if (this->mpRes != (undefined *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_resorce.cpp",0x25f,"mRes == 0");
    m_Do_printf::OSPanic("d_resorce.cpp",0x25f,&DAT_80352119);
  }
  iVar11 = this->mpArchive->mpDataHeader->mFileEntryCount;
  puVar3 = (undefined *)JKernel::operator_new__(iVar11 << 2);
  this->mpRes = puVar3;
  if (this->mpRes == (undefined *)0x0) {
    m_Do_printf::OSReport_Error("<%s.arc> setRes: res pointer buffer nothing !!\n",this);
    uVar4 = 0xffffffff;
  }
  else {
    iVar5 = 0;
    if (0 < iVar11) {
      do {
        *(undefined4 *)(this->mpRes + iVar5) = 0;
        iVar5 = iVar5 + 4;
        iVar11 = iVar11 + -1;
      } while (iVar11 != 0);
    }
    pcVar1 = d_resorce::l_readResType_4166;
    uVar13 = 0;
    do {
      ppcVar6 = (char **)JKRArchive::getFirstResource(this->mpArchive,*(ulong *)pcVar1);
      while (*(char *)(ppcVar6 + 4) != '\0') {
        pRes = (void *)JKRArchive::getGlbResource(*(ulong *)pcVar1,*ppcVar6,this->mpArchive);
        if ((J3DModelData *)pRes == (J3DModelData *)0x0) {
          m_Do_printf::OSReport_Error("<%s> res == NULL !!\n",*ppcVar6);
        }
        else {
          uVar2 = *(ulong *)pcVar1;
          pWhich = uVar2 + 0xbdb30000;
          if (pWhich == 0x4420) {
            pRes = (void *)J3DModelLoaderDataBase::load(pRes,0x51240020);
            if ((J3DModelData *)pRes == (J3DModelData *)0x0) {
              return 0xffffffff;
            }
            d_resorce::setToonTex((J3DModelData *)pRes);
          }
          else {
            if (pWhich == 0x444d) {
              pRes = (void *)J3DModelLoaderDataBase::load(pRes,0x51240020);
              if ((J3DModelData *)pRes == (J3DModelData *)0x0) {
                return 0xffffffff;
              }
              for (uVar10 = 0; uVar10 < ((J3DMaterialTable *)((int)pRes + 0x58))->mMaterialCount;
                  uVar10 = uVar10 + 1) {
                pJVar12 = ((J3DMaterialTable *)((int)pRes + 0x58))->mpMaterials[uVar10];
                (**(code **)(pJVar12->vtbl + 0x28))(pJVar12);
                pJVar7 = (J3DMaterialAnm *)JKernel::operator_new(0x6c);
                if (pJVar7 == (J3DMaterialAnm *)0x0) {
                  return 0xffffffff;
                }
                pJVar7->vtbl = (undefined *)&J3DMaterialAnm::__vt;
                J3DMaterialAnm::initialize(pJVar7);
                pJVar12->mpMaterialAnm = pJVar7;
              }
              d_resorce::setToonTex((J3DModelData *)pRes);
            }
            else {
              if (pWhich == 0x4443) {
                pRes = (void *)J3DModelLoaderDataBase::load(pRes,0x51240020);
                if ((J3DModelData *)pRes == (J3DModelData *)0x0) {
                  return 0xffffffff;
                }
                for (uVar10 = 0; uVar10 < ((J3DMaterialTable *)((int)pRes + 0x58))->mMaterialCount;
                    uVar10 = uVar10 + 1) {
                  (**(code **)(((J3DMaterialTable *)((int)pRes + 0x58))->mpMaterials[uVar10]->vtbl +
                              0x28))();
                }
                d_resorce::setToonTex((J3DModelData *)pRes);
              }
              else {
                if (pWhich == 0x4453) {
                  pRes = (void *)J3DModelLoaderDataBase::load(pRes,0x220020);
                  if ((J3DModelData *)pRes == (J3DModelData *)0x0) {
                    return 0xffffffff;
                  }
                  for (uVar10 = 0; uVar10 < ((J3DMaterialTable *)((int)pRes + 0x58))->mMaterialCount
                      ; uVar10 = uVar10 + 1) {
                    pJVar12 = ((J3DMaterialTable *)((int)pRes + 0x58))->mpMaterials[uVar10];
                    (**(code **)(pJVar12->vtbl + 0x28))(pJVar12);
                    pJVar7 = (J3DMaterialAnm *)JKernel::operator_new(0x6c);
                    if (pJVar7 == (J3DMaterialAnm *)0x0) {
                      return 0xffffffff;
                    }
                    pJVar7->vtbl = (undefined *)&J3DMaterialAnm::__vt;
                    J3DMaterialAnm::initialize(pJVar7);
                    pJVar12->mpMaterialAnm = pJVar7;
                  }
                  d_resorce::setToonTex((J3DModelData *)pRes);
                }
                else {
                  if (uVar2 == 0x42534d44) {
                    pRes = (void *)J3DModelLoaderDataBase::load(pRes,0x1020020);
                    if ((J3DModelData *)pRes == (J3DModelData *)0x0) {
                      return 0xffffffff;
                    }
                    for (uVar10 = 0;
                        uVar10 < ((J3DMaterialTable *)((int)pRes + 0x58))->mMaterialCount;
                        uVar10 = uVar10 + 1) {
                      pJVar12 = ((J3DMaterialTable *)((int)pRes + 0x58))->mpMaterials[uVar10];
                      pJVar7 = (J3DMaterialAnm *)JKernel::operator_new(0x6c);
                      if (pJVar7 == (J3DMaterialAnm *)0x0) {
                        return 0xffffffff;
                      }
                      pJVar7->vtbl = (undefined *)&J3DMaterialAnm::__vt;
                      J3DMaterialAnm::initialize(pJVar7);
                      pJVar12->mpMaterialAnm = pJVar7;
                    }
                    d_resorce::setToonTex((J3DModelData *)pRes);
                  }
                  else {
                    if (uVar2 == 0x42444c20) {
                      pRes = (void *)J3DModelLoaderDataBase::loadBinaryDisplayList(pRes,0x2020);
                      if ((J3DModelData *)pRes == (J3DModelData *)0x0) {
                        return 0xffffffff;
                      }
                      d_resorce::setToonTex((J3DModelData *)pRes);
                    }
                    else {
                      if (uVar2 == 0x42444c4c) {
                        pRes = (void *)J3DModelLoaderDataBase::loadBinaryDisplayList(pRes,0x1020);
                        if ((J3DModelData *)pRes == (J3DModelData *)0x0) {
                          return 0xffffffff;
                        }
                      }
                      else {
                        if (uVar2 == 0x42444c4d) {
                          pRes = (void *)J3DModelLoaderDataBase::loadBinaryDisplayList(pRes,0x2020);
                          if ((J3DModelData *)pRes == (J3DModelData *)0x0) {
                            return 0xffffffff;
                          }
                          for (uVar10 = 0;
                              uVar10 < ((J3DMaterialTable *)((int)pRes + 0x58))->mMaterialCount;
                              uVar10 = uVar10 + 1) {
                            pJVar12 = ((J3DMaterialTable *)((int)pRes + 0x58))->mpMaterials[uVar10];
                            pJVar7 = (J3DMaterialAnm *)JKernel::operator_new(0x6c);
                            if (pJVar7 == (J3DMaterialAnm *)0x0) {
                              return 0xffffffff;
                            }
                            pJVar7->vtbl = (undefined *)&J3DMaterialAnm::__vt;
                            J3DMaterialAnm::initialize(pJVar7);
                            pJVar12->mpMaterialAnm = pJVar7;
                          }
                          d_resorce::setToonTex((J3DModelData *)pRes);
                        }
                        else {
                          if (uVar2 == 0x42444c49) {
                            pRes = (void *)J3DModelLoaderDataBase::loadBinaryDisplayList
                                                     (pRes,0x1002020);
                            if ((J3DModelData *)pRes == (J3DModelData *)0x0) {
                              return 0xffffffff;
                            }
                            for (uVar10 = 0;
                                uVar10 < ((J3DMaterialTable *)((int)pRes + 0x58))->mMaterialCount;
                                uVar10 = uVar10 + 1) {
                              pJVar12 = ((J3DMaterialTable *)((int)pRes + 0x58))->mpMaterials
                                        [uVar10];
                              pJVar7 = (J3DMaterialAnm *)JKernel::operator_new(0x6c);
                              if (pJVar7 == (J3DMaterialAnm *)0x0) {
                                return 0xffffffff;
                              }
                              pJVar7->vtbl = (undefined *)&J3DMaterialAnm::__vt;
                              J3DMaterialAnm::initialize(pJVar7);
                              pJVar12->mpMaterialAnm = pJVar7;
                            }
                            d_resorce::setToonTex((J3DModelData *)pRes);
                          }
                          else {
                            if (uVar2 == 0x42444c43) {
                              pRes = (void *)J3DModelLoaderDataBase::loadBinaryDisplayList
                                                       (pRes,0x2020);
                              if ((J3DModelData *)pRes == (J3DModelData *)0x0) {
                                return 0xffffffff;
                              }
                              d_resorce::setToonTex((J3DModelData *)pRes);
                            }
                            else {
                              pvVar8 = (void *)(uVar2 + 0xbdb40000);
                              if (pvVar8 == (void *)0x5320) {
                                pRes = (void *)J3DClusterLoaderDataBase::load
                                                         ((J3DClusterLoaderDataBase *)pRes,
                                                          (void *)0x5320);
                                if ((J3DModelData *)pRes == (J3DModelData *)0x0) {
                                  return 0xffffffff;
                                }
                              }
                              else {
                                if ((uVar2 == 0x42434b53) || (uVar2 == 0x42434b20)) {
                                  puVar3 = (undefined *)
                                           ((J3DJointTree *)((int)pRes + 0x10))->mbIsBDL;
                                  if (puVar3 == &DAT_ffffffff) {
                                    puVar3 = (undefined *)0x0;
                                  }
                                  else {
                                    puVar3 = (undefined *)((int)(undefined **)pRes + (int)puVar3);
                                  }
                                  pAnm = (mDoExt_transAnmBas *)JKernel::operator_new(0x30);
                                  if (pAnm == (mDoExt_transAnmBas *)0x0) {
                                    return 0xffffffff;
                                  }
                                  (pAnm->parent).parent.parent.vtbl = (undefined *)&J3DAnmBase::__vt
                                  ;
                                  (pAnm->parent).parent.parent.mCurrentTime = d_resorce::_4408;
                                  (pAnm->parent).parent.parent.mDuration = 0;
                                  (pAnm->parent).parent.parent.vtbl =
                                       (undefined *)&J3DAnmTransform::__vt;
                                  *(undefined4 *)&(pAnm->parent).parent.field_0x10 = 0;
                                  *(undefined4 *)&(pAnm->parent).parent.field_0x14 = 0;
                                  *(undefined4 *)&(pAnm->parent).parent.field_0x18 = 0;
                                  *(undefined4 *)&(pAnm->parent).parent.field_0xc = 0;
                                  (pAnm->parent).parent.parent.vtbl =
                                       (undefined *)&J3DAnmTransformKey::__vt;
                                  *(undefined4 *)&(pAnm->parent).field_0x24 = 0;
                                  *(undefined4 *)&(pAnm->parent).field_0x28 = 0;
                                  (pAnm->parent).parent.parent.vtbl =
                                       (undefined *)&mDoExt_transAnmBas::__vt;
                                  (pAnm->parent).field_0x2c = puVar3;
                                  J3DAnmLoaderDataBase::setResource
                                            ((J3DAnmLoaderDataBase *)pAnm,(J3DAnmBase *)pRes,
                                             (void *)pWhich);
                                  pRes = pAnm;
                                }
                                else {
                                  if ((((uVar2 == 0x42545020) || (uVar2 == 0x42544b20)) ||
                                      (uVar2 == 0x42504b20)) ||
                                     (((uVar2 == 0x42524b20 || (pvVar8 == (void *)0x4b20)) ||
                                      (uVar2 == 0x42564120)))) {
                                    pRes = (void *)J3DAnmLoaderDataBase::load(pRes);
                                    if ((J3DModelData *)pRes == (J3DModelData *)0x0) {
                                      return 0xffffffff;
                                    }
                                  }
                                  else {
                                    if (pWhich == 0x5420) {
                                      pRes = (void *)J3DModelLoaderDataBase::loadMaterialTable
                                                               ((J3DModelLoaderDataBase *)pRes,
                                                                pvVar8);
                                      if ((J3DModelData *)pRes == (J3DModelData *)0x0) {
                                        return 0xffffffff;
                                      }
                                      for (uVar10 = 0; uVar10 < *(ushort *)((int)pRes + 4);
                                          uVar10 = uVar10 + 1) {
                                        (**(code **)(**(int **)(*(int *)((int)pRes + 8) +
                                                               (uint)uVar10 * 4) + 0x28))();
                                      }
                                      d_resorce::setToonTex((J3DMaterialTable *)pRes);
                                    }
                                    else {
                                      if (pWhich == 0x544d) {
                                        pRes = (void *)J3DModelLoaderDataBase::loadMaterialTable
                                                                 ((J3DModelLoaderDataBase *)pRes,
                                                                  pvVar8);
                                        if ((J3DModelData *)pRes == (J3DModelData *)0x0) {
                                          return 0xffffffff;
                                        }
                                        for (uVar10 = 0; uVar10 < *(ushort *)((int)pRes + 4);
                                            uVar10 = uVar10 + 1) {
                                          piVar9 = *(int **)(*(int *)((int)pRes + 8) +
                                                            (uint)uVar10 * 4);
                                          (**(code **)(*piVar9 + 0x28))(piVar9);
                                          pJVar7 = (J3DMaterialAnm *)JKernel::operator_new(0x6c);
                                          if (pJVar7 == (J3DMaterialAnm *)0x0) {
                                            return 0xffffffff;
                                          }
                                          pJVar7->vtbl = (undefined *)&J3DMaterialAnm::__vt;
                                          J3DMaterialAnm::initialize(pJVar7);
                                          piVar9[0xf] = (int)pJVar7;
                                        }
                                        d_resorce::setToonTex((J3DMaterialTable *)pRes);
                                      }
                                      else {
                                        if (uVar2 == 0x445a4220) {
                                          pRes = cBgS::ConvDzb((cBgD_t *)pRes);
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
        *(void **)(this->mpRes + (int)ppcVar6[1] * 4) = pRes;
        (**(code **)(ppcVar6[3] + 0xc))(ppcVar6);
      }
      if (ppcVar6 != (char **)0x0) {
        (**(code **)(ppcVar6[3] + 8))(ppcVar6,1);
      }
      uVar13 = uVar13 + 1;
      pcVar1 = (char *)((int)pcVar1 + 4);
    } while (uVar13 < 0x1d);
    uVar4 = 0;
  }
  return uVar4;
}


/* __thiscall JKRFileFinder::~JKRFileFinder(void) */

void __thiscall JKRFileFinder::_JKRFileFinder(JKRFileFinder *this)

{
  short in_r4;
  
  if ((this != (JKRFileFinder *)0x0) &&
     (*(char **)(this + 0xc) = d_resorce::l_readResType_4166 + 0x74, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall J3DAnmTransformKey::~J3DAnmTransformKey(void) */

void __thiscall J3DAnmTransformKey::_J3DAnmTransformKey(J3DAnmTransformKey *this)

{
  bool bVar1;
  short in_r4;
  
  bVar1 = this != (J3DAnmTransformKey *)0x0;
  if (bVar1) {
    (this->parent).parent.vtbl = (undefined *)&__vt;
    if ((bVar1) && ((this->parent).parent.vtbl = (undefined *)&J3DAnmTransform::__vt, bVar1)) {
      (this->parent).parent.vtbl = (undefined *)&J3DAnmBase::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DAnmTransform::~J3DAnmTransform(void) */

void __thiscall J3DAnmTransform::_J3DAnmTransform(J3DAnmTransform *this)

{
  short in_r4;
  
  if (this != (J3DAnmTransform *)0x0) {
    (this->parent).vtbl = (undefined *)&__vt;
    if (this != (J3DAnmTransform *)0x0) {
      (this->parent).vtbl = (undefined *)&J3DAnmBase::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DAnmBase::~J3DAnmBase(void) */

void __thiscall J3DAnmBase::_J3DAnmBase(J3DAnmBase *this)

{
  short in_r4;
  
  if ((this != (J3DAnmBase *)0x0) && (this->vtbl = (undefined *)&__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* WARNING: Removing unreachable block (ram,0x8006eb34) */
/* WARNING: Removing unreachable block (ram,0x8006eb50) */
/* WARNING: Removing unreachable block (ram,0x8006eb84) */
/* WARNING: Removing unreachable block (ram,0x8006eb5c) */
/* WARNING: Removing unreachable block (ram,0x8006eb88) */
/* WARNING: Removing unreachable block (ram,0x8006eac0) */
/* WARNING: Removing unreachable block (ram,0x8006eb1c) */
/* WARNING: Removing unreachable block (ram,0x8006eae8) */
/* __thiscall dRes_info_c::setRes(void) */

undefined4 __thiscall dRes_info_c::setRes(dRes_info_c *this)

{
  undefined4 uVar1;
  mDoDvdThd_mountArchive_c *pmVar2;
  JKRSolidHeap *pJVar3;
  ulong uVar4;
  JKRExpHeap *pJVar5;
  undefined in_r6;
  
  if (this->mpArchive == (JKRArchive *)0x0) {
    pmVar2 = this->mpDvdThdCommand;
    if (pmVar2 == (mDoDvdThd_mountArchive_c *)0x0) {
      return 0xffffffff;
    }
    if ((pmVar2->parent).mStatus == 0) {
      return 1;
    }
    this->mpArchive = &pmVar2->mpResult->parent;
    this->mpParentHeap = this->mpDvdThdCommand->mpHeap;
    pmVar2 = this->mpDvdThdCommand;
    if (pmVar2 != (mDoDvdThd_mountArchive_c *)0x0) {
      (*(code *)((pmVar2->parent).vtbl)->_mDoDvdThd_toMainRam_c)(pmVar2,1);
    }
    this->mpDvdThdCommand = (mDoDvdThd_mountArchive_c *)0x0;
    if (this->mpArchive == (JKRArchive *)0x0) {
      m_Do_printf::OSReport_Error("<%s.arc> setRes: archive mount error !!\n",this);
      return 0xffffffff;
    }
    if (this->mpParentHeap == (JKRHeap *)0x0) {
      pJVar3 = m_Do_ext::mDoExt_createSolidHeapFromGameToCurrent(0,0);
      this->mpDataHeap = &pJVar3->parent;
      if (this->mpDataHeap == (JKRHeap *)0x0) {
        m_Do_printf::OSReport_Error("<%s.arc> mDMCommandsetRes: can\'t alloc memory\n",this);
        return 0xffffffff;
      }
      loadResource(this);
      m_Do_ext::mDoExt_restoreCurrentHeap();
      if (d_resorce::init_4440 == '\0') {
        d_resorce::mode_4439 = 1;
        d_resorce::init_4440 = '\x01';
      }
      if (d_resorce::init_4443 == '\0') {
        d_resorce::allocMode_4442 = 1;
        d_resorce::init_4443 = '\x01';
      }
      uVar1 = d_resorce::allocMode_4442;
      pJVar5 = m_Do_ext::mDoExt_getGameHeap();
      pJVar5->field_0x6c = (byte)uVar1;
      d_resorce::mode_4439 = 2;
      m_Do_ext::mDoExt_adjustSolidHeap((JKRSolidHeap *)this->mpDataHeap);
      pJVar5 = m_Do_ext::mDoExt_getGameHeap();
      pJVar5->field_0x6c = 0;
    }
    else {
      pJVar3 = m_Do_ext::mDoExt_createSolidHeapToCurrent(0,this->mpParentHeap,0x20,in_r6);
      this->mpDataHeap = &pJVar3->parent;
      if (this->mpDataHeap == (JKRHeap *)0x0) {
        uVar4 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar4,"d_resorce.cpp",0x3f5,"mDataHeap != 0");
        m_Do_printf::OSPanic("d_resorce.cpp",0x3f5,&DAT_80352119);
      }
      loadResource(this);
      m_Do_ext::mDoExt_restoreCurrentHeap();
      m_Do_ext::mDoExt_adjustSolidHeap((JKRSolidHeap *)this->mpDataHeap);
    }
    os::DCStoreRangeNoSync(this->mpDataHeap->mpDataBegin,this->mpDataHeap->mSize);
  }
  return 0;
}


namespace d_resorce {

/* __stdcall getArcHeader(JKRArchive *) */

JKRArchive__Header * getArcHeader(JKRArchive *param_1)

{
  if ((param_1 != (JKRArchive *)0x0) && (param_1->mMountMode == Mem)) {
    return param_1->mpHeader;
  }
  return (JKRArchive__Header *)0x0;
}

}

/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall dRes_info_c::dump_long(dRes_info_c *,
                                     int) */

void __thiscall dRes_info_c::dump_long(dRes_info_c *this,int param_1)

{
  short sVar1;
  int heapSize;
  JKRHeap *this_00;
  int size;
  undefined4 pArcHeader;
  int no;
  JKRArchive *pArc;
  JKRHeap *pCmd;
  
  pCmd = (JKRHeap *)param_1;
  JUtility::JUTReportConsole_f("dRes_info_c::dump %08x %d\n",this);
  JUtility::JUTReportConsole_f
            ("No Command  Archive  ArcHeader(size) SolidHeap(size) Resource Count ArchiveName\n");
  for (no = 0; no < param_1; no = no + 1) {
    sVar1 = this->mRefCount;
    if (sVar1 != 0) {
      heapSize = JKRHeap::getSize(this->mpDataHeap,(void *)0x0,pCmd);
      this_00 = (JKRHeap *)d_resorce::getArcHeader(this->mpArchive);
      size = JKRHeap::getSize(this_00,(void *)0x0,pCmd);
      pArc = this->mpArchive;
      pCmd = (JKRHeap *)this->mpDvdThdCommand;
      pArcHeader = d_resorce::getArcHeader(pArc);
      JUtility::JUTReportConsole_f
                ("%2d %08x %08x %08x(%5x) %08x(%5x) %08x %3d   %s\n",no,pCmd,pArc,pArcHeader,size,
                 this->mpDataHeap,heapSize,this->mpRes,sVar1,this);
    }
    this = this + 1;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall dRes_info_c::dump(dRes_info_c *,
                                int) */

void __thiscall dRes_info_c::dump(dRes_info_c *this,int param_1)

{
  JKRHeap *pJVar1;
  uint uVar2;
  JKRHeap *pJVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  pJVar3 = (JKRHeap *)param_1;
  JUtility::JUTReportConsole_f("dRes_info_c::dump %08x %d\n",this);
  JUtility::JUTReportConsole_f("No ArchiveSize(KB) SolidHeapSize(KB) Cnt ArchiveName\n");
  uVar6 = 0;
  uVar5 = 0;
  for (iVar4 = 0; iVar4 < param_1; iVar4 = iVar4 + 1) {
    if (this->mRefCount != 0) {
      pJVar1 = (JKRHeap *)d_resorce::getArcHeader(this->mpArchive);
      pJVar1 = (JKRHeap *)JKRHeap::getSize(pJVar1,(void *)0x0,pJVar3);
      uVar2 = JKRHeap::getSize(this->mpDataHeap,(void *)0x0,pJVar3);
      pJVar3 = pJVar1;
      JUtility::JUTReportConsole_f
                ((double)((float)((double)CONCAT44(0x43300000,(uint)pJVar1 ^ 0x80000000) -
                                 d_resorce::_4513) * d_resorce::_4560),
                 (double)((float)((double)CONCAT44(0x43300000,uVar2 ^ 0x80000000) - d_resorce::_4513
                                 ) * d_resorce::_4560),"%2d %6.1f %6x %6.1f %6x %3d %s\n",iVar4,
                 pJVar1,uVar2,this->mRefCount,this);
      uVar6 = (int)&pJVar1->vtbl + uVar6;
      uVar5 = uVar5 + uVar2;
    }
    this = this + 1;
  }
  JUtility::JUTReportConsole_f
            ((double)((float)((double)CONCAT44(0x43300000,uVar6 ^ 0x80000000) - d_resorce::_4513) *
                     d_resorce::_4560),
             (double)((float)((double)CONCAT44(0x43300000,uVar5 ^ 0x80000000) - d_resorce::_4513) *
                     d_resorce::_4560),
             "----------------------------------------------\n   %6.1f %6x %6.1f %6x   Total\n\n",
             uVar6,uVar5);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dRes_control_c::~dRes_control_c(void) */

void __thiscall dRes_control_c::_dRes_control_c(dRes_control_c *this)

{
  short in_r4;
  int iVar1;
  int iVar2;
  
  if (this != (dRes_control_c *)0x0) {
    iVar1 = 0;
    iVar2 = 0;
    do {
      dRes_info_c::_dRes_info_c((dRes_info_c *)(this->mObjectInfo[0].mName + iVar2));
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x24;
    } while (iVar1 < 0x40);
    iVar1 = 0;
    iVar2 = 0;
    do {
      dRes_info_c::_dRes_info_c((dRes_info_c *)(this->mStageInfo[0].mName + iVar2));
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x24;
    } while (iVar1 < 0x40);
    Runtime.PPCEABI.H::__destroy_arr(this->mStageInfo,dRes_info_c::_dRes_info_c,0x24,0x40);
    Runtime.PPCEABI.H::__destroy_arr(this,dRes_info_c::_dRes_info_c,0x24,0x40);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


namespace dRes_control_c {

/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* __thiscall setRes(char const *,
                                     dRes_info_c *,
                                     int,
                                     char const *,
                                     unsigned char,
                                     JKRHeap *) */

void setRes
               (char *param_1,dRes_info_c *param_2,int param_3,char *param_4,byte param_5,
               JKRHeap *param_6)

{
  dRes_info_c *this;
  int iVar1;
  
  this = getResInfo(param_1,param_2,param_3);
  if (this == (dRes_info_c *)0x0) {
    this = newResInfo(param_2,param_3);
    if (this == (dRes_info_c *)0x0) {
      m_Do_printf::OSReport_Error
                ("<%s.arc> setRes: 空きリソース情報ポインタがありません\n"
                 ,param_1);
      dRes_info_c::_dRes_info_c((dRes_info_c *)0x0);
      return;
    }
    iVar1 = dRes_info_c::set(this,param_1,param_4,param_5,param_6);
    if (iVar1 == 0) {
      m_Do_printf::OSReport_Error
                ("<%s.arc> setRes: res info set error !!\n",param_1);
      dRes_info_c::_dRes_info_c(this);
      return;
    }
  }
  this->mRefCount = this->mRefCount + 1;
  return;
}


/* __thiscall syncRes(char const *,
                                      dRes_info_c *,
                                      int) */

undefined4 syncRes(char *param_1,dRes_info_c *param_2,int param_3)

{
  dRes_info_c *pInf;
  undefined4 uVar1;
  
  pInf = getResInfo(param_1,param_2,param_3);
  if (pInf == (dRes_info_c *)0x0) {
    m_Do_printf::OSReport_Error("<%s.arc> syncRes: リソース未登録!!\n",param_1);
    uVar1 = 1;
  }
  else {
    uVar1 = dRes_info_c::setRes(pInf);
  }
  return uVar1;
}


/* __thiscall deleteRes(char const *,
                                        dRes_info_c *,
                                        int) */

undefined4 deleteRes(char *pName,dRes_info_c *pResInfoList,int count)

{
  short sVar1;
  dRes_info_c *this;
  undefined4 uVar2;
  
  this = getResInfo(pName,pResInfoList,count);
  if (this == (dRes_info_c *)0x0) {
    m_Do_printf::OSReport_Error
              ("<%s.arc> deleteRes: res nothing !!\n(未登録のリソースを削除してるのを発見しました！修正してください。)\n"
               ,pName);
    uVar2 = 0;
  }
  else {
    sVar1 = this->mRefCount + -1;
    this->mRefCount = sVar1;
    if (sVar1 == 0) {
      dRes_info_c::_dRes_info_c(this);
    }
    uVar2 = 1;
  }
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall getResInfo(char const *,
                                         dRes_info_c *,
                                         int) */

dRes_info_c * getResInfo(char *pArcName,dRes_info_c *pResInfoList,int count)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    if (count <= iVar2) {
      return (dRes_info_c *)0x0;
    }
    if ((pResInfoList->mRefCount != 0) &&
       (iVar1 = MSL_C.PPCEABI.bare.H::strcmp(pArcName,pResInfoList->mName), iVar1 == 0)) break;
    pResInfoList = pResInfoList + 1;
    iVar2 = iVar2 + 1;
  }
  return pResInfoList;
}


/* __thiscall newResInfo(dRes_info_c *,
                                         int) */

dRes_info_c * newResInfo(dRes_info_c *param_1,int param_2)

{
  if (0 < param_2) {
    do {
      if (param_1->mRefCount == 0) {
        return param_1;
      }
      param_1 = param_1 + 1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return (dRes_info_c *)0x0;
}


/* __thiscall getResInfoLoaded(char const *,
                                               dRes_info_c *,
                                               int) */

dRes_info_c *
getResInfoLoaded(char *arcName,dRes_info_c *resInfosList,int totalResInfos)

{
  dRes_info_c *pdVar1;
  
  pdVar1 = getResInfo(arcName,resInfosList,totalResInfos);
  if (pdVar1 == (dRes_info_c *)0x0) {
    m_Do_printf::OSReport_Error("<%s.arc> getRes: res nothing !!\n",arcName);
    pdVar1 = (dRes_info_c *)0x0;
  }
  else {
    if (pdVar1->mpArchive == (JKRArchive *)0x0) {
      m_Do_printf::OSReport_Error("<%s.arc> getRes: res during reading !!\n",arcName);
      pdVar1 = (dRes_info_c *)0x0;
    }
  }
  return pdVar1;
}


/* __thiscall getRes(char const *,
                                     long,
                                     dRes_info_c *,
                                     int) */

void * getRes
                 (char *arcName,long fileIndex,dRes_info_c *resInfosList,int totalResInfos)

{
  dRes_info_c *pRes;
  
  pRes = getResInfoLoaded(arcName,resInfosList,totalResInfos);
  if (pRes != (dRes_info_c *)0x0) {
    if (fileIndex < pRes->mpArchive->mpDataHeader->mFileEntryCount) {
      pRes = *(dRes_info_c **)(pRes->mpRes + fileIndex * 4);
    }
    else {
      m_Do_printf::OSReport_Error
                ("<%s.arc> getRes: res index over !! index=%d count=%d\n",arcName,fileIndex);
      pRes = (dRes_info_c *)0x0;
    }
  }
  return pRes;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall getRes(char const *,
                                     char const *,
                                     dRes_info_c *,
                                     int) */

void * getRes(char *param_1,char *param_2,dRes_info_c *param_3,int param_4)

{
  dRes_info_c *pdVar1;
  int iVar2;
  ulong uVar3;
  int iVar4;
  int iVar5;
  SDirEntry aSStack40 [4];
  char *local_24;
  
  pdVar1 = getResInfoLoaded(param_1,param_3,param_4);
  if (pdVar1 != (dRes_info_c *)0x0) {
    iVar4 = pdVar1->mpArchive->mpDataHeader->mFileEntryCount;
    iVar5 = 0;
    for (uVar3 = 0; (int)uVar3 < iVar4; uVar3 = uVar3 + 1) {
      if (*(int *)(pdVar1->mpRes + iVar5) != 0) {
        JKRArchive::getDirEntry(pdVar1->mpArchive,aSStack40,uVar3);
        iVar2 = MSL_C.PPCEABI.bare.H::strcmp(param_2,local_24);
        if (iVar2 == 0) {
          return *(dRes_info_c **)(pdVar1->mpRes + iVar5);
        }
      }
      iVar5 = iVar5 + 4;
    }
    pdVar1 = (dRes_info_c *)0x0;
  }
  return pdVar1;
}


/* __thiscall getIDRes(char const *,
                                       unsigned short,
                                       dRes_info_c *,
                                       int) */

void * getIDRes(char *param_1,ushort param_2,dRes_info_c *param_3,int param_4)

{
  dRes_info_c *pdVar1;
  int iVar2;
  undefined2 in_register_00000010;
  
  pdVar1 = getResInfoLoaded(param_1,param_3,param_4);
  if (pdVar1 != (dRes_info_c *)0x0) {
    iVar2 = m_Do_ext::mDoExt_resIDToIndex(pdVar1->mpArchive,CONCAT22(in_register_00000010,param_2));
    if (iVar2 < 0) {
      pdVar1 = (dRes_info_c *)0x0;
    }
    else {
      pdVar1 = *(dRes_info_c **)(pdVar1->mpRes + iVar2 * 4);
    }
  }
  return pdVar1;
}

}

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dRes_control_c::syncAllRes(dRes_info_c *,
                                         int) */

undefined4 __thiscall
dRes_control_c::syncAllRes(dRes_control_c *this,dRes_info_c *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    if ((int)param_1 <= iVar2) {
      return 0;
    }
    if ((this->mObjectInfo[0].mpDvdThdCommand != (mDoDvdThd_mountArchive_c *)0x0) &&
       (iVar1 = dRes_info_c::setRes(this->mObjectInfo), 0 < iVar1)) break;
    this = (dRes_control_c *)(this->mObjectInfo + 1);
    iVar2 = iVar2 + 1;
  }
  return 1;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dRes_control_c::setStageRes(char const *,
                                          JKRHeap *) */

void __thiscall dRes_control_c::setStageRes(dRes_control_c *this,char *param_1,JKRHeap *param_2)

{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  char acStack56 [36];
  
  bVar1 = false;
  pcVar3 = (char *)0x803c9d3c;
  iVar2 = MSL_C.PPCEABI.bare.H::strcmp
                    (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurStage.mStageName,"ma2room");
  if ((iVar2 == 0) &&
     (iVar2 = dSv_event_c::isEventBit
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x1820),
     iVar2 != 0)) {
    bVar1 = true;
  }
  if (bVar1) {
    pcVar3 = "ma3room";
  }
  MSL_C.PPCEABI.bare.H::snprintf(acStack56,0x14,"/res/Stage/%s/",pcVar3);
  setRes(param_1,this->mStageInfo,0x40,acStack56,1,param_2);
  return;
}


/* __thiscall dRes_control_c::dump(void) */

void __thiscall dRes_control_c::dump(dRes_control_c *this)

{
  JUtility::JUTReportConsole_f("\ndRes_control_c::dump mObjectInfo\n");
  dRes_info_c::dump(this->mObjectInfo,0x40);
  dRes_info_c::dump_long(this->mObjectInfo,0x40);
  JUtility::JUTReportConsole_f("\ndRes_control_c::dump mStageInfo\n");
  dRes_info_c::dump(this->mStageInfo,0x40);
  dRes_info_c::dump_long(this->mStageInfo,0x40);
  return;
}


/* __thiscall mDoExt_transAnmBas::~mDoExt_transAnmBas(void) */

void __thiscall mDoExt_transAnmBas::_mDoExt_transAnmBas(mDoExt_transAnmBas *this)

{
  bool bVar1;
  short in_r4;
  
  bVar1 = this != (mDoExt_transAnmBas *)0x0;
  if (bVar1) {
    (this->parent).parent.parent.vtbl = (undefined *)&__vt;
    if (((bVar1) &&
        ((this->parent).parent.parent.vtbl = (undefined *)&J3DAnmTransformKey::__vt, bVar1)) &&
       ((this->parent).parent.parent.vtbl = (undefined *)&J3DAnmTransform::__vt, bVar1)) {
      (this->parent).parent.parent.vtbl = (undefined *)&J3DAnmBase::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DAnmTransformKey::getTransform(unsigned short,
                                               J3DTransformInfo *) const */

void __thiscall
J3DAnmTransformKey::getTransform(J3DAnmTransformKey *this,ushort param_1,J3DTransformInfo *param_2)

{
  (**(code **)((this->parent).parent.vtbl + 0x10))((double)(this->parent).parent.mCurrentTime);
  return;
}

