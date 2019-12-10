#ifndef GAME_H
#define GAME_H

#include "citadel.h"
#include "barricadefactory.h"
#include "catapultfactory.h"
#include "goblinfactory.h"
#include "knightfactory.h"
#include "orcfactory.h"
#include "ramfactory.h"
#include <vector>

class Game
{
public:
    static Game& getInstance();
    void drawGame(QPainter*);
    void moveObjects();
    void attack();

    void setClickCoordinates(int x, int y);
    void setTargetCoordinates(int x, int y);
    void *setTarget();

    StaticObject *setOrcAttackTarget(MovingObject* orc);
    StaticObject *setGoblinAttackTarget(MovingObject* goblin);
    StaticObject *setKnightAttackTarget(MovingObject* knight);
    StaticObject *setRamAttackTarget(MovingObject* ram);
    StaticObject *setCatapultAttackTarget(MovingObject* catapult);

    void placeOrc();
    void placeGoblin();
    void placeBarricade();

    void createUnit();
    void createEnemies();

    void setUnitID(int value);

    void killUnit();
    void removeUnit();

    bool citadelFallen();

    int getGold() const;

private:
    Game();
    ~Game();
    Game(const Game& rhs) = delete;
    Game& operator=(const Game& rhs) = delete;

    Citadel* citadel;

    int clickX, clickY;
    int targetX, targetY;
    int unitID;

    int gold;
    const int price = 20;

    BarricadeFactory* barricadeFactory;
    CatapultFactory* catapultFactory;
    GoblinFactory* goblinFactory;
    KnightFactory* knightFactory;
    OrcFactory* orcFactory;
    RamFactory* ramFactory;

    std::vector<MovingObject*> gameMovingObjects;
    std::vector<StaticObject*> gameObjects;
    std::vector<MovingObject*> gameEnemies;

    std::vector<MovingObject*> gameOrcs;
    std::vector<MovingObject*> gameGoblins;
    std::vector<StaticObject*> gameBarricades;
    std::vector<MovingObject*> gameKnights;
    std::vector<MovingObject*> gameCatapults;
    std::vector<MovingObject*> gameRams;
};

#endif // GAME_H
