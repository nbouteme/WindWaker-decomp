#pragma once
#include <ctypes.h>



namespace gx {
void GXInitLightAttn(_GXLightObj *param_1,double param_2,double param_3,double param_4,double param_5,double param_6,double param_7);
void GXInitLightSpot(_GXLightObj *param_1,float param_2,GXSpotFn param_3);
void GXInitLightDistAttn(_GXLightObj *param_1,float param_2,float param_3,GXDistAttnFn param_4);
void GXInitLightPos(double param_1,double param_2,double param_3,_GXLightObj *param_4);
void GXInitLightDir(double param_1,double param_2,double param_3,_GXLightObj *param_4);
void GXInitLightColor(_GXLightObj *param_1,_GXColor *param_2);
void GXLoadLightObjImm(_GXLightObj *param_1,GXLightID param_2);
void GXSetChanAmbColor(int param_1,uint *param_2);
void GXSetChanMatColor(int param_1,uint *param_2);
void GXSetNumChans(uint param_1);
void GXSetChanCtrl(GXChannelID param_1,bool param_2,GXColorSrc param_3,GXColorSrc param_4,int lightMask,GXDiffuseFn param_6,GXAttnFn param_7);
}
