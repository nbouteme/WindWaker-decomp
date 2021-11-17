#include <SComponent/c_API_graphic.h>
#include <m_Do_graphic.h>


namespace SComponent {

/* __stdcall cAPIGph_Painter(void) */

void cAPIGph_Painter(void)

{
  (*(code *)PTR_mDoGph_Painter_803950e8)();
  return;
}


/* __stdcall cAPIGph_BeforeOfDraw(void) */

void cAPIGph_BeforeOfDraw(void)

{
  (*(code *)PTR_mDoGph_BeforeOfDraw_803950e0)();
  return;
}


/* __stdcall cAPIGph_AfterOfDraw(void) */

void cAPIGph_AfterOfDraw(void)

{
  (*(code *)PTR_mDoGph_AfterOfDraw_803950e4)();
  return;
}

