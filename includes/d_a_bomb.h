#pragma once
#include <ctypes.h>

#include <profile_method_class.h>
#include <f_pc_profile__Profile_Actor.h>
#include <Demangler/dCcD_SrcSph.h>


namespace d_a_bomb {
//[Data] Expected size is 0x000024
extern undefined4 proc$4551;

//[Data] Expected size is 0x000024
extern undefined4 proc$4640;

//[Data] Expected size is 0x000040
extern struct dCcD_SrcSph l_sph_src;

//[Data] Expected size is 0x000020
extern struct profile_method_class l_daBomb_Method;

//[Data] Expected size is 0x000030
extern struct f_pc_profile__Profile_Actor g_profile_BOMB;

}
//[Data] Expected size is 0x000024
extern undefined1 dBgS_BombAcch;

//[Data] Expected size is 0x00000c
extern pointer mDoExt_bckAnm;

//[Data] Expected size is 0x000020
extern undefined1 daBomb_fuseSparksEcallBack;

//[Data] Expected size is 0x000020
extern undefined1 daBomb_fuseSmokeEcallBack;


namespace d_a_bomb {
//[BSS] Expected size is 0x00000c
extern undefined4 fuse_offset$5399;
//[BSS] Expected size is 0x000001
extern undefined1 init$4555;
//[BSS] Expected size is 0x000001
extern undefined1 init$4644;
//[BSS] Expected size is 0x000001
extern undefined1 init$5401;
}

namespace @unnamed@d_a_bomb_cpp@ {
bool chk_attrState(daBomb_c *param_1,AttrSt_e param_2);
}

namespace d_a_bomb {
void daBomb_Draw(daBomb_c *param_1);
}

namespace d_a_bomb {
void daBomb_Execute(daBomb_c *param_1);
}

namespace d_a_bomb {
undefined4 daBomb_IsDelete(void);
}

namespace d_a_bomb {
undefined4 daBomb_Delete(daBomb_c *param_1);
}

namespace d_a_bomb {
void daBomb_createHeap(daBomb_c *param_1);
}

namespace d_a_bomb {
void daBomb_Create(daBomb_c *param_1);
}
