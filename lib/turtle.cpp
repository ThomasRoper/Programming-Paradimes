#include "turtle.h"
#include <GL/glut.h>
turtle::turtle()
{

}
void turtle::runTurtle()
{
    std::string alphabetCopy = m_lsystem->getAlphabet();
    for (int i = 0; i< m_scale.size(); i++)
    {
    m_scale.pop_back();
    }


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
    case 'f':
        moveFowardNotDraw();
        m_message = "moved foward without drawing";
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
         m_message = "couldn't find character to match: " + y + " \n";
        break;
    }
}
void turtle::moveFoward()
{
    glBegin(GL_LINES);
    glVertex3f(0.0,0.0,0.0);
    glVertex3f(0.0,m_length/**m_scale[m_scale.size()]*/,0.0);
    glEnd();
    glTranslatef(0.0,m_length,0.0);
    //if (m_scale != 1.0f)m_scale = 1.0f;

}
void turtle::moveFowardNotDraw()
{
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
    m_scale.push_back(m_length);

}
void turtle::pop()
{
    glPopMatrix();
    m_length = m_scale.back();
    m_scale.pop_back();
}

void turtle::reverse()
{
    glRotatef(180.0f,0.0f,0.0f,1.0f);
}
void turtle::lineLengthPos()
{
    m_length /= m_scaleFactor;
}
void turtle::lineLengthNeg()
{
    m_length *= m_scaleFactor;
}

void turtle::flipRotate()
{
    m_angle = -m_angle;
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
