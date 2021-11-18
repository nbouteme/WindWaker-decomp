#pragma once
#include <ctypes.h>


//[Data] Expected size is 0x000010
extern undefined1 J3DAnmColorKey;


namespace J3DAnmColor {
//[Data] Expected size is 0x000010
extern undefined1 __vt;

}
//[Data] Expected size is 0x000010
extern undefined1 J3DAnmColorFull;

//[Data] Expected size is 0x000010
extern undefined1 J3DAnmVtxColorKey;

//[Data] Expected size is 0x000010
extern undefined1 J3DAnmVtxColor;

//[Data] Expected size is 0x000010
extern undefined1 J3DAnmVtxColorFull;

//[Data] Expected size is 0x000010
extern undefined1 J3DAnmClusterKey;

//[Data] Expected size is 0x000010
extern undefined1 J3DAnmCluster;

//[Data] Expected size is 0x000010
extern undefined1 J3DAnmClusterFull;

//[Data] Expected size is 0x000014
extern pointer J3DAnmTransformKey;

//[Data] Expected size is 0x000010
extern pointer J3DAnmTransformFull;


namespace J3DGraphAnimator {
double J3DHermiteInterpolationS(double param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7);
double J3DGetKeyFrameInterpolationS(double param_1,ushort *param_2,short *param_3);
}

namespace J3DGraphAnimator {
double J3DGetKeyFrameInterpolation(double param_1,J3DAnmKeyTableBase *animationTrack,short *trackData);
double J3DGetKeyFrameInterpolation(double param_1,ushort *param_2,float *param_3);
}
