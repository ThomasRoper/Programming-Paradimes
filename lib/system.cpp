#include "system.h"

turtlesystem::turtlesystem()
{
    name = "basic_Tree";
    length = 0.2f;
    angle = 30.0f;
    axiom = "F";
    rules.push_back({'F',"FF+[+F-F-F]-[-F+F+F]"});
}

void turtlesystem::chooseTemplate(int choice)
{
    for (int i = 0; i < rules.size(); i++)
    {
    rules.pop_back();
    }
    switch (choice) {
    case 0:
        name = "basic_Tree";
        length = 0.05f;
        angle = 22.5f;
        version = 4;
        axiom = "F";
        rules.push_back({'F',"FF+[+F-F-F]-[-F+F+F]"});
        break;
    case 1:
        name = "Square_Tree";
        length = 0.1f;
        angle = 20.0f;
        version = 8;
        axiom = "VZFFF";
        rules.push_back({'V',"[+++W][---W]YV"});
        rules.push_back({'W',"+X[-W]Z"});
        rules.push_back({'X',"-W[+X]Z"});
        rules.push_back({'Y',"YZ"});
        rules.push_back({'Z',"[-FFF][+FFF]F"});
        break;
    default:
        break;
    }

}

void turtlesystem::makeTree()
{

    Tree.editAlphabet(axiom);
    for (int i = 0; i < rules.size(); i++)
    {
        Tree.addRule(rules[i].first,rules[i].second);
    }
    Turtle.setAngle(angle);
    Turtle.setLength(length);


    Tree.generateTreeVesions(10);
    Tree.editAlphabet(Tree.getTreeVersion(version));

    Turtle.setLSystem(& Tree);


}


void turtlesystem::drawTree()
{
Turtle.runTurtle();
}

std::string turtlesystem::getName()
{
    return name;
}
