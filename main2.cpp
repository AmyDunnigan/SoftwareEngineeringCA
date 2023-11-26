#include "ball.h"
#include "raylib.h"

const int MAX_BALLS = 10;

int main(void) 
{
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 600;
    

    InitWindow(screenWidth, screenHeight, "Ball experiments");

    Ball player({screenWidth/2,screenHeight-50} 30, RED);
    
    SetTargetFPS(60);   // Set desired FPS

    int score = 0;
    bool gameOver = false;

    // Main game loop
    while (!WindowShouldClose()) {    // Detect window close button or ESC key
        // Update
        if(!gameOver);
        {
        if(IsKeyDown(KEY_RIGHT)&& player.GetPosition().x<  screenWidth - player.GetRadius());
        player.Move({-5.0});
        }
         
        // Draw
        BeginDrawing();

        ClearBackground (RAYWHITE);
        DrawText("If this works it will be a miracle", 10, 10, 20, RAYWHITE);
        player.Draw();

        EndDrawing();
    }

    // De-initialization
    CloseWindow();     // Close window and OpenGL context

    return 0;
};