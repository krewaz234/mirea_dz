#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int balls[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int counter = 0;
    do
    {
        for (int i = 0; i < 10; ++i)
        {
            if (balls[i] == i)
            {
                ++counter;
                break;
            }
        }

    } while (next_permutation(balls, balls + 10));
    cout << counter;
    return 0;
}
