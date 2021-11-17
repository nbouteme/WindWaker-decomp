#include <SComponent/c_request.h>
#include <SComponent/c_request.h>


namespace SComponent {

/* __stdcall cReq_Is_Done(request_base_class *) */

undefined4 cReq_Is_Done(request_base_class *param_1)

{
  if ((param_1->mFlags >> 6 & 1) == 1) {
    param_1->mFlags = param_1->mFlags & 0xbf;
    return 1;
  }
  return 0;
}


/* __stdcall cReq_Done(request_base_class *) */

void cReq_Done(request_base_class *param_1)

{
  param_1->mFlags = param_1->mFlags & 0x7f;
  param_1->mFlags = param_1->mFlags & 0xbf | 0x40;
  param_1->mFlags = param_1->mFlags & 0xc0;
  return;
}


/* __stdcall cReq_Command(request_base_class *,
                          unsigned char) */

void cReq_Command(request_base_class *param_1,undefined4 param_2)

{
  cReq_Create(param_1,param_2);
  return;
}


/* __stdcall cReq_Create(request_base_class *,
                         unsigned char) */

void cReq_Create(request_base_class *param_1,undefined4 param_2)

{
  param_1->mFlags = param_1->mFlags & 0x7f | 0x80;
  param_1->mFlags = param_1->mFlags & 0xbf;
  param_1->mFlags = (byte)param_2 & 0x3f | param_1->mFlags & 0xc0;
  return;
}

