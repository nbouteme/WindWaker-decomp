
struct TevOp {
  int op;
  int bias;
  int scale;
  int clamp;
  int out_reg;
  int a, b, c; // pad
};

struct IndSettings {
  int ind_stage;
  int format;
  int bias_sel;
  int matrix_sel;
  int wrap_s;
  int wrap_t;
  int add_prev;
  int utc_lod;
  int alpha_sel;
  int a, b, c; // round to 16*
};

struct TevState {
  int ksel;
  int kasel;
  int c;

  int ras_swizzle;
  int tex_swizzle;

  ivec4 a_inputs;
  // int pa, pb, pc; // 48
  ivec4 c_inputs;
  //
  TevOp aop;
  TevOp cop;
  //
  int coord;
  int tmap;
  int chan;
  //
  IndSettings indirection;
  int d; // 192
};

struct TexGenState {
  int func;
  int src;
  uint mtxid;
  uint ptmtx;
  int normalize;
  int line_bias;
  int point_bias;
};

struct ChanState {
  int enable;

  int amb_src;
  int mat_src;
  uint light_mask;
  int diff_fn;
  int attn_fn;

  int amb_color;
  int mat_color;
};

struct IndTex {
  float ss;
  float st;
  int coord;
  int map;
};

struct AlphaEquationState {
  int comp0;
  uint ref0;
  int op;
  int comp1;
  uint ref1;
};

struct gxState {
  ivec4 swizzles[4]; // 0
  // use unpackDouble2x32 to convert that back into 16 bits integers
  dvec4 a; // 64
  // dvec2 tregs;
  ivec4 kregs; // 96

  TevState tevs[16];   // 112-320-528-736-948-1152-1360-1568
  TexGenState tgs[8]; // 1776
  ChanState chans[2];
  IndTex indtex[4];
  mat2x3 indmtx[3];

  int inds; // was s8[3]
  int texgens;
  int tevstages;
  int colchans;

  int indn;
  int dither;
  float point_sprite_uv_bias;
  float line_sprite_uv_bias;

  int current_mtx;

  AlphaEquationState alphacomp;

  int cupdate;
  int aupdate;
  vec4 dbg; // 2256

  vec4 matrix_mem[128];
  vec4 norm_mat[32]; // 4th component ignored

  mat4 persp_proj;
  mat4 ortho_proj;
  bool isprojpersp;
};