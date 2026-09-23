#include<raylib.h>
#include<vector>
using namespace std;
const int height=800, width=1000, grid_spacing=50;
const float view_scale=250.0f;
struct Complex
{
    float real, imag;
};
void DrawGrid()
{
    const Color gridColor = {60, 60, 60, 255};
    const Color axesColor = {255, 255, 255, 255};

    for (int x = 0; x < width; x += grid_spacing)
        DrawLine(x, 0, x, height, gridColor);

    for (int y = 0; y < height; y += grid_spacing)
        DrawLine(0, y, width, y, gridColor);

    DrawLine(width / 2, 0, width / 2, height, axesColor);
    DrawLine(0, height / 2, width, height / 2, axesColor);
}
Vector2 ComplexToScreen(float real, float imag, float scale)
{
    return
    {
        width/2.0f+real*scale,
        height/2.0f-imag*scale
    };
}
Complex NextIteration(Complex z, Complex c)
{
    return
    {
        z.real*z.real-z.imag*z.imag+c.real,
        2.0f*z.real*z.imag+c.imag
    };
}
bool HasEscaped(Complex z)
{
    return z.real*z.real+z.imag*z.imag>4.0f;
}
int main()
{
    InitWindow(width, height, "Complex Orbit Visualizer");
    SetTargetFPS(60);

    Complex z={0.0f, 0.0f};
    Complex c={-0.5f, 0.5f};
    vector<Complex> orbit;
    orbit.push_back(z);
    for(int iter=0; iter<20; iter++)
    {
        z=NextIteration(z, c);
        orbit.push_back(z);
    }

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        DrawGrid();

        for(int i=1; i<orbit.size(); i++)
        {
            Vector2 start=ComplexToScreen(orbit[i-1].real, orbit[i-1].imag, view_scale);
            Vector2 end=ComplexToScreen(orbit[i].real, orbit[i].imag, view_scale);
            DrawLineV(start, end, YELLOW);
            DrawCircleV(end, 4.0f, RED);
        }

        EndDrawing();
    }
    CloseWindow();
}