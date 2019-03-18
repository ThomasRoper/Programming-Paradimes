#include "lsystems.h"
#include "turtle.h"

LSystems::LSystems()
{
    m_alphabet = "\nLSystems has been constructed\n";
}

std::string LSystems::editAlphabet(std::string newAlphabet)
{
    m_alphabet = newAlphabet;
    return m_alphabet;
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
    //removes a specific rule for a tree
    if (ruleNum <= (m_rules.size() - 1))
    {
        m_rules[ruleNum] = m_rules.back();
        m_rules.pop_back();
    }
}

std::string LSystems::seeRule(int ruleNum)
{
    //prints a single rule for a tree
    std::string lvalue; lvalue += m_rules[ruleNum].first;
    std::string rvalue = m_rules[ruleNum].second;
    std::string rule = lvalue + " -> " + rvalue + "\n";
    return rule;
}

void LSystems::printRules()
{
    //prints all the rules for the current tree
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

void LSystems::generateTreeVesions(int _numOfVersions)
{
    std::string saveAlpha = m_alphabet;
       for (int i = 0; i< _numOfVersions; i++)
       {
           m_treeVersions.push_back(applyRules());
           generateNextAlphabet();
       }
   m_alphabet = saveAlpha;
}





























