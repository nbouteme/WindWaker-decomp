#pragma once
#include <ctypes.h>



namespace mtx {
void PSMTXMultVec(MTX34 *pMtx,cXyz *pSrc,cXyz *pDst);
void PSMTXMultVecArray(int param_1,int param_2,int param_3,int param_4);
undefined8 PSMTXMultVecSR(int param_1,int param_2,int param_3);
}
