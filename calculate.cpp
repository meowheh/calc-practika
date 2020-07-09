#include "calculate.h"
#include <QDebug>

Calculate::Calculate(QString d, bool ang=1): data(d), angle(ang) {}

double Calculate::Resulting(){
        QString str = data;
        std::pair<QString,double> res;
        try{
            res = MathExpr(str);
        }catch(EnteredException &e){
            throw e;
        }
        if(res.first != ""){
            throw EnteredException("Произошла ошибка");
        }
        if(std::abs(res.second) < delta) res.second = 0;
        return res.second;
}

//Рассматриваем термы '+','-'
std::pair<QString,double> Calculate::MathExpr(QString str) {
    std::pair<QString,double> temp;
    try{
        temp = Term(str);
    }catch(EnteredException &e){
        throw e;
    }
    double tempDouble = temp.second;
    if(temp.first != ""){
        if(temp.first[0] == '+' || temp.first[0] == '-'){
           for(int i = 0; i < temp.first.length();++i){
               QChar symb =temp.first[0];
               QString next = temp.first.remove(0,1);
               temp = Term(next);
               if(symb == '+'){
                   tempDouble+= temp.second;
               }
               else{
                   tempDouble-=temp.second;
               }
           }
        }
    }
    return std::make_pair(temp.first,tempDouble);
}
//Рассматриваем термы '*', '/'
std::pair<QString,double> Calculate::Term(QString str){
    std::pair<QString,double> temp;
    try{
        temp = Factor(str);
    }catch(EnteredException &e){
        throw e;
    }
    double tempDouble = temp.second;
    while(temp.first != ""){
       QChar symb = temp.first[0];
        if(symb != '*' && symb != '/')
            return temp;
        QString next = temp.first.remove(0,1);
        std::pair<QString,double> right;
        try{
             right = Factor(next);
        }catch(EnteredException &e){
            throw e;
        }
        if(symb == '/' && right.second == 0) throw EnteredException("Деление на 0 запрещено!");
        tempDouble = (symb == '*') ? tempDouble*right.second:
                                     tempDouble/right.second;

        temp = std::make_pair(right.first,tempDouble);
     }
    return temp;
}
//Рассматриваем унарный минус в начале строки и '^'
std::pair<QString,double> Calculate::Factor(QString str){
    QChar firstChar = str[0];
    double tempDouble = 0;
    std::pair<QString,double> temp;
    std::pair<QString,double> res;
    if(firstChar == '-'){
      try{
       temp = Factor(str.remove(0,1));
        }catch(EnteredException &e){
            throw e;
        }
       tempDouble = -temp.second;
       res = std::make_pair(temp.first,tempDouble);
    }
    else{
        try{
         temp = Base(str);
         tempDouble = temp.second;
          res = std::make_pair(temp.first,temp.second);
            }catch(EnteredException &e){
            throw e;
            }
         if(temp.first != ""){
             if(temp.first[0]=='^'){
                 QString next = temp.first.remove(0,1);
                 std::pair<QString,double> right;
                 try{
                    right = Factor(next);}
                 catch(EnteredException &e){
                     throw e;
                 }
                 tempDouble = std::pow(tempDouble,right.second);
                 res = std::make_pair(right.first,tempDouble);
            }
         }
        else{
               res = std::make_pair(temp.first,temp.second);
            }
        }

    return res;
}
//Рассматриваем скобочные выражения
std::pair<QString,double> Calculate::Base(QString str){
    QChar firstChar = str[0];
    if(firstChar == '('){
        std::pair<QString,double> res;
        try{
             res = MathExpr(str.remove(0,1));
        }catch(EnteredException& e){
            throw e;
        }
        if(res.first != ""){
            if(res.first[0]==')'){
                res.first = res.first.remove(0,1);
            }
        }
       else{
                //throw EnteredException("Ошибка: не закрытая скобка");
           }
      return res;
    }
      return Function(str);
}

//Функции
std::pair<QString,double> Calculate::Function(QString str){
    QString fun;
    int i =0;
    for(i= 0; i < str.length() && (str[i].isLetter());++i){
        fun+= str[i];
    }
    if(fun != ""){
        if(str.length() > i && str[i] == '('){
            std::pair<QString,double> res;
            try{
                res = MathExpr(str.remove(0,fun.length()));
            }catch(EnteredException &e){
                throw e;
            }
            return FuncName(fun,res);
        }
    }
    return Number(str);
}

std::pair<QString,double> Calculate::FuncName(QString fun, std::pair<QString,double> res){
    double param = res.second;
    if (fun == "sqrt"){
        if(param < 0)
            throw EnteredException("Выражение под корнем должно быть положительным");
        return std::make_pair(res.first,sqrt(param));
       }
    if(fun == "sin"){
        if(!angle)
             param = res.second*PI/180;
        return std::make_pair(res.first,sin(param));
    }
    if (fun == "cos"){
        if(!angle)
            param = res.second*PI/180;
        return std::make_pair(res.first,cos(param));
    }
    if(fun == "tg"){
         if(!angle)
              param = res.second*PI/180;
         return std::make_pair(res.first,tan(param));
    }
    if(fun == "arctg"){
         double num = atan(param);
         if(!angle){
              num = num*180/PI;
         }
         return std::make_pair(res.first,num);
    }
    if(param >= -1 && param <= 1){
       double num;
       if(fun == "arcsin"){
            num = asin(param);
            if(!angle){
                  num = num*180/PI;
            }
            return std::make_pair(res.first,num);
            }
            if(fun == "arccos"){
                num = acos(param);
                if(!angle){
                    num = num*180/PI;}
                return std::make_pair(res.first,num);
            }
        }else throw EnteredException("Аргумент arcsin и arccos не может быть больше 1 по модулю");

    throw EnteredException("Не найдена функция: "+fun);
}

std::pair<QString,double> Calculate::Number(QString str){
    int i =0;
    int dotCount = 0;
    for(i = 0; i < str.length() && (str[i].isDigit() || str[i] == '.');++i){
        if(str[i] == '.' && ++dotCount >1){
            throw EnteredException("Неверные данные");
        }
    }
    if(i == 0){
        throw EnteredException("Неверные данные: "+str);
    }
    double dPart = str.mid(0,i).toDouble();
    QString restPart = str.remove(0,i);
    return std::make_pair(restPart,dPart);
}
