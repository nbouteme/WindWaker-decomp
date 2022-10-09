#include "./graphic.h"

#include <JFramework/J2D/J2DPrint.h>
#include <JFramework/JFWDisplay.h>
#include <JFramework/JFWSystem.h>
#include <JFramework/JKernel/JKRHeap.h>
#include <JFramework/JUtility/JUTFader.h>
#include <JFramework/JUtility/JUTVideo.h>
#include <f_ap/game.h>

#include <cstring>

#include "./ext.h"
#include "dComIfG_inf_c.h"

struct JUTFader;

namespace mDoGph_gInf_c {
	JUTFader *mFader;

	ResTIMG *mFrameBufferTimg, *mFrameBufferTex;
	void *mZbufferTex;

	int mBlureFlag;
	int mFade;
	gx::GXColor mBackColor;
	gx::GXColor mFadeColor;

	static JKRSolidHeap *mHeap[2];
	static byte mCurrentHeap;

	static void createHeap() {
		JKRHeap *pParent;
		ulong uVar1;

		pParent = JKRHeap::sCurrentHeap;
		mDoGph_gInf_c::mHeap[0] = JKRSolidHeap::create(0x10000, JKRHeap::sCurrentHeap, false);
		if (mDoGph_gInf_c::mHeap[0] == (JKRSolidHeap *)0x0) {
			JUTAssertion::getSDevice()->showAssert("m_Do_graphic.cpp", 0x1eb, "mHeap[0] != 0");
			m_Do_printf::OSPanic("m_Do_graphic.cpp", 0x1eb, "Halt");
		}
		mDoGph_gInf_c::mHeap[1] = JKRSolidHeap::create(0x10000, pParent, false);
		if (mDoGph_gInf_c::mHeap[1] == (JKRSolidHeap *)0x0) {
			JUTAssertion::getSDevice()->showAssert("m_Do_graphic.cpp", 0x1ed, "mHeap[1] != 0");
			m_Do_printf::OSPanic("m_Do_graphic.cpp", 0x1ed, "Halt");
		}
		mDoGph_gInf_c::mCurrentHeap = 0;
	}

	void create(void) {
		JUTFader *fader;
		ulong uVar1;
		int iVar2;
		undefined4 local_14[4];
		JUTDbPrint *printer;

		JFWDisplay::createManager(JKRHeap::sCurrentHeap, 2, true);
		JFWDisplay::sManager->shoulddraw = 1;
		local_14[0] = 0;
		fader = new JUTFader(0, 0, JUTVideo::sManager->mpRenderMode->fbWidth, JUTVideo::sManager->mpRenderMode->efbHeight, (TColor)local_14);
		if (fader == (JUTFader *)0x0) {
			JUTAssertion::getSDevice()->showAssert("m_Do_graphic.cpp", 0x1a0, "faderPtr != 0");
			m_Do_printf::OSPanic("m_Do_graphic.cpp", 0x1a0, "Halt");
		}
		JFWDisplay::sManager->mpFader = fader;
		mDoGph_gInf_c::mFader = fader;
		JFWDisplay::sManager->mpFader = fader;
		JUTProcBar::sManager->mbDrawHeapBar = 0;
		JUTProcBar::sManager->mbDrawProcessBar = 0;
		printer = JUTDbPrint::sDebugPrint;
		JUTDbPrint::sDebugPrint->uk = 0;
		mDoGph_gInf_c::createHeap();
		iVar2 = gx::GXGetTexBufferSize(0x140, 0xf0, 6, 0, 0);
		mDoGph_gInf_c::mFrameBufferTimg = (ResTIMG *)JKRHeap::alloc(iVar2 + sizeof(ResTIMG), 0x20, (JKRHeap *)0x0);
		mDoGph_gInf_c::mFrameBufferTex = mDoGph_gInf_c::mFrameBufferTimg + 1;
		//SComponent::cLib_memSet(mDoGph_gInf_c::mFrameBufferTimg, 0, iVar2 + 0x20U);
		memset(mDoGph_gInf_c::mFrameBufferTimg, 0, iVar2 + 0x20U);
		mDoGph_gInf_c::mFrameBufferTimg->mTexFmt = gx::GX_TF_RGBA8;
		mDoGph_gInf_c::mFrameBufferTimg->mTranslucency = 0;
		mDoGph_gInf_c::mFrameBufferTimg->mWidth = 0x140;
		mDoGph_gInf_c::mFrameBufferTimg->mHeight = 0xf0;
		mDoGph_gInf_c::mFrameBufferTimg->mMinFilter = gx::GX_LINEAR;
		mDoGph_gInf_c::mFrameBufferTimg->mMagFilter = gx::GX_LINEAR;
		mDoGph_gInf_c::mFrameBufferTimg->mTexDataOffs = 0x20;
		uVar1 = gx::GXGetTexBufferSize(0x140, 0xf0, 3, 0, 0);
		mDoGph_gInf_c::mZbufferTex = (void *)JKRHeap::alloc(uVar1, 0x20, (JKRHeap *)0x0);
		//SComponent::cLib_memSet(mDoGph_gInf_c::mZbufferTex, 0, uVar1);
		memset(mDoGph_gInf_c::mZbufferTex, 0, uVar1);
		J2DPrint::setBuffer(0x400);
		mDoGph_gInf_c::mBlureFlag = 0;
		mDoGph_gInf_c::mFade = 0;
		mDoGph_gInf_c::mBackColor = d_com_inf_game::g_clearColor;
		mDoGph_gInf_c::mFadeColor = d_com_inf_game::g_clearColor;
		vi::VISetBlack(1);
	}
}

namespace m_Do_graphic {
	int mDoGph_Create() {
		JKRSolidHeap *heap;

		heap = m_Do_ext::mDoExt_createSolidHeapToCurrent(0, (JKRHeap *)0x0, 0);
		mDoGph_gInf_c::create();
		//dDlst_list_c::init(&d_com_inf_game::g_dComIfG_gameInfo.mDlstList);
		//m_Do_ext::mDoExt_adjustSolidHeap(heap);
		m_Do_ext::mDoExt_restoreCurrentHeap();
		JFramework::JFWAutoAbortGfx = '\x02' - (mDoMain::developmentMode == '\0');
		return 1;
	}

	undefined4 mDoGph_AfterOfDraw(void) {
		bool bVar1;
		bool bVar2;
		uint uVar3;
		gx::GXColor local_8[2];

		if ((f_ap_game::g_HIO.debugdisp & 2) == 0) {
			uVar3 = !!(JUTGamePad::mPadStatus[3].button);
			//uVar3 = uVar3 >> 5 & 0xff;
			bVar1 = false;
			if (((uVar3 != 0) && (f_ap_game::g_HIO.forceprocessbar != 0)) &&
				(JFWSystem::systemConsole->candisplay == '\0')) {
				bVar1 = true;
			}
			bVar2 = false;
			if ((uVar3 != 0) && ((f_ap_game::g_HIO.debugdisp & 1) != 0)) {
				bVar2 = true;
			}
			if (mDoMain::developmentMode == '\0') {
				bVar1 = false;
				bVar2 = false;
			}
			JUTProcBar::sManager->mbDrawProcessBar = 1U - !bVar1;
			JUTProcBar::sManager->mbDrawHeapBar = 1U - !bVar1;
			JUTDbPrint::sDebugPrint->uk = '\x01' - !bVar2;
		} else {
			JUTProcBar::sManager->mbDrawProcessBar = 0;
			JUTProcBar::sManager->mbDrawHeapBar = 0;
			JUTDbPrint::sDebugPrint->uk = 1;
		}
		gx::GXSetZCompLoc(1);
		using namespace gx;
		gx::GXSetZMode(false, GX_ALWAYS, false);
		gx::GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_CLEAR);
		gx::GXSetAlphaCompare(GX_GREATER, 0, GX_AOP_OR, GX_GREATER, 0);
		// local_8[0] = d_com_inf_game::g_clearColor;
		gx::GXSetFog(GX_FOG_NONE, 0.0, 0.0, 0.0, 0.0, d_com_inf_game::g_clearColor);
		gx::GXSetFogRangeAdj(false, 0, nullptr);
		gx::GXSetCoPlanar(0);
		gx::GXSetZTexture(GXZTexOp::GX_ZT_DISABLE, (GXTexFmt)0x11, 0);
		gx::GXSetDither(1);
		gx::GXSetClipMode(GXClipMode::GX_CLIP_ENABLE);
		GXSetCullMode(gx::GXCullMode::GX_CULL_NONE);
		mDoMch_render_c::mRenderModeObj->fbWidth = f_ap_game::g_HIO.fbWidth;
		mDoMch_render_c::mRenderModeObj->efbHeight = f_ap_game::g_HIO.efbHeight;
		JUTVideo::sManager->setRenderMode(mDoMch_render_c::mRenderModeObj);
		d_com_inf_game::g_dComIfG_gameInfo.mDlstList.mPeekZ.peekData();
		JFWDisplay::sManager->endFrame();
		return 1;
	}

	void mDoGph_BlankingON() {}
	void mDoGph_BlankingOFF() {}

	void mDoGph_Painter() {
		//TODO
	}

	void dScnPly_BeforeOfPaint(void) {
		d_com_inf_game::g_dComIfG_gameInfo.mDlstList.reset();
	}

	undefined4 mDoGph_BeforeOfDraw(void) {
		dScnPly_BeforeOfPaint();
		return 1;
	}
}