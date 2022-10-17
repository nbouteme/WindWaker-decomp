#include <dolphin/dvd.h>
#include <dolphin/os.h>
#include <talloc.h>
#include <ucontext.h>

#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#include <valgrind/valgrind.h>

int countLeadingZeros(int a) {
	return __builtin_clz(a);
}

namespace os {

	void DefaultSwitchThreadCallback(OSThread *, OSThread *) {
		return;
	}

	OSThread *SelectThread(int param_1);
	void __OSUnlockAllMutex(OSThread *param_1);
	u32 __OSBusClock = 162000000;
	u32 __OSFpscrEnableBits;

	// EOSBaseThread *currentbase;
	OSThreadQueue RunQueue[32];

	int RunQueueHint;
	int RunQueueBits;
	// wind waker steals all the available RAM to use its own allocators on it,
	// so we don't need to implement the sdk arena allocator
	void *__arenalow = nullptr;

	using TCCB = void(OSThread *, OSThread *);
	TCCB *SwitchThreadCallback = DefaultSwitchThreadCallback;

	OSThread DefaultThread;

	OSThreadQueue activequeue;
	OSContext IdleContext;

	OSContext *currentctx;
	OSThread *currentbase;

	char *__strtable;
	int Reschedule;

	ucontext_t endthread;

	// I can't let you do that, dave...
	bool OSEnableInterrupts() {
		return 0;
	}

	bool OSDisableInterrupts() {
		return 0;
	}

	bool OSRestoreInterrupts(bool) {
		return 0;
	}

	void OSClearStack(u8 c) {
	}

	u32 OSGetSoundMode() {
		return 1;
	}

	void OSExitThread(void *retcode);
	u8 exitstack[4096];

	ucontext_t endthreadctx;

	void __OSThreadInit(void) {
		OSThreadQueue *pOVar1;
		int iVar2;

		DefaultThread.state = OS_THREAD_STATE_RUNNING;
		DefaultThread.attr = OS_THREAD_ATTR_DETACH;	 // Detached
		DefaultThread.base = 0x10;
		DefaultThread.priority = 0x10;	// 16
		DefaultThread.suspend = 0;
		DefaultThread.val = (void *)~0ul;
		DefaultThread.mutex = nullptr;
		OSInitThreadQueue(&DefaultThread.queueJoin);
		DefaultThread.queueMutex.tail = nullptr;
		DefaultThread.queueMutex.head = nullptr;
		OSClearContext(&DefaultThread.context);
		// currentbase = &base;
		OSSetCurrentContext(&DefaultThread.context);
		DefaultThread.stackBase = nullptr;
		DefaultThread.error = 0xDEADBABE;
		(*SwitchThreadCallback)(0, &DefaultThread);
		currentbase = &DefaultThread;
		OSClearStack(0);
		RunQueueBits = 0;
		iVar2 = 0;
		RunQueueHint = 0;
		pOVar1 = RunQueue;
		do {
			OSInitThreadQueue(pOVar1);
			iVar2 = iVar2 + 1;
			pOVar1 = pOVar1 + 1;
		} while (iVar2 < 0x20);
		OSInitThreadQueue(&activequeue);
		if (activequeue.tail == nullptr) {
			activequeue.head = &DefaultThread;
		} else {
			((activequeue.tail)->linkActive).next = &DefaultThread;
		}
		DefaultThread.linkActive.prev = activequeue.tail;
		DefaultThread.linkActive.next = nullptr;
		activequeue.tail = &DefaultThread;
		OSClearContext(&IdleContext);
		getcontext(&endthreadctx);
		endthreadctx.uc_stack = {(void *)exitstack, 0, 4096};
		makecontext(&endthreadctx, (void (*)())OSExitThread, 0);
		Reschedule = 0;
		// when a thread dies
		// getcontext(&endthread);
		// printf("Getting context from %p without stack restore\n", &endthread);
		// printf("Setting stack for %p\n", &endthread);
		// endthread.uc_stack = {(void *)exitstack, 0, 4096};
		//
		// makecontext(&endthread, (void (*)())OSExitThread, 0);
	}

	void OSInitThreadQueue(OSThreadQueue *param_1) {
		param_1->tail = (OSThread *)0x0;
		param_1->head = (OSThread *)0x0;
	}

	void OSExitThread(void *retcode) {
		OSThread *pOVar1;
		OSThread *pOVar2;
		bool bVar3;
		OSThread *pOVar4;
		OSThread *pOVar5;

		bVar3 = (bool)OSDisableInterrupts();
		pOVar1 = OSGetCurrentThread();
		OSClearContext(&pOVar1->context);
		if ((pOVar1->attr & OS_THREAD_ATTR_DETACH) == 0) {
			pOVar1->state = OS_THREAD_STATE_MORIBUND;
			pOVar1->val = retcode;
		} else {
			pOVar4 = (pOVar1->linkActive).next;
			pOVar5 = (pOVar1->linkActive).prev;
			pOVar2 = pOVar5;
			if (pOVar4) {
				(pOVar4->linkActive).prev = pOVar5;
				pOVar2 = activequeue.tail;
			}
			activequeue.tail = pOVar2;
			if (pOVar5) {
				(pOVar5->linkActive).next = pOVar4;
				pOVar4 = activequeue.head;
			}
			activequeue.head = pOVar4;
			pOVar1->state = 0;
		}
		__OSUnlockAllMutex(pOVar1);
		OSWakeupThread(&pOVar1->queueJoin);
		RunQueueHint = 1;
		SelectThread(0);
		OSRestoreInterrupts(bVar3);
	}

	void OSResetSystem(int, uint, bool) {
		puts("RESET SYSTEM");
		abort();
	}

	u32 OSGetConsoleSimulatedMemSize() {
		return 24 * 1024 * 1024;
	}

	u32 OSGetResetCode() {
		return 0;
	}

	bool OSGetResetSwitchState() {
		return false;
	}

	void OSProtectRange(uint, void *, uint, uint) {
		// used only to make everything rw, so ignore
	}

	void *OSInitAlloc(void *a, void *b, int n) {
		return a;
	}

	void *OSAllocFromArenaLo(uint s, uint a) {
		return malloc(s);  // shouldn't matter
	}

	void DCFlushRange(void *, uint) {
	}

	void DCInvalidateRange(void *, uint) {
	}

	void DCStoreRangeNoSync(void *, uint) {
	}

	void DCStoreRange(void *, uint) {
	}

	void LCDisable() {}

	void *OSGetArenaLo() {
		if (!__arenalow)
			__arenalow = calloc(1, OSGetConsoleSimulatedMemSize());
		return __arenalow;
	}

	void *OSGetArenaHI() {
		return __arenalow + OSGetConsoleSimulatedMemSize();
	}

	// the game use these only to signal it's leaving nothing, but we can just do nothing, probably
	void OSSetArenaLo(void *) {
	}

	void OSSetArenaHI(void *) {
	}

	void OSSetStringTable(void const *a) {
		__strtable = (char *)a;
	}

	int OSEnableScheduler(void) {
		int iVar1;

		auto c = OSDisableInterrupts();
		iVar1 = Reschedule;
		Reschedule = Reschedule + -1;
		OSRestoreInterrupts(c);
		return iVar1;
	}

	int OSDisableScheduler(void) {
		int iVar1;

		auto c = OSDisableInterrupts();
		iVar1 = Reschedule;
		Reschedule = Reschedule + 1;
		OSRestoreInterrupts(c);
		return iVar1;
	}

	void OSYieldThread(void) {
		bool uVar1;

		uVar1 = OSDisableInterrupts();
		SelectThread(1);
		OSRestoreInterrupts(uVar1);
	}

	void OSInitMutex(OSMutex *mtx) {
		OSInitThreadQueue(&mtx->queue);
		mtx->thread = nullptr;
		mtx->count = 0;
	}

	void UnsetRun(OSThread *param_1) {
		OSThread *pOVar1;
		OSThreadQueue *pOVar2;
		OSThread *pOVar3;

		pOVar1 = (param_1->link).next;
		pOVar2 = param_1->queue;
		pOVar3 = (param_1->link).prev;
		if (pOVar1 == nullptr) {
			pOVar2->tail = pOVar3;
		} else {
			(pOVar1->link).prev = pOVar3;
		}
		if (pOVar3 == nullptr) {
			pOVar2->head = pOVar1;
		} else {
			(pOVar3->link).next = pOVar1;
		}
		if (pOVar2->head == nullptr) {
			RunQueueBits = RunQueueBits & ~(1 << 0x1f - param_1->priority);
		}
		param_1->queue = nullptr;
		return;
	}

	TCCB *OSSetSwitchThreadCallback(TCCB *n) {
		TCCB *old = SwitchThreadCallback;
		if (!n)
			n = DefaultSwitchThreadCallback;
		if (n)
			SwitchThreadCallback = n;
		return old;
	}

	void *__arenahi;
	void OSSetArenaHi(void *a) {
		__arenahi = a;
	}

	void *OSGetArenaHi() {
		return (void *)((char *)__arenalow + OSGetConsoleSimulatedMemSize());
	}

	void OSTicksToCalendarTime(OSTime param_1, OSCalendarTime *param_3) {
		param_3->hour = 0;
		param_3->mday = 0;
		param_3->year = 2004;
		param_3->yday = 34;
	}

	bool OSIsThreadTerminated(OSThread *param_1) {
		bool bVar1;

		bVar1 = true;
		if ((param_1->state != OS_THREAD_STATE_MORIBUND) && (param_1->state != 0)) {
			bVar1 = false;
		}
		if (bVar1) {
			return 1;
		}
		return 0;
	}

	long OSCheckActiveThreads() {
		// TODO: return the number of threads in the active thread queue
		return 0;
	}

	OSContext *OSGetCurrentContext() {
		// memcpy(currentbase->thx.context.gqr, &addr, sizeof(addr));
		return currentctx;
	}

	void OSSetCurrentContext(OSContext *ctx) {
		currentctx = ctx;
	}

	void OSLoadContext(OSContext *ctx) {
		setcontext(&ctx->ctx);
	}

	OSThread *SelectThread(int param_1) {
		OSThread *pOVar1;
		OSThread *pOVar2;
		int iVar3;
		OSThreadQueue *pOVar4;

		if (Reschedule < 1) {
			pOVar2 = (OSThread *)OSGetCurrentContext();
			pOVar1 = OSGetCurrentThread();
			if (pOVar2 == OSGetCurrentThread()) {
				if (OSGetCurrentThread()) {
					if (OSGetCurrentThread()->state == OS_THREAD_STATE_RUNNING) {
						if ((param_1 == 0) &&
							(iVar3 = countLeadingZeros(RunQueueBits), OSGetCurrentThread()->priority <= iVar3)) {
							return nullptr;
						}
						OSGetCurrentThread()->state = OS_THREAD_STATE_READY;
						pOVar1->queue = RunQueue + pOVar1->priority;
						pOVar2 = pOVar1->queue->tail;
						if (pOVar2 == nullptr) {
							pOVar1->queue->head = pOVar1;
						} else {
							(pOVar2->link).next = pOVar1;
						}
						(pOVar1->link).prev = pOVar2;
						(pOVar1->link).next = nullptr;
						pOVar1->queue->tail = pOVar1;
						RunQueueBits = RunQueueBits | 1 << 0x1f - pOVar1->priority;
						RunQueueHint = 1;
					}
					if (((pOVar1->context.state & OS_CONTEXT_STATE_EXC) == 0) &&
						(iVar3 = OSSaveContext(&pOVar1->context), iVar3 != 0)) {
						return nullptr;
					}
				}
				(*SwitchThreadCallback)(OSGetCurrentThread(), 0);

				currentbase = nullptr;
				if (RunQueueBits == 0) {
					OSSetCurrentContext(&IdleContext);
					do {
						OSEnableInterrupts();
						do {
							// nothing to do
						} while (RunQueueBits == 0);
						OSDisableInterrupts();
					} while (RunQueueBits == 0);
					OSClearContext(&IdleContext);
				}
				RunQueueHint = 0;
				iVar3 = countLeadingZeros(RunQueueBits);
				pOVar4 = RunQueue + iVar3;
				pOVar1 = pOVar4->head;
				pOVar2 = (pOVar1->link).next;
				if (pOVar2 == nullptr) {
					RunQueue[iVar3].tail = nullptr;
				} else {
					(pOVar2->link).prev = nullptr;
				}
				pOVar4->head = pOVar2;
				if (pOVar4->head == nullptr) {
					RunQueueBits = RunQueueBits & ~(1 << 0x1f - iVar3);
				}
				pOVar1->queue = nullptr;
				pOVar1->state = OS_THREAD_STATE_RUNNING;
				//(*SwitchThreadCallback)(OSGetCurrentThread(), pOVar1);
				(*SwitchThreadCallback)(currentbase, pOVar1);
				currentbase = pOVar1;
				OSSetCurrentContext(&pOVar1->context);
				OSLoadContext(&pOVar1->context);
			} else {
				pOVar1 = nullptr;
			}
		} else {
			pOVar1 = nullptr;
		}
		return pOVar1;
	}

	u32 OSSaveContext(OSContext *ctx) {
		getcontext(&ctx->ctx);
		return 0;
	}

	OSThread *SetEffectivePriority(OSThread *param_1, int param_2) {
		ushort uVar1;
		OSThread *pOVar2;
		OSThreadQueue *pOVar3;
		OSThread *pOVar4;

		uVar1 = param_1->state;
		if (uVar1 != 3) {
			if (uVar1 < 3) {
				if (uVar1 == 1) {
					UnsetRun(param_1);
					param_1->priority = param_2;
					param_1->queue = (OSThreadQueue *)(&RunQueue + param_1->priority * 2);
					pOVar2 = param_1->queue->tail;
					if (pOVar2 == nullptr) {
						param_1->queue->head = param_1;
					} else {
						(pOVar2->link).next = param_1;
					}
					(param_1->link).prev = pOVar2;
					(param_1->link).next = nullptr;
					param_1->queue->tail = param_1;
					RunQueueBits = RunQueueBits | 1 << 0x1f - param_1->priority;
					RunQueueHint = 1;
				} else if (uVar1 != 0) {
					RunQueueHint = 1;
					param_1->priority = param_2;
				}
			} else if (uVar1 < 5) {
				pOVar2 = (param_1->link).next;
				pOVar4 = (param_1->link).prev;
				if (pOVar2 == nullptr) {
					param_1->queue->tail = pOVar4;
				} else {
					(pOVar2->link).prev = pOVar4;
				}
				if (pOVar4 == nullptr) {
					param_1->queue->head = pOVar2;
				} else {
					(pOVar4->link).next = pOVar2;
				}
				param_1->priority = param_2;
				pOVar3 = param_1->queue;
				for (pOVar2 = pOVar3->head;
					 (pOVar2 && (pOVar2->priority <= param_1->priority));
					 pOVar2 = (pOVar2->link).next) {
				}
				if (pOVar2 == nullptr) {
					pOVar2 = pOVar3->tail;
					if (pOVar2 == nullptr) {
						pOVar3->head = param_1;
					} else {
						(pOVar2->link).next = param_1;
					}
					(param_1->link).prev = pOVar2;
					(param_1->link).next = nullptr;
					param_1->queue->tail = param_1;
				} else {
					(param_1->link).next = pOVar2;
					pOVar4 = (pOVar2->link).prev;
					(pOVar2->link).prev = param_1;
					(param_1->link).prev = pOVar4;
					if (pOVar4 == nullptr) {
						param_1->queue->head = param_1;
					} else {
						(pOVar4->link).next = param_1;
					}
				}
				if (param_1->mutex) {
					return param_1->mutex->thread;
				}
			}
		}
		return nullptr;
	}

	void __OSPromoteThread(OSThread *param_1, int param_2) {
		while (true) {
			if (0 < (int)param_1->suspend) {
				return;
			}
			if (param_1->priority <= param_2)
				break;
			param_1 = SetEffectivePriority(param_1, param_2);
			if (param_1 == nullptr) {
				return;
			}
		}
		return;
	}

	void OSLockMutex(OSMutex *param_1) {
		undefined4 uVar1;
		OSThread *currentThread;
		OSMutex *pOVar2;

		uVar1 = OSDisableInterrupts();
		currentThread = OSGetCurrentThread();
		do {
			if (param_1->thread == nullptr) {
				param_1->thread = currentThread;
				param_1->count = param_1->count + 1;
				pOVar2 = (currentThread->queueMutex).tail;
				if (pOVar2 == nullptr) {
					(currentThread->queueMutex).head = param_1;
				} else {
					(pOVar2->link).next = param_1;
				}
				(param_1->link).prev = pOVar2;
				(param_1->link).next = nullptr;
				(currentThread->queueMutex).tail = param_1;
			LAB_80305f48:
				OSRestoreInterrupts((bool)uVar1);
				return;
			}
			if (param_1->thread == currentThread) {
				param_1->count = param_1->count + 1;
				goto LAB_80305f48;
			}
			currentThread->mutex = param_1;
			__OSPromoteThread(param_1->thread, currentThread->priority);
			OSSleepThread(&param_1->queue);
			currentThread->mutex = nullptr;
		} while (true);
	}

	bool OSTryLockMutex(OSMutex *param_1) {
		undefined4 uVar1;
		OSThread *pOVar2;
		OSMutex *pOVar3;
		undefined4 uVar4;

		uVar1 = OSDisableInterrupts();
		pOVar2 = OSGetCurrentThread();
		if (param_1->thread == nullptr) {
			param_1->thread = pOVar2;
			param_1->count = param_1->count + 1;
			pOVar3 = (pOVar2->queueMutex).tail;
			if (pOVar3 == nullptr) {
				(pOVar2->queueMutex).head = param_1;
			} else {
				(pOVar3->link).next = param_1;
			}
			(param_1->link).prev = pOVar3;
			uVar4 = 1;
			(param_1->link).next = nullptr;
			(pOVar2->queueMutex).tail = param_1;
		} else if (param_1->thread == pOVar2) {
			uVar4 = 1;
			param_1->count = param_1->count + 1;
		} else {
			uVar4 = 0;
		}
		OSRestoreInterrupts((bool)uVar1);
		return uVar4;
	}

	void OSFillFPUContext(OSContext *) {}

	void OSSleepThread(OSThreadQueue *param_1) {
		OSThread *pOVar1;
		undefined4 uVar2;
		OSThread *pOVar3;
		OSThread *pOVar4;

		uVar2 = OSDisableInterrupts();
		pOVar1 = OSGetCurrentThread();
		pOVar1->state = OS_THREAD_STATE_WAITING;
		pOVar1->queue = param_1;
		// find a thread with higher prio to run
		for (pOVar4 = param_1->head; (pOVar4 && (pOVar4->priority <= pOVar1->priority)); pOVar4 = (pOVar4->link).next) {
		}
		if (pOVar4 == nullptr) {
			pOVar4 = param_1->tail;
			if (pOVar4 == nullptr) {
				param_1->head = pOVar1;
			} else {
				(pOVar4->link).next = pOVar1;
			}
			(pOVar1->link).prev = pOVar4;
			(pOVar1->link).next = nullptr;
			param_1->tail = pOVar1;
		} else {
			(pOVar1->link).next = pOVar4;
			pOVar3 = (pOVar4->link).prev;
			(pOVar4->link).prev = pOVar1;
			(pOVar1->link).prev = pOVar3;
			if (pOVar3 == nullptr) {
				param_1->head = pOVar1;
			} else {
				(pOVar3->link).next = pOVar1;
			}
		}
		RunQueueHint = 1;
		SelectThread(0);  // reschedule
		OSRestoreInterrupts((bool)uVar2);
		return;
	}

	int __OSGetEffectivePriority(OSThread *param_1) {
		int iVar1;
		OSThread *pOVar2;
		int iVar3;
		OSMutex *pOVar4;

		iVar3 = param_1->base;
		for (pOVar4 = (param_1->queueMutex).head; pOVar4; pOVar4 = (pOVar4->link).next) {
			pOVar2 = (pOVar4->queue).head;
			if ((pOVar2) && (iVar1 = pOVar2->priority, iVar1 < iVar3)) {
				iVar3 = iVar1;
			}
		}
		return iVar3;
	}

	void OSUnlockMutex(OSMutex *param_1) {
		int iVar1;
		bool bVar4;
		OSThread *pOVar2;
		OSMutex *pOVar3;
		OSMutex *pOVar5;

		bVar4 = (bool)OSDisableInterrupts();
		pOVar2 = OSGetCurrentThread();
		if (param_1->thread == pOVar2) {
			iVar1 = param_1->count + -1;
			param_1->count = iVar1;
			if (iVar1 == 0) {
				pOVar3 = (param_1->link).next;
				pOVar5 = (param_1->link).prev;
				if (pOVar3 == nullptr) {
					(pOVar2->queueMutex).tail = pOVar5;
				} else {
					(pOVar3->link).prev = pOVar5;
				}
				if (pOVar5 == nullptr) {
					(pOVar2->queueMutex).head = pOVar3;
				} else {
					(pOVar5->link).next = pOVar3;
				}
				param_1->thread = nullptr;
				if (pOVar2->priority < pOVar2->base) {
					iVar1 = __OSGetEffectivePriority(pOVar2);
					pOVar2->priority = iVar1;
				}
				OSWakeupThread(&param_1->queue);
			}
		}
		OSRestoreInterrupts(bVar4);
		return;
	}

	OSTime OSGetTime() {
		const time_t jan2k = 946681200;
		time_t now;

		time(&now);

		double secondssincejan2k = difftime(now, jan2k);
		return OSSecondsToTicks((u64)secondssincejan2k);
	}

	OSThread *OSGetCurrentThread() {
		return currentbase;
	}

	OSTick OSGetTick() {
		return (u32)OSGetTime();
	}

	struct sigevent sev = {
		.sigev_signo = SIGALRM,
		.sigev_notify = SIGEV_SIGNAL,
	};
	struct sigaction sa;
	static void alarmhandler(int sig, siginfo_t *inf, void *ptr) {
		auto alrm = (OSAlarm *)inf->si_value.sival_ptr;
		alrm->handler(alrm, 0);
	}

	void OSInitAlarm() {
		sa.sa_sigaction = alarmhandler;
		sa.sa_flags = SA_SIGINFO;
		sigaction(SIGALRM, &sa, 0);
	}

	void OSInit(void) {
		puts("Initializing OS module...");
		__OSThreadInit();
		OSInitAlarm();
		dvd::DVDInit();
	}

	u32 OSGetConsoleType() {
		return 0;
	}

	void OSInitMessageQueue(OSMessageQueue *param_1, OSMessage *param_2, int param_3) {
		OSInitThreadQueue(&param_1->queueSend);
		OSInitThreadQueue(&param_1->queueReceive);
		param_1->msgArray = param_2;
		param_1->msgCount = param_3;
		param_1->firstIndex = 0;
		param_1->usedCount = 0;
	}

	bool OSReceiveMessage(OSMessageQueue *param_1, OSMessage *param_2, int param_3) {
		bool uVar1;
		int iVar2;

		uVar1 = OSDisableInterrupts();
		while (true) {
			if (param_1->usedCount != 0) {
				if (param_2) {
					*param_2 = param_1->msgArray[param_1->firstIndex];
				}
				iVar2 = param_1->firstIndex + 1;
				param_1->firstIndex = iVar2 - (iVar2 / param_1->msgCount) * param_1->msgCount;
				param_1->usedCount = param_1->usedCount + -1;
				OSWakeupThread(&param_1->queueSend);
				OSRestoreInterrupts(uVar1);
				return 1;
			}
			if ((param_3 & 1) == 0)
				break;
			OSSleepThread(&param_1->queueReceive);
		}
		OSRestoreInterrupts(uVar1);
		return 0;
	}

	void OSWakeupThread(OSThreadQueue *param_1) {
		bool uVar1;
		OSThread *pOVar2;
		OSThread *uVar3;

		uVar1 = OSDisableInterrupts();
		while (uVar3 = param_1->head, uVar3) {
			pOVar2 = (uVar3->link).next;
			if (pOVar2 == nullptr) {
				param_1->tail = nullptr;
			} else {
				(pOVar2->link).prev = nullptr;
			}
			param_1->head = pOVar2;
			uVar3->state = OS_THREAD_STATE_READY;
			if ((int)uVar3->suspend < 1) {
				uVar3->queue = RunQueue + uVar3->priority;
				pOVar2 = uVar3->queue->tail;
				if (pOVar2 == nullptr) {
					uVar3->queue->head = uVar3;
				} else {
					(pOVar2->link).next = uVar3;
				}
				(uVar3->link).prev = pOVar2;
				(uVar3->link).next = nullptr;
				uVar3->queue->tail = uVar3;
				RunQueueBits = RunQueueBits | 1 << 0x1f - uVar3->priority;
				RunQueueHint = 1;
			}
		}
		if (RunQueueHint != 0) {
			SelectThread(0);
		}
		OSRestoreInterrupts(uVar1);
		return;
	}

	bool OSSendMessage(OSMessageQueue *param_1, OSMessage param_2, int param_3) {
		bool uVar1;
		int iVar2;
		int iVar3;

		uVar1 = OSDisableInterrupts();
		while (true) {
			iVar3 = param_1->msgCount;
			if (param_1->usedCount < iVar3) {
				iVar2 = param_1->firstIndex + param_1->usedCount;
				param_1->msgArray[iVar2 - (iVar2 / iVar3) * iVar3] = param_2;
				param_1->usedCount = param_1->usedCount + 1;
				OSWakeupThread(&param_1->queueReceive);
				OSRestoreInterrupts(uVar1);
				return 1;
			}
			if ((param_3 & 1) == 0)
				break;
			OSSleepThread(&param_1->queueSend);
		}
		OSRestoreInterrupts(uVar1);
		return 0;
	}

	void OSInitCond(OSCond *param_1) {
		OSInitThreadQueue(&param_1->queue);
	}

	void OSSignalCond(OSCond *param_1) {
		OSWakeupThread(&param_1->queue);
	}

	void OSWaitCond(OSCond *param_1, OSMutex *param_2) {
		bool bVar4;
		OSThread *pOVar1;
		OSMutex *pOVar2;
		int iVar3;
		OSMutex *pOVar5;
		s32 sVar6;

		bVar4 = (bool)OSDisableInterrupts();
		pOVar1 = OSGetCurrentThread();
		if (param_2->thread == pOVar1) {
			sVar6 = param_2->count;
			param_2->count = 0;
			pOVar2 = (param_2->link).next;
			pOVar5 = (param_2->link).prev;
			if (pOVar2 == nullptr) {
				(pOVar1->queueMutex).tail = pOVar5;
			} else {
				(pOVar2->link).prev = pOVar5;
			}
			if (pOVar5 == nullptr) {
				(pOVar1->queueMutex).head = pOVar2;
			} else {
				(pOVar5->link).next = pOVar2;
			}
			param_2->thread = nullptr;
			if (pOVar1->priority < pOVar1->base) {
				iVar3 = __OSGetEffectivePriority(pOVar1);
				pOVar1->priority = iVar3;
			}
			OSDisableScheduler();
			OSWakeupThread(&param_2->queue);
			OSEnableScheduler();
			OSSleepThread(&param_1->queue);
			OSLockMutex(param_2);
			param_2->count = sVar6;
		}
		OSRestoreInterrupts(bVar4);
	}

	void OSCreateAlarm(OSAlarm *param_1) {
		param_1->handler = nullptr;
		param_1->tag = 0;
	}

	void OSCancelAlarm(OSAlarm *alarm) {
		struct itimerspec sp;

		sp.it_value.tv_sec = 0;
		sp.it_value.tv_nsec = 0;
		sp.it_interval.tv_sec = 0;
		sp.it_interval.tv_nsec = 0;
		timer_settime(alarm->timer, 0, &sp, nullptr);
	}

	u32 __OSGetSystemTime() {
		return 0;  // TODO: return cpu clocks?
	}

	void InsertAlarm(OSAlarm *alarm, OSTime start, OSTime period, OSAlarmHandler handler) {
		sev.sigev_value.sival_ptr = alarm;
		alarm->handler = handler;
		int r = timer_create(CLOCK_REALTIME, &sev, &alarm->timer);
		struct itimerspec sp;

#define GCTICKSTOSECS(x) OSTicksToSeconds(x)
#define GCTICKSTONANO(x) (OSTicksToNanoseconds(x) - OSTicksToSeconds(x) * 1000000000)
		sp.it_value.tv_sec = GCTICKSTOSECS(start);
		sp.it_value.tv_nsec = GCTICKSTONANO(start);
		sp.it_interval.tv_sec = GCTICKSTOSECS(period);
		sp.it_interval.tv_nsec = GCTICKSTONANO(period);
		timer_settime(alarm->timer, 0, &sp, nullptr);
	}

	void OSSetAlarm(OSAlarm *param_1, OSTime param_2, OSAlarmHandler param_5) {
		long long lVar1;
		bool bVar2;
		long long lVar3;

		bVar2 = (bool)OSDisableInterrupts();
		param_1->period = 0;
		lVar3 = __OSGetSystemTime();
		InsertAlarm(param_1, param_2, param_2, param_5);
		OSRestoreInterrupts(bVar2);
	}

	void OSSetPeriodicAlarm(OSAlarm *param_1, OSTime param_2, OSTime param_3, OSAlarmHandler param_5) {
		long long lVar1;
		bool bVar2;
		long long lVar3;

		bVar2 = (bool)OSDisableInterrupts();
		param_1->period = 0;
		lVar3 = __OSGetSystemTime();
		InsertAlarm(param_1, param_2, param_3, param_5);
		OSRestoreInterrupts(bVar2);
	}

	OSErrorHandler OSSetErrorHandler(OSError error, OSErrorHandler handler) {
		return handler;
	}

	// TODO: not really implementable as meant to load PPC rels, can't even be linked in a 64 bits address space
	// but we're not there yet anyway
	bool OSLink(OSModuleInfo *, void *) { return false; }
	bool OSUnlink(OSModuleInfo *) { return false; }
	bool OSLinkFixed(OSModuleInfo *, void *) { return false; }

	void OSDetachThread(OSThread *param_1) {
		OSThread *pOVar1;
		bool bVar2;
		OSThread *pOVar3;
		OSThread *pOVar4;

		bVar2 = (bool)OSDisableInterrupts();
		param_1->attr |= OS_THREAD_ATTR_DETACH;
		if (param_1->state == OS_THREAD_STATE_MORIBUND) {
			pOVar3 = (param_1->linkActive).next;
			pOVar4 = (param_1->linkActive).prev;
			pOVar1 = pOVar4;
			if (pOVar3) {
				(pOVar3->linkActive).prev = pOVar4;
				pOVar1 = activequeue.tail;
			}
			activequeue.tail = pOVar1;
			if (pOVar4) {
				(pOVar4->linkActive).next = pOVar3;
				pOVar3 = activequeue.head;
			}
			activequeue.head = pOVar3;
			param_1->state = 0;
		}
		OSWakeupThread(param_1->queue);
		OSRestoreInterrupts(bVar2);
		return;
	}

	bool OSSetThreadPriority(OSThread *param_1, int param_2) {
		undefined4 uVar1;
		bool bVar3;
		int iVar2;

		if ((param_2 < 0) || (0x1f < param_2)) {
			uVar1 = 0;
		} else {
			bVar3 = (bool)OSDisableInterrupts();
			if (param_1->base != param_2) {
				param_1->base = param_2;
				while ((int)param_1->suspend < 1) {
					iVar2 = __OSGetEffectivePriority(param_1);
					if ((param_1->priority == iVar2) ||
						(param_1 = (OSThread *)SetEffectivePriority(param_1, iVar2),
						 param_1 == nullptr))
						break;
				}
				if (RunQueueHint != 0) {
					SelectThread(0);
				}
			}
			OSRestoreInterrupts(bVar3);
			uVar1 = 1;
		}
		return uVar1;
	}

	void __OSUnlockAllMutex(OSThread *param_1) {
		OSMutex *pOVar1;
		OSMutex *pOVar2;

		while (pOVar1 = (param_1->queueMutex).head, pOVar1) {
			pOVar2 = (pOVar1->link).next;
			if (pOVar2 == nullptr) {
				(param_1->queueMutex).tail = nullptr;
			} else {
				(pOVar2->link).prev = nullptr;
			}
			(param_1->queueMutex).head = pOVar2;
			pOVar1->count = 0;
			pOVar1->thread = nullptr;
			OSWakeupThread(&pOVar1->queue);
		}
		return;
	}

	void OSCancelThread(OSThread *param_1) {
		ushort uVar1;
		bool bVar3;
		int iVar2;
		OSThread *pOVar4;
		OSThread *pOVar5;
		OSThread *pOVar6;

		bVar3 = (bool)OSDisableInterrupts();
		uVar1 = param_1->state;
		if (uVar1 == 3) {
		LAB_80308410:
			OSRestoreInterrupts(bVar3);
		} else {
			if (uVar1 < 3) {
				if (uVar1 == 1) {
					if ((int)param_1->suspend < 1) {
						UnsetRun(param_1);
					}
				} else {
					if (uVar1 == 0)
						goto LAB_80308410;
					RunQueueHint = 1;
				}
			} else {
				if (4 < uVar1)
					goto LAB_80308410;
				pOVar4 = (param_1->link).next;
				pOVar5 = (param_1->link).prev;
				if (pOVar4 == nullptr) {
					param_1->queue->tail = pOVar5;
				} else {
					(pOVar4->link).prev = pOVar5;
				}
				if (pOVar5 == nullptr) {
					param_1->queue->head = pOVar4;
				} else {
					(pOVar5->link).next = pOVar4;
				}
				param_1->queue = nullptr;
				if (((int)param_1->suspend < 1) && (param_1->mutex)) {
					pOVar4 = param_1->mutex->thread;
					do {
						if ((0 < (int)pOVar4->suspend) ||
							(iVar2 = __OSGetEffectivePriority(pOVar4), pOVar4->priority == iVar2))
							break;
						pOVar4 = (OSThread *)SetEffectivePriority(pOVar4, iVar2);
					} while (pOVar4);
				}
			}
			OSClearContext(&param_1->context);
			if ((param_1->attr & OS_THREAD_ATTR_DETACH) == 0) {
				param_1->state = OS_THREAD_STATE_MORIBUND;
			} else {
				pOVar4 = (param_1->linkActive).next;
				pOVar6 = (param_1->linkActive).prev;
				pOVar5 = pOVar6;
				if (pOVar4) {
					(pOVar4->linkActive).prev = pOVar6;
					pOVar5 = activequeue.tail;
				}
				activequeue.tail = pOVar5;
				if (pOVar6) {
					(pOVar6->linkActive).next = pOVar4;
					pOVar4 = activequeue.head;
				}
				activequeue.head = pOVar4;
				param_1->state = 0;
			}
			__OSUnlockAllMutex(param_1);
			OSWakeupThread(param_1->queue);
			if (RunQueueHint != 0) {
				SelectThread(0);
			}
			OSRestoreInterrupts(bVar3);
		}
		return;
	}

	int OSGetThreadPriority(OSThread *param_1) {
		return param_1->base;
	}

	int OSSuspendThread(OSThread *param_1) {
		ushort uVar1;
		bool bVar3;
		int iVar2;
		int iVar4;
		OSThread *pOVar5;
		OSThread *pOVar6;

		bVar3 = (bool)OSDisableInterrupts();
		iVar4 = param_1->suspend;
		param_1->suspend = iVar4 + 1;
		if (iVar4 == 0) {
			uVar1 = param_1->state;
			if (uVar1 != 3) {
				if (uVar1 < 3) {
					if (uVar1 == 1) {
						UnsetRun(param_1);
					} else if (uVar1 != 0) {
						RunQueueHint = 1;
						param_1->state = 1;
					}
				} else if (uVar1 < 5) {
					pOVar5 = (param_1->link).next;
					pOVar6 = (param_1->link).prev;
					if (pOVar5 == nullptr) {
						param_1->queue->tail = pOVar6;
					} else {
						(pOVar5->link).prev = pOVar6;
					}
					if (pOVar6 == nullptr) {
						param_1->queue->head = pOVar5;
					} else {
						(pOVar6->link).next = pOVar5;
					}
					param_1->priority = 0x20;
					pOVar5 = param_1->queue->tail;
					if (pOVar5 == nullptr) {
						param_1->queue->head = param_1;
					} else {
						(pOVar5->link).next = param_1;
					}
					(param_1->link).prev = pOVar5;
					(param_1->link).next = nullptr;
					param_1->queue->tail = param_1;
					if (param_1->mutex) {
						pOVar5 = param_1->mutex->thread;
						do {
							if ((0 < (int)pOVar5->suspend) ||
								(iVar2 = __OSGetEffectivePriority(pOVar5), pOVar5->priority == iVar2))
								break;
							pOVar5 = (OSThread *)SetEffectivePriority(pOVar5, iVar2);
						} while (pOVar5);
					}
				}
			}
			if (RunQueueHint != 0) {
				SelectThread(0);
			}
		}
		OSRestoreInterrupts(bVar3);
		return iVar4;
	}

	int OSResumeThread(OSThread *param_1) {
		//printf("Resuming thread at %p\n", param_1);
		ushort uVar1;
		int iVar2;
		bool bVar5;
		OSMutex *pOVar3;
		OSThread *pOVar4;
		int iVar6;
		int iVar7;
		OSThreadQueue *pOVar8;
		OSThread *pOVar9;

		bVar5 = (bool)OSDisableInterrupts();
		iVar6 = param_1->suspend;
		param_1->suspend = iVar6 + -1;
		if ((int)param_1->suspend < 0) {
			param_1->suspend = 0;
		} else if (param_1->suspend == 0) {
			uVar1 = param_1->state;
			if (uVar1 == OS_THREAD_STATE_WAITING) {
				pOVar4 = (param_1->link).next;
				pOVar9 = (param_1->link).prev;
				if (pOVar4 == nullptr) {
					param_1->queue->tail = pOVar9;
				} else {
					(pOVar4->link).prev = pOVar9;
				}
				if (pOVar9 == nullptr) {
					param_1->queue->head = pOVar4;
				} else {
					(pOVar9->link).next = pOVar4;
				}
				iVar2 = param_1->base;
				for (pOVar3 = (param_1->queueMutex).head; pOVar3;
					 pOVar3 = (pOVar3->link).next) {
					pOVar4 = (pOVar3->queue).head;
					if ((pOVar4) && (iVar7 = pOVar4->priority, iVar7 < iVar2)) {
						iVar2 = iVar7;
					}
				}
				param_1->priority = iVar2;
				pOVar8 = param_1->queue;
				for (pOVar4 = pOVar8->head;
					 (pOVar4 && (pOVar4->priority <= param_1->priority));
					 pOVar4 = (pOVar4->link).next) {
				}
				if (pOVar4 == nullptr) {
					pOVar4 = pOVar8->tail;
					if (pOVar4 == nullptr) {
						pOVar8->head = param_1;
					} else {
						(pOVar4->link).next = param_1;
					}
					(param_1->link).prev = pOVar4;
					(param_1->link).next = nullptr;
					param_1->queue->tail = param_1;
				} else {
					(param_1->link).next = pOVar4;
					pOVar9 = (pOVar4->link).prev;
					(pOVar4->link).prev = param_1;
					(param_1->link).prev = pOVar9;
					if (pOVar9 == nullptr) {
						param_1->queue->head = param_1;
					} else {
						(pOVar9->link).next = param_1;
					}
				}
				if (param_1->mutex) {
					pOVar4 = param_1->mutex->thread;
					do {
						if ((0 < (int)pOVar4->suspend) ||
							(iVar2 = __OSGetEffectivePriority(pOVar4), pOVar4->priority == iVar2))
							break;
						pOVar4 = (OSThread *)SetEffectivePriority(pOVar4, iVar2);
					} while (pOVar4);
				}
			} else if ((uVar1 < 4) && (uVar1 == 1)) {
				iVar2 = param_1->base;
				for (pOVar3 = (param_1->queueMutex).head; pOVar3;
					 pOVar3 = (pOVar3->link).next) {
					pOVar4 = (pOVar3->queue).head;
					if ((pOVar4) && (iVar7 = pOVar4->priority, iVar7 < iVar2)) {
						iVar2 = iVar7;
					}
				}
				param_1->priority = iVar2;
				param_1->queue = RunQueue + param_1->priority;
				pOVar4 = param_1->queue->tail;
				if (pOVar4 == nullptr) {
					param_1->queue->head = param_1;
				} else {
					(pOVar4->link).next = param_1;
				}
				(param_1->link).prev = pOVar4;
				(param_1->link).next = nullptr;
				param_1->queue->tail = param_1;
				RunQueueBits = RunQueueBits | 1 << 0x1f - param_1->priority;
				RunQueueHint = 1;
			}
			if (RunQueueHint != 0) {
				SelectThread(0);
			}
		}
		OSRestoreInterrupts(bVar5);
		return iVar6;
	}

	void OSClearContext(OSContext *param_1) {
		param_1->mode = 0;
		param_1->state = 0;
	}

	void OSInitContext(OSContext *param_1, void *param_2, void *param_3, u64 ss, void *up) {
		// The stack pointer points to the high address, but ucontext needs the low address
		ss -= 128;
		//printf("Stack BEGIN-END %p-%p\n", param_3 - ss, param_3);
		param_1->ctx.uc_stack = {(void *)((char *)param_3 - ss), 0, ss};
		VALGRIND_STACK_REGISTER((param_3 - ss), param_3);

		// man 3 makecontext
		/*Nevertheless, starting with version 2.8, glibc makes some changes
       to makecontext(), to permit this on some 64-bit architectures
       (e.g., x86-64).*/
		makecontext(&param_1->ctx, (void (*)())param_2, 1, up);

		OSClearContext(param_1);
	}

	bool OSCreateThread(OSThread *param_1, void *(*param_2)(void *), void *param_3, void *param_4, uint param_5,
						OSPriority param_6, ushort param_7) {
		//printf("Creating thread at %p\n", param_1);
		u64 uVar1;
		undefined4 uVar2;
		bool bVar3;
		OSThread *pOVar4;
		int iVar5;

		if ((param_6 < 0) || (0x1f < param_6)) {
			uVar2 = 0;
		} else {
			param_1->state = OS_THREAD_STATE_READY;
			uVar1 = (u64)param_4 & ((0UL) - 8);
			param_1->attr = param_7 & OS_THREAD_ATTR_DETACH;
			param_1->base = param_6;
			param_1->priority = param_6;
			param_1->suspend = 1;
			param_1->val = (void *)-1;
			param_1->mutex = nullptr;
			param_1->queueJoin.tail = nullptr;
			param_1->queueJoin.head = nullptr;
			(param_1->queueMutex).tail = nullptr;
			(param_1->queueMutex).head = nullptr;

			//*(undefined4 *)(uVar1 - 8) = 0;
			//*(undefined4 *)(uVar1 - 4) = 0;
			getcontext(&param_1->context.ctx);
			param_1->context.ctx.uc_link = &endthreadctx;
			OSInitContext(&param_1->context, (void *)param_2, (void *)uVar1, param_5, param_3);
			u64 p = (u64)param_3;

			//(param_1->context).lr = OSExitThread;	// where to return
			//(param_1->context).gpr[3] = param_3;		// first arg
			param_1->stackBase = (u8 *)param_4;
			param_1->error = 0;
			param_1->specific[0] = nullptr;
			param_1->specific[1] = nullptr;
			// param_1[1].context.gpr[0] = 0;
			bVar3 = (bool)OSDisableInterrupts();
			pOVar4 = param_1;
			if (activequeue.tail) {
				((activequeue.tail)->linkActive).next = param_1;
				pOVar4 = activequeue.head;
			}
			activequeue.head = pOVar4;
			(param_1->linkActive).prev = activequeue.tail;
			(param_1->linkActive).next = nullptr;
			activequeue.tail = param_1;
			OSRestoreInterrupts(bVar3);
			uVar2 = 1;
		}
		return uVar2;
	}

	bool OSJoinThread(OSThread *param_1, void **param_2) {
		bool bVar1;
		OSThread *pOVar2;
		bool bVar4;
		undefined4 uVar3;
		OSThread *pOVar5;
		OSThread *pOVar6;

		bVar4 = (bool)OSDisableInterrupts();
		if ((((param_1->attr & OS_THREAD_ATTR_DETACH) == 0) && (param_1->state != OS_THREAD_STATE_MORIBUND)) &&
			((param_1->queueJoin).head == (OSThread *)0x0)) {
			OSSleepThread(&param_1->queueJoin);
			pOVar5 = activequeue.head;
			if (param_1->state == 0) {
				bVar1 = false;
			} else {
				for (; pOVar5; pOVar5 = (pOVar5->linkActive).next) {
					if (param_1 == pOVar5) {
						bVar1 = true;
						goto LAB_80308558;
					}
				}
				bVar1 = false;
			}
		LAB_80308558:
			if (!bVar1) {
				OSRestoreInterrupts(bVar4);
				return 0;
			}
		}
		if (param_1->state == OS_THREAD_STATE_MORIBUND) {
			if (param_2) {
				*param_2 = param_1->val;
			}
			pOVar5 = (param_1->linkActive).next;
			pOVar6 = (param_1->linkActive).prev;
			pOVar2 = pOVar6;
			if (pOVar5) {
				(pOVar5->linkActive).prev = pOVar6;
				pOVar2 = activequeue.tail;
			}
			activequeue.tail = pOVar2;
			if (pOVar6) {
				(pOVar6->linkActive).next = pOVar5;
				pOVar5 = activequeue.head;
			}
			activequeue.head = pOVar5;
			param_1->state = 0;
			OSRestoreInterrupts(bVar4);
			uVar3 = 1;
		} else {
			OSRestoreInterrupts(bVar4);
			uVar3 = 0;
		}
		return uVar3;
	}
}