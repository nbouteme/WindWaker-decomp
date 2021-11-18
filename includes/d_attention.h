#pragma once
#include <ctypes.h>


//[Data] Expected size is 0x00000c
extern struct dAttention__TypeTableEntry dAttention_c[3];

//[Data] Expected size is 0x000014
extern struct dAttention__TypeTableEntry dAttention_c[5];


namespace d_attention {
//[Data] Expected size is 0x00000a
extern ushort l_bpkIdx$4021[5];

//[Data] Expected size is 0x000024
extern uint ftp_table$4271[9];

//[Data] Expected size is 0x00000c
extern short ang_table2$4273[6];

}
//[Data] Expected size is 0x000010
extern undefined1 dAttDraw_CallBack_c;

//[Data] Expected size is 0x00000c
extern undefined1 dAttParam_c;

//[Data] Expected size is 0x000004
extern int dAttention_c;

//[Data] Expected size is 0x000004
extern int dAttention_c;


namespace d_attention {
//[Data] Expected size is 0x000006
extern short ang_table$4272[3];

}

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
