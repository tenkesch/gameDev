#include <cstring>
#include <iostream>
#include <memory>

#define NAME_LENGHT_CAP 15

#define DEFAULT_DAMAGE 20
#define DEFAULT_HEALTH 100
#define DEFAULT_SIZE 100 // in percents

typedef struct Position {
    int X_;
    int Y_;
} Position;

typedef struct Stats {
    bool isAlive_ = true;
    int damage_ = DEFAULT_DAMAGE;
    int maxHP_ = DEFAULT_HEALTH;
    int currentHP_ = DEFAULT_HEALTH;
    int size_ = DEFAULT_SIZE;
} Stats;

struct Unit {
    char name_[NAME_LENGHT_CAP];

  private:
    Position pos = {.X_ = 0, .Y_ = 0};
    Stats stat;

  public:
    int isAlive() {
        if (stat.currentHP_ <= 0) {
            die();
            return false;
        }

        return true;
    }
    int currentHP() { return stat.currentHP_; }
    int getDamage() { return stat.damage_; }
    int getSize() { return stat.size_; }

    void moveX(int value) { pos.X_ += value; }
    void moveY(int value) { pos.Y_ += value; }
    void setDamage(int value) { stat.damage_ = value; }
    void setMaxHP(int value) { stat.currentHP_ = stat.maxHP_ = value; }
    void setSize(int value) { stat.size_ = value; }
    void die() { stat.isAlive_ = false; }
    void setCurrentHP(int value) {
        stat.currentHP_ = value;
        if (stat.currentHP_ <= 0)
            die();
    }

    void recieveDamage(int value) { setCurrentHP(stat.currentHP_ -= value); }
};

// frees up memory Unit was holding
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
