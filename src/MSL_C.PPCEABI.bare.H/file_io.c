#include <MSL_C.PPCEABI.bare.H/file_io.h>
#include <MSL_C.PPCEABI.bare.H/ansi_files.h>
#include <MSL_C.PPCEABI.bare.H/FILE_POS.C.h>
#include <MSL_C.PPCEABI.bare.H/buffer_io.h>
#include <MSL_C.PPCEABI.bare.H/file_io.h>
#include <MSL_C.PPCEABI.bare.H/alloc.h>


namespace MSL_C.PPCEABI.bare.H {

int fflush(FILE *__stream)

{
  int iVar1;
  char *pcVar2;
  
  if (__stream == (FILE *)0x0) {
    iVar1 = __flush_all();
  }
  else {
    if ((*(char *)((int)&__stream->_IO_read_end + 2) == '\0') &&
       ((*(ushort *)&__stream->_IO_read_ptr >> 6 & 7) != 0)) {
      if ((*(byte *)&__stream->_IO_read_ptr >> 3 & 7) == 1) {
        iVar1 = 0;
      }
      else {
        if (2 < *(byte *)&__stream->_IO_read_end >> 5) {
          *(byte *)&__stream->_IO_read_end = *(byte *)&__stream->_IO_read_end & 0x1f | 0x40;
        }
        if (*(byte *)&__stream->_IO_read_end >> 5 == 2) {
          __stream->_IO_backup_base = (char *)0x0;
        }
        if (*(byte *)&__stream->_IO_read_end >> 5 == 1) {
          if ((*(ushort *)&__stream->_IO_read_ptr >> 6 & 7) == 1) {
            pcVar2 = (char *)ftell(__stream);
          }
          else {
            pcVar2 = (char *)0x0;
          }
          iVar1 = __flush_buffer(__stream,0);
          if (iVar1 == 0) {
            iVar1 = 0;
            *(byte *)&__stream->_IO_read_end = *(byte *)&__stream->_IO_read_end & 0x1f;
            __stream->_IO_write_end = pcVar2;
            __stream->_IO_backup_base = (char *)0x0;
          }
          else {
            *(undefined *)((int)&__stream->_IO_read_end + 2) = 1;
            iVar1 = -1;
            __stream->_IO_backup_base = (char *)0x0;
          }
        }
        else {
          iVar1 = 0;
          *(byte *)&__stream->_IO_read_end = *(byte *)&__stream->_IO_read_end & 0x1f;
        }
      }
    }
    else {
      iVar1 = -1;
    }
  }
  return iVar1;
}


int fclose(FILE *__stream)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if (__stream == (FILE *)0x0) {
    iVar1 = -1;
  }
  else {
    if ((*(ushort *)&__stream->_IO_read_ptr >> 6 & 7) == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = fflush(__stream);
      iVar2 = (**(code **)&__stream->_cur_column)(__stream->_flags);
      *(ushort *)&__stream->_IO_read_ptr = *(ushort *)&__stream->_IO_read_ptr & 0xfe3f;
      __stream->_flags = 0;
      if ((*(byte *)&__stream->_IO_read_end >> 4 & 1) != 0) {
        free(__stream->_IO_buf_base);
      }
      uVar3 = 0;
      if ((iVar1 != 0) || (iVar2 != 0)) {
        uVar3 = 1;
      }
      iVar1 = (int)(-uVar3 | uVar3) >> 0x1f;
    }
  }
  return iVar1;
}

