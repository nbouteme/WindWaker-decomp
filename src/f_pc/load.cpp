#include "load.h"

#include <c_dylink.h>

namespace f_pc_load {
	void fpcLd_Free(ushort param_1, char *param_2) {
		c_dylink::cDyl_Unlink(param_1, param_2);
	}

	int fpcLd_Load(ushort param_1) {
		int iVar1;
		undefined4 uVar2;

		iVar1 = c_dylink::cDyl_LinkASync(param_1);
		if (iVar1 == 4) {
			uVar2 = 4;
		} else if ((iVar1 < 4) && (iVar1 == 0)) {
			uVar2 = 0;
		} else {
			uVar2 = 5;
		}
		return uVar2;
	}
}