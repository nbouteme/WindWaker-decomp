#include <SComponent/c_m2d_g_box.h>
#include <cM2dGBox.h>


/* __thiscall cM2dGBox::Set(cXy &,
                            cXy &) */

void __thiscall cM2dGBox::Set(cM2dGBox *this,cXy *param_1,cXy *param_2)

{
  this->x0 = param_1->x;
  this->y0 = param_1->y;
  this->x1 = param_2->x;
  this->y1 = param_2->y;
  return;
}


/* __thiscall cM2dGBox::GetLen(cXy const &) const */

double __thiscall cM2dGBox::GetLen(cM2dGBox *this,cXy *param_1)

{
  double dVar1;
  double ret;
  float x0;
  float xP;
  float y0;
  float yP;
  
  x0 = this->x0;
  xP = param_1->x;
  if ((((xP <= x0) || (this->x1 <= xP)) || (param_1->y <= this->y0)) || (this->y1 <= param_1->y)) {
    if ((xP <= x0) || (this->x1 <= xP)) {
      y0 = this->y0;
      yP = param_1->y;
      if ((yP <= y0) || (this->y1 <= yP)) {
        if (x0 <= xP) {
          if (y0 <= yP) {
            xP = xP - this->x1;
            yP = yP - this->y1;
            ret = (double)(xP * xP + yP * yP);
            if ((double)SComponent::_553 < ret) {
              dVar1 = 1.0 / SQRT(ret);
              dVar1 = SComponent::_554 * dVar1 * (SComponent::_555 - ret * dVar1 * dVar1);
              dVar1 = SComponent::_554 * dVar1 * (SComponent::_555 - ret * dVar1 * dVar1);
              ret = (double)(float)(ret * SComponent::_554 * dVar1 *
                                          (SComponent::_555 - ret * dVar1 * dVar1));
            }
          }
          else {
            xP = xP - this->x1;
            ret = (double)(xP * xP + (yP - y0) * (yP - y0));
            if ((double)SComponent::_553 < ret) {
              dVar1 = 1.0 / SQRT(ret);
              dVar1 = SComponent::_554 * dVar1 * (SComponent::_555 - ret * dVar1 * dVar1);
              dVar1 = SComponent::_554 * dVar1 * (SComponent::_555 - ret * dVar1 * dVar1);
              ret = (double)(float)(ret * SComponent::_554 * dVar1 *
                                          (SComponent::_555 - ret * dVar1 * dVar1));
            }
          }
        }
        else {
          if (y0 <= yP) {
            yP = yP - this->y1;
            ret = (double)((xP - x0) * (xP - x0) + yP * yP);
            if ((double)SComponent::_553 < ret) {
              dVar1 = 1.0 / SQRT(ret);
              dVar1 = SComponent::_554 * dVar1 * (SComponent::_555 - ret * dVar1 * dVar1);
              dVar1 = SComponent::_554 * dVar1 * (SComponent::_555 - ret * dVar1 * dVar1);
              ret = (double)(float)(ret * SComponent::_554 * dVar1 *
                                          (SComponent::_555 - ret * dVar1 * dVar1));
            }
          }
          else {
            ret = (double)((xP - x0) * (xP - x0) + (yP - y0) * (yP - y0));
            if ((double)SComponent::_553 < ret) {
              dVar1 = 1.0 / SQRT(ret);
              dVar1 = SComponent::_554 * dVar1 * (SComponent::_555 - ret * dVar1 * dVar1);
              dVar1 = SComponent::_554 * dVar1 * (SComponent::_555 - ret * dVar1 * dVar1);
              ret = (double)(float)(ret * SComponent::_554 * dVar1 *
                                          (SComponent::_555 - ret * dVar1 * dVar1));
            }
          }
        }
      }
      else {
        dVar1 = (double)ABS(this->x1 - param_1->x);
        ret = (double)ABS(x0 - xP);
        if (dVar1 < (double)ABS(x0 - xP)) {
          ret = dVar1;
        }
      }
    }
    else {
      ret = (double)ABS(this->y0 - param_1->y);
      dVar1 = (double)ABS(this->y1 - param_1->y);
      if (dVar1 < ret) {
        ret = dVar1;
      }
    }
  }
  else {
    ret = (double)SComponent::_553;
  }
  return ret;
}

