#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include "game.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QMessageBox>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    Game* game;
    QTimer* timer;
    QTimer* timerUnit;
    QPushButton* btnOrc;
    QPushButton* btnGoblin;
    QPushButton* btnBarricade;
    QLabel* labelGold;

    QMessageBox startMessage;
    QMessageBox winMessage;
    QMessageBox loseMessage;

    void displayGold();

    void setLabelGold();
    void setStartMessage();
    void setWinMessage();
    void setLoseMessage();

    void paintEvent(QPaintEvent* e);
    void mousePressEvent(QMouseEvent *e);
    void stopGame();

private slots:
    void gameUpdate();
    void createUnit();
    void btnOrcClicked();
    void btnGoblinClicked();
    void btnBarricadeClicked();
    void victory();
};

#endif // WIDGET_H
