#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int num1, num2;
    cout << "Введите 2 числа\n";
    cin >> num1 >> num2;
    while (num2 == 0)
    {
        cout << "Второе число не может быть нулём, потому что на нуль нельзя делить\n";
        cout << "Введите его ещё раз\n";
        cin >> num2;
    }
    cout << "Сумма чисел = " << num1 + num2 << endl;
    cout << "Разность первого и второго числа = " << num1 - num2 << endl;
    cout << "Произведение чисел = " << num1 * num2 << endl;
    cout << "Частное от деления первого числа на второе = " << num1 / num2 << endl << endl;

    double num3, num4;
    cout << "Введите 2 числа\n";
    cin >> num3 >> num4;
    while (num4 == 0)
    {
        cout << "Второе число не может быть нулём, потому что на нуль нельзя делить\n";
        cout << "Введите его ещё раз\n";
        cin >> num4;
    }
    cout << "Сумма чисел = " << num3 + num4 << endl;
    cout << "Разность первого и второго числа = " << num3 - num4 << endl;
    cout << "Произведение чисел = " << num3 * num4 << endl;
    cout << "Частное от деления первого числа на второе = " << num3 / num4 << endl << endl;

    int num5;
    double num6;
    cout << "Введите 2 числа\n";
    cin >> num5 >> num6;
    while (num6 == 0)
    {
        cout << "Второе число не может быть нулём, потому что на нуль нельзя делить\n";
        cout << "Введите его ещё раз\n";
        cin >> num6;
    }
    cout << "Сумма чисел = " << num5 + num6 << endl;
    cout << "Разность первого и второго числа = " << num5 - num6 << endl;
    cout << "Произведение чисел = " << num5 * num6 << endl;
    cout << "Частное от деления первого числа на второе = " << num5 / num6 << endl << endl;

    double num7;
    int num8;
    cout << "Введите 2 числа\n";
    cin >> num7 >> num8;
    while (num8 == 0)
    {
        cout << "Второе число не может быть нулём, потому что на нуль нельзя делить\n";
        cout << "Введите его ещё раз\n";
        cin >> num8;
    }
    cout << "Сумма чисел = " << num7 + num8 << endl;
    cout << "Разность первого и второго числа = " << num7 - num8 << endl;
    cout << "Произведение чисел = " << num7 * num8 << endl;
    cout << "Частное от деления первого числа на второе = " << num7 / num8 << endl << endl;
}