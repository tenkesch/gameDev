#include "libs.hpp"
#include "raylib.h"
#include <iostream>

unsigned int counter = 0;
const int stepValue = 2;

void gameLogic() {
    // const auto pressedKey = GetKeyPressed();

    // if (pressedKey == KEY_A)
    //     playerUnit->moveX(-stepValue);
    int movedX = 0, movedY = 0;

    if (IsKeyDown(KEY_A))
        playerUnit->moveX(-stepValue);
    if (IsKeyDown(KEY_D))
        playerUnit->moveX(stepValue);
    if (IsKeyDown(KEY_S))
        playerUnit->moveY(stepValue);
    if (IsKeyDown(KEY_W))
        playerUnit->moveY(-stepValue);

    if (!(counter++ % 60))
        std::cout << "60frames passed.\n";
}
