#pragma once
#include <ctypes.h>


//[Data] Expected size is 0x00000c
extern pointer cBgW_RwgElm;

//[Data] Expected size is 0x00000c
extern pointer cBgW_NodeTree;

//[Data] Expected size is 0x00000c
extern pointer cBgW_GrpElm;

//[Data] Expected size is 0x00000c
extern pointer cBgW_TriElm;


namespace cBgW {
//[Data] Expected size is 0x000024
extern pointer __vt;

}
//[Data] Expected size is 0x00000c
extern pointer cBgW_BgId;


namespace SComponent {
void ASSERT_SOLDHEAP(void);
}
