#pragma once

#include <dolphin/types.h>

namespace mtx {

	// 3D vector, point
	typedef struct
	{
		f32 x, y, z;

	} Vec, *VecPtr, Point3d, *Point3dPtr;

	// Signed 16bit 3D vector
	typedef struct
	{
		s16 x;
		s16 y;
		s16 z;

	} S16Vec, *S16VecPtr;

	// quaternion
	typedef struct
	{
		f32 x, y, z, w;

	} Quaternion, *QuaternionPtr, Qtrn, *QtrnPtr;

	// 3x4 matrix, pointer
	typedef f32 Mtx[3][4];

	typedef f32 (*MtxPtr)[4];

	// 4x3 reordered matrix, pointer
	typedef f32 ROMtx[4][3];

	typedef f32 (*ROMtxPtr)[3];

	// 4x4 matrix , pointer
	// used for projection matrix
	typedef f32 Mtx44[4][4];

	typedef f32 (*Mtx44Ptr)[4];

}