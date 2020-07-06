#include "enteredexception.h"

EnteredException::EnteredException(QString er): err(er){}

QString EnteredException::what(){
    return err;
}

