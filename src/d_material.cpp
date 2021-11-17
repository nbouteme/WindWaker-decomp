#include <d_material.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <m_Do_ext.h>
#include <J3DGraphBase/J3DMaterial.h>
#include <d_material.h>
#include <JKernel/JKRHeap.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <dMat_ice_c.h>
#include <mDoExt_btkAnm.h>
#include <dMat_control_c.h>
#include <dMat_backup_c.h>

undefined1 dMat_control_c;
undefined1 dMat_control_c;
undefined1 dMat_control_c;
undefined1 dMat_control_c;

/* __thiscall dMat_backup_c::restore(void) */

void __thiscall dMat_backup_c::restore(dMat_backup_c *this)

{
  ulong uVar1;
  
  if (*(int *)this == 0) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_material.cpp",0x52,"mModelData != 0");
    m_Do_printf::OSPanic("d_material.cpp",0x52,&DAT_80352537);
  }
  mDoExt_backupMaterial_c::restore((mDoExt_backupMaterial_c *)(this + 8),*(J3DModelData **)this);
  return;
}


/* __thiscall dMat_ice_c::create(J3DMaterialTable *,
                                 J3DAnmTextureSRTKey *) */

void __thiscall
dMat_ice_c::create(dMat_ice_c *this,J3DMaterialTable *param_1,J3DAnmTextureSRTKey *param_2)

{
  int iVar1;
  ulong uVar2;
  
  *(J3DMaterialTable **)this = param_1;
  iVar1 = ::mDoExt_btkAnm::init
                    ((mDoExt_btkAnm *)(this + 4),*(J3DMaterialTable **)this,param_2,true,Repeat,
                     d_material::_4001,0,-1,false,0);
  if (iVar1 == 0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_material.cpp",0x62,"rt != 0");
    m_Do_printf::OSPanic("d_material.cpp",0x62,&DAT_80352537);
  }
  ::mDoExt_btkAnm::entry
            ((mDoExt_btkAnm *)(this + 4),*(J3DMaterialTable **)this,
             *(float *)(*(int *)(this + 8) + 0x10));
  return;
}


/* __thiscall dMat_ice_c::play(void) */

void __thiscall dMat_ice_c::play(dMat_ice_c *this)

{
  ::mDoExt_baseAnm::play((mDoExt_baseAnm *)(this + 4));
  *(undefined4 *)(*(int *)(this + 0xc) + 8) = *(undefined4 *)(*(int *)(this + 8) + 0x10);
  return;
}


/* WARNING: Inlined function: FUN_80328f34 */
/* WARNING: Inlined function: FUN_80328f80 */
/* WARNING: Type propagation algorithm not settling */
/* __thiscall dMat_ice_c::copy(J3DModelData *) */

int __thiscall dMat_ice_c::copy(dMat_ice_c *this,EVP_PKEY_CTX *dst,EVP_PKEY_CTX *src)

{
  J3DMaterialAnm *pJVar1;
  short *psVar2;
  ushort uVar3;
  J3DMaterial *this_00;
  J3DMaterial *src_00;
  
  src_00 = (J3DMaterial *)(*(J3DMaterial **)(*(int *)this + 8))->vtbl;
  for (uVar3 = 0; uVar3 < *(ushort *)(dst + 0x5c); uVar3 = uVar3 + 1) {
    this_00 = *(J3DMaterial **)(*(int *)(dst + 0x60) + (uint)uVar3 * 4);
    J3DMaterial::copy(this_00,src_00);
    pJVar1 = src_00->mpMaterialAnm;
    if ((J3DMaterialAnm *)0xbfffffff < pJVar1) {
      pJVar1 = (J3DMaterialAnm *)0x0;
    }
    this_00->mpMaterialAnm = pJVar1;
    this_00->mMaterialMode = src_00->mMaterialMode;
  }
  psVar2 = *(short **)(*(int *)this + 0x18);
  if (*psVar2 != 0) {
    *(short **)(dst + 0x70) = psVar2;
    psVar2 = *(short **)this;
    *(undefined4 *)(dst + 0x74) = *(undefined4 *)(psVar2 + 0xe);
  }
  return (int)psVar2;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall dMat_ice_c::updateDL(J3DModel *,
                                   signed char,
                                   mDoExt_invisibleModel *) */

void __thiscall
dMat_ice_c::updateDL(dMat_ice_c *this,J3DModel *param_1,char param_2,mDoExt_invisibleModel *param_3)

{
  J3DDrawBuffer *pJVar1;
  J3DDrawBuffer *pJVar2;
  J3DModelData *pJVar3;
  undefined3 in_register_00000014;
  dMat_control_c *this_00;
  dMat_control_c *src;
  J3DModelData *dst;
  char cVar4;
  
  pJVar2 = J3DGraphBase::j3dSys.mpCurDrawBuffers[1];
  pJVar1 = J3DGraphBase::j3dSys.mpCurDrawBuffers[0];
  this_00 = (dMat_control_c *)CONCAT31(in_register_00000014,param_2);
  dst = param_1->mpModelData;
  src = this_00;
  if (param_2 < '\0') {
    mDoExt_backupMaterial_c::create((mDoExt_backupMaterial_c *)&dMat_control_c::mTempBackup,dst);
  }
  J3DGraphBase::j3dSys.mpCurDrawBuffers[0] =
       d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelOpa;
  J3DGraphBase::j3dSys.mpCurDrawBuffers[1] =
       d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelXlu;
  pJVar3 = dst;
  copy(this,(EVP_PKEY_CTX *)dst,(EVP_PKEY_CTX *)src);
  cVar4 = (char)pJVar3;
  m_Do_ext::mDoExt_modelUpdateDL(param_1);
  if (param_2 < '\0') {
    mDoExt_backupMaterial_c::restore((mDoExt_backupMaterial_c *)&dMat_control_c::mTempBackup,dst);
  }
  else {
    dMat_control_c::restore(this_00,cVar4);
  }
  if (param_3 != (mDoExt_invisibleModel *)0x0) {
    mDoExt_invisibleModel::entry(param_3);
  }
  J3DGraphBase::j3dSys.mpCurDrawBuffers[0] = pJVar1;
  J3DGraphBase::j3dSys.mpCurDrawBuffers[1] = pJVar2;
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall dMat_ice_c::updateDL(mDoExt_McaMorf *,
                                   signed char,
                                   mDoExt_invisibleModel *) */

void __thiscall
dMat_ice_c::updateDL
          (dMat_ice_c *this,mDoExt_McaMorf *param_1,char param_2,mDoExt_invisibleModel *param_3)

{
  J3DDrawBuffer *pJVar1;
  J3DDrawBuffer *pJVar2;
  char extraout_r4;
  undefined3 in_register_00000014;
  dMat_control_c *this_00;
  dMat_control_c *src;
  J3DModelData *dst;
  
  pJVar2 = J3DGraphBase::j3dSys.mpCurDrawBuffers[1];
  pJVar1 = J3DGraphBase::j3dSys.mpCurDrawBuffers[0];
  this_00 = (dMat_control_c *)CONCAT31(in_register_00000014,param_2);
  dst = param_1->mpModel->mpModelData;
  src = this_00;
  if (param_2 < '\0') {
    mDoExt_backupMaterial_c::create((mDoExt_backupMaterial_c *)&dMat_control_c::mTempBackup,dst);
  }
  J3DGraphBase::j3dSys.mpCurDrawBuffers[0] =
       d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelOpa;
  J3DGraphBase::j3dSys.mpCurDrawBuffers[1] =
       d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelXlu;
  copy(this,(EVP_PKEY_CTX *)dst,(EVP_PKEY_CTX *)src);
  mDoExt_McaMorf::updateDL(param_1);
  if (param_2 < '\0') {
    mDoExt_backupMaterial_c::restore((mDoExt_backupMaterial_c *)&dMat_control_c::mTempBackup,dst);
  }
  else {
    dMat_control_c::restore(this_00,extraout_r4);
  }
  if (param_3 != (mDoExt_invisibleModel *)0x0) {
    mDoExt_invisibleModel::entry(param_3);
  }
  J3DGraphBase::j3dSys.mpCurDrawBuffers[0] = pJVar1;
  J3DGraphBase::j3dSys.mpCurDrawBuffers[1] = pJVar2;
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall dMat_ice_c::entryDL(J3DModel *,
                                  signed char,
                                  mDoExt_invisibleModel *) */

void __thiscall
dMat_ice_c::entryDL(dMat_ice_c *this,J3DModel *param_1,char param_2,mDoExt_invisibleModel *param_3)

{
  J3DDrawBuffer *pJVar1;
  J3DDrawBuffer *pJVar2;
  J3DModelData *pJVar3;
  undefined3 in_register_00000014;
  dMat_control_c *this_00;
  dMat_control_c *src;
  J3DModelData *dst;
  char cVar4;
  
  pJVar2 = J3DGraphBase::j3dSys.mpCurDrawBuffers[1];
  pJVar1 = J3DGraphBase::j3dSys.mpCurDrawBuffers[0];
  this_00 = (dMat_control_c *)CONCAT31(in_register_00000014,param_2);
  dst = param_1->mpModelData;
  src = this_00;
  if (param_2 < '\0') {
    mDoExt_backupMaterial_c::create((mDoExt_backupMaterial_c *)&dMat_control_c::mTempBackup,dst);
  }
  J3DGraphBase::j3dSys.mpCurDrawBuffers[0] =
       d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelOpa;
  J3DGraphBase::j3dSys.mpCurDrawBuffers[1] =
       d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelXlu;
  pJVar3 = dst;
  copy(this,(EVP_PKEY_CTX *)dst,(EVP_PKEY_CTX *)src);
  cVar4 = (char)pJVar3;
  m_Do_ext::mDoExt_modelEntryDL(param_1);
  if (param_2 < '\0') {
    mDoExt_backupMaterial_c::restore((mDoExt_backupMaterial_c *)&dMat_control_c::mTempBackup,dst);
  }
  else {
    dMat_control_c::restore(this_00,cVar4);
  }
  if (param_3 != (mDoExt_invisibleModel *)0x0) {
    mDoExt_invisibleModel::entry(param_3);
  }
  J3DGraphBase::j3dSys.mpCurDrawBuffers[0] = pJVar1;
  J3DGraphBase::j3dSys.mpCurDrawBuffers[1] = pJVar2;
  return;
}


/* WARNING: Inlined function: FUN_80328f2c */
/* WARNING: Inlined function: FUN_80328f78 */
/* __thiscall dMat_ice_c::entryDL(mDoExt_McaMorf *,
                                  signed char,
                                  mDoExt_invisibleModel *) */

void __thiscall
dMat_ice_c::entryDL(dMat_ice_c *this,mDoExt_McaMorf *param_1,char param_2,
                   mDoExt_invisibleModel *param_3)

{
  J3DDrawBuffer *pJVar1;
  J3DDrawBuffer *pJVar2;
  char extraout_r4;
  undefined3 in_register_00000014;
  dMat_control_c *this_00;
  dMat_control_c *src;
  J3DModelData *dst;
  
  pJVar2 = J3DGraphBase::j3dSys.mpCurDrawBuffers[1];
  pJVar1 = J3DGraphBase::j3dSys.mpCurDrawBuffers[0];
  this_00 = (dMat_control_c *)CONCAT31(in_register_00000014,param_2);
  dst = param_1->mpModel->mpModelData;
  src = this_00;
  if (param_2 < '\0') {
    mDoExt_backupMaterial_c::create((mDoExt_backupMaterial_c *)&dMat_control_c::mTempBackup,dst);
  }
  J3DGraphBase::j3dSys.mpCurDrawBuffers[0] =
       d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelOpa;
  J3DGraphBase::j3dSys.mpCurDrawBuffers[1] =
       d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelXlu;
  copy(this,(EVP_PKEY_CTX *)dst,(EVP_PKEY_CTX *)src);
  mDoExt_McaMorf::entryDL(param_1);
  if (param_2 < '\0') {
    mDoExt_backupMaterial_c::restore((mDoExt_backupMaterial_c *)&dMat_control_c::mTempBackup,dst);
  }
  else {
    dMat_control_c::restore(this_00,extraout_r4);
  }
  if (param_3 != (mDoExt_invisibleModel *)0x0) {
    mDoExt_invisibleModel::entry(param_3);
  }
  J3DGraphBase::j3dSys.mpCurDrawBuffers[0] = pJVar1;
  J3DGraphBase::j3dSys.mpCurDrawBuffers[1] = pJVar2;
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dMat_control_c::create(J3DMaterialTable *,
                                     J3DAnmTextureSRTKey *) */

void __thiscall
dMat_control_c::create(dMat_control_c *this,J3DMaterialTable *param_1,J3DAnmTextureSRTKey *param_2)

{
  bool bVar1;
  ulong uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  bool in_r6;
  
  _mHeap = (JKRSolidHeap *)m_Do_ext::mDoExt_createSolidHeapFromSystem(0,0,param_2,in_r6);
  if (_mHeap == (JKRSolidHeap *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_material.cpp",0x134,"mHeap != 0");
    m_Do_printf::OSPanic("d_material.cpp",0x134,&DAT_80352537);
  }
  uVar3 = m_Do_ext::mDoExt_setCurrentHeap(_mHeap);
  uVar4 = JKernel::operator_new__(0x150);
  _mBackup = Runtime.PPCEABI.H::__construct_new_array
                       (uVar4,dMat_backup_c::dMat_backup_c,dMat_backup_c::_dMat_backup_c,0x14,0x10);
  _mIce = (dMat_ice_c *)JKernel::operator_new(0x18);
  if (_mIce != (dMat_ice_c *)0x0) {
    *(undefined ***)(_mIce + 4) = &::mDoExt_baseAnm::__vt;
    *(undefined4 *)(_mIce + 8) = 0;
    *(undefined ***)(_mIce + 4) = &::mDoExt_btkAnm::__vt;
    *(undefined4 *)(_mIce + 0x10) = 0;
  }
  bVar1 = false;
  if ((_mBackup != 0) && (_mIce != (dMat_ice_c *)0x0)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_material.cpp",0x139,"mBackup != 0 && mIce != 0");
    m_Do_printf::OSPanic("d_material.cpp",0x139,&DAT_80352537);
  }
  dMat_ice_c::create(_mIce,(J3DMaterialTable *)this,(J3DAnmTextureSRTKey *)param_1);
  mDoExt_backupMaterial_c::create((mDoExt_backupMaterial_c *)&mTempBackup,0x40);
  m_Do_ext::mDoExt_adjustSolidHeap(_mHeap);
  m_Do_ext::mDoExt_setCurrentHeap(uVar3);
  return;
}


/* __thiscall mDoExt_btkAnm::~mDoExt_btkAnm(void) */

void __thiscall mDoExt_btkAnm::_mDoExt_btkAnm(mDoExt_btkAnm *this)

{
  short in_r4;
  
  if (this != (mDoExt_btkAnm *)0x0) {
    (this->parent).vtbl = (mDoExt_baseAnm__vtbl *)&__vt;
    if (this != (mDoExt_btkAnm *)0x0) {
      (this->parent).vtbl = (mDoExt_baseAnm__vtbl *)&::mDoExt_baseAnm::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dMat_backup_c::~dMat_backup_c(void) */

void __thiscall dMat_backup_c::_dMat_backup_c(dMat_backup_c *this)

{
  short in_r4;
  
  if ((this != (dMat_backup_c *)0x0) && (0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall dMat_backup_c::dMat_backup_c(void) */

void __thiscall dMat_backup_c::dMat_backup_c(dMat_backup_c *this)

{
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)this = 0;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dMat_control_c::remove(void) */

int __thiscall dMat_control_c::remove(dMat_control_c *this,char *__filename)

{
  int iVar1;
  
  iVar1 = m_Do_ext::mDoExt_destroySolidHeap(_mHeap);
  return iVar1;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dMat_control_c::restore(signed char) */

void __thiscall dMat_control_c::restore(dMat_control_c *this,char param_1)

{
  if (-1 < (char)this) {
    dMat_backup_c::restore((dMat_backup_c *)(_mBackup + (char)this * 0x14));
  }
  return;
}


namespace d_material {

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __sinit_d_material_cpp(void)

{
  _mTempBackup = 0;
  return;
}

