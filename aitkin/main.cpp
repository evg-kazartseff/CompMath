#include <GL/glut.h>
#include "aitkin.h"
#include <math.h>

#define max_Y_size 2

#define step_func 0.001

aitkin Interpolation(-10, 10, 1, 0.001, [] (double x) { return sin(x); });


void DrawGrid(double x_min, double x_max, double y_min, double y_max, float step_x, float step_y)
{
    glPointSize(1);
    glColor3f(0, 0 ,0);
    glBegin(GL_POINTS);
    for (double i = x_min; i < x_max; i += step_x) {
        for (double j = y_min; j < y_max; j += step_y) {
            glVertex2d(i, j);
        }
    }
    glEnd();
    glBegin(GL_LINES);

    glColor3f(0, 0, 0);

    glVertex2d(x_min, 0);
    glVertex2d(x_max, 0);

    glVertex2d(0, y_min);
    glVertex2d(0, y_max);

    glEnd();
}


void Display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    DrawGrid(Interpolation.GetLeft(), Interpolation.GetRight(), -max_Y_size, max_Y_size, 1, 1);

    glPointSize(1);
    glColor3f(1, 0, 0);
    glBegin(GL_LINES);

    for (double i = Interpolation.GetLeft(); i < Interpolation.GetRight(); i += step_func) {
        glVertex2d(i, Interpolation.GetValFunction(i));
        glVertex2d(i + step_func, Interpolation.GetValFunction(i + step_func));
    }


    glEnd();

    glPointSize(4);
    glColor3f(0, 0, 1);
    glBegin(GL_POINTS);

    for (unsigned int j = 0; j < Interpolation.GetSizeTable(); ++j) {
        std::pair<double, double> tmp = Interpolation.GetPairPoints(j);
        glVertex2d(tmp.first, tmp.second);
    }

    glEnd();

    glPointSize(1);
    glColor3f(0, 1, 0);
    glBegin(GL_LINES);

    for (double i = Interpolation.GetLeft(); i < Interpolation.GetRight(); i += step_func) {
        glVertex2d(i, Interpolation.calc(i));
        glVertex2d(i + step_func, Interpolation.calc(i + step_func));
    }


    glEnd();

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
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Interpolation");
    glClearColor(1, 1, 1, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(Interpolation.GetLeft(), Interpolation.GetRight(), -max_Y_size, max_Y_size);
    glutDisplayFunc(Display);
    //timer();
    glutMainLoop();
}