#include <QPaintEvent>
#include <QApplication>
#include <QPushButton>
#include <QPixmap>
#include <QTimer>
#include <QPainter>
#include <QMediaPlayer>
#include <QMediaContent>


class RedButton : public QPushButton{
    Q_OBJECT

public:
    RedButton() = default;
    RedButton(QWidget *parent);
    void paintEvent(QPaintEvent *e) override;
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;
    void keyPressEvent(QKeyEvent *e) override;

public slots:
    void setUp();
    void setDown();

private:
    QPixmap mCurrentButtonPixmap_;
    QPixmap mButtonUpPixmap_;
    QPixmap mButtonDownPixmap_;

};

RedButton::RedButton(QWidget *parent){
    setParent(parent);
    setToolTip("STOP");
    setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    mButtonUpPixmap_ = QPixmap("/home/reflex/Downloads/Up.png");
    mButtonDownPixmap_ = QPixmap("/home/reflex/Downloads/Down.png");
    mCurrentButtonPixmap_ = mButtonUpPixmap_;
    setGeometry(mCurrentButtonPixmap_.rect());
    connect(this,&QPushButton::clicked,this,&RedButton::setDown);
}

void RedButton::paintEvent(QPaintEvent *e){
    QPainter p(this);
    p.drawPixmap(e->rect(),mCurrentButtonPixmap_);
}

QSize RedButton::sizeHint() const{
    return QSize(200,200);
}

QSize RedButton::minimumSizeHint() const {
    return sizeHint();
}

void RedButton::keyPressEvent(QKeyEvent *e){
    setDown();
}

void RedButton::setUp(){
    mCurrentButtonPixmap_ = mButtonUpPixmap_;
    update();
}

void RedButton::setDown(){
    mCurrentButtonPixmap_ = mButtonDownPixmap_;
    update();
    QTimer::singleShot(200,this,&RedButton::setUp);
}

int main(int argc, char **argv)
{
    QApplication app(argc,argv);
    RedButton buttonSong(nullptr);
    buttonSong.setFixedSize(200,200);
    buttonSong.move(200,400);
    auto *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("/home/reflex/Downloads/Song.mp3"));
    QObject::connect(&buttonSong,&QPushButton::clicked,player,&QMediaPlayer::play);
    buttonSong.show();
    return app.exec();
}

#include <main.moc>
