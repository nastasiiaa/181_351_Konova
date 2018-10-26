// lab7.cpp : Динамическое выделение памяти


#include "pch.h"
#include <iostream>

using namespace std;

	/*
	int arr[11][12] = {0};  - в таком объявлении только константные размерности

	стековая память ограничена, при неправильном использовании стек переполняется (stack overflow)
	размерности массивов, выделяемых в стековой памяти, фиксированы и задаются константами
	int b[1000][1000] = {0} ; - переполнение стека


	для использования свободной памяти ОС (heap - куча_)
	объявляются динамические переменные по синтаксису
	указатель_на_тип_ имя_переменной = new тип;
	или тип *имя_переменной = new тип;
	работа с динамической памятью происходит через указатели

	Преимущества:
	1. доступно гораздо больше памяи, нежели в стеке
	2. размеры массивов и структур данных можно определять и менять во время работы приложения

	Особенность:
	Если приложение предназначено для длительной работы,
	во избежание переполнения памяти созданные переменные и блоки памяти после испльзования
	должны быть освобождены с помощью оператора delete:
	delete имя_переменной;


	
	int * ptr_int = new int; // в неопределенной памяти создается блок
	// размером с int и указатель на него возвращается в переменную ptr_int

	// вызов утечки памяти
	for (int i = 0; i < 1000; i++)
	{
		long long * b = new long long;
		/*
		1. каждый заход в стеке создается новый указатель
		2. выделяется блок new long long; в куче (нераспределенной памяти), приписанной к этой программе
		3. стековая переменная b исчезает
		4. а блок по-прежнему остается там же
		5. при следующем заходе выделяется новый блок// совершать нужные действия  с переменной
		
		delete b; // удалить блок памяти пока не потерян указатель на нее
	}

	// пара операторов new/delere -  это одно из нововведений с++ относительно С

	 в динамической памяти могут выделяться только одномерные массивы
	тип * имя_указателя = new типь [длина];
	удаляются одномерные массивы с помощью записи
	delete [] имя_указателя
	*/

	/*  int * matr = new int[11 * 12];
	for (int row = 0; row < 12; row++)
	{
		for (int col = 0; col < 11; col++)
		{
			matr[row * 11 + col] = row * 11 + col;
		}
	}
	for (int row = 0; row < 12; row++)
	{
		for (int col = 0; col < 11; col++)
		{
			std::cout << matr[row * 11 + col] << "\t";
		}
	}
}
*/
	
	class matrix
	{
	private:
		int * matr = new int[rows*columns];
		int rows, columns;
		int *res = new int[rows*columns];
	public:
		matrix();
		~matrix();

		bool summMatrix(matrix matr2);
		bool multMatrix(matrix matr2);

		int getElem(int row, int col);
		int getRows() {
			return rows;
		}
		int getColumns() {
			return columns;
		}

		bool input();
		void transp();

		void printM()
		{
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < columns; j++)
				{
					cout << matr[i*columns + j] << "\t";
				}
				cout << endl;
			}
		};
	};


	int main()
	{
		matrix matrA, matrB;
		matrA.input();
		matrB.input();
		matrA.printM();
		matrA.transp();
		matrA.summMatrix(matrB);
		matrA.multMatrix(matrB);
	}

	matrix::matrix() {}
	matrix::~matrix() {}

	bool matrix::summMatrix(matrix matr2)
	{
		if (rows == matr2.getRows() && columns == matr2.getColumns())
		{
			for (int i = 0 ; i < rows; i++)
			{
				for (int j = 0; j < columns; j++)
				{
					matr[i*columns + j] += matr2.getElem(i, j);
				}
			}
			printM();
			return true;
		}
		else {
			return false;
		}
	}

	void matrix::transp()
	{
		int t;
		for (int i = 0; i < columns; i++)
		{
			for (int j = 0; j < rows; j++)
			{
				cout << matr[j * columns + i] << " ";
			}
			cout << endl;
		}
	}

	bool matrix::multMatrix(matrix matr2)
	{
		if (columns == matr2.getRows())
		{
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < matr2.getColumns(); j++)
				{
					int sum = 0;
					for (int k = 0; k < columns; k++) {
						sum += matr[i*columns + k] * matr2.getElem(k, j);
					}
					res[i*columns + j] = sum;
				}
			}
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < matr2.getColumns(); j++)
				{
					cout << res[i*columns + j];
				}
				cout << endl;
			}
			return true;
		}
		else
		{
			cout << "col1 != row2";
			return false;
		}
	}

	int matrix::getElem(int row, int col)
	{
		if (row < rows && col < columns && row > -1 && col > -1)
		{
			return matr[row*columns + col];
		}
		else
		{
			cout << "error";
			return -1;
		}
	}

	bool matrix::input()
	{
		cout << "rows=";
		cin >> rows;
		cout << "columns=";
		cin >> columns;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				cin >> matr[i*columns + j];
			}
			cout << endl;
		}
		return true;
	}




