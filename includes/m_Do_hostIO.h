#pragma once
#include <ctypes.h>


//[Data] Expected size is 0x00000c
extern pointer mDoHIO_subRoot_c;

//[Data] Expected size is 0x00000c
extern pointer mDoHIO_root_c;


namespace m_Do_hostIO {
//[BSS] Expected size is 0x000808
extern undefined4 mDoHIO_root;
}

namespace m_Do_hostIO {
void __sinit_m_Do_hostIO_cpp(void);
}
