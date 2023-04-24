#include "J3DDrawPacket.h"

#include "../JKernel/JKernel.h"

void J3DDrawPacket::draw() {
	this->mpDLObj->callDL();
}

int J3DDrawPacket::newDisplayList(unsigned param_1) {
	int iVar2;
	int iVar3;

	J3DDisplayListObj *pJVar1 = new J3DDisplayListObj();
	if (pJVar1) {
		pJVar1->mpData[0] = (void *)0x0;
		pJVar1->mpData[1] = (void *)0x0;
		pJVar1->mSize = 0;
		pJVar1->mCapacity = 0;
	}
	this->mpDLObj = pJVar1;
	if (!this->mpDLObj) {
		return 4;
	} else {
		iVar2 = this->mpDLObj->newDisplayList(param_1);
		iVar3 = 0;
		if (iVar2 != 0) {
			iVar3 = iVar2;
		}
	}
	return iVar3;
}

int J3DDrawPacket::newSingleDisplayList(unsigned param_1) {
	int iVar2;
	int iVar3;

	// the original code may have a path in which the return value
	//  is unassigned, but unlikely
	J3DDisplayListObj *pJVar1 = new J3DDisplayListObj();
	if (pJVar1) {
		pJVar1->mpData[0] = nullptr;
		pJVar1->mpData[1] = nullptr;
		pJVar1->mSize = 0;
		pJVar1->mCapacity = 0;
	}
	this->mpDLObj = pJVar1;
	if (!this->mpDLObj) {
		return 4;
	} else {
		iVar2 = this->mpDLObj->newSingleDisplayList(param_1);
		iVar3 = 0;
		if (iVar2) {
			return 0;
		}
	}
	return iVar3;
}