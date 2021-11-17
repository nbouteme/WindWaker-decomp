#pragma once
#include <ctypes.h>



namespace d_a_arrow {
//Expected size is 0x00000c
extern undefined4 offset_arrow_pos$5149;

}
//Expected size is 0x000002
extern undefined1 daArrow_c;


namespace d_a_arrow {
//Expected size is 0x000001
extern undefined1 init$5151;

void createHeap_CB(daArrow_c *param_1);
}

namespace d_a_arrow {
void atHit_CB(daArrow_c *param_1,dCcD_GObjInf *param_2,fopAc_ac_c *param_3,dCcD_GObjInf *param_4);
}

namespace d_a_arrow {
void daArrowCreate(daArrow_c *param_1);
void daArrowDelete(daArrow_c *param_1);
void daArrowExecute(daArrow_c *param_1);
void daArrowDraw(daArrow_c *param_1);
undefined4 daArrowIsDelete(void);
}

namespace d_a_arrow {
int cLib_calcTimer(short *param_1);
}
