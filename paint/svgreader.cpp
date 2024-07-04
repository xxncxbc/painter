#include "svgreader.h"
#include <QPen>
#include <QFile>
#include <QMessageBox>
#include <QDomDocument>
#include <cmath>
#include <QList>
#include "romb.h"
#include "square.h"
#include "oval.h"

SvgReader::SvgReader()
{

}

QList<element> SvgReader::getElements(const QString filename)
{
    QList<element> figList;    // Объявим в стеке список прямоугольников

    QDomDocument doc;       // объект документа
    QFile file(filename);   // Открываем наш SVG-файл
    // Если он не открылся или не удалось передать содержимое в QDocDocument
    if (!file.open(QIODevice::ReadOnly) || !doc.setContent(&file))
        return figList;    // то возвратим список, но пустой

    // Ищем в документе все объекты с тегом g
    QDomNodeList gList = doc.elementsByTagName("g");
    // Начинаем их перебирать
    for (int i = 0; i < gList.size(); i++) {
        QDomNode gNode = gList.item(i);     // Выделяем из списка ноду
        QDomElement fig = gNode.firstChildElement("path");    // И ищем в ней элемент c тегом rect
        // Если полученный элементы не нулевой, то
        if (fig.isNull()){
            continue;
        } else {

            QString str;
            element p;

            // Забираем размеры из тега rect
            QDomElement gElement = gNode.toElement();
            str = fig.attribute("d"); // достаем координатную строчку
            // из тега <g> забираем цвета
            QColor fillColor(gElement.attribute("fill", "#ffffff"));    // цвет заливки
            fillColor.setAlphaF(gElement.attribute("fill-opacity","0").toFloat());

            // а также цвет и толщина абриса
            QColor strokeColor(gElement.attribute("stroke", "#000000"));
            strokeColor.setAlphaF(gElement.attribute("stroke-opacity").toFloat());
            p.fColor = fillColor;
            p.sColor = strokeColor;
            p.cords = str;
            figList.append(p);  // добавляем элемент
        }
    }
    file.close();
    return figList;
}

QRectF SvgReader::getSizes(const QString filename)
{
    QDomDocument doc;       // инициализируем в стеке объект QDomDocument
    QFile file(filename);   // Открываем наш SVG-файл
    // Если он не открылся или не удалось передать содержимое в QDocDocument
    if (!file.open(QIODevice::ReadOnly) || !doc.setContent(&file))
        return QRectF(0,0,200,200); // то возвратим значения для сцены по умолчанию

    /* Далее забираем список элементов с тегом svg.
     * В случае, если список элементов будет не пустой,
     * то заберём размеры графической сцены.
     * */
    QDomNodeList list = doc.elementsByTagName("svg");
    if(list.length() > 0) {
        QDomElement svgElement = list.item(0).toElement();
        QStringList parameters = svgElement.attribute("viewBox").split(" ");
        return QRectF(parameters.at(0).toInt(),
                      parameters.at(1).toInt(),
                      parameters.at(2).toInt(),
                      parameters.at(3).toInt());
    }
    return QRectF(0,0,200,200);
}

void SvgReader::draw(QList<element> & figList, paintScene * scene){
    QList<QString> moves;
    QList<QString> move;
    for(int i = 0; i < figList.size(); i++){
        std::vector<double> mx, my;
        moves = figList[i].cords.split(" ");// делим figList.str на "M989.123,321.543" конкретные точки
        moves[0].remove(0,1); //убираем первый символ
        move = moves[0].split(","); //берем наальную точку
        mx.push_back(move[0].toDouble()); //загоняем по векторам для ординат и абсцисс
        my.push_back(move[1].toDouble());
        for(int j = 1; j < moves.size(); j++){
            moves[j].remove(0,1);
            move = moves[j].split(",");
            mx.push_back(move[0].toDouble());
            my.push_back(move[1].toDouble());
        }
        if(mx.size() <= 5){ // если 5 элементов (1 угол - 2 угол -3 угол -4 угол - 1 угол), то либо квадрат либо ромб
            if(mx[0] == mx[1] || my[0] == my[1]){
                QGraphicsRectItem * item = new QGraphicsRectItem();
                item->setRect(mx[0], my[0], fabs(mx[0] - mx[1]), fabs(my[0] - my[3]) );
                item->setBrush(QBrush(figList[i].fColor));
                item->setPen(QPen(figList[i].fColor));

                scene->addItem(item);
            }
            else{ //элипс
                QList<QPointF> points;
                QPointF t;
                for(int i = 0; i < mx.size() - 1; i++){
                    t.setX(mx[i]);
                    t.setY(my[i]);
                    points.append(t);
                }
                QPolygonF pts(points);
                QGraphicsPolygonItem * item = new QGraphicsPolygonItem(pts);
                item->setBrush(QBrush(figList[i].fColor));
                item->setPen(QPen(figList[i].fColor));
                item->setFillRule(Qt::OddEvenFill);

                scene->addItem(item);

            }
        }
        else{
            QGraphicsEllipseItem * item = new QGraphicsEllipseItem(); // сложна вырубай
            item->setRect(*std::min_element(begin(mx), end(mx)), *std::min_element(begin(my), end(my)), fabs(*std::max_element(begin(mx), end(mx)) - *std::min_element(begin(mx), end(mx))), fabs(*std::max_element(begin(my), end(my)) - *std::min_element(begin(my), end(my))) );
            item->setBrush(QBrush(figList[i].fColor));
            item->setPen(QPen(figList[i].fColor));
            scene->addItem(item);
        }
    }
}




















