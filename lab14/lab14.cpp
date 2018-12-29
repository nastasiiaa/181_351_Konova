#include <iostream> 

#include <stack> // подключаем библиотеку для использования стека 
#include <queue> // подключили библиотеку для использования очереди 
#include <deque> // подключили библиотеку для использования дека 
#include <string.h>

#include <list> // подключили библиотеку для использования списка
#include <set> // подключили библиотеку для использования множества
#include <map> // подключили библиотеку для использования ассоциативного массива

//#include <fstream>
#include <random>
#include <ctime>
#include <iterator>
#include <string>

using namespace std;
int main ()
{ 
	/*
	Стек — это структура данных, которая работает
	по принципу FILO(first in — last out; первый пришел — последний ушел).

	В стеке нет индексов,т.е. нельзя обратиться к определенному элементу.
	Каждый элемент имеет указатель на следующий элемент.
	Головной элемент указывает на NULL.

	Достоинство: операции удаления и добавления элемента делаются за const время.

	*/
	/*
	std::stack<int> stackInt;//stack <тип данных> <имя>; -создание стека
	int i = 0, a = 0;
	std::cout << "Введите 5 целых чисел: " << std::endl;
	while (i != 5) {
		std::cin >> a;
		stackInt.push(a); // добавляем введенное число
		i++;
	}

	if (stackInt.empty()) // проверяем пуст ли стек (нет)
		std::cout << "Стек не пуст";

	std::cout << "Верхний элемент стека: " << stackInt.top() << std::endl;
	stackInt.pop(); // удаляем верхний элемент

	std::cout << "Новый верхний элемент: " << stackInt.top() << std::endl;

	// ЗАДАНИЕ 1
	/*
	Проверить правильность расстановки скобок (,),[,],{,}
	в введенном пользователем выражении за линейное время
	(один просмотр выражения).
	2+4-5(87192479_7348){72648]76823[] -> no
	({}) -> yes
	({)} -> no
	*/

	//решение 
	/*
	Считываем элемент.
	Если это (,[ или {, то помещаем ее в стек.
	Если это ),] или }, то сравниваем с верхним элементом стека.
	Если образовалась пара, то верхний элемент стека удаляем.
	Иначе - выражение неправильное.

	Когда все элементы считали, то проверяем стек на пустоту.
	Если стек пуст, то выражение правильное.
	Иначе - выражение неправильное.
	*/

	/*
	Очередь — это структура данных, которая построена по принципу
	LILO (last in — last out: последним пришел — последним вышел).
	*/
	/*
	std::queue <int> MyQueue; // создали очередь
	std::cout << "Введите 7 чисел: " << std::endl;
	for (i = 0; i < 7; i++) {
		std::cin >> a;
		MyQueue.push(a); // добавляем в очередь элементы
	}
	std::cout << std::endl;
	std::cout << "Первый элемент в очереди: " << MyQueue.front() << std::endl;
	MyQueue.pop(); // удаляем элемент из очереди
	std::cout << "Первый элемент (после удаления): " << MyQueue.front() << std::endl;

	if (!MyQueue.empty()) // проверяем пуста ли очередь (нет)
		std::cout << "Очередь не пуста!";
	/*
	Очередь с приоритетом (priority_queue) — это обычная очередь,
	но в ней новый элемент добавляется в такое место,
	чтобы очередь была отсортирована по убыванию.
	*/

	/*std::priority_queue <int> priority_q; // объявляем приоритетную очередь

	std::cout << "Введите 7 чисел: " << std::endl;
	for (i = 0; i < 7; i++) {
		std::cin >> a;
		priority_q.push(a); // добавляем элементы в очередь
		//std::copy(MyQueue.front(), MyQueue.back(), std::ostream_iterator<int>(cout, " "));
	}
	// выводим первый
	std::cout << "Первый элемент очереди: " << priority_q.top();

		// ЗАДАНИЕ 2
		/*
		Программа на вход получает список школьников.
		В каждой строке сначала записан номер класса (число, равное 9, 10 или 11),
		затем (через пробел) – фамилия.
		Необходимо вывести список по классам:
		сначала всех учащихся 9 класса, затем – 10, затем – 11.
		Внутри одного класса порядок вывода должен быть таким же, как на входе.
	
	std::queue <std::string> q9, q10, q11;
	std::string cl, name;
	while (1)
	{
		std::getline(std::cin, cl);
		if (cl == "0") break; // останавливает нулём
		if (cl[0] == '9')
		{
			name.assign(cl.begin() + 2, cl.end());
			q9.push(name);
		};
		if (cl[0] == '1')
		{
			if (cl[1] == '0')
			{
				name.assign(cl.begin() + 3, cl.end());
				q10.push(name);
			}
			if (cl[1] == '1')
			{
				name.assign(cl.begin() + 3, cl.end());
				q11.push(name);
			}
		};
	}
	std::cout << "9 class" << std::endl;
	while (!q9.empty())
	{
		std::cout << q9.front() << std::endl;
		q9.pop();
	}
	std::cout << "10 class" << std::endl;
	while (!q10.empty())
	{
		std::cout << q10.front() << std::endl;
		q10.pop();
	}
	std::cout << "11 class" << std::endl;
	while (!q11.empty())
	{
		std::cout << q11.front() << std::endl;
		q11.pop();
	}*/
	/*
	Создаем 3 очереди (свою для каждого класса).

	Считываем очередную строку. В зависимости от класса
	добавляем фамилию в соответствующую очередь

	Когда все считали, выводим очереди последовательно:

	сначала для 9 класса, затем очередь 10 класса,
	а в самом конце очередь 11 класса.
	*/

	/*
	Деком (англ. deque – аббревиатура от double-ended queue, двухсторонняя очередь)
	называется структура данных, в которую можно
	удалять и добавлять элементы
как в начало, так и в конец.

Дек хранится в памяти так же, как и очередь.

	std::deque<int> dequeInt; //deque <тип данных> <имя>;
 создание дека
	int i = 0; a = 0;
	std::cout << "Введите 5 целых чисел: " << std::endl;
	while (i != 5) {
		std::cin >> a;
		deque.push_back(a);
		deque.push_front(a);
		i++;
	}
  if (deque.empty()) //проверяем пуст ли дек (нет)
	  std::cout << "Дек не пуст";

	   std::cout << "Верхний элемент дека: " << deque.back()
	   << std::endl;
	   deque.pop_back(); //удаляем верхний элемент
	   std::cout << "Новый верхний элемент: " << deque.back
	  */
	  //ЗАДАЧА 3 
	  /*
	  Проверить, является ли введенная строка палиндромом
	  (читается одинаково слева направо и справа налево). Использовать дек.
	  */
	bool palindrom(char s[100]);

	setlocale(LC_ALL, "rus");
	char s[100];
	cout << "введите строку" << endl;
	cin.getline(s, 100);
	if (palindrom(s) == 1)
		cout << "палиндром " << endl;
	else
		cout << "не палиндром" << endl;
	return 0;

	bool palindrom(char s[]); {
		int n = strlen(s);
		for (int i = 0; i < n / 2; i++)
			if (s[i] != s[n - 1 - i])
				return false;
		return true;
	}

	/*

	Считываем строку посимвольно. каждый символ добавляем в хвост дека.
	Далее сравниваем первый и последний символ дека.
	*/

	//ЗАДАЧА 4 
	/*
	Описать структуру данных List.
	Продемонстрировать работу с этой структурой:
	ввод, вывод,
	добавление элемента и удаление,
	сортировка.
	
	list <int> mylist;
	//	list <int> mylist2;
	list <int> listmerge = { 7, 8, 9 };
	list <int> ::iterator it;
	list <int> ::iterator pos_ud_begin, pos_ud_end;
	/*static default_random_engine rnd(time(0));
	static uniform_int_distribution<unsigned> d(2, 9);
	int q=d(rnd);


	 for (int i = 0; i < 2; i++) {
		for (int j = 1; j < 6; j++) {
			mylist.push_back(i);	// добавили 10 элементов
		}
	 }


	//	mylist.remove(0); // удалили элемен по значению

	copy(mylist.begin(), mylist.end(), ostream_iterator<int>(cout, " "));
	cout << endl;



	mylist.insert(mylist.end(), 6); // добавили новый элемент
	/* ------> Удаляем последовательность элементов
	pos_ud_begin = pos_ud_end = mylist.begin();
	advance(pos_ud_end, 9);		// сдвигает позицию (pos_end) на 5 ячеек.
	pos_ud_begin++;
	mylist.erase(pos_ud_begin, pos_ud_end);
	<-----------------





	mylist.clear();  // удалили все дубликаты
	cout << "\n";
	copy(mylist.begin(), mylist.end(), ostream_iterator<int>(cout, " ")); // вывод изменённого листа
	cout << endl;
	for (it = mylist.begin(); it != mylist.end(); it++) {
		cout << (*it) << "-";
	}

	mylist.merge(listmerge);  // присвоили список 
	for (it = mylist.begin(); it != mylist.end(); it++) {
		cout << (*it) << "-";
	}

	return 0;
*/
		//ЗАДАЧА 5 
		/*
		Описать структуру данных Set.
	Продемонстрировать работу с этой структурой:
	ввод, вывод,
	добавление элемента и удаление.
	
	map <string, string> passport;

	passport["maxim"] = "Denisov";     // добавляем
	passport["andrey"] = "Puzerevsky"; // новые
	passport["dima"] = "Tilyupo";      // значения

	cout << "Size do udal: " << passport.size() << endl;

	map <string, string> ::iterator full_name; // создали итератор на passport

	full_name = passport.find("andrey");// находим ячейку

	passport.erase("dima");// удаляем
	passport.erase(full_name);// удаляем


	cout << "Size posle udal: " << passport.size();*/
	//ЗАДАЧА 6 
	/*
	Описать структуру данных map.
	Продемонстрировать работу с этой структурой:
	ввод, вывод,
	добавление элемента и удаление.

	char c;
	std::map <char, int> myMap;
	std::map<char, int>::iterator mm;
	for (int i = 0, c = 'a'; i < 5; ++i, ++c)
	{
		myMap.insert(std::pair<char, int>(c, i));
	}
	///вывод не явно инициализированной map на экран
	for (auto it = myMap.begin(); it != myMap.end(); ++it)
	{
		std::cout << (*it).first << " : " << (*it).second << std::endl;
	}
	std::cout << std::endl;
	mm = myMap.find('b');
	std::cout << "заменим с-й элемент  " << std::endl;
	myMap.erase('c'); //удаление
	myMap.insert(mm, std::pair<char, int>('c', 200)); //добавление
	for (auto it = myMap.begin(); it != myMap.end(); ++it)
	{
		std::cout << (*it).first << " : " << (*it).second << std::endl;
	}*/
	// ЗАДАЧА 7 
	/*
	Составить таблицу сравнения по времени выполнения операций
	для дека, стека, очереди, списка, множества, массива из n элементов.
	Список операций:
	добавление в начало
	добавление в конец
	добавление в середину
	удаление из начала
	удаление с конца
	удаление из середины
	значение элемента из начала
	значение элемента с конца
	значение элемента из середины
	*/

	/*std::stack <char> first;
	char a;
	while (1)
	{
		std::cin >> a;
		if (a == 'q')
		{
			std::cout << "Yes";
			break;
		}
		if (a == '(' || a == '{' || a == '[') first.push(a);
		if (a == ')')
		{
			if ('(' == first.top())
			{
				first.pop();
			}
			else
			{
				std::cout << "No";
				break;
			}
		}
		if (a == '}')
		{
			if ('{' == first.top())
			{
				first.pop();
			}
			else
			{
				std::cout << "No";
				break;
			}
		}
		if (a == ']')
		{
			if ('[' == first.top())
			{
				first.pop();
			}
			else
			{
				std::cout << "No";
				break;
			}
		}
	}
		system("pause");
		return 0;
}
*/
}