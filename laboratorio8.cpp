#include <iostream>
#include <vector>
using namespace std;

// ejercicio 1
class Rectangle
{
	public:
		Rectangle();
		Rectangle(float h, float w);
		~Rectangle() {}
		
		float CalculateArea();
		
	private:
		float _height;
		float _width;
};

// constructor default
Rectangle::Rectangle()
{
	_height = 1;
	_width = 1;
}

// constructor por parametros
Rectangle::Rectangle(float h, float w)
{
	_height = h;
	_width = w;
}

// retorna el area del rectangulo
float Rectangle::CalculateArea()
{
	return _height * _width;
}

// ejercicio 2
class Point
{
	public:
		Point();
		Point(float x, float y);
		~Point() {}
		
		void setX(float x){ _x = x; }
		float getX(){ return _x; }
		void setY(float y) { _y = y; }
		float getY() { return _y; }
		
		void MovePoint(float new_x, float new_y);
		
	private:
		float _x;
		float _y;
};

// constructor default
Point::Point()
{
	_x = 0;
	_y = 0;
}

// constructor por parametros
Point::Point(float x, float y)
{
	_x = x;
	_y = y;
}

// mueve el punto ingresado y muestra por cuanto se movio
void Point::MovePoint(float new_x, float new_y)
{
	cout << "Moving Point by:" << endl << _x-new_x << " in x axis" << endl << _y-new_y << " in y axis";
	_x = new_x;
	_y = new_y;
}

// ejercicio 3
struct ListNode
{
	int data;
	ListNode *next;
};

class LinkedList
{
	public:
		LinkedList(ListNode *h);
		~LinkedList() {}
		
		void InsertNode(int data);
		bool SearchNode(int data);
		void DeleteNode(int data);
		void PrintList();
		
	private:
		ListNode *head;
};

// constructor
LinkedList::LinkedList(ListNode *h)
{
	head = h;
}

// inserta nodo en la lista
void LinkedList::InsertNode(int data)
{
	if (head != NULL)
	{
		ListNode *current = head;
		while (current->next != NULL)
			current = current->next;
			
		current->next = new ListNode{data, NULL};
	}
	else
		head = new ListNode{data, NULL};
}

// busca nodo en la lista
bool LinkedList::SearchNode(int data)
{
	if (head != NULL)
	{
		ListNode *current = head;
		while (current != NULL)
		{
			if (current->data == data)
				return true;
			current = current->next;
		}
	}
	return false;
}

// elimina nodo de lista
void LinkedList::DeleteNode(int data)
{
	if (!SearchNode(data))
		return;
	
	if (head != NULL)
	{
		ListNode *current = head;
		ListNode *prev = NULL;
		
		while (current != NULL)
		{
			if (current->data == data)
				break;
				
			prev = current;
			current = current->next;
		}
		
		if (prev == NULL && current->next != NULL) // 1er elemento
			head = current->next;
		else if (prev != NULL && current->next == NULL) // ultimo elemento
			prev->next = NULL;
		else if (prev != NULL && current->next != NULL) // elemento de en medio
			prev->next = current->next;
		else if (prev == NULL && current->next == NULL) // unico elemento
			head = NULL;
		
		delete current;
	}
}

// imprmime lista
void LinkedList::PrintList()
{
	if (head != NULL)
	{
		ListNode *current = head;
		while (current != NULL)
		{
			cout << current->data;
			if (current->next != NULL)
				cout << " - ";
			current = current->next;
		}
	}
}

// ejercicio 4
struct BinaryNode
{
	int data;
	BinaryNode *left;
	BinaryNode *right;
	
	BinaryNode(int data) : data(data), left(nullptr), right(nullptr) {}
};

class BinaryTree
{
	public:
		BinaryTree(BinaryNode *r);
		~BinaryTree() {}
		
		void Insert(int data) { root = InsertNode(root, data); }
		BinaryNode* InsertNode(BinaryNode *current, int data);
		
		bool Search(int data)  { return SearchNode(root, data); }
		bool SearchNode(BinaryNode *current, int data);
		
		void Print() { PrintTree(root); }
		void PrintTree(BinaryNode *current);
		
	private:
		BinaryNode *root;
};

// constructor
BinaryTree::BinaryTree(BinaryNode *r)
{
	root = r;
}

// inserta nodo en arbol con recursividad
BinaryNode* BinaryTree::InsertNode(BinaryNode *current, int data)
{
	if (current == NULL)
		return new BinaryNode(data);
	
	if (current->data > data)
		current->left = InsertNode(current->left, data);
	else if (current->data < data)
		current->right = InsertNode(current->right, data);
		
	return current;
}

// busca nodo en el arbol
bool BinaryTree::SearchNode(BinaryNode *current, int data)
{
	if (current == NULL)
		return false;
		
	if (current->data > data)
		return SearchNode(current->left, data);
	else if (current->data < data)
		return SearchNode(current->right, data);
	else
		return true;
}

// imprime arbol
void BinaryTree::PrintTree(BinaryNode *current)
{
	if (current == NULL)
		return;
	
	PrintTree(current->left);
	cout << current->data << " ";
	PrintTree(current->right);
}

// ejercicio 5
struct GeneralNode
{
	int data;
	vector<GeneralNode*> nodes;
	
	GeneralNode(int data) : data(data) {}
};

class GeneralTree
{
	public:
		GeneralTree(GeneralNode *r);
		~GeneralTree() {}
		
		void Insert(int parent, int data) { InsertNode(root, parent, data); }
		void InsertNode(GeneralNode *current, int parent_data, int data);
		
		bool Search(int data) { return SearchNode(root, data); }
		bool SearchNode(GeneralNode *current, int data);
		
		void Print() { PrintTree(root, 0); }
		void PrintTree(GeneralNode *current, int depth);
		
	private:
		GeneralNode *root;
};

// constructor
GeneralTree::GeneralTree(GeneralNode *r)
{
	root = r;
}

// inserta nodo en arbol, necesitando el valor del padre
void GeneralTree::InsertNode(GeneralNode *current, int parent_data, int data)
{
	if (root == nullptr)
	{
		root = new GeneralNode(data);
	}
	else
	{
		if (current->data == parent_data)
			current->nodes.push_back(new GeneralNode(data));
		else
			for (GeneralNode* node : current->nodes)
				InsertNode(node, parent_data, data);
	}
}

// busca nodo en arbol
bool GeneralTree::SearchNode(GeneralNode *current, int data)
{
	if (root == nullptr)
		return false;
	
	if (current->data == data)
		return true;
		
	for (GeneralNode *node : current->nodes)
		if (SearchNode(node, data))
			return true;
		
	return false;
}

// imprime arbol
void GeneralTree::PrintTree(GeneralNode *current, int depth)
{
	for (int i=0; i<depth; i++)
		cout << "  ";
		
	cout << "|--" << current->data << endl;
	
	for (GeneralNode *node : current->nodes)
		PrintTree(node, depth+1);
}

int main()
{
	// ejercicio 1
	cout << "Ejercicio 1" << endl;
	Rectangle rec(5.2, 4.6);
	
	cout << "Area: " << rec.CalculateArea() << endl;
	
	// ejercicio 2
	cout << endl << "Ejercicio 2" << endl;
	Point po(5,3.5);
	
	po.MovePoint(1.76, 3.2);
	cout << endl;
	
	// ejercicio 3
	cout << endl << "Ejercicio 3" << endl;
	ListNode *head = nullptr;
	LinkedList li(head);
	
	li.InsertNode(5);
	li.InsertNode(1);
	li.InsertNode(7);
	li.InsertNode(3);
	li.InsertNode(9);
	li.PrintList();
	
	cout  << endl << "Buscando 5: " << li.SearchNode(5);
	cout << endl << "Buscando 2: " << li.SearchNode(2);
	
	cout << endl << "Borrando 7..." << endl;
	li.DeleteNode(7);
	li.PrintList();
	cout << endl;
	
	// ejercicio 4
	cout << endl << "Ejercicio 4" << endl;
	BinaryNode *binary_root = nullptr;
	BinaryTree bTree(binary_root);
	
	bTree.Insert(10);
	bTree.Insert(4);
	bTree.Insert(23);
	bTree.Insert(6);
	bTree.Insert(18);
	bTree.Insert(1);
	bTree.Print();
	
	cout << endl << "Buscando 6: " << bTree.Search(6); //bTree.SearchNode(bTree.getRoot(), 6);
	cout << endl << "Buscando 8: " << bTree.Search(8) << endl; //bTree.SearchNode(bTree.getRoot(), 8);
	
	// ejercicio 5
	cout << endl << "Ejercicio 5" << endl;
	GeneralNode *general_root = nullptr;
	GeneralTree gTree(general_root);
	
	gTree.Insert(0, 5);
	gTree.Insert(5, 25);
	gTree.Insert(5, 0);
	gTree.Insert(25, 10);
	gTree.Insert(10, 3);
	gTree.Insert(0, 8);
	gTree.Print();
	
	cout << endl << "Buscando 3: " << gTree.Search(3);
	cout << endl << "Buscando 1: " << gTree.Search(1);
	
	return 0;
}
