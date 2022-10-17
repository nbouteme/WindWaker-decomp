#include "printf.h"

#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace m_Do_printf {
	int OSReport(const char *str, ...) {
		va_list ap;
		va_start(ap, str);
		vprintf(str, ap);
		va_end(ap);
	}

	int OSPanic(const char *fn, int ln, char *reason) {
		printf("[PANIC]: [%s: %d]: %s\n", fn, ln, reason);
		abort();
	}

	void OSReportInit() {
	}

	int OSReport_Error(const char *str, ...) {
		va_list ap;
		va_start(ap, str);
		vprintf(str, ap);
		va_end(ap);
	}

	void OSReport_FatalError(const char *format, ...) {
		va_list ap;
		va_start(ap, format);
		vprintf(format, ap);
		va_end(ap);
	}

	void OSReportDisable() {}

	void OSReportEnable() {}

	void OSReport_Warning(const char *f, ...) {
		va_list ap;
		va_start(ap, f);
		vprintf(f, ap);
		va_end(ap);
	}
}