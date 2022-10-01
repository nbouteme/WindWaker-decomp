#include "JKRAramPiece.h"
#include "JKernel.h"
#include "JKRExpHeap.h"
#include <machine/dolphin/printf.h>
#include "JKRDecomp.h"

namespace JKRAramPiece {
	os::OSMutex mMutex;
	JSUPtrList sAramPieceCommandList;

void doneDMA(JKRAMCommand *param_1) {
		if (param_1->direction == 1) {
			os::DCInvalidateRange((void *)param_1->dest, param_1->length);
		}
		if (param_1->unused_3 == 0) {
			if (!param_1->callback) {
				if (!param_1->unused_2) {
					os::OSSendMessage(&param_1->queue, param_1, 0);
				} else {
					os::OSSendMessage(param_1->unused_2, param_1, 0);
				}
			} else {
				(*param_1->callback)((ulong)param_1);
			}
		} else if (param_1->unused_3 == 2) {
			// next command?
			JKRDecomp::sendCommand(param_1->unused_4);
		}
	}

	void startDMA(JKRAMCommand *param_1)

	{
		if (param_1->direction == 1) {
			os::DCInvalidateRange((void *)param_1->dest, param_1->length);
		} else {
			os::DCStoreRange((void *)param_1->source, param_1->length);
		}
		ar::ARQPostRequest(param_1, 0, param_1->direction, 0, param_1->source, param_1->dest,
						   param_1->length, (ar::ARQCallback)JKRAramPiece::doneDMA);
		return;
	}

	void sendCommand(JKRAMCommand *param_1) {
		startDMA(param_1);
	}

	JKRAMCommand *prepareCommand(int direction, ulong source, ulong dest, ulong length, JKRAramBlock *param_5,
											   void (*callback)(ulong)) {
		JKRAMCommand *cmd;

		cmd = new (JKRHeap::sSystemHeap, -4) JKRAMCommand();
		cmd->direction = direction;
		cmd->source = source;
		cmd->dest = dest;
		cmd->blk = param_5;
		cmd->length = length;
		cmd->callback = callback;
		return cmd;
	}

	JKRAMCommand *orderAsync(int direction, ulong source, ulong destination, ulong length, JKRAramBlock *param_5,
										   void (*param_6)(ulong)) {
		Message *puVar1;
		JKRAMCommand *pJVar2;

		os::OSLockMutex(&mMutex);
		/* check for alignment */
		if (((source & 0x1f) != 0) || ((destination & 0x1f) != 0)) {
			m_Do_printf::OSReport("direction = %x\n", direction);
			m_Do_printf::OSReport("source = %x\n", source);
			m_Do_printf::OSReport("destination = %x\n", destination);
			m_Do_printf::OSReport("length = %x\n", length);
			m_Do_printf::OSPanic("JKRAramPiece.cpp", 0x66, "Abort.");
		}
		puVar1 = new (JKRHeap::sSystemHeap, -4) Message;
		pJVar2 = prepareCommand(direction, source, destination, length, param_5, param_6);
		puVar1->a = 1;
		puVar1->b = pJVar2;
		os::OSSendMessage(&JKRAram::sMessageQueue, puVar1, 1);
		if (pJVar2->callback) {
			sAramPieceCommandList.append(&pJVar2->linka);
		}
		os::OSUnlockMutex(&mMutex);
		return pJVar2;
	}

	void sync(JKRAMCommand *param_1, int param_2) {
		int iVar1;
		undefined auStack24[16];

		os::OSLockMutex(&mMutex);
		if (param_2 == 0) {
			os::OSReceiveMessage(&param_1->queue, (void **)auStack24, 1);
			sAramPieceCommandList.remove(&param_1->linka);
			os::OSUnlockMutex(&mMutex);
		} else {
			iVar1 = os::OSReceiveMessage(&param_1->queue, (void **)auStack24, 0);
			if (iVar1 == 0) {
				os::OSUnlockMutex(&mMutex);
			} else {
				sAramPieceCommandList.remove(&param_1->linka);
				os::OSUnlockMutex(&mMutex);
			}
		}
	}

	void orderSync(int direction, ulong source, ulong dest, ulong len, JKRAramBlock *param_5) {
		JKRAMCommand *cmd;

		os::OSLockMutex(&mMutex);
		cmd = (JKRAMCommand *)
			orderAsync(direction, source, dest, len, param_5, nullptr);
		sync(cmd, 0);
		delete cmd;
		os::OSUnlockMutex(&mMutex);
	}
}