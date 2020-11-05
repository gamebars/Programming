#include <iostream>
#include <locale>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
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