#include <GL/glut.h>
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glColor3f(1, 1, 0); ///����
    glutSolidTeapot( 0.3 ); ///0.3�j�p����߯���

    glutSwapBuffers();///�洫�⭿��buffer
}

int main (int argc, char**argv) ///�i��main�禡
{
    glutInit(&argc, argv ); ///glut��l��
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH ); ///�⭿buffer(�קK��ܥX�Ӱ{�{)+ 3D
    glutCreateWindow("Week03������"); ///�إߵ���
    glutDisplayFunc( display ); ///�Ψӵe�Ϫ��禡
    glutMainLoop(); ///�D�n���j��
}
