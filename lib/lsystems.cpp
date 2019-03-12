#include "lsystems.h"

LSystems::LSystems()
{
    m_alphabet = "\nLSystems has been constructed\n";
}




std::string LSystems::getAlphabet()
{
    std::string Alphabet = m_alphabet;
    return Alphabet;
}

std::string LSystems::editAlphabet(std::string newAlphabet)
{
    m_alphabet = newAlphabet;
    return m_alphabet;
}

void LSystems::setAlphabet(std::string newAlphabet)
{
    m_alphabet = newAlphabet;
}

void LSystems::addRule(std::string lvalue,std::string rvalue)
{
    rules.push_back({lvalue,rvalue});
}

void LSystems::editRule(int ruleNum, std::string lvalue, std::string rvalue)
{
    if (ruleNum <= (rules.size() - 1))
    {
        rules[ruleNum].first = lvalue;
        rules[ruleNum].second = rvalue;
    }
}

void LSystems::removeRule(int ruleNum)
{
    if (ruleNum <= (rules.size() - 1))
    {
      rules[ruleNum] = rules.back();
      rules.pop_back();
    }
}

std::string LSystems::seeRule(int ruleNum)
{

    std::string lvalue = rules[ruleNum].first;
    std::string rvalue = rules[ruleNum].second;

    std::string rule = lvalue + " = " + rvalue + "\n";
    return rule;
}

void LSystems::printRules()
{
    for (int i = 0; i< rules.size(); i++)
    {

        std::cout<<seeRule(i);
    }
}

