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

    std::string getAlphabet();
    std::string editAlphabet(std::string newAlphabet);
    void setAlphabet(std::string newAlphabet);

    void addRule(char lvalue, std::string rvalue);
    void editRule(int ruleNum, char lvalue, std::string rvalue);
    void removeRule(int ruleNum);
    std::string seeRule(int ruleNum);
    void printRules();

    std::string applyRules();
    void generateNextAlphabet();
    void generateTreeVesions(int numOfVersions);

    std::string getTreeVersion(int version);



private:
    std::string m_alphabet;
    std::vector<std::pair <char,std::string>> rules ;
    std::vector<std::string> m_treeVersions;



};

#endif // LSYSTEMS_H
