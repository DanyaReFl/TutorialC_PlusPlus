#include "ui_operations.h"
#include "ClassOperations.h"

int main(int argc , char **argv) {
    QApplication qt_app(argc,argv);
    Operations window(nullptr);
    Ui::MainWindow caller;
    caller.setupUi(&window);
    window.lineEditFirst_ = caller.lineEdit_1;
    window.lineEditSecond_ = caller.lineEdit_2;
    window.lineEditResult_ = caller.lineEdit_3;
    window.resize(500,300);
    window.show();
    return QApplication::exec();
}

#include "main.moc"

