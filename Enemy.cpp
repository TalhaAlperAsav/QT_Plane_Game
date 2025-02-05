
#include "Enemy.h"
#include "Game.h"

#include <stdlib.h> // rand() for really big integer

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    // Setting Random Location
    int random_number = rand() % 700;
    setPos(random_number,0);
    // Drawing
    QPixmap pixmap(":/images/enemy.png");
    setPixmap(pixmap.scaled(70, 70, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    // Connecting
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);

}

void Enemy::move()
{
    // moving the enemy down
    setPos(x(),y()+5);
    // deleting the bullets that passed the view
    if(pos().y()>600){
        // decreasing the health
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }
}
