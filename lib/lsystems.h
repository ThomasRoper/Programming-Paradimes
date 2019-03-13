#ifndef LSYSTEMS_H
#define LSYSTEMS_H

#include "lsystems_global.h"
#include <iostream>
#include <stdlib.h>
#include <utility>
#include <vector>


class LSYSTEMSSHARED_EXPORT LSystems
{

public:
    LSystems();
    //alphabet stuff
    std::string getAlphabet();
    std::string editAlphabet(std::string newAlphabet);
    void setAlphabet(std::string newAlphabet);
    //rule stuff
    void addRule(char lvalue, std::string rvalue);
    void editRule(int ruleNum, char lvalue, std::string rvalue);
    void removeRule(int ruleNum);
    std::string seeRule(int ruleNum);
    void printRules();
    //applying the two
    std::string applyRules();
    void generateNextAlphabet();
    //multiple iterations of applying the rules
    void generateTreeVesions(int numOfVersions);
    std::string getTreeVersion(int version);
    //angle stuff
    float getAngle();
    void setAngle(float newAngle);



private:
    std::string m_alphabet;
    std::vector<std::pair <char,std::string>> rules ;
    std::vector<std::string> m_treeVersions;
    float m_angle;



};

#endif // LSYSTEMS_H
