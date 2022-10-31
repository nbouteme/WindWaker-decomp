#include "ubershader.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <doltypes.h>

#include <cstdio>
#include <cstdlib>
#include <cstring>

#define RESDECL(x)             \
	extern char b_##x##_end[]; \
	extern char b_##x##_start[]

#define LOADRES(x, r)          \
	const char *x = GETRES(r); \
	int x##Len = RESSIZE(r)

#define GETRES(x) \
	b_##x##_start

// linker sets the size of the ressource as the address of its _size symbol
#define RESSIZE(x) (b_##x##_end - b_##x##_start)

RESDECL(shaders_gxstate_glsl);
RESDECL(shaders_main_ms);
RESDECL(shaders_main_fs);
RESDECL(shaders_test_vs);

#if 1
int buildUbershader() {
	u32 meshShader = glCreateShader(GL_MESH_SHADER_NV);

	LOADRES(gxStateDefinition, shaders_gxstate_glsl);
	LOADRES(meshshader, shaders_main_ms);
	LOADRES(fragshader, shaders_main_fs);

	const char *gxState = "/gxState.glsl";
	glNamedStringARB(GL_SHADER_INCLUDE_ARB, strlen(gxState), gxState, gxStateDefinitionLen, gxStateDefinition);

	glShaderSource(meshShader, 1, &meshshader, &meshshaderLen);
	glCompileShader(meshShader);

	u32 fShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(fShader, 1, &fragshader, &fragshaderLen);
	glCompileShader(fShader);

	uint prog = glCreateProgram();
	glAttachShader(prog, meshShader);
	glAttachShader(prog, fShader);
	glLinkProgram(prog);

	int success;
	glGetProgramiv(prog, GL_LINK_STATUS, &success);
	if (!success) {
		int len;
		glGetProgramiv(prog, GL_INFO_LOG_LENGTH, &len);
		char *infoLog = (char *)malloc(len + 1);
		glGetProgramInfoLog(prog, len, NULL, infoLog);
		puts(infoLog);
		abort();
	}
	glUseProgram(prog);
	glDeleteShader(meshShader);
	glDeleteShader(fShader);
	return prog;
}

#else
int buildUbershader() {
	u32 meshShader = glCreateShader(GL_VERTEX_SHADER);

	LOADRES(gxStateDefinition, shaders_gxstate_glsl);
	LOADRES(meshshader, shaders_test_vs);
	LOADRES(fragshader, shaders_main_fs);

	const char *gxState = "/gxState.glsl";
	glNamedStringARB(GL_SHADER_INCLUDE_ARB, strlen(gxState), gxState, gxStateDefinitionLen, gxStateDefinition);

	glShaderSource(meshShader, 1, &meshshader, &meshshaderLen);
	glCompileShader(meshShader);

	u32 fShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(fShader, 1, &fragshader, &fragshaderLen);
	glCompileShader(fShader);

	uint prog = glCreateProgram();
	glAttachShader(prog, meshShader);
	glAttachShader(prog, fShader);
	glLinkProgram(prog);

	int success;
	glGetProgramiv(prog, GL_LINK_STATUS, &success);
	if (!success) {
		int len;
		glGetProgramiv(prog, GL_INFO_LOG_LENGTH, &len);
		char *infoLog = (char *)malloc(len + 1);
		glGetProgramInfoLog(prog, len, NULL, infoLog);
		puts(infoLog);
		abort();
	}
	glUseProgram(prog);
	glDeleteShader(meshShader);
	glDeleteShader(fShader);
	return prog;
}
#endif