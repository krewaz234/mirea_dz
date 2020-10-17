#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

//ввод строки и сортировка по итератору
//любой язык, любая символьная последовательность
void t5()
{
    string str;
    cin>>str;
    int temp, i=0, a[str.size()]={};
    string::iterator it = str.begin();
    while(it != str.end() && i!=str.size())
    {
        a[i]=*it;
        it++;
        i++;
    }
    for (int i = 0; i <str.size(); i++)
    {
        for (int j = 0; j < str.size() - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    cout<<"Вывод с повторяющимися символами: "<<endl;
    for (int i = 0; i <str.size(); i++)
    {
        printf( "%c ", a[i]);
    }
    cout<<endl<<"Вывод без повторяющихся символов: "<<endl;
    for (int i = 0; i < sizeof(a) / sizeof(int); ++ i)
    {
        if (i > 0 && a[i] == a[i - 1]) continue;
        printf( "%c ", a[i]);
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
	cout << "t5\n"; t5();
}
