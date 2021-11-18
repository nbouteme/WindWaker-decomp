#pragma once
#include <ctypes.h>

#include <mDoMemCd_Ctrl_c.h>


namespace m_Do_MemCard {
//[BSS] Expected size is 0x001000
extern undefined MemCardStack;
//[BSS] Expected size is 0x000318
extern undefined MemCardThread;
//[BSS] Expected size is 0x00a000
extern byte MemCardWorkArea0[8192];
//[BSS] Expected size is 0x001698
extern struct mDoMemCd_Ctrl_c g_mDoMemCd_control;
}

namespace m_Do_MemCard {
undefined4 mDoMemCd_main(void);
void __sinit_m_Do_MemCard_cpp(void);
}
