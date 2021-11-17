#pragma once
#include <ctypes.h>



namespace d_attention {
undefined4 check_event_condition(int locType,dEvt__ActorCondition behaviorFlags);
undefined4 check_flontofplayer(uint bits,short angle1,short angle2);
double distace_weight(double distance,short angle,double distanceAngleWeight);
double distace_angle_adjust(double distance,short angle,double distanceAnglePct);
int check_distace(cXyz *pPlayerPos,short angle1,cXyz *pActorPos,double maxDistXZBase,double maxDistAngleMul,double maxDeltaY,double minDeltaY);
}

namespace d_attention {
void select_attention(fopAc_ac_c *param_1,dAttention_c *param_2);
}

namespace d_attention {
undefined4 sound_attention(fopAc_ac_c *pActor,dAttention_c *pAttention);
}
