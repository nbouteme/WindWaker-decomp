#pragma once
#include <ctypes.h>

#include <node_list_class.h>
#include <node_lists_tree_class.h>


namespace f_pc_line {
//[Data] Expected size is 0x000008
extern struct node_lists_tree_class g_fpcLn_Queue;

//[BSS] Expected size is 0x0000c0
extern struct node_list_class l_fpcLn_Line;
void fpcLn_Create(void);
}
