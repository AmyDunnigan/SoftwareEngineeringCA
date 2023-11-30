
#include <stdlib.h> // includes functions involving memory, process control and conversions
#include <time.h> // includes functions for manipulating time

#include "raylib.h"
#include "raymath.h"

// Defining pre-processor constants
#define SNOW_SOURCE_WIDTH 240
#define SNOW_SOURCE_HEIGHT 240
#define SNOW_MAX_COUNT 16
#define SNOW_SOURCE_RECTANGLE CLITERAL(Rectangle){0, 0, SNOW_SOURCE_WIDTH, SNOW_SOURCE_HEIGHT}
#define FALL_SPEED_MIN 10
#define FALL_SPEED_MAX 50


// Determine the Game Window Width and Height
const int screenWidth = 800;
const int screenHeight = 800;
const Vector2 screenSize = {screenWidth, screenHeight};

// Create struct for snow
typedef struct Snow
{
    Vector2 position;
    int fallSpeed;
    bool _active;
}Snow;

// Snow array
Snow _snow[SNOW_MAX_COUNT];

typedef enum GameState

{PLAYING,
END
}GameState;

GameState _state; // Denotes state of game - Global variables prefixed with an underscore

float _timeGameStarted;
float _timeGameEnded;

Texture2D _spriteSnow;
Texture2D _spriteScarfy;

void UnsetSnowAt(int);
void SetSnowAt(int, Vector2, float);
void DrawSnow(void);
void UpdateSnow(void);

void GameInit(void);
void GameEnd(void);
void UpdateDrawFrame(void);

int main() {
    // Initialize the Window
    srand(time(0));
    
    InitWindow(screenWidth, screenHeight, "Basic game modified from example by Andrew Hamel");
    
    // Load textures
    _spriteSnow = LoadTexture("Resources/Textures/cup.png");
    _spriteScarfy = LoadTexture("Resources/Textures/scarfy.png");

    GameInit();

    // Box position and control from Raylib exambles with screen position adjusted

    // Setting motion and rotation

    // The Game Loop here goes all the Game Logic
    while (!WindowShouldClose() /*WindowShouldClose returns true if esc is clicked and closes the window*/) 

        // Setup Canvas
        {
        UpdateDrawFrame();
        }

        CloseWindow();

    return 0;
}

void UnsetSnowAt(int i)
{
    if (i < 0 || i >= SNOW_MAX_COUNT) // Early Out - Ensure variables are within parameters to avoid errors
    {
        return;
    }

    _snow[i]._active = false;
}

void SetSnowAt(int i, Vector2 position, float fallSpeed)
{
    if (i < 0 || i >= SNOW_MAX_COUNT) // Early Out - ensure variables are within parameters to avoid errors
    {
        return;
    }

    _snow[i].position = position;
    _snow[i].fallSpeed = fallSpeed;
    _snow[i]._active = true;
}

void GameInit(void)
{
_state = PLAYING;
_timeGameStarted = GetTime();

for(int i = 0; i < SNOW_MAX_COUNT; i++)
{
    UnsetSnowAt(i);
}
}

void DrawSnow(void)
{
for(int i = 0; i < SNOW_MAX_COUNT; i++)
{
    if(!_snow[i]._active)
    {
        continue;
    }
    // Set drawing to centre of sprite
    Vector2 position = _snow[i].position;
    position.x -= SNOW_SOURCE_WIDTH /2;
    position.y -= SNOW_SOURCE_HEIGHT /2;
    DrawTextureRec(_spriteSnow, SNOW_SOURCE_RECTANGLE, _snow[i].position, WHITE);
}  
}

void UpdateSnow(void)
{
for(int i = 0; i < SNOW_MAX_COUNT; i++)
{
    if(!_snow[i]._active)
    {
        continue;
    }

    float offset = _snow[i].fallSpeed * GetFrameTime(); // for consistent play speed
    _snow[i].position.y += offset;
}  
}

void SpawnSnow (void)
{
    int availableIndex = -1;
    for (int i = 0; i < SNOW_MAX_COUNT; i++)
    {
        if (_snow[i]._active)
        {
            availableIndex = i;
            break;
        }
    }

    if (availableIndex == -1)
    {
        // Checking available index not still -1 as this would be an ERROR!
        return;
    }

    int fallspeed = GetRandomValue(FALL_SPEED_MIN,FALL_SPEED_MAX);
    int posX = GetRandomValue(SNOW_SOURCE_WIDTH / 2, screenWidth - (SNOW_SOURCE_WIDTH / 2));

    SetSnowAt(availableIndex, (Vector2){posX, -SNOW_SOURCE_HEIGHT}, fallspeed);
}

void GameEnd(void)
{
_state = END;
_timeGameEnded = GetTime();
}

void UpdateDrawFrame(void)
{
// reset game
if (_state == END && IsKeyPressed(KEY_RIGHT))
{
    GameInit();    
}

if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
{
    SpawnSnow();
}

UpdateSnow();

BeginDrawing();

ClearBackground(RAYWHITE);

// Draw game
DrawSnow();

if (_state == END)
{
    // TODO: Gameover HUD
}
else
{
    // TODO: Gametime HUD
}


}