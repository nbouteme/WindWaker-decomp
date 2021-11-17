#pragma once
#include <ctypes.h>



namespace JUTAssertion {
void create(void);
}

namespace JUTAssertion {
undefined4 getSDevice(void);
}

namespace JUTAssertion {
void showAssert(ulong param_1,char *param_2,int param_3,char *param_4);
}

namespace JUtility {
void setWarningMessage_f_va(uint param_1,undefined4 param_2,undefined4 param_3,char *param_4,__gnuc_va_list param_5);
}

namespace JUTAssertion {
void setWarningMessage_f(ulong param_1,char *param_2,int param_3,char *param_4,... param_5);
}

namespace JUtility {
void setLogMessage_f_va(uint param_1,undefined4 param_2,undefined4 param_3,char *param_4,__gnuc_va_list param_5);
}

namespace JUTAssertion {
void setVisible(bool param_1);
}
