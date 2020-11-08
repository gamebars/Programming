words = ['hallo', 'klempner', 'das', 'ist', 'fantastisch', 'fluggegecheimen']
dlina_slov = len(''.join(words))
slovo = input('Введите стоп слово: ')
#Создание словаря 
spisok = {}
for word in words:
   for letter in word:
      if letter in spisok:
         spisok[letter] += 1
      else:
         spisok[letter] = 1
result = 1       
for letter in slovo:
	result = result * (spisok[letter]/dlina_slov)
print(result)

