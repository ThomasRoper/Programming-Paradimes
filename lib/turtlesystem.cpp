#include "turtlesystem.h"

turtlesystem::turtlesystem()
{
    name = "basic_Tree";
    length = 0.2f;
    angle = 30.0f;
    axiom = "F";
    version = 1;
    rules.push_back({'F',"FF+[+F-F-F]-[-F+F+F]"});
}

void turtlesystem::chooseTemplate(int _choice)
{
    for (int i = 0; i < rules.size(); i++)
    {
    rules.pop_back();
    }
    switch (_choice) {
    case 0:
        name = "Basic Tree";
        length = 0.05f;
        angle = 22.5f;
        version = 3;
        scaleFactor = 1.5;
        axiom = "F";
        rules.push_back({'F',"FF+[+F-F-F]-[-F+F+F]"});
        break;
    case 1:
        name = "Wavy Bush";
        length = 0.05f;
        angle = 20.0f;
        version = 6;
        scaleFactor = 1.5;
        axiom = "VZFFF";
        rules.push_back({'V',"[+++W][---W]YV"});
        rules.push_back({'W',"+X[-W]Z"});
        rules.push_back({'X',"-W[+X]Z"});
        rules.push_back({'Y',"YZ"});
        rules.push_back({'Z',"[-FFF][+FFF]F"});
        break;
    case 2:
        name = "Branch";
        length = 0.05f;
        angle = 20.0f;
        version = 4;
        scaleFactor = 1.5;
        axiom = "X";
        rules.push_back({'F',"FF"});
        rules.push_back({'X',"F[+X]F[-X]+X"});

        break;
    case 3:
        name = "Triangle";
        length = 0.1f;
        angle = 120.0f;
        version = 3;
        scaleFactor = 1.5;
        axiom = "F+F+F";
        rules.push_back({'F',"F-F+F"});
        break;
    case 4:
        name = "Square Sierpinski";
        length = 0.2f;
        angle = 90.0f;
        version = 4;
        scaleFactor = 1.5;
        axiom = "F+XF+F+XF";
        rules.push_back({'X',"XF-F+F-XF+F+XF-F+F-X"});
        break;
    case 5:
        name = "Square Sierpinski";
        length = 0.01f;
        angle = 60.0f;
        version = 6;
        scaleFactor = 1.5;
        axiom = "YF";
        rules.push_back({'X',"YF+XF+Y"});
        rules.push_back({'Y',"XF-YF-X"});
        break;
    case 6:
        name = "Von Koch Snowflake";
        length = 0.01f;
        angle = 60.0f;
        version = 4;
        scaleFactor = 1.5;
        axiom = "F++F++F";
        rules.push_back({'F',"F-F++F-F"});
        break;
    case 7:
        name = "Cross";
        length = 0.1f;
        angle = 90.0f;
        version = 3;
        scaleFactor = 1.5;
        axiom = "F+F+F+F";
        rules.push_back({'F',"F+FF++F+F"});
        break;
    case 8:
        name = "Pentaplexity";
        length = 0.05f;
        angle = 36.0f;
        version = 2;
        scaleFactor = 1.5;
        axiom = "F++F++F++F++F";
        rules.push_back({'F',"F++F++F|F-F++F"});
        break;
    case 9:
        name = "Dragon Curve";
        length = 0.05f;
        angle = 90.0f;
        version = 8;
        scaleFactor = 1.5;
        axiom = "FX";
        rules.push_back({'X',"X+YF+"});
        rules.push_back({'Y',"-FX-Y"});
        break;
    case 10:
        name = "Hexagonal Gosper";
        length = 0.1f;
        angle = 60.0f;
        version = 2;
        scaleFactor = 1.5;
        axiom = "XF";
        rules.push_back({'X',"X+YF++YF-FX--FXFX-YF+"});
        rules.push_back({'Y',"-FX+YFYF++YF+FX--FX-Y"});
        break;
    case 11:
        name = "Lévy curve";
        length = 0.02f;
        angle = 45.0f;
        version = 9;
        scaleFactor = 1.36;
        axiom = "F";
        rules.push_back({'F',"-F++F-"});

        break;

    case 12:
        name = "The hard scaler one";
        length = 0.7f;
        angle = 40.0f;
        version = 9;
        scaleFactor = 1.36;
        axiom = "FX";
        rules.push_back({'X',">[-FX]+FX"});
        break;

    case 13:
        name = "Leaf";
        length = 0.3f;
        angle = 45.0f;
        version = 5;
        scaleFactor = 1.36;
        axiom = "a";
        rules.push_back({'F',">F<"});
        rules.push_back({'a',"F[+x]Fb"});
        rules.push_back({'b',"F[-y]Fa"});
        rules.push_back({'x',"a"});
        rules.push_back({'y',"b"});
        break;


    case 14:
        name = "Simple Bush";
        length = 0.04f;
        angle = 25.7f;
        version = 4;
        axiom = "Y";
        rules.push_back({'X',"X[-FFF][+FFF]FX"});
        rules.push_back({'Y',"YFX[+Y][-Y]"});
        break;
    case 15:
        name = "Algae";
        length = 0.02f;
        angle = 12.0f;
        version = 7;
        axiom = "aF";
        rules.push_back({'a',"FFFFFv[+++h][---q]fb"});
        rules.push_back({'b',"FFFFFv[+++h][---q]fc"});
        rules.push_back({'c',"FFFFFv[+++fa]fd"});
        rules.push_back({'d',"FFFFFv[+++h][---q]fe"});
        rules.push_back({'e',"FFFFFv[+++h][---q]fg"});
        rules.push_back({'g',"FFFFFv[---fa]fa"});
        rules.push_back({'h',"ifFF"});
        rules.push_back({'i',"fFFF[--m]j"});
        rules.push_back({'j',"fFFF[--n]k"});
        rules.push_back({'k',"fFFF[--o]l"});
        rules.push_back({'l',"fFFF[--p]"});
        rules.push_back({'m',"fFn"});
        rules.push_back({'n',"fFo"});
        rules.push_back({'o',"fFp"});
        rules.push_back({'p',"fF"});
        rules.push_back({'q',"rfF"});
        rules.push_back({'r',"fFFF[++m]s"});
        rules.push_back({'s',"fFFF[++n]t"});
        rules.push_back({'t',"fFFF[++o]u"});
        rules.push_back({'u',"fFFF[++p]"});
        rules.push_back({'v',"Fv"});
        break;
    case 16:
        name = "Kolam";
        length = 0.1f;
        angle = 45.0f;
        version = 5;
        axiom = "-D--D";
        rules.push_back({'A',"F++FFFF--F--FFFF++F++FFFF--F"});
        rules.push_back({'B',"F--FFFF++F++FFFF--F--FFFF++F"});
        rules.push_back({'C',"BFA--BFA"});
        rules.push_back({'D',"CFC--CFC"});
        break;
    case 17:
        name = "Mango Leaf";
        length = 0.1f;
        angle = 60.0f;
        version = 8;
        axiom = "Y---Y";
        rules.push_back({'X',"{F-F}{F-F}--[--X]{F-F}{F-F}--{F-F}{F-F}--"});
        rules.push_back({'Y',"f-F+X+F-fY"});
        break;
    }

}

void turtlesystem::makeTree()
{

    m_Tree.editAlphabet(axiom);
    for (int i = 0; i < rules.size(); i++)
    {
        m_Tree.addRule(rules[i].first,rules[i].second);
    }
      m_Turtle.setLSystem(& m_Tree);
    m_Turtle.setAngle(angle);
    m_Turtle.setLength(length);


    m_Tree.generateTreeVesions(version+1);
    m_Tree.editAlphabet(m_Tree.getTreeVersion(version));


    m_Turtle.setLength(length);

    m_Turtle.setScaleFactor(scaleFactor);
    std::cout<<"Trees name is: " + name + "\n";
    std::cout<<"With Axiom: " + axiom + "\n";
    m_Tree.printRules();
    std::cout<<"Turtle is following this code:\n" +m_Tree.getAlphabet() + "\n\n";
    name = "Tree Made";
}


void turtlesystem::drawTree()
{
m_Turtle.setLength(length);
m_Turtle.runTurtle();
}

std::string turtlesystem::getName()
{
    return name;
}
