#include "JKRThread.h"

#include <cstdio>
#include <cstdlib>

#include "JKRExpHeap.h"

JSUPtrList JKRThread::sThreadList;

void *JKRThread::start(void *up) {
	//printf("%p\n", reinterpret_cast<JKRThread*>(up));
	return ((JKRThread *)up)->run();
}

void *JKRThread::run() {
	return nullptr;
}

JKRThread::JKRThread(ulong param_1, int msgcount, int priority) : JKRDisposer(), threadlink(this) {
	JKRHeap *pJVar1;
	u64 uVar2;
	os::OSThread *pOVar3;
	os::OSMessage *ppvVar4;

	pJVar1 = JKRHeap::findFromRoot(this);
	this->heap = pJVar1;
	if (!this->heap) {
		this->heap = JKRHeap::sSystemHeap;
	}
	this->stacksize = param_1 & 0xffffffe0;
	uVar2 = (u64)JKRHeap::alloc(this->stacksize, 0x20, this->heap);
	this->stackbase = (void *)uVar2;
	pOVar3 = (os::OSThread *)JKRHeap::alloc(sizeof(os::OSThread), 0x20, this->heap);
	this->thread = pOVar3;
	os::OSCreateThread(this->thread, JKRThread::start, this, (void*)((intptr_t)this->stackbase + this->stacksize), this->stacksize, priority, 1);
	this->msgcount = msgcount;
	ppvVar4 = (os::OSMessage *)JKRHeap::alloc(this->msgcount * sizeof(os::OSMessage), 0, this->heap);
	this->msgarray = ppvVar4;
	os::OSInitMessageQueue(&this->msgqueue, this->msgarray, this->msgcount);
	sThreadList.append(&this->threadlink);
	this->newheap = 0;
	this->field10_0x64 = 0;
}

JKRThread::JKRThread(os::OSThread *param_1, int param_2) : JKRDisposer(), threadlink(this) {
	os::OSMessage *ppvVar1;

	this->heap = (JKRHeap *)0x0;
	this->thread = param_1;
	// TODO: fix
	//this->stacksize = param_1->field748_0x308 - param_1->field747_0x304;
	//this->stackbase = param_1->field747_0x304;
	this->msgcount = param_2;
	this->msgarray = (os::OSMessage *)JKRHeap::sSystemHeap->alloc(this->msgcount * sizeof(os::OSMessage), 4);
	os::OSInitMessageQueue(&this->msgqueue, this->msgarray, this->msgcount);
	sThreadList.append(&this->threadlink);
	this->newheap = 0;
	this->field10_0x64 = 0;
	return;
}

JKRThread::~JKRThread() {
	sThreadList.remove(&this->threadlink);
	if (this->heap) {
		if (!os::OSIsThreadTerminated(this->thread)) {
			os::OSDetachThread(this->thread);
			os::OSCancelThread(this->thread);
		}
		JKRHeap::free((void *)this->stackbase, this->heap);
		JKRHeap::free(this->thread, this->heap);
	}
	JKRHeap::free(this->msgarray, (JKRHeap *)0x0);
}