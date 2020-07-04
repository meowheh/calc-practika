#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}
class Button;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
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

private:
    Ui::MainWindow *ui;
    double sumInMemory;
};

#endif // MAINWINDOW_H
