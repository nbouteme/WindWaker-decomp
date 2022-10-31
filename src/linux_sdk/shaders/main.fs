#version 450
#extension GL_ARB_shading_language_include : require

#include "/gxState.glsl"

layout(location = 0) out vec4 FragColor;

struct vertex_attr {
  vec3 pos;
  vec3 n;
  vec3 bi;
  vec3 tang;
  vec4 col[2];
  vec2 uv[8];
  ivec3 mtxidx; // used for position transform
};

in PerVertexData {
  vec4 col[2];
  vec3 generated_uvs[8];
}
frag_in;

void main() { FragColor = vec4(frag_in.col[0].rgb, 1.0f); }
