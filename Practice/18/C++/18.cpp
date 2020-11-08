#include <iostream>
#include <vector>
using namespace std;

int main()
{

	string words = "halloklempnerdasistfantastischfluggegecheimen";
	vector<char> deutch(words.begin(), words.end());






	// Ñ×¨Ò×ÈÊ ÏÎÂÒÎÐÎÂ ÁÓÊÂ!

	string slovo;  cin >> slovo;
	vector<char> letters(slovo.begin(), slovo.end());
	vector<double> counter_bukv(letters.size(), 0);
	for (double i = 0; i < letters.size(); ++i)
	{
		for (double n = 0; n < 45; ++n)
		{
			if (letters[i] == deutch[n])
				++counter_bukv[i];
		}
	}
	 //for (double i = 0; i < counter_bukv.size(); ++i)
	 //	cout << counter_bukv[i];


	double probability = counter_bukv[0]/deutch.size();


	for (double i = 1; i < counter_bukv.size(); ++i)
		probability = probability * (counter_bukv[i] / deutch.size());

	cout << probability;




	return 0;






}
