#include <iostream>
#include <cmath>
#define err 1e-5

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите S, m, n: ";
    double S, m, n;
    cin >> S >> m >> n;
    double L = 0, R = 100;
    while (R - L > err)
    {
        double now = (L + R) / 2.0, r = now / 100.0;
        if (((S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1))) > m)
            R = now - err;
        else
            L = now;
    }
    cout << "p = " << L;
    return 0;
}
