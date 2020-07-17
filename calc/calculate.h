#ifndef CALCULATE_H
#define CALCULATE_H

#include <cmath>
#include <QRegExp>
#include "enteredexception.h"


const double PI = 3.141592653589793;
const double delta = 0.000000000001;

/*Написано на основе метода рекрусивного спуска;
 *  БНФ:
 *  <MathExpr> ::= <Term> {<Operator1> <Term>}
 *   <Operator1> ::= '+' | '-'
 *   <Term> ::= <Factor> {<Operator2> <Factor>}
 *   <Operator2> ::= '*' | '/'
 *   <Factor> ::= '-' <Factor> | <Base> ['^' <Factor>]
 *   <Base> ::=  <Function> | <Number> | '(' <MathExpr> ')'
 *   <Function> ::= <FuncName> '(' <MathExpr> ')'
 *   <FuncName> ::= 'sin' | 'cos' | 'tg' | 'arcsin' | 'arccos' | 'arctg' | 'sqrt'
 *   <Digit> ::= '0' | ... | '9'
 *   <Number> ::= <Digit> {<Digit>} ['.' <Digit> {<Digit>}] */

class Calculate
{
public:
    Calculate(QString, bool);
    Calculate();
    double Resulting();                                                      //получение результата
    void SetData(QString,bool);                                              //Установить выражение
    static bool isSign(QChar);
    static QString deleteExtraNulls(QString num);

private:
    QString data;                                                            //всё выражение
    bool angle;                                                              //угол: 1 - радианы, 0 - градусы

    std::pair<QString,double> MathExpr(QString);                             //определяет '+' и '-'
    std::pair<QString,double> Term(QString);                                 //определяет '*' и '/'
    std::pair<QString,double> Factor(QString);                               //определяет '^ и унарный '-'
    std::pair<QString,double> Base(QString);                                 //разбор скобок
    std::pair<QString,double> Function(QString);                             //разбор функций
    std::pair<QString,double> FuncName(QString, std::pair<QString,double>);  //вычисление функций
    std::pair<QString,double> Number(QString str);                           //разбор чисел
};

#endif // CALCULATE_H
