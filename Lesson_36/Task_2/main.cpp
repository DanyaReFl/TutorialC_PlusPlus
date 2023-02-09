#include <QApplication>
#include <QPixmap>
#include <QSlider>
#include <QVBoxLayout>
#include <QPainter>
#include <QPaintEvent>

class Circle : public QWidget{
Q_OBJECT
public:
    explicit Circle(QWidget *parent);
    void paintEvent(QPaintEvent *e) override;
    [[nodiscard]] QSize minimumSizeHint() const override;
    void setGreenCircle();
    void setYellowCircle();
    void setRedCircle();
private:
    QPixmap pictureGreenCircle_;
    QPixmap pictureYellowCircle_;
    QPixmap pictureRedCircle_;
    QPixmap currentPictureCircle_;
};

Circle::Circle(QWidget *parent){
    setParent(parent);
    pictureGreenCircle_ = QPixmap("green.png");
    pictureYellowCircle_ = QPixmap("yellow.png");
    pictureRedCircle_ = QPixmap("red.png");
    currentPictureCircle_ = pictureGreenCircle_;
    setGeometry(currentPictureCircle_.rect());
    update();
}

void Circle::paintEvent(QPaintEvent *e){
    QPainter p(this);
    p.drawPixmap(e->rect(),currentPictureCircle_);
}

QSize Circle::minimumSizeHint() const{
    return QSize{100,100};
}

void Circle::setGreenCircle() {
    currentPictureCircle_ = pictureGreenCircle_;
    update();
}

void Circle::setYellowCircle() {
    currentPictureCircle_ = pictureYellowCircle_;
    update();
}

void Circle::setRedCircle() {
    currentPictureCircle_ = pictureRedCircle_;
    update();
}


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

#include "main.moc"
