#include <d_a_item_static.h>
#include <d_a_item_static.h>
#include <daItem_c.h>


/* __thiscall daItem_c::checkControl(void) */

undefined4 __thiscall daItem_c::checkControl(daItem_c *this)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (this->mCurAction == 3) {
    uVar2 = 0;
  }
  else {
    iVar3 = checkActionNow(this);
    if (iVar3 == 0) {
      bVar1 = this->mCurAction;
      if (bVar1 == 4) {
        uVar2 = 0;
      }
      else {
        if ((bVar1 == 5) || (bVar1 == 6)) {
          uVar2 = 0;
        }
        else {
          uVar2 = 1;
        }
      }
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}


/* __thiscall daItem_c::startControl(void) */

bool __thiscall daItem_c::startControl(daItem_c *this)

{
  int iVar1;
  
  iVar1 = checkControl(this);
  if (iVar1 != 0) {
    this->mCurAction = 3;
  }
  return iVar1 != 0;
}


/* __thiscall daItem_c::endControl(void) */

undefined4 __thiscall daItem_c::endControl(daItem_c *this)

{
  this->mCurAction = 0;
  return 1;
}


/* __thiscall daItem_c::checkLock(void) */

uint __thiscall daItem_c::checkLock(daItem_c *this)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = checkActionNow(this);
  if (iVar1 == 0) {
    if (this->mCurAction == 4) {
      uVar2 = 0;
    }
    else {
      uVar2 = countLeadingZeros((uint)this->mCurAction);
      uVar2 = uVar2 >> 5;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


/* __thiscall daItem_c::setLock(void) */

bool __thiscall daItem_c::setLock(daItem_c *this)

{
  int iVar1;
  
  iVar1 = checkLock(this);
  if (iVar1 != 0) {
    this->mCurAction = 2;
  }
  return iVar1 != 0;
}


/* __thiscall daItem_c::releaseLock(void) */

undefined4 __thiscall daItem_c::releaseLock(daItem_c *this)

{
  this->mCurAction = 0;
  return 1;
}


/* __thiscall daItem_c::checkActionNow(void) */

undefined4 __thiscall daItem_c::checkActionNow(daItem_c *this)

{
  if ((ABS((this->parent).parent.mVelocityFwd) < d_a_item_static::_4052) &&
     (ABS((this->parent).parent.mNext.mPos.y - (this->parent).parent.mCurrent.mPos.y) <
      d_a_item_static::_4053)) {
    return 0;
  }
  return 1;
}

