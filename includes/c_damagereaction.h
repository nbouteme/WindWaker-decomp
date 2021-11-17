#pragma once
#include <ctypes.h>

#include <cXyz.h>


namespace c_damagereaction {
//Expected size is 0x00000c
extern struct cXyz non_pos;

//Expected size is 0x000001
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
