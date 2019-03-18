#ifndef TURTLE_H
#define TURTLE_H
#include <lsystems.h>
#include <glm/vec3.hpp>
#include <GL/glut.h>



class turtle
{
public:

    turtle();

    /** @brief Runs Through Alpabet appling the Rules for the Tree. Drawing it in the process*/

    void runTurtle();

    /** @brief Applys the TurtleGraphics Rules to a single charater passed to it(character).
     *  @param character should be part of larger string being passed in.
     */

    void applyRules(char _character);

    /** @brief The Different Moves the Turtle can make in applyRules*/

    void moveFoward();
    void moveFowardNotDraw(){glTranslatef(0.0,m_length,0.0);}
    void rotateNeg(){glRotatef(m_angle,0.0f,0.0f,1.0f);}
    void rotatePos(){glRotatef(-m_angle,0.0f,0.0f,1.0f);}
    void push();
    void pop();
    void reverse(){glRotatef(180.0f,0.0f,0.0f,1.0f);}
    void lineLengthPos(){ m_length /= m_scaleFactor;}
    void lineLengthNeg(){m_length *= m_scaleFactor;}
    void flipRotate(){ m_angle = -m_angle;}

    /** @brief Getting and Setting Functions*/

    void setAngle(float _angle){m_angle = _angle;}
    void setLSystem(LSystems * _lsystem){m_lsystem=_lsystem;}
    void setLength(float _length){m_length = _length;}
    void setScaleFactor(float scaleAmount){m_scaleFactor = scaleAmount;}
    std::string getMessage(){return m_message;}

private:

    //the length of the line segments being drawn by the 'F' character
    float m_length;
    //the angle of rotation for the tree
    float m_angle;
    //a scale vector that saves scale values alongside push and pop
    std::vector<float> m_scale;
    //the amount scaled by each '<','>' symbol
    float m_scaleFactor = 1.36f;
    //pointer to LSystems so Turtle can get alphabet or treeVersions
    LSystems * m_lsystem;
    //message string for testing
    std::string m_message;

};

#endif // TURTLE_H
