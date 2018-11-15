// lab7.cpp : Динамическое выделение памяти


#include "pch.h"
#include <iostream>


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
	
class matrix {

private:

	int rows;
	int columns;
	double **matr;

public:

	matrix();
	~matrix();

	bool input();
	void print();
	bool summMatrix(matrix matr2);
	bool multMatrix(matrix matr2);
	bool transp();

	int getRows();
	int getColumns();
	double getElem(int row, int col);
};

int main()
{
	setlocale(LC_ALL, "Russian");
	return 0;
}

matrix::matrix()
{

}

matrix::~matrix()
{

}

bool matrix::input()
{
	std::cout << "Кол-во строк: ";
	std::cin >> rows;
	std::cout << '\n' << "Кол-во столбцов: ";
	std::cin >> columns;

	matr = new double*[rows];

	for (int i = 0; i < rows; i++) {
		matr[i] = new double[columns];
	}

	std::cout << '\n' << "Матрица: ";

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			std::cin >> matr[i][j];
		}
	}
	return true;
}

void matrix::print()
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			std::cout << matr[i][j] << '\t';
		}
		std::cout << '\n';
	}
}

bool matrix::summMatrix(matrix matr2)
{
	double **result = new double*[rows];
	for (int i = 0; i < rows; i++) {
		result[i] = new double[columns];
	}

	std::cout << '\n' << "Сумма: " << '\n';

	if ((rows == matr2.getRows()) && (columns == matr2.getColumns())) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				result[i][j] = matr[i][j] + matr2.getElem(i, j);
				std::cout << result[i][j] << '\t';
			}
			std::cout << '\n';
		}
		return true;
	}
	else return false;
}

bool matrix::multMatrix(matrix matr2)
{
	double **matr3 = new double*[rows];
	for (int i = 0; i < rows; i++) {
		matr3[i] = new double[columns];
	}

	if (columns == matr2.getRows()) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < rows; j++) {
				double sum = 0;
				for (int k = 0; k < matr2.getColumns(); k++) {
					sum += matr[i][k] * matr2.getElem(k, j);
				}
				matr3[i][j] = sum;
				std::cout << matr3[i][j] << '\t';
			}
			std::cout << '\n';
		}
		return true;
	}
	else return false;
}

bool matrix::transp()
{
	int ch;
	if (rows != columns) {
		ch = rows;
		rows = columns;
		columns = ch;
	}

	double temp = 0;
	for (int i = 0; i < rows; i++) {

		for (int j = i; j < columns; j++) {

			temp = matr[i][j];
			matr[i][j] = matr[j][i];
			matr[j][i] = temp;
		}
	}
	return true;
}

int matrix::getRows()
{
	return rows;
}

int matrix::getColumns()
{
	return columns;
}

double matrix::getElem(int row, int col)
{
	if (row<rows && col<columns && row>-1 && col>-1)
		return matr[row][col];

	else
		return -11111111111;
	std::cout << "Error!\n";
	return -1;

}
