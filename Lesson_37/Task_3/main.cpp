#include "Controller.h"
#include "ui_remoteController.h"


int main(int argc , char **argv) {
    QApplication qt_app(argc,argv);
    Controller window(nullptr);
    Ui::MainWindow caller;
    caller.setupUi(&window);
    window.LineChannel_ = caller.lineEdit_1;
    window.LineVolume_ = caller.lineEdit_2;
    window.resize(240,680);
    window.show();
    return QApplication::exec();
}

#include "main.moc"