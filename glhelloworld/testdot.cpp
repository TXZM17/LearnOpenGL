#include <gl/glew.h>
#include <gl/glut.h>
#include "math_3d.h"

static int gldot()
{
	GLenum res = glewInit();
	if (res != GLEW_OK)
	{
		fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
		return 1;
	}
	Vector3f Vertices[1];
	Vertices[0] = Vector3f(0.0f, 0.0f, 0.0f);
	GLuint VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glDrawArrays(GL_POINTS, 0, 1);
	glDisableVertexAttribArray(0);
	return 0;
}

static void draw()
{
	glClear(GL_COLOR_BUFFER_BIT); //�����ɫ
	glColor3ub(255, 10, 10);
	gldot();
	glFlush();
}

//int main(int argc, char* argv[])
//{
//	glutInit(&argc, (char**)argv); //��ʼ��glut,������ã����������仰����
//	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); //������ʾ��ʽ��RGB�������塣��Ȼ����GLUT_INDEX������ɫ GLUT_DOUBLE˫����(Qt�п�����˫����)
//	glutInitWindowPosition(100, 100); //λ��
//	glutInitWindowSize(400, 400);//���ڴ�С
//	glutCreateWindow("��һ��OpenGL����"); //�������ڣ����ñ���
//	glutDisplayFunc(&draw);
//	glutMainLoop(); //��Ϣѭ��
//	return 0;
//}