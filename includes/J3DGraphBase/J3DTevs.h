#pragma once
#include <ctypes.h>



namespace J3DGraphBase {
//Expected size is 0x001dc7
extern undefined1 j3dTexCoordTable;

//Expected size is 0x000400
extern undefined1 j3dTevSwapTableTable;

//Expected size is 0x000300
extern undefined1 j3dAlphaCmpTable;

//Expected size is 0x000060
extern undefined1 j3dZModeTable;

//Expected size is 0x000004
extern undefined4 dualReg$1374;

//Expected size is 0x000001
extern undefined1 init$1375;

}

namespace J3DGraphBase {
void loadTexCoordGens(uint param_1,int param_2);
}

namespace J3DGraphBase {
undefined4 isTexNoReg(int param_1);
uint getTexNoReg(int param_1);
void loadTexNo(int param_1,ushort *param_2);
void patchTexNo_PtrToIdx(undefined4 param_1,undefined2 *param_2);
void loadNBTScale(char *param_1);
void makeTexCoordTable(void);
void makeAlphaCmpTable(void);
void makeZModeTable(void);
void makeTevSwapTable(void);
}
