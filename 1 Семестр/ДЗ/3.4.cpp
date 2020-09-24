#include <iostream>
#include <fstream>
#include <ctime>
#include <algorithm>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    cout << "Генерация случайного файла..." << endl;
    ofstream fout("file.txt");
    for (int i = 0; i < 20; ++i)
    {
        bool is_char = rand() % 2;
        string chars = "QWERTYUIOPASDFGHJKLZXCVBNM";
        if (is_char)
            fout << chars[rand() % 26] << " ";
        else
            fout << rand() % 100 << " ";
    }
    fout.close();
    cout << "Случайный файл сгенерирован" << endl;
    ifstream fin("file.txt");
    while (!fin.eof())
    {
        string c;
        fin >> c;
        if (all_of(c.cbegin(), c.cend(), [](char c){return isdigit(c);}))
            cout << c << endl;
    }
    fin.close();
    return 0;
}
