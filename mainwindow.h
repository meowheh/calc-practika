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
    void on_point_clicked();
    void on_sign_clicked();
    void on_backspace_clicked();
    void on_AC_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
