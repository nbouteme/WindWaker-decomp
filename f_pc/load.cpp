#include "load.h"

#include <c_dylink.h>

namespace f_pc_load {
	void fpcLd_Free(ushort param_1, char *param_2) {
		c_dylink::cDyl_Unlink(param_1, param_2);
	}
}