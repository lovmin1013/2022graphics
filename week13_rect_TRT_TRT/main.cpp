#include <GL/glut.h>
float angle=0, oldX=0; ///角度歸零
void mouse(int button, int state, int x, int y)
{
    oldX= x;
}
void motion(int x, int y)
{
    angle += (x-oldX);
    oldX= x;
    glutPostRedisplay();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1, 1, 1); ///白色的
    glRectf(0.3, 0.5, -0.3, -0.2); ///身體
    glPushMatrix();
        glTranslatef(0.3, 0.5, 0);
        ///glRotatef(angle, 0, 0, 1);
        glTranslatef(-0.3, -0.4, 0);
        glColor3f(1, 0, 0); ///紅色
        glRectf(0.3, 0.5, 0.8, 0.3); ///手臂
        glPushMatrix();
            glTranslatef(0.8, 0.4, 0);/// 3. 把手肘掛在關節上
            glRotatef(angle, 0, 0, 1);/// 2. 旋轉
            glTranslatef(-0.8, -0.4, 0);/// 1. 把手肘旋轉中心放到中間
            glColor3f(0, 1, 0);
            glRectf(0.8, 0.5, 1.1, 0.3);/// 再畫手肘
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc,char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Week13_rect_TRT");

    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display); ///不放Idle

    glutMainLoop();
}
