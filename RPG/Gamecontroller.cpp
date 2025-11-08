#include "GameController.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

GameController::GameController(Player *p)
    : player(p), enemy(nullptr), gameMode(Mode::MOVEMENT), stepCount(0) {}

GameController::~GameController() {
    if (enemy) delete enemy;
}

void GameController::start() {
    cout << "=== Welcome to the RPG ===\n";
    player->displayStats();

    while (player->isAlive()) {
        move();
    }
}

void GameController::move() {
    cout << "\nPress ENTER to move forward...";
    cin.ignore();

    stepCount++;
    cout << "You take a step. Total steps: " << stepCount << endl;

    // Enemy appears on all steps EXCEPT multiples of 3 (not divisible by 5)
    if (!(stepCount % 3 == 0 && stepCount % 5 != 0)) {
        startBattle();
    } else {
        cout << "You continue walking peacefully...\n";
    }
}

void GameController::startBattle() {

    enemy = new Enemy("Name", 0, 0, 0, 0);
    enemy->setStats();
    cout << "\n⚔️ A wild " << enemy->getName() << " appears! ⚔️\n";
    gameMode = Mode::BATTLE;

    while (enemy->isAlive() && player->isAlive()) {
        playerTurn();
        if (!enemy->isAlive()) break;
        enemyTurn();
    }

    bool victory = player->isAlive();
    endBattle(victory);
}

void GameController::playerTurn() {
    player->chooseAttack(*enemy);
}

void GameController::enemyTurn() {
    cout << enemy->getName() << " attacks!\n";
    enemy->attackTarget(*player);
}

void GameController::endBattle(bool victory) {
    if (victory)
        cout << "You defeated " << enemy->getName() << "!\n";
    else
        cout << "You were defeated by " << enemy->getName() << "...\n";

    delete enemy;
    enemy = nullptr;

    // HP returns to full after battle
    player->setHP(player->getMaxHP());

    gameMode = Mode::MOVEMENT;
}
