#include "raylib.h"

void renderScreen() {
    BeginDrawing();
    ClearBackground(BLACK); // visible color
    DrawText("FUCK YEAHHHH", 20, 20, 30, PURPLE);
    EndDrawing();
}
