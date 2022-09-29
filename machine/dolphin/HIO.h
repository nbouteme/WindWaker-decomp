#pragma once

struct mDoHIO_root_c {
    mDoHIO_subRoot_c subroot;
	void update() {}
	virtual ~mDoHIO_root_c() {}
};

struct JORReflexible {};

struct mDoHIO_child_c {
	char mName[24];

	JORReflexible *mReflexible;
};

struct mDoHIO_subRoot_c {
	mDoHIO_child_c mChild[64];

	void deleteChild(char param_1) {
		if (param_1 > 0) {
			if (!this->mChild[param_1].mReflexible) {
				m_Do_printf::OSReport_Error("危険：すでに削除されているホストIOをさらに削除しようとしています<%s>\n", this->mChild + param_1);
			} else {
				this->mChild[param_1].mReflexible = (JORReflexible *)0x0;
			}
		}
	}

	int createChild(char *param_1, JORReflexible *param_2) {
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
};

namespace m_Do_hostIO {
	mDoHIO_root_c mDoHIO_root;
}