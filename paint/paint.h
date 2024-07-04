#ifndef PAINT_H
#define PAINT_H

#include <QMainWindow>
#include <QWidget>
#include <QTimer>
#include <QResizeEvent>
#include "paintscene.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class paint;
}
QT_END_NAMESPACE

class paint : public QMainWindow
{
    Q_OBJECT

public:
    explicit paint(QWidget *parent = nullptr);
    ~paint();

private:
    Ui::paint *ui;
    QTimer * timer;

    paintScene * scene;

private:
    void resizeEvent(QResizeEvent * event);

private slots:
    void slotTimer();
    void on_actioncolor_triggered();
    void on_actionsquare_triggered();
    void on_actionoval_triggered();
    void on_actionromb_triggered();
    void on_actionsave_triggered();
    void on_actionopen_triggered();
    void on_actionnew_triggered();
};
#endif // PAINT_H
