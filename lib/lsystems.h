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
    void addRule(std::string lvalue, std::string rvalue);
    void editRule(int ruleNum, std::string lvalue, std::string rvalue);
    void removeRule(int ruleNum);
    std::string seeRule(int ruleNum);
    void printRules();



private:
    std::string m_alphabet;
    std::vector<std::pair <std::string,std::string>> rules ;



};

#endif // LSYSTEMS_H
