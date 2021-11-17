#pragma once
#include <ctypes.h>



namespace JFramework {
//Expected size is 0x000020
extern undefined clear_z_tobj;

}
//Expected size is 0x000004
extern struct JFWDisplay * JFWDisplay;


namespace JFramework {
//Expected size is 0x000004
extern undefined4 prevFrame$2524;

//Expected size is 0x000001
extern undefined1 init$2525;

//Expected size is 0x000008
extern undefined4 nextTick$2569;

//Expected size is 0x000001
extern undefined1 init$2570;

//Expected size is 0x000004
extern undefined4 nextCount$2577;

//Expected size is 0x000001
extern undefined1 init$2578;

}

namespace JFramework {
void callDirectDraw(void);
}

namespace JFramework {
void waitForTick(uint param_1,uint param_2);
void JFWThreadAlarmHandler(int param_1);
}

namespace JFramework {
void JFWGXDrawDoneAutoAbort(void);
void JFWGXAbortAlarmHandler(void);
void diagnoseGpHang(void);
}
