#include "Circle.h"

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

//#include "moc_Circle.cpp"