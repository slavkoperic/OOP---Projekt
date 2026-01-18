#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include <ostream>
#include "Inventory.h"
using namespace std;

class Character {
public:
    string Name;
    int HP, MaxHP;
    int Mana, MaxMana;
    int lvl;
    double exp, expcap;

    Inventory Inventory;

    Character(const string& name, int hp, int mana)
        : Name(name), HP(hp), MaxHP(hp),
        Mana(mana), MaxMana(mana),
        lvl(1), exp(0.0), expcap(100.0) {
    }

    virtual int BasicAtk() const { return 10; }
    virtual int SpecialAtk() const { return 30; }
    virtual int ManaCost() const { return 50; }

    void Damage(int dmg) {
        HP = max(0, HP - dmg);
    }

    void Regain(const string& type, int amount) {
        if (type == "HP")
            HP = min(HP + amount, MaxHP);
        else
            Mana = min(Mana + amount, MaxMana);
    }

    bool SpendMana(int amount) {
        if (Mana < amount) return false;
        Mana -= amount;
        return true;
    }

    int BasicAttack(int dmg) {
        return dmg + lvl * 2;
    }

    int UseAbility(int dmg, int mana) {
        return SpendMana(mana) ? dmg + lvl * 2 : 0;
    }

    void RegenerateMana() {
        Mana = min(Mana + MaxMana / 10, MaxMana);
    }

    template<typename T>
    void LevelUp(T hpBonus, T manaBonus, T expIncrease) {
        lvl++;
        MaxHP += (int)hpBonus;
        MaxMana += (int)manaBonus;
        expcap += (double)expIncrease;

        HP = MaxHP;
        Mana = MaxMana;

        cout << Name << " leveled up! Level: " << lvl << endl;
    }

    void GainExp(double amount) {
        exp += amount;
        while (exp >= expcap) {
            exp -= expcap;
            LevelUp(10.0 * lvl, 20.0 * lvl, 50.0 * lvl);
        }
    }
};

inline ostream& operator<<(ostream& os, const Character& c) {
    os << "Character: " << c.Name
        << " | Level: " << c.lvl
        << " | HP: " << c.HP << "/" << c.MaxHP
        << " | Mana: " << c.Mana << "/" << c.MaxMana
        << " | EXP: " << c.exp << "/" << c.expcap;
    return os;
}

