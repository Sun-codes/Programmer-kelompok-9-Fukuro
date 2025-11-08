#include "Character.h"
#include <iostream>
using namespace std;

// === FireBlast ===
void FireBlast::use(Character &caster, Character &target) {
    if (caster.getMana() < manaCost) {
        cout << caster.getName() << " doesn’t have enough mana to use FireBlast!\n";
        return;
    }

    if (usesLeft <= 0) {
        cout << "FireBlast has no uses left!\n";
        return;
    }

    int damage = static_cast<int>(caster.getAttack() * 1.5);
    cout << caster.getName() << " casts FireBlast on " << target.getName()
         << " for " << damage << " damage!\n";

    target.takeDamage(damage);
    caster.setMana(caster.getMana() - manaCost);
    usesLeft--;

    cout << "Mana left: " << caster.getMana() << endl;
    cout << "FireBlast uses remaining: " << usesLeft << endl;
}

// === Heal ===
void Heal::use(Character &caster) {
    if (caster.getMana() < manaCost) {
        cout << caster.getName() << " doesn’t have enough mana to Heal!\n";
        return;
    }

    float hpRatio = (float)caster.getHP() / (float)caster.getMaxHP();
    if (hpRatio > 0.3f) {
        cout << caster.getName() << " cannot Heal (HP above 30%)!\n";
        return;
    }

    int healAmount = static_cast<int>(caster.getAttack() * 0.8);
    int newHP = caster.getHP() + healAmount;
    if (newHP > caster.getMaxHP()) newHP = caster.getMaxHP();

    caster.setHP(newHP);
    caster.setMana(caster.getMana() - manaCost);

    cout << caster.getName() << " healed for " << healAmount << " HP!\n";
    cout << "Current HP: " << caster.getHP() << ", Mana left: " << caster.getMana() << endl;
}

// === Player methods ===
void Player::displayStats() const {
    cout << "\n================ CHARACTER STATUS ================\n";
    cout << "Name     : " << name << "\n";
    cout << "HP       : " << hp << "/" << maxHP << "\n";
    cout << "Mana     : " << mp << "\n";
    cout << "Attack   : " << attack << "\n";
    cout << "Defense  : " << defense << "\n";
    cout << "==================================================\n";
}

void Player::chooseAttack(Character &target) {
    FireBlast fire;
    Heal heal;

    int choice;
    cout << "\n====================\n";
    cout << "Choose your action:\n";
    cout << "1. Basic Attack\n";
    cout << "2. Use Ability\n";
    cout << "====================\n";
    cout << "Your choice: ";
    cin >> choice;

    if (choice == 1) {
        attackTarget(target);
    } else if (choice == 2) {
        cout << "\n=== Choose Ability ===\n";
        cout << "1. FireBlast\n";
        cout << "2. Heal\n";
        cout << "Choice: ";
        int abilityChoice;
        cin >> abilityChoice;

        if (abilityChoice == 1)
            fire.use(*this, target);
        else if (abilityChoice == 2)
            heal.use(*this);
        else
            cout << "Invalid choice!\n";
    } else {
        cout << "Invalid input!\n";
    }
}

// == Enemy Methods == 
void Enemy::setStats() {
    string enemies[4] = {"Slime", "Goblin", "Wolf", "Orc"};
    int index = rand() % 4;

    setName(enemies[index]);
    setHP(rand() % 61 + 20);   
    setAttack(rand() % 16 + 5);  
}
