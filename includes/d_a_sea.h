#pragma once
#include <ctypes.h>

#include <daSea_packet_c.h>


namespace d_a_sea {
//Expected size is 0x000148
extern struct daSea_packet_c l_cloth;

//Expected size is 0x000018
extern float offset$4646[6];

}

namespace d_a_sea {
byte get_wave_max(uint param_1);
}

namespace d_a_sea {
void calcMinMax(uint param_1,float *param_2,float *param_3);
}

namespace d_a_sea {
void daSea_Init(void);
int daSea_ChkAreaBeforePos(double param_1,double param_2);
int daSea_ChkArea(float param_1,float param_2);
double daSea_calcWave(double param_1,double param_2);
void daSea_GetPoly(undefined4 param_1,code *param_2,cXyz *param_3,cXyz *param_4);
}

namespace d_a_sea {
void daSea_execute(cXyz *param_1);
}

namespace d_a_sea {
undefined4 daSea_Draw(void);
undefined4 daSea_Execute(void);
undefined4 daSea_IsDelete(void);
undefined4 daSea_Delete(void);
undefined CheckCreateHeap(fopAc_ac_c *param_1);
undefined4 daSea_Create(fopAc_ac_c *param_1);
}

namespace d_a_sea {
void __sinit_d_a_sea_cpp(void);
}
