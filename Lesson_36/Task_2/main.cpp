#include "./ui_untitled.h"
#include "callerMainWindow.h"

int main(int argc , char **argv) {
    QApplication qt_app(argc,argv);
    CallerMainWindow window(nullptr);
    Ui::MainWindow caller;
    caller.setupUi(&window);
    window.lineEdit = caller.lineEdit;
    window.resize(200,480);
    window.show();
    return QApplication::exec();
}

#include "main.moc"
