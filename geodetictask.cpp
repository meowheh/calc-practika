#include <QDebug>
#include "geodetictask.h"
#include <QStringList>

GeodeticTask::GeodeticTask(QString d): data (d) {}

QVector<double> GeodeticTask::CalcPGZ(){
    QString str = data;
    QVector<double> res;

    QVector<double> values = CheckAndRead(str);

        double x1 = DegreesToRadians(values[0]);
        double y1 = DegreesToRadians(values[1]);
        double d = values[2];
        double a = DegreesToRadians(values[3]);

        /*double Dx = cos(a) * d;
        double Dy = sin(a) * d;

        double x2 = x1 + Dx;
        double y2 = y1 + Dy;*/

        double s = d / R;
        double x2 = asin(sin(x1) * cos(s) + cos(x1) * sin(s) * cos(a));

        double diff = atan2(sin(s) * sin(a), cos(s) * cos(x1 - sin(s) * sin(x1) * cos(a)));
        double y2 = diff + y1;

        res.append(RadiansToDegrees(x2));
        res.append(RadiansToDegrees(y2));

    return res;
}

QVector<double> GeodeticTask::CalcOGZ(){
    QString str = data;
    QVector<double> res;

    QVector<double> values = CheckAndRead(str);
    //QVector<double> coord;

   /* for (int i = 0; i < values.size(); ++i){
        values[i] = DegreesToRadians(values[i]);
    }

    QVector<double> dec = SpherToCart(values[2], values[3]);
    QVector<double> rot1 = Rotate(dec, values[1], 2);
    QVector<double> rot2 = Rotate(rot1, pi/2 - values[0], 1);
    QVector<double> sph = CartToSpher(rot2);

    double azi = pi - sph[1];
    double dist = pi / 2 - sph[0];

    res.append(dist * R);
    res.append(RadiansToDegrees(azi));*/


        double x1 = DegreesToRadians(values[0]);
        double y1 = DegreesToRadians(values[1]);
        double x2 = DegreesToRadians(values[2]);
        double y2 = DegreesToRadians(values[3]);

        /*double Dx = x2 - x1;
        double Dy = y2 - y1;

        double delta;
        if (Dx != 0)
            delta = Dy/Dx;
        else
            delta = 0;

        double a = RadiansToDegrees(atan(delta));
        double d = sqrt(pow(Dx, 2) + pow(Dy,2));


        if (Dx > 0 && Dy < 0)
            a = 360 - a;
        if (Dx < 0 && Dy > 0)
            a = 180 - a;
        if (Dx < 0 && Dy < 0)
            a = 180 + a;
        if (Dx == 0 && Dy > 0)
            a = 0;
        if (Dx == 0 && Dy < 0)
            a = 180;
        if (Dx < 0 && Dy == 0)
            a = 270;
        if (Dx > 0 && Dy == 0)
            a = 90;*/

        double s, w, a, d;

        w = y2 - y1;
        double c = sin(x1) * sin(x2) + cos(x1) * cos(x2) * cos(w);
        s = acos(c);

        if (c < 0)
            d = (s > 0)? R * (pi - s) : R * (pi + s);
        else
            d = R * s;

        a = atan2(cos(x2) * sin(w), (cos(x1) * sin(x2) - sin(x1) * cos(x2) * cos(w)));

        res.append(d);
        //res.append(a);
        res.append(RadiansToDegrees(a));

    return res;
}

QVector<double> GeodeticTask::CheckAndRead(QString str){
    QVector <double> values;
    QString error;
    try{
        error = CheckStr(str);
    } catch (EnteredException &e){
            throw e;
    }
    if (error != "")
        throw EnteredException(error);
    else{
        values = ReadStr(str);
    }
    return values;
}

QString GeodeticTask::CheckStr(QString str){
    if (str.indexOf("П") != 0 && str.indexOf("О") != 0)
        return "Неверный формат строки!";
    if (str.indexOf(")") != str.size()-1)
        return "Неверный формат строки!";
    return "";
}

QVector<double> GeodeticTask::ReadStr(QString str){
    str.remove(0, 4);
    str.remove(str.size()-1, 1);
    QStringList s;
    s = str.split(QLatin1Char(';'));
    QVector<double> read;
    for (int i = 0; i < s.size(); ++i){
        bool ok = true;
        read.append(s[i].toDouble(&ok));
        if (!ok) {
            throw EnteredException("Пропущено значение!");
        }
    }
    if (read.size() < 4)
        throw EnteredException("Пропущено значение!");

    return read;
}

double GeodeticTask::DegreesToRadians(double val){
    return val * pi /180;
}

double GeodeticTask::RadiansToDegrees(double val){
    return val * 180 / pi;
}

QVector<double> GeodeticTask::SpherToCart(double x, double y){
    QVector<double> res;
    res.append(cos(x)*cos(y));
    res.append(cos(x)*sin(y));
    res.append(sin(x));

    return res;
}

QVector<double> GeodeticTask::Rotate(QVector<double> x, double a, int i){
    int j,k;
    double c, s, xj;
    QVector<double> res;

    j = (i + 1) % 3;
    k = (i - 1) % 3;

    c = cos(a);
    s = sin(a);
    xj = x[j] * c + x[k] * s;
    x[k] = x[k] * c - x[j] * s;
    x[j] = xj;

    res.append(x[0]);
    res.append(x[1]);
    res.append(x[2]);

    return res;
}

QVector<double> GeodeticTask::CartToSpher(QVector<double> x){
    QVector<double> res;
    double y1, y2, h;

    if (x[0] != 0)
        y1 = atan2(x[1], x[0]);
    else
        y1 = pi / 2;

    h = sqrt(pow(x[0], 2) + pow(x[1],2));

    if (h != 0)
        y2 = atan2(x[2], h);
    else
        y2 = pi / 2;

    res.append(y1);
    res.append(y2);

    return res;
}
