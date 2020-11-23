#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    double a, b;
    char symbol;
    cout << "Введите выражение через пробел: ";
    cin >> a >> symbol >> b;
    if (symbol == '+')
        cout << "Результат выражения: " << a + b;
    else if (symbol == '-')
        cout << "Результат выражения: " << a - b;
    else if (symbol == '*')
        cout << "Результат выражения: " << a * b;
    else if (symbol == '/')
        cout <<"Результат выражения: " <<a / b;
    else
        cout << "Вы ввели неверное значение! ";
        return 0;

}