#include <J2DGraph/J2DScreen.h>
#include <J2DGraph/J2DPane.h>
#include <JKernel/JKRHeap.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JKernel/JKRFileLoader.h>
#include <JSupport/JSUMemoryStream.h>
#include <J2DGraph/J2DScreen.h>
#include <JSupport/JSUInputStream.h>
#include <J2DGraph/J2DWindow.h>
#include <J2DGraph/J2DPicture.h>
#include <J2DGraph/J2DTextBox.h>
#include <JUtility/JUTAssert.h>
#include <J2DGraph/J2DGrafContext.h>
#include <J2DGraph/J2DOrthoGraph.h>
#include <gx/GXTev.h>
#include <gx/GXAttr.h>
#include <gx/GXGeometry.h>
#include <J2DScreen.h>


/* __thiscall J2DScreen::~J2DScreen(void) */

void __thiscall J2DScreen::_J2DScreen(J2DScreen *this,short flag)

{
  if (this != (J2DScreen *)0x0) {
    (this->parent).vtbl = (J2DPane__vtable *)&__vt;
    J2DPane::_J2DPane(&this->parent,0);
    if (0 < flag) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall J2DScreen::set(char const *,
                             JKRArchive *) */

undefined4 __thiscall J2DScreen::set(J2DScreen *this,char *param_1,JKRArchive *param_2)

{
  void *pvVar1;
  long lVar2;
  undefined4 uVar3;
  undefined1 *local_28;
  undefined local_24;
  
  pvVar1 = (void *)JKRFileLoader::getGlbResource(param_1,&param_2->parent);
  if (pvVar1 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    lVar2 = (*(code *)((param_2->parent).parent.vtbl)->getExpandedResSize)(param_2,pvVar1);
    local_24 = 0;
    local_28 = &JSUMemoryInputStream::__vt;
    JSUMemoryInputStream::setBuffer((JSUMemoryInputStream *)&local_28,pvVar1,lVar2);
    uVar3 = set(this,(JSURandomInputStream *)&local_28);
    local_28 = &JSURandomInputStream::__vt;
    JSUInputStream::_JSUInputStream((JSUInputStream *)&local_28);
  }
  return uVar3;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall J2DScreen::makeHierarchyPanes(J2DPane *,
                                            JSURandomInputStream *) */

int __thiscall
J2DScreen::makeHierarchyPanes(J2DScreen *this,J2DPane *param_1,JSURandomInputStream *param_2)

{
  int iVar1;
  J2DPane *pJVar2;
  int local_28;
  long local_24;
  
  pJVar2 = param_1;
  do {
    while( true ) {
      JSURandomInputStream::peek(param_2,&local_28,8);
      if (local_28 == 0x454e4431) {
        JSURandomInputStream::seek(param_2,local_24,1);
        return 0;
      }
      if (local_28 < 0x454e4431) break;
      if (local_28 == 0x45585431) {
        JSURandomInputStream::seek(param_2,local_24,1);
        return 1;
      }
LAB_802d0afc:
      pJVar2 = (J2DPane *)
               (*(code *)(this->parent).vtbl[1].field_0x0)(this,&local_28,param_2,param_1);
      if (pJVar2 == (J2DPane *)0x0) {
        return 2;
      }
    }
    if (local_28 != 0x42474e31) goto LAB_802d0afc;
    JSURandomInputStream::seek(param_2,local_24,1);
    iVar1 = makeHierarchyPanes(this,pJVar2,param_2);
    if (iVar1 != 0) {
      return iVar1;
    }
  } while( true );
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall J2DScreen::createPane(J2DPane::J2DScrnBlockHeader const &,
                                    JSURandomInputStream *,
                                    J2DPane *) */

J2DPicture * __thiscall
J2DScreen::createPane
          (J2DScreen *this,J2DScrnBlockHeader *pHeader,JSURandomInputStream *pStream,J2DPane *pPane)

{
  ulong uVar1;
  int iVar2;
  J2DPicture *pJVar3;
  int iVar4;
  
  iVar4 = pHeader->mMagic;
  if (iVar4 == 0x54425831) {
    pJVar3 = (J2DPicture *)JKernel::operator_new(0x100);
    if (pJVar3 == (J2DPicture *)0x0) {
      return (J2DPicture *)0x0;
    }
    J2DTextBox::J2DTextBox((J2DTextBox *)pJVar3,pPane,pStream);
    return pJVar3;
  }
  if (iVar4 < 0x54425831) {
    if (iVar4 == 0x50494331) {
      pJVar3 = (J2DPicture *)JKernel::operator_new(0x124);
      if (pJVar3 == (J2DPicture *)0x0) {
        return (J2DPicture *)0x0;
      }
      J2DPicture::J2DPicture(pJVar3,pPane,pStream);
      return pJVar3;
    }
    if ((iVar4 < 0x50494331) && (iVar4 == 0x50414e31)) {
      pJVar3 = (J2DPicture *)JKernel::operator_new(0xcc);
      if (pJVar3 == (J2DPicture *)0x0) {
        return (J2DPicture *)0x0;
      }
      J2DPane::J2DPane((J2DPane *)pJVar3,pPane,pStream);
      return pJVar3;
    }
  }
  else {
    if (iVar4 == 0x57494e31) {
      pJVar3 = (J2DPicture *)JKernel::operator_new(0x114);
      if (pJVar3 == (J2DPicture *)0x0) {
        return (J2DPicture *)0x0;
      }
      J2DWindow::J2DWindow((J2DWindow *)pJVar3,pPane,pStream);
      return pJVar3;
    }
  }
  uVar1 = JUTAssertion::getSDevice();
  JUTAssertion::setWarningMessage_f(uVar1,"J2DScreen.cpp",0x9f,"%s",(___)"unknown pane");
  iVar2 = (**(code **)(*(int *)pStream + 0x1c))(pStream);
  iVar4 = pHeader[1].mMagic;
  pJVar3 = (J2DPicture *)JKernel::operator_new(0xcc);
  if (pJVar3 != (J2DPicture *)0x0) {
    J2DPane::J2DPane((J2DPane *)pJVar3,pPane,pStream);
  }
  JSURandomInputStream::seek(pStream,iVar4 + iVar2,0);
  return pJVar3;
}


/* __thiscall J2DScreen::set(JSURandomInputStream *) */

uint __thiscall J2DScreen::set(J2DScreen *this,JSURandomInputStream *param_1)

{
  char cVar3;
  uint uVar1;
  int iVar2;
  
  cVar3 = checkSignature(this,param_1);
  if (cVar3 == '\0') {
    uVar1 = 0;
  }
  else {
    cVar3 = getScreenInformation(this,param_1);
    if (cVar3 == '\0') {
      uVar1 = 0;
    }
    else {
      iVar2 = makeHierarchyPanes(this,&this->parent,param_1);
      if (iVar2 == 2) {
        uVar1 = 0;
      }
      else {
        uVar1 = countLeadingZeros((uint)(byte)param_1[4]);
        uVar1 = uVar1 >> 5;
      }
    }
  }
  return uVar1;
}


/* __thiscall J2DScreen::checkSignature(JSURandomInputStream *) */

undefined4 __thiscall J2DScreen::checkSignature(J2DScreen *this,JSURandomInputStream *param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  int header [2];
  
  JSUInputStream::read((JSUInputStream *)param_1,header,0x20);
  if ((header[0] == 0x5343524e) && (header[1] == 0x626c6f31)) {
    uVar2 = 1;
  }
  else {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::setWarningMessage_f
              (uVar1,"J2DScreen.cpp",0xd9,"%s",(___)"SCRN resource is broken.\n");
    uVar2 = 0;
  }
  return uVar2;
}


/* WARNING: Could not reconcile some variable overlaps */
/* __thiscall J2DScreen::getScreenInformation(JSURandomInputStream *) */

undefined4 __thiscall J2DScreen::getScreenInformation(J2DScreen *this,JSURandomInputStream *param_1)

{
  double dVar1;
  double dVar2;
  float fVar3;
  ulong uVar4;
  undefined4 uVar5;
  u8 local_48;
  u8 uStack71;
  u8 uStack70;
  u8 uStack69;
  char data [16];
  
  JSUInputStream::read((JSUInputStream *)param_1,data,0x10);
  fVar3 = J2DGraph::0_0;
  if (data._0_4_ == 0x494e4631) {
    dVar1 = (double)CONCAT44(0x43300000,(uint)data._8_2_) - J2DGraph::_650;
    dVar2 = (double)CONCAT44(0x43300000,(uint)data._10_2_) - J2DGraph::_650;
    (this->parent).mPosTL.x = J2DGraph::0_0;
    (this->parent).mPosTL.y = fVar3;
    (this->parent).mPosBR.x = (float)dVar1;
    (this->parent).mPosBR.y = (float)dVar2;
    (*(code *)((this->parent).vtbl)->calcMtx)(this);
    local_48 = (u8)((uint)data._12_4_ >> 0x18);
    (this->field_0xd0).r = local_48;
    uStack71 = (u8)((uint)data._12_4_ >> 0x10);
    (this->field_0xd0).g = uStack71;
    uStack70 = (u8)((uint)data._12_4_ >> 8);
    (this->field_0xd0).b = uStack70;
    uStack69 = (u8)data._12_4_;
    (this->field_0xd0).a = uStack69;
    if (0x10 < data._4_4_) {
      (**(code **)(*(int *)param_1 + 0x10))(param_1,data._4_4_ - 0x10);
    }
    uVar5 = 1;
  }
  else {
    uVar4 = JUTAssertion::getSDevice();
    JUTAssertion::setWarningMessage_f
              (uVar4,"J2DScreen.cpp",0xf2,"%s",(___)"SCRN resource is broken.\n");
    uVar5 = 0;
  }
  return uVar5;
}


/* WARNING: Removing unreachable block (ram,0x802d112c) */
/* WARNING: Removing unreachable block (ram,0x802d1134) */
/* __thiscall J2DScreen::draw(float,
                              float,
                              J2DGrafContext const *) */

void __thiscall J2DScreen::draw(J2DScreen *this,float x,float y,J2DGrafContext *pCtx)

{
  float *pfVar1;
  float fVar2;
  float *pfVar3;
  float *pfVar4;
  int iVar5;
  undefined4 uVar6;
  double dVar7;
  double dVar8;
  undefined8 in_f30;
  undefined8 in_f31;
  J2DOrthoGraph local_1b8;
  J2DGrafContext local_e4;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar8 = (double)y;
  dVar7 = (double)x;
  uVar6 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  if (pCtx == (J2DGrafContext *)0x0) {
    J2DOrthoGraph::J2DOrthoGraph
              (&local_1b8,J2DGraph::0_0,J2DGraph::0_0,J2DGraph::_693,J2DGraph::_694,J2DGraph::_695,
               J2DGraph::_696);
    J2DOrthoGraph::setPort(&local_1b8);
    J2DPane::draw(&this->parent,(float)dVar7,(float)dVar8,&local_1b8.parent,
                  (bool)this->mbClipToParent);
    J2DGrafContext::setScissor(&local_1b8.parent);
    local_1b8.parent.vtbl = (J2DGrafContext__vtable *)&J2DGrafContext::__vt;
  }
  else {
    local_e4.vtbl = (J2DGrafContext__vtable *)&J2DGrafContext::__vt;
    local_e4.mViewport.mTL.x = (pCtx->mViewport).mTL.x;
    local_e4.mViewport.mTL.y = (pCtx->mViewport).mTL.y;
    local_e4.mViewport.mBR.x = (pCtx->mViewport).mBR.x;
    local_e4.mViewport.mBR.y = (pCtx->mViewport).mBR.y;
    local_e4.mScissor.mTL.x = (pCtx->mScissor).mTL.x;
    local_e4.mScissor.mTL.y = (pCtx->mScissor).mTL.y;
    local_e4.mScissor.mBR.x = (pCtx->mScissor).mBR.x;
    local_e4.mScissor.mBR.y = (pCtx->mScissor).mBR.y;
    local_e4.mColorTL = pCtx->mColorTL;
    local_e4.mColorTR = pCtx->mColorTR;
    local_e4.mColorBR = pCtx->mColorBR;
    local_e4.mColorBL = pCtx->mColorBL;
    local_e4.mLineWidth = pCtx->mLineWidth;
    local_e4.mLastPoint.x = (pCtx->mLastPoint).x;
    local_e4.mLastPoint.y = (pCtx->mLastPoint).y;
    pfVar4 = &local_e4.mLastPoint.y;
    pfVar3 = &(pCtx->mLastPoint).y;
    iVar5 = 8;
    do {
      pfVar1 = pfVar3 + 1;
      pfVar3 = pfVar3 + 2;
      fVar2 = *pfVar3;
      pfVar4[1] = *pfVar1;
      pfVar4 = pfVar4 + 2;
      *pfVar4 = fVar2;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    pfVar4 = local_e4.mProj.m[3] + 3;
    pfVar3 = (pCtx->mProj).m[3] + 3;
    iVar5 = 6;
    do {
      pfVar1 = pfVar3 + 1;
      pfVar3 = pfVar3 + 2;
      fVar2 = *pfVar3;
      pfVar4[1] = *pfVar1;
      pfVar4 = pfVar4 + 2;
      *pfVar4 = fVar2;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    local_e4._176_2_ = *(undefined2 *)&pCtx->field_0xb0;
    local_e4.field_0xb2 = pCtx->field_0xb2;
    local_e4._179_2_ = *(undefined2 *)&pCtx->mLineBlendMode;
    local_e4.mLineBlendDst = pCtx->mLineBlendDst;
    local_e4._182_2_ = *(undefined2 *)&pCtx->mBoxBlendMode;
    local_e4.mBoxBlendDst = pCtx->mBoxBlendDst;
    J2DPane::draw(&this->parent,x,y,pCtx,(bool)this->mbClipToParent);
    J2DGrafContext::setScissor(&local_e4);
    local_e4.vtbl = (J2DGrafContext__vtable *)&J2DGrafContext::__vt;
  }
  gx::GXSetNumTevStages(1);
  gx::GXSetTevOp(0,4);
  gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR0A0);
  gx::GXSetVtxDesc(GX_VA_TEX0,GX_NONE);
  gx::GXSetCullMode(0);
  gx::GXSetNumTexGens(0);
  __psq_l0(auStack8,uVar6);
  __psq_l1(auStack8,uVar6);
  __psq_l0(auStack24,uVar6);
  __psq_l1(auStack24,uVar6);
  return;
}


/* __thiscall J2DScreen::search(unsigned long) */

undefined4 __thiscall J2DScreen::search(J2DScreen *this,ulong param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = J2DPane::search(&this->parent,param_1);
  }
  return uVar1;
}

