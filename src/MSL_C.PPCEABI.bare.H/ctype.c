#include <MSL_C.PPCEABI.bare.H/ctype.h>


namespace MSL_C.PPCEABI.bare.H {

int tolower(int __c)

{
  if (__c == -1) {
    return 0xffffffff;
  }
  return (uint)(byte)(&__lower_map)[__c & 0xff];
}

