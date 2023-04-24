#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <sys/fcntl.h>
#include <unistd.h>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>

void GLAPIENTRY
MessageCallback(GLenum source,
				GLenum type,
				GLuint id,
				GLenum severity,
				GLsizei length,
				const GLchar *message,
				const void *userParam) {
	(void)id;
	(void)userParam;
	(void)length;
	(void)source;
	fprintf(stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
			(type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : ""),
			type, severity, message);
	if (type == GL_DEBUG_TYPE_ERROR)
		abort();
}

int buildUbershader();

int main(int ac, char **av) {
	if (!glfwInit())
		return;

	auto window = glfwCreateWindow(640, 528, "WW", NULL, NULL);
	if (!window) {
		glfwTerminate();
		return;
	}

	glfwMakeContextCurrent(window);
	glfwSetWindowMonitor(window, nullptr, 10, 10, 640, 528, 30);
	glfwSwapInterval(32);

	glewExperimental = GL_TRUE;
	auto e = glewInit();
	glGetError();
	glEnable(GL_DEBUG_OUTPUT);
	glDebugMessageCallback(MessageCallback, 0);

	int us = buildUbershader();
	int n;
	glGetProgramInterfaceiv(us, GL_SHADER_STORAGE_BLOCK, GL_ACTIVE_RESOURCES, &n);
	GLuint blockIndex = glGetUniformBlockIndex(us, "gxStateBlock");
	if (blockIndex == ~0u) {
		puts("Error getting the uniform block index");
		abort();
	}
	int ufocount;
	glGetActiveUniformBlockiv(us, blockIndex, GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS, &ufocount);

	auto ufos = std::vector<uint>(ufocount);

	auto namelengths = std::vector<int>(ufocount);
	auto offsets = std::vector<int>(ufocount);
	auto strides = std::vector<int>(ufocount);

	glGetActiveUniformBlockiv(us, blockIndex, GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES, (int *)ufos.data());

	glGetActiveUniformsiv(us, ufocount, ufos.data(), GL_UNIFORM_NAME_LENGTH, namelengths.data());
	glGetActiveUniformsiv(us, ufocount, ufos.data(), GL_UNIFORM_OFFSET, offsets.data());
	glGetActiveUniformsiv(us, ufocount, ufos.data(), GL_UNIFORM_ARRAY_STRIDE, strides.data());

	auto names = std::vector<std::string>();
	for (int i = 0; i < ufocount; ++i) {
		char *name = (char *)malloc(namelengths[i] + 1);
		glGetActiveUniformName(us, ufos[i], namelengths[i] + 1, nullptr, name);
		names.push_back(std::string(name).substr(2));  // substr to remove the base fieldname (v.)
		printf("{uniform: '%s', strides: %d, offset: %d},\n", name, strides[i], offsets[i]);
		free(name);
	}

	int fd = open(av[2], O_RDWR | O_CREAT, 0644);
#define WR(x) write(fd, x, strlen(x))
	WR("#pragma once\n");
	close(fd);
}