// dz3.3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    //создание случайного файла
    //файл содержит 10 чисел в 1 строке

    setlocale(LC_ALL, "Russian");
    ofstream fout("file.txt");
    for (size_t i = 0; i < 10; ++i)
        fout << rand() % 11 << " ";
    fout.close();
    cout << "Файл был создан" << endl;
    ifstream fin("file.txt");

    //печать файла
    cout << "Содержимое файла: \n";
    while (!fin.eof())
    {
        string s;
        getline(fin, s);
        cout << s << endl;
    }
    fin.close();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
