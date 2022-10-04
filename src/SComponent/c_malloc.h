#pragma once

struct JKRHeap;

namespace cMl {
	extern JKRHeap *Heap;
	JKRHeap *init(JKRHeap *ctx);

	void *memalignB(int param_1, unsigned long param_2);

	void free(void *__ptr);
}