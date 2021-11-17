#pragma once
#include <ctypes.h>



namespace JPADrawContext {
//Expected size is 0x000004
extern struct JPADrawSetupTev * pcb;

}

namespace JPADraw {
void dirTypeVel(int param_1,undefined4 param_2,undefined4 *param_3);
void dirTypePos(int param_1,undefined4 param_2,undefined4 *param_3);
void dirTypePosInv(int param_1,undefined4 param_2,float *param_3);
void dirTypeEmtrDir(undefined4 param_1,undefined4 param_2,undefined4 *param_3);
void dirTypePrevPtcl(int param_1,JPABaseEmitter *param_2,TVec3<float> *param_3);
void rotTypeY(double param_1,double param_2,float *param_3);
void rotTypeX(double param_1,double param_2,float *param_3);
void rotTypeZ(double param_1,double param_2,float *param_3);
void rotTypeXYZ(double param_1,double param_2,float *param_3);
void rotTypeYJiggle(double param_1,double param_2,float *param_3);
void basePlaneTypeXY(double param_1,double param_2,double param_3,double param_4,float *param_5);
void basePlaneTypeXZ(double param_1,double param_2,double param_3,double param_4,cXyz *param_5);
}

namespace JPADraw {
undefined4 stripeGetNext(int param_1);
undefined4 stripeGetPrev(int param_1);
}
