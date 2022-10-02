#include <dirent.h>
#include <dolphin/dvd.h>
#include <fcntl.h>
#include <unistd.h>

#include <cstdio>
#include <cstdlib>

namespace dvd {
	bool DVDChangeDir(char const* a) {
		chdir(a);
	}

	bool DVDCheckDisk() {
		return true;
	}

	bool DVDFastOpen(int uid, dvd::DVDFileInfo* info) {
		info->startAddr = uid;
		return true;
	}

	DVDDiskID* DVDGetCurrentDiskID() {
		static DVDDiskID data = {
			{'G', 'Z', 'L', 'E'},
			{'0', '1'},
			0,
			99,
			0,
			0};
		return &data;
	}

	void DVDInit() {
		puts("Initializing DVD");
	}

	bool DVDReadAsyncPrio(dvd::DVDFileInfo* info, void* dest, int len, int offset, void (*cb)(int, dvd::DVDFileInfo*), int) {
		lseek(info->startAddr, offset, SEEK_SET);
		int l = read(info->startAddr, dest, len);
		cb(l, info);
		return true;
	}

	bool DVDClose(dvd::DVDFileInfo* info) {
		close(info->startAddr);
	}

	int DVDConvertPathToEntrynum(char const* path) {
		return open(path, O_RDONLY);
	}

	int DVDGetCommandBlockStatus(dvd::DVDCommandBlock const*) {
		return 0;
	}

	bool DVDOpen(char const* str, dvd::DVDFileInfo* info) {
		info->startAddr = DVDConvertPathToEntrynum(str);
	}

	bool DVDCloseDir(dvd::DVDDir* dir) {
		close(dir->entryNum);
		return true;
	}

	int DVDGetDriveStatus() {
		return 0;
	}

	bool DVDOpenDir(char const* path, dvd::DVDDir* dir) {
		*(void**)dir = (void*)opendir(path);
		return true;
	}

	bool DVDReadDir(dvd::DVDDir* dir, dvd::DVDDirEntry* entries) {
		DIR* dirp = *(DIR**)dir;
		auto ent = readdir(dirp);
		if (!ent)
			return false;
		entries->isDir = (ent->d_type | DT_DIR) != 0;
		entries->entryNum = ent->d_ino;
		entries->name = ent->d_name;
		return true;
	}

	int DVDReadPrio(dvd::DVDFileInfo* info, void* dest, int len, int offset, int) {
		lseek(info->startAddr, offset, SEEK_SET);
		return read(info->startAddr, dest, len);
	}
}