#include <iostream>

using namespace std;

int balls[100];
int counter = 0;

void perestanovka(int m, int n)
{
    if (m == n - 1)
    {
        bool x = false;
        for (int i = 0; i < n; ++i)
            if (balls[i] == i)
            {
                x = true;
                break;
            }
        if (!x)
            return;
        //for (int i = 0; i < n; ++i)
        //    cout << balls[i] << " ";
        //cout << endl;
        ++counter;
        return;
    }
    for (int i = m; i < n; ++i)
    {
        int temp = balls[i];
        balls[i] = balls[m];
        balls[m] = temp;
        perestanovka(m + 1, n);
        temp = balls[i];
        balls[i] = balls[m];
        balls[m] = temp;
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        balls[i] = i;
    perestanovka(0, n);
    cout << counter;
    return 0;
}
