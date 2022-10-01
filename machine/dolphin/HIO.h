#pragma once

struct JORReflexible {};

struct mDoHIO_child_c {
	char mName[24];

	JORReflexible *mReflexible;
};

struct mDoHIO_subRoot_c {
	mDoHIO_child_c mChild[64];

	void deleteChild(char param_1);
	int createChild(char *param_1, JORReflexible *param_2);
};

struct mDoHIO_root_c {
	mDoHIO_subRoot_c subroot;
	void update();
	virtual ~mDoHIO_root_c();
};

namespace m_Do_hostIO {
	extern mDoHIO_root_c mDoHIO_root;
}