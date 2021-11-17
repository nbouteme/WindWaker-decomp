#include <JPADraw/JPADrawSetupTev.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <gx/GXTev.h>
#include <gx/GXBump.h>
#include <gx/GXAttr.h>
#include <JPADrawSetupTev.h>


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall JPADrawSetupTev::setupTev(JPABaseShape *,
                                        JPAExTexShape *) */

void __thiscall
JPADrawSetupTev::setupTev(JPADrawSetupTev *this,JPABaseShapeArc *pSHP1,JPAExTexShapeArc *pEXT1)

{
  GXTevColorArg *pGVar1;
  GXTevAlphaArg *pGVar2;
  int iVar3;
  float (*pafVar4) [6];
  undefined4 uVar5;
  GXTevStageID GVar6;
  GXTexCoordID GVar7;
  
  this->mNumTexGen = 1;
  this->mNumTevStage = 1;
  this->mNumIndStage = 0;
  pGVar1 = (GXTevColorArg *)(*(code *)pSHP1->vtbl->getTevColorArg)(pSHP1);
  pGVar2 = (GXTevAlphaArg *)(*(code *)pSHP1->vtbl->getTevAlphaArg)(pSHP1);
  gx::GXSetTevColorIn(GX_TEVSTAGE0,*pGVar1,pGVar1[1],pGVar1[2],pGVar1[3]);
  gx::GXSetTevAlphaIn(GX_TEVSTAGE0,*pGVar2,pGVar2[1],pGVar2[2],pGVar2[3]);
  gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD0,GX_TEXMAP0,GX_COLOR_NULL);
  if (pEXT1 != (JPAExTexShapeArc *)0x0) {
    GVar6 = GX_TEVSTAGE1;
    GVar7 = GX_TEXCOORD1;
    iVar3 = (**(code **)(*(int *)pEXT1 + 0xc))(pEXT1);
    if (iVar3 == 2) {
      gx::GXSetIndTexOrder(0,1,5);
      gx::GXSetIndTexCoordScale(0,0,0);
      iVar3 = (**(code **)(*(int *)pEXT1 + 0x18))(pEXT1);
      pafVar4 = (float (*) [6])(**(code **)(*(int *)pEXT1 + 0x14))(pEXT1);
      gx::GXSetIndTexMtx(GX_ITM_0,pafVar4,iVar3);
      uVar5 = (**(code **)(*(int *)pEXT1 + 0x10))(pEXT1);
      gx::GXSetTevIndirect(1,0,0,7,uVar5,0,0,0,0,0);
      gx::GXSetTevOrder(GX_TEVSTAGE1,GX_TEXCOORD2,GX_TEXMAP6,GX_COLOR_NULL);
      gx::GXSetTevColorIn(GX_TEVSTAGE1,GX_CC_ZERO,GX_CC_TEXC,GX_CC_CPREV,GX_CC_TEXA);
      gx::GXSetTevAlphaIn(GX_TEVSTAGE1,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_APREV);
      gx::GXSetTevColorOp(GX_TEVSTAGE1,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
      gx::GXSetTevAlphaOp(GX_TEVSTAGE1,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
      this->mNumTevStage = this->mNumTevStage + 1;
      this->mNumTexGen = this->mNumTexGen + 2;
      this->mNumIndStage = this->mNumIndStage + 1;
      GVar6 = GX_TEVSTAGE2;
      GVar7 = GX_TEXCOORD3;
    }
    else {
      if ((iVar3 < 2) && (0 < iVar3)) {
        gx::GXSetIndTexOrder(0,1,5);
        gx::GXSetIndTexCoordScale(0,0,0);
        iVar3 = (**(code **)(*(int *)pEXT1 + 0x18))(pEXT1);
        pafVar4 = (float (*) [6])(**(code **)(*(int *)pEXT1 + 0x14))(pEXT1);
        gx::GXSetIndTexMtx(GX_ITM_0,pafVar4,iVar3);
        uVar5 = (**(code **)(*(int *)pEXT1 + 0x10))(pEXT1);
        gx::GXSetTevIndirect(0,0,0,7,uVar5,0,0,0,0,0);
        this->mNumIndStage = this->mNumIndStage + 1;
        this->mNumTexGen = this->mNumTexGen + 1;
        GVar7 = GX_TEXCOORD2;
      }
    }
    iVar3 = (**(code **)(*(int *)pEXT1 + 0x24))(pEXT1);
    if (iVar3 != 0) {
      gx::GXSetTevOrder(GVar6,GVar7,GX_TEXMAP7,GX_COLOR_NULL);
      gx::GXSetTevColorIn(GVar6,GX_CC_ZERO,GX_CC_TEXC,GX_CC_CPREV,GX_CC_ZERO);
      gx::GXSetTevAlphaIn(GVar6,GX_CA_ZERO,GX_CA_TEXA,GX_CA_APREV,GX_CA_ZERO);
      gx::GXSetTevColorOp(GVar6,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
      gx::GXSetTevAlphaOp(GVar6,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
      this->mNumTevStage = this->mNumTevStage + 1;
      this->mNumTexGen = this->mNumTexGen + 1;
    }
  }
  gx::GXSetNumTexGens((uint)this->mNumTexGen);
  gx::GXSetNumTevStages(this->mNumTevStage);
  gx::GXSetNumIndStages((uint)this->mNumIndStage);
  return;
}

