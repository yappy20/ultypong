#include "menu.h"
#include <raylib.h>
#include "game.h"

using namespace std;

void displayMenu() {
    const int screenWidth = 1250;
    const int screenHeight = 650;

    InitWindow(screenWidth, screenHeight, "Ultimate Pong");
    SetTargetFPS(60);
    Texture2D background = LoadTexture("C:\\Users\\edna\\Downloads\\pongbackground.png");
    
    Rectangle startButton = { screenWidth / 2.0f - 100, screenHeight / 2.0f - 25, 200, 50 };
    bool startButtonHovered = false;
    bool startButtonClicked = false;

    // Main game loop
    while (!WindowShouldClose()) {
        // Update
        startButtonHovered = CheckCollisionPointRec(GetMousePosition(), startButton);

        if (startButtonHovered && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            startButtonClicked = true;
        }

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawTexture(background, 0, 0, WHITE);
       

        // Draw start button
        if (startButtonHovered) {
            DrawRectangleRec(startButton, BLUE);
        }
        else {
            DrawRectangleRec(startButton, GRAY);
        }
        DrawText("START", screenWidth / 2.0f - 80, screenHeight / 2.0f - 15, 20, startButtonHovered ? DARKGRAY : BLACK);

        // Draw options button (with corrected positioning)
        Rectangle optionsButton = { screenWidth / 2.0f - 100, screenHeight / 2.0f + 40, 200, 50 };
        bool optionsButtonHovered = CheckCollisionPointRec(GetMousePosition(), optionsButton);

        if (optionsButtonHovered) {
            DrawRectangleRec(optionsButton, BLUE);
        }
        else {
            DrawRectangleRec(optionsButton, GRAY);
        }
        DrawText("OPTIONS", screenWidth / 2.0f - 80, screenHeight / 2.0f + 50, 20, optionsButtonHovered ? DARKGRAY : BLACK);

        // Button click action
        if (startButtonClicked) {
            // Call the startGame function from "game.h"
            startGame();
            startButtonClicked = false;
            break;
        }
        
        EndDrawing();
    }
    UnloadTexture(background);
    CloseWindow();
}
