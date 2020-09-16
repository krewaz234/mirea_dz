#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

size_t numeral_to_decimal(char numeral)
{
    string numerals = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    return numerals.find(numeral);
}

char decimal_to_numeral(size_t decimal)
{
    string numerals = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    return numerals[decimal];
}

bool is_correct(int notation, string number)
{
    if (notation < 2 || notation > 36)
        return false;
    string numerals = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    numerals = numerals.substr(0, notation);
    for (size_t i = 0; i < number.length(); ++i)
        if (numerals.find(number[i]) == string::npos)
            return false;
    return true;
}

string convert_number(string number, size_t st_notation, size_t con_notation)
{
    //converting to decimal
    size_t decimal = 0;
    for (int i = number.length() - 1, deg = 0; i >= 0; --i, ++deg)
        decimal += numeral_to_decimal(number[i]) * pow(st_notation, deg);

    //converting to con_notation
    string ans = "";
    while (decimal > 0)
    {
        ans += decimal_to_numeral(decimal % con_notation);
        decimal /= con_notation;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите число в какой либо системе счисления:" << endl;
    string number;
    getline(cin, number);
    cout << "Введите начальную систему счисления: ";
    int st_notation;
    cin >> st_notation;
    if (!is_correct(st_notation, number))
    {
        cerr << "Неверный ввод. Перезапустите программу и повторите ввод." << endl;
        return 0;
    }
    cout << "Введите систему счисления, в которую выполнить перевод: ";
    int con_notation;
    cin >> con_notation;
    cout << "Если число " << number << " перевести из " << st_notation << "-чной в " << con_notation << "-чную, получим: " << convert_number(number, st_notation, con_notation);
    return 0;
}
