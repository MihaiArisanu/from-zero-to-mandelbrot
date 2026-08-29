#include<iostream>
#include<fstream>
#include<string>
using namespace std;
const int width = 800, height = 600;
struct Color
{
    int r, g, b;
};
Color canvas[height][width];
Color c = {0, 0, 255}, bg = {255, 255, 255};
void drawCircle(Color c, Color bg, int r, Color canvas[height][width])
{
    int centerX=400, centerY=300;
    for(int i=0; i<height; i++)
        for(int j=0; j<width; j++)
        {
            int pointX=j, pointY=i;
            int difX=pointX-centerX, difY=pointY-centerY;
            if(r*r>=difX*difX+difY*difY)
                canvas[i][j]=c;
            else
                canvas[i][j]=bg;
        }
}
void drawSquare(Color c, Color bg, int l, Color canvas[height][width])
{
    int centerX=400, centerY=300;
    int half=l/2;
    for(int i=0; i<height; i++)
        for(int j=0; j<width; j++)
        {
            int pointX=j, pointY=i;
            if(abs(pointX-centerX)<=half && abs(pointY-centerY)<=half)
                canvas[i][j]=c;
            else
                canvas[i][j]=bg;
        }
}
void saveToPPM(const string& filename, Color canvas[height][width])
{
    ofstream file(filename);
    file<<"P3\n";
    file<<width<<" "<<height<<"\n";
    file<<"255\n";
for(int i=0; i<height; i++)
    for(int j=0; j<width; j++)
        file<<canvas[i][j].r<<" "<<canvas[i][j].g<<" "<<canvas[i][j].b<<"\n";

file.close();
}
int main()
{
    int len;
    string shape;
    cout<<"Please enter the shape of your image: "<<'\n';
    cout<<"You can choose one of this: square or circle"<<'\n';
    cout<<"To leave the program type 0"<<'\n';
    do
    {
        cin>>shape;
        if(shape=="0")
            break;
        if(shape=="square")
        {
            cout<<"Enter the length of your square: "<<'\n';
            cin>>len;
            drawSquare(c,bg,len,canvas);
            saveToPPM("canvasSquare.ppm",canvas);
            return 0;
        }
        else if(shape=="circle")
        {
            cout<<"Enter the radius of your circle: "<<'\n';
            cin>>len;
            drawCircle(c,bg,len,canvas);
            saveToPPM("canvasCircle.ppm",canvas);
            return 0;
        }
        else
            cout<<"Invalid shape"<<'\n';
    }while(shape!="0");
}