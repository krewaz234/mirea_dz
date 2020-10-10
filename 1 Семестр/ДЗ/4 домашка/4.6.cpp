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

int digit(char c)
{
    if (c == 'I' || c == 'V' || c == 'X')
        return 0;
    if (c == 'L' || c == 'C' || c == 'D')
        return 1;
    return 2;
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
    //проверяем на 3 одинаковых, стоящих в 1 разряде
    if (s.length() > 2)
    {
        for (int i = 0; i < s.length() - 3; ++i)
        {
            if (digit(s[i]) != 2
            &&  digit(s[i]) == digit(s[i + 1])
            &&  digit(s[i + 1]) == digit(s[i + 2])
            &&  digit(s[i + 2]) == digit(s[i + 3]))
            {
                cerr << "Введено неверное число (по правилу записи римских чисел, рядом не могут стоять 3 цифры одинакового разряда). Перезапустите программу и повторите ввод.";
                return 0;
            }
        }
    }
    //проверяем, что числа одного разряда стоят рядом
    bool is_digit_entered[] = {0, 0, 0};
    int prev = digit(s[0]);
    for (int i = 1; i < s.length(); ++i)
    {
        if (is_digit_entered[digit(s[i])])
        {
            cerr << "Цифры, харакетризующие один разряд должны стоять рядом. Перезапустите программу и повторите ввод.";
            return 0;
        }
        if (digit(s[i]) < prev)
            is_digit_entered[prev] = 1;
        else
            if (digit(s[i]) > prev)
            {
                cerr << "Разряды в записи римского числа должны быть расположены по убыванию. Перезапустите программу и повторите попытку ввода.";
                return 0;
            }
        prev = digit(s[i]);
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
