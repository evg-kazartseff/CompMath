#include <iostream>
#include <GL/glut.h>
#include "interpolation.h"

interpolation Interpolation(-1, 1, 3, 2);




void Display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glutSwapBuffers();
}

void timer(int = 0)
{
    Display();
    glutTimerFunc(5, timer, 0);
}


int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Interpolation");
    glClearColor(1, 1, 1, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 400, 0, 400);
    glutDisplayFunc(Display);
    timer();
    glutMainLoop();
}