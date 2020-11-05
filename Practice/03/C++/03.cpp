#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int a;
	int b;
	cout << "Введите первую переменную ";
	cin >> a;
	cout << "Введите вторую переменную ";
	cin >> b;
	cout << "Сумма равна " << a + b;
	cout << "\n Разность равна " << a - b;
	cout << "\n Произведение равно " << a * b;
	cout << "\n Частное равно " << a / b;
	return 0;
}

