// lab6.cpp : Классы

#include "pch.h"
#include <iostream>
#include <string>

/*		СИНТАКСИС ОБЪЯВЛЕНИЯ КЛАССА
	class имя_класса
	{	
			int hp; число ХП
			double speed; скорость персонажа
			void heal(); восстановление ХП
			void move(); проигрывание анимации
	}

			1. ОПРЕДЕЛЕНИЕ КЛАССА И ОБЪЕКТА

		Свойство (property) - переменная в составе класса
		Метод (method) - функция в составе класса
		Инкапсуляция - фактически, объединение данных и методов, объединенных 
		единым смыслом, в одну конструкцию языка
		Наследование - создание производных классов от родительского и 
		заимствование его свойств и методов
		Полиморфизм простыми словамиЖ экземпляры одного класса ведут себя по-разному
		Инкапсуляция, наследование и полиморфизм - три основные идеи ООП

			2. СИНТАКСИС ОБЪЯВЛЕНИЯ ОБЪЕКТА И ОБРАЩЕНИЯ К СВОЙСТВАМ И МЕТОДАМ
		Имя_Класса объект1;
		vehicle car;
		car.speed = 123;
		объект1.свойство1 = 1;
		объект1.метод3();

			3. СПЕЦИФИКАТОРЫ ДОСТУПА
		К полям (свойствам и методам), объявленным в разделе public:
		можно обращаться везде (и из методов класса, и снаружи, где виден объект)
		К полям private и protacted можно обращаться только из методов
		самого класса. Различие между privat и protected объясняется в следующей
		теме про наследование классов.

			4. КОНСТРУКТОР И ДЕСТРУКТОР КЛАССА
		В случае, если при создании объекта нужно выполнять сложные действия 
		по инициаизации, установлению сетевого соединения, действия с файлами,
		выделения ОП и т.д. эти действия прописываются в специальном методе - 
		- конструкторе 
		Конструктор вызывается автоматически при создании объекта 
		В случае если при исчезновении объекта нужно общие системные ресурсы 
		освобождать:
		закрывать порты, освобождать ОП, сохранять файлы и т.д. - эти действия 
		прописываются в методе - деструкторе (вызывается автоматически при
		исчезновении объекта)

			5. СТРУКТУРЫ
		Несмотря на то, что в литературе структура, как правило, хранит только
		данные, на самом деле, это то же самое, что и класс. 
		Единственное отличие - поля по умолчанию public
		struct

		class vehicle - игровое транспортное средство
		{
			private: 
			public:
			double speed;
			char regnumber[6] = {0};
			unsigned char capacity;
			bool check_regnumber();
			void add_passenger (int passengers);
			void accelerate (double delta_velocity):
		};

*/

class polzovatel
{
private:
	char first_name[255];
	char second_name[255];
	char str_pasport[10];
	char str_birthday[10];
public:
	polzovatel(); // konstructor
	~polzovatel(); // destructor

	polzovatel(char as_first_name[255], char as_second_name[255], char as_str_pasport[10], char as_str_birthday[10]);
	polzovatel(char first_nam[255], char second_name[255]);

	bool set_first_name(char as_first_name[255])
	{
		//tolko bykvi ili tire
		bool prover;
		for (int i = 0; i < '\0'; i++)
		{
			if (((as_first_name[i] >= 33) && (as_first_name[i] <= 44)) ||
				((as_first_name[i] >= 46) && (as_first_name[i] <= 64)))
			{
				return false;
			}
			if ((as_first_name[i] >= 91) && (as_first_name[i] <= 96))
			{
				return false;
			}
		}
		return true;

	};

	bool set_second_name (char as_second_name[255])
	{
		//tolko bykvi ili tire
		bool prover;
		for (int i = 0; i < '\0'; i++)
		{
			if (((as_second_name[i] >= 33) && (as_second_name[i] <= 44)) ||
				((as_second_name[i] >= 46) && (as_second_name[i] <= 64)))
			{
				return false;
			}
			if ((as_second_name[i] >= 91) && (as_second_name[i] <= 96))
			{
				return false;
			}
		}
		return true;

	};

	bool set_birthday(char as_birthday[10])
	{
		for (int i = 0; i < 10; i++)
		{
			if ((as_birthday[i] >= '.') && (as_birthday[i] <= '9'))
			{
				return true;
			}
			else
			{
				return false;
			}
		} 
	};


	bool set_pasport(char as_birthday[10])
	{
		return false;
	};
};

polzovatel::polzovatel()
{

}
polzovatel::~polzovatel()
{

}

polzovatel::polzovatel(char as_first_name[255], char as_second_name[255], char as_str_pasport[10], char as_str_birthday[10])
{
	for (int i = 0; i < 10; i++)
	{
		first_name[i] = as_first_name[i];
		second_name[i] = as_second_name[i];
		str_pasport[i] = as_str_pasport[i];
		str_birthday[i] = as_str_birthday[i];
	}
}

int main()
{
	polzovatel person;
	char firstname[] = "Anastasia";
	if (person.set_first_name(firstname) == true)
	{
		std::cout << "firstname is ok" << std::endl;
	}
	else
	{
		std::cout << "firstname is not ok" << std::endl;
	}
	char secondname[] = "Konova";

	if (person.set_second_name(secondname) == true)
	{
		std::cout << "secondname is ok" << std::endl;
	}
	else
	{
		std::cout << "secondname is not ok" << std::endl;
	}

	char date[] = "18.07.2000";

	if (person.set_birthday(date) == true)
	{
	std::cout << "date is ok" << std::endl;
	}
	else
	{
		std::cout << "date is not ok" << std::endl;
	}
	return 0;
}