#include <JKernel/JKRHeap.h>

namespace cMl {
	JKRHeap *Heap;
	JKRHeap *init(JKRHeap *ctx) {
		Heap = ctx;
		return ctx;
	}

	void *memalignB(int param_1, unsigned long param_2) {
		void *pvVar1;

		if (param_2 == 0) {
			pvVar1 = (void *)0x0;
		} else {
			pvVar1 = Heap->alloc(param_2, param_1);
		}
		return pvVar1;
	}

	void free(void *__ptr) {
		if (__ptr) {
			cMl::Heap->free(__ptr);
		}
	}
}