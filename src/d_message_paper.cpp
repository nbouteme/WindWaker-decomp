#include <d_message_paper.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <JUtility/JUTNameTab.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <m_Do_ext.h>
#include <J3DGraphLoader/J3DModelLoader.h>
#include <J3DGraphLoader/J3DAnmLoader.h>
#include <JKernel/JKRHeap.h>
#include <JKernel/JKRArchivePub.h>
#include <os/OSCache.h>
#include <d_message_paper.h>
#include <mtx/mtx.h>
#include <m_Do_mtx.h>
#include <MSL_C.PPCEABI.bare.H/printf.h>
#include <J2DGraph/J2DTextBox.h>
#include <f_op_msg_mng.h>
#include <d_drawlist.h>
#include <MSL_C.PPCEABI.bare.H/arith.h>
#include <d_kankyo.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <JKernel/JKRFileLoader.h>
#include <J2DGraph/J2DScreen.h>
#include <J2DGraph/J2DPane.h>
#include <J2DGraph/J2DPicture.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <dDlst_2DMSG3_c.h>
#include <dmsg3_3d_c.h>


namespace d_message_paper {
}

namespace d_message_paper {
undefined4 sScreen3;
undefined4 bbutton_icon3;
undefined4 bbutton_kage3;
undefined2 bbuttonTimer3;
undefined4 board;
undefined4 msg3d;
undefined4 dMsg3_popSpeed;
undefined4 message;
}

/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall dmsg3_3d_c::setDummyTexture(void) */

void __thiscall dmsg3_3d_c::setDummyTexture(dmsg3_3d_c *this)

{
  uint uVar1;
  ResTIMG *pRVar2;
  ulong uVar3;
  char *__s1;
  int iVar4;
  ResTIMG *pRVar5;
  ushort uVar6;
  JUTNameTab *this_00;
  J3DTexture *pJVar7;
  J3DModelData *pJVar8;
  
  pJVar8 = *(J3DModelData **)(*(int *)(this + 0x30) + 4);
  pJVar7 = (pJVar8->mMaterialTable).mpTexture;
  this_00 = (pJVar8->mMaterialTable).mpTexNameTab;
  if (pJVar7 == (J3DTexture *)0x0) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"d_message_paper.cpp",0x92,"texture != 0");
    m_Do_printf::OSPanic("d_message_paper.cpp",0x92,"Halt");
  }
  if (this_00 == (JUTNameTab *)0x0) {
    uVar3 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar3,"d_message_paper.cpp",0x93,"textureName != 0");
    m_Do_printf::OSPanic("d_message_paper.cpp",0x93,"Halt");
  }
  for (uVar6 = 0; uVar6 < (ushort)pJVar7->mCount; uVar6 = uVar6 + 1) {
    __s1 = (char *)JUTNameTab::getName(this_00,uVar6);
    iVar4 = MSL_C.PPCEABI.bare.H::strcmp(__s1,"0_black");
    pRVar2 = mDoGph_gInf_c::mFrameBufferTimg;
    if (iVar4 == 0) {
      uVar1 = (uint)uVar6;
      pRVar5 = pJVar7->mpTexData + uVar1;
      pRVar5->mTexFmt = mDoGph_gInf_c::mFrameBufferTimg->mTexFmt;
      pRVar5->mTranslucency = pRVar2->mTranslucency;
      pRVar5->mWidth = pRVar2->mWidth;
      pRVar5->mHeight = pRVar2->mHeight;
      pRVar5->mWrapS = pRVar2->mWrapS;
      pRVar5->mWrapT = pRVar2->mWrapT;
      pRVar5->mbHasTlut = pRVar2->mbHasTlut;
      pRVar5->mTlutFmt = pRVar2->mTlutFmt;
      pRVar5->mTlutCount = pRVar2->mTlutCount;
      pRVar5->mTlutDataOffs = pRVar2->mTlutDataOffs;
      pRVar5->mbMipmapEnabled = pRVar2->mbMipmapEnabled;
      pRVar5->mbDoEdgeLOD = pRVar2->mbDoEdgeLOD;
      pRVar5->mbBiasClamp = pRVar2->mbBiasClamp;
      pRVar5->mMaxAniso = pRVar2->mMaxAniso;
      pRVar5->mMinFilter = pRVar2->mMinFilter;
      pRVar5->mMagFilter = pRVar2->mMagFilter;
      pRVar5->mMinLOD = pRVar2->mMinLOD;
      pRVar5->mMaxLOD = pRVar2->mMaxLOD;
      pRVar5->mMipmapCount = pRVar2->mMipmapCount;
      pRVar5->field_0x19 = pRVar2->field_0x19;
      pRVar5->mLODBias = pRVar2->mLODBias;
      pRVar5->mTexDataOffs = pRVar2->mTexDataOffs;
      pRVar5 = pJVar7->mpTexData + uVar1;
      pRVar5->mTexDataOffs = (int)pRVar2 + (pRVar5->mTexDataOffs - (int)pRVar5);
      pRVar5 = pJVar7->mpTexData + uVar1;
      pRVar5->mTlutDataOffs = (int)pRVar2 + (pRVar5->mTlutDataOffs - (int)pRVar5);
    }
    else {
      iVar4 = MSL_C.PPCEABI.bare.H::strcmp(__s1,"1_black");
      pRVar2 = mDoGph_gInf_c::mFrameBufferTimg;
      if (iVar4 == 0) {
        uVar1 = (uint)uVar6;
        pRVar5 = pJVar7->mpTexData + uVar1;
        pRVar5->mTexFmt = mDoGph_gInf_c::mFrameBufferTimg->mTexFmt;
        pRVar5->mTranslucency = pRVar2->mTranslucency;
        pRVar5->mWidth = pRVar2->mWidth;
        pRVar5->mHeight = pRVar2->mHeight;
        pRVar5->mWrapS = pRVar2->mWrapS;
        pRVar5->mWrapT = pRVar2->mWrapT;
        pRVar5->mbHasTlut = pRVar2->mbHasTlut;
        pRVar5->mTlutFmt = pRVar2->mTlutFmt;
        pRVar5->mTlutCount = pRVar2->mTlutCount;
        pRVar5->mTlutDataOffs = pRVar2->mTlutDataOffs;
        pRVar5->mbMipmapEnabled = pRVar2->mbMipmapEnabled;
        pRVar5->mbDoEdgeLOD = pRVar2->mbDoEdgeLOD;
        pRVar5->mbBiasClamp = pRVar2->mbBiasClamp;
        pRVar5->mMaxAniso = pRVar2->mMaxAniso;
        pRVar5->mMinFilter = pRVar2->mMinFilter;
        pRVar5->mMagFilter = pRVar2->mMagFilter;
        pRVar5->mMinLOD = pRVar2->mMinLOD;
        pRVar5->mMaxLOD = pRVar2->mMaxLOD;
        pRVar5->mMipmapCount = pRVar2->mMipmapCount;
        pRVar5->field_0x19 = pRVar2->field_0x19;
        pRVar5->mLODBias = pRVar2->mLODBias;
        pRVar5->mTexDataOffs = pRVar2->mTexDataOffs;
        pRVar5 = pJVar7->mpTexData + uVar1;
        pRVar5->mTexDataOffs = (int)pRVar2 + (pRVar5->mTexDataOffs - (int)pRVar5);
        pRVar5 = pJVar7->mpTexData + uVar1;
        pRVar5->mTlutDataOffs = (int)pRVar2 + (pRVar5->mTlutDataOffs - (int)pRVar5);
      }
    }
  }
  m_Do_ext::mDoExt_modelTexturePatch(pJVar8);
  return;
}


namespace d_message_paper {

/* __stdcall loadModelData(unsigned char *) */

void loadModelData(void *param_1)

{
  J3DModelLoaderDataBase::loadBinaryDisplayList(param_1,0x1020);
  return;
}


/* __stdcall loadAnmTransformData(unsigned char *) */

void loadAnmTransformData(void *param_1)

{
  J3DAnmLoaderDataBase::load(param_1);
  return;
}

}

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dmsg3_3d_c::dmsg3_3d_c(void) */

void __thiscall dmsg3_3d_c::dmsg3_3d_c(dmsg3_3d_c *this)

{
  float fVar1;
  JKRSolidHeap *pJVar2;
  void *pvVar3;
  J3DModelData *pModel;
  ulong uVar4;
  J3DModel *pJVar5;
  J3DAnmTransform *pJVar6;
  int iVar7;
  
  *(undefined1 **)this = &__vt;
  *(undefined ***)(this + 0x34) = &::mDoExt_baseAnm::__vt;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined ***)(this + 0x34) = &::mDoExt_bckAnm::__vt;
  *(undefined4 *)(this + 0x40) = 0;
  *(undefined4 *)(this + 0x48) = 0;
  pJVar2 = m_Do_ext::mDoExt_createSolidHeapFromGameToCurrent(0x20000,0x20);
  *(JKRSolidHeap **)(this + 0x48) = pJVar2;
  pvVar3 = JKRHeap::alloc(*(JKRHeap **)(this + 0x48),8000,0x20);
  *(void **)(this + 4) = pvVar3;
  JKRArchive::readTypeResource
            (*(void **)(this + 4),8000,0x42444c4d,"hukidashi_07.bdl",
             d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpMsgArchive);
  os::DCStoreRangeNoSync(*(undefined4 *)(this + 4),8000);
  pvVar3 = JKRHeap::alloc(*(JKRHeap **)(this + 0x48),5000,0x20);
  *(void **)(this + 0xc) = pvVar3;
  JKRArchive::readTypeResource
            (*(void **)(this + 0xc),5000,0x42434b20,"hukidashi_07.bck",
             d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpMsgArchive);
  os::DCStoreRangeNoSync(*(undefined4 *)(this + 0xc),5000);
  pModel = (J3DModelData *)d_message_paper::loadModelData(*(undefined4 *)(this + 4));
  if (pModel == (J3DModelData *)0x0) {
    uVar4 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar4,"d_message_paper.cpp",0xd5,"modelData != 0");
    m_Do_printf::OSPanic("d_message_paper.cpp",0xd5,"Halt");
  }
  pJVar5 = m_Do_ext::mDoExt_J3DModel__create(pModel,0x80000,0x37441422);
  *(J3DModel **)(this + 0x30) = pJVar5;
  if (*(int *)(this + 0x30) == 0) {
    uVar4 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar4,"d_message_paper.cpp",0xda,"mModel != 0");
    m_Do_printf::OSPanic("d_message_paper.cpp",0xda,"Halt");
  }
  pJVar6 = (J3DAnmTransform *)d_message_paper::loadAnmTransformData(*(undefined4 *)(this + 0xc));
  if (pJVar6 == (J3DAnmTransform *)0x0) {
    uVar4 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar4,"d_message_paper.cpp",0xdd,"bck != 0");
    m_Do_printf::OSPanic("d_message_paper.cpp",0xdd,"Halt");
  }
  iVar7 = ::mDoExt_bckAnm::init
                    ((mDoExt_bckAnm *)(this + 0x34),pModel,pJVar6,true,Once,d_message_paper::_4087,0
                     ,-1,false);
  if (iVar7 == 0) {
    uVar4 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar4,"d_message_paper.cpp",0xe4,"ok_bck != 0");
    m_Do_printf::OSPanic("d_message_paper.cpp",0xe4,"Halt");
  }
  setDummyTexture(this);
  *(undefined2 *)(this + 0x28) = 0;
  *(undefined2 *)(this + 0x2a) = 0x8000;
  *(undefined2 *)(this + 0x2c) = 0;
  fVar1 = d_message_paper::_4087;
  *(float *)(this + 0x10) = d_message_paper::_4087;
  *(float *)(this + 0x14) = fVar1;
  *(float *)(this + 0x18) = fVar1;
  iVar7 = *(int *)(this + 0x30);
  *(undefined4 *)(iVar7 + 0x18) = *(undefined4 *)(this + 0x10);
  *(undefined4 *)(iVar7 + 0x1c) = *(undefined4 *)(this + 0x14);
  *(undefined4 *)(iVar7 + 0x20) = *(undefined4 *)(this + 0x18);
  set_mtx(this);
  m_Do_ext::mDoExt_adjustSolidHeap(*(JKRSolidHeap **)(this + 0x48));
  m_Do_ext::mDoExt_restoreCurrentHeap();
  return;
}


/* __thiscall dmsg3_3d_c::~dmsg3_3d_c(void) */

void __thiscall dmsg3_3d_c::_dmsg3_3d_c(dmsg3_3d_c *this)

{
  short in_r4;
  
  if (this != (dmsg3_3d_c *)0x0) {
    *(undefined1 **)this = &__vt;
    JKRHeap::free(*(JKRHeap **)(this + 0x48),*(void **)(this + 4));
    JKRHeap::free(*(JKRHeap **)(this + 0x48),*(void **)(this + 0xc));
    m_Do_ext::mDoExt_destroySolidHeap(*(undefined4 *)(this + 0x48));
    if (this != (dmsg3_3d_c *)0xffffffcc) {
      *(undefined ***)(this + 0x34) = &::mDoExt_bckAnm::__vt;
      if (this != (dmsg3_3d_c *)0xffffffcc) {
        *(undefined ***)(this + 0x34) = &::mDoExt_baseAnm::__vt;
      }
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dmsg3_3d_c::set_mtx(void) */

void __thiscall dmsg3_3d_c::set_mtx(dmsg3_3d_c *this)

{
  double dVar1;
  
  dVar1 = (double)d_message_paper::_4126;
  mtx::PSMTXTrans(dVar1,dVar1,dVar1,&mDoMtx_stack_c::now);
  m_Do_mtx::mDoMtx_ZXYrotM
            (&mDoMtx_stack_c::now,(int)*(short *)(this + 0x28),(int)*(short *)(this + 0x2a),
             (int)*(short *)(this + 0x2c));
  mtx::PSMTXCopy(&mDoMtx_stack_c::now,(MTX34 *)(*(int *)(this + 0x30) + 0x24));
  return;
}


/* __thiscall dmsg3_3d_c::exec(void) */

void __thiscall dmsg3_3d_c::exec(dmsg3_3d_c *this)

{
  ::mDoExt_baseAnm::play((mDoExt_baseAnm *)(this + 0x34));
  set_mtx(this);
  return;
}


/* __thiscall dmsg3_3d_c::draw(void) */

void __thiscall dmsg3_3d_c::draw(dmsg3_3d_c *this)

{
  J3DGraphBase::j3dSys.mpCurDrawBuffers[0] = d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x38
  ;
  J3DGraphBase::j3dSys.mpCurDrawBuffers[1] = d_com_inf_game::g_dComIfG_gameInfo.mDlstList.field_0x38
  ;
  ::mDoExt_bckAnm::entry
            ((mDoExt_bckAnm *)(this + 0x34),*(J3DModelData **)(*(int *)(this + 0x30) + 4),
             *(float *)(*(int *)(this + 0x38) + 0x10));
  m_Do_ext::mDoExt_modelUpdateDL(*(J3DModel **)(this + 0x30));
  *(undefined4 *)(**(int **)(*(int *)(*(int *)(this + 0x30) + 4) + 0x2c) + 0x58) = 0;
  J3DGraphBase::j3dSys.mpCurDrawBuffers[0] =
       d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelOpa;
  J3DGraphBase::j3dSys.mpCurDrawBuffers[1] =
       d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelXlu;
  return;
}


namespace d_message_paper {

/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __stdcall dMsg3_value_init(sub_msg3_class *,
                              unsigned char) */

void dMsg3_value_init(int param_1,uint param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  uint uVar6;
  char acStack168 [32];
  char acStack136 [32];
  char acStack104 [32];
  char acStack72 [40];
  
  uVar6 = *(uint *)(&colorTable_4180 + (uint)*(ushort *)(param_1 + 0xea0) * 4);
  iVar5 = param_1 + (param_2 & 0xff) * 0x2a0;
  bVar1 = *(byte *)(iVar5 + 0x3a8);
  bVar2 = *(byte *)(iVar5 + 0x3a9);
  bVar3 = *(byte *)(iVar5 + 0x3aa);
  bVar4 = *(byte *)(iVar5 + 0x3ab);
  MSL_C.PPCEABI.bare.H::sprintf(acStack72,"\x1bCC[%08x]\x1bGC[%08x]",uVar6 | bVar1,uVar6 | bVar2);
  MSL_C.PPCEABI.bare.H::sprintf(acStack136,"\x1bCC[%08x]\x1bGC[%08x]",uVar6 | bVar3,uVar6 | bVar4);
  MSL_C.PPCEABI.bare.H::sprintf(acStack104,"\x1bCC[%08x]\x1bGC[%08x]",(uint)bVar1,(uint)bVar2);
  MSL_C.PPCEABI.bare.H::sprintf(acStack168,"\x1bCC[%08x]\x1bGC[%08x]",(uint)bVar3,(uint)bVar4);
  iVar5 = (param_2 & 0xff) * 4;
  MSL_C.PPCEABI.bare.H::strcpy(*(char **)(param_1 + iVar5 + 0xe60),acStack72);
  MSL_C.PPCEABI.bare.H::strcpy(*(char **)(param_1 + iVar5 + 0xe6c),acStack136);
  MSL_C.PPCEABI.bare.H::strcpy(*(char **)(param_1 + iVar5 + 0xe78),acStack104);
  MSL_C.PPCEABI.bare.H::strcpy(*(char **)(param_1 + iVar5 + 0xe84),acStack168);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall dMsg3_setString(sub_msg3_class *,
                             unsigned char) */

void dMsg3_setString(int param_1,uint param_2,___ param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (param_2 & 0xff) * 0x38;
  iVar2 = (param_2 & 0xff) * 4;
  J2DTextBox::setString
            (*(J2DTextBox **)(param_1 + iVar1 + 0x90c),*(char **)(param_1 + iVar2 + 0xe60),param_3);
  J2DTextBox::setString
            (*(J2DTextBox **)(param_1 + iVar1 + 0xa5c),*(char **)(param_1 + iVar2 + 0xe6c),param_3);
  J2DTextBox::setString
            (*(J2DTextBox **)(param_1 + iVar1 + 0x9b4),*(char **)(param_1 + iVar2 + 0xe78),param_3);
  J2DTextBox::setString
            (*(J2DTextBox **)(param_1 + iVar1 + 0xb04),*(char **)(param_1 + iVar2 + 0xe84),param_3);
  return;
}


/* __stdcall dMsg3_messagePaneShow(sub_msg3_class *,
                                   unsigned char) */

void dMsg3_messagePaneShow(int param_1,uint param_2)

{
  param_1 = param_1 + (param_2 & 0xff) * 0x38;
  *(undefined *)(*(int *)(param_1 + 0x90c) + 0xaa) = 1;
  *(undefined *)(*(int *)(param_1 + 0xa5c) + 0xaa) = 1;
  return;
}


/* __stdcall dMsg3_messagePaneHide(sub_msg3_class *,
                                   unsigned char) */

void dMsg3_messagePaneHide(int param_1,uint param_2)

{
  param_1 = param_1 + (param_2 & 0xff) * 0x38;
  *(undefined *)(*(int *)(param_1 + 0x90c) + 0xaa) = 0;
  *(undefined *)(*(int *)(param_1 + 0xa5c) + 0xaa) = 0;
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Removing unreachable block (ram,0x801ebbb0) */
/* __stdcall dMsg3_outFontHide(unsigned char) */

void dMsg3_outFontHide(uint param_1)

{
  int *piVar1;
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
  iVar2 = 0;
  iVar4 = 0;
  iVar3 = 0;
  dVar6 = (double)_4126;
  do {
    *(undefined *)(*(int *)((int)(&bbutton_icon3 + (param_1 & 0xff)) + iVar3) + 0xaa) = 0;
    *(undefined *)(*(int *)((int)(&bbutton_kage3 + (param_1 & 0xff)) + iVar3) + 0xaa) = 0;
    piVar1 = *(int **)((int)(&bbutton_icon3 + (param_1 & 0xff)) + iVar3);
    piVar1[0x29] = (int)(float)dVar6;
    (**(code **)(*piVar1 + 0x20))();
    piVar1 = *(int **)((int)(&bbutton_kage3 + (param_1 & 0xff)) + iVar3);
    piVar1[0x29] = (int)(float)dVar6;
    (**(code **)(*piVar1 + 0x20))();
    *(undefined2 *)((int)&bbuttonTimer3 + iVar4 + (param_1 & 0xff) * 2) = 0xffff;
    iVar2 = iVar2 + 1;
    iVar4 = iVar4 + 6;
    iVar3 = iVar3 + 0xc;
  } while (iVar2 < 8);
  __psq_l0(auStack8,uVar5);
  __psq_l1(auStack8,uVar5);
  return;
}


/* __stdcall dMsg3_arrowUpShow(sub_msg3_class *) */

void dMsg3_arrowUpShow(int param_1)

{
  f_op_msg_mng::fopMsgM_setInitAlpha(param_1 + 0xbac);
  f_op_msg_mng::fopMsgM_setInitAlpha(param_1 + 0xbe4);
  return;
}


/* __stdcall dMsg3_arrowUpHide(sub_msg3_class *) */

void dMsg3_arrowUpHide(int param_1)

{
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0xbac));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0xbe4));
  return;
}


/* __stdcall dMsg3_arrowDownShow(sub_msg3_class *) */

void dMsg3_arrowDownShow(int param_1)

{
  f_op_msg_mng::fopMsgM_setInitAlpha(param_1 + 0xc1c);
  f_op_msg_mng::fopMsgM_setInitAlpha(param_1 + 0xc54);
  return;
}


/* __stdcall dMsg3_arrowDownHide(sub_msg3_class *) */

void dMsg3_arrowDownHide(int param_1)

{
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0xc1c));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0xc54));
  return;
}


/* __stdcall dMsg3_dotShow(sub_msg3_class *) */

void dMsg3_dotShow(int param_1)

{
  f_op_msg_mng::fopMsgM_setInitAlpha(param_1 + 0xc8c);
  f_op_msg_mng::fopMsgM_setInitAlpha(param_1 + 0xcc4);
  return;
}


/* __stdcall dMsg3_dotHide(sub_msg3_class *) */

void dMsg3_dotHide(int param_1)

{
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0xc8c));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0xcc4));
  return;
}


/* __stdcall dMsg3_multiTexInit(sub_msg3_class *) */

void dMsg3_multiTexInit(int param_1)

{
  JKRArchive::readTypeResource
            (*(void **)(param_1 + 0xe54),0x11800,0x54494d47,"hukidashi_0212.bti",
             d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpMsgArchive);
  os::DCStoreRangeNoSync(*(undefined4 *)(param_1 + 0xe54),0x11800);
  JKRArchive::readTypeResource
            (*(void **)(param_1 + 0xe58),0x11800,0x54494d47,"hukidashi_07.bti",
             d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpMsgArchive);
  os::DCStoreRangeNoSync(*(undefined4 *)(param_1 + 0xe58),0x11800);
  dDlst_2Dm_c::init((dDlst_2Dm_c *)&board,*(ResTIMG **)(param_1 + 0xe54),
                    *(ResTIMG **)(param_1 + 0xe58),_4087,_4087);
  return;
}


/* __stdcall dMsg3_fontdataInit(sub_msg3_class *) */

void dMsg3_fontdataInit(int param_1)

{
  JUTFont *pJVar1;
  ulong uVar2;
  
  pJVar1 = m_Do_ext::mDoExt_getMesgFont();
  *(JUTFont **)(param_1 + 0xe4c) = pJVar1;
  if (*(int *)(param_1 + 0xe4c) == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_message_paper.cpp",0x274,"i_Msg->mx != 0");
    m_Do_printf::OSPanic("d_message_paper.cpp",0x274,"Halt");
  }
  pJVar1 = m_Do_ext::mDoExt_getRubyFont();
  *(JUTFont **)(param_1 + 0xe50) = pJVar1;
  if (*(int *)(param_1 + 0xe50) == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_message_paper.cpp",0x277,"i_Msg->rx != 0");
    m_Do_printf::OSPanic("d_message_paper.cpp",0x277,"Halt");
  }
  return;
}


/* __stdcall dMsg3_screenDataSet(sub_msg3_class *,
                                 unsigned char) */

void dMsg3_screenDataSet(undefined4 param_1,undefined4 param_2)

{
  dMsg3_value_init();
  dMsg3_setString(param_1,param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f30 */
/* WARNING: Inlined function: FUN_80328f7c */
/* WARNING: Removing unreachable block (ram,0x801ec50c) */
/* __stdcall dMsg3_screenDataInit(sub_msg3_class *,
                                  unsigned char) */

void dMsg3_screenDataInit(int param_1,byte param_2)

{
  double dVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  uint uVar5;
  double dVar6;
  J2DScreen *pJVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  double in_f31;
  undefined auStack8 [8];
  
  uVar11 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,SUB84(in_f31,0),0);
  uVar5 = (uint)param_2;
  pJVar7 = (J2DScreen *)
           (**(code **)(*(int *)(&sScreen3)[uVar5] + 0x30))((int *)(&sScreen3)[uVar5],0x74783233);
  iVar9 = param_1 + (uint)param_2 * 0x38;
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(iVar9 + 0x90c),pJVar7);
  pJVar7 = (J2DScreen *)
           (**(code **)(*(int *)(&sScreen3)[uVar5] + 0x30))((int *)(&sScreen3)[uVar5],0x74783239);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(iVar9 + 0xa5c),pJVar7);
  pJVar7 = (J2DScreen *)
           (**(code **)(*(int *)(&sScreen3)[uVar5] + 0x30))((int *)(&sScreen3)[uVar5],0x74783230);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(iVar9 + 0x9b4),pJVar7);
  pJVar7 = (J2DScreen *)
           (**(code **)(*(int *)(&sScreen3)[uVar5] + 0x30))((int *)(&sScreen3)[uVar5],0x74783236);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(iVar9 + 0xb04),pJVar7);
  *(undefined *)(*(int *)(iVar9 + 0x9b4) + 0xaa) = 0;
  *(undefined *)(*(int *)(iVar9 + 0xb04) + 0xaa) = 0;
  pJVar7 = (J2DScreen *)
           (**(code **)(*(int *)(&sScreen3)[uVar5] + 0x30))((int *)(&sScreen3)[uVar5],0x6d733232);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(iVar9 + 0xcfc),pJVar7);
  pJVar7 = (J2DScreen *)
           (**(code **)(*(int *)(&sScreen3)[uVar5] + 0x30))((int *)(&sScreen3)[uVar5],0x6d733230);
  f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(iVar9 + 0xda4),pJVar7);
  iVar8 = (**(code **)(*(int *)(&sScreen3)[uVar5] + 0x30))((int *)(&sScreen3)[uVar5],0x74783234);
  *(undefined *)(iVar8 + 0xaa) = 0;
  iVar8 = (**(code **)(*(int *)(&sScreen3)[uVar5] + 0x30))((int *)(&sScreen3)[uVar5],0x74783330);
  *(undefined *)(iVar8 + 0xaa) = 0;
  iVar8 = (**(code **)(*(int *)(&sScreen3)[uVar5] + 0x30))((int *)(&sScreen3)[uVar5],0x74783231);
  *(undefined *)(iVar8 + 0xaa) = 0;
  iVar8 = (**(code **)(*(int *)(&sScreen3)[uVar5] + 0x30))((int *)(&sScreen3)[uVar5],0x74783237);
  *(undefined *)(iVar8 + 0xaa) = 0;
  iVar8 = *(int *)(iVar9 + 0xcfc);
  *(undefined *)(iVar8 + 0x104) = 0;
  *(undefined *)(iVar8 + 0x105) = 0;
  *(undefined *)(iVar8 + 0x106) = 0;
  *(undefined *)(iVar8 + 0x107) = 0;
  iVar8 = *(int *)(iVar9 + 0xda4);
  *(undefined *)(iVar8 + 0x104) = 0;
  *(undefined *)(iVar8 + 0x105) = 0;
  *(undefined *)(iVar8 + 0x106) = 0;
  *(undefined *)(iVar8 + 0x107) = 0;
  if (param_2 == 0) {
    pJVar7 = (J2DScreen *)
             (**(code **)(*(int *)(&sScreen3)[uVar5] + 0x30))((int *)(&sScreen3)[uVar5],0x797a3231);
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0xbac),pJVar7);
    pJVar7 = (J2DScreen *)
             (**(code **)(*(int *)(&sScreen3)[uVar5] + 0x30))((int *)(&sScreen3)[uVar5],0x797a3230);
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0xc1c),pJVar7);
    pJVar7 = (J2DScreen *)
             (**(code **)(*(int *)(&sScreen3)[uVar5] + 0x30))((int *)(&sScreen3)[uVar5],0x64743230);
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0xc8c),pJVar7);
    pJVar7 = (J2DScreen *)
             (**(code **)(*(int *)(&sScreen3)[uVar5] + 0x30))((int *)(&sScreen3)[uVar5],0x797a3233);
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0xbe4),pJVar7);
    pJVar7 = (J2DScreen *)
             (**(code **)(*(int *)(&sScreen3)[uVar5] + 0x30))((int *)(&sScreen3)[uVar5],0x797a3232);
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0xc54),pJVar7);
    pJVar7 = (J2DScreen *)
             (**(code **)(*(int *)(&sScreen3)[uVar5] + 0x30))((int *)(&sScreen3)[uVar5],0x64743231);
    f_op_msg_mng::fopMsgM_setPaneData((fopMsgM_pane_class *)(param_1 + 0xcc4),pJVar7);
    iVar8 = *(int *)(param_1 + 0xbe4);
    *(undefined *)(iVar8 + 0x104) = 0;
    *(undefined *)(iVar8 + 0x105) = 0;
    *(undefined *)(iVar8 + 0x106) = 0;
    *(undefined *)(iVar8 + 0x107) = 0xff;
    iVar8 = *(int *)(param_1 + 0xc54);
    *(undefined *)(iVar8 + 0x104) = 0;
    *(undefined *)(iVar8 + 0x105) = 0;
    *(undefined *)(iVar8 + 0x106) = 0;
    *(undefined *)(iVar8 + 0x107) = 0xff;
    iVar8 = *(int *)(param_1 + 0xcc4);
    *(undefined *)(iVar8 + 0x104) = 0;
    *(undefined *)(iVar8 + 0x105) = 0;
    *(undefined *)(iVar8 + 0x106) = 0;
    *(undefined *)(iVar8 + 0x107) = 0xff;
  }
  else {
    iVar8 = (**(code **)(*(int *)(&sScreen3)[uVar5] + 0x30))((int *)(&sScreen3)[uVar5],0x797a3231);
    *(undefined *)(iVar8 + 0xaa) = 0;
    iVar8 = (**(code **)(*(int *)(&sScreen3)[uVar5] + 0x30))((int *)(&sScreen3)[uVar5],0x797a3230);
    *(undefined *)(iVar8 + 0xaa) = 0;
    iVar8 = (**(code **)(*(int *)(&sScreen3)[uVar5] + 0x30))((int *)(&sScreen3)[uVar5],0x64743230);
    *(undefined *)(iVar8 + 0xaa) = 0;
    iVar8 = (**(code **)(*(int *)(&sScreen3)[uVar5] + 0x30))((int *)(&sScreen3)[uVar5],0x797a3233);
    *(undefined *)(iVar8 + 0xaa) = 0;
    iVar8 = (**(code **)(*(int *)(&sScreen3)[uVar5] + 0x30))((int *)(&sScreen3)[uVar5],0x797a3232);
    *(undefined *)(iVar8 + 0xaa) = 0;
    iVar8 = (**(code **)(*(int *)(&sScreen3)[uVar5] + 0x30))((int *)(&sScreen3)[uVar5],0x64743231);
    *(undefined *)(iVar8 + 0xaa) = 0;
  }
  iVar10 = param_1 + (uint)param_2 * 0x38;
  J2DTextBox::setFont(*(J2DTextBox **)(iVar10 + 0x90c),*(JUTFont **)(param_1 + 0xe4c));
  J2DTextBox::setFont(*(J2DTextBox **)(iVar10 + 0xa5c),*(JUTFont **)(param_1 + 0xe50));
  J2DTextBox::setFont(*(J2DTextBox **)(iVar9 + 0x9b4),*(JUTFont **)(param_1 + 0xe4c));
  J2DTextBox::setFont(*(J2DTextBox **)(iVar9 + 0xb04),*(JUTFont **)(param_1 + 0xe50));
  dVar1 = (double)CONCAT44(0x43300000,(int)DAT_803e6bb4 ^ 0x80000000U) - _4419;
  fVar2 = (float)dVar1;
  fVar3 = (float)((double)CONCAT44(0x43300000,(int)DAT_803e6bb4 ^ 0x80000000U) - _4419);
  iVar8 = *(int *)(iVar10 + 0x90c);
  fVar4 = _4126;
  if (_4126 < fVar2) {
    fVar4 = fVar2;
  }
  *(float *)(iVar8 + 0xe8) = fVar4;
  fVar4 = _4126;
  if (_4126 < fVar3) {
    fVar4 = fVar3;
  }
  *(float *)(iVar8 + 0xec) = fVar4;
  iVar8 = *(int *)(iVar9 + 0x9b4);
  fVar4 = _4126;
  if (_4126 < fVar2) {
    fVar4 = fVar2;
  }
  *(float *)(iVar8 + 0xe8) = fVar4;
  fVar2 = _4126;
  if (_4126 < fVar3) {
    fVar2 = fVar3;
  }
  *(float *)(iVar8 + 0xec) = fVar2;
  fVar2 = _4416;
  *(float *)(*(int *)(iVar10 + 0x90c) + 0xe0) = _4416;
  fVar3 = _4417;
  *(float *)(*(int *)(iVar10 + 0xa5c) + 0xe0) = _4417;
  *(float *)(*(int *)(iVar9 + 0x9b4) + 0xe0) = fVar2;
  *(float *)(*(int *)(iVar9 + 0xb04) + 0xe0) = fVar3;
  dVar6 = _4419;
  *(float *)(*(int *)(iVar10 + 0x90c) + 0xe4) =
       (float)((double)CONCAT44(0x43300000,(int)DAT_803e6ba2 ^ 0x80000000) - _4419);
  *(float *)(*(int *)(iVar9 + 0x9b4) + 0xe4) =
       (float)((double)CONCAT44(0x43300000,(int)DAT_803e6ba2 ^ 0x80000000) - dVar6);
  *(int *)(param_1 + 0xeb0) = (int)dVar1;
  *(int *)(param_1 + 0xeb4) = (int)in_f31;
  __psq_l0(auStack8,uVar11);
  __psq_l1(auStack8,uVar11);
  return;
}


/* __stdcall dMsg3_ScreenDataValueInit(sub_msg3_class *) */

void dMsg3_ScreenDataValueInit(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x90c);
  *(int *)(param_1 + 0xeac) = (int)(*(float *)(iVar1 + 0xe4) * _4436);
  *(float *)(param_1 + 0xe90) =
       (float)((double)CONCAT44(0x43300000,(int)DAT_803e6c18 ^ 0x80000000) - _4419) +
       (*(float *)(iVar1 + 0x18) - *(float *)(iVar1 + 0x10));
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(param_1 + 0x90c),(double)_4126,(double)_4126);
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(param_1 + 0x944),(double)_4126,
             (double)*(float *)(param_1 + 0xe90));
  f_op_msg_mng::fopMsgM_paneTrans
            ((fopMsgM_pane_class *)(param_1 + 0x97c),(double)_4126,
             -(double)*(float *)(param_1 + 0xe90));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0xbac));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0xbe4));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0xc1c));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0xc54));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0xc8c));
  f_op_msg_mng::fopMsgM_setNowAlphaZero((fopMsgM_pane_class *)(param_1 + 0xcc4));
  iVar1 = 0;
  do {
    dMsg3_messageDataInit(param_1,iVar1);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 3);
  return;
}


/* __stdcall dMsg3_stickInfoInit(sub_msg3_class *) */

void dMsg3_stickInfoInit(int param_1)

{
  if ((_4453 < m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mStickMainPosY) ||
     (_4453 < m_Do_controller_pad::g_mDoCPd_cpadInfo[3].mStickMainPosY)) {
    *(undefined *)(param_1 + 0xed9) = 1;
    return;
  }
  if ((_4453 <= m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mStickMainPosY) &&
     (_4453 <= m_Do_controller_pad::g_mDoCPd_cpadInfo[3].mStickMainPosY)) {
    *(undefined *)(param_1 + 0xed9) = 0;
    return;
  }
  *(undefined *)(param_1 + 0xed9) = 2;
  return;
}


/* __stdcall dMsg3_stickInfoCheck(sub_msg3_class *) */

void dMsg3_stickInfoCheck(int param_1)

{
  if (*(char *)(param_1 + 0xed9) == '\x01') {
    if ((_4126 < m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mStickMainPosY) &&
       (_4126 < m_Do_controller_pad::g_mDoCPd_cpadInfo[3].mStickMainPosY)) {
      return;
    }
    *(undefined *)(param_1 + 0xed9) = 0;
    return;
  }
  if (*(char *)(param_1 + 0xed9) != '\x02') {
    return;
  }
  if ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mStickMainPosY < _4126) &&
     (m_Do_controller_pad::g_mDoCPd_cpadInfo[3].mStickMainPosY < _4126)) {
    return;
  }
  *(undefined *)(param_1 + 0xed9) = 0;
  return;
}


/* WARNING: Inlined function: FUN_80328f18 */
/* WARNING: Inlined function: FUN_80328f64 */
/* __stdcall dMsg3_messageOut(sub_msg3_class *,
                              unsigned char,
                              int) */

void dMsg3_messageOut(int param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  uVar1 = param_2 & 0xff;
  iVar7 = (param_2 & 0xff) * 4;
  *(undefined4 *)(param_1 + iVar7 + 0xec8) = 0;
  dMsg3_messagePaneShow();
  dMsg3_messageDataInit(param_1,uVar1);
  iVar3 = uVar1 * 0x2a0;
  iVar2 = param_1 + iVar3;
  *(undefined4 *)(iVar2 + 0x230) = 0;
  *(undefined4 *)(iVar2 + 0x250) = 0;
  *(undefined4 *)(iVar2 + 0x254) = param_3;
  dMsg3_yose_select(param_1,param_2);
  *(undefined *)(param_1 + iVar3 + 0x3b1) = 1;
  dMsg3_setCharAlpha(param_1,param_2);
  iVar3 = param_1 + iVar3;
  fopMsgM_msgDataProc_c::stringSet((fopMsgM_msgDataProc_c *)(iVar3 + 0x118));
  iVar6 = 0;
  iVar5 = 0;
  iVar4 = 0;
  iVar2 = 0;
  do {
    if ((*(char *)(iVar3 + iVar6 + 0x399) != -1) &&
       (*(short *)((int)&bbuttonTimer3 + iVar4 + uVar1 * 2) == -1)) {
      f_op_msg_mng::fopMsgM_outFontSet
                (*(undefined4 *)((int)&bbutton_icon3 + iVar5 + iVar7),
                 *(undefined4 *)((int)&bbutton_kage3 + iVar5 + iVar7),
                 (int)&bbuttonTimer3 + iVar4 + uVar1 * 2,*(undefined4 *)(iVar3 + iVar2 + 0x338));
    }
    iVar6 = iVar6 + 1;
    iVar5 = iVar5 + 0xc;
    iVar4 = iVar4 + 6;
    iVar2 = iVar2 + 4;
  } while (iVar6 < 8);
  dMsg3_setString(param_1,param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __stdcall dMsg3_yose_select(sub_msg3_class *,
                               unsigned char) */

void dMsg3_yose_select(int param_1,uint param_2)

{
  undefined4 uVar1;
  fopMsgM_msgDataProc_c *this;
  int iVar2;
  
  iVar2 = (param_2 & 0xff) * 0x2a0;
  this = (fopMsgM_msgDataProc_c *)(param_1 + iVar2 + 0x118);
  uVar1 = fopMsgM_msgDataProc_c::stringLength(this);
  iVar2 = param_1 + iVar2;
  *(undefined4 *)(iVar2 + 0x230) = uVar1;
  *(undefined4 *)(param_1 + (param_2 & 0xff) * 4 + 0xec8) = *(undefined4 *)(iVar2 + 0x248);
  *(undefined4 *)(iVar2 + 0x248) = 0;
  fopMsgM_msgDataProc_c::stringShift(this);
  dMsg3_textPosition(param_1,param_2);
  return;
}


/* __stdcall dMsg3_textPosition(sub_msg3_class *,
                                unsigned char) */

void dMsg3_textPosition(int param_1,uint param_2)

{
  float fVar1;
  double dVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  fVar1 = _4126;
  iVar5 = *(int *)(param_1 + 0xeac);
  iVar3 = *(int *)(param_1 + (param_2 & 0xff) * 4 + 0xec8);
  param_1 = param_1 + (param_2 & 0xff) * 0x38;
  iVar6 = *(int *)(param_1 + 0x90c);
  *(float *)(iVar6 + 0xd8) = _4126;
  dVar2 = _4419;
  uVar4 = iVar5 * (2 - iVar3) ^ 0x80000000;
  *(float *)(iVar6 + 0xdc) = (float)((double)CONCAT44(0x43300000,uVar4) - _4419);
  iVar3 = *(int *)(param_1 + 0xa5c);
  *(float *)(iVar3 + 0xd8) = fVar1;
  *(float *)(iVar3 + 0xdc) = (float)((double)CONCAT44(0x43300000,uVar4) - dVar2);
  iVar3 = *(int *)(param_1 + 0x9b4);
  *(float *)(iVar3 + 0xd8) = fVar1;
  *(float *)(iVar3 + 0xdc) = (float)((double)CONCAT44(0x43300000,uVar4) - dVar2);
  iVar3 = *(int *)(param_1 + 0xb04);
  *(float *)(iVar3 + 0xd8) = fVar1;
  *(float *)(iVar3 + 0xdc) = (float)((double)CONCAT44(0x43300000,uVar4) - dVar2);
  return;
}


/* __stdcall dMsg3_rubySet(sub_msg3_class *) */

void dMsg3_rubySet(int param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  sVar1 = *(short *)(param_1 + 0xf8);
  if ((((sVar1 != 5) && (sVar1 != 6)) && (sVar1 != 7)) && (sVar1 != 10)) {
    return;
  }
  iVar2 = 0;
  iVar3 = 3;
  do {
    if (DAT_803e6c27 == '\0') {
      *(undefined *)(*(int *)(param_1 + iVar2 + 0xa5c) + 0xaa) = 0;
    }
    else {
      *(undefined *)(*(int *)(param_1 + iVar2 + 0xa5c) + 0xaa) = 1;
    }
    iVar2 = iVar2 + 0x38;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}


/* __stdcall dMsg3_arrowMove(sub_msg3_class *) */

void dMsg3_arrowMove(int param_1)

{
  int iVar1;
  
  *(int *)(param_1 + 0xeb8) = *(int *)(param_1 + 0xeb8) + 1;
  if (0xc < *(int *)(param_1 + 0xeb8)) {
    *(int *)(param_1 + 0xeb8) = *(int *)(param_1 + 0xeb8) + -0xc;
  }
  iVar1 = MSL_C.PPCEABI.bare.H::abs(6 - *(int *)(param_1 + 0xeb8));
  (**(code **)(**(int **)(param_1 + 0xc1c) + 0x10))
            ((double)(float)((double)CONCAT44(0x43300000,
                                              (int)*(float *)(param_1 + 0xc20) ^ 0x80000000) - _4419
                            ),
             (double)(float)((double)CONCAT44(0x43300000,
                                              (int)*(float *)(param_1 + 0xc24) - iVar1 ^ 0x80000000)
                            - _4419));
  iVar1 = MSL_C.PPCEABI.bare.H::abs(6 - *(int *)(param_1 + 0xeb8));
  (**(code **)(**(int **)(param_1 + 0xc54) + 0x10))
            ((double)(float)((double)CONCAT44(0x43300000,
                                              (int)*(float *)(param_1 + 0xc20) ^ 0x80000000) - _4419
                            ),
             (double)(float)((double)CONCAT44(0x43300000,
                                              (int)*(float *)(param_1 + 0xc24) - iVar1 ^ 0x80000000)
                            - _4419));
  iVar1 = MSL_C.PPCEABI.bare.H::abs(6 - *(int *)(param_1 + 0xeb8));
  (**(code **)(**(int **)(param_1 + 0xbac) + 0x10))
            ((double)(float)((double)CONCAT44(0x43300000,
                                              (int)*(float *)(param_1 + 0xbb0) ^ 0x80000000) - _4419
                            ),
             (double)(float)((double)CONCAT44(0x43300000,
                                              (int)*(float *)(param_1 + 0xbb4) + iVar1 ^ 0x80000000)
                            - _4419));
  iVar1 = MSL_C.PPCEABI.bare.H::abs(6 - *(int *)(param_1 + 0xeb8));
  (**(code **)(**(int **)(param_1 + 0xbe4) + 0x10))
            ((double)(float)((double)CONCAT44(0x43300000,
                                              (int)*(float *)(param_1 + 0xbb0) ^ 0x80000000) - _4419
                            ),
             (double)(float)((double)CONCAT44(0x43300000,
                                              (int)*(float *)(param_1 + 0xbb4) + iVar1 ^ 0x80000000)
                            - _4419));
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall dMsg3_aimAlphaSqare(sub_msg3_class *,
                                 int,
                                 int) */

void dMsg3_aimAlphaSqare(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  if ((int)param_3 < 0) {
    param_3 = 0;
  }
  else {
    if ((int)param_2 < (int)param_3) {
      param_3 = param_2;
    }
  }
  uVar1 = dMsg3_aimBrightness();
  *(float *)(param_1 + 0xea4) =
       _4489 - (_4489 - (float)((double)CONCAT44(0x43300000,uVar1 & 0xff) - _4491)) *
               (((float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - _4419) *
                (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - _4419)) /
               ((float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - _4419) *
               (float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - _4419)));
  return;
}


/* WARNING: Removing unreachable block (ram,0x801ecde8) */
/* __stdcall dMsg3_aimAlphaSqrt(sub_msg3_class *,
                                int,
                                int) */

void dMsg3_aimAlphaSqrt(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  undefined4 uVar2;
  double dVar3;
  undefined8 in_f31;
  double dVar4;
  undefined auStack8 [8];
  
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  if ((int)param_3 < 0) {
    param_3 = 0;
  }
  else {
    if ((int)param_2 < (int)param_3) {
      param_3 = param_2;
    }
  }
  dVar4 = (double)((float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - _4419) /
                  (float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - _4419));
  if ((double)_4126 < dVar4) {
    dVar3 = 1.0 / SQRT(dVar4);
    dVar3 = _4635 * dVar3 * (_4636 - dVar4 * dVar3 * dVar3);
    dVar3 = _4635 * dVar3 * (_4636 - dVar4 * dVar3 * dVar3);
    dVar4 = (double)(float)(dVar4 * _4635 * dVar3 * (_4636 - dVar4 * dVar3 * dVar3));
  }
  uVar1 = dMsg3_aimBrightness();
  *(float *)(param_1 + 0xea4) =
       _4489 - (float)((double)(_4489 - (float)((double)CONCAT44(0x43300000,uVar1 & 0xff) - _4491))
                      * dVar4);
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  return;
}


/* __stdcall dMsg3_kankyoBrightness(void) */

int dMsg3_kankyoBrightness(void)

{
  short *psVar1;
  
  psVar1 = (short *)d_kankyo::dKy_Get_DifCol();
  return (int)(_4643 * (float)((double)CONCAT44(0x43300000,(int)psVar1[2] ^ 0x80000000) - _4419) +
              _4644 * (float)((double)CONCAT44(0x43300000,(int)*psVar1 ^ 0x80000000) - _4419) +
              _4645 * (float)((double)CONCAT44(0x43300000,(int)psVar1[1] ^ 0x80000000) - _4419));
}


/* __stdcall dMsg3_aimBrightness(void) */

char dMsg3_aimBrightness(void)

{
  char cVar1;
  byte bVar2;
  
  bVar2 = dMsg3_kankyoBrightness();
  cVar1 = -1;
  if (DAT_803e6c05 < bVar2) {
    cVar1 = -1 - (bVar2 - DAT_803e6c05);
  }
  return cVar1;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __stdcall dMsg3_setCharAlpha(sub_msg3_class *,
                                unsigned char) */

void dMsg3_setCharAlpha(int param_1,uint param_2)

{
  undefined uVar1;
  undefined uVar2;
  undefined uVar3;
  float fVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  uVar5 = param_2 & 0xff;
  iVar6 = *(int *)(param_1 + (param_2 & 0xff) * 4 + 0xec8);
  fVar4 = (*(float *)(param_1 + 0xd04) - *(float *)(param_1 + 0xdac)) +
          *(float *)(param_1 + uVar5 * 0x38 + 0x91c) +
          (float)((double)CONCAT44(0x43300000,*(int *)(param_1 + 0xeac) * (2 - iVar6) ^ 0x80000000)
                 - _4419);
  iVar7 = (int)fVar4;
  iVar6 = (int)*(float *)(*(int *)(param_1 + 0x90c) + 0xe4) * iVar6;
  iVar9 = iVar7 + iVar6;
  iVar8 = (int)(fVar4 - (float)((double)CONCAT44(0x43300000,(int)DAT_803e6c14 ^ 0x80000000) - _4419)
               );
  iVar6 = iVar8 + iVar6;
  if (iVar9 < 0x3a) {
    iVar7 = (**(code **)(**(int **)(param_1 + 0xe4c) + 0x24))();
    if (iVar9 < 0) {
      *(undefined *)(param_1 + uVar5 + 0xedb) = 0;
    }
    else {
      *(undefined *)(param_1 + uVar5 + 0xedb) = (&dMsg3_tex_i4_color)[iVar9];
    }
    if (iVar9 + iVar7 < 0) {
      *(undefined *)(param_1 + uVar5 + 0xede) = 0;
    }
    else {
      *(undefined *)(param_1 + uVar5 + 0xede) = (&dMsg3_tex_i4_color)[iVar9 + iVar7];
    }
  }
  else {
    if (iVar7 < 0xbc) {
      *(undefined *)(param_1 + uVar5 + 0xedb) = 0xff;
      *(undefined *)(param_1 + uVar5 + 0xede) = 0xff;
    }
    else {
      iVar9 = (**(code **)(**(int **)(param_1 + 0xe4c) + 0x24))();
      if (iVar7 < 0xf0) {
        *(undefined *)(param_1 + uVar5 + 0xedb) = (&dMsg3_tex_i4_color)[iVar7];
      }
      else {
        *(undefined *)(param_1 + uVar5 + 0xedb) = 0;
      }
      if (iVar7 + iVar9 < 0xf0) {
        *(undefined *)(param_1 + uVar5 + 0xede) = (&dMsg3_tex_i4_color)[iVar7 + iVar9];
      }
      else {
        *(undefined *)(param_1 + uVar5 + 0xede) = 0;
      }
    }
  }
  if (iVar6 < 0x3a) {
    iVar7 = (**(code **)(**(int **)(param_1 + 0xe50) + 0x24))();
    if (iVar6 < 0) {
      *(undefined *)(param_1 + uVar5 + 0xee1) = 0;
    }
    else {
      *(undefined *)(param_1 + uVar5 + 0xee1) = (&dMsg3_tex_i4_color)[iVar6];
    }
    if (iVar6 + iVar7 < 0) {
      *(undefined *)(param_1 + uVar5 + 0xee4) = 0;
    }
    else {
      *(undefined *)(param_1 + uVar5 + 0xee4) = (&dMsg3_tex_i4_color)[iVar6 + iVar7];
    }
  }
  else {
    if (iVar8 < 0xbc) {
      *(undefined *)(param_1 + uVar5 + 0xee1) = 0xff;
      *(undefined *)(param_1 + uVar5 + 0xee4) = 0xff;
    }
    else {
      iVar7 = (**(code **)(**(int **)(param_1 + 0xe50) + 0x24))();
      if (iVar8 < 0xf0) {
        *(undefined *)(param_1 + uVar5 + 0xee1) = (&dMsg3_tex_i4_color)[iVar8];
      }
      else {
        *(undefined *)(param_1 + uVar5 + 0xee1) = 0;
      }
      if (iVar8 + iVar7 < 0xf0) {
        *(undefined *)(param_1 + uVar5 + 0xee4) = (&dMsg3_tex_i4_color)[iVar8 + iVar7];
      }
      else {
        *(undefined *)(param_1 + uVar5 + 0xee4) = 0;
      }
    }
  }
  iVar7 = param_1 + uVar5;
  if (((int)*(float *)(param_1 + 0xea8) & 0xffU) < (uint)*(byte *)(iVar7 + 0xedb)) {
    *(char *)(iVar7 + 0xedb) = (char)(int)*(float *)(param_1 + 0xea8);
  }
  iVar8 = param_1 + uVar5;
  if (((int)*(float *)(param_1 + 0xea8) & 0xffU) < (uint)*(byte *)(iVar8 + 0xede)) {
    *(char *)(iVar8 + 0xede) = (char)(int)*(float *)(param_1 + 0xea8);
  }
  iVar6 = param_1 + uVar5;
  if (((int)*(float *)(param_1 + 0xea8) & 0xffU) < (uint)*(byte *)(iVar6 + 0xee1)) {
    *(char *)(iVar6 + 0xee1) = (char)(int)*(float *)(param_1 + 0xea8);
  }
  iVar9 = param_1 + uVar5;
  if (((int)*(float *)(param_1 + 0xea8) & 0xffU) < (uint)*(byte *)(iVar9 + 0xee4)) {
    *(char *)(iVar9 + 0xee4) = (char)(int)*(float *)(param_1 + 0xea8);
  }
  uVar1 = *(undefined *)(iVar9 + 0xee4);
  uVar2 = *(undefined *)(iVar6 + 0xee1);
  uVar3 = *(undefined *)(iVar8 + 0xede);
  param_1 = param_1 + uVar5 * 0x2a0;
  *(undefined *)(param_1 + 0x3a8) = *(undefined *)(iVar7 + 0xedb);
  *(undefined *)(param_1 + 0x3a9) = uVar3;
  *(undefined *)(param_1 + 0x3aa) = uVar2;
  *(undefined *)(param_1 + 0x3ab) = uVar1;
  return;
}


/* __stdcall dMsg3_messageShow(sub_msg3_class *) */

void dMsg3_messageShow(int param_1)

{
  uint uVar1;
  
  for (uVar1 = 0; (uVar1 & 0xff) < 3; uVar1 = uVar1 + 1) {
    dMsg3_screenDataSet(param_1,uVar1);
  }
  if (0 < *(int *)(param_1 + 0xec0)) {
    dMsg3_messageOut(param_1,*(undefined *)(param_1 + 0xe98),
                     *(int *)(param_1 + 0xec0) - (uint)*(byte *)(param_1 + 0x116));
  }
  dMsg3_messageOut(param_1,*(undefined *)(param_1 + 0xe99),*(undefined4 *)(param_1 + 0xec0));
  if (*(char *)(param_1 + (uint)*(byte *)(param_1 + 0xe99) * 0x2a0 + 0x394) == '\a') {
    dMsg3_messageOut(param_1,*(undefined *)(param_1 + 0xe9a),
                     *(int *)(param_1 + 0xec0) + (uint)*(byte *)(param_1 + 0x116));
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x801ed48c) */
/* WARNING: Removing unreachable block (ram,0x801ed494) */
/* __stdcall dMsg3_messageDataInit(sub_msg3_class *,
                                   int) */

void dMsg3_messageDataInit(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 uVar8;
  undefined8 in_f30;
  double dVar9;
  undefined8 in_f31;
  double dVar10;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar8 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  iVar7 = param_1 + param_2 * 0x38;
  dVar10 = (double)*(float *)(*(int *)(iVar7 + 0x90c) + 0xe0);
  dVar9 = (double)*(float *)(*(int *)(iVar7 + 0xa5c) + 0xe0);
  fopMsgM_msgDataProc_c::dataInit((fopMsgM_msgDataProc_c *)(param_1 + param_2 * 0x2a0 + 0x118));
  iVar3 = param_1 + param_2 * 0x2a0;
  *(undefined4 *)(iVar3 + 0x154) = *(undefined4 *)(param_1 + 0xe5c);
  iVar2 = param_1 + param_2 * 4;
  uVar6 = *(undefined4 *)(iVar2 + 0xe84);
  uVar5 = *(undefined4 *)(iVar2 + 0xe78);
  uVar4 = *(undefined4 *)(iVar2 + 0xe6c);
  uVar1 = *(undefined4 *)(iVar2 + 0xe60);
  *(undefined4 *)(iVar3 + 0x178) = uVar1;
  *(undefined4 *)(iVar3 + 0x158) = uVar1;
  *(undefined4 *)(iVar3 + 0x17c) = uVar4;
  *(undefined4 *)(iVar3 + 0x15c) = uVar4;
  *(undefined4 *)(iVar3 + 0x180) = uVar5;
  *(undefined4 *)(iVar3 + 0x160) = uVar5;
  *(undefined4 *)(iVar3 + 0x184) = uVar6;
  *(undefined4 *)(iVar3 + 0x164) = uVar6;
  *(undefined4 *)(iVar3 + 0x11c) = *(undefined4 *)(param_1 + 0xe4c);
  *(undefined4 *)(iVar3 + 0x120) = *(undefined4 *)(param_1 + 0xe50);
  *(int *)(iVar3 + 0x234) = (int)dVar10;
  *(int *)(iVar3 + 0x23c) = (int)dVar9;
  *(int *)(iVar3 + 0x238) = (int)*(float *)(*(int *)(iVar7 + 0x90c) + 0xe4);
  *(int *)(iVar3 + 0x124) = param_1 + 0x100;
  *(undefined4 *)(iVar3 + 0x25c) = *(undefined4 *)(param_1 + 0xeb0);
  *(undefined4 *)(iVar3 + 0x264) = *(undefined4 *)(param_1 + 0xeb4);
  *(undefined4 *)(iVar3 + 0x240) = 0x1f7;
  *(undefined4 *)(iVar3 + 0x244) = 0x1e6;
  *(undefined *)(iVar3 + 0x3b4) = 0;
  __psq_l0(auStack8,uVar8);
  __psq_l1(auStack8,uVar8);
  __psq_l0(auStack24,uVar8);
  __psq_l1(auStack24,uVar8);
  return;
}


/* __stdcall dMsg3_stopProc(sub_msg3_class *) */

undefined4 dMsg3_stopProc(int param_1)

{
  if (*(char *)(param_1 + 0xed9) == '\0') {
    if ((_4453 < m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mStickMainPosY) ||
       (_4453 < m_Do_controller_pad::g_mDoCPd_cpadInfo[3].mStickMainPosY)) {
      if (*(int *)(param_1 + 0xec0) != 0) {
        *(undefined *)(param_1 + 0xed9) = 1;
        dMsg3_screenDataSet(param_1,*(undefined *)(param_1 + 0xe9a));
        *(undefined *)(param_1 + 0xebc) = 3;
        *(uint *)(param_1 + 0xec0) = *(int *)(param_1 + 0xec0) - (uint)*(byte *)(param_1 + 0x116);
        *(undefined2 *)(param_1 + 0xf8) = 5;
        JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x803,(cXyz *)0x0,0,0,_4087,_4087,_4417,_4417,0)
        ;
      }
    }
    else {
      if (((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) != 0) ||
         ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mStickMainPosY < _4815 ||
          (m_Do_controller_pad::g_mDoCPd_cpadInfo[3].mStickMainPosY < _4815)))) {
        *(undefined *)(param_1 + 0xed9) = 2;
        dMsg3_screenDataSet(param_1,*(undefined *)(param_1 + 0xe98));
        *(undefined *)(param_1 + 0xebc) = 1;
        *(uint *)(param_1 + 0xec0) = *(int *)(param_1 + 0xec0) + (uint)*(byte *)(param_1 + 0x116);
        *(undefined2 *)(param_1 + 0xf8) = 5;
        JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x803,(cXyz *)0x0,0,0,_4087,_4087,_4417,_4417,0)
        ;
      }
    }
  }
  else {
    dMsg3_stickInfoCheck();
  }
  return 1;
}


/* __stdcall dMsg3_closewaitProc(sub_msg3_class *) */

undefined4 dMsg3_closewaitProc(int param_1)

{
  if (*(char *)(param_1 + 0xed9) == '\0') {
    if ((_4453 < m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mStickMainPosY) ||
       (_4453 < m_Do_controller_pad::g_mDoCPd_cpadInfo[3].mStickMainPosY)) {
      if (*(int *)(param_1 + 0xec0) != 0) {
        *(undefined *)(param_1 + 0xed9) = 1;
        dMsg3_screenDataSet(param_1,*(undefined *)(param_1 + 0xe9a));
        *(undefined *)(param_1 + 0xebc) = 3;
        *(uint *)(param_1 + 0xec0) = *(int *)(param_1 + 0xec0) - (uint)*(byte *)(param_1 + 0x116);
        *(undefined2 *)(param_1 + 0xf8) = 5;
        JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x803,(cXyz *)0x0,0,0,_4087,_4087,_4417,_4417,0)
        ;
      }
    }
    else {
      if (((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mButton2 & 1) != 0) ||
         ((m_Do_controller_pad::g_mDoCPd_cpadInfo[0].mStickMainPosY < _4815 ||
          (m_Do_controller_pad::g_mDoCPd_cpadInfo[3].mStickMainPosY < _4815)))) {
        *(undefined *)(param_1 + 0xed9) = 2;
        JAIZelBasic::seStart(JAIZelBasic::zel_basic,0x80d,(cXyz *)0x0,0,0,_4087,_4087,_4417,_4417,0)
        ;
        *(undefined2 *)(param_1 + 0xf8) = 0x10;
      }
    }
  }
  else {
    dMsg3_stickInfoCheck();
  }
  return 1;
}


/* __stdcall dMsg3_openProc(sub_msg3_class *) */

undefined4 dMsg3_openProc(int param_1)

{
  double dVar1;
  
  if (*(int *)(param_1 + 0xe94) == 0) {
    dMsg3_messageOut(param_1,*(undefined *)(param_1 + 0xe99),*(undefined4 *)(param_1 + 0xec0));
    if (*(char *)(param_1 + (uint)*(byte *)(param_1 + 0xe99) * 0x2a0 + 0x394) == '\a') {
      dMsg3_messageOut(param_1,*(undefined *)(param_1 + 0xe9a),
                       *(int *)(param_1 + 0xec0) + (uint)*(byte *)(param_1 + 0x116));
    }
  }
  else {
    if (*(int *)(param_1 + 0xe94) == dMsg3_popSpeed) {
      *(ushort *)(param_1 + 0xf8) =
           (ushort)*(byte *)(param_1 + (uint)*(byte *)(param_1 + 0xe99) * 0x2a0 + 0x394);
    }
  }
  dVar1 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                            (dMsg3_popSpeed,*(undefined4 *)(param_1 + 0xe94),0);
  *(float *)(param_1 + 0xea8) = (float)((double)_4489 * dVar1);
  if (*(int *)(param_1 + 0xe94) != 0) {
    dMsg3_messageShow(param_1);
  }
  if (*(char *)(param_1 + (uint)*(byte *)(param_1 + 0xe99) * 0x2a0 + 0x394) == '\a') {
    *(char *)(param_1 + 0xc51) = (char)(int)*(float *)(param_1 + 0xea8);
    *(char *)(param_1 + 0xc89) = (char)(int)*(float *)(param_1 + 0xea8);
  }
  else {
    *(char *)(param_1 + 0xcc1) = (char)(int)*(float *)(param_1 + 0xea8);
    *(char *)(param_1 + 0xcf9) = (char)(int)*(float *)(param_1 + 0xea8);
  }
  dMsg3_aimAlphaSqrt(param_1,dMsg3_popSpeed,*(undefined4 *)(param_1 + 0xe94));
  d_com_inf_game::g_dComIfG_gameInfo.field_0x1d1c1 = (byte)(int)*(float *)(param_1 + 0xea4);
  *(int *)(param_1 + 0xe94) = *(int *)(param_1 + 0xe94) + 1;
  return 1;
}


/* __stdcall dMsg3_closeProc(sub_msg3_class *) */

undefined4 dMsg3_closeProc(int param_1)

{
  uint uVar1;
  double dVar2;
  
  if (*(int *)(param_1 + 0xe94) == 0) {
    for (uVar1 = 0; (uVar1 & 0xff) < 3; uVar1 = uVar1 + 1) {
      dMsg3_messagePaneHide(param_1,uVar1);
      dMsg3_outFontHide(uVar1);
    }
    JKRFileLoader::removeResource(*(void **)(param_1 + 0x908),(JKRFileLoader *)0x0);
    *(undefined2 *)(param_1 + 0xf8) = 0x12;
  }
  *(int *)(param_1 + 0xe94) = *(int *)(param_1 + 0xe94) + -1;
  if (*(int *)(param_1 + 0xe94) < 0) {
    *(undefined4 *)(param_1 + 0xe94) = 0;
  }
  dVar2 = (double)f_op_msg_mng::fopMsgM_valueIncrease
                            (dMsg3_popSpeed,*(undefined4 *)(param_1 + 0xe94),0);
  *(float *)(param_1 + 0xea8) = (float)((double)_4489 * dVar2);
  if (*(char *)(param_1 + 0xbe1) != '\0') {
    *(char *)(param_1 + 0xbe1) = (char)(int)*(float *)(param_1 + 0xea8);
    *(char *)(param_1 + 0xc19) = (char)(int)*(float *)(param_1 + 0xea8);
  }
  if (*(char *)(param_1 + 0xc51) != '\0') {
    *(char *)(param_1 + 0xc51) = (char)(int)*(float *)(param_1 + 0xea8);
    *(char *)(param_1 + 0xc89) = (char)(int)*(float *)(param_1 + 0xea8);
  }
  if (*(char *)(param_1 + 0xcc1) != '\0') {
    *(char *)(param_1 + 0xcc1) = (char)(int)*(float *)(param_1 + 0xea8);
    *(char *)(param_1 + 0xcf9) = (char)(int)*(float *)(param_1 + 0xea8);
  }
  dMsg3_aimAlphaSqare(param_1,dMsg3_popSpeed,*(undefined4 *)(param_1 + 0xe94));
  d_com_inf_game::g_dComIfG_gameInfo.field_0x1d1c1 = (byte)(int)*(float *)(param_1 + 0xea4);
  return 1;
}


/* __stdcall dMsg3_outwaitProc(sub_msg3_class *) */

undefined4 dMsg3_outwaitProc(int param_1)

{
  char cVar1;
  byte bVar2;
  undefined uVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  
  cVar1 = *(char *)(param_1 + 0xebc);
  if ((cVar1 == '\x01') || (cVar1 == '\x02')) {
    *(int *)(param_1 + 0xec4) = *(int *)(param_1 + 0xec4) + 0xc;
  }
  else {
    if ((cVar1 == '\x03') || (cVar1 == '\x04')) {
      *(int *)(param_1 + 0xec4) = *(int *)(param_1 + 0xec4) + -0xc;
    }
  }
  iVar5 = *(int *)(param_1 + 0xec4);
  if (iVar5 < 0x3fd) {
    if (iVar5 < -0x3fc) {
      *(int *)(param_1 + 0xec4) = iVar5 + 0x7f8;
    }
  }
  else {
    *(int *)(param_1 + 0xec4) = iVar5 + -0x7f8;
  }
  fVar4 = _4975;
  cVar1 = *(char *)(param_1 + 0xebc);
  if (cVar1 == '\x01') {
    bVar2 = *(byte *)(param_1 + 0xe98);
    iVar5 = 0;
    iVar6 = 3;
    do {
      *(float *)(param_1 + iVar5 + 0x91c) = *(float *)(param_1 + iVar5 + 0x91c) - fVar4;
      iVar5 = iVar5 + 0x38;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    *(char *)(param_1 + 0xeda) = *(char *)(param_1 + 0xeda) + -0x55;
    if (*(float *)(param_1 + (uint)bVar2 * 0x38 + 0x91c) < -*(float *)(param_1 + 0xe90)) {
      *(undefined *)(param_1 + 0xebc) = 2;
      uVar3 = *(undefined *)(param_1 + 0xe99);
      *(undefined *)(param_1 + 0xe99) = *(undefined *)(param_1 + 0xe9a);
      *(undefined *)(param_1 + 0xe9a) = *(undefined *)(param_1 + 0xe98);
      *(undefined *)(param_1 + 0xe98) = uVar3;
      if (*(char *)(param_1 + (uint)*(byte *)(param_1 + 0xe99) * 0x2a0 + 0x394) == '\a') {
        dMsg3_messageOut(param_1,*(undefined *)(param_1 + 0xe9a),
                         *(int *)(param_1 + 0xec0) + (uint)*(byte *)(param_1 + 0x116));
      }
      else {
        dMsg3_messagePaneHide(param_1,*(undefined *)(param_1 + 0xe9a));
        dMsg3_outFontHide(*(undefined *)(param_1 + 0xe9a));
      }
      *(undefined *)(param_1 + 0xeda) = 0;
      dMsg3_arrowUpHide(param_1);
      dMsg3_arrowDownHide(param_1);
      dMsg3_dotHide(param_1);
    }
  }
  else {
    if (cVar1 == '\x03') {
      bVar2 = *(byte *)(param_1 + 0xe9a);
      iVar5 = 0;
      iVar6 = 3;
      do {
        *(float *)(param_1 + iVar5 + 0x91c) = *(float *)(param_1 + iVar5 + 0x91c) + fVar4;
        iVar5 = iVar5 + 0x38;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      *(char *)(param_1 + 0xeda) = *(char *)(param_1 + 0xeda) + -0x7f;
      if (*(float *)(param_1 + 0xd24) < *(float *)(param_1 + (uint)bVar2 * 0x38 + 0x91c)) {
        *(undefined *)(param_1 + 0xebc) = 4;
        uVar3 = *(undefined *)(param_1 + 0xe99);
        *(undefined *)(param_1 + 0xe99) = *(undefined *)(param_1 + 0xe98);
        *(undefined *)(param_1 + 0xe98) = *(undefined *)(param_1 + 0xe9a);
        *(undefined *)(param_1 + 0xe9a) = uVar3;
        if (*(int *)(param_1 + 0xec0) < 1) {
          dMsg3_messagePaneHide(param_1,*(undefined *)(param_1 + 0xe98));
          dMsg3_outFontHide(*(undefined *)(param_1 + 0xe98));
        }
        else {
          dMsg3_messageOut(param_1,*(undefined *)(param_1 + 0xe98),
                           *(int *)(param_1 + 0xec0) - (uint)*(byte *)(param_1 + 0x116));
        }
        *(undefined *)(param_1 + 0xeda) = 0;
        dMsg3_arrowUpHide(param_1);
        dMsg3_arrowDownHide(param_1);
        dMsg3_dotHide(param_1);
      }
    }
    else {
      if (cVar1 == '\x02') {
        iVar5 = 0;
        iVar6 = 3;
        do {
          *(float *)(param_1 + iVar5 + 0x91c) = *(float *)(param_1 + iVar5 + 0x91c) - fVar4;
          iVar5 = iVar5 + 0x38;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
        *(char *)(param_1 + 0xeda) = *(char *)(param_1 + 0xeda) + '+';
        if (*(float *)(param_1 + (uint)*(byte *)(param_1 + 0xe99) * 0x38 + 0x91c) <=
            *(float *)(param_1 + 0x914)) {
          *(float *)(param_1 + (uint)*(byte *)(param_1 + 0xe98) * 0x38 + 0x91c) =
               *(float *)(param_1 + 0x914) - *(float *)(param_1 + 0xe90);
          *(undefined4 *)(param_1 + (uint)*(byte *)(param_1 + 0xe99) * 0x38 + 0x91c) =
               *(undefined4 *)(param_1 + 0x914);
          *(float *)(param_1 + (uint)*(byte *)(param_1 + 0xe9a) * 0x38 + 0x91c) =
               *(float *)(param_1 + 0x914) + *(float *)(param_1 + 0xe90);
          *(undefined *)(param_1 + 0xebc) = 0;
          if (*(char *)(param_1 + (uint)*(byte *)(param_1 + 0xe99) * 0x2a0 + 0x394) == '\a') {
            *(undefined2 *)(param_1 + 0xf8) = 7;
            dMsg3_arrowDownShow(param_1);
          }
          else {
            *(undefined2 *)(param_1 + 0xf8) = 0xe;
            dMsg3_dotShow(param_1);
          }
          *(undefined *)(param_1 + 0xeda) = 0xff;
          if (*(int *)(param_1 + 0xec0) != 0) {
            dMsg3_arrowUpShow(param_1);
          }
        }
        dMsg3_messageShow(param_1);
      }
      else {
        if (cVar1 == '\x04') {
          iVar5 = 0;
          iVar6 = 3;
          do {
            *(float *)(param_1 + iVar5 + 0x91c) = *(float *)(param_1 + iVar5 + 0x91c) + fVar4;
            iVar5 = iVar5 + 0x38;
            iVar6 = iVar6 + -1;
          } while (iVar6 != 0);
          *(char *)(param_1 + 0xeda) = *(char *)(param_1 + 0xeda) + '%';
          if (*(float *)(param_1 + 0x914) <=
              *(float *)(param_1 + (uint)*(byte *)(param_1 + 0xe99) * 0x38 + 0x91c)) {
            *(float *)(param_1 + (uint)*(byte *)(param_1 + 0xe98) * 0x38 + 0x91c) =
                 *(float *)(param_1 + 0x914) - *(float *)(param_1 + 0xe90);
            *(undefined4 *)(param_1 + (uint)*(byte *)(param_1 + 0xe99) * 0x38 + 0x91c) =
                 *(undefined4 *)(param_1 + 0x914);
            *(float *)(param_1 + (uint)*(byte *)(param_1 + 0xe9a) * 0x38 + 0x91c) =
                 *(float *)(param_1 + 0x914) + *(float *)(param_1 + 0xe90);
            *(undefined *)(param_1 + 0xebc) = 0;
            *(undefined2 *)(param_1 + 0xf8) = 7;
            *(undefined *)(param_1 + 0xeda) = 0xff;
            dMsg3_arrowDownShow(param_1);
            if (*(int *)(param_1 + 0xec0) != 0) {
              dMsg3_arrowUpShow(param_1);
            }
          }
          dMsg3_messageShow(param_1);
        }
        else {
          dMsg3_messageShow(param_1);
        }
      }
    }
  }
  return 1;
}

}

/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* __thiscall dDlst_2DMSG3_c::draw(void) */

void __thiscall dDlst_2DMSG3_c::draw(dDlst_2DMSG3_c *this)

{
  J2DOrthoGraph *pCtx;
  int iVar1;
  int iVar2;
  
  pCtx = d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph;
  (*(code *)(((d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph)->parent).vtbl)->setPort)
            (d_com_inf_game::g_dComIfG_gameInfo.mp2DOrthoGraph);
  iVar1 = 0;
  iVar2 = 0;
  do {
    *(undefined *)(*(int *)((int)&d_message_paper::sScreen3 + iVar2) + 0xcc) = 1;
    J2DScreen::draw(*(J2DScreen **)((int)&d_message_paper::sScreen3 + iVar2),d_message_paper::_4126,
                    d_message_paper::_4126,&pCtx->parent);
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 4;
  } while (iVar1 < 3);
  outFontDraw(this);
  return;
}


/* WARNING: Inlined function: FUN_80328f18 */
/* WARNING: Inlined function: FUN_80328f64 */
/* WARNING: Removing unreachable block (ram,0x801ee0dc) */
/* WARNING: Removing unreachable block (ram,0x801ee0e4) */
/* __thiscall dDlst_2DMSG3_c::outFontDraw(void) */

void __thiscall dDlst_2DMSG3_c::outFontDraw(dDlst_2DMSG3_c *this)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  undefined4 uVar15;
  undefined8 in_f30;
  double dVar16;
  undefined8 in_f31;
  double dVar17;
  double local_68;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar15 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  dVar17 = (double)*(float *)(*(int *)(*(int *)(this + 4) + 0xcfc) + 0x20);
  dVar16 = (double)*(float *)(*(int *)(*(int *)(this + 4) + 0xcfc) + 0x28);
  iVar7 = 0;
  iVar14 = 0;
  iVar13 = 0;
  iVar12 = 0;
  iVar11 = 0;
  do {
    iVar6 = 0;
    iVar10 = 0;
    iVar9 = 0;
    iVar8 = 0;
    do {
      iVar5 = *(int *)(this + 4);
      iVar3 = iVar11 + iVar5 + iVar8 + 0x118;
      if (*(char *)(iVar11 + iVar5 + iVar6 + 0x399) != -1) {
        iVar4 = *(int *)(iVar12 + iVar5 + 0x90c);
        uVar1 = (uint)((float)((double)CONCAT44(0x43300000,
                                                *(int *)(iVar5 + 0xeac) *
                                                ((2 - *(int *)(iVar13 + iVar5 + 0xec8)) +
                                                *(int *)(iVar3 + 0x1a4) * 2) ^ 0x80000000) -
                              d_message_paper::_4419) + *(float *)(iVar4 + 0x20));
        uVar2 = uVar1 ^ 0x80000000;
        if ((dVar17 < (double)(float)((double)CONCAT44(0x43300000,uVar2) - d_message_paper::_4419))
           && (local_68 = (double)CONCAT44(0x43300000,*(uint *)(iVar3 + 0x1e0) ^ 0x80000000),
              (float)((double)CONCAT44(0x43300000,uVar2) - d_message_paper::_4419) <
              (float)(dVar16 - (double)(float)(local_68 - d_message_paper::_4419)))) {
          f_op_msg_mng::fopMsgM_outFontDraw
                    (*(undefined4 *)((int)&d_message_paper::bbutton_icon3 + iVar9 + iVar13),
                     *(undefined4 *)((int)&d_message_paper::bbutton_kage3 + iVar9 + iVar13),
                     (int)((float)((double)CONCAT44(0x43300000,*(uint *)(iVar3 + 0x168) ^ 0x80000000
                                                   ) - d_message_paper::_4419) +
                          *(float *)(iVar4 + 0x1c)),uVar1,*(uint *)(iVar3 + 0x1e0),
                     (int)&d_message_paper::bbuttonTimer3 + iVar10 + iVar14,
                     (int)*(float *)(iVar5 + 0xea8));
        }
      }
      iVar6 = iVar6 + 1;
      iVar10 = iVar10 + 6;
      iVar9 = iVar9 + 0xc;
      iVar8 = iVar8 + 4;
    } while (iVar6 < 8);
    iVar7 = iVar7 + 1;
    iVar14 = iVar14 + 2;
    iVar13 = iVar13 + 4;
    iVar12 = iVar12 + 0x38;
    iVar11 = iVar11 + 0x2a0;
  } while (iVar7 < 3);
  __psq_l0(auStack8,uVar15);
  __psq_l1(auStack8,uVar15);
  __psq_l0(auStack24,uVar15);
  __psq_l1(auStack24,uVar15);
  return;
}


namespace d_message_paper {

/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __stdcall dMsg3_Draw(sub_msg3_class *) */

undefined4 dMsg3_Draw(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = 0;
  iVar3 = 0;
  do {
    iVar2 = param_1 + iVar3;
    *(char *)(iVar2 + 0x941) = (char)(int)*(float *)(param_1 + 0xea8);
    *(char *)(iVar2 + 0xa91) = (char)(int)*(float *)(param_1 + 0xea8);
    *(char *)(iVar2 + 0x9e9) = (char)(int)*(float *)(param_1 + 0xea8);
    *(char *)(iVar2 + 0xb39) = (char)(int)*(float *)(param_1 + 0xea8);
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(iVar2 + 0x90c));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(iVar2 + 0xa5c));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(iVar2 + 0x9b4));
    f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(iVar2 + 0xb04));
    iVar1 = iVar1 + 1;
    iVar3 = iVar3 + 0x38;
  } while (iVar1 < 3);
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0xbac));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0xbe4));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0xc1c));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0xc54));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0xc8c));
  f_op_msg_mng::fopMsgM_setAlpha((fopMsgM_pane_class *)(param_1 + 0xcc4));
  dDlst_list_c::set(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpa,
                    &d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mp2DOpaEnd,
                    (dDlst_base_c *)&message);
  ::dmsg3_3d_c::draw(msg3d);
  return 1;
}


/* WARNING: Inlined function: FUN_80328f24 */
/* WARNING: Inlined function: FUN_80328f70 */
/* WARNING: Removing unreachable block (ram,0x801ee720) */
/* __stdcall dMsg3_Execute(sub_msg3_class *) */

undefined4 dMsg3_Execute(int param_1)

{
  uint uVar1;
  uint uVar2;
  short sVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  undefined8 in_f31;
  double dVar11;
  undefined local_d8;
  undefined uStack215;
  undefined uStack214;
  undefined uStack213;
  undefined local_d4;
  undefined uStack211;
  undefined uStack210;
  undefined uStack209;
  undefined local_d0;
  undefined uStack207;
  undefined uStack206;
  undefined uStack205;
  undefined local_cc;
  undefined uStack203;
  undefined uStack202;
  undefined uStack201;
  undefined local_c8;
  undefined uStack199;
  undefined uStack198;
  undefined uStack197;
  undefined local_c4;
  undefined uStack195;
  undefined uStack194;
  undefined uStack193;
  undefined local_c0;
  undefined uStack191;
  undefined uStack190;
  undefined uStack189;
  undefined local_bc;
  undefined uStack187;
  undefined uStack186;
  undefined uStack185;
  undefined local_b4;
  undefined uStack179;
  undefined uStack178;
  undefined uStack177;
  undefined local_ac;
  undefined uStack171;
  undefined uStack170;
  undefined uStack169;
  undefined local_a4;
  undefined uStack163;
  undefined uStack162;
  undefined uStack161;
  undefined local_9c;
  undefined uStack155;
  undefined uStack154;
  undefined uStack153;
  undefined auStack8 [8];
  
  uVar10 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  uVar5 = m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0xfc));
  ::dmsg3_3d_c::exec(msg3d);
  sVar3 = *(short *)(param_1 + 0xf8);
  if (sVar3 == 2) {
    dMsg3_openProc(param_1);
  }
  else {
    if (sVar3 == 5) {
      dMsg3_outwaitProc(param_1);
    }
    else {
      if (sVar3 == 7) {
        dMsg3_stopProc(param_1);
      }
      else {
        if (sVar3 == 0xe) {
          dMsg3_closewaitProc(param_1);
        }
        else {
          if (sVar3 == 0x10) {
            dMsg3_closeProc(param_1);
          }
          else {
            if (sVar3 == 0x13) {
              f_op_msg_mng::fopMsgM_Delete(param_1);
            }
          }
        }
      }
    }
  }
  dMsg3_arrowMove(param_1);
  iVar9 = 0;
  iVar8 = 0;
  dVar11 = _4419;
  do {
    iVar7 = param_1 + iVar8;
    uVar1 = (uint)(*(float *)(iVar7 + 0x918) +
                  (float)((double)CONCAT44(0x43300000,(int)DAT_803e6c34 ^ 0x80000000) - dVar11));
    uVar2 = (uint)*(float *)(iVar7 + 0x91c);
    (**(code **)(**(int **)(iVar7 + 0x90c) + 0x10))
              ((double)(float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - dVar11),
               (double)(float)((double)CONCAT44(0x43300000,uVar2 ^ 0x80000000) - dVar11));
    (**(code **)(**(int **)(iVar7 + 0xa5c) + 0x10))
              ((double)(float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - dVar11),
               (double)(float)((double)CONCAT44(0x43300000,uVar2 - (int)DAT_803e6c14 ^ 0x80000000) -
                              dVar11));
    (**(code **)(**(int **)(iVar7 + 0x9b4) + 0x10))
              ((double)(float)((double)CONCAT44(0x43300000,uVar1 + 2 ^ 0x80000000) - dVar11),
               (double)(float)((double)CONCAT44(0x43300000,uVar2 + 2 ^ 0x80000000) - dVar11));
    (**(code **)(**(int **)(iVar7 + 0xb04) + 0x10))
              ((double)(float)((double)CONCAT44(0x43300000,uVar1 + 2 ^ 0x80000000) - dVar11),
               (double)(float)((double)CONCAT44(0x43300000,
                                                (uVar2 + 2) - (int)DAT_803e6c14 ^ 0x80000000) -
                              dVar11));
    iVar9 = iVar9 + 1;
    iVar8 = iVar8 + 0x38;
  } while (iVar9 < 3);
  dMsg3_rubySet(param_1);
  iVar8 = 0;
  iVar9 = 3;
  do {
    uVar4 = DAT_803e6be1;
    iVar7 = param_1 + iVar8;
    iVar6 = *(int *)(iVar7 + 0x90c);
    local_9c = (undefined)((uint)DAT_803e6be1 >> 0x18);
    *(undefined *)(iVar6 + 0xd0) = local_9c;
    uStack155 = (undefined)((uint)uVar4 >> 0x10);
    *(undefined *)(iVar6 + 0xd1) = uStack155;
    uStack154 = (undefined)((uint)uVar4 >> 8);
    *(undefined *)(iVar6 + 0xd2) = uStack154;
    uStack153 = (undefined)uVar4;
    *(undefined *)(iVar6 + 0xd3) = uStack153;
    *(undefined *)(iVar6 + 0xd4) = local_9c;
    *(undefined *)(iVar6 + 0xd5) = uStack155;
    *(undefined *)(iVar6 + 0xd6) = uStack154;
    *(undefined *)(iVar6 + 0xd7) = uStack153;
    uVar4 = DAT_803e6bf9;
    iVar6 = *(int *)(iVar7 + 0xa5c);
    local_a4 = (undefined)((uint)DAT_803e6bf9 >> 0x18);
    *(undefined *)(iVar6 + 0xd0) = local_a4;
    uStack163 = (undefined)((uint)uVar4 >> 0x10);
    *(undefined *)(iVar6 + 0xd1) = uStack163;
    uStack162 = (undefined)((uint)uVar4 >> 8);
    *(undefined *)(iVar6 + 0xd2) = uStack162;
    uStack161 = (undefined)uVar4;
    *(undefined *)(iVar6 + 0xd3) = uStack161;
    *(undefined *)(iVar6 + 0xd4) = local_a4;
    *(undefined *)(iVar6 + 0xd5) = uStack163;
    *(undefined *)(iVar6 + 0xd6) = uStack162;
    *(undefined *)(iVar6 + 0xd7) = uStack161;
    uVar4 = DAT_803e6bed;
    iVar6 = *(int *)(iVar7 + 0x9b4);
    local_ac = (undefined)((uint)DAT_803e6bed >> 0x18);
    *(undefined *)(iVar6 + 0xd0) = local_ac;
    uStack171 = (undefined)((uint)uVar4 >> 0x10);
    *(undefined *)(iVar6 + 0xd1) = uStack171;
    uStack170 = (undefined)((uint)uVar4 >> 8);
    *(undefined *)(iVar6 + 0xd2) = uStack170;
    uStack169 = (undefined)uVar4;
    *(undefined *)(iVar6 + 0xd3) = uStack169;
    *(undefined *)(iVar6 + 0xd4) = local_ac;
    *(undefined *)(iVar6 + 0xd5) = uStack171;
    *(undefined *)(iVar6 + 0xd6) = uStack170;
    *(undefined *)(iVar6 + 0xd7) = uStack169;
    uVar4 = DAT_803e6bed;
    iVar6 = *(int *)(iVar7 + 0xb04);
    local_b4 = (undefined)((uint)DAT_803e6bed >> 0x18);
    *(undefined *)(iVar6 + 0xd0) = local_b4;
    uStack179 = (undefined)((uint)uVar4 >> 0x10);
    *(undefined *)(iVar6 + 0xd1) = uStack179;
    uStack178 = (undefined)((uint)uVar4 >> 8);
    *(undefined *)(iVar6 + 0xd2) = uStack178;
    uStack177 = (undefined)uVar4;
    *(undefined *)(iVar6 + 0xd3) = uStack177;
    *(undefined *)(iVar6 + 0xd4) = local_b4;
    *(undefined *)(iVar6 + 0xd5) = uStack179;
    *(undefined *)(iVar6 + 0xd6) = uStack178;
    *(undefined *)(iVar6 + 0xd7) = uStack177;
    uVar4 = DAT_803e6be5;
    iVar6 = *(int *)(iVar7 + 0x90c);
    local_bc = (undefined)((uint)DAT_803e6be5 >> 0x18);
    *(undefined *)(iVar6 + 0xf4) = local_bc;
    uStack187 = (undefined)((uint)uVar4 >> 0x10);
    *(undefined *)(iVar6 + 0xf5) = uStack187;
    uStack186 = (undefined)((uint)uVar4 >> 8);
    *(undefined *)(iVar6 + 0xf6) = uStack186;
    uStack185 = (undefined)uVar4;
    *(undefined *)(iVar6 + 0xf7) = uStack185;
    uVar4 = DAT_803e6bfd;
    iVar6 = *(int *)(iVar7 + 0xa5c);
    local_c0 = (undefined)((uint)DAT_803e6bfd >> 0x18);
    *(undefined *)(iVar6 + 0xf4) = local_c0;
    uStack191 = (undefined)((uint)uVar4 >> 0x10);
    *(undefined *)(iVar6 + 0xf5) = uStack191;
    uStack190 = (undefined)((uint)uVar4 >> 8);
    *(undefined *)(iVar6 + 0xf6) = uStack190;
    uStack189 = (undefined)uVar4;
    *(undefined *)(iVar6 + 0xf7) = uStack189;
    uVar4 = DAT_803e6bf1;
    iVar6 = *(int *)(iVar7 + 0x9b4);
    local_c4 = (undefined)((uint)DAT_803e6bf1 >> 0x18);
    *(undefined *)(iVar6 + 0xf4) = local_c4;
    uStack195 = (undefined)((uint)uVar4 >> 0x10);
    *(undefined *)(iVar6 + 0xf5) = uStack195;
    uStack194 = (undefined)((uint)uVar4 >> 8);
    *(undefined *)(iVar6 + 0xf6) = uStack194;
    uStack193 = (undefined)uVar4;
    *(undefined *)(iVar6 + 0xf7) = uStack193;
    uVar4 = DAT_803e6bf1;
    iVar6 = *(int *)(iVar7 + 0xb04);
    local_c8 = (undefined)((uint)DAT_803e6bf1 >> 0x18);
    *(undefined *)(iVar6 + 0xf4) = local_c8;
    uStack199 = (undefined)((uint)uVar4 >> 0x10);
    *(undefined *)(iVar6 + 0xf5) = uStack199;
    uStack198 = (undefined)((uint)uVar4 >> 8);
    *(undefined *)(iVar6 + 0xf6) = uStack198;
    uStack197 = (undefined)uVar4;
    *(undefined *)(iVar6 + 0xf7) = uStack197;
    uVar4 = DAT_803e6be9;
    iVar6 = *(int *)(iVar7 + 0x90c);
    local_cc = (undefined)((uint)DAT_803e6be9 >> 0x18);
    *(undefined *)(iVar6 + 0xf8) = local_cc;
    uStack203 = (undefined)((uint)uVar4 >> 0x10);
    *(undefined *)(iVar6 + 0xf9) = uStack203;
    uStack202 = (undefined)((uint)uVar4 >> 8);
    *(undefined *)(iVar6 + 0xfa) = uStack202;
    uStack201 = (undefined)uVar4;
    *(undefined *)(iVar6 + 0xfb) = uStack201;
    uVar4 = DAT_803e6c01;
    iVar6 = *(int *)(iVar7 + 0xa5c);
    local_d0 = (undefined)((uint)DAT_803e6c01 >> 0x18);
    *(undefined *)(iVar6 + 0xf8) = local_d0;
    uStack207 = (undefined)((uint)uVar4 >> 0x10);
    *(undefined *)(iVar6 + 0xf9) = uStack207;
    uStack206 = (undefined)((uint)uVar4 >> 8);
    *(undefined *)(iVar6 + 0xfa) = uStack206;
    uStack205 = (undefined)uVar4;
    *(undefined *)(iVar6 + 0xfb) = uStack205;
    uVar4 = DAT_803e6bf5;
    iVar6 = *(int *)(iVar7 + 0x9b4);
    local_d4 = (undefined)((uint)DAT_803e6bf5 >> 0x18);
    *(undefined *)(iVar6 + 0xf8) = local_d4;
    uStack211 = (undefined)((uint)uVar4 >> 0x10);
    *(undefined *)(iVar6 + 0xf9) = uStack211;
    uStack210 = (undefined)((uint)uVar4 >> 8);
    *(undefined *)(iVar6 + 0xfa) = uStack210;
    uStack209 = (undefined)uVar4;
    *(undefined *)(iVar6 + 0xfb) = uStack209;
    uVar4 = DAT_803e6bf5;
    iVar7 = *(int *)(iVar7 + 0xb04);
    local_d8 = (undefined)((uint)DAT_803e6bf5 >> 0x18);
    *(undefined *)(iVar7 + 0xf8) = local_d8;
    uStack215 = (undefined)((uint)uVar4 >> 0x10);
    *(undefined *)(iVar7 + 0xf9) = uStack215;
    uStack214 = (undefined)((uint)uVar4 >> 8);
    *(undefined *)(iVar7 + 0xfa) = uStack214;
    uStack213 = (undefined)uVar4;
    *(undefined *)(iVar7 + 0xfb) = uStack213;
    iVar8 = iVar8 + 0x38;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5bca = (byte)*(undefined2 *)(param_1 + 0xf8);
  m_Do_ext::mDoExt_setCurrentHeap(uVar5);
  __psq_l0(auStack8,uVar10);
  __psq_l1(auStack8,uVar10);
  return 1;
}


/* __stdcall dMsg3_IsDelete(sub_msg3_class *) */

undefined4 dMsg3_IsDelete(void)

{
  return 1;
}


/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* __stdcall dMsg3_Delete(sub_msg3_class *) */

undefined4 dMsg3_Delete(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5bca = 0;
  d_com_inf_game::g_dComIfG_gameInfo.field_0x1d1c1 = 0xff;
  uVar1 = m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0xfc));
  iVar4 = 0;
  iVar5 = 0;
  do {
    piVar2 = *(int **)((int)&sScreen3 + iVar5);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2,1);
    }
    iVar4 = iVar4 + 1;
    iVar5 = iVar5 + 4;
  } while (iVar4 < 3);
  JKRHeap::free(*(JKRHeap **)(param_1 + 0xfc),*(void **)(param_1 + 0xe54));
  JKRHeap::free(*(JKRHeap **)(param_1 + 0xfc),*(void **)(param_1 + 0xe58));
  m_Do_ext::mDoExt_removeMesgFont();
  m_Do_ext::mDoExt_removeRubyFont();
  iVar4 = 0;
  iVar5 = 0;
  do {
    iVar3 = 0;
    iVar6 = 0;
    do {
      piVar2 = *(int **)((int)&bbutton_icon3 + iVar6 + iVar5);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2,1);
      }
      piVar2 = *(int **)((int)&bbutton_kage3 + iVar6 + iVar5);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2,1);
      }
      iVar3 = iVar3 + 1;
      iVar6 = iVar6 + 0xc;
    } while (iVar3 < 8);
    iVar3 = param_1 + iVar5;
    JKRHeap::free(*(JKRHeap **)(param_1 + 0xfc),*(void **)(iVar3 + 0xe60));
    JKRHeap::free(*(JKRHeap **)(param_1 + 0xfc),*(void **)(iVar3 + 0xe6c));
    JKRHeap::free(*(JKRHeap **)(param_1 + 0xfc),*(void **)(iVar3 + 0xe78));
    JKRHeap::free(*(JKRHeap **)(param_1 + 0xfc),*(void **)(iVar3 + 0xe84));
    iVar4 = iVar4 + 1;
    iVar5 = iVar5 + 4;
  } while (iVar4 < 3);
  if (msg3d != (int *)0x0) {
    (**(code **)(*msg3d + 8))(msg3d,1);
  }
  msg3d = (int *)0x0;
  m_Do_ext::mDoExt_setCurrentHeap(uVar1);
  JKRHeap::freeAll(*(JKRHeap **)(param_1 + 0xfc));
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 = 0;
  return 1;
}


/* WARNING: Inlined function: FUN_80328f20 */
/* WARNING: Inlined function: FUN_80328f6c */
/* __stdcall dMsg3_Create(msg_class *) */

undefined4 dMsg3_Create(int param_1)

{
  undefined4 uVar1;
  dmsg3_3d_c *this;
  J2DPane *this_00;
  void *pvVar2;
  ulong uVar3;
  J2DPicture *pJVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  byte bVar10;
  int iVar9;
  undefined4 *puVar11;
  undefined4 *puVar12;
  TBox2_float_ local_58;
  undefined4 local_48;
  undefined2 local_44;
  undefined2 local_42;
  undefined2 local_40;
  undefined2 local_3e;
  undefined local_3c;
  undefined local_3b;
  undefined local_3a;
  undefined local_39;
  undefined local_38;
  undefined local_37;
  undefined local_36;
  undefined local_35;
  undefined local_34;
  undefined local_33;
  undefined local_32;
  undefined local_31;
  
  if ((d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 == 0) ||
     (d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 == 9)) {
    *(JKRExpHeap **)(param_1 + 0xfc) = d_com_inf_game::g_dComIfG_gameInfo.field_0x5c1c;
    d_com_inf_game::g_dComIfG_gameInfo.field_0x5c02 = 9;
    uVar1 = m_Do_ext::mDoExt_setCurrentHeap(*(undefined4 *)(param_1 + 0xfc));
    this = (dmsg3_3d_c *)JKernel::operator_new(0x4c);
    if (this != (dmsg3_3d_c *)0x0) {
      ::dmsg3_3d_c::dmsg3_3d_c(this);
    }
    bVar10 = 0;
    msg3d = this;
    while( true ) {
      if (2 < bVar10) break;
      this_00 = (J2DPane *)JKernel::operator_new(0xd4);
      if (this_00 != (J2DPane *)0x0) {
        local_58.mTL.x = _4126;
        local_58.mTL.y = _4126;
        local_58.mBR.x = _5470;
        local_58.mBR.y = _5471;
        J2DPane::J2DPane(this_00,(J2DPane *)0x0,true,0x726f6f74,&local_58);
        this_00->vtbl = (J2DPane__vtable *)&J2DScreen::__vt;
        *(undefined4 *)this_00[1].mMagic = 0xffffffff;
        *(undefined *)&this_00[1].vtbl = 0;
      }
      (&sScreen3)[bVar10] = this_00;
      J2DScreen::set((J2DScreen *)(&sScreen3)[bVar10],"hukidashi_02.blo",
                     d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpMsgArchive);
      bVar10 = bVar10 + 1;
    }
    pvVar2 = JKRHeap::alloc(*(JKRHeap **)(param_1 + 0xfc),0x11800,0x20);
    *(void **)(param_1 + 0xe54) = pvVar2;
    if (*(int *)(param_1 + 0xe54) == 0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_message_paper.cpp",0x88c,"i_Msg->Tex[0] != 0");
      m_Do_printf::OSPanic("d_message_paper.cpp",0x88c,"Halt");
    }
    pvVar2 = JKRHeap::alloc(*(JKRHeap **)(param_1 + 0xfc),0x11800,0x20);
    *(void **)(param_1 + 0xe58) = pvVar2;
    if (*(int *)(param_1 + 0xe58) == 0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_message_paper.cpp",0x88e,"i_Msg->Tex[1] != 0");
      m_Do_printf::OSPanic("d_message_paper.cpp",0x88e,"Halt");
    }
    dMsg3_fontdataInit(param_1);
    bVar10 = 0;
    while( true ) {
      if (2 < bVar10) break;
      iVar8 = 0;
      iVar7 = 0;
      iVar9 = 0;
      puVar12 = &bbutton_icon3 + bVar10;
      puVar11 = &bbutton_kage3 + bVar10;
      do {
        pJVar4 = (J2DPicture *)JKernel::operator_new(0x124);
        if (pJVar4 != (J2DPicture *)0x0) {
          J2DPicture::J2DPicture(pJVar4,"font_07_02.bti");
        }
        *(J2DPicture **)((int)puVar12 + iVar9) = pJVar4;
        pJVar4 = (J2DPicture *)JKernel::operator_new(0x124);
        if (pJVar4 != (J2DPicture *)0x0) {
          J2DPicture::J2DPicture(pJVar4,"font_07_02.bti");
        }
        *(J2DPicture **)((int)puVar11 + iVar9) = pJVar4;
        f_op_msg_mng::fopMsgM_blendInit(*(undefined4 *)((int)puVar12 + iVar9),"font_00.bti");
        f_op_msg_mng::fopMsgM_blendInit(*(undefined4 *)((int)puVar11 + iVar9),"font_00.bti");
        *(undefined *)(*(int *)((int)puVar12 + iVar9) + 0xaa) = 0;
        *(undefined *)(*(int *)((int)puVar11 + iVar9) + 0xaa) = 0;
        *(undefined *)(*(int *)((int)puVar12 + iVar9) + 0xac) = 0;
        *(undefined *)(*(int *)((int)puVar11 + iVar9) + 0xac) = 0;
        *(undefined2 *)((int)&bbuttonTimer3 + iVar7 + (uint)bVar10 * 2) = 0xffff;
        iVar8 = iVar8 + 1;
        iVar7 = iVar7 + 6;
        iVar9 = iVar9 + 0xc;
      } while (iVar8 < 8);
      bVar10 = bVar10 + 1;
    }
    for (bVar10 = 0; bVar10 < 3; bVar10 = bVar10 + 1) {
      pvVar2 = JKRHeap::alloc(*(JKRHeap **)(param_1 + 0xfc),0x3e9,4);
      iVar9 = param_1 + (uint)bVar10 * 4;
      *(void **)(iVar9 + 0xe60) = pvVar2;
      if (*(int *)(iVar9 + 0xe60) == 0) {
        uVar3 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar3,"d_message_paper.cpp",0x8a5,"i_Msg->output_text[i] != 0");
        m_Do_printf::OSPanic("d_message_paper.cpp",0x8a5,"Halt");
      }
      pvVar2 = JKRHeap::alloc(*(JKRHeap **)(param_1 + 0xfc),0x3e9,4);
      *(void **)(iVar9 + 0xe6c) = pvVar2;
      if (*(int *)(iVar9 + 0xe6c) == 0) {
        uVar3 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar3,"d_message_paper.cpp",0x8a8,"i_Msg->output_ruby[i] != 0");
        m_Do_printf::OSPanic("d_message_paper.cpp",0x8a8,"Halt");
      }
      pvVar2 = JKRHeap::alloc(*(JKRHeap **)(param_1 + 0xfc),0x3e9,4);
      *(void **)(iVar9 + 0xe78) = pvVar2;
      if (*(int *)(iVar9 + 0xe78) == 0) {
        uVar3 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar3,"d_message_paper.cpp",0x8ab,"i_Msg->output_textSdw[i] != 0");
        m_Do_printf::OSPanic("d_message_paper.cpp",0x8ab,"Halt");
      }
      pvVar2 = JKRHeap::alloc(*(JKRHeap **)(param_1 + 0xfc),0x3e9,4);
      *(void **)(iVar9 + 0xe84) = pvVar2;
      if (*(int *)(iVar9 + 0xe84) == 0) {
        uVar3 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar3,"d_message_paper.cpp",0x8ae,"i_Msg->output_rubySdw[i] != 0");
        m_Do_printf::OSPanic("d_message_paper.cpp",0x8ae,"Halt");
      }
    }
    uVar5 = fopMsgM_msgGet_c::getMesgHeader
                      ((fopMsgM_msgGet_c *)(param_1 + 0x8f8),*(ulong *)(param_1 + 0xec));
    *(undefined4 *)(param_1 + 0x908) = uVar5;
    if (*(int *)(param_1 + 0x908) == 0) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_message_paper.cpp",0x8b3,"i_Msg->head_p");
      m_Do_printf::OSPanic("d_message_paper.cpp",0x8b3,"Halt");
    }
    uVar5 = fopMsgM_msgGet_c::getMessage
                      ((fopMsgM_msgGet_c *)(param_1 + 0x8f8),*(mesg_header **)(param_1 + 0x908));
    *(undefined4 *)(param_1 + 0xe5c) = uVar5;
    fopMsgM_msgGet_c::getMesgEntry((fopMsgM_msgGet_c *)&local_48,(mesg_header *)(param_1 + 0x8f8));
    *(undefined4 *)(param_1 + 0x100) = local_48;
    *(undefined2 *)(param_1 + 0x104) = local_44;
    *(undefined2 *)(param_1 + 0x106) = local_42;
    *(undefined2 *)(param_1 + 0x108) = local_40;
    *(undefined2 *)(param_1 + 0x10a) = local_3e;
    *(undefined *)(param_1 + 0x10c) = local_3c;
    *(undefined *)(param_1 + 0x10d) = local_3b;
    *(undefined *)(param_1 + 0x10e) = local_3a;
    *(undefined *)(param_1 + 0x10f) = local_39;
    *(undefined *)(param_1 + 0x110) = local_38;
    *(undefined *)(param_1 + 0x111) = local_37;
    *(undefined *)(param_1 + 0x112) = local_36;
    *(undefined *)(param_1 + 0x113) = local_35;
    *(undefined *)(param_1 + 0x114) = local_34;
    *(undefined *)(param_1 + 0x115) = local_33;
    *(undefined *)(param_1 + 0x116) = local_32;
    *(undefined *)(param_1 + 0x117) = local_31;
    *(uint *)(param_1 + 0xe9c) =
         (uint)*(ushort *)(param_1 + 0x900) << 8 | (uint)*(ushort *)(param_1 + 0x904);
    *(undefined2 *)(param_1 + 0xf8) = 2;
    dMsg3_multiTexInit(param_1);
    for (uVar6 = 0; (uVar6 & 0xff) < 3; uVar6 = uVar6 + 1) {
      dMsg3_screenDataInit(param_1,uVar6);
      dMsg3_screenDataSet(param_1,uVar6);
      dMsg3_messagePaneHide(param_1,uVar6);
    }
    dMsg3_ScreenDataValueInit(param_1);
    dMsg3_stickInfoInit(param_1);
    *(undefined *)(param_1 + 0xebc) = 0;
    *(undefined *)(param_1 + 0xe98) = 2;
    *(undefined *)(param_1 + 0xe99) = 0;
    *(undefined *)(param_1 + 0xe9a) = 1;
    dMsg3_popSpeed = (uint)DAT_803e6c17;
    m_Do_ext::mDoExt_setCurrentHeap(uVar1);
    d_com_inf_game::g_dComIfG_gameInfo.field_0x5bca = (byte)*(undefined2 *)(param_1 + 0xf8);
    uVar1 = 4;
    iRam803f706c = param_1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

}

/* __thiscall dDlst_2DMSG3_c::~dDlst_2DMSG3_c(void) */

void __thiscall dDlst_2DMSG3_c::_dDlst_2DMSG3_c(dDlst_2DMSG3_c *this)

{
  short in_r4;
  
  if (this != (dDlst_2DMSG3_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (this != (dDlst_2DMSG3_c *)0x0) {
      *(undefined ***)this = &dDlst_base_c::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


namespace d_message_paper {

void __sinit_d_message_paper_cpp(void)

{
  message = &::dDlst_2DMSG3_c::__vt;
  Runtime.PPCEABI.H::__register_global_object(&message,::dDlst_2DMSG3_c::_dDlst_2DMSG3_c,&_4175);
  board = &dDlst_2Dm_c::__vt;
  Runtime.PPCEABI.H::__register_global_object(&board,dDlst_2Dm_c::_dDlst_2Dm_c,&_4176);
  return;
}

