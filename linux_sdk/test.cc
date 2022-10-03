#include <dolphin/os.h>
#include <ucontext.h>

#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace os;
OSThreadQueue tq;

void osalrmhandler(OSAlarm *alrm, OSContext *) {
	puts("WAKING UP");
	OSWakeupThread(&tq);
}

OSAlarm alrm;
void *spawned(void *) {
	OSCreateAlarm(&alrm);
	OSInitThreadQueue(&tq);

	puts("Thread Spawned, going to sleep for one second");
	OSSetAlarm(&alrm, OSSecondsToTicks(1), osalrmhandler);

	OSSleepThread(&tq);
	puts("Timer finished");
	return 0;
}

OSThread th;
int main() {
	using namespace os;
	OSInit();
	printf("%p\n", &th.context);
	void *ret;
	void *stack = malloc(0x8000);
	int r = OSCreateThread(&th, spawned, 0, stack, 0x8000, 3, 0);
	OSResumeThread(&th);
	printf("r: %d\n", r);
	OSJoinThread(&th, &ret);
	// printf("ret: %p\n", ret);
}