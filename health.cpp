#include "health.h"
#include <QFont>


Health::Health(QGraphicsTextItem *parent): QGraphicsTextItem (parent)
{
    // initialize the score to zero
    health = 3;

    //draw the text
    setPlainText("Health: " + QString::number(health)); // Health: 3
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Health::decrease()
{
    health--;
    setPlainText("Health: " + QString::number(health)); // Health: 2
}

int Health::getHealth()
{
    return health;
}
