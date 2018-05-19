#include <QPainter>
#include <QTime>
#include "Snake.h"
#include "ui_snake.h"

Snake::Snake(QWidget *parent) :
    QWidget(parent)
{
    //    ui->setupUi(this);


    setStyleSheet("background-color:black;");
    leftDirection = false;
    rightDirection = false;
    upDirection = false;
    downDirection = false;
    inGame = true;

    resize(B_WIDTH, B_HEIGHT);

    loadImages();
    initGame();
}

Snake::~Snake()
{
    //    delete ui;
}

void Snake::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);

    doDrawing();
}

void Snake::timerEvent(QTimerEvent *e)
{
    Q_UNUSED(e);

    if (inGame) {
        checkApple();
        checkCollision();
        move();
    }

    repaint();
}

void Snake::keyPressEvent(QKeyEvent *e)
{
    int key = e->key();

    if ((key == Qt::Key_Left) && (!rightDirection)) {
        leftDirection = true;
        upDirection = false;
        downDirection = false;
    }

    if ((key == Qt::Key_Right) && (!leftDirection)) {
        rightDirection = true;
        upDirection = false;
        downDirection = false;
    }

    if ((key == Qt::Key_Up) && (!downDirection)) {
        upDirection = true;
        leftDirection = false;
        rightDirection = false;
    }

    if ((key == Qt::Key_Down) && (!upDirection)) {
        downDirection = true;
        leftDirection = false;
        rightDirection = false;
    }

    QWidget::keyPressEvent(e);
}

void Snake::loadImages()
{
    dot.load("dot.svg");
    head.load("head.svg");
    apple.load("apple.svg");
}

void Snake::initGame()
{
    dots = 4;
    for (int z = 0; z < dots; z ++) {
        x[z] = 50 - z * 10;
        y[z] = 50;
    }

    locateApple();
    timerId = startTimer(DELAY);
}

void Snake::locateApple()
{
    QTime time = QTime::currentTime();
    qsrand((uint) time.msec());

    int r = qrand() % RAND_POS;
    apple_x = (r * DOT_SIZE);

    r = qrand() % RAND_POS;
    apple_y = (r * DOT_SIZE);
}

void Snake::checkApple()
{
    if ((x[0] == apple_x) && (y[0] == apple_y)) {
        dots++;
        locateApple();
    }
}

void Snake::checkCollision()
{
    for (int z = dots; z > 0; z--) {
        if ((z > 4) && (x[0] == x[z]) && (y[0] == y[z])) {
            inGame = false;
        }
    }

    //    if ((y[0] >= B_HEIGHT) || (y[0] < 0) || (x[0] >= B_WIDTH) || (x[0] < 0)) {
    //        inGame = false;
    //    }

    if (y[0] >= B_HEIGHT) {
        y[0] = 0;
    }

    if (y[0] < 0) {
        y[0] = B_HEIGHT - 1;
    }

    if (x[0] >= B_WIDTH) {
        x[0] = 0;
    }

    if (x[0] < 0) {
        x[0] = B_WIDTH - 1;
    }

    if (!inGame) {
        killTimer(timerId);
    }

}

void Snake::move()
{
    for (int z = dots; z > 0; z--) {
        x[z] = x[(z-1)];
        y[z] = y[(z-1)];
    }

    if (leftDirection) {
        x[0] -= DOT_SIZE;
    }

    if (rightDirection) {
        x[0] += DOT_SIZE;
    }

    if (upDirection) {
        y[0] -= DOT_SIZE;
    }

    if (downDirection) {
        y[0] += DOT_SIZE;
    }
}

void Snake::doDrawing()
{
    QPainter qp(this);

    if (inGame) {
        qp.drawImage(apple_x, apple_y, apple);

        for (int z = 0; z < dots; z++) {
            if (z == 0) {
                qp.drawImage(x[z], y[z], head);
            } else {
                qp.drawImage(x[z], y[z], dot);
            }
        }
    } else {
        gameOver(qp);
    }
}

void Snake::gameOver(QPainter &qp)
{
    QString mess = "Game over";
    QFont font("Courier", 15, QFont::DemiBold);
    QFontMetrics fm(font);

    int textWidth = fm.width(mess);
    qp.setFont(font);
    qp.setPen("white");
    int h = height();
    int w = width();

    qp.translate(QPoint(w/2, h/2));
    qp.drawText(-textWidth/2, 0, mess);

}
