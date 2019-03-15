#include "lsystems.h"
#include "turtle.h"

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

TEST(LSystems,settingAngle)
{
    LSystems test;
    test.setAngle(40.0f);
   ASSERT_EQ(test.getAngle(),40.0f);
}

TEST(turtle, runTurtle)
{



}
