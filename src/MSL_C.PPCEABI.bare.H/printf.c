#include <MSL_C.PPCEABI.bare.H/printf.h>
#include <MSL_C.PPCEABI.bare.H/printf.h>
#include <MSL_C.PPCEABI.bare.H/wchar_io.h>
#include <MSL_C.PPCEABI.bare.H/direct_io.h>
#include <MSL_C.PPCEABI.bare.H/string.h>
#include <Runtime.PPCEABI.H/__va_arg.h>
#include <MSL_C.PPCEABI.bare.H/mbstring.h>
#include <MSL_C.PPCEABI.bare.H/mem.h>
#include <MSL_C.PPCEABI.bare.H/ansi_fp.h>
#include <Runtime.PPCEABI.H/runtime.h>


namespace MSL_C.PPCEABI.bare.H {

int sprintf(char *__s,char *__format,...)

{
  int iVar1;
  int iVar2;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 in_r9;
  undefined4 in_r10;
  byte in_cr1;
  undefined8 in_f1;
  undefined8 in_f2;
  undefined8 in_f3;
  undefined8 in_f4;
  undefined8 in_f5;
  undefined8 in_f6;
  undefined8 in_f7;
  undefined8 in_f8;
  char *local_98;
  char *local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  char *local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined *local_28;
  char **local_24;
  
  if ((bool)(in_cr1 >> 1 & 1)) {
    local_78 = in_f1;
    local_70 = in_f2;
    local_68 = in_f3;
    local_60 = in_f4;
    local_58 = in_f5;
    local_50 = in_f6;
    local_48 = in_f7;
    local_40 = in_f8;
  }
  local_28 = &stack0x00000008;
  local_24 = &local_98;
  local_2c = 0x2000000;
  local_34 = 0xffffffff;
  local_30 = 0;
  local_98 = __s;
  local_94 = __format;
  local_90 = in_r5;
  local_8c = in_r6;
  local_88 = in_r7;
  local_84 = in_r8;
  local_80 = in_r9;
  local_7c = in_r10;
  local_38 = __s;
  iVar1 = __pformatter(__StringWrite,&local_38,__format,&local_2c);
  if (__s != (char *)0x0) {
    iVar2 = -2;
    if (iVar1 != -1) {
      iVar2 = iVar1;
    }
    __s[iVar2] = '\0';
  }
  return iVar1;
}


int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
  uint uVar1;
  uint uVar2;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 in_r9;
  undefined4 in_r10;
  byte in_cr1;
  undefined8 in_f1;
  undefined8 in_f2;
  undefined8 in_f3;
  undefined8 in_f4;
  undefined8 in_f5;
  undefined8 in_f6;
  undefined8 in_f7;
  undefined8 in_f8;
  char *local_98;
  size_t local_94;
  char *local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  char *local_38;
  size_t local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined *local_28;
  char **local_24;
  
  if ((bool)(in_cr1 >> 1 & 1)) {
    local_78 = in_f1;
    local_70 = in_f2;
    local_68 = in_f3;
    local_60 = in_f4;
    local_58 = in_f5;
    local_50 = in_f6;
    local_48 = in_f7;
    local_40 = in_f8;
  }
  local_28 = &stack0x00000008;
  local_24 = &local_98;
  local_2c = 0x3000000;
  local_30 = 0;
  local_98 = __s;
  local_94 = __maxlen;
  local_90 = __format;
  local_8c = in_r6;
  local_88 = in_r7;
  local_84 = in_r8;
  local_80 = in_r9;
  local_7c = in_r10;
  local_38 = __s;
  local_34 = __maxlen;
  uVar1 = __pformatter(__StringWrite,&local_38,__format,&local_2c);
  if (__s != (char *)0x0) {
    uVar2 = __maxlen - 1;
    if (uVar1 < __maxlen) {
      uVar2 = uVar1;
    }
    __s[uVar2] = '\0';
  }
  return uVar1;
}


int vsnprintf(char *__s,size_t __maxlen,char *__format,__gnuc_va_list __arg)

{
  uint uVar1;
  uint uVar2;
  char *local_18;
  size_t local_14;
  undefined4 local_10;
  
  local_10 = 0;
  local_18 = __s;
  local_14 = __maxlen;
  uVar1 = __pformatter(__StringWrite,&local_18);
  if (__s != (char *)0x0) {
    uVar2 = __maxlen - 1;
    if (uVar1 < __maxlen) {
      uVar2 = uVar1;
    }
    __s[uVar2] = '\0';
  }
  return uVar1;
}


int vprintf(char *__format,__gnuc_va_list __arg)

{
  int iVar1;
  
  iVar1 = fwide((__FILE *)&DAT_803a2070,-1);
  if (iVar1 < 0) {
    iVar1 = __pformatter(__FileWrite,&DAT_803a2070,__format,__arg);
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}


int printf(char *__format,...)

{
  int iVar1;
  undefined4 in_r4;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 in_r9;
  undefined4 in_r10;
  byte in_cr1;
  undefined8 in_f1;
  undefined8 in_f2;
  undefined8 in_f3;
  undefined8 in_f4;
  undefined8 in_f5;
  undefined8 in_f6;
  undefined8 in_f7;
  undefined8 in_f8;
  char *local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  undefined4 local_18;
  undefined *local_14;
  char **local_10;
  
  if ((bool)(in_cr1 >> 1 & 1)) {
    local_58 = in_f1;
    local_50 = in_f2;
    local_48 = in_f3;
    local_40 = in_f4;
    local_38 = in_f5;
    local_30 = in_f6;
    local_28 = in_f7;
    local_20 = in_f8;
  }
  local_78 = __format;
  local_74 = in_r4;
  local_70 = in_r5;
  local_6c = in_r6;
  local_68 = in_r7;
  local_64 = in_r8;
  local_60 = in_r9;
  local_5c = in_r10;
  iVar1 = fwide((__FILE *)&DAT_803a2070,-1);
  if (iVar1 < 0) {
    local_14 = &stack0x00000008;
    local_10 = &local_78;
    local_18 = 0x1000000;
    iVar1 = __pformatter(__FileWrite,&DAT_803a2070,__format,&local_18);
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}


undefined4 __StringWrite(int *param_1,byte *param_2,int param_3)

{
  int iVar1;
  int length;
  
  iVar1 = param_1[2];
  length = param_1[1] - iVar1;
  if ((uint)(iVar1 + param_3) <= (uint)param_1[1]) {
    length = param_3;
  }
  copy_bytes((byte *)(*param_1 + iVar1),param_2,length);
  param_1[2] = param_1[2] + length;
  return 1;
}


FILE * __FileWrite(FILE *param_1,void *param_2,size_t param_3)

{
  size_t sVar1;
  
  sVar1 = fwrite(param_2,1,param_3,param_1);
  if (param_3 != sVar1) {
    param_1 = (FILE *)0x0;
  }
  return param_1;
}


/* WARNING: Could not reconcile some variable overlaps */

int __pformatter
              (code *param_1,undefined4 param_2,char *param_3,undefined4 param_4)

{
  byte bVar1;
  char *__s;
  size_t sVar2;
  int iVar3;
  uint *puVar4;
  undefined4 *puVar5;
  undefined8 *puVar6;
  wchar_t **ppwVar7;
  byte **ppbVar8;
  void *pvVar9;
  int **ppiVar10;
  int *piVar11;
  wchar_t *__pwcs;
  byte *__s_00;
  undefined4 unaff_r22;
  undefined4 unaff_r23;
  undefined *puVar12;
  size_t sVar13;
  int iVar14;
  uint unaff_r28;
  undefined8 uVar15;
  undefined local_2b8;
  char local_2b7 [3];
  undefined4 local_2b4;
  undefined4 local_2b0;
  int local_2ac;
  size_t local_2a8;
  undefined4 local_2a4;
  undefined4 local_2a0;
  int local_29c;
  size_t local_298;
  undefined4 local_294;
  undefined4 local_290;
  int local_28c;
  size_t local_288;
  undefined4 local_284;
  undefined4 local_280;
  int local_27c;
  size_t local_278;
  undefined4 local_274;
  undefined4 local_270;
  int local_26c;
  size_t local_268;
  undefined4 local_264;
  undefined4 local_260;
  int local_25c;
  size_t local_258;
  undefined4 local_254;
  undefined4 local_250;
  int local_24c;
  size_t local_248;
  byte local_244 [511];
  undefined auStack69 [17];
  
  puVar12 = auStack69 + 1;
  iVar14 = 0;
  local_2b7[0] = ' ';
LAB_8032c488:
  if (*param_3 == '\0') {
    return iVar14;
  }
  __s = strchr(param_3,0x25);
  if (__s == (char *)0x0) {
    sVar2 = strlen(param_3);
    if (sVar2 == 0) {
      return iVar14 + sVar2;
    }
    iVar3 = (*param_1)(param_2,param_3);
    if (iVar3 != 0) {
      return iVar14 + sVar2;
    }
    return -1;
  }
  iVar14 = iVar14 + ((int)__s - (int)param_3);
  if (((int)__s - (int)param_3 != 0) && (iVar3 = (*param_1)(param_2,param_3), iVar3 == 0)) {
    return -1;
  }
  param_3 = (char *)parse_format(__s,param_4,&local_254);
  if (local_250._1_1_ == 0x68) goto LAB_8032c308;
  if (local_250._1_1_ < 0x68) {
    if (local_250._1_1_ == 0x58) goto LAB_8032bfc4;
    if (local_250._1_1_ < 0x58) {
      if (local_250._1_1_ == 0x41) {
LAB_8032c12c:
        if (local_250._0_1_ == '\x05') {
          puVar6 = (undefined8 *)Runtime.PPCEABI.H::__va_arg(param_4,3);
          uVar15 = *puVar6;
        }
        else {
          puVar6 = (undefined8 *)Runtime.PPCEABI.H::__va_arg(param_4,3);
          uVar15 = *puVar6;
        }
        local_2b4 = local_254;
        local_2b0 = local_250;
        local_2ac = local_24c;
        local_2a8 = local_248;
        __s_00 = (byte *)double2hex(uVar15,puVar12,&local_2b4);
        if (__s_00 == (byte *)0x0) goto LAB_8032c308;
        sVar2 = (int)auStack69 - (int)__s_00;
      }
      else {
        if (0x40 < local_250._1_1_) {
          if ((0x47 < local_250._1_1_) || (local_250._1_1_ < 0x45)) goto LAB_8032c308;
          goto LAB_8032c0c0;
        }
        if (local_250._1_1_ != 0x25) goto LAB_8032c308;
        __s_00 = local_244;
        local_244[0] = 0x25;
        sVar2 = 1;
      }
    }
    else {
      if (local_250._1_1_ == 99) {
        __s_00 = local_244;
        puVar5 = (undefined4 *)Runtime.PPCEABI.H::__va_arg(param_4,1);
        local_244[0] = (byte)*puVar5;
        sVar2 = 1;
      }
      else {
        if (local_250._1_1_ < 99) {
          if (local_250._1_1_ != 0x61) goto LAB_8032c308;
          goto LAB_8032c12c;
        }
        if (local_250._1_1_ < 0x65) goto LAB_8032bec8;
LAB_8032c0c0:
        if (local_250._0_1_ == '\x05') {
          puVar6 = (undefined8 *)Runtime.PPCEABI.H::__va_arg(param_4,3);
          uVar15 = *puVar6;
        }
        else {
          puVar6 = (undefined8 *)Runtime.PPCEABI.H::__va_arg(param_4,3);
          uVar15 = *puVar6;
        }
        local_2a4 = local_254;
        local_2a0 = local_250;
        local_29c = local_24c;
        local_298 = local_248;
        __s_00 = (byte *)float2str(uVar15,puVar12,&local_2a4);
        if (__s_00 == (byte *)0x0) goto LAB_8032c308;
        sVar2 = (int)auStack69 - (int)__s_00;
      }
    }
  }
  else {
    if (local_250._1_1_ == 0x74) goto LAB_8032c308;
    if (local_250._1_1_ < 0x74) {
      if (local_250._1_1_ != 0x6f) {
        if (local_250._1_1_ < 0x6f) {
          if (local_250._1_1_ < 0x6e) {
            if (0x69 < local_250._1_1_) goto LAB_8032c308;
LAB_8032bec8:
            if (local_250._0_1_ == '\x03') {
              puVar4 = (uint *)Runtime.PPCEABI.H::__va_arg(param_4,1);
              unaff_r28 = *puVar4;
            }
            else {
              if (local_250._0_1_ == '\x04') {
                puVar5 = (undefined4 *)Runtime.PPCEABI.H::__va_arg(param_4,2);
                unaff_r22 = *puVar5;
                unaff_r23 = puVar5[1];
              }
              else {
                puVar4 = (uint *)Runtime.PPCEABI.H::__va_arg(param_4,1);
                unaff_r28 = *puVar4;
              }
            }
            if (local_250._0_1_ == '\x02') {
              unaff_r28 = SEXT24((short)unaff_r28);
            }
            if (local_250._0_1_ == '\x01') {
              unaff_r28 = SEXT14((char)unaff_r28);
            }
            if (local_250._0_1_ == '\x04') {
              local_264 = local_254;
              local_260 = local_250;
              local_25c = local_24c;
              local_258 = local_248;
              __s_00 = (byte *)longlong2str(unaff_r22,unaff_r23,puVar12,&local_264);
            }
            else {
              local_274 = local_254;
              local_270 = local_250;
              local_26c = local_24c;
              local_268 = local_248;
              __s_00 = (byte *)long2str(unaff_r28,puVar12,&local_274);
            }
            if (__s_00 == (byte *)0x0) goto LAB_8032c308;
            sVar2 = (int)auStack69 - (int)__s_00;
            goto LAB_8032c348;
          }
          ppiVar10 = (int **)Runtime.PPCEABI.H::__va_arg(param_4,1);
          piVar11 = *ppiVar10;
          if (local_250._0_1_ == 2) {
            *(short *)piVar11 = (short)iVar14;
          }
          else {
            if (local_250._0_1_ < 2) {
              if (local_250._0_1_ == 0) {
                *piVar11 = iVar14;
              }
            }
            else {
              if (local_250._0_1_ == 4) {
                piVar11[1] = iVar14;
                *piVar11 = iVar14 >> 0x1f;
              }
              else {
                if (local_250._0_1_ < 4) {
                  *piVar11 = iVar14;
                }
              }
            }
          }
          goto LAB_8032c488;
        }
        if (local_250._1_1_ < 0x73) goto LAB_8032c308;
        if (local_250._0_1_ == '\x06') {
          ppwVar7 = (wchar_t **)Runtime.PPCEABI.H::__va_arg(param_4,1);
          __pwcs = *ppwVar7;
          if (__pwcs == (wchar_t *)0x0) {
            __pwcs = (wchar_t *)&_wstringBase0;
          }
          sVar2 = wcstombs((char *)local_244,__pwcs,0x200);
          if ((int)sVar2 < 0) goto LAB_8032c308;
          __s_00 = local_244;
        }
        else {
          ppbVar8 = (byte **)Runtime.PPCEABI.H::__va_arg(param_4,1);
          __s_00 = *ppbVar8;
        }
        sVar13 = local_248;
        if (__s_00 == (byte *)0x0) {
          __s_00 = &_stringBase0;
        }
        if ((char)local_254 == '\0') {
          if (local_254._2_1_ == '\0') {
            sVar2 = strlen((char *)__s_00);
          }
          else {
            pvVar9 = memchr(__s_00,0,local_248);
            sVar2 = sVar13;
            if (pvVar9 != (void *)0x0) {
              sVar2 = (int)pvVar9 - (int)__s_00;
            }
          }
        }
        else {
          sVar2 = (size_t)*__s_00;
          __s_00 = __s_00 + 1;
          if ((local_254._2_1_ != '\0') && ((int)local_248 < (int)sVar2)) {
            sVar2 = sVar13;
          }
        }
        goto LAB_8032c348;
      }
    }
    else {
      if ((local_250._1_1_ != 0x78) && ((0x77 < local_250._1_1_ || (0x75 < local_250._1_1_))))
      goto LAB_8032c308;
    }
LAB_8032bfc4:
    if (local_250._0_1_ == '\x03') {
      puVar4 = (uint *)Runtime.PPCEABI.H::__va_arg(param_4,1);
      unaff_r28 = *puVar4;
    }
    else {
      if (local_250._0_1_ == '\x04') {
        puVar5 = (undefined4 *)Runtime.PPCEABI.H::__va_arg(param_4,2);
        unaff_r22 = *puVar5;
        unaff_r23 = puVar5[1];
      }
      else {
        puVar4 = (uint *)Runtime.PPCEABI.H::__va_arg(param_4,1);
        unaff_r28 = *puVar4;
      }
    }
    if (local_250._0_1_ == '\x02') {
      unaff_r28 = unaff_r28 & 0xffff;
    }
    if (local_250._0_1_ == '\x01') {
      unaff_r28 = unaff_r28 & 0xff;
    }
    if (local_250._0_1_ == '\x04') {
      local_284 = local_254;
      local_280 = local_250;
      local_27c = local_24c;
      local_278 = local_248;
      __s_00 = (byte *)longlong2str(unaff_r22,unaff_r23,puVar12,&local_284);
    }
    else {
      local_294 = local_254;
      local_290 = local_250;
      local_28c = local_24c;
      local_288 = local_248;
      __s_00 = (byte *)long2str(unaff_r28,puVar12,&local_294);
    }
    if (__s_00 == (byte *)0x0) {
LAB_8032c308:
      sVar2 = strlen(__s);
      if (sVar2 == 0) {
        return iVar14 + sVar2;
      }
      iVar3 = (*param_1)(param_2,__s);
      if (iVar3 != 0) {
        return iVar14 + sVar2;
      }
      return -1;
    }
    sVar2 = (int)auStack69 - (int)__s_00;
  }
LAB_8032c348:
  sVar13 = sVar2;
  if (local_254._0_1_ != '\0') {
    local_2b7[0] = ' ';
    if (local_254._0_1_ == '\x02') {
      local_2b7[0] = '0';
    }
    bVar1 = *__s_00;
    if ((((bVar1 == 0x2b) || (bVar1 == 0x2d)) || (bVar1 == 0x20)) && (local_2b7[0] == '0')) {
      iVar3 = (*param_1)(param_2,__s_00,1);
      if (iVar3 == 0) {
        return -1;
      }
      __s_00 = __s_00 + 1;
      sVar13 = sVar2 - 1;
    }
    for (; (int)sVar2 < local_24c; sVar2 = sVar2 + 1) {
      iVar3 = (*param_1)(param_2,local_2b7,1);
      if (iVar3 == 0) {
        return -1;
      }
    }
  }
  if ((sVar13 != 0) && (iVar3 = (*param_1)(param_2,__s_00,sVar13), iVar3 == 0)) {
    return -1;
  }
  if (local_254._0_1_ == '\0') {
    for (; (int)sVar2 < local_24c; sVar2 = sVar2 + 1) {
      local_2b8 = 0x20;
      iVar3 = (*param_1)(param_2,&local_2b8,1);
      if (iVar3 == 0) {
        return -1;
      }
    }
  }
  iVar14 = iVar14 + sVar2;
  goto LAB_8032c488;
}


byte * float2str(double param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  byte bVar8;
  uint uVar9;
  undefined local_48 [2];
  undefined2 local_46;
  char local_44 [2];
  short local_42;
  byte local_40;
  byte local_3f [39];
  
  if (0x1fd < *(int *)(param_3 + 0xc)) {
    return (byte *)0x0;
  }
  local_48[0] = 0;
  local_46 = 0x20;
  __num2dec(local_48,local_44);
  pbVar5 = local_3f + local_40;
  while ((1 < local_40 && (pbVar5 = pbVar5 + -1, *pbVar5 == 0x30))) {
    local_40 = local_40 - 1;
    local_42 = local_42 + 1;
  }
  if (local_3f[0] == 0x49) {
    if (_1079 <= param_1) {
      pbVar5 = (byte *)(param_2 + -4);
      if (((&__ctype_map)[*(byte *)(param_3 + 5)] & 0x80) != 0) {
        strcpy((char *)pbVar5,"INF");
        return pbVar5;
      }
      strcpy((char *)pbVar5,"inf");
      return pbVar5;
    }
    pbVar5 = (byte *)(param_2 + -5);
    if (((&__ctype_map)[*(byte *)(param_3 + 5)] & 0x80) != 0) {
      strcpy((char *)pbVar5,"-INF");
      return pbVar5;
    }
    strcpy((char *)pbVar5,"-inf");
    return pbVar5;
  }
  if (local_3f[0] < 0x49) {
    if (local_3f[0] == 0x30) {
      local_42 = 0;
    }
  }
  else {
    if (local_3f[0] == 0x4e) {
      if (local_44[0] == '\0') {
        pbVar5 = (byte *)(param_2 + -4);
        if (((&__ctype_map)[*(byte *)(param_3 + 5)] & 0x80) != 0) {
          strcpy((char *)pbVar5,"NAN");
          return pbVar5;
        }
        strcpy((char *)pbVar5,"nan");
        return pbVar5;
      }
      pbVar5 = (byte *)(param_2 + -5);
      if (((&__ctype_map)[*(byte *)(param_3 + 5)] & 0x80) != 0) {
        strcpy((char *)pbVar5,"-NAN");
        return pbVar5;
      }
      strcpy((char *)pbVar5,"-nan");
      return pbVar5;
    }
  }
  pbVar5 = (byte *)(param_2 + -1);
  local_42 = (ushort)local_40 + local_42 + -1;
  *(undefined *)(param_2 + -1) = 0;
  bVar8 = *(byte *)(param_3 + 5);
  if (bVar8 == 0x65) goto LAB_8032c7e8;
  if (bVar8 < 0x65) {
    if (bVar8 != 0x46) {
      if (bVar8 < 0x46) {
        if (bVar8 < 0x45) {
          return pbVar5;
        }
        goto LAB_8032c7e8;
      }
      if (0x47 < bVar8) {
        return pbVar5;
      }
LAB_8032c730:
      if (*(int *)(param_3 + 0xc) < (int)(uint)local_40) {
        round_decimal(local_44);
      }
      iVar6 = (int)local_42;
      if ((iVar6 < -4) || (*(int *)(param_3 + 0xc) <= iVar6)) {
        if (*(char *)(param_3 + 3) == '\0') {
          *(uint *)(param_3 + 0xc) = local_40 - 1;
        }
        else {
          *(int *)(param_3 + 0xc) = *(int *)(param_3 + 0xc) + -1;
        }
        if (*(char *)(param_3 + 5) == 'g') {
          *(undefined *)(param_3 + 5) = 0x65;
        }
        else {
          *(undefined *)(param_3 + 5) = 0x45;
        }
LAB_8032c7e8:
        if (*(int *)(param_3 + 0xc) + 1 < (int)(uint)local_40) {
          round_decimal(local_44);
        }
        iVar6 = (int)local_42;
        bVar8 = 0x2b;
        if (iVar6 < 0) {
          iVar6 = -iVar6;
          bVar8 = 0x2d;
        }
        for (iVar7 = 0; (iVar6 != 0 || (iVar7 < 2)); iVar7 = iVar7 + 1) {
          iVar2 = iVar6 / 10 + (iVar6 >> 0x1f);
          cVar1 = (char)iVar6;
          iVar6 = iVar2 - (iVar2 >> 0x1f);
          pbVar5[-1] = cVar1 + ((char)iVar2 - (char)(iVar2 >> 0x1f)) * -10 + 0x30;
          pbVar5 = pbVar5 + -1;
        }
        pbVar5[-1] = bVar8;
        pbVar5 = pbVar5 + -2;
        *pbVar5 = *(byte *)(param_3 + 5);
        iVar6 = *(int *)(param_3 + 0xc);
        if (0x1fd < iVar6 + (param_2 - (int)pbVar5)) {
          return (byte *)0x0;
        }
        if ((int)(uint)local_40 < iVar6 + 1) {
          iVar6 = (iVar6 + 2) - (uint)local_40;
          while (iVar6 = iVar6 + -1, iVar6 != 0) {
            pbVar5 = pbVar5 + -1;
            *pbVar5 = 0x30;
          }
        }
        uVar3 = (uint)local_40;
        pbVar4 = local_3f + uVar3;
        while (uVar3 = uVar3 - 1, uVar3 != 0) {
          pbVar4 = pbVar4 + -1;
          pbVar5 = pbVar5 + -1;
          *pbVar5 = *pbVar4;
        }
        if ((*(int *)(param_3 + 0xc) != 0) || (*(char *)(param_3 + 3) != '\0')) {
          pbVar5 = pbVar5 + -1;
          *pbVar5 = 0x2e;
        }
        pbVar5[-1] = local_3f[0];
        if (local_44[0] != '\0') {
          pbVar5[-2] = 0x2d;
          return pbVar5 + -2;
        }
        if (*(char *)(param_3 + 1) == '\x01') {
          pbVar5[-2] = 0x2b;
          return pbVar5 + -2;
        }
        if (*(char *)(param_3 + 1) != '\x02') {
          return pbVar5 + -1;
        }
        pbVar5[-2] = 0x20;
        return pbVar5 + -2;
      }
      if (*(char *)(param_3 + 3) == '\0') {
        iVar6 = (uint)local_40 - (iVar6 + 1);
        *(int *)(param_3 + 0xc) = iVar6;
        if (iVar6 < 0) {
          *(undefined4 *)(param_3 + 0xc) = 0;
        }
      }
      else {
        *(int *)(param_3 + 0xc) = *(int *)(param_3 + 0xc) - (iVar6 + 1);
      }
    }
  }
  else {
    if (bVar8 == 0x67) goto LAB_8032c730;
    if (0x66 < bVar8) {
      return pbVar5;
    }
  }
  iVar6 = ((uint)local_40 - (int)local_42) + -1;
  if (iVar6 < 0) {
    iVar6 = 0;
  }
  if (*(int *)(param_3 + 0xc) < iVar6) {
    round_decimal(local_44,(uint)local_40 - (iVar6 - *(int *)(param_3 + 0xc)));
    iVar6 = ((uint)local_40 - (int)local_42) + -1;
    if (iVar6 < 0) {
      iVar6 = 0;
    }
  }
  iVar7 = local_42 + 1;
  if (iVar7 < 0) {
    iVar7 = 0;
  }
  if (0x1fd < iVar7 + iVar6) {
    return (byte *)0x0;
  }
  pbVar4 = local_3f + local_40;
  for (iVar2 = 0; iVar2 < *(int *)(param_3 + 0xc) - iVar6; iVar2 = iVar2 + 1) {
    pbVar5 = pbVar5 + -1;
    *pbVar5 = 0x30;
  }
  for (iVar2 = 0; (iVar2 < iVar6 && (iVar2 < (int)(uint)local_40)); iVar2 = iVar2 + 1) {
    pbVar4 = pbVar4 + -1;
    pbVar5 = pbVar5 + -1;
    *pbVar5 = *pbVar4;
  }
  uVar3 = iVar6 - iVar2;
  if (iVar2 < iVar6) {
    uVar9 = uVar3 >> 3;
    if (uVar9 != 0) {
      do {
        pbVar5[-1] = 0x30;
        pbVar5[-2] = 0x30;
        pbVar5[-3] = 0x30;
        pbVar5[-4] = 0x30;
        pbVar5[-5] = 0x30;
        pbVar5[-6] = 0x30;
        pbVar5[-7] = 0x30;
        pbVar5 = pbVar5 + -8;
        *pbVar5 = 0x30;
        uVar9 = uVar9 - 1;
      } while (uVar9 != 0);
      uVar3 = uVar3 & 7;
      if (uVar3 == 0) goto LAB_8032ca64;
    }
    do {
      pbVar5 = pbVar5 + -1;
      *pbVar5 = 0x30;
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
LAB_8032ca64:
  if ((*(int *)(param_3 + 0xc) != 0) || (*(char *)(param_3 + 3) != '\0')) {
    pbVar5 = pbVar5 + -1;
    *pbVar5 = 0x2e;
  }
  if (iVar7 == 0) {
    pbVar5 = pbVar5 + -1;
    *pbVar5 = 0x30;
  }
  else {
    for (iVar6 = 0; iVar6 < (int)(iVar7 - (uint)local_40); iVar6 = iVar6 + 1) {
      pbVar5 = pbVar5 + -1;
      *pbVar5 = 0x30;
    }
    uVar3 = iVar7 - iVar6;
    if (iVar6 < iVar7) {
      uVar9 = uVar3 >> 3;
      if (uVar9 != 0) {
        do {
          pbVar5[-1] = pbVar4[-1];
          pbVar5[-2] = pbVar4[-2];
          pbVar5[-3] = pbVar4[-3];
          pbVar5[-4] = pbVar4[-4];
          pbVar5[-5] = pbVar4[-5];
          pbVar5[-6] = pbVar4[-6];
          pbVar5[-7] = pbVar4[-7];
          pbVar4 = pbVar4 + -8;
          pbVar5 = pbVar5 + -8;
          *pbVar5 = *pbVar4;
          uVar9 = uVar9 - 1;
        } while (uVar9 != 0);
        uVar3 = uVar3 & 7;
        if (uVar3 == 0) goto LAB_8032cb30;
      }
      do {
        pbVar4 = pbVar4 + -1;
        pbVar5 = pbVar5 + -1;
        *pbVar5 = *pbVar4;
        uVar3 = uVar3 - 1;
      } while (uVar3 != 0);
    }
  }
LAB_8032cb30:
  if (local_44[0] == '\0') {
    if (*(char *)(param_3 + 1) == '\x01') {
      pbVar5 = pbVar5 + -1;
      *pbVar5 = 0x2b;
    }
    else {
      if (*(char *)(param_3 + 1) == '\x02') {
        pbVar5 = pbVar5 + -1;
        *pbVar5 = 0x20;
      }
    }
  }
  else {
    pbVar5 = pbVar5 + -1;
    *pbVar5 = 0x2d;
  }
  return pbVar5;
}


void round_decimal(int param_1,int param_2)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  
  if (-1 < param_2) {
    if ((int)(uint)*(byte *)(param_1 + 4) <= param_2) {
      return;
    }
    iVar4 = param_1 + param_2;
    pcVar6 = (char *)(iVar4 + 5);
    uVar5 = SEXT14((char)(*(char *)(iVar4 + 5) + -0x30));
    if (uVar5 == 5) {
      pcVar3 = (char *)(param_1 + (uint)*(byte *)(param_1 + 4) + 5);
      do {
        pcVar3 = pcVar3 + -1;
        if (pcVar3 <= pcVar6) break;
      } while (*pcVar3 == '0');
      if (pcVar3 == pcVar6) {
        uVar5 = *(byte *)(iVar4 + 4) & 1;
      }
      else {
        uVar5 = 1;
      }
    }
    else {
      uVar5 = ((int)(uVar5 ^ 5) >> 1) - ((uVar5 ^ 5) & uVar5) >> 0x1f;
    }
    for (; param_2 != 0; param_2 = param_2 + -1) {
      pcVar6 = pcVar6 + -1;
      cVar1 = *pcVar6 + (char)uVar5;
      cVar2 = cVar1 + -0x30;
      uVar5 = (int)cVar2 ^ 9;
      uVar5 = -((int)(((int)uVar5 >> 1) - (uVar5 & (int)cVar2)) >> 0x1f);
      if ((uVar5 == 0) && (cVar2 != '\0')) {
        *pcVar6 = cVar1;
        break;
      }
    }
    if (uVar5 != 0) {
      *(short *)(param_1 + 2) = *(short *)(param_1 + 2) + 1;
      *(undefined *)(param_1 + 4) = 1;
      *(undefined *)(param_1 + 5) = 0x31;
      return;
    }
    if (param_2 != 0) {
      *(char *)(param_1 + 4) = (char)param_2;
      return;
    }
  }
  *(undefined2 *)(param_1 + 2) = 0;
  *(undefined *)(param_1 + 4) = 1;
  *(undefined *)(param_1 + 5) = 0x30;
  return;
}


/* WARNING: Could not reconcile some variable overlaps */

char * double2hex(ulonglong param_1,int param_2,int param_3)

{
  char cVar1;
  char *__dest;
  int iVar2;
  byte bVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  undefined8 local_78;
  undefined local_70 [2];
  undefined2 local_6e;
  ulonglong local_68;
  undefined4 local_60;
  uint local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined auStack64 [5];
  char local_3b;
  
  if (*(int *)(param_3 + 0xc) < 0x1fe) {
    local_70[0] = 0;
    local_6e = 0x20;
    local_78 = param_1;
    local_68 = param_1;
    __num2dec(local_70,auStack64);
    if (local_3b == 'I') {
      if (((int)local_68._0_2_ & 0x8000U) == 0) {
        __dest = (char *)(param_2 + -4);
        if (*(char *)(param_3 + 5) == 'A') {
          strcpy(__dest,"INF");
        }
        else {
          strcpy(__dest,"inf");
        }
      }
      else {
        __dest = (char *)(param_2 + -5);
        if (*(char *)(param_3 + 5) == 'A') {
          strcpy(__dest,"-INF");
        }
        else {
          strcpy(__dest,"-inf");
        }
      }
    }
    else {
      if (local_3b == 'N') {
        if ((local_78 & 0x8000000000000000) == 0) {
          __dest = (char *)(param_2 + -4);
          if (*(char *)(param_3 + 5) == 'A') {
            strcpy(__dest,"NAN");
          }
          else {
            strcpy(__dest,"nan");
          }
        }
        else {
          __dest = (char *)(param_2 + -5);
          if (*(char *)(param_3 + 5) == 'A') {
            strcpy(__dest,"-NAN");
          }
          else {
            strcpy(__dest,"-nan");
          }
        }
      }
      else {
        local_50 = 0x1010000;
        local_4c = (uint)CONCAT12(100,local_4c._2_2_);
        local_48 = 0;
        local_44 = 1;
        local_60 = 0x1010000;
        local_5c = local_4c;
        local_58 = 0;
        local_54 = 1;
        iVar2 = long2str((short)((ushort)((uint)(int)local_68._0_2_ >> 4) & 0x7ff) + -0x3ff,param_2,
                         &local_60);
        if (*(char *)(param_3 + 5) == 'a') {
          *(undefined *)(iVar2 + -1) = 0x70;
        }
        else {
          *(undefined *)(iVar2 + -1) = 0x50;
        }
        pcVar4 = (char *)(iVar2 + -1);
        uVar5 = *(uint *)(param_3 + 0xc);
        uVar6 = uVar5;
        if (0 < (int)uVar5) {
          do {
            bVar3 = (byte)local_70[(int)uVar5 / 2 + -7] >> 4;
            if ((uVar5 & 1 ^ -((int)uVar5 >> 0x1f)) != -((int)uVar5 >> 0x1f)) {
              bVar3 = local_70[(int)uVar5 / 2 + -7];
            }
            bVar3 = bVar3 & 0xf;
            if (bVar3 < 10) {
              cVar1 = bVar3 + 0x30;
            }
            else {
              if (*(char *)(param_3 + 5) == 'a') {
                cVar1 = bVar3 + 0x57;
              }
              else {
                cVar1 = bVar3 + 0x37;
              }
            }
            pcVar4 = pcVar4 + -1;
            *pcVar4 = cVar1;
            uVar5 = uVar5 - 1;
            uVar6 = uVar6 - 1;
          } while (uVar6 != 0);
        }
        if ((*(int *)(param_3 + 0xc) != 0) || (*(char *)(param_3 + 3) != '\0')) {
          pcVar4 = pcVar4 + -1;
          *pcVar4 = '.';
        }
        pcVar4[-1] = '1';
        if (*(char *)(param_3 + 5) == 'a') {
          pcVar4[-2] = 'x';
        }
        else {
          pcVar4[-2] = 'X';
        }
        __dest = pcVar4 + -3;
        *__dest = '0';
        if (((int)local_68._0_2_ & 0x8000U) == 0) {
          if (*(char *)(param_3 + 1) == '\x01') {
            __dest = pcVar4 + -4;
            *__dest = '+';
          }
          else {
            if (*(char *)(param_3 + 1) == '\x02') {
              __dest = pcVar4 + -4;
              *__dest = ' ';
            }
          }
        }
        else {
          __dest = pcVar4 + -4;
          *__dest = '-';
        }
      }
    }
  }
  else {
    __dest = (char *)0x0;
  }
  return __dest;
}


char * longlong2str(uint param_1,uint param_2,int param_3,char *param_4)

{
  bool bVar1;
  char cVar2;
  int extraout_r4;
  int iVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  uint unaff_r28;
  uint unaff_r29;
  undefined4 uVar7;
  longlong lVar8;
  
  pcVar5 = (char *)(param_3 + -1);
  bVar1 = false;
  iVar3 = 0;
  *(undefined *)(param_3 + -1) = 0;
  if ((((param_2 | param_1) != 0) || (*(int *)(param_4 + 0xc) != 0)) ||
     ((param_4[3] != '\0' && (param_4[5] == 'o')))) {
    lVar8 = CONCAT44(param_1,param_2);
    switch(param_4[5]) {
    case 'X':
    case 'x':
      unaff_r28 = 0x10;
      param_4[1] = '\0';
      unaff_r29 = 0;
      lVar8 = CONCAT44(param_1,param_2);
      break;
    case 'd':
    case 'i':
      unaff_r28 = 10;
      unaff_r29 = 0;
      lVar8 = CONCAT44(param_1,param_2);
      if ((param_1 ^ 0x80000000) < 0x80000000) {
        bVar1 = true;
        lVar8 = CONCAT44(-((param_2 != 0) + param_1),-param_2);
      }
      break;
    case 'o':
      unaff_r28 = 8;
      param_4[1] = '\0';
      unaff_r29 = 0;
      lVar8 = CONCAT44(param_1,param_2);
      break;
    case 'u':
      unaff_r28 = 10;
      param_4[1] = '\0';
      unaff_r29 = 0;
      lVar8 = CONCAT44(param_1,param_2);
    }
    do {
      pcVar6 = pcVar5;
      iVar4 = iVar3;
      uVar7 = (undefined4)((ulonglong)lVar8 >> 0x20);
      Runtime.PPCEABI.H::__mod2u(uVar7,(int)lVar8,unaff_r29,unaff_r28);
      lVar8 = Runtime.PPCEABI.H::__div2u(uVar7,(int)lVar8,unaff_r29,unaff_r28);
      cVar2 = (char)extraout_r4;
      if (extraout_r4 < 10) {
        cVar2 = cVar2 + '0';
      }
      else {
        if (param_4[5] == 'x') {
          cVar2 = cVar2 + 'W';
        }
        else {
          cVar2 = cVar2 + '7';
        }
      }
      pcVar5 = pcVar6 + -1;
      *pcVar5 = cVar2;
      iVar3 = iVar4 + 1;
    } while (lVar8 != 0);
    if ((((unaff_r28 ^ 8 | unaff_r29) == 0) && (param_4[3] != '\0')) && (*pcVar5 != '0')) {
      iVar3 = iVar4 + 2;
      pcVar5 = pcVar6 + -2;
      *pcVar5 = '0';
    }
    if (*param_4 == '\x02') {
      *(undefined4 *)(param_4 + 0xc) = *(undefined4 *)(param_4 + 8);
      if ((bVar1) || (param_4[1] != '\0')) {
        *(int *)(param_4 + 0xc) = *(int *)(param_4 + 0xc) + -1;
      }
      if (((unaff_r28 ^ 0x10 | unaff_r29) == 0) && (param_4[3] != '\0')) {
        *(int *)(param_4 + 0xc) = *(int *)(param_4 + 0xc) + -2;
      }
    }
    if (*(int *)(param_4 + 0xc) + (param_3 - (int)pcVar5) < 0x1fe) {
      for (; iVar3 < *(int *)(param_4 + 0xc); iVar3 = iVar3 + 1) {
        pcVar5 = pcVar5 + -1;
        *pcVar5 = '0';
      }
      if (((unaff_r28 ^ 0x10 | unaff_r29) == 0) && (param_4[3] != '\0')) {
        pcVar5[-1] = param_4[5];
        pcVar5 = pcVar5 + -2;
        *pcVar5 = '0';
      }
      if (bVar1) {
        pcVar5 = pcVar5 + -1;
        *pcVar5 = '-';
      }
      else {
        if (param_4[1] == '\x01') {
          pcVar5 = pcVar5 + -1;
          *pcVar5 = '+';
        }
        else {
          if (param_4[1] == '\x02') {
            pcVar5 = pcVar5 + -1;
            *pcVar5 = ' ';
          }
        }
      }
    }
    else {
      pcVar5 = (char *)0x0;
    }
  }
  return pcVar5;
}


char * long2str(uint param_1,int param_2,char *param_3)

{
  bool bVar1;
  uint in_r0;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  char cVar6;
  
  *(undefined *)(param_2 + -1) = 0;
  pcVar2 = (char *)(param_2 + -1);
  bVar1 = false;
  iVar4 = 0;
  if (((param_1 == 0) && (*(int *)(param_3 + 0xc) == 0)) &&
     ((param_3[3] == '\0' || (param_3[5] != 'o')))) {
    return pcVar2;
  }
  switch(param_3[5]) {
  case 'X':
  case 'x':
    in_r0 = 0x10;
    param_3[1] = '\0';
    break;
  case 'd':
  case 'i':
    in_r0 = 10;
    if ((int)param_1 < 0) {
      param_1 = -param_1;
      bVar1 = true;
    }
    break;
  case 'o':
    in_r0 = 8;
    param_3[1] = '\0';
    break;
  case 'u':
    in_r0 = 10;
    param_3[1] = '\0';
  }
  do {
    iVar5 = iVar4;
    pcVar3 = pcVar2;
    iVar4 = param_1 - (param_1 / in_r0) * in_r0;
    param_1 = param_1 / in_r0;
    cVar6 = (char)iVar4;
    if (iVar4 < 10) {
      cVar6 = cVar6 + '0';
    }
    else {
      if (param_3[5] == 'x') {
        cVar6 = cVar6 + 'W';
      }
      else {
        cVar6 = cVar6 + '7';
      }
    }
    pcVar3[-1] = cVar6;
    pcVar2 = pcVar3 + -1;
    iVar4 = iVar5 + 1;
  } while (param_1 != 0);
  if (((in_r0 == 8) && (param_3[3] != '\0')) && (*pcVar2 != '0')) {
    iVar4 = iVar5 + 2;
    pcVar2 = pcVar3 + -2;
    *pcVar2 = '0';
  }
  if (*param_3 == '\x02') {
    *(undefined4 *)(param_3 + 0xc) = *(undefined4 *)(param_3 + 8);
    if ((bVar1) || (param_3[1] != '\0')) {
      *(int *)(param_3 + 0xc) = *(int *)(param_3 + 0xc) + -1;
    }
    if ((in_r0 == 0x10) && (param_3[3] != '\0')) {
      *(int *)(param_3 + 0xc) = *(int *)(param_3 + 0xc) + -2;
    }
  }
  if (0x1fd < *(int *)(param_3 + 0xc) + (param_2 - (int)pcVar2)) {
    return (char *)0x0;
  }
  for (; iVar4 < *(int *)(param_3 + 0xc); iVar4 = iVar4 + 1) {
    pcVar2 = pcVar2 + -1;
    *pcVar2 = '0';
  }
  if ((in_r0 == 0x10) && (param_3[3] != '\0')) {
    pcVar2[-1] = param_3[5];
    pcVar2 = pcVar2 + -2;
    *pcVar2 = '0';
  }
  if (bVar1) {
    pcVar2 = pcVar2 + -1;
    *pcVar2 = '-';
  }
  else {
    if (param_3[1] == '\x01') {
      pcVar2 = pcVar2 + -1;
      *pcVar2 = '+';
    }
    else {
      if (param_3[1] == '\x02') {
        pcVar2 = pcVar2 + -1;
        *pcVar2 = ' ';
      }
    }
  }
  return pcVar2;
}


/* WARNING: Could not reconcile some variable overlaps */

char * parse_format(int param_1,undefined4 param_2,uint *param_3)

{
  bool bVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  undefined4 local_28;
  undefined4 local_24;
  uint local_20;
  uint local_1c;
  
  pcVar5 = (char *)(param_1 + 1);
  uVar4 = SEXT14((char)*(byte *)(param_1 + 1));
  local_28 = 0x1000000;
  local_24 = (uint)local_24._1_3_;
  local_20 = 0;
  local_1c = 0;
  if (uVar4 == 0x25) {
    local_24._1_3_ = local_24._1_3_ & 0xffff | (uint3)*(byte *)(param_1 + 1) << 0x10;
    local_24 = (uint)local_24._1_3_;
    *param_3 = 0x1000000;
    param_3[1] = local_24;
    param_3[2] = 0;
    param_3[3] = 0;
    return (char *)(param_1 + 2);
  }
  while( true ) {
    bVar1 = true;
    switch(uVar4) {
    case 0x20:
      if (local_28._1_1_ != '\x01') {
        local_28._1_3_ = CONCAT12(2,local_28._2_2_);
        local_28 = local_28 & 0xff000000 | (uint)local_28._1_3_;
      }
      break;
    default:
      bVar1 = false;
      break;
    case 0x23:
      local_28 = CONCAT31(local_28._0_3_,1);
      break;
    case 0x2b:
      local_28._1_3_ = CONCAT12(1,local_28._2_2_);
      local_28 = local_28 & 0xff000000 | (uint)local_28._1_3_;
      break;
    case 0x2d:
      local_28 = local_28 & 0xffffff;
      break;
    case 0x30:
      if (local_28._0_1_ != '\0') {
        local_28 = CONCAT13(2,local_28._1_3_);
      }
    }
    if (!bVar1) break;
    pcVar5 = pcVar5 + 1;
    uVar4 = SEXT14(*pcVar5);
  }
  if (uVar4 == 0x2a) {
    puVar3 = (uint *)Runtime.PPCEABI.H::__va_arg(param_2,1);
    local_20 = *puVar3;
    if ((int)local_20 < 0) {
      local_20 = -local_20;
      local_28 = local_28 & 0xffffff;
    }
    pcVar5 = pcVar5 + 1;
    uVar4 = SEXT14(*pcVar5);
  }
  else {
    while (((&__ctype_map)[uVar4 & 0xff] & 0x10) != 0) {
      pcVar5 = pcVar5 + 1;
      local_20 = (uVar4 + local_20 * 10) - 0x30;
      uVar4 = SEXT14(*pcVar5);
    }
  }
  if (0x1fd < (int)local_20) {
    local_24._1_3_ = CONCAT12(0xff,local_24._2_2_);
    local_24 = (uint)local_24._1_3_;
    *param_3 = local_28;
    param_3[1] = local_24;
    param_3[2] = local_20;
    param_3[3] = 0;
    return pcVar5 + 1;
  }
  pcVar6 = pcVar5;
  if (uVar4 == 0x2e) {
    pcVar6 = pcVar5 + 1;
    local_28._2_2_ = CONCAT11(1,(undefined)local_28);
    uVar2 = local_28 & 0xffff0000;
    local_28 = uVar2 | local_28._2_2_;
    uVar4 = SEXT14(*pcVar6);
    if (uVar4 == 0x2a) {
      puVar3 = (uint *)Runtime.PPCEABI.H::__va_arg(param_2,1);
      local_1c = *puVar3;
      if ((int)local_1c < 0) {
        local_28 = uVar2 | local_28._2_2_ & 0xffff00ff;
      }
      pcVar6 = pcVar5 + 2;
      uVar4 = SEXT14(*pcVar6);
    }
    else {
      while (((&__ctype_map)[uVar4 & 0xff] & 0x10) != 0) {
        pcVar6 = pcVar6 + 1;
        local_1c = (uVar4 + local_1c * 10) - 0x30;
        uVar4 = SEXT14(*pcVar6);
      }
    }
  }
  bVar1 = true;
  if (uVar4 == 0x68) {
    pcVar5 = pcVar6 + 1;
    local_24 = CONCAT13(2,local_24._1_3_);
    if ((int)*pcVar5 == 0x68) {
      local_24 = CONCAT13(1,local_24._1_3_);
      pcVar6 = pcVar6 + 1;
      uVar4 = (int)*pcVar5;
    }
  }
  else {
    if ((int)uVar4 < 0x68) {
      if (uVar4 == 0x4c) {
        local_24 = CONCAT13(5,local_24._1_3_);
        goto LAB_8032d7cc;
      }
    }
    else {
      if (uVar4 == 0x6c) {
        pcVar5 = pcVar6 + 1;
        local_24 = CONCAT13(3,local_24._1_3_);
        if ((int)*pcVar5 == 0x6c) {
          local_24 = CONCAT13(4,local_24._1_3_);
          pcVar6 = pcVar6 + 1;
          uVar4 = (int)*pcVar5;
        }
        goto LAB_8032d7cc;
      }
    }
    bVar1 = false;
  }
LAB_8032d7cc:
  if (bVar1) {
    pcVar6 = pcVar6 + 1;
    uVar4 = SEXT14(*pcVar6);
  }
  local_24._1_3_ = CONCAT12((char)uVar4,local_24._2_2_);
  uVar2 = local_24 & 0xff000000;
  local_24 = uVar2 | local_24._1_3_;
  local_24._0_1_ = (char)(uVar2 >> 0x18);
  switch(uVar4) {
  case 0x41:
  case 0x61:
    if (local_28._2_1_ == '\0') {
      local_1c = 0xd;
    }
    if (((local_24._0_1_ == '\x02') || (local_24._0_1_ == '\x04')) || (local_24._0_1_ == '\x01')) {
      local_24._1_3_ = CONCAT12(0xff,local_24._2_2_);
      local_24 = uVar2 | local_24._1_3_;
    }
    break;
  default:
    local_24._1_3_ = CONCAT12(0xff,local_24._2_2_);
    local_24 = uVar2 | local_24._1_3_;
    break;
  case 0x46:
  case 0x66:
    if ((local_24._0_1_ == '\x02') || (local_24._0_1_ == '\x04')) {
      local_24._1_3_ = CONCAT12(0xff,local_24._2_2_);
      local_24 = uVar2 | local_24._1_3_;
    }
    else {
      if (local_28._2_1_ == '\0') {
        local_1c = 6;
      }
    }
    break;
  case 0x47:
  case 0x67:
    if (local_1c == 0) {
      local_1c = 1;
    }
  case 0x45:
  case 0x65:
    if (((local_24._0_1_ == '\x02') || (local_24._0_1_ == '\x04')) || (local_24._0_1_ == '\x01')) {
      local_24._1_3_ = CONCAT12(0xff,local_24._2_2_);
      local_24 = uVar2 | local_24._1_3_;
    }
    else {
      if (local_28._2_1_ == '\0') {
        local_1c = 6;
      }
    }
    break;
  case 0x58:
  case 100:
  case 0x69:
  case 0x6f:
  case 0x75:
  case 0x78:
    if (local_24._0_1_ == '\x05') {
      local_24._1_3_ = CONCAT12(0xff,local_24._2_2_);
      local_24 = uVar2 | local_24._1_3_;
    }
    else {
      if (local_28._2_1_ == '\0') {
        local_1c = 1;
      }
      else {
        if (local_28._0_1_ == '\x02') {
          local_28 = CONCAT13(1,local_28._1_3_);
        }
      }
    }
    break;
  case 99:
    if (local_24._0_1_ == '\x03') {
      local_24 = CONCAT13(6,local_24._1_3_);
    }
    else {
      if ((local_28._2_1_ != '\0') || (local_24._0_1_ != '\0')) {
        local_24._1_3_ = CONCAT12(0xff,local_24._2_2_);
        local_24 = uVar2 | local_24._1_3_;
      }
    }
    break;
  case 0x6e:
    if (local_24._0_1_ == '\x05') {
      local_24._1_3_ = CONCAT12(0xff,local_24._2_2_);
      local_24 = uVar2 | local_24._1_3_;
    }
    break;
  case 0x70:
    local_24._1_3_ = CONCAT12(0x78,local_24._2_2_);
    local_28 = CONCAT31(local_28._0_3_,1);
    local_24 = CONCAT13(3,local_24._1_3_);
    local_1c = 8;
    break;
  case 0x73:
    if (local_24._0_1_ == '\x03') {
      local_24 = CONCAT13(6,local_24._1_3_);
    }
    else {
      if (local_24._0_1_ != '\0') {
        local_24._1_3_ = CONCAT12(0xff,local_24._2_2_);
        local_24 = uVar2 | local_24._1_3_;
      }
    }
  }
  *param_3 = local_28;
  param_3[1] = local_24;
  param_3[2] = local_20;
  param_3[3] = local_1c;
  return pcVar6 + 1;
}

