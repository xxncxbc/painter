#include "oval.h"
#include "figure.h"
#include <QPainter>

Oval::Oval(QPointF point, QObject *parent) :
    Figure(point,parent),
    m_fillColor(Qt::yellow)
{
    Q_UNUSED(point)
}
Oval::Oval(QPointF point,  QColor & color, QObject *parent):Figure(point,parent), m_fillColor(color) {}
Oval::~Oval() {}


void Oval::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->setPen(QPen(m_fillColor));
    painter->setBrush(m_fillColor);

    QPolygonF ellipse;

    // Определяем центр и радиусы овала
    QPointF center((startPoint().x() + endPoint().x()) / 2, (startPoint().y() + endPoint().y()) / 2);
    double rx = std::abs(endPoint().x() - startPoint().x()) / 2;
    double ry = std::abs(endPoint().y() - startPoint().y()) / 2;

    // Заполняем QPolygonF точками овала
    for (int i = 0; i < 100; ++i) {
        double theta = 2.0 * M_PI * i / 100;
        double x = center.x() + rx * std::cos(theta);
        double y = center.y() + ry * std::sin(theta);
        ellipse << QPointF(x, y);
    }
    painter->drawPolygon(ellipse);
    painter->setPen(QPen(m_fillColor, 2));

}
