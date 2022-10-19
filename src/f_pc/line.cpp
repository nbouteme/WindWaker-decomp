#include "line.h"

namespace f_pc_line {
	node_lists_tree_class g_fpcLn_Queue = {
		l_fpcLn_Line, 0x10};
	node_list_class l_fpcLn_Line[16];

	void fpcLn_Create() {
		for (int i = 0; i < 16; ++i) {
			SComponent::cLs_Create(l_fpcLn_Line + i);
		}
	}
}