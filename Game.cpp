#include <QApplication>
#include <QGraphicsScene>
#include "Player.h"
#include "Game.h"
#include <QGraphicsView>
#include <QTimer>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QBrush>
#include <QImage>

Game::Game(QWidget *parent){
    // Creating the scene
    scene = new QGraphicsScene();
    // Making the Game 800x600
    scene->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage(":/images/background.png")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    // Create the player
    player = new Player();
    player->setPos(400,500);
    // Make the player focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    // Create the score/health
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

    // Spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    // Playing Background Music
    QMediaPlayer *music = new QMediaPlayer();
    QAudioOutput *audio = new QAudioOutput();
    music->setAudioOutput(audio);
    music->setSource(QUrl("qrc:/sounds/Age of War - Theme Soundtrack.mp3"));
    audio->setVolume(15);
    music->play();
}
