#include <GL/glut.h>
float angle=0;
void display()

{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);
    glutSolidTeapot( 0.3 );//茶壺當身體
    glPushMatrix();///右邊的手臂手肘
        glTranslatef(0.2,0,0);
        glRotatef(angle,0,0,1);
        glTranslatef(0.2,0,0);
        glColor3f(1,0,0);//紅的
        glutSolidTeapot( 0.2 );//小茶壺 當她是下手臂
        glPushMatrix();///備份矩陣
            glTranslatef(0.2,0,0);
            glRotatef(angle,0,0,1);
            glTranslatef(0.2,0,0);
            glColor3f(1,0,0);//紅的
            glutSolidTeapot( 0.2 );//小茶壺 當她是下手肘
        glPopMatrix();///還原矩陣
    glPopMatrix();///還原矩陣

    glPushMatrix();///左邊的手臂手肘
        glTranslatef(-0.2,0,0);
        glRotatef(-angle,0,0,1);
        glTranslatef(-0.2,0,0);
        glColor3f(1,0,0);//紅的
        glutSolidTeapot( 0.2 );//小茶壺 當她是下手臂
        glPushMatrix();///備份矩陣
            glTranslatef(0.2,0,0);
            glRotatef(angle,0,0,1);
            glTranslatef(0.2,0,0);
            glColor3f(1,0,0);//紅的
            glutSolidTeapot( 0.2 );//小茶壺 當她是下手肘
        glPopMatrix();///還原矩陣
    glPopMatrix();///還原矩陣
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
