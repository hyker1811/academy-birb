#include <QtCore/QEvent>
#include <QtCore/QCoreApplication>
#include "Game.h"
#include "Pipe.h"

Game::Game(QGraphicsScene &scene): scene(scene)
{
    bird = new Bird();
    bird->setPos(0,300);
    scene.addItem(bird);
    textScore->setPos(0,550);
    textScore->setPlainText("0");
  //
//    double pipeHeight = 200;
//    auto* pipe1 = new Pipe(pipeHeight);
//    auto* pipe2 = new Pipe(600 - pipeHeight - 200);
//
//    scene.addItem(pipe1);
//    scene.addItem(pipe2);
//
//    pipe1->setPos(540, pipeHeight);
//    pipe2->setPos( 540, 600 - pipeHeight);

    QObject::connect(&mainLoopTimer, &QTimer::timeout, this, &Game::loop_slot);

    mainLoopTimer.start(1000/33);
}

void Game::loop_slot()
{
    if( !bird->collidingItems().isEmpty() || bird->y() > scene.height() )
    {
        mainLoopTimer.stop();
        scene.removeItem(bird);
        QGraphicsTextItem *text;
        if(score < 0){
            text = scene.addText(" DEAD\nSCORE: 0" );
        }
        else{
            text = scene.addText(" DEAD\nSCORE: " + QString::number(score) );
        }
        text->setPos( 230, 250 );
        text->setScale(2);
    }


    if(loopCounter % 20 == 0 )
    {
        int random = rand() % (250-150 + 1) + 150 ;
        double pipeHeight = random;
        auto* pipe1 = new Pipe(pipeHeight);
        auto* pipe2 = new Pipe(600 - pipeHeight - 200);

        scene.addItem(pipe1);
        scene.addItem(pipe2);

        pipe1->setPos(540, 0);
        pipe2->setPos(540, pipeHeight + 200);
        loopCounter = 0;
        if(score >= 0) textScore->setPlainText( QString::number(score));
        score++;
    }
    loopCounter++;

    scene.advance();
}

bool Game::eventFilter(QObject *watched, QEvent *event)
{
    Q_UNUSED(watched);
    if(event->type() == QEvent::KeyPress)
    {
        keyPressEvent( (QKeyEvent*) event );
        return true;
    }
    else
    {
        return false;
    }
}

void Game::keyPressEvent(QKeyEvent* event)
{
    if(event->isAutoRepeat()) return;

    switch(event->key())
    {
        case Qt::Key_Space :
            bird->setY(bird->y() - bird->boundingRect().height() * 1.8);
            break;
        default:
            break;
    }
}
