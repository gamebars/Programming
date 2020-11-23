#include <iostream>
using namespace std;

double BMI(double weight, double height)
{

	double BMI = weight / (height * height);
	return BMI;

}
void printBMI(double BMI)
{
	string result;
	if (BMI < 18.5 && BMI > 0)
		result = "Underweight";
	else if (BMI >= 18.5 && BMI < 25)
		result = "Normal";
	else if (BMI >= 25 && BMI < 30)
		result = "Overweight";
	else if (30 <= BMI)
		result = "Obesity";
	else cout << "Error, incorrect index.";
	cout << result << endl;


}
int main()
{
	setlocale(LC_ALL, "Russian");
	double weight, height;
	cout << "Введите свой вес 'в килограммах' и рост в 'сантиметрах': ";
	cin >> weight >> height;
	printBMI(BMI(weight, height*0.01));
}