#ifndef LSYSTEMS_H
#define LSYSTEMS_H

#include <iostream>
#include <stdlib.h>
#include <utility>
#include <vector>


class  LSystems
{

public:

    //The LSystems Class deals with taking the Axiom and the Ruleset
    //and generating the Alphabet for the turtle class too follow
/** @brief Constructor*/
    LSystems();

    /** @brief Getting and Setting Functions for Alphabet*/

    std::string getAlphabet(){return m_alphabet;}
    std::string editAlphabet(std::string newAlphabet);
    void setAlphabet(std::string _newAlphabet){m_alphabet = _newAlphabet;}

    /** @brief Rule Functions*/

    void addRule(char lvalue, std::string rvalue){m_rules.push_back({lvalue,rvalue});}
    void editRule(int ruleNum, char lvalue, std::string rvalue);
    void removeRule(int ruleNum);
    std::string seeRule(int ruleNum);
    void printRules();

    /** @brief applys the rules for the current alphabet*/

    std::string applyRules();

    /** @brief applys the rules and overights alphabet or applyRules result*/

    void generateNextAlphabet(){editAlphabet(applyRules());}

    /** @brief generates a number of Alphabet Versions for your current tree
     *  @param numofVersions is the amount of alphabets you want created.
     */

    void generateTreeVesions(int _numOfVersions);

    /** @brief returns one of the tree versions generated
     *  @param version is the specifec version of the tree you want.
     */

    std::string getTreeVersion(int _version){return m_treeVersions[_version];}



private:
    //m_alphabet operates as the alphabet and the axiom to save space as the axiom it the first version
    std::string m_alphabet;
    std::vector<std::pair <char,std::string>> m_rules;
    std::vector<std::string> m_treeVersions;


};

#endif // LSYSTEMS_H
