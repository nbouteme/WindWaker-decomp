#pragma once

#include "JKRAramPiece.h"
#include "JKRThread.h"

struct JKRAMCommand;

enum JKRDecomp__CompressionType {
	NotCompressed,
	Yay0Compressed,
	Yaz0Compressed,
	__dummy = ~0
};

inline u32 read_big_endian_u32(void *ptr) {
	u8 *uptr = (u8 *)ptr;
	return ((u32)uptr[0] << 0x18) | ((u32)uptr[1] << 0x10) | ((u32)uptr[2] << 8) | (u32)uptr[3];
}

inline u16 read_big_endian_u16(void *ptr) {
	u8 *uptr = (u8 *)ptr;
	return ((u16)uptr[0] << 8) | ((u16)uptr[1]);
}

struct JKRDecompCommand {
	using CBType = void();

	byte *buffer;
	byte *destbuff;
	uint srcsize;
	uint destsize;

	CBType *callback;
	void *self;
	os::OSMessageQueue *overridemqueue;
	uint isAram;
	JKRAMCommand *arampiece;
	os::OSMessageQueue messagequeue;
	os::OSMessage message;

	JKRDecompCommand();
};

struct JKRDecomp : public JKRThread {
	using CBType = void();

	static os::OSMessageQueue sMessageQueue;
	static os::OSMessage sMessageBuffer[4];

	static JKRDecomp__CompressionType checkCompressed(uchar *param_1);
	static void sendCommand(JKRDecompCommand *param_1);
	static void sync(JKRDecompCommand *param_1, int param_2);
	static JKRDecompCommand *orderAsync(uchar *param_1, uchar *param_2, ulong param_3, ulong param_4, CBType *param_5);
	static JKRDecompCommand *orderSync(uchar *param_1, uchar *param_2, ulong param_3, ulong param_4);
	static JKRDecomp *sDecompObject;
	static JKRDecomp *create(long prio);
	static JKRDecompCommand *prepareCommand(uchar *param_1, uchar *param_2, ulong param_3, ulong param_4, CBType *param_5);
	/* From TLoZ:TP decomp project*/
	static void decodeSZS(u8 *src_buffer, u8 *dst_buffer, u32 param_3, u32 param_4);
	static void decodeSZP(u8 *src, u8 *dst, u32 srcLength, u32 dstLength);
	static void decode(uchar *param_1, uchar *param_2, ulong param_3, ulong param_4);

	virtual void *run(void *);

	JKRDecomp(long param_1);

	virtual ~JKRDecomp();
};
