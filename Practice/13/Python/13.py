#Простое или нет?
import math

n = int(input())

if n < 2:
    print("Число должно быть больше либо равно 2")
    quit()
elif n == 2:
    print("Это простое число")
    quit()

i = 2
limit = int(math.sqrt(n))

while i <= limit:
    if n % i == 0:
        print("Это составное число")
        quit()
    i += 1

print("Это простое число")