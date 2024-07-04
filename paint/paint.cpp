#include "paint.h"
#include "ui_paint.h"
#include "svgreader.h"
#include <QWidget>
#include <QTimer>
#include <QColorDialog>
#include <QFileDialog>
#include <QFile>
#include <QSvgGenerator>

QColor color = Qt::red;
paintScene * scene;

paint::paint(QWidget *parent)
    : QMainWindow (parent)
    , ui(new Ui::paint)
{
    ui->setupUi(this);
    scene = new paintScene(parent, color);
    ui->graphicsView->setScene(scene);
    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &paint::slotTimer);
    timer->start(100);
}

paint::~paint()
{
    delete ui;
}


void paint::slotTimer(){
    timer->stop();
    scene->setSceneRect(0, 0, ui->graphicsView->width() - 20, ui->graphicsView->height() - 20);
}

void paint::resizeEvent(QResizeEvent * event){
    timer->start(100);
    QWidget::resizeEvent(event);
}

void paint::on_actioncolor_triggered()
{
    color = QColorDialog::getColor(Qt::red, this);
    scene->setcolor(color);
    ui->graphicsView->setScene(scene);
}


void paint::on_actionsquare_triggered()
{
    scene->setTypeFigure(paintScene::SquareType);
    ui->graphicsView->setScene(scene);
}


void paint::on_actionoval_triggered()
{
    scene->setTypeFigure(paintScene::OvalType);
    ui->graphicsView->setScene(scene);
}


void paint::on_actionromb_triggered()
{
    scene->setTypeFigure(paintScene::RombType);
    ui->graphicsView->setScene(scene);
}


void paint::on_actionsave_triggered()
{
    QString file_name = QFileDialog::getSaveFileName(this, "Save SVG");

    QSvgGenerator generator;        // Создаём объект генератора файла
    generator.setFileName(file_name);    // Устанавливаем путь к файлу, куда будет сохраняться векторная графика
    generator.setSize(QSize(scene->width(), scene->height()));  // Устанавливаем размеры рабочей области документа в миллиметрах
    generator.setViewBox(QRect(0, 0, scene->width(), scene->height())); // Устанавливаем рабочую область в координатах
    generator.setTitle("SVG Example");                          // Титульное название документа
    generator.setDescription("File created by SVG Example");    // Описание документа

    // С помощью класса QPainter
    QPainter painter;
    painter.begin(&generator);  // Устанавливаем устройство/объект в котором будем производить отрисовку
    scene->render(&painter);    // Отрисовываем содержимое сцены с помощью painter в целевое устройство/объект
    painter.end();              // Заканчиваем отрисовку


}


void paint::on_actionopen_triggered()
{
    QString file_name1;
    QString file_name = QFileDialog::getOpenFileName(this, tr("Open SVG"),  file_name1, tr("SVG files (*.svg)"));;
    if (file_name.isEmpty()){
        return;
    }

    scene->clear();

    scene->setSceneRect(SvgReader::getSizes(file_name));
    QList<element> help = SvgReader::getElements(file_name);    // Зададим размеры графической сцены
    SvgReader::draw(help, scene) ;

    ui->graphicsView->setScene(scene);
}


void paint::on_actionnew_triggered()
{
    scene->clear();
}

