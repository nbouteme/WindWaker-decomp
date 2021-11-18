#pragma once
#include <ctypes.h>



namespace d_chain {
//[Data] Expected size is 0x000200
extern undefined l_chainS3TCTEX;

//[Data] Expected size is 0x000090
extern undefined l_pos;

//[Data] Expected size is 0x000060
extern undefined l_texCoord;

//[Data] Expected size is 0x00007a
extern undefined l_chainDL;

//[Data] Expected size is 0x0000a8
extern undefined l_matDL;

}
//[Data] Expected size is 0x000018
extern undefined1 dChain_packet_c;


namespace d_chain {
dChain_packet_c * dChain_packet_create(double param_1,int param_2,dKy_tevstr_c *param_3);
void __sinit_d_chain_cpp(void);
}
