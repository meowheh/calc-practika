#include "enteredexception.h"

EnteredException::EnteredException(QString err, int pos): textError(err), num(pos) {}

std::pair<QString, int> EnteredException::what(){
    return std::make_pair(textError,num);
}

