#pragma once
#include <ctypes.h>

#include <MTX34.h>


namespace d_magma {
//[Data] Expected size is 0x000030
extern undefined l_YfloorPos;

//[Data] Expected size is 0x000027
extern undefined l_YfloorDL;

//[Data] Expected size is 0x000055
extern undefined l_YfloorMatDL;

//[Data] Expected size is 0x00018c
extern undefined l_YballPos;

//[Data] Expected size is 0x000076
extern undefined l_YballDL;

//[Data] Expected size is 0x00004b
extern undefined l_YballMatDL;

//[Data] Expected size is 0x00000c
extern undefined1 l_keyColor$4298;

}
//[Data] Expected size is 0x000018
extern undefined1 dMagma_packet_c;

//[Data] Expected size is 0x000018
extern undefined1 dMagma_ball_c;

//[Data] Expected size is 0x000018
extern pointer dMagma_ballPath_c;


namespace d_magma {
//[BSS] Expected size is 0x000030
extern struct MTX34 l_kuroOrthoMtx;
//[BSS] Expected size is 0x000030
extern struct MTX34 l_colOrthoMtx;
}
//[BSS] Expected size is 0x000020
extern GXTexObj dMagma_packet_c;
//[BSS] Expected size is 0x000030
extern struct MTX34 dMagma_packet_c;
//[BSS] Expected size is 0x000020
extern GXTexObj dMagma_packet_c;
//[BSS] Expected size is 0x000030
extern struct MTX34 dMagma_packet_c;
//[BSS] Expected size is 0x000030
extern struct MTX34 dMagma_packet_c;

namespace dMagma_ball_c {
void draw(dMagma_ballPath_c *this);
undefined4 rangeCheck(dMagma_ballPath_c *this,cXyz *pPos,float *param_3);
}

namespace d_magma {
double morfCalc(double param_1,double param_2,double param_3);
}
