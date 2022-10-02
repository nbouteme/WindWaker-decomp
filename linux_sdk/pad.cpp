#include <dolphin/pad.h>

#include <cstdio>

namespace pad {
	bool PADInit() {
		puts("Initializing PAD");
		return true;
	}

	bool PADRecalibrate(unsigned int) {
		return true;
	}

	void PADSetSpec(unsigned int) {
	}

	void PADSetAnalogMode(unsigned int) {
	}

}