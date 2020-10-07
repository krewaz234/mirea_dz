#include <iostream>
#include <fstream>
#include <ctime>

#define NUMS 3

using namespace std;

int main()
{
    srand(time(0));
    setlocale(LC_ALL, "Russian");
    ofstream fout("file.txt");
    for (int i = 0; i < NUMS; ++i)
    {
        int n = rand() % 10;
        fout << n << endl;
        cout << "В файл записано число " << n << endl;
    }
    fout.close();
    ifstream fin("file.txt");
    int sum = 0, n;
    while (fin >> n)
        sum += n;
    fin.close();
    cout << "Сумма чисел в файле: " << sum << endl;
    return 0;
}
