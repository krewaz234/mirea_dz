#include <iostream>
#include <ctime>
#include <algorithm>
#include <string>
#include <windows.h>

using namespace std;

//моя функция, которая проверяет является ли символ буквой или нет
//на вход подается какой то символ char c, который нужно проверить
//функция возвращает true если символ является буквой и false, если не буква
//реализация:
//в строке letters хранятся все буквы, которые можно использовать для составления строки
//если мы смогли найти символ c в этой строке, то нужно вернуть true, иначе false
//выражение мы записали именно так, потому что функция find для строк возвращает первую позицию,
//где она нашла какой то символ/строку, а если она ничего не нашла, то она возвращает число string::npos
bool is_alpha(char c)
{
    string letters = "QWERTYUIOPASDFGHJKLZXCVBNMЙЦУКЕНГШЩЗХЪФЫВАПРОЛДЖЭЯЧСМИТЬБЮqwertyuiopasdfghjklzxcvbnmйцукенгшщзхъфывапролджэячсмитьбю";
    return (letters.find(c) != string::npos);
}


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
        if (!is_alpha(s[i])) //использую свою функцию вместо встроенной потому что в некоторых случаях она может не работать
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
