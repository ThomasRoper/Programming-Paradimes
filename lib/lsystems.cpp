#include "lsystems.h"
#include "turtle.h"

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
    m_rules.push_back({lvalue,rvalue});
}

void LSystems::editRule(int ruleNum, char lvalue, std::string rvalue)
{
    if (ruleNum <= (m_rules.size() - 1))
    {
        m_rules[ruleNum].first = lvalue;
        m_rules[ruleNum].second = rvalue;
    }
}

void LSystems::removeRule(int ruleNum)
{
    if (ruleNum <= (m_rules.size() - 1))
    {
        m_rules[ruleNum] = m_rules.back();
        m_rules.pop_back();
    }
}

std::string LSystems::seeRule(int ruleNum)
{

    std::string lvalue; lvalue += m_rules[ruleNum].first;
    std::string rvalue = m_rules[ruleNum].second;

    std::string rule = lvalue + " = " + rvalue + "\n";

    return rule;
}

void LSystems::printRules()
{
    for (int i = 0; i< m_rules.size(); i++)
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
        for (int i = 0; i< m_rules.size(); i++)
        {
            if (c == m_rules[i].first)
            {
                newAlpha += m_rules[i].second;
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

























