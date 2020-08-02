#include"Mult.h"
/**
* @authors		Onur AKKEPENEK	(ALGORITHMS AND COMPLEXITY (A))		&&	 Yasemin GERBOÐA(ALGORITHMS AND COMPLEXITY (A))
* @date			8 April 2020
* @brief		This code was written to calculate the product of two long integers using the divide-and-conquer algorithm.
*/
int main()
{
	int numberOfDigit;
	string number1, number2, result, fileName;

	cout << "Enter number of digits: ";
	cin >> numberOfDigit;

	cout << "Enter the first file name: ";
	cin >> fileName;
	number1 = ReadFile(fileName, numberOfDigit);

	cout << "Enter the second file name: ";
	cin >> fileName;
	number2 = ReadFile(fileName, numberOfDigit);

	Multiplication(number1, number2, result);
	SaveFile("result.txt", result);
	system("pause");
}