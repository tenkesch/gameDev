#include <cstring>

#include "game.structures.hpp"

void killUnit(std::unique_ptr<Unit> &unitPtr) { unitPtr.reset(); }

std::unique_ptr<Unit> makeUnit(const char *name, int damage, int health) {
    auto newUnit = std::make_unique<Unit>();

    std::strncpy(newUnit->name_, name, NAME_LENGHT_CAP - 1);
    newUnit->name_[NAME_LENGHT_CAP - 1] = '\0';
    newUnit->setDamage(damage);
    newUnit->setMaxHP(health);
    newUnit->setSize(DEFAULT_SIZE);

    return newUnit;
}
