#include <mtx/mtx44.h>
#include <MSL_C.PPCEABI.bare.H/math_ppc.h>


namespace mtx {

void C_MTXPerspective
               (double param_1,double param_2,double param_3,double param_4,float *param_5)

{
  float fVar1;
  float fVar2;
  double dVar3;
  float fVar4;
  
  fVar4 = MSL_C.PPCEABI.bare.H::tanf(_106 * (float)((double)_105 * param_1));
  fVar1 = _99;
  fVar4 = _99 / fVar4;
  *param_5 = (float)((double)fVar4 / param_2);
  fVar2 = _101;
  dVar3 = (double)(fVar1 / (float)(param_4 - param_3));
  param_5[1] = _101;
  param_5[2] = fVar2;
  param_5[3] = fVar2;
  param_5[4] = fVar2;
  param_5[5] = fVar4;
  param_5[6] = fVar2;
  param_5[7] = fVar2;
  param_5[8] = fVar2;
  param_5[9] = fVar2;
  param_5[10] = (float)(-param_3 * dVar3);
  param_5[0xb] = (float)(dVar3 * -(double)(float)(param_4 * param_3));
  param_5[0xc] = fVar2;
  param_5[0xd] = fVar2;
  param_5[0xe] = _102;
  param_5[0xf] = fVar2;
  return;
}


void C_MTXOrtho(float param_1,float param_2,float param_3,float param_4,float param_5,
                    float param_6,MTX44 *param_7)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  fVar5 = _100;
  fVar4 = _99;
  fVar1 = _99 / (param_4 - param_3);
  fVar2 = _99 / (param_1 - param_2);
  param_7->m[0] = _100 * fVar1;
  fVar6 = _101;
  param_7->m[1] = _101;
  fVar3 = fVar4 / (param_6 - param_5);
  param_7->m[2] = fVar6;
  param_7->m[3] = fVar1 * -(param_4 + param_3);
  param_7->m[1][0] = fVar6;
  param_7->m[1][1] = fVar5 * fVar2;
  param_7->m[1][2] = fVar6;
  param_7->m[1][3] = fVar2 * -(param_1 + param_2);
  param_7->m[2][0] = fVar6;
  param_7->m[2][1] = fVar6;
  param_7->m[2][2] = _102 * fVar3;
  param_7->m[2][3] = -param_6 * fVar3;
  param_7->m[3][0] = fVar6;
  param_7->m[3][1] = fVar6;
  param_7->m[3][2] = fVar6;
  param_7->m[3][3] = fVar4;
  return;
}

