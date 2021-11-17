#include <SComponent/c_m3d_g_tri.h>
#include <SComponent/c_m3d.h>
#include <Demangler/cM3dGTri.h>


/* __thiscall cM3dGTri::cM3dGTri(Vec const *,
                                 Vec const *,
                                 Vec const *) */

void __thiscall cM3dGTri::cM3dGTri(cM3dGTri *this,Vec *param_1,Vec *param_2,Vec *param_3)

{
  (this->parent).vtbl = (undefined *)&cM3dGPla::__vt;
  (this->parent).vtbl = (undefined *)&__vt;
  (this->mP0).x = *(float *)param_1;
  (this->mP0).y = *(float *)(param_1 + 4);
  (this->mP0).z = *(float *)(param_1 + 8);
  (this->mP1).x = *(float *)param_2;
  (this->mP1).y = *(float *)(param_2 + 4);
  (this->mP1).z = *(float *)(param_2 + 8);
  (this->mP2).x = *(float *)param_3;
  (this->mP2).y = *(float *)(param_3 + 4);
  (this->mP2).z = *(float *)(param_3 + 8);
  SComponent::cM3d_CalcPla
            (&this->mP0,&this->mP1,&this->mP2,(TVec3_float_ *)this,&(this->parent).mDist);
  return;
}


/* __thiscall cM3dGTri::cross(cM3dGCyl const *,
                              Vec *) const */

void __thiscall cM3dGTri::cross(cM3dGTri *this,cM3dGCyl *param_1,Vec *param_2)

{
  SComponent::cM3d_Cross_CylTri(param_1,this);
  return;
}

