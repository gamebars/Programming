#include <iostream>
using namespace std;
int main()
{
	int chislo, stepen, counter, begining;
	cin >> chislo >> stepen;
	counter = 1;
	begining = chislo;
		while (counter < stepen)
		{
			chislo = chislo * begining;
			counter = counter + 1;
		}
	cout << chislo;
	
	return 0;
}