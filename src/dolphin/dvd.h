#pragma once

#include <doltypes.h>

#undef EMU

namespace dvd {

	typedef struct DVDDiskID DVDDiskID;

	struct DVDDiskID {
		char gameName[4];
		char company[2];
		u8 diskNumber;
		u8 gameVersion;
		u8 streaming;
		u8 streamingBufSize;  // 0 = default
		u8 padding[22];		  // 0's are stored
	};

	typedef struct DVDCommandBlock DVDCommandBlock;

	typedef void (*DVDCBCallback)(s32 result, DVDCommandBlock* block);

	struct DVDCommandBlock {
		DVDCommandBlock* next;
		DVDCommandBlock* prev;
		u32 command;
		s32 state;
		u32 offset;
		u32 length;
		void* addr;
		u32 currTransferSize;
		u32 transferredSize;
		DVDDiskID* id;
		DVDCBCallback callback;
		void* userData;
	};

	typedef struct DVDFileInfo DVDFileInfo;

	/*---------------------------------------------------------------------------*
  Name:         DVDCallback

  Description:  DVD callback function

  Arguments:    result      If the function that set the callback succeeds,
                            it is the number of bytes transferred. If that
                            function fails, it is -1.

  Returns:      None.
 *---------------------------------------------------------------------------*/
	typedef void (*DVDCallback)(s32 result, DVDFileInfo* fileInfo);

	struct DVDFileInfo {
#ifndef MACOS
		DVDCommandBlock cb;
#endif

		u32 startAddr;	// disk address of file
		u32 length;		// file size in bytes

#ifdef MACOS
		DVDFileInfo* next;
#endif	// MACOS
		DVDCallback callback;

#ifdef WIN32
		FILE* file;
#endif

#ifdef MACOS
		IOParam pb;
#endif	// MACOS
	};

	typedef struct
	{
		u32 entryNum;
		u32 location;
		u32 next;
	} DVDDir;

	typedef struct
	{
		u32 entryNum;
		BOOL isDir;
		char* name;
	} DVDDirEntry;

// FST maximum size
#ifndef MINNOW
#define DVD_FST_MAX_SIZE 0x00100000
#else  // MINNOW
#define DVD_FST_MAX_SIZE 0x00080000
#endif

#define DVD_MIN_TRANSFER_SIZE 32

#define DVD_STATE_FATAL_ERROR -1
#define DVD_STATE_END 0
#define DVD_STATE_BUSY 1
#define DVD_STATE_WAITING 2
#define DVD_STATE_COVER_CLOSED 3  // internal state. never returns.
#define DVD_STATE_NO_DISK 4
#define DVD_STATE_COVER_OPEN 5
#define DVD_STATE_WRONG_DISK 6
#define DVD_STATE_MOTOR_STOPPED 7
#define DVD_STATE_PAUSING 8
#define DVD_STATE_IGNORED 9
#define DVD_STATE_CANCELED 10
#define DVD_STATE_RETRY 11

#define DVD_FILEINFO_READY 0
#define DVD_FILEINFO_BUSY 1

#define DVD_RESULT_GOOD 0
#define DVD_RESULT_FATAL_ERROR -1
#define DVD_RESULT_IGNORED -2
#define DVD_RESULT_CANCELED -3

#define DVD_AIS_SUCCESS 0x0

#define DVDGetStartAddr(fileInfo) \
	((fileInfo)->startAddr)

#define DVDGetLength(fileInfo) \
	((fileInfo)->length)

	void DVDInit(void);

	BOOL DVDOpen(const char* fileName, DVDFileInfo* fileInfo);
	BOOL DVDFastOpen(s32 entrynum, DVDFileInfo* fileInfo);

#ifndef MACOS
	s32 DVDReadPrio(DVDFileInfo* fileInfo, void* addr, s32 length,
					s32 offset, s32 prio);

	BOOL DVDReadAsyncPrio(DVDFileInfo* fileInfo, void* addr, s32 length,
						  s32 offset,
						  DVDCallback callback, s32 prio);

#define DVDRead(fileInfo, addr, length, offset) \
	DVDReadPrio((fileInfo), (addr), (length), (offset), 2)
#define DVDReadAsync(fileInfo, addr, length, offset, callback) \
	DVDReadAsyncPrio((fileInfo), (addr), (length), (offset), (callback), 2)
#else
	s32 DVDRead(DVDFileInfo* fileInfo, void* addr, s32 length,
				s32 offset);

	BOOL DVDReadAsync(DVDFileInfo* fileInfo, void* addr, s32 length,
					  s32 offset,
					  DVDCallback callback);
#endif

	BOOL DVDClose(DVDFileInfo* fileInfo);

#ifndef MACOS
	BOOL DVDGetCurrentDir(char* path, u32 maxlen);
#endif

	BOOL DVDChangeDir(const char* dirName);

#ifdef MACOS
	BOOL DVDMovePickup(DVDFileInfo* fileInfo,
					   s32 offset,
					   DVDCallback callback);
#else  // EPPC
	s32 DVDSeekPrio(DVDFileInfo* fileInfo,
					s32 offset, s32 prio);

	BOOL DVDSeekAsyncPrio(DVDFileInfo* fileInfo,
						  s32 offset,
						  DVDCallback callback, s32 prio);

#define DVDSeek(fileInfo, offset) \
	DVDSeekPrio((fileInfo), (offset), 2)
#define DVDSeekAsync(fileInfo, offset, callback) \
	DVDSeekAsyncPrio((fileInfo), (offset), (callback), 2)

	s32 DVDChangeDisk(DVDCommandBlock* block, DVDDiskID* id);

	BOOL DVDChangeDiskAsync(DVDCommandBlock* block, DVDDiskID* id,
							DVDCBCallback callback);
#endif

	s32 DVDGetCommandBlockStatus(const DVDCommandBlock* block);

	s32 DVDGetFileInfoStatus(const DVDFileInfo* fileInfo);

#define DVDGetFileInfoStatus(fileinfo) \
	DVDGetCommandBlockStatus(&(fileinfo)->cb)

	s32 DVDGetDriveStatus(void);

	BOOL DVDSetAutoInvalidation(BOOL autoInval);

	void* DVDGetFSTLocation(void);

#ifdef MACOS
	void DVDSetRoot(const char* rootPath);
#endif
#ifdef WIN32
	void DVDSetRoot(const char* rootPath);
#endif

	s32 DVDConvertPathToEntrynum(const char* pathPtr);

	// Directory access functions
	BOOL DVDOpenDir(const char* dirName, DVDDir* dir);
	BOOL DVDFastOpenDir(s32 entrynum, DVDDir* dir);
	BOOL DVDReadDir(DVDDir* dir, DVDDirEntry* dirent);
	BOOL DVDCloseDir(DVDDir* dir);

	void DVDPause(void);
	void DVDResume(void);

/*---------------------------------------------------------------------------*
  Name:         DVDTellDir

  Description:  Returns the current location associated with the directory

  Arguments:    dir         Pre-opened DVDDir* structure

  Returns:      current location
 *---------------------------------------------------------------------------*/
#define DVDTellDir(dir) ((dir)->location)

/*---------------------------------------------------------------------------*
  Name:         DVDSeekDir

  Description:  Sets the position of the next DVDReadDir on the directory

  Arguments:    dir         Pre-opened DVDDir* structure
                loc         location to set

  Returns:      None
 *---------------------------------------------------------------------------*/
#define DVDSeekDir(dir, loc) ((dir)->location = loc)

	/*---------------------------------------------------------------------------*
  Name:         DVDRewindDir

  Description:  Resets the position of the directory to the beginning

  Arguments:    dir         Pre-opened DVDDir* structure

  Returns:      None
 *---------------------------------------------------------------------------*/
	void DVDRewindDir(DVDDir* dir);

#define DVDGetDirEntryName(dirent) ((dirent)->name)
#define DVDDirEntryIsDir(dirent) ((dirent)->isDir)

/*---------------------------------------------------------------------------*
  Name:         DVDSetUserData

  Description:  Set user data in command block

  Arguments:    block       Command block
                data        Data to set

  Returns:      None
 *---------------------------------------------------------------------------*/
#define DVDSetUserData(block, data) ((block)->userData = (data))

/*---------------------------------------------------------------------------*
  Name:         DVDGetUserData

  Description:  Get user data in command block

  Arguments:    block       Command block

  Returns:      data (void * type)
 *---------------------------------------------------------------------------*/
#define DVDGetUserData(block) ((block)->userData)

#ifndef EMU
	BOOL DVDPrepareStreamAsync(DVDFileInfo* fInfo, u32 length, u32 offset, DVDCallback callback);
	s32 DVDPrepareStream(DVDFileInfo* fInfo, u32 length, u32 offset);

	BOOL DVDCancelStreamAsync(DVDCommandBlock* block, DVDCBCallback callback);
	s32 DVDCancelStream(DVDCommandBlock* block);

	BOOL DVDStopStreamAtEndAsync(DVDCommandBlock* block, DVDCBCallback callback);
	s32 DVDStopStreamAtEnd(DVDCommandBlock* block);

	BOOL DVDGetStreamErrorStatusAsync(DVDCommandBlock* block, DVDCBCallback callback);
	s32 DVDGetStreamErrorStatus(DVDCommandBlock* block);

	BOOL DVDGetStreamPlayAddrAsync(DVDCommandBlock* block, DVDCBCallback callback);
	s32 DVDGetStreamPlayAddr(DVDCommandBlock* block);

#define DVDInitStream(fInfo, length, offset, callback) \
	DVDPrepareStreamAsync(fInfo, length, offset, callback)

	BOOL DVDCancelAsync(DVDCommandBlock* block, DVDCBCallback callback);
	s32 DVDCancel(DVDCommandBlock* block);
	BOOL DVDCancelAllAsync(DVDCBCallback callback);
	s32 DVDCancelAll(void);

	s32 DVDGetTransferredSize(DVDFileInfo* fileinfo);

	DVDDiskID* DVDGetCurrentDiskID(void);

	void DVDDumpWaitingQueue(void);

	BOOL DVDCheckDisk(void);

	BOOL DVDCompareDiskID(const DVDDiskID* id1, const DVDDiskID* id2);

	DVDDiskID* DVDGenerateDiskID(DVDDiskID* id, const char* game, const char* company,
								 u8 diskNum, u8 version);

	BOOL DVDSetAutoFatalMessaging(BOOL enable);

#endif

}