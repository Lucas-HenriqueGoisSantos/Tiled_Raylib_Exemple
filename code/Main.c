#include <stdio.h>
#include "raylib.h"

#define CUTE_TILED_IMPLEMENTATION
#include "cute_tiled.h"


// int main(int argc, char const *argv[])
// {


//     printf("%d\n", layer->data[1119]);
    
//     return 0;
// }

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    cute_tiled_map_t* map = cute_tiled_load_map_from_file("../data/export/basic.json", NULL);
    cute_tiled_layer_t* layer = map->layers;

    Texture2D tilemapTexture = LoadTexture("../graphics/tilesets/tiles.png");
    Rectangle srcTilemapRec = { (layer->id * layer->width), 0, layer->width, layer->height };
    Rectangle destTilemapRec = { 0, 0, layer->width, layer->height };
    Vector2 tileOrigin = { 0, 0 };

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawTexturePro(tilemapTexture, srcTilemapRec, destTilemapRec, tileOrigin, 0.f, WHITE);

            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}