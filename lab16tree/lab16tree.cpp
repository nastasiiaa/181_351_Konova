#include <iostream>
#include <cstdlib>

template<class T>
class tree {
	struct Node {
		T     item;
		Node *son;
		Node *bro;
		Node(T i, Node*s = NULL, Node *b = NULL)
		{
			item = i;
			son = s;
			bro = b;
		}
		Node() {};
	};

	Node *root;

private:
	Node*  tr;
	size_t cnt;
public:
	tree() { root = NULL; }
	void add(const T &elem)
	{
		add(root, elem);
	}

	void f()
	{
		Node *temp = new Node;
		*temp = *root;
		std::cout << temp->item;
		f(temp);
		*temp = *root;
		*temp = *temp->son;
		f(temp);


		/*while (temp->son != NULL)
		{
			*temp = *temp->son;
			std::cout << temp->item;
			while (temp->bro != NULL)
			{
				*temp = *temp->bro;
				std::cout << temp->item;
			}
			//*temp = *root;
		}*/
	}
	/*void print()
	{
		Node *temp = new Node;
		*temp = *root;
		if (temp->son != NULL)
		{
			*temp = *temp->son;
			while (temp->bro != NULL)
			{
				std::cout << temp->item;
				*temp = *temp->bro;
			}
			std::cout << temp->item;
		}
	}*/
private:
	void add(Node *&node, const T &item)
	{
		int a;
		if (node == NULL)
		{
			node = new Node(item);
		}
		else {
			std::cin >> a;
			if (/*item < node->item*/a > 0) {
				add(node->son, item);
			}

			else {
				add(node->bro, item);
			}
		}
	}
	void f(Node *&node)
	{
		if (node->son != NULL)
		{
			*node = *node->son;
			std::cout << node->item;
			while (node->bro != NULL)
			{
				*node = *node->bro;
				std::cout << node->item;
			}

			*node = *root;
			*node = *node->son;
		}

	}
};
int main() {

	tree<int> t1;
	for (int i = 1; i <= 4; i++)t1.add(i); 

	t1.f();
	//t1.print();
	//getchar();
	system("pause"); 
	return 0;
}
