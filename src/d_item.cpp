#include <d_item.h>
#include <d_com_inf_game.h>
#include <d_save.h>
#include <d_item.h>
#include <SComponent/c_data_tbl.h>
#include <SComponent/c_math.h>


namespace d_item {

/* __stdcall execItemGet(unsigned char) */

void execItemGet(dItem_data__ItemNo itemNo)

{
  (*(code *)(&item_func_ptr)[itemNo])();
  return;
}


/* __stdcall checkItemGet(unsigned char,
                          int) */

int checkItemGet(uint param_1,int param_2)

{
  int iVar1;
  
  iVar1 = (*(code *)(&item_getcheck_func_ptr)[param_1 & 0xff])();
  if (iVar1 == -1) {
    iVar1 = param_2;
  }
  return iVar1;
}


/* __stdcall item_func_heart(void) */

void item_func_heart(void)

{
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAdjustHp =
       (int)((float)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAdjustHp + _3972);
  return;
}


/* __stdcall item_func_green_rupee(void) */

void item_func_green_rupee(void)

{
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAdjustRupees =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAdjustRupees + 1;
  return;
}


/* __stdcall item_func_blue_rupee(void) */

void item_func_blue_rupee(void)

{
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAdjustRupees =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAdjustRupees + 5;
  return;
}


/* __stdcall item_func_white_rupee(void) */

void item_func_white_rupee(void)

{
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAdjustRupees =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAdjustRupees + 10;
  return;
}


/* __stdcall item_func_red_rupee(void) */

void item_func_red_rupee(void)

{
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAdjustRupees =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAdjustRupees + 0x14;
  return;
}


/* __stdcall item_func_purple_rupee(void) */

void item_func_purple_rupee(void)

{
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAdjustRupees =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAdjustRupees + 0x32;
  return;
}


/* __stdcall item_func_orange_rupee(void) */

void item_func_orange_rupee(void)

{
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAdjustRupees =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAdjustRupees + 100;
  return;
}


/* __stdcall item_func_kakera_heart(void) */

void item_func_kakera_heart(void)

{
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCollectHeartPieceCount =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCollectHeartPieceCount + 1;
  return;
}


/* __stdcall item_func_utuwa_heart(void) */

void item_func_utuwa_heart(void)

{
  int iVar1;
  
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCollectHeartPieceCount =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay.mCollectHeartPieceCount + 4;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAdjustHp =
       (int)((float)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAdjustHp +
            (float)((double)CONCAT44(0x43300000,
                                     (uint)(ushort)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.
                                                   mPlayer.mStatusA.mMaxHp) - _4043));
  iVar1 = (*(code *)(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mStageData.parent)->getStagInfo)
                    (0x803c9d58);
  if (*(byte *)(iVar1 + 9) >> 1 == 0) {
    d_com_inf_game::dComIfGs_onStageLife(2);
  }
  else {
    dSv_memBit_c::onDungeonItem
              ((dSv_memBit_c *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMemory,4);
  }
  return;
}


/* __stdcall item_func_s_magic(void) */

void item_func_s_magic(void)

{
  d_com_inf_game::g_dComIfG_gameInfo.mPlay._18648_2_ =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay._18648_2_ + 4;
  return;
}


/* __stdcall item_func_l_magic(void) */

void item_func_l_magic(void)

{
  d_com_inf_game::g_dComIfG_gameInfo.mPlay._18648_2_ =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay._18648_2_ + 8;
  return;
}


/* __stdcall item_func_bomb_5(void) */

void item_func_bomb_5(void)

{
  dSv_player_get_item_c::onItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,0xd,'\0');
  d_com_inf_game::g_dComIfG_gameInfo.mPlay._18660_2_ =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay._18660_2_ + 5;
  d_com_inf_game::g_dComIfG_gameInfo._23517_1_ = 0xd;
  d_com_inf_game::g_dComIfG_gameInfo._23518_1_ = 0xb;
  return;
}


/* __stdcall item_func_bomb_10(void) */

void item_func_bomb_10(void)

{
  dSv_player_get_item_c::onItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,0xd,'\0');
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem._13_1_ = 0x31;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay._18660_2_ =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay._18660_2_ + 10;
  return;
}


/* __stdcall item_func_bomb_20(void) */

void item_func_bomb_20(void)

{
  dSv_player_get_item_c::onItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,0xd,'\0');
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem._13_1_ = 0x31;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay._18660_2_ =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay._18660_2_ + 0x14;
  return;
}


/* __stdcall item_func_bomb_30(void) */

void item_func_bomb_30(void)

{
  dSv_player_get_item_c::onItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,0xd,'\0');
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem._13_1_ = 0x31;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay._18660_2_ =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay._18660_2_ + 0x1e;
  return;
}


/* __stdcall item_func_silver_rupee(void) */

void item_func_silver_rupee(void)

{
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAdjustRupees =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAdjustRupees + 200;
  return;
}


/* __stdcall item_func_arrow_10(void) */

void item_func_arrow_10(void)

{
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.field_0x48e0 =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay.field_0x48e0 + 10;
  return;
}


/* __stdcall item_func_arrow_20(void) */

void item_func_arrow_20(void)

{
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.field_0x48e0 =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay.field_0x48e0 + 0x14;
  return;
}


/* __stdcall item_func_arrow_30(void) */

void item_func_arrow_30(void)

{
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.field_0x48e0 =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay.field_0x48e0 + 0x1e;
  return;
}


/* __stdcall item_func_small_key(void) */

void item_func_small_key(void)

{
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.field_0x48d4 =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay.field_0x48d4 + 1;
  return;
}


/* __stdcall item_func_recover_faily(void) */

void item_func_recover_faily(void)

{
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAdjustHp =
       (int)((float)d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAdjustHp + _4252);
  return;
}


/* __stdcall item_func_subdun_rupee(void) */

void item_func_subdun_rupee(void)

{
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAdjustRupees =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAdjustRupees + 10;
  return;
}


/* __stdcall item_func_triple_heart(void) */

void item_func_triple_heart(void)

{
  return;
}


/* __stdcall item_func_pendant(void) */

void item_func_pendant(void)

{
  dSv_player_bag_item_c::setBeastItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem,'\x1f');
  dSv_player_get_bag_item_c::onBeast
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,7);
  d_com_inf_game::g_dComIfG_gameInfo._23446_2_ = d_com_inf_game::g_dComIfG_gameInfo._23446_2_ + 1;
  return;
}


/* __stdcall item_func_telescope(void) */

void item_func_telescope(void)

{
  dSv_player_get_item_c::onItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,0,'\0');
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.mTelescopeSlot = Telescope;
  return;
}


/* __stdcall item_func_tncl_whitsl(void) */

void item_func_tncl_whitsl(void)

{
  dSv_player_get_item_c::onItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,7,'\0');
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.field_0x7 = TingleTuner;
  return;
}


/* __stdcall item_func_wind_tact(void) */

void item_func_wind_tact(void)

{
  dSv_player_get_item_c::onItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,2,'\0');
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.field_0x2 = WindWaker;
  return;
}


/* __stdcall item_func_camera(void) */

void item_func_camera(void)

{
  dSv_player_get_item_c::onItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,8,'\0');
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.field_0x8 = PictoBox;
  return;
}


/* __stdcall item_func_emono_bag(void) */

void item_func_emono_bag(void)

{
  dSv_player_get_item_c::onItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,4,'\0');
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.field_0x4 = SpoilsBag;
  return;
}


/* __stdcall item_func_rope(void) */

void item_func_rope(void)

{
  dSv_player_get_item_c::onItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,3,'\0');
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.field_0x3 = GrapplingHook;
  return;
}


/* __stdcall item_func_camera2(void) */

void item_func_camera2(void)

{
  dSv_player_get_item_c::onItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,8,'\x01');
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.field_0x8 = DeluxePictoBox;
  return;
}


/* __stdcall item_func_bow(void) */

void item_func_bow(void)

{
  dSv_player_get_item_c::onItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,0xc,'\0');
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.mBowSlot = HerosBow;
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._3_1_ = 0x1e;
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax.field_0x1 = 0x1e;
  return;
}


/* __stdcall item_func_pwr_groove(void) */

void item_func_pwr_groove(void)

{
  dSv_player_collect_c::onCollect
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,2,0);
  d_com_inf_game::dComIfGs_setSelectEquip(2,PowerBracelets);
  return;
}


/* __stdcall item_func_hvy_boots(void) */

void item_func_hvy_boots(void)

{
  dSv_player_get_item_c::onItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,9,'\0');
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.field_0x9 = IronBoots;
  return;
}


/* __stdcall item_func_drgn_shield(void) */

void item_func_drgn_shield(void)

{
  dSv_player_get_item_c::onItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,10,'\0');
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.field_0xa = MagicArmor;
  return;
}


/* __stdcall item_func_water_boots(void) */

void item_func_water_boots(void)

{
  return;
}


/* __stdcall item_func_esa_bag(void) */

void item_func_esa_bag(void)

{
  dSv_player_get_item_c::onItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,0xb,'\0');
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.field_0xb = BaitBag;
  return;
}


/* __stdcall item_func_boomerang(void) */

void item_func_boomerang(void)

{
  dSv_player_get_item_c::onItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,5,'\0');
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.field_0x5 = Boomerang;
  return;
}


/* __stdcall item_func_bare_hand(void) */

void item_func_bare_hand(void)

{
  d_com_inf_game::dComIfGs_setSelectEquip(2,0x2e);
  return;
}


/* __stdcall item_func_hookshot(void) */

void item_func_hookshot(void)

{
  dSv_player_get_item_c::onItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,0x13,'\0');
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem._19_1_ = 0x2f;
  return;
}


/* __stdcall item_func_warasibe_bag(void) */

void item_func_warasibe_bag(void)

{
  dSv_player_get_item_c::onItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,0x12,'\0');
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem._18_1_ = 0x30;
  return;
}


/* __stdcall item_func_bomb_bag(void) */

void item_func_bomb_bag(void)

{
  dSv_player_get_item_c::onItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,0xd,'\0');
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem._13_1_ = 0x31;
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._4_1_ = 0x1e;
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax.field_0x2 = 0x1e;
  return;
}


/* __stdcall item_func_fuku(void) */

void item_func_fuku(void)

{
  return;
}


/* __stdcall item_func_hummer(void) */

void item_func_hummer(void)

{
  dSv_player_get_item_c::onItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,0x14,'\0');
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem._20_1_ = 0x33;
  return;
}


/* __stdcall item_func_deku_leaf(void) */

void item_func_deku_leaf(void)

{
  dSv_player_get_item_c::onItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,6,'\0');
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.field_0x6 = DekuLeaf;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay._18648_2_ =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay._18648_2_ + 0x10;
  d_com_inf_game::g_dComIfG_gameInfo.mPlay._18652_2_ =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay._18652_2_ + 0x10;
  return;
}


/* WARNING: Type propagation algorithm not settling */
/* __stdcall item_func_magic_arrow(void) */

void item_func_magic_arrow(void)

{
  dItem_data__ItemNo dVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  int iVar6;
  
  dSv_player_get_item_c::onItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,0xc,'\x01');
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.mBowSlot = FireAndIceArrows;
  iVar3 = 0;
  iVar6 = 3;
  do {
    if (d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[iVar3] == HerosBow) {
      pbVar5 = (byte *)(d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                        mInventorySlotIndexOnButton + iVar3);
      uVar4 = (uint)(byte)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                          mInventorySlotIndexOnButton[iVar3];
      if (uVar4 == 0xff) {
        d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[iVar3] = InvalidItem;
      }
      else {
        if (uVar4 < 0x15) {
          dVar1 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
                  mStageName[uVar4];
        }
        else {
          if (uVar4 < 0x18) {
            dVar1 = InvalidItem;
          }
          else {
            if (uVar4 < 0x20) {
              dVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                      [uVar4 + 0xd];
            }
            else {
              if (uVar4 < 0x24) {
                dVar1 = InvalidItem;
              }
              else {
                if (uVar4 < 0x2c) {
                  dVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                          [uVar4 + 9];
                }
                else {
                  if (uVar4 < 0x30) {
                    dVar1 = InvalidItem;
                  }
                  else {
                    if (uVar4 < 0x38) {
                      dVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.
                              mBits[uVar4 + 5];
                    }
                    else {
                      dVar1 = InvalidItem;
                    }
                  }
                }
              }
            }
          }
        }
        d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[iVar3] = dVar1;
        uVar4 = (uint)*pbVar5;
        if (uVar4 < 0x15) {
          bVar2 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
                  mStageName[uVar4];
        }
        else {
          if (uVar4 < 0x18) {
            bVar2 = 0xff;
          }
          else {
            if (uVar4 < 0x20) {
              bVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                      [uVar4 + 0xd];
            }
            else {
              if (uVar4 < 0x24) {
                bVar2 = 0xff;
              }
              else {
                if (uVar4 < 0x2c) {
                  bVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                          [uVar4 + 9];
                }
                else {
                  if (uVar4 < 0x30) {
                    bVar2 = 0xff;
                  }
                  else {
                    if (uVar4 < 0x38) {
                      bVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.
                              mBits[uVar4 + 5];
                    }
                    else {
                      bVar2 = 0xff;
                    }
                  }
                }
              }
            }
          }
        }
        if (bVar2 == 0xff) {
          *pbVar5 = 0xff;
        }
      }
    }
    iVar3 = iVar3 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  return;
}


/* WARNING: Type propagation algorithm not settling */
/* __stdcall item_func_light_arrow(void) */

void item_func_light_arrow(void)

{
  dItem_data__ItemNo dVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  int iVar6;
  
  dSv_player_get_item_c::onItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,0xc,'\x02');
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.mBowSlot = LightArrow;
  iVar3 = 0;
  iVar6 = 3;
  do {
    if (d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[iVar3] == FireAndIceArrows) {
      pbVar5 = (byte *)(d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                        mInventorySlotIndexOnButton + iVar3);
      uVar4 = (uint)(byte)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                          mInventorySlotIndexOnButton[iVar3];
      if (uVar4 == 0xff) {
        d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[iVar3] = InvalidItem;
      }
      else {
        if (uVar4 < 0x15) {
          dVar1 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
                  mStageName[uVar4];
        }
        else {
          if (uVar4 < 0x18) {
            dVar1 = InvalidItem;
          }
          else {
            if (uVar4 < 0x20) {
              dVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                      [uVar4 + 0xd];
            }
            else {
              if (uVar4 < 0x24) {
                dVar1 = InvalidItem;
              }
              else {
                if (uVar4 < 0x2c) {
                  dVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                          [uVar4 + 9];
                }
                else {
                  if (uVar4 < 0x30) {
                    dVar1 = InvalidItem;
                  }
                  else {
                    if (uVar4 < 0x38) {
                      dVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.
                              mBits[uVar4 + 5];
                    }
                    else {
                      dVar1 = InvalidItem;
                    }
                  }
                }
              }
            }
          }
        }
        d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[iVar3] = dVar1;
        uVar4 = (uint)*pbVar5;
        if (uVar4 < 0x15) {
          bVar2 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
                  mStageName[uVar4];
        }
        else {
          if (uVar4 < 0x18) {
            bVar2 = 0xff;
          }
          else {
            if (uVar4 < 0x20) {
              bVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                      [uVar4 + 0xd];
            }
            else {
              if (uVar4 < 0x24) {
                bVar2 = 0xff;
              }
              else {
                if (uVar4 < 0x2c) {
                  bVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                          [uVar4 + 9];
                }
                else {
                  if (uVar4 < 0x30) {
                    bVar2 = 0xff;
                  }
                  else {
                    if (uVar4 < 0x38) {
                      bVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.
                              mBits[uVar4 + 5];
                    }
                    else {
                      bVar2 = 0xff;
                    }
                  }
                }
              }
            }
          }
        }
        if (bVar2 == 0xff) {
          *pbVar5 = 0xff;
        }
      }
    }
    iVar3 = iVar3 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  return;
}


/* __stdcall item_func_sword(void) */

void item_func_sword(void)

{
  dSv_player_collect_c::onCollect
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,0,0);
  d_com_inf_game::dComIfGs_setSelectEquip(0,HerosSword);
  return;
}


/* __stdcall item_func_master_sword(void) */

void item_func_master_sword(void)

{
  dSv_player_collect_c::onCollect
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,0,1);
  d_com_inf_game::dComIfGs_setSelectEquip(0,MasterSwordPowerless);
  return;
}


/* __stdcall item_func_lv3_sword(void) */

void item_func_lv3_sword(void)

{
  dSv_player_collect_c::onCollect
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,0,2);
  d_com_inf_game::dComIfGs_setSelectEquip(0,MasterSwordHalfPower);
  return;
}


/* __stdcall item_func_shield(void) */

void item_func_shield(void)

{
  dSv_player_collect_c::onCollect
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,1,0);
  d_com_inf_game::dComIfGs_setSelectEquip(1,HerosShield);
  return;
}


/* __stdcall item_func_mirror_shield(void) */

void item_func_mirror_shield(void)

{
  dSv_player_collect_c::onCollect
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,1,1);
  d_com_inf_game::dComIfGs_setSelectEquip(1,MirrorShield);
  return;
}


/* __stdcall item_func_dropped_sword(void) */

void item_func_dropped_sword(void)

{
  dSv_player_collect_c::onCollect
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,0,0);
  d_com_inf_game::dComIfGs_setSelectEquip(0,HerosSword);
  return;
}


/* __stdcall item_func_master_sword_ex(void) */

void item_func_master_sword_ex(void)

{
  dSv_player_collect_c::onCollect
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,0,3);
  d_com_inf_game::dComIfGs_setSelectEquip(0,MasterSwordFullPower);
  return;
}


/* __stdcall item_func_pirates_omamori(void) */

void item_func_pirates_omamori(void)

{
  dSv_player_collect_c::onCollect
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,3,0);
  return;
}


/* __stdcall item_func_heros_omamori(void) */

void item_func_heros_omamori(void)

{
  dSv_player_collect_c::onCollect
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,4,0);
  return;
}


/* __stdcall item_func_grass_ball(void) */

void item_func_grass_ball(void)

{
  return;
}


/* __stdcall item_func_skull_necklace(void) */

void item_func_skull_necklace(void)

{
  dSv_player_bag_item_c::setBeastItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem,'E');
  dSv_player_get_bag_item_c::onBeast
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,0);
  d_com_inf_game::g_dComIfG_gameInfo.mPlay._18664_2_ =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay._18664_2_ + 1;
  return;
}


/* __stdcall item_func_bokobaba_seed(void) */

void item_func_bokobaba_seed(void)

{
  dSv_player_bag_item_c::setBeastItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem,'F');
  dSv_player_get_bag_item_c::onBeast
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,1);
  d_com_inf_game::g_dComIfG_gameInfo.mPlay._18666_2_ =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay._18666_2_ + 1;
  return;
}


/* __stdcall item_func_golden_feather(void) */

void item_func_golden_feather(void)

{
  dSv_player_bag_item_c::setBeastItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem,'G');
  dSv_player_get_bag_item_c::onBeast
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,2);
  d_com_inf_game::g_dComIfG_gameInfo.mPlay._18668_2_ =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay._18668_2_ + 1;
  return;
}


/* __stdcall item_func_boko_belt(void) */

void item_func_boko_belt(void)

{
  dSv_player_bag_item_c::setBeastItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem,'H');
  dSv_player_get_bag_item_c::onBeast
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,3);
  d_com_inf_game::g_dComIfG_gameInfo.mPlay._18670_2_ =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay._18670_2_ + 1;
  return;
}


/* __stdcall item_func_red_jerry(void) */

void item_func_red_jerry(void)

{
  dSv_player_bag_item_c::setBeastItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem,'I');
  dSv_player_get_bag_item_c::onBeast
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,4);
  d_com_inf_game::g_dComIfG_gameInfo.mPlay._18672_2_ =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay._18672_2_ + 1;
  return;
}


/* __stdcall item_func_green_jerry(void) */

void item_func_green_jerry(void)

{
  dSv_player_bag_item_c::setBeastItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem,'J');
  dSv_player_get_bag_item_c::onBeast
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,5);
  d_com_inf_game::g_dComIfG_gameInfo.mPlay._18674_2_ =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay._18674_2_ + 1;
  return;
}


/* __stdcall item_func_blue_jerry(void) */

void item_func_blue_jerry(void)

{
  dSv_player_bag_item_c::setBeastItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem,'K');
  dSv_player_get_bag_item_c::onBeast
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,6);
  d_com_inf_game::g_dComIfG_gameInfo._23444_2_ = d_com_inf_game::g_dComIfG_gameInfo._23444_2_ + 1;
  return;
}


/* __stdcall item_func_map(void) */

void item_func_map(void)

{
  dSv_memBit_c::onDungeonItem((dSv_memBit_c *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMemory,0)
  ;
  return;
}


/* __stdcall item_func_compass(void) */

void item_func_compass(void)

{
  dSv_memBit_c::onDungeonItem((dSv_memBit_c *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMemory,1)
  ;
  return;
}


/* __stdcall item_func_boss_key(void) */

void item_func_boss_key(void)

{
  dSv_memBit_c::onDungeonItem((dSv_memBit_c *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMemory,2)
  ;
  return;
}


/* __stdcall item_func_empty_bship(void) */

void item_func_empty_bship(void)

{
  dSv_player_get_item_c::onBottleItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,'O');
  return;
}


/* __stdcall item_func_empty_bottle(void) */

void item_func_empty_bottle(void)

{
  dSv_player_item_c::setEmptyBottle(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem)
  ;
  dSv_player_get_item_c::onBottleItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,'P');
  return;
}


/* __stdcall item_func_red_bottle(void) */

void item_func_red_bottle(void)

{
  dSv_player_item_c::setEmptyBottleItemIn
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem,'Q');
  dSv_player_get_item_c::onBottleItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,'Q');
  return;
}


/* __stdcall item_func_green_bottle(void) */

void item_func_green_bottle(void)

{
  dSv_player_item_c::setEmptyBottleItemIn
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem,'R');
  dSv_player_get_item_c::onBottleItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,'R');
  return;
}


/* __stdcall item_func_blue_bottle(void) */

void item_func_blue_bottle(void)

{
  dSv_player_item_c::setEmptyBottleItemIn
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem,'S');
  dSv_player_get_item_c::onBottleItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,'S');
  return;
}


/* __stdcall item_func_bottleship(void) */

void item_func_bottleship(void)

{
  dSv_player_get_item_c::onBottleItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,'T');
  return;
}


/* __stdcall item_func_soup_bottle(void) */

void item_func_soup_bottle(void)

{
  dSv_player_get_item_c::onBottleItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,'U');
  return;
}


/* __stdcall item_func_bin_in_water(void) */

void item_func_bin_in_water(void)

{
  dSv_player_get_item_c::onBottleItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,'V');
  return;
}


/* __stdcall item_func_fairy_bottle(void) */

void item_func_fairy_bottle(void)

{
  dSv_player_get_item_c::onBottleItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,'W');
  return;
}


/* __stdcall item_func_firefly_bottle(void) */

void item_func_firefly_bottle(void)

{
  dSv_player_get_item_c::onBottleItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,'X');
  return;
}


/* __stdcall item_func_fwater_bottle(void) */

void item_func_fwater_bottle(void)

{
  dSv_player_get_item_c::onBottleItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,'Y');
  return;
}


/* __stdcall item_func_bin(void) */

void item_func_bin(void)

{
  return;
}


/* __stdcall item_func_triforce1(void) */

void item_func_triforce1(void)

{
  dSv_player_collect_c::onTriforce
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\0');
  return;
}


/* __stdcall item_func_triforce2(void) */

void item_func_triforce2(void)

{
  dSv_player_collect_c::onTriforce
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x01');
  return;
}


/* __stdcall item_func_triforce3(void) */

void item_func_triforce3(void)

{
  dSv_player_collect_c::onTriforce
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x02');
  return;
}


/* __stdcall item_func_triforce4(void) */

void item_func_triforce4(void)

{
  dSv_player_collect_c::onTriforce
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x03');
  return;
}


/* __stdcall item_func_triforce5(void) */

void item_func_triforce5(void)

{
  dSv_player_collect_c::onTriforce
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x04');
  return;
}


/* __stdcall item_func_triforce6(void) */

void item_func_triforce6(void)

{
  dSv_player_collect_c::onTriforce
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x05');
  return;
}


/* __stdcall item_func_triforce7(void) */

void item_func_triforce7(void)

{
  dSv_player_collect_c::onTriforce
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x06');
  return;
}


/* __stdcall item_func_triforce8(void) */

void item_func_triforce8(void)

{
  dSv_player_collect_c::onTriforce
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\a');
  return;
}


/* __stdcall item_func_pearl1(void) */

void item_func_pearl1(void)

{
  dSv_player_collect_c::onSymbol
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\0');
  return;
}


/* __stdcall item_func_pearl2(void) */

void item_func_pearl2(void)

{
  dSv_player_collect_c::onSymbol
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x01');
  return;
}


/* __stdcall item_func_pearl3(void) */

void item_func_pearl3(void)

{
  dSv_player_collect_c::onSymbol
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x02');
  return;
}


/* __stdcall item_func_knowledge_tf(void) */

void item_func_knowledge_tf(void)

{
  return;
}


/* __stdcall item_func_tact_song1(void) */

void item_func_tact_song1(void)

{
  dSv_player_collect_c::onTact
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\0');
  return;
}


/* __stdcall item_func_tact_song2(void) */

void item_func_tact_song2(void)

{
  dSv_player_collect_c::onTact
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x01');
  return;
}


/* __stdcall item_func_tact_song3(void) */

void item_func_tact_song3(void)

{
  dSv_player_collect_c::onTact
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x02');
  return;
}


/* __stdcall item_func_tact_song4(void) */

void item_func_tact_song4(void)

{
  dSv_player_collect_c::onTact
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x03');
  return;
}


/* __stdcall item_func_tact_song5(void) */

void item_func_tact_song5(void)

{
  dSv_player_collect_c::onTact
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x04');
  return;
}


/* __stdcall item_func_tact_song6(void) */

void item_func_tact_song6(void)

{
  dSv_player_collect_c::onTact
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x05');
  return;
}


/* __stdcall item_func_normal_sail(void) */

void item_func_normal_sail(void)

{
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.field_0x1 = normal_sail;
  dSv_player_get_item_c::onItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,1,'\0');
  return;
}


/* __stdcall item_func_triforce_map1(void) */

void item_func_triforce_map1(void)

{
  return;
}


/* __stdcall item_func_triforce_map2(void) */

void item_func_triforce_map2(void)

{
  return;
}


/* __stdcall item_func_triforce_map3(void) */

void item_func_triforce_map3(void)

{
  return;
}


/* __stdcall item_func_triforce_map4(void) */

void item_func_triforce_map4(void)

{
  return;
}


/* __stdcall item_func_triforce_map5(void) */

void item_func_triforce_map5(void)

{
  return;
}


/* __stdcall item_func_triforce_map6(void) */

void item_func_triforce_map6(void)

{
  return;
}


/* __stdcall item_func_triforce_map7(void) */

void item_func_triforce_map7(void)

{
  return;
}


/* __stdcall item_func_triforce_map8(void) */

void item_func_triforce_map8(void)

{
  return;
}


/* __stdcall item_func_bird_esa_5(void) */

void item_func_bird_esa_5(void)

{
  dSv_player_get_bag_item_c::onBait
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,0);
  dSv_player_bag_item_c::setBaitItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem,0x82);
  return;
}


/* __stdcall item_func_animal_esa(void) */

void item_func_animal_esa(void)

{
  dSv_player_get_bag_item_c::onBait
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,1);
  dSv_player_bag_item_c::setBaitItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem,0x83);
  return;
}


/* __stdcall item_func_esa1(void) */

void item_func_esa1(void)

{
  return;
}


/* __stdcall item_func_esa2(void) */

void item_func_esa2(void)

{
  return;
}


/* __stdcall item_func_esa3(void) */

void item_func_esa3(void)

{
  return;
}


/* __stdcall item_func_esa4(void) */

void item_func_esa4(void)

{
  return;
}


/* __stdcall item_func_esa5(void) */

void item_func_esa5(void)

{
  return;
}


/* __stdcall item_func_magic_bean(void) */

void item_func_magic_bean(void)

{
  return;
}


/* __stdcall item_func_bird_esa_10(void) */

void item_func_bird_esa_10(void)

{
  return;
}


/* __stdcall item_func_flower_1(void) */

void item_func_flower_1(void)

{
  dSv_player_get_bag_item_c::onReserve
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,'\0');
  dSv_player_bag_item_c::setReserveItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem,0x8c);
  return;
}


/* __stdcall item_func_flower_2(void) */

void item_func_flower_2(void)

{
  dSv_player_get_bag_item_c::onReserve
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,'\x01');
  dSv_player_bag_item_c::setReserveItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem,0x8d);
  return;
}


/* __stdcall item_func_flower_3(void) */

void item_func_flower_3(void)

{
  dSv_player_get_bag_item_c::onReserve
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,'\x02');
  dSv_player_bag_item_c::setReserveItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem,0x8e);
  return;
}


/* __stdcall item_func_heros_flag(void) */

void item_func_heros_flag(void)

{
  dSv_player_get_bag_item_c::onReserve
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,'\x03');
  dSv_player_bag_item_c::setReserveItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem,0x8f);
  return;
}


/* __stdcall item_func_tairyo_flag(void) */

void item_func_tairyo_flag(void)

{
  dSv_player_get_bag_item_c::onReserve
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,'\x04');
  dSv_player_bag_item_c::setReserveItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem,0x90);
  return;
}


/* __stdcall item_func_sales_flag(void) */

void item_func_sales_flag(void)

{
  dSv_player_get_bag_item_c::onReserve
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,'\x05');
  dSv_player_bag_item_c::setReserveItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem,0x91);
  return;
}


/* __stdcall item_func_wind_flag(void) */

void item_func_wind_flag(void)

{
  dSv_player_get_bag_item_c::onReserve
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,'\x06');
  dSv_player_bag_item_c::setReserveItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem,0x92);
  return;
}


/* __stdcall item_func_red_flag(void) */

void item_func_red_flag(void)

{
  dSv_player_get_bag_item_c::onReserve
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,'\a');
  dSv_player_bag_item_c::setReserveItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem,0x93);
  return;
}


/* __stdcall item_func_fossil_head(void) */

void item_func_fossil_head(void)

{
  dSv_player_get_bag_item_c::onReserve
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,'\b');
  dSv_player_bag_item_c::setReserveItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem,0x94);
  return;
}


/* __stdcall item_func_water_statue(void) */

void item_func_water_statue(void)

{
  dSv_player_get_bag_item_c::onReserve
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,'\t');
  dSv_player_bag_item_c::setReserveItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem,0x95);
  return;
}


/* __stdcall item_func_postman_statue(void) */

void item_func_postman_statue(void)

{
  dSv_player_get_bag_item_c::onReserve
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,'\n');
  dSv_player_bag_item_c::setReserveItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem,0x96);
  return;
}


/* __stdcall item_func_president_statue(void) */

void item_func_president_statue(void)

{
  dSv_player_get_bag_item_c::onReserve
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,'\v');
  dSv_player_bag_item_c::setReserveItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem,0x97);
  return;
}


/* __stdcall item_func_letter00(void) */

void item_func_letter00(void)

{
  dSv_player_get_bag_item_c::onReserve
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,'\f');
  dSv_player_bag_item_c::setReserveItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem,0x98);
  return;
}


/* __stdcall item_func_magic_seed(void) */

void item_func_magic_seed(void)

{
  dSv_player_get_bag_item_c::onReserve
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,'\r');
  dSv_player_bag_item_c::setReserveItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem,0x99);
  return;
}


/* __stdcall item_func_magys_letter(void) */

void item_func_magys_letter(void)

{
  dSv_player_get_bag_item_c::onReserve
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,'\x0e');
  dSv_player_bag_item_c::setReserveItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem,0x9a);
  return;
}


/* __stdcall item_func_mo_letter(void) */

void item_func_mo_letter(void)

{
  dSv_player_get_bag_item_c::onReserve
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,'\x0f');
  dSv_player_bag_item_c::setReserveItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem,0x9b);
  return;
}


/* __stdcall item_func_cottage_paper(void) */

void item_func_cottage_paper(void)

{
  dSv_player_get_bag_item_c::onReserve
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,'\x10');
  dSv_player_bag_item_c::setReserveItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem,0x9c);
  return;
}


/* __stdcall item_func_kaisen_present1(void) */

void item_func_kaisen_present1(void)

{
  dSv_player_get_bag_item_c::onReserve
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,'\x11');
  dSv_player_bag_item_c::setReserveItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem,0x9d);
  return;
}


/* __stdcall item_func_kaisen_present2(void) */

void item_func_kaisen_present2(void)

{
  dSv_player_get_bag_item_c::onReserve
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,'\x12');
  dSv_player_bag_item_c::setReserveItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem,0x9e);
  return;
}


/* __stdcall item_func_salvage_item1(void) */

void item_func_salvage_item1(void)

{
  return;
}


/* __stdcall item_func_salvage_item2(void) */

void item_func_salvage_item2(void)

{
  dSv_player_get_bag_item_c::onReserve
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,'\x14');
  dSv_player_bag_item_c::setReserveItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem,0xa0);
  return;
}


/* __stdcall item_func_salvage_item3(void) */

void item_func_salvage_item3(void)

{
  dSv_player_get_bag_item_c::onReserve
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,'\x15');
  dSv_player_bag_item_c::setReserveItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem,0xa1);
  return;
}


/* __stdcall item_func_xxx_039(void) */

void item_func_xxx_039(void)

{
  dSv_player_get_bag_item_c::onReserve
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,'\x16');
  dSv_player_bag_item_c::setReserveItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem,0xa2);
  return;
}


/* __stdcall item_func_tincle_statue01(void) */

void item_func_tincle_statue01(void)

{
  return;
}


/* __stdcall item_func_tincle_statue02(void) */

void item_func_tincle_statue02(void)

{
  return;
}


/* __stdcall item_func_tincle_statue03(void) */

void item_func_tincle_statue03(void)

{
  return;
}


/* __stdcall item_func_tincle_statue04(void) */

void item_func_tincle_statue04(void)

{
  return;
}


/* __stdcall item_func_tincle_statue05(void) */

void item_func_tincle_statue05(void)

{
  return;
}


/* __stdcall item_func_tincle_statue06(void) */

void item_func_tincle_statue06(void)

{
  return;
}


/* __stdcall item_func_max_rupee_up1(void) */

void item_func_max_rupee_up1(void)

{
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mCurrentWalletIndex = 1;
  return;
}


/* __stdcall item_func_max_rupee_up2(void) */

void item_func_max_rupee_up2(void)

{
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mCurrentWalletIndex = 2;
  return;
}


/* __stdcall item_func_max_bomb_up1(void) */

void item_func_max_bomb_up1(void)

{
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._4_1_ = 0x3c;
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax.field_0x2 = 0x3c;
  return;
}


/* __stdcall item_func_max_bomb_up2(void) */

void item_func_max_bomb_up2(void)

{
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._4_1_ = 99;
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax.field_0x2 = 99;
  return;
}


/* __stdcall item_func_max_arrow_up1(void) */

void item_func_max_arrow_up1(void)

{
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._3_1_ = 0x3c;
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax.field_0x1 = 0x3c;
  return;
}


/* __stdcall item_func_max_arrow_up2(void) */

void item_func_max_arrow_up2(void)

{
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._3_1_ = 99;
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax.field_0x1 = 99;
  return;
}


/* __stdcall item_func_magic_power(void) */

void item_func_magic_power(void)

{
  return;
}


/* __stdcall item_func_max_mp_up1(void) */

void item_func_max_mp_up1(void)

{
  d_com_inf_game::g_dComIfG_gameInfo.mPlay._18652_2_ =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay._18652_2_ + 0x20;
  return;
}


/* __stdcall item_func_tincle_rupee1(void) */

void item_func_tincle_rupee1(void)

{
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAdjustRupees =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAdjustRupees + 0x32;
  return;
}


/* __stdcall item_func_tincle_rupee2(void) */

void item_func_tincle_rupee2(void)

{
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAdjustRupees =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAdjustRupees + 100;
  return;
}


/* __stdcall item_func_tincle_rupee3(void) */

void item_func_tincle_rupee3(void)

{
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAdjustRupees =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAdjustRupees + 0x96;
  return;
}


/* __stdcall item_func_tincle_rupee4(void) */

void item_func_tincle_rupee4(void)

{
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAdjustRupees =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAdjustRupees + 200;
  return;
}


/* __stdcall item_func_tincle_rupee5(void) */

void item_func_tincle_rupee5(void)

{
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAdjustRupees =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAdjustRupees + 0xfa;
  return;
}


/* __stdcall item_func_tincle_rupee6(void) */

void item_func_tincle_rupee6(void)

{
  d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAdjustRupees =
       d_com_inf_game::g_dComIfG_gameInfo.mPlay.mAdjustRupees + 500;
  return;
}


/* __stdcall item_func_lithograph1(void) */

void item_func_lithograph1(void)

{
  dSv_event_c::onEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x3508);
  return;
}


/* __stdcall item_func_lithograph2(void) */

void item_func_lithograph2(void)

{
  dSv_event_c::onEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x3504);
  return;
}


/* __stdcall item_func_lithograph3(void) */

void item_func_lithograph3(void)

{
  dSv_event_c::onEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x3502);
  return;
}


/* __stdcall item_func_lithograph4(void) */

void item_func_lithograph4(void)

{
  dSv_event_c::onEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x3501);
  return;
}


/* __stdcall item_func_lithograph5(void) */

void item_func_lithograph5(void)

{
  dSv_event_c::onEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x3680);
  return;
}


/* __stdcall item_func_lithograph6(void) */

void item_func_lithograph6(void)

{
  dSv_event_c::onEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x3640);
  return;
}


/* __stdcall item_func_collectmap64(void) */

void item_func_collectmap64(void)

{
  dSv_event_c::onEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x3620);
  return;
}


/* __stdcall item_func_collectmap63(void) */

void item_func_collectmap63(void)

{
  dSv_event_c::onEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x3610);
  return;
}


/* __stdcall item_func_collectmap62(void) */

void item_func_collectmap62(void)

{
  dSv_event_c::onEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x3608);
  return;
}


/* __stdcall item_func_collectmap61(void) */

void item_func_collectmap61(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x3c);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x3c);
  dSv_player_map_c::offCompleteMap
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x3c);
  return;
}


/* __stdcall item_func_collectmap60(void) */

void item_func_collectmap60(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x3b);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x3b);
  dSv_player_map_c::offCompleteMap
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x3b);
  return;
}


/* __stdcall item_func_collectmap59(void) */

void item_func_collectmap59(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x3a);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x3a);
  dSv_player_map_c::offCompleteMap
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x3a);
  return;
}


/* __stdcall item_func_collectmap58(void) */

void item_func_collectmap58(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x39);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x39);
  dSv_player_map_c::offCompleteMap
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x39);
  return;
}


/* __stdcall item_func_collectmap57(void) */

void item_func_collectmap57(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x38);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x38);
  dSv_player_map_c::offCompleteMap
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x38);
  return;
}


/* __stdcall item_func_collectmap56(void) */

void item_func_collectmap56(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x37);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x37);
  dSv_player_map_c::offCompleteMap
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x37);
  return;
}


/* __stdcall item_func_collectmap55(void) */

void item_func_collectmap55(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x36);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x36);
  dSv_player_map_c::offCompleteMap
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x36);
  return;
}


/* __stdcall item_func_collectmap54(void) */

void item_func_collectmap54(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x35);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x35);
  dSv_player_map_c::offCompleteMap
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x35);
  return;
}


/* __stdcall item_func_collectmap53(void) */

void item_func_collectmap53(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x34);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x34);
  dSv_player_map_c::offCompleteMap
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x34);
  return;
}


/* __stdcall item_func_collectmap52(void) */

void item_func_collectmap52(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x33);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x33);
  dSv_player_map_c::offCompleteMap
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x33);
  return;
}


/* __stdcall item_func_collectmap51(void) */

void item_func_collectmap51(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x32);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x32);
  dSv_player_map_c::offCompleteMap
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x32);
  return;
}


/* __stdcall item_func_collectmap50(void) */

void item_func_collectmap50(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x31);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x31);
  dSv_player_map_c::offCompleteMap
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x31);
  return;
}


/* __stdcall item_func_collectmap49(void) */

void item_func_collectmap49(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x30);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x30);
  dSv_player_map_c::offCompleteMap
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x30);
  return;
}


/* __stdcall item_func_collectmap48(void) */

void item_func_collectmap48(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x2f);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x2f);
  dSv_player_map_c::offCompleteMap
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x2f);
  return;
}


/* __stdcall item_func_collectmap47(void) */

void item_func_collectmap47(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x2e);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x2e);
  dSv_player_map_c::offCompleteMap
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x2e);
  return;
}


/* __stdcall item_func_collectmap46(void) */

void item_func_collectmap46(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x2d);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x2d);
  dSv_player_map_c::offCompleteMap
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x2d);
  return;
}


/* __stdcall item_func_collectmap45(void) */

void item_func_collectmap45(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x2c);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x2c);
  dSv_player_map_c::offCompleteMap
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x2c);
  return;
}


/* __stdcall item_func_collectmap44(void) */

void item_func_collectmap44(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x2b);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x2b);
  dSv_player_map_c::offCompleteMap
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x2b);
  return;
}


/* __stdcall item_func_collectmap43(void) */

void item_func_collectmap43(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x2a);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x2a);
  dSv_player_map_c::offCompleteMap
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x2a);
  return;
}


/* __stdcall item_func_collectmap42(void) */

void item_func_collectmap42(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x29);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x29);
  dSv_player_map_c::offCompleteMap
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x29);
  return;
}


/* __stdcall item_func_collectmap41(void) */

void item_func_collectmap41(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x28);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x28);
  dSv_player_map_c::offCompleteMap
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x28);
  return;
}


/* __stdcall item_func_collectmap40(void) */

void item_func_collectmap40(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x27);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x27);
  dSv_player_map_c::offCompleteMap
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x27);
  return;
}


/* __stdcall item_func_collectmap39(void) */

void item_func_collectmap39(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x26);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x26);
  dSv_player_map_c::offCompleteMap
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x26);
  return;
}


/* __stdcall item_func_collectmap38(void) */

void item_func_collectmap38(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x25);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x25);
  dSv_player_map_c::offCompleteMap
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x25);
  return;
}


/* __stdcall item_func_collectmap37(void) */

void item_func_collectmap37(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x24);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x24);
  dSv_player_map_c::offCompleteMap
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x24);
  return;
}


/* __stdcall item_func_collectmap36(void) */

void item_func_collectmap36(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x23);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x23);
  dSv_player_map_c::offCompleteMap
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x23);
  return;
}


/* __stdcall item_func_collectmap35(void) */

void item_func_collectmap35(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x22);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x22);
  dSv_player_map_c::offCompleteMap
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x22);
  return;
}


/* __stdcall item_func_collectmap34(void) */

void item_func_collectmap34(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x21);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x21);
  dSv_player_map_c::offCompleteMap
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x21);
  return;
}


/* __stdcall item_func_collectmap33(void) */

void item_func_collectmap33(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x20);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x20);
  dSv_player_map_c::offCompleteMap
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x20);
  return;
}


/* __stdcall item_func_collectmap32(void) */

void item_func_collectmap32(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x1f);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x1f);
  dSv_player_map_c::offCompleteMap
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x1f);
  return;
}


/* __stdcall item_func_collectmap31(void) */

void item_func_collectmap31(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x1e);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x1e);
  dSv_player_map_c::offCompleteMap
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x1e);
  return;
}


/* __stdcall item_func_collectmap30(void) */

void item_func_collectmap30(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x1d);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x1d);
  dSv_player_map_c::offCompleteMap
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x1d);
  return;
}


/* __stdcall item_func_collectmap29(void) */

void item_func_collectmap29(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x1c);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x1c);
  dSv_player_map_c::offCompleteMap
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x1c);
  return;
}


/* __stdcall item_func_collectmap28(void) */

void item_func_collectmap28(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x1b);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x1b);
  dSv_player_map_c::offCompleteMap
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x1b);
  return;
}


/* __stdcall item_func_collectmap27(void) */

void item_func_collectmap27(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x1a);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x1a);
  dSv_player_map_c::offCompleteMap
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x1a);
  return;
}


/* __stdcall item_func_collectmap26(void) */

void item_func_collectmap26(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x19);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x19);
  dSv_player_map_c::offCompleteMap
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x19);
  return;
}


/* __stdcall item_func_collectmap25(void) */

void item_func_collectmap25(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x18);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x18);
  dSv_player_map_c::offCompleteMap
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x18);
  return;
}


/* __stdcall item_func_collectmap24(void) */

void item_func_collectmap24(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x17);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x17);
  dSv_player_map_c::offCompleteMap
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x17);
  return;
}


/* __stdcall item_func_collectmap23(void) */

void item_func_collectmap23(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x16);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x16);
  dSv_player_map_c::offCompleteMap
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x16);
  return;
}


/* __stdcall item_func_collectmap22(void) */

void item_func_collectmap22(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x15);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x15);
  dSv_player_map_c::offCompleteMap
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x15);
  return;
}


/* __stdcall item_func_collectmap21(void) */

void item_func_collectmap21(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x14);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x14);
  dSv_player_map_c::offCompleteMap
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x14);
  return;
}


/* __stdcall item_func_collectmap20(void) */

void item_func_collectmap20(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x13);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x13);
  dSv_player_map_c::offCompleteMap
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x13);
  return;
}


/* __stdcall item_func_collectmap19(void) */

void item_func_collectmap19(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x12);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x12);
  dSv_player_map_c::offCompleteMap
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x12);
  return;
}


/* __stdcall item_func_collectmap18(void) */

void item_func_collectmap18(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x11);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x11);
  dSv_player_map_c::offCompleteMap
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x11);
  return;
}


/* __stdcall item_func_collectmap17(void) */

void item_func_collectmap17(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x10);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x10);
  dSv_player_map_c::offCompleteMap
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x10);
  return;
}


/* __stdcall item_func_collectmap16(void) */

void item_func_collectmap16(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0xf);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0xf);
  dSv_player_map_c::offCompleteMap
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0xf);
  return;
}


/* __stdcall item_func_collectmap15(void) */

void item_func_collectmap15(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0xe);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0xe);
  dSv_player_map_c::offCompleteMap
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0xe);
  return;
}


/* __stdcall item_func_collectmap14(void) */

void item_func_collectmap14(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0xd);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0xd);
  dSv_player_map_c::offCompleteMap
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0xd);
  return;
}


/* __stdcall item_func_collectmap13(void) */

void item_func_collectmap13(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0xc);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0xc);
  dSv_player_map_c::offCompleteMap
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0xc);
  return;
}


/* __stdcall item_func_collectmap12(void) */

void item_func_collectmap12(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0xb);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0xb);
  dSv_player_map_c::offCompleteMap
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0xb);
  return;
}


/* __stdcall item_func_collectmap11(void) */

void item_func_collectmap11(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,10);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,10);
  dSv_player_map_c::offCompleteMap
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,10);
  return;
}


/* __stdcall item_func_collectmap10(void) */

void item_func_collectmap10(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,9);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,9);
  dSv_player_map_c::offCompleteMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,9)
  ;
  return;
}


/* __stdcall item_func_collectmap09(void) */

void item_func_collectmap09(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,8);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,8);
  dSv_player_map_c::offCompleteMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,8)
  ;
  return;
}


/* __stdcall item_func_collectmap08(void) */

void item_func_collectmap08(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,7);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,7);
  dSv_player_map_c::offCompleteMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,7)
  ;
  dSv_player_map_c::offTriforce(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,7);
  return;
}


/* __stdcall item_func_collectmap07(void) */

void item_func_collectmap07(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,6);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,6);
  dSv_player_map_c::offCompleteMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,6)
  ;
  return;
}


/* __stdcall item_func_collectmap06(void) */

void item_func_collectmap06(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,5);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,5);
  dSv_player_map_c::offCompleteMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,5)
  ;
  return;
}


/* __stdcall item_func_collectmap05(void) */

void item_func_collectmap05(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,4);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,4);
  dSv_player_map_c::offCompleteMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,4)
  ;
  return;
}


/* __stdcall item_func_collectmap04(void) */

void item_func_collectmap04(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,3);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,3);
  dSv_player_map_c::offCompleteMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,3)
  ;
  return;
}


/* __stdcall item_func_collectmap03(void) */

void item_func_collectmap03(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,2);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,2);
  dSv_player_map_c::offCompleteMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,2)
  ;
  return;
}


/* __stdcall item_func_collectmap02(void) */

void item_func_collectmap02(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,1);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,1);
  dSv_player_map_c::offCompleteMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,1)
  ;
  return;
}


/* __stdcall item_func_collectmap01(void) */

void item_func_collectmap01(void)

{
  dSv_player_map_c::onGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0);
  dSv_player_map_c::offOpenMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0);
  dSv_player_map_c::offCompleteMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0)
  ;
  return;
}


/* __stdcall item_func_noentry(void) */

void item_func_noentry(void)

{
  return;
}


/* __stdcall item_getcheck_func_heart(void) */

undefined4 item_getcheck_func_heart(void)

{
  return 0xffffffff;
}


/* __stdcall item_getcheck_func_green_rupee(void) */

undefined4 item_getcheck_func_green_rupee(void)

{
  return 0xffffffff;
}


/* __stdcall item_getcheck_func_blue_rupee(void) */

undefined4 item_getcheck_func_blue_rupee(void)

{
  return 0xffffffff;
}


/* __stdcall item_getcheck_func_white_rupee(void) */

undefined4 item_getcheck_func_white_rupee(void)

{
  return 0xffffffff;
}


/* __stdcall item_getcheck_func_red_rupee(void) */

undefined4 item_getcheck_func_red_rupee(void)

{
  return 0xffffffff;
}


/* __stdcall item_getcheck_func_purple_rupee(void) */

undefined4 item_getcheck_func_purple_rupee(void)

{
  return 0xffffffff;
}


/* __stdcall item_getcheck_func_silver_rupee(void) */

undefined4 item_getcheck_func_silver_rupee(void)

{
  return 0xffffffff;
}


/* __stdcall item_getcheck_func_kakera_heart(void) */

undefined4 item_getcheck_func_kakera_heart(void)

{
  return 0xffffffff;
}


/* __stdcall item_getcheck_func_utuwa_heart(void) */

undefined4 item_getcheck_func_utuwa_heart(void)

{
  return 0xffffffff;
}


/* __stdcall item_getcheck_func_s_magic(void) */

undefined4 item_getcheck_func_s_magic(void)

{
  return 0xffffffff;
}


/* __stdcall item_getcheck_func_l_magic(void) */

undefined4 item_getcheck_func_l_magic(void)

{
  return 0xffffffff;
}


/* __stdcall item_getcheck_func_bomb_5(void) */

void item_getcheck_func_bomb_5(void)

{
  dSv_player_get_item_c::isItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,0xd,0);
  return;
}


/* __stdcall item_getcheck_func_bomb_10(void) */

void item_getcheck_func_bomb_10(void)

{
  dSv_player_get_item_c::isItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,0xd,0);
  return;
}


/* __stdcall item_getcheck_func_bomb_20(void) */

void item_getcheck_func_bomb_20(void)

{
  dSv_player_get_item_c::isItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,0xd,0);
  return;
}


/* __stdcall item_getcheck_func_bomb_30(void) */

void item_getcheck_func_bomb_30(void)

{
  dSv_player_get_item_c::isItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,0xd,0);
  return;
}


/* __stdcall item_getcheck_func_noentry(void) */

undefined4 item_getcheck_func_noentry(void)

{
  return 0xffffffff;
}


/* __stdcall item_getcheck_func_arrow_10(void) */

void item_getcheck_func_arrow_10(void)

{
  dSv_player_get_item_c::isItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,0xc,0);
  return;
}


/* __stdcall item_getcheck_func_arrow_20(void) */

void item_getcheck_func_arrow_20(void)

{
  dSv_player_get_item_c::isItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,0xc,0);
  return;
}


/* __stdcall item_getcheck_func_arrow_30(void) */

void item_getcheck_func_arrow_30(void)

{
  dSv_player_get_item_c::isItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,0xc,0);
  return;
}


/* __stdcall item_getcheck_func_small_key(void) */

undefined4 item_getcheck_func_small_key(void)

{
  return 0xffffffff;
}


/* __stdcall item_getcheck_func_recover_faily(void) */

undefined4 item_getcheck_func_recover_faily(void)

{
  return 0xffffffff;
}


/* __stdcall item_getcheck_func_triple_heart(void) */

undefined4 item_getcheck_func_triple_heart(void)

{
  return 0xffffffff;
}


/* __stdcall item_getcheck_func_pendant(void) */

void item_getcheck_func_pendant(void)

{
  dSv_player_get_bag_item_c::isBeast
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,7);
  return;
}


/* __stdcall item_getcheck_func_telescope(void) */

void item_getcheck_func_telescope(void)

{
  dSv_player_get_item_c::isItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,0,0);
  return;
}


/* __stdcall item_getcheck_func_tncl_whitsl(void) */

void item_getcheck_func_tncl_whitsl(void)

{
  dSv_player_get_item_c::isItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,7,0);
  return;
}


/* __stdcall item_getcheck_func_wind_tact(void) */

void item_getcheck_func_wind_tact(void)

{
  dSv_player_get_item_c::isItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,2,0);
  return;
}


/* __stdcall item_getcheck_func_camera(void) */

void item_getcheck_func_camera(void)

{
  dSv_player_get_item_c::isItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,8,0);
  return;
}


/* __stdcall item_getcheck_func_emono_bag(void) */

void item_getcheck_func_emono_bag(void)

{
  dSv_player_get_item_c::isItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,4,0);
  return;
}


/* __stdcall item_getcheck_func_rope(void) */

void item_getcheck_func_rope(void)

{
  dSv_player_get_item_c::isItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,3,0);
  return;
}


/* __stdcall item_getcheck_func_camera2(void) */

void item_getcheck_func_camera2(void)

{
  dSv_player_get_item_c::isItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,8,1);
  return;
}


/* __stdcall item_getcheck_func_bow(void) */

void item_getcheck_func_bow(void)

{
  dSv_player_get_item_c::isItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,0xc,0);
  return;
}


/* __stdcall item_getcheck_func_pwr_groove(void) */

void item_getcheck_func_pwr_groove(void)

{
  dSv_player_collect_c::isCollect
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,2,0);
  return;
}


/* __stdcall item_getcheck_func_hvy_boots(void) */

void item_getcheck_func_hvy_boots(void)

{
  dSv_player_get_item_c::isItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,9,0);
  return;
}


/* __stdcall item_getcheck_func_drgn_shield(void) */

void item_getcheck_func_drgn_shield(void)

{
  dSv_player_get_item_c::isItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,10,0);
  return;
}


/* __stdcall item_getcheck_func_water_boots(void) */

undefined4 item_getcheck_func_water_boots(void)

{
  return 0xffffffff;
}


/* __stdcall item_getcheck_func_esa_bag(void) */

void item_getcheck_func_esa_bag(void)

{
  dSv_player_get_item_c::isItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,0xb,0);
  return;
}


/* __stdcall item_getcheck_func_boomerang(void) */

void item_getcheck_func_boomerang(void)

{
  dSv_player_get_item_c::isItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,5,0);
  return;
}


/* __stdcall item_getcheck_func_bare_hand(void) */

undefined4 item_getcheck_func_bare_hand(void)

{
  return 0xffffffff;
}


/* __stdcall item_getcheck_func_hookshot(void) */

void item_getcheck_func_hookshot(void)

{
  dSv_player_get_item_c::isItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,0x13,0);
  return;
}


/* __stdcall item_getcheck_func_warasibe_bag(void) */

void item_getcheck_func_warasibe_bag(void)

{
  dSv_player_get_item_c::isItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,0x12,0);
  return;
}


/* __stdcall item_getcheck_func_bomb_bag(void) */

undefined4 item_getcheck_func_bomb_bag(void)

{
  return 0xffffffff;
}


/* __stdcall item_getcheck_func_hummer(void) */

void item_getcheck_func_hummer(void)

{
  dSv_player_get_item_c::isItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,0x14,0);
  return;
}


/* __stdcall item_getcheck_func_deku_leaf(void) */

void item_getcheck_func_deku_leaf(void)

{
  dSv_player_get_item_c::isItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,6,0);
  return;
}


/* __stdcall item_getcheck_func_magic_arrow(void) */

void item_getcheck_func_magic_arrow(void)

{
  dSv_player_get_item_c::isItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,0xc,1);
  return;
}


/* __stdcall item_getcheck_func_light_arrow(void) */

void item_getcheck_func_light_arrow(void)

{
  dSv_player_get_item_c::isItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,0xc,2);
  return;
}


/* __stdcall item_getcheck_func_sword(void) */

void item_getcheck_func_sword(void)

{
  dSv_player_collect_c::isCollect
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,0,0);
  return;
}


/* __stdcall item_getcheck_func_master_sword(void) */

void item_getcheck_func_master_sword(void)

{
  dSv_player_collect_c::isCollect
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,0,1);
  return;
}


/* __stdcall item_getcheck_func_lv3_sword(void) */

void item_getcheck_func_lv3_sword(void)

{
  dSv_player_collect_c::isCollect
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,0,2);
  return;
}


/* __stdcall item_getcheck_func_shield(void) */

void item_getcheck_func_shield(void)

{
  dSv_player_collect_c::isCollect
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,1,0);
  return;
}


/* __stdcall item_getcheck_func_mirror_shield(void) */

void item_getcheck_func_mirror_shield(void)

{
  dSv_player_collect_c::isCollect
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,1,1);
  return;
}


/* __stdcall item_getcheck_func_master_sword_ex(void) */

void item_getcheck_func_master_sword_ex(void)

{
  dSv_player_collect_c::isCollect
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,0,3);
  return;
}


/* __stdcall item_getcheck_func_pirates_omamori(void) */

void item_getcheck_func_pirates_omamori(void)

{
  dSv_player_collect_c::isCollect
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,3,0);
  return;
}


/* __stdcall item_getcheck_func_heros_omamori(void) */

void item_getcheck_func_heros_omamori(void)

{
  dSv_player_collect_c::isCollect
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,4,0);
  return;
}


/* __stdcall item_getcheck_func_grass_ball(void) */

undefined4 item_getcheck_func_grass_ball(void)

{
  return 0xffffffff;
}


/* __stdcall item_getcheck_func_skull_necklace(void) */

void item_getcheck_func_skull_necklace(void)

{
  dSv_player_get_bag_item_c::isBeast
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,0);
  return;
}


/* __stdcall item_getcheck_func_bokobaba_seed(void) */

void item_getcheck_func_bokobaba_seed(void)

{
  dSv_player_get_bag_item_c::isBeast
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,1);
  return;
}


/* __stdcall item_getcheck_func_golden_feather(void) */

void item_getcheck_func_golden_feather(void)

{
  dSv_player_get_bag_item_c::isBeast
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,2);
  return;
}


/* __stdcall item_getcheck_func_boko_belt(void) */

void item_getcheck_func_boko_belt(void)

{
  dSv_player_get_bag_item_c::isBeast
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,3);
  return;
}


/* __stdcall item_getcheck_func_red_jerry(void) */

void item_getcheck_func_red_jerry(void)

{
  dSv_player_get_bag_item_c::isBeast
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,4);
  return;
}


/* __stdcall item_getcheck_func_green_jerry(void) */

void item_getcheck_func_green_jerry(void)

{
  dSv_player_get_bag_item_c::isBeast
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,5);
  return;
}


/* __stdcall item_getcheck_func_blue_jerry(void) */

void item_getcheck_func_blue_jerry(void)

{
  dSv_player_get_bag_item_c::isBeast
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,6);
  return;
}


/* __stdcall item_getcheck_func_map(void) */

void item_getcheck_func_map(void)

{
  dSv_memBit_c::isDungeonItem((dSv_memBit_c *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMemory,0)
  ;
  return;
}


/* __stdcall item_getcheck_func_compass(void) */

undefined4 item_getcheck_func_compass(void)

{
  return 0xffffffff;
}


/* __stdcall item_getcheck_func_boss_key(void) */

void item_getcheck_func_boss_key(void)

{
  dSv_memBit_c::isDungeonItem((dSv_memBit_c *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mMemory,2)
  ;
  return;
}


/* __stdcall item_getcheck_func_empty_bship(void) */

void item_getcheck_func_empty_bship(void)

{
  dSv_player_get_item_c::isBottleItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,'O');
  return;
}


/* __stdcall item_getcheck_func_empty_bottle(void) */

void item_getcheck_func_empty_bottle(void)

{
  dSv_player_get_item_c::isBottleItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,'P');
  return;
}


/* __stdcall item_getcheck_func_red_bottle(void) */

void item_getcheck_func_red_bottle(void)

{
  dSv_player_get_item_c::isBottleItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,'Q');
  return;
}


/* __stdcall item_getcheck_func_green_bottle(void) */

void item_getcheck_func_green_bottle(void)

{
  dSv_player_get_item_c::isBottleItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,'R');
  return;
}


/* __stdcall item_getcheck_func_blue_bottle(void) */

void item_getcheck_func_blue_bottle(void)

{
  dSv_player_get_item_c::isBottleItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,'S');
  return;
}


/* __stdcall item_getcheck_func_bottleship(void) */

void item_getcheck_func_bottleship(void)

{
  dSv_player_get_item_c::isBottleItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,'T');
  return;
}


/* __stdcall item_getcheck_func_bin_in_bottleship(void) */

void item_getcheck_func_bin_in_bottleship(void)

{
  dSv_player_get_item_c::isBottleItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,'U');
  return;
}


/* __stdcall item_getcheck_func_bin_in_water(void) */

void item_getcheck_func_bin_in_water(void)

{
  dSv_player_get_item_c::isBottleItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,'V');
  return;
}


/* __stdcall item_getcheck_func_bin(void) */

void item_getcheck_func_bin(void)

{
  dSv_player_get_item_c::isBottleItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,'W');
  return;
}


/* __stdcall item_getcheck_func_triforce1(void) */

void item_getcheck_func_triforce1(void)

{
  dSv_player_collect_c::isTriforce
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\0');
  return;
}


/* __stdcall item_getcheck_func_triforce2(void) */

void item_getcheck_func_triforce2(void)

{
  dSv_player_collect_c::isTriforce
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x01');
  return;
}


/* __stdcall item_getcheck_func_triforce3(void) */

void item_getcheck_func_triforce3(void)

{
  dSv_player_collect_c::isTriforce
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x02');
  return;
}


/* __stdcall item_getcheck_func_triforce4(void) */

void item_getcheck_func_triforce4(void)

{
  dSv_player_collect_c::isTriforce
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x03');
  return;
}


/* __stdcall item_getcheck_func_triforce5(void) */

void item_getcheck_func_triforce5(void)

{
  dSv_player_collect_c::isTriforce
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x04');
  return;
}


/* __stdcall item_getcheck_func_triforce6(void) */

void item_getcheck_func_triforce6(void)

{
  dSv_player_collect_c::isTriforce
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x05');
  return;
}


/* __stdcall item_getcheck_func_triforce7(void) */

void item_getcheck_func_triforce7(void)

{
  dSv_player_collect_c::isTriforce
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x06');
  return;
}


/* __stdcall item_getcheck_func_triforce8(void) */

void item_getcheck_func_triforce8(void)

{
  dSv_player_collect_c::isTriforce
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\a');
  return;
}


/* __stdcall item_getcheck_func_pearl1(void) */

void item_getcheck_func_pearl1(void)

{
  dSv_player_collect_c::isSymbol
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\0');
  return;
}


/* __stdcall item_getcheck_func_pearl2(void) */

void item_getcheck_func_pearl2(void)

{
  dSv_player_collect_c::isSymbol
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x01');
  return;
}


/* __stdcall item_getcheck_func_pearl3(void) */

void item_getcheck_func_pearl3(void)

{
  dSv_player_collect_c::isSymbol
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x02');
  return;
}


/* __stdcall item_getcheck_func_tact_song1(void) */

void item_getcheck_func_tact_song1(void)

{
  dSv_player_collect_c::isTact
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\0');
  return;
}


/* __stdcall item_getcheck_func_tact_song2(void) */

void item_getcheck_func_tact_song2(void)

{
  dSv_player_collect_c::isTact
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x01');
  return;
}


/* __stdcall item_getcheck_func_tact_song3(void) */

void item_getcheck_func_tact_song3(void)

{
  dSv_player_collect_c::isTact
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x02');
  return;
}


/* __stdcall item_getcheck_func_tact_song4(void) */

void item_getcheck_func_tact_song4(void)

{
  dSv_player_collect_c::isTact
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x03');
  return;
}


/* __stdcall item_getcheck_func_tact_song5(void) */

void item_getcheck_func_tact_song5(void)

{
  dSv_player_collect_c::isTact
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x04');
  return;
}


/* __stdcall item_getcheck_func_tact_song6(void) */

void item_getcheck_func_tact_song6(void)

{
  dSv_player_collect_c::isTact
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect,'\x05');
  return;
}


/* __stdcall item_getcheck_func_normal_sail(void) */

void item_getcheck_func_normal_sail(void)

{
  dSv_player_get_item_c::isItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,1,0);
  return;
}


/* __stdcall item_getcheck_func_zora_sail(void) */

undefined4 item_getcheck_func_zora_sail(void)

{
  return 0xffffffff;
}


/* __stdcall item_getcheck_func_tincle_sail(void) */

undefined4 item_getcheck_func_tincle_sail(void)

{
  return 0xffffffff;
}


/* __stdcall item_getcheck_func_sail(void) */

undefined4 item_getcheck_func_sail(void)

{
  return 0xffffffff;
}


/* __stdcall item_getcheck_func_bird_esa_5(void) */

void item_getcheck_func_bird_esa_5(void)

{
  dSv_player_get_bag_item_c::isBait
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,0);
  return;
}


/* __stdcall item_getcheck_func_animal_esa(void) */

void item_getcheck_func_animal_esa(void)

{
  dSv_player_get_bag_item_c::isBait
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,1);
  return;
}


/* __stdcall item_getcheck_func_esa1(void) */

void item_getcheck_func_esa1(void)

{
  dSv_player_get_bag_item_c::isBait
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,2);
  return;
}


/* __stdcall item_getcheck_func_esa2(void) */

void item_getcheck_func_esa2(void)

{
  dSv_player_get_bag_item_c::isBait
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,3);
  return;
}


/* __stdcall item_getcheck_func_esa3(void) */

void item_getcheck_func_esa3(void)

{
  dSv_player_get_bag_item_c::isBait
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,4);
  return;
}


/* __stdcall item_getcheck_func_esa4(void) */

void item_getcheck_func_esa4(void)

{
  dSv_player_get_bag_item_c::isBait
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,5);
  return;
}


/* __stdcall item_getcheck_func_esa5(void) */

void item_getcheck_func_esa5(void)

{
  dSv_player_get_bag_item_c::isBait
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,6);
  return;
}


/* __stdcall item_getcheck_func_magic_bean(void) */

undefined4 item_getcheck_func_magic_bean(void)

{
  return 0xffffffff;
}


/* __stdcall item_getcheck_func_bird_esa_10(void) */

void item_getcheck_func_bird_esa_10(void)

{
  dSv_player_get_bag_item_c::isBait
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,7);
  return;
}


/* __stdcall item_getcheck_func_flower_1(void) */

void item_getcheck_func_flower_1(void)

{
  dSv_player_get_bag_item_c::isReserve
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,'\0');
  return;
}


/* __stdcall item_getcheck_func_flower_2(void) */

void item_getcheck_func_flower_2(void)

{
  dSv_player_get_bag_item_c::isReserve
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,'\x01');
  return;
}


/* __stdcall item_getcheck_func_flower_3(void) */

void item_getcheck_func_flower_3(void)

{
  dSv_player_get_bag_item_c::isReserve
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,'\x02');
  return;
}


/* __stdcall item_getcheck_func_heros_flag(void) */

void item_getcheck_func_heros_flag(void)

{
  dSv_player_get_bag_item_c::isReserve
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,'\x03');
  return;
}


/* __stdcall item_getcheck_func_tairyo_flag(void) */

void item_getcheck_func_tairyo_flag(void)

{
  dSv_player_get_bag_item_c::isReserve
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,'\x04');
  return;
}


/* __stdcall item_getcheck_func_sales_flag(void) */

void item_getcheck_func_sales_flag(void)

{
  dSv_player_get_bag_item_c::isReserve
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,'\x05');
  return;
}


/* __stdcall item_getcheck_func_wind_flag(void) */

void item_getcheck_func_wind_flag(void)

{
  dSv_player_get_bag_item_c::isReserve
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,'\x06');
  return;
}


/* __stdcall item_getcheck_func_red_flag(void) */

void item_getcheck_func_red_flag(void)

{
  dSv_player_get_bag_item_c::isReserve
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,'\a');
  return;
}


/* __stdcall item_getcheck_func_fossil_head(void) */

void item_getcheck_func_fossil_head(void)

{
  dSv_player_get_bag_item_c::isReserve
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,'\b');
  return;
}


/* __stdcall item_getcheck_func_water_statue(void) */

void item_getcheck_func_water_statue(void)

{
  dSv_player_get_bag_item_c::isReserve
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,'\t');
  return;
}


/* __stdcall item_getcheck_func_postman_statue(void) */

void item_getcheck_func_postman_statue(void)

{
  dSv_player_get_bag_item_c::isReserve
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,'\n');
  return;
}


/* __stdcall item_getcheck_func_president_statue(void) */

void item_getcheck_func_president_statue(void)

{
  dSv_player_get_bag_item_c::isReserve
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,'\v');
  return;
}


/* __stdcall item_getcheck_func_letter00(void) */

void item_getcheck_func_letter00(void)

{
  dSv_player_get_bag_item_c::isReserve
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,'\f');
  return;
}


/* __stdcall item_getcheck_func_magic_seed(void) */

void item_getcheck_func_magic_seed(void)

{
  dSv_player_get_bag_item_c::isReserve
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,'\r');
  return;
}


/* __stdcall item_getcheck_func_magys_letter(void) */

void item_getcheck_func_magys_letter(void)

{
  dSv_player_get_bag_item_c::isReserve
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,'\x0e');
  return;
}


/* __stdcall item_getcheck_func_mo_letter(void) */

void item_getcheck_func_mo_letter(void)

{
  dSv_player_get_bag_item_c::isReserve
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,'\x0f');
  return;
}


/* __stdcall item_getcheck_func_cottage_paper(void) */

void item_getcheck_func_cottage_paper(void)

{
  dSv_player_get_bag_item_c::isReserve
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,'\x10');
  return;
}


/* __stdcall item_getcheck_func_kaisen_present1(void) */

void item_getcheck_func_kaisen_present1(void)

{
  dSv_player_get_bag_item_c::isReserve
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,'\x11');
  return;
}


/* __stdcall item_getcheck_func_kaisen_present2(void) */

void item_getcheck_func_kaisen_present2(void)

{
  dSv_player_get_bag_item_c::isReserve
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,'\x12');
  return;
}


/* __stdcall item_getcheck_func_salvage_item1(void) */

void item_getcheck_func_salvage_item1(void)

{
  dSv_player_get_bag_item_c::isReserve
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,'\x13');
  return;
}


/* __stdcall item_getcheck_func_salvage_item2(void) */

void item_getcheck_func_salvage_item2(void)

{
  dSv_player_get_bag_item_c::isReserve
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,'\x14');
  return;
}


/* __stdcall item_getcheck_func_salvage_item3(void) */

void item_getcheck_func_salvage_item3(void)

{
  dSv_player_get_bag_item_c::isReserve
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,'\x15');
  return;
}


/* __stdcall item_getcheck_func_xxx_039(void) */

void item_getcheck_func_xxx_039(void)

{
  dSv_player_get_bag_item_c::isReserve
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,'\x16');
  return;
}


/* __stdcall item_getcheck_func_lithograph1(void) */

void item_getcheck_func_lithograph1(void)

{
  dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x3508);
  return;
}


/* __stdcall item_getcheck_func_lithograph2(void) */

void item_getcheck_func_lithograph2(void)

{
  dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x3504);
  return;
}


/* __stdcall item_getcheck_func_lithograph3(void) */

void item_getcheck_func_lithograph3(void)

{
  dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x3502);
  return;
}


/* __stdcall item_getcheck_func_lithograph4(void) */

void item_getcheck_func_lithograph4(void)

{
  dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x3501);
  return;
}


/* __stdcall item_getcheck_func_lithograph5(void) */

void item_getcheck_func_lithograph5(void)

{
  dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x3680);
  return;
}


/* __stdcall item_getcheck_func_lithograph6(void) */

void item_getcheck_func_lithograph6(void)

{
  dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x3640);
  return;
}


/* __stdcall item_getcheck_func_lithograph7(void) */

void item_getcheck_func_lithograph7(void)

{
  dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x3620);
  return;
}


/* __stdcall item_getcheck_func_lithograph8(void) */

void item_getcheck_func_lithograph8(void)

{
  dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x3610);
  return;
}


/* __stdcall item_getcheck_func_lithograph9(void) */

void item_getcheck_func_lithograph9(void)

{
  dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x3608);
  return;
}


/* __stdcall item_getcheck_func_lithograph10(void) */

void item_getcheck_func_lithograph10(void)

{
  dSv_event_c::isEventBit(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x3604);
  return;
}


/* __stdcall item_getcheck_func_lithograph11(void) */

void item_getcheck_func_lithograph11(void)

{
  dSv_player_map_c::isGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x3b);
  return;
}


/* __stdcall item_getcheck_func_lithograph12(void) */

void item_getcheck_func_lithograph12(void)

{
  dSv_player_map_c::isGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x3a);
  return;
}


/* __stdcall item_getcheck_func_lithograph13(void) */

void item_getcheck_func_lithograph13(void)

{
  dSv_player_map_c::isGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x39);
  return;
}


/* __stdcall item_getcheck_func_lithograph14(void) */

void item_getcheck_func_lithograph14(void)

{
  dSv_player_map_c::isGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x38);
  return;
}


/* __stdcall item_getcheck_func_lithograph15(void) */

void item_getcheck_func_lithograph15(void)

{
  dSv_player_map_c::isGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x37);
  return;
}


/* __stdcall item_getcheck_func_lithograph16(void) */

void item_getcheck_func_lithograph16(void)

{
  dSv_player_map_c::isGetMap(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x36);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall getRotenItemNumInBag(void) */

int getRotenItemNumInBag(void)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  
  iVar3 = 0;
  for (bVar2 = 0x8c; bVar2 < 0x98; bVar2 = bVar2 + 1) {
    uVar1 = dSv_player_bag_item_c::checkReserveItem
                      (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem,bVar2);
    iVar3 = iVar3 + (uVar1 & 0xff);
  }
  return iVar3;
}


/* __stdcall isDaizaItem(unsigned char) */

undefined4 isDaizaItem(byte param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (((byte)(param_1 + 0x74) < 0xb) || (param_1 == 0x97)) {
    uVar1 = 1;
  }
  return uVar1;
}


/* __stdcall isBomb(unsigned char) */

bool isBomb(dItem_data__ItemNo itemNo)

{
  bool bVar1;
  
  bVar1 = false;
  if (((byte)(itemNo + ~LargeMagicJar) < 3) || (itemNo == ThirtyBombs)) {
    bVar1 = true;
  }
  return bVar1;
}


/* __stdcall isArrow(unsigned char) */

bool isArrow(dItem_data__ItemNo itemNo)

{
  bool bVar1;
  
  bVar1 = false;
  if (((byte)(itemNo + Treasure_Chart_31) < 2) || (itemNo == ThirtyArrows)) {
    bVar1 = true;
  }
  return bVar1;
}


/* __stdcall isEmono(unsigned char) */

undefined4 isEmono(dItem_data__ItemNo param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (((param_1 == JoyPendant) || ((byte)(param_1 + 0xbb) < 6)) || (param_1 == BlueChuJelly)) {
    uVar1 = 1;
  }
  return uVar1;
}


/* __stdcall isEsa(unsigned char) */

undefined4 isEsa(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (((byte)(param_1 + 0x7eU) < 2) || (param_1 == -0x77)) {
    uVar1 = 1;
  }
  return uVar1;
}


/* __stdcall isRupee(unsigned char) */

undefined4 isRupee(byte param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (((byte)(param_1 - 1) < 6) || (param_1 == 0xf)) {
    uVar1 = 1;
  }
  return uVar1;
}


/* __stdcall isLimitedItem(unsigned char) */

uint isLimitedItem(dItem_data__ItemNo param_1)

{
  return (uint)(param_1 == BlueChuJelly);
}


/* __stdcall isNonSavedEmono(unsigned char) */

undefined4 isNonSavedEmono(dItem_data__ItemNo param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (((param_1 == JoyPendant) || ((byte)(param_1 + 0xbb) < 5)) || (param_1 == GreenChuJelly)) {
    uVar1 = 1;
  }
  return uVar1;
}


/* __stdcall isUseClothPacket(unsigned char) */

undefined4 isUseClothPacket(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (((byte)(param_1 + 0x71U) < 3) || (param_1 == -0x6d)) {
    uVar1 = 1;
  }
  return uVar1;
}


/* __stdcall isTriforce(unsigned char) */

undefined4 isTriforce(char param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (((byte)(param_1 + 0x9fU) < 7) || (param_1 == 'h')) {
    uVar1 = 1;
  }
  return uVar1;
}


/* __stdcall isHeart(unsigned char) */

bool isHeart(dItem_data__ItemNo itemNo)

{
  bool bVar1;
  
  bVar1 = false;
  if ((itemNo == Heart) || (itemNo == triple_heart)) {
    bVar1 = true;
  }
  return bVar1;
}


/* __stdcall getItemNoByLife(unsigned char) */

uint getItemNoByLife(dItem_data__ItemNo param_1)

{
  undefined3 in_register_0000000c;
  uint uVar1;
  
  uVar1 = CONCAT31(in_register_0000000c,param_1);
  if ((((uint)(ushort)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mCurrHp *
       100) / ((ushort)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mMaxHp &
              0xfc) & 0xff) != 100) {
    return uVar1;
  }
  if (param_1 == Heart) {
    uVar1 = 1;
  }
  if ((uVar1 & 0xff) != 0x1e) {
    return uVar1;
  }
  return 3;
}


/* __stdcall check_itemno(int) */

uint check_itemno(uint param_1)

{
  dItem_data__ItemNo itemNo;
  uint uVar1;
  bool bVar3;
  int iVar2;
  
  if ((d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.mMaxMagic == 0) &&
     ((param_1 == 9 || (param_1 == 10)))) {
    param_1 = 1;
  }
  else {
    uVar1 = dSv_player_get_item_c::isItem
                      (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,0xc,0);
    itemNo = (dItem_data__ItemNo)param_1;
    if ((uVar1 == 0) &&
       (((uVar1 = dSv_player_get_item_c::isItem
                            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,0xc,
                             1), uVar1 == 0 &&
         (uVar1 = dSv_player_get_item_c::isItem
                            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,0xc,
                             2), uVar1 == 0)) && (bVar3 = isArrow(itemNo), bVar3 != false)))) {
      param_1 = 1;
    }
    else {
      uVar1 = dSv_player_get_item_c::isItem
                        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,0xd,0);
      if ((uVar1 == 0) && (bVar3 = isBomb(itemNo), bVar3 != false)) {
        param_1 = 1;
      }
      else {
        iVar2 = checkItemGet(0x2c,1);
        if ((iVar2 == 0) && (iVar2 = isEsa(param_1 & 0xff), iVar2 != 0)) {
          param_1 = 1;
        }
        else {
          iVar2 = checkItemGet(0x24,1);
          if ((iVar2 == 0) && (iVar2 = isEmono(itemNo), iVar2 != 0)) {
            param_1 = 1;
          }
          else {
            if (param_1 == 0x1e) {
              param_1 = 0;
            }
            param_1 = param_1 & 0xff;
          }
        }
      }
    }
  }
  return param_1;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __stdcall getEmonoItemFromLifeBallTable(unsigned short) */

dItem_data__ItemNo getEmonoItemFromLifeBallTable(uint param_1)

{
  dItem_data__ItemNo dVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  dItem_data__ItemNo *pdVar5;
  dItem_data__ItemNo local_28 [4];
  undefined local_24;
  undefined local_23;
  undefined local_22;
  undefined local_21;
  undefined local_20;
  undefined local_1f;
  undefined local_1e;
  undefined local_1d;
  undefined local_1c;
  undefined local_1b;
  undefined local_1a;
  undefined local_19;
  
  param_1 = param_1 & 0xffff;
  uVar2 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_ITEM0,param_1);
  local_28[0] = (dItem_data__ItemNo)uVar2;
  uVar2 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_ITEM1,param_1);
  local_28[1] = (dItem_data__ItemNo)uVar2;
  uVar2 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_ITEM2,param_1);
  local_28[2] = (dItem_data__ItemNo)uVar2;
  uVar2 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_ITEM3,param_1);
  local_28[3] = (dItem_data__ItemNo)uVar2;
  uVar2 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_ITEM4,param_1);
  local_24 = (undefined)uVar2;
  uVar2 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_ITEM5,param_1);
  local_23 = (undefined)uVar2;
  uVar2 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_ITEM6,param_1);
  local_22 = (undefined)uVar2;
  uVar2 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_ITEM7,param_1);
  local_21 = (char)uVar2;
  iVar4 = 0;
  pdVar5 = local_28;
  do {
    dVar1 = *pdVar5;
    iVar3 = isEmono(dVar1);
    if (iVar3 != 0) {
      return dVar1;
    }
    iVar4 = iVar4 + 1;
    pdVar5 = pdVar5 + 1;
  } while (iVar4 < 8);
  uVar2 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_N_ITEM0,param_1)
  ;
  local_28[0] = (dItem_data__ItemNo)uVar2;
  uVar2 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_N_ITEM1,param_1)
  ;
  local_28[1] = (dItem_data__ItemNo)uVar2;
  uVar2 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_N_ITEM2,param_1)
  ;
  local_28[2] = (dItem_data__ItemNo)uVar2;
  uVar2 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_N_ITEM3,param_1)
  ;
  local_28[3] = (dItem_data__ItemNo)uVar2;
  uVar2 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_N_ITEM4,param_1)
  ;
  local_24 = (undefined)uVar2;
  uVar2 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_N_ITEM5,param_1)
  ;
  local_23 = (undefined)uVar2;
  uVar2 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_N_ITEM6,param_1)
  ;
  local_22 = (undefined)uVar2;
  uVar2 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_N_ITEM7,param_1)
  ;
  local_21 = (undefined)uVar2;
  uVar2 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_N_ITEM8,param_1)
  ;
  local_20 = (undefined)uVar2;
  uVar2 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_N_ITEM9,param_1)
  ;
  local_1f = (undefined)uVar2;
  uVar2 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_N_ITEM10,param_1
                     );
  local_1e = (undefined)uVar2;
  uVar2 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_N_ITEM11,param_1
                     );
  local_1d = (undefined)uVar2;
  uVar2 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_N_ITEM12,param_1
                     );
  local_1c = (undefined)uVar2;
  uVar2 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_N_ITEM13,param_1
                     );
  local_1b = (undefined)uVar2;
  uVar2 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_N_ITEM14,param_1
                     );
  local_1a = (undefined)uVar2;
  uVar2 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_N_ITEM15,param_1
                     );
  local_19 = (char)uVar2;
  iVar4 = 0;
  pdVar5 = local_28;
  do {
    dVar1 = *pdVar5;
    iVar3 = isEmono(dVar1);
    if (iVar3 != 0) {
      return dVar1;
    }
    iVar4 = iVar4 + 1;
    pdVar5 = pdVar5 + 1;
  } while (iVar4 < 0x10);
  return InvalidItem;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __stdcall getItemFromLifeBallTableWithoutEmono(unsigned short) */

dItem_data__ItemNo getItemFromLifeBallTableWithoutEmono(uint param_1)

{
  dItem_data__ItemNo dVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  dItem_data__ItemNo *pItemTbl;
  float fVar5;
  byte itemTbl [16];
  
  param_1 = param_1 & 0xffff;
  uVar2 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_N_ITEM0,param_1)
  ;
  itemTbl[0] = (byte)uVar2;
  uVar2 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_N_ITEM1,param_1)
  ;
  itemTbl[1] = (byte)uVar2;
  uVar2 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_N_ITEM2,param_1)
  ;
  itemTbl[2] = (byte)uVar2;
  uVar2 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_N_ITEM3,param_1)
  ;
  itemTbl[3] = (byte)uVar2;
  uVar2 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_N_ITEM4,param_1)
  ;
  itemTbl[4] = (byte)uVar2;
  uVar2 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_N_ITEM5,param_1)
  ;
  itemTbl[5] = (byte)uVar2;
  uVar2 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_N_ITEM6,param_1)
  ;
  itemTbl[6] = (byte)uVar2;
  uVar2 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_N_ITEM7,param_1)
  ;
  itemTbl[7] = (byte)uVar2;
  uVar2 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_N_ITEM8,param_1)
  ;
  itemTbl[8] = (byte)uVar2;
  uVar2 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_N_ITEM9,param_1)
  ;
  itemTbl[9] = (byte)uVar2;
  uVar2 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_N_ITEM10,param_1
                     );
  itemTbl[10] = (byte)uVar2;
  uVar2 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_N_ITEM11,param_1
                     );
  itemTbl[11] = (byte)uVar2;
  uVar2 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_N_ITEM12,param_1
                     );
  itemTbl[12] = (byte)uVar2;
  uVar2 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_N_ITEM13,param_1
                     );
  itemTbl[13] = (byte)uVar2;
  uVar2 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_N_ITEM14,param_1
                     );
  itemTbl[14] = (byte)uVar2;
  uVar2 = cDT::GetInf(&d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.parent,
                      d_com_inf_game::g_dComIfG_gameInfo.mPlay.mADM.mCharTbl.mIndex_N_ITEM15,param_1
                     );
  itemTbl[15] = (byte)uVar2;
  iVar4 = 0;
  while( true ) {
    fVar5 = SComponent::cM_rndF(15_999);
    dVar1 = itemTbl[(int)fVar5];
    iVar3 = isEmono(dVar1);
    if ((iVar3 == 0) && (dVar1 != InvalidItem)) break;
    iVar4 = iVar4 + 1;
    if (7 < iVar4) {
      iVar4 = 0;
      pItemTbl = itemTbl;
      while( true ) {
        dVar1 = *pItemTbl;
        iVar3 = isEmono(dVar1);
        if ((iVar3 == 0) && (dVar1 != InvalidItem)) break;
        iVar4 = iVar4 + 1;
        pItemTbl = pItemTbl + 1;
        if (0xf < iVar4) {
          return InvalidItem;
        }
      }
      return dVar1;
    }
  }
  return dVar1;
}

