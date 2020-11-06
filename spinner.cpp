#include <iostream>
#include <map>

using namespace std;

void F1()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << (c - a) / b - ((c - a) % b == 0);
}

void F2()
{
    unsigned long long n;
    cin >> n;
    if (n == 5 || n < 3)
    {
        cout << 0 << endl << 0;
        exit(0);
    }
    int i = 0;
    while ((n - i*4) % 3 != 0)
        ++i;
    cout << (n - i*4) / 3 << endl << i;
}

void F3()
{
    int n, m;
    cin >> n >> m;
    unsigned long long sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            sum += (n - i + 1) * (m - j + 1);
        }
    }
    cout << sum;
}

void F4()
{
    int n;
    cin >> n;
    int k1[9], k2[9];
    for (int i = 0; i < 9; ++i)
        k1[i] = k2[i] = 0;
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        if (a <= 36)
            ++k1[a / 4 - (a % 4 == 0)];
        else
            ++k2[a / 2 - (a % 2) - 19];
    }
    int ans = 0;
    int maxlen = 0, _len = 0;
    for (int i = 0; i < 9; ++i)
    {
        if (k1[i] != 4)
        {
            maxlen = max(_len, maxlen);
            _len = 0;
            continue;
        }
        ++_len;
    }
    ans = max(ans, maxlen);
    maxlen = _len = 0;
    for (int i = 0; i < 9; ++i)
    {
        if (k2[i] != 2)
        {
            maxlen = max(maxlen, _len);
            _len = 0;
            continue;
        }
    }
    cout << max(ans, maxlen);
}

void F5()
{
    long long n, k;
    cin >> n >> k;
    map<long long, long long> counters;
    counters.insert({n, 1});
    long long a = -1, b = -1;
    while (k > 0)
    {
        auto maxnum_element = counters.end();
        advance(maxnum_element, -1);
        auto f1 = counters.find(maxnum_element->first / 2);
        auto f2 = counters.find(maxnum_element->first / 2 - (maxnum_element->first % 2 == 0));
        if (f1 == counters.end())
            counters.insert({maxnum_element->first / 2, maxnum_element->second});
        else
            f1->second += maxnum_element->second;
        if (f2 == counters.end())
            counters.insert({maxnum_element->first / 2 - (maxnum_element->first % 2 == 0), maxnum_element->second});
        else
            f2->second += maxnum_element->second;
        a = maxnum_element->first / 2 - (maxnum_element->first % 2 == 0);
        b = maxnum_element->first / 2;
        k -= maxnum_element->second;
        counters.erase(maxnum_element);
    }
    cout << a << endl << b;
}

int main()
{
    //insert code here
    return 0;
}
