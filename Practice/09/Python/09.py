print("Введите значения через 'Enter', каждое с новой строки")

h1, m1 = map(int, input().split(sep=':'))
h2, m2 = map(int, input().split(sep=':'))

chislo1 = 60 * h1 + m1
chislo2 = 60 * h1 + m2

if abs(chislo2 - chislo1) > 15:
    print('Встреча не состоится')
else:
    print('Встреча состоится')