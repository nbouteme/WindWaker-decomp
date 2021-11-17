#pragma once
#include <ctypes.h>



namespace m_Do_machine_exception {
//Expected size is 0x000004
extern undefined4 sConsole;

void print_f(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,undefined4 param_13,undefined4 param_14,undefined4 param_15,undefined4 param_16);
void print(char *param_1);
void dispHeapInfo(void);
void dispGameInfo(void);
void dispDateInfo(void);
void dispConsoleToTerminal(void);
void exception_addition(undefined4 param_1);
}
