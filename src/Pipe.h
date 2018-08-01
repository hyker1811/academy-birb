#pragma once

#include <QtWidgets/QGraphicsItem>
#include <QPainter>

class Pipe: public QGraphicsItem
{
private:
    QRectF pipeShape;

public:
    Pipe(qreal height);
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void advance(int step);
};
