#include "./JUTAssert.h"

#include <cstdio>

JUTAssertion *JUTAssertion::getSDevice() {
#ifdef DOLPHIN
#else
	return nullptr;
#endif
}

void JUTAssertion::setVisible(bool) {
}

void JUTAssertion::setWarningMessage_f(const char *file, int ln, const char *format, ...) {
}

void JUTAssertion::setLogMessage_f(const char *file, int ln, const char *format, ...) {
}

void JUTAssertion::showAssert(const char *file, int ln, const char *format) {
}

void JUTAssertion::setConfirmMessage(const char *, byte, byte, const char *) {
}

void JUTAssertion::flushMessage() {
}

void JUTAssertion::setMessageCount(int) {
}
