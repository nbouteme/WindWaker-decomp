#include <d_kyeff2.h>
#include <d_kankyo_wether.h>
#include <d_kyeff2.h>
#include <dKyeff2_c.h>


namespace d_kyeff2 {

/* __stdcall dKyeff2_Draw(dKyeff2_c *) */

undefined4 dKyeff2_Draw(void)

{
  d_kankyo_wether::dKyw_wether_draw2();
  return 1;
}

}

/* __thiscall dKyeff2_c::execute(void) */

undefined4 __thiscall dKyeff2_c::execute(dKyeff2_c *this)

{
  d_kankyo_wether::dKyw_wether_move_draw2();
  return 1;
}


namespace d_kyeff2 {

/* __stdcall dKyeff2_Execute(dKyeff2_c *) */

void dKyeff2_Execute(dKyeff2_c *param_1)

{
  ::dKyeff2_c::execute(param_1);
  return;
}


/* __stdcall dKyeff2_IsDelete(dKyeff2_c *) */

undefined4 dKyeff2_IsDelete(void)

{
  return 1;
}


/* __stdcall dKyeff2_Delete(dKyeff2_c *) */

undefined4 dKyeff2_Delete(void)

{
  d_kankyo_wether::dKyw_wether_delete2();
  return 1;
}


/* __stdcall dKyeff2_Create(kankyo_class *) */

undefined4 dKyeff2_Create(void)

{
  d_kankyo_wether::dKyw_wether_init2();
  return 4;
}

