
#include "Bullet.h"
#include "Enemy.h"
#include "Game.h"

extern Game *game; // External global object

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    // Drawing the bullet
    setPixmap(QPixmap(":/images/bullet.png"));
    // Connectting
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);

}

void Bullet::move()
{

    // If the Bullet collides
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; i++){
        if(typeid(*(colliding_items[i])) == typeid(Enemy)){
            // Increasing the Score
            game->score->increase();
            // Removing both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            // Delete them both
            delete colliding_items[i];
            delete this;
            return;
        }

    }

    // moving the bullet up
    setPos(x(),y()-10);
    // deleting the bullets that passed the view
    if(pos().y()<0){
        scene()->removeItem(this);
        delete this;
    }
}
