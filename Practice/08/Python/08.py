while True:
   print('Если хоттите завершить программу введите 0 ')
    s = input("Введите знак: ")
    if s == '0':
        break
    if s in ('+', '-', '*', '/'):
        x = int(input("x="))
        y = int(input("y="))
        if s == '+':
            print(x+y)
        elif s == '-':
            print(x-y)
        elif s == '*':
            print(x*y)
        elif s == '/':
            if y != 0:
                print(x/y) 
            else:
                print("Деление на ноль!")
    else:
        print("Неверный знак операции!")