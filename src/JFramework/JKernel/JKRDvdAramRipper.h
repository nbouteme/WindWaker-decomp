#pragma once

#include <dolphin/os.h>

#include "JKRDvdRipper.h"
#include "../JSupport/JSUIosBase.h"
#include "../JSupport/JSUPtrList.h"

struct JKRAramStreamCommand;

struct JKRADCommand : public JSUPtrLink {
	JKRDvdFile *dvdfile;
	uint offset, availableAramBuffer, size;
	JKRAramBlock *aramAreaPointer;
	JKRExpandSwitch expand;
	byte unused[24];
	void (*callback)(JKRADCommand *);
	int commandsucc;
	byte dataloaded;
	JKRAramStreamCommand *streamcmd;
	JKRADCommand();
};

namespace JKRDvdAramRipper {
	extern int sSzpBufferSize;
	extern JSUPtrList sDvdAramAsyncList;
	extern byte errorRetry;

	undefined4 syncAram(JKRADCommand *param_1, int param_2);
	JKRADCommand *callCommand_Async(JKRADCommand *param_1);
	JKRADCommand *loadToAram_Async(JKRDvdFile *param_1, ulong param_2, JKRExpandSwitch param_3, void (*callback)(JKRADCommand *), ulong offset, ulong aramBuffSize);
	JKRAramBlock *loadToAram(JKRDvdFile *dvdfile, ulong size, JKRExpandSwitch expand, ulong offset, ulong param_5);
	JKRAramBlock *loadToAram(long param_1, ulong param_2, JKRExpandSwitch param_3, ulong param_4, ulong param_5);
};
