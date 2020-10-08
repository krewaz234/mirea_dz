#include <iostream>
#include <ctime>
#include <algorithm>
#include <windows.h>

using namespace std;

int main()
{
    //устанавливаем полную поддержку русского языка
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    string s;
    cout << "Введите строку:" << endl;
    getline(cin, s);
    
    //удаление небуквенных символов
    for (size_t i = 0; i < s.length(); ++i)
        if (!isalpha(s[i]))
            s.erase(i--, 1);
    
    //сортировка
    for (size_t i = 0; i < s.length() - 1; ++i)
    {
        for (size_t j = i + 1; j < s.length(); ++j)
        {
            if (s[i] > s[j])
            {
                char temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }

    //удаление повторяющихся символов
    //делается строго после сортировки
    for (size_t i = 0; i < s.length() - 1; ++i)
        if (s[i] == s[i + 1])
            s.erase(i--, 1);
    
    cout << "Преобразованная строка: " << s << endl;
    return 0;
}
