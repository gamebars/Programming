#include <iostream>
#include <ctime>
#include <vector>
#include <cstdlib>
// BozoSort 
using namespace std;
vector<int> BozoSort(vector<int> arr, bool sorted = true) {
	using namespace std;
	//Замена двух рандомных элементов в массиве.
	bool stop = false;

	while (!stop)
	{

		if (sorted)
		{
			swap(arr[rand() % arr.size()], arr[rand() % arr.size()]);
			stop = true;
			for (int i = 1; i < arr.size(); i++)
			{
				if (arr[i - 1] > arr[i])
				{
					stop = false;
					break;
				}
			}
		}
		else
		{
			swap(arr[rand() % arr.size()], arr[rand() % arr.size()]);

			stop = true;

			for (int i = 1; i < arr.size(); i++)
			{
				if (arr[i - 1] < arr[i])
				{
					stop = false;
					break;
				}
			}
		}

	}
	return arr;
}
void ArrayOutput(std::vector<int> arr) {
	for (auto item : arr)
	{
		std::cout << item << " ";
	}
	std::cout << std::endl;
}

vector<int> BozoSort(int a, int b, int c, bool order = true)
{
	vector<int> arr{ a, b, c };
	return BozoSort(arr, order);
}

vector<int> BozoSort(vector<vector<int>> matrix, bool sorted = true)
{
	vector<int> arr;
	for (auto& row : matrix)
	{
		for (auto item : row)
		{
			arr.push_back(item);
		}
	}
	return BozoSort(arr, sorted);
}



int main()
{

	setlocale(LC_ALL, "Russian");


	srand(time(0));
	//Создаю массив целых чисел ' vector '
	cout << "Введите кол-во символов требующих сортировки:" << endl;
	int n, s;
	cin >> n;
	s = sqrt(n);
	vector<int> arr(n);
	vector<vector<int>> matrix(s, vector<int>(s));
	cout << "Заполните массив" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int counter = 0;
	while (counter < n)
	{
		for (int j = 0; j < s; j++)
		{
			for (int k = 0; k < s; k++)
			{
				matrix[j][k] = arr[counter];
				counter++;
			}
		}
	}
	ArrayOutput(BozoSort(arr));
	ArrayOutput(BozoSort(arr, false));
	ArrayOutput(BozoSort(matrix));
	ArrayOutput(BozoSort(matrix, false));
	ArrayOutput(BozoSort(arr[0], arr[1], arr[2]));
	ArrayOutput(BozoSort(arr[0], arr[1], arr[2], false));
}