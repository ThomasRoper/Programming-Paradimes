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
        m_message = "moved foward";
        break;
    case '+':
        rotatePos();
        m_message = "rotated to the right";
        break;
    case '-':
        rotateNeg();
        m_message = "rotated to the left";
        break;
    case '[':
        push();
        m_message = "pushs current transforms";
        break;
    case ']':
        pop();
        m_message = "pops current transforms";
        break;
    case '|':
        reverse();
        m_message = "reverses the current direction";
        break;
    case '>':
        lineLengthPos();
        m_message = "Multiply the line length by scaler";
        break;
    case '<':
        lineLengthNeg();
        m_message = "Divide the line length by scaler";
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
    glVertex3f(0.0,m_length*m_scale,0.0);
    glEnd();
    glTranslatef(0.0,m_length*m_scale,0.0);

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

void turtle::reverse()
{
    glRotatef(180.0f,0.0f,0.0f,1.0f);
}
void turtle::lineLengthPos()
{
    m_scale *= 2;
}
void turtle::lineLengthNeg()
{
    m_scale /= 2;
}




void turtle::setAngle(float angle)
{
    m_angle = angle;
}


void turtle::setLSystem(LSystems * _lsystem)
{
    m_lsystem=_lsystem;
}

void turtle::setLength(float length)
{
    m_length = length;


}

std::string turtle::getMessage()
{
    return m_message;
}
