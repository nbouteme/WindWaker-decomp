#include <d_save.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <Runtime.PPCEABI.H/runtime.h>
#include <JUtility/JUTAssert.h>
#include <m_Do_printf.h>
#include <d_save.h>
#include <SComponent/c_math.h>
#include <os/OSRtc.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <d_save_init.h>
#include <m_Do_mtx.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <SComponent/c_lib.h>
#include <JKernel/JKRHeap.h>
#include <os/OSTime.h>
#include <MSL_C.PPCEABI.bare.H/printf.h>
#include <dSv_zone_c.h>
#include <dSv_memBit_c.h>
#include <dSv_player_get_item_c.h>
#include <dSv_player_map_c.h>
#include <dSv_event_c.h>
#include <dSv_player_bag_item_c.h>
#include <dSv_reserve_c.h>
#include <dSv_player_item_record_c.h>
#include <dSv_save_c.h>
#include <dSv_player_status_b_c.h>
#include <dSv_player_status_c_c.h>
#include <dSv_turnRestart_c.h>
#include <dSv_player_bag_item_record_c.h>
#include <dSv_player_status_a_c.h>
#include <dSv_player_c.h>
#include <dSv_player_item_c.h>
#include <dSv_info_c.h>
#include <dSv_player_return_place_c.h>
#include <dSv_player_priest_c.h>
#include <dSv_zoneActor_c.h>
#include <dSv_ocean_c.h>
#include <dSv_player_collect_c.h>
#include <dSv_restart_c.h>
#include <dSv_player_item_max_c.h>
#include <dSv_player_info_c.h>
#include <dSv_memory_c.h>
#include <dSv_player_get_bag_item_c.h>
#include <dSv_danBit_c.h>
#include <dSv_player_config_c.h>
#include <dSv_zoneBit_c.h>


namespace d_save {
struct cXyz l_offsetPos$7549;
byte init$7551;
}

/* WARNING: Type propagation algorithm not settling */
/* __thiscall dSv_player_status_a_c::init(void) */

int __thiscall dSv_player_status_a_c::init(dSv_player_status_a_c *this)

{
  byte bVar1;
  int iVar2;
  dItem_data__ItemNo dVar3;
  uint uVar4;
  byte *pbVar5;
  int iVar6;
  
  this->mMaxHp = 0xc;
  this->mCurrHp = 0xc;
  *(undefined *)&this->field_0x8 = 0;
  iVar2 = 0;
  iVar6 = 5;
  do {
    dVar3 = InvalidItem;
    this->mInventorySlotIndexOnButton[iVar2] = -1;
    pbVar5 = (byte *)(d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                      mInventorySlotIndexOnButton + iVar2);
    uVar4 = (uint)(byte)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                        mInventorySlotIndexOnButton[iVar2];
    if (uVar4 == 0xff) {
      d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[iVar2] = InvalidItem;
    }
    else {
      if (uVar4 < 0x15) {
        dVar3 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
                mStageName[uVar4];
      }
      else {
        if (0x17 < uVar4) {
          if (uVar4 < 0x20) {
            dVar3 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                    [uVar4 + 0xd];
          }
          else {
            if (0x23 < uVar4) {
              if (uVar4 < 0x2c) {
                dVar3 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                        [uVar4 + 9];
              }
              else {
                if ((0x2f < uVar4) && (uVar4 < 0x38)) {
                  dVar3 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                          [uVar4 + 5];
                }
              }
            }
          }
        }
      }
      d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[iVar2] = dVar3;
      uVar4 = (uint)*pbVar5;
      if (uVar4 < 0x15) {
        bVar1 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
                mStageName[uVar4];
      }
      else {
        if (uVar4 < 0x18) {
          bVar1 = 0xff;
        }
        else {
          if (uVar4 < 0x20) {
            bVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                    [uVar4 + 0xd];
          }
          else {
            if (uVar4 < 0x24) {
              bVar1 = 0xff;
            }
            else {
              if (uVar4 < 0x2c) {
                bVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                        [uVar4 + 9];
              }
              else {
                if (uVar4 < 0x30) {
                  bVar1 = 0xff;
                }
                else {
                  if (uVar4 < 0x38) {
                    bVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                            [uVar4 + 5];
                  }
                  else {
                    bVar1 = 0xff;
                  }
                }
              }
            }
          }
        }
      }
      if (bVar1 == 0xff) {
        *pbVar5 = 0xff;
      }
    }
    iVar2 = iVar2 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  iVar2 = 0;
  iVar6 = 4;
  do {
    this->mInventorySlotIndexOnButton[iVar2 + 5] = -1;
    iVar2 = iVar2 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  this->mCurrRupees = 0;
  this->mCurrentWalletIndex = 0;
  this->mMaxMagic = 0;
  this->mCurrMagic = 0;
  *(undefined *)&this->field_0x15 = 0;
  *(undefined2 *)&this->field_0x6 = 0;
  *(undefined *)&this->field_0x16 = 0;
  return (int)this;
}


/* __thiscall dSv_player_status_b_c::init(void) */

int __thiscall dSv_player_status_b_c::init(dSv_player_status_b_c *this)

{
  this->mTactWindAngleX = -1;
  this->mTactWindAngleY = -1;
  this->mCurTime = d_save::_4194;
  this->mDayOfWeek = 0;
  *(undefined4 *)&this->field_0x4 = 0;
  *(undefined4 *)this = 0;
  *(float *)&this->field_0x8 = d_save::_4195;
  return (int)this;
}


/* __thiscall dSv_player_return_place_c::init(void) */

int __thiscall dSv_player_return_place_c::init(dSv_player_return_place_c *this)

{
  char *pcVar1;
  
  pcVar1 = MSL_C.PPCEABI.bare.H::strcpy(this->mStageName,"sea");
  this->mRoomNo = 0x2c;
  this->mStartCode = 0xce;
  return (int)pcVar1;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dSv_player_return_place_c::set(char const *,
                                             signed char,
                                             unsigned char) */

void __thiscall
dSv_player_return_place_c::set
          (dSv_player_return_place_c *this,char *param_1,char param_2,uchar param_3)

{
  size_t sVar1;
  ulong uVar2;
  
  sVar1 = MSL_C.PPCEABI.bare.H::strlen(param_1);
  if (7 < sVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_save.cpp",0xb3,"strlen(i_name) <= 7");
    m_Do_printf::OSPanic("d_save.cpp",0xb3,&DAT_8034f7fb);
  }
  MSL_C.PPCEABI.bare.H::strcpy(this->mStageName,param_1);
  this->mRoomNo = param_2;
  this->mStartCode = param_3;
  return;
}


/* __thiscall dSv_player_item_c::init(void) */

int __thiscall dSv_player_item_c::init(dSv_player_item_c *this)

{
  int iVar1;
  
  iVar1 = 0x15;
  do {
    this->mTelescopeSlot = InvalidItem;
    this = (dSv_player_item_c *)&this->field_0x1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return (int)this;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall dSv_player_item_c::setBottleItemIn(unsigned char,
                                                 unsigned char) */

void __thiscall
dSv_player_item_c::setBottleItemIn(dSv_player_item_c *this,byte param_1,byte param_2)

{
  dItem_data__ItemNo dVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  
  iVar4 = 0;
  iVar6 = 4;
  do {
    if (param_1 == *(byte *)(&this->field_0xe + iVar4)) {
      *(byte *)(&this->field_0xe + iVar4) = param_2;
      iVar6 = 0;
      iVar7 = 3;
      do {
        pbVar5 = (byte *)(d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                          mInventorySlotIndexOnButton + iVar6);
        uVar3 = (uint)(byte)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                            mInventorySlotIndexOnButton[iVar6];
        if (iVar4 + 0xeU == uVar3) {
          if (uVar3 == 0xff) {
            d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[iVar6] = InvalidItem;
          }
          else {
            if (uVar3 < 0x15) {
              dVar1 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
                      mStageName[uVar3];
            }
            else {
              if (uVar3 < 0x18) {
                dVar1 = InvalidItem;
              }
              else {
                if (uVar3 < 0x20) {
                  dVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                          [uVar3 + 0xd];
                }
                else {
                  if (uVar3 < 0x24) {
                    dVar1 = InvalidItem;
                  }
                  else {
                    if (uVar3 < 0x2c) {
                      dVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.
                              mBits[uVar3 + 9];
                    }
                    else {
                      if (uVar3 < 0x30) {
                        dVar1 = InvalidItem;
                      }
                      else {
                        if (uVar3 < 0x38) {
                          dVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.
                                  mBits[uVar3 + 5];
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
            d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[iVar6] = dVar1;
            uVar3 = (uint)*pbVar5;
            if (uVar3 < 0x15) {
              bVar2 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
                      mStageName[uVar3];
            }
            else {
              if (uVar3 < 0x18) {
                bVar2 = 0xff;
              }
              else {
                if (uVar3 < 0x20) {
                  bVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                          [uVar3 + 0xd];
                }
                else {
                  if (uVar3 < 0x24) {
                    bVar2 = 0xff;
                  }
                  else {
                    if (uVar3 < 0x2c) {
                      bVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.
                              mBits[uVar3 + 9];
                    }
                    else {
                      if (uVar3 < 0x30) {
                        bVar2 = 0xff;
                      }
                      else {
                        if (uVar3 < 0x38) {
                          bVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.
                                  mBits[uVar3 + 5];
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
        iVar6 = iVar6 + 1;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      return;
    }
    iVar4 = iVar4 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  return;
}


/* __thiscall dSv_player_item_c::setEmptyBottleItemIn(unsigned char) */

void __thiscall dSv_player_item_c::setEmptyBottleItemIn(dSv_player_item_c *this,uchar param_1)

{
  setBottleItemIn(this,0x50,param_1);
  return;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall dSv_player_item_c::setEmptyBottle(void) */

void __thiscall dSv_player_item_c::setEmptyBottle(dSv_player_item_c *this)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  iVar4 = 4;
  while( true ) {
    uVar1 = iVar3 + 0xeU & 0xff;
    if (uVar1 < 0x15) {
      bVar2 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].mStageName
              [uVar1];
    }
    else {
      if (uVar1 < 0x18) {
        bVar2 = 0xff;
      }
      else {
        if (uVar1 < 0x20) {
          bVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                  [uVar1 + 0xd];
        }
        else {
          if (uVar1 < 0x24) {
            bVar2 = 0xff;
          }
          else {
            if (uVar1 < 0x2c) {
              bVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                      [uVar1 + 9];
            }
            else {
              if (uVar1 < 0x30) {
                bVar2 = 0xff;
              }
              else {
                if (uVar1 < 0x38) {
                  bVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                          [uVar1 + 5];
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
    if (bVar2 == 0xff) break;
    iVar3 = iVar3 + 1;
    iVar4 = iVar4 + -1;
    if (iVar4 == 0) {
      return;
    }
  }
  if (uVar1 < 0x15) {
    (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].mStageName[uVar1] =
         'P';
    return;
  }
  if (uVar1 < 0x18) {
    return;
  }
  if (uVar1 < 0x20) {
    d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits[uVar1 + 0xd] = 0x50;
    return;
  }
  if (uVar1 < 0x24) {
    return;
  }
  if (uVar1 < 0x2c) {
    d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits[uVar1 + 9] = 0x50;
    return;
  }
  if (uVar1 < 0x30) {
    return;
  }
  if (0x37 < uVar1) {
    return;
  }
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits[uVar1 + 5] = 0x50;
  return;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall dSv_player_item_c::setEquipBottleItemIn(unsigned char,
                                                      unsigned char) */

void __thiscall
dSv_player_item_c::setEquipBottleItemIn(dSv_player_item_c *this,byte param_1,byte param_2)

{
  byte *pbVar1;
  uint uVar2;
  byte bVar3;
  dItem_data__ItemNo dVar4;
  uint uVar5;
  
  uVar2 = (uint)param_1;
  pbVar1 = (byte *)(d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                    mInventorySlotIndexOnButton + uVar2);
  uVar5 = (uint)*pbVar1;
  if (uVar5 < 0xe) {
    return;
  }
  if (0x11 < uVar5) {
    return;
  }
  (&this->mTelescopeSlot)[uVar5] = param_2;
  uVar5 = (uint)*pbVar1;
  if (uVar5 < 0x15) {
    (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].mStageName[uVar5] =
         param_2;
  }
  else {
    if (0x17 < uVar5) {
      if (uVar5 < 0x20) {
        d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits[uVar5 + 0xd] =
             param_2;
      }
      else {
        if (0x23 < uVar5) {
          if (uVar5 < 0x2c) {
            d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits[uVar5 + 9] =
                 param_2;
          }
          else {
            if ((0x2f < uVar5) && (uVar5 < 0x38)) {
              d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits[uVar5 + 5] =
                   param_2;
            }
          }
        }
      }
    }
  }
  d_com_inf_game::g_dComIfG_gameInfo._23517_1_ = *pbVar1;
  uVar5 = (uint)*pbVar1;
  d_com_inf_game::g_dComIfG_gameInfo._23518_1_ = param_2;
  if (uVar5 == 0xff) {
    d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[uVar2] = InvalidItem;
    return;
  }
  if (uVar5 < 0x15) {
    dVar4 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].mStageName
            [uVar5];
  }
  else {
    if (uVar5 < 0x18) {
      dVar4 = InvalidItem;
    }
    else {
      if (uVar5 < 0x20) {
        dVar4 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits[uVar5 + 0xd]
        ;
      }
      else {
        if (uVar5 < 0x24) {
          dVar4 = InvalidItem;
        }
        else {
          if (uVar5 < 0x2c) {
            dVar4 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                    [uVar5 + 9];
          }
          else {
            if (uVar5 < 0x30) {
              dVar4 = InvalidItem;
            }
            else {
              if (uVar5 < 0x38) {
                dVar4 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                        [uVar5 + 5];
              }
              else {
                dVar4 = InvalidItem;
              }
            }
          }
        }
      }
    }
  }
  d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[uVar2] = dVar4;
  uVar2 = (uint)*pbVar1;
  if (uVar2 < 0x15) {
    bVar3 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].mStageName
            [uVar2];
  }
  else {
    if (uVar2 < 0x18) {
      bVar3 = 0xff;
    }
    else {
      if (uVar2 < 0x20) {
        bVar3 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits[uVar2 + 0xd]
        ;
      }
      else {
        if (uVar2 < 0x24) {
          bVar3 = 0xff;
        }
        else {
          if (uVar2 < 0x2c) {
            bVar3 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                    [uVar2 + 9];
          }
          else {
            if (uVar2 < 0x30) {
              bVar3 = 0xff;
            }
            else {
              if (uVar2 < 0x38) {
                bVar3 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                        [uVar2 + 5];
              }
              else {
                bVar3 = 0xff;
              }
            }
          }
        }
      }
    }
  }
  if (bVar3 != 0xff) {
    return;
  }
  *pbVar1 = 0xff;
  return;
}


/* __thiscall dSv_player_item_c::setEquipBottleItemEmpty(unsigned char) */

void __thiscall dSv_player_item_c::setEquipBottleItemEmpty(dSv_player_item_c *this,uchar param_1)

{
  setEquipBottleItemIn(this,param_1,0x50);
  return;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall dSv_player_item_c::setEquipBottleItemIn(unsigned char) */

void __thiscall dSv_player_item_c::setEquipBottleItemIn(dSv_player_item_c *this,uchar param_1)

{
  byte *pbVar1;
  int iVar2;
  byte bVar3;
  dItem_data__ItemNo dVar4;
  uint uVar5;
  
  if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mTalkButton == 1) {
    iVar2 = 0;
  }
  else {
    if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mTalkButton == 2) {
      iVar2 = 1;
    }
    else {
      if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mTalkButton != 3) {
        return;
      }
      iVar2 = 2;
    }
  }
  pbVar1 = (byte *)(d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                    mInventorySlotIndexOnButton + iVar2);
  uVar5 = (uint)*pbVar1;
  if (uVar5 < 0xe) {
    return;
  }
  if (0x11 < uVar5) {
    return;
  }
  (&this->mTelescopeSlot)[uVar5] = param_1;
  uVar5 = (uint)*pbVar1;
  if (uVar5 < 0x15) {
    (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].mStageName[uVar5] =
         param_1;
  }
  else {
    if (0x17 < uVar5) {
      if (uVar5 < 0x20) {
        d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits[uVar5 + 0xd] =
             param_1;
      }
      else {
        if (0x23 < uVar5) {
          if (uVar5 < 0x2c) {
            d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits[uVar5 + 9] =
                 param_1;
          }
          else {
            if ((0x2f < uVar5) && (uVar5 < 0x38)) {
              d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits[uVar5 + 5] =
                   param_1;
            }
          }
        }
      }
    }
  }
  d_com_inf_game::g_dComIfG_gameInfo._23517_1_ = *pbVar1;
  uVar5 = (uint)*pbVar1;
  d_com_inf_game::g_dComIfG_gameInfo._23518_1_ = param_1;
  if (uVar5 != 0xff) {
    if (uVar5 < 0x15) {
      dVar4 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].mStageName
              [uVar5];
    }
    else {
      if (uVar5 < 0x18) {
        dVar4 = InvalidItem;
      }
      else {
        if (uVar5 < 0x20) {
          dVar4 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                  [uVar5 + 0xd];
        }
        else {
          if (uVar5 < 0x24) {
            dVar4 = InvalidItem;
          }
          else {
            if (uVar5 < 0x2c) {
              dVar4 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                      [uVar5 + 9];
            }
            else {
              if (uVar5 < 0x30) {
                dVar4 = InvalidItem;
              }
              else {
                if (uVar5 < 0x38) {
                  dVar4 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                          [uVar5 + 5];
                }
                else {
                  dVar4 = InvalidItem;
                }
              }
            }
          }
        }
      }
    }
    d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[iVar2] = dVar4;
    uVar5 = (uint)*pbVar1;
    if (uVar5 < 0x15) {
      bVar3 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].mStageName
              [uVar5];
    }
    else {
      if (uVar5 < 0x18) {
        bVar3 = 0xff;
      }
      else {
        if (uVar5 < 0x20) {
          bVar3 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                  [uVar5 + 0xd];
        }
        else {
          if (uVar5 < 0x24) {
            bVar3 = 0xff;
          }
          else {
            if (uVar5 < 0x2c) {
              bVar3 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                      [uVar5 + 9];
            }
            else {
              if (uVar5 < 0x30) {
                bVar3 = 0xff;
              }
              else {
                if (uVar5 < 0x38) {
                  bVar3 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                          [uVar5 + 5];
                }
                else {
                  bVar3 = 0xff;
                }
              }
            }
          }
        }
      }
    }
    if (bVar3 != 0xff) {
      return;
    }
    *pbVar1 = 0xff;
    return;
  }
  d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[iVar2] = InvalidItem;
  return;
}


/* __thiscall dSv_player_item_c::setEquipBottleItemEmpty(void) */

void __thiscall dSv_player_item_c::setEquipBottleItemEmpty(dSv_player_item_c *this)

{
  setEquipBottleItemIn(this,'P');
  return;
}


/* __thiscall dSv_player_item_c::checkBottle(unsigned char) */

char __thiscall dSv_player_item_c::checkBottle(dSv_player_item_c *this,byte param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  cVar1 = '\0';
  iVar2 = 0;
  iVar3 = 4;
  do {
    if (param_1 == *(byte *)(&this->field_0xe + iVar2)) {
      cVar1 = cVar1 + '\x01';
    }
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return cVar1;
}


/* __thiscall dSv_player_item_c::checkEmptyBottle(void) */

char __thiscall dSv_player_item_c::checkEmptyBottle(dSv_player_item_c *this)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  cVar1 = '\0';
  iVar2 = 0;
  iVar3 = 4;
  do {
    if (*(char *)(&this->field_0xe + iVar2) == 'P') {
      cVar1 = cVar1 + '\x01';
    }
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return cVar1;
}


/* __thiscall dSv_player_get_item_c::init(void) */

int __thiscall dSv_player_get_item_c::init(dSv_player_get_item_c *this)

{
  int iVar1;
  
  iVar1 = 0x15;
  do {
    this->mBits[0] = 0;
    this = (dSv_player_get_item_c *)(this->mBits + 1);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return (int)this;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dSv_player_get_item_c::onItem(int,
                                            unsigned char) */

void __thiscall dSv_player_get_item_c::onItem(dSv_player_get_item_c *this,int param_1,uchar param_2)

{
  ulong uVar1;
  
  if (7 < param_2) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_save.cpp",399,"0 <= i_item && i_item < 8");
    m_Do_printf::OSPanic("d_save.cpp",399,&DAT_8034f7fb);
  }
  this->mBits[param_1] = this->mBits[param_1] | (byte)(1 << param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dSv_player_get_item_c::isItem(int,
                                            unsigned char) */

uint __thiscall dSv_player_get_item_c::isItem(dSv_player_get_item_c *this,int param_1,byte param_2)

{
  ulong uVar1;
  
  if (7 < param_2) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_save.cpp",0x1ad,"0 <= i_item && i_item < 8");
    m_Do_printf::OSPanic("d_save.cpp",0x1ad,&DAT_8034f7fb);
  }
  return (uint)((1 << param_2 & 0xffU & (uint)this->mBits[param_1]) != 0);
}


/* __thiscall dSv_player_get_item_c::onBottleItem(unsigned char) */

void __thiscall dSv_player_get_item_c::onBottleItem(dSv_player_get_item_c *this,uchar param_1)

{
  switch(param_1) {
  case 'O':
    this->mBits[0] = this->mBits[0] | 2;
    return;
  case 'P':
    this->mBits[0] = this->mBits[0] | 4;
    return;
  case 'Q':
    this->mBits[0] = this->mBits[0] | 8;
    return;
  case 'R':
    this->mBits[0] = this->mBits[0] | 0x10;
    return;
  case 'S':
    this->mBits[0] = this->mBits[0] | 0x20;
    return;
  case 'T':
    this->mBits[0] = this->mBits[0] | 0x40;
    return;
  case 'U':
    this->mBits[0] = this->mBits[0] | 0x80;
    return;
  case 'V':
    this->mBits[1] = this->mBits[1] | 2;
    return;
  case 'W':
    this->mBits[1] = this->mBits[1] | 4;
    return;
  case 'X':
    this->mBits[1] = this->mBits[1] | 8;
    return;
  case 'Y':
    this->mBits[1] = this->mBits[1] | 0x10;
    return;
  case 'Z':
    this->mBits[1] = this->mBits[1] | 0x20;
    return;
  case '[':
    this->mBits[1] = this->mBits[1] | 0x40;
    return;
  case '\\':
    this->mBits[1] = this->mBits[1] | 0x80;
    return;
  case ']':
    this->mBits[2] = this->mBits[2] | 2;
    return;
  case '^':
    this->mBits[2] = this->mBits[2] | 4;
    return;
  case '_':
    this->mBits[2] = this->mBits[2] | 8;
    return;
  case '`':
    this->mBits[2] = this->mBits[2] | 0x10;
    return;
  default:
    return;
  }
}


/* __thiscall dSv_player_get_item_c::isBottleItem(unsigned char) */

byte __thiscall dSv_player_get_item_c::isBottleItem(dSv_player_get_item_c *this,uchar param_1)

{
  switch(param_1) {
  case 'O':
    return this->mBits[0] >> 1 & 1;
  case 'P':
    return this->mBits[0] >> 2 & 1;
  case 'Q':
    return this->mBits[0] >> 3 & 1;
  case 'R':
    return this->mBits[0] >> 4 & 1;
  case 'S':
    return this->mBits[0] >> 5 & 1;
  case 'T':
    return this->mBits[0] >> 6 & 1;
  case 'U':
    return this->mBits[0] >> 7;
  case 'V':
    return this->mBits[1] >> 1 & 1;
  case 'W':
    return this->mBits[1] >> 2 & 1;
  case 'X':
    return this->mBits[1] >> 3 & 1;
  case 'Y':
    return this->mBits[1] >> 4 & 1;
  case 'Z':
    return this->mBits[1] >> 5 & 1;
  case '[':
    return this->mBits[1] >> 6 & 1;
  case '\\':
    return this->mBits[1] >> 7;
  case ']':
    return this->mBits[2] >> 1 & 1;
  case '^':
    return this->mBits[2] >> 2 & 1;
  case '_':
    return this->mBits[2] >> 3 & 1;
  case '`':
    return this->mBits[2] >> 4 & 1;
  default:
    return 0;
  }
}


/* __thiscall dSv_player_item_record_c::init(void) */

int __thiscall dSv_player_item_record_c::init(dSv_player_item_record_c *this)

{
  int iVar1;
  int iVar2;
  
  *(undefined *)&this->field_0x2 = 0;
  *(undefined *)&this->field_0x3 = 0;
  *(undefined *)&this->field_0x4 = 0;
  this->mTimer = 0;
  iVar1 = 0;
  iVar2 = 3;
  do {
    *(undefined *)(&this->field_0x5 + iVar1) = 0;
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return (int)this;
}


/* __thiscall dSv_player_item_record_c::resetTimer(unsigned short) */

void __thiscall dSv_player_item_record_c::resetTimer(dSv_player_item_record_c *this,ushort param_1)

{
  this->mTimer = param_1;
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5bf6 = 0;
  return;
}


/* __thiscall dSv_player_item_record_c::decTimer(void) */

void __thiscall dSv_player_item_record_c::decTimer(dSv_player_item_record_c *this)

{
  if (d_com_inf_game::g_dComIfG_gameInfo.field_0x5bf6 != 1) {
    return;
  }
  if (this->mTimer != 0) {
    this->mTimer = this->mTimer + -1;
    return;
  }
  this->mTimer = 0;
  d_com_inf_game::g_dComIfG_gameInfo.field_0x5bf6 = 0;
  return;
}


/* __thiscall dSv_player_item_record_c::getTimer(void) */

short __thiscall dSv_player_item_record_c::getTimer(dSv_player_item_record_c *this)

{
  return this->mTimer;
}


/* __thiscall dSv_player_item_max_c::init(void) */

int __thiscall dSv_player_item_max_c::init(dSv_player_item_max_c *this)

{
  int iVar1;
  int iVar2;
  
  *(undefined *)this = 0;
  this->field_0x1 = 0;
  this->field_0x2 = 0;
  iVar1 = 0;
  iVar2 = 5;
  do {
    *(undefined *)(&this->field_0x3 + iVar1) = 0;
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return (int)this;
}


/* __thiscall dSv_player_bag_item_c::init(void) */

int __thiscall dSv_player_bag_item_c::init(dSv_player_bag_item_c *this)

{
  dSv_player_bag_item_c *pdVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 8;
  pdVar1 = this;
  do {
    pdVar1->field_0x0[0] = 0xff;
    pdVar1 = (dSv_player_bag_item_c *)(pdVar1->field_0x0 + 1);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar2 = 0;
  iVar3 = 8;
  do {
    this->field_0x0[iVar2 + 8] = 0xff;
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar2 = 0;
  iVar3 = 8;
  do {
    this->field_0x0[iVar2 + 0x10] = 0xff;
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return (int)this;
}


/* __thiscall dSv_player_bag_item_c::setBeastItem(unsigned char) */

void __thiscall dSv_player_bag_item_c::setBeastItem(dSv_player_bag_item_c *this,uchar param_1)

{
  char cVar2;
  dSv_player_bag_item_c *pdVar1;
  int iVar3;
  int iVar4;
  
  cVar2 = checkBeastItem(this,param_1);
  if (cVar2 == '\0') {
    iVar3 = 0;
    iVar4 = 8;
    pdVar1 = this;
    do {
      if (pdVar1->field_0x0[0] == 0xff) {
        this->field_0x0[iVar3] = param_1;
        return;
      }
      iVar3 = iVar3 + 1;
      pdVar1 = (dSv_player_bag_item_c *)(pdVar1->field_0x0 + 1);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  return;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall dSv_player_bag_item_c::setBeastItemEmpty(unsigned char) */

void __thiscall dSv_player_bag_item_c::setBeastItemEmpty(dSv_player_bag_item_c *this,uchar param_1)

{
  char cVar2;
  dSv_player_bag_item_c *pdVar1;
  int iVar3;
  byte *pbVar4;
  dItem_data__ItemNo dVar5;
  byte bVar6;
  uint uVar7;
  int iVar8;
  
  cVar2 = checkBeastItem(this,param_1);
  if (cVar2 != '\0') {
    iVar3 = 0;
    iVar8 = 8;
    pdVar1 = this;
    do {
      if (param_1 == pdVar1->field_0x0[0]) {
        this->field_0x0[iVar3] = 0xff;
        iVar3 = 0;
        iVar8 = 3;
        do {
          if (param_1 == d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[iVar3]) {
            pbVar4 = (byte *)(d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                              mInventorySlotIndexOnButton + iVar3);
            uVar7 = (uint)(byte)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                                mInventorySlotIndexOnButton[iVar3];
            if (uVar7 < 0x15) {
              (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].mStageName
              [uVar7] = -1;
            }
            else {
              if (0x17 < uVar7) {
                if (uVar7 < 0x20) {
                  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                  [uVar7 + 0xd] = 0xff;
                }
                else {
                  if (0x23 < uVar7) {
                    if (uVar7 < 0x2c) {
                      d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                      [uVar7 + 9] = 0xff;
                    }
                    else {
                      if ((0x2f < uVar7) && (uVar7 < 0x38)) {
                        d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                        [uVar7 + 5] = 0xff;
                      }
                    }
                  }
                }
              }
            }
            d_com_inf_game::g_dComIfG_gameInfo._23517_1_ = *pbVar4;
            dVar5 = InvalidItem;
            d_com_inf_game::g_dComIfG_gameInfo._23518_1_ = 0xff;
            uVar7 = (uint)*pbVar4;
            if (uVar7 == 0xff) {
              d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[iVar3] = InvalidItem;
            }
            else {
              if (uVar7 < 0x15) {
                dVar5 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
                        mStageName[uVar7];
              }
              else {
                if (0x17 < uVar7) {
                  if (uVar7 < 0x20) {
                    dVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                            [uVar7 + 0xd];
                  }
                  else {
                    if (0x23 < uVar7) {
                      if (uVar7 < 0x2c) {
                        dVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.
                                mBits[uVar7 + 9];
                      }
                      else {
                        if ((0x2f < uVar7) && (uVar7 < 0x38)) {
                          dVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.
                                  mBits[uVar7 + 5];
                        }
                      }
                    }
                  }
                }
              }
              d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[iVar3] = dVar5;
              uVar7 = (uint)*pbVar4;
              if (uVar7 < 0x15) {
                bVar6 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].
                        mStageName[uVar7];
              }
              else {
                if (uVar7 < 0x18) {
                  bVar6 = 0xff;
                }
                else {
                  if (uVar7 < 0x20) {
                    bVar6 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                            [uVar7 + 0xd];
                  }
                  else {
                    if (uVar7 < 0x24) {
                      bVar6 = 0xff;
                    }
                    else {
                      if (uVar7 < 0x2c) {
                        bVar6 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.
                                mBits[uVar7 + 9];
                      }
                      else {
                        if (uVar7 < 0x30) {
                          bVar6 = 0xff;
                        }
                        else {
                          if (uVar7 < 0x38) {
                            bVar6 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.
                                    mGetItem.mBits[uVar7 + 5];
                          }
                          else {
                            bVar6 = 0xff;
                          }
                        }
                      }
                    }
                  }
                }
              }
              if (bVar6 == 0xff) {
                *pbVar4 = 0xff;
              }
            }
          }
          iVar3 = iVar3 + 1;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
        return;
      }
      iVar3 = iVar3 + 1;
      pdVar1 = (dSv_player_bag_item_c *)(pdVar1->field_0x0 + 1);
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
  }
  return;
}


/* __thiscall dSv_player_bag_item_c::checkBeastItem(unsigned char) */

undefined4 __thiscall
dSv_player_bag_item_c::checkBeastItem(dSv_player_bag_item_c *this,uchar param_1)

{
  int iVar1;
  
  iVar1 = 8;
  do {
    if (param_1 == this->field_0x0[0]) {
      return 1;
    }
    this = (dSv_player_bag_item_c *)(this->field_0x0 + 1);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return 0;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall dSv_player_bag_item_c::setBaitItemChange(unsigned char) */

void __thiscall dSv_player_bag_item_c::setBaitItemChange(dSv_player_bag_item_c *this,uchar param_1)

{
  byte *pbVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  dItem_data__ItemNo dVar5;
  
  if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mTalkButton == 1) {
    iVar2 = 0;
  }
  else {
    if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mTalkButton == 2) {
      iVar2 = 1;
    }
    else {
      if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mTalkButton != 3) {
        return;
      }
      iVar2 = 2;
    }
  }
  pbVar1 = (byte *)(d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                    mInventorySlotIndexOnButton + iVar2);
  uVar4 = (uint)*pbVar1;
  if (uVar4 < 0x24) {
    return;
  }
  if (0x2b < uVar4) {
    return;
  }
  if (uVar4 < 0x15) {
    (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].mStageName[uVar4] =
         param_1;
  }
  else {
    if (0x17 < uVar4) {
      if (uVar4 < 0x20) {
        d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits[uVar4 + 0xd] =
             param_1;
      }
      else {
        if (0x23 < uVar4) {
          if (uVar4 < 0x2c) {
            d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits[uVar4 + 9] =
                 param_1;
          }
          else {
            if ((0x2f < uVar4) && (uVar4 < 0x38)) {
              d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits[uVar4 + 5] =
                   param_1;
            }
          }
        }
      }
    }
  }
  d_com_inf_game::g_dComIfG_gameInfo._23517_1_ = *pbVar1;
  uVar4 = (uint)*pbVar1;
  d_com_inf_game::g_dComIfG_gameInfo._23518_1_ = param_1;
  if (uVar4 != 0xff) {
    if (uVar4 < 0x15) {
      dVar5 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].mStageName
              [uVar4];
    }
    else {
      if (uVar4 < 0x18) {
        dVar5 = InvalidItem;
      }
      else {
        if (uVar4 < 0x20) {
          dVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                  [uVar4 + 0xd];
        }
        else {
          if (uVar4 < 0x24) {
            dVar5 = InvalidItem;
          }
          else {
            if (uVar4 < 0x2c) {
              dVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                      [uVar4 + 9];
            }
            else {
              if (uVar4 < 0x30) {
                dVar5 = InvalidItem;
              }
              else {
                if (uVar4 < 0x38) {
                  dVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                          [uVar4 + 5];
                }
                else {
                  dVar5 = InvalidItem;
                }
              }
            }
          }
        }
      }
    }
    d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[iVar2] = dVar5;
    uVar4 = (uint)*pbVar1;
    if (uVar4 < 0x15) {
      bVar3 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].mStageName
              [uVar4];
    }
    else {
      if (uVar4 < 0x18) {
        bVar3 = 0xff;
      }
      else {
        if (uVar4 < 0x20) {
          bVar3 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                  [uVar4 + 0xd];
        }
        else {
          if (uVar4 < 0x24) {
            bVar3 = 0xff;
          }
          else {
            if (uVar4 < 0x2c) {
              bVar3 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                      [uVar4 + 9];
            }
            else {
              if (uVar4 < 0x30) {
                bVar3 = 0xff;
              }
              else {
                if (uVar4 < 0x38) {
                  bVar3 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                          [uVar4 + 5];
                }
                else {
                  bVar3 = 0xff;
                }
              }
            }
          }
        }
      }
    }
    if (bVar3 != 0xff) {
      return;
    }
    *pbVar1 = 0xff;
    return;
  }
  d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[iVar2] = InvalidItem;
  return;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall dSv_player_bag_item_c::setBaitItemChange(unsigned char,
                                                       unsigned char) */

void __thiscall
dSv_player_bag_item_c::setBaitItemChange(dSv_player_bag_item_c *this,uchar param_1,uchar param_2)

{
  byte *pbVar1;
  dItem_data__ItemNo dVar3;
  uint uVar2;
  byte bVar4;
  uint uVar5;
  
  uVar2 = (uint)param_1;
  if (2 < uVar2) {
    return;
  }
  pbVar1 = (byte *)(d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                    mInventorySlotIndexOnButton + uVar2);
  uVar5 = (uint)*pbVar1;
  if (uVar5 < 0x24) {
    return;
  }
  if (0x2b < uVar5) {
    return;
  }
  if (uVar5 < 0x15) {
    (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].mStageName[uVar5] =
         param_2;
  }
  else {
    if (0x17 < uVar5) {
      if (uVar5 < 0x20) {
        d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits[uVar5 + 0xd] =
             param_2;
      }
      else {
        if (0x23 < uVar5) {
          if (uVar5 < 0x2c) {
            d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits[uVar5 + 9] =
                 param_2;
          }
          else {
            if ((0x2f < uVar5) && (uVar5 < 0x38)) {
              d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits[uVar5 + 5] =
                   param_2;
            }
          }
        }
      }
    }
  }
  d_com_inf_game::g_dComIfG_gameInfo._23517_1_ = *pbVar1;
  uVar5 = (uint)*pbVar1;
  d_com_inf_game::g_dComIfG_gameInfo._23518_1_ = param_2;
  if (uVar5 != 0xff) {
    if (uVar5 < 0x15) {
      dVar3 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].mStageName
              [uVar5];
    }
    else {
      if (uVar5 < 0x18) {
        dVar3 = InvalidItem;
      }
      else {
        if (uVar5 < 0x20) {
          dVar3 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                  [uVar5 + 0xd];
        }
        else {
          if (uVar5 < 0x24) {
            dVar3 = InvalidItem;
          }
          else {
            if (uVar5 < 0x2c) {
              dVar3 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                      [uVar5 + 9];
            }
            else {
              if (uVar5 < 0x30) {
                dVar3 = InvalidItem;
              }
              else {
                if (uVar5 < 0x38) {
                  dVar3 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                          [uVar5 + 5];
                }
                else {
                  dVar3 = InvalidItem;
                }
              }
            }
          }
        }
      }
    }
    d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[uVar2] = dVar3;
    uVar2 = (uint)*pbVar1;
    if (uVar2 < 0x15) {
      bVar4 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].mStageName
              [uVar2];
    }
    else {
      if (uVar2 < 0x18) {
        bVar4 = 0xff;
      }
      else {
        if (uVar2 < 0x20) {
          bVar4 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                  [uVar2 + 0xd];
        }
        else {
          if (uVar2 < 0x24) {
            bVar4 = 0xff;
          }
          else {
            if (uVar2 < 0x2c) {
              bVar4 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                      [uVar2 + 9];
            }
            else {
              if (uVar2 < 0x30) {
                bVar4 = 0xff;
              }
              else {
                if (uVar2 < 0x38) {
                  bVar4 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                          [uVar2 + 5];
                }
                else {
                  bVar4 = 0xff;
                }
              }
            }
          }
        }
      }
    }
    if (bVar4 != 0xff) {
      return;
    }
    *pbVar1 = 0xff;
    return;
  }
  d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[uVar2] = InvalidItem;
  return;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall dSv_player_bag_item_c::setBaitItemEmpty(void) */

void __thiscall dSv_player_bag_item_c::setBaitItemEmpty(dSv_player_bag_item_c *this)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  
  if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mTalkButton == 1) {
    iVar1 = 0;
  }
  else {
    if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mTalkButton == 2) {
      iVar1 = 1;
    }
    else {
      if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mTalkButton != 3) {
        return;
      }
      iVar1 = 2;
    }
  }
  uVar3 = (uint)(byte)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                      mInventorySlotIndexOnButton[iVar1];
  if ((0x23 < uVar3) && (uVar3 < 0x2c)) {
    if (d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[iVar1] == HyoiPear) {
      setBaitItemChange(this,0xff);
    }
    else {
      if (d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[iVar1] == AllPurposeBait) {
        bVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem.field_0x0
                [uVar3 + 10];
        if (bVar2 != 0) {
          bVar2 = bVar2 - 1;
        }
        d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem.field_0x0[uVar3 + 10] =
             bVar2;
        if (bVar2 == 0) {
          setBaitItemChange(this,0xff);
        }
      }
    }
  }
  return;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall dSv_player_bag_item_c::setBaitItemEmpty(unsigned char) */

void __thiscall dSv_player_bag_item_c::setBaitItemEmpty(dSv_player_bag_item_c *this,uchar param_1)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  
  uVar1 = (uint)param_1;
  if (((uVar1 < 3) &&
      (uVar3 = (uint)(byte)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                           mInventorySlotIndexOnButton[uVar1], 0x23 < uVar3)) && (uVar3 < 0x2c)) {
    if (d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[uVar1] == HyoiPear) {
      setBaitItemChange(this,param_1,0xff);
    }
    else {
      if (d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[uVar1] == AllPurposeBait) {
        bVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem.field_0x0
                [uVar3 + 10];
        if (bVar2 != 0) {
          bVar2 = bVar2 - 1;
        }
        d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem.field_0x0[uVar3 + 10] =
             bVar2;
        if (bVar2 == 0) {
          setBaitItemChange(this,param_1,0xff);
        }
      }
    }
  }
  return;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall dSv_player_bag_item_c::setBaitItem(unsigned char) */

void __thiscall dSv_player_bag_item_c::setBaitItem(dSv_player_bag_item_c *this,uchar param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  cVar1 = checkBaitItemEmpty(this);
  if (cVar1 != '\0') {
    iVar2 = 0;
    iVar3 = 8;
    do {
      if (this->field_0x0[iVar2 + 8] == 0xff) {
        this->field_0x0[iVar2 + 8] = param_1;
        (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem)[1].field_0x0
        [iVar2 + 0x16] = 3;
        return;
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return;
}


/* __thiscall dSv_player_bag_item_c::checkBaitItemEmpty(void) */

void __thiscall dSv_player_bag_item_c::checkBaitItemEmpty(dSv_player_bag_item_c *this)

{
  checkBaitItem(this,0xff);
  return;
}


/* __thiscall dSv_player_bag_item_c::checkBaitItem(unsigned char) */

char __thiscall dSv_player_bag_item_c::checkBaitItem(dSv_player_bag_item_c *this,uchar param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  cVar1 = '\0';
  iVar2 = 0;
  iVar3 = 8;
  do {
    if (this->field_0x0[iVar2 + 8] == param_1) {
      cVar1 = cVar1 + '\x01';
    }
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return cVar1;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall dSv_player_bag_item_c::setReserveItemChange(unsigned char) */

void __thiscall
dSv_player_bag_item_c::setReserveItemChange(dSv_player_bag_item_c *this,uchar param_1)

{
  byte *pbVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  dItem_data__ItemNo dVar5;
  
  if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mTalkButton == 1) {
    iVar2 = 0;
  }
  else {
    if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mTalkButton == 2) {
      iVar2 = 1;
    }
    else {
      if (d_com_inf_game::g_dComIfG_gameInfo.mPlay.mEvtCtrl.mTalkButton != 3) {
        return;
      }
      iVar2 = 2;
    }
  }
  pbVar1 = (byte *)(d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                    mInventorySlotIndexOnButton + iVar2);
  uVar4 = (uint)*pbVar1;
  if (uVar4 < 0x30) {
    return;
  }
  if (0x37 < uVar4) {
    return;
  }
  if (uVar4 < 0x15) {
    (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].mStageName[uVar4] =
         param_1;
  }
  else {
    if (0x17 < uVar4) {
      if (uVar4 < 0x20) {
        d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits[uVar4 + 0xd] =
             param_1;
      }
      else {
        if (0x23 < uVar4) {
          if (uVar4 < 0x2c) {
            d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits[uVar4 + 9] =
                 param_1;
          }
          else {
            if ((0x2f < uVar4) && (uVar4 < 0x38)) {
              d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits[uVar4 + 5] =
                   param_1;
            }
          }
        }
      }
    }
  }
  d_com_inf_game::g_dComIfG_gameInfo._23517_1_ = *pbVar1;
  uVar4 = (uint)*pbVar1;
  d_com_inf_game::g_dComIfG_gameInfo._23518_1_ = param_1;
  if (uVar4 != 0xff) {
    if (uVar4 < 0x15) {
      dVar5 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].mStageName
              [uVar4];
    }
    else {
      if (uVar4 < 0x18) {
        dVar5 = InvalidItem;
      }
      else {
        if (uVar4 < 0x20) {
          dVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                  [uVar4 + 0xd];
        }
        else {
          if (uVar4 < 0x24) {
            dVar5 = InvalidItem;
          }
          else {
            if (uVar4 < 0x2c) {
              dVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                      [uVar4 + 9];
            }
            else {
              if (uVar4 < 0x30) {
                dVar5 = InvalidItem;
              }
              else {
                if (uVar4 < 0x38) {
                  dVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                          [uVar4 + 5];
                }
                else {
                  dVar5 = InvalidItem;
                }
              }
            }
          }
        }
      }
    }
    d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[iVar2] = dVar5;
    uVar4 = (uint)*pbVar1;
    if (uVar4 < 0x15) {
      bVar3 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].mStageName
              [uVar4];
    }
    else {
      if (uVar4 < 0x18) {
        bVar3 = 0xff;
      }
      else {
        if (uVar4 < 0x20) {
          bVar3 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                  [uVar4 + 0xd];
        }
        else {
          if (uVar4 < 0x24) {
            bVar3 = 0xff;
          }
          else {
            if (uVar4 < 0x2c) {
              bVar3 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                      [uVar4 + 9];
            }
            else {
              if (uVar4 < 0x30) {
                bVar3 = 0xff;
              }
              else {
                if (uVar4 < 0x38) {
                  bVar3 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                          [uVar4 + 5];
                }
                else {
                  bVar3 = 0xff;
                }
              }
            }
          }
        }
      }
    }
    if (bVar3 != 0xff) {
      return;
    }
    *pbVar1 = 0xff;
    return;
  }
  d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[iVar2] = InvalidItem;
  return;
}


/* WARNING: Type propagation algorithm not settling */
/* __thiscall dSv_player_bag_item_c::setReserveItemChange(unsigned char,
                                                          unsigned char) */

void __thiscall
dSv_player_bag_item_c::setReserveItemChange(dSv_player_bag_item_c *this,uchar param_1,uchar param_2)

{
  byte *pbVar1;
  dItem_data__ItemNo dVar3;
  uint uVar2;
  byte bVar4;
  uint uVar5;
  
  uVar2 = (uint)param_1;
  if (2 < uVar2) {
    return;
  }
  pbVar1 = (byte *)(d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusA.
                    mInventorySlotIndexOnButton + uVar2);
  uVar5 = (uint)*pbVar1;
  if (uVar5 < 0x30) {
    return;
  }
  if (0x37 < uVar5) {
    return;
  }
  if (uVar5 < 0x15) {
    (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].mStageName[uVar5] =
         param_2;
  }
  else {
    if (0x17 < uVar5) {
      if (uVar5 < 0x20) {
        d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits[uVar5 + 0xd] =
             param_2;
      }
      else {
        if (0x23 < uVar5) {
          if (uVar5 < 0x2c) {
            d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits[uVar5 + 9] =
                 param_2;
          }
          else {
            if ((0x2f < uVar5) && (uVar5 < 0x38)) {
              d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits[uVar5 + 5] =
                   param_2;
            }
          }
        }
      }
    }
  }
  d_com_inf_game::g_dComIfG_gameInfo._23517_1_ = *pbVar1;
  uVar5 = (uint)*pbVar1;
  d_com_inf_game::g_dComIfG_gameInfo._23518_1_ = param_2;
  if (uVar5 != 0xff) {
    if (uVar5 < 0x15) {
      dVar3 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].mStageName
              [uVar5];
    }
    else {
      if (uVar5 < 0x18) {
        dVar3 = InvalidItem;
      }
      else {
        if (uVar5 < 0x20) {
          dVar3 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                  [uVar5 + 0xd];
        }
        else {
          if (uVar5 < 0x24) {
            dVar3 = InvalidItem;
          }
          else {
            if (uVar5 < 0x2c) {
              dVar3 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                      [uVar5 + 9];
            }
            else {
              if (uVar5 < 0x30) {
                dVar3 = InvalidItem;
              }
              else {
                if (uVar5 < 0x38) {
                  dVar3 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                          [uVar5 + 5];
                }
                else {
                  dVar3 = InvalidItem;
                }
              }
            }
          }
        }
      }
    }
    d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[uVar2] = dVar3;
    uVar2 = (uint)*pbVar1;
    if (uVar2 < 0x15) {
      bVar4 = (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace)[1].mStageName
              [uVar2];
    }
    else {
      if (uVar2 < 0x18) {
        bVar4 = 0xff;
      }
      else {
        if (uVar2 < 0x20) {
          bVar4 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                  [uVar2 + 0xd];
        }
        else {
          if (uVar2 < 0x24) {
            bVar4 = 0xff;
          }
          else {
            if (uVar2 < 0x2c) {
              bVar4 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                      [uVar2 + 9];
            }
            else {
              if (uVar2 < 0x30) {
                bVar4 = 0xff;
              }
              else {
                if (uVar2 < 0x38) {
                  bVar4 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits
                          [uVar2 + 5];
                }
                else {
                  bVar4 = 0xff;
                }
              }
            }
          }
        }
      }
    }
    if (bVar4 != 0xff) {
      return;
    }
    *pbVar1 = 0xff;
    return;
  }
  d_com_inf_game::g_dComIfG_gameInfo.mEquippedItems[uVar2] = InvalidItem;
  return;
}


/* __thiscall dSv_player_bag_item_c::setReserveItemEmpty(void) */

void __thiscall dSv_player_bag_item_c::setReserveItemEmpty(dSv_player_bag_item_c *this)

{
  setReserveItemChange(this,0xff);
  return;
}


/* __thiscall dSv_player_bag_item_c::setReserveItemEmpty(unsigned char) */

void __thiscall
dSv_player_bag_item_c::setReserveItemEmpty(dSv_player_bag_item_c *this,uchar param_1)

{
  setReserveItemChange(this,param_1,0xff);
  return;
}


/* __thiscall dSv_player_bag_item_c::setReserveItem(unsigned char) */

void __thiscall dSv_player_bag_item_c::setReserveItem(dSv_player_bag_item_c *this,uchar param_1)

{
  char cVar2;
  int iVar1;
  int iVar3;
  
  cVar2 = checkReserveItemEmpty(this);
  if (cVar2 != '\0') {
    iVar1 = 0;
    iVar3 = 8;
    do {
      if (this->field_0x0[iVar1 + 0x10] == 0xff) {
        this->field_0x0[iVar1 + 0x10] = param_1;
        return;
      }
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return;
}


/* __thiscall dSv_player_bag_item_c::checkReserveItemEmpty(void) */

void __thiscall dSv_player_bag_item_c::checkReserveItemEmpty(dSv_player_bag_item_c *this)

{
  checkReserveItem(this,0xff);
  return;
}


/* __thiscall dSv_player_bag_item_c::checkReserveItem(unsigned char) */

char __thiscall dSv_player_bag_item_c::checkReserveItem(dSv_player_bag_item_c *this,uchar param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  cVar1 = '\0';
  iVar2 = 0;
  iVar3 = 8;
  do {
    if (this->field_0x0[iVar2 + 0x10] == param_1) {
      cVar1 = cVar1 + '\x01';
    }
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return cVar1;
}


/* __thiscall dSv_player_get_bag_item_c::init(void) */

int __thiscall dSv_player_get_bag_item_c::init(dSv_player_get_bag_item_c *this)

{
  *(undefined *)&this->field_0x4 = 0;
  *(undefined *)&this->field_0x5 = 0;
  *(undefined4 *)this = 0;
  return (int)this;
}


/* __thiscall dSv_player_get_bag_item_c::onBeast(unsigned char) */

void __thiscall dSv_player_get_bag_item_c::onBeast(dSv_player_get_bag_item_c *this,byte bitIndex)

{
  ulong uVar1;
  
  if (7 < bitIndex) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_save.cpp",0x4d3,"0 <= i_no && i_no < 8");
    m_Do_printf::OSPanic("d_save.cpp",0x4d3,&DAT_8034f7fb);
  }
  *(byte *)&this->field_0x4 = *(byte *)&this->field_0x4 | (byte)(1 << bitIndex);
  return;
}


/* __thiscall dSv_player_get_bag_item_c::isBeast(unsigned char) */

bool __thiscall dSv_player_get_bag_item_c::isBeast(dSv_player_get_bag_item_c *this,byte bitIndex)

{
  ulong uVar1;
  
  if (7 < bitIndex) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_save.cpp",0x4f1,"0 <= i_no && i_no < 8");
    m_Do_printf::OSPanic("d_save.cpp",0x4f1,&DAT_8034f7fb);
  }
  return (1 << bitIndex & 0xffU & (uint)*(byte *)&this->field_0x4) != 0;
}


/* __thiscall dSv_player_get_bag_item_c::onBait(unsigned char) */

void __thiscall dSv_player_get_bag_item_c::onBait(dSv_player_get_bag_item_c *this,byte param_1)

{
  ulong uVar1;
  
  if (7 < param_1) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_save.cpp",0x500,"0 <= i_no && i_no < 8");
    m_Do_printf::OSPanic("d_save.cpp",0x500,&DAT_8034f7fb);
  }
  *(byte *)&this->field_0x5 = *(byte *)&this->field_0x5 | (byte)(1 << param_1);
  return;
}


/* __thiscall dSv_player_get_bag_item_c::isBait(unsigned char) */

bool __thiscall dSv_player_get_bag_item_c::isBait(dSv_player_get_bag_item_c *this,byte param_1)

{
  ulong uVar1;
  
  if (7 < param_1) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_save.cpp",0x51e,"0 <= i_no && i_no < 8");
    m_Do_printf::OSPanic("d_save.cpp",0x51e,&DAT_8034f7fb);
  }
  return (1 << param_1 & 0xffU & (uint)*(byte *)&this->field_0x5) != 0;
}


/* __thiscall dSv_player_get_bag_item_c::onReserve(unsigned char) */

void __thiscall dSv_player_get_bag_item_c::onReserve(dSv_player_get_bag_item_c *this,uchar param_1)

{
  ulong uVar1;
  
  if (0x1f < param_1) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_save.cpp",0x52d,"0 <= i_no && i_no < 32");
    m_Do_printf::OSPanic("d_save.cpp",0x52d,&DAT_8034f7fb);
  }
  *(uint *)this = *(uint *)this | 1 << param_1;
  return;
}


/* __thiscall dSv_player_get_bag_item_c::isReserve(unsigned char) */

bool __thiscall dSv_player_get_bag_item_c::isReserve(dSv_player_get_bag_item_c *this,uchar param_1)

{
  ulong uVar1;
  
  if (0x1f < param_1) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_save.cpp",0x54b,"0 <= i_no && i_no < 32");
    m_Do_printf::OSPanic("d_save.cpp",0x54b,&DAT_8034f7fb);
  }
  return (*(uint *)this & 1 << param_1) != 0;
}


/* __thiscall dSv_player_bag_item_record_c::init(void) */

int __thiscall dSv_player_bag_item_record_c::init(dSv_player_bag_item_record_c *this)

{
  dSv_player_bag_item_record_c *pdVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 8;
  pdVar1 = this;
  do {
    *(undefined *)pdVar1 = 0;
    pdVar1 = (dSv_player_bag_item_record_c *)&pdVar1->field_0x1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  iVar2 = 0;
  iVar3 = 8;
  do {
    *(undefined *)(&this->field_0x8 + iVar2) = 0;
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar2 = 0;
  iVar3 = 8;
  do {
    *(undefined *)(&this->field_0x10 + iVar2) = 0;
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return (int)this;
}


/* __thiscall dSv_player_collect_c::init(void) */

int __thiscall dSv_player_collect_c::init(dSv_player_collect_c *this)

{
  dSv_player_collect_c *pdVar1;
  int iVar2;
  
  iVar2 = 8;
  pdVar1 = this;
  do {
    pdVar1->mData[0] = 0;
    pdVar1 = (dSv_player_collect_c *)(pdVar1->mData + 1);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined *)&this->field_0x8 = 0;
  this->mTact = 0;
  this->mTriforce = 0;
  this->mSymbol = 0;
  *(undefined *)&this->field_0xc = 0;
  return (int)this;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dSv_player_collect_c::onCollect(int,
                                              unsigned char) */

void __thiscall
dSv_player_collect_c::onCollect(dSv_player_collect_c *this,int byteOffset,byte bitIndex)

{
  ulong uVar1;
  
  if (7 < bitIndex) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_save.cpp",0x584,"0 <= i_item && i_item < 8");
    m_Do_printf::OSPanic("d_save.cpp",0x584,&DAT_8034f7fb);
  }
  this->mData[byteOffset] = this->mData[byteOffset] | (byte)(1 << bitIndex);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dSv_player_collect_c::offCollect(int,
                                               unsigned char) */

void __thiscall
dSv_player_collect_c::offCollect(dSv_player_collect_c *this,int param_1,uchar param_2)

{
  ulong uVar1;
  
  if (7 < param_2) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_save.cpp",0x593,"0 <= i_item && i_item < 8");
    m_Do_printf::OSPanic("d_save.cpp",0x593,&DAT_8034f7fb);
  }
  this->mData[param_1] = this->mData[param_1] & ~(byte)(1 << param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dSv_player_collect_c::isCollect(int,
                                              unsigned char) */

uint __thiscall
dSv_player_collect_c::isCollect(dSv_player_collect_c *this,int byteOffset,byte bitIndex)

{
  ulong uVar1;
  
  if (7 < bitIndex) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_save.cpp",0x5a2,"0 <= i_item && i_item < 8");
    m_Do_printf::OSPanic("d_save.cpp",0x5a2,&DAT_8034f7fb);
  }
  return (uint)((1 << bitIndex & 0xffU & (uint)this->mData[byteOffset]) != 0);
}


/* __thiscall dSv_player_collect_c::onTact(unsigned char) */

void __thiscall dSv_player_collect_c::onTact(dSv_player_collect_c *this,uchar param_1)

{
  ulong uVar1;
  
  if (7 < param_1) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_save.cpp",0x5de,"0 <= i_no && i_no < 8");
    m_Do_printf::OSPanic("d_save.cpp",0x5de,&DAT_8034f7fb);
  }
  this->mTact = this->mTact | (byte)(1 << param_1);
  return;
}


/* __thiscall dSv_player_collect_c::isTact(unsigned char) */

bool __thiscall dSv_player_collect_c::isTact(dSv_player_collect_c *this,uchar param_1)

{
  ulong uVar1;
  
  if (7 < param_1) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_save.cpp",0x5fc,"0 <= i_no && i_no < 8");
    m_Do_printf::OSPanic("d_save.cpp",0x5fc,&DAT_8034f7fb);
  }
  return (1 << param_1 & 0xffU & (uint)this->mTact) != 0;
}


/* __thiscall dSv_player_collect_c::onTriforce(unsigned char) */

void __thiscall dSv_player_collect_c::onTriforce(dSv_player_collect_c *this,uchar param_1)

{
  ulong uVar1;
  
  if (7 < param_1) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_save.cpp",0x60b,"0 <= i_no && i_no < 8");
    m_Do_printf::OSPanic("d_save.cpp",0x60b,&DAT_8034f7fb);
  }
  this->mTriforce = this->mTriforce | (byte)(1 << param_1);
  return;
}


/* __thiscall dSv_player_collect_c::isTriforce(unsigned char) */

bool __thiscall dSv_player_collect_c::isTriforce(dSv_player_collect_c *this,uchar param_1)

{
  ulong uVar1;
  
  if (7 < param_1) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_save.cpp",0x629,"0 <= i_no && i_no < 8");
    m_Do_printf::OSPanic("d_save.cpp",0x629,&DAT_8034f7fb);
  }
  return (1 << param_1 & 0xffU & (uint)this->mTriforce) != 0;
}


/* __thiscall dSv_player_collect_c::onSymbol(unsigned char) */

void __thiscall dSv_player_collect_c::onSymbol(dSv_player_collect_c *this,uchar param_1)

{
  ulong uVar1;
  
  if (7 < param_1) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_save.cpp",0x638,"0 <= i_no && i_no < 8");
    m_Do_printf::OSPanic("d_save.cpp",0x638,&DAT_8034f7fb);
  }
  this->mSymbol = this->mSymbol | (byte)(1 << param_1);
  return;
}


/* __thiscall dSv_player_collect_c::isSymbol(unsigned char) */

bool __thiscall dSv_player_collect_c::isSymbol(dSv_player_collect_c *this,uchar param_1)

{
  ulong uVar1;
  
  if (7 < param_1) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_save.cpp",0x656,"0 <= i_no && i_no < 8");
    m_Do_printf::OSPanic("d_save.cpp",0x656,&DAT_8034f7fb);
  }
  return (1 << param_1 & 0xffU & (uint)this->mSymbol) != 0;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dSv_player_collect_c::getTriforceNum(void) */

int __thiscall dSv_player_collect_c::getTriforceNum(dSv_player_collect_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = 0;
  do {
    iVar1 = isTriforce(this,(uchar)iVar2);
    if (iVar1 != 0) {
      iVar3 = iVar3 + 1;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 8);
  return iVar3;
}


/* __thiscall dSv_player_map_c::init(void) */

int __thiscall dSv_player_map_c::init(dSv_player_map_c *this)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar1 = 0;
  iVar3 = 4;
  do {
    puVar2 = (undefined4 *)(&this->field_0x0 + iVar1);
    *puVar2 = 0;
    puVar2[4] = 0;
    puVar2[8] = 0;
    puVar2[0xc] = 0;
    iVar1 = iVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar1 = 0;
  iVar3 = 0x31;
  do {
    *(undefined *)(&this->field_0x40 + iVar1) = 0;
    iVar1 = iVar1 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *(undefined *)&this->field_0x81 = 0;
  *(undefined *)&this->field_0x40 = 3;
  *(undefined *)&this->field_0x6b = 3;
  *(undefined *)&this->field_0x4a = 3;
  iVar1 = 0;
  iVar3 = 0x10;
  do {
    *(undefined *)(&this->field_0x71 + iVar1) = 0;
    iVar1 = iVar1 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return (int)this;
}


/* __thiscall dSv_player_map_c::onGetMap(int) */

void __thiscall dSv_player_map_c::onGetMap(dSv_player_map_c *this,int param_1)

{
  bool bVar1;
  ulong uVar2;
  int iVar3;
  
  bVar1 = false;
  if ((-1 < param_1) && (param_1 < 0x80)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_save.cpp",0x69a,"0 <= i_no && i_no < 128");
    m_Do_printf::OSPanic("d_save.cpp",0x69a,&DAT_8034f7fb);
  }
  iVar3 = &this->field_0x0 + (param_1 >> 5) * 4;
  *(uint *)(iVar3 + 0x10) = *(uint *)(iVar3 + 0x10) | 1 << (param_1 & 0x1fU);
  return;
}


/* __thiscall dSv_player_map_c::isGetMap(int) */

bool __thiscall dSv_player_map_c::isGetMap(dSv_player_map_c *this,int param_1)

{
  bool bVar1;
  ulong uVar2;
  
  bVar1 = false;
  if ((-1 < param_1) && (param_1 < 0x80)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_save.cpp",0x6b6,"0 <= i_no && i_no < 128");
    m_Do_printf::OSPanic("d_save.cpp",0x6b6,&DAT_8034f7fb);
  }
  return (*(uint *)(&this->field_0x10 + (param_1 >> 5) * 4) & 1 << (param_1 & 0x1fU)) != 0;
}


/* __thiscall dSv_player_map_c::onOpenMap(int) */

void __thiscall dSv_player_map_c::onOpenMap(dSv_player_map_c *this,int param_1)

{
  bool bVar1;
  ulong uVar2;
  int iVar3;
  
  bVar1 = false;
  if ((-1 < param_1) && (param_1 < 0x80)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_save.cpp",0x6d7,"0 <= i_no && i_no < 128");
    m_Do_printf::OSPanic("d_save.cpp",0x6d7,&DAT_8034f7fb);
  }
  iVar3 = &this->field_0x0 + (param_1 >> 5) * 4;
  *(uint *)(iVar3 + 0x20) = *(uint *)(iVar3 + 0x20) | 1 << (param_1 & 0x1fU);
  return;
}


/* __thiscall dSv_player_map_c::offOpenMap(int) */

void __thiscall dSv_player_map_c::offOpenMap(dSv_player_map_c *this,int param_1)

{
  bool bVar1;
  ulong uVar2;
  int iVar3;
  
  bVar1 = false;
  if ((-1 < param_1) && (param_1 < 0x80)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_save.cpp",0x6e5,"0 <= i_no && i_no < 128");
    m_Do_printf::OSPanic("d_save.cpp",0x6e5,&DAT_8034f7fb);
  }
  iVar3 = &this->field_0x0 + (param_1 >> 5) * 4;
  *(uint *)(iVar3 + 0x20) = *(uint *)(iVar3 + 0x20) & ~(1 << (param_1 & 0x1fU));
  return;
}


/* __thiscall dSv_player_map_c::isOpenMap(int) */

bool __thiscall dSv_player_map_c::isOpenMap(dSv_player_map_c *this,int param_1)

{
  bool bVar1;
  ulong uVar2;
  
  bVar1 = false;
  if ((-1 < param_1) && (param_1 < 0x80)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_save.cpp",0x6f3,"0 <= i_no && i_no < 128");
    m_Do_printf::OSPanic("d_save.cpp",0x6f3,&DAT_8034f7fb);
  }
  return (*(uint *)(&this->field_0x20 + (param_1 >> 5) * 4) & 1 << (param_1 & 0x1fU)) != 0;
}


/* __thiscall dSv_player_map_c::onCompleteMap(int) */

void __thiscall dSv_player_map_c::onCompleteMap(dSv_player_map_c *this,int param_1)

{
  bool bVar1;
  ulong uVar2;
  int iVar3;
  
  bVar1 = false;
  if ((-1 < param_1) && (param_1 < 0x80)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_save.cpp",0x714,"0 <= i_no && i_no < 128");
    m_Do_printf::OSPanic("d_save.cpp",0x714,&DAT_8034f7fb);
  }
  iVar3 = &this->field_0x0 + (param_1 >> 5) * 4;
  *(uint *)(iVar3 + 0x30) = *(uint *)(iVar3 + 0x30) | 1 << (param_1 & 0x1fU);
  return;
}


/* __thiscall dSv_player_map_c::offCompleteMap(int) */

void __thiscall dSv_player_map_c::offCompleteMap(dSv_player_map_c *this,int param_1)

{
  bool bVar1;
  ulong uVar2;
  int iVar3;
  
  bVar1 = false;
  if ((-1 < param_1) && (param_1 < 0x80)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_save.cpp",0x722,"0 <= i_no && i_no < 128");
    m_Do_printf::OSPanic("d_save.cpp",0x722,&DAT_8034f7fb);
  }
  iVar3 = &this->field_0x0 + (param_1 >> 5) * 4;
  *(uint *)(iVar3 + 0x30) = *(uint *)(iVar3 + 0x30) & ~(1 << (param_1 & 0x1fU));
  return;
}


/* __thiscall dSv_player_map_c::isCompleteMap(int) */

bool __thiscall dSv_player_map_c::isCompleteMap(dSv_player_map_c *this,int param_1)

{
  bool bVar1;
  ulong uVar2;
  
  bVar1 = false;
  if ((-1 < param_1) && (param_1 < 0x80)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_save.cpp",0x730,"0 <= i_no && i_no < 128");
    m_Do_printf::OSPanic("d_save.cpp",0x730,&DAT_8034f7fb);
  }
  return (*(uint *)(&this->field_0x30 + (param_1 >> 5) * 4) & 1 << (param_1 & 0x1fU)) != 0;
}


/* __thiscall dSv_player_map_c::onTriforce(int) */

void __thiscall dSv_player_map_c::onTriforce(dSv_player_map_c *this,int param_1)

{
  bool bVar1;
  ulong uVar2;
  
  bVar1 = false;
  if ((-1 < param_1) && (param_1 < 8)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_save.cpp",0x752,"0 <= i_no && i_no < 8");
    m_Do_printf::OSPanic("d_save.cpp",0x752,&DAT_8034f7fb);
  }
  *(byte *)&this->field_0x81 = *(byte *)&this->field_0x81 | (byte)(1 << param_1);
  return;
}


/* __thiscall dSv_player_map_c::offTriforce(int) */

void __thiscall dSv_player_map_c::offTriforce(dSv_player_map_c *this,int param_1)

{
  bool bVar1;
  ulong uVar2;
  
  bVar1 = false;
  if ((-1 < param_1) && (param_1 < 8)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_save.cpp",0x760,"0 <= i_no && i_no < 8");
    m_Do_printf::OSPanic("d_save.cpp",0x760,&DAT_8034f7fb);
  }
  *(byte *)&this->field_0x81 = *(byte *)&this->field_0x81 & ~(byte)(1 << param_1);
  return;
}


/* __thiscall dSv_player_map_c::isTriforce(int) */

bool __thiscall dSv_player_map_c::isTriforce(dSv_player_map_c *this,int param_1)

{
  bool bVar1;
  ulong uVar2;
  
  bVar1 = false;
  if ((-1 < param_1) && (param_1 < 8)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_save.cpp",0x76e,"0 <= i_no && i_no < 8");
    m_Do_printf::OSPanic("d_save.cpp",0x76e,&DAT_8034f7fb);
  }
  return (1 << param_1 & 0xffU & (uint)*(byte *)&this->field_0x81) != 0;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dSv_player_map_c::getCollectMapNum(void) */

int __thiscall dSv_player_map_c::getCollectMapNum(dSv_player_map_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = 1;
  do {
    if ((((iVar2 != 0x23) && (iVar2 != 0x24)) && (iVar2 < 0x34)) &&
       (iVar1 = isGetMap(this,iVar2 + -1), iVar1 != 0)) {
      iVar3 = iVar3 + 1;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x3e);
  return iVar3;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dSv_player_map_c::onFmapBit(int,
                                          unsigned char) */

void __thiscall dSv_player_map_c::onFmapBit(dSv_player_map_c *this,int param_1,uchar param_2)

{
  ulong uVar1;
  int iVar2;
  
  if (7 < param_2) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_save.cpp",0x7a5,"0 <= i_no && i_no < 8");
    m_Do_printf::OSPanic("d_save.cpp",0x7a5,&DAT_8034f7fb);
  }
  iVar2 = &this->field_0x0 + param_1;
  *(byte *)(iVar2 + 0x40) = *(byte *)(iVar2 + 0x40) | (byte)(1 << param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dSv_player_map_c::isFmapBit(int,
                                          unsigned char) */

bool __thiscall dSv_player_map_c::isFmapBit(dSv_player_map_c *this,int param_1,uchar param_2)

{
  ulong uVar1;
  
  if (7 < param_2) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_save.cpp",0x7c3,"0 <= i_no && i_no < 8");
    m_Do_printf::OSPanic("d_save.cpp",0x7c3,&DAT_8034f7fb);
  }
  return (1 << param_2 & 0xffU & (uint)*(byte *)(&this->field_0x40 + param_1)) != 0;
}


/* __thiscall dSv_player_map_c::onSaveArriveGrid(int) */

void __thiscall dSv_player_map_c::onSaveArriveGrid(dSv_player_map_c *this,int param_1)

{
  bool bVar1;
  ulong uVar2;
  
  bVar1 = false;
  if ((-1 < param_1) && (param_1 < 0x31)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_save.cpp",0x7cc,"(no >= 0) && (no < 49)");
    m_Do_printf::OSPanic("d_save.cpp",0x7cc,&DAT_8034f7fb);
  }
  onFmapBit(this,param_1,'\0');
  return;
}


/* __thiscall dSv_player_map_c::isSaveArriveGrid(int) */

void __thiscall dSv_player_map_c::isSaveArriveGrid(dSv_player_map_c *this,int param_1)

{
  bool bVar1;
  ulong uVar2;
  
  bVar1 = false;
  if ((-1 < param_1) && (param_1 < 0x31)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_save.cpp",0x7da,"(no >= 0) && (no < 49)");
    m_Do_printf::OSPanic("d_save.cpp",0x7da,&DAT_8034f7fb);
  }
  isFmapBit(this,param_1,'\0');
  return;
}


/* __thiscall dSv_player_map_c::onSaveArriveGridForAgb(int) */

void __thiscall dSv_player_map_c::onSaveArriveGridForAgb(dSv_player_map_c *this,int param_1)

{
  bool bVar1;
  ulong uVar2;
  
  bVar1 = false;
  if ((-1 < param_1) && (param_1 < 0x31)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_save.cpp",0x7e1,"(no >= 0) && (no < 49)");
    m_Do_printf::OSPanic("d_save.cpp",0x7e1,&DAT_8034f7fb);
  }
  onFmapBit(this,param_1,'\x01');
  return;
}


/* __thiscall dSv_player_map_c::isSaveArriveGridForAgb(int) */

void __thiscall dSv_player_map_c::isSaveArriveGridForAgb(dSv_player_map_c *this,int param_1)

{
  bool bVar1;
  ulong uVar2;
  
  bVar1 = false;
  if ((-1 < param_1) && (param_1 < 0x31)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_save.cpp",0x7ed,"(no >= 0) && (no < 49)");
    m_Do_printf::OSPanic("d_save.cpp",0x7ed,&DAT_8034f7fb);
  }
  isFmapBit(this,param_1,'\x01');
  return;
}


/* __thiscall dSv_player_info_c::init(void) */

int __thiscall dSv_player_info_c::init(dSv_player_info_c *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  
  MSL_C.PPCEABI.bare.H::strcpy(&this->mPlayerName,&d_save::l_defaultName_6963);
  *(undefined2 *)&this->field_0x10 = 0;
  MSL_C.PPCEABI.bare.H::strcpy((char *)&this->field_0x25,&d_save::l_defaultName_6963);
  MSL_C.PPCEABI.bare.H::strcpy((char *)&this->field_0x36,&d_save::l_defaultName_6963);
  iVar1 = 0;
  *(undefined2 *)&this->field_0x12 = 0;
  this->mNumGamesCompleted = 0;
  iVar2 = 0;
  iVar3 = 0x11;
  do {
    *(undefined *)(&this->field_0x47 + iVar2) = 0;
    iVar2 = iVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  fVar4 = SComponent::cM_rndF(d_save::_6972);
  *(char *)&this->field_0x59 = (char)(int)fVar4;
  if (2 < *(byte *)&this->field_0x59) {
    *(undefined *)&this->field_0x59 = 2;
  }
  return iVar1;
}


/* __thiscall dSv_player_config_c::init(void) */

int __thiscall dSv_player_config_c::init(dSv_player_config_c *this)

{
  int iVar1;
  
  *(undefined *)this = 1;
  iVar1 = os::OSGetSoundMode();
  if (iVar1 == 0) {
    *(undefined *)&this->field_0x1 = 0;
    iVar1 = JAIZelBasic::setOutputMode(JAIZelBasic::zel_basic,0);
  }
  else {
    *(undefined *)&this->field_0x1 = 1;
    iVar1 = JAIZelBasic::setOutputMode(JAIZelBasic::zel_basic,1);
  }
  this->field_0x2 = 0;
  *(undefined *)&this->field_0x3 = 1;
  return iVar1;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dSv_player_config_c::checkVibration(void) */

undefined __thiscall dSv_player_config_c::checkVibration(dSv_player_config_c *this)

{
  if ((_sRumbleSupported & 0x80000000) != 0) {
    return d_com_inf_game::g_dComIfG_gameInfo._23555_1_;
  }
  return 0;
}


/* __thiscall dSv_player_priest_c::init(void) */

int __thiscall dSv_player_priest_c::init(dSv_player_priest_c *this,EVP_PKEY_CTX *ctx)

{
  this->field_0xf = '\0';
  return (int)this;
}


/* __thiscall dSv_player_priest_c::set(unsigned char,
                                       cXyz &,
                                       short,
                                       signed char) */

void __thiscall
dSv_player_priest_c::set
          (dSv_player_priest_c *this,uchar param_1,cXyz *param_2,short param_3,char param_4)

{
  this->field_0xf = param_1;
  (this->field_0x0).x = param_2->x;
  (this->field_0x0).y = param_2->y;
  (this->field_0x0).z = param_2->z;
  this->field_0xc = param_3;
  this->field_0xe = param_4;
  return;
}


/* __thiscall dSv_player_status_c_c::init(void) */

int __thiscall dSv_player_status_c_c::init(dSv_player_status_c_c *this,EVP_PKEY_CTX *ctx)

{
  return (int)this;
}


/* __thiscall dSv_player_c::init(void) */

int __thiscall dSv_player_c::init(dSv_player_c *this)

{
  int iVar1;
  
  dSv_player_status_a_c::init(&this->mStatusA);
  dSv_player_status_b_c::init(&this->mStatusB);
  dSv_player_return_place_c::init(&this->mReturnPlace);
  dSv_player_item_c::init(&this->mItem);
  dSv_player_get_item_c::init(&this->mGetItem);
  dSv_player_item_record_c::init(&this->mItemRecord);
  dSv_player_item_max_c::init(&this->mItemMax);
  dSv_player_bag_item_c::init(&this->mBagItem);
  dSv_player_get_bag_item_c::init(&this->mGetBagItem);
  dSv_player_bag_item_record_c::init(&this->mBagItemRecord);
  dSv_player_collect_c::init(&this->mCollect);
  dSv_player_map_c::init(&this->mMap);
  dSv_player_info_c::init(&this->mInfo);
  iVar1 = dSv_player_config_c::init(&this->mConfig);
  return iVar1;
}


/* __thiscall dSv_memBit_c::init(void) */

void __thiscall dSv_memBit_c::init(dSv_memBit_c *this)

{
  int iVar1;
  int iVar2;
  
  this->mTbox = 0;
  iVar1 = 0;
  iVar2 = 4;
  do {
    *(undefined4 *)((int)this->mSwitch + iVar1) = 0;
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  this->mItem = 0;
  iVar1 = 0;
  iVar2 = 2;
  do {
    *(undefined4 *)((int)this->mVisitedRoom + iVar1) = 0;
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  this->field_0x20 = 0;
  this->mDungeonItem = 0;
  return;
}


/* __thiscall dSv_memBit_c::onTbox(int) */

void __thiscall dSv_memBit_c::onTbox(dSv_memBit_c *this,int param_1)

{
  bool bVar1;
  ulong uVar2;
  
  bVar1 = false;
  if ((-1 < param_1) && (param_1 < 0x20)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_save.cpp",0x8cc,"0 <= i_no && i_no < 32");
    m_Do_printf::OSPanic("d_save.cpp",0x8cc,&DAT_8034f7fb);
  }
  this->mTbox = this->mTbox | 1 << param_1;
  return;
}


/* __thiscall dSv_memBit_c::isTbox(int) */

bool __thiscall dSv_memBit_c::isTbox(dSv_memBit_c *this,int i_no)

{
  bool bVar1;
  ulong uVar2;
  
  bVar1 = false;
  if ((-1 < i_no) && (i_no < 0x20)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_save.cpp",0x8e8,"0 <= i_no && i_no < 32");
    m_Do_printf::OSPanic("d_save.cpp",0x8e8,&DAT_8034f7fb);
  }
  return (this->mTbox & 1 << i_no) != 0;
}


/* __thiscall dSv_memBit_c::onSwitch(int) */

void __thiscall dSv_memBit_c::onSwitch(dSv_memBit_c *this,int switchNo)

{
  bool bVar1;
  ulong uVar2;
  
  bVar1 = false;
  if ((-1 < switchNo) && (switchNo < 0x80)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_save.cpp",0x907,"0 <= i_no && i_no < 128");
    m_Do_printf::OSPanic("d_save.cpp",0x907,&DAT_8034f7fb);
  }
  (this->mSwitch + (switchNo >> 5) + -1)[1] =
       (this->mSwitch + (switchNo >> 5) + -1)[1] | 1 << (switchNo & 0x1fU);
  return;
}


/* __thiscall dSv_memBit_c::offSwitch(int) */

void __thiscall dSv_memBit_c::offSwitch(dSv_memBit_c *this,int param_1)

{
  bool bVar1;
  ulong uVar2;
  
  bVar1 = false;
  if ((-1 < param_1) && (param_1 < 0x80)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_save.cpp",0x915,"0 <= i_no && i_no < 128");
    m_Do_printf::OSPanic("d_save.cpp",0x915,&DAT_8034f7fb);
  }
  (this->mSwitch + (param_1 >> 5) + -1)[1] =
       (this->mSwitch + (param_1 >> 5) + -1)[1] & ~(1 << (param_1 & 0x1fU));
  return;
}


/* __thiscall dSv_memBit_c::isSwitch(int) */

bool __thiscall dSv_memBit_c::isSwitch(dSv_memBit_c *this,int i_no)

{
  bool bVar1;
  ulong uVar2;
  
  bVar1 = false;
  if ((-1 < i_no) && (i_no < 0x80)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_save.cpp",0x923,"0 <= i_no && i_no < 128");
    m_Do_printf::OSPanic("d_save.cpp",0x923,&DAT_8034f7fb);
  }
  return (this->mSwitch[i_no >> 5] & 1 << (i_no & 0x1fU)) != 0;
}


/* __thiscall dSv_memBit_c::revSwitch(int) */

bool __thiscall dSv_memBit_c::revSwitch(dSv_memBit_c *this,int param_1)

{
  bool bVar1;
  ulong uVar2;
  int *piVar3;
  uint uVar4;
  
  bVar1 = false;
  if ((-1 < param_1) && (param_1 < 0x80)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_save.cpp",0x931,"0 <= i_no && i_no < 128");
    m_Do_printf::OSPanic("d_save.cpp",0x931,&DAT_8034f7fb);
  }
  uVar4 = 1 << (param_1 & 0x1fU);
  piVar3 = this->mSwitch + (param_1 >> 5) + -1;
  piVar3[1] = piVar3[1] ^ uVar4;
  return (piVar3[1] & uVar4) != 0;
}


/* __thiscall dSv_memBit_c::onItem(int) */

void __thiscall dSv_memBit_c::onItem(dSv_memBit_c *this,int param_1)

{
  bool bVar1;
  ulong uVar2;
  
  bVar1 = false;
  if ((-1 < param_1) && (param_1 < 0x40)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_save.cpp",0x944,"0 <= i_no && i_no < 64");
    m_Do_printf::OSPanic("d_save.cpp",0x944,&DAT_8034f7fb);
  }
  (this->mSwitch + (param_1 >> 5) + -1)[5] =
       (this->mSwitch + (param_1 >> 5) + -1)[5] | 1 << (param_1 & 0x1fU);
  return;
}


/* __thiscall dSv_memBit_c::isItem(int) */

bool __thiscall dSv_memBit_c::isItem(dSv_memBit_c *this,int i_no)

{
  bool bVar1;
  ulong uVar2;
  
  bVar1 = false;
  if ((-1 < i_no) && (i_no < 0x40)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_save.cpp",0x960,"0 <= i_no && i_no < 64");
    m_Do_printf::OSPanic("d_save.cpp",0x960,&DAT_8034f7fb);
  }
  return (this->mVisitedRoom[(i_no >> 5) + -1] & 1 << (i_no & 0x1fU)) != 0;
}


/* __thiscall dSv_memBit_c::onVisitedRoom(int) */

void __thiscall dSv_memBit_c::onVisitedRoom(dSv_memBit_c *this,int param_1)

{
  bool bVar1;
  ulong uVar2;
  
  bVar1 = false;
  if ((-1 < param_1) && (param_1 < 0x40)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_save.cpp",0x980,"0 <= i_no && i_no < 64");
    m_Do_printf::OSPanic("d_save.cpp",0x980,&DAT_8034f7fb);
  }
  (this->mSwitch + (param_1 >> 5) + -1)[6] =
       (this->mSwitch + (param_1 >> 5) + -1)[6] | 1 << (param_1 & 0x1fU);
  return;
}


/* __thiscall dSv_memBit_c::isVisitedRoom(int) */

bool __thiscall dSv_memBit_c::isVisitedRoom(dSv_memBit_c *this,int i_no)

{
  bool bVar1;
  ulong uVar2;
  
  bVar1 = false;
  if ((-1 < i_no) && (i_no < 0x40)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_save.cpp",0x99c,"0 <= i_no && i_no < 64");
    m_Do_printf::OSPanic("d_save.cpp",0x99c,&DAT_8034f7fb);
  }
  return (this->mVisitedRoom[i_no >> 5] & 1 << (i_no & 0x1fU)) != 0;
}


/* __thiscall dSv_memBit_c::onDungeonItem(int) */

void __thiscall dSv_memBit_c::onDungeonItem(dSv_memBit_c *this,int param_1)

{
  bool bVar1;
  ulong uVar2;
  
  bVar1 = false;
  if ((-1 < param_1) && (param_1 < 6)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_save.cpp",0x9bc,"0 <= i_no && i_no < 6");
    m_Do_printf::OSPanic("d_save.cpp",0x9bc,&DAT_8034f7fb);
  }
  this->mDungeonItem = this->mDungeonItem | (byte)(1 << param_1);
  return;
}


/* __thiscall dSv_memBit_c::isDungeonItem(int) */

bool __thiscall dSv_memBit_c::isDungeonItem(dSv_memBit_c *this,int i_no)

{
  bool bVar1;
  ulong uVar2;
  
  bVar1 = false;
  if ((-1 < i_no) && (i_no < 6)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_save.cpp",0x9d9,"0 <= i_no && i_no < 6");
    m_Do_printf::OSPanic("d_save.cpp",0x9d9,&DAT_8034f7fb);
  }
  return (1 << i_no & 0xffU & (uint)this->mDungeonItem) != 0;
}


/* __thiscall dSv_ocean_c::init(void) */

int __thiscall dSv_ocean_c::init(dSv_ocean_c *this)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 0x32;
  do {
    *(undefined2 *)((int)this->mBits + iVar1) = 0;
    iVar1 = iVar1 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return (int)this;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dSv_ocean_c::onOceanSvBit(unsigned char,
                                        unsigned short) */

void __thiscall dSv_ocean_c::onOceanSvBit(dSv_ocean_c *this,uchar param_1,ushort param_2)

{
  ulong uVar1;
  
  if (0x31 < param_1) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_save.cpp",0xa50,"(0 <= i_grid) && (i_grid <= 0x31)");
    m_Do_printf::OSPanic("d_save.cpp",0xa50,&DAT_8034f7fb);
  }
  if (0xf < param_2) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_save.cpp",0xa51,"(0 <= i_bit) && (i_bit < 16)");
    m_Do_printf::OSPanic("d_save.cpp",0xa51,&DAT_8034f7fb);
  }
  this->mBits[param_1] = this->mBits[param_1] | (ushort)(1 << param_2);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dSv_ocean_c::isOceanSvBit(unsigned char,
                                        unsigned short) */

bool __thiscall dSv_ocean_c::isOceanSvBit(dSv_ocean_c *this,uchar param_1,ushort param_2)

{
  ulong uVar1;
  
  if (0x31 < param_1) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_save.cpp",0xa70,"(0 <= i_grid) && (i_grid <= 0x31)");
    m_Do_printf::OSPanic("d_save.cpp",0xa70,&DAT_8034f7fb);
  }
  if (0xf < param_2) {
    uVar1 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar1,"d_save.cpp",0xa71,"(0 <= i_bit) && (i_bit < 16)");
    m_Do_printf::OSPanic("d_save.cpp",0xa71,&DAT_8034f7fb);
  }
  return (1 << param_2 & 0xffffU & (uint)(ushort)this->mBits[param_1]) != 0;
}


/* __thiscall dSv_event_c::init(void) */

int __thiscall dSv_event_c::init(dSv_event_c *this)

{
  int iVar1;
  
  iVar1 = 0x100;
  do {
    this->mBits[0] = 0;
    this = (dSv_event_c *)(this->mBits + 1);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  iVar1 = d_save_init::setInitEventBit();
  return iVar1;
}


/* __thiscall dSv_event_c::onEventBit(unsigned short) */

void __thiscall dSv_event_c::onEventBit(dSv_event_c *this,ushort param_1)

{
  this->mBits[param_1 >> 8] = this->mBits[param_1 >> 8] | (byte)param_1;
  return;
}


/* __thiscall dSv_event_c::offEventBit(unsigned short) */

void __thiscall dSv_event_c::offEventBit(dSv_event_c *this,ushort param_1)

{
  this->mBits[param_1 >> 8] = this->mBits[param_1 >> 8] & ~(byte)param_1;
  return;
}


/* __thiscall dSv_event_c::isEventBit(unsigned short) */

undefined4 __thiscall dSv_event_c::isEventBit(dSv_event_c *this,ushort param_1)

{
  if ((param_1 & 0xff & (ushort)this->mBits[param_1 >> 8]) != 0) {
    return 1;
  }
  return 0;
}


/* __thiscall dSv_event_c::setEventReg(unsigned short,
                                       unsigned char) */

void __thiscall dSv_event_c::setEventReg(dSv_event_c *this,ushort param_1,byte param_2)

{
  uint uVar1;
  
  uVar1 = (uint)(param_1 >> 8);
  this->mBits[uVar1] = this->mBits[uVar1] & ~(byte)param_1;
  this->mBits[uVar1] = this->mBits[uVar1] | param_2;
  return;
}


/* __thiscall dSv_event_c::getEventReg(unsigned short) */

ushort __thiscall dSv_event_c::getEventReg(dSv_event_c *this,ushort param_1)

{
  return param_1 & 0xff & (ushort)this->mBits[param_1 >> 8];
}


/* __thiscall dSv_reserve_c::init(void) */

int __thiscall dSv_reserve_c::init(dSv_reserve_c *this,EVP_PKEY_CTX *ctx)

{
  int iVar1;
  
  iVar1 = 0x50;
  do {
    *this = (dSv_reserve_c)0x0;
    this = this + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return (int)this;
}


/* __thiscall dSv_memory_c::init(void) */

int __thiscall dSv_memory_c::init(dSv_memory_c *this)

{
  dSv_memBit_c::init(&this->mBits);
  return (int)this;
}


/* __thiscall dSv_danBit_c::init(signed char) */

int __thiscall dSv_danBit_c::init(dSv_danBit_c *this,char param_1)

{
  if (param_1 != this->field_0x0) {
    this->field_0x4 = 0;
    this->field_0x8 = 0;
    this->field_0x0 = param_1;
    *(undefined *)&this->field_0x1 = 0;
    return 1;
  }
  return 0;
}


/* __thiscall dSv_danBit_c::onSwitch(int) */

void __thiscall dSv_danBit_c::onSwitch(dSv_danBit_c *this,int switchNo)

{
  bool bVar1;
  ulong uVar2;
  
  bVar1 = false;
  if ((-1 < switchNo) && (switchNo < 0x40)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_save.cpp",0xb01,"0 <= i_no && i_no < 64");
    m_Do_printf::OSPanic("d_save.cpp",0xb01,&DAT_8034f7fb);
  }
  *(uint *)(&this->field_0x0 + (switchNo >> 5) * 4 + 4) =
       *(uint *)(&this->field_0x0 + (switchNo >> 5) * 4 + 4) | 1 << (switchNo & 0x1fU);
  return;
}


/* __thiscall dSv_danBit_c::offSwitch(int) */

void __thiscall dSv_danBit_c::offSwitch(dSv_danBit_c *this,int param_1)

{
  bool bVar1;
  ulong uVar2;
  
  bVar1 = false;
  if ((-1 < param_1) && (param_1 < 0x40)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_save.cpp",0xb0f,"0 <= i_no && i_no < 64");
    m_Do_printf::OSPanic("d_save.cpp",0xb0f,&DAT_8034f7fb);
  }
  *(uint *)(&this->field_0x0 + (param_1 >> 5) * 4 + 4) =
       *(uint *)(&this->field_0x0 + (param_1 >> 5) * 4 + 4) & ~(1 << (param_1 & 0x1fU));
  return;
}


/* __thiscall dSv_danBit_c::isSwitch(int) */

bool __thiscall dSv_danBit_c::isSwitch(dSv_danBit_c *this,int param_1)

{
  bool bVar1;
  ulong uVar2;
  
  bVar1 = false;
  if ((-1 < param_1) && (param_1 < 0x40)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_save.cpp",0xb1d,"0 <= i_no && i_no < 64");
    m_Do_printf::OSPanic("d_save.cpp",0xb1d,&DAT_8034f7fb);
  }
  return ((&this->field_0x4)[param_1 >> 5] & 1 << (param_1 & 0x1fU)) != 0;
}


/* __thiscall dSv_danBit_c::revSwitch(int) */

bool __thiscall dSv_danBit_c::revSwitch(dSv_danBit_c *this,int param_1)

{
  bool bVar1;
  ulong uVar2;
  char *pcVar3;
  uint uVar4;
  
  bVar1 = false;
  if ((-1 < param_1) && (param_1 < 0x40)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_save.cpp",0xb2b,"0 <= i_no && i_no < 64");
    m_Do_printf::OSPanic("d_save.cpp",0xb2b,&DAT_8034f7fb);
  }
  uVar4 = 1 << (param_1 & 0x1fU);
  pcVar3 = &this->field_0x0 + (param_1 >> 5) * 4;
  *(uint *)(pcVar3 + 4) = *(uint *)(pcVar3 + 4) ^ uVar4;
  return (*(uint *)(pcVar3 + 4) & uVar4) != 0;
}


/* __thiscall dSv_zoneBit_c::init(void) */

int __thiscall dSv_zoneBit_c::init(dSv_zoneBit_c *this)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 3;
  do {
    *(undefined2 *)((int)this->mSwitch + iVar1) = 0;
    iVar1 = iVar1 + 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  this->mItem = 0;
  return (int)this;
}


/* __thiscall dSv_zoneBit_c::clearRoomSwitch(void) */

void __thiscall dSv_zoneBit_c::clearRoomSwitch(dSv_zoneBit_c *this)

{
  this->mSwitch[2] = 0;
  return;
}


/* __thiscall dSv_zoneBit_c::onSwitch(int) */

void __thiscall dSv_zoneBit_c::onSwitch(dSv_zoneBit_c *this,int param_1)

{
  bool bVar1;
  ulong uVar2;
  
  bVar1 = false;
  if ((-1 < param_1) && (param_1 < 0x30)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_save.cpp",0xb57,"0 <= i_no && i_no < SWITCH_MAX");
    m_Do_printf::OSPanic("d_save.cpp",0xb57,&DAT_8034f7fb);
  }
  this->mSwitch[param_1 >> 4] = this->mSwitch[param_1 >> 4] | (ushort)(1 << (param_1 & 0xfU));
  return;
}


/* __thiscall dSv_zoneBit_c::offSwitch(int) */

void __thiscall dSv_zoneBit_c::offSwitch(dSv_zoneBit_c *this,int param_1)

{
  bool bVar1;
  ulong uVar2;
  
  bVar1 = false;
  if ((-1 < param_1) && (param_1 < 0x30)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_save.cpp",0xb65,"0 <= i_no && i_no < SWITCH_MAX");
    m_Do_printf::OSPanic("d_save.cpp",0xb65,&DAT_8034f7fb);
  }
  this->mSwitch[param_1 >> 4] = this->mSwitch[param_1 >> 4] & ~(ushort)(1 << (param_1 & 0xfU));
  return;
}


/* __thiscall dSv_zoneBit_c::isSwitch(int) */

bool __thiscall dSv_zoneBit_c::isSwitch(dSv_zoneBit_c *this,int param_1)

{
  bool bVar1;
  ulong uVar2;
  
  bVar1 = false;
  if ((-1 < param_1) && (param_1 < 0x30)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_save.cpp",0xb73,"0 <= i_no && i_no < SWITCH_MAX");
    m_Do_printf::OSPanic("d_save.cpp",0xb73,&DAT_8034f7fb);
  }
  return (1 << (param_1 & 0xfU) & (uint)(ushort)this->mSwitch[param_1 >> 4]) != 0;
}


/* __thiscall dSv_zoneBit_c::revSwitch(int) */

bool __thiscall dSv_zoneBit_c::revSwitch(dSv_zoneBit_c *this,int param_1)

{
  bool bVar1;
  ulong uVar2;
  int iVar3;
  uint uVar4;
  
  bVar1 = false;
  if ((-1 < param_1) && (param_1 < 0x30)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_save.cpp",0xb81,"0 <= i_no && i_no < SWITCH_MAX");
    m_Do_printf::OSPanic("d_save.cpp",0xb81,&DAT_8034f7fb);
  }
  iVar3 = param_1 >> 4;
  uVar4 = 1 << (param_1 & 0xfU);
  this->mSwitch[iVar3] = this->mSwitch[iVar3] ^ (ushort)uVar4;
  return (uVar4 & (ushort)this->mSwitch[iVar3]) != 0;
}


/* __thiscall dSv_zoneBit_c::onItem(int) */

void __thiscall dSv_zoneBit_c::onItem(dSv_zoneBit_c *this,int param_1)

{
  bool bVar1;
  ulong uVar2;
  
  bVar1 = false;
  if ((-1 < param_1) && (param_1 < 0x10)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_save.cpp",0xb94,"0 <= i_no && i_no < 16");
    m_Do_printf::OSPanic("d_save.cpp",0xb94,&DAT_8034f7fb);
  }
  this->mItem = this->mItem | (ushort)(1 << param_1);
  return;
}


/* __thiscall dSv_zoneBit_c::isItem(int) */

bool __thiscall dSv_zoneBit_c::isItem(dSv_zoneBit_c *this,int param_1)

{
  bool bVar1;
  ulong uVar2;
  
  bVar1 = false;
  if ((-1 < param_1) && (param_1 < 0x10)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_save.cpp",0xbb0,"0 <= i_no && i_no < 16");
    m_Do_printf::OSPanic("d_save.cpp",0xbb0,&DAT_8034f7fb);
  }
  return ((uint)(ushort)this->mItem & 1 << param_1) != 0;
}


/* __thiscall dSv_zoneActor_c::init(void) */

int __thiscall dSv_zoneActor_c::init(dSv_zoneActor_c *this)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 0x10;
  do {
    *(undefined4 *)((int)this->mActorFlags + iVar1) = 0;
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return (int)this;
}


/* __thiscall dSv_zoneActor_c::on(int) */

void __thiscall dSv_zoneActor_c::on(dSv_zoneActor_c *this,int param_1)

{
  bool bVar1;
  ulong uVar2;
  
  bVar1 = false;
  if ((-1 < param_1) && (param_1 < 0x200)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_save.cpp",0xbdd,"0 <= i_id && i_id < ACTOR_MAX");
    m_Do_printf::OSPanic("d_save.cpp",0xbdd,&DAT_8034f7fb);
  }
  this->mActorFlags[param_1 >> 5] = this->mActorFlags[param_1 >> 5] | 1 << (param_1 & 0x1fU);
  return;
}


/* __thiscall dSv_zoneActor_c::is(int) */

bool __thiscall dSv_zoneActor_c::is(dSv_zoneActor_c *this,int param_1)

{
  bool bVar1;
  ulong uVar2;
  
  bVar1 = false;
  if ((-1 < param_1) && (param_1 < 0x200)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert(uVar2,"d_save.cpp",0xbf9,"0 <= i_id && i_id < ACTOR_MAX");
    m_Do_printf::OSPanic("d_save.cpp",0xbf9,&DAT_8034f7fb);
  }
  return (1 << (param_1 & 0x1fU) & this->mActorFlags[param_1 >> 5]) != 0;
}


/* __thiscall dSv_zone_c::init(int) */

int __thiscall dSv_zone_c::init(dSv_zone_c *this,int param_1)

{
  int iVar1;
  
  this->mRoomIdx = (byte)param_1;
  dSv_zoneBit_c::init(&this->mZoneBit);
  iVar1 = dSv_zoneActor_c::init(&this->mZoneActor);
  return iVar1;
}


/* __thiscall dSv_restart_c::setRoom(cXyz const &,
                                     short,
                                     signed char) */

void __thiscall dSv_restart_c::setRoom(dSv_restart_c *this,cXyz *param_1,short param_2,char param_3)

{
  this->mRestartCode = param_3;
  (this->mLinkRestartPos).x = param_1->x;
  (this->mLinkRestartPos).y = param_1->y;
  (this->mLinkRestartPos).z = param_1->z;
  this->mParameter = param_2;
  return;
}


/* __thiscall dSv_restart_c::setRestartOption(signed char) */

void __thiscall dSv_restart_c::setRestartOption(dSv_restart_c *this,char param_1)

{
  cXyz local_18;
  
  if (d_save::init_7551 == 0) {
    d_save::l_offsetPos_7549.x = d_save::_7558;
    d_save::l_offsetPos_7549.y = d_save::_4195;
    d_save::l_offsetPos_7549.z = d_save::_4195;
    Runtime.PPCEABI.H::__register_global_object
              (&d_save::l_offsetPos_7549,::cXyz::_cXyz,&d_save::_7550);
    d_save::init_7551 = 1;
  }
  local_18.x = (this->mLinkRestartPos).x;
  local_18.y = (this->mLinkRestartPos).y;
  local_18.z = (this->mLinkRestartPos).z;
  SComponent::cLib_offsetPos(&local_18,&local_18,this->mParameter,&d_save::l_offsetPos_7549);
  setRestartOption(this,param_1,&local_18,this->mParameter,this->mRestartCode);
  return;
}


/* __thiscall dSv_restart_c::setRestartOption(signed char,
                                              cXyz *,
                                              short,
                                              signed char) */

void __thiscall
dSv_restart_c::setRestartOption(dSv_restart_c *this,char param_1,cXyz *pos,short rotY,char roomNo)

{
  (this->mPos).x = pos->x;
  (this->mPos).y = pos->y;
  (this->mPos).z = pos->z;
  this->mRotY = rotY;
  this->mRoomNo = roomNo;
  this->field_0x4 = -1;
  this->field_0x1 = param_1;
  return;
}


/* __thiscall dSv_turnRestart_c::set(cXyz const &,
                                     short,
                                     signed char,
                                     unsigned long,
                                     cXyz const &,
                                     short,
                                     int) */

void __thiscall
dSv_turnRestart_c::set
          (dSv_turnRestart_c *this,cXyz *pos,short rotY,char param_3,ulong param_4,cXyz *param_5,
          short param_6,int param_7)

{
  (this->mPos).x = pos->x;
  (this->mPos).y = pos->y;
  (this->mPos).z = pos->z;
  this->mRotY = rotY;
  this->mRoomNo = param_3;
  this->mParamData = param_4;
  this->field_0x13 = 0;
  (this->field_0x24).x = param_5->x;
  (this->field_0x24).y = param_5->y;
  (this->field_0x24).z = param_5->z;
  this->field_0x30 = param_6;
  this->field_0x34 = param_7;
  return;
}


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall dSv_info_c::init(void) */

int __thiscall dSv_info_c::init(dSv_info_c *this)

{
  int iVar1;
  
  dSv_save_c::init(&this->mSave);
  dSv_memory_c::init(&this->mMemory);
  dSv_danBit_c::init(&this->mDanBit,-1);
  initZone(this);
  iVar1 = dSv_event_c::init(&this->mEvent);
  _ship_race_rupee = 0;
  _ship_race_result = 0;
  return iVar1;
}


/* WARNING: Inlined function: FUN_80328f10 */
/* WARNING: Inlined function: FUN_80328f5c */
/* __thiscall dSv_info_c::reinit(void) */

void __thiscall dSv_info_c::reinit(dSv_info_c *this)

{
  undefined uVar1;
  byte bVar2;
  undefined uVar3;
  undefined uVar4;
  byte bVar5;
  undefined uVar6;
  byte *pbVar7;
  ushort uVar8;
  byte *pbVar9;
  int iVar10;
  uint uVar11;
  char acStack88 [28];
  
  pbVar7 = (byte *)JKernel::operator_new__(0x11);
  uVar11 = 0;
  iVar10 = 0;
  pbVar9 = pbVar7;
  do {
    uVar8 = dSv_event_c::getEventReg
                      (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,
                       *(ushort *)((int)&d_save::l_holdEventReg_7593 + iVar10));
    *pbVar9 = (byte)uVar8;
    bVar2 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mInfo.mNumGamesCompleted;
    uVar11 = uVar11 + 1;
    pbVar9 = pbVar9 + 1;
    iVar10 = iVar10 + 2;
  } while (uVar11 < 0x11);
  MSL_C.PPCEABI.bare.H::strcpy
            (acStack88,&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mInfo.mPlayerName);
  uVar6 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mConfig._3_1_;
  bVar5 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mConfig.field_0x2;
  uVar4 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mConfig._1_1_;
  uVar3 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mConfig._0_1_;
  uVar1 = d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._2_1_;
  uVar8 = dSv_event_c::getEventReg(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x89ff);
  init(this);
  uVar11 = 0;
  iVar10 = 0;
  do {
    dSv_event_c::setEventReg
              (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,
               *(ushort *)((int)&d_save::l_holdEventReg_7593 + iVar10),*pbVar7);
    uVar11 = uVar11 + 1;
    pbVar7 = pbVar7 + 1;
    iVar10 = iVar10 + 2;
  } while (uVar11 < 0x11);
  uVar11 = 0;
  iVar10 = 0;
  do {
    dSv_event_c::onEventBit
              (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,
               *(ushort *)((int)&d_save::l_onEventBit_7604 + iVar10));
    uVar11 = uVar11 + 1;
    iVar10 = iVar10 + 2;
  } while (uVar11 < 5);
  dSv_event_c::setEventReg(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0xc407,7);
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mInfo.mNumGamesCompleted = bVar2;
  dSv_memBit_c::onTbox
            ((dSv_memBit_c *)(d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mMemory + 0xb),0);
  dSv_memBit_c::onSwitch
            ((dSv_memBit_c *)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mMemory,0x47);
  dSv_memBit_c::onSwitch
            ((dSv_memBit_c *)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mMemory,0x5e);
  MSL_C.PPCEABI.bare.H::strcpy
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mInfo.mPlayerName,acStack88);
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mInfo._89_1_ = 3;
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.field_0x8 = DeluxePictoBox;
  d_com_inf_game::g_dComIfG_gameInfo._23517_1_ = 8;
  d_com_inf_game::g_dComIfG_gameInfo._23518_1_ = 0x26;
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mConfig._0_1_ = uVar3;
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mConfig._1_1_ = uVar4;
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mConfig.field_0x2 = bVar5;
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mConfig._3_1_ = uVar6;
  dSv_player_get_item_c::onItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,8,'\0');
  dSv_player_get_item_c::onItem
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem,8,'\x01');
  d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord._2_1_ = uVar1;
  dSv_event_c::setEventReg
            (&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent,0x89ff,(byte)uVar8);
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dSv_save_c::init(void) */

int __thiscall dSv_save_c::init(dSv_save_c *this)

{
  int iVar1;
  int iVar2;
  
  dSv_player_c::init(&this->mPlayer);
  iVar1 = 0;
  iVar2 = 0;
  do {
    dSv_memory_c::init((dSv_memory_c *)((int)this->mMemory[0].mBits.mSwitch + iVar2 + -4));
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x24;
  } while (iVar1 < 0x10);
  dSv_ocean_c::init(&this->mOcean);
  iVar1 = dSv_event_c::init(&this->mEvent);
  return iVar1;
}


/* __thiscall dSv_info_c::getSave(int) */

void __thiscall dSv_info_c::getSave(dSv_info_c *this,int param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  ulong uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  
  bVar1 = false;
  if ((-1 < param_1) && (param_1 < 0x10)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar5,"d_save.cpp",0xd07,"0 <= i_stageNo && i_stageNo < dSv_save_c::STAGE_MAX");
    m_Do_printf::OSPanic("d_save.cpp",0xd07,&DAT_8034f7fb);
  }
  iVar8 = 4;
  puVar2 = (undefined4 *)&(this->mSave).mMemory[param_1 + -1].mBits.field_0x20;
  puVar3 = (undefined4 *)&this->field_0x774;
  do {
    puVar7 = puVar3;
    puVar6 = puVar2;
    uVar4 = puVar6[2];
    puVar7[1] = puVar6[1];
    puVar7[2] = uVar4;
    iVar8 = iVar8 + -1;
    puVar2 = puVar6 + 2;
    puVar3 = puVar7 + 2;
  } while (iVar8 != 0);
  puVar7[3] = puVar6[3];
  return;
}


/* __thiscall dSv_info_c::putSave(int) */

void __thiscall dSv_info_c::putSave(dSv_info_c *this,int param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  ulong uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 uStack60;
  undefined4 local_38 [12];
  
  bVar1 = false;
  if ((-1 < param_1) && (param_1 < 0x10)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar5 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar5,"d_save.cpp",0xd17,"0 <= i_stageNo && i_stageNo < dSv_save_c::STAGE_MAX");
    m_Do_printf::OSPanic("d_save.cpp",0xd17,&DAT_8034f7fb);
  }
  iVar8 = 4;
  puVar2 = (undefined4 *)&this->field_0x774;
  puVar3 = &uStack60;
  do {
    puVar7 = puVar3;
    puVar6 = puVar2;
    uVar4 = puVar6[2];
    puVar7[1] = puVar6[1];
    puVar7[2] = uVar4;
    iVar8 = iVar8 + -1;
    puVar2 = puVar6 + 2;
    puVar3 = puVar7 + 2;
  } while (iVar8 != 0);
  puVar7[3] = puVar6[3];
  iVar8 = 4;
  puVar2 = &uStack60;
  puVar3 = (undefined4 *)&(this->mSave).mMemory[param_1 + -1].mBits.field_0x20;
  do {
    puVar7 = puVar3;
    puVar6 = puVar2;
    uVar4 = puVar6[2];
    puVar7[1] = puVar6[1];
    puVar7[2] = uVar4;
    iVar8 = iVar8 + -1;
    puVar2 = puVar6 + 2;
    puVar3 = puVar7 + 2;
  } while (iVar8 != 0);
  puVar7[3] = puVar6[3];
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dSv_info_c::initZone(void) */

void __thiscall dSv_info_c::initZone(dSv_info_c *this)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 0;
  do {
    dSv_zone_c::init((dSv_zone_c *)(&this->mZone[0].mRoomIdx + iVar2),-1);
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x4c;
  } while (iVar1 < 0x20);
  return;
}


/* __thiscall dSv_info_c::createZone(int) */

int __thiscall dSv_info_c::createZone(dSv_info_c *this,int param_1)

{
  dSv_zone_c *this_00;
  int iVar1;
  int iVar2;
  
  this_00 = this->mZone;
  iVar1 = 0;
  iVar2 = 0x20;
  do {
    if ((char)this_00->mRoomIdx < '\0') {
      dSv_zone_c::init(this_00,param_1);
      return iVar1;
    }
    this_00 = this_00 + 1;
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return -1;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dSv_info_c::onSwitch(int,
                                   int) */

void __thiscall dSv_info_c::onSwitch(dSv_info_c *this,int switchNo,int roomNo)

{
  bool bVar1;
  ulong uVar2;
  int zoneId;
  
  bVar1 = false;
  if ((((-1 < switchNo) && (switchNo < 0xf0)) || (switchNo == -1)) || (switchNo == 0xff)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar2,"d_save.cpp",0xd53,
               "(0 <= i_no && i_no < (MEMORY_SWITCH+ DAN_SWITCH+ ZONE_SWITCH)) || i_no == -1 || i_no == 255"
              );
    m_Do_printf::OSPanic("d_save.cpp",0xd53,&DAT_8034f7fb);
  }
  if ((switchNo != -1) && (switchNo != 0xff)) {
    if (switchNo < 0x80) {
      dSv_memBit_c::onSwitch((dSv_memBit_c *)&this->mMemory,switchNo);
    }
    else {
      if (switchNo < 0xc0) {
        dSv_danBit_c::onSwitch(&this->mDanBit,switchNo + -0x80);
      }
      else {
        bVar1 = false;
        if ((-1 < roomNo) && (roomNo < 0x40)) {
          bVar1 = true;
        }
        if (!bVar1) {
          uVar2 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar2,"d_save.cpp",0xd60,"0 <= i_roomNo && i_roomNo < 64");
          m_Do_printf::OSPanic("d_save.cpp",0xd60,&DAT_8034f7fb);
        }
        zoneId = dStage_roomControl_c::getZoneNo(roomNo);
        bVar1 = false;
        if ((-1 < zoneId) && (zoneId < 0x20)) {
          bVar1 = true;
        }
        if (!bVar1) {
          uVar2 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar2,"d_save.cpp",0xd62,"0 <= zoneId && zoneId < ZONE_MAX");
          m_Do_printf::OSPanic("d_save.cpp",0xd62,&DAT_8034f7fb);
        }
        dSv_zoneBit_c::onSwitch(&this->mZone[zoneId].mZoneBit,switchNo + -0xc0);
      }
    }
  }
  return;
}


namespace dStage_roomControl_c {

/* __thiscall getZoneNo(int) */

int getZoneNo(int roomNo)

{
  return (int)(char)mStatus[roomNo].mZoneNo;
}

}

/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dSv_info_c::offSwitch(int,
                                    int) */

void __thiscall dSv_info_c::offSwitch(dSv_info_c *this,int param_1,int param_2)

{
  bool bVar1;
  ulong uVar2;
  int iVar3;
  
  bVar1 = false;
  if ((((-1 < param_1) && (param_1 < 0xf0)) || (param_1 == -1)) || (param_1 == 0xff)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar2,"d_save.cpp",0xd78,
               "(0 <= i_no && i_no < (MEMORY_SWITCH+ DAN_SWITCH+ ZONE_SWITCH)) || i_no == -1 || i_no == 255"
              );
    m_Do_printf::OSPanic("d_save.cpp",0xd78,&DAT_8034f7fb);
  }
  if ((param_1 != -1) && (param_1 != 0xff)) {
    if (param_1 < 0x80) {
      dSv_memBit_c::offSwitch((dSv_memBit_c *)&this->mMemory,param_1);
    }
    else {
      if (param_1 < 0xc0) {
        dSv_danBit_c::offSwitch(&this->mDanBit,param_1 + -0x80);
      }
      else {
        bVar1 = false;
        if ((-1 < param_2) && (param_2 < 0x40)) {
          bVar1 = true;
        }
        if (!bVar1) {
          uVar2 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar2,"d_save.cpp",0xd85,"0 <= i_roomNo && i_roomNo < 64");
          m_Do_printf::OSPanic("d_save.cpp",0xd85,&DAT_8034f7fb);
        }
        iVar3 = dStage_roomControl_c::getZoneNo(param_2);
        bVar1 = false;
        if ((-1 < iVar3) && (iVar3 < 0x20)) {
          bVar1 = true;
        }
        if (!bVar1) {
          uVar2 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar2,"d_save.cpp",0xd87,"0 <= zoneNo && zoneNo < ZONE_MAX");
          m_Do_printf::OSPanic("d_save.cpp",0xd87,&DAT_8034f7fb);
        }
        dSv_zoneBit_c::offSwitch(&this->mZone[iVar3].mZoneBit,param_1 + -0xc0);
      }
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dSv_info_c::isSwitch(int,
                                   int) */

bool __thiscall dSv_info_c::isSwitch(dSv_info_c *this,int switchIndex,int roomNo)

{
  bool bVar1;
  undefined uVar4;
  ulong uVar2;
  int iVar3;
  
  if ((switchIndex == -1) || (switchIndex == 0xff)) {
    uVar4 = 0;
  }
  else {
    if (switchIndex < 0x80) {
      uVar4 = dSv_memBit_c::isSwitch((dSv_memBit_c *)&this->mMemory,switchIndex);
    }
    else {
      if (switchIndex < 0xc0) {
        uVar4 = dSv_danBit_c::isSwitch(&this->mDanBit,switchIndex + -0x80);
      }
      else {
        bVar1 = false;
        if ((-1 < roomNo) && (roomNo < 0x40)) {
          bVar1 = true;
        }
        if (!bVar1) {
          uVar2 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar2,"d_save.cpp",0xdb5,"0 <= i_roomNo && i_roomNo < 64");
          m_Do_printf::OSPanic("d_save.cpp",0xdb5,&DAT_8034f7fb);
        }
        iVar3 = dStage_roomControl_c::getZoneNo(roomNo);
        bVar1 = false;
        if ((-1 < iVar3) && (iVar3 < 0x20)) {
          bVar1 = true;
        }
        if (!bVar1) {
          uVar2 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar2,"d_save.cpp",0xdb7,"0 <= zoneNo && zoneNo < ZONE_MAX");
          m_Do_printf::OSPanic("d_save.cpp",0xdb7,&DAT_8034f7fb);
        }
        uVar4 = dSv_zoneBit_c::isSwitch(&this->mZone[iVar3].mZoneBit,switchIndex + -0xc0);
      }
    }
  }
  return (bool)uVar4;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dSv_info_c::revSwitch(int,
                                    int) */

undefined4 __thiscall dSv_info_c::revSwitch(dSv_info_c *this,int param_1,int param_2)

{
  bool bVar1;
  ulong uVar2;
  undefined4 uVar3;
  int iVar4;
  
  bVar1 = false;
  if ((((-1 < param_1) && (param_1 < 0xf0)) || (param_1 == -1)) || (param_1 == 0xff)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar2,"d_save.cpp",0xdcc,
               "(0 <= i_no && i_no < (MEMORY_SWITCH+ DAN_SWITCH+ ZONE_SWITCH)) || i_no == -1 || i_no == 255"
              );
    m_Do_printf::OSPanic("d_save.cpp",0xdcc,&DAT_8034f7fb);
  }
  if ((param_1 == -1) || (param_1 == 0xff)) {
    uVar3 = 0;
  }
  else {
    if (param_1 < 0x80) {
      uVar3 = dSv_memBit_c::revSwitch((dSv_memBit_c *)&this->mMemory,param_1);
    }
    else {
      if (param_1 < 0xc0) {
        uVar3 = dSv_danBit_c::revSwitch(&this->mDanBit,param_1 + -0x80);
      }
      else {
        bVar1 = false;
        if ((-1 < param_2) && (param_2 < 0x40)) {
          bVar1 = true;
        }
        if (!bVar1) {
          uVar2 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar2,"d_save.cpp",0xdd8,"0 <= i_roomNo && i_roomNo < 64");
          m_Do_printf::OSPanic("d_save.cpp",0xdd8,&DAT_8034f7fb);
        }
        iVar4 = dStage_roomControl_c::getZoneNo(param_2);
        bVar1 = false;
        if ((-1 < iVar4) && (iVar4 < 0x20)) {
          bVar1 = true;
        }
        if (!bVar1) {
          uVar2 = JUTAssertion::getSDevice();
          JUTAssertion::showAssert(uVar2,"d_save.cpp",0xdda,"0 <= zoneNo && zoneNo < ZONE_MAX");
          m_Do_printf::OSPanic("d_save.cpp",0xdda,&DAT_8034f7fb);
        }
        uVar3 = dSv_zoneBit_c::revSwitch(&this->mZone[iVar4].mZoneBit,param_1 + -0xc0);
      }
    }
  }
  return uVar3;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dSv_info_c::onItem(int,
                                 int) */

void __thiscall dSv_info_c::onItem(dSv_info_c *this,int param_1,int param_2)

{
  bool bVar1;
  ulong uVar2;
  int iVar3;
  
  bVar1 = false;
  if ((((-1 < param_1) && (param_1 < 0x50)) || (param_1 == -1)) || (param_1 == 0x7f)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar2,"d_save.cpp",0xded,
               "(0 <= i_no && i_no < (MEMORY_ITEM+ZONE_ITEM)) || i_no == -1 || i_no == 127");
    m_Do_printf::OSPanic("d_save.cpp",0xded,&DAT_8034f7fb);
  }
  if ((param_1 != -1) && (param_1 != 0x7f)) {
    if (param_1 < 0x40) {
      dSv_memBit_c::onItem((dSv_memBit_c *)&this->mMemory,param_1);
    }
    else {
      bVar1 = false;
      if ((-1 < param_2) && (param_2 < 0x40)) {
        bVar1 = true;
      }
      if (!bVar1) {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar2,"d_save.cpp",0xdf7,"0 <= i_roomNo && i_roomNo < 64");
        m_Do_printf::OSPanic("d_save.cpp",0xdf7,&DAT_8034f7fb);
      }
      iVar3 = dStage_roomControl_c::getZoneNo(param_2);
      bVar1 = false;
      if ((-1 < iVar3) && (iVar3 < 0x20)) {
        bVar1 = true;
      }
      if (!bVar1) {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar2,"d_save.cpp",0xdf9,"0 <= zoneNo && zoneNo < ZONE_MAX");
        m_Do_printf::OSPanic("d_save.cpp",0xdf9,&DAT_8034f7fb);
      }
      dSv_zoneBit_c::onItem(&this->mZone[iVar3].mZoneBit,param_1 + -0x40);
    }
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dSv_info_c::isItem(int,
                                 int) */

undefined4 __thiscall dSv_info_c::isItem(dSv_info_c *this,int i_no,int i_roomNo)

{
  bool bVar1;
  ulong uVar2;
  undefined4 uVar3;
  int zoneNo;
  
  bVar1 = false;
  if ((((-1 < i_no) && (i_no < 0x50)) || (i_no == -1)) || (i_no == 0x7f)) {
    bVar1 = true;
  }
  if (!bVar1) {
    uVar2 = JUTAssertion::getSDevice();
    JUTAssertion::showAssert
              (uVar2,"d_save.cpp",0xe2d,
               "(0 <= i_no && i_no < (MEMORY_ITEM+ZONE_ITEM)) || i_no == -1 || i_no == 127");
    m_Do_printf::OSPanic("d_save.cpp",0xe2d,&DAT_8034f7fb);
  }
  if ((i_no == -1) || (i_no == 0x7f)) {
    uVar3 = 0;
  }
  else {
    if (i_no < 0x40) {
      uVar3 = dSv_memBit_c::isItem((dSv_memBit_c *)&this->mMemory,i_no);
    }
    else {
      bVar1 = false;
      if ((-1 < i_roomNo) && (i_roomNo < 0x40)) {
        bVar1 = true;
      }
      if (!bVar1) {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar2,"d_save.cpp",0xe36,"0 <= i_roomNo && i_roomNo < 64");
        m_Do_printf::OSPanic("d_save.cpp",0xe36,&DAT_8034f7fb);
      }
      zoneNo = dStage_roomControl_c::getZoneNo(i_roomNo);
      bVar1 = false;
      if ((-1 < zoneNo) && (zoneNo < 0x20)) {
        bVar1 = true;
      }
      if (!bVar1) {
        uVar2 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert(uVar2,"d_save.cpp",0xe38,"0 <= zoneNo && zoneNo < ZONE_MAX");
        m_Do_printf::OSPanic("d_save.cpp",0xe38,&DAT_8034f7fb);
      }
      uVar3 = dSv_zoneBit_c::isItem(&this->mZone[zoneNo].mZoneBit,i_no + -0x40);
    }
  }
  return uVar3;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dSv_info_c::onActor(int,
                                  int) */

void __thiscall dSv_info_c::onActor(dSv_info_c *this,int param_1,int param_2)

{
  bool bVar1;
  ulong uVar2;
  int iVar3;
  
  if (((param_1 != -1) && (param_1 != 0xffff)) && (param_2 != -1)) {
    bVar1 = false;
    if (((-1 < param_1) && (param_1 < 0x200)) && ((-1 < param_2 && (param_2 < 0x40)))) {
      bVar1 = true;
    }
    if (!bVar1) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert
                (uVar2,"d_save.cpp",0xe6d,
                 "(0 <= i_id && i_id < dSv_zoneActor_c::ACTOR_MAX) && (0 <= i_roomNo && i_roomNo < 64)"
                );
      m_Do_printf::OSPanic("d_save.cpp",0xe6d,&DAT_8034f7fb);
    }
    iVar3 = dStage_roomControl_c::getZoneNo(param_2);
    bVar1 = false;
    if ((-1 < iVar3) && (iVar3 < 0x20)) {
      bVar1 = true;
    }
    if (!bVar1) {
      uVar2 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar2,"d_save.cpp",0xe6f,"0 <= zoneNo && zoneNo < ZONE_MAX");
      m_Do_printf::OSPanic("d_save.cpp",0xe6f,&DAT_8034f7fb);
    }
    dSv_zoneActor_c::on(&this->mZone[iVar3].mZoneActor,param_1);
  }
  return;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall dSv_info_c::isActor(int,
                                  int) */

undefined4 __thiscall dSv_info_c::isActor(dSv_info_c *this,int i_id,int i_roomNo)

{
  bool bVar1;
  undefined4 uVar2;
  ulong uVar3;
  int iVar4;
  
  if (((i_id == -1) || (i_id == 0xffff)) || (i_roomNo == -1)) {
    uVar2 = 0;
  }
  else {
    if ((i_id < 0) || (0x1ff < i_id)) {
      bVar1 = false;
      if ((-1 < i_id) && (i_id < 0x200)) {
        bVar1 = true;
      }
      if (!bVar1) {
        uVar3 = JUTAssertion::getSDevice();
        JUTAssertion::showAssert
                  (uVar3,"d_save.cpp",0xea0,"0 <= i_id && i_id < dSv_zoneActor_c::ACTOR_MAX");
        m_Do_printf::OSPanic("d_save.cpp",0xea0,&DAT_8034f7fb);
      }
    }
    bVar1 = false;
    if ((-1 < i_roomNo) && (i_roomNo < 0x40)) {
      bVar1 = true;
    }
    if (!bVar1) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_save.cpp",0xea2,"0 <= i_roomNo && i_roomNo < 64");
      m_Do_printf::OSPanic("d_save.cpp",0xea2,&DAT_8034f7fb);
    }
    iVar4 = dStage_roomControl_c::getZoneNo(i_roomNo);
    bVar1 = false;
    if ((-1 < iVar4) && (iVar4 < 0x20)) {
      bVar1 = true;
    }
    if (!bVar1) {
      uVar3 = JUTAssertion::getSDevice();
      JUTAssertion::showAssert(uVar3,"d_save.cpp",0xea4,"0 <= zoneNo && zoneNo < ZONE_MAX");
      m_Do_printf::OSPanic("d_save.cpp",0xea4,&DAT_8034f7fb);
    }
    uVar2 = dSv_zoneActor_c::is(&this->mZone[iVar4].mZoneActor,i_id);
  }
  return uVar2;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dSv_info_c::memory_to_card(char *,
                                         int) */

undefined4 __thiscall dSv_info_c::memory_to_card(dSv_info_c *this,char *param_1,int param_2)

{
  byte *pbVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  byte *dst;
  byte *dst_00;
  
  dst = (byte *)(param_1 + param_2 * 0x770);
  copy_bytes(dst,(byte *)&d_com_inf_game::g_dComIfG_gameInfo,0x18);
  if (*(ushort *)(dst + 2) < 0xc) {
    *(undefined2 *)(dst + 2) = 0xc;
  }
  uVar3 = 0x803c4c20;
  copy_bytes(dst + 0x18,(byte *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB,
             0x18);
  iVar2 = os::OSGetTime();
  *(undefined4 *)(dst + 0x1c) = uVar3;
  *(int *)(dst + 0x18) = iVar2;
  copy_bytes(dst + 0x30,
             (byte *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace,0xc);
  copy_bytes(dst + 0x3c,
             &d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.mTelescopeSlot,0x15);
  copy_bytes(dst + 0x51,d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits,0x15
            );
  copy_bytes(dst + 0x66,
             (byte *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord,8);
  copy_bytes(dst + 0x6e,(byte *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax,8
            );
  copy_bytes(dst + 0x76,d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem.field_0x0,
             0x18);
  copy_bytes(dst + 0x8e,
             (byte *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,0xc);
  copy_bytes(dst + 0x9a,
             (byte *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItemRecord,0x18);
  copy_bytes(dst + 0xb2,d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect.mData,0xd)
  ;
  copy_bytes(dst + 0xbf,(byte *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,0x84)
  ;
  copy_bytes(dst + 0x143,(byte *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mInfo,
             0x5c);
  copy_bytes(dst + 0x19f,(byte *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mConfig,5
            );
  copy_bytes(dst + 0x1a4,(byte *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mPriest,
             0x10);
  iVar2 = 0;
  iVar4 = 0;
  pbVar1 = dst + 0x1b4;
  do {
    dst_00 = pbVar1;
    copy_bytes(dst_00,(byte *)(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusC.
                                field_0x0 + iVar4),0x70);
    iVar2 = iVar2 + 1;
    iVar4 = iVar4 + 0x70;
    pbVar1 = dst_00 + 0x70;
  } while (iVar2 < 4);
  copy_bytes(dst_00 + 0x70,(byte *)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mMemory,0x240);
  copy_bytes(dst_00 + 0x2b0,(byte *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mOcean,100);
  copy_bytes(dst_00 + 0x314,d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent.mBits,0x100);
  copy_bytes(dst_00 + 0x414,(byte *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.field_0x724,0x50);
  if ((int)(dst_00 + (0x464 - (int)dst)) < 0x769) {
    MSL_C.PPCEABI.bare.H::printf("SAVE size:%d\n",dst_00 + (0x464 - (int)dst));
    uVar3 = 0;
  }
  else {
    MSL_C.PPCEABI.bare.H::printf("SAVE size over(%d/%d)\n",0x768);
    uVar3 = 0xffffffff;
  }
  return uVar3;
}


/* WARNING: Inlined function: FUN_80328f38 */
/* WARNING: Inlined function: FUN_80328f84 */
/* __thiscall dSv_info_c::card_to_memory(char *,
                                         int) */

undefined4 __thiscall dSv_info_c::card_to_memory(dSv_info_c *this,char *param_1,int param_2)

{
  byte *pbVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  byte *src;
  byte *src_00;
  
  src = (byte *)(param_1 + param_2 * 0x770);
  copy_bytes((byte *)&d_com_inf_game::g_dComIfG_gameInfo,src,0x18);
  copy_bytes((byte *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusB,src + 0x18,
             0x18);
  copy_bytes((byte *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mReturnPlace,
             src + 0x30,0xc);
  copy_bytes(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItem.mTelescopeSlot,
             src + 0x3c,0x15);
  copy_bytes(d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetItem.mBits,src + 0x51,0x15
            );
  copy_bytes((byte *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemRecord,
             src + 0x66,8);
  copy_bytes((byte *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mItemMax,src + 0x6e,8
            );
  copy_bytes(d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItem.field_0x0,src + 0x76,
             0x18);
  copy_bytes((byte *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mGetBagItem,
             src + 0x8e,0xc);
  copy_bytes((byte *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mBagItemRecord,
             src + 0x9a,0x18);
  copy_bytes(d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mCollect.mData,src + 0xb2,0xd)
  ;
  copy_bytes((byte *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mMap,src + 0xbf,0x84)
  ;
  copy_bytes((byte *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mInfo,src + 0x143,
             0x5c);
  copy_bytes((byte *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mConfig,src + 0x19f,5
            );
  iVar2 = os::OSGetSoundMode();
  if (iVar2 == 0) {
    d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mConfig._1_1_ = '\0';
    JAIZelBasic::setOutputMode(JAIZelBasic::zel_basic,0);
  }
  else {
    if (d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mConfig._1_1_ == '\x02') {
      JAIZelBasic::setOutputMode(JAIZelBasic::zel_basic,2);
    }
    else {
      d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mConfig._1_1_ = '\x01';
      JAIZelBasic::setOutputMode(JAIZelBasic::zel_basic,1);
    }
  }
  copy_bytes((byte *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mPriest,src + 0x1a4,
             0x10);
  iVar2 = 0;
  iVar4 = 0;
  pbVar1 = src + 0x1b4;
  do {
    src_00 = pbVar1;
    copy_bytes((byte *)(&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mPlayer.mStatusC.field_0x0
                       + iVar4),src_00,0x70);
    iVar2 = iVar2 + 1;
    iVar4 = iVar4 + 0x70;
    pbVar1 = src_00 + 0x70;
  } while (iVar2 < 4);
  copy_bytes((byte *)d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mMemory,src_00 + 0x70,0x240);
  copy_bytes((byte *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mOcean,src_00 + 0x2b0,100);
  copy_bytes(d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.mSave.mEvent.mBits,src_00 + 0x314,0x100);
  copy_bytes((byte *)&d_com_inf_game::g_dComIfG_gameInfo.mSvInfo.field_0x724,src_00 + 0x414,0x50);
  if ((int)(src_00 + (0x464 - (int)src)) < 0x769) {
    MSL_C.PPCEABI.bare.H::printf("LOAD size:%d\n",src_00 + (0x464 - (int)src));
    uVar3 = 0;
  }
  else {
    MSL_C.PPCEABI.bare.H::printf("LOAD size over(%d/%d)\n",0x768);
    uVar3 = 0xffffffff;
  }
  return uVar3;
}


/* WARNING: Inlined function: FUN_80328f3c */
/* WARNING: Inlined function: FUN_80328f88 */
/* __thiscall dSv_info_c::initdata_to_card(char *,
                                           int) */

undefined4 __thiscall dSv_info_c::initdata_to_card(dSv_info_c *this,char *param_1,int param_2)

{
  byte *pbVar1;
  undefined4 uVar2;
  dSv_player_config_c *ctx;
  dSv_player_priest_c *ctx_00;
  dSv_event_c *ctx_01;
  int iVar3;
  byte *dst;
  byte *dst_00;
  dSv_player_config_c dStack1048;
  dSv_player_item_max_c dStack1040;
  dSv_player_item_record_c dStack1032;
  dSv_player_priest_c dStack1024;
  dSv_player_collect_c dStack1008;
  dSv_player_get_bag_item_c dStack992;
  dSv_player_return_place_c dStack980;
  dSv_player_bag_item_record_c dStack968;
  dSv_player_bag_item_c dStack944;
  dSv_player_get_item_c dStack920;
  dSv_player_item_c dStack896;
  dSv_player_status_b_c dStack872;
  dSv_player_status_a_c dStack848;
  dSv_memory_c dStack824;
  dSv_reserve_c adStack788 [80];
  dSv_ocean_c dStack708;
  dSv_player_status_c_c adStack608 [4];
  dSv_player_info_c dStack496;
  dSv_event_c dStack404;
  dSv_player_map_c dStack148;
  
  dst = (byte *)(param_1 + param_2 * 0x770);
  dSv_player_status_a_c::init(&dStack848);
  copy_bytes(dst,(byte *)&dStack848,0x18);
  dSv_player_status_b_c::init(&dStack872);
  copy_bytes(dst + 0x18,(byte *)&dStack872,0x18);
  dSv_player_return_place_c::init(&dStack980);
  copy_bytes(dst + 0x30,(byte *)&dStack980,0xc);
  dSv_player_item_c::init(&dStack896);
  copy_bytes(dst + 0x3c,&dStack896.mTelescopeSlot,0x15);
  dSv_player_get_item_c::init(&dStack920);
  copy_bytes(dst + 0x51,dStack920.mBits,0x15);
  dSv_player_item_record_c::init(&dStack1032);
  copy_bytes(dst + 0x66,(byte *)&dStack1032,8);
  dSv_player_item_max_c::init(&dStack1040);
  copy_bytes(dst + 0x6e,(byte *)&dStack1040,8);
  dSv_player_bag_item_c::init(&dStack944);
  copy_bytes(dst + 0x76,dStack944.field_0x0,0x18);
  dSv_player_get_bag_item_c::init(&dStack992);
  copy_bytes(dst + 0x8e,(byte *)&dStack992,0xc);
  dSv_player_bag_item_record_c::init(&dStack968);
  copy_bytes(dst + 0x9a,(byte *)&dStack968,0x18);
  dSv_player_collect_c::init(&dStack1008);
  copy_bytes(dst + 0xb2,dStack1008.mData,0xd);
  dSv_player_map_c::init(&dStack148);
  copy_bytes(dst + 0xbf,(byte *)&dStack148,0x84);
  dSv_player_info_c::init(&dStack496);
  FUN_800033a8((int)(dst + 0x143),0,0x5c);
  dSv_player_config_c::init(&dStack1048);
  ctx = &dStack1048;
  copy_bytes(dst + 0x19f,(byte *)ctx,5);
  dSv_player_priest_c::init(&dStack1024,(EVP_PKEY_CTX *)ctx);
  ctx_00 = &dStack1024;
  copy_bytes(dst + 0x1a4,(byte *)ctx_00,0x10);
  dSv_player_status_c_c::init(adStack608,(EVP_PKEY_CTX *)ctx_00);
  iVar3 = 0;
  pbVar1 = dst + 0x1b4;
  do {
    dst_00 = pbVar1;
    copy_bytes(dst_00,(byte *)adStack608,0x70);
    iVar3 = iVar3 + 1;
    pbVar1 = dst_00 + 0x70;
  } while (iVar3 < 4);
  dSv_memory_c::init(&dStack824);
  dSv_memory_c::init(&dStack824);
  copy_bytes(dst_00 + 0x70,(byte *)&dStack824,0x240);
  dSv_ocean_c::init(&dStack708);
  copy_bytes(dst_00 + 0x2b0,(byte *)&dStack708,100);
  dSv_event_c::init(&dStack404);
  ctx_01 = &dStack404;
  copy_bytes(dst_00 + 0x314,ctx_01->mBits,0x100);
  dSv_reserve_c::init(adStack788,(EVP_PKEY_CTX *)ctx_01);
  copy_bytes(dst_00 + 0x414,(byte *)adStack788,0x50);
  if ((int)(dst_00 + (0x464 - (int)dst)) < 0x769) {
    MSL_C.PPCEABI.bare.H::printf("INIT size:%d\n",dst_00 + (0x464 - (int)dst));
    uVar2 = 0;
  }
  else {
    MSL_C.PPCEABI.bare.H::printf("INIT size over %d/%d\n",0x768);
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

