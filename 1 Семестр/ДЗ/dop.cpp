#include <iostream>

using std::cin;
using std::cout;

template<typename T>
T get_Q(T arr[], size_t sz)
{
    size_t N = sz / 3;
    T pr = 1;
    T Q = 0;
    for (int i = 0; i < sz; ++i)
    {
        pr *= arr[i];
        if ((i + 1) % N == 0)
        {
            Q += pr;
            pr = 1;
        }
    }
    return Q;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите N: ";
    long long N;
    cin >> N;
    cout << "Введите 3N чисел (" << 3*N << " чисел): ";
    long long arr[3*N];
    for (int i = 0; i < 3*N; ++i)
        cin >> arr[i];
    cout << "Q = " << get_Q(arr, 3*N);
    return 0;
}
