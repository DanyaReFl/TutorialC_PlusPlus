#ifndef TASK_1_CLASSOPERATIONS_H
#define TASK_1_CLASSOPERATIONS_H

#include <QMainWindow>
#include <QtWidgets/QLineEdit>

class Operations : public QMainWindow{

Q_OBJECT

public:
    QLineEdit *lineEditFirst_ = nullptr;
    QLineEdit *lineEditSecond_ = nullptr;
    QLineEdit *lineEditResult_ = nullptr;

    explicit Operations(QWidget *parent= nullptr): QMainWindow(parent){};

public slots :

    void Add() const{
    lineEditResult_->setText(QString::number((lineEditFirst_->text().toDouble())+(lineEditSecond_->text().toDouble())));
    };

    void Subtract() const{
        lineEditResult_->setText(QString::number((lineEditFirst_->text().toDouble())-(lineEditSecond_->text().toDouble())));
    };

    void Divide() const{
        if (lineEditSecond_->text()=="0") lineEditResult_->setText("ERROR");
        else lineEditResult_->setText(QString::number((lineEditFirst_->text().toDouble())/ (lineEditSecond_->text().toDouble())));
    };

    void Multiply() const{
        lineEditResult_->setText(QString::number((lineEditFirst_->text().toDouble())* (lineEditSecond_->text().toDouble())));
    };
};

#endif //TASK_1_CLASSOPERATIONS_H
