///a
#include<GL/glut.h>
#include<stdio.h>
float angle[20],oldX=0;
int angleID=0;
FILE * fout = NULL, * fin = NULL;
void myWrite(){
    if(fout == NULL) fout = fopen("file.txt","w+");

    for(int i=0;i<20;i++){
            printf("%.1f ",angle[i]);///�p�¦L�X��
            fprintf(fout,"%.1f ",angle[i]);///�ɮצL�X��
    }///�o�̦Ѯv�S��fclose
    printf("\n");
    fprintf(fout,"\n");
}
void myRead(){
    if( fout != NULL){ fclose(fout); fout=NULL; }
    if( fin == NULL ) fin = fopen("file.txt"," r");
    for(int i=0;i<20;i++){
        fscanf(fin, "%f",&angle[i]);
    }
    glutPostRedisplay();
}
void keyboard(unsigned char key,int x,int y){
    if(key=='s') myWrite();///�զn�ʧ@�~�s��
    if(key=='r') myRead();
    if(key=='1') angleID=1;
    if(key=='2') angleID=2;
    if(key=='3') angleID=3;
}
void mouse(int button,int state,int x,int y){
    oldX=x;
}
void motion(int x,int y){
    angle[angleID] += (x-oldX);
    ///myWrite();
    oldX = x;
    glutPostRedisplay();///��GLUT���e�e��Re display
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///�զ⪺
    glRectf(0.3,0.5,-0.3,-0.5);///�|���
    glPushMatrix();///�k�b��
        glTranslatef(0.3,0.4,0);///(3)����u���^����
        glRotatef(angle[0],0,0,1);///(2)���� ��Z�b��
        glTranslatef(-0.3,-0.4,0);///(1)����u�����त��,�񤤤�
        glColor3f(1,0,0);//���⪺
        glRectf(0.3,0.5,0.7,0.3);

        glPushMatrix();
            glTranslatef(0.7,0.4,0);///(3)���y���^��誺��m
            glRotatef(angle[1],0,0,1);///(2)����
            glTranslatef(-0.7,-0.4,0);///(1)���y���त��,�񤤤�
            glColor3f(0,1,0);///��⪺
            glRectf(0.7,0.5,1.0,0.3);///�W���u
        glPopMatrix();

        glPushMatrix();///���b��
        glTranslatef(-0.3,0.4,0);///(3)����u���^����
        glRotatef(angle[2],0,0,1);///(2)���� ��Z�b��
        glTranslatef(0.3,-0.4,0);///(1)����u�����त��,�񤤤�
        glColor3f(1,0,0);///���⪺
        glRectf(-0.3,0.5,-0.7,0.3);

        glPushMatrix();
            glTranslatef(-0.7,0.4,0);///(3)���y���^��誺��m
            glRotatef(angle[3],0,0,1);///(2)����
            glTranslatef(0.7,-0.4,0);///(1)���y���त��,�񤤤�
            glColor3f(0,1,0);///��⪺
            glRectf(-0.7,0.5,-1.0,0.3);///�W���u
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc, char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    //glutInitWindowSize(600,600);
    glutCreateWindow("week13 rect TRT");

    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);

    glutMainLoop();
}
