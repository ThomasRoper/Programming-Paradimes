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

    /** @brief Constructor*/

    turtlesystem();
    /** @brief Choose from 18 different pre-made trees
     * *  @param choice is the option from 0-17.
     */
    void chooseTemplate(int _choice);
    /** @brief makes all the inputs for the tree. called at the end of choose templae*/
    void makeTree();
    /** @brief Runs the Turtle to draw the specified tree*/
    void drawTree();
    /** @brief Gets the trees name for testing purposes*/
    std::string getName();
private:
        //Lsystem to deal with the rules and alphabet
        LSystems m_Tree;
        //Turtle to draw the alphabet once its generated
        turtle m_Turtle;

        //the different parameters for the tree. given no m_ for ease of use
        float scaleFactor;
        int version;
        std::string name;
        float length;
        float angle;
        std::string axiom;
        std::vector<std::pair <char,std::string>> rules;

};

#endif // SYSTEM_H
