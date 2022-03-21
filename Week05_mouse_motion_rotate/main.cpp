#include <GL/glut.h>
float angle= 0, oldX= 0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        glColor3f(1, 0, 0);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}
void mouse(int botton, int state, int x, int y)
{///按下滑鼠、放下滑鼠
    oldX= x;
}
void motion(int x, int y)
{///拖著移動
    angle += (x-oldX);
    oldX = x;
    display();
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("mouse");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop();
}
