#include "glwidget.h"
#include <GL/glut.h>
#include <camera.h>
#include "lsystems.h"
#include "turtle.h"
#include "turtlesystem.h"

#define WIDTH 350
#define HEIGHT 350

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
    glClearColor(0.5,0.5,0.5,1.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);

    //basic libraby test

    //test.editAlphabet("F");
    //test.addRule('F',"FF+[+F-F-F]-[-F+F+F]");
    /*
    test.editAlphabet("FX");
    test.addRule('X',"[-FX]+FX");

    std::cout<<test.getAlphabet() + "\n";

    test.editAlphabet(test.applyRules());
    std::cout<<test.getAlphabet() + "\n";
    test.editAlphabet(test.applyRules());

    test.editAlphabet(test.applyRules());
    test.editAlphabet(test.applyRules());
    */
    example.chooseTemplate(4);
    example.makeTree();
    trees[0].chooseTemplate(0);
    trees[0].makeTree();
    trees[1].chooseTemplate(1);
    trees[1].makeTree();
    trees[2].chooseTemplate(2);
    trees[2].makeTree();
    trees[3].chooseTemplate(3);
    trees[3].makeTree();
    trees[4].chooseTemplate(4);
    trees[4].makeTree();


};
void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glTranslatef(0.0,-1.0,0.0);
    /*glBegin(GL_LINES);


        glVertex3f(-1.0, -1.0, 0.0);
        glVertex3f( 1.0, -1.0, 0.0);
        glVertex3f( 0.0, -1.0, -1.0);
        glVertex3f( 0.0, -1.0, 1.0);
        glVertex3f(-1.0, -1.0, -1.0);
        glVertex3f(-1.0, -1.0, 1.0);
        glVertex3f(-1.0, -1.0, -1.0);
        glVertex3f( 1.0, -1.0, -1.0);
        glVertex3f( 1.0, -1.0, -1.0);
        glVertex3f( 1.0, -1.0, 1.0);
        glVertex3f(-1.0, -1.0, 1.0);
        glVertex3f( 1.0, -1.0, 1.0);
    glEnd();*/
    glRotatef(0.3, 0.0,0.1,0.0);


    glPushMatrix();
    glTranslatef(-1.0,-1.0,-1.0);
    glRotatef(90, 1.0,0.0,0.0);
    glRotatef(45, 0.0,0.0,1.0);
    example.drawTree();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(0.0,-1.0,0.0);
    glTranslatef(-0.8,0.0,-0.8);
    trees[0].drawTree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0,-1.0,0.0);
    glTranslatef(-0.8,0.0,0.8);
    trees[1].drawTree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0,-1.0,0.0);
    glTranslatef(0.8,0.0,-0.8);
    trees[2].drawTree();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0,-1.0,0.0);
    glTranslatef(0.8,0.0,0.8);
    trees[3].drawTree();
    glPopMatrix();

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
