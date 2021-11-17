#include <MSL_C.PPCEABI.bare.H/direct_io.h>
#include <MSL_C.PPCEABI.bare.H/wchar_io.h>
#include <MSL_C.PPCEABI.bare.H/misc_io.h>
#include <MSL_C.PPCEABI.bare.H/FILE_POS.C.h>
#include <MSL_C.PPCEABI.bare.H/buffer_io.h>
#include <MSL_C.PPCEABI.bare.H/mem.h>
#include <MSL_C.PPCEABI.bare.H/direct_io.h>


namespace MSL_C.PPCEABI.bare.H {

/* WARNING: Type propagation algorithm not settling */

uint __fwrite(byte *param_1,uint param_2,int param_3,__FILE *param_4)

{
  bool bVar1;
  bool bVar2;
  ushort uVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  char *local_28 [3];
  
  iVar4 = fwide(param_4,0);
  if (iVar4 == 0) {
    fwide(param_4,-1);
  }
  pcVar7 = (char *)(param_2 * param_3);
  if (((pcVar7 == (char *)0x0) || (*(char *)((int)&param_4->_IO_read_end + 2) != '\0')) ||
     (uVar3 = *(ushort *)&param_4->_IO_read_ptr >> 6 & 7, uVar3 == 0)) {
    return 0;
  }
  if (uVar3 == 2) {
    __stdio_atexit();
  }
  bVar2 = true;
  bVar1 = false;
  if (((*(byte *)((int)&param_4->_IO_read_ptr + 1) >> 3 & 1) == 0) ||
     ((*(byte *)&param_4->_IO_read_ptr >> 1 & 3) == 2)) {
    bVar1 = true;
  }
  if ((!bVar1) && ((*(byte *)&param_4->_IO_read_ptr >> 1 & 3) != 1)) {
    bVar2 = false;
  }
  if ((*(byte *)&param_4->_IO_read_end >> 5 == 0) &&
     ((*(byte *)&param_4->_IO_read_ptr >> 3 & 2) != 0)) {
    if (((*(byte *)&param_4->_IO_read_ptr >> 3 & 4) != 0) &&
       (iVar4 = fseek((FILE *)param_4,0,2), iVar4 != 0)) {
      return 0;
    }
    *(byte *)&param_4->_IO_read_end = *(byte *)&param_4->_IO_read_end & 0x1f | 0x20;
    __prep_buffer(param_4);
  }
  if (*(byte *)&param_4->_IO_read_end >> 5 != 1) {
    *(undefined *)((int)&param_4->_IO_read_end + 2) = 1;
    param_4->_IO_backup_base = (char *)0x0;
    return 0;
  }
  pcVar6 = (char *)0x0;
  if (pcVar7 != (char *)0x0) {
    if ((param_4->_IO_save_base != param_4->_IO_buf_base) || (bVar2)) {
      param_4->_IO_backup_base =
           param_4->_IO_buf_end + -((int)param_4->_IO_save_base - (int)param_4->_IO_buf_base);
      while( true ) {
        iVar4 = 0;
        local_28[0] = param_4->_IO_backup_base;
        if (pcVar7 < param_4->_IO_backup_base) {
          local_28[0] = pcVar7;
        }
        if ((((*(byte *)&param_4->_IO_read_ptr >> 1 & 3) == 1) && (local_28[0] != (char *)0x0)) &&
           (iVar4 = __memrchr(param_1,10), iVar4 != 0)) {
          local_28[0] = (char *)((iVar4 + 1) - (int)param_1);
        }
        if (local_28[0] != (char *)0x0) {
          copy_bytes((byte *)param_4->_IO_save_base,param_1,(int)local_28[0]);
          param_1 = param_1 + (int)local_28[0];
          pcVar6 = pcVar6 + (int)local_28[0];
          pcVar7 = pcVar7 + -(int)local_28[0];
          param_4->_IO_save_base = param_4->_IO_save_base + (int)local_28[0];
          param_4->_IO_backup_base = param_4->_IO_backup_base + -(int)local_28[0];
        }
        if ((((param_4->_IO_backup_base == (char *)0x0) || (iVar4 != 0)) ||
            ((*(byte *)&param_4->_IO_read_ptr >> 1 & 3) == 0)) &&
           (iVar4 = __flush_buffer(param_4,0), iVar4 != 0)) break;
        if ((pcVar7 == (char *)0x0) || (!bVar2)) goto LAB_8032add8;
      }
      *(undefined *)((int)&param_4->_IO_read_end + 2) = 1;
      pcVar7 = (char *)0x0;
      param_4->_IO_backup_base = (char *)0x0;
    }
  }
LAB_8032add8:
  if ((pcVar7 != (char *)0x0) && (!bVar2)) {
    pcVar5 = param_4->_IO_buf_base;
    pcVar8 = param_4->_IO_buf_end;
    param_4->_IO_buf_base = (char *)param_1;
    param_4->_IO_buf_end = pcVar7;
    param_4->_IO_save_base = (char *)(param_1 + (int)pcVar7);
    iVar4 = __flush_buffer(param_4,local_28);
    if (iVar4 != 0) {
      *(undefined *)((int)&param_4->_IO_read_end + 2) = 1;
      param_4->_IO_backup_base = (char *)0x0;
    }
    param_4->_IO_buf_base = pcVar5;
    pcVar6 = pcVar6 + (int)local_28[0];
    param_4->_IO_buf_end = pcVar8;
    __prep_buffer(param_4);
    param_4->_IO_backup_base = (char *)0x0;
  }
  if ((*(byte *)&param_4->_IO_read_ptr >> 1 & 3) != 2) {
    param_4->_IO_backup_base = (char *)0x0;
  }
  return (uint)(pcVar6 + (param_2 - 1)) / param_2;
}


size_t fwrite(void *__ptr,size_t __size,size_t __n,FILE *__s)

{
  size_t sVar1;
  
  sVar1 = __fwrite();
  return sVar1;
}

