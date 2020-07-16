#ifndef GEODETICTASK_H
#define GEODETICTASK_H

#include <cmath>
#include "enteredexception.h"

const double pi = 3.141592653589793;
const double R = 39587.56;                                                      //радиус Земли

class GeodeticTask
{
public:
    GeodeticTask(QString);

    QVector<double> CalcPGZ();                                               //решение ПГЗ
    QVector<double> CalcOGZ();                                               //решение ОГЗ

private:
    QString data;                                                            //всё выражение

    QVector <double> CheckAndRead(QString);                                  //проверка на корректный ввод и чтение строки
    QString CheckStr(QString);                                               //проверка корректности введенного выражения
    QVector <double> ReadStr(QString);                                       //разбор введенных значений и проверка их корректночти

    double RadiansToDegrees(double);
    double DegreesToRadians(double);
};

#endif // GEODETICTASK_H
