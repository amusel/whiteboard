#include "whiteboard.h"
#include "ui_whiteboard.h"

Whiteboard::Whiteboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Whiteboard)
{
    ui->setupUi(this);
    scene = new Scene();                //add scene
    ui->graphicsView->setScene(scene);

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &Whiteboard::Timer);
    timer->start(100);

    //enable clear after first item add
    //unable redo after item add
    connect(scene, SIGNAL(clear_emit()),this, SLOT(clear_enable()));
    connect(scene, SIGNAL(redo_emit()),this, SLOT(redo_unable()));
}

Whiteboard::~Whiteboard()
{
    delete ui;
}

void Whiteboard::Timer()
{
    timer->stop();
    scene->setSceneRect(0,0, ui->graphicsView->width(), ui->graphicsView->height());
}

void Whiteboard::resizeEvent(QResizeEvent *event)
{
    timer->start(100);
    QWidget::resizeEvent(event);
}

void Whiteboard::on_horizontalSlider_valueChanged(int value)
{
    scene->size = value;
    ui->spinBox->setValue(value);
}

void Whiteboard::on_spinBox_valueChanged(int value)
{
    scene->size = value;
    ui->horizontalSlider->setValue(value);
}

void Whiteboard::on_typeLine_currentIndexChanged(int index)
{
    scene->type = index;
}

void Whiteboard::on_clear_clicked()
{
    scene->clear();                 //undo,redo,clear set unable
    scene->undo_items.clear();
    scene->redo_items.clear();
    ui->undo->setEnabled(false);
    ui->redo->setEnabled(false);
    ui->clear->setEnabled(false);
    scene->update();
}

void Whiteboard::clear_enable()
{
    ui->clear->setEnabled(true);
    ui->undo->setEnabled(true);
}

void Whiteboard::redo_unable()
{
    ui->redo->setEnabled(false);
    scene->redo_items.clear();
}

void Whiteboard::on_undo_clicked()
{
    if (!scene->undo_items.isEmpty())       //just to be sure
    {
        scene->redo_items.push(scene->undo_items.top());
        scene->removeItem(scene->undo_items.top());
        scene->undo_items.pop();
        ui->redo->setEnabled(true);
    }

    if (scene->undo_items.isEmpty())    //set unable if it was last item
        ui->undo->setEnabled(false);
    scene->update();
}

void Whiteboard::on_redo_clicked()
{
    if (!scene->redo_items.isEmpty())       //just to be sure
    {
        scene->addItem(scene->redo_items.top());
        scene->undo_items.push(scene->redo_items.top());
        scene->redo_items.pop();
        ui->undo->setEnabled(true);
    }

    if (scene->redo_items.isEmpty())    //set unable if it was last item
        ui->redo->setEnabled(false);
    scene->update();
}
