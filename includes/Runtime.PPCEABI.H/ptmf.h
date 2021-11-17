#pragma once
#include <ctypes.h>



namespace Runtime.PPCEABI.H {
bool __ptmf_test(PTMF *param_1);
bool __ptmf_cmpr(PTMF *ptmf1,PTMF *ptmf2);
void __ptmf_scall(PTMF *ptmf,void *this,void *param_3);
}
