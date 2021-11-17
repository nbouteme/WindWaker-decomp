#include <SComponent/c_m3d_g_aab.h>
#include <SComponent/c_m3d_g_aab.h>
#include <cM3dGAab.h>


/* __thiscall cM3dGAab::SetMinMax(cXyz const &) */

void __thiscall cM3dGAab::SetMinMax(cM3dGAab *this,cXyz *param_1)

{
  SetMin(this,param_1);
  SetMax(this,param_1);
  return;
}


/* __thiscall cM3dGAab::SetMin(cXyz const &) */

void __thiscall cM3dGAab::SetMin(cM3dGAab *this,cXyz *param_1)

{
  if (param_1->x < (this->mMin).x) {
    (this->mMin).x = param_1->x;
  }
  if (param_1->y < (this->mMin).y) {
    (this->mMin).y = param_1->y;
  }
  if ((this->mMin).z <= param_1->z) {
    return;
  }
  (this->mMin).z = param_1->z;
  return;
}


/* __thiscall cM3dGAab::SetMax(cXyz const &) */

void __thiscall cM3dGAab::SetMax(cM3dGAab *this,cXyz *param_1)

{
  if ((this->mMax).x < param_1->x) {
    (this->mMax).x = param_1->x;
  }
  if ((this->mMax).y < param_1->y) {
    (this->mMax).y = param_1->y;
  }
  if (param_1->z <= (this->mMax).z) {
    return;
  }
  (this->mMax).z = param_1->z;
  return;
}

