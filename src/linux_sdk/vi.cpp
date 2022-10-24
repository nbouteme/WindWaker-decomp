#include <GLFW/glfw3.h>
#include <dolphin/gx.h>
#include <dolphin/vi.h>
#include <fenv.h>

#include <cstdio>
#include <thread>

namespace os {
	extern os::__OSExceptionHandler OSExceptionTable[16];
	extern os::OSContext *currentctx;
	extern u32 pi_regs[5];
	void NotifyExternalException();
}

namespace vi {

	/*
		Each piece of hardware will be emulated through a real thread
		to not interfer with the regular scheduling
	*/
	namespace hw_thread {
		GLFWwindow *window;
		void startup() {
			if (!glfwInit())
				return;

			window = glfwCreateWindow(640, 528, "WW", NULL, NULL);
			if (!window) {
				glfwTerminate();
				return;
			}

			glfwMakeContextCurrent(window);
			glfwSetWindowMonitor(window, nullptr, 10, 10, 640, 528, 30);
			glfwSwapInterval(32);

			std::thread vithread([]() {
				sigset_t mask;

				sigemptyset(&mask);
				sigaddset(&mask, SIGALRM);
				sigaddset(&mask, SIGUSR1);
				pthread_sigmask(SIG_BLOCK, &mask, NULL);
				//fedisableexcept(FE_DIVBYZERO | FE_INEXACT | FE_INVALID | FE_OVERFLOW | FE_UNDERFLOW);
				//fedisableexcept(-1);

				while (true) {
					glfwSwapBuffers(window);  // maybe not correct
					//usleep(16666);
					os::pi_regs[0] |= 0x00000100;  // Set VI Interrupt flag
					os::NotifyExternalException();
					//os::OSExceptionTable[4](4, os::currentctx);	 // hope this is correct
					//glfwPollEvents();
				}

				// while (!glfwWindowShouldClose(window)) {
				// 	// hack to make the refresh rate 60fps on my 120hz screen
				// 	glfwSwapBuffers(window);  // maybe not correct

				// 	os::pi_regs[0] |= 0x00000100;  // Set VI Interrupt flag
				// 	os::NotifyExternalException();
				// 	//os::OSExceptionTable[4](4, os::currentctx);	 // hope this is correct

				// 	glfwPollEvents();
				// }

				//glfwTerminate();
			});
			vithread.detach();
		}

	}

	int retraceCount;
	os::OSThreadQueue retraceQueue;
	int flushFlag;
	int shdwChangeMode;
	VIRetraceCallback post, pre;

	void VIConfigure(gx::GXRenderModeObj const *mode) {
		//
	}

	void __VIRetraceHandler(s16 param_1, os::OSContext *param_2) {
		// TODO: return if caused by DI2 or DI3, but seems to be unused
		os::OSContext OStack736;
		bool bVar4;
		int iVar3;

		retraceCount = retraceCount + 1;
		os::OSClearContext(&OStack736);
		os::OSSetCurrentContext(&OStack736);
		if (pre) {
			(*pre)(retraceCount);
		}
		if (flushFlag != 0) {
			// do something?
		}
		if (post) {
			os::OSClearContext(&OStack736);
			(*post)(retraceCount);
		}
		os::OSWakeupThread(&retraceQueue);
		os::OSClearContext(&OStack736);
		os::OSSetCurrentContext(param_2);
	}

	void VIInit() {
		static bool isinit = false;
		if (isinit)
			return;
		isinit = true;

		os::OSInitThreadQueue(&retraceQueue);
		os::__OSSetInterruptHandler(__OS_INTERRUPT_PI_VI, __VIRetraceHandler);

		hw_thread::startup();
	}

	void VISetNextFrameBuffer(void *) {
		//
	}

	VIRetraceCallback VISetPostRetraceCallback(VIRetraceCallback cb) {
		auto old = post;
		if (cb)
			post = cb;
		return old;
	}

	VIRetraceCallback VISetPreRetraceCallback(VIRetraceCallback cb) {
		auto old = pre;
		if (cb)
			pre = cb;
		return old;
	}

	uint VIGetRetraceCount() {
		return retraceCount;
	}

	void VISetBlack(bool) {
		//
	}

	void VIFlush() {
		//
	}

	void VIWaitForRetrace() {
		int iVar1;
		bool bVar2;

		bVar2 = (bool)os::OSDisableInterrupts();
		iVar1 = retraceCount;
		do {
			os::OSSleepThread(&retraceQueue);
		} while (iVar1 == retraceCount);
		os::OSRestoreInterrupts(bVar2);
		return;
	}
}