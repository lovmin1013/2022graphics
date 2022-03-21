#include <stdio.h>
#include <GL/glut.h>
int N=0; ///一開始沒有任何頂點
int x[1000], y[1000]; ///最多1000個頂點
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);
    for(int i=0; i<N; i++){ ///用迴圈 畫N個頂點
        glVertex2f( (x[i]-150)/150.0, -(y[i]-150)/150.0);
    }    ///口訣:  減一半、除一半 y要加負號
    glEnd();
    glutSwapBuffers();
}
void motion(int mouseX, int mouseY)
{
    N++; ///多一個頂點
    x[N-1] = mouseX; ///最後一個新增之頂點x座標
    y[N-1] = mouseY; ///最後一個新增之頂點y座標
    printf("按下滑鼠，得到新座標 %d %d\n", x[N-1], y[N-1]);
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
