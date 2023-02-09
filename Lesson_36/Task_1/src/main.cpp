#include "Circle.h"

int main(int argc , char **argv) {

    QApplication qt_app(argc,argv);

    auto *window = new QWidget;
    window->setFixedSize(350,350);

    Circle colorCircle(window);

    auto *sliderColor = new QSlider(Qt::Horizontal,window);
    sliderColor->setMinimum(0); sliderColor->setMaximum(100);

    auto *gag = new QVBoxLayout (window);
    gag->addWidget(&colorCircle);
    gag->addWidget(sliderColor);

    QObject::connect(sliderColor, &QSlider::valueChanged, [&sliderColor, &colorCircle](int newValue) {
        if (newValue>33){
            if (newValue>66) colorCircle.setRedCircle();
            else colorCircle.setYellowCircle();
        }
        else colorCircle.setGreenCircle();
    });

    window->show();
    return QApplication::exec();
}

//#include "main.moc"


