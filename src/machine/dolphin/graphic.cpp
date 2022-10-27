#include "./graphic.h"

#include <JFramework/J2D/J2DPrint.h>
#include <JFramework/J3D/J3DSys.h>
#include <JFramework/JFWDisplay.h>
#include <JFramework/JFWSystem.h>
#include <JFramework/JKernel/JKRHeap.h>
#include <JFramework/JUtility/JUTFader.h>
#include <JFramework/JUtility/JUTVideo.h>
#include <common/dComIfG_inf_c.h>
#include <dolphin/base.h>
#include <f_ap/game.h>

#include <cstring>
#include <cstdio>

#include "./ext.h"

struct JUTFader;
void write_volatile_1(uint, ...);

namespace m_Do_mtx {
	mtx::Mtx g_mDoMtx_identity;
}

namespace mDoGph_gInf_c {
	JUTFader *mFader;

	ResTIMG *mFrameBufferTimg, *mFrameBufferTex;
	void *mZbufferTex;

	int mBlureFlag;
	int mFade;
	gx::GXColor mBackColor;
	gx::GXColor mFadeColor;

	int mMonotone;

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

	void free(void) {
		uint uVar1;

		uVar1 = (uint)mDoGph_gInf_c::mCurrentHeap;
		mDoGph_gInf_c::mCurrentHeap = (byte)(uVar1 ^ 1);
		mDoGph_gInf_c::mHeap[uVar1 ^ 1]->freeAll();
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
		iVar2 = gx::GXGetTexBufferSize(0x140, 0xf0, gx::GXTexFmt::GX_TF_RGBA8, 0, 0);
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
		uVar1 = gx::GXGetTexBufferSize(0x140, 0xf0, gx::GXTexFmt::GX_TF_IA8, 0, 0); // from page 209 of manual, "Use IA8 for Z16"
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

	void drawAlphaBuffer(camera_class *param_1, gx::GXColor *param_2) {
		using namespace gx;
		_GXColor local_58;
		GXColor local_54;
		MTX44 MStack80;

		gx::GXSetNumChans(1);
		gx::GXSetChanCtrl(GX_COLOR0A0, false, GX_SRC_REG, GX_SRC_REG, 0, GX_DF_NONE, GX_AF_NONE);
		local_54 = *param_2;
		gx::GXSetChanMatColor(GXChannelID::GX_COLOR0, local_54);
		gx::GXSetNumTexGens(0);
		gx::GXSetNumTevStages(1);
		gx::GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
		gx::GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO, GX_CC_RASC);
		gx::GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, true, GX_TEVPREV);
		gx::GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO);
		gx::GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, true, GX_TEVPREV);
		gx::GXSetZCompLoc(1);
		gx::GXSetZMode(false, GX_ALWAYS, false);
		gx::GXSetBlendMode(GX_BM_BLEND, GX_BL_DSTALPHA, GX_BL_ONE, GX_LO_OR);
		gx::GXSetAlphaCompare(GX_ALWAYS, 0, GX_AOP_OR, GX_ALWAYS, 0);
		local_58 = d_com_inf_game::g_clearColor;
		gx::GXSetFog(GX_FOG_NONE, 0.0, 0.0, 0.0, 0.0, local_58);
		gx::GXSetFogRangeAdj(false, 0, (_GXFogAdjTable *)0x0);
		gx::GXSetCullMode(GXCullMode::GX_CULL_NONE);
		gx::GXSetDstAlpha(1, 0);
		gx::GXSetDither(1);
		gx::GXSetColorUpdate(true);
		gx::GXSetAlphaUpdate(1);
		gx::GXSetNumIndStages(0);
		mtx::MTXOrtho(MStack80, 0.0, 1.0, 0.0, 1.0, 0.0, 10.0);
		gx::GXSetProjection(MStack80, GX_ORTHOGRAPHIC);
		gx::GXLoadPosMtxImm(m_Do_mtx::g_mDoMtx_identity, 0);
		gx::GXSetCurrentMtx(0);
		gx::GXClearVtxDesc();
		gx::GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
		gx::GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_S8, 0);
		gx::GXBegin(GXPrimitive::GX_QUADS, GXVtxFmt::GX_VTXFMT0, 4);
		// Vertex format is [Pos(3b)]

		gx::GXPosition3s16(0, 0, -5);
		gx::GXPosition3s16(1, 0, -5);
		gx::GXPosition3s16(1, 1, -5);
		gx::GXPosition3s16(0, 1, -5);

		gx::GXSetColorUpdate(true);
		gx::GXSetAlphaUpdate(0);
		gx::GXSetDstAlpha(0, 0);
		gx::GXSetProjection(param_1->mProjMtx, GX_PERSPECTIVE);
	}

	void clearAlphaBuffer(camera_class *param_1, byte param_2) {
		using namespace gx;
		_GXColor local_58;
		_GXColor local_54;
		_GXColor local_50;
		MTX44 MStack76;

		gx::GXSetNumChans(1);
		gx::GXSetChanCtrl(GX_COLOR0A0, false, GX_SRC_REG, GX_SRC_REG, 0, GX_DF_NONE, GX_AF_NONE);
		gx::GXSetNumTexGens(0);
		gx::GXSetNumTevStages(1);
		gx::GXSetTevOrder(GX_TEVSTAGE0, GX_TEXCOORD_NULL, GX_TEXMAP_NULL, GX_COLOR0A0);
		gx::GXSetTevColorIn(GX_TEVSTAGE0, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO, GX_CC_ZERO);
		gx::GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, true, GX_TEVPREV);
		gx::GXSetTevAlphaIn(GX_TEVSTAGE0, GX_CA_ZERO, GX_CA_ZERO, GX_CA_ZERO, GX_CA_A0);
		gx::GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, true, GX_TEVPREV);
		gx::GXSetZCompLoc(1);
		gx::GXSetZMode(false, GX_ALWAYS, false);
		gx::GXSetBlendMode(GX_BM_NONE, GX_BL_ZERO, GX_BL_ZERO, GX_LO_OR);
		gx::GXSetAlphaCompare(GX_ALWAYS, 0, GX_AOP_OR, GX_ALWAYS, 0);
		gx::GXSetFog(GX_FOG_NONE, 0.0, 0.0, 0.0, 0.0, d_com_inf_game::g_clearColor);
		gx::GXSetFogRangeAdj(false, 0, (_GXFogAdjTable *)0x0);
		gx::GXSetCullMode(GXCullMode::GX_CULL_NONE);
		gx::GXSetDither(1);
		gx::GXSetColorUpdate(false);
		gx::GXSetAlphaUpdate(1);
		gx::GXSetNumIndStages(0);
		local_50 = {0, 0, 0, param_2};
		local_58 = local_50;
		gx::GXSetTevColor(GX_TEVREG0, local_50);
		mtx::C_MTXOrtho(MStack76, 0.0, 1.0, 0.0, 1.0, 0.0, 10.0);
		gx::GXSetProjection(MStack76, GX_ORTHOGRAPHIC);
		gx::GXLoadPosMtxImm(m_Do_mtx::g_mDoMtx_identity, 0);
		gx::GXSetCurrentMtx(0);
		gx::GXClearVtxDesc();
		gx::GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
		gx::GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_S8, 0);
		gx::GXBegin(GXPrimitive::GX_QUADS, GXVtxFmt::GX_VTXFMT0, 4);

		gx::GXPosition3s16(0, 0, -5);
		gx::GXPosition3s16(1, 0, -5);
		gx::GXPosition3s16(1, 1, -5);
		gx::GXPosition3s16(0, 1, -5);

		gx::GXSetColorUpdate(true);
		gx::GXSetAlphaUpdate(0);
		gx::GXSetProjection(param_1->mProjMtx, GX_PERSPECTIVE);
		return;
	}

	// code possibly related to the pictobox functionality was removed
	int mDoGph_Painter() {
		uint uVar1;
		bool bVar2;
		JFWDisplay *pJVar3;
		int iVar4;
		undefined4 uVar5;
		undefined4 uVar6;
		undefined4 uVar7;
		undefined4 uVar8;
		int iVar9;
		byte bVar10;
		dPa_control_c *partclctr;
		dDlst_list_c *this_00;
		dDlst_window_c *pWindow;
		camera_class *pView;
		u8 uStack534;
		u8 uStack533;
		gx::GXColor local_214;
		gx::GXColor local_210;
		gx::GXColor local_20c;
		undefined4 local_208;
		undefined auStack516[4];
		TBox2<float> local_200;
		TBox2<float> local_1f0;
		JPADrawInfo local_1e0;
		JPADrawInfo local_1d4;
		JPADrawInfo JStack456;
		MTX34 MStack444;
		MTX34 MStack396;
		os::OSAlarm OStack344;
		dDlst_window_c dStack304;

		JFWDisplay::sManager->mpFader = mDoGph_gInf_c::mFader;
		pJVar3 = JFWDisplay::sManager;
		JFWDisplay::sManager->clearColor = mDoGph_gInf_c::mBackColor;
		JFWDisplay::sManager->beginRender();
		JFWDisplay::sManager->endRender();
		return 1;
		gx::GXSetAlphaUpdate(0);
		mDoGph_gInf_c::mBackColor = d_com_inf_game::g_clearColor;
		mDoGph_gInf_c::free();
		J3DGraphBase::j3dSys.drawInit();
		gx::GXSetDither(1);
		struct J2DOrthoGraph JStack264(0.0, 0.0, 640.0, 480.0, -1.0, 1.0);
		local_1f0.mTL[0] = -9.0;
		local_1f0.mTL[1] = -21.0;
		local_1f0.mBR[0] = 650.0;
		local_1f0.mBR[1] = 503.0;
		JStack264.setOrtho(&local_1f0, -1.0, 1.0);
		JStack264.setPort();
		auto &ginfo = d_com_inf_game::g_dComIfG_gameInfo;
		auto &gdlist = d_com_inf_game::g_dComIfG_gameInfo.mDlstList;
		auto &gplay = d_com_inf_game::g_dComIfG_gameInfo.mPlay;

		ginfo.mPlay.mp2DOrthoGraph = &JStack264;
		gdlist.draw(gdlist.list_a);

		if (gplay.field66_0x4841) {
			pWindow = &gplay.mDlstWindow;
			iVar4 = (int)(char)gplay.mCurCameraInfo;
			pView = gplay.mCameraInfo[iVar4].mpCamera;
			if (pView) {
				// update the projected shadow
				// dDlst_shadowControl_c::imageDraw(&gdlist.mShadowControl, &pView->mViewMtx);

				if ((gplay.mDlstWindow.mXOrig != 0.0) ||
					(gplay.mDlstWindow.mYOrig != 0.0)) {
					dStack304.mXOrig = (gplay.mDlstWindow.mXOrig * 2.0 +
										gplay.mDlstWindow.mWidth) *
										   0.5 -
									   320.0;
					dStack304.mYOrig = (gplay.mDlstWindow.mYOrig * 2.0 +
										gplay.mDlstWindow.mHeight) *
										   0.5 -
									   240.0;

					dStack304.mWidth = 640.0;
					dStack304.mHeight = 480.0;
					dStack304.mNearZ = gplay.mDlstWindow.mNearZ;
					dStack304.mFarZ = gplay.mDlstWindow.mFarZ;
					dStack304.mScissorXOrig = gplay.mDlstWindow.mScissorXOrig;
					dStack304.mScissorYOrig = gplay.mDlstWindow.mScissorYOrig;
					dStack304.mScissorWidth = gplay.mDlstWindow.mScissorWidth;
					dStack304.mScissorHeight = gplay.mDlstWindow.mScissorHeight;
					pWindow = &dStack304;
				}
				gx::GXSetViewport(pWindow->mXOrig, pWindow->mYOrig, pWindow->mWidth,
								  pWindow->mHeight, pWindow->mNearZ, pWindow->mFarZ);
				uVar5 = pWindow->mHeight;
				uVar6 = pWindow->mWidth;
				uVar7 = pWindow->mYOrig;
				uVar8 = pWindow->mXOrig;
				gx::GXSetScissor(uVar8, uVar7, uVar6, uVar5);
				JStack456.mpViewMtx = &pView->mViewMtx;
				JStack456.mFovY = pView->mFovY;
				JStack456.mAspect = pView->mAspect;
				bVar2 = false;
				//iVar9 = strcmp(gplay.mCurStage.mStageName, "GTower");
				//if (iVar9 == 0) {
				//	if (gplay.mCurStage.mLayerNo == 9) {
				//		bVar2 = true;
				//	}
				//}
				gplay.field448_0x4a54 = &gplay.mDlstWindow;
				gplay.field449_0x4a58 = pView;
				gplay.field450_0x4a5c = pWindow;
				gx::GXSetProjection(pView->mProjMtx, gx::GX_PERSPECTIVE);
				base::PPCSync();
				mtx::MTXCopy(pView->mViewMtx, J3DGraphBase::j3dSys.mCurViewMtx);
				//d_kankyo::dKy_setLight();
				J3DGraphBase::j3dSys.mCurDrawMode = 3;
				gdlist.mpBufSkyOpa->draw();
				J3DGraphBase::j3dSys.mCurDrawMode = 4;
				gdlist.mpBufSkyXlu->draw();
				//bVar10 = d_meter::dMenu_flag();
				bVar10 = false;
				if (((bVar10 == 0) && ((dPa_control_c::mStatus & 1) != 0)) &&
					(gplay.mParticleCtrl)) {
					gplay.mParticleCtrl->draw(&JStack456, 5);
				}
				gx::GXSetClipMode(gx::GXClipMode::GX_CLIP_DISABLE);
				J3DGraphBase::j3dSys.mCurDrawMode = 3;
				gdlist.mpBufWorldOpa->draw();

				// effectively draws the shadow
				// dDlst_shadowControl_c::draw(&gdlist.mShadowControl, &pView->mViewMtx);

				//gdlist.mpAlphaModel0->draw(&pView->mViewMtx);
				//local_20c = (gdlist.mpAlphaModel0)->mColor;
				//m_Do_graphic::drawAlphaBuffer(pView, &local_20c);
				//if ((gdlist.mpAlphaModel1)->mCount != 0) {
				//	m_Do_graphic::clearAlphaBuffer(pView, 0);
				//	gdlist.mpAlphaModel1.draw(&pView->mViewMtx);
				//	local_210 = (gdlist.mpAlphaModel1)->mColor;
				//	m_Do_graphic::drawAlphaBuffer(pView, &local_210);
				//}
				if (mDoGph_gInf_c::mMonotone == 0) {
					J3DGraphBase::j3dSys.mCurDrawMode = 3;
					gdlist.mpLinkBuf->drawTail();
					J3DGraphBase::j3dSys.mCurDrawMode = 3;
					gdlist.linkBodyBuffOpa->draw();
				}
				J3DGraphBase::j3dSys.mCurDrawMode = 3;
				gdlist.mpBufInvisibleModelOpa->draw();
				J3DGraphBase::j3dSys.mCurDrawMode = 4;
				gdlist.mpBufWorldXlu->draw();
				//if ((gdlist.mpAlphaModel2)->mCount != 0) {
				//	m_Do_graphic::clearAlphaBuffer(pView, ((gdlist.mpAlphaModel2)->mColor).a);
				//}
				//bVar10 = d_meter::dMenu_flag();
				bVar10 = false;
				if (((bVar10 == 0) && ((dPa_control_c::mStatus & 1) == 0)) &&
					(gplay.mParticleCtrl)) {
					gplay.mParticleCtrl->draw(&JStack456, 5);
				}
				if (mDoGph_gInf_c::mMonotone == 0) {
					J3DGraphBase::j3dSys.mCurDrawMode = 3;
					gdlist.linkBodyBuffTranslu->draw();
				}
				J3DGraphBase::j3dSys.mCurDrawMode = 4;
				gdlist.mpBufInvisibleModelXlu->draw();
				//bVar10 = d_meter::dMenu_flag();
				bVar10 = false;
				if (bVar10 == 0) {	// if the game is not paused (as in item select pause menu)
					if (gplay.mParticleCtrl) {
						gplay.mParticleCtrl->draw(&JStack456, 0);
					}
					if ((mDoGph_gInf_c::mMonotone == 0) &&
						(gplay.mParticleCtrl)) {
						gplay.mParticleCtrl->draw(&JStack456, 1);
					}
					local_1d4.mpViewMtx = (MTX34 *)&dPa_control_c::mWindViewMatrix;
					local_1d4.mFovY = pView->mFovY;
					local_1d4.mAspect = pView->mAspect;
					if (gplay.mParticleCtrl) {
						gplay.mParticleCtrl->draw(&local_1d4, 6);
					}
					if (gplay.mParticleCtrl) {
						gplay.mParticleCtrl->draw(&JStack456, 2);
					}
					if ((mDoGph_gInf_c::mMonotone == 0) &&
						(gplay.mParticleCtrl)) {
						gplay.mParticleCtrl->draw(&JStack456, 3);
					}
					gx::GXSetClipMode(gx::GXClipMode::GX_CLIP_DISABLE);
				}
				J3DGraphBase::j3dSys.mCurDrawMode = 3;
				gdlist.mpWetherFxBuffer->draw();
				J3DGraphBase::j3dSys.reinitGX();
				gx::GXSetNumIndStages(0);
				//if ((gdlist.mpAlphaModel2)->mCount != 0) {
				//	gdlist.mpAlphaModel0.draw(&pView->mViewMtx);
				//	gdlist.mpAlphaModel2.draw(&pView->mViewMtx);
				//	m_Do_graphic::drawSpot(pView);
				//}
				gx::GXSetClipMode(gx::GXClipMode::GX_CLIP_DISABLE);
				J3DGraphBase::j3dSys.mCurDrawMode = 3;
				gdlist.mpBufInvisibleModelMaskOffOpa->draw();
				J3DGraphBase::j3dSys.mCurDrawMode = 4;
				gdlist.mpBufInvisibleModelMaskOffXlu->draw();
				//bVar10 = d_meter::dMenu_flag();
				bVar10 = false;
				if (bVar10 == 0) {
					// supposedly the motion blur from damage and camera shakes
					//m_Do_graphic::motionBlure(pView);
					// updates the image shown behind the pause menu
					// it's also the image used for the diffraction pattern on glasslike translucent objects
					//m_Do_graphic::drawDepth(pView, pWindow, (int)gplay.mCameraInfo[iVar4].field7_0x10);
					if (gplay.mParticleCtrl) {
						gplay.mParticleCtrl->draw(&JStack456, 4);
					}
					gx::GXSetClipMode(gx::GXClipMode::GX_CLIP_DISABLE);
					J3DGraphBase::j3dSys.mCurDrawMode = 3;
					gdlist.mpBufDistortionOpa->draw();
					J3DGraphBase::j3dSys.mCurDrawMode = 4;
					gdlist.mpBufDistortionXlu->draw();
					J3DGraphBase::j3dSys.reinitGX();
					partclctr = (dPa_control_c *)0x0;
					gx::GXSetNumIndStages(0);
					if ((bVar2) &&	// if on GTower and Layer 9
						(partclctr = gplay.mParticleCtrl,
						 gplay.mParticleCtrl)) {
						gplay.mParticleCtrl->draw(&JStack456, 0);
					}
					if (mDoGph_gInf_c::mMonotone != 0) {
						m_Do_graphic::clearAlphaBuffer(pView, 0);
						J3DGraphBase::j3dSys.mCurDrawMode = 3;
						gdlist.mpLinkBuf->drawTail();
						J3DGraphBase::j3dSys.mCurDrawMode = 3;
						gdlist.linkBodyBuffOpa->draw();
						J3DGraphBase::j3dSys.mCurDrawMode = 3;
						gdlist.linkBodyBuffTranslu->draw();
						if (gplay.mParticleCtrl) {
							gplay.mParticleCtrl->draw(&JStack456, 1);
						}
						partclctr = gplay.mParticleCtrl;
						if (gplay.mParticleCtrl) {
							gplay.mParticleCtrl->draw(&JStack456, 3);
						}
					}
					// fade in when changing scenes
					//mDoGph_gInf_c::calcFade();
				}
			}
		}

		//this_00->calcWipe();
		J3DGraphBase::j3dSys.reinitGX();
		gx::GXSetNumIndStages(0);
		local_200.mTL[0] = -9.0;
		local_200.mTL[1] = -21.0;
		local_200.mBR[0] = 650.0;
		local_200.mBR[1] = 503.0;
		JStack264.setOrtho(&local_200, 100000.0, -100000.0);
		JStack264.setPort();
		mtx::MTXTrans(MStack396, 320.0, 240.0, 0.0);
		local_1e0.mpViewMtx = &MStack396;
		local_1e0.mFovY = 0.0;
		local_1e0.mAspect = 1.333333;
		//bVar10 = d_meter::dMenu_flag();
		bVar10 = false;
		if ((bVar10 == 0) &&
			(gplay.mParticleCtrl)) {
			gplay.mParticleCtrl->draw(&local_1e0, 8);
		}
		if (gplay.mParticleCtrl) {
			gplay.mParticleCtrl->draw(&local_1e0, 10);
		}
		if (gdlist.titleScreenBuff->mpPacketBuf[0]) {
			mtx::MTXCopy(J3DGraphBase::j3dSys.mCurViewMtx, MStack444);
			//m_Do_graphic::setLight();
			//mtx::MTXTrans(mDoMtx_stack_c::now, 320.0, 240.0, 1000.0);
			//m_Do_mtx::mDoMtx_ZrotM(mDoMtx_stack_c::now, -0x8000);
			//mtx::MTXCopy(mDoMtx_stack_c::now, J3DGraphBase::j3dSys.mCurViewMtx);
			J3DGraphBase::j3dSys.mCurDrawMode = 3;
			gdlist.titleScreenBuff->draw();
			J3DGraphBase::j3dSys.reinitGX();
			gx::GXSetNumIndStages(0);
			mtx::MTXCopy(MStack444, J3DGraphBase::j3dSys.mCurViewMtx);
		}
		gdlist.draw(gdlist.mp2DArr);
		gdlist.draw(gdlist.list_b);
		gdlist.draw(gdlist.list_c);
		//bVar10 = d_meter::dMenu_flag();
		bVar10 = false;
		if ((bVar10 == 0) &&
			(gplay.mParticleCtrl)) {
			gplay.mParticleCtrl->draw(&local_1e0, 7);
		}
		if (gplay.mParticleCtrl) {
			gplay.mParticleCtrl->draw(&local_1e0, 9);
		}
		JFWDisplay::sManager->endRender();
		return 1;
	}

	void dScnPly_BeforeOfPaint(void) {
		d_com_inf_game::g_dComIfG_gameInfo.mDlstList.reset();
	}

	undefined4 mDoGph_BeforeOfDraw(void) {
		dScnPly_BeforeOfPaint();
		return 1;
	}
}