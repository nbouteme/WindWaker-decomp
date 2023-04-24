#pragma once

#include <dolphin/ar.h>
#include <dolphin/os.h>
#include <doltypes.h>

#include "../JSupport/JSUPtrList.h"
#include "JKRAram.h"

struct JKRAramBlock;
struct JKRDecompCommand;

struct JKRAMCommand : public ar::ARQRequest {
	JSUPtrLink linka, linkb;
	int direction;
	intptr_t length, source, dest;
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
	extern os::OSMutex mMutex;
	extern JSUPtrList sAramPieceCommandList;

	struct Message {
		int a;
		JKRAMCommand *b;
	};

	JKRAMCommand *prepareCommand(int direction, ulong source, ulong dest, ulong length, JKRAramBlock *param_5,
								 void (*callback)(ulong));

	JKRAMCommand *orderAsync(int direction, ulong source, ulong destination, ulong length, JKRAramBlock *param_5,
							 void (*param_6)(ulong));

	void doneDMA(JKRAMCommand *param_1);
	void startDMA(JKRAMCommand *param_1);
	void sendCommand(JKRAMCommand *param_1);
	void sync(JKRAMCommand *param_1, int param_2);

	void orderSync(int direction, ulong source, ulong dest, ulong len, JKRAramBlock *param_5);
}