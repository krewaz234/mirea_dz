//Объяснение алгоритма:
//https://ru.wikipedia.org/wiki/%D0%A0%D0%B5%D1%88%D0%B5%D1%82%D0%BE_%D0%AD%D1%80%D0%B0%D1%82%D0%BE%D1%81%D1%84%D0%B5%D0%BD%D0%B0
#include <iostream>

using namespace std;

void resheto(size_t n)
{
	++n;
	bool* arr = new bool[n];
	for (size_t i = 0; i < n; ++i)
		arr[i] = true;
	for (size_t i = 2; i < n; ++i)
	{
		if (arr[i])
		{
			for (size_t j = i*2; j < n; j += i)
				arr[j] = false;
		}
	}
	for (size_t i = 2; i < n; ++i)
		if (arr[i])
			cout << i << " ";
}

int main()
{
	//INSERT CODE HERE
	return 0;
}
