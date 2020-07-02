#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setText("0");
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
    ui->lineEdit->setText(ui->lineEdit->text() + QString::number(digitValue));
}

//слот на сигнал нажатия точки
void MainWindow::on_point_clicked()
{
    if (!ui->lineEdit->text().contains("."))
            ui->lineEdit->setText(ui->lineEdit->text() + tr("."));
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
        text.chop(1);
        if (text.isEmpty()) {
            text = "0";
        }
        ui->lineEdit->setText(text);
}
//void MainWindow::unaryOperatorClicked()
// {
//     QPushButton *clickedButton = qobject_cast< QPushButton *>(sender());
//     QString clickedOperator = clickedButton->text();
//     QString result = ui->lineEdit->text();
//    // double operand = display->text().toDouble();
//   //  double result = 0.0;

//     if (clickedOperator == tr("Sqrt")) {
//         if (operand < 0.0) {
//             abortOperation();
//             return;
//         }
//         result = sqrt(operand);
//     } else if (clickedOperator == tr("x\262")) {
//         result = pow(operand, 2.0);
//     } else if (clickedOperator == tr("1/x")) {
//         if (operand == 0.0) {
//             abortOperation();
//             return;
//         }
//         result = 1.0 / operand;
//     }
//     ui->lineEdit->setText(QString::number(result));
//     waitingForOperand = true;
// }
//слот на очистку данных
void MainWindow::on_AC_clicked()
{
     ui->lineEdit->setText("0");
}
