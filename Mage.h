
#pragma once
using namespace std;

#include "Character.h"

class Mage : public Character {
public:
    Mage(const string& name) : Character(name, 70, 250) {}

    int BasicAtk() const override { return 10; }
    int SpecialAtk() const override { return 50; }
    int ManaCost() const override { return 70; }
};
