#pragma once
#include <ctypes.h>


//[Data] Expected size is 0x000018
extern pointer cBgS;

//[Data] Expected size is 0x000010
extern pointer cBgS_ChkElm;


namespace SComponent {
//[BSS] Expected size is 0x000004
extern undefined4 l_SetCounter;
}

namespace cBgS {
cBgD_t * ConvDzb(cBgD_t *pDt);
}
