#pragma once
    
/*---------------------------------------------------------------------------*/
#include <dolphin/types.h>
#include <dolphin/gx/GXEnum.h>
namespace gx {
/*---------------------------------------------------------------------------*/
void GXSetGPMetric     (  GXPerf0       perf0,
                          GXPerf1       perf1 );

void GXClearGPMetric   (  void );

void GXReadGPMetric    (  u32*          cnt0,
                          u32*          cnt1 );


#define GXSetGP0Metric(perf0)    GXSetGPMetric((perf0), GX_PERF1_NONE)

#define GXClearGP0Metric()       GXClearGPMetric()

u32  GXReadGP0Metric   ( void );


#define GXSetGP1Metric(perf1)    GXSetGPMetric(GX_PERF0_NONE, (perf1))

#define GXClearGP1Metric()       GXClearGPMetric()

u32  GXReadGP1Metric   ( void );


void GXReadMemMetric   ( u32*           cp_req,
                         u32*           tc_req,
                         u32*           cpu_rd_req,
                         u32*           cpu_wr_req,
                         u32*           dsp_req,
                         u32*           io_req,
                         u32*           vi_req,
                         u32*           pe_req,
                         u32*           rf_req,
                         u32*           fi_req );

void GXClearMemMetric  ( void );


void GXReadPixMetric   (  u32*          top_pixels_in, 
                          u32*          top_pixels_out, 
                          u32*          bot_pixels_in, 
                          u32*          bot_pixels_out,
                          u32*          clr_pixels_in,
                          u32*          copy_clks );

void GXClearPixMetric  (  void  );


void GXSetVCacheMetric  ( GXVCachePerf  attr );

void GXReadVCacheMetric ( u32*          check, 
                          u32*          miss, 
                          u32*          stall );

void GXClearVCacheMetric ( void );


// DO NOT use with GXReadGP*Metric
void GXReadXfRasMetric  ( u32*          xf_wait_in,
                          u32*          xf_wait_out,
                          u32*          ras_busy,
                          u32*          clocks );

// DO NOT use with GXReadGP*Metric
void GXInitXfRasMetric();

    
u32 GXReadClksPerVtx( void );

/*---------------------------------------------------------------------------*/

void __GXSetBWDials     ( u16           cpDial,
                          u16           tcDial,
                          u16           peDial,
                          u16           cpuRdDial,
                          u16           cpuWrDial );
}