#include <d_a_leaflift_static.h>
#include <SComponent/c_lib.h>
#include <d_com_inf_game.h>
#include <JAZelAudio/JAIZelBasic.h>
#include <d_particle.h>
#include <daLlift_c.h>


/* __thiscall daLlift_c::checkEndDownLift(void) */

uint __thiscall daLlift_c::checkEndDownLift(daLlift_c *this)

{
  return ((uint)(byte)((*(float *)(this + 0x1fc) <= *(float *)(this + 0x1d4)) << 1) << 0x1c) >> 0x1d
  ;
}


/* WARNING: Inlined function: FUN_80328f40 */
/* WARNING: Inlined function: FUN_80328f8c */
/* __thiscall daLlift_c::MoveUpLift(void) */

undefined4 __thiscall daLlift_c::MoveUpLift(daLlift_c *this)

{
  sbyte sVar3;
  JPABaseEmitter *pJVar1;
  int iVar2;
  undefined4 uVar4;
  double dVar5;
  cXyz local_28 [2];
  
  uVar4 = 0;
  *(int *)(this + 0x49c) = *(int *)(this + 0x49c) + 1;
  if (*(float *)(this + 0x1fc) != d_a_leaflift_static::_4026 + *(float *)(this + 0x1d4)) {
    this[0x43d] = (daLlift_c)0x1;
  }
  dVar5 = SComponent::cLib_addCalc
                    ((float *)(this + 0x1fc),d_a_leaflift_static::_4026 + *(float *)(this + 0x1d4),
                     d_a_leaflift_static::_4027,d_a_leaflift_static::_4028,
                     d_a_leaflift_static::_4029);
  if ((double)d_a_leaflift_static::_4030 != dVar5) {
    if (((double)d_a_leaflift_static::_4030 != dVar5) && (this[0x469] == (daLlift_c)0x0)) {
      sVar3 = d_com_inf_game::dComIfGp_getReverb((int)(char)this[0x20a]);
      JAIZelBasic::seStart
                (JAIZelBasic::zel_basic,0x697f,(cXyz *)(this + 0x260),0,sVar3,
                 d_a_leaflift_static::_4031,d_a_leaflift_static::_4031,d_a_leaflift_static::_4032,
                 d_a_leaflift_static::_4032,0);
      this[0x469] = (daLlift_c)0x1;
      pJVar1 = dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0x82ac,
                                  (cXyz *)(this + 0x1f8),(csXyz *)(this + 0x204),(cXyz *)0x0,0xff,
                                  (dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,(_GXColor *)0x0,
                                  (cXyz *)0x0);
      *(JPABaseEmitter **)(this + 0x4a0) = pJVar1;
      *(undefined4 *)(this + 0x4a4) = 0;
      local_28[0].x = *(float *)(this + 0x1f8);
      local_28[0].z = *(float *)(this + 0x200);
      local_28[0].y = *(float *)(this + 0x4b0);
      pJVar1 = dPa_control_c::set(d_com_inf_game::g_dComIfG_gameInfo.mPlay.mParticleCtrl,0,0x82ab,
                                  local_28,(csXyz *)(this + 0x204),(cXyz *)0x0,0xff,
                                  (dPa_levelEcallBack *)0x0,-1,(_GXColor *)0x0,(_GXColor *)0x0,
                                  (cXyz *)0x0);
      *(JPABaseEmitter **)(this + 0x4ac) = pJVar1;
      *(undefined4 *)(this + 0x49c) = 0;
      iVar2 = *(int *)(this + 0x4a8);
      if (iVar2 != 0) {
        *(uint *)(iVar2 + 0x20c) = *(uint *)(iVar2 + 0x20c) | 1;
      }
    }
  }
  else {
    this[0x469] = (daLlift_c)0x0;
    uVar4 = 1;
  }
  return uVar4;
}

