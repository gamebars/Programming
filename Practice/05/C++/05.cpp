#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	double x,t,v,g,L;
	g = 9.8;
	cout << "Введите начальное положение ";
	cin >> x;
	cout << "Введите время движения " ;
	cin >> t;
	cout << "Введите начальную скорость ";
	cin >> v;
    S= x + v * t + g * t * t / 2;


	cout << "\n Расстояние = " << S ;


}