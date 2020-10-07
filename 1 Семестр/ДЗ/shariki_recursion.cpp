//та же самая задача с шариками, но через рекурсию
//(оптимизировал поиск использованных чисел)
//если не понимаете рекурсию, то самый лучший способ ее понять
//это порешать задачи на эту тему, например отсюда
//https://habr.com/ru/post/275813/
#include <iostream>

using namespace std;

size_t counter = 0;
void rec(int *balls, size_t k = 0)
{
    if (k == 10) //терминальное условие (рекурсия закончила свою работу, нужно выполнить проверки и вернуться назад)
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
    
    //used[i] будет равно true если число i присутствует в массиве на текущем шаге рекурсии, иначе false
    bool used[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 10; ++i)
        used[balls[i]] = true;
    for (int i = 0; i < 10; ++i)
    {
        if (!used[i]) //если число еще не использовали, то берем его и переходим на след. шаг рекурсии
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
    rec(balls); //понеслась
    cout << counter;
    return 0;
}
