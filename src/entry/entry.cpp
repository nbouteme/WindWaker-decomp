#include <dolphin/os.h>
#include <doltypes.h>

#include <cstdlib>

#include "../machine/dolphin/main.h"
#include <mcheck.h>

#ifdef DOLPHIN
int state44;

int _start(int argc, char const *argv[]) {
	int iVar1;
	undefined4 uVar2;
	int *piVar3;
	int iVar4;
	int *piVar5;
	int iVar6;
	undefined8 uVar7;

	FUN_80003278();
	FUN_80003354();
	uVar7 = FUN_80003294();
	state44 = 0;
	if (DAT_800000f4 == 0) {
		iVar1 = DAT_800030e8;
		if (DAT_80000034 != 0)
			goto LAB_800031a8;
	} else {
		iVar1 = *(int *)(DAT_800000f4 + 0xc);
	LAB_800031a8:
		uVar2 = 0;
		if (iVar1 != 2) {
			if (iVar1 != 3)
				goto LAB_800031d0;
			uVar2 = 1;
		}
		TRK_MINNOW_DOLPHIN::InitMetroTRK((int)((ulonglong)uVar7 >> 0x20), (int)uVar7, uVar2);
	}
LAB_800031d0:
	iVar1 = DAT_800000f4;
	if ((DAT_800000f4 != 0) && (*(int *)(DAT_800000f4 + 8) != 0)) {
		piVar3 = (int *)(DAT_800000f4 + *(int *)(DAT_800000f4 + 8));
		iVar4 = *piVar3;
		if (iVar4 != 0) {
			piVar5 = piVar3 + 1;
			iVar6 = iVar4;
			do {
				piVar3 = piVar3 + 1;
				*piVar3 = *piVar3 + iVar1;
				iVar6 = iVar6 + -1;
			} while (iVar6 != 0);
			DAT_80000034 = (uint)piVar5 & 0xffffffe0;
			goto LAB_80003238;
		}
	}
	iVar4 = 0;
	piVar5 = (int *)0x0;
LAB_80003238:
	db::DBInit();
	os::OSInit();
	if (((DAT_800030e6 & 0x8000) == 0) || ((DAT_800030e6 & 0x7fff) == 1)) {
		FUN_80003100();
	}

	os::__init_user();
	iVar1 = m_Do_main::main(iVar4, piVar5);
	exit(iVar1);
}
#else
#include <cstdio>

int main(int ac, char **av) {
	os::OSInit();
	return m_Do_main::main(ac, &ac);
}
#endif