#pragma once

#include <doltypes.h>

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

/*---------------------------------------------------------------------------*
    Default function binding configuration
 *---------------------------------------------------------------------------*/
// [Binding Rule]
//
// "MTX_USE_PS" -> When this flag is specified, it uses PS* (Paired-Single
//                 assembler code) functions for non-prefixed function calls.
// "MTX_USE_C " -> When this flag is specified, it uses C_* (C code) functions
//                 for non-prefixed function calls.
//
// If both are specified, it will be treated as MTX_USE_PS.
// If nothing is specified, NDEBUG build refers PS* functions and
// DEBUG build uses C_* functions.

// For non-Gekko HW (e.g. emulator)
#ifndef GEKKO
#define MTX_USE_C
#undef MTX_USE_PS
#endif

#if (!defined(MTX_USE_PS) && !defined(MTX_USE_C))
#ifndef _DEBUG
#define MTX_USE_PS
#endif
#endif

/*---------------------------------------------------------------------------*
    Macro definitions
 *---------------------------------------------------------------------------*/

// MtxPtr offset to access next Mtx of an array
#define MTX_PTR_OFFSET 3

// Mtx44Ptr offset to access next Mtx44 of an array
#define MTX44_PTR_OFFSET 4

	// matrix stack
	typedef struct
	{
		u32 numMtx;
		MtxPtr stackBase;
		MtxPtr stackPtr;

	} MtxStack, *MtxStackPtr;

// degree <--> radian conversion macros
#define MTXDegToRad(a) ((a)*0.01745329252f)
#define MTXRadToDeg(a) ((a)*57.29577951f)

	// Matrix-element-referencing macro.
	// Insulates user from changes from row-major to column-major and vice-versa.
	// Fully documents which index is row, which index is column.
	// XXX this version will change once matrices are transposed.

#define MTXRowCol(m, r, c) ((m)[(r)][(c)])

	/*---------------------------------------------------------------------------*
    GENERAL MATRIX SECTION
 *---------------------------------------------------------------------------*/
	// C version
	void C_MTXIdentity(Mtx m);
	void C_MTXCopy(const Mtx src, Mtx dst);
	void C_MTXConcat(const Mtx a, const Mtx b, Mtx ab);
	void C_MTXConcatArray(const Mtx a, const Mtx *srcBase, Mtx *dstBase, u32 count);
	void C_MTXTranspose(const Mtx src, Mtx xPose);
	u32 C_MTXInverse(const Mtx src, Mtx inv);
	u32 C_MTXInvXpose(const Mtx src, Mtx invX);

// PS assembler version
#ifdef GEKKO
	void PSMTXIdentity(Mtx m);
	void PSMTXCopy(const Mtx src, Mtx dst);
	void PSMTXConcat(const Mtx a, const Mtx b, Mtx ab);
	void PSMTXConcatArray(const Mtx a, const Mtx *srcBase, Mtx *dstBase, u32 count);
	void PSMTXTranspose(const Mtx src, Mtx xPose);
	u32 PSMTXInverse(const Mtx src, Mtx inv);
	u32 PSMTXInvXpose(const Mtx src, Mtx invX);
#endif

// Bindings
#ifdef MTX_USE_PS
#define MTXIdentity PSMTXIdentity
#define MTXCopy PSMTXCopy
#define MTXConcat PSMTXConcat
#define MTXConcatArray PSMTXConcatArray
#define MTXTranspose PSMTXTranspose
#define MTXInverse PSMTXInverse
#define MTXInvXpose PSMTXInvXpose
#else  // MTX_USE_C
#define MTXIdentity C_MTXIdentity
#define MTXCopy C_MTXCopy
#define MTXConcat C_MTXConcat
#define MTXConcatArray C_MTXConcatArray
#define MTXTranspose C_MTXTranspose
#define MTXInverse C_MTXInverse
#define MTXInvXpose C_MTXInvXpose
#endif

	/*---------------------------------------------------------------------------*
    MATRIX-VECTOR SECTION
 *---------------------------------------------------------------------------*/
	// C version
	void C_MTXMultVec(const Mtx m, const Vec *src, Vec *dst);
	void C_MTXMultVecArray(const Mtx m, const Vec *srcBase, Vec *dstBase, u32 count);
	void C_MTXMultVecSR(const Mtx m, const Vec *src, Vec *dst);
	void C_MTXMultVecArraySR(const Mtx m, const Vec *srcBase, Vec *dstBase, u32 count);

// PS assembler version
#ifdef GEKKO
	void PSMTXMultVec(const Mtx m, const Vec *src, Vec *dst);
	void PSMTXMultVecArray(const Mtx m, const Vec *srcBase, Vec *dstBase, u32 count);
	void PSMTXMultVecSR(const Mtx m, const Vec *src, Vec *dst);
	void PSMTXMultVecArraySR(const Mtx m, const Vec *srcBase, Vec *dstBase, u32 count);
#endif

// Bindings
#ifdef MTX_USE_PS
#define MTXMultVec PSMTXMultVec
#define MTXMultVecArray PSMTXMultVecArray
#define MTXMultVecSR PSMTXMultVecSR
#define MTXMultVecArraySR PSMTXMultVecArraySR
#else  // MTX_USE_C
#define MTXMultVec C_MTXMultVec
#define MTXMultVecArray C_MTXMultVecArray
#define MTXMultVecSR C_MTXMultVecSR
#define MTXMultVecArraySR C_MTXMultVecArraySR
#endif

	/*---------------------------------------------------------------------------*
    MODEL MATRIX SECTION
 *---------------------------------------------------------------------------*/
	// C version
	void C_MTXQuat(Mtx m, const Quaternion *q);
	void C_MTXReflect(Mtx m, const Vec *p, const Vec *n);

	void C_MTXTrans(Mtx m, f32 xT, f32 yT, f32 zT);
	void C_MTXTransApply(const Mtx src, Mtx dst, f32 xT, f32 yT, f32 zT);
	void C_MTXScale(Mtx m, f32 xS, f32 yS, f32 zS);
	void C_MTXScaleApply(const Mtx src, Mtx dst, f32 xS, f32 yS, f32 zS);

	void C_MTXRotRad(Mtx m, char axis, f32 rad);
	void C_MTXRotTrig(Mtx m, char axis, f32 sinA, f32 cosA);
	void C_MTXRotAxisRad(Mtx m, const Vec *axis, f32 rad);

// PS assembler version
#ifdef GEKKO
	void PSMTXQuat(Mtx m, const Quaternion *q);
	void PSMTXReflect(Mtx m, const Vec *p, const Vec *n);

	void PSMTXTrans(Mtx m, f32 xT, f32 yT, f32 zT);
	void PSMTXTransApply(const Mtx src, Mtx dst, f32 xT, f32 yT, f32 zT);
	void PSMTXScale(Mtx m, f32 xS, f32 yS, f32 zS);
	void PSMTXScaleApply(const Mtx src, Mtx dst, f32 xS, f32 yS, f32 zS);

	void PSMTXRotRad(Mtx m, char axis, f32 rad);
	void PSMTXRotTrig(Mtx m, char axis, f32 sinA, f32 cosA);
	void PSMTXRotAxisRad(Mtx m, const Vec *axis, f32 rad);
#endif

// Bindings
#ifdef MTX_USE_PS
#define MTXQuat PSMTXQuat
#define MTXReflect PSMTXReflect
#define MTXTrans PSMTXTrans
#define MTXTransApply PSMTXTransApply
#define MTXScale PSMTXScale
#define MTXScaleApply PSMTXScaleApply
#define MTXRotRad PSMTXRotRad
#define MTXRotTrig PSMTXRotTrig
#define MTXRotAxisRad PSMTXRotAxisRad

#define MTXRotDeg(m, axis, deg) \
	PSMTXRotRad(m, axis, MTXDegToRad(deg))
#define MTXRotAxisDeg(m, axis, deg) \
	PSMTXRotAxisRad(m, axis, MTXDegToRad(deg))

#else  // MTX_USE_C
#define MTXQuat C_MTXQuat
#define MTXReflect C_MTXReflect
#define MTXTrans C_MTXTrans
#define MTXTransApply C_MTXTransApply
#define MTXScale C_MTXScale
#define MTXScaleApply C_MTXScaleApply
#define MTXRotRad C_MTXRotRad
#define MTXRotTrig C_MTXRotTrig
#define MTXRotAxisRad C_MTXRotAxisRad

#define MTXRotDeg(m, axis, deg) \
	C_MTXRotRad(m, axis, MTXDegToRad(deg))
#define MTXRotAxisDeg(m, axis, deg) \
	C_MTXRotAxisRad(m, axis, MTXDegToRad(deg))

#endif

// Obsoleted. Don't use this if possible.
#define MTXRotAxis MTXRotAxisDeg

	/*---------------------------------------------------------------------------*
    VIEW MATRIX SECTION
 *---------------------------------------------------------------------------*/
	// C version only so far
	void C_MTXLookAt(Mtx m,
					 const Point3d *camPos,
					 const Vec *camUp,
					 const Point3d *target);

// Bindings
#define MTXLookAt C_MTXLookAt

	/*---------------------------------------------------------------------------*
    PROJECTION MATRIX SECTION
 *---------------------------------------------------------------------------*/
	// C version only so far
	void C_MTXFrustum(Mtx44 m, f32 t, f32 b, f32 l, f32 r, f32 n, f32 f);
	void C_MTXPerspective(Mtx44 m, f32 fovY, f32 aspect, f32 n, f32 f);
	void C_MTXOrtho(Mtx44 m, f32 t, f32 b, f32 l, f32 r, f32 n, f32 f);

// Bindings
#define MTXFrustum C_MTXFrustum
#define MTXPerspective C_MTXPerspective
#define MTXOrtho C_MTXOrtho

	/*---------------------------------------------------------------------------*
    TEXTURE PROJECTION MATRIX SECTION
 *---------------------------------------------------------------------------*/
	// C version only so far
	void C_MTXLightFrustum(Mtx m, f32 t, f32 b, f32 l, f32 r, f32 n,
						   f32 scaleS, f32 scaleT, f32 transS,
						   f32 transT);

	void C_MTXLightPerspective(Mtx m, f32 fovY, f32 aspect, f32 scaleS,
							   f32 scaleT, f32 transS, f32 transT);

	void C_MTXLightOrtho(Mtx m, f32 t, f32 b, f32 l, f32 r, f32 scaleS,
						 f32 scaleT, f32 transS, f32 transT);

// Bindings
#define MTXLightFrustum C_MTXLightFrustum
#define MTXLightPerspective C_MTXLightPerspective
#define MTXLightOrtho C_MTXLightOrtho

	/*---------------------------------------------------------------------------*
    VECTOR SECTION
 *---------------------------------------------------------------------------*/
	// C version
	void C_VECAdd(const Vec *a, const Vec *b, Vec *ab);
	void C_VECSubtract(const Vec *a, const Vec *b, Vec *a_b);
	void C_VECScale(const Vec *src, Vec *dst, f32 scale);
	void C_VECNormalize(const Vec *src, Vec *unit);
	f32 C_VECSquareMag(const Vec *v);
	f32 C_VECMag(const Vec *v);
	f32 C_VECDotProduct(const Vec *a, const Vec *b);
	void C_VECCrossProduct(const Vec *a, const Vec *b, Vec *axb);
	f32 C_VECSquareDistance(const Vec *a, const Vec *b);
	f32 C_VECDistance(const Vec *a, const Vec *b);
	void C_VECReflect(const Vec *src, const Vec *normal, Vec *dst);
	void C_VECHalfAngle(const Vec *a, const Vec *b, Vec *half);

// PS assembler version
#ifdef GEKKO
	void PSVECAdd(const Vec *a, const Vec *b, Vec *ab);
	void PSVECSubtract(const Vec *a, const Vec *b, Vec *a_b);
	void PSVECScale(const Vec *src, Vec *dst, f32 scale);
	void PSVECNormalize(const Vec *src, Vec *unit);
	f32 PSVECSquareMag(const Vec *v);
	f32 PSVECMag(const Vec *v);
	f32 PSVECDotProduct(const Vec *a, const Vec *b);
	void PSVECCrossProduct(const Vec *a, const Vec *b, Vec *axb);
	f32 PSVECSquareDistance(const Vec *a, const Vec *b);
	f32 PSVECDistance(const Vec *a, const Vec *b);
#endif

// Bindings
#ifdef MTX_USE_PS
#define VECAdd PSVECAdd
#define VECSubtract PSVECSubtract
#define VECScale PSVECScale
#define VECNormalize PSVECNormalize
#define VECSquareMag PSVECSquareMag
#define VECMag PSVECMag
#define VECDotProduct PSVECDotProduct
#define VECCrossProduct PSVECCrossProduct
#define VECSquareDistance PSVECSquareDistance
#define VECDistance PSVECDistance
#else  // MTX_USE_C
#define VECAdd C_VECAdd
#define VECSubtract C_VECSubtract
#define VECScale C_VECScale
#define VECNormalize C_VECNormalize
#define VECSquareMag C_VECSquareMag
#define VECMag C_VECMag
#define VECDotProduct C_VECDotProduct
#define VECCrossProduct C_VECCrossProduct
#define VECSquareDistance C_VECSquareDistance
#define VECDistance C_VECDistance
#endif

#define VECReflect C_VECReflect
#define VECHalfAngle C_VECHalfAngle

	/*---------------------------------------------------------------------------*
    QUATERNION SECTION
 *---------------------------------------------------------------------------*/
	// C version
	void C_QUATAdd(const Quaternion *p, const Quaternion *q, Quaternion *r);
	void C_QUATSubtract(const Quaternion *p, const Quaternion *q, Quaternion *r);
	void C_QUATMultiply(const Quaternion *p, const Quaternion *q, Quaternion *pq);
	void C_QUATDivide(const Quaternion *p, const Quaternion *q, Quaternion *r);
	void C_QUATScale(const Quaternion *q, Quaternion *r, f32 scale);
	f32 C_QUATDotProduct(const Quaternion *p, const Quaternion *q);
	void C_QUATNormalize(const Quaternion *src, Quaternion *unit);
	void C_QUATInverse(const Quaternion *src, Quaternion *inv);
	void C_QUATExp(const Quaternion *q, Quaternion *r);
	void C_QUATLogN(const Quaternion *q, Quaternion *r);

	void C_QUATMakeClosest(const Quaternion *q, const Quaternion *qto, Quaternion *r);
	void C_QUATRotAxisRad(Quaternion *r, const Vec *axis, f32 rad);
	void C_QUATMtx(Quaternion *r, const Mtx m);

	void C_QUATLerp(const Quaternion *p, const Quaternion *q, Quaternion *r, f32 t);
	void C_QUATSlerp(const Quaternion *p, const Quaternion *q, Quaternion *r, f32 t);
	void C_QUATSquad(const Quaternion *p, const Quaternion *a, const Quaternion *b,
					 const Quaternion *q, Quaternion *r, f32 t);
	void C_QUATCompA(const Quaternion *qprev, const Quaternion *q,
					 const Quaternion *qnext, Quaternion *a);

// PS assembler version
#ifdef GEKKO
	void PSQUATAdd(const Quaternion *p, const Quaternion *q, Quaternion *r);
	void PSQUATSubtract(const Quaternion *p, const Quaternion *q, Quaternion *r);
	void PSQUATMultiply(const Quaternion *p, const Quaternion *q, Quaternion *pq);
	void PSQUATDivide(const Quaternion *p, const Quaternion *q, Quaternion *r);
	void PSQUATScale(const Quaternion *q, Quaternion *r, f32 scale);
	f32 PSQUATDotProduct(const Quaternion *p, const Quaternion *q);
	void PSQUATNormalize(const Quaternion *src, Quaternion *unit);
	void PSQUATInverse(const Quaternion *src, Quaternion *inv);
#endif

// Bindings
#ifdef MTX_USE_PS
#define QUATAdd PSQUATAdd
#define QUATSubtract PSQUATSubtract
#define QUATMultiply PSQUATMultiply
#define QUATDivide PSQUATDivide
#define QUATScale PSQUATScale
#define QUATDotProduct PSQUATDotProduct
#define QUATNormalize PSQUATNormalize
#define QUATInverse PSQUATInverse
#else  // MTX_USE_C
#define QUATAdd C_QUATAdd
#define QUATSubtract C_QUATSubtract
#define QUATMultiply C_QUATMultiply
#define QUATDivide C_QUATDivide
#define QUATScale C_QUATScale
#define QUATDotProduct C_QUATDotProduct
#define QUATNormalize C_QUATNormalize
#define QUATInverse C_QUATInverse
#endif

#define QUATExp C_QUATExp
#define QUATLogN C_QUATLogN
#define QUATMakeClosest C_QUATMakeClosest
#define QUATRotAxisRad C_QUATRotAxisRad
#define QUATMtx C_QUATMtx
#define QUATLerp C_QUATLerp
#define QUATSlerp C_QUATSlerp
#define QUATSquad C_QUATSquad
#define QUATCompA C_QUATCompA

/*---------------------------------------------------------------------------*
    SPECIAL PURPOSE MATRIX SECTION
 *---------------------------------------------------------------------------*/
// Only PS assembler versions are available
#ifdef GEKKO
	void PSMTXReorder(const Mtx src, ROMtx dest);
	void PSMTXROMultVecArray(const ROMtx m, const Vec *srcBase, Vec *dstBase, u32 count);
	void PSMTXROSkin2VecArray(const ROMtx m0, const ROMtx m1, const f32 *wtBase, const Vec *srcBase, Vec *dstBase, u32 count);
	void PSMTXMultS16VecArray(const Mtx m, const S16Vec *srcBase, Vec *dstBase, u32 count);
	void PSMTXROMultS16VecArray(const ROMtx m, const S16Vec *srcBase, Vec *dstBase, u32 count);
#endif

	/*---------------------------------------------------------------------------*
    MATRIX STACK SECTION
 *---------------------------------------------------------------------------*/
	void MTXInitStack(MtxStack *sPtr, u32 numMtx);
	MtxPtr MTXPush(MtxStack *sPtr, const Mtx m);
	MtxPtr MTXPushFwd(MtxStack *sPtr, const Mtx m);
	MtxPtr MTXPushInv(MtxStack *sPtr, const Mtx m);
	MtxPtr MTXPushInvXpose(MtxStack *sPtr, const Mtx m);
	MtxPtr MTXPop(MtxStack *sPtr);
	MtxPtr MTXGetStackPtr(const MtxStack *sPtr);

// macro to create a matrix stack.
// the macro exposes the  use of OSAlloc() for
// ease of replacement if desired.
#define MTXAllocStack(sPtr, numMtx) (((MtxStackPtr)(sPtr))->stackBase = (MtxPtr)OSAlloc(((numMtx) * sizeof(Mtx))))

// macro to free a matrix stack
#define MTXFreeStack(sPtr) (OSFree((void *)(((MtxStackPtr)(sPtr))->stackBase)))

	/*---------------------------------------------------------------------------*
    Matrix-Vector Library : 4x4 matrix extension
 *---------------------------------------------------------------------------*/

	/*---------------------------------------------------------------------------*
    Default function binding configuration
 *---------------------------------------------------------------------------*/
	/*
(Defined in mtx.h)

// [Binding Rule]
//
// "MTX_USE_PS" -> When this flag is specified, it uses PS* (Paired-Single
//                 assembler code) functions for non-prefixed function calls.
// "MTX_USE_C " -> When this flag is specified, it uses C_* (C code) functions
//                 for non-prefixed function calls.
//
// If both are specified, it will be treated as MTX_USE_PS.
// If nothing is specified, NDEBUG build refers PS* functions and
// DEBUG build uses C_* functions.

// For non-Gekko HW (e.g. emulator)
#ifndef GEKKO
#define MTX_USE_C
#undef  MTX_USE_PS
#endif

#if ( !defined(MTX_USE_PS) && !defined(MTX_USE_C) )
#ifndef _DEBUG
#define MTX_USE_PS
#endif
#endif
*/

	/*---------------------------------------------------------------------------*
    4x4 GENERAL MATRIX SECTION
 *---------------------------------------------------------------------------*/
	// C version
	void C_MTX44Identity(Mtx44 m);
	void C_MTX44Copy(const Mtx44 src, Mtx44 dst);
	void C_MTX44Concat(const Mtx44 a, const Mtx44 b, Mtx44 ab);
	void C_MTX44Transpose(const Mtx44 src, Mtx44 xPose);
	u32 C_MTX44Inverse(const Mtx44 src, Mtx44 inv);

// PS assembler version
#ifdef GEKKO
	void PSMTX44Identity(Mtx44 m);
	void PSMTX44Copy(const Mtx44 src, Mtx44 dst);
	void PSMTX44Concat(const Mtx44 a, const Mtx44 b, Mtx44 ab);
	void PSMTX44Transpose(const Mtx44 src, Mtx44 xPose);
#endif

// Bindings
#ifdef MTX_USE_PS
#define MTX44Identity PSMTX44Identity
#define MTX44Copy PSMTX44Copy
#define MTX44Concat PSMTX44Concat
#define MTX44Transpose PSMTX44Transpose
#else  // MTX_USE_C
#define MTX44Identity C_MTX44Identity
#define MTX44Copy C_MTX44Copy
#define MTX44Concat C_MTX44Concat
#define MTX44Transpose C_MTX44Transpose
#endif

#define MTX44Inverse C_MTX44Inverse

	/*---------------------------------------------------------------------------*
    MODEL MATRIX SECTION
 *---------------------------------------------------------------------------*/
	// C version
	void C_MTX44Trans(Mtx44 m, f32 xT, f32 yT, f32 zT);
	void C_MTX44TransApply(const Mtx44 src, Mtx44 dst, f32 xT, f32 yT, f32 zT);
	void C_MTX44Scale(Mtx44 m, f32 xS, f32 yS, f32 zS);
	void C_MTX44ScaleApply(const Mtx44 src, Mtx44 dst, f32 xS, f32 yS, f32 zS);

	void C_MTX44RotRad(Mtx44 m, char axis, f32 rad);
	void C_MTX44RotTrig(Mtx44 m, char axis, f32 sinA, f32 cosA);
	void C_MTX44RotAxisRad(Mtx44 m, const Vec *axis, f32 rad);

// PS assembler version
#ifdef GEKKO
	void PSMTX44Trans(Mtx44 m, f32 xT, f32 yT, f32 zT);
	void PSMTX44TransApply(const Mtx44 src, Mtx44 dst, f32 xT, f32 yT, f32 zT);
	void PSMTX44Scale(Mtx44 m, f32 xS, f32 yS, f32 zS);
	void PSMTX44ScaleApply(const Mtx44 src, Mtx44 dst, f32 xS, f32 yS, f32 zS);

	void PSMTX44RotRad(Mtx44 m, char axis, f32 rad);
	void PSMTX44RotTrig(Mtx44 m, char axis, f32 sinA, f32 cosA);
	void PSMTX44RotAxisRad(Mtx44 m, const Vec *axis, f32 rad);
#endif

// Bindings
#ifdef MTX_USE_PS
#define MTX44Trans PSMTX44Trans
#define MTX44TransApply PSMTX44TransApply
#define MTX44Scale PSMTX44Scale
#define MTX44ScaleApply PSMTX44ScaleApply

#define MTX44RotRad PSMTX44RotRad
#define MTX44RotTrig PSMTX44RotTrig
#define MTX44RotAxisRad PSMTX44RotAxisRad

#else  // MTX_USE_C
#define MTX44Trans C_MTX44Trans
#define MTX44TransApply C_MTX44TransApply
#define MTX44Scale C_MTX44Scale
#define MTX44ScaleApply C_MTX44ScaleApply

#define MTX44RotRad C_MTX44RotRad
#define MTX44RotTrig C_MTX44RotTrig
#define MTX44RotAxisRad C_MTX44RotAxisRad
#endif

	/*---------------------------------------------------------------------------*
    MATRIX-VECTOR SECTION
 *---------------------------------------------------------------------------*/
	// C version
	void C_MTX44MultVec(const Mtx44 m, const Vec *src, Vec *dst);
	void C_MTX44MultVecArray(const Mtx44 m, const Vec *srcBase, Vec *dstBase, u32 count);
	void C_MTX44MultVecSR(const Mtx44 m, const Vec *src, Vec *dst);
	void C_MTX44MultVecArraySR(const Mtx44 m, const Vec *srcBase, Vec *dstBase, u32 count);

// PS assembler version
#ifdef GEKKO
	void PSMTX44MultVec(const Mtx44 m, const Vec *src, Vec *dst);
	void PSMTX44MultVecArray(const Mtx44 m, const Vec *srcBase, Vec *dstBase, u32 count);
	void PSMTX44MultVecSR(const Mtx44 m, const Vec *src, Vec *dst);
	void PSMTX44MultVecArraySR(const Mtx44 m, const Vec *srcBase, Vec *dstBase, u32 count);
#endif

// Bindings
#ifdef MTX_USE_PS
#define MTX44MultVec PSMTX44MultVec
#define MTX44MultVecArray PSMTX44MultVecArray
#define MTX44MultVecSR PSMTX44MultVecSR
#define MTX44MultVecArraySR PSMTX44MultVecArraySR
#else  // MTX_USE_C
#define MTX44MultVec C_MTX44MultVec
#define MTX44MultVecArray C_MTX44MultVecArray
#define MTX44MultVecSR C_MTX44MultVecSR
#define MTX44MultVecArraySR C_MTX44MultVecArraySR
#endif

}