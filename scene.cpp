#include "scene.h"

Scene::Scene(QObject *parent) : QGraphicsScene(parent)
{
    size=4;             //standart parameters
    color= Qt::black;
    type = 1;
}

Scene::~Scene()
{}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    undo_items.push(items()[0]);    //saving every item in stack
    redo_emit();
    if (items().size() > 0)
        emit clear_emit();

    path = QPainterPath();  //del old path
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //add ellipse on click
    addEllipse(event->scenePos().x(),
               event->scenePos().y(),
               size,
               size,
               QPen(Qt::NoPen),
               QBrush(color));

    prev = event->scenePos();       //save start point
}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (type != 1)
        removeItem(items()[0]);     //deleting previous item
                                    //until mouse release
    if (type == 0)          //line
    {
        addLine(prev.x(),
                prev.y(),
                event->scenePos().x(),
                event->scenePos().y(),
                QPen(color,size,Qt::SolidLine,Qt::SquareCap));
        update();
    }
    else if  (type == 1)    //curve
    {
        path.moveTo(prev);
        path.lineTo(event->scenePos().x(),event->scenePos().y());
        removeItem(items()[0]);
        addPath(path, QPen(color,size,Qt::SolidLine,Qt::SquareCap));
        prev = event->scenePos();
        update();
    }
    else if (type == 2)      //rectangle
    {
        addRect(prev.x(),prev.y(),
                event->scenePos().x()-prev.x(),
                event->scenePos().y()-prev.y(),
            QPen(color,size,Qt::SolidLine,Qt::SquareCap));
        update();
    }
    else if (type == 3)     //ellipse
    {
        addEllipse(prev.x(),prev.y(),
            event->scenePos().x()-prev.x(),
            event->scenePos().y()-prev.y(),
            QPen(color,size,Qt::SolidLine,Qt::SquareCap));
        update();
    }
}
