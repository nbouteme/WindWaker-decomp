#version 450
#extension GL_ARB_shading_language_include : require

#include "/gxState.glsl"

uint tid = gl_VertexID;

struct vertex_attr {
  vec4 pos;
  vec4 n;
  vec4 bi;
  vec4 tang;
  vec4 col[2];
  // vec4 uv01, uv23, uv45, uv67;
  vec2 uv0;
  vec2 uv1;
  vec2 uv2;
  vec2 uv3;
  vec2 uv4;
  vec2 uv5;
  vec2 uv6;
  vec2 uv7;
  ivec4 mtxidx; // used for position transform
};

layout(binding = 0, std430) buffer _vertices { vertex_attr v[]; }
vb;

layout(location = 0) out PerVertexData {
  vec4 col[2];
  vec3 generated_uvs[8];
}
v_out;

layout(std140) uniform gxStateBlock { gxState v; };

const vec3 vertices[3] = {vec3(0, 0, 0), vec3(0, 100, 0), vec3(100, 100, 0)};
const vec3 colors[3] = {vec3(1.0, 0.0, 0.0), vec3(0.0, 1.0, 0.0),
                        vec3(0.0, 0.0, 1.0)};

mat3x4 load_mtx34(uint i) {
  return (mat3x4(v.matrix_mem[i], v.matrix_mem[i + 1], v.matrix_mem[i + 2]));
}

void main() {
  mat3x4 curmtx = load_mtx34(v.current_mtx);
  vec3 p = vertices[tid];
  vec3 r = transpose(curmtx) * vec4(p, 1.0);
  mat4 proj = v.persp_proj;
  if (!v.isprojpersp)
    proj = v.ortho_proj;
  vec4 tr = transpose(proj) * vec4(r, 1.0);

  gl_Position = tr;
  v_out.col[0] = v.dbg;
}
