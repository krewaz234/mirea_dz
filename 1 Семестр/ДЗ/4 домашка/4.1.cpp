#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int main()
{
    //обновляем сид рандома, чтобы при каждом новом запуске программы были разные рандомные числа
    srand(time(0));
    setlocale(LC_ALL, "Russian");
    ofstream fout("file.txt");
    for (int i = 0; i < NUMS; ++i)
    {
        //случайное число в диапазоне от 0 до 10
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
