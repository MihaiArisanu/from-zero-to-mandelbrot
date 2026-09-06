#include<raylib.h>
#include<cmath>
using namespace std;
const int height=800, width=1000;

void drawCircles(Camera2D camera)
{
    float circleDistance=50.0f;

    while(circleDistance*camera.zoom>50.0f)
        circleDistance/=2.0f;

    while(circleDistance*camera.zoom<25.0f)
        circleDistance*=2.0f;

    float halfVisibleWidth=width/(2.0f*camera.zoom);
    float halfVisibleHeight=height/(2.0f*camera.zoom);
    float visibleRadius=sqrt(halfVisibleWidth*halfVisibleWidth+halfVisibleHeight*halfVisibleHeight);
    float distanceFromCenter=sqrt(camera.target.x*camera.target.x+camera.target.y*camera.target.y);
    float minRadius=distanceFromCenter-visibleRadius;
    float maxRadius=distanceFromCenter+visibleRadius;

    if(minRadius<0)
        minRadius=0;

    int firstCircle=int(minRadius/circleDistance);
    int lastCircle=int(maxRadius/circleDistance)+1;

    if(firstCircle<1)
        firstCircle=1;

    for(int i=firstCircle; i<=lastCircle; i++)
    {
        float radius=i*circleDistance;
        DrawCircleLines(0, 0, radius, BLUE);
    }
}
void updateCamera(Camera2D &camera)
{
    const float cameraSpeed=300.0f;

    float wheel=GetMouseWheelMove();

    if(wheel!=0)
    {
        Vector2 mousePosition=GetMousePosition();
        Vector2 beforeZoom=GetScreenToWorld2D(mousePosition, camera);

        if(wheel>0)
            camera.zoom*=1.1f;

        if(wheel<0)
            camera.zoom/=1.1f;

        if(camera.zoom<0.01f)
            camera.zoom=0.01f;

        if(camera.zoom>1000.0f)
            camera.zoom=1000.0f;

        Vector2 afterZoom=GetScreenToWorld2D(mousePosition, camera);

        camera.target.x+=beforeZoom.x-afterZoom.x;
        camera.target.y+=beforeZoom.y-afterZoom.y;
    }

    float movementFactor=camera.zoom;

    if(movementFactor<1.0f)
        movementFactor=1.0f;

    if(movementFactor>3.0f)
        movementFactor=3.0f;

    float movement=cameraSpeed*GetFrameTime()*
                   movementFactor/camera.zoom;

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
        camera.rotation=0.0f;
        camera.zoom=1.0f;
    }
}

int main()
{
    InitWindow(width, height, "Camera Playground");
    SetTargetFPS(60);

    Camera2D camera{};
    camera.target={0.0f, 0.0f};
    camera.offset={width/2.0f, height/2.0f};
    camera.rotation=0.0f;
    camera.zoom=1.0f;

    while(!WindowShouldClose())
    {
        updateCamera(camera);
        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode2D(camera);
        drawCircles(camera);
        EndMode2D();
        EndDrawing();
    }

    CloseWindow();
}