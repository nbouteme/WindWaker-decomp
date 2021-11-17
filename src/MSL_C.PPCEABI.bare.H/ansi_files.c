#include <MSL_C.PPCEABI.bare.H/ansi_files.h>
#include <MSL_C.PPCEABI.bare.H/file_io.h>
#include <MSL_C.PPCEABI.bare.H/alloc.h>


namespace MSL_C.PPCEABI.bare.H {
undefined stderr_buff;
undefined stdout_buff;
undefined stdin_buff;

undefined4 __flush_all(void)

{
  FILE *__stream;
  int iVar1;
  undefined4 uVar2;
  
  __stream = (FILE *)&__files;
  uVar2 = 0;
  while( true ) {
    if (__stream == (FILE *)0x0) break;
    if (((*(ushort *)&__stream->_IO_read_ptr >> 6 & 7) != 0) &&
       (iVar1 = fflush(__stream), iVar1 != 0)) {
      uVar2 = 0xffffffff;
    }
    __stream = *(FILE **)&__stream->_offset;
  }
  return uVar2;
}


void __close_all(void)

{
  FILE *pFVar1;
  FILE *__stream;
  
  pFVar1 = (FILE *)&__files;
  while( true ) {
    __stream = pFVar1;
    if (__stream == (FILE *)0x0) break;
    if ((*(ushort *)&__stream->_IO_read_ptr >> 6 & 7) != 0) {
      fclose(__stream);
    }
    pFVar1 = *(FILE **)&__stream->_offset;
    if (*(char *)&__stream->_IO_read_base == '\0') {
      *(ushort *)&__stream->_IO_read_ptr = *(ushort *)&__stream->_IO_read_ptr & 0xfe3f | 0xc0;
      if ((pFVar1 != (FILE *)0x0) && (*(char *)&pFVar1->_IO_read_base != '\0')) {
        *(undefined4 *)&__stream->_offset = 0;
      }
    }
    else {
      free(__stream);
    }
  }
  return;
}

