#pragma once
#include <string>
#include "IUsable.h"
using namespace std;

class Item : public IUsable {
public:
    string Name;

    Item(const string& name) : Name(name) {}
    virtual void Use(Character& target) = 0;
    virtual ~Item() {}
};
