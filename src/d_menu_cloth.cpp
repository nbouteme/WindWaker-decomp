#include <d_menu_cloth.h>
#include <d_menu_cloth.h>
#include <Runtime.PPCEABI.H/NMWExceptionp.h>
#include <JKernel/JKRHeap.h>
#include <gx/GXLight.h>
#include <os/OSCache.h>
#include <SComponent/c_math.h>
#include <JKernel/JKRArchivePub.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <gx/GXTexture.h>
#include <m_Do_ext.h>
#include <m_Do_mtx.h>
#include <m_Do_hostIO.h>
#include <SComponent/c_xyz.h>
#include <mtx/vec.h>
#include <SComponent/c_lib.h>
#include <gx/GXGeometry.h>
#include <gx/GXAttr.h>
#include <gx/GXTev.h>
#include <J3DGraphBase/J3DSys.h>
#include <gx/GXBump.h>
#include <gx/GXDisplayList.h>
#include <mtx/mtx.h>
#include <gx/GXTransform.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <daCLOTH_ChildHIO_c.h>
#include <daCLOTH_HIO_c.h>
#include <dMCloth_c.h>


namespace d_menu_cloth {
struct daCLOTH_HIO_c l_HIO;
}
undefined1 dMCloth_c;

/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall daCLOTH_HIO_c::daCLOTH_HIO_c(void) */

void __thiscall daCLOTH_HIO_c::daCLOTH_HIO_c(daCLOTH_HIO_c *this)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  
  this->field_0x0 = &__vt;
  Runtime.PPCEABI.H::__construct_array
            ((void *)&this->field_0x8,daCLOTH_ChildHIO_c::daCLOTH_ChildHIO_c,
             daCLOTH_ChildHIO_c::_daCLOTH_ChildHIO_c,0x58,3);
  *(undefined *)&this->field_0x4 = 0xff;
  fVar1 = d_menu_cloth::_4005;
  this->field_0xc = d_menu_cloth::_4005;
  this->field_0x10 = fVar1;
  fVar1 = d_menu_cloth::_4006;
  this->field_0x14 = d_menu_cloth::_4006;
  this->field_0x24 = 0;
  this->field_0x26 = 0;
  this->field_0x28 = 0;
  fVar2 = d_menu_cloth::_4007;
  this->field_0x18 = d_menu_cloth::_4007;
  fVar3 = d_menu_cloth::_4008;
  this->field_0x1c = d_menu_cloth::_4008;
  fVar4 = d_menu_cloth::_4009;
  this->field_0x20 = d_menu_cloth::_4009;
  this->field_0x2a = 0x78;
  this->field_0x2c = 0xa5;
  this->field_0x2e = 0x37;
  this->field_0x30 = 0xdc;
  this->field_0x32 = 0x23;
  this->field_0x34 = 0x5f;
  this->field_0x36 = 0x19;
  this->field_0x38 = 0x20;
  this->field_0x3a = 0;
  this->field_0x3c = 7;
  this->field_0x3e = 0xfc18;
  this->field_0x40 = 9000;
  this->field_0x42 = 0x800;
  fVar5 = d_menu_cloth::_4010;
  this->field_0x44 = d_menu_cloth::_4010;
  this->field_0x48 = fVar5;
  fVar6 = d_menu_cloth::_4011;
  this->field_0x4c = d_menu_cloth::_4011;
  fVar7 = d_menu_cloth::_4012;
  this->field_0x54 = d_menu_cloth::_4012;
  this->field_0x50 = 0;
  this->field_0x52 = 0;
  this->field_0x58 = 2;
  fVar8 = d_menu_cloth::_4013;
  this->field_0x5c = d_menu_cloth::_4013;
  this->field_0x64 = d_menu_cloth::_4014;
  this->field_0x68 = d_menu_cloth::_4015;
  this->field_0x6c = fVar1;
  this->field_0x7c = 0;
  this->field_0x7e = 0;
  this->field_0x80 = 0;
  this->field_0x70 = d_menu_cloth::_4016;
  this->field_0x74 = d_menu_cloth::_4017;
  this->field_0x78 = fVar4;
  this->field_0x82 = 0xbe;
  this->field_0x84 = 0xb4;
  this->field_0x86 = 100;
  this->field_0x88 = 0xaa;
  this->field_0x8a = 0x8c;
  this->field_0x8c = 0x50;
  this->field_0x8e = 0x14;
  this->field_0x90 = 0x20;
  this->field_0x92 = 0;
  this->field_0x94 = 7;
  this->field_0x96 = 0xfc18;
  this->field_0x98 = 9000;
  this->field_0x9a = 0x800;
  this->field_0x9c = fVar5;
  this->field_0xa0 = fVar5;
  this->field_0xa4 = fVar6;
  this->field_0xac = fVar7;
  this->field_0xa8 = 0;
  this->field_0xaa = 0;
  this->field_0xb0 = 2;
  this->field_0xb4 = fVar8;
  fVar9 = d_menu_cloth::_4018;
  this->field_0xbc = d_menu_cloth::_4018;
  this->field_0xc0 = fVar9;
  this->field_0xc4 = fVar1;
  this->field_0xd4 = 0;
  this->field_0xd6 = 0;
  this->field_0xd8 = 0x4000;
  this->field_0xc8 = fVar2;
  this->field_0xcc = fVar3;
  this->field_0xd0 = fVar4;
  this->field_0xda = 0xbe;
  this->field_0xdc = 0xb4;
  this->field_0xde = 100;
  this->field_0xe0 = 0xdc;
  this->field_0xe2 = 0x8c;
  this->field_0xe4 = 0x50;
  this->field_0xe6 = 0x14;
  this->field_0xe8 = 0x20;
  this->field_0xea = 0;
  this->field_0xec = 7;
  this->field_0xee = 0xfc18;
  this->field_0xf0 = 9000;
  this->field_0xf2 = 0x800;
  this->field_0xf4 = fVar5;
  this->field_0xf8 = fVar5;
  this->field_0xfc = fVar6;
  this->field_0x104 = fVar7;
  this->field_0x100 = 0;
  this->field_0x102 = 0;
  this->field_0x108 = 2;
  this->field_0x10c = fVar8;
  return;
}


/* __thiscall daCLOTH_ChildHIO_c::~daCLOTH_ChildHIO_c(void) */

void __thiscall daCLOTH_ChildHIO_c::_daCLOTH_ChildHIO_c(daCLOTH_ChildHIO_c *this)

{
  short in_r4;
  
  if ((this != (daCLOTH_ChildHIO_c *)0x0) && (*(undefined1 **)this = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


/* __thiscall daCLOTH_ChildHIO_c::daCLOTH_ChildHIO_c(void) */

void __thiscall daCLOTH_ChildHIO_c::daCLOTH_ChildHIO_c(daCLOTH_ChildHIO_c *this)

{
  *(undefined1 **)this = &__vt;
  return;
}


/* __thiscall dMCloth_c::lightSet1(cXyz) */

void __thiscall dMCloth_c::lightSet1(dMCloth_c *this,cXyz *param_1)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  _GXColor local_44;
  _GXLightObj _Stack64;
  
  uVar2 = (uint)(byte)this[0x913d];
  iVar3 = (int)((int)(short)(&d_menu_cloth::l_HIO.field_0x50)[uVar2 * 0x2c] & 0xffffU) >>
          (JKernel::JMath::jmaSinShift & 0x3f);
  iVar4 = (int)((int)(short)(&d_menu_cloth::l_HIO.field_0x52)[uVar2 * 0x2c] & 0xffffU) >>
          (JKernel::JMath::jmaSinShift & 0x3f);
  fVar1 = -(&d_menu_cloth::l_HIO.field_0x54)[uVar2 * 0x16];
  gx::GXInitLightPos((double)(fVar1 * JKernel::JMath::jmaSinTable[iVar4] *
                             JKernel::JMath::jmaCosTable[iVar3]),
                     (double)(fVar1 * JKernel::JMath::jmaSinTable[iVar3]),
                     (double)(fVar1 * JKernel::JMath::jmaCosTable[iVar4] *
                             JKernel::JMath::jmaCosTable[iVar3]),&_Stack64);
  local_44 = d_menu_cloth::_4040;
  gx::GXInitLightColor(&_Stack64,&local_44);
  gx::GXLoadLightObjImm(&_Stack64,GX_LIGHT0);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* WARNING: Removing unreachable block (ram,0x80199ca8) */
/* WARNING: Removing unreachable block (ram,0x80199c98) */
/* WARNING: Removing unreachable block (ram,0x80199b14) */
/* WARNING: Removing unreachable block (ram,0x80199c90) */
/* WARNING: Removing unreachable block (ram,0x80199ca0) */
/* WARNING: Removing unreachable block (ram,0x80199cb0) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dMCloth_c::cloth_init(void) */

void __thiscall dMCloth_c::cloth_init(dMCloth_c *this)

{
  bool bVar1;
  dMCloth_c dVar2;
  float fVar3;
  uint uVar4;
  uint uVar5;
  short sVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  double dVar19;
  uint uVar20;
  uint uVar21;
  int iVar22;
  int iVar23;
  uint uVar24;
  float *pfVar25;
  int iVar26;
  cXyz *pcVar27;
  int iVar28;
  undefined4 uVar29;
  undefined8 in_f27;
  undefined8 in_f28;
  undefined8 in_f29;
  undefined8 in_f30;
  undefined8 in_f31;
  float fVar30;
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar19 = d_menu_cloth::_4215;
  fVar18 = d_menu_cloth::_4210;
  fVar17 = d_menu_cloth::_4209;
  fVar16 = d_menu_cloth::_4208;
  fVar15 = d_menu_cloth::_4207;
  fVar14 = d_menu_cloth::_4206;
  fVar13 = d_menu_cloth::_4205;
  fVar12 = d_menu_cloth::_4204;
  fVar11 = d_menu_cloth::_4203;
  fVar10 = d_menu_cloth::_4202;
  fVar9 = d_menu_cloth::_4201;
  fVar8 = d_menu_cloth::_4077;
  fVar7 = d_menu_cloth::_4012;
  fVar30 = d_menu_cloth::_4006;
  uVar29 = 0;
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
  dVar2 = this[0x913c];
  pcVar27 = (cXyz *)(this + (uint)(byte)dVar2 * 0x14ac + 0x29a0);
  uVar20 = 0;
  iVar23 = 0;
  do {
    uVar21 = 0;
    uVar4 = uVar20 * -0xdac & 0xffff;
    iVar28 = 0xb;
    do {
      uVar24 = uVar21 ^ 0x80000000;
      fVar3 = fVar12 * (float)((double)CONCAT44(0x43300000,uVar24) - dVar19);
      uVar5 = (int)fVar3 & 0xffff;
      iVar26 = (uVar21 + iVar23) * 0xc;
      pfVar25 = (float *)(this + (uint)(byte)dVar2 * 0x14ac + iVar26 + 0x48);
      *pfVar25 = fVar9 + fVar11 * JKernel::JMath::jmaSinTable
                                  [(int)uVar5 >> (JKernel::JMath::jmaSinShift & 0x3f)] +
                 fVar13 * (float)((double)CONCAT44(0x43300000,uVar24) - dVar19) *
                 JKernel::JMath::jmaSinTable[(int)uVar4 >> (JKernel::JMath::jmaSinShift & 0x3f)];
      pfVar25[1] = fVar9 + fVar10 * (float)((double)CONCAT44(0x43300000,uVar20 ^ 0x80000000) -
                                           dVar19);
      pfVar25[2] = fVar14 + fVar15 * (fVar30 - JKernel::JMath::jmaCosTable
                                               [(int)uVar5 >> (JKernel::JMath::jmaSinShift & 0x3f)])
                   + fVar16 * (float)((double)CONCAT44(0x43300000,uVar24) - dVar19) *
                     JKernel::JMath::jmaCosTable[(int)uVar4 >> (JKernel::JMath::jmaSinShift & 0x3f)]
      ;
      iVar22 = (int)((int)(fVar3 - fVar7) & 0xffffU) >> (JKernel::JMath::jmaSinShift & 0x3f);
      fVar3 = JKernel::JMath::jmaSinTable[iVar22];
      pfVar25 = (float *)(this + iVar26 + 0x67a4);
      *pfVar25 = fVar18 * JKernel::JMath::jmaCosTable[iVar22];
      pfVar25[1] = fVar8;
      pfVar25[2] = fVar17 * fVar3;
      uVar21 = uVar21 + 1;
      iVar28 = iVar28 + -1;
    } while (iVar28 != 0);
    uVar20 = uVar20 + 1;
    iVar23 = iVar23 + 0xb;
  } while ((int)uVar20 < 0xb);
  iVar23 = 0;
  do {
    iVar28 = 0;
    do {
      setNrmVtx(this,pcVar27,iVar28,iVar23);
      iVar28 = iVar28 + 1;
      pcVar27 = pcVar27 + 1;
    } while (iVar28 < 0xb);
    iVar23 = iVar23 + 1;
  } while (iVar23 < 0xb);
  setBackNrm(this);
  *(undefined2 *)(this + 8) = 0;
  *(undefined2 *)(this + 10) = 0;
  cloth_move(this);
  this[0xc] = (dMCloth_c)0x0;
  this[0xd] = SUB21((&d_menu_cloth::l_HIO.field_0x30)[(uint)(byte)this[0x913d] * 0x2c],0);
  *(short *)(this + 8) =
       *(short *)(this + 8) + (&d_menu_cloth::l_HIO.field_0x3e)[(uint)(byte)this[0x913d] * 0x2c];
  os::DCStoreRangeNoSync(this + (uint)(byte)this[0x913c] * 0x14ac + 0x48,0x5ac);
  os::DCStoreRangeNoSync(this + (uint)(byte)this[0x913c] * 0x14ac + 0x29a0,0x5ac);
  os::DCStoreRangeNoSync(this + 0x52f8,0x5ac);
  this[0x915e] = SUB21((&d_menu_cloth::l_HIO.field_0x2a)[(uint)(byte)this[0x913d] * 0x2c],0);
  this[0x915f] = SUB21((&d_menu_cloth::l_HIO.field_0x2c)[(uint)(byte)this[0x913d] * 0x2c],0);
  this[0x9160] = SUB21((&d_menu_cloth::l_HIO.field_0x2e)[(uint)(byte)this[0x913d] * 0x2c],0);
  this[0x9161] = SUB21((&d_menu_cloth::l_HIO.field_0x30)[(uint)(byte)this[0x913d] * 0x2c],0);
  this[0x9162] = SUB21((&d_menu_cloth::l_HIO.field_0x32)[(uint)(byte)this[0x913d] * 0x2c],0);
  this[0x9163] = SUB21((&d_menu_cloth::l_HIO.field_0x34)[(uint)(byte)this[0x913d] * 0x2c],0);
  this[0x9164] = SUB21((&d_menu_cloth::l_HIO.field_0x36)[(uint)(byte)this[0x913d] * 0x2c],0);
  this[0x9165] = SUB21((&d_menu_cloth::l_HIO.field_0x38)[(uint)(byte)this[0x913d] * 0x2c],0);
  uVar20 = (uint)(byte)this[0x913d];
  if (uVar20 == 1) {
    *(float *)(this + 0x9140) = d_menu_cloth::_4014;
    *(float *)(this + 0x9144) = d_menu_cloth::_4015;
    *(float *)(this + 0x9148) = d_menu_cloth::_4006;
    *(undefined2 *)(this + 0x9158) = 0;
    *(undefined2 *)(this + 0x915a) = 0;
    *(undefined2 *)(this + 0x915c) = 0;
  }
  else {
    if (uVar20 == 0) {
      fVar30 = SComponent::cM_rndFX(d_menu_cloth::_4211);
      _init_angle_z =
           _init_angle_z + (short)(int)(d_menu_cloth::_4212 * (d_menu_cloth::_4078 + fVar30));
      uVar20 = (uint)(byte)this[0x913d];
      *(float *)(this + 0x9140) = (&d_menu_cloth::l_HIO.field_0xc)[uVar20 * 0x16];
      *(float *)(this + 0x9144) = (&d_menu_cloth::l_HIO.field_0x10)[uVar20 * 0x16];
      *(float *)(this + 0x9148) = (&d_menu_cloth::l_HIO.field_0x14)[uVar20 * 0x16];
      sVar6 = _init_angle_z;
      *(undefined2 *)(this + 0x9158) = 0;
      *(undefined2 *)(this + 0x915a) = 0;
      *(short *)(this + 0x915c) = sVar6;
      iVar23 = (int)(short)(&d_menu_cloth::l_HIO.field_0x58)[(uint)(byte)this[0x913d] * 0x2c];
      while (bVar1 = iVar23 != 0, iVar23 = iVar23 + -1, bVar1) {
        cloth_move_sin(this);
      }
    }
    else {
      if (uVar20 < 3) {
        *(float *)(this + 0x9140) = (&d_menu_cloth::l_HIO.field_0xc)[uVar20 * 0x16];
        *(float *)(this + 0x9144) = (&d_menu_cloth::l_HIO.field_0x10)[uVar20 * 0x16];
        *(float *)(this + 0x9148) = (&d_menu_cloth::l_HIO.field_0x14)[uVar20 * 0x16];
        uVar20 = (uint)(byte)this[0x913d];
        *(undefined2 *)(this + 0x9158) = (&d_menu_cloth::l_HIO.field_0x24)[uVar20 * 0x2c];
        *(undefined2 *)(this + 0x915a) = (&d_menu_cloth::l_HIO.field_0x26)[uVar20 * 0x2c];
        *(undefined2 *)(this + 0x915c) = (&d_menu_cloth::l_HIO.field_0x28)[uVar20 * 0x2c];
        fVar30 = SComponent::cM_rndFX(d_menu_cloth::_4213);
        *(short *)(this + 0x915c) =
             *(short *)(this + 0x915c) + (short)(int)(d_menu_cloth::_4212 * fVar30);
        iVar23 = (int)(short)(&d_menu_cloth::l_HIO.field_0x58)[(uint)(byte)this[0x913d] * 0x2c];
        while (bVar1 = iVar23 != 0, iVar23 = iVar23 + -1, bVar1) {
          cloth_move_sin(this);
        }
      }
    }
  }
  __psq_l0(auStack8,uVar29);
  __psq_l1(auStack8,uVar29);
  __psq_l0(auStack24,uVar29);
  __psq_l1(auStack24,uVar29);
  __psq_l0(auStack40,uVar29);
  __psq_l1(auStack40,uVar29);
  __psq_l0(auStack56,uVar29);
  __psq_l1(auStack56,uVar29);
  __psq_l0(auStack72,uVar29);
  __psq_l1(auStack72,uVar29);
  return;
}


/* __thiscall dMCloth_c::init(void) */

int __thiscall dMCloth_c::init(dMCloth_c *this,EVP_PKEY_CTX *ctx)

{
  _GXTexFmt *p_Var1;
  ulong uVar2;
  int iVar3;
  
  cloth_init(this);
  p_Var1 = (_GXTexFmt *)
           JKRArchive::getGlbResource(0x54494d47,"cloth_piece01.bti",*(JKRArchive **)(this + 0x44));
  if (p_Var1 == (_GXTexFmt *)0x0) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_menu_cloth.cpp",0x212,"image != 0");
    m_Do_printf::OSPanic("d_menu_cloth.cpp",0x212,"Halt");
  }
  gx::GXInitTexObj((GXTexObj *)(this + 0x90fc),p_Var1 + *(int *)(p_Var1 + 0x1c),
                   (uint)*(ushort *)(p_Var1 + 2),(uint)*(ushort *)(p_Var1 + 4),*p_Var1,p_Var1[6],
                   p_Var1[7],SUB41(1 - (uint)p_Var1[0x18] >> 0x1f,0));
  iVar3 = gx::GXInitTexObjLOD((double)(d_menu_cloth::_4277 *
                                      (float)((double)CONCAT44(0x43300000,
                                                               (int)(char)p_Var1[0x16] ^ 0x80000000)
                                             - d_menu_cloth::_4215)),
                              (double)(d_menu_cloth::_4277 *
                                      (float)((double)CONCAT44(0x43300000,
                                                               (int)(char)p_Var1[0x17] ^ 0x80000000)
                                             - d_menu_cloth::_4215)),
                              (double)(d_menu_cloth::_4278 *
                                      (float)((double)CONCAT44(0x43300000,
                                                               (int)*(short *)(p_Var1 + 0x1a) ^
                                                               0x80000000) - d_menu_cloth::_4215)),
                              this + 0x90fc,p_Var1[0x14],p_Var1[0x15],p_Var1[0x12],p_Var1[0x11],
                              p_Var1[0x13]);
  return iVar3;
}


/* __thiscall dMCloth_c::dMCloth_c(void) */

void __thiscall dMCloth_c::dMCloth_c(dMCloth_c *this)

{
  *(undefined1 **)this = &__vt;
  Runtime.PPCEABI.H::__construct_array(this + 0x48,::cXyz::cXyz,::cXyz::_cXyz,0xc,0x372);
  Runtime.PPCEABI.H::__construct_array(this + 0x29a0,::cXyz::cXyz,::cXyz::_cXyz,0xc,0x372);
  Runtime.PPCEABI.H::__construct_array(this + 0x52f8,::cXyz::cXyz,::cXyz::_cXyz,0xc,0x1b9);
  Runtime.PPCEABI.H::__construct_array(this + 0x67a4,::cXyz::cXyz,::cXyz::_cXyz,0xc,0x1b9);
  Runtime.PPCEABI.H::__construct_array(this + 0x7c50,::cXyz::cXyz,::cXyz::_cXyz,0xc,0x1b9);
  this[0x913c] = (dMCloth_c)0x0;
  *(undefined2 *)(this + 4) = 0;
  this[0x913d] = (dMCloth_c)0x0;
  if (d_menu_cloth::l_HIO._4_1_ < '\0') {
    d_menu_cloth::l_HIO._4_1_ =
         mDoHIO_subRoot_c::createChild
                   (&mDoHIO_subRoot_c_803a5778,"メニューの布",
                    (JORReflexible *)&d_menu_cloth::l_HIO);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dMCloth_c::~dMCloth_c(void) */

void __thiscall dMCloth_c::_dMCloth_c(dMCloth_c *this)

{
  short in_r4;
  
  if (this != (dMCloth_c *)0x0) {
    *(undefined1 **)this = &__vt;
    if (-1 < d_menu_cloth::l_HIO._4_1_) {
      mDoHIO_subRoot_c::deleteChild(&mDoHIO_subRoot_c_803a5778,d_menu_cloth::l_HIO._4_1_);
      d_menu_cloth::l_HIO._4_1_ = -1;
    }
    (**(code **)(**(int **)(this + 0x44) + 0x24))();
    Runtime.PPCEABI.H::__destroy_arr(this + 0x7c50,::cXyz::_cXyz,0xc,0x1b9);
    Runtime.PPCEABI.H::__destroy_arr(this + 0x67a4,::cXyz::_cXyz,0xc,0x1b9);
    Runtime.PPCEABI.H::__destroy_arr(this + 0x52f8,::cXyz::_cXyz,0xc,0x1b9);
    Runtime.PPCEABI.H::__destroy_arr(this + 0x29a0,::cXyz::_cXyz,0xc,0x372);
    Runtime.PPCEABI.H::__destroy_arr(this + 0x48,::cXyz::_cXyz,0xc,0x372);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall dMCloth_c::setBackNrm(void) */

void __thiscall dMCloth_c::setBackNrm(dMCloth_c *this)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  float *pfVar4;
  int iVar5;
  
  pfVar4 = (float *)(this + (uint)(byte)this[0x913c] * 0x14ac + 0x29a0);
  pfVar3 = (float *)(this + 0x52f8);
  iVar5 = 0x1b9;
  do {
    fVar1 = pfVar4[2];
    fVar2 = pfVar4[1];
    *pfVar3 = -*pfVar4;
    pfVar3[1] = -fVar2;
    pfVar3[2] = -fVar1;
    pfVar4 = pfVar4 + 3;
    pfVar3 = pfVar3 + 3;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  return;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dMCloth_c::setNrmVtx(cXyz *,
                                   int,
                                   int) */

void __thiscall dMCloth_c::setNrmVtx(dMCloth_c *this,cXyz *param_1,int param_2,int param_3)

{
  float fVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  dMCloth_c *pdVar5;
  cXyz local_108;
  cXyz local_fc;
  cXyz local_f0;
  cXyz local_e4;
  cXyz local_d8;
  cXyz local_cc;
  cXyz local_c0;
  cXyz local_b4;
  cXyz local_a8;
  cXyz local_9c;
  cXyz local_90;
  cXyz local_84;
  cXyz local_78;
  cXyz local_6c;
  cXyz local_60;
  cXyz local_54;
  cXyz local_48;
  cXyz local_3c;
  cXyz local_30;
  longlong local_20;
  
  pdVar5 = this + (uint)(byte)this[0x913c] * 0x14ac + 0x48;
  iVar4 = param_2 + param_3 * 0xb;
  iVar2 = iVar4 * 0xc;
  local_60.x = *(float *)(pdVar5 + iVar2);
  local_60.y = *(float *)(pdVar5 + iVar2 + 4);
  local_60.z = *(float *)(pdVar5 + iVar2 + 8);
  local_54.x = d_menu_cloth::_4077;
  local_54.y = d_menu_cloth::_4077;
  local_54.z = d_menu_cloth::_4077;
  if (param_2 != 0) {
    ::cXyz::operator__(&local_6c,(cXyz *)(pdVar5 + (iVar4 + -1) * 0xc),&local_60);
    local_30.x = local_6c.x;
    local_30.y = local_6c.y;
    local_30.z = local_6c.z;
    if (param_3 != 0) {
      ::cXyz::operator__(&local_78,(cXyz *)(pdVar5 + (param_2 + (param_3 + -1) * 0xb) * 0xc),
                         &local_60);
      local_3c.x = local_78.x;
      local_3c.y = local_78.y;
      local_3c.z = local_78.z;
      ::cXyz::outprod(&local_84,&local_30,&local_3c);
      local_48.x = local_84.x;
      local_48.y = local_84.y;
      local_48.z = local_84.z;
      ::cXyz::normZP(&local_90,&local_48);
      local_48.x = local_90.x;
      local_48.y = local_90.y;
      local_48.z = local_90.z;
      mtx::PSVECAdd(&local_54,&local_48,&local_54);
    }
    if (param_3 != 10) {
      ::cXyz::operator__(&local_9c,(cXyz *)(pdVar5 + (param_2 + (param_3 + 1) * 0xb) * 0xc),
                         &local_60);
      local_3c.x = local_9c.x;
      local_3c.y = local_9c.y;
      local_3c.z = local_9c.z;
      ::cXyz::outprod(&local_a8,&local_3c,&local_30);
      local_48.x = local_a8.x;
      local_48.y = local_a8.y;
      local_48.z = local_a8.z;
      ::cXyz::normZP(&local_b4,&local_48);
      local_48.x = local_b4.x;
      local_48.y = local_b4.y;
      local_48.z = local_b4.z;
      mtx::PSVECAdd(&local_54,&local_48,&local_54);
    }
  }
  if (param_2 != 10) {
    ::cXyz::operator__(&local_c0,(cXyz *)(pdVar5 + (param_2 + param_3 * 0xb + 1) * 0xc),&local_60);
    local_30.x = local_c0.x;
    local_30.y = local_c0.y;
    local_30.z = local_c0.z;
    if (param_3 != 0) {
      ::cXyz::operator__(&local_cc,(cXyz *)(pdVar5 + (param_2 + (param_3 + -1) * 0xb) * 0xc),
                         &local_60);
      local_3c.x = local_cc.x;
      local_3c.y = local_cc.y;
      local_3c.z = local_cc.z;
      ::cXyz::outprod(&local_d8,&local_3c,&local_30);
      local_48.x = local_d8.x;
      local_48.y = local_d8.y;
      local_48.z = local_d8.z;
      ::cXyz::normZP(&local_e4,&local_48);
      local_48.x = local_e4.x;
      local_48.y = local_e4.y;
      local_48.z = local_e4.z;
      mtx::PSVECAdd(&local_54,&local_48,&local_54);
    }
    if (param_3 != 10) {
      ::cXyz::operator__(&local_f0,(cXyz *)(pdVar5 + (param_2 + (param_3 + 1) * 0xb) * 0xc),
                         &local_60);
      local_3c.x = local_f0.x;
      local_3c.y = local_f0.y;
      local_3c.z = local_f0.z;
      ::cXyz::outprod(&local_fc,&local_30,&local_3c);
      local_48.x = local_fc.x;
      local_48.y = local_fc.y;
      local_48.z = local_fc.z;
      ::cXyz::normZP(&local_108,&local_48);
      local_48.x = local_108.x;
      local_48.y = local_108.y;
      local_48.z = local_108.z;
      mtx::PSVECAdd(&local_54,&local_48,&local_54);
    }
  }
  SComponent::MtxPush();
  local_20 = (longlong)
             (int)(d_menu_cloth::_4451 *
                  JKernel::JMath::jmaSinTable
                  [(int)(param_2 * -800 & 0xffffU) >> (JKernel::JMath::jmaSinShift & 0x3f)]);
  m_Do_mtx::mDoMtx_YrotM
            (SComponent::calc_mtx,
             (short)(int)(d_menu_cloth::_4451 *
                         JKernel::JMath::jmaSinTable
                         [(int)(param_2 * -800 & 0xffffU) >> (JKernel::JMath::jmaSinShift & 0x3f)]))
  ;
  SComponent::MtxPosition(&local_54,param_1);
  cVar3 = ::cXyz::normalizeRS(param_1);
  fVar1 = d_menu_cloth::_4077;
  if (cVar3 == '\0') {
    param_1->x = d_menu_cloth::_4077;
    param_1->y = fVar1;
    param_1->z = d_menu_cloth::_4006;
  }
  SComponent::MtxPull();
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x8019a528) */
/* WARNING: Removing unreachable block (ram,0x8019a63c) */
/* WARNING: Removing unreachable block (ram,0x8019a62c) */
/* WARNING: Removing unreachable block (ram,0x8019a624) */
/* WARNING: Removing unreachable block (ram,0x8019a634) */
/* __thiscall dMCloth_c::plot(float,
                              float,
                              float,
                              float) */

void __thiscall
dMCloth_c::plot(dMCloth_c *this,float param_1,float param_2,float param_3,float param_4)

{
  float fVar1;
  dMCloth_c dVar2;
  short sVar5;
  int iVar3;
  int iVar4;
  short sVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  double dVar13;
  double dVar14;
  undefined8 in_f28;
  undefined8 in_f29;
  double dVar15;
  undefined8 in_f30;
  double dVar16;
  undefined8 in_f31;
  double dVar17;
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar14 = (double)param_4;
  uVar12 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  dVar16 = (double)(d_menu_cloth::_4530 * (param_3 - param_1));
  dVar15 = (double)(d_menu_cloth::_4530 * (float)(dVar14 - (double)param_2));
  iVar10 = 1;
  iVar9 = 0;
  fVar1 = d_menu_cloth::_4077;
  do {
    dVar17 = (double)fVar1;
    gx::GXBegin(0x98,0,0x16);
    iVar8 = 0;
    sVar6 = 0;
    iVar11 = 0xb;
    dVar13 = dVar14;
    do {
      dVar2 = this[0x913d];
      if (dVar2 == (dMCloth_c)0x1) {
        iVar7 = ((10 - iVar9) + iVar8) * 0x19;
        iVar3 = 0xff;
        if (iVar7 < 0x100) {
          iVar3 = iVar7;
        }
        iVar4 = ((10 - iVar10) + iVar8) * 0x19;
        iVar7 = 0xff;
        if (iVar4 < 0x100) {
          iVar7 = iVar4;
        }
        sVar5 = (short)iVar9 + sVar6;
        write_volatile_2(0xcc008000,sVar5);
        write_volatile_2(0xcc008000,sVar5);
        write_volatile_1(DAT_cc008000,this[0x915e]);
        write_volatile_1(DAT_cc008000,this[0x915f]);
        write_volatile_1(DAT_cc008000,this[0x9160]);
        write_volatile_1(DAT_cc008000,(char)iVar3);
        write_volatile_4(0xcc008000,(float)dVar17);
        write_volatile_4(0xcc008000,(float)dVar13);
        sVar5 = (short)iVar10 + sVar6;
        write_volatile_2(0xcc008000,sVar5);
        write_volatile_2(0xcc008000,sVar5);
        write_volatile_1(DAT_cc008000,this[0x915e]);
        write_volatile_1(DAT_cc008000,this[0x915f]);
        write_volatile_1(DAT_cc008000,this[0x9160]);
        write_volatile_1(DAT_cc008000,(char)iVar7);
        write_volatile_4(0xcc008000,(float)(dVar17 + dVar16));
        write_volatile_4(0xcc008000,(float)dVar13);
      }
      else {
        if ((dVar2 == (dMCloth_c)0x0) || ((byte)dVar2 < 3)) {
          sVar5 = (short)iVar9 + sVar6;
          write_volatile_2(0xcc008000,sVar5);
          write_volatile_2(0xcc008000,sVar5);
          write_volatile_4(0xcc008000,(float)dVar17);
          write_volatile_4(0xcc008000,(float)dVar13);
          sVar5 = (short)iVar10 + sVar6;
          write_volatile_2(0xcc008000,sVar5);
          write_volatile_2(0xcc008000,sVar5);
          write_volatile_4(0xcc008000,(float)(dVar17 + dVar16));
          write_volatile_4(0xcc008000,(float)dVar13);
        }
      }
      dVar13 = (double)(float)(dVar13 - dVar15);
      iVar8 = iVar8 + 1;
      sVar6 = sVar6 + 0xb;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
    fVar1 = (float)(dVar17 + dVar16);
    iVar9 = iVar9 + 1;
    iVar10 = iVar10 + 1;
  } while (iVar9 < 10);
  __psq_l0(auStack8,uVar12);
  __psq_l1(auStack8,uVar12);
  __psq_l0(auStack24,uVar12);
  __psq_l1(auStack24,uVar12);
  __psq_l0(auStack40,uVar12);
  __psq_l1(auStack40,uVar12);
  __psq_l0(auStack56,uVar12);
  __psq_l1(auStack56,uVar12);
  return;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* WARNING: Removing unreachable block (ram,0x8019a704) */
/* WARNING: Removing unreachable block (ram,0x8019a818) */
/* WARNING: Removing unreachable block (ram,0x8019a808) */
/* WARNING: Removing unreachable block (ram,0x8019a800) */
/* WARNING: Removing unreachable block (ram,0x8019a810) */
/* __thiscall dMCloth_c::plot_shadow(float,
                                     float,
                                     float,
                                     float) */

void __thiscall
dMCloth_c::plot_shadow(dMCloth_c *this,float param_1,float param_2,float param_3,float param_4)

{
  float fVar1;
  dMCloth_c dVar2;
  short sVar5;
  int iVar3;
  int iVar4;
  short sVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  double dVar13;
  double dVar14;
  undefined8 in_f28;
  undefined8 in_f29;
  double dVar15;
  undefined8 in_f30;
  double dVar16;
  undefined8 in_f31;
  double dVar17;
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  dVar14 = (double)param_4;
  uVar12 = 0;
  __psq_st0(auStack8,(int)((ulonglong)in_f31 >> 0x20),0);
  __psq_st1(auStack8,(int)in_f31,0);
  __psq_st0(auStack24,(int)((ulonglong)in_f30 >> 0x20),0);
  __psq_st1(auStack24,(int)in_f30,0);
  __psq_st0(auStack40,(int)((ulonglong)in_f29 >> 0x20),0);
  __psq_st1(auStack40,(int)in_f29,0);
  __psq_st0(auStack56,(int)((ulonglong)in_f28 >> 0x20),0);
  __psq_st1(auStack56,(int)in_f28,0);
  dVar16 = (double)(d_menu_cloth::_4530 * (param_3 - param_1));
  dVar15 = (double)(d_menu_cloth::_4530 * (float)(dVar14 - (double)param_2));
  iVar10 = 1;
  iVar9 = 0;
  fVar1 = d_menu_cloth::_4077;
  do {
    dVar17 = (double)fVar1;
    gx::GXBegin(0x98,0,0x16);
    iVar8 = 0;
    sVar6 = 0;
    iVar11 = 0xb;
    dVar13 = dVar14;
    do {
      dVar2 = this[0x913d];
      if (dVar2 == (dMCloth_c)0x1) {
        iVar7 = ((10 - iVar9) + iVar8) * 0x19;
        iVar3 = 0xff;
        if (iVar7 < 0x100) {
          iVar3 = iVar7;
        }
        iVar4 = ((10 - iVar10) + iVar8) * 0x19;
        iVar7 = 0xff;
        if (iVar4 < 0x100) {
          iVar7 = iVar4;
        }
        sVar5 = (short)iVar9 + sVar6;
        write_volatile_2(0xcc008000,sVar5);
        write_volatile_2(0xcc008000,sVar5);
        write_volatile_1(DAT_cc008000,this[0x9162]);
        write_volatile_1(DAT_cc008000,this[0x9163]);
        write_volatile_1(DAT_cc008000,this[0x9164]);
        write_volatile_1(DAT_cc008000,(char)iVar3);
        write_volatile_4(0xcc008000,(float)dVar17);
        write_volatile_4(0xcc008000,(float)dVar13);
        sVar5 = (short)iVar10 + sVar6;
        write_volatile_2(0xcc008000,sVar5);
        write_volatile_2(0xcc008000,sVar5);
        write_volatile_1(DAT_cc008000,this[0x9162]);
        write_volatile_1(DAT_cc008000,this[0x9163]);
        write_volatile_1(DAT_cc008000,this[0x9164]);
        write_volatile_1(DAT_cc008000,(char)iVar7);
        write_volatile_4(0xcc008000,(float)(dVar17 + dVar16));
        write_volatile_4(0xcc008000,(float)dVar13);
      }
      else {
        if ((dVar2 == (dMCloth_c)0x0) || ((byte)dVar2 < 3)) {
          sVar5 = (short)iVar9 + sVar6;
          write_volatile_2(0xcc008000,sVar5);
          write_volatile_2(0xcc008000,sVar5);
          write_volatile_4(0xcc008000,(float)dVar17);
          write_volatile_4(0xcc008000,(float)dVar13);
          sVar5 = (short)iVar10 + sVar6;
          write_volatile_2(0xcc008000,sVar5);
          write_volatile_2(0xcc008000,sVar5);
          write_volatile_4(0xcc008000,(float)(dVar17 + dVar16));
          write_volatile_4(0xcc008000,(float)dVar13);
        }
      }
      dVar13 = (double)(float)(dVar13 - dVar15);
      iVar8 = iVar8 + 1;
      sVar6 = sVar6 + 0xb;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
    fVar1 = (float)(dVar17 + dVar16);
    iVar9 = iVar9 + 1;
    iVar10 = iVar10 + 1;
  } while (iVar9 < 10);
  __psq_l0(auStack8,uVar12);
  __psq_l1(auStack8,uVar12);
  __psq_l0(auStack24,uVar12);
  __psq_l1(auStack24,uVar12);
  __psq_l0(auStack40,uVar12);
  __psq_l1(auStack40,uVar12);
  __psq_l0(auStack56,uVar12);
  __psq_l1(auStack56,uVar12);
  return;
}


/* __thiscall dMCloth_c::alpha_out(void) */

void __thiscall dMCloth_c::alpha_out(dMCloth_c *this)

{
  this[0xc] = (dMCloth_c)0x1;
  return;
}


/* __thiscall dMCloth_c::TevSettingMenu(void) */

void __thiscall dMCloth_c::TevSettingMenu(dMCloth_c *this)

{
  gx::GXSetChanCtrl(GX_COLOR0,true,GX_SRC_REG,GX_SRC_REG,1,GX_DF_CLAMP,GX_AF_NONE);
  gx::GXSetNumTexGens(1);
  gx::GXSetTexCoordGen2(GX_TEXCOORD0,GX_TG_MTX2x4,GX_TG_TEX0,GX_IDENTITY,false,GX_PTIDENTITY);
  gx::GXSetNumTevStages(2);
  gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD0,GX_TEXMAP0,GX_COLOR0A0);
  gx::GXSetTevSwapMode(0,1,0);
  gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_C1,GX_CC_C0,GX_CC_TEXC,GX_CC_ZERO);
  gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO);
  gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetTevSwapMode(1,0,0);
  gx::GXSetTevOrder(GX_TEVSTAGE1,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR_NULL);
  gx::GXSetTevColorIn(GX_TEVSTAGE1,GX_CC_ZERO,GX_CC_ZERO,GX_CC_ZERO,GX_CC_CPREV);
  gx::GXSetTevColorOp(GX_TEVSTAGE1,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetTevAlphaIn(GX_TEVSTAGE1,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_A0);
  gx::GXSetTevAlphaOp(GX_TEVSTAGE1,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  return;
}


/* __thiscall dMCloth_c::TevSettingFileSelect(void) */

void __thiscall dMCloth_c::TevSettingFileSelect(dMCloth_c *this)

{
  gx::GXSetChanCtrl(GX_COLOR0,true,GX_SRC_REG,GX_SRC_REG,1,GX_DF_CLAMP,GX_AF_NONE);
  gx::GXSetChanCtrl(GX_ALPHA0,false,GX_SRC_VTX,GX_SRC_VTX,0,GX_DF_CLAMP,GX_AF_NONE);
  gx::GXSetNumTexGens(1);
  gx::GXSetTexCoordGen2(GX_TEXCOORD0,GX_TG_MTX2x4,GX_TG_TEX0,GX_IDENTITY,false,GX_PTIDENTITY);
  gx::GXSetNumTevStages(2);
  gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD0,GX_TEXMAP0,GX_COLOR0A0);
  gx::GXSetTevSwapMode(0,1,0);
  gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_C1,GX_CC_C0,GX_CC_TEXC,GX_CC_ZERO);
  gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_A0,GX_CA_RASA,GX_CA_ZERO);
  gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetTevSwapMode(1,0,0);
  gx::GXSetTevOrder(GX_TEVSTAGE1,GX_TEXCOORD_NULL,GX_TEXMAP_NULL,GX_COLOR0A0);
  gx::GXSetTevColorIn(GX_TEVSTAGE1,GX_CC_ZERO,GX_CC_ZERO,GX_CC_ZERO,GX_CC_CPREV);
  gx::GXSetTevColorOp(GX_TEVSTAGE1,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetTevAlphaIn(GX_TEVSTAGE1,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_APREV);
  gx::GXSetTevAlphaOp(GX_TEVSTAGE1,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  return;
}


/* WARNING: Removing unreachable block (ram,0x8019ab8c) */
/* __thiscall dMCloth_c::TevSetting(void) */

void __thiscall dMCloth_c::TevSetting(dMCloth_c *this)

{
  dMCloth_c dVar1;
  
  dVar1 = this[0x913d];
  if (dVar1 == (dMCloth_c)0x1) {
    TevSettingFileSelect(this);
  }
  else {
    if ((dVar1 == (dMCloth_c)0x0) || ((byte)dVar1 < 3)) {
      TevSettingMenu(this);
    }
  }
  return;
}


/* __thiscall dMCloth_c::ShadowTevSettingMenu(void) */

void __thiscall dMCloth_c::ShadowTevSettingMenu(dMCloth_c *this)

{
  gx::GXSetChanCtrl(GX_COLOR0,true,GX_SRC_REG,GX_SRC_REG,1,GX_DF_CLAMP,GX_AF_NONE);
  gx::GXSetNumTexGens(1);
  gx::GXSetNumTevStages(1);
  gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD0,GX_TEXMAP0,GX_COLOR0A0);
  gx::GXSetTevSwapMode(0,1,0);
  gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_ZERO,GX_CC_ZERO,GX_CC_ZERO,GX_CC_ZERO);
  gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_ZERO,GX_CA_ZERO,GX_CA_A1);
  gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  return;
}


/* __thiscall dMCloth_c::ShadowTevSettingFileSelect(void) */

void __thiscall dMCloth_c::ShadowTevSettingFileSelect(dMCloth_c *this)

{
  gx::GXSetChanCtrl(GX_COLOR0,true,GX_SRC_REG,GX_SRC_REG,1,GX_DF_CLAMP,GX_AF_NONE);
  gx::GXSetChanCtrl(GX_ALPHA0,false,GX_SRC_VTX,GX_SRC_VTX,0,GX_DF_CLAMP,GX_AF_NONE);
  gx::GXSetNumTexGens(1);
  gx::GXSetNumTevStages(1);
  gx::GXSetTevOrder(GX_TEVSTAGE0,GX_TEXCOORD0,GX_TEXMAP0,GX_COLOR0A0);
  gx::GXSetTevSwapMode(0,1,0);
  gx::GXSetTevColorIn(GX_TEVSTAGE0,GX_CC_ZERO,GX_CC_ZERO,GX_CC_ZERO,GX_CC_ZERO);
  gx::GXSetTevColorOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  gx::GXSetTevAlphaIn(GX_TEVSTAGE0,GX_CA_ZERO,GX_CA_A1,GX_CA_RASA,GX_CA_ZERO);
  gx::GXSetTevAlphaOp(GX_TEVSTAGE0,GX_TEV_ADD,GX_TB_ZERO,GX_CS_SCALE_1,true,GX_TEVPREV);
  return;
}


/* WARNING: Removing unreachable block (ram,0x8019adac) */
/* __thiscall dMCloth_c::ShadowTevSetting(void) */

void __thiscall dMCloth_c::ShadowTevSetting(dMCloth_c *this)

{
  dMCloth_c dVar1;
  
  dVar1 = this[0x913d];
  if (dVar1 == (dMCloth_c)0x1) {
    ShadowTevSettingFileSelect(this);
  }
  else {
    if ((dVar1 == (dMCloth_c)0x0) || ((byte)dVar1 < 3)) {
      ShadowTevSettingMenu(this);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* WARNING: Removing unreachable block (ram,0x8019b098) */
/* __thiscall dMCloth_c::draw(float,
                              _GXColor,
                              _GXColor,
                              unsigned char) */

void __thiscall
dMCloth_c::draw(dMCloth_c *this,float param_1,_GXColor *param_2,_GXColor *param_3,uchar param_4)

{
  dMCloth_c dVar1;
  short sVar2;
  float fVar3;
  float fVar4;
  ResTIMG *pRVar5;
  short sVar7;
  uint uVar6;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int iVar10;
  undefined3 in_register_00000018;
  int iVar11;
  _GXColor local_b8;
  _GXColor local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  cXyz local_90;
  float local_84;
  float local_80;
  float local_7c;
  GXTexObj GStack120;
  undefined4 local_58;
  uint uStack84;
  undefined4 local_50;
  uint uStack76;
  undefined4 local_48;
  uint uStack68;
  undefined4 local_40;
  uint uStack60;
  longlong local_38;
  undefined4 local_30;
  uint uStack44;
  undefined4 local_28;
  uint uStack36;
  double local_20;
  
  fVar3 = d_menu_cloth::_4793;
  puVar8 = (undefined4 *)(this + (uint)(byte)this[0x913c] * 0x14ac + 0x48);
  puVar9 = (undefined4 *)(this + 0x7c50);
  iVar10 = 0;
  do {
    iVar11 = 0xb;
    do {
      *puVar9 = *puVar8;
      puVar9[1] = puVar8[1];
      puVar9[2] = puVar8[2];
      puVar9[2] = fVar3;
      puVar9 = puVar9 + 3;
      puVar8 = puVar8 + 3;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
    iVar10 = iVar10 + 1;
  } while (iVar10 < 0xb);
  os::DCStoreRangeNoSync(this + 0x7c50,0x5ac,iVar10,CONCAT31(in_register_00000018,param_4));
  *(dMCloth_c *)&param_2->r = this[0x915e];
  *(dMCloth_c *)&param_2->g = this[0x915f];
  *(dMCloth_c *)&param_2->b = this[0x9160];
  *(dMCloth_c *)&param_2->a = this[0x9161];
  *(dMCloth_c *)&param_3->r = this[0x9162];
  *(dMCloth_c *)&param_3->g = this[0x9163];
  *(dMCloth_c *)&param_3->b = this[0x9164];
  *(dMCloth_c *)&param_3->a = this[0x9165];
  if (this[0xc] == (dMCloth_c)0x1) {
    *(dMCloth_c *)&param_2->a = this[0xd];
    if ((byte)this[0xd] < 0x1a) {
      this[0xd] = (dMCloth_c)0x0;
    }
    else {
      this[0xd] = (dMCloth_c)((char)this[0xd] - 0x19);
    }
  }
  else {
    uStack84 = (int)*(short *)(this + 10) ^ 0x80000000;
    local_58 = 0x43300000;
    uStack76 = (int)(short)(&d_menu_cloth::l_HIO.field_0x3c)[(uint)(byte)this[0x913d] * 0x2c] ^
               0x80000000;
    local_50 = 0x43300000;
    fVar3 = (float)((double)CONCAT44(0x43300000,uStack84) - d_menu_cloth::_4215) /
            (float)((double)CONCAT44(0x43300000,uStack76) - d_menu_cloth::_4215);
    sVar2 = (&d_menu_cloth::l_HIO.field_0x30)[(uint)(byte)this[0x913d] * 0x2c];
    if (sVar2 < 0) {
      sVar7 = 0;
    }
    else {
      sVar7 = 0xff;
      if (sVar2 < 0x100) {
        sVar7 = sVar2;
      }
    }
    param_2->a = (u8)sVar7;
    uStack68 = (uint)param_2->a;
    local_48 = 0x43300000;
    fVar4 = d_menu_cloth::_4006 - fVar3;
    uStack60 = (int)(short)(&d_menu_cloth::l_HIO.field_0x3a)[(uint)(byte)this[0x913d] * 0x2c] ^
               0x80000000;
    local_40 = 0x43300000;
    iVar10 = (int)((float)((double)CONCAT44(0x43300000,uStack68) - d_menu_cloth::_4804) * fVar3 +
                  fVar4 * (float)((double)CONCAT44(0x43300000,uStack60) - d_menu_cloth::_4215));
    local_38 = (longlong)iVar10;
    param_2->a = (u8)iVar10;
    sVar2 = (&d_menu_cloth::l_HIO.field_0x38)[(uint)(byte)this[0x913d] * 0x2c];
    if (sVar2 < 0) {
      sVar7 = 0;
    }
    else {
      sVar7 = 0xff;
      if (sVar2 < 0x100) {
        sVar7 = sVar2;
      }
    }
    param_3->a = (u8)sVar7;
    uStack44 = (uint)param_3->a;
    local_30 = 0x43300000;
    uStack36 = (int)(short)(&d_menu_cloth::l_HIO.field_0x3a)[(uint)(byte)this[0x913d] * 0x2c] ^
               0x80000000;
    local_28 = 0x43300000;
    iVar10 = (int)((float)((double)CONCAT44(0x43300000,uStack44) - d_menu_cloth::_4804) * fVar3 +
                  fVar4 * (float)((double)CONCAT44(0x43300000,uStack36) - d_menu_cloth::_4215));
    local_20 = (double)(longlong)iVar10;
    param_3->a = (u8)iVar10;
  }
  J3DSys::reinitGX(&J3DGraphBase::j3dSys);
  gx::GXSetNumIndStages(0);
  local_84 = d_menu_cloth::_4077;
  local_80 = d_menu_cloth::_4077;
  local_7c = d_menu_cloth::_4077;
  dVar1 = this[0x913d];
  if (dVar1 == (dMCloth_c)0x1) {
    gx::GXClearVtxDesc();
    gx::GXSetVtxDesc(GX_VA_POS,GX_INDEX16);
    gx::GXSetVtxDesc(GX_VA_NRM,GX_INDEX16);
    gx::GXSetVtxDesc(GX_VA_CLR0,GX_DIRECT);
    gx::GXSetVtxDesc(GX_VA_TEX0,GX_DIRECT);
    gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_F32,0);
    gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_NRM,GX_CLR_RGB,GX_F32,0);
    gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_CLR0,GX_CLR_RGBA,GX_RGBA8,0);
    gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX0,GX_CLR_RGBA,GX_F32,0);
    local_a8 = d_menu_cloth::_4660;
    local_a4 = d_menu_cloth::_4660;
    gx::GXSetChanAmbColor(0,&local_a4);
    local_b0 = d_menu_cloth::_4663;
    local_ac = d_menu_cloth::_4663;
    gx::GXSetChanMatColor(0,&local_ac);
  }
  else {
    if ((dVar1 == (dMCloth_c)0x0) || ((byte)dVar1 < 3)) {
      gx::GXClearVtxDesc();
      gx::GXSetVtxDesc(GX_VA_POS,GX_INDEX16);
      gx::GXSetVtxDesc(GX_VA_NRM,GX_INDEX16);
      gx::GXSetVtxDesc(GX_VA_TEX0,GX_DIRECT);
      gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_POS,GX_CLR_RGBA,GX_F32,0);
      gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_NRM,GX_CLR_RGB,GX_F32,0);
      gx::GXSetVtxAttrFmt(GX_VTXFMT0,GX_VA_TEX0,GX_CLR_RGBA,GX_F32,0);
      local_98 = d_menu_cloth::_4653;
      local_94 = d_menu_cloth::_4653;
      gx::GXSetChanAmbColor(0,&local_94);
      local_a0 = d_menu_cloth::_4656;
      local_9c = d_menu_cloth::_4656;
      gx::GXSetChanMatColor(0,&local_9c);
    }
  }
  local_b4 = *param_2;
  gx::GXSetTevColor(GX_TEVREG0,&local_b4);
  local_b8 = *param_3;
  gx::GXSetTevColor(GX_TEVREG1,&local_b8);
  pRVar5 = dDlst_list_c::mToonImage;
  gx::GXInitTexObj(&GStack120,
                   &dDlst_list_c::mToonImage->mTexFmt + dDlst_list_c::mToonImage->mTexDataOffs,
                   (uint)dDlst_list_c::mToonImage->mWidth,(uint)dDlst_list_c::mToonImage->mHeight,
                   dDlst_list_c::mToonImage->mTexFmt,dDlst_list_c::mToonImage->mWrapS,
                   dDlst_list_c::mToonImage->mWrapT,
                   SUB41(1 - (uint)dDlst_list_c::mToonImage->mMipmapCount >> 0x1f,0));
  local_20 = (double)CONCAT44(0x43300000,(int)(char)pRVar5->mMinLOD ^ 0x80000000);
  uStack36 = (int)(char)pRVar5->mMaxLOD ^ 0x80000000;
  local_28 = 0x43300000;
  uStack44 = (int)pRVar5->mLODBias ^ 0x80000000;
  local_30 = 0x43300000;
  gx::GXInitTexObjLOD((double)(d_menu_cloth::_4277 * (float)(local_20 - d_menu_cloth::_4215)),
                      (double)(d_menu_cloth::_4277 *
                              (float)((double)CONCAT44(0x43300000,uStack36) - d_menu_cloth::_4215)),
                      (double)(d_menu_cloth::_4278 *
                              (float)((double)CONCAT44(0x43300000,uStack44) - d_menu_cloth::_4215)),
                      &GStack120,pRVar5->mMinFilter,pRVar5->mMagFilter,pRVar5->mbBiasClamp,
                      pRVar5->mbDoEdgeLOD,pRVar5->mMaxAniso);
  gx::GXLoadTexObj((GXTexObj *)(this + 0x90fc),0);
  gx::GXLoadTexObj(&GStack120,1);
  gx::GXSetNumChans(1);
  gx::GXCallDisplayList(&d_menu_cloth::l_matDL,0x20);
  local_90.x = local_84;
  local_90.y = local_80;
  local_90.z = local_7c;
  lightSet1(this,&local_90);
  uVar6 = (uint)(byte)this[0x913d];
  if ((uVar6 < 3) && (uVar6 != 0)) {
    mtx::PSMTXTrans((double)(d_menu_cloth::_4794 + (&d_menu_cloth::l_HIO.field_0x18)[uVar6 * 0x16]),
                    (double)((&d_menu_cloth::l_HIO.field_0x1c)[uVar6 * 0x16] - d_menu_cloth::_4795),
                    (double)(d_menu_cloth::_4796 + (&d_menu_cloth::l_HIO.field_0x20)[uVar6 * 0x16]),
                    &mDoMtx_stack_c::now);
    m_Do_mtx::mDoMtx_XrotM(&mDoMtx_stack_c::now,*(short *)(this + 0x9158));
    m_Do_mtx::mDoMtx_YrotM(&mDoMtx_stack_c::now,*(short *)(this + 0x915a));
    m_Do_mtx::mDoMtx_ZrotM(&mDoMtx_stack_c::now,*(short *)(this + 0x915c));
    mDoMtx_stack_c::scaleM
              (*(float *)(this + 0x9140),*(float *)(this + 0x9144),*(float *)(this + 0x9148));
    mDoMtx_stack_c::transM(d_menu_cloth::_4077,d_menu_cloth::_4077,d_menu_cloth::_4797);
    gx::GXLoadPosMtxImm(&mDoMtx_stack_c::now,0);
    gx::GXLoadNrmMtxImm(&mDoMtx_stack_c::now,0);
    gx::GXSetCullMode(1);
    gx::GXSetCurrentMtx(0);
    gx::GXSetArray(GX_VA_POS,this + (uint)(byte)this[0x913c] * 0x14ac + 0x48,0xc);
    gx::GXSetArray(GX_VA_NRM,this + (uint)(byte)this[0x913c] * 0x14ac + 0x29a0,0xc);
    ShadowTevSetting(this);
    plot(this,d_menu_cloth::_4077,d_menu_cloth::_4077,d_menu_cloth::_4205,d_menu_cloth::_4205);
  }
  uVar6 = (uint)(byte)this[0x913d];
  mtx::PSMTXTrans((double)(d_menu_cloth::_4798 + (&d_menu_cloth::l_HIO.field_0x18)[uVar6 * 0x16]),
                  (double)(&d_menu_cloth::l_HIO.field_0x1c)[uVar6 * 0x16],
                  (double)(d_menu_cloth::_4796 + (&d_menu_cloth::l_HIO.field_0x20)[uVar6 * 0x16]),
                  &mDoMtx_stack_c::now);
  m_Do_mtx::mDoMtx_XrotM(&mDoMtx_stack_c::now,*(short *)(this + 0x9158));
  m_Do_mtx::mDoMtx_YrotM(&mDoMtx_stack_c::now,*(short *)(this + 0x915a));
  m_Do_mtx::mDoMtx_ZrotM(&mDoMtx_stack_c::now,*(short *)(this + 0x915c));
  mDoMtx_stack_c::scaleM
            (*(float *)(this + 0x9140),*(float *)(this + 0x9144),*(float *)(this + 0x9148));
  mDoMtx_stack_c::transM(d_menu_cloth::_4077,d_menu_cloth::_4077,d_menu_cloth::_4797);
  gx::GXLoadPosMtxImm(&mDoMtx_stack_c::now,0);
  gx::GXLoadNrmMtxImm(&mDoMtx_stack_c::now,0);
  gx::GXSetCullMode(1);
  gx::GXSetCurrentMtx(0);
  gx::GXSetArray(GX_VA_POS,this + (uint)(byte)this[0x913c] * 0x14ac + 0x48,0xc);
  gx::GXSetArray(GX_VA_NRM,this + (uint)(byte)this[0x913c] * 0x14ac + 0x29a0,0xc);
  TevSetting(this);
  plot(this,d_menu_cloth::_4077,d_menu_cloth::_4077,d_menu_cloth::_4205,d_menu_cloth::_4205);
  gx::GXSetCullMode(2);
  ShadowTevSetting(this);
  gx::GXSetArray(GX_VA_POS,this + 0x7c50,0xc);
  plot_shadow(this,d_menu_cloth::_4077,d_menu_cloth::_4077,d_menu_cloth::_4006,d_menu_cloth::_4006);
  TevSetting(this);
  gx::GXSetArray(GX_VA_POS,this + (uint)(byte)this[0x913c] * 0x14ac + 0x48,0xc);
  gx::GXSetArray(GX_VA_NRM,this + 0x52f8,0xc);
  plot(this,d_menu_cloth::_4077,d_menu_cloth::_4077,d_menu_cloth::_4205,d_menu_cloth::_4205);
  J3DSys::reinitGX(&J3DGraphBase::j3dSys);
  return;
}


/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* WARNING: Removing unreachable block (ram,0x8019b998) */
/* WARNING: Removing unreachable block (ram,0x8019b988) */
/* WARNING: Removing unreachable block (ram,0x8019b978) */
/* WARNING: Removing unreachable block (ram,0x8019b970) */
/* WARNING: Removing unreachable block (ram,0x8019b980) */
/* WARNING: Removing unreachable block (ram,0x8019b990) */
/* WARNING: Removing unreachable block (ram,0x8019b9a0) */
/* __thiscall dMCloth_c::cloth_move_sin(void) */

void __thiscall dMCloth_c::cloth_move_sin(dMCloth_c *this)

{
  float fVar1;
  float fVar2;
  dMCloth_c dVar3;
  float fVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  cXyz *pcVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  undefined4 uVar12;
  undefined8 in_f25;
  double dVar13;
  undefined8 in_f26;
  double dVar14;
  undefined8 in_f27;
  double dVar15;
  undefined8 in_f28;
  double dVar16;
  undefined8 in_f29;
  double dVar17;
  undefined8 in_f30;
  double dVar18;
  undefined8 in_f31;
  double dVar19;
  cXyz local_c8;
  undefined4 local_b8;
  uint uStack180;
  undefined4 local_b0;
  uint uStack172;
  undefined4 local_a8;
  uint uStack164;
  undefined auStack104 [16];
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar12 = 0;
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
  __psq_st0(auStack88,(int)((ulonglong)in_f26 >> 0x20),0);
  __psq_st1(auStack88,(int)in_f26,0);
  __psq_st0(auStack104,(int)((ulonglong)in_f25 >> 0x20),0);
  __psq_st1(auStack104,(int)in_f25,0);
  *(short *)(this + 8) =
       *(short *)(this + 8) + (&d_menu_cloth::l_HIO.field_0x3e)[(uint)(byte)this[0x913d] * 0x2c];
  dVar3 = this[0x913c];
  uVar10 = 0;
  iVar7 = 0;
  dVar16 = (double)d_menu_cloth::_5093;
  dVar17 = (double)d_menu_cloth::_4201;
  dVar18 = (double)d_menu_cloth::_4261;
  dVar19 = (double)d_menu_cloth::_4206;
  dVar14 = (double)d_menu_cloth::_4202;
  dVar15 = d_menu_cloth::_4215;
  do {
    uVar9 = 0;
    uVar11 = uVar10 ^ 0x80000000;
    dVar13 = (double)(float)(dVar17 + (double)(float)(dVar14 * (double)(float)((double)CONCAT44(
                                                  0x43300000,uVar11) - dVar15)));
    do {
      uStack180 = uVar9 ^ 0x80000000;
      local_b8 = 0x43300000;
      fVar1 = (float)((double)CONCAT44(0x43300000,uStack180) - dVar15);
      local_b0 = 0x43300000;
      fVar2 = (float)((double)CONCAT44(0x43300000,uVar11) - dVar15);
      if (5 < (int)uVar9) {
        fVar1 = (d_menu_cloth::_5091 - fVar1) - d_menu_cloth::_4006;
      }
      if (5 < (int)uVar10) {
        fVar2 = (d_menu_cloth::_5091 - fVar2) - d_menu_cloth::_4006;
      }
      fVar4 = d_menu_cloth::_4006;
      if ((double)(fVar1 + fVar2) <= dVar16) {
        fVar4 = (float)((double)d_menu_cloth::_5092 * (double)(fVar1 + fVar2));
      }
      uStack164 = uVar9 ^ 0x80000000;
      local_a8 = 0x43300000;
      uVar5 = (uint)(byte)this[0x913d];
      iVar6 = (int)*(short *)(this + 8);
      local_c8.x = (float)(dVar17 + (double)(float)(dVar18 * (double)(float)((double)CONCAT44(
                                                  0x43300000,uStack164) - dVar15))) +
                   (&d_menu_cloth::l_HIO.field_0x44)[uVar5 * 0x16] * fVar4 *
                   JKernel::JMath::jmaSinTable
                   [(int)(iVar6 + uVar9 * (int)(short)(&d_menu_cloth::l_HIO.field_0x40)
                                                      [uVar5 * 0x2c] +
                                  uVar10 * (int)(short)(&d_menu_cloth::l_HIO.field_0x42)
                                                       [uVar5 * 0x2c] & 0xffff) >>
                    (JKernel::JMath::jmaSinShift & 0x3f)];
      local_c8.y = (float)(dVar13 + (double)((&d_menu_cloth::l_HIO.field_0x48)[uVar5 * 0x16] * fVar4
                                            * JKernel::JMath::jmaCosTable
                                              [(int)(iVar6 + uVar9 * (int)(short)(&d_menu_cloth::
                                                                                   l_HIO.field_0x40)
                                                                                 [uVar5 * 0x2c] +
                                                             uVar10 * (int)(short)(&d_menu_cloth::
                                                                                    l_HIO.field_0x42
                                                                                  )[uVar5 * 0x2c] &
                                                    0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f)]
                                            ));
      local_c8.z = (float)(dVar19 + (double)((&d_menu_cloth::l_HIO.field_0x4c)[uVar5 * 0x16] * fVar4
                                            * JKernel::JMath::jmaSinTable
                                              [(int)(iVar6 + uVar9 * (int)(short)(&d_menu_cloth::
                                                                                   l_HIO.field_0x40)
                                                                                 [uVar5 * 0x2c] &
                                                    0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f)]
                                            ));
      uStack172 = uVar11;
      SComponent::cLib_addCalcPos2
                ((cXyz *)(this + (uVar9 + iVar7) * 0xc + (uint)(byte)dVar3 * 0x14ac + 0x48),
                 &local_c8,d_menu_cloth::_4955,(&d_menu_cloth::l_HIO.field_0x5c)[uVar5 * 0x16]);
      uVar9 = uVar9 + 1;
    } while ((int)uVar9 < 0xb);
    uVar10 = uVar10 + 1;
    iVar7 = iVar7 + 0xb;
  } while ((int)uVar10 < 0xb);
  pcVar8 = (cXyz *)(this + (uint)(byte)this[0x913c] * 0x14ac + 0x29a0);
  iVar7 = 0;
  do {
    iVar6 = 0;
    do {
      setNrmVtx(this,pcVar8,iVar6,iVar7);
      iVar6 = iVar6 + 1;
      pcVar8 = pcVar8 + 1;
    } while (iVar6 < 0xb);
    iVar7 = iVar7 + 1;
  } while (iVar7 < 0xb);
  setBackNrm(this);
  os::DCStoreRangeNoSync(this + (uint)(byte)this[0x913c] * 0x14ac + 0x48,0x5ac);
  os::DCStoreRangeNoSync(this + (uint)(byte)this[0x913c] * 0x14ac + 0x29a0,0x5ac);
  os::DCStoreRangeNoSync(this + 0x52f8,0x5ac);
  __psq_l0(auStack8,uVar12);
  __psq_l1(auStack8,uVar12);
  __psq_l0(auStack24,uVar12);
  __psq_l1(auStack24,uVar12);
  __psq_l0(auStack40,uVar12);
  __psq_l1(auStack40,uVar12);
  __psq_l0(auStack56,uVar12);
  __psq_l1(auStack56,uVar12);
  __psq_l0(auStack72,uVar12);
  __psq_l1(auStack72,uVar12);
  __psq_l0(auStack88,uVar12);
  __psq_l1(auStack88,uVar12);
  __psq_l0(auStack104,uVar12);
  __psq_l1(auStack104,uVar12);
  return;
}


/* WARNING: Inlined function: FUN_80328f28 */
/* WARNING: Inlined function: FUN_80328f74 */
/* WARNING: Removing unreachable block (ram,0x8019bccc) */
/* WARNING: Removing unreachable block (ram,0x8019bcbc) */
/* WARNING: Removing unreachable block (ram,0x8019bcac) */
/* WARNING: Removing unreachable block (ram,0x8019bca4) */
/* WARNING: Removing unreachable block (ram,0x8019bcb4) */
/* WARNING: Removing unreachable block (ram,0x8019bcc4) */
/* WARNING: Removing unreachable block (ram,0x8019bcd4) */
/* __thiscall dMCloth_c::cloth_move_simple(void) */

void __thiscall dMCloth_c::cloth_move_simple(dMCloth_c *this)

{
  float fVar1;
  float fVar2;
  dMCloth_c dVar3;
  float fVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  cXyz *pcVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  undefined4 uVar12;
  undefined8 in_f25;
  double dVar13;
  undefined8 in_f26;
  double dVar14;
  undefined8 in_f27;
  double dVar15;
  undefined8 in_f28;
  double dVar16;
  undefined8 in_f29;
  double dVar17;
  undefined8 in_f30;
  double dVar18;
  undefined8 in_f31;
  double dVar19;
  cXyz local_c8;
  undefined4 local_b8;
  uint uStack180;
  undefined4 local_b0;
  uint uStack172;
  undefined4 local_a8;
  uint uStack164;
  undefined auStack104 [16];
  undefined auStack88 [16];
  undefined auStack72 [16];
  undefined auStack56 [16];
  undefined auStack40 [16];
  undefined auStack24 [16];
  undefined auStack8 [8];
  
  uVar12 = 0;
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
  __psq_st0(auStack88,(int)((ulonglong)in_f26 >> 0x20),0);
  __psq_st1(auStack88,(int)in_f26,0);
  __psq_st0(auStack104,(int)((ulonglong)in_f25 >> 0x20),0);
  __psq_st1(auStack104,(int)in_f25,0);
  dVar3 = this[0x913c];
  uVar10 = 0;
  iVar7 = 0;
  dVar16 = (double)d_menu_cloth::_5093;
  dVar17 = (double)d_menu_cloth::_4201;
  dVar18 = (double)d_menu_cloth::_4261;
  dVar19 = (double)d_menu_cloth::_4206;
  dVar14 = (double)d_menu_cloth::_4202;
  dVar15 = d_menu_cloth::_4215;
  do {
    uVar9 = 0;
    uVar11 = uVar10 ^ 0x80000000;
    dVar13 = (double)(float)(dVar17 + (double)(float)(dVar14 * (double)(float)((double)CONCAT44(
                                                  0x43300000,uVar11) - dVar15)));
    do {
      uStack180 = uVar9 ^ 0x80000000;
      local_b8 = 0x43300000;
      fVar1 = (float)((double)CONCAT44(0x43300000,uStack180) - dVar15);
      local_b0 = 0x43300000;
      fVar2 = (float)((double)CONCAT44(0x43300000,uVar11) - dVar15);
      if (5 < (int)uVar9) {
        fVar1 = (d_menu_cloth::_5091 - fVar1) - d_menu_cloth::_4006;
      }
      if (5 < (int)uVar10) {
        fVar2 = (d_menu_cloth::_5091 - fVar2) - d_menu_cloth::_4006;
      }
      fVar4 = d_menu_cloth::_4006;
      if ((double)(fVar1 + fVar2) <= dVar16) {
        fVar4 = (float)((double)d_menu_cloth::_5092 * (double)(fVar1 + fVar2));
      }
      uStack164 = uVar9 ^ 0x80000000;
      local_a8 = 0x43300000;
      uVar5 = (uint)(byte)this[0x913d];
      iVar6 = (int)*(short *)(this + 8);
      local_c8.x = (float)(dVar17 + (double)(float)(dVar18 * (double)(float)((double)CONCAT44(
                                                  0x43300000,uStack164) - dVar15))) +
                   (&d_menu_cloth::l_HIO.field_0x44)[uVar5 * 0x16] * fVar4 *
                   JKernel::JMath::jmaSinTable
                   [(int)(iVar6 + uVar9 * (int)(short)(&d_menu_cloth::l_HIO.field_0x40)
                                                      [uVar5 * 0x2c] +
                                  uVar10 * (int)(short)(&d_menu_cloth::l_HIO.field_0x42)
                                                       [uVar5 * 0x2c] & 0xffff) >>
                    (JKernel::JMath::jmaSinShift & 0x3f)];
      local_c8.y = (float)(dVar13 + (double)((&d_menu_cloth::l_HIO.field_0x48)[uVar5 * 0x16] * fVar4
                                            * JKernel::JMath::jmaCosTable
                                              [(int)(iVar6 + uVar9 * (int)(short)(&d_menu_cloth::
                                                                                   l_HIO.field_0x40)
                                                                                 [uVar5 * 0x2c] +
                                                             uVar10 * (int)(short)(&d_menu_cloth::
                                                                                    l_HIO.field_0x42
                                                                                  )[uVar5 * 0x2c] &
                                                    0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f)]
                                            ));
      local_c8.z = (float)(dVar19 + (double)((&d_menu_cloth::l_HIO.field_0x4c)[uVar5 * 0x16] * fVar4
                                            * JKernel::JMath::jmaSinTable
                                              [(int)(iVar6 + uVar10 * (int)(short)(&d_menu_cloth::
                                                                                    l_HIO.field_0x42
                                                                                  )[uVar5 * 0x2c] &
                                                    0xffff) >> (JKernel::JMath::jmaSinShift & 0x3f)]
                                            ));
      uStack172 = uVar11;
      SComponent::cLib_addCalcPos2
                ((cXyz *)(this + (uVar9 + iVar7) * 0xc + (uint)(byte)dVar3 * 0x14ac + 0x48),
                 &local_c8,d_menu_cloth::_4955,(&d_menu_cloth::l_HIO.field_0x5c)[uVar5 * 0x16]);
      uVar9 = uVar9 + 1;
    } while ((int)uVar9 < 0xb);
    uVar10 = uVar10 + 1;
    iVar7 = iVar7 + 0xb;
  } while ((int)uVar10 < 0xb);
  pcVar8 = (cXyz *)(this + (uint)(byte)this[0x913c] * 0x14ac + 0x29a0);
  iVar7 = 0;
  do {
    iVar6 = 0;
    do {
      setNrmVtx(this,pcVar8,iVar6,iVar7);
      iVar6 = iVar6 + 1;
      pcVar8 = pcVar8 + 1;
    } while (iVar6 < 0xb);
    iVar7 = iVar7 + 1;
  } while (iVar7 < 0xb);
  setBackNrm(this);
  os::DCStoreRangeNoSync(this + (uint)(byte)this[0x913c] * 0x14ac + 0x48,0x5ac);
  os::DCStoreRangeNoSync(this + (uint)(byte)this[0x913c] * 0x14ac + 0x29a0,0x5ac);
  os::DCStoreRangeNoSync(this + 0x52f8,0x5ac);
  __psq_l0(auStack8,uVar12);
  __psq_l1(auStack8,uVar12);
  __psq_l0(auStack24,uVar12);
  __psq_l1(auStack24,uVar12);
  __psq_l0(auStack40,uVar12);
  __psq_l1(auStack40,uVar12);
  __psq_l0(auStack56,uVar12);
  __psq_l1(auStack56,uVar12);
  __psq_l0(auStack72,uVar12);
  __psq_l1(auStack72,uVar12);
  __psq_l0(auStack88,uVar12);
  __psq_l1(auStack88,uVar12);
  __psq_l0(auStack104,uVar12);
  __psq_l1(auStack104,uVar12);
  return;
}


/* WARNING: Removing unreachable block (ram,0x8019bd24) */
/* __thiscall dMCloth_c::cloth_move(void) */

void __thiscall dMCloth_c::cloth_move(dMCloth_c *this)

{
  uint uVar1;
  
  uVar1 = (uint)(byte)this[0x913d];
  if (uVar1 == 1) {
    if (*(short *)(this + 10) < d_menu_cloth::l_HIO.field_0x94) {
      *(short *)(this + 10) = *(short *)(this + 10) + 1;
    }
    cloth_move_sin(this);
  }
  else {
    if ((uVar1 == 0) || (uVar1 < 3)) {
      if (*(short *)(this + 10) < (short)(&d_menu_cloth::l_HIO.field_0x3c)[uVar1 * 0x2c]) {
        cloth_move_sin(this);
        *(short *)(this + 10) = *(short *)(this + 10) + 1;
      }
      else {
        cloth_move_simple(this);
      }
    }
  }
  return;
}


namespace d_menu_cloth {

/* __stdcall dMenu_ClothCreate(void *) */

undefined4 dMenu_ClothCreate(void)

{
  return 4;
}


/* __stdcall dMenu_ClothDelete(void *) */

undefined4 dMenu_ClothDelete(void)

{
  return 1;
}


/* __stdcall dMenu_ClothExecute(void *) */

undefined4 dMenu_ClothExecute(void)

{
  return 0;
}


/* __stdcall dMenu_ClothDraw(void *) */

undefined4 dMenu_ClothDraw(void)

{
  return 1;
}


/* __stdcall dMenu_ClothIsDelete(void *) */

undefined4 dMenu_ClothIsDelete(void)

{
  return 1;
}

}

/* __thiscall daCLOTH_HIO_c::~daCLOTH_HIO_c(void) */

void __thiscall daCLOTH_HIO_c::_daCLOTH_HIO_c(daCLOTH_HIO_c *this)

{
  short in_r4;
  
  if (this != (daCLOTH_HIO_c *)0x0) {
    this->field_0x0 = &__vt;
    Runtime.PPCEABI.H::__destroy_arr
              (&this->field_0x8,daCLOTH_ChildHIO_c::_daCLOTH_ChildHIO_c,0x58,3);
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


namespace d_menu_cloth {

void __sinit_d_menu_cloth_cpp(void)

{
  ::daCLOTH_HIO_c::daCLOTH_HIO_c(&l_HIO);
  Runtime.PPCEABI.H::__register_global_object();
  return;
}

