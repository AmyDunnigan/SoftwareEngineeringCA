#include "raylib.h"

int main() {
    // Determine the Game Window Width and Height
    const int screenWidth = 800;
    const int screenHeight = 800;

    // Initialize the Window
    InitWindow(screenWidth, screenHeight, "Input Movement Example");

    // Box position and control from Raylib exambles with screen position adjusted
    int boxPositionY = screenHeight/3 - 40;
    int scrollSpeed = 4;

    // Initialising position for random object
    int posx, posy;
    int velx, vely;  
    bool correctRange = false;

    // Initialise random object copied from asteroid game
        for (int i = 0; i < 2; i++)
    {
        posx = GetRandomValue(0, screenWidth);

        while (!correctRange)
        {
            if (posx > screenWidth/2 - 150 && posx < screenWidth/2 + 150) posx = GetRandomValue(0, screenWidth);
            else correctRange = true;
        }

        correctRange = false;

        posy = GetRandomValue(0, screenHeight);

        while (!correctRange)
        {
            if (posy > screenHeight/2 - 150 && posy < screenHeight/2 + 150)  posy = GetRandomValue(0, screenHeight);
            else correctRange = true;
        }

        [i].position = (Vector2){posx, posy};

        correctRange = false;
        velx = GetRandomValue(0, 20);
        vely = GetRandomValue(0, 20);

        while (!correctRange)
        {
            if (velx == 0 && vely == 0)
            {
                velx = GetRandomValue(0, 20);
                vely = GetRandomValue(0, 20);
            }
            else correctRange = true;
        }

        [i].speed = (Vector2){velx, vely};
        [i].radius = 40;
        [i].active = true;
        [i].color = BLUE;
    }
      
    // Define spider
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

    // Box controls from Raylib example
        boxPositionY -= (GetMouseWheelMove()*scrollSpeed);
        
    // Spider controls from class example
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
        DrawRectangle(screenWidth/2 - 40, boxPositionY, 80, 80, MAROON);
        
        // Add circle moving randomly
        DrawCircle ((GetRandomValue(0,screenWidth)), (GetRandomValue(0,screenHeight)), 20, RED);


        DrawText("Use mouse wheel to move the cube up and down!", 10, 10, 20, GRAY);
        DrawText(TextFormat("Box position Y: %03i", boxPositionY), 10, 40, 20, LIGHTGRAY);
        
        
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
