#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//size_t это то же самое что и unsigned int
//Функция переводит какую то цифру (даже если она в буквенном виде)
//В десятичный эквивалент
//Например, если на вход дать '6', вернет 6
//На входе 'C', вернет 12
//Внутри функции нет проверок на то что на вход подаётся корректный символ
//Потому что проверка на то что ввод корректный в моем решении происходит в другой функции
//
size_t numeral_to_decimal(char numeral)
{
    string numerals = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    return numerals.find(numeral);
}

//Функция обратная предыдущей: получить по десятичному эквиваленту цифру
//Пример: на входе 12, вернет 'C'
//На входе 6, вернет '6'
char decimal_to_numeral(size_t decimal)
{
    string numerals = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    return numerals[decimal];
}

//Проверка на то что ввод корректен
bool is_correct(int notation, string number)
{
    //Если такая система счисления не существует
    if (notation < 2 || notation > 36)
        return false;
    string numerals = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    //Оставляем в numerals только те цифры, которые используются при записи числа
    //То есть первые notation цифр из строки выше
    //Notation это основание системы счисления
    numerals = numerals.substr(0, notation);
    //В цикле пробегаемся по всем цифрам числа и если
    //Какую то не нашли в numerals, значит была использована запрещённая цифра
    //и это значит что число записано неправильно
    for (size_t i = 0; i < number.length(); ++i)
        if (numerals.find(number[i]) == string::npos)
            return false;
    return true;
}

//Преобразование числа в конечную систему через промежуточную десятичную
string convert_number(string number, size_t st_notation, size_t con_notation)
{
    //Сначала преобразование в десятичную
    //Выполняется на основе разложения числа в полином
    size_t decimal = 0;
    for (int i = number.length() - 1, deg = 0; i >= 0; --i, ++deg)
        decimal += numeral_to_decimal(number[i]) * pow(st_notation, deg);

    //Приведение десятичного числа к конечной системе
    //При помощи машинного алгоритма
    string ans = "";
    while (decimal > 0)
    {
        ans += decimal_to_numeral(decimal % con_notation);
        decimal /= con_notation;
    }
    //Переворачиваем, чтобы получить конечный результат
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
