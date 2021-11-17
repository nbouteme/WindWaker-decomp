#pragma once
#include <ctypes.h>

#include <mDoDvdThd_param_c.h>

//Expected size is 0x000318
extern undefined1 mDoDvdThd;

//Expected size is 0x001000
extern undefined1 mDoDvdThd;

//Expected size is 0x000048
extern struct mDoDvdThd_param_c mDoDvdThd;

//Expected size is 0x000001
extern undefined1 mDoDvdThd;

//Expected size is 0x000001
extern undefined1 mDoDvdThd;


namespace mDoDvdThd {
void create(long param_1);
}

namespace m_Do_dvd_thread {
int my_DVDConvertPathToEntrynum(char *pFilePath);
}

namespace m_Do_dvd_thread {
undefined4 cb(int *param_1);
}

namespace mDoDvdThd_callback_c {
mDoDvdThd_command_c * create(FuncDef501 *param_1,void *param_2);
}

namespace mDoDvdThd_mountArchive_c {
mDoDvdThd_command_c * create(char *param_1,uchar param_2,JKRHeap *param_3);
}

namespace mDoDvdThd_mountXArchive_c {
mDoDvdThd_mountXArchive_c *create(char *param_1,byte param_2,EMountMode param_3);
}

namespace mDoDvdThd_toMainRam_c {
mDoDvdThd_toMainRam_c * create(char *pFilePath,byte direction,JKRHeap *pHeap);
}

namespace m_Do_dvd_thread {
void __sinit_m_Do_dvd_thread_cpp(void);
}
