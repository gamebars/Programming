import math

print("Введите три числа")

a = int(input())
b = int(input())
c = int(input())

if a == 0:
    if b == 0:
        print("Корней нет.")
    else:
        print("x =", -c / b)
else:
    disc = b**2 - 4*a*c
    if d < 0:
        print("Ошибка. Дискриминант = 0")
    elif d == 0:
        print("x =", -b/(2*a))
    else:
        d_sqrt = math.sqrt(disc)
        x1 = (-b + d_sqrt) / (2 * a)
        x2 = (-b - d_sqrt) / (2 * a)
        print("x1 =", x1,"\nx2 =", x1)