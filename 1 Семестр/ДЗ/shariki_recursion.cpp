//та же самая задача с шариками, но через рекурсию
#include <iostream>

using namespace std;

size_t counter = 0;
void rec(int *balls, size_t k = 0)
{
    if (k == 10)
    {
        for (int i = 0; i < 10; ++i)
        {
            if (balls[i] == i)
            {
                ++counter;
                return;
            }
        }
        return;
    }
    for (int i = 0; i < 10; ++i)
    {
        bool f = false;
        for (int j = 0; j < k; ++j)
        {
            if (i == balls[j])
            {
                f = true;
                break;
            }
        }
        if (!f)
        {
            balls[k] = i;
            rec(balls, k + 1);
            balls[k] = -1;
        }
    }
}

int main()
{
    int *balls = new int[10];
    for (int i = 0; i < 10; ++i)
        balls[i] = -1;
    rec(balls);
    cout << counter;
    return 0;
}
