#include <gl/glew.h>
#include <gl/glut.h>
#include <cstring>
//#include <windows.h>
//// ASCII字符总共只有0到127，一共128种字符
//#define MAX_CHAR       128

//void myDisplay(void)
//
//{
//
//	glClear(GL_COLOR_BUFFER_BIT); //清除颜色
//
//	glRectf(-0.5f, -0.5f, 0.5f, 0.5f); //画一个矩形
//
//	glFlush(); //让前面的命令立即执行而不是在缓冲区，与fflush(stdout)作用类似
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
//	if (isFirstCall) { // 如果是第一次调用，执行初始化
//					   // 为每一个ASCII字符产生一个显示列表
//		isFirstCall = 0;
//
//		// 申请MAX_CHAR个连续的显示列表编号
//		lists = glGenLists(MAX_CHAR);
//
//		// 把每个字符的绘制命令都装到对应的显示列表中
//		wglUseFontBitmaps(wglGetCurrentDC(), 0, MAX_CHAR, lists);
//	}
//	// 调用每个字符对应的显示列表，绘制每个字符
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
	glClear(GL_COLOR_BUFFER_BIT); //清除颜色
	show_text("hello world!");
	glFlush(); //让前面的命令立即执行而不是在缓冲区，与fflush(stdout)作用类似
}

//int main(int argc, char* argv[])
//
//{
//
//	glutInit(&argc, (char**)argv); //初始化glut,必须调用，复制黏贴这句话即可
//
//	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); //设置显示方式，RGB、单缓冲。当然还有GLUT_INDEX索引颜色 GLUT_DOUBLE双缓冲(Qt中看到过双缓冲)
//
//	glutInitWindowPosition(100, 100); //位置
//
//	glutInitWindowSize(400, 400);//窗口大小
//
//	glutCreateWindow("第一个OpenGL程序"); //创建窗口，设置标题
//
//	//glutDisplayFunc(&myDisplay); // 当绘制窗口时调用myDisplay，像Cocos2d-x刷帧Draw中的操作
//	glutDisplayFunc(&displayString);
//
//	glutMainLoop(); //消息循环
//
//	return 0;
//
//}