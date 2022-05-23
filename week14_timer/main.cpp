#include <GL/glut.h>
#include <stdio.h>
#include <mmsystem.h>
void timer(int t){ ///t 單位為ms 1000代表1秒
    printf("鬧鐘%d, 起床了!\n", t);
    PlaySound("do.wav", NULL, SND_ASYNC);///發出聲音

    printf("再設下一個鬧鐘\n");
    glutTimerFunc(2000, timer, t+1); ///2秒後
    ///printf("設好鬧鐘，再繼續睡!\n");
}
void display()
{

}
int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week_timer");

    glutTimerFunc(3000, timer, 0); ///3秒後，叫timer()
    glutDisplayFunc(display);
    glutMainLoop();
}
