#include <dolphin/card.h>
#define _GNU_SOURCE
#include <fcntl.h>
#include <unistd.h>

#include <cstdio>
#include <cstdlib>

namespace card {
	int CARDCreate(int id, char const* fn, unsigned int size, card::CARDFileInfo* info) {
		char* path;
		asprintf(&path, "%s_%d.dat", fn, id);
		int fd = open(path, O_RDWR);
		ftruncate(fd, size);
		free(path);
		return CARD_RESULT_READY;
	}

	int CARDFormat(int) {
		return CARD_RESULT_READY;
	}

	int CARDFreeBlocks(int, int* a, int* b) {
		*a = 4096;
		*b = 4096;
		return CARD_RESULT_READY;
	}

	int CARDGetSerialNo(int a, unsigned long long* b) {
		*b = 0xDEADBEEFDEADBEEF + a;
		return CARD_RESULT_READY;
	}

	void CARDInit() {
		puts("Initing CARD");
	}

	struct {
		void* work_area;
		void (*detach)(int, int);
	} wa[2];

	int CARDMount(int a, void* b, void (*cb)(int, int)) {
		wa[a] = {
			b, cb};
		return CARD_RESULT_READY;
	}

	int CARDProbeEx(int a, int* b, int* c) {
		*b = 128;
		*c = 8;
	}

	int CARDSetStatus(int c, int fo, card::CARDStat* sta) {
		if (fo < 0) {
			return CARD_RESULT_NOFILE;
		}

		lseek(fo, 0, SEEK_SET);
		write(fo, sta, sizeof(*sta));
		return CARD_RESULT_READY;
	}

	int CARDUnmount(int) {
		return CARD_RESULT_READY;
	}

	int CARDCheck(int) {
		return CARD_RESULT_READY;
	}

	int CARDGetStatus(int c, int fo, card::CARDStat* sta) {
		if (fo < 0) {
			return CARD_RESULT_NOFILE;
		}

		lseek(fo, 0, SEEK_SET);
		read(fo, sta, sizeof(*sta));
		return CARD_RESULT_READY;
	}

	bool CARDProbe(int) {
		return true;
	}

	int CARDClose(card::CARDFileInfo* info) {
		if (info->fileNo >= 0)
			close(info->fileNo);
		return CARD_RESULT_READY;
	}

	int CARDOpen(int c, char const* path, card::CARDFileInfo* info) {
		char* rpath;
		asprintf(&rpath, "save%d/%s.dat", c, path);
		free(rpath);
		info->fileNo = open(rpath, O_RDWR | O_CREAT, 0644);
		if (info->fileNo < 0)
			return CARD_RESULT_NOFILE;
		return CARD_RESULT_READY;
	}

	int CARDRead(card::CARDFileInfo* info, void* buff, int len, int offset) {
		lseek(info->fileNo, sizeof(card::CARDStat) + offset, SEEK_SET);
		read(info->fileNo, buff, len);
		return CARD_RESULT_READY;
	}

	int CARDWrite(card::CARDFileInfo* info, void const* buff, int len, int offset) {
		lseek(info->fileNo, sizeof(card::CARDStat) + offset, SEEK_SET);
		write(info->fileNo, buff, len);
		return CARD_RESULT_READY;
	}

}