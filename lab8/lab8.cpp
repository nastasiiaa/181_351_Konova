// lab8.cpp : строки и файлы
//

#include "pch.h"
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>

using std::cout;
using std::endl;
using std::cin;
using std::fstream;
using std::string;


// strcat (), strlen, strcnp() для работы с с++ строками
 /*строки старого с-типа представляют из себя всего лишь массив символов с нулевым окончанием */


//char cstr1[] = "C-style string1";
//char sim;
//char cstr2[] = { 'c', '-', 's','\0' };
//char cstr3[] = { '\67', '\45', '\115','t', 'y', '\0' };

/* в типе char  на самом деле хранится знаковое целое число. можно скадывать, делить, умножать 
char
чтобы придать символьный смысл данным, хранимым в чар, нужна таблица соответствовать
чисел с символами - кодовая таблица

функции для работы с с-строками

вывод на печать printf (char[],,,) или printf (*char, , , ) - 
print formated

с помощью printf можно не просто печатать готовую строку
но и подставлять в нее другие переменные, попутно преобразовывая их
в символьный вид и применяя форматироване
форматирование printf ("базовая %s строка %f", параметр1, параметр2)

позиции, куда будут подсталять параметры, обозначаются в базовой строке
символом "%"

значение символов форматирования берется из таблицы справки к функции 
http://www.cplusplus.com/reference/ /cstudio/printf/
значение некоторых из них

%f - параметр подставляется на место %f , оформленное в виде числа с плавающей точкой
%s - параметр подставляется на место %s как строка
%d - параметр подставляется на место %d как целое число
%e - параметр подставляется на место %e как число в экспоненциальном виде

объединение (конкатенация) строк strcat (*char, *char)
копирование из одной строки в другую strcpy()
сравнение strcmp ()
длина строки strlen ()
вставка строки в подстроку производится в несколько действий
 
в стандартной библиотеке с++ массив символов инкапсулирован в класс std::string
в который также собраны самые частоиспользуемые методы обработки
и для которого перегружены операторы + (конкатенация), ввод,  вывод и т.д.
еще одно отличие от строк с - длина строки теперь задается отдельным числом,
а не нулевым окончанием
*/

//string cppstr1 = "C++ - style string 1";
//string cppstr2 = "";

/*
#define ANSI_COLOR_RED "\33[0:31m\\]"
#define ANSI_COLOR_RESET "33[0m\\]"
*/




int main()
{
	fstream nas, zam;
	zam.open("Name.txt", fstream::in);
	nas.open("Surname.txt", fstream::out);
	
	string str1;
	string str2;
	getline(zam, str1);
	getline(zam, str2);

	int i = 0, k = 0;
	
	while (str1.find(str2, i) != -1) {
		i = str1.find(str2, i);
		i++;
		k++;
		nas << i << '\t';
	}
	if (k == 0)
		k = -1;
	nas << '\n' << k;
	nas.close();
}


