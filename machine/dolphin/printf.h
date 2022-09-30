#pragma once

namespace m_Do_printf {
	int OSReport(const char *format, ...);
	int OSPanic(const char *fn, int ln, char *reason);
	void OSReportInit();
	int OSReport_Error(const char *format, ...);
	void OSReportDisable();
	void OSReportEnable();
	void OSReport_Warning(const char *f, ...);
}