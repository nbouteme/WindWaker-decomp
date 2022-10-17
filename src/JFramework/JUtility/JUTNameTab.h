#pragma once

#include <d_resorce.h>

struct JUTNameTab {
	ResNTAB *mpRes;
	byte *mpStrData;
	short mCount;

	short calcKeyCode(char *param_1) {
		short sVar1;

		sVar1 = 0;
		while (*param_1) {
			sVar1 = *param_1 + sVar1 * 3;
			param_1++;
		}
		return sVar1;
	}

	int getIndex(char *param_1) {
		ulong uVar1;
		short sVar4;
		int iVar3;
		ushort uVar5;

		if (!this->mpRes) {
			auto uVar1 = JUTAssertion::getSDevice();
			JUTAssertion::showAssert(uVar1, "JUTNameTab.cpp", 0x65, "mNameTable != 0");
			m_Do_printf::OSPanic("JUTNameTab.cpp", 0x65, "Halt");
		}
		sVar4 = calcKeyCode(param_1);
		uVar5 = 0;
		while (true) {
			auto pRVar2 = &mpRes->mEntries[uVar5];
			if ((ushort)this->mCount <= uVar5) {
				return -1;
			}
			if ((pRVar2->hash == sVar4) &&
				(!strcmp(((char *)mpRes) + pRVar2->stroffset, param_1)))
				break;
			uVar5++;
		}
		return (uint)uVar5;
	}
};
