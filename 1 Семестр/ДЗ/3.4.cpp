#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

bool is_digit(string str)
{
    string nums = "0123456789";
    for (int i = 0; i < str.length(); ++i)
        if (nums.find(str[i]) == string::npos)
            return false;
    return true;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    cout << "Генерация случайного файла..." << endl;
    ofstream fout("file.txt");
    for (int i = 0; i < 20; ++i)
    {
        bool is_char = rand() % 2;
        char chars[] = {"QWERTYUIOPASDFGHJKLZXCVBNM"};
        if (is_char)
            fout << chars[rand() % 26] << " ";
        else
            fout << rand() % 10 << " ";
    }
    fout.close();
    cout << "Случайный файл сгенерирован" << endl;
    ifstream fin("file.txt");
    while (!fin.eof())
    {
        string c;
        fin >> c;
        if (is_digit(c))
            cout << c << endl;
    }
    fin.close();
    return 0;
}
