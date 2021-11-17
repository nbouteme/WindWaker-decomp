#pragma once
#include <ctypes.h>



namespace JUtility {
//Expected size is 0x000014
extern undefined4 exCallbackObject;

}
//Expected size is 0x00000c
extern undefined1 JUTException;

//Expected size is 0x000004
extern struct JUTException * JUTException;

//Expected size is 0x000004
extern undefined1 JUTException;

//Expected size is 0x000004
extern undefined1 JUTException;

//Expected size is 0x000004
extern undefined1 JUTException;

//Expected size is 0x000004
extern undefined1 JUTException;

//Expected size is 0x000004
extern undefined1 JUTException;

//Expected size is 0x000004
extern undefined1 JUTException;

//Expected size is 0x000004
extern undefined1 JUTException;


namespace JUTException {
JUTException * create(JUTDirectPrint *param_1);
}

namespace JUtility {
void search_name_part(char *param_1,char *param_2,int param_3);
}

namespace JUTException {
void waitTime(long param_1);
}

namespace JUTException {
undefined4 setPreUserCallback(FuncDef590 *param_1);
undefined4 setPostUserCallback(FuncDef591 *param_1);
void appendMapFile(char *param_1);
}

namespace JUtility {
void __sinit_JUTException_cpp(void);
}
