#include "yomewidget.h"
#include "ui_yomewidget.h"

yomewidget::yomewidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::yomewidget)
{
    QStringList filters;
    filters << "*.png" << "*.gif";
    QDir dir(QDir::currentPath());
    dir.setNameFilters(filters);
    entries = dir.entryList();
    if(entries.length()!=0) {
        setWindowFlags(Qt::WindowStaysOnTopHint);
        currentEntry = -1;
        setBackground();
    } else exit(1);
}

yomewidget::~yomewidget()
{
}

void yomewidget::mouseMoveEvent(QMouseEvent *event) {
    if(event->buttons() & Qt::LeftButton) {
        move(event->globalPos() - dragPos);
        event->accept();
    }
}

void yomewidget::mousePressEvent(QMouseEvent *event) {
    if(event->buttons() & Qt::LeftButton) {
        dragPos = event->globalPos() - frameGeometry().topLeft();
        event->accept();
    } else if(event->button() & Qt::RightButton) {
        exit(0);
    }
}

void yomewidget::mouseDoubleClickEvent(QMouseEvent *event) {
    if(event->buttons() & Qt::LeftButton) {
        setBackground();
        event->accept();
    } else if(event->button() & Qt::RightButton) {
        exit(0);
    }
}

void yomewidget::setBackground() {
    if(currentEntry==-1||currentEntry==entries.length()-1) currentEntry = 0;
    else ++currentEntry;
    this->setWindowTitle(QString::number(currentEntry));
    QPixmap pixmap(entries[currentEntry]);
    setMask(pixmap.mask());
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(QImage(pixmap.toImage())));
    this->setPalette(palette);
    this->setFixedSize(pixmap.width(),pixmap.height());
}
