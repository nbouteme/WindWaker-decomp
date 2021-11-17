#include <MSL_C.PPCEABI.bare.H/misc_io.h>
#include <MSL_C.PPCEABI.bare.H/ansi_files.h>


namespace MSL_C.PPCEABI.bare.H {

void __stdio_atexit(void)

{
  __stdio_exit = __close_all;
  return;
}

