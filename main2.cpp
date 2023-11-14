#include "raylib.h"

int main() {
    // Determin the Game Window Width and Height
    const int screenWidth = 800;
    const int screenHeight = 800;

    // Initialize the Window
    InitWindow(screenWidth, screenHeight, "Input Movement Example");

 
    Texture2D myTexture = LoadTexture("Resources/Textures/spider.png");
    Vector2 scale = {0.5f,0.5f};

    float rotation = 0.0f;
    Color tint = WHITE;

    Vector2 position = {(screenWidth -(myTexture.width *scale.x))/2, (screenHeight-(myTexture.height*scale.y))/2};

    const float moveSpeed = 5.0f;

    

    // Setting the Frames Per Second
    SetTargetFPS(60);

    // Setting motion and rotation

    // The Game Loop
    while (!WindowShouldClose() /*WindowShouldClose returns true if esc is clicked and closes the window*/) {

    {
        if(IsKeyDown(KEY_RIGHT)) position.x += moveSpeed;
        if(IsKeyDown(KEY_LEFT)) position.x -= moveSpeed;
        if(IsKeyDown(KEY_UP)) position.y -= moveSpeed;
        if(IsKeyDown(KEY_DOWN)) position.y += moveSpeed;
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) rotation -= 10.0f;
        if(IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)) rotation += 10.0f;
    }

        // Setup Canvas
        BeginDrawing();
        // Clear canvas to a specific color to avoid flicker
        ClearBackground(RAYWHITE);
        DrawTextureEx(myTexture, position, rotation, 0.5f, tint);

        // Here goes all the Game Logic

        // teardown Canvas
        EndDrawing();
    }
    UnloadTexture(myTexture);
    CloseWindow();
    return 0;
}
