#include <stdio.h>
#include <GL/glut.h>
int N=0; ///�@�}�l�S�������I
int x[1000], y[1000]; ///�̦h1000�ӳ��I
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);
    for(int i=0; i<N; i++){ ///�ΰj�� �eN�ӳ��I
        glVertex2f( (x[i]-150)/150.0, -(y[i]-150)/150.0);
    }    ///�f�Z:  ��@�b�B���@�b y�n�[�t��
    glEnd();
    glutSwapBuffers();
}
void motion(int mouseX, int mouseY)
{
    N++; ///�h�@�ӳ��I
    x[N-1] = mouseX; ///�̫�@�ӷs�W�����Ix�y��
    y[N-1] = mouseY; ///�̫�@�ӷs�W�����Iy�y��
    printf("���U�ƹ��A�o��s�y�� %d %d\n", x[N-1], y[N-1]);
    display();
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("mouse");

    glutDisplayFunc(display);
    glutMotionFunc(motion);
    glutMainLoop();
}
