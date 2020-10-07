#include <iostream>
#include <windows.h>

#define WHITE 79
#define RED 240
#define BLUE_BG 31
#define STANDART_COLOR_SCHEME 15

using namespace std;

int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < 13; ++i)
    {
        WORD stripeColor = (i % 2) ? (RED) : (WHITE);
        if (i >= 0 && i <= 5)
        {
            SetConsoleTextAttribute(hConsole, BLUE_BG);
            for (int j = 0; j < 8; ++j)
                cout << "* ";
            SetConsoleTextAttribute(hConsole, stripeColor);
            for (int j = 8; j < 49-8; ++j)
                cout << " ";
        }
        else
        {
            SetConsoleTextAttribute(hConsole, stripeColor);
            for (int j = 0; j < 49; ++j)
                cout << " ";
        }
        cout << endl;
    }
    SetConsoleTextAttribute(hConsole, STANDART_COLOR_SCHEME);
    return 0;
}
