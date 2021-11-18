#pragma once
#include <ctypes.h>

#include <cXyz.h>
#include <dPa_levelEcallBack__vtbl.h>


namespace d_particle {
//[Data] Expected size is 0x00000c
extern undefined1 l_lifeBallColor;

}
//[Data] Expected size is 0x000020
extern undefined1 dPa_trackEcallBack;

//[Data] Expected size is 0x000020
extern undefined1 dPa_bombSmokeEcallBack;

//[Data] Expected size is 0x00001c
extern undefined1 dPa_kageroEcallBack;

//[Data] Expected size is 0x000020
extern undefined1 dPa_stripesEcallBack;

//[Data] Expected size is 0x000020
extern undefined1 dPa_cutTurnEcallBack_c;

//[Data] Expected size is 0x000020
extern undefined1 dPa_splashEcallBack;

//[Data] Expected size is 0x000020
extern undefined1 dPa_waveEcallBack;

//[Data] Expected size is 0x000018
extern undefined1 dPa_ripplePcallBack;

//[Data] Expected size is 0x000020
extern undefined1 dPa_singleRippleEcallBack;

//[Data] Expected size is 0x000020
extern undefined1 dPa_rippleEcallBack;

//[Data] Expected size is 0x000018
extern undefined1 dPa_windPcallBack;

//[Data] Expected size is 0x00001c
extern undefined1 dPa_simpleEcallBack;

//[Data] Expected size is 0x000020
extern undefined1 dPa_selectTexEcallBack;

//[Data] Expected size is 0x000018
extern undefined1 dPa_smokePcallBack;

//[Data] Expected size is 0x000024
extern struct dPa_levelEcallBack__vtbl dPa_smokeEcallBack;

//[Data] Expected size is 0x000018
extern undefined1 JPACallBackBase2<JPABaseEmitter*,JPABaseParticle*>;

//[Data] Expected size is 0x000024
extern undefined1 dPa_followEcallBack;

//[Data] Expected size is 0x000010
extern undefined1 dPa_J3DmodelEmitter_c;

//[Data] Expected size is 0x000010
extern undefined1 dPa_modelEmitter_c;

//[Data] Expected size is 0x000020
extern undefined1 dPa_setColorEcallBack;


namespace d_particle {
//[BSS] Expected size is 0x00000c
extern struct cXyz pos$5010;
}
//[BSS] Expected size is 0x000020
extern undefined dPa_control_c;
//[BSS] Expected size is 0x000018
extern undefined1 dPa_control_c;
//[BSS] Expected size is 0x000020
extern undefined1 dPa_control_c;
//[BSS] Expected size is 0x000030
extern undefined1 dPa_control_c;

namespace d_particle {
//[BSS] Expected size is 0x000020
extern char jpcName$5165[32];
}
//[BSS] Expected size is 0x000004
extern struct dPa_J3Dmodel_c * dPa_modelControl_c;

namespace d_particle {
//[BSS] Expected size is 0x000001
extern undefined1 init$4530;
//[BSS] Expected size is 0x000004
extern undefined4 l_smokePcallBack$4528;
//[BSS] Expected size is 0x000001
extern undefined1 init$4932;
//[BSS] Expected size is 0x000004
extern undefined4 l_windPcallBack$4930;
//[BSS] Expected size is 0x000001
extern undefined1 init$5011;
}
//[BSS] Expected size is 0x000004
extern struct JPAEmitterManager * dPa_control_c;
//[BSS] Expected size is 0x000004
extern undefined1 dPa_control_c;
//[BSS] Expected size is 0x000004
extern undefined1 dPa_control_c;
//[BSS] Expected size is 0x000004
extern undefined1 dPa_control_c;
//[BSS] Expected size is 0x000004
extern undefined1 dPa_control_c;
//[BSS] Expected size is 0x000004
extern undefined1 dPa_control_c;
//[BSS] Expected size is 0x000004
extern undefined1 dPa_control_c;
//[BSS] Expected size is 0x000001
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
