
#include "Health.h"
#include "qfont.h"

Health::Health(QGraphicsTextItem *parent) : QGraphicsTextItem(parent)
{
    health = 3;

    setPlainText(QString("Health: ") + QString::number(health));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));

}

void Health::decrease()
{
    health--;
    setPlainText(QString("Health: ") + QString::number(health));
}

int Health::getHealth()
{
    return health;
}
