



#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int a;
    cout << "Выберите способ нахождения площади тругольника: (1-по длине сторон), (2-по координатам вершин) ";
    cin >> a;

    if (a == 1)
    {
        double a, b, c, p, S;
        cout << "Введите стороны треугольника: ";
        cin >> a >> b >> c;
        p = (a + b + c) / 2;
        S = sqrt(p * (p - a) * (p - b) * (p - c));
        cout << "Площадь треугольника: " << S;
    }

    else if (a == 2)
    {

        double x1, x2, x3, y1, y2, y3, S, p, l1, l2, l3;
        cout << "Введите координаты первой вершины труегольника (x1, y1): ";
        cin >> x1 >> y1;
        cout << "Введите координаты первой вершины труегольника (x2, y2): ";
        cin >> x2 >> y2;
        cout << "Введите координаты первой вершины труегольника (x3, y3): ";
        cin >> x3 >> y3;
        l1 = sqrt(x2 * x2 - 2 * x2 * x1 + x1 * x1 + y2 * y2 - 2 * y2 * y1 + y1 * y1);
        l2 = sqrt(x3 * x3 - 2 * x3 * x1 + x1 * x1 + y3 * y3 - 2 * y3 * y1 + y1 * y1);
        l3 = sqrt(x3 * x3 - 2 * x3 * x2 + x2 * x2 + y3 * y3 - 2 * y3 * y2 + y2 * y2);

        p = (l1 + l2 + l3) / 2;
        S = sqrt(p * (p - l1) * (p - l2) * (p - l3));
        cout << "S = " << S;
    }
    else
        cout << "Ошибочный ввод!";
    return 0;

}