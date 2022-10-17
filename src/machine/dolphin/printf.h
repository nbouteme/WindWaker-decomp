#pragma once

namespace m_Do_printf {
	int OSReport(const char *format, ...); // should be in OS?
	int OSPanic(const char *fn, int ln, char *reason);
	void OSReportInit();
	int OSReport_Error(const char *format, ...);
	void OSReport_FatalError(const char *format, ...);
	void OSReportDisable();
	void OSReportEnable();
	void OSReport_Warning(const char *f, ...);
}