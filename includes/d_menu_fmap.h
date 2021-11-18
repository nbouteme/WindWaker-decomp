#pragma once
#include <ctypes.h>



namespace d_menu_fmap {
//[Data] Expected size is 0x000048
extern undefined rollmapTex;

//[Data] Expected size is 0x000048
extern undefined * salvItemex;

//[Data] Expected size is 0x00003c
extern undefined4 tag00$4288;

//[Data] Expected size is 0x000020
extern undefined4 tagkr$4304;

//[Data] Expected size is 0x00000c
extern undefined4 txtnm$4327;

//[Data] Expected size is 0x00002c
extern undefined4 islandPos$4618;

//[Data] Expected size is 0x000054
extern undefined4 fmapProcMain;

//[Data] Expected size is 0x000018
extern undefined4 mainProc;

//[Data] Expected size is 0x000024
extern undefined4 HikakuProcMain;

//[Data] Expected size is 0x00003c
extern undefined4 warpProcMain;

//[Data] Expected size is 0x000060
extern undefined4 FishManProcMain;

}
//[Data] Expected size is 0x000010
extern undefined1 dDlst_FMAP_c;

//[Data] Expected size is 0x00000c
extern undefined1 dMf_HIO_c;


namespace d_menu_fmap {
//[Data] Expected size is 0x000008
extern pointer korogStat;

//[BSS] Expected size is 0x000120
extern undefined g_mfHIO;
}

namespace d_menu_fmap {
void __sinit_d_menu_fmap_cpp(void);
}
