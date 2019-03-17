#ifndef SYSTEM_H
#define SYSTEM_H
#include <iostream>
#include <stdlib.h>
#include <utility>
#include <vector>
#include <turtle.h>
#include <lsystems.h>

class turtlesystem
{
public:
    turtlesystem();
    void chooseTemplate(int choice);
    void makeTree();
    void drawTree();
    std::string getName();
private:

        LSystems Tree;
        turtle Turtle;

        float scaleFactor;
        int version;
        std::string name;
        float length;
        float angle;
        std::string axiom;
        std::vector<std::pair <char,std::string>> rules;

};

#endif // SYSTEM_H
