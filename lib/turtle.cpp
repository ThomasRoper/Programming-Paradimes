#include "turtle.h"
#include <GL/glut.h>
turtle::turtle()
{

}
void turtle::runTurtle()
{
    std::string alphabetCopy = m_lsystem->getAlphabet();
    for(char& c : alphabetCopy)
    {
        applyRules(c);
    }

}
void turtle::applyRules(char x)
{
    switch (x) {
    case 'F':
        moveFoward();
        std::cout<<"moved foward\n";
        break;
    case '+':
       rotatePos();
        break;
    case '-':
       rotateNeg();
        break;
    case '[':
       push();
        break;
    case ']':
       pop();
        break;

    default:
        std::string y;
        y += x;
        std::cout<<"couldn't find character to match: " + y + " \n";
        break;
    }
}
void turtle::moveFoward()
{
    glBegin(GL_LINES);
        glVertex3f(0.0,0.0,0.0);
        glVertex3f(0.0,m_length,0.0);
    glEnd();
    glTranslatef(0.0,m_length,0.0);

}
void turtle::rotateNeg()
{
    glRotatef(m_angle,0.0f,0.0f,1.0f);
}
void turtle::rotatePos()
{
    glRotatef(-m_angle,0.0f,0.0f,1.0f);
}
void turtle::push()
{
    glPushMatrix();
}
void turtle::pop()
{
    glPopMatrix();
}
void turtle::setAngle(float angle)
{
    m_angle = angle;
}


void turtle::setLSystem(LSystems * _lsystem)
{
    m_lsystem=_lsystem;
}
