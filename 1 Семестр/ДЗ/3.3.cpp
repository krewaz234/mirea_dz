#include <iostream>
#include <fstream>
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
    int value;
    while (fin >> value)
        cout << value << " ";
    fin.close();
    return 0;
}
