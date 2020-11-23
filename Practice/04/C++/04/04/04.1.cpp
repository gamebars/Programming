#include <iostream>
#include <locale>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int i;
	cout << "Введите способ замены переменных местами (1-без доп. переменной, 2-при помощи доп. переменной: )";
	cin >> i;
	if (i == 1) {

		double a, b;
		cout << "Введите первое число ";
		cin >> a;
		cout << "Введите второе число ";
		cin >> b;
		a = b - a;
		b = b - a;
		a = b + a;

		cout << "\n Первое число " << a;
		cout << "\n Второе число " << b;
	}
	else {
		double a, b, c;
		cout << "Введите первое число ";
		cin >> a;
		cout << "Введите второе число ";
		cin >> b;
		c = a;
		a = b;
		b = c;

		cout << "\n Первое число " << a;
		cout << "\n Второе число " << b;

	}
	return 0;
}



	

