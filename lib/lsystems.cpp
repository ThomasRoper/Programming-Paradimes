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

void LSystems::addRule(char lvalue, std::string rvalue)
{
    rules.push_back({lvalue,rvalue});
}

void LSystems::editRule(int ruleNum, char lvalue, std::string rvalue)
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

    std::string lvalue; lvalue += rules[ruleNum].first;
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

std::string LSystems::applyRules()
{

    std::string Alpha = m_alphabet;
    std::string newAlpha;
    bool found = false;
    for(char& c : Alpha)
    {
        found = false;
        for (int i = 0; i< rules.size(); i++)
        {
            if (c == rules[i].first)
            {
                newAlpha += rules[i].second;
                found = true;
            }

        }
        if (!found)
        {
        newAlpha += c;
        }
    }



return newAlpha;
}



void LSystems::generateNextAlphabet()
{
    editAlphabet(applyRules());
}


void LSystems::generateTreeVesions(int numOfVersions)
{
    std::string saveAlpha = m_alphabet;
       for (int i = 0; i< numOfVersions; i++)
       {
           m_treeVersions.push_back(applyRules());
           generateNextAlphabet();
       }
   m_alphabet = saveAlpha;
}

std::string LSystems::getTreeVersion(int version)
{
    return m_treeVersions[version];
}

float LSystems::getAngle()
{
    return m_angle;
}
void LSystems::setAngle(float newAngle)
{
    m_angle = newAngle;
}























