#include <dolphin/gx.h>

namespace gx {
	void GXInitFifoBase(gx::GXFifoObj *, void *, unsigned int) {}
	void GXInitFifoPtrs(gx::GXFifoObj *, void *, void *) {}
	void GXInvalidateTexAll() {}
	void GXPeekZ(unsigned short, unsigned short, unsigned int *) {}
	void GXPixModeSync() {}
	void GXSaveCPUFifo(gx::GXFifoObj *) {}
	void GXSetColorUpdate(unsigned char) {}
	void GXSetCopyClamp(gx::_GXFBClamp) {}
	void GXSetCopyClear(gx::_GXColor, unsigned int) {}
	void GXSetCopyFilter(unsigned char, unsigned char const (*)[2], unsigned char, unsigned char const *) {}
	void GXSetDispCopyDst(unsigned short, unsigned short) {}
	void GXSetDispCopyGamma(gx::_GXGamma) {}
	void GXSetDispCopySrc(unsigned short, unsigned short, unsigned short, unsigned short) {}
	void GXSetFog(gx::_GXFogType, float, float, float, float, gx::_GXColor) {}
	void GXSetFogRangeAdj(unsigned char, unsigned short, gx::_GXFogAdjTable const *) {}
	void GXSetIndTexCoordScale(gx::_GXIndTexStageID, gx::_GXIndTexScale, gx::_GXIndTexScale) {}
	void GXSetIndTexMtx(gx::_GXIndTexMtxID, float const (*)[3], char) {}
	void GXSetMisc(gx::_GXMiscToken, unsigned int) {}
	void GXSetTevColorS10(gx::_GXTevRegID, gx::_GXColorS10) {}
	void GXSetTevDirect(gx::_GXTevStageID) {}
	void GXSetTevIndirect(gx::_GXTevStageID, gx::_GXIndTexStageID, gx::_GXIndTexFormat, gx::_GXIndTexBiasSel, gx::_GXIndTexMtxID, gx::_GXIndTexWrap, gx::_GXIndTexWrap, unsigned char, unsigned char, gx::_GXIndTexAlphaSel) {}
	void GXSetTevKColor(gx::_GXTevKColorID, gx::_GXColor) {}
	void GXSetTevSwapMode(gx::_GXTevStageID, gx::_GXTevSwapSel, gx::_GXTevSwapSel) {}
	void GXAbortFrame() {}
	void GXGetGPStatus(unsigned char *, unsigned char *, unsigned char *, unsigned char *, unsigned char *) {}
	void GXInitTexObjLOD(gx::_GXTexObj *, gx::_GXTexFilter, gx::_GXTexFilter, float, float, float, unsigned char, unsigned char, gx::_GXAnisotropy) {}
	void GXInvalidateVtxCache() {}
	void GXLoadTexMtxImm(float const (*)[4], unsigned int, gx::_GXTexMtxType) {}
	void GXReadXfRasMetric(unsigned int *, unsigned int *, unsigned int *, unsigned int *) {}
	void GXSetChanMatColor(gx::_GXChannelID, gx::_GXColor) {}
	void GXSetClipMode(gx::_GXClipMode) {}
	void GXSetCoPlanar(unsigned char) {}
	void GXSetDrawDone() {}
	void GXSetDstAlpha(unsigned char, unsigned char) {}
	void GXSetLineWidth(unsigned char, gx::_GXTexOffset) {}
	void GXSetNumIndStages(unsigned char) {}
	void GXSetProjection(float const (*)[4], gx::_GXProjectionType) {}
	void GXSetTevOp(gx::_GXTevStageID, gx::_GXTevMode) {}
	void GXSetViewport(float, float, float, float, float, float) {}
	void GXCopyDisp(void *, unsigned char) {}
	void GXInitTexObj(gx::_GXTexObj *, void *, unsigned short, unsigned short, gx::_GXTexFmt, gx::_GXTexWrapMode, gx::_GXTexWrapMode, unsigned char) {}
	void GXSetAlphaUpdate(unsigned char) {}
	void GXSetCurrentMtx(unsigned int) {}
	void GXSetPixelFmt(gx::_GXPixelFmt, gx::_GXZFmt16) {}
	void GXSetScissor(unsigned int, unsigned int, unsigned int, unsigned int) {}
	void GXSetTevColor(gx::_GXTevRegID, gx::_GXColor) {}
	void GXSetTexCoordGen2(gx::_GXTexCoordID, gx::_GXTexGenType, gx::_GXTexGenSrc, unsigned int, unsigned char, unsigned int) {}
	void GXSetZTexture(gx::_GXZTexOp, gx::_GXTexFmt, unsigned int) {}
	void GXBegin(gx::_GXPrimitive, gx::_GXVtxFmt, unsigned short) {}
	void GXClearVtxDesc() {}

	void GXDrawDone() {
		
	}

	void GXSetAlphaCompare(gx::_GXCompare, unsigned char, gx::_GXAlphaOp, gx::_GXCompare, unsigned char) {}
	void GXSetCullMode(gx::_GXCullMode) {}
	void GXSetTevAlphaIn(gx::_GXTevStageID, gx::_GXTevAlphaArg, gx::_GXTevAlphaArg, gx::_GXTevAlphaArg, gx::_GXTevAlphaArg) {}
	void GXSetTevAlphaOp(gx::_GXTevStageID, gx::_GXTevOp, gx::_GXTevBias, gx::_GXTevScale, unsigned char, gx::_GXTevRegID) {}
	void GXSetTevColorIn(gx::_GXTevStageID, gx::_GXTevColorArg, gx::_GXTevColorArg, gx::_GXTevColorArg, gx::_GXTevColorArg) {}
	void GXSetTevColorOp(gx::_GXTevStageID, gx::_GXTevOp, gx::_GXTevBias, gx::_GXTevScale, unsigned char, gx::_GXTevRegID) {}
	void GXSetTevSwapModeTable(gx::_GXTevSwapSel, gx::_GXTevColorChan, gx::_GXTevColorChan, gx::_GXTevColorChan, gx::_GXTevColorChan) {}
	void GXSetZCompLoc(unsigned char) {}
	void GXLoadPosMtxImm(float const (*)[4], unsigned int) {}
	void GXSetDither(unsigned char) {}
	void GXSetNumChans(unsigned char) {}
	void GXSetNumTevStages(unsigned char) {}
	void GXSetNumTexGens(unsigned char) {}
	void GXSetZMode(unsigned char, gx::_GXCompare, unsigned char) {}
	void GXFlush() {}
	void GXLoadTexObj(gx::_GXTexObj const *, gx::_GXTexMapID) {}
	void GXSetBlendMode(gx::_GXBlendMode, gx::_GXBlendFactor, gx::_GXBlendFactor, gx::_GXLogicOp) {}
	void GXSetChanCtrl(gx::_GXChannelID, unsigned char, gx::_GXColorSrc, gx::_GXColorSrc, unsigned int, gx::_GXDiffuseFn, gx::_GXAttnFn) {}
	void GXSetTevOrder(gx::_GXTevStageID, gx::_GXTexCoordID, gx::_GXTexMapID, gx::_GXChannelID) {}
	void GXSetVtxDesc(gx::_GXAttr, gx::_GXAttrType) {}
	void GXSetVtxAttrFmt(gx::_GXVtxFmt, gx::_GXAttr, gx::_GXCompCnt, gx::_GXCompType, unsigned char) {}

	OSThread *GXGetCurrentGXThread() { return nullptr; }
	u16 GXGetNumXfbLines(unsigned short, float) { return 0; }
	GXFifoObj *GXInit(void *, unsigned int) { return nullptr; }
	OSThread *GXSetCurrentGXThread() { return nullptr; }
	u32 GXSetDispCopyYScale(float) { return 0; }
	u32 GXGetTexBufferSize(unsigned short, unsigned short, unsigned int, unsigned char, unsigned char) { return 0; }
	float GXGetYScaleFactor(unsigned short, unsigned short) { return 0; }
	using CB = void();
	CB *GXSetDrawDoneCallback(CB *) { return nullptr; }

}