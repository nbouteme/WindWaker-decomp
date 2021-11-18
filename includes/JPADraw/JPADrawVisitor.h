#pragma once
#include <ctypes.h>


//[Data] Expected size is 0x000010
extern undefined1 JPADrawCalcChildScaleOut;

//[Data] Expected size is 0x000010
extern undefined1 JPADrawCalcParticleVisitor;

//[Data] Expected size is 0x000010
extern undefined1 JPADrawCalcChildAlphaOut;

//[Data] Expected size is 0x000010
extern undefined1 JPADrawCalcAlphaFlickMultSin;

//[Data] Expected size is 0x000010
extern undefined1 JPADrawCalcAlphaFlickAddSin;

//[Data] Expected size is 0x000010
extern undefined1 JPADrawCalcAlphaFlickNrmSin;

//[Data] Expected size is 0x000010
extern undefined1 JPADrawCalcAlpha;

//[Data] Expected size is 0x000010
extern undefined1 JPADrawCalcColorCopyFromEmitter;

//[Data] Expected size is 0x000010
extern undefined1 JPADrawCalcScaleAnmTimingReverseY;

//[Data] Expected size is 0x000010
extern undefined1 JPADrawCalcScaleAnmTimingReverseX;

//[Data] Expected size is 0x000010
extern undefined1 JPADrawCalcScaleAnmTimingRepeatY;

//[Data] Expected size is 0x000010
extern undefined1 JPADrawCalcScaleAnmTimingRepeatX;

//[Data] Expected size is 0x000010
extern undefined1 JPADrawCalcScaleAnmTimingNormal;

//[Data] Expected size is 0x000010
extern undefined1 JPADrawCalcScaleCopyX2Y;

//[Data] Expected size is 0x000010
extern undefined1 JPADrawCalcScaleYBySpeed;

//[Data] Expected size is 0x000010
extern undefined1 JPADrawCalcScaleXBySpeed;

//[Data] Expected size is 0x000010
extern undefined1 JPADrawCalcScaleY;

//[Data] Expected size is 0x000010
extern undefined1 JPADrawCalcScaleX;

//[Data] Expected size is 0x000024
extern pointer JPADrawExecCallBack;

//[Data] Expected size is 0x000010
extern undefined1 JPADrawExecEmitterVisitor;

//[Data] Expected size is 0x000010
extern undefined1 JPADrawExecParticleVisitor;

//[Data] Expected size is 0x000024
extern undefined1 JPADrawCalcTextureAnmIndexRandom;

//[Data] Expected size is 0x000010
extern undefined1 JPADrawCalcEmitterVisitor;

//[Data] Expected size is 0x000024
extern undefined1 JPADrawCalcTextureAnmIndexMerge;

//[Data] Expected size is 0x000024
extern undefined1 JPADrawCalcTextureAnmIndexReverse;

//[Data] Expected size is 0x000024
extern undefined1 JPADrawCalcTextureAnmIndexRepeat;

//[Data] Expected size is 0x000024
extern undefined1 JPADrawCalcTextureAnmIndexNormal;

//[Data] Expected size is 0x000024
extern undefined1 JPADrawCalcColorAnmFrameRandom;

//[Data] Expected size is 0x000024
extern undefined1 JPADrawCalcColorAnmFrameMerge;

//[Data] Expected size is 0x000024
extern undefined1 JPADrawCalcColorAnmFrameReverse;

//[Data] Expected size is 0x000024
extern undefined1 JPADrawCalcColorAnmFrameRepeat;

//[Data] Expected size is 0x000024
extern undefined1 JPADrawCalcColorAnmFrameNormal;

//[Data] Expected size is 0x000024
extern undefined1 JPADrawCalcColorEnv;

//[Data] Expected size is 0x000024
extern pointer JPADrawCalcColorPrm;

//[Data] Expected size is 0x000010
extern undefined1 JPADrawExecRegisterColorChildPE;

//[Data] Expected size is 0x000010
extern undefined1 JPADrawExecRegisterColorEmitterE;

//[Data] Expected size is 0x000010
extern undefined1 JPADrawExecRegisterColorEmitterP;

//[Data] Expected size is 0x000010
extern undefined1 JPADrawExecRegisterColorEmitterPE;

//[Data] Expected size is 0x000010
extern undefined1 JPADrawExecStripeCross;

//[Data] Expected size is 0x000010
extern undefined1 JPADrawExecStripe;

//[Data] Expected size is 0x000010
extern undefined1 JPADrawExecLine;

//[Data] Expected size is 0x000010
extern undefined1 JPADrawExecPoint;

//[Data] Expected size is 0x000010
extern undefined1 JPADrawExecRotationCross;

//[Data] Expected size is 0x000010
extern undefined1 JPADrawExecRotation;

//[Data] Expected size is 0x000010
extern undefined1 JPADrawExecDirBillBoard;

//[Data] Expected size is 0x000010
extern undefined1 JPADrawExecRotDirectionalCross;

//[Data] Expected size is 0x000010
extern undefined1 JPADrawExecDirectionalCross;

//[Data] Expected size is 0x000010
extern undefined1 JPADrawExecRotDirectional;

//[Data] Expected size is 0x000010
extern undefined1 JPADrawExecDirectional;

//[Data] Expected size is 0x000010
extern undefined1 JPADrawExecRotYBillBoard;

//[Data] Expected size is 0x000010
extern undefined1 JPADrawExecYBillBoard;

//[Data] Expected size is 0x000010
extern undefined1 JPADrawExecRotBillBoard;

//[Data] Expected size is 0x000010
extern undefined1 JPADrawExecBillBoard;

//[Data] Expected size is 0x000010
extern undefined1 JPADrawExecRegisterPrmAEnv;

//[Data] Expected size is 0x000010
extern undefined1 JPADrawExecRegisterPrmCEnv;

//[Data] Expected size is 0x000010
extern undefined1 JPADrawExecRegisterEnvColorAnm;

//[Data] Expected size is 0x000010
extern undefined1 JPADrawExecRegisterPrmAlphaAnm;

//[Data] Expected size is 0x000010
extern undefined1 JPADrawExecRegisterPrmColorAnm;

//[Data] Expected size is 0x000010
extern undefined1 JPADrawExecSetLineWidth;

//[Data] Expected size is 0x000010
extern undefined1 JPADrawExecSetPointSize;

//[Data] Expected size is 0x000024
extern pointer JPADrawExecLoadTexture;

//[Data] Expected size is 0x000010
extern undefined1 JPADrawExecLoadDefaultTexture;

//[Data] Expected size is 0x000024
extern undefined1 JPADrawExecSetTexMtx;

//[Data] Expected size is 0x000010
extern undefined1 JPADrawExecGenIdtMtx;

//[Data] Expected size is 0x000010
extern undefined1 JPADrawExecGenTexMtx0;

//[Data] Expected size is 0x000010
extern undefined1 JPADrawExecGenPrjTexMtx;

//[Data] Expected size is 0x000010
extern undefined1 JPADrawExecGenPrjMtx;

//[Data] Expected size is 0x000010
extern undefined1 JPADrawExecLoadExTex;


namespace JPADrawContext {
//[BSS] Expected size is 0x000004
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
