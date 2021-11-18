#pragma once
#include <ctypes.h>



namespace SComponent {
//[Data] Expected size is 0x000802
extern undefined atntable;

//[BSS] Expected size is 0x000004
extern undefined4 r0;
//[BSS] Expected size is 0x000004
extern undefined4 r1;
//[BSS] Expected size is 0x000004
extern undefined4 r2;
//[BSS] Expected size is 0x000004
extern undefined4 r02;
//[BSS] Expected size is 0x000004
extern undefined4 r12;
//[BSS] Expected size is 0x000004
extern undefined4 r22;
int cM_rad2s(double param_1);
undefined2 U_GetAtanTable(double param_1,double param_2);
int cM_atan2s(float param_1,float param_2);
double cM_atan2f(double param_1,double param_2);
void cM_initRnd(undefined4 param_1,undefined4 param_2,undefined4 param_3);
float cM_rnd(float param_1);
float cM_rndF(float param_1);
float cM_rndFX(float param_1);
void cM_initRnd2(undefined4 param_1,undefined4 param_2,undefined4 param_3);
}
