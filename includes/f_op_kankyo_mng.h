#pragma once
#include <ctypes.h>



namespace f_op_kankyo_mng {
void fopKyM_SearchByID(uint param_1);
fopKyM_prm_class * fopKyM_CreateAppend(void);
undefined4 * createAppend(int prm,cXyz *param_2,cXyz *param_3);
void fopKyM_Delete(base_process_class *param_1);
void fopKyM_Create(short param_1,undefined *param_2,void *param_3);
undefined4 fopKyM_create(int procName,int parameter,cXyz *pPos,cXyz *pScale,undefined4 param_5);
undefined4 fopKyM_fastCreate(undefined4 param_1,int param_2,cXyz *param_3,cXyz *param_4,undefined4 param_5);
undefined4 fopKyM_createWpillar(double param_1,double param_2,float *param_3,int param_4);
undefined4 fopKyM_createMpillar(double param_1,cXyz *param_2);
}
