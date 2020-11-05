import math
print("""Выберите удобный для вариант
1. Длины стороны треугольника.
2. Координаты треугольника.""")

a = b = c = 0.0
choise = int(input())
if choise == 1:
    print("Введите длины сторон треугольника, каждое с отдельной строки.")
    a = float(input())
    b = float(input())
    c = float(input())
elif choise == 2:
    print("Введите три пары чисел через пробел")
    x1, y1 = map(float, input().split())
    x2, y2 = map(float, input().split())
    x3, y3 = map(float, input().split())
    
    a = math.sqrt((x1 - x2)**2 + (y1 - y2)**2)
    b = math.sqrt((x2 - x3)**2 + (y2 - y3)**2)
    c = math.sqrt((x3 - x1)**2 + (y3 - y1)**2)

p = (a + b + c) / 2
S = math.sqrt(p * (p - a) * (p - b) * (p - c))

print("S =", S)