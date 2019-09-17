#include "score.h"
#include <QFont>


Score::Score(QGraphicsTextItem *parent): QGraphicsTextItem (parent)
{
    // initialize the score to zero
    score = 0;

    //draw the text
    setPlainText("Score: " + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Score::increase()
{
    score++;
    setPlainText("Score: " + QString::number(score)); // Score: 1
}

int Score::getScore()
{
    return score;
}
