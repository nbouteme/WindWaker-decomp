#pragma once

#include <SComponent.h>

struct draw_priority_class {
	ushort mPriority;
};

struct leafdraw_class : public base_process_class {
	profile_leaf_method_class *mpSubMtd;
	byte a, b;
	draw_priority_class mDwPi;
};

namespace f_pc_leaf {
	extern int g_fpcLf_type;
}
