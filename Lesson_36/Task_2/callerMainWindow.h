//
// Created by 1661322 on 2/13/2023.
//

#ifndef TASK_2_CALLERMAINWINDOW_H
#define TASK_2_CALLERMAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QLineEdit>

class CallerMainWindow : public QMainWindow{
    Q_OBJECT
public:
    QLineEdit* lineEdit = nullptr;

    CallerMainWindow(QWidget* parent = nullptr): QMainWindow(parent){}
public slots:
    void add0() const{ lineEdit->setText(lineEdit->text()+"0"); };
    void add1() const{ lineEdit->setText(lineEdit->text()+"1"); };
    void add2() const{ lineEdit->setText(lineEdit->text()+"2"); };
    void add3() const{ lineEdit->setText(lineEdit->text()+"3"); };
    void add4() const{ lineEdit->setText(lineEdit->text()+"4"); };
    void add5() const{ lineEdit->setText(lineEdit->text()+"5"); };
    void add6() const{ lineEdit->setText(lineEdit->text()+"6"); };
    void add7() const{ lineEdit->setText(lineEdit->text()+"7"); };
    void add8() const{ lineEdit->setText(lineEdit->text()+"8"); };
    void add9() const{ lineEdit->setText(lineEdit->text()+"9"); };
    void makeCall() const{ lineEdit->setText("CALL..."); };
};

#endif //TASK_2_CALLERMAINWINDOW_H
