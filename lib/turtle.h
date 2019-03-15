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
    void setAngle(float angle);
    void setLSystem(LSystems * _lsystem);



private:
    float m_length= 0.2;
    float m_angle= 40;
    LSystems * m_lsystem;
    Vec3 start = Vec3(0.0f,-1.0f,0.0f);
    Vec3 pos;

};

#endif // TURTLE_H
