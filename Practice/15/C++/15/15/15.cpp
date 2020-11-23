#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int guess, i, repeat;
	cout << "Введите число: ";
	cin >> guess;
	i = 0;
	srand(0);

	int secret = rand() % 100;  // сгенерировать секретное число
while(i<=15)
	{
	if (guess < secret)
	{
		cout << "Загаданное число больше!"<<endl;
		cin >> guess;
		}
	else if (guess > secret)
	{
		cout << "Загаданное число меньше!"<<endl;
		cin >> guess;
	}
		else if (guess == secret)
		{
		cout << "Поздравляю! Вы угадали";
		return 0;
		}
		i++;
	}
cout << "Вы проиграли. Было загадано: " << secret;
cout << "Хотите начать сначала? (1 - ДА )";
cin >> repeat;


}