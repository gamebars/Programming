#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

template <typename T>
void ArrayOuter(vector<T> arr)
{
	for (auto item : arr)
	{
		cout << item << " ";
	}
	cout << endl;
}

template <typename T>
vector<T> BozoSort(vector<T> arr, bool order = true)
{
	bool sorted = false;
	int n = arr.size();

	while (!sorted)
	{
		if (order)
		{
			std::swap(arr[rand() % n], arr[rand() % n]);

			sorted = true;

			for (int i = 1; i < n; i++)
			{
				if (arr[i - 1] > arr[i])
				{
					sorted = false;
					break;
				}
			}
		}
		else
		{
			std::swap(arr[rand() % n], arr[rand() % n]);

			sorted = true;

			for (int i = 1; i < n; i++)
			{
				if (arr[i - 1] < arr[i])
				{
					sorted = false;
					break;
				}
			}
		}
	}

	return arr;
}

template <typename T>
vector<T> BozoSort(vector<vector<T>> matrix, bool order = true)
{
	vector<T> arr;
	for (auto& row : matrix)
	{
		for (auto item : row)
		{
			arr.push_back(item);
		}
	}
	return BozoSort(arr, order);
}

template <typename T>
vector<T> BozoSort(T a, T b, T c, bool order = true)
{
	vector<T> arr{ a, b, c };
	return BozoSort(arr, order);
}

int main()
{
	setlocale(LC_ALL, "Russian");

	srand(time(0));
	int nD, sD, nS, sS;
	cout << "Введите количество элементов массива вещественных чисел\n";
	cin >> nD;
	sD = sqrt(nD);
	vector<double> arrD(nD);
	vector<vector<double>> matrixD(sD, vector<double>(sD));

	cout << "Заполните массив\n";
	for (int i = 0; i < nD; i++)
	{
		cin >> arrD[i];
	}

	int i = 0;
	while (i < nD)
	{
		for (int j = 0; j < sD; j++)
		{
			for (int k = 0; k < sD; k++)
			{
				matrixD[j][k] = arrD[i];
				i++;
			}
		}
	}

	cout << "Введите количество элементов массива строк\n";
	cin >> nS;
	sS = sqrt(nS);
	vector<string> arrS(nS);
	vector<vector<string>> matrixS(sS, vector<string>(sS));

	cout << "Заполните массив\n";
	for (int i = 0; i < nS; i++)
	{
		cin >> arrS[i];
	}

	i = 0;
	while (i < nS)
	{
		for (int j = 0; j < sS; j++)
		{
			for (int k = 0; k < sS; k++)
			{
				matrixS[j][k] = arrS[i];
				i++;
			}
		}
	}
	cout << endl;

	ArrayOuter(BozoSort(arrD));
	ArrayOuter(BozoSort(arrD, false));
	ArrayOuter(BozoSort(matrixD));
	ArrayOuter(BozoSort(matrixD, false));
	ArrayOuter(BozoSort(arrD[0], arrD[1], arrD[2]));
	ArrayOuter(BozoSort(arrD[0], arrD[1], arrD[2], false));
	ArrayOuter(BozoSort(arrS));
	ArrayOuter(BozoSort(arrS, false));
	ArrayOuter(BozoSort(matrixS));
	ArrayOuter(BozoSort(matrixS, false));
	ArrayOuter(BozoSort(arrS[0], arrS[1], arrS[2]));
	ArrayOuter(BozoSort(arrS[0], arrS[1], arrS[2], false));
}