#include "./JUTAssert.h"

#include <cstdarg>
#include <cstdio>

JUTAssertion *JUTAssertion::getSDevice() {
#ifdef DOLPHIN
#else
	return nullptr;
#endif
}

void JUTAssertion::setVisible(bool) {
}

void JUTAssertion::setWarningMessage_f(const char *file, int ln, const char *str, ...) {
	va_list ap;
	va_start(ap, str);
	printf("[WARNING][%s:%d] - ", file, ln);
	vprintf(str, ap);
	va_end(ap);
}

void JUTAssertion::setLogMessage_f(const char *file, int ln, const char *str, ...) {
	va_list ap;
	va_start(ap, str);
	printf("[LOG][%s:%d] - ", file, ln);
	vprintf(str, ap);
	va_end(ap);
}

void JUTAssertion::showAssert(const char *file, int ln, const char *ass) {
	printf("[ASSERT][%s:%d] - %s\n", file, ln, ass);
}

void JUTAssertion::showAssert(JUTAssertion *s, const char *file, int ln, const char *ass) {
	s->showAssert(file, ln, ass);
}

void JUTAssertion::showAssert(int a, const char *file, int ln, const char *ass) {
	printf("[ASSERT][%s:%d] - %s\n", file, ln, ass);
}

void JUTAssertion::setConfirmMessage(const char *, byte, byte, const char *) {
}

void JUTAssertion::flushMessage() {
}

void JUTAssertion::setMessageCount(int) {
}
