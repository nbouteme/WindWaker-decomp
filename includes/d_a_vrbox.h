#pragma once
#include <ctypes.h>



namespace d_a_vrbox {
undefined4 daVrbox_Draw(vrbox_class *param_1);
undefined4 daVrbox_color_set(vrbox_class *param_1);
}

namespace d_a_vrbox {
void dungeon_rain_proc(void);
undefined4 daVrbox_Execute(void);
undefined4 daVrbox_IsDelete(void);
undefined4 daVrbox_Delete(void);
undefined4 daVrbox_solidHeapCB(vrbox_class *param_1);
undefined4 daVrbox_Create(vrbox_class *param_1);
}
