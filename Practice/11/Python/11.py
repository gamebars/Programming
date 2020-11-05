chsilo = int(input("Введите число возводимое в степень: "))
stepen = int(input("Введите степень данного числа: "))
i = 0
result = 1
while (i < stepen):
	result = result*chsilo
	i = i + 1
print("Результат: ",result)
