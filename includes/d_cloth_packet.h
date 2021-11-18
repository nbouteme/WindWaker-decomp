#pragma once
#include <ctypes.h>



namespace d_cloth_packet {
//[Data] Expected size is 0x000034
extern undefined l_matDL;

//[Data] Expected size is 0x000034
extern undefined l_alpha_matDL;

}
//[Data] Expected size is 0x000030
extern undefined1 dClothVobj07_0_c;

//[Data] Expected size is 0x000030
extern undefined1 dClothVobj05_c;

//[Data] Expected size is 0x000030
extern undefined1 dClothVobj04_c;

//[Data] Expected size is 0x000030
extern undefined1 dClothVobj03_c;

//[Data] Expected size is 0x000030
extern undefined1 dCloth_packetXlu_c;

//[Data] Expected size is 0x000030
extern pointer dCloth_packet_c;

//[Data] Expected size is 0x000004
extern undefined1 dClothVobj03_c;

//[Data] Expected size is 0x000004
extern undefined1 dClothVobj04_c;

//[Data] Expected size is 0x000004
extern undefined1 dClothVobj05_c;

//[Data] Expected size is 0x000004
extern undefined1 dClothVobj07_0_c;

//[BSS] Expected size is 0x000004
extern undefined1 dClothVobj03_c;
//[BSS] Expected size is 0x000004
extern undefined1 dClothVobj04_c;
//[BSS] Expected size is 0x000004
extern undefined1 dClothVobj05_c;
//[BSS] Expected size is 0x000004
extern undefined1 dClothVobj07_0_c;

namespace d_cloth_packet {
undefined4 default_factor_checkCB(dCloth_packet_c *pPkt,int x,int y);
}

namespace d_cloth_packet {
void get_cloth_anim_sub_factor(cXyz *pPos,cXyz *pOther,cXyz *pDst,float param_4,float param_5);
}

namespace d_cloth_packet {
dCloth_packet_c *dCloth_packet_create(ResTIMG *param_1,ResTIMG *param_2,int param_3,int param_4,float param_5,float param_6,dKy_tevstr_c *param_7,cXyz **param_8);
}

namespace d_cloth_packet {
dCloth_packet_c *dCloth_packetXlu_create(double param_1,double param_2,int param_3,ResTIMG *param_4,int param_5,int param_6,dKy_tevstr_c *param_7,cXyz **param_8);
}

namespace d_cloth_packet {
dCloth_packet_c *dClothVobj03_create(int param_1,ResTIMG *param_2,dKy_tevstr_c *param_3,cXyz **param_4);
}

namespace d_cloth_packet {
dCloth_packet_c *dClothVobj04_create(int param_1,ResTIMG *param_2,dKy_tevstr_c *param_3,cXyz **param_4);
}

namespace d_cloth_packet {
uint dClothVobj05_VtxFactorCB(dCloth_packet_c *pPkt,int x,int y);
dCloth_packet_c *dClothVobj05_create(int param_1,ResTIMG *param_2,dKy_tevstr_c *param_3,cXyz **param_4);
}

namespace d_cloth_packet {
uint dClothVobj07_0_VtxFactorCB(dCloth_packet_c *pPkt,int x,int y);
dCloth_packet_c *dClothVobj07_0_create(int param_1,ResTIMG *param_2,dKy_tevstr_c *param_3,cXyz **param_4);
}
