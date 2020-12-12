#include <iostream>
#include <vector>
//Создаю прототип функции
std::vector <int> sort(std::vector<int>, int);

int main() {
	using namespace std;
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите кол-во сигалов: ";
	cin >> n;
	vector<int> array(n);
	cout << "Введите последовательность сигналов:" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
	}

	vector<int> arr;
	int size = 0;
	for (int i = 0; i < n; i++)
	{
		arr.push_back(array[i]);
		size++;
		arr = sort(arr, size);
		if (size <= 5)
		{
			for (int j = 0; j < size; j++)
			{
				cout << arr[j] << " ";
			}
			cout << endl;
		}
		else
		{
			for (int j = size - 5; j < size; j++)
			{
				cout << arr[j] << " ";
			}
			cout << endl;
		}
	}
}
std::vector <int> sort(std::vector<int> arr, int n) {
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}
	return arr;
}