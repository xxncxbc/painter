#ifndef PAINTSCENE_H
#define PAINTSCENE_H
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <QDebug>


#include "figure.h"

class paintScene : public QGraphicsScene
{

    Q_OBJECT
    // Свойство текущего типа используемой фигуры
    Q_PROPERTY(int typeFigure
                   READ typeFigure WRITE setTypeFigure
                       NOTIFY typeFigureChanged)

public:
    explicit paintScene(QObject *parent = 0);
    ~paintScene();
    paintScene(QObject *parent, QColor& color/*, Array<Figure*> & _vector*/);

    int typeFigure() const;                 // Возвращение текущего типа
    void setTypeFigure(const int type);     // Установка текущего типа
    void setcolor(QColor & clr);
    QColor c;
    //Array<Figure*>& o1;
    // Перечисление типов используемых фигур
    enum FigureTypes {
        SquareType,
        RombType,
        OvalType
    };

signals:
    void typeFigureChanged();

private:
    QPointF     previousPoint;      // Координаты предыдущей точки
    /* Объект для временного хранения рисуемой фигуры
     * Является объектом базового класса для всех трёх типов фигур в примере
     * */
    Figure *tempFigure;
    int m_typeFigure;   // текущий тип фигуры


private:
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

};

#endif // PAINTSCENE_H
