#include "includes/libs.hpp"
#include "raylib.h"

int main() {
    InitWindow(800, 600, "GAMEDEV");
    SetTargetFPS(60);

    // const char playerName[] = "player1";
    // makeUnit(playerName, 20, 100);

    while (!WindowShouldClose()) {
        gameLogic();
        renderScreen();
    }

    // killUnit()
    CloseWindow();
    return 0;
}
