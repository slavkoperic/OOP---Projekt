#pragma once
#include <string>
#include <iostream>
#include <ostream>
#include "Character.h"

using namespace std;

class Enemy {
public:
    string Name;
    int HP, Atk;

    Enemy(const string& name, int hp, int atk)
        : Name(name), HP(hp), Atk(atk) {
    }

    void Attack(Character& target) {
        cout << Name << " deals " << Atk << " damage!\n";
        target.Damage(Atk);
    }

    void TakeDamage(int dmg) {
        HP -= dmg;
        cout << Name << " took " << dmg << " damage. HP: " << HP << endl;
    }
};

inline ostream& operator<<(ostream& os, const Enemy& e) {
    os << "Enemy: " << e.Name
        << " | HP: " << e.HP
        << " | ATK: " << e.Atk;
    return os;
}

