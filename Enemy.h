#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QGraphicsScene>

class Enemy: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy(QGraphicsItem * parent=0);
public slots:
    void move();
};

#endif // ENEMY_H
