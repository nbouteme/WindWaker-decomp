#pragma once

#include <JFramework/JUtility/JUTGamePad.h>
#include <dDlst.h>
#include <dolphin/gx.h>
#include <doltypes.h>

#include "dComIfG_inf_c.h"
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

struct ResTIMG {
	gx::GXTexFmt mTexFmt;	   // 0
	byte mTranslucency;			   // 1
	ushort mWidth;				   //
	ushort mHeight;				   //
	gx::GXTexWrapMode mWrapS;  //
	gx::GXTexWrapMode mWrapT;  //
	byte mbHasTlut;				   //
	gx::GXTlutFmt mTlutFmt;	   //
	short mTlutCount;			   //
	int mTlutDataOffs;			   //
	byte mbMipmapEnabled;		   //
	byte mbDoEdgeLOD;			   //
	byte mbBiasClamp;			   //
	gx::GXAnisotropy mMaxAniso;
	gx::GXTexFilter mMinFilter;
	gx::GXTexFilter mMagFilter;
	byte mbMinLOD;
	byte mbMaxLOD;
	byte mbMipmapCount;
	byte unk1;
	short mLODBias;
	int mTexDataOffs;
};