#pragma once
#include <ctypes.h>



namespace base {
void PPCMfmsr(void);
void PPCMtmsr(void);
void PPCMfhid0(void);
void PPCMthid0(void);
void PPCMfl2cr(void);
void PPCMtl2cr(void);
void PPCMtdec(void);
void PPCSync(void);
void PPCHalt(void);
uint PPCMffpscr(void);
void PPCMtfpscr(void);
void PPCMfhid2(void);
void PPCMthid2(void);
void PPCMtwpar(void);
void PPCDisableSpeculation(void);
void PPCSetFpNonIEEEMode(void);
}
