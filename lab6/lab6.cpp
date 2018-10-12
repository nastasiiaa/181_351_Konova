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
*/

