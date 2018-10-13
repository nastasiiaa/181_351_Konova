// lab6!.cpp : 1. Определение и синтаксис
/*
Наслледование - заимствование свойств и методов родительского класса 
в производном классе 

синтаксис:
class имя_произв_класса: [тип_наследования] имя_родительского класса1,
						 [тип_наследования] имя_родительского класса2

						 {
						 ...
						 }

где "тип_наследования" - тоже public, protected и private,
но указывать необязательно


В род.						В заголовке при наследовании
классе			public:			protected:		 private:
					
public			public:			protected:		 private:
protected		protected:		protected:		 private:
private			недоступно		недоступно		 недоступно

2. Метод, переопределенный в дочернем классе полностью заменит унаследованный
родительский метод
Чтобы при запуске нового дочернего метода также выполнять и родительский
необходимо указать это явно
в родительском классе void weapon:: reload() {};
в дочернем классе void rifle::reload():weapon::reload(),...{};

3. Если объявить медот со словом virtual, в данном классе можно не приводить
реализацию метода, и определить его (привести реализацию) только в дочерних классах

4. void fnc1(const тип1 параметр1, тип2 параметр2) (const - если ни при каких условиях
нельзя менять значение параметра)

	void fnc1(тип1 параметр1, тип2 параметр2) const (запрещается менять какое-либо
	из свойств объекта)
{
	параметр1=10;
}

4*. Приведение типов 
При попытке сложить/умножить/вычесть/разделить


int i = -15;
double d = 1000.5e+03; // = 1000.5 * 10^3 = 1000.5 * pow(10, 3) = 1000500 = 1000.5e03
float result1;
long long result2;
result1 = i + d;
result2 = i / d;

const char *ch1 = "123"; // {'1', '2', '3', 0} = {'1', '2', '3', '\0'}
const char *ch2 = "456";
 ??? = ch1 + ch2;
 std::string "1233456"



 getchar ();
 return 0;


 */

#include "pch.h"
#include <iostream>
#include <string>

int main()
{
	int i = -15;
	double d = 1000.5e+03; // = 1000.5 * 10^3 = 1000.5 * pow(10, 3) = 1000500 = 1000.5e03
	float result1;
	long long result2;
	result1 = i + d;
	result2 = i / d;

	std::cout << result1 << '\n' << result2;
	std::string;

	const char *ch1 = "123.4"; 
	const char *ch2 = "456.7";
	 //  ??? = ch1 + ch2;
	 // std::string "1233456"

	std::cout << "First: ";
	std::cin >> ch1;
	std::cout << std::endl;

	std::cout << "Second: ";
	std::cin >> ch2;
	std::cout << std::endl;

	i = atoi(ch1); // в int или long
	d = atof(ch2) * 10 / 10; // для double
	i += d;

	std::cout << i << '\n' << std::endl;



	getchar();
	return 0;
}
