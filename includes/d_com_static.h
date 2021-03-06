#pragma once
#include <ctypes.h>


//[Data] Expected size is 0x00001c
extern undefined1 JPACallBackBase<JPABaseEmitter*>;

//[Data] Expected size is 0x000020
extern undefined1 dPa_levelEcallBack;

//[Data] Expected size is 0x000003
extern undefined1 daNpc_Os_c;

//[Data] Expected size is 0x000001
extern undefined1 daNpc_Os_c;

//[Data] Expected size is 0x000001
extern undefined1 daTitle_proc_c;


namespace Global {
//[BSS] Expected size is 0x00000c
extern undefined g_dComIfG_gameInfo.field_0x1d1d4;
}
//[BSS] Expected size is 0x000020
extern undefined1 daNpc_Os_c;
//[BSS] Expected size is 0x0000b0
extern undefined1 daNpc_Os_c;
//[BSS] Expected size is 0x000014
extern undefined1 daIball_c;
//[BSS] Expected size is 0x000004
extern undefined1 daLodbg_c;
//[BSS] Expected size is 0x000004
extern undefined1 daLodbg_c;
//[BSS] Expected size is 0x000001
extern undefined1 daSteamTag_c;
//[BSS] Expected size is 0x000001
extern undefined1 daYkgr_c;
//[BSS] Expected size is 0x000001
extern undefined1 daYkgr_c;
//[BSS] Expected size is 0x000001
extern undefined1 daYkgr_c;
//[BSS] Expected size is 0x000004
extern float daYkgr_c;
//[BSS] Expected size is 0x000004
extern undefined1 daYkgr_c;
//[BSS] Expected size is 0x000004
extern undefined1 daYkgr_c;

namespace daTagWaterlevel {

namespace Act_c {
//[BSS] Expected size is 0x000004
extern undefined1 M_now;
//[BSS] Expected size is 0x000004
extern undefined1 M_state;
}
}
//[BSS] Expected size is 0x000001
extern undefined1 daAgbsw0_c;
//[BSS] Expected size is 0x000001
extern undefined1 daAgbsw0_c;
//[BSS] Expected size is 0x000004
extern undefined1 daSalvage_c;
//[BSS] Expected size is 0x000001
extern undefined1 daSalvage_c;
//[BSS] Expected size is 0x000004
extern undefined1 daSalvage_c;

namespace daObjLight {
//[BSS] Expected size is 0x000002
extern short Act_c;
//[BSS] Expected size is 0x000004
extern int Act_c;
//[BSS] Expected size is 0x000004
extern int Act_c;
//[BSS] Expected size is 0x000001
extern undefined1 Act_c;
}
//[BSS] Expected size is 0x000001
extern undefined1 daDai_c;
//[BSS] Expected size is 0x000001
extern undefined1 daDai_c;
//[BSS] Expected size is 0x000001
extern undefined1 daNpc_Md_c;
//[BSS] Expected size is 0x000001
extern undefined1 daNpc_Md_c;
//[BSS] Expected size is 0x000001
extern undefined1 daNpc_Md_c;
//[BSS] Expected size is 0x000002
extern undefined1 daNpc_Md_c;
//[BSS] Expected size is 0x000001
extern undefined1 daNpc_Md_c;
//[BSS] Expected size is 0x000004
extern undefined1 daNpc_Sarace_c;
//[BSS] Expected size is 0x000004
extern undefined1 daNpc_Sarace_c;
//[BSS] Expected size is 0x000004
extern undefined1 daCanon_c;
//[BSS] Expected size is 0x000001
extern undefined1 daNpc_Kg2_c;
//[BSS] Expected size is 0x000004
extern undefined1 daNpc_Kg2_c;
//[BSS] Expected size is 0x000001
extern undefined1 daArrow_c;
//[BSS] Expected size is 0x000001
extern undefined1 daNpc_Ji1_c;
//[BSS] Expected size is 0x000001
extern byte daNpc_kam_c;
//[BSS] Expected size is 0x000001
extern undefined1 daNpc_Bs1_c;
//[BSS] Expected size is 0x000001
extern undefined1 daNpc_Bs1_c;
//[BSS] Expected size is 0x000002
extern undefined1 daNpc_Bs1_c;

namespace daObjPirateship {
double getShipOffsetY(short *param_1,short *param_2,float param_3);
}

namespace daObjLight {

namespace Act_c {
int get_light_angle(void);
int get_light_dif_angle(void);
void set_light_dif_angle_LOD(short param_1);
}
}

namespace daStandItem_c {
undefined4 daiItemNodeCallBack(J3DJoint *param_1,int param_2);
}

namespace d_com_static {
void __sinit_d_com_static_cpp(void);
}
