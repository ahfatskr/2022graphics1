#include <GL./glut.h>

void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glColor3f(1,1,0);
    //glutSolidTeapot(0.3);
    glBegin(GL_POLYGON);
        glColor3f(1,0,0);
        glVertex2f(-1, -1);

        glColor3f(0,1,0);
        glVertex2f(+1, -1);

        glColor3f(0,0,1);
        glVertex2f(0, +1);

    glEnd();

    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("第二週的程式喔!");

    glutDisplayFunc(display);

    glutMainLoop();
}
