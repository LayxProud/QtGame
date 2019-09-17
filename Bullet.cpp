#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include "game.h"

extern Game * game; // there is an external global object called name

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(){
    // draw graphics
    setPixmap(QPixmap(":/image/img/bullet.png"));

    // connect
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Bullet::move()
{
    // get a list of all the items currently colliding with this bullet
    QList<QGraphicsItem *> colliding_items = collidingItems();

    //if bullet collides with enemy, destroy both
    for (int i = 0, n = colliding_items.size(); i < n; ++i) {
        if (typeid(*(colliding_items[i])) == typeid(Enemy)) {
            // increase the score
            game->score->increase();

            // remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            // delete them both
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    // move bullet up
    setPos(x(),y()-10);
    // if the bullet is off the screen - destroy it
    if (pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
