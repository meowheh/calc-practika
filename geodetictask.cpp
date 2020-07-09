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

        double x1 = DegreesToRadians(values[0]);
        double y1 = DegreesToRadians(values[1]);
        double x2 = DegreesToRadians(values[2]);
        double y2 = DegreesToRadians(values[3]);

        double s, w, a, d;

        w = y2 - y1;
        double c = sin(x1) * sin(x2) + cos(x1) * cos(x2) * cos(w);
        s = acos(c);

        if (c < 0)
            d = (s > 0)? R * (pi - s) : R * (pi + s);
        else
            d = R * s;

        a = atan2(cos(x2) * sin(w), cos(x1) * sin(x2) - sin(x1) * cos(x2) * cos(w));

        res.append(d);
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


