#include <QtGui/QtGui>
#include <QApplication>
#include <QLabel>
#include <QSlider>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QGraphicsScene>
#include <QGraphicsBlurEffect>
#include <QGraphicsPixmapItem>
#include <QtConcurrent/QtConcurrent>


QImage blurImage(QImage source,int blurRadius)
{
    if(source.isNull()) return QImage();
    QGraphicsScene scene;
    QGraphicsPixmapItem item;
    item.setPixmap(QPixmap::fromImage(source));
    auto *blur = new QGraphicsBlurEffect;
    blur->setBlurRadius(blurRadius);
    item.setGraphicsEffect(blur);
    scene.addItem(&item);
    QImage result(source.size(),QImage::Format_ARGB32);
    result.fill(Qt::transparent);
    QPainter painter(&result);
    scene.render(&painter,QRectF(),QRectF(0,0,source.width(),
                                          source.height()));
    return result;
}


int main(int argc, char *argv[]){
    QApplication app(argc, argv);
    QWidget *window = new QWidget;
    QLabel *imageBlur = new QLabel;
    QSlider *sliderBlur = new QSlider;
    QPushButton *openButton = new QPushButton("OPEN");
    QVBoxLayout *hbox = new QVBoxLayout(window);

    sliderBlur->setOrientation(Qt::Horizontal);
    sliderBlur->setMinimum(0);
    sliderBlur->setMaximum(10);

    hbox->addWidget(imageBlur);
    hbox->addWidget(sliderBlur);
    hbox->addWidget(openButton);

    QString filePath;

    QObject::connect(openButton,&QPushButton::clicked,[&filePath,imageBlur,sliderBlur](){
        filePath = QFileDialog::getOpenFileName(nullptr,
                                     "Open jpg image",
                                     "/home/reflex/",
                                     "jpg files (*.jpg)");

        if (!filePath.isEmpty() && !filePath.isNull()){
        imageBlur->setPixmap(filePath);
        imageBlur->setScaledContents(true);
        imageBlur->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
        sliderBlur->setValue(0);
        }
    });

    QObject::connect(sliderBlur,&QSlider::valueChanged,[imageBlur,&filePath](qint64 number){
        imageBlur->setPixmap(QPixmap::fromImage(blurImage(QImage(filePath),number)));
    });

    window->show();
    return app.exec();
}
