#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    ofstream fout("file.txt");
    for (int i = 0; i < 10; ++i)
    {
        int n = rand() % 100;
        fout << n << endl;
        cout << "В файл записано число " << n << endl;
    }
    fout.close();
    ifstream fin("file.txt");
    int sum = 0;
    while (!fin.eof())
    {
        int n;
        fin >> n;
        sum += n;
    }
    cout << "Сумма чисел в файле: " << sum << endl;
    return 0;
}
