#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    double h1, h2, m1, m2, dif;
    char symbol;
    cout << "Введите время прихода первого человека (Пример ввода : ";
    cin>>h1>>symbol>>m1;
    cout << "Введите время прихода второго человека: ";
    cin>>h2>>symbol>>m2;


    if (h1 >= 0 && h1 <= 23 && m1 >= 0 && m1 <= 59 && 
        h2 >= 0 && h2 <= 23 && m2 >= 0 && m2 <= 59)
    {
        if (h2 - h1 == 0)
            dif = m2 - m1;
        else if (h2 - h1 < 0)
            cout << "Увы, вы опоздали.";
        else if (h2 - h1 == 1)
            dif = (60 - m1) + m2;
        else
            dif = (h2 - h1) * 60 + (60 - m1) + m2;


        if (dif <= 15)
            cout << "Встреча состоится ";
        else
            cout << "Встреча не состоится ";


    }
    else
        cout << "Введено недопустимое значение времени!";

    return 0;
}