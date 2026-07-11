#include "includes/libs.hpp"
#include "raylib.h"
#include <iostream>
#include <memory>

std::unique_ptr<Unit> playerUnit;

int main() {
    InitWindow(800, 600, "GAMEDEV");
    SetTargetFPS(60);

    playerUnit = makeUnit("Goblin", 20, 100);

    while (!WindowShouldClose()) {
        gameLogic();
        renderScreen();
    }

    CloseWindow();
    return 0;
}
