#pragma once
#include <ctypes.h>

#include <profile_method_class.h>
#include <f_pc_profile__Profile_Actor.h>


namespace d_a_agb {
//[Data] Expected size is 0x00009f
extern undefined1 l_sjis2chrNo$4313;

}
//[Data] Expected size is 0x000090
extern undefined1 daAgb_c;

//[Data] Expected size is 0x000010
extern undefined1 daAgb_c;


namespace d_a_agb {
//[Data] Expected size is 0x000020
extern undefined4 l_ckOffset$5504;

//[Data] Expected size is 0x000020
extern struct profile_method_class l_daAgb_Method;

//[Data] Expected size is 0x000030
extern struct f_pc_profile__Profile_Actor g_profile_AGB;

}

namespace dBgS_CrrPos {
//[Data] Expected size is 0x000030
extern pointer __vt;

}
//[Data] Expected size is 0x000030
extern pointer dBgS_LinkCrrPos;

//[Data] Expected size is 0x000024
extern undefined1 dBgS_LinkAcch;

//[Data] Expected size is 0x000030
extern pointer dBgS_LinkLinChk;

//[Data] Expected size is 0x00000c
extern undefined1 daAgb_HIO_c;

//[Data] Expected size is 0x00000c
extern undefined1 mDoHIO_entry_c;


namespace d_a_agb {
//[BSS] Expected size is 0x000034
extern undefined l_HIO;
//[BSS] Expected size is 0x00000c
extern undefined l_msgCtrl;
//[BSS] Expected size is 0x000004
extern undefined4 l_gbaCommand;
}
//[BSS] Expected size is 0x000004
extern undefined1 daAgb_c;
//[BSS] Expected size is 0x000004
extern undefined1 daAgb_c;
//[BSS] Expected size is 0x000008
extern undefined1 daAgb_c;
//[BSS] Expected size is 0x000008
extern undefined1 daAgb_c;
//[BSS] Expected size is 0x000004
extern undefined1 daAgb_c;
//[BSS] Expected size is 0x000004
extern undefined1 daAgb_c;

namespace d_a_agb {
//[BSS] Expected size is 0x000001
extern undefined1 se_flag$4619;
//[BSS] Expected size is 0x000001
extern undefined1 init$4620;
}

namespace d_a_agb {
uint sjis2chrNo(char param_1);
}

namespace d_a_agb {
undefined4 daAgb_Execute(daAgb_c *param_1);
undefined4 daAgb_Draw(int param_1);
}

namespace d_a_agb {
undefined4 daAgb_IsDelete(void);
undefined4 daAgb_Delete(int param_1);
void createHeap_CB(daAgb_c *param_1);
}

namespace d_a_agb {
PhaseState daAgb_Create(daAgb_c *pthis);
}

namespace d_a_agb {
void __sinit_d_a_agb_cpp(void);
}
