//Решето:
//https://ru.wikipedia.org/wiki/%D0%A0%D0%B5%D1%88%D0%B5%D1%82%D0%BE_%D0%AD%D1%80%D0%B0%D1%82%D0%BE%D1%81%D1%84%D0%B5%D0%BD%D0%B0
//Евклид:
//https://ru.wikipedia.org/wiki/%D0%90%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC_%D0%95%D0%B2%D0%BA%D0%BB%D0%B8%D0%B4%D0%B0
#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

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
