#include <f_op_draw_iter.h>
#include <f_op_draw_iter.h>


namespace f_op_draw_iter {
undefined4 l_fopDwTg_id;

/* __stdcall fopDwIt_GetTag(void) */

node_class * fopDwIt_GetTag(void)

{
  do {
    if (f_op_draw_tag::g_fopDwTg_Queue.mNumLists <= l_fopDwTg_id + 1) {
      return (node_class *)0x0;
    }
    l_fopDwTg_id = l_fopDwTg_id + 1;
  } while (f_op_draw_tag::g_fopDwTg_Queue.mpLists[l_fopDwTg_id].mpHead == (node_class *)0x0);
  return f_op_draw_tag::g_fopDwTg_Queue.mpLists[l_fopDwTg_id].mpHead;
}


/* __stdcall fopDwIt_Begin(void) */

void fopDwIt_Begin(void)

{
  l_fopDwTg_id = 0;
  if ((f_op_draw_tag::g_fopDwTg_Queue.mpLists)->mpHead == (node_class *)0x0) {
    fopDwIt_GetTag();
  }
  return;
}


/* __stdcall fopDwIt_Next(create_tag_class *) */

node_class * fopDwIt_Next(create_tag_class *param_1)

{
  node_class *pnVar1;
  
  pnVar1 = (param_1->parent).mpNextNode;
  if (pnVar1 == (node_class *)0x0) {
    pnVar1 = fopDwIt_GetTag();
  }
  return pnVar1;
}

