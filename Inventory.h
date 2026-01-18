#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include "Item.h"
using namespace std;

class Character;

class Inventory {
public:
    vector<Item*> items;

    ~Inventory() {
        for (auto item : items)
            delete item;
    }

    void AddItem(Item* item) {
        items.push_back(item);
        cout << item->Name << " potion added to inventory\n";
    }

    bool ContainsItem(Item* item) {
        return find(items.begin(), items.end(), item) != items.end();
    }

    void RemoveItem(Item* item) {
        items.erase(remove(items.begin(), items.end(), item), items.end());
        cout << "The empty " << item->Name << " potion was discarded.\n";
        delete item;
    }

    void UseItem(Item* item, Character& target) {
        if (ContainsItem(item)) {
            item->Use(target);
            RemoveItem(item);
        }
    }

    void ListItems() {
        cout << "Inventory:\n";
        for (auto item : items)
            cout << "- " << item->Name << " Potion\n";
    }
};
