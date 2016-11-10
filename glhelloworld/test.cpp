#include <gl/glew.h>
#include <gl/glut.h>
#include <cstring>
//#include <windows.h>
//// ASCII�ַ��ܹ�ֻ��0��127��һ��128���ַ�
//#define MAX_CHAR       128

//void myDisplay(void)
//
//{
//
//	glClear(GL_COLOR_BUFFER_BIT); //�����ɫ
//
//	glRectf(-0.5f, -0.5f, 0.5f, 0.5f); //��һ������
//
//	glFlush(); //��ǰ�����������ִ�ж������ڻ���������fflush(stdout)��������
//
//}

//void drawString() {
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	glColor3f(1.0f, 0.0f, 0.0f);
//	glRasterPos2f(0.0f, 0.0f);
//
//	char* str = "hello world!";
//	static int isFirstCall = 1;
//	static GLuint lists;
//
//	if (isFirstCall) { // ����ǵ�һ�ε��ã�ִ�г�ʼ��
//					   // Ϊÿһ��ASCII�ַ�����һ����ʾ�б�
//		isFirstCall = 0;
//
//		// ����MAX_CHAR����������ʾ�б���
//		lists = glGenLists(MAX_CHAR);
//
//		// ��ÿ���ַ��Ļ������װ����Ӧ����ʾ�б���
//		wglUseFontBitmaps(wglGetCurrentDC(), 0, MAX_CHAR, lists);
//	}
//	// ����ÿ���ַ���Ӧ����ʾ�б�����ÿ���ַ�
//	for (; *str != '\0'; ++str)
//		glCallList(lists + *str);
//
//	glFlush();
//}

void show_text(char *text_toshow)
{
	/* There are 7 bitmap fonts available in GLUT. They are
	GLUT_BITMAP_8_BY_13
	GLUT_BITMAP_9_BY_15
	GLUT_BITMAP_TIMES_ROMAN_10
	GLUT_BITMAP_TIMES_ROMAN_24
	GLUT_BITMAP_HELVETICA_10
	GLUT_BITMAP_HELVETICA_12
	GLUT_BITMAP_HELVETICA_18 */
	void * font = GLUT_BITMAP_HELVETICA_18;
	glColor3ub(255, 100, 10);
	glRasterPos2i(0, 0);
	for (int i = 0; i <= strlen(text_toshow); ++i) {
		char c = text_toshow[i];
		glutBitmapCharacter(font, c);
	}
}

void displayString()
{
	glClear(GL_COLOR_BUFFER_BIT); //�����ɫ
	show_text("hello world!");
	glFlush(); //��ǰ�����������ִ�ж������ڻ���������fflush(stdout)��������
}

//int main(int argc, char* argv[])
//
//{
//
//	glutInit(&argc, (char**)argv); //��ʼ��glut,������ã����������仰����
//
//	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); //������ʾ��ʽ��RGB�������塣��Ȼ����GLUT_INDEX������ɫ GLUT_DOUBLE˫����(Qt�п�����˫����)
//
//	glutInitWindowPosition(100, 100); //λ��
//
//	glutInitWindowSize(400, 400);//���ڴ�С
//
//	glutCreateWindow("��һ��OpenGL����"); //�������ڣ����ñ���
//
//	//glutDisplayFunc(&myDisplay); // �����ƴ���ʱ����myDisplay����Cocos2d-xˢ֡Draw�еĲ���
//	glutDisplayFunc(&displayString);
//
//	glutMainLoop(); //��Ϣѭ��
//
//	return 0;
//
//}