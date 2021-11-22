#include <iostream>
#include <string>

using namespace std;


/*
* A singly linked list has been created in the program. Its functions include:adding, deleting, returning, filling, outputting from the end, etc.
*/


template<typename T>
class List {
public:
	List();
	~List();

	void pop_front();
	void Push_Back(T data);
	void clear();
	void push_front(T data);
	void insert(T value,int index);
	void removeAT(int index);
	void pop_back();
	int GetSize() { return Size; };

	T& operator[](const int index);
private:



	template<typename T>
	class Node {
	
	public:
		Node *pNext;
		T data;
		Node(T data=T(), Node *pNext=nullptr) 
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node<T> *head;

};

template<typename T>
List<T>::List() {
	Size = 0;
	head = nullptr;
}

template<typename T>
List<T>::~List() {

	clear();
}



template<typename T>
void List<T>::pop_front()
{
	Node<T> *temp = head;
	head = head->pNext;

	delete temp;

	Size--;
}

template<typename T>
void List<T>::Push_Back(T data) {
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;
		while (current->pNext !=nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}

	Size++;
}

template<typename T>
void List<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}

template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data,head);
	Size++;
}

template<typename T>
void List<T>::insert(T value, int index)
{
	if (index==0)
	{
		push_front(value);
	}
	else
	{
     
		Node<T>* previous = this->head;

	for (int i = 0; i < index-1; i++)
	{
		previous = previous->pNext;

	}

	Node<T>* newNode = new Node<T>(value,previous->pNext);
	previous->pNext = newNode;

	Size++;
	}

	
}

template<typename T>
void List<T>::removeAT(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index-1; i++)
		{
			previous = previous->pNext;
		}

		Node<T>* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;

		delete toDelete;
		Size--;

	}
}

template<typename T>
void List<T>::pop_back()
{
	removeAT(Size-1);
}

template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
};

 int main()
{
	 setlocale(LC_ALL,"ru");



	
	 List<int> lst;
	 lst.push_front(5);
	 lst.push_front(7);
	 lst.push_front(6754);
	 lst.push_front(78);

	

	 for (int i = 0; i < lst.GetSize(); i++)
	 {
		 cout << lst[i] << endl;
	 }

	 cout << "Remove" << endl;
	 lst.pop_back();


	 for (int i = 0; i < lst.GetSize(); i++)
	 {
		 cout << lst[i] << endl;
	 }

	 return 0;
}
