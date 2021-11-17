#include <d_a_obj_tribox_static.h>
#include <m_Do_mtx.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <Demangler/daTsubo/Act_c.h>


namespace daObjTribox {

namespace Act_c {
undefined1 M_sound_pos;
undefined1 M_correct_cnt;
undefined1 M_correct_flag;
undefined1 M_b_cont_cnt;
undefined1 M_c_cont_cnt;
undefined1 M_sink_start;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* __thiscall Act_c::reset(void) */

void __thiscall Act_c::reset(Act_c *this)

{
  _M_sound_pos = ::cXyz::Zero.x;
  DAT_803e1f40 = ::cXyz::Zero.y;
  DAT_803e1f44 = ::cXyz::Zero.z;
  _M_correct_cnt = 0;
  M_correct_flag = 0;
  _M_b_cont_cnt = 0;
  _M_c_cont_cnt = 0;
  M_sink_start = 0;
  return;
}

}

namespace d_a_obj_tribox_static {

void __sinit_d_a_obj_tribox_static_cpp(void)

{
  Runtime.PPCEABI.H::__register_global_object(&daObjTribox::Act_c::M_sound_pos,::cXyz::_cXyz,&_3981)
  ;
  return;
}

