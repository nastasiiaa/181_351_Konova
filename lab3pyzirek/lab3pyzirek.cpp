// lab3pyzirek.cpp : Пузырек

#include "pch.h"
#include <iostream>

using namespace std;


int main()
{
	int *arr; // указатель выделения памяти для массива
	int size;

	cout << "n = ";
	cin >> size;

	if (size <= 0) {
		cerr << "Invalid size" << endl;
		return 1;
	}
	arr = new int[size]; //выделяем память под массив 

						 // заполняем массив
	for (int i = 0; i < size; i++) {
		cout << "arr[[" << i << "] = ";
		cin >> arr[i];
	}
	int temp; // перемаенная для обмена элементов местами

	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; i++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j]; //запись в буферную переменную наибольшего жлемента в паре чисел
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	delete[] arr; // освобождение памяти

	return 0;
}