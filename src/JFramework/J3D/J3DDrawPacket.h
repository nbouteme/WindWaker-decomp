#pragma once

#include "J3DDisplayListObj.h"
#include "J3DPacket.h"

struct J3DDrawPacket : public J3DPacket {
	int mFlags;
	J3DDisplayListObj *mpDLObj;

	void draw();
	int newDisplayList(unsigned param_1);
    int newSingleDisplayList(unsigned param_1);
};