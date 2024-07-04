#ifndef OVAL_H
#define OVAL_H

#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

#include <QPainter>
#include <QColor>

class Oval: public Figure
{
    Q_OBJECT
public:
    explicit Oval(QPointF point, QObject *parent = 0);
    Oval(QPointF point,  QColor & c, QObject *parent = 0);
    ~Oval();
    QColor m_fillColor;
private:
    // Для Ромба реализуем только саму отрисовку
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    // Array<Figure*>& o1;
};

#endif // OVAL_H
