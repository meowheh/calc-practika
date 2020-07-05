#ifndef ENTEREDEXCEPTION_H
#define ENTEREDEXCEPTION_H

#include <utility>
#include <QString>
#include <exception>

class EnteredException: public std::exception{
private:
    QString textError;
    int num;
public:
    EnteredException(QString, int);
    std::pair<QString,int> what();
    virtual ~EnteredException() throw() {}
};

#endif // ENTEREDEXCEPTION_H
