// lab3shifrcaesar.cpp : Шифр Цезаря
//

#include "pch.h"
#include <iostream>

using namespace std;

void cezar (char slova[], int sal)
{
	const int bykvSal = 26;
	char bykv[bykvSal] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
							'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
								'u', 'v', 'w', 'x', 'y', 'z' };
		for (int i = 0; i < sal; i++)
			if (slova[i] != ' ')
				for (int j = 0; j < bykvSal; j++)
					if (slova[i] == bykv[j])
					{
						slova[i] = bykv[j + 30 % (bykvSal - 1)];
						break;
					}

}

void printArray(char array[], int sal)
{
	for (int i = 0; i < sal; i++)
		cout << array[i];
}

int main()
{
	const int bykvSal = 10;
	char bykv[bykvSal] = { 'b','e', ' ', 'p', 'e', 'r', 'f', 'e', 'c', 't' };

	cezar(bykv, bykvSal);
	printArray(bykv, bykvSal);
}