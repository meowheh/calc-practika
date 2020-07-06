#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "calculate.h"

namespace Ui {
class MainWindow;
}
class Button;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    static bool isSign(QChar);
    ~MainWindow();

private slots:
    void digitClicked();
    void simpleOperatorClicked();
    void powOperatorClicked();
    void bracketOperatorClicked();
    void trigonometricOperatorClicked();
    void on_point_clicked();
    void on_sign_clicked();
    void on_backspace_clicked();
    void on_AC_clicked();
    void memoryOperatorClicked();
    void on_result_clicked();

    void on_history_activated(const QString &arg1);

private:
    Ui::MainWindow *ui;
    double sumInMemory;
};

#endif // MAINWINDOW_H
