#include "lsystems.h"
#include "turtle.h"
#include "turtlesystem.h"

#include <gtest/gtest.h>

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


TEST(LSystems,lsystemsConstructorAndGet)
{
    LSystems test;
    ASSERT_EQ(test.getAlphabet(),"\nLSystems has been constructed\n");
}


TEST(LSystems,editAlpabet)
{
    LSystems test;
    ASSERT_EQ(test.editAlphabet("This is a test"),"This is a test");
}

TEST(LSystems,setAlpabet)
{
    LSystems test;
    test.setAlphabet("This is a test");
    ASSERT_EQ(test.getAlphabet(),"This is a test");
}

TEST(LSystems,addRule)
{
    LSystems test;
    test.addRule('A', "AB");
    ASSERT_EQ(test.seeRule(0),"A = AB\n");

    test.addRule('C',"CD");
    test.addRule('E',"EF");
    ASSERT_EQ(test.seeRule(1),"C = CD\n");

}


TEST(LSystems,editRule)
{
    LSystems test;
    test.addRule('A',"TB");
    test.editRule(0,'X',"TY");
    ASSERT_EQ(test.seeRule(0),"X = TY\n");
}

TEST(LSystems,removeRule)
{
    LSystems test;
    test.addRule('A',"TB");
    test.addRule('C',"TD");
    test.removeRule(0);
    ASSERT_EQ(test.seeRule(0),"C = TD\n");
}


TEST(LSystems,applyRules)
{
    LSystems test;
    test.editAlphabet("A");
    test.addRule('A',"AB");
    ASSERT_EQ(test.applyRules(),"AB");
}

TEST(LSystems,applyRules2)
{
    LSystems test;
    test.editAlphabet("A");
    test.addRule('C',"AB");
    ASSERT_EQ(test.applyRules(),"A");
}


TEST(LSystems,applyRules3)
{
    LSystems test;
    test.editAlphabet("ABC");
    test.addRule('A',"C");
    test.addRule('B',"D");
    test.addRule('C',"A");
    ASSERT_EQ(test.applyRules(),"CDA");
}

TEST(LSystems,generateNextAlphabet)
{
    LSystems test;
    test.editAlphabet("A");
    test.addRule('A',"AC");
    test.generateNextAlphabet();
    ASSERT_EQ(test.getAlphabet(),"AC");
}
TEST(LSystems,generatingTreeVersions)
{
    LSystems test;
    test.editAlphabet("A");
    test.addRule('A',"AC");
    test.generateTreeVesions(4);
    ASSERT_EQ(test.getTreeVersion(3),"ACCCC");
}


TEST(turtle, runTurtleFoward)
{
    LSystems test;
    turtle tust;
    test.editAlphabet("F");
    test.addRule('F',"FF");
    test.editAlphabet(test.applyRules());
    tust.setAngle(30.0f);
    tust.setLength(0.5f);
    tust.setLSystem(& test);
    tust.runTurtle();

    ASSERT_EQ(tust.getMessage(),"moved foward");
}
TEST(turtle, runTurtleFowardNotDraw)
{
    LSystems test;
    turtle tust;
    test.editAlphabet("f");
    test.addRule('f',"ff");
    test.editAlphabet(test.applyRules());
    tust.setAngle(30.0f);
    tust.setLength(0.5f);
    tust.setLSystem(& test);
    tust.runTurtle();

    ASSERT_EQ(tust.getMessage(),"moved foward without drawing");
}
TEST(turtle, runTurtleRotatePos)
{
    LSystems test;
    turtle tust;
    test.editAlphabet("+");
    test.addRule('+',"++");
    test.editAlphabet(test.applyRules());
    tust.setAngle(30.0f);
    tust.setLength(0.5f);
    tust.setLSystem(& test);
    tust.runTurtle();
    ASSERT_EQ(tust.getMessage(),"rotated to the right");
}
TEST(turtle, runTurtleRotateNeg)
{
    LSystems test;
    turtle tust;
    test.editAlphabet("-");
    test.addRule('-',"--");
    test.editAlphabet(test.applyRules());
    tust.setAngle(30.0f);
    tust.setLength(0.5f);
    tust.setLSystem(& test);
    tust.runTurtle();
    ASSERT_EQ(tust.getMessage(),"rotated to the left");
}
TEST(turtle, flipRotate)
{
    LSystems test;
    turtle tust;
    test.editAlphabet("|");
    test.addRule('|',"||");
    test.editAlphabet(test.applyRules());
    tust.setAngle(30.0f);
    tust.setLength(0.5f);
    tust.setLSystem(& test);
    tust.runTurtle();
    ASSERT_EQ(tust.getMessage(),"reverses the current rotation direction");
}
TEST(turtle, scaleLengthPos)
{
    LSystems test;
    turtle tust;
    test.editAlphabet(">");
    test.addRule('>',">>");
    test.editAlphabet(test.applyRules());
    tust.setAngle(30.0f);
    tust.setLength(0.5f);
    tust.setLSystem(& test);
    tust.runTurtle();
    ASSERT_EQ(tust.getMessage(),"Multiply the line length by scaler");
}
TEST(turtle, scaleLengthNeg)
{
    LSystems test;
    turtle tust;
    test.editAlphabet("<");
    test.addRule('<',"<<");
    test.editAlphabet(test.applyRules());
    tust.setAngle(30.0f);
    tust.setLength(0.5f);
    tust.setLSystem(& test);
    tust.runTurtle();
    ASSERT_EQ(tust.getMessage(),"Divide the line length by scaler");
}
TEST(turtle, runTurtlePush)
{
    LSystems test;
    turtle tust;
    test.editAlphabet("[");
    test.addRule('[',"[[");
    test.editAlphabet(test.applyRules());

    tust.setAngle(30.0f);
    tust.setLength(0.5f);
    tust.setLSystem(& test);
    tust.runTurtle();

    ASSERT_EQ(tust.getMessage(),"pushs current transforms");
}/*
TEST(turtle, runTurtlePop)
{
    LSystems test;
    turtle tust;

    test.editAlphabet("]");
    test.addRule(']',"]]");
    test.editAlphabet(test.applyRules());

    tust.setAngle(30.0f);
    tust.setLength(0.5f);
    tust.setLSystem(& test);
    tust.runTurtle();

    ASSERT_EQ(tust.getMessage(),"pops current transforms");
}*/
TEST(turtle, outOfLimitsSymbol)
{
    LSystems test;
    turtle tust;
    test.editAlphabet("F");
    test.addRule('F',"#");
    test.editAlphabet(test.applyRules());

    tust.setAngle(30.0f);
    tust.setLength(0.5f);
    tust.setLSystem(& test);
    tust.runTurtle();

    ASSERT_EQ(tust.getMessage(),"couldn't find character to match: #");
}


TEST(turtlesystem, construct)
{
    turtlesystem test;
    std::string name = test.getName();
    ASSERT_EQ(name,"basic_Tree");
}
TEST(turtlesystem, constructAndChoose)
{
    turtlesystem test;
    test.chooseTemplate(1);
    std::string name = test.getName();
    ASSERT_EQ(name,"Wavy Bush");
}


TEST(turtlesystem, MakeTree)
{
    turtlesystem test;
    test.chooseTemplate(1);
    test.makeTree();
    ASSERT_EQ(test.getName(),"Tree Made");
}
