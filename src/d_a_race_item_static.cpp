#include <d_a_race_item_static.h>
#include <d_a_race_item_static.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <d_item.h>
#include <d_save.h>
#include <mtx/mtx.h>
#include <m_Do_mtx.h>
#include <daRaceItem_c.h>


/* WARNING: Removing unreachable block (ram,0x80068a84) */
/* __thiscall daRaceItem_c::raceItemForceGet(void) */

void __thiscall daRaceItem_c::raceItemForceGet(daRaceItem_c *this)

{
  char cVar1;
  
  (this->parent).mScaleTarget.y = 1.401298e-45;
  cVar1 = *(char *)&(this->parent).mScaleTarget.z;
  if (cVar1 == '\x01') {
    normalItemGet(this);
  }
  else {
    if (cVar1 == '\0') {
      raceItemGet(this);
    }
  }
  return;
}


/* __thiscall daRaceItem_c::raceItemGet(void) */

void __thiscall daRaceItem_c::raceItemGet(daRaceItem_c *this)

{
  switch((this->parent).mItemNo) {
  case GreenRupee:
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x826,(cXyz *)0x0,0,0,d_a_race_item_static::_4056,
               d_a_race_item_static::_4056,d_a_race_item_static::_4057,d_a_race_item_static::_4057,0
              );
    if (d_com_inf_game::g_dComIfG_gameInfo._23772_2_ + 1 < 1) {
      d_com_inf_game::g_dComIfG_gameInfo._23772_2_ = 0;
    }
    else {
      d_com_inf_game::g_dComIfG_gameInfo._23772_2_ =
           d_com_inf_game::g_dComIfG_gameInfo._23772_2_ + 1;
    }
    break;
  case BlueRupee:
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x835,(cXyz *)0x0,0,0,d_a_race_item_static::_4056,
               d_a_race_item_static::_4056,d_a_race_item_static::_4057,d_a_race_item_static::_4057,0
              );
    if (d_com_inf_game::g_dComIfG_gameInfo._23772_2_ + 5 < 1) {
      d_com_inf_game::g_dComIfG_gameInfo._23772_2_ = 0;
    }
    else {
      d_com_inf_game::g_dComIfG_gameInfo._23772_2_ =
           d_com_inf_game::g_dComIfG_gameInfo._23772_2_ + 5;
    }
    break;
  case YellowRupee:
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x826,(cXyz *)0x0,0,0,d_a_race_item_static::_4056,
               d_a_race_item_static::_4056,d_a_race_item_static::_4057,d_a_race_item_static::_4057,0
              );
    if (d_com_inf_game::g_dComIfG_gameInfo._23772_2_ + 10 < 1) {
      d_com_inf_game::g_dComIfG_gameInfo._23772_2_ = 0;
    }
    else {
      d_com_inf_game::g_dComIfG_gameInfo._23772_2_ =
           d_com_inf_game::g_dComIfG_gameInfo._23772_2_ + 10;
    }
    break;
  case RedRupee:
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x836,(cXyz *)0x0,0,0,d_a_race_item_static::_4056,
               d_a_race_item_static::_4056,d_a_race_item_static::_4057,d_a_race_item_static::_4057,0
              );
    if (d_com_inf_game::g_dComIfG_gameInfo._23772_2_ + 0x14 < 1) {
      d_com_inf_game::g_dComIfG_gameInfo._23772_2_ = 0;
    }
    else {
      d_com_inf_game::g_dComIfG_gameInfo._23772_2_ =
           d_com_inf_game::g_dComIfG_gameInfo._23772_2_ + 0x14;
    }
    break;
  case PurpleRupee:
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x826,(cXyz *)0x0,0,0,d_a_race_item_static::_4056,
               d_a_race_item_static::_4056,d_a_race_item_static::_4057,d_a_race_item_static::_4057,0
              );
    if (d_com_inf_game::g_dComIfG_gameInfo._23772_2_ + 0x32 < 1) {
      d_com_inf_game::g_dComIfG_gameInfo._23772_2_ = 0;
    }
    else {
      d_com_inf_game::g_dComIfG_gameInfo._23772_2_ =
           d_com_inf_game::g_dComIfG_gameInfo._23772_2_ + 0x32;
    }
    break;
  case OrangeRupee:
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x826,(cXyz *)0x0,0,0,d_a_race_item_static::_4056,
               d_a_race_item_static::_4056,d_a_race_item_static::_4057,d_a_race_item_static::_4057,0
              );
    if (d_com_inf_game::g_dComIfG_gameInfo._23772_2_ + 100 < 1) {
      d_com_inf_game::g_dComIfG_gameInfo._23772_2_ = 0;
    }
    else {
      d_com_inf_game::g_dComIfG_gameInfo._23772_2_ =
           d_com_inf_game::g_dComIfG_gameInfo._23772_2_ + 100;
    }
    break;
  case SilverRupee:
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x826,(cXyz *)0x0,0,0,d_a_race_item_static::_4056,
               d_a_race_item_static::_4056,d_a_race_item_static::_4057,d_a_race_item_static::_4057,0
              );
    if (d_com_inf_game::g_dComIfG_gameInfo._23772_2_ + 200 < 1) {
      d_com_inf_game::g_dComIfG_gameInfo._23772_2_ = 0;
    }
    else {
      d_com_inf_game::g_dComIfG_gameInfo._23772_2_ =
           d_com_inf_game::g_dComIfG_gameInfo._23772_2_ + 200;
    }
  }
  return;
}


/* __thiscall daRaceItem_c::normalItemGet(void) */

void __thiscall daRaceItem_c::normalItemGet(daRaceItem_c *this)

{
  int iVar1;
  
  (this->parent).mScaleTarget.y = 1.401298e-45;
  d_item::execItemGet((this->parent).mItemNo);
  iVar1 = (this->parent).mPickupFlag;
  if (iVar1 != 0x7f) {
    dSv_info_c::onItem(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo,iVar1,
                       (int)(char)(this->parent).parent.mOrig.mRoomNo);
  }
  switch((this->parent).mItemNo) {
  case GreenRupee:
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x826,(cXyz *)0x0,0,0,d_a_race_item_static::_4056,
               d_a_race_item_static::_4056,d_a_race_item_static::_4057,d_a_race_item_static::_4057,0
              );
    break;
  case BlueRupee:
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x835,(cXyz *)0x0,0,0,d_a_race_item_static::_4056,
               d_a_race_item_static::_4056,d_a_race_item_static::_4057,d_a_race_item_static::_4057,0
              );
    break;
  case YellowRupee:
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x836,(cXyz *)0x0,0,0,d_a_race_item_static::_4056,
               d_a_race_item_static::_4056,d_a_race_item_static::_4057,d_a_race_item_static::_4057,0
              );
    break;
  case RedRupee:
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x836,(cXyz *)0x0,0,0,d_a_race_item_static::_4056,
               d_a_race_item_static::_4056,d_a_race_item_static::_4057,d_a_race_item_static::_4057,0
              );
    break;
  case PurpleRupee:
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x836,(cXyz *)0x0,0,0,d_a_race_item_static::_4056,
               d_a_race_item_static::_4056,d_a_race_item_static::_4057,d_a_race_item_static::_4057,0
              );
    break;
  case OrangeRupee:
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x836,(cXyz *)0x0,0,0,d_a_race_item_static::_4056,
               d_a_race_item_static::_4056,d_a_race_item_static::_4057,d_a_race_item_static::_4057,0
              );
    break;
  case SmallMagicJar:
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x879,(cXyz *)0x0,0,0,d_a_race_item_static::_4056,
               d_a_race_item_static::_4056,d_a_race_item_static::_4057,d_a_race_item_static::_4057,0
              );
    break;
  case LargeMagicJar:
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x87a,(cXyz *)0x0,0,0,d_a_race_item_static::_4056,
               d_a_race_item_static::_4056,d_a_race_item_static::_4057,d_a_race_item_static::_4057,0
              );
    break;
  case FiveBombs:
  case TenBombs:
  case TwentyBombs:
  case ThirtyBombs:
  case TenArrows:
  case TwentyArrows:
  case ThirtyArrows:
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x827,(cXyz *)0x0,0,0,d_a_race_item_static::_4056,
               d_a_race_item_static::_4056,d_a_race_item_static::_4057,d_a_race_item_static::_4057,0
              );
    break;
  case SilverRupee:
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x836,(cXyz *)0x0,0,0,d_a_race_item_static::_4056,
               d_a_race_item_static::_4056,d_a_race_item_static::_4057,d_a_race_item_static::_4057,0
              );
    break;
  case triple_heart:
    JAIZelBasic::seStart
              (JAIZelBasic::zel_basic,0x821,(cXyz *)0x0,0,0,d_a_race_item_static::_4056,
               d_a_race_item_static::_4056,d_a_race_item_static::_4057,d_a_race_item_static::_4057,0
              );
  }
  return;
}


/* __thiscall daRaceItem_c::startOffsetPos(void) */

undefined4 __thiscall daRaceItem_c::startOffsetPos(daRaceItem_c *this)

{
  (this->parent).mScaleTarget.y = 0.0;
  return 1;
}


/* __thiscall daRaceItem_c::endOffsetPos(float,
                                         cXyz *,
                                         float,
                                         float,
                                         csXyz *) */

undefined4 __thiscall
daRaceItem_c::endOffsetPos
          (daRaceItem_c *this,float param_1,cXyz *param_2,float param_3,float param_4,csXyz *param_5
          )

{
  if (param_5 != (csXyz *)0x0) {
    (this->parent).parent.mCurrent.mRot.x = param_5->x;
    (this->parent).parent.mCurrent.mRot.y = param_5->y;
    (this->parent).parent.mCurrent.mRot.z = param_5->z;
  }
  if (param_2 != (cXyz *)0x0) {
    (this->parent).parent.mScale.x = param_2->x;
    (this->parent).parent.mScale.y = param_2->y;
    (this->parent).parent.mScale.z = param_2->z;
  }
  (this->parent).parent.mAccelerationY = param_1;
  (this->parent).parent.mVelocityFwd = param_4;
  (this->parent).parent.mVelocity.y = param_3;
  (this->parent).mScaleTarget.y = 4.203895e-45;
  return 1;
}


/* __thiscall daRaceItem_c::checkOffsetPos(void) */

undefined4 __thiscall daRaceItem_c::checkOffsetPos(daRaceItem_c *this)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if (((*(byte *)((int)&(this->parent).mScaleTarget.z + 1) & 1) != 0) ||
     (((this->parent).parent.mStatus & 0x100000) != 0)) {
    uVar1 = 0;
  }
  return uVar1;
}


/* __thiscall daRaceItem_c::set_mtx(cXyz *) */

void __thiscall daRaceItem_c::set_mtx(daRaceItem_c *this,cXyz *param_1)

{
  J3DModel *pJVar1;
  
  pJVar1 = (this->parent).mpModel;
  (pJVar1->mBaseScale).x = (this->parent).parent.mScale.x;
  (pJVar1->mBaseScale).y = (this->parent).parent.mScale.y;
  (pJVar1->mBaseScale).z = (this->parent).parent.mScale.z;
  mtx::PSMTXTrans((double)param_1->x,(double)param_1->y,(double)param_1->z,&mDoMtx_stack_c::now);
  m_Do_mtx::mDoMtx_YrotM(&mDoMtx_stack_c::now,(this->parent).parent.mCurrent.mRot.y);
  mtx::PSMTXCopy(&mDoMtx_stack_c::now,&((this->parent).mpModel)->mBaseMtx);
  return;
}

