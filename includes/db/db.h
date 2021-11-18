#pragma once
#include <ctypes.h>



namespace db {
//[BSS] Expected size is 0x000004
extern undefined4 __DBInterface;
//[BSS] Expected size is 0x000004
extern undefined4 DBVerbose;
void DBInit(void);
void __DBExceptionDestinationAux(void);
void __DBExceptionDestination(void);
uint __DBIsExceptionMarked(uint param_1);
void DBPrintf(void);
}
