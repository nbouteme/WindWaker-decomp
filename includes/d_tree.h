#pragma once
#include <ctypes.h>



namespace d_tree {
//[Data] Expected size is 0x000800
extern undefined l_Txa_swood_aTEX;

//[Data] Expected size is 0x0003cc
extern undefined l_pos;

//[Data] Expected size is 0x000028
extern undefined l_color;

//[Data] Expected size is 0x000080
extern undefined l_texCoord;

//[Data] Expected size is 0x000025
extern undefined l_Oba_swood_noneDL;

//[Data] Expected size is 0x0000af
extern undefined l_Oba_swood_a_cuttDL;

//[Data] Expected size is 0x000067
extern undefined l_Oba_swood_a_cutuDL;

//[Data] Expected size is 0x000164
extern undefined l_Oba_swood_a_hapaDL;

//[Data] Expected size is 0x0000c2
extern undefined l_Oba_swood_a_mikiDL;

//[Data] Expected size is 0x0000a3
extern undefined l_matDL;

//[Data] Expected size is 0x000200
extern undefined l_Txa_kage_32TEX;

//[Data] Expected size is 0x00000c
extern undefined g_dTree_shadowPos;

//[Data] Expected size is 0x00002b
extern undefined g_dTree_Oba_kage_32DL;

//[Data] Expected size is 0x000090
extern undefined g_dTree_shadowMatDL;

//[Data] Expected size is 0x000018
extern undefined l_shadowVtxDescList$4654;

//[Data] Expected size is 0x000030
extern undefined l_shadowVtxAttrFmtList$4655;

//[Data] Expected size is 0x000020
extern undefined l_vtxDescList$4669;

//[Data] Expected size is 0x000040
extern undefined l_vtxAttrFmtList$4670;

//[Data] Expected size is 0x000028
extern pointer l_modelDataStatus$4682;

}
//[Data] Expected size is 0x000018
extern undefined1 dTree_packet_c;


namespace d_tree {
//[Data] Expected size is 0x000008
extern undefined g_dTree_shadowTexCoord;

//[Data] Expected size is 0x000004
extern undefined4 l_shadowColor$4656;

//[Data] Expected size is 0x000006
extern undefined l_modelStatus$4683;

//[BSS] Expected size is 0x00000c
extern undefined4 l_particleOffset$4492;
//[BSS] Expected size is 0x00000c
extern undefined4 l_scale$4496;
}
//[BSS] Expected size is 0x000020
extern undefined1 dTree_data_c;

namespace d_tree {
//[BSS] Expected size is 0x000001
extern undefined1 l_CutSoundFlag;
//[BSS] Expected size is 0x000001
extern undefined1 init$4494;
//[BSS] Expected size is 0x000001
extern undefined1 init$4498;
}

namespace d_tree {
double checkGroundY(dTree_data_c *param_1,cXyz *param_2);
}

namespace d_tree {
void __sinit_d_tree_cpp(void);
}
