#include "JUTResReference.h"

void *JUTResReference::getResource(JSUInputStream *param_1, ulong param_2, JKRArchive *param_3) {
	byte bVar1;

	param_1->read(&this->rtype, 1);
	param_1->read(&this->typelen, 1);
	param_1->read(this->type, (uint)(byte)this->typelen);
	bVar1 = this->rtype;
	if (((bVar1 == 2) || (bVar1 == 3)) || (bVar1 == 4)) {
		this->type[(byte)this->typelen] = '\0';
	}
	getResource(param_2, param_3);
}

void *JUTResReference::getResource(ulong param_1, JKRArchive *param_2) {
	byte bVar1;
	void *iVar2;

	iVar2 = 0;
	bVar1 = this->rtype;
	if (bVar1 == 3) {
		iVar2 = JKRFileLoader::getGlbResource(this->type, param_2);
	} else if (bVar1 < 3) {
		if ((bVar1 != 1) && (bVar1 != 0)) {
			iVar2 = JKRArchive::getGlbResource(param_1, this->type, param_2);
		}
	} else if (bVar1 < 5) {
		iVar2 = JKRFileLoader::getGlbResource(this->type);
	}
	return iVar2;
}
