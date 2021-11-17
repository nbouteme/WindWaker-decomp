#pragma once
#include <ctypes.h>



namespace f_op_msg {
//Expected size is 0x000004
extern int fopMsg_MSG_TYPE;

void fopMsg_Draw(msg_class *param_1);
void fopMsg_Execute(msg_class *this);
int fopMsg_IsDelete(msg_class *param_1);
int fopMsg_Delete(msg_class *param_1);
int fopMsg_Create(msg_class *this);
}
