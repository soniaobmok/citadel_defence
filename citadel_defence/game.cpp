#include "game.h"
#include <QMouseEvent>
#include <algorithm>

Game& Game::getInstance() {
    static Game game;
    return game;
}

Game::Game()
{
    citadel = new Citadel(15, 110, QPixmap(":/textures/citadel.png"));
    gameObjects.push_back(citadel);

    barricadeFactory = new BarricadeFactory();
    catapultFactory = new CatapultFactory();
    goblinFactory = new GoblinFactory();
    knightFactory = new KnightFactory();
    orcFactory = new OrcFactory();
    ramFactory = new RamFactory();

    clickX = -1;
    clickY = -1;
    targetX = -1;
    targetY = -1;
    unitID = -1;
    gold = 100;
}

Game::~Game()
{
    if (!gameObjects.empty())
        for(auto obj: gameObjects)
            delete obj;

    delete barricadeFactory;
    delete catapultFactory;
    delete goblinFactory;
    delete knightFactory;
    delete orcFactory;
    delete ramFactory;
}

int Game::getGold() const
{
    return gold;
}

void Game::setUnitID(int value)
{
    unitID = value;
}

void Game::killUnit()
{
    for (auto obj: gameObjects)
    {
        if (obj->getHp() <= 0)
        {
            if (std::find(gameEnemies.begin(), gameEnemies.end(), obj) != gameEnemies.end())
            {
                gold += price;
            }
            obj->setIsAlive(false);
        }
    }
}

void Game::removeUnit()
{
    for (auto obj: gameObjects)
    {
        if (!obj->getIsAlive() && std::find(gameObjects.begin(), gameObjects.end(), obj) != gameObjects.end())
        {
            gameObjects.erase(std::remove(gameObjects.begin(), gameObjects.end(), obj), gameObjects.end());
        }
    }
    for (auto obj: gameMovingObjects)
    {
        if (!obj->getIsAlive() && std::find(gameMovingObjects.begin(), gameMovingObjects.end(), obj) != gameMovingObjects.end())
        {
            gameMovingObjects.erase(std::remove(gameMovingObjects.begin(), gameMovingObjects.end(), obj), gameMovingObjects.end());
        }
    }
    for (auto obj: gameEnemies)
    {
        if (!obj->getIsAlive() && std::find(gameEnemies.begin(), gameEnemies.end(), obj) != gameEnemies.end())
        {
            gameEnemies.erase(std::remove(gameEnemies.begin(), gameEnemies.end(), obj), gameEnemies.end());
        }
    }
    for (auto obj: gameOrcs)
    {
        if (!obj->getIsAlive() && std::find(gameOrcs.begin(), gameOrcs.end(), obj) != gameOrcs.end())
        {
            gameOrcs.erase(std::remove(gameOrcs.begin(), gameOrcs.end(), obj), gameOrcs.end());
        }
    }
    for (auto obj: gameGoblins)
    {
        if (!obj->getIsAlive() && std::find(gameGoblins.begin(), gameGoblins.end(), obj) != gameGoblins.end())
        {
            gameGoblins.erase(std::remove(gameGoblins.begin(), gameGoblins.end(), obj), gameGoblins.end());
        }
    }
    for (auto obj: gameBarricades)
    {
        if (!obj->getIsAlive() && std::find(gameBarricades.begin(), gameBarricades.end(), obj) != gameBarricades.end())
        {
            gameBarricades.erase(std::remove(gameBarricades.begin(), gameBarricades.end(), obj), gameBarricades.end());
        }
    }
    for (auto obj: gameKnights)
    {
        if (!obj->getIsAlive() && std::find(gameKnights.begin(), gameKnights.end(), obj) != gameKnights.end())
        {
            gameKnights.erase(std::remove(gameKnights.begin(), gameKnights.end(), obj), gameKnights.end());
        }
    }
    for (auto obj: gameCatapults)
    {
        if (!obj->getIsAlive() && std::find(gameCatapults.begin(), gameCatapults.end(), obj) != gameCatapults.end())
        {
            gameCatapults.erase(std::remove(gameCatapults.begin(), gameCatapults.end(), obj), gameCatapults.end());
        }
    }
    for (auto obj: gameRams)
    {
        if (!obj->getIsAlive() && std::find(gameRams.begin(), gameRams.end(), obj) != gameRams.end())
        {
            gameRams.erase(std::remove(gameRams.begin(), gameRams.end(), obj), gameRams.end());
        }
    }
}

bool Game::citadelFallen()
{
    if (!citadel->getIsAlive())
        return true;
    return false;
}

void Game::drawGame(QPainter* painter)
{
    painter->drawPixmap(0, 0, QPixmap(":/textures/background.png"));
    for (auto obj: gameObjects)
    {
        obj->draw(painter);
    }
}

void Game::moveObjects()
{
    for (auto obj: gameMovingObjects)
    {
        if (obj->getIsMoving())
        {
            obj->move(obj->getMoveTarget());
        }
    }
}

void Game::attack()
{
    for (auto obj: gameOrcs)
    {
        obj->damageAt(setOrcAttackTarget(obj));
    }
    for (auto obj: gameGoblins)
    {
        obj->damageAt(setGoblinAttackTarget(obj));
    }
    for (auto obj: gameKnights)
    {
        obj->damageAt(setKnightAttackTarget(obj));
    }
    for (auto obj: gameCatapults)
    {
        obj->damageAt(setCatapultAttackTarget(obj));
    }
    for (auto obj: gameRams)
    {
        obj->damageAt(setRamAttackTarget(obj));
    }
}

void Game::setClickCoordinates(int x, int y)
{
    clickX = x;
    clickY = y;
}

void Game::setTargetCoordinates(int x, int y)
{
    targetX = x;
    targetY = y;
}

void *Game::setTarget()
{
    for (auto obj: gameEnemies)
    {
        obj->setMoveTarget(citadel->getX(), citadel->getY());
    }
    for (auto obj: gameOrcs)
    {
        obj->setMoveTarget(targetX, targetY);
    }
}

StaticObject *Game::setOrcAttackTarget(MovingObject* orc)
{
    std::vector<int> distances;
    int dist;
    int minDist = 10000;
    for (auto enemy: gameEnemies)
    {
        dist = static_cast<int>(sqrt((orc->getX() - enemy->getX()) * (orc->getX() - enemy->getX()) +
                                                     (orc->getY() - enemy->getY()) * (orc->getY() - enemy->getY())));
        distances.push_back(dist);
        if (dist <= minDist)
        {
            minDist = dist;
        }
    }

    for (unsigned int i = 0; i < distances.size(); i++)
    {
        if (distances[i] == minDist)
            return gameEnemies[i];
    }
}

StaticObject *Game::setGoblinAttackTarget(MovingObject *goblin)
{
    std::vector<int> distances;
    int dist;
    int minDist = 10000;
    for (auto enemy: gameEnemies)
    {
        dist = static_cast<int>(sqrt((goblin->getX() - enemy->getX()) * (goblin->getX() - enemy->getX()) +
                                                     (goblin->getY() - enemy->getY()) * (goblin->getY() - enemy->getY())));
        distances.push_back(dist);
        if (dist <= minDist)
        {
            minDist = dist;
        }
    }

    for (unsigned int i = 0; i < distances.size(); i++)
    {
        if (distances[i] == minDist)
            return gameEnemies[i];
    }
}

StaticObject *Game::setKnightAttackTarget(MovingObject *knight)
{
    std::vector<int> distancesToOrcs;
    std::vector<int> distancesToGoblins;
    std::vector<int> distancesToBarricades;
    int distanceToCitadel = static_cast<int>(sqrt((knight->getX() - citadel->getX()) * (knight->getX() - citadel->getX()) +
                                                  (knight->getY() - citadel->getY()) * (knight->getY() - citadel->getY())));;
    int dist;
    int minDistOrc = 10000;
    int minDistGoblin = 10000;
    int minDistBarricade = 10000;

    for (auto orc: gameOrcs)
    {
        dist = static_cast<int>(sqrt((knight->getX() - orc->getX()) * (knight->getX() - orc->getX()) +
                                                     (knight->getY() - orc->getY()) * (knight->getY() - orc->getY())));
        distancesToOrcs.push_back(dist);
        if (dist <= minDistOrc)
        {
            minDistOrc = dist;
        }
    }
    for (auto goblin: gameGoblins)
    {
        dist = static_cast<int>(sqrt((knight->getX() - goblin->getX()) * (knight->getX() - goblin->getX()) +
                                                     (knight->getY() - goblin->getY()) * (knight->getY() - goblin->getY())));
        distancesToGoblins.push_back(dist);
        if (dist <= minDistGoblin)
        {
            minDistGoblin = dist;
        }
    }
    for (auto barr: gameBarricades)
    {
        dist = static_cast<int>(sqrt((knight->getX() - barr->getX()) * (knight->getX() - barr->getX()) +
                                                     (knight->getY() - barr->getY()) * (knight->getY() - barr->getY())));
        distancesToBarricades.push_back(dist);
        if (dist <= minDistBarricade)
        {
            minDistBarricade = dist;
        }
    }

    if(minDistGoblin <= minDistOrc && minDistGoblin <= distanceToCitadel && minDistGoblin <= minDistBarricade)
    {
        for (unsigned int i = 0; i < distancesToGoblins.size(); i++)
        {
            if (distancesToGoblins[i] == minDistGoblin)
                return gameGoblins[i];
        }
    }
    else if (minDistOrc <= minDistGoblin && minDistOrc <= distanceToCitadel && minDistOrc <= minDistBarricade)
    {
        for (unsigned int i = 0; i < distancesToOrcs.size(); i++)
        {
            if (distancesToOrcs[i] == minDistOrc)
                return gameOrcs[i];
        }
    }
    else if (minDistBarricade <= minDistGoblin && minDistBarricade <= distanceToCitadel && minDistBarricade <= minDistOrc)
    {
        for (unsigned int i = 0; i < distancesToBarricades.size(); i++)
        {
            if (distancesToBarricades[i] == minDistBarricade)
                return gameBarricades[i];
        }
    }
    else if (distanceToCitadel <= minDistGoblin && distanceToCitadel <= minDistOrc && distanceToCitadel <= minDistBarricade)
    {
        return citadel;
    }
}

StaticObject *Game::setRamAttackTarget(MovingObject *ram)
{
    std::vector<int> distancesToBarricades;
    int distanceToCitadel = static_cast<int>(sqrt((ram->getX() - citadel->getX()) * (ram->getX() - citadel->getX()) +
                                                  (ram->getY() - citadel->getY()) * (ram->getY() - citadel->getY())));;
    int dist;
    int minDistBarricade = 10000;
    for (auto barr: gameBarricades)
    {
        dist = static_cast<int>(sqrt((ram->getX() - barr->getX()) * (ram->getX() - barr->getX()) +
                                                     (ram->getY() - barr->getY()) * (ram->getY() - barr->getY())));
        distancesToBarricades.push_back(dist);
        if (dist <= minDistBarricade)
        {
            minDistBarricade = dist;
        }
    }

    if(minDistBarricade <= distanceToCitadel)
    {
        for (unsigned int i = 0; i < distancesToBarricades.size(); i++)
        {
            if (distancesToBarricades[i] == minDistBarricade)
                return gameBarricades[i];
        }
    }
    else if (distanceToCitadel < minDistBarricade)
    {
        return citadel;
    }
}

StaticObject *Game::setCatapultAttackTarget(MovingObject *catapult)
{
    std::vector<int> distancesToBarricades;
    std::vector<int> distancesToGoblins;
    int distanceToCitadel = static_cast<int>(sqrt((catapult->getX() - citadel->getX()) * (catapult->getX() - citadel->getX()) +
                                                  (catapult->getY() - citadel->getY()) * (catapult->getY() - citadel->getY())));;
    int dist;
    int minDistBarricade = 10000;
    int minDistGoblin = 10000;
    for (auto barr: gameBarricades)
    {
        dist = static_cast<int>(sqrt((catapult->getX() - barr->getX()) * (catapult->getX() - barr->getX()) +
                                                     (catapult->getY() - barr->getY()) * (catapult->getY() - barr->getY())));
        distancesToBarricades.push_back(dist);
        if (dist <= minDistBarricade)
        {
            minDistBarricade = dist;
        }
    }
    for (auto goblin: gameGoblins)
    {
        dist = static_cast<int>(sqrt((catapult->getX() - goblin->getX()) * (catapult->getX() - goblin->getX()) +
                                                     (catapult->getY() - goblin->getY()) * (catapult->getY() - goblin->getY())));
        distancesToGoblins.push_back(dist);
        if (dist <= minDistGoblin)
        {
            minDistGoblin = dist;
        }
    }

    if(minDistGoblin <= minDistBarricade && minDistGoblin <= distanceToCitadel)
    {
        for (unsigned int i = 0; i < distancesToGoblins.size(); i++)
        {
            if (distancesToGoblins[i] == minDistGoblin)
                return gameGoblins[i];
        }
    }
    else if (minDistBarricade <= minDistGoblin && minDistBarricade <= distanceToCitadel)
    {
        for (unsigned int i = 0; i < distancesToBarricades.size(); i++)
        {
            if (distancesToBarricades[i] == minDistBarricade)
                return gameBarricades[i];
        }
    }
    else if (distanceToCitadel <= minDistGoblin && distanceToCitadel <= minDistBarricade)
    {
        return citadel;
    }
}

void Game::createUnit()
{
    if (gold >= price)
    {
        switch (unitID) {
        case -1:
        {
            break;
        }
        case 1:
        {
            Orc* newOrc = orcFactory->createUnit(clickX, clickY, QPixmap(":/textures/orc.png"));
            gameObjects.push_back(newOrc);
            gameMovingObjects.push_back(newOrc);
            gameOrcs.push_back(newOrc);
            unitID = -1;
            gold -= price;
            break;
        }
        case 2:
        {
            Goblin* newGoblin = goblinFactory->createUnit(clickX, clickY, QPixmap(":/textures/goblin.png"));
            gameObjects.push_back(newGoblin);
            gameGoblins.push_back(newGoblin);
            unitID = -1;
            gold -= price;
            break;
        }
        case 3:
        {
            Barricade* newBarricade = barricadeFactory->createUnit(clickX, clickY, QPixmap(":/textures/barricade.png"));
            gameObjects.push_back(newBarricade);
            gameBarricades.push_back(newBarricade);
            unitID = -1;
            gold -= price;
            break;
        }
        }
    }
}

void Game::createEnemies()
{
    Knight* newKnight = knightFactory->createUnit(1200, 100, QPixmap(":/textures/knight.png"));
    Catapult* newCatapult = catapultFactory->createUnit(1250, 200, QPixmap(":/textures/catapult.png"));
    Ram* newRam = ramFactory->createUnit(1300, 300, QPixmap(":/textures/ram.png"));

    gameObjects.push_back(newKnight);
    gameObjects.push_back(newCatapult);
    gameObjects.push_back(newRam);

    gameMovingObjects.push_back(newKnight);
    gameMovingObjects.push_back(newCatapult);
    gameMovingObjects.push_back(newRam);

    gameEnemies.push_back(newKnight);
    gameEnemies.push_back(newCatapult);
    gameEnemies.push_back(newRam);

    gameKnights.push_back(newKnight);
    gameRams.push_back(newRam);
    gameCatapults.push_back(newCatapult);
}

void Game::placeOrc()
{
    unitID = 1;
}

void Game::placeGoblin()
{
    unitID = 2;
}

void Game::placeBarricade()
{
    unitID = 3;
}

