#include<raylib.h>
const int height=800, width=1000;
int main()
{
    InitWindow(width, height, "Camera Playground");
    SetTargetFPS(60);

    Camera2D camera={0};
    camera.target={0.0f, 0.0f};
    camera.offset={width/2.0f, height/2.0f};
    camera.rotation=0.0f;
    camera.zoom=1.0f;

    const float cameraSpeed=300.0f;

    while(!WindowShouldClose())
    {
        float movement=cameraSpeed*GetFrameTime();
        float wheel=GetMouseWheelMove();

        if(wheel!=0)
            camera.zoom+=wheel*0.1f;
        if(camera.zoom<0.1f)
            camera.zoom=0.1f;
        if(camera.zoom>10.0f)
            camera.zoom=10.0f;
        if(IsKeyDown(KEY_W))
            camera.target.y-=movement;
        if(IsKeyDown(KEY_S))
            camera.target.y+=movement;
        if(IsKeyDown(KEY_A))
            camera.target.x-=movement;
        if(IsKeyDown(KEY_D))
            camera.target.x+=movement;
        if(IsKeyPressed(KEY_R))
        {
            camera.target={0.0f, 0.0f};
            camera.zoom=1.0f;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode2D(camera);

        for(int r=50; r<=width/2; r+=50)
            DrawCircleLines(0, 0, r, BLUE);

        EndMode2D();
        EndDrawing();
    }
}