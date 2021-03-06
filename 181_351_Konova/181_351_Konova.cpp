// ЛР 1 СТРУКТУРА ПРОГРАММЫ, ТИПЫ ДАННЫХ, ОСНОВНЫЕ ОПЕРАТОРЫ

/*ДЗ:
	1) выписать и распечатать в коде с помощью count всю таблицу escape последовательностей
	2) таблица кодировки ASCII
	3) дописать остальные типы данных С++
	4) для числовых данных выписать диапазоны, которые в них хранятся
	 bool (0..1) (false..true)
	 char:
	 signed char -128..0..127
	 unsigned char (0..255)
	 wchar_t:
	 char16_t (0..2^16-10)
	 char32_t (0..4294967295)
	 short (-2^8)..0..(-2^8-1)
	 signed short int (-2^15..0..-2^15-1)
	 unsigned short int (0..2^16)
	 signed long int (-2^31..0..2^31-1)
	 unsigned long int (0..4294967295)
	 long long (-9223372036milliard..0..9223372036milliard)
	 unsigned long long (0..18446744073709551615)
	 float (3.4e-38..0..3.4e38)
	 double (1.7e-308..0..1.7e308)
	 long double (3.4e-4932..3.4e+4932)

*/



//#include "stdafx.h"
#include<iostream>
#include<string> 
#include<vector>
#include<algorithm>
#include<cmath> 

/*тоже

// include - подключение сторонних библиотек */
#include "pch.h"
#include <iostream>

double value_of_pi = 3.14;

int main()// т.н. "точка входа"
{
	//вывод на консоль
	//STD - область видимости, т.н. "пространство имён"
	// в <iostream> есть часть библиотеки STD
	/*
	  ESCAPE последовательности: \n- знак переноса строки.
	  Существует также \t-табуляция
	  \\ - слеш
	  */

	std::cout << "\"Hello, World!\"\n";
	std::cout << "Hello, World!\n";
	std::cout << "\"Hello, World!\a	zvonok predypreshdenie\"\n";
	std::cout << "\"Hello, World!\b	Backspace\"\n";
	std::cout << "\"Hello, World!\f	perevod stranicy\"\n";
	std::cout << "\"Hello, World!\n	novaya stroka\"\n";
	std::cout << "\"Hello, World!\r	vozvrat caretki\"\n";
	std::cout << "\"Hello, World!\t	gorizontalnaya tabylyaciya\"\n";
	std::cout << "\"Hello, World!\v	verticalnya tabylyaciya\"\n";
	std::cout << "\"Hello, World!\'	odinochnaya kavychka\"\n";
	std::cout << "\"Hello, World!\"	dvoinaya kavychka\"\n";
	std::cout << "\"Hello, World!\\	obratnaya kosaya cherta\"\n";
	std::cout << "\"Hello, World!\?	literal voprositelnogo znaka\"\n";

	// обьявление пременных / тип данных
	int a;
	int nuber_of_desks;
	double speed;

	//типы данных
	//char(x8),short(x16),int(x32),long int(x32),long long(x64) - целые цисла со знаком
	//float(x32),double(x64)-числа с плавающей точкой
	//char- так же символы
	//boll,long boll
}
// СИНТАКСИС C++
// блок кода в скобках {}
// разделение строк 
// 
