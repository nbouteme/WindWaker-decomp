#pragma once

#include <dolphin/dvd.h>

#include "JKRArchive.h"

struct JKRDvdFinder : public JKRFileFinder {
	dvd::DVDDir direntry;
	byte successfullyopened;

	virtual ~JKRDvdFinder();

	JKRDvdFinder(char *param_1);

	virtual char findNextFile() override;
};