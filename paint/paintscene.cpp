#include "paintscene.h"
#include "romb.h"
#include "square.h"
#include "oval.h"

paintScene::paintScene(QObject *parent, QColor& color):QGraphicsScene(parent), c(color) {}
paintScene::paintScene(QObject *parent) : QGraphicsScene(parent), c(Qt::red) {}

paintScene::~paintScene() {}

int paintScene::typeFigure() const
{
    return m_typeFigure;
}

void paintScene::setTypeFigure(const int type)
{
    m_typeFigure = type;
}

void paintScene::setcolor(QColor & clr){
    c = clr;
}

void paintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    /* Устанавливаем конечную координату положения мыши
     * в текущую отрисовываемую фигуру
     * */
    tempFigure->setEndPoint(event->scenePos());
    /* Обновляем содержимое сцены,
     * необходимо для устранения артефактов при отрисовке фигур
     * */
    this->update(QRectF(0,0,this->width(), this->height()));
}

void paintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    switch (m_typeFigure) {
    case SquareType: {
        Square *item = new Square(event->scenePos(),c);
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    case RombType: {
        Romb *item = new Romb(event->scenePos(),c);
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    case OvalType:{
        Figure *item = new Oval(event->scenePos(),c);
        //o.data.push_back(item);
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    default:{
        Square *item = new Square(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        break;
    }
    }
    this->addItem(tempFigure);
}


