#pragma once
#include <ctypes.h>

#include <profile_method_class.h>
#include <f_pc_profile__Profile_Actor.h>


namespace d_a_boomerang {
//[Data] Expected size is 0x000095
extern undefined l_matDL$4438;

//[Data] Expected size is 0x000018
extern undefined l_vtxDescList$4439;

//[Data] Expected size is 0x000030
extern undefined l_vtxAttrFmtList$4440;

//[Data] Expected size is 0x00007c
extern undefined l_sightMatDL;

//[Data] Expected size is 0x000037
extern undefined l_sightDL;

//[Data] Expected size is 0x000018
extern undefined l_vtxDescList$4674;

//[Data] Expected size is 0x000030
extern undefined l_vtxAttrFmtList$4675;

//[Data] Expected size is 0x00004c
extern undefined l_at_cps_src;

//[Data] Expected size is 0x000020
extern struct profile_method_class l_daBoomerang_Method;

//[Data] Expected size is 0x000030
extern struct f_pc_profile__Profile_Actor g_profile_BOOMERANG;

}
//[Data] Expected size is 0x000030
extern undefined1 dBgS_BoomerangLinChk;

//[Data] Expected size is 0x000010
extern undefined1 daBoomerang_sightPacket_c;

//[Data] Expected size is 0x000018
extern undefined1 daBoomerang_blur_c;


namespace d_a_boomerang {
//[Data] Expected size is 0x000004
extern undefined4 color0$4442;

//[BSS] Expected size is 0x00000c
extern undefined4 l_blur_top;
//[BSS] Expected size is 0x00000c
extern undefined4 l_blur_root;
//[BSS] Expected size is 0x000020
extern undefined texObj$4441;
//[BSS] Expected size is 0x00000c
extern undefined at_offset$5155;
//[BSS] Expected size is 0x000001
extern undefined1 init$5157;
}

namespace d_a_boomerang {
void daBoomerang_Draw(daBoomerang_c *param_1);
}

namespace d_a_boomerang {
void daBoomerang_rockLineCallback(daBoomerang_c *param_1,undefined4 param_2,fopAc_ac_c *param_3);
}

namespace d_a_boomerang {
void daBoomerang_Execute(daBoomerang_c *param_1);
undefined4 daBoomerang_IsDelete(void);
undefined4 daBoomerang_Delete(void);
}

namespace d_a_boomerang {
void daBoomerang_createHeap(daBoomerang_c *param_1);
}

namespace d_a_boomerang {
void daBoomerang_Create(daBoomerang_c *param_1);
void __sinit_d_a_boomerang_cpp(void);
}
