#include <GL/glut.h>
#include <stdio.h>
#include <mmsystem.h>
void timer(int t){ ///t ��쬰ms 1000�N��1��
    printf("�x��%d, �_�ɤF!\n", t);
    PlaySound("do.wav", NULL, SND_ASYNC);///�o�X�n��

    printf("�A�]�U�@�Ӿx��\n");
    glutTimerFunc(2000, timer, t+1); ///2���
    ///printf("�]�n�x���A�A�~���!\n");
}
void display()
{

}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week_timer");

    glutTimerFunc(3000, timer, 0); ///3���A�stimer()
    glutDisplayFunc(display);
    glutMainLoop();
}
