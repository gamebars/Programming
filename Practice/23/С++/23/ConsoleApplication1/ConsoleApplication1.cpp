#include <iostream>
#include <iomanip>
#include "fact.h"
#include "Taylor.h"
#include "perebor.h"
#define PI 3.141592

void main()
{
	setlocale(LC_ALL, "Russian");

	std::cout << "n   n!" << std::endl;

	for (unsigned int n = 1; n <= 10; n++)
	{
		std::cout << n << "    " << factorial(n) << std::endl;
	}

	std::cout << std::endl << "x    sin(x)" << std::endl;

	for (double x = 0; x <= PI / 4; x += PI / 180)
	{
		std::cout << x << "    " << std::setprecision(4) << taylor(x, 5) << std::endl;
	}

	std::cout << std::endl << "k    C(k, 10)" << std::endl;

	for (unsigned int k = 1; k <= 10; k++)
	{
		std::cout << k << "    " << combinations(k, 10) << std::endl;
	}
}
