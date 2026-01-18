#pragma once
#include <string>
#include <iostream>
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
        cout << Name << " deals" << Atk << " damage!\n";
        target.Damage(Atk);
    }

    void TakeDamage(int dmg) {
        HP -= dmg;
        cout << Name << " took " << dmg << " damage. HP: " << HP << endl;
    }
};

