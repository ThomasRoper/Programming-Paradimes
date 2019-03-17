#ifndef TURTLE_H
#define TURTLE_H
#include <lsystems.h>
#include <glm/vec3.hpp>
#include <vec3.h>


class turtle
{
public:
    turtle();
    void runTurtle();
    void applyRules(char x);

    void moveFoward();
    void rotateNeg();
    void rotatePos();
    void push();
    void pop();
    void reverse();
    void lineLengthPos();
    void lineLengthNeg();


    void setAngle(float angle);
    void setLSystem(LSystems * _lsystem);
    void setLength(float length);


    std::string getMessage();



private:
    float m_length;
    float m_angle;
    float m_scale = 1.0f;
    LSystems * m_lsystem;
    Vec3 start = Vec3(0.0f,-1.0f,0.0f);
    Vec3 pos;
    std::string m_message;

};

#endif // TURTLE_H
