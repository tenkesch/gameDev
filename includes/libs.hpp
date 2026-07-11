#ifndef INCLUDES
#include <memory>

#define INCLUDES

void renderScreen();
void gameLogic();
struct Unit;
Unit *makeUnit(char, int, int);
void killUnit(std::unique_ptr<Unit> &);

#endif
