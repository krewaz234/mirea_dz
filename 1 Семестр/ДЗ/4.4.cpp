#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < 13; ++i)
    {
        WORD stripeColor = (i % 2) ? (240) : (79);
        if (i >= 0 && i <= 5)
        {
            SetConsoleTextAttribute(hConsole, 31);
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
    SetConsoleTextAttribute(hConsole, 15);
    return 0;
}
