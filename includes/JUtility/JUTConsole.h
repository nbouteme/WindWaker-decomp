#pragma once
#include <ctypes.h>


//Expected size is 0x000004
extern struct JUTConsoleManager * JUTConsoleManager;


namespace JUtility {
//Expected size is 0x000004
extern undefined4 sReportConsole;

//Expected size is 0x000004
extern undefined4 sWarningConsole;

}

namespace JUTConsole {
JUTConsole * create(uint param_1,uint param_2,JKRHeap *param_3);
JUTConsole * create(uint param_1,void *buffer,ulong param_3);
}

namespace JUtility {
void JUTConsole_print_f_va_(JUTConsole *param_1,char *param_2,__gnuc_va_list param_3);
}

namespace JUTConsoleManager {
JUTConsoleManager * createManager(JKRHeap *param_1);
}

namespace JUtility {
void JUTSetReportConsole(undefined4 param_1);
undefined4 JUTGetReportConsole(void);
void JUTSetWarningConsole(undefined4 param_1);
undefined4 JUTGetWarningConsole(void);
void JUTReportConsole_f_va(char *param_1,__gnuc_va_list param_2);
void JUTReportConsole_f(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,undefined4 param_13,undefined4 param_14,undefined4 param_15,undefined4 param_16);
void JUTReportConsole(undefined4 param_1);
void JUTWarningConsole_f_va(char *param_1,__gnuc_va_list param_2);
void JUTWarningConsole_f(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,undefined4 param_13,undefined4 param_14,undefined4 param_15,undefined4 param_16);
void JUTWarningConsole(undefined4 param_1);
}
