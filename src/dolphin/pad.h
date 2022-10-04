#pragma once

#include <doltypes.h>

namespace pad {

// CAUTION: Define PAD_USESPEC as long as bread boards or prototype
//          controllers (including DS4) are in use.
#ifndef EMU
#define PAD_USESPEC
#endif	// EMU

#ifdef __MWERKS__
#pragma warn_padding off
#endif

	typedef struct PADStatus {
		u16 button;		  // Or-ed PAD_BUTTON_* bits
		s8 stickX;		  // -128 <= stickX       <= 127
		s8 stickY;		  // -128 <= stickY       <= 127
		s8 substickX;	  // -128 <= substickX    <= 127
		s8 substickY;	  // -128 <= substickY    <= 127
		u8 triggerLeft;	  //    0 <= triggerLeft  <= 255
		u8 triggerRight;  //    0 <= triggerRight <= 255
		u8 analogA;		  //    0 <= analogA      <= 255
		u8 analogB;		  //    0 <= analogB      <= 255
		s8 err;			  // one of PAD_ERR_* number
	} PADStatus;

#ifdef __MWERKS__
#pragma warn_padding reset
#endif

#define PAD_MAX_CONTROLLERS 4

#define PAD_BUTTON_LEFT 0x0001
#define PAD_BUTTON_RIGHT 0x0002
#define PAD_BUTTON_DOWN 0x0004
#define PAD_BUTTON_UP 0x0008
#define PAD_TRIGGER_Z 0x0010
#define PAD_TRIGGER_R 0x0020
#define PAD_TRIGGER_L 0x0040
#define PAD_BUTTON_A 0x0100
#define PAD_BUTTON_B 0x0200
#define PAD_BUTTON_X 0x0400
#define PAD_BUTTON_Y 0x0800
#define PAD_BUTTON_MENU 0x1000
#define PAD_BUTTON_START 0x1000

#define PAD_CHAN0 0
#define PAD_CHAN1 1
#define PAD_CHAN2 2
#define PAD_CHAN3 3

#define PAD_CHAN0_BIT 0x80000000
#define PAD_CHAN1_BIT 0x40000000
#define PAD_CHAN2_BIT 0x20000000
#define PAD_CHAN3_BIT 0x10000000

#define PAD_ERR_NONE 0
#define PAD_ERR_NO_CONTROLLER -1
#define PAD_ERR_NOT_READY -2
#define PAD_ERR_TRANSFER -3

#define PAD_MOTOR_STOP 0
#define PAD_MOTOR_RUMBLE 1
#define PAD_MOTOR_STOP_HARD 2

#ifdef PAD_USESPEC
#define PAD_SPEC_0 0  // bread board    (ver 0.x)
#define PAD_SPEC_1 1  // 1st prototypes (ver 1.0)
#define PAD_SPEC_2 2  // 2nd prototypes (ver 3.0 FPGA)
#define PAD_SPEC_3 3  // DS3
#define PAD_SPEC_4 4  // DS4
#define PAD_SPEC_5 5  // DS5 (production version)
#endif				  // PAD_USESPEC

// PADSetAnalogMode() param
#define PAD_MODE_0 0
#define PAD_MODE_1 1
#define PAD_MODE_2 2
#define PAD_MODE_3 3
#define PAD_MODE_4 4
#define PAD_MODE_5 5
#define PAD_MODE_6 6
#define PAD_MODE_7 7

#define PADButtonDown(buttonLast, button) \
	((u16)(((buttonLast) ^ (button)) & (button)))

#define PADButtonUp(buttonLast, button) \
	((u16)(((buttonLast) ^ (button)) & (buttonLast)))

#define PADStartMotor(chan) PADControlMotor((chan), PAD_MOTOR_RUMBLE)
#define PADStopMotorHard(chan) PADControlMotor((chan), PAD_MOTOR_STOP_HARD)
#define PADStopMotor(chan) PADControlMotor((chan), PAD_MOTOR_STOP)

	BOOL PADInit(void);
	BOOL PADReset(u32 mask);
	u32 PADRead(PADStatus* status);
	void PADSetSamplingRate(u32 msec);
	void PADClamp(PADStatus* status);
	void PADClampCircle(PADStatus* status);
	void PADControlAllMotors(const u32* command);
	void PADControlMotor(int chan, u32 command);
	BOOL PADRecalibrate(u32 mask);
	BOOL PADSync(void);
	void PADSetAnalogMode(u32 mode);
	BOOL PADIsBarrel(s32 chan);

	typedef void (*PADSamplingCallback)(void);

	PADSamplingCallback PADSetSamplingCallback(PADSamplingCallback callback);

	// obsolete. Use SIProbe() instead.
	BOOL PADGetType(s32 chan, u32* type);

#ifdef PAD_USESPEC
	void PADSetSpec(u32 model);
	u32 PADGetSpec(void);
#endif	// PAD_USESPEC

#ifdef _DEBUG
	void __PADTestSamplingRate(u32 tvmode);
#endif	// _DEBUG

#ifdef MACOS
	void PADConfigure(void);
#endif	// MACOS

	//
	// System internal use only (do not use/touch)
	//

	BOOL __PADDisableRecalibration(BOOL disable);
	BOOL __PADDisableRumble(BOOL disable);
	void __PADDisableXPatch(void);

	extern u32 __PADFixBits;

	//
	//
	//

}  // namespace pad
