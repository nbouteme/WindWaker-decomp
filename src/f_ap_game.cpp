#include <f_ap_game.h>
#include <f_op_scene_mng.h>
#include <f_op_overlap_mng.h>
#include <f_op_camera_mng.h>
#include <f_ap_game.h>
#include <f_pc_manager.h>
#include <SComponent/c_counter.h>
#include <f_op_draw_tag.h>
#include <m_Do_hostIO.h>
#include <JKernel/JKRHeap.h>
#include <Runtime.PPCEABI.H/global_destructor_chain.h>
#include <fapGm_HIO_c.h>


namespace f_ap_game {
struct fapGm_HIO_c g_HIO;
}

/* __thiscall fapGm_HIO_c::fapGm_HIO_c(void) */

void __thiscall fapGm_HIO_c::fapGm_HIO_c(fapGm_HIO_c *this)

{
  this->field_0x0 = &__vt;
  *(undefined4 *)&this->field_0x20 = 0xffffffff;
  *(undefined4 *)&this->field_0x3c = 0xffffffff;
  *(undefined4 *)&this->field_0x40 = 0xffffffff;
  *(undefined4 *)&this->field_0x44 = 0xffffffff;
  *(undefined4 *)&this->field_0x48 = 0xffffffff;
  *(undefined *)&this->field_0x5 = 1;
  if (mDoMain::developmentMode == '\0') {
    this->deven = 0;
    this->deven2 = 0;
  }
  else {
    this->deven = 1;
    this->deven2 = 1;
  }
  *(undefined *)&this->field_0x9 = 1;
  *(undefined *)&this->field_0xa = 1;
  this->aspectRatio = f_ap_game::_4052;
  *(undefined *)&this->field_0x10 = 0;
  *(undefined *)&this->field_0x11 = 0;
  *(undefined *)&this->field_0x12 = 8;
  *(undefined *)&this->field_0x13 = 8;
  *(undefined *)&this->field_0x14 = 10;
  *(undefined *)&this->field_0x15 = 0xc;
  *(undefined *)&this->field_0x16 = 10;
  *(undefined *)&this->field_0x17 = 8;
  *(undefined *)&this->field_0x18 = 8;
  *(undefined *)&this->field_0x19 = 0xff;
  *(undefined *)&this->field_0x1a = 0;
  *(undefined *)&this->field_0x1b = 1;
  *(undefined *)&this->field_0x1c = 0;
  this->field_0x2c = 0x280;
  this->field_0x2e = 0x1e0;
  *(undefined *)&this->field_0x30 = 0;
  *(undefined *)&this->field_0x20 = 0xff;
  *(undefined *)&this->field_0x21 = 0xff;
  *(undefined *)&this->field_0x22 = 0xff;
  *(undefined *)&this->field_0x23 = 0xff;
  this->mTriggerThreshLo = f_ap_game::_4053;
  this->mTriggerThreshHi = f_ap_game::_4054;
  *(undefined *)&this->field_0x3c = 0xff;
  *(undefined *)&this->field_0x3d = 0x96;
  *(undefined *)&this->field_0x3e = 0;
  *(undefined *)&this->field_0x3f = 0xff;
  *(undefined *)&this->field_0x40 = 0xff;
  *(undefined *)&this->field_0x41 = 0x78;
  *(undefined *)&this->field_0x42 = 0;
  *(undefined *)&this->field_0x43 = 0xff;
  *(undefined *)&this->field_0x44 = 0;
  *(undefined *)&this->field_0x45 = 0;
  *(undefined *)&this->field_0x46 = 0;
  *(undefined *)&this->field_0x47 = 0xff;
  *(undefined *)&this->field_0x48 = 0;
  *(undefined *)&this->field_0x49 = 0;
  *(undefined *)&this->field_0x4a = 0;
  *(undefined *)&this->field_0x4b = 0xff;
  this->field_0x4c = 0;
  this->field_0x4e = 10;
  this->field_0x54 = 0x1b;
  this->field_0x50 = 0;
  this->field_0x52 = 0;
  *(undefined *)&this->field_0x56 = 0x82;
  return;
}


namespace f_ap_game {

/* __stdcall fapGm_After(void) */

void fapGm_After(void)

{
  f_op_scene_mng::fopScnM_Management();
  f_op_overlap_mng::fopOvlpM_Management();
  f_op_camera_mng::fopCamM_Management();
  return;
}


/* __stdcall fapGm_Execute(void) */

void fapGm_Execute(void)

{
  f_pc_manager::fpcM_Management(0,fapGm_After);
  SComponent::cCt_Counter(0);
  return;
}


/* __stdcall fapGm_Create(void) */

void fapGm_Create(void)

{
  f_pc_manager::fpcM_Init();
  f_op_scene_mng::fopScnM_Init();
  f_op_overlap_mng::fopOvlpM_Init();
  f_op_camera_mng::fopCamM_Init();
  f_op_draw_tag::fopDwTg_CreateQueue();
  f_op_scene_mng::fopScnM_CreateReq(5,0x7fff,0,0);
  g_HIO._4_1_ = mDoHIO_subRoot_c::createChild
                          (&mDoHIO_subRoot_c_803a5778,"ゲームシステム",
                           (JORReflexible *)&g_HIO);
  return;
}

}

/* __thiscall fapGm_HIO_c::~fapGm_HIO_c(void) */

void __thiscall fapGm_HIO_c::_fapGm_HIO_c(fapGm_HIO_c *this)

{
  short in_r4;
  
  if ((this != (fapGm_HIO_c *)0x0) && (this->field_0x0 = &__vt, 0 < in_r4)) {
    JKernel::operator_delete((JKRHeap *)this);
  }
  return;
}


namespace f_ap_game {

void __sinit_f_ap_game_cpp(void)

{
  ::fapGm_HIO_c::fapGm_HIO_c(&g_HIO);
  Runtime.PPCEABI.H::__register_global_object();
  return;
}

