#pragma once

#include <JFramework/JUtility/JUTGamePad.h>
#include <common/dDlst.h>
#include <dolphin/gx.h>
#include <doltypes.h>

#include <common/dComIfG_inf_c.h>
#include "machine.h"

namespace mDoGph_gInf_c {
	extern gx::GXColor mBackColor;
	extern gx::GXColor mFadeColor;

}

namespace m_Do_graphic {
	int mDoGph_Create();
	void mDoGph_BlankingON();
	void mDoGph_BlankingOFF();
	void mDoGph_Painter();
	void dScnPly_BeforeOfPaint(void);
	undefined4 mDoGph_BeforeOfDraw(void);
	undefined4 mDoGph_AfterOfDraw(void);
}
