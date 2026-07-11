#include <cstring>
#include <iostream>
#include <memory>

#define NAME_LENGHT_CAP 15

#define DEFAULT_DAMAGE 20
#define DEFAULT_HEALTH 100
#define DEFAULT_SIZE 100 // in percents

struct Unit {
    char name_[NAME_LENGHT_CAP];

  private:
    bool isAlive_ = true;
    int damage_ = DEFAULT_DAMAGE;
    int maxHP_ = DEFAULT_HEALTH;
    int currentHP_ = DEFAULT_HEALTH;
    int size_ = DEFAULT_SIZE;

  public:
    int isAlive() {
        if (currentHP_ <= 0) {
            die();
            return false;
        }

        return true;
    }
    int currentHP() { return currentHP_; }
    int getDamage() { return damage_; }
    int getSize() { return size_; }

    void setDamage(int value) { damage_ = value; }
    void setMaxHP(int value) { currentHP_ = maxHP_ = value; }
    void setSize(int value) { size_ = value; }
    void die() { isAlive_ = false; }
    void setCurrentHP(int value) {
        currentHP_ = value;
        if (currentHP_ <= 0)
            die();
    }

    void recieveDamage(int value) { setCurrentHP(currentHP_ -= value); }
};

void killUnit(std::unique_ptr<Unit> &unitPtr) { unitPtr.reset(); }

std::unique_ptr<Unit> makeUnit(char name[NAME_LENGHT_CAP], int damage,
                               int health) {
    auto newUnit = std::make_unique<Unit>();

    std::strncpy(newUnit->name_, name, NAME_LENGHT_CAP - 1);
    newUnit->name_[NAME_LENGHT_CAP - 1] = '\0';
    newUnit->setDamage(damage);
    newUnit->setMaxHP(health);
    newUnit->setSize(DEFAULT_SIZE);

    return newUnit;
}

// struct Unit *createUnit(char name[NAME_LENGHT_CAP]) {
//     struct Unit newCreature;

//     std::strncpy(newCreature.name_, name, NAME_LENGHT_CAP - 1);
//     newCreature.name_[NAME_LENGHT_CAP - 1] = '\0';
//     newCreature.setDamage(DEFAULT_DAMAGE);
//     newCreature.setHealth(DEFAULT_HEALTH);
//     newCreature.setSize(DEFAULT_SIZE);

//     std ::cout << "New Mob has been created : '" << name << "'" << std::endl;
//     return &newCreature;
// }
