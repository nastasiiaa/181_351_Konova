#include <iostream> 

#include <stack> // ���������� ���������� ��� ������������� ����� 
#include <queue> // ���������� ���������� ��� ������������� ������� 
#include <deque> // ���������� ���������� ��� ������������� ���� 
#include <string.h>

#include <list> // ���������� ���������� ��� ������������� ������
#include <set> // ���������� ���������� ��� ������������� ���������
#include <map> // ���������� ���������� ��� ������������� �������������� �������

//#include <fstream>
#include <random>
#include <ctime>
#include <iterator>
#include <string>

using namespace std;
int main ()
{ 
	/*
	���� � ��� ��������� ������, ������� ��������
	�� �������� FILO(first in � last out; ������ ������ � ��������� ����).

	� ����� ��� ��������,�.�. ������ ���������� � ������������� ��������.
	������ ������� ����� ��������� �� ��������� �������.
	�������� ������� ��������� �� NULL.

	�����������: �������� �������� � ���������� �������� �������� �� const �����.

	*/
	/*
	std::stack<int> stackInt;//stack <��� ������> <���>; -�������� �����
	int i = 0, a = 0;
	std::cout << "������� 5 ����� �����: " << std::endl;
	while (i != 5) {
		std::cin >> a;
		stackInt.push(a); // ��������� ��������� �����
		i++;
	}

	if (stackInt.empty()) // ��������� ���� �� ���� (���)
		std::cout << "���� �� ����";

	std::cout << "������� ������� �����: " << stackInt.top() << std::endl;
	stackInt.pop(); // ������� ������� �������

	std::cout << "����� ������� �������: " << stackInt.top() << std::endl;

	// ������� 1
	/*
	��������� ������������ ����������� ������ (,),[,],{,}
	� ��������� ������������� ��������� �� �������� �����
	(���� �������� ���������).
	2+4-5(87192479_7348){72648]76823[] -> no
	({}) -> yes
	({)} -> no
	*/

	//������� 
	/*
	��������� �������.
	���� ��� (,[ ��� {, �� �������� �� � ����.
	���� ��� ),] ��� }, �� ���������� � ������� ��������� �����.
	���� ������������ ����, �� ������� ������� ����� �������.
	����� - ��������� ������������.

	����� ��� �������� �������, �� ��������� ���� �� �������.
	���� ���� ����, �� ��������� ����������.
	����� - ��������� ������������.
	*/

	/*
	������� � ��� ��������� ������, ������� ��������� �� ��������
	LILO (last in � last out: ��������� ������ � ��������� �����).
	*/
	/*
	std::queue <int> MyQueue; // ������� �������
	std::cout << "������� 7 �����: " << std::endl;
	for (i = 0; i < 7; i++) {
		std::cin >> a;
		MyQueue.push(a); // ��������� � ������� ��������
	}
	std::cout << std::endl;
	std::cout << "������ ������� � �������: " << MyQueue.front() << std::endl;
	MyQueue.pop(); // ������� ������� �� �������
	std::cout << "������ ������� (����� ��������): " << MyQueue.front() << std::endl;

	if (!MyQueue.empty()) // ��������� ����� �� ������� (���)
		std::cout << "������� �� �����!";
	/*
	������� � ����������� (priority_queue) � ��� ������� �������,
	�� � ��� ����� ������� ����������� � ����� �����,
	����� ������� ���� ������������� �� ��������.
	*/

	/*std::priority_queue <int> priority_q; // ��������� ������������ �������

	std::cout << "������� 7 �����: " << std::endl;
	for (i = 0; i < 7; i++) {
		std::cin >> a;
		priority_q.push(a); // ��������� �������� � �������
		//std::copy(MyQueue.front(), MyQueue.back(), std::ostream_iterator<int>(cout, " "));
	}
	// ������� ������
	std::cout << "������ ������� �������: " << priority_q.top();

		// ������� 2
		/*
		��������� �� ���� �������� ������ ����������.
		� ������ ������ ������� ������� ����� ������ (�����, ������ 9, 10 ��� 11),
		����� (����� ������) � �������.
		���������� ������� ������ �� �������:
		������� ���� �������� 9 ������, ����� � 10, ����� � 11.
		������ ������ ������ ������� ������ ������ ���� ����� ��, ��� �� �����.
	
	std::queue <std::string> q9, q10, q11;
	std::string cl, name;
	while (1)
	{
		std::getline(std::cin, cl);
		if (cl == "0") break; // ������������� ����
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
	������� 3 ������� (���� ��� ������� ������).

	��������� ��������� ������. � ����������� �� ������
	��������� ������� � ��������������� �������

	����� ��� �������, ������� ������� ���������������:

	������� ��� 9 ������, ����� ������� 10 ������,
	� � ����� ����� ������� 11 ������.
	*/

	/*
	����� (����. deque � ������������ �� double-ended queue, ������������� �������)
	���������� ��������� ������, � ������� �����
	������� � ��������� ��������
��� � ������, ��� � � �����.

��� �������� � ������ ��� ��, ��� � �������.

	std::deque<int> dequeInt; //deque <��� ������> <���>;
 �������� ����
	int i = 0; a = 0;
	std::cout << "������� 5 ����� �����: " << std::endl;
	while (i != 5) {
		std::cin >> a;
		deque.push_back(a);
		deque.push_front(a);
		i++;
	}
  if (deque.empty()) //��������� ���� �� ��� (���)
	  std::cout << "��� �� ����";

	   std::cout << "������� ������� ����: " << deque.back()
	   << std::endl;
	   deque.pop_back(); //������� ������� �������
	   std::cout << "����� ������� �������: " << deque.back
	  */
	  //������ 3 
	  /*
	  ���������, �������� �� ��������� ������ �����������
	  (�������� ��������� ����� ������� � ������ ������). ������������ ���.
	  */
	bool palindrom(char s[100]);

	setlocale(LC_ALL, "rus");
	char s[100];
	cout << "������� ������" << endl;
	cin.getline(s, 100);
	if (palindrom(s) == 1)
		cout << "��������� " << endl;
	else
		cout << "�� ���������" << endl;
	return 0;

	bool palindrom(char s[]); {
		int n = strlen(s);
		for (int i = 0; i < n / 2; i++)
			if (s[i] != s[n - 1 - i])
				return false;
		return true;
	}

	/*

	��������� ������ �����������. ������ ������ ��������� � ����� ����.
	����� ���������� ������ � ��������� ������ ����.
	*/

	//������ 4 
	/*
	������� ��������� ������ List.
	������������������ ������ � ���� ����������:
	����, �����,
	���������� �������� � ��������,
	����������.
	
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
			mylist.push_back(i);	// �������� 10 ���������
		}
	 }


	//	mylist.remove(0); // ������� ������ �� ��������

	copy(mylist.begin(), mylist.end(), ostream_iterator<int>(cout, " "));
	cout << endl;



	mylist.insert(mylist.end(), 6); // �������� ����� �������
	/* ------> ������� ������������������ ���������
	pos_ud_begin = pos_ud_end = mylist.begin();
	advance(pos_ud_end, 9);		// �������� ������� (pos_end) �� 5 �����.
	pos_ud_begin++;
	mylist.erase(pos_ud_begin, pos_ud_end);
	<-----------------





	mylist.clear();  // ������� ��� ���������
	cout << "\n";
	copy(mylist.begin(), mylist.end(), ostream_iterator<int>(cout, " ")); // ����� ���������� �����
	cout << endl;
	for (it = mylist.begin(); it != mylist.end(); it++) {
		cout << (*it) << "-";
	}

	mylist.merge(listmerge);  // ��������� ������ 
	for (it = mylist.begin(); it != mylist.end(); it++) {
		cout << (*it) << "-";
	}

	return 0;
*/
		//������ 5 
		/*
		������� ��������� ������ Set.
	������������������ ������ � ���� ����������:
	����, �����,
	���������� �������� � ��������.
	
	map <string, string> passport;

	passport["maxim"] = "Denisov";     // ���������
	passport["andrey"] = "Puzerevsky"; // �����
	passport["dima"] = "Tilyupo";      // ��������

	cout << "Size do udal: " << passport.size() << endl;

	map <string, string> ::iterator full_name; // ������� �������� �� passport

	full_name = passport.find("andrey");// ������� ������

	passport.erase("dima");// �������
	passport.erase(full_name);// �������


	cout << "Size posle udal: " << passport.size();*/
	//������ 6 
	/*
	������� ��������� ������ map.
	������������������ ������ � ���� ����������:
	����, �����,
	���������� �������� � ��������.

	char c;
	std::map <char, int> myMap;
	std::map<char, int>::iterator mm;
	for (int i = 0, c = 'a'; i < 5; ++i, ++c)
	{
		myMap.insert(std::pair<char, int>(c, i));
	}
	///����� �� ���� ������������������ map �� �����
	for (auto it = myMap.begin(); it != myMap.end(); ++it)
	{
		std::cout << (*it).first << " : " << (*it).second << std::endl;
	}
	std::cout << std::endl;
	mm = myMap.find('b');
	std::cout << "������� �-� �������  " << std::endl;
	myMap.erase('c'); //��������
	myMap.insert(mm, std::pair<char, int>('c', 200)); //����������
	for (auto it = myMap.begin(); it != myMap.end(); ++it)
	{
		std::cout << (*it).first << " : " << (*it).second << std::endl;
	}*/
	// ������ 7 
	/*
	��������� ������� ��������� �� ������� ���������� ��������
	��� ����, �����, �������, ������, ���������, ������� �� n ���������.
	������ ��������:
	���������� � ������
	���������� � �����
	���������� � ��������
	�������� �� ������
	�������� � �����
	�������� �� ��������
	�������� �������� �� ������
	�������� �������� � �����
	�������� �������� �� ��������
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