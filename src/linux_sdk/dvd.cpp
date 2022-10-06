#include <dirent.h>
#include <dolphin/dvd.h>
#include <fcntl.h>
#include <unistd.h>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sys/stat.h>

const char rootdir[] = "/home/lillie/rev/ww.iso-ext/files";
const char* cwd;

namespace dvd {

	bool DVDChangeDir(char const* a) {
		chdir(a);
		free((void*)cwd);
		cwd = strdup(a);
		return true;
	}

	bool DVDCheckDisk() {
		return true;
	}

	bool DVDFastOpen(int uid, dvd::DVDFileInfo* info) {
		struct stat s;
		info->startAddr = uid;
		fstat(uid, &s);
		info->length = s.st_size;
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
		cwd = strdup("/");
	}

	bool DVDReadAsyncPrio(dvd::DVDFileInfo* info, void* dest, int len, int offset, void (*cb)(int, dvd::DVDFileInfo*), int) {
		lseek(info->startAddr, offset, SEEK_SET);
		int l = read(info->startAddr, dest, len);
		cb(l, info);
		return true;
	}

	bool DVDClose(dvd::DVDFileInfo* info) {
		close(info->startAddr);
		return true;
	}

	int DVDConvertPathToEntrynum(char const* path) {
		// hack: what's known as the "files" folder seems to be internally refered as "/dvd"? but sometimes it's omitted?
		if (path[0] == '/' && path[1] == 'd' && path[2] == 'v' && path[3] == 'd')
			path += 4;

		std::string fdir;
		if (path[0] == '/')
			fdir = std::string(rootdir) + (path);
		else
			fdir = std::string(rootdir) + cwd + "/" + (path);
		return open(fdir.c_str(), O_RDONLY);
	}

	int DVDGetCommandBlockStatus(dvd::DVDCommandBlock const*) {
		return 0;
	}

	bool DVDOpen(char const* str, dvd::DVDFileInfo* info) {
		struct stat s;
		int uid = DVDConvertPathToEntrynum(str);
		info->startAddr = uid;
		fstat(uid, &s);
		info->length = s.st_size;
		return info->startAddr != ~0u;
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
		entries->isDir = (ent->d_type & DT_DIR) != 0;
		entries->entryNum = ent->d_ino;
		entries->name = ent->d_name;
		return true;
	}

	int DVDReadPrio(dvd::DVDFileInfo* info, void* dest, int len, int offset, int) {
		lseek(info->startAddr, offset, SEEK_SET);
		return read(info->startAddr, dest, len);
	}
}