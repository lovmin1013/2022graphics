#include <GL/glut.h>
#include <stdio.h> ///為了 printf , fprintf, fopen, fclose
float angle[20], oldX=0; ///角度歸零
int angleID=0; ///0為第0個關節...以此類推
FILE * fout = NULL, * fin = NULL;
void myWrite(){
    if(fout==NULL) fout= fopen("file.txt", "w+");
    for(int i=0; i<20; i++){
        printf("%.2f ", angle[i]);
        fprintf(fout, "%.2f ", angle[i]);
    }
    printf("\n");
    fprintf(fout, "\n");
    ///少了fclose，因為不想印一行就結束，要多行一點
}
void myRead()
{
    if(fout!=NULL){ /// 還在讀的檔案關掉
        fclose(fout);
        fout=NULL;
    }
    if(fin==NULL) fin= fopen("file.txt", "r");
    for(int i=0; i<20; i++){
        fscanf(fin, "%f", &angle[i]);
    }
    glutPostRedisplay(); ///重畫畫面
}
void keyboard(unsigned char key, int x, int y)
{
    if(key == '0') angleID=0; ///預設
    if(key == '1') angleID=1;
    if(key == '2') angleID=2;
    if(key == '3') angleID=3;
    if(key == 'r') myRead();
    if(key == 's') myWrite(); ///save
}
void mouse(int button, int state, int x, int y)
{
    oldX= x;
}
void motion(int x, int y)
{
    angle[angleID] += (x-oldX);
    ///myWrite(); ///沒必要一直寫檔
    oldX= x;
    glutPostRedisplay();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1, 1, 1); ///白色的
    glRectf(0.3, 0.5, -0.3, -0.2); ///身體

    glPushMatrix(); ///右半邊
        glTranslatef(0.3, 0.4, 0);
        glRotatef(angle[0], 0, 0, 1);
        glTranslatef(-0.3, -0.4, 0);
        glColor3f(1, 0, 0); ///紅色
        glRectf(0.3, 0.5, 0.8, 0.3); ///手臂
        glPushMatrix();
            glTranslatef(0.8, 0.4, 0);/// 3. 把手肘掛在關節上
            glRotatef(angle[1], 0, 0, 1);/// 2. 旋轉
            glTranslatef(-0.8, -0.4, 0);/// 1. 把手肘旋轉中心放到中間
            glColor3f(0, 1, 0);
            glRectf(0.8, 0.5, 1.1, 0.3);/// 再畫手肘
        glPopMatrix();
    glPopMatrix();

    glPushMatrix(); ///左半邊
        glTranslatef(-0.3, 0.4, 0);
        glRotatef(angle[2], 0, 0, 1);
        glTranslatef(0.3, -0.4, 0);
        glColor3f(1, 0, 0); ///紅色
        glRectf(-0.3, 0.5, -0.8, 0.3); ///手臂
        glPushMatrix();
            glTranslatef(-0.8, 0.4, 0);/// 3. 把手肘掛在關節上
            glRotatef(angle[3], 0, 0, 1);/// 2. 旋轉
            glTranslatef(0.8, -0.4, 0);/// 1. 把手肘旋轉中心放到中間
            glColor3f(0, 1, 0);
            glRectf(-0.8, 0.5, -1.1, 0.3);/// 再畫手肘
        glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();
}
int main(int argc,char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Week15_angles_TRT_again");

    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display); ///不放Idle

    glutMainLoop();
}
