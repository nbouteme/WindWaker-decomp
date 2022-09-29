#pragma once

#include <dolphin/ar.h>
#include <dolphin/os.h>
#include <doltypes.h>

#include "../JSupport/JSUPtrList.h"
#include "JKRAram.h"
#include "JKRAramHeap.h"

struct JKRAMCommand : public ar::ARQRequest {
	JSUPtrLink linka, linkb;
	int direction;
	uint length, source, dest;
	JKRAramBlock *blk;
	uint unused_;
	void (*callback)(ulong);
	os::OSMessageQueue *unused_2;
	uint unused_3;
	JKRDecompCommand *unused_4;
	os::OSMessageQueue queue;
	os::OSMessage messages[1];
	uint unused_5, unused_6, unused_7;

	JKRAMCommand() : linka(this), linkb(this) {
		os::OSInitMessageQueue(&this->queue, this->messages, 1);
		this->callback = nullptr;
		this->unused_2 = nullptr;
		this->unused_3 = 0;
		this->unused_5 = 0;
		this->unused_6 = 0;
		this->unused_7 = 0;
	}
};

namespace JKRAramPiece {
	os::OSMutex mMutex;
	JSUPtrList sAramPieceCommandList;

	struct Message {
		int a;
		JKRAMCommand *b;
	};

	JKRAMCommand *
	JKRAramPiece::prepareCommand(int direction, ulong source, ulong dest, ulong length, JKRAramBlock *param_5,
								 void (*callback)(ulong))

	{
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

	JKRAMCommand *
	JKRAramPiece::orderAsync(int direction, ulong source, ulong destination, ulong length, JKRAramBlock *param_5,
							 void (*param_6)(ulong))

	{
		Message *puVar1;
		JKRAMCommand *pJVar2;

		os::OSLockMutex(&JKRAramPiece::mMutex);
		/* check for alignment */
		if (((source & 0x1f) != 0) || ((destination & 0x1f) != 0)) {
			m_Do_printf::OSReport("direction = %x\n", direction);
			m_Do_printf::OSReport("source = %x\n", source);
			m_Do_printf::OSReport("destination = %x\n", destination);
			m_Do_printf::OSReport("length = %x\n", length);
			m_Do_printf::OSPanic("JKRAramPiece.cpp", 0x66, "Abort.");
		}
		puVar1 = new (JKRHeap::sSystemHeap, -4) Message;
		pJVar2 = JKRAramPiece::prepareCommand(direction, source, destination, length, param_5, param_6);
		puVar1->a = 1;
		puVar1->b = pJVar2;
		os::OSSendMessage(&JKRAram::sMessageQueue, puVar1, 1);
		if (pJVar2->callback) {
			JKRAramPiece::sAramPieceCommandList.append(&pJVar2->linka);
		}
		os::OSUnlockMutex(&JKRAramPiece::mMutex);
		return pJVar2;
	}

	void JKRAramPiece::sync(JKRAMCommand *param_1, int param_2)

	{
		int iVar1;
		undefined auStack24[16];

		os::OSLockMutex(&JKRAramPiece::mMutex);
		if (param_2 == 0) {
			os::OSReceiveMessage(&param_1->queue, (void **)auStack24, 1);
			JKRAramPiece::sAramPieceCommandList.remove(&param_1->linka);
			os::OSUnlockMutex(&JKRAramPiece::mMutex);
		} else {
			iVar1 = os::OSReceiveMessage(&param_1->queue, (void **)auStack24, 0);
			if (iVar1 == 0) {
				os::OSUnlockMutex(&JKRAramPiece::mMutex);
			} else {
				JKRAramPiece::sAramPieceCommandList.remove(&param_1->linka);
				os::OSUnlockMutex(&JKRAramPiece::mMutex);
			}
		}
		return;
	}

	void orderSync(int direction, ulong source, ulong dest, ulong len, JKRAramBlock *param_5)

	{
		JKRAMCommand *cmd;

		os::OSLockMutex(&JKRAramPiece::mMutex);
		cmd = (JKRAMCommand *)
			JKRAramPiece::orderAsync(direction, source, dest, len, param_5, nullptr);
		JKRAramPiece::sync(cmd, 0);
		delete cmd;
		os::OSUnlockMutex(&JKRAramPiece::mMutex);
		return;
	}
}