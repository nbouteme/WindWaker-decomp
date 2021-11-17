#pragma once
#include <ctypes.h>



namespace d_a_agb {
//Expected size is 0x000034
extern undefined l_HIO;

//Expected size is 0x00000c
extern undefined l_msgCtrl;

//Expected size is 0x000004
extern undefined4 l_gbaCommand;

}
//Expected size is 0x000004
extern undefined1 daAgb_c;

//Expected size is 0x000004
extern undefined1 daAgb_c;

//Expected size is 0x000008
extern undefined1 daAgb_c;

//Expected size is 0x000008
extern undefined1 daAgb_c;

//Expected size is 0x000004
extern undefined1 daAgb_c;

//Expected size is 0x000004
extern undefined1 daAgb_c;


namespace d_a_agb {
//Expected size is 0x000001
extern undefined1 se_flag$4619;

//Expected size is 0x000001
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
