#include <iostream>

using namespace std;

size_t s1 = 0, s2 = 0; //начальные значения

size_t random1()
{
    s1 = (37*s1 + 3) % 64;
    return s1;
}

size_t random2()
{
    s2 = (25173 * s2 + 13849) % 65537;
    return s2;
}

int main()
{
    //просто выводим 10 случайных чисел
    for (int i = 0; i < 10; ++i)
    {
        cout << random1() << " " << random2() << endl;
    }
    return 0;
}
