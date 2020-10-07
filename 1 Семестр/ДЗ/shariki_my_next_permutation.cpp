#include <iostream>
#include <vector>
#define SZ 10

using namespace std;

//все пояснения по поводу использованного алгоритма здесь
//https://ru.wikipedia.org/wiki/%D0%90%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC_%D0%9D%D0%B0%D1%80%D0%B0%D0%B9%D0%B0%D0%BD%D1%8B
//по такому же алгоритму работает встроенная функция next_permutation() которая находится в <algorithm>
//но тут написал свою, вдруг на защите докопаются
void my_next_permutation(int *arr, int sz)
{
    int i = sz - 2;
    while (arr[i] >= arr[i + 1] && i >= 0)
        --i;
    if (i == -1)
    {
        arr[0] = -1;
        return;
    }
    int j = sz - 1;
    while (arr[j] <= arr[i] && j > i)
        --j;
    int sw = arr[i];
    arr[i] = arr[j];
    arr[j] = sw;
    for (int k = 1; k < sz - k - i; ++k)
    {
        sw = arr[k + i];
        arr[k + i] = arr[sz - k];
        arr[sz - k] = sw;
    }
    return;
}

int main()
{
    int *balls = new int[SZ];
    for (int i = 0; i < SZ; ++i)
        balls[i] = i;
    int counter = 0;
    while (balls[0] != -1)
    {
        for (int i = 0; i < SZ; ++i)
        {
            if (balls[i] == i)
            {
                ++counter;
                break;
            }
        }

        my_next_permutation(balls, SZ);
    }
    cout << counter;
    delete[] balls;
    return 0;
}
