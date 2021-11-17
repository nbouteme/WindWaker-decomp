#pragma once
#include <ctypes.h>



namespace d_a_bomb {
//Expected size is 0x00000c
extern undefined4 fuse_offset$5399;

//Expected size is 0x000001
extern undefined1 init$4555;

//Expected size is 0x000001
extern undefined1 init$4644;

//Expected size is 0x000001
extern undefined1 init$5401;

}

namespace @unnamed@d_a_bomb_cpp@ {
bool chk_attrState(daBomb_c *param_1,AttrSt_e param_2);
}

namespace d_a_bomb {
void daBomb_Draw(daBomb_c *param_1);
}

namespace d_a_bomb {
void daBomb_Execute(daBomb_c *param_1);
}

namespace d_a_bomb {
undefined4 daBomb_IsDelete(void);
}

namespace d_a_bomb {
undefined4 daBomb_Delete(daBomb_c *param_1);
}

namespace d_a_bomb {
void daBomb_createHeap(daBomb_c *param_1);
}

namespace d_a_bomb {
void daBomb_Create(daBomb_c *param_1);
}
