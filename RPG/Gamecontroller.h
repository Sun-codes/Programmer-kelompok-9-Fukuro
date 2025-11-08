#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "Character.h"

class GameController {
public:
    enum class Mode { MOVEMENT, BATTLE };

private:
    Player *player;
    Enemy *enemy;
    Mode gameMode;
    int stepCount;

public:
    GameController(Player *p);
    ~GameController();

    void start();
    void move();
    void startBattle();
    void playerTurn();
    void enemyTurn();
    void endBattle(bool victory);
};

#endif
