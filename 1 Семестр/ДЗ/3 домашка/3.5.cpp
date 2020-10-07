#include <iostream>
#include <ctime>
#include <algorithm>

#define SZ 30

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    string s;
    for (int i = 0; i < SZ; ++i)
        s += rand() % 26 + 65;
    cout << "Исходная строка: " << s << endl;
    sort(s.begin(), s.end());
    cout << "Отсортированная строка: " << s << endl;
    return 0;
}
