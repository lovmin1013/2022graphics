#include <GL/glut.h>
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glColor3f(1, 1, 0); ///黃色
    glutSolidTeapot( 0.3 ); ///0.3大小的實心茶壺

    glutSwapBuffers();///交換兩倍的buffer
}

int main (int argc, char**argv) ///進階main函式
{
    glutInit(&argc, argv ); ///glut初始化
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH ); ///兩倍buffer(避免顯示出來閃爍)+ 3D
    glutCreateWindow("Week03的視窗"); ///建立視窗
    glutDisplayFunc( display ); ///用來畫圖的函式
    glutMainLoop(); ///主要的迴圈
}
