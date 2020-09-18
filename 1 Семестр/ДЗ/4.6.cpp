#include <iostream>
#include <map>
#include <algorithm>
#include <fstream>

using namespace std;

const map<char, int> n = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите число в римской системе счисления: ";
    string s;
    cin >> s;
    for (char &i: s) i = toupper(i);
    int result = 0;
    for (size_t i = 0; i < s.length() - 1; ++i)
    {
        int n1 = n.find(s[i])->second, n2 = n.find(s[i + 1])->second;
        result += n1 * (1 - 2*(n1 < n2));
    }
    result += n.find(s.back())->second;
    cout << "Его представление в десятичном виде: " << result << endl;
    return 0;
}
