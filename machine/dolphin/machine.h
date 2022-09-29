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

	void myHeapCheckRecursive(JKRHeap *param_1) {
		char cVar3;
		char *uVar1;
		JSUPtrLink *pJVar2;

		cVar3 = param_1->check();
		if (cVar3 == '\0') {
			uVar1 = m_Do_machine::myGetHeapTypeByString(param_1);
			m_Do_printf::OSReport_Error("error in %08x(%s)\n", param_1, uVar1);
		}
		pJVar2 = (param_1->mChildHeap).mpHead;
		if (pJVar2) {
			pJVar2 = (JSUPtrLink *)&pJVar2[-1].mpList;
		}
		while (pJVar2 != (JSUPtrLink *)0x0) {
			m_Do_machine::myHeapCheckRecursive((JKRHeap *)pJVar2->mpNext);
			pJVar2 = pJVar2[1].mpPrev;
			if (pJVar2) {
				pJVar2 = (JSUPtrLink *)&pJVar2[-1].mpList;
			}
		}
	}

	void mDoMch_HeapCheckAll() {
		m_Do_machine::myHeapCheckRecursive(JKRHeap::sRootHeap);
	}
}