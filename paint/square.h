#ifndef SQUARE_H
#define SQUARE_H

#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

#include <QPainter>
#include <QColor>

class Square: public Figure
{
    Q_OBJECT
public:
    explicit Square(QPointF point, QObject *parent = 0);
    ~Square();
    Square(QPointF point,  QColor & c2, QObject *parent = 0);
    QColor m_fillColor2;

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // SQUARE_H

