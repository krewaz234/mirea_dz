#include <iostream>
#include <fstream>
#include <ctime>

#define MAX_NUM 100

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
            fout << chars[rand() % chars.length()] << " ";
        else
            fout << rand() % MAX_NUM << " ";
    }
    fout.close();
    cout << "Случайный файл сгенерирован" << endl;
    ifstream fin("file.txt");
    string str;
    while (fin >> str)
    {
        bool isnumber = true;
        for (char c: str)
            if (c < '0' || c > '9')
            {
                isnumber = false;
                break;
            }
        if (isnumber)
            cout << str << " ";
    }
    fin.close();
    return 0;
}
