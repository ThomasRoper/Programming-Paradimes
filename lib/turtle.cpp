#include "turtle.h"
turtle::turtle()
{

}
void turtle::runTurtle()
{
    std::string alphabetCopy = m_lsystem->getAlphabet();
    //resets the line length scaling for the < and > operators
    for (int i = 0; i< m_scale.size(); i++)
    {
    m_scale.pop_back();
    }

    //goes through every letter in the alphabet and calls applyrules on each one
    for(char& c : alphabetCopy)
    {
        applyRules(c);
    }

}
void turtle::applyRules(char _character)
{
    switch (_character) {
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
        m_message = "reverses the current rotation direction";
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
        y += _character;
         m_message = "couldn't find character to match: " + y;
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

void turtle::push()
{
    //pushs the turtles current translation so it can go back to the position after drawing a branch
    glPushMatrix();    
    m_scale.push_back(m_length);
}
void turtle::pop()
{
    //pops the current translation so that the turtle is able to draw from the stem
    glPopMatrix();
    m_length = m_scale.back();
    m_scale.pop_back();
}



