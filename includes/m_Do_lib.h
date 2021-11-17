#pragma once
#include <ctypes.h>

#include <J3DUClipper.h>

//Expected size is 0x00005c
extern struct J3DUClipper mDoLib_clipper;

//Expected size is 0x000004
extern float mDoLib_clipper;

//Expected size is 0x000004
extern float mDoLib_clipper;


namespace m_Do_lib {
byte mDoLib_setResTimgObj(ResTIMG *pResTIMG,GXTexObj *pTex,long param_3,GXTlutObj *param_4);
}

namespace mDoLib_clipper {
void setup(float fovy,float aspect,float near,float far);
}

namespace m_Do_lib {
void mDoLib_project(cXyz *param_1,cXyz *param_2);
void mDoLib_pos2camera(cXyz *param_1,cXyz *param_2);
undefined4 mDoLib_cnvind32(undefined4 param_1);
undefined2 mDoLib_cnvind16(undefined2 param_1);
void __sinit_m_Do_lib_cpp(undefined4 param_1,EVP_PKEY_CTX *param_2);
}
