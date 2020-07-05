#include "calculate.h"

Calculate::Calculate(QString d): data(d) {

}

QString Calculate::parse(){
    QString str;
    int count =0;
    int i, size;
    for(i =0, size = 0;i < data.length(); ++i){
        QChar temp = data.at(i);
        while((temp >= '0' && temp <= '9') || (temp == '.' && size)){
            if(temp == '.'){
                count++;
            }
            if(count > 1){
                throw EnteredException("Неверно введенный символ",i);
            }
            str= str + temp;
            size++;
            temp = data.at(i++);
        }
        count = 0;
        if(size > 0) {
            numbers.push(str.toDouble());
            size = 0;
            str.clear();
        }
        if (size == 0){
            if(temp == 'p'){
                if(data.at(i+1) == 'i'){
                    numbers.push(PI);
                    i++;
                }
                else{
                    throw EnteredException("Неверно введенный символ",i);
                }
            }
            if(temp == 's'){
                if(data.at(i+1) == 'i' && data.at(i+2) == 'n'){
                    if(symbols.top() <= sin){
                         symbols.push(sin);
                         i+=2;
                    }
                    else{

                    }
                }
                else if(data.at(i+1) == 'q' && data.at(i+2)=='r' && data.at(i+3) == 't'){
                    symbols.push(sqrt);
                    i+=3;
                }
                else{
                    throw EnteredException("Неверно введенный символ",i);
                }
            }
            if(temp == 'c'){
                if(data.at(i+1) == 'o' && data.at(i+2)=='s'){
                    symbols.push(cos);
                    i+=2;
                }
                else{
                     throw EnteredException("Неверно введенный символ",i);
                }
            }
            if(temp == 't'){
                if(data.at(i+1)=='g'){
                    symbols.push(tg);
                    i++;
                }
                else{
                     throw EnteredException("Неверно введенный символ",i);
                }
            }
            if(temp == 'a'){
                if(data.at(i+1)=='r' && data.at(i+2)=='c'){
                    if(data.at(i+3)=='s'&&data.at(i+4)=='i' &&data.at(i+5)=='n'){
                        symbols.push(arcsin);
                        i+=5;
                    }
                    else if (data.at(i+3)=='c'&&data.at(i+4)=='o' &&data.at(i+5)=='s'){
                        symbols.push(arccos);
                        i+=5;
                    }
                    else if(data.at(i+3)=='t'&&data.at(i+4)=='g'){
                        symbols.push(arctg);
                        i+=4;
                    }
                    else{
                        throw EnteredException("Неверно введенный символ",i);
                    }
                }
                else{
                    throw EnteredException("Неверно введенный символ",i);
                }
            }



            }
        }
    }



QString Calculate::resulting(){


}


