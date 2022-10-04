#pragma once
namespace os {

#define register
#ifndef _WIN32

#ifdef GEKKO

#else
/*---------------------------------------------------------------------------*
  Non-Gekko code
 *---------------------------------------------------------------------------*/
static inline void OSInitFastCast(void) {
	while (0) {
	}
}

/*---------------------------------------------------------------------------*
  int to float
 *---------------------------------------------------------------------------*/
static inline void OSs16tof32(s16* in, f32* out) {
	*out = (f32)*in;
}

static inline void OSs8tof32(s8* in, f32* out) {
	*out = (f32)*in;
}

static inline void OSu16tof32(u16* in, f32* out) {
	*out = (f32)*in;
}

static inline void OSu8tof32(u8* in, f32* out) {
	*out = (f32)*in;
}

/*---------------------------------------------------------------------------*
  float to int
 *---------------------------------------------------------------------------*/

static inline void OSf32tou8(register f32* in, register u8* out) {
	*out = (u8)*in;
}

static inline void OSf32tou16(register f32* in, register u16* out) {
	*out = (u16)*in;
}

static inline void OSf32tos8(register f32* in, register s8* out) {
	*out = (s8)*in;
}

static inline void OSf32tos16(register f32* in, register s16* out) {
	*out = (s16)*in;
}

#endif	// GEKKO

#endif	// _WIN32
}