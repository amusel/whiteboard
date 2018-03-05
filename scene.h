#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QStack>

class Scene : public QGraphicsScene
{

    Q_OBJECT

public:
    int size,type;  //of current object
    QColor color;
    QStack<QGraphicsItem*> undo_items, redo_items;
    //QT undo/redo framework can be used instead
    //of QStack items

    explicit Scene(QObject *parent = 0);
    ~Scene();

private:
    QPainterPath    path;   //path item for curve
    QPointF         prev;   //previous  point

private slots:
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

signals:
    void clear_emit();
    void redo_emit();
};

#endif // SCENE_H
