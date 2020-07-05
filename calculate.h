#ifndef CALCULATE_H
#define CALCULATE_H

#include <QStack>
#include "enteredexception.h"

const double PI = 3.141592653589793;
enum symb {sum = 1, minus, mult,del, sin, cos, tg,
           arcsin, arccos, arctg, sqrt, pow, left, right};
class Calculate
{
public:
    Calculate(QString);
private:
    QString data;              //всё выражение
    QStack<double>  numbers;   //стек для чисел
    QStack<symb> symbols;      //стек для математических операторов
    QString parse();           //разделитель чисел и операторов
    QString resulting();
};

#endif // CALCULATE_H
