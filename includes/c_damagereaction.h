#pragma once
#include <ctypes.h>

#include <cXyz.h>
#include <cBgS_Chk__vtbl.h>
#include <Demangler/dCcD_SrcCyl.h>
#include <Demangler/dCcD_SrcSph.h>


namespace c_damagereaction {
//[Data] Expected size is 0x000044
extern struct dCcD_SrcCyl cc_cyl_src;

//[Data] Expected size is 0x000040
extern struct dCcD_SrcSph fire_at_sph_src;

}
//[Data] Expected size is 0x000030
extern undefined1 dBgS_ObjGndChk_Yogan;

//[Data] Expected size is 0x000018
extern undefined1 cBgS_GndChk;

//[Data] Expected size is 0x000030
extern pointer dBgS_ObjGndChk_Spl;

//[Data] Expected size is 0x000030
extern struct cBgS_Chk__vtbl dBgS_ObjGndChk;

//[Data] Expected size is 0x000030
extern struct cBgS_Chk__vtbl dBgS_GndChk;

//[Data] Expected size is 0x000030
extern pointer dBgS_LinChk;

//[Data] Expected size is 0x000018
extern pointer dBgS_Chk;

//[Data] Expected size is 0x00000c
extern pointer dBgS_GrpPassChk;

//[Data] Expected size is 0x00000c
extern pointer cBgS_GrpPassChk;

//[Data] Expected size is 0x00000c
extern pointer dBgS_PolyPassChk;

//[Data] Expected size is 0x00000c
extern pointer cBgS_PolyPassChk;

//[Data] Expected size is 0x00000c
extern pointer cM3dGLin;

//[Data] Expected size is 0x000018
extern pointer cBgS_LinChk;

//[Data] Expected size is 0x00000c
extern pointer cBgS_PolyInfo;


namespace c_damagereaction {
//[Data] Expected size is 0x000008
extern int kado_bit$5637[2];

//[Data] Expected size is 0x000008
extern float kado_check_x$5638[2];

//[BSS] Expected size is 0x00000c
extern struct cXyz non_pos;
//[BSS] Expected size is 0x000001
extern undefined1 test_sw;
undefined4 ice_bg_check(enemyice *pIce);
int enemy_ice(enemyice *this);
}

namespace c_damagereaction {
void enemy_fire(enemyfire *this);
void enemy_fire_remove(enemyfire *this);
void enemy_piyo_set(fopAc_ac_c *pActor);
int wall_angle_get(fopAc_ac_c *param_1,undefined4 param_2);
}

namespace c_damagereaction {
void dr_body_bg_check(damagereaction *this);
}

namespace c_damagereaction {
undefined4 dr_joint_bg_check(damagereaction *this);
}

namespace c_damagereaction {
uint kado_check(damagereaction *this);
int hang_ang_get(damagereaction *this);
int dr_damage_set(damagereaction *this);
void dr_damage_anime(damagereaction *this);
void dr_matrix_set(damagereaction *this);
undefined4 damage_reaction(damagereaction *this);
void __sinit_c_damagereaction_cpp(void);
}
