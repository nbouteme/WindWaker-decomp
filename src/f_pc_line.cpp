#include <f_pc_line.h>
#include <SComponent/c_list.h>


namespace f_pc_line {
struct node_list_class l_fpcLn_Line;

/* __stdcall fpcLn_Create(void) */

void fpcLn_Create(void)

{
  bool bVar1;
  node_list_class *pnVar2;
  int iVar3;
  
  iVar3 = 0xf;
  pnVar2 = &l_fpcLn_Line;
  do {
    SComponent::cLs_Create(pnVar2);
    bVar1 = 0 < iVar3;
    iVar3 = iVar3 + -1;
    pnVar2 = pnVar2 + 1;
  } while (bVar1);
  return;
}

