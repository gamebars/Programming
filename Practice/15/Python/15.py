import random

while True:
    chislo = random.randrange(0,100)
    schetchik = 0
    schetchik=schetchik+1

    print("Вас приветствует игра 'Угадайка', введите свою догадку: ")

    for i in range(5):
        dogadka = int(input())
        if dogadka > chislo:
            print("Загаданное число меньше")
        elif dogadka < chislo:
            print("Загаданное число больше")
        else:
            print("Вы выиграли!")
            win = True
            break

    if schetchik == 3:
        print("Вы проиграли. Загаданное число:", chislo)

    if not 1 == int(input("Хотите начать сначала? (1 - да)\n")):
        break