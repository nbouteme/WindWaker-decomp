#pragma once
#include <ctypes.h>

#include <profile_method_class.h>
#include <daSea_packet_c.h>
#include <f_pc_profile__Profile_Actor.h>


namespace d_a_sea {
//[Data] Expected size is 0x000060
extern struct daSea_WaveInfo__Table wi_prm_ocean[4];

//[Data] Expected size is 0x000010
extern sbyte pos_around[16];

//[Data] Expected size is 0x000020
extern struct profile_method_class l_daSea_Method;

//[Data] Expected size is 0x000030
extern struct f_pc_profile__Profile_Actor g_profile_SEA;

}
//[Data] Expected size is 0x000018
extern undefined daSea_packet_c;

//[Data] Expected size is 0x00000c
extern undefined1 cM2dGBox;

//[Data] Expected size is 0x00000c
extern pointer daSea_WaterHeightInfo_Mng;

//[Data] Expected size is 0x00000c
extern pointer daSea_WaveInfo;

//[Data] Expected size is 0x000004
extern float daSea_packet_c;


namespace d_a_sea {
//[BSS] Expected size is 0x000148
extern struct daSea_packet_c l_cloth;
//[BSS] Expected size is 0x000018
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
