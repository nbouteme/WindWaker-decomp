#include <SComponent/c_list_iter.h>
#include <SComponent/c_node_iter.h>


namespace SComponent {

/* __stdcall cLsIt_Method(node_list_class *,
                          int *(node_class *,void *),
                          void *) */

undefined4 cLsIt_Method(node_list_class *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (param_1->mSize < 1) {
    uVar1 = 1;
  }
  else {
    uVar1 = cNdIt_Method(param_1->mpHead,param_2,param_3);
  }
  return uVar1;
}


/* __stdcall cLsIt_Judge(node_list_class *,
                         void * *(node_class *,void *),
                         void *) */

void * cLsIt_Judge(node_list_class *param_1,undefined *param_2,void *param_3)

{
  void *pvVar1;
  
  if (param_1->mSize < 1) {
    pvVar1 = (void *)0x0;
  }
  else {
    pvVar1 = (void *)cNdIt_Judge(param_1->mpHead,param_2,param_3);
  }
  return pvVar1;
}

