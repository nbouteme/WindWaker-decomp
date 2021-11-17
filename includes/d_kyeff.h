#pragma once
#include <ctypes.h>



namespace d_kyeff {
undefined4 dKyeff_Draw(void);
double get_parcent(double param_1,double param_2,double param_3);
int s16_data_ratio_set(double param_1,short param_2,short param_3);
void menu_vrbox_set(void);
}

namespace d_kyeff {
void dKyeff_Execute(dKyeff_c *param_1);
undefined4 dKyeff_IsDelete(void);
undefined4 dKyeff_Delete(void);
undefined4 dKyeff_Create(void);
}
