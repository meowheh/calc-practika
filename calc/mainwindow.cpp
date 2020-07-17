#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setWindowIcon(QIcon(":/img/img/icon.png"));
    ui->setupUi(this);
    init();

}
MainWindow::~MainWindow()
{
    delete ui;
}

//слот на сигнал нажатия цифры
void MainWindow::digitClicked(){
   QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    ui->lineEdit->setStyleSheet("border: 1px solid blue");
    int digitValue = clickedButton->text().toInt();
    if (ui->lineEdit->text() == "0" && digitValue == 0.0)
          return;
    if(ui->lineEdit->text() == "0")
        ui->lineEdit->clear();
    QString text = ui->lineEdit->text();
    int position = ui->lineEdit->cursorPosition();
    bool agree = false;
    if (position == 0)
        agree = true;
    else{
        if(text[position-1] != ')')
            agree = true;
    }
    if(agree == true){
        text.insert(position,QString::number(digitValue));
        ui->lineEdit->setText(text);
        ui->lineEdit->setCursorPosition(position+1);
    }
    else{
        ui->statusBar->showMessage(tr("Ввод числа невозможен"));
        ui->lineEdit->setStyleSheet("border: 1px solid red");
    }
}

//слот на сигнал нажатия точки
void MainWindow::on_point_clicked()
{
    ui->lineEdit->setStyleSheet("border: 1px solid blue");
    QString text = ui->lineEdit->text();
    int position = ui->lineEdit->cursorPosition();
    if (text[position - 1].isDigit()) {
        int temp_pos = position - 1;
        while (text[temp_pos].isDigit() && temp_pos > 0)
            temp_pos = temp_pos - 1;
        if (text[temp_pos] != '.') {
            text.insert(position, ".");
            ui->lineEdit->setText(text);
            ui->lineEdit->setCursorPosition(position + 1);
        }
        else{
             ui->lineEdit->setStyleSheet("border: 1px solid red");
        }
    }
}

//слот на сигнал нажатия смены знака
void MainWindow::on_sign_clicked()
{
    ui->lineEdit->setStyleSheet("border: 1px solid blue");
    QString text = ui->lineEdit->text();
    if(!text.contains(':')){
        double value = text.toDouble();
            if (value > 0.0) {
              text.prepend(tr("-"));
             } else if (value < 0.0) {
                 text.remove(0, 1);
            }
             else if(value == 0){
                if(text.at(0)== '-' && text.at(1)=='(') {
                     text.remove(0,2);
                     text.remove(text.size()-1,1);
                 }
                else{
                   text.prepend("-(");
                  text.append(")");
                 }
            }
             ui->lineEdit->setText(text);
     }
    else{
        ui->statusBar->showMessage(tr("Недопустимая операция"));
        ui->lineEdit->setStyleSheet("border: 1px solid red");
    }

}

//слот на сигнал Backspace
void MainWindow::on_backspace_clicked()
{
    QString text = ui->lineEdit->text();
    ui->lineEdit->setStyleSheet("border: 1px solid blue");
    if (text != "0") {
        int position = ui->lineEdit->cursorPosition();
        if (position > 0 && text[position-1] != ';'){
            if (text[position - 1] == '(' && text[position] == ')')
                text.remove(position, 1);
            text.remove(position - 1, 1);
            if (text.isEmpty()) {
                text = "0";
                ui->lineEdit->setCursorPosition(0);
            }
            else{
                if (position > 1)
                    position = position - 1;
                ui->lineEdit->setCursorPosition(position);
            }
            ui->lineEdit->setText(text);
            while (text[position - 1].isLetter() && position > 0) {
                text.remove(position - 1, 1);
                if (text.isEmpty()) {
                    text = "0";
                    ui->lineEdit->setCursorPosition(0);
                }
                else{
                    position = position - 1;
                    ui->lineEdit->setCursorPosition(position);
                }
                ui->lineEdit->setText(text);
            }
            while (text[position].isLetter()) {
                text.remove(position, 1);
                if (text.isEmpty()) {
                    text = "0";
                    ui->lineEdit->setCursorPosition(0);
                }
                ui->lineEdit->setText(text);
            }
        }
    }
}

//слот на сигналы возведения в степень и корня
void MainWindow::powOperatorClicked()
 {
    if(ui->lineEdit->text() == "0")
        ui->lineEdit->clear();
    ui->lineEdit->setStyleSheet("border: 1px solid blue");
    std::pair<QString,int> result;
    QObject* button = QObject::sender();
    QString toolTipText;
    result.first = ui->lineEdit->text();
    result.second = 0;
    int position = ui->lineEdit->cursorPosition();
    if(button == ui->sqr){

       result = powText(position,result.first,"^2");
       if(result.second)
            toolTipText = tr("( <выражение> )^2");

    }
    else if(button == ui->pow){
        result = powText(position, result.first,"^");
        if(result.second)
             toolTipText = tr("( <выражение> )^( <выражение> )");

   }else if (button == ui->sqrt){
           result = sqrtFractText(position, result.first, "sqrt()");
          if(result.second)
               toolTipText = tr("sqrt( <выражение> )");

   }
  else if(button == ui->fraction){
        result = sqrtFractText(position,result.first, "1/()");
        if(result.second)
            toolTipText = tr("1 / ( <выражение> )");

    }
   if(result.second){
     ui->lineEdit->setText(result.first);
     ui->lineEdit->setCursorPosition(position+result.second);
     QToolTip::showText(mapToGlobal(ui->lineEdit->pos()-QPoint(0,25)),toolTipText);
   }

}

//слоты операций +,-,*,/ константы pi
void MainWindow::simpleOperatorClicked(){
    int add = 0;
    ui->lineEdit->setStyleSheet("border: 1px solid blue");
    QObject* button = QObject::sender();
    if(ui->lineEdit->text() == "0")
        ui->lineEdit->clear();
    int position = ui->lineEdit->cursorPosition();
    QString res = ui->lineEdit->text();
    bool agree = false;
    if(button == ui->pi){
        if(position == 0){
           agree = true;
        }
        else{
            if(Calculate::isSign(res[position-1]) || res[position-1]=='^' || res[position-1]=='(')
                agree = true;
        }
        if (agree == true){
            QString pi = QString::number(PI,'f',10);
            pi = Calculate::deleteExtraNulls(pi);
            res.insert(position,pi);
            add = pi.length();
        }
        else{
            ui->statusBar->showMessage(tr("Ввод числа невозможен"));
            ui->lineEdit->setStyleSheet("border: 1px solid red");
        }
    }
    else{
        if(position != 0){
            if(!Calculate::isSign(res[position-1]) && res[position-1]!='^'){
                if(button == ui->plus &&  res[position-1]!='('){
                  res.insert(position,"+");
                 add = 1;
                 }
                else if(button == ui->minus){ //Допустим ввод (-<выражение>)
                  res.insert(position,"-");
                  add = 1;
                 }
                 else if(button == ui->mult && res[position-1]!='('){
                  res.insert(position,"*");
                  add = 1;
                 }
                else if(button == ui->division && res[position-1]!='('){
                  res.insert(position,"/");
                  add = 1;
                 }
            }
         }
        else if(position == 0 || res == "0"){
            if(button == ui->minus){
                if(res == "0"){
                    ui->lineEdit->clear();
                    position = ui->lineEdit->cursorPosition();
                    res = ui->lineEdit->text();
                }
                res.insert(position,'-');
                add = 1;
            }
        }
        if(!add){
             ui->statusBar->showMessage(tr("Оператор ставится между числами или скобками"));
             ui->lineEdit->setStyleSheet("border: 1px solid red");
            }
    }
    ui->lineEdit->setText(res);
    ui->lineEdit->setCursorPosition(position+add);
}

//слот на скобки
void MainWindow::bracketOperatorClicked(){
    int add = 0;
    ui->lineEdit->setStyleSheet("border: 1px solid blue");
    QObject* button = QObject::sender();
    int position = ui->lineEdit->cursorPosition();
    QString res = ui->lineEdit->text();

    if(button == ui->left_bracket){
        if(position){
            if(Calculate::isSign(res[position - 1]) || res[position-1] == '(' || res[position-1] == '^' || res == "0"){
                if(res == "0"){
                    res.clear();
                    position = 0;
                }
                res.insert(position,"(");
                add = 1;
                res.append(")");
            }
            else{
                ui->statusBar->showMessage(tr("Добавьте оператор или '('"));
                ui->lineEdit->setStyleSheet("border: 1px solid red");
            }
        }
        else{
            res.insert(position,"(");
            add = 1;
            res.append(")");
        }

    }
    else if(button == ui->right_bracket){
        if(res != "0" && position){
            if (res[position-1].isDigit() || res[position-1] == '(' || res[position-1]== ')')
                res.insert(position,")");
            else{
                ui->statusBar->showMessage(tr("Добавьте число или '('"));
                ui->lineEdit->setStyleSheet("border: 1px solid red");
            }
        }else{
            ui->statusBar->showMessage(tr("Вначале должна быть открывающая скобка"));
            ui->lineEdit->setStyleSheet("border: 1px solid red");
        }
    }
    ui->lineEdit->setText(res);
    ui->lineEdit->setCursorPosition(position+add);
}

//слот для тригометрических функций
void MainWindow::trigonometricOperatorClicked(){
   int add = 0;
   QPushButton *button = qobject_cast<QPushButton *>(sender());
   QString text = button->text();
   if(ui->lineEdit->text() == "0"){
        ui->lineEdit->clear();
   }
   int position = ui->lineEdit->cursorPosition();
   QString res = ui->lineEdit->text();
   if(position == 0){
       res.insert(position,text.append("()"));
       add = text.size()-1;
   }
   else if(Calculate::isSign(res[position-1])|| res[position-1] == '('){
       res.insert(position,text.append("()"));
       add = text.size()-1;
   }
   if(add){
       ui->lineEdit->setText(res);
       ui->lineEdit->setCursorPosition(position+add);
       QToolTip::showText(mapToGlobal(ui->lineEdit->pos()-QPoint(0,25)),button->text() + tr("( <выражение> )"));
   }
   else{
       ui->statusBar->showMessage(tr("Добавьте операторы перед началом и в конце функции"));
       ui->lineEdit->setStyleSheet("border: 1px solid red");
   }
}

//слот на очистку данных
void MainWindow::on_AC_clicked()
{
    ui->lineEdit->setStyleSheet("border: 1px solid blue");
     ui->lineEdit->setText("0");
}

//слот для клавиш MS, MR, MC, M+
void MainWindow::memoryOperatorClicked(){
    ui->lineEdit->setStyleSheet("border: 1px solid blue");
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (button == ui->MS)
    {
        double temp =(ui->lineEdit->text()).toDouble();
        if(temp != 0.0){
            sumInMemory = temp;
            ui->statusBar->showMessage(tr("Значение ")+QString::number(sumInMemory)+tr(" было успешно записано"));
        }
        else{
            ui->statusBar->showMessage(tr("Вы ввели ноль или не вычислили результат выражения"));
            ui->lineEdit->setStyleSheet("border: 1px solid red");
        }
    }
    else if(button == ui->MR){
            ui->lineEdit->setText(QString::number(sumInMemory));
            ui->statusBar->showMessage(tr("Значение в памяти: ")+ QString::number(sumInMemory));
    }
    else if(button == ui->MC){
        sumInMemory = 0;
        ui->statusBar->showMessage(tr("Значение в памяти успешно обнулено"));
    }
    else if(button == ui->memory_plus){
        double temp = (ui->lineEdit->text().toDouble());
        if(temp!=0){
            sumInMemory +=temp;
            ui->statusBar->showMessage(tr("Значение успешно вычислено, чтобы его посмотреть нажмите MR"));
        }
        else{
           ui->statusBar->showMessage(tr("Вы ввели ноль или не вычислили результат выражения"));
           ui->lineEdit->setStyleSheet("border: 1px solid red");
        }
    }
}

//слот кнопки вычисления
void MainWindow::on_result_clicked()
{
    if(ui->lineEdit->text().toDouble() == 0 && ui->lineEdit->text() != "0"){
        ui->lineEdit->setStyleSheet("border: 1px solid blue");
        QString text = ui->lineEdit->text();
        if (!text.contains('=')){
            Calculate calc(text,ui->radian->isChecked());
            GeodeticTask GT (text);
            double res;
            QVector <double> res_z;
            try{
                if (text.contains("ПГЗ")){
                    res_z = GT.CalcPGZ();
                    QString num1 = QString::number(res_z[0],'f',10);
                    QString num2 = QString::number(res_z[1],'f',10);
                    num1 = Calculate::deleteExtraNulls(num1);
                    num2 = Calculate::deleteExtraNulls(num2);
                    ui->lineEdit->setText("X2=");
                    ui->lineEdit->insert(num1);
                    ui->lineEdit->insert("; Y2=");
                    ui->lineEdit->insert(num2);
                    ui->statusBar->showMessage(tr("Результат успешно вычислен: X2,Y2 - координаты (deg)"));
                    QString saving = text +": X2= "+ num1 + "; Y2= " + num2;
                    ui->history->addItem(saving);
                }
                else{
                    if (text.contains("ОГЗ")){
                        res_z = GT.CalcOGZ();
                        QString num1 = QString::number(res_z[0],'f',10);
                        QString num2 = QString::number(res_z[1],'f',10);
                        num1 = Calculate::deleteExtraNulls(num1);
                        num2 = Calculate::deleteExtraNulls(num2);
                        ui->lineEdit->setText("d=");
                        ui->lineEdit->insert(num1);
                        ui->lineEdit->insert("; a=");
                        ui->lineEdit->insert(num2);
                        ui->statusBar->showMessage(tr("Результат успешно вычислен: d-рассторяние(kbt), a-азимут(deg)"));
                        QString saving = text +": d= "+ num1 + "; a= " + num2;
                        ui->history->addItem(saving);
                    }
                    else{
                        res = calc.Resulting();
                        QString num = QString::number(res,'f',10);
                        num = Calculate::deleteExtraNulls(num);
                        ui->lineEdit->setText(num);
                        ui->statusBar->showMessage(tr("Результат успешно вычислен"));
                        QString saving = text +" = "+ num;
                        ui->history->addItem(saving);
                    }
                }
            } catch(EnteredException &e){
                ui->statusBar->showMessage(e.what());
                ui->lineEdit->setStyleSheet("border: 1px solid red");
            }
         }
        else{
            QChar splitter = '=';
            if(text.contains(':')) splitter = ':';
             text = text.right(text.length() - text.indexOf(splitter) - 2);
             ui->lineEdit->setText(text);
        }
    }
    else{
        ui->statusBar->showMessage(tr("Введите выражение"));
        ui->lineEdit->setStyleSheet("border: 1px solid red");
    }
}

//слот выбора строки из списка прошлых операций
void MainWindow::on_history_activated(const QString &arg1)
{
    if(arg1 != "История вычислений")
        ui->lineEdit->setText(arg1);
}
//слот на нажатие кнопки ПГЗ
void MainWindow::on_pgzButton_clicked()
{
    if(ui->lineEdit->text() == "0" || ui->lineEdit->text() == ""){
        ui->lineEdit->setStyleSheet("border: 1px solid blue");
        ui->lineEdit->clear();
        int currentPosition = ui->lineEdit->cursorPosition();
        ui->lineEdit->setText(tr("ПГЗ( ; ; ; )"));
        ui->statusBar->showMessage(tr("ПГЗ(X1; Y1; d; a): X1,Y1 - координаты (deg); d - расстояние (kbt); a - азимут (deg)"));
        QToolTip::showText(mapToGlobal(ui->lineEdit->pos()-QPoint(0,25)), tr("ПГЗ(X1; Y1; d; a): X1,Y1 - координаты (deg); d - расстояние (kbt); a - азимут (deg)"));
        ui->lineEdit->setCursorPosition(currentPosition+4);
    }
    else{
        ui->statusBar->showMessage(tr("Очистите строку вывода"));
        ui->lineEdit->setStyleSheet("border: 1px solid red");
    }
}
//слот на нажатие кнопки ОГЗ
void MainWindow::on_ogzButton_clicked()
{
    if(ui->lineEdit->text() == "0" || ui->lineEdit->text() == ""){
        ui->lineEdit->setStyleSheet("border: 1px solid blue");
        ui->lineEdit->clear();
        int currentPosition = ui->lineEdit->cursorPosition();
        ui->lineEdit->setText(tr("ОГЗ( ; ; ; )"));
        ui->statusBar->showMessage(tr("ОГЗ(X1; Y1; X2; Y2): X1, Y1, X2, Y2 - координаты (deg)"));
        QToolTip::showText(mapToGlobal(ui->lineEdit->pos()-QPoint(0,25)), tr("ОГЗ(X1; Y1; X2; Y2): X1, Y1, X2, Y2 - координаты (deg)"));
        ui->lineEdit->setCursorPosition(currentPosition+4);
    }
    else{
        ui->statusBar->showMessage(tr("Очистите строку вывода"));
        ui->lineEdit->setStyleSheet("border: 1px solid red");
    }
}
//назначение названий нестандартных кнопок и подключение сигналов к слотам
void MainWindow::init(){

    sumInMemory = 0.0;

    ui->history->addItem("История вычислений");

    ui->sqr->setText("x"+QString(0x00B2));
    ui->pow->setText("x"+QString(0x207F));
    ui->sqrt->setText(QString(0x221A));
    ui->sign->setText(QString(0x00B1));
    ui->pi->setText(QString(0x03C0));
    ui->division->setText(QString(0x00F7));

    connect(ui->zero, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(ui->one, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(ui->two, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(ui->three, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(ui->four, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(ui->five, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(ui->six, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(ui->seven, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(ui->eight, SIGNAL(clicked()), this, SLOT(digitClicked()));
    connect(ui->nine, SIGNAL(clicked()), this, SLOT(digitClicked()));

    connect(ui->left_bracket,SIGNAL(clicked()),this,SLOT(bracketOperatorClicked()));
    connect(ui->right_bracket,SIGNAL(clicked()),this,SLOT(bracketOperatorClicked()));

    connect(ui->sqr,SIGNAL(clicked()),this,SLOT(powOperatorClicked()));
    connect(ui->pow, SIGNAL(clicked()),this,SLOT(powOperatorClicked()));
    connect(ui->sqrt,SIGNAL(clicked()),this,SLOT(powOperatorClicked()));
    connect(ui->fraction,SIGNAL(clicked()),this,SLOT(powOperatorClicked()));

    connect(ui->pi,SIGNAL(clicked()),this,SLOT(simpleOperatorClicked()));
    connect(ui->plus,SIGNAL(clicked()),this,SLOT(simpleOperatorClicked()));
    connect(ui->minus,SIGNAL(clicked()),this,SLOT(simpleOperatorClicked()));
    connect(ui->mult,SIGNAL(clicked()),this,SLOT(simpleOperatorClicked()));
    connect(ui->division,SIGNAL(clicked()),this,SLOT(simpleOperatorClicked()));

    connect(ui->sin,SIGNAL(clicked()),this,SLOT(trigonometricOperatorClicked()));
    connect(ui->cos,SIGNAL(clicked()),this,SLOT(trigonometricOperatorClicked()));
    connect(ui->tg,SIGNAL(clicked()),this,SLOT(trigonometricOperatorClicked()));
    connect(ui->arcsin,SIGNAL(clicked()),this,SLOT(trigonometricOperatorClicked()));
    connect(ui->arccos,SIGNAL(clicked()),this,SLOT(trigonometricOperatorClicked()));
    connect(ui->arctg,SIGNAL(clicked()),this,SLOT(trigonometricOperatorClicked()));

    connect(ui->MS,SIGNAL(clicked()),this,SLOT(memoryOperatorClicked()));
    connect(ui->MR,SIGNAL(clicked()),this,SLOT(memoryOperatorClicked()));
    connect(ui->MC,SIGNAL(clicked()),this,SLOT(memoryOperatorClicked()));
    connect(ui->memory_plus,SIGNAL(clicked()),this,SLOT(memoryOperatorClicked()));

}
std::pair<QString,int> MainWindow::powText(int position,QString text, QString name){
    QString res = text;
    int add = 0;
    if(position != 0){
        if(res[position - 1].isDigit() || res[position-1] == ')'){
            res.insert(position,name);
            add = name.length();
        }
    }
    if(!add){
           ui->statusBar->showMessage(tr("Возводить в степень можно скобку или число"));
           ui->lineEdit->setStyleSheet("border: 1px solid red");
     }
    return std::make_pair(res,add);
}

std::pair<QString,int> MainWindow::sqrtFractText(int position, QString text, QString name){
    QString res = text;
    int add = 0;
    if(position != 0){
        if(Calculate::isSign(res[position - 1]) || res[position-1]=='('){
             res.insert(position,name);
             add = name.length()-1;
        }else{
            ui->statusBar->showMessage(tr("Добавьте операторы перед началом и в конце функции"));
            ui->lineEdit->setStyleSheet("border: 1px solid red");
        }
    }
    else{
        if(res == "0")
             ui->lineEdit->clear();
        res.insert(position,name);
        add = name.length()-1;
    }
    return std::make_pair(res,add);
}
