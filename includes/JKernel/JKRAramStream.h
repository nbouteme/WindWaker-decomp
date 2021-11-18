#pragma once
#include <ctypes.h>


//[Data] Expected size is 0x000010
extern undefined1 JKRAramStream;

//[Data] Expected size is 0x000020
extern undefined1 JKRAramStream;

//[Data] Expected size is 0x000010
extern undefined1 JKRAramStream;

//[BSS] Expected size is 0x000004
extern undefined1 JKRAramStream;
//[BSS] Expected size is 0x000004
extern undefined1 JKRAramStream;
//[BSS] Expected size is 0x000004
extern undefined1 JKRAramStream;
//[BSS] Expected size is 0x000004
extern undefined1 JKRAramStream;

namespace JKRAramStream {
JKRAramStream * create(long param_1);
}
