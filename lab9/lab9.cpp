// lab9.cpp : Перегрузка
/*
Перегрузка  - объявление нескольких функций, методов или операторов, которые тоже являются 
функциями, с одинаковыми именами, но разным набором аргументов

различие функций по одному входному параметру не является перегрузкой, так как на месте вызова 
компилятору недостаточно информации, чтобы решить, какую функцию вызвать

для компилятора критерием является сигнатура функции - имя + последовательность аргументов + их типы

методы класса перегружаются точно также, как и обычные функции

унарные и бинарные операторы перегружаются по-разному
унарные - в самом классе (получается новый метод класса)
бинарные - как отдельную функцию

бинарные операторы прописываются вне класса, так как результат не обязательно записывается
в один из операндов, а может записываться в некий третий объект

в унарных операторах результат записыватся в тот же самый объект, для которого вызван опреатор, 
поэтому унарный стоит отнести к методам класса


*/

#include "pch.h"
#include <iostream>
#include <sstream>


class matrix
{
private:

	int rows;
	int columns;
	double *matr;

public:

	matrix();
	~matrix();

	friend matrix operator+ (const matrix & matr1, matrix & matr2);
	friend matrix operator- (const matrix & matr1, matrix & matr2);
	friend matrix operator* (const matrix & matr1, matrix & matr2);
	friend std::ostream & operator << (std::ostream & os, matrix & matr2);

	bool input();
	bool print();

	int getRows()
	{
		return rows;
	}

	int getColumns()
	{
		return columns;
	}
	double getElem(int row, int col);
};

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
	std::cout << "Кол-во столбцов: ";
	std::cin >> columns;
	std::cout << "Матрица: ";

	matr = new double[rows * columns];

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			std::cin >> matr[i * columns + j];
		}
	}
	return true;
}

bool matrix::print()
{
	std::cout << std::endl;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			std::cout << matr[i * columns + j] << ' ';
		}
		std::cout << std::endl;
	}
	return true;
}

int main()
{

	setlocale(LC_ALL, "Russian");
	matrix a, b;
	a.input(); a.print();
	b.input(); b.print();
	(a + b).print();
	(a - b).print();
	(a * b).print();

	return 0;
}

matrix operator+(const matrix & matr1, matrix & matr2)
{
	if ((matr1.rows == matr2.rows) && (matr1.columns == matr2.columns)) {

		matrix result;

		result.rows = matr1.rows;
		result.columns = matr1.columns;
		result.matr = new double[result.rows * result.columns];

		for (int i = 0; i < matr1.rows; i++) {

			for (int j = 0; j < matr1.columns; j++) {

				result.matr[i * result.columns + j] = matr1.matr[i * result.columns + j] + matr2.matr[i * result.columns + j];
			}
		}
		return result;
	}
	else return matr1;
}

matrix operator-(const matrix & matr1, matrix & matr2)
{
	if ((matr1.rows == matr2.rows) && (matr1.columns == matr2.columns)) {

		matrix result;

		result.rows = matr1.rows;
		result.columns = matr1.columns;
		result.matr = new double[result.rows * result.columns];

		for (int i = 0; i < matr1.rows; i++) {

			for (int j = 0; j < matr1.columns; j++) {

				result.matr[i * result.columns + j] = matr1.matr[i * result.columns + j] - matr2.matr[i * result.columns + j];
			}
		}
		return result;
	}
	else return matr1;
}

matrix operator*(const matrix & matr1, matrix & matr2)
{
	if (matr1.rows == matr2.columns)
	{
		matrix result;

		result.columns = matr2.columns;
		result.rows = matr1.rows;
		result.matr = new double[result.rows * result.columns];

		for (int i = 0; i < matr1.rows; i++)
		{
			for (int j = 0; j < matr1.rows; j++)
			{
				double mid = 0;

				for (int k = 0; k < matr2.columns; k++)
				{
					mid += matr1.matr[i * matr1.rows + k] * matr2.matr[k * matr1.rows + j];
				}
				result.matr[i * matr1.rows + j] = mid;
			}
		}
		return result;
	}
	else return matr1;
}


std::ostream & operator<<(std::ostream & os, matrix & matr2)
{
	for (int i = 0; i < matr2.rows; i++)	
		for (int j = 0; j < matr2.columns; j++)
		{
			os << matr2.matr[i * matr2.columns + j] << ' ';
		}
		os << std::endl;
	return os;
}

double matrix::getElem(int row, int col)
{
	if (row <= rows && col <= columns && row > -1 && col > -1)
		return matr[row * columns + col];
	else
		return -11111111111;
	std::cout << "Error!\n";
	return -1;
}