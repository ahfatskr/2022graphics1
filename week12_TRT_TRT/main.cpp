#include <GL/glut.h>
float angle=0;
void display()

{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);
    glutSolidTeapot( 0.3 );//��������
    glPushMatrix();///�k�䪺���u��y
        glTranslatef(0.2,0,0);
        glRotatef(angle,0,0,1);
        glTranslatef(0.2,0,0);
        glColor3f(1,0,0);//����
        glutSolidTeapot( 0.2 );//�p���� ��o�O�U���u
        glPushMatrix();///�ƥ��x�}
            glTranslatef(0.2,0,0);
            glRotatef(angle,0,0,1);
            glTranslatef(0.2,0,0);
            glColor3f(1,0,0);//����
            glutSolidTeapot( 0.2 );//�p���� ��o�O�U��y
        glPopMatrix();///�٭�x�}
    glPopMatrix();///�٭�x�}

    glPushMatrix();///���䪺���u��y
        glTranslatef(-0.2,0,0);
        glRotatef(-angle,0,0,1);
        glTranslatef(-0.2,0,0);
        glColor3f(1,0,0);//����
        glutSolidTeapot( 0.2 );//�p���� ��o�O�U���u
        glPushMatrix();///�ƥ��x�}
            glTranslatef(0.2,0,0);
            glRotatef(angle,0,0,1);
            glTranslatef(0.2,0,0);
            glColor3f(1,0,0);//����
            glutSolidTeapot( 0.2 );//�p���� ��o�O�U��y
        glPopMatrix();///�٭�x�}
    glPopMatrix();///�٭�x�}
    glutSwapBuffers();
    angle+=0.1;
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Week12_TRT");

    glutIdleFunc(display);
    glutDisplayFunc(display);
    glutMainLoop();
}
