#include <iostream>
#include <map>

using namespace std;

//преобразование одной римской цифры в арабское число
int char_to_number(char c)
{
    switch (c)
    {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите число в римской системе счисления: ";
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); ++i)
        s[i] = toupper(s[i]); //все символы делаем большими
    int result = 0; //конечный результат
    for (size_t i = 0; i < s.length() - 1; ++i)
    {
        int n1 = char_to_number(s[i]), n2 = char_to_number(s[i + 1]); //2 соседних цифры
        //любое римское число переводится по правилу:
        //если перед большей цифрой стоит меньшая - мы ее отнимаем
        //если перед меньшей цифрой стоит большая - мы ее прибавляем
        //как пример: IV - 4; VI - 6
        if (n1 < n2)
            result -= n1;
        else
            result += n1;
    }
    result += char_to_number(s.back()); //последняя цифра всегда прибавляется
    cout << "Его представление в десятичном виде: " << result << endl;
    return 0;
}
