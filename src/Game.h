#pragma once

#include <QtCore/QObject>
#include <QtWidgets/QGraphicsScene>
#include <QtCore/QTimer>
#include <QKeyEvent>

#include "Bird.h"

class Game: public QObject
{
Q_OBJECT
private:
    QGraphicsScene& scene;
    Bird* bird = nullptr;
    QTimer mainLoopTimer;
    int loopCounter = 0;
    int score = -4;
    QGraphicsTextItem *textScore = scene.addText("0");

protected slots:
    void loop_slot();

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;
    void keyPressEvent( QKeyEvent* event );

public:
    Game(QGraphicsScene &scene);


};
