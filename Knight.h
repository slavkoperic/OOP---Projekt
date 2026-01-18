#pragma once
#include "Character.h"
using namespace std;

class Knight : public Character {
public:
    Knight(const string& name) : Character(name, 120, 150) {}

    int BasicAtk() const override { return 20; }
    int SpecialAtk() const override { return 40; }
    int ManaCost() const override { return 50; }
};

