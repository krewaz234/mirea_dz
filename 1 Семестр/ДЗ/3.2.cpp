#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите S, m, n: ";
    double S, m, n;
    cin >> S >> m >> n;
    for (int i = 0; i < 101; ++i)
    {
        double r = (double)i/100.0;
        if (m == (S*r*pow(1 + r, n)) / (12*(pow(1 + r, n) - 1)))
        {
            cout << "p = " << i;
            exit(0);
        }
    }
    cerr << "Значение не найдено. Проверьте правильность введенных данных.";
    return 0;
}
