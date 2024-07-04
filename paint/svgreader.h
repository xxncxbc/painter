#ifndef SVGREADER_H
#define SVGREADER_H

#include <QList>
#include <QGraphicsRectItem>
#include "paintscene.h"

struct element{
    QString cords;
    QColor fColor, sColor;
    element(){
        cords = "";
        fColor = "0";
        sColor =  "0";
    }
};

class SvgReader
{
public:
    SvgReader();
    static QList<element> getElements(const QString filename);
    static QRectF getSizes(const QString filename);
    static void draw(QList<element> & figList, paintScene* scene);
};



#endif // SVGREADER_H
