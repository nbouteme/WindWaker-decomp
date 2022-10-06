#include <dolphin/os.h>
#include <ucontext.h>

#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace os;
OSThreadQueue tq;
OSMessageQueue mq;
OSMessage msg;

void osalrmhandler(OSAlarm *alrm, OSContext *) {
	puts("WAKING UP");
	OSWakeupThread(&tq);
}

OSAlarm alrm;
void *spawned(void *) {
	OSInitMessageQueue(&mq, &msg, 1);
	while (true) {
		OSReceiveMessage(&mq, &msg, OS_MESSAGE_BLOCK);
		printf("Received message: %s\n", msg);
	}
	return 0;
}

OSThread th;
int main() {
	using namespace os;
	OSInit();
	void *ret;
	void *stack = malloc(0x8000);
	int r = OSCreateThread(&th, spawned, 0, (void *)((char *)stack + 0x8000), 0x8000, 3, 0);
	OSResumeThread(&th);
	const char *mesgs[] = {"First", "Second", "Third"};
	for (int i = 0; i < 3; ++i) {
		puts("Sending message");
		OSSendMessage(&mq, (void*)mesgs[i], OS_MESSAGE_BLOCK);
		puts("Sent");
	}
	OSJoinThread(&th, &ret);
	free(stack);
	// printf("ret: %p\n", ret);
}