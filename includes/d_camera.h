#pragma once
#include <ctypes.h>



namespace d_camera {
//Expected size is 0x00000c
extern undefined4 ofan$9214;

//Expected size is 0x00000c
extern undefined4 opixy$9221;

//Expected size is 0x000018
extern undefined4 p$13482;

//Expected size is 0x000018
extern undefined4 p$13498;

//Expected size is 0x000030
extern undefined p$14128;

//Expected size is 0x000030
extern undefined p$14143;

//Expected size is 0x000004
extern undefined4 prev_hit_type$8381;

//Expected size is 0x000001
extern undefined1 init$8382;

//Expected size is 0x000004
extern undefined4 prev_plat1$8384;

//Expected size is 0x000001
extern undefined1 init$8385;

//Expected size is 0x000004
extern undefined4 prev_plat2$8387;

//Expected size is 0x000001
extern undefined1 init$8388;

//Expected size is 0x000001
extern undefined1 init$9216;

//Expected size is 0x000004
extern float dfan$9218;

//Expected size is 0x000001
extern undefined1 init$9219;

//Expected size is 0x000001
extern undefined1 init$9223;

//Expected size is 0x000004
extern float dpixy$9225;

//Expected size is 0x000001
extern undefined1 init$9226;

//Expected size is 0x000004
extern float SA_FLY$9681;

//Expected size is 0x000001
extern undefined1 init$9682;

//Expected size is 0x000004
extern float SA_FLY$12181;

//Expected size is 0x000001
extern undefined1 init$12182;

//Expected size is 0x000001
extern undefined1 init$13484;

//Expected size is 0x000001
extern undefined1 init$13500;

//Expected size is 0x000001
extern undefined1 init$14130;

//Expected size is 0x000001
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
