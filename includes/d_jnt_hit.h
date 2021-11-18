#pragma once
#include <ctypes.h>


//[Data] Expected size is 0x00000c
extern pointer JntHit_HIO_c;


namespace d_jnt_hit {
JntHit_c * JntHit_create(J3DModel *param_1,__jnt_hit_data_c *param_2,short param_3);
}
