#pragma once
#include <ctypes.h>

#include <JSUPtrList.h>

//Expected size is 0x00000c
extern struct JSUPtrList JUTGamePad;

//Expected size is 0x000030
extern struct PADStatus JUTGamePad[4];

//Expected size is 0x0000c0
extern struct CButton JUTGamePad[4];

//Expected size is 0x000040
extern struct CStick JUTGamePad[4];

//Expected size is 0x000040
extern struct CStick JUTGamePad[4];

//Expected size is 0x000001
extern undefined1 JUTGamePad;

//Expected size is 0x000004
extern byte JUTGamePad[4];

//Expected size is 0x000004
extern undefined1 JUTGamePad;

//Expected size is 0x000004
extern int JUTGamePad;

//Expected size is 0x000004
extern undefined1 JUTGamePad;


namespace JUTGamePad {
//Expected size is 0x000004
extern byte CRumble[4];

//Expected size is 0x000004
extern int CRumble;


namespace C3ButtonReset {
//Expected size is 0x000004
extern undefined1 sCallback;

//Expected size is 0x000004
extern undefined1 sCallbackArg;

//Expected size is 0x000008
extern undefined1 sThreshold;

//Expected size is 0x000001
extern undefined1 sResetSwitchPushing;

//Expected size is 0x000001
extern undefined1 sResetOccurred;

//Expected size is 0x000004
extern undefined1 sResetOccurredPort;

}
}

namespace JUTGamePad {
void init(void);
}

namespace JUTGamePad {

namespace CRumble {
void stopMotorHard(int index);
}
int getGamePad(int param_1);
}

namespace JUtility {
void __sinit_JUTGamePad_cpp(void);
}

namespace JUTGamePad {
}
