#include "JKRDecomp.h"

JKRDecompCommand::JKRDecompCommand() {
	os::OSInitMessageQueue(&this->messagequeue, &this->message, 1);
	this->callback = 0;
	this->overridemqueue = nullptr;
	this->self = this;
	this->isAram = 0;
}

os::OSMessageQueue JKRDecomp::sMessageQueue;
os::OSMessage JKRDecomp::sMessageBuffer[4];

JKRDecomp__CompressionType JKRDecomp::checkCompressed(uchar *param_1) {
	if (((*param_1 == 'Y') && (param_1[1] == 'a')) && (param_1[3] == '0')) {
		if (param_1[2] == 'y') {
			return Yay0Compressed;
		}
		if (param_1[2] == 'z') {
			return Yaz0Compressed;
		}
	}
	return NotCompressed;
}

JKRDecomp::JKRDecomp(long param_1) : JKRThread(0x4000, 0x10, param_1) {
	os::OSResumeThread(thread);
}

void JKRDecomp::sendCommand(JKRDecompCommand *param_1) {
	os::OSSendMessage(&JKRDecomp::sMessageQueue, param_1, 1);
}

void JKRDecomp::sync(JKRDecompCommand *param_1, int param_2) {
	undefined auStack8[8];

	if (param_2 == 0) {
		os::OSReceiveMessage(&param_1->messagequeue, (void **)auStack8, 1);
	} else {
		os::OSReceiveMessage(&param_1->messagequeue, (void **)auStack8, 0);
	}
}

JKRDecompCommand *JKRDecomp::orderAsync(uchar *param_1, uchar *param_2, ulong param_3, ulong param_4, CBType *param_5) {
	JKRDecompCommand *pJVar1;

	pJVar1 = JKRDecomp::prepareCommand(param_1, param_2, param_3, param_4, (CBType *)param_5);
	JKRDecomp::sendCommand(pJVar1);
	return pJVar1;
}

JKRDecompCommand *JKRDecomp::orderSync(uchar *param_1, uchar *param_2, ulong param_3, ulong param_4) {
	JKRDecompCommand *self;
	JKRDecompCommand *pJVar1;

	self = JKRDecomp::orderAsync(param_1, param_2, param_3, param_4, nullptr);
	pJVar1 = self;
	JKRDecomp::sync(self, 0);
	self->~JKRDecompCommand();
	return pJVar1;	// why
}

JKRDecomp *JKRDecomp::sDecompObject;

JKRDecomp *JKRDecomp::create(long prio) {
	JKRDecomp *self;

	self = sDecompObject;
	if ((sDecompObject == (JKRDecomp *)0x0)) {
		self = new (JKRHeap::sSystemHeap, 0) JKRDecomp(prio);
	}
	sDecompObject = self;
	return sDecompObject;
}

JKRDecompCommand *JKRDecomp::prepareCommand(uchar *param_1, uchar *param_2, ulong param_3, ulong param_4, CBType *param_5) {
	JKRDecompCommand *this_00;

	this_00 = new (JKRHeap::sSystemHeap, -4) JKRDecompCommand();
	this_00->buffer = param_1;
	this_00->destbuff = param_2;
	this_00->srcsize = param_3;
	this_00->destsize = param_4;

	this_00->callback = param_5;
	return this_00;
}

void *JKRDecomp::run(void *) {
	JKRDecompCommand *pJVar1;
	JKRAMCommand *pJVar2;
	JKRDecompCommand *local_18[4];

	os::OSInitMessageQueue(&JKRDecomp::sMessageQueue, JKRDecomp::sMessageBuffer, 4);
	do {
		while (true) {
			while (true) {
				os::OSReceiveMessage(&JKRDecomp::sMessageQueue, (os::OSMessage *)local_18, 1);
				pJVar1 = local_18[0];
				pJVar2 = local_18[0]->srcsize;
				JKRDecomp::decode(local_18[0]->buffer, (uchar *)pJVar2, (ulong)local_18[0]->destbuff,
								  local_18[0]->destsize);
				if (pJVar1->isAram == 0)
					break;
				if (pJVar1->isAram == 1) {
					JKRAramPiece::sendCommand(pJVar1->arampiece, pJVar2);
				}
			}
			if (!pJVar1->callback)
				break;
			pJVar1->callback();
		}
		if (pJVar1->overridemqueue == 0) {
			os::OSSendMessage(&pJVar1->messagequeue, (void *)1, 0);
		} else {
			os::OSSendMessage(pJVar1->overridemqueue, (void *)1, 0);
		}
	} while (true);
}

/* From TLoZ:TP decomp project*/
void JKRDecomp::decodeSZS(u8 *src_buffer, u8 *dst_buffer, u32 param_3, u32 param_4) {
	int copyByteCount;
	u8 *decompEnd;
	u8 *copyStart;
	int chunkBitsLeft = 0;
	int chunkBits;
	decompEnd = dst_buffer + *(int *)(src_buffer + 4) - param_4;
	if (param_3 == 0) {
		return;
	}
	if (param_4 > *(u32 *)src_buffer) {
		return;
	}
	u8 *curSrcPos = src_buffer + 0x10;
	do {
		if (chunkBitsLeft == 0) {
			chunkBits = *curSrcPos;
			chunkBitsLeft = 8;
			curSrcPos++;
		}
		if ((chunkBits & 0x80) != 0) {
			if (param_4 == 0) {
				*dst_buffer = *curSrcPos;
				param_3--;
				dst_buffer++;
				if (param_3 == 0) {
					return;
				}
			} else {
				param_4--;
			}
			curSrcPos++;
		} else {
			int curVal = *curSrcPos;
			// load is inversed
			copyStart = dst_buffer - ((curVal & 0xF) << 8 | curSrcPos[1]);
			// copyByteCount = ;
			curSrcPos += 2;
			// instruction order differences
			if (curVal >> 4 == 0) {
				copyByteCount = *curSrcPos + 0x12;
				curSrcPos++;
			} else {
				copyByteCount = (curVal >> 4) + 2;
			}
			do {
				if (param_4 == 0) {
					*dst_buffer = *(copyStart - 1);
					param_3--;
					dst_buffer++;
					if (param_3 == 0) {
						return;
					}
				} else {
					param_4--;
				}
				copyByteCount--;
				copyStart++;
			} while (copyByteCount != 0);
		}
		chunkBits <<= 1;
		chunkBitsLeft--;
	} while (dst_buffer != decompEnd);
}

void JKRDecomp::decodeSZP(u8 *src, u8 *dst, u32 srcLength, u32 dstLength) {
	u32 decodedSize;
	s32 srcChunkOffset;
	s32 count;
	s32 dstOffset;
	u32 length;
	u32 counter;
	u32 srcDataOffset;
	u32 linkTableOffset;
	s32 offset;
	s32 i;

	decodedSize = read_big_endian_u32(src + 4);
	linkTableOffset = read_big_endian_u32(src + 8);
	srcDataOffset = read_big_endian_u32(src + 12);

	dstOffset = 0;
	counter = 0;
	srcChunkOffset = 16;

	u32 chunkBits;
	if (srcLength == 0)
		return;
	if (dstLength > decodedSize)
		return;

	length = srcLength;
	do {
		if (counter == 0) {
			chunkBits = read_big_endian_u32(src + srcChunkOffset);
			srcChunkOffset += 4;
			counter = 32;
		}

		if (chunkBits & 0x80000000) {
			if (dstLength == 0) {
				dst[dstOffset] = src[srcDataOffset];
				length--;
				if (length == 0) {
					return;
				}
			} else {
				dstLength--;
			}
			dstOffset++;
			srcDataOffset++;
		} else {
			u32 linkInfo = read_big_endian_u16(src + linkTableOffset);
			linkTableOffset += 2;

			offset = dstOffset - (linkInfo & 0xFFF);
			count = ((s32)linkInfo) >> 12;
			if (count == 0) {
				count = (u32)src[srcDataOffset] + 0x12;
				srcDataOffset++;
			} else {
				count += 2;
			}

			if (count > decodedSize - dstOffset) {
				count = decodedSize - dstOffset;
			}

			for (i = 0; i < count; i++, dstOffset++, offset++) {
				if (dstLength == 0) {
					dst[dstOffset] = dst[offset - 1];
					length--;
					if (length == 0) {
						return;
					}
				} else {
					dstLength--;
				}
			}
		}

		chunkBits <<= 1;
		counter--;
	} while ((s32)dstLength < decodedSize);
}

void JKRDecomp::decode(uchar *param_1, uchar *param_2, ulong param_3, ulong param_4)

{
	JKRDecomp__CompressionType JVar1;

	JVar1 = JKRDecomp::checkCompressed(param_1);
	if (JVar1 == Yay0Compressed) {
		decodeSZP(param_1, param_2, param_3, param_4);
	} else if (JVar1 == Yaz0Compressed) {
		decodeSZS(param_1, param_2, param_3, param_4);
	}
	return;
}

JKRDecomp::~JKRDecomp() {}
