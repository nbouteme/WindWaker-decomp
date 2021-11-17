#pragma once
#include <ctypes.h>

#include <MTX34.h>


namespace d_magma {
//Expected size is 0x000030
extern struct MTX34 l_kuroOrthoMtx;

//Expected size is 0x000030
extern struct MTX34 l_colOrthoMtx;

}
//Expected size is 0x000020
extern GXTexObj dMagma_packet_c;

//Expected size is 0x000030
extern struct MTX34 dMagma_packet_c;

//Expected size is 0x000020
extern GXTexObj dMagma_packet_c;

//Expected size is 0x000030
extern struct MTX34 dMagma_packet_c;

//Expected size is 0x000030
extern struct MTX34 dMagma_packet_c;


namespace dMagma_ball_c {
void draw(dMagma_ballPath_c *this);
undefined4 rangeCheck(dMagma_ballPath_c *this,cXyz *pPos,float *param_3);
}

namespace d_magma {
double morfCalc(double param_1,double param_2,double param_3);
}
