#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <windows.h>

#define ENCODING 1251

using namespace std;

void transform_string(string &s);
bool open_dict(const char *file_dir, vector<string> &dictionary);
string lower_str(string s);

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(ENCODING);
    SetConsoleOutputCP(ENCODING);

    cout << "Введите строку: ";
    string s;
    getline(cin, s);
    transform_string(s);
    cout << "Преобразованная строка: " << s << endl
         << "Из этих букв можно составить слова:" << endl;

    vector<string> dict;
    open_dict("dict.txt", dict);

    string *temp = new string(lower_str(s));
    for (size_t i = 0; i < dict.size(); ++i)
    {
        bool x = true;
        for (size_t j = 0; j < dict[i].size(); ++j)
        {
            if (temp->find(dict[i][j]) == string::npos)
            {
                x = false;
                break;
            }
        }
        if (x)
            cout << dict[i] << endl;
    }
    delete temp;
    return 0;
}


/** \brief Сортировка строки, удаление
 *  небуквенных и повторяющихся символов.
 *
 * \param string &s - ссылка на строку,
 * которую нужно привести к "правильному" виду.
 *
 * \return ничего не возвращает, просто изменяет строку.
 *
 */

void transform_string(string &s)
{
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
    for (size_t i = 0; i < s.length() - 1; ++i)
        if (s[i] == s[i + 1])
            s.erase(i--, 1);

    //удаление небуквенных символов
    for (size_t i = 0; i < s.length(); ++i)
        if (!isalpha(s[i]))
            s.erase(i--, 1);
}


/** \brief Импорт словаря из текстового файла.
 * В текстовом файле должны содержаться слова
 * для поиска через пробел или с новой строки.
 *
 * \param const char *file_dir - директория
 * текстового файла.
 *
 * \param vector<string> &dictionary - словарь, куда
 * нужно записать слова из файла.
 *
 * \return
 * Возвращает true, если словарь был успешно
 * импортирован, false, если не удалось открыть файл
 * со словарем.
 */

bool open_dict(const char *file_dir, vector<string> &dictionary)
{
    dictionary.clear();
    ifstream fin(file_dir);

    if (!fin.is_open())
        return false;

    string word;
    while (fin >> word)
        dictionary.push_back(lower_str(word));

    fin.close();
    return true;
}


/** \brief Изменяет все заглавные буквы
 * строки на прописные.
 *
 * \param string s - строка, которую нужно изменить.
 *
 * \return Возвращает измененную строку.
 *
 */

string lower_str(string s)
{
    for (size_t i = 0; i < s.length(); ++i)
        s[i] = tolower(s[i]);
    return s;
}
