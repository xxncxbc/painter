#ifndef ROMB_H
#define ROMB_H

#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

#include <QPainter>
#include <QColor>

/* Наследуемся от класса Figure,
 * в котором реализован общий для всех фигур функционал
 * */
class Romb : public Figure
{
    Q_OBJECT

public:
    explicit Romb(QPointF point, QObject *parent = 0);
    ~Romb();
    Romb(QPointF point,  QColor & c1, QObject *parent = 0);
    QColor m_fillColor1;

private:
    // Для Ромба реализуем только саму отрисовку
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // ROMB_H
