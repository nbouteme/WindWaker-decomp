#version 450
#extension GL_ARB_shading_language_include : require

#include "/gxState.glsl"

layout(location = 0) out vec4 FragColor;

void main() { FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f); }
