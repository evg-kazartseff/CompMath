#include <GL/glut.h>
#include "logrange.h"

#define max_Y_size 3

#define step_func 0.0001

logrange Interpolation(-10, 10, 7, 6, [] (double x) { return sin(x); });

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

    DrawGrid(Interpolation.get_left(), Interpolation.get_right(), -max_Y_size, max_Y_size, 1, 1);

    glPointSize(1);
    glColor3f(1, 0, 0);
    glBegin(GL_LINES);

    for (double i = Interpolation.get_left(); i < Interpolation.get_right(); i += step_func) {
        glVertex2d(i, Interpolation.get_val_function(i));
        glVertex2d(i + step_func, Interpolation.get_val_function(i + step_func));
    }


    glEnd();
    glPointSize(4);
    glColor3f(0, 0, 1);
    glBegin(GL_POINTS);

    for (unsigned int j = 0; j < Interpolation.get_number_of_nodes(); ++j) {
        double x = Interpolation.get_node_interpolation(j);
        double y = Interpolation.get_val_function(x);
        glVertex2d(x, y);
    }

    glEnd();

    glPointSize(1);
    glColor3f(0, 1, 0);
    glBegin(GL_LINES);

    for (double i = Interpolation.get_left(); i < Interpolation.get_right(); i += step_func) {
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
    gluOrtho2D(Interpolation.get_left(), Interpolation.get_right(), -max_Y_size, max_Y_size);
    glutDisplayFunc(Display);
    //timer();
    glutMainLoop();
}