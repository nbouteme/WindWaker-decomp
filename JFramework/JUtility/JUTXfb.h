#pragma once
#include <doltypes.h>

#include "../../dolphin/gx.h"
#include "../JKernel/JKRHeap.h"
#include "../JKernel/JKernel.h"
#include "JUTVideo.h"
#include "JUtility.h"

using EXfbNumber = int;
using ushort = unsigned short;

struct JUTXfb {
	static JUTXfb *sManager;

	void *xfb0, *xfb1, *xfb2;
	byte hasxfb0, hasxfb1, hasxfb2;
	int xfbnum;
	short idx0, idx1, idx2;
	int renderStatus;

	static JUTXfb *createManager(gx::GXRenderModeObj *param_1, JKRHeap *heap, EXfbNumber param_3);
	static void destroyManager(void);

	void clearIndex();
	void JUTXfb::common_init(int param_1);
	void initiate(ushort width, ushort height, JKRHeap *heap, EXfbNumber numexfb);
	JUTXfb(gx::GXRenderModeObj *param_1, JKRHeap *heap, EXfbNumber xfbnum);
	void delXfb(int param_1);
	~JUTXfb();
};