#include "method.h"

namespace f_pc_method_iter {
	int fpcMtdIt_Method(node_list_class *param_1, SComponent::Method *param_2) {
		return SComponent::cLsIt_Method(param_1, param_2, 0);
	}
}