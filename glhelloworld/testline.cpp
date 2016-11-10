#include <gl/glew.h>
#include <gl/glut.h>
#include "math_3d.h"


static int gltriangle()
{
	GLenum res = glewInit();
	if (res != GLEW_OK)
	{
		fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
		return 1;
	}
	Vector3f Vertices[3];
	Vertices[0] = Vector3f(-1.0f, -1.0f, 0.0f);
	Vertices[1] = Vector3f(1.0f, -1.0f, 0.0f);
	Vertices[2] = Vector3f(0.0f, 1.0f, 0.0f);
	GLuint VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glDisableVertexAttribArray(0);
	return 0;
}


static void triangle()
{
	glBegin(GL_TRIANGLES);
	glVertex3d(0.0, 0.0, 1.0);
	glVertex3d(0.0, 1.0, 0.0);
	glVertex3d(1.0, 0.0, 0.0);
	glEnd();
}

static void draw()
{
	glClear(GL_COLOR_BUFFER_BIT); //清除颜色
	glColor3ub(255, 10, 10);
	//gltriangle();
	triangle();
	glFlush();
}



//int main(int argc, char* argv[])
//{
//	glutInit(&argc, (char**)argv); //初始化glut,必须调用，复制黏贴这句话即可
//	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); //设置显示方式，RGB、单缓冲。当然还有GLUT_INDEX索引颜色 GLUT_DOUBLE双缓冲(Qt中看到过双缓冲)
//	glutInitWindowPosition(100, 100); //位置
//	glutInitWindowSize(400, 400);//窗口大小
//	glutCreateWindow("第一个OpenGL程序"); //创建窗口，设置标题
//	glutDisplayFunc(&draw);
//	glutMainLoop(); //消息循环
//	return 0;
//}