#ifndef YOMEWIDGET_H
#define YOMEWIDGET_H

#include <QWidget>
#include <QStringList>
#include <QDir>
#include <QPixmap>
#include <QBitmap>
#include <QMouseEvent>
#include <QPoint>

namespace Ui {
    class yomewidget;
}

class yomewidget : public QWidget
{
    Q_OBJECT

public:
    explicit yomewidget(QWidget *parent = 0);
    ~yomewidget();

protected:
    void mouseMoveEvent(QMouseEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseDoubleClickEvent(QMouseEvent *);

private:
    Ui::yomewidget *ui;
    QPoint dragPos;
    QStringList entries;
    int currentEntry;
    void setBackground();
};

#endif // YOMEWIDGET_H
