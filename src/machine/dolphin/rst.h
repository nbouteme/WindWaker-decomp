#pragma once

#include <doltypes.h>

namespace mDoRst {
	extern int *mResetData;
}

namespace m_Do_Reset {
	void my_OSCancelAlarmAll();
	void destroyVideo();
	void mDoRst_reset(undefined4 param_1, undefined4 param_2, undefined4 param_3);
	void *mDoRst_resetCallBack(u32 param_1, u32 param_2);
}