#include<raylib.h>
using namespace std;
const int height=800, width=1000;
struct complex
{
    float real, imag;
}c;
int main()
{
    InitWindow(width, height, "Complex Orbit Visualizer");
    SetTargetFPS(60);
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }
    CloseWindow();
}