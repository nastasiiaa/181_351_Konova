// Dll1.cpp : Определяет экспортированные функции для приложения DLL.

#include "stdafx.h"
#include "Dll1.h"


int discrim(int a, int b, int c)
{
	int d;
	d = b * b - 4 * a*c;
	return d; // b * b - 4 * a*c;
}
