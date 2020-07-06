#ifndef ENTEREDEXCEPTION_H
#define ENTEREDEXCEPTION_H

#include <utility>
#include <QString>
#include <exception>

class EnteredException: public std::exception{
private:
    QString err;
public:
    EnteredException(QString );
    QString what();
    virtual ~EnteredException() throw() {}
};

#endif // ENTEREDEXCEPTION_H
