#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <GL/glut.h>
#include <QTimer>
#include <camera.h>
#include <lsystems.h>
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
        LSystems test;
};

#endif // GLWIDGET_H
