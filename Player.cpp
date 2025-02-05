
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

#include <QGraphicsScene>
#include <QThread>
#include <QTimer>


Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent) {
    QPixmap pixmap(":/images/player.png");
    setPixmap(pixmap.scaled(70, 70, Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left){
        if(pos().x()>0)
        setPos(x()-20,y());
    }
    else if(event->key() == Qt::Key_Right){
        if(pos().x() + 100 < 800)
        setPos(x()+20,y());
    }
    else if(event->key() == Qt::Key_Space){
        Bullet *bullet = new Bullet();
        bullet->setPos(x(),y());
        scene()->addItem(bullet);
        //QThread::msleep(10);
    }

}

void Player::spawn()
{
    // Create an Enemy
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);

}
