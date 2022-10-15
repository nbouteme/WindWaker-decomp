#pragma once

#include <doltypes.h>

struct JUTAssertion {
	static JUTAssertion *getSDevice();
	static void setVisible(bool);
	void setWarningMessage_f(const char *file, int ln, const char *format, ...);
	void setLogMessage_f(const char *file, int ln, const char *format, ...);
	void showAssert(const char *file, int ln, const char *format);
	static void showAssert(JUTAssertion *, const char *file, int ln, const char *format);
	static void showAssert(int, const char *file, int ln, const char *format);
	void setConfirmMessage(const char *, byte, byte, const char *);
	static void flushMessage();
	static void setMessageCount(int);
};