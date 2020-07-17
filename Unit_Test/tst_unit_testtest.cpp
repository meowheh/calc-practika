#include <QString>
#include <QtTest>

#include "../calc/calculate.h"

//Q_DECLARE_METATYPE(MathExpr)

class Unit_TestTest : public QObject
{
    Q_OBJECT

public:
    Unit_TestTest();

private Q_SLOTS:
    void plus();
    void plus_data();
    void Test1();
};

Unit_TestTest::Unit_TestTest()
{
}


void Unit_TestTest::Test1()
{
    QVERIFY2(true, "Yes");
}


void Unit_TestTest::plus_data() {
//    QTest::addColumn<bool>("b");
//    QTest::addColumn<QString>("a");
//    QTest::addColumn<double>("result");

//    QTest::newRow("0+5") << bool(1) << QTest::newRow("0 ") << QString(5) << double(5);

}

void Unit_TestTest::plus()
{
//    QFETCH(QString, a);
//    QFETCH(bool, b);
//    QFETCH(double, result);

//    QCOMPARE(MathExpr(b), result);
}

QTEST_APPLESS_MAIN(Unit_TestTest)

#include "tst_unit_testtest.moc"
