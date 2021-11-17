#include <SComponent/c_m3d_g_pla.h>
#include <SComponent/c_m3d.h>
#include <mtx/vec.h>
#include <Demangler/cM3dGPla.h>


/* __thiscall cM3dGPla::CalcAngleXz(short *,
                                    short *) const */

void __thiscall cM3dGPla::CalcAngleXz(cM3dGPla *this,short *param_1,short *param_2)

{
  SComponent::cM3d_CalcVecAngle((cXyz *)this,param_1,param_2);
  return;
}


/* __thiscall cM3dGPla::SetupNP0(Vec const &,
                                 Vec const &) */

void __thiscall cM3dGPla::SetupNP0(cM3dGPla *this,Vec *param_1,Vec *param_2)

{
  double dVar1;
  
  (this->mNorm).x = *(float *)param_1;
  (this->mNorm).y = *(float *)(param_1 + 4);
  (this->mNorm).z = *(float *)(param_1 + 8);
  mtx::PSVECNormalize(this,this);
  dVar1 = (double)mtx::PSVECDotProduct(this,param_2);
  this->mDist = (float)-dVar1;
  return;
}

