#pragma once

#include <JFramework/JKernel/JKRHeap.h>

namespace mDoMch {
	extern char mDebugFill;
}

struct mDoMch_render_c {
	static gx::GXRenderModeObj *mRenderModeObj;
};

namespace m_Do_machine {
	int mDoMch_Create();
	char *myGetHeapTypeByString(JKRHeap *param_1);
	void myHeapCheckRecursive(JKRHeap *param_1);
	void mDoMch_HeapCheckAll();
}