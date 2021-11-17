#pragma once
#include <ctypes.h>



namespace gx {
int GXGetTexBufferSize(uint param_1,uint param_2,int param_3,char param_4,uint param_5);
void __GetImageTileCount(int param_1,ushort param_2,ushort param_3,int *param_4,int *param_5,undefined4 *param_6);
void GXInitTexObj(GXTexObj *param_1,void *param_2,uint param_3,uint param_4,_GXTexFmt format,_GXTexWrapMode wrap_s,_GXTexWrapMode wrap_t,bool mipmap);
void GXInitTexObjCI(GXTexObj *param_1,void *param_2,uint param_3,uint param_4,_GXTexFmt param_5,_GXTexWrapMode param_6,_GXTexWrapMode param_7,bool param_8,u32 param_9);
void GXInitTexObjLOD(double param_1,double param_2,double param_3,uint *param_4,int param_5,int param_6,uint param_7,char param_8,int param_9);
int GXGetTexObjData(int param_1);
int GXGetTexObjWidth(int param_1);
int GXGetTexObjHeight(int param_1);
undefined4 GXGetTexObjFmt(int param_1);
uint GXGetTexObjWrapS(uint *param_1);
uint GXGetTexObjWrapT(uint *param_1);
undefined4 GXGetTexObjTlut(int param_1);
void GXLoadTexObjPreLoaded(uint *param_1,uint *param_2,int param_3);
void GXLoadTexObj(GXTexObj *param_1,int param_2);
void GXInitTlutObj(uint *param_1,uint param_2,int param_3,undefined2 param_4);
void GXLoadTlut(uint *param_1,undefined4 param_2);
void GXInitTexCacheRegion(uint *param_1,undefined param_2,uint param_3,int param_4,uint param_5,int param_6,undefined4 param_7,int param_8);
void GXInitTlutRegion(uint *param_1,int param_2,int param_3);
void GXInvalidateTexAll(void);
undefined4 GXSetTexRegionCallback(undefined4 param_1);
undefined4 GXSetTlutRegionCallback(undefined4 param_1);
void GXSetTexCoordScaleManually(int param_1,uint param_2,int param_3,int param_4);
void GXSetTexCoordBias(int param_1,uint param_2,uint param_3);
void __SetSURegs(int param_1,int param_2);
void __GXSetSUTexRegs(void);
void __GXSetTmemConfig(int param_1);
}
