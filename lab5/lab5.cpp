// lab5.cpp : операторы переходов и циклов


#include "pch.h"
#include <iostream>


/* if - оператор условного перехода

		if(лог_усл)
		{
			код, выполняемый если (лог_усл == true)
		}

		if(лог_усл)
		{
			код, выполняемый если (лог_усл == true)
		}

		else
		{ 
			код, выполняемый в противном случае
		}

		Примеры:

		if (a > b) {... ;
		bool c = ... ;
		bool d = ... ; 
		if ( c && d) { ...
*/

using std::cout;
using std::endl;
using std::cin;

int arr[10];

int* input_array() {

	int arr[10] = { 0 };

	for (int iter = 0; iter < 10; iter++) {

		cin >> arr[iter];

	}

	return arr;

}

int func(int *num1, int num2);

int main()

{

	/*input_array();

	for (int iter = 0; iter < 10; iter++) {

		cout << arr[iter];

		getchar();

		return 0;

	}
	*/





	int num1 = 1, num2 = 2, res = 0;

	res = func(&num1, num2);

	cout << res << " " << num1 << " " << num2 << endl;

}



int func(int *num1, int num2)

{

	*num1 += 10;

	return *num1 + num2;

}