#include <QtWidgets>

#include <iostream>
#include "Bird.h"
#include "Pipe.h"
#include "Game.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    qDebug() << "Started...";

    QGraphicsView view;
    view.setWindowTitle("Flappy bird");

    view.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view.setFixedSize(600, 600);

    view.setBackgroundBrush(QPixmap("clouds.jpg"));

    QGraphicsScene scene;
    scene.setItemIndexMethod(QGraphicsScene::NoIndex);
    scene.setSceneRect(view.geometry());

    view.setScene(&scene);
    view.show();

    Game game(scene);
    app.installEventFilter(&game);

    return app.exec();
}