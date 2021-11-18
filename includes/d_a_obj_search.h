#pragma once
#include <ctypes.h>

#include <profile_method_class.h>
#include <f_pc_profile__Profile_Actor.h>


namespace d_a_obj_search {
//[Data] Expected size is 0x00004c
extern undefined cps_src;

//[Data] Expected size is 0x0000e0
extern undefined4 mode_tbl$4960;

}

namespace daObj_Search {
//[Data] Expected size is 0x000020
extern struct profile_method_class Mthd;

}

namespace d_a_obj_search {
//[Data] Expected size is 0x000030
extern struct f_pc_profile__Profile_Actor g_profile_OBJ_SEARCH;

}
//[Data] Expected size is 0x000030
extern undefined1 dBgS_ObjLinChk;


namespace d_a_obj_search {
//[Data] Expected size is 0x000008
extern undefined dzb$4138;

//[BSS] Expected size is 0x00000c
extern undefined4 pos$4262;
//[BSS] Expected size is 0x00000c
extern undefined4 pos$4268;
//[BSS] Expected size is 0x00000c
extern undefined4 pos$4274;
//[BSS] Expected size is 0x00000c
extern undefined4 pos$4567;
//[BSS] Expected size is 0x00000c
extern undefined4 pos$4678;
//[BSS] Expected size is 0x00000c
extern undefined4 pos$4832;
//[BSS] Expected size is 0x00000c
extern undefined4 pos$4837;
//[BSS] Expected size is 0x000001
extern undefined1 init$4264;
//[BSS] Expected size is 0x000001
extern undefined1 init$4270;
//[BSS] Expected size is 0x000001
extern undefined1 init$4276;
//[BSS] Expected size is 0x000001
extern undefined1 init$4569;
//[BSS] Expected size is 0x000001
extern undefined1 init$4680;
//[BSS] Expected size is 0x000001
extern undefined1 init$4834;
//[BSS] Expected size is 0x000001
extern undefined1 init$4839;
//[BSS] Expected size is 0x000001
extern undefined1 init$4977;

namespace Act_c {
//[BSS] Expected size is 0x000001
extern undefined1 m_find_flag;
}
void createHeap_CB(Act_c *param_1);
}

namespace daObj_Search {
}

namespace d_a_obj_search {
undefined4 nodeControl_CB(J3DNode *param_1,int param_2);
}

namespace daObj_Search {
}

namespace daObj_Search {
}
