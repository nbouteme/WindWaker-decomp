#pragma once
#include <ctypes.h>

#include <f_pc_profile__Profile_Base.h>


namespace d_s_room {
//[Data] Expected size is 0x000014
extern undefined * l_method$4448;

//[Data] Expected size is 0x000014
extern undefined * l_dScnRoom_Method;

//[Data] Expected size is 0x000028
extern struct f_pc_profile__Profile_Base g_profile_ROOM_SCENE;

//[BSS] Expected size is 0x000020
extern undefined arcName$4176;
void setMapImage(room_of_scene_class *param_1);
void deleteMapImage(int param_1,int param_2);
char * setArcName(room_of_scene_class *param_1);
undefined4 dScnRoom_Draw(void);
undefined4 deleteJugge(base_process_class *param_1);
void objectSetCheck(room_of_scene_class *param_1);
undefined4 dScnRoom_Execute(room_of_scene_class *param_1);
undefined4 dScnRoom_IsDelete(void);
undefined4 dScnRoom_Delete(room_of_scene_class *param_1);
int phase_0(room_of_scene_class *param_1);
undefined4 phase_1(room_of_scene_class *param_1);
undefined4 phase_2(room_of_scene_class *param_1);
}

namespace dStage_roomControl_c {
void setZoneNo(int param_1,int param_2);
}

namespace d_s_room {
undefined4 phase_3(room_of_scene_class *param_1);
undefined4 phase_4(room_of_scene_class *param_1);
void dScnRoom_Create(room_of_scene_class *param_1);
}
