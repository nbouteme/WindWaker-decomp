#include <d_a_boko_static.h>
#include <mtx/mtxvec.h>
#include <SComponent/c_xyz.h>
#include <daBoko_c.h>


/* __thiscall daBoko_c::getTopPos(cXyz *) */

void __thiscall daBoko_c::getTopPos(daBoko_c *this,cXyz *param_1)

{
  cXyz local_18;
  
  if (this->mpModel == (J3DModel *)0x0) {
    ::cXyz::operator__(&local_18,&(this->parent).mCurrent.mPos,
                       (cXyz *)(&m_top_offset + (this->parent).parent.parent.mParameters * 0xc));
    param_1->x = local_18.x;
    param_1->y = local_18.y;
    param_1->z = local_18.z;
  }
  else {
    mtx::PSMTXMultVec(&this->mpModel->mBaseMtx,
                      (cXyz *)(&m_top_offset + (this->parent).parent.parent.mParameters * 0xc),
                      param_1);
  }
  return;
}


/* __thiscall daBoko_c::getBlurRootPos(cXyz *) */

void __thiscall daBoko_c::getBlurRootPos(daBoko_c *this,cXyz *param_1)

{
  cXyz local_18;
  
  if (this->mpModel == (J3DModel *)0x0) {
    ::cXyz::operator__(&local_18,&(this->parent).mCurrent.mPos,
                       (cXyz *)(&m_blur_root_offset + (this->parent).parent.parent.mParameters * 0xc
                               ));
    param_1->x = local_18.x;
    param_1->y = local_18.y;
    param_1->z = local_18.z;
  }
  else {
    mtx::PSMTXMultVec(&this->mpModel->mBaseMtx,
                      (cXyz *)(&m_blur_root_offset + (this->parent).parent.parent.mParameters * 0xc)
                      ,param_1);
  }
  return;
}

