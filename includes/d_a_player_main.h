#pragma once
#include <ctypes.h>

#include <cXyz.h>
#include <profile_method_class.h>
#include <J3DPacket.h>
#include <Demangler/dCcD_SrcCps.h>
#include <csXyz.h>
#include <daPy_py_c__vtbl.h>
#include <f_pc_profile__Profile_Actor.h>
#include <Demangler/dCcD_SrcCyl.h>
#include <Demangler/dCcD_SrcSph.h>


namespace d_a_player_main {
//[Data] Expected size is 0x000044
extern undefined l_cyl_src;

//[Data] Expected size is 0x000044
extern struct dCcD_SrcCyl l_wind_cyl_src;

//[Data] Expected size is 0x000044
extern struct dCcD_SrcCyl l_at_cyl_src;

//[Data] Expected size is 0x00004c
extern struct dCcD_SrcCps l_at_cps_src;

//[Data] Expected size is 0x00004c
extern struct dCcD_SrcCps l_fan_wind_cps_src;

//[Data] Expected size is 0x000040
extern struct dCcD_SrcSph l_fan_wind_sph_src;

}
//[Data] Expected size is 0x000db0
extern struct PTMF_0x10 daPy_lk_c[219];

//[Data] Expected size is 0x000384
extern struct PTMF daPy_lk_c[75];


namespace d_a_player_main {
//[Data] Expected size is 0x000089
extern undefined l_sightDL;

//[Data] Expected size is 0x00000c
extern undefined waterfall_ripple_scale$5702;

//[Data] Expected size is 0x00000c
extern undefined grass_scale$6038;

//[Data] Expected size is 0x00000c
extern undefined smoke_scale$6039;

//[Data] Expected size is 0x00000c
extern undefined eff_scale$24884;

//[Data] Expected size is 0x000010
extern undefined norm_quat$25648;

//[Data] Expected size is 0x00000c
extern undefined top_vec$29499;

//[Data] Expected size is 0x000010
extern pointer l_method$44066;

//[Data] Expected size is 0x000024
extern struct profile_method_class l_daPy_Method;

//[Data] Expected size is 0x000034
extern struct f_pc_profile__Profile_Actor g_profile_PLAYER;

}
//[Data] Expected size is 0x00009c
extern struct daPy_py_c__vtbl daPy_lk_c;

//[Data] Expected size is 0x000030
extern undefined1 dBgS_MirLightLinChk;

//[Data] Expected size is 0x000030
extern pointer dBgS_LinkRoofChk;

//[Data] Expected size is 0x000030
extern pointer dBgS_LinkGndChk;

//[Data] Expected size is 0x00009c
extern struct daPy_py_c__vtbl daPy_py_c;

//[Data] Expected size is 0x00000c
extern undefined1 JUTNameTab;


namespace J3DAnmTextureSRTKey {
//[Data] Expected size is 0x00000c
extern undefined1 __vt;

}

namespace J3DAnmTexPattern {
//[Data] Expected size is 0x00000c
extern undefined1 __vt;

}
//[Data] Expected size is 0x000010
extern undefined1 daPy_matAnm_c;

//[Data] Expected size is 0x000020
extern undefined1 daPy_dmEcallBack_c;

//[Data] Expected size is 0x000020
extern undefined1 daPy_mtxPosFollowEcallBack_c;

//[Data] Expected size is 0x000020
extern undefined1 daPy_waterDropEcallBack_c;

//[Data] Expected size is 0x000020
extern undefined1 daPy_followEcallBack_c;

//[Data] Expected size is 0x000018
extern undefined1 daPy_waterDropPcallBack_c;

//[Data] Expected size is 0x000020
extern undefined1 daPy_fanSwingEcallBack_c;

//[Data] Expected size is 0x000018
extern undefined1 daPy_swBlur_c;

//[Data] Expected size is 0x000010
extern undefined1 daPy_sightPacket_c;

//[Data] Expected size is 0x000020
extern undefined1 daPy_swimTailEcallBack_c;


namespace d_a_player_main {
//[Data] Expected size is 0x000004
extern undefined l_freeze_fade_color;

//[Data] Expected size is 0x000004
extern undefined4 n_color0$5158;

//[Data] Expected size is 0x000004
extern undefined4 y_color0$5159;

//[Data] Expected size is 0x000004
extern undefined4 g_color0$5160;

}
//[Data] Expected size is 0x000002
extern undefined1 daPy_dmEcallBack_c;


namespace d_a_player_main {
//[BSS] Expected size is 0x00000c
extern struct cXyz l_hammer_splash_particle_scale;
//[BSS] Expected size is 0x00000c
extern struct cXyz l_debug_keep_pos;
//[BSS] Expected size is 0x00000c
extern undefined4 right_dir$4883;
//[BSS] Expected size is 0x000020
extern GXTexObj texObj$5157;
}
//[BSS] Expected size is 0x00005c
extern undefined1 daPy_waterDropEcallBack_c;

namespace d_a_player_main {
//[BSS] Expected size is 0x00000c
extern undefined4 normal_ripple_scale$5638;
//[BSS] Expected size is 0x00000c
extern undefined4 small_ripple_scale$5641;
//[BSS] Expected size is 0x00000c
extern undefined4 waterfall_splash_trans$5699;
//[BSS] Expected size is 0x00000c
extern undefined4 run_splash_scale$6040;
//[BSS] Expected size is 0x00000c
extern undefined4 run_grass_scale$6043;
//[BSS] Expected size is 0x00000c
extern undefined4 heavy_emit_smoke_scale$6046;
//[BSS] Expected size is 0x00000c
extern undefined4 heavy_dyn_smoke_scale$6049;
//[BSS] Expected size is 0x00000c
extern undefined4 heavy_pat_smoke_scale$6052;
//[BSS] Expected size is 0x00000c
extern undefined4 tail_scale$6508;
//[BSS] Expected size is 0x00000c
extern undefined4 arm_flame_scale$6651;
//[BSS] Expected size is 0x00000c
extern undefined4 eff_scale0$6784;
//[BSS] Expected size is 0x00000c
extern undefined4 eff_scale2$6788;
//[BSS] Expected size is 0x00000c
extern undefined4 direction$6792;
//[BSS] Expected size is 0x00000c
extern undefined4 splash_scale$14445;
//[BSS] Expected size is 0x00000c
extern undefined4 ripple_scale$14448;
//[BSS] Expected size is 0x00000c
extern undefined4 arm_pos$15292;
//[BSS] Expected size is 0x00000c
extern undefined4 armA_offset$15296;
//[BSS] Expected size is 0x00000c
extern undefined4 dynamic_scale$16750;
//[BSS] Expected size is 0x00000c
extern undefined4 particle_scale$16753;
//[BSS] Expected size is 0x00000c
extern undefined4 local_height_offset$17479;
//[BSS] Expected size is 0x00000c
extern undefined4 eff_scale$18886;
//[BSS] Expected size is 0x00000c
extern undefined4 eff_dscale$18889;
//[BSS] Expected size is 0x00000c
extern undefined4 eff_pscale$18892;
//[BSS] Expected size is 0x00000c
extern undefined4 smoke_kusa_particle_scale$21005;
//[BSS] Expected size is 0x00000c
extern undefined4 emitter_scale$21008;
//[BSS] Expected size is 0x00000c
extern undefined4 emitter_trans$21011;
//[BSS] Expected size is 0x00000c
extern undefined4 d_scale$23162;
//[BSS] Expected size is 0x00000c
extern undefined4 p_scale$23165;
//[BSS] Expected size is 0x00000c
extern undefined4 emitter_trans$24824;
//[BSS] Expected size is 0x00000c
extern undefined4 particle_scale$24827;
//[BSS] Expected size is 0x000030
extern undefined root_mtx$25647;
//[BSS] Expected size is 0x000010
extern undefined4 l_offCupOnAupPacket1;
//[BSS] Expected size is 0x000010
extern struct J3DPacket l_offCupOnAupPacket2;
//[BSS] Expected size is 0x000010
extern struct J3DPacket l_onCupOffAupPacket1;
//[BSS] Expected size is 0x000010
extern struct J3DPacket l_onCupOffAupPacket2;
//[BSS] Expected size is 0x00000c
extern undefined4 normal_scale$38064;
//[BSS] Expected size is 0x00000c
extern undefined4 boss_scale$38067;
//[BSS] Expected size is 0x000006
extern struct csXyz l_debug_current_angle;
//[BSS] Expected size is 0x000006
extern struct csXyz l_debug_shape_angle;
}
//[BSS] Expected size is 0x000001
extern byte daPy_matAnm_c;
//[BSS] Expected size is 0x000001
extern byte daPy_matAnm_c;
//[BSS] Expected size is 0x000001
extern byte daPy_matAnm_c;
//[BSS] Expected size is 0x000001
extern byte daPy_matAnm_c;

namespace d_a_player_main {
//[BSS] Expected size is 0x000001
extern undefined1 init$4884;
}
//[BSS] Expected size is 0x000002
extern byte daPy_dmEcallBack_c;

namespace d_a_player_main {
//[BSS] Expected size is 0x000001
extern undefined1 init$5639;
//[BSS] Expected size is 0x000001
extern undefined1 init$5642;
//[BSS] Expected size is 0x000001
extern undefined1 init$5700;
//[BSS] Expected size is 0x000001
extern undefined1 init$6041;
//[BSS] Expected size is 0x000001
extern undefined1 init$6044;
//[BSS] Expected size is 0x000001
extern undefined1 init$6047;
//[BSS] Expected size is 0x000001
extern undefined1 init$6050;
//[BSS] Expected size is 0x000001
extern undefined1 init$6053;
//[BSS] Expected size is 0x000001
extern undefined1 init$6509;
//[BSS] Expected size is 0x000001
extern undefined1 init$6652;
//[BSS] Expected size is 0x000001
extern undefined1 init$6786;
//[BSS] Expected size is 0x000001
extern undefined1 init$6790;
//[BSS] Expected size is 0x000001
extern undefined1 init$6793;
//[BSS] Expected size is 0x000004
extern float magtail_offset$13136;
//[BSS] Expected size is 0x000001
extern undefined1 init$13137;
//[BSS] Expected size is 0x000001
extern undefined1 init$14446;
//[BSS] Expected size is 0x000001
extern undefined1 init$14449;
//[BSS] Expected size is 0x000001
extern undefined1 init$15294;
//[BSS] Expected size is 0x000001
extern undefined1 init$15298;
//[BSS] Expected size is 0x000001
extern undefined1 init$16751;
//[BSS] Expected size is 0x000001
extern undefined1 init$16754;
//[BSS] Expected size is 0x000001
extern undefined1 init$17481;
//[BSS] Expected size is 0x000001
extern undefined1 init$18887;
//[BSS] Expected size is 0x000001
extern undefined1 init$18890;
//[BSS] Expected size is 0x000001
extern undefined1 init$18893;
//[BSS] Expected size is 0x000001
extern undefined1 init$21006;
//[BSS] Expected size is 0x000001
extern undefined1 init$21009;
//[BSS] Expected size is 0x000001
extern undefined1 init$21012;
//[BSS] Expected size is 0x000001
extern undefined1 init$23163;
//[BSS] Expected size is 0x000001
extern undefined1 init$23166;
//[BSS] Expected size is 0x000001
extern undefined1 init$24825;
//[BSS] Expected size is 0x000001
extern undefined1 init$24828;
//[BSS] Expected size is 0x000004
extern float guard_rate$25858;
//[BSS] Expected size is 0x000001
extern undefined1 init$25859;
//[BSS] Expected size is 0x000001
extern undefined1 init$38065;
//[BSS] Expected size is 0x000001
extern undefined1 init$38068;
void daPy_createHeap(daPy_lk_c *param_1);
}

namespace d_a_player_main {
undefined4 daPy_auraCallback(J3DNode *param_1,int param_2);
}

namespace d_a_player_main {
void daPy_jointBeforeCallback(daPy_lk_c *param_1,uint param_2,J3DTransformInfo *param_3,Quaternion *param_4);
}

namespace d_a_player_main {
void daPy_jointAfterCallback(daPy_lk_c *param_1,uint param_2,J3DTransformInfo *param_3,Quaternion *param_4);
}

namespace d_a_player_main {
undefined4 daPy_jointCallback0(int param_1,int param_2);
}

namespace d_a_player_main {
undefined4 daPy_jointCallback1(undefined4 param_1,int param_2);
}

namespace d_a_player_main {
void daPy_Draw(daPy_lk_c *param_1);
}

namespace d_a_player_main {
void daPy_Execute(daPy_lk_c *param_1);
undefined4 daPy_IsDelete(void);
}

namespace d_a_player_main {
void daPy_Delete(daPy_lk_c *param_1);
}

namespace d_a_player_main {
undefined4 phase_1(daPy_lk_c *param_1);
undefined4 phase_2(daPy_lk_c *param_1);
}

namespace d_a_player_main {
void phase_3(daPy_lk_c *param_1);
void daPy_Create(daPy_lk_c *param_1);
}

namespace d_a_player_main {
void __sinit_d_a_player_main_cpp(void);
}

namespace d_a_player_main {
undefined4 daPy_bowJointCB(int param_1,int param_2);
}

namespace d_a_player_main {
undefined4 daPy_fanJointCallback(J3DNode *param_1,int param_2);
}

namespace d_a_player_main {
undefined4 daPy_parachuteJointCallback(int param_1,int param_2);
}
