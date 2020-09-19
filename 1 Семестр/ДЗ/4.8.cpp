#include <iostream>

#define AN 3
#define AM 4
#define BN 4
#define BM 2

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	double A[AN][AM] = { {5, 2, 0, 10}, {3, 5, 2, 5}, {20, 0, 0, 0} };
	double B[BN][BM] = { {1.20, 0.50}, {2.80, 0.40}, {5.0, 1.0}, {2.0, 1.5} };
	int ans[AN][BM];
	for (size_t i = 0; i < AN; ++i)
		for (size_t j = 0; j < BM; ++j)
			ans[i][j] = 0;
	for (size_t i = 0; i < AN; ++i)
		for (size_t j = 0; j < BM; ++j)
			for (size_t k = 0; k < AM; ++k)
				ans[i][j] += A[i][k] * B[k][j];
	//считаем наибольшую выручку
	int max = ans[0][0], ind1 = 0, min = ans[0][0], ind2 = 0;
	for (size_t i = 0; i < AN; ++i)
	{
		if (max < ans[i][0])
		{
			max = ans[i][0];
			ind1 = i + 1;
		}
		if (min > ans[i][0])
		{
			min = ans[i][0];
			ind2 = i + 1;
		}
	}
	cout << "Наибольшая выручка у продавца " << ind1 << "; Наименьшая у продавца " << ind2 << endl;

	//считаем наибольшие комиссионные
	max = ans[0][1]; ind1 = 0; min = ans[0][1]; ind2 = 0;
	for (size_t i = 0; i < AN; ++i)
	{
		if (max < ans[i][0])
		{
			max = ans[i][0];
			ind1 = i + 1;
		}
		if (min > ans[i][0])
		{
			min = ans[i][0];
			ind2 = i + 1;
		}
	}
	cout << "Наибольшие комиссионные у продавца " << ind1 << "; Наименьшая у продавца " << ind2 << endl;

	//общая цена проданной продукции
	int total_price = 0;
	for (size_t i = 0; i < AN; ++i)
		total_price += ans[i][0];
	cout << "Всего товаров продано на " << total_price << endl;

	//общий размер комиссионных
	int total_com = 0;
	for (size_t i = 0; i < AN; ++i)
		total_com += ans[i][1];
	cout << "Всего комиссионных: " << total_com << endl;

	cout << "Всего через руки продавцов прошло " << total_price + total_com << " денег" << endl;
	return 0;
}
