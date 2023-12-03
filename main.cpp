// Game starting point taken from class example

#include "raylib.h"

#define MAX_SNOW    360
#define SNOW_SPEED  2

// Outlining snow features adapted from Raylib asteroid game 
// https://github.com/raysan5/raylib-games/blob/master/classics/src/asteroids.c
// attempted to move this to a header file, but decided it was unnecessary as the code is not complex

typedef struct Snow                                    
{
    float radius;
    Color color;
    Vector2 speed;
    Vector2 position;
    bool active;    
}Snow;

struct Anim
{
    Rectangle rec;
    Vector2 pos;
    int frame;
    float updateTime;
    float runningTime;
};

// Setting screen size and loading snow and text parameters
int main()
{
    const int screenWidth = 1200;
    const int screenHeight = 800;

    int posx, posy;
    int velx, vely;
    bool correctRange = false;
    static Snow BigSnow[MAX_SNOW] = { 0 };
    
    InitWindow(screenWidth, screenHeight, "First Game");

    Font customFont = LoadFont("Resource/Fonts/font.ttf");
    const char *text = "PRESS THE SPACE BAR TO";
    Vector2 textPosition = {10,screenHeight/3 -20};
    int textSize = 20;
    Color textColor = RAYWHITE;
    
// array for snow adapted from raylib asteriod game
    for (int i = 0; i < MAX_SNOW; i++)
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

// BigSnow is possibly not the best name as there is only one size of snow
// This was carried over from the asteroid game and was useful in differtiating between 
// various, structs, classes, arrays etc

        BigSnow[i].position = (Vector2){posx, posy}; 

        correctRange = false;
        velx = GetRandomValue(-SNOW_SPEED, SNOW_SPEED);
        vely = GetRandomValue(-SNOW_SPEED, SNOW_SPEED);

// Initialising snow adapted from raylib asteroid game
        while (!correctRange)
        {
            if (velx == 0 && vely == 0)
            {
                velx = GetRandomValue(-SNOW_SPEED, SNOW_SPEED);
                vely = GetRandomValue(-SNOW_SPEED, SNOW_SPEED);
            }
            else correctRange = true;
        }

        BigSnow[i].speed = (Vector2){velx, vely};
        BigSnow[i].radius = 10;
        BigSnow[i].active = true;
        BigSnow[i].color = WHITE;
    }

// Loading sounds and textures
    InitAudioDevice();    

    Sound sound = LoadSound("Resources/Sounds/sound.wav");
    Sound questionsound = LoadSound("Resources/Sounds/questionsound.wav");

    int volume = 50;
    SetSoundVolume(sound, volume/100.f);

    const int gravity{350};
    const int scarfyPadding{50};

    Texture2D obstacle = LoadTexture("Resources/Textures/smpenguin.png");
    Texture2D scarfy = LoadTexture("Resources/Textures/scarfy.png");
    
    Anim scarfyAnim; // Set character features
    scarfyAnim.rec.width = scarfy.width/6;
    scarfyAnim.rec.height = scarfy.height;
    scarfyAnim.rec.x = 0;
    scarfyAnim.rec.y = 0;
    scarfyAnim.pos.x = scarfyPadding;
    scarfyAnim.pos.y = screenHeight - scarfyAnim.rec.height;
    scarfyAnim.frame = 0;
    scarfyAnim.updateTime = 1.0/12.0;
    scarfyAnim.runningTime = 0.0;

    Rectangle obRec; // Set obstacle features
    obRec.width = obstacle.width;
    obRec.height = obstacle.height;
    obRec.x = 300;
    obRec.y = 0;
    Vector2 obPos;
    obPos.x = screenWidth - obRec.width;
    obPos.y = screenHeight - obRec.height;

    int obVel{-100};

    int velocity{0};
    const int jumpHeight{500};
    bool jumped{false};
    int speed{200};
    bool collision{};
    
    SetTargetFPS(60);
    
// Main game loop
    
    while (!WindowShouldClose())    // Detect window close button or ESC key
    { const float deltaTime{GetFrameTime()};

    Rectangle obstacleRec{
        obPos.x,
        obPos.y,
        obRec.height,
        obRec.width
    };

    Rectangle scarfyRec{
        scarfyAnim.pos.x,
        scarfyAnim.pos.y,
        scarfyAnim.rec.height,
        scarfyAnim.rec.width
    };

// Check collision
    if(CheckCollisionRecs(scarfyRec,obstacleRec))
    {
        collision = true;     
    }

// Scarfy movement from class example
    if(IsKeyDown(KEY_RIGHT) && !jumped){
        scarfyAnim.pos.x += speed* deltaTime;
        scarfyAnim.rec.width = scarfy.width/6;

        scarfyAnim.runningTime += deltaTime;
        if(scarfyAnim.runningTime>= scarfyAnim.updateTime){
            scarfyAnim.runningTime = 0.0;
            scarfyAnim.rec.x = scarfyAnim.frame * scarfyAnim.rec.width;
            scarfyAnim.frame ++;
            if (scarfyAnim.frame>5){
                scarfyAnim.frame = 0;
            }
        }

    }

    if(IsKeyReleased(KEY_RIGHT) && !jumped)
    {
        scarfyAnim.frame = 0;
        scarfyAnim.rec.x = scarfyAnim.frame * scarfyAnim.rec.width;
       
    }

    if(IsKeyDown(KEY_LEFT) && !jumped)
    {
        scarfyAnim.pos.x -= speed* deltaTime;
        scarfyAnim.rec.width = -scarfy.width/6;

        scarfyAnim.runningTime += deltaTime;
        if(scarfyAnim.runningTime>= scarfyAnim.updateTime)
        {
            scarfyAnim.runningTime = 0.0;
            scarfyAnim.rec.x = scarfyAnim.frame * scarfyAnim.rec.width;
            scarfyAnim.frame ++;
            if (scarfyAnim.frame>5)
            {
                scarfyAnim.frame = 0;
            }
        }
    }

    if(IsKeyReleased(KEY_LEFT) && !jumped)
    {
        scarfyAnim.frame = 0;
        scarfyAnim.rec.x = scarfyAnim.frame * scarfyAnim.rec.width;       
    }

    if(scarfyAnim.pos.y >= screenHeight - scarfy.height)
    {
        velocity = 0;
        jumped = false;
    }

    else
    {
        velocity += gravity * deltaTime;
        jumped = true;
    }

    if (IsKeyPressed(KEY_SPACE) && !jumped)
    {
        velocity -= jumpHeight; 
    }

        scarfyAnim.pos.y += velocity * deltaTime;
        obPos.x += obVel * deltaTime;

    if (!collision)
    {
        DrawTextureRec(scarfy, scarfyAnim.rec, scarfyAnim.pos, WHITE);
        DrawTextureRec(obstacle, obRec, obPos, WHITE);
    }
        BeginDrawing();
        ClearBackground(LIGHTGRAY);

    if(IsKeyPressed(KEY_SPACE))
    {
        PlaySound(sound);
    }

    if(IsKeyPressed(KEY_RIGHT))
    {
        PlaySound(questionsound);
    }

    if(IsKeyPressed(KEY_LEFT))
    {
        PlaySound(questionsound);
    }

// Snow logic adapted from Raylib asteroid game
    for (int i = 0; i < MAX_SNOW; i++)
    {
    if (BigSnow[i].active)
        {
// Snow movement
        BigSnow[i].position.x += BigSnow[i].speed.x;
        BigSnow[i].position.y += BigSnow[i].speed.y;

// Collision logic: snow vs wall
        if  (BigSnow[i].position.x > screenWidth + BigSnow[i].radius) BigSnow[i].position.x = -(BigSnow[i].radius);
        else if (BigSnow[i].position.x < 0 - BigSnow[i].radius) BigSnow[i].position.x = screenWidth + BigSnow[i].radius;
        if (BigSnow[i].position.y > screenHeight + BigSnow[i].radius) BigSnow[i].position.y = -(BigSnow[i].radius);
        else if (BigSnow[i].position.y < 0 - BigSnow[i].radius) BigSnow[i].position.y = screenHeight + BigSnow[i].radius;
        }
    }    
// Draw snow adapted from asteroid game
    
    for (int i = 0; i < MAX_SNOW; i++)
            {
                if (BigSnow[i].active) DrawCircleV(BigSnow[i].position, BigSnow[i].radius, WHITE);
                else DrawCircleV(BigSnow[i].position, BigSnow[i].radius, Fade(WHITE, 0.3f));
            }
        if (!collision)
    {
        DrawText(text, textPosition.x, textPosition.y, textSize, textColor);
        DrawText("JUMP OVER THE PENGUIN!", 10, screenHeight/2.4, 80, RAYWHITE);
    }

        EndDrawing();        
                
    }

// Unload textures sounds and fonts
    UnloadTexture(scarfy);    
    UnloadTexture(obstacle);
    UnloadSound(sound);
    UnloadSound(questionsound);
    UnloadFont(customFont);
    CloseAudioDevice();
    CloseWindow();       
    return 0;       
            
}