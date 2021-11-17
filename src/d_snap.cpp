#include <d_snap.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <mtx/mtx.h>
#include <m_Do_mtx.h>
#include <mtx/mtxvec.h>
#include <m_Do_lib.h>
#include <gx/GXAttr.h>
#include <gx/GXTransform.h>
#include <gx/GXGeometry.h>
#include <mtx/vec.h>
#include <SComponent/c_math.h>
#include <SComponent/c_lib.h>
#include <d_snap.h>
#include <gx/GXLight.h>
#include <gx/GXBump.h>
#include <gx/GXTev.h>
#include <gx/GXPixel.h>
#include <J3DGraphBase/J3DSys.h>
#include <mtx/mtx44.h>
#include <gx/GXMisc.h>
#include <Runtime.PPCEABI.H/ptmf.h>
#include <J3DGraphBase/J3DDrawBuffer.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <JKernel/JKRHeap.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <dSnap_packet.h>
#include <dSnap_RegistObjElm.h>
#include <dSnap_Obj.h>


namespace d_snap {
undefined4 l_snap;

/* __stdcall dSnap_PhotoIndex2TableIndex(int) */

int dSnap_PhotoIndex2TableIndex(int param_1)

{
  bool bVar1;
  ulong uVar2;
  int iVar3;
  
  iVar3 = param_1 + -0x49;
  bVar1 = false;
  if ((-1 < iVar3) && (iVar3 < 0x86)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_snap.cpp",0x14e,"index >= 0 && index < CharaDataTblSize");
    m_Do_printf::OSPanic("d_snap.cpp",0x14e,&DAT_8035b73e);
  }
  return iVar3;
}


/* __stdcall dSnap_GetFigRoomId(int) */

byte dSnap_GetFigRoomId(int figure)

{
  if (0x85 < figure) {
    return 0xff;
  }
  return l_CharaData[figure].mFigRoomId;
}

}

/* __thiscall dSnap_Obj::dSnap_Obj(void) */

void __thiscall dSnap_Obj::dSnap_Obj(dSnap_Obj *this)

{
  this->vtbl = (undefined *)&__vt;
  this->mBsPcId = -1;
  this->field_0x18 = 0;
  this->field_0x19 = 4;
  this->field_0x1a = 0xff;
  this->field_0x1b = 0;
  this->field_0x1c = 0x7fff;
  this->field_0x1e = 0;
  this->field_0x20 = 0;
  this->field_0x24 = d_snap::_4141;
  this->field_0x28 = 0;
  this->field_0x2a = 0;
  this->field_0x2c = 0;
  this->field_0x2e = 0;
  return;
}


/* WARNING: Inlined function: FUN_80328f10 */
/* WARNING: Inlined function: FUN_80328f5c */
/* WARNING: Removing unreachable block (ram,0x800cd6a8) */
/* WARNING: Removing unreachable block (ram,0x800cd698) */
/* WARNING: Removing unreachable block (ram,0x800cd6a0) */
/* WARNING: Removing unreachable block (ram,0x800cd6b0) */
/* __thiscall dSnap_Obj::CalcArea2D(void) */

double __thiscall dSnap_Obj::CalcArea2D(dSnap_Obj *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  double dVar5;
  undefined8 in_f28;
  double dVar6;
  undefined8 in_f29;
  double dVar7;
  undefined8 in_f30;
  double dVar8;
  undefined8 in_f31;
  double dVar9;
  cXyz local_118;
  cXyz local_10c;
  cXyz local_100;
  cXyz local_f4;
  cXyz local_e8;
  cXyz local_dc;
  cXyz local_d0;
  cXyz local_c4;
  cXyz local_b8;
  cXyz local_ac;
  cXyz cStack160;
  cXyz local_94 [2];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar4 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  dVar6 = (double)d_snap::_4141;
  dVar7 = (double)this->field_0xc;
  dVar8 = (double)this->field_0x10;
  if ((this->field_0x1b & 1) == 0) {
    mtx::PSMTXTrans((double)(this->field_0x0).x,(double)(this->field_0x0).y,
                    (double)(this->field_0x0).z,&mDoMtx_stack_c::now);
    mDoMtx_stack_c::scaleM((float)dVar7,(float)dVar8,(float)dVar7);
    m_Do_mtx::mDoMtx_YrotM(&mDoMtx_stack_c::now,this->field_0x1e);
    local_dc.x = d_snap::_4141;
    local_dc.y = d_snap::_4141;
    local_dc.z = d_snap::_4141;
    mtx::PSMTXMultVec(&mDoMtx_stack_c::now,&local_dc,&local_dc);
    local_e8.x = d_snap::_4141;
    local_e8.y = d_snap::_4335;
    local_e8.z = d_snap::_4141;
    mtx::PSMTXMultVec(&mDoMtx_stack_c::now,&local_e8,&local_e8);
    iVar2 = 0;
    dVar7 = (double)d_snap::_4141;
    dVar8 = (double)d_snap::_4335;
    dVar9 = (double)d_snap::_4336;
    for (iVar3 = 0; iVar3 < (int)(uint)this->field_0x19; iVar3 = iVar3 + 1) {
      local_94[0].x = *(float *)((int)&d_snap::cylvtx + iVar2);
      local_94[0].y = (float)dVar7;
      local_94[0].z = *(float *)((int)&DAT_8035b558 + iVar2);
      mtx::PSMTXMultVec(&mDoMtx_stack_c::now,local_94,&cStack160);
      m_Do_lib::mDoLib_project(&cStack160,&local_ac);
      local_94[0].y = (float)dVar8;
      mtx::PSMTXMultVec(&mDoMtx_stack_c::now,local_94,&cStack160);
      m_Do_lib::mDoLib_project(&cStack160,&local_b8);
      local_94[0].x = *(float *)((int)&DAT_8035b55c + iVar2);
      local_94[0].z = *(float *)((int)&DAT_8035b564 + iVar2);
      mtx::PSMTXMultVec(&mDoMtx_stack_c::now,local_94,&cStack160);
      m_Do_lib::mDoLib_project(&cStack160,&local_c4);
      local_94[0].y = (float)dVar7;
      mtx::PSMTXMultVec(&mDoMtx_stack_c::now,local_94,&cStack160);
      m_Do_lib::mDoLib_project(&cStack160,&local_d0);
      dVar5 = (double)(float)(dVar9 * (double)((local_b8.x - local_ac.x) * (local_c4.y - local_ac.y)
                                              - (local_b8.y - local_ac.y) *
                                                (local_c4.x - local_ac.x)));
      if (dVar7 < dVar5) {
        dVar6 = (double)(float)(dVar6 + dVar5);
      }
      dVar5 = (double)(float)(dVar9 * (double)((local_c4.x - local_ac.x) * (local_d0.y - local_ac.y)
                                              - (local_c4.y - local_ac.y) *
                                                (local_d0.x - local_ac.x)));
      if (dVar7 < dVar5) {
        dVar6 = (double)(float)(dVar6 + dVar5);
      }
      m_Do_lib::mDoLib_project(&local_e8,&local_f4);
      dVar5 = (double)(float)(dVar9 * (double)((local_c4.x - local_f4.x) * (local_b8.y - local_f4.y)
                                              - (local_c4.y - local_f4.y) *
                                                (local_b8.x - local_f4.x)));
      if (dVar7 < dVar5) {
        dVar6 = (double)(float)(dVar6 + dVar5);
      }
      m_Do_lib::mDoLib_project(&local_dc,&local_100);
      dVar5 = (double)(float)(dVar9 * (double)((local_ac.x - local_100.x) *
                                               (local_d0.y - local_100.y) -
                                              (local_ac.y - local_100.y) *
                                              (local_d0.x - local_100.x)));
      if (dVar7 < dVar5) {
        dVar6 = (double)(float)(dVar6 + dVar5);
      }
      local_94[0].x = -*(float *)((int)&d_snap::cylvtx + iVar2);
      local_94[0].y = (float)dVar8;
      local_94[0].z = *(float *)((int)&DAT_8035b558 + iVar2);
      mtx::PSMTXMultVec(&mDoMtx_stack_c::now,local_94,&cStack160);
      m_Do_lib::mDoLib_project(&cStack160,&local_ac);
      local_94[0].y = (float)dVar7;
      mtx::PSMTXMultVec(&mDoMtx_stack_c::now,local_94,&cStack160);
      m_Do_lib::mDoLib_project(&cStack160,&local_b8);
      local_94[0].x = -*(float *)((int)&DAT_8035b55c + iVar2);
      local_94[0].z = *(float *)((int)&DAT_8035b564 + iVar2);
      mtx::PSMTXMultVec(&mDoMtx_stack_c::now,local_94,&cStack160);
      m_Do_lib::mDoLib_project(&cStack160,&local_c4);
      local_94[0].y = (float)dVar8;
      mtx::PSMTXMultVec(&mDoMtx_stack_c::now,local_94,&cStack160);
      m_Do_lib::mDoLib_project(&cStack160,&local_d0);
      dVar5 = (double)(float)(dVar9 * (double)((local_b8.x - local_ac.x) * (local_c4.y - local_ac.y)
                                              - (local_b8.y - local_ac.y) *
                                                (local_c4.x - local_ac.x)));
      if (dVar7 < dVar5) {
        dVar6 = (double)(float)(dVar6 + dVar5);
      }
      dVar5 = (double)(float)(dVar9 * (double)((local_c4.x - local_ac.x) * (local_d0.y - local_ac.y)
                                              - (local_c4.y - local_ac.y) *
                                                (local_d0.x - local_ac.x)));
      if (dVar7 < dVar5) {
        dVar6 = (double)(float)(dVar6 + dVar5);
      }
      m_Do_lib::mDoLib_project(&local_e8,&local_10c);
      dVar5 = (double)(float)(dVar9 * (double)((local_ac.x - local_10c.x) *
                                               (local_d0.y - local_10c.y) -
                                              (local_ac.y - local_10c.y) *
                                              (local_d0.x - local_10c.x)));
      if (dVar7 < dVar5) {
        dVar6 = (double)(float)(dVar6 + dVar5);
      }
      m_Do_lib::mDoLib_project(&local_dc,&local_118);
      dVar5 = (double)(float)(dVar9 * (double)((local_c4.x - local_118.x) *
                                               (local_b8.y - local_118.y) -
                                              (local_c4.y - local_118.y) *
                                              (local_b8.x - local_118.x)));
      if (dVar7 < dVar5) {
        dVar6 = (double)(float)(dVar6 + dVar5);
      }
      iVar2 = iVar2 + 0xc;
    }
  }
  else {
    mtx::PSMTXTrans((double)(this->field_0x0).x,(double)(this->field_0x0).y,
                    (double)(this->field_0x0).z,&mDoMtx_stack_c::now);
    mDoMtx_stack_c::scaleM((float)dVar7,(float)dVar7,(float)dVar7);
    iVar3 = 0;
    iVar2 = 0;
    dVar8 = (double)d_snap::_4336;
    dVar7 = (double)d_snap::_4141;
    do {
      iVar1 = *(int *)((int)&d_snap::tindices + iVar2) * 0xc;
      local_94[0].x = *(float *)(&d_snap::vdata + iVar1);
      local_94[0].y = *(float *)(&DAT_8035b590 + iVar1);
      local_94[0].z = *(float *)(&DAT_8035b594 + iVar1);
      mtx::PSMTXMultVec(&mDoMtx_stack_c::now,local_94,&cStack160);
      m_Do_lib::mDoLib_project(&cStack160,&local_ac);
      iVar1 = *(int *)((int)&DAT_8035b620 + iVar2) * 0xc;
      local_94[0].x = *(float *)(&d_snap::vdata + iVar1);
      local_94[0].y = *(float *)(&DAT_8035b590 + iVar1);
      local_94[0].z = *(float *)(&DAT_8035b594 + iVar1);
      mtx::PSMTXMultVec(&mDoMtx_stack_c::now,local_94,&cStack160);
      m_Do_lib::mDoLib_project(&cStack160,&local_b8);
      iVar1 = *(int *)((int)&DAT_8035b624 + iVar2) * 0xc;
      local_94[0].x = *(float *)(&d_snap::vdata + iVar1);
      local_94[0].y = *(float *)(&DAT_8035b590 + iVar1);
      local_94[0].z = *(float *)(&DAT_8035b594 + iVar1);
      mtx::PSMTXMultVec(&mDoMtx_stack_c::now,local_94,&cStack160);
      m_Do_lib::mDoLib_project(&cStack160,&local_c4);
      dVar9 = (double)(float)(dVar8 * (double)((local_b8.x - local_ac.x) * (local_c4.y - local_ac.y)
                                              - (local_b8.y - local_ac.y) *
                                                (local_c4.x - local_ac.x)));
      if (dVar7 < dVar9) {
        dVar6 = (double)(float)(dVar6 + dVar9);
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0xc;
    } while (iVar3 < 0x14);
  }
  __psq_l0(auStack8,uVar4);
  __psq_l1(auStack8,uVar4);
  __psq_l0(auStack24,uVar4);
  __psq_l1(auStack24,uVar4);
  __psq_l0(auStack40,uVar4);
  __psq_l1(auStack40,uVar4);
  __psq_l0(auStack56,uVar4);
  __psq_l1(auStack56,uVar4);
  return dVar6;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x800cdad0) */
/* WARNING: Removing unreachable block (ram,0x800cdad8) */
/* __thiscall dSnap_Obj::draw(void) */

void __thiscall dSnap_Obj::draw(dSnap_Obj *this)

{
  float fVar1;
  undefined4 uVar2;
  float fVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
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
  if ((this->field_0x1b & 1) == 0) {
    dVar10 = (double)this->field_0xc;
    dVar9 = (double)this->field_0x10;
    mtx::PSMTXCopy(&J3DGraphBase::j3dSys.mCurViewMtx,&mDoMtx_stack_c::now);
    mDoMtx_stack_c::transM((this->field_0x0).x,(this->field_0x0).y,(this->field_0x0).z);
    mDoMtx_stack_c::scaleM((float)dVar10,(float)dVar9,(float)dVar10);
    gx::GXClearVtxDesc();
    gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
    gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_F32,0);
    m_Do_mtx::mDoMtx_YrotM(&mDoMtx_stack_c::now,this->field_0x1e);
    gx::GXLoadPosMtxImm(&mDoMtx_stack_c::now,0);
    gx::GXSetCurrentMtx(0);
    gx::GXBegin(0x80,0,(uint)this->field_0x19 << 3);
    iVar6 = 0;
    for (iVar7 = 0; iVar7 < (int)(uint)this->field_0x19; iVar7 = iVar7 + 1) {
      fVar1 = *(float *)((int)&d_snap::cylvtx + iVar6);
      write_volatile_4(0xcc008000,fVar1);
      write_volatile_4(0xcc008000,d_snap::_4141);
      uVar2 = *(undefined4 *)((int)&DAT_8035b558 + iVar6);
      write_volatile_4(0xcc008000,uVar2);
      write_volatile_4(0xcc008000,fVar1);
      write_volatile_4(0xcc008000,d_snap::_4335);
      write_volatile_4(0xcc008000,uVar2);
      fVar3 = *(float *)((int)&DAT_8035b55c + iVar6);
      write_volatile_4(0xcc008000,fVar3);
      write_volatile_4(0xcc008000,d_snap::_4335);
      uVar4 = *(undefined4 *)((int)&DAT_8035b564 + iVar6);
      write_volatile_4(0xcc008000,uVar4);
      write_volatile_4(0xcc008000,fVar3);
      write_volatile_4(0xcc008000,d_snap::_4141);
      write_volatile_4(0xcc008000,uVar4);
      write_volatile_4(0xcc008000,-fVar1);
      write_volatile_4(0xcc008000,d_snap::_4335);
      write_volatile_4(0xcc008000,uVar2);
      write_volatile_4(0xcc008000,-fVar1);
      write_volatile_4(0xcc008000,d_snap::_4141);
      write_volatile_4(0xcc008000,uVar2);
      write_volatile_4(0xcc008000,-fVar3);
      write_volatile_4(0xcc008000,d_snap::_4141);
      write_volatile_4(0xcc008000,uVar4);
      write_volatile_4(0xcc008000,-fVar3);
      write_volatile_4(0xcc008000,d_snap::_4335);
      write_volatile_4(0xcc008000,uVar4);
      iVar6 = iVar6 + 0xc;
    }
    gx::GXBegin(0x90,0,(uint)this->field_0x19 * 0xc);
    iVar6 = 0;
    for (iVar7 = 0; iVar7 < (int)(uint)this->field_0x19; iVar7 = iVar7 + 1) {
      write_volatile_4(0xcc008000,d_snap::_4141);
      write_volatile_4(0xcc008000,d_snap::_4335);
      write_volatile_4(0xcc008000,d_snap::_4141);
      fVar1 = *(float *)((int)&DAT_8035b55c + iVar6);
      write_volatile_4(0xcc008000,fVar1);
      write_volatile_4(0xcc008000,d_snap::_4335);
      uVar2 = *(undefined4 *)((int)&DAT_8035b564 + iVar6);
      write_volatile_4(0xcc008000,uVar2);
      fVar3 = *(float *)((int)&d_snap::cylvtx + iVar6);
      write_volatile_4(0xcc008000,fVar3);
      write_volatile_4(0xcc008000,d_snap::_4335);
      uVar4 = *(undefined4 *)((int)&DAT_8035b558 + iVar6);
      write_volatile_4(0xcc008000,uVar4);
      write_volatile_4(0xcc008000,d_snap::_4141);
      write_volatile_4(0xcc008000,d_snap::_4141);
      write_volatile_4(0xcc008000,d_snap::_4141);
      write_volatile_4(0xcc008000,fVar3);
      write_volatile_4(0xcc008000,d_snap::_4141);
      write_volatile_4(0xcc008000,uVar4);
      write_volatile_4(0xcc008000,fVar1);
      write_volatile_4(0xcc008000,d_snap::_4141);
      write_volatile_4(0xcc008000,uVar2);
      write_volatile_4(0xcc008000,d_snap::_4141);
      write_volatile_4(0xcc008000,d_snap::_4335);
      write_volatile_4(0xcc008000,d_snap::_4141);
      write_volatile_4(0xcc008000,-fVar3);
      write_volatile_4(0xcc008000,d_snap::_4335);
      write_volatile_4(0xcc008000,uVar4);
      write_volatile_4(0xcc008000,-fVar1);
      write_volatile_4(0xcc008000,d_snap::_4335);
      write_volatile_4(0xcc008000,uVar2);
      write_volatile_4(0xcc008000,d_snap::_4141);
      write_volatile_4(0xcc008000,d_snap::_4141);
      write_volatile_4(0xcc008000,d_snap::_4141);
      write_volatile_4(0xcc008000,-fVar1);
      write_volatile_4(0xcc008000,d_snap::_4141);
      write_volatile_4(0xcc008000,uVar2);
      write_volatile_4(0xcc008000,-fVar3);
      write_volatile_4(0xcc008000,d_snap::_4141);
      write_volatile_4(0xcc008000,uVar4);
      iVar6 = iVar6 + 0xc;
    }
  }
  else {
    dVar9 = (double)this->field_0xc;
    mtx::PSMTXCopy(&J3DGraphBase::j3dSys.mCurViewMtx,&mDoMtx_stack_c::now);
    mDoMtx_stack_c::transM((this->field_0x0).x,(this->field_0x0).y,(this->field_0x0).z);
    mDoMtx_stack_c::scaleM((float)dVar9,(float)dVar9,(float)dVar9);
    gx::GXClearVtxDesc();
    gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
    gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_F32,0);
    gx::GXLoadPosMtxImm(&mDoMtx_stack_c::now,0);
    gx::GXSetCurrentMtx(0);
    iVar6 = 0;
    iVar7 = 0;
    do {
      gx::GXBegin(0x90,0,3);
      iVar5 = *(int *)((int)&d_snap::tindices + iVar7) * 0xc;
      write_volatile_4(0xcc008000,*(undefined4 *)(&d_snap::vdata + iVar5));
      write_volatile_4(0xcc008000,*(undefined4 *)(&DAT_8035b590 + iVar5));
      write_volatile_4(0xcc008000,*(undefined4 *)(&DAT_8035b594 + iVar5));
      iVar5 = *(int *)((int)&DAT_8035b620 + iVar7) * 0xc;
      write_volatile_4(0xcc008000,*(undefined4 *)(&d_snap::vdata + iVar5));
      write_volatile_4(0xcc008000,*(undefined4 *)(&DAT_8035b590 + iVar5));
      write_volatile_4(0xcc008000,*(undefined4 *)(&DAT_8035b594 + iVar5));
      iVar5 = *(int *)((int)&DAT_8035b624 + iVar7) * 0xc;
      write_volatile_4(0xcc008000,*(undefined4 *)(&d_snap::vdata + iVar5));
      write_volatile_4(0xcc008000,*(undefined4 *)(&DAT_8035b590 + iVar5));
      write_volatile_4(0xcc008000,*(undefined4 *)(&DAT_8035b594 + iVar5));
      iVar6 = iVar6 + 1;
      iVar7 = iVar7 + 0xc;
    } while (iVar6 < 0x14);
  }
  __psq_l0(auStack8,uVar8);
  __psq_l1(auStack8,uVar8);
  __psq_l0(auStack24,uVar8);
  __psq_l1(auStack24,uVar8);
  return;
}


/* __thiscall dSnap_Obj::SetGeo(Vec const &,
                                float,
                                float,
                                short) */

void __thiscall
dSnap_Obj::SetGeo(dSnap_Obj *this,cXyz *param_1,float param_2,float param_3,short param_4)

{
  this->field_0x1b = this->field_0x1b & 0xfe;
  (this->field_0x0).x = param_1->x;
  (this->field_0x0).y = param_1->y;
  (this->field_0x0).z = param_1->z;
  this->field_0xc = param_2;
  this->field_0x10 = param_3;
  this->field_0x1e = param_4;
  return;
}


/* __thiscall dSnap_Obj::SetGeoSph(Vec const &,
                                   float) */

void __thiscall dSnap_Obj::SetGeoSph(dSnap_Obj *this,Vec *param_1,float param_2)

{
  this->field_0x1b = this->field_0x1b | 1;
  (this->field_0x0).x = *(float *)param_1;
  (this->field_0x0).y = *(float *)(param_1 + 4);
  (this->field_0x0).z = *(float *)(param_1 + 8);
  this->field_0xc = param_2;
  this->field_0x10 = d_snap::_4141;
  this->field_0x1e = 0;
  return;
}


/* __thiscall dSnap_Obj::SetInf(unsigned char,
                                fopAc_ac_c const *,
                                unsigned char,
                                unsigned char,
                                short) */

void __thiscall
dSnap_Obj::SetInf(dSnap_Obj *this,uchar param_1,fopAc_ac_c *param_2,uchar param_3,uchar param_4,
                 short param_5)

{
  uint uVar1;
  
  this->field_0x18 = param_1;
  if (param_2 == (fopAc_ac_c *)0x0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = (param_2->parent).parent.mBsPcId;
  }
  this->mBsPcId = uVar1;
  this->field_0x1a = param_3;
  this->field_0x19 = param_4;
  this->field_0x1c = param_5;
  return;
}


/* __thiscall dSnap_Obj::SetAreaClear(void) */

void __thiscall dSnap_Obj::SetAreaClear(dSnap_Obj *this)

{
  this->field_0x28 = 0x800;
  this->field_0x2a = 0x800;
  this->field_0x2c = 0xf800;
  this->field_0x2e = 0xf800;
  return;
}


/* __thiscall dSnap_Obj::SetArea(short,
                                 short) */

void __thiscall dSnap_Obj::SetArea(dSnap_Obj *this,short param_1,short param_2)

{
  if (param_1 < (short)this->field_0x28) {
    this->field_0x28 = param_1;
  }
  if (param_2 < (short)this->field_0x2a) {
    this->field_0x2a = param_2;
  }
  if ((short)this->field_0x2c < param_1) {
    this->field_0x2c = param_1;
  }
  if (param_2 <= (short)this->field_0x2e) {
    return;
  }
  this->field_0x2e = param_2;
  return;
}


/* __thiscall dSnap_Obj::ChkPhoto(int) */

uint __thiscall dSnap_Obj::ChkPhoto(dSnap_Obj *this,int param_1)

{
  uint uVar1;
  
  uVar1 = countLeadingZeros(param_1 - (uint)this->field_0x18);
  return uVar1 >> 5 & 0xff;
}


/* __thiscall dSnap_Obj::ChkSuccess(long,
                                    float) */

undefined4 __thiscall dSnap_Obj::ChkSuccess(dSnap_Obj *this,long param_1,float param_2)

{
  if ((param_1 < (int)this->field_0x20) && (param_2 < this->field_0x24)) {
    return 1;
  }
  return 0;
}


/* __thiscall dSnap_Obj::ChkCamCull(void) const */

undefined4 __thiscall dSnap_Obj::ChkCamCull(dSnap_Obj *this)

{
  int iVar1;
  short sVar2;
  cXyz local_18;
  
  if (((this->field_0x1b & 1) == 0) && (this->field_0x1c != 0x7fff)) {
    mtx::PSVECSubtract(&(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo
                         [(char)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurCamera].mpCamera)->
                        mEyePos,&this->field_0x0,&local_18);
    iVar1 = SComponent::cM_atan2s(local_18.x,local_18.z);
    sVar2 = SComponent::cLib_distanceAngleS((short)iVar1,this->field_0x1e);
    if ((short)this->field_0x1c < sVar2) {
      return 1;
    }
  }
  return 0;
}


/* __thiscall dSnap_RegistObjElm::Init(void) */

void __thiscall dSnap_RegistObjElm::Init(dSnap_RegistObjElm *this)

{
  return;
}


/* __thiscall dSnap_RegistObjElm::Regist(dSnap_Obj const &) */

void __thiscall dSnap_RegistObjElm::Regist(dSnap_RegistObjElm *this,dSnap_Obj *param_1)

{
  *(float *)this = (param_1->field_0x0).x;
  *(float *)(this + 4) = (param_1->field_0x0).y;
  *(float *)(this + 8) = (param_1->field_0x0).z;
  *(float *)(this + 0xc) = param_1->field_0xc;
  *(float *)(this + 0x10) = param_1->field_0x10;
  *(int *)(this + 0x14) = param_1->mBsPcId;
  this[0x18] = *(dSnap_RegistObjElm *)&param_1->field_0x18;
  this[0x19] = *(dSnap_RegistObjElm *)&param_1->field_0x19;
  this[0x1a] = *(dSnap_RegistObjElm *)&param_1->field_0x1a;
  this[0x1b] = *(dSnap_RegistObjElm *)&param_1->field_0x1b;
  *(undefined2 *)(this + 0x1c) = param_1->field_0x1c;
  *(short *)(this + 0x1e) = param_1->field_0x1e;
  *(undefined4 *)(this + 0x20) = param_1->field_0x20;
  *(float *)(this + 0x24) = param_1->field_0x24;
  *(undefined2 *)(this + 0x28) = param_1->field_0x28;
  *(undefined2 *)(this + 0x2a) = param_1->field_0x2a;
  *(undefined2 *)(this + 0x2c) = param_1->field_0x2c;
  *(undefined2 *)(this + 0x2e) = param_1->field_0x2e;
  return;
}


/* __thiscall dSnap_packet::Create(void) */

void __thiscall dSnap_packet::Create(dSnap_packet *this)

{
  *(undefined4 *)(this + 0xedc) = 0;
  *(undefined4 *)(this + 0xee0) = 0;
  this[0xee4] = (dSnap_packet)0x0;
  return;
}


/* __thiscall dSnap_packet::ReleaseShutter(void) */

void __thiscall dSnap_packet::ReleaseShutter(dSnap_packet *this)

{
  *(uint *)(this + 0xedc) = *(uint *)(this + 0xedc) | 1;
  return;
}


/* __thiscall dSnap_packet::ChkReleaseShutter(void) */

uint __thiscall dSnap_packet::ChkReleaseShutter(dSnap_packet *this)

{
  return *(uint *)(this + 0xedc) & 1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x800cde00) */
/* __thiscall dSnap_packet::Execute(void) */

void __thiscall dSnap_packet::Execute(dSnap_packet *this)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 in_f31;
  double dVar4;
  undefined auStack8 [8];
  
  uVar3 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  iVar1 = ChkReleaseShutter(this);
  if (iVar1 != 0) {
    iVar1 = 0;
    iVar2 = 0;
    dVar4 = (double)d_snap::_4819;
    do {
      dSnap_RegistObjElm::Init((dSnap_RegistObjElm *)(this + iVar2 + 0x18));
      *(float *)(this + iVar2 + 0x4c) = (float)dVar4;
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x3c;
    } while (iVar1 < 0x3f);
    *(undefined4 *)(this + 0x14) = 0;
  }
  __psq_l0(auStack8,uVar3);
  __psq_l1(auStack8,uVar3);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x800cdf70) */
/* WARNING: Removing unreachable block (ram,0x800cdf78) */
/* __thiscall dSnap_packet::Regist(dSnap_Obj const &) */

undefined4 __thiscall dSnap_packet::Regist(dSnap_packet *this,dSnap_Obj *param_1)

{
  bool bVar1;
  daPy_lk_c *pdVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int unaff_r29;
  int iVar6;
  undefined4 uVar7;
  double dVar8;
  undefined8 in_f30;
  double dVar9;
  undefined8 in_f31;
  float fVar10;
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar7 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  iVar3 = ChkReleaseShutter(this);
  pdVar2 = d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor;
  if (iVar3 == 0) {
    uVar4 = 0;
  }
  else {
    if (*(int *)(this + 0x14) < 0x3f) {
      dSnap_RegistObjElm::Regist
                ((dSnap_RegistObjElm *)(this + *(int *)(this + 0x14) * 0x3c + 0x18),param_1);
      fVar10 = mtx::PSVECSquareDistance
                         (&(pdVar2->parent).parent.mCurrent.mPos,
                          (cXyz *)(this + *(int *)(this + 0x14) * 0x3c + 0x18));
      *(float *)(this + *(int *)(this + 0x14) * 0x3c + 0x4c) = fVar10;
      *(int *)(this + 0x14) = *(int *)(this + 0x14) + 1;
      uVar4 = 1;
    }
    else {
      bVar1 = false;
      dVar9 = (double)d_snap::_4853;
      iVar5 = 0;
      iVar3 = 0;
      iVar6 = 0x3f;
      do {
        dVar8 = (double)*(float *)(this + iVar3 + 0x4c);
        if ((dVar9 < dVar8) && (0x47 < (byte)(this + iVar3)[0x30])) {
          bVar1 = true;
          unaff_r29 = iVar5;
          dVar9 = dVar8;
        }
        iVar5 = iVar5 + 1;
        iVar3 = iVar3 + 0x3c;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      if (bVar1) {
        fVar10 = mtx::PSVECSquareDistance
                           (&((d_com_inf_game::g_dComIfG_gameInfo.mPlay.mpCurPlayerActor)->parent).
                             parent.mCurrent.mPos,&param_1->field_0x0);
        dVar8 = (double)fVar10;
        if ((param_1->field_0x18 < 0x48) || (dVar8 <= dVar9)) {
          dSnap_RegistObjElm::Regist((dSnap_RegistObjElm *)(this + unaff_r29 * 0x3c + 0x18),param_1)
          ;
          *(float *)(this + unaff_r29 * 0x3c + 0x4c) = (float)dVar8;
          uVar4 = 0;
        }
        else {
          uVar4 = 0;
        }
      }
      else {
        uVar4 = 0;
      }
    }
  }
  __psq_l0(auStack8,uVar7);
  __psq_l1(auStack8,uVar7);
  __psq_l0(auStack24,uVar7);
  __psq_l1(auStack24,uVar7);
  return uVar4;
}


namespace d_snap {

/* __stdcall dSnap_MatDl(void) */

void dSnap_MatDl(void)

{
  gx::GXSetNumChans(1);
  gx::GXSetCullMode(2);
  gx::GXSetNumTexGens(0);
  gx::GXSetNumIndStages(0);
  gx::GXSetNumTevStages(1);
  gx::GXSetCoPlanar(0);
  gx::GXSetChanCtrl(GX_COLOR0,false,GX_SRC_REG,GX_SRC_VTX,0,GX_DF_NONE,GX_AF_NONE);
  gx::GXSetChanCtrl(GX_ALPHA0,false,GX_SRC_REG,GX_SRC_VTX,0,GX_DF_NONE,GX_AF_NONE);
  gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR_ZERO);
  gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_ZERO,GX_CC_ZERO,GX_CC_ZERO,GX_CC_C0);
  gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_A0);
  gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetTevSwapMode(0,0,0);
  gx::GXSetAlphaCompare(GX_ALWAYS,0,GX_AOP_OR,GX_ALWAYS,0);
  gx::GXSetZCompLoc(1);
  gx::GXSetPixelFmt(1,0);
  gx::GXSetZMode(true,GX_LEQUAL,true);
  gx::GXSetBlendMode(GX_BM_BLEND,GX_BL_ZERO,GX_BL_ONE,GX_LO_CLEAR);
  gx::GXSetColorUpdate(false);
  gx::GXSetAlphaUpdate(1);
  gx::GXSetDither(0);
  return;
}


/* __stdcall dSnap_AlphaClearDL(void) */

void dSnap_AlphaClearDL(void)

{
  gx::GXSetNumChans(1);
  gx::GXSetCullMode(2);
  gx::GXSetNumTexGens(0);
  gx::GXSetNumIndStages(0);
  gx::GXSetNumTevStages(1);
  gx::GXSetCoPlanar(0);
  gx::GXSetChanCtrl(GX_COLOR0,false,GX_SRC_REG,GX_SRC_VTX,0,GX_DF_NONE,GX_AF_NONE);
  gx::GXSetChanCtrl(GX_ALPHA0,false,GX_SRC_REG,GX_SRC_VTX,0,GX_DF_NONE,GX_AF_NONE);
  gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR_ZERO);
  gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_ZERO,GX_CC_ZERO,GX_CC_ZERO,GX_CC_C0);
  gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_A0);
  gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetTevSwapMode(0,0,0);
  gx::GXSetAlphaCompare(GX_ALWAYS,0,GX_AOP_OR,GX_ALWAYS,0);
  gx::GXSetZCompLoc(1);
  gx::GXSetPixelFmt(1,0);
  gx::GXSetZMode(false,GX_LEQUAL,true);
  gx::GXSetBlendMode(GX_BM_NONE,GX_BL_ZERO,GX_BL_ZERO,GX_LO_CLEAR);
  gx::GXSetColorUpdate(false);
  gx::GXSetAlphaUpdate(1);
  gx::GXSetDither(1);
  return;
}

}

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dSnap_packet::draw(void) */

void __thiscall dSnap_packet::draw(dSnap_packet *this)

{
  int iVar1;
  uint uVar2;
  _GXColor local_18;
  _GXColor local_14;
  
  iVar1 = ChkReleaseShutter(this);
  if (iVar1 != 0) {
    J3DSys::reinitGX(&J3DGraphBase::j3dSys);
    ClearAlphaBuffer(this);
    d_snap::dSnap_MatDl();
    iVar1 = 0;
    for (uVar2 = 0; (int)uVar2 < *(int *)(this + 0x14); uVar2 = uVar2 + 1) {
      local_14 = d_snap::_4876;
      gx::GXSetDstAlpha(1,(uVar2 & 0x3f) << 2);
      local_18 = local_14;
      gx::GXSetTevColor(GX_TEVREG0,&local_18);
      dSnap_Obj::draw((dSnap_Obj *)(this + iVar1 + 0x18));
      iVar1 = iVar1 + 0x3c;
    }
    Judge(this);
    gx::GXSetColorUpdate(true);
    gx::GXSetAlphaUpdate(0);
    gx::GXSetBlendMode(GX_BM_NONE,GX_BL_ZERO,GX_BL_ZERO,GX_LO_CLEAR);
    gx::GXSetDither(1);
  }
  return;
}


/* __thiscall dSnap_packet::ClearAlphaBuffer(void) */

void __thiscall dSnap_packet::ClearAlphaBuffer(dSnap_packet *this)

{
  _GXColor local_48;
  _GXColor local_44;
  MTX44 MStack64;
  
  local_44 = d_snap::_4885;
  d_snap::dSnap_AlphaClearDL();
  gx::GXSetDstAlpha(1,0xfc);
  local_48 = local_44;
  gx::GXSetTevColor(GX_TEVREG0,&local_48);
  mtx::C_MTXOrtho(d_snap::_4141,d_snap::_4899,d_snap::_4141,d_snap::_4900,d_snap::_4141,
                  d_snap::_4901,&MStack64);
  gx::GXSetProjection(&MStack64,GX_ORTHOGRAPHIC);
  gx::GXClearVtxDesc();
  gx::GXSetVtxDesc(GX_VA_POS,GX_DIRECT);
  gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_RGBA4,0);
  gx::GXLoadPosMtxImm(&m_Do_mtx::g_mDoMtx_identity,0);
  gx::GXSetCurrentMtx(0);
  gx::GXBegin(0x80,0,4);
  write_volatile_2(0xcc008000,0xae);
  write_volatile_2(0xcc008000,0x83);
  write_volatile_2(0xcc008000,0xfffb);
  write_volatile_2(0xcc008000,0x1d4);
  write_volatile_2(0xcc008000,0x83);
  write_volatile_2(0xcc008000,0xfffb);
  write_volatile_2(0xcc008000,0x1d4);
  write_volatile_2(0xcc008000,0x149);
  write_volatile_2(0xcc008000,0xfffb);
  write_volatile_2(0xcc008000,0xae);
  write_volatile_2(0xcc008000,0x149);
  write_volatile_2(0xcc008000,0xfffb);
  gx::GXSetProjection(&(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCameraInfo
                        [(char)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCurCameraInfo].mpCamera)->
                       mProjMtx,GX_PERSPECTIVE);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dSnap_packet::Judge(void) */

void __thiscall dSnap_packet::Judge(dSnap_packet *this)

{
  int iVar1;
  dSnap_packet *pdVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  double dVar6;
  uint local_28 [2];
  undefined4 local_20;
  uint uStack28;
  
  iVar1 = ChkReleaseShutter(this);
  if (iVar1 != 0) {
    *(undefined4 *)(this + 0xee0) = 0;
    gx::GXDrawDone();
    gx::GXPokeAlphaRead(2);
    iVar1 = 0;
    iVar5 = 0;
    do {
      *(undefined4 *)(this + iVar5 + 0x38) = 0;
      dSnap_Obj::SetAreaClear((dSnap_Obj *)(this + iVar5 + 0x18));
      iVar1 = iVar1 + 1;
      iVar5 = iVar5 + 0x3c;
    } while (iVar1 < 0x3f);
    uVar3 = 0x56;
    do {
      uVar4 = 0xae;
      do {
        gx::GXPeekARGB(uVar4 & 0xffff,uVar3 & 0xffff,local_28);
        if (local_28[0] >> 0x1a < 0x3f) {
          pdVar2 = this + (local_28[0] >> 0x1a) * 0x3c;
          *(int *)(pdVar2 + 0x38) = *(int *)(pdVar2 + 0x38) + 1;
          dSnap_Obj::SetArea((dSnap_Obj *)(pdVar2 + 0x18),(short)uVar4,(short)uVar3);
        }
        uVar4 = uVar4 + 1;
      } while ((int)uVar4 < 0x1d4);
      uVar3 = uVar3 + 1;
    } while ((int)uVar3 < 0x11c);
    iVar5 = 0;
    for (iVar1 = 0; iVar1 < *(int *)(this + 0x14); iVar1 = iVar1 + 1) {
      pdVar2 = this + iVar5;
      if ((*(int *)(pdVar2 + 0x38) != 0) &&
         (dVar6 = (double)dSnap_Obj::CalcArea2D((dSnap_Obj *)(pdVar2 + 0x18)),
         SComponent::G_CM3D_F_ABS_MIN <= (float)ABS(dVar6))) {
        uStack28 = *(uint *)(pdVar2 + 0x38) ^ 0x80000000;
        local_20 = 0x43300000;
        *(float *)(pdVar2 + 0x3c) =
             (float)((double)(float)((double)CONCAT44(0x43300000,uStack28) - d_snap::_4950) / dVar6)
        ;
      }
      iVar5 = iVar5 + 0x3c;
    }
    SetResult(this);
    *(uint *)(this + 0xedc) = *(uint *)(this + 0xedc) & 0xfffffffe;
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dSnap_packet::FindPhoto(int,
                                      int) */

int __thiscall dSnap_packet::FindPhoto(dSnap_packet *this,int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  
  if ((-1 < param_1) && (param_1 < *(int *)(this + 0x14))) {
    iVar2 = param_1 * 0x3c;
    for (; param_1 < *(int *)(this + 0x14); param_1 = param_1 + 1) {
      cVar1 = dSnap_Obj::ChkPhoto((dSnap_Obj *)(this + iVar2 + 0x18),param_2);
      if (cVar1 != '\0') {
        return param_1;
      }
      iVar2 = iVar2 + 0x3c;
    }
  }
  return -1;
}


/* __thiscall dSnap_packet::JudgePost(void) */

bool __thiscall dSnap_packet::JudgePost(dSnap_packet *this)

{
  int iVar1;
  char cVar2;
  bool bVar3;
  
  iVar1 = FindPhoto(this,0,1);
  if (iVar1 == -1) {
    bVar3 = false;
  }
  else {
    cVar2 = dSnap_Obj::ChkSuccess((dSnap_Obj *)(this + iVar1 * 0x3c + 0x18),2000,d_snap::_4989);
    bVar3 = cVar2 != '\0';
  }
  return bVar3;
}


/* __thiscall dSnap_packet::JudgeBikutsuki(void) */

byte __thiscall dSnap_packet::JudgeBikutsuki(dSnap_packet *this)

{
  int iVar1;
  char cVar2;
  byte bVar3;
  
  iVar1 = FindPhoto(this,0,2);
  if (iVar1 == -1) {
    bVar3 = 0;
  }
  else {
    cVar2 = dSnap_Obj::ChkSuccess((dSnap_Obj *)(this + iVar1 * 0x3c + 0x18),2000,d_snap::_4989);
    bVar3 = -(cVar2 != '\0') & 2;
  }
  return bVar3;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dSnap_packet::JudgeCoupleLook(void) */

undefined4 __thiscall dSnap_packet::JudgeCoupleLook(dSnap_packet *this)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char cVar4;
  
  iVar1 = FindPhoto(this,0,3);
  if (iVar1 == -1) {
    uVar2 = 0;
  }
  else {
    iVar3 = FindPhoto(this,iVar1 + 1,3);
    if (iVar3 == -1) {
      uVar2 = 0;
    }
    else {
      cVar4 = dSnap_Obj::ChkSuccess((dSnap_Obj *)(this + iVar1 * 0x3c + 0x18),2000,d_snap::_4989);
      if ((cVar4 == '\0') ||
         (cVar4 = dSnap_Obj::ChkSuccess
                            ((dSnap_Obj *)(this + iVar3 * 0x3c + 0x18),2000,d_snap::_4989),
         cVar4 == '\0')) {
        uVar2 = 0;
      }
      else {
        uVar2 = 3;
      }
    }
  }
  return uVar2;
}


/* __thiscall dSnap_packet::JudgeGF(void) */

byte __thiscall dSnap_packet::JudgeGF(dSnap_packet *this)

{
  int iVar1;
  char cVar2;
  byte bVar3;
  
  iVar1 = FindPhoto(this,0,4);
  if (iVar1 == -1) {
    bVar3 = 0;
  }
  else {
    cVar2 = dSnap_Obj::ChkSuccess((dSnap_Obj *)(this + iVar1 * 0x3c + 0x18),5000,d_snap::_5023);
    bVar3 = -(cVar2 != '\0') & 4;
  }
  return bVar3;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dSnap_packet::JudgeGenzo(void) */

undefined4 __thiscall dSnap_packet::JudgeGenzo(dSnap_packet *this)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char cVar4;
  
  iVar1 = FindPhoto(this,0,5);
  if (iVar1 == -1) {
    uVar2 = 0;
  }
  else {
    iVar3 = FindPhoto(this,0,6);
    if (iVar3 == -1) {
      uVar2 = 0;
    }
    else {
      cVar4 = dSnap_Obj::ChkSuccess((dSnap_Obj *)(this + iVar1 * 0x3c + 0x18),0x5dc,d_snap::_5037);
      if ((cVar4 == '\0') ||
         (cVar4 = dSnap_Obj::ChkSuccess
                            ((dSnap_Obj *)(this + iVar3 * 0x3c + 0x18),0x5dc,d_snap::_5037),
         cVar4 == '\0')) {
        uVar2 = 0;
      }
      else {
        uVar2 = 5;
      }
    }
  }
  return uVar2;
}


/* __thiscall dSnap_packet::JudgeObasan4(void) */

byte __thiscall dSnap_packet::JudgeObasan4(dSnap_packet *this)

{
  int iVar1;
  int iVar2;
  char cVar3;
  byte bVar4;
  
  iVar1 = FindPhoto(this,0,6);
  if (iVar1 == -1) {
    bVar4 = 0;
  }
  else {
    iVar2 = FindPhoto(this,0,5);
    if (iVar2 == -1) {
      cVar3 = dSnap_Obj::ChkSuccess((dSnap_Obj *)(this + iVar1 * 0x3c + 0x18),4000,d_snap::_4336);
      bVar4 = -(cVar3 != '\0') & 6;
    }
    else {
      bVar4 = 0;
    }
  }
  return bVar4;
}


/* __thiscall dSnap_packet::JudgeTestM(void) */

undefined4 __thiscall dSnap_packet::JudgeTestM(dSnap_packet *this)

{
  return 0;
}


/* __thiscall dSnap_packet::JudgeGene(void) */

undefined4 __thiscall dSnap_packet::JudgeGene(dSnap_packet *this)

{
  int iVar1;
  undefined4 uVar2;
  char cVar3;
  
  iVar1 = FindPhoto(this,0,*(int *)(this + 0x10));
  if (iVar1 == -1) {
    uVar2 = 0;
  }
  else {
    cVar3 = dSnap_Obj::ChkSuccess((dSnap_Obj *)(this + iVar1 * 0x3c + 0x18),4000,d_snap::_4336);
    if (cVar3 == '\0') {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(this + 0x10);
    }
  }
  return uVar2;
}


/* __thiscall dSnap_packet::JudgeFigure(int) */

undefined4 __thiscall dSnap_packet::JudgeFigure(dSnap_packet *this,int param_1)

{
  int iVar1;
  undefined4 uVar2;
  char cVar3;
  
  iVar1 = *(int *)(this + 0x10);
  if (iVar1 < 0xd0) {
    if (iVar1 < 0xcf) {
      if (iVar1 < 0x49) {
        uVar2 = 0;
      }
      else {
        iVar1 = d_snap::dSnap_PhotoIndex2TableIndex(iVar1);
        if (*(int *)(this + param_1 * 0x3c + 0x38) <
            (int)(uint)(ushort)d_snap::l_CharaData[iVar1].field_0xe) {
          uVar2 = 0;
        }
        else {
          if (*(float *)(this + param_1 * 0x3c + 0x3c) <
              (float)((double)CONCAT44(0x43300000,(uint)(ushort)d_snap::l_CharaData[iVar1].field_0xa
                                      ) - d_snap::_5091) / d_snap::_5089) {
            this[0xee4] = (dSnap_packet)((byte)this[0xee4] | 2);
          }
          cVar3 = dSnap_Obj::ChkCamCull((dSnap_Obj *)(this + param_1 * 0x3c + 0x18));
          if (cVar3 != '\0') {
            this[0xee4] = (dSnap_packet)((byte)this[0xee4] | 1);
          }
          uVar2 = *(undefined4 *)(this + 0x10);
        }
      }
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dSnap_packet::SetResult(void) */

void __thiscall dSnap_packet::SetResult(dSnap_packet *this)

{
  char *pcVar1;
  ulong uVar2;
  bool bVar5;
  dSnap_packet *pdVar3;
  undefined4 uVar4;
  uint uVar6;
  int iVar7;
  int iVar8;
  dSnap_packet *pdVar9;
  int iVar10;
  char local_28 [20];
  
  *(undefined4 *)(this + 0xee0) = 0;
  this[0xee4] = (dSnap_packet)0x0;
  pcVar1 = local_28;
  iVar10 = 0xb;
  do {
    *pcVar1 = '\0';
    pcVar1 = pcVar1 + 1;
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  iVar8 = -1;
  iVar7 = 0;
  iVar10 = 0;
  do {
    if (*(int *)(this + 0x14) <= iVar7) {
      return;
    }
    pdVar9 = this + iVar10;
    if ((*(int *)(pdVar9 + 0x38) != 0) && (pdVar9[0x30] != (dSnap_packet)0x0)) {
      if (0xcf < (byte)pdVar9[0x30]) {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert
                  (uVar2,"d_snap.cpp",0x917,
                   "0 <= m_tbl[col].m_obj.GetPhoto() && m_tbl[col].m_obj.GetPhoto() < DSNAP_TYPE_LAST_INDEX"
                  );
        m_Do_printf::OSPanic("d_snap.cpp",0x917,&DAT_8035b73e);
      }
      uVar6 = (uint)(byte)pdVar9[0x30];
      if (uVar6 < 0xb) {
        if (local_28[uVar6] == '\0') {
          bVar5 = Runtime.PPCEABI.H::__ptmf_test((PTMF *)(&m_judge_tbl + uVar6 * 0xc));
          if (bVar5 != false) {
            *(uint *)(this + 0x10) = (uint)(byte)pdVar9[0x30];
            pdVar3 = this;
            Runtime.PPCEABI.H::__ptmf_scall
                      ((PTMF *)(&m_judge_tbl + (uint)(byte)pdVar9[0x30] * 0xc),this,&DAT_80390000);
            *(dSnap_packet **)(this + 0xee0) = pdVar3;
            iVar8 = *(int *)(pdVar9 + 0x38);
            if (*(int *)(this + 0xee0) != 0) {
              return;
            }
          }
          local_28[(byte)pdVar9[0x30]] = '\x01';
        }
      }
      else {
        if (iVar8 < *(int *)(pdVar9 + 0x38)) {
          *(uint *)(this + 0x10) = uVar6;
          uVar4 = JudgeFigure(this,iVar7);
          *(undefined4 *)(this + 0xee0) = uVar4;
          iVar8 = *(int *)(pdVar9 + 0x38);
        }
      }
    }
    iVar7 = iVar7 + 1;
    iVar10 = iVar10 + 0x3c;
  } while( true );
}


namespace d_snap {

/* __stdcall dSnap_Create(void) */

void dSnap_Create(void)

{
  ::dSnap_packet::Create((dSnap_packet *)&l_snap);
  return;
}


/* __stdcall dSnap_ReleaseShutter(void) */

void dSnap_ReleaseShutter(void)

{
  ::dSnap_packet::ReleaseShutter((dSnap_packet *)&l_snap);
  return;
}


/* __stdcall dSnap_Execute(void) */

void dSnap_Execute(void)

{
  ::dSnap_packet::Execute((dSnap_packet *)&l_snap);
  return;
}


/* __stdcall dSnap_GetResult(void) */

undefined4 dSnap_GetResult(void)

{
  return DAT_803e35dc;
}


/* __stdcall dSnap_GetResultDetail(void) */

undefined dSnap_GetResultDetail(void)

{
  return DAT_803e35e0;
}


/* __stdcall dSnap_RegistSnapObj(dSnap_Obj &) */

void dSnap_RegistSnapObj(dSnap_Obj *param_1)

{
  ::dSnap_packet::Regist((dSnap_packet *)&l_snap,param_1);
  return;
}


/* __stdcall dSnap_RegistFig(unsigned char,
                             fopAc_ac_c *,
                             float,
                             float,
                             float) */

void dSnap_RegistFig
               (double param_1,double param_2,double param_3,byte param_4,fopAc_ac_c *param_5)

{
  dSnap_RegistFig(param_4,param_5,&(param_5->mCurrent).mPos,(param_5->mCollisionRot).y,
                  (float)param_1,(float)param_2,(float)param_3);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x800cefac) */
/* WARNING: Removing unreachable block (ram,0x800cefa4) */
/* WARNING: Removing unreachable block (ram,0x800cefb4) */
/* __stdcall dSnap_RegistFig(unsigned char,
                             fopAc_ac_c *,
                             Vec const &,
                             short,
                             float,
                             float,
                             float) */

void dSnap_RegistFig
               (byte param_1,fopAc_ac_c *param_2,cXyz *param_3,short param_4,float param_5,
               float param_6,float param_7)

{
  int iVar1;
  undefined2 in_register_00000018;
  undefined4 uVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  cXyz local_c8;
  cXyz cStack188;
  dSnap_Obj dStack176;
  undefined4 local_78;
  uint uStack116;
  undefined4 local_70;
  uint uStack108;
  undefined4 local_68;
  uint uStack100;
  undefined4 local_60;
  uint uStack92;
  undefined4 local_58;
  uint uStack84;
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar5 = (double)param_7;
  dVar4 = (double)param_6;
  dVar3 = (double)param_5;
  uVar2 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  iVar1 = ::dSnap_packet::ChkReleaseShutter((dSnap_packet *)&l_snap);
  if ((iVar1 != 0) && (param_1 < 0xcf)) {
    iVar1 = dSnap_PhotoIndex2TableIndex((uint)param_1);
    m_Do_mtx::mDoMtx_YrotS(&mDoMtx_stack_c::now,CONCAT22(in_register_00000018,param_4));
    uStack116 = (int)l_CharaData[iVar1].field_0x0 ^ 0x80000000;
    local_78 = 0x43300000;
    uStack108 = (int)l_CharaData[iVar1].field_0x2 ^ 0x80000000;
    local_70 = 0x43300000;
    uStack100 = (int)l_CharaData[iVar1].field_0x4 ^ 0x80000000;
    local_68 = 0x43300000;
    local_c8.x = (float)((double)(float)((double)CONCAT44(0x43300000,uStack116) - _4950) * dVar5);
    local_c8.y = (float)((double)(float)((double)CONCAT44(0x43300000,uStack108) - _4950) * dVar5);
    local_c8.z = (float)((double)(float)((double)CONCAT44(0x43300000,uStack100) - _4950) * dVar5);
    mtx::PSMTXMultVec(&mDoMtx_stack_c::now,&local_c8,&cStack188);
    mtx::PSVECAdd(&cStack188,param_3,&cStack188);
    ::dSnap_Obj::dSnap_Obj(&dStack176);
    uStack92 = (int)l_CharaData[iVar1].field_0x6 ^ 0x80000000;
    local_60 = 0x43300000;
    uStack84 = (int)l_CharaData[iVar1].field_0x8 ^ 0x80000000;
    local_58 = 0x43300000;
    ::dSnap_Obj::SetGeo(&dStack176,&cStack188,
                        (float)((double)(float)((double)CONCAT44(0x43300000,uStack92) - _4950) *
                               dVar4),
                        (float)((double)(float)((double)CONCAT44(0x43300000,uStack84) - _4950) *
                               dVar3),param_4);
    ::dSnap_Obj::SetInf(&dStack176,param_1,param_2,'\0','\x04',l_CharaData[iVar1].field_0xc);
    dSnap_RegistSnapObj(&dStack176);
  }
  __psq_l0(auStack8,uVar2);
  __psq_l1(auStack8,uVar2);
  __psq_l0(auStack24,uVar2);
  __psq_l1(auStack24,uVar2);
  __psq_l0(auStack40,uVar2);
  __psq_l1(auStack40,uVar2);
  return;
}


/* __stdcall dSnap_DebugDraw(void) */

void dSnap_DebugDraw(void)

{
  int iVar1;
  
  iVar1 = ::dSnap_packet::ChkReleaseShutter((dSnap_packet *)&l_snap);
  if (iVar1 != 0) {
    J3DGraphBase::j3dSys.mpCurDrawBuffers[0] =
         d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelMaskOffOpa;
    J3DGraphBase::j3dSys.mpCurDrawBuffers[1] =
         d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelMaskOffXlu;
    J3DDrawBuffer::entryImm
              (d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelMaskOffXlu,
               (J3DPacket *)&l_snap,0xff);
    J3DGraphBase::j3dSys.mpCurDrawBuffers[0] =
         d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelOpa;
    J3DGraphBase::j3dSys.mpCurDrawBuffers[1] =
         d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mpBufInvisibleModelXlu;
  }
  return;
}


/* __stdcall dSnap_Delete(void) */

void dSnap_Delete(void)

{
  return;
}

}

/* __thiscall dSnap_packet::~dSnap_packet(void) */

void __thiscall dSnap_packet::_dSnap_packet(dSnap_packet *this)

{
  short in_r4;
  
  if (this != (dSnap_packet *)0x0) {
    *(undefined1 **)this = &__vt;
    Runtime.PPCEABI.H::__destroy_arr(this + 0x18,dSnap_RegistObjElm::_dSnap_RegistObjElm,0x3c,0x3f);
    if (this != (dSnap_packet *)0x0) {
      *(undefined ***)this = &J3DPacket::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dSnap_RegistObjElm::~dSnap_RegistObjElm(void) */

void __thiscall dSnap_RegistObjElm::_dSnap_RegistObjElm(dSnap_RegistObjElm *this)

{
  short in_r4;
  
  if (this != (dSnap_RegistObjElm *)0x0) {
    *(undefined1 **)(this + 0x38) = &__vt;
    if (this != (dSnap_RegistObjElm *)0x0) {
      *(undefined ***)(this + 0x30) = &dSnap_Obj::__vt;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


namespace d_snap {

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __sinit_d_snap_cpp(void)

{
  _m_judge_tbl = Runtime.PPCEABI.H::__ptmf_null;
  DAT_803891d4 = DAT_80370fbc;
  DAT_803891d8 = DAT_80370fc0;
  DAT_803891dc = _5092;
  DAT_803891e0 = DAT_8038915c;
  DAT_803891e4 = PTR_JudgePost_80389160;
  DAT_803891e8 = _5093;
  DAT_803891ec = DAT_80389168;
  DAT_803891f0 = PTR_JudgeBikutsuki_8038916c;
  DAT_803891f4 = _5094;
  DAT_803891f8 = DAT_80389174;
  DAT_803891fc = PTR_JudgeCoupleLook_80389178;
  DAT_80389200 = _5095;
  DAT_80389204 = DAT_80389180;
  DAT_80389208 = PTR_JudgeGF_80389184;
  DAT_8038920c = _5096;
  DAT_80389210 = DAT_8038918c;
  DAT_80389214 = PTR_JudgeGenzo_80389190;
  DAT_80389218 = _5097;
  DAT_8038921c = DAT_80389198;
  DAT_80389220 = PTR_JudgeObasan4_8038919c;
  DAT_80389224 = _5098;
  DAT_80389228 = DAT_803891a4;
  DAT_8038922c = PTR_JudgeGene_803891a8;
  DAT_80389230 = _5099;
  DAT_80389234 = DAT_803891b0;
  DAT_80389238 = PTR_JudgeGene_803891b4;
  DAT_8038923c = _5100;
  DAT_80389240 = DAT_803891bc;
  DAT_80389244 = PTR_JudgeGene_803891c0;
  DAT_80389248 = _5101;
  DAT_8038924c = DAT_803891c8;
  DAT_80389250 = PTR_JudgeTestM_803891cc;
  DAT_803e2700 = 0;
  DAT_803e2704 = 0;
  DAT_803e2708 = 0;
  l_snap = &::dSnap_packet::__vt;
  Runtime.PPCEABI.H::__construct_array
            (&DAT_803e2714,::dSnap_RegistObjElm::dSnap_RegistObjElm,
             ::dSnap_RegistObjElm::_dSnap_RegistObjElm,0x3c,0x3f);
  Runtime.PPCEABI.H::__register_global_object(&l_snap,::dSnap_packet::_dSnap_packet,&_5157);
  return;
}

}

/* __thiscall dSnap_RegistObjElm::dSnap_RegistObjElm(void) */

void __thiscall dSnap_RegistObjElm::dSnap_RegistObjElm(dSnap_RegistObjElm *this)

{
  *(undefined1 **)(this + 0x38) = &__vt;
  dSnap_Obj::dSnap_Obj((dSnap_Obj *)this);
  return;
}

