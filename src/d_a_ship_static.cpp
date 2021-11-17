#include <d_a_ship_static.h>
#include <d_particle.h>
#include <daShip_c.h>


/* __thiscall daShip_c::initStartPos(cXyz const *,
                                     short) */

void __thiscall daShip_c::initStartPos(daShip_c *this,cXyz *param_1,short param_2)

{
  (this->parent).mCurrent.mPos.x = param_1->x;
  (this->parent).mCurrent.mPos.y = param_1->y;
  (this->parent).mCurrent.mPos.z = param_1->z;
  (this->parent).mNext.mPos.x = param_1->x;
  (this->parent).mNext.mPos.y = param_1->y;
  (this->parent).mNext.mPos.z = param_1->z;
  (this->parent).mCollisionRot.y = param_2;
  (this->parent).mCurrent.mRot.y = (this->parent).mCollisionRot.y;
  this->field_0x358 = this->field_0x358 & 0xffffffef;
  (this->parent).mAccelerationY = d_a_ship_static::_3997;
  dPa_waveEcallBack::remove((dPa_waveEcallBack *)&this->field_0x18a0);
  dPa_waveEcallBack::remove((dPa_waveEcallBack *)&this->field_0x183c);
  dPa_splashEcallBack::remove((dPa_splashEcallBack *)&this->field_0x1904);
  dPa_trackEcallBack::remove((dPa_trackEcallBack *)&this->field_0x1920);
  dPa_rippleEcallBack::end((dPa_rippleEcallBack *)&this->field_0x1970);
  (**(code **)(*(int *)&this->field_0x1984 + 0x20))(&this->field_0x1984);
  (**(code **)(*(int *)&this->field_0x1998 + 0x20))(&this->field_0x1998);
  (**(code **)(*(int *)&this->field_0x19ac + 0x20))(&this->field_0x19ac);
  dPa_rippleEcallBack::end((dPa_rippleEcallBack *)&this->field_0x19c0);
  return;
}

