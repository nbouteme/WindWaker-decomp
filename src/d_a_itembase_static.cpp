#include <d_a_itembase_static.h>
#include <d_a_itembase_static.h>
#include <d_a_itembase.h>
#include <daItemBase_c.h>


/* __thiscall daItemBase_c::getItemNo(void) */

dItem_data__ItemNo __thiscall daItemBase_c::getItemNo(daItemBase_c *this)

{
  return this->mItemNo;
}


/* __thiscall daItemBase_c::getHeight(void) */

byte __thiscall daItemBase_c::getHeight(daItemBase_c *this)

{
  return dItem_data::item_info[this->mItemNo].mCollisionH;
}


/* __thiscall daItemBase_c::getR(void) */

byte __thiscall daItemBase_c::getR(daItemBase_c *this)

{
  return dItem_data::item_info[this->mItemNo].mCollisionR;
}


/* __thiscall daItemBase_c::hide(void) */

void __thiscall daItemBase_c::hide(daItemBase_c *this)

{
  this->mDrawFlags = this->mDrawFlags & 0xfe;
  return;
}


/* __thiscall daItemBase_c::show(void) */

void __thiscall daItemBase_c::show(daItemBase_c *this)

{
  this->mDrawFlags = this->mDrawFlags | 1;
  return;
}


/* __thiscall daItemBase_c::changeDraw(void) */

void __thiscall daItemBase_c::changeDraw(daItemBase_c *this)

{
  char cVar1;
  
  cVar1 = chkDraw(this);
  if (cVar1 == '\0') {
    show(this);
  }
  else {
    hide(this);
  }
  return;
}


/* __thiscall daItemBase_c::chkDraw(void) */

bool __thiscall daItemBase_c::chkDraw(daItemBase_c *this)

{
  return (this->mDrawFlags & 1) != 0;
}


/* __thiscall daItemBase_c::dead(void) */

void __thiscall daItemBase_c::dead(daItemBase_c *this)

{
  this->mDrawFlags = this->mDrawFlags | 2;
  return;
}


/* __thiscall daItemBase_c::chkDead(void) */

bool __thiscall daItemBase_c::chkDead(daItemBase_c *this)

{
  return (this->mDrawFlags & 2) != 0;
}


/* __thiscall daItemBase_c::setLoadError(void) */

void __thiscall daItemBase_c::setLoadError(daItemBase_c *this)

{
  this->mDrawFlags = this->mDrawFlags | 4;
  return;
}


namespace d_a_itembase_static {

/* __stdcall CheckItemCreateHeap(fopAc_ac_c *) */

void CheckItemCreateHeap(daItemBase_c *param_1)

{
  uint uVar1;
  
  uVar1 = ::daItemBase_c::getItemNo(param_1);
  uVar1 = uVar1 & 0xff;
  ::daItemBase_c::CreateItemHeap
            (param_1,dItem_data::item_resource[uVar1].mModelArcName,
             dItem_data::item_resource[uVar1].mModelFileIdx,
             dItem_data::item_resource[uVar1].mBtkFileIdx,
             dItem_data::item_resource[uVar1].mBrkFileIdx,dItem_data::item_resource[uVar1].field_0xe
             ,dItem_data::item_resource[uVar1].field_0x10,
             dItem_data::item_resource[uVar1].field_0x12,-1);
  return;
}


/* __stdcall CheckFieldItemCreateHeap(fopAc_ac_c *) */

void CheckFieldItemCreateHeap(daItemBase_c *param_1)

{
  uint uVar1;
  
  uVar1 = ::daItemBase_c::getItemNo(param_1);
  uVar1 = uVar1 & 0xff;
  ::daItemBase_c::CreateItemHeap
            (param_1,dItem_data::field_item_res[uVar1].mModelArcName,
             dItem_data::field_item_res[uVar1].mModelFileId,
             dItem_data::field_item_res[uVar1].mBtkAnmResIdx1,
             dItem_data::field_item_res[uVar1].mBtkAnmResIdx2,
             dItem_data::field_item_res[uVar1].mBrkAnmResIdx1,
             dItem_data::field_item_res[uVar1].mBrkAnmResIdx2,
             dItem_data::field_item_res[uVar1].mBckAnmResIdx,-1);
  return;
}

