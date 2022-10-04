#include <dolphin/gx.h>
#include <dolphin/dvd.h>

#include "rst.h"
#include "dvd.h"

#include <JFramework/JUtility/JUTGamePad.h>
#include <JFramework/JUtility/JUTXfb.h>

#include "./mDoAud.h"

namespace mDoRst {
	int *mResetData;
}


namespace m_Do_Reset {

    void my_OSCancelAlarmAll() {
        // nop
    }

	void destroyVideo() {
		JUTVideo::destroyManager();
		gx::GXSetDrawDoneCallback(0);
		vi::VISetBlack(1);
		vi::VIFlush();
		vi::VIWaitForRetrace();
	}

	void mDoRst_reset(undefined4 param_1, undefined4 param_2, undefined4 param_3)

	{
		int iVar1;
		bool bVar5;
		os::OSThread *pOVar2;
		undefined4 uVar3;
		os::OSThread *pOVar4;

		iVar1 = dvd::DVDGetDriveStatus();
		if (iVar1 == -1) {
			do {
			} while (true);
		}
		JUTXfb::sManager->clearIndex();
		m_Do_DVDError::mDoDvdErr_ThdCleanup();
		bVar5 = JUTGamePad::clearForReset();
		mDoAud_zelAudio_c::mInitFlag = 0;
		vi::VIWaitForRetrace();
		vi::VIWaitForRetrace();
		pOVar2 = gx::GXGetCurrentGXThread();
		uVar3 = os::OSDisableInterrupts();
		pOVar4 = os::OSGetCurrentThread();
		if (pOVar2 != pOVar4) {
			os::OSCancelThread(pOVar2);
			gx::GXSetCurrentGXThread();
		}
		gx::GXFlush();
		gx::GXAbortFrame();
		gx::GXDrawDone();
		os::OSRestoreInterrupts(uVar3);
		destroyVideo();
		my_OSCancelAlarmAll();
		os::LCDisable();
		//os::OSSetSaveRegion(mDoRst::mResetData, 0x80017f00);
		os::OSResetSystem(param_1, param_2, param_3);
		do {
			vi::VIWaitForRetrace();
		} while (true);
	}

	void *mDoRst_resetCallBack(u32 param_1, u32 param_2) {
		int iVar1;
		int *piVar2;

		if (*mDoRst::mResetData == 0) {
			if (param_1 == -1) {
				piVar2 = mDoRst::mResetData;
				JUTGamePad::clearForReset();
				//JUTGamePad::CRumble::setEnabled((CRumble *)0xf0000000, (ulong)piVar2);
			} else {
				if (mDoRst::mResetData[2] != 0) {
					JUTGamePad::C3ButtonReset::sCallback = mDoRst_resetCallBack;
					JUTGamePad::C3ButtonReset::sCallbackArg = 0;
					JUTGamePad::C3ButtonReset::sResetOccurred = 0;
					return;
				}
				mDoRst::mResetData[2] = 1;
				piVar2 = mDoRst::mResetData;
				mDoRst::mResetData[3] = param_1;
				JUTGamePad::clearForReset();
				//JUTGamePad::CRumble::setEnabled((CRumble *)0xf0000000, (ulong)piVar2);
			}
			iVar1 = dvd::DVDCheckDisk();
			if (iVar1 == 0) {
				mDoRst_reset(1, 0x80000000, 0);
			}
			*mDoRst::mResetData = 1;
		}
	}
}