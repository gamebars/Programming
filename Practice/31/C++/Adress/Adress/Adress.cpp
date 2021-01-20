#include <iostream>
#include <vector>
#include <fstream>

using std::endl;
using std::vector;
using std::ostream;

#define PART 2

#if PART == 3
ostream& operator<< (ostream& out, const vector<int> vector)
{
	out << vector.size() << "\t| ";
	for (auto& item : vector)
	{
		out << &item << " ";
	}
	out << endl;
	return out;
}
#elif PART == 2
ostream& operator<< (ostream& out, const vector<int>& vector)
{
	out << vector.size() << "\t| ";
	for (auto& item : vector)
	{
		out << &item << " ";
	}
	out << endl;
	return out;
}
#endif

int main()
{
	
	
	vector<int> vector;
	std::ofstream data("data.txt");

	for (int i = 0; i < 64; ++i)
	{
		vector.push_back(rand());
		data << vector;
	}
	for (int i = 0; i < 63; ++i)
	{
		vector.pop_back();
		data << vector;
	}

	data.close();
}
/* Вопрос 1. Адреса элемента вектора всегда отличаются, т.к. с помощью оператора << вектор копируется,
а так как элементы идут последовательно,то адреса следующих элементов увеличиваются на размер того, сколько байт занимает int)
Нет, потому что вектор будет перемещён в новую память.

Вопрос 2. Из-за того, что вектор переместиться в новую память, значение нулевой ячейки вектора не измениться. 

Вопрос 3. Адреса элемента вектора всегда отличаются, т.к. с помощью оператора << вектор копируется,
а так как элементы идут последовательно,то адреса следующих элементов увеличиваются на размер того, сколько байт занимает int)
Нет, потому что вектор будет перемещён в новую память..

Вопрос 4. Изменения присутствуют. В памяти не выделится новое место и первый элемент вектора останется с старым адресом*/