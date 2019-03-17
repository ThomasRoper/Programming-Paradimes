#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <GL/glut.h>
#include <QTimer>
#include <camera.h>
#include <lsystems.h>
#include <turtlesystem.h>
class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
       explicit GLWidget(QWidget *parent = 0);

       void initializeGL();
       void paintGL();
       void resizeGL(int w,int h);
 //Camera cam();
private:
       QTimer timer;
       //auto ground = glutSolidCube(2.0);
       turtlesystem example;
       turtlesystem trees[5];

};

#endif // GLWIDGET_H
