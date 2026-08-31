#include<iostream>
#include<fstream>
using namespace std;
const int height = 800, width = 600;
struct Color
{
    int r, g, b;
};
const Color gridColor={209, 209, 209}, bgColor={255, 255, 255}, graphColor={0, 0, 255}, axesColor={0, 0, 0};
Color canvas[height][width];
void drawGrid()
{
    const int ox = height / 2, oy = width / 2;
    //background
    for(int i=0; i<height; i++)
        for(int j=0; j<width; j++)
            canvas[i][j]=bgColor;

    //grid scheme
    for(int i=0; i<height; i+=10)
        for(int j=0; j<width; j++)
            canvas[i][j]=gridColor;
    for(int i=0; i<height; i++)
        for(int j=0; j<width; j+=10)
            canvas[i][j]=gridColor;

    //axes
    for(int i=0; i<height; i++)
        for(int j=0; j<width; j++)
            if(i==ox || j==oy)
                canvas[i][j]=axesColor;
}
void drawGraph()
{
    //TODO
}
void saveToPPM(const string& filename, Color canvas[height][width])
{
    ofstream file(filename);
    file<<"P3\n";
    file<<width<<" "<<height<<'\n';
    file<<"\n255\n";
    for(int i=0; i<height; i++)
        for(int j=0; j<width; j++)
            file<<canvas[i][j].r<<" "<<canvas[i][j].g<<" "<<canvas[i][j].b<<'\n';
    file.close();
}
int main()
{
    drawGrid();
    drawGraph();
    saveToPPM("canvas.ppm", canvas);
}
