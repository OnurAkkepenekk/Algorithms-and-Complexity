#pragma once
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<string>
#include<fstream>
using namespace std;
/*
*	@brief			: This function is used to read numbers from the file.
*	@param			: Gets the number of digits to be read and the file name to be read.
*	@return			: Function returns a string.
*/
string ReadFile(string FileName, int N)
{
	char digit;
	string number = "";
	ifstream file;
	file.open(FileName, ios::in);
	if (file.is_open()) {
		for (int i = 0; i < N; i++) {
			file >> digit;
			number.insert(i, to_string(digit - '0'));
		}
		file.close();
		reverse(number.begin(), number.end());
		return number;
	}
	else {
		cout << "The file could not open" << endl;
		return "";
	}
}
/*
*	@brief			: This function is used to save numbers to the file.
*	@param			: It takes 2 strings, path of file and result.
*/
void SaveFile(string FileName, string result)
{
	ofstream file;
	file.open(FileName, ios::out);
	if (file.is_open()) {
		reverse(result.begin(), result.end());
		file << result;
		file.close();
	}
	else {
		cout << FileName << " couldn't open!" << endl;
	}
}
/*
*	@brief			: This function calculates string length.
*	@param			: It takes 2 strings,Number1 and Number2.
*	@return			: Function returns a int.
*/
int lengthMax(string Number1, string Number2)
{
	int length = 0;
	if (Number1.size() > Number2.size())
	{
		length = Number1.size();
	}
	else
	{
		length = Number2.size();
	}
	return length;
}
/*
*	@brief			: This function synchronizes the digit numbers of the numbers.
*	@param			: It takes 2 strings,Number1 and Number2.
*/
void Eq_digit(string& Number1, string& Number2, int len)
{
	while (Number1.size() < len)
		Number1.insert(0, "0");

	while (Number2.size() < len)
		Number2.insert(0, "0");
}
/*
*	@brief			: This function sums.
*	@param			: It takes 2 strings,Number1 and Number2.
*	@return			: Function returns a string.
*/
string addition(string Number1, string Number2)
{
	int sum = 0;
	int carry = 0;
	int len = lengthMax(Number1, Number2);
	string result;
	Eq_digit(Number1, Number2, len);
	for (int i = len - 1; i >= 0; i--)
	{
		sum = Number1[i] - '0' + Number2[i] - '0' + carry;
		carry = sum / 10;
		sum = sum % 10;
		result.insert(0, to_string(sum));
	}
	if (carry == 1)
	{
		result.insert(0, to_string(carry));
	}
	return result.erase(0, min(result.find_first_not_of('0'), result.size() - 1));
}
/*
*	@brief			: This function subtract.
*	@param			: It takes 2 strings,Number1 and Number2.
*	@return			: Function returns a string.
*/
string subtract(string Number1, string Number2)
{
	int len = lengthMax(Number1, Number2);
	int diff;
	int Neighbor = 0;
	string result;
	Eq_digit(Number1, Number2, len);
	for (int i = len - 1; i >= 0; i--)
	{
		diff = (Number1[i] - '0') - (Number2[i] - '0');
		if (diff >= 0)
		{
			result.insert(0, to_string(diff));
		}
		else
		{
			Neighbor = i - 1;
			while (Neighbor >= 0)
			{
				Number1[Neighbor] = ((Number1[Neighbor] - '0') - 1) % 10 + '0';
				if (Number1[Neighbor] != 9)
				{
					break;
				}
				else
				{
					Neighbor--;
				}
			}
			result.insert(0, to_string(diff + 10));
		}
	}
	return result.erase(0, min(result.find_first_not_of("0"), result.size() - 1));
}
/*
*	@brief			: This function calculates the result of multiplication of 2 numbers.
*	@param			: It takes 3 strings,Number1, Number2 and result.
*/
void Multiplication(string Number1, string Number2, string& result)
{
	string C, D, E, P, F;
	int len = max(Number1.length(), Number2.length());
	Eq_digit(Number1, Number2, len);
	if (len == 1) {
		result = to_string((Number1[0] - '0') * (Number2[0] - '0'));
		return;
	}
	string w_most_significant_digits = Number1.substr(0, len / 2);
	string x_least_significant_digits = Number1.substr(len / 2, len - (len / 2));
	string y_most_significant_digits = Number2.substr(0, len / 2);
	string z_least_significant_digits = Number2.substr(len / 2, len - (len / 2));
	Multiplication(w_most_significant_digits, y_most_significant_digits, C);
	Multiplication(x_least_significant_digits, z_least_significant_digits, D);
	Multiplication(addition(w_most_significant_digits, x_least_significant_digits), addition(y_most_significant_digits, z_least_significant_digits), E);
	E = subtract(E, addition(C, D));
	for (int i = 0; i < 2 * (len - (len / 2)); i++) {
		C.append("0");
	}
	for (int i = 0; i < len - (len / 2); i++) {
		E.append("0");
	}
	result = addition(C, addition(D, E));
}