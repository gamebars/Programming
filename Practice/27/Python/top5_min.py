n = int(input('Введите количество сигалов\n'))
massiv = list(map(int, input('Введите последовательность сигналов\n').split(' ')))
numbers = []
size = int(0)
for i in range(n):
    numbers.append(massiv[i])
    size += 1
    #Сортировка в порядке убывания
    numbers.sort(reverse = True)
    if (size <= 5):
        for j in range(size):
            print(numbers[j], end=" ")
        print()
    else:
        for j in range(size-5, size):
            print(numbers[j], end=" ")
        print()