#pragma once
#include <ctypes.h>



namespace daObjTribox {

namespace Act_c {
//Expected size is 0x00000c
extern undefined1 M_sound_pos;

//Expected size is 0x000004
extern undefined1 M_correct_cnt;

//Expected size is 0x000001
extern undefined1 M_correct_flag;

//Expected size is 0x000004
extern undefined1 M_b_cont_cnt;

//Expected size is 0x000004
extern undefined1 M_c_cont_cnt;

//Expected size is 0x000001
extern undefined1 M_sink_start;

}
}

namespace d_a_obj_tribox_static {
void __sinit_d_a_obj_tribox_static_cpp(void);
}
