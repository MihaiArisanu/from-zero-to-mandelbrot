#include<raylib.h>
const int height=600, width=800;
int main()
{
    InitWindow(width, height, "Camera Playground");
    SetTargetFPS(60);

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello", 20, 20, 20, BLACK);
        EndDrawing();
    }
    CloseWindow();
}