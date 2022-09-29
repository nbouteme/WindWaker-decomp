#include "../../machine/dolphin/printf.h"
#include "JKRHeap.h"
#include <doltypes.h>

void *operator new(ulong size) {
	void *pvVar1;

	pvVar1 = (void *)JKRHeap::alloc(size, 4, (JKRHeap *)0x0);
	return pvVar1;
}

void *operator new(ulong size, int param_2) {
	void *pvVar1;

	pvVar1 = (void *)JKRHeap::alloc(size, param_2, (JKRHeap *)0x0);
	return pvVar1;
}

void *operator new(ulong size, JKRHeap *heap, int align) {
	void *pvVar1;

	pvVar1 = (void *)JKRHeap::alloc(size, align, heap);
	return pvVar1;
}

void *operator new[](unsigned long param_1) {
	return JKRHeap::alloc(param_1, 4, nullptr);
}

void *operator new[](unsigned long param_1, int param_2) {
	return JKRHeap::alloc(param_1, param_2, nullptr);
}

void *operator new[](unsigned long param_1, JKRHeap *param_2, int param_3) {
	return JKRHeap::alloc(param_1, param_3, param_2);
}

void operator delete(void *ptr) {
	JKRHeap::free(ptr, nullptr);
}

void operator delete[](void *param_1) {
	JKRHeap::free(param_1, nullptr);
}

namespace JKernel {
	void JKRDefaultMemoryErrorRoutine(JKRHeap *param_1, int param_2, int param_3) {
		m_Do_printf::OSReport("Error: Cannot allocate memory %d(0x%x)byte in %d byte alignment from %08x\n", param_2,
							  param_2, param_3, param_1);
		m_Do_printf::OSPanic("JKRHeap.cpp", 0x2ff, "abort\n");
		return;
	}
}