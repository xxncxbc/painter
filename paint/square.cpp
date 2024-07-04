#include "square.h"
#include <QPainter>

Square::Square(QPointF point, QObject *parent) :
    Figure(point,parent),
    m_fillColor2(Qt::yellow)
{
    Q_UNUSED(point)
}
Square::Square(QPointF point,  QColor & color, QObject *parent):Figure(point,color,parent), m_fillColor2(color) {}
Square::~Square() {}

// Реализуем метод отрисовки
void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(m_fillColor2));
    painter->setBrush(m_fillColor2);

    QPolygonF polygon;

    polygon << QPointF(startPoint().x(), startPoint().y()) // Верхний левый угол
            << QPointF(endPoint().x(), startPoint().y())   // Верхний правый угол
            << QPointF(endPoint().x(), endPoint().y())     // Нижний правый угол
            << QPointF(startPoint().x(), endPoint().y());  // Нижний левый угол
    painter->drawPolygon(polygon);
    Q_UNUSED(option)
    Q_UNUSED(widget)
}
