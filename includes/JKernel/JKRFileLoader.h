#pragma once
#include <ctypes.h>

#include <JSUPtrList.h>

//[Data] Expected size is 0x00003c
extern pointer JKRFileLoader;


namespace JKernel {
//[Data] Expected size is 0x000002
extern undefined rootPath$2460;

}
//[BSS] Expected size is 0x00000c
extern struct JSUPtrList JKRFileLoader;
//[BSS] Expected size is 0x000004
extern undefined1 JKRFileLoader;

namespace JKRFileLoader {
undefined4 getGlbResource(char *param_1);
int getGlbResource(char *param_1,JKRFileLoader *param_2);
undefined4 removeResource(void *param_1,JKRFileLoader *param_2);
}

namespace JKRFileLoader {
int findVolume(char **param_1);
char * fetchVolumeName(char *param_1,long param_2,char *param_3);
}

namespace JKernel {
void __sinit_JKRFileLoader_cpp(void);
}
