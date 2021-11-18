#pragma once
#include <ctypes.h>


//[Data] Expected size is 0x00002c
extern undefined1 J3DLockedMaterial;

//[Data] Expected size is 0x00002c
extern undefined1 J3DPatchedMaterial;


namespace J3DMaterial {
//[Data] Expected size is 0x00002c
extern pointer __vt;

}
//[Data] Expected size is 0x000078
extern undefined1 J3DPEBlock;

//[Data] Expected size is 0x00004c
extern undefined1 J3DIndBlockNull;

//[Data] Expected size is 0x00004c
extern undefined1 J3DIndBlock;

//[Data] Expected size is 0x000060
extern undefined1 J3DTexGenBlock;

//[Data] Expected size is 0x000088
extern pointer J3DColorBlock;


namespace J3DMaterial {
J3DColorBlockLightOn * createColorBlock(ulong param_1);
}

namespace J3DMaterial {
J3DPEBlockFull * createPEBlock(ulong param_1,ulong param_2);
}
