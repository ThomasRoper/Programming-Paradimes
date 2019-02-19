#include "glwidget.h"
#include <GL/glut.h>

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
    connect(&timer, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer.start(16);
}

void GLWidget::initializeGL()
{
    //sets background colour [r,g,b,a]
    //black
    //glClearColor(0.1,0.1,0.1,1.0);
    //white
    glClearColor(1.0,1.0,1.0,1.0);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);


}
void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //intial triangle test
    /*glBegin(GL_TRIANGLES);
        glColor3f(1,0,0);
        glVertex3f(-0.5, -0.5, 0.0);
        glColor3f(0,1,0);
        glVertex3f( 0.5, -0.5, 0.0);
        glColor3f(0,0,1);
        glVertex3f( 0.0, 0.5, 0.0);
    glEnd();*/
    //should draw a 2d multi coloured triangle


    glRotatef(0.5, 1,1,1);
    glColor3f(1,0.6,0);
    glutSolidTeapot(0.6);
}
void GLWidget::resizeGL(int w,int h)
{
        glViewport(0,0,w,h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(45, (float)w/h, 0.01, 100.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(0,0,5,  0,0,0,  0,1,0);
}
