#include <iostream>
#include "Potion.h"
#include "Character.h"
using namespace std;

Potion::Potion(const string& name, int amount)
    : Item(name), Amount(amount) {
}

void Potion::Use(Character& target) {
    target.Regain(Name, Amount);
    cout << target.Name << " used " << Name << " potion.\n";
}
