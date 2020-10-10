#include <iostream>
#include <cmath>

using namespace std;

long long gcd(long long a, long long b)
{
    a = abs(a);
    b = abs(b);
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите кол-во чисел: ";
    int n;
    cin >> n;
    while (true)
    {
        bool correct = true;
        if (n == 1)
        {
            cerr << "НОД от 1 числа? Интересно)) Введите еще раз" << endl;
            correct = false;
        }
        if (n == 0)
        {
            cerr << "НОД от 0 чисел? Зачем тогда нужно было запускать эту программу? Отключаюсь..." << endl;
            correct = false;
            return 0;
        }
        if (n < 0)
        {
            cerr << "Количество чисел может быть отрицательным? Вот это прикол, хд. Введите еще раз" << endl;
            correct = false;
        }
        if (correct)
            break;
        cin >> n;
    }
    cout << "Введите сами числа: ";
    int result;
    cin >> result;
    for (int i = 1; i < n; ++i)
    {
        int a;
        cin >> a;
        result = gcd(result, a);
    }
    cout << "НОД всех чисел: " << result;
    return 0;
}
