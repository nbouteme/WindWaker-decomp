#pragma once
#include <ctypes.h>


//Expected size is 0x000004
extern undefined4 d_s_menu;

//Expected size is 0x000004
extern undefined4 d_s_menu;

//Expected size is 0x000004
extern undefined4 d_s_menu;

//Expected size is 0x000002
extern undefined2 d_s_menu;

//Expected size is 0x000002
extern undefined2 d_s_menu;

//Expected size is 0x000004
extern undefined4 d_s_menu;

//Expected size is 0x000001
extern undefined1 d_s_menu;


namespace d_s_menu {
undefined4 dScnMenu_Draw(d_s_menu *param_1);
undefined4 dScnMenu_Execute(d_s_menu *param_1);
undefined4 dScnMenu_IsDelete(void);
undefined4 dScnMenu_Delete(d_s_menu *param_1);
undefined4 phase_1(d_s_menu *param_1);
int phase_2(d_s_menu *param_1);
void dScnMenu_Create(d_s_menu *param_1);
}
