#ifndef WHITEBOARD_H
#define WHITEBOARD_H

#include <QWidget>
#include <QTimer>
#include <QResizeEvent>
#include "scene.h"

namespace Ui {
class Whiteboard;
}

class Whiteboard : public QWidget
{
    Q_OBJECT

public:
    explicit Whiteboard(QWidget *parent = 0);
    ~Whiteboard();

private:
    Ui::Whiteboard *ui;
    QTimer *timer;      //timer for scene resize
    Scene *scene;

    void resizeEvent(QResizeEvent * event);

private slots:
    void Timer();
    void on_typeLine_currentIndexChanged(int index);
    void on_horizontalSlider_valueChanged(int value);
    void on_spinBox_valueChanged(int value);
    void on_clear_clicked();
    void on_undo_clicked();
    void on_redo_clicked();
    void clear_enable();
    void redo_unable();

    //colors managment can be implemented
    //with QPalette
    void on_black_clicked();
    void on_l_grey_clicked();
    void on_blue_clicked();
    void on_sea_clicked();
    void on_green_clicked();
    void on_d_green_clicked();
    void on_d_red_clicked();
    void on_violet_clicked();
    void on_grey_clicked();
    void on_white_clicked();
    void on_l_blue_clicked();
    void on_cyan_clicked();
    void on_l_green_clicked();
    void on_yellow_clicked();
    void on_red_clicked();
    void on_pink_clicked();
};

#endif
