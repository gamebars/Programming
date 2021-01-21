while True:
    print('Введите через пробел числа s, l1, r1, l2, r2')
    s, l1, r1, l2, r2 = map(int,input('Числа должны удовлетворять условиям l1 <= r1 и l2 <= r2\n').split())
    if l1 <= r1 and l2 <= r2:
        if s < l1 + l2 or s > r1 + r2:
            print(-1)
        else:
            if l1 + r2 - s == 0:
                print(l1, r2)
            elif l1 + r2 - s < 0:
                x = l1 - (l1 + r2 - s)
                print(x, r2)
            elif l1 + r2 - s > 0:
                x = r2 - (l1 + r2 - s)
                print(l1, x)
        break
    else:
        print('Числа не удовлетворяют условиям\n')