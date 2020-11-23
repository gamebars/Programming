#include <iostream>
using namespace std;
int main()
{
	setlocale (LC_ALL, "Russian");
	int n;
	cin >> n;
	
	string array[1000];
	string slovo;
	for (int i = 0; i <= n; i++)
	{
		cin >> slovo;
		if (slovo[0] == 'a' && slovo[8] == '1' && slovo[7] == '6' &&
			slovo[6] == '6' && slovo[5] == '5' && slovo[4] == '5')
		{
			array[i] = slovo;
			cout << array[i]<<endl;
		}

	}
	cout << -1;



}


/*ЗАПОЛНЕНИЕ ВЕКТОРА ЭЛЕМЕНТАМИ STRING
string s("string");
vector<char> v(s.begin(), s.end());*/