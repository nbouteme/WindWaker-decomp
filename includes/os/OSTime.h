#pragma once
#include <ctypes.h>



namespace os {
//[Data] Expected size is 0x000030
extern undefined YearDays;

//[Data] Expected size is 0x000030
extern undefined LeapYearDays;

int OSGetTime(void);
void OSGetTick(void);
undefined8 __OSGetSystemTime(void);
undefined8 __OSTimeToSystemTime(int param_1,uint param_2);
void GetDates(int param_1,int param_2);
void OSTicksToCalendarTime(int32_t param_1,int32_t param_2,OSCalendarTime *param_3);
}
