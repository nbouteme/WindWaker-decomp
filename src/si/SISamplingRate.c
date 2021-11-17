#include <si/SISamplingRate.h>
#include <os/OSInterrupt.h>
#include <vi/vi.h>
#include <m_Do_printf.h>
#include <si/SIBios.h>
#include <si/SISamplingRate.h>


namespace si {
undefined4 SamplingRate;

void SISetSamplingRate(uint param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined2 *puVar3;
  
  puVar3 = &XYNTSC;
  if (0xb < param_1) {
    param_1 = 0xb;
  }
  uVar1 = os::OSDisableInterrupts();
  SamplingRate = param_1;
  iVar2 = vi::VIGetTvFormat();
  if (iVar2 == 2) {
LAB_8030cf10:
    puVar3 = &XYNTSC;
  }
  else {
    if (iVar2 < 2) {
      if (iVar2 == 0) goto LAB_8030cf10;
      if (-1 < iVar2) {
        puVar3 = (undefined2 *)&XYPAL;
        goto LAB_8030cf34;
      }
    }
    else {
      if (iVar2 == 5) goto LAB_8030cf10;
    }
    m_Do_printf::OSReport(_16);
    param_1 = 0;
  }
LAB_8030cf34:
  if ((DAT_cc00206c & 1) == 0) {
    iVar2 = 1;
  }
  else {
    iVar2 = 2;
  }
  SISetXY(iVar2 * (uint)(ushort)puVar3[param_1 * 2],*(undefined *)(puVar3 + param_1 * 2 + 1));
  os::OSRestoreInterrupts(uVar1);
  return;
}


void SIRefreshSamplingRate(void)

{
  SISetSamplingRate(SamplingRate);
  return;
}

