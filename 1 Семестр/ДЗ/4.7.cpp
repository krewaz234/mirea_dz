#include <iostream>

using namespace std;

size_t s1 = 0, s2 = 0;

size_t random1()
{
    return s1 = (37*s1 + 3) % 64;
}

size_t random2()
{
    return s2 = (25173 * s2 + 13849) % 65537;
}

int main()
{
    for (int i = 0; i < 10; ++i)
    {
        cout << random1() << " " << random2() << endl;
    }
    return 0;
}
