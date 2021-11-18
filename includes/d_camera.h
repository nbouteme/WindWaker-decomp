#pragma once
#include <ctypes.h>

#include <f_pc_profile__Profile_Actor.h>

//[Data] Expected size is 0x0000f0
extern struct PTMF dCamera_c[20];


namespace d_camera {
//[Data] Expected size is 0x000070
extern undefined * ActionNames$17107;

//[Data] Expected size is 0x00000c
extern pointer l_method$18182;

//[Data] Expected size is 0x000014
extern undefined * method;

//[Data] Expected size is 0x000044
extern struct f_pc_profile__Profile_Actor g_profile_CAMERA;

//[Data] Expected size is 0x000044
extern undefined g_profile_CAMERA2;

}
//[Data] Expected size is 0x00003c
extern undefined1 dBgS_CamSphChk;


namespace dBgS_SphChk {
//[Data] Expected size is 0x00003c
extern pointer __vt;

}
//[Data] Expected size is 0x000030
extern undefined1 dBgS_CamGndChk_Wtr;

//[Data] Expected size is 0x000030
extern undefined1 dBgS_CamLinChk_NorWtr;

//[Data] Expected size is 0x000030
extern undefined1 dBgS_CamLinChk;

//[Data] Expected size is 0x000030
extern undefined1 dBgS_CamGndChk;

//[Data] Expected size is 0x00000c
extern undefined1 d2DBSplinePath;


namespace d_camera {
//[BSS] Expected size is 0x00000c
extern undefined4 ofan$9214;
//[BSS] Expected size is 0x00000c
extern undefined4 opixy$9221;
//[BSS] Expected size is 0x000018
extern undefined4 p$13482;
//[BSS] Expected size is 0x000018
extern undefined4 p$13498;
//[BSS] Expected size is 0x000030
extern undefined p$14128;
//[BSS] Expected size is 0x000030
extern undefined p$14143;
//[BSS] Expected size is 0x000004
extern undefined4 prev_hit_type$8381;
//[BSS] Expected size is 0x000001
extern undefined1 init$8382;
//[BSS] Expected size is 0x000004
extern undefined4 prev_plat1$8384;
//[BSS] Expected size is 0x000001
extern undefined1 init$8385;
//[BSS] Expected size is 0x000004
extern undefined4 prev_plat2$8387;
//[BSS] Expected size is 0x000001
extern undefined1 init$8388;
//[BSS] Expected size is 0x000001
extern undefined1 init$9216;
//[BSS] Expected size is 0x000004
extern float dfan$9218;
//[BSS] Expected size is 0x000001
extern undefined1 init$9219;
//[BSS] Expected size is 0x000001
extern undefined1 init$9223;
//[BSS] Expected size is 0x000004
extern float dpixy$9225;
//[BSS] Expected size is 0x000001
extern undefined1 init$9226;
//[BSS] Expected size is 0x000004
extern float SA_FLY$9681;
//[BSS] Expected size is 0x000001
extern undefined1 init$9682;
//[BSS] Expected size is 0x000004
extern float SA_FLY$12181;
//[BSS] Expected size is 0x000001
extern undefined1 init$12182;
//[BSS] Expected size is 0x000001
extern undefined1 init$13484;
//[BSS] Expected size is 0x000001
extern undefined1 init$13500;
//[BSS] Expected size is 0x000001
extern undefined1 init$14130;
//[BSS] Expected size is 0x000001
extern undefined1 init$14145;
}

namespace d_camera {
undefined4 limited_range_addition(double param_1,double param_2,double param_3,float *param_4);
}

namespace d_camera {
void sph_chk_callback(void);
}

namespace dCamera_c {
void forwardCheckAngle(cSAngle *param_1,dCamera_c *param_2);
}

namespace d_camera {
uint dCam_isManual(int param_1);
void dCam_getAngleY(camera_class *param_1);
int dCam_getAngleX(camera_class *param_1);
cSAngle dCam_getControledAngleY(camera_class *param_1);
camera_class * dCam_getCamera(void);
dCamera_c * dCam_getBody(void);
void preparation(camera_class *param_1);
void view_setup(camera_class *pCam);
void store(camera_class *pCamera);
undefined4 camera_execute(camera_class *pCam);
undefined4 camera_draw(camera_class *this);
undefined4 init_phase1(camera_class *param_1);
undefined4 init_phase2(camera_class *pCamera);
void camera_create(void *param_1);
undefined4 camera_delete(int param_1);
undefined4 is_camera_delete(void);
}

namespace dCamera_c {
}

namespace dCamera_c {
}

namespace dCamera_c {
cSAngle * Bank(cSAngle *param_1,dCamera_c *param_2);
}

namespace dCamera_c {
cXyz * Center(cXyz *__return_storage_ptr__,dCamera_c *param_1);
}

namespace d_camera {
int dComIfGp_evmng_cameraPlay(void);
void __sinit_d_camera_cpp(void);
}
