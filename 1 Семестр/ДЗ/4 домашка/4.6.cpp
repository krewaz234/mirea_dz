#include <iostream>

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

int numeral_id(char numeral)
{
    string s = "IVXLCDM";
    return s.find(numeral);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите число в римской системе счисления: ";
    string s;
    getline(cin, s);
    for (int i = 0; i < s.length(); ++i)
        s[i] = toupper(s[i]); //все символы делаем большими
    //проверяем что все символы корректны
    for (int i = 0; i < s.length(); ++i)
    {
        string l = "IVXLCDM";
        if (l.find(s[i]) == string::npos)
        {
            cerr << "Введен неверный символ. Перезапустите программу и повторите ввод.";
            return 0;
        }
    }
    //проверяем цифры которые не могут повторяться
    int V_counter = 0, L_counter = 0, D_counter = 0;
    for (size_t i = 0; i < s.length(); ++i)
    {
        switch (s[i])
        {
        case 'V':
            ++V_counter;
            break;
        case 'L':
            ++L_counter;
            break;
        case 'D':
            ++D_counter;
            break;
        default:
            break;
        }
    }
    if (V_counter > 1 || L_counter > 1 || D_counter > 1)
    {
        cerr << "Цифры V, L, D могут встречаться в числе лишь единожды. Перезапустите программу и повторите ввод.";
        return 0;
    }
    //проверяем цифры, которые могут повторяться не больше 3 раз подряд
    if (s.length() > 3)
    {
        for (size_t i = 0; i < s.length() - 3; ++i)
        {
            string l = "IXCM";
            if (l.find(s[i]) != string::npos &&
                s[i] == s[i + 1] && s[i + 1] == s[i + 2] && s[i + 2] == s[i + 3])
            {
                cerr << "Цифры I, X, C, M не могут повторяться больше 3 раз подряд. Перезапустите программу и повторите ввод.";
                return 0;
            }
        }
    }
    //проверка на правильность вычитаемых цифр
    for (size_t i = 0; i < s.length() - 1; ++i)
    {
        string l = "IXCM";
        if (char_to_number(s[i]) < char_to_number(s[i + 1]) && (l.find(s[i]) == string::npos || numeral_id(s[i + 1]) - numeral_id(s[i]) > 2))
        {
            cerr << "Из старшего числа могут вычитаться только цифры равные степени десятки. К тому же, число должно быть ближайшим к вычитаемому. Перезапустите программу и повторите ввод.";
            return 0;
        }
    }
    //перевод
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
    result += char_to_number(s[s.length() - 1]); //последняя цифра всегда прибавляется
    cout << "Его представление в десятичном виде: " << result << endl;
    return 0;
}
