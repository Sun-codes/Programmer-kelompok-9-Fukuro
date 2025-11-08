#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <iostream>
using namespace std;

class Character {
protected:
    string name;
    int hp;
    int maxHP;
    int mp;
    int attack;
    int defense;

public:
    Character(const string &charName, int healthPoints, int mana, int attackPower, int defensePower)
        : name(charName), hp(healthPoints), maxHP(healthPoints),
          mp(mana), attack(attackPower), defense(defensePower) {}

    // === Getters ===
    string getName() const { return name; }
    int getHP() const { return hp; }
    int getMaxHP() const { return maxHP; }
    int getMana() const { return mp; }
    int getAttack() const { return attack; }
    int getDefense() const { return defense; }

    // === Setters ===
    void setName(string newName) { name = newName; }
    void setHP(int newHP) { hp = newHP; }
    void setMana(int newMana) { mp = newMana; }
    void setAttack(int newAttack) { attack = newAttack; } 

    // === Methods ===
    void takeDamage(int dmg) {
        hp -= dmg;
        if (hp < 0) hp = 0;
    }

    bool isAlive() const { return hp > 0; }

    void attackTarget(Character &target) {
        cout << name << " attacks " << target.getName()
             << " for " << attack << " damage!\n";
        target.takeDamage(attack);
    }
};

// === ABILITY CLASSES ===
class FireBlast {
public:
    int manaCost = 10;
    int usesLeft = 3;

    void use(Character &caster, Character &target);
};

class Heal {
public:
    int manaCost = 20;
    void use(Character &caster);
};

// === PLAYER CLASS ===
class Player : public Character {
public:
    Player(const string &charName, int healthPoints, int mana, int attackPower, int defensePower)
        : Character(charName, healthPoints, mana, attackPower, defensePower) {}

    void chooseAttack(Character &target);
    void displayStats() const;
};

// === ENEMY CLASS ===
class Enemy : public Character {
public:
    Enemy(const string &charName, int healthPoints, int mana, int attackPower, int defensePower)
        : Character(charName, healthPoints, mana, attackPower, defensePower) {
            
        }
    
    void setStats();
};

#endif
