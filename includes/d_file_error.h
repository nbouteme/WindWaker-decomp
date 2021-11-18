#pragma once
#include <ctypes.h>



namespace d_file_error {
//[Data] Expected size is 0x00003c
extern undefined4 FileErrProc;

//[Data] Expected size is 0x00000c
extern undefined xp1$4320;

//[Data] Expected size is 0x00000c
extern undefined rt1$4321;

//[Data] Expected size is 0x00000c
extern undefined xp2$4322;

//[Data] Expected size is 0x00000c
extern undefined rt2$4323;

}
//[Data] Expected size is 0x000010
extern undefined1 dDlst_FileErr_c;

//[Data] Expected size is 0x00003c
extern undefined1 MyScreen;

//[Data] Expected size is 0x00000c
extern undefined1 dFe_HIO_c;


namespace d_file_error {
//[Data] Expected size is 0x000008
extern undefined curxp;

//[Data] Expected size is 0x000006
extern undefined txt$4112;

//[BSS] Expected size is 0x00001c
extern undefined g_feHIO;
}

namespace d_file_error {
void __sinit_d_file_error_cpp(void);
}
