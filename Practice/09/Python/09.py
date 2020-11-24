h1,m1 = map(int,input().split(':'))
h2,m2 = map(int,input().split(':'))
if (0<=h1<=23 and 0<=m1<=59 and 0<=h2<=23 and 0<=m2<=59):
	h1 = h1 * 60
	person1 = h1 + m1
	h2 = h2 * 60
	person2 = h2 + m2
	if (person2 - person1 <= 15 and person2 - person1 >= 0):
		if (person2 - person1 >= -15 and person2 - person1 <= 0):
			print('Встреча состоится')
		print('Встреча состоится')
	else:
		print('Встреча не состоится')
else:
	print('Неверные данные')