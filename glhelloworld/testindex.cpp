#include <stdio.h>
#include <string.h>

#include <math.h>
#include <gl/glew.h>
#include <gl/glut.h>
#include "math_3d.h"
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <string>

#include "include/ogldev_math_3d.h"
#include "include/ogldev_util.h"

static GLuint VBO;
static GLuint IBO;
static GLuint ShaderProgram;
static GLuint gScaleLocation; // 位置中间变量
static GLuint gColorLocation;
static GLuint gTransMat;

static float transMat[4][4] = { 1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1 };

static const char* pVSFileName = "shader.vs";
static const char* pFSFileName = "shader.fs";

static void RenderSceneCB()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glUseProgram(ShaderProgram);
	// 维护一个不断慢慢增大的静态浮点数
	static float Scale = 0.0f;
	Scale += 0.01f;
	// 将值传递给shader
	//glUniform1f(gScaleLocation, sinf(Scale));
	transMat[0][0] = sinf(Scale);
	transMat[1][1] = sinf(Scale);
	transMat[2][2] = sinf(Scale);
	//transMat[1][1] = cosf(Scale);
	//glUniform3f(gColorLocation, rand() % 100 / 100.0, rand() % 100 / 100.0, rand() % 100 / 100.0);
	glUniformMatrix4fv(gTransMat, 1, GL_TRUE, &transMat[0][0]);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);
	glUseProgram(NULL);
	glDrawElements(GL_LINES, 2, GL_UNSIGNED_INT, (void *)12);

	//glDrawArrays(GL_TRIANGLES, 0, 3);

	glDisableVertexAttribArray(0);

	glutSwapBuffers();

	//printf("render screen\n");
}

static void InitializeGlutCallbacks()
{
	glutDisplayFunc(RenderSceneCB);
	// 将渲染回调注册为全局闲置回调
	glutIdleFunc(RenderSceneCB);
}

static void CreateVertexBuffer()
{
	Vector3f Vertices[6];
	Vertices[0] = Vector3f(-1.0f, -1.0f, 0.0f);
	Vertices[1] = Vector3f(1.0f, 0.0f, 1.0f);
	Vertices[2] = Vector3f(1.0f, -1.0f, 0.0f);
	Vertices[3] = Vector3f(0.0f, 1.0f, 0.0f);
	Vertices[4] = Vector3f(1.0f, -1.0f, 1.0f);
	Vertices[5] = Vector3f(-1.0f, 1.0f, 1.0f);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
}

static void CreateIndexBuffer()
{
	unsigned int Indicis[] = {
		0, 3, 1,
		1, 3, 2,
		2, 3, 0,
		0, 1, 2,
		4, 5
		};

	glGenBuffers(1, &IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Indicis), Indicis, GL_STATIC_DRAW);
}

static void AddShader(GLuint ShaderProgram, const char* pShaderText, GLenum ShaderType)
{
	GLuint ShaderObj = glCreateShader(ShaderType);

	if (ShaderObj == 0) {
		fprintf(stdout, "Error creating shader type %d\n", ShaderType);
		exit(1);
	}

	const GLchar* p[1];
	p[0] = pShaderText;
	GLint Lengths[1];
	Lengths[0] = strlen(pShaderText);
	glShaderSource(ShaderObj, 1, p, Lengths);
	glCompileShader(ShaderObj);
	GLint success;
	glGetShaderiv(ShaderObj, GL_COMPILE_STATUS, &success);
	if (!success) {
		GLchar InfoLog[1024];
		glGetShaderInfoLog(ShaderObj, 1024, NULL, InfoLog);
		fprintf(stderr, "Error compiling shader type %d: '%s'\n", ShaderType, InfoLog);
		exit(1);
	}

	glAttachShader(ShaderProgram, ShaderObj);
}

static void CompileShaders()
{
	ShaderProgram = glCreateProgram();

	if (ShaderProgram == 0) {
		fprintf(stdout, "Error creating shader program\n");
		exit(1);
	}

	string vs, fs;

	if (!ReadFile(pVSFileName, vs)) {
		exit(1);
	};

	if (!ReadFile(pFSFileName, fs)) {
		exit(1);
	};

	AddShader(ShaderProgram, vs.c_str(), GL_VERTEX_SHADER);
	AddShader(ShaderProgram, fs.c_str(), GL_FRAGMENT_SHADER);

	GLint Success = 0;
	GLchar ErrorLog[1024] = { 0 };

	glLinkProgram(ShaderProgram);
	glGetProgramiv(ShaderProgram, GL_LINK_STATUS, &Success);
	if (Success == 0) {
		glGetProgramInfoLog(ShaderProgram, sizeof(ErrorLog), NULL, ErrorLog);
		fprintf(stdout, "Error linking shader program: '%s'\n", ErrorLog);
		exit(1);
	}

	glValidateProgram(ShaderProgram);
	glGetProgramiv(ShaderProgram, GL_VALIDATE_STATUS, &Success);
	if (!Success) {
		glGetProgramInfoLog(ShaderProgram, sizeof(ErrorLog), NULL, ErrorLog);
		fprintf(stdout, "Invalid shader program: '%s'\n", ErrorLog);
		exit(1);
	}

	glUseProgram(ShaderProgram);

	// 查询获取一致变量的位置
	//gScaleLocation = glGetUniformLocation(ShaderProgram, "gScale");
	//gColorLocation = glGetUniformLocation(ShaderProgram, "gColor");
	gTransMat = glGetUniformLocation(ShaderProgram, "gTransMat");
	// 检查错误
	//assert(gScaleLocation != 0xFFFFFFFF);
	assert(gColorLocation != 0xFFFFFFFF);
	assert(gTransMat != 0xffffffff);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(1024, 768);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Tutorial 05");

	InitializeGlutCallbacks();

	// Must be done after glut is initialized!
	GLenum res = glewInit();
	if (res != GLEW_OK) {
		fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
		return 1;
	}

	printf("GL version: %s\n", glGetString(GL_VERSION));

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	CreateVertexBuffer();
	CreateIndexBuffer();

	CompileShaders();

	glutMainLoop();

	return 0;
}