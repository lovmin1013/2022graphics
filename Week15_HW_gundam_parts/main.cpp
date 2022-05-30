///��gundam���X��  �n��glm.h glm.cpp �� gundam 5���ɮ�
#include <GL/glut.h>
#include <stdio.h> ///���F printf , fprintf, fopen, fclose
#include "glm.h"
GLMmodel * pmodel = NULL;
GLMmodel * head = NULL;
GLMmodel * body = NULL;
GLMmodel * bot = NULL;
GLMmodel * arm1 = NULL;
GLMmodel * arm2 = NULL;
GLMmodel * hand1 = NULL;
GLMmodel * hand2 = NULL;

float angle[20], oldX=0; ///�����k�s
int angleID=0; ///0����0�����`...�H������
FILE * fout = NULL, * fin = NULL;
void myWrite(){
    if(fout==NULL) fout= fopen("file.txt", "w+");
    for(int i=0; i<20; i++){
        printf("%.2f ", angle[i]);
        fprintf(fout, "%.2f ", angle[i]);
    }
    printf("\n");
    fprintf(fout, "\n");
    ///�֤Ffclose�A�]�����Q�L�@��N�����A�n�h��@�I
}
void myRead()
{
    if(fout!=NULL){ /// �٦bŪ���ɮ�����
        fclose(fout);
        fout=NULL;
    }
    if(fin==NULL) fin= fopen("file.txt", "r");
    for(int i=0; i<20; i++){
        fscanf(fin, "%f", &angle[i]);
    }
    glutPostRedisplay(); ///���e�e��
}
void keyboard(unsigned char key, int x, int y)
{
    if(key == '0') angleID=0; ///�w�]
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
    ///myWrite(); ///�S���n�@���g��
    oldX= x;
    glutPostRedisplay();
}
GLMmodel * myReadOne(char * filename){
    GLMmodel * one = NULL;
    if(one == NULL){
        one = glmReadOBJ(filename);
        glmUnitize(one);
        glmFacetNormals(one);
        glmVertexNormals(one, 90);
    }
    return one;
}
void display()///�̷s��display
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if(head==NULL) head= myReadOne("data/head.obj");
    if(body==NULL) body= myReadOne("data/body.obj");
    glmDraw(head, GLM_SMOOTH);

    glutSwapBuffers();
}
void displayNotParts()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if(pmodel == NULL) {
        pmodel = glmReadOBJ("data/Gundam.obj");
        glmUnitize(pmodel);
        glmFacetNormals(pmodel);
        glmVertexNormals(pmodel, 90);
    }
    glmDraw(pmodel, GLM_SMOOTH);
    glutSwapBuffers();
}
void displayOld()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1, 1, 1); ///�զ⪺
    glRectf(0.3, 0.5, -0.3, -0.2); ///����

    glPushMatrix(); ///�k�b��
        glTranslatef(0.3, 0.4, 0);
        glRotatef(angle[0], 0, 0, 1);
        glTranslatef(-0.3, -0.4, 0);
        glColor3f(1, 0, 0); ///����
        glRectf(0.3, 0.5, 0.8, 0.3); ///���u
        glPushMatrix();
            glTranslatef(0.8, 0.4, 0);/// 3. ���y���b���`�W
            glRotatef(angle[1], 0, 0, 1);/// 2. ����
            glTranslatef(-0.8, -0.4, 0);/// 1. ���y���त�ߩ�줤��
            glColor3f(0, 1, 0);
            glRectf(0.8, 0.5, 1.1, 0.3);/// �A�e��y
        glPopMatrix();
    glPopMatrix();

    glPushMatrix(); ///���b��
        glTranslatef(-0.3, 0.4, 0);
        glRotatef(angle[2], 0, 0, 1);
        glTranslatef(0.3, -0.4, 0);
        glColor3f(1, 0, 0); ///����
        glRectf(-0.3, 0.5, -0.8, 0.3); ///���u
        glPushMatrix();
            glTranslatef(-0.8, 0.4, 0);/// 3. ���y���b���`�W
            glRotatef(angle[3], 0, 0, 1);/// 2. ����
            glTranslatef(0.8, -0.4, 0);/// 1. ���y���त�ߩ�줤��
            glColor3f(0, 1, 0);
            glRectf(-0.8, 0.5, -1.1, 0.3);/// �A�e��y
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
    glutDisplayFunc(display); ///����Idle

    glutMainLoop();
}
