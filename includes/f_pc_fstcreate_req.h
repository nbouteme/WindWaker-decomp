#pragma once
#include <ctypes.h>



namespace f_pc_fstcreate_req {
//[Data] Expected size is 0x00000c
extern pointer submethod$2176;

undefined4 fpcFCtRq_Do(fast_create_request *param_1);
undefined4 fpcFCtRq_Delete(void);
void * fpcFCtRq_Request(layer_class *param_1,short param_2,undefined *param_3,void *param_4,void *param_5);
}
