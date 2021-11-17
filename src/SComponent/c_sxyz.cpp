#include <SComponent/c_sxyz.h>
#include <SComponent/c_sxyz.h>
#include <c_damagereaction.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <csXyz.h>

struct csXyz csXyz;

/* __thiscall csXyz::csXyz(short,
                           short,
                           short) */

void __thiscall csXyz::csXyz(csXyz *this,short param_1,short param_2,short param_3)

{
  this->x = param_1;
  this->y = param_2;
  this->z = param_3;
  return;
}


/* __thiscall csXyz::operator +(csXyz &) */

void __thiscall csXyz::operator__(csXyz *this,csXyz *param_1)

{
  short *in_r5;
  
  csXyz(this,param_1->x + *in_r5,param_1->y + in_r5[1],param_1->z + in_r5[2]);
  return;
}


/* __thiscall csXyz::operator +=(csXyz &) */

void __thiscall csXyz::operator___(csXyz *this,csXyz *param_1)

{
  this->x = this->x + param_1->x;
  this->y = this->y + param_1->y;
  this->z = this->z + param_1->z;
  return;
}


/* __thiscall csXyz::operator *(float) */

void __thiscall csXyz::operator_(csXyz *this,float param_1)

{
  short *in_r4;
  
  csXyz(this,(short)(int)((float)((double)CONCAT44(0x43300000,(int)*in_r4 ^ 0x80000000) -
                                 SComponent::_152) * param_1),
        (short)(int)((float)((double)CONCAT44(0x43300000,(int)in_r4[1] ^ 0x80000000) -
                            SComponent::_152) * param_1),
        (short)(int)((float)((double)CONCAT44(0x43300000,(int)in_r4[2] ^ 0x80000000) -
                            SComponent::_152) * param_1));
  return;
}


namespace SComponent {

void __sinit_c_sxyz_cpp(void)

{
  undefined4 local_8;
  short local_4;
  
  ::csXyz::csXyz((csXyz *)&local_8,0,0,0);
  ::csXyz::Zero._0_4_ = local_8;
  ::csXyz::Zero.z = local_4;
  Runtime.PPCEABI.H::__register_global_object(&::csXyz::Zero,::csXyz::_csXyz,&_251);
  return;
}

