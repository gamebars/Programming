#include <iostream>
#include <string>
#include <math.h>

void func0(std::string& str)
{
	for (int i = 0; i < str.length() / 2; i++)
	{
		char tmp = str[i];
		str[i] = str[str.length() - 1 - i];
		str[str.length() - 1 - i] = tmp;
	}
}

std::string func1(int a, std::string str)
{
	int p = str.length();
	std::string res("");
	int counter = 0;

	while (counter != a)
	{
		res += std::to_string(a % p);
		a /= p;
	}

	func0(res);

	return res;
}

int func2(char a)
{
	for (int i = char('0'), j = 0; i < std::numeric_limits<char>::max(); i++, j++)
		if (a == char(i))
			return j;
}

int main()
{
	int n;
	std::cin >> n;

	std::string k;
	std::cin >> k;

	std::string str("");

	for (int i = 0; i < n; i++)
		str += '0';

	std::string tmp;
	for (int a = 0; a < pow(k.length(), n); a++)
	{
		tmp = func1(a, k);
		for (int j = 0; j < tmp.length(); j++)
			str[str.length() - 1 - j] = tmp[tmp.length() - 1 - j];

		for (int j = 0; j < n; j++)
		{
			str[j] = k[func2(str[j])];
		}
		std::cout << str << ' ';

		str = "";
		for (int i = 0; i < n; i++)
			str += '0';
	}

	std::cout << '\n';
	return 0;
}