#pragma once
#include <ctypes.h>



namespace d_grass {
//[Data] Expected size is 0x001000
extern undefined l_K_kusa_00TEX;

//[Data] Expected size is 0x000144
extern float l_Vmori_pos[81];

//[Data] Expected size is 0x000014
extern struct _GXColor l_Vmori_color[5];

//[Data] Expected size is 0x000048
extern float l_Vmori_texCoord[18];

//[Data] Expected size is 0x0000b0
extern undefined l_Vmori_00DL;

//[Data] Expected size is 0x00008c
extern undefined l_Vmori_01DL;

//[Data] Expected size is 0x0000a8
extern undefined l_Vmori_matDL;

//[Data] Expected size is 0x000800
extern undefined l_Txa_ob_kusa_aTEX;

//[Data] Expected size is 0x000144
extern float l_pos[81];

//[Data] Expected size is 0x000020
extern struct _GXColor l_color[8];

//[Data] Expected size is 0x000048
extern float l_texCoord[22];

//[Data] Expected size is 0x0000a7
extern undefined l_Oba_kusa_aDL;

//[Data] Expected size is 0x00008c
extern undefined l_Oba_kusa_a_cutDL;

//[Data] Expected size is 0x0000a8
extern undefined l_matDL;

//[Data] Expected size is 0x000020
extern undefined l_vtxDescList$4528;

//[Data] Expected size is 0x000040
extern undefined l_vtxAttrFmtList$4529;

}
//[Data] Expected size is 0x000018
extern undefined1 dGrass_packet_c;


namespace dCcMassS_HitInf {
//[Data] Expected size is 0x00000c
extern pointer __vt;

}

namespace d_grass {
//[BSS] Expected size is 0x000001
extern undefined1 l_CutSoundFlag;
//[BSS] Expected size is 0x000001
extern undefined1 init$4375;
//[BSS] Expected size is 0x000006
extern undefined ang$4373;
void setBatta(cXyz *param_1,_GXColor *param_2);
}

namespace d_grass {
double checkGroundY(cXyz *pPos);
}

namespace d_grass {
void __sinit_d_grass_cpp(void);
}
