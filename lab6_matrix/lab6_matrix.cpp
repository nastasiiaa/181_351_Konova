// lab6_matrix.cpp 
//

#include "pch.h"
#include <iostream>

class matrix
{
private:

	int matr[10][10];
	int rows;
	int columns;

public:
	matrix();
	~matrix();

	bool input();
	bool print();
	bool summMatrix(matrix matr2);
	bool multMatrix(matrix matr2);
	bool transp();

	int getRows()
	{
		return rows;
	}
	int getColumns()
	{
		return columns;
	}
	double getElem(int row, int col)
	{
		if (row<rows && col<columns && row>-1 && col>-1)
		{
			return matr[row][col];
		}
		std::cout << "Connot get element. Index Error!\n";
		return -1;
	}
};

matrix::matrix()
{
}

using namespace std;

bool matrix::input()
{
	cin >> rows;
	if (rows < 1 && rows > 10) 
	{ 
		return false; 
	}
	cin >> columns;
	if (columns < 1 && columns > 10) 
	{
		return false; 
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cin >> matr[i][j];
		}
	
	}
	return true;
}
		 
		//	if ()
		//считать количество строк
		//проверить, что введено число в пределах [1;10]
		//иначе, вернуть ошибку
		//считать количество стлобцов
		//проверить, что введено число в пределах [1;10]
		//иначе, вернуть ошибку

		//считать элементы матрицы

	//	return true; cin
	

int main()
{
    
}


