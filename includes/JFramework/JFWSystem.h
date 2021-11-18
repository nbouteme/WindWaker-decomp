#pragma once
#include <ctypes.h>



namespace JFWSystem {

namespace CSetUpParam {
//[Data] Expected size is 0x000004
extern int maxStdHeaps;

//[Data] Expected size is 0x000004
extern int sysHeapSize;

//[Data] Expected size is 0x000004
extern int fifoBufSize;

//[Data] Expected size is 0x000004
extern int aramAudioBufSize;

//[Data] Expected size is 0x000004
extern int aramGraphBufSize;

//[Data] Expected size is 0x000004
extern int streamPriority;

//[Data] Expected size is 0x000004
extern int decompPriority;

//[Data] Expected size is 0x000004
extern int aPiecePriority;

//[Data] Expected size is 0x000004
extern pointer systemFontRes;

//[Data] Expected size is 0x000004
extern pointer renderMode;

//[Data] Expected size is 0x000004
extern int exConsoleBufferSize;

}
}
//[BSS] Expected size is 0x000004
extern struct JKRHeap * JFWSystem;
//[BSS] Expected size is 0x000004
extern struct JKRHeap * JFWSystem;
//[BSS] Expected size is 0x000004
extern undefined1 JFWSystem;
//[BSS] Expected size is 0x000004
extern struct JUTDbPrint * JFWSystem;
//[BSS] Expected size is 0x000004
extern struct JUTResFont * JFWSystem;
//[BSS] Expected size is 0x000004
extern undefined1 JFWSystem;
//[BSS] Expected size is 0x000004
extern struct JUTConsole * JFWSystem;
//[BSS] Expected size is 0x000001
extern byte JFWSystem;
