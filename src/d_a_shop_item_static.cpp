#include <d_a_shop_item_static.h>
#include <daShopItem_c.h>


/* __thiscall daShopItem_c::getScaleP(void) */

daShopItem_c * __thiscall daShopItem_c::getScaleP(daShopItem_c *this)

{
  return this + 0x214;
}


/* __thiscall daShopItem_c::getRotateP(void) */

daShopItem_c * __thiscall daShopItem_c::getRotateP(daShopItem_c *this)

{
  return this + 0x204;
}


/* __thiscall daShopItem_c::getPosP(void) */

daShopItem_c * __thiscall daShopItem_c::getPosP(daShopItem_c *this)

{
  return this + 0x1f8;
}


/* __thiscall daShopItem_c::getCenter(void) */

void __thiscall daShopItem_c::getCenter(daShopItem_c *this)

{
  float fVar1;
  float fVar2;
  int in_r4;
  
  fVar2 = d_a_shop_item_static::_4047;
  fVar1 = d_a_shop_item_static::_4046;
  if ((0x8b < *(byte *)(in_r4 + 0x63a)) && (*(byte *)(in_r4 + 0x63a) < 0x98)) {
    fVar1 = d_a_shop_item_static::_4045;
  }
  fVar1 = fVar1 * d_a_shop_item_static::_4048;
  *(float *)this = d_a_shop_item_static::_4047;
  *(float *)(this + 4) = fVar1;
  *(float *)(this + 8) = fVar2;
  return;
}

