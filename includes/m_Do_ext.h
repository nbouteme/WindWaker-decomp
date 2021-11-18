#pragma once
#include <ctypes.h>

#include <mDoExt_3DlineMat0__vtbl.h>


namespace m_Do_ext {
//[Data] Expected size is 0x000085
extern undefined l_invisibleMat$7212;

//[Data] Expected size is 0x00008d
extern undefined l_matDL;

//[Data] Expected size is 0x00009c
extern undefined l_toonMatDL;

//[Data] Expected size is 0x000096
extern undefined l_mat1DL;

//[Data] Expected size is 0x0000a5
extern undefined l_toonMat1DL;

}
//[Data] Expected size is 0x000044
extern pointer JUTFont;

//[Data] Expected size is 0x000018
extern undefined1 mDoExt_3DlineMatSortPacket;

//[Data] Expected size is 0x000014
extern pointer mDoExt_3DlineMat1_c;

//[Data] Expected size is 0x000014
extern struct mDoExt_3DlineMat0__vtbl mDoExt_3DlineMat0_c;

//[Data] Expected size is 0x000018
extern undefined1 mDoExt_invJntPacket;

//[Data] Expected size is 0x000018
extern undefined1 mDoExt_onCupOffAupPacket;

//[Data] Expected size is 0x000018
extern undefined1 mDoExt_offCupOnAupPacket;

//[Data] Expected size is 0x000034
extern undefined1 mDoExt_McaMorf2;


namespace mDoExt_McaMorf {
//[Data] Expected size is 0x000034
extern pointer __vt;

}

namespace mDoExt_zelAnime {
//[Data] Expected size is 0x000010
extern undefined1 __vt;

}
//[Data] Expected size is 0x000034
extern undefined1 mDoExt_MtxCalcAnmBlendTblOld;

//[Data] Expected size is 0x000034
extern undefined1 mDoExt_MtxCalcAnmBlendTbl;

//[Data] Expected size is 0x000044
extern undefined1 J3DMtxCalcMayaAnm;

//[Data] Expected size is 0x000018
extern pointer J3DMtxCalc;

//[Data] Expected size is 0x00000c
extern pointer J3DFrameCtrl;


namespace m_Do_ext {
//[Data] Expected size is 0x000006
extern undefined l_normal$7302;

//[Data] Expected size is 0x000006
extern sbyte l_normal$7801[2][3];

//[BSS] Expected size is 0x000004
extern struct JKRHeap * gameHeap;
//[BSS] Expected size is 0x000004
extern undefined4 safeGameHeapSize;
//[BSS] Expected size is 0x000004
extern struct JKRHeap * zeldaHeap;
//[BSS] Expected size is 0x000004
extern undefined4 safeZeldaHeapSize;
//[BSS] Expected size is 0x000004
extern undefined4 commandHeap;
//[BSS] Expected size is 0x000004
extern undefined4 safeCommandHeapSize;
//[BSS] Expected size is 0x000004
extern struct JKRHeap * archiveHeap;
//[BSS] Expected size is 0x000004
extern undefined4 safeArchiveHeapSize;
//[BSS] Expected size is 0x000004
extern undefined4 mDoExt_SaveCurrentHeap;
//[BSS] Expected size is 0x000004
extern undefined4 mDoExt_font0;
//[BSS] Expected size is 0x000004
extern undefined4 mDoExt_font0_getCount;
//[BSS] Expected size is 0x000004
extern undefined4 mDoExt_resfont0;
//[BSS] Expected size is 0x000004
extern undefined4 mDoExt_font1;
//[BSS] Expected size is 0x000004
extern undefined4 mDoExt_font1_getCount;
//[BSS] Expected size is 0x000004
extern undefined4 mDoExt_resfont1;
void mDoExt_setJ3DData(MTX34 *pDst,J3DTransformInfo *pInfo,uint param_3);
}

namespace m_Do_ext {
bool isCurrentSolidHeap(void);
}

namespace m_Do_ext {
void mDoExt_changeMaterial(J3DModel *param_1);
void mDoExt_modelTexturePatch(J3DModelData *param_1);
}

namespace m_Do_ext {
void mDoExt_modelDiff(J3DModel *param_1);
void mDoExt_modelUpdate(J3DModel *param_1);
void mDoExt_modelUpdateDL(J3DModel *param_1);
void mDoExt_modelEntry(J3DModel *param_1);
void mDoExt_modelEntryDL(J3DModel *model);
}

namespace m_Do_ext {
JKRHeap * mDoExt_createGameHeap(ulong param_1,JKRHeap *param_2);
JKRExpHeap * mDoExt_getGameHeap(void);
void mDoExt_setSafeGameHeapSize(void);
undefined4 mDoExt_getSafeGameHeapSize(void);
JKRHeap * mDoExt_createZeldaHeap(ulong param_1,JKRHeap *param_2);
JKRHeap * mDoExt_getZeldaHeap(void);
void mDoExt_setSafeZeldaHeapSize(void);
undefined4 mDoExt_getSafeZeldaHeapSize(void);
void mDoExt_createCommandHeap(ulong param_1,JKRHeap *param_2);
JKRHeap * mDoExt_getCommandHeap(void);
void mDoExt_setSafeCommandHeapSize(void);
undefined4 mDoExt_getSafeCommandHeapSize(void);
JKRHeap * mDoExt_createArchiveHeap(ulong param_1,JKRHeap *param_2);
void mDoExt_setSafeArchiveHeapSize(void);
undefined4 mDoExt_getSafeArchiveHeapSize(void);
JKRHeap * mDoExt_getArchiveHeap(void);
JKRSolidHeap *mDoExt_createSolidHeap(int maxHeapSize,JKRHeap *param_2,uint param_3,bool param_4);
void mDoExt_createSolidHeapFromGame(int param_1,uint param_2,undefined4 param_3,undefined param_4);
JKRHeap * mDoExt_createSolidHeapFromSystem(int param_1,uint param_2,undefined4 param_3,bool param_4);
JKRSolidHeap *mDoExt_createSolidHeapToCurrent(int maxHeapSize,JKRHeap *param_2,uint param_3,bool param_4);
JKRSolidHeap * mDoExt_createSolidHeapFromGameToCurrent(int maxHeapSize,int param_2);
uint mDoExt_adjustSolidHeap(JKRSolidHeap *param_1);
void mDoExt_destroySolidHeap(JKRHeap *param_1);
void mDoExt_setCurrentHeap(JKRHeap *param_1);
JKRHeap * mDoExt_getCurrentHeap(void);
void mDoExt_restoreCurrentHeap(void);
int mDoExt_resIDToIndex(JKRArchive *param_1,ushort param_2);
}

namespace m_Do_ext {
void mDoExt_initFontCommon(JUTResFont **param_1,ResFONT **param_2,JKRHeap *param_3,char *param_4,JKRArchive *param_5,char param_6,int param_7,int param_8);
}

namespace m_Do_ext {
void mDoExt_initFont0(void);
JUTFont * mDoExt_getMesgFont(void);
void mDoExt_removeMesgFont(void);
void mDoExt_initFont1(void);
JUTFont * mDoExt_getRubyFont(void);
void mDoExt_removeRubyFont(void);
J3DModel * mDoExt_J3DModel__create(J3DModelData *pModel,ulong param_2,ulong param_3);
}
