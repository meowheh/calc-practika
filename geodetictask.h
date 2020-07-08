#ifndef GEODETICTASK_H
#define GEODETICTASK_H

#include <cmath>
#include "enteredexception.h"

const double pi = 3.141592653589793;
const double R = 39588;   //радиус Земли

class GeodeticTask
{
public:
    GeodeticTask(QString);

    QVector<double> CalcPGZ();
    QVector<double> CalcOGZ();

private:
    QString data;                                                            //всё выражение

    QVector <double> CheckAndRead(QString);
    QString CheckStr(QString);
    QVector <double> ReadStr(QString);

    QVector<double> SpherToCart(double, double);
    QVector<double>Rotate(QVector<double>, double, int);
    QVector<double>CartToSpher(QVector<double>);

    double RadiansToDegrees(double);
    double DegreesToRadians(double);
};

#endif // GEODETICTASK_H
