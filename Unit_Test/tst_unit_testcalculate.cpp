#include <QString>
#include <QtTest>

#include "../calc/calculate.h"

//Q_DECLARE_METATYPE(MathExpr)

class Unit_TestCalc : public QObject
{
    Q_OBJECT

public:
//    Unit_TestCalc(double);
    Unit_TestCalc(QObject *parent=0);
//    void SetResult(double);

//    double result;

private Q_SLOTS:

    void MathExpr();
    void Term();
    void Factor();
    void Base();
    void Func();

//    void MathExpr_data();
    void Test1();
};

//Unit_TestCalc::Unit_TestCalc(double res): result(res) {}

Unit_TestCalc::Unit_TestCalc(QObject *parent): QObject(parent){}

void Unit_TestCalc::Test1()
{
    QVERIFY2(true, "Yes");
}

//void Unit_TestCalc::Base_data() {

//    QTest::addColumn<QString>("data");
//    QTest::addColumn<double>("res");

//    QTest::newRow("(20*3)+(35+5)^3") << QString("(20*3)+(35+5)^3") << double(64060.0);

//
//}

void Unit_TestCalc::MathExpr()
{    
     Calculate o;

     o.SetData("1+1",1);
     QCOMPARE(o.Resulting(),2.0);

     o.SetData("1-1",1);
     QCOMPARE(o.Resulting(),0.0);

     o.SetData("(1-5",1);
     QCOMPARE(o.Resulting(),-4.0);

     o.SetData("5-1",1);
     QCOMPARE(o.Resulting(),4.0);

     o.SetData("1+1-3+0+5-6",1);
     QCOMPARE(o.Resulting(),-2.0);

}

void Unit_TestCalc::Term()
{
     Calculate o;

     o.SetData("2*8",1);
     QCOMPARE(o.Resulting(),16.0);

     o.SetData("3/3",1);
     QCOMPARE(o.Resulting(),1.0);

     o.SetData("5*1",1);
     QCOMPARE(o.Resulting(),5.0);

     o.SetData("10/1",1);
     QCOMPARE(o.Resulting(),10.0);

     o.SetData("0/5",1);
     QCOMPARE(o.Resulting(),0.0);

     o.SetData("0*5",1);
     QCOMPARE(o.Resulting(),0.0);

     o.SetData("10*3/2/5*(-2)",1);
     QCOMPARE(o.Resulting(),-6.0);

}

void Unit_TestCalc::Factor()
{
     Calculate o;

     o.SetData("10^0",1);
     QCOMPARE(o.Resulting(),1.0);

     o.SetData("2^3",1);
     QCOMPARE(o.Resulting(),8.0);

     o.SetData("-3/1",1);
     QCOMPARE(o.Resulting(),-3.0);

}

void Unit_TestCalc::Base()
{
     Calculate o;

//     double res = result;

//     o.SetData(data,1);
//     QCOMPARE(o.Resulting(),res);

     o.SetData("(20+3)+(156-88)",1);
     QCOMPARE(o.Resulting(),91.0);

     o.SetData("(-1568-596+87)-(-5)",1);
     QCOMPARE(o.Resulting(),-2072.0);

     o.SetData("(2+3)*(10-2)",1);
     QCOMPARE(o.Resulting(),40.0);

     o.SetData("(10*5)/(10-8)",1);
     QCOMPARE(o.Resulting(),25.0);
}

void Unit_TestCalc::Func()
{
//     Calculate o;



}


QTEST_APPLESS_MAIN(Unit_TestCalc)

#include "tst_unit_calculate.moc"
