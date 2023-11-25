#include "raylib.h"
#include "Ball.h"
    
int main() {
    // Determine the Game Window Width and Height
    const int screenWidth = 800;
    const int screenHeight = 800;

    // Initialize the Window
    InitWindow(screenWidth, screenHeight, "Input Movement Example");

    // Intialise ball
    Ball myBall({screenWidth/2, screenHeight/2}, 50, BLUE);

    // Draw background    
    Texture2D deskTexture = LoadTexture("Resources/Textures/desk.png");

    // Initialize cup 
    Texture2D myTexture = LoadTexture("Resources/Textures/cup.png");
    Vector2 scale = {0.5f,0.5f};
    Color tint = WHITE;
    Vector2 position = {(screenWidth -(myTexture.width *scale.x))/2, (screenHeight-(myTexture.height*scale.y))/2};
    const float moveSpeed = 5.0f;

    // Initialize pen
    Texture2D penTexture = LoadTexture("Resources/Textures/pen.png");
    float rotation = 0.0f;
   
    // Initialise box from Raylib example
    int boxPositionY = screenHeight/2 - 20;
    int scrollSpeed = 4;

    // Setting the Frames Per Second
    SetTargetFPS(60);

    // Setting motion and rotation

    // The Game Loop
    while (!WindowShouldClose() /*WindowShouldClose returns true if esc is clicked and closes the window*/) {
    
    // Set cup movement
    {
        if(IsKeyDown(KEY_RIGHT)) position.x += moveSpeed;
        if(IsKeyDown(KEY_LEFT)) position.x -= moveSpeed;
        if(IsKeyDown(KEY_UP)) position.y -= moveSpeed;
        if(IsKeyDown(KEY_DOWN)) position.y += moveSpeed;

    }

    // Set pen movement
    {
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) rotation -= 10.0f;
        if(IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)) rotation += 10.0f;
    }
    // Add box from Raylib examples
    {
    boxPositionY -= (GetMouseWheelMove()*scrollSpeed);
    }

        // Setup Canvas
        BeginDrawing();
        // Clear canvas to a specific color to avoid flicker
        ClearBackground(RAYWHITE);
        DrawTexture(deskTexture,0,0,WHITE);
        DrawTextureEx(myTexture, position, rotation, 0.5f, tint);
        DrawRectangle(screenWidth/3 - 40, boxPositionY, 80, 80, MAROON);
        DrawText("Use mouse wheel to move the cube up and down!", 10, 10, 20, GRAY);
        DrawTextureEx(penTexture, position, rotation, 0.5f, tint);

        // Draw ball
        
            myBall.Draw();

            if(IsKeyDown(KEY_RIGHT)) myBall.Move({5,0});
            if(IsKeyDown(KEY_LEFT)) myBall.Move({-5,0});
            if(IsKeyDown(KEY_UP)) myBall.Move({0,-5});
            if(IsKeyDown(KEY_DOWN)) myBall.Move({0,5});

            EndDrawing();

        // Here goes all the Game Logic

        // teardown Canvas
        EndDrawing();
    }
    UnloadTexture(myTexture);
    UnloadTexture(penTexture);
    CloseWindow();
    return 0;
}