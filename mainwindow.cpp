#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sumInMemory = 0.0;

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
MainWindow::~MainWindow()
{
    delete ui;
}

//слот на сигнал нажатия цифры
void MainWindow::digitClicked(){
   QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    int digitValue = clickedButton->text().toInt();
    if (ui->lineEdit->text() == "0" && digitValue == 0.0)
          return;
    if(ui->lineEdit->text() == "0")
        ui->lineEdit->clear();
    QString text = ui->lineEdit->text();
    int position = ui->lineEdit->cursorPosition();
    text.insert(position,QString::number(digitValue));
    ui->lineEdit->setText(text);
    ui->lineEdit->setCursorPosition(position+1);
}

//слот на сигнал нажатия точки
void MainWindow::on_point_clicked()
{
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
    }
}

//слот на сигнал нажатия смены знака
void MainWindow::on_sign_clicked()
{
    QString text = ui->lineEdit->text();
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
//слот на сигнал Backspace
void MainWindow::on_backspace_clicked()
{
    QString text = ui->lineEdit->text();
    if (text != "0") {
        int position = ui->lineEdit->cursorPosition();
        if (position > 0){
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
    int add=0;
    QObject* button = QObject::sender();
    if(ui->lineEdit->text() == "0")
        ui->lineEdit->clear();
    QString res = ui->lineEdit->text();
    int position = ui->lineEdit->cursorPosition();
    if(button == ui->sqr){
        if(position != 0){
            if(res[position - 1].isDigit() || res[position-1] == ')'){
                res.insert(position,"^2");
                add = 2;
            }
            else  ui->statusBar->showMessage(tr("Возводить в степень можно скобку или число"));
          }else  ui->statusBar->showMessage(tr("Возводить в степень можно скобку или число"));
     }else if(button == ui->pow){
        if(position != 0){
            if(res[position - 1].isDigit() || res[position-1] == ')'){
                res.insert(position,"^");
                add = 1;
            }
            else ui->statusBar->showMessage(tr("Возводить в степень можно скобку или число"));
        }else ui->statusBar->showMessage(tr("Возводить в степень можно скобку или число"));
    }
    else if(button == ui->pow){
                    if(position != 0){
                        if (res[position - 1].isDigit() || res[position-1] == ')'){
                         res.insert(position,"^");
                         add = 1;
                        }
                        else ui->statusBar->showMessage(tr("Возводить в степень можно скобку или число"));
                     }
                    else ui->statusBar->showMessage(tr("Возводить в степень можно скобку или число"));
   }else if (button == ui->sqrt){
        if(position != 0){
            if(isSign(res[position - 1]) || res[position-1]=='('){
                 res.insert(position,"sqrt()");
                 add = 5;
            }else{
                ui->statusBar->showMessage(tr("Добавьте операторы перед началом и в конце функции"));}
        }
        else{
            if(res == "0")
                 ui->lineEdit->clear();
            res.insert(position,"sqrt()");
            add = 5;
        }
   }
  else if(button == ui->fraction){
        if(position != 0){
            if(isSign(res[position-1]) || res[position-1] == '('){
                 res.insert(position,"1/()");
                 add = 3;}
            else{
                 ui->statusBar->showMessage(tr("Добавьте операторы перед началом и в конце функции"));
                }
        }
        else{
            if(res == "0")
                ui->lineEdit->clear();
            res.insert(position,"1/()");
            add = 3;
        }
    }
   ui->lineEdit->setText(res);
   ui->lineEdit->setCursorPosition(position+add);

}
//слоты операций +,-,*,/ константы pi
void MainWindow::simpleOperatorClicked(){
    int add = 0;
    QObject* button = QObject::sender();
    if(ui->lineEdit->text() == "0")
        ui->lineEdit->clear();
   int position = ui->lineEdit->cursorPosition();
    QString res = ui->lineEdit->text();
    if(button == ui->pi){
           QString pi = QString::number(PI);
           res.insert(position,pi);
            add = pi.length();
    }
    else{
        if(position != 0){
            if(!isSign(res[position-1]) && res[position-1]!='^'){
                if(button == ui->plus){
                  res.insert(position,"+");
                 add = 1;
                 }
                else if(button == ui->minus){
                  res.insert(position,"-");
                  add = 1;
                 }
                 else if(button == ui->mult){
                  res.insert(position,"*");
                  add = 1;
                 }
                else if(button == ui->division){
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
            }
    }
    ui->lineEdit->setText(res);
    ui->lineEdit->setCursorPosition(position+add);
}
//слот на скобки
void MainWindow::bracketOperatorClicked(){
    int add = 0;
    QObject* button = QObject::sender();
    if(ui->lineEdit->text() == "0"){
        ui->lineEdit->clear();
    }
    int position = ui->lineEdit->cursorPosition();
    QString res = ui->lineEdit->text();
    if(button == ui->left_bracket){
        res.insert(position,"(");
        add = 1;
      res.append(")");
    }
    else if(button == ui->right_bracket){
        res.insert(position,")");
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
   else if(isSign(res[position-1])|| res[position-1] == '('){
       res.insert(position,text.append("()"));
       add = text.size()-1;
   }
   else{
       ui->statusBar->showMessage(tr("Добавьте операторы перед началом и в конце функции"));
   }
   ui->lineEdit->setText(res);
   ui->lineEdit->setCursorPosition(position+add);
}

//слот на очистку данных
void MainWindow::on_AC_clicked()
{
     ui->lineEdit->setText("0");
}
//слот для клавиш MS, MR, MC, M+
void MainWindow::memoryOperatorClicked(){
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (button == ui->MS)
    {
        double temp =(ui->lineEdit->text()).toDouble();
        if(temp != 0.0){
            ui->statusBar->showMessage(tr("Значение ")+QString::number(sumInMemory)+tr(" было успешно записано"));
            sumInMemory = temp;
        }
        else{
            ui->statusBar->showMessage(tr("Вы ввели ноль или не вычислили результат выражения"));
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
        }
    }
}

//слот кнопки вычисления
void MainWindow::on_result_clicked()
{
    if(ui->lineEdit->text().toDouble() == 0 && ui->lineEdit->text() != "0"){
        QString text = ui->lineEdit->text();

        Calculate calc(text,ui->radian->isChecked());
        double res;
        try{
            res = calc.Resulting();
            ui->lineEdit->setText(QString::number(res));
            ui->statusBar->showMessage(tr("Результат успешно вычислен"));
        } catch(EnteredException &e){
            ui->statusBar->showMessage(e.what());
        }
    }
    else{
        ui->statusBar->showMessage(tr("Введите выражение"));
    }
}

 bool MainWindow::isSign(QChar s){
    return (s == '*' || s == '/' || s == '+' || s == '-');
}
