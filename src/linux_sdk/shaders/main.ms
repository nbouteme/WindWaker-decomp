#version 450
#extension GL_NV_mesh_shader : require
#extension GL_ARB_shading_language_include : require

#include "/gxState.glsl"

layout(local_size_x = 3) in;
layout(triangles, max_vertices = 3, max_primitives = 1) out;
layout(triangles) out;

uint tid = gl_LocalInvocationID.x;

struct vertex_attr {
  vec3 pos;
  vec3 n;
  vec3 bi;
  vec3 tang;
  vec4 col[2];
  vec2 uv[8];
  ivec3 mtxidx; // used for position transform
};

layout(std430, binding = 1) buffer _vertices { vertex_attr v[]; }
vb;

layout(location = 0) out PerVertexData {
  vec4 col[2];
  vec3 generated_uvs[8];
}
v_out[];

layout(std140) uniform gxStateBlock { gxState v; };

vec4 compute_mat_color(int idx) {
  if (v.chans[idx].mat_src == 1)
    return vb.v[tid].col[idx];
  return vec4(((v.chans[idx].mat_color >> 24) & 0xFF) / 255.,
              ((v.chans[idx].mat_color >> 16) & 0xFF) / 255.,
              ((v.chans[idx].mat_color >> 8) & 0xFF) / 255.,
              ((v.chans[idx].mat_color >> 0) & 0xFF) / 255.);
}

vec4 compute_amb_color(int idx) {
  if (v.chans[idx].amb_src == 1)
    return vb.v[tid].col[idx];
  return vec4(((v.chans[idx].amb_color >> 24) & 0xFF) / 255.,
              ((v.chans[idx].amb_color >> 16) & 0xFF) / 255.,
              ((v.chans[idx].amb_color >> 8) & 0xFF) / 255.,
              ((v.chans[idx].amb_color >> 0) & 0xFF) / 255.);
}

float light_function() {
  // need to implement lighting
  return 1.;
}

vec4 compute_raster_color(int idx) {
  return compute_mat_color(idx) * light_function();
}

vec3 norm;
vec3 bnorm;
vec3 tangent;

vec4 get_input_tex_gen(int idx) {
  int p = v.tgs[idx].src;
  switch (p) {
  case 0: // GX_TG_POS
    return vec4(vb.v[tid].pos, 1.);
  case 1: // GX_TG_NRM
    return vec4(vb.v[tid].n, 1.);
  case 2: // GX_TG_BINRM
    return vec4(vb.v[tid].bi, 1.);
  case 3: // GX_TG_TANGENT
    return vec4(vb.v[tid].tang, 1.);
  default:
    break;
  }
  if (p <= 11) { // GX_TG_TEX7
    return vec4(vb.v[tid].uv[p - 11], 1., 1.);
  }

  // Dont handle bump input parameters

  switch (p) {
  case 19: // GX_TG_COLOR0
  case 20: // GX_TG_COLOR1
    return vec4(vb.v[tid].col[p - 19].r, vb.v[tid].col[p - 19].g, 1., 1.);
  }
  return vec4(0.);
}

mat3x4 load_mtx34(int i) {
  return mat3x4(v.matrix_mem[i], v.matrix_mem[i + 1], v.matrix_mem[i + 2]);
}

mat2x4 load_mtx24(int i) {
  return mat2x4(v.matrix_mem[i], v.matrix_mem[i + 1]);
}

mat3x3 load_nmtx33(int i) {
  return mat3x3(v.norm_mat[i], v.norm_mat[i + 1], v.norm_mat[i + 2]);
}

mat3x4 load_mtx34(uint i) {
  return mat3x4(v.matrix_mem[i], v.matrix_mem[i + 1], v.matrix_mem[i + 2]);
}

mat2x4 load_mtx24(uint i) {
  return mat2x4(v.matrix_mem[i], v.matrix_mem[i + 1]);
}

mat3x3 load_nmtx33(uint i) {
  return mat3x3(v.norm_mat[i], v.norm_mat[i + 1], v.norm_mat[i + 2]);
}

void main() {
  vertex_attr cv = vb.v[tid];
  mat3x4 curmtx = load_mtx34(v.current_mtx);
  mat3x3 curnmtx = load_nmtx33(v.current_mtx & 0x1f);

  vec4 trpos = vec4(vec4(cv.pos, 1.) * curmtx, 1.);
  norm = normalize(mat3(curnmtx) * cv.n);
  mat4 proj = v.persp_proj;
  if (!v.isprojpersp)
    proj = v.ortho_proj;
  trpos = proj * trpos;

  for (int i = 0; i < 2; ++i)
    v_out[tid].col[i] = compute_raster_color(i);

  int csel = 0; // incremented every time a texture generator refers to srtg

  for (int i = 0; i < 8; ++i) {
    vec4 src_param = get_input_tex_gen(i);
    mat2x4 twoxf;
    mat4x4 threexf;

    vec2 st;
    vec3 stq;
    // Dont support BUMP mapping
    switch (v.tgs[i].func) {
    case 0: // GX_TG_MTX3x4
      stq = src_param * load_mtx34(v.tgs[i].mtxid);
      break;
    case 1: // GX_TG_MTX2x4
      st = src_param * load_mtx24(v.tgs[i].mtxid);
      stq = vec3(st, 1.);
      break;
    case 10: // GX_TG_SRTG
      stq = vec3(v_out[tid].col[csel++].rg, 1.);
      break;
    }
    v_out[tid].generated_uvs[i] = stq;
  }

  gl_MeshVerticesNV[tid].gl_Position = trpos;
  gl_PrimitiveIndicesNV[tid] = tid;

  gl_PrimitiveCountNV = 1;
}
