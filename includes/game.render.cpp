#include "raylib.h"

int ballX = 0, ballY = 0;
void renderScreen() {
    BeginDrawing();
    ClearBackground(BLACK); // visible color
    DrawText("FUCK YEAHHHH", 20, 20, 30, PURPLE);
    DrawCircle(ballX++, ballY++, 20, ORANGE);
    EndDrawing();
}
