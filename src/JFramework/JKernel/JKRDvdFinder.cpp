#include "JKRDvdFinder.h"

JKRDvdFinder::~JKRDvdFinder() {
	if (this->successfullyopened != '\0') {
		dvd::DVDCloseDir(&this->direntry);
	}
}

JKRDvdFinder::JKRDvdFinder(char *param_1) {
	bool bVar1 = dvd::DVDOpenDir(param_1, &this->direntry);
	this->successfullyopened = '\x01' - !bVar1;
	this->attribute = this->successfullyopened;
	findNextFile();
}

char JKRDvdFinder::findNextFile() {
	short sVar1;
	int iVar2;
	dvd::DVDDirEntry local_18;

	if (attribute != '\0') {
		iVar2 = dvd::DVDReadDir(&this->direntry, &local_18);
		attribute = '\x01' - (iVar2 == 0);
		if (attribute != '\0') {
			regFile = 1 - (local_18.isDir == 0);
			name = local_18.name;
			entryNum = local_18.entryNum;
			id = 0;
			sVar1 = 1;
			if (regFile != 0) {
				sVar1 = 2;
			}
			attr = sVar1;
		}
	}
	return attribute;
}
