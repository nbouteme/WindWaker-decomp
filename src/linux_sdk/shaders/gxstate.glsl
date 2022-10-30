
struct TevOp {
  int op;
  int bias;
  int scale;
  bool clamp;
  int out_reg;
};

struct IndSettings {
  int ind_stage;
  int format;
  int bias_sel;
  int matrix_sel;
  int wrap_s;
  int wrap_t;
  bool add_prev;
  bool utc_lod;
  int alpha_sel;
};

struct TevState {
  int ksel;
  int kasel;
  int c;

  int ras_swizzle;
  int tex_swizzle;

  int a_inputs[4];
  int c_inputs[4];

  TevOp aop;
  TevOp cop;

  int coord;
  int tmap;
  int chan;

  IndSettings indirection;
};

struct TexGenState {
  int func;
  int src;
  uint mtxid;
  uint ptmtx;
  bool normalize;
  bool line_bias;
  bool point_bias;
};

struct ChanState {
  bool enable;

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
  int swizzles[4][4];
  dvec3 tregs; // use unpackDouble2x32 to convert that back into 16 bits integers
  ivec4 kregs;
  TevState tevs[8];
  TexGenState tgs[8];
  ChanState chans[2];
  IndTex indtex[4];
  mat2x3 indmtx[3];
  int inds; // was s8

  int texgens;
  int tevstages;
  int colchans;
  int indn;
  int dither;

  float point_sprite_uv_bias;
  float line_sprite_uv_bias;
  int current_mtx;

  AlphaEquationState alphacomp;

  bool cupdate;
  bool aupdate;

  vec4 matrix_mem[128];
  vec4 norm_mat[32]; // 4th component ignored

  mat4 persp_proj;
  mat4 ortho_proj;
  bool isprojpersp;
};