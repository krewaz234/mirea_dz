#include <iostream>

using namespace std;

int sign(double x)
{
    if (x < 0)
        return -1;
    if (x == 0)
        return 0;
    return 1;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    double x;
    cout << "Введите число для вычисления sign(x): ";
    cin >> x;
    cout << "sign(x) = " << sign(x) << endl;
    return 0;
}
