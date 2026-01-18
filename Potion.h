#pragma once
#include "Item.h"
using namespace std;

class Potion : public Item {
public:
    int Amount;

    Potion(const string& name, int amount);
    void Use(Character& target) override;
};
