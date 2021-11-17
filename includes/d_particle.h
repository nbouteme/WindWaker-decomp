#pragma once
#include <ctypes.h>

#include <cXyz.h>


namespace d_particle {
//Expected size is 0x00000c
extern struct cXyz pos$5010;

}
//Expected size is 0x000020
extern undefined dPa_control_c;

//Expected size is 0x000018
extern undefined1 dPa_control_c;

//Expected size is 0x000020
extern undefined1 dPa_control_c;

//Expected size is 0x000030
extern undefined1 dPa_control_c;


namespace d_particle {
//Expected size is 0x000020
extern char jpcName$5165[32];

}
//Expected size is 0x000004
extern struct dPa_J3Dmodel_c * dPa_modelControl_c;


namespace d_particle {
//Expected size is 0x000001
extern undefined1 init$4530;

//Expected size is 0x000004
extern undefined4 l_smokePcallBack$4528;

//Expected size is 0x000001
extern undefined1 init$4932;

//Expected size is 0x000004
extern undefined4 l_windPcallBack$4930;

//Expected size is 0x000001
extern undefined1 init$5011;

}
//Expected size is 0x000004
extern struct JPAEmitterManager * dPa_control_c;

//Expected size is 0x000004
extern undefined1 dPa_control_c;

//Expected size is 0x000004
extern undefined1 dPa_control_c;

//Expected size is 0x000004
extern undefined1 dPa_control_c;

//Expected size is 0x000004
extern undefined1 dPa_control_c;

//Expected size is 0x000004
extern undefined1 dPa_control_c;

//Expected size is 0x000004
extern undefined1 dPa_control_c;

//Expected size is 0x000001
extern undefined1 dPa_control_c;


namespace d_particle {
void initiateLighting(_GXColorS10 *param_1,_GXColor *param_2,_GXColor *param_3);
void smokeEcallBack(JPABaseEmitter *param_1,dKy_tevstr_c *param_2,sbyte param_3,_GXColor *param_4);
}

namespace d_particle {
void dPa_setWindPower(JPABaseParticle *pPtcl);
}

namespace dPa_control_c {
ushort getRM_ID(ushort userID);
}

namespace d_particle {
int cLib_calcTimer(int *param_1);
void __sinit_d_particle_cpp(void);
}
