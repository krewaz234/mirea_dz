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
