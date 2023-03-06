#include <QtGui/QtGui>
#include <QApplication>
#include <QWebEngineView>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QMainWindow>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    auto *window = new QWidget;
    auto *lineHtml = new QTextEdit;
    auto *viewHtml = new QWebEngineView;
    viewHtml->setHtml("");
    auto *hbox = new QHBoxLayout(window);

    hbox->addWidget(lineHtml);
    hbox->addWidget(viewHtml);

    lineHtml->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    lineHtml->setMinimumWidth(650);
    lineHtml->sizePolicy().setHorizontalStretch(1);
    lineHtml->setStyleSheet(QString("font-size: %1px").arg(24));
    lineHtml->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    viewHtml->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Preferred);
    viewHtml->sizePolicy().setHorizontalStretch(1);
    QObject::connect(lineHtml,&QTextEdit::textChanged,[viewHtml,lineHtml]() { viewHtml->setHtml( lineHtml->toPlainText() ); } );

    window->show();
    return app.exec();
}

#include <main.moc>
