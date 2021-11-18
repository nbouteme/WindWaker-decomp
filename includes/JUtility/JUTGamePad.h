#pragma once
#include <ctypes.h>

#include <JSUPtrList.h>


namespace JUtility {
//[Data] Expected size is 0x000010
extern int channel_mask[4];

}
//[Data] Expected size is 0x00000c
extern undefined1 JUTGamePad;

//[Data] Expected size is 0x000004
extern int JUTGamePad;


namespace JUTGamePad {

namespace C3ButtonReset {
//[Data] Expected size is 0x000004
extern undefined1 sResetPattern;

//[Data] Expected size is 0x000004
extern undefined1 sResetMaskPattern;

}
}
//[BSS] Expected size is 0x00000c
extern struct JSUPtrList JUTGamePad;
//[BSS] Expected size is 0x000030
extern struct PADStatus JUTGamePad[4];
//[BSS] Expected size is 0x0000c0
extern struct CButton JUTGamePad[4];
//[BSS] Expected size is 0x000040
extern struct CStick JUTGamePad[4];
//[BSS] Expected size is 0x000040
extern struct CStick JUTGamePad[4];
//[BSS] Expected size is 0x000001
extern undefined1 JUTGamePad;
//[BSS] Expected size is 0x000004
extern byte JUTGamePad[4];
//[BSS] Expected size is 0x000004
extern undefined1 JUTGamePad;
//[BSS] Expected size is 0x000004
extern int JUTGamePad;
//[BSS] Expected size is 0x000004
extern undefined1 JUTGamePad;

namespace JUTGamePad {
//[BSS] Expected size is 0x000004
extern byte CRumble[4];
//[BSS] Expected size is 0x000004
extern int CRumble;

namespace C3ButtonReset {
//[BSS] Expected size is 0x000004
extern undefined1 sCallback;
//[BSS] Expected size is 0x000004
extern undefined1 sCallbackArg;
//[BSS] Expected size is 0x000008
extern undefined1 sThreshold;
//[BSS] Expected size is 0x000001
extern undefined1 sResetSwitchPushing;
//[BSS] Expected size is 0x000001
extern undefined1 sResetOccurred;
//[BSS] Expected size is 0x000004
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
