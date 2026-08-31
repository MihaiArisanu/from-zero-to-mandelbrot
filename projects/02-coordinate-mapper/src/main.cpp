#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
using namespace std;
const int height = 800, width = 1600;
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
void drawSqGraph()
{
    const double scale=10.0;
    int prevI=0;
    bool hasPrev=false;

    for(int j=0; j<width; j++)
    {
        double x=(j-width/2)/scale;
        double y=x*x;
        int i=int(height/2-y*scale);
        if(i>=0 && i<height)
        {
            if(hasPrev)
            {
                int first=i;
                int last=prevI;

                if(first>last)
                {
                    int aux=last;
                    last=first;
                    first=aux;
                }

                for(int k=first; k<=last; k++)
                    canvas[k][j]=graphColor;
            }
            else
                canvas[i][j]=graphColor;

            hasPrev=true;
            prevI=i;
        }
        else
            hasPrev=false;
    }
}
void drawSqrtGraph()
{
    const double scale=10.0;
    int prevI=0;
    bool hasPrev=false;

    for(int j=width/2; j<width; j++)
    {
        double x=(j-width/2)/scale;
        double y=sqrt(x);
        int i=int(height/2-y*scale);
        if(i>=0 && i<height)
        {
            if(hasPrev)
            {
                int first=i;
                int last=prevI;

                if(first>last)
                {
                    int aux=last;
                    last=first;
                    first=aux;
                }

                for(int k=first; k<=last; k++)
                    canvas[k][j]=graphColor;
            }
            else
                canvas[i][j]=graphColor;

            hasPrev=true;
            prevI=i;
        }
        else
            hasPrev=false;
    }
}
void drawLogGraph()
{
    const double scale=10.0;
    int prevI=0;
    bool hasPrev=false;

    for(int j=width/2+1; j<width; j++)
    {
        double x=(j-width/2)/scale;
        double y=log(x);
        int i=int(height/2-y*scale);
        if(i>=0 && i<height)
        {
            if(hasPrev)
            {
                int first=i;
                int last=prevI;

                if(first>last)
                {
                    int aux=last;
                    last=first;
                    first=aux;
                }

                for(int k=first; k<=last; k++)
                    canvas[k][j]=graphColor;
            }
            else
                canvas[i][j]=graphColor;

            hasPrev=true;
            prevI=i;
        }
        else
            hasPrev=false;
    }
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
    string s;
    cout<<"This program generates the graph of these 3 functions: square, square root and log"<<'\n';
    cout<<"Please choose a function: for square type 2, for square root type sqrt and for log type log"<<'\n';
    cin>>s;
    if(s!="2" && s!="sqrt" && s!="log")
    {
        cout<<"Next time choose one of them"<<'\n';
        return 0;
    }

    drawGrid();
    if(s=="2")
    {
        drawSqGraph();
        saveToPPM("canvasSquare.ppm", canvas);
    }
    else if(s=="log")
    {
        drawLogGraph();
        saveToPPM("canvasLog.ppm", canvas);
    }
    else
    {
        drawSqrtGraph();
        saveToPPM("canvasSqrt.ppm", canvas);
    }

}