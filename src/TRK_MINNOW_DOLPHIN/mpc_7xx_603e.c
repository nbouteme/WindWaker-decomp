#include <TRK_MINNOW_DOLPHIN/mpc_7xx_603e.h>


namespace TRK_MINNOW_DOLPHIN {

void TRKSaveExtended1Block(void)

{
  undefined4 in_sr0;
  undefined4 in_sr1;
  undefined4 in_sr2;
  undefined4 in_sr3;
  undefined4 in_sr4;
  undefined4 in_sr5;
  undefined4 in_sr6;
  undefined4 in_sr7;
  undefined4 in_sr8;
  undefined4 in_sr9;
  undefined4 in_sr10;
  undefined4 in_sr11;
  undefined4 in_sr12;
  undefined4 in_sr13;
  undefined4 in_sr14;
  undefined4 in_sr15;
  undefined4 in_DSISR;
  undefined4 in_DAR;
  undefined4 in_SDR1;
  undefined4 in_SRR1;
  undefined4 in_TBLr;
  undefined4 in_TBUr;
  undefined4 in_SPRG0;
  undefined4 in_SPRG1;
  undefined4 in_SPRG2;
  undefined4 in_SPRG3;
  undefined4 in_EAR;
  undefined4 in_PVR;
  undefined4 in_IBAT0U;
  undefined4 in_IBAT0L;
  undefined4 in_IBAT1U;
  undefined4 in_IBAT1L;
  undefined4 in_IBAT2U;
  undefined4 in_IBAT2L;
  undefined4 in_IBAT3U;
  undefined4 in_IBAT3L;
  undefined4 in_DBAT0U;
  undefined4 in_DBAT0L;
  undefined4 in_DBAT1U;
  undefined4 in_DBAT1L;
  undefined4 in_DBAT2U;
  undefined4 in_DBAT2L;
  undefined4 in_DBAT3U;
  undefined4 in_DBAT3L;
  undefined4 in_GQR1;
  undefined4 in_GQR7;
  undefined4 in_HID2;
  undefined4 in_WPAR;
  undefined4 in_DMAU;
  undefined4 in_DMAL;
  undefined4 in_MMCR0;
  undefined4 in_PMC1;
  undefined4 in_PMC2;
  undefined4 in_SIA;
  undefined4 in_MMCR1;
  undefined4 in_PMC3;
  undefined4 in_PMC4;
  undefined4 in_HID0;
  undefined4 in_HID1;
  undefined4 in_IABR;
  undefined4 in_DABR;
  undefined4 in_L2CR;
  undefined4 in_ICTC;
  undefined4 in_THRM1;
  undefined4 in_THRM2;
  undefined4 in_THRM3;
  
  DAT_803f3b58 = in_sr0;
  DAT_803f3b5c = in_sr1;
  DAT_803f3b60 = in_sr2;
  DAT_803f3b64 = in_sr3;
  DAT_803f3b68 = in_sr4;
  DAT_803f3b6c = in_sr5;
  DAT_803f3b70 = in_sr6;
  DAT_803f3b74 = in_sr7;
  DAT_803f3b78 = in_sr8;
  DAT_803f3b7c = in_sr9;
  DAT_803f3b80 = in_sr10;
  DAT_803f3b84 = in_sr11;
  DAT_803f3b88 = in_sr12;
  DAT_803f3b8c = in_sr13;
  DAT_803f3b90 = in_sr14;
  DAT_803f3b94 = in_sr15;
  DAT_803f3b98 = in_TBLr;
  DAT_803f3b9c = in_TBUr;
  DAT_803f3ba0 = in_HID0;
  DAT_803f3ba4 = in_HID1;
  DAT_803f3ba8 = in_SRR1;
  DAT_803f3bac = in_PVR;
  DAT_803f3bb0 = in_IBAT0U;
  DAT_803f3bb4 = in_IBAT0L;
  DAT_803f3bb8 = in_IBAT1U;
  DAT_803f3bbc = in_IBAT1L;
  DAT_803f3bc0 = in_IBAT2U;
  DAT_803f3bc4 = in_IBAT2L;
  DAT_803f3bc8 = in_IBAT3U;
  DAT_803f3bcc = in_IBAT3L;
  DAT_803f3bd0 = in_DBAT0U;
  DAT_803f3bd4 = in_DBAT0L;
  DAT_803f3bd8 = in_DBAT1U;
  DAT_803f3bdc = in_DBAT1L;
  DAT_803f3be0 = in_DBAT2U;
  DAT_803f3be4 = in_DBAT2L;
  DAT_803f3be8 = in_DBAT3U;
  DAT_803f3bec = in_DBAT3L;
  DAT_803f3c0c = in_SDR1;
  DAT_803f3c10 = in_DAR;
  DAT_803f3c14 = in_DSISR;
  DAT_803f3c18 = in_SPRG0;
  DAT_803f3c1c = in_SPRG1;
  DAT_803f3c20 = in_SPRG2;
  DAT_803f3c24 = in_SPRG3;
  DAT_803f3c28 = 0;
  DAT_803f3c2c = in_IABR;
  DAT_803f3c30 = in_EAR;
  DAT_803f3c34 = in_DABR;
  DAT_803f3c38 = in_PMC1;
  DAT_803f3c3c = in_PMC2;
  DAT_803f3c40 = in_PMC3;
  DAT_803f3c44 = in_PMC4;
  DAT_803f3c48 = in_SIA;
  DAT_803f3c4c = in_MMCR0;
  DAT_803f3c50 = in_MMCR1;
  DAT_803f3c54 = in_THRM1;
  DAT_803f3c58 = in_THRM2;
  DAT_803f3c5c = in_THRM3;
  DAT_803f3c60 = in_ICTC;
  DAT_803f3c64 = in_L2CR;
  DAT_803f3cac = 0;
  DAT_803f3cb0 = in_GQR1;
  DAT_803f3cb4 = 0x40004;
  DAT_803f3cb8 = 0x50005;
  DAT_803f3cbc = 0x60006;
  DAT_803f3cc0 = 0x70007;
  DAT_803f3cc4 = 0x3d043d04;
  DAT_803f3cc8 = in_GQR7;
  DAT_803f3ccc = in_HID2;
  DAT_803f3cd0 = in_WPAR;
  DAT_803f3cd4 = in_DMAU;
  DAT_803f3cd8 = in_DMAL;
  return;
}


void TRKRestoreExtended1Block(void)

{
  gTRKRestoreFlags = 0;
  DAT_803a28c1 = 0;
  return;
}


undefined4 TRKTargetCPUMinorType(void)

{
  return 0x54;
}

