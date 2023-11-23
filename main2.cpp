#include "raylib.h"
#include "raymath.h"

// Defines modified from Pang game
# define RandomSpider 
# define SpiderSpeed    2.0f

// Types and Structures definition modified from Pang game
typedef struct RandomSpider {
    Vector2 position;
    Vector2 speed;
    float radius;
    int points;
    bool active;
    } RandomSpider;

typedef struct Points {
    Vector2 position;
    int value;
    float alpha;
    } Points;

    // Global variables declaration

int main(void) {
    
    const int screenWidth = 800;
    const int screenHeight = 800;

    // Initialize the Window
    InitWindow(screenWidth, screenHeight, "Input Movement Example");
    
    // Setting the Frames Per Second
    SetTargetFPS(60);

    // Box position and control from Raylib exambles with screen position adjusted
    int boxPositionY = screenHeight/3 - 40;
    int scrollSpeed = 4;

    // Initialise modified Pang game variables
    int posx, posy;
    int velx = 0;
    int vely = 0;

    // Initialising random object modified from pang game
    for (int i = 0; i < RandomSpider; i++)
    {
        RandomSpider[i].radius = 40.0f;
        posx = GetRandomValue(0 + RandomSpider[i].radius, screenWidth - RandomSpider[i].radius);
        posy = GetRandomValue(0 + RandomSpider[i].radius, screenHeight/2);

        RandomSpider[i].position = (Vector2){ posx, posy };

        while ((velx == 0) || (vely == 0))
        {
            velx = GetRandomValue(-SpiderSpeed, SpiderSpeed);
            vely = GetRandomValue(-SpiderSpeed, SpiderSpeed);
        }

        RandomSpider[i].speed = (Vector2){ velx, vely };
        RandomSpider[i].points = 200;
        RandomSpider[i].active = true;
    }
      
    // Define spider
    Texture2D myTexture = LoadTexture("Resources/Textures/spider.png");
    Vector2 scale = {0.5f,0.5f};
    float rotation = 0.0f;
    Color tint = WHITE;
    Vector2 position = {(screenWidth -(myTexture.width*scale.x))/2, (screenHeight-(myTexture.height*scale.y))/2};
    const float moveSpeed = 5.0f;
     
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

        // Draw RandomSpider modified from Pang game

            for (int i = 0;i < RandomSpider; i++)
            {
                if (RandomSpider[i].active) DrawCircleV(RandomSpider[i].position, RandomSpider[i].radius, DARKGRAY);
                else DrawCircleV(RandomSpider[i].position, RandomSpider[i].radius, Fade(LIGHTGRAY, 0.3f));
            }
        
        
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
