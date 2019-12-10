#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QMouseEvent>
#include <QLabel>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    setFixedSize(1600, 900);
    setLabelGold();

    btnOrc = new QPushButton(this);
    btnGoblin = new QPushButton(this);
    btnBarricade = new QPushButton(this);
    btnOrc->setText("Orc");
    btnGoblin->setText("Goblin");
    btnBarricade->setText("Barricade");

    btnOrc->setGeometry(0, 800, 400, 100);
    btnGoblin->setGeometry(400, 800, 400, 100);
    btnBarricade->setGeometry(800, 800, 400, 100);
    btnOrc->setFont(QFont("Helvetica", 26, QFont::Bold));
    btnGoblin->setFont(QFont("Helvetica", 26, QFont::Bold));
    btnBarricade->setFont(QFont("Helvetica", 26, QFont::Bold));

    connect(btnOrc, SIGNAL(clicked()), this, SLOT(btnOrcClicked()));
    connect(btnGoblin, SIGNAL(clicked()), this, SLOT(btnGoblinClicked()));
    connect(btnBarricade, SIGNAL(clicked()), this, SLOT(btnBarricadeClicked()));

    game = &this->game->getInstance();

    timer = new QTimer();
    timerUnit = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(gameUpdate()));
    connect(timerUnit, SIGNAL(timeout()), this, SLOT(createUnit()));

    setStartMessage();
}

Widget::~Widget()
{
    delete ui;
    delete timer;
    delete timerUnit;
    delete btnOrc;
    delete btnGoblin;
    delete btnBarricade;
}

void Widget::displayGold()
{
    labelGold->setText(QString("Gold: ") + QString::number(game->getGold()));
}

void Widget::setLabelGold()
{
    labelGold = new QLabel(this);
    labelGold->setGeometry(1200, 800, 400, 100);
    labelGold->setAlignment(Qt::AlignCenter);
    QFont font("Helvetica", 26, QFont::Bold);
    labelGold->setFont(font);
}

void Widget::setStartMessage()
{
    startMessage.setText("My leader! The knights are coming back."
                         " This time they decided to attack us with rams and catapults. "
                         "We must show them once and for all, whose lands these are! Raise the barricades!");
    startMessage.addButton(QMessageBox::Ok);

    int action = startMessage.exec();
    switch (action) {
    case QMessageBox::Ok:
    {
        timer->start(20);
        timerUnit->start(10000);
        break;
    }
    default:
        break;
    }
}

void Widget::setWinMessage()
{
    winMessage.setText("VICTORY!\n.............................................................\n"
                       "My leader! You have once again proved that it is not "
                       "for nothing that you stand at the head of our tribe. "
                       "Knights scattered in fear, hiding behind the remnants "
                       "of their stumps! Glory to the great leader!");
    winMessage.addButton(QMessageBox::Close);

    timer->stop();
    timerUnit->stop();
    int action = winMessage.exec();
    switch (action) {
    case QMessageBox::Close:
    {      
        this->close();
        break;
    }
    default:
        break;
    }
}

void Widget::setLoseMessage()
{
    winMessage.setText("DEFEAT!\n.............................................................\n"
                       "Who could doubt that we, the glorious knights of the king,"
                       " will mix the damned orcs with mud! Today we will get home "
                       "with a victory. Long life to the king!\n"
                       "...............................................................\n"
                       "...and somewhere far away from here other clans of orcs are coming together."
                       " They will be able to avenge us. \nThey say that the one who leads them can hear the spirits ...");
    winMessage.addButton(QMessageBox::Close);

    timer->stop();
    timerUnit->stop();

    int action = winMessage.exec();
    switch (action) {
    case QMessageBox::Close:
    {
        this->close();
        break;
    }
    default:
        break;
    }
}

void Widget::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QPainter painter(this);
    game->drawGame(&painter);
}

void Widget::mousePressEvent(QMouseEvent *e)
{
    int x = e->x();
    int y = e->y();

    if (e->button() == Qt::LeftButton)
    {
        game->setClickCoordinates(x, y);
        game->createUnit();
    }
    else if (e->button() == Qt::RightButton)
    {
        game->setTargetCoordinates(x, y);
    }
}

void Widget::stopGame()
{
    if (game->citadelFallen())
    {
        setLoseMessage();
    }
}

void Widget::gameUpdate()
{
    game->setTarget();
    game->moveObjects();
    game->attack();
    game->killUnit();
    game->removeUnit();
    displayGold();
    stopGame();
    update();
}

void Widget::createUnit()
{
    game->createEnemies();
}

void Widget::btnOrcClicked()
{
    game->placeOrc();
}

void Widget::btnGoblinClicked()
{
    game->placeGoblin();
}

void Widget::btnBarricadeClicked()
{
    game->placeBarricade();
}

void Widget::victory()
{
    setWinMessage();
}
