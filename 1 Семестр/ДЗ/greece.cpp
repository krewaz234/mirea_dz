#include <iostream>
#include <windows.h>

#define BLUE 16
#define WHITE 240
#define WIDTH 30
#define HEIGHT 9

using namespace std;

void draw(char **matr)
{
    for (int i = 0; i <= 5; ++i)
    {
        matr[i][WIDTH/6-1] = '*';
        matr[i][WIDTH/6] = '*';
    }
    for (int i = 0; i < WIDTH/3; ++i)
    {
        matr[2][i] = '*';
        matr[3][i] = '*';
    }
    for (int i = 0; i < HEIGHT; ++i)
    {
        for (int j = 0; j < WIDTH; ++j)
        {
            cout << matr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    char **matr = new char*[HEIGHT];
    for (int i = 0; i < HEIGHT; ++i)
        matr[i] = new char[WIDTH];
    for (int i = 0; i < HEIGHT; ++i)
    {
        for (int j = 0; j < WIDTH; ++j)
        {
            matr[i][j] = ' ';
        }
    }
    draw(matr);
    return 0;
}
