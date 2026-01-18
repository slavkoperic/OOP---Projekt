#pragma once
using namespace std;

class Character;

class IUsable {
public:
    virtual void Use(Character& target) = 0;
    virtual ~IUsable() {}
};

