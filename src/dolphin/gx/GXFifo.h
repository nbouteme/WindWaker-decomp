#pragma once

#include <dolphin/gx/GXEnum.h>
#include <dolphin/os/OSAlarm.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os/OSThread.h>
#include <dolphin/types.h>

namespace gx {
	using namespace os;

// Minimum size for any FIFO is 64k
// The hi watermark is automatically set to fifosize - 16k,
// large enough for a full locked cache DMA.
#define GX_FIFO_MINSIZE (64 * 1024)
#define GX_FIFO_HI_WATERMARK_BUFFER (16 * 1024)

// Placeholder structure for GXFifoObj.  Actual structure members are private.
#define GX_FIFO_OBJ_SIZE 128

	typedef struct {
		void* baseptr;
		void* bottom;
		uint size;
		u32 hi_wm;
		u32 lo_wm;
		void* begin;
		void* end;
		int distance;
	} GXFifoObj;

	typedef void (*GXBreakPtCallback)(void);

	/*---------------------------------------------------------------------------*
  Get APIs
 *---------------------------------------------------------------------------*/
	void GXGetGPStatus(
		GXBool* overhi,
		GXBool* underlow,
		GXBool* readIdle,
		GXBool* cmdIdle,
		GXBool* brkpt);

	void GXGetFifoStatus(
		GXFifoObj* fifo,
		GXBool* overhi,
		GXBool* underlow,
		u32* fifoCount,
		GXBool* cpu_write,
		GXBool* gp_read,
		GXBool* fifowrap);

	void GXGetFifoPtrs(
		GXFifoObj* fifo,
		void** readPtr,
		void** writePtr);

	GXFifoObj* GXGetCPUFifo(void);
	GXFifoObj* GXGetGPFifo(void);

	void* GXGetFifoBase(const GXFifoObj* fifo);
	u32 GXGetFifoSize(const GXFifoObj* fifo);
	void GXGetFifoLimits(const GXFifoObj* fifo, u32* hi, u32* lo);

	/*---------------------------------------------------------------------------*
  Breakpoint APIs
 *---------------------------------------------------------------------------*/
	GXBreakPtCallback GXSetBreakPtCallback(GXBreakPtCallback cb);

	void GXEnableBreakPt(
		void* breakPtr);

	void GXDisableBreakPt(void);

	/*---------------------------------------------------------------------------*
  Init FIFO APIs
 *---------------------------------------------------------------------------*/
	void GXInitFifoBase(
		GXFifoObj* fifo,
		void* base,
		u32 size);

	void GXInitFifoPtrs(
		GXFifoObj* fifo,
		void* readPtr,
		void* writePtr);

	void GXInitFifoLimits(
		GXFifoObj* fifo,
		u32 hiWaterMark,
		u32 loWaterMark);

	/*---------------------------------------------------------------------------*
  Attaching FIFOs to CPU/GP
 *---------------------------------------------------------------------------*/
	void GXSetCPUFifo(GXFifoObj* fifo);
	void GXSetGPFifo(GXFifoObj* fifo);
	void GXSaveCPUFifo(GXFifoObj* fifo);
	void GXSaveGPFifo(GXFifoObj* fifo);

	/*---------------------------------------------------------------------------*
  Redirecting write gather pipe
 *---------------------------------------------------------------------------*/
	volatile void* GXRedirectWriteGatherPipe(void* ptr);
	void GXRestoreWriteGatherPipe(void);

	/*---------------------------------------------------------------------------*
  GX thread that will be interrupted by FIFO handlers in immediate mode
 *---------------------------------------------------------------------------*/
	OSThread* GXSetCurrentGXThread(void);
	OSThread* GXGetCurrentGXThread(void);

	/*---------------------------------------------------------------------------*
  Overflow counter API
 *---------------------------------------------------------------------------*/
	u32 GXGetOverflowCount(void);
	u32 GXResetOverflowCount(void);

/*---------------------------------------------------------------------------*
  EPPC Emulation
 *---------------------------------------------------------------------------*/
#ifndef EMU

	void __GXDumpFifo(
		BOOL full);

	void __GXWriteFifo(
		u8* ptr,
		s32 size,
		OSContext* context);

	void __GXWritePI(
		u32 cmd,
		u32 ea,
		u32 data[8],
		OSContext* context);

	// for extensive testing of watermark triggers
	void __GXInsaneWatermark();
#endif

}