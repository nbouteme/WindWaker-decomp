#pragma once

#include <JFramework/JKernel/JKRArchive.h>
#include <JFramework/JSupport/JSUIosBase.h>

struct JUTResReference {
	byte rtype;
	byte typelen;
	char type[4];

	void *getResource(JSUInputStream *param_1, ulong param_2, JKRArchive *param_3);

	void *getResource(ulong param_1, JKRArchive *param_2);
};