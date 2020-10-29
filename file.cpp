#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    cout << "Введите название файла, в который нужно записать текст.\nФайл должен лежать в одной папке с программой.\n";
    string s;
    getline(cin, s);
    ofstream fout(s.c_str(), ios::app);
    while (!fout.is_open())
    {
        cerr << "Файл с таким названием не найден. Повторите ввод.\n";
        getline(cin, s);
        fout.open(s.c_str(), ios::app);
    }
    cout << "Вводите текст, который нужно записать в конец файла.\nВведите / с новой строки для окончания ввода текста.\n\n";
    getline(cin, s);
    while (s != "/")
    {
        fout << s << endl;
        getline(cin, s);
    }
    fout.close();
    cout << "Текст записан.";
    return 0;
}
