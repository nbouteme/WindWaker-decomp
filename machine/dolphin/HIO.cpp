#include "HIO.h"
#include "printf.h"
#include <cstring>

void mDoHIO_root_c::update() {}
mDoHIO_root_c::~mDoHIO_root_c() {}

void mDoHIO_subRoot_c::deleteChild(char param_1) {
	if (param_1 > 0) {
		if (!this->mChild[param_1].mReflexible) {
			m_Do_printf::OSReport_Error("危険：すでに削除されているホストIOをさらに削除しようとしています<%s>\n", this->mChild + param_1);
		} else {
			this->mChild[param_1].mReflexible = (JORReflexible *)0x0;
		}
	}
}

int mDoHIO_subRoot_c::createChild(char *param_1, JORReflexible *param_2) {
	int iVar1;
	mDoHIO_subRoot_c *pRoot;
	char cVar2;
	int iVar3;

	iVar1 = 0;
	iVar3 = 0x40;

	// check if was added before
	do {
		if (this->mChild[iVar1].mReflexible == param_2) {
			m_Do_printf::OSReport_Error(
				"危険：既に登録されているホストIOをふたたび登録しようとしています<%s>\n");
			return -1;
		}
		iVar1 = iVar1++;
		iVar3 = iVar3 + -1;
	} while (iVar3 != 0);

	cVar2 = 0;
	iVar1 = 0;
	iVar3 = 0x40;
	do {
		if (!this->mChild[cVar2].mReflexible) {
			strncpy(this->mChild[cVar2].mName, param_1, 0x18);
			this->mChild[0].mReflexible = param_2;
			return cVar2;
		}
		cVar2 = cVar2 + 1;
		iVar3 = iVar3 + -1;
	} while (iVar3 != 0);
	// no space left
	m_Do_printf::OSReport_Error("ホストIOの空きエントリがありません。登録できませんでした。\n");
	return -1;
}
