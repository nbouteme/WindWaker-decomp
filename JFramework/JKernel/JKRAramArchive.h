#pragma once

#include <cmath>
#include <cstring>

#include "JKRAram.h"
#include "JKRArchive.h"
#include "JKRDvdAramRipper.h"
#include "JKRDvdRipper.h"

// maybe i shouldn't bother with that as it wont be used well after boot

// oh well, it's basically copy pasted JKRDvdArchive but with aram targets

struct JKRAramArchive : public JKRArchive {
	JKRDvdFile *dvdfile;

	int open(long __file);

	JKRAramArchive(long param_1, EMountDirection param_2);
};