#pragma once
#include <ctypes.h>



namespace d_event_data {
//[Data] Expected size is 0x00000c
extern pointer action_table$4196;

//[Data] Expected size is 0x000024
extern undefined * action_table$4251;

//[Data] Expected size is 0x000020
extern undefined * action_table$4350;

//[Data] Expected size is 0x00001c
extern undefined landing_table$4363;

//[Data] Expected size is 0x000024
extern undefined * action_table$4506;

//[Data] Expected size is 0x00000c
extern pointer bgm_table$4521;

//[Data] Expected size is 0x00000c
extern pointer action_table$4648;

//[Data] Expected size is 0x000008
extern pointer action_table$4428;

//[Data] Expected size is 0x000004
extern undefined se_table$4535;

//[Data] Expected size is 0x000008
extern pointer action_table$4728;

//[BSS] Expected size is 0x000004
extern undefined4 l_msgId$4247;
//[BSS] Expected size is 0x000004
extern undefined4 l_msg$4248;
//[BSS] Expected size is 0x000004
extern undefined4 l_msgNo$4249;
undefined4 dEvDt_Next_Stage(int staffIdx,byte wipeType);
}
