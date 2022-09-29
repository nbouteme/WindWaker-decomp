#include <cstdio>
#include "./JUTAssert.h"

JUTAssertion *JUTAssertion::getSDevice() {
#ifdef DOLPHIN
#else
	return nullptr;
#endif
}

void JUTAssertion::setWarningMessage_f(const char *file, int ln, const char *format, ...) {
	//
}
