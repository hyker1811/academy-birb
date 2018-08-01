#include "Bird.h"

Bird::Bird() {}

void Bird::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap flappy("sprite.png");
    flappy.scaled(QSize(40,40), Qt::KeepAspectRatio);
    painter->drawPixmap(0,0,40,40, flappy);
}

QRectF Bird::boundingRect() const
{
    QRectF rect(0,0,40,40);
    return rect;
}

QPainterPath Bird::shape() const
{
    QPainterPath path;
    path.addEllipse(0,0,40,40);
    return path;
}

void Bird::advance(int step)
{
    if(!step) return;

    setPos(mapToParent(0,5));

}
