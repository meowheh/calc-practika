/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *action_2;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *left_bracket;
    QPushButton *AC;
    QPushButton *MS;
    QPushButton *memory_plus;
    QPushButton *nine;
    QPushButton *abs;
    QPushButton *sh;
    QPushButton *MR;
    QPushButton *cos;
    QPushButton *pow;
    QPushButton *ln;
    QPushButton *factorial;
    QPushButton *MC;
    QPushButton *exp;
    QPushButton *tg;
    QPushButton *memory_minus;
    QRadioButton *degree;
    QPushButton *arccos;
    QPushButton *arctg;
    QPushButton *seven;
    QPushButton *division;
    QPushButton *pi;
    QPushButton *arsh;
    QPushButton *log;
    QPushButton *cube;
    QPushButton *sin;
    QPushButton *arcsin;
    QPushButton *sqr;
    QPushButton *arch;
    QPushButton *sqrt;
    QPushButton *three;
    QPushButton *one;
    QPushButton *th;
    QPushButton *log_any;
    QPushButton *sqr_ten;
    QPushButton *sign;
    QPushButton *arth;
    QPushButton *mod;
    QPushButton *two;
    QPushButton *zero;
    QPushButton *plus;
    QPushButton *point;
    QPushButton *ch;
    QPushButton *minus;
    QPushButton *six;
    QPushButton *five;
    QPushButton *four;
    QPushButton *mult;
    QRadioButton *radian;
    QHBoxLayout *horizontalLayout;
    QPushButton *result;
    QLineEdit *lineEdit;
    QPushButton *eight;
    QPushButton *backspace;
    QPushButton *right_bracket;
    QPushButton *pushButton;
    QPushButton *root;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(915, 475);
        MainWindow->setFocusPolicy(Qt::StrongFocus);
        MainWindow->setTabShape(QTabWidget::Triangular);
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        left_bracket = new QPushButton(centralWidget);
        left_bracket->setObjectName(QString::fromUtf8("left_bracket"));

        gridLayout->addWidget(left_bracket, 3, 4, 1, 1);

        AC = new QPushButton(centralWidget);
        AC->setObjectName(QString::fromUtf8("AC"));

        gridLayout->addWidget(AC, 3, 8, 1, 1);

        MS = new QPushButton(centralWidget);
        MS->setObjectName(QString::fromUtf8("MS"));
        MS->setMinimumSize(QSize(20, 30));

        gridLayout->addWidget(MS, 2, 6, 1, 1);

        memory_plus = new QPushButton(centralWidget);
        memory_plus->setObjectName(QString::fromUtf8("memory_plus"));
        memory_plus->setMinimumSize(QSize(20, 30));

        gridLayout->addWidget(memory_plus, 2, 7, 1, 1);

        nine = new QPushButton(centralWidget);
        nine->setObjectName(QString::fromUtf8("nine"));

        gridLayout->addWidget(nine, 4, 6, 1, 1);

        abs = new QPushButton(centralWidget);
        abs->setObjectName(QString::fromUtf8("abs"));

        gridLayout->addWidget(abs, 4, 8, 1, 1);

        sh = new QPushButton(centralWidget);
        sh->setObjectName(QString::fromUtf8("sh"));

        gridLayout->addWidget(sh, 5, 0, 1, 1);

        MR = new QPushButton(centralWidget);
        MR->setObjectName(QString::fromUtf8("MR"));
        MR->setMinimumSize(QSize(20, 30));

        gridLayout->addWidget(MR, 2, 5, 1, 1);

        cos = new QPushButton(centralWidget);
        cos->setObjectName(QString::fromUtf8("cos"));
        cos->setMinimumSize(QSize(20, 30));

        gridLayout->addWidget(cos, 3, 0, 1, 1);

        pow = new QPushButton(centralWidget);
        pow->setObjectName(QString::fromUtf8("pow"));

        gridLayout->addWidget(pow, 5, 3, 1, 1);

        ln = new QPushButton(centralWidget);
        ln->setObjectName(QString::fromUtf8("ln"));

        gridLayout->addWidget(ln, 4, 2, 1, 1);

        factorial = new QPushButton(centralWidget);
        factorial->setObjectName(QString::fromUtf8("factorial"));
        factorial->setMinimumSize(QSize(20, 30));

        gridLayout->addWidget(factorial, 2, 3, 1, 1);

        MC = new QPushButton(centralWidget);
        MC->setObjectName(QString::fromUtf8("MC"));
        MC->setMinimumSize(QSize(20, 30));

        gridLayout->addWidget(MC, 2, 4, 1, 1);

        exp = new QPushButton(centralWidget);
        exp->setObjectName(QString::fromUtf8("exp"));

        gridLayout->addWidget(exp, 3, 2, 1, 1);

        tg = new QPushButton(centralWidget);
        tg->setObjectName(QString::fromUtf8("tg"));

        gridLayout->addWidget(tg, 4, 0, 1, 1);

        memory_minus = new QPushButton(centralWidget);
        memory_minus->setObjectName(QString::fromUtf8("memory_minus"));
        memory_minus->setMinimumSize(QSize(20, 30));

        gridLayout->addWidget(memory_minus, 2, 8, 1, 1);

        degree = new QRadioButton(centralWidget);
        degree->setObjectName(QString::fromUtf8("degree"));

        gridLayout->addWidget(degree, 1, 1, 1, 1);

        arccos = new QPushButton(centralWidget);
        arccos->setObjectName(QString::fromUtf8("arccos"));
        arccos->setMinimumSize(QSize(20, 30));

        gridLayout->addWidget(arccos, 3, 1, 1, 1);

        arctg = new QPushButton(centralWidget);
        arctg->setObjectName(QString::fromUtf8("arctg"));

        gridLayout->addWidget(arctg, 4, 1, 1, 1);

        seven = new QPushButton(centralWidget);
        seven->setObjectName(QString::fromUtf8("seven"));

        gridLayout->addWidget(seven, 4, 4, 1, 1);

        division = new QPushButton(centralWidget);
        division->setObjectName(QString::fromUtf8("division"));

        gridLayout->addWidget(division, 4, 7, 1, 1);

        pi = new QPushButton(centralWidget);
        pi->setObjectName(QString::fromUtf8("pi"));
        pi->setMinimumSize(QSize(20, 30));

        gridLayout->addWidget(pi, 2, 2, 1, 1);

        arsh = new QPushButton(centralWidget);
        arsh->setObjectName(QString::fromUtf8("arsh"));

        gridLayout->addWidget(arsh, 5, 1, 1, 1);

        log = new QPushButton(centralWidget);
        log->setObjectName(QString::fromUtf8("log"));

        gridLayout->addWidget(log, 5, 2, 1, 1);

        cube = new QPushButton(centralWidget);
        cube->setObjectName(QString::fromUtf8("cube"));

        gridLayout->addWidget(cube, 4, 3, 1, 1);

        sin = new QPushButton(centralWidget);
        sin->setObjectName(QString::fromUtf8("sin"));
        sin->setMinimumSize(QSize(20, 30));

        gridLayout->addWidget(sin, 2, 0, 1, 1);

        arcsin = new QPushButton(centralWidget);
        arcsin->setObjectName(QString::fromUtf8("arcsin"));
        arcsin->setMinimumSize(QSize(20, 30));

        gridLayout->addWidget(arcsin, 2, 1, 1, 1);

        sqr = new QPushButton(centralWidget);
        sqr->setObjectName(QString::fromUtf8("sqr"));

        gridLayout->addWidget(sqr, 3, 3, 1, 1);

        arch = new QPushButton(centralWidget);
        arch->setObjectName(QString::fromUtf8("arch"));

        gridLayout->addWidget(arch, 7, 1, 1, 1);

        sqrt = new QPushButton(centralWidget);
        sqrt->setObjectName(QString::fromUtf8("sqrt"));

        gridLayout->addWidget(sqrt, 7, 3, 1, 1);

        three = new QPushButton(centralWidget);
        three->setObjectName(QString::fromUtf8("three"));

        gridLayout->addWidget(three, 7, 6, 1, 1);

        one = new QPushButton(centralWidget);
        one->setObjectName(QString::fromUtf8("one"));

        gridLayout->addWidget(one, 7, 4, 1, 1);

        th = new QPushButton(centralWidget);
        th->setObjectName(QString::fromUtf8("th"));

        gridLayout->addWidget(th, 8, 0, 1, 1);

        log_any = new QPushButton(centralWidget);
        log_any->setObjectName(QString::fromUtf8("log_any"));

        gridLayout->addWidget(log_any, 7, 2, 1, 1);

        sqr_ten = new QPushButton(centralWidget);
        sqr_ten->setObjectName(QString::fromUtf8("sqr_ten"));

        gridLayout->addWidget(sqr_ten, 8, 2, 1, 1);

        sign = new QPushButton(centralWidget);
        sign->setObjectName(QString::fromUtf8("sign"));

        gridLayout->addWidget(sign, 8, 6, 1, 1);

        arth = new QPushButton(centralWidget);
        arth->setObjectName(QString::fromUtf8("arth"));

        gridLayout->addWidget(arth, 8, 1, 1, 1);

        mod = new QPushButton(centralWidget);
        mod->setObjectName(QString::fromUtf8("mod"));

        gridLayout->addWidget(mod, 5, 8, 1, 1);

        two = new QPushButton(centralWidget);
        two->setObjectName(QString::fromUtf8("two"));

        gridLayout->addWidget(two, 7, 5, 1, 1);

        zero = new QPushButton(centralWidget);
        zero->setObjectName(QString::fromUtf8("zero"));

        gridLayout->addWidget(zero, 8, 4, 1, 1);

        plus = new QPushButton(centralWidget);
        plus->setObjectName(QString::fromUtf8("plus"));

        gridLayout->addWidget(plus, 8, 7, 1, 1);

        point = new QPushButton(centralWidget);
        point->setObjectName(QString::fromUtf8("point"));

        gridLayout->addWidget(point, 8, 5, 1, 1);

        ch = new QPushButton(centralWidget);
        ch->setObjectName(QString::fromUtf8("ch"));

        gridLayout->addWidget(ch, 7, 0, 1, 1);

        minus = new QPushButton(centralWidget);
        minus->setObjectName(QString::fromUtf8("minus"));

        gridLayout->addWidget(minus, 7, 7, 1, 1);

        six = new QPushButton(centralWidget);
        six->setObjectName(QString::fromUtf8("six"));

        gridLayout->addWidget(six, 5, 6, 1, 1);

        five = new QPushButton(centralWidget);
        five->setObjectName(QString::fromUtf8("five"));

        gridLayout->addWidget(five, 5, 5, 1, 1);

        four = new QPushButton(centralWidget);
        four->setObjectName(QString::fromUtf8("four"));

        gridLayout->addWidget(four, 5, 4, 1, 1);

        mult = new QPushButton(centralWidget);
        mult->setObjectName(QString::fromUtf8("mult"));

        gridLayout->addWidget(mult, 5, 7, 1, 1);

        radian = new QRadioButton(centralWidget);
        radian->setObjectName(QString::fromUtf8("radian"));
        radian->setChecked(true);

        gridLayout->addWidget(radian, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        result = new QPushButton(centralWidget);
        result->setObjectName(QString::fromUtf8("result"));
        result->setMinimumSize(QSize(20, 80));
        result->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(result);


        gridLayout->addLayout(horizontalLayout, 7, 8, 2, 1);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(true);
        lineEdit->setMinimumSize(QSize(500, 50));
        lineEdit->setFocusPolicy(Qt::ClickFocus);

        gridLayout->addWidget(lineEdit, 0, 0, 1, 9);

        eight = new QPushButton(centralWidget);
        eight->setObjectName(QString::fromUtf8("eight"));

        gridLayout->addWidget(eight, 4, 5, 1, 1);

        backspace = new QPushButton(centralWidget);
        backspace->setObjectName(QString::fromUtf8("backspace"));

        gridLayout->addWidget(backspace, 3, 7, 1, 1);

        right_bracket = new QPushButton(centralWidget);
        right_bracket->setObjectName(QString::fromUtf8("right_bracket"));

        gridLayout->addWidget(right_bracket, 3, 6, 1, 1);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 3, 5, 1, 1);

        root = new QPushButton(centralWidget);
        root->setObjectName(QString::fromUtf8("root"));

        gridLayout->addWidget(root, 8, 3, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 915, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(action);
        menu->addAction(action_2);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        action->setText(QApplication::translate("MainWindow", "\320\237\321\200\321\217\320\274\320\260\321\217 \320\263\320\265\320\276\320\264\320\265\320\267\320\270\321\207\320\265\321\201\320\272\320\260\321\217 \320\267\320\260\320\264\320\260\321\207\320\260", 0, QApplication::UnicodeUTF8));
        action_2->setText(QApplication::translate("MainWindow", "\320\236\320\261\321\200\320\260\321\202\320\275\320\260\321\217 \320\263\320\265\320\276\320\264\320\265\320\267\320\270\321\207\320\265\321\201\320\272\320\260\321\217 \320\267\320\260\320\264\320\260\321\207\320\260", 0, QApplication::UnicodeUTF8));
        left_bracket->setText(QApplication::translate("MainWindow", "(", 0, QApplication::UnicodeUTF8));
        AC->setText(QApplication::translate("MainWindow", "AC", 0, QApplication::UnicodeUTF8));
        MS->setText(QApplication::translate("MainWindow", "MS", 0, QApplication::UnicodeUTF8));
        memory_plus->setText(QApplication::translate("MainWindow", "M+", 0, QApplication::UnicodeUTF8));
        nine->setText(QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8));
        abs->setText(QApplication::translate("MainWindow", "abs", 0, QApplication::UnicodeUTF8));
        sh->setText(QApplication::translate("MainWindow", "sh", 0, QApplication::UnicodeUTF8));
        MR->setText(QApplication::translate("MainWindow", "MR", 0, QApplication::UnicodeUTF8));
        cos->setText(QApplication::translate("MainWindow", "cos", 0, QApplication::UnicodeUTF8));
        pow->setText(QApplication::translate("MainWindow", "x^y", 0, QApplication::UnicodeUTF8));
        ln->setText(QApplication::translate("MainWindow", "ln", 0, QApplication::UnicodeUTF8));
        factorial->setText(QApplication::translate("MainWindow", "n!", 0, QApplication::UnicodeUTF8));
        MC->setText(QApplication::translate("MainWindow", "MC", 0, QApplication::UnicodeUTF8));
        exp->setText(QApplication::translate("MainWindow", "exp", 0, QApplication::UnicodeUTF8));
        tg->setText(QApplication::translate("MainWindow", "tg", 0, QApplication::UnicodeUTF8));
        memory_minus->setText(QApplication::translate("MainWindow", "M-", 0, QApplication::UnicodeUTF8));
        degree->setText(QApplication::translate("MainWindow", "\320\223\321\200\320\260\320\264\321\203\321\201\321\213", 0, QApplication::UnicodeUTF8));
        arccos->setText(QApplication::translate("MainWindow", "arccos", 0, QApplication::UnicodeUTF8));
        arctg->setText(QApplication::translate("MainWindow", "arctg", 0, QApplication::UnicodeUTF8));
        seven->setText(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
        division->setText(QApplication::translate("MainWindow", "/", 0, QApplication::UnicodeUTF8));
        pi->setText(QApplication::translate("MainWindow", "pi", 0, QApplication::UnicodeUTF8));
        arsh->setText(QApplication::translate("MainWindow", "arsh", 0, QApplication::UnicodeUTF8));
        log->setText(QApplication::translate("MainWindow", "log", 0, QApplication::UnicodeUTF8));
        cube->setText(QApplication::translate("MainWindow", "x^3", 0, QApplication::UnicodeUTF8));
        sin->setText(QApplication::translate("MainWindow", "sin", 0, QApplication::UnicodeUTF8));
        arcsin->setText(QApplication::translate("MainWindow", "arcsin", 0, QApplication::UnicodeUTF8));
        sqr->setText(QApplication::translate("MainWindow", "x^2", 0, QApplication::UnicodeUTF8));
        arch->setText(QApplication::translate("MainWindow", "arch", 0, QApplication::UnicodeUTF8));
        sqrt->setText(QApplication::translate("MainWindow", "sqrt", 0, QApplication::UnicodeUTF8));
        three->setText(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        one->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        th->setText(QApplication::translate("MainWindow", "th", 0, QApplication::UnicodeUTF8));
        log_any->setText(QApplication::translate("MainWindow", "logxy", 0, QApplication::UnicodeUTF8));
        sqr_ten->setText(QApplication::translate("MainWindow", "10^x", 0, QApplication::UnicodeUTF8));
        sign->setText(QApplication::translate("MainWindow", "+/-", 0, QApplication::UnicodeUTF8));
        arth->setText(QApplication::translate("MainWindow", "arth", 0, QApplication::UnicodeUTF8));
        mod->setText(QApplication::translate("MainWindow", "mod", 0, QApplication::UnicodeUTF8));
        two->setText(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        zero->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        plus->setText(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        point->setText(QApplication::translate("MainWindow", ".", 0, QApplication::UnicodeUTF8));
        ch->setText(QApplication::translate("MainWindow", "ch", 0, QApplication::UnicodeUTF8));
        minus->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        six->setText(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        five->setText(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        four->setText(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        mult->setText(QApplication::translate("MainWindow", "x", 0, QApplication::UnicodeUTF8));
        radian->setText(QApplication::translate("MainWindow", "\320\240\320\260\320\264\320\270\320\260\320\275\321\213", 0, QApplication::UnicodeUTF8));
        result->setText(QApplication::translate("MainWindow", "=", 0, QApplication::UnicodeUTF8));
        eight->setText(QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8));
        backspace->setText(QApplication::translate("MainWindow", "Backspace", 0, QApplication::UnicodeUTF8));
        right_bracket->setText(QApplication::translate("MainWindow", ")", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", ",", 0, QApplication::UnicodeUTF8));
        root->setText(QApplication::translate("MainWindow", "sqrt3", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("MainWindow", "\320\232\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
