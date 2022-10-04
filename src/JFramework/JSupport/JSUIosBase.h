#pragma once

#include <dolphin/dvd.h>
#include <dolphin/os.h>
#include <doltypes.h>
#include <machine/dolphin/printf.h>

#include "../JKernel/JKRDisposer.h"
#include "../JUtility/JUTAssert.h"

struct JKRAramBlock;

struct JSUIosBase {
	virtual ~JSUIosBase();
};

struct JSUInputStream : public JSUIosBase {
	byte status;

	virtual uint readData(void *b, uint s) = 0;
	virtual int skip(uint param_1);
	virtual ~JSUInputStream();

	uint read(void *b, uint s);
};

struct JSURandomInputStream : public JSUInputStream {
	virtual uint readData(void *b, uint n) = 0;
	virtual uint getLength() = 0;
	virtual uint getPosition() = 0;
	virtual uint seekPos(uint p, uint from) = 0;

	virtual ~JSURandomInputStream();
	virtual uint getAvailable();
	virtual void skip(int n);
};

struct JKRFile : public JKRDisposer {
	byte mStatus;

	virtual int open(char *fn) = 0;
	virtual void close() = 0;
	virtual u32 readData(void *param_1, long param_2, long param_3) = 0;
	virtual u32 writeData(void *param_1, long param_2, long param_3) = 0;
	virtual u32 getFileSize() = 0;

	virtual ~JKRFile();
};

struct JSUFileInputStream;

struct JKRDvdFile : public JKRFile {
	static JSUPtrList sDvdList;

	os::OSMutex mutex1, mutex2;

	//
	dvd::DVDFileInfo fileinfo;
	// might be an aliasing issue and this is actually a userptr from DVDFileInfo?
	// me from the future: self NEEDS to be right after fileinfo so that doneProcess can get a pointer to self
	// this is bad because it relies on alignment
	JKRDvdFile *self;
	//

	os::OSMessageQueue queue2;
	os::OSMessage msg2;
	os::OSMessageQueue queue1;
	os::OSMessage msg1;
	JSUPtrLink mLink;
	JKRAramBlock *aramAreaPointer;
	JSUFileInputStream *fileinputstream;
	os::OSThread *currentThread, *executionThread;
	int s2;

	static void doneProcess(s32 res, dvd::DVDFileInfo *info);

	virtual int open(char *fn);
	virtual uint open(uint id);
	virtual void close();
	virtual u32 readData(void *param_1, long param_2, long param_3);
	virtual u32 writeData(void *param_1, long length, long param_3);
	virtual u32 getFileSize();

	void initiate();
	JKRDvdFile();
	JKRDvdFile(char *param_1);
	JKRDvdFile(long param_1);

	uint sync();
};

struct JSUFileInputStream : public JSURandomInputStream {
	uint state0;
	JKRFile *filehandle;
	uint position;

	virtual uint getPosition();
	virtual uint readData(void *param_1, uint len) override;

	uint getLength();
	uint seekPos(uint param_1, uint param_2);
	JSUFileInputStream(JKRFile *file);
};