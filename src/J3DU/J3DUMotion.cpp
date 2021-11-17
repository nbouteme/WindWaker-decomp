#include <J3DU/J3DUMotion.h>
#include <JKernel/JKRHeap.h>
#include <mtx/mtx.h>
#include <J3DMtxCalcSoftimage.h>
#include <J3DMtxCalcBasic.h>


/* __thiscall J3DMtxCalcSoftimage::~J3DMtxCalcSoftimage(void) */

void __thiscall J3DMtxCalcSoftimage::_J3DMtxCalcSoftimage(J3DMtxCalcSoftimage *this)

{
  short in_r4;
  
  if (this != (J3DMtxCalcSoftimage *)0x0) {
    *(undefined1 **)(this + 0x4c) = &__vt;
    **(undefined4 **)this = &DAT_8039ebd8;
    *(int *)(*(int *)this + 0x24) = (int)(this + 0x50) - *(int *)this;
    if (this != (J3DMtxCalcSoftimage *)0x0) {
      *(J3DMtxCalcBasic__vtbl **)(this + 0x4c) = &J3DMtxCalcBasic::__vt;
      **(undefined ***)this = (undefined *)&PTR_8039ec0c;
      *(int *)(*(int *)this + 0x24) = (int)(this + 0x50) - *(int *)this;
    }
    if (0 < in_r4) {
      JKernel::operator_delete((JKRHeap *)this);
    }
  }
  return;
}


/* __thiscall J3DMtxCalcSoftimage::init(Vec const &,
                                        float const &[][][]) */

int __thiscall J3DMtxCalcSoftimage::init(J3DMtxCalcSoftimage *this,EVP_PKEY_CTX *ctx)

{
  MTX34 *in_r5;
  
  J3DSys::mCurrentS.x = *(float *)ctx;
  J3DSys::mCurrentS.y = *(float *)(ctx + 4);
  J3DSys::mCurrentS.z = *(float *)(ctx + 8);
  mtx::PSMTXCopy(in_r5,&J3DSys::mCurrentMtx);
  return (int)in_r5;
}


/* __thiscall J3DMtxCalcBasic::init(Vec const &,
                                    float const &[][][]) */

int __thiscall J3DMtxCalcBasic::init(J3DMtxCalcBasic *this,TVec3_float_ *param_1,MTX34 *param_2)

{
  J3DSys::mCurrentS.x = param_1->x;
  J3DSys::mCurrentS.y = param_1->y;
  J3DSys::mCurrentS.z = param_1->z;
  J3DSys::mCurrentMtx.m[0][0] = param_2->m[0] * J3DSys::mCurrentS.x;
  J3DSys::mCurrentMtx.m[0][1] = param_2->m[1] * J3DSys::mCurrentS.y;
  J3DSys::mCurrentMtx.m[0][2] = param_2->m[2] * J3DSys::mCurrentS.z;
  J3DSys::mCurrentMtx.m[0][3] = param_2->m[3];
  J3DSys::mCurrentMtx.m[1][0] = param_2->m[1][0] * J3DSys::mCurrentS.x;
  J3DSys::mCurrentMtx.m[1][1] = param_2->m[1][1] * J3DSys::mCurrentS.y;
  J3DSys::mCurrentMtx.m[1][2] = param_2->m[1][2] * J3DSys::mCurrentS.z;
  J3DSys::mCurrentMtx.m[1][3] = param_2->m[1][3];
  J3DSys::mCurrentMtx.m[2][0] = param_2->m[2][0] * J3DSys::mCurrentS.x;
  J3DSys::mCurrentMtx.m[2][1] = param_2->m[2][1] * J3DSys::mCurrentS.y;
  J3DSys::mCurrentMtx.m[2][2] = param_2->m[2][2] * J3DSys::mCurrentS.z;
  J3DSys::mCurrentMtx.m[2][3] = param_2->m[2][3];
  J3DSys::mParentS.x = J3DU::_1437;
  J3DSys::mParentS.y = DAT_8036655c;
  J3DSys::mParentS.z = DAT_80366560;
  return (int)&J3DSys::mCurrentMtx;
}

