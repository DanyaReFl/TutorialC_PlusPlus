#ifndef TASK_3_CONTROLLER_H
#define TASK_3_CONTROLLER_H

#include <QMainWindow>
#include <QtWidgets/QLineEdit>

class Controller : public QMainWindow{

    Q_OBJECT

public:

    QLineEdit* LineChannel_ {nullptr};
    QLineEdit* LineVolume_ {nullptr};

    Controller(QWidget* parent): QMainWindow(parent){}

public slots:
    void one() const { LineChannel_->setText("1"); };
    void two() const { LineChannel_->setText("2"); };
    void three() const { LineChannel_->setText("3"); };
    void four() const { LineChannel_->setText("4"); };
    void five() const { LineChannel_->setText("5"); };
    void six() const { LineChannel_->setText("6"); };
    void seven() const { LineChannel_->setText("7"); };
    void eight() const { LineChannel_->setText("8"); };
    void nine() const { LineChannel_->setText("9"); };
    void zero() const { LineChannel_->setText("0"); };
    void previous() const {
        if( LineChannel_->text().toInt()!=0) LineChannel_->setText(QString::number(LineChannel_->text().toInt()-1));
        else LineChannel_->setText(QString::number(LineChannel_->text().toInt()+9));
    }
    void next() const {
        if( LineChannel_->text().toInt()!=9) LineChannel_->setText(QString::number(LineChannel_->text().toInt()+1));
        else LineChannel_->setText(QString::number(LineChannel_->text().toInt()-9));
    }
    void quieter() const {
        if ( LineVolume_->text().toInt()!=0) LineVolume_->setText(QString::number(LineVolume_->text().toInt()-10));
    }
    void louder() const {
        if ( LineVolume_->text().toInt()!=100) LineVolume_->setText(QString::number(LineVolume_->text().toInt()+10));
    }

};
#endif //TASK_3_CONTROLLER_H
