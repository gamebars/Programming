#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout << "Введите три числа" << endl;
    double a, b, c;
	cin >> a >> b >> c;

	if (a == 0) {
		if (b == 0) {
		    cout << "Нет корней" << endl;
		} else {
			cout << "x = " << -c / b << endl;
		}
	} else {
		double d = b * b - 4 * a * c;
		if (d < 0)
			cout <<"действительных корней нет." << endl;
		else if (d == 0) {
			cout << "x = " << -b / (2 * a) <<endl;
		} else {
			double koren_disc{sqrt(d)};
			double x1 = (-b + koren_disc) / (2 * a);
			double x2 = (-b - koren_disc) / (2 * a);

		    cout << "x1 = " << x1 <<endl;
			cout << "x2 = " << x2 <<endl;
		}
	}
}