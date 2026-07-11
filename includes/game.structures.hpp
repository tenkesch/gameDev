#pragma once

#include <memory>

inline constexpr int NAME_LENGHT_CAP = 15;
inline constexpr int DEFAULT_DAMAGE = 20;
inline constexpr int DEFAULT_HEALTH = 100;
inline constexpr int DEFAULT_SIZE = 100; // in percents

struct Position {
    int X_ = 300;
    int Y_ = 400;
};

struct Stats {
    bool isAlive_ = true;
    int damage_ = DEFAULT_DAMAGE;
    int maxHP_ = DEFAULT_HEALTH;
    int currentHP_ = DEFAULT_HEALTH;
    int size_ = DEFAULT_SIZE;
};

struct Unit {
    char name_[NAME_LENGHT_CAP];

  private:
    Position pos{0, 0};
    Stats stat;

  public:
    bool isAlive() {
        if (stat.currentHP_ <= 0) {
            die();
            return false;
        }

        return true;
    }

    void moveX(int value) { pos.X_ += value; }
    void moveY(int value) { pos.Y_ += value; }

    // GETTERS
    int getPositionX() { return pos.X_; }
    int getPositionY() { return pos.Y_; }
    int currentHP() { return stat.currentHP_; }
    int getDamage() { return stat.damage_; }
    int getSize() { return stat.size_; }

    // SETTERS
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

extern std::unique_ptr<Unit> playerUnit;

std::unique_ptr<Unit> makeUnit(const char *name, int damage, int health);
void killUnit(std::unique_ptr<Unit> &unitPtr);
