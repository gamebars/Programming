#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int chislo, result, c;
    cout << "Введите число: ";
    cin >> chislo;
    result = 1;
    c = 1;
    while (c <= chislo)
    {
        result = result * c;
        c++;
    }
    cout << "Ответ: " << result;
    return 0;
}
